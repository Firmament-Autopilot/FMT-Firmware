#ifndef __HAL_USB_OTG_H__
#define __HAL_USB_OTG_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hal_ret_type.h"


typedef enum
{
    HAL_USB_PORT_0 = 0,
    HAL_USB_PORT_1,
    HAL_USB_PORT_NUM,
} ENUM_HAL_USB_PORT;


typedef enum
{
    HAL_USB_DR_MODE_DEVICE  = 0,
    HAL_USB_DR_MODE_HOST    = 1,
    HAL_USB_DR_MODE_OTG     = 2,
} ENUM_HAL_USB_DR_MODE;

typedef enum
{
    ENUM_USB_DEVICE_UNKNOWN      = 0x00,
    ENUM_USB_ANDROID_DEVICE      = 0x01,
    ENUM_USB_APPLE_DEVICE        = 0x02,
    ENUM_USB_ANDROID_HOST        = 0x03,
} ENUM_USB_OTG_IDTENTITY;

typedef enum
{
    ENUM_USB_DEVICE_UNKNOWN_ERROR     = 0x00,
    ENUM_USB_DEVICE_UN_SUPPORTED      = 0x01,
    ENUM_USB_DEVICE_NO_RESPONSE       = 0x02,
    ENUM_USB_HUB_UN_SUPPORTED         = 0x03,

} ENUM_USBH_ERR_MSG_TYPE;



/**
* @brief    initiate the USB Port
* @param  void
* @retval   void
* @note  
*/
void HAL_USB_Init(ENUM_HAL_USB_PORT e_usbPort, ENUM_HAL_USB_DR_MODE e_usbDrMode);

/**
* @brief    Configure the parameters optimized by IC Designer
* @param  void
* @retval   void
* @note  
*/
void HAL_USB_ConfigPHY(void);

HAL_RET_T HAL_USB_SendCtrl(uint8_t *buff, uint32_t u32_len, uint8_t u8_portId);

uint8_t HAL_USB_Get_ID_State(ENUM_HAL_USB_PORT e_usbPort);

void HAL_USB_ConfigHighImpedance(ENUM_HAL_USB_PORT e_usbPort);

ENUM_HAL_USB_DR_MODE HAL_USB_Get_USB_DR_Mode(ENUM_HAL_USB_PORT e_usbPort);

HAL_RET_T HAL_USB_GetConnState(uint8_t u8_usbPortId);

#ifdef __cplusplus
}
#endif  

#endif

