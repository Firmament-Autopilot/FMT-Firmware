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

#include "module/sensor/sensor_manager.h"

sensor_imu_t sensor_imu_init(const char* gyr_dev_name, const char* acc_dev_name);

fmt_err sensor_gyr_raw_measure(sensor_imu_t imu_dev, int16_t gyr[3]);
fmt_err sensor_gyr_measure(sensor_imu_t imu_dev, float gyr[3]);
void sensor_gyr_set_rotation(sensor_imu_t imu_dev, const float rotation[9]);
void sensor_gyr_set_offset(sensor_imu_t imu_dev, const float offset[3]);
void sensor_gyr_correct(sensor_imu_t imu_dev, const float gyr[3], float gyr_cor[3]);

fmt_err sensor_acc_raw_measure(sensor_imu_t imu_dev, int16_t acc[3]);
fmt_err sensor_acc_measure(sensor_imu_t imu_dev, float acc[3]);
void sensor_acc_set_rotation(sensor_imu_t imu_dev, const float rotation[9]);
void sensor_acc_set_offset(sensor_imu_t imu_dev, const float offset[3]);
void sensor_acc_correct(sensor_imu_t imu_dev, const float acc[3], float acc_cor[3]);

#endif
