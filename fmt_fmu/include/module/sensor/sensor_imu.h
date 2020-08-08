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

#ifndef __SENSOR_IMU_H__
#define __SENSOR_IMU_H__

#include <firmament.h>

#define SENSOR_IMU_NUM              2

fmt_err sensor_imu_init(void);

fmt_err sensor_gyr_raw_measure(int16_t gyr[3], uint8_t imu_id);
fmt_err sensor_gyr_measure(float gyr[3], uint8_t imu_id);
fmt_err sensor_acc_raw_measure(int16_t acc[3], uint8_t imu_id);
fmt_err sensor_acc_measure(float acc[3], uint8_t imu_id);

#endif
