/*
 * Copyright (c) 2017-2020, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#include "sw.h"
#include "ssdk_init.h"
#include "ssdk_plat.h"
#include "ssdk_clk.h"
#include "ssdk_dts.h"
#include "adpt_hppe.h"
#include "adpt.h"
#include "fal.h"
#include <linux/kconfig.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/reset.h>
#include <linux/clk.h>
#include <linux/clk-provider.h>
#include <linux/clkdev.h>

#if IS_ENABLED(CONFIG_QCOM_FPGA_PCI)
#include <linux/qcom-fpga-pci.h>
#endif

#if defined(SSDK_RAW_CLOCK)
#include <dt-bindings/reset/qcom,ipq5424-nsscc.h>
#include <dt-bindings/clock/qcom,ipq5424-nsscc.h>
#include <dt-bindings/reset/qcom,ipq5424-gcc.h>
#include <dt-bindings/clock/qcom,ipq5424-gcc.h>
#include <linux/reset-controller.h>

struct reset_control {
	struct reset_controller_dev *rcdev;
	struct list_head list;
	unsigned int id;
	struct kref refcnt;
	bool acquired;
	bool shared;
	bool array;
	atomic_t deassert_count;
	atomic_t triggered_count;
};

struct clk {
	struct clk_core	*core;
	struct device *dev;
	const char *dev_id;
	const char *con_id;
	unsigned long min_rate;
	unsigned long max_rate;
	unsigned int exclusive_count;
	struct hlist_node clks_node;
};
#endif

struct device_node *clock_node = NULL;
static struct clk *uniphy_port_clks[UNIPHYT_CLK_MAX] = {0};

struct device_node *rst_node = NULL;
struct reset_control *uniphy_rsts[UNIPHY_RST_MAX] = {0};
struct reset_control *port_rsts[SSDK_MAX_PORT_NUM * 2] = {0};
struct reset_control *port_mac_rsts[SSDK_MAX_PORT_NUM] = {0};

#if defined(SSDK_RAW_CLOCK)
#define RST_LOOKUP(_cbc, _node_name, _rst_index, _rst_bits)	\
{					\
	.cbc = _cbc,			\
	.node_name = _node_name,	\
	.rst_index = _rst_index,	\
	.rst_bits = _rst_bits,		\
}

#define CLK_LOOKUP(_rcg, _rcg_val, _cdiv, _cdiv_val, _cbc, _clk_id, _en_bit, _rate, _prate, _is_gcc)	\
{					\
	.rcg = _rcg,			\
	.rcg_val = _rcg_val,		\
	.cdiv = _cdiv,			\
	.cdiv_val = _cdiv_val,		\
	.cbc = _cbc,			\
	.clk_id = _clk_id,		\
	.en_bit = _en_bit,		\
	.rate = _rate,			\
	.prate = _prate,		\
	.is_gcc = _is_gcc,		\
}

struct clk_data_t {
	const char *clk_id;
	unsigned int rcg;
	unsigned int rcg_val;
	unsigned int cdiv;
	unsigned int cdiv_val;
	unsigned int cbc;
	unsigned int cbc_val;
	unsigned int rate;
	unsigned int prate;
	unsigned int en_bit;
	bool is_gcc;
};

struct rst_data_t {
	const char *node_name;
	unsigned int rst_index;
	unsigned int cbc;
	unsigned int rst_bits;
};

#define GCC_BASE_ADDR	0x1800000
#define GCC_SIZE	0x80000
#define NSSCC_BASE_ADDR	0x39b00000
#define JHPPE_NSSCC_BASE_ADDR	0x29b00000
#define NSSCC_SIZE	0x80000
#define GCC_NODE_NAME	"clock-controller@1800000"
#define NSSCC_NODE_NAME	"nsscc@39b00000"
#define RST_BIT0	BIT(0)
#define RST_BIT		BIT(2)
#define EN_BIT		BIT(0)
#define RCGR_CMD_UPDATE	BIT(0)
void __iomem *gcc_clk_base_g = NULL;
void __iomem *nsscc_clk_base_g = NULL;

static struct rst_data_t mppe_rst_tbl[] = {
       RST_LOOKUP(0x17044, GCC_NODE_NAME, GCC_UNIPHY0_BCR, RST_BIT0),
       RST_LOOKUP(0x17054, GCC_NODE_NAME, GCC_UNIPHY1_BCR, RST_BIT0),
       RST_LOOKUP(0x17064, GCC_NODE_NAME, GCC_UNIPHY2_BCR, RST_BIT0),
       RST_LOOKUP(0x17050, GCC_NODE_NAME, GCC_UNIPHY0_XPCS_ARES, RST_BIT),
       RST_LOOKUP(0x17060, GCC_NODE_NAME, GCC_UNIPHY1_XPCS_ARES, RST_BIT),
       RST_LOOKUP(0x17070, GCC_NODE_NAME, GCC_UNIPHY2_XPCS_ARES, RST_BIT),
       RST_LOOKUP(0x1704C, GCC_NODE_NAME, GCC_UNIPHY0_AHB_ARES, RST_BIT),
       RST_LOOKUP(0x1705C, GCC_NODE_NAME, GCC_UNIPHY1_AHB_ARES, RST_BIT),
       RST_LOOKUP(0x1706C, GCC_NODE_NAME, GCC_UNIPHY2_AHB_ARES, RST_BIT),
       RST_LOOKUP(0x17048, GCC_NODE_NAME, GCC_UNIPHY0_SYS_ARES, RST_BIT),
       RST_LOOKUP(0x17058, GCC_NODE_NAME, GCC_UNIPHY1_SYS_ARES, RST_BIT),
       RST_LOOKUP(0x17068, GCC_NODE_NAME, GCC_UNIPHY2_SYS_ARES, RST_BIT),

#if 0
       RST_LOOKUP(0x3e8, NSSCC_NODE_NAME, NSS_CC_PPE_BCR, RST_BIT0),
       RST_LOOKUP(0x57c, NSSCC_NODE_NAME, NSS_CC_UNIPHY_PORT1_RX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x580, NSSCC_NODE_NAME, NSS_CC_UNIPHY_PORT1_TX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x584, NSSCC_NODE_NAME, NSS_CC_UNIPHY_PORT2_RX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x588, NSSCC_NODE_NAME, NSS_CC_UNIPHY_PORT2_TX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x58c, NSSCC_NODE_NAME, NSS_CC_UNIPHY_PORT3_RX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x590, NSSCC_NODE_NAME, NSS_CC_UNIPHY_PORT3_TX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x4FC, NSSCC_NODE_NAME, NSS_CC_PORT1_RX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x504, NSSCC_NODE_NAME, NSS_CC_PORT1_TX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x50C, NSSCC_NODE_NAME, NSS_CC_PORT2_RX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x514, NSSCC_NODE_NAME, NSS_CC_PORT2_TX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x51C, NSSCC_NODE_NAME, NSS_CC_PORT3_RX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x524, NSSCC_NODE_NAME, NSS_CC_PORT3_TX_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x428, NSSCC_NODE_NAME, NSS_CC_PORT1_MAC_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x430, NSSCC_NODE_NAME, NSS_CC_PORT2_MAC_CLK_ARES, RST_BIT),
       RST_LOOKUP(0x438, NSSCC_NODE_NAME, NSS_CC_PORT3_MAC_CLK_ARES, RST_BIT),
#endif
};

#define PPE_CLK_UNAWARE_RATE	0
static struct clk_data_t mppe_clk_tbl[] = {
	/* gcc clock */
	CLK_LOOKUP(0, 0, 0, 0, 0x34020, IM_SLEEP_CLK, EN_BIT, 0, PPE_CLK_UNAWARE_RATE, A_TRUE),
	CLK_LOOKUP(0, 0, 0, 0, 0x3A004, CMN_AHB_CLK, EN_BIT, 0, PPE_CLK_UNAWARE_RATE, A_TRUE),
	CLK_LOOKUP(0, 0, 0, 0, 0x3A008, CMN_SYS_CLK, EN_BIT, 0, PPE_CLK_UNAWARE_RATE, A_TRUE),

	/* gcc bfdcd clock */
	CLK_LOOKUP(0x31008, 0x10f, 0, 0, 0x17034, NSSCC_CLK, EN_BIT,
			NSS_NSSCC_CLK_RATE, PPE_CLK_UNAWARE_RATE, A_TRUE),
	CLK_LOOKUP(0x31008, 0x10f, 0, 0, 0x17030, NSSNOC_NSSCC_CLK, EN_BIT,
			NSS_NSSNOC_NSSCC_CLK_RATE, PPE_CLK_UNAWARE_RATE, A_TRUE),
	CLK_LOOKUP(0x31008, 0x10f, 0, 0, 0x1704C, UNIPHY0_AHB_CLK, EN_BIT,
			UNIPHY_AHB_CLK_RATE, PPE_CLK_UNAWARE_RATE, A_TRUE),
	CLK_LOOKUP(0x31008, 0x10f, 0, 0, 0x1705C, UNIPHY1_AHB_CLK, EN_BIT,
			UNIPHY_AHB_CLK_RATE, PPE_CLK_UNAWARE_RATE, A_TRUE),
	CLK_LOOKUP(0x31008, 0x10f, 0, 0, 0x1706C, UNIPHY2_AHB_CLK, EN_BIT,
			UNIPHY_AHB_CLK_RATE, PPE_CLK_UNAWARE_RATE, A_TRUE),

	/* gcc noc & uniphy clock */
	CLK_LOOKUP(0x2E008, 0x208, 0, 0, 0x17028, NSSNOC_SNOC_CLK, EN_BIT,
			MPPE_NSS_NSSNOC_SNOC_CLK_RATE, PPE_CLK_UNAWARE_RATE, A_TRUE),
	CLK_LOOKUP(0x2E008, 0x208, 0, 0, 0x1707C, NSSNOC_SNOC_1_CLK, EN_BIT,
			MPPE_NSS_NSSNOC_SNOC_CLK_RATE, PPE_CLK_UNAWARE_RATE, A_TRUE),
	CLK_LOOKUP(0x17094, 0x1, 0, 0, 0x17048, UNIPHY0_SYS_CLK, EN_BIT,
			APPE_UNIPHY_SYS_CLK_RATE, PPE_CLK_UNAWARE_RATE, A_TRUE),
	CLK_LOOKUP(0x17094, 0x1, 0, 0, 0x17058, UNIPHY1_SYS_CLK, EN_BIT,
			APPE_UNIPHY_SYS_CLK_RATE, PPE_CLK_UNAWARE_RATE, A_TRUE),
	CLK_LOOKUP(0x17094, 0x1, 0, 0, 0x17068, UNIPHY2_SYS_CLK, EN_BIT,
			APPE_UNIPHY_SYS_CLK_RATE, PPE_CLK_UNAWARE_RATE, A_TRUE),

