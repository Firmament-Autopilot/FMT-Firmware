/**
  ******************************************************************************
  * @file    py32e407_hal_usart.c
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

/** @defgroup USART USART
  * @brief HAL USART module driver
  * @{
  */
  
#ifdef HAL_USART_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup USART_Private_Constants USART Private Constants
  * @{
  */
#define USART_DUMMY_DATA          ((uint16_t) 0xFFFF)           /*!< USART transmitted dummy data                     */
#define USART_TEACK_REACK_TIMEOUT             1000U             /*!< USART TX or RX enable acknowledge time-out value */
#define USART_CR1_FIELDS          ((uint32_t)(USART_CR1_M0 | USART_CR1_M1 | USART_CR1_PCE | \
                                              USART_CR1_PS | USART_CR1_TE | USART_CR1_RE  | \
                                              USART_CR1_FIFOEN | USART_CR1_TXFTCFG | USART_CR1_RXFTCFG  ))  /*!< USART CR1 fields of parameters set by USART_SetConfig API */

#define USART_CR2_FIELDS          ((uint32_t)(USART_CR2_CPHA | USART_CR2_CPOL | USART_CR2_CLKEN | \
                                              USART_CR2_LBCL | USART_CR2_STOP))                 /*!< USART CR2 fields of parameters set by USART_SetConfig API */

#define USART_CR3_FIELDS          ((uint32_t)(USART_CR3_OVR8))             /*!< USART or USART CR3 fields of parameters set by USART_SetConfig API */

