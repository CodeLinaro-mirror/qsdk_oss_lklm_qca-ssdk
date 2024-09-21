/*
 * Copyright (c) 2012, 2015-2018, The Linux Foundation. All rights reserved.
 * Copyright (c) 2023-2024 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "sw.h"
#include "fal_port_ctrl.h"
#include "hsl_api.h"
#include "hsl.h"
#include "f1_phy.h"
#include "hsl_phy.h"
#include "qcaphy_common.h"
#include "ssdk_plat.h"

static int f1_phy_api_ops_init(void)
{
	int ret;
	hsl_phy_ops_t *f1_phy_api_ops = NULL;

	f1_phy_api_ops = kzalloc(sizeof(hsl_phy_ops_t), GFP_KERNEL);
	if (f1_phy_api_ops == NULL) {
		SSDK_ERROR("f1 phy ops kzalloc failed!\n");
		return -ENOMEM;
	}

	phy_api_ops_init(F1_PHY_CHIP);

	ret = hsl_phy_api_ops_register(F1_PHY_CHIP, f1_phy_api_ops);

	if (ret == 0)
		SSDK_INFO("qca probe f1 phy driver succeeded!\n");
	else
		SSDK_ERROR("qca probe f1 phy driver failed! (code: %d)\n", ret);
	return ret;
}

int f1_phy_init(a_uint32_t dev_id, a_uint32_t port_bmp)
{
	static a_uint32_t phy_ops_flag = 0;

	if(phy_ops_flag == 0) {
		f1_phy_api_ops_init();
		phy_ops_flag = 1;
	}

	return 0;
}

