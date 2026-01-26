/**
  ******************************************************************************
  * @file    py32e407_hal_irda.h
  * @author  MCU Application Team
  * @brief   Header file of IRDA HAL module.
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
#ifndef __PY32E407_HAL_IRDA_H
#define __PY32E407_HAL_IRDA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup IRDA
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup IRDA_Exported_Types IRDA Exported Types
  * @{
  */
/**
  * @brief IRDA Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< This member configures the IRDA communication baud rate.
                                           The baud rate is computed using the following formula:
                                           - IntegerDivider = ((PCLKx) / (16 * (hirda->Init.BaudRate)))
                                           - FractionalDivider = ((IntegerDivider - ((uint32_t) IntegerDivider)) * 16) + 0.5 */

  uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref IRDA_Word_Length */

  uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref IRDA_Parity
                                           @note When parity is enabled, the computed parity is inserted
                                                 at the MSB position of the transmitted data (9th bit when
                                                 the word length is set to 9 data bits; 8th bit when the
                                                 word length is set to 8 data bits). */

  uint32_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref IRDA_Mode */

  uint8_t  Prescaler;                 /*!< Specifies the Prescaler value to be programmed
                                           in the IrDA low-power Baud Register, for defining pulse width on which
                                           burst acceptance/rejection will be decided. This value is used as divisor
                                           of system clock to achieve required pulse width. */

  uint32_t IrDAMode;                  /*!< Specifies the IrDA mode
                                           This parameter can be a value of @ref IRDA_Low_Power */
} IRDA_InitTypeDef;

/**
  * @brief HAL IRDA State structures definition
  * @note  HAL IRDA State value is a combination of 2 different substates: gState and RxState.
  *        - gState contains IRDA state information related to global Handle management
  *          and also information related to Tx operations.
  *          gState value coding follow below described bitmap :
  *          b7-b6  Error information
  *             00 : No Error
  *             01 : (Not Used)
  *             10 : Timeout
  *             11 : Error
  *          b5     IP initilisation status
  *             0  : Reset (IP not initialized)
  *             1  : Init done (IP not initialized. HAL IRDA Init function already called)
  *          b4-b3  (not used)
  *             xx : Should be set to 00
  *          b2     Intrinsic process state
  *             0  : Ready
  *             1  : Busy (IP busy with some configuration or internal operations)
  *          b1     (not used)
  *             x  : Should be set to 0
  *          b0     Tx state
  *             0  : Ready (no Tx operation ongoing)
  *             1  : Busy (Tx operation ongoing)
  *        - RxState contains information related to Rx operations.
  *          RxState value coding follow below described bitmap :
  *          b7-b6  (not used)
  *             xx : Should be set to 00
  *          b5     IP initilisation status
  *             0  : Reset (IP not initialized)
  *             1  : Init done (IP not initialized)
  *          b4-b2  (not used)
  *            xxx : Should be set to 000
  *          b1     Rx state
  *             0  : Ready (no Rx operation ongoing)
  *             1  : Busy (Rx operation ongoing)
  *          b0     (not used)
  *             x  : Should be set to 0.
  */

/**
  * @brief IRDA clock sources definition
  */
typedef enum
{
  IRDA_CLOCKSOURCE_PCLK1      = 0x00U,    /*!< PCLK1 clock source         */
  IRDA_CLOCKSOURCE_PCLK2      = 0x01U,    /*!< PCLK2 clock source         */
  IRDA_CLOCKSOURCE_HSI        = 0x02U,    /*!< HSI clock source           */
  IRDA_CLOCKSOURCE_SYSCLK     = 0x04U,    /*!< SYSCLK clock source        */
  IRDA_CLOCKSOURCE_LSE        = 0x10U,    /*!< LSE clock source           */
  IRDA_CLOCKSOURCE_UNDEFINED  = 0x20U     /*!< Undefined clock source     */
} IRDA_ClockSourceTypeDef;

/** @defgroup IRDA_State_Definition IRDA State Code Definition
  * @{
  */
typedef enum
{
  HAL_IRDA_STATE_RESET             = 0x00U,    /*!< Peripheral is not yet Initialized
                                                   Value is allowed for gState and RxState */
  HAL_IRDA_STATE_READY             = 0x20U,    /*!< Peripheral Initialized and ready for use
                                                   Value is allowed for gState and RxState */
  HAL_IRDA_STATE_BUSY              = 0x24U,    /*!< An internal process is ongoing
                                                   Value is allowed for gState only */
  HAL_IRDA_STATE_BUSY_TX           = 0x21U,    /*!< Data Transmission process is ongoing
                                                   Value is allowed for gState only */
  HAL_IRDA_STATE_BUSY_RX           = 0x22U,    /*!< Data Reception process is ongoing
                                                   Value is allowed for RxState only */
  HAL_IRDA_STATE_BUSY_TX_RX        = 0x23U,    /*!< Data Transmission and Reception process is ongoing
                                                   Not to be used for neither gState nor RxState.
                                                   Value is result of combination (Or) between gState and RxState values */
  HAL_IRDA_STATE_TIMEOUT           = 0xA0U,    /*!< Timeout state
                                                   Value is allowed for gState only */
  HAL_IRDA_STATE_ERROR             = 0xE0U     /*!< Error
                                                   Value is allowed for gState only */
} HAL_IRDA_StateTypeDef;

