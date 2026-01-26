/**
  ******************************************************************************
  * @file    py32e407_hal_lpuart.c
  * @author  MCU Application Team
  * @brief   LPUART HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Universal Asynchronous Receiver Transmitter Peripheral (LPUART).
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *           + Peripheral Control functions
  *           + Peripheral State and Errors functions
  @verbatim
  ==============================================================================
                        ##### How to use this driver #####
  ==============================================================================
  [..]
    The LPUART HAL driver can be used as follows:

    (#) Declare a LPUART_HandleTypeDef handle structure (eg. LPUART_HandleTypeDef hlpuart).
    (#) Initialize the LPUART low level resources by implementing the HAL_LPUART_MspInit() API:
        (##) Enable the LPUARTx interface clock.
        (##) LPUART pins configuration:
            (+++) Enable the clock for the LPUART GPIOs.
            (+++) Configure these LPUART pins (TX as alternate function pull-up, RX as alternate function Input).
        (##) NVIC configuration if you need to use interrupt process (HAL_LPUART_Transmit_IT()
             and HAL_LPUART_Receive_IT() APIs):
            (+++) Configure the LPUARTx interrupt priority.
            (+++) Enable the NVIC LPUART IRQ handle.

    (#) Program the Baud Rate, Word Length, Stop Bit, Parity, first bit(MSB/LSB) 
        and Mode(Receiver/Transmitter) in the hlpuart Init structure.

    (#) Initialize the LPUART registers by calling the HAL_LPUART_Init() API.

     [..]
       (@) The specific LPUART interrupts (Transmission complete interrupt,
            RXNE interrupt and Error Interrupts) will be managed using the macros
            __HAL_LPUART_ENABLE_IT() and __HAL_LPUART_DISABLE_IT() inside the transmit
            and receive process.

     [..]
       (@)  HAL_LPUART_Init() configure also the low level Hardware GPIO, CLOCK, 
            CORTEX...etc) by calling the customized HAL_LPUART_MspInit() API.

    ##### Callback registration #####
    ==================================

    [..]
    The compilation define USE_HAL_LPUART_REGISTER_CALLBACKS when set to 1
    allows the user to configure dynamically the driver callbacks.

    [..]
    Use Function @ref HAL_LPUART_RegisterCallback() to register a user callback.
    Function @ref HAL_LPUART_RegisterCallback() allows to register following callbacks:
    (+) TxCpltCallback            : Tx Complete Callback.
    (+) RxCpltCallback            : Rx Complete Callback.
    (+) ErrorCallback             : Error Callback.
    (+) AbortCpltCallback         : Abort Complete Callback.
    (+) AbortTransmitCpltCallback : Abort Transmit Complete Callback.
    (+) AbortReceiveCpltCallback  : Abort Receive Complete Callback.
    (+) BreakFrameCallback        : Break Frame Detection Callback.
    (+) AddrMatchCallback         : Address Match Callback.
    (+) MspInitCallback           : LPUART MspInit.
    (+) MspDeInitCallback         : LPUART MspDeInit.
    This function takes as parameters the HAL peripheral handle, the Callback ID
    and a pointer to the user callback function.

    [..]
    Use function @ref HAL_LPUART_UnRegisterCallback() to reset a callback to the default
    weak (surcharged) function.
    @ref HAL_LPUART_UnRegisterCallback() takes as parameters the HAL peripheral handle,
    and the Callback ID.
    This function allows to reset following callbacks:
    (+) TxCpltCallback            : Tx Complete Callback.
    (+) RxCpltCallback            : Rx Complete Callback.
    (+) ErrorCallback             : Error Callback.
    (+) AbortCpltCallback         : Abort Complete Callback.
    (+) AbortTransmitCpltCallback : Abort Transmit Complete Callback.
    (+) AbortReceiveCpltCallback  : Abort Receive Complete Callback.
    (+) BreakFrameCallback        : Break Frame Detection Callback.
    (+) AddrMatchCallback         : Address Match Callback.
    (+) MspInitCallback           : LPUART MspInit.
    (+) MspDeInitCallback         : LPUART MspDeInit.

    [..]
    By default, after the @ref HAL_LPUART_Init() and when the state is HAL_LPUART_STATE_RESET
    all callbacks are set to the corresponding weak (surcharged) functions:
    examples @ref HAL_LPUART_TxCpltCallback(), @ref HAL_LPUART_RxCpltCallback().
    Exception done for MspInit and MspDeInit functions that are respectively
    reset to the legacy weak (surcharged) functions in the @ref HAL_LPUART_Init()
    and @ref HAL_LPUART_DeInit() only when these callbacks are null (not registered beforehand).
    If not, MspInit or MspDeInit are not null, the @ref HAL_LPUART_Init() and @ref HAL_LPUART_DeInit()
    keep and use the user MspInit/MspDeInit callbacks (registered beforehand).

    [..]
    Callbacks can be registered/unregistered in HAL_LPUART_STATE_READY state only.
    Exception done MspInit/MspDeInit that can be registered/unregistered
    in HAL_LPUART_STATE_READY or HAL_LPUART_STATE_RESET state, thus registered (user)
    MspInit/DeInit callbacks can be used during the Init/DeInit.
    In that case first register the MspInit/MspDeInit user callbacks
    using @ref HAL_LPUART_RegisterCallback() before calling @ref HAL_LPUART_DeInit()
    or @ref HAL_LPUART_Init() function.

    [..]
    When The compilation define USE_HAL_LPUART_REGISTER_CALLBACKS is set to 0 or
    not defined, the callback registration feature is not available
    and weak (surcharged) callbacks are used.

     [..]
        Two operation modes are available within this driver :

     *** Polling mode IO operation ***
     =================================
     [..]
       (+) Send an amount of data in blocking mode using HAL_LPUART_Transmit()
       (+) Receive an amount of data in blocking mode using HAL_LPUART_Receive()

     *** Interrupt mode IO operation ***
     ===================================
     [..]
       (+) Send an amount of data in non blocking mode using HAL_LPUART_Transmit_IT()
       (+) At transmission end of transfer HAL_LPUART_TxCpltCallback is executed and user can
            add his own code by customization of function pointer HAL_LPUART_TxCpltCallback
       (+) Receive an amount of data in non blocking mode using HAL_LPUART_Receive_IT()
       (+) At reception end of transfer HAL_LPUART_RxCpltCallback is executed and user can
            add his own code by customization of function pointer HAL_LPUART_RxCpltCallback
       (+) In case of transfer Error, HAL_LPUART_ErrorCallback() function is executed and user can
            add his own code by customization of function pointer HAL_LPUART_ErrorCallback

     *** LPUART HAL driver macros list ***
     =============================================
     [..]
       Below the list of most used macros in LPUART HAL driver.

      (+) __HAL_LPUART_GET_FLAG : Check whether the specified LPUART flag is set or not
      (+) __HAL_LPUART_CLEAR_FLAG : Clear the specified LPUART pending flag
      (+) __HAL_LPUART_ENABLE_IT: Enable the specified LPUART interrupt
      (+) __HAL_LPUART_DISABLE_IT: Disable the specified LPUART interrupt
      (+) __HAL_LPUART_GET_IT_SOURCE: Check whether the specified LPUART interrupt has occurred or not

     [..]
       (@) You can refer to the LPUART HAL driver header file for more useful macros

  @endverbatim
     [..]
       (@) Additionnal remark: If the parity is enabled, then the MSB bit of the data written
           in the data register is transmitted but is changed by the parity bit.
           Depending on the frame length defined by the M_E bit (8-bits or 9-bits),
           the possible LPUART frame formats are as listed in the following table:
    +-------------------------------------------------------------+
    | M_E bit |  PCE bit  |            LPUART frame               |
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
#include "py32e407_hal_lpuart.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup LPUART LPUART
  * @brief HAL LPUART module driver
  * @{
  */

#ifdef HAL_LPUART_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup LPUART_Private_Constants LPUART Private Constants
  * @{
  */
#define LPUART_CR1_FIELDS  ((uint32_t)(LPUART_CR1_M0 | LPUART_CR1_M1  | LPUART_CR1_PCE | LPUART_CR1_PS | \
                                       LPUART_CR1_TE | LPUART_CR1_RE  | LPUART_CR1_FIFOEN )) /*!< LPUART CR1 fields of parameters set by LPUART_SetConfig API */

#define LPUART_CR3_FIELDS  ((uint32_t)(LPUART_CR3_RTSE | LPUART_CR3_CTSE | LPUART_CR3_TXFTCFG | LPUART_CR3_RXFTCFG )) /*!< LPUART CR3 fields of parameters set by LPUART_SetConfig API */

#define LPUART_BRR_MIN  0x00000300U  /* LPUART BRR minimum authorized value */
#define LPUART_BRR_MAX  0x000FFFFFU  /* LPUART BRR maximum authorized value */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
const uint16_t LPUARTPrescTable[12] = {1U, 2U, 4U, 6U, 8U, 10U, 12U, 16U, 32U, 64U, 128U, 256U};

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup LPUART_Private_Functions
  * @{
  */
static void LPUART_EndTxTransfer(LPUART_HandleTypeDef *hlpuart);
static void LPUART_EndRxTransfer(LPUART_HandleTypeDef *hlpuart);

static void LPUART_DMATransmitCplt(DMA_HandleTypeDef *hdma);
static void LPUART_DMAReceiveCplt(DMA_HandleTypeDef *hdma);
static void LPUART_DMARxBlockCplt(DMA_HandleTypeDef *hdma);
static void LPUART_DMARxHalfBlockCplt(DMA_HandleTypeDef *hdma);
static void LPUART_DMASrcTranCplt(DMA_HandleTypeDef *hdma);
static void LPUART_DMATxBlockCplt(DMA_HandleTypeDef *hdma);
static void LPUART_DMATxHalfBlockCplt(DMA_HandleTypeDef *hdma);
static void LPUART_DMADstTranCplt(DMA_HandleTypeDef *hdma);

static void LPUART_DMAError(DMA_HandleTypeDef *hdma);
static void LPUART_DMAAbortOnError(DMA_HandleTypeDef *hdma);
static void LPUART_DMATxAbortCallback(DMA_HandleTypeDef *hdma);
static void LPUART_DMARxAbortCallback(DMA_HandleTypeDef *hdma);
static void LPUART_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma);
static void LPUART_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma);

static void LPUART_TxISR_8BIT(LPUART_HandleTypeDef *hlpuart);
static void LPUART_TxISR_16BIT(LPUART_HandleTypeDef *hlpuart);
static void LPUART_TxISR_8BIT_FIFOEN(LPUART_HandleTypeDef *hlpuart);
static void LPUART_TxISR_16BIT_FIFOEN(LPUART_HandleTypeDef *hlpuart);
static void LPUART_EndTransmit_IT(LPUART_HandleTypeDef *hlpuart);
static void LPUART_RxISR_8BIT(LPUART_HandleTypeDef *hlpuart);
static void LPUART_RxISR_16BIT(LPUART_HandleTypeDef *hlpuart);
static void LPUART_RxISR_8BIT_FIFOEN(LPUART_HandleTypeDef *hlpuart);
static void LPUART_RxISR_16BIT_FIFOEN(LPUART_HandleTypeDef *hlpuart);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup LPUART_Exported_Functions LPUART Exported Functions
  * @{
  */

/** @defgroup LPUART_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
@verbatim
===============================================================================
            ##### Initialization and Configuration functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to initialize the LPUARTx or the LPUARTy
    in asynchronous mode.
      (+) For the asynchronous mode the parameters below can be configured:
        (++) Baud Rate
        (++) Word Length
        (++) Stop Bit
        (++) Parity: If the parity is enabled, then the MSB bit of the data written
             in the data register is transmitted but is changed by the parity bit.
        (++) Hardware flow control
        (++) Receiver/transmitter modes
        (++) Over Sampling Method
        (++) One-Bit Sampling Method
      (+) For the asynchronous mode, the following advanced features can be configured as well:
        (++) TX and/or RX pin level inversion
        (++) data logical level inversion
        (++) RX and TX pins swap
        (++) RX overrun detection disabling
        (++) DMA disabling on RX error
        (++) MSB first on communication line
        (++) auto Baud rate detection
    [..]
    The HAL_LPUART_Init(), HAL_HalfDuplex_Init() and HAL_MultiProcessor_Init()API
    follow respectively the LPUART asynchronous, LPUART Half duplex, LPUART LIN mode
    and LPUART multiprocessor mode configuration procedures (details for the procedures
    are available in reference manual).

@endverbatim

  Depending on the frame length defined by the M1 and M0 bits (7-bit,
  8-bit or 9-bit), the possible LPUART formats are listed in the
  following table.

  Table 1. LPUART frame format.
    +-----------------------------------------------------------------------+
    |  M1 bit |  M0 bit |  PCE bit  |           LPUART frame                |
    |---------|---------|-----------|---------------------------------------|
    |    0    |    0    |    0      |    | SB |    8 bit data   | STB |     |
    |---------|---------|-----------|---------------------------------------|
    |    0    |    0    |    1      |    | SB | 7 bit data | PB | STB |     |
    |---------|---------|-----------|---------------------------------------|
    |    0    |    1    |    0      |    | SB |    9 bit data   | STB |     |
    |---------|---------|-----------|---------------------------------------|
    |    0    |    1    |    1      |    | SB | 8 bit data | PB | STB |     |
    |---------|---------|-----------|---------------------------------------|
    |    1    |    0    |    0      |    | SB |    7 bit data   | STB |     |
    |---------|---------|-----------|---------------------------------------|
    |    1    |    0    |    1      |    | SB | 6 bit data | PB | STB |     |
    +-----------------------------------------------------------------------+

  * @{
  */

/**
  * @brief Initialize the LPUART mode according to the specified
  *        parameters in the LPUART_InitTypeDef and initialize the associated handle.
  * @param hlpuart LPUART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_Init(LPUART_HandleTypeDef *hlpuart)
{
  /* Check the LPUART handle allocation */
  if (hlpuart == NULL)
  {
    return HAL_ERROR;
  }

  if (hlpuart->Init.HwFlowCtl != LPUART_HWCONTROL_NONE)
  {
    /* Check the parameters */
    assert_param(IS_LPUART_HWFLOW_INSTANCE(hlpuart->Instance));
  }
  else
  {
    /* Check the parameters */
    assert_param(IS_LPUART_INSTANCE(hlpuart->Instance));
  }

  if (hlpuart->gState == HAL_LPUART_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hlpuart->Lock = HAL_UNLOCKED;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
    LPUART_InitCallbacksToDefault(hlpuart);

    if (hlpuart->MspInitCallback == NULL)
    {
      hlpuart->MspInitCallback = HAL_LPUART_MspInit;
    }

    /* Init the low level hardware */
    hlpuart->MspInitCallback(hlpuart);
#else
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_LPUART_MspInit(hlpuart);
#endif /* (USE_HAL_LPUART_REGISTER_CALLBACKS) */
  }

  hlpuart->gState = HAL_LPUART_STATE_BUSY;

  __HAL_LPUART_DISABLE(hlpuart);

  /* Set the LPUART Communication parameters */
  if (LPUART_SetConfig(hlpuart) == HAL_ERROR)
  {
    return HAL_ERROR;
  }

  if (hlpuart->AdvancedInit.AdvFeatureInit != LPUART_ADVFEATURE_NO_INIT)
  {
    LPUART_AdvFeatureConfig(hlpuart);
  }

  /* In asynchronous mode, the HDSEL bit must be kept cleared: HDSEL bit in the LPUART_CR3 register.*/
  CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_HDSEL);

  __HAL_LPUART_ENABLE(hlpuart);

  /* TEACK and/or REACK to check before moving hlpuart->gState and hlpuart->RxState to Ready */
  return (LPUART_CheckIdleState(hlpuart));
}

/**
  * @brief Initialize the half-duplex mode according to the specified
  *        parameters in the LPUART_InitTypeDef and creates the associated handle.
  * @param hlpuart LPUART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_HalfDuplex_Init(LPUART_HandleTypeDef *hlpuart)
{
  /* Check the LPUART handle allocation */
  if (hlpuart == NULL)
  {
    return HAL_ERROR;
  }

  /* Check LPUART instance */
  assert_param(IS_LPUART_HALFDUPLEX_INSTANCE(hlpuart->Instance));

  if (hlpuart->gState == HAL_LPUART_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hlpuart->Lock = HAL_UNLOCKED;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
    LPUART_InitCallbacksToDefault(hlpuart);

    if (hlpuart->MspInitCallback == NULL)
    {
      hlpuart->MspInitCallback = HAL_LPUART_MspInit;
    }

    /* Init the low level hardware */
    hlpuart->MspInitCallback(hlpuart);
#else
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_LPUART_MspInit(hlpuart);
#endif /* (USE_HAL_LPUART_REGISTER_CALLBACKS) */
  }

  hlpuart->gState = HAL_LPUART_STATE_BUSY;

  __HAL_LPUART_DISABLE(hlpuart);

  /* Set the LPUART Communication parameters */
  if (LPUART_SetConfig(hlpuart) == HAL_ERROR)
  {
    return HAL_ERROR;
  }

  if (hlpuart->AdvancedInit.AdvFeatureInit != LPUART_ADVFEATURE_NO_INIT)
  {
    LPUART_AdvFeatureConfig(hlpuart);
  }

  /* Enable the Half-Duplex mode by setting the HDSEL bit in the CR3 register */
  SET_BIT(hlpuart->Instance->CR3, LPUART_CR3_HDSEL);

  __HAL_LPUART_ENABLE(hlpuart);

  /* TEACK and/or REACK to check before moving hlpuart->gState and hlpuart->RxState to Ready */
  return (LPUART_CheckIdleState(hlpuart));
}

/**
  * @brief Initialize the multiprocessor mode according to the specified
  *        parameters in the LPUART_InitTypeDef and initialize the associated handle.
  * @param hlpuart LPUART handle.
  * @param Address LPUART node address (4-, 6-, 7- or 8-bit long).
  * @param WakeUpMethod Specifies the LPUART wakeup method.
  *        This parameter can be one of the following values:
  *          @arg @ref LPUART_WAKEUPMETHOD_IDLELINE WakeUp by an idle line detection
  *          @arg @ref LPUART_WAKEUPMETHOD_ADDRESSMARK WakeUp by an address mark
  * @note  If the user resorts to idle line detection wake up, the Address parameter
  *        is useless and ignored by the initialization function.
  * @note  If the user resorts to address mark wake up, the address length detection
  *        is configured by default to 4 bits only. For the LPUART to be able to
  *        manage 6-, 7- or 8-bit long addresses detection, the API
  *        HAL_MultiProcessorEx_AddressLength_Set() must be called after
  *        HAL_MultiProcessor_Init().
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_MultiProcessor_Init(LPUART_HandleTypeDef *hlpuart, uint8_t Address, uint32_t WakeUpMethod)
{
  /* Check the LPUART handle allocation */
  if (hlpuart == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the wake up method parameter */
  assert_param(IS_LPUART_WAKEUPMETHOD(WakeUpMethod));

  if (hlpuart->gState == HAL_LPUART_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hlpuart->Lock = HAL_UNLOCKED;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
    LPUART_InitCallbacksToDefault(hlpuart);

    if (hlpuart->MspInitCallback == NULL)
    {
      hlpuart->MspInitCallback = HAL_LPUART_MspInit;
    }

    /* Init the low level hardware */
    hlpuart->MspInitCallback(hlpuart);
#else
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_LPUART_MspInit(hlpuart);
#endif /* (USE_HAL_LPUART_REGISTER_CALLBACKS) */
  }

  hlpuart->gState = HAL_LPUART_STATE_BUSY;

  __HAL_LPUART_DISABLE(hlpuart);

  /* Set the LPUART Communication parameters */
  if (LPUART_SetConfig(hlpuart) == HAL_ERROR)
  {
    return HAL_ERROR;
  }

  if (hlpuart->AdvancedInit.AdvFeatureInit != LPUART_ADVFEATURE_NO_INIT)
  {
    LPUART_AdvFeatureConfig(hlpuart);
  }

  /* In multiprocessor mode, the following bits must be kept cleared:
  - HDSEL bit in the LPUART_CR3 register. */
  CLEAR_BIT(hlpuart->Instance->CR3, (LPUART_CR3_HDSEL));

  if (WakeUpMethod == LPUART_WAKEUPMETHOD_ADDRESSMARK)
  {
    /* If address mark wake up method is chosen, set the LPUART address node */
    MODIFY_REG(hlpuart->Instance->CR2, LPUART_CR2_ADD, ((uint32_t)Address << LPUART_CR2_ADDRESS_LSB_POS));
  }

  /* Set the wake up method by setting the WAKE bit in the CR1 register */
  MODIFY_REG(hlpuart->Instance->CR1, LPUART_CR1_WAKE, WakeUpMethod);

  __HAL_LPUART_ENABLE(hlpuart);

  /* TEACK and/or REACK to check before moving hlpuart->gState and hlpuart->RxState to Ready */
  return (LPUART_CheckIdleState(hlpuart));
}


/**
  * @brief DeInitialize the LPUART peripheral.
  * @param hlpuart LPUART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_DeInit(LPUART_HandleTypeDef *hlpuart)
{
  /* Check the LPUART handle allocation */
  if (hlpuart == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_LPUART_INSTANCE(hlpuart->Instance));

  hlpuart->gState = HAL_LPUART_STATE_BUSY;

  __HAL_LPUART_DISABLE(hlpuart);

  hlpuart->Instance->CR1 = 0x0U;
  hlpuart->Instance->CR2 = 0x0U;
  hlpuart->Instance->CR3 = 0x0U;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  if (hlpuart->MspDeInitCallback == NULL)
  {
    hlpuart->MspDeInitCallback = HAL_LPUART_MspDeInit;
  }
  /* DeInit the low level hardware */
  hlpuart->MspDeInitCallback(hlpuart);
#else
  /* DeInit the low level hardware */
  HAL_LPUART_MspDeInit(hlpuart);
#endif /* (USE_HAL_LPUART_REGISTER_CALLBACKS) */

  hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;
  hlpuart->gState = HAL_LPUART_STATE_RESET;
  hlpuart->RxState = HAL_LPUART_STATE_RESET;

  __HAL_UNLOCK(hlpuart);

  return HAL_OK;
}

/**
  * @brief Initialize the LPUART MSP.
  * @param hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_MspInit(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LPUART_MspInit can be implemented in the user file
   */
}

/**
  * @brief DeInitialize the LPUART MSP.
  * @param hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_MspDeInit(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LPUART_MspDeInit can be implemented in the user file
   */
}

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User LPUART Callback
  *         To be used instead of the weak predefined callback
  * @param  hlpuart LPUART handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_LPUART_TX_BLOCKCOMPLETE_CB_ID Tx Block Complete Callback ID
  *           @arg @ref HAL_LPUART_TX_HALFBLOCKCOMPLETE_CB_ID Tx Half Block Complete Callback ID
  *           @arg @ref HAL_LPUART_TX_SRCCOMPLETE_CB_ID Tx Source Complete Callback ID
  *           @arg @ref HAL_LPUART_TX_COMPLETE_CB_ID Tx Complete Callback ID
  *           @arg @ref HAL_LPUART_RX_BLOCKCOMPLETE_CB_ID Rx Block Complete Callback ID
  *           @arg @ref HAL_LPUART_RX_HALFBLOCKCOMPLETE_CB_ID Rx Half Block Complete Callback ID
  *           @arg @ref HAL_LPUART_RX_DSTCOMPLETE_CB_ID Rx Destination Complete Callback ID
  *           @arg @ref HAL_LPUART_RX_COMPLETE_CB_ID Rx Complete Callback ID
  *           @arg @ref HAL_LPUART_ERROR_CB_ID Error Callback ID
  *           @arg @ref HAL_LPUART_ABORT_COMPLETE_CB_ID Abort Complete Callback ID
  *           @arg @ref HAL_LPUART_ABORT_TRANSMIT_COMPLETE_CB_ID Abort Transmit Complete Callback ID
  *           @arg @ref HAL_LPUART_ABORT_RECEIVE_COMPLETE_CB_ID Abort Receive Complete Callback ID
  *           @arg @ref HAL_LPUART_WAKEUP_CB_ID Wakeup Callback ID
  *           @arg @ref HAL_LPUART_RX_FIFO_FULL_CB_ID Rx Fifo Full Callback ID
  *           @arg @ref HAL_LPUART_TX_FIFO_EMPTY_CB_ID Tx Fifo Empty Callback ID
  *           @arg @ref HAL_LPUART_MSPINIT_CB_ID MspInit Callback ID
  *           @arg @ref HAL_LPUART_MSPDEINIT_CB_ID MspDeInit Callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_RegisterCallback(LPUART_HandleTypeDef *hlpuart, HAL_LPUART_CallbackIDTypeDef CallbackID,
                                            pLPUART_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    hlpuart->ErrorCode |= HAL_LPUART_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  __HAL_LOCK(hlpuart);

  if (hlpuart->gState == HAL_LPUART_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_LPUART_TX_BLOCKCOMPLETE_CB_ID :
        hlpuart->TxBlockCpltCallback = pCallback;
        break;

      case HAL_LPUART_TX_HALFBLOCKCOMPLETE_CB_ID :
        hlpuart->TxHalfBlockCpltCallback = pCallback;
        break;

      case HAL_LPUART_TX_SRCCOMPLETE_CB_ID :
        hlpuart->TxSrcCpltCallback = pCallback;
        break;

      case HAL_LPUART_TX_COMPLETE_CB_ID :
        hlpuart->TxCpltCallback = pCallback;
        break;

      case HAL_LPUART_RX_BLOCKCOMPLETE_CB_ID :
        hlpuart->RxBlockCpltCallback = pCallback;
        break;

      case HAL_LPUART_RX_HALFBLOCKCOMPLETE_CB_ID :
        hlpuart->RxHalfBlockCpltCallback = pCallback;
        break;

      case HAL_LPUART_RX_DSTCOMPLETE_CB_ID :
        hlpuart->RxDstCpltCallback = pCallback;
        break;

      case HAL_LPUART_RX_COMPLETE_CB_ID :
        hlpuart->RxCpltCallback = pCallback;
        break;

      case HAL_LPUART_ERROR_CB_ID :
        hlpuart->ErrorCallback = pCallback;
        break;

      case HAL_LPUART_ABORT_COMPLETE_CB_ID :
        hlpuart->AbortCpltCallback = pCallback;
        break;

      case HAL_LPUART_ABORT_TRANSMIT_COMPLETE_CB_ID :
        hlpuart->AbortTransmitCpltCallback = pCallback;
        break;

      case HAL_LPUART_ABORT_RECEIVE_COMPLETE_CB_ID :
        hlpuart->AbortReceiveCpltCallback = pCallback;
        break;

      case HAL_LPUART_WAKEUP_CB_ID :
        hlpuart->WakeupCallback = pCallback;
        break;

      case HAL_LPUART_RX_FIFO_FULL_CB_ID :
        hlpuart->RxFifoFullCallback = pCallback;
        break;

      case HAL_LPUART_TX_FIFO_EMPTY_CB_ID :
        hlpuart->TxFifoEmptyCallback = pCallback;
        break;

      case HAL_LPUART_MSPINIT_CB_ID :
        hlpuart->MspInitCallback = pCallback;
        break;

      case HAL_LPUART_MSPDEINIT_CB_ID :
        hlpuart->MspDeInitCallback = pCallback;
        break;

      default :
        hlpuart->ErrorCode |= HAL_LPUART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else if (hlpuart->gState == HAL_LPUART_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_LPUART_MSPINIT_CB_ID :
        hlpuart->MspInitCallback = pCallback;
        break;

      case HAL_LPUART_MSPDEINIT_CB_ID :
        hlpuart->MspDeInitCallback = pCallback;
        break;

      default :
        hlpuart->ErrorCode |= HAL_LPUART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    hlpuart->ErrorCode |= HAL_LPUART_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  __HAL_UNLOCK(hlpuart);

  return status;
}

/**
  * @brief  Unregister an LPUART Callback
  *         LPUART callaback is redirected to the weak predefined callback
  * @param  hlpuart LPUART handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_LPUART_TX_BLOCKCOMPLETE_CB_ID Tx Block Complete Callback ID
  *           @arg @ref HAL_LPUART_TX_HALFBLOCKCOMPLETE_CB_ID Tx Half Block Complete Callback ID
  *           @arg @ref HAL_LPUART_TX_SRCCOMPLETE_CB_ID Tx Source Complete Callback ID
  *           @arg @ref HAL_LPUART_TX_COMPLETE_CB_ID Tx Complete Callback ID
  *           @arg @ref HAL_LPUART_RX_BLOCKCOMPLETE_CB_ID Rx Block Complete Callback ID
  *           @arg @ref HAL_LPUART_RX_HALFBLOCKCOMPLETE_CB_ID Rx Half Block Complete Callback ID
  *           @arg @ref HAL_LPUART_RX_DSTCOMPLETE_CB_ID Rx Destination Complete Callback ID
  *           @arg @ref HAL_LPUART_RX_COMPLETE_CB_ID Rx Complete Callback ID
  *           @arg @ref HAL_LPUART_ERROR_CB_ID Error Callback ID
  *           @arg @ref HAL_LPUART_ABORT_COMPLETE_CB_ID Abort Complete Callback ID
  *           @arg @ref HAL_LPUART_ABORT_TRANSMIT_COMPLETE_CB_ID Abort Transmit Complete Callback ID
  *           @arg @ref HAL_LPUART_ABORT_RECEIVE_COMPLETE_CB_ID Abort Receive Complete Callback ID
  *           @arg @ref HAL_LPUART_WAKEUP_CB_ID Wakeup Callback ID
  *           @arg @ref HAL_LPUART_RX_FIFO_FULL_CB_ID Rx Fifo Full Callback ID
  *           @arg @ref HAL_LPUART_TX_FIFO_EMPTY_CB_ID Tx Fifo Empty Callback ID
  *           @arg @ref HAL_LPUART_MSPINIT_CB_ID MspInit Callback ID
  *           @arg @ref HAL_LPUART_MSPDEINIT_CB_ID MspDeInit Callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_UnRegisterCallback(LPUART_HandleTypeDef *hlpuart, HAL_LPUART_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  __HAL_LOCK(hlpuart);

  if (HAL_LPUART_STATE_READY == hlpuart->gState)
  {
    switch (CallbackID)
    {
      case HAL_LPUART_TX_BLOCKCOMPLETE_CB_ID :
        hlpuart->TxBlockCpltCallback = HAL_LPUART_TxBlockCpltCallback;             /* Legacy weak TxBlockCpltCallback     */
        break;

      case HAL_LPUART_TX_HALFBLOCKCOMPLETE_CB_ID :
        hlpuart->TxHalfBlockCpltCallback = HAL_LPUART_TxHalfBlockCpltCallback;     /* Legacy weak TxHalfBlockCpltCallback */
        break;

      case HAL_LPUART_TX_SRCCOMPLETE_CB_ID :
        hlpuart->TxSrcCpltCallback = HAL_LPUART_TxSrcCpltCallback;                 /* Legacy weak TxSrcCpltCallback       */
        break;

      case HAL_LPUART_TX_COMPLETE_CB_ID :
        hlpuart->TxCpltCallback = HAL_LPUART_TxCpltCallback;                       /* Legacy weak TxCpltCallback          */
        break;

      case HAL_LPUART_RX_BLOCKCOMPLETE_CB_ID :
        hlpuart->RxBlockCpltCallback = HAL_LPUART_RxBlockCpltCallback;             /* Legacy weak RxBlockCpltCallback     */
        break;

      case HAL_LPUART_RX_HALFBLOCKCOMPLETE_CB_ID :
        hlpuart->RxHalfBlockCpltCallback = HAL_LPUART_RxHalfBlockCpltCallback;     /* Legacy weak RxHalfBlockCpltCallback */
        break;

      case HAL_LPUART_RX_DSTCOMPLETE_CB_ID :
        hlpuart->RxDstCpltCallback = HAL_LPUART_RxDstCpltCallback;                 /* Legacy weak RxDstCpltCallback       */
        break;

      case HAL_LPUART_RX_COMPLETE_CB_ID :
        hlpuart->RxCpltCallback = HAL_LPUART_RxCpltCallback;                       /* Legacy weak RxCpltCallback          */
        break;

      case HAL_LPUART_ERROR_CB_ID :
        hlpuart->ErrorCallback = HAL_LPUART_ErrorCallback;                         /* Legacy weak ErrorCallback           */
        break;

      case HAL_LPUART_ABORT_COMPLETE_CB_ID :
        hlpuart->AbortCpltCallback = HAL_LPUART_AbortCpltCallback;                 /* Legacy weak AbortCpltCallback       */
        break;

      case HAL_LPUART_ABORT_TRANSMIT_COMPLETE_CB_ID :
        hlpuart->AbortTransmitCpltCallback = HAL_LPUART_AbortTransmitCpltCallback; /* Legacy weak
                                                                                  AbortTransmitCpltCallback               */
        break;

      case HAL_LPUART_ABORT_RECEIVE_COMPLETE_CB_ID :
        hlpuart->AbortReceiveCpltCallback = HAL_LPUART_AbortReceiveCpltCallback;   /* Legacy weak
                                                                                  AbortReceiveCpltCallback                */
        break;

      case HAL_LPUART_WAKEUP_CB_ID :
        hlpuart->WakeupCallback = HAL_LPUARTEx_WakeupCallback;                     /* Legacy weak WakeupCallback          */
        break;

      case HAL_LPUART_RX_FIFO_FULL_CB_ID :
        hlpuart->RxFifoFullCallback = HAL_LPUARTEx_RxFifoFullCallback;             /* Legacy weak RxFifoFullCallback      */
        break;

      case HAL_LPUART_TX_FIFO_EMPTY_CB_ID :
        hlpuart->TxFifoEmptyCallback = HAL_LPUARTEx_TxFifoEmptyCallback;           /* Legacy weak TxFifoEmptyCallback     */
        break;

      case HAL_LPUART_MSPINIT_CB_ID :
        hlpuart->MspInitCallback = HAL_LPUART_MspInit;                             /* Legacy weak MspInitCallback         */
        break;

      case HAL_LPUART_MSPDEINIT_CB_ID :
        hlpuart->MspDeInitCallback = HAL_LPUART_MspDeInit;                         /* Legacy weak MspDeInitCallback       */
        break;

      default :
        hlpuart->ErrorCode |= HAL_LPUART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_LPUART_STATE_RESET == hlpuart->gState)
  {
    switch (CallbackID)
    {
      case HAL_LPUART_MSPINIT_CB_ID :
        hlpuart->MspInitCallback = HAL_LPUART_MspInit;
        break;

      case HAL_LPUART_MSPDEINIT_CB_ID :
        hlpuart->MspDeInitCallback = HAL_LPUART_MspDeInit;
        break;

      default :
        hlpuart->ErrorCode |= HAL_LPUART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    hlpuart->ErrorCode |= HAL_LPUART_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  __HAL_UNLOCK(hlpuart);

  return status;
}
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup LPUART_Exported_Functions_Group2 IO operation functions
  * @brief LPUART Transmit/Receive functions
  *
@verbatim
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    This subsection provides a set of functions allowing to manage the LPUART asynchronous
    and Half duplex data transfers.

    (#) There are two mode of transfer:
       (+) Blocking mode: The communication is performed in polling mode.
           The HAL status of all data processing is returned by the same function
           after finishing transfer.
       (+) Non-Blocking mode: The communication is performed using Interrupts
           or DMA, These API's return the HAL status.
           The end of the data processing will be indicated through the
           dedicated LPUART IRQ when using Interrupt mode or the DMA IRQ when
           using DMA mode.
           The HAL_LPUART_TxCpltCallback(), HAL_LPUART_RxCpltCallback() user callbacks
           will be executed respectively at the end of the transmit or Receive process
           The HAL_LPUART_ErrorCallback()user callback will be executed when a communication error is detected

    (#) Blocking mode API's are :
        (+) HAL_LPUART_Transmit()
        (+) HAL_LPUART_Receive()

    (#) Non-Blocking mode API's with Interrupt are :
        (+) HAL_LPUART_Transmit_IT()
        (+) HAL_LPUART_Receive_IT()
        (+) HAL_LPUART_IRQHandler()

    (#) Non-Blocking mode API's with DMA are :
        (+) HAL_LPUART_Transmit_DMA()
        (+) HAL_LPUART_Receive_DMA()
        (+) HAL_LPUART_DMAPause()
        (+) HAL_LPUART_DMAResume()
        (+) HAL_LPUART_DMAStop()

    (#) A set of Transfer Complete Callbacks are provided in Non_Blocking mode:
        (+) HAL_LPUART_TxBlockCpltCallback()
        (+) HAL_LPUART_TxHalfBlockCpltCallback()
        (+) HAL_LPUART_TxSrcCpltCallback()
        (+) HAL_LPUART_TxCpltCallback()
        (+) HAL_LPUART_RxBlockCpltCallback()
        (+) HAL_LPUART_RxHalfBlockCpltCallback()
        (+) HAL_LPUART_RxDstCpltCallback()
        (+) HAL_LPUART_RxCpltCallback()
        (+) HAL_LPUART_ErrorCallback()

    (#) Non-Blocking mode transfers could be aborted using Abort API's :
        (+) HAL_LPUART_Abort()
        (+) HAL_LPUART_AbortTransmit()
        (+) HAL_LPUART_AbortReceive()
        (+) HAL_LPUART_Abort_IT()
        (+) HAL_LPUART_AbortTransmit_IT()
        (+) HAL_LPUART_AbortReceive_IT()

    (#) For Abort services based on interrupts (HAL_LPUART_Abortxxx_IT), a set of Abort Complete Callbacks are provided:
        (+) HAL_LPUART_AbortCpltCallback()
        (+) HAL_LPUART_AbortTransmitCpltCallback()
        (+) HAL_LPUART_AbortReceiveCpltCallback()

    (#) In Non-Blocking mode transfers, possible errors are split into 2 categories.
        Errors are handled as follows :
       (+) Error is considered as Recoverable and non blocking : Transfer could go till end, but error severity is
           to be evaluated by user : this concerns Frame Error, Parity Error or Noise Error
           in Interrupt mode reception .
           Received character is then retrieved and stored in Rx buffer, Error code is set to allow user
           to identify error type, and HAL_LPUART_ErrorCallback() user callback is executed.
           Transfer is kept ongoing on LPUART side.
           If user wants to abort it, Abort services should be called by user.
       (+) Error is considered as Blocking : Transfer could not be completed properly and is aborted.
           This concerns Overrun Error In Interrupt mode reception and all errors in DMA mode.
           Error code is set to allow user to identify error type, and HAL_LPUART_ErrorCallback()
           user callback is executed.

    -@- In the Half duplex communication, it is forbidden to run the transmit
        and receive process in parallel, the LPUART state HAL_LPUART_STATE_BUSY_TX_RX can't be useful.

@endverbatim
  * @{
  */

/**
  * @brief Send an amount of data in blocking mode.
  * @note   When LPUART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @note When FIFO mode is enabled, writing a data in the TDR register adds one
  *       data to the TXFIFO. Write operations to the TDR register are performed
  *       when TXE flag is set. From hardware perspective, TXE flag andis mapped on the same bit-field.
  * @param hlpuart   LPUART handle.
  * @param pData   Pointer to data buffer (u8 or u16 data elements).
  * @param Size    Amount of data elements (u8 or u16 or u32) to be sent.
  * @param Timeout Timeout duration.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_Transmit(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size, uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint16_t *pdata16bits;
  uint32_t tickstart;

  /* Check that a Tx process is not already ongoing */
  if (hlpuart->gState == HAL_LPUART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    __HAL_LOCK(hlpuart);

    hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;
    hlpuart->gState = HAL_LPUART_STATE_BUSY_TX;

    /* Init tickstart for timeout management */
    tickstart = HAL_GetTick();

    hlpuart->TxXferSize  = Size;
    hlpuart->TxXferCount = Size;

    /* In case of 9bits/No Parity transfer, pData needs to be handled as a uint16_t pointer */
    if ((hlpuart->Init.WordLength == LPUART_WORDLENGTH_9B) && (hlpuart->Init.Parity == LPUART_PARITY_NONE))
    {
      pdata8bits  = NULL;
      pdata16bits = (uint16_t *) pData;
    }
    else
    {
      pdata8bits  = pData;
      pdata16bits = NULL;
    }

    __HAL_UNLOCK(hlpuart);

    while (hlpuart->TxXferCount > 0U)
    {
      if (LPUART_WaitOnFlagUntilTimeout(hlpuart, LPUART_FLAG_TXE, RESET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
      if (pdata8bits == NULL)
      {
        hlpuart->Instance->TDR = (uint16_t)(*pdata16bits & 0x01FFU);
        pdata16bits++;
      }
      else
      {
        hlpuart->Instance->TDR = (uint8_t)(*pdata8bits & 0xFFU);
        pdata8bits++;
      }
      hlpuart->TxXferCount--;
    }

    if (LPUART_WaitOnFlagUntilTimeout(hlpuart, LPUART_FLAG_TC, RESET, tickstart, Timeout) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    /* At end of Tx process, restore hlpuart->gState to Ready */
    hlpuart->gState = HAL_LPUART_STATE_READY;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in blocking mode.
  * @note   When LPUART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the received data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 available through pData.
  * @note When FIFO mode is enabled, the RXNE flag is set as long as the RXFIFO
  *       is not empty. Read operations from the RDR register are performed when
  *       RXNE flag is set. From hardware perspective, RXNE flag and is mapped on the same bit-field.
  * @param hlpuart   LPUART handle.
  * @param pData   Pointer to data buffer (u8 or u16 data elements).
  * @param Size    Amount of data elements (u8 or u16 or u32) to be received.
  * @param Timeout Timeout duration.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_Receive(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size, uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint16_t *pdata16bits;
  uint16_t uhMask;
  uint32_t tickstart;

  /* Check that a Rx process is not already ongoing */
  if (hlpuart->RxState == HAL_LPUART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    __HAL_LOCK(hlpuart);

    hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;
    hlpuart->RxState = HAL_LPUART_STATE_BUSY_RX;

    /* Init tickstart for timeout management */
    tickstart = HAL_GetTick();

    hlpuart->RxXferSize  = Size;
    hlpuart->RxXferCount = Size;

    /* Computation of LPUART mask to apply to RDR register */
    LPUART_MASK_COMPUTATION(hlpuart);
    uhMask = hlpuart->Mask;

    /* In case of 9bits/No Parity transfer, pRxData needs to be handled as a uint16_t pointer */
    if ((hlpuart->Init.WordLength == LPUART_WORDLENGTH_9B) && (hlpuart->Init.Parity == LPUART_PARITY_NONE))
    {
      pdata8bits  = NULL;
      pdata16bits = (uint16_t *) pData;
    }
    else
    {
      pdata8bits  = pData;
      pdata16bits = NULL;
    }

    __HAL_UNLOCK(hlpuart);

    /* as long as data have to be received */
    while (hlpuart->RxXferCount > 0U)
    {
      if (LPUART_WaitOnFlagUntilTimeout(hlpuart, LPUART_FLAG_RXNE, RESET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
      if (pdata8bits == NULL)
      {
        *pdata16bits = (uint16_t)(hlpuart->Instance->RDR & uhMask);
        pdata16bits++;
      }
      else
      {
        *pdata8bits = (uint8_t)(hlpuart->Instance->RDR & (uint8_t)uhMask);
        pdata8bits++;
      }
      hlpuart->RxXferCount--;
    }

    /* At end of Rx process, restore hlpuart->RxState to Ready */
    hlpuart->RxState = HAL_LPUART_STATE_READY;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Send an amount of data in interrupt mode.
  * @note   When LPUART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @param hlpuart LPUART handle.
  * @param pData Pointer to data buffer (u8 or u16 data elements).
  * @param Size  Amount of data elements (u8 or u16 or u32) to be sent.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_Transmit_IT(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size)
{
  /* Check that a Tx process is not already ongoing */
  if (hlpuart->gState == HAL_LPUART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(hlpuart);

    hlpuart->pTxBuffPtr  = pData;
    hlpuart->TxXferSize  = Size;
    hlpuart->TxXferCount = Size;
    hlpuart->TxISR       = NULL;

    hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;
    hlpuart->gState = HAL_LPUART_STATE_BUSY_TX;

    /* Configure Tx interrupt processing */
    if (hlpuart->FifoMode == LPUART_FIFOMODE_ENABLE)
    {
      /* Set the Tx ISR function pointer according to the data word length */
      if ((hlpuart->Init.WordLength == LPUART_WORDLENGTH_9B) && (hlpuart->Init.Parity == LPUART_PARITY_NONE))
      {
        hlpuart->TxISR = LPUART_TxISR_16BIT_FIFOEN;
      }
      else
      {
        hlpuart->TxISR = LPUART_TxISR_8BIT_FIFOEN;
      }

      __HAL_UNLOCK(hlpuart);

      /* Enable the TX FIFO threshold interrupt */
      SET_BIT(hlpuart->Instance->CR3, LPUART_CR3_TXFTIE);
    }
    else
    {
      /* Set the Tx ISR function pointer according to the data word length */
      if ((hlpuart->Init.WordLength == LPUART_WORDLENGTH_9B) && (hlpuart->Init.Parity == LPUART_PARITY_NONE))
      {
        hlpuart->TxISR = LPUART_TxISR_16BIT;
      }
      else
      {
        hlpuart->TxISR = LPUART_TxISR_8BIT;
      }

      __HAL_UNLOCK(hlpuart);

      /* Enable the Transmit Data Register Empty interrupt */
      SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_TXEIE);
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
  * @note   When LPUART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the received data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 available through pData.
  * @param hlpuart LPUART handle.
  * @param pData Pointer to data buffer (u8 or u16 data elements).
  * @param Size  Amount of data elements (u8 or u16 or u32) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_Receive_IT(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size)
{
  /* Check that a Rx process is not already ongoing */
  if (hlpuart->RxState == HAL_LPUART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(hlpuart);

    hlpuart->pRxBuffPtr  = pData;
    hlpuart->RxXferSize  = Size;
    hlpuart->RxXferCount = Size;
    hlpuart->RxISR       = NULL;

    /* Computation of LPUART mask to apply to RDR register */
    LPUART_MASK_COMPUTATION(hlpuart);

    hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;
    hlpuart->RxState = HAL_LPUART_STATE_BUSY_RX;

    /* Enable the LPUART Error Interrupt: (Frame error, noise error, overrun error) */
    SET_BIT(hlpuart->Instance->CR3, LPUART_CR3_EIE);

    /* Configure Rx interrupt processing*/
    if ((hlpuart->FifoMode == LPUART_FIFOMODE_ENABLE) && (Size >= hlpuart->NbRxDataToProcess))
    {
      /* Set the Rx ISR function pointer according to the data word length */
      if ((hlpuart->Init.WordLength == LPUART_WORDLENGTH_9B) && (hlpuart->Init.Parity == LPUART_PARITY_NONE))
      {
        hlpuart->RxISR = LPUART_RxISR_16BIT_FIFOEN;
      }
      else
      {
        hlpuart->RxISR = LPUART_RxISR_8BIT_FIFOEN;
      }

      __HAL_UNLOCK(hlpuart);

      /* Enable the LPUART Parity Error interrupt and RX FIFO Threshold interrupt */
      SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_PEIE);
      SET_BIT(hlpuart->Instance->CR3, LPUART_CR3_RXFTIE);
    }
    else
    {
      /* Set the Rx ISR function pointer according to the data word length */
      if ((hlpuart->Init.WordLength == LPUART_WORDLENGTH_9B) && (hlpuart->Init.Parity == LPUART_PARITY_NONE))
      {
        hlpuart->RxISR = LPUART_RxISR_16BIT;
      }
      else
      {
        hlpuart->RxISR = LPUART_RxISR_8BIT;
      }

      __HAL_UNLOCK(hlpuart);

      /* Enable the LPUART Parity Error interrupt and Data Register Not Empty interrupt */
      SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_PEIE | LPUART_CR1_RXNEIE);
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
  * @note   When LPUART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @param hlpuart LPUART handle.
  * @param pData Pointer to data buffer (u8 or u16 data elements).
  * @param Size  Amount of data elements (u8 or u16 or u32) to be sent.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_Transmit_DMA(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size)
{
  /* Check that a Tx process is not already ongoing */
  if (hlpuart->gState == HAL_LPUART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(hlpuart);

    hlpuart->pTxBuffPtr  = pData;
    hlpuart->TxXferSize  = Size;
    hlpuart->TxXferCount = Size;

    hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;
    hlpuart->gState = HAL_LPUART_STATE_BUSY_TX;

    if (hlpuart->hdmatx != NULL)
    {
      /* Set the LPUART DMA transfer complete callback */
      hlpuart->hdmatx->XferCpltCallback = LPUART_DMATransmitCplt;

      /* Set the LPUART DMA Block transfer complete callback */
      hlpuart->hdmatx->XferBlockCpltCallback = LPUART_DMATxBlockCplt;

      /* Set the LPUART DMA Half Block transfer complete callback */
      hlpuart->hdmatx->XferHalfBlockCpltCallback = LPUART_DMATxHalfBlockCplt;

      /* Set the LPUART DMA Source transfer complete callback */
      hlpuart->hdmatx->XferSrcTranCpltCallback = LPUART_DMASrcTranCplt;

      /* Set the DMA error callback */
      hlpuart->hdmatx->XferErrorCallback = LPUART_DMAError;

      /* Set the DMA abort callback */
      hlpuart->hdmatx->XferAbortCallback = NULL;

      /* Enable the LPUART transmit DMA channel */
      if (HAL_DMA_Start_IT(hlpuart->hdmatx, (uint32_t)hlpuart->pTxBuffPtr, (uint32_t)&hlpuart->Instance->TDR, Size) != HAL_OK)
      {
        /* Set error code to DMA */
        hlpuart->ErrorCode = HAL_LPUART_ERROR_DMA;

        __HAL_UNLOCK(hlpuart);

        /* Restore hlpuart->gState to ready */
        hlpuart->gState = HAL_LPUART_STATE_READY;

        return HAL_ERROR;
      }
    }
    /* Clear the TC flag in the ICR register */
    __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_TCF);

    __HAL_UNLOCK(hlpuart);

    /* Enable the DMA transfer for transmit request by setting the DMAT bit
    in the LPUART CR3 register */
    SET_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in DMA mode.
  * @note   When the LPUART parity is enabled (PCE = 1), the received data contain
  *         the parity bit (MSB position).
  * @note   When LPUART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the received data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 available through pData.
  * @param hlpuart LPUART handle.
  * @param pData Pointer to data buffer (u8 or u16 data elements).
  * @param Size  Amount of data elements (u8 or u16 or u32) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_Receive_DMA(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size)
{
  /* Check that a Rx process is not already ongoing */
  if (hlpuart->RxState == HAL_LPUART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(hlpuart);

    hlpuart->pRxBuffPtr = pData;
    hlpuart->RxXferSize = Size;

    hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;
    hlpuart->RxState = HAL_LPUART_STATE_BUSY_RX;

    if (hlpuart->hdmarx != NULL)
    {
      /* Set the LPUART DMA transfer complete callback */
      hlpuart->hdmarx->XferCpltCallback = LPUART_DMAReceiveCplt;

      /* Set the LPUART DMA Block transfer complete callback */   
      hlpuart->hdmarx->XferBlockCpltCallback = LPUART_DMARxBlockCplt;

      /* Set the LPUART DMA Half Block transfer complete callback */
      hlpuart->hdmarx->XferHalfBlockCpltCallback = LPUART_DMARxHalfBlockCplt;

      /* Set the LPUART DMA Destination transfer complete callback */
      hlpuart->hdmarx->XferDstTranCpltCallback = LPUART_DMADstTranCplt;

      /* Set the DMA error callback */
      hlpuart->hdmarx->XferErrorCallback = LPUART_DMAError;

      /* Set the DMA abort callback */
      hlpuart->hdmarx->XferAbortCallback = NULL;

      /* Enable the DMA channel */
      if (HAL_DMA_Start_IT(hlpuart->hdmarx, (uint32_t)&hlpuart->Instance->RDR, (uint32_t)hlpuart->pRxBuffPtr, Size) != HAL_OK)
      {
        /* Set error code to DMA */
        hlpuart->ErrorCode = HAL_LPUART_ERROR_DMA;

        __HAL_UNLOCK(hlpuart);

        /* Restore hlpuart->gState to ready */
        hlpuart->gState = HAL_LPUART_STATE_READY;

        return HAL_ERROR;
      }
    }
    __HAL_UNLOCK(hlpuart);

    /* Enable the LPUART Parity Error Interrupt */
    SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_PEIE);

    /* Enable the LPUART Error Interrupt: (Frame error, noise error, overrun error) */
    SET_BIT(hlpuart->Instance->CR3, LPUART_CR3_EIE);

    /* Enable the DMA transfer for the receiver request by setting the DMAR bit
    in the LPUART CR3 register */
    SET_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAR);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Pause the DMA Transfer.
  * @param hlpuart LPUART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_DMAPause(LPUART_HandleTypeDef *hlpuart)
{
  const HAL_LPUART_StateTypeDef gstate = hlpuart->gState;
  const HAL_LPUART_StateTypeDef rxstate = hlpuart->RxState;

  __HAL_LOCK(hlpuart);

  if ((HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAT)) &&
      (gstate == HAL_LPUART_STATE_BUSY_TX))
  {
    /* Disable the LPUART DMA Tx request */
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAT);
  }
  if ((HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAR)) &&
      (rxstate == HAL_LPUART_STATE_BUSY_RX))
  {
    /* Disable PE and ERR (Frame error, noise error, overrun error) interrupts */
    CLEAR_BIT(hlpuart->Instance->CR1, LPUART_CR1_PEIE);
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_EIE);

    /* Disable the LPUART DMA Rx request */
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAR);
  }

  __HAL_UNLOCK(hlpuart);

  return HAL_OK;
}

/**
  * @brief Resume the DMA Transfer.
  * @param hlpuart LPUART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_DMAResume(LPUART_HandleTypeDef *hlpuart)
{
  __HAL_LOCK(hlpuart);

  if (hlpuart->gState == HAL_LPUART_STATE_BUSY_TX)
  {
    /* Enable the LPUART DMA Tx request */
    SET_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAT);
  }
  if (hlpuart->RxState == HAL_LPUART_STATE_BUSY_RX)
  {
    /* Clear the Overrun flag before resuming the Rx transfer */
    __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_OREF);

    /* Re-enable PE and ERR (Frame error, noise error, overrun error) interrupts */
    SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_PEIE);
    SET_BIT(hlpuart->Instance->CR3, LPUART_CR3_EIE);

    /* Enable the LPUART DMA Rx request */
    SET_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAR);
  }

  __HAL_UNLOCK(hlpuart);

  return HAL_OK;
}

/**
  * @brief Stop the DMA Transfer.
  * @param hlpuart LPUART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_DMAStop(LPUART_HandleTypeDef *hlpuart)
{
  /* The Lock is not implemented on this API to allow the user application
     to call the HAL LPUART API under callbacks 
     HAL_LPUART_TxCpltCallback()        / HAL_LPUART_RxCpltCallback()        /
     HAL_LPUART_TxBlockCpltCallback     / HAL_LPUART_RxBlokCpltCallback      /
     HAL_LPUART_TxHalfBlockCpltCallback / HAL_LPUART_RxHalfBlockCpltCallback /
     HAL_LPUART_TxSrcCpltCallback       / HAL_LPUART_RxDstCpltCallback:
     indeed, when HAL_DMA_Abort() API is called, the DMA TX/RX Transfer or Half Transfer complete
     interrupt is generated if the DMA transfer interruption occurs at the middle or at the end of
     the stream and the corresponding call back is executed. */

  const HAL_LPUART_StateTypeDef gstate = hlpuart->gState;
  const HAL_LPUART_StateTypeDef rxstate = hlpuart->RxState;

  /* Stop LPUART DMA Tx request if ongoing */
  if ((HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAT)) &&
      (gstate == HAL_LPUART_STATE_BUSY_TX))
  {
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAT);

    /* Abort the LPUART DMA Tx channel */
    if (hlpuart->hdmatx != NULL)
    {
      if (HAL_DMA_Abort(hlpuart->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hlpuart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hlpuart->ErrorCode = HAL_LPUART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }

    LPUART_EndTxTransfer(hlpuart);
  }

  /* Stop LPUART DMA Rx request if ongoing */
  if ((HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAR)) &&
      (rxstate == HAL_LPUART_STATE_BUSY_RX))
  {
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAR);

    /* Abort the LPUART DMA Rx channel */
    if (hlpuart->hdmarx != NULL)
    {
      if (HAL_DMA_Abort(hlpuart->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hlpuart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hlpuart->ErrorCode = HAL_LPUART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }

    LPUART_EndRxTransfer(hlpuart);
  }

  return HAL_OK;
}

/**
  * @brief  Abort ongoing transfers (blocking mode).
  * @param  hlpuart LPUART handle.
  * @note   This procedure could be used for aborting any ongoing transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable LPUART Interrupts (Tx and Rx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort (in case of transfer in DMA mode)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_Abort(LPUART_HandleTypeDef *hlpuart)
{
  /* Disable TXE, TC, RXNE, PE, RXFT, TXFT and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_RXNEIE | LPUART_CR1_PEIE | LPUART_CR1_TXEIE | LPUART_CR1_TCIE));
  CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_EIE | LPUART_CR3_RXFTIE | LPUART_CR3_TXFTIE);

  /* Disable the LPUART DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAT))
  {
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAT);

    /* Abort the LPUART DMA Tx channel : use blocking DMA Abort API (no callback) */
    if (hlpuart->hdmatx != NULL)
    {
      /* Set the LPUART DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      hlpuart->hdmatx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(hlpuart->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hlpuart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hlpuart->ErrorCode = HAL_LPUART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
  }

  /* Disable the LPUART DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAR))
  {
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAR);

    /* Abort the LPUART DMA Rx channel : use blocking DMA Abort API (no callback) */
    if (hlpuart->hdmarx != NULL)
    {
      /* Set the LPUART DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      hlpuart->hdmarx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(hlpuart->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hlpuart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hlpuart->ErrorCode = HAL_LPUART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
  }

  /* Reset Tx and Rx transfer counters */
  hlpuart->TxXferCount = 0U;
  hlpuart->RxXferCount = 0U;

  /* Clear the Error flags in the ICR register */
  __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_OREF | LPUART_CLEAR_NEF | LPUART_CLEAR_PEF | LPUART_CLEAR_FEF);

  /* Flush the whole TX FIFO (if needed) */
  if (hlpuart->FifoMode == LPUART_FIFOMODE_ENABLE)
  {
    __HAL_LPUART_SEND_REQ(hlpuart, LPUART_TXDATA_FLUSH_REQUEST);
  }

  /* Discard the received data */
  __HAL_LPUART_SEND_REQ(hlpuart, LPUART_RXDATA_FLUSH_REQUEST);

  /* Restore hlpuart->gState and hlpuart->RxState to Ready */
  hlpuart->gState  = HAL_LPUART_STATE_READY;
  hlpuart->RxState = HAL_LPUART_STATE_READY;

  hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Transmit transfer (blocking mode).
  * @param  hlpuart LPUART handle.
  * @note   This procedure could be used for aborting any ongoing Tx transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable LPUART Interrupts (Tx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort (in case of transfer in DMA mode)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_AbortTransmit(LPUART_HandleTypeDef *hlpuart)
{
  /* Disable TCIE, TXEIE and TXFTIE interrupts */
  CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_TCIE | LPUART_CR1_TXEIE));
  CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_TXFTIE);

  /* Disable the LPUART DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAT))
  {
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAT);

    /* Abort the LPUART DMA Tx channel : use blocking DMA Abort API (no callback) */
    if (hlpuart->hdmatx != NULL)
    {
      /* Set the LPUART DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      hlpuart->hdmatx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(hlpuart->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hlpuart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hlpuart->ErrorCode = HAL_LPUART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
  }

  /* Reset Tx transfer counter */
  hlpuart->TxXferCount = 0U;

  /* Flush the whole TX FIFO (if needed) */
  if (hlpuart->FifoMode == LPUART_FIFOMODE_ENABLE)
  {
    __HAL_LPUART_SEND_REQ(hlpuart, LPUART_TXDATA_FLUSH_REQUEST);
  }

  /* Restore hlpuart->gState to Ready */
  hlpuart->gState = HAL_LPUART_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Receive transfer (blocking mode).
  * @param  hlpuart LPUART handle.
  * @note   This procedure could be used for aborting any ongoing Rx transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable LPUART Interrupts (Rx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort (in case of transfer in DMA mode)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_AbortReceive(LPUART_HandleTypeDef *hlpuart)
{
  /* Disable PEIE, EIE, RXNEIE and RXFTIE interrupts */
  CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_PEIE | LPUART_CR1_RXNEIE));
  CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_EIE | LPUART_CR3_RXFTIE);

  /* Disable the LPUART DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAR))
  {
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAR);

    /* Abort the LPUART DMA Rx channel : use blocking DMA Abort API (no callback) */
    if (hlpuart->hdmarx != NULL)
    {
      /* Set the LPUART DMA Abort callback to Null.
         No call back execution at end of DMA abort procedure */
      hlpuart->hdmarx->XferAbortCallback = NULL;

      if (HAL_DMA_Abort(hlpuart->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(hlpuart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          hlpuart->ErrorCode = HAL_LPUART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
  }

  /* Reset Rx transfer counter */
  hlpuart->RxXferCount = 0U;

  /* Clear the Error flags in the ICR register */
  __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_OREF | LPUART_CLEAR_NEF | LPUART_CLEAR_PEF | LPUART_CLEAR_FEF);

  /* Discard the received data */
  __HAL_LPUART_SEND_REQ(hlpuart, LPUART_RXDATA_FLUSH_REQUEST);

  /* Restore hlpuart->RxState to Ready */
  hlpuart->RxState = HAL_LPUART_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing transfers (Interrupt mode).
  * @param  hlpuart LPUART handle.
  * @note   This procedure could be used for aborting any ongoing transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable LPUART Interrupts (Tx and Rx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort_IT (in case of transfer in DMA mode)
  *           - Set handle State to READY
  *           - At abort completion, call user abort complete callback
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_Abort_IT(LPUART_HandleTypeDef *hlpuart)
{
  uint32_t abortcplt = 1U;

  /* Disable interrupts */
  CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_PEIE | LPUART_CR1_TCIE | LPUART_CR1_RXNEIE |  LPUART_CR1_TXEIE));
  CLEAR_BIT(hlpuart->Instance->CR3, (LPUART_CR3_EIE | LPUART_CR3_RXFTIE | LPUART_CR3_TXFTIE));

  /* If DMA Tx and/or DMA Rx Handles are associated to LPUART handle, DMA Abort complete callbacks should be initialised
     before any call to DMA Abort functions */
  /* DMA Tx Handle is valid */
  if (hlpuart->hdmatx != NULL)
  {
    /* Set DMA Abort Complete callback if LPUART DMA Tx request if enabled.
       Otherwise, set it to NULL */
    if (HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAT))
    {
      hlpuart->hdmatx->XferAbortCallback = LPUART_DMATxAbortCallback;
    }
    else
    {
      hlpuart->hdmatx->XferAbortCallback = NULL;
    }
  }
  /* DMA Rx Handle is valid */
  if (hlpuart->hdmarx != NULL)
  {
    /* Set DMA Abort Complete callback if LPUART DMA Rx request if enabled.
       Otherwise, set it to NULL */
    if (HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAR))
    {
      hlpuart->hdmarx->XferAbortCallback = LPUART_DMARxAbortCallback;
    }
    else
    {
      hlpuart->hdmarx->XferAbortCallback = NULL;
    }
  }

  /* Disable the LPUART DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAT))
  {
    /* Disable DMA Tx at LPUART level */
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAT);

    /* Abort the LPUART DMA Tx channel : use non blocking DMA Abort API (callback) */
    if (hlpuart->hdmatx != NULL)
    {
      /* LPUART Tx DMA Abort callback has already been initialised :
         will lead to call HAL_LPUART_AbortCpltCallback() at end of DMA abort procedure */

      /* Abort DMA TX */
      if (HAL_DMA_Abort_IT(hlpuart->hdmatx) != HAL_OK)
      {
        hlpuart->hdmatx->XferAbortCallback = NULL;
      }
      else
      {
        abortcplt = 0U;
      }
    }
  }

  /* Disable the LPUART DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAR))
  {
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAR);

    /* Abort the LPUART DMA Rx channel : use non blocking DMA Abort API (callback) */
    if (hlpuart->hdmarx != NULL)
    {
      /* LPUART Rx DMA Abort callback has already been initialised :
         will lead to call HAL_LPUART_AbortCpltCallback() at end of DMA abort procedure */

      /* Abort DMA RX */
      if (HAL_DMA_Abort_IT(hlpuart->hdmarx) != HAL_OK)
      {
        hlpuart->hdmarx->XferAbortCallback = NULL;
        abortcplt = 1U;
      }
      else
      {
        abortcplt = 0U;
      }
    }
  }

  /* if no DMA abort complete callback execution is required => call user Abort Complete callback */
  if (abortcplt == 1U)
  {
    /* Reset Tx and Rx transfer counters */
    hlpuart->TxXferCount = 0U;
    hlpuart->RxXferCount = 0U;

    /* Clear ISR function pointers */
    hlpuart->RxISR = NULL;
    hlpuart->TxISR = NULL;

    /* Reset errorCode */
    hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;

    /* Clear the Error flags in the ICR register */
    __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_OREF | LPUART_CLEAR_NEF | LPUART_CLEAR_PEF | LPUART_CLEAR_FEF);

    /* Flush the whole TX FIFO (if needed) */
    if (hlpuart->FifoMode == LPUART_FIFOMODE_ENABLE)
    {
      __HAL_LPUART_SEND_REQ(hlpuart, LPUART_TXDATA_FLUSH_REQUEST);
    }

    /* Discard the received data */
    __HAL_LPUART_SEND_REQ(hlpuart, LPUART_RXDATA_FLUSH_REQUEST);

    /* Restore hlpuart->gState and hlpuart->RxState to Ready */
    hlpuart->gState  = HAL_LPUART_STATE_READY;
    hlpuart->RxState = HAL_LPUART_STATE_READY;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
    /* Call registered Abort complete callback */
    hlpuart->AbortCpltCallback(hlpuart);
#else
    /* Call legacy weak Abort complete callback */
    HAL_LPUART_AbortCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
  }

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Transmit transfer (Interrupt mode).
  * @param  hlpuart LPUART handle.
  * @note   This procedure could be used for aborting any ongoing Tx transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable LPUART Interrupts (Tx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort_IT (in case of transfer in DMA mode)
  *           - Set handle State to READY
  *           - At abort completion, call user abort complete callback
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_AbortTransmit_IT(LPUART_HandleTypeDef *hlpuart)
{
  /* Disable interrupts */
  CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_TCIE | LPUART_CR1_TXEIE));
  CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_TXFTIE);

  /* Disable the LPUART DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAT))
  {
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAT);

    /* Abort the LPUART DMA Tx channel : use non blocking DMA Abort API (callback) */
    if (hlpuart->hdmatx != NULL)
    {
      /* Set the LPUART DMA Abort callback :
         will lead to call HAL_LPUART_AbortCpltCallback() at end of DMA abort procedure */
      hlpuart->hdmatx->XferAbortCallback = LPUART_DMATxOnlyAbortCallback;

      /* Abort DMA TX */
      if (HAL_DMA_Abort_IT(hlpuart->hdmatx) != HAL_OK)
      {
        /* Call Directly hlpuart->hdmatx->XferAbortCallback function in case of error */
        hlpuart->hdmatx->XferAbortCallback(hlpuart->hdmatx);
      }
    }
    else
    {
      /* Reset Tx transfer counter */
      hlpuart->TxXferCount = 0U;

      /* Clear TxISR function pointers */
      hlpuart->TxISR = NULL;

      /* Restore hlpuart->gState to Ready */
      hlpuart->gState = HAL_LPUART_STATE_READY;

      /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
      /* Call registered Abort Transmit Complete Callback */
      hlpuart->AbortTransmitCpltCallback(hlpuart);
#else
      /* Call legacy weak Abort Transmit Complete Callback */
      HAL_LPUART_AbortTransmitCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
    }
  }
  else
  {
    /* Reset Tx transfer counter */
    hlpuart->TxXferCount = 0U;

    /* Clear TxISR function pointers */
    hlpuart->TxISR = NULL;

    /* Flush the whole TX FIFO (if needed) */
    if (hlpuart->FifoMode == LPUART_FIFOMODE_ENABLE)
    {
      __HAL_LPUART_SEND_REQ(hlpuart, LPUART_TXDATA_FLUSH_REQUEST);
    }

    /* Restore hlpuart->gState to Ready */
    hlpuart->gState = HAL_LPUART_STATE_READY;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
    /* Call registered Abort Transmit Complete Callback */
    hlpuart->AbortTransmitCpltCallback(hlpuart);
#else
    /* Call legacy weak Abort Transmit Complete Callback */
    HAL_LPUART_AbortTransmitCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
  }

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Receive transfer (Interrupt mode).
  * @param  hlpuart LPUART handle.
  * @note   This procedure could be used for aborting any ongoing Rx transfer started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable LPUART Interrupts (Rx)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort_IT (in case of transfer in DMA mode)
  *           - Set handle State to READY
  *           - At abort completion, call user abort complete callback
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_AbortReceive_IT(LPUART_HandleTypeDef *hlpuart)
{
  /* Disable RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_PEIE | LPUART_CR1_RXNEIE));
  CLEAR_BIT(hlpuart->Instance->CR3, (LPUART_CR3_EIE | LPUART_CR3_RXFTIE));

  /* Disable the LPUART DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAR))
  {
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAR);

    /* Abort the LPUART DMA Rx channel : use non blocking DMA Abort API (callback) */
    if (hlpuart->hdmarx != NULL)
    {
      /* Set the LPUART DMA Abort callback :
         will lead to call HAL_LPUART_AbortCpltCallback() at end of DMA abort procedure */
      hlpuart->hdmarx->XferAbortCallback = LPUART_DMARxOnlyAbortCallback;

      /* Abort DMA RX */
      if (HAL_DMA_Abort_IT(hlpuart->hdmarx) != HAL_OK)
      {
        /* Call Directly hlpuart->hdmarx->XferAbortCallback function in case of error */
        hlpuart->hdmarx->XferAbortCallback(hlpuart->hdmarx);
      }
    }
    else
    {
      /* Reset Rx transfer counter */
      hlpuart->RxXferCount = 0U;

      /* Clear RxISR function pointer */
      hlpuart->pRxBuffPtr = NULL;

      /* Clear the Error flags in the ICR register */
      __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_OREF | LPUART_CLEAR_NEF | LPUART_CLEAR_PEF | LPUART_CLEAR_FEF);

      /* Discard the received data */
      __HAL_LPUART_SEND_REQ(hlpuart, LPUART_RXDATA_FLUSH_REQUEST);

      /* Restore hlpuart->RxState to Ready */
      hlpuart->RxState = HAL_LPUART_STATE_READY;

      /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
      /* Call registered Abort Receive Complete Callback */
      hlpuart->AbortReceiveCpltCallback(hlpuart);
#else
      /* Call legacy weak Abort Receive Complete Callback */
      HAL_LPUART_AbortReceiveCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
    }
  }
  else
  {
    /* Reset Rx transfer counter */
    hlpuart->RxXferCount = 0U;

    /* Clear RxISR function pointer */
    hlpuart->pRxBuffPtr = NULL;

    /* Clear the Error flags in the ICR register */
    __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_OREF | LPUART_CLEAR_NEF | LPUART_CLEAR_PEF | LPUART_CLEAR_FEF);

    /* Restore hlpuart->RxState to Ready */
    hlpuart->RxState = HAL_LPUART_STATE_READY;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
    /* Call registered Abort Receive Complete Callback */
    hlpuart->AbortReceiveCpltCallback(hlpuart);
#else
    /* Call legacy weak Abort Receive Complete Callback */
    HAL_LPUART_AbortReceiveCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
  }

  return HAL_OK;
}

/**
  * @brief Handle LPUART interrupt request.
  * @param hlpuart LPUART handle.
  * @retval None
  */
void HAL_LPUART_IRQHandler(LPUART_HandleTypeDef *hlpuart)
{
  uint32_t isrflags   = READ_REG(hlpuart->Instance->ISR);
  uint32_t cr1its     = READ_REG(hlpuart->Instance->CR1);
  uint32_t cr3its     = READ_REG(hlpuart->Instance->CR3);

  uint32_t errorflags;
  uint32_t errorcode;

  /* If no error occurs */
  errorflags = (isrflags & (uint32_t)(LPUART_ISR_PE | LPUART_ISR_FE | LPUART_ISR_ORE | LPUART_ISR_NE));
  if (errorflags == 0U)
  {
    /* LPUART in mode Receiver ---------------------------------------------------*/
    if (((isrflags & LPUART_ISR_RXNE) != 0U)
        && (((cr1its & LPUART_CR1_RXNEIE) != 0U)
          || ((cr3its & LPUART_CR3_RXFTIE) != 0U)))
    {
      if (hlpuart->RxISR != NULL)
      {
        hlpuart->RxISR(hlpuart);
      }
      return;
    }
  }

  /* If some errors occur */
  if ((errorflags != 0U)
      && ((((cr3its & (LPUART_CR3_RXFTIE | LPUART_CR3_EIE)) != 0U)
           || ((cr1its & (LPUART_CR1_RXNEIE | LPUART_CR1_PEIE)) != 0U))))
  {
    /* LPUART parity error interrupt occurred -------------------------------------*/
    if (((isrflags & LPUART_ISR_PE) != 0U) && ((cr1its & LPUART_CR1_PEIE) != 0U))
    {
      __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_PEF);

      hlpuart->ErrorCode |= HAL_LPUART_ERROR_PE;
    }

    /* LPUART frame error interrupt occurred --------------------------------------*/
    if (((isrflags & LPUART_ISR_FE) != 0U) && ((cr3its & LPUART_CR3_EIE) != 0U))
    {
      __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_FEF);

      hlpuart->ErrorCode |= HAL_LPUART_ERROR_FE;
    }

    /* LPUART noise error interrupt occurred --------------------------------------*/
    if (((isrflags & LPUART_ISR_NE) != 0U) && ((cr3its & LPUART_CR3_EIE) != 0U))
    {
      __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_NEF);

      hlpuart->ErrorCode |= HAL_LPUART_ERROR_NE;
    }

    /* LPUART Over-Run interrupt occurred -----------------------------------------*/
    if (((isrflags & LPUART_ISR_ORE) != 0U)
        && (((cr1its & LPUART_CR1_RXNEIE) != 0U) ||
            ((cr3its & (LPUART_CR3_RXFTIE | LPUART_CR3_EIE)) != 0U)))
    {
      __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_OREF);

      hlpuart->ErrorCode |= HAL_LPUART_ERROR_ORE;
    }

    /* Call LPUART Error Call back function if need be ----------------------------*/
    if (hlpuart->ErrorCode != HAL_LPUART_ERROR_NONE)
    {
      /* LPUART in mode Receiver --------------------------------------------------*/
      if (((isrflags & LPUART_ISR_RXNE) != 0U)
          && (((cr1its & LPUART_CR1_RXNEIE) != 0U)
              || ((cr3its & LPUART_CR3_RXFTIE) != 0U)))
      {
        if (hlpuart->RxISR != NULL)
        {
          hlpuart->RxISR(hlpuart);
        }
      }

      /* If Error is to be considered as blocking :
          - Receiver Timeout error in Reception
          - Overrun error in Reception
          - any error occurs in DMA mode reception
      */
      errorcode = hlpuart->ErrorCode;
      if ((HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAR)) ||
          ((errorcode & (HAL_LPUART_ERROR_RTO | HAL_LPUART_ERROR_ORE)) != 0U))
      {
        /* Blocking error : transfer is aborted
           Set the LPUART state ready to be able to start again the process,
           Disable Rx Interrupts, and disable Rx DMA request, if ongoing */
        LPUART_EndRxTransfer(hlpuart);

        /* Disable the LPUART DMA Rx request if enabled */
        if (HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAR))
        {
          CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAR);

          /* Abort the LPUART DMA Rx channel */
          if (hlpuart->hdmarx != NULL)
          {
            /* Set the LPUART DMA Abort callback :
               will lead to call HAL_LPUART_ErrorCallback() at end of DMA abort procedure */
            hlpuart->hdmarx->XferAbortCallback = LPUART_DMAAbortOnError;

            /* Abort DMA RX */
            if (HAL_DMA_Abort_IT(hlpuart->hdmarx) != HAL_OK)
            {
              /* Call Directly hlpuart->hdmarx->XferAbortCallback function in case of error */
              hlpuart->hdmarx->XferAbortCallback(hlpuart->hdmarx);
            }
          }
          else
          {
            /* Call user error callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
            /*Call registered error callback*/
            hlpuart->ErrorCallback(hlpuart);
#else
            /*Call legacy weak error callback*/
            HAL_LPUART_ErrorCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */

          }
        }
        else
        {
          /* Call user error callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
          /*Call registered error callback*/
          hlpuart->ErrorCallback(hlpuart);
#else
          /*Call legacy weak error callback*/
          HAL_LPUART_ErrorCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
        }
      }
      else
      {
        /* Non Blocking error : transfer could go on.
           Error is notified to user through user error callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
        /*Call registered error callback*/
        hlpuart->ErrorCallback(hlpuart);
#else
        /*Call legacy weak error callback*/
        HAL_LPUART_ErrorCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
        hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;
      }
    }
    return;

  } /* End if some error occurs */

  /* LPUART wakeup from Stop mode interrupt occurred ---------------------------*/
  if (((isrflags & LPUART_ISR_WUF) != 0U) && ((cr3its & LPUART_CR3_WUFIE) != 0U))
  {
    __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_WUF);

    /* LPUART Rx state is not reset as a reception process might be ongoing.
       If LPUART handle state fields need to be reset to READY, this could be done in Wakeup callback */

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
    /* Call registered Wakeup Callback */
    hlpuart->WakeupCallback(hlpuart);
#else
    /* Call legacy weak Wakeup Callback */
    HAL_LPUARTEx_WakeupCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
    return;
  }

  /* LPUART in mode Transmitter ------------------------------------------------*/
  if (((isrflags & LPUART_ISR_TXE) != 0U)
      && (((cr1its & LPUART_CR1_TXEIE) != 0U)
          || ((cr3its & LPUART_CR3_TXFTIE) != 0U)))
  {
    if (hlpuart->TxISR != NULL)
    {
      hlpuart->TxISR(hlpuart);
    }
    return;
  }

  /* LPUART in mode Transmitter (transmission end) -----------------------------*/
  if (((isrflags & LPUART_ISR_TC) != 0U) && ((cr1its & LPUART_CR1_TCIE) != 0U))
  {
    LPUART_EndTransmit_IT(hlpuart);
    return;
  }

  /* LPUART TX Fifo Empty occurred ----------------------------------------------*/
  if (((isrflags & LPUART_ISR_TXFE) != 0U) && ((cr1its & LPUART_CR1_TXFEIE) != 0U))
  {
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
    /* Call registered Tx Fifo Empty Callback */
    hlpuart->TxFifoEmptyCallback(hlpuart);
#else
    /* Call legacy weak Tx Fifo Empty Callback */
    HAL_LPUARTEx_TxFifoEmptyCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
    return;
  }

  /* LPUART RX Fifo Full occurred ----------------------------------------------*/
  if (((isrflags & LPUART_ISR_RXFF) != 0U) && ((cr1its & LPUART_CR1_RXFFIE) != 0U))
  {
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
    /* Call registered Rx Fifo Full Callback */
    hlpuart->RxFifoFullCallback(hlpuart);
#else
    /* Call legacy weak Rx Fifo Full Callback */
    HAL_LPUARTEx_RxFifoFullCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
    return;
  }
}

/**
  * @brief Tx Transfer completed callback.
  * @param hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_TxCpltCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LPUART_TxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx Block Transfer completed callback.
  * @param  hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_TxBlockCpltCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_LPUART_TxBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx Half Block Transfer completed callback.
  * @param  hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_TxHalfBlockCpltCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_LPUART_TxHalfBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx Source Transfer completed callback.
  * @param  hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_TxSrcCpltCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_LPUART_TxSrcCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Transfer completed callback.
  * @param  hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_RxCpltCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LPUART_RxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Block Transfer completed callback.
  * @param  hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_RxBlockCpltCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_LPUART_RxBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Half Block Transfer completed callback.
  * @param  hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_RxHalfBlockCpltCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_LPUART_RxHalfBlockCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Destination Transfer completed callback.
  * @param  hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_RxDstCpltCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_LPUART_RxDstCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  LPUART error callback.
  * @param  hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_ErrorCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LPUART_ErrorCallback can be implemented in the user file.
   */
}

/**
  * @brief  LPUART Abort Complete callback.
  * @param  hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_AbortCpltCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LPUART_AbortCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  LPUART Abort Complete callback.
  * @param  hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_AbortTransmitCpltCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LPUART_AbortTransmitCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  LPUART Abort Receive Complete callback.
  * @param  hlpuart LPUART handle.
  * @retval None
  */
