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

#ifndef __SENSOR_MAG_H__
#define __SENSOR_MAG_H__

#include <firmament.h>

#define MAG1_DEVICE_NAME			"lsm303d"
#define MAG2_DEVICE_NAME			"hmc5883"   //external mag

rt_err_t sensor_mag_init(void);

rt_err_t sensor_mag_raw_measure(int16_t mag[3], uint8_t mag_id);
rt_err_t sensor_mag_measure(float mag[3], uint8_t mag_id);

#endif