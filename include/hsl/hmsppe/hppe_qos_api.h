/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HPPE_QOS_API_H_
#define _HPPE_QOS_API_H_


sw_error_t
hppe_tdm_depth_cfg_get(
		a_uint32_t dev_id,
		union tdm_depth_cfg_u *value);

sw_error_t
hppe_tdm_depth_cfg_set(
		a_uint32_t dev_id,
		union tdm_depth_cfg_u *value);

#define L0_FLOW_MAP_TBL_MAX_ENTRY	300

sw_error_t
hppe_l0_flow_map_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_flow_map_tbl_u *value);

sw_error_t
hppe_l0_flow_map_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_flow_map_tbl_u *value);

sw_error_t
hppe_l0_flow_map_tbl_c_drr_credit_unit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_map_tbl_c_drr_credit_unit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_flow_map_tbl_c_drr_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_map_tbl_c_drr_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_flow_map_tbl_c_drr_wt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_map_tbl_c_drr_wt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_flow_map_tbl_c_pri_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_map_tbl_c_pri_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_flow_map_tbl_e_drr_credit_unit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_map_tbl_e_drr_credit_unit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_flow_map_tbl_e_drr_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_map_tbl_e_drr_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_flow_map_tbl_e_drr_wt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_map_tbl_e_drr_wt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_flow_map_tbl_e_pri_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_map_tbl_e_pri_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_flow_map_tbl_sp_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_map_tbl_sp_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L0_FLOW_PORT_MAP_TBL_MAX_ENTRY	300

sw_error_t
hppe_l0_flow_port_map_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_flow_port_map_tbl_u *value);

sw_error_t
hppe_l0_flow_port_map_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_flow_port_map_tbl_u *value);

#define L0_C_DRR_HEAD_TBL_MAX_ENTRY	256

sw_error_t
hppe_l0_c_drr_head_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_c_drr_head_tbl_u *value);

sw_error_t
hppe_l0_c_drr_head_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_c_drr_head_tbl_u *value);

sw_error_t
hppe_l0_c_drr_head_tbl_active_head_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_c_drr_head_tbl_active_head_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_c_drr_head_tbl_active_max_n_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_c_drr_head_tbl_active_max_n_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_c_drr_head_tbl_active_tail_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_c_drr_head_tbl_active_tail_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_c_drr_head_tbl_active_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_c_drr_head_tbl_active_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_c_drr_head_tbl_backup_head_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_c_drr_head_tbl_backup_head_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_c_drr_head_tbl_backup_max_n_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_c_drr_head_tbl_backup_max_n_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_c_drr_head_tbl_backup_tail_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_c_drr_head_tbl_backup_tail_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_c_drr_head_tbl_backup_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_c_drr_head_tbl_backup_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L0_E_DRR_HEAD_TBL_MAX_ENTRY	256

sw_error_t
hppe_l0_e_drr_head_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_e_drr_head_tbl_u *value);

sw_error_t
hppe_l0_e_drr_head_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_e_drr_head_tbl_u *value);

sw_error_t
hppe_l0_e_drr_head_tbl_active_head_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_e_drr_head_tbl_active_head_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_e_drr_head_tbl_active_max_n_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_e_drr_head_tbl_active_max_n_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_e_drr_head_tbl_active_tail_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_e_drr_head_tbl_active_tail_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_e_drr_head_tbl_active_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_e_drr_head_tbl_active_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_e_drr_head_tbl_backup_head_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_e_drr_head_tbl_backup_head_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_e_drr_head_tbl_backup_max_n_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_e_drr_head_tbl_backup_max_n_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_e_drr_head_tbl_backup_tail_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_e_drr_head_tbl_backup_tail_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_e_drr_head_tbl_backup_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_e_drr_head_tbl_backup_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L0_DRR_CREDIT_TBL_MAX_ENTRY	300

sw_error_t
hppe_l0_drr_credit_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_drr_credit_tbl_u *value);

sw_error_t
hppe_l0_drr_credit_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_drr_credit_tbl_u *value);

sw_error_t
hppe_l0_drr_credit_tbl_c_drr_credit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_drr_credit_tbl_c_drr_credit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_drr_credit_tbl_c_drr_credit_neg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_drr_credit_tbl_c_drr_credit_neg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_drr_credit_tbl_e_drr_credit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_drr_credit_tbl_e_drr_credit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_drr_credit_tbl_e_drr_credit_neg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_drr_credit_tbl_e_drr_credit_neg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L0_C_DRR_LL_TBL_MAX_ENTRY	300

