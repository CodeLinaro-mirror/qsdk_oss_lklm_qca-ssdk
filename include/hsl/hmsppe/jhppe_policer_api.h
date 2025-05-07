/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _JHPPE_POLICER_API_H_
#define _JHPPE_POLICER_API_H_


sw_error_t
jhppe_sawf_flow_statis_ctrl0_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl0_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl0_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl0_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl0_sample_time_sawf0_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl0_sample_time_sawf0_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_sawf_flow_statis_ctrl0_sample_time_sawf1_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl0_sample_time_sawf1_set(
		a_uint32_t dev_id,
		unsigned int value);


sw_error_t
jhppe_sawf_flow_statis_ctrl1_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl1_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl1_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl1_u *value);


sw_error_t
jhppe_sawf_flow_statis_ctrl2_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl2_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl2_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl2_u *value);


sw_error_t
jhppe_sawf_flow_statis_ctrl3_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl3_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl3_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl3_u *value);


sw_error_t
jhppe_sawf_flow_statis_ctrl4_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl4_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl4_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl4_u *value);


sw_error_t
jhppe_sawf_flow_statis_ctrl5_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl5_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl5_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl5_u *value);


sw_error_t
jhppe_sawf_flow_statis_ctrl6_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl6_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl6_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl6_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl6_cycle_trigger_en_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl6_cycle_trigger_en_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_sawf_flow_statis_ctrl6_cycle_trigger_num_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl6_cycle_trigger_num_set(
		a_uint32_t dev_id,
		unsigned int value);


sw_error_t
jhppe_sawf_flow_statis_ctrl7_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl7_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl7_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl7_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl7_clear_mode_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl7_clear_mode_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_sawf_flow_statis_ctrl7_cnt_mode_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl7_cnt_mode_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_sawf_flow_statis_ctrl7_comp_len_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl7_comp_len_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_sawf_flow_statis_ctrl7_iat_shift_bit_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl7_iat_shift_bit_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_sawf_flow_statis_ctrl7_overflow_ctrl_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl7_overflow_ctrl_set(
		a_uint32_t dev_id,
		unsigned int value);


sw_error_t
jhppe_sawf_flow_statis_state_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_state_u *value);

sw_error_t
jhppe_sawf_flow_statis_state_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_state_u *value);

sw_error_t
jhppe_sawf_flow_statis_state_bytes_id_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_state_bytes_id_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_sawf_flow_statis_state_sawf0_active0_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_state_sawf0_active0_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
jhppe_sawf_flow_statis_state_sawf0_active1_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
jhppe_sawf_flow_statis_state_sawf0_active1_set(
		a_uint32_t dev_id,
		unsigned int value);


sw_error_t
jhppe_sawf_flow_statis_ctrl8_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl8_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl8_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl8_u *value);


sw_error_t
jhppe_sawf_flow_statis_ctrl9_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl9_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl9_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl9_u *value);


sw_error_t
jhppe_sawf_flow_statis_ctrl10_get(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl10_u *value);

sw_error_t
jhppe_sawf_flow_statis_ctrl10_set(
		a_uint32_t dev_id,
		union sawf_flow_statis_ctrl10_u *value);

#define SAWF_FLOW_BLOCK_MAP_MAX_ENTRY	16

sw_error_t
jhppe_sawf_flow_block_map_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union sawf_flow_block_map_u *value);

sw_error_t
jhppe_sawf_flow_block_map_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union sawf_flow_block_map_u *value);

#define PM_COUNTER_TBL_MAX_ENTRY	32

sw_error_t
jhppe_pm_counter_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pm_counter_tbl_u *value);

sw_error_t
jhppe_pm_counter_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pm_counter_tbl_u *value);

sw_error_t
jhppe_pm_counter_tbl_bcast_packet_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_pm_counter_tbl_bcast_packet_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_pm_counter_tbl_crc_error_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_pm_counter_tbl_crc_error_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_pm_counter_tbl_frame_1024_1518_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_pm_counter_tbl_frame_1024_1518_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_pm_counter_tbl_frame_128_255_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_pm_counter_tbl_frame_128_255_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_pm_counter_tbl_frame_256_511_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_pm_counter_tbl_frame_256_511_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_pm_counter_tbl_frame_512_1023_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_pm_counter_tbl_frame_512_1023_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_pm_counter_tbl_frame_64_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_pm_counter_tbl_frame_64_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_pm_counter_tbl_frame_65_127_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_pm_counter_tbl_frame_65_127_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_pm_counter_tbl_mcast_packet_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_pm_counter_tbl_mcast_packet_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_pm_counter_tbl_octets_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value);

sw_error_t
jhppe_pm_counter_tbl_octets_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value);

sw_error_t
jhppe_pm_counter_tbl_oversize_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_pm_counter_tbl_oversize_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_pm_counter_tbl_ucast_packet_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_pm_counter_tbl_ucast_packet_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#define SAWF_FLOW_CNT_TBL_MAX_ENTRY	512

sw_error_t
jhppe_sawf_flow_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union sawf_flow_cnt_tbl_u *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union sawf_flow_cnt_tbl_u *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes0_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes0_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes1_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes1_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes2_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes2_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes3_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes3_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes4_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes4_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes5_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes5_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes6_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes6_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes7_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes7_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes8_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes8_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes9_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_bytes9_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_flags_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_flags_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_is_bytes_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_is_bytes_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_oc_bytes_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_oc_bytes_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_timestamp_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_burst_timestamp_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_bytes_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_bytes_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_bytes_max_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_bytes_max_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_bytes_min_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_bytes_min_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_flow_timestamp_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_flow_timestamp_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_packet_iat_max_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_packet_iat_max_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_packet_iat_min_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_packet_iat_min_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_packet_iat_sum_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_packet_iat_sum_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_packets_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
jhppe_sawf_flow_cnt_tbl_packets_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#endif
