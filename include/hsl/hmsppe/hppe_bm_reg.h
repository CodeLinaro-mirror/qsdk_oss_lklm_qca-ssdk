/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HPPE_BM_REG_H_
#define _HPPE_BM_REG_H_

/*[register] FB_FIFO_CFG*/
#define FB_FIFO_CFG
#define FB_FIFO_CFG_ADDRESS 0x0
#define FB_FIFO_CFG_NUM     1
#define FB_FIFO_CFG_INC     0x4
#define FB_FIFO_CFG_TYPE    REG_TYPE_RW
#define FB_FIFO_CFG_DEFAULT 0x10
	/*[field] FB_FIFO_THRES*/
	#define FB_FIFO_CFG_FB_FIFO_THRES
	#define FB_FIFO_CFG_FB_FIFO_THRES_OFFSET  0
	#define FB_FIFO_CFG_FB_FIFO_THRES_LEN     5
	#define FB_FIFO_CFG_FB_FIFO_THRES_DEFAULT 0x10

struct fb_fifo_cfg {
	a_uint32_t  fb_fifo_thres:5;
	a_uint32_t  _reserved0:27;
};

union fb_fifo_cfg_u {
	a_uint32_t val;
	struct fb_fifo_cfg bf;
};

/*[register] FP_FIFO_CFG*/
#define FP_FIFO_CFG
#define FP_FIFO_CFG_ADDRESS 0x4
#define FP_FIFO_CFG_NUM     1
#define FP_FIFO_CFG_INC     0x4
#define FP_FIFO_CFG_TYPE    REG_TYPE_RW
#define FP_FIFO_CFG_DEFAULT 0x10
	/*[field] FP_FIFO_THRES*/
	#define FP_FIFO_CFG_FP_FIFO_THRES
	#define FP_FIFO_CFG_FP_FIFO_THRES_OFFSET  0
	#define FP_FIFO_CFG_FP_FIFO_THRES_LEN     5
	#define FP_FIFO_CFG_FP_FIFO_THRES_DEFAULT 0x10

struct fp_fifo_cfg {
	a_uint32_t  fp_fifo_thres:5;
	a_uint32_t  _reserved0:27;
};

union fp_fifo_cfg_u {
	a_uint32_t val;
	struct fp_fifo_cfg bf;
};

/*[register] DEQ_FIFO_CFG*/
#define DEQ_FIFO_CFG
#define DEQ_FIFO_CFG_ADDRESS 0x8
#define DEQ_FIFO_CFG_NUM     9
#define DEQ_FIFO_CFG_INC     0x4
#define DEQ_FIFO_CFG_TYPE    REG_TYPE_RW
#define DEQ_FIFO_CFG_DEFAULT 0x2
	/*[field] DEQ_FIFO_THRES*/
	#define DEQ_FIFO_CFG_DEQ_FIFO_THRES
	#define DEQ_FIFO_CFG_DEQ_FIFO_THRES_OFFSET  0
	#define DEQ_FIFO_CFG_DEQ_FIFO_THRES_LEN     3
	#define DEQ_FIFO_CFG_DEQ_FIFO_THRES_DEFAULT 0x2

struct deq_fifo_cfg {
	a_uint32_t  deq_fifo_thres:3;
	a_uint32_t  _reserved0:29;
};

union deq_fifo_cfg_u {
	a_uint32_t val;
	struct deq_fifo_cfg bf;
};

/*[register] TICK_DLY_CFG*/
#define TICK_DLY_CFG
#define TICK_DLY_CFG_ADDRESS 0x30
#define TICK_DLY_CFG_NUM     1
#define TICK_DLY_CFG_INC     0x4
#define TICK_DLY_CFG_TYPE    REG_TYPE_RW
#define TICK_DLY_CFG_DEFAULT 0x0
	/*[field] TICK_DLY*/
	#define TICK_DLY_CFG_TICK_DLY
	#define TICK_DLY_CFG_TICK_DLY_OFFSET  0
	#define TICK_DLY_CFG_TICK_DLY_LEN     1
	#define TICK_DLY_CFG_TICK_DLY_DEFAULT 0x0

struct tick_dly_cfg {
	a_uint32_t  tick_dly:1;
	a_uint32_t  _reserved0:31;
};

union tick_dly_cfg_u {
	a_uint32_t val;
	struct tick_dly_cfg bf;
};

/*[register] BM_RSV_0*/
#define BM_RSV_0
#define BM_RSV_0_ADDRESS 0x34
#define BM_RSV_0_NUM     1
#define BM_RSV_0_INC     0x4
#define BM_RSV_0_TYPE    REG_TYPE_RW
#define BM_RSV_0_DEFAULT 0x0
	/*[field] RSV_0*/
	#define BM_RSV_0_RSV_0
	#define BM_RSV_0_RSV_0_OFFSET  0
	#define BM_RSV_0_RSV_0_LEN     32
	#define BM_RSV_0_RSV_0_DEFAULT 0x0

struct bm_rsv_0 {
	a_uint32_t  rsv_0:32;
};

union bm_rsv_0_u {
	a_uint32_t val;
	struct bm_rsv_0 bf;
};

/*[register] BM_RSV_1*/
#define BM_RSV_1
#define BM_RSV_1_ADDRESS 0x38
#define BM_RSV_1_NUM     1
#define BM_RSV_1_INC     0x4
#define BM_RSV_1_TYPE    REG_TYPE_RW
#define BM_RSV_1_DEFAULT 0x0
	/*[field] RSV_1*/
	#define BM_RSV_1_RSV_1
	#define BM_RSV_1_RSV_1_OFFSET  0
	#define BM_RSV_1_RSV_1_LEN     32
	#define BM_RSV_1_RSV_1_DEFAULT 0x0

struct bm_rsv_1 {
	a_uint32_t  rsv_1:32;
};

union bm_rsv_1_u {
	a_uint32_t val;
	struct bm_rsv_1 bf;
};

/*[register] PORT_FC_MODE*/
#define PORT_FC_MODE
#define PORT_FC_MODE_ADDRESS 0x100
#define PORT_FC_MODE_NUM     40
#define PORT_FC_MODE_INC     0x4
#define PORT_FC_MODE_TYPE    REG_TYPE_RW
#define PORT_FC_MODE_DEFAULT 0x0
	/*[field] FC_EN*/
	#define PORT_FC_MODE_FC_EN
	#define PORT_FC_MODE_FC_EN_OFFSET  0
	#define PORT_FC_MODE_FC_EN_LEN     1
	#define PORT_FC_MODE_FC_EN_DEFAULT 0x0

struct port_fc_mode {
	a_uint32_t  fc_en:1;
	a_uint32_t  _reserved0:31;
};

union port_fc_mode_u {
	a_uint32_t val;
	struct port_fc_mode bf;
};

/*[register] PORT_FC_STATUS*/
#define PORT_FC_STATUS
#define PORT_FC_STATUS_ADDRESS 0x1a0
#define PORT_FC_STATUS_NUM     40
#define PORT_FC_STATUS_INC     0x4
#define PORT_FC_STATUS_TYPE    REG_TYPE_RO
#define PORT_FC_STATUS_DEFAULT 0x0
	/*[field] PORT_XON_TH*/
	#define PORT_FC_STATUS_PORT_XON_TH
	#define PORT_FC_STATUS_PORT_XON_TH_OFFSET  0
	#define PORT_FC_STATUS_PORT_XON_TH_LEN     12
	#define PORT_FC_STATUS_PORT_XON_TH_DEFAULT 0x0
	/*[field] PORT_FC_STATUS*/
	#define PORT_FC_STATUS_PORT_FC_STATUS
	#define PORT_FC_STATUS_PORT_FC_STATUS_OFFSET  17
	#define PORT_FC_STATUS_PORT_FC_STATUS_LEN     2
	#define PORT_FC_STATUS_PORT_FC_STATUS_DEFAULT 0x0

struct port_fc_status {
	a_uint32_t  port_xon_th:12;
	a_uint32_t  _reserved0:5;
	a_uint32_t  port_fc_status:2;
	a_uint32_t  _reserved1:13;
};

union port_fc_status_u {
	a_uint32_t val;
	struct port_fc_status bf;
};

/*[register] PORT_GROUP_ID*/
#define PORT_GROUP_ID
#define PORT_GROUP_ID_ADDRESS 0x240
#define PORT_GROUP_ID_NUM     40
#define PORT_GROUP_ID_INC     0x4
#define PORT_GROUP_ID_TYPE    REG_TYPE_RW
#define PORT_GROUP_ID_DEFAULT 0x0
	/*[field] PORT_SHARED_GROUP_ID*/
	#define PORT_GROUP_ID_PORT_SHARED_GROUP_ID
	#define PORT_GROUP_ID_PORT_SHARED_GROUP_ID_OFFSET  0
	#define PORT_GROUP_ID_PORT_SHARED_GROUP_ID_LEN     2
	#define PORT_GROUP_ID_PORT_SHARED_GROUP_ID_DEFAULT 0x0

