/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */
#include "hsl_htt_reg.h"

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
httppe_eg_bridge_config_bridge_type_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_bridge_config_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_bridge_config_get(dev_id, &reg_val);
	*value = reg_val.bf.bridge_type;
	return ret;
}

sw_error_t
httppe_eg_bridge_config_bridge_type_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_bridge_config_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_bridge_config_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.bridge_type = value;
	ret = httppe_eg_bridge_config_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_bridge_config_passthrough_cpu_code0_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_bridge_config_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_bridge_config_get(dev_id, &reg_val);
	*value = reg_val.bf.passthrough_cpu_code0;
	return ret;
}

sw_error_t
httppe_eg_bridge_config_passthrough_cpu_code0_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_bridge_config_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_bridge_config_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.passthrough_cpu_code0 = value;
	ret = httppe_eg_bridge_config_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_bridge_config_passthrough_cpu_code1_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_bridge_config_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_bridge_config_get(dev_id, &reg_val);
	*value = reg_val.bf.passthrough_cpu_code1;
	return ret;
}

sw_error_t
httppe_eg_bridge_config_passthrough_cpu_code1_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_bridge_config_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_bridge_config_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.passthrough_cpu_code1 = value;
	ret = httppe_eg_bridge_config_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_bridge_config_pkt_l2_edit_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_bridge_config_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_bridge_config_get(dev_id, &reg_val);
	*value = reg_val.bf.pkt_l2_edit_en;
	return ret;
}

sw_error_t
httppe_eg_bridge_config_pkt_l2_edit_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_bridge_config_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_bridge_config_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pkt_l2_edit_en = value;
	ret = httppe_eg_bridge_config_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
httppe_eg_bridge_config_queue_cnt_en_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_bridge_config_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_bridge_config_get(dev_id, &reg_val);
	*value = reg_val.bf.queue_cnt_en;
	return ret;
}

sw_error_t
httppe_eg_bridge_config_queue_cnt_en_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_bridge_config_u reg_val;
	sw_error_t ret = SW_OK;

	ret = httppe_eg_bridge_config_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.queue_cnt_en = value;
	ret = httppe_eg_bridge_config_set(dev_id, &reg_val);
	return ret;
}