#define USART_BRR_MIN    0x10U        /* USART BRR minimum authorized value */
#define USART_BRR_MAX    0xFFFFU      /* USART BRR maximum authorized value */
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup USART_Private_Functions
  * @{
  */
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
void USART_InitCallbacksToDefault(USART_HandleTypeDef *husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
static void USART_EndTransfer(USART_HandleTypeDef *husart);
static void USART_DMATransmitCplt(DMA_HandleTypeDef *hdma);
static void USART_DMAReceiveCplt(DMA_HandleTypeDef *hdma);
static void USART_DMATxBlockCplt(DMA_HandleTypeDef *hdma);
static void USART_DMATxHalfBlockCplt(DMA_HandleTypeDef *hdma);
static void USART_DMARxHalfBlockCplt(DMA_HandleTypeDef *hdma);
static void USART_DMARxBlockCplt(DMA_HandleTypeDef *hdma);
static void USART_DMATxSrcTransmitCplt(DMA_HandleTypeDef *hdma);
static void USART_DMARxDstReceiveCplt(DMA_HandleTypeDef *hdma);

static void USART_DMAError(DMA_HandleTypeDef *hdma);
static void USART_DMAAbortOnError(DMA_HandleTypeDef *hdma);
static void USART_DMATxAbortCallback(DMA_HandleTypeDef *hdma);
static void USART_DMARxAbortCallback(DMA_HandleTypeDef *hdma);
static HAL_StatusTypeDef USART_WaitOnFlagUntilTimeout(USART_HandleTypeDef *husart, uint32_t Flag, FlagStatus Status,
                                                      uint32_t Tickstart, uint32_t Timeout);
static void USART_SetConfig(USART_HandleTypeDef *husart);

static void USART_TxSR_8BIT(USART_HandleTypeDef *husart);
static void USART_TxSR_16BIT(USART_HandleTypeDef *husart);
static void USART_TxSR_8BIT_FIFOEN(USART_HandleTypeDef *husart);
static void USART_TxSR_16BIT_FIFOEN(USART_HandleTypeDef *husart);
static void USART_EndTransmit_IT(USART_HandleTypeDef *husart);

static void USART_RxSR_8BIT(USART_HandleTypeDef *husart);
static void USART_RxSR_16BIT(USART_HandleTypeDef *husart);
static void USART_RxSR_8BIT_FIFOEN(USART_HandleTypeDef *husart);
static void USART_RxSR_16BIT_FIFOEN(USART_HandleTypeDef *husart);

/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @defgroup USART_Exported_Functions USART Exported Functions
  * @{
  */
/** @defgroup USART_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
  * @{
  */
/**
  * @brief  Initializes the USART mode according to the specified parameters in
  *         the USART_InitTypeDef and create the associated handle.
  * @param  husart  Pointer to a USART_HandleTypeDef structure that contains
  *                the configuration information for the specified USART module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_Init(USART_HandleTypeDef *husart)
{
  /* Check the USART handle allocation */
  if (husart == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_USART_INSTANCE(husart->Instance));

  if (husart->State == HAL_USART_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    husart->Lock = HAL_UNLOCKED;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
    USART_InitCallbacksToDefault(husart);

    if (husart->MspInitCallback == NULL)
    {
      husart->MspInitCallback = HAL_USART_MspInit;
    }

    /* Init the low level hardware */
    husart->MspInitCallback(husart);
#else
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_USART_MspInit(husart);
#endif /* (USE_HAL_USART_REGISTER_CALLBACKS) */
  }

  husart->State = HAL_USART_STATE_BUSY;

  /* Disable the peripheral */
  __HAL_USART_DISABLE(husart);

  /* Set the USART Communication parameters */
  USART_SetConfig(husart);

  /* In asynchronous mode, the following bits must be kept cleared:
     - LINEN and CLKEN bits in the USART_CR2 register,
     - SCEN, HDSEL and IREN  bits in the USART_CR3 register.*/
  CLEAR_BIT(husart->Instance->CR2, USART_CR2_LINEN);
  CLEAR_BIT(husart->Instance->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));

  /* Enable the peripheral */
  __HAL_USART_ENABLE(husart);

  /* Initialize the USART state */
  husart->ErrorCode = HAL_USART_ERROR_NONE;
  husart->State = HAL_USART_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  DeInitializes the USART peripheral.
  * @param  husart  Pointer to a USART_HandleTypeDef structure that contains
  *                the configuration information for the specified USART module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_DeInit(USART_HandleTypeDef *husart)
{
  /* Check the USART handle allocation */
  if (husart == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_USART_INSTANCE(husart->Instance));

  husart->State = HAL_USART_STATE_BUSY;

  husart->Instance->CR1 = 0x0U;
  husart->Instance->CR2 = 0x0U;
  husart->Instance->CR3 = 0x0U;

  /* Disable the Peripheral */
  __HAL_USART_DISABLE(husart);

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  if (husart->MspDeInitCallback == NULL)
  {
    husart->MspDeInitCallback = HAL_USART_MspDeInit;
  }
  /* DeInit the low level hardware */
  husart->MspDeInitCallback(husart);
#else
  /* DeInit the low level hardware */
  HAL_USART_MspDeInit(husart);
#endif /* (USE_HAL_USART_REGISTER_CALLBACKS) */

  husart->ErrorCode = HAL_USART_ERROR_NONE;
  husart->State = HAL_USART_STATE_RESET;

  /* Process Unlock */
  __HAL_UNLOCK(husart);

  return HAL_OK;
}

/**
  * @brief  USART MSP Init.
  * @param  husart  Pointer to a USART_HandleTypeDef structure that contains
  *                the configuration information for the specified USART module.
  * @retval None
  */
__weak void HAL_USART_MspInit(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_USART_MspInit could be implemented in the user file
   */
}

/**
  * @brief  USART MSP DeInit.
  * @param  husart  Pointer to a USART_HandleTypeDef structure that contains
  *                the configuration information for the specified USART module.
  * @retval None
  */
__weak void HAL_USART_MspDeInit(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_USART_MspDeInit could be implemented in the user file
   */
}

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User USART Callback
  *         To be used instead of the weak predefined callback
  * @param  husart usart handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_USART_TX_SRCCOMPLETE_CB_ID Tx Source Complete Callback ID
  *           @arg @ref HAL_USART_TX_BLOCKCOMPLETE_CB_ID Tx Block Complete Callback ID
  *           @arg @ref HAL_USART_TX_HALFBLOCKCOMPLETE_CB_ID Tx Half Block Complete Callback ID
  *           @arg @ref HAL_USART_TX_COMPLETE_CB_ID Tx Complete Callback ID
  *           @arg @ref HAL_USART_RX_DSTCOMPLETE_CB_ID Rx Destination Complete Callback ID
  *           @arg @ref HAL_USART_RX_BLOCKCOMPLETE_CB_ID Rx Block Complete Callback ID
  *           @arg @ref HAL_USART_RX_HALFBLOCKCOMPLETE_CB_ID Rx Half Block Complete Callback ID
  *           @arg @ref HAL_USART_RX_COMPLETE_CB_ID Rx Complete Callback ID
  *           @arg @ref HAL_USART_TX_RX_COMPLETE_CB_ID Rx Complete Callback ID
  *           @arg @ref HAL_USART_ERROR_CB_ID Error Callback ID
  *           @arg @ref HAL_USART_ABORT_COMPLETE_CB_ID Abort Complete Callback ID
  *           @arg @ref HAL_USART_RX_FIFO_FULL_CB_ID Rx Fifo Full Callback ID
  *           @arg @ref HAL_USART_TX_FIFO_EMPTY_CB_ID Tx Fifo Empty Callback ID
  *           @arg @ref HAL_USART_MSPINIT_CB_ID MspInit Callback ID
  *           @arg @ref HAL_USART_MSPDEINIT_CB_ID MspDeInit Callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_RegisterCallback(USART_HandleTypeDef *husart, HAL_USART_CallbackIDTypeDef CallbackID,
                                             pUSART_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    husart->ErrorCode |= HAL_USART_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(husart);

  if (husart->State == HAL_USART_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_USART_TX_SRCCOMPLETE_CB_ID :
        husart->TxSrcCpltCallback = pCallback;
        break;

      case HAL_USART_TX_BLOCKCOMPLETE_CB_ID :
        husart->TxBlockCpltCallback = pCallback;
        break;

      case HAL_USART_TX_HALFBLOCKCOMPLETE_CB_ID :
        husart->TxHalfBlockCpltCallback = pCallback;
        break;

      case HAL_USART_TX_COMPLETE_CB_ID :
        husart->TxCpltCallback = pCallback;
        break;

      case HAL_USART_RX_DSTCOMPLETE_CB_ID :
        husart->RxDstCpltCallback = pCallback;
        break;

      case HAL_USART_RX_BLOCKCOMPLETE_CB_ID :
        husart->RxBlockCpltCallback = pCallback;
        break;

      case HAL_USART_RX_HALFBLOCKCOMPLETE_CB_ID :
        husart->RxHalfBlockCpltCallback = pCallback;
        break;

      case HAL_USART_RX_COMPLETE_CB_ID :
        husart->RxCpltCallback = pCallback;
        break;

      case HAL_USART_TX_RX_COMPLETE_CB_ID :
        husart->TxRxCpltCallback = pCallback;
        break;

      case HAL_USART_ERROR_CB_ID :
        husart->ErrorCallback = pCallback;
        break;

      case HAL_USART_ABORT_COMPLETE_CB_ID :
        husart->AbortCpltCallback = pCallback;
        break;

      case HAL_USART_RX_FIFO_FULL_CB_ID :
        husart->RxFifoFullCallback = pCallback;
        break;

      case HAL_USART_TX_FIFO_EMPTY_CB_ID :
        husart->TxFifoEmptyCallback = pCallback;
        break;

      case HAL_USART_MSPINIT_CB_ID :
        husart->MspInitCallback = pCallback;
        break;

      case HAL_USART_MSPDEINIT_CB_ID :
        husart->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        husart->ErrorCode |= HAL_USART_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (husart->State == HAL_USART_STATE_RESET)
  {
    switch (CallbackID)
    {
    case HAL_USART_MSPINIT_CB_ID :
      husart->MspInitCallback = pCallback;
      break;

    case HAL_USART_MSPDEINIT_CB_ID :
      husart->MspDeInitCallback = pCallback;
      break;

    default :
      /* Update the error code */
      husart->ErrorCode |= HAL_USART_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* Update the error code */
    husart->ErrorCode |= HAL_USART_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husart);

  return status;
}

/**
  * @brief  Unregister an USART Callback
  *         USART callaback is redirected to the weak predefined callback
  * @param  husart usart handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_USART_TX_SRCCOMPLETE_CB_ID Tx Source Complete Callback ID
  *           @arg @ref HAL_USART_TX_BLOCKCOMPLETE_CB_ID Tx Block Complete Callback ID
  *           @arg @ref HAL_USART_TX_HALFBLOCKCOMPLETE_CB_ID Tx Half Block Complete Callback ID
  *           @arg @ref HAL_USART_TX_COMPLETE_CB_ID Tx Complete Callback ID
  *           @arg @ref HAL_USART_RX_DSTCOMPLETE_CB_ID Rx Destination Complete Callback ID
  *           @arg @ref HAL_USART_RX_BLOCKCOMPLETE_CB_ID Rx Block Complete Callback ID
  *           @arg @ref HAL_USART_RX_HALFBLOCKCOMPLETE_CB_ID Rx Half Block Complete Callback ID
  *           @arg @ref HAL_USART_RX_COMPLETE_CB_ID Rx Complete Callback ID
  *           @arg @ref HAL_USART_TX_RX_COMPLETE_CB_ID Rx Complete Callback ID
  *           @arg @ref HAL_USART_ERROR_CB_ID Error Callback ID
  *           @arg @ref HAL_USART_ABORT_COMPLETE_CB_ID Abort Complete Callback ID
  *           @arg @ref HAL_USART_RX_FIFO_FULL_CB_ID Rx Fifo Full Callback ID
  *           @arg @ref HAL_USART_TX_FIFO_EMPTY_CB_ID Tx Fifo Empty Callback ID
  *           @arg @ref HAL_USART_MSPINIT_CB_ID MspInit Callback ID
  *           @arg @ref HAL_USART_MSPDEINIT_CB_ID MspDeInit Callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_UnRegisterCallback(USART_HandleTypeDef *husart, HAL_USART_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(husart);

  if (HAL_USART_STATE_READY == husart->State)
  {
    switch (CallbackID)
    {
      case HAL_USART_TX_SRCCOMPLETE_CB_ID :
        husart->TxSrcCpltCallback = HAL_USART_TxSrcCpltCallback;                 /* Legacy weak TxSrcCpltCallback         */
        break;

      case HAL_USART_TX_BLOCKCOMPLETE_CB_ID :
        husart->TxBlockCpltCallback = HAL_USART_TxBlockCpltCallback;             /* Legacy weak TxBlockCpltCallback       */
        break;

      case HAL_USART_TX_HALFBLOCKCOMPLETE_CB_ID :
        husart->TxHalfBlockCpltCallback = HAL_USART_TxHalfBlockCpltCallback;     /* Legacy weak TxHalfBlockCpltCallback   */
        break;

      case HAL_USART_TX_COMPLETE_CB_ID :
        husart->TxCpltCallback = HAL_USART_TxCpltCallback;                       /* Legacy weak TxCpltCallback            */
        break;

      case HAL_USART_RX_DSTCOMPLETE_CB_ID :
        husart->RxDstCpltCallback = HAL_USART_RxDstCpltCallback;                 /* Legacy weak RxDstCpltCallback         */
        break;

      case HAL_USART_RX_BLOCKCOMPLETE_CB_ID :
        husart->RxBlockCpltCallback = HAL_USART_RxBlockCpltCallback;             /* Legacy weak RxBlockCpltCallback       */
        break;

      case HAL_USART_RX_HALFBLOCKCOMPLETE_CB_ID :
        husart->RxHalfBlockCpltCallback = HAL_USART_RxHalfBlockCpltCallback;     /* Legacy weak RxHalfBlockCpltCallback   */
        break;

      case HAL_USART_RX_COMPLETE_CB_ID :
        husart->RxCpltCallback = HAL_USART_RxCpltCallback;                       /* Legacy weak RxCpltCallback            */
        break;

      case HAL_USART_TX_RX_COMPLETE_CB_ID :
        husart->TxRxCpltCallback = HAL_USART_TxRxCpltCallback;                   /* Legacy weak TxRxCpltCallback          */
        break;

      case HAL_USART_ERROR_CB_ID :
        husart->ErrorCallback = HAL_USART_ErrorCallback;                         /* Legacy weak ErrorCallback             */
        break;

      case HAL_USART_ABORT_COMPLETE_CB_ID :
        husart->AbortCpltCallback = HAL_USART_AbortCpltCallback;                 /* Legacy weak AbortCpltCallback         */
        break;

      case HAL_USART_RX_FIFO_FULL_CB_ID :
        husart->RxFifoFullCallback = HAL_USARTEx_RxFifoFullCallback;             /* Legacy weak RxFifoFullCallback        */
        break;

      case HAL_USART_TX_FIFO_EMPTY_CB_ID :
        husart->TxFifoEmptyCallback = HAL_USARTEx_TxFifoEmptyCallback;           /* Legacy weak TxFifoEmptyCallback       */
        break;

      case HAL_USART_MSPINIT_CB_ID :
        husart->MspInitCallback = HAL_USART_MspInit;                             /* Legacy weak MspInitCallback           */
        break;

      case HAL_USART_MSPDEINIT_CB_ID :
        husart->MspDeInitCallback = HAL_USART_MspDeInit;                         /* Legacy weak MspDeInitCallback         */
        break;

      default :
        /* Update the error code */
        husart->ErrorCode |= HAL_USART_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_USART_STATE_RESET == husart->State)
  {
    switch (CallbackID)
    {
    case HAL_USART_MSPINIT_CB_ID :
      husart->MspInitCallback = HAL_USART_MspInit;
      break;

    case HAL_USART_MSPDEINIT_CB_ID :
      husart->MspDeInitCallback = HAL_USART_MspDeInit;
      break;

    default :
      /* Update the error code */
      husart->ErrorCode |= HAL_USART_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* Update the error code */
    husart->ErrorCode |= HAL_USART_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(husart);

  return status;
}
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup USART_Exported_Functions_Group2 IO operation functions
  *  @brief USART Transmit and Receive functions
  *
  * @{
  */

/**
  * @brief  Sends an amount of data in blocking mode.
  * @note   When Word Length is configured to 9 bits,
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @param  husart Pointer to a USART_HandleTypeDef structure that contains
  *               the configuration information for the specified USART module.
  * @param  pTxData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16 or u32) to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_Transmit(USART_HandleTypeDef *husart, uint8_t *pTxData, uint32_t Size,
                                     uint32_t Timeout)
{
  uint8_t  *ptxdata8bits;
  uint16_t *ptxdata16bits;
  uint32_t tickstart;

  /* Check that a Tx process is not already ongoing */
  if (husart->State == HAL_USART_STATE_READY)
  {
    if ((pTxData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }
    /* In case of 9bits transfer, pData buffer provided as input parameter
       should be aligned on a u16 frontier, as data to be filled into DR will be
       handled through a u16 cast. */
    if ((husart->Init.WordLength == USART_WORDLENGTH_9B) && (husart->Init.Parity == USART_PARITY_NONE))
    {
      if ((((uint32_t)pTxData) & 1U) != 0U)
      {
        return  HAL_ERROR;
      }
    }
    /* Process Locked */
    __HAL_LOCK(husart);

    husart->ErrorCode = HAL_USART_ERROR_NONE;
    husart->State = HAL_USART_STATE_BUSY_TX;

    /* Init tickstart for timeout managment */
    tickstart = HAL_GetTick();

    husart->TxXferSize = Size;
    husart->TxXferCount = Size;

    /* In case of 9bits/No Parity transfer, pData needs to be handled as a uint16_t pointer */
    if ((husart->Init.WordLength == USART_WORDLENGTH_9B) && (husart->Init.Parity == USART_PARITY_NONE))
    {
      ptxdata8bits  = NULL;
      ptxdata16bits = (uint16_t *) pTxData;
    }
    else
    {
      ptxdata8bits  = pTxData;
      ptxdata16bits = NULL;
    }

    while (husart->TxXferCount > 0U)
    {
      if (USART_WaitOnFlagUntilTimeout(husart, USART_FLAG_TXE, RESET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
      if (ptxdata8bits == NULL)
      {
        husart->Instance->DR = (uint16_t)(*ptxdata16bits & 0x01FFU);
        ptxdata16bits++;
      }
      else
      {
        husart->Instance->DR = (uint8_t)(*ptxdata8bits & 0xFFU);
        ptxdata8bits++;
      }

      husart->TxXferCount--;
    }

    if (USART_WaitOnFlagUntilTimeout(husart, USART_FLAG_TC, RESET, tickstart, Timeout) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    /* Clear Transmission Complete Flag */
    __HAL_USART_CLEAR_FLAG(husart, USART_FLAG_TC);

    /* Clear overrun flag and discard the received data */
    __HAL_USART_CLEAR_OREFLAG(husart);
    __HAL_USART_SEND_REQ(husart, USART_RXDATA_FLUSH_REQUEST);
    __HAL_USART_SEND_REQ(husart, USART_TXDATA_FLUSH_REQUEST);

    /* At end of Tx process, restore husart->State to Ready */
    husart->State = HAL_USART_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(husart);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in blocking mode.
  * @note   To receive synchronous data, dummy data are simultaneously transmitted.
  * @note   When USART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the received data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 available through pRxData.
  * @param husart USART handle.
  * @param pRxData Pointer to data buffer (u8 or u16 data elements).
  * @param Size Amount of data elements (u8 or u16 or u32) to be received.
  * @param Timeout Timeout duration.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_Receive(USART_HandleTypeDef *husart, uint8_t *pRxData, uint32_t Size, uint32_t Timeout)
{
  uint8_t  *prxdata8bits;
  uint16_t *prxdata16bits;
  uint16_t uhMask;
  uint32_t tickstart;

  /* Check that a Rx process is not already ongoing */
  if (husart->State == HAL_USART_STATE_READY)
  {
    if ((pRxData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }
    /* In case of 9bits, pData buffer provided as input parameter
       should be aligned on a u16 frontier, as data to be received from RDR will be
       handled through a u16 cast. */
    if ((husart->Init.WordLength == USART_WORDLENGTH_9B) && (husart->Init.Parity == USART_PARITY_NONE))
    {
      if ((((uint32_t)pRxData) & 1U) != 0U)
      {
        return  HAL_ERROR;
      }
    }
    /* Process Locked */
    __HAL_LOCK(husart);

    husart->ErrorCode = HAL_USART_ERROR_NONE;
    husart->State = HAL_USART_STATE_BUSY_RX;

    /* Init tickstart for timeout managment */
    tickstart = HAL_GetTick();

    husart->RxXferSize = Size;
    husart->RxXferCount = Size;

    /* Computation of USART mask to apply to RDR register */
    USART_MASK_COMPUTATION(husart);
    uhMask = husart->Mask;

    /* In case of 9bits, pRxData needs to be handled as a uint16_t pointer */
    if ((husart->Init.WordLength == USART_WORDLENGTH_9B) && (husart->Init.Parity == USART_PARITY_NONE))
    {
      prxdata8bits  = NULL;
      prxdata16bits = (uint16_t *) pRxData;
    }
    else
    {
      prxdata8bits  = pRxData;
      prxdata16bits = NULL;
    }
    
    /* as long as data have to be received */
    while (husart->RxXferCount > 0U)
    {

      /* Wait for RXNE Flag */
      if (USART_WaitOnFlagUntilTimeout(husart, USART_FLAG_RXNE, RESET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }

      if (prxdata8bits == NULL)
      {
        *prxdata16bits = (uint16_t)(husart->Instance->DR & uhMask);
        prxdata16bits++;
      }
      else
      {
        *prxdata8bits = (uint8_t)(husart->Instance->DR & (uint8_t)(uhMask & 0xFFU));
        prxdata8bits++;
      }
      husart->RxXferCount--;
    }
    /* At end of Rx process, restore husart->State to Ready */
    husart->State = HAL_USART_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(husart);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Full-Duplex Send and Receive an amount of data in blocking mode.
  * @note   When USART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data and the received data are handled as sets of u16. In this case, Size must indicate the number
  *         of u16 available through pTxData and through pRxData.
  * @param  husart USART handle.
  * @param  pTxData pointer to TX data buffer (u8 or u16 data elements).
  * @param  pRxData pointer to RX data buffer (u8 or u16 data elements).
  * @param  Size amount of data elements (u8 or u16 or u32) to be sent (same amount to be received).
  * @param  Timeout Timeout duration.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_TransmitReceive(USART_HandleTypeDef *husart, uint8_t *pTxData, uint8_t *pRxData,
                                            uint32_t Size, uint32_t Timeout)
{
  uint8_t  *prxdata8bits;
  uint16_t *prxdata16bits;
  uint8_t  *ptxdata8bits;
  uint16_t *ptxdata16bits;
  uint16_t uhMask;
  uint32_t rxdatacount;
  uint32_t tickstart;

  if (husart->State == HAL_USART_STATE_READY)
  {
    if ((pTxData == NULL) || (pRxData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(husart);

    husart->ErrorCode = HAL_USART_ERROR_NONE;
    husart->State = HAL_USART_STATE_BUSY_RX;

    /* Init tickstart for timeout management */
    tickstart = HAL_GetTick();

    husart->RxXferSize = Size;
    husart->TxXferSize = Size;
    husart->TxXferCount = Size;
    husart->RxXferCount = Size;

    /* Computation of USART mask to apply to RDR register */
    USART_MASK_COMPUTATION(husart);
    uhMask = husart->Mask;

    /* In case of 9bits/No Parity transfer, pRxData needs to be handled as a uint16_t pointer */
    if ((husart->Init.WordLength == USART_WORDLENGTH_9B) && (husart->Init.Parity == USART_PARITY_NONE))
    {
      prxdata8bits  = NULL;
      ptxdata8bits  = NULL;
      ptxdata16bits = (uint16_t *) pTxData;
      prxdata16bits = (uint16_t *) pRxData;
    }
    else
    {
      prxdata8bits  = pRxData;
      ptxdata8bits  = pTxData;
      ptxdata16bits = NULL;
      prxdata16bits = NULL;
    }

    if (husart->TxXferCount == 0x01U)
    {
      /* Wait until TXE flag is set to send data */
      if (USART_WaitOnFlagUntilTimeout(husart, USART_FLAG_TXE, RESET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
      if (ptxdata8bits == NULL)
      {
        husart->Instance->DR = (uint16_t)(*ptxdata16bits & uhMask);
        ptxdata16bits++;
      }
      else
      {
        husart->Instance->DR = (uint8_t)(*ptxdata8bits & (uint8_t)(uhMask & 0xFFU));
        ptxdata8bits++;
      }

      husart->TxXferCount--;
    }

    /* Check the remain data to be sent */
    /* rxdatacount is a temporary variable for MISRAC2012-Rule-13.5 */
    rxdatacount = husart->RxXferCount;
    while ((husart->TxXferCount > 0U) || (rxdatacount > 0U))
    {
      if (husart->TxXferCount > 0U)
      {
        /* Wait until TXE flag is set to send data */
        if (USART_WaitOnFlagUntilTimeout(husart, USART_FLAG_TXE, RESET, tickstart, Timeout) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }
        if (ptxdata8bits == NULL)
        {
          husart->Instance->DR = (uint16_t)(*ptxdata16bits & uhMask);
          ptxdata16bits++;
        }
        else
        {
          husart->Instance->DR = (uint8_t)(*ptxdata8bits & (uint8_t)(uhMask & 0xFFU));
          ptxdata8bits++;
        }

        husart->TxXferCount--;
      }

      if (husart->RxXferCount > 0U)
      {
        /* Wait for RXNE Flag */
        if (USART_WaitOnFlagUntilTimeout(husart, USART_FLAG_RXNE, RESET, tickstart, Timeout) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }

        if (prxdata8bits == NULL)
        {
          *prxdata16bits = (uint16_t)(husart->Instance->DR & uhMask);
          prxdata16bits++;
        }
        else
        {
          *prxdata8bits = (uint8_t)(husart->Instance->DR & (uint8_t)(uhMask & 0xFFU));
          prxdata8bits++;
        }

        husart->RxXferCount--;
      }
      rxdatacount = husart->RxXferCount;
    }

    /* At end of TxRx process, restore husart->State to Ready */
    husart->State  = HAL_USART_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(husart);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Send an amount of data in interrupt mode.
  * @note   When USART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pTxData.
  * @param  husart USART handle.
  * @param  pTxData pointer to data buffer (u8 or u16 data elements).
  * @param  Size amount of data elements (u8 or u16 or u32) to be sent.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_Transmit_IT(USART_HandleTypeDef *husart, uint8_t *pTxData, uint32_t Size)
{
  /* Check that a Tx process is not already ongoing */
  if (husart->State == HAL_USART_STATE_READY)
  {
    if ((pTxData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(husart);

    husart->pTxBuffPtr  = pTxData;
    husart->TxXferSize  = Size;
    husart->TxXferCount = Size;
    husart->TxISR       = NULL;

    husart->ErrorCode = HAL_USART_ERROR_NONE;
    husart->State     = HAL_USART_STATE_BUSY_TX;

    /* The USART Error Interrupts: (Frame error, noise error, overrun error)
    are not managed by the USART Transmit Process to avoid the overrun interrupt
    when the usart mode is configured for transmit and receive "USART_MODE_TX_RX"
    to benefit for the frame error and noise interrupts the usart mode should be
    configured only for transmit "USART_MODE_TX" */

    /* Configure Tx interrupt processing */
    if (husart->FifoMode == USART_FIFOMODE_ENABLE)
    {
      /* Set the Tx SR function pointer according to the data word length */
      if ((husart->Init.WordLength == USART_WORDLENGTH_9B) && (husart->Init.Parity == USART_PARITY_NONE))
      {
        husart->TxISR = USART_TxSR_16BIT_FIFOEN;
      }
      else
      {
        husart->TxISR = USART_TxSR_8BIT_FIFOEN;
      }

      /* Process Unlocked */
      __HAL_UNLOCK(husart);

      /* Enable the TX FIFO threshold interrupt */
      __HAL_USART_ENABLE_IT(husart, USART_IT_TXFT);
    }
    else
    {
      /* Set the Tx SR function pointer according to the data word length */
      if ((husart->Init.WordLength == USART_WORDLENGTH_9B) && (husart->Init.Parity == USART_PARITY_NONE))
      {
        husart->TxISR = USART_TxSR_16BIT;
      }
      else
      {
        husart->TxISR = USART_TxSR_8BIT;
      }

      /* Process Unlocked */
      __HAL_UNLOCK(husart);

      /* Enable the USART Transmit Data Register Empty Interrupt */
      SET_BIT(husart->Instance->CR1, USART_CR1_TXEIE);
    }

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in interrupt mode.
  * @note   To receive synchronous data, dummy data are simultaneously transmitted.
  * @note   When USART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the received data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 available through pRxData.
  * @param  husart USART handle.
  * @param  pRxData pointer to data buffer (u8 or u16 data elements).
  * @param  Size amount of data elements (u8 or u16 or u32) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_Receive_IT(USART_HandleTypeDef *husart, uint8_t *pRxData, uint32_t Size)
{
  /* Check that a Rx process is not already ongoing */
  if (husart->State == HAL_USART_STATE_READY)
  {
    if ((pRxData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(husart);

    husart->pRxBuffPtr  = pRxData;
    husart->RxXferSize  = Size;
    husart->RxXferCount = Size;
    husart->RxISR       = NULL;

    USART_MASK_COMPUTATION(husart);

    husart->ErrorCode = HAL_USART_ERROR_NONE;
    husart->State = HAL_USART_STATE_BUSY_RX;

    /* Enable the USART Error Interrupt: (Frame error, noise error, overrun error) */
    SET_BIT(husart->Instance->CR3, USART_CR3_EIE);

    /* Configure Rx interrupt processing */
    if ((husart->FifoMode == USART_FIFOMODE_ENABLE) && (Size >= husart->NbRxDataToProcess))
    {
      /* Set the Rx ISR function pointer according to the data word length */
      if ((husart->Init.WordLength == USART_WORDLENGTH_9B) && (husart->Init.Parity == USART_PARITY_NONE))
      {
        husart->RxISR = USART_RxSR_16BIT_FIFOEN;
      }
      else
      {
        husart->RxISR = USART_RxSR_8BIT_FIFOEN;
      }
      
      /* Process Unlocked */
      __HAL_UNLOCK(husart);

      /* Enable the USART Parity Error Interrupt */
      __HAL_USART_ENABLE_IT(husart, USART_IT_PE);
      /* Enable the UART Error Interrupt: (Frame error, noise error, overrun error) */
      SET_BIT(husart->Instance->CR3, USART_CR3_EIE);
      /* Enable the USART Data Register not empty Interrupt */
      SET_BIT(husart->Instance->CR3, USART_CR3_RXFTIE);
    }
    else
    {
      /* Set the Rx ISR function pointer according to the data word length */
      if ((husart->Init.WordLength == USART_WORDLENGTH_9B) && (husart->Init.Parity == USART_PARITY_NONE))
      {
        husart->RxISR = USART_RxSR_16BIT;
      }
      else
      {
        husart->RxISR = USART_RxSR_8BIT;
      }
      
      /* Process Unlocked */
      __HAL_UNLOCK(husart);

      /* Enable the USART Parity Error and Data Register not empty Interrupts */
      SET_BIT(husart->Instance->CR1, USART_CR1_PEIE | USART_CR1_RXNEIE);

      /* Enable the USART Error Interrupt: (Frame error, noise error, overrun error) */
      SET_BIT(husart->Instance->CR3, USART_CR3_EIE);

      /* Send dummy byte in order to generate the clock for the slave to send data */
      husart->Instance->DR = (USART_DUMMY_DATA & (uint16_t)0x01FF);

    }
    
    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Full-Duplex Send and Receive an amount of data in interrupt mode.
  * @note   When USART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data and the received data are handled as sets of u16. In this case, Size must indicate the number
  *         of u16 available through pTxData and through pRxData.
  * @param  husart USART handle.
  * @param  pTxData pointer to TX data buffer (u8 or u16 data elements).
  * @param  pRxData pointer to RX data buffer (u8 or u16 data elements).
  * @param  Size amount of data elements (u8 or u16 or u32) to be sent (same amount to be received).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_TransmitReceive_IT(USART_HandleTypeDef *husart, uint8_t *pTxData, uint8_t *pRxData,
                                               uint32_t Size)
{

  if (husart->State == HAL_USART_STATE_READY)
  {
    if ((pTxData == NULL) || (pRxData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(husart);

    husart->pRxBuffPtr = pRxData;
    husart->RxXferSize = Size;
    husart->RxXferCount = Size;
    husart->pTxBuffPtr = pTxData;
    husart->TxXferSize = Size;
    husart->TxXferCount = Size;

    /* Computation of USART mask to apply to RDR register */
    USART_MASK_COMPUTATION(husart);

    husart->ErrorCode = HAL_USART_ERROR_NONE;
    husart->State = HAL_USART_STATE_BUSY_TX_RX;

    /* Configure TxRx interrupt processing */
    if ((husart->FifoMode == USART_FIFOMODE_ENABLE) && (Size >= husart->NbRxDataToProcess))
    {
      /* Set the Rx ISR function pointer according to the data word length */
      if ((husart->Init.WordLength == USART_WORDLENGTH_9B) && (husart->Init.Parity == USART_PARITY_NONE))
      {
        husart->TxISR = USART_TxSR_16BIT_FIFOEN;
        husart->RxISR = USART_RxSR_16BIT_FIFOEN;
      }
      else
      {
        husart->TxISR = USART_TxSR_8BIT_FIFOEN;
        husart->RxISR = USART_RxSR_8BIT_FIFOEN;
      }

      /* Process Locked */
      __HAL_UNLOCK(husart);

      /* Enable the USART Error Interrupt: (Frame error, noise error, overrun error) */
      SET_BIT(husart->Instance->CR3, USART_CR3_EIE);

      /* Enable the USART Parity Error Interrupt */
      SET_BIT(husart->Instance->CR1, USART_CR1_PEIE);

      /* Enable the TX and  RX FIFO Threshold interrupts */
      SET_BIT(husart->Instance->CR3, (USART_CR3_TXFTIE | USART_CR3_RXFTIE));
    }
    else
    {
      if ((husart->Init.WordLength == USART_WORDLENGTH_9B) && (husart->Init.Parity == USART_PARITY_NONE))
      {
        husart->TxISR = USART_TxSR_16BIT;
        husart->RxISR = USART_RxSR_16BIT;
      }
      else
      {
        husart->TxISR = USART_TxSR_8BIT;
        husart->RxISR = USART_RxSR_8BIT;
      }

      /* Process Locked */
      __HAL_UNLOCK(husart);

      /* Enable the USART Error Interrupt: (Frame error, noise error, overrun error) */
      SET_BIT(husart->Instance->CR3, USART_CR3_EIE);

      /* Enable the USART Parity Error, USART Transmit Data Register Empty and USART Data Register not empty Interrupt */
      SET_BIT(husart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_TXEIE | USART_CR1_PEIE));
    }

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Send an amount of data in DMA mode.
  * @note   When USART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pTxData.
  * @param  husart USART handle.
  * @param  pTxData pointer to data buffer (u8 or u16 data elements).
  * @param  Size amount of data elements (u8 or u16 or u32) to be sent.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_Transmit_DMA(USART_HandleTypeDef *husart, uint8_t *pTxData, uint32_t Size)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t *tmp;

  if (husart->State == HAL_USART_STATE_READY)
  {
    if ((pTxData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(husart);

    husart->pTxBuffPtr = pTxData;
    husart->TxXferSize = Size;
    husart->TxXferCount = Size;

    husart->ErrorCode = HAL_USART_ERROR_NONE;
    husart->State = HAL_USART_STATE_BUSY_TX;

    if (husart->hdmatx != NULL)
    {
      /* Set the USART DMA transfer complete callback */
      husart->hdmatx->XferCpltCallback = USART_DMATransmitCplt;

      /* Set the USART DMA Half Block transfer complete callback */
      husart->hdmatx->XferHalfBlockCpltCallback = USART_DMATxHalfBlockCplt;

      /* Set the USART DMA Block transfer complete callback */
      husart->hdmatx->XferBlockCpltCallback = USART_DMATxBlockCplt;

      /* Set the USART Source transfer complete callback */
      husart->hdmatx->XferSrcTranCpltCallback = USART_DMATxSrcTransmitCplt;

      /* Set the DMA error callback */
      husart->hdmatx->XferErrorCallback = USART_DMAError;

      /* Enable the USART transmit DMA channel */
      tmp = (uint32_t *)&pTxData;
      status = HAL_DMA_Start_IT(husart->hdmatx, *(uint32_t *)tmp, (uint32_t)&husart->Instance->DR, Size);
    }

    if (status == HAL_OK)
    {
      /* Clear the TC flag */
      __HAL_USART_CLEAR_FLAG(husart, USART_FLAG_TC);

      /* Process Unlocked */
      __HAL_UNLOCK(husart);

      /* Enable the DMA transfer for transmit request by setting the DMAT bit
         in the USART CR3 register */
      SET_BIT(husart->Instance->CR3, USART_CR3_DMAT);

      return HAL_OK;
    }
    else
    {
      /* Set error code to DMA */
      husart->ErrorCode = HAL_USART_ERROR_DMA;

      /* Process Unlocked */
      __HAL_UNLOCK(husart);

      /* Restore husart->State to ready */
      husart->State = HAL_USART_STATE_READY;

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
  * @note   When the USART parity is enabled (PCE = 1), the received data contain
  *         the parity bit (MSB position).
  * @note   The USART DMA transmit channel must be configured in order to generate the clock for the slave.
  * @note   When USART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the received data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 available through pRxData.
  * @param  husart USART handle.
  * @param  pRxData pointer to data buffer (u8 or u16 data elements).
  * @param  Size amount of data elements (u8 or u16 u32) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_Receive_DMA(USART_HandleTypeDef *husart, uint8_t *pRxData, uint32_t Size)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t *tmp = (uint32_t *)&pRxData;

  /* Check that a Rx process is not already ongoing */
  if (husart->State == HAL_USART_STATE_READY)
  {
    if ((pRxData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(husart);

    husart->pRxBuffPtr = pRxData;
    husart->RxXferSize = Size;
    husart->pTxBuffPtr = pRxData;
    husart->TxXferSize = Size;

    husart->ErrorCode = HAL_USART_ERROR_NONE;
    husart->State = HAL_USART_STATE_BUSY_RX;

    if (husart->hdmarx != NULL)
    {
      /* Set the USART DMA Rx transfer complete callback */
      husart->hdmarx->XferCpltCallback = USART_DMAReceiveCplt;

      /* Set the USART DMA Block transfer complete callback */
      husart->hdmarx->XferBlockCpltCallback = USART_DMARxBlockCplt;

      /* Set the USART DMA Half Block transfer complete callback */
      husart->hdmarx->XferHalfBlockCpltCallback = USART_DMARxHalfBlockCplt;

      /* Set the USART DMA Destination transfer complete callback */
      husart->hdmarx->XferDstTranCpltCallback = USART_DMARxDstReceiveCplt;

      /* Set the USART DMA Rx transfer error callback */
      husart->hdmarx->XferErrorCallback = USART_DMAError;

      /* Enable the USART receive DMA channel */
      status = HAL_DMA_Start_IT(husart->hdmarx, (uint32_t)&husart->Instance->DR, *(uint32_t *)tmp, Size);
    }

    if (status == HAL_OK)
    {
      /* Clear the Overrun flag just before enabling the DMA Rx request: mandatory for the second transfer */
      __HAL_USART_CLEAR_OREFLAG(husart);

      /* Process Unlocked */
      __HAL_UNLOCK(husart);

      /* Enable the USART Parity Error Interrupt */
      SET_BIT(husart->Instance->CR1, USART_CR1_PEIE);

      /* Enable the USART Error Interrupt: (Frame error, noise error, overrun error) */
      SET_BIT(husart->Instance->CR3, USART_CR3_EIE);

      /* Enable the DMA transfer for the receiver request by setting the DMAR bit
         in the USART CR3 register */
      SET_BIT(husart->Instance->CR3, USART_CR3_DMAR);

      /* Enable the DMA transfer for transmit request by setting the DMAT bit in the USART CR3 register */
      SET_BIT(husart->Instance->CR3, USART_CR3_DMAT);

      return HAL_OK;
    }
    else
    {
      if (husart->hdmarx != NULL)
      {
        status = HAL_DMA_Abort(husart->hdmarx);
      }

      /* No need to check on error code */
      UNUSED(status);

      /* Set error code to DMA */
      husart->ErrorCode = HAL_USART_ERROR_DMA;

      /* Process Unlocked */
      __HAL_UNLOCK(husart);

      /* Restore husart->State to ready */
      husart->State = HAL_USART_STATE_READY;

      return HAL_ERROR;
    }
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Full-Duplex Transmit Receive an amount of data in non-blocking mode.
  * @note   When the USART parity is enabled (PCE = 1) the data received contain the parity bit.
  * @note   When USART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data and the received data are handled as sets of u16. In this case, Size must indicate the number
  *         of u16 available through pTxData and through pRxData.
  * @param  husart USART handle.
  * @param  pTxData pointer to TX data buffer (u8 or u16 data elements).
  * @param  pRxData pointer to RX data buffer (u8 or u16 data elements).
  * @param  Size amount of data elements (u8 or u16 or u32) to be received/sent.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_TransmitReceive_DMA(USART_HandleTypeDef *husart, uint8_t *pTxData, uint8_t *pRxData,
                                                uint32_t Size)
{
  HAL_StatusTypeDef status;
  uint32_t *tmp;

  if (husart->State == HAL_USART_STATE_READY)
  {
    if ((pTxData == NULL) || (pRxData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Process Locked */
    __HAL_LOCK(husart);

    husart->pRxBuffPtr = pRxData;
    husart->RxXferSize = Size;
    husart->pTxBuffPtr = pTxData;
    husart->TxXferSize = Size;

    husart->ErrorCode = HAL_USART_ERROR_NONE;
    husart->State = HAL_USART_STATE_BUSY_TX_RX;

    if ((husart->hdmarx != NULL) && (husart->hdmatx != NULL))
    {
      /* Set the USART DMA Rx transfer complete callback */
      husart->hdmarx->XferCpltCallback = USART_DMAReceiveCplt;

      /* Set the USART DMA Rx Block transfer complete callback */
      husart->hdmarx->XferBlockCpltCallback = USART_DMARxBlockCplt;

      /* Set the USART DMA Rx Half Block transfer complete callback */
      husart->hdmarx->XferHalfBlockCpltCallback = USART_DMARxHalfBlockCplt;

      /* Set the USART DMA destination transfer complete callback */
      husart->hdmarx->XferDstTranCpltCallback = USART_DMARxDstReceiveCplt;

      /* Set the USART DMA Tx transfer complete callback */
      husart->hdmatx->XferCpltCallback = USART_DMATransmitCplt;

      /* Set the USART DMA Tx Block transfer complete callback */
      husart->hdmatx->XferBlockCpltCallback = USART_DMATxBlockCplt;

      /* Set the USART DMA Tx Half Block transfer complete callback */
      husart->hdmatx->XferHalfBlockCpltCallback = USART_DMATxHalfBlockCplt;

      /* Set the USART DMA Tx Source transfer complete callback */
      husart->hdmatx->XferSrcTranCpltCallback = USART_DMATxSrcTransmitCplt;

      /* Set the USART DMA Tx transfer error callback */
      husart->hdmatx->XferErrorCallback = USART_DMAError;

      /* Set the USART DMA Rx transfer error callback */
      husart->hdmarx->XferErrorCallback = USART_DMAError;

      /* Enable the USART receive DMA channel */
      tmp = (uint32_t *)&pRxData;
      status = HAL_DMA_Start_IT(husart->hdmarx, (uint32_t)&husart->Instance->DR, *(uint32_t *)tmp, Size);

      /* Enable the USART transmit DMA channel */
      if (status == HAL_OK)
      {
        tmp = (uint32_t *)&pTxData;
        status = HAL_DMA_Start_IT(husart->hdmatx, *(uint32_t *)tmp, (uint32_t)&husart->Instance->DR, Size);
      }
    }
    else
    {
      status = HAL_ERROR;
    }

    /* Clear the TC flag in the SR register by writing 0 to it */
    __HAL_USART_CLEAR_FLAG(husart, USART_FLAG_TC);

    /* Clear the Overrun flag: mandatory for the second transfer in circular mode */
    __HAL_USART_CLEAR_OREFLAG(husart);

    if (status == HAL_OK)
    {
      /* Process Unlocked */
      __HAL_UNLOCK(husart);

      /* Enable the USART Parity Error Interrupt */
      SET_BIT(husart->Instance->CR1, USART_CR1_PEIE);

      /* Enable the USART Error Interrupt: (Frame error, noise error, overrun error) */
      SET_BIT(husart->Instance->CR3, USART_CR3_EIE);

      /* Enable the DMA transfer for the receiver request by setting the DMAR bit
         in the USART CR3 register */
      SET_BIT(husart->Instance->CR3, USART_CR3_DMAR);

      /* Enable the DMA transfer for transmit request by setting the DMAT bit
         in the USART CR3 register */
      SET_BIT(husart->Instance->CR3, USART_CR3_DMAT);

      return HAL_OK;
    }
    else
    {
      if (husart->hdmarx != NULL)
      {
        status = HAL_DMA_Abort(husart->hdmarx);
      }

      /* No need to check on error code */
      UNUSED(status);

      /* Set error code to DMA */
      husart->ErrorCode = HAL_USART_ERROR_DMA;

      /* Process Unlocked */
      __HAL_UNLOCK(husart);

      /* Restore husart->State to ready */
      husart->State = HAL_USART_STATE_READY;

      return HAL_ERROR;
    }
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Pause the DMA Transfer.
  * @param  husart USART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_DMAPause(USART_HandleTypeDef *husart)
{
  const HAL_USART_StateTypeDef state = husart->State;

  /* Process Locked */
  __HAL_LOCK(husart);

  if ((HAL_IS_BIT_SET(husart->Instance->CR3, USART_CR3_DMAT)) &&
      (state == HAL_USART_STATE_BUSY_TX))
  {
    /* Disable the USART DMA Tx request */
    CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAT);
  }
  else if ((state == HAL_USART_STATE_BUSY_RX) ||
           (state == HAL_USART_STATE_BUSY_TX_RX))
  {
    if (HAL_IS_BIT_SET(husart->Instance->CR3, USART_CR3_DMAT))
    {
      /* Disable the USART DMA Tx request */
      CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAT);
    }
    if (HAL_IS_BIT_SET(husart->Instance->CR3, USART_CR3_DMAR))
    {
      /* Disable PE and ERR (Frame error, noise error, overrun error) interrupts */
      CLEAR_BIT(husart->Instance->CR1, USART_CR1_PEIE);
      CLEAR_BIT(husart->Instance->CR3, USART_CR3_EIE);

      /* Disable the USART DMA Rx request */
      CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAR);
    }
  }
  else
  {
    /* Nothing to do */
  }

  /* Process Unlocked */
  __HAL_UNLOCK(husart);

  return HAL_OK;
}

/**
  * @brief Resume the DMA Transfer.
  * @param  husart USART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_DMAResume(USART_HandleTypeDef *husart)
{
  const HAL_USART_StateTypeDef state = husart->State;

  /* Process Locked */
  __HAL_LOCK(husart);

  if (state == HAL_USART_STATE_BUSY_TX)
  {
    /* Enable the USART DMA Tx request */
    SET_BIT(husart->Instance->CR3, USART_CR3_DMAT);
  }
  else if ((state == HAL_USART_STATE_BUSY_RX) ||
           (state == HAL_USART_STATE_BUSY_TX_RX))
  {
    /* Clear the Overrun flag before resuming the Rx transfer*/
    __HAL_USART_CLEAR_OREFLAG(husart);

    /* Re-enable PE and ERR (Frame error, noise error, overrun error) interrupts */
    SET_BIT(husart->Instance->CR1, USART_CR1_PEIE);
    SET_BIT(husart->Instance->CR3, USART_CR3_EIE);

    /* Enable the USART DMA Rx request  before the DMA Tx request */
    SET_BIT(husart->Instance->CR3, USART_CR3_DMAR);

    /* Enable the USART DMA Tx request */
    SET_BIT(husart->Instance->CR3, USART_CR3_DMAT);
  }
  else
  {
    /* Nothing to do */
  }

  /* Process Unlocked */
  __HAL_UNLOCK(husart);

  return HAL_OK;
}

/**
  * @brief Stop the DMA Transfer.
  * @param  husart USART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_DMAStop(USART_HandleTypeDef *husart)
{
  /* The Lock is not implemented on this API to allow the user application
     to call the HAL USART API under callbacks HAL_USART_TxCpltCallback() / HAL_USART_RxCpltCallback() /
     HAL_USART_TxHalfCpltCallback / HAL_USART_RxHalfCpltCallback:
     indeed, when HAL_DMA_Abort() API is called, the DMA TX/RX Transfer or Half Transfer complete
     interrupt is generated if the DMA transfer interruption occurs at the middle or at the end of
     the stream and the corresponding call back is executed. */

  /* Disable the USART Tx/Rx DMA requests */
  CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAT);
  CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAR);

  /* Abort the USART DMA tx channel */
  if (husart->hdmatx != NULL)
  {
    if (HAL_DMA_Abort(husart->hdmatx) != HAL_OK)
    {
      if (HAL_DMA_GetError(husart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
      {
        /* Set error code to DMA */
        husart->ErrorCode = HAL_USART_ERROR_DMA;

        return HAL_TIMEOUT;
      }
    }
  }
  /* Abort the USART DMA rx channel */
  if (husart->hdmarx != NULL)
  {
    if (HAL_DMA_Abort(husart->hdmarx) != HAL_OK)
    {
      if (HAL_DMA_GetError(husart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
      {
        /* Set error code to DMA */
        husart->ErrorCode = HAL_USART_ERROR_DMA;

        return HAL_TIMEOUT;
      }
    }
  }

  USART_EndTransfer(husart);
  husart->State = HAL_USART_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing transfers (blocking mode).
  * @param  husart USART handle.
  * @note   This procedure could be used for aborting any ongoing transfer started in Interrupt mode.
  *         This procedure performs following operations :
  *           - Disable USART Interrupts (Tx and Rx)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
*/
HAL_StatusTypeDef HAL_USART_Abort(USART_HandleTypeDef *husart)
{
  /* Disable TXEIE, TCIE, RXNE, RXFT, TXFT, PE and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(husart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE   | USART_CR1_TXEIE | USART_CR1_TCIE));
  CLEAR_BIT(husart->Instance->CR3, (USART_CR3_EIE    | USART_CR3_RXFTIE | USART_CR3_TXFTIE));

  /* Disable the USART DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(husart->Instance->CR3, USART_CR3_DMAT))
  {
    /* Abort the USART DMA Tx channel: use blocking DMA Abort API (no callback) */
    if (husart->hdmatx != NULL)
    {
      /* Set the USART DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      husart->hdmatx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(husart->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(husart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          husart->ErrorCode = HAL_USART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
    CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAT);
  }

  /* Disable the USART DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(husart->Instance->CR3, USART_CR3_DMAR))
  {
    CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAR);

    /* Abort the USART DMA Rx channel: use blocking DMA Abort API (no callback) */
    if (husart->hdmarx != NULL)
    {
      /* Set the USART DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      husart->hdmarx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(husart->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(husart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          husart->ErrorCode = HAL_USART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
  }

  /* Reset Tx and Rx transfer counters */
  husart->TxXferCount = 0x00U;
  husart->RxXferCount = 0x00U;

  /* Clear the Error flags IDLE + ORE NE FE PE bit */
  __HAL_USART_CLEAR_FEFLAG(husart);

  /* Flush the whole TX FIFO (if needed) */
  if (husart->FifoMode == USART_FIFOMODE_ENABLE)
  {
    __HAL_USART_SEND_REQ(husart, USART_TXDATA_FLUSH_REQUEST);
  }

  /* Discard the received data */
  __HAL_USART_SEND_REQ(husart, USART_RXDATA_FLUSH_REQUEST);

  /* Restore husart->State and husart->gState to Ready */
  husart->State = HAL_USART_STATE_READY;

  /* Reset Handle ErrorCode to No Error */
  husart->ErrorCode = HAL_USART_ERROR_NONE;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing transfers (Interrupt mode).
  * @param  husart USART handle.
  * @note   This procedure could be used for aborting any ongoing transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable USART Interrupts (Tx and Rx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort_IT (in case of transfer in DMA mode)
  *           - Set handle State to READY
  *           - At abort completion, call user abort complete callback
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_USART_Abort_IT(USART_HandleTypeDef *husart)
{
  uint32_t abortcplt = 1U;

  /* Disable TXEIE, TCIE, RXNE, RXFT, TXFT, PE and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(husart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE   | USART_CR1_TXEIE | USART_CR1_TCIE));
  CLEAR_BIT(husart->Instance->CR3, (USART_CR3_EIE    | USART_CR3_RXFTIE | USART_CR3_TXFTIE));

  /* If DMA Tx and/or DMA Rx Handles are associated to USART Handle, DMA Abort complete callbacks should be initialised
     before any call to DMA Abort functions */
  /* DMA Tx Handle is valid */
  if (husart->hdmatx != NULL)
  {
    /* Set DMA Abort Complete callback if USART DMA Tx request if enabled.
       Otherwise, set it to NULL */
    if (HAL_IS_BIT_SET(husart->Instance->CR3, USART_CR3_DMAT))
    {
      husart->hdmatx->XferAbortCallback = USART_DMATxAbortCallback;
    }
    else
    {
      husart->hdmatx->XferAbortCallback = NULL;
    }
  }
  /* DMA Rx Handle is valid */
  if (husart->hdmarx != NULL)
  {
    /* Set DMA Abort Complete callback if USART DMA Rx request if enabled.
       Otherwise, set it to NULL */
    if (HAL_IS_BIT_SET(husart->Instance->CR3, USART_CR3_DMAR))
    {
      husart->hdmarx->XferAbortCallback = USART_DMARxAbortCallback;
    }
    else
    {
      husart->hdmarx->XferAbortCallback = NULL;
    }
  }

  /* Abort the USART DMA Tx channel if enabled */
  if (HAL_IS_BIT_SET(husart->Instance->CR3, USART_CR3_DMAT))
  {
    /* Abort the USART DMA Tx channel : use non blocking DMA Abort API (callback) */
    if (husart->hdmatx != NULL)
    {
      /* USART Tx DMA Abort callback has already been initialised :
         will lead to call HAL_USART_AbortCpltCallback() at end of DMA abort procedure */

      /* Abort DMA TX */
      if (HAL_DMA_Abort_IT(husart->hdmatx) != HAL_OK)
      {
        husart->hdmatx->XferAbortCallback = NULL;
      }
      else
      {
        abortcplt = 0U;
      }
    }
    /* Disable DMA Tx at USART level */
    CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAT);
  }

  /* Abort the USART DMA Rx channel if enabled */
  if (HAL_IS_BIT_SET(husart->Instance->CR3, USART_CR3_DMAR))
  {
    /* Abort the USART DMA Rx channel : use non blocking DMA Abort API (callback) */
    if (husart->hdmarx != NULL)
    {
      /* USART Rx DMA Abort callback has already been initialised :
         will lead to call HAL_USART_AbortCpltCallback() at end of DMA abort procedure */

      /* Abort DMA RX */
      if (HAL_DMA_Abort_IT(husart->hdmarx) != HAL_OK)
      {
        husart->hdmarx->XferAbortCallback = NULL;
        abortcplt = 1U;
      }
      else
      {
        abortcplt = 0U;
      }
    }
    /* Disable the USART DMA Rx request if enabled */
    CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAR);
  }

  /* if no DMA abort complete callback execution is required => call user Abort Complete callback */
  if (abortcplt == 1U)
  {
    /* Reset Tx and Rx transfer counters */
    husart->TxXferCount = 0U;
    husart->RxXferCount = 0U;

    /* Reset errorCode */
    husart->ErrorCode = HAL_USART_ERROR_NONE;

    /* Clear the Error flags IDLE + ORE NE FE PE bit */
    __HAL_USART_CLEAR_FEFLAG(husart);

    /* Flush the whole TX FIFO (if needed) */
    if (husart->FifoMode == USART_FIFOMODE_ENABLE)
    {
      __HAL_USART_SEND_REQ(husart, USART_TXDATA_FLUSH_REQUEST);
    }

    /* Discard the received data */
    __HAL_USART_SEND_REQ(husart, USART_RXDATA_FLUSH_REQUEST);

    /* Restore husart->State to Ready */
    husart->State  = HAL_USART_STATE_READY;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
    /* Call registered Abort Complete Callback */
    husart->AbortCpltCallback(husart);
#else
    /* Call legacy weak Abort Complete Callback */
    HAL_USART_AbortCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
  }

  return HAL_OK;
}

/**
  * @brief  Handle USART interrupt request.
  * @param  husart USART handle.
  * @retval None
  */
void HAL_USART_IRQHandler(USART_HandleTypeDef *husart)
{
  uint32_t isrflags   = READ_REG(husart->Instance->SR);
  uint32_t cr1its     = READ_REG(husart->Instance->CR1);
  uint32_t cr3its     = READ_REG(husart->Instance->CR3);
  uint32_t errorflags = 0x00U;
  uint32_t dmarequest = 0x00U;

  /* If no error occurs */
  errorflags = (isrflags & (uint32_t)(USART_SR_PE | USART_SR_FE | USART_SR_ORE | USART_SR_NE | USART_SR_RTOF));
  if (errorflags == RESET)
  {
    /* USART in mode Receiver -------------------------------------------------*/
    if (((isrflags & USART_SR_RXNE) != RESET) && (((cr1its & USART_CR1_RXNEIE) != RESET) || ((cr3its & USART_CR3_RXFTIE) != 0U)))
    {
      husart->RxISR(husart);
      return;
    }
  }

  /* If some errors occur */
  if ((errorflags != RESET) && (((cr3its & (USART_CR3_RXFTIE | USART_CR3_EIE | USART_CR3_RTOIE)) != RESET) || ((cr1its & (USART_CR1_RXNEIE | USART_CR1_PEIE)) != RESET)))
  {
    /* USART parity error interrupt occurred ----------------------------------*/
    if (((isrflags & USART_SR_PE) != RESET) && ((cr1its & USART_CR1_PEIE) != RESET))
    {
      husart->ErrorCode |= HAL_USART_ERROR_PE;
    }

    /* USART noise error interrupt occurred -----------------------------------*/
    if (((isrflags & USART_SR_NE) != RESET) && ((cr3its & USART_CR3_EIE) != RESET))
    {
      husart->ErrorCode |= HAL_USART_ERROR_NE;
    }

    /* USART frame error interrupt occurred -----------------------------------*/
    if (((isrflags & USART_SR_FE) != RESET) && ((cr3its & USART_CR3_EIE) != RESET))
    {
      husart->ErrorCode |= HAL_USART_ERROR_FE;
    }

    /* USART Over-Run interrupt occurred --------------------------------------*/
    if (((isrflags & USART_SR_ORE) != RESET) && (((cr1its & USART_CR1_RXNEIE) != 0U) || ((cr3its & (USART_CR3_RXFTIE | USART_CR3_EIE)) != RESET)))
    {
      husart->ErrorCode |= HAL_USART_ERROR_ORE;
    }

    /* USART Receiver Timeout interrupt occurred ---------------------------------*/
    if (((isrflags & USART_SR_RTOF) != 0U) && ((cr3its & USART_CR3_RTOIE) != 0U))
    {
      __HAL_USART_CLEAR_RTOFLAG(husart);
      
      husart->ErrorCode |= HAL_USART_ERROR_RTO;
    }

    /* Call USART Error Call back function if need be --------------------------*/
    if (husart->ErrorCode != HAL_USART_ERROR_NONE)
    {
      /* USART in mode Receiver -----------------------------------------------*/
      if (((isrflags & USART_SR_RXNE) != RESET) && (((cr1its & USART_CR1_RXNEIE) != RESET) || ((cr3its & USART_CR3_RXFTIE) != 0U)))
      {
        husart->RxISR(husart);
      }

      /* If Overrun error occurs, or if any error occurs in DMA mode reception,
         consider error as blocking */
      dmarequest = HAL_IS_BIT_SET(husart->Instance->CR3, USART_CR3_DMAR);
      if (((husart->ErrorCode & HAL_USART_ERROR_ORE) != RESET) || dmarequest)
      {
        /* Blocking error : transfer is aborted
           Set the USART state ready to be able to start again the process,
           Disable Interrupts, and disable DMA requests, if ongoing */
        USART_EndTransfer(husart);

        /* Abort the USART DMA Rx channel if enabled */
        if (HAL_IS_BIT_SET(husart->Instance->CR3, USART_CR3_DMAR))
        {
          /* Disable the USART DMA Rx request if enabled */
          CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAR);

          /* Abort the USART DMA Tx channel */
          if (husart->hdmatx != NULL)
          {
            /* Set the USART Tx DMA Abort callback to NULL : no callback
               executed at end of DMA abort procedure */
            husart->hdmatx->XferAbortCallback = NULL;

            /* Abort DMA TX */
            (void)HAL_DMA_Abort_IT(husart->hdmatx);
          }

          /* Abort the USART DMA Rx channel */
          if (husart->hdmarx != NULL)
          {
            /* Set the USART Rx DMA Abort callback :
               will lead to call HAL_USART_ErrorCallback() at end of DMA abort procedure */
            husart->hdmarx->XferAbortCallback = USART_DMAAbortOnError;

            /* Abort DMA RX */
            if (HAL_DMA_Abort_IT(husart->hdmarx) != HAL_OK)
            {
              /* Call Directly husart->hdmarx->XferAbortCallback function in case of error */
              husart->hdmarx->XferAbortCallback(husart->hdmarx);
            }
          }
          else
          {
            /* Call user error callback */
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
            /* Call registered Error Callback */
            husart->ErrorCallback(husart);
#else
            /* Call legacy weak Error Callback */
            HAL_USART_ErrorCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
          }
        }
        else
        {
          /* Call user error callback */
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
          /* Call registered Error Callback */
          husart->ErrorCallback(husart);
#else
          /* Call legacy weak Error Callback */
          HAL_USART_ErrorCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
        }
      }
      else
      {
        /* Non Blocking error : transfer could go on.
           Error is notified to user through user error callback */
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
        /* Call registered Error Callback */
        husart->ErrorCallback(husart);
#else
        /* Call legacy weak Error Callback */
        HAL_USART_ErrorCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */

        husart->ErrorCode = HAL_USART_ERROR_NONE;
      }
    }
    return;
  } /* End if some error occurs */
  
  /* Idle frame detect */
  if (((isrflags & USART_SR_IDLE) != RESET) && ((cr1its & USART_CR1_IDLEIE) != RESET))
  {
    __HAL_USART_CLEAR_IDLEFLAG(husart);
  }

  /* USART in mode Transmitter ------------------------------------------------*/
  if (((isrflags & USART_SR_TXE) != RESET) && (((cr1its & USART_CR1_TXEIE) != RESET) || ((cr3its & USART_CR3_TXFTIE) != RESET)))
  {
    husart->TxISR(husart);
    return;
  }

  /* USART in mode Transmitter end --------------------------------------------*/
  if (((isrflags & USART_SR_TC) != RESET) && ((cr1its & USART_CR1_TCIE) != RESET))
  {
    USART_EndTransmit_IT(husart);
    return;
  }
  
  /* USART TX Fifo Empty occurred ----------------------------------------------*/
  if (((isrflags & USART_SR_TXFE) != 0U) && ((cr3its & USART_CR3_TXFEIE) != RESET))
  {
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
    /* Call registered Tx Fifo Empty Callback */
    husart->TxFifoEmptyCallback(husart);
#else
    /* Call legacy weak Tx Fifo Empty Callback */
    HAL_USARTEx_TxFifoEmptyCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
    return;
  }

  /* USART RX Fifo Full occurred ----------------------------------------------*/
  if (((isrflags & USART_SR_RXFF) != 0U) && ((cr3its & USART_CR3_RXFFIE) != RESET))
  {
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
    /* Call registered Rx Fifo Full Callback */
    husart->RxFifoFullCallback(husart);
#else
    /* Call legacy weak Rx Fifo Full Callback */
    HAL_USARTEx_RxFifoFullCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
    return;
  }
}

/**
  * @brief Tx Transfer completed callback.
  * @param husart USART handle.
  * @retval None
  */
__weak void HAL_USART_TxCpltCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USART_TxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx Half Block Transfer completed callback.
  * @param husart USART handle.
  * @retval None
  */
__weak void HAL_USART_TxHalfBlockCpltCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_USART_TxHalfBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx Block Transfer completed callback.
  * @param husart USART handle.
  * @retval None
  */
__weak void HAL_USART_TxBlockCpltCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_USART_TxBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx source Transfer completed callback.
  * @param husart USART handle.
  * @retval None
  */
__weak void HAL_USART_TxSrcCpltCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_USART_TxSrcCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Transfer completed callback.
  * @param husart USART handle.
  * @retval None
  */
__weak void HAL_USART_RxCpltCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_USART_RxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief Rx Block Transfer completed callback.
  * @param husart USART handle.
  * @retval None
  */
__weak void HAL_USART_RxBlockCpltCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USART_RxBlockCpltCallback can be implemented in the user file
   */
}

/**
  * @brief Rx Half Block Transfer completed callback.
  * @param husart USART handle.
  * @retval None
  */
__weak void HAL_USART_RxHalfBlockCpltCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USART_RxHalfBlockCpltCallback can be implemented in the user file
   */
}

/**
  * @brief Rx Destination Transfer completed callback.
  * @param husart USART handle.
  * @retval None
  */
__weak void HAL_USART_RxDstCpltCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USART_RxDstCpltCallback can be implemented in the user file
   */
}

/**
  * @brief Tx/Rx Transfers completed callback for the non-blocking process.
  * @param husart USART handle.
  * @retval None
  */
__weak void HAL_USART_TxRxCpltCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USART_TxRxCpltCallback can be implemented in the user file
   */
}

/**
  * @brief USART error callback.
  * @param husart USART handle.
  * @retval None
  */
__weak void HAL_USART_ErrorCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USART_ErrorCallback can be implemented in the user file.
   */
}

/**
  * @brief  USART Abort Complete callback.
  * @param  husart USART handle.
  * @retval None
  */
__weak void HAL_USART_AbortCpltCallback(USART_HandleTypeDef *husart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(husart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_USART_AbortCpltCallback can be implemented in the user file.
   */
}

/** @defgroup USART_Exported_Functions_Group4 Peripheral State and Errors functions
  *  @brief   USART State and Errors functions
  *
@verbatim
  ==============================================================================
                 ##### Peripheral State and Errors functions #####
  ==============================================================================
 [..]
   This subsection provides a set of functions allowing to return the State of
   USART communication process, return Peripheral Errors occurred during communication
   process
   (+) HAL_USART_GetState() API can be helpful to check in run-time the state of the USART peripheral.
   (+) HAL_USART_GetError() check in run-time errors that could be occurred during communication.

@endverbatim
  * @{
  */

/**
  * @brief Return the USART handle state.
  * @param husart pointer to a USART_HandleTypeDef structure that contains
  *              the configuration information for the specified USART.
  * @retval USART handle state
  */
HAL_USART_StateTypeDef HAL_USART_GetState(USART_HandleTypeDef *husart)
{
  return husart->State;
}

/**
  * @brief Return the USART error code.
  * @param husart pointer to a USART_HandleTypeDef structure that contains
  *              the configuration information for the specified USART.
  * @retval USART handle Error Code
  */
uint32_t HAL_USART_GetError(USART_HandleTypeDef *husart)
{
  return husart->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup USART_Private_Functions USART Private Functions
  * @{
  */

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
/**
  * @brief  Initialize the callbacks to their default values.
  * @param  husart USART handle.
  * @retval none
  */
void USART_InitCallbacksToDefault(USART_HandleTypeDef *husart)
{
  /* Init the USART Callback settings */
  husart->TxSrcCpltCallback         = HAL_USART_TxSrcCpltCallback;         /* Legacy weak TxSrcCpltCallback         */
  husart->TxBlockCpltCallback       = HAL_USART_TxBlockCpltCallback;       /* Legacy weak TxBlockCpltCallback       */
  husart->TxHalfBlockCpltCallback   = HAL_USART_TxHalfBlockCpltCallback;   /* Legacy weak TxHalfBlockCpltCallback   */
  husart->TxCpltCallback            = HAL_USART_TxCpltCallback;            /* Legacy weak TxCpltCallback            */
  husart->RxDstCpltCallback         = HAL_USART_RxDstCpltCallback;         /* Legacy weak RxDstCpltCallback         */
  husart->RxBlockCpltCallback       = HAL_USART_RxBlockCpltCallback;       /* Legacy weak RxBlockCpltCallback       */
  husart->RxHalfBlockCpltCallback   = HAL_USART_RxHalfBlockCpltCallback;   /* Legacy weak RxHalfBlockCpltCallback   */
  husart->RxCpltCallback            = HAL_USART_RxCpltCallback;            /* Legacy weak RxCpltCallback            */
  husart->TxRxCpltCallback          = HAL_USART_TxRxCpltCallback;          /* Legacy weak TxRxCpltCallback          */
  husart->ErrorCallback             = HAL_USART_ErrorCallback;             /* Legacy weak ErrorCallback             */
  husart->AbortCpltCallback         = HAL_USART_AbortCpltCallback;         /* Legacy weak AbortCpltCallback         */
  husart->RxFifoFullCallback        = HAL_USARTEx_RxFifoFullCallback;      /* Legacy weak RxFifoFullCallback        */
  husart->TxFifoEmptyCallback       = HAL_USARTEx_TxFifoEmptyCallback;     /* Legacy weak TxFifoEmptyCallback       */
}
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */

/**
  * @brief  End ongoing transfer on USART peripheral (following error detection or Transfer completion).
  * @param  husart USART handle.
  * @retval None
  */
static void USART_EndTransfer(USART_HandleTypeDef *husart)
{
  /* Disable TXEIE, TCIE, RXNE, RXFT, TXFT, PE and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(husart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE   | USART_CR1_TXEIE | USART_CR1_TCIE));
  CLEAR_BIT(husart->Instance->CR3, (USART_CR3_EIE    | USART_CR3_RXFTIE | USART_CR3_TXFTIE));

  /* At end of process, restore husart->State to Ready */
  husart->State = HAL_USART_STATE_READY;
}

/**
  * @brief DMA USART transmit process complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMATransmitCplt(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);

  /* DMA Normal mode */
  if (HAL_IS_BIT_CLR(hdma->Init.Mode, DMA_CIRCULAR))
  {
    husart->TxXferCount = 0U;

    if (husart->State == HAL_USART_STATE_BUSY_TX)
    {
      /* Disable the DMA transfer for transmit request by resetting the DMAT bit
         in the USART CR3 register */
      CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAT);

      /* Enable the USART Transmit Complete Interrupt */
      SET_BIT(husart->Instance->CR1, USART_CR1_TCIE);
    }
  }
  /* DMA Circular mode */
  else
  {
    if (husart->State == HAL_USART_STATE_BUSY_TX)
    {
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
      /* Call registered Tx Complete Callback */
      husart->TxCpltCallback(husart);
#else
      /* Call legacy weak Tx Complete Callback */
      HAL_USART_TxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
    }
  }
}

/**
  * @brief DMA USART transmit process half Block complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMATxHalfBlockCplt(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  /* Call registered Tx Half Block Complete Callback */
  husart->TxHalfBlockCpltCallback(husart);
#else
  /* Call legacy weak Tx Half Block Complete Callback */
  HAL_USART_TxHalfBlockCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA USART transmit process Block complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMATxBlockCplt(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  /* Call registered Tx Block Complete Callback */
  husart->TxBlockCpltCallback(husart);
#else
  /* Call legacy weak Tx Block Complete Callback */
  HAL_USART_TxBlockCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA USART transmit process Source complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMATxSrcTransmitCplt(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  /* Call registered Tx Source Complete Callback */
  husart->TxSrcCpltCallback(husart);
#else
  /* Call legacy weak Tx Source Complete Callback */
  HAL_USART_TxSrcCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA USART receive process complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMAReceiveCplt(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);

  /* DMA Normal mode */
  if (HAL_IS_BIT_CLR(hdma->Init.Mode, DMA_CIRCULAR))
  {
    husart->RxXferCount = 0U;

    /* Disable PE and ERR (Frame error, noise error, overrun error) interrupts */
    CLEAR_BIT(husart->Instance->CR1, USART_CR1_PEIE);
    CLEAR_BIT(husart->Instance->CR3, USART_CR3_EIE);

    /* Disable the DMA RX transfer for the receiver request by resetting the DMAR bit
       in USART CR3 register */
    CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAR);
    /* similarly, disable the DMA TX transfer that was started to provide the clock to the slave device */
    CLEAR_BIT(husart->Instance->CR3, USART_CR3_DMAT);

    husart->State = HAL_USART_STATE_READY;

    if (husart->State == HAL_USART_STATE_BUSY_RX)
    {
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
      /* Call registered Rx Complete Callback */
      husart->RxCpltCallback(husart);
#else
      /* Call legacy weak Rx Complete Callback */
      HAL_USART_RxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
    }
    /* The USART state is HAL_USART_STATE_BUSY_TX_RX */
    else
    {
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
      /* Call registered Tx Rx Complete Callback */
      husart->TxRxCpltCallback(husart);
#else
      /* Call legacy weak Tx Rx Complete Callback */
      HAL_USART_TxRxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
    }
    husart->State = HAL_USART_STATE_READY;
  }
  /* DMA circular mode */
  else
  {
    if (husart->State == HAL_USART_STATE_BUSY_RX)
    {
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
      /* Call registered Rx Complete Callback */
      husart->RxCpltCallback(husart);
#else
      /* Call legacy weak Rx Complete Callback */
      HAL_USART_RxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
    }
    /* The USART state is HAL_USART_STATE_BUSY_TX_RX */
    else
    {
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
      /* Call registered Tx Rx Complete Callback */
      husart->TxRxCpltCallback(husart);
#else
      /* Call legacy weak Tx Rx Complete Callback */
      HAL_USART_TxRxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
    }
  }
}

/**
  * @brief DMA USART receive process block complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMARxBlockCplt(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  /* Call registered Rx Half Complete Callback */
  husart->RxBlockCpltCallback(husart);
#else
  /* Call legacy weak Rx Half Complete Callback */
  HAL_USART_RxBlockCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA USART receive process half block complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMARxHalfBlockCplt(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  /* Call registered Rx Half Block Complete Callback */
  husart->RxHalfBlockCpltCallback(husart);
#else
  /* Call legacy weak Rx Half Block Complete Callback */
  HAL_USART_RxHalfBlockCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA USART receive process Destination complete callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMARxDstReceiveCplt(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  /* Call registered Rx Destination Complete Callback */
  husart->RxDstCpltCallback(husart);
#else
  /* Call legacy weak Rx Destination Complete Callback */
  HAL_USART_RxDstCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA USART communication error callback.
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMAError(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);

  husart->RxXferCount = 0U;
  husart->TxXferCount = 0U;
  USART_EndTransfer(husart);

  husart->ErrorCode |= HAL_USART_ERROR_DMA;
  husart->State = HAL_USART_STATE_READY;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  /* Call registered Error Callback */
  husart->ErrorCallback(husart);
#else
  /* Call legacy weak Error Callback */
  HAL_USART_ErrorCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA USART communication abort callback, when initiated by HAL services on Error
  *         (To be called at end of DMA Abort procedure following error occurrence).
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMAAbortOnError(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);
  husart->RxXferCount = 0U;
  husart->TxXferCount = 0U;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  /* Call registered Error Callback */
  husart->ErrorCallback(husart);
#else
  /* Call legacy weak Error Callback */
  HAL_USART_ErrorCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA USART Tx communication abort callback, when initiated by user
  *         (To be called at end of DMA Tx Abort procedure following user abort request).
  * @note   When this callback is executed, User Abort complete call back is called only if no
  *         Abort still ongoing for Rx DMA Handle.
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMATxAbortCallback(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);

  husart->hdmatx->XferAbortCallback = NULL;

  /* Check if an Abort process is still ongoing */
  if (husart->hdmarx != NULL)
  {
    if (husart->hdmarx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA channels are aborted, call user Abort Complete callback */
  husart->TxXferCount = 0U;
  husart->RxXferCount = 0U;

  /* Reset errorCode */
  husart->ErrorCode = HAL_USART_ERROR_NONE;

  /* Clear the Error flags */
  __HAL_USART_CLEAR_FEFLAG(husart);

  /* Restore husart->State to Ready */
  husart->State = HAL_USART_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Complete Callback */
  husart->AbortCpltCallback(husart);
#else
  /* Call legacy weak Abort Complete Callback */
  HAL_USART_AbortCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA USART Rx communication abort callback, when initiated by user
  *         (To be called at end of DMA Rx Abort procedure following user abort request).
  * @note   When this callback is executed, User Abort complete call back is called only if no
  *         Abort still ongoing for Tx DMA Handle.
  * @param  hdma DMA handle.
  * @retval None
  */
static void USART_DMARxAbortCallback(DMA_HandleTypeDef *hdma)
{
  USART_HandleTypeDef *husart = (USART_HandleTypeDef *)(hdma->Parent);

  husart->hdmarx->XferAbortCallback = NULL;

  /* Check if an Abort process is still ongoing */
  if (husart->hdmatx != NULL)
  {
    if (husart->hdmatx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA channels are aborted, call user Abort Complete callback */
  husart->TxXferCount = 0U;
  husart->RxXferCount = 0U;

  /* Reset errorCode */
  husart->ErrorCode = HAL_USART_ERROR_NONE;

  /* Clear the Error flags */
  __HAL_USART_CLEAR_FEFLAG(husart);

  /* Restore husart->State to Ready */
  husart->State  = HAL_USART_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Complete Callback */
  husart->AbortCpltCallback(husart);
#else
  /* Call legacy weak Abort Complete Callback */
  HAL_USART_AbortCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
}

/**
  * @brief  Handle USART Communication Timeout. It waits
  *         until a flag is no longer in the specified status.
  * @param  husart USART handle.
  * @param  Flag Specifies the USART flag to check.
  * @param  Status the actual Flag status (SET or RESET).
  * @param  Tickstart Tick start value
  * @param  Timeout timeout duration.
  * @retval HAL status
  */
static HAL_StatusTypeDef USART_WaitOnFlagUntilTimeout(USART_HandleTypeDef *husart, uint32_t Flag, FlagStatus Status,
                                                      uint32_t Tickstart, uint32_t Timeout)
{
  /* Wait until flag is set */
  while ((__HAL_USART_GET_FLAG(husart, Flag) ? SET : RESET) == Status)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - Tickstart) > Timeout) || (Timeout == 0U))
      {
        /* Disable TXE, RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts for the interrupt process */
        CLEAR_BIT(husart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE | USART_CR1_TXEIE));
        CLEAR_BIT(husart->Instance->CR3, USART_CR3_EIE);

        husart->State  = HAL_USART_STATE_READY;

        /* Process Unlocked */
        __HAL_UNLOCK(husart);

        return HAL_TIMEOUT;
      }
    }
  }
  return HAL_OK;
}

/**
  * @brief  Configures the USART peripheral.
  * @param  husart  Pointer to a USART_HandleTypeDef structure that contains
  *                the configuration information for the specified USART module.
  * @retval None
  */
static void USART_SetConfig(USART_HandleTypeDef *husart)
{
  uint32_t tmpreg;
  uint64_t clockfreq;

  /* Check the parameters */
  assert_param(IS_USART_POLARITY(husart->Init.CLKPolarity));
  assert_param(IS_USART_PHASE(husart->Init.CLKPhase));
  assert_param(IS_USART_LASTBIT(husart->Init.CLKLastBit));
  assert_param(IS_USART_BAUDRATE(husart->Init.BaudRate));
  assert_param(IS_USART_WORD_LENGTH(husart->Init.WordLength));
  assert_param(IS_USART_STOPBITS(husart->Init.StopBits));
  assert_param(IS_USART_PARITY(husart->Init.Parity));
  assert_param(IS_USART_MODE(husart->Init.Mode));

  /*-------------------------- USART CR1 Configuration -----------------------*/
  /* Configure the USART Word Length, Parity and mode:
     Set the M bits according to husart->Init.WordLength value
     Set PCE and PS bits according to husart->Init.Parity value
     Set TE and RE bits according to husart->Init.Mode value */
  
  tmpreg = (uint32_t)husart->Init.WordLength | husart->Init.Parity | husart->Init.Mode;
  MODIFY_REG(husart->Instance->CR1,USART_CR1_FIELDS,tmpreg);

  /*---------------------------- USART CR2 Configuration ---------------------*/
  /* Clear and configure the USART Clock, CPOL, CPHA, LBCL STOP and SLVEN bits:
   * set CPOL bit according to husart->Init.CLKPolarity value
   * set CPHA bit according to husart->Init.CLKPhase value
   * set LBCL bit according to husart->Init.CLKLastBit value (used in SPI master mode only)
   * set STOP[13:12] bits according to husart->Init.StopBits value */
  tmpreg = (uint32_t)(USART_CLOCK_ENABLE);
  tmpreg |= (uint32_t)husart->Init.CLKLastBit;
  tmpreg |= ((uint32_t)husart->Init.CLKPolarity | (uint32_t)husart->Init.CLKPhase);
  tmpreg |= (uint32_t)husart->Init.StopBits;
  MODIFY_REG(husart->Instance->CR2, USART_CR2_FIELDS, tmpreg);

  /*-------------------------- USART CR3 Configuration -----------------------*/
  /* Clear CTSE and RTSE bits */
  CLEAR_BIT(husart->Instance->CR3, (USART_CR3_RTSE | USART_CR3_CTSE));

  /*-------------------------- USART BRR Configuration ---------------------*/
  if(husart->Instance == USART1)
  {
    clockfreq = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_USART1);
  }
  else if(husart->Instance == USART2)
  {
    clockfreq = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_USART2);
  }
  else if(husart->Instance == USART3)
  {
    clockfreq = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_USART3);
  }
  else
  {
  }
  husart->Instance->BRR = USART_BRR_SAMPLING16(clockfreq, husart->Init.BaudRate);

  /* Initialize the number of data to process during RX/TX SR execution */
  husart->NbTxDataToProcess = 1U;
  husart->NbRxDataToProcess = 1U;

  /* Clear SR function pointers */
  husart->RxISR   = NULL;
  husart->TxISR   = NULL;
}

/**
  * @brief  Simplex send an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_USART_Transmit_IT().
  * @note   The USART errors are not managed to avoid the overrun error.
  * @note   ISR function executed when FIFO mode is disabled and when the
  *         data word length is less than 9 bits long.
  * @param  husart USART handle.
  * @retval None
  */
static void USART_TxSR_8BIT(USART_HandleTypeDef *husart)
{
  const HAL_USART_StateTypeDef state = husart->State;

  /* Check that a Tx process is ongoing */
  if ((state == HAL_USART_STATE_BUSY_TX) ||
      (state == HAL_USART_STATE_BUSY_TX_RX))
  {
    if (husart->TxXferCount == 0U)
    {
      /* Disable the USART Transmit data register empty interrupt */
      __HAL_USART_DISABLE_IT(husart, USART_IT_TXE);

      /* Enable the USART Transmit Complete Interrupt */
      __HAL_USART_ENABLE_IT(husart, USART_IT_TC);
    }
    else
    {
      /* To prevent the TC flag bit from being affected by other operations during
         data transmission, read the SR register in conjunction with write the DR 
         Register to clear the TC flag bit.
         */
      (void)(husart->Instance->SR);
      husart->Instance->DR = (uint8_t)(*husart->pTxBuffPtr & (uint8_t)0xFF);
      husart->pTxBuffPtr++;
      husart->TxXferCount--;
    }
  }
}

/**
  * @brief  Simplex send an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_USART_Transmit_IT().
  * @note   The USART errors are not managed to avoid the overrun error.
  * @note   ISR function executed when FIFO mode is disabled and when the
  *         data word length is 9 bits long.
  * @param  husart USART handle.
  * @retval None
  */
static void USART_TxSR_16BIT(USART_HandleTypeDef *husart)
{
  const HAL_USART_StateTypeDef state = husart->State;
  uint16_t *tmp;

  if ((state == HAL_USART_STATE_BUSY_TX) ||
      (state == HAL_USART_STATE_BUSY_TX_RX))
  {
    if (husart->TxXferCount == 0U)
    {
      /* Disable the USART Transmit data register empty interrupt */
      __HAL_USART_DISABLE_IT(husart, USART_IT_TXE);

      /* Enable the USART Transmit Complete Interrupt */
      __HAL_USART_ENABLE_IT(husart, USART_IT_TC);
    }
    else
    {
      tmp = (uint16_t *) husart->pTxBuffPtr;
      /* To prevent the TC flag bit from being affected by other operations during
         data transmission, read the SR register in conjunction with write the DR 
         Register to clear the TC flag bit.
         */
      (void)(husart->Instance->SR);
      husart->Instance->DR = (uint16_t)(*tmp & 0x01FFU);
      husart->pTxBuffPtr += 2U;
      husart->TxXferCount--;
    }
  }
}

/**
  * @brief  Simplex send an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_USART_Transmit_IT().
  * @note   The USART errors are not managed to avoid the overrun error.
  * @note   ISR function executed when FIFO mode is enabled and when the
  *         data word length is less than 9 bits long.
  * @param  husart USART handle.
  * @retval None
  */
static void USART_TxSR_8BIT_FIFOEN(USART_HandleTypeDef *husart)
{
  const HAL_USART_StateTypeDef state = husart->State;
  uint32_t  nb_tx_data;

  /* Check that a Tx process is ongoing */
  if ((state == HAL_USART_STATE_BUSY_TX) ||
      (state == HAL_USART_STATE_BUSY_TX_RX))
  {
    for (nb_tx_data = husart->NbTxDataToProcess ; nb_tx_data > 0U ; nb_tx_data--)
    {
      if (husart->TxXferCount == 0U)
      {
        /* Disable the TX FIFO threshold interrupt */
        __HAL_USART_DISABLE_IT(husart, USART_IT_TXFT);

        /* Enable the USART Transmit Complete Interrupt */
        __HAL_USART_ENABLE_IT(husart, USART_IT_TC);

        break; /* force exit loop */
      }
      else if (__HAL_USART_GET_FLAG(husart, USART_FLAG_TXE) == SET)
      {
        /* To prevent the TC flag bit from being affected by other operations during
           data transmission, read the SR register in conjunction with write the DR 
           Register to clear the TC flag bit.
           */
        (void)(husart->Instance->SR);
        husart->Instance->DR = (uint8_t)(*husart->pTxBuffPtr & (uint8_t)0xFF);
        husart->pTxBuffPtr++;
        husart->TxXferCount--;
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
  *         interruptions have been enabled by HAL_USART_Transmit_IT().
  * @note   The USART errors are not managed to avoid the overrun error.
  * @note   ISR function executed when FIFO mode is enabled and when the
  *         data word length is 9 bits long.
  * @param  husart USART handle.
  * @retval None
  */
static void USART_TxSR_16BIT_FIFOEN(USART_HandleTypeDef *husart)
{
  const HAL_USART_StateTypeDef state = husart->State;
  uint16_t *tmp;
  uint32_t  nb_tx_data;

  /* Check that a Tx process is ongoing */
  if ((state == HAL_USART_STATE_BUSY_TX) ||
      (state == HAL_USART_STATE_BUSY_TX_RX))
  {
    for (nb_tx_data = husart->NbTxDataToProcess ; nb_tx_data > 0U ; nb_tx_data--)
    {
      if (husart->TxXferCount == 0U)
      {
        /* Disable the TX FIFO threshold interrupt */
        __HAL_USART_DISABLE_IT(husart, USART_IT_TXFT);

        /* Enable the USART Transmit Complete Interrupt */
        __HAL_USART_ENABLE_IT(husart, USART_IT_TC);

        break; /* force exit loop */
      }
      else if (__HAL_USART_GET_FLAG(husart, USART_FLAG_TXE) == SET)
      {
        tmp = (uint16_t *) husart->pTxBuffPtr;
        /* To prevent the TC flag bit from being affected by other operations during
           data transmission, read the SR register in conjunction with write the DR 
           Register to clear the TC flag bit.
           */
        (void)(husart->Instance->SR);
        husart->Instance->DR = (uint16_t)(*tmp & 0x01FFU);
        husart->pTxBuffPtr += 2U;
        husart->TxXferCount--;
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
  * @param  husart Pointer to a USART_HandleTypeDef structure that contains
  *                the configuration information for the specified USART module.
  * @retval None
  */
static void USART_EndTransmit_IT(USART_HandleTypeDef *husart)
{
  /* Disable the USART Transmit Complete Interrupt */
  __HAL_USART_DISABLE_IT(husart, USART_IT_TC);

  /* Disable the USART Error Interrupt: (Frame error, noise error, overrun error) */
  __HAL_USART_DISABLE_IT(husart, USART_IT_ERR);

  /* Clear TxISR function pointer */
  husart->TxISR = NULL;

  if (husart->State == HAL_USART_STATE_BUSY_TX)
  {
    /* Clear overrun flag and discard the received data */
    __HAL_USART_CLEAR_OREFLAG(husart);
    __HAL_USART_SEND_REQ(husart, USART_RXDATA_FLUSH_REQUEST);

    /* Tx process is completed, restore husart->State to Ready */
    husart->State = HAL_USART_STATE_READY;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
    /* Call registered Tx Complete Callback */
    husart->TxCpltCallback(husart);
#else
    /* Call legacy weak Tx Complete Callback */
    HAL_USART_TxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
  }
  else if (husart->RxXferCount == 0U)
  {
    /* TxRx process is completed, restore husart->State to Ready */
    husart->State = HAL_USART_STATE_READY;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
    /* Call registered Tx Rx Complete Callback */
    husart->TxRxCpltCallback(husart);
#else
    /* Call legacy weak Tx Rx Complete Callback */
    HAL_USART_TxRxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
  }
  else
  {
    /* Nothing to do */
  }
}

/**
  * @brief  Simplex receive an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_USART_Receive_IT().
  * @note   ISR function executed when FIFO mode is disabled and when the
  *         data word length is less than 9 bits long.
  * @param  husart USART handle
  * @retval None
  */
static void USART_RxSR_8BIT(USART_HandleTypeDef *husart)
{
  const HAL_USART_StateTypeDef state = husart->State;
  uint32_t txdatacount;
  uint16_t uhMask = husart->Mask;
  uint32_t txftie;

  if ((state == HAL_USART_STATE_BUSY_RX) ||
      (state == HAL_USART_STATE_BUSY_TX_RX))
  {
    *husart->pRxBuffPtr = (uint8_t)(husart->Instance->DR & (uint8_t)uhMask);
    husart->pRxBuffPtr++;
    husart->RxXferCount--;

    if (husart->RxXferCount == 0U)
    {
      /* Disable the USART Parity Error Interrupt and RXNE interrupt*/
      CLEAR_BIT(husart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));

      /* Disable the USART Error Interrupt: (Frame error, noise error, overrun error) */
      CLEAR_BIT(husart->Instance->CR3, USART_CR3_EIE);

      /* Clear RxISR function pointer */
      husart->RxISR = NULL;

      /* txftie and txdatacount are temporary variables for MISRAC2012-Rule-13.5 */
      txftie = READ_BIT(husart->Instance->CR3, USART_CR3_TXFTIE);
      txdatacount = husart->TxXferCount;

      if (state == HAL_USART_STATE_BUSY_RX)
      {
#if defined(USART_SLAVEMODE_ENABLE)
        /* Clear SPI slave underrun flag and discard transmit data */
        if (husart->SlaveMode == USART_SLAVEMODE_ENABLE)
        {
          __HAL_USART_CLEAR_UDRFLAG(husart);
          __HAL_USART_SEND_REQ(husart, USART_TXDATA_FLUSH_REQUEST);
        }
#endif
        /* Rx process is completed, restore husart->State to Ready */
        husart->State = HAL_USART_STATE_READY;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
        /* Call registered Rx Complete Callback */
        husart->RxCpltCallback(husart);
#else
        /* Call legacy weak Rx Complete Callback */
        HAL_USART_RxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
      }
      else if ((READ_BIT(husart->Instance->CR1, USART_CR1_TCIE) != USART_CR1_TCIE) &&
               (txftie != USART_CR3_TXFTIE) &&
               (txdatacount == 0U))
      {
        /* TxRx process is completed, restore husart->State to Ready */
        husart->State = HAL_USART_STATE_READY;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
        /* Call registered Tx Rx Complete Callback */
        husart->TxRxCpltCallback(husart);
#else
        /* Call legacy weak Tx Rx Complete Callback */
        HAL_USART_TxRxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
      }
      else
      {
        /* Nothing to do */
      }
    }
#if defined(USART_SLAVEMODE_ENABLE)
    else if ((state == HAL_USART_STATE_BUSY_RX) &&
             (husart->SlaveMode == USART_SLAVEMODE_DISABLE))
    {
      /* Send dummy byte in order to generate the clock for the Slave to Send the next data */
      husart->Instance->DR = (USART_DUMMY_DATA & (uint16_t)0x00FF);
    }
#endif
    else
    {
      /* Nothing to do */
    }
  }
}

/**
  * @brief  Simplex receive an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_USART_Receive_IT().
  * @note   ISR function executed when FIFO mode is disabled and when the
  *         data word length is 9 bits long.
  * @param  husart USART handle
  * @retval None
  */
static void USART_RxSR_16BIT(USART_HandleTypeDef *husart)
{
  const HAL_USART_StateTypeDef state = husart->State;
  uint32_t txdatacount;
  uint16_t *tmp;
  uint16_t uhMask = husart->Mask;
  uint32_t txftie;

  if ((state == HAL_USART_STATE_BUSY_RX) ||
      (state == HAL_USART_STATE_BUSY_TX_RX))
  {
    tmp = (uint16_t *) husart->pRxBuffPtr;
    *tmp = (uint16_t)(husart->Instance->DR & uhMask);
    husart->pRxBuffPtr += 2U;
    husart->RxXferCount--;

    if (husart->RxXferCount == 0U)
    {
      /* Disable the USART Parity Error Interrupt and RXNE interrupt*/
      CLEAR_BIT(husart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));

      /* Disable the USART Error Interrupt: (Frame error, noise error, overrun error) */
      CLEAR_BIT(husart->Instance->CR3, USART_CR3_EIE);

      /* Clear RxISR function pointer */
      husart->RxISR = NULL;

      /* txftie and txdatacount are temporary variables for MISRAC2012-Rule-13.5 */
      txftie = READ_BIT(husart->Instance->CR3, USART_CR3_TXFTIE);
      txdatacount = husart->TxXferCount;

      if (state == HAL_USART_STATE_BUSY_RX)
      {
        /* Rx process is completed, restore husart->State to Ready */
        husart->State = HAL_USART_STATE_READY;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
        /* Call registered Rx Complete Callback */
        husart->RxCpltCallback(husart);
#else
        /* Call legacy weak Rx Complete Callback */
        HAL_USART_RxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
      }
      else if ((READ_BIT(husart->Instance->CR1, USART_CR1_TCIE) != USART_CR1_TCIE) &&
               (txftie != USART_CR3_TXFTIE) &&
               (txdatacount == 0U))
      {
        /* TxRx process is completed, restore husart->State to Ready */
        husart->State = HAL_USART_STATE_READY;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
        /* Call registered Tx Rx Complete Callback */
        husart->TxRxCpltCallback(husart);
#else
        /* Call legacy weak Tx Rx Complete Callback */
        HAL_USART_TxRxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
      }
      else
      {
        /* Nothing to do */
      }
    }
    else if (state == HAL_USART_STATE_BUSY_RX)
    {
      /* Send dummy byte in order to generate the clock for the Slave to Send the next data */
      husart->Instance->DR = (USART_DUMMY_DATA & (uint16_t)0x00FF);
    }
    else
    {
      /* Nothing to do */
    }
  }
}

/**
  * @brief  Simplex receive an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_USART_Receive_IT().
  * @note   ISR function executed when FIFO mode is enabled and when the
  *         data word length is less than 9 bits long.
  * @param  husart USART handle
  * @retval None
  */
static void USART_RxSR_8BIT_FIFOEN(USART_HandleTypeDef *husart)
{
  HAL_USART_StateTypeDef state = husart->State;
  uint32_t txdatacount;
  uint32_t rxdatacount;
  uint16_t uhMask = husart->Mask;
  uint32_t nb_rx_data;
  uint32_t txftie;

  /* Check that a Rx process is ongoing */
  if ((state == HAL_USART_STATE_BUSY_RX) ||
      (state == HAL_USART_STATE_BUSY_TX_RX))
  {
    for (nb_rx_data = husart->NbRxDataToProcess ; nb_rx_data > 0U ; nb_rx_data--)
    {
      if (__HAL_USART_GET_FLAG(husart, USART_FLAG_RXNE) == SET)
      {
        *husart->pRxBuffPtr = (uint8_t)(husart->Instance->DR & (uint8_t)(uhMask & 0xFFU));
        husart->pRxBuffPtr++;
        husart->RxXferCount--;

        if (husart->RxXferCount == 0U)
        {
          /* Disable the USART Parity Error Interrupt */
          CLEAR_BIT(husart->Instance->CR1, USART_CR1_PEIE);

          /* Disable the USART Error Interrupt: (Frame error, noise error, overrun error)
             and RX FIFO Threshold interrupt */
          CLEAR_BIT(husart->Instance->CR3, (USART_CR3_EIE | USART_CR3_RXFTIE));

          /* Clear RxISR function pointer */
          husart->RxISR = NULL;

          /* txftie and txdatacount are temporary variables for MISRAC2012-Rule-13.5 */
          txftie = READ_BIT(husart->Instance->CR3, USART_CR3_TXFTIE);
          txdatacount = husart->TxXferCount;

          if (state == HAL_USART_STATE_BUSY_RX)
          {
            /* Rx process is completed, restore husart->State to Ready */
            husart->State = HAL_USART_STATE_READY;
            state = HAL_USART_STATE_READY;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
            /* Call registered Rx Complete Callback */
            husart->RxCpltCallback(husart);
#else
            /* Call legacy weak Rx Complete Callback */
            HAL_USART_RxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
          }
          else if ((READ_BIT(husart->Instance->CR1, USART_CR1_TCIE) != USART_CR1_TCIE) &&
                   (txftie != USART_CR3_TXFTIE) &&
                   (txdatacount == 0U))
          {
            /* TxRx process is completed, restore husart->State to Ready */
            husart->State = HAL_USART_STATE_READY;
            state = HAL_USART_STATE_READY;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
            /* Call registered Tx Rx Complete Callback */
            husart->TxRxCpltCallback(husart);
#else
            /* Call legacy weak Tx Rx Complete Callback */
            HAL_USART_TxRxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
          }
          else
          {
            /* Nothing to do */
          }
        }
        else if (state == HAL_USART_STATE_BUSY_RX)
        {
          /* Send dummy byte in order to generate the clock for the Slave to Send the next data */
          husart->Instance->DR = (USART_DUMMY_DATA & (uint16_t)0x00FF);
        }
        else
        {
          /* Nothing to do */
        }
      }
    }

    /* When remaining number of bytes to receive is less than the RX FIFO
    threshold, next incoming frames are processed as if FIFO mode was
    disabled (i.e. one interrupt per received frame).
    */
    rxdatacount = husart->RxXferCount;
    if (((rxdatacount != 0U)) && (rxdatacount < husart->NbRxDataToProcess))
    {
      /* Disable the USART RXFT interrupt*/
      CLEAR_BIT(husart->Instance->CR3, USART_CR3_RXFTIE);

      /* Update the RxISR function pointer */
      husart->RxISR = USART_RxSR_8BIT;

      /* Enable the USART Data Register Not Empty interrupt */
      SET_BIT(husart->Instance->CR1, USART_CR1_RXNEIE);

      if ((husart->TxXferCount == 0U) &&
          (state == HAL_USART_STATE_BUSY_TX_RX))
      {
        /* Send dummy byte in order to generate the clock for the Slave to Send the next data */
        husart->Instance->DR = (USART_DUMMY_DATA & (uint16_t)0x00FF);
      }
    }
  }
  else
  {
    /* Clear RXNE interrupt flag */
    __HAL_USART_SEND_REQ(husart, USART_RXDATA_FLUSH_REQUEST);
  }
}

/**
  * @brief  Simplex receive an amount of data in non-blocking mode.
  * @note   Function called under interruption only, once
  *         interruptions have been enabled by HAL_USART_Receive_IT().
  * @note   ISR function executed when FIFO mode is enabled and when the
  *         data word length is 9 bits long.
  * @param  husart USART handle
  * @retval None
  */
static void USART_RxSR_16BIT_FIFOEN(USART_HandleTypeDef *husart)
{
  HAL_USART_StateTypeDef state = husart->State;
  uint32_t txdatacount;
  uint32_t rxdatacount;
  uint16_t *tmp;
  uint16_t uhMask = husart->Mask;
  uint32_t nb_rx_data;
  uint32_t txftie;

  /* Check that a Tx process is ongoing */
  if ((state == HAL_USART_STATE_BUSY_RX) ||
      (state == HAL_USART_STATE_BUSY_TX_RX))
  {
    for (nb_rx_data = husart->NbRxDataToProcess ; nb_rx_data > 0U ; nb_rx_data--)
    {
      if (__HAL_USART_GET_FLAG(husart, USART_FLAG_RXNE) == SET)
      {
        tmp = (uint16_t *) husart->pRxBuffPtr;
        *tmp = (uint16_t)(husart->Instance->DR & uhMask);
        husart->pRxBuffPtr += 2U;
        husart->RxXferCount--;

        if (husart->RxXferCount == 0U)
        {
          /* Disable the USART Parity Error Interrupt */
          CLEAR_BIT(husart->Instance->CR1, USART_CR1_PEIE);

          /* Disable the USART Error Interrupt: (Frame error, noise error, overrun error)
             and RX FIFO Threshold interrupt */
          CLEAR_BIT(husart->Instance->CR3, (USART_CR3_EIE | USART_CR3_RXFTIE));

          /* Clear RxISR function pointer */
          husart->RxISR = NULL;

          /* txftie and txdatacount are temporary variables for MISRAC2012-Rule-13.5 */
          txftie = READ_BIT(husart->Instance->CR3, USART_CR3_TXFTIE);
          txdatacount = husart->TxXferCount;

          if (state == HAL_USART_STATE_BUSY_RX)
          {
            /* Rx process is completed, restore husart->State to Ready */
            husart->State = HAL_USART_STATE_READY;
            state = HAL_USART_STATE_READY;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
            /* Call registered Rx Complete Callback */
            husart->RxCpltCallback(husart);
#else
            /* Call legacy weak Rx Complete Callback */
            HAL_USART_RxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
          }
          else if ((READ_BIT(husart->Instance->CR1, USART_CR1_TCIE) != USART_CR1_TCIE) &&
                   (txftie != USART_CR3_TXFTIE) &&
                   (txdatacount == 0U))
          {
            /* TxRx process is completed, restore husart->State to Ready */
            husart->State = HAL_USART_STATE_READY;
            state = HAL_USART_STATE_READY;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
            /* Call registered Tx Rx Complete Callback */
            husart->TxRxCpltCallback(husart);
#else
            /* Call legacy weak Tx Rx Complete Callback */
            HAL_USART_TxRxCpltCallback(husart);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
          }
          else
          {
            /* Nothing to do */
          }
        }
        else if (state == HAL_USART_STATE_BUSY_RX)
        {
          /* Send dummy byte in order to generate the clock for the Slave to Send the next data */
          husart->Instance->DR = (USART_DUMMY_DATA & (uint16_t)0x00FF);
        }
        else
        {
          /* Nothing to do */
        }
      }
    }

    /* When remaining number of bytes to receive is less than the RX FIFO
    threshold, next incoming frames are processed as if FIFO mode was
    disabled (i.e. one interrupt per received frame).
    */
    rxdatacount = husart->RxXferCount;
    if (((rxdatacount != 0U)) && (rxdatacount < husart->NbRxDataToProcess))
    {
      /* Disable the USART RXFT interrupt*/
      CLEAR_BIT(husart->Instance->CR3, USART_CR3_RXFTIE);

      /* Update the RxISR function pointer */
      husart->RxISR = USART_RxSR_16BIT;

      /* Enable the USART Data Register Not Empty interrupt */
      SET_BIT(husart->Instance->CR1, USART_CR1_RXNEIE);

      if ((husart->TxXferCount == 0U) &&
          (state == HAL_USART_STATE_BUSY_TX_RX))
      {
        /* Send dummy byte in order to generate the clock for the Slave to Send the next data */
        husart->Instance->DR = (USART_DUMMY_DATA & (uint16_t)0x00FF);
      }
    }
  }
  else
  {
    /* Clear RXNE interrupt flag */
    __HAL_USART_SEND_REQ(husart, USART_RXDATA_FLUSH_REQUEST);
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
/**
  * @}
  */
/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
