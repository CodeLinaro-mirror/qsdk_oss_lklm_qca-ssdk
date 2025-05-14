/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: ISC
 */

#include <linux/kernel.h>
#include "sw_error.h"
#include "aos_types.h"

#if defined(HMSPPE)
#include "hmsppe/hsl_hms_reg.h"
#elif defined(JHPPE)
#include "hmsppe/hsl_hms_reg.h" //to be fixed by Chao
#else
#include "appe/hsl_appe_reg.h"
#endif
