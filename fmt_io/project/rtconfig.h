/* RT-Thread config file */
#ifndef __RTTHREAD_CFG_H__
#define __RTTHREAD_CFG_H__

#define RT_USING_LIBC
#define RT_USING_NEWLIB

// <bool name="RT_USING_CMSIS_OS" description="Using CMSIS OS API" default="true" />
// #define RT_USING_CMSIS_OS
// <bool name="RT_USING_RTT_CMSIS" description="Using CMSIS in RTT" default="true" />
// #define RT_USING_RTT_CMSIS
// <bool name="RT_USING_BSP_CMSIS" description="Using CMSIS in BSP" default="true" />
#define RT_USING_BSP_CMSIS

#endif
