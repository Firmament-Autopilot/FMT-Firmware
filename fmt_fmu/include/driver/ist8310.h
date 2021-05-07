/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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
#ifndef __IST8310_H__
#define __IST8310_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define REG_WHOAMI       0x00
#define REG_STAT1        0x02
#define REG_DATA_OUT_X_L 0x03
#define REG_DATA_OUT_X_H 0x04
#define REG_DATA_OUT_Y_L 0x05
#define REG_DATA_OUT_Y_H 0x06
#define REG_DATA_OUT_Z_L 0x07
#define REG_DATA_OUT_Z_H 0x08
#define REG_STAT2        0x09
#define REG_CTRL1        0x0a
#define REG_CTRL2        0x0b
#define REG_TEMP_L       0x1c
#define REG_TEMP_H       0x1d
#define REG_CTRL3        0x41
#define REG_CTRL4        0x42

#define CTRL1_ODR_SINGLE 0x01 /* Single measurement mode */
#define CTRL1_ODR_10_HZ  0x03
#define CTRL1_ODR_20_HZ  0x05
#define CTRL1_ODR_50_HZ  0x07
#define CTRL1_ODR_100_HZ 0x06
#define CTRL1_ODR_200_HZ 0x0B

#define CTRL2_SRST 0x01 /* Software reset */

#define CTRL3_SAMPLEAVG_16 0x24 /* Sample Averaging 16 */
#define CTRL3_SAMPLEAVG_8  0x1b /* Sample Averaging 8 */
#define CTRL3_SAMPLEAVG_4  0x12 /* Sample Averaging 4 */
#define CTRL3_SAMPLEAVG_2  0x09 /* Sample Averaging 2 */
#define CTRL4_SRPD         0xC0 /* Set Reset Pulse Duration */

rt_err_t drv_ist8310_init(const char* device_name);

#ifdef __cplusplus
}
#endif

#endif