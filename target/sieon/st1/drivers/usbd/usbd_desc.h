/** 
 * @brief USBD COM 设备描述符
 * @author WeiXuan <2020302121154@whu.edu.cn
 * @file usbd_desc_com.h
 * @addtogroup USBD_desc
 * @signature: 热爱漫无边际，生活自有分寸
 */

#ifndef __USBD_DESC__C__
#define __USBD_DESC__C__

#ifdef __cplusplus
 extern "C" {
#endif

#include "usbd_def.h"

#define         DEVICE_ID1          (UID_BASE)
#define         DEVICE_ID2          (UID_BASE + 0x4)
#define         DEVICE_ID3          (UID_BASE + 0x8)

#define  USB_SIZ_STRING_SERIAL       0x1A

extern USBD_DescriptorsTypeDef USBD_Desc;

#ifdef __cplusplus
}
#endif

#endif

