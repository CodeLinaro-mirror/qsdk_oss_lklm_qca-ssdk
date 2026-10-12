/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

/**
 * @defgroup
 * @{
 */
#include "sw.h"
#include "hsl_htt_reg.h"
#include "adpt_hppe.h"
#include "adpt.h"

#define QUEUE_TX_COUNTER_TBL_MAX_ENTRY	300
#define CPU_CODE_CNT_TBL_MAX_ENTRY 256
#define HTTPPE_MAX_PORT_NUM 9
#define HTTPPE_DOT1P_MISS_DROP_CODE 126

extern char *dropcode[];

void
adpt_httppe_debug_queue_tx_counter_get(a_uint32_t dev_id, a_bool_t show_type, char **buf, ssize_t *count)
{
	union queue_tx_counter_tbl_u queue_tx_counter_tbl;
	a_uint64_t value;
	int i, tags, sign;

	sign = tags = 0;
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "QUEUE_TX_COUNTER_TBL TX:");
	for (i = 0; i < QUEUE_TX_COUNTER_TBL_MAX_ENTRY; i++)
	{
		httppe_queue_tx_counter_tbl_get(dev_id, i, &queue_tx_counter_tbl);
		if (show_type == A_FALSE)
			value = (a_uint64_t)queue_tx_counter_tbl.bf.tx_packets;
		else
			value = queue_tx_counter_tbl.bf.tx_bytes_0 | ((a_uint64_t)queue_tx_counter_tbl.bf.tx_bytes_1 << 32);
		if (value > 0)
		{
			if (sign) {
				*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
				*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "");
			}
			sign = 0;
			*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%15llu(queue=%04d)", value, i);
			if (++tags % 3 == 0)
				sign = 1;
		}
	}
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
}

void
adpt_httppe_debug_queue_pending_counter_get(a_uint32_t dev_id, char **buf, ssize_t *count)
{
	union ac_uni_queue_cnt_tbl_u uni_cnt;
	union ac_mul_queue_cnt_tbl_u mul_cnt;
	int i, tags = 0;

	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "QUEUE_PENDING_CNT:");
	for (i = 0; i < AC_UNI_QUEUE_CNT_TBL_MAX_ENTRY; i++) {
		aos_mem_zero(&uni_cnt, sizeof(uni_cnt));
		httppe_ac_uni_queue_cnt_tbl_get(dev_id, i, &uni_cnt);
		adpt_hppe_debug_value_print(buf, count, &tags,
				uni_cnt.bf.ac_uni_queue_cnt, "queue", 4, i);
	}
	for (i = 0; i < AC_MUL_QUEUE_CNT_TBL_MAX_ENTRY; i++) {
		aos_mem_zero(&mul_cnt, sizeof(mul_cnt));
		httppe_ac_mul_queue_cnt_tbl_get(dev_id, i, &mul_cnt);
		adpt_hppe_debug_value_print(buf, count, &tags, mul_cnt.bf.ac_mul_queue_cnt,
				"queue", 4, i + AC_UNI_QUEUE_CNT_TBL_MAX_ENTRY);
	}
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
}

void
adpt_httppe_debug_ac_group_counter_get(a_uint32_t dev_id, char **buf, ssize_t *count)
{
	union ac_grp_cnt_tbl_u grp_cnt;
	int i, tags = 0;

	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "AC_GRP_CNT:");
	for (i = 0; i < AC_GRP_CNT_TBL_MAX_ENTRY; i++) {
		aos_mem_zero(&grp_cnt, sizeof(grp_cnt));
		httppe_ac_grp_cnt_tbl_get(dev_id, i, &grp_cnt);
		adpt_hppe_debug_value_print(buf, count, &tags,
				grp_cnt.bf.ac_grp_cnt, "group", 0, i);
	}
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
}

void
adpt_httppe_debug_bm_group_counter_get(a_uint32_t dev_id, char **buf, ssize_t *count)
{
	union shared_group_cnt_u group_cnt;
	union port_cnt_u port_cnt;
	union port_reacted_cnt_u port_reacted_cnt;
	int i, tags = 0;

	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "BM_PORT_USED_CNT:");
	for (i = 0; i < PORT_CNT_MAX_ENTRY; i++) {
		aos_mem_zero(&port_cnt, sizeof(port_cnt));
		httppe_port_cnt_get(dev_id, i, &port_cnt);
		adpt_hppe_debug_value_print(buf, count, &tags,
				port_cnt.bf.port_cnt, "port", 0, i);
	}
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");

	tags = 0;
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "BM_PORT_REACT_CNT:");
	for (i = 0; i < PORT_REACTED_CNT_MAX_ENTRY; i++) {
		aos_mem_zero(&port_reacted_cnt, sizeof(port_reacted_cnt));
		httppe_port_reacted_cnt_get(dev_id, i, &port_reacted_cnt);
		adpt_hppe_debug_value_print(buf, count, &tags,
				port_reacted_cnt.bf.port_reacted_cnt, "port", 0, i);
	}
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");

	tags = 0;
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "BM_SHARED_GROUP_CNT:");
	for (i = 0; i < SHARED_GROUP_CNT_MAX_ENTRY; i++) {
		aos_mem_zero(&group_cnt, sizeof(group_cnt));
		httppe_shared_group_cnt_get(dev_id, i, &group_cnt);
		adpt_hppe_debug_value_print(buf, count, &tags,
				group_cnt.bf.shared_group_cnt, "group", 0, i);
	}
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
}

