/**
  ******************************************************************************
  * @file    py32e407_hal_usbd_ex.h
  * @author  MCU Application Team
  * @brief   Header file of USBDEV HAL Extension module.
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
#ifndef PY32E407_HAL_USBDEV_EX_H
#define PY32E407_HAL_USBDEV_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup USBDEVEx
  * @{
  */
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup USBDEVEx_Exported_Functions USBDEVEx Exported Functions
  * @{
  */
/** @addtogroup USBDEVEx_Exported_Functions_Group1 Peripheral Control functions
  * @{
  */

#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
HAL_StatusTypeDef HAL_USBDEVEx_SetTxFiFo(USBDEV_HandleTypeDef *husbd, uint8_t fifo, uint16_t size);
HAL_StatusTypeDef HAL_USBDEVEx_SetRxFiFo(USBDEV_HandleTypeDef *husbd, uint16_t size);
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */

void HAL_USBDEVEx_LPM_Callback(USBDEV_HandleTypeDef *husbd, USBDEV_LPM_MsgTypeDef msg);
void HAL_USBDEVEx_BCD_Callback(USBDEV_HandleTypeDef *husbd, USBDEV_BCD_MsgTypeDef msg);

/**
  * @}
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


#endif /* PY32E407_HAL_USBDEV_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
