/*
 * Copyright (c) 2018, The Linux Foundation. All rights reserved.
 *
 * Copyright (c) 2022-2024 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <linux/kconfig.h>
#include <linux/version.h>
#include <linux/phy.h>
#include <linux/kthread.h>

#include "hsl.h"
#include "ssdk_plat.h"
#include "hsl_phy.h"
#include "qcaphy_common.h"
#include "hsl_ptp.h"
#include "qca808x_phy.h"

#define QCA808X_PHY_DRIVER_NAME	"QCA808X ethernet"
#define QCA808X_SSDK_PHY_DRIVER_NAME	"QCA808X SSDK ethernet"

struct qca808x_phy_info {
	struct list_head list;
	a_uint32_t dev_id;
	/* phy real address,it is the mdio addr or the i2c slave addr */
	a_uint32_t phy_addr;
	/* the address of phy device, it is a fake addr for the i2c accessed phy */
	a_uint32_t phydev_addr;
};

typedef struct {
	struct phy_device *phydev;
	struct qca808x_phy_info *phy_info;
} qca808x_priv;

void qca808x_phydev_init(a_uint32_t dev_id, a_uint32_t port_id);
void qca808x_phydev_deinit(a_uint32_t dev_id, a_uint32_t port_id);
a_int32_t qca808x_phy_driver_register(void);
void qca808x_phy_driver_unregister(void);
int qca808x_phy_probe(struct phy_device *phydev);
void qca808x_phy_remove(struct phy_device *phydev);