sw_error_t
hppe_l0_c_drr_ll_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_c_drr_ll_tbl_u *value);

sw_error_t
hppe_l0_c_drr_ll_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_c_drr_ll_tbl_u *value);

#define L0_C_DRR_REVERSE_LL_TBL_MAX_ENTRY	300

sw_error_t
hppe_l0_c_drr_reverse_ll_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_c_drr_reverse_ll_tbl_u *value);

sw_error_t
hppe_l0_c_drr_reverse_ll_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_c_drr_reverse_ll_tbl_u *value);

#define L0_E_DRR_LL_TBL_MAX_ENTRY	300

sw_error_t
hppe_l0_e_drr_ll_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_e_drr_ll_tbl_u *value);

sw_error_t
hppe_l0_e_drr_ll_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_e_drr_ll_tbl_u *value);

#define L0_E_DRR_REVERSE_LL_TBL_MAX_ENTRY	300

sw_error_t
hppe_l0_e_drr_reverse_ll_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_e_drr_reverse_ll_tbl_u *value);

sw_error_t
hppe_l0_e_drr_reverse_ll_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_e_drr_reverse_ll_tbl_u *value);

#define L0_SP_ENTRY_TBL_MAX_ENTRY	64

sw_error_t
hppe_l0_sp_entry_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_sp_entry_tbl_u *value);

sw_error_t
hppe_l0_sp_entry_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_sp_entry_tbl_u *value);

sw_error_t
hppe_l0_sp_entry_tbl_entry_path_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value);

sw_error_t
hppe_l0_sp_entry_tbl_entry_path_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value);

sw_error_t
hppe_l0_sp_entry_tbl_entry_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_sp_entry_tbl_entry_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L0_ENS_Q_LL_TBL_MAX_ENTRY	300

sw_error_t
hppe_l0_ens_q_ll_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_ens_q_ll_tbl_u *value);

sw_error_t
hppe_l0_ens_q_ll_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_ens_q_ll_tbl_u *value);

#define L0_ENS_Q_HEAD_TBL_MAX_ENTRY	9

sw_error_t
hppe_l0_ens_q_head_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_ens_q_head_tbl_u *value);

sw_error_t
hppe_l0_ens_q_head_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_ens_q_head_tbl_u *value);

sw_error_t
hppe_l0_ens_q_head_tbl_head_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_ens_q_head_tbl_head_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_ens_q_head_tbl_tail_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_ens_q_head_tbl_tail_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_ens_q_head_tbl_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_ens_q_head_tbl_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L0_ENS_Q_ENTRY_TBL_MAX_ENTRY	300

sw_error_t
hppe_l0_ens_q_entry_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_ens_q_entry_tbl_u *value);

sw_error_t
hppe_l0_ens_q_entry_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_ens_q_entry_tbl_u *value);

sw_error_t
hppe_l0_ens_q_entry_tbl_entry_ens_in_q_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_ens_q_entry_tbl_entry_ens_in_q_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_ens_q_entry_tbl_entry_ens_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_ens_q_entry_tbl_entry_ens_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_ens_q_entry_tbl_entry_ens_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_ens_q_entry_tbl_entry_ens_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L0_FLOW_STATUS_TBL_MAX_ENTRY	300

sw_error_t
hppe_l0_flow_status_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_flow_status_tbl_u *value);

sw_error_t
hppe_l0_flow_status_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l0_flow_status_tbl_u *value);

sw_error_t
hppe_l0_flow_status_tbl_en_cdrr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_status_tbl_en_cdrr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_flow_status_tbl_en_edrr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_status_tbl_en_edrr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l0_flow_status_tbl_en_level_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l0_flow_status_tbl_en_level_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define RFC_BLOCK_TBL_MAX_ENTRY	300

sw_error_t
hppe_rfc_block_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union rfc_block_tbl_u *value);

sw_error_t
hppe_rfc_block_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union rfc_block_tbl_u *value);

#define RFC_STATUS_TBL_MAX_ENTRY	300

sw_error_t
hppe_rfc_status_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union rfc_status_tbl_u *value);

