/*
* Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
* Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
* SPDX-License-Identifier: ISC
*/

#include "sw.h"
#include "adpt.h"
#include "hsl_htt_reg.h"

sw_error_t
adpt_httppe_port_qinq_mode_set(a_uint32_t dev_id, fal_port_t port_id, fal_port_qinq_role_t *mode)
{
	sw_error_t rtn = SW_OK;
	a_uint32_t port_value = FAL_PORT_ID_VALUE(port_id);

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(mode);

	if (ADPT_IS_VPORT(port_id)) {
		if (FAL_FLG_TST(mode->mask, FAL_PORT_QINQ_ROLE_INGRESS_EN)) {
			union ipr_vp_parsing_u vp_parsing_reg;
			aos_mem_zero(&vp_parsing_reg, sizeof(vp_parsing_reg));

			rtn = httppe_ipr_vp_parsing_get(dev_id, (port_value - SSDK_MIN_VIRTUAL_PORT_ID), &vp_parsing_reg);
			SW_RTN_ON_ERROR(rtn);

			vp_parsing_reg.bf.port_role = mode->ingress_port_role;
			vp_parsing_reg.bf.src_port_sel =
					mode->ingress_port_sel == FAL_QINQ_SEL_TNL_DECAP_SRC_VP ? 0 : 1;
			vp_parsing_reg.bf.vlan_mode = mode->in_port_ponmode_en;

			rtn = httppe_ipr_vp_parsing_set(dev_id, (port_value - SSDK_MIN_VIRTUAL_PORT_ID), &vp_parsing_reg);
			SW_RTN_ON_ERROR(rtn);
		}

		if (FAL_FLG_TST(mode->mask, FAL_PORT_QINQ_ROLE_EGRESS_EN)) {
			rtn = httppe_eg_vp_tbl_port_vlan_type_set(dev_id, port_value,
					(a_uint32_t)mode->egress_port_role);
			SW_RTN_ON_ERROR(rtn);
		}
	} else
	if (ADPT_IS_PPORT(port_id)) {
		if (FAL_FLG_TST(mode->mask, FAL_PORT_QINQ_ROLE_INGRESS_EN)) {
			union port_parsing_reg_u port_parsing_reg;
			aos_mem_zero(&port_parsing_reg, sizeof(port_parsing_reg));

			rtn = httppe_port_parsing_reg_get(dev_id, port_value, &port_parsing_reg);
			SW_RTN_ON_ERROR(rtn);

			port_parsing_reg.bf.port_role = mode->ingress_port_role;
			port_parsing_reg.bf.src_port_sel =
					mode->ingress_port_sel == FAL_QINQ_SEL_TNL_DECAP_SRC_VP ? 0 : 1;
			port_parsing_reg.bf.vlan_mode = mode->in_port_ponmode_en;

			rtn = httppe_port_parsing_reg_set(dev_id, port_value, &port_parsing_reg);
			SW_RTN_ON_ERROR(rtn);
		}

		if (FAL_FLG_TST(mode->mask, FAL_PORT_QINQ_ROLE_EGRESS_EN)) {
			SW_RTN_ON_ERROR(httppe_port_eg_vlan_port_vlan_type_set(dev_id, port_value,
						(a_uint32_t)mode->egress_port_role));
		}
	}

	return rtn;
}

sw_error_t
adpt_httppe_port_qinq_mode_get(a_uint32_t dev_id, fal_port_t port_id, fal_port_qinq_role_t *mode)
{
	sw_error_t rtn = SW_OK;
	a_uint32_t port_value = FAL_PORT_ID_VALUE(port_id);

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(mode);

	if (ADPT_IS_VPORT(port_id)) {
		union ipr_vp_parsing_u vp_parsing_reg;
		aos_mem_zero(&vp_parsing_reg, sizeof(vp_parsing_reg));

		rtn = httppe_ipr_vp_parsing_get(dev_id, (port_value - SSDK_MIN_VIRTUAL_PORT_ID), &vp_parsing_reg);
		SW_RTN_ON_ERROR(rtn);

		mode->ingress_port_role = (fal_qinq_port_role_t)vp_parsing_reg.bf.port_role;
		mode->ingress_port_sel =
				vp_parsing_reg.bf.src_port_sel ? FAL_QINQ_SEL_ORG_SRC_PORT : FAL_QINQ_SEL_TNL_DECAP_SRC_VP;
		mode->in_port_ponmode_en = vp_parsing_reg.bf.vlan_mode;

		rtn = httppe_eg_vp_tbl_port_vlan_type_get(dev_id, port_value,
				(a_uint32_t *)&mode->egress_port_role);
		SW_RTN_ON_ERROR(rtn);
	} else if (ADPT_IS_PPORT(port_id)) {
		union port_parsing_reg_u port_parsing_reg;
		aos_mem_zero(&port_parsing_reg, sizeof(port_parsing_reg));

		rtn = httppe_port_parsing_reg_get(dev_id, port_value, &port_parsing_reg);
		SW_RTN_ON_ERROR(rtn);

		mode->ingress_port_role = (fal_qinq_port_role_t)port_parsing_reg.bf.port_role;
		mode->ingress_port_sel =
				port_parsing_reg.bf.src_port_sel ? FAL_QINQ_SEL_ORG_SRC_PORT : FAL_QINQ_SEL_TNL_DECAP_SRC_VP;
		mode->in_port_ponmode_en = port_parsing_reg.bf.vlan_mode;

		rtn = httppe_port_eg_vlan_port_vlan_type_get(dev_id, port_value,
					(a_uint32_t *)&mode->egress_port_role);
		SW_RTN_ON_ERROR(rtn);
	}

	return rtn;
}

sw_error_t
adpt_httppe_tpid_set(a_uint32_t dev_id, fal_tpid_t *tpid)
{
	sw_error_t rtn = SW_OK;
	union vlan_tpid_reg_u ppe_tpid;
	union vlan_tpid_reg_ext0_u ppe_tpid0;
	union vlan_tpid_reg_ext1_u ppe_tpid1;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(tpid);

	rtn = httppe_vlan_tpid_reg_get(dev_id, &ppe_tpid);
	SW_RTN_ON_ERROR(rtn);

	if (FAL_FLG_TST(tpid->mask, FAL_TPID_CTAG_EN)) {
		ppe_tpid.bf.ctag_tpid = tpid->ctpid;
	}

	if (FAL_FLG_TST(tpid->mask, FAL_TPID_STAG_EN)) {
		ppe_tpid.bf.stag_tpid = tpid->stpid;
	}

	rtn = httppe_vlan_tpid_reg_ext0_get(dev_id, &ppe_tpid0);
	SW_RTN_ON_ERROR(rtn);

	rtn = httppe_vlan_tpid_reg_ext1_get(dev_id, &ppe_tpid1);
	SW_RTN_ON_ERROR(rtn);

	if (FAL_FLG_TST(tpid->mask, FAL_EXT_TPID_CTAG_EN)) {
		ppe_tpid0.bf.ctag_tpid = tpid->ext_ctpid;
	}

	if (FAL_FLG_TST(tpid->mask, FAL_EXT_TPID_STAG_EN)) {
		ppe_tpid0.bf.stag_tpid = tpid->ext_stpid;
	}

	if (FAL_FLG_TST(tpid->mask, FAL_TPID_CTAG_MAP_EN)) {
		ppe_tpid1.bf.ctag_tpid_map = tpid->ctpid_map;
	}

	if (FAL_FLG_TST(tpid->mask, FAL_TPID_STAG_MAP_EN)) {
		ppe_tpid1.bf.stag_tpid_map = tpid->stpid_map;
	}

	rtn = httppe_vlan_tpid_reg_ext0_set(dev_id, &ppe_tpid0);
	SW_RTN_ON_ERROR(rtn);

	rtn = httppe_vlan_tpid_reg_ext1_set(dev_id, &ppe_tpid1);
	SW_RTN_ON_ERROR(rtn);

	rtn = httppe_vlan_tpid_reg_set(dev_id, &ppe_tpid);

	return rtn;
}

