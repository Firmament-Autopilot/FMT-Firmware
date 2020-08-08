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
#ifndef __SENSOR_GPS_H__
#define __SENSOR_GPS_H__

#include <firmament.h>
#include "module/sensor/sensor_manager.h"

fmt_err sensor_gps_init(void);
uint8_t sensor_gps_report_ready(void);
fmt_err sensor_gps_get_report(GPS_Report* gps_report);

#endif