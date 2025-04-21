/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HMSPPE_PON_PM_API_H_
#define _HMSPPE_PON_PM_API_H_

#define PRE_IPO_PM_COUNTER_GEN_MAX_ENTRY	32

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_pm_counter_gen_u *value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pre_ipo_pm_counter_gen_u *value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_counter_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_counter_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_ipmc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_ipmc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_pcp_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_pcp_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_pcp_incl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_pcp_incl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_port_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_port_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_port_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_port_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_tag_fmt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_tag_fmt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_vid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_vid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_vid_incl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hmsppe_pre_ipo_pm_counter_gen_vid_incl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#endif