sw_error_t
adpt_httppe_tpid_get(a_uint32_t dev_id, fal_tpid_t *tpid)
{
	sw_error_t rtn = SW_OK;
	union vlan_tpid_reg_u ppe_tpid;
	union vlan_tpid_reg_ext0_u ppe_tpid0;
	union vlan_tpid_reg_ext1_u ppe_tpid1;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(tpid);

	rtn = httppe_vlan_tpid_reg_get(dev_id, &ppe_tpid);
	SW_RTN_ON_ERROR(rtn);

	rtn = httppe_vlan_tpid_reg_ext0_get(dev_id, &ppe_tpid0);
	SW_RTN_ON_ERROR(rtn);

	rtn = httppe_vlan_tpid_reg_ext1_get(dev_id, &ppe_tpid1);
	SW_RTN_ON_ERROR(rtn);

	tpid->ext_ctpid = ppe_tpid0.bf.ctag_tpid;
	tpid->ext_stpid = ppe_tpid0.bf.stag_tpid;
	tpid->ctpid_map = ppe_tpid1.bf.ctag_tpid_map;
	tpid->stpid_map = ppe_tpid1.bf.stag_tpid_map;
	tpid->ctpid = ppe_tpid.bf.ctag_tpid;
	tpid->stpid = ppe_tpid.bf.stag_tpid;

	return rtn;
}

sw_error_t
adpt_httppe_egress_tpid_set(a_uint32_t dev_id, fal_tpid_t *tpid)
{
	sw_error_t rtn = SW_OK;

	ADPT_DEV_ID_CHECK(dev_id);

	if (FAL_FLG_TST(tpid->mask, FAL_TPID_CTAG_EN)) {
		rtn = httppe_eg_vlan_tpid_ctpid_set(dev_id,
				(a_uint32_t)tpid->ctpid);
		SW_RTN_ON_ERROR(rtn);
	}

	if (FAL_FLG_TST(tpid->mask, FAL_TPID_STAG_EN)) {
		rtn = httppe_eg_vlan_tpid_stpid_set(dev_id,
				(a_uint32_t)tpid->stpid);
		SW_RTN_ON_ERROR(rtn);
	}

	if (FAL_FLG_TST(tpid->mask, FAL_EXT_TPID_CTAG_EN)) {
		rtn = httppe_eg_vlan_tpid_ext0_ctpid_set(dev_id,
				(a_uint32_t)tpid->ext_ctpid);
		SW_RTN_ON_ERROR(rtn);
	}

	if (FAL_FLG_TST(tpid->mask, FAL_EXT_TPID_STAG_EN)) {
		rtn = httppe_eg_vlan_tpid_ext0_stpid_set(dev_id,
				(a_uint32_t)tpid->ext_stpid);
		SW_RTN_ON_ERROR(rtn);
	}

	if (FAL_FLG_TST(tpid->mask, FAL_TPID_CTAG_MAP_EN)) {
		rtn = httppe_eg_vlan_tpid_ext1_ctag_tpid_map_set(dev_id,
				(a_uint32_t)tpid->ctpid_map);
		SW_RTN_ON_ERROR(rtn);
	}

	if (FAL_FLG_TST(tpid->mask, FAL_TPID_STAG_MAP_EN)) {
		rtn = httppe_eg_vlan_tpid_ext1_stag_tpid_map_set(dev_id,
				(a_uint32_t)tpid->stpid_map);
		SW_RTN_ON_ERROR(rtn);
	}

	return rtn;
}

sw_error_t
adpt_httppe_egress_tpid_get(a_uint32_t dev_id, fal_tpid_t *tpid)
{
	sw_error_t rtn = SW_OK;
	a_uint32_t tmp = 0;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(tpid);

	rtn = httppe_eg_vlan_tpid_ctpid_get(dev_id, &tmp);
	SW_RTN_ON_ERROR(rtn);
	tpid->ctpid = tmp;

	rtn = httppe_eg_vlan_tpid_stpid_get(dev_id, &tmp);
	SW_RTN_ON_ERROR(rtn);
	tpid->stpid = tmp;

	rtn = httppe_eg_vlan_tpid_ext0_ctpid_get(dev_id, &tmp);
	SW_RTN_ON_ERROR(rtn);
	tpid->ext_ctpid = tmp;

	rtn = httppe_eg_vlan_tpid_ext0_stpid_get(dev_id, &tmp);
	SW_RTN_ON_ERROR(rtn);
	tpid->ext_stpid = tmp;

	rtn = httppe_eg_vlan_tpid_ext1_ctag_tpid_map_get(dev_id, &tmp);
	SW_RTN_ON_ERROR(rtn);
	tpid->ctpid_map = tmp;

	rtn = httppe_eg_vlan_tpid_ext1_stag_tpid_map_get(dev_id, &tmp);
	SW_RTN_ON_ERROR(rtn);
	tpid->stpid_map = tmp;

	return rtn;
}

