/**
  ******************************************************************************
  * @file    py32e407_hal_usart_ex.c
  * @author  MCU Application Team
  * @brief   USART HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Universal Asynchronous Receiver Transmitter Peripheral (USART).
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *           + Peripheral Control functions
  *           + Peripheral State and Errors functions
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
#include "py32e407_hal_usart_ex.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup USARTEx USARTEx
  * @brief HAL USART module driver
  * @{
  */
#ifdef HAL_USART_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/** @defgroup USARTEx_Private_Constants USARTEx Private Constants
  * @{
  */
/* USART RX FIFO depth */
#define RX_FIFO_DEPTH 8U

/* USART TX FIFO depth */
#define TX_FIFO_DEPTH 8U
/**
  * @}
  */

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @defgroup USARTEx_Private_Functions USARTEx Private Functions
  * @{
  */
static void USARTEx_SetNbDataToProcess(USART_HandleTypeDef *husart);
/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @defgroup USARTEx_Exported_Functions  USARTEx Exported Functions
  * @{
  */

/** @defgroup USARTEx_Exported_Functions_Group1 IO operation functions
  * @brief Extended USART Transmit/Receive functions
  *
@verbatim
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    This subsection provides a set of FIFO mode related callback functions.

    (#) TX/RX Fifos Callbacks:
        (+) HAL_USARTEx_RxFifoFullCallback()
        (+) HAL_USARTEx_TxFifoEmptyCallback()

@endverbatim
  * @{
  */

/**
  * @brief  USART RX Fifo full callback.
  * @param  husart USART handle.
  * @retval None
  */
__weak void HAL_USARTEx_RxFifoFullCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USARTEx_RxFifoFullCallback can be implemented in the user file.
   */
}

/**
  * @brief  USART TX Fifo empty callback.
  * @param  husart USART handle.
  * @retval None
  */
__weak void HAL_USARTEx_TxFifoEmptyCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USARTEx_TxFifoEmptyCallback can be implemented in the user file.
   */
}

/**
  * @}
  */

/** @defgroup USARTEx_Exported_Functions_Group2 Peripheral Control functions
  * @brief    Extended Peripheral Control functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..] This section provides the following functions:
     (+) HAL_USARTEx_EnableFifoMode() API enables the FIFO mode
     (+) HAL_USARTEx_DisableFifoMode() API disables the FIFO mode
     (+) HAL_USARTEx_SetTxFifoThreshold() API sets the TX FIFO threshold
     (+) HAL_USARTEx_SetRxFifoThreshold() API sets the RX FIFO threshold


@endverbatim
  * @{
  */


/**
  * @brief  Enable the FIFO mode.
  * @param husart      USART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USARTEx_EnableFifoMode(USART_HandleTypeDef *husart)
{
  uint32_t tmpcr1;

  /* Check parameters */
  assert_param(IS_USART_FIFO_INSTANCE(husart->Instance));

  /* Process Locked */
  __HAL_LOCK(husart);

  husart->State = HAL_USART_STATE_BUSY;

  /* Save actual USART configuration */
  tmpcr1 = READ_REG(husart->Instance->CR1);

  /* Disable USART */
  __HAL_USART_DISABLE(husart);

  /* Enable FIFO mode */
  SET_BIT(tmpcr1, USART_CR1_FIFOEN);
  husart->FifoMode = USART_FIFOMODE_ENABLE;

  /* Restore USART configuration */
  WRITE_REG(husart->Instance->CR1, tmpcr1);

  /* Determine the number of data to process during RX/TX SR execution */
  USARTEx_SetNbDataToProcess(husart);

  husart->State = HAL_USART_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(husart);

  return HAL_OK;
}

/**
  * @brief  Disable the FIFO mode.
  * @param husart      USART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USARTEx_DisableFifoMode(USART_HandleTypeDef *husart)
{
  uint32_t tmpcr1;

  /* Check parameters */
  assert_param(IS_USART_FIFO_INSTANCE(husart->Instance));

  /* Process Locked */
  __HAL_LOCK(husart);

  husart->State = HAL_USART_STATE_BUSY;

  /* Save actual USART configuration */
  tmpcr1 = READ_REG(husart->Instance->CR1);

  /* Disable USART */
  __HAL_USART_DISABLE(husart);

  /* Enable FIFO mode */
  CLEAR_BIT(tmpcr1, USART_CR1_FIFOEN);
  husart->FifoMode = USART_FIFOMODE_DISABLE;

  /* Restore USART configuration */
  WRITE_REG(husart->Instance->CR1, tmpcr1);

  husart->State = HAL_USART_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(husart);

  return HAL_OK;
}

