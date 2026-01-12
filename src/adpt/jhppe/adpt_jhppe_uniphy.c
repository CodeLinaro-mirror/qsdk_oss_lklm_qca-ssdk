/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

/**
 * @defgroup
 * @{
 */
#include "sw.h"
#include "adpt.h"
#include "ssdk_clk.h"
#include "hppe_init.h"
#include "hppe_uniphy_reg.h"
#include "hppe_uniphy.h"
#include "jhppe_uniphy_reg.h"
#include "jhppe_uniphy.h"
#include "adpt_hppe_uniphy.h"

#define ADPT_JHPPE_UNIPHY_POLLING_TIMEOUT	2000
#define ADPT_JHPPE_UNIPHY_POLLING_DELAY		1

static sw_error_t
adpt_jhppe_uniphy_25g_pcs_set(a_uint32_t dev_id, a_uint32_t uniphy_index)
{
	sw_error_t ret = SW_OK;
	bool rs_fec_en = false, base_r_fec_en = false;
	a_uint32_t vr_rst;
	a_uint32_t timeout = ADPT_JHPPE_UNIPHY_POLLING_TIMEOUT;

	/* Step 1: Write 4'b0101 to bits[5:2] (SS_5_2 field) of the SR_PCS_CTRL1 register */
	ret = jhppe_uniphy_sr_pcs_ctrl1_ss_5_2_set(dev_id, uniphy_index, 0x5);
	SW_RTN_ON_ERROR(ret);

	/* Step 2: Write 4'b0111 to bits[3:0] (PCS_TYPE_SEL field) of the SR_PCS_CTRL2 register
	 * to select 25GBASE-R PCS.
	 */
	ret = jhppe_uniphy_sr_pcs_ctrl2_pcs_type_sel_set(dev_id, uniphy_index, 0x7);
	SW_RTN_ON_ERROR(ret);

	/* Step 3: Program bits[6:0] (PMA_TYPE field) of the SR_PMA_CTRL2 register
	 * to 7'b0111001 (25GBASE-KR).
	 */
	ret = jhppe_uniphy_sr_pma_ctrl2_pma_type_set(dev_id, uniphy_index, 0x39);
	SW_RTN_ON_ERROR(ret);

	/* Step 4: Program bit[1] (EN_50G field) in the VR_PCS_DIG_CTRL3 register
	 * to 0 (to disable 50G).
	 */
	ret = jhppe_uniphy_vr_pcs_dig_ctrl3_en_50g_set(dev_id, uniphy_index, 0);
	SW_RTN_ON_ERROR(ret);

	/* Step 5: Program bit[0] (CNS_EN field) in the VR_PCS_DIG_CTRL3 register to 0 or 1 */
	ret = jhppe_uniphy_vr_pcs_dig_ctrl3_cns_en_set(dev_id, uniphy_index, 0);
	SW_RTN_ON_ERROR(ret);

	/* Step 6: To enable RS-FEC, perform the following */
	if (rs_fec_en == true) {
		/* Step 6a: Program the AM interval period in field [13:0] of the VR_PCS_AM_CNT
		 * register to 14'h400 (16'd1024).
		 */
		ret = jhppe_uniphy_vr_pcs_am_cnt_pcs_am_cnt_set(dev_id, uniphy_index, 0x400);
		SW_RTN_ON_ERROR(ret);

		/* Step 6b: Program the VR_PMA_CWM00 register to 16'h68C1 */
		ret = jhppe_uniphy_vr_pma_cwm00_cwm15_0_set(dev_id, uniphy_index, 0x68C1);
		SW_RTN_ON_ERROR(ret);

		/* Step 6c: Program the VR_PMA_CWM01 register to 16'h3321 */
		ret = jhppe_uniphy_vr_pma_cwm01_cwm31_16_set(dev_id, uniphy_index, 0x3321);
		SW_RTN_ON_ERROR(ret);

		/* Step 6d: Program the VR_PMA_CWM02 register to 16'h973E */
		ret = jhppe_uniphy_vr_pma_cwm02_cwm47_32_set(dev_id, uniphy_index, 0x973E);
		SW_RTN_ON_ERROR(ret);

		/* Step 6e: Program the VR_PMA_CWM03 register to 16'hCCDE */
		ret = jhppe_uniphy_vr_pma_cwm03_cwm63_48_set(dev_id, uniphy_index, 0xCCDE);
		SW_RTN_ON_ERROR(ret);

		/* Step 6f: Set bit [2] in the SR_PMA_RS_FEC_CTRL register to 1 */
		ret = jhppe_uniphy_sr_pma_rs_fec_ctrl_rsfec_en_set(dev_id, uniphy_index, 1);
		SW_RTN_ON_ERROR(ret);
	}

	/* Step 7: To enable BASE-R FEC, program bit [0] in the SR_PMA_KR_FEC_CTRL register */
	if (base_r_fec_en == true) {
		ret = jhppe_uniphy_sr_pma_kr_fec_ctrl_fec_en_set(dev_id, uniphy_index, 1);
		SW_RTN_ON_ERROR(ret);
	}

	/* Step 8: Program the VR_RST field (bit [15]) of the VR_PCS_DIG_CTRL1 register to 1 */
	ret = jhppe_uniphy_vr_pcs_dig_ctrl1_vr_rst_set(dev_id, uniphy_index, 1);
	SW_RTN_ON_ERROR(ret);

	/* Step 9: Polling until VR_RST field (bit [15]) to be 0 */
	while (timeout > 0) {
		ret = jhppe_uniphy_vr_pcs_dig_ctrl1_vr_rst_get(dev_id, uniphy_index, &vr_rst);
		SW_RTN_ON_ERROR(ret);

		if (vr_rst == 0) {
			/* Reset completed */
			break;
		}

		mdelay(ADPT_JHPPE_UNIPHY_POLLING_DELAY);
		timeout--;
	}

	if (timeout == 0) {
		SSDK_ERROR("JHPPE UNIPHY %d: VR_RST polling timeout\n", uniphy_index);
		return SW_TIMEOUT;
	}

	SSDK_INFO("JHPPE UNIPHY %d: 25G PCS configuration completed successfully\n", uniphy_index);
	return SW_OK;
}

static int adpt_jhppe_uniphy_rxeq_engine_done_read(a_uint32_t dev_id, a_uint32_t uniphy_index)
{
	sw_error_t ret;
	a_uint32_t rxeq_engine_done = 0;

	ret = jhppe_uniphy_qserdes_rx_ext_ro_pmad_rxeq_status_rxeq_engine_done_get(dev_id,
			uniphy_index, &rxeq_engine_done);

	if (ret != SW_OK)
		return -EIO;  /* Return negative error code */

	return rxeq_engine_done;
}

sw_error_t
adpt_jhppe_uniphy_rxeq_status_check(a_uint32_t dev_id, a_uint32_t uniphy_index)
{
	int ret;
	int rxeq_engine_done;

	/* Polling QSERDES_RX_EXT_RO_PMAD_RXEQ_STATUS[1] (RXEQ_ENGINE_DONE) until 1
	 * Using read_poll_timeout with:
	 * - op: adpt_jhppe_uniphy_rxeq_engine_done_read
	 * - val: rxeq_engine_done
	 * - cond: rxeq_engine_done == 1 (RXEQ engine completed)
	 * - sleep_us: 1000 (1ms between polls)
	 * - timeout_us: 2000000 (2 second timeout)
	 * - sleep_before_read: false (don't sleep before first read)
	 * - args: dev_id, uniphy_index
	 */
	ret = read_poll_timeout(adpt_jhppe_uniphy_rxeq_engine_done_read, rxeq_engine_done,
			rxeq_engine_done == 1 || rxeq_engine_done < 0,
			1000, 2000000, false, dev_id, uniphy_index);

	if (ret == -ETIMEDOUT) {
		SSDK_ERROR("JHPPE UNIPHY %d: RXEQ engine done polling timeout\n", uniphy_index);
		return SW_TIMEOUT;
	} else if (rxeq_engine_done < 0) {
		SSDK_ERROR("JHPPE UNIPHY %d: RXEQ engine status read error\n", uniphy_index);
		return SW_FAIL;
	} else if (rxeq_engine_done == 1) {
		SSDK_INFO("JHPPE UNIPHY %d: RXEQ engine completed successfully\n", uniphy_index);
		return SW_OK;
	}

	return SW_FAIL;
}

static void
adpt_jhppe_gcc_uniphy_xlgpcs_reset(a_uint32_t dev_id, a_uint32_t uniphy_index, a_bool_t enable)
{
	enum ssdk_rst_action rst_action;
	enum uniphy_rst_type rst_type;

	switch (uniphy_index) {
	case SSDK_UNIPHY_INSTANCE1:
		rst_type = UNIPHY1_XLGPCS_RESET_E;
		break;
	case SSDK_UNIPHY_INSTANCE2:
		rst_type = UNIPHY2_XLGPCS_RESET_E;
		break;
	case SSDK_UNIPHY_INSTANCE0:
	default:
		SSDK_ERROR("UNIPHY %d not support XLGPCS\n", uniphy_index);
		return;
	}

	rst_action = (enable == A_TRUE) ? SSDK_RESET_ASSERT : SSDK_RESET_DEASSERT;

	ssdk_uniphy_reset(dev_id, rst_type, rst_action);

	return;
}

sw_error_t
adpt_jhppe_uniphy_calibrate(a_uint32_t dev_id, a_uint32_t uniphy_index)
{
	a_uint32_t reg_value = 0;
	a_uint32_t retries = ADPT_JHPPE_UNIPHY_POLLING_TIMEOUT;

	ADPT_DEV_ID_CHECK(dev_id);

	/* JHPPE calibration sequence:
	 * 1. Write 1'b1 to register CSR0 UNIPHY_OPTION_3[4](OFFSET 0x5AC/0X588): uniphy start
	 * 2. Wait for traffic state—read CSR3 R0_POWER_STATE[15:0](OFFSET 0XCDF4) = 0xf
	 */

	/* Step 1: Set UNIPHY_START bit to 1 */
	jhppe_uniphy_pcs_uniphy_option_3_uniphy_start_set(dev_id, uniphy_index, 1);

	/* Step 2: Wait for traffic state to be 0xf */
	while (reg_value != 0xf) {
		mdelay(ADPT_JHPPE_UNIPHY_POLLING_DELAY);
		if (retries-- == 0) {
			SSDK_ERROR("JHPPE uniphy %d calibration time out!\n", uniphy_index);
			return SW_TIMEOUT;
		}
		jhppe_uniphy_qserdes_rx_ext_ro_power_state_power_state_get(dev_id,
				uniphy_index, &reg_value);
	}

	return SW_OK;
}
sw_error_t
adpt_jhppe_uniphy_25g_r_mode_set(a_uint32_t dev_id, a_uint32_t uniphy_index)
{
	union uniphy_mode_ctrl_u uniphy_mode_ctrl;
	sw_error_t rv;

	/* disable instance clock */
	qca_gcc_uniphy_port_clock_set(dev_id, uniphy_index, 1, A_FALSE);

	/* keep xpcs to reset status */
	adpt_jhppe_gcc_uniphy_xlgpcs_reset(dev_id, uniphy_index, A_TRUE);

	/* configure uniphy to usxgmii mode */
	hppe_uniphy_mode_ctrl_get(dev_id, uniphy_index, &uniphy_mode_ctrl);
	uniphy_mode_ctrl.bf.newaddedfromhere_ch0_psgmii_qsgmii =
		UNIPHY_CH0_QSGMII_SGMII_MODE;
	uniphy_mode_ctrl.bf.newaddedfromhere_ch0_qsgmii_sgmii =
		UNIPHY_CH0_SGMII_MODE;
	uniphy_mode_ctrl.bf.newaddedfromhere_sg_mode =
		UNIPHY_SGMII_MODE_DISABLE;
	uniphy_mode_ctrl.bf.newaddedfromhere_sgplus_mode =
		UNIPHY_SGMIIPLUS_MODE_DISABLE;
	uniphy_mode_ctrl.bf.newaddedfromhere_xpcs_mode =
		UNIPHY_XPCS_MODE_DISABLE;
	uniphy_mode_ctrl.bf.newaddedfromhere_usxg_en = false;
	uniphy_mode_ctrl.bf.newaddedfromhere_xlgpcs_en = true;
	hppe_uniphy_mode_ctrl_set(dev_id, uniphy_index, &uniphy_mode_ctrl);

	/* configure uniphy usxgmii gcc software reset */
	__adpt_ppe_gcc_uniphy_software_reset(dev_id, uniphy_index);

	/* Write 1'b1 to register CSR3 RXEQ_CTRL0[7] (0XCB20) */
	jhppe_uniphy_qserdes_rx_ext_rxeq_ctrl0_xpcs_rxeq_en_mask_set(dev_id, uniphy_index, 1);

	/* wait calibration done to uniphy */
	adpt_jhppe_uniphy_calibrate(dev_id, uniphy_index);

	/* enable instance clock */
	qca_gcc_uniphy_port_clock_set(dev_id, uniphy_index, 1, A_TRUE);

	/* release xpcs reset status */
	adpt_jhppe_gcc_uniphy_xlgpcs_reset(dev_id, uniphy_index, A_FALSE);

	/* 25g xlgpcs setting */
	rv = adpt_jhppe_uniphy_25g_pcs_set(dev_id, uniphy_index);
	if (rv != SW_OK)
		SSDK_ERROR("uniphy %d 25g pcs set failed.\n", uniphy_index);

	/* Write 1'b0 to register CSR3 RXEQ_CTRL0[7] (0XCB20) */
	jhppe_uniphy_qserdes_rx_ext_rxeq_ctrl0_xpcs_rxeq_en_mask_set(dev_id, uniphy_index, 0);

	return SW_OK;
}
