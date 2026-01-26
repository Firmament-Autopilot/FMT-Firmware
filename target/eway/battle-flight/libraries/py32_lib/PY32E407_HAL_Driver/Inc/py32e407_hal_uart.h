/**
  ******************************************************************************
  * @file    py32e407_hal_uart.h
  * @author  MCU Application Team
  * @brief   Header file of UART HAL module.
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
#ifndef __PY32E407_HAL_UART_H
#define __PY32E407_HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup UART
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup UART_Exported_Types UART Exported Types
  * @{
  */

/**
  * @brief UART Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< This member configures the UART communication baud rate.
                                           The baud rate is computed using the following formula:
                                           - huart->Init.BaudRate = PCLKx / (16 * DIVISOR) */

  uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref UART_Word_Length */

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref UART_Stop_Bits */

  uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref UART_Parity */
  
  uint32_t MsbFirst;                    /*!< Specifies the MSB first.
                                           This parameter can be a value of @ref UART_Msb_First */
  
  uint32_t TxMode;                    /*!< Specifies the transmit mode.
                                           This parameter can be a value of @ref UART_Tx_Mode
                                           @note When the data length is 9 bits, it needs to be configured.  */
  
  uint32_t RxMode;                    /*!< Specifies the receive mode.
                                           This parameter can be a value of @ref UART_Rx_Mode
                                           @note When the data length is 9 bits, it needs to be configured.  */

  uint32_t RxMatchAddr;               /*!< Matching address in receive mode. 
                                           @note When the data length is 9 bits and receive mode is
                                                 UART_RX_ADDR_MATCH_HARD, it needs to be configured.*/
} UART_InitTypeDef;

/**
  * @brief HAL UART State structures definition
  * @note  HAL UART State value is a combination of 2 different substates: gState and RxState.
  *        - gState contains UART state information related to global Handle management
  *          and also information related to Tx operations.
  *          gState value coding follow below described bitmap :
  *          b7-b6  Error information
  *             00 : No Error
  *             01 : (Not Used)
  *             10 : Timeout
  *             11 : Error
  *          b5     Peripheral initialization status
  *             0  : Reset (Peripheral not initialized)
  *             1  : Init done (Peripheral not initialized. HAL UART Init function already called)
  *          b4-b3  (not used)
  *             xx : Should be set to 00
  *          b2     Intrinsic process state
  *             0  : Ready
  *             1  : Busy (Peripheral busy with some configuration or internal operations)
  *          b1     (not used)
  *             x  : Should be set to 0
  *          b0     Tx state
  *             0  : Ready (no Tx operation ongoing)
  *             1  : Busy (Tx operation ongoing)
  *        - RxState contains information related to Rx operations.
  *          RxState value coding follow below described bitmap :
  *          b7-b6  (not used)
  *             xx : Should be set to 00
  *          b5     Peripheral initialization status
  *             0  : Reset (Peripheral not initialized)
  *             1  : Init done (Peripheral not initialized)
  *          b4-b2  (not used)
  *            xxx : Should be set to 000
  *          b1     Rx state
  *             0  : Ready (no Rx operation ongoing)
  *             1  : Busy (Rx operation ongoing)
  *          b0     (not used)
  *             x  : Should be set to 0.
  */
typedef enum
{
  HAL_UART_STATE_RESET             = 0x00U,    /*!< Peripheral is not yet Initialized
                                                   Value is allowed for gState and RxState */
  HAL_UART_STATE_READY             = 0x20U,    /*!< Peripheral Initialized and ready for use
                                                   Value is allowed for gState and RxState */
  HAL_UART_STATE_BUSY              = 0x24U,    /*!< an internal process is ongoing
                                                   Value is allowed for gState only */
  HAL_UART_STATE_BUSY_TX           = 0x21U,    /*!< Data Transmission process is ongoing
                                                   Value is allowed for gState only */
  HAL_UART_STATE_BUSY_RX           = 0x22U,    /*!< Data Reception process is ongoing
                                                   Value is allowed for RxState only */
  HAL_UART_STATE_BUSY_TX_RX        = 0x23U,    /*!< Data Transmission and Reception process is ongoing
                                                   Not to be used for neither gState nor RxState.
                                                   Value is result of combination (Or) between gState and RxState values */
  HAL_UART_STATE_TIMEOUT           = 0xA0U,    /*!< Timeout state
                                                   Value is allowed for gState only */
  HAL_UART_STATE_ERROR             = 0xE0U     /*!< Error
                                                   Value is allowed for gState only */
} HAL_UART_StateTypeDef;

