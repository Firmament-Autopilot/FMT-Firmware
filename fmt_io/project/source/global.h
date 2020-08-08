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
#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifndef USE_STDPERIPH_DRIVER
	#define USE_STDPERIPH_DRIVER
#endif

#include <stdio.h>
#include "stm32f10x.h"

//#define USE_LIDAR
#define USE_PWM_OUTPUT

uint8_t constrain(float* val, float min_val, float max_val);

#endif