/**
  * @}
  */

/**
  * @brief IRDA handle Structure definition
  */
#if (USE_HAL_IRDA_REGISTER_CALLBACKS == 1)
typedef struct __IRDA_HandleTypeDef
#else
typedef struct
#endif  /* USE_HAL_IRDA_REGISTER_CALLBACKS */
{
  USART_TypeDef               *Instance;        /*!<  USART registers base address       */

  IRDA_InitTypeDef            Init;             /*!<  IRDA communication parameters      */

  uint8_t                     *pTxBuffPtr;      /*!<  Pointer to IRDA Tx transfer Buffer */

  uint32_t                    TxXferSize;       /*!<  IRDA Tx Transfer size              */

  __IO uint32_t               TxXferCount;      /*!<  IRDA Tx Transfer Counter           */

  uint8_t                     *pRxBuffPtr;      /*!<  Pointer to IRDA Rx transfer Buffer */

  uint32_t                    RxXferSize;       /*!<  IRDA Rx Transfer size              */

  __IO uint32_t               RxXferCount;      /*!<  IRDA Rx Transfer Counter           */

  uint16_t                    Mask;             /*!< USART RX RDR register mask         */

  DMA_HandleTypeDef           *hdmatx;          /*!<  IRDA Tx DMA Handle parameters      */

  DMA_HandleTypeDef           *hdmarx;          /*!<  IRDA Rx DMA Handle parameters      */

  HAL_LockTypeDef             Lock;             /*!<  Locking object                     */

  __IO HAL_IRDA_StateTypeDef  gState;           /*!<  IRDA state information related to global Handle management
                                                   and also related to Tx operations.
                                                   This parameter can be a value of @ref HAL_IRDA_StateTypeDef */

  __IO HAL_IRDA_StateTypeDef  RxState;          /*!<  IRDA state information related to Rx operations.
                                                   This parameter can be a value of @ref HAL_IRDA_StateTypeDef */

  __IO uint32_t               ErrorCode;        /*!< IRDA Error code                    */

#if (USE_HAL_IRDA_REGISTER_CALLBACKS == 1)
  void (* TxBlockCpltCallback)(struct __IRDA_HandleTypeDef *hirda);       /*!< IRDA Tx Block Complete Callback       */
  void (* TxHalfBlockCpltCallback)(struct __IRDA_HandleTypeDef *hirda);   /*!< IRDA Tx Half Block Complete Callback  */
  void (* TxSrcCpltCallback)(struct __IRDA_HandleTypeDef *hirda);         /*!< IRDA Tx Source Complete Callback      */
  void (* TxCpltCallback)(struct __IRDA_HandleTypeDef *hirda);            /*!< IRDA Tx Complete Callback             */
  void (* RxBlockCpltCallback)(struct __IRDA_HandleTypeDef *hirda);       /*!< IRDA Rx Block Complete Callback       */
  void (* RxHalfBlockCpltCallback)(struct __IRDA_HandleTypeDef *hirda);   /*!< IRDA Rx Half Block Complete Callback  */
  void (* RxDstCpltCallback)(struct __IRDA_HandleTypeDef *hirda);         /*!< IRDA Rx Destination Complete Callback */
  void (* RxCpltCallback)(struct __IRDA_HandleTypeDef *hirda);            /*!< IRDA Rx Complete Callback             */
  void (* ErrorCallback)(struct __IRDA_HandleTypeDef *hirda);             /*!< IRDA Error Callback                   */
  void (* AbortCpltCallback)(struct __IRDA_HandleTypeDef *hirda);         /*!< IRDA Abort Complete Callback          */
  void (* AbortTransmitCpltCallback)(struct __IRDA_HandleTypeDef *hirda); /*!< IRDA Abort Transmit Complete Callback */
  void (* AbortReceiveCpltCallback)(struct __IRDA_HandleTypeDef *hirda);  /*!< IRDA Abort Receive Complete Callback  */

  void (* MspInitCallback)(struct __IRDA_HandleTypeDef *hirda);           /*!< IRDA Msp Init callback                */
  void (* MspDeInitCallback)(struct __IRDA_HandleTypeDef *hirda);         /*!< IRDA Msp DeInit callback              */
#endif  /* USE_HAL_IRDA_REGISTER_CALLBACKS */

} IRDA_HandleTypeDef;

#if (USE_HAL_IRDA_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL IRDA Callback ID enumeration definition
  */
typedef enum
{
  HAL_IRDA_TX_BLOCKCOMPLETE_CB_ID        = 0x00U,    /*!< IRDA Tx Block Complete Callback ID       */
  HAL_IRDA_TX_HALFBLOCKCOMPLETE_CB_ID    = 0x01U,    /*!< IRDA Tx Half Block Complete Callback ID  */
  HAL_IRDA_TX_SRCCOMPLETE_CB_ID          = 0x02U,    /*!< IRDA Tx Source Complete Callback ID      */
  HAL_IRDA_TX_COMPLETE_CB_ID             = 0x03U,    /*!< IRDA Tx Complete Callback ID             */
  HAL_IRDA_RX_BLOCKCOMPLETE_CB_ID        = 0x04U,    /*!< IRDA Rx Block Complete Callback ID       */
  HAL_IRDA_RX_HALFBLOCKCOMPLETE_CB_ID    = 0x05U,    /*!< IRDA Rx Half Block Complete Callback ID  */
  HAL_IRDA_RX_DSTCOMPLETE_CB_ID          = 0x06U,    /*!< IRDA Rx Destination Complete Callback ID */
  HAL_IRDA_RX_COMPLETE_CB_ID             = 0x07U,    /*!< IRDA Rx Complete Callback ID             */
  HAL_IRDA_ERROR_CB_ID                   = 0x08U,    /*!< IRDA Error Callback ID                   */
  HAL_IRDA_ABORT_COMPLETE_CB_ID          = 0x09U,    /*!< IRDA Abort Complete Callback ID          */
  HAL_IRDA_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x0AU,    /*!< IRDA Abort Transmit Complete Callback ID */
  HAL_IRDA_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x0BU,    /*!< IRDA Abort Receive Complete Callback ID  */

  HAL_IRDA_MSPINIT_CB_ID                 = 0x0CU,    /*!< IRDA MspInit callback ID                 */
  HAL_IRDA_MSPDEINIT_CB_ID               = 0x0DU     /*!< IRDA MspDeInit callback ID               */

} HAL_IRDA_CallbackIDTypeDef;

/**
  * @brief  HAL IRDA Callback pointer definition
  */
typedef  void (*pIRDA_CallbackTypeDef)(IRDA_HandleTypeDef *hirda);  /*!< pointer to an IRDA callback function */

#endif /* USE_HAL_IRDA_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup IRDA_Exported_Constants IRDA Exported constants
  * @{
  */
  
/** @defgroup IRDA_Error_Code IRDA Error Code
  * @{
  */
#define HAL_IRDA_ERROR_NONE        0x00000000U   /*!< No error            */
#define HAL_IRDA_ERROR_PE          0x00000001U   /*!< Parity error        */
#define HAL_IRDA_ERROR_NE          0x00000002U   /*!< Noise error         */
#define HAL_IRDA_ERROR_FE          0x00000004U   /*!< Frame error         */
#define HAL_IRDA_ERROR_ORE         0x00000008U   /*!< Overrun error       */
#define HAL_IRDA_ERROR_DMA         0x00000010U   /*!< DMA transfer error  */
#define HAL_IRDA_ERROR_BUSY        0x00000020U   /*!< Busy Error          */
#if (USE_HAL_IRDA_REGISTER_CALLBACKS == 1)
#define HAL_IRDA_ERROR_INVALID_CALLBACK   ((uint32_t)0x00000040U)   /*!< Invalid Callback error  */
#endif /* USE_HAL_IRDA_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup IRDA_Word_Length IRDA Word Length
  * @{
  */
#define IRDA_WORDLENGTH_7B         USART_CR1_M1   /*!< 7-bit long frame */
#define IRDA_WORDLENGTH_8B         0x00000000U    /*!< 8-bit long frame */
#define IRDA_WORDLENGTH_9B         USART_CR1_M0   /*!< 9-bit long frame */
/**
  * @}
  */

/** @defgroup IRDA_Parity  IRDA Parity
  * @{
  */
#define IRDA_PARITY_NONE                    0x00000000U                      /*!< No parity   */
#define IRDA_PARITY_EVEN                    USART_CR1_PCE                    /*!< Even parity */
#define IRDA_PARITY_ODD                     (USART_CR1_PCE | USART_CR1_PS)   /*!< Odd parity  */
/**
  * @}
  */

/** @defgroup IRDA_Transfer_Mode IRDA Transfer Mode
  * @{
  */
#define IRDA_MODE_RX                        USART_CR1_RE                   /*!< RX mode        */
#define IRDA_MODE_TX                        USART_CR1_TE                   /*!< TX mode        */
#define IRDA_MODE_TX_RX                     (USART_CR1_TE |USART_CR1_RE)   /*!< RX and TX mode */
/**
  * @}
  */

/** @defgroup IRDA_Low_Power IRDA Low Power
  * @{
  */
#define IRDA_POWERMODE_NORMAL               0x00000000U       /*!< IRDA normal power mode */
#define IRDA_POWERMODE_LOWPOWER             USART_CR3_IRLP    /*!< IRDA low power mode    */
/**
  * @}
  */


/** @defgroup IRDA_State IRDA State
  * @{
  */
#define IRDA_STATE_DISABLE                  0x00000000U     /*!< IRDA disabled  */
#define IRDA_STATE_ENABLE                   USART_CR1_UE    /*!< IRDA enabled   */
/**
  * @}
  */

/** @defgroup IRDA_Mode IRDA Transfer Mode
  * @{
  */
#define IRDA_MODE_DISABLE                   0x00000000U      /*!< Associated SCI disabled in IRDA mode */
#define IRDA_MODE_ENABLE                    USART_CR3_IREN   /*!< Associated SCI enabled in IRDA mode  */
/**
  * @}
  */

/** @defgroup IRDA_DMA_Tx IRDA DMA Tx
  * @{
  */
#define IRDA_DMA_TX_DISABLE                 0x00000000U       /*!< IRDA DMA TX disabled */
#define IRDA_DMA_TX_ENABLE                  USART_CR3_DMAT    /*!< IRDA DMA TX enabled  */
/**
  * @}
  */

/** @defgroup IRDA_DMA_Rx IRDA DMA Rx
  * @{
  */
#define IRDA_DMA_RX_DISABLE                 0x00000000U       /*!< IRDA DMA RX disabled */
#define IRDA_DMA_RX_ENABLE                  USART_CR3_DMAR    /*!< IRDA DMA RX enabled  */
/**
  * @}
  */

/** @defgroup IRDA_Request_Parameters IRDA Request Parameters
  * @{
  */
#define IRDA_AUTOBAUD_REQUEST            USART_SR_ABRRQ         /*!< Auto-Baud Rate Request      */
#define IRDA_RXDATA_FLUSH_REQUEST        USART_CR1_RXFRQ        /*!< Receive Data flush Request  */
#define IRDA_TXDATA_FLUSH_REQUEST        USART_CR1_TXFRQ        /*!< Transmit data flush Request */
/**
  * @}
  */

/** @defgroup IRDA_Flags IRDA Flags
  *        Elements values convention: 0xXXXX
  *           - 0xXXXX  : Flag mask in the SR register
  * @{
  */
#define IRDA_FLAG_ABRF             ((uint32_t)USART_SR_ABRF)   /*!< IRDA auto Baud rate flag  */
#define IRDA_FLAG_ABRE             ((uint32_t)USART_SR_ABRE)   /*!< IRDA auto Baud rate error */
#define IRDA_FLAG_TXE              ((uint32_t)USART_SR_TXE)
#define IRDA_FLAG_TC               ((uint32_t)USART_SR_TC)
#define IRDA_FLAG_RXNE             ((uint32_t)USART_SR_RXNE)
#define IRDA_FLAG_IDLE             ((uint32_t)USART_SR_IDLE)
#define IRDA_FLAG_ORE              ((uint32_t)USART_SR_ORE)
#define IRDA_FLAG_NE               ((uint32_t)USART_SR_NE)
#define IRDA_FLAG_FE               ((uint32_t)USART_SR_FE)
#define IRDA_FLAG_PE               ((uint32_t)USART_SR_PE)
/**
  * @}
  */

/** @defgroup IRDA_Interrupt_definition IRDA Interrupt Definitions
  *        Elements values convention: 0xY000XXXX
  *           - XXXX  : Interrupt mask in the XX register
  *           - Y  : Interrupt source register (2bits)
  *                 - 01: CR1 register
  *                 - 10: CR2 register
  *                 - 11: CR3 register
  * @{
  */
#define IRDA_IT_PE                 ((uint32_t)(IRDA_CR1_REG_INDEX << 28U | USART_CR1_PEIE))
#define IRDA_IT_TXE                ((uint32_t)(IRDA_CR1_REG_INDEX << 28U | USART_CR1_TXEIE))
#define IRDA_IT_TC                 ((uint32_t)(IRDA_CR1_REG_INDEX << 28U | USART_CR1_TCIE))
#define IRDA_IT_RXNE               ((uint32_t)(IRDA_CR1_REG_INDEX << 28U | USART_CR1_RXNEIE))
#define IRDA_IT_IDLE               ((uint32_t)(IRDA_CR1_REG_INDEX << 28U | USART_CR1_IDLEIE))

#define IRDA_IT_LBD                ((uint32_t)(IRDA_CR2_REG_INDEX << 28U | USART_CR2_LBDIE))

#define IRDA_IT_CTS                ((uint32_t)(IRDA_CR3_REG_INDEX << 28U | USART_CR3_CTSIE))
#define IRDA_IT_ERR                ((uint32_t)(IRDA_CR3_REG_INDEX << 28U | USART_CR3_EIE))
/**
  * @}
  */


/** @brief IRDA interruptions flag mask
  *
  */
#define IRDA_IT_MASK  ((uint32_t) USART_CR1_PEIE | USART_CR1_TXEIE | USART_CR1_TCIE | USART_CR1_RXNEIE | \
                                  USART_CR1_IDLEIE | USART_CR2_LBDIE | USART_CR3_CTSIE | USART_CR3_EIE )

#define IRDA_CR1_REG_INDEX         1U
#define IRDA_CR2_REG_INDEX         2U
#define IRDA_CR3_REG_INDEX         3U
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup IRDA_Exported_Macros IRDA Exported Macros
  * @{
  */

/** @brief Reset IRDA handle gstate & RxState
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USARTx or SCIy peripheral
  *         (USART,SCI availability and x,y values depending on device).
  * @retval None
  */
#if USE_HAL_IRDA_REGISTER_CALLBACKS == 1
#define __HAL_IRDA_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_IRDA_STATE_RESET;      \
                                                       (__HANDLE__)->RxState = HAL_IRDA_STATE_RESET;     \
                                                       (__HANDLE__)->MspInitCallback = NULL;             \
                                                       (__HANDLE__)->MspDeInitCallback = NULL;           \
                                                     } while(0U)
#else
#define __HAL_IRDA_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_IRDA_STATE_RESET;      \
                                                       (__HANDLE__)->RxState = HAL_IRDA_STATE_RESET;     \
                                                     } while(0U)
