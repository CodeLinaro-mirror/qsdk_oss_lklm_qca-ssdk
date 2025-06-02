/*
* Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
* SPDX-License-Identifier: ISC
*/

#ifndef _ADPT_JHPPE_PORTVLAN_
#define _ADPT_JHPPE_PORTVLAN_

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

sw_error_t
adpt_jhppe_vlan_trans_dscp_pcp_mapping_set(a_uint32_t dev_id, fal_port_vlan_direction_t direction,
		a_uint8_t group_id, a_uint8_t dscp, a_uint8_t pcp);
sw_error_t
adpt_jhppe_vlan_trans_dscp_pcp_mapping_get(a_uint32_t dev_id, fal_port_vlan_direction_t direction,
		a_uint8_t group_id, a_uint8_t dscp, a_uint8_t *pcp);
#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif
