/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */
#include "hsl_htt_reg.h"

sw_error_t
httppe_port_parsing_reg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_parsing_reg_u *value)
{
	if (index >= PORT_PARSING_REG_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				IPR_CSR_BASE_ADDR + PORT_PARSING_REG_ADDRESS + \
				index * PORT_PARSING_REG_INC,
				&value->val);
}

sw_error_t
httppe_port_parsing_reg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_parsing_reg_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPR_CSR_BASE_ADDR + PORT_PARSING_REG_ADDRESS + \
				index * PORT_PARSING_REG_INC,
				value->val);
}

sw_error_t
httppe_vlan_tpid_reg_get(
		a_uint32_t dev_id,
		union vlan_tpid_reg_u *value)
{
	return hppe_reg_get(
				dev_id,
				IPR_CSR_BASE_ADDR + VLAN_TPID_REG_ADDRESS,
				&value->val);
}

sw_error_t
httppe_vlan_tpid_reg_set(
		a_uint32_t dev_id,
		union vlan_tpid_reg_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPR_CSR_BASE_ADDR + VLAN_TPID_REG_ADDRESS,
				value->val);
}

sw_error_t
httppe_vlan_tpid_reg_ctag_tpid_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union vlan_tpid_reg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_get(dev_id, &reg_val);
	*value = reg_val.bf.ctag_tpid;
	return ret;
}

sw_error_t
httppe_vlan_tpid_reg_ctag_tpid_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union vlan_tpid_reg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ctag_tpid = value;
	ret = httppe_vlan_tpid_reg_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_vlan_tpid_reg_stag_tpid_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union vlan_tpid_reg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_get(dev_id, &reg_val);
	*value = reg_val.bf.stag_tpid;
	return ret;
}

sw_error_t
httppe_vlan_tpid_reg_stag_tpid_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union vlan_tpid_reg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.stag_tpid = value;
	ret = httppe_vlan_tpid_reg_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_ipr_vp_parsing_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_vp_parsing_u *value)
{
	if (index >= IPR_VP_PARSING_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_VP_PARSING_ADDRESS + \
				index * IPR_VP_PARSING_INC,
				&value->val);
}

sw_error_t
httppe_ipr_vp_parsing_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_vp_parsing_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_VP_PARSING_ADDRESS + \
				index * IPR_VP_PARSING_INC,
				value->val);
}

sw_error_t
httppe_vlan_tpid_reg_ext0_get(
		a_uint32_t dev_id,
		union vlan_tpid_reg_ext0_u *value)
{
	return hppe_reg_get(
				dev_id,
				IPR_CSR_BASE_ADDR + VLAN_TPID_REG_EXT0_ADDRESS,
				&value->val);
}

sw_error_t
httppe_vlan_tpid_reg_ext0_set(
		a_uint32_t dev_id,
		union vlan_tpid_reg_ext0_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPR_CSR_BASE_ADDR + VLAN_TPID_REG_EXT0_ADDRESS,
				value->val);
}

sw_error_t
httppe_vlan_tpid_reg_ext0_ctag_tpid_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union vlan_tpid_reg_ext0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_ext0_get(dev_id, &reg_val);
	*value = reg_val.bf.ctag_tpid;
	return ret;
}

sw_error_t
httppe_vlan_tpid_reg_ext0_ctag_tpid_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union vlan_tpid_reg_ext0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_ext0_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ctag_tpid = value;
	ret = httppe_vlan_tpid_reg_ext0_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_vlan_tpid_reg_ext0_stag_tpid_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union vlan_tpid_reg_ext0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_ext0_get(dev_id, &reg_val);
	*value = reg_val.bf.stag_tpid;
	return ret;
}

sw_error_t
httppe_vlan_tpid_reg_ext0_stag_tpid_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union vlan_tpid_reg_ext0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_ext0_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.stag_tpid = value;
	ret = httppe_vlan_tpid_reg_ext0_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_vlan_tpid_reg_ext1_get(
		a_uint32_t dev_id,
		union vlan_tpid_reg_ext1_u *value)
{
	return hppe_reg_get(
				dev_id,
				IPR_CSR_BASE_ADDR + VLAN_TPID_REG_EXT1_ADDRESS,
				&value->val);
}

sw_error_t
httppe_vlan_tpid_reg_ext1_set(
		a_uint32_t dev_id,
		union vlan_tpid_reg_ext1_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPR_CSR_BASE_ADDR + VLAN_TPID_REG_EXT1_ADDRESS,
				value->val);
}

sw_error_t
httppe_vlan_tpid_reg_ext1_ctag_tpid_map_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union vlan_tpid_reg_ext1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_ext1_get(dev_id, &reg_val);
	*value = reg_val.bf.ctag_tpid_map;
	return ret;
}

