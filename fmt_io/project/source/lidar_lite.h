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

#ifndef  _LIDAR_LITE_H_
#define  _LIDAR_LITE_H_

#include "stm32f10x.h"

uint8_t lidar_lite_init(void);
uint8_t send_lidar_distance(void);
uint8_t lidar_lite_ready(void);
void lidar_lite_clear_ready(void);

#endif
