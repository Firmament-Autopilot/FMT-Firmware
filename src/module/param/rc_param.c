/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <firmament.h>

#include "module/param/param.h"

/* define parameters */
static param_t __param_list[] = {
    /* RC channel calibration value */
    PARAM_FLOAT(RC1_MAX, 2000.0f, false),
    PARAM_FLOAT(RC1_MIN, 1000.0f, false),
    PARAM_FLOAT(RC1_REV, 1.0f, false),
    PARAM_FLOAT(RC1_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC2_MAX, 2000.0f, false),
    PARAM_FLOAT(RC2_MIN, 1000.0f, false),
    PARAM_FLOAT(RC2_REV, 1.0f, false),
    PARAM_FLOAT(RC2_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC3_MAX, 2000.0f, false),
    PARAM_FLOAT(RC3_MIN, 1000.0f, false),
    PARAM_FLOAT(RC3_REV, 1.0f, false),
    PARAM_FLOAT(RC3_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC4_MAX, 2000.0f, false),
    PARAM_FLOAT(RC4_MIN, 1000.0f, false),
    PARAM_FLOAT(RC4_REV, 1.0f, false),
    PARAM_FLOAT(RC4_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC5_MAX, 2000.0f, false),
    PARAM_FLOAT(RC5_MIN, 1000.0f, false),
    PARAM_FLOAT(RC5_REV, 1.0f, false),
    PARAM_FLOAT(RC5_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC6_MAX, 2000.0f, false),
    PARAM_FLOAT(RC6_MIN, 1000.0f, false),
    PARAM_FLOAT(RC6_REV, 1.0f, false),
    PARAM_FLOAT(RC6_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC7_MAX, 2000.0f, false),
    PARAM_FLOAT(RC7_MIN, 1000.0f, false),
    PARAM_FLOAT(RC7_REV, 1.0f, false),
    PARAM_FLOAT(RC7_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC8_MAX, 2000.0f, false),
    PARAM_FLOAT(RC8_MIN, 1000.0f, false),
    PARAM_FLOAT(RC8_REV, 1.0f, false),
    PARAM_FLOAT(RC8_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC9_MAX, 2000.0f, false),
    PARAM_FLOAT(RC9_MIN, 1000.0f, false),
    PARAM_FLOAT(RC9_REV, 1.0f, false),
    PARAM_FLOAT(RC9_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC10_MAX, 2000.0f, false),
    PARAM_FLOAT(RC10_MIN, 1000.0f, false),
    PARAM_FLOAT(RC10_REV, 1.0f, false),
    PARAM_FLOAT(RC10_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC11_MAX, 2000.0f, false),
    PARAM_FLOAT(RC11_MIN, 1000.0f, false),
    PARAM_FLOAT(RC11_REV, 1.0f, false),
    PARAM_FLOAT(RC11_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC12_MAX, 2000.0f, false),
    PARAM_FLOAT(RC12_MIN, 1000.0f, false),
    PARAM_FLOAT(RC12_REV, 1.0f, false),
    PARAM_FLOAT(RC12_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC13_MAX, 2000.0f, false),
    PARAM_FLOAT(RC13_MIN, 1000.0f, false),
    PARAM_FLOAT(RC13_REV, 1.0f, false),
    PARAM_FLOAT(RC13_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC14_MAX, 2000.0f, false),
    PARAM_FLOAT(RC14_MIN, 1000.0f, false),
    PARAM_FLOAT(RC14_REV, 1.0f, false),
    PARAM_FLOAT(RC14_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC15_MAX, 2000.0f, false),
    PARAM_FLOAT(RC15_MIN, 1000.0f, false),
    PARAM_FLOAT(RC15_REV, 1.0f, false),
    PARAM_FLOAT(RC15_TRIM, 1500.0f, false),
    PARAM_FLOAT(RC16_MAX, 2000.0f, false),
    PARAM_FLOAT(RC16_MIN, 1000.0f, false),
    PARAM_FLOAT(RC16_REV, 1.0f, false),
    PARAM_FLOAT(RC16_TRIM, 1500.0f, false),
    /* RC channel count, only used by ground station */
    PARAM_INT32(RC_CHAN_CNT, 0, false),
};
PARAM_GROUP_DEFINE(RC, __param_list);