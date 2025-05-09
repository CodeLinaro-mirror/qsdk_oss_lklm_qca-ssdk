/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 *
 * Copyright (c) 2022, 2025 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
/**
 * @defgroup
 * @{
 */
#include "hsl_reg.h"

sw_error_t
hppe_queue_tx_counter_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union queue_tx_counter_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + QUEUE_TX_COUNTER_TBL_ADDRESS + \
				index * QUEUE_TX_COUNTER_TBL_INC,
				value->val,
				sizeof(union queue_tx_counter_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_queue_tx_counter_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union queue_tx_counter_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				NSS_PTX_CSR_BASE_ADDR + QUEUE_TX_COUNTER_TBL_ADDRESS + \
				index * QUEUE_TX_COUNTER_TBL_INC,
				value->val,
				sizeof(union queue_tx_counter_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_flush_cfg_get(
		a_uint32_t dev_id,
		union flush_cfg_u *value)
{
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + FLUSH_CFG_ADDRESS,
				&value->val);
}

sw_error_t
hppe_flush_cfg_set(
		a_uint32_t dev_id,
		union flush_cfg_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + FLUSH_CFG_ADDRESS,
				value->val);
}

sw_error_t
hppe_in_mirror_priority_ctrl_get(
		a_uint32_t dev_id,
		union in_mirror_priority_ctrl_u *value)
{
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + IN_MIRROR_PRIORITY_CTRL_ADDRESS,
				&value->val);
}

sw_error_t
hppe_in_mirror_priority_ctrl_set(
		a_uint32_t dev_id,
		union in_mirror_priority_ctrl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + IN_MIRROR_PRIORITY_CTRL_ADDRESS,
				value->val);
}

sw_error_t
hppe_eg_mirror_priority_ctrl_get(
		a_uint32_t dev_id,
		union eg_mirror_priority_ctrl_u *value)
{
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + EG_MIRROR_PRIORITY_CTRL_ADDRESS,
				&value->val);
}

sw_error_t
hppe_eg_mirror_priority_ctrl_set(
		a_uint32_t dev_id,
		union eg_mirror_priority_ctrl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + EG_MIRROR_PRIORITY_CTRL_ADDRESS,
				value->val);
}

sw_error_t
hppe_ucast_default_hash_get(
		a_uint32_t dev_id,
		union ucast_default_hash_u *value)
{
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_DEFAULT_HASH_ADDRESS,
				&value->val);
}

sw_error_t
hppe_ucast_default_hash_set(
		a_uint32_t dev_id,
		union ucast_default_hash_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_DEFAULT_HASH_ADDRESS,
				value->val);
}

sw_error_t
hppe_spare_reg0_get(
		a_uint32_t dev_id,
		union spare_reg0_u *value)
{
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + SPARE_REG0_ADDRESS,
				&value->val);
}

sw_error_t
hppe_spare_reg0_set(
		a_uint32_t dev_id,
		union spare_reg0_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + SPARE_REG0_ADDRESS,
				value->val);
}

sw_error_t
hppe_spare_reg1_get(
		a_uint32_t dev_id,
		union spare_reg1_u *value)
{
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + SPARE_REG1_ADDRESS,
				&value->val);
}

sw_error_t
hppe_spare_reg1_set(
		a_uint32_t dev_id,
		union spare_reg1_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + SPARE_REG1_ADDRESS,
				value->val);
}

sw_error_t
hppe_mcast_priority_map0_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map0_u *value)
{
	if (index >= MCAST_PRIORITY_MAP0_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP0_ADDRESS + \
				index * MCAST_PRIORITY_MAP0_INC,
				&value->val);
}

sw_error_t
hppe_mcast_priority_map0_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map0_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP0_ADDRESS + \
				index * MCAST_PRIORITY_MAP0_INC,
				value->val);
}

sw_error_t
hppe_mcast_priority_map1_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map1_u *value)
{
	if (index >= MCAST_PRIORITY_MAP1_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP1_ADDRESS + \
				index * MCAST_PRIORITY_MAP1_INC,
				&value->val);
}

sw_error_t
hppe_mcast_priority_map1_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map1_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP1_ADDRESS + \
				index * MCAST_PRIORITY_MAP1_INC,
				value->val);
}

sw_error_t
hppe_mcast_priority_map2_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map2_u *value)
{
	if (index >= MCAST_PRIORITY_MAP2_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP2_ADDRESS + \
				index * MCAST_PRIORITY_MAP2_INC,
				&value->val);
}

sw_error_t
hppe_mcast_priority_map2_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map2_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP2_ADDRESS + \
				index * MCAST_PRIORITY_MAP2_INC,
				value->val);
}

sw_error_t
hppe_mcast_priority_map3_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map3_u *value)
{
	if (index >= MCAST_PRIORITY_MAP3_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP3_ADDRESS + \
				index * MCAST_PRIORITY_MAP3_INC,
				&value->val);
}

sw_error_t
hppe_mcast_priority_map3_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map3_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP3_ADDRESS + \
				index * MCAST_PRIORITY_MAP3_INC,
				value->val);
}

sw_error_t
hppe_mcast_priority_map4_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map4_u *value)
{
	if (index >= MCAST_PRIORITY_MAP4_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP4_ADDRESS + \
				index * MCAST_PRIORITY_MAP4_INC,
				&value->val);
}

sw_error_t
hppe_mcast_priority_map4_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map4_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP4_ADDRESS + \
				index * MCAST_PRIORITY_MAP4_INC,
				value->val);
}

sw_error_t
hppe_mcast_priority_map5_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map5_u *value)
{
	if (index >= MCAST_PRIORITY_MAP5_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP5_ADDRESS + \
				index * MCAST_PRIORITY_MAP5_INC,
				&value->val);
}

sw_error_t
hppe_mcast_priority_map5_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map5_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP5_ADDRESS + \
				index * MCAST_PRIORITY_MAP5_INC,
				value->val);
}

sw_error_t
hppe_mcast_priority_map6_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map6_u *value)
{
	if (index >= MCAST_PRIORITY_MAP6_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP6_ADDRESS + \
				index * MCAST_PRIORITY_MAP6_INC,
				&value->val);
}

sw_error_t
hppe_mcast_priority_map6_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map6_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP6_ADDRESS + \
				index * MCAST_PRIORITY_MAP6_INC,
				value->val);
}

sw_error_t
hppe_mcast_priority_map7_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map7_u *value)
{
	if (index >= MCAST_PRIORITY_MAP7_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP7_ADDRESS + \
				index * MCAST_PRIORITY_MAP7_INC,
				&value->val);
}