a_uint32_t
_httppe_get_port_vlan_trans_adv_rule_by_index(a_uint32_t dev_id,
		a_uint32_t index, fal_port_vlan_direction_t direction,
		fal_vlan_trans_adv_rule_t *rule, fal_vlan_trans_adv_action_t * action)
{
	union xlt_rule_tbl_u in_vlan_xlt_rule;
	union xlt_action_tbl_u in_vlan_xlt_action;
	union eg_vlan_xlt_rule_u eg_vlan_xlt_rule;
	union eg_vlan_xlt_action_u eg_vlan_xlt_action;
	a_uint32_t rtn = SW_OK;

	if (direction == FAL_PORT_VLAN_INGRESS) {
		/*rule part*/
		rtn = httppe_xlt_rule_tbl_get(dev_id, index, &in_vlan_xlt_rule);
		SW_RTN_ON_ERROR(rtn);

		if (!in_vlan_xlt_rule.bf.valid) {
			memset(&in_vlan_xlt_rule, 0, sizeof(in_vlan_xlt_rule));
		}

		rule->stpid_idx_en = in_vlan_xlt_rule.bf.stpid_incl;
		rule->stpid_idx = in_vlan_xlt_rule.bf.stpid_index;
		rule->ctpid_idx_en = in_vlan_xlt_rule.bf.ctpid_incl;
		rule->ctpid_idx = in_vlan_xlt_rule.bf.ctpid_index;
		rule->dhcp_type = in_vlan_xlt_rule.bf.dhcp_type;
		rule->mc_type = in_vlan_xlt_rule.bf.mc_type;
		rule->vni_resv = (in_vlan_xlt_rule.bf.vni_resv_0 |
			in_vlan_xlt_rule.bf.vni_resv_1 << SW_FIELD_OFFSET_IN_WORD(XLT_RULE_TBL_VNI_RESV_OFFSET));
		rule->vni_resv_enable = in_vlan_xlt_rule.bf.vni_resv_incl;
		rule->vni_resv_type = in_vlan_xlt_rule.bf.vni_resv_type;
		rule->port_bitmap = FAL_PORT_ID(adpt_port_type_convert(A_FALSE,
					in_vlan_xlt_rule.bf.port_type),
				in_vlan_xlt_rule.bf.port_bitmap);
		rule->s_tagged = in_vlan_xlt_rule.bf.skey_fmt;
		rule->s_vid_enable = in_vlan_xlt_rule.bf.skey_vid_incl;
		rule->s_vid = in_vlan_xlt_rule.bf.skey_vid;
		rule->s_pcp_enable = in_vlan_xlt_rule.bf.skey_pcp_incl;
		rule->s_pcp = in_vlan_xlt_rule.bf.skey_pcp;
		rule->s_dei_enable = in_vlan_xlt_rule.bf.skey_dei_incl;
		rule->s_dei = in_vlan_xlt_rule.bf.skey_dei;
		rule->protocol = (in_vlan_xlt_rule.bf.prot_value_0 |
			in_vlan_xlt_rule.bf.prot_value_1 << SW_FIELD_OFFSET_IN_WORD(XLT_RULE_TBL_PROT_VALUE_OFFSET));
		rule->c_tagged = in_vlan_xlt_rule.bf.ckey_fmt;

		rule->c_vid_enable = in_vlan_xlt_rule.bf.ckey_vid_incl;
		rule->c_vid = in_vlan_xlt_rule.bf.ckey_vid;
		rule->c_pcp_enable = in_vlan_xlt_rule.bf.ckey_pcp_incl;
		rule->c_pcp = in_vlan_xlt_rule.bf.ckey_pcp;
		rule->c_dei_enable = in_vlan_xlt_rule.bf.ckey_dei_incl;
		rule->c_dei = in_vlan_xlt_rule.bf.ckey_dei;

		rule->frmtype_enable = in_vlan_xlt_rule.bf.frm_type_incl;
		rule->frmtype = in_vlan_xlt_rule.bf.frm_type;
		rule->protocol_enable = in_vlan_xlt_rule.bf.prot_incl;

		/*action part*/
		rtn = httppe_xlt_action_tbl_get(dev_id, index, &in_vlan_xlt_action);
		SW_RTN_ON_ERROR(rtn);

		if (!in_vlan_xlt_rule.bf.valid) {
			memset(&in_vlan_xlt_action, 0, sizeof(struct xlt_action_tbl));
		}

		action->swap_svid_cvid = in_vlan_xlt_action.bf.vid_swap_cmd;
		action->svid_xlt_cmd = in_vlan_xlt_action.bf.xlt_svid_cmd;
		action->svid_xlt = in_vlan_xlt_action.bf.xlt_svid;
		action->cvid_xlt_cmd = in_vlan_xlt_action.bf.xlt_cvid_cmd;
		action->cvid_xlt = in_vlan_xlt_action.bf.xlt_cvid;

		action->swap_spcp_cpcp = in_vlan_xlt_action.bf.pcp_swap_cmd;
		action->spcp_xlt_cmd = in_vlan_xlt_action.bf.xlt_spcp_cmd;
		action->spcp_xlt = in_vlan_xlt_action.bf.xlt_spcp;
		action->cpcp_xlt_cmd = in_vlan_xlt_action.bf.xlt_cpcp_cmd;
		action->cpcp_xlt = in_vlan_xlt_action.bf.xlt_cpcp;

		action->swap_sdei_cdei = in_vlan_xlt_action.bf.dei_swap_cmd;
		action->sdei_xlt_cmd = in_vlan_xlt_action.bf.xlt_sdei_cmd;
		action->sdei_xlt = in_vlan_xlt_action.bf.xlt_sdei;
		action->cdei_xlt_cmd = in_vlan_xlt_action.bf.xlt_cdei_cmd;
		action->cdei_xlt = in_vlan_xlt_action.bf.xlt_cdei;
		action->counter_enable = in_vlan_xlt_action.bf.counter_en;
		action->tags_to_rm = in_vlan_xlt_action.bf.tags_to_remove;
		action->stpid_idx_xlt_cmd = in_vlan_xlt_action.bf.stpid_cmd;
		action->stpid_idx_xlt = in_vlan_xlt_action.bf.stpid_index;
		action->ctpid_idx_xlt_cmd = in_vlan_xlt_action.bf.ctpid_cmd;
		action->ctpid_idx_xlt = in_vlan_xlt_action.bf.ctpid_index;
		action->dscp_map_idx = in_vlan_xlt_action.bf.dscp_pbit_mapping_index;
		action->counter_mode = in_vlan_xlt_action.bf.counter_mode;
		action->fwd_cmd = in_vlan_xlt_action.bf.fwd_cmd;
		action->dst_valid = in_vlan_xlt_action.bf.dest_info_valid;
		action->dst_port.dest_info_value = (in_vlan_xlt_action.bf.dest_info_0 |
			(in_vlan_xlt_action.bf.dest_info_1 << SW_FIELD_OFFSET_IN_WORD(XLT_ACTION_TBL_DEST_INFO_OFFSET)));
		action->dst_port.dest_info_type = (in_vlan_xlt_action.bf.dest_info_valid) ? FAL_DEST_INFO_PORT_ID : 0;
		action->svc_code_en = in_vlan_xlt_action.bf.service_code_en;
		action->svc_code = in_vlan_xlt_action.bf.service_code;
		action->counter_id = in_vlan_xlt_action.bf.counter_id;
		action->src_info_enable = in_vlan_xlt_action.bf.src_info_valid;
		action->src_info_type = in_vlan_xlt_action.bf.src_info_type;
		action->src_info = in_vlan_xlt_action.bf.src_info;
		action->vsi_xlt_enable = in_vlan_xlt_action.bf.vsi_cmd;
		action->vsi_xlt = in_vlan_xlt_action.bf.vsi;

		return in_vlan_xlt_rule.bf.valid;
	} else {
		/*rule part*/
		rtn = httppe_eg_vlan_xlt_rule_get(dev_id, index, &eg_vlan_xlt_rule);
		SW_RTN_ON_ERROR(rtn);

		if (!eg_vlan_xlt_rule.bf.valid) {
			memset(&eg_vlan_xlt_rule, 0, sizeof(struct eg_vlan_xlt_rule));
		}

		rule->s_tagged = eg_vlan_xlt_rule.bf.skey_fmt;
		rule->s_vid_enable = eg_vlan_xlt_rule.bf.skey_vid_incl;
		rule->stpid_idx_en = eg_vlan_xlt_rule.bf.stpid_incl;
		rule->stpid_idx = eg_vlan_xlt_rule.bf.stpid_index;
		rule->ctpid_idx_en = eg_vlan_xlt_rule.bf.ctpid_incl;
		rule->ctpid_idx = eg_vlan_xlt_rule.bf.ctpid_index;
		rule->protocol_enable = eg_vlan_xlt_rule.bf.prot_incl;
		rule->protocol = eg_vlan_xlt_rule.bf.prot_value;
		rule->dhcp_type = eg_vlan_xlt_rule.bf.dhcp_type;
		rule->mc_type = eg_vlan_xlt_rule.bf.mc_type;
		rule->s_vid = (eg_vlan_xlt_rule.bf.skey_vid_0 |
			(eg_vlan_xlt_rule.bf.skey_vid_1 << SW_FIELD_OFFSET_IN_WORD(EG_VLAN_XLT_RULE_SKEY_VID_OFFSET)));
		rule->port_bitmap = FAL_PORT_ID(adpt_port_type_convert(A_FALSE,
					eg_vlan_xlt_rule.bf.port_type),
				eg_vlan_xlt_rule.bf.port_bitmap);
		rule->s_pcp_enable = eg_vlan_xlt_rule.bf.skey_pcp_incl;
		rule->s_pcp = eg_vlan_xlt_rule.bf.skey_pcp;
		rule->s_dei_enable = eg_vlan_xlt_rule.bf.skey_dei_incl;
		rule->s_dei = eg_vlan_xlt_rule.bf.skey_dei;

		rule->c_tagged = eg_vlan_xlt_rule.bf.ckey_fmt;
		rule->c_vid_enable = eg_vlan_xlt_rule.bf.ckey_vid_incl;
		rule->c_vid = eg_vlan_xlt_rule.bf.ckey_vid;
		rule->c_pcp_enable = eg_vlan_xlt_rule.bf.ckey_pcp_incl;
		rule->c_pcp = eg_vlan_xlt_rule.bf.ckey_pcp;
		rule->c_dei_enable = eg_vlan_xlt_rule.bf.ckey_dei_incl;
		rule->c_dei = eg_vlan_xlt_rule.bf.ckey_dei;

		rule->vsi_valid = eg_vlan_xlt_rule.bf.vsi_valid;
		rule->vsi_enable = eg_vlan_xlt_rule.bf.vsi_incl;
		rule->vsi = eg_vlan_xlt_rule.bf.vsi;

		/*action part*/
		rtn = httppe_eg_vlan_xlt_action_get(dev_id, index, &eg_vlan_xlt_action);
		SW_RTN_ON_ERROR(rtn);

		if (!eg_vlan_xlt_rule.bf.valid) {
			memset(&eg_vlan_xlt_action, 0, sizeof(struct eg_vlan_xlt_action));
		}

		action->swap_svid_cvid = eg_vlan_xlt_action.bf.vid_swap_cmd;
		action->svid_xlt_cmd = eg_vlan_xlt_action.bf.xlt_svid_cmd;
		action->svid_xlt = eg_vlan_xlt_action.bf.xlt_svid;
		action->cvid_xlt_cmd = eg_vlan_xlt_action.bf.xlt_cvid_cmd;
		action->cvid_xlt = eg_vlan_xlt_action.bf.xlt_cvid;

		action->swap_spcp_cpcp = eg_vlan_xlt_action.bf.pcp_swap_cmd;
		action->spcp_xlt_cmd = eg_vlan_xlt_action.bf.xlt_spcp_cmd;
		action->spcp_xlt = eg_vlan_xlt_action.bf.xlt_spcp;
		action->cpcp_xlt_cmd = eg_vlan_xlt_action.bf.xlt_cpcp_cmd;
		action->cpcp_xlt = eg_vlan_xlt_action.bf.xlt_cpcp;

		action->swap_sdei_cdei = eg_vlan_xlt_action.bf.dei_swap_cmd;
		action->sdei_xlt_cmd = eg_vlan_xlt_action.bf.xlt_sdei_cmd;
		action->sdei_xlt = eg_vlan_xlt_action.bf.xlt_sdei;
		action->cdei_xlt_cmd = eg_vlan_xlt_action.bf.xlt_cdei_cmd;
		action->cdei_xlt = eg_vlan_xlt_action.bf.xlt_cdei;

		action->counter_enable = eg_vlan_xlt_action.bf.counter_en;
		action->counter_id = eg_vlan_xlt_action.bf.counter_id;
		action->tags_to_rm = eg_vlan_xlt_action.bf.tags_to_remove;
		action->stpid_idx_xlt_cmd = eg_vlan_xlt_action.bf.stpid_cmd;
		action->stpid_idx_xlt = eg_vlan_xlt_action.bf.stpid_index;
		action->ctpid_idx_xlt_cmd = eg_vlan_xlt_action.bf.ctpid_cmd;
		action->ctpid_idx_xlt = eg_vlan_xlt_action.bf.ctpid_index;
		action->dscp_map_idx = eg_vlan_xlt_action.bf.dscp_pbit_mapping_index;
		action->fwd_cmd = eg_vlan_xlt_action.bf.fwd_cmd;
		action->vni_resv_enable = eg_vlan_xlt_action.bf.vni_resv_en;
		action->vni_resv = (eg_vlan_xlt_action.bf.vni_resv_0 |
			(eg_vlan_xlt_action.bf.vni_resv_1 << SW_FIELD_OFFSET_IN_WORD(EG_VLAN_XLT_ACTION_VNI_RESV_OFFSET)));

		return eg_vlan_xlt_rule.bf.valid;
	}
}

