/**
  ******************************************************************************
  * @file    py32e407_hal_uart.c
  * @author  MCU Application Team
  * @brief   UART HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Universal Asynchronous Receiver Transmitter Peripheral (UART).
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *           + Peripheral Control functions
  *           + Peripheral State and Errors functions
  @verbatim
  ==============================================================================
                        ##### How to use this driver #####
  ==============================================================================
  [..]
    The UART HAL driver can be used as follows:

    (#) Declare a UART_HandleTypeDef handle structure (eg. UART_HandleTypeDef huart).
    (#) Initialize the UART low level resources by implementing the HAL_UART_MspInit() API:
        (##) Enable the UARTx interface clock.
        (##) UART pins configuration:
            (+++) Enable the clock for the UART GPIOs.
            (+++) Configure these UART pins (TX as alternate function pull-up, RX as alternate function Input).
        (##) NVIC configuration if you need to use interrupt process (HAL_UART_Transmit_IT()
             and HAL_UART_Receive_IT() APIs):
            (+++) Configure the UARTx interrupt priority.
            (+++) Enable the NVIC UART IRQ handle.

    (#) Program the Baud Rate, Word Length, Stop Bit, Parity, first bit(MSB/LSB) 
        and Mode(Receiver/Transmitter) in the huart Init structure.

    (#) Initialize the UART registers by calling the HAL_UART_Init() API.

     [..]
       (@) The specific UART interrupts (Transmission complete interrupt,
            RXNE interrupt and Error Interrupts) will be managed using the macros
            __HAL_UART_ENABLE_IT() and __HAL_UART_DISABLE_IT() inside the transmit
            and receive process.

     [..]
       (@)  HAL_UART_Init() configure also the low level Hardware GPIO, CLOCK, 
            CORTEX...etc) by calling the customized HAL_UART_MspInit() API.

    ##### Callback registration #####
    ==================================

    [..]
    The compilation define USE_HAL_UART_REGISTER_CALLBACKS when set to 1
    allows the user to configure dynamically the driver callbacks.

    [..]
    Use Function @ref HAL_UART_RegisterCallback() to register a user callback.
    Function @ref HAL_UART_RegisterCallback() allows to register following callbacks:
    (+) TxCpltCallback            : Tx Complete Callback.
    (+) RxCpltCallback            : Rx Complete Callback.
    (+) TxBlockCpltCallback       : Tx Block Complete Callback.
    (+) TxHalfBlockCpltCallback   : Tx Half Block Complete Callback.
    (+) TxSrcCpltCallback         : Tx Source Complete Callback.
    (+) RxBlockCpltCallback       : Rx Half Block Complete Callback.
    (+) RxHalfBlockCpltCallback   : Rx Block Complete Callback.
    (+) RxDstCpltCallback         : Rx Destination Complete Callback.
    (+) ErrorCallback             : Error Callback.
    (+) AbortCpltCallback         : Abort Complete Callback.
    (+) AbortTransmitCpltCallback : Abort Transmit Complete Callback.
    (+) AbortReceiveCpltCallback  : Abort Receive Complete Callback.
    (+) BreakFrameCallback        : Break Frame Detection Callback.
    (+) AddrMatchCallback         : Address Match Callback.
    (+) MspInitCallback           : UART MspInit.
    (+) MspDeInitCallback         : UART MspDeInit.
    This function takes as parameters the HAL peripheral handle, the Callback ID
    and a pointer to the user callback function.

    [..]
    Use function @ref HAL_UART_UnRegisterCallback() to reset a callback to the default
    weak (surcharged) function.
    @ref HAL_UART_UnRegisterCallback() takes as parameters the HAL peripheral handle,
    and the Callback ID.
    This function allows to reset following callbacks:
    (+) TxCpltCallback            : Tx Complete Callback.
    (+) RxCpltCallback            : Rx Complete Callback.
    (+) TxBlockCpltCallback       : Tx Block Complete Callback.
    (+) TxHalfBlockCpltCallback   : Tx Half Block Complete Callback.
    (+) TxSrcCpltCallback         : Tx Source Complete Callback.
    (+) RxBlockCpltCallback       : Rx Half Block Complete Callback.
    (+) RxHalfBlockCpltCallback   : Rx Block Complete Callback.
    (+) RxDstCpltCallback         : Rx Destination Complete Callback.
    (+) ErrorCallback             : Error Callback.
    (+) AbortCpltCallback         : Abort Complete Callback.
    (+) AbortTransmitCpltCallback : Abort Transmit Complete Callback.
    (+) AbortReceiveCpltCallback  : Abort Receive Complete Callback.
    (+) BreakFrameCallback        : Break Frame Detection Callback.
    (+) AddrMatchCallback         : Address Match Callback.
    (+) MspInitCallback           : UART MspInit.
    (+) MspDeInitCallback         : UART MspDeInit.

    [..]
    By default, after the @ref HAL_UART_Init() and when the state is HAL_UART_STATE_RESET
    all callbacks are set to the corresponding weak (surcharged) functions:
    examples @ref HAL_UART_TxCpltCallback(), @ref HAL_UART_RxCpltCallback().
    Exception done for MspInit and MspDeInit functions that are respectively
    reset to the legacy weak (surcharged) functions in the @ref HAL_UART_Init()
    and @ref HAL_UART_DeInit() only when these callbacks are null (not registered beforehand).
    If not, MspInit or MspDeInit are not null, the @ref HAL_UART_Init() and @ref HAL_UART_DeInit()
    keep and use the user MspInit/MspDeInit callbacks (registered beforehand).

    [..]
    Callbacks can be registered/unregistered in HAL_UART_STATE_READY state only.
    Exception done MspInit/MspDeInit that can be registered/unregistered
    in HAL_UART_STATE_READY or HAL_UART_STATE_RESET state, thus registered (user)
    MspInit/DeInit callbacks can be used during the Init/DeInit.
    In that case first register the MspInit/MspDeInit user callbacks
    using @ref HAL_UART_RegisterCallback() before calling @ref HAL_UART_DeInit()
    or @ref HAL_UART_Init() function.

    [..]
    When The compilation define USE_HAL_UART_REGISTER_CALLBACKS is set to 0 or
    not defined, the callback registration feature is not available
    and weak (surcharged) callbacks are used.

     [..]
        Two operation modes are available within this driver :

     *** Polling mode IO operation ***
     =================================
     [..]
       (+) Send an amount of data in blocking mode using HAL_UART_Transmit()
       (+) Receive an amount of data in blocking mode using HAL_UART_Receive()

     *** Interrupt mode IO operation ***
     ===================================
     [..]
       (+) Send an amount of data in non blocking mode using HAL_UART_Transmit_IT()
       (+) At transmission end of transfer HAL_UART_TxCpltCallback is executed and user can
            add his own code by customization of function pointer HAL_UART_TxCpltCallback
       (+) Receive an amount of data in non blocking mode using HAL_UART_Receive_IT()
       (+) At reception end of transfer HAL_UART_RxCpltCallback is executed and user can
            add his own code by customization of function pointer HAL_UART_RxCpltCallback
       (+) In case of transfer Error, HAL_UART_ErrorCallback() function is executed and user can
            add his own code by customization of function pointer HAL_UART_ErrorCallback

     *** UART HAL driver macros list ***
     =============================================
     [..]
       Below the list of most used macros in UART HAL driver.

      (+) __HAL_UART_GET_FLAG : Check whether the specified UART flag is set or not
      (+) __HAL_UART_CLEAR_FLAG : Clear the specified UART pending flag
      (+) __HAL_UART_ENABLE_IT: Enable the specified UART interrupt
      (+) __HAL_UART_DISABLE_IT: Disable the specified UART interrupt
      (+) __HAL_UART_GET_IT_SOURCE: Check whether the specified UART interrupt has occurred or not

     [..]
       (@) You can refer to the UART HAL driver header file for more useful macros

  @endverbatim
     [..]
       (@) Additionnal remark: If the parity is enabled, then the MSB bit of the data written
           in the data register is transmitted but is changed by the parity bit.
           Depending on the frame length defined by the M_E bit (8-bits or 9-bits),
           the possible UART frame formats are as listed in the following table:
    +-------------------------------------------------------------+
    | M_E bit |  PCE bit  |            UART frame                 |
    |---------------------|---------------------------------------|
    |    0    |    0      |    | SB | 8 bit data | STB |          |
    |---------|-----------|---------------------------------------|
    |    0    |    1      |    | SB | 8 bit data | PB | STB |     |
    |---------|-----------|---------------------------------------|
    |    1    |    0      |    | SB | 9 bit data | STB |          |
    |---------|-----------|---------------------------------------|
    |    1    |    1      |    | SB | 9 bit data | PB | STB |     |
    +-------------------------------------------------------------+
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

/** @defgroup UART UART
  * @brief HAL UART module driver
  * @{
  */
