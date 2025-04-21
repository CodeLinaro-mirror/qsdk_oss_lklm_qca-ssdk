/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _JHPPE_QM_REG_H_
#define _JHPPE_QM_REG_H_

/*[register] MC_ENQ_CTRL*/
#define MC_ENQ_CTRL
#define MC_ENQ_CTRL_ADDRESS 0xa80
#define MC_ENQ_CTRL_NUM     1
#define MC_ENQ_CTRL_INC     0x4
#define MC_ENQ_CTRL_TYPE    REG_TYPE_RW
#define MC_ENQ_CTRL_DEFAULT 0x10
	/*[field] UC_PORT_ID*/
	#define MC_ENQ_CTRL_UC_PORT_ID
	#define MC_ENQ_CTRL_UC_PORT_ID_OFFSET  0
	#define MC_ENQ_CTRL_UC_PORT_ID_LEN     4
	#define MC_ENQ_CTRL_UC_PORT_ID_DEFAULT 0x0
	/*[field] UC_ENQ_EN*/
	#define MC_ENQ_CTRL_UC_ENQ_EN
	#define MC_ENQ_CTRL_UC_ENQ_EN_OFFSET  4
	#define MC_ENQ_CTRL_UC_ENQ_EN_LEN     1
	#define MC_ENQ_CTRL_UC_ENQ_EN_DEFAULT 0x1
	/*[field] DOT1P_PON_VP*/
	#define MC_ENQ_CTRL_DOT1P_PON_VP
	#define MC_ENQ_CTRL_DOT1P_PON_VP_OFFSET  5
	#define MC_ENQ_CTRL_DOT1P_PON_VP_LEN     8
	#define MC_ENQ_CTRL_DOT1P_PON_VP_DEFAULT 0x0

struct mc_enq_ctrl {
	a_uint32_t  uc_port_id:4;
	a_uint32_t  uc_enq_en:1;
	a_uint32_t  dot1p_pon_vp:8;
	a_uint32_t  _reserved0:19;
};

union mc_enq_ctrl_u {
	a_uint32_t val;
	struct mc_enq_ctrl bf;
};

