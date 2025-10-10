/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HTTPPE_PORTVLAN_API_H_
#define _HTTPPE_PORTVLAN_API_H_


sw_error_t
httppe_eg_bridge_config_get(
		a_uint32_t dev_id,
		union eg_bridge_config_u *value);

sw_error_t
httppe_eg_bridge_config_set(
		a_uint32_t dev_id,
		union eg_bridge_config_u *value);

sw_error_t
httppe_eg_bridge_config_bridge_type_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
httppe_eg_bridge_config_bridge_type_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
httppe_eg_bridge_config_field_update_enable_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
httppe_eg_bridge_config_field_update_enable_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
httppe_eg_bridge_config_passthrough_cpu_code0_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
httppe_eg_bridge_config_passthrough_cpu_code0_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
httppe_eg_bridge_config_passthrough_cpu_code1_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
httppe_eg_bridge_config_passthrough_cpu_code1_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
httppe_eg_bridge_config_pkt_l2_edit_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
httppe_eg_bridge_config_pkt_l2_edit_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
httppe_eg_bridge_config_ppe_eip_rsv_w4_3130_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
httppe_eg_bridge_config_ppe_eip_rsv_w4_3130_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
httppe_eg_bridge_config_queue_cnt_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
httppe_eg_bridge_config_queue_cnt_en_set(
		a_uint32_t dev_id,
		unsigned int value);

#endif