#ifdef HAL_UART_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup UART_Private_Functions  UART Private Functions
  * @{
  */

static void UART_DMASrcTranCplt(DMA_HandleTypeDef *hdma);
static void UART_DMADstTranCplt(DMA_HandleTypeDef *hdma);

static void UART_DMAReceiveCplt(DMA_HandleTypeDef *hdma);
static void UART_DMARxBlockCplt(DMA_HandleTypeDef *hdma);
static void UART_DMARxHalfBlockCplt(DMA_HandleTypeDef *hdma);

static void UART_DMATransmitCplt(DMA_HandleTypeDef *hdma);
static void UART_DMATxBlockCplt(DMA_HandleTypeDef *hdma);
static void UART_DMATxHalfBlockCplt(DMA_HandleTypeDef *hdma);

static void UART_EndTxTransfer(UART_HandleTypeDef *huart);
static void UART_EndRxTransfer(UART_HandleTypeDef *huart);
static void UART_DMAError(DMA_HandleTypeDef *hdma);
static void UART_DMAAbortOnError(DMA_HandleTypeDef *hdma);
static void UART_DMATxAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMARxAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma);
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
void UART_InitCallbacksToDefault(UART_HandleTypeDef *huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
static HAL_StatusTypeDef UART_WaitOnFlagUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status, uint32_t Tickstart, uint32_t Timeout);
static HAL_StatusTypeDef UART_Transmit_IT(UART_HandleTypeDef *huart);
static HAL_StatusTypeDef UART_Receive_IT(UART_HandleTypeDef *huart);
/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @defgroup UART_Exported_Functions UART Exported Functions
  * @{
  */
/** @defgroup UART_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
  * @{
  */
/**
  * @brief  Initializes the UART mode according to the specified parameters in
  *         the UART_InitTypeDef and create the associated handle.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart)
{
  uint64_t pclk;
  uint64_t integer = 0;
  
  /* Check the UART handle allocation */
  if (huart == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_UART_INSTANCE(huart->Instance));
  assert_param(IS_UART_WORD_LENGTH(huart->Init.WordLength));
  assert_param(IS_UART_STOPBITS(huart->Init.StopBits));
  assert_param(IS_UART_PARITY(huart->Init.Parity));
  assert_param(IS_UART_MSB_FIRST(huart->Init.MsbFirst));

  if (huart->gState == HAL_UART_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    huart->Lock = HAL_UNLOCKED;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    UART_InitCallbacksToDefault(huart);

    if (huart->MspInitCallback == NULL)
    {
      huart->MspInitCallback = HAL_UART_MspInit;
    }

    /* Init the low level hardware */
    huart->MspInitCallback(huart);
#else
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_UART_MspInit(huart);
#endif /* (USE_HAL_UART_REGISTER_CALLBACKS) */
  }

  huart->gState = HAL_UART_STATE_BUSY;
  
  pclk = HAL_RCC_GetPCLK1Freq();
  integer = UART_BRR_SAMPLING16(pclk, huart->Init.BaudRate);
  MODIFY_REG(huart->Instance->BRR,  UART_BRR_BRR,   ((integer >> 4) & 0xFFFF));
  MODIFY_REG(huart->Instance->BRRF, UART_BRRF_BRRF, (integer & 0xF));
  
  MODIFY_REG(huart->Instance->CR1, (UART_CR1_STOP | UART_CR1_PCE | UART_CR1_PS | UART_CR1_SP | UART_CR1_MSBFIRST), \
                                   (huart->Init.StopBits | huart->Init.Parity | huart->Init.MsbFirst));

  if (huart->Init.WordLength == UART_WORDLENGTH_9B)
  {
    assert_param(IS_UART_TX_MODE(huart->Init.TxMode));
    assert_param(IS_UART_RX_MODE(huart->Init.RxMode));
    
    SET_BIT(huart->Instance->CR3, UART_CR3_M_E);
    
    MODIFY_REG(huart->Instance->CR3, (UART_CR3_TX_MODE | UART_CR3_ADDR_MATCH), (huart->Init.TxMode | huart->Init.RxMode));
    
    if (huart->Init.RxMode == UART_RX_ADDR_MATCH_HARD)
    {
      assert_param(IS_UART_RX_MATCH_ADDR(huart->Init.RxMatchAddr));
      MODIFY_REG(huart->Instance->RAR, UART_RAR_RAR, (huart->Init.RxMatchAddr & 0xFF));
    }
  }
  else
  {
    CLEAR_BIT(huart->Instance->CR3, UART_CR3_M_E);
    MODIFY_REG(huart->Instance->CR1, UART_CR1_M, huart->Init.WordLength);
  }

  /* Initialize the UART state */
  huart->ErrorCode = HAL_UART_ERROR_NONE;
  huart->gState = HAL_UART_STATE_READY;
  huart->RxState = HAL_UART_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  DeInitializes the UART peripheral.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart)
{
  /* Check the UART handle allocation */
  if (huart == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_UART_INSTANCE(huart->Instance));

  huart->gState = HAL_UART_STATE_BUSY;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  if (huart->MspDeInitCallback == NULL)
  {
    huart->MspDeInitCallback = HAL_UART_MspDeInit;
  }
  /* DeInit the low level hardware */
  huart->MspDeInitCallback(huart);
#else
  /* DeInit the low level hardware */
  HAL_UART_MspDeInit(huart);
#endif /* (USE_HAL_UART_REGISTER_CALLBACKS) */

  huart->ErrorCode = HAL_UART_ERROR_NONE;
  huart->gState = HAL_UART_STATE_RESET;
  huart->RxState = HAL_UART_STATE_RESET;

  /* Process Unlock */
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

/**
  * @brief  UART MSP Init.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
__weak void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_MspInit could be implemented in the user file
   */
}

