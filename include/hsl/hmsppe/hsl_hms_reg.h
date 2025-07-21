/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#include "hmsppe/hppe_acl_reg.h"
#include "hmsppe/hppe_bm_reg.h"
#include "hmsppe/hppe_ctrlpkt_reg.h"
#include "hmsppe/hppe_fdb_reg.h"
#include "hmsppe/hppe_flow_reg.h"
#include "hmsppe/hppe_ip_reg.h"
#include "hmsppe/hppe_mib_reg.h"
#include "hmsppe/hppe_mirror_reg.h"
#include "hmsppe/hppe_policer_reg.h"
#include "hmsppe/hppe_portctrl_reg.h"
#include "hmsppe/hppe_portvlan_reg.h"
#include "hmsppe/hppe_qm_reg.h"
#include "hmsppe/hppe_qos_reg.h"
#include "hmsppe/hppe_rss_reg.h"
#include "hmsppe/hppe_sec_reg.h"
#include "hmsppe/hppe_servcode_reg.h"
#include "hmsppe/hppe_shaper_reg.h"
#include "hmsppe/hppe_stp_reg.h"
#include "hmsppe/hppe_trunk_reg.h"
#include "hmsppe/hppe_vsi_reg.h"
#include "hmsppe/appe_acl_reg.h"
#include "hmsppe/appe_counter_reg.h"
#include "hmsppe/appe_geneve_reg.h"
#include "hmsppe/appe_global_reg.h"
#include "hmsppe/appe_l2_vp_reg.h"
#include "hmsppe/appe_policer_reg.h"
#include "hmsppe/appe_portvlan_reg.h"
#include "hmsppe/appe_pppoe_reg.h"
#include "hmsppe/appe_qm_reg.h"
#include "hmsppe/appe_sec_reg.h"
#include "hmsppe/appe_servcode_reg.h"
#include "hmsppe/appe_shaper_reg.h"
#include "hmsppe/appe_tunnel_map_reg.h"
#include "hmsppe/appe_tunnel_program_reg.h"
#include "hmsppe/appe_tunnel_reg.h"
#include "hmsppe/appe_vsi_reg.h"
#include "hmsppe/appe_vxlan_reg.h"
#include "hmsppe/mppe_athtag_reg.h"
#include "hmsppe/mppe_servcode_reg.h"
#include "hmsppe/mrppe_pktedit_reg.h"
#include "hmsppe/cppe_qos_reg.h"
#include "hmsppe/jhppe_counter_reg.h"
#include "hmsppe/jhppe_ctrlpkt_reg.h"
#include "hmsppe/jhppe_pm_reg.h"
#include "hmsppe/jhppe_ipmc_reg.h"
#include "hmsppe/jhppe_l2_vp_reg.h"
#include "hmsppe/jhppe_l3_flow_reg.h"
#include "hmsppe/jhppe_policer_reg.h"
#include "hmsppe/jhppe_portvlan_reg.h"
#include "hmsppe/jhppe_qm_reg.h"
#include "hmsppe/jhppe_servcode_reg.h"
#include "hmsppe/jhppe_tunnel_program_reg.h"
#include "hmsppe/jhppe_tunnel_reg.h"
#include "hmsppe/jhppe_pktedit_reg.h"
#include "hmsppe/jhppe_acl_reg.h"
#include "hmsppe/jhppe_loopback_reg.h"
#include "hmsppe/hmsppe_prx_pon_reg.h"