/*[register] ENQ_CTRL*/
#define ENQ_CTRL
#define ENQ_CTRL_ADDRESS 0x90
#define ENQ_CTRL_NUM     1
#define ENQ_CTRL_INC     0x4
#define ENQ_CTRL_TYPE    REG_TYPE_RW
#define ENQ_CTRL_DEFAULT 0x3f37fb01
	/*[field] UC_ENQ_EN*/
	#define ENQ_CTRL_UC_ENQ_EN
	#define ENQ_CTRL_UC_ENQ_EN_OFFSET  0
	#define ENQ_CTRL_UC_ENQ_EN_LEN     1
	#define ENQ_CTRL_UC_ENQ_EN_DEFAULT 0x1
	/*[field] QUEUE_MAP_RULE_EN*/
	#define ENQ_CTRL_QUEUE_MAP_RULE_EN
	#define ENQ_CTRL_QUEUE_MAP_RULE_EN_OFFSET  1
	#define ENQ_CTRL_QUEUE_MAP_RULE_EN_LEN     1
	#define ENQ_CTRL_QUEUE_MAP_RULE_EN_DEFAULT 0x0
	/*[field] PASS_THROUGH0_SRC_PROFILE_EG_EN*/
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE_EG_EN
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE_EG_EN_OFFSET  4
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE_EG_EN_LEN     1
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE_EG_EN_DEFAULT 0x0
	/*[field] PASS_THROUGH1_SRC_PROFILE_EG_EN*/
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE_EG_EN
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE_EG_EN_OFFSET  5
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE_EG_EN_LEN     1
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE_EG_EN_DEFAULT 0x0
	/*[field] PASS_THROUGH2_SRC_PROFILE_EG_EN*/
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE_EG_EN
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE_EG_EN_OFFSET  6
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE_EG_EN_LEN     1
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE_EG_EN_DEFAULT 0x0
	/*[field] PASS_THROUGH3_SRC_PROFILE_EG_EN*/
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE_EG_EN
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE_EG_EN_OFFSET  7
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE_EG_EN_LEN     1
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE_EG_EN_DEFAULT 0x0
	/*[field] QID_MISMATCH_ENQ_CPU_CODE*/
	#define ENQ_CTRL_QID_MISMATCH_ENQ_CPU_CODE
	#define ENQ_CTRL_QID_MISMATCH_ENQ_CPU_CODE_OFFSET  8
	#define ENQ_CTRL_QID_MISMATCH_ENQ_CPU_CODE_LEN     8
	#define ENQ_CTRL_QID_MISMATCH_ENQ_CPU_CODE_DEFAULT 0xfb
	/*[field] PASS_THROUGH0_DIREC_ENQ_DIS*/
	#define ENQ_CTRL_PASS_THROUGH0_DIREC_ENQ_DIS
	#define ENQ_CTRL_PASS_THROUGH0_DIREC_ENQ_DIS_OFFSET  16
	#define ENQ_CTRL_PASS_THROUGH0_DIREC_ENQ_DIS_LEN     1
	#define ENQ_CTRL_PASS_THROUGH0_DIREC_ENQ_DIS_DEFAULT 0x1
	/*[field] PASS_THROUGH1_DIREC_ENQ_DIS*/
	#define ENQ_CTRL_PASS_THROUGH1_DIREC_ENQ_DIS
	#define ENQ_CTRL_PASS_THROUGH1_DIREC_ENQ_DIS_OFFSET  17
	#define ENQ_CTRL_PASS_THROUGH1_DIREC_ENQ_DIS_LEN     1
	#define ENQ_CTRL_PASS_THROUGH1_DIREC_ENQ_DIS_DEFAULT 0x1
	/*[field] PASS_THROUGH2_DIREC_ENQ_DIS*/
	#define ENQ_CTRL_PASS_THROUGH2_DIREC_ENQ_DIS
	#define ENQ_CTRL_PASS_THROUGH2_DIREC_ENQ_DIS_OFFSET  18
	#define ENQ_CTRL_PASS_THROUGH2_DIREC_ENQ_DIS_LEN     1
	#define ENQ_CTRL_PASS_THROUGH2_DIREC_ENQ_DIS_DEFAULT 0x1
	/*[field] PASS_THROUGH3_DIREC_ENQ_DIS*/
	#define ENQ_CTRL_PASS_THROUGH3_DIREC_ENQ_DIS
	#define ENQ_CTRL_PASS_THROUGH3_DIREC_ENQ_DIS_OFFSET  19
	#define ENQ_CTRL_PASS_THROUGH3_DIREC_ENQ_DIS_LEN     1
	#define ENQ_CTRL_PASS_THROUGH3_DIREC_ENQ_DIS_DEFAULT 0x0
	/*[field] PASS_THROUGH0_SRC_PROFILE_EN*/
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE_EN
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE_EN_OFFSET  20
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE_EN_LEN     1
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE_EN_DEFAULT 0x1
	/*[field] PASS_THROUGH1_SRC_PROFILE_EN*/
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE_EN
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE_EN_OFFSET  21
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE_EN_LEN     1
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE_EN_DEFAULT 0x1
	/*[field] PASS_THROUGH2_SRC_PROFILE_EN*/
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE_EN
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE_EN_OFFSET  22
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE_EN_LEN     1
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE_EN_DEFAULT 0x0
	/*[field] PASS_THROUGH3_SRC_PROFILE_EN*/
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE_EN
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE_EN_OFFSET  23
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE_EN_LEN     1
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE_EN_DEFAULT 0x0
	/*[field] PASS_THROUGH0_SRC_PROFILE*/
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE_OFFSET  24
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE_LEN     2
	#define ENQ_CTRL_PASS_THROUGH0_SRC_PROFILE_DEFAULT 0x3
	/*[field] PASS_THROUGH1_SRC_PROFILE*/
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE_OFFSET  26
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE_LEN     2
	#define ENQ_CTRL_PASS_THROUGH1_SRC_PROFILE_DEFAULT 0x3
	/*[field] PASS_THROUGH2_SRC_PROFILE*/
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE_OFFSET  28
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE_LEN     2
	#define ENQ_CTRL_PASS_THROUGH2_SRC_PROFILE_DEFAULT 0x3
	/*[field] PASS_THROUGH3_SRC_PROFILE*/
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE_OFFSET  30
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE_LEN     2
	#define ENQ_CTRL_PASS_THROUGH3_SRC_PROFILE_DEFAULT 0x0

struct enq_ctrl {
	a_uint32_t  uc_enq_en:1;
	a_uint32_t  queue_map_rule_en:1;
	a_uint32_t  _reserved0:2;
	a_uint32_t  pass_through0_src_profile_eg_en:1;
	a_uint32_t  pass_through1_src_profile_eg_en:1;
	a_uint32_t  pass_through2_src_profile_eg_en:1;
	a_uint32_t  pass_through3_src_profile_eg_en:1;
	a_uint32_t  qid_mismatch_enq_cpu_code:8;
	a_uint32_t  pass_through0_direc_enq_dis:1;
	a_uint32_t  pass_through1_direc_enq_dis:1;
	a_uint32_t  pass_through2_direc_enq_dis:1;
	a_uint32_t  pass_through3_direc_enq_dis:1;
	a_uint32_t  pass_through0_src_profile_en:1;
	a_uint32_t  pass_through1_src_profile_en:1;
	a_uint32_t  pass_through2_src_profile_en:1;
	a_uint32_t  pass_through3_src_profile_en:1;
	a_uint32_t  pass_through0_src_profile:2;
	a_uint32_t  pass_through1_src_profile:2;
	a_uint32_t  pass_through2_src_profile:2;
	a_uint32_t  pass_through3_src_profile:2;
};

union enq_ctrl_u {
	a_uint32_t val;
	struct enq_ctrl bf;
};

/*[register] ENQ_CTRL_EXT*/
#define ENQ_CTRL_EXT
#define ENQ_CTRL_EXT_ADDRESS 0x94
#define ENQ_CTRL_EXT_NUM     1
#define ENQ_CTRL_EXT_INC     0x4
#define ENQ_CTRL_EXT_TYPE    REG_TYPE_RW
#define ENQ_CTRL_EXT_DEFAULT 0xfcfcfc00
	/*[field] CPU_CODE_EN*/
	#define ENQ_CTRL_EXT_CPU_CODE_EN
	#define ENQ_CTRL_EXT_CPU_CODE_EN_OFFSET  0
	#define ENQ_CTRL_EXT_CPU_CODE_EN_LEN     4
	#define ENQ_CTRL_EXT_CPU_CODE_EN_DEFAULT 0x0
	/*[field] RSV*/
	#define ENQ_CTRL_EXT_RSV
	#define ENQ_CTRL_EXT_RSV_OFFSET  4
	#define ENQ_CTRL_EXT_RSV_LEN     4
	#define ENQ_CTRL_EXT_RSV_DEFAULT 0x0
	/*[field] DROP_CPU_CODE*/
	#define ENQ_CTRL_EXT_DROP_CPU_CODE
	#define ENQ_CTRL_EXT_DROP_CPU_CODE_OFFSET  8
	#define ENQ_CTRL_EXT_DROP_CPU_CODE_LEN     8
	#define ENQ_CTRL_EXT_DROP_CPU_CODE_DEFAULT 0xfc
	/*[field] TRAP_CPU_CODE*/
	#define ENQ_CTRL_EXT_TRAP_CPU_CODE
	#define ENQ_CTRL_EXT_TRAP_CPU_CODE_OFFSET  16
	#define ENQ_CTRL_EXT_TRAP_CPU_CODE_LEN     8
	#define ENQ_CTRL_EXT_TRAP_CPU_CODE_DEFAULT 0xfc
	/*[field] MC_CPU_CODE*/
	#define ENQ_CTRL_EXT_MC_CPU_CODE
	#define ENQ_CTRL_EXT_MC_CPU_CODE_OFFSET  24
	#define ENQ_CTRL_EXT_MC_CPU_CODE_LEN     8
	#define ENQ_CTRL_EXT_MC_CPU_CODE_DEFAULT 0xfc

struct enq_ctrl_ext {
	a_uint32_t  cpu_code_en:4;
	a_uint32_t  rsv:4;
	a_uint32_t  drop_cpu_code:8;
	a_uint32_t  trap_cpu_code:8;
	a_uint32_t  mc_cpu_code:8;
};

union enq_ctrl_ext_u {
	a_uint32_t val;
	struct enq_ctrl_ext bf;
};

/*[table] UCAST_QUEUE_MAP_RULE_TBL*/
#define UCAST_QUEUE_MAP_RULE_TBL
#define UCAST_QUEUE_MAP_RULE_TBL_ADDRESS 0x2000
#define UCAST_QUEUE_MAP_RULE_TBL_NUM     64
#define UCAST_QUEUE_MAP_RULE_TBL_INC     0x10
#define UCAST_QUEUE_MAP_RULE_TBL_TYPE    REG_TYPE_RW
#define UCAST_QUEUE_MAP_RULE_TBL_DEFAULT 0x0
	/*[field] SRC_PROFILE_MAP*/
	#define UCAST_QUEUE_MAP_RULE_TBL_SRC_PROFILE_MAP
	#define UCAST_QUEUE_MAP_RULE_TBL_SRC_PROFILE_MAP_OFFSET  0
	#define UCAST_QUEUE_MAP_RULE_TBL_SRC_PROFILE_MAP_LEN     4
	#define UCAST_QUEUE_MAP_RULE_TBL_SRC_PROFILE_MAP_DEFAULT 0x0
	/*[field] PASS_THROUGH_MAP*/
	#define UCAST_QUEUE_MAP_RULE_TBL_PASS_THROUGH_MAP
	#define UCAST_QUEUE_MAP_RULE_TBL_PASS_THROUGH_MAP_OFFSET  4
	#define UCAST_QUEUE_MAP_RULE_TBL_PASS_THROUGH_MAP_LEN     4
	#define UCAST_QUEUE_MAP_RULE_TBL_PASS_THROUGH_MAP_DEFAULT 0x0
	/*[field] FIELD_0_MODE*/
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_MODE
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_MODE_OFFSET  8
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_MODE_LEN     1
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_MODE_DEFAULT 0x0
	/*[field] FIELD_0_TYPE_MAP reuse FIELD_0_MODE[0]*/
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_TYPE_MAP
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_TYPE_MAP_OFFSET  9
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_TYPE_MAP_LEN     4
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_TYPE_MAP_DEFAULT 0x0
	/*[field] FIELD_0_TYPE reuse FIELD_0_MODE[0]*/
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_TYPE
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_TYPE_OFFSET  9
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_TYPE_LEN     2
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_TYPE_DEFAULT 0x0
	/*[field] FIELD_0_INFO reuse FIELD_0_MODE[2]*/
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_INFO
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_INFO_OFFSET  11
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_INFO_LEN     8
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_INFO_DEFAULT 0x0
	/*[field] FIELD_0_INFO_HI reuse FIELD_0_MODE[2]*/
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_INFO_HI
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_INFO_HI_OFFSET  19
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_INFO_HI_LEN     8
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_0_INFO_HI_DEFAULT 0x0
	/*[field] FIELD_1_MODE*/
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_MODE
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_MODE_OFFSET  27
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_MODE_LEN     1
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_MODE_DEFAULT 0x0
	/*[field] FIELD_1_TYPE_MAP reuse FIELD_1_MODE[0]*/
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_TYPE_MAP
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_TYPE_MAP_OFFSET  28
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_TYPE_MAP_LEN     4
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_TYPE_MAP_DEFAULT 0x0
	/*[field] FIELD_1_TYPE reuse FIELD_1_MODE[2]*/
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_TYPE
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_TYPE_OFFSET  28
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_TYPE_LEN     2
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_TYPE_DEFAULT 0x0
	/*[field] FIELD_1_INFO reuse FIELD_1_MODE[0]*/
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_INFO
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_INFO_OFFSET  30
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_INFO_LEN     8
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_INFO_DEFAULT 0x0
	/*[field] FIELD_1_INFO_HI reuse FIELD_1_MODE[0]*/
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_INFO_HI
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_INFO_HI_OFFSET  38
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_INFO_HI_LEN     8
	#define UCAST_QUEUE_MAP_RULE_TBL_FIELD_1_INFO_HI_DEFAULT 0x0
	/*[field] INT_PRI_INCL*/
	#define UCAST_QUEUE_MAP_RULE_TBL_INT_PRI_INCL
	#define UCAST_QUEUE_MAP_RULE_TBL_INT_PRI_INCL_OFFSET  46
	#define UCAST_QUEUE_MAP_RULE_TBL_INT_PRI_INCL_LEN     1
	#define UCAST_QUEUE_MAP_RULE_TBL_INT_PRI_INCL_DEFAULT 0x0
	/*[field] INT_PRI*/
	#define UCAST_QUEUE_MAP_RULE_TBL_INT_PRI
	#define UCAST_QUEUE_MAP_RULE_TBL_INT_PRI_OFFSET  47
	#define UCAST_QUEUE_MAP_RULE_TBL_INT_PRI_LEN     4
	#define UCAST_QUEUE_MAP_RULE_TBL_INT_PRI_DEFAULT 0x0
	/*[field] SLICE*/
	#define UCAST_QUEUE_MAP_RULE_TBL_SLICE
	#define UCAST_QUEUE_MAP_RULE_TBL_SLICE_OFFSET  51
	#define UCAST_QUEUE_MAP_RULE_TBL_SLICE_LEN     1
	#define UCAST_QUEUE_MAP_RULE_TBL_SLICE_DEFAULT 0x0
	/*[field] VALID*/
	#define UCAST_QUEUE_MAP_RULE_TBL_VALID
	#define UCAST_QUEUE_MAP_RULE_TBL_VALID_OFFSET  52
	#define UCAST_QUEUE_MAP_RULE_TBL_VALID_LEN     1
	#define UCAST_QUEUE_MAP_RULE_TBL_VALID_DEFAULT 0x0