#endif /*USE_HAL_IRDA_REGISTER_CALLBACKS  */

/** @brief  Flush the IRDA DR register
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USARTx or SCIy peripheral
  *         (USART,SCI availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_IRDA_FLUSH_DRREGISTER(__HANDLE__) ((__HANDLE__)->Instance->DR)

/** @brief  Check whether the specified IRDA flag is set or not.
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USARTx or SCIy peripheral
  *         (USART,SCI availability and x,y values depending on device).
  * @param  __FLAG__ specifies the flag to check.
  *        This parameter can be one of the following values:
  *            @arg IRDA_FLAG_TXE:  Transmit data register empty flag
  *            @arg IRDA_FLAG_TC:   Transmission Complete flag
  *            @arg IRDA_FLAG_RXNE: Receive data register not empty flag
  *            @arg IRDA_FLAG_IDLE: Idle Line detection flag
  *            @arg IRDA_FLAG_ORE:  OverRun Error flag
  *            @arg IRDA_FLAG_NE:   Noise Error flag
  *            @arg IRDA_FLAG_FE:   Framing Error flag
  *            @arg IRDA_FLAG_PE:   Parity Error flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_IRDA_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))

/** @brief  Clear the specified IRDA pending flag.
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USARTx or SCIy peripheral
  *         (USART,SCI availability and x,y values depending on device).
  * @param  __FLAG__ specifies the flag to check.
  *          This parameter can be any combination of the following values:
  *            @arg IRDA_FLAG_TC:   Transmission Complete flag.
  *            @arg IRDA_FLAG_RXNE: Receive data register not empty flag.
  *
  * @note   PE (Parity error), FE (Framing error), NE (Noise error), ORE (OverRun
  *          error) and IDLE (Idle line detected) flags are cleared by software
  *          sequence: a read operation to USART_SR register followed by a read
  *          operation to USART_DR register.
  * @note   RXNE flag can be also cleared by a read to the USART_DR register.
  * @note   TC flag can be also cleared by software sequence: a read operation to
  *          USART_SR register followed by a write operation to USART_DR register.
  * @note   TXE flag is cleared only by a write to the USART_DR register.
  * @retval None
  */
