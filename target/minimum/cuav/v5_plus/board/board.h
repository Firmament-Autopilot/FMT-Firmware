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

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

// Board Information
#define TARGET_NAME  "CUAV V5+"

// Internal SRAM memory size[Kbytes]
#define SYSTEM_TOTAL_MEM_SIZE (0x80000) // 512K
// Internal Free SRAM memory used by kernel (e.g, rt_malloc)
#ifdef __ICCARM__
// Use *.icf ram symbal, to avoid hardcode.
extern char __ICFEDIT_region_RAM_end__;
    #define SYSTEM_FREE_MEM_END &__ICFEDIT_region_RAM_end__
#elif defined(__CC_ARM) || defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
/* the size of heap is defined in startup.s, the address can be found in .map file */
extern int __heap_base;
extern int __heap_limit;
    #define SYSTEM_FREE_MEM_BEGIN (&__heap_base)
    #define SYSTEM_FREE_MEM_END   (&__heap_limit)
#else
extern int __bss_end;
    #define SYSTEM_FREE_MEM_BEGIN (&__bss_end)
    #define SYSTEM_FREE_MEM_END   (0x20000000 + SYSTEM_TOTAL_MEM_SIZE)
#endif

#ifndef NVIC_PRIORITYGROUP_0
    #define NVIC_PRIORITYGROUP_0 ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority, \
                                                             4 bits for subpriority */
    #define NVIC_PRIORITYGROUP_1 ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority, \
                                                             3 bits for subpriority */
    #define NVIC_PRIORITYGROUP_2 ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority, \
                                                             2 bits for subpriority */
    #define NVIC_PRIORITYGROUP_3 ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority, \
                                                             1 bit  for subpriority */
    #define NVIC_PRIORITYGROUP_4 ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority, \
                                                             0 bit  for subpriority */
#endif

void rt_hw_board_init(void);
void bsp_early_initialize(void);
void bsp_initialize(void);
void bsp_post_initialize(void);
void board_show_version(void);

void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif
