/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HSL_HMS_MANUAL_H_
#define _HSL_HMS_MANUAL_H_

enum {
	OP_ADD = 0,
	OP_DEL,
	OP_GET,
	OP_FLUSH,
};

#define HASH_MODE	0
#define INDEX_MODE	1

/*[register] TOEPLITZ_SECRET_KEY*/
#define TOEPLITZ_SECRET_KEY
#define TOEPLITZ_SECRET_KEY_ADDRESS 0x4420
#define TOEPLITZ_SECRET_KEY_NUM     11
#define TOEPLITZ_SECRET_KEY_INC     0x4
#define TOEPLITZ_SECRET_KEY_TYPE    REG_TYPE_RW

/*[register]*/
#define IPO_MASK_REG
#define IPO_MASK_REG_ADDRESS 0x2000
#if defined(MRPPE)
#define IPO_MASK_REG_NUM     512
#elif defined(MPPE)
#define IPO_MASK_REG_NUM     128
#else
#define IPO_MASK_REG_NUM     512
#endif
#define IPO_MASK_REG_INC     0x10
#define IPO_MASK_REG_TYPE    REG_TYPE_RW
#define IPO_MASK_REG_DEFAULT 0x0

#define IPO_RULE_REG
#define IPO_RULE_REG_ADDRESS 0x0
#define IPO_RULE_REG_NUM     512
#define IPO_RULE_REG_INC     0x10
#define IPO_RULE_REG_TYPE    REG_TYPE_RW
#define IPO_RULE_REG_DEFAULT 0x0

/*[table] */
#define FLOW_HOST_TBL_RD_RSLT_DATA
#if defined(APPE)
#define FLOW_HOST_TBL_RD_RSLT_DATA_ADDRESS 0x6ec
#else
#define FLOW_HOST_TBL_RD_RSLT_DATA_ADDRESS 0x494
#endif
#define FLOW_HOST_TBL_RD_RSLT_DATA_NUM     10
#define FLOW_HOST_TBL_RD_RSLT_DATA_INC     0x4
#define FLOW_HOST_TBL_RD_RSLT_DATA_TYPE    REG_TYPE_RO
#define FLOW_HOST_TBL_RD_RSLT_DATA_DEFAULT 0x0

/*[table] */
#define IN_FLOW_TBL_OP_DATA
#if defined(APPE)
#define IN_FLOW_TBL_OP_DATA_ADDRESS 0x550
#define IN_FLOW_TBL_OP_DATA_NUM     11
#else
#define IN_FLOW_TBL_OP_DATA_ADDRESS 0x3c0
#define IN_FLOW_TBL_OP_DATA_NUM     9
#endif
#define IN_FLOW_TBL_OP_DATA_INC     0x4
#define IN_FLOW_TBL_OP_DATA_TYPE    REG_TYPE_RW
#define IN_FLOW_TBL_OP_DATA_DEFAULT 0x0

/*[register] HOST_TBL_OP_DATA0*/
#define HOST_TBL_OP_DATA
#if defined(APPE)
#define HOST_TBL_OP_DATA_ADDRESS 0x738
#else
#define HOST_TBL_OP_DATA_ADDRESS 0x4c0
#endif
#define HOST_TBL_OP_DATA_NUM     10
#define HOST_TBL_OP_DATA_INC     0x4
#define HOST_TBL_OP_DATA_TYPE    REG_TYPE_RW
#define HOST_TBL_OP_DATA_DEFAULT 0x0

/*[table] */
#define FLOW_HOST_TBL_OP_DATA
#if defined(APPE)
#define FLOW_HOST_TBL_OP_DATA_ADDRESS 0x58c
#else
#define FLOW_HOST_TBL_OP_DATA_ADDRESS 0x3e4
#endif
#define FLOW_HOST_TBL_OP_DATA_NUM     10
#define FLOW_HOST_TBL_OP_DATA_INC     0x4
#define FLOW_HOST_TBL_OP_DATA_TYPE    REG_TYPE_RW
#define FLOW_HOST_TBL_OP_DATA_DEFAULT 0x0

/*[table] */
#define IN_FLOW_TBL_RD_OP_DATA
#if defined(APPE)
#define IN_FLOW_TBL_RD_OP_DATA_ADDRESS 0x614
#define IN_FLOW_TBL_RD_OP_DATA_NUM     11
#else
#define IN_FLOW_TBL_RD_OP_DATA_ADDRESS 0x41c
#define IN_FLOW_TBL_RD_OP_DATA_NUM     9
#endif
#define IN_FLOW_TBL_RD_OP_DATA_INC     0x4
#define IN_FLOW_TBL_RD_OP_DATA_TYPE    REG_TYPE_RW
#define IN_FLOW_TBL_RD_OP_DATA_DEFAULT 0x0

#define IN_FLOW_TBL_RD_RSLT_DATA
#if defined(APPE)
#define IN_FLOW_TBL_RD_RSLT_DATA_ADDRESS 0x6b0
#define IN_FLOW_TBL_RD_RSLT_DATA_NUM     11
#else
#define IN_FLOW_TBL_RD_RSLT_DATA_ADDRESS 0x470
#define IN_FLOW_TBL_RD_RSLT_DATA_NUM     9
#endif
#define IN_FLOW_TBL_RD_RSLT_DATA_INC     0x4
#define IN_FLOW_TBL_RD_RSLT_DATA_TYPE    REG_TYPE_RO
#define IN_FLOW_TBL_RD_RSLT_DATA_DEFAULT 0x0

/*[table] */
#define HOST_TBL_RD_OP_DATA
#if defined(APPE)
#define HOST_TBL_RD_OP_DATA_ADDRESS 0x798
#else
#define HOST_TBL_RD_OP_DATA_ADDRESS 0x4f0
#endif
#define HOST_TBL_RD_OP_DATA_NUM     10
#define HOST_TBL_RD_OP_DATA_INC     0x4
#define HOST_TBL_RD_OP_DATA_TYPE    REG_TYPE_RW
#define HOST_TBL_RD_OP_DATA_DEFAULT 0x0

/*[register]*/
#define HOST_TBL_RD_RSLT_DATA
#if defined(APPE)
#define HOST_TBL_RD_RSLT_DATA_ADDRESS 0x7e4
#else
#define HOST_TBL_RD_RSLT_DATA_ADDRESS 0x51c
#endif
#define HOST_TBL_RD_RSLT_DATA_NUM     10
#define HOST_TBL_RD_RSLT_DATA_INC     0x4
#define HOST_TBL_RD_RSLT_DATA_TYPE    REG_TYPE_RO
#define HOST_TBL_RD_RSLT_DATA_DEFAULT 0x0

/*[register] FLOW_HOST_TBL_RD_OP_DATA*/
#define FLOW_HOST_TBL_RD_OP_DATA
#if defined(APPE)
#define FLOW_HOST_TBL_RD_OP_DATA_ADDRESS 0x650
#else
#define FLOW_HOST_TBL_RD_OP_DATA_ADDRESS 0x440
#endif
#define FLOW_HOST_TBL_RD_OP_DATA_NUM     10
#define FLOW_HOST_TBL_RD_OP_DATA_INC     0x4
#define FLOW_HOST_TBL_RD_OP_DATA_TYPE    REG_TYPE_RW
#define FLOW_HOST_TBL_RD_OP_DATA_DEFAULT 0x0

/*[table] PRE_IPO_MASK_REG*/
#define PRE_IPO_MASK_REG
#define PRE_IPO_MASK_REG_ADDRESS 0x2000
#if defined(MRPPE)
#define PRE_IPO_MASK_REG_NUM     512
#elif defined(MPPE)
#define PRE_IPO_MASK_REG_NUM     128
#else
#define PRE_IPO_MASK_REG_NUM     512
#endif
#define PRE_IPO_MASK_REG_INC     0x10
#define PRE_IPO_MASK_REG_TYPE    REG_TYPE_RW
#define PRE_IPO_MASK_REG_DEFAULT 0x0