sw_error_t
hppe_mcast_priority_map7_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_priority_map7_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_PRIORITY_MAP7_ADDRESS + \
				index * MCAST_PRIORITY_MAP7_INC,
				value->val);
}

sw_error_t
hppe_ucast_queue_map_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_map_tbl_u *value)
{
	if (index >= UCAST_QUEUE_MAP_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_QUEUE_MAP_TBL_ADDRESS + \
				index * UCAST_QUEUE_MAP_TBL_INC,
				&value->val);
}

sw_error_t
hppe_ucast_queue_map_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_queue_map_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_QUEUE_MAP_TBL_ADDRESS + \
				index * UCAST_QUEUE_MAP_TBL_INC,
				value->val);
}

sw_error_t
hppe_ucast_hash_map_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_hash_map_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_HASH_MAP_TBL_ADDRESS + \
				index * UCAST_HASH_MAP_TBL_INC,
				value->val);
}

sw_error_t
hppe_ucast_hash_map_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_hash_map_tbl_u *value)
{
	if (index >= UCAST_HASH_MAP_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_HASH_MAP_TBL_ADDRESS + \
				index * UCAST_HASH_MAP_TBL_INC,
				&value->val);
}

sw_error_t
hppe_ucast_priority_map_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_priority_map_tbl_u *value)
{
	if (index >= UCAST_PRIORITY_MAP_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_PRIORITY_MAP_TBL_ADDRESS + \
				index * UCAST_PRIORITY_MAP_TBL_INC,
				&value->val);
}

sw_error_t
hppe_ucast_priority_map_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ucast_priority_map_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UCAST_PRIORITY_MAP_TBL_ADDRESS + \
				index * UCAST_PRIORITY_MAP_TBL_INC,
				value->val);
}

sw_error_t
hppe_mcast_queue_map_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_queue_map_tbl_u *value)
{
	if (index >= MCAST_QUEUE_MAP_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_QUEUE_MAP_TBL_ADDRESS + \
				index * MCAST_QUEUE_MAP_TBL_INC,
				&value->val);
}

sw_error_t
hppe_mcast_queue_map_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mcast_queue_map_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MCAST_QUEUE_MAP_TBL_ADDRESS + \
				index * MCAST_QUEUE_MAP_TBL_INC,
				value->val);
}

sw_error_t
hppe_ac_mseq_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_mseq_tbl_u *value)
{
	if (index >= AC_MSEQ_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_MSEQ_TBL_ADDRESS + \
				index * AC_MSEQ_TBL_INC,
				&value->val);
}

sw_error_t
hppe_ac_mseq_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_mseq_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_MSEQ_TBL_ADDRESS + \
				index * AC_MSEQ_TBL_INC,
				value->val);
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_uni_queue_cfg_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_UNI_QUEUE_CFG_TBL_ADDRESS + \
				index * AC_UNI_QUEUE_CFG_TBL_INC,
				value->val,
				sizeof(union ac_uni_queue_cfg_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_uni_queue_cfg_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_UNI_QUEUE_CFG_TBL_ADDRESS + \
				index * AC_UNI_QUEUE_CFG_TBL_INC,
				value->val,
				sizeof(union ac_uni_queue_cfg_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_mul_queue_cfg_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_MUL_QUEUE_CFG_TBL_ADDRESS + \
				index * AC_MUL_QUEUE_CFG_TBL_INC,
				value->val,
				sizeof(union ac_mul_queue_cfg_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_mul_queue_cfg_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_MUL_QUEUE_CFG_TBL_ADDRESS + \
				index * AC_MUL_QUEUE_CFG_TBL_INC,
				value->val,
				sizeof(union ac_mul_queue_cfg_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_ac_grp_cfg_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_grp_cfg_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_GRP_CFG_TBL_ADDRESS + \
				index * AC_GRP_CFG_TBL_INC,
				value->val,
				sizeof(union ac_grp_cfg_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_ac_grp_cfg_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_grp_cfg_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_GRP_CFG_TBL_ADDRESS + \
				index * AC_GRP_CFG_TBL_INC,
				value->val,
				sizeof(union ac_grp_cfg_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_ac_uni_queue_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_uni_queue_cnt_tbl_u *value)
{
	if (index >= AC_UNI_QUEUE_CNT_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_UNI_QUEUE_CNT_TBL_ADDRESS + \
				index * AC_UNI_QUEUE_CNT_TBL_INC,
				&value->val);
}

sw_error_t
hppe_ac_uni_queue_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_uni_queue_cnt_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_UNI_QUEUE_CNT_TBL_ADDRESS + \
				index * AC_UNI_QUEUE_CNT_TBL_INC,
				value->val);
}

sw_error_t
hppe_ac_mul_queue_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_mul_queue_cnt_tbl_u *value)
{
	if (index >= AC_MUL_QUEUE_CNT_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_MUL_QUEUE_CNT_TBL_ADDRESS + \
				index * AC_MUL_QUEUE_CNT_TBL_INC,
				&value->val);
}

sw_error_t
hppe_ac_mul_queue_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_mul_queue_cnt_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_MUL_QUEUE_CNT_TBL_ADDRESS + \
				index * AC_MUL_QUEUE_CNT_TBL_INC,
				value->val);
}

sw_error_t
hppe_ac_grp_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_grp_cnt_tbl_u *value)
{
	if (index >= AC_GRP_CNT_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_GRP_CNT_TBL_ADDRESS + \
				index * AC_GRP_CNT_TBL_INC,
				&value->val);
}

