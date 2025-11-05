/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

/**
 * @defgroup
 * @{
 */

#include "hsl_reg.h"
#include "adpt.h"
#include "fal_portvlan.h"

sw_error_t
adpt_jhppe_vlan_trans_dscp_pcp_mapping_set(a_uint32_t dev_id, fal_port_vlan_direction_t direction,
		a_uint8_t group_id, a_uint8_t dscp, a_uint8_t pcp)
{
	sw_error_t rv = SW_OK;

	if (direction == FAL_PORT_VLAN_INGRESS || direction == FAL_PORT_VLAN_ALL) {
		switch(group_id) {
		case 0:
			rv = jhppe_in_vlan_dscp_pbit_map_tbl_pcp_0_set(dev_id, dscp, pcp);
			break;
		case 1:
			rv = jhppe_in_vlan_dscp_pbit_map_tbl_pcp_1_set(dev_id, dscp, pcp);
			break;
		default:
			rv = SW_NOT_SUPPORTED;
			break;
		}
	}

	SW_RTN_ON_ERROR(rv);

	if (direction == FAL_PORT_VLAN_EGRESS || direction == FAL_PORT_VLAN_ALL) {
		switch(group_id) {
		case 0:
			rv = jhppe_dscp_pbit_map_tbl_pcp_0_set(dev_id, dscp, pcp);
			break;
		case 1:
			rv = jhppe_dscp_pbit_map_tbl_pcp_1_set(dev_id, dscp, pcp);
			break;
		default:
			rv = SW_NOT_SUPPORTED;
			break;
		}
	}

	return rv;
}

sw_error_t
adpt_jhppe_vlan_trans_dscp_pcp_mapping_get(a_uint32_t dev_id, fal_port_vlan_direction_t direction,
		a_uint8_t group_id, a_uint8_t dscp, a_uint8_t *pcp)
{
	a_uint32_t val = 0;
	sw_error_t rv;

	if (direction == FAL_PORT_VLAN_INGRESS) {
		switch(group_id) {
		case 0:
			rv = jhppe_in_vlan_dscp_pbit_map_tbl_pcp_0_get(dev_id, dscp, &val);
			break;
		case 1:
			rv = jhppe_in_vlan_dscp_pbit_map_tbl_pcp_1_get(dev_id, dscp, &val);
			break;
		default:
			rv = SW_NOT_SUPPORTED;
			break;
		}
	} else if (direction == FAL_PORT_VLAN_EGRESS) {
		switch (group_id) {
		case 0:
			rv = jhppe_dscp_pbit_map_tbl_pcp_0_get(dev_id, dscp, &val);
			break;
		case 1:
			rv = jhppe_dscp_pbit_map_tbl_pcp_1_get(dev_id, dscp, &val);
			break;
		default:
			rv = SW_NOT_SUPPORTED;
			break;
		}
	} else {
		rv = SW_NOT_SUPPORTED;
	}

	*pcp = val;
	return rv;
}

#ifndef IN_PORTVLAN_MINI
sw_error_t
adpt_jhppe_port_isol_action_ctrl_set(a_uint32_t dev_id,
		fal_port_isol_act_ctrl_t *act_ctrl)
{
	sw_error_t rv = SW_OK;
	union l2_global_conf_u reg_val;

	rv = hppe_l2_global_conf_get(dev_id, &reg_val);
	SW_RTN_ON_ERROR(rv);

	reg_val.bf.bc_pvlan_isol_en = act_ctrl->bc_isol_en;
	reg_val.bf.mc_pvlan_isol_en = act_ctrl->mc_isol_en;

	rv = hppe_l2_global_conf_set(dev_id, &reg_val);

	return rv;
}

sw_error_t
adpt_jhppe_port_isol_action_ctrl_get(a_uint32_t dev_id,
		fal_port_isol_act_ctrl_t *act_ctrl)
{
	sw_error_t rv = SW_OK;
	union l2_global_conf_u reg_val;

	rv = hppe_l2_global_conf_get(dev_id, &reg_val);
	SW_RTN_ON_ERROR(rv);

	act_ctrl->bc_isol_en = reg_val.bf.bc_pvlan_isol_en;
	act_ctrl->mc_isol_en = reg_val.bf.mc_pvlan_isol_en;

	return SW_OK;
}

sw_error_t
adpt_jhppe_port_isol_action_set(a_uint32_t dev_id,
		fal_port_isol_act_idx_t *isol_id, fal_port_isol_act_t *isol_act)
{
	sw_error_t rv = SW_OK;
	union port_isol_action_u pp_isol_act;
	union vp_isol_action_tbl_u vp_isol_act;

	if (isol_id->isol_type == FAL_ISOL_ACT_PPORT) {
		rv = jhppe_port_isol_action_get(dev_id, isol_id->pport_id, &pp_isol_act);
		SW_RTN_ON_ERROR(rv);

		pp_isol_act.bf.action = isol_act->act_bitmap[0] & ((1 << PORT_ISOL_ACTION_ACTION_LEN) - 1);

		rv = jhppe_port_isol_action_set(dev_id, isol_id->pport_id, &pp_isol_act);
		SW_RTN_ON_ERROR(rv);
	} else {
		a_uint32_t i;

		rv = jhppe_vp_isol_action_tbl_get(dev_id, isol_id->isol_group_id, &vp_isol_act);
		SW_RTN_ON_ERROR(rv);

		for (i = 0; i < FAL_ISOL_ACT_ARR_SIZE; i++) {
			vp_isol_act.val[i] = isol_act->act_bitmap[i];
		}

		rv = jhppe_vp_isol_action_tbl_set(dev_id, isol_id->isol_group_id, &vp_isol_act);
		SW_RTN_ON_ERROR(rv);
	}

	return rv;
}