/*[table] PRE_IPO_RULE_REG*/
#define PRE_IPO_RULE_REG
#define PRE_IPO_RULE_REG_ADDRESS 0x0
#if defined(MRPPE)
#define PRE_IPO_RULE_REG_NUM     512
#elif defined(MPPE)
#define PRE_IPO_RULE_REG_NUM     128
#else
#define PRE_IPO_RULE_REG_NUM     512
#endif
#define PRE_IPO_RULE_REG_INC     0x10
#define PRE_IPO_RULE_REG_TYPE    REG_TYPE_RW
#define PRE_IPO_RULE_REG_DEFAULT 0x0

/*[register] PORT_MUX_CTRL*/
#define SWITCH_PORT_MUX_CTRL
#define SWITCH_PORT_MUX_CTRL_ADDRESS 0x10
#define SWITCH_PORT_MUX_CTRL_NUM     1
#define SWITCH_PORT_MUX_CTRL_INC     0x4
#define SWITCH_PORT_MUX_CTRL_TYPE    REG_TYPE_RW
#define SWITCH_PORT_MUX_CTRL_DEFAULT 0x0

/*[register] TDM_CTRL*/
#define TDM_CTRL
#define TDM_CTRL_ADDRESS 0x0
#define TDM_CTRL_NUM     1
#define TDM_CTRL_INC     0x4
#define TDM_CTRL_TYPE    REG_TYPE_RW
#define TDM_CTRL_DEFAULT 0x80000050

/*[table] TDM_CFG*/
#define TDM_CFG_MAX_ENTRY	128
#define TDM_CFG
#define TDM_CFG_ADDRESS 0x1000
#define TDM_CFG_NUM     128
#define TDM_CFG_INC     0x10
#define TDM_CFG_TYPE    REG_TYPE_RW
#define TDM_CFG_DEFAULT 0x0

/*[register] RX_FIFO_CFG*/
#define RX_FIFO_CFG_MAX_ENTRY	8
#define RX_FIFO_CFG
#define RX_FIFO_CFG_ADDRESS 0x4
#define RX_FIFO_CFG_NUM     8
#define RX_FIFO_CFG_INC     0x4
#define RX_FIFO_CFG_TYPE    REG_TYPE_RW
#define RX_FIFO_CFG_DEFAULT 0x4

/*[table] DROP_STAT*/
#define DROP_STAT
#define DROP_STAT_ADDRESS 0x3000
#if defined(MRPPE)
#define DROP_STAT_NUM     38
#else
#define DROP_STAT_NUM     30
#endif
#define DROP_STAT_INC     0x10
#define DROP_STAT_TYPE    REG_TYPE_RW
#define DROP_STAT_DEFAULT 0x0

/*[register] LPI_ENABLE*/
#define LPI_PORT_ENABLE
#define LPI_PORT_ENABLE_ADDRESS 0xf4
#define LPI_PORT_ENABLE_NUM     3
#define LPI_PORT_ENABLE_INC     0x200
#define LPI_PORT_ENABLE_TYPE    REG_TYPE_RW
#define LPI_PORT_ENABLE_DEFAULT 0x0

/*[register] LPI_PORT_WAKEUP_TIMER*/
#define LPI_PORT_WAKEUP_TIMER_ENABLE
#define LPI_PORT_WAKEUP_TIMER_ADDRESS 0xf8
#define LPI_PORT_WAKEUP_TIMER_NUM     3
#define LPI_PORT_WAKEUP_TIMER_INC     0x200
#define LPI_PORT_WAKEUP_TIMER_TYPE    REG_TYPE_RW
#define LPI_PORT_WAKEUP_TIMER_DEFAULT 0x20

/*[register] LPI_PORT_SLEEP_TIMER*/
#define LPI_PORT_SLEEP_TIMER_ENABLE
#define LPI_PORT_SLEEP_TIMER_ADDRESS 0xfc
#define LPI_PORT_SLEEP_TIMER_NUM     3
#define LPI_PORT_SLEEP_TIMER_INC     0x200
#define LPI_PORT_SLEEP_TIMER_TYPE    REG_TYPE_RW
#define LPI_PORT_SLEEP_TIMER_DEFAULT 0x100

/*[register] LPI_1US_CNT*/
#define LPI_1US_CNT
#define LPI_1US_CNT_ADDRESS 0x104
#define LPI_1US_CNT_NUM     3
#define LPI_1US_CNT_INC     0x200
#define LPI_1US_CNT_TYPE    REG_TYPE_RW
#define LPI_1US_CNT_DEFAULT 0x177

