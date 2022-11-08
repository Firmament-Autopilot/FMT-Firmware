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

#ifndef DRV_SYSTICK_H__
#define DRV_SYSTICK_H__

#include <firmament.h>
#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_SYS_TICK_COUNT (0xFFFFFFFFUL)

void HAL_Delay(volatile uint32_t Delay);
rt_err_t drv_systick_init(void);

/* HAL exported functions */
uint32_t HAL_GetTick(void);

void SysTicks_IncTickCount(void);
uint32_t SysTicks_GetTickCount(void);
uint64_t SysTicks_GetUsTickCount(void);

void SysTicks_DelayMS(uint32_t msDelay);
void SysTicks_DelayUS(uint64_t usDelay);
uint32_t SysTicks_GetDiff(uint32_t u32_start, uint32_t u32_end);
uint64_t SysTicks_GetUsDiff(uint64_t u64_start, uint64_t u64_end);


#ifdef __cplusplus
}
#endif

#endif
