/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _ADPT_APPE_POLICER_H_
#define _ADPT_APPE_POLICER_H_

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

#define APPE_POLICER_ID_MIN                  0
#define APPE_POLICER_ID_MAX                  511

sw_error_t
adpt_appe_policer_ctrl_set(a_uint32_t dev_id, fal_policer_ctrl_t *ctrl);

sw_error_t
adpt_appe_policer_ctrl_get(a_uint32_t dev_id, fal_policer_ctrl_t *ctrl);

#ifndef IN_POLICER_MINI
sw_error_t
adpt_appe_policer_priority_remap_get(a_uint32_t dev_id,
	fal_policer_priority_t *priority, fal_policer_remap_t *remap);

sw_error_t
adpt_appe_policer_priority_remap_set(a_uint32_t dev_id,
	fal_policer_priority_t *priority, fal_policer_remap_t *remap);
#endif
#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif
