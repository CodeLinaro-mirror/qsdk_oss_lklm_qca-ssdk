/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#include "hsl_reg.h"

sw_error_t
jhppe_sawf_flow_statis_ctrl0_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl0_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL0_ADDRESS,
				value->val, sizeof(union sawf_flow_statis_ctrl0_u)/sizeof(a_uint32_t));
}

sw_error_t
jhppe_sawf_flow_statis_ctrl0_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl0_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL0_ADDRESS,
				value->val, sizeof(union sawf_flow_statis_ctrl0_u)/sizeof(a_uint32_t));
}

sw_error_t
jhppe_sawf_flow_statis_ctrl0_sample_time_sawf0_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl0_get(dev_id, &reg_val);
	*value = reg_val.bf.sample_time_sawf0;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl0_sample_time_sawf0_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl0_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.sample_time_sawf0 = value;
	ret = jhppe_sawf_flow_statis_ctrl0_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl0_sample_time_sawf1_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl0_get(dev_id, &reg_val);
	*value = reg_val.bf.sample_time_sawf1;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl0_sample_time_sawf1_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl0_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.sample_time_sawf1 = value;
	ret = jhppe_sawf_flow_statis_ctrl0_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl1_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl1_u *value)
{
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL1_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl1_current_time_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl1_get(dev_id, &reg_val);
	*value = reg_val.bf.current_time;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl2_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl2_u *value)
{
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL2_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl2_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl2_u *value)
{
	return hppe_reg_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL2_ADDRESS,
				value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl2_sawf0_done_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl2_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl2_get(dev_id, &reg_val);
	*value = reg_val.bf.sawf0_done;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl2_sawf0_done_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl2_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl2_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.sawf0_done = value;
	ret = jhppe_sawf_flow_statis_ctrl2_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl3_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl3_u *value)
{
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL3_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl3_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl3_u *value)
{
	return hppe_reg_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL3_ADDRESS,
				value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl3_burst_threshold_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl3_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl3_get(dev_id, &reg_val);
	*value = reg_val.bf.burst_threshold;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl3_burst_threshold_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl3_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl3_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.burst_threshold = value;
	ret = jhppe_sawf_flow_statis_ctrl3_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl4_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl4_u *value)
{
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL4_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl4_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl4_u *value)
{
	return hppe_reg_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL4_ADDRESS,
				value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl4_burst_short_intvl_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl4_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl4_get(dev_id, &reg_val);
	*value = reg_val.bf.burst_short_intvl;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl4_burst_short_intvl_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl4_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl4_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.burst_short_intvl = value;
	ret = jhppe_sawf_flow_statis_ctrl4_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl5_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl5_u *value)
{
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL5_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl5_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl5_u *value)
{
	return hppe_reg_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL5_ADDRESS,
				value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl5_burst_long_intvl_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl5_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl5_get(dev_id, &reg_val);
	*value = reg_val.bf.burst_long_intvl;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl5_burst_long_intvl_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl5_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl5_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.burst_long_intvl = value;
	ret = jhppe_sawf_flow_statis_ctrl5_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl6_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl6_u *value)
{
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL6_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl6_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl6_u *value)
{
	return hppe_reg_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL6_ADDRESS,
				value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl6_cycle_trigger_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl6_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl6_get(dev_id, &reg_val);
	*value = reg_val.bf.cycle_trigger_en;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl6_cycle_trigger_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl6_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl6_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.cycle_trigger_en = value;
	ret = jhppe_sawf_flow_statis_ctrl6_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl6_cycle_trigger_num_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl6_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl6_get(dev_id, &reg_val);
	*value = reg_val.bf.cycle_trigger_num;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl6_cycle_trigger_num_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl6_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl6_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.cycle_trigger_num = value;
	ret = jhppe_sawf_flow_statis_ctrl6_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl7_u *value)
{
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL7_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl7_u *value)
{
	return hppe_reg_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL7_ADDRESS,
				value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_clear_mode_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl7_get(dev_id, &reg_val);
	*value = reg_val.bf.clear_mode;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_clear_mode_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl7_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.clear_mode = value;
	ret = jhppe_sawf_flow_statis_ctrl7_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_cnt_mode_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl7_get(dev_id, &reg_val);
	*value = reg_val.bf.cnt_mode;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_cnt_mode_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl7_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.cnt_mode = value;
	ret = jhppe_sawf_flow_statis_ctrl7_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_comp_len_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl7_get(dev_id, &reg_val);
	*value = reg_val.bf.comp_len;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_comp_len_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl7_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.comp_len = value;
	ret = jhppe_sawf_flow_statis_ctrl7_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_iat_shift_bit_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl7_get(dev_id, &reg_val);
	*value = reg_val.bf.iat_shift_bit;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_iat_shift_bit_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl7_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.iat_shift_bit = value;
	ret = jhppe_sawf_flow_statis_ctrl7_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_overflow_ctrl_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl7_get(dev_id, &reg_val);
	*value = reg_val.bf.overflow_ctrl;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl7_overflow_ctrl_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl7_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.overflow_ctrl = value;
	ret = jhppe_sawf_flow_statis_ctrl7_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_state_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_state_u *value)
{
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_STATE_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_statis_state_bytes_id_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_state_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_state_get(dev_id, &reg_val);
	*value = reg_val.bf.bytes_id;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_state_sawf0_active0_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_state_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_state_get(dev_id, &reg_val);
	*value = reg_val.bf.sawf0_active0;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_state_sawf0_active1_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_state_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_state_get(dev_id, &reg_val);
	*value = reg_val.bf.sawf0_active1;
	return ret;
}

