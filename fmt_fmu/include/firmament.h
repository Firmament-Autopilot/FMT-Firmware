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

#ifndef __FIRMAMENT_H__
#define __FIRMAMENT_H__

/* Standard C Library */
#include <stdio.h>
#include <stdlib.h>
/* stm32 peripheral library */
#include "stm32f4xx.h"
/* FPU Library */
#include <arm_math.h>
/* RT-Thread */
#include <rtdevice.h>
#include <rthw.h>
#include <rtthread.h>
/* System */
#include <board_device.h>
#include <fmt_def.h>
#include <fmtconfig.h>
#include <module/module_common.h>

/* Thread Prority */
#define VEHICLE_THREAD_PRIORITY    3
#define FMTIO_THREAD_PRIORITY      9
#define LOGGER_THREAD_PRIORITY     10
#define MAVLINK_RX_THREAD_PRIORITY 11
#define COMM_THREAD_PRIORITY       12
#define STATUS_THREAD_PRIORITY     13

// Macro to define packed structures
#ifdef __GNUC__
#define __PACKED__(__Declaration__) __Declaration__ __attribute__((packed))
#else
#define __PACKED__(__Declaration__) __pragma(pack(push, 1)) __Declaration__ __pragma(pack(pop))
#endif

// //extern const float PI;
#ifndef PI
#define PI 3.14159265358979f
#endif

// #define TIME_GAP(t1,t2)		(((t2)>=(t1))?((t2)-(t1)):(0xFFFFFFFF-(t1)+(t2)))
// #define IN_RANGE(v,l,r)		( (v)>(l) && (v)<(r) )

#define OS_ENTER_CRITICAL rt_enter_critical()
#define OS_EXIT_CRITICAL  rt_exit_critical()
#define OS_MALLOC(size)   rt_malloc(size)
#define OS_FREE(ptr)      rt_free(ptr)

#define FMT_CHECK(func) RT_ASSERT(func == FMT_EOK)

#endif