struct port_group_id {
	a_uint32_t  port_shared_group_id:2;
	a_uint32_t  _reserved0:30;
};

union port_group_id_u {
	a_uint32_t val;
	struct port_group_id bf;
};

/*[register] PORT_CNT*/
#define PORT_CNT
#define PORT_CNT_ADDRESS 0x2e0
#define PORT_CNT_NUM     40
#define PORT_CNT_INC     0x4
#define PORT_CNT_TYPE    REG_TYPE_RO
#define PORT_CNT_DEFAULT 0x0
	/*[field] PORT_CNT*/
	#define PORT_CNT_PORT_CNT
	#define PORT_CNT_PORT_CNT_OFFSET  0
	#define PORT_CNT_PORT_CNT_LEN     12
	#define PORT_CNT_PORT_CNT_DEFAULT 0x0

struct port_cnt {
	a_uint32_t  port_cnt:12;
	a_uint32_t  _reserved0:20;
};

union port_cnt_u {
	a_uint32_t val;
	struct port_cnt bf;
};

/*[register] PORT_REACTED_CNT*/
#define PORT_REACTED_CNT
#define PORT_REACTED_CNT_ADDRESS 0x380
#define PORT_REACTED_CNT_NUM     40
#define PORT_REACTED_CNT_INC     0x4
#define PORT_REACTED_CNT_TYPE    REG_TYPE_RO
#define PORT_REACTED_CNT_DEFAULT 0x0
	/*[field] PORT_REACTED_CNT*/
	#define PORT_REACTED_CNT_PORT_REACTED_CNT
	#define PORT_REACTED_CNT_PORT_REACTED_CNT_OFFSET  0
	#define PORT_REACTED_CNT_PORT_REACTED_CNT_LEN     10
	#define PORT_REACTED_CNT_PORT_REACTED_CNT_DEFAULT 0x0

struct port_reacted_cnt {
	a_uint32_t  port_reacted_cnt:10;
	a_uint32_t  _reserved0:22;
};

union port_reacted_cnt_u {
	a_uint32_t val;
	struct port_reacted_cnt bf;
};

/*[register] SHARED_GROUP_CNT*/
#define SHARED_GROUP_CNT
#define SHARED_GROUP_CNT_ADDRESS 0x420
#define SHARED_GROUP_CNT_NUM     4
#define SHARED_GROUP_CNT_INC     0x4
#define SHARED_GROUP_CNT_TYPE    REG_TYPE_RO
#define SHARED_GROUP_CNT_DEFAULT 0x0
	/*[field] SHARED_GROUP_CNT*/
	#define SHARED_GROUP_CNT_SHARED_GROUP_CNT
	#define SHARED_GROUP_CNT_SHARED_GROUP_CNT_OFFSET  0
	#define SHARED_GROUP_CNT_SHARED_GROUP_CNT_LEN     12
	#define SHARED_GROUP_CNT_SHARED_GROUP_CNT_DEFAULT 0x0

struct shared_group_cnt {
	a_uint32_t  shared_group_cnt:12;
	a_uint32_t  _reserved0:20;
};

union shared_group_cnt_u {
	a_uint32_t val;
	struct shared_group_cnt bf;
};

/*[register] SHARED_GROUP_CFG*/
#define SHARED_GROUP_CFG
#define SHARED_GROUP_CFG_ADDRESS 0x460
#define SHARED_GROUP_CFG_NUM     4
#define SHARED_GROUP_CFG_INC     0x4
#define SHARED_GROUP_CFG_TYPE    REG_TYPE_RW
#define SHARED_GROUP_CFG_DEFAULT 0x0
	/*[field] SHARED_GROUP_LIMIT*/
	#define SHARED_GROUP_CFG_SHARED_GROUP_LIMIT
	#define SHARED_GROUP_CFG_SHARED_GROUP_LIMIT_OFFSET  0
	#define SHARED_GROUP_CFG_SHARED_GROUP_LIMIT_LEN     12
	#define SHARED_GROUP_CFG_SHARED_GROUP_LIMIT_DEFAULT 0x0

struct shared_group_cfg {
	a_uint32_t  shared_group_limit:12;
	a_uint32_t  _reserved0:20;
};

