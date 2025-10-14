/*
* Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
* SPDX-License-Identifier: ISC
*/

/**
 * @defgroup
 * @{
 */
#ifndef _ADPT_HTTPPE_PORTCTRLH_
#define _ADPT_HTTPPE_PORTCTRLH_

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

sw_error_t
_adpt_httppe_xgmac_speed_set(a_uint32_t dev_id, a_uint32_t mac_id,
			     a_uint32_t mode, fal_port_speed_t speed);

sw_error_t
adpt_httppe_port_mtu_cfg_set(a_uint32_t dev_id, fal_port_t port_id,
	fal_mtu_cfg_t *mtu_cfg);
sw_error_t
adpt_httppe_port_mtu_cfg_get(a_uint32_t dev_id, fal_port_t port_id,
	fal_mtu_cfg_t *mtu_cfg);
#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif
