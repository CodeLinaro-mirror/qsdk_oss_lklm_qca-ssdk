/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#include "hsl_htt_reg.h"

sw_error_t
httppe_ipo_rule_reg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipo_rule_reg_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				IPO_CSR_BASE_ADDR + IPO_RULE_REG_ADDRESS + \
				index * IPO_RULE_REG_INC,
				value->val,
				3);
}

sw_error_t
httppe_ipo_rule_reg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipo_rule_reg_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				IPO_CSR_BASE_ADDR + IPO_RULE_REG_ADDRESS + \
				index * IPO_RULE_REG_INC,
				value->val,
				3);
}

sw_error_t
httppe_ipo_mask_reg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipo_mask_reg_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				IPO_CSR_BASE_ADDR + IPO_MASK_REG_ADDRESS + \
				index * IPO_MASK_REG_INC,
				value->val,
				2);
}

sw_error_t
httppe_ipo_mask_reg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipo_mask_reg_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				IPO_CSR_BASE_ADDR + IPO_MASK_REG_ADDRESS + \
				index * IPO_MASK_REG_INC,
				value->val,
				2);
}

sw_error_t
httppe_ipo_action_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipo_action_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				IPE_L2_BASE_ADDR + IPO_ACTION_ADDRESS + \
				index * IPO_ACTION_INC,
				value->val,
				sizeof(union ipo_action_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_ipo_action_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipo_action_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				IPE_L2_BASE_ADDR + IPO_ACTION_ADDRESS + \
				index * IPO_ACTION_INC,
				value->val,
				sizeof(union ipo_action_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_ipo_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipo_cnt_tbl_u *value)
{
		return hppe_reg_tbl_get(
					dev_id,
					INGRESS_POLICER_BASE_ADDR + IPO_CNT_TBL_ADDRESS + \
					index * IPO_CNT_TBL_INC,
					value->val,
					sizeof(union ipo_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_ipo_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipo_cnt_tbl_u *value)
{
		return hppe_reg_tbl_set(
					dev_id,
					INGRESS_POLICER_BASE_ADDR + IPO_CNT_TBL_ADDRESS + \
					index * IPO_CNT_TBL_INC,
					value->val,
					sizeof(union ipo_cnt_tbl_u)/sizeof(a_uint32_t));
}
