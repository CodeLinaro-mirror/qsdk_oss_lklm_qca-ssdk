/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HTTPPE_CROSSCHIP_REG_H_
#define _HTTPPE_CROSSCHIP_REG_H_

/*[register] CROSSCHIP_QUEUE_CTRL*/
#define CROSSCHIP_QUEUE_CTRL
#define CROSSCHIP_QUEUE_CTRL_ADDRESS 0x100
#define CROSSCHIP_QUEUE_CTRL_NUM     8
#define CROSSCHIP_QUEUE_CTRL_INC     0x4
#define CROSSCHIP_QUEUE_CTRL_TYPE    REG_TYPE_RW
#define CROSSCHIP_QUEUE_CTRL_DEFAULT 0x0
	/*[field] CROSSCHIP_QUEUE_EN_0*/
	#define CROSSCHIP_QUEUE_CTRL_CROSSCHIP_QUEUE_EN_0
	#define CROSSCHIP_QUEUE_CTRL_CROSSCHIP_QUEUE_EN_0_OFFSET  0
	#define CROSSCHIP_QUEUE_CTRL_CROSSCHIP_QUEUE_EN_0_LEN     16
	#define CROSSCHIP_QUEUE_CTRL_CROSSCHIP_QUEUE_EN_0_DEFAULT 0x0
	/*[field] CROSSCHIP_QUEUE_EN_1*/
	#define CROSSCHIP_QUEUE_CTRL_CROSSCHIP_QUEUE_EN_1
	#define CROSSCHIP_QUEUE_CTRL_CROSSCHIP_QUEUE_EN_1_OFFSET  16
	#define CROSSCHIP_QUEUE_CTRL_CROSSCHIP_QUEUE_EN_1_LEN     16
	#define CROSSCHIP_QUEUE_CTRL_CROSSCHIP_QUEUE_EN_1_DEFAULT 0x0

struct crosschip_queue_ctrl {
	a_uint32_t  crosschip_queue_en_0:16;
	a_uint32_t  crosschip_queue_en_1:16;
};

union crosschip_queue_ctrl_u {
	a_uint32_t val;
	struct crosschip_queue_ctrl bf;
};

/*[register] CROSSCHIP_BP_CTRL*/
#define CROSSCHIP_BP_CTRL
#define CROSSCHIP_BP_CTRL_ADDRESS 0x120
#define CROSSCHIP_BP_CTRL_NUM     1
#define CROSSCHIP_BP_CTRL_INC     0x4
#define CROSSCHIP_BP_CTRL_TYPE    REG_TYPE_RW
#define CROSSCHIP_BP_CTRL_DEFAULT 0x0
	/*[field] CROSSCHIP_BP_EN*/
	#define CROSSCHIP_BP_CTRL_CROSSCHIP_BP_EN
	#define CROSSCHIP_BP_CTRL_CROSSCHIP_BP_EN_OFFSET  0
	#define CROSSCHIP_BP_CTRL_CROSSCHIP_BP_EN_LEN     1
	#define CROSSCHIP_BP_CTRL_CROSSCHIP_BP_EN_DEFAULT 0x0
	/*[field] CROSSCHIP_BP_MODE*/
	#define CROSSCHIP_BP_CTRL_CROSSCHIP_BP_MODE
	#define CROSSCHIP_BP_CTRL_CROSSCHIP_BP_MODE_OFFSET  1
	#define CROSSCHIP_BP_CTRL_CROSSCHIP_BP_MODE_LEN     1
	#define CROSSCHIP_BP_CTRL_CROSSCHIP_BP_MODE_DEFAULT 0x0

struct crosschip_bp_ctrl {
	a_uint32_t  crosschip_bp_en:1;
	a_uint32_t  crosschip_bp_mode:1;
	a_uint32_t  _reserved0:30;
};

union crosschip_bp_ctrl_u {
	a_uint32_t val;
	struct crosschip_bp_ctrl bf;
};

/*[register] VP_BP_THRES*/
#define VP_BP_THRES
#define VP_BP_THRES_ADDRESS 0xa0
#define VP_BP_THRES_NUM     16
#define VP_BP_THRES_INC     0x4
#define VP_BP_THRES_TYPE    REG_TYPE_RW
#define VP_BP_THRES_DEFAULT 0x80400080
	/*[field] VP_BP_XOFF*/
	#define VP_BP_THRES_VP_BP_XOFF
	#define VP_BP_THRES_VP_BP_XOFF_OFFSET  0
	#define VP_BP_THRES_VP_BP_XOFF_LEN     12
	#define VP_BP_THRES_VP_BP_XOFF_DEFAULT 0x80
	/*[field] VP_BP_XON*/
	#define VP_BP_THRES_VP_BP_XON
	#define VP_BP_THRES_VP_BP_XON_OFFSET  16
	#define VP_BP_THRES_VP_BP_XON_LEN     12
	#define VP_BP_THRES_VP_BP_XON_DEFAULT 0x40
	/*[field] VP_BP_EN*/
	#define VP_BP_THRES_VP_BP_EN
	#define VP_BP_THRES_VP_BP_EN_OFFSET  31
	#define VP_BP_THRES_VP_BP_EN_LEN     1
	#define VP_BP_THRES_VP_BP_EN_DEFAULT 0x1

struct vp_bp_thres {
	a_uint32_t  vp_bp_xoff:12;
	a_uint32_t  _reserved0:4;
	a_uint32_t  vp_bp_xon:12;
	a_uint32_t  _reserved1:3;
	a_uint32_t  vp_bp_en:1;
};

union vp_bp_thres_u {
	a_uint32_t val;
	struct vp_bp_thres bf;
};

/*[register] VP_BP_CNT*/
#define VP_BP_CNT
#define VP_BP_CNT_ADDRESS 0xe0
#define VP_BP_CNT_NUM     8
#define VP_BP_CNT_INC     0x4
#define VP_BP_CNT_TYPE    REG_TYPE_RO
#define VP_BP_CNT_DEFAULT 0x0
	/*[field] VP_BP_CNT_0*/
	#define VP_BP_CNT_VP_BP_CNT_0
	#define VP_BP_CNT_VP_BP_CNT_0_OFFSET  0
	#define VP_BP_CNT_VP_BP_CNT_0_LEN     12
	#define VP_BP_CNT_VP_BP_CNT_0_DEFAULT 0x0
	/*[field] VP_BP_CNT_1*/
	#define VP_BP_CNT_VP_BP_CNT_1
	#define VP_BP_CNT_VP_BP_CNT_1_OFFSET  16
	#define VP_BP_CNT_VP_BP_CNT_1_LEN     12
	#define VP_BP_CNT_VP_BP_CNT_1_DEFAULT 0x0

struct vp_bp_cnt {
	a_uint32_t  vp_bp_cnt_0:12;
	a_uint32_t  _reserved0:4;
	a_uint32_t  vp_bp_cnt_1:12;
	a_uint32_t  _reserved1:4;
};

union vp_bp_cnt_u {
	a_uint32_t val;
	struct vp_bp_cnt bf;
};

#endif
