/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

/**
 * @defgroup
 * @{
 */
#include "sw.h"
#include "ssdk_init.h"
#include "ssdk_plat.h"
#include "ssdk_clk.h"
#include "hmsppe_uniphy_reg.h"
#include "hmsppe_uniphy.h"
#include "adpt_hppe_uniphy.h"

#define SRC_PON_MODE_EXTERNAL					1
#define SRC_PON_MODE_INTERNAL					0
/* Wait time cnt (clock cycles) */
#define JCCDR_STG1_LOW_WAIT_TIME_CNT				0x964
#define JCCDR_STG2_LOW_WAIT_TIME_CNT				0x12CA
#define JCCDR_STG3_LOW_WAIT_TIME_CNT				0x7085
#define JCCDR_TUNE_CNT1_LOW_WAIT_TIME_CNT			0x10E0
#define JCCDR_TUNE_CNT2_LOW_WAIT_TIME_CNT			0x6EA5
#define PON_CDR_FAST_LOCK_WAIT_TIME_CNT				0xE10A
#define PON_CDR_REGULAR_LOCK_WAIT_TIME_CNT			0xCF02
#define PON_CDR_REGULAR_LOCK_WAIT_TIME_CNT_EXTEND		0x044A

static sw_error_t
adpt_hmsppe_uniphy_pon_clock_enable(a_uint32_t dev_id, a_uint32_t uniphy_index,
	a_uint32_t mode)
{
	union pon_smcbc_ctrl_u smcbc_ctrl;
	sw_error_t rv = SW_OK;

	rv = hmsppe_uniphy_pon_smcbc_ctrl_get(dev_id, uniphy_index, &smcbc_ctrl);
	SW_RTN_ON_ERROR(rv);

	if (mode == PORT_WRAPPER_GPON) {
		/* GPON: write 2'b10 to PON_SMCBC_CTRL[2:1] */
		smcbc_ctrl.bf.mmd1_reg_async_sw_clk_en_gpon_smcbc = A_TRUE;
		smcbc_ctrl.bf.mmd1_reg_async_sw_clk_en_xgpon_smcbc = A_FALSE;
	} else if (mode == PORT_WRAPPER_XGPON || mode == PORT_WRAPPER_XGSPON) {
		/* XGPON/XGSPON: write 2'b01 to PON_SMCBC_CTRL[2:1] */
		smcbc_ctrl.bf.mmd1_reg_async_sw_clk_en_gpon_smcbc = A_FALSE;
		smcbc_ctrl.bf.mmd1_reg_async_sw_clk_en_xgpon_smcbc = A_TRUE;
	} else {
		return SW_BAD_PARAM;
	}

	return hmsppe_uniphy_pon_smcbc_ctrl_set(dev_id, uniphy_index, &smcbc_ctrl);
}