sw_error_t
hppe_rfc_status_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union rfc_status_tbl_u *value);

#define DEQ_DIS_TBL_MAX_ENTRY	300

sw_error_t
hppe_deq_dis_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union deq_dis_tbl_u *value);

sw_error_t
hppe_deq_dis_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union deq_dis_tbl_u *value);

#define RING_Q_MAP_TBL_MAX_ENTRY	176

sw_error_t
hppe_ring_q_map_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ring_q_map_tbl_u *value);

sw_error_t
hppe_ring_q_map_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ring_q_map_tbl_u *value);

#define L1_FLOW_MAP_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_flow_map_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_flow_map_tbl_u *value);

sw_error_t
hppe_l1_flow_map_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_flow_map_tbl_u *value);

sw_error_t
hppe_l1_flow_map_tbl_c_drr_credit_unit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_map_tbl_c_drr_credit_unit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_flow_map_tbl_c_drr_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_map_tbl_c_drr_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_flow_map_tbl_c_drr_wt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_map_tbl_c_drr_wt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_flow_map_tbl_c_pri_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_map_tbl_c_pri_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_flow_map_tbl_e_drr_credit_unit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_map_tbl_e_drr_credit_unit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_flow_map_tbl_e_drr_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_map_tbl_e_drr_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_flow_map_tbl_e_drr_wt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_map_tbl_e_drr_wt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_flow_map_tbl_e_pri_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_map_tbl_e_pri_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_flow_map_tbl_sp_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_map_tbl_sp_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L1_FLOW_PORT_MAP_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_flow_port_map_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_flow_port_map_tbl_u *value);

sw_error_t
hppe_l1_flow_port_map_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_flow_port_map_tbl_u *value);

#define L1_C_DRR_HEAD_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_c_drr_head_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_c_drr_head_tbl_u *value);

sw_error_t
hppe_l1_c_drr_head_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_c_drr_head_tbl_u *value);

sw_error_t
hppe_l1_c_drr_head_tbl_active_head_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_c_drr_head_tbl_active_head_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_c_drr_head_tbl_active_max_n_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_c_drr_head_tbl_active_max_n_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_c_drr_head_tbl_active_tail_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_c_drr_head_tbl_active_tail_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_c_drr_head_tbl_active_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_c_drr_head_tbl_active_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_c_drr_head_tbl_backup_head_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_c_drr_head_tbl_backup_head_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_c_drr_head_tbl_backup_max_n_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_c_drr_head_tbl_backup_max_n_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_c_drr_head_tbl_backup_tail_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_c_drr_head_tbl_backup_tail_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_c_drr_head_tbl_backup_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_c_drr_head_tbl_backup_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L1_E_DRR_HEAD_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_e_drr_head_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_e_drr_head_tbl_u *value);

sw_error_t
hppe_l1_e_drr_head_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_e_drr_head_tbl_u *value);

sw_error_t
hppe_l1_e_drr_head_tbl_active_head_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_e_drr_head_tbl_active_head_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_e_drr_head_tbl_active_max_n_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_e_drr_head_tbl_active_max_n_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_e_drr_head_tbl_active_tail_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_e_drr_head_tbl_active_tail_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_e_drr_head_tbl_active_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_e_drr_head_tbl_active_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_e_drr_head_tbl_backup_head_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_e_drr_head_tbl_backup_head_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_e_drr_head_tbl_backup_max_n_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_e_drr_head_tbl_backup_max_n_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_e_drr_head_tbl_backup_tail_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_e_drr_head_tbl_backup_tail_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_e_drr_head_tbl_backup_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_e_drr_head_tbl_backup_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L1_DRR_CREDIT_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_drr_credit_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_drr_credit_tbl_u *value);

sw_error_t
hppe_l1_drr_credit_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_drr_credit_tbl_u *value);

sw_error_t
hppe_l1_drr_credit_tbl_c_drr_credit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_drr_credit_tbl_c_drr_credit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_drr_credit_tbl_c_drr_credit_neg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_drr_credit_tbl_c_drr_credit_neg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_drr_credit_tbl_e_drr_credit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_drr_credit_tbl_e_drr_credit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_drr_credit_tbl_e_drr_credit_neg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_drr_credit_tbl_e_drr_credit_neg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L1_C_DRR_LL_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_c_drr_ll_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_c_drr_ll_tbl_u *value);

