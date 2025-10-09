/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

/**
 * @defgroup
 * @{
 */
#include "sw.h"
#include "hsl_reg.h"
#include "fal_qm.h"
#include "adpt.h"

#ifdef HMSPPE
#define ADPT_PPE_MULTIQ_MONITOR_STATUS_PORT_NUM   8
#else
#define ADPT_PPE_MULTIQ_MONITOR_STATUS_PORT_NUM   9
#endif
#define ADPT_PPE_UNIQ_MONITOR_STATUS_CNT_NUM      64
#define ADPT_PPE_UNIQ_ID_MAPPING_NUM_ENTRY        256
#define ADPT_PPE_MULTIQ_ID_MAPPING_MAX_OFFSET     16

sw_error_t
adpt_jhppe_qm_tcont_set(a_uint32_t dev_id,
			a_uint32_t queue_id,
			fal_queue_tcont_cfg_t *cfg)
{
	union queue_map_tbl_u q_tcont_map;
	sw_error_t rv = SW_OK;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(cfg);

	aos_mem_zero(&q_tcont_map, sizeof(union queue_map_tbl_u));

	rv = jhppe_queue_map_tbl_get(dev_id, queue_id, &q_tcont_map);
	SW_RTN_ON_ERROR(rv);

	q_tcont_map.bf.tcont_id_vld = cfg->valid;
	q_tcont_map.bf.tcont_id = cfg->tcont_id;

	return jhppe_queue_map_tbl_set(dev_id, queue_id, &q_tcont_map);
}

