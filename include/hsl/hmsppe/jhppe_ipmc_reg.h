/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _JHPPE_IPMC_REG_H_
#define _JHPPE_IPMC_REG_H_

/*[register] IPMC_CONVERT_UC_CTRL*/
#define IPMC_CONVERT_UC_CTRL
#define IPMC_CONVERT_UC_CTRL_ADDRESS 0xa84
#define IPMC_CONVERT_UC_CTRL_NUM     1
#define IPMC_CONVERT_UC_CTRL_INC     0x4
#define IPMC_CONVERT_UC_CTRL_TYPE    REG_TYPE_RW
#define IPMC_CONVERT_UC_CTRL_DEFAULT 0x1
	/*[field] ENABLE_PORT_NUM*/
	#define IPMC_CONVERT_UC_CTRL_ENABLE_PORT_NUM
	#define IPMC_CONVERT_UC_CTRL_ENABLE_PORT_NUM_OFFSET  0
	#define IPMC_CONVERT_UC_CTRL_ENABLE_PORT_NUM_LEN     4
	#define IPMC_CONVERT_UC_CTRL_ENABLE_PORT_NUM_DEFAULT 0x1
	/*[field] CONVERT_PORT_VP*/
	#define IPMC_CONVERT_UC_CTRL_CONVERT_PORT_VP
	#define IPMC_CONVERT_UC_CTRL_CONVERT_PORT_VP_OFFSET  4
	#define IPMC_CONVERT_UC_CTRL_CONVERT_PORT_VP_LEN     8
	#define IPMC_CONVERT_UC_CTRL_CONVERT_PORT_VP_DEFAULT 0x0
	/*[field] SERVICE_CODE*/
	#define IPMC_CONVERT_UC_CTRL_SERVICE_CODE
	#define IPMC_CONVERT_UC_CTRL_SERVICE_CODE_OFFSET  12
	#define IPMC_CONVERT_UC_CTRL_SERVICE_CODE_LEN     8
	#define IPMC_CONVERT_UC_CTRL_SERVICE_CODE_DEFAULT 0x0
	/*[field] POST_BYPASS_BITMAP*/
	#define IPMC_CONVERT_UC_CTRL_POST_BYPASS_BITMAP
	#define IPMC_CONVERT_UC_CTRL_POST_BYPASS_BITMAP_OFFSET  20
	#define IPMC_CONVERT_UC_CTRL_POST_BYPASS_BITMAP_LEN     8
	#define IPMC_CONVERT_UC_CTRL_POST_BYPASS_BITMAP_DEFAULT 0x0

struct ipmc_convert_uc_ctrl {
	a_uint32_t  enable_port_num:4;
	a_uint32_t  convert_port_vp:8;
	a_uint32_t  service_code:8;
	a_uint32_t  post_bypass_bitmap:8;
	a_uint32_t  _reserved0:4;
};

union ipmc_convert_uc_ctrl_u {
	a_uint32_t val;
	struct ipmc_convert_uc_ctrl bf;
};

#endif