#if 0
	/* 100M */
	CLK_LOOKUP(0x6AC, 0x505, 0, 0, 0x6B0, NSS_CSR, EN_BIT, NSS_NSSCC_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x6AC, 0x505, 0, 0, 0x6B4, NSSNOC_NSS_CSR, EN_BIT, NSS_NSSCC_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),

	/* 375M */
	CLK_LOOKUP(0x5E4, 0x601, 0, 0, 0x5E8, NSSCC_CE_APB, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x5E4, 0x601, 0, 0, 0x5EC, NSSCC_CE_AXI, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x5E4, 0x601, 0, 0, 0x5F4, NSSCC_NSSNOC_CE_APB, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x5E4, 0x601, 0, 0, 0x5F8, NSSCC_NSSNOC_CE_AXI, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),

	/* nss ppe clock */
	CLK_LOOKUP(0x3F0, 0x601, 0, 0, 0x428, PORT1_MAC_CLK, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x3F0, 0x601, 0, 0, 0x430, PORT2_MAC_CLK, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x3F0, 0x601, 0, 0, 0x438, PORT3_MAC_CLK, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x3F0, 0x601, 0, 0, 0x410, NSS_PPE_CLK, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x3F0, 0x601, 0, 0, 0x418, NSS_PPE_CFG_CLK, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x3F0, 0x601, 0, 0, 0x440, NSSNOC_PPE_CLK, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x3F0, 0x601, 0, 0, 0x444, NSSNOC_PPE_CFG_CLK, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x3F0, 0x601, 0, 0, 0x41C, NSS_EDMA_CLK, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x3F0, 0x601, 0, 0, 0x424, NSS_EDMA_CFG_CLK, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x3F0, 0x601, 0, 0, 0x400, NSS_PPE_IPE_CLK, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),
	CLK_LOOKUP(0x3F0, 0x601, 0, 0, 0x408, NSS_PPE_BTQ_CLK, EN_BIT, MRPPE_CLK_RATE,
			PPE_CLK_UNAWARE_RATE, A_FALSE),

	/* nss port & uniphy port clock */
	CLK_LOOKUP(0x4B8, 0x301, 0x4BC, 0, 0x4FC, NSS_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4B8, 0x301, 0x4BC, 0, 0x57C, UNIPHY0_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4B8, 0x303, 0x4BC, 0, 0x4FC, NSS_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4B8, 0x303, 0x4BC, 0, 0x57C, UNIPHY0_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4B8, 0x307, 0x4BC, 0, 0x4FC, NSS_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4B8, 0x307, 0x4BC, 0, 0x57C, UNIPHY0_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4B8, 0x304, 0x4BC, 0, 0x4FC, NSS_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4B8, 0x304, 0x4BC, 0, 0x57C, UNIPHY0_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4B8, 0x318, 0x4BC, 1, 0x4FC, NSS_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4B8, 0x318, 0x4BC, 1, 0x57C, UNIPHY0_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	/* XGMAC used, so 1.25M for 10Mbps 312.5/12.5/20 */
	CLK_LOOKUP(0x4B8, 0x318, 0x4BC, 0x13, 0x4FC, NSS_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4B8, 0x318, 0x4BC, 0x13, 0x57C, UNIPHY0_PORT1_RX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4B8, 0x301, 0x4BC, 0, 0x4FC, NSS_PORT1_RX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),
	CLK_LOOKUP(0x4B8, 0x301, 0x4BC, 0, 0x57C, UNIPHY0_PORT1_RX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),

	CLK_LOOKUP(0x4B8, 0x301, 0x4BC, 0, 0x4FC, NSS_PORT1_RX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4B8, 0x301, 0x4BC, 0, 0x57C, UNIPHY0_PORT1_RX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4B8, 0x309, 0x4BC, 0, 0x4FC, NSS_PORT1_RX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4B8, 0x309, 0x4BC, 0, 0x57C, UNIPHY0_PORT1_RX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4B8, 0x318, 0x4BC, 3, 0x4FC, NSS_PORT1_RX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4B8, 0x318, 0x4BC, 3, 0x57C, UNIPHY0_PORT1_RX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4C4, 0x401, 0x4C8, 0, 0x504, NSS_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4C4, 0x401, 0x4C8, 0, 0x580, UNIPHY0_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4C4, 0x403, 0x4C8, 0, 0x504, NSS_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4C4, 0x403, 0x4C8, 0, 0x580, UNIPHY0_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4C4, 0x407, 0x4C8, 0, 0x504, NSS_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4C4, 0x407, 0x4C8, 0, 0x580, UNIPHY0_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4C4, 0x404, 0x4C8, 0, 0x504, NSS_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4C4, 0x404, 0x4C8, 0, 0x580, UNIPHY0_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4C4, 0x418, 0x4C8, 1, 0x504, NSS_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4C4, 0x418, 0x4C8, 1, 0x580, UNIPHY0_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	/* XGMAC used, so 1.25M for 10Mbps 312.5/12.5/20 */
	CLK_LOOKUP(0x4C4, 0x418, 0x4C8, 0x13, 0x504, NSS_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4C4, 0x418, 0x4C8, 0x13, 0x580, UNIPHY0_PORT1_TX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),


	CLK_LOOKUP(0x4C4, 0x401, 0x4C8, 0, 0x504, NSS_PORT1_TX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),
	CLK_LOOKUP(0x4C4, 0x401, 0x4C8, 0, 0x580, UNIPHY0_PORT1_TX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),

	CLK_LOOKUP(0x4C4, 0x401, 0x4C8, 0, 0x504, NSS_PORT1_TX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4C4, 0x401, 0x4C8, 0, 0x580, UNIPHY0_PORT1_TX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4C4, 0x409, 0x4C8, 0, 0x504, NSS_PORT1_TX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4C4, 0x409, 0x4C8, 0, 0x580, UNIPHY0_PORT1_TX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4C4, 0x418, 0x4C8, 3, 0x504, NSS_PORT1_TX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4C4, 0x418, 0x4C8, 3, 0x580, UNIPHY0_PORT1_TX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	/* port 2 */
	CLK_LOOKUP(0x4D0, 0x301, 0x4D4, 0, 0x50C, NSS_PORT2_RX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4D0, 0x301, 0x4D4, 0, 0x584, UNIPHY1_PORT5_RX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4D0, 0x303, 0x4D4, 0, 0x50C, NSS_PORT2_RX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4D0, 0x303, 0x4D4, 0, 0x584, UNIPHY1_PORT5_RX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4D0, 0x307, 0x4D4, 0, 0x50C, NSS_PORT2_RX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4D0, 0x307, 0x4D4, 0, 0x584, UNIPHY1_PORT5_RX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4D0, 0x304, 0x4D4, 0, 0x50C, NSS_PORT2_RX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4D0, 0x304, 0x4D4, 0, 0x584, UNIPHY1_PORT5_RX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4D0, 0x318, 0x4D4, 1, 0x50C, NSS_PORT2_RX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4D0, 0x318, 0x4D4, 1, 0x584, UNIPHY1_PORT5_RX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	/* XGMAC used, so 1.25M for 10Mbps 312.5/12.5/20 */
	CLK_LOOKUP(0x4D0, 0x318, 0x4D4, 0x13, 0x50C, NSS_PORT2_RX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4D0, 0x318, 0x4D4, 0x13, 0x584, UNIPHY1_PORT5_RX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4D0, 0x301, 0x4D4, 0, 0x50C, NSS_PORT2_RX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),
	CLK_LOOKUP(0x4D0, 0x301, 0x4D4, 0, 0x584, UNIPHY1_PORT5_RX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),

	CLK_LOOKUP(0x4D0, 0x301, 0x4D4, 0, 0x50C, NSS_PORT2_RX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4D0, 0x301, 0x4D4, 0, 0x584, UNIPHY1_PORT5_RX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4D0, 0x309, 0x4D4, 0, 0x50C, NSS_PORT2_RX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4D0, 0x309, 0x4D4, 0, 0x584, UNIPHY1_PORT5_RX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4D0, 0x318, 0x4D4, 3, 0x50C, NSS_PORT2_RX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4D0, 0x318, 0x4D4, 3, 0x584, UNIPHY1_PORT5_RX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4DC, 0x401, 0x4E0, 0, 0x514, NSS_PORT2_TX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4DC, 0x401, 0x4E0, 0, 0x588, UNIPHY1_PORT5_TX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4DC, 0x403, 0x4E0, 0, 0x514, NSS_PORT2_TX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4DC, 0x403, 0x4E0, 0, 0x588, UNIPHY1_PORT5_TX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4DC, 0x407, 0x4E0, 0, 0x514, NSS_PORT2_TX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4DC, 0x407, 0x4E0, 0, 0x588, UNIPHY1_PORT5_TX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4DC, 0x404, 0x4E0, 0, 0x514, NSS_PORT2_TX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4DC, 0x404, 0x4E0, 0, 0x588, UNIPHY1_PORT5_TX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4DC, 0x418, 0x4E0, 1, 0x514, NSS_PORT2_TX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4DC, 0x418, 0x4E0, 1, 0x588, UNIPHY1_PORT5_TX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	/* XGMAC used, so 1.25M for 10Mbps 312.5/12.5/20 */
	CLK_LOOKUP(0x4DC, 0x418, 0x4E0, 0x13, 0x514, NSS_PORT2_TX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4DC, 0x418, 0x4E0, 0x13, 0x588, UNIPHY1_PORT5_TX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4DC, 0x401, 0x4E0, 0, 0x514, NSS_PORT2_TX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),
	CLK_LOOKUP(0x4DC, 0x401, 0x4E0, 0, 0x588, UNIPHY1_PORT5_TX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),

	CLK_LOOKUP(0x4DC, 0x401, 0x4E0, 0, 0x514, NSS_PORT2_TX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4DC, 0x401, 0x4E0, 0, 0x588, UNIPHY1_PORT5_TX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4DC, 0x409, 0x4E0, 0, 0x514, NSS_PORT2_TX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4DC, 0x409, 0x4E0, 0, 0x588, UNIPHY1_PORT5_TX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4DC, 0x418, 0x4E0, 3, 0x514, NSS_PORT2_TX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4DC, 0x418, 0x4E0, 3, 0x588, UNIPHY1_PORT5_TX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	/* port 3 */
	CLK_LOOKUP(0x4E8, 0x301, 0x4EC, 0, 0x51C, NSS_PORT3_RX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4E8, 0x301, 0x4EC, 0, 0x58C, UNIPHY2_PORT6_RX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4E8, 0x303, 0x4EC, 0, 0x51C, NSS_PORT3_RX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4E8, 0x303, 0x4EC, 0, 0x58C, UNIPHY2_PORT6_RX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4E8, 0x307, 0x4EC, 0, 0x51C, NSS_PORT3_RX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4E8, 0x307, 0x4EC, 0, 0x58C, UNIPHY2_PORT6_RX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4E8, 0x304, 0x4EC, 0, 0x51C, NSS_PORT3_RX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4E8, 0x304, 0x4EC, 0, 0x58C, UNIPHY2_PORT6_RX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4E8, 0x318, 0x4EC, 1, 0x51C, NSS_PORT3_RX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4E8, 0x318, 0x4EC, 1, 0x58C, UNIPHY2_PORT6_RX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	/* XGMAC used, so 1.25M for 10Mbps 312.5/12.5/20 */
	CLK_LOOKUP(0x4E8, 0x318, 0x4EC, 0x13, 0x51C, NSS_PORT3_RX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4E8, 0x318, 0x4EC, 0x13, 0x58C, UNIPHY2_PORT6_RX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4E8, 0x301, 0x4EC, 0, 0x51C, NSS_PORT3_RX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),
	CLK_LOOKUP(0x4E8, 0x301, 0x4EC, 0, 0x58C, UNIPHY2_PORT6_RX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),

	CLK_LOOKUP(0x4E8, 0x301, 0x4EC, 0, 0x51C, NSS_PORT3_RX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4E8, 0x301, 0x4EC, 0, 0x58C, UNIPHY2_PORT6_RX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4E8, 0x309, 0x4EC, 0, 0x51C, NSS_PORT3_RX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4E8, 0x309, 0x4EC, 0, 0x58C, UNIPHY2_PORT6_RX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4E8, 0x318, 0x4EC, 3, 0x51C, NSS_PORT3_RX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4E8, 0x318, 0x4EC, 3, 0x58C, UNIPHY2_PORT6_RX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4F4, 0x401, 0x4F8, 0, 0x524, NSS_PORT3_TX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4F4, 0x401, 0x4F8, 0, 0x590, UNIPHY2_PORT6_TX_CLK, EN_BIT,
			USXGMII_SPEED_10000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4F4, 0x403, 0x4F8, 0, 0x524, NSS_PORT3_TX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4F4, 0x403, 0x4F8, 0, 0x590, UNIPHY2_PORT6_TX_CLK, EN_BIT,
			USXGMII_SPEED_5000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4F4, 0x407, 0x4F8, 0, 0x524, NSS_PORT3_TX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4F4, 0x407, 0x4F8, 0, 0x590, UNIPHY2_PORT6_TX_CLK, EN_BIT,
			USXGMII_SPEED_2500M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4F4, 0x404, 0x4F8, 0, 0x524, NSS_PORT3_TX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4F4, 0x404, 0x4F8, 0, 0x590, UNIPHY2_PORT6_TX_CLK, EN_BIT,
			USXGMII_SPEED_1000M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4F4, 0x418, 0x4F8, 1, 0x524, NSS_PORT3_TX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4F4, 0x418, 0x4F8, 1, 0x590, UNIPHY2_PORT6_TX_CLK, EN_BIT,
			USXGMII_SPEED_100M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	/* XGMAC used, so 1.25M for 10Mbps 312.5/12.5/20 */
	CLK_LOOKUP(0x4F4, 0x418, 0x4F8, 0x13, 0x524, NSS_PORT3_TX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4F4, 0x418, 0x4F8, 0x13, 0x590, UNIPHY2_PORT6_TX_CLK, EN_BIT,
			USXGMII_SPEED_10M_CLK, USXGMII_SPEED_10000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4F4, 0x401, 0x4F8, 0, 0x524, NSS_PORT3_TX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),
	CLK_LOOKUP(0x4F4, 0x401, 0x4F8, 0, 0x590, UNIPHY2_PORT6_TX_CLK, EN_BIT,
			SGMII_PLUS_SPEED_2500M_CLK, SGMII_PLUS_SPEED_2500M_CLK, A_FALSE),

	CLK_LOOKUP(0x4F4, 0x401, 0x4F8, 0, 0x524, NSS_PORT3_TX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4F4, 0x401, 0x4F8, 0, 0x590, UNIPHY2_PORT6_TX_CLK, EN_BIT,
			SGMII_SPEED_1000M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4F4, 0x409, 0x4F8, 0, 0x524, NSS_PORT3_TX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4F4, 0x409, 0x4F8, 0, 0x590, UNIPHY2_PORT6_TX_CLK, EN_BIT,
			SGMII_SPEED_100M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),

	CLK_LOOKUP(0x4F4, 0x418, 0x4F8, 3, 0x524, NSS_PORT3_TX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
	CLK_LOOKUP(0x4F4, 0x418, 0x4F8, 3, 0x590, UNIPHY2_PORT6_TX_CLK, EN_BIT,
			SGMII_SPEED_10M_CLK, SGMII_SPEED_1000M_CLK, A_FALSE),
#endif
};

struct clk_data_t *ssdk_clock_find(const char *clock_id, unsigned int rate, unsigned int prate)
{
	int i = 0;
	struct clk_data_t *clk_inst = NULL;

	for (i = 0; i < ARRAY_SIZE(mppe_clk_tbl); i++) {
		clk_inst = &mppe_clk_tbl[i];

		if (!strncmp(clock_id, clk_inst->clk_id, strlen(clock_id)))
			if (rate == 0 || (clk_inst->rate == rate &&
						(clk_inst->prate == PPE_CLK_UNAWARE_RATE ||
						 clk_inst->prate == prate)))
					break;
		clk_inst = NULL;
	}

	return clk_inst;
}

a_bool_t ssdk_clock_en_set(const char *clock_id, a_bool_t enable)
{
	struct clk_data_t *clk_inst = NULL;

	clk_inst = ssdk_clock_find(clock_id, 0, PPE_CLK_UNAWARE_RATE);
	if (!clk_inst) {
		SSDK_DEBUG("Cant find the clock %s\n", clock_id);
		return A_FALSE;
	}

	if (clk_inst->cbc != 0 && clk_inst->en_bit != 0) {
		void __iomem *reg_addr = NULL;
		uint32_t reg_val = 0, reg_val_old = 0;

		if (clk_inst->is_gcc)
			reg_addr = gcc_clk_base_g + clk_inst->cbc;
		else
			reg_addr = nsscc_clk_base_g + clk_inst->cbc;

		reg_val_old = readl(reg_addr);
		if (enable)
			reg_val = reg_val_old | clk_inst->en_bit;
		else
			reg_val = reg_val_old & ~clk_inst->en_bit;

		if (reg_val_old == reg_val) {
			SSDK_DEBUG("%s CLK %s reg: 0x%x, val: 0x%x has no change\n",
					enable ? "Enable" : "Disable",
					clk_inst->clk_id, clk_inst->cbc, reg_val);
		} else {
			writel(reg_val, reg_addr);
			SSDK_DEBUG("%s CLK %s reg: 0x%x, val: 0x%x\n",
					enable ? "Enable" : "Disable",
					clk_inst->clk_id, clk_inst->cbc, reg_val);
		}
		return A_TRUE;
	}
	SSDK_DEBUG("CLK %s CBC REG or EN_BIT is not available\n", clock_id);

	return A_FALSE;
}

a_bool_t ssdk_clock_rate_set(const char *clock_id, unsigned int rate);

#if 0
/* This funciton is for resetting the clock that is not defined in the DTS */
a_bool_t ssdk_raw_reset_control(const char *node_name, unsigned int reset_index, a_uint32_t action)
{
	struct rst_data_t *rst_inst = NULL;
	a_bool_t is_found = A_FALSE;
	void __iomem *clk_base = NULL;
	uint32_t reg_val = 0;
	int i = 0;

	for (i = 0; i < ARRAY_SIZE(mppe_rst_tbl); i++) {
		rst_inst = &mppe_rst_tbl[i];
		if (strcmp(node_name, rst_inst->node_name))
			continue;

		if (reset_index == rst_inst->rst_index)
			break;
	}

	if (!strcmp(node_name, GCC_NODE_NAME)) {
		clk_base = gcc_clk_base_g;
	} else if (!strcmp(node_name, NSSCC_NODE_NAME)) {
		clk_base = nsscc_clk_base_g;
	} else {
		SSDK_ERROR("Unknown Reset Name: %s\n", node_name);
		return A_FALSE;
	}

	if (i < ARRAY_SIZE(mppe_rst_tbl)) {
		reg_val = readl(clk_base + rst_inst->cbc);

		if (action == SSDK_RESET_ASSERT)
			reg_val |= rst_inst->rst_bits;
		else
			reg_val &= ~rst_inst->rst_bits;

		writel(reg_val, clk_base + rst_inst->cbc);
		SSDK_DEBUG("%s reset_id: %d CBC reg: 0x%x, val: 0x%x\n",
				action == SSDK_RESET_ASSERT ? "Assert" : "Deassert",
				reset_index, rst_inst->cbc, reg_val);

		is_found = A_TRUE;
	} else {
		SSDK_ERROR("Can't find the node name %s reset ID %d\n", node_name, reset_index);
		is_found = A_FALSE;
	}

	return is_found;
}
#endif

a_bool_t ssdk_reset_find(struct reset_control *rst,
			 struct rst_data_t **rst_inst,
			 void __iomem **clk_base)
{
	struct device_node *clk_node = NULL;
	struct reset_controller_dev *rcdev = NULL;
	struct rst_data_t *rst_inst_tmp;
	int i = 0;

	rcdev = rst->rcdev;
	clk_node = rcdev->of_node;
	if (!clk_node) {
		SSDK_DEBUG("clock node is null\n");
		return A_FALSE;
	}

	if (!strcmp(clk_node->full_name, GCC_NODE_NAME)) {
		*clk_base = gcc_clk_base_g;
	} else if (!strcmp(clk_node->full_name, NSSCC_NODE_NAME)) {
		*clk_base = nsscc_clk_base_g;
	} else {
		SSDK_DEBUG("Unknown Reset Name: %s\n", clk_node->full_name);
		return A_FALSE;
	}

	if (!(*clk_base)) {
		SSDK_DEBUG("clk_base is not ioremap_nocache on %s\n", clk_node->full_name);
		return A_FALSE;
	}

	for (i = 0; i < ARRAY_SIZE(mppe_rst_tbl); i++) {
		rst_inst_tmp = &mppe_rst_tbl[i];
		if (strcmp(clk_node->full_name, rst_inst_tmp->node_name)) {
			continue;
		}

		if (rst->id == rst_inst_tmp->rst_index) {
			*rst_inst = rst_inst_tmp;
			return A_TRUE;
		}
	}

	return A_FALSE;
}

a_bool_t ssdk_reset_control(struct reset_control *rst, a_uint32_t action)
{
	struct rst_data_t *rst_inst = NULL;
	void __iomem *clk_base = NULL;
	uint32_t reg_val = 0;

	if (!rst) {
		SSDK_DEBUG("reset_control is null\n");
		return A_FALSE;
	}

	if (!ssdk_reset_find(rst, &rst_inst, &clk_base)) {
		SSDK_DEBUG("Can't find the reset ID %d\n", rst->id);
		return A_FALSE;
	}

	reg_val = readl(clk_base + rst_inst->cbc);

	if (action == SSDK_RESET_ASSERT)
		reg_val |= rst_inst->rst_bits;
	else
		reg_val &= ~rst_inst->rst_bits;

	writel(reg_val, clk_base + rst_inst->cbc);
	SSDK_DEBUG("%s reset_id: %d CBC reg: 0x%x, val: 0x%x\n",
		   action == SSDK_RESET_ASSERT ? "Assert" : "Deassert",
		   rst->id, rst_inst->cbc, reg_val);

	return A_TRUE;
}

static bool ssdk_raw_clock_rate_set_and_enable(a_uint8_t* clock_id,
						   a_uint32_t rate)
{
	bool ret = A_TRUE;

	if (rate)
		ret = ssdk_clock_rate_set(clock_id, rate);

	if (!ret)
		return ret;

	return ssdk_clock_en_set(clock_id, A_TRUE);

}
#endif

/* below 3 routines to be used as common */
void ssdk_clock_rate_set_and_enable(
	struct device_node *node, a_uint8_t* clock_id, a_uint32_t rate)
{
	struct clk *clk;

#if defined(MRPPE)
	if ((!strcmp("uniphy0_sys_clk", clock_id)) ||
			(!strcmp("uniphy0_ahb_clk", clock_id))) {
		if (ssdk_uniphy_valid_check(0, SSDK_UNIPHY_INSTANCE0,
					PORT_WRAPPER_MAX) == A_FALSE) {
			return;
		}
	}
	if ((!strcmp("uniphy1_sys_clk", clock_id)) ||
			(!strcmp("uniphy1_ahb_clk", clock_id))) {
		if (ssdk_uniphy_valid_check(0, SSDK_UNIPHY_INSTANCE1,
					PORT_WRAPPER_MAX) == A_FALSE) {
			return;
		}
	}
	if ((!strcmp("uniphy2_sys_clk", clock_id)) ||
			(!strcmp("uniphy2_ahb_clk", clock_id))) {
		if (ssdk_uniphy_valid_check(0, SSDK_UNIPHY_INSTANCE2,
					PORT_WRAPPER_MAX) == A_FALSE) {
			return;
		}
	}
#endif
#if defined(SSDK_RAW_CLOCK)
	if (ssdk_raw_clock_rate_set_and_enable(clock_id, rate))
		return;
#endif
	clk = of_clk_get_by_name(node, clock_id);
	if (!IS_ERR(clk)) {
		if (rate) {
			clk_set_rate(clk, rate);
		}
		clk_prepare_enable(clk);
	}
}

void ssdk_gcc_reset(struct reset_control *rst, a_uint32_t action)
{
#if defined(SSDK_RAW_CLOCK)
	if (ssdk_reset_control(rst, action))
		return;
#endif

	if (action == SSDK_RESET_ASSERT)
		reset_control_assert(rst);
	else
		reset_control_deassert(rst);

}

void ssdk_uniphy_reset(
	a_uint32_t dev_id,
	enum unphy_rst_type rst_type,
	a_uint32_t action)
{
	struct reset_control *rst;

	rst = uniphy_rsts[rst_type];
	if (IS_ERR(rst)) {
		SSDK_ERROR("reset(%d) not exist!\n", rst_type);
		return;
	}

	ssdk_gcc_reset(rst, action);
}

void ssdk_port_reset(
	a_uint32_t dev_id,
	a_uint32_t port_id,
	a_uint32_t action)
{
	struct reset_control *rst;

	if ((port_id < SSDK_PHYSICAL_PORT1) || (port_id > SSDK_PHYSICAL_PORT6))
		return;

	if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq95xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq53xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq54xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq52xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq96xx")) {
		struct reset_control *mac_rst = NULL;

		mac_rst = port_mac_rsts[port_id - 1];
		if (IS_ERR(mac_rst)) {
			SSDK_ERROR("appe port mac reset(%d) not exist!\n", port_id);
			return;
		}
		ssdk_gcc_reset(mac_rst, action);
	}

#if defined(MPPE)
	if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq53xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq54xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq52xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq96xx")) {
		/* reset RX */
		rst = port_rsts[2 * (port_id - 1)];
		if (IS_ERR(rst)) {
			SSDK_ERROR("port RX reset(%d) not exist!\n", port_id);
			return;
		}
		ssdk_gcc_reset(rst, action);

		/* reset TX */
		rst = port_rsts[2 * (port_id - 1) + 1];
		if (IS_ERR(rst)) {
			SSDK_ERROR("port TX reset(%d) not exist!\n", port_id);
			return;
		}
		ssdk_gcc_reset(rst, action);
	} else
#endif
	{
		rst = port_rsts[port_id - 1];
		if (IS_ERR(rst)) {
			SSDK_ERROR("port reset(%d) not exist!\n", port_id);
			return;
		}
		ssdk_gcc_reset(rst, action);
	}
}

void ssdk_uniphy_clock_rate_set(
	a_uint32_t dev_id,
	enum unphy_clk_type clock_type,
	a_uint32_t rate)
{
	struct clk *uniphy_clk;

#if defined(MRPPE)
	if ((clock_type == NSS_PORT1_RX_CLK_E) ||
		(clock_type == NSS_PORT1_TX_CLK_E)) {
		if (ssdk_uniphy_valid_check(dev_id, SSDK_UNIPHY_INSTANCE0,
			PORT_WRAPPER_MAX) == A_FALSE) {
			return;
		}
	}
	if ((clock_type == NSS_PORT2_RX_CLK_E) ||
		(clock_type == NSS_PORT2_TX_CLK_E)) {
		if (ssdk_uniphy_valid_check(dev_id, SSDK_UNIPHY_INSTANCE1,
			PORT_WRAPPER_MAX) == A_FALSE) {
			return;
		}
	}
	if ((clock_type == NSS_PORT3_RX_CLK_E) ||
		(clock_type == NSS_PORT3_TX_CLK_E)) {
		if (ssdk_uniphy_valid_check(dev_id, SSDK_UNIPHY_INSTANCE2,
			PORT_WRAPPER_MAX) == A_FALSE) {
			return;
		}
	}
#else
	if ((clock_type == NSS_PORT5_RX_CLK_E) ||
		(clock_type == NSS_PORT5_TX_CLK_E)) {
		a_uint32_t mode;
		mode = ssdk_dt_global_get_mac_mode(dev_id, SSDK_UNIPHY_INSTANCE1);
		if (mode != PORT_WRAPPER_MAX) {
			if (ssdk_uniphy_valid_check(dev_id, SSDK_UNIPHY_INSTANCE1,
				PORT_WRAPPER_MAX) == A_FALSE) {
				return;
			}
		}
	}
	if ((clock_type == NSS_PORT6_RX_CLK_E) ||
		(clock_type == NSS_PORT6_TX_CLK_E)) {
		if (ssdk_uniphy_valid_check(dev_id, SSDK_UNIPHY_INSTANCE2,
			PORT_WRAPPER_MAX) == A_FALSE) {
			return;
		}
	}
#endif
	uniphy_clk = uniphy_port_clks[clock_type];
	if (!IS_ERR_OR_NULL(uniphy_clk)) {
		if (rate) {
#if defined(SSDK_RAW_CLOCK)
			if (!ssdk_clock_rate_set(uniphy_clk->con_id, rate))
#endif
				if (clk_set_rate(uniphy_clk, rate))
					SSDK_INFO("%d set rate=%d fail\n", clock_type, rate);
		}
	} else
		SSDK_INFO("%d set rate %x fail!\n", clock_type, rate);
}

void ssdk_uniphy_clock_enable(
	a_uint32_t dev_id,
	enum unphy_clk_type clock_type,
	a_bool_t enable)
{
	struct clk *uniphy_clk;

#if defined(MRPPE)
	if ((clock_type == UNIPHY0_PORT1_RX_CLK_E) ||
		(clock_type == UNIPHY0_PORT1_TX_CLK_E)) {
		if (ssdk_uniphy_valid_check(dev_id,
			SSDK_UNIPHY_INSTANCE0,PORT_WRAPPER_MAX) == A_FALSE) {
			return;
		}
	}
	if ((clock_type == UNIPHY1_PORT5_RX_CLK_E) ||
		(clock_type == UNIPHY1_PORT5_TX_CLK_E)) {
		if (ssdk_uniphy_valid_check(dev_id,
			SSDK_UNIPHY_INSTANCE1,PORT_WRAPPER_MAX) == A_FALSE) {
			return;
		}
	}
#else
	if ((clock_type == UNIPHY0_PORT5_RX_CLK_E) ||
		(clock_type == UNIPHY0_PORT5_TX_CLK_E)) {
		a_uint32_t mode;
		mode = ssdk_dt_global_get_mac_mode(dev_id, SSDK_UNIPHY_INSTANCE1);
		if (mode != PORT_WRAPPER_MAX) {
			if (ssdk_uniphy_valid_check(dev_id,
				SSDK_UNIPHY_INSTANCE1, PORT_WRAPPER_MAX) == A_FALSE) {
				return;
			}
		}
	}
#endif
	if ((clock_type == UNIPHY2_PORT6_RX_CLK_E) ||
		(clock_type == UNIPHY2_PORT6_TX_CLK_E)) {
		if (ssdk_uniphy_valid_check(dev_id,
			SSDK_UNIPHY_INSTANCE2,PORT_WRAPPER_MAX) == A_FALSE) {
			return;
		}
	}
	uniphy_clk = uniphy_port_clks[clock_type];
	if (!IS_ERR_OR_NULL(uniphy_clk)) {
#if defined(SSDK_RAW_CLOCK)
		if (!ssdk_clock_en_set(uniphy_clk->con_id, enable))
#endif
		{
			if (enable) {
				if (clk_prepare_enable(uniphy_clk))
					SSDK_ERROR("clock enable fail!\n");
			} else
				clk_disable_unprepare(uniphy_clk);
		}
	} else {
		SSDK_DEBUG("clock_type= %d enable=%d not find\n",
				clock_type, enable);
	}
}

struct clk_uniphy {
	struct clk_hw hw;
	u8 uniphy_index;
	u8 dir;
	unsigned long rate;
};

#define to_clk_uniphy(_hw) container_of(_hw, struct clk_uniphy, hw)

static unsigned long
uniphy_clks_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
	struct clk_uniphy *uniphy = to_clk_uniphy(hw);

	return uniphy->rate;
}

static int
uniphy_clks_determine_rate(struct clk_hw *hw, struct clk_rate_request *req)
{
	/* add logic for checking the current mode */
	if (req->rate <= UNIPHY_CLK_RATE_125M)
		req->rate = UNIPHY_CLK_RATE_125M;
	else
		req->rate = UNIPHY_CLK_RATE_312M;

	return 0;
}

static int
uniphy_clks_set_rate(struct clk_hw *hw, unsigned long rate,
		     unsigned long parent_rate)
{
	struct clk_uniphy *uniphy = to_clk_uniphy(hw);

	if (rate != UNIPHY_CLK_RATE_125M && rate != UNIPHY_CLK_RATE_312M)
		return -1;

	uniphy->rate = rate;

	return 0;
}

static const struct clk_ops clk_uniphy_ops = {
	.recalc_rate = uniphy_clks_recalc_rate,
	.determine_rate = uniphy_clks_determine_rate,
	.set_rate = uniphy_clks_set_rate,
};

static struct clk_uniphy uniphy0_gcc_rx_clk = {
                .hw.init = &(struct clk_init_data){
                        .name = "uniphy0_gcc_rx_clk",
                        .ops = &clk_uniphy_ops,
                },
		.uniphy_index = 0,
		.dir = UNIPHY_RX,
		.rate = UNIPHY_DEFAULT_RATE,
};

static struct clk_uniphy uniphy0_gcc_tx_clk = {
                .hw.init = &(struct clk_init_data){
                        .name = "uniphy0_gcc_tx_clk",
                        .ops = &clk_uniphy_ops,
                },
		.uniphy_index = 0,
		.dir = UNIPHY_TX,
		.rate = UNIPHY_DEFAULT_RATE,
};

static struct clk_uniphy uniphy1_gcc_rx_clk = {
                .hw.init = &(struct clk_init_data){
                        .name = "uniphy1_gcc_rx_clk",
                        .ops = &clk_uniphy_ops,
                },
		.uniphy_index = 1,
		.dir = UNIPHY_RX,
		.rate = UNIPHY_DEFAULT_RATE,
};

static struct clk_uniphy uniphy1_gcc_tx_clk = {
                .hw.init = &(struct clk_init_data){
                        .name = "uniphy1_gcc_tx_clk",
                        .ops = &clk_uniphy_ops,
                },
		.uniphy_index = 1,
		.dir = UNIPHY_TX,
		.rate = UNIPHY_DEFAULT_RATE,
};

static struct clk_uniphy uniphy2_gcc_rx_clk = {
                .hw.init = &(struct clk_init_data){
                        .name = "uniphy2_gcc_rx_clk",
                        .ops = &clk_uniphy_ops,
                },
		.uniphy_index = 2,
		.dir = UNIPHY_RX,
		.rate = UNIPHY_DEFAULT_RATE,
};

static struct clk_uniphy uniphy2_gcc_tx_clk = {
                .hw.init = &(struct clk_init_data){
                        .name = "uniphy2_gcc_tx_clk",
                        .ops = &clk_uniphy_ops,
                },
		.uniphy_index = 2,
		.dir = UNIPHY_TX,
		.rate = UNIPHY_DEFAULT_RATE,
};

static struct clk_hw *uniphy_raw_clks[SSDK_MAX_UNIPHY_INSTANCE * 2] = {
	&uniphy0_gcc_rx_clk.hw, &uniphy0_gcc_tx_clk.hw,
	&uniphy1_gcc_rx_clk.hw, &uniphy1_gcc_tx_clk.hw,
	&uniphy2_gcc_rx_clk.hw, &uniphy2_gcc_tx_clk.hw,
};

static char *ppe_clk_ids[UNIPHYT_CLK_MAX] = {
	NSS_PORT1_RX_CLK,
	NSS_PORT1_TX_CLK,
	NSS_PORT2_RX_CLK,
	NSS_PORT2_TX_CLK,
	NSS_PORT3_RX_CLK,
	NSS_PORT3_TX_CLK,
	NSS_PORT4_RX_CLK,
	NSS_PORT4_TX_CLK,
	NSS_PORT5_RX_CLK,
	NSS_PORT5_TX_CLK,
	NSS_PORT6_RX_CLK,
	NSS_PORT6_TX_CLK,
	UNIPHY0_PORT1_RX_CLK,
	UNIPHY0_PORT1_TX_CLK,
	UNIPHY0_PORT2_RX_CLK,
	UNIPHY0_PORT2_TX_CLK,
	UNIPHY0_PORT3_RX_CLK,
	UNIPHY0_PORT3_TX_CLK,
	UNIPHY0_PORT4_RX_CLK,
	UNIPHY0_PORT4_TX_CLK,
	UNIPHY0_PORT5_RX_CLK,
	UNIPHY0_PORT5_TX_CLK,
	UNIPHY1_PORT5_RX_CLK,
	UNIPHY1_PORT5_TX_CLK,
	UNIPHY2_PORT6_RX_CLK,
	UNIPHY2_PORT6_TX_CLK,
	PORT5_RX_SRC,
	PORT5_TX_SRC
};

static void ssdk_ppe_uniphy_clock_init(adpt_ppe_type_t chip_type)
{
	a_uint32_t i, inst_num = 0;
	struct clk *clk;

	switch (chip_type) {
		case HPPE_TYPE:
		case APPE_TYPE:
		case MRPPE_TYPE:
		case JHPPE_TYPE:
		case HMSPPE_TYPE:
			inst_num = SSDK_MAX_UNIPHY_INSTANCE;
			break;
		case CPPE_TYPE:
		case MPPE_TYPE:
			inst_num = SSDK_MAX_UNIPHY_INSTANCE - 1;
			break;
		default:
			SSDK_ERROR("Unsupported chip type: %d\n", chip_type);
			return;
	}

	for (i = 0; i < inst_num * 2; i++) {
		clk = clk_register(NULL, uniphy_raw_clks[i]);
		if (IS_ERR(clk))
			SSDK_ERROR("Clk register %d fail!\n", i);
	}

	for (i = 0; i < ARRAY_SIZE(ppe_clk_ids); i++) {
		uniphy_port_clks[i] = of_clk_get_by_name(clock_node, ppe_clk_ids[i]);
		if (IS_ERR(uniphy_port_clks[i]))
			continue;
		if (i != PORT5_RX_SRC_E && i != PORT5_TX_SRC_E)
			ssdk_uniphy_clock_enable(0, i, A_TRUE);
	}

	return;
}

static void ssdk_ppe_uniphy_clock_deinit(adpt_ppe_type_t chip_type)
{
	a_uint32_t i, inst_num = 0;

	switch (chip_type) {
	case HPPE_TYPE:
	case APPE_TYPE:
	case MRPPE_TYPE:
	case JHPPE_TYPE:
	case HMSPPE_TYPE:
		inst_num = SSDK_MAX_UNIPHY_INSTANCE;
		break;
	case CPPE_TYPE:
	case MPPE_TYPE:
		inst_num = SSDK_MAX_UNIPHY_INSTANCE - 1;
		break;
	default:
		SSDK_ERROR("Unsupported chip type: %d\n", chip_type);
		return;
	}

	for (i = 0; i < ARRAY_SIZE(ppe_clk_ids); i++) {
		if (IS_ERR(uniphy_port_clks[i]))
			continue;
		/* disable and unprepare uniphy port and nss port clock */
		if (i != PORT5_RX_SRC_E && i != PORT5_TX_SRC_E)
			ssdk_uniphy_clock_enable(0, i, A_FALSE);

		/* put clock */
		clk_put(uniphy_port_clks[i]);
	}

	/* unregister uniphy raw clock */
	for (i = 0; i < inst_num * 2; i++)
		clk_hw_unregister(uniphy_raw_clks[i]);
}

#if defined(SSDK_RAW_CLOCK)
struct clk_data_t *ssdk_clk_to_clk_data(const char *clock_id, unsigned int rate)
{
	unsigned int prate = PPE_CLK_UNAWARE_RATE;
	uint32_t clk_id = 0xff;

	if (strstr(clock_id, "port1_rx"))
		clk_id = SSDK_UNIPHY_INSTANCE0 * 2 + UNIPHY_RX;
	else if (strstr(clock_id, "port1_tx"))
		clk_id = SSDK_UNIPHY_INSTANCE0 * 2 + UNIPHY_TX;
	else if (strstr(clock_id, "port2_rx"))
		clk_id = SSDK_UNIPHY_INSTANCE1 * 2 + UNIPHY_RX;
	else if (strstr(clock_id, "port2_tx"))
		clk_id = SSDK_UNIPHY_INSTANCE1 * 2 + UNIPHY_TX;
	else if (strstr(clock_id, "port3_rx"))
		clk_id = SSDK_UNIPHY_INSTANCE2 * 2 + UNIPHY_RX;
	else if (strstr(clock_id, "port3_tx"))
		clk_id = SSDK_UNIPHY_INSTANCE2 * 2 + UNIPHY_TX;

	if (clk_id != 0xff) {
		prate = clk_get_rate(uniphy_raw_clks[clk_id]->clk);
		SSDK_DEBUG("UNIPHY CLK %s prate: %d for the clock %s rate %d set\n",
				__clk_get_name(uniphy_raw_clks[clk_id]->clk), prate,
				clock_id, rate);
	}

	return ssdk_clock_find(clock_id, rate, prate);
}

a_bool_t ssdk_raw_clock_rate_set(struct clk_data_t *clk_inst, unsigned int rate)
{
	void __iomem *clk_base = NULL;
	uint32_t reg_val = 0;

	if (!clk_inst) {
		SSDK_DEBUG("clk_inst is NULL\n");
		return A_FALSE;
	}

	if (clk_inst->is_gcc)
		clk_base = gcc_clk_base_g;
	else
		clk_base = nsscc_clk_base_g;

	if (clk_inst->rcg != 0) {
		reg_val = readl(clk_base + clk_inst->rcg);

		if (reg_val != clk_inst->rcg_val) {
			writel(clk_inst->rcg_val, clk_base + clk_inst->rcg);
			SSDK_DEBUG("CLK %s rate: %d RCG: 0x%x, val: 0x%x\n", clk_inst->clk_id,
					rate, clk_inst->rcg, clk_inst->rcg_val);

			/* Update cmd register */
			reg_val = readl(clk_base + clk_inst->rcg - 4);
			reg_val |= RCGR_CMD_UPDATE;
			writel(reg_val, clk_base + clk_inst->rcg - 4);
			usleep_range(1000, 1100);
			SSDK_DEBUG("CLK %s rate: %d CMD: 0x%x, write val: 0x%x read val: 0x%x\n",
					clk_inst->clk_id, rate, clk_inst->rcg - 4,
					reg_val, readl(clk_base + clk_inst->rcg - 4));
		}

	}

	if (clk_inst->cdiv != 0) {
		reg_val = readl(clk_base + clk_inst->cdiv);

		if (reg_val != clk_inst->cdiv_val) {
			writel(clk_inst->cdiv_val, clk_base + clk_inst->cdiv);
			SSDK_DEBUG("CLK %s rate: %d CDIV: 0x%x, val: 0x%x\n", clk_inst->clk_id,
					rate, clk_inst->cdiv, clk_inst->cdiv_val);
		}
	}

	return A_TRUE;
}

a_bool_t ssdk_clock_rate_set(const char *clock_id, unsigned int rate)
{
	struct clk_data_t *clk_inst = ssdk_clk_to_clk_data(clock_id, rate);

	if (clk_inst != NULL)
		return ssdk_raw_clock_rate_set(clk_inst, rate);

	return A_FALSE;
}

#endif

void ssdk_port_mac_clock_reset(
	a_uint32_t dev_id,
	a_uint32_t port_id)
{
	ssdk_port_reset(dev_id, port_id, SSDK_RESET_ASSERT);
	msleep(10);
	ssdk_port_reset(dev_id, port_id, SSDK_RESET_DEASSERT);
	return;
}

static
void ssdk_uniphy1_clock_source_set(void)
{
	if (ssdk_uniphy_valid_check(0,
		SSDK_UNIPHY_INSTANCE1, PORT_WRAPPER_MAX) == A_FALSE) {
		SSDK_INFO("UNIPHY 1 is not available on this SKU!\n");
		return;
	}

	clk_set_parent(uniphy_port_clks[PORT5_RX_SRC_E],
			uniphy_raw_clks[2]->clk);
	clk_set_parent(uniphy_port_clks[PORT5_TX_SRC_E],
			uniphy_raw_clks[3]->clk);
}

void ssdk_uniphy_raw_clock_reset(a_uint8_t uniphy_index)
{
	a_uint32_t id;

	if (uniphy_index >= SSDK_MAX_UNIPHY_INSTANCE)
		return;

	id = uniphy_index*2;
	if (clk_set_rate(uniphy_raw_clks[id]->clk, UNIPHY_DEFAULT_RATE))
		SSDK_ERROR("set rate for %d fail!\n", id);
	if (clk_set_rate(uniphy_raw_clks[id+1]->clk, UNIPHY_DEFAULT_RATE))
		SSDK_ERROR("set rate for %d fail!\n", id+1);

}

void ssdk_uniphy_raw_clock_set(
	a_uint8_t uniphy_index,
	a_uint8_t direction,
	a_uint32_t clock)
{
	a_uint32_t old_clock, id, mode;
	a_uint32_t rate = 0;

	if ((uniphy_index >= SSDK_MAX_UNIPHY_INSTANCE) ||
	     ((direction != UNIPHY_TX) && (direction != UNIPHY_RX)) ||
	     (clock != UNIPHY_CLK_RATE_125M &&
	      clock != UNIPHY_CLK_RATE_312M)) {
		SSDK_ERROR("invalid uniphy: %d or clock: %d\n", uniphy_index, clock);
		return;
	}

	id = uniphy_index*2 + direction;
	old_clock = clk_get_rate(uniphy_raw_clks[id]->clk);

#if defined(MPPE)
	if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq53xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq54xx")) {
		if (clock != old_clock) {
			if (clk_set_rate(uniphy_raw_clks[id]->clk, clock))
				SSDK_ERROR("set clock rate: %d fail!\n", clock);
		}
		return;
	}
#endif

	if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq95xx")) {
		rate = NSS_APPE_PORT5_DFLT_RATE;
	} else if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq807x")) {
		rate = NSS_HPPE_PORT5_DFLT_RATE;
	} else if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq60xx")) {
		rate = NSS_CPPE_PORT5_DFLT_RATE;
	} else {
		SSDK_INFO("invalid device in uniphy raw clock set!\n");
	}

	if (clock != old_clock) {
		if (uniphy_index == SSDK_UNIPHY_INSTANCE1) {
			if (UNIPHY_RX == direction)
				ssdk_uniphy_clock_rate_set(0,
						NSS_PORT5_RX_CLK_E,
						rate);
			else
				ssdk_uniphy_clock_rate_set(0,
						NSS_PORT5_TX_CLK_E,
						rate);
		}
		if (clk_set_rate(uniphy_raw_clks[id]->clk, clock))
			SSDK_ERROR("set rate: %d fail!\n", clock);
	}

	mode = ssdk_dt_global_get_mac_mode(0, SSDK_UNIPHY_INSTANCE1);
	if (((uniphy_index == SSDK_UNIPHY_INSTANCE0) &&
	     (mode == PORT_INTERFACE_MODE_MAX)) ||
	    (uniphy_index == SSDK_UNIPHY_INSTANCE1)) {
		if (clk_set_parent(uniphy_port_clks[PORT5_RX_SRC_E + direction],
				uniphy_raw_clks[id]->clk))
			SSDK_ERROR("set parent fail!\n");
	}
}

void ssdk_uniphy_port5_clock_source_set(void)
{
	a_uint32_t id, mode, i;

	if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq53xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq54xx")) {
		return;
	}
	mode = ssdk_dt_global_get_mac_mode(0, SSDK_UNIPHY_INSTANCE1);

	for (i = UNIPHY_RX; i <= UNIPHY_TX; i++) {
		if (mode == PORT_WRAPPER_MAX) {
			id = SSDK_UNIPHY_INSTANCE0*2 + i;
		} else {
			id = SSDK_UNIPHY_INSTANCE1*2 + i;
			if (ssdk_uniphy_valid_check(0, SSDK_UNIPHY_INSTANCE1,
				PORT_WRAPPER_MAX) == A_FALSE) {
				SSDK_INFO("UNIPHY 1 is not available on this SKU!\n");
				return;
			}
		}

		if (clk_set_parent(uniphy_port_clks[PORT5_RX_SRC_E + i],
			uniphy_raw_clks[id]->clk)) {
			SSDK_ERROR("set parent fail!\n");
		}
	}
}