sw_error_t
hppe_ac_grp_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_grp_cnt_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_GRP_CNT_TBL_ADDRESS + \
				index * AC_GRP_CNT_TBL_INC,
				value->val);
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_uni_queue_drop_state_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_UNI_QUEUE_DROP_STATE_TBL_ADDRESS + \
				index * AC_UNI_QUEUE_DROP_STATE_TBL_INC,
				value->val,
				sizeof(union ac_uni_queue_drop_state_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_uni_queue_drop_state_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_UNI_QUEUE_DROP_STATE_TBL_ADDRESS + \
				index * AC_UNI_QUEUE_DROP_STATE_TBL_INC,
				value->val,
				sizeof(union ac_uni_queue_drop_state_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_mul_queue_drop_state_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_MUL_QUEUE_DROP_STATE_TBL_ADDRESS + \
				index * AC_MUL_QUEUE_DROP_STATE_TBL_INC,
				value->val,
				sizeof(union ac_mul_queue_drop_state_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_mul_queue_drop_state_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_MUL_QUEUE_DROP_STATE_TBL_ADDRESS + \
				index * AC_MUL_QUEUE_DROP_STATE_TBL_INC,
				value->val,
				sizeof(union ac_mul_queue_drop_state_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_ac_grp_drop_state_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_grp_drop_state_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_GRP_DROP_STATE_TBL_ADDRESS + \
				index * AC_GRP_DROP_STATE_TBL_INC,
				value->val,
				sizeof(union ac_grp_drop_state_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_ac_grp_drop_state_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ac_grp_drop_state_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + AC_GRP_DROP_STATE_TBL_ADDRESS + \
				index * AC_GRP_DROP_STATE_TBL_INC,
				value->val,
				sizeof(union ac_grp_drop_state_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_oq_enq_opr_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_enq_opr_tbl_u *value)
{
	if (index >= OQ_ENQ_OPR_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_ENQ_OPR_TBL_ADDRESS + \
				index * OQ_ENQ_OPR_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_enq_opr_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_enq_opr_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_ENQ_OPR_TBL_ADDRESS + \
				index * OQ_ENQ_OPR_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_deq_opr_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_deq_opr_tbl_u *value)
{
	if (index >= OQ_DEQ_OPR_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_DEQ_OPR_TBL_ADDRESS + \
				index * OQ_DEQ_OPR_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_deq_opr_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_deq_opr_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_DEQ_OPR_TBL_ADDRESS + \
				index * OQ_DEQ_OPR_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_head_uni_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_head_uni_tbl_u *value)
{
	if (index >= OQ_HEAD_UNI_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_HEAD_UNI_TBL_ADDRESS + \
				index * OQ_HEAD_UNI_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_head_uni_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_head_uni_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_HEAD_UNI_TBL_ADDRESS + \
				index * OQ_HEAD_UNI_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_head_mul_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_head_mul_tbl_u *value)
{
	if (index >= OQ_HEAD_MUL_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_HEAD_MUL_TBL_ADDRESS + \
				index * OQ_HEAD_MUL_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_head_mul_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_head_mul_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_HEAD_MUL_TBL_ADDRESS + \
				index * OQ_HEAD_MUL_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_ll_uni_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_uni_tbl_u *value)
{
	if (index >= OQ_LL_UNI_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_UNI_TBL_ADDRESS + \
				index * OQ_LL_UNI_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_ll_uni_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_uni_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_UNI_TBL_ADDRESS + \
				index * OQ_LL_UNI_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_ll_mul_p0_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p0_tbl_u *value)
{
	if (index >= OQ_LL_MUL_P0_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P0_TBL_ADDRESS + \
				index * OQ_LL_MUL_P0_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_ll_mul_p0_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p0_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P0_TBL_ADDRESS + \
				index * OQ_LL_MUL_P0_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_ll_mul_p1_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p1_tbl_u *value)
{
	if (index >= OQ_LL_MUL_P1_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P1_TBL_ADDRESS + \
				index * OQ_LL_MUL_P1_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_ll_mul_p1_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p1_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P1_TBL_ADDRESS + \
				index * OQ_LL_MUL_P1_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_ll_mul_p2_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p2_tbl_u *value)
{
	if (index >= OQ_LL_MUL_P2_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P2_TBL_ADDRESS + \
				index * OQ_LL_MUL_P2_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_ll_mul_p2_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p2_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P2_TBL_ADDRESS + \
				index * OQ_LL_MUL_P2_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_ll_mul_p3_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p3_tbl_u *value)
{
	if (index >= OQ_LL_MUL_P3_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P3_TBL_ADDRESS + \
				index * OQ_LL_MUL_P3_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_ll_mul_p3_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p3_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P3_TBL_ADDRESS + \
				index * OQ_LL_MUL_P3_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_ll_mul_p4_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p4_tbl_u *value)
{
	if (index >= OQ_LL_MUL_P4_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P4_TBL_ADDRESS + \
				index * OQ_LL_MUL_P4_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_ll_mul_p4_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p4_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P4_TBL_ADDRESS + \
				index * OQ_LL_MUL_P4_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_ll_mul_p5_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p5_tbl_u *value)
{
	if (index >= OQ_LL_MUL_P5_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P5_TBL_ADDRESS + \
				index * OQ_LL_MUL_P5_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_ll_mul_p5_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p5_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P5_TBL_ADDRESS + \
				index * OQ_LL_MUL_P5_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_ll_mul_p6_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p6_tbl_u *value)
{
	if (index >= OQ_LL_MUL_P6_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P6_TBL_ADDRESS + \
				index * OQ_LL_MUL_P6_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_ll_mul_p6_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p6_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P6_TBL_ADDRESS + \
				index * OQ_LL_MUL_P6_TBL_INC,
				value->val);
}

sw_error_t
hppe_oq_ll_mul_p7_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p7_tbl_u *value)
{
	if (index >= OQ_LL_MUL_P7_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P7_TBL_ADDRESS + \
				index * OQ_LL_MUL_P7_TBL_INC,
				&value->val);
}

sw_error_t
hppe_oq_ll_mul_p7_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union oq_ll_mul_p7_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + OQ_LL_MUL_P7_TBL_ADDRESS + \
				index * OQ_LL_MUL_P7_TBL_INC,
				value->val);
}

sw_error_t
hppe_pkt_desp_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pkt_desp_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + PKT_DESP_TBL_ADDRESS + \
				index * PKT_DESP_TBL_INC,
				value->val,
				sizeof(union pkt_desp_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_pkt_desp_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union pkt_desp_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + PKT_DESP_TBL_ADDRESS + \
				index * PKT_DESP_TBL_INC,
				value->val,
				sizeof(union pkt_desp_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_uni_drop_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union uni_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UNI_DROP_CNT_TBL_ADDRESS + \
				index * UNI_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union uni_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_uni_drop_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union uni_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + UNI_DROP_CNT_TBL_ADDRESS + \
				index * UNI_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union uni_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p0_drop_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p0_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P0_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P0_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p0_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p0_drop_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p0_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P0_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P0_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p0_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p1_drop_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p1_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P1_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P1_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p1_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p1_drop_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p1_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P1_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P1_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p1_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p2_drop_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p2_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P2_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P2_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p2_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p2_drop_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p2_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P2_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P2_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p2_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p3_drop_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p3_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P3_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P3_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p3_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p3_drop_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p3_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P3_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P3_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p3_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p4_drop_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p4_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P4_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P4_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p4_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p4_drop_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p4_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P4_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P4_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p4_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p5_drop_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p5_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P5_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P5_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p5_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p5_drop_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p5_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P5_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P5_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p5_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p6_drop_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p6_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P6_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P6_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p6_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p6_drop_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p6_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P6_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P6_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p6_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p7_drop_cnt_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p7_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P7_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P7_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p7_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_mul_p7_drop_cnt_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union mul_p7_drop_cnt_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				QUEUE_MANAGER_BASE_ADDR + MUL_P7_DROP_CNT_TBL_ADDRESS + \
				index * MUL_P7_DROP_CNT_TBL_INC,
				value->val,
				sizeof(union mul_p7_drop_cnt_tbl_u)/sizeof(a_uint32_t));
}

sw_error_t
hppe_flush_cfg_flush_busy_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	*value = reg_val.bf.flush_busy;
	return ret;
}

sw_error_t
hppe_flush_cfg_flush_busy_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.flush_busy = value;
	ret = hppe_flush_cfg_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
hppe_flush_cfg_flush_qid_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	*value = reg_val.bf.flush_qid;
	return ret;
}

sw_error_t
hppe_flush_cfg_flush_qid_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.flush_qid = value;
	ret = hppe_flush_cfg_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
hppe_flush_cfg_flush_dst_port_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	*value = reg_val.bf.flush_dst_port;
	return ret;
}

sw_error_t
hppe_flush_cfg_flush_dst_port_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.flush_dst_port = value;
	ret = hppe_flush_cfg_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
hppe_flush_cfg_flush_all_queues_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	*value = reg_val.bf.flush_all_queues;
	return ret;
}

sw_error_t
hppe_flush_cfg_flush_all_queues_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.flush_all_queues = value;
	ret = hppe_flush_cfg_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
hppe_flush_cfg_flush_wt_time_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	*value = reg_val.bf.flush_wt_time;
	return ret;
}

sw_error_t
hppe_flush_cfg_flush_wt_time_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.flush_wt_time = value;
	ret = hppe_flush_cfg_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
hppe_flush_cfg_flush_status_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	*value = reg_val.bf.flush_status;
	return ret;
}

sw_error_t
hppe_flush_cfg_flush_status_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union flush_cfg_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_flush_cfg_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.flush_status = value;
	ret = hppe_flush_cfg_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
hppe_in_mirror_priority_ctrl_priority_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union in_mirror_priority_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_in_mirror_priority_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.priority;
	return ret;
}

sw_error_t
hppe_in_mirror_priority_ctrl_priority_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union in_mirror_priority_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_in_mirror_priority_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.priority = value;
	ret = hppe_in_mirror_priority_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
hppe_eg_mirror_priority_ctrl_priority_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union eg_mirror_priority_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_eg_mirror_priority_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.priority;
	return ret;
}

sw_error_t
hppe_eg_mirror_priority_ctrl_priority_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union eg_mirror_priority_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_eg_mirror_priority_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.priority = value;
	ret = hppe_eg_mirror_priority_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
hppe_ucast_default_hash_hash_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union ucast_default_hash_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ucast_default_hash_get(dev_id, &reg_val);
	*value = reg_val.bf.hash;
	return ret;
}

sw_error_t
hppe_ucast_default_hash_hash_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union ucast_default_hash_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ucast_default_hash_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.hash = value;
	ret = hppe_ucast_default_hash_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
hppe_spare_reg0_spare_reg0_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union spare_reg0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_spare_reg0_get(dev_id, &reg_val);
	*value = reg_val.bf.spare_reg0;
	return ret;
}

sw_error_t
hppe_spare_reg0_spare_reg0_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union spare_reg0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_spare_reg0_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.spare_reg0 = value;
	ret = hppe_spare_reg0_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
hppe_spare_reg1_spare_reg1_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union spare_reg1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_spare_reg1_get(dev_id, &reg_val);
	*value = reg_val.bf.spare_reg1;
	return ret;
}

sw_error_t
hppe_spare_reg1_spare_reg1_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union spare_reg1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_spare_reg1_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.spare_reg1 = value;
	ret = hppe_spare_reg1_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
hppe_ucast_hash_map_tbl_hash_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ucast_hash_map_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ucast_hash_map_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.hash;
	return ret;
}

sw_error_t
hppe_ucast_hash_map_tbl_hash_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ucast_hash_map_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ucast_hash_map_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.hash = value;
	ret = hppe_ucast_hash_map_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mcast_queue_map_tbl_class_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union mcast_queue_map_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mcast_queue_map_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.class;
	return ret;
}