/**
  * @brief  UART MSP DeInit.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
__weak void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_MspDeInit could be implemented in the user file
   */
}

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User UART Callback
  *         To be used instead of the weak predefined callback
  * @param  huart uart handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_UART_TX_COMPLETE_CB_ID Tx Complete Callback ID
  *           @arg @ref HAL_UART_RX_COMPLETE_CB_ID Rx Complete Callback ID
  *           @arg @ref HAL_UART_TX_BLOCK_COMPLETE_CB_ID Tx Block Complete Callback ID
  *           @arg @ref HAL_UART_TX_HALF_BLOCKCOMPLETE_CB_ID Tx Half Block Complete Callback ID
  *           @arg @ref HAL_UART_TX_SRC_COMPLETE_CB_ID Tx Source Complete Callback ID
  *           @arg @ref HAL_UART_RX_BLOCK_COMPLETE_CB_ID Rx Block Complete Callback ID
  *           @arg @ref HAL_UART_RX_HALFBLOCK_COMPLETE_CB_ID Rx Half Block Complete Callback ID
  *           @arg @ref HAL_UART_RX_DST_COMPLETE_CB_ID Rx Destination Complete Callback ID
  *           @arg @ref HAL_UART_ERROR_CB_ID Error Callback ID
  *           @arg @ref HAL_UART_ABORT_COMPLETE_CB_ID Abort Complete Callback ID
  *           @arg @ref HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID Abort Transmit Complete Callback ID
  *           @arg @ref HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID Abort Receive Complete Callback ID
  *           @arg @ref HAL_UART_BREAK_FRAME_CB_ID UART Break Frame Detection Callback ID
  *           @arg @ref HAL_UART_ADDR_MATCH_CB_ID UART Address Match Callback ID
  *           @arg @ref HAL_UART_MSPINIT_CB_ID MspInit Callback ID
  *           @arg @ref HAL_UART_MSPDEINIT_CB_ID MspDeInit Callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_RegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID, pUART_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(huart);

  if (huart->gState == HAL_UART_STATE_READY)
  {
    switch (CallbackID)
    {
    case HAL_UART_TX_COMPLETE_CB_ID :
      huart->TxCpltCallback = pCallback;
      break;

    case HAL_UART_RX_COMPLETE_CB_ID :
      huart->RxCpltCallback = pCallback;
      break;

    case HAL_UART_TX_BLOCK_COMPLETE_CB_ID :
      huart->TxBlockCpltCallback = pCallback;
      break;

    case HAL_UART_TX_HALF_BLOCK_COMPLETE_CB_ID :
      huart->TxHalfBlockCpltCallback = pCallback;
      break;

    case HAL_UART_TX_SRC_COMPLETE_CB_ID :
      huart->TxSrcCpltCallback = pCallback;
      break;

    case HAL_UART_RX_BLOCK_COMPLETE_CB_ID :
      huart->RxBlockCpltCallback = pCallback;
      break;

    case HAL_UART_RX_HALF_BLOCK_COMPLETE_CB_ID :
      huart->RxHalfBlockCpltCallback = pCallback;
      break;

    case HAL_UART_RX_DST_COMPLETE_CB_ID :
      huart->RxDstCpltCallback = pCallback;
      break;

    case HAL_UART_ERROR_CB_ID :
      huart->ErrorCallback = pCallback;
      break;

    case HAL_UART_ABORT_COMPLETE_CB_ID :
      huart->AbortCpltCallback = pCallback;
      break;

    case HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID :
      huart->AbortTransmitCpltCallback = pCallback;
      break;

    case HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID :
      huart->AbortReceiveCpltCallback = pCallback;
      break;
      
    case HAL_UART_BREAK_FRAME_CB_ID :
      huart->BreakFrameCallback = pCallback;
      break;
      
    case HAL_UART_ADDR_MATCH_CB_ID :
      huart->AddrMatchCallback = pCallback;
      break;

    case HAL_UART_MSPINIT_CB_ID :
      huart->MspInitCallback = pCallback;
      break;

    case HAL_UART_MSPDEINIT_CB_ID :
      huart->MspDeInitCallback = pCallback;
      break;

    default :
      /* Update the error code */
      huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else if (huart->gState == HAL_UART_STATE_RESET)
  {
    switch (CallbackID)
    {
    case HAL_UART_MSPINIT_CB_ID :
      huart->MspInitCallback = pCallback;
      break;

    case HAL_UART_MSPDEINIT_CB_ID :
      huart->MspDeInitCallback = pCallback;
      break;

    default :
      /* Update the error code */
      huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* Update the error code */
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(huart);

  return status;
}

/**
  * @brief  Unregister an UART Callback
  *         UART callaback is redirected to the weak predefined callback
  * @param  huart uart handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_UART_TX_COMPLETE_CB_ID Tx Complete Callback ID
  *           @arg @ref HAL_UART_RX_COMPLETE_CB_ID Rx Complete Callback ID
  *           @arg @ref HAL_UART_TX_BLOCK_COMPLETE_CB_ID Tx Block Complete Callback ID
  *           @arg @ref HAL_UART_TX_HALF_BLOCK_COMPLETE_CB_ID Tx Half Block Complete Callback ID
  *           @arg @ref HAL_UART_TX_SRC_COMPLETE_CB_ID Tx Source Complete Callback ID
  *           @arg @ref HAL_UART_RX_BLOCK_COMPLETE_CB_ID Rx Block Complete Callback ID
  *           @arg @ref HAL_UART_RX_HALF_BLOCK_COMPLETE_CB_ID Rx Half Block Complete Callback ID
  *           @arg @ref HAL_UART_RX_DST_COMPLETE_CB_ID Rx Destination Complete Callback ID
  *           @arg @ref HAL_UART_ERROR_CB_ID Error Callback ID
  *           @arg @ref HAL_UART_ABORT_COMPLETE_CB_ID Abort Complete Callback ID
  *           @arg @ref HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID Abort Transmit Complete Callback ID
  *           @arg @ref HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID Abort Receive Complete Callback ID
  *           @arg @ref HAL_UART_BREAK_FRAME_CB_ID UART Break Frame Detection Callback ID
  *           @arg @ref HAL_UART_ADDR_MATCH_CB_ID UART Address Match Callback ID
  *           @arg @ref HAL_UART_MSPINIT_CB_ID MspInit Callback ID
  *           @arg @ref HAL_UART_MSPDEINIT_CB_ID MspDeInit Callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_UnRegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(huart);

  if (HAL_UART_STATE_READY == huart->gState)
  {
    switch (CallbackID)
    {
    case HAL_UART_TX_COMPLETE_CB_ID :
      huart->TxCpltCallback = HAL_UART_TxCpltCallback;                       /* Legacy weak TxCpltCallback            */
      break;

    case HAL_UART_RX_COMPLETE_CB_ID :
      huart->RxCpltCallback = HAL_UART_RxCpltCallback;                       /* Legacy weak RxCpltCallback            */
      break;

    case HAL_UART_TX_BLOCK_COMPLETE_CB_ID :
      huart->TxBlockCpltCallback = HAL_UART_TxBlockCpltCallback;             /* Legacy weak TxBlockCpltCallback       */
      break;

    case HAL_UART_TX_HALF_BLOCK_COMPLETE_CB_ID :
      huart->TxHalfBlockCpltCallback = HAL_UART_TxHalfBlockCpltCallback;     /* Legacy weak TxHalfBlockCpltCallback   */
      break;

    case HAL_UART_TX_SRC_COMPLETE_CB_ID :
      huart->TxSrcCpltCallback = HAL_UART_TxSrcCpltCallback;                 /* Legacy weak TxSrcCpltCallback         */
      break;

    case HAL_UART_RX_BLOCK_COMPLETE_CB_ID :
      huart->RxBlockCpltCallback = HAL_UART_RxBlockCpltCallback;             /* Legacy weak RxBlockCpltCallback       */
      break;

    case HAL_UART_RX_HALF_BLOCK_COMPLETE_CB_ID :
      huart->RxHalfBlockCpltCallback = HAL_UART_RxHalfBlockCpltCallback;     /* Legacy weak RxHalfBlockCpltCallback   */
      break;

    case HAL_UART_RX_DST_COMPLETE_CB_ID :
      huart->RxDstCpltCallback = HAL_UART_RxDstCpltCallback;                 /* Legacy weak RxDstCpltCallback         */
      break;

    case HAL_UART_ERROR_CB_ID :
      huart->ErrorCallback = HAL_UART_ErrorCallback;                         /* Legacy weak ErrorCallback             */
      break;

    case HAL_UART_ABORT_COMPLETE_CB_ID :
      huart->AbortCpltCallback = HAL_UART_AbortCpltCallback;                 /* Legacy weak AbortCpltCallback         */
      break;

    case HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID :
      huart->AbortTransmitCpltCallback = HAL_UART_AbortTransmitCpltCallback; /* Legacy weak AbortTransmitCpltCallback */
      break;

    case HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID :
      huart->AbortReceiveCpltCallback = HAL_UART_AbortReceiveCpltCallback;   /* Legacy weak AbortReceiveCpltCallback  */
      break;
    
    case HAL_UART_BREAK_FRAME_CB_ID :
      huart->BreakFrameCallback = HAL_UART_BreakFrameCallback;               /* Legacy weak HAL_UART_BreakFrameCallback  */
      break;
      
    case HAL_UART_ADDR_MATCH_CB_ID :
      huart->AddrMatchCallback = HAL_UART_AddrMatchCallback;                 /* Legacy weak HAL_UART_AddrMatchCallback  */
      break;

    case HAL_UART_MSPINIT_CB_ID :
      huart->MspInitCallback = HAL_UART_MspInit;                             /* Legacy weak MspInitCallback           */
      break;

    case HAL_UART_MSPDEINIT_CB_ID :
      huart->MspDeInitCallback = HAL_UART_MspDeInit;                         /* Legacy weak MspDeInitCallback         */
      break;

    default :
      /* Update the error code */
      huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else if (HAL_UART_STATE_RESET == huart->gState)
  {
    switch (CallbackID)
    {
    case HAL_UART_MSPINIT_CB_ID :
      huart->MspInitCallback = HAL_UART_MspInit;
      break;

    case HAL_UART_MSPDEINIT_CB_ID :
      huart->MspDeInitCallback = HAL_UART_MspDeInit;
      break;

    default :
      /* Update the error code */
      huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* Update the error code */
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(huart);

  return status;
}
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup UART_Exported_Functions_Group2 IO operation functions
  *  @brief UART Transmit and Receive functions
  *
  * @{
  */

/**
  * @brief  Sends an amount of data in blocking mode.
  * @note   When Word Length is configured to 9 bits,
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @param  huart Pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART module.
  * @param  addr Slave address to be sent.
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_TransmitAddr(UART_HandleTypeDef *huart, uint8_t *addr, uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint16_t *pdata16bits;
  uint32_t tickstart = 0U;
  
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if (addr == NULL)
    {
      return  HAL_ERROR;
    }
    
    /* In case of 9bits transfer, pData buffer provided as input parameter
       should be aligned on a u16 frontier, as data to be filled into DR will be
       handled through a u16 cast. */
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.TxMode == UART_TX_MODE_1))
    {
      if ((((uint32_t)addr) & 1U) != 0U)
      {
        return  HAL_ERROR;
      }
    }
    
    /* Process Locked */
    __HAL_LOCK(huart);
    
    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX;
    
    /* Init tickstart for timeout managment */
    tickstart = HAL_GetTick();
    
    /* If 9-bit data length, transmission mode 1 */
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.TxMode == UART_TX_MODE_1))
    {
      /* Waiting for TDRE flag to be set */
      if (UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_TDRE, RESET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
      
      /* Sending Address */
      pdata16bits = (uint16_t *) addr;
      huart->Instance->DR = (uint16_t)(*pdata16bits & 0x01FFU);
      
      /* Waiting for sending to complete */
      if (UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_TXE, RESET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
    }
    /* If 9-bit data length, transmission mode 0 */
    else
    {
      /* Sending Address */
      pdata8bits  = addr;
      huart->Instance->TAR = (uint8_t)(*pdata8bits & 0xFFU);
      SET_BIT(huart->Instance->CR3, UART_CR3_SEND_ADDR);
      
      /* Waiting for SEND_ ADDR bit clear */
      while (READ_BIT(huart->Instance->CR3, UART_CR3_SEND_ADDR) == UART_CR3_SEND_ADDR)
      {
        /* Check for the Timeout */
        if (Timeout != HAL_MAX_DELAY)
        {
          if ((Timeout == 0U) || ((HAL_GetTick() - tickstart) > Timeout))
          {
            huart->gState  = HAL_UART_STATE_READY;
            
            /* Process Unlocked */
            __HAL_UNLOCK(huart);

            return HAL_TIMEOUT;
          }
        }
      }
    }
    
    /* At end of Tx process, restore huart->gState to Ready */
    huart->gState = HAL_UART_STATE_READY;
    
    /* Process Unlocked */
    __HAL_UNLOCK(huart);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Sends an amount of data in blocking mode.
  * @note   When Word Length is configured to 9 bits,
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @param  huart Pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART module.
  * @param  pData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size, uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint16_t *pdata16bits;
  uint32_t tickstart = 0U;

  /* Check that a Tx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }
    /* In case of 9bits transfer, pData buffer provided as input parameter
       should be aligned on a u16 frontier, as data to be filled into DR will be
       handled through a u16 cast. */
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.TxMode == UART_TX_MODE_1))
    {
      if ((((uint32_t)pData) & 1U) != 0U)
      {
        return  HAL_ERROR;
      }
    }
    /* Process Locked */
    __HAL_LOCK(huart);

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX;

    /* Init tickstart for timeout managment */
    tickstart = HAL_GetTick();

    huart->TxXferSize = Size;
    huart->TxXferCount = Size;

    /* In case of 9bits/No Parity transfer, pData needs to be handled as a uint16_t pointer */
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.TxMode == UART_TX_MODE_1))
    {
      pdata8bits  = NULL;
      pdata16bits = (uint16_t *) pData;
    }
    else
    {
      pdata8bits  = pData;
      pdata16bits = NULL;
    }

    while (huart->TxXferCount > 0U)
    {
      if (UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_TDRE, RESET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
      
      if (pdata8bits == NULL)
      {
        huart->Instance->DR = (uint16_t)(*pdata16bits & 0x01FFU);
        pdata16bits++;
      }
      else
      {
        huart->Instance->DR = (uint8_t)(*pdata8bits & 0xFFU);
        pdata8bits++;
      }

      huart->TxXferCount--;
    }

    if (UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_TXE, RESET, tickstart, Timeout) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    /* At end of Tx process, restore huart->gState to Ready */
    huart->gState = HAL_UART_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(huart);

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
  * @param  huart Pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART module.
  * @param  pData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be received.
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size, uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint16_t *pdata16bits;
  uint32_t tickstart = 0U;

  /* Check that a Rx process is not already ongoing */
  if (huart->RxState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }
    /* In case of 9bits, pData buffer provided as input parameter
       should be aligned on a u16 frontier, as data to be received from RDR will be
       handled through a u16 cast. */
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.RxMode == UART_RX_ADDR_MATCH_SOFT))
    {
      if ((((uint32_t)pData) & 1U) != 0U)
      {
        return  HAL_ERROR;
      }
    }
    /* Process Locked */
    __HAL_LOCK(huart);

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->RxState = HAL_UART_STATE_BUSY_RX;

    /* Init tickstart for timeout managment */
    tickstart = HAL_GetTick();

    huart->RxXferSize = Size;
    huart->RxXferCount = Size;

    /* In case of 9bits, pRxData needs to be handled as a uint16_t pointer */
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.RxMode == UART_RX_ADDR_MATCH_SOFT))
    {
      pdata8bits  = NULL;
      pdata16bits = (uint16_t *) pData;
    }
    else
    {
      pdata8bits  = pData;
      pdata16bits = NULL;
    }
    
    /* as long as data have to be received */
    while (huart->RxXferCount > 0U)
    {
      if (UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_RXNE, RESET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
      if (pdata8bits == NULL)
      {
        *pdata16bits = (uint16_t)(huart->Instance->DR & 0x1FF);
        pdata16bits++;
      }
      else
      {
        *pdata8bits = (uint8_t)(huart->Instance->DR & (uint8_t)0xFF);
        pdata8bits++;
      }
      huart->RxXferCount--;
    }
    /* At end of Rx process, restore huart->RxState to Ready */
    huart->RxState = HAL_UART_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(huart);

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
  * @param  huart Pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART module.
  * @param  pData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size)
{
  /* Check that a Tx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(huart);

    huart->pTxBuffPtr = pData;
    huart->TxXferSize = Size;
    huart->TxXferCount = Size;

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX;

    /* Process Unlocked */
    __HAL_UNLOCK(huart);

    /* Enable the BUSYERR status interrupt and Transfer Hold Register empty interrupt */
    __HAL_UART_ENABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_TDRE));

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
  * @param  huart Pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART module.
  * @param  pData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size)
{
  /* Check that a Rx process is not already ongoing */
  if (huart->RxState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(huart);

    huart->pRxBuffPtr = pData;
    huart->RxXferSize = Size;
    huart->RxXferCount = Size;

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->RxState = HAL_UART_STATE_BUSY_RX;

    /* Process Unlocked */
    __HAL_UNLOCK(huart);

    /* Enable the UART BUSYERR status interrupt , Receiver line status interrupt and Data Register not empty Interrupt */
    __HAL_UART_ENABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_LS | UART_IT_RXNE));

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Sends an amount of data in DMA mode.
  * @note   When UART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @param  pData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size)
{
  uint32_t *tmp;

  /* Check that a Tx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }
    /* In case of 9bits transfer, pData buffer provided as input parameter
       should be aligned on a u16 frontier, as data to be filled into DR will be
       handled through a u16 cast. */
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.TxMode == UART_TX_MODE_1))
    {
      if ((((uint32_t)pData) & 1U) != 0U)
      {
        return  HAL_ERROR;
      }
    }
    /* Process Locked */
    __HAL_LOCK(huart);

    huart->pTxBuffPtr = pData;
    huart->TxXferSize = Size;
    huart->TxXferCount = Size;

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX;

    /* Set the UART DMA transfer complete callback */
    huart->hdmatx->XferCpltCallback = UART_DMATransmitCplt;

    /* Set the UART DMA Half Block transfer Half complete callback */
    huart->hdmatx->XferHalfBlockCpltCallback = UART_DMATxHalfBlockCplt;

    /* Set the UART DMA Block transfer complete callback */
    huart->hdmatx->XferBlockCpltCallback = UART_DMATxBlockCplt;
    
    /* Set the UART DMA Source transfer complete callback */
    huart->hdmatx->XferSrcTranCpltCallback = UART_DMASrcTranCplt;
    
    /* Set the UART DMA Source transfer complete callback */
    huart->hdmatx->XferDstTranCpltCallback = UART_DMADstTranCplt;
    
    /* Set the DMA error callback */
    huart->hdmatx->XferErrorCallback = UART_DMAError;

    /* Set the DMA abort callback */
    huart->hdmatx->XferAbortCallback = NULL;

    /* Enable the UART transmit DMA channel */
    tmp = (uint32_t *)&pData;
    HAL_DMA_Start_IT(huart->hdmatx, *(uint32_t *)tmp, (uint32_t)&huart->Instance->DR, Size);

    /* Process Unlocked */
    __HAL_UNLOCK(huart);

    /* Enable the DMA transfer for transmit request by setting the DMAT bit
       in the UART CR3 register */
    SET_BIT(huart->Instance->CR3, UART_CR3_DMAT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in DMA mode.
  * @note   When the UART parity is enabled (PCE = 1), the received data contain
  *         the parity bit (MSB position).
  * @note   When UART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the received data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 available through pData.
  * @param huart UART handle.
  * @param pData Pointer to data buffer (u8 or u16 data elements).
  * @param Size  Amount of data elements (u8 or u16 or u32) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size)
{
  /* Check that a Rx process is not already ongoing */
  if (huart->RxState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }
    /* In case of 9bits, pData buffer provided as input parameter
       should be aligned on a u16 frontier, as data to be received from RDR will be
       handled through a u16 cast. */
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.RxMode == UART_RX_ADDR_MATCH_SOFT))
    {
      if ((((uint32_t)pData) & 1U) != 0U)
      {
        return  HAL_ERROR;
      }
    }
    /* Process Locked */
    __HAL_LOCK(huart);

    huart->pRxBuffPtr = pData;
    huart->RxXferSize = Size;

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->RxState = HAL_UART_STATE_BUSY_RX;

    if (huart->hdmarx != NULL)
    {
      /* Set the UART DMA transfer complete callback */
      huart->hdmarx->XferCpltCallback = UART_DMAReceiveCplt;

      /* Set the UART DMA Half Block transfer complete callback */
      huart->hdmarx->XferHalfBlockCpltCallback = UART_DMARxHalfBlockCplt;
      
      /* Set the UART DMA Block transfer complete callback */
      huart->hdmarx->XferBlockCpltCallback = UART_DMARxBlockCplt;
      
      /* Set the UART DMA Destination transfer complete callback */
      huart->hdmarx->XferSrcTranCpltCallback = UART_DMASrcTranCplt;

      /* Set the UART DMA Destination transfer complete callback */
      huart->hdmarx->XferDstTranCpltCallback = UART_DMADstTranCplt;

      /* Set the DMA error callback */
      huart->hdmarx->XferErrorCallback = UART_DMAError;

      /* Set the DMA abort callback */
      huart->hdmarx->XferAbortCallback = NULL;

      /* Enable the DMA channel */
      if (HAL_DMA_Start_IT(huart->hdmarx, (uint32_t)&huart->Instance->DR, (uint32_t)huart->pRxBuffPtr, Size) != HAL_OK)
      {
        /* Set error code to DMA */
        huart->ErrorCode = HAL_UART_ERROR_DMA;

        __HAL_UNLOCK(huart);

        /* Restore huart->gState to ready */
        huart->gState = HAL_UART_STATE_READY;

        return HAL_ERROR;
      }
    }
    __HAL_UNLOCK(huart);

    /* Enable the UART Parity Error Interrupt */
    SET_BIT(huart->Instance->CR2, UART_CR2_LSIE);

    /* Enable the UART busy Error Interrupt */
    SET_BIT(huart->Instance->CR2, UART_CR2_BUSYERRIE);

    /* Enable the DMA transfer for the receiver request by setting the DMAR bit
    in the UART CR3 register */
    SET_BIT(huart->Instance->CR3, UART_CR3_DMAR);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Pause the DMA Transfer.
  * @param huart UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart)
{
  const HAL_UART_StateTypeDef gstate = huart->gState;
  const HAL_UART_StateTypeDef rxstate = huart->RxState;

  __HAL_LOCK(huart);

  if ((HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAT)) &&
      (gstate == HAL_UART_STATE_BUSY_TX))
  {
    /* Disable the UART DMA Tx request */
    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAT);
  }
  if ((HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAR)) &&
      (rxstate == HAL_UART_STATE_BUSY_RX))
  {
    /* Disable PE and ERR (Frame error, noise error, overrun error) interrupts */
    CLEAR_BIT(huart->Instance->CR2, UART_CR2_LSIE);

    /* Disable Busy interrupts */
    CLEAR_BIT(huart->Instance->CR2, UART_CR2_BUSYERRIE);

    /* Disable the UART DMA Rx request */
    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAR);
  }

  __HAL_UNLOCK(huart);

  return HAL_OK;
}