static
void ssdk_gcc_ppe_clock_deinit(adpt_ppe_type_t chip_type)
{
	ssdk_ppe_uniphy_clock_deinit(chip_type);
}

static void ssdk_appe_fixed_clock_init(adpt_ppe_type_t chip_type)
{
	a_uint32_t noc_rate = 0, ppe_rate = 0;

	switch (chip_type) {
		case APPE_TYPE:
			noc_rate = NSS_NSSNOC_SNOC_CLK_RATE;
			ppe_rate = APPE_CLK_RATE;
			break;
		case MPPE_TYPE:
			noc_rate = MPPE_NSS_NSSNOC_SNOC_CLK_RATE;
			ppe_rate = MPPE_CLK_RATE;
			ssdk_clock_rate_set_and_enable(clock_node, IM_SLEEP_CLK, 0);
			break;
#if defined(MRPPE)
		case MRPPE_TYPE:
			noc_rate = MPPE_NSS_NSSNOC_SNOC_CLK_RATE;
			ppe_rate = MRPPE_CLK_RATE;
			ssdk_clock_rate_set_and_enable(clock_node, IM_SLEEP_CLK, 0);
			ssdk_clock_rate_set_and_enable(clock_node, NSS_CSR, NSS_NSSCC_CLK_RATE);
			ssdk_clock_rate_set_and_enable(clock_node, NSSNOC_NSS_CSR, NSS_NSSCC_CLK_RATE);
			ssdk_clock_rate_set_and_enable(clock_node, NSSCC_CE_APB, ppe_rate);
			ssdk_clock_rate_set_and_enable(clock_node, NSSCC_CE_AXI, ppe_rate);
			ssdk_clock_rate_set_and_enable(clock_node, NSSCC_NSSNOC_CE_APB, ppe_rate);
			ssdk_clock_rate_set_and_enable(clock_node, NSSCC_NSSNOC_CE_AXI, ppe_rate);
			break;
#endif
#if defined(JHPPE)
		case JHPPE_TYPE:
			noc_rate = JHPPE_NSS_NSSNOC_SNOC_CLK_RATE;
			ppe_rate = JHPPE_CLK_RATE;
			ssdk_clock_rate_set_and_enable(clock_node, IM_SLEEP_CLK, 0);
			ssdk_clock_rate_set_and_enable(clock_node, NSS_CSR, NSS_NSSCC_CLK_RATE);
			ssdk_clock_rate_set_and_enable(clock_node, NSSNOC_NSS_CSR, NSS_NSSCC_CLK_RATE);
			ssdk_clock_rate_set_and_enable(clock_node, NSSCC_CE_APB, ppe_rate);
			ssdk_clock_rate_set_and_enable(clock_node, NSSCC_CE_AXI, ppe_rate);
			ssdk_clock_rate_set_and_enable(clock_node, NSSCC_NSSNOC_CE_APB, ppe_rate);
			ssdk_clock_rate_set_and_enable(clock_node, NSSCC_NSSNOC_CE_AXI, ppe_rate);
			break;
#endif
#if defined(HMSPPE)
		case HMSPPE_TYPE:
			noc_rate = JHPPE_NSS_NSSNOC_SNOC_CLK_RATE;
			ppe_rate = HMSPPE_CLK_RATE;
			ssdk_clock_rate_set_and_enable(clock_node, IM_SLEEP_CLK, 0);
			ssdk_clock_rate_set_and_enable(clock_node, NSS_CSR, NSS_NSSCC_CLK_RATE);
			ssdk_clock_rate_set_and_enable(clock_node, NSSNOC_NSS_CSR, NSS_NSSCC_CLK_RATE);
			ssdk_clock_rate_set_and_enable(clock_node, NSSCC_PON, ppe_rate);
			break;
#endif
		default:
			SSDK_ERROR("Unknown chip type %d\n", chip_type);
			return;
	}

	/* cmn ahb and sys clk */
	ssdk_clock_rate_set_and_enable(clock_node, CMN_AHB_CLK, 0);
	ssdk_clock_rate_set_and_enable(clock_node, CMN_SYS_CLK, 0);

	/* nssnoc and nssnoc_soc clk */
	ssdk_clock_rate_set_and_enable(clock_node, NSSCC_CLK, NSS_NSSCC_CLK_RATE);
	ssdk_clock_rate_set_and_enable(clock_node, NSSNOC_NSSCC_CLK, NSS_NSSNOC_NSSCC_CLK_RATE);

	ssdk_clock_rate_set_and_enable(clock_node, NSSNOC_SNOC_CLK, noc_rate);
	ssdk_clock_rate_set_and_enable(clock_node, NSSNOC_SNOC_1_CLK, noc_rate);

	/* GCC_UNIPHY_SYS_CFG_RCGR init 24MHz */
	ssdk_clock_rate_set_and_enable(clock_node, UNIPHY0_SYS_CLK, APPE_UNIPHY_SYS_CLK_RATE);
	ssdk_clock_rate_set_and_enable(clock_node, UNIPHY1_SYS_CLK, APPE_UNIPHY_SYS_CLK_RATE);
	if (chip_type != MPPE_TYPE)
		ssdk_clock_rate_set_and_enable(clock_node, UNIPHY2_SYS_CLK, APPE_UNIPHY_SYS_CLK_RATE);

	/* GCC_PCNOC_BFDCD_CFG_RCGR init 100MHz */
	ssdk_clock_rate_set_and_enable(clock_node, UNIPHY0_AHB_CLK, UNIPHY_AHB_CLK_RATE);
	ssdk_clock_rate_set_and_enable(clock_node, UNIPHY1_AHB_CLK, UNIPHY_AHB_CLK_RATE);
	if (chip_type != MPPE_TYPE)
		ssdk_clock_rate_set_and_enable(clock_node, UNIPHY2_AHB_CLK, UNIPHY_AHB_CLK_RATE);

	/* NSS_CC_PPE_CFG_RCGR init 353MHz for APPE, 200MHZ for MPPE, 375M for MRPPE. */
	switch (chip_type) {
		case APPE_TYPE:
		case JHPPE_TYPE:
		case HMSPPE_TYPE:
			ssdk_clock_rate_set_and_enable(clock_node, PORT4_MAC_CLK, ppe_rate);
			ssdk_clock_rate_set_and_enable(clock_node, PORT5_MAC_CLK, ppe_rate);
			ssdk_clock_rate_set_and_enable(clock_node, PORT6_MAC_CLK, ppe_rate);
			fallthrough;
		case MRPPE_TYPE:
			ssdk_clock_rate_set_and_enable(clock_node, PORT3_MAC_CLK, ppe_rate);
			fallthrough;
		case MPPE_TYPE:
			ssdk_clock_rate_set_and_enable(clock_node, PORT1_MAC_CLK, ppe_rate);
			ssdk_clock_rate_set_and_enable(clock_node, PORT2_MAC_CLK, ppe_rate);
			break;
		default:
			SSDK_ERROR("Unknown chip type %d\n", chip_type);
			return;
	}

	ssdk_clock_rate_set_and_enable(clock_node, NSS_PPE_CLK, ppe_rate);
	ssdk_clock_rate_set_and_enable(clock_node, NSS_PPE_CFG_CLK, ppe_rate);
	ssdk_clock_rate_set_and_enable(clock_node, NSSNOC_PPE_CLK, ppe_rate);
	ssdk_clock_rate_set_and_enable(clock_node, NSSNOC_PPE_CFG_CLK, ppe_rate);
	ssdk_clock_rate_set_and_enable(clock_node, NSS_EDMA_CLK, ppe_rate);
	ssdk_clock_rate_set_and_enable(clock_node, NSS_EDMA_CFG_CLK, ppe_rate);
	ssdk_clock_rate_set_and_enable(clock_node, NSS_PPE_IPE_CLK, ppe_rate);
	ssdk_clock_rate_set_and_enable(clock_node, NSS_PPE_BTQ_CLK, ppe_rate);

	return;
}