static sw_error_t
adpt_hmsppe_uniphy_jccdr_fast_lock_tune(a_uint32_t dev_id, a_uint32_t uniphy_index,
	a_uint32_t mode)
{
	union jccdr_fst_div_stg1_2_step1_u step1_reg;
	union jccdr_fst_div_stg1_2_step2_u step2_reg;
	union jccdr_fst_div_stg1_2_step3_u step3_reg;
	union jccdr_floop_gain_tune_val_u fgain_reg;
	union jccdr_rgl_fst_div_stg3_u stg3_reg;
	a_uint8_t stg3_step_val;
	sw_error_t rv = SW_OK;

	/* Determine stg3 step value based on mode */
	if (mode == PORT_WRAPPER_XGSPON || mode == PORT_WRAPPER_XGPON) {
		stg3_step_val = 0x3;
	} else if (mode == PORT_WRAPPER_GPON) {
		stg3_step_val = 0x1;
	} else {
		return SW_BAD_PARAM;
	}

	/* JCCDR 3 steps div ratio wait time */
	rv = hmsppe_uniphy_jccdr_stg1_low_mmd1_reg_reg_jccdr_stg1_15_0_set(
		dev_id, uniphy_index, JCCDR_STG1_LOW_WAIT_TIME_CNT);
	SW_RTN_ON_ERROR(rv);
	rv = hmsppe_uniphy_jccdr_stg2_low_mmd1_reg_reg_jccdr_stg2_15_0_set(
		dev_id, uniphy_index, JCCDR_STG2_LOW_WAIT_TIME_CNT);
	SW_RTN_ON_ERROR(rv);
	rv = hmsppe_uniphy_jccdr_stg3_low_mmd1_reg_reg_jccdr_stg3_15_0_set(
		dev_id, uniphy_index, JCCDR_STG3_LOW_WAIT_TIME_CNT);
	SW_RTN_ON_ERROR(rv);

	/* JCCDR 3 steps floop gain wait time */
	rv = hmsppe_uniphy_jccdr_tune_cnt1_low_mmd1_reg_reg_jccdr_tune_cnt1_15_0_set(
		dev_id, uniphy_index, JCCDR_TUNE_CNT1_LOW_WAIT_TIME_CNT);
	SW_RTN_ON_ERROR(rv);
	rv = hmsppe_uniphy_jccdr_tune_cnt2_low_mmd1_reg_reg_jccdr_tune_cnt2_15_0_set(
		dev_id, uniphy_index, JCCDR_TUNE_CNT2_LOW_WAIT_TIME_CNT);
	SW_RTN_ON_ERROR(rv);

	/* JCCDR step stg1/2/3 override */
	rv = hmsppe_uniphy_jccdr_fst_div_stg1_2_step1_get(dev_id, uniphy_index, &step1_reg);
	SW_RTN_ON_ERROR(rv);
	step1_reg.bf.mmd1_reg_reg_fst_cdr_div_stg1_step1 = 0x04;
	step1_reg.bf.mmd1_reg_reg_fst_cdr_div_stg2_step1 = 0x04;
	rv = hmsppe_uniphy_jccdr_fst_div_stg1_2_step1_set(dev_id, uniphy_index, &step1_reg);
	SW_RTN_ON_ERROR(rv);

	rv = hmsppe_uniphy_jccdr_fst_div_stg1_2_step2_get(dev_id, uniphy_index, &step2_reg);
	SW_RTN_ON_ERROR(rv);
	step2_reg.bf.mmd1_reg_reg_fst_cdr_div_stg1_step2 = 0xff;
	step2_reg.bf.mmd1_reg_reg_fst_cdr_div_stg2_step2 = 0x04;
	rv = hmsppe_uniphy_jccdr_fst_div_stg1_2_step2_set(dev_id, uniphy_index, &step2_reg);
	SW_RTN_ON_ERROR(rv);

	rv = hmsppe_uniphy_jccdr_fst_div_stg1_2_step3_get(dev_id, uniphy_index, &step3_reg);
	SW_RTN_ON_ERROR(rv);
	step3_reg.bf.mmd1_reg_reg_fst_cdr_div_stg1_step3 = 0xff;
	step3_reg.bf.mmd1_reg_reg_fst_cdr_div_stg2_step3 = 0xff;
	rv = hmsppe_uniphy_jccdr_fst_div_stg1_2_step3_set(dev_id, uniphy_index, &step3_reg);
	SW_RTN_ON_ERROR(rv);

	rv = hmsppe_uniphy_jccdr_rgl_fst_div_stg3_get(dev_id, uniphy_index, &stg3_reg);
	SW_RTN_ON_ERROR(rv);
	stg3_reg.bf.mmd1_reg_reg_rgl_cdr_div_stg3 = 0x0;
	stg3_reg.bf.mmd1_reg_reg_fst_cdr_div_stg3_step1 = stg3_step_val;
	stg3_reg.bf.mmd1_reg_reg_fst_cdr_div_stg3_step2 = stg3_step_val;
	stg3_reg.bf.mmd1_reg_reg_fst_cdr_div_stg3_step3 = stg3_step_val;
	rv = hmsppe_uniphy_jccdr_rgl_fst_div_stg3_set(dev_id, uniphy_index, &stg3_reg);
	SW_RTN_ON_ERROR(rv);

	/* JCCDR fgain override */
	rv = hmsppe_uniphy_jccdr_floop_gain_tune_val_get(dev_id, uniphy_index, &fgain_reg);
	SW_RTN_ON_ERROR(rv);
	fgain_reg.bf.mmd1_reg_jccdr_floop_gain_tune_en = A_TRUE;
	fgain_reg.bf.mmd1_reg_reg_jccdr_floop_gain_tune0 = 0x04;
	fgain_reg.bf.mmd1_reg_reg_jccdr_floop_gain_tune1 = 0x0A;
	fgain_reg.bf.mmd1_reg_reg_jccdr_floop_gain_tune2 = 0x10;
	rv = hmsppe_uniphy_jccdr_floop_gain_tune_val_set(
		dev_id, uniphy_index, &fgain_reg);
	SW_RTN_ON_ERROR(rv);

	/* sdrx_lock wait */
	rv = hmsppe_uniphy_pon_cdr_lock_wait_cnt_mmd1_reg_reg_pon_cdr_lock_wait_cnt_set(
		dev_id, uniphy_index, PON_CDR_FAST_LOCK_WAIT_TIME_CNT);
	SW_RTN_ON_ERROR(rv);

	return rv;
}

