/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */
#include "hsl_htt_reg.h"

sw_error_t
httppe_vsi_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union vsi_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				IPE_L2_BASE_ADDR + VSI_TBL_ADDRESS + \
				index * VSI_TBL_INC,
				value->val,
				sizeof(union vsi_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
httppe_vsi_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union vsi_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				IPE_L2_BASE_ADDR + VSI_TBL_ADDRESS + \
				index * VSI_TBL_INC,
				value->val,
				sizeof(union vsi_tbl_u)/sizeof(a_uint32_t));
}