union shared_group_cfg_u {
	a_uint32_t val;
	struct shared_group_cfg bf;
};

/*[register] PORT_PROFILE_TH_CFG*/
#define PORT_PROFILE_TH_CFG
#define PORT_PROFILE_TH_CFG_ADDRESS 0x4b0
#define PORT_PROFILE_TH_CFG_NUM     40
#define PORT_PROFILE_TH_CFG_INC     0x4
#define PORT_PROFILE_TH_CFG_TYPE    REG_TYPE_RW
#define PORT_PROFILE_TH_CFG_DEFAULT 0x0
	/*[field] PORT_PROFILE_TH_CFG*/
	#define PORT_PROFILE_TH_CFG_PORT_PROFILE_TH_CFG
	#define PORT_PROFILE_TH_CFG_PORT_PROFILE_TH_CFG_OFFSET  0
	#define PORT_PROFILE_TH_CFG_PORT_PROFILE_TH_CFG_LEN     12
	#define PORT_PROFILE_TH_CFG_PORT_PROFILE_TH_CFG_DEFAULT 0x0

struct port_profile_th_cfg {
	a_uint32_t  port_profile_th_cfg:12;
	a_uint32_t  _reserved0:20;
};

union port_profile_th_cfg_u {
	a_uint32_t val;
	struct port_profile_th_cfg bf;
};

/*[register] REACT_PROFILE_TH_CFG*/
#define REACT_PROFILE_TH_CFG
#define REACT_PROFILE_TH_CFG_ADDRESS 0x550
#define REACT_PROFILE_TH_CFG_NUM     40
#define REACT_PROFILE_TH_CFG_INC     0x4
#define REACT_PROFILE_TH_CFG_TYPE    REG_TYPE_RW
#define REACT_PROFILE_TH_CFG_DEFAULT 0x0
	/*[field] REACT_PROFILE_TH_CFG*/
	#define REACT_PROFILE_TH_CFG_REACT_PROFILE_TH_CFG
	#define REACT_PROFILE_TH_CFG_REACT_PROFILE_TH_CFG_OFFSET  0
	#define REACT_PROFILE_TH_CFG_REACT_PROFILE_TH_CFG_LEN     10
	#define REACT_PROFILE_TH_CFG_REACT_PROFILE_TH_CFG_DEFAULT 0x0

struct react_profile_th_cfg {
	a_uint32_t  react_profile_th_cfg:10;
	a_uint32_t  _reserved0:22;
};

union react_profile_th_cfg_u {
	a_uint32_t val;
	struct react_profile_th_cfg bf;
};

/*[register] GRP_PROFILE_TH_CFG*/
#define GRP_PROFILE_TH_CFG
#define GRP_PROFILE_TH_CFG_ADDRESS 0x5f0
#define GRP_PROFILE_TH_CFG_NUM     4
#define GRP_PROFILE_TH_CFG_INC     0x4
#define GRP_PROFILE_TH_CFG_TYPE    REG_TYPE_RW
#define GRP_PROFILE_TH_CFG_DEFAULT 0x0
	/*[field] GRP_PROFILE_TH_CFG*/
	#define GRP_PROFILE_TH_CFG_GRP_PROFILE_TH_CFG
	#define GRP_PROFILE_TH_CFG_GRP_PROFILE_TH_CFG_OFFSET  0
	#define GRP_PROFILE_TH_CFG_GRP_PROFILE_TH_CFG_LEN     12
	#define GRP_PROFILE_TH_CFG_GRP_PROFILE_TH_CFG_DEFAULT 0x0

struct grp_profile_th_cfg {
	a_uint32_t  grp_profile_th_cfg:12;
	a_uint32_t  _reserved0:20;
};

union grp_profile_th_cfg_u {
	a_uint32_t val;
	struct grp_profile_th_cfg bf;
};

/*[register] TOT_REACT_PROFILE_TH_CFG*/
#define TOT_REACT_PROFILE_TH_CFG
#define TOT_REACT_PROFILE_TH_CFG_ADDRESS 0x600
#define TOT_REACT_PROFILE_TH_CFG_NUM     1
#define TOT_REACT_PROFILE_TH_CFG_INC     0x4
#define TOT_REACT_PROFILE_TH_CFG_TYPE    REG_TYPE_RW
#define TOT_REACT_PROFILE_TH_CFG_DEFAULT 0x0
	/*[field] TOT_REACT_PROFILE_TH_CFG*/
	#define TOT_REACT_PROFILE_TH_CFG_TOT_REACT_PROFILE_TH_CFG
	#define TOT_REACT_PROFILE_TH_CFG_TOT_REACT_PROFILE_TH_CFG_OFFSET  0
	#define TOT_REACT_PROFILE_TH_CFG_TOT_REACT_PROFILE_TH_CFG_LEN     12
	#define TOT_REACT_PROFILE_TH_CFG_TOT_REACT_PROFILE_TH_CFG_DEFAULT 0x0