#define __HAL_IRDA_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/** @brief  Clear the IRDA PE pending flag.
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USARTx or SCIy peripheral
  *         (USART,SCI availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_IRDA_CLEAR_PEFLAG(__HANDLE__)     \
  do{                                           \
    __IO uint32_t tmpreg = 0x00U;               \
    tmpreg = (__HANDLE__)->Instance->SR;        \
    tmpreg = (__HANDLE__)->Instance->DR;        \
    UNUSED(tmpreg);                             \
  } while(0U)

/** @brief  Clear the IRDA FE pending flag.
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USART peripheral
  *         (USART values depending on device).
  * @retval None
  */
#define __HAL_IRDA_CLEAR_FEFLAG(__HANDLE__) __HAL_IRDA_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clear the IRDA NE pending flag.
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USART peripheral
  *         (USART values depending on device).
  * @retval None
  */
#define __HAL_IRDA_CLEAR_NEFLAG(__HANDLE__) __HAL_IRDA_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clear the IRDA ORE pending flag.
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USART peripheral
  *         (USART values depending on device).
  * @retval None
  */
#define __HAL_IRDA_CLEAR_OREFLAG(__HANDLE__) __HAL_IRDA_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clear the IRDA IDLE pending flag.
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USART peripheral
  *         (USART values depending on device).
  * @retval None
  */
#define __HAL_IRDA_CLEAR_IDLEFLAG(__HANDLE__) __HAL_IRDA_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Enable the specified IRDA interrupt.
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USART peripheral
  *         (USART values depending on device).
  * @param  __INTERRUPT__ specifies the IRDA interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg IRDA_IT_TXE:  Transmit Data Register empty interrupt
  *            @arg IRDA_IT_TC:   Transmission complete interrupt
  *            @arg IRDA_IT_RXNE: Receive Data register not empty interrupt
  *            @arg IRDA_IT_IDLE: Idle line detection interrupt
  *            @arg IRDA_IT_PE:   Parity Error interrupt
  *            @arg IRDA_IT_ERR:  Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_IRDA_ENABLE_IT(__HANDLE__, __INTERRUPT__)   ((((__INTERRUPT__) >> 28U) == IRDA_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 |= ((__INTERRUPT__) & IRDA_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == IRDA_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 |=  ((__INTERRUPT__) & IRDA_IT_MASK)): \
                                                            ((__HANDLE__)->Instance->CR3 |= ((__INTERRUPT__) & IRDA_IT_MASK)))
/** @brief  Disable the specified IRDA interrupt.
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USART peripheral
  *         (USART values depending on device).
  * @param  __INTERRUPT__ specifies the IRDA interrupt source to disable.
  *          This parameter can be one of the following values:
  *            @arg IRDA_IT_TXE:  Transmit Data Register empty interrupt
  *            @arg IRDA_IT_TC:   Transmission complete interrupt
  *            @arg IRDA_IT_RXNE: Receive Data register not empty interrupt
  *            @arg IRDA_IT_IDLE: Idle line detection interrupt
  *            @arg IRDA_IT_PE:   Parity Error interrupt
  *            @arg IRDA_IT_ERR:  Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_IRDA_DISABLE_IT(__HANDLE__, __INTERRUPT__)  ((((__INTERRUPT__) >> 28U) == IRDA_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 &= ~((__INTERRUPT__) & IRDA_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == IRDA_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 &= ~((__INTERRUPT__) & IRDA_IT_MASK)): \
                                                           ((__HANDLE__)->Instance->CR3 &= ~ ((__INTERRUPT__) & IRDA_IT_MASK)))

/** @brief  Check whether the specified IRDA interrupt has occurred or not.
  * @param  __HANDLE__ specifies the IRDA Handle.
  *         IRDA Handle selects the USART peripheral
  *         (USART values depending on device).
  * @param  __IT__ specifies the IRDA interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg IRDA_IT_TXE: Transmit Data Register empty interrupt
  *            @arg IRDA_IT_TC:  Transmission complete interrupt
  *            @arg IRDA_IT_RXNE: Receive Data register not empty interrupt
  *            @arg IRDA_IT_IDLE: Idle line detection interrupt
  *            @arg IRDA_IT_ERR: Error interrupt
  *            @arg IRDA_IT_PE: Parity Error interrupt
  * @retval The new state of __IT__ (TRUE or FALSE).
  */
#define __HAL_IRDA_GET_IT_SOURCE(__HANDLE__, __IT__) (((((__IT__) >> 28U) == IRDA_CR1_REG_INDEX)? (__HANDLE__)->Instance->CR1:(((((uint32_t)(__IT__)) >> 28U) == IRDA_CR2_REG_INDEX)? \
                                                      (__HANDLE__)->Instance->CR2 : (__HANDLE__)->Instance->CR3)) & (((uint32_t)(__IT__)) & IRDA_IT_MASK))

/** @brief  Enable USART associated to IRDA Handle.
  * @param  __HANDLE__ specifies the IRDA Handle.
  * @retval None
  */
#define __HAL_IRDA_ENABLE(__HANDLE__)                   ((__HANDLE__)->Instance->CR1 |=  USART_CR1_UE)

/** @brief  Disable USART associated to IRDA Handle.
  * @param  __HANDLE__ specifies the IRDA Handle.
  * @retval None
  */
#define __HAL_IRDA_DISABLE(__HANDLE__)                  ((__HANDLE__)->Instance->CR1 &=  ~USART_CR1_UE)

/* Private macros --------------------------------------------------------*/
/** @addtogroup IRDA_Private_Macros
  * @{
  */

/** @brief  Ensure that IRDA Baud rate is less or equal to maximum value.
  * @param  __BAUDRATE__ specifies the IRDA Baudrate set by the user.
  * @retval True or False
  */
#define IS_IRDA_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) < 115201U)

/** @brief Ensure that IRDA frame parity is valid.
  * @param __PARITY__ IRDA frame parity.
  * @retval SET (__PARITY__ is valid) or RESET (__PARITY__ is invalid)
  */
#define IS_IRDA_PARITY(__PARITY__) (((__PARITY__) == IRDA_PARITY_NONE) || \
                                    ((__PARITY__) == IRDA_PARITY_EVEN) || \
                                    ((__PARITY__) == IRDA_PARITY_ODD))

/** @brief Ensure that IRDA communication mode is valid.
  * @param __MODE__ IRDA communication mode.
  * @retval SET (__MODE__ is valid) or RESET (__MODE__ is invalid)
  */
#define IS_IRDA_TX_RX_MODE(__MODE__) ((((__MODE__)\
                                        & (~((uint32_t)(IRDA_MODE_TX_RX)))) == 0x00U) && ((__MODE__) != 0x00U))

/** @brief Ensure that IRDA power mode is valid.
  * @param __MODE__ IRDA power mode.
  * @retval SET (__MODE__ is valid) or RESET (__MODE__ is invalid)
  */
#define IS_IRDA_POWERMODE(__MODE__) (((__MODE__) == IRDA_POWERMODE_LOWPOWER) || \
                                     ((__MODE__) == IRDA_POWERMODE_NORMAL))

/** @brief Ensure that IRDA associated SCI/USART mode is valid.
  * @param __MODE__ IRDA associated SCI/USART mode.
  * @retval SET (__MODE__ is valid) or RESET (__MODE__ is invalid)
  */
