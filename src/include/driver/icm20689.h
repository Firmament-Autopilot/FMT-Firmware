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
#ifndef ICM20689_H__
#define ICM20689_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

rt_err_t drv_icm20689_init(const char* spi_device_name, const char* gyro_device_name, const char* accel_device_name);

#ifdef __cplusplus
}
#endif

#endif
