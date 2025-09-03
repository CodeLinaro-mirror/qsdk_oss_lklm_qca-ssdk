/*
* Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
* SPDX-License-Identifier: ISC
*/

#include "sw.h"
#include "hsl_reg.h"
#include "adpt.h"
#include "adpt_appe_portctrl.h"

sw_error_t
adpt_httppe_port_mux_mac_set(a_uint32_t dev_id, fal_port_t port_id)
{
	sw_error_t rv = SW_OK;
	union appe_port_mux_ctrl_u appe_port_mux_ctrl;

	ADPT_DEV_ID_CHECK(dev_id);
	memset(&appe_port_mux_ctrl, 0, sizeof(appe_port_mux_ctrl));

	if (port_id >= SSDK_PHYSICAL_PORT6) {
		return SW_BAD_PARAM;
	}

	rv = appe_port_mux_ctrl_get(dev_id, &appe_port_mux_ctrl);
	SW_RTN_ON_ERROR (rv);

	if (port_id == SSDK_PHYSICAL_PORT0) {
		if (qca_hppe_port_mac_type_get(dev_id, port_id) == PORT_XGMAC_TYPE)
			appe_port_mux_ctrl.bf.port1_mac_sel = 1;
		else
			appe_port_mux_ctrl.bf.port1_mac_sel = 0;
	}
	if (port_id == SSDK_PHYSICAL_PORT5) {
		if (qca_hppe_port_mac_type_get(dev_id, port_id) == PORT_XGMAC_TYPE)
			appe_port_mux_ctrl.bf.port5_mac_sel = 1;
		else
			appe_port_mux_ctrl.bf.port5_mac_sel = 0;
	}

	rv = appe_port_mux_ctrl_set(dev_id, &appe_port_mux_ctrl);
	SW_RTN_ON_ERROR (rv);

	return rv;
}
