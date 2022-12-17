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

#ifndef FMT_BSP_H__
#define FMT_BSP_H__

#include "vexpress_a9.h"
#include <firmament.h>
#include <realview.h>

#ifdef __cplusplus
extern "C" {
#endif

// Board Information
#define TARGET_NAME  "QEMU vexpress-a9"

#if defined(__CC_ARM)
extern int Image$$RW_IRAM1$$ZI$$Limit;
#define SYSTEM_FREE_MEM_BEGIN ((void*)&Image$$RW_IRAM1$$ZI$$Limit)
#elif defined(__GNUC__)
extern int __bss_end;
#define SYSTEM_FREE_MEM_BEGIN ((void*)&__bss_end)
#endif

#define SYSTEM_TOTAL_MEM_SIZE (8 * 1024 * 1024)
#define SYSTEM_FREE_MEM_END   (void*)(SYSTEM_FREE_MEM_BEGIN + SYSTEM_TOTAL_MEM_SIZE)

void rt_hw_board_init(void);
void bsp_early_initialize(void);
void bsp_initialize(void);
void bsp_post_initialize(void);
void board_show_version(void);

#ifdef __cplusplus
}
#endif

#endif
