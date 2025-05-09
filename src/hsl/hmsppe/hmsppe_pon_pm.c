/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#include "hsl_reg.h"

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_pm_counter_gen_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_PM_COUNTER_GEN_ADDRESS + \
				index * PRE_IPO_PM_COUNTER_GEN_INC,
				value->val,
				sizeof(union pre_ipo_pm_counter_gen_u)/sizeof(a_uint32_t));
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_pm_counter_gen_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				PRE_IPO_CSR_BASE_ADDR + PRE_IPO_PM_COUNTER_GEN_ADDRESS + \
				index * PRE_IPO_PM_COUNTER_GEN_INC,
				value->val,
				sizeof(union pre_ipo_pm_counter_gen_u)/sizeof(a_uint32_t));
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_counter_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.counter_id;
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_counter_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.counter_id = value;
	ret = hmsppe_pre_ipo_pm_counter_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_ipmc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ipmc;
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_ipmc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ipmc = value;
	ret = hmsppe_pre_ipo_pm_counter_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_pcp_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.pcp;
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_pcp_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pcp = value;
	ret = hmsppe_pre_ipo_pm_counter_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_pcp_incl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.pcp_incl;
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_pcp_incl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pcp_incl = value;
	ret = hmsppe_pre_ipo_pm_counter_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_port_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port;
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_port_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port = value;
	ret = hmsppe_pre_ipo_pm_counter_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_port_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.port_type;
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_port_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.port_type = value;
	ret = hmsppe_pre_ipo_pm_counter_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_tag_fmt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.tag_fmt;
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_tag_fmt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tag_fmt = value;
	ret = hmsppe_pre_ipo_pm_counter_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_vid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.vid;
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_vid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.vid = value;
	ret = hmsppe_pre_ipo_pm_counter_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_vid_incl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.vid_incl;
	return ret;
}

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_vid_incl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union pre_ipo_pm_counter_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hmsppe_pre_ipo_pm_counter_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.vid_incl = value;
	ret = hmsppe_pre_ipo_pm_counter_gen_set(dev_id, index, &reg_val);
	return ret;
}