/*[register] LPI_PORT_TIMER*/
#define LPI_PORT_TIMER_ENABLE
#define LPI_PORT_TIMER_ADDRESS 0x0
#define LPI_PORT_TIMER_NUM     6
#define LPI_PORT_TIMER_INC     0x4
#define LPI_PORT_TIMER_TYPE    REG_TYPE_RW
#define LPI_PORT_TIMER_DEFAULT 0x0

/*[register] LPI_ENABLE*/
#define LPI_ENABLE
#define LPI_ENABLE_ADDRESS 0x0
#define LPI_ENABLE_NUM     1
#define LPI_ENABLE_INC     0x0
#define LPI_ENABLE_TYPE    REG_TYPE_RW
#define LPI_ENABLE_DEFAULT 0x0

/*[register] LPI_CNT*/
#define LPI_CNT
#define LPI_CNT_ADDRESS 0x30
#define LPI_CNT_NUM     1
#define LPI_CNT_INC     0x1
#define LPI_CNT_TYPE    REG_TYPE_RW
#define LPI_CNT_DEFAULT 0x0

/*[register] DROP_CNT*/
#define DROP_CNT
#define DROP_CNT_ADDRESS 0x24
#if defined(MRPPE)
#define DROP_CNT_NUM     16
#else
#define DROP_CNT_NUM     8
#endif
#define DROP_CNT_INC     0x4
#define DROP_CNT_TYPE    REG_TYPE_RW
#define DROP_CNT_DEFAULT 0x0


struct pre_ipo_mask_reg {
	a_uint32_t  maskfield_0:32;
	a_uint32_t  maskfield_1:21;
	a_uint32_t  _reserved0:11;
};

union pre_ipo_mask_reg_u {
	a_uint32_t val[2];
	struct pre_ipo_mask_reg bf;
};

struct pre_ipo_rule_reg {
	a_uint32_t  rule_field_0:32;
	a_uint32_t  rule_field_1:20;
	a_uint32_t  fake_mac_header:1;
	a_uint32_t  range_en:1;
	a_uint32_t  inverse_en:1;
	a_uint32_t  rule_type:5;
	a_uint32_t  src_type:3;
	a_uint32_t  src_0:1;
	a_uint32_t  src_1:7;
	a_uint32_t  pri:9;
	a_uint32_t  res_chain:1;
	a_uint32_t  inner_outer_sel:1;
	a_uint32_t  _reserved0:14;
};

union pre_ipo_rule_reg_u {
	a_uint32_t val[3];
	struct pre_ipo_rule_reg bf;
};

struct ipo_mask_reg {
	a_uint32_t  maskfield_0:32;
	a_uint32_t  maskfield_1:21;
	a_uint32_t  _reserved0:11;
};

union ipo_mask_reg_u {
	a_uint32_t val[2];
	struct ipo_mask_reg bf;
};

struct ipo_rule_reg {
	a_uint32_t  rule_field_0:32;
	a_uint32_t  rule_field_1:20;
	a_uint32_t  fake_mac_header:1;
	a_uint32_t  range_en:1;
	a_uint32_t  inverse_en:1;
	a_uint32_t  rule_type:4;
	a_uint32_t  src_type:2;
	a_uint32_t  src_0:3;
	a_uint32_t  src_1:5;
	a_uint32_t  pri:9;
	a_uint32_t  res_chain:1;
	a_uint32_t  post_routing_en:1;
	a_uint32_t  _reserved0:16;
};

union ipo_rule_reg_u {
	a_uint32_t val[3];
	struct ipo_rule_reg bf;
};

struct drop_stat {
	a_uint32_t  pkts:32;
	a_uint32_t  bytes_0:32;
	a_uint32_t  bytes_1:8;
	a_uint32_t  _reserved0:24;
};

union drop_stat_u {
	a_uint32_t val[3];
	struct drop_stat bf;
};

struct lpi_cnt {
	a_uint32_t  lpi_cnt_val:9;
	a_uint32_t  _reserved0:23;
};

