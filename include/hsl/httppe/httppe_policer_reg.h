/*
 * Copyright (c) 2016-2017, 2021, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HTTPPE_POLICER_REG_H_
#define _HTTPPE_POLICER_REG_H_

/*[table] DROP_CPU_CNT_TBL*/
#define DROP_CPU_CNT_TBL
#define DROP_CPU_CNT_TBL_ADDRESS 0x60000
#define DROP_CPU_CNT_TBL_NUM     1408
#define DROP_CPU_CNT_TBL_INC     0x10
#define DROP_CPU_CNT_TBL_TYPE    REG_TYPE_RW
#define DROP_CPU_CNT_TBL_DEFAULT 0x0
	/*[field] PKT_CNT*/
	#define DROP_CPU_CNT_TBL_PKT_CNT
	#define DROP_CPU_CNT_TBL_PKT_CNT_OFFSET  0
	#define DROP_CPU_CNT_TBL_PKT_CNT_LEN     32
	#define DROP_CPU_CNT_TBL_PKT_CNT_DEFAULT 0x0
	/*[field] BYTE_CNT*/
	#define DROP_CPU_CNT_TBL_BYTE_CNT
	#define DROP_CPU_CNT_TBL_BYTE_CNT_OFFSET  32
	#define DROP_CPU_CNT_TBL_BYTE_CNT_LEN     40
	#define DROP_CPU_CNT_TBL_BYTE_CNT_DEFAULT 0x0

struct drop_cpu_cnt_tbl {
	a_uint32_t  pkt_cnt:32;
	a_uint32_t  byte_cnt_0:32;
	a_uint32_t  byte_cnt_1:8;
	a_uint32_t  _reserved0:24;
};

union drop_cpu_cnt_tbl_u {
	a_uint32_t val[3];
	struct drop_cpu_cnt_tbl bf;
};

#endif