void
adpt_httppe_queue_tx_counter_tbl_set(a_uint32_t dev_id)
{
	union queue_tx_counter_tbl_u queue_tx_counter_tbl = {0};
	a_uint32_t i;

	for (i = 0; i < QUEUE_TX_COUNTER_TBL_MAX_ENTRY; i++)
		httppe_queue_tx_counter_tbl_set(dev_id, i, &queue_tx_counter_tbl);
}

void
adpt_httppe_debug_drop_cpu_counter_get(a_uint32_t dev_id, a_bool_t show_type,
		char **buf, ssize_t *count, a_uint32_t sd_size)
{
	union drop_cpu_cnt_tbl_u drop_cpu_cnt_tbl;
	a_uint64_t value;
	int i, tags, sign;
	int drop_code_idx;

	sign = tags = 0;
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "DROP_CPU_CNT_TBL:");
	for (i = CPU_CODE_CNT_TBL_MAX_ENTRY; i < DROP_CPU_CNT_TBL_MAX_ENTRY; i++)
	{
		httppe_drop_cpu_cnt_tbl_get(dev_id, i, &drop_cpu_cnt_tbl);
		if (show_type == A_FALSE)
			value = (a_uint64_t)drop_cpu_cnt_tbl.bf.pkt_cnt;
		else
			value = drop_cpu_cnt_tbl.bf.byte_cnt_0 | ((a_uint64_t)drop_cpu_cnt_tbl.bf.byte_cnt_1 << 32);
		if (value > 0)
		{
			drop_code_idx = (i - CPU_CODE_CNT_TBL_MAX_ENTRY) / HTTPPE_MAX_PORT_NUM;

			*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
			*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "");

			/* Special print without changing global arry */
			if (drop_code_idx == HTTPPE_DOT1P_MISS_DROP_CODE)
				*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count),
					"%15llu(port=%d:Dot1p miss action drop),dropcode:%d",
					value, (i - CPU_CODE_CNT_TBL_MAX_ENTRY) % HTTPPE_MAX_PORT_NUM, drop_code_idx);
			else if (drop_code_idx >= 0 && drop_code_idx < sd_size)
				*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%15llu(port=%d:%s),dropcode:%d",
					value, (i - CPU_CODE_CNT_TBL_MAX_ENTRY) % HTTPPE_MAX_PORT_NUM,
					dropcode[drop_code_idx], drop_code_idx);
			else
				*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%15llu(port=%d:Unknown),dropcode:%d",
					value, (i - CPU_CODE_CNT_TBL_MAX_ENTRY) % HTTPPE_MAX_PORT_NUM, drop_code_idx);
		}
	}
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
}

void
adpt_httppe_debug_drop_cpu_counter_set(a_uint32_t dev_id)
{
	union drop_cpu_cnt_tbl_u drop_cpu_cnt_tbl = {0};
	a_uint32_t i;

	for (i = 0; i < DROP_CPU_CNT_TBL_MAX_ENTRY; i++)
		httppe_drop_cpu_cnt_tbl_set(dev_id, i, &drop_cpu_cnt_tbl);
}

void
adpt_httppe_debug_eg_vsi_counter_get(a_uint32_t dev_id, a_bool_t show_type, char **buf, ssize_t *count)
{
	union eg_vsi_counter_tbl_u eg_vsi_counter_tbl;
	a_uint64_t value;
	int i, tags, sign;

	sign = tags = 0;
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "EG_VSI_COUNTER_TBL TX:");
	for (i = 0; i < EG_VSI_COUNTER_TBL_MAX_ENTRY; i++)
	{
		httppe_eg_vsi_counter_tbl_get(dev_id, i, &eg_vsi_counter_tbl);
		if (show_type == A_FALSE)
			value = (a_uint64_t)eg_vsi_counter_tbl.bf.tx_packets;
		else
			value = eg_vsi_counter_tbl.bf.tx_bytes_0 | ((a_uint64_t)eg_vsi_counter_tbl.bf.tx_bytes_1 << 32);
		if (value > 0)
		{
			if (sign) {
				*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
				*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "");
			}
			sign = 0;
			*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%15llu(vsi=%04d)", value, i);
			if (++tags % 3 == 0)
				sign = 1;
		}
	}
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
}