sw_error_t
httppe_vlan_tpid_reg_ext1_ctag_tpid_map_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union vlan_tpid_reg_ext1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_ext1_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ctag_tpid_map = value;
	ret = httppe_vlan_tpid_reg_ext1_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_vlan_tpid_reg_ext1_stag_tpid_map_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union vlan_tpid_reg_ext1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_ext1_get(dev_id, &reg_val);
	*value = reg_val.bf.stag_tpid_map;
	return ret;
}

sw_error_t
httppe_vlan_tpid_reg_ext1_stag_tpid_map_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union vlan_tpid_reg_ext1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_vlan_tpid_reg_ext1_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.stag_tpid_map = value;
	ret = httppe_vlan_tpid_reg_ext1_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_xlt_rule_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union xlt_rule_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				INGRESS_VLAN_BASE_ADDR + XLT_RULE_TBL_ADDRESS + \
				index * XLT_RULE_TBL_INC,
				value->val,
				sizeof(union xlt_rule_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_xlt_rule_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union xlt_rule_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				INGRESS_VLAN_BASE_ADDR + XLT_RULE_TBL_ADDRESS + \
				index * XLT_RULE_TBL_INC,
				value->val,
				sizeof(union xlt_rule_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_xlt_action_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union xlt_action_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				INGRESS_VLAN_BASE_ADDR + XLT_ACTION_TBL_ADDRESS + \
				index * XLT_ACTION_TBL_INC,
				value->val,
				sizeof(union xlt_action_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_xlt_action_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union xlt_action_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				INGRESS_VLAN_BASE_ADDR + XLT_ACTION_TBL_ADDRESS + \
				index * XLT_ACTION_TBL_INC,
				value->val,
				sizeof(union xlt_action_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_in_vlan_dscp_pbit_map_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union in_vlan_dscp_pbit_map_tbl_u *value)
{
	if (index >= IN_VLAN_DSCP_PBIT_MAP_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				INGRESS_VLAN_BASE_ADDR + IN_VLAN_DSCP_PBIT_MAP_TBL_ADDRESS + \
				index * IN_VLAN_DSCP_PBIT_MAP_TBL_INC,
				&value->val);
}

sw_error_t
httppe_in_vlan_dscp_pbit_map_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union in_vlan_dscp_pbit_map_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				INGRESS_VLAN_BASE_ADDR + IN_VLAN_DSCP_PBIT_MAP_TBL_ADDRESS + \
				index * IN_VLAN_DSCP_PBIT_MAP_TBL_INC,
				value->val);
}

sw_error_t
httppe_port_eg_vlan_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_eg_vlan_u *value)
{
	if (index >= PORT_EG_VLAN_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + PORT_EG_VLAN_ADDRESS + \
				index * PORT_EG_VLAN_INC,
				&value->val);
}

sw_error_t
httppe_port_eg_vlan_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_eg_vlan_u *value)
{
	return hppe_reg_set(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + PORT_EG_VLAN_ADDRESS + \
				index * PORT_EG_VLAN_INC,
				value->val);
}

sw_error_t
httppe_port_eg_vlan_port_eg_dei_prop_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_eg_dei_prop_cmd;
	return ret;
}

sw_error_t
httppe_port_eg_vlan_port_eg_dei_prop_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_eg_dei_prop_cmd = value;
	ret = httppe_port_eg_vlan_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_port_eg_vlan_port_eg_pcp_prop_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_eg_pcp_prop_cmd;
	return ret;
}

sw_error_t
httppe_port_eg_vlan_port_eg_pcp_prop_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_eg_pcp_prop_cmd = value;
	ret = httppe_port_eg_vlan_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_port_eg_vlan_port_eg_vlan_ctag_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_eg_vlan_ctag_mode;
	return ret;
}

sw_error_t
httppe_port_eg_vlan_port_eg_vlan_ctag_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_eg_vlan_ctag_mode = value;
	ret = httppe_port_eg_vlan_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_port_eg_vlan_port_eg_vlan_stag_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_eg_vlan_stag_mode;
	return ret;
}

sw_error_t
httppe_port_eg_vlan_port_eg_vlan_stag_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_eg_vlan_stag_mode = value;
	ret = httppe_port_eg_vlan_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_port_eg_vlan_port_vlan_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_vlan_type;
	return ret;
}

sw_error_t
httppe_port_eg_vlan_port_vlan_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_vlan_type = value;
	ret = httppe_port_eg_vlan_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_port_eg_vlan_tx_counting_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	*value = reg_val.bf.tx_counting_en;
	return ret;
}

sw_error_t
httppe_port_eg_vlan_tx_counting_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tx_counting_en = value;
	ret = httppe_port_eg_vlan_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_port_eg_vlan_vsi_tag_mode_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	*value = reg_val.bf.vsi_tag_mode_en;
	return ret;
}

