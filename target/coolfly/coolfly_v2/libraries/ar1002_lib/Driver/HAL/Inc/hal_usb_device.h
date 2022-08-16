/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_usb_device.h
Description: The external HAL APIs to use the SRAM.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/22
History: 
        0.0.1    2016/12/22    The initial version of hal_usb_device.h
*****************************************************************************/

#ifndef __HAL_USB_DEVICE_H__
#define __HAL_USB_DEVICE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "hal_ret_type.h"
#include "hal_usb_otg.h"



/**
* @brief  config the usb as device controller
* @param  e_usbPort         usb port number: 0 or 1
* @retval   void
* @note  
*/
void HAL_USB_InitDevice(ENUM_HAL_USB_PORT e_usbPort, uint8_t u8_DeviceMode);

/**
* @brief  reset the usb device controller for usb device hotplug
* @param  void * p         for sys event call-back
* @retval   void
* @note  
*/
void HAL_USB_ResetDevice(void * p);

/**
* @brief  send control data to the host
* @param  uint8_t    *buff                the buffer to send
*               uint32_t    u32_len          buffer length 
* @retval   void
* @note
*/
HAL_RET_T HAL_USB_DeviceSendCtrl(uint8_t *buff, uint32_t u32_len, uint8_t u8_portId);
HAL_RET_T HAL_USB_DeviceSendCtrl_From_Task(uint8_t *buff, uint32_t u32_len, uint8_t u8_portId);

/**
* @brief   register the user callback function to receive host data
* @param  void (*pUsrFunc)(void *)     user callback function
* @retval   void
* @note
*/
void HAL_USB_RegisterUserProcess(void (*pUsrFunc)(void *, uint8_t), void (*pInitFunc)(void));


HAL_RET_T HAL_USB_DeviceGetConnState(uint8_t u8_usbPortId);


/**
* @brief  open the video output to PC or PAD.
* @param  void
* @retval   void
* @note  
*/
void HAL_USB_OpenVideo(uint8_t u8_usbPortId);


/**
* @brief  close the video output to PC or PAD.
* @param  void
* @retval   void
* @note  
*/
void HAL_USB_CloseVideo(uint8_t u8_usbPortId);


/**
* @brief  register customer's receive data function
* @param  void (*customerRecv)(void *)
* @retval   void
* @note  
*/
void HAL_USB_RegisterCustomerRecvData(void (*customerRecv)(void *, uint32_t, uint8_t));


/**
* @brief  Customer call this function to send data to host
* @param  uint8_t *buff             customer's data buffer to send
*               uint32_t u32_len       the length of buffer
* @retval   void
* @note  
*/
HAL_RET_T HAL_USB_CustomerSendData(uint8_t *buff,
                                   uint32_t u32_len,
                                   uint8_t u8_portId);

HAL_RET_T HAL_USB_SendData(uint8_t *buff, uint32_t data_len, uint8_t portId, uint8_t ep);

void HAL_USB_RegisterEncoderBypassVideo(void (*VideoStreamRecv)(void *, uint32_t, uint8_t));

void HAL_USB_DeInitDevice(ENUM_HAL_USB_PORT e_usbPort);


#ifdef __cplusplus
}
#endif

#endif

