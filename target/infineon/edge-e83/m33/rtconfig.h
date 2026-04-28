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

/* RT-Thread config file */
#ifndef __RTTHREAD_CFG_H__
#define __RTTHREAD_CFG_H__

/*============================================================================
 * FMT config file
 *============================================================================*/
#include <fmtconfig.h>

/*============================================================================
 * Target SoC and Board
 *============================================================================*/
#define SOC_SERIES_IFX_PSOCE84
#define KIT_PROCE84_EVK_M33

/*============================================================================
 * RT-Thread Kernel
 *============================================================================*/

/* RT_NAME_MAX */
#define RT_NAME_MAX              20

/* RT_ALIGN_SIZE */
#define RT_ALIGN_SIZE            4

/* PRIORITY_MAX */
#define RT_THREAD_PRIORITY_MAX   32

/* Tick per Second */
#define RT_TICK_PER_SECOND       1000

/*============================================================================
 * RT-Thread Debug
 *============================================================================*/
#define RT_DEBUG
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK

/* Idle thread stack size */
#define IDLE_THREAD_STACK_SIZE   1024

/*============================================================================
 * RT-Thread Timer
 *============================================================================*/
#define RT_USING_TIMER_SOFT
#define RT_TIMER_THREAD_PRIO     5
#define RT_TIMER_THREAD_STACK_SIZE    1024

/*============================================================================
 * RT-Thread IPC
 *============================================================================*/
#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE

/*============================================================================
 * RT-Thread Memory Management
 *============================================================================*/
#define RT_USING_MEMPOOL
#define RT_USING_HEAP
#define RT_USING_SMALL_MEM

/*============================================================================
 * RT-Thread Device System
 *============================================================================*/
#define RT_USING_DEVICE
#define RT_USING_DEVICE_IPC
#define RT_USING_SYSTEM_WORKQUEUE
#define RT_SYSTEM_WORKQUEUE_STACKSIZE    2048
#define RT_SYSTEM_WORKQUEUE_PRIORITY     23

/*============================================================================
 * RT-Thread Console
 *============================================================================*/
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE      256

/*============================================================================
 * RT-Thread FINSH (Shell)
 *============================================================================*/
#define RT_USING_FINSH
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES      5
#define FINSH_USING_SYMTAB
#define FINSH_USING_DESCRIPTION
#define FINSH_THREAD_PRIORITY   20
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_CMD_SIZE          80
#define FINSH_USING_MSH
#define FINSH_USING_MSH_DEFAULT
#define FINSH_ARG_MAX           20

/*============================================================================
 * RT-Thread Components
 *============================================================================*/

/* Device Drivers */
#define RT_USING_DEVICE_IPC
#define RT_PIPE_BUFSZ           512
#define RT_SERIAL_RB_BUFSZ      128
#define RT_USING_MTD_NOR
#define FMT_USING_MAVLINK_V2

/* POSIX layer and C standard library */
#define RT_USING_LIBC

/*============================================================================
 * Hardware Drivers Config
 *============================================================================*/

/* Onboard Peripheral Drivers */
#define SOC_Enable_CM55

/* On-chip Peripheral Drivers */
#define BSP_USING_GPIO
#define BSP_USING_UART
#define BSP_USING_UART2
#define BSP_USING_PWM
#define BSP_USING_ADC
#define BSP_USING_ADC0
#define BSP_USING_IPC
#define BSP_USING_RC

#endif /* __RTTHREAD_CFG_H__ */
