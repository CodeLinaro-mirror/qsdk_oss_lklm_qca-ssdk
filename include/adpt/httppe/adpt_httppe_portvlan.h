/*
* Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
* SPDX-License-Identifier: ISC
*/

#ifndef _ADPT_HTTPPE_PORTVLAN_
#define _ADPT_HTTPPE_PORTVLAN_

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

sw_error_t
adpt_httppe_port_qinq_mode_set(a_uint32_t dev_id, fal_port_t port_id, fal_port_qinq_role_t *mode);

sw_error_t
adpt_httppe_port_qinq_mode_get(a_uint32_t dev_id, fal_port_t port_id, fal_port_qinq_role_t *mode);

sw_error_t
adpt_httppe_tpid_set(a_uint32_t dev_id, fal_tpid_t *tpid);

sw_error_t
adpt_httppe_tpid_get(a_uint32_t dev_id, fal_tpid_t *tpid);

sw_error_t
adpt_httppe_egress_tpid_set(a_uint32_t dev_id, fal_tpid_t *tpid);

sw_error_t
adpt_httppe_egress_tpid_get(a_uint32_t dev_id, fal_tpid_t *tpid);

sw_error_t
adpt_httppe_port_vlan_trans_adv_add(a_uint32_t dev_id,
		fal_port_t port_id, fal_port_vlan_direction_t direction,
		fal_vlan_trans_adv_rule_t * rule, fal_vlan_trans_adv_action_t * action);

sw_error_t
adpt_httppe_port_vlan_trans_adv_del(a_uint32_t dev_id,
		fal_port_t port_id, fal_port_vlan_direction_t direction,
		fal_vlan_trans_adv_rule_t * rule, fal_vlan_trans_adv_action_t * action);

sw_error_t
adpt_httppe_port_vlan_trans_adv_get(a_uint32_t dev_id,
		fal_port_vlan_direction_t direction, a_uint32_t index,
		fal_vlan_trans_adv_rule_t *rule, fal_vlan_trans_adv_action_t *action);

sw_error_t
adpt_httppe_port_vlan_trans_adv_set(a_uint32_t dev_id,
		fal_port_vlan_direction_t direction, a_uint32_t index,
		fal_vlan_trans_adv_rule_t *rule, fal_vlan_trans_adv_action_t *action);

sw_error_t
adpt_httppe_port_vlan_trans_adv_getfirst(a_uint32_t dev_id,
		fal_port_t port_id, fal_port_vlan_direction_t direction,
		fal_vlan_trans_adv_rule_t * rule, fal_vlan_trans_adv_action_t * action);

sw_error_t
adpt_httppe_port_vlan_trans_adv_getnext(a_uint32_t dev_id,
		fal_port_t port_id, fal_port_vlan_direction_t direction,
		fal_vlan_trans_adv_rule_t * rule, fal_vlan_trans_adv_action_t * action);

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif
