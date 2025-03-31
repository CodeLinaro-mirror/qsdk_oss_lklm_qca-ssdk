/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HMSPPE_PON_PM_REG_H_
#define _HMSPPE_PON_PM_REG_H_

/*[table] PRE_IPO_PM_COUNTER_GEN*/
#define PRE_IPO_PM_COUNTER_GEN
#define PRE_IPO_PM_COUNTER_GEN_ADDRESS 0x6000
#define PRE_IPO_PM_COUNTER_GEN_NUM     32
#define PRE_IPO_PM_COUNTER_GEN_INC     0x10
#define PRE_IPO_PM_COUNTER_GEN_TYPE    REG_TYPE_RW
#define PRE_IPO_PM_COUNTER_GEN_DEFAULT 0x0
	/*[field] PORT_TYPE*/
	#define PRE_IPO_PM_COUNTER_GEN_PORT_TYPE
	#define PRE_IPO_PM_COUNTER_GEN_PORT_TYPE_OFFSET  0
	#define PRE_IPO_PM_COUNTER_GEN_PORT_TYPE_LEN     3
	#define PRE_IPO_PM_COUNTER_GEN_PORT_TYPE_DEFAULT 0x0
	/*[field] PORT*/
	#define PRE_IPO_PM_COUNTER_GEN_PORT
	#define PRE_IPO_PM_COUNTER_GEN_PORT_OFFSET  3
	#define PRE_IPO_PM_COUNTER_GEN_PORT_LEN     9
	#define PRE_IPO_PM_COUNTER_GEN_PORT_DEFAULT 0x0
	/*[field] TAG_FMT*/
	#define PRE_IPO_PM_COUNTER_GEN_TAG_FMT
	#define PRE_IPO_PM_COUNTER_GEN_TAG_FMT_OFFSET  12
	#define PRE_IPO_PM_COUNTER_GEN_TAG_FMT_LEN     3
	#define PRE_IPO_PM_COUNTER_GEN_TAG_FMT_DEFAULT 0x0
	/*[field] VID*/
	#define PRE_IPO_PM_COUNTER_GEN_VID
	#define PRE_IPO_PM_COUNTER_GEN_VID_OFFSET  15
	#define PRE_IPO_PM_COUNTER_GEN_VID_LEN     12
	#define PRE_IPO_PM_COUNTER_GEN_VID_DEFAULT 0x0
	/*[field] VID_INCL*/
	#define PRE_IPO_PM_COUNTER_GEN_VID_INCL
	#define PRE_IPO_PM_COUNTER_GEN_VID_INCL_OFFSET  27
	#define PRE_IPO_PM_COUNTER_GEN_VID_INCL_LEN     1
	#define PRE_IPO_PM_COUNTER_GEN_VID_INCL_DEFAULT 0x0
	/*[field] PCP*/
	#define PRE_IPO_PM_COUNTER_GEN_PCP
	#define PRE_IPO_PM_COUNTER_GEN_PCP_OFFSET  28
	#define PRE_IPO_PM_COUNTER_GEN_PCP_LEN     3
	#define PRE_IPO_PM_COUNTER_GEN_PCP_DEFAULT 0x0
	/*[field] PCP_INCL*/
	#define PRE_IPO_PM_COUNTER_GEN_PCP_INCL
	#define PRE_IPO_PM_COUNTER_GEN_PCP_INCL_OFFSET  31
	#define PRE_IPO_PM_COUNTER_GEN_PCP_INCL_LEN     1
	#define PRE_IPO_PM_COUNTER_GEN_PCP_INCL_DEFAULT 0x0
	/*[field] IPMC*/
	#define PRE_IPO_PM_COUNTER_GEN_IPMC
	#define PRE_IPO_PM_COUNTER_GEN_IPMC_OFFSET  32
	#define PRE_IPO_PM_COUNTER_GEN_IPMC_LEN     3
	#define PRE_IPO_PM_COUNTER_GEN_IPMC_DEFAULT 0x0
	/*[field] COUNTER_ID*/
	#define PRE_IPO_PM_COUNTER_GEN_COUNTER_ID
	#define PRE_IPO_PM_COUNTER_GEN_COUNTER_ID_OFFSET  35
	#define PRE_IPO_PM_COUNTER_GEN_COUNTER_ID_LEN     5
	#define PRE_IPO_PM_COUNTER_GEN_COUNTER_ID_DEFAULT 0x0

struct pre_ipo_pm_counter_gen {
	a_uint32_t  port_type:3;
	a_uint32_t  port:9;
	a_uint32_t  tag_fmt:3;
	a_uint32_t  vid:12;
	a_uint32_t  vid_incl:1;
	a_uint32_t  pcp:3;
	a_uint32_t  pcp_incl:1;
	a_uint32_t  ipmc:3;
	a_uint32_t  counter_id:5;
	a_uint32_t  _reserved0:24;
};

union pre_ipo_pm_counter_gen_u {
	a_uint32_t val[2];
	struct pre_ipo_pm_counter_gen bf;
};

#endif
