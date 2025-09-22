/*
* Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
* SPDX-License-Identifier: ISC
*/

#include "adpt.h"
#include "hsl_htt_reg.h"

static fal_queue_bmp_t port_queue_map[6] = {0};

sw_error_t
adpt_httppe_l1_flow_map_set(a_uint32_t dev_id,
			    a_uint32_t node_id,
			    fal_port_t port_id,
			    fal_qos_scheduler_cfg_t *scheduler_cfg)
{
	union l1_flow_port_map_tbl_u l1_flow_port_map_tbl;
	union l1_flow_map_tbl_u l1_flow_map_tbl;
	union l1_comp_cfg_tbl_u l1_comp_cfg_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(scheduler_cfg);

	if (node_id >= L1_FLOW_MAP_TBL_MAX_ENTRY)
		return SW_BAD_PARAM;

	memset(&l1_flow_map_tbl, 0, sizeof(l1_flow_map_tbl));

	l1_flow_map_tbl.bf.e_drr_credit_unit = scheduler_cfg->e_drr_unit;
	l1_flow_map_tbl.bf.c_drr_credit_unit = scheduler_cfg->c_drr_unit;
	l1_flow_map_tbl.bf.e_drr_id = scheduler_cfg->e_drr_id;
	l1_flow_map_tbl.bf.c_drr_id = scheduler_cfg->c_drr_id;

	l1_flow_map_tbl.bf.e_drr_wt= scheduler_cfg->e_drr_wt;
	l1_flow_map_tbl.bf.c_drr_wt = scheduler_cfg->c_drr_wt;
	l1_flow_map_tbl.bf.e_pri = scheduler_cfg->e_pri;
	l1_flow_map_tbl.bf.c_pri = scheduler_cfg->c_pri;
	l1_flow_map_tbl.bf.sp_id = scheduler_cfg->sp_id;
	httppe_l1_flow_map_tbl_set(dev_id, node_id, &l1_flow_map_tbl);

	httppe_l1_flow_port_map_tbl_get(dev_id, node_id, &l1_flow_port_map_tbl);
	l1_flow_port_map_tbl.bf.port_num = port_id;
	httppe_l1_flow_port_map_tbl_set(dev_id, node_id, &l1_flow_port_map_tbl);

	httppe_l1_comp_cfg_tbl_get(dev_id, node_id, &l1_comp_cfg_tbl);
	l1_comp_cfg_tbl.bf.drr_meter_len = scheduler_cfg->drr_frame_mode;
	httppe_l1_comp_cfg_tbl_set(dev_id, node_id, &l1_comp_cfg_tbl);

	return SW_OK;
}

sw_error_t
adpt_httppe_l1_flow_map_get(a_uint32_t dev_id,
			    a_uint32_t node_id,
			    fal_port_t *port_id,
			    fal_qos_scheduler_cfg_t *scheduler_cfg)
{
	union l1_flow_map_tbl_u l1_flow_map_tbl;
	union l1_comp_cfg_tbl_u l1_comp_cfg_tbl;
	union l1_flow_port_map_tbl_u port_map;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(scheduler_cfg);

	if (node_id >= L1_FLOW_MAP_TBL_MAX_ENTRY)
		return SW_BAD_PARAM;

	memset(&l1_flow_map_tbl, 0, sizeof(l1_flow_map_tbl));

	httppe_l1_flow_map_tbl_get(dev_id, node_id, &l1_flow_map_tbl);
	scheduler_cfg->e_drr_wt = l1_flow_map_tbl.bf.e_drr_wt;
	scheduler_cfg->c_drr_wt = l1_flow_map_tbl.bf.c_drr_wt;
	scheduler_cfg->e_pri = l1_flow_map_tbl.bf.e_pri;
	scheduler_cfg->c_pri = l1_flow_map_tbl.bf.c_pri;
	scheduler_cfg->sp_id = l1_flow_map_tbl.bf.sp_id;
	scheduler_cfg->c_drr_id = l1_flow_map_tbl.bf.c_drr_id;
	scheduler_cfg->e_drr_id = l1_flow_map_tbl.bf.e_drr_id;
	scheduler_cfg->c_drr_unit = l1_flow_map_tbl.bf.c_drr_credit_unit;
	scheduler_cfg->e_drr_unit = l1_flow_map_tbl.bf.e_drr_credit_unit;

	httppe_l1_flow_port_map_tbl_get(dev_id, node_id, &port_map);
	*port_id = port_map.bf.port_num;

	httppe_l1_comp_cfg_tbl_get(dev_id, node_id, &l1_comp_cfg_tbl);
	scheduler_cfg->drr_frame_mode = l1_comp_cfg_tbl.bf.drr_meter_len;

	return SW_OK;
}