#include "hmsppe/hmsppe_prx_pon_api.h"
#include "hmsppe/appe_acl_api.h"
#include "hmsppe/appe_counter_api.h"
#include "hmsppe/appe_geneve_api.h"
#include "hmsppe/appe_global_api.h"
#include "hmsppe/appe_l2_vp_api.h"
#include "hmsppe/appe_policer_api.h"
#include "hmsppe/appe_portvlan_api.h"
#include "hmsppe/appe_pppoe_api.h"
#include "hmsppe/appe_qm_api.h"
#include "hmsppe/appe_sec_api.h"
#include "hmsppe/appe_servcode_api.h"
#include "hmsppe/appe_shaper_api.h"
#include "hmsppe/appe_tunnel_api.h"
#include "hmsppe/appe_tunnel_map_api.h"
#include "hmsppe/appe_tunnel_program_api.h"
#include "hmsppe/appe_vsi_api.h"
#include "hmsppe/appe_vxlan_api.h"
#include "hmsppe/cppe_qos_api.h"
#include "hmsppe/hppe_acl_api.h"
#include "hmsppe/hppe_bm_api.h"
#include "hmsppe/hppe_ctrlpkt_api.h"
#include "hmsppe/hppe_fdb_api.h"
#include "hmsppe/hppe_flow_api.h"
#include "hmsppe/hppe_ip_api.h"
#include "hmsppe/hppe_mib_api.h"
#include "hmsppe/hppe_mirror_api.h"
#include "hmsppe/hppe_policer_api.h"
#include "hmsppe/hppe_portctrl_api.h"
#include "hmsppe/hppe_portvlan_api.h"
#include "hmsppe/hppe_qm_api.h"
#include "hmsppe/hppe_qos_api.h"
#include "hmsppe/hppe_rss_api.h"
#include "hmsppe/hppe_sec_api.h"
#include "hmsppe/hppe_servcode_api.h"
#include "hmsppe/hppe_shaper_api.h"
#include "hmsppe/hppe_stp_api.h"
#include "hmsppe/hppe_trunk_api.h"
#include "hmsppe/hppe_vsi_api.h"
#include "hmsppe/jhppe_acl_api.h"
#include "hmsppe/jhppe_counter_api.h"
#include "hmsppe/jhppe_ctrlpkt_api.h"
#include "hmsppe/jhppe_pm_api.h"
#include "hmsppe/jhppe_ipmc_api.h"
#include "hmsppe/jhppe_l2_vp_api.h"
#include "hmsppe/jhppe_l3_flow_api.h"
#include "hmsppe/jhppe_pktedit_api.h"
#include "hmsppe/jhppe_policer_api.h"
#include "hmsppe/jhppe_portvlan_api.h"
#include "hmsppe/jhppe_qm_api.h"
#include "hmsppe/jhppe_servcode_api.h"
#include "hmsppe/jhppe_tunnel_api.h"
#include "hmsppe/jhppe_tunnel_program_api.h"
#include "hmsppe/jhppe_loopback_api.h"
#include "hmsppe/mppe_athtag_api.h"
#include "hmsppe/mppe_servcode_api.h"
#include "hmsppe/mrppe_pktedit_api.h"

#define NSS_GLOBAL_BASE_ADDR    	 	0x0
#define TPR_UDF_PROFILE_BASE_ADDRESS 		0x480
#define IPR_UDF_PROFILE_BASE_ADDRESS 		0x480
#define NSS_MAC_BASE_ADDR    			0x1000
#define PRX_BASE_ADDR				0xB000
#define INGRESS_VLAN_BASE_ADDR    		0xf000
#define IPO_CSR_BASE_ADDR    			0xb0000
#define PRE_IPO_BASE_ADDR    			0x180000
#define TPR_BASE_ADDR    			0x1d0000
#define IPR_CSR_BASE_ADDR			0x1e0000
#define IPE_L3_BASE_ADDR    			0x200000
#define TT_BASE_ADDR    			0x300000
#define TRAFFIC_MANAGER_BASE_ADDR    		0x400000
#define IPE_L2_BASE_ADDR    			0x540000
#define NSS_PTX_CSR_BASE_ADDR    		0x600000
#define INGRESS_POLICER_BASE_ADDR    		0x700000
#define BM_BASE_ADDR    			0x800000
#define QUEUE_MANAGER_BASE_ADDR    		0xa00000
#define EDMA_BASE_ADDR    			0xd00000

#define TUNNEL_LOOKUP_BASE_ADDR 		TT_BASE_ADDR
#define TUNNEL_PARSER_BASE_ADDR 		TPR_BASE_ADDR
#define PRE_IPO_CSR_BASE_ADDR 			PRE_IPO_BASE_ADDR
#define NSS_MAC_CSR_BASE_ADDR 			NSS_MAC_BASE_ADDR
#define NSS_BM_CSR_BASE_ADDR 			BM_BASE_ADDR
#define NSS_PRX_CSR_BASE_ADDR        		PRX_BASE_ADDR
#define NSS_LPI_BASE_ADDR    		 	NSS_MAC_CSR_BASE_ADDR

sw_error_t hppe_reg_get(a_uint32_t dev_id, a_uint32_t reg_addr, a_uint32_t *val);
sw_error_t hppe_reg_set(a_uint32_t dev_id, a_uint32_t reg_addr, a_uint32_t val);
sw_error_t hppe_reg_tbl_get(a_uint32_t dev_id, a_uint32_t reg_addr, a_uint32_t *val, a_uint32_t num);
sw_error_t hppe_reg_tbl_set(a_uint32_t dev_id, a_uint32_t reg_addr, a_uint32_t *val, a_uint32_t num);

//to be fixed
#include "hmsppe/hsl_misc.h"
