/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _JHPPE_EPE_PM_REG_H_
#define _JHPPE_EPE_PM_REG_H_

/*[table] EG_PM_COUNTER_GEN*/
#define EG_PM_COUNTER_GEN
#define EG_PM_COUNTER_GEN_ADDRESS 0x400
#define EG_PM_COUNTER_GEN_NUM     32
#define EG_PM_COUNTER_GEN_INC     0x10
#define EG_PM_COUNTER_GEN_TYPE    REG_TYPE_RW
#define EG_PM_COUNTER_GEN_DEFAULT 0x0
	/*[field] PORT_TYPE*/
	#define EG_PM_COUNTER_GEN_PORT_TYPE
	#define EG_PM_COUNTER_GEN_PORT_TYPE_OFFSET  0
	#define EG_PM_COUNTER_GEN_PORT_TYPE_LEN     2
	#define EG_PM_COUNTER_GEN_PORT_TYPE_DEFAULT 0x0
	/*[field] PORT*/
	#define EG_PM_COUNTER_GEN_PORT
	#define EG_PM_COUNTER_GEN_PORT_OFFSET  2
	#define EG_PM_COUNTER_GEN_PORT_LEN     9
	#define EG_PM_COUNTER_GEN_PORT_DEFAULT 0x0
	/*[field] TAG_FMT*/
	#define EG_PM_COUNTER_GEN_TAG_FMT
	#define EG_PM_COUNTER_GEN_TAG_FMT_OFFSET  11
	#define EG_PM_COUNTER_GEN_TAG_FMT_LEN     3
	#define EG_PM_COUNTER_GEN_TAG_FMT_DEFAULT 0x0
	/*[field] VID*/
	#define EG_PM_COUNTER_GEN_VID
	#define EG_PM_COUNTER_GEN_VID_OFFSET  14
	#define EG_PM_COUNTER_GEN_VID_LEN     12
	#define EG_PM_COUNTER_GEN_VID_DEFAULT 0x0
	/*[field] VID_INCL*/
	#define EG_PM_COUNTER_GEN_VID_INCL
	#define EG_PM_COUNTER_GEN_VID_INCL_OFFSET  26
	#define EG_PM_COUNTER_GEN_VID_INCL_LEN     1
	#define EG_PM_COUNTER_GEN_VID_INCL_DEFAULT 0x0
	/*[field] PCP*/
	#define EG_PM_COUNTER_GEN_PCP
	#define EG_PM_COUNTER_GEN_PCP_OFFSET  27
	#define EG_PM_COUNTER_GEN_PCP_LEN     3
	#define EG_PM_COUNTER_GEN_PCP_DEFAULT 0x0
	/*[field] PCP_INCL*/
	#define EG_PM_COUNTER_GEN_PCP_INCL
	#define EG_PM_COUNTER_GEN_PCP_INCL_OFFSET  30
	#define EG_PM_COUNTER_GEN_PCP_INCL_LEN     1
	#define EG_PM_COUNTER_GEN_PCP_INCL_DEFAULT 0x0
	/*[field] IPMC*/
	#define EG_PM_COUNTER_GEN_IPMC
	#define EG_PM_COUNTER_GEN_IPMC_OFFSET  31
	#define EG_PM_COUNTER_GEN_IPMC_LEN     3
	#define EG_PM_COUNTER_GEN_IPMC_DEFAULT 0x0

struct eg_pm_counter_gen {
	a_uint32_t  port_type:2;
	a_uint32_t  port:9;
	a_uint32_t  tag_fmt:3;
	a_uint32_t  vid:12;
	a_uint32_t  vid_incl:1;
	a_uint32_t  pcp:3;
	a_uint32_t  pcp_incl:1;
	a_uint32_t  ipmc_0:1;
	a_uint32_t  ipmc_1:2;
	a_uint32_t  _reserved0:30;
};

union eg_pm_counter_gen_u {
	a_uint32_t val[2];
	struct eg_pm_counter_gen bf;
};

/*[table] EG_PM_COUNTER_TBL*/
#define EG_PM_COUNTER_TBL
#define EG_PM_COUNTER_TBL_ADDRESS 0x29000
#define EG_PM_COUNTER_TBL_NUM     32
#define EG_PM_COUNTER_TBL_INC     0x40
#define EG_PM_COUNTER_TBL_TYPE    REG_TYPE_RW
#define EG_PM_COUNTER_TBL_DEFAULT 0x0
	/*[field] OCTETS*/
	#define EG_PM_COUNTER_TBL_OCTETS
	#define EG_PM_COUNTER_TBL_OCTETS_OFFSET  0
	#define EG_PM_COUNTER_TBL_OCTETS_LEN     40
	#define EG_PM_COUNTER_TBL_OCTETS_DEFAULT 0x0
	/*[field] UCAST_PACKET*/
	#define EG_PM_COUNTER_TBL_UCAST_PACKET
	#define EG_PM_COUNTER_TBL_UCAST_PACKET_OFFSET  40
	#define EG_PM_COUNTER_TBL_UCAST_PACKET_LEN     32
	#define EG_PM_COUNTER_TBL_UCAST_PACKET_DEFAULT 0x0
	/*[field] BCAST_PACKET*/
	#define EG_PM_COUNTER_TBL_BCAST_PACKET
	#define EG_PM_COUNTER_TBL_BCAST_PACKET_OFFSET  72
	#define EG_PM_COUNTER_TBL_BCAST_PACKET_LEN     32
	#define EG_PM_COUNTER_TBL_BCAST_PACKET_DEFAULT 0x0
	/*[field] MCAST_PACKET*/
	#define EG_PM_COUNTER_TBL_MCAST_PACKET
	#define EG_PM_COUNTER_TBL_MCAST_PACKET_OFFSET  104
	#define EG_PM_COUNTER_TBL_MCAST_PACKET_LEN     32
	#define EG_PM_COUNTER_TBL_MCAST_PACKET_DEFAULT 0x0
	/*[field] OVERSIZE*/
	#define EG_PM_COUNTER_TBL_OVERSIZE
	#define EG_PM_COUNTER_TBL_OVERSIZE_OFFSET  136
	#define EG_PM_COUNTER_TBL_OVERSIZE_LEN     32
	#define EG_PM_COUNTER_TBL_OVERSIZE_DEFAULT 0x0
	/*[field] FRAME_64*/
	#define EG_PM_COUNTER_TBL_FRAME_64
	#define EG_PM_COUNTER_TBL_FRAME_64_OFFSET  168
	#define EG_PM_COUNTER_TBL_FRAME_64_LEN     32
	#define EG_PM_COUNTER_TBL_FRAME_64_DEFAULT 0x0
	/*[field] FRAME_65_127*/
	#define EG_PM_COUNTER_TBL_FRAME_65_127
	#define EG_PM_COUNTER_TBL_FRAME_65_127_OFFSET  200
	#define EG_PM_COUNTER_TBL_FRAME_65_127_LEN     32
	#define EG_PM_COUNTER_TBL_FRAME_65_127_DEFAULT 0x0
	/*[field] FRAME_128_255*/
	#define EG_PM_COUNTER_TBL_FRAME_128_255
	#define EG_PM_COUNTER_TBL_FRAME_128_255_OFFSET  232
	#define EG_PM_COUNTER_TBL_FRAME_128_255_LEN     32
	#define EG_PM_COUNTER_TBL_FRAME_128_255_DEFAULT 0x0
	/*[field] FRAME_256_511*/
	#define EG_PM_COUNTER_TBL_FRAME_256_511
	#define EG_PM_COUNTER_TBL_FRAME_256_511_OFFSET  264
	#define EG_PM_COUNTER_TBL_FRAME_256_511_LEN     32
	#define EG_PM_COUNTER_TBL_FRAME_256_511_DEFAULT 0x0
	/*[field] FRAME_512_1023*/
	#define EG_PM_COUNTER_TBL_FRAME_512_1023
	#define EG_PM_COUNTER_TBL_FRAME_512_1023_OFFSET  296
	#define EG_PM_COUNTER_TBL_FRAME_512_1023_LEN     32
	#define EG_PM_COUNTER_TBL_FRAME_512_1023_DEFAULT 0x0
	/*[field] FRAME_1024_1518*/
	#define EG_PM_COUNTER_TBL_FRAME_1024_1518
	#define EG_PM_COUNTER_TBL_FRAME_1024_1518_OFFSET  328
	#define EG_PM_COUNTER_TBL_FRAME_1024_1518_LEN     32
	#define EG_PM_COUNTER_TBL_FRAME_1024_1518_DEFAULT 0x0

struct eg_pm_counter_tbl {
	a_uint32_t  octets_0:32;
	a_uint32_t  octets_1:8;
	a_uint32_t  ucast_packet_0:24;
	a_uint32_t  ucast_packet_1:8;
	a_uint32_t  bcast_packet_0:24;
	a_uint32_t  bcast_packet_1:8;
	a_uint32_t  mcast_packet_0:24;
	a_uint32_t  mcast_packet_1:8;
	a_uint32_t  oversize_0:24;
	a_uint32_t  oversize_1:8;
	a_uint32_t  frame_64_0:24;
	a_uint32_t  frame_64_1:8;
	a_uint32_t  frame_65_127_0:24;
	a_uint32_t  frame_65_127_1:8;
	a_uint32_t  frame_128_255_0:24;
	a_uint32_t  frame_128_255_1:8;
	a_uint32_t  frame_256_511_0:24;
	a_uint32_t  frame_256_511_1:8;
	a_uint32_t  frame_512_1023_0:24;
	a_uint32_t  frame_512_1023_1:8;
	a_uint32_t  frame_1024_1518_0:24;
	a_uint32_t  frame_1024_1518_1:8;
	a_uint32_t  _reserved0:24;
};

union eg_pm_counter_tbl_u {
	a_uint32_t val[12];
	struct eg_pm_counter_tbl bf;
};

#endif