sw_error_t
adpt_httppe_l0_queue_map_set(a_uint32_t dev_id,
			     a_uint32_t node_id,
			     fal_port_t port_id,
			     fal_qos_scheduler_cfg_t *scheduler_cfg)
{
	union l0_flow_port_map_tbl_u l0_flow_port_map_tbl;
	union l0_flow_map_tbl_u l0_flow_map_tbl;
	union l0_comp_cfg_tbl_u l0_comp_cfg_tbl;
	a_uint32_t i, j, k;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(scheduler_cfg);

	if (node_id >= L0_FLOW_MAP_TBL_MAX_ENTRY)
		return SW_BAD_PARAM;

	memset(&l0_flow_map_tbl, 0, sizeof(l0_flow_map_tbl));

	l0_flow_map_tbl.bf.e_drr_credit_unit = scheduler_cfg->e_drr_unit;
	l0_flow_map_tbl.bf.c_drr_credit_unit = scheduler_cfg->c_drr_unit;
	l0_flow_map_tbl.bf.e_drr_id = scheduler_cfg->e_drr_id;
	l0_flow_map_tbl.bf.c_drr_id = scheduler_cfg->c_drr_id;

	l0_flow_map_tbl.bf.e_drr_wt= scheduler_cfg->e_drr_wt;
	l0_flow_map_tbl.bf.c_drr_wt = scheduler_cfg->c_drr_wt;
	l0_flow_map_tbl.bf.e_pri = scheduler_cfg->e_pri;
	l0_flow_map_tbl.bf.c_pri = scheduler_cfg->c_pri;
	l0_flow_map_tbl.bf.sp_id = scheduler_cfg->sp_id;
	httppe_l0_flow_map_tbl_set(dev_id, node_id, &l0_flow_map_tbl);

	httppe_l0_flow_port_map_tbl_get(dev_id, node_id, &l0_flow_port_map_tbl);
	l0_flow_port_map_tbl.bf.port_num = port_id;
	httppe_l0_flow_port_map_tbl_set(dev_id, node_id, &l0_flow_port_map_tbl);

	httppe_l0_comp_cfg_tbl_get(dev_id, node_id, &l0_comp_cfg_tbl);
	l0_comp_cfg_tbl.bf.drr_meter_len = scheduler_cfg->drr_frame_mode;
	httppe_l0_comp_cfg_tbl_set(dev_id, node_id, &l0_comp_cfg_tbl);

	i = node_id / 32;
	j = node_id % 32;
	port_queue_map[port_id].bmp[i] |= 1 << j;

	for (k = 0; k < 6; k++) {
		if (k != port_id) {
			port_queue_map[k].bmp[i] &= ~(1 << j);
		}
	}

	return SW_OK;
}

