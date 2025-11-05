/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _JHPPE_ATHTAG_REG_H_
#define _JHPPE_ATHTAG_REG_H_

/*[register] SERVICE_CODE_MAPPING*/
#define SERVICE_CODE_MAPPING
#define SERVICE_CODE_MAPPING_ADDRESS 0x200
#define SERVICE_CODE_MAPPING_NUM     16
#define SERVICE_CODE_MAPPING_INC     0x10
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

/*[register] SRC_PORT_MAPPING_TBL*/
#define SRC_PORT_MAPPING_TBL
#define SRC_PORT_MAPPING_TBL_ADDRESS 0x2000
#define SRC_PORT_MAPPING_TBL_NUM     256
#define SRC_PORT_MAPPING_TBL_INC     0x10
#define SRC_PORT_MAPPING_TBL_TYPE    REG_TYPE_RW
#define SRC_PORT_MAPPING_TBL_DEFAULT 0x0
	/*[field] PORT_VP*/
	#define SRC_PORT_MAPPING_TBL_PORT_VP
	#define SRC_PORT_MAPPING_TBL_PORT_VP_OFFSET  0
	#define SRC_PORT_MAPPING_TBL_PORT_VP_LEN     8
	#define SRC_PORT_MAPPING_TBL_PORT_VP_DEFAULT 0x0
	/*[field] PORT_VALID*/
	#define SRC_PORT_MAPPING_TBL_PORT_VALID
	#define SRC_PORT_MAPPING_TBL_PORT_VALID_OFFSET  8
	#define SRC_PORT_MAPPING_TBL_PORT_VALID_LEN     1
	#define SRC_PORT_MAPPING_TBL_PORT_VALID_DEFAULT 0x0
	/*[field] DST_INFO*/
	#define SRC_PORT_MAPPING_TBL_DST_INFO
	#define SRC_PORT_MAPPING_TBL_DST_INFO_OFFSET  9
	#define SRC_PORT_MAPPING_TBL_DST_INFO_LEN     14
	#define SRC_PORT_MAPPING_TBL_DST_INFO_DEFAULT 0x0
	/*[field] DST_INFO_VALID*/
	#define SRC_PORT_MAPPING_TBL_DST_INFO_VALID
	#define SRC_PORT_MAPPING_TBL_DST_INFO_VALID_OFFSET  23
	#define SRC_PORT_MAPPING_TBL_DST_INFO_VALID_LEN     1
	#define SRC_PORT_MAPPING_TBL_DST_INFO_VALID_DEFAULT 0x0

struct src_port_mapping_tbl {
	a_uint32_t  port_vp:8;
	a_uint32_t  port_valid:1;
	a_uint32_t  dst_info:14;
	a_uint32_t  dst_info_valid:1;
	a_uint32_t  _reserved0:8;
};

union src_port_mapping_tbl_u {
	a_uint32_t val;
	struct src_port_mapping_tbl bf;
};

/*[register] DST_PORT_MAPPING_TBL*/
#define DST_PORT_MAPPING_TBL
#define DST_PORT_MAPPING_TBL_ADDRESS 0x3000
#define DST_PORT_MAPPING_TBL_NUM     256
#define DST_PORT_MAPPING_TBL_INC     0x10
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