void ssdk_gcc_appe_clock_init(adpt_ppe_type_t chip_type)
{
#if defined(SSDK_RAW_CLOCK)
	gcc_clk_base_g = ioremap(GCC_BASE_ADDR, GCC_SIZE);
	if (!gcc_clk_base_g)
		SSDK_ERROR("ioremap error on base 0x%x\n", GCC_BASE_ADDR);

	if (chip_type == JHPPE_TYPE)
		nsscc_clk_base_g = ioremap(JHPPE_NSSCC_BASE_ADDR, NSSCC_SIZE);
	else
		nsscc_clk_base_g = ioremap(NSSCC_BASE_ADDR, NSSCC_SIZE);

	if (!nsscc_clk_base_g)
		SSDK_ERROR("NSSCC ioremap error with the chip type %d\n", chip_type);
#endif
	ssdk_appe_fixed_clock_init(chip_type);
	ssdk_ppe_uniphy_clock_init(chip_type);

	if (chip_type == APPE_TYPE)
		ssdk_uniphy_port5_clock_source_set();
}

void
qca_gcc_uniphy_port_clock_set(
	a_uint32_t dev_id, a_uint32_t uniphy_index,
	a_uint32_t port_id, a_bool_t enable)
{

	if (uniphy_index == SSDK_UNIPHY_INSTANCE2) {
		ssdk_uniphy_clock_enable(dev_id,
					UNIPHY2_PORT6_RX_CLK_E, enable);
		ssdk_uniphy_clock_enable(dev_id,
					UNIPHY2_PORT6_TX_CLK_E, enable);
	} else if (uniphy_index == SSDK_UNIPHY_INSTANCE1) {
		if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq95xx")) {
			ssdk_uniphy_clock_enable(dev_id,
					UNIPHY0_PORT5_RX_CLK_E, enable);
			ssdk_uniphy_clock_enable(dev_id,
					UNIPHY0_PORT5_TX_CLK_E, enable);
		} else {
			ssdk_uniphy_clock_enable(dev_id,
					UNIPHY1_PORT5_RX_CLK_E, enable);
			ssdk_uniphy_clock_enable(dev_id,
					UNIPHY1_PORT5_TX_CLK_E, enable);
		}
	} else if (uniphy_index == SSDK_UNIPHY_INSTANCE0) {
		switch (port_id) {
			case SSDK_PHYSICAL_PORT1:
				ssdk_uniphy_clock_enable(dev_id,
							UNIPHY0_PORT1_RX_CLK_E,
							enable);
				ssdk_uniphy_clock_enable(dev_id,
							UNIPHY0_PORT1_TX_CLK_E,
							enable);
				break;
			case SSDK_PHYSICAL_PORT2:
				ssdk_uniphy_clock_enable(dev_id,
							UNIPHY0_PORT2_RX_CLK_E,
							enable);
				ssdk_uniphy_clock_enable(dev_id,
							UNIPHY0_PORT2_TX_CLK_E,
							enable);
				break;
			case SSDK_PHYSICAL_PORT3:
				ssdk_uniphy_clock_enable(dev_id,
							UNIPHY0_PORT3_RX_CLK_E,
							enable);
				ssdk_uniphy_clock_enable(dev_id,
							UNIPHY0_PORT3_TX_CLK_E,
							enable);
				break;
			case SSDK_PHYSICAL_PORT4:
				ssdk_uniphy_clock_enable(dev_id,
							UNIPHY0_PORT4_RX_CLK_E,
							enable);
				ssdk_uniphy_clock_enable(dev_id,
							UNIPHY0_PORT4_TX_CLK_E,
							enable);
				break;
			case SSDK_PHYSICAL_PORT5:
				ssdk_uniphy_clock_enable(dev_id,
							UNIPHY0_PORT5_RX_CLK_E,
							enable);
				ssdk_uniphy_clock_enable(dev_id,
							UNIPHY0_PORT5_TX_CLK_E,
							enable);
				break;
			default:
				break;
		}
	}
}

