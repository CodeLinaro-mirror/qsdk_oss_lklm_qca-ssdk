/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2021-2023, 2025 Qualcomm Innovation Center, Inc. All rights reserved.
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
/**
 * @defgroup
 * @{
 */
#include "hsl_reg.h"

sw_error_t
appe_ipr_udf_ctrl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_ctrl_u *value)
{
	if (index >= IPR_UDF_CTRL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_CTRL_ADDRESS + \
				index * IPR_UDF_CTRL_INC,
				&value->val);
}

sw_error_t
appe_ipr_udf_ctrl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_ctrl_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_CTRL_ADDRESS + \
				index * IPR_UDF_CTRL_INC,
				value->val);
}

sw_error_t
appe_ipr_udf_profile_base_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_profile_base_u *value)
{
	if (index >= IPR_UDF_PROFILE_BASE_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_PROFILE_BASE_ADDRESS + \
				index * IPR_UDF_PROFILE_BASE_INC,
				&value->val);
}

sw_error_t
appe_ipr_udf_profile_base_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_profile_base_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_PROFILE_BASE_ADDRESS + \
				index * IPR_UDF_PROFILE_BASE_INC,
				value->val);
}

sw_error_t
appe_ipr_udf_profile_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_profile_offset_u *value)
{
	if (index >= IPR_UDF_PROFILE_OFFSET_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_PROFILE_OFFSET_ADDRESS + \
				index * IPR_UDF_PROFILE_OFFSET_INC,
				&value->val);
}

sw_error_t
appe_ipr_udf_profile_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_profile_offset_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_PROFILE_OFFSET_ADDRESS + \
				index * IPR_UDF_PROFILE_OFFSET_INC,
				value->val);
}

sw_error_t
appe_eg_ipo_ext_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union eg_ipo_ext_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_IPO_EXT_TBL_ADDRESS + \
				index * EG_IPO_EXT_TBL_INC,
				value->val,
				sizeof(union eg_ipo_ext_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
appe_eg_ipo_ext_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union eg_ipo_ext_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + EG_IPO_EXT_TBL_ADDRESS + \
				index * EG_IPO_EXT_TBL_INC,
				value->val,
				sizeof(union eg_ipo_ext_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
appe_pre_ipo_rule_reg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_rule_reg_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_RULE_REG_ADDRESS + \
				index * PRE_IPO_RULE_REG_INC,
				value->val,
				3);
}

sw_error_t
appe_pre_ipo_rule_reg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_rule_reg_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_RULE_REG_ADDRESS + \
				index * PRE_IPO_RULE_REG_INC,
				value->val,
				3);
}

sw_error_t
appe_pre_ipo_mask_reg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_mask_reg_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_MASK_REG_ADDRESS + \
				index * PRE_IPO_MASK_REG_INC,
				value->val,
				2);
}

sw_error_t
appe_pre_ipo_mask_reg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_mask_reg_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_MASK_REG_ADDRESS + \
				index * PRE_IPO_MASK_REG_INC,
				value->val,
				2);
}

sw_error_t
appe_pre_ipo_rule_ext_1_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_rule_ext_1_u *value)
{
	if (index >= PRE_IPO_RULE_EXT_1_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_RULE_EXT_1_ADDRESS + \
				index * PRE_IPO_RULE_EXT_1_INC,
				&value->val);
}

sw_error_t
appe_pre_ipo_rule_ext_1_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_rule_ext_1_u *value)
{
	return hppe_reg_set(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_RULE_EXT_1_ADDRESS + \
				index * PRE_IPO_RULE_EXT_1_INC,
				value->val);
}

sw_error_t
appe_pre_ipo_rule_ext_2_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_rule_ext_2_u *value)
{
	if (index >= PRE_IPO_RULE_EXT_2_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_RULE_EXT_2_ADDRESS + \
				index * PRE_IPO_RULE_EXT_2_INC,
				&value->val);
}

sw_error_t
appe_pre_ipo_rule_ext_2_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_rule_ext_2_u *value)
{
	return hppe_reg_set(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_RULE_EXT_2_ADDRESS + \
				index * PRE_IPO_RULE_EXT_2_INC,
				value->val);
}

sw_error_t
appe_pre_ipo_rule_ext_4_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_rule_ext_4_u *value)
{
	if (index >= PRE_IPO_RULE_EXT_4_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_RULE_EXT_4_ADDRESS + \
				index * PRE_IPO_RULE_EXT_4_INC,
				&value->val);
}

sw_error_t
appe_pre_ipo_rule_ext_4_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_rule_ext_4_u *value)
{
	return hppe_reg_set(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_RULE_EXT_4_ADDRESS + \
				index * PRE_IPO_RULE_EXT_4_INC,
				value->val);
}

sw_error_t
appe_pre_ipo_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + PRE_IPO_CNT_TBL_ADDRESS + \
				index * PRE_IPO_CNT_TBL_INC,
				value->val,
				sizeof(union pre_ipo_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
appe_pre_ipo_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + PRE_IPO_CNT_TBL_ADDRESS + \
				index * PRE_IPO_CNT_TBL_INC,
				value->val,
				sizeof(union pre_ipo_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
appe_pre_ipo_action_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_action_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_ACTION_ADDRESS + \
				index * PRE_IPO_ACTION_INC,
				value->val,
				sizeof(union pre_ipo_action_u)/sizeof(a_uint32_t));
}

sw_error_t
appe_pre_ipo_action_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_action_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_ACTION_ADDRESS + \
				index * PRE_IPO_ACTION_INC,
				value->val,
				sizeof(union pre_ipo_action_u)/sizeof(a_uint32_t));
}

sw_error_t
appe_pre_ipo_cnt_tbl_hit_byte_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union pre_ipo_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_pre_ipo_cnt_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.hit_byte_cnt_1 << 32 | \
		reg_val.bf.hit_byte_cnt_0;
	return ret;
}

sw_error_t
appe_pre_ipo_cnt_tbl_hit_byte_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union pre_ipo_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_pre_ipo_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.hit_byte_cnt_1 = value >> 32;
	reg_val.bf.hit_byte_cnt_0 = value & (((a_uint64_t)1<<32)-1);
	ret = appe_pre_ipo_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_pre_ipo_cnt_tbl_hit_pkt_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pre_ipo_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_pre_ipo_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.hit_pkt_cnt;
	return ret;
}

sw_error_t
appe_pre_ipo_cnt_tbl_hit_pkt_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pre_ipo_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_pre_ipo_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.hit_pkt_cnt = value;
	ret = appe_pre_ipo_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

