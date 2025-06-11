/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

/**
 * @defgroup
 * @{
 */

#include "hsl_reg.h"

sw_error_t
adpt_jhppe_acl_dscp_pcp_mapping_set(a_uint32_t dev_id,
		a_uint8_t group_id, a_uint8_t dscp, a_uint8_t pcp)
{
	sw_error_t rv;

	switch(group_id) {
	case 0:
		rv = jhppe_l2_dscp_pbit_map_tbl_pcp_0_set(dev_id, dscp, pcp);
		break;
	case 1:
		rv = jhppe_l2_dscp_pbit_map_tbl_pcp_1_set(dev_id, dscp, pcp);
		break;
	default:
		rv = SW_NOT_SUPPORTED;
		break;
	}

	return rv;
}

sw_error_t
adpt_jhppe_acl_dscp_pcp_mapping_get(a_uint32_t dev_id,
		a_uint8_t group_id, a_uint8_t dscp, a_uint8_t *pcp)
{
	a_uint32_t val = 0;
	sw_error_t rv;

	switch(group_id) {
	case 0:
		rv = jhppe_l2_dscp_pbit_map_tbl_pcp_0_get(dev_id, dscp, &val);
		break;
	case 1:
		rv = jhppe_l2_dscp_pbit_map_tbl_pcp_1_get(dev_id, dscp, &val);
		break;
	default:
		rv = SW_NOT_SUPPORTED;
	}

	*pcp = val;

	return rv;
}