sw_error_t
hppe_mcast_queue_map_tbl_class_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union mcast_queue_map_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mcast_queue_map_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.class = value;
	ret = hppe_mcast_queue_map_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mseq_tbl_ac_mseq_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mseq_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mseq_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_mseq;
	return ret;
}

sw_error_t
hppe_ac_mseq_tbl_ac_mseq_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mseq_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mseq_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_mseq = value;
	ret = hppe_ac_mseq_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_gap_grn_yel_max_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_gap_grn_yel_max;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_gap_grn_yel_max_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_gap_grn_yel_max = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_wred_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_wred_en;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_wred_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_wred_en = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_ac_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_ac_en;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_ac_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_ac_en = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_red_resume_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_red_resume_offset_1 << 9 | \
		reg_val.bf.ac_cfg_red_resume_offset_0;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_red_resume_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_red_resume_offset_1 = value >> 9;
	reg_val.bf.ac_cfg_red_resume_offset_0 = value & (((a_uint64_t)1<<9)-1);
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_grp_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_grp_id;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_grp_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_grp_id = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_color_aware_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_color_aware;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_color_aware_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_color_aware = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_yel_resume_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_yel_resume_offset;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_yel_resume_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_yel_resume_offset = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_gap_grn_yel_min_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_gap_grn_yel_min_1 << 10 | \
		reg_val.bf.ac_cfg_gap_grn_yel_min_0;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_gap_grn_yel_min_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_gap_grn_yel_min_1 = value >> 10;
	reg_val.bf.ac_cfg_gap_grn_yel_min_0 = value & (((a_uint64_t)1<<10)-1);
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_shared_weight_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_shared_weight;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_shared_weight_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_shared_weight = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_shared_dynamic_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_shared_dynamic;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_shared_dynamic_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_shared_dynamic = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_gap_grn_red_max_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_gap_grn_red_max;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_gap_grn_red_max_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_gap_grn_red_max = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_pre_alloc_limit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_pre_alloc_limit;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_pre_alloc_limit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_pre_alloc_limit = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_force_ac_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_force_ac_en;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_force_ac_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_force_ac_en = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_gap_grn_red_min_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_gap_grn_red_min;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_gap_grn_red_min_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_gap_grn_red_min = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_gap_grn_grn_min_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_gap_grn_grn_min;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_gap_grn_grn_min_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_gap_grn_grn_min = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_shared_ceiling_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_shared_ceiling;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_shared_ceiling_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_shared_ceiling = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_grn_resume_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_grn_resume_offset;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_cfg_tbl_ac_cfg_grn_resume_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_grn_resume_offset = value;
	ret = hppe_ac_uni_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_ac_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_ac_en;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_ac_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_ac_en = value;
	ret = hppe_ac_mul_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_red_resume_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_red_resume_offset;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_red_resume_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_red_resume_offset = value;
	ret = hppe_ac_mul_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_grp_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_grp_id;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_grp_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_grp_id = value;
	ret = hppe_ac_mul_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_color_aware_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_color_aware;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_color_aware_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_color_aware = value;
	ret = hppe_ac_mul_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_yel_resume_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_yel_resume_offset_1 << 4 | \
		reg_val.bf.ac_cfg_yel_resume_offset_0;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_yel_resume_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_yel_resume_offset_1 = value >> 4;
	reg_val.bf.ac_cfg_yel_resume_offset_0 = value & (((a_uint64_t)1<<4)-1);
	ret = hppe_ac_mul_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_pre_alloc_limit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_pre_alloc_limit;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_pre_alloc_limit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_pre_alloc_limit = value;
	ret = hppe_ac_mul_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_force_ac_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_force_ac_en;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_force_ac_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_force_ac_en = value;
	ret = hppe_ac_mul_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_shared_ceiling_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_shared_ceiling;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_shared_ceiling_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_shared_ceiling = value;
	ret = hppe_ac_mul_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_grn_resume_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_grn_resume_offset;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_grn_resume_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_grn_resume_offset = value;
	ret = hppe_ac_mul_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_gap_grn_yel_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_gap_grn_yel_1 << 5 | \
		reg_val.bf.ac_cfg_gap_grn_yel_0;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_gap_grn_yel_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_gap_grn_yel_1 = value >> 5;
	reg_val.bf.ac_cfg_gap_grn_yel_0 = value & (((a_uint64_t)1<<5)-1);
	ret = hppe_ac_mul_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_gap_grn_red_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_gap_grn_red;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_cfg_tbl_ac_cfg_gap_grn_red_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_gap_grn_red = value;
	ret = hppe_ac_mul_queue_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_grn_resume_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_grp_grn_resume_offset;
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_grn_resume_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_grp_grn_resume_offset = value;
	ret = hppe_ac_grp_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_dp_thrd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_grp_dp_thrd_1 << 7 | \
		reg_val.bf.ac_grp_dp_thrd_0;
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_dp_thrd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_grp_dp_thrd_1 = value >> 7;
	reg_val.bf.ac_grp_dp_thrd_0 = value & (((a_uint64_t)1<<7)-1);
	ret = hppe_ac_grp_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_cfg_ac_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_ac_en;
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_cfg_ac_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_ac_en = value;
	ret = hppe_ac_grp_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_palloc_limit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_grp_palloc_limit;
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_palloc_limit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_grp_palloc_limit = value;
	ret = hppe_ac_grp_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_cfg_color_aware_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_color_aware;
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_cfg_color_aware_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_color_aware = value;
	ret = hppe_ac_grp_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_red_resume_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_grp_red_resume_offset;
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_red_resume_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_grp_red_resume_offset = value;
	ret = hppe_ac_grp_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_gap_grn_yel_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_grp_gap_grn_yel;
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_gap_grn_yel_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_grp_gap_grn_yel = value;
	ret = hppe_ac_grp_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_cfg_force_ac_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_cfg_force_ac_en;
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_cfg_force_ac_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_cfg_force_ac_en = value;
	ret = hppe_ac_grp_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_yel_resume_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_grp_yel_resume_offset_1 << 6 | \
		reg_val.bf.ac_grp_yel_resume_offset_0;
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_yel_resume_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_grp_yel_resume_offset_1 = value >> 6;
	reg_val.bf.ac_grp_yel_resume_offset_0 = value & (((a_uint64_t)1<<6)-1);
	ret = hppe_ac_grp_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_gap_grn_red_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_grp_gap_grn_red;
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_gap_grn_red_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_grp_gap_grn_red = value;
	ret = hppe_ac_grp_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_limit_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_grp_limit;
	return ret;
}

