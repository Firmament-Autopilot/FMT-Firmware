/**
  ******************************************************************************
  * @file    py32e407_hal_sci.c
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

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup SCI SCI
  * @brief HAL SCI module driver
  * @{
  */
  
#ifdef HAL_SCI_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup SCI_Private_Constants SCI Private Constants
  * @{
  */
#define SCI_DUMMY_DATA            ((uint16_t) 0xFFFF)           /*!< SCI transmitted dummy data                     */
#define SCI_TEACK_REACK_TIMEOUT               1000U             /*!< SCI TX or RX enable acknowledge time-out value */
#define SCI_CR1_FIELDS            ((uint32_t)(USART_CR1_M0 | USART_CR1_M1 | USART_CR1_PCE | \
                                              USART_CR1_PS | USART_CR1_TE | USART_CR1_RE  | \
                                              USART_CR1_FIFOEN | USART_CR1_TXFTCFG | USART_CR1_RXFTCFG )) /*!< USART CR1 fields of parameters set by SCI_SetConfig API */

#define SCI_CR2_FIELDS            ((uint32_t)(USART_CR2_CPHA | USART_CR2_CPOL | USART_CR2_CLKEN | \
                                              USART_CR2_LBCL | USART_CR2_STOP))                 /*!< USART CR2 fields of parameters set by SCI_SetConfig API */

#define SCI_CR3_FIELDS           ((uint32_t)(USART_CR3_RTSE | USART_CR3_CTSE | \
                                             USART_CR3_TXFTCFG | USART_CR3_RXFTCFG ))  /*!< SCI or USART CR3 fields of parameters set by SCI API */

#define SCI_BRR_MIN    0x10U        /* SCI BRR minimum authorized value */
#define SCI_BRR_MAX    0xFFFFU      /* SCI BRR maximum authorized value */
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup SCI_Private_Functions
  * @{
  */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
void SCI_InitCallbacksToDefault(SCI_HandleTypeDef *hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
static void SCI_EndTxTransfer(SCI_HandleTypeDef *hsci);
static void SCI_EndRxTransfer(SCI_HandleTypeDef *hsci);
static void SCI_DMATransmitCplt(DMA_HandleTypeDef *hdma);
static void SCI_DMAReceiveCplt(DMA_HandleTypeDef *hdma);
static void SCI_DMATxBlockCplt(DMA_HandleTypeDef *hdma);
static void SCI_DMATxHalfBlockCplt(DMA_HandleTypeDef *hdma);
static void SCI_DMATransmitSrcCplt(DMA_HandleTypeDef *hdma);
static void SCI_DMARxHalfBlockCplt(DMA_HandleTypeDef *hdma);
static void SCI_DMARxBlockCplt(DMA_HandleTypeDef *hdma);
static void SCI_DMAReceiveDstCplt(DMA_HandleTypeDef *hdma);

static void SCI_DMAError(DMA_HandleTypeDef *hdma);
static void SCI_DMAAbortOnError(DMA_HandleTypeDef *hdma);
static void SCI_DMATxAbortCallback(DMA_HandleTypeDef *hdma);
static void SCI_DMARxAbortCallback(DMA_HandleTypeDef *hdma);
static void SCI_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma);
static void SCI_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma);

static void SCI_TxSR_8BIT(SCI_HandleTypeDef *hsci);
static void SCI_TxSR_16BIT(SCI_HandleTypeDef *hsci);
static void SCI_TxSR_8BIT_FIFOEN(SCI_HandleTypeDef *hsci);
static void SCI_TxSR_16BIT_FIFOEN(SCI_HandleTypeDef *hsci);
static void SCI_EndTransmit_IT(SCI_HandleTypeDef *hsci);

static void SCI_RxSR_8BIT(SCI_HandleTypeDef *hsci);
static void SCI_RxSR_16BIT(SCI_HandleTypeDef *hsci);
static void SCI_RxSR_8BIT_FIFOEN(SCI_HandleTypeDef *hsci);
static void SCI_RxSR_16BIT_FIFOEN(SCI_HandleTypeDef *hsci);

static HAL_StatusTypeDef SCI_WaitOnFlagUntilTimeout(SCI_HandleTypeDef *hsci, uint32_t Flag, FlagStatus Status, uint32_t Tickstart, uint32_t Timeout);

/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @defgroup SCI_Exported_Functions SCI Exported Functions
  * @{
  */
/** @defgroup SCI_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
  * @{
  */
/**
  * @brief  Initializes the SCI mode according to the specified parameters in
  *         the SCI_InitTypeDef and create the associated handle.
  * @param  hsci  Pointer to a SCI_HandleTypeDef structure that contains
  *                the configuration information for the specified SCI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_Init(SCI_HandleTypeDef *hsci)
{
  /* Check the SCI handle allocation */
  if (hsci == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  if (hsci->Init.HwFlowCtl != SCI_HWCONTROL_NONE)
  {
    /* The hardware flow control is available only for USART1 ~ USART3 */
    assert_param(IS_SCI_HWFLOW_INSTANCE(hsci->Instance));
    assert_param(IS_SCI_HARDWARE_FLOW_CONTROL(hsci->Init.HwFlowCtl));
  }
  else
  {
    assert_param(IS_SCI_INSTANCE(hsci->Instance));
  }
  assert_param(IS_SCI_WORD_LENGTH(hsci->Init.WordLength));
  assert_param(IS_SCI_OVERSAMPLING(hsci->Init.OverSampling));

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
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_SCI_MspInit(hsci);
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */
  }

  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Disable the peripheral */
  __HAL_SCI_DISABLE(hsci);

  /* Set the SCI Communication parameters */
  SCI_SetConfig(hsci);

  if (hsci->AdvancedInit.AdvFeatureInit != SCI_ADVFEATURE_NO_INIT)
  {
    SCI_AdvFeatureConfig(hsci);
  }

  /* In asynchronous mode, the following bits must be kept cleared:
     - LINEN and CLKEN bits in the USART_CR2 register,
     - SCEN, HDSEL and IREN  bits in the USART_CR3 register.*/
  CLEAR_BIT(hsci->Instance->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));

  /* Enable the peripheral */
  __HAL_SCI_ENABLE(hsci);

  /* Initialize the SCI state */
  hsci->ErrorCode = HAL_SCI_ERROR_NONE;
  hsci->gState = HAL_SCI_STATE_READY;
  hsci->RxState = HAL_SCI_STATE_READY;

  return HAL_OK;
}

/**
  * @brief Initialize the half-duplex mode according to the specified
  *        parameters in the SCI_InitTypeDef and creates the associated handle.
  * @param hsci SCI handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_HalfDuplex_Init(SCI_HandleTypeDef *hsci)
{
  /* Check the SCI handle allocation */
  if (hsci == NULL)
  {
    return HAL_ERROR;
  }

  /* Check SCI instance */
  assert_param(IS_SCI_HALFDUPLEX_INSTANCE(hsci->Instance));

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
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_SCI_MspInit(hsci);
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */
  }

  hsci->gState = HAL_SCI_STATE_BUSY;

  __HAL_SCI_DISABLE(hsci);

  if (hsci->AdvancedInit.AdvFeatureInit != SCI_ADVFEATURE_NO_INIT)
  {
    SCI_AdvFeatureConfig(hsci);
  }

  /* Set the SCICommunication parameters */
  SCI_SetConfig(hsci);

  /* In half-duplex mode, the following bits must be kept cleared:
  - LINEN and CLKEN bits in the USART_CR2 register,
  - SCEN and IREN bits in the USART_CR3 register.*/
  CLEAR_BIT(hsci->Instance->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_IREN | USART_CR3_SCEN));

  /* Enable the Half-Duplex mode by setting the HDSEL bit in the CR3 register */
  SET_BIT(hsci->Instance->CR3, USART_CR3_HDSEL);

  __HAL_SCI_ENABLE(hsci);

  /* Initialize the SCI state */
  hsci->ErrorCode = HAL_SCI_ERROR_NONE;
  hsci->gState = HAL_SCI_STATE_READY;
  hsci->RxState = HAL_SCI_STATE_READY;

  return HAL_OK;
}


/**
  * @brief Initialize the LIN mode according to the specified
  *        parameters in the SCI_InitTypeDef and creates the associated handle.
  * @param hsci             SCI handle.
  * @param BreakDetectLength Specifies the LIN break detection length.
  *        This parameter can be one of the following values:
  *          @arg @ref SCI_LINBREAKDETECTLENGTH_10B 10-bit break detection
  *          @arg @ref SCI_LINBREAKDETECTLENGTH_11B 11-bit break detection
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LIN_Init(SCI_HandleTypeDef *hsci, uint32_t BreakDetectLength)
{
  /* Check the SCI handle allocation */
  if (hsci == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the LIN SCI instance */
  assert_param(IS_SCI_LIN_INSTANCE(hsci->Instance));
  /* Check the Break detection length parameter */
  assert_param(IS_SCI_LIN_BREAK_DETECT_LENGTH(BreakDetectLength));

  /* LIN mode limited to 16-bit oversampling only */
  if (hsci->Init.OverSampling == SCI_OVERSAMPLING_8)
  {
    return HAL_ERROR;
  }
  /* LIN mode limited to 8-bit data length */
  if (hsci->Init.WordLength != SCI_WORDLENGTH_8B)
  {
    return HAL_ERROR;
  }

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
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_SCI_MspInit(hsci);
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */
  }

  hsci->gState = HAL_SCI_STATE_BUSY;

  __HAL_SCI_DISABLE(hsci);

  /* Set the SCI Communication parameters */
  /* In LIN mode, stop bit occupies 1 bit, 16 times oversampling, and data length occupies 8 bits. */
  hsci->Init.OverSampling = SCI_OVERSAMPLING_16;
  hsci->Init.StopBits = SCI_STOPBITS_1;
  hsci->Init.WordLength = SCI_WORDLENGTH_8B;

  if (hsci->AdvancedInit.AdvFeatureInit != SCI_ADVFEATURE_NO_INIT)
  {
    SCI_AdvFeatureConfig(hsci);
  }

  /* Set the SCI Communication parameters */
  SCI_SetConfig(hsci);

  /* In LIN mode, the following bits must be kept cleared:
  - LINEN and CLKEN bits in the USART_CR2 register,
  - SCEN and IREN bits in the USART_CR3 register.*/
  CLEAR_BIT(hsci->Instance->CR2, USART_CR2_CLKEN);
  CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_HDSEL | USART_CR3_IREN | USART_CR3_SCEN));

  /* Enable the LIN mode by setting the LINEN bit in the CR2 register */
  SET_BIT(hsci->Instance->CR2, USART_CR2_LINEN);

  /* Set the SCI LIN Break detection length. */
  MODIFY_REG(hsci->Instance->CR2, USART_CR2_LBDL, BreakDetectLength);

  __HAL_SCI_ENABLE(hsci);
  
  /* Initialize the SCI state */
  hsci->ErrorCode = HAL_SCI_ERROR_NONE;
  hsci->gState = HAL_SCI_STATE_READY;
  hsci->RxState = HAL_SCI_STATE_READY;

  return HAL_OK;

}

