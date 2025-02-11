/**
 * @brief usb_device 驱动代码
 * @author WeiXuan <2020302121154@whu.edu.cn>
 * @file usb_device.h
 * @addtogroup USB
 * @signature: 热爱漫无边际，生活自有分寸
 */

#ifndef __USB_DEVICE__H__
#define __USB_DEVICE__H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32h7xx.h"
#include "stm32h7xx_hal.h"
#include "usbd_def.h"

/**
 * @author WeiXuan
 * @brief USB 底层初始化 
 * @returns 
 */
void MX_USB_DEVICE_Init(void);

#ifdef __cplusplus
}
#endif

#endif
