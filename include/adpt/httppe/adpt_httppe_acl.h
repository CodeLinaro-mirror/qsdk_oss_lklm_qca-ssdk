/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */


/**
 * @defgroup
 * @{
 */
#ifndef _ADPT_HTTPPE_ACL_H_
#define _ADPT_HTTPPE_ACL_H_

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

sw_error_t
_adpt_httppe_acl_rule_hw_add(a_uint32_t dev_id, a_uint32_t list_pri,
		a_uint32_t hw_list_id, a_uint32_t rule_id, a_uint32_t rule_nr,
		fal_acl_rule_t *rule, ADPT_HPPE_ACL_RULE_MAP *rule_map,
		a_uint32_t allocated_entries);

sw_error_t
_adpt_httppe_acl_rule_sw_query(a_uint32_t dev_id,
		a_uint32_t hw_list_id, a_uint32_t hw_entries, fal_acl_rule_t *rule);

sw_error_t
_adpt_httppe_acl_rule_hw_delete(a_uint32_t dev_id,
		a_uint32_t hw_list_id, a_uint32_t hw_entries, a_uint32_t rule_nr);

sw_error_t
_adpt_httppe_acl_rule_dump(a_uint32_t dev_id, a_uint32_t hw_list_id, a_uint32_t hw_entries);

sw_error_t
_adpt_httppe_acl_rule_bind(a_uint32_t dev_id, a_uint32_t hw_list_id, a_uint32_t hw_entries,
		fal_acl_direc_t direc, fal_acl_bind_obj_t obj_t, a_uint32_t obj_idx);

sw_error_t
_adpt_httppe_acl_rule_unbind(a_uint32_t dev_id, a_uint32_t hw_list_id, a_uint32_t hw_entries,
		fal_acl_direc_t direc, fal_acl_bind_obj_t obj_t, a_uint32_t obj_idx);

sw_error_t
_adpt_httppe_acl_rule_priority_set(a_uint32_t dev_id, a_uint32_t hw_list_id,
		a_uint32_t hw_entries, a_uint32_t priority);

sw_error_t
_adpt_httppe_acl_rule_priority_get(a_uint32_t dev_id, a_uint32_t hw_list_id,
		a_uint32_t hw_entries, a_uint32_t *priority);
#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif
/**
 * @}
 */
