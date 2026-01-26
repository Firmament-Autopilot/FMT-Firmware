/**
  ******************************************************************************
  * @file    py32e407_hal_fdcan.c
  * @author  MCU Application Team
  * @brief   FDCAN HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Flexible DataRate Controller Area Network
  *          (FDCAN) peripheral:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *           + Peripheral Configuration and Control functions
  *           + Peripheral State and Error functions
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

#if defined(FDCAN1) || defined (FDCAN2)

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup FDCAN FDCAN
  * @brief FDCAN HAL module driver
  * @{
  */

#ifdef HAL_FDCAN_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup FDCAN_Private_Constants
  * @{
  */
#define FDCAN_TIMEOUT_VALUE 10U
#define FDCAN_TIMEOUT_COUNT 50U

#define FDCAN_TX_EVENT_FIFO_MASK (FDCAN_IR_TEFL | FDCAN_IR_TEFF | FDCAN_IR_TEFW | FDCAN_IR_TEFN)
#define FDCAN_RX_FIFO0_MASK (FDCAN_IR_RF0L | FDCAN_IR_RF0F | FDCAN_IR_RF0W | FDCAN_IR_RF0N)
#define FDCAN_RX_FIFO1_MASK (FDCAN_IR_RF1L | FDCAN_IR_RF1F | FDCAN_IR_RF1W | FDCAN_IR_RF1N)
#define FDCAN_ERROR_MASK (FDCAN_IR_ELO | FDCAN_IR_WDI | FDCAN_IR_PEA | FDCAN_IR_PED | FDCAN_IR_ARA)
#define FDCAN_ERROR_STATUS_MASK (FDCAN_IR_EP | FDCAN_IR_EW | FDCAN_IR_BO)

#define FDCAN_ELEMENT_MASK_STDID ((uint32_t)0x1FFC0000U) /* Standard Identifier         */
#define FDCAN_ELEMENT_MASK_EXTID ((uint32_t)0x1FFFFFFFU) /* Extended Identifier         */
#define FDCAN_ELEMENT_MASK_RTR   ((uint32_t)0x20000000U) /* Remote Transmission Request */
#define FDCAN_ELEMENT_MASK_XTD   ((uint32_t)0x40000000U) /* Extended Identifier         */
#define FDCAN_ELEMENT_MASK_ESI   ((uint32_t)0x80000000U) /* Error State Indicator       */
#define FDCAN_ELEMENT_MASK_TS    ((uint32_t)0x0000FFFFU) /* Timestamp                   */
#define FDCAN_ELEMENT_MASK_DLC   ((uint32_t)0x000F0000U) /* Data Length Code            */
#define FDCAN_ELEMENT_MASK_BRS   ((uint32_t)0x00100000U) /* Bit Rate Switch             */
#define FDCAN_ELEMENT_MASK_FDF   ((uint32_t)0x00200000U) /* FD Format                   */
#define FDCAN_ELEMENT_MASK_EFC   ((uint32_t)0x00800000U) /* Event FIFO Control          */
#define FDCAN_ELEMENT_MASK_MM    ((uint32_t)0xFF000000U) /* Message Marker              */
#define FDCAN_ELEMENT_MASK_FIDX  ((uint32_t)0x7F000000U) /* Filter Index                */
#define FDCAN_ELEMENT_MASK_ANMF  ((uint32_t)0x80000000U) /* Accepted Non-matching Frame */
#define FDCAN_ELEMENT_MASK_ET    ((uint32_t)0x00C00000U) /* Event type                  */

#define FDCAN_MESSAGE_RAM_SIZE 0x6A0U
#define FDCAN_MESSAGE_RAM_END_ADDRESS (SRAMCAN_BASE + FDCAN_MESSAGE_RAM_SIZE) /* The Message RAM has a width of 4 Bytes */

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static const uint8_t DLCtoBytes[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup FDCAN_Private_Functions_Prototypes
  * @{
  */
static HAL_StatusTypeDef FDCAN_CalcultateRamBlockAddresses(FDCAN_HandleTypeDef *hfdcan);
static void FDCAN_CopyMessageToRAM(FDCAN_HandleTypeDef *hfdcan, FDCAN_TxHeaderTypeDef *pTxHeader, uint8_t *pTxData, uint32_t BufferIndex);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup FDCAN_Exported_Functions FDCAN Exported Functions
  * @{
  */

/** @defgroup FDCAN_Exported_Functions_Group1 Initialization and de-initialization functions
 *  @brief    Initialization and Configuration functions
 *
@verbatim
  ==============================================================================
              ##### Initialization and de-initialization functions #####
  ==============================================================================
    [..]  This section provides functions allowing to:
      (+) Initialize and configure the FDCAN.
      (+) De-initialize the FDCAN.
      (+) Enter FDCAN peripheral in power down mode.
      (+) Exit power down mode.
      (+) Register callbacks.
      (+) Unregister callbacks.

@endverbatim
  * @{
  */

/**
  * @brief  Initializes the FDCAN peripheral according to the specified
  *         parameters in the FDCAN_InitTypeDef structure.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_Init(FDCAN_HandleTypeDef *hfdcan)
{
  uint32_t tickstart;
  HAL_StatusTypeDef status;
  const uint32_t CvtEltSize[] = {0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 5, 0, 0, 0, 6, 0, 0, 0, 7};

  /* Check FDCAN handle */
  if (hfdcan == NULL)
  {
    return HAL_ERROR;
  }

  /* Check function parameters */
  assert_param(IS_FDCAN_ALL_INSTANCE(hfdcan->Instance));
  assert_param(IS_FDCAN_FRAME_FORMAT(hfdcan->Init.FrameFormat));
  assert_param(IS_FDCAN_MODE(hfdcan->Init.Mode));
  assert_param(IS_FUNCTIONAL_STATE(hfdcan->Init.AutoRetransmission));
  assert_param(IS_FUNCTIONAL_STATE(hfdcan->Init.TransmitPause));
  assert_param(IS_FUNCTIONAL_STATE(hfdcan->Init.ProtocolException));
  assert_param(IS_FDCAN_NOMINAL_PRESCALER(hfdcan->Init.NominalPrescaler));
  assert_param(IS_FDCAN_NOMINAL_SJW(hfdcan->Init.NominalSyncJumpWidth));
  assert_param(IS_FDCAN_NOMINAL_TSEG1(hfdcan->Init.NominalTimeSeg1));
  assert_param(IS_FDCAN_NOMINAL_TSEG2(hfdcan->Init.NominalTimeSeg2));
  if (hfdcan->Init.FrameFormat == FDCAN_FRAME_FD_BRS)
  {
    assert_param(IS_FDCAN_DATA_PRESCALER(hfdcan->Init.DataPrescaler));
    assert_param(IS_FDCAN_DATA_SJW(hfdcan->Init.DataSyncJumpWidth));
    assert_param(IS_FDCAN_DATA_TSEG1(hfdcan->Init.DataTimeSeg1));
    assert_param(IS_FDCAN_DATA_TSEG2(hfdcan->Init.DataTimeSeg2));
  }
  assert_param(IS_FDCAN_MAX_VALUE(hfdcan->Init.StdFiltersNbr, 28U));
  assert_param(IS_FDCAN_MAX_VALUE(hfdcan->Init.ExtFiltersNbr, 8U));
  assert_param(IS_FDCAN_MAX_VALUE(hfdcan->Init.RxFifo0ElmtsNbr, 3U));
  if (hfdcan->Init.RxFifo0ElmtsNbr > 0U)
  {
    assert_param(IS_FDCAN_DATA_SIZE(hfdcan->Init.RxFifo0ElmtSize));
  }
  assert_param(IS_FDCAN_MAX_VALUE(hfdcan->Init.RxFifo1ElmtsNbr, 3U));
  if (hfdcan->Init.RxFifo1ElmtsNbr > 0U)
  {
    assert_param(IS_FDCAN_DATA_SIZE(hfdcan->Init.RxFifo1ElmtSize));
  }
  assert_param(IS_FDCAN_MAX_VALUE(hfdcan->Init.RxBuffersNbr, 6U));
  if (hfdcan->Init.RxBuffersNbr > 0U)
  {
    assert_param(IS_FDCAN_DATA_SIZE(hfdcan->Init.RxBufferSize));
  }
  assert_param(IS_FDCAN_MAX_VALUE(hfdcan->Init.TxEventsNbr, 3U));
  assert_param(IS_FDCAN_MAX_VALUE((hfdcan->Init.TxBuffersNbr + hfdcan->Init.TxFifoQueueElmtsNbr), 3U));
  if (hfdcan->Init.TxFifoQueueElmtsNbr > 0U)
  {
    assert_param(IS_FDCAN_TX_FIFO_QUEUE_MODE(hfdcan->Init.TxFifoQueueMode));
  }
  if ((hfdcan->Init.TxBuffersNbr + hfdcan->Init.TxFifoQueueElmtsNbr) > 0U)
  {
    assert_param(IS_FDCAN_DATA_SIZE(hfdcan->Init.TxElmtSize));
  }

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
  if (hfdcan->State == HAL_FDCAN_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hfdcan->Lock = HAL_UNLOCKED;

    /* Reset callbacks to legacy functions */
    hfdcan->TxEventFifoCallback         = HAL_FDCAN_TxEventFifoCallback;         /* Legacy weak TxEventFifoCallback         */
    hfdcan->RxFifo0Callback             = HAL_FDCAN_RxFifo0Callback;             /* Legacy weak RxFifo0Callback             */
    hfdcan->RxFifo1Callback             = HAL_FDCAN_RxFifo1Callback;             /* Legacy weak RxFifo1Callback             */
    hfdcan->TxFifoEmptyCallback         = HAL_FDCAN_TxFifoEmptyCallback;         /* Legacy weak TxFifoEmptyCallback         */
    hfdcan->TxBufferCompleteCallback    = HAL_FDCAN_TxBufferCompleteCallback;    /* Legacy weak TxBufferCompleteCallback    */
    hfdcan->TxBufferAbortCallback       = HAL_FDCAN_TxBufferAbortCallback;       /* Legacy weak TxBufferAbortCallback       */
    hfdcan->RxBufferNewMessageCallback  = HAL_FDCAN_RxBufferNewMessageCallback;  /* Legacy weak RxBufferNewMessageCallback  */
    hfdcan->HighPriorityMessageCallback = HAL_FDCAN_HighPriorityMessageCallback; /* Legacy weak HighPriorityMessageCallback */
    hfdcan->TimestampWraparoundCallback = HAL_FDCAN_TimestampWraparoundCallback; /* Legacy weak TimestampWraparoundCallback */
    hfdcan->TimeoutOccurredCallback     = HAL_FDCAN_TimeoutOccurredCallback;     /* Legacy weak TimeoutOccurredCallback     */
    hfdcan->ErrorCallback               = HAL_FDCAN_ErrorCallback;               /* Legacy weak ErrorCallback               */
    hfdcan->ErrorStatusCallback         = HAL_FDCAN_ErrorStatusCallback;         /* Legacy weak ErrorStatusCallback         */

    if (hfdcan->MspInitCallback == NULL)
    {
      hfdcan->MspInitCallback = HAL_FDCAN_MspInit;  /* Legacy weak MspInit */
    }

    /* Init the low level hardware: CLOCK, NVIC */
    hfdcan->MspInitCallback(hfdcan);
  }
#else
  if (hfdcan->State == HAL_FDCAN_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hfdcan->Lock = HAL_UNLOCKED;

    /* Init the low level hardware: CLOCK, NVIC */
    HAL_FDCAN_MspInit(hfdcan);
  }
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */

  /* Exit from Sleep mode */
  CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_CSR);

  /* Get tick */
  tickstart = HAL_GetTick();

  /* Check Sleep mode acknowledge */
  while ((hfdcan->Instance->CCCR & FDCAN_CCCR_CSA) == FDCAN_CCCR_CSA)
  {
    if ((HAL_GetTick() - tickstart) > FDCAN_TIMEOUT_VALUE)
    {
      /* Update error code */
      hfdcan->ErrorCode |= HAL_FDCAN_ERROR_TIMEOUT;

      /* Change FDCAN state */
      hfdcan->State = HAL_FDCAN_STATE_ERROR;

      return HAL_ERROR;
    }
  }

  /* Request initialisation */
  SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_INIT);

  /* Get tick */
  tickstart = HAL_GetTick();

  /* Wait until the INIT bit into CCCR register is set */
  while ((hfdcan->Instance->CCCR & FDCAN_CCCR_INIT) == 0U)
  {
    /* Check for the Timeout */
    if ((HAL_GetTick() - tickstart) > FDCAN_TIMEOUT_VALUE)
    {
      /* Update error code */
      hfdcan->ErrorCode |= HAL_FDCAN_ERROR_TIMEOUT;

      /* Change FDCAN state */
      hfdcan->State = HAL_FDCAN_STATE_ERROR;

      return HAL_ERROR;
    }
  }

  /* Enable configuration change */
  SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_CCE);

  /* Set the no automatic retransmission */
  if (hfdcan->Init.AutoRetransmission == ENABLE)
  {
    CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_DAR);
  }
  else
  {
    SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_DAR);
  }

  /* Set the transmit pause feature */
  if (hfdcan->Init.TransmitPause == ENABLE)
  {
    SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_TXP);
  }
  else
  {
    CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_TXP);
  }

  /* Set the Protocol Exception Handling */
  if (hfdcan->Init.ProtocolException == ENABLE)
  {
    CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_PXHD);
  }
  else
  {
    SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_PXHD);
  }

  /* Set FDCAN Frame Format */
  MODIFY_REG(hfdcan->Instance->CCCR, FDCAN_FRAME_FD_BRS, hfdcan->Init.FrameFormat);

  /* Reset FDCAN Operation Mode */
  CLEAR_BIT(hfdcan->Instance->CCCR, (FDCAN_CCCR_TEST | FDCAN_CCCR_MON | FDCAN_CCCR_ASM));
  CLEAR_BIT(hfdcan->Instance->TEST, FDCAN_TEST_LBCK);

  /* Set FDCAN Operating Mode:
               | Normal | Restricted |    Bus     | Internal | External
               |        | Operation  | Monitoring | LoopBack | LoopBack
     CCCR.TEST |   0    |     0      |     0      |    1     |    1
     CCCR.MON  |   0    |     0      |     1      |    1     |    0
     TEST.LBCK |   0    |     0      |     0      |    1     |    1
     CCCR.ASM  |   0    |     1      |     0      |    0     |    0
  */
  if (hfdcan->Init.Mode == FDCAN_MODE_RESTRICTED_OPERATION)
  {
    /* Enable Restricted Operation mode */
    SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_ASM);
  }
  else if (hfdcan->Init.Mode != FDCAN_MODE_NORMAL)
  {
    if (hfdcan->Init.Mode != FDCAN_MODE_BUS_MONITORING)
    {
      /* Enable write access to TEST register */
      SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_TEST);

      /* Enable LoopBack mode */
      SET_BIT(hfdcan->Instance->TEST, FDCAN_TEST_LBCK);

      if (hfdcan->Init.Mode == FDCAN_MODE_INTERNAL_LOOPBACK)
      {
        SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_MON);
      }
    }
    else
    {
      /* Enable bus monitoring mode */
      SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_MON);
    }
  }
  else
  {
    /* Nothing to do: normal mode */
  }

  /* Set the nominal bit timing register */
  hfdcan->Instance->NBTP = ((((uint32_t)hfdcan->Init.NominalSyncJumpWidth - 1U) << FDCAN_NBTP_NSJW_Pos) | \
                            (((uint32_t)hfdcan->Init.NominalTimeSeg1 - 1U) << FDCAN_NBTP_NTSEG1_Pos)    | \
                            (((uint32_t)hfdcan->Init.NominalTimeSeg2 - 1U) << FDCAN_NBTP_NTSEG2_Pos)    | \
                            (((uint32_t)hfdcan->Init.NominalPrescaler - 1U) << FDCAN_NBTP_NBRP_Pos));

  /* If FD operation with BRS is selected, set the data bit timing register */
  if (hfdcan->Init.FrameFormat == FDCAN_FRAME_FD_BRS)
  {
    hfdcan->Instance->DBTP = ((((uint32_t)hfdcan->Init.DataSyncJumpWidth - 1U) << FDCAN_DBTP_DSJW_Pos) | \
                              (((uint32_t)hfdcan->Init.DataTimeSeg1 - 1U) << FDCAN_DBTP_DTSEG1_Pos)    | \
                              (((uint32_t)hfdcan->Init.DataTimeSeg2 - 1U) << FDCAN_DBTP_DTSEG2_Pos)    | \
                              (((uint32_t)hfdcan->Init.DataPrescaler - 1U) << FDCAN_DBTP_DBRP_Pos));
  }

  if (hfdcan->Init.TxFifoQueueElmtsNbr > 0U)
  {
    /* Select between Tx FIFO and Tx Queue operation modes */
    MODIFY_REG(hfdcan->Instance->TXBC, FDCAN_TXBC_TFQM, hfdcan->Init.TxFifoQueueMode);
  }

  /* Configure Tx element size */
  if ((hfdcan->Init.TxBuffersNbr + hfdcan->Init.TxFifoQueueElmtsNbr) > 0U)
  {
    MODIFY_REG(hfdcan->Instance->TXESC, FDCAN_TXESC_TBDS, CvtEltSize[hfdcan->Init.TxElmtSize]);
  }

  /* Configure Rx FIFO 0 element size */
  if (hfdcan->Init.RxFifo0ElmtsNbr > 0U)
  {
    MODIFY_REG(hfdcan->Instance->RXESC, FDCAN_RXESC_F0DS, (CvtEltSize[hfdcan->Init.RxFifo0ElmtSize] << FDCAN_RXESC_F0DS_Pos));
  }

  /* Configure Rx FIFO 1 element size */
  if (hfdcan->Init.RxFifo1ElmtsNbr > 0U)
  {
    MODIFY_REG(hfdcan->Instance->RXESC, FDCAN_RXESC_F1DS, (CvtEltSize[hfdcan->Init.RxFifo1ElmtSize] << FDCAN_RXESC_F1DS_Pos));
  }

  /* Configure Rx buffer element size */
  if (hfdcan->Init.RxBuffersNbr > 0U)
  {
    MODIFY_REG(hfdcan->Instance->RXESC, FDCAN_RXESC_RBDS, (CvtEltSize[hfdcan->Init.RxBufferSize] << FDCAN_RXESC_RBDS_Pos));
  }

  /* Initialize the Latest Tx FIFO/Queue request buffer index */
  hfdcan->LatestTxFifoQRequest = 0U;

  /* Initialize the error code */
  hfdcan->ErrorCode = HAL_FDCAN_ERROR_NONE;

  /* Initialize the FDCAN state */
  hfdcan->State = HAL_FDCAN_STATE_READY;

  /* Calculate each RAM block address */
  status = FDCAN_CalcultateRamBlockAddresses(hfdcan);

  /* Return function status */
  return status;
}

/**
  * @brief  Deinitializes the FDCAN peripheral registers to their default reset values.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_DeInit(FDCAN_HandleTypeDef *hfdcan)
{
  /* Check FDCAN handle */
  if (hfdcan == NULL)
  {
    return HAL_ERROR;
  }

  /* Check function parameters */
  assert_param(IS_FDCAN_ALL_INSTANCE(hfdcan->Instance));

  /* Stop the FDCAN module: return value is voluntary ignored */
  (void)HAL_FDCAN_Stop(hfdcan);

  /* Disable Interrupt lines */
  CLEAR_BIT(hfdcan->Instance->ILE, (FDCAN_INTERRUPT_LINE0 | FDCAN_INTERRUPT_LINE1));

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
  if (hfdcan->MspDeInitCallback == NULL)
  {
    hfdcan->MspDeInitCallback = HAL_FDCAN_MspDeInit; /* Legacy weak MspDeInit */
  }

  /* DeInit the low level hardware: CLOCK, NVIC */
  hfdcan->MspDeInitCallback(hfdcan);
#else
  /* DeInit the low level hardware: CLOCK, NVIC */
  HAL_FDCAN_MspDeInit(hfdcan);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */

  /* Reset the FDCAN ErrorCode */
  hfdcan->ErrorCode = HAL_FDCAN_ERROR_NONE;

  /* Change FDCAN state */
  hfdcan->State = HAL_FDCAN_STATE_RESET;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Initializes the FDCAN MSP.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval None
  */
__weak void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef *hfdcan)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitializes the FDCAN MSP.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval None
  */
__weak void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef *hfdcan)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_MspDeInit could be implemented in the user file
   */
}

/**
  * @brief  Enter FDCAN peripheral in sleep mode.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_EnterPowerDownMode(FDCAN_HandleTypeDef *hfdcan)
{
  uint32_t tickstart;

  /* Request clock stop */
  SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_CSR);

  /* Get tick */
  tickstart = HAL_GetTick();

  /* Wait until FDCAN is ready for power down */
  while ((hfdcan->Instance->CCCR & FDCAN_CCCR_CSA) == 0U)
  {
    if ((HAL_GetTick() - tickstart) > FDCAN_TIMEOUT_VALUE)
    {
      /* Update error code */
      hfdcan->ErrorCode |= HAL_FDCAN_ERROR_TIMEOUT;

      /* Change FDCAN state */
      hfdcan->State = HAL_FDCAN_STATE_ERROR;

      return HAL_ERROR;
    }
  }

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Exit power down mode.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ExitPowerDownMode(FDCAN_HandleTypeDef *hfdcan)
{
  uint32_t tickstart;

  /* Reset clock stop request */
  CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_CSR);

  /* Get tick */
  tickstart = HAL_GetTick();

  /* Wait until FDCAN exits sleep mode */
  while ((hfdcan->Instance->CCCR & FDCAN_CCCR_CSA) == FDCAN_CCCR_CSA)
  {
    if ((HAL_GetTick() - tickstart) > FDCAN_TIMEOUT_VALUE)
    {
      /* Update error code */
      hfdcan->ErrorCode |= HAL_FDCAN_ERROR_TIMEOUT;

      /* Change FDCAN state */
      hfdcan->State = HAL_FDCAN_STATE_ERROR;

      return HAL_ERROR;
    }
  }

  /* Enter normal operation */
  CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_INIT);

  /* Return function status */
  return HAL_OK;
}

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
/**
  * @brief  Register a FDCAN CallBack.
  *         To be used instead of the weak predefined callback
  * @param  hfdcan pointer to a FDCAN_HandleTypeDef structure that contains
  *         the configuration information for FDCAN module
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_FDCAN_TX_FIFO_EMPTY_CB_ID Tx Fifo Empty callback ID
  *           @arg @ref HAL_FDCAN_RX_BUFFER_NEW_MSG_CB_ID Rx buffer new message callback ID
  *           @arg @ref HAL_FDCAN_HIGH_PRIO_MESSAGE_CB_ID High priority message callback ID
  *           @arg @ref HAL_FDCAN_TIMESTAMP_WRAPAROUND_CB_ID Timestamp wraparound callback ID
  *           @arg @ref HAL_FDCAN_TIMEOUT_OCCURRED_CB_ID Timeout occurred callback ID
  *           @arg @ref HAL_FDCAN_ERROR_CALLBACK_CB_ID Error callback ID
  *           @arg @ref HAL_FDCAN_MSPINIT_CB_ID MspInit callback ID
  *           @arg @ref HAL_FDCAN_MSPDEINIT_CB_ID MspDeInit callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_RegisterCallback(FDCAN_HandleTypeDef *hfdcan, HAL_FDCAN_CallbackIDTypeDef CallbackID, void (* pCallback)(FDCAN_HandleTypeDef *_hFDCAN))
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_FDCAN_TX_FIFO_EMPTY_CB_ID :
        hfdcan->TxFifoEmptyCallback = pCallback;
        break;

      case HAL_FDCAN_RX_BUFFER_NEW_MSG_CB_ID :
        hfdcan->RxBufferNewMessageCallback = pCallback;
        break;

      case HAL_FDCAN_HIGH_PRIO_MESSAGE_CB_ID :
        hfdcan->HighPriorityMessageCallback = pCallback;
        break;

      case HAL_FDCAN_TIMESTAMP_WRAPAROUND_CB_ID :
        hfdcan->TimestampWraparoundCallback = pCallback;
        break;

      case HAL_FDCAN_TIMEOUT_OCCURRED_CB_ID :
        hfdcan->TimeoutOccurredCallback = pCallback;
        break;

      case HAL_FDCAN_ERROR_CALLBACK_CB_ID :
        hfdcan->ErrorCallback = pCallback;
        break;

      case HAL_FDCAN_MSPINIT_CB_ID :
        hfdcan->MspInitCallback = pCallback;
        break;

      case HAL_FDCAN_MSPDEINIT_CB_ID :
        hfdcan->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (hfdcan->State == HAL_FDCAN_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_FDCAN_MSPINIT_CB_ID :
        hfdcan->MspInitCallback = pCallback;
        break;

      case HAL_FDCAN_MSPDEINIT_CB_ID :
        hfdcan->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  Unregister a FDCAN CallBack.
  *         FDCAN callback is redirected to the weak predefined callback
  * @param  hfdcan pointer to a FDCAN_HandleTypeDef structure that contains
  *         the configuration information for FDCAN module
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_FDCAN_TX_FIFO_EMPTY_CB_ID Tx Fifo Empty callback ID
  *           @arg @ref HAL_FDCAN_RX_BUFFER_NEW_MSG_CB_ID Rx buffer new message callback ID
  *           @arg @ref HAL_FDCAN_HIGH_PRIO_MESSAGE_CB_ID High priority message callback ID
  *           @arg @ref HAL_FDCAN_TIMESTAMP_WRAPAROUND_CB_ID Timestamp wraparound callback ID
  *           @arg @ref HAL_FDCAN_TIMEOUT_OCCURRED_CB_ID Timeout occurred callback ID
  *           @arg @ref HAL_FDCAN_ERROR_CALLBACK_CB_ID Error callback ID
  *           @arg @ref HAL_FDCAN_MSPINIT_CB_ID MspInit callback ID
  *           @arg @ref HAL_FDCAN_MSPDEINIT_CB_ID MspDeInit callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_UnRegisterCallback(FDCAN_HandleTypeDef *hfdcan, HAL_FDCAN_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_FDCAN_TX_FIFO_EMPTY_CB_ID :
        hfdcan->TxFifoEmptyCallback = HAL_FDCAN_TxFifoEmptyCallback;
        break;

      case HAL_FDCAN_RX_BUFFER_NEW_MSG_CB_ID :
        hfdcan->RxBufferNewMessageCallback = HAL_FDCAN_RxBufferNewMessageCallback;
        break;

      case HAL_FDCAN_HIGH_PRIO_MESSAGE_CB_ID :
        hfdcan->HighPriorityMessageCallback = HAL_FDCAN_HighPriorityMessageCallback;
        break;

      case HAL_FDCAN_TIMESTAMP_WRAPAROUND_CB_ID :
        hfdcan->TimestampWraparoundCallback = HAL_FDCAN_TimestampWraparoundCallback;
        break;

      case HAL_FDCAN_TIMEOUT_OCCURRED_CB_ID :
        hfdcan->TimeoutOccurredCallback = HAL_FDCAN_TimeoutOccurredCallback;
        break;

      case HAL_FDCAN_ERROR_CALLBACK_CB_ID :
        hfdcan->ErrorCallback = HAL_FDCAN_ErrorCallback;
        break;

      case HAL_FDCAN_MSPINIT_CB_ID :
        hfdcan->MspInitCallback = HAL_FDCAN_MspInit;
        break;

      case HAL_FDCAN_MSPDEINIT_CB_ID :
        hfdcan->MspDeInitCallback = HAL_FDCAN_MspDeInit;
        break;

      default :
        /* Update the error code */
        hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (hfdcan->State == HAL_FDCAN_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_FDCAN_MSPINIT_CB_ID :
        hfdcan->MspInitCallback = HAL_FDCAN_MspInit;
        break;

      case HAL_FDCAN_MSPDEINIT_CB_ID :
        hfdcan->MspDeInitCallback = HAL_FDCAN_MspDeInit;
        break;

      default :
        /* Update the error code */
        hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  Register Tx Event Fifo FDCAN Callback
  *         To be used instead of the weak HAL_FDCAN_TxEventFifoCallback() predefined callback
  * @param  hfdcan FDCAN handle
  * @param  pCallback pointer to the Tx Event Fifo Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_RegisterTxEventFifoCallback(FDCAN_HandleTypeDef *hfdcan, pFDCAN_TxEventFifoCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->TxEventFifoCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  UnRegister the Tx Event Fifo FDCAN Callback
  *         Tx Event Fifo FDCAN Callback is redirected to the weak HAL_FDCAN_TxEventFifoCallback() predefined callback
  * @param  hfdcan FDCAN handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_UnRegisterTxEventFifoCallback(FDCAN_HandleTypeDef *hfdcan)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->TxEventFifoCallback = HAL_FDCAN_TxEventFifoCallback; /* Legacy weak TxEventFifoCallback  */
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  Register Rx Fifo 0 FDCAN Callback
  *         To be used instead of the weak HAL_FDCAN_RxFifo0Callback() predefined callback
  * @param  hfdcan FDCAN handle
  * @param  pCallback pointer to the Rx Fifo 0 Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_RegisterRxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, pFDCAN_RxFifo0CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->RxFifo0Callback = pCallback;
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  UnRegister the Rx Fifo 0 FDCAN Callback
  *         Rx Fifo 0 FDCAN Callback is redirected to the weak HAL_FDCAN_RxFifo0Callback() predefined callback
  * @param  hfdcan FDCAN handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_UnRegisterRxFifo0Callback(FDCAN_HandleTypeDef *hfdcan)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->RxFifo0Callback = HAL_FDCAN_RxFifo0Callback; /* Legacy weak RxFifo0Callback  */
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  Register Rx Fifo 1 FDCAN Callback
  *         To be used instead of the weak HAL_FDCAN_RxFifo1Callback() predefined callback
  * @param  hfdcan FDCAN handle
  * @param  pCallback pointer to the Rx Fifo 1 Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_RegisterRxFifo1Callback(FDCAN_HandleTypeDef *hfdcan, pFDCAN_RxFifo1CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->RxFifo1Callback = pCallback;
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  UnRegister the Rx Fifo 1 FDCAN Callback
  *         Rx Fifo 1 FDCAN Callback is redirected to the weak HAL_FDCAN_RxFifo1Callback() predefined callback
  * @param  hfdcan FDCAN handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_UnRegisterRxFifo1Callback(FDCAN_HandleTypeDef *hfdcan)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->RxFifo1Callback = HAL_FDCAN_RxFifo1Callback; /* Legacy weak RxFifo1Callback  */
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  Register Tx Buffer Complete FDCAN Callback
  *         To be used instead of the weak HAL_FDCAN_TxBufferCompleteCallback() predefined callback
  * @param  hfdcan FDCAN handle
  * @param  pCallback pointer to the Tx Buffer Complete Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_RegisterTxBufferCompleteCallback(FDCAN_HandleTypeDef *hfdcan, pFDCAN_TxBufferCompleteCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->TxBufferCompleteCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  UnRegister the Tx Buffer Complete FDCAN Callback
  *         Tx Buffer Complete FDCAN Callback is redirected to the weak HAL_FDCAN_TxBufferCompleteCallback() predefined callback
  * @param  hfdcan FDCAN handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_UnRegisterTxBufferCompleteCallback(FDCAN_HandleTypeDef *hfdcan)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->TxBufferCompleteCallback = HAL_FDCAN_TxBufferCompleteCallback; /* Legacy weak TxBufferCompleteCallback  */
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  Register Tx Buffer Abort FDCAN Callback
  *         To be used instead of the weak HAL_FDCAN_TxBufferAbortCallback() predefined callback
  * @param  hfdcan FDCAN handle
  * @param  pCallback pointer to the Tx Buffer Abort Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_RegisterTxBufferAbortCallback(FDCAN_HandleTypeDef *hfdcan, pFDCAN_TxBufferAbortCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->TxBufferAbortCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  UnRegister the Tx Buffer Abort FDCAN Callback
  *         Tx Buffer Abort FDCAN Callback is redirected to the weak HAL_FDCAN_TxBufferAbortCallback() predefined callback
  * @param  hfdcan FDCAN handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_UnRegisterTxBufferAbortCallback(FDCAN_HandleTypeDef *hfdcan)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->TxBufferAbortCallback = HAL_FDCAN_TxBufferAbortCallback; /* Legacy weak TxBufferAbortCallback  */
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  Register Error Status FDCAN Callback
  *         To be used instead of the weak HAL_FDCAN_ErrorStatusCallback() predefined callback
  * @param  hfdcan FDCAN handle
  * @param  pCallback pointer to the Error Status Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_RegisterErrorStatusCallback(FDCAN_HandleTypeDef *hfdcan, pFDCAN_ErrorStatusCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->ErrorStatusCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  UnRegister the Error Status FDCAN Callback
  *         Error Status FDCAN Callback is redirected to the weak HAL_FDCAN_ErrorStatusCallback() predefined callback
  * @param  hfdcan FDCAN handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_UnRegisterErrorStatusCallback(FDCAN_HandleTypeDef *hfdcan)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    hfdcan->ErrorStatusCallback = HAL_FDCAN_ErrorStatusCallback; /* Legacy weak ErrorStatusCallback  */
  }
  else
  {
    /* Update the error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup FDCAN_Exported_Functions_Group2 Configuration functions
 *  @brief    FDCAN Configuration functions.
 *
@verbatim
  ==============================================================================
              ##### Configuration functions #####
  ==============================================================================
    [..]  This section provides functions allowing to:
      (+) HAL_FDCAN_ConfigFilter                  : Configure the FDCAN reception filters
      (+) HAL_FDCAN_ConfigGlobalFilter            : Configure the FDCAN global filter
      (+) HAL_FDCAN_ConfigExtendedIdMask          : Configure the extended ID mask
      (+) HAL_FDCAN_ConfigRxFifoOverwrite         : Configure the Rx FIFO operation mode
      (+) HAL_FDCAN_ConfigFifoWatermark           : Configure the FIFO watermark
      (+) HAL_FDCAN_ConfigRamWatchdog             : Configure the RAM watchdog
      (+) HAL_FDCAN_ConfigTimestampCounter        : Configure the timestamp counter
        (+) HAL_FDCAN_EnableTimestampCounter        : Enable the timestamp counter
        (+) HAL_FDCAN_DisableTimestampCounter       : Disable the timestamp counter
        (+) HAL_FDCAN_GetTimestampCounter           : Get the timestamp counter value
        (+) HAL_FDCAN_ResetTimestampCounter         : Reset the timestamp counter to zero
      (+) HAL_FDCAN_ConfigTimeoutCounter          : Configure the timeout counter
        (+) HAL_FDCAN_EnableTimeoutCounter          : Enable the timeout counter
        (+) HAL_FDCAN_DisableTimeoutCounter         : Disable the timeout counter
        (+) HAL_FDCAN_GetTimeoutCounter             : Get the timeout counter value
        (+) HAL_FDCAN_ResetTimeoutCounter           : Reset the timeout counter to its start value
      (+) HAL_FDCAN_ConfigTxDelayCompensation     : Configure the transmitter delay compensation
        (+) HAL_FDCAN_EnableTxDelayCompensation     : Enable the transmitter delay compensation
        (+) HAL_FDCAN_DisableTxDelayCompensation    : Disable the transmitter delay compensation
      (+) HAL_FDCAN_EnableISOMode                 : Enable ISO 11898-1 protocol mode
      (+) HAL_FDCAN_DisableISOMode                : Disable ISO 11898-1 protocol mode
      (+) HAL_FDCAN_EnableEdgeFiltering           : Enable edge filtering during bus integration
      (+) HAL_FDCAN_DisableEdgeFiltering          : Disable edge filtering during bus integration

@endverbatim
  * @{
  */

/**
  * @brief  Configure the FDCAN reception filter according to the specified
  *         parameters in the FDCAN_FilterTypeDef structure.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  sFilterConfig pointer to an FDCAN_FilterTypeDef structure that
  *         contains the filter configuration information
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ConfigFilter(FDCAN_HandleTypeDef *hfdcan, FDCAN_FilterTypeDef *sFilterConfig)
{
  uint32_t FilterElementW1;
  uint32_t FilterElementW2;
  uint32_t *FilterAddress;
  HAL_FDCAN_StateTypeDef state = hfdcan->State;

  if ((state == HAL_FDCAN_STATE_READY) || (state == HAL_FDCAN_STATE_BUSY))
  {
    /* Check function parameters */
    assert_param(IS_FDCAN_ID_TYPE(sFilterConfig->IdType));
    assert_param(IS_FDCAN_FILTER_CFG(sFilterConfig->FilterConfig));
    if (sFilterConfig->FilterConfig == FDCAN_FILTER_TO_RXBUFFER)
    {
      assert_param(IS_FDCAN_MAX_VALUE(sFilterConfig->RxBufferIndex, 5U));
    }

    if (sFilterConfig->IdType == FDCAN_STANDARD_ID)
    {
      /* Check function parameters */
      assert_param(IS_FDCAN_MAX_VALUE(sFilterConfig->FilterIndex, (hfdcan->Init.StdFiltersNbr - 1U)));
      assert_param(IS_FDCAN_MAX_VALUE(sFilterConfig->FilterID1, 0x7FFU));
      if (sFilterConfig->FilterConfig != FDCAN_FILTER_TO_RXBUFFER)
      {
        assert_param(IS_FDCAN_MAX_VALUE(sFilterConfig->FilterID2, 0x7FFU));
        assert_param(IS_FDCAN_STD_FILTER_TYPE(sFilterConfig->FilterType));
      }

      /* Build filter element */
      if (sFilterConfig->FilterConfig == FDCAN_FILTER_TO_RXBUFFER)
      {
        FilterElementW1 = ((FDCAN_FILTER_TO_RXBUFFER << 27U)       |
                           (sFilterConfig->FilterID1 << 16U)       |
                           sFilterConfig->RxBufferIndex);
      }
      else
      {
        FilterElementW1 = ((sFilterConfig->FilterType << 30U)   |
                           (sFilterConfig->FilterConfig << 27U) |
                           (sFilterConfig->FilterID1 << 16U)    |
                           sFilterConfig->FilterID2);
      }

      /* Calculate filter address */
      FilterAddress = (uint32_t *)(hfdcan->msgRam.StandardFilterSA + (sFilterConfig->FilterIndex * 4U));

      /* Write filter element to the message RAM */
      *FilterAddress = FilterElementW1;
    }
    else /* sFilterConfig->IdType == FDCAN_EXTENDED_ID */
    {
      /* Check function parameters */
      assert_param(IS_FDCAN_MAX_VALUE(sFilterConfig->FilterIndex, (hfdcan->Init.ExtFiltersNbr - 1U)));
      assert_param(IS_FDCAN_MAX_VALUE(sFilterConfig->FilterID1, 0x1FFFFFFFU));
      if (sFilterConfig->FilterConfig != FDCAN_FILTER_TO_RXBUFFER)
      {
        assert_param(IS_FDCAN_MAX_VALUE(sFilterConfig->FilterID2, 0x1FFFFFFFU));
        assert_param(IS_FDCAN_EXT_FILTER_TYPE(sFilterConfig->FilterType));
      }

      /* Build first word of filter element */
      FilterElementW1 = ((sFilterConfig->FilterConfig << 29U) | sFilterConfig->FilterID1);

      /* Build second word of filter element */
      if (sFilterConfig->FilterConfig == FDCAN_FILTER_TO_RXBUFFER)
      {
        FilterElementW2 = sFilterConfig->RxBufferIndex;
      }
      else
      {
        FilterElementW2 = ((sFilterConfig->FilterType << 30U) | sFilterConfig->FilterID2);
      }

      /* Calculate filter address */
      FilterAddress = (uint32_t *)(hfdcan->msgRam.ExtendedFilterSA + (sFilterConfig->FilterIndex * 4U * 2U));

      /* Write filter element to the message RAM */
      *FilterAddress = FilterElementW1;
      FilterAddress++;
      *FilterAddress = FilterElementW2;
    }

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_INITIALIZED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Configure the FDCAN global filter.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  NonMatchingStd Defines how received messages with 11-bit IDs that
  *         do not match any element of the filter list are treated.
  *         This parameter can be a value of @arg FDCAN_Non_Matching_Frames.
  * @param  NonMatchingExt Defines how received messages with 29-bit IDs that
  *         do not match any element of the filter list are treated.
  *         This parameter can be a value of @arg FDCAN_Non_Matching_Frames.
  * @param  RejectRemoteStd Filter or reject all the remote 11-bit IDs frames.
  *         This parameter can be a value of @arg FDCAN_Reject_Remote_Frames.
  * @param  RejectRemoteExt Filter or reject all the remote 29-bit IDs frames.
  *         This parameter can be a value of @arg FDCAN_Reject_Remote_Frames.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ConfigGlobalFilter(FDCAN_HandleTypeDef *hfdcan,
                                               uint32_t NonMatchingStd,
                                               uint32_t NonMatchingExt,
                                               uint32_t RejectRemoteStd,
                                               uint32_t RejectRemoteExt)
{
  /* Check function parameters */
  assert_param(IS_FDCAN_NON_MATCHING(NonMatchingStd));
  assert_param(IS_FDCAN_NON_MATCHING(NonMatchingExt));
  assert_param(IS_FDCAN_REJECT_REMOTE(RejectRemoteStd));
  assert_param(IS_FDCAN_REJECT_REMOTE(RejectRemoteExt));

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Configure global filter */
    hfdcan->Instance->GFC = ((NonMatchingStd << FDCAN_GFC_ANFS_Pos)  |
                             (NonMatchingExt << FDCAN_GFC_ANFE_Pos)  |
                             (RejectRemoteStd << FDCAN_GFC_RRFS_Pos) |
                             (RejectRemoteExt << FDCAN_GFC_RRFE_Pos));

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Configure the extended ID mask.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  Mask Extended ID Mask.
  *         This parameter must be a number between 0 and 0x1FFFFFFF
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ConfigExtendedIdMask(FDCAN_HandleTypeDef *hfdcan, uint32_t Mask)
{
  /* Check function parameters */
  assert_param(IS_FDCAN_MAX_VALUE(Mask, 0x1FFFFFFFU));

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Configure the extended ID mask */
    hfdcan->Instance->XIDAM = Mask;

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Configure the Rx FIFO operation mode.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  RxFifo Rx FIFO.
  *         This parameter can be one of the following values:
  *           @arg FDCAN_RX_FIFO0: Rx FIFO 0
  *           @arg FDCAN_RX_FIFO1: Rx FIFO 1
  * @param  OperationMode operation mode.
  *         This parameter can be a value of @arg FDCAN_Rx_FIFO_operation_mode.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ConfigRxFifoOverwrite(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo, uint32_t OperationMode)
{
  /* Check function parameters */
  assert_param(IS_FDCAN_RX_FIFO(RxFifo));
  assert_param(IS_FDCAN_RX_FIFO_MODE(OperationMode));

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    if (RxFifo == FDCAN_RX_FIFO0)
    {
      /* Select FIFO 0 Operation Mode */
      MODIFY_REG(hfdcan->Instance->RXF0C, FDCAN_RXF0C_F0OM, OperationMode);
    }
    else /* RxFifo == FDCAN_RX_FIFO1 */
    {
      /* Select FIFO 1 Operation Mode */
      MODIFY_REG(hfdcan->Instance->RXF1C, FDCAN_RXF1C_F1OM, OperationMode);
    }

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Configure the FIFO watermark.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  FIFO select the FIFO to be configured.
  *         This parameter can be a value of @arg FDCAN_FIFO_watermark.
  * @param  Watermark level for FIFO watermark interrupt.
  *         This parameter must be a number between:
  *           - 0 and 3, if FIFO is FDCAN_CFG_TX_EVENT_FIFO
  *           - 0 and 3, if FIFO is FDCAN_CFG_RX_FIFO0 or FDCAN_CFG_RX_FIFO1
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ConfigFifoWatermark(FDCAN_HandleTypeDef *hfdcan, uint32_t FIFO, uint32_t Watermark)
{
  /* Check function parameters */
  assert_param(IS_FDCAN_FIFO_WATERMARK(FIFO));
  if (FIFO == FDCAN_CFG_TX_EVENT_FIFO)
  {
    assert_param(IS_FDCAN_MAX_VALUE(Watermark, 3U));
  }
  else /* (FIFO == FDCAN_CFG_RX_FIFO0) || (FIFO == FDCAN_CFG_RX_FIFO1) */
  {
    assert_param(IS_FDCAN_MAX_VALUE(Watermark, 3U));
  }

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Set the level for FIFO watermark interrupt */
    if (FIFO == FDCAN_CFG_TX_EVENT_FIFO)
    {
      MODIFY_REG(hfdcan->Instance->TXEFC, FDCAN_TXEFC_EFWM, (Watermark << FDCAN_TXEFC_EFWM_Pos));
    }
    else if (FIFO == FDCAN_CFG_RX_FIFO0)
    {
      MODIFY_REG(hfdcan->Instance->RXF0C, FDCAN_RXF0C_F0WM, (Watermark << FDCAN_RXF0C_F0WM_Pos));
    }
    else /* FIFO == FDCAN_CFG_RX_FIFO1 */
    {
      MODIFY_REG(hfdcan->Instance->RXF1C, FDCAN_RXF1C_F1WM, (Watermark << FDCAN_RXF1C_F1WM_Pos));
    }

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Configure the RAM watchdog.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  CounterStartValue Start value of the Message RAM Watchdog Counter,
  *         This parameter must be a number between 0x00 and 0xFF,
  *         with the reset value of 0x00 the counter is disabled.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ConfigRamWatchdog(FDCAN_HandleTypeDef *hfdcan, uint32_t CounterStartValue)
{
  /* Check function parameters */
  assert_param(IS_FDCAN_MAX_VALUE(CounterStartValue, 0xFFU));

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Configure the RAM watchdog counter start value */
    MODIFY_REG(hfdcan->Instance->RWD, FDCAN_RWD_WDC, CounterStartValue);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Configure the timestamp counter.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  TimestampPrescaler Timestamp Counter Prescaler.
  *         This parameter can be a value of @arg FDCAN_Timestamp_Prescaler.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ConfigTimestampCounter(FDCAN_HandleTypeDef *hfdcan, uint32_t TimestampPrescaler)
{
  /* Check function parameters */
  assert_param(IS_FDCAN_TIMESTAMP_PRESCALER(TimestampPrescaler));

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Configure prescaler */
    MODIFY_REG(hfdcan->Instance->TSCC, FDCAN_TSCC_TCP, TimestampPrescaler);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Enable the timestamp counter.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  TimestampOperation Timestamp counter operation.
  *         This parameter can be a value of @arg FDCAN_Timestamp.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_EnableTimestampCounter(FDCAN_HandleTypeDef *hfdcan, uint32_t TimestampOperation)
{
  /* Check function parameters */
  assert_param(IS_FDCAN_TIMESTAMP(TimestampOperation));

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Enable timestamp counter */
    MODIFY_REG(hfdcan->Instance->TSCC, FDCAN_TSCC_TSS, TimestampOperation);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Disable the timestamp counter.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_DisableTimestampCounter(FDCAN_HandleTypeDef *hfdcan)
{
  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Disable timestamp counter */
    CLEAR_BIT(hfdcan->Instance->TSCC, FDCAN_TSCC_TSS);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Get the timestamp counter value.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval Value Timestamp counter value
  */
uint16_t HAL_FDCAN_GetTimestampCounter(FDCAN_HandleTypeDef *hfdcan)
{
  return (uint16_t)(hfdcan->Instance->TSCV);
}

/**
  * @brief  Reset the timestamp counter to zero.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ResetTimestampCounter(FDCAN_HandleTypeDef *hfdcan)
{
  /* Reset timestamp counter.
     Actually any write operation to TSCV clears the counter */
  CLEAR_REG(hfdcan->Instance->TSCV);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Configure the timeout counter.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  TimeoutOperation Timeout counter operation.
  *         This parameter can be a value of @arg FDCAN_Timeout_Operation.
  * @param  TimeoutPeriod Start value of the timeout down-counter.
  *         This parameter must be a number between 0x0000 and 0xFFFF
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ConfigTimeoutCounter(FDCAN_HandleTypeDef *hfdcan, uint32_t TimeoutOperation, uint32_t TimeoutPeriod)
{
  /* Check function parameters */
  assert_param(IS_FDCAN_TIMEOUT(TimeoutOperation));
  assert_param(IS_FDCAN_MAX_VALUE(TimeoutPeriod, 0xFFFFU));

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Select timeout operation and configure period */
    MODIFY_REG(hfdcan->Instance->TOCC, (FDCAN_TOCC_TOS | FDCAN_TOCC_TOP), (TimeoutOperation | (TimeoutPeriod << FDCAN_TOCC_TOP_Pos)));

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Enable the timeout counter.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_EnableTimeoutCounter(FDCAN_HandleTypeDef *hfdcan)
{
  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Enable timeout counter */
    SET_BIT(hfdcan->Instance->TOCC, FDCAN_TOCC_ETOC);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Disable the timeout counter.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_DisableTimeoutCounter(FDCAN_HandleTypeDef *hfdcan)
{
  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Disable timeout counter */
    CLEAR_BIT(hfdcan->Instance->TOCC, FDCAN_TOCC_ETOC);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Get the timeout counter value.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval Value Timeout counter value
  */
uint16_t HAL_FDCAN_GetTimeoutCounter(FDCAN_HandleTypeDef *hfdcan)
{
  return (uint16_t)(hfdcan->Instance->TOCV);
}

/**
  * @brief  Reset the timeout counter to its start value.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ResetTimeoutCounter(FDCAN_HandleTypeDef *hfdcan)
{
  if ((hfdcan->Instance->TOCC & FDCAN_TOCC_TOS) == FDCAN_TIMEOUT_CONTINUOUS)
  {
    /* Reset timeout counter to start value */
    CLEAR_REG(hfdcan->Instance->TOCV);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code.
       Unable to reset counter: controlled only by FIFO empty state */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_SUPPORTED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Configure the transmitter delay compensation.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  TdcOffset Transmitter Delay Compensation Offset.
  *         This parameter must be a number between 0x00 and 0x7F.
  * @param  TdcFilter Transmitter Delay Compensation Filter Window Length.
  *         This parameter must be a number between 0x00 and 0x7F.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ConfigTxDelayCompensation(FDCAN_HandleTypeDef *hfdcan, uint32_t TdcOffset, uint32_t TdcFilter)
{
  /* Check function parameters */
  assert_param(IS_FDCAN_MAX_VALUE(TdcOffset, 0x7FU));
  assert_param(IS_FDCAN_MAX_VALUE(TdcFilter, 0x7FU));

  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Configure TDC offset and filter window */
    hfdcan->Instance->TDCR = ((TdcFilter << FDCAN_TDCR_TDCF_Pos) | (TdcOffset << FDCAN_TDCR_TDCO_Pos));

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Enable the transmitter delay compensation.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_EnableTxDelayCompensation(FDCAN_HandleTypeDef *hfdcan)
{
  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Enable transmitter delay compensation */
    SET_BIT(hfdcan->Instance->DBTP, FDCAN_DBTP_TDC);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Disable the transmitter delay compensation.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_DisableTxDelayCompensation(FDCAN_HandleTypeDef *hfdcan)
{
  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Disable transmitter delay compensation */
    CLEAR_BIT(hfdcan->Instance->DBTP, FDCAN_DBTP_TDC);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Enable ISO 11898-1 protocol mode.
  *         CAN FD frame format is according to ISO 11898-1 standard.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_EnableISOMode(FDCAN_HandleTypeDef *hfdcan)
{
  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Disable Non ISO protocol mode */
    CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_NISO);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Disable ISO 11898-1 protocol mode.
  *         CAN FD frame format is according to Bosch CAN FD specification V1.0.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_DisableISOMode(FDCAN_HandleTypeDef *hfdcan)
{
  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Enable Non ISO protocol mode */
    SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_NISO);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Enable edge filtering during bus integration.
  *         Two consecutive dominant tq are required to detect an edge for hard synchronization.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_EnableEdgeFiltering(FDCAN_HandleTypeDef *hfdcan)
{
  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Enable edge filtering */
    SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_EFBI);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Disable edge filtering during bus integration.
  *         One dominant tq is required to detect an edge for hard synchronization.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_DisableEdgeFiltering(FDCAN_HandleTypeDef *hfdcan)
{
  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Disable edge filtering */
    CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_EFBI);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @}
  */

/** @defgroup FDCAN_Exported_Functions_Group3 Control functions
 *  @brief    Control functions
 *
@verbatim
  ==============================================================================
                          ##### Control functions #####
  ==============================================================================
    [..]  This section provides functions allowing to:
      (+) HAL_FDCAN_Start                         : Start the FDCAN module
      (+) HAL_FDCAN_Stop                          : Stop the FDCAN module and enable access to configuration registers
      (+) HAL_FDCAN_AddMessageToTxFifoQ           : Add a message to the Tx FIFO/Queue and activate the corresponding transmission request
      (+) HAL_FDCAN_AddMessageToTxBuffer          : Add a message to a dedicated Tx buffer
      (+) HAL_FDCAN_EnableTxBufferRequest         : Enable transmission request
      (+) HAL_FDCAN_GetLatestTxFifoQRequestBuffer : Get Tx buffer index of latest Tx FIFO/Queue request
      (+) HAL_FDCAN_AbortTxRequest                : Abort transmission request
      (+) HAL_FDCAN_GetRxMessage                  : Get an FDCAN frame from the Rx Buffer/FIFO zone into the message RAM
      (+) HAL_FDCAN_GetTxEvent                    : Get an FDCAN Tx event from the Tx Event FIFO zone into the message RAM
      (+) HAL_FDCAN_GetHighPriorityMessageStatus  : Get high priority message status
      (+) HAL_FDCAN_GetProtocolStatus             : Get protocol status
      (+) HAL_FDCAN_GetErrorCounters              : Get error counter values
      (+) HAL_FDCAN_IsRxBufferMessageAvailable    : Check if a new message is received in the selected Rx buffer
      (+) HAL_FDCAN_IsTxBufferMessagePending      : Check if a transmission request is pending on the selected Tx buffer
      (+) HAL_FDCAN_GetRxFifoFillLevel            : Return Rx FIFO fill level
      (+) HAL_FDCAN_GetTxFifoFreeLevel            : Return Tx FIFO free level
      (+) HAL_FDCAN_IsRestrictedOperationMode     : Check if the FDCAN peripheral entered Restricted Operation Mode
      (+) HAL_FDCAN_ExitRestrictedOperationMode   : Exit Restricted Operation Mode

@endverbatim
  * @{
  */

/**
  * @brief  Start the FDCAN module.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_Start(FDCAN_HandleTypeDef *hfdcan)
{
  if (hfdcan->State == HAL_FDCAN_STATE_READY)
  {
    /* Change FDCAN peripheral state */
    hfdcan->State = HAL_FDCAN_STATE_BUSY;

    /* Request leave initialisation */
    CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_INIT);

    /* Reset the FDCAN ErrorCode */
    hfdcan->ErrorCode = HAL_FDCAN_ERROR_NONE;

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_READY;

    return HAL_ERROR;
  }
}

/**
  * @brief  Stop the FDCAN module and enable access to configuration registers.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_Stop(FDCAN_HandleTypeDef *hfdcan)
{
  uint32_t Counter = 0U;

  if (hfdcan->State == HAL_FDCAN_STATE_BUSY)
  {
    /* Request initialisation */
    SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_INIT);

    /* Wait until the INIT bit into CCCR register is set */
    while ((hfdcan->Instance->CCCR & FDCAN_CCCR_INIT) == 0U)
    {
      /* Check for the Timeout */
      if (Counter > FDCAN_TIMEOUT_COUNT)
      {
        /* Update error code */
        hfdcan->ErrorCode |= HAL_FDCAN_ERROR_TIMEOUT;

        /* Change FDCAN state */
        hfdcan->State = HAL_FDCAN_STATE_ERROR;

        return HAL_ERROR;
      }

      /* Increment counter */
      Counter++;
    }

    /* Reset counter */
    Counter = 0U;

    /* Exit from Sleep mode */
    CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_CSR);

    /* Wait until FDCAN exits sleep mode */
    while ((hfdcan->Instance->CCCR & FDCAN_CCCR_CSA) == FDCAN_CCCR_CSA)
    {
      /* Check for the Timeout */
      if (Counter > FDCAN_TIMEOUT_COUNT)
      {
        /* Update error code */
        hfdcan->ErrorCode |= HAL_FDCAN_ERROR_TIMEOUT;

        /* Change FDCAN state */
        hfdcan->State = HAL_FDCAN_STATE_ERROR;

        return HAL_ERROR;
      }

      /* Increment counter */
      Counter++;
    }

    /* Enable configuration change */
    SET_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_CCE);

    /* Reset Latest Tx FIFO/Queue Request Buffer Index */
    hfdcan->LatestTxFifoQRequest = 0U;

    /* Change FDCAN peripheral state */
    hfdcan->State = HAL_FDCAN_STATE_READY;

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_STARTED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Add a message to the Tx FIFO/Queue and activate the corresponding transmission request
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  pTxHeader pointer to a FDCAN_TxHeaderTypeDef structure.
  * @param  pTxData pointer to a buffer containing the payload of the Tx frame.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_AddMessageToTxFifoQ(FDCAN_HandleTypeDef *hfdcan, FDCAN_TxHeaderTypeDef *pTxHeader, uint8_t *pTxData)
{
  uint32_t PutIndex;

  /* Check function parameters */
  assert_param(IS_FDCAN_ID_TYPE(pTxHeader->IdType));
  if (pTxHeader->IdType == FDCAN_STANDARD_ID)
  {
    assert_param(IS_FDCAN_MAX_VALUE(pTxHeader->Identifier, 0x7FFU));
  }
  else /* pTxHeader->IdType == FDCAN_EXTENDED_ID */
  {
    assert_param(IS_FDCAN_MAX_VALUE(pTxHeader->Identifier, 0x1FFFFFFFU));
  }
  assert_param(IS_FDCAN_FRAME_TYPE(pTxHeader->TxFrameType));
  assert_param(IS_FDCAN_DLC(pTxHeader->DataLength));
  assert_param(IS_FDCAN_ESI(pTxHeader->ErrorStateIndicator));
  assert_param(IS_FDCAN_BRS(pTxHeader->BitRateSwitch));
  assert_param(IS_FDCAN_FDF(pTxHeader->FDFormat));
  assert_param(IS_FDCAN_EFC(pTxHeader->TxEventFifoControl));
  assert_param(IS_FDCAN_MAX_VALUE(pTxHeader->MessageMarker, 0xFFU));

  if (hfdcan->State == HAL_FDCAN_STATE_BUSY)
  {
    /* Check that the Tx FIFO/Queue has an allocated area into the RAM */
    if ((hfdcan->Instance->TXBC & FDCAN_TXBC_TFQS) == 0U)
    {
      /* Update error code */
      hfdcan->ErrorCode |= HAL_FDCAN_ERROR_PARAM;

      return HAL_ERROR;
    }

    /* Check that the Tx FIFO/Queue is not full */
    if ((hfdcan->Instance->TXFQS & FDCAN_TXFQS_TFQF) != 0U)
    {
      /* Update error code */
      hfdcan->ErrorCode |= HAL_FDCAN_ERROR_FIFO_FULL;

      return HAL_ERROR;
    }
    else
    {
      /* Retrieve the Tx FIFO PutIndex */
      PutIndex = ((hfdcan->Instance->TXFQS & FDCAN_TXFQS_TFQPI) >> FDCAN_TXFQS_TFQPI_Pos);

      /* Add the message to the Tx FIFO/Queue */
      FDCAN_CopyMessageToRAM(hfdcan, pTxHeader, pTxData, PutIndex);

      /* Activate the corresponding transmission request */
      hfdcan->Instance->TXBAR = ((uint32_t)1 << PutIndex);

      /* Store the Latest Tx FIFO/Queue Request Buffer Index */
      hfdcan->LatestTxFifoQRequest = ((uint32_t)1 << PutIndex);
    }

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_STARTED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Add a message to a dedicated Tx buffer
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  pTxHeader pointer to a FDCAN_TxHeaderTypeDef structure.
  * @param  pTxData pointer to a buffer containing the payload of the Tx frame.
  * @param  BufferIndex index of the buffer to be configured.
  *         This parameter can be a value of @arg FDCAN_Tx_location.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_AddMessageToTxBuffer(FDCAN_HandleTypeDef *hfdcan, FDCAN_TxHeaderTypeDef *pTxHeader, uint8_t *pTxData, uint32_t BufferIndex)
{
  HAL_FDCAN_StateTypeDef state = hfdcan->State;

  /* Check function parameters */
  assert_param(IS_FDCAN_ID_TYPE(pTxHeader->IdType));
  if (pTxHeader->IdType == FDCAN_STANDARD_ID)
  {
    assert_param(IS_FDCAN_MAX_VALUE(pTxHeader->Identifier, 0x7FFU));
  }
  else /* pTxHeader->IdType == FDCAN_EXTENDED_ID */
  {
    assert_param(IS_FDCAN_MAX_VALUE(pTxHeader->Identifier, 0x1FFFFFFFU));
  }
  assert_param(IS_FDCAN_FRAME_TYPE(pTxHeader->TxFrameType));
  assert_param(IS_FDCAN_DLC(pTxHeader->DataLength));
  assert_param(IS_FDCAN_ESI(pTxHeader->ErrorStateIndicator));
  assert_param(IS_FDCAN_BRS(pTxHeader->BitRateSwitch));
  assert_param(IS_FDCAN_FDF(pTxHeader->FDFormat));
  assert_param(IS_FDCAN_EFC(pTxHeader->TxEventFifoControl));
  assert_param(IS_FDCAN_MAX_VALUE(pTxHeader->MessageMarker, 0xFFU));
  assert_param(IS_FDCAN_TX_LOCATION(BufferIndex));

  if ((state == HAL_FDCAN_STATE_READY) || (state == HAL_FDCAN_STATE_BUSY))
  {
    /* Check that the selected buffer has an allocated area into the RAM */
    if (POSITION_VAL(BufferIndex) >= ((hfdcan->Instance->TXBC & FDCAN_TXBC_NDTB) >> FDCAN_TXBC_NDTB_Pos))
    {
      /* Update error code */
      hfdcan->ErrorCode |= HAL_FDCAN_ERROR_PARAM;

      return HAL_ERROR;
    }

    /* Check that there is no transmission request pending for the selected buffer */
    if ((hfdcan->Instance->TXBRP & BufferIndex) != 0U)
    {
      /* Update error code */
      hfdcan->ErrorCode |= HAL_FDCAN_ERROR_PENDING;

      return HAL_ERROR;
    }
    else
    {
      /* Add the message to the Tx buffer */
      FDCAN_CopyMessageToRAM(hfdcan, pTxHeader, pTxData, POSITION_VAL(BufferIndex));
    }

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_INITIALIZED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Enable transmission request.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  BufferIndex buffer index.
  *         This parameter can be any combination of @arg FDCAN_Tx_location.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_EnableTxBufferRequest(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndex)
{
  if (hfdcan->State == HAL_FDCAN_STATE_BUSY)
  {
    /* Add transmission request */
    hfdcan->Instance->TXBAR = BufferIndex;

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_STARTED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Get Tx buffer index of latest Tx FIFO/Queue request
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval Tx buffer index of last Tx FIFO/Queue request
  *          - Any value of @arg FDCAN_Tx_location if Tx request has been submitted.
  *          - 0 if no Tx FIFO/Queue request have been submitted.
  */
uint32_t HAL_FDCAN_GetLatestTxFifoQRequestBuffer(FDCAN_HandleTypeDef *hfdcan)
{
  /* Return Last Tx FIFO/Queue Request Buffer */
  return hfdcan->LatestTxFifoQRequest;
}

/**
  * @brief  Abort transmission request
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  BufferIndex buffer index.
  *         This parameter can be any combination of @arg FDCAN_Tx_location.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_AbortTxRequest(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndex)
{
  if (hfdcan->State == HAL_FDCAN_STATE_BUSY)
  {
    /* Add cancellation request */
    hfdcan->Instance->TXBCR = BufferIndex;

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_STARTED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Get an FDCAN frame from the Rx Buffer/FIFO zone into the message RAM.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  RxLocation Location of the received message to be read.
  *         This parameter can be a value of @arg FDCAN_Rx_location.
  * @param  pRxHeader pointer to a FDCAN_RxHeaderTypeDef structure.
  * @param  pRxData pointer to a buffer where the payload of the Rx frame will be stored.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_GetRxMessage(FDCAN_HandleTypeDef *hfdcan, uint32_t RxLocation, FDCAN_RxHeaderTypeDef *pRxHeader, uint8_t *pRxData)
{
  uint32_t *RxAddress;
  uint8_t  *pData;
  uint32_t ByteCounter;
  uint32_t GetIndex = 0;
  HAL_FDCAN_StateTypeDef state = hfdcan->State;

  if (state == HAL_FDCAN_STATE_BUSY)
  {
    if (RxLocation == FDCAN_RX_FIFO0) /* Rx element is assigned to the Rx FIFO 0 */
    {
      /* Check that the Rx FIFO 0 has an allocated area into the RAM */
      if ((hfdcan->Instance->RXF0C & FDCAN_RXF0C_F0S) == 0U)
      {
        /* Update error code */
        hfdcan->ErrorCode |= HAL_FDCAN_ERROR_PARAM;

        return HAL_ERROR;
      }

      /* Check that the Rx FIFO 0 is not empty */
      if ((hfdcan->Instance->RXF0S & FDCAN_RXF0S_F0FL) == 0U)
      {
        /* Update error code */
        hfdcan->ErrorCode |= HAL_FDCAN_ERROR_FIFO_EMPTY;

        return HAL_ERROR;
      }
      else
      {
        /* Check that the Rx FIFO 0 is full & overwrite mode is on*/
        if(((hfdcan->Instance->RXF0S & FDCAN_RXF0S_F0F) >> FDCAN_RXF0S_F0F_Pos) == 1U)
        {
          if(((hfdcan->Instance->RXF0C & FDCAN_RXF0C_F0OM) >> FDCAN_RXF0C_F0OM_Pos) == FDCAN_RX_FIFO_OVERWRITE)
          {
            /* When overwrite status is on discard first message in FIFO */
            GetIndex = 1U;
          }
        }

        /* Calculate Rx FIFO 0 element index*/
        GetIndex += ((hfdcan->Instance->RXF0S & FDCAN_RXF0S_F0GI) >> FDCAN_RXF0S_F0GI_Pos);

        /* Calculate Rx FIFO 0 element address */
        RxAddress = (uint32_t *)(hfdcan->msgRam.RxFIFO0SA + (GetIndex * hfdcan->Init.RxFifo0ElmtSize * 4U));
      }
    }
    else if (RxLocation == FDCAN_RX_FIFO1) /* Rx element is assigned to the Rx FIFO 1 */
    {
      /* Check that the Rx FIFO 1 has an allocated area into the RAM */
      if ((hfdcan->Instance->RXF1C & FDCAN_RXF1C_F1S) == 0U)
      {
        /* Update error code */
        hfdcan->ErrorCode |= HAL_FDCAN_ERROR_PARAM;

        return HAL_ERROR;
      }

      /* Check that the Rx FIFO 0 is not empty */
      if ((hfdcan->Instance->RXF1S & FDCAN_RXF1S_F1FL) == 0U)
      {
        /* Update error code */
        hfdcan->ErrorCode |= HAL_FDCAN_ERROR_FIFO_EMPTY;

        return HAL_ERROR;
      }
      else
      {
        /* Check that the Rx FIFO 1 is full & overwrite mode is on*/
        if(((hfdcan->Instance->RXF1S & FDCAN_RXF1S_F1F) >> FDCAN_RXF1S_F1F_Pos) == 1U)
        {
          if(((hfdcan->Instance->RXF1C & FDCAN_RXF1C_F1OM) >> FDCAN_RXF1C_F1OM_Pos) == FDCAN_RX_FIFO_OVERWRITE)
          {
            /* When overwrite status is on discard first message in FIFO */
            GetIndex = 1U;
          }
        }

        /* Calculate Rx FIFO 1 element index*/
        GetIndex += ((hfdcan->Instance->RXF1S & FDCAN_RXF1S_F1GI) >> FDCAN_RXF1S_F1GI_Pos);

        /* Calculate Rx FIFO 1 element address */
        RxAddress = (uint32_t *)(hfdcan->msgRam.RxFIFO1SA + (GetIndex * hfdcan->Init.RxFifo1ElmtSize * 4U));
      }
    }
    else /* Rx element is assigned to a dedicated Rx buffer */
    {
      /* Check that the selected buffer has an allocated area into the RAM */
      if (RxLocation >= hfdcan->Init.RxBuffersNbr)
      {
        /* Update error code */
        hfdcan->ErrorCode |= HAL_FDCAN_ERROR_PARAM;

        return HAL_ERROR;
      }
      else
      {
        /* Calculate Rx buffer address */
        RxAddress = (uint32_t *)(hfdcan->msgRam.RxBufferSA + (RxLocation * hfdcan->Init.RxBufferSize * 4U));
      }
    }

    /* Retrieve IdType */
    pRxHeader->IdType = *RxAddress & FDCAN_ELEMENT_MASK_XTD;

    /* Retrieve Identifier */
    if (pRxHeader->IdType == FDCAN_STANDARD_ID) /* Standard ID element */
    {
      pRxHeader->Identifier = ((*RxAddress & FDCAN_ELEMENT_MASK_STDID) >> 18);
    }
    else /* Extended ID element */
    {
      pRxHeader->Identifier = (*RxAddress & FDCAN_ELEMENT_MASK_EXTID);
    }

    /* Retrieve RxFrameType */
    pRxHeader->RxFrameType = (*RxAddress & FDCAN_ELEMENT_MASK_RTR);

    /* Retrieve ErrorStateIndicator */
    pRxHeader->ErrorStateIndicator = (*RxAddress & FDCAN_ELEMENT_MASK_ESI);

    /* Increment RxAddress pointer to second word of Rx FIFO element */
    RxAddress++;

    /* Retrieve RxTimestamp */
    pRxHeader->RxTimestamp = (*RxAddress & FDCAN_ELEMENT_MASK_TS);

    /* Retrieve DataLength */
    pRxHeader->DataLength = (*RxAddress & FDCAN_ELEMENT_MASK_DLC);

    /* Retrieve BitRateSwitch */
    pRxHeader->BitRateSwitch = (*RxAddress & FDCAN_ELEMENT_MASK_BRS);

    /* Retrieve FDFormat */
    pRxHeader->FDFormat = (*RxAddress & FDCAN_ELEMENT_MASK_FDF);

    /* Retrieve FilterIndex */
    pRxHeader->FilterIndex = ((*RxAddress & FDCAN_ELEMENT_MASK_FIDX) >> 24);

    /* Retrieve NonMatchingFrame */
    pRxHeader->IsFilterMatchingFrame = ((*RxAddress & FDCAN_ELEMENT_MASK_ANMF) >> 31);

    /* Increment RxAddress pointer to payload of Rx FIFO element */
    RxAddress++;

    /* Retrieve Rx payload */
    pData = (uint8_t *)RxAddress;
    for (ByteCounter = 0; ByteCounter < DLCtoBytes[pRxHeader->DataLength >> 16]; ByteCounter++)
    {
      pRxData[ByteCounter] = pData[ByteCounter];
    }

    if (RxLocation == FDCAN_RX_FIFO0) /* Rx element is assigned to the Rx FIFO 0 */
    {
      /* Acknowledge the Rx FIFO 0 that the oldest element is read so that it increments the GetIndex */
      hfdcan->Instance->RXF0A = GetIndex;
    }
    else if (RxLocation == FDCAN_RX_FIFO1) /* Rx element is assigned to the Rx FIFO 1 */
    {
      /* Acknowledge the Rx FIFO 1 that the oldest element is read so that it increments the GetIndex */
      hfdcan->Instance->RXF1A = GetIndex;
    }
    else /* Rx element is assigned to a dedicated Rx buffer */
    {
      /* Clear the New Data flag of the current Rx buffer */
      hfdcan->Instance->NDAT1 = ((uint32_t)1 << RxLocation);
//      if (RxLocation < FDCAN_RX_BUFFER32)
//      {
//        hfdcan->Instance->NDAT1 = ((uint32_t)1 << RxLocation);
//      }
//      else /* FDCAN_RX_BUFFER32 <= RxLocation <= FDCAN_RX_BUFFER63 */
//      {
//        hfdcan->Instance->NDAT2 = ((uint32_t)1 << (RxLocation & 0x1FU));
//      }
    }

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_STARTED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Get an FDCAN Tx event from the Tx Event FIFO zone into the message RAM.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  pTxEvent pointer to a FDCAN_TxEventFifoTypeDef structure.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_GetTxEvent(FDCAN_HandleTypeDef *hfdcan, FDCAN_TxEventFifoTypeDef *pTxEvent)
{
  uint32_t *TxEventAddress;
  uint32_t GetIndex;
  HAL_FDCAN_StateTypeDef state = hfdcan->State;

  /* Check function parameters */
  assert_param(IS_FDCAN_MIN_VALUE(hfdcan->Init.TxEventsNbr, 1U));

  if (state == HAL_FDCAN_STATE_BUSY)
  {
    /* Check that the Tx Event FIFO has an allocated area into the RAM */
    if ((hfdcan->Instance->TXEFC & FDCAN_TXEFC_EFS) == 0U)
    {
      /* Update error code */
      hfdcan->ErrorCode |= HAL_FDCAN_ERROR_PARAM;

      return HAL_ERROR;
    }

    /* Check that the Tx event FIFO is not empty */
    if ((hfdcan->Instance->TXEFS & FDCAN_TXEFS_EFFL) == 0U)
    {
      /* Update error code */
      hfdcan->ErrorCode |= HAL_FDCAN_ERROR_FIFO_EMPTY;

      return HAL_ERROR;
    }

    /* Calculate Tx event FIFO element address */
    GetIndex = ((hfdcan->Instance->TXEFS & FDCAN_TXEFS_EFGI) >> FDCAN_TXEFS_EFGI_Pos);
    TxEventAddress = (uint32_t *)(hfdcan->msgRam.TxEventFIFOSA + (GetIndex * 2U * 4U));

    /* Retrieve IdType */
    pTxEvent->IdType = *TxEventAddress & FDCAN_ELEMENT_MASK_XTD;

    /* Retrieve Identifier */
    if (pTxEvent->IdType == FDCAN_STANDARD_ID) /* Standard ID element */
    {
      pTxEvent->Identifier = ((*TxEventAddress & FDCAN_ELEMENT_MASK_STDID) >> 18U);
    }
    else /* Extended ID element */
    {
      pTxEvent->Identifier = (*TxEventAddress & FDCAN_ELEMENT_MASK_EXTID);
    }

    /* Retrieve TxFrameType */
    pTxEvent->TxFrameType = (*TxEventAddress & FDCAN_ELEMENT_MASK_RTR);

    /* Retrieve ErrorStateIndicator */
    pTxEvent->ErrorStateIndicator = (*TxEventAddress & FDCAN_ELEMENT_MASK_ESI);

    /* Increment TxEventAddress pointer to second word of Tx Event FIFO element */
    TxEventAddress++;

    /* Retrieve TxTimestamp */
    pTxEvent->TxTimestamp = (*TxEventAddress & FDCAN_ELEMENT_MASK_TS);

    /* Retrieve DataLength */
    pTxEvent->DataLength = (*TxEventAddress & FDCAN_ELEMENT_MASK_DLC);

    /* Retrieve BitRateSwitch */
    pTxEvent->BitRateSwitch = (*TxEventAddress & FDCAN_ELEMENT_MASK_BRS);

    /* Retrieve FDFormat */
    pTxEvent->FDFormat = (*TxEventAddress & FDCAN_ELEMENT_MASK_FDF);

    /* Retrieve EventType */
    pTxEvent->EventType = (*TxEventAddress & FDCAN_ELEMENT_MASK_ET);

    /* Retrieve MessageMarker */
    pTxEvent->MessageMarker = ((*TxEventAddress & FDCAN_ELEMENT_MASK_MM) >> 24);

    /* Acknowledge the Tx Event FIFO that the oldest element is read so that it increments the GetIndex */
    hfdcan->Instance->TXEFA = GetIndex;

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_STARTED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Get high priority message status.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  HpMsgStatus pointer to an FDCAN_HpMsgStatusTypeDef structure.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_GetHighPriorityMessageStatus(FDCAN_HandleTypeDef *hfdcan, FDCAN_HpMsgStatusTypeDef *HpMsgStatus)
{
  HpMsgStatus->FilterList = ((hfdcan->Instance->HPMS & FDCAN_HPMS_FLST) >> FDCAN_HPMS_FLST_Pos);
  HpMsgStatus->FilterIndex = ((hfdcan->Instance->HPMS & FDCAN_HPMS_FIDX) >> FDCAN_HPMS_FIDX_Pos);
  HpMsgStatus->MessageStorage = (hfdcan->Instance->HPMS & FDCAN_HPMS_MSI);
  HpMsgStatus->MessageIndex = (hfdcan->Instance->HPMS & FDCAN_HPMS_BIDX);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Get protocol status.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  ProtocolStatus pointer to an FDCAN_ProtocolStatusTypeDef structure.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_GetProtocolStatus(FDCAN_HandleTypeDef *hfdcan, FDCAN_ProtocolStatusTypeDef *ProtocolStatus)
{
  uint32_t StatusReg;

  /* Read the protocol status register */
  StatusReg = READ_REG(hfdcan->Instance->PSR);

  /* Fill the protocol status structure */
  ProtocolStatus->LastErrorCode = (StatusReg & FDCAN_PSR_LEC);
  ProtocolStatus->DataLastErrorCode = ((StatusReg & FDCAN_PSR_DLEC) >> FDCAN_PSR_DLEC_Pos);
  ProtocolStatus->Activity = (StatusReg & FDCAN_PSR_ACT);
  ProtocolStatus->ErrorPassive = ((StatusReg & FDCAN_PSR_EP) >> FDCAN_PSR_EP_Pos);
  ProtocolStatus->Warning = ((StatusReg & FDCAN_PSR_EW) >> FDCAN_PSR_EW_Pos);
  ProtocolStatus->BusOff = ((StatusReg & FDCAN_PSR_BO) >> FDCAN_PSR_BO_Pos);
  ProtocolStatus->RxESIflag = ((StatusReg & FDCAN_PSR_RESI) >> FDCAN_PSR_RESI_Pos);
  ProtocolStatus->RxBRSflag = ((StatusReg & FDCAN_PSR_RBRS) >> FDCAN_PSR_RBRS_Pos);
  ProtocolStatus->RxFDFflag = ((StatusReg & FDCAN_PSR_RFDF) >> FDCAN_PSR_RFDF_Pos);
  ProtocolStatus->ProtocolException = ((StatusReg & FDCAN_PSR_PXE) >> FDCAN_PSR_PXE_Pos);
  ProtocolStatus->TDCvalue = ((StatusReg & FDCAN_PSR_TDCV) >> FDCAN_PSR_TDCV_Pos);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Get error counter values.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  ErrorCounters pointer to an FDCAN_ErrorCountersTypeDef structure.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_GetErrorCounters(FDCAN_HandleTypeDef *hfdcan, FDCAN_ErrorCountersTypeDef *ErrorCounters)
{
  uint32_t CountersReg;

  /* Read the error counters register */
  CountersReg = READ_REG(hfdcan->Instance->ECR);

  /* Fill the error counters structure */
  ErrorCounters->TxErrorCnt = ((CountersReg & FDCAN_ECR_TEC) >> FDCAN_ECR_TEC_Pos);
  ErrorCounters->RxErrorCnt = ((CountersReg & FDCAN_ECR_REC) >> FDCAN_ECR_REC_Pos);
  ErrorCounters->RxErrorPassive = ((CountersReg & FDCAN_ECR_RP) >> FDCAN_ECR_RP_Pos);
  ErrorCounters->ErrorLogging = ((CountersReg & FDCAN_ECR_CEL) >> FDCAN_ECR_CEL_Pos);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Check if a new message is received in the selected Rx buffer.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  RxBufferIndex Rx buffer index.
  *         This parameter must be a number between 0 and 5.
  * @retval Status
  *          - 0 : No new message on RxBufferIndex.
  *          - 1 : New message received on RxBufferIndex.
  */
uint32_t HAL_FDCAN_IsRxBufferMessageAvailable(FDCAN_HandleTypeDef *hfdcan, uint32_t RxBufferIndex)
{
  /* Check function parameters */
  assert_param(IS_FDCAN_MAX_VALUE(RxBufferIndex, 5U));
  uint32_t NewData1 = hfdcan->Instance->NDAT1;
//  uint32_t NewData2 = hfdcan->Instance->NDAT2;

  /* Check new message reception on the selected buffer */
  if ((NewData1 & (uint32_t)((uint32_t)1 << RxBufferIndex)) == 0U)
  {
    return 0;
  }
//  if (((RxBufferIndex < 32U) && ((NewData1 & (uint32_t)((uint32_t)1 << RxBufferIndex)) == 0U)) ||
//      ((RxBufferIndex >= 32U) && ((NewData2 & (uint32_t)((uint32_t)1 << (RxBufferIndex & 0x1FU))) == 0U)))
//  {
//    return 0;
//  }

  /* Clear the New Data flag of the current Rx buffer */
  hfdcan->Instance->NDAT1 = ((uint32_t)1 << RxBufferIndex);
//  if (RxBufferIndex < 32U)
//  {
//    hfdcan->Instance->NDAT1 = ((uint32_t)1 << RxBufferIndex);
//  }
//  else /* 32 <= RxBufferIndex <= 63 */
//  {
//    hfdcan->Instance->NDAT2 = ((uint32_t)1 << (RxBufferIndex & 0x1FU));
//  }

  return 1;
}

/**
  * @brief  Check if a transmission request is pending on the selected Tx buffer.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  TxBufferIndex Tx buffer index.
  *         This parameter can be any combination of @arg FDCAN_Tx_location.
  * @retval Status
  *          - 0 : No pending transmission request on TxBufferIndex.
  *          - 1 : Pending transmission request on TxBufferIndex.
  */
uint32_t HAL_FDCAN_IsTxBufferMessagePending(FDCAN_HandleTypeDef *hfdcan, uint32_t TxBufferIndex)
{
  /* Check pending transmission request on the selected buffer */
  if ((hfdcan->Instance->TXBRP & TxBufferIndex) == 0U)
  {
    return 0;
  }
  return 1;
}

/**
  * @brief  Return Rx FIFO fill level.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  RxFifo Rx FIFO.
  *         This parameter can be one of the following values:
  *           @arg FDCAN_RX_FIFO0: Rx FIFO 0
  *           @arg FDCAN_RX_FIFO1: Rx FIFO 1
  * @retval Level Rx FIFO fill level.
  */
uint32_t HAL_FDCAN_GetRxFifoFillLevel(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo)
{
  uint32_t FillLevel;

  /* Check function parameters */
  assert_param(IS_FDCAN_RX_FIFO(RxFifo));

  if (RxFifo == FDCAN_RX_FIFO0)
  {
    FillLevel = hfdcan->Instance->RXF0S & FDCAN_RXF0S_F0FL;
  }
  else /* RxFifo == FDCAN_RX_FIFO1 */
  {
    FillLevel = hfdcan->Instance->RXF1S & FDCAN_RXF1S_F1FL;
  }

  /* Return Rx FIFO fill level */
  return FillLevel;
}

/**
  * @brief  Return Tx FIFO free level: number of consecutive free Tx FIFO
  *         elements starting from Tx FIFO GetIndex.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval Level Tx FIFO free level.
  */
uint32_t HAL_FDCAN_GetTxFifoFreeLevel(FDCAN_HandleTypeDef *hfdcan)
{
  uint32_t FreeLevel;

  FreeLevel = hfdcan->Instance->TXFQS & FDCAN_TXFQS_TFFL;

  /* Return Tx FIFO free level */
  return FreeLevel;
}

/**
  * @brief  Check if the FDCAN peripheral entered Restricted Operation Mode.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval Status
  *          - 0 : Normal FDCAN operation.
  *          - 1 : Restricted Operation Mode active.
  */
uint32_t HAL_FDCAN_IsRestrictedOperationMode(FDCAN_HandleTypeDef *hfdcan)
{
  uint32_t OperationMode;

  /* Get Operation Mode */
  OperationMode = ((hfdcan->Instance->CCCR & FDCAN_CCCR_ASM) >> FDCAN_CCCR_ASM_Pos);

  return OperationMode;
}

/**
  * @brief  Exit Restricted Operation Mode.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ExitRestrictedOperationMode(FDCAN_HandleTypeDef *hfdcan)
{
  HAL_FDCAN_StateTypeDef state = hfdcan->State;

  if ((state == HAL_FDCAN_STATE_READY) || (state == HAL_FDCAN_STATE_BUSY))
  {
    /* Exit Restricted Operation mode */
    CLEAR_BIT(hfdcan->Instance->CCCR, FDCAN_CCCR_ASM);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_INITIALIZED;

    return HAL_ERROR;
  }
}

/**
  * @}
  */

/** @defgroup FDCAN_Exported_Functions_Group5 Interrupts management
 *  @brief    Interrupts management
 *
@verbatim
  ==============================================================================
                       ##### Interrupts management #####
  ==============================================================================
    [..]  This section provides functions allowing to:
      (+) HAL_FDCAN_ConfigInterruptLines      : Assign interrupts to either Interrupt line 0 or 1
      (+) HAL_FDCAN_ActivateNotification      : Enable interrupts
      (+) HAL_FDCAN_DeactivateNotification    : Disable interrupts
      (+) HAL_FDCAN_IRQHandler                : Handles FDCAN interrupt request

@endverbatim
  * @{
  */

/**
  * @brief  Assign interrupts to either Interrupt line 0 or 1.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  ITList indicates which interrupts will be assigned to the selected interrupt line.
  *         This parameter can be any combination of @arg FDCAN_Interrupts.
  * @param  InterruptLine Interrupt line.
  *         This parameter can be a value of @arg FDCAN_Interrupt_Line.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ConfigInterruptLines(FDCAN_HandleTypeDef *hfdcan, uint32_t ITList, uint32_t InterruptLine)
{
  HAL_FDCAN_StateTypeDef state = hfdcan->State;

  /* Check function parameters */
  assert_param(IS_FDCAN_IT(ITList));
  assert_param(IS_FDCAN_IT_LINE(InterruptLine));

  if ((state == HAL_FDCAN_STATE_READY) || (state == HAL_FDCAN_STATE_BUSY))
  {
    /* Assign list of interrupts to the selected line */
    if (InterruptLine == FDCAN_INTERRUPT_LINE0)
    {
      CLEAR_BIT(hfdcan->Instance->ILS, ITList);
    }
    else /* InterruptLine == FDCAN_INTERRUPT_LINE1 */
    {
      SET_BIT(hfdcan->Instance->ILS, ITList);
    }

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_INITIALIZED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Enable interrupts.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  ActiveITs indicates which interrupts will be enabled.
  *         This parameter can be any combination of @arg FDCAN_Interrupts.
  * @param  BufferIndexes Tx Buffer Indexes.
  *         This parameter can be any combination of @arg FDCAN_Tx_location.
  *         This parameter is ignored if ActiveITs does not include one of the following:
  *           - FDCAN_IT_TX_COMPLETE
  *           - FDCAN_IT_TX_ABORT_COMPLETE
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_ActivateNotification(FDCAN_HandleTypeDef *hfdcan, uint32_t ActiveITs, uint32_t BufferIndexes)
{
  HAL_FDCAN_StateTypeDef state = hfdcan->State;

  /* Check function parameters */
  assert_param(IS_FDCAN_IT(ActiveITs));

  if ((state == HAL_FDCAN_STATE_READY) || (state == HAL_FDCAN_STATE_BUSY))
  {
    /* Enable Interrupt lines */
    if ((ActiveITs & hfdcan->Instance->ILS) == 0U)
    {
      /* Enable Interrupt line 0 */
      SET_BIT(hfdcan->Instance->ILE, FDCAN_INTERRUPT_LINE0);
    }
    else if ((ActiveITs & hfdcan->Instance->ILS) == ActiveITs)
    {
      /* Enable Interrupt line 1 */
      SET_BIT(hfdcan->Instance->ILE, FDCAN_INTERRUPT_LINE1);
    }
    else
    {
      /* Enable Interrupt lines 0 and 1 */
      hfdcan->Instance->ILE = (FDCAN_INTERRUPT_LINE0 | FDCAN_INTERRUPT_LINE1);
    }

    if ((ActiveITs & FDCAN_IT_TX_COMPLETE) != 0U)
    {
      /* Enable Tx Buffer Transmission Interrupt to set TC flag in IR register,
         but interrupt will only occur if TC is enabled in IE register */
      SET_BIT(hfdcan->Instance->TXBTIE, BufferIndexes);
    }

    if ((ActiveITs & FDCAN_IT_TX_ABORT_COMPLETE) != 0U)
    {
      /* Enable Tx Buffer Cancellation Finished Interrupt to set TCF flag in IR register,
         but interrupt will only occur if TCF is enabled in IE register */
      SET_BIT(hfdcan->Instance->TXBCIE, BufferIndexes);
    }

    /* Enable the selected interrupts */
    __HAL_FDCAN_ENABLE_IT(hfdcan, ActiveITs);

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_INITIALIZED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Disable interrupts.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  InactiveITs indicates which interrupts will be disabled.
  *         This parameter can be any combination of @arg FDCAN_Interrupts.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_FDCAN_DeactivateNotification(FDCAN_HandleTypeDef *hfdcan, uint32_t InactiveITs)
{
  uint32_t ITLineSelection;
  HAL_FDCAN_StateTypeDef state = hfdcan->State;

  /* Check function parameters */
  assert_param(IS_FDCAN_IT(InactiveITs));

  if ((state == HAL_FDCAN_STATE_READY) || (state == HAL_FDCAN_STATE_BUSY))
  {
    /* Disable the selected interrupts */
    __HAL_FDCAN_DISABLE_IT(hfdcan, InactiveITs);

    if ((InactiveITs & FDCAN_IT_TX_COMPLETE) != 0U)
    {
      /* Disable Tx Buffer Transmission Interrupts */
      CLEAR_REG(hfdcan->Instance->TXBTIE);
    }

    if ((InactiveITs & FDCAN_IT_TX_ABORT_COMPLETE) != 0U)
    {
      /* Disable Tx Buffer Cancellation Finished Interrupt */
      CLEAR_REG(hfdcan->Instance->TXBCIE);
    }

    ITLineSelection = hfdcan->Instance->ILS;

    if ((hfdcan->Instance->IE | ITLineSelection) == ITLineSelection)
    {
      /* Disable Interrupt line 0 */
      CLEAR_BIT(hfdcan->Instance->ILE, FDCAN_INTERRUPT_LINE0);
    }

    if ((hfdcan->Instance->IE & ITLineSelection) == 0U)
    {
      /* Disable Interrupt line 1 */
      CLEAR_BIT(hfdcan->Instance->ILE, FDCAN_INTERRUPT_LINE1);
    }

    /* Return function status */
    return HAL_OK;
  }
  else
  {
    /* Update error code */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_NOT_INITIALIZED;

    return HAL_ERROR;
  }
}

/**
  * @brief  Handles FDCAN interrupt request.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
  */
void HAL_FDCAN_IRQHandler(FDCAN_HandleTypeDef *hfdcan)
{
  uint32_t TxEventFifoITs;
  uint32_t RxFifo0ITs;
  uint32_t RxFifo1ITs;
  uint32_t Errors;
  uint32_t ErrorStatusITs;
  uint32_t TransmittedBuffers;
  uint32_t AbortedBuffers;
  uint32_t itsourceIE;
  uint32_t itflagIR;

  TxEventFifoITs = hfdcan->Instance->IR & FDCAN_TX_EVENT_FIFO_MASK;
  TxEventFifoITs &= hfdcan->Instance->IE;
  RxFifo0ITs = hfdcan->Instance->IR & FDCAN_RX_FIFO0_MASK;
  RxFifo0ITs &= hfdcan->Instance->IE;
  RxFifo1ITs = hfdcan->Instance->IR & FDCAN_RX_FIFO1_MASK;
  RxFifo1ITs &= hfdcan->Instance->IE;
  Errors = hfdcan->Instance->IR & FDCAN_ERROR_MASK;
  Errors &= hfdcan->Instance->IE;
  ErrorStatusITs = hfdcan->Instance->IR & FDCAN_ERROR_STATUS_MASK;
  ErrorStatusITs &= hfdcan->Instance->IE;
  itsourceIE = hfdcan->Instance->IE;
  itflagIR = hfdcan->Instance->IR;

  /* High Priority Message interrupt management *******************************/
  if (FDCAN_CHECK_IT_SOURCE(itsourceIE, FDCAN_IT_RX_HIGH_PRIORITY_MSG) != RESET)
  {
    if (FDCAN_CHECK_FLAG(itflagIR, FDCAN_FLAG_RX_HIGH_PRIORITY_MSG) != RESET)
    {
      /* Clear the High Priority Message flag */
      __HAL_FDCAN_CLEAR_FLAG(hfdcan, FDCAN_FLAG_RX_HIGH_PRIORITY_MSG);

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
      /* Call registered callback*/
      hfdcan->HighPriorityMessageCallback(hfdcan);
#else
      /* High Priority Message Callback */
      HAL_FDCAN_HighPriorityMessageCallback(hfdcan);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
    }
  }

  /* Transmission Abort interrupt management **********************************/
  if (FDCAN_CHECK_IT_SOURCE(itsourceIE, FDCAN_IT_TX_ABORT_COMPLETE) != RESET)
  {
    if (FDCAN_CHECK_FLAG(itflagIR, FDCAN_FLAG_TX_ABORT_COMPLETE) != RESET)
    {
      /* List of aborted monitored buffers */
      AbortedBuffers = hfdcan->Instance->TXBCF;
      AbortedBuffers &= hfdcan->Instance->TXBCIE;

      /* Clear the Transmission Cancellation flag */
      __HAL_FDCAN_CLEAR_FLAG(hfdcan, FDCAN_FLAG_TX_ABORT_COMPLETE);

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
      /* Call registered callback*/
      hfdcan->TxBufferAbortCallback(hfdcan, AbortedBuffers);
#else
      /* Transmission Cancellation Callback */
      HAL_FDCAN_TxBufferAbortCallback(hfdcan, AbortedBuffers);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
    }
  }

  /* Tx event FIFO interrupts management **************************************/
  if (TxEventFifoITs != 0U)
  {
    /* Clear the Tx Event FIFO flags */
    __HAL_FDCAN_CLEAR_FLAG(hfdcan, TxEventFifoITs);

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
    /* Call registered callback*/
    hfdcan->TxEventFifoCallback(hfdcan, TxEventFifoITs);
#else
    /* Tx Event FIFO Callback */
    HAL_FDCAN_TxEventFifoCallback(hfdcan, TxEventFifoITs);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
  }

  /* Rx FIFO 0 interrupts management ******************************************/
  if (RxFifo0ITs != 0U)
  {
    /* Clear the Rx FIFO 0 flags */
    __HAL_FDCAN_CLEAR_FLAG(hfdcan, RxFifo0ITs);

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
    /* Call registered callback*/
    hfdcan->RxFifo0Callback(hfdcan, RxFifo0ITs);
#else
    /* Rx FIFO 0 Callback */
    HAL_FDCAN_RxFifo0Callback(hfdcan, RxFifo0ITs);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
  }

  /* Rx FIFO 1 interrupts management ******************************************/
  if (RxFifo1ITs != 0U)
  {
    /* Clear the Rx FIFO 1 flags */
    __HAL_FDCAN_CLEAR_FLAG(hfdcan, RxFifo1ITs);

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
    /* Call registered callback*/
    hfdcan->RxFifo1Callback(hfdcan, RxFifo1ITs);
#else
    /* Rx FIFO 1 Callback */
    HAL_FDCAN_RxFifo1Callback(hfdcan, RxFifo1ITs);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
  }

  /* Tx FIFO empty interrupt management ***************************************/
  if (FDCAN_CHECK_IT_SOURCE(itsourceIE, FDCAN_IT_TX_FIFO_EMPTY) != RESET)
  {
    if (FDCAN_CHECK_FLAG(itflagIR, FDCAN_FLAG_TX_FIFO_EMPTY) != RESET)
    {
      /* Clear the Tx FIFO empty flag */
      __HAL_FDCAN_CLEAR_FLAG(hfdcan, FDCAN_FLAG_TX_FIFO_EMPTY);

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
      /* Call registered callback*/
      hfdcan->TxFifoEmptyCallback(hfdcan);
#else
      /* Tx FIFO empty Callback */
      HAL_FDCAN_TxFifoEmptyCallback(hfdcan);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
    }
  }

  /* Transmission Complete interrupt management *******************************/
  if (FDCAN_CHECK_IT_SOURCE(itsourceIE, FDCAN_IT_TX_COMPLETE) != RESET)
  {
    if (FDCAN_CHECK_FLAG(itflagIR, FDCAN_FLAG_TX_COMPLETE) != RESET)
    {
      /* List of transmitted monitored buffers */
      TransmittedBuffers = hfdcan->Instance->TXBTO;
      TransmittedBuffers &= hfdcan->Instance->TXBTIE;

      /* Clear the Transmission Complete flag */
      __HAL_FDCAN_CLEAR_FLAG(hfdcan, FDCAN_FLAG_TX_COMPLETE);

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
      /* Call registered callback*/
      hfdcan->TxBufferCompleteCallback(hfdcan, TransmittedBuffers);
#else
      /* Transmission Complete Callback */
      HAL_FDCAN_TxBufferCompleteCallback(hfdcan, TransmittedBuffers);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
    }
  }

  /* Rx Buffer New Message interrupt management *******************************/
  if (FDCAN_CHECK_IT_SOURCE(itsourceIE, FDCAN_IT_RX_BUFFER_NEW_MESSAGE) != RESET)
  {
    if (FDCAN_CHECK_FLAG(itflagIR, FDCAN_FLAG_RX_BUFFER_NEW_MESSAGE) != RESET)
    {
      /* Clear the Rx Buffer New Message flag */
      __HAL_FDCAN_CLEAR_FLAG(hfdcan, FDCAN_FLAG_RX_BUFFER_NEW_MESSAGE);

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
      /* Call registered callback*/
      hfdcan->RxBufferNewMessageCallback(hfdcan);
#else
      /* Rx Buffer New Message Callback */
      HAL_FDCAN_RxBufferNewMessageCallback(hfdcan);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
    }
  }

  /* Timestamp Wraparound interrupt management ********************************/
  if (FDCAN_CHECK_IT_SOURCE(itsourceIE, FDCAN_IT_TIMESTAMP_WRAPAROUND) != RESET)
  {
    if (FDCAN_CHECK_FLAG(itflagIR, FDCAN_FLAG_TIMESTAMP_WRAPAROUND) != RESET)
    {
      /* Clear the Timestamp Wraparound flag */
      __HAL_FDCAN_CLEAR_FLAG(hfdcan, FDCAN_FLAG_TIMESTAMP_WRAPAROUND);

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
      /* Call registered callback*/
      hfdcan->TimestampWraparoundCallback(hfdcan);
#else
      /* Timestamp Wraparound Callback */
      HAL_FDCAN_TimestampWraparoundCallback(hfdcan);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
    }
  }

  /* Timeout Occurred interrupt management ************************************/
  if (FDCAN_CHECK_IT_SOURCE(itsourceIE, FDCAN_IT_TIMEOUT_OCCURRED) != RESET)
  {
    if (FDCAN_CHECK_FLAG(itflagIR, FDCAN_FLAG_TIMEOUT_OCCURRED) != RESET)
    {
      /* Clear the Timeout Occurred flag */
      __HAL_FDCAN_CLEAR_FLAG(hfdcan, FDCAN_FLAG_TIMEOUT_OCCURRED);

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
      /* Call registered callback*/
      hfdcan->TimeoutOccurredCallback(hfdcan);
#else
      /* Timeout Occurred Callback */
      HAL_FDCAN_TimeoutOccurredCallback(hfdcan);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
    }
  }

  /* Message RAM access failure interrupt management **************************/
  if (FDCAN_CHECK_IT_SOURCE(itsourceIE, FDCAN_IT_RAM_ACCESS_FAILURE) != RESET)
  {
    if (FDCAN_CHECK_FLAG(itflagIR, FDCAN_FLAG_RAM_ACCESS_FAILURE) != RESET)
    {
      /* Clear the Message RAM access failure flag */
      __HAL_FDCAN_CLEAR_FLAG(hfdcan, FDCAN_FLAG_RAM_ACCESS_FAILURE);

      /* Update error code */
      hfdcan->ErrorCode |= HAL_FDCAN_ERROR_RAM_ACCESS;
    }
  }

  /* Error Status interrupts management ***************************************/
  if (ErrorStatusITs != 0U)
  {
    /* Clear the Error flags */
    __HAL_FDCAN_CLEAR_FLAG(hfdcan, ErrorStatusITs);

#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
    /* Call registered callback*/
    hfdcan->ErrorStatusCallback(hfdcan, ErrorStatusITs);
#else
    /* Error Status Callback */
    HAL_FDCAN_ErrorStatusCallback(hfdcan, ErrorStatusITs);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
  }

  /* Error interrupts management **********************************************/
  if (Errors != 0U)
  {
    /* Clear the Error flags */
    __HAL_FDCAN_CLEAR_FLAG(hfdcan, Errors);

    /* Update error code */
    hfdcan->ErrorCode |= Errors;
  }

  if (hfdcan->ErrorCode != HAL_FDCAN_ERROR_NONE)
  {
#if USE_HAL_FDCAN_REGISTER_CALLBACKS == 1
    /* Call registered callback*/
    hfdcan->ErrorCallback(hfdcan);
#else
    /* Error Callback */
    HAL_FDCAN_ErrorCallback(hfdcan);
#endif /* USE_HAL_FDCAN_REGISTER_CALLBACKS */
  }
}

/**
  * @}
  */

/** @defgroup FDCAN_Exported_Functions_Group6 Callback functions
 *  @brief   FDCAN Callback functions
 *
@verbatim
  ==============================================================================
                          ##### Callback functions #####
  ==============================================================================
    [..]
    This subsection provides the following callback functions:
      (+) HAL_FDCAN_TxEventFifoCallback
      (+) HAL_FDCAN_RxFifo0Callback
      (+) HAL_FDCAN_RxFifo1Callback
      (+) HAL_FDCAN_TxFifoEmptyCallback
      (+) HAL_FDCAN_TxBufferCompleteCallback
      (+) HAL_FDCAN_TxBufferAbortCallback
      (+) HAL_FDCAN_RxBufferNewMessageCallback
      (+) HAL_FDCAN_HighPriorityMessageCallback
      (+) HAL_FDCAN_TimestampWraparoundCallback
      (+) HAL_FDCAN_TimeoutOccurredCallback
      (+) HAL_FDCAN_ErrorCallback
      (+) HAL_FDCAN_ErrorStatusCallback

@endverbatim
  * @{
  */

/**
  * @brief  Tx Event callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  TxEventFifoITs indicates which Tx Event FIFO interrupts are signaled.
  *         This parameter can be any combination of @arg FDCAN_Tx_Event_Fifo_Interrupts.
  * @retval None
  */
__weak void HAL_FDCAN_TxEventFifoCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t TxEventFifoITs)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);
  UNUSED(TxEventFifoITs);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_TxEventFifoCallback could be implemented in the user file
   */
}

/**
  * @brief  Rx FIFO 0 callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  RxFifo0ITs indicates which Rx FIFO 0 interrupts are signaled.
  *         This parameter can be any combination of @arg FDCAN_Rx_Fifo0_Interrupts.
  * @retval None
  */
__weak void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);
  UNUSED(RxFifo0ITs);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_RxFifo0Callback could be implemented in the user file
   */
}

/**
  * @brief  Rx FIFO 1 callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  RxFifo1ITs indicates which Rx FIFO 1 interrupts are signaled.
  *         This parameter can be any combination of @arg FDCAN_Rx_Fifo1_Interrupts.
  * @retval None
  */
__weak void HAL_FDCAN_RxFifo1Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo1ITs)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);
  UNUSED(RxFifo1ITs);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_RxFifo1Callback could be implemented in the user file
   */
}

/**
  * @brief  Tx FIFO Empty callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval None
  */
__weak void HAL_FDCAN_TxFifoEmptyCallback(FDCAN_HandleTypeDef *hfdcan)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_TxFifoEmptyCallback could be implemented in the user file
   */
}

/**
  * @brief  Transmission Complete callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  BufferIndexes Indexes of the transmitted buffers.
  *         This parameter can be any combination of @arg FDCAN_Tx_location.
  * @retval None
  */
__weak void HAL_FDCAN_TxBufferCompleteCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndexes)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);
  UNUSED(BufferIndexes);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_TxBufferCompleteCallback could be implemented in the user file
   */
}

/**
  * @brief  Transmission Cancellation callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  BufferIndexes Indexes of the aborted buffers.
  *         This parameter can be any combination of @arg FDCAN_Tx_location.
  * @retval None
  */
__weak void HAL_FDCAN_TxBufferAbortCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndexes)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);
  UNUSED(BufferIndexes);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_TxBufferAbortCallback could be implemented in the user file
   */
}

/**
  * @brief  Rx Buffer New Message callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval None
  */
__weak void HAL_FDCAN_RxBufferNewMessageCallback(FDCAN_HandleTypeDef *hfdcan)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_RxBufferNewMessageCallback could be implemented in the user file
   */
}

/**
  * @brief  Timestamp Wraparound callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval None
  */
__weak void HAL_FDCAN_TimestampWraparoundCallback(FDCAN_HandleTypeDef *hfdcan)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_TimestampWraparoundCallback could be implemented in the user file
   */
}

/**
  * @brief  Timeout Occurred callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval None
  */
__weak void HAL_FDCAN_TimeoutOccurredCallback(FDCAN_HandleTypeDef *hfdcan)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_TimeoutOccurredCallback could be implemented in the user file
   */
}

/**
  * @brief  High Priority Message callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval None
  */
__weak void HAL_FDCAN_HighPriorityMessageCallback(FDCAN_HandleTypeDef *hfdcan)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_HighPriorityMessageCallback could be implemented in the user file
   */
}

/**
  * @brief  Error callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval None
  */
__weak void HAL_FDCAN_ErrorCallback(FDCAN_HandleTypeDef *hfdcan)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_ErrorCallback could be implemented in the user file
   */
}

/**
  * @brief  Error status callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  ErrorStatusITs indicates which Error Status interrupts are signaled.
  *         This parameter can be any combination of @arg FDCAN_Error_Status_Interrupts.
  * @retval None
  */
__weak void HAL_FDCAN_ErrorStatusCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t ErrorStatusITs)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hfdcan);
  UNUSED(ErrorStatusITs);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FDCAN_ErrorStatusCallback could be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup FDCAN_Exported_Functions_Group7 Peripheral State functions
 *  @brief   FDCAN Peripheral State functions
 *
@verbatim
  ==============================================================================
                      ##### Peripheral State functions #####
  ==============================================================================
    [..]
    This subsection provides functions allowing to :
      (+) HAL_FDCAN_GetState()  : Return the FDCAN state.
      (+) HAL_FDCAN_GetError()  : Return the FDCAN error code if any.

@endverbatim
  * @{
  */
/**
  * @brief  Return the FDCAN state
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL state
  */
HAL_FDCAN_StateTypeDef HAL_FDCAN_GetState(FDCAN_HandleTypeDef *hfdcan)
{
  /* Return FDCAN state */
  return hfdcan->State;
}

/**
  * @brief  Return the FDCAN error code
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval FDCAN Error Code
  */
uint32_t HAL_FDCAN_GetError(FDCAN_HandleTypeDef *hfdcan)
{
  /* Return FDCAN error code */
  return hfdcan->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup FDCAN_Private_Functions
  * @{
  */

/**
  * @brief  Calculate each RAM block start address and size
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @retval HAL status
 */
static HAL_StatusTypeDef FDCAN_CalcultateRamBlockAddresses(FDCAN_HandleTypeDef *hfdcan)
{
  uint32_t RAMcounter;
  uint32_t StartAddress;

  StartAddress = hfdcan->Init.MessageRAMOffset;

  /* Standard filter list start address */
  MODIFY_REG(hfdcan->Instance->SIDFC, FDCAN_SIDFC_FLSSA, (StartAddress << FDCAN_SIDFC_FLSSA_Pos));

  /* Standard filter elements number */
  MODIFY_REG(hfdcan->Instance->SIDFC, FDCAN_SIDFC_LSS, (hfdcan->Init.StdFiltersNbr << FDCAN_SIDFC_LSS_Pos));

  /* Extended filter list start address */
  StartAddress += hfdcan->Init.StdFiltersNbr;
  MODIFY_REG(hfdcan->Instance->XIDFC, FDCAN_XIDFC_FLESA, (StartAddress << FDCAN_XIDFC_FLESA_Pos));

  /* Extended filter elements number */
  MODIFY_REG(hfdcan->Instance->XIDFC, FDCAN_XIDFC_LSE, (hfdcan->Init.ExtFiltersNbr << FDCAN_XIDFC_LSE_Pos));

  /* Rx FIFO 0 start address */
  StartAddress += (hfdcan->Init.ExtFiltersNbr * 2U);
  MODIFY_REG(hfdcan->Instance->RXF0C, FDCAN_RXF0C_F0SA, (StartAddress << FDCAN_RXF0C_F0SA_Pos));

  /* Rx FIFO 0 elements number */
  MODIFY_REG(hfdcan->Instance->RXF0C, FDCAN_RXF0C_F0S, (hfdcan->Init.RxFifo0ElmtsNbr << FDCAN_RXF0C_F0S_Pos));

  /* Rx FIFO 1 start address */
  StartAddress += (hfdcan->Init.RxFifo0ElmtsNbr * hfdcan->Init.RxFifo0ElmtSize);
  MODIFY_REG(hfdcan->Instance->RXF1C, FDCAN_RXF1C_F1SA, (StartAddress << FDCAN_RXF1C_F1SA_Pos));

  /* Rx FIFO 1 elements number */
  MODIFY_REG(hfdcan->Instance->RXF1C, FDCAN_RXF1C_F1S, (hfdcan->Init.RxFifo1ElmtsNbr << FDCAN_RXF1C_F1S_Pos));

  /* Rx buffer list start address */
  StartAddress += (hfdcan->Init.RxFifo1ElmtsNbr * hfdcan->Init.RxFifo1ElmtSize);
  MODIFY_REG(hfdcan->Instance->RXBC, FDCAN_RXBC_RBSA, (StartAddress << FDCAN_RXBC_RBSA_Pos));

  /* Tx event FIFO start address */
  StartAddress += (hfdcan->Init.RxBuffersNbr * hfdcan->Init.RxBufferSize);
  MODIFY_REG(hfdcan->Instance->TXEFC, FDCAN_TXEFC_EFSA, (StartAddress << FDCAN_TXEFC_EFSA_Pos));

  /* Tx event FIFO elements number */
  MODIFY_REG(hfdcan->Instance->TXEFC, FDCAN_TXEFC_EFS, (hfdcan->Init.TxEventsNbr << FDCAN_TXEFC_EFS_Pos));

  /* Tx buffer list start address */
  StartAddress += (hfdcan->Init.TxEventsNbr * 2U);
  MODIFY_REG(hfdcan->Instance->TXBC, FDCAN_TXBC_TBSA, (StartAddress << FDCAN_TXBC_TBSA_Pos));

  /* Dedicated Tx buffers number */
  MODIFY_REG(hfdcan->Instance->TXBC, FDCAN_TXBC_NDTB, (hfdcan->Init.TxBuffersNbr << FDCAN_TXBC_NDTB_Pos));

  /* Tx FIFO/queue elements number */
  MODIFY_REG(hfdcan->Instance->TXBC, FDCAN_TXBC_TFQS, (hfdcan->Init.TxFifoQueueElmtsNbr << FDCAN_TXBC_TFQS_Pos));

  hfdcan->msgRam.StandardFilterSA = SRAMCAN_BASE + (hfdcan->Init.MessageRAMOffset * 4U);
  hfdcan->msgRam.ExtendedFilterSA = hfdcan->msgRam.StandardFilterSA + (hfdcan->Init.StdFiltersNbr * 4U);
  hfdcan->msgRam.RxFIFO0SA = hfdcan->msgRam.ExtendedFilterSA + (hfdcan->Init.ExtFiltersNbr * 2U * 4U);
  hfdcan->msgRam.RxFIFO1SA = hfdcan->msgRam.RxFIFO0SA + (hfdcan->Init.RxFifo0ElmtsNbr * hfdcan->Init.RxFifo0ElmtSize * 4U);
  hfdcan->msgRam.RxBufferSA = hfdcan->msgRam.RxFIFO1SA + (hfdcan->Init.RxFifo1ElmtsNbr * hfdcan->Init.RxFifo1ElmtSize * 4U);
  hfdcan->msgRam.TxEventFIFOSA = hfdcan->msgRam.RxBufferSA + (hfdcan->Init.RxBuffersNbr * hfdcan->Init.RxBufferSize * 4U);
  hfdcan->msgRam.TxBufferSA = hfdcan->msgRam.TxEventFIFOSA + (hfdcan->Init.TxEventsNbr * 2U * 4U);
  hfdcan->msgRam.TxFIFOQSA = hfdcan->msgRam.TxBufferSA + (hfdcan->Init.TxBuffersNbr * hfdcan->Init.TxElmtSize * 4U);

  hfdcan->msgRam.EndAddress = hfdcan->msgRam.TxFIFOQSA + (hfdcan->Init.TxFifoQueueElmtsNbr * hfdcan->Init.TxElmtSize * 4U);

  if (hfdcan->msgRam.EndAddress > FDCAN_MESSAGE_RAM_END_ADDRESS) /* Last address of the Message RAM */
  {
    /* Update error code.
       Message RAM overflow */
    hfdcan->ErrorCode |= HAL_FDCAN_ERROR_PARAM;

    /* Change FDCAN state */
    hfdcan->State = HAL_FDCAN_STATE_ERROR;

    return HAL_ERROR;
  }
  else
  {
    /* Flush the allocated Message RAM area */
    for (RAMcounter = hfdcan->msgRam.StandardFilterSA; RAMcounter < hfdcan->msgRam.EndAddress; RAMcounter += 4U)
    {
      *(uint32_t *)(RAMcounter) = 0x00000000;
    }
  }

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Copy Tx message to the message RAM.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  pTxHeader pointer to a FDCAN_TxHeaderTypeDef structure.
  * @param  pTxData pointer to a buffer containing the payload of the Tx frame.
  * @param  BufferIndex index of the buffer to be configured.
  * @retval HAL status
 */
static void FDCAN_CopyMessageToRAM(FDCAN_HandleTypeDef *hfdcan, FDCAN_TxHeaderTypeDef *pTxHeader, uint8_t *pTxData, uint32_t BufferIndex)
{
  uint32_t TxElementW1;
  uint32_t TxElementW2;
  uint32_t *TxAddress;
  uint32_t ByteCounter;

  /* Build first word of Tx header element */
  if (pTxHeader->IdType == FDCAN_STANDARD_ID)
  {
    TxElementW1 = (pTxHeader->ErrorStateIndicator |
                   FDCAN_STANDARD_ID |
                   pTxHeader->TxFrameType |
                   (pTxHeader->Identifier << 18));
  }
  else /* pTxHeader->IdType == FDCAN_EXTENDED_ID */
  {
    TxElementW1 = (pTxHeader->ErrorStateIndicator |
                   FDCAN_EXTENDED_ID |
                   pTxHeader->TxFrameType |
                   pTxHeader->Identifier);
  }

  /* Build second word of Tx header element */
  TxElementW2 = ((pTxHeader->MessageMarker << 24) |
                 pTxHeader->TxEventFifoControl |
                 pTxHeader->FDFormat |
                 pTxHeader->BitRateSwitch |
                 pTxHeader->DataLength);

  /* Calculate Tx element address */
  TxAddress = (uint32_t *)(hfdcan->msgRam.TxBufferSA + (BufferIndex * hfdcan->Init.TxElmtSize * 4U));

  /* Write Tx element header to the message RAM */
  *TxAddress = TxElementW1;
  TxAddress++;
  *TxAddress = TxElementW2;
  TxAddress++;

  /* Write Tx payload to the message RAM */
  for (ByteCounter = 0; ByteCounter < DLCtoBytes[pTxHeader->DataLength >> 16]; ByteCounter += 4U)
  {
    *TxAddress = (((uint32_t)pTxData[ByteCounter + 3U] << 24) |
                  ((uint32_t)pTxData[ByteCounter + 2U] << 16) |
                  ((uint32_t)pTxData[ByteCounter + 1U] << 8) |
                  (uint32_t)pTxData[ByteCounter]);
    TxAddress++;
  }
}

/**
  * @}
  */
#endif /* HAL_FDCAN_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

#endif /* FDCAN1 || FDCAN2 */