sw_error_t
hppe_ac_grp_cfg_tbl_ac_grp_limit_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cfg_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cfg_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_grp_limit = value;
	ret = hppe_ac_grp_cfg_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cnt_tbl_ac_grp_alloc_used_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_grp_alloc_used;
	return ret;
}

sw_error_t
hppe_ac_grp_cnt_tbl_ac_grp_alloc_used_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_grp_alloc_used = value;
	ret = hppe_ac_grp_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_cnt_tbl_ac_grp_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ac_grp_cnt;
	return ret;
}

sw_error_t
hppe_ac_grp_cnt_tbl_ac_grp_cnt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ac_grp_cnt = value;
	ret = hppe_ac_grp_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_red_resume_thrd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.red_resume_thrd;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_red_resume_thrd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.red_resume_thrd = value;
	ret = hppe_ac_uni_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_red_drop_state_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.red_drop_state;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_red_drop_state_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.red_drop_state = value;
	ret = hppe_ac_uni_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_yel_resume_thrd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.yel_resume_thrd;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_yel_resume_thrd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.yel_resume_thrd = value;
	ret = hppe_ac_uni_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_grn_drop_state_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.grn_drop_state;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_grn_drop_state_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.grn_drop_state = value;
	ret = hppe_ac_uni_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_yel_drop_state_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.yel_drop_state;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_yel_drop_state_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.yel_drop_state = value;
	ret = hppe_ac_uni_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_grn_resume_thrd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.grn_resume_thrd_1 << 10 | \
		reg_val.bf.grn_resume_thrd_0;
	return ret;
}

