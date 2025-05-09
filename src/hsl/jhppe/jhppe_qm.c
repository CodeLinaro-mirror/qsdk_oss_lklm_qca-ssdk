/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#include "hsl_reg.h"

sw_error_t
jhppe_mc_enq_ctrl_get(
		a_uint32_t dev_id,
		union mc_enq_ctrl_u *value)
{
	return hppe_reg_get(
				dev_id,
				IPE_L2_BASE_ADDR + MC_ENQ_CTRL_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_mc_enq_ctrl_set(
		a_uint32_t dev_id,
		union mc_enq_ctrl_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPE_L2_BASE_ADDR + MC_ENQ_CTRL_ADDRESS,
				value->val);
}

sw_error_t
jhppe_mc_enq_ctrl_dot1p_pon_vp_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union mc_enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_mc_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.dot1p_pon_vp;
	return ret;
}

sw_error_t
jhppe_mc_enq_ctrl_dot1p_pon_vp_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union mc_enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_mc_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.dot1p_pon_vp = value;
	ret = jhppe_mc_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_mc_enq_ctrl_uc_enq_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union mc_enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_mc_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.uc_enq_en;
	return ret;
}

sw_error_t
jhppe_mc_enq_ctrl_uc_enq_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union mc_enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_mc_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.uc_enq_en = value;
	ret = jhppe_mc_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_mc_enq_ctrl_uc_port_id_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union mc_enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_mc_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.uc_port_id;
	return ret;
}

sw_error_t
jhppe_mc_enq_ctrl_uc_port_id_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union mc_enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_mc_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.uc_port_id = value;
	ret = jhppe_mc_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_get(
		a_uint32_t dev_id,
		union enq_ctrl_u *value)
{
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + ENQ_CTRL_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_enq_ctrl_set(
		a_uint32_t dev_id,
		union enq_ctrl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + ENQ_CTRL_ADDRESS,
				value->val);
}

sw_error_t
jhppe_enq_ctrl_pass_through0_direc_enq_dis_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through0_direc_enq_dis;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through0_direc_enq_dis_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through0_direc_enq_dis = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through0_src_profile;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through0_src_profile = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_eg_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through0_src_profile_eg_en;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_eg_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through0_src_profile_eg_en = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through0_src_profile_en;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through0_src_profile_en = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through1_direc_enq_dis_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through1_direc_enq_dis;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through1_direc_enq_dis_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through1_direc_enq_dis = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through1_src_profile;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through1_src_profile = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_eg_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through1_src_profile_eg_en;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_eg_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through1_src_profile_eg_en = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through1_src_profile_en;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through1_src_profile_en = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through2_direc_enq_dis_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through2_direc_enq_dis;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through2_direc_enq_dis_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through2_direc_enq_dis = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through2_src_profile;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through2_src_profile = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_eg_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through2_src_profile_eg_en;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_eg_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through2_src_profile_eg_en = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through2_src_profile_en;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through2_src_profile_en = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through3_direc_enq_dis_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through3_direc_enq_dis;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through3_direc_enq_dis_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through3_direc_enq_dis = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through3_src_profile;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through3_src_profile = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_eg_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through3_src_profile_eg_en;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_eg_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through3_src_profile_eg_en = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pass_through3_src_profile_en;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pass_through3_src_profile_en = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_qid_mismatch_enq_cpu_code_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.qid_mismatch_enq_cpu_code;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_qid_mismatch_enq_cpu_code_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.qid_mismatch_enq_cpu_code = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_queue_map_rule_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.queue_map_rule_en;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_queue_map_rule_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.queue_map_rule_en = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_uc_enq_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.uc_enq_en;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_uc_enq_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.uc_enq_en = value;
	ret = jhppe_enq_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_ext_get(
		a_uint32_t dev_id,
		union enq_ctrl_ext_u *value)
{
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + ENQ_CTRL_EXT_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_enq_ctrl_ext_set(
		a_uint32_t dev_id,
		union enq_ctrl_ext_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + ENQ_CTRL_EXT_ADDRESS,
				value->val);
}

