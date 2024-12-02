/*
 * Copyright (c) 2018, 2020-2021, The Linux Foundation. All rights reserved.
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
/*qca808x_start*/
#include "sw.h"
#include "fal_port_ctrl.h"
#include "hsl_api.h"
#include "hsl.h"
#include "hsl_phy.h"
#include "qcaphy_common.h"
#include "ssdk_plat.h"
#include "qca808x_phy.h"
/*qca808x_end*/
#include "qca808x.h"
#if defined(MHT)
#include "mht_sec_ctrl.h"
#endif

static a_bool_t qca808x_ssdk_phy_drv_registered = A_FALSE;
/*qca808x_start*/
static a_bool_t phy_ops_flag = A_FALSE;

static sw_error_t qca808x_phy_api_ops_init(a_uint32_t dev_id, a_uint32_t port_bmp)
{
	sw_error_t  ret = SW_OK;
	hsl_phy_ops_t *qca808x_phy_api_ops = NULL;

	qca808x_phy_api_ops = kzalloc(sizeof(hsl_phy_ops_t), GFP_KERNEL);
	if (qca808x_phy_api_ops == NULL) {
		SSDK_ERROR("qca808x phy ops kzalloc failed!\n");
		return -ENOMEM;
	}

	phy_api_ops_init(QCA808X_PHY_CHIP);

/*qca808x_end*/
/*qca808x_start*/
	ret = hsl_phy_api_ops_register(QCA808X_PHY_CHIP, qca808x_phy_api_ops);

	if (ret == SW_OK) {
		SSDK_INFO("qca probe qca808x phy driver succeeded!\n");
	} else {
		SSDK_ERROR("qca probe qca808x phy driver failed! (code: %d)\n", ret);
	}

	return ret;
}

/******************************************************************************
*
* qca808x_phy_init -
*
*/
int qca808x_phy_init(a_uint32_t dev_id, a_uint32_t port_bmp)
{
/*qca808x_end*/
	a_uint32_t port_id = 0;
/*qca808x_start*/
	int ret = 0;

	if(phy_ops_flag == A_FALSE &&
			qca808x_phy_api_ops_init(dev_id, port_bmp) == SW_OK) {
		phy_ops_flag = A_TRUE;
	}
/*qca808x_end*/
	for (port_id = 0; port_id < SW_MAX_NR_PORT; port_id ++)
	{
		if (port_bmp & (0x1 << port_id)) {
			qca808x_phydev_init(dev_id, port_id);
		}
	}

	if (qca808x_ssdk_phy_drv_registered == A_FALSE) {
		ret |= qca808x_phy_driver_register();
		qca808x_ssdk_phy_drv_registered = A_TRUE;
	}

/*qca808x_start*/
	return ret;
}

void qca808x_phy_exit(a_uint32_t dev_id, a_uint32_t port_bmp)
{
/*qca808x_end*/
	a_uint32_t port_id = 0;

	if (qca808x_ssdk_phy_drv_registered == A_TRUE) {
		qca808x_phy_driver_unregister();
		qca808x_ssdk_phy_drv_registered = A_FALSE;
	}

	for (port_id = 0; port_id < SW_MAX_NR_PORT; port_id ++)
	{
		if (port_bmp & (0x1 << port_id)) {
			qca808x_phydev_deinit(dev_id, port_id);
		}
	}
/*qca808x_start*/
}
/*qca808x_end*/