void
qca_gcc_mac_port_clock_set(
	a_uint32_t dev_id,
	a_uint32_t port_id,
	a_bool_t enable)
{

	switch (port_id) {
		case SSDK_PHYSICAL_PORT1:
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT1_RX_CLK_E,
						enable);
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT1_TX_CLK_E,
						enable);
			break;
		case SSDK_PHYSICAL_PORT2:
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT2_RX_CLK_E,
						enable);
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT2_TX_CLK_E,
						enable);
			break;
		case SSDK_PHYSICAL_PORT3:
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT3_RX_CLK_E,
						enable);
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT3_TX_CLK_E,
						enable);
			break;
		case SSDK_PHYSICAL_PORT4:
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT4_RX_CLK_E,
						enable);
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT4_TX_CLK_E,
						enable);
			break;
		case SSDK_PHYSICAL_PORT5:
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT5_RX_CLK_E,
						enable);
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT5_TX_CLK_E,
						enable);
			break;
		case SSDK_PHYSICAL_PORT6:
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT6_RX_CLK_E,
						enable);
			ssdk_uniphy_clock_enable(dev_id,
						NSS_PORT6_TX_CLK_E,
						enable);
			break;
		default:
			break;
	}
}

void
ssdk_port_speed_clock_set(
	a_uint32_t dev_id,
	a_uint32_t port_id,
	a_uint32_t rate)
{
	a_uint32_t mode = 0;

	switch (port_id ) {
		case SSDK_PHYSICAL_PORT1:
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT1_RX_CLK_E, rate);
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT1_TX_CLK_E, rate);
			break;
		case SSDK_PHYSICAL_PORT2:
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT2_RX_CLK_E, rate);
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT2_TX_CLK_E, rate);
			break;
		case SSDK_PHYSICAL_PORT3:
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT3_RX_CLK_E, rate);
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT3_TX_CLK_E, rate);
			break;
		case SSDK_PHYSICAL_PORT4:
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT4_RX_CLK_E, rate);
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT4_TX_CLK_E, rate);
			break;
		case SSDK_PHYSICAL_PORT5:
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT5_RX_CLK_E, rate);
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT5_TX_CLK_E, rate);
			mode = ssdk_dt_global_get_mac_mode(dev_id, SSDK_UNIPHY_INSTANCE1);
			if (mode != PORT_INTERFACE_MODE_MAX)
				ssdk_uniphy1_clock_source_set();
			break;
		case SSDK_PHYSICAL_PORT6:
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT6_RX_CLK_E, rate);
			ssdk_uniphy_clock_rate_set(dev_id,
					NSS_PORT6_TX_CLK_E, rate);
			break;
		default:
			break;
	}
}

