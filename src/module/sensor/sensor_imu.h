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
#ifndef SENSOR_IMU_H__
#define SENSOR_IMU_H__

#include <firmament.h>

#include "module/sensor/sensor_hub.h"

#ifdef __cplusplus
extern "C" {
#endif

sensor_imu_t sensor_imu_init(const char* gyr_dev_name, const char* acc_dev_name);
/* gyro api */
fmt_err_t sensor_gyr_measure(sensor_imu_t imu_dev, float buffer[3]);
void sensor_gyr_set_rotation(sensor_imu_t imu_dev, const float rotation[9]);
void sensor_gyr_set_offset(sensor_imu_t imu_dev, const float offset[3]);
void sensor_gyr_correct(sensor_imu_t imu_dev, const float src[3], float dst[3]);
/* accel api */
fmt_err_t sensor_acc_measure(sensor_imu_t imu_dev, float buffer[3]);
void sensor_acc_set_rotation(sensor_imu_t imu_dev, const float rotation[9]);
void sensor_acc_set_offset(sensor_imu_t imu_dev, const float offset[3]);
void sensor_acc_correct(sensor_imu_t imu_dev, const float src[3], float dst[3]);

#ifdef __cplusplus
}
#endif

#endif