/**
  * @brief Resume the DMA Transfer.
  * @param huart UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart)
{
  __HAL_LOCK(huart);

  if (huart->gState == HAL_UART_STATE_BUSY_TX)
  {
    /* Enable the UART DMA Tx request */
    SET_BIT(huart->Instance->CR3, UART_CR3_DMAT);
  }
  if (huart->RxState == HAL_UART_STATE_BUSY_RX)
  {
    /* Clear the Overrun flag before resuming the Rx transfer */
    __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_ORE);

    /* Re-enable PE and ERR (Frame error, noise error, overrun error) interrupts */
    SET_BIT(huart->Instance->CR2, UART_CR2_LSIE);

    /* Re-enable Busy interrupts */
    SET_BIT(huart->Instance->CR2, UART_CR2_BUSYERRIE);

    /* Enable the UART DMA Rx request */
    SET_BIT(huart->Instance->CR3, UART_CR3_DMAR);
  }

  __HAL_UNLOCK(huart);

  return HAL_OK;
}

/**
  * @brief Stop the DMA Transfer.
  * @param huart UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart)
{
  /* The Lock is not implemented on this API to allow the user application
     to call the HAL UART API under callbacks HAL_UART_TxCpltCallback() / HAL_UART_RxCpltCallback() /
     HAL_UART_TxHalfCpltCallback / HAL_UART_RxHalfCpltCallback:
     indeed, when HAL_DMA_Abort() API is called, the DMA TX/RX Transfer or Half Transfer complete
     interrupt is generated if the DMA transfer interruption occurs at the middle or at the end of
     the stream and the corresponding call back is executed. */

  const HAL_UART_StateTypeDef gstate = huart->gState;
  const HAL_UART_StateTypeDef rxstate = huart->RxState;

  /* Stop UART DMA Tx request if ongoing */
  if ((HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAT)) &&
      (gstate == HAL_UART_STATE_BUSY_TX))
  {
    /* Abort the UART DMA Tx channel */
    if (huart->hdmatx != NULL)
    {
      if (HAL_DMA_Abort(huart->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(huart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          huart->ErrorCode = HAL_UART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }

    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAT);

    UART_EndTxTransfer(huart);
  }

  /* Stop UART DMA Rx request if ongoing */
  if ((HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAR)) &&
      (rxstate == HAL_UART_STATE_BUSY_RX))
  {
    /* Abort the UART DMA Rx channel */
    if (huart->hdmarx != NULL)
    {
      if (HAL_DMA_Abort(huart->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(huart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          huart->ErrorCode = HAL_UART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }

    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAR);

    UART_EndRxTransfer(huart);
  }

  return HAL_OK;
}

/**
  * @brief  Abort ongoing transfers (blocking mode).
  * @param  huart UART handle.
  * @note   This procedure could be used for aborting any ongoing transfer started in Interrupt mode.
  *         This procedure performs following operations :
  *           - Disable UART Interrupts (Tx and Rx)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
*/
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart)
{
  /* Disable the UART BUSYERR status interrupt , Receiver line status interrupt, 
             Transfer Hold Register empty Interrupt and Data Register not empty Interrupt */
  __HAL_UART_DISABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_LS | UART_IT_TDRE | UART_IT_RXNE));

  /* Disable the UART DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAT))
  {
    /* Abort the UART DMA Tx channel: use blocking DMA Abort API (no callback) */
    if (huart->hdmatx != NULL)
    {
      /* Set the UART DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      huart->hdmatx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(huart->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(huart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          huart->ErrorCode = HAL_UART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAT);
  }

  /* Disable the UART DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAR))
  {
    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAR);

    /* Abort the UART DMA Rx channel: use blocking DMA Abort API (no callback) */
    if (huart->hdmarx != NULL)
    {
      /* Set the UART DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      huart->hdmarx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(huart->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(huart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          huart->ErrorCode = HAL_UART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
  }

  /* Reset Tx and Rx transfer counters */
  huart->TxXferCount = 0x00U;
  huart->RxXferCount = 0x00U;

  /* Reset ErrorCode */
  huart->ErrorCode = HAL_UART_ERROR_NONE;

  /* Restore huart->RxState and huart->gState to Ready */
  huart->RxState = HAL_UART_STATE_READY;
  huart->gState = HAL_UART_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Transmit transfer (blocking mode).
  * @param  huart UART handle.
  * @note   This procedure could be used for aborting any ongoing Tx transfer started in Interrupt mode.
  *         This procedure performs following operations :
  *           - Disable UART Interrupts (Tx)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
*/
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart)
{
  /* Disable the UART BUSYERR status interrupt and Transfer Hold Register empty Interrupt */
  __HAL_UART_DISABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_TDRE));

  /* Reset Tx transfer counter */
  huart->TxXferCount = 0x00U;

  /* Restore huart->gState to Ready */
  huart->gState = HAL_UART_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Receive transfer (blocking mode).
  * @param  huart UART handle.
  * @note   This procedure could be used for aborting any ongoing Rx transfer started in Interrupt mode.
  *         This procedure performs following operations :
  *           - Disable UART Interrupts (Rx)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
*/
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart)
{
  /* Disable the UART BUSYERR status interrupt , Receiver line status interrupt, 
             and Data Register not empty Interrupt */
  __HAL_UART_DISABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_LS | UART_IT_RXNE));

  /* Reset Rx transfer counter */
  huart->RxXferCount = 0x00U;

  /* Restore huart->RxState to Ready */
  huart->RxState = HAL_UART_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing transfers (Interrupt mode).
  * @param  huart UART handle.
  * @note   This procedure could be used for aborting any ongoing transfer started in Interrupt mode.
  *         This procedure performs following operations :
  *           - Disable UART Interrupts (Tx and Rx)
  *           - Set handle State to READY
  *           - At abort completion, call user abort complete callback
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
*/
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart)
{
  uint32_t abortcplt = 1U;

  /* Disable the UART BUSYERR status interrupt , Receiver line status interrupt, 
             Transfer Hold Register empty Interrupt and Data Register not empty Interrupt */
  __HAL_UART_DISABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_LS | UART_IT_TDRE | UART_IT_RXNE));

  /* If DMA Tx and/or DMA Rx Handles are associated to UART Handle, DMA Abort complete callbacks should be initialised
     before any call to DMA Abort functions */
  /* DMA Tx Handle is valid */
  if (huart->hdmatx != NULL)
  {
    /* Set DMA Abort Complete callback if UART DMA Tx request if enabled.
       Otherwise, set it to NULL */
    if (HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAT))
    {
      huart->hdmatx->XferAbortCallback = UART_DMATxAbortCallback;
    }
    else
    {
      huart->hdmatx->XferAbortCallback = NULL;
    }
  }
  /* DMA Rx Handle is valid */
  if (huart->hdmarx != NULL)
  {
    /* Set DMA Abort Complete callback if UART DMA Rx request if enabled.
       Otherwise, set it to NULL */
    if (HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAR))
    {
      huart->hdmarx->XferAbortCallback = UART_DMARxAbortCallback;
    }
    else
    {
      huart->hdmarx->XferAbortCallback = NULL;
    }
  }

  /* Abort the UART DMA Tx channel if enabled */
  if (HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAT))
  {
    /* Abort the UART DMA Tx channel : use non blocking DMA Abort API (callback) */
    if (huart->hdmatx != NULL)
    {
      /* UART Tx DMA Abort callback has already been initialised :
         will lead to call HAL_UART_AbortCpltCallback() at end of DMA abort procedure */

      /* Abort DMA TX */
      if (HAL_DMA_Abort_IT(huart->hdmatx) != HAL_OK)
      {
        huart->hdmatx->XferAbortCallback = NULL;
      }
      else
      {
        abortcplt = 0U;
      }
    }
    /* Disable DMA Tx at UART level */
    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAT);
  }

  /* Abort the UART DMA Rx channel if enabled */
  if (HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAR))
  {
    /* Abort the UART DMA Rx channel : use non blocking DMA Abort API (callback) */
    if (huart->hdmarx != NULL)
    {
      /* UART Rx DMA Abort callback has already been initialised :
         will lead to call HAL_UART_AbortCpltCallback() at end of DMA abort procedure */

      /* Abort DMA RX */
      if (HAL_DMA_Abort_IT(huart->hdmarx) != HAL_OK)
      {
        huart->hdmarx->XferAbortCallback = NULL;
        abortcplt = 1U;
      }
      else
      {
        abortcplt = 0U;
      }
    }
    /* Disable the UART DMA Rx request if enabled */
    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAR);
  }

  /* if no DMA abort complete callback execution is required => call user Abort Complete callback */
  if (abortcplt == 1U)
  {
    /* Reset Tx and Rx transfer counters */
    huart->TxXferCount = 0x00U;
    huart->RxXferCount = 0x00U;

    /* Reset ErrorCode */
    huart->ErrorCode = HAL_UART_ERROR_NONE;

    /* Restore huart->gState and huart->RxState to Ready */
    huart->gState  = HAL_UART_STATE_READY;
    huart->RxState = HAL_UART_STATE_READY;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /* Call registered Abort complete callback */
    huart->AbortCpltCallback(huart);
#else
    /* Call legacy weak Abort complete callback */
    HAL_UART_AbortCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
  return HAL_OK;
}

/**
  * @brief  Abort ongoing Transmit transfer (Interrupt mode).
  * @param  huart UART handle.
  * @note   This procedure could be used for aborting any ongoing Tx transfer started in Interrupt mode.
  *         This procedure performs following operations :
  *           - Disable UART Interrupts (Tx)
  *           - Set handle State to READY
  *           - At abort completion, call user abort complete callback
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
*/
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart)
{
  /* Disable the UART BUSYERR status interrupt and Transfer Hold Register empty Interrupt */
  __HAL_UART_DISABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_TDRE));

  /* Disable the UART DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAT))
  {
    /* Abort the UART DMA Tx channel : use non blocking DMA Abort API (callback) */
    if (huart->hdmatx != NULL)
    {
      /* Set the UART DMA Abort callback :
         will lead to call HAL_UART_AbortCpltCallback() at end of DMA abort procedure */
      huart->hdmatx->XferAbortCallback = UART_DMATxOnlyAbortCallback;

      /* Abort DMA TX */
      if (HAL_DMA_Abort_IT(huart->hdmatx) != HAL_OK)
      {
        /* Call Directly huart->hdmatx->XferAbortCallback function in case of error */
        huart->hdmatx->XferAbortCallback(huart->hdmatx);
      }
    }
    else
    {
      /* Reset Tx transfer counter */
      huart->TxXferCount = 0U;

      /* Restore huart->gState to Ready */
      huart->gState = HAL_UART_STATE_READY;

      /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
      /* Call registered Abort Transmit Complete Callback */
      huart->AbortTransmitCpltCallback(huart);
#else
      /* Call legacy weak Abort Transmit Complete Callback */
      HAL_UART_AbortTransmitCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
    }
    /* Disable the UART DMA Tx request if enabled */
    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAT);
  }
  else
  {
    /* Reset Tx transfer counter */
    huart->TxXferCount = 0U;

    /* Restore huart->gState to Ready */
    huart->gState = HAL_UART_STATE_READY;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /* Call registered Abort Transmit Complete Callback */
    huart->AbortTransmitCpltCallback(huart);
#else
    /* Call legacy weak Abort Transmit Complete Callback */
    HAL_UART_AbortTransmitCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Receive transfer (Interrupt mode).
  * @param  huart UART handle.
  * @note   This procedure could be used for aborting any ongoing Rx transfer started in Interrupt mode.
  *         This procedure performs following operations :
  *           - Disable UART Interrupts (Rx)
  *           - Set handle State to READY
  *           - At abort completion, call user abort complete callback
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
*/
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart)
{
  /* Disable the UART BUSYERR status interrupt , Receiver line status interrupt, 
             and Data Register not empty Interrupt */
  __HAL_UART_DISABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_LS | UART_IT_RXNE));

  /* Disable the UART DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAR))
  {
    /* Abort the UART DMA Rx channel : use non blocking DMA Abort API (callback) */
    if (huart->hdmarx != NULL)
    {
      /* Set the UART DMA Abort callback :
         will lead to call HAL_UART_AbortCpltCallback() at end of DMA abort procedure */
      huart->hdmarx->XferAbortCallback = UART_DMARxOnlyAbortCallback;

      /* Abort DMA RX */
      if (HAL_DMA_Abort_IT(huart->hdmarx) != HAL_OK)
      {
        /* Call Directly huart->hdmarx->XferAbortCallback function in case of error */
        huart->hdmarx->XferAbortCallback(huart->hdmarx);
      }
    }
    else
    {
      /* Reset Rx transfer counter */
      huart->RxXferCount = 0U;

      /* Clear RxISR function pointer */
      huart->pRxBuffPtr = NULL;

      /* Clear the Error flags */
      __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_PE);

      /* Restore huart->RxState to Ready */
      huart->RxState = HAL_UART_STATE_READY;

      /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
      /* Call registered Abort Receive Complete Callback */
      huart->AbortReceiveCpltCallback(huart);
#else
      /* Call legacy weak Abort Receive Complete Callback */
      HAL_UART_AbortReceiveCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
    }
    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAR);
  }
  else
  {
    /* Reset Rx transfer counter */
    huart->RxXferCount = 0U;

    /* Clear RxISR function pointer */
    huart->pRxBuffPtr = NULL;

    /* Clear the Error flags */
    __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_PE);

    /* Restore huart->RxState to Ready */
    huart->RxState = HAL_UART_STATE_READY;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /* Call registered Abort Receive Complete Callback */
    huart->AbortReceiveCpltCallback(huart);
#else
    /* Call legacy weak Abort Receive Complete Callback */
    HAL_UART_AbortReceiveCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }

  return HAL_OK;
}

/**
  * @brief  This function handles UART interrupt request.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @note   Depending on devices and packages, DMA may not be available.
  *         Refer to device datasheet for DMA availability.
  * @retval None
  */
void HAL_UART_IRQHandler(UART_HandleTypeDef *huart)
{
  uint32_t isrflags   = READ_REG(huart->Instance->SR);
  uint32_t cr2its     = READ_REG(huart->Instance->CR2);
  uint32_t errorflags = 0x00U;
  uint32_t dmarequest = 0x00U;

  /* If no error occurs */
  errorflags = (isrflags & (uint32_t)(UART_SR_ORE | UART_SR_PE | UART_SR_FE | UART_SR_BUSY_ERR));
  if (errorflags == RESET)
  {
    /* UART in mode Receiver -------------------------------------------------*/
    if (((isrflags & UART_SR_RXNE) != RESET) && ((cr2its & UART_CR2_RXNEIE) != RESET))
    {
      UART_Receive_IT(huart);
      return;
    }
  }
  
  /* If Break frame detection interrupt occurred*/
  if (((isrflags & UART_SR_BRI) != RESET) && ((cr2its & UART_CR2_LSIE) != RESET))
  {
    /* Clear Flag */
    __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_BRI);

    /* Call callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    huart->BreakFrameCallback(huart);
#else
    HAL_UART_BreakFrameCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
  
  /* If address matching interrupt occurred*/
  if (((isrflags & UART_SR_ADDR_RCVD) != RESET) && ((cr2its & UART_CR2_LSIE) != RESET))
  {
    /* Clear Flag */
    __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_ADDR_RCVD);

    /* Call callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    huart->AddrMatchCallback(huart);
#else
    HAL_UART_AddrMatchCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }

  /* If some errors occur */
  if ((errorflags != RESET) && ((cr2its & (UART_CR2_LSIE | UART_CR2_BUSYERRIE | UART_CR2_RXNEIE)) != RESET))
  {
    /* UART Over-Run interrupt occurred --------------------------------------*/
    if (((isrflags & UART_SR_ORE) != RESET) && ((cr2its & UART_CR2_LSIE) != RESET))
    {
      /* Clear Flag */
      __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_ORE);
      
      huart->ErrorCode |= HAL_UART_ERROR_ORE;
    }
    
    /* UART parity error interrupt occurred ----------------------------------*/
    if (((isrflags & UART_SR_PE) != RESET) && ((cr2its & UART_CR2_LSIE) != RESET))
    {
      /* Clear Flag */
      __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_PE);
      
      huart->ErrorCode |= HAL_UART_ERROR_PE;
    }

    /* UART frame error interrupt occurred -----------------------------------*/
    if (((isrflags & UART_SR_FE) != RESET) && ((cr2its & UART_CR2_LSIE) != RESET))
    {
      /* Clear Flag */
      __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_FE);
      
      huart->ErrorCode |= HAL_UART_ERROR_FE;
    }
    
    /* UART BUSYERR status interrupt occurred -----------------------------------*/
    if (((isrflags & UART_SR_BUSY_ERR) != RESET) && ((cr2its & UART_CR2_BUSYERRIE) != RESET))
    {
      /* Clear Flag */
      __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_BUSY_ERR);
      
      huart->ErrorCode |= HAL_UART_ERROR_BUSY;
    }

    /* Call UART Error Call back function if need be --------------------------*/
    if (huart->ErrorCode != HAL_UART_ERROR_NONE)
    {
      /* UART in mode Receiver -----------------------------------------------*/
      if (((isrflags & UART_SR_RXNE) != RESET) && ((cr2its & UART_CR2_RXNEIE) != RESET))
      {
        UART_Receive_IT(huart);
      }

      /* If Overrun error occurs, or if any error occurs in DMA mode reception,
         consider error as blocking */
      dmarequest = HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAR);
      if (((huart->ErrorCode & HAL_UART_ERROR_ORE) != RESET) || dmarequest)
      {
        /* Blocking error : transfer is aborted
           Set the UART state ready to be able to start again the process,
           Disable Rx Interrupts, if ongoing */
        UART_EndRxTransfer(huart);
        
        /* Abort the UART DMA Rx channel if enabled */
        if (HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAR))
        {
          /* Disable the UART DMA Rx request if enabled */
          CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAR);

          /* Abort the UART DMA Tx channel */
          if (huart->hdmatx != NULL)
          {
            /* Set the UART Tx DMA Abort callback to NULL : no callback
               executed at end of DMA abort procedure */
            huart->hdmatx->XferAbortCallback = NULL;

            /* Abort DMA TX */
            (void)HAL_DMA_Abort_IT(huart->hdmatx);
          }

          /* Abort the UART DMA Rx channel */
          if (huart->hdmarx != NULL)
          {
            /* Set the UART Rx DMA Abort callback :
               will lead to call HAL_UART_ErrorCallback() at end of DMA abort procedure */
            huart->hdmarx->XferAbortCallback = UART_DMAAbortOnError;

            /* Abort DMA RX */
            if (HAL_DMA_Abort_IT(huart->hdmarx) != HAL_OK)
            {
              /* Call Directly huart->hdmarx->XferAbortCallback function in case of error */
              huart->hdmarx->XferAbortCallback(huart->hdmarx);
            }
          }
          else
          {
            /* Call user error callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
            /* Call registered Error Callback */
            huart->ErrorCallback(huart);
#else
            /* Call legacy weak Error Callback */
            HAL_UART_ErrorCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
          }
        }
        else
        {
          /* Call user error callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
          /* Call registered error callback*/
          huart->ErrorCallback(huart);
#else
          /* Call legacy weak error callback*/
          HAL_UART_ErrorCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
        }
      }
      else
      {
        /* Non Blocking error : transfer could go on.
           Error is notified to user through user error callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
        /* Call registered error callback*/
        huart->ErrorCallback(huart);
#else
        /* Call legacy weak error callback*/
        HAL_UART_ErrorCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

        huart->ErrorCode = HAL_UART_ERROR_NONE;
      }
    }
    return;
  } /* End if some error occurs */

  /* UART in mode Transmitter ------------------------------------------------*/
  if (((isrflags & UART_SR_TDRE) != RESET) && ((cr2its & UART_CR2_TDREIE) != RESET))
  {
    UART_Transmit_IT(huart);
    return;
  }
}