sw_error_t
hppe_ac_uni_queue_drop_state_tbl_grn_resume_thrd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_uni_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_uni_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.grn_resume_thrd_1 = value >> 10;
	reg_val.bf.grn_resume_thrd_0 = value & (((a_uint64_t)1<<10)-1);
	ret = hppe_ac_uni_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_red_resume_thrd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.red_resume_thrd;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_red_resume_thrd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.red_resume_thrd = value;
	ret = hppe_ac_mul_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_red_drop_state_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.red_drop_state;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_red_drop_state_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.red_drop_state = value;
	ret = hppe_ac_mul_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_yel_resume_thrd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.yel_resume_thrd;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_yel_resume_thrd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.yel_resume_thrd = value;
	ret = hppe_ac_mul_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_grn_drop_state_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.grn_drop_state;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_grn_drop_state_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.grn_drop_state = value;
	ret = hppe_ac_mul_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_yel_drop_state_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.yel_drop_state;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_yel_drop_state_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.yel_drop_state = value;
	ret = hppe_ac_mul_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_grn_resume_thrd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.grn_resume_thrd_1 << 10 | \
		reg_val.bf.grn_resume_thrd_0;
	return ret;
}

sw_error_t
hppe_ac_mul_queue_drop_state_tbl_grn_resume_thrd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_mul_queue_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_mul_queue_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.grn_resume_thrd_1 = value >> 10;
	reg_val.bf.grn_resume_thrd_0 = value & (((a_uint64_t)1<<10)-1);
	ret = hppe_ac_mul_queue_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_red_resume_thrd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.red_resume_thrd;
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_red_resume_thrd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.red_resume_thrd = value;
	ret = hppe_ac_grp_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_red_drop_state_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.red_drop_state;
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_red_drop_state_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.red_drop_state = value;
	ret = hppe_ac_grp_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_yel_resume_thrd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.yel_resume_thrd;
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_yel_resume_thrd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.yel_resume_thrd = value;
	ret = hppe_ac_grp_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_grn_drop_state_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.grn_drop_state;
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_grn_drop_state_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.grn_drop_state = value;
	ret = hppe_ac_grp_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_yel_drop_state_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.yel_drop_state;
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_yel_drop_state_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.yel_drop_state = value;
	ret = hppe_ac_grp_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_grn_resume_thrd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.grn_resume_thrd_1 << 10 | \
		reg_val.bf.grn_resume_thrd_0;
	return ret;
}

sw_error_t
hppe_ac_grp_drop_state_tbl_grn_resume_thrd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ac_grp_drop_state_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_ac_grp_drop_state_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.grn_resume_thrd_1 = value >> 10;
	reg_val.bf.grn_resume_thrd_0 = value & (((a_uint64_t)1<<10)-1);
	ret = hppe_ac_grp_drop_state_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_deq_opr_tbl_deq_drop_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_deq_opr_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_deq_opr_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.deq_drop;
	return ret;
}

sw_error_t
hppe_oq_deq_opr_tbl_deq_drop_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_deq_opr_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_deq_opr_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.deq_drop = value;
	ret = hppe_oq_deq_opr_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_head_uni_tbl_head_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_head_uni_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_head_uni_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.head;
	return ret;
}

sw_error_t
hppe_oq_head_uni_tbl_head_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_head_uni_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_head_uni_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.head = value;
	ret = hppe_oq_head_uni_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_head_uni_tbl_tail_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_head_uni_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_head_uni_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.tail;
	return ret;
}

sw_error_t
hppe_oq_head_uni_tbl_tail_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_head_uni_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_head_uni_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tail = value;
	ret = hppe_oq_head_uni_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_head_uni_tbl_empty_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_head_uni_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_head_uni_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.empty;
	return ret;
}

sw_error_t
hppe_oq_head_uni_tbl_empty_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_head_uni_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_head_uni_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.empty = value;
	ret = hppe_oq_head_uni_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_uni_tbl_next_pointer_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_uni_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_uni_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.next_pointer;
	return ret;
}