struct tot_react_profile_th_cfg {
	a_uint32_t  tot_react_profile_th_cfg:12;
	a_uint32_t  _reserved0:20;
};

union tot_react_profile_th_cfg_u {
	a_uint32_t val;
	struct tot_react_profile_th_cfg bf;
};

/*[register] PORT_OUT_PROFILE_CNT*/
#define PORT_OUT_PROFILE_CNT
#define PORT_OUT_PROFILE_CNT_ADDRESS 0x604
#define PORT_OUT_PROFILE_CNT_NUM     40
#define PORT_OUT_PROFILE_CNT_INC     0x4
#define PORT_OUT_PROFILE_CNT_TYPE    REG_TYPE_RW
#define PORT_OUT_PROFILE_CNT_DEFAULT 0x0
	/*[field] PORT_OUT_PROFILE_CNT*/
	#define PORT_OUT_PROFILE_CNT_PORT_OUT_PROFILE_CNT
	#define PORT_OUT_PROFILE_CNT_PORT_OUT_PROFILE_CNT_OFFSET  0
	#define PORT_OUT_PROFILE_CNT_PORT_OUT_PROFILE_CNT_LEN     32
	#define PORT_OUT_PROFILE_CNT_PORT_OUT_PROFILE_CNT_DEFAULT 0x0

struct port_out_profile_cnt {
	a_uint32_t  port_out_profile_cnt:32;
};

union port_out_profile_cnt_u {
	a_uint32_t val;
	struct port_out_profile_cnt bf;
};

/*[register] PORT_IN_PROFILE_CNT*/
#define PORT_IN_PROFILE_CNT
#define PORT_IN_PROFILE_CNT_ADDRESS 0x6a4
#define PORT_IN_PROFILE_CNT_NUM     40
#define PORT_IN_PROFILE_CNT_INC     0x4
#define PORT_IN_PROFILE_CNT_TYPE    REG_TYPE_RW
#define PORT_IN_PROFILE_CNT_DEFAULT 0x0
	/*[field] PORT_IN_PROFILE_CNT*/
	#define PORT_IN_PROFILE_CNT_PORT_IN_PROFILE_CNT
	#define PORT_IN_PROFILE_CNT_PORT_IN_PROFILE_CNT_OFFSET  0
	#define PORT_IN_PROFILE_CNT_PORT_IN_PROFILE_CNT_LEN     32
	#define PORT_IN_PROFILE_CNT_PORT_IN_PROFILE_CNT_DEFAULT 0x0

struct port_in_profile_cnt {
	a_uint32_t  port_in_profile_cnt:32;
};

union port_in_profile_cnt_u {
	a_uint32_t val;
	struct port_in_profile_cnt bf;
};

/*[register] REACT_OUT_PROFILE_CNT*/
#define REACT_OUT_PROFILE_CNT
#define REACT_OUT_PROFILE_CNT_ADDRESS 0x744
#define REACT_OUT_PROFILE_CNT_NUM     40
#define REACT_OUT_PROFILE_CNT_INC     0x4
#define REACT_OUT_PROFILE_CNT_TYPE    REG_TYPE_RW
#define REACT_OUT_PROFILE_CNT_DEFAULT 0x0
	/*[field] REACT_OUT_PROFILE_CNT*/
	#define REACT_OUT_PROFILE_CNT_REACT_OUT_PROFILE_CNT
	#define REACT_OUT_PROFILE_CNT_REACT_OUT_PROFILE_CNT_OFFSET  0
	#define REACT_OUT_PROFILE_CNT_REACT_OUT_PROFILE_CNT_LEN     32
	#define REACT_OUT_PROFILE_CNT_REACT_OUT_PROFILE_CNT_DEFAULT 0x0

struct react_out_profile_cnt {
	a_uint32_t  react_out_profile_cnt:32;
};

union react_out_profile_cnt_u {
	a_uint32_t val;
	struct react_out_profile_cnt bf;
};

