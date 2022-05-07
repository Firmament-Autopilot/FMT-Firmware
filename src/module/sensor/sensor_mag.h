/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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
#ifndef SENSOR_MAG_H__
#define SENSOR_MAG_H__

#include <firmament.h>

#include "module/sensor/sensor_hub.h"

#ifdef __cplusplus
extern "C" {
#endif

sensor_mag_t sensor_mag_init(const char* mag_dev_name);
fmt_err_t sensor_mag_measure(sensor_mag_t mag_dev, float buffer[3]);
void sensor_mag_set_rotation(sensor_mag_t mag_dev, const float rotation[9]);
void sensor_mag_set_offset(sensor_mag_t mag_dev, const float offset[3]);
void sensor_mag_correct(sensor_mag_t mag_dev, const float src[3], float dst[3]);

#ifdef __cplusplus
}
#endif

#endif