struct ucast_queue_map_rule_tbl_0 {
	a_uint32_t  src_profile_map:4;
	a_uint32_t  pass_through_map:4;
	a_uint32_t  field_0_mode:1;
	a_uint32_t  field_0_type_map:4;
	a_uint32_t  _reserved0:14;
	a_uint32_t  field_1_mode:1;
	a_uint32_t  field_1_type_map:4;
	a_uint32_t  _reserved1:14;
	a_uint32_t  int_pri_incl:1;
	a_uint32_t  int_pri:4;
	a_uint32_t  slice:1;
	a_uint32_t  valid:1;
	a_uint32_t  _reserved2:11;
};

struct ucast_queue_map_rule_tbl_1 {
	a_uint32_t  src_profile_map:4;
	a_uint32_t  pass_through_map:4;
	a_uint32_t  field_0_mode:1;
	a_uint32_t  field_0_type:2;
	a_uint32_t  field_0_info:8;
	a_uint32_t  field_0_info_hi:8;
	a_uint32_t  field_1_mode:1;
	a_uint32_t  field_1_type_map:4;
	a_uint32_t  _reserved0:14;
	a_uint32_t  int_pri_incl:1;
	a_uint32_t  int_pri:4;
	a_uint32_t  slice:1;
	a_uint32_t  valid:1;
	a_uint32_t  _reserved1:11;
};

struct ucast_queue_map_rule_tbl_2 {
	a_uint32_t  src_profile_map:4;
	a_uint32_t  pass_through_map:4;
	a_uint32_t  field_0_mode:1;
	a_uint32_t  field_0_type_map:4;
	a_uint32_t  _reserved0:14;
	a_uint32_t  field_1_mode:1;
	a_uint32_t  field_1_type:2;
	a_uint32_t  field_1_info_0:2;
	a_uint32_t  field_1_info_1:6;
	a_uint32_t  field_1_info_hi:8;
	a_uint32_t  int_pri_incl:1;
	a_uint32_t  int_pri:4;
	a_uint32_t  slice:1;
	a_uint32_t  valid:1;
	a_uint32_t  _reserved1:11;
};

struct ucast_queue_map_rule_tbl_3 {
	a_uint32_t  src_profile_map:4;
	a_uint32_t  pass_through_map:4;
	a_uint32_t  field_0_mode:1;
	a_uint32_t  field_0_type:2;
	a_uint32_t  field_0_info:8;
	a_uint32_t  field_0_info_hi:8;
	a_uint32_t  field_1_mode:1;
	a_uint32_t  field_1_type:2;
	a_uint32_t  field_1_info_0:2;
	a_uint32_t  field_1_info_1:6;
	a_uint32_t  field_1_info_hi:8;
	a_uint32_t  int_pri_incl:1;
	a_uint32_t  int_pri:4;
	a_uint32_t  slice:1;
	a_uint32_t  valid:1;
	a_uint32_t  _reserved0:11;
};