#define IS_IRDA_MODE(__MODE__)  (((__MODE__) == IRDA_MODE_DISABLE) || \
                                 ((__MODE__) == IRDA_MODE_ENABLE))

/** @brief Ensure that IRDA DMA TX mode is valid.
  * @param __DMATX__ IRDA DMA TX mode.
  * @retval SET (__DMATX__ is valid) or RESET (__DMATX__ is invalid)
  */
#define IS_IRDA_DMA_TX(__DMATX__)     (((__DMATX__) == IRDA_DMA_TX_DISABLE) || \
                                       ((__DMATX__) == IRDA_DMA_TX_ENABLE))

/** @brief Ensure that IRDA DMA RX mode is valid.
  * @param __DMARX__ IRDA DMA RX mode.
  * @retval SET (__DMARX__ is valid) or RESET (__DMARX__ is invalid)
  */
#define IS_IRDA_DMA_RX(__DMARX__) (((__DMARX__) == IRDA_DMA_RX_DISABLE) || \
                                   ((__DMARX__) == IRDA_DMA_RX_ENABLE))

/** @brief Ensure that IRDA request is valid.
  * @param __PARAM__ IRDA request.
  * @retval SET (__PARAM__ is valid) or RESET (__PARAM__ is invalid)
  */
#define IS_IRDA_REQUEST_PARAMETER(__PARAM__) (((__PARAM__) == IRDA_AUTOBAUD_REQUEST) || \
                                              ((__PARAM__) == IRDA_RXDATA_FLUSH_REQUEST) || \
                                              ((__PARAM__) == IRDA_TXDATA_FLUSH_REQUEST))

/** @brief Ensure that IRDA frame length is valid.
  * @param __LENGTH__ IRDA frame length.
  * @retval SET (__LENGTH__ is valid) or RESET (__LENGTH__ is invalid)
  */
#define IS_IRDA_WORD_LENGTH(__LENGTH__) (((__LENGTH__) == IRDA_WORDLENGTH_7B) || \
                                         ((__LENGTH__) == IRDA_WORDLENGTH_8B) || \
                                         ((__LENGTH__) == IRDA_WORDLENGTH_9B))
/**
  * @}
  */

#define IRDA_DIV(_PCLK_, _BAUD_)      (((_PCLK_)*25U)/(4U*(_BAUD_)))

#define IRDA_DIVMANT(_PCLK_, _BAUD_)  (IRDA_DIV((_PCLK_), (_BAUD_))/100U)

#define IRDA_DIVFRAQ(_PCLK_, _BAUD_)  (((IRDA_DIV((_PCLK_), (_BAUD_)) - (IRDA_DIVMANT((_PCLK_), (_BAUD_)) * 100U)) * 16U + 50U) / 100U)

/* IRDA BRR = mantissa + overflow + fraction
            = (IRDA DIVMANT << 4) + (IRDA DIVFRAQ & 0xF0) + (IRDA DIVFRAQ & 0x0FU) */
