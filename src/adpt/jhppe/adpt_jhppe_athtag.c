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
#include "fal_athtag.h"
#include "adpt.h"

sw_error_t adpt_jhppe_athtag_rx_src_port_mapping_set(a_uint32_t dev_id,
		fal_port_t ath_src_port, fal_dest_info_t *int_dest_info)
{
	union src_port_mapping_tbl_u reg = {0};
	sw_error_t rv = SW_OK;

	ADPT_NULL_POINT_CHECK(int_dest_info);

	rv = jhppe_src_port_mapping_tbl_get(dev_id, FAL_PORT_ID_VALUE(ath_src_port), &reg);
	SW_RTN_ON_ERROR(rv);

	if (int_dest_info->dest_info_type == FAL_DEST_INFO_INVALID) {
		reg.bf.dst_info_valid = A_FALSE;
		reg.bf.dst_info = 0;
	} else {
		reg.bf.dst_info_valid = A_TRUE;
		reg.bf.dst_info =
		ADPT_DEST_INFO(adpt_dest_type_convert(A_TRUE, int_dest_info->dest_info_type),
				       int_dest_info->dest_info_value);
	}

	return jhppe_src_port_mapping_tbl_set(dev_id, FAL_PORT_ID_VALUE(ath_src_port), &reg);
}

sw_error_t adpt_jhppe_athtag_rx_src_port_mapping_get(a_uint32_t dev_id,
		fal_port_t ath_src_port, fal_dest_info_t *int_dest_info)
{
	union src_port_mapping_tbl_u reg = {0};
	sw_error_t rv = SW_OK;

	ADPT_NULL_POINT_CHECK(int_dest_info);

	rv = jhppe_src_port_mapping_tbl_get(dev_id, FAL_PORT_ID_VALUE(ath_src_port), &reg);
	SW_RTN_ON_ERROR(rv);

	if (reg.bf.dst_info_valid == A_FALSE) {
		int_dest_info->dest_info_type = FAL_DEST_INFO_INVALID;
		int_dest_info->dest_info_value = 0;
	} else {
		int_dest_info->dest_info_type = adpt_dest_type_convert(A_FALSE,
							ADPT_DEST_TYPE(reg.bf.dst_info));
		int_dest_info->dest_info_value = ADPT_DEST_VAL(reg.bf.dst_info);
	}

	return SW_OK;
}

sw_error_t adpt_jhppe_athtag_rx_dest_port_mapping_set(a_uint32_t dev_id,
		fal_port_t ath_dest_port, fal_dest_info_t *int_dest_info)
{
	union dst_port_mapping_tbl_u reg = {0};
	sw_error_t rv = SW_OK;

	ADPT_NULL_POINT_CHECK(int_dest_info);

	rv = jhppe_dst_port_mapping_tbl_get(dev_id, FAL_PORT_ID_VALUE(ath_dest_port), &reg);
	SW_RTN_ON_ERROR(rv);

	if (int_dest_info->dest_info_type == FAL_DEST_INFO_INVALID) {
		reg.bf.dst_info_valid = A_FALSE;
		reg.bf.dst_info = 0;
	} else {
		reg.bf.dst_info_valid = A_TRUE;
		reg.bf.dst_info =
		ADPT_DEST_INFO(adpt_dest_type_convert(A_TRUE, int_dest_info->dest_info_type),
				       int_dest_info->dest_info_value);
	}

	return jhppe_dst_port_mapping_tbl_set(dev_id, FAL_PORT_ID_VALUE(ath_dest_port), &reg);
}

sw_error_t adpt_jhppe_athtag_rx_dest_port_mapping_get(a_uint32_t dev_id,
		fal_port_t ath_dest_port, fal_dest_info_t *int_dest_info)
{
	union dst_port_mapping_tbl_u reg = {0};
	sw_error_t rv = SW_OK;

	ADPT_NULL_POINT_CHECK(int_dest_info);

	rv = jhppe_dst_port_mapping_tbl_get(dev_id, FAL_PORT_ID_VALUE(ath_dest_port), &reg);
	SW_RTN_ON_ERROR(rv);

	if (reg.bf.dst_info_valid == A_FALSE) {
		int_dest_info->dest_info_type = FAL_DEST_INFO_INVALID;
		int_dest_info->dest_info_value = 0;
	} else {
		int_dest_info->dest_info_type = adpt_dest_type_convert(A_FALSE,
							ADPT_DEST_TYPE(reg.bf.dst_info));
		int_dest_info->dest_info_value = ADPT_DEST_VAL(reg.bf.dst_info);
	}

	return SW_OK;
}

sw_error_t adpt_jhppe_athtag_rx_servcode_mapping_set(a_uint32_t dev_id,
		a_uint32_t ath_servcode, a_uint32_t int_servcode)
{
	union service_code_mapping_u reg = {0};
	sw_error_t rv = SW_OK;

	rv = jhppe_service_code_mapping_get(dev_id, ath_servcode, &reg);
	SW_RTN_ON_ERROR(rv);

	if (int_servcode == FAL_SERVCODE_INVALID) {
		reg.bf.service_code_valid = A_FALSE;
		reg.bf.service_code = 0;
	} else {
		reg.bf.service_code_valid = A_TRUE;
		reg.bf.service_code = int_servcode;
	}

	return jhppe_service_code_mapping_set(dev_id, ath_servcode, &reg);
}

sw_error_t adpt_jhppe_athtag_rx_servcode_mapping_get(a_uint32_t dev_id,
		a_uint32_t ath_servcode, a_uint32_t *int_servcode)
{
	union service_code_mapping_u reg = {0};
	sw_error_t rv = SW_OK;

	ADPT_NULL_POINT_CHECK(int_servcode);

	rv = jhppe_service_code_mapping_get(dev_id, ath_servcode, &reg);
	SW_RTN_ON_ERROR(rv);

	if (reg.bf.service_code_valid == A_FALSE)
		*int_servcode = FAL_SERVCODE_INVALID;
	else
		*int_servcode = reg.bf.service_code;

	return SW_OK;
}

sw_error_t adpt_jhppe_athtag_tx_src_port_mapping_set(a_uint32_t dev_id,
		fal_port_t int_src_port, fal_port_t ath_src_port)
{
	union eg_src_port_remap_u reg = {0};
	sw_error_t rv = SW_OK;

	rv = jhppe_eg_src_port_remap_get(dev_id, FAL_PORT_ID_VALUE(int_src_port), &reg);
	SW_RTN_ON_ERROR(rv);

	reg.bf.src_port_num = FAL_PORT_ID_VALUE(ath_src_port);

	return jhppe_eg_src_port_remap_set(dev_id, FAL_PORT_ID_VALUE(int_src_port), &reg);
}

sw_error_t adpt_jhppe_athtag_tx_src_port_mapping_get(a_uint32_t dev_id,
		fal_port_t int_src_port, fal_port_t *ath_src_port)
{
	union eg_src_port_remap_u reg = {0};
	sw_error_t rv = SW_OK;

	ADPT_NULL_POINT_CHECK(ath_src_port);

	rv = jhppe_eg_src_port_remap_get(dev_id, FAL_PORT_ID_VALUE(int_src_port), &reg);
	SW_RTN_ON_ERROR(rv);

	*ath_src_port = reg.bf.src_port_num;

	return SW_OK;
}

/**
 * @}
 */

