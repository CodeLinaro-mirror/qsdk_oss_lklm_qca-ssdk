/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HTTPPE_ATHTAG_REG_H_
#define _HTTPPE_ATHTAG_REG_H_

/*[register] EG_HDR_XMIT_PRI_MAPPING*/
#define EG_HDR_XMIT_PRI_MAPPING
#define EG_HDR_XMIT_PRI_MAPPING_ADDRESS 0xc8
#define EG_HDR_XMIT_PRI_MAPPING_NUM     16
#define EG_HDR_XMIT_PRI_MAPPING_INC     0x4
#define EG_HDR_XMIT_PRI_MAPPING_TYPE    REG_TYPE_RW
#define EG_HDR_XMIT_PRI_MAPPING_DEFAULT 0x0
	/*[field] PRI*/
	#define EG_HDR_XMIT_PRI_MAPPING_PRI
	#define EG_HDR_XMIT_PRI_MAPPING_PRI_OFFSET  0
	#define EG_HDR_XMIT_PRI_MAPPING_PRI_LEN     3
	#define EG_HDR_XMIT_PRI_MAPPING_PRI_DEFAULT 0x0

struct eg_hdr_xmit_pri_mapping {
	a_uint32_t  pri:3;
	a_uint32_t  _reserved0:29;
};

union eg_hdr_xmit_pri_mapping_u {
	a_uint32_t val;
	struct eg_hdr_xmit_pri_mapping bf;
};

/*[register] SERVICE_CODE_MAPPING*/
#define SERVICE_CODE_MAPPING
#define SERVICE_CODE_MAPPING_ADDRESS 0x400
#define SERVICE_CODE_MAPPING_NUM     16
#define SERVICE_CODE_MAPPING_INC     0x4
#define SERVICE_CODE_MAPPING_TYPE    REG_TYPE_RW
#define SERVICE_CODE_MAPPING_DEFAULT 0x0
	/*[field] SERVICE_CODE*/
	#define SERVICE_CODE_MAPPING_SERVICE_CODE
	#define SERVICE_CODE_MAPPING_SERVICE_CODE_OFFSET  0
	#define SERVICE_CODE_MAPPING_SERVICE_CODE_LEN     8
	#define SERVICE_CODE_MAPPING_SERVICE_CODE_DEFAULT 0x0
	/*[field] SERVICE_CODE_VALID*/
	#define SERVICE_CODE_MAPPING_SERVICE_CODE_VALID
	#define SERVICE_CODE_MAPPING_SERVICE_CODE_VALID_OFFSET  8
	#define SERVICE_CODE_MAPPING_SERVICE_CODE_VALID_LEN     1
	#define SERVICE_CODE_MAPPING_SERVICE_CODE_VALID_DEFAULT 0x0

struct service_code_mapping {
	a_uint32_t  service_code:8;
	a_uint32_t  service_code_valid:1;
	a_uint32_t  _reserved0:23;
};

union service_code_mapping_u {
	a_uint32_t val;
	struct service_code_mapping bf;
};

/*[register] DST_PORT_MAPPING_TBL*/
#define DST_PORT_MAPPING_TBL
#define DST_PORT_MAPPING_TBL_ADDRESS 0x3800
#define DST_PORT_MAPPING_TBL_NUM     256
#define DST_PORT_MAPPING_TBL_INC     0x4
#define DST_PORT_MAPPING_TBL_TYPE    REG_TYPE_RW
#define DST_PORT_MAPPING_TBL_DEFAULT 0x0
	/*[field] DST_INFO*/
	#define DST_PORT_MAPPING_TBL_DST_INFO
	#define DST_PORT_MAPPING_TBL_DST_INFO_OFFSET  0
	#define DST_PORT_MAPPING_TBL_DST_INFO_LEN     14
	#define DST_PORT_MAPPING_TBL_DST_INFO_DEFAULT 0x0
	/*[field] DST_INFO_VALID*/
	#define DST_PORT_MAPPING_TBL_DST_INFO_VALID
	#define DST_PORT_MAPPING_TBL_DST_INFO_VALID_OFFSET  14
	#define DST_PORT_MAPPING_TBL_DST_INFO_VALID_LEN     1
	#define DST_PORT_MAPPING_TBL_DST_INFO_VALID_DEFAULT 0x0

struct dst_port_mapping_tbl {
	a_uint32_t  dst_info:14;
	a_uint32_t  dst_info_valid:1;
	a_uint32_t  _reserved0:17;
};

union dst_port_mapping_tbl_u {
	a_uint32_t val;
	struct dst_port_mapping_tbl bf;
};
#endif