union lpi_cnt_u {
	a_uint32_t val;
	struct lpi_cnt bf;
};

struct lpi_enable {
	a_uint32_t  lpi_port1_en:1;
	a_uint32_t  lpi_port2_en:1;
	a_uint32_t  lpi_port3_en:1;
	a_uint32_t  lpi_port4_en:1;
	a_uint32_t  lpi_port5_en:1;
	a_uint32_t  lpi_port6_en:1;
	a_uint32_t  _reserved0:26;
};

union lpi_enable_u {
	a_uint32_t val;
	struct lpi_enable bf;
};

struct lpi_port_timer {
	a_uint32_t  lpi_port_wakeup_timer:16;
	a_uint32_t  lpi_port_sleep_timer:16;
};

union lpi_port_timer_u {
	a_uint32_t val;
	struct lpi_port_timer bf;
};

struct appe_port_mux_ctrl {
	a_uint32_t  port1_pcs_sel:1;
	a_uint32_t  port2_pcs_sel:1;
	a_uint32_t  port3_pcs_sel:1;
	a_uint32_t  port4_pcs_sel:1;
	a_uint32_t  port5_pcs_sel:1;
	a_uint32_t  port6_pcs_sel:1;
	a_uint32_t  _reserved0:2;
	a_uint32_t  port1_mac_sel:1;
	a_uint32_t  port2_mac_sel:1;
	a_uint32_t  port3_mac_sel:1;
	a_uint32_t  port4_mac_sel:1;
	a_uint32_t  port5_mac_sel:1;
	a_uint32_t  port6_mac_sel:1;
	a_uint32_t  _reserved1:18;
};

union appe_port_mux_ctrl_u {
	a_uint32_t val;
	struct appe_port_mux_ctrl bf;
};

struct rx_fifo_cfg {
	a_uint32_t  rx_fifo_thres:3;
	a_uint32_t  _reserved0:29;
};

union rx_fifo_cfg_u {
	a_uint32_t val;
	struct rx_fifo_cfg bf;
};

struct tdm_ctrl {
	a_uint32_t  tdm_depth:8;
	a_uint32_t  tdm_offset:7;
	a_uint32_t  _reserved0:16;
	a_uint32_t  tdm_en:1;
};

union tdm_ctrl_u {
	a_uint32_t val;
	struct tdm_ctrl bf;
};

struct tdm_cfg {
	a_uint32_t  port_num:4;
	a_uint32_t  dir:1;
	a_uint32_t  valid:1;
	a_uint32_t  sec_valid:1;
	a_uint32_t  resv:1;
	a_uint32_t  sec_port_num:4;
	a_uint32_t  _reserved0:20;
};

union tdm_cfg_u {
	a_uint32_t val;
	struct tdm_cfg bf;
};

struct drop_cnt {
	a_uint32_t  drop_cnt:32;
};

union drop_cnt_u {
	a_uint32_t val;
	struct drop_cnt bf;
};

struct lpi_port_sleep_timer {
	a_uint32_t  lpi_port_sleep_timer:16;
	a_uint32_t  _reserved0:16;
};

union lpi_port_sleep_timer_u {
	a_uint32_t val;
	struct lpi_port_sleep_timer bf;
};

struct lpi_port_enable {
	a_uint32_t  lpi_port_en:1;
	a_uint32_t  _reserved0:31;
};

union lpi_port_enable_u {
	a_uint32_t val;
	struct lpi_port_enable bf;
};

struct lpi_1us_cnt {
	a_uint32_t  lpi_1us_cnt_val:9;
	a_uint32_t  _reserved0:23;
};

union lpi_1us_cnt_u {
	a_uint32_t val;
	struct lpi_1us_cnt bf;
};

struct lpi_port_wakeup_timer {
	a_uint32_t  lpi_port_wakeup_timer:16;
	a_uint32_t  _reserved0:16;
};

union lpi_port_wakeup_timer_u {
	a_uint32_t val;
	struct lpi_port_wakeup_timer bf;
};

struct toeplitz_secret_key {
	a_uint32_t  key_word:32;
};

union toeplitz_secret_key_u {
	a_uint32_t val;
	struct toeplitz_secret_key bf;
};

#endif
