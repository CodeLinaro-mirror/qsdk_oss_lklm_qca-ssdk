/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _JHPPE_QM_API_H_
#define _JHPPE_QM_API_H_


sw_error_t
jhppe_mc_enq_ctrl_get(
		a_uint32_t dev_id,
		union mc_enq_ctrl_u *value);

sw_error_t
jhppe_mc_enq_ctrl_set(
		a_uint32_t dev_id,
		union mc_enq_ctrl_u *value);

sw_error_t
jhppe_mc_enq_ctrl_dot1p_pon_vp_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_mc_enq_ctrl_dot1p_pon_vp_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_mc_enq_ctrl_uc_enq_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_mc_enq_ctrl_uc_enq_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_mc_enq_ctrl_uc_port_id_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_mc_enq_ctrl_uc_port_id_set(
		a_uint32_t dev_id,
		unsigned int value);


sw_error_t
jhppe_enq_ctrl_get(
		a_uint32_t dev_id,
		union enq_ctrl_u *value);

sw_error_t
jhppe_enq_ctrl_set(
		a_uint32_t dev_id,
		union enq_ctrl_u *value);

sw_error_t
jhppe_enq_ctrl_pass_through0_direc_enq_dis_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through0_direc_enq_dis_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_eg_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_eg_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through0_src_profile_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through1_direc_enq_dis_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through1_direc_enq_dis_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_eg_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_eg_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through1_src_profile_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through2_direc_enq_dis_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through2_direc_enq_dis_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_eg_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_eg_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through2_src_profile_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through3_direc_enq_dis_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through3_direc_enq_dis_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_eg_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_eg_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_pass_through3_src_profile_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_qid_mismatch_enq_cpu_code_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_qid_mismatch_enq_cpu_code_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_queue_map_rule_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_queue_map_rule_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_uc_enq_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_uc_enq_en_set(
		a_uint32_t dev_id,
		unsigned int value);


sw_error_t
jhppe_enq_ctrl_ext_get(
		a_uint32_t dev_id,
		union enq_ctrl_ext_u *value);

sw_error_t
jhppe_enq_ctrl_ext_set(
		a_uint32_t dev_id,
		union enq_ctrl_ext_u *value);

sw_error_t
jhppe_enq_ctrl_ext_cpu_code_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_ext_cpu_code_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_ext_drop_cpu_code_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_ext_drop_cpu_code_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_ext_mc_cpu_code_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_ext_mc_cpu_code_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_ext_rsv_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_ext_rsv_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_enq_ctrl_ext_trap_cpu_code_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_enq_ctrl_ext_trap_cpu_code_set(
		a_uint32_t dev_id,
		unsigned int value);

#define UCAST_QUEUE_MAP_RULE_TBL_MAX_ENTRY	64

sw_error_t
jhppe_ucast_queue_map_rule_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_map_rule_tbl_u *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_map_rule_tbl_u *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_0_info_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_0_info_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_0_info_hi_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_0_info_hi_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_0_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_0_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_0_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_0_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_0_type_map_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_0_type_map_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_1_info_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_1_info_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_1_info_hi_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_1_info_hi_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_1_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_1_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_1_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_1_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_1_type_map_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_field_1_type_map_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_int_pri_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_int_pri_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_int_pri_incl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_int_pri_incl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_pass_through_map_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_pass_through_map_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_slice_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_slice_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_src_profile_map_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_src_profile_map_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_rule_tbl_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define UCAST_QUEUE_MAP_ACTION_TBL_MAX_ENTRY	64

sw_error_t
jhppe_ucast_queue_map_action_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_map_action_tbl_u *value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_map_action_tbl_u *value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_force_index_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_force_index_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_force_index_type_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_force_index_type_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_profile_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_profile_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_queue_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_queue_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_queue_map_base_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_queue_map_base_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_queueid_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_map_action_tbl_queueid_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define UCAST_QUEUE_CTRL_TBL_MAX_ENTRY	256

sw_error_t
jhppe_ucast_queue_ctrl_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_ctrl_tbl_u *value);

sw_error_t
jhppe_ucast_queue_ctrl_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_ctrl_tbl_u *value);

sw_error_t
jhppe_ucast_queue_ctrl_tbl_ddrq_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_ctrl_tbl_ddrq_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_ucast_queue_ctrl_tbl_qid_mismatch_check_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_ucast_queue_ctrl_tbl_qid_mismatch_check_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define MUL_P8_DROP_CNT_TBL_MAX_ENTRY	12

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p8_drop_cnt_tbl_u *value);

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p8_drop_cnt_tbl_u *value);

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_mul_p8_drop_byte_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value);

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_mul_p8_drop_byte_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value);

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_mul_p8_drop_pkt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_mul_p8_drop_cnt_tbl_mul_p8_drop_pkt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#endif