sw_error_t
adpt_httppe_l0_queue_map_get(a_uint32_t dev_id,
			     a_uint32_t node_id,
			     fal_port_t *port_id,
			     fal_qos_scheduler_cfg_t *scheduler_cfg)
{
	union l0_flow_port_map_tbl_u l0_flow_port_map_tbl;
	union l0_flow_map_tbl_u l0_flow_map_tbl;
	union l0_comp_cfg_tbl_u l0_comp_cfg_tbl;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(scheduler_cfg);

	if (node_id >= L0_FLOW_MAP_TBL_MAX_ENTRY)
		return SW_BAD_PARAM;

	memset(&l0_flow_map_tbl, 0, sizeof(l0_flow_map_tbl));

	httppe_l0_flow_map_tbl_get(dev_id, node_id, &l0_flow_map_tbl);
	scheduler_cfg->e_drr_wt = l0_flow_map_tbl.bf.e_drr_wt;
	scheduler_cfg->c_drr_wt = l0_flow_map_tbl.bf.c_drr_wt;
	scheduler_cfg->e_pri = l0_flow_map_tbl.bf.e_pri;
	scheduler_cfg->c_pri = l0_flow_map_tbl.bf.c_pri;
	scheduler_cfg->sp_id = l0_flow_map_tbl.bf.sp_id;
	scheduler_cfg->c_drr_id = l0_flow_map_tbl.bf.c_drr_id;
	scheduler_cfg->e_drr_id = l0_flow_map_tbl.bf.e_drr_id;
	scheduler_cfg->c_drr_unit = l0_flow_map_tbl.bf.c_drr_credit_unit;
	scheduler_cfg->e_drr_unit = l0_flow_map_tbl.bf.e_drr_credit_unit;

	httppe_l0_flow_port_map_tbl_get(dev_id, node_id, &l0_flow_port_map_tbl);
	*port_id = l0_flow_port_map_tbl.bf.port_num;

	httppe_l0_comp_cfg_tbl_get(dev_id, node_id, &l0_comp_cfg_tbl);
	scheduler_cfg->drr_frame_mode = l0_comp_cfg_tbl.bf.drr_meter_len;

	return SW_OK;
}

sw_error_t
adpt_httppe_tdm_tick_num_set(a_uint32_t dev_id, a_uint32_t tick_num)
{
	union tdm_depth_cfg_u tdm_depth_cfg;

	ADPT_DEV_ID_CHECK(dev_id);

	tdm_depth_cfg.bf.tdm_depth = tick_num;
	return httppe_tdm_depth_cfg_set(dev_id, &tdm_depth_cfg);
}

sw_error_t
adpt_httppe_port_scheduler_cfg_set(a_uint32_t dev_id,
				a_uint32_t tick_index,
				fal_port_scheduler_cfg_t *cfg)
{
	union psch_tdm_cfg_tbl_u psch_tdm_cfg = {0};

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(cfg);

	psch_tdm_cfg.bf.ens_port_bitmap = cfg->en_scheduler_port_bmp;
	psch_tdm_cfg.bf.ens_port = cfg->en_scheduler_port;
	psch_tdm_cfg.bf.des_port = cfg->de_scheduler_port;
	psch_tdm_cfg.bf.des_sec_port_en = cfg->de_scheduler_2nd_port_en;
	psch_tdm_cfg.bf.des_sec_port = cfg->de_scheduler_2nd_port;

	return httppe_psch_tdm_cfg_tbl_set(dev_id, tick_index, &psch_tdm_cfg);
}

#ifndef IN_QOS_MINI
sw_error_t
adpt_httppe_port_queues_get(a_uint32_t dev_id,
			    fal_port_t port_id,
			    fal_queue_bmp_t *queue_bmp)
{
	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(queue_bmp);

	*queue_bmp = port_queue_map[port_id];

	return SW_OK;
}

sw_error_t
adpt_httppe_tdm_tick_num_get(a_uint32_t dev_id, a_uint32_t *tick_num)
{
	union tdm_depth_cfg_u tdm_depth_cfg;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(tick_num);

	httppe_tdm_depth_cfg_get(dev_id, &tdm_depth_cfg);
	*tick_num = tdm_depth_cfg.bf.tdm_depth;

	return SW_OK;
}

sw_error_t
adpt_httppe_port_scheduler_cfg_get(a_uint32_t dev_id,
				a_uint32_t tick_index,
				fal_port_scheduler_cfg_t *cfg)
{
	union psch_tdm_cfg_tbl_u psch_tdm_cfg;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(cfg);

	httppe_psch_tdm_cfg_tbl_get(dev_id, tick_index, &psch_tdm_cfg);
	cfg->en_scheduler_port_bmp = psch_tdm_cfg.bf.ens_port_bitmap;
	cfg->en_scheduler_port = psch_tdm_cfg.bf.ens_port;
	cfg->de_scheduler_port = psch_tdm_cfg.bf.des_port;
	cfg->de_scheduler_2nd_port_en = psch_tdm_cfg.bf.des_sec_port_en;
	cfg->de_scheduler_2nd_port = psch_tdm_cfg.bf.des_sec_port;

	return SW_OK;
}
#endif
