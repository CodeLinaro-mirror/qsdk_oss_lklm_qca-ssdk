/*
 * Copyright (c) 2016-2017, 2021, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */
#include "hsl_htt_reg.h"

sw_error_t
httppe_drop_cpu_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union drop_cpu_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + DROP_CPU_CNT_TBL_ADDRESS + \
				index * DROP_CPU_CNT_TBL_INC,
				value->val,
				sizeof(union drop_cpu_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_drop_cpu_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union drop_cpu_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				INGRESS_POLICER_BASE_ADDR + DROP_CPU_CNT_TBL_ADDRESS + \
				index * DROP_CPU_CNT_TBL_INC,
				value->val,
				sizeof(union drop_cpu_cnt_tbl_u)/sizeof(a_uint32_t));
}

