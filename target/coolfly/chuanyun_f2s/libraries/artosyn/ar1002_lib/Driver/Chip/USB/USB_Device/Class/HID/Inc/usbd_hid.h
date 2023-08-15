/**
  ******************************************************************************
  * @file    usbd_hid.h
  * @author  MCD Application Team
  * @version V2.4.2
  * @date    11-December-2015
  * @brief   Header file for the usbd_hid_core.c file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_HID_H
#define __USB_HID_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include  "usbd_ioreq.h"

/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @{
  */
  
/** @defgroup USBD_HID
  * @brief This file is the Header file for usbd_hid.c
  * @{
  */ 


/** @defgroup USBD_HID_Exported_Defines
  * @{
  */ 
#define HID_EPIN_VIDEO_ADDR           0x86
#define HID_EPIN_VIDEO_SIZE           512

#define HID_EPOUT_VIDEO_ADDR          0x06
#define HID_EPOUT_VIDEO_SIZE          512

#define HID_EPIN_AUDIO_ADDR           0x85
#define HID_EPIN_AUDIO_SIZE           512

#define HID_EPIN_CTRL_ADDR            0x84
#define HID_EPIN_CTRL_SIZE            512

#define HID_EPOUT_CTRL_ADDR           0x01
#define HID_EPOUT_CTRL_SIZE           512

#define HID_CUSTOMER_OUT_ADDR         0x03
#define HID_CUSTOMER_OUT_SIZE         512

#define HID_CUSTOMER_IN_ADDR          0x83
#define HID_CUSTOMER_IN_SIZE          512

#define MFI_IN_ADDR                   0x82
#define MFI_IN_SIZE                   512

#define MFI_OUT_ADDR                  0x02
#define MFI_OUT_SIZE                  512

#define USB_HID_CONFIG_DESC_SIZ       130
#define USB_MFI_CONFIG_DESC_SIZ       0x9C

//#define USB_HID_CONFIG_DESC_SIZ       91
#define USB_HID_DESC_SIZ              9
#define HID_MOUSE_REPORT_DESC_SIZE    40

#define HID_DESCRIPTOR_TYPE           0x21
#define HID_REPORT_DESC               0x22

#define HID_HS_BINTERVAL              0x01
#define HID_FS_BINTERVAL              0x0A
#define HID_POLLING_INTERVAL          0x0A

#define HID_REQ_SET_PROTOCOL          0x0B
#define HID_REQ_GET_PROTOCOL          0x03

#define HID_REQ_SET_IDLE              0x0A
#define HID_REQ_GET_IDLE              0x02

#define HID_REQ_SET_REPORT            0x09
#define HID_REQ_GET_REPORT            0x01

#define MFI_STRING_INTERFACE          0x05
#define HID_COMM_STRING_INTERFACE     0x06
#define HID_VIDEO0_STRING_INTERFACE   0x07
#define HID_AUDIO_STRING_INTERFACE    0x08
#define HID_CUSTOMER_STRING_INTERFACE 0x09


/**
  * @}
  */ 


/** @defgroup USBD_CORE_Exported_TypesDefinitions
  * @{
  */
typedef enum
{
  HID_IDLE = 0,
  HID_BUSY,
}
HID_StateTypeDef; 


typedef enum
{
  HID_VIDEO = 0,
  HID_CTRL,
}
HID_DataTypeDef; 


typedef struct _USBD_HID_Itf
{
    void (* dataOut)(void *, uint8_t);
    void (* userInit)(void);
    void (* customerOut)(void *, uint32_t, uint8_t);
    void (* recvVideoStream)(void *, uint32_t, uint8_t);
}USBD_HID_ItfTypeDef;


typedef struct
{
  uint32_t             Protocol;   
  uint32_t             IdleState;  
  uint32_t             AltSetting;
  HID_StateTypeDef     state[7];
  uint16_t             size[7];
  uint8_t             *buffer[7];
}
USBD_HID_HandleTypeDef; 
/**
  * @}
  */ 


/** @defgroup USBD_CORE_Exported_Macros
  * @{
  */ 

/**
  * @}
  */ 

/** @defgroup USBD_CORE_Exported_Variables
  * @{
  */ 


extern USBD_ClassTypeDef  USBD_HID;
#define USBD_HID_CLASS    &USBD_HID
/**
  * @}
  */ 

/** @defgroup USB_CORE_Exported_Functions
  * @{
  */ 
uint8_t USBD_HID_SendReport (USBD_HandleTypeDef *pdev, 
                                 uint8_t *report,
                                 uint16_t len,
                                 uint8_t  ep_addr);

uint8_t USBD_HID_PortActive(USBD_HandleTypeDef  *pdev, uint8_t ep_addr);

uint32_t USBD_HID_GetPollingInterval (USBD_HandleTypeDef *pdev);
uint8_t USBD_HID_RegisterInterface(USBD_HandleTypeDef *pdev,
                             USBD_HID_ItfTypeDef *fops);

void USBD_HID_OpenVideoDisplay(USBD_HandleTypeDef *pdev);
void USBD_HID_CloseVideoDisplay(USBD_HandleTypeDef *pdev);

void USBD_HID_SetHostTypeGPIO(uint32_t u32_hostModeGpio);

/**
  * @}
  */ 

#ifdef __cplusplus
}
#endif

#endif  /* __USB_HID_H */
/**
  * @}
  */ 

/**
  * @}
  */ 
  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
