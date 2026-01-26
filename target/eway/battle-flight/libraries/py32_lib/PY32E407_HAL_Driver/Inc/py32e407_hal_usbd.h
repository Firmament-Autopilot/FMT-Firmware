/**
  ******************************************************************************
  * @file    py32e407_hal_usbd.h
  * @author  MCU Application Team
  * @brief   Header file of USBDEV HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by Puya under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PY32E407_HAL_USBDEV_H
#define PY32E407_HAL_USBDEV_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_ll_usb.h"

#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup USBDEV
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup USBDEV_Exported_Types USBDEV Exported Types
  * @{
  */

/**
  * @brief  USBDEV State structure definition
  */
typedef enum
{
  HAL_USBDEV_STATE_RESET   = 0x00,
  HAL_USBDEV_STATE_READY   = 0x01,
  HAL_USBDEV_STATE_ERROR   = 0x02,
  HAL_USBDEV_STATE_BUSY    = 0x03,
  HAL_USBDEV_STATE_TIMEOUT = 0x04
} USBDEV_StateTypeDef;

/* Device LPM suspend state */
typedef enum
{
  LPM_L0 = 0x00, /* on */
  LPM_L1 = 0x01, /* LPM L1 sleep */
  LPM_L2 = 0x02, /* suspend */
  LPM_L3 = 0x03, /* off */
} USBDEV_LPM_StateTypeDef;

typedef enum
{
  USBDEV_LPM_L0_ACTIVE = 0x00, /* on */
  USBDEV_LPM_L1_ACTIVE = 0x01, /* LPM L1 sleep */
} USBDEV_LPM_MsgTypeDef;

typedef enum
{
  USBDEV_BCD_ERROR                     = 0xFF,
  USBDEV_BCD_CONTACT_DETECTION         = 0xFE,
  USBDEV_BCD_STD_DOWNSTREAM_PORT       = 0xFD,
  USBDEV_BCD_CHARGING_DOWNSTREAM_PORT  = 0xFC,
  USBDEV_BCD_DEDICATED_CHARGING_PORT   = 0xFB,
  USBDEV_BCD_DISCOVERY_COMPLETED       = 0x00,

} USBDEV_BCD_MsgTypeDef;

#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
typedef USB_OTG_GlobalTypeDef  USBDEV_TypeDef;
typedef USB_OTG_CfgTypeDef     USBDEV_InitTypeDef;
typedef USB_OTG_EPTypeDef      USBDEV_EPTypeDef;
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */

/**
  * @brief  USBDEV Handle Structure definition
  */
#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
typedef struct __USBDEV_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */
{
  USBDEV_TypeDef             *Instance;                               /*!< Register base address          */
                            
  USBDEV_InitTypeDef         Init;                                    /*!< USBDEV required parameters     */
                              
  __IO uint8_t               USB_Address;                             /*!< USB Address                    */

#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
  USBDEV_EPTypeDef           IN_ep[16];                               /*!< IN endpoint parameters         */

  USBDEV_EPTypeDef           OUT_ep[16];                              /*!< OUT endpoint parameters        */
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */

  HAL_LockTypeDef            Lock;                                    /*!< USBDEV peripheral status       */

  __IO USBDEV_StateTypeDef   State;                                   /*!< USBDEV communication state     */
 
  __IO  uint32_t             ErrorCode;                               /*!< USBDEV Error code              */

  uint32_t                   Setup[12];                               /*!< Setup packet buffer            */

  USBDEV_LPM_StateTypeDef    LPM_State;                               /*!< LPM State                      */

  uint32_t                   BESL;

  void                      *pData;                                   /*!< Pointer to upper stack Handler */

#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
  void (* SOFCallback)(struct __USBDEV_HandleTypeDef *husbd);                              /*!< USB OTG USBDEV SOF callback                */
  void (* SetupStageCallback)(struct __USBDEV_HandleTypeDef *husbd);                       /*!< USB OTG USBDEV Setup Stage callback        */
  void (* ResetCallback)(struct __USBDEV_HandleTypeDef *husbd);                            /*!< USB OTG USBDEV Reset callback              */
  void (* SuspendCallback)(struct __USBDEV_HandleTypeDef *husbd);                          /*!< USB OTG USBDEV Suspend callback            */
  void (* ResumeCallback)(struct __USBDEV_HandleTypeDef *husbd);                           /*!< USB OTG USBDEV Resume callback             */
  void (* ConnectCallback)(struct __USBDEV_HandleTypeDef *husbd);                          /*!< USB OTG USBDEV Connect callback            */
  void (* DisconnectCallback)(struct __USBDEV_HandleTypeDef *husbd);                       /*!< USB OTG USBDEV Disconnect callback         */

  void (* DataOutStageCallback)(struct __USBDEV_HandleTypeDef *husbd, uint8_t epnum);      /*!< USB OTG USBDEV Data OUT Stage callback     */
  void (* DataInStageCallback)(struct __USBDEV_HandleTypeDef *husbd, uint8_t epnum);       /*!< USB OTG USBDEV Data IN Stage callback      */
  void (* ISOOUTIncompleteCallback)(struct __USBDEV_HandleTypeDef *husbd, uint8_t epnum);  /*!< USB OTG USBDEV ISO OUT Incomplete callback */
  void (* ISOINIncompleteCallback)(struct __USBDEV_HandleTypeDef *husbd, uint8_t epnum);   /*!< USB OTG USBDEV ISO IN Incomplete callback  */

  void (* MspInitCallback)(struct __USBDEV_HandleTypeDef *husbd);                          /*!< USB OTG USBDEV Msp Init callback           */
  void (* MspDeInitCallback)(struct __USBDEV_HandleTypeDef *husbd);                        /*!< USB OTG USBDEV Msp DeInit callback         */
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */
} USBDEV_HandleTypeDef;