static char *ppe_rst_ids[UNIPHY_RST_MAX] = {
	UNIPHY0_SOFT_RESET_ID,
	UNIPHY0_XPCS_RESET_ID,
	UNIPHY1_SOFT_RESET_ID,
	UNIPHY1_XPCS_RESET_ID,
	UNIPHY2_SOFT_RESET_ID,
	UNIPHY2_XPCS_RESET_ID,
	UNIPHY0_PORT1_DISABLE_ID,
	UNIPHY0_PORT2_DISABLE_ID,
	UNIPHY0_PORT3_DISABLE_ID,
	UNIPHY0_PORT4_DISABLE_ID,
	UNIPHY0_PORT5_DISABLE_ID,
	UNIPHY0_PORT_4_5_RESET_ID,
	UNIPHY0_PORT_4_RESET_ID,
	UNIPHY2_PORT_6_DISABLE_ID,
	UNIPHY0_SYS_RESET_ID,
	UNIPHY1_SYS_RESET_ID,
	UNIPHY2_SYS_RESET_ID,
	UNIPHY0_AHB_RESET_ID,
	UNIPHY1_AHB_RESET_ID,
	UNIPHY_PORT1_RX_RESET_ID,
	UNIPHY_PORT1_TX_RESET_ID,
	UNIPHY_PORT2_RX_RESET_ID,
	UNIPHY_PORT2_TX_RESET_ID,
	UNIPHY_PORT3_RX_RESET_ID,
	UNIPHY_PORT3_TX_RESET_ID,
	UNIPHY_PORT4_RX_RESET_ID,
	UNIPHY_PORT4_TX_RESET_ID,
	UNIPHY_PORT5_RX_RESET_ID,
	UNIPHY_PORT5_TX_RESET_ID,
	UNIPHY_PORT6_RX_RESET_ID,
	UNIPHY_PORT6_TX_RESET_ID,
	PON_RESET_ID,
};