sw_error_t
hppe_l1_c_drr_ll_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_c_drr_ll_tbl_u *value);

#define L1_C_DRR_REVERSE_LL_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_c_drr_reverse_ll_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_c_drr_reverse_ll_tbl_u *value);

sw_error_t
hppe_l1_c_drr_reverse_ll_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_c_drr_reverse_ll_tbl_u *value);

#define L1_E_DRR_LL_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_e_drr_ll_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_e_drr_ll_tbl_u *value);

sw_error_t
hppe_l1_e_drr_ll_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_e_drr_ll_tbl_u *value);

#define L1_E_DRR_REVERSE_LL_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_e_drr_reverse_ll_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_e_drr_reverse_ll_tbl_u *value);

sw_error_t
hppe_l1_e_drr_reverse_ll_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_e_drr_reverse_ll_tbl_u *value);

#define L1_SP_ENTRY_TBL_MAX_ENTRY	41

sw_error_t
hppe_l1_sp_entry_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_sp_entry_tbl_u *value);

sw_error_t
hppe_l1_sp_entry_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_sp_entry_tbl_u *value);

sw_error_t
hppe_l1_sp_entry_tbl_entry_path_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value);

sw_error_t
hppe_l1_sp_entry_tbl_entry_path_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value);

sw_error_t
hppe_l1_sp_entry_tbl_entry_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_sp_entry_tbl_entry_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L1_ENS_Q_LL_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_ens_q_ll_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_ens_q_ll_tbl_u *value);

sw_error_t
hppe_l1_ens_q_ll_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_ens_q_ll_tbl_u *value);

#define L1_ENS_Q_HEAD_TBL_MAX_ENTRY	9

sw_error_t
hppe_l1_ens_q_head_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_ens_q_head_tbl_u *value);

sw_error_t
hppe_l1_ens_q_head_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_ens_q_head_tbl_u *value);

sw_error_t
hppe_l1_ens_q_head_tbl_head_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_ens_q_head_tbl_head_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_ens_q_head_tbl_tail_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_ens_q_head_tbl_tail_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_ens_q_head_tbl_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_ens_q_head_tbl_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L1_ENS_Q_ENTRY_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_ens_q_entry_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_ens_q_entry_tbl_u *value);

sw_error_t
hppe_l1_ens_q_entry_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_ens_q_entry_tbl_u *value);

sw_error_t
hppe_l1_ens_q_entry_tbl_entry_ens_in_q_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_ens_q_entry_tbl_entry_ens_in_q_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_ens_q_entry_tbl_entry_ens_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_ens_q_entry_tbl_entry_ens_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_ens_q_entry_tbl_entry_ens_vld_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_ens_q_entry_tbl_entry_ens_vld_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define L1_FLOW_STATUS_TBL_MAX_ENTRY	64

sw_error_t
hppe_l1_flow_status_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_flow_status_tbl_u *value);

sw_error_t
hppe_l1_flow_status_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union l1_flow_status_tbl_u *value);

sw_error_t
hppe_l1_flow_status_tbl_en_cdrr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_status_tbl_en_cdrr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_flow_status_tbl_en_edrr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_status_tbl_en_edrr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_l1_flow_status_tbl_en_level_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_l1_flow_status_tbl_en_level_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define PSCH_TDM_CFG_TBL_MAX_ENTRY	128

sw_error_t
hppe_psch_tdm_cfg_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union psch_tdm_cfg_tbl_u *value);

sw_error_t
hppe_psch_tdm_cfg_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union psch_tdm_cfg_tbl_u *value);

sw_error_t
hppe_psch_tdm_cfg_tbl_des_port_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_psch_tdm_cfg_tbl_des_port_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_psch_tdm_cfg_tbl_des_sec_port_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_psch_tdm_cfg_tbl_des_sec_port_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_psch_tdm_cfg_tbl_des_sec_port_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_psch_tdm_cfg_tbl_des_sec_port_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_psch_tdm_cfg_tbl_ens_port_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_psch_tdm_cfg_tbl_ens_port_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_psch_tdm_cfg_tbl_ens_port_bitmap_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_psch_tdm_cfg_tbl_ens_port_bitmap_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#endif
