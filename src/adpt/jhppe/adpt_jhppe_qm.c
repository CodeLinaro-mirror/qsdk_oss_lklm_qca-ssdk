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

/**
 * @}
 */