/**
  * @brief  UART error callbacks.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
__weak void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_ErrorCallback could be implemented in the user file
   */
}

/**
  * @brief  Tx Transfer completed callbacks.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
__weak void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_TxCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  Tx Block Transfer completed callback.
  * @param  huart UART handle.
  * @retval None
  */
__weak void HAL_UART_TxBlockCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_TxBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx Half Block Transfer completed callback.
  * @param  huart UART handle.
  * @retval None
  */
__weak void HAL_UART_TxHalfBlockCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_TxHalfBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx Source Transfer completed callback.
  * @param  huart UART handle.
  * @retval None
  */
__weak void HAL_UART_TxSrcCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_TxSrcCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Transfer completed callbacks.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
__weak void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_RxCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  Rx Block Transfer completed callback.
  * @param  huart UART handle.
  * @retval None
  */
__weak void HAL_UART_RxBlockCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_RxBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Half Block Transfer completed callback.
  * @param  huart UART handle.
  * @retval None
  */
__weak void HAL_UART_RxHalfBlockCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_RxHalfBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Destination Transfer completed callback.
  * @param  huart UART handle.
  * @retval None
  */
__weak void HAL_UART_RxDstCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_RxDstTranCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Break frame detection callbacks.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
__weak void HAL_UART_BreakFrameCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_BreakFrameCallback could be implemented in the user file
   */
}

/**
  * @brief  Break frame detection callbacks.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
__weak void HAL_UART_AddrMatchCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_AddrMatchCallback could be implemented in the user file
   */
}

/**
  * @brief  UART Abort Complete callback.
  * @param  huart UART handle.
  * @retval None
  */
__weak void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_AbortCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  UART Abort Complete callback.
  * @param  huart UART handle.
  * @retval None
  */
__weak void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_AbortTransmitCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  UART Abort Receive Complete callback.
  * @param  huart UART handle.
  * @retval None
  */
__weak void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_AbortReceiveCpltCallback can be implemented in the user file.
   */
}

/**
  * @}
  */

/** @defgroup UART_Exported_Functions_Group3 Peripheral Control functions
  *  @brief   UART control functions
  *
  * @{
  */

/**
  * @brief  Start transmits break characters.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_StartSendBreak(UART_HandleTypeDef *huart)
{
  /* Check the parameters */
  assert_param(IS_UART_INSTANCE(huart->Instance));

  /* Process Locked */
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

  /* Send break characters */
  SET_BIT(huart->Instance->CR1, UART_CR1_SBK);

  huart->gState = HAL_UART_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

/**
  * @brief  Stop transmits break characters.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_StopSendBreak(UART_HandleTypeDef *huart)
{
  /* Check the parameters */
  assert_param(IS_UART_INSTANCE(huart->Instance));

  /* Process Locked */
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

  /* Stop send break characters */
  CLEAR_BIT(huart->Instance->CR1, UART_CR1_SBK);

  huart->gState = HAL_UART_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

/**
  * @}
  */

/** @defgroup UART_Exported_Functions_Group4 Peripheral State and Errors functions
  *  @brief   UART State and Errors functions
  *
@verbatim
  ==============================================================================
                 ##### Peripheral State and Errors functions #####
  ==============================================================================
 [..]
   This subsection provides a set of functions allowing to return the State of
   UART communication process, return Peripheral Errors occurred during communication
   process
   (+) HAL_UART_GetState() API can be helpful to check in run-time the state of the UART peripheral.
   (+) HAL_UART_GetError() check in run-time errors that could be occurred during communication.

@endverbatim
  * @{
  */

/**
  * @brief  Returns the UART state.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval HAL state
  */
HAL_UART_StateTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart)
{
  uint32_t temp1 = 0x00U, temp2 = 0x00U;
  temp1 = huart->gState;
  temp2 = huart->RxState;

  return (HAL_UART_StateTypeDef)(temp1 | temp2);
}

/**
  * @brief  Return the UART error code
  * @param  huart Pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART.
  * @retval UART Error Code
  */
uint32_t HAL_UART_GetError(UART_HandleTypeDef *huart)
{
  return huart->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup UART_Private_Functions UART Private Functions
  * @{
  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/**
  * @brief  Initialize the callbacks to their default values.
  * @param  huart UART handle.
  * @retval none
  */
void UART_InitCallbacksToDefault(UART_HandleTypeDef *huart)
{
  /* Init the UART Callback settings */
  huart->TxCpltCallback            = HAL_UART_TxCpltCallback;            /* Legacy weak TxCpltCallback            */
  huart->RxCpltCallback            = HAL_UART_RxCpltCallback;            /* Legacy weak RxCpltCallback            */
  huart->ErrorCallback             = HAL_UART_ErrorCallback;             /* Legacy weak ErrorCallback             */
  huart->AbortCpltCallback         = HAL_UART_AbortCpltCallback;         /* Legacy weak AbortCpltCallback         */
  huart->AbortTransmitCpltCallback = HAL_UART_AbortTransmitCpltCallback; /* Legacy weak AbortTransmitCpltCallback */
  huart->AbortReceiveCpltCallback  = HAL_UART_AbortReceiveCpltCallback;  /* Legacy weak AbortReceiveCpltCallback  */
  huart->BreakFrameCallback        = HAL_UART_BreakFrameCallback;        /* Legacy weak BreakFrameCallback  */
  huart->AddrMatchCallback         = HAL_UART_AddrMatchCallback;         /* Legacy weak AddrMatchCallback  */

}
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @brief  This function handles UART Communication Timeout.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @param  Flag specifies the UART flag to check.
  * @param  Status The new Flag status (SET or RESET).
  * @param  Tickstart Tick start value.
  * @param  Timeout Timeout duration.
  * @retval HAL status
  */
static HAL_StatusTypeDef UART_WaitOnFlagUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status, uint32_t Tickstart, uint32_t Timeout)
{
  /* Wait until flag is set */
  while ((__HAL_UART_GET_FLAG(huart, Flag) ? SET : RESET) == Status)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if ((Timeout == 0U) || ((HAL_GetTick() - Tickstart) > Timeout))
      {
        /* Disable the interrupt process */
        CLEAR_BIT(huart->Instance->CR2, (UART_CR2_RXNEIE | UART_CR2_TDREIE | UART_CR2_LSIE | UART_CR2_BUSYERRIE));

        huart->gState  = HAL_UART_STATE_READY;
        huart->RxState = HAL_UART_STATE_READY;

        /* Process Unlocked */
        __HAL_UNLOCK(huart);

        return HAL_TIMEOUT;
      }
    }
  }
  return HAL_OK;
}

/**
  * @brief  End ongoing Tx transfer on UART peripheral (following error detection or Transmit completion).
  * @param  huart UART handle.
  * @retval None
  */
static void UART_EndTxTransfer(UART_HandleTypeDef *huart)
{
  /* Disable the UART BUSYERR status interrupt , Transfer line status interrupt and Data Register not empty Interrupt */
  __HAL_UART_DISABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_LS | UART_IT_TDRE));

  /* At end of Tx process, restore huart->gState to Ready */
  huart->gState = HAL_UART_STATE_READY;
}

/**
  * @brief  End ongoing Rx transfer on UART peripheral (following error detection or Reception completion).
  * @param  huart UART handle.
  * @retval None
  */
static void UART_EndRxTransfer(UART_HandleTypeDef *huart)
{
  /* Disable the UART BUSYERR status interrupt , Receiver line status interrupt and Data Register not empty Interrupt */
  __HAL_UART_DISABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_LS | UART_IT_RXNE));

  /* At end of Rx process, restore huart->RxState to Ready */
  huart->RxState = HAL_UART_STATE_READY;
}

/**
  * @brief DMA UART transmit process complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void UART_DMATransmitCplt(DMA_HandleTypeDef *hdma)
{
  uint32_t tickstart = 0;
  
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  /* Init tickstart for timeout managment */
  tickstart = HAL_GetTick();

  /* DMA Normal mode */
  if (HAL_IS_BIT_CLR(hdma->Init.Mode, DMA_CIRCULAR))
  {
    huart->TxXferCount = 0U;

    /* Wait the TC flag in the SR register by writing 1 to it */
    if (UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_TXE, RESET, tickstart, 1000) != HAL_OK)
    {
      huart->gState = HAL_UART_STATE_TIMEOUT;
    }
    else
    {
      /* At end of Tx process, restore huart->gState to Ready */
      huart->gState = HAL_UART_STATE_READY;
    }
    /* Disable the DMA transfer for transmit request by resetting the DMAT bit
       in the UART CR3 register */
    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAT);
  }
  /* DMA Circular mode */
  else
  {
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /*Call registered Tx complete callback*/
    huart->TxCpltCallback(huart);
#else
    /*Call legacy weak Tx complete callback*/
    HAL_UART_TxCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
}

/**
  * @brief DMA UART transmit process half block complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void UART_DMATxHalfBlockCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx Half complete callback*/
  huart->TxHalfBlockCpltCallback(huart);
#else
  /*Call legacy weak Tx Half complete callback*/
  HAL_UART_TxHalfBlockCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA UART transmit process block complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void UART_DMATxBlockCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx Half complete callback*/
  huart->TxBlockCpltCallback(huart);
#else
  /*Call legacy weak Tx Half complete callback*/
  HAL_UART_TxBlockCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA UART transmit process source complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void UART_DMASrcTranCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx Half complete callback*/
  huart->TxSrcCpltCallback(huart);
