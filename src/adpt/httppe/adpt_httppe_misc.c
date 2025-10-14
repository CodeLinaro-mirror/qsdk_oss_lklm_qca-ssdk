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

void
adpt_httppe_debug_queue_tx_counter_get(a_uint32_t dev_id, a_bool_t show_type, char **buf, ssize_t *count)
{
	union queue_tx_counter_tbl_u queue_tx_counter_tbl;
	a_uint64_t value;
	int i, tags, sign;

	sign = tags = 0;
	*count += scnprintf(*buf + *count, PAGE_SIZE - *count,"%-35s", "QUEUE_TX_COUNTER_TBL TX:");
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
				*count += scnprintf(*buf + *count, PAGE_SIZE - *count, "\n");
				*count += scnprintf(*buf + *count, PAGE_SIZE - *count, "%-35s", "");
			}
			sign = 0;
			*count += scnprintf(*buf + *count, PAGE_SIZE - *count, "%15llu(queue=%04d)", value, i);
			if (++tags % 3 == 0)
				sign = 1;
		}
	}
	*count += scnprintf(*buf + *count, PAGE_SIZE - *count, "\n");
}

void
adpt_httppe_queue_tx_counter_tbl_set(a_uint32_t dev_id)
{
	union queue_tx_counter_tbl_u queue_tx_counter_tbl = {0};
	a_uint32_t i;

	for (i = 0; i < QUEUE_TX_COUNTER_TBL_MAX_ENTRY; i++)
		httppe_queue_tx_counter_tbl_set(dev_id, i, &queue_tx_counter_tbl);
}

/**
 * @}
 */
