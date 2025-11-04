/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */
#include "hsl_dev.h"
#include "httppe/httppe_qm_reg.h"
#include "httppe/httppe_qm_api.h"
#include "httppe/httppe_portvlan_reg.h"
#include "httppe/httppe_portvlan_api.h"
#include "httppe/httppe_bm_reg.h"
#include "httppe/httppe_bm_api.h"
#include "httppe/httppe_qos_reg.h"
#include "httppe/httppe_qos_api.h"
#include "httppe/httppe_vsi_reg.h"
#include "httppe/httppe_vsi_api.h"
#include "httppe/httppe_l2_vp_reg.h"
#include "httppe/httppe_l2_vp_api.h"
#include "httppe/httppe_xgportctrl_reg.h"
#include "httppe/httppe_xgportctrl_api.h"
#include "httppe/hsl_misc.h"
#include "httppe/httppe_acl_reg.h"
#include "httppe/httppe_acl_api.h"
#include "httppe/httppe_policer_reg.h"
#include "httppe/httppe_policer_api.h"

sw_error_t hppe_reg_get(a_uint32_t dev_id, a_uint32_t reg_addr, a_uint32_t *val);
sw_error_t hppe_reg_set(a_uint32_t dev_id, a_uint32_t reg_addr, a_uint32_t val);
sw_error_t hppe_reg_tbl_get(a_uint32_t dev_id, a_uint32_t reg_addr, a_uint32_t *val, a_uint32_t num);
sw_error_t hppe_reg_tbl_set(a_uint32_t dev_id, a_uint32_t reg_addr, a_uint32_t *val, a_uint32_t num);
