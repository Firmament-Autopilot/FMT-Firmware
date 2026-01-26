/**
  ******************************************************************************
  * @file    py32e407_hal_sci_ex.c
  * @author  MCU Application Team
  * @brief   SCI HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Universal Asynchronous Receiver Transmitter Peripheral (SCI).
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
#include "py32e407_hal_sci.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup SCIEx SCIEx
  * @brief HAL SCI module driver
  * @{
  */
#ifdef HAL_SCI_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/** @defgroup SCIEx_Private_Constants SCIEx Private Constants
  * @{
  */
/* SCI RX FIFO depth */
#define RX_FIFO_DEPTH 8U

/* SCI TX FIFO depth */
#define TX_FIFO_DEPTH 8U
/**
  * @}
  */

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @defgroup SCIEx_Private_Functions SCIEx Private Functions
  * @{
  */
static void SCIEx_SetNbDataToProcess(SCI_HandleTypeDef *hsci);
/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @defgroup SCIEx_Exported_Functions  SCIEx Exported Functions
  * @{
  */

/**
  * @brief Initialize the RS485 Driver enable feature according to the specified
  *         parameters in the SCI_InitTypeDef and creates the associated handle.
  * @param hsci             SCI handle.
  * @param Polarity         Select the driver enable polarity.
  *          This parameter can be one of the following values:
  *          @arg @ref SCI_DE_POLARITY_HIGH DE signal is active high
  *          @arg @ref SCI_DE_POLARITY_LOW  DE signal is active low
  * @param AssertionTime    Driver Enable assertion time:
  *       5-bit value defining the time between the activation of the DE (Driver Enable)
  *       signal and the beginning of the start bit. It is expressed in sample time
  *       units (1/8 or 1/16 bit time, depending on the oversampling rate)
  * @param DeassertionTime  Driver Enable deassertion time:
  *       5-bit value defining the time between the end of the last stop bit, in a
  *       transmitted message, and the de-activation of the DE (Driver Enable) signal.
  *       It is expressed in sample time units (1/8 or 1/16 bit time, depending on the
  *       oversampling rate).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_RS485Ex_Init(SCI_HandleTypeDef *hsci, uint32_t Polarity, uint32_t AssertionTime,
                                   uint32_t DeassertionTime)
{
  uint32_t temp;

  /* Check the SCI handle allocation */
  if (hsci == NULL)
  {
    return HAL_ERROR;
  }
  /* Check the Driver Enable SCI instance */
  assert_param(IS_SCI_DRIVER_ENABLE_INSTANCE(hsci->Instance));

  /* Check the Driver Enable polarity */
  assert_param(IS_SCI_DE_POLARITY(Polarity));

  /* Check the Driver Enable assertion time */
  assert_param(IS_SCI_ASSERTIONTIME(AssertionTime));

  /* Check the Driver Enable deassertion time */
  assert_param(IS_SCI_DEASSERTIONTIME(DeassertionTime));

  if (hsci->gState == HAL_SCI_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hsci->Lock = HAL_UNLOCKED;

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
    SCI_InitCallbacksToDefault(hsci);

    if (hsci->MspInitCallback == NULL)
    {
      hsci->MspInitCallback = HAL_SCI_MspInit;
    }

    /* Init the low level hardware */
    hsci->MspInitCallback(hsci);
#else
    /* Init the low level hardware : GPIO, CLOCK, CORTEX */
    HAL_SCI_MspInit(hsci);
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */
  }

  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Disable the Peripheral */
  __HAL_SCI_DISABLE(hsci);

  /* Perform advanced settings configuration */
  /* For some items, configuration requires to be done prior TE and RE bits are set */
  if (hsci->AdvancedInit.AdvFeatureInit != SCI_ADVFEATURE_NO_INIT)
  {
    SCI_AdvFeatureConfig(hsci);
  }

  /* Set the SCI Communication parameters */
  SCI_SetConfig(hsci);

  /* Enable the Driver Enable mode by setting the DEM bit in the CR2 register */
  SET_BIT(hsci->Instance->CR2, USART_CR2_DEM);

  /* Set the Driver Enable polarity */
  MODIFY_REG(hsci->Instance->CR2, USART_CR2_DEP, Polarity);

  /* Set the Driver Enable assertion and deassertion times */
  temp = (AssertionTime << SCI_CR3_DEAT_ADDRESS_LSB_POS);
  temp |= (DeassertionTime << SCI_CR3_DEDT_ADDRESS_LSB_POS);
  MODIFY_REG(hsci->Instance->CR3, (USART_CR3_DEDT | USART_CR3_DEAT), temp);

  /* Enable the Peripheral */
  __HAL_SCI_ENABLE(hsci);

  /* Initialize the SCI State */
  hsci->gState = HAL_SCI_STATE_READY;
  hsci->RxState = HAL_SCI_STATE_READY;

  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @}
  */
/** @defgroup SCIEx_Exported_Functions_Group1 IO operation functions
  * @brief Extended SCI Transmit/Receive functions
  *
@verbatim
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    This subsection provides a set of FIFO mode related callback functions.

    (#) Wakeup Callback:
        (+) HAL_SCIEx_WakeupCallback()

    (#) TX/RX Fifos Callbacks:
        (+) HAL_SCIEx_RxFifoFullCallback()
        (+) HAL_SCIEx_TxFifoEmptyCallback()

@endverbatim
  * @{
  */

/**
  * @brief  SCI wake up callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCIEx_WakeupCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCIEx_WakeupCallback can be implemented in the user file.
   */
}

/**
  * @brief  SCI RX Fifo full callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCIEx_RxFifoFullCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCIEx_RxFifoFullCallback can be implemented in the user file.
   */
}

/**
  * @brief  SCI TX Fifo empty callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCIEx_TxFifoEmptyCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCIEx_TxFifoEmptyCallback can be implemented in the user file.
   */
}

/**
  * @}
  */

/** @defgroup SCIEx_Exported_Functions_Group2 Peripheral Control functions
  * @brief    Extended Peripheral Control functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..] This section provides the following functions:
     (+) HAL_SCIEx_EnableFifoMode() API enables the FIFO mode
     (+) HAL_SCIEx_DisableFifoMode() API disables the FIFO mode
     (+) HAL_SCIEx_SetTxFifoThreshold() API sets the TX FIFO threshold
     (+) HAL_SCIEx_SetRxFifoThreshold() API sets the RX FIFO threshold
@endverbatim
  * @{
  */

/**
  * @brief By default in multiprocessor mode, when the wake up method is set
  *        to address mark, the SCI handles only 4-bit long addresses detection;
  *        this API allows to enable longer addresses detection (6-, 7- or 8-bit
  *        long).
  * @note  Addresses detection lengths are: 6-bit address detection in 7-bit data mode,
  *        7-bit address detection in 8-bit data mode, 8-bit address detection in 9-bit data mode.
  * @param hsci         SCI handle.
  * @param AddressLength This parameter can be one of the following values:
  *          @arg @ref SCI_ADDRESS_DETECT_4B 4-bit long address
  *          @arg @ref SCI_ADDRESS_DETECT_7B 6-, 7- or 8-bit long address
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_MultiProcessorEx_AddressLength_Set(SCI_HandleTypeDef *hsci, uint32_t AddressLength)
{
  /* Check the SCI handle allocation */
  if (hsci == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the address length parameter */
  assert_param(IS_SCI_ADDRESSLENGTH_DETECT(AddressLength));

  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Disable the Peripheral */
  __HAL_SCI_DISABLE(hsci);

  /* Set the address length */
  MODIFY_REG(hsci->Instance->CR1, USART_CR1_ADDM7, AddressLength);

  /* Enable the Peripheral */
  __HAL_SCI_ENABLE(hsci);

  /* Initialize the SCI State */
  hsci->gState  = HAL_SCI_STATE_READY;
  hsci->RxState = HAL_SCI_STATE_READY;
  
  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief  Enable the FIFO mode.
  * @param hsci      SCI handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCIEx_EnableFifoMode(SCI_HandleTypeDef *hsci)
{
  uint32_t tmpcr1;

  /* Check parameters */
  assert_param(IS_SCI_FIFO_INSTANCE(hsci->Instance));

  /* Process Locked */
  __HAL_LOCK(hsci);

  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Save actual SCI configuration */
  tmpcr1 = READ_REG(hsci->Instance->CR1);

  /* Disable SCI */
  __HAL_SCI_DISABLE(hsci);

  /* Enable FIFO mode */
  SET_BIT(tmpcr1, USART_CR1_FIFOEN);
  hsci->FifoMode = SCI_FIFOMODE_ENABLE;

  /* Restore SCI configuration */
  WRITE_REG(hsci->Instance->CR1, tmpcr1);

  /* Determine the number of data to process during RX/TX SR execution */
  SCIEx_SetNbDataToProcess(hsci);

  hsci->gState = HAL_SCI_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief  Disable the FIFO mode.
  * @param  hsci SCI handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCIEx_DisableFifoMode(SCI_HandleTypeDef *hsci)
{
  uint32_t tmpcr1;

  /* Check parameters */
  assert_param(IS_SCI_FIFO_INSTANCE(hsci->Instance));

  /* Process Locked */
  __HAL_LOCK(hsci);

  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Save actual SCI configuration */
  tmpcr1 = READ_REG(hsci->Instance->CR1);

  /* Disable SCI */
  __HAL_SCI_DISABLE(hsci);

  /* Disable FIFO mode */
  CLEAR_BIT(tmpcr1, USART_CR1_FIFOEN);
  hsci->FifoMode = SCI_FIFOMODE_DISABLE;

  /* Restore SCI configuration */
  WRITE_REG(hsci->Instance->CR1, tmpcr1);

  hsci->gState = HAL_SCI_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief  Set the TXFIFO threshold.
  * @param hsci      SCI handle.
  * @param Threshold  TX FIFO threshold value
  *          This parameter can be one of the following values:
  *            @arg @ref SCI_TXFIFO_THRESHOLD_1_8
  *            @arg @ref SCI_TXFIFO_THRESHOLD_1_4
  *            @arg @ref SCI_TXFIFO_THRESHOLD_1_2
  *            @arg @ref SCI_TXFIFO_THRESHOLD_3_4
  *            @arg @ref SCI_TXFIFO_THRESHOLD_7_8
  *            @arg @ref SCI_TXFIFO_THRESHOLD_8_8
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCIEx_SetTxFifoThreshold(SCI_HandleTypeDef *hsci, uint32_t Threshold)
{
  uint32_t tmpcr1;

  /* Check parameters */
  assert_param(IS_SCI_FIFO_INSTANCE(hsci->Instance));
  assert_param(IS_SCI_TXFIFO_THRESHOLD(Threshold));

  /* Process Locked */
  __HAL_LOCK(hsci);

  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Save actual SCI configuration */
  tmpcr1 = READ_REG(hsci->Instance->CR1);

  /* Disable SCI */
  __HAL_SCI_DISABLE(hsci);

  /* Update TX threshold configuration */
  MODIFY_REG(hsci->Instance->CR1, USART_CR1_TXFTCFG, Threshold);

  /* Determine the number of data to process during RX/TX SR execution */
  SCIEx_SetNbDataToProcess(hsci);

  /* Restore SCI configuration */
  SET_BIT(hsci->Instance->CR1, tmpcr1);

  hsci->gState = HAL_SCI_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief  Set the RXFIFO threshold.
  * @param hsci      SCI handle.
  * @param Threshold  RX FIFO threshold value
  *          This parameter can be one of the following values:
  *            @arg @ref SCI_RXFIFO_THRESHOLD_1_8
  *            @arg @ref SCI_RXFIFO_THRESHOLD_1_4
  *            @arg @ref SCI_RXFIFO_THRESHOLD_1_2
  *            @arg @ref SCI_RXFIFO_THRESHOLD_3_4
  *            @arg @ref SCI_RXFIFO_THRESHOLD_7_8
  *            @arg @ref SCI_RXFIFO_THRESHOLD_8_8
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCIEx_SetRxFifoThreshold(SCI_HandleTypeDef *hsci, uint32_t Threshold)
{
  uint32_t tmpcr1;

  /* Check the parameters */
  assert_param(IS_SCI_FIFO_INSTANCE(hsci->Instance));
  assert_param(IS_SCI_RXFIFO_THRESHOLD(Threshold));

  /* Process Locked */
  __HAL_LOCK(hsci);

  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Save actual SCI configuration */
  tmpcr1 = READ_REG(hsci->Instance->CR1);

  /* Disable SCI */
  __HAL_SCI_DISABLE(hsci);

  /* Update RX threshold configuration */
  MODIFY_REG(hsci->Instance->CR1, USART_CR1_RXFTCFG, Threshold);

  /* Determine the number of data to process during RX/TX SR execution */
  SCIEx_SetNbDataToProcess(hsci);

  /* Restore SCI configuration */
  SET_BIT(hsci->Instance->CR1, tmpcr1);

  hsci->gState = HAL_SCI_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief Receive an amount of data in blocking mode till either the expected number of data
  *        is received or an IDLE event occurs.
  * @note  HAL_OK is returned if reception is completed (expected number of data has been received)
  *        or if reception is stopped after IDLE event (less than the expected number of data has been received)
  *        In this case, RxLen output parameter indicates number of data available in reception buffer.
  * @note  When SCI parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *        the received data is handled as a set of uint16_t. In this case, Size must indicate the number
  *        of uint16_t available through pData.
  * @note When FIFO mode is enabled, the RXNE flag is set as long as the RXFIFO
  *       is not empty. Read operations from the RDR register are performed when
  *       RXNE flag is set. From hardware perspective, RXNE flag and is mapped on the same bit-field.
  * @param hsci    SCI handle.
  * @param pData   Pointer to data buffer (uint8_t or uint16_t data elements).
  * @param Size    Amount of data elements (uint8_t or uint16_t or uint32_t) to be received.
  * @param RxLen   Number of data elements finally received
  *                (could be lower than Size, in case reception ends on IDLE event)
  * @param Timeout Timeout duration expressed in ms (covers the whole reception sequence).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCIEx_ReceiveToIdle(SCI_HandleTypeDef *hsci, uint8_t *pData, uint32_t Size, uint16_t *RxLen,
                                           uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint16_t *pdata16bits;
  uint16_t uhMask;
  uint32_t tickstart;

  /* Check that a Rx process is not already ongoing */
  if (hsci->RxState == HAL_SCI_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    hsci->ErrorCode = HAL_SCI_ERROR_NONE;
    hsci->RxState = HAL_SCI_STATE_BUSY_RX;
    hsci->ReceptionType = HAL_SCI_RECEPTION_TOIDLE;
    hsci->RxEventType = HAL_SCI_RXEVENT_TC;

    /* Init tickstart for timeout management */
    tickstart = HAL_GetTick();

    hsci->RxXferSize  = Size;
    hsci->RxXferCount = Size;

    /* Computation of SCI mask to apply to RDR register */
    SCI_MASK_COMPUTATION(hsci);
    uhMask = hsci->Mask;

    /* In case of 9bits/No Parity transfer, pRxData needs to be handled as a uint16_t pointer */
    if ((hsci->Init.WordLength == SCI_WORDLENGTH_9B) && (hsci->Init.Parity == SCI_PARITY_NONE))
    {
      pdata8bits  = NULL;
      pdata16bits = (uint16_t *) pData;
    }
    else
    {
      pdata8bits  = pData;
      pdata16bits = NULL;
    }

    /* Initialize output number of received elements */
    *RxLen = 0U;

    /* as long as data have to be received */
    while (hsci->RxXferCount > 0U)
    {
      /* Check if IDLE flag is set */
      if (__HAL_SCI_GET_FLAG(hsci, SCI_FLAG_IDLE))
      {
        /* Clear IDLE flag in SR */
        __HAL_SCI_CLEAR_IDLEFLAG(hsci);

        /* If Set, but no data ever received, clear flag without exiting loop */
        /* If Set, and data has already been received, this means Idle Event is valid : End reception */
        if (*RxLen > 0U)
        {
          hsci->RxEventType = HAL_SCI_RXEVENT_IDLE;
          hsci->RxState = HAL_SCI_STATE_READY;

          return HAL_OK;
        }
      }

      /* Check if RXNE flag is set */
      if (__HAL_SCI_GET_FLAG(hsci, SCI_FLAG_RXNE))
      {
        if (pdata8bits == NULL)
        {
          *pdata16bits = (uint16_t)(hsci->Instance->DR & uhMask);
          pdata16bits++;
        }
        else
        {
          *pdata8bits = (uint8_t)(hsci->Instance->DR & (uint8_t)uhMask);
          pdata8bits++;
        }
        /* Increment number of received elements */
        *RxLen += 1U;
        hsci->RxXferCount--;
      }

      /* Check for the Timeout */
      if (Timeout != HAL_MAX_DELAY)
      {
        if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0U))
        {
          hsci->RxState = HAL_SCI_STATE_READY;

          return HAL_TIMEOUT;
        }
      }
    }

    /* Set number of received elements in output parameter : RxLen */
    *RxLen = hsci->RxXferSize - hsci->RxXferCount;
    /* At end of Rx process, restore hsci->RxState to Ready */
    hsci->RxState = HAL_SCI_STATE_READY;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in interrupt mode till either the expected number of data
  *        is received or an IDLE event occurs.
  * @note  Reception is initiated by this function call. Further progress of reception is achieved thanks
  *        to SCI interrupts raised by RXNE and IDLE events. Callback is called at end of reception indicating
  *        number of received data elements.
  * @note  When SCI parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *        the received data is handled as a set of uint16_t. In this case, Size must indicate the number
  *        of uint16_t available through pData.
  * @param hsci SCI handle.
  * @param pData Pointer to data buffer (uint8_t or uint16_t data elements).
  * @param Size  Amount of data elements (uint8_t or uint16_t or uint32_t) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCIEx_ReceiveToIdle_IT(SCI_HandleTypeDef *hsci, uint8_t *pData, uint32_t Size)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check that a Rx process is not already ongoing */
  if (hsci->RxState == HAL_SCI_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Set Reception type to reception till IDLE Event*/
    hsci->ReceptionType = HAL_SCI_RECEPTION_TOIDLE;
    hsci->RxEventType = HAL_SCI_RXEVENT_TC;

    (void)SCI_Start_Receive_IT(hsci, pData, Size);

    if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
    {
      __HAL_SCI_CLEAR_IDLEFLAG(hsci);
      ATOMIC_SET_BIT(hsci->Instance->CR1, USART_CR1_IDLEIE);
    }
    else
    {
      /* In case of errors already pending when reception is started,
         Interrupts may have already been raised and lead to reception abortion.
         (Overrun error for instance).
         In such case Reception Type has been reset to HAL_SCI_RECEPTION_STANDARD. */
      status = HAL_ERROR;
    }

    return status;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in DMA mode till either the expected number
  *        of data is received or an IDLE event occurs.
  * @note  Reception is initiated by this function call. Further progress of reception is achieved thanks
  *        to DMA services, transferring automatically received data elements in user reception buffer and
  *        calling registered callbacks at half/end of reception. SCI IDLE events are also used to consider
  *        reception phase as ended. In all cases, callback execution will indicate number of received data elements.
  * @note  When the SCI parity is enabled (PCE = 1), the received data contain
  *        the parity bit (MSB position).
  * @note  When hsci parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *        the received data is handled as a set of uint16_t. In this case, Size must indicate the number
  *        of uint16_t available through pData.
  * @param hsci  SCI handle.
  * @param pData Pointer to data buffer (uint8_t or uint16_t data elements).
  * @param Size  Amount of data elements (uint8_t or uint16_t or uint32_t) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCIEx_ReceiveToIdle_DMA(SCI_HandleTypeDef *hsci, uint8_t *pData, uint32_t Size)
{
  HAL_StatusTypeDef status;

  /* Check that a Rx process is not already ongoing */
  if (hsci->RxState == HAL_SCI_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Set Reception type to reception till IDLE Event*/
    hsci->ReceptionType = HAL_SCI_RECEPTION_TOIDLE;
    hsci->RxEventType = HAL_SCI_RXEVENT_TC;

    status = SCI_Start_Receive_DMA(hsci, pData, Size);

    /* Check Rx process has been successfully started */
    if (status == HAL_OK)
    {
      if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
      {
        __HAL_SCI_CLEAR_IDLEFLAG(hsci);
        SET_BIT(hsci->Instance->CR1, USART_CR1_IDLEIE);
      }
      else
      {
        /* In case of errors already pending when reception is started,
           Interrupts may have already been raised and lead to reception abortion.
           (Overrun error for instance).
           In such case Reception Type has been reset to HAL_SCI_RECEPTION_STANDARD. */
        status = HAL_ERROR;
      }
    }

    return status;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Provide Rx Event type that has lead to RxEvent callback execution.
  * @note  When HAL_SCIEx_ReceiveToIdle_IT() or HAL_SCIEx_ReceiveToIdle_DMA() API are called, progress
  *        of reception process is provided to application through calls of Rx Event callback (either default one
  *        HAL_SCIEx_RxEventCallback() or user registered one). As several types of events could occur (IDLE event,
  *        Half Transfer, or Transfer Complete), this function allows to retrieve the Rx Event type that has lead
  *        to Rx Event callback execution.
  * @note  This function is expected to be called within the user implementation of Rx Event Callback,
  *        in order to provide the accurate value :
  *        In Interrupt Mode :
  *           - HAL_SCI_RXEVENT_TC : when Reception has been completed (expected nb of data has been received)
  *           - HAL_SCI_RXEVENT_IDLE : when Idle event occurred prior reception has been completed (nb of
  *             received data is lower than expected one)
  *        In DMA Mode :
  *           - HAL_SCI_RXEVENT_TC : when Reception has been completed (expected nb of data has been received)
  *           - HAL_SCI_RXEVENT_HT : when half of expected nb of data has been received
  *           - HAL_SCI_RXEVENT_IDLE : when Idle event occurred prior reception has been completed (nb of
  *             received data is lower than expected one).
  *        In DMA mode, RxEvent callback could be called several times;
  *        When DMA is configured in Normal Mode, HT event does not stop Reception process;
  *        When DMA is configured in Circular Mode, HT, TC or IDLE events don't stop Reception process;
  * @param  hsci SCI handle.
  * @retval Rx Event Type (return vale will be a value of @ref SCI_RxEvent_Type_Values)
  */
HAL_SCI_RxEventTypeTypeDef HAL_SCIEx_GetRxEventType(const SCI_HandleTypeDef *hsci)
{
  /* Return Rx Event type value, as stored in SCI handle */
  return (hsci->RxEventType);
}

/**
  * @}
  */

/** @addtogroup SCIEx_Private_Functions
  * @{
  */

/**
  * @brief Calculate the number of data to process in RX/TX ISR.
  * @note The RX FIFO depth and the TX FIFO depth is extracted from
  *       the SCI configuration registers.
  * @param hsci SCI handle.
  * @retval None
  */
static void SCIEx_SetNbDataToProcess(SCI_HandleTypeDef *hsci)
{
  uint8_t rx_fifo_depth;
  uint8_t tx_fifo_depth;
  uint8_t rx_fifo_threshold;
  uint8_t tx_fifo_threshold;
  /* 2 0U/1U added for MISRAC2012-Rule-18.1_b and MISRAC2012-Rule-18.1_d */
  static const uint8_t numerator[]   = {1U, 1U, 1U, 3U, 7U, 1U, 0U, 0U};
  static const uint8_t denominator[] = {8U, 4U, 2U, 4U, 8U, 1U, 1U, 1U};

  if (hsci->FifoMode == SCI_FIFOMODE_DISABLE)
  {
    hsci->NbTxDataToProcess = 1U;
    hsci->NbRxDataToProcess = 1U;
  }
  else
  {
    rx_fifo_depth = RX_FIFO_DEPTH;
    tx_fifo_depth = TX_FIFO_DEPTH;
    rx_fifo_threshold = (uint8_t)((READ_BIT(hsci->Instance->CR1,
                                            USART_CR1_RXFTCFG) >> USART_CR1_RXFTCFG_Pos) & 0xFFU);
    tx_fifo_threshold = (uint8_t)((READ_BIT(hsci->Instance->CR1,
                                            USART_CR1_TXFTCFG) >> USART_CR1_TXFTCFG_Pos) & 0xFFU);
    hsci->NbTxDataToProcess = ((uint16_t)tx_fifo_depth * numerator[tx_fifo_threshold]) /
                                (uint16_t)denominator[tx_fifo_threshold];
    hsci->NbRxDataToProcess = ((uint16_t)rx_fifo_depth * numerator[rx_fifo_threshold]) /
                                (uint16_t)denominator[rx_fifo_threshold];
  }
}
/**
  * @}
  */

#endif /* HAL_SCI_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
