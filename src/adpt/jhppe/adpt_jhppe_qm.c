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
/**
 * @}
 */