void
adpt_httppe_debug_port_tx_counter_get(a_uint32_t dev_id, a_bool_t show_type, char **buf, ssize_t *count)
{
	union port_tx_counter_tbl_reg_u port_tx_counter_tbl;
	a_uint64_t value;
	int i, tags, sign;

	sign = tags = 0;
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "PORT_TX_COUNTER_TBL TX:");
	for (i = 0; i < PORT_TX_COUNTER_TBL_REG_MAX_ENTRY; i++)
	{
		httppe_port_tx_counter_tbl_reg_get(dev_id, i, &port_tx_counter_tbl);
		if (show_type == A_FALSE)
			value = (a_uint64_t)port_tx_counter_tbl.bf.tx_packets;
		else
			value = port_tx_counter_tbl.bf.tx_bytes_0 | ((a_uint64_t)port_tx_counter_tbl.bf.tx_bytes_1 << 32);
		if (value > 0)
		{
			if (sign) {
				*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
				*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "");
			}
			sign = 0;
			*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%15llu(port=%04d)", value, i);
			if (++tags % 3 == 0)
				sign = 1;
		}
	}
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
}

sw_error_t
adpt_httppe_eg_vsi_counter_tbl_set(a_uint32_t dev_id)
{
	sw_error_t rtn = SW_OK;
	union eg_vsi_counter_tbl_u eg_vsi_counter_tbl = {0};
	a_uint32_t i;

	ADPT_DEV_ID_CHECK(dev_id);

	for (i = 0; i < EG_VSI_COUNTER_TBL_MAX_ENTRY; i++) {
		rtn = httppe_eg_vsi_counter_tbl_set(dev_id, i, &eg_vsi_counter_tbl);
		SW_RTN_ON_ERROR(rtn);
	}

	return rtn;
}

sw_error_t
adpt_httppe_port_tx_counter_tbl_set(a_uint32_t dev_id)
{
	sw_error_t rtn = SW_OK;
	union port_tx_counter_tbl_reg_u port_tx_counter_tbl = {0};
	a_uint32_t i;

	ADPT_DEV_ID_CHECK(dev_id);

	for (i = 0; i < PORT_TX_COUNTER_TBL_REG_MAX_ENTRY; i++) {
		rtn = httppe_port_tx_counter_tbl_reg_set(dev_id, i, &port_tx_counter_tbl);
		SW_RTN_ON_ERROR(rtn);
	}

	return rtn;
}

void
adpt_httppe_debug_vp_tx_counter_get(a_uint32_t dev_id, a_bool_t show_type, char **buf, ssize_t *count)
{
	union vp_tx_counter_tbl_reg_u vp_tx_counter_tbl;
	a_uint64_t value;
	int i, tags, sign;

	sign = tags = 0;
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "VP_TX_COUNTER_TBL TX:");
	for (i = 0; i < VP_TX_COUNTER_TBL_REG_MAX_ENTRY; i++)
	{
		httppe_vp_tx_counter_tbl_reg_get(dev_id, i, &vp_tx_counter_tbl);
		if (show_type == A_FALSE)
			value = (a_uint64_t)vp_tx_counter_tbl.bf.tx_packets;
		else
			value = vp_tx_counter_tbl.bf.tx_bytes_0 | ((a_uint64_t)vp_tx_counter_tbl.bf.tx_bytes_1 << 32);
		if (value > 0)
		{
			if (sign) {
				*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
				*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%-35s", "");
			}
			sign = 0;
			*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "%15llu(port=%04d)", value, i);
			if (++tags % 3 == 0)
				sign = 1;
		}
	}
	*count += scnprintf(*buf + *count, SSDK_BUF_REMAINING(count), "\n");
}

sw_error_t
adpt_httppe_vp_tx_counter_tbl_set(a_uint32_t dev_id)
{
	sw_error_t rtn = SW_OK;
	union vp_tx_counter_tbl_reg_u vp_tx_cnt_tbl = {0};
	a_uint32_t i;

	ADPT_DEV_ID_CHECK(dev_id);

	for (i = 0; i < VP_TX_COUNTER_TBL_REG_MAX_ENTRY; i++) {
		rtn = httppe_vp_tx_counter_tbl_reg_set(dev_id, i, &vp_tx_cnt_tbl);
		SW_RTN_ON_ERROR(rtn);
	}

	return rtn;
}

/**
 * @}
 */