union ucast_queue_map_rule_tbl_u {
	a_uint32_t val[2];
	struct ucast_queue_map_rule_tbl_0 bf;
	struct ucast_queue_map_rule_tbl_1 bf1;
	struct ucast_queue_map_rule_tbl_2 bf2;
	struct ucast_queue_map_rule_tbl_3 bf3;
};

/*[table] UCAST_QUEUE_MAP_ACTION_TBL*/
#define UCAST_QUEUE_MAP_ACTION_TBL
#define UCAST_QUEUE_MAP_ACTION_TBL_ADDRESS 0x4000
#define UCAST_QUEUE_MAP_ACTION_TBL_NUM     64
#define UCAST_QUEUE_MAP_ACTION_TBL_INC     0x10
#define UCAST_QUEUE_MAP_ACTION_TBL_TYPE    REG_TYPE_RW
#define UCAST_QUEUE_MAP_ACTION_TBL_DEFAULT 0x0
	/*[field] QUEUEID_MODE*/
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUEID_MODE
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUEID_MODE_OFFSET  0
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUEID_MODE_LEN     2
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUEID_MODE_DEFAULT 0x0
	/*[field] QUEUE_MAP_BASE reuse QUEUEID_MODE[1]*/
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUE_MAP_BASE
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUE_MAP_BASE_OFFSET  2
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUE_MAP_BASE_LEN     4
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUE_MAP_BASE_DEFAULT 0x0
	/*[field] QUEUE_ID reuse QUEUEID_MODE[2]*/
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUE_ID
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUE_ID_OFFSET  2
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUE_ID_LEN     8
	#define UCAST_QUEUE_MAP_ACTION_TBL_QUEUE_ID_DEFAULT 0x0
	/*[field] FORCE_INDEX_TYPE_EN reuse QUEUEID_MODE[1]*/
	#define UCAST_QUEUE_MAP_ACTION_TBL_FORCE_INDEX_TYPE_EN
	#define UCAST_QUEUE_MAP_ACTION_TBL_FORCE_INDEX_TYPE_EN_OFFSET  6
	#define UCAST_QUEUE_MAP_ACTION_TBL_FORCE_INDEX_TYPE_EN_LEN     1
	#define UCAST_QUEUE_MAP_ACTION_TBL_FORCE_INDEX_TYPE_EN_DEFAULT 0x0
	/*[field] FORCE_INDEX_TYPE reuse QUEUEID_MODE[0]*/
	#define UCAST_QUEUE_MAP_ACTION_TBL_FORCE_INDEX_TYPE
	#define UCAST_QUEUE_MAP_ACTION_TBL_FORCE_INDEX_TYPE_OFFSET  7
	#define UCAST_QUEUE_MAP_ACTION_TBL_FORCE_INDEX_TYPE_LEN     3
	#define UCAST_QUEUE_MAP_ACTION_TBL_FORCE_INDEX_TYPE_DEFAULT 0x0
	/*[field] PROFILE_ID reuse QUEUEID_MODE[2]*/
	#define UCAST_QUEUE_MAP_ACTION_TBL_PROFILE_ID
	#define UCAST_QUEUE_MAP_ACTION_TBL_PROFILE_ID_OFFSET  10
	#define UCAST_QUEUE_MAP_ACTION_TBL_PROFILE_ID_LEN     4
	#define UCAST_QUEUE_MAP_ACTION_TBL_PROFILE_ID_DEFAULT 0x0

struct ucast_queue_map_action_tbl_0 {
	a_uint32_t  queueid_mode:2;
	a_uint32_t  queue_map_base:4;
	a_uint32_t  force_index_type_en:1;
	a_uint32_t  force_index_type:3;
	a_uint32_t  _reserved0:22;
};

struct ucast_queue_map_action_tbl_1 {
	a_uint32_t  queueid_mode:2;
	a_uint32_t  queue_id:8;
	a_uint32_t  profile_id:4;
	a_uint32_t  _reserved0:18;
};

struct ucast_queue_map_action_tbl_2 {
	a_uint32_t  queueid_mode:2;
	a_uint32_t  _reserved0:30;
};