static sw_error_t
adpt_hmsppe_uniphy_jccdr_regular_lock_tune(a_uint32_t dev_id, a_uint32_t uniphy_index,
	a_uint32_t mode)
{
	union jccdr_floop_gain_tune_val_u fgain_reg;
	union jccdr_rgl_div_stg1_2_u rgl_div_reg;
	a_uint8_t rgl_cdr_div_stg3_val;
	sw_error_t rv = SW_OK;

	/* Determine rgl_cdr_div_stg3 value based on mode */
	if (mode == PORT_WRAPPER_XGSPON || mode == PORT_WRAPPER_XGPON) {
		rgl_cdr_div_stg3_val = 0x3;
	} else if (mode == PORT_WRAPPER_GPON) {
		rgl_cdr_div_stg3_val = 0x1;
	} else {
		return SW_BAD_PARAM;
	}

	/* Write 1'b1 to JCCDR_DIG_CTRL1[10] JCCDR_REGULAR_LOCK */
	rv = hmsppe_uniphy_jccdr_dig_ctrl1_mmd1_reg_jccdr_regular_lock_set(
		dev_id, uniphy_index, A_TRUE);
	SW_RTN_ON_ERROR(rv);

	/* Write 16’hffff to (offset 0x6f0)JCCDR_RGL_DIV_STG1_2 */
	rv = hmsppe_uniphy_jccdr_rgl_div_stg1_2_get(dev_id, uniphy_index, &rgl_div_reg);
	SW_RTN_ON_ERROR(rv);
	rgl_div_reg.bf.mmd1_reg_reg_rgl_cdr_div_stg1 = 0xff;
	rgl_div_reg.bf.mmd1_reg_reg_rgl_cdr_div_stg2 = 0xff;
	rv = hmsppe_uniphy_jccdr_rgl_div_stg1_2_set(
		dev_id, uniphy_index, &rgl_div_reg);
	SW_RTN_ON_ERROR(rv);

	/* Write 4’h3 or 4’h1 to (offset 0x700) JCCDR_RGL_FST_DIV_STG3[3:0] */
	rv = hmsppe_uniphy_jccdr_rgl_fst_div_stg3_mmd1_reg_reg_rgl_cdr_div_stg3_set(
		dev_id, uniphy_index, rgl_cdr_div_stg3_val);
	SW_RTN_ON_ERROR(rv);

	/* Write 16'h8421 to (offset 0x6ec)JCCDR_FLOOP_GAIN_TUNE_VAL */
	rv = hmsppe_uniphy_jccdr_floop_gain_tune_val_get(dev_id, uniphy_index, &fgain_reg);
	SW_RTN_ON_ERROR(rv);
	fgain_reg.bf.mmd1_reg_jccdr_floop_gain_tune_en = 1;
	fgain_reg.bf.mmd1_reg_reg_jccdr_floop_gain_tune0 = 0x10;
	fgain_reg.bf.mmd1_reg_reg_jccdr_floop_gain_tune1 = 0x10;
	fgain_reg.bf.mmd1_reg_reg_jccdr_floop_gain_tune2 = 0x10;
	rv = hmsppe_uniphy_jccdr_floop_gain_tune_val_set(
		dev_id, uniphy_index, &fgain_reg);
	SW_RTN_ON_ERROR(rv);

	/* Write 16'hcf02 to (offset 0x610)PON_CDR_LOCK_WAIT_TIME_CNT */
	rv = hmsppe_uniphy_pon_cdr_lock_wait_cnt_mmd1_reg_reg_pon_cdr_lock_wait_cnt_set(
		dev_id, uniphy_index, PON_CDR_REGULAR_LOCK_WAIT_TIME_CNT);
	SW_RTN_ON_ERROR(rv);

	/* Write 16’h044a to (offset 0x6a8)PON_CDR_LOCK_WAIT_CNT_EXTEND */
	rv = hmsppe_uniphy_pon_cdr_lock_wait_cnt_extend_mmd1_reg_reg_pon_cdr_lock_wait_cnt_extend_set(
		dev_id, uniphy_index, PON_CDR_REGULAR_LOCK_WAIT_TIME_CNT_EXTEND);
	SW_RTN_ON_ERROR(rv);

	return rv;
}

