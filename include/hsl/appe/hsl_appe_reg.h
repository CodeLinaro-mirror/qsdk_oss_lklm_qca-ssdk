/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

/*disable MINI for hsl header files*/
#ifdef IN_FDB_MINI
#define IN_FDB_MINI_TEMP
#undef IN_FDB_MINI
#endif

#ifdef IN_MISC_MINI
#define IN_MISC_MINI_TEMP
#undef IN_MISC_MINI
#endif

#ifdef IN_PORTCONTROL_MINI
#define IN_PORTCONTROL_MINI_TEMP
#undef IN_PORTCONTROL_MINI
#endif

#ifdef IN_PORTVLAN_MINI
#define IN_PORTVLAN_MINI_TEMP
#undef IN_PORTVLAN_MINI
#endif

#ifdef IN_QOS_MINI
#define IN_QOS_MINI_TEMP
#undef IN_QOS_MINI
#endif

#ifdef IN_VLAN_MINI
#define IN_VLAN_MINI_TEMP
#undef IN_VLAN_MINI
#endif

#ifdef IN_COSMAP_MINI
#define IN_COSMAP_MINI_TEMP
#undef IN_COSMAP_MINI
#endif

#ifdef IN_IP_MINI
#define IN_IP_MINI_TEMP
#undef IN_IP_MINI
#endif

#ifdef IN_FLOW_MINI
#define IN_FLOW_MINI_TEMP
#undef IN_FLOW_MINI
#endif

#ifdef IN_SEC_MINI
#define IN_SEC_MINI_TEMP
#undef IN_SEC_MINI
#endif

#ifdef IN_QM_MINI
#define IN_QM_MINI_TEMP
#undef IN_QM_MINI
#endif

#ifdef IN_VSI_MINI
#define IN_VSI_MINI_TEMP
#undef IN_VSI_MINI
#endif

#ifdef IN_BM_MINI
#define IN_BM_MINI_TEMP
#undef IN_BM_MINI
#endif

#ifdef IN_SHAPER_MINI
#define IN_SHAPER_MINI_TEMP
#undef IN_SHAPER_MINI
#endif

#ifdef IN_POLICER_MINI
#define IN_POLICER_MINI_TEMP
#undef IN_POLICER_MINI
#endif

#ifdef IN_UNIPHY_MINI
#define IN_UNIPHY_MINI_TEMP
#undef IN_UNIPHY_MINI
#endif

#ifdef IN_TUNNEL_MINI
#define IN_TUNNEL_MINI_TEMP
#undef IN_TUNNEL_MINI
#endif

#ifdef IN_VXLAN_MINI
#define IN_VXLAN_MINI_TEMP
#undef IN_VXLAN_MINI
#endif

#include "appe/appe_acl_reg.h"
#include "appe/appe_counter_reg.h"
#include "appe/appe_geneve_reg.h"
#include "appe/appe_global_reg.h"
#include "appe/appe_l2_vp_reg.h"
#include "appe/appe_policer_reg.h"
#include "appe/appe_portvlan_reg.h"
#include "appe/appe_qm_reg.h"
#include "appe/appe_sec_reg.h"
#include "appe/appe_servcode_reg.h"
#include "appe/appe_shaper_reg.h"
#include "appe/appe_tunnel_map_reg.h"
#include "appe/appe_tunnel_program_reg.h"
#include "appe/appe_tunnel_reg.h"
#include "appe/appe_vsi_reg.h"
#include "appe/appe_vxlan_reg.h"
#include "appe/appe_pppoe_reg.h"

#include "appe/appe_acl.h"
#include "appe/appe_counter.h"
#include "appe/appe_geneve.h"
#include "appe/appe_global.h"
#include "appe/appe_l2_vp.h"
#include "appe/appe_policer.h"
#include "appe/appe_portvlan.h"
#include "appe/appe_qm.h"
#include "appe/appe_sec.h"
#include "appe/appe_servcode.h"
#include "appe/appe_shaper.h"
#include "appe/appe_tunnel_map.h"
#include "appe/appe_tunnel_program.h"
#include "appe/appe_tunnel.h"
#include "appe/appe_vsi.h"
#include "appe/appe_vxlan.h"
#include "appe/appe_pppoe.h"

#include "hppe/hppe_bm_reg.h"
#include "hppe/hppe_ctrlpkt_reg.h"
#include "hppe/hppe_fdb_reg.h"
#include "hppe/hppe_flow_reg.h"
#include "hppe/hppe_ip_reg.h"
#include "hppe/hppe_mib_reg.h"
#include "hppe/hppe_mirror_reg.h"
#include "hppe/hppe_policer_reg.h"
#include "hppe/hppe_portctrl_reg.h"
#include "hppe/hppe_portvlan_reg.h"
#include "hppe/hppe_qm_reg.h"
#include "hppe/hppe_qos_reg.h"
#include "hppe/hppe_rss_reg.h"
#include "hppe/hppe_sec_reg.h"
#include "hppe/hppe_servcode_reg.h"
#include "hppe/hppe_shaper_reg.h"
#include "hppe/hppe_stp_reg.h"
#include "hppe/hppe_trunk_reg.h"
#include "hppe/hppe_vsi_reg.h"
#include "hppe/hppe_xgportctrl_reg.h"
#include "hppe/hppe_acl_reg.h"
#include "hppe/hppe_reg_access.h"

