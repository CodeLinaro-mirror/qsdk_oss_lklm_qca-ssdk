/*
 * Copyright (c) 2015-2019, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022-2024 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "sw.h"
#include "fal_port_ctrl.h"
#include "hsl_api.h"
#include "hsl.h"
#include "malibu_phy.h"
#include "hsl_phy.h"
#include "qcaphy_common.h"
#include "ssdk_plat.h"

static a_uint32_t first_phy_addr = MAX_PHY_ADDR;
static a_uint32_t combo_phy_addr = MAX_PHY_ADDR;
#define COMBO_PHY_ID combo_phy_addr

#if 0
/******************************************************************************
*
* malibu_phy_reset_done - reset the phy
*
* reset the phy
*/
a_bool_t malibu_phy_reset_done(a_uint32_t dev_id, a_uint32_t phy_addr)
{
	a_uint16_t phy_data;
	a_uint16_t ii = 200;

	if (phy_addr == COMBO_PHY_ID)
		__phy_reg_pages_sel_by_active_medium(dev_id, phy_addr);

	do {
		phy_data =
			hsl_phy_mii_reg_read(dev_id, phy_addr, MALIBU_PHY_CONTROL);
		aos_mdelay(10);
	}
	while ((!MALIBU_RESET_DONE(phy_data)) && --ii);

	if (ii == 0)
		return A_FALSE;

	return A_TRUE;
}

/******************************************************************************
*
* malibu_autoneg_done
*
* malibu_autoneg_done
*/
a_bool_t malibu_autoneg_done(a_uint32_t dev_id, a_uint32_t phy_addr)
{
	a_uint16_t phy_data;
	a_uint16_t ii = 200;

	if (phy_addr == COMBO_PHY_ID)
		__phy_reg_pages_sel_by_active_medium(dev_id, phy_addr);

	do {
		phy_data =
			hsl_phy_mii_reg_read(dev_id, phy_addr, MALIBU_PHY_STATUS);
		aos_mdelay(10);
	}
	while ((!MALIBU_AUTONEG_DONE(phy_data)) && --ii);

	if (ii == 0)
		return A_FALSE;

	return A_TRUE;
}

/******************************************************************************
*
* malibu_phy_Speed_Duplex_Resolved
 - reset the phy
*
* reset the phy
*/
a_bool_t malibu_phy_speed_duplex_resolved(a_uint32_t dev_id, a_uint32_t phy_addr)
{
	a_uint16_t phy_data;
	a_uint16_t ii = 200;

	if (phy_addr == COMBO_PHY_ID)
		__phy_reg_pages_sel_by_active_medium(dev_id, phy_addr);

	do {
		phy_data =
			hsl_phy_mii_reg_read(dev_id, phy_addr, MALIBU_PHY_SPEC_STATUS);
		aos_mdelay(10);
	}
	while ((!MALIBU_SPEED_DUPLEX_RESOVLED(phy_data)) && --ii);

	if (ii == 0)
		return A_FALSE;

	return A_TRUE;
}
#endif

sw_error_t
malibu_phy_hw_init(a_uint32_t dev_id, a_uint32_t port_bmp)
{
	a_uint32_t port_id = 0, phy_addr = 0, phy_cnt = 0;
	a_uint32_t mode = 0;

	for (port_id = 0; port_id < SW_MAX_NR_PORT; port_id ++)
	{
		if (port_bmp & (0x1 << port_id))
		{
			phy_cnt ++;
			phy_addr = qca_ssdk_port_to_phy_addr(dev_id, port_id);
			if (phy_addr < first_phy_addr)
			{
				first_phy_addr = phy_addr;
			}
			/*change malibu control_dac[2:0] of MMD7 0x801A bit[9:7] from 111 to 101*/
			hsl_phy_modify_mmd(dev_id, phy_addr, A_FALSE, MALIBU_PHY_MMD7_NUM,
				MALIBU_PHY_MMD7_DAC_CTRL, MALIBU_DAC_CTRL_MASK,
				MALIBU_DAC_CTRL_VALUE);
			/* add 10M and 100M link LED behavior for QFN board*/
			hsl_phy_modify_mmd(dev_id, phy_addr, A_FALSE, MALIBU_PHY_MMD7_NUM,
				MALIBU_PHY_MMD7_LED_1000_CTRL1, MALIBU_LED_1000_CTRL1_100_10_MASK,
				MALIBU_LED_1000_CTRL1_100_10_MASK);
			/*disable Extended next page*/
			hsl_phy_modify_mii(dev_id, phy_addr, MALIBU_AUTONEG_ADVERT,
				MALIBU_EXTENDED_NEXT_PAGE_EN, 0);
		}
	}
	/* qca 8072 two ports phy chip's firstly address to init phy chip */
	if ((phy_cnt == QCA8072_PHY_NUM) && (first_phy_addr >= 0x3)) {
		first_phy_addr = first_phy_addr - 0x3;
	}

	/*workaround to enable AZ transmitting ability*/
	hsl_phy_mmd_reg_write(dev_id, first_phy_addr + 5, A_FALSE, MALIBU_PHY_MMD1_NUM,
		MALIBU_PSGMII_MODE_CTRL, MALIBU_PHY_PSGMII_MODE_CTRL_ADJUST_VALUE);

	/* adjust psgmii serdes tx amp */
	hsl_phy_mii_reg_write(dev_id, first_phy_addr + 5,
		MALIBU_PSGMII_TX_DRIVER_1_CTRL, MALIBU_PHY_PSGMII_REDUCE_SERDES_TX_AMP);

	/* to avoid psgmii module goes into hibernation, work with psgmii self test*/
	hsl_phy_modify_mmd(dev_id, first_phy_addr + 4, A_FALSE, MALIBU_PHY_MMD3_NUM,
		MALIBU_PHY_MMD3_ADDR_REMOTE_LOOPBACK_CTRL, BIT(1), 0);

	mode = ssdk_dt_global_get_mac_mode(dev_id, 0);

	/*init combo phy address*/
	combo_phy_addr = first_phy_addr+4;

	return SW_OK;
}

static int malibu_phy_api_ops_init(void)
{

	int ret;
	hsl_phy_ops_t *malibu_phy_api_ops = NULL;

	malibu_phy_api_ops = kzalloc(sizeof(hsl_phy_ops_t), GFP_KERNEL);
	if (malibu_phy_api_ops == NULL) {
		SSDK_ERROR("malibu phy ops kzalloc failed!\n");
		return -ENOMEM;
	}

	phy_api_ops_init(MALIBU_PHY_CHIP);

	ret = hsl_phy_api_ops_register(MALIBU_PHY_CHIP, malibu_phy_api_ops);

	if (ret == 0)
		SSDK_INFO("qca probe malibu phy driver succeeded!\n");
	else
		SSDK_ERROR("qca probe malibu phy driver failed! (code: %d)\n", ret);
	return ret;
}

/******************************************************************************
*
* malibu_phy_init -
*
*/
int malibu_phy_init(a_uint32_t dev_id, a_uint32_t port_bmp)
{
	static a_uint32_t phy_ops_flag = 0;

	if(phy_ops_flag == 0) {
		malibu_phy_api_ops_init();
		phy_ops_flag = 1;
	}
	malibu_phy_hw_init(dev_id, port_bmp);

	return 0;
}