/**
  * @brief Initialize the multiprocessor mode according to the specified
  *        parameters in the SCI_InitTypeDef and initialize the associated handle.
  * @param hsci        SCI handle.
  * @param Address      SCI node address (4-, 6-, 7- or 8-bit long).
  * @param WakeUpMethod Specifies the SCI wakeup method.
  *        This parameter can be one of the following values:
  *          @arg @ref SCI_WAKEUPMETHOD_IDLELINE WakeUp by an idle line detection
  *          @arg @ref SCI_WAKEUPMETHOD_ADDRESSMARK WakeUp by an address mark
  * @note  If the user resorts to idle line detection wake up, the Address parameter
  *        is useless and ignored by the initialization function.
  * @note  If the user resorts to address mark wake up, the address length detection
  *        is configured by default to 4 bits only. For the SCI to be able to
  *        manage 6-, 7- or 8-bit long addresses detection, the API
  *        HAL_MultiProcessorEx_AddressLength_Set() must be called after
  *        HAL_MultiProcessor_Init().
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_MultiProcessor_Init(SCI_HandleTypeDef *hsci, uint8_t Address, uint32_t WakeUpMethod)
{
  /* Check the SCI handle allocation */
  if (hsci == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_SCI_INSTANCE(hsci->Instance));

  /* Check the wake up method parameter */
  assert_param(IS_SCI_WAKEUPMETHOD(WakeUpMethod));
  assert_param(IS_SCI_ADDRESS(Address));

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
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_SCI_MspInit(hsci);
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */
  }

  hsci->gState = HAL_SCI_STATE_BUSY;

  __HAL_SCI_DISABLE(hsci);
  
  /* Perform advanced settings configuration */
  /* For some items, configuration requires to be done prior TE and RE bits are set */
  if (hsci->AdvancedInit.AdvFeatureInit != SCI_ADVFEATURE_NO_INIT)
  {
    SCI_AdvFeatureConfig(hsci);
  }

  /* Set the SCI Communication parameters */
  SCI_SetConfig(hsci);

  /* In multiprocessor mode, the following bits must be kept cleared:
  - LINEN and CLKEN bits in the USART_CR2 register,
  - SCEN, HDSEL and IREN  bits in the USART_CR3 register. */
  CLEAR_BIT(hsci->Instance->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));

  if (WakeUpMethod == SCI_WAKEUPMETHOD_ADDRESSMARK)
  {
    /* If address mark wake up method is chosen, set the SCI address node */
    MODIFY_REG(hsci->Instance->CR2, USART_CR2_ADD, ((uint32_t)Address << 15));
  }

  /* Set the wake up method by setting the WAKE bit in the CR1 register */
  MODIFY_REG(hsci->Instance->CR1, USART_CR1_WAKE, WakeUpMethod);

  __HAL_SCI_ENABLE(hsci);

  /* Initialize the SCI state */
  hsci->ErrorCode = HAL_SCI_ERROR_NONE;
  hsci->gState = HAL_SCI_STATE_READY;
  hsci->RxState = HAL_SCI_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  DeInitializes the SCI peripheral.
  * @param  hsci  Pointer to a SCI_HandleTypeDef structure that contains
  *                the configuration information for the specified SCI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_DeInit(SCI_HandleTypeDef *hsci)
{
  /* Check the SCI handle allocation */
  if (hsci == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_SCI_INSTANCE(hsci->Instance));

  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Disable the Peripheral */
  __HAL_SCI_DISABLE(hsci);

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  if (hsci->MspDeInitCallback == NULL)
  {
    hsci->MspDeInitCallback = HAL_SCI_MspDeInit;
  }
  /* DeInit the low level hardware */
  hsci->MspDeInitCallback(hsci);
#else
  /* DeInit the low level hardware */
  HAL_SCI_MspDeInit(hsci);
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */

  hsci->ErrorCode = HAL_SCI_ERROR_NONE;
  hsci->gState = HAL_SCI_STATE_RESET;
  hsci->RxState = HAL_SCI_STATE_RESET;
  hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;
  hsci->RxEventType = HAL_SCI_RXEVENT_TC;

  /* Process Unlock */
  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief  SCI MSP Init.
  * @param  hsci  Pointer to a SCI_HandleTypeDef structure that contains
  *                the configuration information for the specified SCI module.
  * @retval None
  */
__weak void HAL_SCI_MspInit(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_SCI_MspInit could be implemented in the user file
   */
}

/**
  * @brief  SCI MSP DeInit.
  * @param  hsci  Pointer to a SCI_HandleTypeDef structure that contains
  *                the configuration information for the specified SCI module.
  * @retval None
  */
__weak void HAL_SCI_MspDeInit(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_SCI_MspDeInit could be implemented in the user file
   */
}

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User SCI Callback
  *         To be used instead of the weak predefined callback
  * @param  hsci SCI handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_SCI_TX_BLOCKCOMPLETE_CB_ID Tx Block Complete Callback ID
  *           @arg @ref HAL_SCI_TX_HALFBLOCKCOMPLETE_CB_ID Tx Half Block Complete Callback ID
  *           @arg @ref HAL_SCI_TX_SRCCOMPLETE_CB_ID Tx Source Complete Callback ID
  *           @arg @ref HAL_SCI_TX_COMPLETE_CB_ID Tx Complete Callback ID
  *           @arg @ref HAL_SCI_RX_BLOCKCOMPLETE_CB_ID Rx Block Complete Callback ID
  *           @arg @ref HAL_SCI_RX_HALFBLOCKCOMPLETE_CB_ID Rx Half Block Complete Callback ID
  *           @arg @ref HAL_SCI_RX_DSTCOMPLETE_CB_ID Rx Destination Complete Callback ID
  *           @arg @ref HAL_SCI_RX_COMPLETE_CB_ID Rx Complete Callback ID
  *           @arg @ref HAL_SCI_ERROR_CB_ID Error Callback ID
  *           @arg @ref HAL_SCI_ABORT_COMPLETE_CB_ID Abort Complete Callback ID
  *           @arg @ref HAL_SCI_ABORT_TRANSMIT_COMPLETE_CB_ID Abort Transmit Complete Callback ID
  *           @arg @ref HAL_SCI_ABORT_RECEIVE_COMPLETE_CB_ID Abort Receive Complete Callback ID
  *           @arg @ref HAL_SCI_RX_FIFO_FULL_CB_ID Rx Fifo Full Callback ID
  *           @arg @ref HAL_SCI_TX_FIFO_EMPTY_CB_ID Tx Fifo Empty Callback ID
  *           @arg @ref HAL_SCI_MSPINIT_CB_ID MspInit Callback ID
  *           @arg @ref HAL_SCI_MSPDEINIT_CB_ID MspDeInit Callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_RegisterCallback(SCI_HandleTypeDef *hsci, HAL_SCI_CallbackIDTypeDef CallbackID, pSCI_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hsci->ErrorCode |= HAL_SCI_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(hsci);

  if (hsci->gState == HAL_SCI_STATE_READY)
  {
    switch (CallbackID)
    {
    case HAL_SCI_TX_BLOCKCOMPLETE_CB_ID :
      hsci->TxBlockCpltCallback = pCallback;
      break;

    case HAL_SCI_TX_HALFBLOCKCOMPLETE_CB_ID :
      hsci->TxHalfBlockCpltCallback = pCallback;
      break;

    case HAL_SCI_TX_SRCCOMPLETE_CB_ID :
      hsci->TxSrcCpltCallback = pCallback;
      break;

    case HAL_SCI_TX_COMPLETE_CB_ID :
      hsci->TxCpltCallback = pCallback;
      break;

    case HAL_SCI_RX_BLOCKCOMPLETE_CB_ID :
      hsci->RxBlockCpltCallback = pCallback;
      break;

    case HAL_SCI_RX_HALFBLOCKCOMPLETE_CB_ID :
      hsci->RxHalfBlockCpltCallback = pCallback;
      break;

    case HAL_SCI_RX_DSTCOMPLETE_CB_ID :
      hsci->RxDstCpltCallback = pCallback;
      break;

    case HAL_SCI_RX_COMPLETE_CB_ID :
      hsci->RxCpltCallback = pCallback;
      break;

    case HAL_SCI_ERROR_CB_ID :
      hsci->ErrorCallback = pCallback;
      break;

    case HAL_SCI_ABORT_COMPLETE_CB_ID :
      hsci->AbortCpltCallback = pCallback;
      break;

    case HAL_SCI_ABORT_TRANSMIT_COMPLETE_CB_ID :
      hsci->AbortTransmitCpltCallback = pCallback;
      break;

    case HAL_SCI_ABORT_RECEIVE_COMPLETE_CB_ID :
      hsci->AbortReceiveCpltCallback = pCallback;
      break;

    case HAL_SCI_WAKEUP_CB_ID :
      hsci->WakeupCallback = pCallback;
      break;

    case HAL_SCI_RX_FIFO_FULL_CB_ID :
      hsci->RxFifoFullCallback = pCallback;
      break;

    case HAL_SCI_TX_FIFO_EMPTY_CB_ID :
      hsci->TxFifoEmptyCallback = pCallback;
      break;

    case HAL_SCI_MSPINIT_CB_ID :
      hsci->MspInitCallback = pCallback;
      break;

    case HAL_SCI_MSPDEINIT_CB_ID :
      hsci->MspDeInitCallback = pCallback;
      break;

    default :
      /* Update the error code */
      hsci->ErrorCode |= HAL_SCI_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else if (hsci->gState == HAL_SCI_STATE_RESET)
  {
    switch (CallbackID)
    {
    case HAL_SCI_MSPINIT_CB_ID :
      hsci->MspInitCallback = pCallback;
      break;

    case HAL_SCI_MSPDEINIT_CB_ID :
      hsci->MspDeInitCallback = pCallback;
      break;

    default :
      /* Update the error code */
      hsci->ErrorCode |= HAL_SCI_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* Update the error code */
    hsci->ErrorCode |= HAL_SCI_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hsci);

  return status;
}

/**
  * @brief  Unregister an SCI Callback
  *         SCI callaback is redirected to the weak predefined callback
  * @param  hsci SCI handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_SCI_TX_BLOCKCOMPLETE_CB_ID Tx Block Complete Callback ID
  *           @arg @ref HAL_SCI_TX_HALFBLOCKCOMPLETE_CB_ID Tx Half Block Complete Callback ID
  *           @arg @ref HAL_SCI_TX_SRCCOMPLETE_CB_ID Tx Source Complete Callback ID
  *           @arg @ref HAL_SCI_TX_COMPLETE_CB_ID Tx Complete Callback ID
  *           @arg @ref HAL_SCI_RX_BLOCKCOMPLETE_CB_ID Rx Block Complete Callback ID
  *           @arg @ref HAL_SCI_RX_HALFBLOCKCOMPLETE_CB_ID Rx Half Block Complete Callback ID
  *           @arg @ref HAL_SCI_RX_DSTCOMPLETE_CB_ID Rx Destination Complete Callback ID
  *           @arg @ref HAL_SCI_RX_COMPLETE_CB_ID Rx Complete Callback ID
  *           @arg @ref HAL_SCI_ERROR_CB_ID Error Callback ID
  *           @arg @ref HAL_SCI_ABORT_COMPLETE_CB_ID Abort Complete Callback ID
  *           @arg @ref HAL_SCI_ABORT_TRANSMIT_COMPLETE_CB_ID Abort Transmit Complete Callback ID
  *           @arg @ref HAL_SCI_ABORT_RECEIVE_COMPLETE_CB_ID Abort Receive Complete Callback ID
  *           @arg @ref HAL_SCI_RX_FIFO_FULL_CB_ID Rx Fifo Full Callback ID
  *           @arg @ref HAL_SCI_TX_FIFO_EMPTY_CB_ID Tx Fifo Empty Callback ID
  *           @arg @ref HAL_SCI_MSPINIT_CB_ID MspInit Callback ID
  *           @arg @ref HAL_SCI_MSPDEINIT_CB_ID MspDeInit Callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_UnRegisterCallback(SCI_HandleTypeDef *hsci, HAL_SCI_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hsci);

  if (HAL_SCI_STATE_READY == hsci->gState)
  {
    switch (CallbackID)
    {
    case HAL_SCI_TX_BLOCKCOMPLETE_CB_ID :
      hsci->TxBlockCpltCallback = HAL_SCI_TxBlockCpltCallback;             /* Legacy weak TxBlockCpltCallback       */
      break;

    case HAL_SCI_TX_HALFBLOCKCOMPLETE_CB_ID :
      hsci->TxHalfBlockCpltCallback = HAL_SCI_TxHalfBlockCpltCallback;     /* Legacy weak TxHalfBlockCpltCallback   */
      break;

    case HAL_SCI_TX_SRCCOMPLETE_CB_ID :
      hsci->TxSrcCpltCallback = HAL_SCI_TxSrcCpltCallback;                 /* Legacy weak  TxSrcCpltCallback        */
      break;

    case HAL_SCI_TX_COMPLETE_CB_ID :
      hsci->TxCpltCallback = HAL_SCI_TxCpltCallback;                       /* Legacy weak TxCpltCallback            */
      break;

    case HAL_SCI_RX_BLOCKCOMPLETE_CB_ID :
      hsci->RxBlockCpltCallback = HAL_SCI_RxBlockCpltCallback;             /* Legacy weak RxBlockCpltCallback       */
      break;

    case HAL_SCI_RX_HALFBLOCKCOMPLETE_CB_ID :
      hsci->RxHalfBlockCpltCallback = HAL_SCI_RxHalfBlockCpltCallback;     /* Legacy weak RxHalfBlockCpltCallback   */
      break;

    case HAL_SCI_RX_DSTCOMPLETE_CB_ID :
      hsci->RxDstCpltCallback = HAL_SCI_RxDstCpltCallback;                 /* Legacy weak RxDstCpltCallback         */
      break;

    case HAL_SCI_RX_COMPLETE_CB_ID :
      hsci->RxCpltCallback = HAL_SCI_RxCpltCallback;                       /* Legacy weak RxCpltCallback            */
      break;

    case HAL_SCI_ERROR_CB_ID :
      hsci->ErrorCallback = HAL_SCI_ErrorCallback;                         /* Legacy weak ErrorCallback             */
      break;

    case HAL_SCI_ABORT_COMPLETE_CB_ID :
      hsci->AbortCpltCallback = HAL_SCI_AbortCpltCallback;                 /* Legacy weak AbortCpltCallback         */
      break;

    case HAL_SCI_ABORT_TRANSMIT_COMPLETE_CB_ID :
      hsci->AbortTransmitCpltCallback = HAL_SCI_AbortTransmitCpltCallback; /* Legacy weak AbortTransmitCpltCallback */
      break;

    case HAL_SCI_ABORT_RECEIVE_COMPLETE_CB_ID :
      hsci->AbortReceiveCpltCallback = HAL_SCI_AbortReceiveCpltCallback;   /* Legacy weak AbortReceiveCpltCallback  */
      break;

    case HAL_SCI_WAKEUP_CB_ID :
      hsci->WakeupCallback = HAL_SCIEx_WakeupCallback;                     /* Legacy weak WakeupCallback         */
      break;

    case HAL_SCI_RX_FIFO_FULL_CB_ID :
      hsci->RxFifoFullCallback = HAL_SCIEx_RxFifoFullCallback;             /* Legacy weak RxFifoFullCallback       */
      break;

    case HAL_SCI_TX_FIFO_EMPTY_CB_ID :
      hsci->TxFifoEmptyCallback = HAL_SCIEx_TxFifoEmptyCallback;           /* Legacy weak TxFifoEmptyCallback      */
      break;

    case HAL_SCI_MSPINIT_CB_ID :
      hsci->MspInitCallback = HAL_SCI_MspInit;                             /* Legacy weak MspInitCallback           */
      break;

    case HAL_SCI_MSPDEINIT_CB_ID :
      hsci->MspDeInitCallback = HAL_SCI_MspDeInit;                         /* Legacy weak MspDeInitCallback         */
      break;

    default :
      /* Update the error code */
      hsci->ErrorCode |= HAL_SCI_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else if (HAL_SCI_STATE_RESET == hsci->gState)
  {
    switch (CallbackID)
    {
    case HAL_SCI_MSPINIT_CB_ID :
      hsci->MspInitCallback = HAL_SCI_MspInit;
      break;

    case HAL_SCI_MSPDEINIT_CB_ID :
      hsci->MspDeInitCallback = HAL_SCI_MspDeInit;
      break;

    default :
      /* Update the error code */
      hsci->ErrorCode |= HAL_SCI_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* Update the error code */
    hsci->ErrorCode |= HAL_SCI_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hsci);

  return status;
}

/**
  * @brief  Register a User SCI Rx Event Callback
  *         To be used instead of the weak predefined callback
  * @param  hsci     SCI handle
  * @param  pCallback Pointer to the Rx Event Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_RegisterRxEventCallback(SCI_HandleTypeDef *hsci, pSCI_RxEventCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    hsci->ErrorCode |= HAL_SCI_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  if (hsci->RxState == HAL_SCI_STATE_READY)
  {
    hsci->RxEventCallback = pCallback;
  }
  else
  {
    hsci->ErrorCode |= HAL_SCI_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  UnRegister the SCI Rx Event Callback
  *         SCI Rx Event Callback is redirected to the weak HAL_SCIEx_RxEventCallback() predefined callback
  * @param  hsci     SCI handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_UnRegisterRxEventCallback(SCI_HandleTypeDef *hsci)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (hsci->RxState == HAL_SCI_STATE_READY)
  {
    hsci->RxEventCallback = HAL_SCIEx_RxEventCallback; /* Legacy weak SCI Rx Event Callback  */
  }
  else
  {
    hsci->ErrorCode |= HAL_SCI_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  return status;
}
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup SCI_Exported_Functions_Group2 IO operation functions
  *  @brief SCI Transmit and Receive functions
  *
  * @{
  */

/**
  * @brief  Sends an amount of data in blocking mode.
  * @note   When Word Length is configured to 9 bits,
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @param  hsci Pointer to a SCI_HandleTypeDef structure that contains
  *               the configuration information for the specified SCI module.
  * @param  pTxData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_Transmit(SCI_HandleTypeDef *hsci, uint8_t *pTxData, uint32_t Size, uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint16_t *pdata16bits;
  uint32_t tickstart = 0U;

  /* Check that a Tx process is not already ongoing */
  if (hsci->gState == HAL_SCI_STATE_READY)
  {
    if ((pTxData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }
    /* In case of 9bits transfer, pData buffer provided as input parameter
       should be aligned on a u16 frontier, as data to be filled into DR will be
       handled through a u16 cast. */
    if ((hsci->Init.WordLength == SCI_WORDLENGTH_9B) && (hsci->Init.Parity == SCI_PARITY_NONE))
    {
      if ((((uint32_t)pTxData) & 1U) != 0U)
      {
        return  HAL_ERROR;
      }
    }
    /* Process Locked */
    __HAL_LOCK(hsci);

    hsci->ErrorCode = HAL_SCI_ERROR_NONE;
    hsci->gState = HAL_SCI_STATE_BUSY_TX;

    /* Init tickstart for timeout managment */
    tickstart = HAL_GetTick();

    hsci->TxXferSize = Size;
    hsci->TxXferCount = Size;

    /* In case of 9bits/No Parity transfer, pData needs to be handled as a uint16_t pointer */
    if ((hsci->Init.WordLength == SCI_WORDLENGTH_9B) && (hsci->Init.Parity == SCI_PARITY_NONE))
    {
      pdata8bits  = NULL;
      pdata16bits = (uint16_t *) pTxData;
    }
    else
    {
      pdata8bits  = pTxData;
      pdata16bits = NULL;
    }

    while (hsci->TxXferCount > 0U)
    {
      if (SCI_WaitOnFlagUntilTimeout(hsci,SCI_FLAG_TXE, RESET, tickstart, Timeout) != HAL_OK)
      {

        hsci->gState = HAL_SCI_STATE_READY;

        return HAL_TIMEOUT;
      }
      if (pdata8bits == NULL)
      {
        hsci->Instance->DR = (uint16_t)(*pdata16bits & 0x01FFU);
        pdata16bits++;
      }
      else
      {
        hsci->Instance->DR = (uint8_t)(*pdata8bits & 0xFFU);
        pdata8bits++;
      }

      hsci->TxXferCount--;
    }

    if (SCI_WaitOnFlagUntilTimeout(hsci, SCI_FLAG_TC, RESET, tickstart, Timeout) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    /* At end of Tx process, restore hsci->gState to Ready */
    hsci->gState = HAL_SCI_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hsci);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Receives an amount of data in blocking mode.
  * @note   When Word Length is configured to 9 bits,
  *         the received data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 available through pData.
  * @param  hsci Pointer to a SCI_HandleTypeDef structure that contains
  *               the configuration information for the specified SCI module.
  * @param  pRxData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be received.
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_Receive(SCI_HandleTypeDef *hsci, uint8_t *pRxData, uint32_t Size, uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint16_t *pdata16bits;
  uint16_t uhMask;
  uint32_t tickstart = 0U;

  /* Check that a Rx process is not already ongoing */
  if (hsci->RxState == HAL_SCI_STATE_READY)
  {
    if ((pRxData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }
    /* In case of 9bits, pData buffer provided as input parameter
       should be aligned on a u16 frontier, as data to be received from RDR will be
       handled through a u16 cast. */
    if ((hsci->Init.WordLength == SCI_WORDLENGTH_9B) && (hsci->Init.Parity == SCI_PARITY_NONE))
    {
      if ((((uint32_t)pRxData) & 1U) != 0U)
      {
        return  HAL_ERROR;
      }
    }
    /* Process Locked */
    __HAL_LOCK(hsci);

    hsci->ErrorCode = HAL_SCI_ERROR_NONE;
    hsci->RxState = HAL_SCI_STATE_BUSY_RX;
    hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

    /* Init tickstart for timeout managment */
    tickstart = HAL_GetTick();

    hsci->RxXferSize = Size;
    hsci->RxXferCount = Size;

    /* Computation of SCI mask to apply to RDR register */
    SCI_MASK_COMPUTATION(hsci);
    uhMask = hsci->Mask;

    /* In case of 9bits, pRxData needs to be handled as a uint16_t pointer */
    if ((hsci->Init.WordLength == SCI_WORDLENGTH_9B) && (hsci->Init.Parity == SCI_PARITY_NONE))
    {
      pdata8bits  = NULL;
      pdata16bits = (uint16_t *) pRxData;
    }
    else
    {
      pdata8bits  = pRxData;
      pdata16bits = NULL;
    }
    
    /* as long as data have to be received */
    while (hsci->RxXferCount > 0U)
    {
      /* Wait for RXNE Flag */
      if (SCI_WaitOnFlagUntilTimeout(hsci, SCI_FLAG_RXNE, RESET, tickstart, Timeout) != HAL_OK)
      {
        hsci->RxState = HAL_SCI_STATE_READY;

        return HAL_TIMEOUT;
      }
      if (pdata8bits == NULL)
      {
        *pdata16bits = (uint16_t)(hsci->Instance->DR & uhMask);
        pdata16bits++;
      }
      else
      {
        *pdata8bits = (uint8_t)(hsci->Instance->DR & (uint8_t)(uhMask &0xFF));
        pdata8bits++;
      }
      hsci->RxXferCount--;
    }
    /* At end of Rx process, restore hsci->gState to Ready */
    hsci->RxState = HAL_SCI_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hsci);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Sends an amount of data in non blocking mode.
  * @note   When Word Length is configured to 9 bits,
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @param  hsci Pointer to a SCI_HandleTypeDef structure that contains
  *               the configuration information for the specified SCI module.
  * @param  pTxData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_Transmit_IT(SCI_HandleTypeDef *hsci, uint8_t *pTxData, uint32_t Size)
{
  /* Check that a Tx process is not already ongoing */
  if (hsci->gState == HAL_SCI_STATE_READY)
  {
    if ((pTxData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(hsci);

    hsci->pTxBuffPtr  = pTxData;
    hsci->TxXferSize  = Size;
    hsci->TxXferCount = Size;
    hsci->TxISR       = NULL;

    hsci->ErrorCode = HAL_SCI_ERROR_NONE;
    hsci->gState    = HAL_SCI_STATE_BUSY_TX;

    /* Configure Tx interrupt processing */
    if (hsci->FifoMode == SCI_FIFOMODE_ENABLE)
    {
      /* Set the Tx SR function pointer according to the data word length */
      if ((hsci->Init.WordLength == SCI_WORDLENGTH_9B) && (hsci->Init.Parity == SCI_PARITY_NONE))
      {
        hsci->TxISR = SCI_TxSR_16BIT_FIFOEN;
      }
      else
      {
        hsci->TxISR = SCI_TxSR_8BIT_FIFOEN;
      }

      /* Process Unlocked */
      __HAL_UNLOCK(hsci);

      /* Enable the TX FIFO threshold interrupt */
      __HAL_SCI_ENABLE_IT(hsci, SCI_IT_TXFT);
    }
    else
    {
      /* Set the Tx SR function pointer according to the data word length */
      if ((hsci->Init.WordLength == SCI_WORDLENGTH_9B) && (hsci->Init.Parity == SCI_PARITY_NONE))
      {
        hsci->TxISR = SCI_TxSR_16BIT;
      }
      else
      {
        hsci->TxISR = SCI_TxSR_8BIT;
      }

      __HAL_UNLOCK(hsci);

      /* Enable the Transmit Data Register Empty interrupt */
      __HAL_SCI_ENABLE_IT(hsci, SCI_IT_TXE);
    }

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Receives an amount of data in non blocking mode.
  * @note   When Word Length is configured to 9 bits,
  *         the received data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 available through pData.
  * @param  hsci Pointer to a SCI_HandleTypeDef structure that contains
  *               the configuration information for the specified SCI module.
  * @param  pRxData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_Receive_IT(SCI_HandleTypeDef *hsci, uint8_t *pRxData, uint32_t Size)
{
  /* Check that a Rx process is not already ongoing */
  if (hsci->RxState == HAL_SCI_STATE_READY)
  {
    if ((pRxData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Set Reception type to Standard reception */
    hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

    /* Check that SCI RTOEN bit is set */
    if (READ_BIT(hsci->Instance->CR2, USART_CR2_RTOEN) != 0U)
    {
      /* Enable the SCI Receiver Timeout Interrupt */
      SET_BIT(hsci->Instance->CR3, USART_CR3_RTOIE);
    }

    return (SCI_Start_Receive_IT(hsci, pRxData, Size));
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Send an amount of data in DMA mode.
  * @note   When SCI parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pTxData.
  * @param  hsci SCI handle.
  * @param  pTxData pointer to data buffer (u8 or u16 data elements).
  * @param  Size amount of data elements (u8 or u16 or u32) to be sent.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_Transmit_DMA(SCI_HandleTypeDef *hsci, uint8_t *pTxData, uint32_t Size)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check that a Tx process is not already ongoing */
  if (hsci->gState == HAL_SCI_STATE_READY)
  {
    if ((pTxData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(hsci);

    hsci->pTxBuffPtr = pTxData;
    hsci->TxXferSize = Size;
    hsci->TxXferCount = Size;

    hsci->ErrorCode = HAL_SCI_ERROR_NONE;
    hsci->gState = HAL_SCI_STATE_BUSY_TX;

    if (hsci->hdmatx != NULL)
    {
      /* Set the SCI DMA transfer complete callback */
      hsci->hdmatx->XferCpltCallback = SCI_DMATransmitCplt;

      /* Set the SCI DMA Half Block transfer complete callback */
      hsci->hdmatx->XferHalfBlockCpltCallback = SCI_DMATxHalfBlockCplt;

      /* Set the SCI DMA Block transfer complete callback */
      hsci->hdmatx->XferBlockCpltCallback = SCI_DMATxBlockCplt;

      /* Set the SCI Source transaction complete callback */
      hsci->hdmatx->XferSrcTranCpltCallback = SCI_DMATransmitSrcCplt;

      /* Set the DMA error callback */
      hsci->hdmatx->XferErrorCallback = SCI_DMAError;

      /* Set the DMA error callback */
      hsci->hdmatx->XferAbortCallback = NULL;

      /* Enable the SCI transmit DMA channel */
      status = HAL_DMA_Start_IT(hsci->hdmatx, (uint32_t)hsci->pTxBuffPtr, (uint32_t)&hsci->Instance->DR, Size);
    }

    if (status == HAL_OK)
    {
      /* Clear the TC flag */
      __HAL_SCI_CLEAR_FLAG(hsci, SCI_FLAG_TC);

      /* Process Unlocked */
      __HAL_UNLOCK(hsci);

      /* Enable the DMA transfer for transmit request by setting the DMAT bit
         in the USART CR3 register */
      __disable_irq();
      CLEAR_BIT(hsci->Instance->CR1, USART_CR1_TE);
      SET_BIT(hsci->Instance->CR1, USART_CR1_TE);
      SET_BIT(hsci->Instance->CR3, USART_CR3_DMAT);
      __enable_irq();

      return HAL_OK;
    }
    else
    {
      /* Set error code to DMA */
      hsci->ErrorCode = HAL_SCI_ERROR_DMA;

      /* Process Unlocked */
      __HAL_UNLOCK(hsci);

      /* Restore hsci->gState to ready */
      hsci->gState = HAL_SCI_STATE_READY;

      return HAL_ERROR;
    }
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in DMA mode.
  * @note   When the SCI parity is enabled (PCE = 1), the received data contain
  *         the parity bit (MSB position).
  * @note   The SCI DMA transmit channel must be configured in order to generate the clock for the slave.
  * @note   When SCI parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the received data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 available through pRxData.
  * @param  hsci SCI handle.
  * @param  pRxData pointer to data buffer (u8 or u16 data elements).
  * @param  Size amount of data elements (u8 or u16 or u32) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_Receive_DMA(SCI_HandleTypeDef *hsci, uint8_t *pRxData, uint32_t Size)
{
  /* Check that a Rx process is not already ongoing */
  if (hsci->RxState == HAL_SCI_STATE_READY)
  {
    if ((pRxData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Set Reception type to Standard reception */
    hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

    /* Check that SCI RTOEN bit is set */
    if (READ_BIT(hsci->Instance->CR2, USART_CR2_RTOEN) != 0U)
    {
      /* Enable the SCI Receiver Timeout Interrupt */
      SET_BIT(hsci->Instance->CR3, USART_CR3_RTOIE);
    }

    /* In case of 9bits/No Parity transfer, pData buffer provided as input parameter
       should be aligned on a u16 frontier, as data copy from RDR will be
       handled by DMA from a u16 frontier. */
    if ((hsci->Init.WordLength == SCI_WORDLENGTH_9B) && (hsci->Init.Parity == SCI_PARITY_NONE))
    {
      if ((((uint32_t)pRxData) & 1U) != 0U)
      {
        return  HAL_ERROR;
      }
    }

    return (SCI_Start_Receive_DMA(hsci, pRxData, Size));
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Pause the DMA Transfer.
  * @param  hsci SCI handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_DMAPause(SCI_HandleTypeDef *hsci)
{
  uint32_t dmarequest = 0x00U;

  /* Process Locked */
  __HAL_LOCK(hsci);
  
  dmarequest = HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAT);
  if (dmarequest && (hsci->gState == HAL_SCI_STATE_BUSY_TX))
  {
    /* Disable the SCI DMA Tx request */
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAT);
  }
  
  dmarequest = HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAR);
  if (dmarequest && (hsci->RxState == HAL_SCI_STATE_BUSY_RX))
  {

    /* Disable PE and ERR (Frame error, noise error, overrun error) interrupts */
    CLEAR_BIT(hsci->Instance->CR1, USART_CR1_PEIE);
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_EIE);

    /* Disable the SCI DMA Rx request */
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAR);
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief Resume the DMA Transfer.
  * @param  hsci SCI handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_DMAResume(SCI_HandleTypeDef *hsci)
{
  /* Process Locked */
  __HAL_LOCK(hsci);

  if (hsci->gState == HAL_SCI_STATE_BUSY_TX)
  {
    /* Enable the SCI DMA Tx request */
    SET_BIT(hsci->Instance->CR3, USART_CR3_DMAT);
  }
  if (hsci->RxState == HAL_SCI_STATE_BUSY_RX)
  {
    /* Clear the Overrun flag before resuming the Rx transfer*/
    __HAL_SCI_CLEAR_OREFLAG(hsci);

    /* Re-enable PE and ERR (Frame error, noise error, overrun error) interrupts */
    SET_BIT(hsci->Instance->CR1, USART_CR1_PEIE);
    SET_BIT(hsci->Instance->CR3, USART_CR3_EIE);

    /* Enable the SCI DMA Rx request  before the DMA Tx request */
    SET_BIT(hsci->Instance->CR3, USART_CR3_DMAR);
  }
  
  /* Process Unlocked */
  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief Stop the DMA Transfer.
  * @param  hsci SCI handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_DMAStop(SCI_HandleTypeDef *hsci)
{
  uint32_t dmarequest = 0x00U;
  /* The Lock is not implemented on this API to allow the user application
     to call the HAL SCI API under callbacks HAL_SCI_TxCpltCallback() / HAL_SCI_RxCpltCallback() /
     HAL_SCI_TxHalfCpltCallback / HAL_SCI_RxHalfCpltCallback:
     indeed, when HAL_DMA_Abort() API is called, the DMA TX/RX Transfer or Half Transfer complete
     interrupt is generated if the DMA transfer interruption occurs at the middle or at the end of
     the stream and the corresponding call back is executed. */

  /* Stop SCI DMA Tx request if ongoing */
  dmarequest = HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAT);
  if ((hsci->gState == HAL_SCI_STATE_BUSY_TX) && dmarequest)
  {
    /* Abort the SCI DMA Tx channel */
    if (hsci->hdmatx != NULL)
    {
      if (HAL_DMA_Abort(hsci->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hsci->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hsci->ErrorCode = HAL_SCI_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAT);
    SCI_EndTxTransfer(hsci);
  }

  /* Stop SCI DMA Rx request if ongoing */
  dmarequest = HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAR);
  if ((hsci->RxState == HAL_SCI_STATE_BUSY_RX) && dmarequest)
  {
    /* Abort the SCI DMA Rx channel */
    if (hsci->hdmarx != NULL)
    {
      if (HAL_DMA_Abort(hsci->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hsci->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hsci->ErrorCode = HAL_SCI_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAR);
    SCI_EndRxTransfer(hsci);
  }

  return HAL_OK;
}

/**
  * @brief  Abort ongoing transfers (blocking mode).
  * @param  hsci SCI handle.
  * @note   This procedure could be used for aborting any ongoing transfer started in Interrupt mode.
  *         This procedure performs following operations :
  *           - Disable SCI Interrupts (Tx and Rx)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
*/
HAL_StatusTypeDef HAL_SCI_Abort(SCI_HandleTypeDef *hsci)
{
  /* Disable TXEIE, TCIE, RXNE, RXFT, TXFT, PE and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE   | USART_CR1_TXEIE | USART_CR1_TCIE));
  CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_EIE    | USART_CR3_RXFTIE | USART_CR3_TXFTIE));

  /* If Reception till IDLE event was ongoing, disable IDLEIE interrupt */
  if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
  {
    CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_IDLEIE));
  }

  /* Disable the SCI DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAT))
  {
    /* Abort the SCI DMA Tx channel: use blocking DMA Abort API (no callback) */
    if (hsci->hdmatx != NULL)
    {
      /* Set the SCI DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      hsci->hdmatx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(hsci->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hsci->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hsci->ErrorCode = HAL_SCI_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAT);
  }

  /* Disable the SCI DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAR))
  {
    /* Abort the SCI DMA Rx channel: use blocking DMA Abort API (no callback) */
    if (hsci->hdmarx != NULL)
    {
      /* Set the SCI DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      hsci->hdmarx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(hsci->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hsci->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hsci->ErrorCode = HAL_SCI_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
    /* Disable the SCI DMA Rx request if enabled */
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAR);
  }

  /* Reset Tx and Rx transfer counters */
  hsci->TxXferCount = 0x00U;
  hsci->RxXferCount = 0x00U;

  /* Clear the Error flags IDLE + ORE NE FE PE bit */
  __HAL_SCI_CLEAR_FEFLAG(hsci);

  /* Flush the whole TX FIFO (if needed) */
  if (hsci->FifoMode == SCI_FIFOMODE_ENABLE)
  {
    __HAL_SCI_SEND_REQ(hsci, SCI_TXDATA_FLUSH_REQUEST);
  }

  /* Discard the received data */
  __HAL_SCI_SEND_REQ(hsci, SCI_RXDATA_FLUSH_REQUEST);

  /* Restore hsci->gState and hsci->RxState to Ready */
  hsci->gState  = HAL_SCI_STATE_READY;
  hsci->RxState = HAL_SCI_STATE_READY;
  hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

  /* Reset Handle ErrorCode to No Error */
  hsci->ErrorCode = HAL_SCI_ERROR_NONE;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Transmit transfer (blocking mode).
  * @param  hsci SCI handle.
  * @note   This procedure could be used for aborting any ongoing Tx transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable SCI Interrupts (Tx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort (in case of transfer in DMA mode)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
*/
HAL_StatusTypeDef HAL_SCI_AbortTransmit(SCI_HandleTypeDef *hsci)
{
  /* Disable TXEIE and TCIE interrupts */
  CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_TXEIE | USART_CR1_TCIE));
  CLEAR_BIT(hsci->Instance->CR3, USART_CR3_TXFTIE);

  /* Disable the SCI DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAT))
  {
    /* Abort the SCI DMA Tx channel : use blocking DMA Abort API (no callback) */
    if (hsci->hdmatx != NULL)
    {
      /* Set the SCI DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      hsci->hdmatx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(hsci->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hsci->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hsci->ErrorCode = HAL_SCI_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAT);
  }

  /* Reset Tx transfer counter */
  hsci->TxXferCount = 0x00U;

  /* Flush the whole TX FIFO (if needed) */
  if (hsci->FifoMode == SCI_FIFOMODE_ENABLE)
  {
    __HAL_SCI_SEND_REQ(hsci, SCI_TXDATA_FLUSH_REQUEST);
  }

  /* Restore hsci->gState to Ready */
  hsci->gState = HAL_SCI_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Receive transfer (blocking mode).
  * @param  hsci SCI handle.
  * @note   This procedure could be used for aborting any ongoing Rx transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable SCI Interrupts (Rx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort (in case of transfer in DMA mode)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
*/
HAL_StatusTypeDef HAL_SCI_AbortReceive(SCI_HandleTypeDef *hsci)
{
  /* Disable RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));
  CLEAR_BIT(hsci->Instance->CR3, USART_CR3_EIE | USART_CR3_RXFTIE);

  /* Disable the SCI DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAR))
  {
    /* Abort the SCI DMA Rx channel : use blocking DMA Abort API (no callback) */
    if (hsci->hdmarx != NULL)
    {
      /* Set the SCI DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      hsci->hdmarx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(hsci->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hsci->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hsci->ErrorCode = HAL_SCI_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAR);
  }

  /* Reset Rx transfer counter */
  hsci->RxXferCount = 0x00U;

  /* Clear the Error flags */
  __HAL_SCI_CLEAR_PEFLAG(hsci);

  /* Discard the received data */
  __HAL_SCI_SEND_REQ(hsci, SCI_RXDATA_FLUSH_REQUEST);

  /* Restore hsci->RxState to Ready */
  hsci->RxState = HAL_SCI_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing transfers (Interrupt mode).
  * @param  hsci SCI handle.
  * @note   This procedure could be used for aborting any ongoing transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable SCI Interrupts (Tx and Rx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort_IT (in case of transfer in DMA mode)
  *           - Set handle State to READY
  *           - At abort completion, call user abort complete callback
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_Abort_IT(SCI_HandleTypeDef *hsci)
{
  uint32_t abortcplt = 1U;

  /* Disable TXEIE, TCIE, RXNE, RXFT, TXFT, PE and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE   | USART_CR1_TXEIE | USART_CR1_TCIE));
  CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_EIE    | USART_CR3_RXFTIE | USART_CR3_TXFTIE));

  /* If Reception till IDLE event was ongoing, disable IDLEIE interrupt */
  if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
  {
    CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_IDLEIE));
  }

  /* If DMA Tx and/or DMA Rx Handles are associated to SCI Handle, DMA Abort complete callbacks should be initialised
     before any call to DMA Abort functions */
  /* DMA Tx Handle is valid */
  if (hsci->hdmatx != NULL)
  {
    /* Set DMA Abort Complete callback if SCI DMA Tx request if enabled.
       Otherwise, set it to NULL */
    if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAT))
    {
      hsci->hdmatx->XferAbortCallback = SCI_DMATxAbortCallback;
    }
    else
    {
      hsci->hdmatx->XferAbortCallback = NULL;
    }
  }
  /* DMA Rx Handle is valid */
  if (hsci->hdmarx != NULL)
  {
    /* Set DMA Abort Complete callback if SCI DMA Rx request if enabled.
       Otherwise, set it to NULL */
    if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAR))
    {
      hsci->hdmarx->XferAbortCallback = SCI_DMARxAbortCallback;
    }
    else
    {
      hsci->hdmarx->XferAbortCallback = NULL;
    }
  }

  /* Disable the SCI DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAT))
  {
    /* Abort the SCI DMA Tx channel : use non blocking DMA Abort API (callback) */
    if (hsci->hdmatx != NULL)
    {
      /* SCI Tx DMA Abort callback has already been initialised :
         will lead to call HAL_SCI_AbortCpltCallback() at end of DMA abort procedure */

      /* Abort DMA TX */
      if (HAL_DMA_Abort_IT(hsci->hdmatx) != HAL_OK)
      {
        hsci->hdmatx->XferAbortCallback = NULL;
      }
      else
      {
        abortcplt = 0U;
      }
    }
    /* Disable DMA Tx at SCI level */
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAT);
  }

  /* Disable the SCI DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAR))
  {
    /* Abort the SCI DMA Rx channel : use non blocking DMA Abort API (callback) */
    if (hsci->hdmarx != NULL)
    {
      /* SCI Rx DMA Abort callback has already been initialised :
         will lead to call HAL_SCI_AbortCpltCallback() at end of DMA abort procedure */

      /* Abort DMA RX */
      if (HAL_DMA_Abort_IT(hsci->hdmarx) != HAL_OK)
      {
        hsci->hdmarx->XferAbortCallback = NULL;
        abortcplt = 1U;
      }
      else
      {
        abortcplt = 0U;
      }
    }
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAR);
  }

  /* if no DMA abort complete callback execution is required => call user Abort Complete callback */
  if (abortcplt == 1U)
  {
    /* Reset Tx and Rx transfer counters */
    hsci->TxXferCount = 0U;
    hsci->RxXferCount = 0U;

    /* Clear ISR function pointers */
    hsci->RxISR = NULL;
    hsci->TxISR = NULL;

    /* Reset errorCode */
    hsci->ErrorCode = HAL_SCI_ERROR_NONE;

    /* Clear the Error flags */
  __HAL_SCI_CLEAR_PEFLAG(hsci);

    /* Flush the whole TX FIFO (if needed) */
    if (hsci->FifoMode == SCI_FIFOMODE_ENABLE)
    {
      __HAL_SCI_SEND_REQ(hsci, SCI_TXDATA_FLUSH_REQUEST);
    }

    /* Discard the received data */
    __HAL_SCI_SEND_REQ(hsci, SCI_RXDATA_FLUSH_REQUEST);

    /* Restore hsci->gState to Ready */
    hsci->gState   = HAL_SCI_STATE_READY;
    hsci->RxState  = HAL_SCI_STATE_READY;
    hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
    /* Call registered Abort Complete Callback */
    hsci->AbortCpltCallback(hsci);
#else
    /* Call legacy weak Abort Complete Callback */
    HAL_SCI_AbortCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
  }

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Transmit transfer (Interrupt mode).
  * @param  hsci SCI handle.
  * @note   This procedure could be used for aborting any ongoing Tx transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable SCI Interrupts (Tx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort_IT (in case of transfer in DMA mode)
  *           - Set handle State to READY
  *           - At abort completion, call user abort complete callback
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_AbortTransmit_IT(SCI_HandleTypeDef *hsci)
{
  /* Disable interrupts */
  CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_TCIE | USART_CR1_TXEIE));
  CLEAR_BIT(hsci->Instance->CR3, USART_CR3_TXFTIE);

  /* Disable the SCI DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAT))
  {
    /* Abort the SCI DMA Tx channel : use non blocking DMA Abort API (callback) */
    if (hsci->hdmatx != NULL)
    {
      /* Set the SCI DMA Abort callback :
         will lead to call HAL_SCI_AbortCpltCallback() at end of DMA abort procedure */
      hsci->hdmatx->XferAbortCallback = SCI_DMATxOnlyAbortCallback;

      /* Abort DMA TX */
      if (HAL_DMA_Abort_IT(hsci->hdmatx) != HAL_OK)
      {
        /* Call Directly hsci->hdmatx->XferAbortCallback function in case of error */
        hsci->hdmatx->XferAbortCallback(hsci->hdmatx);
      }
    }
    else
    {
      /* Reset Tx transfer counter */
      hsci->TxXferCount = 0U;

      /* Clear TxISR function pointers */
      hsci->TxISR = NULL;

      /* Restore hsci->gState to Ready */
      hsci->gState = HAL_SCI_STATE_READY;

      /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
      /* Call registered Abort Transmit Complete Callback */
      hsci->AbortTransmitCpltCallback(hsci);
#else
      /* Call legacy weak Abort Transmit Complete Callback */
      HAL_SCI_AbortTransmitCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
    }
    /* Disable the SCI DMA Tx request if enabled */
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAT);
  }
  else
  {
    /* Reset Tx transfer counter */
    hsci->TxXferCount = 0U;

    /* Clear TxISR function pointers */
    hsci->TxISR = NULL;

    /* Flush the whole TX FIFO (if needed) */
    if (hsci->FifoMode == SCI_FIFOMODE_ENABLE)
    {
      __HAL_SCI_SEND_REQ(hsci, SCI_TXDATA_FLUSH_REQUEST);
    }

    /* Restore hsci->gState to Ready */
    hsci->gState = HAL_SCI_STATE_READY;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
    /* Call registered Abort Transmit Complete Callback */
    hsci->AbortTransmitCpltCallback(hsci);
#else
    /* Call legacy weak Abort Transmit Complete Callback */
    HAL_SCI_AbortTransmitCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
  }

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Receive transfer (Interrupt mode).
  * @param  hsci SCI handle.
  * @note   This procedure could be used for aborting any ongoing Rx transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable SCI Interrupts (Rx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort_IT (in case of transfer in DMA mode)
  *           - Set handle State to READY
  *           - At abort completion, call user abort complete callback
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_AbortReceive_IT(SCI_HandleTypeDef *hsci)
{
  /* Disable RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_PEIE | USART_CR1_RXNEIE));
  CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_EIE | USART_CR3_RXFTIE));

  /* If Reception till IDLE event was ongoing, disable IDLEIE interrupt */
  if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
  {
    CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_IDLEIE));
  }
  /* Disable the SCI DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAR))
  {
    /* Abort the SCI DMA Rx channel : use non blocking DMA Abort API (callback) */
    if (hsci->hdmarx != NULL)
    {
      /* Set the SCI DMA Abort callback :
         will lead to call HAL_SCI_AbortCpltCallback() at end of DMA abort procedure */
      hsci->hdmarx->XferAbortCallback = SCI_DMARxOnlyAbortCallback;

      /* Abort DMA RX */
      if (HAL_DMA_Abort_IT(hsci->hdmarx) != HAL_OK)
      {
        /* Call Directly hsci->hdmarx->XferAbortCallback function in case of error */
        hsci->hdmarx->XferAbortCallback(hsci->hdmarx);
      }
    }
    else
    {
      /* Reset Rx transfer counter */
      hsci->RxXferCount = 0U;

      /* Clear RxISR function pointer */
      hsci->pRxBuffPtr = NULL;

      /* Clear the Error flags */
      __HAL_SCI_CLEAR_PEFLAG(hsci);

      /* Discard the received data */
      __HAL_SCI_SEND_REQ(hsci, SCI_RXDATA_FLUSH_REQUEST);

      /* Restore hsci->RxState to Ready */
      hsci->RxState = HAL_SCI_STATE_READY;
      hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

      /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
      /* Call registered Abort Receive Complete Callback */
      hsci->AbortReceiveCpltCallback(hsci);
#else
      /* Call legacy weak Abort Receive Complete Callback */
      HAL_SCI_AbortReceiveCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
    }
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAR);
  }
  else
  {
    /* Reset Rx transfer counter */
    hsci->RxXferCount = 0U;

    /* Clear RxISR function pointer */
    hsci->pRxBuffPtr = NULL;

    /* Clear the Error flags */
    __HAL_SCI_CLEAR_PEFLAG(hsci);

    /* Restore hsci->RxState to Ready */
    hsci->RxState = HAL_SCI_STATE_READY;
    hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
    /* Call registered Abort Receive Complete Callback */
    hsci->AbortReceiveCpltCallback(hsci);
#else
    /* Call legacy weak Abort Receive Complete Callback */
    HAL_SCI_AbortReceiveCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
  }

  return HAL_OK;
}

/**
  * @brief  This function handles SCI interrupt request.
  * @param  hsci  Pointer to a SCI_HandleTypeDef structure that contains
  *                the configuration information for the specified SCI module.
  * @note   Depending on devices and packages, DMA may not be available.
  *         Refer to device datasheet for DMA availability.
  * @retval None
  */
void HAL_SCI_IRQHandler(SCI_HandleTypeDef *hsci)
{
  uint32_t isrflags   = READ_REG(hsci->Instance->SR);
  uint32_t cr1its     = READ_REG(hsci->Instance->CR1);
  uint32_t cr3its     = READ_REG(hsci->Instance->CR3);
  uint32_t errorflags = 0x00U;
  uint32_t dmarequest = 0x00U;

  /* If no error occurs */
  errorflags = (isrflags & (uint32_t)(USART_SR_PE | USART_SR_FE | USART_SR_ORE | USART_SR_NE | USART_SR_RTOF));
  if (errorflags == RESET)
  {
    /* SCI in mode Receiver -------------------------------------------------*/
    if (((isrflags & USART_SR_RXNE) != RESET) && (((cr1its & USART_CR1_RXNEIE) != RESET) || ((cr3its & USART_CR3_RXFTIE) != 0U)))
    {
      if (hsci->RxISR != NULL)
      {
        hsci->RxISR(hsci);
      }
      return;
    }
  }

  /* If some errors occur */
  if ((errorflags != RESET) && (((cr3its & (USART_CR3_RXFTIE | USART_CR3_EIE | USART_CR3_RTOIE)) != RESET) || ((cr1its & (USART_CR1_RXNEIE | USART_CR1_PEIE)) != RESET)))
  {
    /* SCI parity error interrupt occurred ----------------------------------*/
    if (((isrflags & USART_SR_PE) != RESET) && ((cr1its & USART_CR1_PEIE) != RESET))
    {
      hsci->ErrorCode |= HAL_SCI_ERROR_PE;
    }

    /* SCI noise error interrupt occurred -----------------------------------*/
    if (((isrflags & USART_SR_NE) != RESET) && ((cr3its & USART_CR3_EIE) != RESET))
    {
      hsci->ErrorCode |= HAL_SCI_ERROR_NE;
    }

    /* SCI frame error interrupt occurred -----------------------------------*/
    if (((isrflags & USART_SR_FE) != RESET) && ((cr3its & USART_CR3_EIE) != RESET))
    {
      hsci->ErrorCode |= HAL_SCI_ERROR_FE;
    }

    /* SCI Over-Run interrupt occurred --------------------------------------*/
    if (((isrflags & USART_SR_ORE) != RESET) && (((cr1its & USART_CR1_RXNEIE) != 0U) || ((cr3its & (USART_CR3_RXFTIE | USART_CR3_EIE)) != RESET)))
    {
      hsci->ErrorCode |= HAL_SCI_ERROR_ORE;
    }

    /* SCI Receiver Timeout interrupt occurred ---------------------------------*/
    if (((isrflags & USART_SR_RTOF) != 0U) && ((cr3its & USART_CR3_RTOIE) != 0U))
    {
      __HAL_SCI_CLEAR_RTOFLAG(hsci);
      hsci->ErrorCode |= HAL_SCI_ERROR_RTO;
    }

    /* Call SCI Error Call back function if need be --------------------------*/
    if (hsci->ErrorCode != HAL_SCI_ERROR_NONE)
    {
      /* SCI in mode Receiver -----------------------------------------------*/
      if (((isrflags & USART_SR_RXNE) != RESET) && (((cr1its & USART_CR1_RXNEIE) != RESET) || ((cr3its & USART_CR3_RXFTIE) != 0U)))
      {
        if (hsci->RxISR != NULL)
        {
          hsci->RxISR(hsci);
        }
      }

      /* If Overrun error occurs, or if any error occurs in DMA mode reception,
         consider error as blocking */
      dmarequest = HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAR);
      if (((hsci->ErrorCode & HAL_SCI_ERROR_ORE) != RESET) || dmarequest)
      {
        /* Blocking error : transfer is aborted
           Set the SCI state ready to be able to start again the process,
           Disable Rx Interrupts, and disable Rx DMA request, if ongoing */
        SCI_EndRxTransfer(hsci);

        /* Disable the SCI DMA Rx request if enabled */
        if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAR))
        {
          /* Abort the SCI DMA Rx channel */
          if (hsci->hdmarx != NULL)
          {
            /* Set the SCI DMA Abort callback :
               will lead to call HAL_SCI_ErrorCallback() at end of DMA abort procedure */
            hsci->hdmarx->XferAbortCallback = SCI_DMAAbortOnError;

            /* Abort DMA RX */
            if (HAL_DMA_Abort_IT(hsci->hdmarx) != HAL_OK)
            {
              /* Call Directly XferAbortCallback function in case of error */
              hsci->hdmarx->XferAbortCallback(hsci->hdmarx);
            }
          }
          else
          {
            /* Call user error callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
            /*Call registered error callback*/
            hsci->ErrorCallback(hsci);
#else
            /*Call legacy weak error callback*/
            HAL_SCI_ErrorCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
          }
          CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAR);
        }
        else
        {
          /* Call user error callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
          /*Call registered error callback*/
          hsci->ErrorCallback(hsci);
#else
          /*Call legacy weak error callback*/
          HAL_SCI_ErrorCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
        }
      }
      else
      {
        /* Non Blocking error : transfer could go on.
           Error is notified to user through user error callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
        /*Call registered error callback*/
        hsci->ErrorCallback(hsci);
#else
        /*Call legacy weak error callback*/
        HAL_SCI_ErrorCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */

        hsci->ErrorCode = HAL_SCI_ERROR_NONE;
      }
    }
    return;
  } /* End if some error occurs */

  /* Check current reception Mode :
     If Reception till IDLE event has been selected : */
  if ((hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
      && ((isrflags & USART_SR_IDLE) != RESET) && ((cr1its & USART_CR1_IDLEIE) != RESET))
  {
    __HAL_SCI_CLEAR_IDLEFLAG(hsci);
        /* Check if DMA mode is enabled in SCI */
    if (HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAR))
    {
      /* DMA mode enabled */
      /* Check received length : If all expected data are received, do nothing,
         (DMA cplt callback will be called).
         Otherwise, if at least one data has already been received, IDLE event is to be notified to user */
      uint32_t nb_remaining_rx_data = hsci->hdmarx->RemainLen;
      if ((nb_remaining_rx_data > 0U)
          && (nb_remaining_rx_data < hsci->RxXferSize))
      {
        /* Reception is not complete */
        hsci->RxXferCount = nb_remaining_rx_data;

        /* In Normal mode, end DMA xfer and HAL SCI Rx process*/
        if (hsci->hdmarx->Init.Mode != DMA_CIRCULAR)
        {
          /* Disable PE and ERR (Frame error, noise error, overrun error) interrupts */
          CLEAR_BIT(hsci->Instance->CR1, USART_CR1_PEIE);
          CLEAR_BIT(hsci->Instance->CR3, USART_CR3_EIE);

          /* Disable the DMA transfer for the receiver request by resetting the DMAR bit
             in the USART CR3 register */
          CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAR);

          /* At end of Rx process, restore hsci->RxState to Ready */
          hsci->RxState = HAL_SCI_STATE_READY;
          hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

          CLEAR_BIT(hsci->Instance->CR1, USART_CR1_IDLEIE);

          /* Last bytes received, so no need as the abort is immediate */
          (void)HAL_DMA_Abort(hsci->hdmarx);
        }
        /* Initialize type of RxEvent that correspond to RxEvent callback execution;
           In this case, Rx Event type is Idle Event */
        hsci->RxEventType = HAL_SCI_RXEVENT_IDLE;

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
        /*Call registered Rx Event callback*/
        hsci->RxEventCallback(hsci, (hsci->RxXferSize - hsci->RxXferCount));
#else
        /*Call legacy weak Rx Event callback*/
        HAL_SCIEx_RxEventCallback(hsci, (hsci->RxXferSize - hsci->RxXferCount));
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */
      }
      return;
    }
    else
    {
      /* DMA mode not enabled */
      /* Check received length : If all expected data are received, do nothing.
         Otherwise, if at least one data has already been received, IDLE event is to be notified to user */
      uint32_t nb_rx_data = hsci->RxXferSize - hsci->RxXferCount;
      if ((hsci->RxXferCount > 0U)
          && (nb_rx_data > 0U))
      {
        /* Disable the SCI Parity Error Interrupt and RXNE interrupts */
        CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));

        /* Disable the SCI Error Interrupt:(Frame error, noise error, overrun error) and RX FIFO Threshold interrupt */
        CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_EIE | USART_CR3_RXFTIE));

        /* Rx process is completed, restore hsci->RxState to Ready */
        hsci->RxState = HAL_SCI_STATE_READY;
        hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

        /* Clear RxISR function pointer */
        hsci->RxISR = NULL;

        CLEAR_BIT(hsci->Instance->CR1, USART_CR1_IDLEIE);

        /* Initialize type of RxEvent that correspond to RxEvent callback execution;
           In this case, Rx Event type is Idle Event */
        hsci->RxEventType = HAL_SCI_RXEVENT_IDLE;

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
        /*Call registered Rx complete callback*/
        hsci->RxEventCallback(hsci, nb_rx_data);
#else
        /*Call legacy weak Rx Event callback*/
        HAL_SCIEx_RxEventCallback(hsci, nb_rx_data);
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */
      }
      return;
    }
  }

  /* SCI in mode Transmitter ------------------------------------------------*/
  if (((isrflags & USART_SR_TXE) != RESET) && (((cr1its & USART_CR1_TXEIE) != RESET) || ((cr3its & USART_CR3_TXFTIE) != RESET)))
  {
    if (hsci->TxISR != NULL)
    {
      hsci->TxISR(hsci);
    }
    return;
  }

  /* SCI in mode Transmitter end --------------------------------------------*/
  if (((isrflags & USART_SR_TC) != RESET) && ((cr1its & USART_CR1_TCIE) != RESET))
  {
    SCI_EndTransmit_IT(hsci);
    return;
  }
  
  /* SCI TX Fifo Empty occurred ----------------------------------------------*/
  if (((isrflags & USART_SR_TXFE) != 0U) && ((cr3its & USART_CR3_TXFEIE) != RESET))
  {
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
    /* Call registered Tx Fifo Empty Callback */
    hsci->TxFifoEmptyCallback(hsci);
#else
    /* Call legacy weak Tx Fifo Empty Callback */
    HAL_SCIEx_TxFifoEmptyCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
    return;
  }

  /* SCI RX Fifo Full occurred ----------------------------------------------*/
  if (((isrflags & USART_SR_RXFF) != 0U) && ((cr3its & USART_CR3_RXFFIE) != RESET))
  {
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
    /* Call registered Rx Fifo Full Callback */
    hsci->RxFifoFullCallback(hsci);
#else
    /* Call legacy weak Rx Fifo Full Callback */
    HAL_SCIEx_RxFifoFullCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
    return;
  }
}

/**
  * @brief  Tx Transfer completed callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_TxCpltCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCI_TxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx Half Block Transfer completed callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_TxHalfBlockCpltCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_SCI_TxHalfBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx Block Transfer completed callback.
  * @param hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_TxBlockCpltCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_SCI_TxBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx source transaction completed callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_TxSrcCpltCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_SCI_TxSrcCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Transfer completed callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_RxCpltCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_SCI_RxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Half Block Transfer completed callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_RxHalfBlockCpltCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCI_RxHalfBlockCpltCallback can be implemented in the user file
   */
}

/**
  * @brief  Rx Block Transfer completed callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_RxBlockCpltCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCI_RxBlockCpltCallback can be implemented in the user file
   */
}

/**
  * @brief  Rx destination Transaction completed callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_RxDstCpltCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCI_RxDstCpltCallback can be implemented in the user file
   */
}

/**
  * @brief  SCI error callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_ErrorCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCI_ErrorCallback can be implemented in the user file.
   */
}

