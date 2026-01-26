/**
  ******************************************************************************
  * @file    py32e407_ll_uart.c
  * @author  MCU Application Team
  * @brief   UART LL module driver.
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

#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "py32e407_ll_uart.h"
#include "py32e407_ll_rcc.h"
#include "py32e407_ll_bus.h"
#ifdef  USE_FULL_ASSERT
#include "py32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (UART1) || defined (UART2) || defined (UART3)
/** @addtogroup UART_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup UART_LL_Private_Macros
  * @{
  */

/* __BAUDRATE__ The maximum Baud Rate is derived from the maximum clock available
 *              divided by the smallest oversampling used on the UART (i.e. 8)    */
#define IS_LL_UART_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) <= 3000000U)

/* __VALUE__ BRR content must be greater than or equal to 1d. */
#define IS_LL_UART_BRR_MIN(__VALUE__)     ((__VALUE__) >= 1U)

/* __VALUE__ BRR content must be lower than or equal to 0xFFFF. */
#define IS_LL_UART_BRR_MAX(__VALUE__)     ((__VALUE__) <= 0x0000FFFFU)

#define IS_LL_UART_DATAWIDTH(__VALUE__)   (((__VALUE__) == LL_UART_DATAWIDTH_5B)    || \
                                           ((__VALUE__) == LL_UART_DATAWIDTH_6B)    || \
                                           ((__VALUE__) == LL_UART_DATAWIDTH_7B)    || \
                                           ((__VALUE__) == LL_UART_DATAWIDTH_8B)    || \
                                           ((__VALUE__) == LL_UART_DATAWIDTH_9B))

#define IS_LL_UART_STOPBITS(__VALUE__)    (((__VALUE__) == LL_UART_STOPBITS_1)      || \
                                           ((__VALUE__) == LL_UART_STOPBITS_1_5_OR_2))

#define IS_LL_UART_PARITY(__VALUE__)      (((__VALUE__) == LL_UART_PARITY_NONE)     || \
                                           ((__VALUE__) == LL_UART_PARITY_EVEN)     || \
                                           ((__VALUE__) == LL_UART_PARITY_ODD)      || \
                                           ((__VALUE__) == LL_UART_PARITY_STICKY_0) || \
                                           ((__VALUE__) == LL_UART_PARITY_STICKY_1))

#define IS_LL_UART_BITORDER(__VALUE__)    (((__VALUE__) == LL_UART_BITORDER_LSBFIRST)  || \
                                           ((__VALUE__) == LL_UART_BITORDER_MSBFIRST))

#define IS_LL_UART_TXMODE(__VALUE__)      (((__VALUE__) == LL_UART_TXMODE_0)  || \
                                           ((__VALUE__) == LL_UART_TXMODE_1))

#define IS_LL_UART_RXMODE(__VALUE__)      (((__VALUE__) == LL_UART_RX_ADDR_MATCH_SOFT)  || \
                                           ((__VALUE__) == LL_UART_RX_ADDR_MATCH_HARD))

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup UART_LL_Exported_Functions
  * @{
  */

/** @addtogroup UART_LL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize UART registers (Registers restored to their default values).
  * @param  UARTx UART Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: UART registers are de-initialized
  *          - ERROR: UART registers are not de-initialized
  */
ErrorStatus LL_UART_DeInit(UART_TypeDef *UARTx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_UART_INSTANCE(UARTx));

  if (UARTx == UART1)
  {
    /* Force reset of UART clock */
    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_UART1);

    /* Release reset of UART clock */
    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_UART1);
  }
  else if (UARTx == UART2)
  {
    /* Force reset of UART clock */
    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_UART2);

    /* Release reset of UART clock */
    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_UART2);
  }
  else if (UARTx == UART3)
  {
    /* Force reset of UART clock */
    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_UART3);

    /* Release reset of UART clock */
    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_UART3);
  }
  else
  {
    status = ERROR;
  }

  return (status);
}

/**
  * @brief  Initialize UART registers according to the specified
  *         parameters in UART_InitStruct.
  * @note   Baud rate value stored in UART_InitStruct BaudRate field, should be valid (different from 0).
  * @param  UARTx UART Instance
  * @param  UART_InitStruct pointer to a LL_UART_InitTypeDef structure
  *         that contains the configuration information for the specified UART peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: UART registers are initialized according to UART_InitStruct content
  *          - ERROR: Problem occurred during UART Registers initialization
  */
ErrorStatus LL_UART_Init(UART_TypeDef *UARTx, LL_UART_InitTypeDef *UART_InitStruct)
{
  ErrorStatus status = ERROR;
  uint32_t periphclk = LL_RCC_PERIPH_FREQUENCY_NO;
  LL_RCC_ClocksTypeDef rcc_clocks;

  /* Check the parameters */
  assert_param(IS_UART_INSTANCE(UARTx));
  assert_param(IS_LL_UART_BAUDRATE(UART_InitStruct->BaudRate));
  assert_param(IS_LL_UART_DATAWIDTH(UART_InitStruct->DataWidth));
  assert_param(IS_LL_UART_STOPBITS(UART_InitStruct->StopBits));
  assert_param(IS_LL_UART_PARITY(UART_InitStruct->Parity));
  assert_param(IS_LL_UART_BITORDER(UART_InitStruct->BitOrder));
  assert_param(IS_LL_UART_TXMODE(UART_InitStruct->TxMode));
  assert_param(IS_LL_UART_RXMODE(UART_InitStruct->RxMode));

  /* UART must not be in busy state, in order to be able to configure some bits in
     CRx registers */
  if (LL_UART_IsActiveFlag_BUSY(UARTx) == 0U)
  {
    /*---------------------------- UART CR1, CR3 Configuration -----------------------
     * Configure UARTx CR1\3 with parameters:
     * - DataWidth:          UART_CR1_M, UART_CR3_M_E bits according to UART_InitStruct->DataWidth value
     * - Parity:             UART_CR1_PCE, UART_CR1_PS, UART_CR1_SP bits according to UART_InitStruct->Parity value
     * - StopBits:           UART_CR1_STOP bits according to UART_InitStruct->StopBits value
     * - BitOrder:           UART_CR1_MSBFIRST bit according to UART_InitStruct->BitOrder value.
     * - TxMode:             UART_CR3_TX_MODE bit according to UART_InitStruct->TxMode value.
     * - RxMode:             UART_CR3_ADDR_MATCH bit according to UART_InitStruct->RxMode value.
     */
    MODIFY_REG(UARTx->CR1, (UART_CR1_PS | UART_CR1_PCE | UART_CR1_SP | UART_CR1_STOP | UART_CR1_MSBFIRST), 
                           (UART_InitStruct->Parity   | 
                            UART_InitStruct->StopBits |
                            UART_InitStruct->BitOrder));

    if (UART_InitStruct->DataWidth == LL_UART_DATAWIDTH_9B)
    {
      SET_BIT(UARTx->CR3, UART_CR3_M_E);
      MODIFY_REG(UARTx->CR3, (UART_CR3_TX_MODE | UART_CR3_ADDR_MATCH), 
                             (UART_InitStruct->TxMode  | 
                              UART_InitStruct->RxMode));

    /*---------------------------- UART RAR Configuration -----------------------
     * Configure UARTx RAR with parameters:
     * - RxMatchAddr:        UART_RAR_RAR bits according to UART_InitStruct->RxMatchAddr value.
     */
      if(UART_InitStruct->RxMode == LL_UART_RX_ADDR_MATCH_HARD)
      {
        LL_UART_SetRxMatchAddr(UARTx, UART_InitStruct->RxMatchAddr);
      }
    }
    else
    {
      CLEAR_BIT(UARTx->CR3, UART_CR3_M_E);
      MODIFY_REG(UARTx->CR1, ( UART_CR1_M),(UART_InitStruct->DataWidth));
    }

    /*---------------------------- UART BRR Configuration -----------------------
     * Retrieve Clock frequency used for UART Peripheral
     */
    LL_RCC_GetSystemClocksFreq(&rcc_clocks);
    periphclk = rcc_clocks.PCLK1_Frequency;

    /* Configure the UART Baud Rate :
       - valid baud rate value (different from 0) is required
       - Peripheral clock as returned by RCC service, should be valid (different from 0).
    */
    if ((periphclk != LL_RCC_PERIPH_FREQUENCY_NO)
        && (UART_InitStruct->BaudRate != 0U))
    {
      status = SUCCESS;
      LL_UART_SetBaudRate(UARTx, periphclk, UART_InitStruct->BaudRate);

      /* Check BRR is greater than or equal to 16d */
      assert_param(IS_LL_UART_BRR_MIN(UARTx->BRR));

      /* Check BRR is greater than or equal to 16d */
      assert_param(IS_LL_UART_BRR_MAX(UARTx->BRR));
    }
  }
  /* Endif (=> UART in BUSY state => return ERROR) */

  return (status);
}

/**
  * @brief Set each @ref LL_UART_InitTypeDef field to default value.
  * @param UART_InitStruct Pointer to a @ref LL_UART_InitTypeDef structure
  *                         whose fields will be set to default values.
  * @retval None
  */

void LL_UART_StructInit(LL_UART_InitTypeDef *UART_InitStruct)
{
  /* Set UART_InitStruct fields to default values */
  UART_InitStruct->BaudRate            = 9600U;
  UART_InitStruct->DataWidth           = LL_UART_DATAWIDTH_8B;
  UART_InitStruct->StopBits            = LL_UART_STOPBITS_1;
  UART_InitStruct->Parity              = LL_UART_PARITY_NONE ;
  UART_InitStruct->BitOrder            = LL_UART_BITORDER_LSBFIRST;
  UART_InitStruct->TxMode              = LL_UART_TXMODE_0;
  UART_InitStruct->RxMode              = LL_UART_RX_ADDR_MATCH_SOFT;
  UART_InitStruct->RxMatchAddr         = 0;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* UART1 || UART2 */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