/**
  * @}
  */

/* Include USBDEV HAL Extended module */
#include "py32e407_hal_usbd_ex.h"

/* Exported constants --------------------------------------------------------*/
/** @defgroup USBDEV_Exported_Constants USBDEV Exported Constants
  * @{
  */

/** @defgroup USBDEV_Speed USBDEV Speed
  * @{
  */
#define USBDEV_SPEED_FULL               USBD_FS_SPEED
/**
  * @}
  */

/** @defgroup USBDEV_PHY_Module USBDEV PHY Module
  * @{
  */
#define USBDEV_PHY_EMBEDDED             2U
/**
  * @}
  */

/** @defgroup USBDEV_Error_Code_definition USBDEV Error Code definition
  * @brief  USBDEV Error Code definition
  * @{
  */
#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
#define  HAL_USBDEV_ERROR_INVALID_CALLBACK                        (0x00000010U)    /*!< Invalid Callback error  */
#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup USBDEV_Exported_Macros USBDEV Exported Macros
 *  @brief macros to handle interrupts and specific clock configurations
 * @{
 */
#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
#define __HAL_USBDEV_ENABLE(__HANDLE__)                       (void)USB_EnableGlobalInt ((__HANDLE__)->Instance)
#define __HAL_USBDEV_DISABLE(__HANDLE__)                      (void)USB_DisableGlobalInt ((__HANDLE__)->Instance)

#define __HAL_USBDEV_GET_FLAG(__HANDLE__, __INTERRUPT__)      ((USB_ReadInterrupts((__HANDLE__)->Instance) & (__INTERRUPT__)) == (__INTERRUPT__))
#define __HAL_USBDEV_CLEAR_FLAG(__HANDLE__, __INTERRUPT__)    (((__HANDLE__)->Instance->GINTSTS) &=  (__INTERRUPT__))
#define __HAL_USBDEV_IS_INVALID_INTERRUPT(__HANDLE__)         (USB_ReadInterrupts((__HANDLE__)->Instance) == 0U)


#define __HAL_USBDEV_UNGATE_PHYCLOCK(__HANDLE__)              *(__IO uint32_t *)((uint32_t)((__HANDLE__)->Instance) + USB_OTG_PCGCCTL_BASE) &= ~(USB_OTG_PCGCCTL_STPPCLK)

#define __HAL_USBDEV_GATE_PHYCLOCK(__HANDLE__)                *(__IO uint32_t *)((uint32_t)((__HANDLE__)->Instance) + USB_OTG_PCGCCTL_BASE) |= USB_OTG_PCGCCTL_STPPCLK

#define __HAL_USBDEV_IS_PHY_SUSPENDED(__HANDLE__)             ((*(__IO uint32_t *)((uint32_t)((__HANDLE__)->Instance) + USB_OTG_PCGCCTL_BASE)) & 0x10U)

#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */


/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup USBDEV_Exported_Functions USBDEV Exported Functions
  * @{
  */

/* Initialization/de-initialization functions  ********************************/
/** @addtogroup USBDEV_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */
HAL_StatusTypeDef HAL_USBDEV_Init(USBDEV_HandleTypeDef *husbd);
HAL_StatusTypeDef HAL_USBDEV_DeInit(USBDEV_HandleTypeDef *husbd);
void HAL_USBDEV_MspInit(USBDEV_HandleTypeDef *husbd);
void HAL_USBDEV_MspDeInit(USBDEV_HandleTypeDef *husbd);

#if (USE_HAL_USBDEV_REGISTER_CALLBACKS == 1U)
/** @defgroup HAL_USBDEV_Callback_ID_enumeration_definition HAL USB OTG USBDEV Callback ID enumeration definition
  * @brief  HAL USB OTG USBDEV Callback ID enumeration definition
  * @{
  */
typedef enum
{
  HAL_USBDEV_SOF_CB_ID          = 0x01,      /*!< USB USBDEV SOF callback ID          */
  HAL_USBDEV_SETUPSTAGE_CB_ID   = 0x02,      /*!< USB USBDEV Setup Stage callback ID  */
  HAL_USBDEV_RESET_CB_ID        = 0x03,      /*!< USB USBDEV Reset callback ID        */
  HAL_USBDEV_SUSPEND_CB_ID      = 0x04,      /*!< USB USBDEV Suspend callback ID      */
  HAL_USBDEV_RESUME_CB_ID       = 0x05,      /*!< USB USBDEV Resume callback ID       */
  HAL_USBDEV_CONNECT_CB_ID      = 0x06,      /*!< USB USBDEV Connect callback ID      */
  HAL_USBDEV_DISCONNECT_CB_ID  = 0x07,      /*!< USB USBDEV Disconnect callback ID   */

  HAL_USBDEV_MSPINIT_CB_ID      = 0x08,      /*!< USB USBDEV MspInit callback ID      */
  HAL_USBDEV_MSPDEINIT_CB_ID    = 0x09       /*!< USB USBDEV MspDeInit callback ID    */

} HAL_USBDEV_CallbackIDTypeDef;
/**
  * @}
  */

/** @defgroup HAL_USBDEV_Callback_pointer_definition HAL USB OTG USBDEV Callback pointer definition
  * @brief  HAL USB OTG USBDEV Callback pointer definition
  * @{
  */

typedef void (*pUSBDEV_CallbackTypeDef)(USBDEV_HandleTypeDef *husbd);                                   /*!< pointer to a common USB OTG USBDEV callback function  */
typedef void (*pUSBDEV_DataOutStageCallbackTypeDef)(USBDEV_HandleTypeDef *husbd, uint8_t epnum);        /*!< pointer to USB OTG USBDEV Data OUT Stage callback     */
typedef void (*pUSBDEV_DataInStageCallbackTypeDef)(USBDEV_HandleTypeDef *husbd, uint8_t epnum);         /*!< pointer to USB OTG USBDEV Data IN Stage callback      */
typedef void (*pUSBDEV_IsoOutIncpltCallbackTypeDef)(USBDEV_HandleTypeDef *husbd, uint8_t epnum);        /*!< pointer to USB OTG USBDEV ISO OUT Incomplete callback */
typedef void (*pUSBDEV_IsoInIncpltCallbackTypeDef)(USBDEV_HandleTypeDef *husbd, uint8_t epnum);         /*!< pointer to USB OTG USBDEV ISO IN Incomplete callback  */

/**
  * @}
  */

HAL_StatusTypeDef HAL_USBDEV_RegisterCallback(USBDEV_HandleTypeDef *husbd, HAL_USBDEV_CallbackIDTypeDef CallbackID, pUSBDEV_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_USBDEV_UnRegisterCallback(USBDEV_HandleTypeDef *husbd, HAL_USBDEV_CallbackIDTypeDef CallbackID);

HAL_StatusTypeDef HAL_USBDEV_RegisterDataOutStageCallback(USBDEV_HandleTypeDef *husbd, pUSBDEV_DataOutStageCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_USBDEV_UnRegisterDataOutStageCallback(USBDEV_HandleTypeDef *husbd);

HAL_StatusTypeDef HAL_USBDEV_RegisterDataInStageCallback(USBDEV_HandleTypeDef *husbd, pUSBDEV_DataInStageCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_USBDEV_UnRegisterDataInStageCallback(USBDEV_HandleTypeDef *husbd);

HAL_StatusTypeDef HAL_USBDEV_RegisterIsoOutIncpltCallback(USBDEV_HandleTypeDef *husbd, pUSBDEV_IsoOutIncpltCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_USBDEV_UnRegisterIsoOutIncpltCallback(USBDEV_HandleTypeDef *husbd);

HAL_StatusTypeDef HAL_USBDEV_RegisterIsoInIncpltCallback(USBDEV_HandleTypeDef *husbd, pUSBDEV_IsoInIncpltCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_USBDEV_UnRegisterIsoInIncpltCallback(USBDEV_HandleTypeDef *husbd);

#endif /* USE_HAL_USBDEV_REGISTER_CALLBACKS */
/**
  * @}
  */

/* I/O operation functions  ***************************************************/
/* Non-Blocking mode: Interrupt */
/** @addtogroup USBDEV_Exported_Functions_Group2 Input and Output operation functions
  * @{
  */
HAL_StatusTypeDef HAL_USBDEV_Start(USBDEV_HandleTypeDef *husbd);
HAL_StatusTypeDef HAL_USBDEV_Stop(USBDEV_HandleTypeDef *husbd);
void HAL_USBDEV_IRQHandler(USBDEV_HandleTypeDef *husbd);

void HAL_USBDEV_SOFCallback(USBDEV_HandleTypeDef *husbd);
void HAL_USBDEV_SetupStageCallback(USBDEV_HandleTypeDef *husbd);
void HAL_USBDEV_ResetCallback(USBDEV_HandleTypeDef *husbd);
void HAL_USBDEV_SuspendCallback(USBDEV_HandleTypeDef *husbd);
void HAL_USBDEV_ResumeCallback(USBDEV_HandleTypeDef *husbd);
void HAL_USBDEV_ConnectCallback(USBDEV_HandleTypeDef *husbd);
void HAL_USBDEV_DisconnectCallback(USBDEV_HandleTypeDef *husbd);

void HAL_USBDEV_DataOutStageCallback(USBDEV_HandleTypeDef *husbd, uint8_t epnum);
void HAL_USBDEV_DataInStageCallback(USBDEV_HandleTypeDef *husbd, uint8_t epnum);
void HAL_USBDEV_ISOOUTIncompleteCallback(USBDEV_HandleTypeDef *husbd, uint8_t epnum);
void HAL_USBDEV_ISOINIncompleteCallback(USBDEV_HandleTypeDef *husbd, uint8_t epnum);
/**
  * @}
  */

/* Peripheral Control functions  **********************************************/
/** @addtogroup USBDEV_Exported_Functions_Group3 Peripheral Control functions
  * @{
  */
HAL_StatusTypeDef HAL_USBDEV_DevConnect(USBDEV_HandleTypeDef *husbd);
HAL_StatusTypeDef HAL_USBDEV_DevDisconnect(USBDEV_HandleTypeDef *husbd);
HAL_StatusTypeDef HAL_USBDEV_SetAddress(USBDEV_HandleTypeDef *husbd, uint8_t address);
HAL_StatusTypeDef HAL_USBDEV_EP_Open(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr, uint16_t ep_mps, uint8_t ep_type);
HAL_StatusTypeDef HAL_USBDEV_EP_Close(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr);
HAL_StatusTypeDef HAL_USBDEV_EP_Receive(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr, uint8_t *pBuf, uint32_t len);
HAL_StatusTypeDef HAL_USBDEV_EP_Transmit(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr, uint8_t *pBuf, uint32_t len);
uint32_t          HAL_USBDEV_EP_GetRxCount(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr);
HAL_StatusTypeDef HAL_USBDEV_EP_SetStall(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr);
HAL_StatusTypeDef HAL_USBDEV_EP_ClrStall(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr);
HAL_StatusTypeDef HAL_USBDEV_EP_Flush(USBDEV_HandleTypeDef *husbd, uint8_t ep_addr);
HAL_StatusTypeDef HAL_USBDEV_ActivateRemoteWakeup(USBDEV_HandleTypeDef *husbd);
HAL_StatusTypeDef HAL_USBDEV_DeActivateRemoteWakeup(USBDEV_HandleTypeDef *husbd);
/**
  * @}
  */

/* Peripheral State functions  ************************************************/
/** @addtogroup USBDEV_Exported_Functions_Group4 Peripheral State functions
  * @{
  */
USBDEV_StateTypeDef HAL_USBDEV_GetState(USBDEV_HandleTypeDef *husbd);
/**
  * @}
  */

/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @defgroup USBDEV_Private_Macros USBDEV Private Macros
 * @{
 */


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */

#ifdef __cplusplus
}
#endif

#endif /* PY32E407_HAL_USBDEV_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
