/**
  ******************************************************************************
  * @file    py32e407_ll_uart.h
  * @author  MCU Application Team
  * @brief   Header file of UART LL module.
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
#ifndef __PY32E407_LL_UART_H
#define __PY32E407_LL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (UART1) || defined (UART2) || defined (UART3)

/** @defgroup UART_LL UART
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup UART_LL_ES_INIT UART Exported Init structures
  * @{
  */

/**
  * @brief LL UART Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< This field defines expected Uart communication baud rate.
                                           This feature can be modified afterwards using unitary function @ref LL_UART_SetBaudRate().*/

  uint32_t DataWidth;                 /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref UART_LL_EC_DATAWIDTH.
                                           This feature can be modified afterwards using unitary function @ref LL_UART_SetDataWidth().*/

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref UART_LL_EC_STOPBITS.
                                           This feature can be modified afterwards using unitary function @ref LL_UART_SetStopBitsLength().*/

  uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref UART_LL_EC_PARITY.
                                           This feature can be modified afterwards using unitary function @ref LL_UART_SetParity().*/

  uint32_t BitOrder;                  /*!< Specifies whether data transfers start from MSB or LSB bit.
                                           This parameter can be a value of @ref UART_LL_EC_BITORDER.
                                           This feature can be modified afterwards using unitary function @ref LL_UART_SetTransferBitOrder().*/
  
  uint32_t TxMode;                    /*!< Specifies the transmit mode. When the data length is 9 bits, it needs to be configured.
                                           This parameter can be a value of @ref UART_LL_EC_Tx_Mode
                                           This feature can be modified afterwards using unitary function @ref LL_UART_SetTxMode(). */
  
  uint32_t RxMode;                    /*!< Specifies the receive mode. When the data length is 9 bits, it needs to be configured.
                                           This parameter can be a value of @ref UART_LL_EC_Rx_Mode
                                           This feature can be modified afterwards using unitary function @ref LL_UART_SetRxMode(). */
  
  uint32_t RxMatchAddr;               /*!< Matching address in receive mode. When the data length is 9 bits and receive mode is
                                           LL_UART_RX_ADDR_MATCH_HARD, it needs to be configured.
                                           This feature can be modified afterwards using unitary function @ref LL_UART_SetRxMatchAddr().*/

} LL_UART_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup UART_LL_Exported_Constants UART Exported Constants
  * @{
  */

/** @defgroup UART_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_UART_ReadReg function
  * @{
  */
#define LL_UART_SR_RXNE                        UART_SR_RXNE                 /*!< Read data register not empty flag */
#define LL_UART_SR_ORE                         UART_SR_ORE                  /*!< Overrun error flag */
#define LL_UART_SR_PE                          UART_SR_PE                   /*!< Parity error flag */
#define LL_UART_SR_FE                          UART_SR_FE                   /*!< Framing error flag */
#define LL_UART_SR_BRI                         UART_SR_BRI                  /*!< Break interrupt flag */
#define LL_UART_SR_TDRE                        UART_SR_TDRE                 /*!< Transmit data register empty flag */
#define LL_UART_SR_TXE                         UART_SR_TXE                  /*!< Transmit data register empty flag and no data is being transmitted */
#define LL_UART_SR_ADDR_RCVD                   UART_SR_ADDR_RCVD            /*!< Address received flag */
#define LL_UART_SR_BUSY                        UART_SR_BUSY                 /*!< Busy flag */
#define LL_UART_SR_BUSYERR                     UART_SR_BUSY_ERR             /*!< Error flag: write CR1 when Busy flag is set */
/**
  * @}
  */

/** @defgroup UART_LL_EC_IT IT Defines
  * @brief    IT defines which can be used with LL_UART_ReadReg and  LL_UART_WriteReg functions
  * @{
  */
#define LL_UART_CR2_RXNEIE                     UART_CR2_RXNEIE              /*!< Read data register not empty interrupt enable */
#define LL_UART_CR2_TDREIE                     UART_CR2_TDREIE              /*!< Transmit data register empty interrupt enable */
#define LL_UART_CR2_LSIE                       UART_CR2_LSIE                /*!< Line status interrupt enable */
#define LL_UART_CR2_BUSYERRIE                  UART_CR2_BUSYERRIE           /*!< Busy error interrupt enable */
/**
  * @}
  */

/** @defgroup UART_LL_EC_DATAWIDTH Datawidth
  * @{
  */
#define LL_UART_DATAWIDTH_5B                  0x00000000U                                     /*!< 5 bits word length : Start bit, 5 data bits, n stop bits */
#define LL_UART_DATAWIDTH_6B                  ((uint32_t)UART_CR1_M_0)                        /*!< 6 bits word length : Start bit, 6 data bits, n stop bits */
#define LL_UART_DATAWIDTH_7B                  ((uint32_t)UART_CR1_M_1)                        /*!< 7 bits word length : Start bit, 7 data bits, n stop bits */
#define LL_UART_DATAWIDTH_8B                  ((uint32_t)(UART_CR1_M_1) | (UART_CR1_M_0))     /*!< 8 bits word length : Start bit, 8 data bits, n stop bits */
#define LL_UART_DATAWIDTH_9B                  0xFFFFFFFFU                                     /*!< 9 bits word length : Start bit, 9 data bits, n stop bits */
/**
  * @}
  */

/** @defgroup UART_LL_EC_STOPBITS Stop Bits
  * @{
  */
#define LL_UART_STOPBITS_1                     0x00000000U                   /*!< 1 stop bit */
#define LL_UART_STOPBITS_1_5_OR_2              ((uint32_t)UART_CR1_STOP)     /*!< 1.5 or 2 stop bits */
/**
  * @}
  */

/** @defgroup UART_LL_EC_PARITY Parity Control
  * @{
  */
#define LL_UART_PARITY_NONE                    0x00000000U                                             /*!< Parity control disabled */
#define LL_UART_PARITY_EVEN                    ((uint32_t)(UART_CR1_PCE | UART_CR1_PS))                /*!< Parity control enabled and Even Parity is selected */
#define LL_UART_PARITY_ODD                     ((uint32_t)UART_CR1_PCE)                                /*!< Parity control enabled and Odd Parity is selected */
#define LL_UART_PARITY_STICKY_0                ((uint32_t)(UART_CR1_PCE | UART_CR1_SP | UART_CR1_PS))  /*!< Parity control enabled and Parity bit is set to 0 */
#define LL_UART_PARITY_STICKY_1                ((uint32_t)(UART_CR1_PCE | UART_CR1_SP))                /*!< Parity control enabled and Parity bit is set to 1 */
/**
  * @}
  */

/** @defgroup UART_LL_EC_BITORDER Bit Order
  * @{
  */
#define LL_UART_BITORDER_LSBFIRST              0x00000000U                     /*!< data is transmitted/received with data bit 0 first, following the start bit */
#define LL_UART_BITORDER_MSBFIRST              UART_CR1_MSBFIRST               /*!< data is transmitted/received with the MSB first, following the start bit */
/**
  * @}
  */

/** @defgroup UART_LL_EC_Tx_Mode Txmode Control
  * @{
  */
#define LL_UART_TXMODE_0                  0x00000000U                          /*!< 9th bit is control by hardware when transmit */
#define LL_UART_TXMODE_1                  ((uint32_t)UART_CR3_TX_MODE)         /*!< 9th bit is control by software when transmit */
/**
  * @}
  */

/** @defgroup UART_LL_EC_Rx_Mode Rxmode Control
  * @{
  */
#define LL_UART_RX_ADDR_MATCH_SOFT        0x00000000U                          /*!< Addr match is performed by software */
#define LL_UART_RX_ADDR_MATCH_HARD        ((uint32_t)UART_CR3_ADDR_MATCH)      /*!< Addr match is performed by hardware */
/**
  * @}
  */


/** @defgroup UART_LL_EC_TXRX TX RX Pins Swap
  * @{
  */
#define LL_UART_TXRX_STANDARD             0x00000000U                          /*!< TX/RX pins are used as defined in standard pinout */
#define LL_UART_TXRX_SWAPPED              (UART_CR1_SWAP)                      /*!< TX and RX pins functions are swapped.             */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup UART_LL_Exported_Macros UART Exported Macros
  * @{
  */

/** @defgroup UART_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in UART register
  * @param  __INSTANCE__ UART Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_UART_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in UART register
  * @param  __INSTANCE__ UART Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_UART_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup UART_LL_EM_Exported_Macros_Helper Exported_Macros_Helper
  * @{
  */

/**
  * @brief  Compute UARTDIV value according to Peripheral Clock and
  *         expected Baud Rate (32 bits value of UARTDIV is returned)
  * @param  __PERIPHCLK__ Peripheral Clock frequency used for UART instance
  * @param  __BAUDRATE__ Baud rate value to achieve
  * @retval UARTDIV value to be used for BRR register
  */
/* UART BRR = mantissa + overflow */
#define __LL_UART_DIV(__PERIPHCLK__, __BAUDRATE__)            (((((__PERIPHCLK__)*10)/(16*(__BAUDRATE__))) + 5) / 10)                                                                          

/**
  * @}
  */

/** @defgroup UART_LL_EM_Exported_Macros_Helper Exported_Macros_Helper
  * @{
  */

/**
  * @brief  Compute UARTDIV value according to Peripheral Clock and
  *         expected Baud Rate in 8 bits sampling mode (32 bits value of UARTDIV is returned)
  * @param  __PERIPHCLK__ Peripheral Clock frequency used for UART instance
  * @param  __BAUDRATE__ Baud rate value to achieve
  * @retval UARTDIV value to be used for BRR register filling in OverSampling_8 case
  */
#define __LL_UART_DIV_SAMPLING8_100(__PERIPHCLK__, __BAUDRATE__)      (((__PERIPHCLK__)*25)/(2*(__BAUDRATE__)))
#define __LL_UART_DIVMANT_SAMPLING8(__PERIPHCLK__, __BAUDRATE__)      (__LL_UART_DIV_SAMPLING8_100((__PERIPHCLK__), (__BAUDRATE__))/100)
#define __LL_UART_DIVFRAQ_SAMPLING8(__PERIPHCLK__, __BAUDRATE__)      (((__LL_UART_DIV_SAMPLING8_100((__PERIPHCLK__), (__BAUDRATE__)) - (__LL_UART_DIVMANT_SAMPLING8((__PERIPHCLK__), (__BAUDRATE__)) * 100)) * 8 + 50) / 100)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + ((UART DIVFRAQ & 0xF8) << 1) + (UART DIVFRAQ & 0x07) */
#define __LL_UART_DIV_SAMPLING8(__PERIPHCLK__, __BAUDRATE__)             (((__LL_UART_DIVMANT_SAMPLING8((__PERIPHCLK__), (__BAUDRATE__)) << 4) + \
                                                                           ((__LL_UART_DIVFRAQ_SAMPLING8((__PERIPHCLK__), (__BAUDRATE__)) & 0xF8) << 1)) + \
                                                                           (__LL_UART_DIVFRAQ_SAMPLING8((__PERIPHCLK__), (__BAUDRATE__)) & 0x07))