sw_error_t
adpt_hmsppe_uniphy_pon_mode_set(a_uint32_t dev_id, a_uint32_t uniphy_index,
	a_uint32_t mode)
{
	a_bool_t jccdr_regular_lock = A_FALSE;
	a_bool_t jccdr_fast_lock = A_TRUE;
	union func_rst_pon_u func_rst;
	a_uint32_t reg_value = 0;
	sw_error_t rv = SW_OK;

	/* UNIPHY sys reset */
	ssdk_uniphy_reset(dev_id, UNIPHY0_SYS_RESET_E + uniphy_index, SSDK_RESET_ASSERT);
	msleep(1);
	ssdk_uniphy_reset(dev_id, UNIPHY0_SYS_RESET_E + uniphy_index, SSDK_RESET_DEASSERT);

	/* Step 1: Write 1'b1 to PON_REG_SOURCE_SEL1[10] SRC_PON_MODE_EXT_INTERNAL */
	rv = hmsppe_uniphy_pon_reg_source_sel1_mmd1_reg_src_pon_mode_ext_internal_set(
		dev_id, uniphy_index, SRC_PON_MODE_EXTERNAL);
	if (rv != SW_OK)
		SSDK_WARN("uniphy %d pon mode %d source select failed.\n", uniphy_index, mode);

	/* Step 2: UNIPHY_INST2 PON interface clock enable */
	rv = adpt_hmsppe_uniphy_pon_clock_enable(dev_id, uniphy_index, mode);
	if (rv != SW_OK)
		SSDK_WARN("uniphy %d pon mode %d interface clock enable failed.\n", uniphy_index, mode);

	/* Step 3: UNIPHY_PON interface data disable - Write 0 to FUNC_RST_PON[5:4] & [1:0] */
	rv = hmsppe_uniphy_func_rst_pon_get(dev_id, uniphy_index, &func_rst);
	if (rv != SW_OK)
		SSDK_WARN("uniphy %d pon mode %d interface data disable failed.\n", uniphy_index, mode);

	func_rst.bf.mmd1_reg_func_rst_pon_tx_n = A_FALSE;
	func_rst.bf.mmd1_reg_func_rst_pon_rx_n = A_FALSE;
	func_rst.bf.mmd1_reg_qsgmii_enable = A_FALSE;
	func_rst.bf.mmd1_reg_xpcs_enable = A_FALSE;
	rv = hmsppe_uniphy_func_rst_pon_set(dev_id, uniphy_index, &func_rst);
	if (rv != SW_OK)
		SSDK_WARN("uniphy %d pon mode %d interface data disable failed.\n", uniphy_index, mode);

	/* Step 4: PON jccdr fast lock tune (if needed) */
	if (jccdr_fast_lock) {
		rv = adpt_hmsppe_uniphy_jccdr_fast_lock_tune(dev_id, uniphy_index, mode);
		if (rv != SW_OK)
			SSDK_WARN("uniphy %d pon mode %d jccdr fast lock tune failed.\n", uniphy_index, mode);
	}

	/* Step 5: PON jccdr regular lock tune (if needed) */
	if (jccdr_regular_lock) {
		rv = adpt_hmsppe_uniphy_jccdr_regular_lock_tune(dev_id, uniphy_index, mode);
		if (rv != SW_OK)
			SSDK_WARN("uniphy %d pon mode %d jccdr regular lock tune failed.\n", uniphy_index, mode);
	}

	/* Step 6: Wait calibration done - read CSR0 OFFSET_CALIB_4[7] (OFFSET 0x1E0) */
	rv = __adpt_hppe_uniphy_calibrate(dev_id, uniphy_index);
	if (rv != SW_OK)
		SSDK_WARN("uniphy %d pon mode %d calibration failed.\n", uniphy_index, mode);

	/* Step 7: Wait sdrx_lock asserted - JCCDR_CALIB_STS_DEBUG[7] SDRX_LOCK */
	rv = read_poll_timeout(hmsppe_uniphy_jccdr_calib_sts_debug_mmd1_reg_sdrx_lock_get,
				rv, (rv == SW_OK && reg_value), 1000, 100000, false,
				dev_id, uniphy_index, &reg_value);
	if (rv) {
		SSDK_ERROR("Timeout waiting for sdrx_lock on uniphy %d mode %d\n",
			   uniphy_index, mode);
	}

	/* Step 8: UNIPHY_PON interface data enable */
	/* Write 2'b11 to FUNC_RST_PON[1:0] FUNC_RST_PON_RX_N, FUNC_RST_PON_TX_N */
	rv = hmsppe_uniphy_func_rst_pon_get(dev_id, uniphy_index, &func_rst);
	if (rv != SW_OK)
		SSDK_WARN("uniphy %d pon mode %d interface data enable failed.\n", uniphy_index, mode);

	func_rst.bf.mmd1_reg_func_rst_pon_rx_n = A_TRUE;
	func_rst.bf.mmd1_reg_func_rst_pon_tx_n = A_TRUE;
	rv = hmsppe_uniphy_func_rst_pon_set(dev_id, uniphy_index, &func_rst);
	if (rv != SW_OK)
		SSDK_WARN("uniphy %d pon mode %d interface data enable failed.\n", uniphy_index, mode);

	return SW_OK;
}

/**
 * @}
 */
