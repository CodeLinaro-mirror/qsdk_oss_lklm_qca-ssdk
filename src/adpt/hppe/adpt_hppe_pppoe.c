/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 *
 * Copyright (c) 2021, 2023-2025 Qualcomm Innovation Center, Inc. All rights reserved.
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


/**
 * @defgroup
 * @{
 */
#include "sw.h"
#include "hppe_pppoe_reg.h"
#include "hppe_pppoe.h"
#include "hppe_ip_reg.h"
#include "hppe_ip.h"
#include "adpt.h"
#if defined(APPE)
#include "adpt_appe_pppoe.h"
#endif

#define MAX_SESSION_ID 0xffff

sw_error_t
adpt_hppe_pppoe_en_set(a_uint32_t dev_id, a_uint32_t l3_if, a_uint32_t enable)
{
	sw_error_t rv = SW_OK;
	union in_l3_if_tbl_u in_l3_if_tbl = {0};
	union eg_l3_if_tbl_u eg_l3_if_tbl = {0};

	ADPT_DEV_ID_CHECK(dev_id);

	rv = hppe_in_l3_if_tbl_get(dev_id, l3_if, &in_l3_if_tbl);
	SW_RTN_ON_ERROR(rv);

	rv = hppe_eg_l3_if_tbl_get(dev_id, l3_if, &eg_l3_if_tbl);
	SW_RTN_ON_ERROR(rv);

	in_l3_if_tbl.bf.pppoe_en = enable;
	eg_l3_if_tbl.bf.pppoe_en = enable;

	rv = hppe_in_l3_if_tbl_set(dev_id, l3_if, &in_l3_if_tbl);
	SW_RTN_ON_ERROR(rv);

	rv = hppe_eg_l3_if_tbl_set(dev_id, l3_if, &eg_l3_if_tbl);

	return rv;
}

sw_error_t
adpt_hppe_pppoe_en_get(a_uint32_t dev_id, a_uint32_t l3_if, a_uint32_t *enable)
{
	sw_error_t rv = SW_OK;
	union in_l3_if_tbl_u in_l3_if_tbl = {0};

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(enable);

	rv = hppe_in_l3_if_tbl_get(dev_id, l3_if, &in_l3_if_tbl);
	SW_RTN_ON_ERROR(rv);

	*enable = in_l3_if_tbl.bf.pppoe_en;

	return rv;
}

sw_error_t
adpt_hppe_pppoe_global_ctrl_set(a_uint32_t dev_id, fal_pppoe_global_cfg_t *cfg)
{
	sw_error_t rv = SW_OK;
	union l3_route_ctrl_u l3_route_ctrl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(cfg);

	aos_mem_zero(&l3_route_ctrl, sizeof(l3_route_ctrl));

	rv = hppe_l3_route_ctrl_get(dev_id, &l3_route_ctrl);
	SW_RTN_ON_ERROR(rv);

	l3_route_ctrl.bf.pppoe_multicast_cmd = cfg->pppoe_multicast_cmd;
	l3_route_ctrl.bf.pppoe_multicast_de_acce = cfg->pppoe_multicast_deacclr_en;

	rv = hppe_l3_route_ctrl_set(dev_id, &l3_route_ctrl);
	return rv;
}

sw_error_t
adpt_hppe_pppoe_global_ctrl_get(a_uint32_t dev_id, fal_pppoe_global_cfg_t *cfg)
{
	sw_error_t rv = SW_OK;
	union l3_route_ctrl_u l3_route_ctrl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(cfg);

	aos_mem_zero(&l3_route_ctrl, sizeof(l3_route_ctrl));

	rv = hppe_l3_route_ctrl_get(dev_id, &l3_route_ctrl);
	SW_RTN_ON_ERROR(rv);

	cfg->pppoe_multicast_cmd = l3_route_ctrl.bf.pppoe_multicast_cmd;
	cfg->pppoe_multicast_deacclr_en = l3_route_ctrl.bf.pppoe_multicast_de_acce;

	return rv;
}

sw_error_t adpt_hppe_pppoe_init(a_uint32_t dev_id)
{
	adpt_api_t *p_adpt_api = NULL;

	p_adpt_api = adpt_api_ptr_get(dev_id);

	if(p_adpt_api == NULL)
		return SW_FAIL;

#if defined(APPE)
	p_adpt_api->adpt_pppoe_session_table_add = adpt_appe_pppoe_session_table_add;
	p_adpt_api->adpt_pppoe_session_table_del = adpt_appe_pppoe_session_table_del;
	p_adpt_api->adpt_pppoe_session_table_get = adpt_appe_pppoe_session_table_get;
#endif
	p_adpt_api->adpt_pppoe_en_set = adpt_hppe_pppoe_en_set;
	p_adpt_api->adpt_pppoe_en_get = adpt_hppe_pppoe_en_get;
#if defined(APPE)
	p_adpt_api->adpt_pppoe_l3_intf_set = adpt_appe_pppoe_l3_intf_set;
	p_adpt_api->adpt_pppoe_l3_intf_get = adpt_appe_pppoe_l3_intf_get;
#endif
	p_adpt_api->adpt_pppoe_global_ctrl_set = adpt_hppe_pppoe_global_ctrl_set;
	p_adpt_api->adpt_pppoe_global_ctrl_get = adpt_hppe_pppoe_global_ctrl_get;

	return SW_OK;
}

/**
 * @}
 */