#include "hppe/hppe_bm.h"
#include "hppe/hppe_ctrlpkt.h"
#include "hppe/hppe_fdb.h"
#include "hppe/hppe_flow.h"
#include "hppe/hppe_ip.h"
#include "hppe/hppe_mib.h"
#include "hppe/hppe_mirror.h"
#include "hppe/hppe_policer.h"
#include "hppe/hppe_portctrl.h"
#include "hppe/hppe_portvlan.h"
#include "hppe/hppe_qm.h"
#include "hppe/hppe_qos.h"
#include "hppe/hppe_rss.h"
#include "hppe/hppe_sec.h"
#include "hppe/hppe_servcode.h"
#include "hppe/hppe_shaper.h"
#include "hppe/hppe_stp.h"
#include "hppe/hppe_trunk.h"
#include "hppe/hppe_vsi.h"
#include "hppe/hppe_xgportctrl.h"
#include "hppe/hppe_acl.h"
#include "hppe/hppe_reg_access.h"

#include "cppe/cppe_qos_reg.h"
#include "cppe/cppe_loopback_reg.h"

#include "mppe/mppe_athtag_reg.h"
#include "mppe/mppe_servcode_reg.h"
#include "mrppe/mrppe_pktedit_reg.h"
#include "mrppe/mrppe_pktedit.h"
#include "mppe/mppe_servcode.h"
#include "mppe/mppe_athtag.h"

#ifdef IN_FDB_MINI_TEMP
#define IN_FDB_MINI
#undef IN_FDB_MINI_TEMP
#endif

#ifdef IN_MISC_MINI_TEMP
#define IN_MISC_MINI
#undef IN_MISC_MINI_TEMP
#endif

#ifdef IN_PORTCONTROL_MINI_TEMP
#define IN_PORTCONTROL_MINI
#undef IN_PORTCONTROL_MINI_TEMP
#endif

#ifdef IN_PORTVLAN_MINI_TEMP
#define IN_PORTVLAN_MINI
#undef IN_PORTVLAN_MINI_TEMP
#endif

#ifdef IN_QOS_MINI_TEMP
#define IN_QOS_MINI
#undef IN_QOS_MINI_TEMP
#endif

#ifdef IN_VLAN_MINI_TEMP
#define IN_VLAN_MINI
#undef IN_VLAN_MINI_TEMP
#endif

#ifdef IN_COSMAP_MINI_TEMP
#define IN_COSMAP_MINI
#undef IN_COSMAP_MINI_TEMP
#endif

#ifdef IN_IP_MINI_TEMP
#define IN_IP_MINI
#undef IN_IP_MINI_TEMP
#endif

#ifdef IN_FLOW_MINI_TEMP
#define IN_FLOW_MINI
#undef IN_FLOW_MINI_TEMP
#endif

#ifdef IN_SEC_MINI_TEMP
#define IN_SEC_MINI
#undef IN_SEC_MINI_TEMP
#endif

#ifdef IN_QM_MINI_TEMP
#define IN_QM_MINI
#undef IN_QM_MINI_TEMP
#endif

#ifdef IN_VSI_MINI_TEMP
#define IN_VSI_MINI
#undef IN_VSI_MINI_TEMP
#endif

#ifdef IN_BM_MINI_TEMP
#define IN_BM_MINI
#undef IN_BM_MINI_TEMP
#endif
#ifdef IN_SHAPER_MINI_TEMP
#define IN_SHAPER_MINI
#undef IN_SHAPER_MINI_TEMP
#endif

#ifdef IN_POLICER_MINI_TEMP
#define IN_POLICER_MINI
#undef IN_POLICER_MINI_TEMP
#endif

#ifdef IN_UNIPHY_MINI_TEMP
#define IN_UNIPHY_MINI
#undef IN_UNIPHY_MINI_TEMP
#endif

#ifdef IN_TUNNEL_MINI_TEMP
#define IN_TUNNEL_MINI
#undef IN_TUNNEL_MINI_TEMP
#endif

#ifdef IN_VXLAN_MINI_TEMP
#define IN_VXLAN_MINI
#undef IN_VXLAN_MINI_TEMP
#endif

#define PRX_BASE_ADDR		NSS_PRX_CSR_BASE_ADDR
#define EDMA_BASE_ADDR		EDMA_CSR_BASE_ADDR
#define L2_CPU_CODE_CTRL_MAX_ENTRY		L2_CPU_CODE_CTRL_NUM
#define PORT_DEF_PCP_MAX_ENTRY			PORT_DEF_PCP_NUM
#define PORT_DEF_VID_MAX_ENTRY			PORT_DEF_VID_NUM
#define PORT_VLAN_CONFIG_MAX_ENTRY 		PORT_VLAN_CONFIG_NUM
#define EG_VSI_TAG_MAX_ENTRY        	EG_VSI_TAG_NUM
#define EG_FLOW_IPV6_IID_TBL_MAX_ENTRY  EG_FLOW_IPV6_IID_TBL_NUM