a_uint32_t
_httppe_check_if_rule_equal(fal_port_vlan_direction_t direction, fal_vlan_trans_adv_rule_t * rule1,
		fal_vlan_trans_adv_rule_t * rule2)
{
	if (!(rule1->s_tagged == rule2->s_tagged &&
		rule1->s_vid_enable == rule2->s_vid_enable && rule1->s_vid == rule2->s_vid &&
		rule1->s_pcp_enable == rule2->s_pcp_enable && rule1->s_pcp == rule2->s_pcp &&
		rule1->s_dei_enable == rule2->s_dei_enable && rule1->s_dei == rule2->s_dei &&
		rule1->c_tagged == rule2->c_tagged &&
		rule1->stpid_idx_en == rule2->stpid_idx_en &&
		rule1->stpid_idx == rule2->stpid_idx &&
		rule1->ctpid_idx_en == rule2->ctpid_idx_en &&
		rule1->ctpid_idx == rule2->ctpid_idx &&
		rule1->dhcp_type == rule2->dhcp_type &&
		rule1->mc_type == rule2->mc_type &&
		FAL_PORT_ID_TYPE(rule1->port_bitmap) == FAL_PORT_ID_TYPE(rule2->port_bitmap) &&
		rule1->c_vid_enable == rule2->c_vid_enable && rule1->c_vid == rule2->c_vid &&
		rule1->c_pcp_enable == rule2->c_pcp_enable && rule1->c_pcp == rule2->c_pcp &&
		rule1->c_dei_enable == rule2->c_dei_enable && rule1->c_dei == rule2->c_dei))
		return 1;

	if (direction == FAL_PORT_VLAN_INGRESS)
	{
		if (!(rule1->frmtype_enable == rule2->frmtype_enable &&
					rule1->frmtype == rule2->frmtype &&
					rule1->vni_resv_enable == rule2->vni_resv_enable &&
					rule1->vni_resv_type == rule2->vni_resv_type &&
					rule1->vni_resv == rule2->vni_resv &&
					rule1->protocol_enable == rule2->protocol_enable &&
					rule1->protocol == rule2->protocol))
			return 1;
	} else {
		if (!(rule1->vsi_valid == rule2->vsi_valid &&
					rule1->vsi_enable == rule2->vsi_enable &&
					rule1->vsi == rule2->vsi &&
					rule1->protocol_enable == rule2->protocol_enable &&
					rule1->protocol == rule2->protocol
					))
			return 1;
	}

	return 0;
}

a_uint32_t
_httppe_check_if_action_equal(fal_port_vlan_direction_t direction, fal_vlan_trans_adv_action_t * action1,
		fal_vlan_trans_adv_action_t * action2)
{
	if (!(action1->swap_svid_cvid == action2->swap_svid_cvid &&
		action1->svid_xlt_cmd == action2->svid_xlt_cmd &&
		action1->svid_xlt == action2->svid_xlt &&
		action1->cvid_xlt_cmd == action2->cvid_xlt_cmd &&
		action1->cvid_xlt == action2->cvid_xlt &&
		action1->swap_sdei_cdei == action2->swap_sdei_cdei &&
		action1->sdei_xlt_cmd == action2->sdei_xlt_cmd &&
		action1->sdei_xlt == action2->sdei_xlt &&
		action1->cdei_xlt_cmd == action2->cdei_xlt_cmd &&
		action1->cdei_xlt == action2->cdei_xlt &&
		action1->swap_spcp_cpcp == action2->swap_spcp_cpcp &&
		action1->spcp_xlt_cmd == action2->spcp_xlt_cmd &&
		action1->spcp_xlt == action2->spcp_xlt &&
		action1->cpcp_xlt_cmd == action2->cpcp_xlt_cmd &&
		action1->cpcp_xlt == action2->cpcp_xlt &&
		action1->tags_to_rm == action2->tags_to_rm &&
		action1->stpid_idx_xlt_cmd == action2->stpid_idx_xlt_cmd &&
		action1->stpid_idx_xlt == action2->stpid_idx_xlt &&
		action1->ctpid_idx_xlt_cmd == action2->ctpid_idx_xlt_cmd &&
		action1->ctpid_idx_xlt == action2->ctpid_idx_xlt &&
		action1->dscp_map_idx == action2->dscp_map_idx &&
		action1->fwd_cmd == action2->fwd_cmd &&
		action1->counter_enable == action2->counter_enable &&
		action1->counter_id == action2->counter_id))
		return 1;

	if (direction == FAL_PORT_VLAN_INGRESS) {
		if (!(action1->vsi_xlt_enable == action2->vsi_xlt_enable &&
					action1->svc_code_en == action2->svc_code_en &&
					action1->svc_code == action2->svc_code &&
					action1->dst_valid == action2->dst_valid &&
					action1->dst_port.dest_info_type == action2->dst_port.dest_info_type &&
					action1->dst_port.dest_info_value == action2->dst_port.dest_info_value &&
					action1->counter_mode == action2->counter_mode &&
					action1->src_info_enable == action2->src_info_enable &&
					action1->src_info_type == action2->src_info_type &&
					action1->src_info == action2->src_info &&
					action1->vsi_xlt == action2->vsi_xlt))
			return 1;
	} else {
		if (!(action1->vni_resv_enable == action2->vni_resv_enable &&
					action1->vni_resv == action2->vni_resv))
			return 1;
	}

	return 0;
}