sw_error_t
httppe_port_eg_vlan_vsi_tag_mode_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union port_eg_vlan_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_port_eg_vlan_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.vsi_tag_mode_en = value;
	ret = httppe_port_eg_vlan_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vlan_tpid_get(
		a_uint32_t dev_id,
		union eg_vlan_tpid_u *value)
{
	return hppe_reg_get(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VLAN_TPID_ADDRESS,
				&value->val);
}

sw_error_t
httppe_eg_vlan_tpid_set(
		a_uint32_t dev_id,
		union eg_vlan_tpid_u *value)
{
	return hppe_reg_set(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VLAN_TPID_ADDRESS,
				value->val);
}

sw_error_t
httppe_eg_vlan_tpid_ctpid_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_vlan_tpid_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_get(dev_id, &reg_val);
	*value = reg_val.bf.ctpid;
	return ret;
}

sw_error_t
httppe_eg_vlan_tpid_ctpid_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_vlan_tpid_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ctpid = value;
	ret = httppe_eg_vlan_tpid_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vlan_tpid_stpid_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_vlan_tpid_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_get(dev_id, &reg_val);
	*value = reg_val.bf.stpid;
	return ret;
}

sw_error_t
httppe_eg_vlan_tpid_stpid_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_vlan_tpid_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.stpid = value;
	ret = httppe_eg_vlan_tpid_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_bridge_config_get(
		a_uint32_t dev_id,
		union eg_bridge_config_u *value)
{
	return hppe_reg_get(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_BRIDGE_CONFIG_ADDRESS,
				&value->val);
}

sw_error_t
httppe_eg_bridge_config_set(
		a_uint32_t dev_id,
		union eg_bridge_config_u *value)
{
	return hppe_reg_set(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_BRIDGE_CONFIG_ADDRESS,
				value->val);
}

sw_error_t
httppe_eg_vlan_tpid_ext0_get(
		a_uint32_t dev_id,
		union eg_vlan_tpid_ext0_u *value)
{
	return hppe_reg_get(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VLAN_TPID_EXT0_ADDRESS,
				&value->val);
}

sw_error_t
httppe_eg_vlan_tpid_ext0_set(
		a_uint32_t dev_id,
		union eg_vlan_tpid_ext0_u *value)
{
	return hppe_reg_set(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VLAN_TPID_EXT0_ADDRESS,
				value->val);
}

sw_error_t
httppe_eg_vlan_tpid_ext0_ctpid_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_vlan_tpid_ext0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_ext0_get(dev_id, &reg_val);
	*value = reg_val.bf.ctpid;
	return ret;
}

sw_error_t
httppe_eg_vlan_tpid_ext0_ctpid_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_vlan_tpid_ext0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_ext0_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ctpid = value;
	ret = httppe_eg_vlan_tpid_ext0_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vlan_tpid_ext0_stpid_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_vlan_tpid_ext0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_ext0_get(dev_id, &reg_val);
	*value = reg_val.bf.stpid;
	return ret;
}

sw_error_t
httppe_eg_vlan_tpid_ext0_stpid_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_vlan_tpid_ext0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_ext0_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.stpid = value;
	ret = httppe_eg_vlan_tpid_ext0_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vlan_tpid_ext1_get(
		a_uint32_t dev_id,
		union eg_vlan_tpid_ext1_u *value)
{
	return hppe_reg_get(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VLAN_TPID_EXT1_ADDRESS,
				&value->val);
}

sw_error_t
httppe_eg_vlan_tpid_ext1_set(
		a_uint32_t dev_id,
		union eg_vlan_tpid_ext1_u *value)
{
	return hppe_reg_set(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VLAN_TPID_EXT1_ADDRESS,
				value->val);
}

sw_error_t
httppe_eg_vlan_tpid_ext1_ctag_tpid_map_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_vlan_tpid_ext1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_ext1_get(dev_id, &reg_val);
	*value = reg_val.bf.ctag_tpid_map;
	return ret;
}

sw_error_t
httppe_eg_vlan_tpid_ext1_ctag_tpid_map_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_vlan_tpid_ext1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_ext1_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ctag_tpid_map = value;
	ret = httppe_eg_vlan_tpid_ext1_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vlan_tpid_ext1_stag_tpid_map_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_vlan_tpid_ext1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_ext1_get(dev_id, &reg_val);
	*value = reg_val.bf.stag_tpid_map;
	return ret;
}

