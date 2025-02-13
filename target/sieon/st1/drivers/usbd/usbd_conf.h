/**
 * @brief usbd_conf 驱动代码
 * @author WeiXuan <2020302121154@whu.edu.cn>
 * @file usbd_conf.h
 * @addtogroup USB
 * @signature: 热爱漫无边际，生活自有分寸
 */
#ifndef __USBD_CONF__H__
#define __USBD_CONF__H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stm32h7xx.h"
#include "stm32h7xx_hal.h"

/* USBD 复合设备 */
#define USE_USBD_COMPOSITE
#define USBD_CMPSIT_ACTIVATE_MSC     1
#define USBD_CMPSIT_ACTIVATE_CDC     1
#define USBD_COMPOSITE_USE_IAD       1
#define USE_USB_FS

/* USBD composite接口数量 */                                     
#define USBD_MAX_NUM_INTERFACES      3U
#define USBD_MAX_SUPPORTED_CLASS     2U

/* USBD Compound接口配置数量 */
#define USBD_MAX_NUM_CONFIGURATION   1U

/* USBD 字符描述符所用的内存空间大小 */
#define USBD_MAX_STR_DESC_SIZ        512U

/* USBD 是否使用USB库自带的打印信息 */
#define USBD_DEBUG_LEVEL             0U
#define USBD_LPM_ENABLED             1U

/* USBD 该设备是自供电还是由上位设备供电 */           
#define USBD_SELF_POWERED            1U

/* MSC Class Config 定义包大小为32KB,越大,速度越快 */
#define MSC_MEDIA_PACKET             5*1024	

#define DEVICE_FS 		0
#define DEVICE_HS 		1

#define USBD_malloc         malloc
#define USBD_free           free

/** Alias for memory set. */
#define USBD_memset         memset

/** Alias for memory copy. */
#define USBD_memcpy         memcpy

/** Alias for delay. */
#define USBD_Delay          HAL_Delay

#if (USBD_DEBUG_LEVEL > 0)
#define USBD_UsrLog(...)    printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_UsrLog(...)
#endif

#if (USBD_DEBUG_LEVEL > 1)

#define USBD_ErrLog(...)    printf("ERROR: ");\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_ErrLog(...)
#endif

#if (USBD_DEBUG_LEVEL > 2)
#define USBD_DbgLog(...)    printf("DEBUG : ");\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_DbgLog(...)
#endif


#ifdef __cplusplus
}
#endif

#endif