#define IRDA_BRR(_PCLK_, _BAUD_)      (((IRDA_DIVMANT((_PCLK_), (_BAUD_)) << 4U) + \
                                        (IRDA_DIVFRAQ((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                        (IRDA_DIVFRAQ((_PCLK_), (_BAUD_)) & 0x0FU))

/** @brief  Compute the mask to apply to retrieve the received data
  *         according to the word length and to the parity bits activation.
  * @param  __HANDLE__ specifies the IRDA Handle.
  * @retval None, the mask to apply to the associated USART DR register is stored in (__HANDLE__)->Mask field.
  */
#define IRDA_MASK_COMPUTATION(__HANDLE__)                             \
  do {                                                                \
    if ((__HANDLE__)->Init.WordLength == IRDA_WORDLENGTH_9B)          \
    {                                                                 \
      if ((__HANDLE__)->Init.Parity == IRDA_PARITY_NONE)              \
      {                                                               \
        (__HANDLE__)->Mask = 0x01FFU ;                                \
      }                                                               \
      else                                                            \
      {                                                               \
        (__HANDLE__)->Mask = 0x00FFU ;                                \
      }                                                               \
    }                                                                 \
    else if ((__HANDLE__)->Init.WordLength == IRDA_WORDLENGTH_8B)     \
    {                                                                 \
      if ((__HANDLE__)->Init.Parity == IRDA_PARITY_NONE)              \
      {                                                               \
        (__HANDLE__)->Mask = 0x00FFU ;                                \
      }                                                               \
      else                                                            \
      {                                                               \
        (__HANDLE__)->Mask = 0x007FU ;                                \
      }                                                               \
    }                                                                 \
    else if ((__HANDLE__)->Init.WordLength == IRDA_WORDLENGTH_7B)     \
    {                                                                 \
      if ((__HANDLE__)->Init.Parity == IRDA_PARITY_NONE)              \
      {                                                               \
        (__HANDLE__)->Mask = 0x007FU ;                                \
      }                                                               \
      else                                                            \
      {                                                               \
        (__HANDLE__)->Mask = 0x003FU ;                                \
      }                                                               \
    }                                                                 \
    else                                                              \
    {                                                                 \
      (__HANDLE__)->Mask = 0x0000U;                                   \
    }                                                                 \
  } while(0U)

/** @brief  Report the IRDA clock source.
  * @param  __HANDLE__ specifies the IRDA Handle.
  * @param  __CLOCKSOURCE__ output variable.
  * @retval IRDA clocking source, written in __CLOCKSOURCE__.
  */
#define IRDA_GETCLOCKSOURCE(__HANDLE__,__CLOCKSOURCE__)        \
  do {                                                         \
    if((__HANDLE__)->Instance == USART1)                       \
    {                                                          \
      switch(__HAL_RCC_GET_USART1_SOURCE())                    \
      {                                                        \
        case RCC_USART1CLKSOURCE_PCLK2:                        \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_PCLK2;          \
          break;                                               \
        case RCC_USART1CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_HSI;            \
          break;                                               \
        case RCC_USART1CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_SYSCLK;         \
          break;                                               \
        case RCC_USART1CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_LSE;            \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_UNDEFINED;      \
          break;                                               \
      }                                                        \
    }                                                          \
    else if((__HANDLE__)->Instance == USART2)                  \
    {                                                          \
      switch(__HAL_RCC_GET_USART2_SOURCE())                    \
      {                                                        \
        case RCC_USART2CLKSOURCE_PCLK1:                        \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_PCLK1;          \
          break;                                               \
        case RCC_USART2CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_HSI;            \
          break;                                               \
        case RCC_USART2CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_SYSCLK;         \
          break;                                               \
        case RCC_USART2CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_LSE;            \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_UNDEFINED;      \
          break;                                               \
      }                                                        \
    }                                                          \
    else if((__HANDLE__)->Instance == USART3)                  \
    {                                                          \
      switch(__HAL_RCC_GET_USART3_SOURCE())                    \
      {                                                        \
        case RCC_USART3CLKSOURCE_PCLK1:                        \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_PCLK1;          \
          break;                                               \
        case RCC_USART3CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_HSI;            \
          break;                                               \
        case RCC_USART3CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_SYSCLK;         \
          break;                                               \
        case RCC_USART3CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_LSE;            \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_UNDEFINED;      \
          break;                                               \
      }                                                        \
    }                                                          \
    else                                                       \
    {                                                          \
      (__CLOCKSOURCE__) = IRDA_CLOCKSOURCE_UNDEFINED;          \
    }                                                          \
  } while(0U)
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup IRDA_Exported_Functions
  * @{
  */

/** @addtogroup IRDA_Exported_Functions_Group1
  * @{
  */
/* Initialization/de-initialization functions  **********************************/
HAL_StatusTypeDef HAL_IRDA_Init(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_DeInit(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_MspInit(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_MspDeInit(IRDA_HandleTypeDef *hirda);

#if (USE_HAL_IRDA_REGISTER_CALLBACKS == 1)
/* Callbacks Register/UnRegister functions  ***********************************/
HAL_StatusTypeDef HAL_IRDA_RegisterCallback(IRDA_HandleTypeDef *hirda, HAL_IRDA_CallbackIDTypeDef CallbackID, pIRDA_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_IRDA_UnRegisterCallback(IRDA_HandleTypeDef *hirda, HAL_IRDA_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_IRDA_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup IRDA_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *******************************************************/
HAL_StatusTypeDef HAL_IRDA_Transmit(IRDA_HandleTypeDef *hirda, uint8_t *pData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_IRDA_Receive(IRDA_HandleTypeDef *hirda, uint8_t *pData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_IRDA_Transmit_IT(IRDA_HandleTypeDef *hirda, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_IRDA_Receive_IT(IRDA_HandleTypeDef *hirda, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_IRDA_Transmit_DMA(IRDA_HandleTypeDef *hirda, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_IRDA_Receive_DMA(IRDA_HandleTypeDef *hirda, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_IRDA_DMAPause(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_DMAResume(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_DMAStop(IRDA_HandleTypeDef *hirda);
/* Transfer Abort functions */
HAL_StatusTypeDef HAL_IRDA_Abort(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_AbortTransmit(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_AbortReceive(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_Abort_IT(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_AbortTransmit_IT(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_AbortReceive_IT(IRDA_HandleTypeDef *hirda);

void HAL_IRDA_IRQHandler(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_TxCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_RxCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_TxBlockCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_TxHalfBlockCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_TxSrcCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_RxBlockCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_RxHalfBlockCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_RxDstCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_ErrorCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_AbortCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_AbortTransmitCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_AbortReceiveCpltCallback(IRDA_HandleTypeDef *hirda);
/**
  * @}
  */

/** @addtogroup IRDA_Exported_Functions_Group3
  * @{
  */
/* Peripheral State functions  **************************************************/
HAL_IRDA_StateTypeDef HAL_IRDA_GetState(IRDA_HandleTypeDef *hirda);
uint32_t HAL_IRDA_GetError(IRDA_HandleTypeDef *hirda);
/**
  * @}
  */

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

#endif /* __PY32E407_HAL_IRDA_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

