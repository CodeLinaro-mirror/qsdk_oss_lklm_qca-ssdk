/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#ifndef _HTTPPE_PORTCTRL_REG_H_
#define _HTTPPE_PORTCTRL_REG_H_

/*[table] PORT_TX_COUNTER_TBL_REG*/
#define PORT_TX_COUNTER_TBL_REG
#define PORT_TX_COUNTER_TBL_REG_ADDRESS 0x14000
#define PORT_TX_COUNTER_TBL_REG_NUM     9
#define PORT_TX_COUNTER_TBL_REG_INC     0x10
#define PORT_TX_COUNTER_TBL_REG_TYPE    REG_TYPE_RW
#define PORT_TX_COUNTER_TBL_REG_DEFAULT 0x0
	/*[field] TX_PACKETS*/
	#define PORT_TX_COUNTER_TBL_REG_TX_PACKETS
	#define PORT_TX_COUNTER_TBL_REG_TX_PACKETS_OFFSET  0
	#define PORT_TX_COUNTER_TBL_REG_TX_PACKETS_LEN     32
	#define PORT_TX_COUNTER_TBL_REG_TX_PACKETS_DEFAULT 0x0
	/*[field] TX_BYTES*/
	#define PORT_TX_COUNTER_TBL_REG_TX_BYTES
	#define PORT_TX_COUNTER_TBL_REG_TX_BYTES_OFFSET  32
	#define PORT_TX_COUNTER_TBL_REG_TX_BYTES_LEN     40
	#define PORT_TX_COUNTER_TBL_REG_TX_BYTES_DEFAULT 0x0

struct port_tx_counter_tbl_reg {
	a_uint32_t  tx_packets:32;
	a_uint32_t  tx_bytes_0:32;
	a_uint32_t  tx_bytes_1:8;
	a_uint32_t  _reserved0:24;
};

union port_tx_counter_tbl_reg_u {
	a_uint32_t val[3];
	struct port_tx_counter_tbl_reg bf;
};

/*[table] VP_TX_COUNTER_TBL_REG*/
#define VP_TX_COUNTER_TBL_REG
#define VP_TX_COUNTER_TBL_REG_ADDRESS 0x16000
#define VP_TX_COUNTER_TBL_REG_NUM     256
#define VP_TX_COUNTER_TBL_REG_INC     0x10
#define VP_TX_COUNTER_TBL_REG_TYPE    REG_TYPE_RW
#define VP_TX_COUNTER_TBL_REG_DEFAULT 0x0
	/*[field] TX_PACKETS*/
	#define VP_TX_COUNTER_TBL_REG_TX_PACKETS
	#define VP_TX_COUNTER_TBL_REG_TX_PACKETS_OFFSET  0
	#define VP_TX_COUNTER_TBL_REG_TX_PACKETS_LEN     32
	#define VP_TX_COUNTER_TBL_REG_TX_PACKETS_DEFAULT 0x0
	/*[field] TX_BYTES*/
	#define VP_TX_COUNTER_TBL_REG_TX_BYTES
	#define VP_TX_COUNTER_TBL_REG_TX_BYTES_OFFSET  32
	#define VP_TX_COUNTER_TBL_REG_TX_BYTES_LEN     40
	#define VP_TX_COUNTER_TBL_REG_TX_BYTES_DEFAULT 0x0

struct vp_tx_counter_tbl_reg {
	a_uint32_t  tx_packets:32;
	a_uint32_t  tx_bytes_0:32;
	a_uint32_t  tx_bytes_1:8;
	a_uint32_t  _reserved0:24;
};

union vp_tx_counter_tbl_reg_u {
	a_uint32_t val[3];
	struct vp_tx_counter_tbl_reg bf;
};

#endif