/*[register] REACT_IN_PROFILE_CNT*/
#define REACT_IN_PROFILE_CNT
#define REACT_IN_PROFILE_CNT_ADDRESS 0x7e4
#define REACT_IN_PROFILE_CNT_NUM     40
#define REACT_IN_PROFILE_CNT_INC     0x4
#define REACT_IN_PROFILE_CNT_TYPE    REG_TYPE_RW
#define REACT_IN_PROFILE_CNT_DEFAULT 0x0
	/*[field] REACT_IN_PROFILE_CNT*/
	#define REACT_IN_PROFILE_CNT_REACT_IN_PROFILE_CNT
	#define REACT_IN_PROFILE_CNT_REACT_IN_PROFILE_CNT_OFFSET  0
	#define REACT_IN_PROFILE_CNT_REACT_IN_PROFILE_CNT_LEN     32
	#define REACT_IN_PROFILE_CNT_REACT_IN_PROFILE_CNT_DEFAULT 0x0

struct react_in_profile_cnt {
	a_uint32_t  react_in_profile_cnt:32;
};

union react_in_profile_cnt_u {
	a_uint32_t val;
	struct react_in_profile_cnt bf;
};

/*[register] GRP_OUT_PROFILE_CNT*/
#define GRP_OUT_PROFILE_CNT
#define GRP_OUT_PROFILE_CNT_ADDRESS 0x884
#define GRP_OUT_PROFILE_CNT_NUM     4
#define GRP_OUT_PROFILE_CNT_INC     0x4
#define GRP_OUT_PROFILE_CNT_TYPE    REG_TYPE_RW
#define GRP_OUT_PROFILE_CNT_DEFAULT 0x0
	/*[field] GRP_OUT_PROFILE_CNT*/
	#define GRP_OUT_PROFILE_CNT_GRP_OUT_PROFILE_CNT
	#define GRP_OUT_PROFILE_CNT_GRP_OUT_PROFILE_CNT_OFFSET  0
	#define GRP_OUT_PROFILE_CNT_GRP_OUT_PROFILE_CNT_LEN     32
	#define GRP_OUT_PROFILE_CNT_GRP_OUT_PROFILE_CNT_DEFAULT 0x0

struct grp_out_profile_cnt {
	a_uint32_t  grp_out_profile_cnt:32;
};

union grp_out_profile_cnt_u {
	a_uint32_t val;
	struct grp_out_profile_cnt bf;
};

/*[register] GRP_IN_PROFILE_CNT*/
#define GRP_IN_PROFILE_CNT
#define GRP_IN_PROFILE_CNT_ADDRESS 0x894
#define GRP_IN_PROFILE_CNT_NUM     4
#define GRP_IN_PROFILE_CNT_INC     0x4
#define GRP_IN_PROFILE_CNT_TYPE    REG_TYPE_RW
#define GRP_IN_PROFILE_CNT_DEFAULT 0x0
	/*[field] GRP_IN_PROFILE_CNT*/
	#define GRP_IN_PROFILE_CNT_GRP_IN_PROFILE_CNT
	#define GRP_IN_PROFILE_CNT_GRP_IN_PROFILE_CNT_OFFSET  0
	#define GRP_IN_PROFILE_CNT_GRP_IN_PROFILE_CNT_LEN     32
	#define GRP_IN_PROFILE_CNT_GRP_IN_PROFILE_CNT_DEFAULT 0x0

struct grp_in_profile_cnt {
	a_uint32_t  grp_in_profile_cnt:32;
};

union grp_in_profile_cnt_u {
	a_uint32_t val;
	struct grp_in_profile_cnt bf;
};

/*[register] TOT_REACT_OUT_PROFILE_CNT*/
#define TOT_REACT_OUT_PROFILE_CNT
#define TOT_REACT_OUT_PROFILE_CNT_ADDRESS 0x8a4
#define TOT_REACT_OUT_PROFILE_CNT_NUM     1
#define TOT_REACT_OUT_PROFILE_CNT_INC     0x4
#define TOT_REACT_OUT_PROFILE_CNT_TYPE    REG_TYPE_RW
#define TOT_REACT_OUT_PROFILE_CNT_DEFAULT 0x0
	/*[field] TOT_REACT_OUT_PROFILE_CNT*/
	#define TOT_REACT_OUT_PROFILE_CNT_TOT_REACT_OUT_PROFILE_CNT
	#define TOT_REACT_OUT_PROFILE_CNT_TOT_REACT_OUT_PROFILE_CNT_OFFSET  0
	#define TOT_REACT_OUT_PROFILE_CNT_TOT_REACT_OUT_PROFILE_CNT_LEN     32
	#define TOT_REACT_OUT_PROFILE_CNT_TOT_REACT_OUT_PROFILE_CNT_DEFAULT 0x0

struct tot_react_out_profile_cnt {
	a_uint32_t  tot_react_out_profile_cnt:32;
};

union tot_react_out_profile_cnt_u {
	a_uint32_t val;
	struct tot_react_out_profile_cnt bf;
};

/*[register] TOT_REACT_IN_PROFILE_CNT*/
#define TOT_REACT_IN_PROFILE_CNT
#define TOT_REACT_IN_PROFILE_CNT_ADDRESS 0x8a8
#define TOT_REACT_IN_PROFILE_CNT_NUM     1
#define TOT_REACT_IN_PROFILE_CNT_INC     0x4
#define TOT_REACT_IN_PROFILE_CNT_TYPE    REG_TYPE_RW
#define TOT_REACT_IN_PROFILE_CNT_DEFAULT 0x0
	/*[field] TOT_REACT_IN_PROFILE_CNT*/
	#define TOT_REACT_IN_PROFILE_CNT_TOT_REACT_IN_PROFILE_CNT
	#define TOT_REACT_IN_PROFILE_CNT_TOT_REACT_IN_PROFILE_CNT_OFFSET  0
	#define TOT_REACT_IN_PROFILE_CNT_TOT_REACT_IN_PROFILE_CNT_LEN     32
	#define TOT_REACT_IN_PROFILE_CNT_TOT_REACT_IN_PROFILE_CNT_DEFAULT 0x0

struct tot_react_in_profile_cnt {
	a_uint32_t  tot_react_in_profile_cnt:32;
};

union tot_react_in_profile_cnt_u {
	a_uint32_t val;
	struct tot_react_in_profile_cnt bf;
};

/*[table] PORT_FC_CFG*/
#define PORT_FC_CFG
#define PORT_FC_CFG_ADDRESS 0x1000
#define PORT_FC_CFG_NUM     40
#define PORT_FC_CFG_INC     0x10
#define PORT_FC_CFG_TYPE    REG_TYPE_RW
#define PORT_FC_CFG_DEFAULT 0x0
	/*[field] PORT_REACT_LIMIT*/
	#define PORT_FC_CFG_PORT_REACT_LIMIT
	#define PORT_FC_CFG_PORT_REACT_LIMIT_OFFSET  0
	#define PORT_FC_CFG_PORT_REACT_LIMIT_LEN     10
	#define PORT_FC_CFG_PORT_REACT_LIMIT_DEFAULT 0x0
	/*[field] PORT_RESUME_FLOOR_TH*/
	#define PORT_FC_CFG_PORT_RESUME_FLOOR_TH
	#define PORT_FC_CFG_PORT_RESUME_FLOOR_TH_OFFSET  10
	#define PORT_FC_CFG_PORT_RESUME_FLOOR_TH_LEN     9
	#define PORT_FC_CFG_PORT_RESUME_FLOOR_TH_DEFAULT 0x0
	/*[field] PORT_RESUME_OFFSET*/
	#define PORT_FC_CFG_PORT_RESUME_OFFSET
	#define PORT_FC_CFG_PORT_RESUME_OFFSET_OFFSET  19
	#define PORT_FC_CFG_PORT_RESUME_OFFSET_LEN     12
	#define PORT_FC_CFG_PORT_RESUME_OFFSET_DEFAULT 0x0
	/*[field] PORT_SHARED_CEILING*/
	#define PORT_FC_CFG_PORT_SHARED_CEILING
	#define PORT_FC_CFG_PORT_SHARED_CEILING_OFFSET  31
	#define PORT_FC_CFG_PORT_SHARED_CEILING_LEN     12
	#define PORT_FC_CFG_PORT_SHARED_CEILING_DEFAULT 0x0
	/*[field] PORT_SHARED_WEIGHT*/
	#define PORT_FC_CFG_PORT_SHARED_WEIGHT
	#define PORT_FC_CFG_PORT_SHARED_WEIGHT_OFFSET  43
	#define PORT_FC_CFG_PORT_SHARED_WEIGHT_LEN     3
	#define PORT_FC_CFG_PORT_SHARED_WEIGHT_DEFAULT 0x0
	/*[field] PORT_SHARED_DYNAMIC*/
	#define PORT_FC_CFG_PORT_SHARED_DYNAMIC
	#define PORT_FC_CFG_PORT_SHARED_DYNAMIC_OFFSET  46
	#define PORT_FC_CFG_PORT_SHARED_DYNAMIC_LEN     1
	#define PORT_FC_CFG_PORT_SHARED_DYNAMIC_DEFAULT 0x0
	/*[field] PORT_PRE_ALLOC*/
	#define PORT_FC_CFG_PORT_PRE_ALLOC
	#define PORT_FC_CFG_PORT_PRE_ALLOC_OFFSET  47
	#define PORT_FC_CFG_PORT_PRE_ALLOC_LEN     12
	#define PORT_FC_CFG_PORT_PRE_ALLOC_DEFAULT 0x0