/**
  * @brief  SCI Abort Complete callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_AbortCpltCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCI_AbortCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  SCI Abort Complete callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_AbortTransmitCpltCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCI_AbortTransmitCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  SCI Abort Receive Complete callback.
  * @param  hsci SCI handle.
  * @retval None
  */
__weak void HAL_SCI_AbortReceiveCpltCallback(SCI_HandleTypeDef *hsci)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCI_AbortReceiveCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Reception Event Callback (Rx event notification called after use of advanced reception service).
  * @param  hsci SCI handle
  * @param  Size  Number of data available in application reception buffer (indicates a position in
  *               reception buffer until which, data are available)
  * @retval None
  */
__weak void HAL_SCIEx_RxEventCallback(SCI_HandleTypeDef *hsci, uint32_t Size)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsci);
  UNUSED(Size);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SCIEx_RxEventCallback can be implemented in the user file.
   */
}

/** @defgroup SCI_Exported_Functions_Group3 Peripheral Control functions
  *  @brief   SCI control functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the SCI.
     (+) HAL_SCI_ReceiverTimeout_Config() API allows to configure the receiver timeout value on the fly
     (+) HAL_SCI_EnableReceiverTimeout() API enables the receiver timeout feature
     (+) HAL_SCI_DisableReceiverTimeout() API disables the receiver timeout feature
     (+) SCI_SetConfig() API configures the SCI peripheral
     (+) SCI_AdvFeatureConfig() API optionally configures the SCI advanced features
     (+) HAL_HalfDuplex_EnableTransmitter() API disables receiver and enables transmitter
     (+) HAL_HalfDuplex_EnableReceiver() API disables transmitter and enables receiver
     (+) HAL_LIN_SendBreak() API transmits the break characters
@endverbatim
  * @{
  */

/**
  * @brief  Update on the fly the receiver timeout value in RTOR register.
  * @param  hsci Pointer to a SCI_HandleTypeDef structure that contains
  *                    the configuration information for the specified SCI module.
  * @param  TimeoutValue receiver timeout value in number of baud blocks. The timeout
  *                     value must be less or equal to 0x0FFFFFFFF.
  * @retval None
  */
void HAL_SCI_ReceiverTimeout_Config(SCI_HandleTypeDef *hsci, uint32_t TimeoutValue)
{
  assert_param(IS_SCI_RECEIVER_TIMEOUT_VALUE(TimeoutValue));
  MODIFY_REG(hsci->Instance->RTOR, USART_RTOR_RTO, TimeoutValue);

}

/**
  * @brief  Enable the SCI receiver timeout feature.
  * @param  hsci Pointer to a SCI_HandleTypeDef structure that contains
  *                    the configuration information for the specified SCI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_EnableReceiverTimeout(SCI_HandleTypeDef *hsci)
{
  if (hsci->gState == HAL_SCI_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hsci);

    hsci->gState = HAL_SCI_STATE_BUSY;

    /* Set the SCI RTOEN bit */
    SET_BIT(hsci->Instance->CR2, USART_CR2_RTOEN);

    hsci->gState = HAL_SCI_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hsci);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Disable the SCI receiver timeout feature.
  * @param  hsci Pointer to a SCI_HandleTypeDef structure that contains
  *                    the configuration information for the specified SCI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCI_DisableReceiverTimeout(SCI_HandleTypeDef *hsci)
{
    if (hsci->gState == HAL_SCI_STATE_READY)
    {
      /* Process Locked */
      __HAL_LOCK(hsci);

      hsci->gState = HAL_SCI_STATE_BUSY;

      /* Clear the SCI RTOEN bit */
      CLEAR_BIT(hsci->Instance->CR2, USART_CR2_RTOEN);

      hsci->gState = HAL_SCI_STATE_READY;

      /* Process Unlocked */
      __HAL_UNLOCK(hsci);

      return HAL_OK;
    }
    else
    {
      return HAL_BUSY;
    }
}

/**
  * @brief  Enters the SCI in mute mode.
  * @param  hsci  Pointer to a SCI_HandleTypeDef structure that contains
  *                the configuration information for the specified SCI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(SCI_HandleTypeDef *hsci)
{
  /* Check the parameters */
  assert_param(IS_SCI_INSTANCE(hsci->Instance));

  /* Process Locked */
  __HAL_LOCK(hsci);

  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Enable the SCI mute mode  by setting the RWU bit in the CR1 register */
  SET_BIT(hsci->Instance->CR1, USART_CR1_RWU);

  hsci->gState = HAL_SCI_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief  Exits the SCI mute mode: wake up software.
  * @param  hsci  Pointer to a SCI_HandleTypeDef structure that contains
  *                the configuration information for the specified SCI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode(SCI_HandleTypeDef *hsci)
{
  /* Check the parameters */
  assert_param(IS_SCI_INSTANCE(hsci->Instance));

  /* Process Locked */
  __HAL_LOCK(hsci);

  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Disable the SCI mute mode by clearing the RWU bit in the CR1 register */
  CLEAR_BIT(hsci->Instance->CR1, USART_CR1_RWU);

  hsci->gState = HAL_SCI_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief  Enable the SCI transmitter and disable the SCI receiver.
  * @param  hsci SCI handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(SCI_HandleTypeDef *hsci)
{
  __HAL_LOCK(hsci);
  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Clear TE and RE bits */
  CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_TE | USART_CR1_RE));

  /* Enable the SCI's transmit interface by setting the TE bit in the USART CR1 register */
  SET_BIT(hsci->Instance->CR1, USART_CR1_TE);

  hsci->gState = HAL_SCI_STATE_READY;

  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief  Enable the SCI receiver and disable the SCI transmitter.
  * @param  hsci SCI handle.
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(SCI_HandleTypeDef *hsci)
{
  __HAL_LOCK(hsci);
  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Clear TE and RE bits */
  CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_TE | USART_CR1_RE));

  /* Enable the SCI's receive interface by setting the RE bit in the USART CR1 register */
  SET_BIT(hsci->Instance->CR1, USART_CR1_RE);

  hsci->gState = HAL_SCI_STATE_READY;

  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief  Transmit break characters.
  * @param  hsci SCI handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LIN_SendBreak(SCI_HandleTypeDef *hsci)
{
  /* Check the parameters */
  assert_param(IS_SCI_LIN_INSTANCE(hsci->Instance));

  __HAL_LOCK(hsci);

  hsci->gState = HAL_SCI_STATE_BUSY;

  /* Send break characters */
  __HAL_SCI_SEND_REQ(hsci, SCI_SENDBREAK_REQUEST);

  hsci->gState = HAL_SCI_STATE_READY;

  __HAL_UNLOCK(hsci);

  return HAL_OK;
}

/**
  * @brief  Returns the SCI state.
  * @param  hsci  Pointer to a SCI_HandleTypeDef structure that contains
  *                the configuration information for the specified SCI module.
  * @retval HAL state
  */
HAL_SCI_StateTypeDef HAL_SCI_GetState(SCI_HandleTypeDef *hsci)
{
  uint32_t temp1 = 0x00U, temp2 = 0x00U;
  temp1 = hsci->gState;
  temp2 = hsci->RxState;
  
  return (HAL_SCI_StateTypeDef)(temp1 | temp2);
}

/**
  * @brief  Return the SCI error code
  * @param  hsci Pointer to a SCI_HandleTypeDef structure that contains
  *               the configuration information for the specified SCI.
  * @retval SCI Error Code
  */
uint32_t HAL_SCI_GetError(SCI_HandleTypeDef *hsci)
{
  return hsci->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup SCI_Private_Functions SCI Private Functions
  * @{
  */

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
/**
  * @brief  Initialize the callbacks to their default values.
  * @param  hsci SCI handle.
  * @retval none
  */
void SCI_InitCallbacksToDefault(SCI_HandleTypeDef *hsci)
{
  /* Init the SCI Callback settings */
  hsci->TxBlockCpltCallback        = HAL_SCI_TxBlockCpltCallback;       /* Legacy weak TxBlockCpltCallback       */
  hsci->TxHalfBlockCpltCallback    = HAL_SCI_TxHalfBlockCpltCallback;   /* Legacy weak TxHalfBlockCpltCallback   */
  hsci->TxSrcCpltCallback          = HAL_SCI_TxSrcCpltCallback;         /* Legacy weak TxSrcCpltCallback         */
  hsci->TxCpltCallback             = HAL_SCI_TxCpltCallback;            /* Legacy weak TxCpltCallback            */
  hsci->RxBlockCpltCallback        = HAL_SCI_RxBlockCpltCallback;       /* Legacy weak RxBlockCpltCallback       */
  hsci->RxHalfBlockCpltCallback    = HAL_SCI_RxHalfBlockCpltCallback;   /* Legacy weak RxHalfBlockCpltCallback   */
  hsci->RxDstCpltCallback          = HAL_SCI_RxDstCpltCallback;         /* Legacy weak RxDstCpltCallback         */
  hsci->RxCpltCallback             = HAL_SCI_RxCpltCallback;            /* Legacy weak RxCpltCallback            */
  hsci->ErrorCallback              = HAL_SCI_ErrorCallback;             /* Legacy weak ErrorCallback             */
  hsci->AbortCpltCallback          = HAL_SCI_AbortCpltCallback;         /* Legacy weak AbortCpltCallback         */
  hsci->AbortTransmitCpltCallback  = HAL_SCI_AbortTransmitCpltCallback; /* Legacy weak AbortTransmitCpltCallback */
  hsci->AbortReceiveCpltCallback   = HAL_SCI_AbortReceiveCpltCallback;  /* Legacy weak AbortReceiveCpltCallback  */
  hsci->WakeupCallback             = HAL_SCIEx_WakeupCallback;          /* Legacy weak WakeupCallback            */
  hsci->RxFifoFullCallback         = HAL_SCIEx_RxFifoFullCallback;      /* Legacy weak RxFifoFullCallback        */
  hsci->TxFifoEmptyCallback        = HAL_SCIEx_TxFifoEmptyCallback;     /* Legacy weak TxFifoEmptyCallback       */
}
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */

/**
  * @brief  Configures the SCI peripheral.
  * @param  hsci  Pointer to a SCI_HandleTypeDef structure that contains
  *                the configuration information for the specified SCI module.
  * @retval None
  */
void SCI_SetConfig(SCI_HandleTypeDef *hsci)
{
  uint32_t tmpreg;
  uint64_t clockfreq;

  /* Check the parameters */
  assert_param(IS_SCI_BAUDRATE(hsci->Init.BaudRate));
  assert_param(IS_SCI_WORD_LENGTH(hsci->Init.WordLength));
  assert_param(IS_SCI_STOPBITS(hsci->Init.StopBits));
  assert_param(IS_SCI_PARITY(hsci->Init.Parity));
  assert_param(IS_SCI_MODE(hsci->Init.Mode));
  assert_param(IS_SCI_HARDWARE_FLOW_CONTROL(hsci->Init.HwFlowCtl));
  assert_param(IS_SCI_OVERSAMPLING(hsci->Init.OverSampling));

  /*-------------------------- USART CR1 Configuration -----------------------*/
  /* Configure the SCI Word Length, Parity and mode:
     Set the M bits according to hsci->Init.WordLength value
     Set PCE and PS bits according to hsci->Init.Parity value
     Set TE and RE bits according to hsci->Init.Mode value */
  
  tmpreg  = (uint32_t)hsci->Init.WordLength | hsci->Init.Parity | hsci->Init.Mode;
  tmpreg |= (uint32_t)hsci->FifoMode;
  MODIFY_REG(hsci->Instance->CR1,SCI_CR1_FIELDS,tmpreg);

  /*---------------------------- USART CR2 Configuration ---------------------*/
  /* Configure the SCI Stop Bits: Set STOP[13:12] bits according
  * to hsci->Init.StopBits value */
  MODIFY_REG(hsci->Instance->CR2, USART_CR2_STOP, hsci->Init.StopBits);

  /*-------------------------- USART CR3 Configuration -----------------------*/
  /* Configure the SCI HFC: Set CTSE and RTSE bits according to hsci->Init.HwFlowCtl value
     Set OVER8 bit according to hsci->Init.OverSampling value */
  MODIFY_REG(hsci->Instance->CR3, (USART_CR3_RTSE | USART_CR3_CTSE), hsci->Init.HwFlowCtl);
  MODIFY_REG(hsci->Instance->CR3, (uint32_t)(USART_CR3_OVER8), (uint32_t) hsci->Init.OverSampling);

  /*-------------------------- USART BRR Configuration -----------------------*/
  if(hsci->Instance == USART1)
  {
    clockfreq = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_USART1);
  }
  else if(hsci->Instance == USART2)
  {
    clockfreq = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_USART2);
  }
  else if(hsci->Instance == USART3)
  {
    clockfreq = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_USART3);
  }
  else
  {
  }

  /* Check the Over Sampling */
  if(hsci->Init.OverSampling == SCI_OVERSAMPLING_8)
  {
    hsci->Instance->BRR = SCI_BRR_SAMPLING8(clockfreq, hsci->Init.BaudRate);
  }
  else
  {
    hsci->Instance->BRR = SCI_BRR_SAMPLING16(clockfreq, hsci->Init.BaudRate);
  }

  /* Initialize the number of data to process during RX/TX SR execution */
  hsci->NbTxDataToProcess = 1U;
  hsci->NbRxDataToProcess = 1U;

  /* Clear SR function pointers */
  hsci->RxISR   = NULL;
  hsci->TxISR   = NULL;
}

/**
  * @brief Configure the SCI peripheral advanced features.
  * @param hsci SCI handle.
  * @retval None
  */
void SCI_AdvFeatureConfig(SCI_HandleTypeDef *hsci)
{
  /* Check whether the set of advanced features to configure is properly set */
  assert_param(IS_SCI_ADVFEATURE_INIT(hsci->AdvancedInit.AdvFeatureInit));

  /* if required, configure RX/TX pins swap */
  if (HAL_IS_BIT_SET(hsci->AdvancedInit.AdvFeatureInit, SCI_ADVFEATURE_SWAP_INIT))
  {
    assert_param(IS_SCI_ADVFEATURE_SWAP(hsci->AdvancedInit.Swap));
    MODIFY_REG(hsci->Instance->CR1, USART_CR1_SWAP, hsci->AdvancedInit.Swap);
  }

  /* if required, configure TX pin active level inversion */
  if (HAL_IS_BIT_SET(hsci->AdvancedInit.AdvFeatureInit, SCI_ADVFEATURE_TXINVERT_INIT))
  {
    assert_param(IS_SCI_ADVFEATURE_TXINV(hsci->AdvancedInit.TxPinLevelInvert));
    MODIFY_REG(hsci->Instance->CR1, USART_CR1_TX_INV, hsci->AdvancedInit.TxPinLevelInvert);
  }

  /* if required, configure RX pin active level inversion */
  if (HAL_IS_BIT_SET(hsci->AdvancedInit.AdvFeatureInit, SCI_ADVFEATURE_RXINVERT_INIT))
  {
    assert_param(IS_SCI_ADVFEATURE_RXINV(hsci->AdvancedInit.RxPinLevelInvert));
    MODIFY_REG(hsci->Instance->CR1, USART_CR1_RX_INV, hsci->AdvancedInit.RxPinLevelInvert);
  }

  /* if required, configure data inversion */
  if (HAL_IS_BIT_SET(hsci->AdvancedInit.AdvFeatureInit, SCI_ADVFEATURE_DATAINVERT_INIT))
  {
    assert_param(IS_SCI_ADVFEATURE_DATAINV(hsci->AdvancedInit.DataInvert));
    MODIFY_REG(hsci->Instance->CR1, USART_CR1_DATAINV, hsci->AdvancedInit.DataInvert);
  }

  /* if required, configure auto Baud rate detection scheme */
  if (HAL_IS_BIT_SET(hsci->AdvancedInit.AdvFeatureInit, SCI_ADVFEATURE_AUTOBAUDRATE_INIT))
  {
    assert_param(IS_SCI_AUTOBAUDRATE_DETECTION_INSTANCE(hsci->Instance));
    assert_param(IS_SCI_ADVFEATURE_AUTOBAUDRATE(hsci->AdvancedInit.AutoBaudRateEnable));
    MODIFY_REG(hsci->Instance->CR3, USART_CR3_ABREN, hsci->AdvancedInit.AutoBaudRateEnable);
    /* set auto Baudrate detection parameters if detection is enabled */
    if (hsci->AdvancedInit.AutoBaudRateEnable == SCI_ADVFEATURE_AUTOBAUDRATE_ENABLE)
    {
      assert_param(IS_SCI_ADVFEATURE_AUTOBAUDRATEMODE(hsci->AdvancedInit.AutoBaudRateMode));
      MODIFY_REG(hsci->Instance->CR3, USART_CR3_ABRMOD, hsci->AdvancedInit.AutoBaudRateMode);
    }
  }
  
  /* if required, configure MSB first on communication line */
  if (HAL_IS_BIT_SET(hsci->AdvancedInit.AdvFeatureInit, SCI_ADVFEATURE_MSBFIRST_INIT))
  {
    assert_param(IS_SCI_ADVFEATURE_MSBFIRST(hsci->AdvancedInit.MSBFirst));
    MODIFY_REG(hsci->Instance->CR1, USART_CR1_MSB, hsci->AdvancedInit.MSBFirst);
  }
}

/**
  * @brief  This function handles SCI Communication Timeout.
  * @param  hsci  Pointer to a SCI_HandleTypeDef structure that contains
  *                the configuration information for the specified SCI module.
  * @param  Flag specifies the SCI flag to check.
  * @param  Status The new Flag status (SET or RESET).
  * @param  Tickstart Tick start value
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
static HAL_StatusTypeDef SCI_WaitOnFlagUntilTimeout(SCI_HandleTypeDef *hsci, uint32_t Flag, FlagStatus Status, uint32_t Tickstart, uint32_t Timeout)
{
  /* Wait until flag is set */
  while ((__HAL_SCI_GET_FLAG(hsci, Flag) ? SET : RESET) == Status)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if ((Timeout == 0U) || ((HAL_GetTick() - Tickstart) > Timeout))
      {
        /* Disable TXE, RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts for the interrupt process */
        CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE | USART_CR1_TXEIE));
        CLEAR_BIT(hsci->Instance->CR3, USART_CR3_EIE);

        hsci->gState  = HAL_SCI_STATE_READY;
        hsci->RxState = HAL_SCI_STATE_READY;

        /* Process Unlocked */
        __HAL_UNLOCK(hsci);

        return HAL_TIMEOUT;
      }
    }
    
    if ((READ_BIT(hsci->Instance->CR1, USART_CR1_RE) != 0U) && (Flag != SCI_FLAG_TXE) && (Flag != SCI_FLAG_TC))
    {
      if (__HAL_SCI_GET_FLAG(hsci, SCI_FLAG_ORE) == SET)
      {
        /* Clear Receiver Timeout flag*/
        __HAL_SCI_CLEAR_FLAG(hsci, SCI_FLAG_ORE);

        /* Blocking error : transfer is aborted
        Set the SCI state ready to be able to start again the process,
        Disable Rx Interrupts if ongoing */
        SCI_EndRxTransfer(hsci);

        hsci->ErrorCode = HAL_SCI_ERROR_ORE;

        /* Process Unlocked */
        __HAL_UNLOCK(hsci);

        return HAL_TIMEOUT;
      }
      if (__HAL_SCI_GET_FLAG(hsci, SCI_FLAG_RTOF) == SET)
      {
        /* Clear Receiver Timeout flag*/
        __HAL_SCI_CLEAR_FLAG(hsci, SCI_FLAG_RTOF);

        /* Blocking error : transfer is aborted
        Set the SCI state ready to be able to start again the process,
        Disable Rx Interrupts if ongoing */
        SCI_EndRxTransfer(hsci);

        hsci->ErrorCode = HAL_SCI_ERROR_RTO;

        /* Process Unlocked */
        __HAL_UNLOCK(hsci);

        return HAL_TIMEOUT;
      }
    }
  }
  return HAL_OK;
}

/**
  * @brief  Start Receive operation in interrupt mode.
  * @note   This function could be called by all HAL SCI API providing reception in Interrupt mode.
  * @note   When calling this function, parameters validity is considered as already checked,
  *         i.e. Rx State, buffer address, ...
  *         SCI Handle is assumed as Locked.
  * @param  hsci SCI handle.
  * @param  pRxData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef SCI_Start_Receive_IT(SCI_HandleTypeDef *hsci, uint8_t *pRxData, uint32_t Size)
{
  hsci->pRxBuffPtr  = pRxData;
  hsci->RxXferSize  = Size;
  hsci->RxXferCount = Size;
  hsci->RxISR       = NULL;

  SCI_MASK_COMPUTATION(hsci);

  hsci->ErrorCode = HAL_SCI_ERROR_NONE;
  hsci->RxState   = HAL_SCI_STATE_BUSY_RX;

  /* Enable the SCI Error Interrupt: (Frame error, noise error, overrun error) */
  SET_BIT(hsci->Instance->CR3, USART_CR3_EIE);

  /* Configure Rx interrupt processing */
  if ((hsci->FifoMode == SCI_FIFOMODE_ENABLE) && (Size >= hsci->NbRxDataToProcess))
  {
    /* Set the Rx ISR function pointer according to the data word length */
    if ((hsci->Init.WordLength == SCI_WORDLENGTH_9B) && (hsci->Init.Parity == SCI_PARITY_NONE))
    {
      hsci->RxISR = SCI_RxSR_16BIT_FIFOEN;
    }
    else
    {
      hsci->RxISR = SCI_RxSR_8BIT_FIFOEN;
    }
    
    /* Enable the SCI Parity Error interrupt and RX FIFO Threshold interrupt */
    SET_BIT(hsci->Instance->CR1, USART_CR1_PEIE);
    SET_BIT(hsci->Instance->CR3, USART_CR3_RXFTIE);
  }
  else
  {
    /* Set the Rx ISR function pointer according to the data word length */
    if ((hsci->Init.WordLength == SCI_WORDLENGTH_9B) && (hsci->Init.Parity == SCI_PARITY_NONE))
    {
      hsci->RxISR = SCI_RxSR_16BIT;
    }
    else
    {
      hsci->RxISR = SCI_RxSR_8BIT;
    }
    
    /* Enable the SCI Parity Error interrupt and Data Register Not Empty interrupt */
    SET_BIT(hsci->Instance->CR1, USART_CR1_PEIE | USART_CR1_RXNEIE);
  }
  
  return HAL_OK;
}

/**
  * @brief  Start Receive operation in DMA mode.
  * @note   This function could be called by all HAL SCI API providing reception in DMA mode.
  * @note   When calling this function, parameters validity is considered as already checked,
  *         i.e. Rx State, buffer address, ...
  *         SCI Handle is assumed as Locked.
  * @param  hsci SCI handle.
  * @param  pRxData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef SCI_Start_Receive_DMA(SCI_HandleTypeDef *hsci, uint8_t *pRxData, uint32_t Size)
{
    hsci->pRxBuffPtr = pRxData;
    hsci->RxXferSize = Size;

    hsci->ErrorCode = HAL_SCI_ERROR_NONE;
    hsci->RxState   = HAL_SCI_STATE_BUSY_RX;

    if (hsci->hdmarx != NULL)
    {
      /* Set the SCI DMA Rx transfer complete callback */
      hsci->hdmarx->XferCpltCallback = SCI_DMAReceiveCplt;

      /* Set the SCI DMA Block transfer complete callback */
      hsci->hdmarx->XferBlockCpltCallback = SCI_DMARxBlockCplt;

      /* Set the SCI DMA Half Block transfer complete callback */
      hsci->hdmarx->XferHalfBlockCpltCallback = SCI_DMARxHalfBlockCplt;

      /* Set the SCI DMA Destination transaction complete callback */
      hsci->hdmarx->XferDstTranCpltCallback = SCI_DMAReceiveDstCplt;

      /* Set the SCI DMA Rx transfer error callback */
      hsci->hdmarx->XferErrorCallback = SCI_DMAError;

      /* Set the DMA abort callback */
      hsci->hdmarx->XferAbortCallback = NULL;

    }

    if (HAL_DMA_Start_IT(hsci->hdmarx, (uint32_t)&hsci->Instance->DR, (uint32_t)hsci->pRxBuffPtr, Size) != HAL_OK)
    {
      /* Set error code to DMA */
      hsci->ErrorCode = HAL_SCI_ERROR_DMA;

      /* Restore hsci->RxState to ready */
      hsci->RxState = HAL_SCI_STATE_READY;

      return HAL_ERROR;
    }
    
    /* Enable the SCI Parity Error Interrupt */
    SET_BIT(hsci->Instance->CR1, USART_CR1_PEIE);

    /* Enable the SCI Error Interrupt: (Frame error, noise error, overrun error) */
    SET_BIT(hsci->Instance->CR3, USART_CR3_EIE);

    /* Enable the DMA transfer for the receiver request by setting the DMAR bit in the USART CR3 register */
    SET_BIT(hsci->Instance->CR3, USART_CR3_DMAR);

    return HAL_OK;
}

/**
  * @brief  End ongoing Tx transfer on SCI peripheral (following error detection or Transmit completion).
  * @param  hsci SCI handle.
  * @retval None
  */
static void SCI_EndTxTransfer(SCI_HandleTypeDef *hsci)
{
  /* Disable TXEIE, TCIE, TXFT interrupts */
  CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_TXEIE| USART_CR1_TCIE));
  CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_TXFTIE));

  /* At end of Tx process, restore hsci->gState to Ready */
  hsci->gState = HAL_SCI_STATE_READY;
}


/**
  * @brief  End ongoing Rx transfer on SCI peripheral (following error detection or Reception completion).
  * @param  hsci SCI handle.
  * @retval None
  */
static void SCI_EndRxTransfer(SCI_HandleTypeDef *hsci)
{
  /* Disable RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));
  CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_EIE | USART_CR3_RXFTIE));

  /* In case of reception waiting for IDLE event, disable also the IDLE IE interrupt source */
  if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
  {
    CLEAR_BIT(hsci->Instance->CR1, USART_CR1_IDLEIE);
  }

  /* At end of Rx process, restore hsci->RxState to Ready */
  hsci->RxState = HAL_SCI_STATE_READY;
  hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

  /* Reset RxIsr function pointer */
  hsci->RxISR = NULL;
}

/**
  * @brief DMA SCI transmit process complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMATransmitCplt(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);

  /* DMA Normal mode */
  if (HAL_IS_BIT_CLR(hdma->Init.Mode, DMA_CIRCULAR))
  {
    hsci->TxXferCount = 0U;

    /* Disable the DMA transfer for transmit request by resetting the DMAT bit
       in the USART CR3 register */
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAT);

    /* Enable the SCI Transmit Complete Interrupt */
    __HAL_SCI_ENABLE_IT(hsci, SCI_IT_TC);

  }
  /* DMA Circular mode */
  else
  {

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
    /* Call registered Tx Complete Callback */
    hsci->TxCpltCallback(hsci);
#else
    /* Call legacy weak Tx Complete Callback */
    HAL_SCI_TxCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
  }
}

/**
  * @brief DMA SCI transmit process half Block complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMATxHalfBlockCplt(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Tx Half Block Complete Callback */
  hsci->TxHalfBlockCpltCallback(hsci);
#else
  /* Call legacy weak Tx Half Block Complete Callback */
  HAL_SCI_TxHalfBlockCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief DMA SCI transmit process Block complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMATxBlockCplt(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Tx Block Complete Callback */
  hsci->TxBlockCpltCallback(hsci);
#else
  /* Call legacy weak Tx Block Complete Callback */
  HAL_SCI_TxBlockCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief DMA SCI source transaction process Source complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMATransmitSrcCplt(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Tx source Transaction Complete Callback */
  hsci->TxSrcCpltCallback(hsci);
#else
  /* Call legacy weak Tx source Transaction Complete Callback */
  HAL_SCI_TxSrcCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief DMA SCI receive process complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMAReceiveCplt(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);

  /* DMA Normal mode */
  if (HAL_IS_BIT_CLR(hdma->Init.Mode, DMA_CIRCULAR))
  {
    hsci->RxXferCount = 0U;

    /* Disable PE and ERR (Frame error, noise error, overrun error) interrupts */
    CLEAR_BIT(hsci->Instance->CR1, USART_CR1_PEIE);
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_EIE);

    /* Disable the DMA RX transfer for the receiver request by resetting the DMAR bit
       in USART CR3 register */
    CLEAR_BIT(hsci->Instance->CR3, USART_CR3_DMAR);

    /* At end of Rx process, restore hsci->RxState to Ready */
    hsci->RxState = HAL_SCI_STATE_READY;

    /* If Reception till IDLE event has been selected, Disable IDLE Interrupt */
    if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
    {
      CLEAR_BIT(hsci->Instance->CR1, USART_CR1_IDLEIE);
    }
  }

  /* Initialize type of RxEvent that correspond to RxEvent callback execution;
     In this case, Rx Event type is Transfer Complete */
  hsci->RxEventType = HAL_SCI_RXEVENT_TC;
  
  /* Check current reception Mode :
     If Reception till IDLE event has been selected : use Rx Event callback */
  if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
  {
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
    /*Call registered Rx Event callback*/
    hsci->RxEventCallback(hsci, hsci->RxXferSize);
#else
    /*Call legacy weak Rx Event callback*/
    HAL_SCIEx_RxEventCallback(hsci, hsci->RxXferSize);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
  }
  else
  {
    /* In other cases : use Rx Complete callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
    /*Call registered Rx complete callback*/
    hsci->RxCpltCallback(hsci);
#else
    /*Call legacy weak Rx complete callback*/
    HAL_SCI_RxCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
  }
}

/**
  * @brief DMA SCI receive process block complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMARxBlockCplt(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Rx Block Complete Callback */
  hsci->RxBlockCpltCallback(hsci);