sw_error_t
_httppe_insert_vlan_trans_adv_rule_action(a_uint32_t dev_id, a_uint32_t index,
		fal_port_vlan_direction_t direction,
		fal_vlan_trans_adv_rule_t * rule, fal_vlan_trans_adv_action_t * action)
{
	sw_error_t rtn = SW_OK;
	union xlt_rule_tbl_u in_vlan_xlt_rule;
	union eg_vlan_xlt_rule_u eg_vlan_xlt_rule;
	union xlt_action_tbl_u in_vlan_xlt_action;
	union eg_vlan_xlt_action_u eg_vlan_xlt_action;

	if (direction == FAL_PORT_VLAN_INGRESS)
	{
		in_vlan_xlt_rule.bf.stpid_incl = rule->stpid_idx_en;
		in_vlan_xlt_rule.bf.stpid_index = rule->stpid_idx;
		in_vlan_xlt_rule.bf.ctpid_incl = rule->ctpid_idx_en;
		in_vlan_xlt_rule.bf.ctpid_index = rule->ctpid_idx;
		in_vlan_xlt_rule.bf.dhcp_type = rule->dhcp_type;
		in_vlan_xlt_rule.bf.mc_type = rule->mc_type;
		in_vlan_xlt_rule.bf.vni_resv_0 = rule->vni_resv;
		in_vlan_xlt_rule.bf.vni_resv_1 = (rule->vni_resv >>
			(SW_FIELD_OFFSET_IN_WORD(XLT_RULE_TBL_VNI_RESV_OFFSET)));

		in_vlan_xlt_rule.bf.port_bitmap = FAL_PORT_ID_VALUE(rule->port_bitmap);
		in_vlan_xlt_rule.bf.port_type = adpt_port_type_convert(A_TRUE,
				FAL_PORT_ID_TYPE(rule->port_bitmap));
		in_vlan_xlt_rule.bf.vni_resv_incl = rule->vni_resv_enable;
		in_vlan_xlt_rule.bf.vni_resv_type = rule->vni_resv_type;
		in_vlan_xlt_rule.bf.valid = A_TRUE;
		in_vlan_xlt_rule.bf.skey_fmt = rule->s_tagged;
		in_vlan_xlt_rule.bf.skey_vid_incl = rule->s_vid_enable;
		in_vlan_xlt_rule.bf.skey_vid = rule->s_vid;
		in_vlan_xlt_rule.bf.skey_pcp_incl = rule->s_pcp_enable;
		in_vlan_xlt_rule.bf.skey_pcp = rule->s_pcp;
		in_vlan_xlt_rule.bf.skey_dei_incl = rule->s_dei_enable;
		in_vlan_xlt_rule.bf.skey_dei = rule->s_dei;
		in_vlan_xlt_rule.bf.ckey_fmt = rule->c_tagged;
		in_vlan_xlt_rule.bf.prot_value_0 = rule->protocol;
		in_vlan_xlt_rule.bf.prot_value_1 = (rule->protocol >>
			(SW_FIELD_OFFSET_IN_WORD(XLT_RULE_TBL_PROT_VALUE_OFFSET)));
		in_vlan_xlt_rule.bf.ckey_vid_incl = rule->c_vid_enable;
		in_vlan_xlt_rule.bf.ckey_vid = rule->c_vid;
		in_vlan_xlt_rule.bf.ckey_pcp_incl = rule->c_pcp_enable;
		in_vlan_xlt_rule.bf.ckey_pcp = rule->c_pcp;
		in_vlan_xlt_rule.bf.ckey_dei_incl = rule->c_dei_enable;
		in_vlan_xlt_rule.bf.ckey_dei = rule->c_dei;

		in_vlan_xlt_rule.bf.prot_incl = rule->protocol_enable;
		in_vlan_xlt_rule.bf.frm_type_incl = rule->frmtype_enable;
		in_vlan_xlt_rule.bf.frm_type = rule->frmtype;

		rtn = httppe_xlt_rule_tbl_set(dev_id, index, &in_vlan_xlt_rule);
		SW_RTN_ON_ERROR(rtn);

		/*action part*/
		in_vlan_xlt_action.bf.vid_swap_cmd = action->swap_svid_cvid;
		in_vlan_xlt_action.bf.xlt_svid_cmd = action->svid_xlt_cmd;
		in_vlan_xlt_action.bf.xlt_svid = action->svid_xlt;
		in_vlan_xlt_action.bf.xlt_cvid_cmd = action->cvid_xlt_cmd;
		in_vlan_xlt_action.bf.xlt_cvid = action->cvid_xlt;

		in_vlan_xlt_action.bf.pcp_swap_cmd = action->swap_spcp_cpcp;
		in_vlan_xlt_action.bf.xlt_spcp_cmd = action->spcp_xlt_cmd;
		in_vlan_xlt_action.bf.xlt_spcp = action->spcp_xlt;
		in_vlan_xlt_action.bf.xlt_cpcp_cmd = action->cpcp_xlt_cmd;
		in_vlan_xlt_action.bf.xlt_cpcp = action->cpcp_xlt;

		in_vlan_xlt_action.bf.dei_swap_cmd = action->swap_sdei_cdei;
		in_vlan_xlt_action.bf.xlt_cdei_cmd = action->cdei_xlt_cmd;
		in_vlan_xlt_action.bf.xlt_cdei = action->cdei_xlt;
		in_vlan_xlt_action.bf.xlt_sdei_cmd = action->sdei_xlt_cmd;
		in_vlan_xlt_action.bf.xlt_sdei = action->sdei_xlt;

		in_vlan_xlt_action.bf.counter_en = action->counter_enable;
		in_vlan_xlt_action.bf.tags_to_remove = action->tags_to_rm;
		in_vlan_xlt_action.bf.stpid_cmd = action->stpid_idx_xlt_cmd;
		in_vlan_xlt_action.bf.stpid_index = action->stpid_idx_xlt;
		in_vlan_xlt_action.bf.ctpid_cmd = action->ctpid_idx_xlt_cmd;
		in_vlan_xlt_action.bf.ctpid_index = action->ctpid_idx_xlt;
		in_vlan_xlt_action.bf.dscp_pbit_mapping_index = action->dscp_map_idx;
		in_vlan_xlt_action.bf.counter_mode = action->counter_mode;
		in_vlan_xlt_action.bf.fwd_cmd = action->fwd_cmd;
		if (action->dst_valid && action->dst_port.dest_info_type != FAL_DEST_INFO_PORT_ID) {
			SSDK_ERROR("dest_info_type: %#x is not supported\n",
				action->dst_port.dest_info_type);
			return SW_NOT_SUPPORTED;
		}
		in_vlan_xlt_action.bf.dest_info_valid = action->dst_valid;
		in_vlan_xlt_action.bf.dest_info_0 = action->dst_port.dest_info_value;
		in_vlan_xlt_action.bf.dest_info_1 = (action->dst_port.dest_info_value >>
			(SW_FIELD_OFFSET_IN_WORD(XLT_ACTION_TBL_DEST_INFO_OFFSET)));
		in_vlan_xlt_action.bf.service_code_en = action->svc_code_en;
		in_vlan_xlt_action.bf.service_code = action->svc_code;
		in_vlan_xlt_action.bf.counter_id = action->counter_id;
		in_vlan_xlt_action.bf.src_info_valid = action->src_info_enable;
		in_vlan_xlt_action.bf.src_info_type = action->src_info_type;
		in_vlan_xlt_action.bf.src_info = action->src_info;
		in_vlan_xlt_action.bf.vsi_cmd = action->vsi_xlt_enable;
		in_vlan_xlt_action.bf.vsi = action->vsi_xlt;

		rtn = httppe_xlt_action_tbl_set(dev_id, index, &in_vlan_xlt_action);
		SW_RTN_ON_ERROR(rtn);
	}
	else
	{
		eg_vlan_xlt_rule.bf.valid = A_TRUE;

		eg_vlan_xlt_rule.bf.skey_fmt = rule->s_tagged;
		eg_vlan_xlt_rule.bf.skey_vid_incl = rule->s_vid_enable;
		eg_vlan_xlt_rule.bf.stpid_incl = rule->stpid_idx_en;
		eg_vlan_xlt_rule.bf.stpid_index = rule->stpid_idx;
		eg_vlan_xlt_rule.bf.ctpid_incl = rule->ctpid_idx_en;
		eg_vlan_xlt_rule.bf.ctpid_index = rule->ctpid_idx;
		eg_vlan_xlt_rule.bf.prot_incl = rule->protocol_enable;
		eg_vlan_xlt_rule.bf.prot_value = rule->protocol;
		eg_vlan_xlt_rule.bf.dhcp_type = rule->dhcp_type;
		eg_vlan_xlt_rule.bf.mc_type = rule->mc_type;
		eg_vlan_xlt_rule.bf.skey_vid_0 = rule->s_vid;
		eg_vlan_xlt_rule.bf.skey_vid_1 = (rule->s_vid >>
			(SW_FIELD_OFFSET_IN_WORD(EG_VLAN_XLT_RULE_SKEY_VID_OFFSET)));
		eg_vlan_xlt_rule.bf.port_bitmap = FAL_PORT_ID_VALUE(rule->port_bitmap);
		eg_vlan_xlt_rule.bf.port_type = adpt_port_type_convert(A_TRUE,
				FAL_PORT_ID_TYPE(rule->port_bitmap));
		eg_vlan_xlt_rule.bf.skey_pcp_incl = rule->s_pcp_enable;
		eg_vlan_xlt_rule.bf.skey_pcp = rule->s_pcp;
		eg_vlan_xlt_rule.bf.skey_dei_incl = rule->s_dei_enable;
		eg_vlan_xlt_rule.bf.skey_dei = rule->s_dei;

		eg_vlan_xlt_rule.bf.ckey_fmt = rule->c_tagged;
		eg_vlan_xlt_rule.bf.ckey_vid_incl = rule->c_vid_enable;
		eg_vlan_xlt_rule.bf.ckey_vid = rule->c_vid;
		eg_vlan_xlt_rule.bf.ckey_pcp_incl = rule->c_pcp_enable;
		eg_vlan_xlt_rule.bf.ckey_pcp = rule->c_pcp;
		eg_vlan_xlt_rule.bf.ckey_dei_incl = rule->c_dei_enable;
		eg_vlan_xlt_rule.bf.ckey_dei = rule->c_dei;

		eg_vlan_xlt_rule.bf.vsi_valid = rule->vsi_valid;
		eg_vlan_xlt_rule.bf.vsi_incl = rule->vsi_enable;
		eg_vlan_xlt_rule.bf.vsi = rule->vsi;

		rtn = httppe_eg_vlan_xlt_rule_set(dev_id, index, &eg_vlan_xlt_rule);
		SW_RTN_ON_ERROR(rtn);

		/*action part*/
		eg_vlan_xlt_action.bf.vid_swap_cmd = action->swap_svid_cvid;
		eg_vlan_xlt_action.bf.xlt_svid_cmd = action->svid_xlt_cmd;
		eg_vlan_xlt_action.bf.xlt_svid = action->svid_xlt;
		eg_vlan_xlt_action.bf.xlt_cvid_cmd = action->cvid_xlt_cmd;
		eg_vlan_xlt_action.bf.xlt_cvid = action->cvid_xlt;

		eg_vlan_xlt_action.bf.pcp_swap_cmd = action->swap_spcp_cpcp;
		eg_vlan_xlt_action.bf.xlt_spcp_cmd = action->spcp_xlt_cmd;
		eg_vlan_xlt_action.bf.xlt_spcp = action->spcp_xlt;
		eg_vlan_xlt_action.bf.xlt_cpcp_cmd = action->cpcp_xlt_cmd;
		eg_vlan_xlt_action.bf.xlt_cpcp = action->cpcp_xlt;

		eg_vlan_xlt_action.bf.dei_swap_cmd = action->swap_sdei_cdei;
		eg_vlan_xlt_action.bf.xlt_sdei_cmd = action->sdei_xlt_cmd;
		eg_vlan_xlt_action.bf.xlt_sdei = action->sdei_xlt;
		eg_vlan_xlt_action.bf.xlt_cdei_cmd = action->cdei_xlt_cmd;
		eg_vlan_xlt_action.bf.xlt_cdei = action->cdei_xlt;

		eg_vlan_xlt_action.bf.counter_en = action->counter_enable;
		eg_vlan_xlt_action.bf.counter_id = action->counter_id;

		eg_vlan_xlt_action.bf.tags_to_remove = action->tags_to_rm;
		eg_vlan_xlt_action.bf.stpid_cmd = action->stpid_idx_xlt_cmd;
		eg_vlan_xlt_action.bf.stpid_index = action->stpid_idx_xlt;
		eg_vlan_xlt_action.bf.ctpid_cmd = action->ctpid_idx_xlt_cmd;
		eg_vlan_xlt_action.bf.ctpid_index = action->ctpid_idx_xlt;
		eg_vlan_xlt_action.bf.dscp_pbit_mapping_index = action->dscp_map_idx;
		if (action->fwd_cmd != FAL_MAC_FRWRD && action->fwd_cmd != FAL_MAC_DROP) {
			SSDK_ERROR("egress xlt cmd: %#x is not supported\n", action->fwd_cmd);
			return SW_NOT_SUPPORTED;
		}
		eg_vlan_xlt_action.bf.fwd_cmd = action->fwd_cmd;

		eg_vlan_xlt_action.bf.vni_resv_0 = action->vni_resv;
		eg_vlan_xlt_action.bf.vni_resv_1 = (action->vni_resv >>
			(SW_FIELD_OFFSET_IN_WORD(EG_VLAN_XLT_ACTION_VNI_RESV_OFFSET)));
		eg_vlan_xlt_action.bf.vni_resv_en = action->vni_resv_enable;

		rtn = httppe_eg_vlan_xlt_action_set(dev_id, index, &eg_vlan_xlt_action);
		SW_RTN_ON_ERROR(rtn);
	}

	return rtn;
}

