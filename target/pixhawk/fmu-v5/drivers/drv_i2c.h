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
#ifndef DRV_I2C_H__
#define DRV_I2C_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

/* i2c slave device 7-bits addresses */
#define IST8310_ADDRESS  0x0E
#define NCP5623C_ADDRESS 0x39
#define MS4525_ADDRESS   0x28

rt_err_t drv_i2c_init(void);

#ifdef __cplusplus
}
#endif

#endif