/**
  * @brief  Compute UARTDIV value according to Peripheral Clock and
  *         expected Baud Rate in 16 bits sampling mode (32 bits value of UARTDIV is returned)
  * @param  __PERIPHCLK__ Peripheral Clock frequency used for UART instance
  * @param  __BAUDRATE__ Baud rate value to achieve
  * @retval UARTDIV value to be used for BRR register filling in OverSampling_16 case
  */
#define __LL_UART_DIV_SAMPLING16_100(__PERIPHCLK__, __BAUDRATE__)     (((__PERIPHCLK__)*25)/(4*(__BAUDRATE__)))
#define __LL_UART_DIVMANT_SAMPLING16(__PERIPHCLK__, __BAUDRATE__)     (__LL_UART_DIV_SAMPLING16_100((__PERIPHCLK__), (__BAUDRATE__))/100)
#define __LL_UART_DIVFRAQ_SAMPLING16(__PERIPHCLK__, __BAUDRATE__)     (((__LL_UART_DIV_SAMPLING16_100((__PERIPHCLK__), (__BAUDRATE__)) - (__LL_UART_DIVMANT_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) * 100)) * 16 + 50) / 100)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0F) */
#define __LL_UART_DIV_SAMPLING16(__PERIPHCLK__, __BAUDRATE__)            (((__LL_UART_DIVMANT_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) << 4) + \
                                                                           (__LL_UART_DIVFRAQ_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) & 0xF0)) + \
                                                                           (__LL_UART_DIVFRAQ_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) & 0x0F))

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup UART_LL_Exported_Functions UART Exported Functions
  * @{
  */

/** @defgroup UART_LL_EF_Configuration Configuration functions
  * @{
  */

/**
  * @brief  Configure TX/RX pins swapping setting.
  * @rmtoll CR1          SWAP          LL_UART_SetTXRXSwap
  * @param  UARTx UART Instance
  * @param  SwapConfig This parameter can be one of the following values:
  *         @arg @ref LL_UART_TXRX_STANDARD
  *         @arg @ref LL_UART_TXRX_SWAPPED
  * @retval None
  */
__STATIC_INLINE void LL_UART_SetTXRXSwap(UART_TypeDef *UARTx, uint32_t SwapConfig)
{
  MODIFY_REG(UARTx->CR1, UART_CR1_SWAP, SwapConfig);
}

/**
  * @brief  Retrieve TX/RX pins swapping configuration.
  * @rmtoll CR1          SWAP          LL_UART_GetTXRXSwap
  * @param  UARTx UART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_UART_TXRX_STANDARD
  *         @arg @ref LL_UART_TXRX_SWAPPED
  */
__STATIC_INLINE uint32_t LL_UART_GetTXRXSwap(const UART_TypeDef *UARTx)
{
  return (uint32_t)(READ_BIT(UARTx->CR1, UART_CR1_SWAP));
}

/**
  * @brief  Start send address (This field applies only if the data width is set to 9 bits and the TX_MODE is set to Txmode 0)
  * @rmtoll CR3          SEND_ADDR     LL_UART_SendAddr
  * @param  UARTx UART Instance
  * @param  Addr  The address to be sent
  * @retval None
  */
__STATIC_INLINE void LL_UART_SendAddr(UART_TypeDef *UARTx, uint8_t Addr)
{
  WRITE_REG(UARTx->TAR, Addr);
  SET_BIT(UARTx->CR3, UART_CR3_SEND_ADDR);
}

/**
  * @brief  Set Word length (i.e. nb of data bits, excluding start and stop bits)
  * @rmtoll CR1        M               LL_UART_SetDataWidth
  * @rmtoll CR3        M_E             LL_UART_SetDataWidth
  * @param  UARTx UART Instance
  * @param  DataWidth This parameter can be one of the following values:
  *         @arg @ref LL_UART_DATAWIDTH_5B
  *         @arg @ref LL_UART_DATAWIDTH_6B
  *         @arg @ref LL_UART_DATAWIDTH_7B
  *         @arg @ref LL_UART_DATAWIDTH_8B
  *         @arg @ref LL_UART_DATAWIDTH_9B
  * @retval None
  */
__STATIC_INLINE void LL_UART_SetDataWidth(UART_TypeDef *UARTx, uint32_t DataWidth)
{
  if (DataWidth == LL_UART_DATAWIDTH_9B)
  {
    SET_BIT(UARTx->CR3, UART_CR3_M_E);
  }
  else
  {
    CLEAR_BIT(UARTx->CR3, UART_CR3_M_E);
    MODIFY_REG(UARTx->CR1, UART_CR1_M, DataWidth);
  }
}

/**
  * @brief  Return Word length (i.e. nb of data bits, excluding start and stop bits)
  * @rmtoll CR1        M               LL_UART_GetDataWidth
  * @rmtoll CR3        M_E             LL_UART_GetDataWidth
  * @param  UARTx UART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_UART_DATAWIDTH_5B
  *         @arg @ref LL_UART_DATAWIDTH_6B
  *         @arg @ref LL_UART_DATAWIDTH_7B
  *         @arg @ref LL_UART_DATAWIDTH_8B
  *         @arg @ref LL_UART_DATAWIDTH_9B
  */
__STATIC_INLINE uint32_t LL_UART_GetDataWidth(UART_TypeDef *UARTx)
{
  if(((uint32_t)READ_BIT(UARTx->CR3, UART_CR3_M_E)) != 0)
  {
    return LL_UART_DATAWIDTH_9B;
  }
  else
  {
    return (uint32_t)(READ_BIT(UARTx->CR1, UART_CR1_M));
  } 
}

/**
  * @brief  Set the length of the stop bits
  * @rmtoll CR1          STOP          LL_UART_SetStopBitsLength
  * @param  UARTx UART Instance
  * @param  StopBits This parameter can be one of the following values:
  *         @arg @ref LL_UART_STOPBITS_1
  *         @arg @ref LL_UART_STOPBITS_1_5_OR_2
  * @retval None
  */
__STATIC_INLINE void LL_UART_SetStopBitsLength(UART_TypeDef *UARTx, uint32_t StopBits)
{
  MODIFY_REG(UARTx->CR1, UART_CR1_STOP, StopBits);
}

/**
  * @brief  Retrieve the length of the stop bits
  * @rmtoll CR1          STOP          LL_UART_GetStopBitsLength
  * @param  UARTx UART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_UART_STOPBITS_1
  *         @arg @ref LL_UART_STOPBITS_1_5_OR_2
  */
__STATIC_INLINE uint32_t LL_UART_GetStopBitsLength(UART_TypeDef *UARTx)
{
  return (uint32_t)(READ_BIT(UARTx->CR1, UART_CR1_STOP));
}

/**
  * @brief  Configure Parity (enabled/disabled and parity mode if enabled).
  * @note   This function selects if hardware parity control (generation and detection) is enabled or disabled.
  *         When the parity control is enabled (Odd or Even), computed parity bit is inserted after data position
  *         and parity is checked on the received data.
  * @rmtoll CR1          PS            LL_UART_SetParity
  *         CR1          PCE           LL_UART_SetParity
  *         CR1          SP            LL_UART_SetParity
  * @param  UARTx UART Instance
  * @param  Parity This parameter can be one of the following values:
  *         @arg @ref LL_UART_PARITY_NONE
  *         @arg @ref LL_UART_PARITY_EVEN
  *         @arg @ref LL_UART_PARITY_ODD
  *         @arg @ref LL_UART_PARITY_STICKY_0
  *         @arg @ref LL_UART_PARITY_STICKY_1
  * @retval None
  */
__STATIC_INLINE void LL_UART_SetParity(UART_TypeDef *UARTx, uint32_t Parity)
{
  MODIFY_REG(UARTx->CR1, UART_CR1_PS | UART_CR1_PCE | UART_CR1_SP, Parity);
}

/**
  * @brief  Return Parity configuration (enabled/disabled and parity mode if enabled)
  * @rmtoll CR1          PS            LL_UART_GetParity
  *         CR1          PCE           LL_UART_GetParity
  *         CR1          SP            LL_UART_GetParity
  * @param  UARTx UART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_UART_PARITY_NONE
  *         @arg @ref LL_UART_PARITY_EVEN
  *         @arg @ref LL_UART_PARITY_ODD
  *         @arg @ref LL_UART_PARITY_STICKY_0
  *         @arg @ref LL_UART_PARITY_STICKY_1
  */
__STATIC_INLINE uint32_t LL_UART_GetParity(UART_TypeDef *UARTx)
{
  return (uint32_t)(READ_BIT(UARTx->CR1, UART_CR1_PS | UART_CR1_PCE | UART_CR1_SP));
}

/**
  * @brief  Configure transfer bit order (either Less or Most Significant Bit First)
  * @note   MSB First means data is transmitted/received with the MSB first, following the start bit.
  *         LSB First means data is transmitted/received with data bit 0 first, following the start bit.
  * @rmtoll CR1          MSBFIRST      LL_UART_SetTransferBitOrder
  * @param  UARTx    UART Instance
  * @param  BitOrder This parameter can be one of the following values:
  *         @arg @ref LL_UART_BITORDER_LSBFIRST
  *         @arg @ref LL_UART_BITORDER_MSBFIRST
  * @retval None
  */
__STATIC_INLINE void LL_UART_SetTransferBitOrder(UART_TypeDef *UARTx, uint32_t BitOrder)
{
  MODIFY_REG(UARTx->CR1, UART_CR1_MSBFIRST, BitOrder);
}

/**
  * @brief  Return transfer bit order (either Less or Most Significant Bit First)
  * @note   MSB First means data is transmitted/received with the MSB first, following the start bit.
  *         LSB First means data is transmitted/received with data bit 0 first, following the start bit.
  * @rmtoll CR1          MSBFIRST      LL_UART_GetTransferBitOrder
  * @param  UARTx    UART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_UART_BITORDER_LSBFIRST
  *         @arg @ref LL_UART_BITORDER_MSBFIRST
  */
__STATIC_INLINE uint32_t LL_UART_GetTransferBitOrder(const UART_TypeDef *UARTx)
{
  return (uint32_t)(READ_BIT(UARTx->CR1, UART_CR1_MSBFIRST));
}

/**
  * @brief  Configure TxMode.
  * @note   This function selects TxMode.
  * @rmtoll CR3          TX_MODE       LL_UART_SetTxMode
  * @param  UARTx UART Instance
  * @param  TxMode This parameter can be one of the following values:
  *         @arg @ref LL_UART_TXMODE_0
  *         @arg @ref LL_UART_TXMODE_1
  * @retval None
  */
__STATIC_INLINE void LL_UART_SetTxMode(UART_TypeDef *UARTx, uint32_t TxMode)
{
  MODIFY_REG(UARTx->CR3, UART_CR3_TX_MODE, TxMode);
}

/**
  * @brief  Return TxMode configuration (enabled/disabled)
  * @rmtoll CR3          TX_MODE       LL_UART_GetTxMode
  * @param  UARTx UART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_UART_TXMODE_0
  *         @arg @ref LL_UART_TXMODE_1
  */
__STATIC_INLINE uint32_t LL_UART_GetTxMode(UART_TypeDef *UARTx)
{
  return (uint32_t)(READ_BIT(UARTx->CR3, UART_CR3_TX_MODE));
}

/**
  * @brief  Configure RxMode.
  * @note   This function selects RxMode.
  * @rmtoll CR3          ADDR_MATCH    LL_UART_SetRxMode
  * @param  UARTx UART Instance
  * @param  RxMode This parameter can be one of the following values:
  *         @arg @ref LL_UART_RX_ADDR_MATCH_SOFT
  *         @arg @ref LL_UART_RX_ADDR_MATCH_HARD
  * @retval None
  */
__STATIC_INLINE void LL_UART_SetRxMode(UART_TypeDef *UARTx, uint32_t RxMode)
{
  MODIFY_REG(UARTx->CR3, UART_CR3_ADDR_MATCH, RxMode);
}

/**
  * @brief  Return Rxmode configuration
  * @rmtoll CR3          ADDR_MATCH    LL_UART_GetRxMode
  * @param  UARTx UART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_UART_RX_ADDR_MATCH_SOFT
  *         @arg @ref LL_UART_RX_ADDR_MATCH_HARD
  */
__STATIC_INLINE uint32_t LL_UART_GetRxMode(UART_TypeDef *UARTx)
{
  return (uint32_t)(READ_BIT(UARTx->CR3, UART_CR3_ADDR_MATCH));
}

/**
  * @brief  Configure receive match address.
  * @note   This function configure receive match address..
  * @rmtoll RAR          RAR    LL_UART_SetRxMatchAddr
  * @param  UARTx UART Instance
  * @param  Addr  Receive match address
  * @retval None
  */
__STATIC_INLINE void LL_UART_SetRxMatchAddr(UART_TypeDef *UARTx, uint32_t Addr)
{
  MODIFY_REG(UARTx->RAR, UART_RAR_RAR, Addr & 0xFF);
}

/**
  * @brief  Return receive match address.
  * @rmtoll RAR          RAR    LL_UART_GetRxMatchAddr
  * @param  UARTx UART Instance
  */
__STATIC_INLINE uint32_t LL_UART_GetRxMatchAddr(UART_TypeDef *UARTx)
{
  return (uint32_t)(READ_BIT(UARTx->RAR, UART_RAR_RAR));
}

/**
  * @brief  Configure Character frame format (Datawidth, Parity control, Stop Bits)
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Data Width configuration using @ref LL_UART_SetDataWidth() function
  *         - Parity Control and mode configuration using @ref LL_UART_SetParity() function
  *         - Stop bits configuration using @ref LL_UART_SetStopBitsLength() function
  * @rmtoll CR1          PS            LL_UART_ConfigCharacter
  *         CR1          SP            LL_UART_ConfigCharacter
  *         CR1          PCE           LL_UART_ConfigCharacter
  *         CR1          M             LL_UART_ConfigCharacter
  *         CR1          STOP          LL_UART_ConfigCharacter
  *         CR3          M_E           LL_UART_ConfigCharacter
  * @param  UARTx UART Instance
  * @param  DataWidth This parameter can be one of the following values:
  *         @arg @ref LL_UART_DATAWIDTH_5B
  *         @arg @ref LL_UART_DATAWIDTH_6B
  *         @arg @ref LL_UART_DATAWIDTH_7B
  *         @arg @ref LL_UART_DATAWIDTH_8B
  *         @arg @ref LL_UART_DATAWIDTH_9B
  * @param  Parity This parameter can be one of the following values:
  *         @arg @ref LL_UART_PARITY_NONE
  *         @arg @ref LL_UART_PARITY_EVEN
  *         @arg @ref LL_UART_PARITY_ODD
  *         @arg @ref LL_UART_PARITY_STICKY_0
  *         @arg @ref LL_UART_PARITY_STICKY_1
  * @param  StopBits This parameter can be one of the following values:
  *         @arg @ref LL_UART_STOPBITS_1
  *         @arg @ref LL_UART_STOPBITS_1_5_OR_2
  * @retval None
  */
__STATIC_INLINE void LL_UART_ConfigCharacter(UART_TypeDef *UARTx, uint32_t DataWidth, uint32_t Parity,
                                              uint32_t StopBits)
{
  if (DataWidth == LL_UART_DATAWIDTH_9B)
  {
    SET_BIT(UARTx->CR3, UART_CR3_M_E);
    MODIFY_REG(UARTx->CR1, UART_CR1_PS | UART_CR1_PCE | UART_CR1_SP | UART_CR1_STOP, Parity | StopBits);
  }
  else
  {
    CLEAR_BIT(UARTx->CR3, UART_CR3_M_E);
    MODIFY_REG(UARTx->CR1, UART_CR1_PS | UART_CR1_PCE | UART_CR1_SP | UART_CR1_STOP | UART_CR1_M, Parity | StopBits | DataWidth);
  }
}

/**
  * @brief  Configure UART BRR register for achieving expected Baud Rate value.
  * @note   Compute and set UARTDIV value in BRR Register (full BRR content)
  *         according to used Peripheral Clock, and expected Baud Rate values
  * @note   Peripheral clock and Baud rate values provided as function parameters should be valid
  *         (Baud rate value != 0)
  * @rmtoll BRR          BRR           LL_UART_SetBaudRate
  * @param  UARTx UART Instance
  * @param  PeriphClk Peripheral Clock
  * @param  BaudRate Baud Rate
  * @retval None
  */
__STATIC_INLINE void LL_UART_SetBaudRate(UART_TypeDef *UARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
  UARTx->BRR  = (uint16_t)((__LL_UART_DIV_SAMPLING16(PeriphClk, BaudRate) >> 4) & 0xFFFF);
  UARTx->BRRF = (uint16_t)((__LL_UART_DIV_SAMPLING16(PeriphClk, BaudRate) & 0xF));
}

/**
  * @brief  Return current Baud Rate value, according to UARTDIV present in BRR register
  *         (full BRR content), and to used Peripheral Clock and Oversampling mode values
  * @note   In case of non-initialized or invalid value stored in BRR register, value 0 will be returned.
  * @rmtoll BRR          BRR           LL_UART_GetBaudRate
  * @param  UARTx UART Instance
  * @param  PeriphClk Peripheral Clock
  * @retval Baud Rate
  */
__STATIC_INLINE uint32_t LL_UART_GetBaudRate(UART_TypeDef *UARTx, uint32_t PeriphClk)
{
  register uint32_t uartdiv     = 0x0U;
  register uint32_t uartdivbrrf = 0x0U;
  register uint32_t brrresult   = 0x0U;

  uartdiv = UARTx->BRR;
  uartdivbrrf = UARTx->BRRF;

  if ((uartdiv & 0xFFFFU) != 0U)
  {
    brrresult = PeriphClk / (16*uartdiv + (uint8_t)uartdivbrrf);
  }
  return (brrresult);
}

/**
  * @}
  */

/** @defgroup UART_LL_EF_FLAG_Management FLAG Management
  * @{
  */

/**
  * @brief  Check if the UART Read Data Register Not Empty Flag is set or not
  * @rmtoll SR           RXNE          LL_UART_IsActiveFlag_RXNE
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_RXNE(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->SR, UART_SR_RXNE) == (UART_SR_RXNE));
}

/**
  * @brief  Check if the UART OverRun Error Flag is set or not
  * @rmtoll SR           ORE           LL_UART_IsActiveFlag_ORE
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_ORE(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->SR, UART_SR_ORE) == (UART_SR_ORE));
}

/**
  * @brief  Check if the UART Parity Error Flag is set or not
  * @rmtoll SR           PE            LL_UART_IsActiveFlag_PE
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_PE(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->SR, UART_SR_PE) == (UART_SR_PE));
}

/**
  * @brief  Check if the UART Framing Error Flag is set or not
  * @rmtoll SR           FE            LL_UART_IsActiveFlag_FE
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_FE(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->SR, UART_SR_FE) == (UART_SR_FE));
}

/**
  * @brief  Check if the UART break interrupt Flag is set or not
  * @rmtoll SR           BRI           LL_UART_IsActiveFlag_BRI
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_BRI(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->SR, UART_SR_BRI) == (UART_SR_BRI));
}

/**
  * @brief  Check if the UART transmit data register empty Flag is set or not
  * @rmtoll SR           TDRE          LL_UART_IsActiveFlag_TDRE
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_TDRE(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->SR, UART_SR_TDRE) == (UART_SR_TDRE));
}

/**
  * @brief  Check if the UART TXE Flag is set or not
  * @rmtoll SR           TXE           LL_UART_IsActiveFlag_TXE
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_TXE(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->SR, UART_SR_TXE) == (UART_SR_TXE));
}

/**
  * @brief  Check if the UART ADDR_RCVD Flag is set or not
  * @rmtoll SR           ADDR_RCVD     LL_UART_IsActiveFlag_ADDR_RCVD
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_ADDR_RCVD(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->SR, UART_SR_ADDR_RCVD) == (UART_SR_ADDR_RCVD));
}

/**
  * @brief  Check if the UART BUSY Flag is set or not
  * @rmtoll SR           BUSY          LL_UART_IsActiveFlag_BUSY
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_BUSY(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->SR, UART_SR_BUSY) == (UART_SR_BUSY));
}

/**
  * @brief  Check if the UART BUSYERR Flag is set or not
  * @rmtoll SR           BUSY_ERR      LL_UART_IsActiveFlag_BUSYERR
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_BUSYERR(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->SR, UART_SR_BUSY_ERR) == (UART_SR_BUSY_ERR));
}

/**
  * @brief  Clear OverRun Error Flag
  * @note   Clearing this flag is done by writing 1 to corresponding bit in
  * the UARTx_SR.
  * @rmtoll SR           ORE           LL_UART_ClearFlag_ORE
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_ClearFlag_ORE(UART_TypeDef *UARTx)
{
  WRITE_REG(UARTx->SR, UART_SR_ORE);
}

/**
  * @brief  Clear Parity Error Flag
  * @note   Clearing this flag is done by writing 1 to corresponding bit in
  * the UARTx_SR.
  * @rmtoll SR           PE            LL_UART_ClearFlag_PE
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_ClearFlag_PE(UART_TypeDef *UARTx)
{
  WRITE_REG(UARTx->SR, UART_SR_PE);
}

/**
  * @brief  Clear Framing Error Flag
  * @note   Clearing this flag is done by writing 1 to corresponding bit in
  * the UARTx_SR.
  * @rmtoll SR           FE            LL_UART_ClearFlag_FE
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_ClearFlag_FE(UART_TypeDef *UARTx)
{
  WRITE_REG(UARTx->SR, UART_SR_FE);
}

/**
  * @brief  Clear break interrupt Flag
  * @note   Clearing this flag is done by writing 1 to corresponding bit in
  * the UARTx_SR.
  * @rmtoll SR           BRI           LL_UART_ClearFlag_BRI
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_ClearFlag_BRI(UART_TypeDef *UARTx)
{
  WRITE_REG(UARTx->SR, UART_SR_BRI);
}

/**
  * @brief  Clear address received Flag
  * @note   Clearing this flag is done by writing 1 to corresponding bit in
  * the UARTx_SR.
  * @rmtoll SR           ADDR_RCVD     LL_UART_ClearFlag_ADDR_RCVD
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_ClearFlag_ADDR_RCVD(UART_TypeDef *UARTx)
{
   WRITE_REG(UARTx->SR, UART_SR_ADDR_RCVD);
}

/**
  * @brief  Clear BUSYERR Flag
  * @note   Clearing this flag is done by writing 1 to corresponding bit in
  * the UARTx_SR.
  * @rmtoll SR           BUSY_ERR      LL_UART_ClearFlag_BUSYERR
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_ClearFlag_BUSYERR(UART_TypeDef *UARTx)
{
   WRITE_REG(UARTx->SR, UART_SR_BUSY_ERR);
}

/**
  * @}
  */

/**
  * @brief  Enable RX Not Empty Interrupt
  * @rmtoll CR2          RXNEIE        LL_UART_EnableIT_RXNE
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_EnableIT_RXNE(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->CR2, UART_CR2_RXNEIE);
}

/**
  * @brief  Enable Transmission data register empty Interrupt
  * @rmtoll CR2          TDREIE        LL_UART_EnableIT_TDRE
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_EnableIT_TDRE(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->CR2, UART_CR2_TDREIE);
}

/**
  * @brief  Enable Line status Interrupt
  * @rmtoll CR2          LSIE          LL_UART_EnableIT_LS
  * @note   Line status Interrupt is a combination of PE, FE, OE, BI, and ADDR RCV interrupt flags 
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_EnableIT_LS(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->CR2, UART_CR2_LSIE);
}

/**
  * @brief  Enable busy Error Interrupt
  * @rmtoll CR2          BUSYERRIE     LL_UART_EnableIT_BUSYERR
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_EnableIT_BUSYERR(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->CR2, UART_CR2_BUSYERRIE);
}

/**
  * @brief  Disable RX Not Empty Interrupt
  * @rmtoll CR2          RXNEIE        LL_UART_DisableIT_RXNE
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_DisableIT_RXNE(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->CR2, UART_CR2_RXNEIE);
}

/**
  * @brief  Disable Transmission data register empty Interrupt
  * @rmtoll CR2          TDREIE        LL_UART_DisableIT_TDRE
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_DisableIT_TDRE(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->CR2, UART_CR2_TDREIE);
}

/**
  * @brief  Disable Line status Interrupt
  * @rmtoll CR2          LSIE          LL_UART_DisableIT_LS
  * @note   Line status Interrupt is a combination of PE, FE, OE, BI, and ADDR RCV interrupt flags 
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_DisableIT_LS(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->CR2, UART_CR2_LSIE);
}

/**
  * @brief  Disable busy Error Interrupt
  * @rmtoll CR2          BUSYERRIE     LL_UART_DisableIT_BUSYERR
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_DisableIT_BUSYERR(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->CR2, UART_CR2_BUSYERRIE);
}

/**
  * @brief  Check if the UART RX Not Empty Interrupt is enabled or disabled.
  * @rmtoll CR2          RXNEIE        LL_UART_IsEnabledIT_RXNE
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledIT_RXNE(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->CR2, UART_CR2_RXNEIE) == (UART_CR2_RXNEIE));
}

/**
  * @brief  Check if the UART Transmission data register empty
  * Interrupt is enabled or disabled.
  * @rmtoll CR2          TDREIE       LL_UART_IsEnabledIT_TDRE
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledIT_TDRE(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->CR2, UART_CR2_TDREIE) == (UART_CR2_TDREIE));
}

/**
  * @brief  Check if the UART Line status Interrupt is enabled or disabled.
  * @rmtoll CR2          LSIE         LL_UART_IsEnabledIT_LS
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledIT_LS(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->CR2, UART_CR2_LSIE) == (UART_CR2_LSIE));
}

/**
  * @brief  Check if the UART BUSY Error Interrupt is enabled or disabled.
  * @rmtoll CR2          BUSYERRIE    LL_UART_IsEnabledIT_BUSYERR
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledIT_BUSYERR(UART_TypeDef *UARTx)
{
  return (READ_BIT(UARTx->CR2, UART_CR2_BUSYERRIE) == (UART_CR2_BUSYERRIE));
}

/**
  * @brief  Enable DMA Mode for reception
  * @rmtoll CR3          DMAR          LL_UART_EnableDMAReq_RX
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_EnableDMAReq_RX(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->CR3, UART_CR3_DMAR);
}

/**
  * @brief  Disable DMA Mode for reception
  * @rmtoll CR3          DMAR          LL_UART_DisableDMAReq_RX
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_DisableDMAReq_RX(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->CR3, UART_CR3_DMAR);
}

/**
  * @brief  Check if DMA Mode is enabled for reception
  * @rmtoll CR3          DMAR          LL_UART_IsEnabledDMAReq_RX
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledDMAReq_RX(UART_TypeDef *UARTx)
{
  return ((READ_BIT(UARTx->CR3, UART_CR3_DMAR) == (UART_CR3_DMAR)) ? 1UL : 0UL);
}

/**
  * @brief  Enable DMA Mode for transmission
  * @rmtoll CR3          DMAT          LL_UART_EnableDMAReq_TX
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_EnableDMAReq_TX(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->CR3, UART_CR3_DMAT);
}

/**
  * @brief  Disable DMA Mode for transmission
  * @rmtoll CR3          DMAT          LL_UART_DisableDMAReq_TX
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_DisableDMAReq_TX(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->CR3, UART_CR3_DMAT);
}

/**
  * @brief  Check if DMA Mode is enabled for transmission
  * @rmtoll CR3          DMAT          LL_UART_IsEnabledDMAReq_TX
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledDMAReq_TX(UART_TypeDef *UARTx)
{
  return ((READ_BIT(UARTx->CR3, UART_CR3_DMAT) == (UART_CR3_DMAT)) ? 1UL : 0UL);
}

/**
  * @brief  Enable software clear DMA Tx/Rx request
  * @rmtoll CR3          SOFTACK          LL_UART_EnableDMASoftAck
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_EnableDMASoftAck(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->CR3, UART_CR3_DMA_SOFT_ACK);
}

/**
  * @brief  Disable software clear DMA Tx/Rx request
  * @rmtoll CR3          SOFTACK          LL_UART_DisableDMASoftAck
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_DisableDMASoftAck(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->CR3, UART_CR3_DMA_SOFT_ACK);
}

/**
  * @brief  Check if software clear DMA Tx/Rx request is enable
  * @rmtoll CR3          SOFTACK          LL_UART_IsEnabledDMASoftAck
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledDMASoftAck(UART_TypeDef *UARTx)
{
  return ((READ_BIT(UARTx->CR3, UART_CR3_DMA_SOFT_ACK) == (UART_CR3_DMA_SOFT_ACK)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup UART_LL_EF_Data_Management Data_Management
  * @{
  */

/**
  * @brief  Read Receiver Data register (Receive Data value, 5/6/7/8 bits)
  * @rmtoll DR           DR            LL_UART_ReceiveData
  * @param  UARTx UART Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint8_t LL_UART_ReceiveData(UART_TypeDef *UARTx)
{
  return (uint8_t)(READ_BIT(UARTx->DR, UART_DR_DR));
}

/**
  * @brief  Read Receiver Data register (Receive Data value, 9 bits)
  * @rmtoll DR           DR            LL_UART_ReceiveData9
  * @param  UARTx UART Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x1FF
  */
__STATIC_INLINE uint16_t LL_UART_ReceiveData9(UART_TypeDef *UARTx)
{
  return (uint16_t)(READ_BIT(UARTx->DR, UART_DR_DR));
}

/**
  * @brief  Write in Transmitter Data Register (Transmit Data value, 5/6/7/8 bits)
  * @rmtoll DR           DR            LL_UART_TransmitData
  * @param  UARTx UART Instance
  * @param  Value between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE void LL_UART_TransmitData(UART_TypeDef *UARTx, uint8_t Value)
{
  UARTx->DR = Value;
}

/**
  * @brief  Write in Transmitter Data Register (Transmit Data value, 9 bits)
  * @rmtoll DR           DR            LL_UART_TransmitData9
  * @param  UARTx UART Instance
  * @param  Value between Min_Data=0x00 and Max_Data=0x1FF
  * @retval None
  */
__STATIC_INLINE void LL_UART_TransmitData9(UART_TypeDef *UARTx, uint16_t Value)
{
  UARTx->DR = Value & 0x1FFU;
}

/**
  * @}
  */

/** @defgroup UART_LL_EF_Execution Execution
  * @{
  */

/**
  * @brief  Start send break frame
  * @rmtoll CR1          SBK           LL_UART_StartSendBreak
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_StartSendBreak(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->CR1, UART_CR1_SBK);
}

/**
  * @brief  Stop send break frame
  * @rmtoll CR1          SBK           LL_UART_StopSendBreak
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void LL_UART_StopSendBreak(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->CR1, UART_CR1_SBK);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup UART_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_UART_DeInit(UART_TypeDef *UARTx);
ErrorStatus LL_UART_Init(UART_TypeDef *UARTx, LL_UART_InitTypeDef *UART_InitStruct);
void        LL_UART_StructInit(LL_UART_InitTypeDef *UART_InitStruct);
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* UART1 || UART2 || UART3 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32E407_LL_UART_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