__weak void HAL_LPUART_AbortReceiveCpltCallback(LPUART_HandleTypeDef *hlpuart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlpuart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LPUART_AbortReceiveCpltCallback can be implemented in the user file.
   */
}

/**
  * @}
  */

/** @defgroup LPUART_Exported_Functions_Group3 Peripheral Control functions
  *  @brief   LPUART control functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the LPUART.
     (+) HAL_MultiProcessor_EnableMuteMode() API enables mute mode
     (+) HAL_MultiProcessor_DisableMuteMode() API disables mute mode
     (+) HAL_MultiProcessor_EnterMuteMode() API enters mute mode
     (+) LPUART_SetConfig() API configures the LPUART peripheral
     (+) LPUART_AdvFeatureConfig() API optionally configures the LPUART advanced features
     (+) LPUART_CheckIdleState() API ensures that TEACK and/or REACK are set after initialization
     (+) HAL_LPUART_HalfDuplex_EnableTransmitter() API disables receiver and enables transmitter
     (+) HAL_LPUART_HalfDuplex_EnableReceiver() API disables transmitter and enables receiver
@endverbatim
  * @{
  */

/**
  * @brief  Enable LPUART in mute mode (does not mean LPUART enters mute mode;
  *         to enter mute mode, HAL_MultiProcessor_EnterMuteMode() API must be called).
  * @param  hlpuart LPUART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_MultiProcessor_EnableMuteMode(LPUART_HandleTypeDef *hlpuart)
{
  __HAL_LOCK(hlpuart);

  hlpuart->gState = HAL_LPUART_STATE_BUSY;

  /* Enable LPUART mute mode by setting the MME bit in the CR1 register */
  SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_MME);

  hlpuart->gState = HAL_LPUART_STATE_READY;

  return (LPUART_CheckIdleState(hlpuart));
}

/**
  * @brief  Disable LPUART mute mode (does not mean the LPUART actually exits mute mode
  *         as it may not have been in mute mode at this very moment).
  * @param  hlpuart LPUART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_MultiProcessor_DisableMuteMode(LPUART_HandleTypeDef *hlpuart)
{
  __HAL_LOCK(hlpuart);

  hlpuart->gState = HAL_LPUART_STATE_BUSY;

  /* Disable LPUART mute mode by clearing the MME bit in the CR1 register */
  CLEAR_BIT(hlpuart->Instance->CR1, LPUART_CR1_MME);

  hlpuart->gState = HAL_LPUART_STATE_READY;

  return (LPUART_CheckIdleState(hlpuart));
}

/**
  * @brief Enter LPUART mute mode (means LPUART actually enters mute mode).
  * @note  To exit from mute mode, HAL_MultiProcessor_DisableMuteMode() API must be called.
  * @param hlpuart LPUART handle.
  * @retval None
  */
void HAL_LPUART_MultiProcessor_EnterMuteMode(LPUART_HandleTypeDef *hlpuart)
{
  __HAL_LPUART_SEND_REQ(hlpuart, LPUART_MUTE_MODE_REQUEST);
}

/**
  * @brief  Enable the LPUART transmitter and disable the LPUART receiver.
  * @param  hlpuart LPUART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LPUART_HalfDuplex_EnableTransmitter(LPUART_HandleTypeDef *hlpuart)
{
  __HAL_LOCK(hlpuart);
  hlpuart->gState = HAL_LPUART_STATE_BUSY;

  /* Clear TE and RE bits */
  CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_TE | LPUART_CR1_RE));

  /* Enable the LPUART's transmit interface by setting the TE bit in the LPUART CR1 register */
  SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_TE);

  hlpuart->gState = HAL_LPUART_STATE_READY;

  __HAL_UNLOCK(hlpuart);

  return HAL_OK;
}

/**
  * @brief  Enable the LPUART receiver and disable the LPUART transmitter.
  * @param  hlpuart LPUART handle.
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_LPUART_HalfDuplex_EnableReceiver(LPUART_HandleTypeDef *hlpuart)
{
  __HAL_LOCK(hlpuart);
  hlpuart->gState = HAL_LPUART_STATE_BUSY;

  /* Clear TE and RE bits */
  CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_TE | LPUART_CR1_RE));

  /* Enable the LPUART's receive interface by setting the RE bit in the LPUART CR1 register */
  SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_RE);

  hlpuart->gState = HAL_LPUART_STATE_READY;

  __HAL_UNLOCK(hlpuart);

  return HAL_OK;
}

/**
  * @}
  */

/** @defgroup LPUART_Exported_Functions_Group4 Peripheral State and Error functions
  *  @brief   LPUART Peripheral State functions
  *
@verbatim
  ==============================================================================
            ##### Peripheral State and Error functions #####
  ==============================================================================
    [..]
    This subsection provides functions allowing to :
      (+) Return the LPUART handle state.
      (+) Return the LPUART handle error code

@endverbatim
  * @{
  */

/**
  * @brief Return the LPUART handle state.
  * @param  hlpuart Pointer to a LPUART_HandleTypeDef structure that contains
  *               the configuration information for the specified LPUART.
  * @retval HAL state
  */
HAL_LPUART_StateTypeDef HAL_LPUART_GetState(LPUART_HandleTypeDef *hlpuart)
{
  uint32_t temp1;
  uint32_t temp2;
  temp1 = hlpuart->gState;
  temp2 = hlpuart->RxState;

  return (HAL_LPUART_StateTypeDef)(temp1 | temp2);
}

/**
  * @brief  Return the LPUART handle error code.
  * @param  hlpuart Pointer to a LPUART_HandleTypeDef structure that contains
  *               the configuration information for the specified LPUART.
  * @retval LPUART Error Code
  */
uint32_t HAL_LPUART_GetError(LPUART_HandleTypeDef *hlpuart)
{
  return hlpuart->ErrorCode;
}
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup LPUART_Private_Functions LPUART Private Functions
  * @{
  */

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
/**
  * @brief  Initialize the callbacks to their default values.
  * @param  hlpuart LPUART handle.
  * @retval none
  */
void LPUART_InitCallbacksToDefault(LPUART_HandleTypeDef *hlpuart)
{
  /* Init the LPUART Callback settings */
  hlpuart->TxBlockCpltCallback       = HAL_LPUART_TxBlockCpltCallback;       /* Legacy weak TxBlockCpltCallback       */
  hlpuart->TxHalfBlockCpltCallback   = HAL_LPUART_TxHalfBlockCpltCallback;   /* Legacy weak TxHalfBlockCpltCallback   */
  hlpuart->TxSrcCpltCallback         = HAL_LPUART_TxSrcCpltCallback;         /* Legacy weak TxSrcCpltCallback         */
  hlpuart->TxCpltCallback            = HAL_LPUART_TxCpltCallback;            /* Legacy weak TxCpltCallback            */
  hlpuart->RxBlockCpltCallback       = HAL_LPUART_RxBlockCpltCallback;       /* Legacy weak RxBlockCpltCallback       */
  hlpuart->RxHalfBlockCpltCallback   = HAL_LPUART_RxHalfBlockCpltCallback;   /* Legacy weak RxHalfBlockCpltCallback   */
  hlpuart->RxDstCpltCallback         = HAL_LPUART_RxDstCpltCallback;         /* Legacy weak RxDstCpltCallback         */
  hlpuart->RxCpltCallback            = HAL_LPUART_RxCpltCallback;            /* Legacy weak RxCpltCallback            */
  hlpuart->ErrorCallback             = HAL_LPUART_ErrorCallback;             /* Legacy weak ErrorCallback             */
  hlpuart->AbortCpltCallback         = HAL_LPUART_AbortCpltCallback;         /* Legacy weak AbortCpltCallback         */
  hlpuart->AbortTransmitCpltCallback = HAL_LPUART_AbortTransmitCpltCallback; /* Legacy weak AbortTransmitCpltCallback */
  hlpuart->AbortReceiveCpltCallback  = HAL_LPUART_AbortReceiveCpltCallback;  /* Legacy weak AbortReceiveCpltCallback  */
  hlpuart->WakeupCallback            = HAL_LPUARTEx_WakeupCallback;          /* Legacy weak WakeupCallback            */
  hlpuart->RxFifoFullCallback        = HAL_LPUARTEx_RxFifoFullCallback;      /* Legacy weak RxFifoFullCallback        */
  hlpuart->TxFifoEmptyCallback       = HAL_LPUARTEx_TxFifoEmptyCallback;     /* Legacy weak TxFifoEmptyCallback       */

}
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */

/**
  * @brief Configure the LPUART peripheral.
  * @param hlpuart LPUART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef LPUART_SetConfig(LPUART_HandleTypeDef *hlpuart)
{
  uint32_t tmpreg;
  uint32_t LPUARTdiv;
  HAL_StatusTypeDef ret               = HAL_OK;
  uint32_t lpuart_ker_ck_pres;
  uint32_t clockfreq;

  /* Check the parameters */
  assert_param(IS_LPUART_BAUDRATE(hlpuart->Init.BaudRate));
  assert_param(IS_LPUART_WORD_LENGTH(hlpuart->Init.WordLength));
  assert_param(IS_LPUART_STOPBITS(hlpuart->Init.StopBits));
  assert_param(IS_LPUART_PARITY(hlpuart->Init.Parity));
  assert_param(IS_LPUART_MODE(hlpuart->Init.Mode));
  assert_param(IS_LPUART_HARDWARE_FLOW_CONTROL(hlpuart->Init.HwFlowCtl));
  assert_param(IS_LPUART_PRESCALER(hlpuart->Init.ClockPrescaler));

  /*-------------------------- LPUART CR1 Configuration -----------------------*/
  /* Clear M, PCE, PS, TE and RE bits and configure
  *  the LPUART Word Length, Parityand Mode:
  *  set the M bits according to hlpuart->Init.WordLength value
  *  set PCE and PS bits according to hlpuart->Init.Parity value
  *  set TE and RE bits according to hlpuart->Init.Mode value*/
  tmpreg = (uint32_t)(hlpuart->Init.WordLength | hlpuart->Init.Parity | hlpuart->Init.Mode);
  tmpreg |= (uint32_t)hlpuart->FifoMode;
  MODIFY_REG(hlpuart->Instance->CR1, LPUART_CR1_FIELDS, tmpreg);

  /*-------------------------- LPUART CR2 Configuration -----------------------*/
  /* Configure the LPUART Stop Bits: Set STOP[13:12] bits according
  * to hlpuart->Init.StopBits value */
  MODIFY_REG(hlpuart->Instance->CR2, LPUART_CR2_STOP, hlpuart->Init.StopBits);

  /*-------------------------- LPUART CR3 Configuration -----------------------*/
  /* Configure
  * - LPUART HardWare Flow Control: set CTSE and RTSE bits according
  *   to hlpuart->Init.HwFlowCtl value */
  tmpreg = (uint32_t)hlpuart->Init.HwFlowCtl;

  MODIFY_REG(hlpuart->Instance->CR3, LPUART_CR3_FIELDS, tmpreg);

  /*-------------------------- LPUART PRESC Configuration -----------------------*/
  /* Configure
  * - LPUART Clock Prescaler : set PRESCALER according to hlpuart->Init.ClockPrescaler value */
  MODIFY_REG(hlpuart->Instance->PRESC, LPUART_PRESC_PRESCALER, hlpuart->Init.ClockPrescaler);

  /*-------------------------- LPUART BRR Configuration -----------------------*/
  clockfreq = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_LPUART1);

  /* If proper clock source reported */
  if (clockfreq != 0U)
  {
    /* Compute clock after Prescaler */
    lpuart_ker_ck_pres = (clockfreq / LPUARTPrescTable[hlpuart->Init.ClockPrescaler]);

    /* Ensure that Frequency clock is in the range [3 * baudrate, 4096 * baudrate] */
    if ((lpuart_ker_ck_pres < (3U * hlpuart->Init.BaudRate)) ||
        (lpuart_ker_ck_pres > (4096U * hlpuart->Init.BaudRate)))
    {
      ret = HAL_ERROR;
    }
    else
    {
      /* Check computed LPUARTDiv value is in allocated range
         (it is forbidden to write values lower than 0x300 in the LPUART_BRR register) */
      LPUARTdiv = (uint32_t)(LPUART_DIV_LPUART(clockfreq, hlpuart->Init.BaudRate, hlpuart->Init.ClockPrescaler));
      if ((LPUARTdiv >= LPUART_BRR_MIN) && (LPUARTdiv <= LPUART_BRR_MAX))
      {
        hlpuart->Instance->BRR = LPUARTdiv;
      }
      else
      {
        ret = HAL_ERROR;
      }
    } /* if ( (lpuart_ker_ck_pres < (3 * hlpuart->Init.BaudRate) ) ||
              (lpuart_ker_ck_pres > (4096 * hlpuart->Init.BaudRate) )) */
  } /* if (clockfreq != 0) */
  
  /* Initialize the number of data to process during RX/TX ISR execution */
  hlpuart->NbTxDataToProcess = 1;
  hlpuart->NbRxDataToProcess = 1;

  /* Clear ISR function pointers */
  hlpuart->RxISR = NULL;
  hlpuart->TxISR = NULL;

  return ret;
}

/**
  * @brief Configure the LPUART peripheral advanced features.
  * @param hlpuart LPUART handle.
  * @retval None
  */
void LPUART_AdvFeatureConfig(LPUART_HandleTypeDef *hlpuart)
{
  /* Check whether the set of advanced features to configure is properly set */
  assert_param(IS_LPUART_ADVFEATURE_INIT(hlpuart->AdvancedInit.AdvFeatureInit));

  /* if required, configure TX pin active level inversion */
  if (HAL_IS_BIT_SET(hlpuart->AdvancedInit.AdvFeatureInit, LPUART_ADVFEATURE_TXINVERT_INIT))
  {
    assert_param(IS_LPUART_ADVFEATURE_TXINV(hlpuart->AdvancedInit.TxPinLevelInvert));
    MODIFY_REG(hlpuart->Instance->CR2, LPUART_CR2_TXINV, hlpuart->AdvancedInit.TxPinLevelInvert);
  }

  /* if required, configure RX pin active level inversion */
  if (HAL_IS_BIT_SET(hlpuart->AdvancedInit.AdvFeatureInit, LPUART_ADVFEATURE_RXINVERT_INIT))
  {
    assert_param(IS_LPUART_ADVFEATURE_RXINV(hlpuart->AdvancedInit.RxPinLevelInvert));
    MODIFY_REG(hlpuart->Instance->CR2, LPUART_CR2_RXINV, hlpuart->AdvancedInit.RxPinLevelInvert);
  }

  /* if required, configure data inversion */
  if (HAL_IS_BIT_SET(hlpuart->AdvancedInit.AdvFeatureInit, LPUART_ADVFEATURE_DATAINVERT_INIT))
  {
    assert_param(IS_LPUART_ADVFEATURE_DATAINV(hlpuart->AdvancedInit.DataInvert));
    MODIFY_REG(hlpuart->Instance->CR2, LPUART_CR2_DATAINV, hlpuart->AdvancedInit.DataInvert);
  }

  /* if required, configure RX/TX pins swap */
  if (HAL_IS_BIT_SET(hlpuart->AdvancedInit.AdvFeatureInit, LPUART_ADVFEATURE_SWAP_INIT))
  {
    assert_param(IS_LPUART_ADVFEATURE_SWAP(hlpuart->AdvancedInit.Swap));
    MODIFY_REG(hlpuart->Instance->CR2, LPUART_CR2_SWAP, hlpuart->AdvancedInit.Swap);
  }

  /* if required, configure RX overrun detection disabling */
  if (HAL_IS_BIT_SET(hlpuart->AdvancedInit.AdvFeatureInit, LPUART_ADVFEATURE_RXOVERRUNDISABLE_INIT))
  {
    assert_param(IS_LPUART_OVERRUN(hlpuart->AdvancedInit.OverrunDisable));
    MODIFY_REG(hlpuart->Instance->CR3, LPUART_CR3_OVRDIS, hlpuart->AdvancedInit.OverrunDisable);
  }

  /* if required, configure DMA disabling on reception error */
  if (HAL_IS_BIT_SET(hlpuart->AdvancedInit.AdvFeatureInit, LPUART_ADVFEATURE_DMADISABLEONERROR_INIT))
  {
    assert_param(IS_LPUART_ADVFEATURE_DMAONRXERROR(hlpuart->AdvancedInit.DMADisableonRxError));
    MODIFY_REG(hlpuart->Instance->CR3, LPUART_CR3_DDRE, hlpuart->AdvancedInit.DMADisableonRxError);
  }

  /* if required, configure MSB first on communication line */
  if (HAL_IS_BIT_SET(hlpuart->AdvancedInit.AdvFeatureInit, LPUART_ADVFEATURE_MSBFIRST_INIT))
  {
    assert_param(IS_LPUART_ADVFEATURE_MSBFIRST(hlpuart->AdvancedInit.MSBFirst));
    MODIFY_REG(hlpuart->Instance->CR2, LPUART_CR2_MSBFIRST, hlpuart->AdvancedInit.MSBFirst);
  }
}

/**
  * @brief Check the LPUART Idle State.
  * @param hlpuart LPUART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef LPUART_CheckIdleState(LPUART_HandleTypeDef *hlpuart)
{
  uint32_t tickstart;

  /* Initialize the LPUART ErrorCode */
  hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;

  /* Init tickstart for timeout management */
  tickstart = HAL_GetTick();

  /* Check if the Transmitter is enabled */
  if ((hlpuart->Instance->CR1 & LPUART_CR1_TE) == LPUART_CR1_TE)
  {
    /* Wait until TEACK flag is set */
    if (LPUART_WaitOnFlagUntilTimeout(hlpuart, LPUART_ISR_TEACK, RESET, tickstart, HAL_LPUART_TIMEOUT_VALUE) != HAL_OK)
    {
      /* Timeout occurred */
      return HAL_TIMEOUT;
    }
  }

  /* Check if the Receiver is enabled */
  if ((hlpuart->Instance->CR1 & LPUART_CR1_RE) == LPUART_CR1_RE)
  {
    /* Wait until REACK flag is set */
    if (LPUART_WaitOnFlagUntilTimeout(hlpuart, LPUART_ISR_REACK, RESET, tickstart, HAL_LPUART_TIMEOUT_VALUE) != HAL_OK)
    {
      /* Timeout occurred */
      return HAL_TIMEOUT;
    }
  }

  /* Initialize the LPUART State */
  hlpuart->gState = HAL_LPUART_STATE_READY;
  hlpuart->RxState = HAL_LPUART_STATE_READY;

  __HAL_UNLOCK(hlpuart);

  return HAL_OK;
}

/**
  * @brief  Handle LPUART Communication Timeout.  Public use
  * @param hlpuart     LPUART handle.
  * @param Flag      Specifies the LPUART flag to check
  * @param Status    Flag status (SET or RESET)
  * @param Tickstart Tick start value
  * @param Timeout   Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef LPUART_WaitOnFlagUntilTimeout(LPUART_HandleTypeDef *hlpuart, uint32_t Flag, FlagStatus Status,
                                              uint32_t Tickstart, uint32_t Timeout)
{
  /* Wait until flag is set */
  while ((__HAL_LPUART_GET_FLAG(hlpuart, Flag) ? SET : RESET) == Status)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - Tickstart) > Timeout) || (Timeout == 0U))
      {
        return HAL_TIMEOUT;
      }

      if ((READ_BIT(hlpuart->Instance->CR1, USART_CR1_RE) != 0U) && (Flag != UART_FLAG_TXE) && (Flag != LPUART_FLAG_TC))
      {
        if (__HAL_LPUART_GET_FLAG(hlpuart, LPUART_FLAG_ORE) == SET)
        {
          /* Clear Overrun Error flag*/
          __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_OREF);

          /* Blocking error : transfer is aborted
          Set the UART state ready to be able to start again the process,
          Disable Rx Interrupts if ongoing */
          LPUART_EndRxTransfer(hlpuart);

          hlpuart->ErrorCode = HAL_UART_ERROR_ORE;

          /* Process Unlocked */
          __HAL_UNLOCK(hlpuart);

          return HAL_ERROR;
        }
      }
    }
  }
  return HAL_OK;
}


/**
  * @brief  End ongoing Tx transfer on LPUART peripheral (following error detection or Transmit completion).
  * @param  hlpuart LPUART handle.
  * @retval None
  */
static void LPUART_EndTxTransfer(LPUART_HandleTypeDef *hlpuart)
{
  /* Disable TXEIE, TCIE, TXFT interrupts */
  CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_TXEIE | LPUART_CR1_TCIE));
  CLEAR_BIT(hlpuart->Instance->CR3, (LPUART_CR3_TXFTIE));

  /* At end of Tx process, restore hlpuart->gState to Ready */
  hlpuart->gState = HAL_LPUART_STATE_READY;
}


/**
  * @brief  End ongoing Rx transfer on LPUART peripheral (following error detection or Reception completion).
  * @param  hlpuart LPUART handle.
  * @retval None
  */
static void LPUART_EndRxTransfer(LPUART_HandleTypeDef *hlpuart)
{
  /* Disable RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_RXNEIE | LPUART_CR1_PEIE));
  CLEAR_BIT(hlpuart->Instance->CR3, (LPUART_CR3_EIE | LPUART_CR3_RXFTIE));

  /* At end of Rx process, restore hlpuart->RxState to Ready */
  hlpuart->RxState = HAL_LPUART_STATE_READY;

  /* Reset RxIsr function pointer */
  hlpuart->RxISR = NULL;
}


/**
  * @brief DMA LPUART transmit process complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void LPUART_DMATransmitCplt(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

  /* DMA Normal mode */
  if (HAL_IS_BIT_CLR(hdma->Init.Mode, DMA_CIRCULAR))
  {
    hlpuart->TxXferCount = 0U;

    /* Disable the DMA transfer for transmit request by resetting the DMAT bit
       in the LPUART CR3 register */
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAT);

    /* Enable the LPUART Transmit Complete Interrupt */
    SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_TCIE);
  }
  /* DMA Circular mode */
  else
  {
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
    /*Call registered Tx complete callback*/
    hlpuart->TxCpltCallback(hlpuart);
#else
    /*Call legacy weak Tx complete callback*/
    HAL_LPUART_TxCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
  }
}

/**
  * @brief DMA LPUART transmit process block complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void LPUART_DMATxBlockCplt(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx Block complete callback*/
  hlpuart->TxBlockCpltCallback(hlpuart);
#else
  /*Call legacy weak Tx Block complete callback*/
  HAL_LPUART_TxBlockCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA LPUART transmit process half block complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void LPUART_DMATxHalfBlockCplt(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx Half Block complete callback*/
  hlpuart->TxHalfBlockCpltCallback(hlpuart);
#else
  /*Call legacy weak Tx Half Block complete callback*/
  HAL_LPUART_TxHalfBlockCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA LPUART transmit process source complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void LPUART_DMASrcTranCplt(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx Source complete callback*/
  hlpuart->TxSrcCpltCallback(hlpuart);
#else
  /*Call legacy weak Tx Source complete callback*/
  HAL_LPUART_TxSrcCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA LPUART receive process complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void LPUART_DMAReceiveCplt(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

  /* DMA Normal mode */
  if (HAL_IS_BIT_CLR(hdma->Init.Mode, DMA_CIRCULAR))
  {
    hlpuart->RxXferCount = 0U;

    /* Disable PE and ERR (Frame error, noise error, overrun error) interrupts */
    CLEAR_BIT(hlpuart->Instance->CR1, LPUART_CR1_PEIE);
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_EIE);

    /* Disable the DMA transfer for the receiver request by resetting the DMAR bit
       in the LPUART CR3 register */
    CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_DMAR);

    /* At end of Rx process, restore hlpuart->RxState to Ready */
    hlpuart->RxState = HAL_LPUART_STATE_READY;
  }

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /*Call registered Rx complete callback*/
  hlpuart->RxCpltCallback(hlpuart);
#else
  /*Call legacy weak Rx complete callback*/
  HAL_LPUART_RxCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA LPUART receive process block complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void LPUART_DMARxBlockCplt(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /*Call registered Rx Block complete callback*/
  hlpuart->RxBlockCpltCallback(hlpuart);
#else
  /*Call legacy weak Rx Block complete callback*/
  HAL_LPUART_RxBlockCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA LPUART receive process half block complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void LPUART_DMARxHalfBlockCplt(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /*Call registered Rx Half Block complete callback*/
  hlpuart->RxHalfBlockCpltCallback(hlpuart);
#else
  /*Call legacy weak Rx Half Block complete callback*/
  HAL_LPUART_RxHalfBlockCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA LPUART receive process destination complete callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void LPUART_DMADstTranCplt(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /*Call registered Rx destination complete callback*/
  hlpuart->RxDstCpltCallback(hlpuart);
#else
  /*Call legacy weak Rx destination complete callback*/
  HAL_LPUART_RxDstCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA LPUART communication error callback.
  * @param hdma DMA handle.
  * @retval None
  */
static void LPUART_DMAError(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

  const HAL_LPUART_StateTypeDef gstate = hlpuart->gState;
  const HAL_LPUART_StateTypeDef rxstate = hlpuart->RxState;

  /* Stop LPUART DMA Tx request if ongoing */
  if ((HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAT)) &&
      (gstate == HAL_LPUART_STATE_BUSY_TX))
  {
    hlpuart->TxXferCount = 0U;
    LPUART_EndTxTransfer(hlpuart);
  }

  /* Stop LPUART DMA Rx request if ongoing */
  if ((HAL_IS_BIT_SET(hlpuart->Instance->CR3, LPUART_CR3_DMAR)) &&
      (rxstate == HAL_LPUART_STATE_BUSY_RX))
  {
    hlpuart->RxXferCount = 0U;
    LPUART_EndRxTransfer(hlpuart);
  }

  hlpuart->ErrorCode |= HAL_LPUART_ERROR_DMA;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /*Call registered error callback*/
  hlpuart->ErrorCallback(hlpuart);
#else
  /*Call legacy weak error callback*/
  HAL_LPUART_ErrorCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA LPUART communication abort callback, when initiated by HAL services on Error
  *         (To be called at end of DMA Abort procedure following error occurrence).
  * @param  hdma DMA handle.
  * @retval None
  */
static void LPUART_DMAAbortOnError(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);
  hlpuart->RxXferCount = 0U;
  hlpuart->TxXferCount = 0U;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /*Call registered error callback*/
  hlpuart->ErrorCallback(hlpuart);
#else
  /*Call legacy weak error callback*/
  HAL_LPUART_ErrorCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA LPUART Tx communication abort callback, when initiated by user
  *         (To be called at end of DMA Tx Abort procedure following user abort request).
  * @note   When this callback is executed, User Abort complete call back is called only if no
  *         Abort still ongoing for Rx DMA Handle.
  * @param  hdma DMA handle.
  * @retval None
  */
static void LPUART_DMATxAbortCallback(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

  hlpuart->hdmatx->XferAbortCallback = NULL;

  /* Check if an Abort process is still ongoing */
  if (hlpuart->hdmarx != NULL)
  {
    if (hlpuart->hdmarx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA channels are aborted, call user Abort Complete callback */
  hlpuart->TxXferCount = 0U;
  hlpuart->RxXferCount = 0U;

  /* Reset errorCode */
  hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;

  /* Clear the Error flags in the ICR register */
  __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_OREF | LPUART_CLEAR_NEF | LPUART_CLEAR_PEF | LPUART_CLEAR_FEF);

  /* Flush the whole TX FIFO (if needed) */
  if (hlpuart->FifoMode == LPUART_FIFOMODE_ENABLE)
  {
    __HAL_LPUART_SEND_REQ(hlpuart, LPUART_TXDATA_FLUSH_REQUEST);
  }

  /* Restore hlpuart->gState and hlpuart->RxState to Ready */
  hlpuart->gState  = HAL_LPUART_STATE_READY;
  hlpuart->RxState = HAL_LPUART_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort complete callback */
  hlpuart->AbortCpltCallback(hlpuart);
#else
  /* Call legacy weak Abort complete callback */
  HAL_LPUART_AbortCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}


/**
  * @brief  DMA LPUART Rx communication abort callback, when initiated by user
  *         (To be called at end of DMA Rx Abort procedure following user abort request).
  * @note   When this callback is executed, User Abort complete call back is called only if no
  *         Abort still ongoing for Tx DMA Handle.
  * @param  hdma DMA handle.
  * @retval None
  */
static void LPUART_DMARxAbortCallback(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

  hlpuart->hdmarx->XferAbortCallback = NULL;

  /* Check if an Abort process is still ongoing */
  if (hlpuart->hdmatx != NULL)
  {
    if (hlpuart->hdmatx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA channels are aborted, call user Abort Complete callback */
  hlpuart->TxXferCount = 0U;
  hlpuart->RxXferCount = 0U;

  /* Reset errorCode */
  hlpuart->ErrorCode = HAL_LPUART_ERROR_NONE;

  /* Clear the Error flags in the ICR register */
  __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_OREF | LPUART_CLEAR_NEF | LPUART_CLEAR_PEF | LPUART_CLEAR_FEF);

  /* Discard the received data */
  __HAL_LPUART_SEND_REQ(hlpuart, LPUART_RXDATA_FLUSH_REQUEST);

  /* Restore hlpuart->gState and hlpuart->RxState to Ready */
  hlpuart->gState  = HAL_LPUART_STATE_READY;
  hlpuart->RxState = HAL_LPUART_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort complete callback */
  hlpuart->AbortCpltCallback(hlpuart);
#else
  /* Call legacy weak Abort complete callback */
  HAL_LPUART_AbortCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}


/**
  * @brief  DMA LPUART Tx communication abort callback, when initiated by user by a call to
  *         HAL_LPUART_AbortTransmit_IT API (Abort only Tx transfer)
  *         (This callback is executed at end of DMA Tx Abort procedure following user abort request,
  *         and leads to user Tx Abort Complete callback execution).
  * @param  hdma DMA handle.
  * @retval None
  */
static void LPUART_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)(hdma->Parent);

  hlpuart->TxXferCount = 0U;

  /* Flush the whole TX FIFO (if needed) */
  if (hlpuart->FifoMode == LPUART_FIFOMODE_ENABLE)
  {
    __HAL_LPUART_SEND_REQ(hlpuart, LPUART_TXDATA_FLUSH_REQUEST);
  }

  /* Restore hlpuart->gState to Ready */
  hlpuart->gState = HAL_LPUART_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Transmit Complete Callback */
  hlpuart->AbortTransmitCpltCallback(hlpuart);
#else
  /* Call legacy weak Abort Transmit Complete Callback */
  HAL_LPUART_AbortTransmitCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA LPUART Rx communication abort callback, when initiated by user by a call to
  *         HAL_LPUART_AbortReceive_IT API (Abort only Rx transfer)
  *         (This callback is executed at end of DMA Rx Abort procedure following user abort request,
  *         and leads to user Rx Abort Complete callback execution).
  * @param  hdma DMA handle.
  * @retval None
  */
static void LPUART_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma)
{
  LPUART_HandleTypeDef *hlpuart = (LPUART_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  hlpuart->RxXferCount = 0U;

  /* Clear the Error flags in the ICR register */
  __HAL_LPUART_CLEAR_FLAG(hlpuart, LPUART_CLEAR_OREF | LPUART_CLEAR_NEF | LPUART_CLEAR_PEF | LPUART_CLEAR_FEF);

  /* Discard the received data */
  __HAL_LPUART_SEND_REQ(hlpuart, LPUART_RXDATA_FLUSH_REQUEST);

  /* Restore hlpuart->RxState to Ready */
  hlpuart->RxState = HAL_LPUART_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Receive Complete Callback */
  hlpuart->AbortReceiveCpltCallback(hlpuart);
#else
  /* Call legacy weak Abort Receive Complete Callback */
  HAL_LPUART_AbortReceiveCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief TX interrupt handler for 7 or 8 bits data word length .
  * @note   Function is called under interruption only, once
  *         interruptions have been enabled by HAL_LPUART_Transmit_IT().
  * @param hlpuart LPUART handle.
  * @retval None
  */
static void LPUART_TxISR_8BIT(LPUART_HandleTypeDef *hlpuart)
{
  /* Check that a Tx process is ongoing */
  if (hlpuart->gState == HAL_LPUART_STATE_BUSY_TX)
  {
    if (hlpuart->TxXferCount == 0U)
    {
      /* Disable the LPUART Transmit Data Register Empty Interrupt */
      CLEAR_BIT(hlpuart->Instance->CR1, LPUART_CR1_TXEIE);

      /* Enable the LPUART Transmit Complete Interrupt */
      SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_TCIE);
    }
    else
    {
      /* To prevent the TC flag bit from being affected by other operations 
         during data transmission, clear the TC flag bit in advance. 
         */
      __HAL_LPUART_CLEAR_IT(hlpuart, LPUART_CLEAR_TCF);
      hlpuart->Instance->TDR = (uint8_t)(*hlpuart->pTxBuffPtr & (uint8_t)0xFF);
      hlpuart->pTxBuffPtr++;
      hlpuart->TxXferCount--;
    }
  }
}

/**
  * @brief TX interrupt handler for 9 bits data word length.
  * @note   Function is called under interruption only, once
  *         interruptions have been enabled by HAL_LPUART_Transmit_IT().
  * @param hlpuart LPUART handle.
  * @retval None
  */
static void LPUART_TxISR_16BIT(LPUART_HandleTypeDef *hlpuart)
{
  uint16_t *tmp;

  /* Check that a Tx process is ongoing */
  if (hlpuart->gState == HAL_LPUART_STATE_BUSY_TX)
  {
    if (hlpuart->TxXferCount == 0U)
    {
      /* Disable the LPUART Transmit Data Register Empty Interrupt */
      CLEAR_BIT(hlpuart->Instance->CR1, LPUART_CR1_TXEIE);

      /* Enable the LPUART Transmit Complete Interrupt */
      SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_TCIE);
    }
    else
    {
      tmp = (uint16_t *) hlpuart->pTxBuffPtr;
      /* To prevent the TC flag bit from being affected by other operations 
         during data transmission, clear the TC flag bit in advance. 
         */
      __HAL_LPUART_CLEAR_IT(hlpuart, LPUART_CLEAR_TCF);
      hlpuart->Instance->TDR = (((uint32_t)(*tmp)) & 0x01FFUL);
      hlpuart->pTxBuffPtr += 2U;
      hlpuart->TxXferCount--;
    }
  }
}

/**
  * @brief TX interrupt handler for 7 or 8 bits data word length and FIFO mode is enabled.
  * @note   Function is called under interruption only, once
  *         interruptions have been enabled by HAL_LPUART_Transmit_IT().
  * @param hlpuart LPUART handle.
  * @retval None
  */
static void LPUART_TxISR_8BIT_FIFOEN(LPUART_HandleTypeDef *hlpuart)
{
  uint32_t  nb_tx_data;

  /* Check that a Tx process is ongoing */
  if (hlpuart->gState == HAL_LPUART_STATE_BUSY_TX)
  {
    for (nb_tx_data = hlpuart->NbTxDataToProcess ; nb_tx_data > 0U ; nb_tx_data--)
    {
      if (hlpuart->TxXferCount == 0U)
      {
        /* Disable the TX FIFO threshold interrupt */
        CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_TXFTIE);

        /* Enable the LPUART Transmit Complete Interrupt */
        SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_TCIE);

        break; /* force exit loop */
      }
      else if (READ_BIT(hlpuart->Instance->ISR, LPUART_ISR_TXE) != 0U)
      {
        /* To prevent the TC flag bit from being affected by other operations 
           during data transmission, clear the TC flag bit in advance. 
           */
        __HAL_LPUART_CLEAR_IT(hlpuart, LPUART_CLEAR_TCF);
        hlpuart->Instance->TDR = (uint8_t)(*hlpuart->pTxBuffPtr & (uint8_t)0xFF);
        hlpuart->pTxBuffPtr++;
        hlpuart->TxXferCount--;
      }
      else
      {
        /* Nothing to do */
      }
    }
  }
}

/**
  * @brief TX interrupt handler for 9 bits data word length and FIFO mode is enabled.
  * @note   Function is called under interruption only, once
  *         interruptions have been enabled by HAL_LPUART_Transmit_IT().
  * @param hlpuart LPUART handle.
  * @retval None
  */
static void LPUART_TxISR_16BIT_FIFOEN(LPUART_HandleTypeDef *hlpuart)
{
  uint16_t *tmp;
  uint32_t  nb_tx_data;

  /* Check that a Tx process is ongoing */
  if (hlpuart->gState == HAL_LPUART_STATE_BUSY_TX)
  {
    for (nb_tx_data = hlpuart->NbTxDataToProcess ; nb_tx_data > 0U ; nb_tx_data--)
    {
      if (hlpuart->TxXferCount == 0U)
      {
        /* Disable the TX FIFO threshold interrupt */
        CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_TXFTIE);

        /* Enable the LPUART Transmit Complete Interrupt */
        SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_TCIE);

        break; /* force exit loop */
      }
      else if (READ_BIT(hlpuart->Instance->ISR, LPUART_ISR_TXE) != 0U)
      {
        tmp = (uint16_t *) hlpuart->pTxBuffPtr;
        /* To prevent the TC flag bit from being affected by other operations 
           during data transmission, clear the TC flag bit in advance. 
           */
        __HAL_LPUART_CLEAR_IT(hlpuart, LPUART_CLEAR_TCF);
        hlpuart->Instance->TDR = (((uint32_t)(*tmp)) & 0x01FFUL);
        hlpuart->pTxBuffPtr += 2U;
        hlpuart->TxXferCount--;
      }
      else
      {
        /* Nothing to do */
      }
    }
  }
}

