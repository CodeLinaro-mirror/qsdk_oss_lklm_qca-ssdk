/*
* Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
* SPDX-License-Identifier: ISC
*/

/**
 * @defgroup
 * @{
 */
#ifndef _ADPT_HTTPPE_QOS_H_
#define _ADPT_HTTPPE_QOS_H_

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

sw_error_t
adpt_httppe_l1_flow_map_set(a_uint32_t dev_id,
			    a_uint32_t node_id,
			    fal_port_t port_id,
			    fal_qos_scheduler_cfg_t *scheduler_cfg);

sw_error_t
adpt_httppe_l1_flow_map_get(a_uint32_t dev_id,
			    a_uint32_t node_id,
			    fal_port_t *port_id,
			    fal_qos_scheduler_cfg_t *scheduler_cfg);
sw_error_t
adpt_httppe_l0_queue_map_set(a_uint32_t dev_id,
			     a_uint32_t node_id,
			     fal_port_t port_id,
			     fal_qos_scheduler_cfg_t *scheduler_cfg);
sw_error_t
adpt_httppe_l0_queue_map_get(a_uint32_t dev_id,
			     a_uint32_t node_id,
			     fal_port_t *port_id,
			     fal_qos_scheduler_cfg_t *scheduler_cfg);
sw_error_t
adpt_httppe_tdm_tick_num_set(a_uint32_t dev_id, a_uint32_t tick_num);

sw_error_t
adpt_httppe_port_scheduler_cfg_set(a_uint32_t dev_id,
				   a_uint32_t tick_index,
				   fal_port_scheduler_cfg_t *cfg);

sw_error_t
adpt_httppe_qos_cosmap_dscp_get(a_uint32_t dev_id, a_uint8_t group_id,
			a_uint8_t dscp,
			fal_qos_cosmap_t *cosmap);

sw_error_t
adpt_httppe_qos_cosmap_dscp_set(a_uint32_t dev_id, a_uint8_t group_id,
			a_uint8_t dscp,
			fal_qos_cosmap_t *cosmap);
#ifndef IN_QOS_MINI
sw_error_t
adpt_httppe_port_queues_get(a_uint32_t dev_id,
			    fal_port_t port_id,
			    fal_queue_bmp_t *queue_bmp);
sw_error_t
adpt_httppe_tdm_tick_num_get(a_uint32_t dev_id, a_uint32_t *tick_num);

sw_error_t
adpt_httppe_port_scheduler_cfg_get(a_uint32_t dev_id,
				   a_uint32_t tick_index,
				   fal_port_scheduler_cfg_t *cfg);

sw_error_t
adpt_httppe_qos_cosmap_pcp_get(a_uint32_t dev_id, a_uint8_t group_id,
			a_uint8_t pcp,
			fal_qos_cosmap_t *cosmap);

sw_error_t
adpt_httppe_qos_cosmap_pcp_set(a_uint32_t dev_id, a_uint8_t group_id,
			a_uint8_t pcp,
			fal_qos_cosmap_t *cosmap);
#endif
#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif
