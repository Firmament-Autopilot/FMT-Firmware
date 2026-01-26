/**
  ******************************************************************************
  * @file    py32e407_hal_usbh.h
  * @author  MCU Application Team
  * @brief   Header file of USBHOST HAL module.
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
#ifndef PY32E407_HAL_USBHOST_H
#define PY32E407_HAL_USBHOST_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_ll_usb.h"

#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup USBHOST
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup USBHOST_Exported_Types USBHOST Exported Types
  * @{
  */

/** @defgroup USBHOST_Exported_Types_Group1 USBHOST State Structure definition
  * @{
  */
typedef enum
{
  HAL_USBHOST_STATE_RESET    = 0x00,
  HAL_USBHOST_STATE_READY    = 0x01,
  HAL_USBHOST_STATE_ERROR    = 0x02,
  HAL_USBHOST_STATE_BUSY     = 0x03,
  HAL_USBHOST_STATE_TIMEOUT  = 0x04
} USBHOST_StateTypeDef;

typedef USB_OTG_GlobalTypeDef   USBHOST_TypeDef;
typedef USB_OTG_CfgTypeDef      USBHOST_InitTypeDef;
typedef USB_OTG_HCTypeDef       USBHOST_HCTypeDef;
typedef USB_OTG_URBStateTypeDef USBHOST_URBStateTypeDef;
typedef USB_OTG_HCStateTypeDef  USBHOST_HCStateTypeDef;
/**
  * @}
  */

/** @defgroup USBHOST_Exported_Types_Group2 USBHOST Handle Structure definition
  * @{
  */
#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
typedef struct __USBHOST_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */
{
  USBHOST_TypeDef               *Instance;  /*!< Register base address        */

  USBHOST_InitTypeDef           Init;       /*!< USBHOST required parameters  */

  USBHOST_HCTypeDef             hc[16];     /*!< Host channels parameters     */

  HAL_LockTypeDef               Lock;       /*!< USBHOST peripheral status    */

  __IO USBHOST_StateTypeDef     State;      /*!< USBHOST communication state  */

  __IO  uint32_t                ErrorCode;  /*!< USBHOST Error code           */

  void                          *pData;     /*!< Pointer Stack Handler        */

#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
  void (* SOFCallback)(struct __USBHOST_HandleTypeDef *husbh);                               /*!< USB OTG USBHOST SOF callback                */
  void (* ConnectCallback)(struct __USBHOST_HandleTypeDef *husbh);                           /*!< USB OTG USBHOST Connect callback            */
  void (* DisconnectCallback)(struct __USBHOST_HandleTypeDef *husbh);                        /*!< USB OTG USBHOST Disconnect callback         */
  void (* PortEnabledCallback)(struct __USBHOST_HandleTypeDef *husbh);                       /*!< USB OTG USBHOST Port Enable callback        */
  void (* PortDisabledCallback)(struct __USBHOST_HandleTypeDef *husbh);                      /*!< USB OTG USBHOST Port Disable callback       */
  void (* HC_NotifyURBChangeCallback)(struct __USBHOST_HandleTypeDef *husbh, uint8_t chnum,
                                      USBHOST_URBStateTypeDef urb_state);                   /*!< USB OTG USBHOST Host Channel Notify URB Change callback  */

  void (* MspInitCallback)(struct __USBHOST_HandleTypeDef *husbh);                           /*!< USB OTG USBHOST Msp Init callback           */
  void (* MspDeInitCallback)(struct __USBHOST_HandleTypeDef *husbh);                         /*!< USB OTG USBHOST Msp DeInit callback         */
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */

} USBHOST_HandleTypeDef;
/**
  * @}
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup USBHOST_Exported_Constants USBHOST Exported Constants
  * @{
  */

/** @defgroup USBHOST_Speed USBHOST Speed
  * @{
  */
#define USBHOST_SPEED_FULL               USBH_FS_SPEED
#define USBHOST_SPEED_LOW                USBH_LS_SPEED

/**
  * @}
  */

/** @defgroup USBHOST_PHY_Module USBHOST PHY Module
  * @{
  */
#define USBHOST_PHY_EMBEDDED             2U
/**
  * @}
  */

/** @defgroup USBHOST_Error_Code_definition USBHOST Error Code definition
  * @brief  USBHOST Error Code definition
  * @{
  */
#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
#define  HAL_USBHOST_ERROR_INVALID_CALLBACK                        (0x00000010U)    /*!< Invalid Callback error  */
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup USBHOST_Exported_Macros USBHOST Exported Macros
 *  @brief macros to handle interrupts and specific clock configurations
 * @{
 */
#define __HAL_USBHOST_ENABLE(__HANDLE__)                       (void)USB_EnableGlobalInt ((__HANDLE__)->Instance)
#define __HAL_USBHOST_DISABLE(__HANDLE__)                      (void)USB_DisableGlobalInt ((__HANDLE__)->Instance)

#define __HAL_USBHOST_GET_FLAG(__HANDLE__, __INTERRUPT__)      ((USB_ReadInterrupts((__HANDLE__)->Instance) & (__INTERRUPT__)) == (__INTERRUPT__))
#define __HAL_USBHOST_CLEAR_FLAG(__HANDLE__, __INTERRUPT__)    (((__HANDLE__)->Instance->GINTSTS) = (__INTERRUPT__))
#define __HAL_USBHOST_IS_INVALID_INTERRUPT(__HANDLE__)         (USB_ReadInterrupts((__HANDLE__)->Instance) == 0U)

#define __HAL_USBHOST_CLEAR_HC_INT(chnum, __INTERRUPT__)       (USBx_HC(chnum)->HCINT = (__INTERRUPT__))
#define __HAL_USBHOST_MASK_HALT_HC_INT(chnum)                  (USBx_HC(chnum)->HCINTMSK &= ~USB_OTG_HCINTMSK_CHHM)
#define __HAL_USBHOST_UNMASK_HALT_HC_INT(chnum)                (USBx_HC(chnum)->HCINTMSK |= USB_OTG_HCINTMSK_CHHM)
#define __HAL_USBHOST_MASK_ACK_HC_INT(chnum)                   (USBx_HC(chnum)->HCINTMSK &= ~USB_OTG_HCINTMSK_ACKM)
#define __HAL_USBHOST_UNMASK_ACK_HC_INT(chnum)                 (USBx_HC(chnum)->HCINTMSK |= USB_OTG_HCINTMSK_ACKM)
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup USBHOST_Exported_Functions USBHOST Exported Functions
  * @{
  */

/** @defgroup USBHOST_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */
HAL_StatusTypeDef      HAL_USBHOST_Init(USBHOST_HandleTypeDef *husbh);
HAL_StatusTypeDef      HAL_USBHOST_DeInit(USBHOST_HandleTypeDef *husbh);
HAL_StatusTypeDef      HAL_USBHOST_HC_Init(USBHOST_HandleTypeDef *husbh,
                                           uint8_t ch_num,
                                           uint8_t epnum,
                                           uint8_t dev_address,
                                           uint8_t speed,
                                           uint8_t ep_type,
                                           uint16_t mps);

HAL_StatusTypeDef     HAL_USBHOST_HC_Halt(USBHOST_HandleTypeDef *husbh, uint8_t ch_num);
void                  HAL_USBHOST_MspInit(USBHOST_HandleTypeDef *husbh);
void                  HAL_USBHOST_MspDeInit(USBHOST_HandleTypeDef *husbh);

#if (USE_HAL_USBHOST_REGISTER_CALLBACKS == 1U)
/** @defgroup HAL_USBHOST_Callback_ID_enumeration_definition HAL USB OTG USBHOST Callback ID enumeration definition
  * @brief  HAL USB OTG USBHOST Callback ID enumeration definition
  * @{
  */
typedef enum
{
  HAL_USBHOST_SOF_CB_ID            = 0x01,       /*!< USB USBHOST SOF callback ID           */
  HAL_USBHOST_CONNECT_CB_ID        = 0x02,       /*!< USB USBHOST Connect callback ID       */
  HAL_USBHOST_DISCONNECT_CB_ID     = 0x03,       /*!< USB USBHOST Disconnect callback ID    */
  HAL_USBHOST_PORT_ENABLED_CB_ID   = 0x04,       /*!< USB USBHOST Port Enable callback ID   */
  HAL_USBHOST_PORT_DISABLED_CB_ID  = 0x05,       /*!< USB USBHOST Port Disable callback ID  */
  HAL_USBHOST_MSPINIT_CB_ID        = 0x06,       /*!< USB USBHOST MspInit callback ID       */
  HAL_USBHOST_MSPDEINIT_CB_ID      = 0x07        /*!< USB USBHOST MspDeInit callback ID     */

} HAL_USBHOST_CallbackIDTypeDef;
/**
  * @}
  */

/** @defgroup HAL_USBHOST_Callback_pointer_definition HAL USB OTG USBHOST Callback pointer definition
  * @brief  HAL USB OTG USBHOST Callback pointer definition
  * @{
  */

typedef void (*pUSBHOST_CallbackTypeDef)(USBHOST_HandleTypeDef *husbh);                   /*!< pointer to a common USB OTG USBHOST callback function  */
typedef void (*pUSBHOST_HC_NotifyURBChangeCallbackTypeDef)(USBHOST_HandleTypeDef *husbh,
                                                           uint8_t epnum,
                                                           USBHOST_URBStateTypeDef urb_state);   /*!< pointer to USB OTG USBHOST host channel  callback */
/**
  * @}
  */

HAL_StatusTypeDef HAL_USBHOST_RegisterCallback(USBHOST_HandleTypeDef *husbh, HAL_USBHOST_CallbackIDTypeDef CallbackID, pUSBHOST_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_USBHOST_UnRegisterCallback(USBHOST_HandleTypeDef *husbh, HAL_USBHOST_CallbackIDTypeDef CallbackID);

HAL_StatusTypeDef HAL_USBHOST_RegisterHC_NotifyURBChangeCallback(USBHOST_HandleTypeDef *husbh, pUSBHOST_HC_NotifyURBChangeCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_USBHOST_UnRegisterHC_NotifyURBChangeCallback(USBHOST_HandleTypeDef *husbh);
#endif /* USE_HAL_USBHOST_REGISTER_CALLBACKS */
/**
  * @}
  */

/* I/O operation functions  ***************************************************/
/** @addtogroup USBHOST_Exported_Functions_Group2 Input and Output operation functions
  * @{
  */
HAL_StatusTypeDef       HAL_USBHOST_HC_SubmitRequest(USBHOST_HandleTypeDef *husbh,
                                                     uint8_t ch_num,
                                                     uint8_t direction,
                                                     uint8_t ep_type,
                                                     uint8_t token,
                                                     uint8_t *pbuff,
                                                     uint16_t length,
                                                     uint8_t do_ping);

/* Non-Blocking mode: Interrupt */
void             HAL_USBHOST_IRQHandler(USBHOST_HandleTypeDef *husbh);
void             HAL_USBHOST_SOF_Callback(USBHOST_HandleTypeDef *husbh);
void             HAL_USBHOST_Connect_Callback(USBHOST_HandleTypeDef *husbh);
void             HAL_USBHOST_Disconnect_Callback(USBHOST_HandleTypeDef *husbh);
void             HAL_USBHOST_PortEnabled_Callback(USBHOST_HandleTypeDef *husbh);
void             HAL_USBHOST_PortDisabled_Callback(USBHOST_HandleTypeDef *husbh);
void             HAL_USBHOST_HC_NotifyURBChange_Callback(USBHOST_HandleTypeDef *husbh,
                                                         uint8_t chnum,
                                                         USBHOST_URBStateTypeDef urb_state);
/**
  * @}
  */

/* Peripheral Control functions  **********************************************/
/** @addtogroup USBHOST_Exported_Functions_Group3 Peripheral Control functions
  * @{
  */
HAL_StatusTypeDef       HAL_USBHOST_ResetPort(USBHOST_HandleTypeDef *husbh);
HAL_StatusTypeDef       HAL_USBHOST_Start(USBHOST_HandleTypeDef *husbh);
HAL_StatusTypeDef       HAL_USBHOST_Stop(USBHOST_HandleTypeDef *husbh);
/**
  * @}
  */

/* Peripheral State functions  ************************************************/
/** @addtogroup USBHOST_Exported_Functions_Group4 Peripheral State functions
  * @{
  */
USBHOST_StateTypeDef        HAL_USBHOST_GetState(USBHOST_HandleTypeDef *husbh);
USBHOST_URBStateTypeDef     HAL_USBHOST_HC_GetURBState(USBHOST_HandleTypeDef *husbh, uint8_t chnum);
uint32_t                    HAL_USBHOST_HC_GetXferCount(USBHOST_HandleTypeDef *husbh, uint8_t chnum);
USBHOST_HCStateTypeDef      HAL_USBHOST_HC_GetState(USBHOST_HandleTypeDef *husbh, uint8_t chnum);
uint32_t                    HAL_USBHOST_GetCurrentFrame(USBHOST_HandleTypeDef *husbh);
uint32_t                    HAL_USBHOST_GetCurrentSpeed(USBHOST_HandleTypeDef *husbh);
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup USBHOST_Private_Macros USBHOST Private Macros
 * @{
 */

/**
  * @}
  */

/* Private functions prototypes ----------------------------------------------*/
/** @defgroup USBHOST_Private_Functions_Prototypes USBHOST Private Functions Prototypes
  * @{
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup USBHOST_Private_Functions USBHOST Private Functions
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

#endif /* PY32E407_HAL_USBHOST_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
