/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HPPE_BM_API_H_
#define _HPPE_BM_API_H_


sw_error_t
hppe_fb_fifo_cfg_get(
		a_uint32_t dev_id,
		union fb_fifo_cfg_u *value);

sw_error_t
hppe_fb_fifo_cfg_set(
		a_uint32_t dev_id,
		union fb_fifo_cfg_u *value);


sw_error_t
hppe_fp_fifo_cfg_get(
		a_uint32_t dev_id,
		union fp_fifo_cfg_u *value);

sw_error_t
hppe_fp_fifo_cfg_set(
		a_uint32_t dev_id,
		union fp_fifo_cfg_u *value);

#define DEQ_FIFO_CFG_MAX_ENTRY	4

sw_error_t
hppe_deq_fifo_cfg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union deq_fifo_cfg_u *value);

sw_error_t
hppe_deq_fifo_cfg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union deq_fifo_cfg_u *value);


sw_error_t
hppe_tick_dly_cfg_get(
		a_uint32_t dev_id,
		union tick_dly_cfg_u *value);

sw_error_t
hppe_tick_dly_cfg_set(
		a_uint32_t dev_id,
		union tick_dly_cfg_u *value);


sw_error_t
hppe_bm_rsv_0_get(
		a_uint32_t dev_id,
		union bm_rsv_0_u *value);

sw_error_t
hppe_bm_rsv_0_set(
		a_uint32_t dev_id,
		union bm_rsv_0_u *value);


sw_error_t
hppe_bm_rsv_1_get(
		a_uint32_t dev_id,
		union bm_rsv_1_u *value);

sw_error_t
hppe_bm_rsv_1_set(
		a_uint32_t dev_id,
		union bm_rsv_1_u *value);

#define PORT_FC_MODE_MAX_ENTRY	19

sw_error_t
hppe_port_fc_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_fc_mode_u *value);

sw_error_t
hppe_port_fc_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_fc_mode_u *value);

#define PORT_FC_STATUS_MAX_ENTRY	19

sw_error_t
hppe_port_fc_status_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_fc_status_u *value);

sw_error_t
hppe_port_fc_status_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_fc_status_u *value);

sw_error_t
hppe_port_fc_status_port_fc_status_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_port_fc_status_port_fc_status_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_port_fc_status_port_xon_th_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_port_fc_status_port_xon_th_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define PORT_GROUP_ID_MAX_ENTRY	19

sw_error_t
hppe_port_group_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_group_id_u *value);

sw_error_t
hppe_port_group_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_group_id_u *value);

#define PORT_CNT_MAX_ENTRY	19

sw_error_t
hppe_port_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_cnt_u *value);

sw_error_t
hppe_port_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_cnt_u *value);

#define PORT_REACTED_CNT_MAX_ENTRY	19

sw_error_t
hppe_port_reacted_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_reacted_cnt_u *value);

sw_error_t
hppe_port_reacted_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_reacted_cnt_u *value);

#define SHARED_GROUP_CNT_MAX_ENTRY	4

sw_error_t
hppe_shared_group_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union shared_group_cnt_u *value);

sw_error_t
hppe_shared_group_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union shared_group_cnt_u *value);

#define SHARED_GROUP_CFG_MAX_ENTRY	4

sw_error_t
hppe_shared_group_cfg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union shared_group_cfg_u *value);

sw_error_t
hppe_shared_group_cfg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union shared_group_cfg_u *value);


sw_error_t
hppe_port_profile_cnt_en_get(
		a_uint32_t dev_id,
		union port_profile_cnt_en_u *value);

sw_error_t
hppe_port_profile_cnt_en_set(
		a_uint32_t dev_id,
		union port_profile_cnt_en_u *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_0_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_0_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_1_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_1_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_10_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_10_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_2_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_2_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_3_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_3_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_4_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_4_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_5_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_5_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_6_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_6_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_7_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_7_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_8_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_8_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_9_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_port_cnt_en_9_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_0_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_0_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_1_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_1_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_10_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_10_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_2_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_2_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_3_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_3_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_4_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_4_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_5_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_5_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_6_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_6_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_7_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_7_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_8_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_8_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_9_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_port_profile_cnt_en_react_cnt_en_9_set(
		a_uint32_t dev_id,
		unsigned int value);


sw_error_t
hppe_grp_profile_cnt_en_get(
		a_uint32_t dev_id,
		union grp_profile_cnt_en_u *value);

sw_error_t
hppe_grp_profile_cnt_en_set(
		a_uint32_t dev_id,
		union grp_profile_cnt_en_u *value);

sw_error_t
hppe_grp_profile_cnt_en_grp_cnt_en_0_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_grp_cnt_en_0_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_grp_cnt_en_1_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_grp_cnt_en_1_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_grp_cnt_en_2_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_grp_cnt_en_2_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_grp_cnt_en_3_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_grp_cnt_en_3_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_11_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_11_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_12_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_12_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_13_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_13_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_14_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_14_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_15_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_15_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_16_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_16_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_17_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_17_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_18_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_port_cnt_en_18_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_11_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_11_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_12_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_12_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_13_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_13_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_14_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_14_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_15_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_15_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_16_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_16_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_17_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_17_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_18_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_react_cnt_en_18_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
hppe_grp_profile_cnt_en_tot_rect_cnt_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
hppe_grp_profile_cnt_en_tot_rect_cnt_en_set(
		a_uint32_t dev_id,
		unsigned int value);

#define PORT_PROFILE_TH_CFG_MAX_ENTRY	19

sw_error_t
hppe_port_profile_th_cfg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_profile_th_cfg_u *value);