#if defined(HMSPPE)
static char *port_rst_ids[] = {
	SSDK_PORT1_RX_RESET_ID,
	SSDK_PORT1_TX_RESET_ID,
	SSDK_PORT2_RX_RESET_ID,
	SSDK_PORT2_TX_RESET_ID,
	SSDK_PORT3_RX_RESET_ID,
	SSDK_PORT3_TX_RESET_ID,
	SSDK_PORT4_RX_RESET_ID,
	SSDK_PORT4_TX_RESET_ID,
	SSDK_PORT5_RX_RESET_ID,
	SSDK_PORT5_TX_RESET_ID,
	SSDK_PORT6_RX_RESET_ID,
	SSDK_PORT6_TX_RESET_ID,
	EPHY_RX_RESET_ID,
	EPHY_TX_RESET_ID,
};
#elif defined(JHPPE)
static char *port_rst_ids[] = {
	SSDK_PORT1_RX_RESET_ID,
	SSDK_PORT1_TX_RESET_ID,
	SSDK_PORT2_RX_RESET_ID,
	SSDK_PORT2_TX_RESET_ID,
	SSDK_PORT3_RX_RESET_ID,
	SSDK_PORT3_TX_RESET_ID,
	SSDK_PORT4_RX_RESET_ID,
	SSDK_PORT4_TX_RESET_ID,
	SSDK_PORT5_RX_RESET_ID,
	SSDK_PORT5_TX_RESET_ID,
	SSDK_PORT6_RX_RESET_ID,
	SSDK_PORT6_TX_RESET_ID,
};
#elif defined(MPPE)
static char *port_rst_ids[] = {
	SSDK_PORT1_RX_RESET_ID,
	SSDK_PORT1_TX_RESET_ID,
	SSDK_PORT2_RX_RESET_ID,
	SSDK_PORT2_TX_RESET_ID,
	SSDK_PORT3_RX_RESET_ID,
	SSDK_PORT3_TX_RESET_ID
};
#else
static char *port_rst_ids[] = {
	SSDK_PORT1_RESET_ID,
	SSDK_PORT2_RESET_ID,
	SSDK_PORT3_RESET_ID,
	SSDK_PORT4_RESET_ID,
	SSDK_PORT5_RESET_ID,
	SSDK_PORT6_RESET_ID
};
#endif

static char *port_mac_rst_ids[] = {
	SSDK_PORT1_MAC_RESET_ID,
	SSDK_PORT2_MAC_RESET_ID,
	SSDK_PORT3_MAC_RESET_ID,
	SSDK_PORT4_MAC_RESET_ID,
	SSDK_PORT5_MAC_RESET_ID,
	SSDK_PORT6_MAC_RESET_ID
};

void ssdk_ppe_reset_init(a_uint32_t dev_id)
{
	struct device_node *ppe_node = ssdk_dts_node_get(dev_id);
	struct reset_control *rst;

	rst = of_reset_control_get(ppe_node, PPE_RESET_ID);
	if (IS_ERR(rst)) {
		SSDK_ERROR("%s not exist!\n", PPE_RESET_ID);
		return;
	}

	ssdk_gcc_reset(rst, SSDK_RESET_ASSERT);
	msleep(10);
	ssdk_gcc_reset(rst, SSDK_RESET_DEASSERT);

	reset_control_put(rst);
}

static void ssdk_gcc_reset_ids_init(void)
{
	a_uint32_t i;
	rst_node = of_find_node_by_name(NULL, "ess-switch");

	for (i = 0; i < ARRAY_SIZE(ppe_rst_ids); i++)
		uniphy_rsts[i] = of_reset_control_get(rst_node, ppe_rst_ids[i]);

	for (i = 0; i < ARRAY_SIZE(port_rst_ids); i++)
		port_rsts[i] = of_reset_control_get(rst_node, port_rst_ids[i]);

	for (i = 0; i < ARRAY_SIZE(port_mac_rst_ids); i++)
		port_mac_rsts[i] = of_reset_control_get(rst_node, port_mac_rst_ids[i]);
}

static void ssdk_gcc_reset_ids_deinit(void)
{
	a_uint32_t i;

	for (i = 0; i < ARRAY_SIZE(port_mac_rst_ids); i++)
		reset_control_put(port_mac_rsts[i]);

	for (i = 0; i < ARRAY_SIZE(port_rst_ids); i++)
		reset_control_put(port_rsts[i]);

	for (i = 0; i < ARRAY_SIZE(ppe_rst_ids); i++)
		reset_control_put(uniphy_rsts[i]);
}

enum unphy_rst_type uniphy_sys_rst[SSDK_MAX_UNIPHY_INSTANCE] = {
	UNIPHY0_SYS_RESET_E,
	UNIPHY1_SYS_RESET_E,
	UNIPHY2_SYS_RESET_E
};

#if defined(MRPPE)
enum unphy_rst_type uniphy_soft_rst[SSDK_MAX_UNIPHY_INSTANCE * 2] = {
	UNIPHY_PORT1_RX_RESET_E,
	UNIPHY_PORT1_TX_RESET_E,
	UNIPHY_PORT2_RX_RESET_E,
	UNIPHY_PORT2_TX_RESET_E,
	UNIPHY_PORT3_RX_RESET_E,
	UNIPHY_PORT3_TX_RESET_E
};
#elif defined(MPPE)
enum unphy_rst_type uniphy_soft_rst[SSDK_UNIPHY_INSTANCE2 * 2] = {
	UNIPHY_PORT1_RX_RESET_E,
	UNIPHY_PORT1_TX_RESET_E,
	UNIPHY_PORT2_RX_RESET_E,
	UNIPHY_PORT2_TX_RESET_E
};
#else
enum unphy_rst_type uniphy_soft_rst[SSDK_MAX_UNIPHY_INSTANCE] = {
	UNIPHY0_SOFT_RESET_E,
	UNIPHY1_SOFT_RESET_E,
	UNIPHY2_SOFT_RESET_E
};
#endif

void ssdk_gcc_uniphy_sys_set(a_uint32_t dev_id, a_uint32_t uniphy_index,
	a_bool_t enable)
{
	a_uint32_t index = 0, uniphy_max = SSDK_UNIPHY_INSTANCE2;
	enum unphy_rst_type rst_type[SSDK_MAX_UNIPHY_INSTANCE * 2] = {UNIPHY_RST_MAX};

	if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq60xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq53xx")) {
		uniphy_max = SSDK_UNIPHY_INSTANCE1;
	}

	if (uniphy_index > uniphy_max) {
		SSDK_DEBUG("Unsupported uniphy index: %d\n", uniphy_index);
		return;
	}

