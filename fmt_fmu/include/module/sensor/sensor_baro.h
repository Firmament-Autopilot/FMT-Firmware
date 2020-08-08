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
#ifndef __SENSOR_BARO_H__
#define __SENSOR_BARO_H__

#include <firmament.h>
#include "hal/barometer.h"

fmt_err sensor_baro_init(void);
uint8_t sensor_baro_check_update(void);
fmt_err sensor_baro_get_report(baro_report_t* report);

#endif