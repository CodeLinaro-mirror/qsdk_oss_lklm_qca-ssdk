/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

/**
 * @defgroup
 * @{
 */
#include "adpt.h"
#include "adpt_appe_vsi.h"
#include "hsl_htt_reg.h"

sw_error_t
adpt_httppe_vsi_stamove_set(a_uint32_t dev_id, a_uint32_t vsi_id, fal_vsi_stamove_t *stamove)
{
	sw_error_t rv;
	union vsi_tbl_u vsi_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(stamove);

	rv = httppe_vsi_tbl_get( dev_id, vsi_id, &vsi_tbl);
	SW_RTN_ON_ERROR(rv);

	vsi_tbl.bf.station_move_lrn_en = stamove->stamove_en;
	vsi_tbl.bf.station_move_fwd_cmd = stamove->action;

	rv = httppe_vsi_tbl_set( dev_id, vsi_id, &vsi_tbl);
	SW_RTN_ON_ERROR(rv);

	return SW_OK;
}

sw_error_t
adpt_httppe_vsi_stamove_get(a_uint32_t dev_id, a_uint32_t vsi_id, fal_vsi_stamove_t *stamove)
{
	sw_error_t rv;
	union vsi_tbl_u vsi_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(stamove);

	rv = httppe_vsi_tbl_get( dev_id, vsi_id, &vsi_tbl);
	SW_RTN_ON_ERROR(rv);

	stamove->stamove_en = vsi_tbl.bf.station_move_lrn_en;
	stamove->action = vsi_tbl.bf.station_move_fwd_cmd;

	return SW_OK;
}

sw_error_t
adpt_httppe_vsi_newaddr_lrn_get(a_uint32_t dev_id, a_uint32_t vsi_id, fal_vsi_newaddr_lrn_t *newaddr_lrn)
{
	sw_error_t rv;
	union vsi_tbl_u vsi_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(newaddr_lrn);

	rv = httppe_vsi_tbl_get( dev_id, vsi_id, &vsi_tbl);
	SW_RTN_ON_ERROR(rv);

	newaddr_lrn->lrn_en = vsi_tbl.bf.new_addr_lrn_en;
	newaddr_lrn->action = vsi_tbl.bf.new_addr_fwd_cmd;

	return SW_OK;
}

sw_error_t
adpt_httppe_vsi_newaddr_lrn_set(a_uint32_t dev_id, a_uint32_t vsi_id, fal_vsi_newaddr_lrn_t *newaddr_lrn)
{
	sw_error_t rv;
	union vsi_tbl_u vsi_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(newaddr_lrn);

	rv = httppe_vsi_tbl_get( dev_id, vsi_id, &vsi_tbl);
	SW_RTN_ON_ERROR(rv);

	vsi_tbl.bf.new_addr_lrn_en = newaddr_lrn->lrn_en;
	vsi_tbl.bf.new_addr_fwd_cmd = newaddr_lrn->action;

	rv = httppe_vsi_tbl_set( dev_id, vsi_id, &vsi_tbl);
	SW_RTN_ON_ERROR(rv);

	return SW_OK;
}

sw_error_t
adpt_httppe_vsi_member_set(a_uint32_t dev_id, a_uint32_t vsi_id, fal_vsi_member_t *vsi_member)
{
	sw_error_t rv;
	union vsi_tbl_u vsi_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(vsi_member);

	rv = httppe_vsi_tbl_get( dev_id, vsi_id, &vsi_tbl);
	SW_RTN_ON_ERROR(rv);

	vsi_tbl.bf.bc_bitmap_0 = vsi_member->bc_ports;
	vsi_tbl.bf.bc_bitmap_1 = vsi_member->bc_ports >> 5;
	vsi_tbl.bf.member_port_bitmap = vsi_member->member_ports;
	vsi_tbl.bf.umc_bitmap = vsi_member->umc_ports;
	vsi_tbl.bf.uuc_bitmap = vsi_member->uuc_ports;

	rv = httppe_vsi_tbl_set(dev_id, vsi_id, &vsi_tbl);
	SW_RTN_ON_ERROR(rv);

	rv = adpt_appe_vsi_vp_member_set(dev_id, vsi_id, vsi_member);
	SW_RTN_ON_ERROR(rv);

	return SW_OK;
}

sw_error_t
adpt_httppe_vsi_member_get(a_uint32_t dev_id, a_uint32_t vsi_id, fal_vsi_member_t *vsi_member)
{
	sw_error_t rv;
	union vsi_tbl_u vsi_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(vsi_member);

	rv = httppe_vsi_tbl_get( dev_id, vsi_id, &vsi_tbl);
	SW_RTN_ON_ERROR(rv);

	vsi_member->bc_ports = vsi_tbl.bf.bc_bitmap_0 | ((vsi_tbl.bf.bc_bitmap_1 & 0xf) << 5);
	vsi_member->member_ports = vsi_tbl.bf.member_port_bitmap;
	vsi_member->umc_ports = vsi_tbl.bf.umc_bitmap;
	vsi_member->uuc_ports = vsi_tbl.bf.uuc_bitmap;

	rv = adpt_appe_vsi_vp_member_get(dev_id, vsi_id, vsi_member);
	SW_RTN_ON_ERROR(rv);

	return SW_OK;
}
/**
 * @}
 */