/**
  * @brief  Set the TXFIFO threshold.
  * @param husart      USART handle.
  * @param Threshold  TX FIFO threshold value
  *          This parameter can be one of the following values:
  *            @arg @ref USART_TXFIFO_THRESHOLD_1_8
  *            @arg @ref USART_TXFIFO_THRESHOLD_1_4
  *            @arg @ref USART_TXFIFO_THRESHOLD_1_2
  *            @arg @ref USART_TXFIFO_THRESHOLD_3_4
  *            @arg @ref USART_TXFIFO_THRESHOLD_7_8
  *            @arg @ref USART_TXFIFO_THRESHOLD_8_8
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USARTEx_SetTxFifoThreshold(USART_HandleTypeDef *husart, uint32_t Threshold)
{
  uint32_t tmpcr1;

  /* Check parameters */
  assert_param(IS_USART_FIFO_INSTANCE(husart->Instance));
  assert_param(IS_USART_TXFIFO_THRESHOLD(Threshold));

  /* Process Locked */
  __HAL_LOCK(husart);

  husart->State = HAL_USART_STATE_BUSY;

  /* Save actual USART configuration */
  tmpcr1 = READ_REG(husart->Instance->CR1);

  /* Disable USART */
  __HAL_USART_DISABLE(husart);

  /* Update TX threshold configuration */
  MODIFY_REG(husart->Instance->CR1, USART_CR1_TXFTCFG, Threshold);

  /* Determine the number of data to process during RX/TX SR execution */
  USARTEx_SetNbDataToProcess(husart);

  /* Restore USART configuration */
  SET_BIT(husart->Instance->CR1, tmpcr1);

  husart->State = HAL_USART_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(husart);

  return HAL_OK;
}

/**
  * @brief  Set the RXFIFO threshold.
  * @param husart      USART handle.
  * @param Threshold  RX FIFO threshold value
  *          This parameter can be one of the following values:
  *            @arg @ref USART_RXFIFO_THRESHOLD_1_8
  *            @arg @ref USART_RXFIFO_THRESHOLD_1_4
  *            @arg @ref USART_RXFIFO_THRESHOLD_1_2
  *            @arg @ref USART_RXFIFO_THRESHOLD_3_4
  *            @arg @ref USART_RXFIFO_THRESHOLD_7_8
  *            @arg @ref USART_RXFIFO_THRESHOLD_8_8
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USARTEx_SetRxFifoThreshold(USART_HandleTypeDef *husart, uint32_t Threshold)
{
  uint32_t tmpcr1;

  /* Check the parameters */
  assert_param(IS_USART_FIFO_INSTANCE(husart->Instance));
  assert_param(IS_USART_RXFIFO_THRESHOLD(Threshold));

  /* Process Locked */
  __HAL_LOCK(husart);

  husart->State = HAL_USART_STATE_BUSY;

  /* Save actual USART configuration */
  tmpcr1 = READ_REG(husart->Instance->CR1);

  /* Disable USART */
  __HAL_USART_DISABLE(husart);

  /* Update RX threshold configuration */
  MODIFY_REG(husart->Instance->CR1, USART_CR1_RXFTCFG, Threshold);

  /* Determine the number of data to process during RX/TX SR execution */
  USARTEx_SetNbDataToProcess(husart);

  /* Restore USART configuration */
  SET_BIT(husart->Instance->CR1, tmpcr1);

  husart->State = HAL_USART_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(husart);

  return HAL_OK;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup USARTEx_Private_Functions
  * @{
  */

/**
  * @brief Calculate the number of data to process in RX/TX ISR.
  * @note The RX FIFO depth and the TX FIFO depth is extracted from
  *       the USART configuration registers.
  * @param husart USART handle.
  * @retval None
  */
static void USARTEx_SetNbDataToProcess(USART_HandleTypeDef *husart)
{
  uint8_t rx_fifo_depth;
  uint8_t tx_fifo_depth;
  uint8_t rx_fifo_threshold;
  uint8_t tx_fifo_threshold;
  /* 2 0U/1U added for MISRAC2012-Rule-18.1_b and MISRAC2012-Rule-18.1_d */
  static const uint8_t numerator[]   = {1U, 1U, 1U, 3U, 7U, 1U, 0U, 0U};
  static const uint8_t denominator[] = {8U, 4U, 2U, 4U, 8U, 1U, 1U, 1U};

  if (husart->FifoMode == USART_FIFOMODE_DISABLE)
  {
    husart->NbTxDataToProcess = 1U;
    husart->NbRxDataToProcess = 1U;
  }
  else
  {
    rx_fifo_depth = RX_FIFO_DEPTH;
    tx_fifo_depth = TX_FIFO_DEPTH;
    rx_fifo_threshold = (uint8_t)((READ_BIT(husart->Instance->CR1,
                                            USART_CR1_RXFTCFG) >> USART_CR1_RXFTCFG_Pos) & 0xFFU);
    tx_fifo_threshold = (uint8_t)((READ_BIT(husart->Instance->CR1,
                                            USART_CR1_TXFTCFG) >> USART_CR1_TXFTCFG_Pos) & 0xFFU);
    husart->NbTxDataToProcess = ((uint16_t)tx_fifo_depth * numerator[tx_fifo_threshold]) /
                                (uint16_t)denominator[tx_fifo_threshold];
    husart->NbRxDataToProcess = ((uint16_t)rx_fifo_depth * numerator[rx_fifo_threshold]) /
                                (uint16_t)denominator[rx_fifo_threshold];
  }
}
/**
  * @}
  */

#endif /* HAL_USART_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