#else
  /* Call legacy weak Rx Block Complete Callback */
  HAL_SCI_RxBlockCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief DMA SCI receive process half block complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMARxHalfBlockCplt(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Rx Half Block Complete Callback */
  hsci->RxHalfBlockCpltCallback(hsci);
#else
  /* Call legacy weak Rx Half Block Complete Callback */
  HAL_SCI_RxHalfBlockCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief DMA SCI receive process destination transaction complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMAReceiveDstCplt(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Rx Destination Transaction Complete Callback */
  hsci->RxDstCpltCallback(hsci);
#else
  /* Call legacy weak Rx destination transaction Complete Callback */
  HAL_SCI_RxDstCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief DMA SCI communication error callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMAError(DMA_HandleTypeDef *hdma)
{
  uint32_t dmarequest = 0x00U;
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  /* Stop SCI DMA Tx request if ongoing */
  dmarequest = HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAT);
  if ((hsci->gState == HAL_SCI_STATE_BUSY_TX) && dmarequest)
  {
    hsci->TxXferCount = 0x00U;
    SCI_EndTxTransfer(hsci);
  }

  /* Stop SCI DMA Rx request if ongoing */
  dmarequest = HAL_IS_BIT_SET(hsci->Instance->CR3, USART_CR3_DMAR);
  if ((hsci->RxState == HAL_SCI_STATE_BUSY_RX) && dmarequest)
  {
    hsci->RxXferCount = 0x00U;
    SCI_EndRxTransfer(hsci);
  }

  hsci->ErrorCode |= HAL_SCI_ERROR_DMA;
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /*Call registered error callback*/
  hsci->ErrorCallback(hsci);
#else
  /*Call legacy weak error callback*/
  HAL_SCI_ErrorCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA SCI communication abort callback, when initiated by HAL services on Error
  *         (To be called at end of DMA Abort procedure following error occurrence).
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMAAbortOnError(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);
  hsci->RxXferCount = 0U;
  hsci->TxXferCount = 0U;

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Error Callback */
  hsci->ErrorCallback(hsci);
#else
  /* Call legacy weak Error Callback */
  HAL_SCI_ErrorCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA SCI Tx communication abort callback, when initiated by user
  *         (To be called at end of DMA Tx Abort procedure following user abort request).
  * @note   When this callback is executed, User Abort complete call back is called only if no
  *         Abort still ongoing for Rx DMA Handle.
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMATxAbortCallback(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);

  hsci->hdmatx->XferAbortCallback = NULL;

  /* Check if an Abort process is still ongoing */
  if (hsci->hdmarx != NULL)
  {
    if (hsci->hdmarx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA channels are aborted, call user Abort Complete callback */
  hsci->TxXferCount = 0U;
  hsci->RxXferCount = 0U;

  /* Reset errorCode */
  hsci->ErrorCode = HAL_SCI_ERROR_NONE;

  /* Clear the Error flags */
  __HAL_SCI_CLEAR_PEFLAG(hsci);

  /* Flush the whole TX FIFO (if needed) */
  if (hsci->FifoMode == SCI_FIFOMODE_ENABLE)
  {
    __HAL_SCI_SEND_REQ(hsci, SCI_TXDATA_FLUSH_REQUEST);
  }

  /* Restore hsci->gState and hsci->RxState to Ready */
  hsci->gState  = HAL_SCI_STATE_READY;
  hsci->RxState = HAL_SCI_STATE_READY;
  hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

  /* Call user Abort complete callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Complete Callback */
  hsci->AbortCpltCallback(hsci);
#else
  /* Call legacy weak Abort Complete Callback */
  HAL_SCI_AbortCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA SCI Rx communication abort callback, when initiated by user
  *         (To be called at end of DMA Rx Abort procedure following user abort request).
  * @note   When this callback is executed, User Abort complete call back is called only if no
  *         Abort still ongoing for Tx DMA Handle.
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMARxAbortCallback(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);

  hsci->hdmarx->XferAbortCallback = NULL;

  /* Check if an Abort process is still ongoing */
  if (hsci->hdmatx != NULL)
  {
    if (hsci->hdmatx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA channels are aborted, call user Abort Complete callback */
  hsci->TxXferCount = 0U;
  hsci->RxXferCount = 0U;

  /* Reset errorCode */
  hsci->ErrorCode = HAL_SCI_ERROR_NONE;

  /* Clear the Error flags */
  __HAL_SCI_CLEAR_PEFLAG(hsci);

  /* Discard the received data */
  __HAL_SCI_SEND_REQ(hsci, SCI_RXDATA_FLUSH_REQUEST);
  /* Restore hsci->gState to Ready */
  hsci->gState  = HAL_SCI_STATE_READY;
  hsci->RxState = HAL_SCI_STATE_READY;
  hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

  /* Call user Abort complete callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Complete Callback */
  hsci->AbortCpltCallback(hsci);
#else
  /* Call legacy weak Abort Complete Callback */
  HAL_SCI_AbortCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA SCI Tx communication abort callback, when initiated by user by a call to
  *         HAL_SCI_AbortTransmit_IT API (Abort only Tx transfer)
  *         (This callback is executed at end of DMA Tx Abort procedure following user abort request,
  *         and leads to user Tx Abort Complete callback execution).
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)(hdma->Parent);

  hsci->TxXferCount = 0U;

  /* Flush the whole TX FIFO (if needed) */
  if (hsci->FifoMode == SCI_FIFOMODE_ENABLE)
  {
    __HAL_SCI_SEND_REQ(hsci, SCI_TXDATA_FLUSH_REQUEST);
  }

  /* Restore hsci->gState to Ready */
  hsci->gState = HAL_SCI_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Transmit Complete Callback */
  hsci->AbortTransmitCpltCallback(hsci);
#else
  /* Call legacy weak Abort Transmit Complete Callback */
  HAL_SCI_AbortTransmitCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA SCI Rx communication abort callback, when initiated by user by a call to
  *         HAL_SCI_AbortReceive_IT API (Abort only Rx transfer)
  *         (This callback is executed at end of DMA Rx Abort procedure following user abort request,
  *         and leads to user Rx Abort Complete callback execution).
  * @param  hdma DMA handle.
  * @retval None
  */
static void SCI_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma)
{
  SCI_HandleTypeDef *hsci = (SCI_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  hsci->RxXferCount = 0U;

  /* Clear the Error flags in */
  __HAL_SCI_CLEAR_PEFLAG(hsci);

  /* Discard the received data */
  __HAL_SCI_SEND_REQ(hsci, SCI_RXDATA_FLUSH_REQUEST);

  /* Restore hsci->RxState to Ready */
  hsci->RxState = HAL_SCI_STATE_READY;
  hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

  /* Call user Abort complete callback */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Receive Complete Callback */
  hsci->AbortReceiveCpltCallback(hsci);
#else
  /* Call legacy weak Abort Receive Complete Callback */
  HAL_SCI_AbortReceiveCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief  Simplex send an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_SCI_Transmit_IT().
  * @note   The SCI errors are not managed to avoid the overrun error.
  * @note   ISR function executed when FIFO mode is disabled and when the
  *         data word length is less than 9 bits long.
  * @param  hsci SCI handle.
  * @retval None
  */
static void SCI_TxSR_8BIT(SCI_HandleTypeDef *hsci)
{
  /* Check that a Tx process is ongoing */
  if (hsci->gState == HAL_SCI_STATE_BUSY_TX)
  {
    if (hsci->TxXferCount == 0U)
    {
      /* Disable the SCI Transmit data register empty interrupt */
      __HAL_SCI_DISABLE_IT(hsci, SCI_IT_TXE);

      /* Enable the SCI Transmit Complete Interrupt */
      __HAL_SCI_ENABLE_IT(hsci, SCI_IT_TC);
    }
    else
    {
      /* To prevent the TC flag bit from being affected by other operations during
         data transmission, read the SR register in conjunction with write the DR 
         Register to clear the TC flag bit.
         */
      (void)(hsci->Instance->SR);
      hsci->Instance->DR = (uint8_t)(*hsci->pTxBuffPtr & (uint8_t)0xFF);
      hsci->pTxBuffPtr++;
      hsci->TxXferCount--;
    }
  }
}

/**
  * @brief  Simplex send an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_SCI_Transmit_IT().
  * @note   The SCI errors are not managed to avoid the overrun error.
  * @note   ISR function executed when FIFO mode is disabled and when the
  *         data word length is 9 bits long.
  * @param  hsci SCI handle.
  * @retval None
  */
static void SCI_TxSR_16BIT(SCI_HandleTypeDef *hsci)
{
  uint16_t *tmp;

  if (hsci->gState == HAL_SCI_STATE_BUSY_TX)
  {
    if (hsci->TxXferCount == 0U)
    {
      /* Disable the SCI Transmit data register empty interrupt */
      __HAL_SCI_DISABLE_IT(hsci, SCI_IT_TXE);

      /* Enable the SCI Transmit Complete Interrupt */
      __HAL_SCI_ENABLE_IT(hsci, SCI_IT_TC);
    }
    else
    {
      tmp = (uint16_t *) hsci->pTxBuffPtr;
      /* To prevent the TC flag bit from being affected by other operations during
         data transmission, read the SR register in conjunction with write the DR 
         Register to clear the TC flag bit.
         */
      (void)(hsci->Instance->SR);
      hsci->Instance->DR = (uint16_t)(*tmp & 0x01FFU);
      hsci->pTxBuffPtr += 2U;
      hsci->TxXferCount--;
    }
  }
}

/**
  * @brief  Simplex send an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_SCI_Transmit_IT().
  * @note   The SCI errors are not managed to avoid the overrun error.
  * @note   ISR function executed when FIFO mode is enabled and when the
  *         data word length is less than 9 bits long.
  * @param  hsci SCI handle.
  * @retval None
  */
static void SCI_TxSR_8BIT_FIFOEN(SCI_HandleTypeDef *hsci)
{
  uint32_t  nb_tx_data;

  /* Check that a Tx process is ongoing */
  if (hsci->gState == HAL_SCI_STATE_BUSY_TX)
  {
    for (nb_tx_data = hsci->NbTxDataToProcess ; nb_tx_data > 0U ; nb_tx_data--)
    {
      if (hsci->TxXferCount == 0U)
      {
        /* Disable the TX FIFO threshold interrupt */
        __HAL_SCI_DISABLE_IT(hsci, SCI_IT_TXFT);

        /* Enable the SCI Transmit Complete Interrupt */
        __HAL_SCI_ENABLE_IT(hsci, SCI_IT_TC);

        break; /* force exit loop */
      }
      else if (__HAL_SCI_GET_FLAG(hsci, SCI_FLAG_TXE) == SET)
      {
        /* To prevent the TC flag bit from being affected by other operations during
           data transmission, read the SR register in conjunction with write the DR 
           Register to clear the TC flag bit.
           */
        (void)(hsci->Instance->SR);
        hsci->Instance->DR = (uint8_t)(*hsci->pTxBuffPtr & (uint8_t)0xFF);
        hsci->pTxBuffPtr++;
        hsci->TxXferCount--;
      }
      else
      {
        /* Nothing to do */
      }
    }
  }
}

/**
  * @brief  Simplex send an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_SCI_Transmit_IT().
  * @note   The SCI errors are not managed to avoid the overrun error.
  * @note   ISR function executed when FIFO mode is enabled and when the
  *         data word length is 9 bits long.
  * @param  hsci SCI handle.
  * @retval None
  */
static void SCI_TxSR_16BIT_FIFOEN(SCI_HandleTypeDef *hsci)
{
  uint16_t *tmp;
  uint32_t  nb_tx_data;

  /* Check that a Tx process is ongoing */
  if (hsci->gState == HAL_SCI_STATE_BUSY_TX)
  {
    for (nb_tx_data = hsci->NbTxDataToProcess ; nb_tx_data > 0U ; nb_tx_data--)
    {
      if (hsci->TxXferCount == 0U)
      {
        /* Disable the TX FIFO threshold interrupt */
        __HAL_SCI_DISABLE_IT(hsci, SCI_IT_TXFT);

        /* Enable the SCI Transmit Complete Interrupt */
        __HAL_SCI_ENABLE_IT(hsci, SCI_IT_TC);

        break; /* force exit loop */
      }
      else if (__HAL_SCI_GET_FLAG(hsci, SCI_FLAG_TXE) == SET)
      {
        tmp = (uint16_t *) hsci->pTxBuffPtr;
        /* To prevent the TC flag bit from being affected by other operations during
           data transmission, read the SR register in conjunction with write the DR 
           Register to clear the TC flag bit.
           */
        (void)(hsci->Instance->SR);
        hsci->Instance->DR = (uint16_t)(*tmp & 0x01FFU);
        hsci->pTxBuffPtr += 2U;
        hsci->TxXferCount--;
      }
      else
      {
        /* Nothing to do */
      }
    }
  }
}

/**
  * @brief  Wraps up transmission in non-blocking mode.
  * @param  hsci Pointer to a SCI_HandleTypeDef structure that contains
  *                the configuration information for the specified SCI module.
  * @retval None
  */
static void SCI_EndTransmit_IT(SCI_HandleTypeDef *hsci)
{
  /* Disable the SCI Transmit Complete Interrupt */
  __HAL_SCI_DISABLE_IT(hsci, SCI_IT_TC);

  /* Clear TxISR function pointer */
  hsci->TxISR = NULL;

  /* Tx process is completed, restore hsci->gState to Ready */
  hsci->gState = HAL_SCI_STATE_READY;

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  /* Call registered Tx Complete Callback */
  hsci->TxCpltCallback(hsci);
#else
  /* Call legacy weak Tx Complete Callback */
  HAL_SCI_TxCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
}

/**
  * @brief  Simplex receive an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_SCI_Receive_IT().
  * @note   SR function executed when FIFO mode is disabled and when the
  *         data word length is less than 9 bits long.
  * @param  hsci SCI handle
  * @retval None
  */
static void SCI_RxSR_8BIT(SCI_HandleTypeDef *hsci)
{
  uint16_t uhMask = hsci->Mask;
  uint16_t uhdata;

  if (hsci->RxState == HAL_SCI_STATE_BUSY_RX)
  {
    uhdata = (uint16_t) READ_REG(hsci->Instance->DR);
    *hsci->pRxBuffPtr = (uint8_t)(uhdata & (uint8_t)uhMask);
    hsci->pRxBuffPtr++;
    hsci->RxXferCount--;

    if (hsci->RxXferCount == 0U)
    {
      /* Disable the SCI Parity Error Interrupt and RXNE interrupt*/
      CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));

      /* Disable the SCI Error Interrupt: (Frame error, noise error, overrun error) */
      CLEAR_BIT(hsci->Instance->CR3, USART_CR3_EIE);

      /* Rx process is completed, restore hsci->RxState to Ready */
      hsci->RxState = HAL_SCI_STATE_READY;

      /* Clear RxISR function pointer */
      hsci->RxISR = NULL;

      /* Initialize type of RxEvent to Transfer Complete */
      hsci->RxEventType = HAL_SCI_RXEVENT_TC;

        /* Check that USART RTOEN bit is set */
      if (READ_BIT(hsci->Instance->CR2, USART_CR2_RTOEN) != 0U)
      {
        /* Enable the SCI Receiver Timeout Interrupt */
        CLEAR_BIT(hsci->Instance->CR3, USART_CR3_RTOIE);
      }

      /* Check current reception Mode :
         If Reception till IDLE event has been selected : */
      if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
      {
        /* Set reception type to Standard */
        hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

        /* Disable IDLE interrupt */
        CLEAR_BIT(hsci->Instance->CR1, USART_CR1_IDLEIE);

        if (__HAL_SCI_GET_FLAG(hsci, SCI_FLAG_IDLE) == SET)
        {
          /* Clear IDLE Flag */
          __HAL_SCI_CLEAR_IDLEFLAG(hsci);
        }

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
        /*Call registered Rx Event callback*/
        hsci->RxEventCallback(hsci, hsci->RxXferSize);
#else
        /*Call legacy weak Rx Event callback*/
        HAL_SCIEx_RxEventCallback(hsci, hsci->RxXferSize);
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */
      }
      else
      {
        /* Standard reception API called */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
        /*Call registered Rx complete callback*/
        hsci->RxCpltCallback(hsci);
#else
      /* Call legacy weak Rx Complete Callback */
      HAL_SCI_RxCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
      }
    }
  }
  else
  {
    /* Clear RXNE interrupt flag */
    __HAL_SCI_SEND_REQ(hsci, SCI_RXDATA_FLUSH_REQUEST);
  }
}

/**
  * @brief  Simplex receive an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_SCI_Receive_IT().
  * @note   ISR function executed when FIFO mode is disabled and when the
  *         data word length is 9 bits long.
  * @param  hsci SCI handle
  * @retval None
  */
static void SCI_RxSR_16BIT(SCI_HandleTypeDef *hsci)
{
  uint16_t *tmp;
  uint16_t uhMask = hsci->Mask;
  uint16_t uhdata;

  if (hsci->RxState == HAL_SCI_STATE_BUSY_RX)
  {
    uhdata = (uint16_t) READ_REG(hsci->Instance->DR);
    tmp = (uint16_t *) hsci->pRxBuffPtr;
    *tmp = (uint16_t)(uhdata & uhMask);
    hsci->pRxBuffPtr += 2U;
    hsci->RxXferCount--;

    if (hsci->RxXferCount == 0U)
    {
      /* Disable the SCI Parity Error Interrupt and RXNE interrupt*/
      CLEAR_BIT(hsci->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));

      /* Disable the SCI Error Interrupt: (Frame error, noise error, overrun error) */
      CLEAR_BIT(hsci->Instance->CR3, USART_CR3_EIE);

      /* Rx process is completed, restore hsci->RxState to Ready */
      hsci->RxState = HAL_SCI_STATE_READY;

      /* Clear RxISR function pointer */
      hsci->RxISR = NULL;

      /* Initialize type of RxEvent to Transfer Complete */
      hsci->RxEventType = HAL_SCI_RXEVENT_TC;

      /* Check that USART RTOEN bit is set */
      if (READ_BIT(hsci->Instance->CR2, USART_CR2_RTOEN) != 0U)
      {
        /* Enable the SCI Receiver Timeout Interrupt */
        CLEAR_BIT(hsci->Instance->CR3, USART_CR3_RTOIE);
      }

      /* Check current reception Mode :
         If Reception till IDLE event has been selected : */
      if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
      {
        /* Set reception type to Standard */
        hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

        /* Disable IDLE interrupt */
        CLEAR_BIT(hsci->Instance->CR1, USART_CR1_IDLEIE);

        if (__HAL_SCI_GET_FLAG(hsci, SCI_FLAG_IDLE) == SET)
        {
          /* Clear IDLE Flag */
          __HAL_SCI_CLEAR_IDLEFLAG(hsci);
        }

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
        /*Call registered Rx Event callback*/
        hsci->RxEventCallback(hsci, hsci->RxXferSize);
#else
        /*Call legacy weak Rx Event callback*/
        HAL_SCIEx_RxEventCallback(hsci, hsci->RxXferSize);
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */
      }
      else
      {
        /* Standard reception API called */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
        /*Call registered Rx complete callback*/
        hsci->RxCpltCallback(hsci);
#else
        /* Call legacy weak Rx Complete Callback */
        HAL_SCI_RxCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
      }
    }
  }
  else
  {
    /* Clear RXNE interrupt flag */
    __HAL_SCI_SEND_REQ(hsci, SCI_RXDATA_FLUSH_REQUEST);
  }
}

/**
  * @brief  Simplex receive an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_SCI_Receive_IT().
  * @note   ISR function executed when FIFO mode is enabled and when the
  *         data word length is less than 9 bits long.
  * @param  hsci SCI handle
  * @retval None
  */
static void SCI_RxSR_8BIT_FIFOEN(SCI_HandleTypeDef *hsci)
{
  uint16_t uhMask = hsci->Mask;
  uint16_t uhdata;
  uint32_t nb_rx_data;
  uint32_t rxdatacount;

  /* Check that a Rx process is ongoing */
  if (hsci->RxState == HAL_SCI_STATE_BUSY_RX)
  {
    for (nb_rx_data = hsci->NbRxDataToProcess ; nb_rx_data > 0U ; nb_rx_data--)
    {
      uhdata = (uint16_t) READ_REG(hsci->Instance->DR);
      *hsci->pRxBuffPtr = (uint8_t)(uhdata & (uint8_t)(uhMask & 0xFFU));
      hsci->pRxBuffPtr++;
      hsci->RxXferCount--;

      if (hsci->RxXferCount == 0U)
      {
        /* Disable the SCI Parity Error Interrupt */
        CLEAR_BIT(hsci->Instance->CR1, USART_CR1_PEIE);

        /* Disable the SCI Error Interrupt: (Frame error, noise error, overrun error)
           and RX FIFO Threshold interrupt */
        CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_EIE | USART_CR3_RXFTIE));

        /* Rx process is completed, restore hsci->gState to Ready */
        hsci->RxState = HAL_SCI_STATE_READY;
        
        /* Clear RxISR function pointer */
        hsci->RxISR = NULL;

        /* Initialize type of RxEvent to Transfer Complete */
        hsci->RxEventType = HAL_SCI_RXEVENT_TC;

        /* Check that USART RTOEN bit is set */
        if (READ_BIT(hsci->Instance->CR2, USART_CR2_RTOEN) != 0U)
        {
          /* Enable the SCI Receiver Timeout Interrupt */
          CLEAR_BIT(hsci->Instance->CR3, USART_CR3_RTOIE);
        }

        /* Check current reception Mode :
           If Reception till IDLE event has been selected : */
        if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
        {
          /* Set reception type to Standard */
          hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

          /* Disable IDLE interrupt */
          CLEAR_BIT(hsci->Instance->CR1, USART_CR1_IDLEIE);

          if (__HAL_SCI_GET_FLAG(hsci, SCI_FLAG_IDLE) == SET)
          {
            /* Clear IDLE Flag */
            __HAL_SCI_CLEAR_IDLEFLAG(hsci);
          }

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
          /*Call registered Rx Event callback*/
          hsci->RxEventCallback(hsci, hsci->RxXferSize);
#else
          /*Call legacy weak Rx Event callback*/
          HAL_SCIEx_RxEventCallback(hsci, hsci->RxXferSize);
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */
        }
        else
        {
          /* Standard reception API called */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
          /*Call registered Rx complete callback*/
          hsci->RxCpltCallback(hsci);
#else
          /* Call legacy weak Rx Complete Callback */
          HAL_SCI_RxCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
        }
      }
    }
    /* When remaining number of bytes to receive is less than the RX FIFO
    threshold, next incoming frames are processed as if FIFO mode was
    disabled (i.e. one interrupt per received frame).
    */
    rxdatacount = hsci->RxXferCount;
    if (((rxdatacount != 0U)) && (rxdatacount < hsci->NbRxDataToProcess))
    {
      /* Disable the SCI RXFT interrupt*/
      CLEAR_BIT(hsci->Instance->CR3, USART_CR3_RXFTIE);

      /* Update the RxISR function pointer */
      hsci->RxISR = SCI_RxSR_8BIT;

      /* Enable the SCI Data Register Not Empty interrupt */
      SET_BIT(hsci->Instance->CR1, USART_CR1_RXNEIE);
    }
  }
  else
  {
    /* Clear RXNE interrupt flag */
    __HAL_SCI_SEND_REQ(hsci, SCI_RXDATA_FLUSH_REQUEST);
  }
}

/**
  * @brief  Simplex receive an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_SCI_Receive_IT().
  * @note   ISR function executed when FIFO mode is enabled and when the
  *         data word length is 9 bits long.
  * @param  hsci SCI handle
  * @retval None
  */
static void SCI_RxSR_16BIT_FIFOEN(SCI_HandleTypeDef *hsci)
{
  uint16_t *tmp;
  uint16_t uhMask = hsci->Mask;
  uint16_t uhdata;
  uint32_t nb_rx_data;
  uint32_t rxdatacount;

  /* Check that a Tx process is ongoing */
  if (hsci->RxState == HAL_SCI_STATE_BUSY_RX)
  {
    for (nb_rx_data = hsci->NbRxDataToProcess ; nb_rx_data > 0U ; nb_rx_data--)
    {
      uhdata = (uint16_t) READ_REG(hsci->Instance->DR);
      tmp = (uint16_t *) hsci->pRxBuffPtr;
      *tmp = (uint16_t)(uhdata & uhMask);
      hsci->pRxBuffPtr += 2U;
      hsci->RxXferCount--;

      if (hsci->RxXferCount == 0U)
      {
        /* Disable the SCI Parity Error Interrupt */
        CLEAR_BIT(hsci->Instance->CR1, USART_CR1_PEIE);

        /* Disable the SCI Error Interrupt: (Frame error, noise error, overrun error)
           and RX FIFO Threshold interrupt */
        CLEAR_BIT(hsci->Instance->CR3, (USART_CR3_EIE | USART_CR3_RXFTIE));

        /* Rx process is completed, restore hsci->gState to Ready */
        hsci->RxState = HAL_SCI_STATE_READY;
        
        /* Clear RxISR function pointer */
        hsci->RxISR = NULL;

        /* Initialize type of RxEvent to Transfer Complete */
        hsci->RxEventType = HAL_SCI_RXEVENT_TC;

        /* Check that USART RTOEN bit is set */
        if (READ_BIT(hsci->Instance->CR2, USART_CR2_RTOEN) != 0U)
        {
          /* Enable the SCI Receiver Timeout Interrupt */
          ATOMIC_CLEAR_BIT(hsci->Instance->CR3, USART_CR3_RTOIE);
        }

        /* Check current reception Mode :
           If Reception till IDLE event has been selected : */
        if (hsci->ReceptionType == HAL_SCI_RECEPTION_TOIDLE)
        {
          /* Set reception type to Standard */
          hsci->ReceptionType = HAL_SCI_RECEPTION_STANDARD;

          /* Disable IDLE interrupt */
          ATOMIC_CLEAR_BIT(hsci->Instance->CR1, USART_CR1_IDLEIE);

          if (__HAL_SCI_GET_FLAG(hsci, SCI_FLAG_IDLE) == SET)
          {
            /* Clear IDLE Flag */
            __HAL_SCI_CLEAR_IDLEFLAG(hsci);
          }

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
          /*Call registered Rx Event callback*/
          hsci->RxEventCallback(hsci, hsci->RxXferSize);
#else
          /*Call legacy weak Rx Event callback*/
          HAL_SCIEx_RxEventCallback(hsci, hsci->RxXferSize);
#endif /* (USE_HAL_SCI_REGISTER_CALLBACKS) */
        }
        else
        {
          /* Standard reception API called */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
          /*Call registered Rx complete callback*/
          hsci->RxCpltCallback(hsci);
#else
          /* Call legacy weak Rx Complete Callback */
          HAL_SCI_RxCpltCallback(hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
        }
      }
    }

    /* When remaining number of bytes to receive is less than the RX FIFO
    threshold, next incoming frames are processed as if FIFO mode was
    disabled (i.e. one interrupt per received frame).
    */
    rxdatacount = hsci->RxXferCount;
    if (((rxdatacount != 0U)) && (rxdatacount < hsci->NbRxDataToProcess))
    {
      /* Disable the SCI RXFT interrupt*/
      CLEAR_BIT(hsci->Instance->CR3, USART_CR3_RXFTIE);

      /* Update the RxISR function pointer */
      hsci->RxISR = SCI_RxSR_16BIT;

      /* Enable the SCI Data Register Not Empty interrupt */
      SET_BIT(hsci->Instance->CR1, USART_CR1_RXNEIE);
    }
  }
  else
  {
    /* Clear RXNE interrupt flag */
    __HAL_SCI_SEND_REQ(hsci, SCI_RXDATA_FLUSH_REQUEST);
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
/**
  * @}
  */
/************************ (C) COPYRIGHT Puya *****END OF FILE****/