#else
  /*Call legacy weak Tx Half complete callback*/
  HAL_UART_TxSrcCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA UART receive process complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void UART_DMAReceiveCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  /* DMA Normal mode */
  if (HAL_IS_BIT_CLR(hdma->Init.Mode, DMA_CIRCULAR))
  {
    huart->RxXferCount = 0U;

    /* Disable PE and ERR (Frame error, noise error, overrun error) interrupts */
    CLEAR_BIT(huart->Instance->CR2, UART_CR2_LSIE);

    /* Disable the DMA transfer for the receiver request by resetting the DMAR bit
       in the UART CR3 register */
    CLEAR_BIT(huart->Instance->CR3, UART_CR3_DMAR);

    /* At end of Rx process, restore huart->RxState to Ready */
    huart->RxState = HAL_UART_STATE_READY;
  }

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Rx complete callback*/
  huart->RxCpltCallback(huart);
#else
  /*Call legacy weak Rx complete callback*/
  HAL_UART_RxCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA UART receive process block complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void UART_DMARxBlockCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Rx Half complete callback*/
  huart->RxBlockCpltCallback(huart);
#else
  /*Call legacy weak Rx Half complete callback*/
  HAL_UART_RxBlockCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA UART receive process half block complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void UART_DMARxHalfBlockCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Rx Half complete callback*/
  huart->RxHalfBlockCpltCallback(huart);
#else
  /*Call legacy weak Rx Half complete callback*/
  HAL_UART_RxHalfBlockCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA UART receive process destination complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void UART_DMADstTranCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Rx Half complete callback*/
  huart->RxDstCpltCallback(huart);
#else
  /*Call legacy weak Rx Half complete callback*/
  HAL_UART_RxDstCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA UART communication error callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void UART_DMAError(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  const HAL_UART_StateTypeDef gstate = huart->gState;
  const HAL_UART_StateTypeDef rxstate = huart->RxState;

  /* Stop UART DMA Tx request if ongoing */
  if ((HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAT)) &&
      (gstate == HAL_UART_STATE_BUSY_TX))
  {
    huart->TxXferCount = 0U;
    UART_EndTxTransfer(huart);
  }

  /* Stop UART DMA Rx request if ongoing */
  if ((HAL_IS_BIT_SET(huart->Instance->CR3, UART_CR3_DMAR)) &&
      (rxstate == HAL_UART_STATE_BUSY_RX))
  {
    huart->RxXferCount = 0U;
    UART_EndRxTransfer(huart);
  }

  huart->ErrorCode |= HAL_UART_ERROR_DMA;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered error callback*/
  huart->ErrorCallback(huart);
#else
  /*Call legacy weak error callback*/
  HAL_UART_ErrorCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA UART communication abort callback, when initiated by HAL services on Error
  *         (To be called at end of DMA Abort procedure following error occurrence).
  * @param  hdma DMA handle.
  * @retval None
  */
static void UART_DMAAbortOnError(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);
  huart->RxXferCount = 0U;
  huart->TxXferCount = 0U;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /* Call registered Error Callback */
  huart->ErrorCallback(huart);
#else
  /* Call legacy weak Error Callback */
  HAL_UART_ErrorCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA UART Tx communication abort callback, when initiated by user
  *         (To be called at end of DMA Tx Abort procedure following user abort request).
  * @note   When this callback is executed, User Abort complete call back is called only if no
  *         Abort still ongoing for Rx DMA Handle.
  * @param  hdma DMA handle.
  * @retval None
  */
static void UART_DMATxAbortCallback(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  huart->hdmatx->XferAbortCallback = NULL;

  /* Check if an Abort process is still ongoing */
  if (huart->hdmarx != NULL)
  {
    if (huart->hdmarx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA channels are aborted, call user Abort Complete callback */
  huart->TxXferCount = 0U;
  huart->RxXferCount = 0U;

  /* Reset errorCode */
  huart->ErrorCode = HAL_UART_ERROR_NONE;

  /* Clear the Error flags */
  __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_PE);

  /* Restore huart->gState and huart->RxState to Ready */
  huart->gState  = HAL_UART_STATE_READY;
  huart->RxState = HAL_UART_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Complete Callback */
  huart->AbortCpltCallback(huart);
#else
  /* Call legacy weak Abort Complete Callback */
  HAL_UART_AbortCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA UART Rx communication abort callback, when initiated by user
  *         (To be called at end of DMA Rx Abort procedure following user abort request).
  * @note   When this callback is executed, User Abort complete call back is called only if no
  *         Abort still ongoing for Tx DMA Handle.
  * @param  hdma DMA handle.
  * @retval None
  */
static void UART_DMARxAbortCallback(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  huart->hdmarx->XferAbortCallback = NULL;

  /* Check if an Abort process is still ongoing */
  if (huart->hdmatx != NULL)
  {
    if (huart->hdmatx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA channels are aborted, call user Abort Complete callback */
  huart->TxXferCount = 0U;
  huart->RxXferCount = 0U;

  /* Reset errorCode */
  huart->ErrorCode = HAL_UART_ERROR_NONE;

  /* Clear the Error flags */
  __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_PE);

  /* Restore huart->gState to Ready */
  huart->gState  = HAL_UART_STATE_READY;
  huart->RxState = HAL_UART_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Complete Callback */
  huart->AbortCpltCallback(huart);
#else
  /* Call legacy weak Abort Complete Callback */
  HAL_UART_AbortCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA UART Tx communication abort callback, when initiated by user by a call to
  *         HAL_UART_AbortTransmit_IT API (Abort only Tx transfer)
  *         (This callback is executed at end of DMA Tx Abort procedure following user abort request,
  *         and leads to user Tx Abort Complete callback execution).
  * @param  hdma DMA handle.
  * @retval None
  */
static void UART_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  huart->TxXferCount = 0U;

  /* Restore huart->gState to Ready */
  huart->gState = HAL_UART_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Transmit Complete Callback */
  huart->AbortTransmitCpltCallback(huart);
#else
  /* Call legacy weak Abort Transmit Complete Callback */
  HAL_UART_AbortTransmitCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA UART Rx communication abort callback, when initiated by user by a call to
  *         HAL_UART_AbortReceive_IT API (Abort only Rx transfer)
  *         (This callback is executed at end of DMA Rx Abort procedure following user abort request,
  *         and leads to user Rx Abort Complete callback execution).
  * @param  hdma DMA handle.
  * @retval None
  */
static void UART_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma)
{
 UART_HandleTypeDef *huart = (UART_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  huart->RxXferCount = 0U;

  /* Clear the Error flags */
  __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_PE);

  /* Restore huart->RxState to Ready */
  huart->RxState = HAL_UART_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Receive Complete Callback */
  huart->AbortReceiveCpltCallback(huart);
#else
  /* Call legacy weak Abort Receive Complete Callback */
  HAL_UART_AbortReceiveCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief  Sends an amount of data in non blocking mode.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval HAL status
  */
static HAL_StatusTypeDef UART_Transmit_IT(UART_HandleTypeDef *huart)
{
  uint16_t *tmp16bit;
  uint8_t *tmp8bit;
  
  /* Check that a Tx process is ongoing */
  if (huart->gState == HAL_UART_STATE_BUSY_TX)
  {
    if (huart->TxXferCount == 0U)
    {
      /* Disable the BUSYERR status interrupt and Transfer Hold Register empty interrupt */
      __HAL_UART_DISABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_TDRE));

      /* Tx process is ended, restore huart->gState to Ready */
      huart->gState = HAL_UART_STATE_READY;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
        /*Call registered Tx complete callback*/
        huart->TxCpltCallback(huart);
#else
        /*Call legacy weak Tx complete callback*/
        HAL_UART_TxCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
    }
    else
    {
      if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.TxMode == UART_TX_MODE_1))
      {
        tmp16bit=(uint16_t *) huart->pTxBuffPtr;
        huart->Instance->DR = (uint16_t)(*tmp16bit & (uint16_t)0x01FF);
        huart->pTxBuffPtr += 2U;
      }
      else
      {
        tmp8bit=(uint8_t *) huart->pTxBuffPtr;
        huart->Instance->DR = (uint8_t)(*tmp8bit & (uint8_t)0x00FF);
        huart->pTxBuffPtr++;
        huart->TxXferCount--;
      }
    }
    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Receives an amount of data in non blocking mode
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval HAL status
  */
static HAL_StatusTypeDef UART_Receive_IT(UART_HandleTypeDef *huart)
{
  uint16_t *tmp16bit;
  /* Check that a Rx process is ongoing */
  if (huart->RxState == HAL_UART_STATE_BUSY_RX)
  {
    /* Set the Rx ISR function pointer according to the data word length */
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.RxMode == UART_RX_ADDR_MATCH_SOFT))
    {
      tmp16bit = (uint16_t *) huart->pRxBuffPtr;
      *tmp16bit = (uint16_t)(huart->Instance->DR & (uint16_t)0x01FF);
      huart->pRxBuffPtr += 2U;

    }
    else
    {

      *huart->pRxBuffPtr++ = (uint8_t)(huart->Instance->DR & (uint8_t)0x00FF);
    }

    if (--huart->RxXferCount == 0U)
    {
      /* Disable the UART BUSYERR status interrupt , Receiver line status interrupt and Data Register not empty Interrupt */
      __HAL_UART_DISABLE_IT(huart, (UART_IT_BUSY_ERR | UART_IT_LS | UART_IT_RXNE));

      /* Rx process is completed, restore huart->RxState to Ready */
      huart->RxState = HAL_UART_STATE_READY;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
      /*Call registered Rx complete callback*/
      huart->RxCpltCallback(huart);
#else
      /*Call legacy weak Rx complete callback*/
      HAL_UART_RxCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

      return HAL_OK;
    }
    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @}
  */

#endif /* HAL_UART_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