sw_error_t
jhppe_sawf_flow_block_map_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union sawf_flow_block_map_u *value)
{
	if (index >= SAWF_FLOW_BLOCK_MAP_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_BLOCK_MAP_ADDRESS + \
				index * SAWF_FLOW_BLOCK_MAP_INC,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_block_map_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union sawf_flow_block_map_u *value)
{
	return hppe_reg_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_BLOCK_MAP_ADDRESS + \
				index * SAWF_FLOW_BLOCK_MAP_INC,
				value->val);
}

sw_error_t
jhppe_sawf_flow_block_map_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union sawf_flow_block_map_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_block_map_get(dev_id, index, &reg_val);
	*value = reg_val.bf.valid;
	return ret;
}

sw_error_t
jhppe_sawf_flow_block_map_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union sawf_flow_block_map_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_block_map_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.valid = value;
	ret = jhppe_sawf_flow_block_map_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl8_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl8_u *value)
{
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL8_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl8_short_interval_time_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl8_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl8_get(dev_id, &reg_val);
	*value = reg_val.bf.short_interval_time;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl9_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl9_u *value)
{
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL9_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl9_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl9_u *value)
{
	return hppe_reg_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL9_ADDRESS,
				value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl9_sawf_done_miss_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl9_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl9_get(dev_id, &reg_val);
	*value = reg_val.bf.sawf_done_miss;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl9_sawf_done_miss_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl9_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl9_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.sawf_done_miss = value;
	ret = jhppe_sawf_flow_statis_ctrl9_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl10_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl10_u *value)
{
	return hppe_reg_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL10_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl10_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl10_u *value)
{
	return hppe_reg_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_STATIS_CTRL10_ADDRESS,
				value->val);
}

sw_error_t
jhppe_sawf_flow_statis_ctrl10_sawf1_done_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union sawf_flow_statis_ctrl10_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl10_get(dev_id, &reg_val);
	*value = reg_val.bf.sawf1_done;
	return ret;
}