sw_error_t
_httppe_delete_vlan_trans_adv_rule_action(a_uint32_t dev_id, a_uint32_t index,
		fal_port_vlan_direction_t direction)
{
	sw_error_t rtn = SW_OK;
	union xlt_rule_tbl_u in_vlan_xlt_rule;
	union eg_vlan_xlt_rule_u eg_vlan_xlt_rule;
	union xlt_action_tbl_u in_vlan_xlt_action;
	union eg_vlan_xlt_action_u eg_vlan_xlt_action;

	memset(&in_vlan_xlt_rule, 0, sizeof(in_vlan_xlt_rule));
	memset(&eg_vlan_xlt_rule, 0, sizeof(struct eg_vlan_xlt_rule));
	memset(&in_vlan_xlt_action, 0, sizeof(struct xlt_action_tbl));
	memset(&eg_vlan_xlt_action, 0, sizeof(struct eg_vlan_xlt_action));

	if (direction == FAL_PORT_VLAN_INGRESS) {
		rtn = httppe_xlt_rule_tbl_set(dev_id,
				index, &in_vlan_xlt_rule);
		SW_RTN_ON_ERROR(rtn);
		rtn = httppe_xlt_action_tbl_set(dev_id,
				index, &in_vlan_xlt_action);
		SW_RTN_ON_ERROR(rtn);
	} else {
		rtn = httppe_eg_vlan_xlt_rule_set(dev_id,
				index, &eg_vlan_xlt_rule);
		SW_RTN_ON_ERROR(rtn);
		rtn = httppe_eg_vlan_xlt_action_set(dev_id,
				index, &eg_vlan_xlt_action);
		SW_RTN_ON_ERROR(rtn);
	}

	return rtn;
}

sw_error_t
adpt_httppe_port_vlan_trans_adv_add(a_uint32_t dev_id,
		fal_port_t port_id, fal_port_vlan_direction_t direction,
		fal_vlan_trans_adv_rule_t * rule, fal_vlan_trans_adv_action_t * action)
{
	sw_error_t rtn = SW_OK;
	a_uint32_t entry_idx = FAL_PORTVLAN_TRANS_TBL_NUM(direction);
	a_int32_t idx, rule_valid, entry_found;
	fal_vlan_trans_adv_rule_t temp_rule;
	fal_vlan_trans_adv_action_t temp_action;
	a_bool_t entry_sign, insert_entry_ready;

	ADPT_DEV_ID_CHECK(dev_id);

	if (direction == FAL_PORT_VLAN_ALL)
		return SW_FAIL;

	if (FAL_PORT_ID_TYPE(port_id) == FAL_PORT_TYPE_PPORT) {
		rule->port_bitmap = BIT(port_id);
	} else {
		rule->port_bitmap = port_id;
	}

	entry_sign = A_FALSE;
	insert_entry_ready = A_FALSE;
	for (idx = FAL_PORTVLAN_TRANS_TBL_NUM(direction) - 1; idx >= 0; idx--) {
		aos_mem_zero(&temp_rule, sizeof (fal_vlan_trans_adv_rule_t));
		aos_mem_zero(&temp_action, sizeof (fal_vlan_trans_adv_action_t));
		rule_valid = _httppe_get_port_vlan_trans_adv_rule_by_index(dev_id,
				idx, direction, &temp_rule, &temp_action);

		if (!rule_valid) { /* nonexist rule */
			if (!entry_sign) {
				entry_idx = idx;
				entry_sign = A_TRUE;
			}
			continue;
		}
		/* existing rule */
		if (!_httppe_check_if_rule_equal(direction, &temp_rule, rule)) {
			/* rule equal */
			if (!_httppe_check_if_action_equal(direction, &temp_action, action)) {
				/* action equal */
				entry_found = adpt_port_id_compare(temp_rule.port_bitmap,
						port_id);
				if (entry_found == ADPT_PORT_ID_EQUAL ||
						entry_found == ADPT_PORT_ID_INCLD) {
					return SW_ALREADY_EXIST;
				} else if (entry_found == ADPT_PORT_ID_EXCLD) {
					SW_PBMP_ADD_PORT(temp_rule.port_bitmap, port_id);
					rtn = _httppe_insert_vlan_trans_adv_rule_action(
							dev_id,
							idx, direction,
							&temp_rule,
							&temp_action);
					SW_RTN_ON_ERROR(rtn);
					rule->index = idx;
					return SW_OK;
				} else {
					/* need to insert a new portvlan entry */
					insert_entry_ready = A_TRUE;
				}
			} else { /* action not equal */
				entry_found = adpt_port_id_compare(temp_rule.port_bitmap,
						port_id);
				if (entry_found == ADPT_PORT_ID_EQUAL) {
					/* port equal, need update action */
					rtn = _httppe_insert_vlan_trans_adv_rule_action(dev_id,
							idx, direction,
							&temp_rule,
							action);
					SW_RTN_ON_ERROR(rtn);
					rule->index = idx;
					return SW_OK;
				} else {
					if (entry_found == ADPT_PORT_ID_INCLD) {
						/* port included, need remove port from
						 * existing rule bitmap, insert new rule
						 * and action later */
						SW_PBMP_DEL_PORT(temp_rule.port_bitmap, port_id);
						_httppe_insert_vlan_trans_adv_rule_action(dev_id,
								idx, direction,
								&temp_rule,
								&temp_action);
					}

					/* need to insert a new portvlan entry */
					insert_entry_ready = A_TRUE;
				}
			}
		}

		if (insert_entry_ready == A_TRUE && entry_sign == A_TRUE) {
			break;
		}
	}

	if (entry_idx == FAL_PORTVLAN_TRANS_TBL_NUM(direction)) {
		return SW_NO_RESOURCE;
	} else {
		/* insert new rule and action */
		rtn = _httppe_insert_vlan_trans_adv_rule_action(dev_id, entry_idx,
				direction, rule, action);
		SW_RTN_ON_ERROR(rtn);
		rule->index = entry_idx;
	}

	return rtn;
}

sw_error_t
adpt_httppe_port_vlan_trans_adv_del(a_uint32_t dev_id,
		fal_port_t port_id, fal_port_vlan_direction_t direction,
		fal_vlan_trans_adv_rule_t * rule, fal_vlan_trans_adv_action_t * action)
{
	sw_error_t rtn = SW_OK;
	a_uint32_t idx, rule_valid, entry_found;
	fal_vlan_trans_adv_rule_t temp_rule;
	fal_vlan_trans_adv_action_t temp_action;

	ADPT_DEV_ID_CHECK(dev_id);

	if (direction == FAL_PORT_VLAN_ALL)
		return SW_FAIL;

	if (FAL_PORT_ID_TYPE(port_id) == FAL_PORT_TYPE_PPORT) {
		rule->port_bitmap = BIT(port_id);
	} else {
		rule->port_bitmap = port_id;
	}

	for (idx = 0; idx < FAL_PORTVLAN_TRANS_TBL_NUM(direction); idx++) {
		aos_mem_zero(&temp_rule, sizeof (fal_vlan_trans_adv_rule_t));
		aos_mem_zero(&temp_action, sizeof (fal_vlan_trans_adv_action_t));
		rule_valid = _httppe_get_port_vlan_trans_adv_rule_by_index(dev_id,
				idx, direction, &temp_rule, &temp_action);

		if (!rule_valid) {
			continue;
		}

		/* existing valid rule */
		if (!_httppe_check_if_rule_equal(direction, &temp_rule, rule))
		{ /* rule equal */
			if (!_httppe_check_if_action_equal(direction, &temp_action, action))
			{ /* action equal */
				entry_found = adpt_port_id_compare(temp_rule.port_bitmap,
						port_id);

				if (entry_found == ADPT_PORT_ID_EQUAL) {
					/* port equal, need delete existing rule and action */
					rtn = _httppe_delete_vlan_trans_adv_rule_action(dev_id, idx, direction);
					SW_RTN_ON_ERROR(rtn);
					rule->index = idx;
				} else if (entry_found == ADPT_PORT_ID_INCLD) {
					/* current port_bitmap includes this port_id,
					   remove port from port_bitmap and update rule
					   and action */
					SW_PBMP_DEL_PORT(temp_rule.port_bitmap, port_id);
					rtn = _httppe_insert_vlan_trans_adv_rule_action(dev_id,
							idx, direction, &temp_rule,
							&temp_action);
				}
				else {
					/* VP or VP group NOT EQUAL */
					continue;
				}

				break;
			}
		}
	}

	if (idx == FAL_PORTVLAN_TRANS_TBL_NUM(direction))
		return SW_NOT_FOUND;

	return rtn;
}