#if defined(MPPE)
	if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq53xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq54xx")) {
		/* For MPPE, the UNIPHY SOFT RESET includes UNIPHY PORT RX, UNIPHY PORT TX RESET */
		rst_type[index++] = uniphy_soft_rst[uniphy_index * 2];
		rst_type[index++] = uniphy_soft_rst[uniphy_index * 2 + 1];
	} else
#endif
	{
		rst_type[index++] = uniphy_soft_rst[uniphy_index];
		if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq95xx")) {
			a_uint32_t mode0, mode1;

			mode0 = ssdk_dt_global_get_mac_mode(dev_id, SSDK_UNIPHY_INSTANCE0);
			mode1 = ssdk_dt_global_get_mac_mode(dev_id, SSDK_UNIPHY_INSTANCE1);
			if ((uniphy_index == SSDK_UNIPHY_INSTANCE1) &&
				(mode0 == PORT_WRAPPER_PSGMII || mode0 == PORT_WRAPPER_PSGMII_FIBER)
				&& (mode1 == PORT_WRAPPER_MAX)) {
				/* can not reset uniphy port5 as it is used by uniphy0 psgmii */
				index--;
			}
			if ((uniphy_index == SSDK_UNIPHY_INSTANCE0) &&
				(mode0 == PORT_WRAPPER_MAX) && (mode1 != PORT_WRAPPER_MAX)) {
				/* can not reset uniphy port5 as it is used by uniphy1, instead
				 * only reset uniphy port1 to port4 */
				index--;
				rst_type[index++] = UNIPHY0_PORT1_DISABLE_E;
				rst_type[index++] = UNIPHY0_PORT2_DISABLE_E;
				rst_type[index++] = UNIPHY0_PORT3_DISABLE_E;
				rst_type[index++] = UNIPHY0_PORT4_DISABLE_E;
			}
		}
	}

	if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq95xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq53xx") ||
			of_device_is_compatible(clock_node, "qcom,ess-switch-ipq54xx")) {
		rst_type[index++] = uniphy_sys_rst[uniphy_index];
	}

	while (index > 0) {
		ssdk_uniphy_reset(dev_id, rst_type[--index],
				enable == A_TRUE ? SSDK_RESET_DEASSERT : SSDK_RESET_ASSERT);
	}

	return;
}

void ssdk_gcc_clock_init(void)
{
	enum cmnblk_clk_type cmnblk_clk_mode = INTERNAL_48MHZ;
	a_uint8_t *mode = NULL;

	clock_node = of_find_node_by_name(NULL, "ess-switch");
	if (of_property_read_string(clock_node, "cmnblk_clk",
				    (const char **)&mode)) {
		cmnblk_clk_mode = INTERNAL_48MHZ;
	} else {
		if (!strcmp(mode, "external_50MHz")) {
			cmnblk_clk_mode = EXTERNAL_50MHZ;
		} else if (!strcmp(mode, "external_25MHz")) {
			cmnblk_clk_mode = EXTERNAL_25MHZ;
		} else if (!strcmp(mode, "external_31250KHz")) {
			cmnblk_clk_mode = EXTERNAL_31250KHZ;
		} else if (!strcmp(mode, "external_40MHz")) {
			cmnblk_clk_mode = EXTERNAL_40MHZ;
		} else if (!strcmp(mode, "external_48MHz")) {
			cmnblk_clk_mode = EXTERNAL_48MHZ;
		} else if (!strcmp(mode, "internal_96MHz")) {
			cmnblk_clk_mode = INTERNAL_96MHZ;
		}
	}

	if (of_device_is_compatible(clock_node,
			"qcom,ess-switch-ipq95xx")) {
		ssdk_gcc_appe_clock_init(APPE_TYPE);
	} else if (of_device_is_compatible(clock_node,
			"qcom,ess-switch-ipq53xx")) {
#if defined(MPPE)
		ssdk_gcc_appe_clock_init(MPPE_TYPE);
#endif
	} else if (of_device_is_compatible(clock_node,
			"qcom,ess-switch-ipq54xx")) {
#if defined(MRPPE)
		ssdk_gcc_appe_clock_init(MRPPE_TYPE);
#endif
	} else if (of_device_is_compatible(clock_node,
			"qcom,ess-switch-ipq96xx")) {
#if defined(JHPPE)
		ssdk_gcc_appe_clock_init(JHPPE_TYPE);
#endif
	} else if (of_device_is_compatible(clock_node,
			"qcom,ess-switch-ipq52xx")) {
#if defined(HMSPPE)
		ssdk_gcc_appe_clock_init(HMSPPE_TYPE);
#endif
	}
	ssdk_gcc_reset_ids_init();
}

void ssdk_gcc_clock_exit(void)
{
	if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq95xx")) {
		ssdk_gcc_ppe_clock_deinit(APPE_TYPE);
	} else if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq53xx")) {
#if defined(MPPE)
		ssdk_gcc_ppe_clock_deinit(MPPE_TYPE);
#endif
	} else if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq54xx")) {
#if defined(MRPPE)
		ssdk_gcc_ppe_clock_deinit(MRPPE_TYPE);;
#endif
	} else if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq96xx")) {
#if defined(JHPPE)
		ssdk_gcc_ppe_clock_deinit(JHPPE_TYPE);;
#endif
	} else if (of_device_is_compatible(clock_node, "qcom,ess-switch-ipq52xx")) {
#if defined(HMSPPE)
		ssdk_gcc_ppe_clock_deinit(HMSPPE_TYPE);;
#endif
	}

	ssdk_gcc_reset_ids_deinit();

#if defined(SSDK_RAW_CLOCK)
	if (gcc_clk_base_g)
		iounmap(gcc_clk_base_g);

	if (nsscc_clk_base_g)
		iounmap(nsscc_clk_base_g);
#endif
}

#if IS_ENABLED(CONFIG_QCOM_FPGA_PCI) || defined(SSDK_PCIE_BUS)
void ssdk_pci_ppe_clock_init(a_uint32_t dev_id)
{
	struct device_node * switch_node = ssdk_dts_node_get(dev_id);
	if (of_device_is_compatible(switch_node, "qcom,ess-switch-ipq52xx")) {
#if IS_ENABLED(CONFIG_QCOM_FPGA_PCI)
		/* Read NSS_NOC (Non-PPE) registers for validate PCI access */
		uint32_t reg, val;
		reg = 0x01D80000;
		val = qcom_fpga_mem_read(reg);
		SSDK_INFO("Read register [0x%x] = 0x%x\n", reg, val);
		reg = 0x01D80004;
		val = qcom_fpga_mem_read(reg);
		SSDK_INFO("Read register [0x%x] = 0x%x\n", reg, val);

		/* NSS_CC_NSS_CSR_CBCR */
		qcom_fpga_mem_write(0x39B00714, 0x1);
		/* NSS_CC_NSSNOC_NSS_CSR_CBCR */
		qcom_fpga_mem_write(0x39B00718, 0x1);

		/* NSS_CC_PPE_SWITCH_IPE_CBCR */
		qcom_fpga_mem_write(0x39B00424, 0x221);
		/* NSS_CC_PPE_SWITCH_BTQ_CBCR */
		qcom_fpga_mem_write(0x39B0042C, 0x221);
		/* NSS_CC_PPE_SWITCH_CBCR */
		qcom_fpga_mem_write(0x39B00434, 0x221);
		/* NSS_CC_PPE_SWITCH_CFG_CBCR */
		qcom_fpga_mem_write(0x39B0043C, 0x1);
		/* NSS_CC_PPE_EDMA_CBCR */
		qcom_fpga_mem_write(0x39B00440, 0x221);
		/* NSS_CC_PPE_EDMA_CFG_CBCR */
		qcom_fpga_mem_write(0x39B00448, 0x1);

		/* NSS_CC_NSSNOC_PPE_CBCR */
		qcom_fpga_mem_write(0x39B004A4, 0x1);
		/* NSS_CC_NSSNOC_PPE_CFG_CBCR */
		qcom_fpga_mem_write(0x39B004A8, 0x1);

		/* NSS_CC_PORT1_MAC_CBCR */
		qcom_fpga_mem_write(0x39B0044C, 0x221);
		/* NSS_CC_PORT2_MAC_CBCR */
		qcom_fpga_mem_write(0x39B00454, 0x221);
		/* NSS_CC_PORT3_MAC_CBCR */
		qcom_fpga_mem_write(0x39B0045C, 0x221);
		/* NSS_CC_PORT4_MAC_CBCR */
		qcom_fpga_mem_write(0x39B00464, 0x221);
		/* NSS_CC_PORT5_MAC_CBCR */
		qcom_fpga_mem_write(0x39B0046C, 0x221);
		/* NSS_CC_PORT6_MAC_CBCR */
		qcom_fpga_mem_write(0x39B00474, 0x221);
		/* NSS_CC_PON_CBCR */
		qcom_fpga_mem_write(0x39B0047C, 0x221);

		/* NSS_CC_PORT1_RX_CBCR */
		qcom_fpga_mem_write(0x39B00548, 0x221);
		/* NSS_CC_PORT1_TX_CBCR */
		qcom_fpga_mem_write(0x39B00550, 0x221);
		/* NSS_CC_PORT2_RX_CBCR */
		qcom_fpga_mem_write(0x39B00558, 0x221);
		/* NSS_CC_PORT2_TX_CBCR */
		qcom_fpga_mem_write(0x39B00560, 0x221);
		/* NSS_CC_PORT3_RX_CBCR */
		qcom_fpga_mem_write(0x39B00568, 0x221);
		/* NSS_CC_PORT3_TX_CBCR */
		qcom_fpga_mem_write(0x39B00570, 0x221);
		/* NSS_CC_PORT4_RX_CBCR */
		qcom_fpga_mem_write(0x39B00578, 0x221);
		/* NSS_CC_PORT4_TX_CBCR */
		qcom_fpga_mem_write(0x39B00580, 0x221);
		/* NSS_CC_PORT5_RX_CBCR */
		qcom_fpga_mem_write(0x39B00588, 0x221);
		/* NSS_CC_PORT5_TX_CBCR */
		qcom_fpga_mem_write(0x39B00590, 0x221);
		/* NSS_CC_PORT6_RX_CBCR */
		qcom_fpga_mem_write(0x39B00598, 0x221);
		/* NSS_CC_PORT6_TX_CBCR */
		qcom_fpga_mem_write(0x39B005A0, 0x221);

		/* NSS_CC_XGMAC0_PTP_REF_CBCR */
		qcom_fpga_mem_write(0x39B00488, 0x221);
		/* NSS_CC_XGMAC0_PTP_REF_CBCR */
		qcom_fpga_mem_write(0x39B0048C, 0x221);
		/* NSS_CC_XGMAC0_PTP_REF_CBCR */
		qcom_fpga_mem_write(0x39B00490, 0x221);

		/* NSS_CC_DEBUG_CBCR */
		qcom_fpga_mem_write(0x39B00770, 0x1);

		/* PPE reset */
		qcom_fpga_mem_write(0x39b003E8,0x1);
		msleep(10);
		qcom_fpga_mem_write(0x39b003E8,0x0);

		/* Switch clock gating setting */
		val = qcom_fpga_mem_read(0x3A000008);
		val &= ~(BIT(4) | GENMASK(15, 14));
		qcom_fpga_mem_write(0x3A000008, val);

		/* Check PPE register after clocks configured */
		reg = 0x3A000000;
		val = qcom_fpga_mem_read(reg);
		SSDK_INFO("Read PPE register [0x%x] = 0x%x\n", reg, val);
#endif
	}
}
#endif