sw_error_t
jhppe_enq_ctrl_ext_cpu_code_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_ext_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_ext_get(dev_id, &reg_val);
	*value = reg_val.bf.cpu_code_en;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_ext_cpu_code_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_ext_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_ext_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.cpu_code_en = value;
	ret = jhppe_enq_ctrl_ext_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_ext_drop_cpu_code_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_ext_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_ext_get(dev_id, &reg_val);
	*value = reg_val.bf.drop_cpu_code;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_ext_drop_cpu_code_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_ext_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_ext_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.drop_cpu_code = value;
	ret = jhppe_enq_ctrl_ext_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_ext_mc_cpu_code_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_ext_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_ext_get(dev_id, &reg_val);
	*value = reg_val.bf.mc_cpu_code;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_ext_mc_cpu_code_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_ext_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_ext_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mc_cpu_code = value;
	ret = jhppe_enq_ctrl_ext_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_ext_rsv_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_ext_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_ext_get(dev_id, &reg_val);
	*value = reg_val.bf.rsv;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_ext_rsv_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_ext_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_ext_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.rsv = value;
	ret = jhppe_enq_ctrl_ext_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_enq_ctrl_ext_trap_cpu_code_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union enq_ctrl_ext_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_ext_get(dev_id, &reg_val);
	*value = reg_val.bf.trap_cpu_code;
	return ret;
}

sw_error_t
jhppe_enq_ctrl_ext_trap_cpu_code_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union enq_ctrl_ext_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_enq_ctrl_ext_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.trap_cpu_code = value;
	ret = jhppe_enq_ctrl_ext_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_ucast_queue_map_rule_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_map_rule_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_QUEUE_MAP_RULE_TBL_ADDRESS + \
				index * UCAST_QUEUE_MAP_RULE_TBL_INC,
				value->val,
				sizeof(union ucast_queue_map_rule_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
jhppe_ucast_queue_map_rule_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_map_rule_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_QUEUE_MAP_RULE_TBL_ADDRESS + \
				index * UCAST_QUEUE_MAP_RULE_TBL_INC,
				value->val,
				sizeof(union ucast_queue_map_rule_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
jhppe_ucast_queue_map_action_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_map_action_tbl_u *value)
{
	if (index >= UCAST_QUEUE_MAP_ACTION_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_QUEUE_MAP_ACTION_TBL_ADDRESS + \
				index * UCAST_QUEUE_MAP_ACTION_TBL_INC,
				&value->val);
}

sw_error_t
jhppe_ucast_queue_map_action_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_map_action_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_QUEUE_MAP_ACTION_TBL_ADDRESS + \
				index * UCAST_QUEUE_MAP_ACTION_TBL_INC,
				value->val);
}

sw_error_t
jhppe_ucast_queue_ctrl_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_ctrl_tbl_u *value)
{
	if (index >= UCAST_QUEUE_CTRL_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_QUEUE_CTRL_TBL_ADDRESS + \
				index * UCAST_QUEUE_CTRL_TBL_INC,
				&value->val);
}

sw_error_t
jhppe_ucast_queue_ctrl_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_ctrl_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_QUEUE_CTRL_TBL_ADDRESS + \
				index * UCAST_QUEUE_CTRL_TBL_INC,
				value->val);
}

sw_error_t
jhppe_ucast_queue_ctrl_tbl_ddrq_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ucast_queue_ctrl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ucast_queue_ctrl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ddrq_en;
	return ret;
}

sw_error_t
jhppe_ucast_queue_ctrl_tbl_ddrq_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ucast_queue_ctrl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ucast_queue_ctrl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ddrq_en = value;
	ret = jhppe_ucast_queue_ctrl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_ucast_queue_ctrl_tbl_qid_mismatch_check_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ucast_queue_ctrl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ucast_queue_ctrl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.qid_mismatch_check_en;
	return ret;
}

sw_error_t
jhppe_ucast_queue_ctrl_tbl_qid_mismatch_check_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ucast_queue_ctrl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ucast_queue_ctrl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.qid_mismatch_check_en = value;
	ret = jhppe_ucast_queue_ctrl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p8_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P8_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P8_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p8_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p8_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P8_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P8_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p8_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_mul_p8_drop_byte_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union mul_p8_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_mul_p8_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.mul_p8_drop_byte_1 << 32 | \
		reg_val.bf.mul_p8_drop_byte_0;
	return ret;
}

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_mul_p8_drop_byte_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union mul_p8_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_mul_p8_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p8_drop_byte_1 = value >> 32;
	reg_val.bf.mul_p8_drop_byte_0 = value & (((a_uint64_t)1<<32)-1);
	ret = jhppe_mul_p8_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_mul_p8_drop_pkt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union mul_p8_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_mul_p8_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.mul_p8_drop_pkt;
	return ret;
}

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_mul_p8_drop_pkt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union mul_p8_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_mul_p8_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p8_drop_pkt = value;
	ret = jhppe_mul_p8_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