sw_error_t
adpt_httppe_port_vlan_trans_adv_get(a_uint32_t dev_id,
		fal_port_vlan_direction_t direction, a_uint32_t index,
		fal_vlan_trans_adv_rule_t *rule, fal_vlan_trans_adv_action_t *action)
{
	ADPT_DEV_ID_CHECK(dev_id);

	if (index >= FAL_PORTVLAN_TRANS_TBL_NUM(direction))
		return SW_BAD_VALUE;

	if (1 == _httppe_get_port_vlan_trans_adv_rule_by_index(dev_id,
		index, direction,rule, action)) {
		rule->index = index;
		return SW_OK;
	} else
		return SW_NOT_FOUND;
}

sw_error_t
adpt_httppe_port_vlan_trans_adv_set(a_uint32_t dev_id,
		fal_port_vlan_direction_t direction, a_uint32_t index,
		fal_vlan_trans_adv_rule_t *rule, fal_vlan_trans_adv_action_t *action)
{
	fal_vlan_trans_adv_rule_t tmp_rule = {.port_bitmap = 0};
	fal_vlan_trans_adv_action_t tmp_action = {.svid_xlt = 0};

	ADPT_DEV_ID_CHECK(dev_id);

	if (index >= FAL_PORTVLAN_TRANS_TBL_NUM(direction))
		return SW_BAD_VALUE;

	memset(&tmp_rule, 0, sizeof(tmp_rule));
	memset(&tmp_action, 0, sizeof(tmp_action));

	if (!memcmp(&tmp_rule, rule, sizeof(*rule)) &&
		!memcmp(&tmp_action, action, sizeof(*action)))
		return _httppe_delete_vlan_trans_adv_rule_action(dev_id, index, direction);

	return _httppe_insert_vlan_trans_adv_rule_action(dev_id, index, direction, rule, action);;
}

sw_error_t
adpt_httppe_port_vlan_trans_adv_getfirst(a_uint32_t dev_id,
		fal_port_t port_id, fal_port_vlan_direction_t direction,
		fal_vlan_trans_adv_rule_t * rule, fal_vlan_trans_adv_action_t * action)
{
	sw_error_t rtn = SW_OK;
	a_uint32_t idx, rule_valid, entry_found;
	fal_vlan_trans_adv_rule_t temp_rule;
	fal_vlan_trans_adv_action_t temp_action;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(rule);
	ADPT_NULL_POINT_CHECK(action);

	if (direction == FAL_PORT_VLAN_ALL)
		return SW_FAIL;

	entry_found = A_FALSE;
	for (idx = 0; idx < FAL_PORTVLAN_TRANS_TBL_NUM(direction); idx++) {
		aos_mem_zero(&temp_rule, sizeof (fal_vlan_trans_adv_rule_t));
		aos_mem_zero(&temp_action, sizeof (fal_vlan_trans_adv_action_t));
		rule_valid = _httppe_get_port_vlan_trans_adv_rule_by_index(dev_id,
				idx, direction, &temp_rule, &temp_action);
		if (rule_valid == 1) {
			entry_found = adpt_port_id_compare(temp_rule.port_bitmap, port_id);

			if (entry_found == ADPT_PORT_ID_EQUAL ||
					entry_found == ADPT_PORT_ID_INCLD) {
				aos_mem_copy(rule, &temp_rule,
						sizeof(fal_vlan_trans_adv_rule_t));
				rule->index = idx;
				aos_mem_copy(action, &temp_action,
						sizeof(fal_vlan_trans_adv_action_t));
				break;
			}
		}
	}

	if (idx == FAL_PORTVLAN_TRANS_TBL_NUM(direction))
		return SW_NOT_FOUND;

	return rtn;
}

sw_error_t
adpt_httppe_port_vlan_trans_adv_getnext(a_uint32_t dev_id,
		fal_port_t port_id, fal_port_vlan_direction_t direction,
		fal_vlan_trans_adv_rule_t * rule, fal_vlan_trans_adv_action_t * action)
{
	sw_error_t rtn = SW_OK;
	a_uint32_t idx, rule_valid, entry_found;
	fal_vlan_trans_adv_rule_t temp_rule;
	fal_vlan_trans_adv_action_t temp_action;
	a_bool_t sign_tag = A_FALSE;

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(rule);
	ADPT_NULL_POINT_CHECK(action);

	if (direction == FAL_PORT_VLAN_ALL)
		return SW_FAIL;

	/* all the entries have been checked */
	if (rule->index == (FAL_PORTVLAN_TRANS_TBL_NUM(direction) - 1))
		return SW_NOT_FOUND;

	if (FAL_PORT_ID_TYPE(port_id) == FAL_PORT_TYPE_PPORT) {
		rule->port_bitmap = BIT(port_id);
	} else {
		rule->port_bitmap = port_id;
	}

	for (idx = 0; idx < FAL_PORTVLAN_TRANS_TBL_NUM(direction); idx++) {
		aos_mem_zero(&temp_rule, sizeof (fal_vlan_trans_adv_rule_t));
		aos_mem_zero(&temp_action, sizeof (fal_vlan_trans_adv_action_t));
		rule_valid = _httppe_get_port_vlan_trans_adv_rule_by_index(dev_id, idx,
				direction, &temp_rule, &temp_action);
		if (rule_valid == 1)
		{ /* existing rule */
			entry_found = adpt_port_id_compare(temp_rule.port_bitmap,
					port_id);
			if (sign_tag == A_TRUE && (entry_found == ADPT_PORT_ID_EQUAL ||
						entry_found == ADPT_PORT_ID_INCLD))
			{
				aos_mem_copy(rule, &temp_rule,
						sizeof (fal_vlan_trans_adv_rule_t));
				rule->index = idx;
				aos_mem_copy(action, &temp_action,
						sizeof (fal_vlan_trans_adv_action_t));
				break;
			}
			if (!_httppe_check_if_rule_equal(direction, &temp_rule, rule))
			{ /* rule equal */
				if (!_httppe_check_if_action_equal(direction, &temp_action, action))
				{ /* action equal */
					if (entry_found == ADPT_PORT_ID_EQUAL ||
							entry_found == ADPT_PORT_ID_INCLD) {
						sign_tag = A_TRUE;
					}
				}
			}
		}
	}

	if (idx == FAL_PORTVLAN_TRANS_TBL_NUM(direction))
		return SW_NOT_FOUND;

	return rtn;
}

