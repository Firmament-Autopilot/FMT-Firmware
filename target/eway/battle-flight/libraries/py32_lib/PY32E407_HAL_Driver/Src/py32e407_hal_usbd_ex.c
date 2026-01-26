/**
  ******************************************************************************
  * @file    py32e407_hal_usbd_ex.c
  * @author  MCU Application Team
  * @brief   USBDEV Extended HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the USB Peripheral Controller:
  *           + Extended features functions
  *
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

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx_hal.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup USBDEVEx USBDEVEx
  * @brief USBDEV Extended HAL module driver
  * @{
  */

#ifdef HAL_USBD_MODULE_ENABLED

#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @defgroup USBDEVEx_Exported_Functions USBDEVEx Exported Functions
  * @{
  */

/** @defgroup USBDEVEx_Exported_Functions_Group1 Peripheral Control functions
  * @brief    USBDEVEx control functions
 *
@verbatim
 ===============================================================================
                 ##### Extended features functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Update FIFO configuration

@endverbatim
  * @{
  */
#if defined (USB1_OTG_FS) || defined (USB2_OTG_FS)
/**
  * @brief  Set Tx FIFO
  * @param  husbd USBDEV handle
  * @param  fifo The number of Tx fifo
  * @param  size Fifo size
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEVEx_SetTxFiFo(USBDEV_HandleTypeDef *husbd, uint8_t fifo, uint16_t size)
{
  uint8_t i;
  uint32_t Tx_Offset;

  /*  TXn min size = 16 words. (n  : Transmit FIFO index)
      When a TxFIFO is not used, the Configuration should be as follows:
          case 1 :  n > m    and Txn is not used    (n,m  : Transmit FIFO indexes)
         --> Txm can use the space allocated for Txn.
         case2  :  n < m    and Txn is not used    (n,m  : Transmit FIFO indexes)
         --> Txn should be configured with the minimum space of 16 words
     The FIFO is used optimally when used TxFIFOs are allocated in the top
         of the FIFO.Ex: use EP1 and EP2 as IN instead of EP1 and EP3 as IN ones. */

  Tx_Offset = husbd->Instance->GRXFSIZ;

  if (fifo == 0U)
  {
    husbd->Instance->DIEPTXF0_HNPTXFSIZ = ((uint32_t)size << 16) | Tx_Offset;
  }
  else
  {
    Tx_Offset += (husbd->Instance->DIEPTXF0_HNPTXFSIZ) >> 16;
    for (i = 0U; i < (fifo - 1U); i++)
    {
      Tx_Offset += (husbd->Instance->DIEPTXF[i] >> 16);
    }

    /* Multiply Tx_Size by 2 to get higher performance */
    husbd->Instance->DIEPTXF[fifo - 1U] = ((uint32_t)size << 16) | Tx_Offset;
  }

  return HAL_OK;
}

/**
  * @brief  Set Rx FIFO
  * @param  husbd USBDEV handle
  * @param  size Size of Rx fifo
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USBDEVEx_SetRxFiFo(USBDEV_HandleTypeDef *husbd, uint16_t size)
{
  husbd->Instance->GRXFSIZ = size;

  return HAL_OK;
}
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */

/**
  * @brief  Send LPM message to user layer callback.
  * @param  husbd USBDEV handle
  * @param  msg LPM message
  * @retval HAL status
  */
__weak void HAL_USBDEVEx_LPM_Callback(USBDEV_HandleTypeDef *husbd, USBDEV_LPM_MsgTypeDef msg)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);
  UNUSED(msg);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEVEx_LPM_Callback could be implemented in the user file
   */
}

/**
  * @brief  Send BatteryCharging message to user layer callback.
  * @param  husbd USBDEV handle
  * @param  msg LPM message
  * @retval HAL status
  */
__weak void HAL_USBDEVEx_BCD_Callback(USBDEV_HandleTypeDef *husbd, USBDEV_BCD_MsgTypeDef msg)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husbd);
  UNUSED(msg);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USBDEVEx_BCD_Callback could be implemented in the user file
   */
}

/**
  * @}
  */

/**
  * @}
  */
#endif /* defined (USB1_OTG_FS) || defined (USB2_OTG_FS) */
#endif /* HAL_USBD_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
