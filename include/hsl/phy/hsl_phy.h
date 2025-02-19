/*
 * Copyright (c) 2015, 2017-2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022-2025 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*qca808x_start*/
#ifndef _HSL_PHY_H_
#define _HSL_PHY_H_

#ifdef __cplusplus
extern "C" {
#endif				/* __cplusplus */

#include "fal.h"
#include <linux/version.h>
#include <linux/phy.h>
#include "qca-nss-phy/nss_phy.h"
#include "hsl_port_prop.h"
#ifdef IN_AQUANTIA_PHY
#include "aquantia_phy.h"
#endif

	/** Phy function reset type */
	typedef enum {
		PHY_FIFO_RESET = 0,	/**< Phy fifo reset */
	} hsl_phy_function_reset_t;

	typedef sw_error_t(*hsl_phy_init) (a_uint32_t dev_id,
					   a_uint32_t phy_id);
	typedef sw_error_t(*hsl_phy_hibernation_set) (a_uint32_t dev_id,
						      a_uint32_t phy_id,
						      a_bool_t enable);
	typedef sw_error_t(*hsl_phy_hibernation_get) (a_uint32_t dev_id,
						      a_uint32_t phy_id,
						      a_bool_t * enable);
	typedef sw_error_t(*hsl_phy_speed_get) (a_uint32_t dev_id,
						a_uint32_t phy_id,
						fal_port_speed_t * speed);
	typedef sw_error_t(*hsl_phy_speed_set) (a_uint32_t dev_id,
						a_uint32_t phy_id,
						fal_port_speed_t speed);
	typedef sw_error_t(*hsl_phy_duplex_get) (a_uint32_t dev_id,
						 a_uint32_t phy_id,
						 fal_port_duplex_t * duplex);
	typedef sw_error_t(*hsl_phy_duplex_set) (a_uint32_t dev_id,
						 a_uint32_t phy_id,
						 fal_port_duplex_t duplex);
	typedef sw_error_t(*hsl_phy_autoneg_enable_set) (a_uint32_t dev_id,
							 a_uint32_t phy_id);
	typedef sw_error_t(*hsl_phy_autoneg_enable_get) (a_uint32_t dev_id,
							 a_uint32_t phy_id,
							 a_bool_t * enable);
	typedef sw_error_t(*hsl_phy_restart_autoneg) (a_uint32_t dev_id,
						      a_uint32_t phy_id);
	typedef a_bool_t(*hsl_phy_autoneg_status_get) (a_uint32_t dev_id,
							 a_uint32_t phy_id);
	typedef sw_error_t(*hsl_phy_powersave_set) (a_uint32_t dev_id,
						    a_uint32_t phy_id,
						    a_bool_t enable);
	typedef sw_error_t(*hsl_phy_powersave_get) (a_uint32_t dev_id,
						    a_uint32_t phy_id,
						    a_bool_t * enable);
	typedef sw_error_t(*hsl_phy_cdt) (a_uint32_t dev_id, a_uint32_t phy_id,
					  a_uint32_t mdi_pair,
					  fal_cable_status_t * cable_status,
					  a_uint32_t * cable_len);
	typedef a_bool_t(*hsl_phy_link_status_get) (a_uint32_t dev_id,
						      a_uint32_t phy_id);
	typedef sw_error_t(*hsl_phy_get_ability) (a_uint32_t dev_id,
						  a_uint32_t phy_id,
						  a_uint32_t * ability);
	typedef sw_error_t(*hsl_phy_mdix_set) (a_uint32_t dev_id,
					       a_uint32_t phy_id,
					       fal_port_mdix_mode_t mode);
	typedef sw_error_t(*hsl_phy_mdix_get) (a_uint32_t dev_id,
					       a_uint32_t phy_id,
					       fal_port_mdix_mode_t * mode);
	typedef sw_error_t(*hsl_phy_mdix_status_get) (a_uint32_t dev_id,
						      a_uint32_t phy_id,
						      fal_port_mdix_status_t *
						      mode);
	typedef sw_error_t(*hsl_phy_8023az_set) (a_uint32_t dev_id,
						 a_uint32_t phy_id,
						 a_bool_t enable);
	typedef sw_error_t(*hsl_phy_8023az_get) (a_uint32_t dev_id,
						 a_uint32_t phy_id,
						 a_bool_t * enable);
	typedef sw_error_t(*hsl_phy_local_loopback_set) (a_uint32_t dev_id,
							 a_uint32_t phy_id,
							 a_bool_t enable);
	typedef sw_error_t(*hsl_phy_local_loopback_get) (a_uint32_t dev_id,
							 a_uint32_t phy_id,
							 a_bool_t * enable);
	typedef sw_error_t(*hsl_phy_remote_loopback_set) (a_uint32_t dev_id,
							  a_uint32_t phy_id,
							  a_bool_t enable);
	typedef sw_error_t(*hsl_phy_remote_loopback_get) (a_uint32_t dev_id,
							  a_uint32_t phy_id,
							  a_bool_t * enable);
	typedef sw_error_t(*hsl_phy_master_set) (a_uint32_t dev_id,
						 a_uint32_t phy_id,
						 fal_port_master_t master);
	typedef sw_error_t(*hsl_phy_master_get) (a_uint32_t dev_id,
						 a_uint32_t phy_id,
						 fal_port_master_t * master);
/*qca808x_end*/
	typedef sw_error_t(*hsl_phy_combo_prefer_medium_set) (a_uint32_t dev_id,
							      a_uint32_t phy_id,
							      fal_port_medium_t
							      phy_medium);
	typedef sw_error_t(*hsl_phy_combo_prefer_medium_get) (a_uint32_t dev_id,
							      a_uint32_t phy_id,
							      fal_port_medium_t
							      * phy_medium);
	typedef sw_error_t(*hsl_phy_combo_medium_status_get) (a_uint32_t dev_id,
							      a_uint32_t phy_id,
							      fal_port_medium_t
							      * phy_medium);
	typedef sw_error_t(*hsl_phy_combo_fiber_mode_set) (a_uint32_t dev_id,
							   a_uint32_t phy_id,
							   fal_port_fiber_mode_t
							   fiber_mode);
	typedef sw_error_t(*hsl_phy_combo_fiber_mode_get) (a_uint32_t dev_id,
							   a_uint32_t phy_id,
							   fal_port_fiber_mode_t
							   * fiber_mode);
/*qca808x_start*/
	typedef sw_error_t (*hsl_phy_function_reset) (a_uint32_t dev_id,
							   a_uint32_t phy_id,
							   hsl_phy_function_reset_t
							   phy_reset_type);
	typedef sw_error_t(*hsl_phy_reset) (a_uint32_t dev_id,
					    a_uint32_t phy_id);
	typedef sw_error_t(*hsl_phy_reset_status_get) (a_uint32_t dev_id,
						       a_uint32_t phy_id,
						       fal_port_reset_status_t *
						       status);
	typedef sw_error_t(*hsl_phy_power_off) (a_uint32_t dev_id,
					    a_uint32_t phy_id);
	typedef sw_error_t(*hsl_phy_power_on) (a_uint32_t dev_id,
					    a_uint32_t phy_id);
	typedef sw_error_t(*hsl_phy_id_get) (a_uint32_t dev_id,
					     a_uint32_t phy_id,
					     a_uint32_t *phy_chip_id);
	typedef sw_error_t(*hsl_phy_autoneg_adv_set) (a_uint32_t dev_id,
						      a_uint32_t phy_id,
						      a_uint32_t autoneg);
	typedef sw_error_t(*hsl_phy_autoneg_adv_get) (a_uint32_t dev_id,
						      a_uint32_t phy_id,
						      a_uint32_t * autoneg);
	typedef sw_error_t(*hsl_phy_reg_write) (a_uint32_t dev_id,
						a_uint32_t phy_addr,
						a_uint32_t reg,
						a_uint16_t reg_val);
	typedef a_uint16_t(*hsl_phy_reg_read) (a_uint32_t dev_id,
					       a_uint32_t phy_addr,
					       a_uint32_t reg);
	typedef sw_error_t(*hsl_phy_debug_write) (a_uint32_t dev_id,
						  a_uint32_t phy_id,
						  a_uint16_t reg_id,
						  a_uint16_t reg_val);
	typedef a_uint16_t(*hsl_phy_debug_read) (a_uint32_t dev_id,
						 a_uint32_t phy_id,
						 a_uint16_t reg_id);
	typedef sw_error_t(*hsl_phy_mmd_write) (a_uint32_t dev_id,
						a_uint32_t phy_id,
						a_uint16_t mmd_num,
						a_uint16_t reg_id,
						a_uint16_t reg_val);
	typedef a_uint16_t(*hsl_phy_mmd_read) (a_uint32_t dev_id,
					       a_uint32_t phy_id,
					       a_uint16_t mmd_num,
					       a_uint16_t reg_id);

	typedef sw_error_t(*hsl_phy_magic_frame_mac_set) (a_uint32_t dev_id,
							  a_uint32_t phy_id,
							  fal_mac_addr_t * mac);

	typedef sw_error_t(*hsl_phy_magic_frame_mac_get) (a_uint32_t dev_id,
							  a_uint32_t phy_id,
							  fal_mac_addr_t * mac);
	typedef sw_error_t(*hsl_phy_wol_status_set) (a_uint32_t dev_id,
							 a_uint32_t phy_id,
							 a_bool_t enable);
	typedef sw_error_t(*hsl_phy_wol_status_get) (a_uint32_t dev_id,
							 a_uint32_t phy_id,
							 a_bool_t * enable);
	typedef sw_error_t(*hsl_phy_interface_mode_set) (a_uint32_t dev_id,
							 a_uint32_t phy_id,
							 fal_port_interface_mode_t
							 interface_mode);
	typedef sw_error_t(*hsl_phy_interface_mode_get) (a_uint32_t dev_id,
							 a_uint32_t phy_id,
							 fal_port_interface_mode_t
							 * interface_mode);
	typedef sw_error_t(*hsl_phy_interface_mode_status_get) (a_uint32_t dev_id,
							 a_uint32_t phy_id,
							 fal_port_interface_mode_t
							 * interface_mode);
	typedef sw_error_t(*hsl_phy_intr_mask_set) (a_uint32_t dev_id,
						      a_uint32_t phy_id,
						      a_uint32_t mask);
	typedef sw_error_t(*hsl_phy_intr_mask_get) (a_uint32_t dev_id,
						      a_uint32_t phy_id,
						      a_uint32_t * mask);
	typedef sw_error_t(*hsl_phy_intr_status_get) (a_uint32_t dev_id,
						      a_uint32_t phy_id,
						      a_uint32_t * status);
	typedef sw_error_t(*hsl_phy_counter_set) (a_uint32_t dev_id,
						      a_uint32_t phy_id,
						      a_bool_t enable);
	typedef sw_error_t(*hsl_phy_counter_get) (a_uint32_t dev_id,
						      a_uint32_t phy_id,
						      a_bool_t * enable);
	typedef sw_error_t(*hsl_phy_counter_show) (a_uint32_t dev_id,
						      a_uint32_t phy_id,
						      fal_port_counter_info_t * counter_info);
	typedef sw_error_t(*hsl_phy_serdes_reset) (a_uint32_t dev_id);

	typedef sw_error_t(*hsl_phy_get_status) (a_uint32_t dev_id,
				a_uint32_t phy_id, struct port_phy_status *phy_status);

	typedef sw_error_t(*hsl_phy_eee_adv_set) (a_uint32_t dev_id,
					      a_uint32_t phy_id,
					      a_uint32_t adv);
	typedef sw_error_t(*hsl_phy_eee_adv_get) (a_uint32_t dev_id,
					      a_uint32_t phy_id,
					      a_uint32_t * adv);
	typedef sw_error_t(*hsl_phy_eee_partner_adv_get) (a_uint32_t dev_id,
					      a_uint32_t phy_id,
					      a_uint32_t * adv);
	typedef sw_error_t(*hsl_phy_eee_cap_get) (a_uint32_t dev_id,
					      a_uint32_t phy_id,
					      a_uint32_t * cap);
	typedef sw_error_t(*hsl_phy_eee_status_get) (a_uint32_t dev_id,
					      a_uint32_t phy_id,
					      a_uint32_t * status);
/*qca808x_end*/
	typedef sw_error_t(*hsl_phy_led_ctrl_pattern_set) (a_uint32_t dev_id,
					      a_uint32_t phy_id,
					      led_ctrl_pattern_t * pattern);
	typedef sw_error_t(*hsl_phy_led_ctrl_pattern_get) (a_uint32_t dev_id,
					      a_uint32_t phy_id,
					      led_ctrl_pattern_t * pattern);
	typedef sw_error_t(*hsl_phy_led_ctrl_source_set) (a_uint32_t dev_id,
					      a_uint32_t phy_id,
					      a_uint32_t source_id,
					      led_ctrl_pattern_t * pattern);
	typedef sw_error_t(*hsl_phy_led_ctrl_source_get) (a_uint32_t dev_id,
					      a_uint32_t phy_id,
					      a_uint32_t source_id,
					      led_ctrl_pattern_t * pattern);
	typedef sw_error_t(*hsl_phy_pll_on) (a_uint32_t dev_id, a_uint32_t phy_id);
	typedef sw_error_t(*hsl_phy_pll_off) (a_uint32_t dev_id, a_uint32_t phy_id);
	typedef sw_error_t(*hsl_phy_ldo_set) (a_uint32_t dev_id, a_uint32_t phy_id,
				a_bool_t enable);

	typedef struct hsl_phy_ops_s {

		hsl_phy_init phy_init;
		hsl_phy_hibernation_set phy_hibernation_set;
		hsl_phy_hibernation_get phy_hibernation_get;
		hsl_phy_speed_get phy_speed_get;
		hsl_phy_speed_set phy_speed_set;
		hsl_phy_duplex_get phy_duplex_get;
		hsl_phy_duplex_set phy_duplex_set;
		hsl_phy_autoneg_enable_set phy_autoneg_enable_set;
		hsl_phy_autoneg_enable_get phy_autoneg_enable_get;
		hsl_phy_restart_autoneg phy_restart_autoneg;
		hsl_phy_autoneg_status_get phy_autoneg_status_get;
		hsl_phy_autoneg_adv_set phy_autoneg_adv_set;
		hsl_phy_autoneg_adv_get phy_autoneg_adv_get;
		hsl_phy_powersave_set phy_powersave_set;
		hsl_phy_powersave_get phy_powersave_get;
		hsl_phy_cdt phy_cdt;
		hsl_phy_link_status_get phy_link_status_get;
		hsl_phy_get_ability phy_get_ability;
		hsl_phy_mdix_set phy_mdix_set;
		hsl_phy_mdix_get phy_mdix_get;
		hsl_phy_mdix_status_get phy_mdix_status_get;
		hsl_phy_8023az_set phy_8023az_set;
		hsl_phy_8023az_get phy_8023az_get;
		hsl_phy_local_loopback_set phy_local_loopback_set;
		hsl_phy_local_loopback_get phy_local_loopback_get;
		hsl_phy_remote_loopback_set phy_remote_loopback_set;
		hsl_phy_remote_loopback_get phy_remote_loopback_get;
		hsl_phy_master_set phy_master_set;
		hsl_phy_master_get phy_master_get;
/*qca808x_end*/
		hsl_phy_combo_prefer_medium_set phy_combo_prefer_medium_set;
		hsl_phy_combo_prefer_medium_get phy_combo_prefer_medium_get;
		hsl_phy_combo_medium_status_get phy_combo_medium_status_get;
		hsl_phy_combo_fiber_mode_set phy_combo_fiber_mode_set;
		hsl_phy_combo_fiber_mode_get phy_combo_fiber_mode_get;
/*qca808x_start*/
		hsl_phy_function_reset phy_function_reset;
		hsl_phy_reset phy_reset;
		hsl_phy_power_off phy_power_off;
		hsl_phy_power_on phy_power_on;
		hsl_phy_reset_status_get phy_reset_status_get;
		hsl_phy_id_get phy_id_get;
		hsl_phy_reg_write phy_reg_write;
		hsl_phy_reg_read phy_reg_read;
		hsl_phy_debug_write phy_debug_write;
		hsl_phy_debug_read phy_debug_read;
		hsl_phy_mmd_write phy_mmd_write;
		hsl_phy_mmd_read phy_mmd_read;
		hsl_phy_magic_frame_mac_set phy_magic_frame_mac_set;
		hsl_phy_magic_frame_mac_get phy_magic_frame_mac_get;
		hsl_phy_wol_status_set phy_wol_status_set;
		hsl_phy_wol_status_get phy_wol_status_get;
		hsl_phy_interface_mode_set phy_interface_mode_set;
		hsl_phy_interface_mode_get phy_interface_mode_get;
		hsl_phy_interface_mode_status_get phy_interface_mode_status_get;
		hsl_phy_intr_mask_set  phy_intr_mask_set;
		hsl_phy_intr_mask_get  phy_intr_mask_get;
		hsl_phy_intr_status_get  phy_intr_status_get;
		hsl_phy_counter_set  phy_counter_set;
		hsl_phy_counter_get  phy_counter_get;
		hsl_phy_counter_show  phy_counter_show;
		hsl_phy_serdes_reset phy_serdes_reset;
		hsl_phy_get_status phy_get_status;
		hsl_phy_eee_adv_set phy_eee_adv_set;
		hsl_phy_eee_adv_get phy_eee_adv_get;
		hsl_phy_eee_partner_adv_get phy_eee_partner_adv_get;
		hsl_phy_eee_cap_get phy_eee_cap_get;
		hsl_phy_eee_status_get phy_eee_status_get;
/*qca808x_end*/
		hsl_phy_led_ctrl_pattern_set phy_led_ctrl_pattern_set;
		hsl_phy_led_ctrl_pattern_get phy_led_ctrl_pattern_get;
		hsl_phy_led_ctrl_source_set phy_led_ctrl_source_set;
		hsl_phy_led_ctrl_source_get phy_led_ctrl_source_get;
		hsl_phy_pll_on phy_pll_on;
		hsl_phy_pll_off phy_pll_off;
		hsl_phy_ldo_set phy_ldo_set;
/*qca808x_start*/
	} hsl_phy_ops_t;

typedef struct phy_driver_instance {
	a_uint32_t phy_type;
	a_uint32_t port_bmp[SW_MAX_NR_DEV];
	hsl_phy_ops_t *phy_ops;
	int (*init)(a_uint32_t dev_id, a_uint32_t portbmp);
	void (*exit)(a_uint32_t dev_id, a_uint32_t portbmp);
} phy_driver_instance_t;

typedef enum
{
/*qca808x_end*/
	F1_PHY_CHIP = 0,
	F2_PHY_CHIP,
	MALIBU_PHY_CHIP,
	AQUANTIA_PHY_CHIP,
	QCA803X_PHY_CHIP,
	SFP_PHY_CHIP,
	MPGE_PHY_CHIP,
/*qca808x_start*/
	QCA808X_PHY_CHIP,
	MAX_PHY_CHIP,
} phy_type_t;

typedef struct {
	a_uint8_t mdac;
	a_uint8_t edac;
} phy_dac_t;

typedef struct {
	a_uint32_t phy_address[SW_MAX_NR_PORT];
	a_uint8_t port_force_duplex[SW_MAX_NR_PORT];
	a_uint32_t port_force_speed[SW_MAX_NR_PORT];
	phy_features_t phy_features[SW_MAX_NR_PORT];
	a_uint32_t phy_type[SW_MAX_NR_PORT];
#if defined(IN_PHY_I2C_MODE)
	/* fake mdio address is used to register the phy device,
	 * when the phy is not accessed by the MDIO bus, and is
	 for i2c qca808x PHY only
	 * */
	a_uint32_t phy_mdio_fake_address[SW_MAX_NR_PORT];
#endif
	a_uint32_t phy_reset_gpio[SW_MAX_NR_PORT];
	phy_dac_t phy_dac[SW_MAX_NR_PORT];
	a_bool_t port_link_status[SW_MAX_NR_PORT];
	a_uint32_t port_mode[SW_MAX_NR_PORT];
	a_uint32_t combo_phy_type[SW_MAX_NR_PORT];
	struct net_device *netdev[SW_MAX_NR_PORT];
} phy_info_t;

#define INVALID_PHY_ID          0xFFFFFFFF
#define AQUANTIA_PHY_107        0x03a1b4e2
#define AQUANTIA_PHY_108        0x03a1b4f2
#define AQUANTIA_PHY_109        0x03a1b502
#define AQUANTIA_PHY_111        0x03a1b610
#define AQUANTIA_PHY_111B0      0x03a1b612
#define AQUANTIA_PHY_112        0x03a1b660
#define AQUANTIA_PHY_113C_A0    0x31c31C10
#define AQUANTIA_PHY_113C_A1    0x31c31C11
#define AQUANTIA_PHY_113C_B0    0x31c31C12
#define AQUANTIA_PHY_113C_B1    0x31c31C13
#define AQUANTIA_PHY_112C       0x03a1b792
#define MVL_PHY_X3410           0x31c31DD3
#define SFP_PHY                 0xaaaabbbb
#define MP_GEPHY                0x004DD0C0
#define SFP_PHY_MASK            0xffffffff

#define CABLE_PAIR_A            0
#define CABLE_PAIR_B            1
#define CABLE_PAIR_C            2
#define CABLE_PAIR_D            3
/*qca808x_start*/
#define PHY_MDIO_ACCESS         0
#define PHY_I2C_ACCESS          1

#define INVALID_PHY_ADDR        0xfff
#define MAX_PHY_ADDR            0xf1f

#define PHY_INVALID_DATA 0xffff

#define PHY_RTN_ON_READ_ERROR(phy_data) \
    do { if (phy_data == PHY_INVALID_DATA) return(SW_READ_ERROR); } while(0);

#define PHY_RTN_ON_ERROR(rv) \
    do { if (rv != SW_OK) return(rv); } while(0);

#define TO_PHY_ADDR_E(phy_addr, miibus_index) (phy_addr | (miibus_index << 8))
#define TO_PHY_ADDR(phy_addr_e) (phy_addr_e & 0x1f)
#define TO_MIIBUS_INDEX(phy_addr_e) (phy_addr_e >> 8 & 0xf)

#define TO_PHY_I2C_ADDR(phy_addr) (BIT(24) | phy_addr)
#define TO_PHY_I2C_ADDR_VAL(i2c_addr) (i2c_addr & 0x7f)
#define IS_I2C_PHY_ADDR(phy_addr) (phy_addr & BIT(24))

hsl_phy_ops_t *hsl_phy_api_ops_get(a_uint32_t dev_id, a_uint32_t port_id);

int ssdk_phy_driver_init(a_uint32_t dev_id);

int qca_ssdk_phy_info_init(a_uint32_t dev_id);

void qca_ssdk_port_bmp_init(a_uint32_t dev_id);
a_bool_t
qca_ssdk_gpio_is_invalid(a_uint32_t dev_id, a_uint32_t gpio_num);
/*qca808x_end*/
void hsl_phy_address_init(a_uint32_t dev_id, a_uint32_t i,
				a_uint32_t value);
/*qca808x_start*/
a_uint32_t
hsl_phyid_get(a_uint32_t dev_id, a_uint32_t port_id);

a_uint32_t
qca_ssdk_port_to_phy_addr(a_uint32_t dev_id, a_uint32_t port_id);
/*qca808x_end*/
#if defined(IN_PHY_I2C_MODE)
a_uint32_t
qca_ssdk_port_to_phy_mdio_fake_addr(a_uint32_t dev_id, a_uint32_t port_id);

void qca_ssdk_phy_mdio_fake_address_set(a_uint32_t dev_id, a_uint32_t i,
				a_uint32_t value);
#endif
/*qca808x_start*/
void qca_ssdk_port_bmp_set(a_uint32_t dev_id, a_uint32_t value);

a_uint32_t qca_ssdk_port_bmp_get(a_uint32_t dev_id);
a_uint32_t
qca_ssdk_phy_addr_to_port(a_uint32_t dev_id, a_uint32_t phy_addr);
/*qca808x_end*/
a_uint32_t
qca_ssdk_phydev_to_port(a_uint32_t dev_id, struct phy_device *phydev);
void
hsl_port_phy_c45_capability_set(a_uint32_t dev_id, a_uint32_t port_id,
			a_bool_t enable);

a_bool_t
hsl_port_phy_combo_capability_get(a_uint32_t dev_id, a_uint32_t port_id);

void
hsl_port_phy_combo_capability_set(a_uint32_t dev_id, a_uint32_t port_id,
		a_bool_t enable);
/*qca808x_start*/
a_uint8_t
hsl_port_phy_access_type_get(a_uint32_t dev_id, a_uint32_t port_id);

void
hsl_port_phy_access_type_set(a_uint32_t dev_id, a_uint32_t port_id,
		a_uint8_t access_type);
/*qca808x_end*/
sw_error_t
hsl_port_phy_serdes_reset(a_uint32_t dev_id);

phy_type_t hsl_phy_type_get(a_uint32_t dev_id, a_uint32_t port_id);

a_uint32_t
hsl_port_phyid_get(a_uint32_t dev_id, fal_port_t port_id);

a_uint32_t hsl_port_phy_reset_gpio_get(a_uint32_t dev_id, a_uint32_t port_id);

void hsl_port_phy_reset_gpio_set(a_uint32_t dev_id, a_uint32_t port_id,
	a_uint32_t phy_reset_gpio);

void hsl_port_phy_gpio_reset(a_uint32_t dev_id, a_uint32_t port_id);

void
hsl_port_phy_dac_get(a_uint32_t dev_id, a_uint32_t port_id,
	phy_dac_t *phy_dac);

void
hsl_port_phy_dac_set(a_uint32_t dev_id, a_uint32_t port_id,
	phy_dac_t phy_dac);

a_bool_t hsl_port_is_sfp(a_uint32_t dev_id, a_uint32_t port_id);

a_bool_t hsl_port_phy_connected(a_uint32_t dev_id, fal_port_t port_id);
/*qca808x_start*/
sw_error_t ssdk_phy_driver_cleanup(a_uint32_t dev_id);
/*qca808x_end*/
sw_error_t
hsl_phydriver_update(a_uint32_t dev_id, a_uint32_t port_id);

void
qca_ssdk_phy_address_set(a_uint32_t dev_id, a_uint32_t port_id,
	a_uint32_t phy_addr);

sw_error_t
hsl_port_phy_hw_init(a_uint32_t dev_id, a_uint32_t port_id);

sw_error_t
hsl_port_phydev_get(a_uint32_t dev_id, a_uint32_t port_id,
	struct phy_device **phydev);
sw_error_t
hsl_phy_phydev_get(a_uint32_t dev_id, a_uint32_t phy_addr,
	struct phy_device **phydev);
sw_error_t
hsl_port_phydev_interface_mode_status_get(a_uint32_t dev_id, a_uint32_t port_id,
	fal_port_interface_mode_t *interface_mode_status);
sw_error_t
hsl_phy_adv_to_linkmode_adv(a_uint32_t autoadv, a_ulong_t *advertising);
#ifdef IN_LED
sw_error_t
hsl_port_phy_led_ctrl_pattern_set(a_uint32_t dev_id, led_pattern_group_t group,
	a_uint32_t port_id, led_ctrl_pattern_t * pattern);
sw_error_t
hsl_port_phy_led_ctrl_pattern_get(a_uint32_t dev_id, led_pattern_group_t group,
	a_uint32_t port_id, led_ctrl_pattern_t * pattern);
#endif
phy_info_t *hsl_phy_info_get(a_uint32_t dev_id);

sw_error_t
hsl_phy_phydev_autoneg_update(a_uint32_t dev_id, a_uint32_t phy_addr,
	a_bool_t autoneg_en, a_uint32_t autoadv);
a_uint32_t
hsl_phy_speed_duplex_to_auto_adv(fal_port_speed_t speed,
	fal_port_duplex_t duplex);
sw_error_t
hsl_phy_linkmode_adv_to_adv(a_ulong_t *advertising, a_uint32_t *autoadv);
sw_error_t
hsl_port_phy_adv_update(a_uint32_t dev_id, a_uint32_t port_id,
	a_uint32_t adv_mask, a_uint32_t adv);
sw_error_t
hsl_port_phy_txfc_set(a_uint32_t dev_id, a_uint32_t port_id, a_bool_t enable);
sw_error_t
hsl_port_phy_rxfc_set(a_uint32_t dev_id, a_uint32_t port_id, a_bool_t enable);
a_uint32_t
hsl_port_mode_to_phydev_interface(a_uint32_t dev_id, a_uint32_t port_mode);
a_uint32_t
hsl_port_mode_to_uniphy_mode(a_uint32_t dev_id, a_uint32_t port_mode);
a_uint32_t
hsl_uniphy_mode_to_port_mode(a_uint32_t dev_id, a_uint32_t port_id,
	a_uint32_t uniphy_mode);
a_uint32_t
hsl_port_to_uniphy(a_uint32_t dev_id, a_uint32_t port_id);
sw_error_t
hsl_port_combo_phy_link_status_get(a_uint32_t dev_id,
	a_uint32_t port_id, fal_port_combo_link_status_t * status);
sw_error_t
hsl_port_combo_phy_driver_update(a_uint32_t dev_id,
	a_uint32_t port_id, fal_port_medium_t medium);
sw_error_t
hsl_port_phydev_get_status(a_uint32_t dev_id, a_uint32_t port_id,
	struct port_phy_status *phy_status);
/*qca808x_end*/
a_uint32_t
hsl_port_force_speed_get(a_uint32_t dev_id, a_uint32_t port_id);
void
hsl_port_force_speed_set(a_uint32_t dev_id, a_uint32_t port_id, a_uint32_t speed);
a_uint8_t
hsl_port_force_duplex_get(a_uint32_t dev_id, a_uint32_t port_id);
void
hsl_port_force_duplex_set(a_uint32_t dev_id, a_uint32_t port_id, a_uint8_t duplex);
/*qca808x_start*/
a_bool_t
hsl_port_feature_get(a_uint32_t dev_id, a_uint32_t port_id, phy_features_t feature);
sw_error_t
hsl_port_feature_set(a_uint32_t dev_id, a_uint32_t port_id, phy_features_t feature);
sw_error_t
hsl_port_feature_clear(a_uint32_t dev_id, a_uint32_t port_id, phy_features_t feature);
phy_type_t
hsl_phytype_get_by_phyid(a_uint32_t dev_id, a_uint32_t phy_id);
/*********************APIs to access PHY with MDIO and I2C*********************/
#define HSL_PHY_REG_C45_ADDR(mmd_num, reg_num) (BIT(30) | mmd_num << 16 | reg_num)
#define HSL_PHY_MMD_CTRL_REG                                   13
#define HSL_PHY_MMD_DATA_REG                                   14
#define HSL_PHY_DEBUG_PORT_ADDRESS                             29
#define HSL_PHY_DEBUG_PORT_DATA                                30
#define I2C_ADAPTER_DEFAULT_ID                                 0

/*APIs to access mii register*/
a_uint32_t hsl_phy_mii_soc_read(a_uint32_t dev_id, a_uint32_t phy_addr,
	a_uint32_t reg);
void hsl_phy_mii_soc_write(a_uint32_t dev_id, a_uint32_t phy_addr,
	a_uint32_t reg, a_uint32_t val);
a_uint16_t
__hsl_phy_mii_reg_read(a_uint32_t dev_id, a_uint32_t phy_addr, a_uint32_t mii_reg);
sw_error_t
__hsl_phy_mii_reg_write(a_uint32_t dev_id, a_uint32_t phy_addr, a_uint32_t mii_reg,
	a_uint16_t reg_val);
sw_error_t
__hsl_phy_modify_mii(a_uint32_t dev_id, a_uint32_t phy_addr, a_uint32_t mii_reg,
	a_uint16_t mask, a_uint16_t value);
a_uint16_t
hsl_phy_mii_reg_read(a_uint32_t dev_id, a_uint32_t phy_addr, a_uint32_t mii_reg);
sw_error_t
hsl_phy_mii_reg_write(a_uint32_t dev_id, a_uint32_t phy_addr, a_uint32_t mii_reg,
	a_uint16_t reg_val);
sw_error_t
hsl_phy_modify_mii(a_uint32_t dev_id, a_uint32_t phy_addr, a_uint32_t mii_reg,
	a_uint16_t mask, a_uint16_t value);
/*APIs to access mmd register*/
a_uint16_t
__hsl_phy_mmd_reg_read(a_uint32_t dev_id, a_uint32_t phy_addr, a_bool_t is_c45,
	a_uint32_t mmd_num, a_uint32_t mmd_reg);
sw_error_t
__hsl_phy_mmd_reg_write(a_uint32_t dev_id, a_uint32_t phy_addr, a_bool_t is_c45,
	a_uint32_t mmd_num, a_uint32_t mmd_reg, a_uint16_t reg_val);
sw_error_t
__hsl_phy_modify_mmd(a_uint32_t dev_id, a_uint32_t phy_addr, a_bool_t is_c45,
	a_uint32_t mmd_num, a_uint32_t mmd_reg, a_uint16_t mask, a_uint16_t value);
a_uint16_t
hsl_phy_mmd_reg_read(a_uint32_t dev_id, a_uint32_t phy_addr, a_bool_t is_c45,
	a_uint32_t mmd_num, a_uint32_t mmd_reg);
sw_error_t
hsl_phy_mmd_reg_write(a_uint32_t dev_id, a_uint32_t phy_addr, a_bool_t is_c45,
	a_uint32_t mmd_num, a_uint32_t mmd_reg, a_uint16_t reg_val);
sw_error_t
hsl_phy_modify_mmd(a_uint32_t dev_id, a_uint32_t phy_addr, a_bool_t is_c45,
	a_uint32_t mmd_num, a_uint32_t mmd_reg, a_uint16_t mask, a_uint16_t value);
/*APIs to access debug register*/
a_uint16_t
__hsl_phy_debug_reg_read(a_uint32_t dev_id, a_uint32_t phy_addr,
	a_uint32_t debug_reg);
sw_error_t
__hsl_phy_debug_reg_write(a_uint32_t dev_id, a_uint32_t phy_id,
	a_uint32_t debug_reg, a_uint16_t reg_val);
sw_error_t
__hsl_phy_modify_debug(a_uint32_t dev_id, a_uint32_t phy_addr,
	a_uint32_t debug_reg, a_uint16_t mask, a_uint16_t value);
a_uint16_t
hsl_phy_debug_reg_read(a_uint32_t dev_id, a_uint32_t phy_addr,
	a_uint32_t debug_reg);
sw_error_t
hsl_phy_debug_reg_write(a_uint32_t dev_id, a_uint32_t phy_addr,
	a_uint32_t debug_reg, a_uint16_t reg_val);
sw_error_t
hsl_phy_modify_debug(a_uint32_t dev_id, a_uint32_t phy_addr,
	a_uint32_t debug_reg, a_uint16_t mask, a_uint16_t value);
/*use the phy driver of nss ext or linux std for HSL APIs*/
enum hsl_phy_api_id {
	hibernation_set,
	hibernation_get,
	cdt,
	mdix_set,
	mdix_get,
	mdix_status_get,
	stats_status_set,
	stats_status_get,
	stats_get,
	intr_mask_set,
	intr_mask_get,
	intr_status_get,
	powersave_set,
	powersave_get,
	eee_adv_set,
	eee_adv_get,
	eee_partner_adv_get,
	eee_cap_get,
	eee_status_get,
	ieee_8023az_set,
	ieee_8023az_get,
	local_loopback_set,
	local_loopback_get,
	remote_loopback_set,
	remote_loopback_get,
	function_reset,
	led_ctrl_source_set,
	led_ctrl_source_get,
	interface_set,
	interface_get,
	combo_prefer_medium_set,
	combo_prefer_medium_get,
	combo_medium_status_get,
	combo_fiber_mode_set,
	combo_fiber_mode_get,
	pll_on,
	pll_off,
	ldo_set,
	adjust_link_post,
	duplex_get,
	duplex_set,
	wol_set,
	wol_get,
	magic_frame_set,
	magic_frame_get,
	phyid_get,
	autoadv_get,
	autoadv_set,
	autoneg_restart,
	autoneg_status_get,
	autoneg_enable,
	speed_set,
	speed_get,
	link_status_get,
	reset,
	power_on,
	power_off,
	api_max,
};

struct hsl_phy_api {
	enum hsl_phy_api_id id;
	int (*phy_std)(struct phy_device*, ...);
};

sw_error_t hsl_port_nss_phy_ops_get(a_uint32_t dev_id, fal_port_t port_id,
	struct nss_phy_device *nss_phydev, struct nss_phy_ops  **nss_phy_ops);
struct hsl_phy_api *hsl_phy_api_get(a_uint32_t id);

#define HSL_PORT_PHY_EXT_API_RUN(func, dev_id, port_id, ...) \
	{ \
		struct nss_phy_ops *nss_phy_ops = NULL; \
		struct nss_phy_device nss_phydev; \
		hsl_port_nss_phy_ops_get(dev_id, port_id, &nss_phydev, &nss_phy_ops); \
		if (nss_phy_ops && nss_phy_ops->func) { \
			rv = nss_phy_ops->func(&nss_phydev, ##__VA_ARGS__); \
		} \
	}

#define HSL_PORT_PHY_API_RUN(func, dev_id, port_id, ...) \
	{ \
		if (hsl_port_phy_connected(dev_id, port_id)) { \
			struct phy_device *phydev = NULL; \
			struct hsl_phy_api *api = NULL; \
			api = hsl_phy_api_get(func); \
			hsl_port_phydev_get(dev_id, port_id, &phydev); \
			if (api && api->phy_std && phydev) { \
				rv = api->phy_std(phydev, ##__VA_ARGS__); \
			} else { \
				HSL_PORT_PHY_EXT_API_RUN(func, dev_id, port_id, ##__VA_ARGS__); \
			} \
		} \
	}

#ifdef IN_AQUANTIA_PHY
/* this macro is for the features that NSS PHY and AQR PHY both supported */
#define HSL_PORT_PHY_EXT_NSS_WITH_AQR_API_RUN(func, dev_id, port_id, ...) \
	{ \
		struct nss_phy_ops *nss_phy_ops = NULL; \
		struct nss_phy_device nss_phydev; \
		hsl_port_nss_phy_ops_get(dev_id, port_id, &nss_phydev, &nss_phy_ops); \
		if (nss_phy_ops && nss_phy_ops->func) { \
			rv = nss_phy_ops->func(&nss_phydev, ##__VA_ARGS__); \
		} else { \
			a_uint32_t phy_addr = 0; \
			hsl_port_prop_get_phyid (dev_id, port_id, &phy_addr); \
			rv = aquantia_phy_##func(dev_id, phy_addr, ##__VA_ARGS__); \
		} \
	}
#else
#define HSL_PORT_PHY_EXT_NSS_WITH_AQR_API_RUN HSL_PORT_PHY_API_RUN
#endif

#define HSL_PORT_PHY_PTP_API_RUN(func, dev_id, port_id, ...)					\
	{											\
		if (hsl_port_phy_connected(dev_id, port_id)) {					\
			struct nss_phy_ops *nss_phy_ops = NULL;					\
			struct nss_phy_ptp_ops *ptp_ops = NULL;					\
			struct nss_phy_device nss_phydev;					\
			hsl_port_nss_phy_ops_get(dev_id, port_id, &nss_phydev, &nss_phy_ops);	\
			ptp_ops = nss_phy_ops->ptp_ops;						\
			if (ptp_ops && ptp_ops->func)						\
				rv = ptp_ops->func(&nss_phydev, ##__VA_ARGS__);			\
		}										\
	}

#ifdef __cplusplus
}
#endif				/* __cplusplus */
#endif				/* _HSL_PHY_H_ */
/*qca808x_end*/
