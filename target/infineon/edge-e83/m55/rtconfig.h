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
#define KIT_PROCE84_EVK_M55

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

/* Device virtual file system */
#define RT_USING_DFS
#define DFS_USING_WORKDIR
#define DFS_FILESYSTEMS_MAX 2
#define DFS_FILESYSTEM_TYPES_MAX 2
#define DFS_FD_MAX             16
#define RT_USING_DFS_ELMFAT
#define RT_USING_DFS_DEVFS
#define RT_USING_DFS_ROMFS

/* FatFs */
#define RT_DFS_ELM_CODE_PAGE            437
#define RT_DFS_ELM_WORD_ACCESS
#define RT_DFS_ELM_USE_LFN_3
#define RT_DFS_ELM_USE_LFN              3
#define RT_DFS_ELM_LFN_UNICODE_0
#define RT_DFS_ELM_LFN_UNICODE          0
#define RT_DFS_ELM_MAX_LFN             255
#define RT_DFS_ELM_DRIVES               2
#define RT_DFS_ELM_MAX_SECTOR_SIZE    512
#define RT_DFS_ELM_REENTRANT

/* Device Drivers */
#define RT_USING_DEVICE_IPC
#define RT_PIPE_BUFSZ           512
#define RT_SERIAL_RB_BUFSZ      128
#define RT_USING_MTD_NOR
#define FMT_USING_MAVLINK_V2

/* POSIX layer and C standard library */
#define RT_USING_LIBC

/*============================================================================
 * Network
 *============================================================================*/

/* Socket abstraction layer */
#define RT_USING_SAL
#define SAL_INTERNET_CHECK
#define SAL_USING_LWIP
#define SAL_SOCKETS_NUM         16

/* Network interface device */
#define RT_USING_NETDEV
#define NETDEV_USING_IFCONFIG
#define NETDEV_USING_PING
#define NETDEV_USING_NETSTAT
#define NETDEV_USING_AUTO_DEFAULT
#define NETDEV_IPV4             1
#define NETDEV_IPV6             0

/* LwIP */
#define RT_USING_LWIP
#define RT_USING_LWIP212
#define BSP_USING_ETH
#define RT_LWIP_MEM_ALIGNMENT   4

#define RT_LWIP_IGMP
#define RT_LWIP_ICMP
#define RT_LWIP_DNS
#define RT_LWIP_DHCP

#define IP_SOF_BROADCAST        1
#define IP_SOF_BROADCAST_RECV   1

/* Static IPv4 Address */
#define RT_LWIP_IPADDR          "192.168.1.30"
#define RT_LWIP_GWADDR          "192.168.1.1"
#define RT_LWIP_MSKADDR         "255.255.255.0"

/* LwIP Protocols */
#define RT_LWIP_UDP
#define RT_LWIP_TCP
#define RT_LWIP_RAW

/* LwIP Memory */
#define RT_MEMP_NUM_NETCONN     8
#define RT_LWIP_PBUF_NUM       16
#define RT_LWIP_RAW_PCB_NUM    4
#define RT_LWIP_UDP_PCB_NUM     4
#define RT_LWIP_TCP_PCB_NUM    4
#define RT_LWIP_TCP_SEG_NUM   40
#define RT_LWIP_TCP_SND_BUF  8196
#define RT_LWIP_TCP_WND      8196

/* LwIP Thread */
#define RT_LWIP_TCPTHREAD_PRIORITY      10
#define RT_LWIP_TCPTHREAD_MBOX_SIZE      8
#define RT_LWIP_TCPTHREAD_STACKSIZE   2048

#define RT_LWIP_ETHTHREAD_PRIORITY      12
#define RT_LWIP_ETHTHREAD_STACKSIZE   1024
#define RT_LWIP_ETHTHREAD_MBOX_SIZE      8

/* LwIP Options */
#define LWIP_NETIF_STATUS_CALLBACK  1
#define LWIP_NETIF_LINK_CALLBACK    1
#define SO_REUSE                   1
#define LWIP_SO_RCVTIMEO           1
#define LWIP_SO_SNDTIMEO           1
#define LWIP_SO_RCVBUF             1
#define LWIP_SO_LINGER             0
#define LWIP_NETIF_LOOPBACK        0
#define RT_LWIP_USING_PING
#define LWIP_NO_TX_THREAD

/*============================================================================
 * Hardware Drivers Config
 *============================================================================*/

/* Onboard Peripheral Drivers */

/* On-chip Peripheral Drivers */
#define BSP_USING_CMSIS_DSP
#define BSP_USING_GPIO
#define BSP_USING_UART
#define BSP_USING_UART4
// #define BSP_USING_UART5
// #define BSP_USING_UART5_DMA_TX
#define BSP_USING_SPI
#define BSP_USING_SPI3
#define BSP_USING_SPI8
#define BSP_USING_HW_I2C
#define BSP_USING_HW_I2C0
#define BSP_USING_PWM
#define BSP_USING_PWM5
#define BSP_USING_SDCARD
#define BSP_USING_USB
#define BSP_USING_IPC

/*============================================================================
 * Packages
 *============================================================================*/
#define PKG_USING_CHERRYUSB
#define PKG_CHERRYUSB_DEVICE
#define PKG_CHERRYUSB_DEVICE_SPEED_HS
#define PKG_CHERRYUSB_DEVICE_DWC2_INFINEON
#define PKG_CHERRYUSB_DEVICE_CDC_ACM

#define PKG_USING_RT_VSNPRINTF_FULL
#define PKG_VSNPRINTF_SUPPORT_DECIMAL_SPECIFIERS
#define PKG_VSNPRINTF_SUPPORT_EXPONENTIAL_SPECIFIERS
#define PKG_VSNPRINTF_SUPPORT_WRITEBACK_SPECIFIER
#define PKG_VSNPRINTF_SUPPORT_LONG_LONG
#define PKG_VSNPRINTF_CHECK_FOR_NUL_IN_FORMAT_SPECIFIER
#define PKG_VSNPRINTF_INTEGER_BUFFER_SIZE 32
#define PKG_VSNPRINTF_DECIMAL_BUFFER_SIZE 32
#define PKG_VSNPRINTF_DEFAULT_FLOAT_PRECISION 6
#define PKG_VSNPRINTF_MAX_INTEGRAL_DIGITS_FOR_DECIMAL 9
#define PKG_VSNPRINTF_LOG10_TAYLOR_TERMS 4
#define PKG_USING_RT_VSNPRINTF_FULL_LATEST_VERSION
#define RT_VSNPRINTF_FULL_REPLACING_VSNPRINTF
#define RT_VSNPRINTF_FULL_REPLACING_VSPRINTF

#endif /* __RTTHREAD_CFG_H__ */
