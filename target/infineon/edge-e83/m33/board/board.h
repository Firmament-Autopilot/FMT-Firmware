/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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

#ifndef __BOARD_H__
#define __BOARD_H__

#include "drv_gpio.h"
#include <rtthread.h>

#include "cy_result.h"
#include "cybsp.h"
#include "cybsp_types.h"
#include "mtb_hal.h"

#ifdef BSP_USING_USBD
    #include "cy_usb_dev.h"
    #include "cy_usb_dev_hid.h"
#endif

/*SRAM CONFIG*/
#define IFX_SRAM_SIZE (256)
#define IFX_SRAM_END  (0x240BD000 + IFX_SRAM_SIZE * 1024)

#ifdef __ARMCC_VERSION
extern int Image$$RW_IRAM1$$ZI$$Limit;
    #define HEAP_BEGIN (&Image$$RW_IRAM1$$ZI$$Limit)
    #define HEAP_END   IFX_SRAM_END
#elif __ICCARM__
    #pragma section = "HEAP"
    #define HEAP_BEGIN (__segment_end("HEAP"))
#else
extern unsigned int __end__;
extern unsigned int __HeapLimit;
    #define HEAP_BEGIN (void*)&__end__
    #define HEAP_END   (void*)&__HeapLimit
#endif

#define TARGET_NAME "e83"

void cy_bsp_all_init(void);

void rt_hw_board_init(void);

void bsp_early_initialize(void);
void bsp_initialize(void);
void bsp_post_initialize(void);

#endif
