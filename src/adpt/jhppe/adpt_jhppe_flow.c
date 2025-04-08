/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

/**
 * @defgroup
 * @{
 */
#include "sw.h"
#include "hsl_reg.h"
#include "fal_flow.h"
#include "adpt.h"

sw_error_t adpt_jhppe_flow_key_get(a_uint32_t dev_id,
				   fal_flow_protocol_type_t key_type,
				   fal_flow_key_t *flow_key)
{
	union l3_flow_key_gen_u key_gen;
	union l3_flow_key_sel_u key_sel;
	sw_error_t rv = SW_OK;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(flow_key);

	if (FAL_FLOW_KEY_GEN0 != key_type && FAL_FLOW_KEY_GEN1 != key_type)
		return SW_OUT_OF_RANGE;

	key_type -= FAL_FLOW_KEY_GEN0;

	aos_mem_zero(&key_gen, sizeof(union l3_flow_key_gen_u));
	aos_mem_zero(&key_sel, sizeof(union l3_flow_key_sel_u));

	rv = jhppe_l3_flow_key_gen_get(dev_id, key_type, &key_gen);
	SW_RTN_ON_ERROR(rv);

	rv = jhppe_l3_flow_key_sel_get(dev_id, key_type, &key_sel);
	SW_RTN_ON_ERROR(rv);

	flow_key->valid = key_gen.bf.valid;
	flow_key->key_bmp = 0;

	if (key_gen.bf.l3_type_vld)
		flow_key->key_bmp |= BIT(FAL_FLOW_KEY_L3_TYPE);

	if (key_gen.bf.l4_type_vld)
		flow_key->key_bmp |= BIT(FAL_FLOW_KEY_L4_TYPE);

	if (key_gen.bf.app_type_vld)
		flow_key->key_bmp |= BIT(FAL_FLOW_KEY_APP_TYPE);

	if (key_sel.bf.sip_inc)
		flow_key->key_bmp |= BIT(FAL_FLOW_KEY_SIP);

	if (key_sel.bf.dip_inc)
		flow_key->key_bmp |= BIT(FAL_FLOW_KEY_DIP);

	if (key_sel.bf.ip_prot_inc)
		flow_key->key_bmp |= BIT(FAL_FLOW_KEY_IP_PROTOCOL);

	if (key_sel.bf.sport_inc)
		flow_key->key_bmp |= BIT(FAL_FLOW_KEY_SPORT);

	if (key_sel.bf.dport_inc)
		flow_key->key_bmp |= BIT(FAL_FLOW_KEY_DPORT);

	if (key_sel.bf.udf0_inc)
		flow_key->key_bmp |= BIT(FAL_FLOW_KEY_UDF0);

	if (key_sel.bf.udf1_inc)
		flow_key->key_bmp |= BIT(FAL_FLOW_KEY_UDF1);

	flow_key->l3_type = key_gen.bf.l3_type;
	flow_key->l4_type = key_gen.bf.l4_type;
	flow_key->app_type = key_gen.bf.app_type;
	flow_key->udf0_idx = key_sel.bf.udf0_id;
	flow_key->udf0_mask = key_sel.bf.udf0_mask;
	flow_key->udf1_idx = key_sel.bf.udf1_id;
	flow_key->udf1_mask = key_sel.bf.udf1_mask;

	return SW_OK;
}