sw_error_t
httppe_eg_vlan_tpid_ext1_stag_tpid_map_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_vlan_tpid_ext1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_vlan_tpid_ext1_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.stag_tpid_map = value;
	ret = httppe_eg_vlan_tpid_ext1_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vlan_xlt_action_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union eg_vlan_xlt_action_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VLAN_XLT_ACTION_ADDRESS + \
				index * EG_VLAN_XLT_ACTION_INC,
				value->val,
				sizeof(union eg_vlan_xlt_action_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_eg_vlan_xlt_action_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union eg_vlan_xlt_action_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VLAN_XLT_ACTION_ADDRESS + \
				index * EG_VLAN_XLT_ACTION_INC,
				value->val,
				sizeof(union eg_vlan_xlt_action_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_egress_vp_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union eg_vp_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VP_TBL_ADDRESS + \
				index * EG_VP_TBL_INC,
				value->val,
				sizeof(union eg_vp_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_egress_vp_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union eg_vp_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VP_TBL_ADDRESS + \
				index * EG_VP_TBL_INC,
				value->val,
				sizeof(union eg_vp_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_eg_vp_tbl_ath_hdr_default_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ath_hdr_default_type;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_ath_hdr_default_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ath_hdr_default_type = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_ath_hdr_disable_bit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ath_hdr_disable_bit;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_ath_hdr_disable_bit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ath_hdr_disable_bit = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_ath_hdr_from_cpu_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ath_hdr_from_cpu;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_ath_hdr_from_cpu_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ath_hdr_from_cpu = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_ath_hdr_insert_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ath_hdr_insert;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_ath_hdr_insert_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ath_hdr_insert = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_ath_hdr_ver_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ath_hdr_ver;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_ath_hdr_ver_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ath_hdr_ver = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_ath_port_bitmap_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ath_port_bitmap_1 << 6 | \
		reg_val.bf.ath_port_bitmap_0;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_ath_port_bitmap_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ath_port_bitmap_1 = value >> 6;
	reg_val.bf.ath_port_bitmap_0 = value & (((a_uint64_t)1<<6)-1);
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_cnt_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.cnt_mode;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_cnt_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.cnt_mode = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_def_cvid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_def_cvid;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_def_cvid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_def_cvid = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_def_cvid_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_def_cvid_en;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_def_cvid_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_def_cvid_en = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_def_svid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_def_svid;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_def_svid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_def_svid = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_def_svid_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_def_svid_en;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_def_svid_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_def_svid_en = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_eg_dei_prop_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_eg_dei_prop_cmd;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_eg_dei_prop_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_eg_dei_prop_cmd = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_eg_pcp_prop_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_eg_pcp_prop_cmd;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_eg_pcp_prop_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_eg_pcp_prop_cmd = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_eg_vlan_ctag_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_eg_vlan_ctag_mode;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_eg_vlan_ctag_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_eg_vlan_ctag_mode = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_eg_vlan_stag_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_eg_vlan_stag_mode;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_eg_vlan_stag_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_eg_vlan_stag_mode = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_vlan_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_vlan_type;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_port_vlan_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_vlan_type = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_private_tag_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.private_tag_en;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_private_tag_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.private_tag_en = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_private_tag_tci_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.private_tag_tci;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_private_tag_tci_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.private_tag_tci = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_tunnel_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.tunnel_id;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_tunnel_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tunnel_id = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_tunnel_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.tunnel_valid;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_tunnel_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tunnel_valid = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_tx_counting_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.tx_counting_en;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_tx_counting_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tx_counting_en = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_vsi_tag_mode_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.vsi_tag_mode_en;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_vsi_tag_mode_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.vsi_tag_mode_en = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_xlat_profile_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.xlat_profile;
	return ret;
}

sw_error_t
httppe_eg_vp_tbl_xlat_profile_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union eg_vp_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_egress_vp_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.xlat_profile = value;
	ret = httppe_egress_vp_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_vlan_xlt_rule_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union eg_vlan_xlt_rule_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VLAN_XLT_RULE_ADDRESS + \
				index * EG_VLAN_XLT_RULE_INC,
				value->val,
				sizeof(union eg_vlan_xlt_rule_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_eg_vlan_xlt_rule_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union eg_vlan_xlt_rule_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_VLAN_XLT_RULE_ADDRESS + \
				index * EG_VLAN_XLT_RULE_INC,
				value->val,
				sizeof(union eg_vlan_xlt_rule_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_dscp_pbit_map_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union dscp_pbit_map_tbl_u *value)
{
	if (index >= DSCP_PBIT_MAP_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + DSCP_PBIT_MAP_TBL_ADDRESS + \
				index * DSCP_PBIT_MAP_TBL_INC,
				&value->val);
}

sw_error_t
httppe_dscp_pbit_map_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union dscp_pbit_map_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + DSCP_PBIT_MAP_TBL_ADDRESS + \
				index * DSCP_PBIT_MAP_TBL_INC,
				value->val);
}