sw_error_t
hppe_oq_ll_uni_tbl_next_pointer_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_uni_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_uni_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.next_pointer = value;
	ret = hppe_oq_ll_uni_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p0_tbl_next_pointer_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p0_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p0_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.next_pointer;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p0_tbl_next_pointer_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p0_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p0_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.next_pointer = value;
	ret = hppe_oq_ll_mul_p0_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p0_tbl_ingress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p0_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p0_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ingress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p0_tbl_ingress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p0_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p0_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ingress_mirr = value;
	ret = hppe_oq_ll_mul_p0_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p0_tbl_egress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p0_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p0_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.egress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p0_tbl_egress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p0_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p0_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.egress_mirr = value;
	ret = hppe_oq_ll_mul_p0_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p0_tbl_normal_fwd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p0_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p0_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.normal_fwd;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p0_tbl_normal_fwd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p0_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p0_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.normal_fwd = value;
	ret = hppe_oq_ll_mul_p0_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p1_tbl_next_pointer_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p1_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p1_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.next_pointer;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p1_tbl_next_pointer_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p1_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p1_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.next_pointer = value;
	ret = hppe_oq_ll_mul_p1_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p1_tbl_ingress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p1_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p1_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ingress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p1_tbl_ingress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p1_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p1_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ingress_mirr = value;
	ret = hppe_oq_ll_mul_p1_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p1_tbl_egress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p1_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p1_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.egress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p1_tbl_egress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p1_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p1_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.egress_mirr = value;
	ret = hppe_oq_ll_mul_p1_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p1_tbl_normal_fwd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p1_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p1_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.normal_fwd;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p1_tbl_normal_fwd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p1_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p1_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.normal_fwd = value;
	ret = hppe_oq_ll_mul_p1_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p2_tbl_next_pointer_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p2_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p2_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.next_pointer;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p2_tbl_next_pointer_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p2_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p2_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.next_pointer = value;
	ret = hppe_oq_ll_mul_p2_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p2_tbl_ingress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p2_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p2_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ingress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p2_tbl_ingress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p2_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p2_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ingress_mirr = value;
	ret = hppe_oq_ll_mul_p2_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p2_tbl_egress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p2_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p2_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.egress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p2_tbl_egress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p2_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p2_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.egress_mirr = value;
	ret = hppe_oq_ll_mul_p2_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p2_tbl_normal_fwd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p2_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p2_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.normal_fwd;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p2_tbl_normal_fwd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p2_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p2_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.normal_fwd = value;
	ret = hppe_oq_ll_mul_p2_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p3_tbl_next_pointer_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p3_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p3_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.next_pointer;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p3_tbl_next_pointer_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p3_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p3_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.next_pointer = value;
	ret = hppe_oq_ll_mul_p3_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p3_tbl_ingress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p3_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p3_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ingress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p3_tbl_ingress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p3_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p3_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ingress_mirr = value;
	ret = hppe_oq_ll_mul_p3_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p3_tbl_egress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p3_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p3_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.egress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p3_tbl_egress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p3_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p3_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.egress_mirr = value;
	ret = hppe_oq_ll_mul_p3_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p3_tbl_normal_fwd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p3_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p3_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.normal_fwd;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p3_tbl_normal_fwd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p3_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p3_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.normal_fwd = value;
	ret = hppe_oq_ll_mul_p3_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p4_tbl_next_pointer_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p4_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p4_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.next_pointer;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p4_tbl_next_pointer_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p4_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p4_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.next_pointer = value;
	ret = hppe_oq_ll_mul_p4_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p4_tbl_ingress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p4_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p4_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ingress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p4_tbl_ingress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p4_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p4_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ingress_mirr = value;
	ret = hppe_oq_ll_mul_p4_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p4_tbl_egress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p4_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p4_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.egress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p4_tbl_egress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p4_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p4_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.egress_mirr = value;
	ret = hppe_oq_ll_mul_p4_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p4_tbl_normal_fwd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p4_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p4_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.normal_fwd;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p4_tbl_normal_fwd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p4_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p4_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.normal_fwd = value;
	ret = hppe_oq_ll_mul_p4_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p5_tbl_next_pointer_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p5_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p5_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.next_pointer;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p5_tbl_next_pointer_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p5_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p5_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.next_pointer = value;
	ret = hppe_oq_ll_mul_p5_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p5_tbl_ingress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p5_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p5_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ingress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p5_tbl_ingress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p5_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p5_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ingress_mirr = value;
	ret = hppe_oq_ll_mul_p5_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p5_tbl_egress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p5_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p5_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.egress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p5_tbl_egress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p5_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p5_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.egress_mirr = value;
	ret = hppe_oq_ll_mul_p5_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p5_tbl_normal_fwd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p5_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p5_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.normal_fwd;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p5_tbl_normal_fwd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p5_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p5_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.normal_fwd = value;
	ret = hppe_oq_ll_mul_p5_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p6_tbl_next_pointer_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p6_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p6_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.next_pointer;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p6_tbl_next_pointer_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p6_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p6_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.next_pointer = value;
	ret = hppe_oq_ll_mul_p6_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p6_tbl_ingress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p6_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p6_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ingress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p6_tbl_ingress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p6_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p6_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ingress_mirr = value;
	ret = hppe_oq_ll_mul_p6_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p6_tbl_egress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p6_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p6_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.egress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p6_tbl_egress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p6_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p6_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.egress_mirr = value;
	ret = hppe_oq_ll_mul_p6_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p6_tbl_normal_fwd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p6_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p6_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.normal_fwd;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p6_tbl_normal_fwd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p6_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p6_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.normal_fwd = value;
	ret = hppe_oq_ll_mul_p6_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p7_tbl_next_pointer_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p7_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p7_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.next_pointer;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p7_tbl_next_pointer_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p7_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p7_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.next_pointer = value;
	ret = hppe_oq_ll_mul_p7_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p7_tbl_ingress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p7_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p7_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ingress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p7_tbl_ingress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p7_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p7_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ingress_mirr = value;
	ret = hppe_oq_ll_mul_p7_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p7_tbl_egress_mirr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p7_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p7_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.egress_mirr;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p7_tbl_egress_mirr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p7_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p7_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.egress_mirr = value;
	ret = hppe_oq_ll_mul_p7_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p7_tbl_normal_fwd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union oq_ll_mul_p7_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p7_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.normal_fwd;
	return ret;
}

sw_error_t
hppe_oq_ll_mul_p7_tbl_normal_fwd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union oq_ll_mul_p7_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_oq_ll_mul_p7_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.normal_fwd = value;
	ret = hppe_oq_ll_mul_p7_tbl_set(dev_id, index, &reg_val);
	return ret;
}
#ifdef HMSPPE

sw_error_t
hppe_uni_drop_cnt_tbl_uni_drop_byte_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union uni_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_uni_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.uni_drop_byte_1 << 32 | \
		reg_val.bf.uni_drop_byte_0;
	return ret;
}

sw_error_t
hppe_uni_drop_cnt_tbl_uni_drop_byte_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union uni_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_uni_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.uni_drop_byte_1 = value >> 32;
	reg_val.bf.uni_drop_byte_0 = value & (((a_uint64_t)1<<32)-1);
	ret = hppe_uni_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_uni_drop_cnt_tbl_uni_drop_pkt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union uni_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_uni_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.uni_drop_pkt;
	return ret;
}

sw_error_t
hppe_uni_drop_cnt_tbl_uni_drop_pkt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union uni_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_uni_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.uni_drop_pkt = value;
	ret = hppe_uni_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p0_drop_cnt_tbl_mul_p0_drop_pkt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union mul_p0_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p0_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.mul_p0_drop_pkt;
	return ret;
}

sw_error_t
hppe_mul_p0_drop_cnt_tbl_mul_p0_drop_pkt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union mul_p0_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p0_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p0_drop_pkt = value;
	ret = hppe_mul_p0_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p0_drop_cnt_tbl_mul_p0_drop_byte_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union mul_p0_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p0_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.mul_p0_drop_byte_1 << 32 | \
		reg_val.bf.mul_p0_drop_byte_0;
	return ret;
}

sw_error_t
hppe_mul_p0_drop_cnt_tbl_mul_p0_drop_byte_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union mul_p0_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p0_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p0_drop_byte_1 = value >> 32;
	reg_val.bf.mul_p0_drop_byte_0 = value & (((a_uint64_t)1<<32)-1);
	ret = hppe_mul_p0_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p1_drop_cnt_tbl_mul_p1_drop_byte_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union mul_p1_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p1_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.mul_p1_drop_byte_1 << 32 | \
		reg_val.bf.mul_p1_drop_byte_0;
	return ret;
}

sw_error_t
hppe_mul_p1_drop_cnt_tbl_mul_p1_drop_byte_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union mul_p1_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p1_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p1_drop_byte_1 = value >> 32;
	reg_val.bf.mul_p1_drop_byte_0 = value & (((a_uint64_t)1<<32)-1);
	ret = hppe_mul_p1_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p1_drop_cnt_tbl_mul_p1_drop_pkt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union mul_p1_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p1_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.mul_p1_drop_pkt;
	return ret;
}

sw_error_t
hppe_mul_p1_drop_cnt_tbl_mul_p1_drop_pkt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union mul_p1_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p1_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p1_drop_pkt = value;
	ret = hppe_mul_p1_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p2_drop_cnt_tbl_mul_p2_drop_pkt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union mul_p2_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p2_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.mul_p2_drop_pkt;
	return ret;
}