struct ucast_queue_map_action_tbl_3 {
	a_uint32_t  queueid_mode:2;
	a_uint32_t  _reserved0:30;
};

union ucast_queue_map_action_tbl_u {
	a_uint32_t val;
	struct ucast_queue_map_action_tbl_0 bf;
	struct ucast_queue_map_action_tbl_1 bf1;
	struct ucast_queue_map_action_tbl_2 bf2;
	struct ucast_queue_map_action_tbl_3 bf3;
};

/*[table] UCAST_QUEUE_CTRL_TBL*/
#define UCAST_QUEUE_CTRL_TBL
#define UCAST_QUEUE_CTRL_TBL_ADDRESS 0x6000
#define UCAST_QUEUE_CTRL_TBL_NUM     256
#define UCAST_QUEUE_CTRL_TBL_INC     0x4
#define UCAST_QUEUE_CTRL_TBL_TYPE    REG_TYPE_RW
#define UCAST_QUEUE_CTRL_TBL_DEFAULT 0x0
	/*[field] DDRQ_EN*/
	#define UCAST_QUEUE_CTRL_TBL_DDRQ_EN
	#define UCAST_QUEUE_CTRL_TBL_DDRQ_EN_OFFSET  0
	#define UCAST_QUEUE_CTRL_TBL_DDRQ_EN_LEN     1
	#define UCAST_QUEUE_CTRL_TBL_DDRQ_EN_DEFAULT 0x0
	/*[field] QID_MISMATCH_CHECK_EN*/
	#define UCAST_QUEUE_CTRL_TBL_QID_MISMATCH_CHECK_EN
	#define UCAST_QUEUE_CTRL_TBL_QID_MISMATCH_CHECK_EN_OFFSET  1
	#define UCAST_QUEUE_CTRL_TBL_QID_MISMATCH_CHECK_EN_LEN     1
	#define UCAST_QUEUE_CTRL_TBL_QID_MISMATCH_CHECK_EN_DEFAULT 0x0

struct ucast_queue_ctrl_tbl {
	a_uint32_t  ddrq_en:1;
	a_uint32_t  qid_mismatch_check_en:1;
	a_uint32_t  _reserved0:30;
};

union ucast_queue_ctrl_tbl_u {
	a_uint32_t val;
	struct ucast_queue_ctrl_tbl bf;
};

/*[table] MUL_P8_DROP_CNT_TBL*/
#define MUL_P8_DROP_CNT_TBL
#define MUL_P8_DROP_CNT_TBL_ADDRESS 0x1f8000
#define MUL_P8_DROP_CNT_TBL_NUM     12
#define MUL_P8_DROP_CNT_TBL_INC     0x10
#define MUL_P8_DROP_CNT_TBL_TYPE    REG_TYPE_RW
#define MUL_P8_DROP_CNT_TBL_DEFAULT 0x0
	/*[field] MUL_P8_DROP_PKT*/
	#define MUL_P8_DROP_CNT_TBL_MUL_P8_DROP_PKT
	#define MUL_P8_DROP_CNT_TBL_MUL_P8_DROP_PKT_OFFSET  0
	#define MUL_P8_DROP_CNT_TBL_MUL_P8_DROP_PKT_LEN     32
	#define MUL_P8_DROP_CNT_TBL_MUL_P8_DROP_PKT_DEFAULT 0x0
	/*[field] MUL_P8_DROP_BYTE*/
	#define MUL_P8_DROP_CNT_TBL_MUL_P8_DROP_BYTE
	#define MUL_P8_DROP_CNT_TBL_MUL_P8_DROP_BYTE_OFFSET  32
	#define MUL_P8_DROP_CNT_TBL_MUL_P8_DROP_BYTE_LEN     40
	#define MUL_P8_DROP_CNT_TBL_MUL_P8_DROP_BYTE_DEFAULT 0x0

struct mul_p8_drop_cnt_tbl {
	a_uint32_t  mul_p8_drop_pkt:32;
	a_uint32_t  mul_p8_drop_byte_0:32;
	a_uint32_t  mul_p8_drop_byte_1:8;
	a_uint32_t  _reserved0:24;
};

union mul_p8_drop_cnt_tbl_u {
	a_uint32_t val[3];
	struct mul_p8_drop_cnt_tbl bf;
};

#endif