sw_error_t adpt_jhppe_flow_key_set(a_uint32_t dev_id,
				   fal_flow_protocol_type_t key_type,
				   fal_flow_key_t *flow_key)
{
	union l3_flow_key_gen_u key_gen;
	union l3_flow_key_sel_u key_sel;
	sw_error_t rv = SW_OK;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(flow_key);

	if (FAL_FLOW_KEY_GEN0 != key_type && FAL_FLOW_KEY_GEN1 != key_type)
		return SW_OUT_OF_RANGE;

	key_type -= FAL_FLOW_KEY_GEN0;

	aos_mem_zero(&key_gen, sizeof(union l3_flow_key_gen_u));
	aos_mem_zero(&key_sel, sizeof(union l3_flow_key_sel_u));

	rv = jhppe_l3_flow_key_gen_get(dev_id, key_type, &key_gen);
	SW_RTN_ON_ERROR(rv);

	rv = jhppe_l3_flow_key_sel_get(dev_id, key_type, &key_sel);
	SW_RTN_ON_ERROR(rv);

	if (flow_key->key_bmp & BIT(FAL_FLOW_KEY_L3_TYPE))
		key_gen.bf.l3_type_vld = 1;
	else
		key_gen.bf.l3_type_vld = 0;

	if (flow_key->key_bmp & BIT(FAL_FLOW_KEY_L4_TYPE))
		key_gen.bf.l4_type_vld = 1;
	else
		key_gen.bf.l4_type_vld = 0;

	if (flow_key->key_bmp & BIT(FAL_FLOW_KEY_APP_TYPE))
		key_gen.bf.app_type_vld = 1;
	else
		key_gen.bf.app_type_vld = 0;

	if (flow_key->key_bmp & BIT(FAL_FLOW_KEY_SIP))
		key_sel.bf.sip_inc = 1;
	else
		key_sel.bf.sip_inc = 0;

	if (flow_key->key_bmp & BIT(FAL_FLOW_KEY_DIP))
		key_sel.bf.dip_inc = 1;
	else
		key_sel.bf.dip_inc = 0;

	if (flow_key->key_bmp & BIT(FAL_FLOW_KEY_IP_PROTOCOL))
		key_sel.bf.ip_prot_inc = 1;
	else
		key_sel.bf.ip_prot_inc = 0;

	if (flow_key->key_bmp & BIT(FAL_FLOW_KEY_SPORT))
		key_sel.bf.sport_inc = 1;
	else
		key_sel.bf.sport_inc = 0;

	if (flow_key->key_bmp & BIT(FAL_FLOW_KEY_DPORT))
		key_sel.bf.dport_inc = 1;
	else
		key_sel.bf.dport_inc = 0;

	if (flow_key->key_bmp & BIT(FAL_FLOW_KEY_UDF0))
		key_sel.bf.udf0_inc = 1;
	else
		key_sel.bf.udf0_inc = 0;

	if (flow_key->key_bmp & BIT(FAL_FLOW_KEY_UDF1))
		key_sel.bf.udf1_inc = 1;
	else
		key_sel.bf.udf1_inc = 0;

	key_gen.bf.l3_type = flow_key->l3_type;
	key_gen.bf.l4_type = flow_key->l4_type;
	key_gen.bf.app_type = flow_key->app_type;
	key_sel.bf.udf0_id = flow_key->udf0_idx;
	key_sel.bf.udf0_mask = flow_key->udf0_mask;
	key_sel.bf.udf1_id = flow_key->udf1_idx;
	key_sel.bf.udf1_mask = flow_key->udf1_mask;

	rv = jhppe_l3_flow_key_gen_set(dev_id, key_type, &key_gen);
	SW_RTN_ON_ERROR(rv);

	return jhppe_l3_flow_key_sel_set(dev_id, key_type, &key_sel);
}

sw_error_t adpt_jhppe_flow_sampling_id_get(a_uint32_t dev_id,
					   a_uint32_t flow_index,
					   a_uint32_t *sampling_id)
{
	sw_error_t rv = SW_OK;
	union in_flow_tbl_u entry;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(sampling_id);

	if (flow_index >= IN_FLOW_TBL_NUM)
		return SW_OUT_OF_RANGE;

	aos_mem_zero(&entry, sizeof(entry));

	rv = hppe_in_flow_tbl_get(dev_id, flow_index, &entry);
	SW_RTN_ON_ERROR(rv);

	*sampling_id = entry.bf.counter_id;

	return rv;
}

sw_error_t adpt_jhppe_flow_sampling_id_set(a_uint32_t dev_id,
					   a_uint32_t flow_index,
					   a_uint32_t sampling_id)
{
	sw_error_t rv = SW_OK;
	union in_flow_tbl_u entry;

	ADPT_DEV_ID_CHECK(dev_id);

	if (flow_index >= IN_FLOW_TBL_NUM)
		return SW_OUT_OF_RANGE;

	aos_mem_zero(&entry, sizeof(entry));

	rv = hppe_in_flow_tbl_get(dev_id, flow_index, &entry);
	SW_RTN_ON_ERROR(rv);

	entry.bf.counter_id = sampling_id;

	return hppe_in_flow_tbl_set(dev_id, flow_index, &entry);
}

sw_error_t adpt_jhppe_flow_gro_en_get(a_uint32_t dev_id,
				      a_uint32_t flow_index,
				      a_bool_t *enable)
{
	sw_error_t rv = SW_OK;
	union eg_flow_tree_map_tbl_u entry;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(enable);

	if (flow_index >= EG_FLOW_TREE_MAP_TBL_NUM)
		return SW_OUT_OF_RANGE;

	aos_mem_zero(&entry, sizeof(entry));

	rv = hppe_eg_flow_tree_map_tbl_get(dev_id, flow_index, &entry);
	SW_RTN_ON_ERROR(rv);

	*enable = entry.bf.gro;

	return rv;
}

sw_error_t adpt_jhppe_flow_gro_en_set(a_uint32_t dev_id,
				      a_uint32_t flow_index,
				      a_bool_t enable)
{
	sw_error_t rv = SW_OK;
	union eg_flow_tree_map_tbl_u entry;

	ADPT_DEV_ID_CHECK(dev_id);

	if (flow_index >= EG_FLOW_TREE_MAP_TBL_NUM)
		return SW_OUT_OF_RANGE;

	aos_mem_zero(&entry, sizeof(entry));

	rv = hppe_eg_flow_tree_map_tbl_get(dev_id, flow_index, &entry);
	SW_RTN_ON_ERROR(rv);

	entry.bf.gro = enable;

	return hppe_eg_flow_tree_map_tbl_set(dev_id, flow_index, &entry);
}
/**
 * @}
 */
