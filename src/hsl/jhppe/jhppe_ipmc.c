/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#include "hsl_reg.h"

sw_error_t
jhppe_ipmc_convert_uc_ctrl_get(
		a_uint32_t dev_id,
		union ipmc_convert_uc_ctrl_u *value)
{
	return hppe_reg_get(
				dev_id,
				IPE_L2_BASE_ADDR + IPMC_CONVERT_UC_CTRL_ADDRESS,
				&value->val);
}

sw_error_t
jhppe_ipmc_convert_uc_ctrl_set(
		a_uint32_t dev_id,
		union ipmc_convert_uc_ctrl_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPE_L2_BASE_ADDR + IPMC_CONVERT_UC_CTRL_ADDRESS,
				value->val);
}

sw_error_t
jhppe_ipmc_convert_uc_ctrl_convert_port_vp_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union ipmc_convert_uc_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ipmc_convert_uc_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.convert_port_vp;
	return ret;
}

sw_error_t
jhppe_ipmc_convert_uc_ctrl_convert_port_vp_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union ipmc_convert_uc_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ipmc_convert_uc_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.convert_port_vp = value;
	ret = jhppe_ipmc_convert_uc_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_ipmc_convert_uc_ctrl_enable_port_num_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union ipmc_convert_uc_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ipmc_convert_uc_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.enable_port_num;
	return ret;
}

sw_error_t
jhppe_ipmc_convert_uc_ctrl_enable_port_num_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union ipmc_convert_uc_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ipmc_convert_uc_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.enable_port_num = value;
	ret = jhppe_ipmc_convert_uc_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_ipmc_convert_uc_ctrl_post_bypass_bitmap_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union ipmc_convert_uc_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ipmc_convert_uc_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.post_bypass_bitmap;
	return ret;
}

sw_error_t
jhppe_ipmc_convert_uc_ctrl_post_bypass_bitmap_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union ipmc_convert_uc_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ipmc_convert_uc_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.post_bypass_bitmap = value;
	ret = jhppe_ipmc_convert_uc_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
jhppe_ipmc_convert_uc_ctrl_service_code_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union ipmc_convert_uc_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ipmc_convert_uc_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.service_code;
	return ret;
}

sw_error_t
jhppe_ipmc_convert_uc_ctrl_service_code_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union ipmc_convert_uc_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = jhppe_ipmc_convert_uc_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.service_code = value;
	ret = jhppe_ipmc_convert_uc_ctrl_set(dev_id, &reg_val);
	return ret;
}