sw_error_t
adpt_jhppe_port_isol_action_get(a_uint32_t dev_id,
		fal_port_isol_act_idx_t *isol_id, fal_port_isol_act_t *isol_act)
{
	sw_error_t rv = SW_OK;
	union port_isol_action_u pp_isol_act;
	union vp_isol_action_tbl_u vp_isol_act;

	if (isol_id->isol_type == FAL_ISOL_ACT_PPORT) {
		rv = jhppe_port_isol_action_get(dev_id, isol_id->pport_id, &pp_isol_act);
		SW_RTN_ON_ERROR(rv);

		isol_act->act_bitmap[0] = pp_isol_act.bf.action;
	} else {
		a_uint32_t i;

		rv = jhppe_vp_isol_action_tbl_get(dev_id, isol_id->isol_group_id, &vp_isol_act);
		SW_RTN_ON_ERROR(rv);

		for (i = 0; i < FAL_ISOL_ACT_ARR_SIZE; i++) {
			isol_act->act_bitmap[i] = vp_isol_act.val[i];
		}
	}

	return rv;
}

sw_error_t
adpt_jhppe_port_isol_ctrl_set(a_uint32_t dev_id,
		fal_port_t port_id, fal_port_isol_ctrl_t *isol_ctrl)
{
	sw_error_t rv = SW_OK;
	union l2_vp_port_tbl_u l2_vp_pre_tbl;
	union l2_vp_port_post_tbl_u l2_vp_post_tbl;
	a_uint32_t port_value = FAL_PORT_ID_VALUE(port_id);

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(isol_ctrl);

	aos_mem_zero(&l2_vp_pre_tbl, sizeof(union l2_vp_port_tbl_u));
	aos_mem_zero(&l2_vp_post_tbl, sizeof(union l2_vp_port_post_tbl_u));

	if (isol_ctrl->dir == FAL_DIR_INGRESS || isol_ctrl->dir == FAL_DIR_BOTH) {
		rv = appe_l2_vp_port_tbl_get(dev_id, port_value, &l2_vp_pre_tbl);
		SW_RTN_ON_ERROR(rv);

		l2_vp_pre_tbl.bf.isol_profile_en = isol_ctrl->enable;
		l2_vp_pre_tbl.bf.isol_profile = isol_ctrl->isol_group_id;

		rv = appe_l2_vp_port_tbl_set(dev_id, port_value, &l2_vp_pre_tbl);
		SW_RTN_ON_ERROR(rv);
	}

	if (isol_ctrl->dir == FAL_DIR_EGRESS || isol_ctrl->dir == FAL_DIR_BOTH) {
		rv = jhppe_l2_vp_port_post_tbl_get(dev_id, port_value, &l2_vp_post_tbl);
		SW_RTN_ON_ERROR(rv);

		l2_vp_post_tbl.bf.isol_profile_en = isol_ctrl->enable;
		l2_vp_post_tbl.bf.isol_profile = isol_ctrl->isol_group_id;

		rv = jhppe_l2_vp_port_post_tbl_set(dev_id, port_value, &l2_vp_post_tbl);
		SW_RTN_ON_ERROR(rv);
	}

	return rv;
}

sw_error_t
adpt_jhppe_port_isol_ctrl_get(a_uint32_t dev_id,
		fal_port_t port_id, fal_port_isol_ctrl_t *isol_ctrl)
{
	sw_error_t rv = SW_OK;
	union l2_vp_port_tbl_u l2_vp_pre_tbl;
	union l2_vp_port_post_tbl_u l2_vp_post_tbl;
	a_uint32_t port_value = FAL_PORT_ID_VALUE(port_id);

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(isol_ctrl);

	aos_mem_zero(&l2_vp_pre_tbl, sizeof(union l2_vp_port_tbl_u));
	aos_mem_zero(&l2_vp_post_tbl, sizeof(union l2_vp_port_post_tbl_u));

	rv = appe_l2_vp_port_tbl_get(dev_id, port_value, &l2_vp_pre_tbl);
	SW_RTN_ON_ERROR(rv);
	rv = jhppe_l2_vp_port_post_tbl_get(dev_id, port_value, &l2_vp_post_tbl);
	SW_RTN_ON_ERROR(rv);

	if (isol_ctrl->dir == FAL_DIR_BOTH) {
		if (l2_vp_pre_tbl.bf.isol_profile_en != l2_vp_post_tbl.bf.isol_profile_en ||
			l2_vp_pre_tbl.bf.isol_profile != l2_vp_post_tbl.bf.isol_profile)
			return SW_NOT_SUPPORTED;

		isol_ctrl->enable = l2_vp_pre_tbl.bf.isol_profile_en;
		isol_ctrl->isol_group_id = l2_vp_pre_tbl.bf.isol_profile;
	}

	if (isol_ctrl->dir == FAL_DIR_INGRESS) {
		isol_ctrl->enable = l2_vp_pre_tbl.bf.isol_profile_en;
		isol_ctrl->isol_group_id = l2_vp_pre_tbl.bf.isol_profile;
	}

	if (isol_ctrl->dir == FAL_DIR_EGRESS) {
		isol_ctrl->enable = l2_vp_post_tbl.bf.isol_profile_en;
		isol_ctrl->isol_group_id = l2_vp_post_tbl.bf.isol_profile;
	}

	return rv;
}
#endif
