/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HTTPPE_PORTVLAN_REG_H_
#define _HTTPPE_PORTVLAN_REG_H_

/*[register] EG_BRIDGE_CONFIG*/
#define EG_BRIDGE_CONFIG
#define EG_BRIDGE_CONFIG_ADDRESS 0x84
#define EG_BRIDGE_CONFIG_NUM     1
#define EG_BRIDGE_CONFIG_INC     0x4
#define EG_BRIDGE_CONFIG_TYPE    REG_TYPE_RW
#define EG_BRIDGE_CONFIG_DEFAULT 0x7cfd400
	/*[field] BRIDGE_TYPE*/
	#define EG_BRIDGE_CONFIG_BRIDGE_TYPE
	#define EG_BRIDGE_CONFIG_BRIDGE_TYPE_OFFSET  0
	#define EG_BRIDGE_CONFIG_BRIDGE_TYPE_LEN     1
	#define EG_BRIDGE_CONFIG_BRIDGE_TYPE_DEFAULT 0x0
	/*[field] PKT_L2_EDIT_EN*/
	#define EG_BRIDGE_CONFIG_PKT_L2_EDIT_EN
	#define EG_BRIDGE_CONFIG_PKT_L2_EDIT_EN_OFFSET  1
	#define EG_BRIDGE_CONFIG_PKT_L2_EDIT_EN_LEN     1
	#define EG_BRIDGE_CONFIG_PKT_L2_EDIT_EN_DEFAULT 0x0
	/*[field] QUEUE_CNT_EN*/
	#define EG_BRIDGE_CONFIG_QUEUE_CNT_EN
	#define EG_BRIDGE_CONFIG_QUEUE_CNT_EN_OFFSET  2
	#define EG_BRIDGE_CONFIG_QUEUE_CNT_EN_LEN     1
	#define EG_BRIDGE_CONFIG_QUEUE_CNT_EN_DEFAULT 0x0
	/*[field] PPE_EIP_RSV_W4_3130*/
	#define EG_BRIDGE_CONFIG_PPE_EIP_RSV_W4_3130
	#define EG_BRIDGE_CONFIG_PPE_EIP_RSV_W4_3130_OFFSET  8
	#define EG_BRIDGE_CONFIG_PPE_EIP_RSV_W4_3130_LEN     2
	#define EG_BRIDGE_CONFIG_PPE_EIP_RSV_W4_3130_DEFAULT 0x0
	/*[field] FIELD_UPDATE_ENABLE*/
	#define EG_BRIDGE_CONFIG_FIELD_UPDATE_ENABLE
	#define EG_BRIDGE_CONFIG_FIELD_UPDATE_ENABLE_OFFSET  10
	#define EG_BRIDGE_CONFIG_FIELD_UPDATE_ENABLE_LEN     1
	#define EG_BRIDGE_CONFIG_FIELD_UPDATE_ENABLE_DEFAULT 0x1
	/*[field] PASSTHROUGH_CPU_CODE0*/
	#define EG_BRIDGE_CONFIG_PASSTHROUGH_CPU_CODE0
	#define EG_BRIDGE_CONFIG_PASSTHROUGH_CPU_CODE0_OFFSET  11
	#define EG_BRIDGE_CONFIG_PASSTHROUGH_CPU_CODE0_LEN     8
	#define EG_BRIDGE_CONFIG_PASSTHROUGH_CPU_CODE0_DEFAULT 0xfa
	/*[field] PASSTHROUGH_CPU_CODE1*/
	#define EG_BRIDGE_CONFIG_PASSTHROUGH_CPU_CODE1
	#define EG_BRIDGE_CONFIG_PASSTHROUGH_CPU_CODE1_OFFSET  19
	#define EG_BRIDGE_CONFIG_PASSTHROUGH_CPU_CODE1_LEN     8
	#define EG_BRIDGE_CONFIG_PASSTHROUGH_CPU_CODE1_DEFAULT 0xf9

struct eg_bridge_config {
	a_uint32_t  bridge_type:1;
	a_uint32_t  pkt_l2_edit_en:1;
	a_uint32_t  queue_cnt_en:1;
	a_uint32_t  _reserved0:5;
	a_uint32_t  ppe_eip_rsv_w4_3130:2;
	a_uint32_t  field_update_enable:1;
	a_uint32_t  passthrough_cpu_code0:8;
	a_uint32_t  passthrough_cpu_code1:8;
	a_uint32_t  _reserved1:5;
};

union eg_bridge_config_u {
	a_uint32_t val;
	struct eg_bridge_config bf;
};

#endif
