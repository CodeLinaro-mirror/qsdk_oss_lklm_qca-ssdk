/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

/**
 * @defgroup
 * @{
 */

#include "hsl_reg.h"
#include "fal_portvlan.h"

sw_error_t
adpt_jhppe_vlan_trans_dscp_pcp_mapping_set(a_uint32_t dev_id, fal_port_vlan_direction_t direction,
		a_uint8_t group_id, a_uint8_t dscp, a_uint8_t pcp)
{
	sw_error_t rv = SW_OK;

	if (direction == FAL_PORT_VLAN_INGRESS || direction == FAL_PORT_VLAN_ALL) {
		switch(group_id) {
		case 0:
			rv = jhppe_in_vlan_dscp_pbit_map_tbl_pcp_0_set(dev_id, dscp, pcp);
			break;
		case 1:
			rv = jhppe_in_vlan_dscp_pbit_map_tbl_pcp_1_set(dev_id, dscp, pcp);
			break;
		default:
			rv = SW_NOT_SUPPORTED;
			break;
		}
	}

	SW_RTN_ON_ERROR(rv);

	if (direction == FAL_PORT_VLAN_EGRESS || direction == FAL_PORT_VLAN_ALL) {
		switch(group_id) {
		case 0:
			rv = jhppe_dscp_pbit_map_tbl_pcp_0_set(dev_id, dscp, pcp);
			break;
		case 1:
			rv = jhppe_dscp_pbit_map_tbl_pcp_1_set(dev_id, dscp, pcp);
			break;
		default:
			rv = SW_NOT_SUPPORTED;
			break;
		}
	}

	return rv;
}

sw_error_t
adpt_jhppe_vlan_trans_dscp_pcp_mapping_get(a_uint32_t dev_id, fal_port_vlan_direction_t direction,
		a_uint8_t group_id, a_uint8_t dscp, a_uint8_t *pcp)
{
	a_uint32_t val = 0;
	sw_error_t rv;

	if (direction == FAL_PORT_VLAN_INGRESS) {
		switch(group_id) {
		case 0:
			rv = jhppe_in_vlan_dscp_pbit_map_tbl_pcp_0_get(dev_id, dscp, &val);
			break;
		case 1:
			rv = jhppe_in_vlan_dscp_pbit_map_tbl_pcp_1_get(dev_id, dscp, &val);
			break;
		default:
			rv = SW_NOT_SUPPORTED;
			break;
		}
	} else if (direction == FAL_PORT_VLAN_EGRESS) {
		switch (group_id) {
		case 0:
			rv = jhppe_dscp_pbit_map_tbl_pcp_0_get(dev_id, dscp, &val);
			break;
		case 1:
			rv = jhppe_dscp_pbit_map_tbl_pcp_1_get(dev_id, dscp, &val);
			break;
		default:
			rv = SW_NOT_SUPPORTED;
			break;
		}
	} else {
		rv = SW_NOT_SUPPORTED;
	}

	*pcp = val;
	return rv;
}