sw_error_t
adpt_jhppe_qm_tcont_get(a_uint32_t dev_id,
			a_uint32_t queue_id,
			fal_queue_tcont_cfg_t *cfg)
{
	union queue_map_tbl_u q_tcont_map;
	sw_error_t rv = SW_OK;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(cfg);

	aos_mem_zero(&q_tcont_map, sizeof(union queue_map_tbl_u));

	rv = jhppe_queue_map_tbl_get(dev_id, queue_id, &q_tcont_map);
	SW_RTN_ON_ERROR(rv);

	cfg->valid = q_tcont_map.bf.tcont_id_vld;
	cfg->tcont_id = q_tcont_map.bf.tcont_id;

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_tcont_stat_get(a_uint32_t dev_id,
			     a_uint32_t tcont_id,
			     fal_queue_tcont_stat_t *stat)
{
	union tcont_byte_cnt_tbl_u tcont_byte_cnt;
	union tcont_credit_tbl_u tcont_credit;
	sw_error_t rv = SW_OK;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(stat);

	aos_mem_zero(&tcont_credit, sizeof(union tcont_credit_tbl_u));
	aos_mem_zero(&tcont_byte_cnt, sizeof(union tcont_byte_cnt_tbl_u));

	rv = jhppe_tcont_credit_tbl_get(dev_id, tcont_id, &tcont_credit);
	SW_RTN_ON_ERROR(rv);

	rv = jhppe_tcont_byte_cnt_tbl_get(dev_id, tcont_id, &tcont_byte_cnt);
	SW_RTN_ON_ERROR(rv);

	stat->credit = tcont_credit.bf.tcont_credit;
	stat->bytes = tcont_byte_cnt.bf.tcont_byte_cnt_0;
	stat->bytes |= (a_uint64_t)tcont_byte_cnt.bf.tcont_byte_cnt_1 << 32;

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_tcont_stat_set(a_uint32_t dev_id,
			     a_uint32_t tcont_id,
			     fal_queue_tcont_stat_t *stat)
{
	union tcont_byte_cnt_tbl_u tcont_byte_cnt;
	union tcont_credit_tbl_u tcont_credit;
	sw_error_t rv = SW_OK;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(stat);

	aos_mem_zero(&tcont_credit, sizeof(union tcont_credit_tbl_u));
	aos_mem_zero(&tcont_byte_cnt, sizeof(union tcont_byte_cnt_tbl_u));

	rv = jhppe_tcont_credit_tbl_get(dev_id, tcont_id, &tcont_credit);
	SW_RTN_ON_ERROR(rv);

	rv = jhppe_tcont_byte_cnt_tbl_get(dev_id, tcont_id, &tcont_byte_cnt);
	SW_RTN_ON_ERROR(rv);

	tcont_credit.bf.tcont_credit = stat->credit;
	tcont_byte_cnt.bf.tcont_byte_cnt_0 = stat->bytes;
	tcont_byte_cnt.bf.tcont_byte_cnt_1 =  stat->bytes >> 32;

	rv = jhppe_tcont_credit_tbl_set(dev_id, tcont_id, &tcont_credit);
	SW_RTN_ON_ERROR(rv);

	return jhppe_tcont_byte_cnt_tbl_set(dev_id, tcont_id, &tcont_byte_cnt);
}

sw_error_t
adpt_jhppe_qm_cpucode_enqueue_get(a_uint32_t dev_id, a_uint32_t cpu_code, a_bool_t *enable)
{
	sw_error_t rv = SW_OK;
	a_uint32_t enqueue_dis;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(enable);

	rv = hppe_l2_cpu_code_ctrl_enqueue_disable_get(dev_id, cpu_code, &enqueue_dis);
	SW_RTN_ON_ERROR(rv);

	*enable = !enqueue_dis;

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_cpucode_enqueue_set(a_uint32_t dev_id, a_uint32_t cpu_code, a_bool_t enable)
{
	a_uint32_t enqueue_dis;

	ADPT_DEV_ID_CHECK(dev_id);
	enqueue_dis = !enable;

	return hppe_l2_cpu_code_ctrl_enqueue_disable_set(dev_id, cpu_code, enqueue_dis);
}

sw_error_t
adpt_jhppe_qm_counter_monitor_en_set(a_uint32_t dev_id, a_bool_t enable)
{
	sw_error_t rv = SW_OK;
	union sram_qcnt_ctrl_u sram_qcnt_ctrl;

	ADPT_DEV_ID_CHECK(dev_id);

	aos_mem_zero(&sram_qcnt_ctrl, sizeof(union sram_qcnt_ctrl_u));

	rv = jhppe_sram_qcnt_ctrl_get(dev_id, &sram_qcnt_ctrl);
	SW_RTN_ON_ERROR(rv);
	sram_qcnt_ctrl.bf.sramq_go = enable;

	return jhppe_sram_qcnt_ctrl_set(dev_id, &sram_qcnt_ctrl);
}

sw_error_t
adpt_jhppe_qm_counter_monitor_en_get(a_uint32_t dev_id, a_bool_t *enable)
{
	sw_error_t rv = SW_OK;
	union sram_qcnt_ctrl_u sram_qcnt_ctrl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(enable);

	aos_mem_zero(&sram_qcnt_ctrl, sizeof(union sram_qcnt_ctrl_u));

	rv = jhppe_sram_qcnt_ctrl_get(dev_id, &sram_qcnt_ctrl);
	SW_RTN_ON_ERROR(rv);
	*enable = sram_qcnt_ctrl.bf.sramq_go;

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_counter_monitor_stats_cleanup(a_uint32_t dev_id)
{
	sw_error_t rv = SW_OK;
	union sram_qcnt_ctrl_u sram_qcnt_ctrl;

	ADPT_DEV_ID_CHECK(dev_id);

	aos_mem_zero(&sram_qcnt_ctrl, sizeof(union sram_qcnt_ctrl_u));

	rv = jhppe_sram_qcnt_ctrl_get(dev_id, &sram_qcnt_ctrl);
	SW_RTN_ON_ERROR(rv);
	sram_qcnt_ctrl.bf.sramq_clear = 0x1;

	return jhppe_sram_qcnt_ctrl_set(dev_id, &sram_qcnt_ctrl);
}

sw_error_t
adpt_jhppe_qm_counter_monitor_status_get(a_uint32_t dev_id, fal_qm_queue_type_t type,
		a_uint32_t cnt_id, a_bool_t *status)
{
	sw_error_t rv = SW_OK;
	union sram_mulq_cnt_status_u sram_mulq_cnt_status;
	union sram_uniq_cnt_status_u sram_uniq_cnt_status;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(status);

	aos_mem_zero(&sram_mulq_cnt_status, sizeof(union sram_mulq_cnt_status_u));
	aos_mem_zero(&sram_uniq_cnt_status, sizeof(union sram_uniq_cnt_status_u));

	if (type == FAL_SRAM_UNIQ) {
		if (cnt_id < ADPT_PPE_UNIQ_MONITOR_STATUS_CNT_NUM / 2) {
			rv = jhppe_sram_uniq_cnt_status_get(dev_id, 0, &sram_uniq_cnt_status);
			SW_RTN_ON_ERROR(rv);
			*status = (sram_uniq_cnt_status.bf.status >> cnt_id) & 0x1;
		} else if (cnt_id < ADPT_PPE_UNIQ_MONITOR_STATUS_CNT_NUM) {
			rv = jhppe_sram_uniq_cnt_status_get(dev_id, 1, &sram_uniq_cnt_status);
			SW_RTN_ON_ERROR(rv);
			*status = (sram_uniq_cnt_status.bf.status >> cnt_id % 32) & 0x1;
		} else {
			return SW_BAD_VALUE;
		}
	} else if (type == FAL_SRAM_MULTIQ) {
		if (cnt_id < ADPT_PPE_MULTIQ_MONITOR_STATUS_PORT_NUM) {
			rv = jhppe_sram_mulq_cnt_status_get(dev_id, &sram_mulq_cnt_status);
			SW_RTN_ON_ERROR(rv);
			*status = (sram_mulq_cnt_status.bf.status >> cnt_id) & 0x1;
		} else {
				return SW_BAD_VALUE;
		}
	} else {
		return SW_BAD_VALUE;
	}

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_counter_monitor_map_set(a_uint32_t dev_id, fal_qm_queue_type_t type,
		a_uint32_t map_id, fal_qm_monitor_map_t *monitor_map)
{
	sw_error_t rv = SW_OK;
	union sram_uniq_cnt_qid_map_u sram_uniq_cnt_qid_map;
	union sram_mulq_cnt_cfg_tbl_u sram_mulq_cnt_cfg_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(monitor_map);

	aos_mem_zero(&sram_uniq_cnt_qid_map, sizeof(union sram_uniq_cnt_qid_map_u));
	aos_mem_zero(&sram_mulq_cnt_cfg_tbl, sizeof(union sram_mulq_cnt_cfg_tbl_u));

	if (type == FAL_SRAM_UNIQ) {
		if (monitor_map->cnt_id >= ADPT_PPE_UNIQ_MONITOR_STATUS_CNT_NUM) {
			return SW_BAD_VALUE;
		}
		if (map_id < ADPT_PPE_UNIQ_ID_MAPPING_NUM_ENTRY) {
			rv = jhppe_sram_uniq_cnt_qid_map_get(dev_id, map_id, &sram_uniq_cnt_qid_map);
			SW_RTN_ON_ERROR(rv);
			sram_uniq_cnt_qid_map.bf.uniq_cnt_id = monitor_map->cnt_id;
			sram_uniq_cnt_qid_map.bf.uniq_cnt_id_en = monitor_map->cnt_en;
			return jhppe_sram_uniq_cnt_qid_map_set(dev_id, map_id, &sram_uniq_cnt_qid_map);
		} else {
			return SW_BAD_VALUE;
		}
	} else if (type == FAL_SRAM_MULTIQ) {
		if (monitor_map->cnt_id >= ADPT_PPE_MULTIQ_ID_MAPPING_MAX_OFFSET) {
			return SW_BAD_VALUE;
		}
		if (map_id < ADPT_PPE_MULTIQ_MONITOR_STATUS_PORT_NUM) {
			rv = jhppe_sram_mulq_cnt_cfg_tbl_get(dev_id, map_id, &sram_mulq_cnt_cfg_tbl);
			SW_RTN_ON_ERROR(rv);
			sram_mulq_cnt_cfg_tbl.bf.mulq_qid = monitor_map->cnt_id;
			sram_mulq_cnt_cfg_tbl.bf.mulq_qid_en = monitor_map->cnt_en;
			return jhppe_sram_mulq_cnt_cfg_tbl_set(dev_id, map_id, &sram_mulq_cnt_cfg_tbl);
		} else {
			return SW_BAD_VALUE;
		}
	} else {
		return SW_BAD_VALUE;
	}

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_counter_monitor_map_get(a_uint32_t dev_id, fal_qm_queue_type_t type,
		a_uint32_t map_id, fal_qm_monitor_map_t *monitor_map)
{
	sw_error_t rv = SW_OK;
	union sram_uniq_cnt_qid_map_u sram_uniq_cnt_qid_map;
	union sram_mulq_cnt_cfg_tbl_u sram_mulq_cnt_cfg_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(monitor_map);

	aos_mem_zero(&sram_uniq_cnt_qid_map, sizeof(union sram_uniq_cnt_qid_map_u));
	aos_mem_zero(&sram_mulq_cnt_cfg_tbl, sizeof(union sram_mulq_cnt_cfg_tbl_u));

	if (type == FAL_SRAM_UNIQ) {
		if (map_id < ADPT_PPE_UNIQ_ID_MAPPING_NUM_ENTRY) {
			rv = jhppe_sram_uniq_cnt_qid_map_get(dev_id, map_id, &sram_uniq_cnt_qid_map);
			SW_RTN_ON_ERROR(rv);
			monitor_map->cnt_id = sram_uniq_cnt_qid_map.bf.uniq_cnt_id;
			monitor_map->cnt_en = sram_uniq_cnt_qid_map.bf.uniq_cnt_id_en;
		} else {
			return SW_BAD_VALUE;
		}
	} else if (type == FAL_SRAM_MULTIQ) {
		if (map_id < ADPT_PPE_MULTIQ_MONITOR_STATUS_PORT_NUM) {
			rv = jhppe_sram_mulq_cnt_cfg_tbl_get(dev_id, map_id, &sram_mulq_cnt_cfg_tbl);
			SW_RTN_ON_ERROR(rv);
			monitor_map->cnt_id = sram_mulq_cnt_cfg_tbl.bf.mulq_qid;
			monitor_map->cnt_en = sram_mulq_cnt_cfg_tbl.bf.mulq_qid_en;
		} else {
			return SW_BAD_VALUE;
		}
	} else {
		return SW_BAD_VALUE;
	}

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_counter_monitor_ctrl_set(a_uint32_t dev_id, fal_qm_queue_type_t type,
		a_uint32_t cnt_id, fal_qm_monitor_ctrl_t *monitor_ctrl)
{
	sw_error_t rv = SW_OK;
	union sram_uniq_cnt_cfg_tbl_u sram_uniq_cnt_cfg_tbl;
	union sram_mulq_cnt_cfg_tbl_u sram_mulq_cnt_cfg_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(monitor_ctrl);

	aos_mem_zero(&sram_uniq_cnt_cfg_tbl, sizeof(union sram_uniq_cnt_cfg_tbl_u));
	aos_mem_zero(&sram_mulq_cnt_cfg_tbl, sizeof(union sram_mulq_cnt_cfg_tbl_u));

	if (type == FAL_SRAM_UNIQ) {
		if (cnt_id < ADPT_PPE_UNIQ_MONITOR_STATUS_CNT_NUM) {
			rv = jhppe_sram_uniq_cnt_cfg_tbl_get(dev_id, cnt_id, &sram_uniq_cnt_cfg_tbl);
			SW_RTN_ON_ERROR(rv);
			sram_uniq_cnt_cfg_tbl.bf.uniq_hi_th_type = monitor_ctrl->cnt_threshold_mode;
			sram_uniq_cnt_cfg_tbl.bf.uniq_hi_th = monitor_ctrl->cnt_threshold;
			return jhppe_sram_uniq_cnt_cfg_tbl_set(dev_id, cnt_id, &sram_uniq_cnt_cfg_tbl);
		} else {
			return SW_BAD_VALUE;
		}
	} else if (type == FAL_SRAM_MULTIQ) {
		if (cnt_id < ADPT_PPE_MULTIQ_MONITOR_STATUS_PORT_NUM) {
			rv = jhppe_sram_mulq_cnt_cfg_tbl_get(dev_id, cnt_id, &sram_mulq_cnt_cfg_tbl);
			SW_RTN_ON_ERROR(rv);
			sram_mulq_cnt_cfg_tbl.bf.mulq_hi_th_type = monitor_ctrl->cnt_threshold_mode;
			sram_mulq_cnt_cfg_tbl.bf.mulq_hi_th = monitor_ctrl->cnt_threshold;
			return jhppe_sram_mulq_cnt_cfg_tbl_set(dev_id, cnt_id, &sram_mulq_cnt_cfg_tbl);
		}
	} else {
		return SW_BAD_VALUE;
	}

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_counter_monitor_ctrl_get(a_uint32_t dev_id, fal_qm_queue_type_t type,
		a_uint32_t cnt_id, fal_qm_monitor_ctrl_t *monitor_ctrl)
{
	sw_error_t rv = SW_OK;
	union sram_uniq_cnt_cfg_tbl_u sram_uniq_cnt_cfg_tbl;
	union sram_mulq_cnt_cfg_tbl_u sram_mulq_cnt_cfg_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(monitor_ctrl);

	aos_mem_zero(&sram_uniq_cnt_cfg_tbl, sizeof(union sram_uniq_cnt_cfg_tbl_u));
	aos_mem_zero(&sram_mulq_cnt_cfg_tbl, sizeof(union sram_mulq_cnt_cfg_tbl_u));

	if (type == FAL_SRAM_UNIQ) {
		if (cnt_id < ADPT_PPE_UNIQ_MONITOR_STATUS_CNT_NUM) {
			rv = jhppe_sram_uniq_cnt_cfg_tbl_get(dev_id, cnt_id, &sram_uniq_cnt_cfg_tbl);
			SW_RTN_ON_ERROR(rv);
			monitor_ctrl->cnt_threshold_mode = sram_uniq_cnt_cfg_tbl.bf.uniq_hi_th_type;
			monitor_ctrl->cnt_threshold = sram_uniq_cnt_cfg_tbl.bf.uniq_hi_th;
		} else {
			return SW_BAD_VALUE;
		}

	} else if (type == FAL_SRAM_MULTIQ) {
		if (cnt_id < ADPT_PPE_MULTIQ_MONITOR_STATUS_PORT_NUM) {
			rv = jhppe_sram_mulq_cnt_cfg_tbl_get(dev_id, cnt_id, &sram_mulq_cnt_cfg_tbl);
			SW_RTN_ON_ERROR(rv);
			monitor_ctrl->cnt_threshold_mode = sram_mulq_cnt_cfg_tbl.bf.mulq_hi_th_type;
			monitor_ctrl->cnt_threshold = sram_mulq_cnt_cfg_tbl.bf.mulq_hi_th;
		}
	} else {
		return SW_BAD_VALUE;
	}

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_counter_monitor_stats_get(a_uint32_t dev_id, fal_qm_queue_type_t type,
		a_uint32_t cnt_id, fal_qm_monitor_stats_t *monitor_stats)
{
	sw_error_t rv = SW_OK;
	union sram_uniq_cnt_tbl_u sram_uniq_cnt_tbl;
	union sram_mulq_cnt_tbl_u sram_mulq_cnt_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(monitor_stats);

	aos_mem_zero(&sram_uniq_cnt_tbl, sizeof(union sram_uniq_cnt_tbl_u));
	aos_mem_zero(&sram_mulq_cnt_tbl, sizeof(union sram_mulq_cnt_tbl_u));

	if (type == FAL_SRAM_UNIQ) {
		if (cnt_id < ADPT_PPE_UNIQ_MONITOR_STATUS_CNT_NUM) {
			rv = jhppe_sram_uniq_cnt_tbl_get(dev_id, cnt_id, &sram_uniq_cnt_tbl);
			monitor_stats->packets = sram_uniq_cnt_tbl.bf.uniq_pkt_cnt;
			monitor_stats->bytes = sram_uniq_cnt_tbl.bf.uniq_byte_cnt;
			monitor_stats->peak_packets = sram_uniq_cnt_tbl.bf.uniq_peak_pkt_cnt;
			monitor_stats->peak_bytes = sram_uniq_cnt_tbl.bf.uniq_peak_byte_cnt;
		} else {
			return SW_BAD_VALUE;
		}
	} else if (type == FAL_SRAM_MULTIQ) {
		rv = jhppe_sram_mulq_cnt_tbl_get(dev_id, cnt_id, &sram_mulq_cnt_tbl);
		monitor_stats->packets = (sram_mulq_cnt_tbl.bf.mulq_pkt_cnt_1 <<
			SW_FIELD_OFFSET_IN_WORD(SRAM_MULQ_CNT_TBL_MULQ_PKT_CNT_OFFSET)) |
			sram_mulq_cnt_tbl.bf.mulq_pkt_cnt_0;
		monitor_stats->bytes = sram_mulq_cnt_tbl.bf.mulq_byte_cnt;
		monitor_stats->peak_packets = (sram_mulq_cnt_tbl.bf.mulq_peak_pkt_cnt_1 <<
			SW_FIELD_OFFSET_IN_WORD(SRAM_MULQ_CNT_TBL_MULQ_PEAK_PKT_CNT_OFFSET)) |
			sram_mulq_cnt_tbl.bf.mulq_peak_pkt_cnt_0;
		monitor_stats->peak_bytes = sram_mulq_cnt_tbl.bf.mulq_peak_byte_cnt;
	} else {
		return SW_BAD_VALUE;
	}

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_enqueue_servcode_config_set(a_uint32_t dev_id, fal_enqueue_cfg_t *enqueue_cfg)
{
	union l2_vp_port_post_tbl_u l2_vp_tbl;
	sw_error_t rv = SW_OK;
	a_uint32_t index = 0;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(enqueue_cfg);

	if (enqueue_cfg->rule_entry.enqueue_type != FAL_ENQUEUE_SERVCODE)
		return SW_BAD_PARAM;

	aos_mem_zero(&l2_vp_tbl, sizeof(union l2_vp_port_post_tbl_u));

	index = enqueue_cfg->rule_entry.dst_port;

	rv = jhppe_l2_vp_port_post_tbl_get(dev_id, index, &l2_vp_tbl);
	SW_RTN_ON_ERROR(rv);

	l2_vp_tbl.bf.enq_service_code_0 =
		enqueue_cfg->index_entry.enqueue_servcode.service_code;
	l2_vp_tbl.bf.enq_service_code_1 =
		enqueue_cfg->index_entry.enqueue_servcode.service_code >>
		SW_FIELD_OFFSET_IN_WORD(L2_VP_PORT_POST_TBL_ENQ_SERVICE_CODE_OFFSET);

	l2_vp_tbl.bf.enq_service_code_en = enqueue_cfg->index_entry.enqueue_en;

	l2_vp_tbl.bf.enq_phy_port =
		enqueue_cfg->index_entry.enqueue_servcode.phy_port;

	l2_vp_tbl.bf.enq_service_code_queue_dis =
		!enqueue_cfg->index_entry.enqueue_servcode.queue_select_en;

	return jhppe_l2_vp_port_post_tbl_set(dev_id, index, &l2_vp_tbl);
}

sw_error_t
adpt_jhppe_qm_enqueue_servcode_config_get(a_uint32_t dev_id, fal_enqueue_cfg_t *enqueue_cfg)
{
	union l2_vp_port_post_tbl_u l2_vp_tbl;
	sw_error_t rv = SW_OK;
	a_uint32_t index = 0;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(enqueue_cfg);

	if (enqueue_cfg->rule_entry.enqueue_type != FAL_ENQUEUE_SERVCODE)
		return SW_BAD_PARAM;

	aos_mem_zero(&l2_vp_tbl, sizeof(union l2_vp_port_post_tbl_u));

	index = enqueue_cfg->rule_entry.dst_port;

	rv = jhppe_l2_vp_port_post_tbl_get(dev_id, index, &l2_vp_tbl);
	SW_RTN_ON_ERROR(rv);

	enqueue_cfg->index_entry.enqueue_en =
		l2_vp_tbl.bf.enq_service_code_en;

	enqueue_cfg->index_entry.enqueue_servcode.phy_port =
		l2_vp_tbl.bf.enq_phy_port;

	enqueue_cfg->index_entry.enqueue_servcode.queue_select_en =
		!l2_vp_tbl.bf.enq_service_code_queue_dis;

	enqueue_cfg->index_entry.enqueue_servcode.service_code =
		l2_vp_tbl.bf.enq_service_code_0;
	enqueue_cfg->index_entry.enqueue_servcode.service_code |=
		l2_vp_tbl.bf.enq_service_code_1 <<
		SW_FIELD_OFFSET_IN_WORD(L2_VP_PORT_POST_TBL_ENQ_SERVICE_CODE_OFFSET);

	return rv;
}

sw_error_t
adpt_jhppe_ucast_queue_ddrq_en_set(a_uint32_t dev_id, a_uint32_t queue_id,
		fal_ucast_queue_ddrq_en_t *ddrqen)
{
	union ucast_queue_ctrl_tbl_u reg_val;
	sw_error_t rv;

	rv = jhppe_ucast_queue_ctrl_tbl_get(dev_id, queue_id, &reg_val);
	SW_RTN_ON_ERROR(rv);

	reg_val.bf.ddrq_en = ddrqen->ddrq_en;
	reg_val.bf.qid_mismatch_check_en = ddrqen->qid_mismatch_check_en;

	return jhppe_ucast_queue_ctrl_tbl_set(dev_id, queue_id, &reg_val);;
}

sw_error_t
adpt_jhppe_ucast_queue_ddrq_en_get(a_uint32_t dev_id, a_uint32_t queue_id,
		fal_ucast_queue_ddrq_en_t *ddrqen)
{
	union ucast_queue_ctrl_tbl_u reg_val = {0};
	sw_error_t rv;

	rv = jhppe_ucast_queue_ctrl_tbl_get(dev_id, queue_id, &reg_val);
	SW_RTN_ON_ERROR(rv);

	ddrqen->ddrq_en = reg_val.bf.ddrq_en;
	ddrqen->qid_mismatch_check_en = reg_val.bf.qid_mismatch_check_en;

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_passthrough_source_profile_set(a_uint32_t dev_id,
		fal_passthrough_mode_t mode, fal_passthrough_src_profile_t *profile)
{
	a_bool_t esram_en, isram_en;
	union enq_ctrl_u reg_val;
	sw_error_t rv;

	rv = jhppe_enq_ctrl_get(dev_id, &reg_val);
	SW_RTN_ON_ERROR(rv);

	esram_en = profile->esramq_src_profile_en ? A_TRUE : A_FALSE;
	isram_en = profile->isramq_src_profile_en ? A_TRUE : A_FALSE;

	switch (mode) {
	case FAL_PASSTHROUGH_MODE_192_128:
		reg_val.bf.pass_through0_src_profile = profile->src_profile;
		reg_val.bf.pass_through0_src_profile_eg_en = esram_en;
		reg_val.bf.pass_through0_src_profile_en = isram_en;
		break;
	case FAL_PASSTHROUGH_MODE_FULL_2ND_PASS:
		reg_val.bf.pass_through1_src_profile = profile->src_profile;
		reg_val.bf.pass_through1_src_profile_eg_en = esram_en;
		reg_val.bf.pass_through1_src_profile_en = isram_en;
		break;
	case FAL_PASSTHROUGH_MODE_NO:
		reg_val.bf.pass_through2_src_profile = profile->src_profile;
		reg_val.bf.pass_through2_src_profile_eg_en = esram_en;
		reg_val.bf.pass_through2_src_profile_en = isram_en;
		break;
	case FAL_PASSTHROUGH_MODE_FULL:
		reg_val.bf.pass_through3_src_profile = profile->src_profile;
		reg_val.bf.pass_through3_src_profile_eg_en = esram_en;
		reg_val.bf.pass_through3_src_profile_en = isram_en;
		break;
	default:
		return SW_BAD_PARAM;
	}

	return jhppe_enq_ctrl_set(dev_id, &reg_val);
}

sw_error_t
adpt_jhppe_qm_passthrough_source_profile_get(a_uint32_t dev_id,
		fal_passthrough_mode_t mode, fal_passthrough_src_profile_t *profile)
{
	union enq_ctrl_u reg_val;
	sw_error_t rv;

	rv = jhppe_enq_ctrl_get(dev_id, &reg_val);
	SW_RTN_ON_ERROR(rv);

	switch (mode) {
	case FAL_PASSTHROUGH_MODE_192_128:
		profile->src_profile = reg_val.bf.pass_through0_src_profile;
		profile->esramq_src_profile_en = reg_val.bf.pass_through0_src_profile_eg_en;
		profile->isramq_src_profile_en = reg_val.bf.pass_through0_src_profile_en;
		break;
	case FAL_PASSTHROUGH_MODE_FULL_2ND_PASS:
		profile->src_profile = reg_val.bf.pass_through1_src_profile;
		profile->esramq_src_profile_en = reg_val.bf.pass_through1_src_profile_eg_en;
		profile->isramq_src_profile_en = reg_val.bf.pass_through1_src_profile_en;
		break;
	case FAL_PASSTHROUGH_MODE_NO:
		profile->src_profile = reg_val.bf.pass_through2_src_profile;
		profile->esramq_src_profile_en = reg_val.bf.pass_through2_src_profile_eg_en;
		profile->isramq_src_profile_en = reg_val.bf.pass_through2_src_profile_en;
		break;
	case FAL_PASSTHROUGH_MODE_FULL:
		profile->src_profile = reg_val.bf.pass_through3_src_profile;
		profile->esramq_src_profile_en = reg_val.bf.pass_through3_src_profile_eg_en;
		profile->isramq_src_profile_en = reg_val.bf.pass_through3_src_profile_en;
		break;
	default:
		return SW_BAD_PARAM;
	}

	return SW_OK;
}

sw_error_t
adpt_jhppe_qm_passthrough_direct_enqueue_set(a_uint32_t dev_id,
		fal_passthrough_mode_t mode, a_bool_t enable)
{
	sw_error_t rv;

	switch (mode) {
	case FAL_PASSTHROUGH_MODE_192_128:
		rv = jhppe_enq_ctrl_pass_through0_direc_enq_dis_set(dev_id, !enable);
		break;
	case FAL_PASSTHROUGH_MODE_FULL_2ND_PASS:
		rv = jhppe_enq_ctrl_pass_through1_direc_enq_dis_set(dev_id, !enable);
		break;
	case FAL_PASSTHROUGH_MODE_NO:
		rv = jhppe_enq_ctrl_pass_through2_direc_enq_dis_set(dev_id, !enable);
		break;
	case FAL_PASSTHROUGH_MODE_FULL:
		rv = jhppe_enq_ctrl_pass_through3_direc_enq_dis_set(dev_id, !enable);
		break;
	default:
		rv = SW_BAD_PARAM;
		break;
	}

	return rv;
}

sw_error_t
adpt_jhppe_qm_passthrough_direct_enqueue_get(a_uint32_t dev_id,
		fal_passthrough_mode_t mode, a_bool_t *enable)
{
	a_uint32_t val = 0;
	sw_error_t rv;

	switch (mode) {
	case FAL_PASSTHROUGH_MODE_192_128:
		rv = jhppe_enq_ctrl_pass_through0_direc_enq_dis_get(dev_id, &val);
		break;
	case FAL_PASSTHROUGH_MODE_FULL_2ND_PASS:
		rv = jhppe_enq_ctrl_pass_through1_direc_enq_dis_get(dev_id, &val);
		break;
	case FAL_PASSTHROUGH_MODE_NO:
		rv = jhppe_enq_ctrl_pass_through2_direc_enq_dis_get(dev_id, &val);
		break;
	case FAL_PASSTHROUGH_MODE_FULL:
		rv = jhppe_enq_ctrl_pass_through3_direc_enq_dis_get(dev_id, &val);
		break;
	default:
		rv = SW_BAD_PARAM;
		break;
	}

	*enable = !val;

	return rv;
}

sw_error_t
adpt_jhppe_qm_passthrough_cpucode_set(a_uint32_t dev_id, fal_passthrough_cpucode_t *cpucode)
{
	union enq_ctrl_ext_u enq_ctrl_ext = {0};
	sw_error_t rv;

	rv = jhppe_enq_ctrl_ext_get(dev_id, &enq_ctrl_ext);
	SW_RTN_ON_ERROR(rv);

	enq_ctrl_ext.bf.drop_cpu_code = cpucode->drop_cpucode;
	enq_ctrl_ext.bf.cpu_code_0 = cpucode->cpucode[0];
	enq_ctrl_ext.bf.cpu_code_1 = cpucode->cpucode[1];
	rv = jhppe_enq_ctrl_ext_set(dev_id, &enq_ctrl_ext);
	SW_RTN_ON_ERROR(rv);

	return jhppe_enq_ctrl_qid_mismatch_enq_cpu_code_set(dev_id, cpucode->qid_mismatch_cpucode);
}

sw_error_t
adpt_jhppe_qm_passthrough_cpucode_get(a_uint32_t dev_id, fal_passthrough_cpucode_t *cpucode)
{
	union enq_ctrl_ext_u enq_ctrl_ext = {0};
	sw_error_t rv;

	rv = jhppe_enq_ctrl_ext_get(dev_id, &enq_ctrl_ext);
	SW_RTN_ON_ERROR(rv);

	cpucode->drop_cpucode = enq_ctrl_ext.bf.drop_cpu_code;
	cpucode->cpucode[0] = enq_ctrl_ext.bf.cpu_code_0;
	cpucode->cpucode[1] = enq_ctrl_ext.bf.cpu_code_1;

	return jhppe_enq_ctrl_qid_mismatch_enq_cpu_code_get(dev_id, &cpucode->qid_mismatch_cpucode);
}

sw_error_t
adpt_jhppe_qm_passthrough_cpucode_en_set(a_uint32_t dev_id,
			fal_passthrough_mode_t mode, a_bool_t enable)
{
	union enq_ctrl_ext_u enq_ctrl_ext = {0};
	sw_error_t rv;

	if (mode > FAL_PASSTHROUGH_MODE_FULL)
		return SW_BAD_PARAM;

	rv = jhppe_enq_ctrl_ext_get(dev_id, &enq_ctrl_ext);
	SW_RTN_ON_ERROR(rv);

	if (enable)
		enq_ctrl_ext.bf.cpu_code_en |= BIT(mode);
	else
		enq_ctrl_ext.bf.cpu_code_en &= ~BIT(mode);

	return jhppe_enq_ctrl_ext_set(dev_id, &enq_ctrl_ext);
}

sw_error_t
adpt_jhppe_qm_passthrough_cpucode_en_get(a_uint32_t dev_id,
			fal_passthrough_mode_t mode, a_bool_t *enable)
{
	union enq_ctrl_ext_u enq_ctrl_ext = {0};
	sw_error_t rv;

	if (mode > FAL_PASSTHROUGH_MODE_FULL)
		return SW_BAD_PARAM;

	rv = jhppe_enq_ctrl_ext_get(dev_id, &enq_ctrl_ext);
	SW_RTN_ON_ERROR(rv);

	*enable = !!(enq_ctrl_ext.bf.cpu_code_en & BIT(mode));

	return SW_OK;
}
/**
 * @}
 */