/**
  * @brief  Wrap up transmission in non-blocking mode.
  * @param  hlpuart pointer to a LPUART_HandleTypeDef structure that contains
  *                the configuration information for the specified LPUART module.
  * @retval None
  */
static void LPUART_EndTransmit_IT(LPUART_HandleTypeDef *hlpuart)
{
  /* Disable the LPUART Transmit Complete Interrupt */
  CLEAR_BIT(hlpuart->Instance->CR1, LPUART_CR1_TCIE);

  /* Tx process is ended, restore hlpuart->gState to Ready */
  hlpuart->gState = HAL_LPUART_STATE_READY;

  /* Cleat TxISR function pointer */
  hlpuart->TxISR = NULL;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx complete callback*/
  hlpuart->TxCpltCallback(hlpuart);
#else
  /*Call legacy weak Tx complete callback*/
  HAL_LPUART_TxCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
}

/**
  * @brief RX interrupt handler for 7 or 8 bits data word length .
  * @param hlpuart LPUART handle.
  * @retval None
  */
static void LPUART_RxISR_8BIT(LPUART_HandleTypeDef *hlpuart)
{
  uint16_t uhMask = hlpuart->Mask;
  uint16_t uhdata;

  /* Check that a Rx process is ongoing */
  if (hlpuart->RxState == HAL_LPUART_STATE_BUSY_RX)
  {
    uhdata = (uint16_t) READ_REG(hlpuart->Instance->RDR);
    *hlpuart->pRxBuffPtr = (uint8_t)(uhdata & (uint8_t)uhMask);
    hlpuart->pRxBuffPtr++;
    hlpuart->RxXferCount--;

    if (hlpuart->RxXferCount == 0U)
    {
      /* Disable the LPUART Parity Error Interrupt and RXNE interrupts */
      CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_RXNEIE | LPUART_CR1_PEIE));

      /* Disable the LPUART Error Interrupt: (Frame error, noise error, overrun error) */
      CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_EIE);

      /* Rx process is completed, restore hlpuart->RxState to Ready */
      hlpuart->RxState = HAL_LPUART_STATE_READY;

      /* Clear RxISR function pointer */
      hlpuart->RxISR = NULL;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
      /*Call registered Rx complete callback*/
      hlpuart->RxCpltCallback(hlpuart);
#else
      /*Call legacy weak Rx complete callback*/
      HAL_LPUART_RxCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
    }
  }
  else
  {
    /* Clear RXNE interrupt flag */
    __HAL_LPUART_SEND_REQ(hlpuart, LPUART_RXDATA_FLUSH_REQUEST);
  }
}

/**
  * @brief RX interrupt handler for 9 bits data word length .
  * @note   Function is called under interruption only, once
  *         interruptions have been enabled by HAL_LPUART_Receive_IT()
  * @param hlpuart LPUART handle.
  * @retval None
  */
static void LPUART_RxISR_16BIT(LPUART_HandleTypeDef *hlpuart)
{
  uint16_t *tmp;
  uint16_t uhMask = hlpuart->Mask;
  uint16_t  uhdata;

  /* Check that a Rx process is ongoing */
  if (hlpuart->RxState == HAL_LPUART_STATE_BUSY_RX)
  {
    uhdata = (uint16_t) READ_REG(hlpuart->Instance->RDR);
    tmp = (uint16_t *) hlpuart->pRxBuffPtr ;
    *tmp = (uint16_t)(uhdata & uhMask);
    hlpuart->pRxBuffPtr += 2U;
    hlpuart->RxXferCount--;

    if (hlpuart->RxXferCount == 0U)
    {
      /* Disable the LPUART Parity Error Interrupt and RXNE interrupt*/
      CLEAR_BIT(hlpuart->Instance->CR1, (LPUART_CR1_RXNEIE | LPUART_CR1_PEIE));

      /* Disable the LPUART Error Interrupt: (Frame error, noise error, overrun error) */
      CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_EIE);

      /* Rx process is completed, restore hlpuart->RxState to Ready */
      hlpuart->RxState = HAL_LPUART_STATE_READY;

      /* Clear RxISR function pointer */
      hlpuart->RxISR = NULL;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
      /*Call registered Rx complete callback*/
      hlpuart->RxCpltCallback(hlpuart);
#else
      /*Call legacy weak Rx complete callback*/
      HAL_LPUART_RxCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
    }
  }
  else
  {
    /* Clear RXNE interrupt flag */
    __HAL_LPUART_SEND_REQ(hlpuart, LPUART_RXDATA_FLUSH_REQUEST);
  }
}

/**
  * @brief RX interrupt handler for 7 or 8  bits data word length and FIFO mode is enabled.
  * @note   Function is called under interruption only, once
  *         interruptions have been enabled by HAL_LPUART_Receive_IT()
  * @param hlpuart LPUART handle.
  * @retval None
  */
static void LPUART_RxISR_8BIT_FIFOEN(LPUART_HandleTypeDef *hlpuart)
{
  uint16_t  uhMask = hlpuart->Mask;
  uint16_t  uhdata;
  uint32_t  nb_rx_data;
  uint32_t  rxdatacount;

  /* Check that a Rx process is ongoing */
  if (hlpuart->RxState == HAL_LPUART_STATE_BUSY_RX)
  {
    for (nb_rx_data = hlpuart->NbRxDataToProcess ; nb_rx_data > 0U ; nb_rx_data--)
    {
      uhdata = (uint16_t) READ_REG(hlpuart->Instance->RDR);
      *hlpuart->pRxBuffPtr = (uint8_t)(uhdata & (uint8_t)uhMask);
      hlpuart->pRxBuffPtr++;
      hlpuart->RxXferCount--;

      if (hlpuart->RxXferCount == 0U)
      {
        /* Disable the LPUART Parity Error Interrupt and RXFT interrupt*/
        CLEAR_BIT(hlpuart->Instance->CR1, LPUART_CR1_PEIE);

        /* Disable the LPUART Error Interrupt: (Frame error, noise error, overrun error)
           and RX FIFO Threshold interrupt */
        CLEAR_BIT(hlpuart->Instance->CR3, (LPUART_CR3_EIE | LPUART_CR3_RXFTIE));

        /* Rx process is completed, restore hlpuart->RxState to Ready */
        hlpuart->RxState = HAL_LPUART_STATE_READY;

        /* Clear RxISR function pointer */
        hlpuart->RxISR = NULL;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
        /*Call registered Rx complete callback*/
        hlpuart->RxCpltCallback(hlpuart);
#else
        /*Call legacy weak Rx complete callback*/
        HAL_LPUART_RxCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
      }
    }

    /* When remaining number of bytes to receive is less than the RX FIFO
    threshold, next incoming frames are processed as if FIFO mode was
    disabled (i.e. one interrupt per received frame).
    */
    rxdatacount = hlpuart->RxXferCount;
    if ((rxdatacount != 0U) && (rxdatacount < hlpuart->NbRxDataToProcess))
    {
      /* Disable the LPUART RXFT interrupt*/
      CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_RXFTIE);

      /* Update the RxISR function pointer */
      hlpuart->RxISR = LPUART_RxISR_8BIT;

      /* Enable the LPUART Data Register Not Empty interrupt */
      SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_RXNEIE);
    }
  }
  else
  {
    /* Clear RXNE interrupt flag */
    __HAL_LPUART_SEND_REQ(hlpuart, LPUART_RXDATA_FLUSH_REQUEST);
  }
}

/**
  * @brief RX interrupt handler for 9 bits data word length and FIFO mode is enabled.
  * @note   Function is called under interruption only, once
  *         interruptions have been enabled by HAL_LPUART_Receive_IT()
  * @param hlpuart LPUART handle.
  * @retval None
  */
static void LPUART_RxISR_16BIT_FIFOEN(LPUART_HandleTypeDef *hlpuart)
{
  uint16_t *tmp;
  uint16_t  uhMask = hlpuart->Mask;
  uint16_t  uhdata;
  uint32_t  nb_rx_data;
  uint32_t  rxdatacount;

  /* Check that a Rx process is ongoing */
  if (hlpuart->RxState == HAL_LPUART_STATE_BUSY_RX)
  {
    for (nb_rx_data = hlpuart->NbRxDataToProcess ; nb_rx_data > 0U ; nb_rx_data--)
    {
      uhdata = (uint16_t) READ_REG(hlpuart->Instance->RDR);
      tmp = (uint16_t *) hlpuart->pRxBuffPtr ;
      *tmp = (uint16_t)(uhdata & uhMask);
      hlpuart->pRxBuffPtr += 2U;
      hlpuart->RxXferCount--;

      if (hlpuart->RxXferCount == 0U)
      {
        /* Disable the LPUART Parity Error Interrupt and RXFT interrupt*/
        CLEAR_BIT(hlpuart->Instance->CR1, LPUART_CR1_PEIE);

        /* Disable the LPUART Error Interrupt: (Frame error, noise error, overrun error)
           and RX FIFO Threshold interrupt */
        CLEAR_BIT(hlpuart->Instance->CR3, (LPUART_CR3_EIE | LPUART_CR3_RXFTIE));

        /* Rx process is completed, restore hlpuart->RxState to Ready */
        hlpuart->RxState = HAL_LPUART_STATE_READY;

        /* Clear RxISR function pointer */
        hlpuart->RxISR = NULL;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
        /*Call registered Rx complete callback*/
        hlpuart->RxCpltCallback(hlpuart);
#else
        /*Call legacy weak Rx complete callback*/
        HAL_LPUART_RxCpltCallback(hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
      }
    }

    /* When remaining number of bytes to receive is less than the RX FIFO
    threshold, next incoming frames are processed as if FIFO mode was
    disabled (i.e. one interrupt per received frame).
    */
    rxdatacount = hlpuart->RxXferCount;
    if ((rxdatacount != 0U) && (rxdatacount < hlpuart->NbRxDataToProcess))
    {
      /* Disable the LPUART RXFT interrupt*/
      CLEAR_BIT(hlpuart->Instance->CR3, LPUART_CR3_RXFTIE);

      /* Update the RxISR function pointer */
      hlpuart->RxISR = LPUART_RxISR_16BIT;

      /* Enable the LPUART Data Register Not Empty interrupt */
      SET_BIT(hlpuart->Instance->CR1, LPUART_CR1_RXNEIE);
    }
  }
  else
  {
    /* Clear RXNE interrupt flag */
    __HAL_LPUART_SEND_REQ(hlpuart, LPUART_RXDATA_FLUSH_REQUEST);
  }
}

/**
  * @}
  */

#endif /* HAL_LPUART_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT PUYA *****END OF FILE****/