sw_error_t
hppe_mul_p2_drop_cnt_tbl_mul_p2_drop_pkt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union mul_p2_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p2_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p2_drop_pkt = value;
	ret = hppe_mul_p2_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p2_drop_cnt_tbl_mul_p2_drop_byte_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union mul_p2_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p2_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.mul_p2_drop_byte_1 << 32 | \
		reg_val.bf.mul_p2_drop_byte_0;
	return ret;
}

sw_error_t
hppe_mul_p2_drop_cnt_tbl_mul_p2_drop_byte_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union mul_p2_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p2_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p2_drop_byte_1 = value >> 32;
	reg_val.bf.mul_p2_drop_byte_0 = value & (((a_uint64_t)1<<32)-1);
	ret = hppe_mul_p2_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p3_drop_cnt_tbl_mul_p3_drop_pkt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union mul_p3_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p3_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.mul_p3_drop_pkt;
	return ret;
}

sw_error_t
hppe_mul_p3_drop_cnt_tbl_mul_p3_drop_pkt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union mul_p3_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p3_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p3_drop_pkt = value;
	ret = hppe_mul_p3_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p3_drop_cnt_tbl_mul_p3_drop_byte_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union mul_p3_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p3_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.mul_p3_drop_byte_1 << 32 | \
		reg_val.bf.mul_p3_drop_byte_0;
	return ret;
}

sw_error_t
hppe_mul_p3_drop_cnt_tbl_mul_p3_drop_byte_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union mul_p3_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p3_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p3_drop_byte_1 = value >> 32;
	reg_val.bf.mul_p3_drop_byte_0 = value & (((a_uint64_t)1<<32)-1);
	ret = hppe_mul_p3_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p4_drop_cnt_tbl_mul_p4_drop_pkt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union mul_p4_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p4_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.mul_p4_drop_pkt;
	return ret;
}

sw_error_t
hppe_mul_p4_drop_cnt_tbl_mul_p4_drop_pkt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union mul_p4_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p4_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p4_drop_pkt = value;
	ret = hppe_mul_p4_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p4_drop_cnt_tbl_mul_p4_drop_byte_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union mul_p4_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p4_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.mul_p4_drop_byte_1 << 32 | \
		reg_val.bf.mul_p4_drop_byte_0;
	return ret;
}

sw_error_t
hppe_mul_p4_drop_cnt_tbl_mul_p4_drop_byte_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union mul_p4_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p4_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p4_drop_byte_1 = value >> 32;
	reg_val.bf.mul_p4_drop_byte_0 = value & (((a_uint64_t)1<<32)-1);
	ret = hppe_mul_p4_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p5_drop_cnt_tbl_mul_p5_drop_byte_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union mul_p5_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p5_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.mul_p5_drop_byte_1 << 32 | \
		reg_val.bf.mul_p5_drop_byte_0;
	return ret;
}

sw_error_t
hppe_mul_p5_drop_cnt_tbl_mul_p5_drop_byte_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union mul_p5_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p5_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p5_drop_byte_1 = value >> 32;
	reg_val.bf.mul_p5_drop_byte_0 = value & (((a_uint64_t)1<<32)-1);
	ret = hppe_mul_p5_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p5_drop_cnt_tbl_mul_p5_drop_pkt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union mul_p5_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p5_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.mul_p5_drop_pkt;
	return ret;
}

sw_error_t
hppe_mul_p5_drop_cnt_tbl_mul_p5_drop_pkt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union mul_p5_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p5_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p5_drop_pkt = value;
	ret = hppe_mul_p5_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p6_drop_cnt_tbl_mul_p6_drop_byte_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union mul_p6_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p6_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.mul_p6_drop_byte_1 << 32 | \
		reg_val.bf.mul_p6_drop_byte_0;
	return ret;
}

sw_error_t
hppe_mul_p6_drop_cnt_tbl_mul_p6_drop_byte_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union mul_p6_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p6_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p6_drop_byte_1 = value >> 32;
	reg_val.bf.mul_p6_drop_byte_0 = value & (((a_uint64_t)1<<32)-1);
	ret = hppe_mul_p6_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p6_drop_cnt_tbl_mul_p6_drop_pkt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union mul_p6_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p6_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.mul_p6_drop_pkt;
	return ret;
}

sw_error_t
hppe_mul_p6_drop_cnt_tbl_mul_p6_drop_pkt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union mul_p6_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p6_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p6_drop_pkt = value;
	ret = hppe_mul_p6_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p7_drop_cnt_tbl_mul_p7_drop_pkt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union mul_p7_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p7_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.mul_p7_drop_pkt;
	return ret;
}

sw_error_t
hppe_mul_p7_drop_cnt_tbl_mul_p7_drop_pkt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union mul_p7_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p7_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p7_drop_pkt = value;
	ret = hppe_mul_p7_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_mul_p7_drop_cnt_tbl_mul_p7_drop_byte_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union mul_p7_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p7_drop_cnt_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.mul_p7_drop_byte_1 << 32 | \
		reg_val.bf.mul_p7_drop_byte_0;
	return ret;
}

sw_error_t
hppe_mul_p7_drop_cnt_tbl_mul_p7_drop_byte_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union mul_p7_drop_cnt_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_mul_p7_drop_cnt_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.mul_p7_drop_byte_1 = value >> 32;
	reg_val.bf.mul_p7_drop_byte_0 = value & (((a_uint64_t)1<<32)-1);
	ret = hppe_mul_p7_drop_cnt_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_queue_tx_counter_tbl_tx_bytes_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union queue_tx_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_queue_tx_counter_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf.tx_bytes_1 << 32 | \
		reg_val.bf.tx_bytes_0;
	return ret;
}

sw_error_t
hppe_queue_tx_counter_tbl_tx_bytes_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union queue_tx_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_queue_tx_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tx_bytes_1 = value >> 32;
	reg_val.bf.tx_bytes_0 = value & (((a_uint64_t)1<<32)-1);
	ret = hppe_queue_tx_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
hppe_queue_tx_counter_tbl_tx_packets_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union queue_tx_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_queue_tx_counter_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.tx_packets;
	return ret;
}

sw_error_t
hppe_queue_tx_counter_tbl_tx_packets_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union queue_tx_counter_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = hppe_queue_tx_counter_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tx_packets = value;
	ret = hppe_queue_tx_counter_tbl_set(dev_id, index, &reg_val);
	return ret;
}
#endif