sw_error_t
jhppe_sawf_flow_statis_ctrl10_sawf1_done_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union sawf_flow_statis_ctrl10_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_sawf_flow_statis_ctrl10_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.sawf1_done = value;
	ret = jhppe_sawf_flow_statis_ctrl10_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pm_counter_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + PM_COUNTER_TBL_ADDRESS + \
				index * PM_COUNTER_TBL_INC,
				value->val,
				sizeof(union pm_counter_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
jhppe_pm_counter_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pm_counter_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + PM_COUNTER_TBL_ADDRESS + \
				index * PM_COUNTER_TBL_INC,
				value->val,
				sizeof(union pm_counter_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
jhppe_pm_counter_tbl_bcast_packet_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.bcast_packet_1 << 24 | \
		reg_val.bf.bcast_packet_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_bcast_packet_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.bcast_packet_1 = value >> 24;
	reg_val.bf.bcast_packet_0 = value & (((a_uint64_t)1<<24)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_crc_error_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.crc_error_1 << 24 | \
		reg_val.bf.crc_error_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_crc_error_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.crc_error_1 = value >> 24;
	reg_val.bf.crc_error_0 = value & (((a_uint64_t)1<<24)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_1024_1518_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.frame_1024_1518_1 << 24 | \
		reg_val.bf.frame_1024_1518_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_1024_1518_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.frame_1024_1518_1 = value >> 24;
	reg_val.bf.frame_1024_1518_0 = value & (((a_uint64_t)1<<24)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_128_255_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.frame_128_255_1 << 24 | \
		reg_val.bf.frame_128_255_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_128_255_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.frame_128_255_1 = value >> 24;
	reg_val.bf.frame_128_255_0 = value & (((a_uint64_t)1<<24)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_256_511_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.frame_256_511_1 << 24 | \
		reg_val.bf.frame_256_511_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_256_511_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.frame_256_511_1 = value >> 24;
	reg_val.bf.frame_256_511_0 = value & (((a_uint64_t)1<<24)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_512_1023_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.frame_512_1023_1 << 24 | \
		reg_val.bf.frame_512_1023_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_512_1023_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.frame_512_1023_1 = value >> 24;
	reg_val.bf.frame_512_1023_0 = value & (((a_uint64_t)1<<24)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_64_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.frame_64_1 << 24 | \
		reg_val.bf.frame_64_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_64_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.frame_64_1 = value >> 24;
	reg_val.bf.frame_64_0 = value & (((a_uint64_t)1<<24)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_65_127_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.frame_65_127_1 << 24 | \
		reg_val.bf.frame_65_127_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_frame_65_127_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.frame_65_127_1 = value >> 24;
	reg_val.bf.frame_65_127_0 = value & (((a_uint64_t)1<<24)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_mcast_packet_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.mcast_packet_1 << 24 | \
		reg_val.bf.mcast_packet_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_mcast_packet_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mcast_packet_1 = value >> 24;
	reg_val.bf.mcast_packet_0 = value & (((a_uint64_t)1<<24)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_octets_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.octets_1 << 32 | \
		reg_val.bf.octets_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_octets_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.octets_1 = value >> 32;
	reg_val.bf.octets_0 = value & (((a_uint64_t)1<<32)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_oversize_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.oversize_1 << 24 | \
		reg_val.bf.oversize_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_oversize_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.oversize_1 = value >> 24;
	reg_val.bf.oversize_0 = value & (((a_uint64_t)1<<24)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_ucast_packet_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ucast_packet_1 << 24 | \
		reg_val.bf.ucast_packet_0;
	return ret;
}

sw_error_t
jhppe_pm_counter_tbl_ucast_packet_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pm_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_pm_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ucast_packet_1 = value >> 24;
	reg_val.bf.ucast_packet_0 = value & (((a_uint64_t)1<<24)-1);
	ret = jhppe_pm_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
jhppe_sawf_flow_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union sawf_flow_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_CNT_TBL_ADDRESS + \
				index * SAWF_FLOW_CNT_TBL_INC,
				value->val,
				sizeof(union sawf_flow_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
jhppe_sawf_flow_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union sawf_flow_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + SAWF_FLOW_CNT_TBL_ADDRESS + \
				index * SAWF_FLOW_CNT_TBL_INC,
				value->val,
				sizeof(union sawf_flow_cnt_tbl_u)/sizeof(a_uint32_t));
}