sw_error_t
hppe_port_profile_th_cfg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_profile_th_cfg_u *value);

#define REACT_PROFILE_TH_CFG_MAX_ENTRY	19

sw_error_t
hppe_react_profile_th_cfg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union react_profile_th_cfg_u *value);

sw_error_t
hppe_react_profile_th_cfg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union react_profile_th_cfg_u *value);

#define GRP_PROFILE_TH_CFG_MAX_ENTRY	4

sw_error_t
hppe_grp_profile_th_cfg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union grp_profile_th_cfg_u *value);

sw_error_t
hppe_grp_profile_th_cfg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union grp_profile_th_cfg_u *value);


sw_error_t
hppe_tot_react_profile_th_cfg_get(
		a_uint32_t dev_id,
		union tot_react_profile_th_cfg_u *value);

sw_error_t
hppe_tot_react_profile_th_cfg_set(
		a_uint32_t dev_id,
		union tot_react_profile_th_cfg_u *value);

#define PORT_OUT_PROFILE_CNT_MAX_ENTRY	19

sw_error_t
hppe_port_out_profile_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_out_profile_cnt_u *value);

sw_error_t
hppe_port_out_profile_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_out_profile_cnt_u *value);

#define PORT_IN_PROFILE_CNT_MAX_ENTRY	19

sw_error_t
hppe_port_in_profile_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_in_profile_cnt_u *value);

sw_error_t
hppe_port_in_profile_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_in_profile_cnt_u *value);

#define REACT_OUT_PROFILE_CNT_MAX_ENTRY	19

sw_error_t
hppe_react_out_profile_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union react_out_profile_cnt_u *value);

sw_error_t
hppe_react_out_profile_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union react_out_profile_cnt_u *value);

#define REACT_IN_PROFILE_CNT_MAX_ENTRY	19

sw_error_t
hppe_react_in_profile_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union react_in_profile_cnt_u *value);

sw_error_t
hppe_react_in_profile_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union react_in_profile_cnt_u *value);

#define GRP_OUT_PROFILE_CNT_MAX_ENTRY	4

sw_error_t
hppe_grp_out_profile_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union grp_out_profile_cnt_u *value);

sw_error_t
hppe_grp_out_profile_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union grp_out_profile_cnt_u *value);

#define GRP_IN_PROFILE_CNT_MAX_ENTRY	4

sw_error_t
hppe_grp_in_profile_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union grp_in_profile_cnt_u *value);

sw_error_t
hppe_grp_in_profile_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union grp_in_profile_cnt_u *value);


sw_error_t
hppe_tot_react_out_profile_cnt_get(
		a_uint32_t dev_id,
		union tot_react_out_profile_cnt_u *value);

sw_error_t
hppe_tot_react_out_profile_cnt_set(
		a_uint32_t dev_id,
		union tot_react_out_profile_cnt_u *value);


sw_error_t
hppe_tot_react_in_profile_cnt_get(
		a_uint32_t dev_id,
		union tot_react_in_profile_cnt_u *value);

sw_error_t
hppe_tot_react_in_profile_cnt_set(
		a_uint32_t dev_id,
		union tot_react_in_profile_cnt_u *value);

#define PORT_FC_CFG_MAX_ENTRY	19

sw_error_t
hppe_port_fc_cfg_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_fc_cfg_u *value);

sw_error_t
hppe_port_fc_cfg_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union port_fc_cfg_u *value);

sw_error_t
hppe_port_fc_cfg_port_pre_alloc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_port_fc_cfg_port_pre_alloc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_port_fc_cfg_port_react_limit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_port_fc_cfg_port_react_limit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_port_fc_cfg_port_resume_floor_th_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_port_fc_cfg_port_resume_floor_th_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_port_fc_cfg_port_resume_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_port_fc_cfg_port_resume_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_port_fc_cfg_port_shared_ceiling_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_port_fc_cfg_port_shared_ceiling_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_port_fc_cfg_port_shared_dynamic_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_port_fc_cfg_port_shared_dynamic_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_port_fc_cfg_port_shared_weight_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_port_fc_cfg_port_shared_weight_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define LLM_MAX_ENTRY	2048

sw_error_t
hppe_llm_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union llm_u *value);

sw_error_t
hppe_llm_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union llm_u *value);

sw_error_t
hppe_llm_eop_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_llm_eop_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
hppe_llm_nxt_ptr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
hppe_llm_nxt_ptr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define RCM_MAX_ENTRY	2048

sw_error_t
hppe_rcm_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union rcm_u *value);

sw_error_t
hppe_rcm_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union rcm_u *value);

#define DM_MAX_ENTRY	8192

sw_error_t
hppe_dm_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union dm_u *value);

sw_error_t
hppe_dm_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union dm_u *value);

#endif
