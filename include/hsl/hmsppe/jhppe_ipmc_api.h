/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _JHPPE_IPMC_API_H_
#define _JHPPE_IPMC_API_H_


sw_error_t
jhppe_ipmc_convert_uc_ctrl_get(
		a_uint32_t dev_id,
		union ipmc_convert_uc_ctrl_u *value);

sw_error_t
jhppe_ipmc_convert_uc_ctrl_set(
		a_uint32_t dev_id,
		union ipmc_convert_uc_ctrl_u *value);

sw_error_t
jhppe_ipmc_convert_uc_ctrl_convert_port_vp_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_ipmc_convert_uc_ctrl_convert_port_vp_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_ipmc_convert_uc_ctrl_enable_port_num_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_ipmc_convert_uc_ctrl_enable_port_num_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_ipmc_convert_uc_ctrl_post_bypass_bitmap_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_ipmc_convert_uc_ctrl_post_bypass_bitmap_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_ipmc_convert_uc_ctrl_service_code_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_ipmc_convert_uc_ctrl_service_code_set(
		a_uint32_t dev_id,
		unsigned int value);

#endif
