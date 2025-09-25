/*
* Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
* SPDX-License-Identifier: ISC
*/

#include "sw.h"
#include "hsl_htt_reg.h"
#include "adpt.h"

sw_error_t
adpt_httppe_port_mtu_cfg_set(a_uint32_t dev_id, fal_port_t port_id,
	fal_mtu_cfg_t *mtu_cfg)
{
	a_uint32_t port_type = 0, port_value = 0;
	union l2_vp_port_post_tbl_u l2_vp_port_tbl = {0};

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(mtu_cfg);

	port_type = FAL_PORT_ID_TYPE(port_id);
	port_value = FAL_PORT_ID_VALUE(port_id);

	SW_RTN_ON_ERROR(httppe_l2_vp_port_post_tbl_get(dev_id, port_value, &l2_vp_port_tbl));

	l2_vp_port_tbl.bf.mtu_check_type = mtu_cfg->mtu_type;
	l2_vp_port_tbl.bf.extra_header_len = mtu_cfg->extra_header_len;

	l2_vp_port_tbl.bf.eg_vlan_fmt_valid = A_FALSE;
	l2_vp_port_tbl.bf.eg_ctag_fmt = A_FALSE;
	l2_vp_port_tbl.bf.eg_stag_fmt = A_FALSE;
	if(mtu_cfg->eg_vlan_tag_flag != 0)
	{
		l2_vp_port_tbl.bf.eg_vlan_fmt_valid = A_TRUE;
	}
	if(mtu_cfg->eg_vlan_tag_flag & BIT(0))
	{
		l2_vp_port_tbl.bf.eg_ctag_fmt = A_TRUE;
	}
	if(mtu_cfg->eg_vlan_tag_flag & BIT(1))
	{
		l2_vp_port_tbl.bf.eg_stag_fmt = A_TRUE;
	}
	/*physical_port_mtu_check_en is only for VP port*/
	if(port_type == FAL_PORT_TYPE_VPORT)
	{
		if(!mtu_cfg->mtu_enable)
		{
			l2_vp_port_tbl.bf.physical_port_mtu_check_en = A_TRUE;
		}
		else
		{
			l2_vp_port_tbl.bf.physical_port_mtu_check_en = A_FALSE;
		}
	}
	else
	{
		if(!mtu_cfg->mtu_enable)
		{
			SSDK_ERROR("physical port %d does not support mtu disable\n",
				port_id);
			return SW_NOT_SUPPORTED;
		}
	}
	return httppe_l2_vp_port_post_tbl_set(dev_id, port_value, &l2_vp_port_tbl);
}

sw_error_t
adpt_httppe_port_mtu_cfg_get(a_uint32_t dev_id, fal_port_t port_id,
	fal_mtu_cfg_t *mtu_cfg)
{
	a_uint32_t port_type, port_value;
	union l2_vp_port_post_tbl_u l2_vp_port_tbl = {0};

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(mtu_cfg);

	port_type = FAL_PORT_ID_TYPE(port_id);
	port_value = FAL_PORT_ID_VALUE(port_id);

	SW_RTN_ON_ERROR(httppe_l2_vp_port_post_tbl_get(dev_id, port_value, &l2_vp_port_tbl));

	mtu_cfg->mtu_type = l2_vp_port_tbl.bf.mtu_check_type;
	mtu_cfg->extra_header_len = l2_vp_port_tbl.bf.extra_header_len;
	mtu_cfg->eg_vlan_tag_flag = 0;
	if(l2_vp_port_tbl.bf.eg_vlan_fmt_valid == A_TRUE)
	{
		if(l2_vp_port_tbl.bf.eg_ctag_fmt)
		{
			mtu_cfg->eg_vlan_tag_flag |= BIT(0);
		}
		if(l2_vp_port_tbl.bf.eg_stag_fmt)
		{
			mtu_cfg->eg_vlan_tag_flag |= BIT(1);
		}
	}
	mtu_cfg->mtu_enable = A_TRUE;
	if(port_type == FAL_PORT_TYPE_VPORT)
	{
		if(l2_vp_port_tbl.bf.physical_port_mtu_check_en)
		{
			mtu_cfg->mtu_enable = A_FALSE;
		}
	}

	return SW_OK;
}