/**
  * @brief  UART handle Structure definition
  */
typedef struct __UART_HandleTypeDef
{
  UART_TypeDef                 *Instance;        /*!< UART registers base address        */

  UART_InitTypeDef              Init;             /*!< UART communication parameters      */

  uint8_t                       *pTxBuffPtr;      /*!< Pointer to UART Tx transfer Buffer */

  uint32_t                      TxXferSize;       /*!< UART Tx Transfer size              */

  __IO uint32_t                 TxXferCount;      /*!< UART Tx Transfer Counter           */

  uint8_t                       *pRxBuffPtr;      /*!< Pointer to UART Rx transfer Buffer */

  uint32_t                      RxXferSize;       /*!< UART Rx Transfer size              */

  __IO uint32_t                 RxXferCount;      /*!< UART Rx Transfer Counter           */

  DMA_HandleTypeDef             *hdmatx;          /*!< UART Tx DMA Handle parameters      */

  DMA_HandleTypeDef             *hdmarx;          /*!< UART Rx DMA Handle parameters      */

  HAL_LockTypeDef               Lock;             /*!< Locking object                     */

  __IO HAL_UART_StateTypeDef    gState;           /*!< UART state information related to global Handle management
                                                       and also related to Tx operations.
                                                       This parameter can be a value of @ref HAL_UART_StateTypeDef */

  __IO HAL_UART_StateTypeDef    RxState;          /*!< UART state information related to Rx operations.
                                                       This parameter can be a value of @ref HAL_UART_StateTypeDef */

  __IO uint32_t                 ErrorCode;        /*!< UART Error code                    */

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  void (* TxCpltCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART Tx Complete Callback             */
  void (* RxCpltCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART Rx Complete Callback             */
  void (* TxBlockCpltCallback)(struct __UART_HandleTypeDef *huart);       /*!< UART Tx Block Complete Callback       */
  void (* TxHalfBlockCpltCallback)(struct __UART_HandleTypeDef *huart);   /*!< UART Tx Half Block Complete Callback  */
  void (* TxSrcCpltCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Tx Source Complete Callback      */
  void (* RxBlockCpltCallback)(struct __UART_HandleTypeDef *huart);       /*!< UART Rx Block Complete Callback       */
  void (* RxHalfBlockCpltCallback)(struct __UART_HandleTypeDef *huart);   /*!< UART Rx Half Block Complete Callback  */
  void (* RxDstCpltCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Rx Destination Complete Callback */
  void (* ErrorCallback)(struct __UART_HandleTypeDef *huart);             /*!< UART Error Callback                   */
  void (* AbortCpltCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Abort Complete Callback          */
  void (* AbortTransmitCpltCallback)(struct __UART_HandleTypeDef *huart); /*!< UART Abort Transmit Complete Callback */
  void (* AbortReceiveCpltCallback)(struct __UART_HandleTypeDef *huart);  /*!< UART Abort Receive Complete Callback  */
  void (* BreakFrameCallback)(struct __UART_HandleTypeDef *huart);        /*!< UART Break Frame Detection Callback   */
  void (* AddrMatchCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Address Match Callback           */

  void (* MspInitCallback)(struct __UART_HandleTypeDef *huart);           /*!< UART Msp Init callback                */
  void (* MspDeInitCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Msp DeInit callback              */
#endif  /* USE_HAL_UART_REGISTER_CALLBACKS */

} UART_HandleTypeDef;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL UART Callback ID enumeration definition
  */
typedef enum
{
  HAL_UART_TX_COMPLETE_CB_ID             = 0x00U,    /*!< UART Tx Complete Callback ID             */
  HAL_UART_RX_COMPLETE_CB_ID             = 0x01U,    /*!< UART Rx Complete Callback ID             */
  HAL_UART_TX_BLOCK_COMPLETE_CB_ID       = 0x02U,    /*!< UART Tx Block Complete Callback ID       */
  HAL_UART_TX_HALF_BLOCK_COMPLETE_CB_ID  = 0x03U,    /*!< UART Tx Half Block Complete Callback ID  */
  HAL_UART_TX_SRC_COMPLETE_CB_ID         = 0x04U,    /*!< UART Tx Source Complete Callback ID      */
  HAL_UART_RX_BLOCK_COMPLETE_CB_ID       = 0x05U,    /*!< UART Rx Block Complete Callback ID       */
  HAL_UART_RX_HALF_BLOCK_COMPLETE_CB_ID  = 0x06U,    /*!< UART Rx Half Block Complete Callback ID  */
  HAL_UART_RX_DST_COMPLETE_CB_ID         = 0x07U,    /*!< UART Rx Destination Complete Callback ID */
  HAL_UART_ERROR_CB_ID                   = 0x08U,    /*!< UART Error Callback ID                   */
  HAL_UART_ABORT_COMPLETE_CB_ID          = 0x09U,    /*!< UART Abort Complete Callback ID          */
  HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x0AU,    /*!< UART Abort Transmit Complete Callback ID */
  HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x0BU,    /*!< UART Abort Receive Complete Callback ID  */
  HAL_UART_BREAK_FRAME_CB_ID             = 0x0CU,    /*!< UART Break Frame Detection Callback ID   */
  HAL_UART_ADDR_MATCH_CB_ID              = 0x0DU,    /*!< UART Address Match Callback ID           */

  HAL_UART_MSPINIT_CB_ID                 = 0x0EU,    /*!< UART MspInit callback ID                 */
  HAL_UART_MSPDEINIT_CB_ID               = 0x0FU     /*!< UART MspDeInit callback ID               */

} HAL_UART_CallbackIDTypeDef;

/**
  * @brief  HAL UART Callback pointer definition
  */
typedef  void (*pUART_CallbackTypeDef)(UART_HandleTypeDef *huart);  /*!< pointer to an UART callback function */

#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup UART_Exported_Constants UART Exported Constants
  * @{
  */

/** @defgroup UART_Error_Code UART Error Code
  * @{
  */
#define HAL_UART_ERROR_NONE              0x00000000U   /*!< No error            */
#define HAL_UART_ERROR_ORE               0x00000001U   /*!< Overrun error       */
#define HAL_UART_ERROR_PE                0x00000002U   /*!< Parity error        */
#define HAL_UART_ERROR_FE                0x00000004U   /*!< Frame error         */
#define HAL_UART_ERROR_BUSY              0x00000008U   /*!< BUSY error          */
#define HAL_UART_ERROR_DMA               0x00000010U   /*!< DMA transfer error  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
#define  HAL_UART_ERROR_INVALID_CALLBACK 0x00000020U   /*!< Invalid Callback error  */
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup UART_Word_Length UART Word Length
  * @{
  */
#define UART_WORDLENGTH_5B                  0x00000000U
#define UART_WORDLENGTH_6B                  ((uint32_t)UART_CR1_M_0)
#define UART_WORDLENGTH_7B                  ((uint32_t)UART_CR1_M_1)
#define UART_WORDLENGTH_8B                  ((uint32_t)(UART_CR1_M_1) | (UART_CR1_M_0))
#define UART_WORDLENGTH_9B                  0xFFFFFFFFU
/**
  * @}
  */
  
/** @defgroup UART_Stop_Bits UART Number of Stop Bits
  * @{
  */
#define UART_STOPBITS_1                     0x00000000U
#define UART_STOPBITS_1_5_OR_2              ((uint32_t)UART_CR1_STOP)
/**
  * @}
  */

/** @defgroup UART_Parity UART Parity
  * @{
  */
#define UART_PARITY_NONE         0x00000000U
#define UART_PARITY_EVEN         ((uint32_t)(UART_CR1_PCE | UART_CR1_PS))
#define UART_PARITY_ODD          ((uint32_t)UART_CR1_PCE)
#define UART_PARITY_STICKY_0     ((uint32_t)(UART_CR1_PCE | UART_CR1_SP | UART_CR1_PS))
#define UART_PARITY_STICKY_1     ((uint32_t)(UART_CR1_PCE | UART_CR1_SP))
/**
  * @}
  */

/** @defgroup UART_Msb_First UART MSB First
  * @{
  */
#define UART_MSB_FIRST_DISABLE         0x00000000U
#define UART_MSB_FIRST_ENABLE          ((uint32_t)UART_CR1_MSBFIRST)
/**
  * @}
  */
  
/** @defgroup UART_Tx_Mode UART transmit mode
  * @{
  */
#define UART_TX_MODE_0         0x00000000U
#define UART_TX_MODE_1         ((uint32_t)UART_CR3_TX_MODE)
/**
  * @}
  */

/** @defgroup UART_Rx_Mode UART receive mode
  * @{
  */
#define UART_RX_ADDR_MATCH_SOFT         0x00000000U
#define UART_RX_ADDR_MATCH_HARD         ((uint32_t)UART_CR3_ADDR_MATCH)
/**
  * @}
  */

/** @defgroup UART_Flags   UART FLags
  *        Elements values convention: 0xXXXX
  *           - 0xXXXX  : Flag mask in the SR register
  * @{
  */
#define UART_FLAG_BUSY_ERR                  ((uint32_t)UART_SR_BUSY_ERR)
#define UART_FLAG_BUSY                      ((uint32_t)UART_SR_BUSY)
#define UART_FLAG_ADDR_RCVD                 ((uint32_t)UART_SR_ADDR_RCVD)
#define UART_FLAG_TXE                       ((uint32_t)UART_SR_TXE)
#define UART_FLAG_TDRE                      ((uint32_t)UART_SR_TDRE)
#define UART_FLAG_BRI                       ((uint32_t)UART_SR_BRI)
#define UART_FLAG_FE                        ((uint32_t)UART_SR_FE)
#define UART_FLAG_PE                        ((uint32_t)UART_SR_PE)
#define UART_FLAG_ORE                       ((uint32_t)UART_SR_ORE)
#define UART_FLAG_RXNE                      ((uint32_t)UART_SR_RXNE)
/**
  * @}
  */

/** @defgroup UART_Interrupt_definition  UART Interrupt Definitions
  *        Elements values convention: 0xXXXX
  *           - XXXX  : Interrupt mask in the CR2 register
  * @{
  */
#define UART_IT_BUSY_ERR                     ((uint32_t)UART_CR2_BUSYERRIE)
#define UART_IT_LS                           ((uint32_t)UART_CR2_LSIE)
#define UART_IT_TDRE                         ((uint32_t)UART_CR2_TDREIE)
#define UART_IT_RXNE                         ((uint32_t)UART_CR2_RXNEIE)
/**
  * @}
  */
  
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup UART_Exported_Macros UART Exported Macros
  * @{
  */

/** @brief Reset UART handle gstate & RxState
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the UARTx peripheral
  *         (UART availability and x values depending on device).
  * @retval None
  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \
                                                       (__HANDLE__)->MspInitCallback = NULL;             \
                                                       (__HANDLE__)->MspDeInitCallback = NULL;           \
                                                     } while(0U)
#else
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \
                                                     } while(0U)
#endif /*USE_HAL_UART_REGISTER_CALLBACKS */

/** @brief  Flushes the UART DR register
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the UARTx peripheral
  *         (UART availability and x values depending on device).
  */
#define __HAL_UART_FLUSH_DRREGISTER(__HANDLE__) ((__HANDLE__)->Instance->DR)

/** @brief  Checks whether the specified UART flag is set or not.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the UARTx peripheral
  *         (UART availability and x values depending on device).
  * @param  __FLAG__ specifies the flag to check.
  *        This parameter can be one of the following values:
  *            @arg UART_FLAG_BUSY_ERR : When UART is busy (SR [9] is set to 1), the master attempts to write to the CR1 register
  *            @arg UART_FLAG_BUSY     : UART busy flag
  *            @arg UART_FLAG_ADDR_RCVD: Address receiving flag
  *            @arg UART_FLAG_TXE      : Send empty flag
  *            @arg UART_FLAG_TDRE     : Send Hold Register Empty flag
  *            @arg UART_FLAG_BRI      : Break interrupt flag
  *            @arg UART_FLAG_FE       : Framing Error flag
  *            @arg UART_FLAG_PE       : Parity Error flag
  *            @arg UART_FLAG_ORE      : Overrun Error flag
  *            @arg UART_FLAG_RXNE     : Receive data register not empty flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_UART_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))

/** @brief  Clears the specified UART pending flag.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the UARTx peripheral
  *         (UART availability and x values depending on device).
  * @param  __FLAG__ specifies the flag to check.
  *          This parameter can be any combination of the following values:
  *            @arg UART_FLAG_BUSY_ERR : When UART is busy (SR [9] is set to 1), the master attempts to write to the CR1 register
  *            @arg UART_FLAG_ADDR_RCVD: Address receiving flag
  *            @arg UART_FLAG_BRI      : Break interrupt flag
  *            @arg UART_FLAG_FE       : Framing Error flag
  *            @arg UART_FLAG_PE       : Parity Error flag
  *            @arg UART_FLAG_ORE      : Overrun Error flag
  * @retval None
  */
#define __HAL_UART_CLEAR_FLAG(__HANDLE__, __FLAG__)       WRITE_REG((__HANDLE__)->Instance->SR, (__FLAG__))

/** @brief  Enable the specified UART interrupt.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the UARTx peripheral
  *         (UART availability and x values depending on device).
  * @param  __INTERRUPT__ specifies the UART interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg UART_IT_BUSY_ERR: BUSYERR status interrupt
  *            @arg UART_IT_LS      : Receiver line status interrupt
  *            @arg UART_IT_TDRE    : Transfer Hold Register empty interrupt
  *            @arg UART_IT_RXNE    : Receive data available interrupt
  * @retval None
  */
#define __HAL_UART_ENABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->CR2 |= (__INTERRUPT__))

/** @brief  Disable the specified UART interrupt.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the UARTx peripheral
  *         (UART availability and x values depending on device).
  * @param  __INTERRUPT__ specifies the UART interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg UART_IT_BUSY_ERR: BUSYERR status interrupt
  *            @arg UART_IT_LS      : Receiver line status interrupt
  *            @arg UART_IT_TDRE    : Transfer Hold Register empty interrupt
  *            @arg UART_IT_RXNE    : Receive data available interrupt
  * @retval None
  */
#define __HAL_UART_DISABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->CR2 &= ~(__INTERRUPT__))

/** @brief  Checks whether the specified UART interrupt has occurred or not.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the UARTx peripheral
  *         (UART availability and x values depending on device).
  * @param  __IT__ specifies the UART interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg UART_IT_BUSY_ERR: BUSYERR status interrupt
  *            @arg UART_IT_LS      : Receiver line status interrupt
  *            @arg UART_IT_TDRE    : Transfer Hold Register empty interrupt
  *            @arg UART_IT_RXNE    : Receive data available interrupt
  * @retval The new state of __IT__ (TRUE or FALSE).
  */
#define __HAL_UART_GET_IT_SOURCE(__HANDLE__, __IT__) (((__HANDLE__)->Instance->CR2 & (__IT__)) == (__IT__))

/** @brief  Enable the TX/RX pin exchange.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the UARTx peripheral
  *         (UART availability and x values depending on device).
  * @retval None
  */
#define __HAL_UART_ENABLE_SWAP(__HANDLE__)   SET_BIT((__HANDLE__)->Instance->CR1 , UART_CR1_SWAP)

/** @brief  Disable the TX/RX pin exchange.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the UARTx peripheral
  *         (UART availability and x values depending on device).
  * @retval None
  */
#define __HAL_UART_DISABLE_SWAP(__HANDLE__)   CLEAR_BIT((__HANDLE__)->Instance->CR1 , UART_CR1_SWAP)

/** @brief  Enable the software clears dma send requests and dma receive requests.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the UARTx peripheral
  *         (UART availability and x values depending on device).
  * @retval None
  */
#define __HAL_UART_ENABLE_DMA_SOFT_ACK(__HANDLE__)   SET_BIT((__HANDLE__)->Instance->CR3 , UART_CR3_DMA_SOFT_ACK)

/** @brief  Disable the software clears dma send requests and dma receive requests.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the UARTx peripheral
  *         (UART availability and x values depending on device).
  * @retval None
  */
#define __HAL_UART_DISABLE_DMA_SOFT_ACK(__HANDLE__)   CLEAR_BIT((__HANDLE__)->Instance->CR3 , UART_CR3_DMA_SOFT_ACK)

#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        (((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
             = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup UART_Exported_Functions
  * @{
  */
/** @addtogroup UART_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */

/* Initialization/de-initialization functions  **********************************/
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);

/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_UART_RegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID, pUART_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_UART_UnRegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group2 IO operation functions
  * @{
  */

/* IO operation functions *******************************************************/
HAL_StatusTypeDef HAL_UART_TransmitAddr(UART_HandleTypeDef *huart, uint8_t *addr, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);
/* Transfer Abort functions */
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_TxBlockCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_TxHalfBlockCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_TxSrcCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxBlockCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxHalfBlockCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxDstCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_BreakFrameCallback(UART_HandleTypeDef *huart);
void HAL_UART_AddrMatchCallback(UART_HandleTypeDef *huart);

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group3
  * @{
  */
/* Peripheral Control functions  ************************************************/
HAL_StatusTypeDef HAL_UART_StartSendBreak(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_StopSendBreak(UART_HandleTypeDef *huart);
/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group4
  * @{
  */
/* Peripheral State functions  **************************************************/
HAL_UART_StateTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart);
uint32_t              HAL_UART_GetError(UART_HandleTypeDef *huart);
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup UART_Private_Macros UART Private Macros
  * @{
  */

#define IS_UART_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_5B) || \
                                     ((LENGTH) == UART_WORDLENGTH_6B) || \
                                     ((LENGTH) == UART_WORDLENGTH_7B) || \
                                     ((LENGTH) == UART_WORDLENGTH_8B) || \
                                     ((LENGTH) == UART_WORDLENGTH_9B))

#define IS_UART_STOPBITS(STOPBITS) (((STOPBITS) == UART_STOPBITS_1) || \
                                    ((STOPBITS) == UART_STOPBITS_1_5_OR_2))

#define IS_UART_PARITY(PARITY) (((PARITY) == UART_PARITY_NONE) || \
                                ((PARITY) == UART_PARITY_EVEN) || \
                                ((PARITY) == UART_PARITY_ODD)  || \
                                ((PARITY) == UART_PARITY_STICKY_0)  || \
                                ((PARITY) == UART_PARITY_STICKY_1))

#define IS_UART_MSB_FIRST(MSB) (((MSB) == UART_MSB_FIRST_DISABLE) || \
                                ((MSB) == UART_MSB_FIRST_ENABLE))

#define IS_UART_TX_MODE(MODE) (((MODE) == UART_TX_MODE_0) || \
                               ((MODE) == UART_TX_MODE_1))

#define IS_UART_RX_MODE(MODE) (((MODE) == UART_RX_ADDR_MATCH_SOFT) || \
                               ((MODE) == UART_RX_ADDR_MATCH_HARD))

#define IS_UART_RX_MATCH_ADDR(ADDR) ((ADDR) <= 0xFF)

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32E407_HAL_UART_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