struct port_fc_cfg {
	a_uint32_t  port_react_limit:10;
	a_uint32_t  port_resume_floor_th:9;
	a_uint32_t  port_resume_offset:12;
	a_uint32_t  port_shared_ceiling_0:1;
	a_uint32_t  port_shared_ceiling_1:11;
	a_uint32_t  port_shared_weight:3;
	a_uint32_t  port_shared_dynamic:1;
	a_uint32_t  port_pre_alloc:12;
	a_uint32_t  _reserved0:5;
};

union port_fc_cfg_u {
	a_uint32_t val[2];
	struct port_fc_cfg bf;
};

/*[table] LLM*/
#define LLM
#define LLM_ADDRESS 0x10000
#define LLM_NUM     3072
#define LLM_INC     0x10
#define LLM_TYPE    REG_TYPE_RW
#define LLM_DEFAULT 0x0
	/*[field] NXT_PTR*/
	#define LLM_NXT_PTR
	#define LLM_NXT_PTR_OFFSET  0
	#define LLM_NXT_PTR_LEN     12
	#define LLM_NXT_PTR_DEFAULT 0x0
	/*[field] EOP*/
	#define LLM_EOP
	#define LLM_EOP_OFFSET  12
	#define LLM_EOP_LEN     1
	#define LLM_EOP_DEFAULT 0x0

struct llm {
	a_uint32_t  nxt_ptr:12;
	a_uint32_t  eop:1;
	a_uint32_t  _reserved0:19;
};

union llm_u {
	a_uint32_t val;
	struct llm bf;
};

/*[table] RCM*/
#define RCM
#define RCM_ADDRESS 0x20000
#define RCM_NUM     3072
#define RCM_INC     0x10
#define RCM_TYPE    REG_TYPE_RW
#define RCM_DEFAULT 0x0
	/*[field] REF_CNT*/
	#define RCM_REF_CNT
	#define RCM_REF_CNT_OFFSET  0
	#define RCM_REF_CNT_LEN     4
	#define RCM_REF_CNT_DEFAULT 0x0

struct rcm {
	a_uint32_t  ref_cnt:4;
	a_uint32_t  _reserved0:28;
};

union rcm_u {
	a_uint32_t val;
	struct rcm bf;
};

/*[table] DM*/
#define DM
#define DM_ADDRESS 0x100000
#define DM_NUM     12288
#define DM_INC     0x40
#define DM_TYPE    REG_TYPE_RW
#define DM_DEFAULT 0x0
	/*[field] PKT_DATA*/
	#define DM_PKT_DATA
	#define DM_PKT_DATA_OFFSET  0
	#define DM_PKT_DATA_LEN     512
	#define DM_PKT_DATA_DEFAULT 0x0

struct dm {
	a_uint32_t  pkt_data_0:32;
	a_uint32_t  pkt_data_1:32;
	a_uint32_t  pkt_data_2:32;
	a_uint32_t  pkt_data_3:32;
	a_uint32_t  pkt_data_4:32;
	a_uint32_t  pkt_data_5:32;
	a_uint32_t  pkt_data_6:32;
	a_uint32_t  pkt_data_7:32;
	a_uint32_t  pkt_data_8:32;
	a_uint32_t  pkt_data_9:32;
	a_uint32_t  pkt_data_10:32;
	a_uint32_t  pkt_data_11:32;
	a_uint32_t  pkt_data_12:32;
	a_uint32_t  pkt_data_13:32;
	a_uint32_t  pkt_data_14:32;
	a_uint32_t  pkt_data_15:32;
};

union dm_u {
	a_uint32_t val[16];
	struct dm bf;
};

#endif
