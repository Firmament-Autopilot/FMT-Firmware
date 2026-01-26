/**
  ******************************************************************************
  * @file    py32e407_hal_usart.h
  * @author  MCU Application Team
  * @brief   Header file of USART HAL module.
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
#ifndef __PY32E407_HAL_USART_H
#define __PY32E407_HAL_USART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup USART
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup USART_Exported_Types USART Exported Types
  * @{
  */

/**
  * @brief USART Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< This member configures the Usart communication baud rate.
                                           The baud rate is computed using the following formula:
                                              Baud Rate Register[15:4] = ((2 * fclk_pres) /
                                              ((husart->Init.BaudRate)))[15:4]
                                              Baud Rate Register[3]    = 0
                                              Baud Rate Register[2:0]  =  (((2 * fclk_pres) /
                                              ((husart->Init.BaudRate)))[3:0]) >> 1
                                              where fclk_pres is the USART input clock frequency (fclk)
                                              divided by a prescaler.
                                           @note  Oversampling by 8 is systematically applied to
                                                  achieve high baud rates. */

  uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref USARTEx_Word_Length. */

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref USART_Stop_Bits. */

  uint32_t Parity;                   /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref USART_Parity
                                           @note When parity is enabled, the computed parity is inserted
                                                 at the MSB position of the transmitted data (9th bit when
                                                 the word length is set to 9 data bits; 8th bit when the
                                                 word length is set to 8 data bits). */

  uint32_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref USART_Mode. */

  uint32_t CLKPolarity;               /*!< Specifies the steady state of the serial clock.
                                           This parameter can be a value of @ref USART_Clock_Polarity. */

  uint32_t CLKPhase;                  /*!< Specifies the clock transition on which the bit capture is made.
                                           This parameter can be a value of @ref USART_Clock_Phase. */

  uint32_t CLKLastBit;                /*!< Specifies whether the clock pulse corresponding to the last transmitted
                                           data bit (MSB) has to be output on the SCLK pin in synchronous mode.
                                           This parameter can be a value of @ref USART_Last_Bit. */
} USART_InitTypeDef;

/**
  * @brief HAL USART State structures definition
  * @note  HAL USART State value is a combination of 2 different substates: gState and RxState.
  *        - gState contains USART state information related to global Handle management
  *          and also information related to Tx operations.
  *          gState value coding follow below described bitmap :
  *          b7-b6  Error information
  *             00 : No Error
  *             01 : (Not Used)
  *             10 : Timeout
  *             11 : Error
  *          b5     Peripheral initialization status
  *             0  : Reset (Peripheral not initialized)
  *             1  : Init done (Peripheral not initialized. HAL USART Init function already called)
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
  HAL_USART_STATE_RESET             = 0x00U,    /*!< Peripheral is not yet Initialized
                                                    Value is allowed for gState and RxState */
  HAL_USART_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use
                                                    Value is allowed for gState and RxState */
  HAL_USART_STATE_BUSY              = 0x02U,    /*!< an internal process is ongoing
                                                    Value is allowed for gState only */
  HAL_USART_STATE_BUSY_TX           = 0x12U,    /*!< Data Transmission process is ongoing
                                                    Value is allowed for gState only */
  HAL_USART_STATE_BUSY_RX           = 0x22U,    /*!< Data Reception process is ongoing
                                                    Value is allowed for RxState only */
  HAL_USART_STATE_BUSY_TX_RX        = 0x32U,    /*!< Data Transmission and Reception process is ongoing
                                                    Not to be used for neither gState nor RxState.
                                                    Value is result of combination (Or) between gState and RxState values */
  HAL_USART_STATE_TIMEOUT           = 0x03U,    /*!< Timeout state
                                                    Value is allowed for gState only */
  HAL_USART_STATE_ERROR             = 0x04U     /*!< Error
                                                    Value is allowed for gState only */
} HAL_USART_StateTypeDef;

/**
  * @brief  USART clock sources definitions
  */
typedef enum
{
  USART_CLOCKSOURCE_PCLK1      = 0x00U,    /*!< PCLK1 clock source     */
  USART_CLOCKSOURCE_PCLK2      = 0x01U,    /*!< PCLK2 clock source     */
  USART_CLOCKSOURCE_HSI        = 0x02U,    /*!< HSI clock source       */
  USART_CLOCKSOURCE_SYSCLK     = 0x04U,    /*!< SYSCLK clock source    */
  USART_CLOCKSOURCE_LSE        = 0x08U,    /*!< LSE clock source       */
  USART_CLOCKSOURCE_UNDEFINED  = 0x10U     /*!< Undefined clock source */
} USART_ClockSourceTypeDef;

/**
  * @brief  USART handle Structure definition
  */
typedef struct __USART_HandleTypeDef
{
  USART_TypeDef                 *Instance;               /*!< USART registers base address        */

  USART_InitTypeDef             Init;                    /*!< USART communication parameters      */

  const uint8_t                 *pTxBuffPtr;             /*!< Pointer to USART Tx transfer Buffer */

  uint32_t                      TxXferSize;              /*!< USART Tx Transfer size              */

  __IO uint32_t                 TxXferCount;             /*!< USART Tx Transfer Counter           */

  uint8_t                       *pRxBuffPtr;             /*!< Pointer to USART Rx transfer Buffer */

  uint32_t                      RxXferSize;              /*!< USART Rx Transfer size              */

  __IO uint32_t                 RxXferCount;             /*!< USART Rx Transfer Counter           */

  uint16_t                      Mask;                    /*!< USART Rx RDR register mask          */

  uint32_t                      NbRxDataToProcess;       /*!< Number of data to process during RX SR execution */

  uint32_t                      NbTxDataToProcess;       /*!< Number of data to process during TX SR execution */

  uint32_t                      FifoMode;                /*!< Specifies if the FIFO mode will be used. This parameter can be a value
                                                              of @ref USARTEx_FIFO_mode. */

  void (*RxISR)(struct __USART_HandleTypeDef *husart);   /*!< Function pointer on Rx IRQ handler  */

  void (*TxISR)(struct __USART_HandleTypeDef *husart);   /*!< Function pointer on Tx IRQ handler  */

  DMA_HandleTypeDef             *hdmatx;                 /*!< USART Tx DMA Handle parameters      */

  DMA_HandleTypeDef             *hdmarx;                 /*!< USART Rx DMA Handle parameters      */

  HAL_LockTypeDef               Lock;                    /*!< Locking object                      */

  __IO HAL_USART_StateTypeDef   State;                   /*!< USART communication state           */

  __IO uint32_t                 ErrorCode;               /*!< USART Error code                    */

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  void (* TxSrcCpltCallback)(struct __USART_HandleTypeDef *husart);         /*!< USART Tx Source Complete Callback      */
  void (* TxBlockCpltCallback)(struct __USART_HandleTypeDef *husart);       /*!< USART Tx Block Complete Callback       */
  void (* TxHalfBlockCpltCallback)(struct __USART_HandleTypeDef *husart);   /*!< USART Tx Half Block Complete Callback  */
  void (* TxCpltCallback)(struct __USART_HandleTypeDef *husart);            /*!< USART Tx Complete Callback             */
  void (* RxDstCpltCallback)(struct __USART_HandleTypeDef *husart);         /*!< USART Rx Destination Complete Callback */
  void (* RxBlockCpltCallback)(struct __USART_HandleTypeDef *husart);       /*!< USART Rx Block Complete Callback       */
  void (* RxHalfBlockCpltCallback)(struct __USART_HandleTypeDef *husart);   /*!< USART Rx Half Block Complete Callback  */
  void (* RxCpltCallback)(struct __USART_HandleTypeDef *husart);            /*!< USART Rx Complete Callback             */
  void (* TxRxCpltCallback)(struct __USART_HandleTypeDef *husart);          /*!< USART Tx Rx Complete Callback          */
  void (* ErrorCallback)(struct __USART_HandleTypeDef *husart);             /*!< USART Error Callback                   */
  void (* AbortCpltCallback)(struct __USART_HandleTypeDef *husart);         /*!< USART Abort Complete Callback          */
  void (* RxFifoFullCallback)(struct __USART_HandleTypeDef *husart);        /*!< USART Rx Fifo Full Callback            */
  void (* TxFifoEmptyCallback)(struct __USART_HandleTypeDef *husart);       /*!< USART Tx Fifo Empty Callback           */

  void (* MspInitCallback)(struct __USART_HandleTypeDef *husart);           /*!< USART Msp Init callback                */
  void (* MspDeInitCallback)(struct __USART_HandleTypeDef *husart);         /*!< USART Msp DeInit callback              */
#endif  /* USE_HAL_USART_REGISTER_CALLBACKS */

} USART_HandleTypeDef;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL USART Callback ID enumeration definition
  */
typedef enum
{
  HAL_USART_TX_HALFBLOCKCOMPLETE_CB_ID    = 0x00U,    /*!< USART Tx Half Block Complete Callback ID  */
  HAL_USART_TX_BLOCKCOMPLETE_CB_ID        = 0x01U,    /*!< USART Tx Block Complete Callback ID       */
  HAL_USART_TX_SRCCOMPLETE_CB_ID          = 0x02U,    /*!< USART Tx Source Complete Callback ID      */
  HAL_USART_TX_COMPLETE_CB_ID             = 0x03U,    /*!< USART Tx Complete Callback ID             */
  HAL_USART_RX_HALFBLOCKCOMPLETE_CB_ID    = 0x04U,    /*!< USART Rx Half Block Complete Callback ID  */
  HAL_USART_RX_BLOCKCOMPLETE_CB_ID        = 0x05U,    /*!< USART Rx Block Complete Callback ID       */
  HAL_USART_RX_DSTCOMPLETE_CB_ID          = 0x06U,    /*!< USART Rx Destination Complete Callback ID */
  HAL_USART_RX_COMPLETE_CB_ID             = 0x07U,    /*!< USART Rx Complete Callback ID             */
  HAL_USART_TX_RX_COMPLETE_CB_ID          = 0x08U,    /*!< USART Tx Rx Complete Callback ID          */
  HAL_USART_ERROR_CB_ID                   = 0x09U,    /*!< USART Error Callback ID                   */
  HAL_USART_ABORT_COMPLETE_CB_ID          = 0x0AU,    /*!< USART Abort Complete Callback ID          */
  HAL_USART_RX_FIFO_FULL_CB_ID            = 0x0BU,    /*!< USART Rx Fifo Full Callback ID            */
  HAL_USART_TX_FIFO_EMPTY_CB_ID           = 0x0CU,    /*!< USART Tx Fifo Empty Callback ID           */

  HAL_USART_MSPINIT_CB_ID                 = 0x0DU,    /*!< USART MspInit callback ID                 */
  HAL_USART_MSPDEINIT_CB_ID               = 0x0EU     /*!< USART MspDeInit callback ID               */

} HAL_USART_CallbackIDTypeDef;

/**
  * @brief  HAL USART Callback pointer definition
  */
typedef  void (*pUSART_CallbackTypeDef)(USART_HandleTypeDef *husart);  /*!< pointer to an USART callback function */

#endif /* USE_HAL_USART_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup USART_Exported_Constants USART Exported Constants
  * @{
  */

/** @defgroup USART_Error_Definition   USART Error Definition
  * @{
  */
#define HAL_USART_ERROR_NONE             (0x00000000U)    /*!< No error                  */
#define HAL_USART_ERROR_PE               (0x00000001U)    /*!< Parity error              */
#define HAL_USART_ERROR_NE               (0x00000002U)    /*!< Noise error               */
#define HAL_USART_ERROR_FE               (0x00000004U)    /*!< Frame error               */
#define HAL_USART_ERROR_ORE              (0x00000008U)    /*!< Overrun error             */
#define HAL_USART_ERROR_DMA              (0x00000010U)    /*!< DMA transfer error        */
#define HAL_USART_ERROR_UDR              (0x00000020U)    /*!< SPI slave underrun error  */
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
#define HAL_USART_ERROR_INVALID_CALLBACK (0x00000040U)    /*!< Invalid Callback error    */
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */
#define  HAL_USART_ERROR_RTO              (0x00000080U)    /*!< Receiver Timeout error  */
/**
  * @}
  */

/** @defgroup USART_Stop_Bits  USART Number of Stop Bits
  * @{
  */
#define USART_STOPBITS_0_5                   USART_CR2_STOP_0                     /*!< USART frame with 0.5 stop bit  */
#define USART_STOPBITS_1                     0x00000000U                          /*!< USART frame with 1 stop bit    */
#define USART_STOPBITS_1_5                  (USART_CR2_STOP_0 | USART_CR2_STOP_1) /*!< USART frame with 1.5 stop bits */
#define USART_STOPBITS_2                     USART_CR2_STOP_1                     /*!< USART frame with 2 stop bits   */
/**
  * @}
  */

/** @defgroup USART_Parity    USART Parity
  * @{
  */
#define USART_PARITY_NONE                   0x00000000U                      /*!< No parity   */
#define USART_PARITY_EVEN                   USART_CR1_PCE                    /*!< Even parity */
#define USART_PARITY_ODD                    (USART_CR1_PCE | USART_CR1_PS)   /*!< Odd parity  */
/**
  * @}
  */

/** @defgroup USART_Mode   USART Mode
  * @{
  */
#define USART_MODE_RX                       USART_CR1_RE                    /*!< RX mode        */
#define USART_MODE_TX                       USART_CR1_TE                    /*!< TX mode        */
#define USART_MODE_TX_RX                    (USART_CR1_TE |USART_CR1_RE)    /*!< RX and TX mode */
/**
  * @}
  */

/** @defgroup USART_Clock  USART Clock
  * @{
  */
#define USART_CLOCK_DISABLE                 0x00000000U       /*!< USART clock disable */
#define USART_CLOCK_ENABLE                  USART_CR2_CLKEN   /*!< USART clock enable  */
/**
  * @}
  */

/** @defgroup USART_Clock_Polarity  USART Clock Polarity
  * @{
  */
#define USART_POLARITY_LOW                  0x00000000U      /*!< Driver enable signal is active high */
#define USART_POLARITY_HIGH                 USART_CR2_CPOL   /*!< Driver enable signal is active low  */
/**
  * @}
  */

/** @defgroup USART_Clock_Phase   USART Clock Phase
  * @{
  */
#define USART_PHASE_1EDGE                   0x00000000U      /*!< USART frame phase on first clock transition  */
#define USART_PHASE_2EDGE                   USART_CR2_CPHA   /*!< USART frame phase on second clock transition */
/**
  * @}
  */

/** @defgroup USART_Last_Bit  USART Last Bit
  * @{
  */
#define USART_LASTBIT_DISABLE               0x00000000U      /*!< USART frame last data bit clock pulse not output to SCLK pin */
#define USART_LASTBIT_ENABLE                USART_CR2_LBCL   /*!< USART frame last data bit clock pulse output to SCLK pin     */
/**
  * @}
  */

/** @defgroup USART_Request_Parameters  USART Request Parameters
  * @{
  */
#define USART_RXDATA_FLUSH_REQUEST        USART_CR1_RXFRQ        /*!< Receive Data flush Request  */
#define USART_TXDATA_FLUSH_REQUEST        USART_CR1_TXFRQ        /*!< Transmit data flush Request */
/**
  * @}
  */

/** @defgroup USART_Flags      USART Flags
  *        Elements values convention: 0xXXXX
  *           - 0xXXXX  : Flag mask in the ISR register
  * @{
  */
#define USART_FLAG_RTOF                     USART_SR_RTOF          /*!< USART receiver timeout flag                */
#define USART_FLAG_EOBF                     USART_SR_EOBF          /*!< USART block end flag                       */
#define USART_FLAG_RXFF                     USART_SR_RXFF          /*!< USART RXFIFO Full flag                     */
#define USART_FLAG_TXFE                     USART_SR_TXFE          /*!< USART TXFIFO Empty flag                    */
#define USART_FLAG_TXFT                     USART_SR_TXFT          /*!< USART TXFIFO threshold flag                */
#define USART_FLAG_RXFT                     USART_SR_RXFT          /*!< USART RXFIFO threshold flag                */
#define USART_FLAG_ABRRQ                    USART_SR_ABRRQ         /*!< USART auto BRR request flag                */
#define USART_FLAG_ABRE                     USART_SR_ABRE          /*!< USART auto BRR error flag                  */
#define USART_FLAG_ABRF                     USART_SR_ABRF          /*!< USART auto BRR detection flag              */
#define USART_FLAG_CTS                      USART_SR_CTS           /*!< USART CTS flag                             */
#define USART_FLAG_LBD                      USART_SR_LBD           /*!< USART LIN break detection flag             */
#define USART_FLAG_TXE                      USART_SR_TXE           /*!< USART transmit data register empty         */
#define USART_FLAG_TC                       USART_SR_TC            /*!< USART transmission complete                */
#define USART_FLAG_RXNE                     USART_SR_RXNE          /*!< USART read data register not empty         */
#define USART_FLAG_IDLE                     USART_SR_IDLE          /*!< USART idle flag                            */
#define USART_FLAG_ORE                      USART_SR_ORE           /*!< USART overrun error                        */
#define USART_FLAG_NE                       USART_SR_NE            /*!< USART noise error                          */
#define USART_FLAG_FE                       USART_SR_FE            /*!< USART frame error                          */
#define USART_FLAG_PE                       USART_SR_PE            /*!< USART parity error                         */
/**
  * @}
  */
/** @defgroup USART_Private_Constants USART Private Constants
  * @{
  */
/** @brief USART interruptions flag mask
  *
  */
#define USART_IT_MASK                     0x0000001FU

#define USART_CR1_REG_INDEX               1U
#define USART_CR2_REG_INDEX               2U
#define USART_CR3_REG_INDEX               3U
/**
  * @}
  */
/** @defgroup USART_Interrupt_definition USART Interrupts Definition
  *        Elements values convention: 000ZZZZZ0XXYYYYYb
  *           - YYYYY  : Interrupt source position in the XX register (5bits)
  *           - XX  : Interrupt source register (2bits)
  *                 - 01: CR1 register
  *                 - 10: CR2 register
  *                 - 11: CR3 register
  *           - ZZZZZ  : Flag position in the ISR register(5bits)
  *        Elements values convention: 000000000XXYYYYYb
  *           - YYYYY  : Interrupt source position in the XX register (5bits)
  *           - XX  : Interrupt source register (2bits)
  *                 - 01: CR1 register
  *                 - 10: CR2 register
  *                 - 11: CR3 register
  *        Elements values convention: 0000ZZZZ00000000b
  *           - ZZZZ  : Flag position in the ISR register(4bits)
  * @{
  */

#define USART_IT_PE                          0x0028U  /*!< USART parity error interruption                 */
#define USART_IT_TXE                         0x0727U  /*!< USART transmit data register empty interruption */
#define USART_IT_TC                          0x0626U  /*!< USART transmission complete interruption        */
#define USART_IT_RXNE                        0x0525U  /*!< USART read data register not empty interruption */
#define USART_IT_IDLE                        0x0424U  /*!< USART idle interruption                         */
#define USART_IT_LBD                         0x0846U  /*!< USART LBD interruption                          */
#define USART_IT_EOB                         0x127EU  /*!< USART EOB interruption                          */
#define USART_IT_RTO                         0x137DU  /*!< USART RTO interruption                          */
#define USART_IT_RXFF                        0x0F6FU  /*!< USART RXFIFO full interruption                  */
#define USART_IT_TXFE                        0x1070U  /*!< USART TXFIFO empty interruption                 */
#define USART_IT_RXFT                        0x0E71U  /*!< USART RXFIFO threshold reached interruption     */
#define USART_IT_TXFT                        0x0D72U  /*!< USART TXFIFO threshold reached interruption     */
#define USART_IT_CTS                         0x096AU  /*!< USART fCTS interruption                         */

#define USART_IT_ERR                         0x0060U  /*!< USART error interruption                        */
#define USART_IT_ORE                         0x0300U  /*!< USART overrun error interruption                */
#define USART_IT_NE                          0x0200U  /*!< USART noise error interruption                  */
#define USART_IT_FE                          0x0100U  /*!< USART frame error interruption                  */

/**
  * @}
  */

/**
  * @}
  */
 
/* Exported macros -----------------------------------------------------------*/
/** @defgroup USART_Exported_Macros USART Exported Macros
  * @{
  */

/** @brief Reset USART handle state.
  * @param  __HANDLE__ USART handle.
  * @retval None
  */
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
#define __HAL_USART_RESET_HANDLE_STATE(__HANDLE__)  do{                                            \
                                                        (__HANDLE__)->State = HAL_USART_STATE_RESET; \
                                                        (__HANDLE__)->MspInitCallback = NULL;        \
                                                        (__HANDLE__)->MspDeInitCallback = NULL;      \
                                                      } while(0U)
#else
#define __HAL_USART_RESET_HANDLE_STATE(__HANDLE__)  ((__HANDLE__)->State = HAL_USART_STATE_RESET)
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */

/** @brief  Flushes the USART DR register
  * @param  __HANDLE__ specifies the USART Handle.
  *         USART Handle selects the USARTx or USARTy peripheral
  *         (USART,USART availability and x,y values depending on device).
  */
#define __HAL_USART_FLUSH_DRREGISTER(__HANDLE__) ((__HANDLE__)->Instance->DR)

/** @brief  Clears the specified USART pending flag.
  * @param  __HANDLE__ specifies the USART Handle.
  *         USART Handle selects the USARTx or USARTy peripheral
  *         (USART,USART availability and x,y values depending on device).
  * @param  __FLAG__ specifies the flag to check.
  *          This parameter can be any combination of the following values:
  *            @arg USART_FLAG_LBD:  LIN Break detection flag.
  *            @arg USART_FLAG_TC:   Transmission Complete flag.
  *            @arg USART_FLAG_RXNE: Receive data register not empty flag.
  *
  * @note   PE (Parity error), FE (Framing error), NE (Noise error), ORE (Overrun
  *          error) and IDLE (Idle line detected) flags are cleared by software
  *          sequence: a read operation to USART_SR register followed by a read
  *          operation to USART_DR register.
  * @note   RXNE flag can be also cleared by a read to the USART_DR register.
  * @note   TC flag can be also cleared by software sequence: a read operation to
  *          USART_SR register followed by a write operation to USART_DR register.
  * @note   TXE flag is cleared only by a write to the USART_DR register.
  *
  * @retval None
  */
#define __HAL_USART_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/** @brief  Clear the USART EOB pending flag.
  * @param  __HANDLE__ specifies the USART Handle.
  * @retval None
  */
#define __HAL_USART_CLEAR_EOBFLAG(__HANDLE__) ((__HANDLE__)->Instance->SR &= (~USART_SR_EOBF))

/** @brief  Clear the USART RTOF pending flag.
  * @param  __HANDLE__ specifies the USART Handle.
  * @retval None
  */
#define __HAL_USART_CLEAR_RTOFLAG(__HANDLE__) ((__HANDLE__)->Instance->SR &= (~USART_SR_RTOF))

/** @brief  Clears the USART PE pending flag.
  * @param  __HANDLE__ specifies the USART Handle.
  *         USART Handle selects the USARTx or USARTy peripheral
  *         (USART,USART availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_USART_CLEAR_PEFLAG(__HANDLE__)    \
  do{                                           \
    __IO uint32_t tmpreg = 0x00U;               \
    tmpreg = (__HANDLE__)->Instance->SR;        \
    tmpreg = (__HANDLE__)->Instance->DR;        \
    UNUSED(tmpreg);                             \
  } while(0U)

/** @brief  Clears the USART FE pending flag.
  * @param  __HANDLE__ specifies the USART Handle.
  *         USART Handle selects the USARTx or USARTy peripheral
  *         (USART,USART availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_USART_CLEAR_FEFLAG(__HANDLE__) __HAL_USART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clears the USART NE pending flag.
  * @param  __HANDLE__ specifies the USART Handle.
  *         USART Handle selects the USARTx or USARTy peripheral
  *         (USART,USART availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_USART_CLEAR_NEFLAG(__HANDLE__) __HAL_USART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clears the USART ORE pending flag.
  * @param  __HANDLE__ specifies the USART Handle.
  *         USART Handle selects the USARTx or USARTy peripheral
  *         (USART,USART availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_USART_CLEAR_OREFLAG(__HANDLE__) __HAL_USART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clears the USART IDLE pending flag.
  * @param  __HANDLE__ specifies the USART Handle.
  *         USART Handle selects the USARTx or USARTy peripheral
  *         (USART,USART availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_USART_CLEAR_IDLEFLAG(__HANDLE__) __HAL_USART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Check whether the specified USART flag is set or not.
  * @param  __HANDLE__ specifies the USART Handle
  * @param  __FLAG__ specifies the flag to check.
  *        This parameter can be one of the following values:
  *            @arg @ref USART_FLAG_RTOF   Receiver timeout flag
  *            @arg @ref USART_FLAG_EOBF   Block end flag
  *            @arg @ref USART_FLAG_RXFF   RXFIFO Full flag
  *            @arg @ref USART_FLAG_TXFE   TXFIFO Empty flag
  *            @arg @ref USART_FLAG_TXFT   TXFIFO threshold flag
  *            @arg @ref USART_FLAG_RXFT   RXFIFO threshold flag
  *            @arg @ref USART_FLAG_ABRRQ  Auto BRR request flag
  *            @arg @ref USART_FLAG_ABRE   Auto BRR error flag
  *            @arg @ref USART_FLAG_ABRF   Auto BRR detection flag
  *            @arg @ref USART_FLAG_CTS    CTS flag
  *            @arg @ref USART_FLAG_LBD    LIN break detection flag
  *            @arg @ref USART_FLAG_TXE    Transmit data register empty flag
  *            @arg @ref USART_FLAG_TC     Transmission complete flag
  *            @arg @ref USART_FLAG_RXNE   Read data register not empty flag
  *            @arg @ref USART_FLAG_IDLE   IDLE flag
  *            @arg @ref USART_FLAG_ORE    Overrun error flag
  *            @arg @ref USART_FLAG_NE     Noising Error flag
  *            @arg @ref USART_FLAG_FE     Framing Error flag
  *            @arg @ref USART_FLAG_PE     Parity Error flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_USART_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))

/** @brief  Enable the specified USART interrupt.
  * @param  __HANDLE__ specifies the USART Handle.
  * @param  __INTERRUPT__ specifies the USART interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg @ref USART_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref USART_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref USART_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref USART_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref USART_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref USART_IT_TC    Transmission complete interrupt
  *            @arg @ref USART_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref USART_IT_IDLE  Idle line detection interrupt
  *            @arg @ref USART_IT_PE    Parity Error interrupt
  *            @arg @ref USART_IT_ERR   Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_USART_ENABLE_IT(__HANDLE__, __INTERRUPT__)  ( \
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == USART_CR1_REG_INDEX)?((__HANDLE__)->Instance->CR1 |= (1U << ((__INTERRUPT__) & USART_IT_MASK))): \
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == USART_CR2_REG_INDEX)?((__HANDLE__)->Instance->CR2 |= (1U << ((__INTERRUPT__) & USART_IT_MASK))): \
                                                           ((__HANDLE__)->Instance->CR3 |= (1U << ((__INTERRUPT__) & USART_IT_MASK))))

/** @brief  Disable the specified USART interrupt.
  * @param  __HANDLE__ specifies the USART Handle.
  * @param  __INTERRUPT__ specifies the USART interrupt source to disable.
  *          This parameter can be one of the following values:
  *            @arg @ref USART_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref USART_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref USART_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref USART_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref USART_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref USART_IT_TC    Transmission complete interrupt
  *            @arg @ref USART_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref USART_IT_IDLE  Idle line detection interrupt
  *            @arg @ref USART_IT_PE    Parity Error interrupt
  *            @arg @ref USART_IT_ERR   Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_USART_DISABLE_IT(__HANDLE__, __INTERRUPT__) ( \
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == USART_CR1_REG_INDEX)?((__HANDLE__)->Instance->CR1 &= ~(1U << ((__INTERRUPT__) & USART_IT_MASK))): \
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == USART_CR2_REG_INDEX)?((__HANDLE__)->Instance->CR2 &= ~(1U << ((__INTERRUPT__) & USART_IT_MASK))): \
                                                           ((__HANDLE__)->Instance->CR3 &= ~(1U << ((__INTERRUPT__) & USART_IT_MASK))))

/** @brief  Check whether the specified USART interrupt has occurred or not.
  * @param  __HANDLE__ specifies the USART Handle.
  * @param  __INTERRUPT__ specifies the USART interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg @ref USART_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref USART_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref USART_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref USART_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref USART_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref USART_IT_TC    Transmission complete interrupt
  *            @arg @ref USART_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref USART_IT_IDLE  Idle line detection interrupt
  *            @arg @ref USART_IT_PE    Parity Error interrupt
  *            @arg @ref USART_IT_ERR   Error interrupt(Frame error, noise error, overrun error)
  * @retval The new state of __INTERRUPT__ (SET or RESET).
  */
#define __HAL_USART_GET_IT(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->SR & (1U << ((__INTERRUPT__)>> 8U))) != RESET) ? SET : RESET)

/** @brief  Check whether the specified USART interrupt source is enabled or not.
  * @param  __HANDLE__ specifies the USART Handle.
  * @param  __INTERRUPT__ specifies the USART interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg @ref USART_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref USART_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref USART_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref USART_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref USART_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref USART_IT_TC    Transmission complete interrupt
  *            @arg @ref USART_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref USART_IT_IDLE  Idle line detection interrupt
  *            @arg @ref USART_IT_PE    Parity Error interrupt
  *            @arg @ref USART_IT_ERR   Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_USART_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((((((uint8_t)(__INTERRUPT__)) >> 5U) == USART_CR1_REG_INDEX) ? (__HANDLE__)->Instance->CR1 : \
                                                                (((((uint8_t)(__INTERRUPT__)) >> 5U) == USART_CR2_REG_INDEX) ? (__HANDLE__)->Instance->CR2 : \
                                                                (__HANDLE__)->Instance->CR3)) & (1U << (((uint16_t)(__INTERRUPT__)) & USART_IT_MASK))) != RESET) ? SET : RESET)

/** @brief  Set a specific USART request flag.
  * @param  __HANDLE__ specifies the USART Handle.
  * @param  __REQ__ specifies the request flag to set.
  *          This parameter can be one of the following values:
  *            @arg @ref USART_RXDATA_FLUSH_REQUEST Receive Data flush Request
  *            @arg @ref USART_TXDATA_FLUSH_REQUEST Transmit data flush Request
  *
  * @retval None
  */
#define __HAL_USART_SEND_REQ(__HANDLE__, __REQ__)      ((__HANDLE__)->Instance->CR1 |= (uint16_t)(__REQ__))

/** @brief  Enable USART.
  * @param  __HANDLE__ specifies the USART Handle.
  * @retval None
  */
#define __HAL_USART_ENABLE(__HANDLE__)                 ((__HANDLE__)->Instance->CR1 |= USART_CR1_UE)

/** @brief  Disable USART.
  * @param  __HANDLE__ specifies the USART Handle.
  * @retval None
  */
#define __HAL_USART_DISABLE(__HANDLE__)                ((__HANDLE__)->Instance->CR1 &= ~USART_CR1_UE)

/**
  * @}
  */

/* Private macros --------------------------------------------------------*/
/** @defgroup USART_Private_Macros   USART Private Macros
  * @{
  */

/** @brief  Report the USART clock source.
  * @param  __HANDLE__ specifies the USART Handle.
  * @param  __CLOCKSOURCE__ output variable.
  * @retval the USART clocking source, written in __CLOCKSOURCE__.
  */
#define USART_GETCLOCKSOURCE(__HANDLE__,__CLOCKSOURCE__)       \
  do {                                                         \
    if((__HANDLE__)->Instance == USART1)                       \
    {                                                          \
      switch(__HAL_RCC_GET_USART1_SOURCE())                    \
      {                                                        \
        case RCC_USART1CLKSOURCE_PCLK2:                        \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_PCLK2;         \
          break;                                               \
        case RCC_USART1CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_HSI;           \
          break;                                               \
        case RCC_USART1CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_SYSCLK;        \
          break;                                               \
        case RCC_USART1CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_LSE;           \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_UNDEFINED;     \
          break;                                               \
      }                                                        \
    }                                                          \
    else if((__HANDLE__)->Instance == USART2)                  \
    {                                                          \
      switch(__HAL_RCC_GET_USART2_SOURCE())                    \
      {                                                        \
        case RCC_USART2CLKSOURCE_PCLK1:                        \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_PCLK1;         \
          break;                                               \
        case RCC_USART2CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_HSI;           \
          break;                                               \
        case RCC_USART2CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_SYSCLK;        \
          break;                                               \
        case RCC_USART2CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_LSE;           \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_UNDEFINED;     \
          break;                                               \
      }                                                        \
    }                                                          \
    else if((__HANDLE__)->Instance == USART3)                  \
    {                                                          \
      switch(__HAL_RCC_GET_USART3_SOURCE())                    \
      {                                                        \
        case RCC_USART3CLKSOURCE_PCLK1:                        \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_PCLK1;         \
          break;                                               \
        case RCC_USART3CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_HSI;           \
          break;                                               \
        case RCC_USART3CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_SYSCLK;        \
          break;                                               \
        case RCC_USART3CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_LSE;           \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = USART_CLOCKSOURCE_UNDEFINED;     \
          break;                                               \
      }                                                        \
    }                                                          \
    else                                                       \
    {                                                          \
      (__CLOCKSOURCE__) = USART_CLOCKSOURCE_UNDEFINED;         \
    }                                                          \
  } while(0)

/** @brief  Check USART Baud rate.
  * @param  __BAUDRATE__ Baudrate specified by the user.
  *         The maximum Baud Rate is derived from the maximum clock on E4
  *         divided by the smallest oversampling used on the USART (i.e. 8)
  * @retval SET (__BAUDRATE__ is valid) or RESET (__BAUDRATE__ is invalid)  */
#define IS_USART_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) <= 4500000U)

/**
  * @brief Ensure that USART frame number of stop bits is valid.
  * @param __STOPBITS__ USART frame number of stop bits.
  * @retval SET (__STOPBITS__ is valid) or RESET (__STOPBITS__ is invalid)
  */
#define IS_USART_STOPBITS(__STOPBITS__) (((__STOPBITS__) == USART_STOPBITS_0_5) || \
                                         ((__STOPBITS__) == USART_STOPBITS_1)   || \
                                         ((__STOPBITS__) == USART_STOPBITS_1_5) || \
                                         ((__STOPBITS__) == USART_STOPBITS_2))
/**
  * @brief Ensure that USART frame parity is valid.
  * @param __PARITY__ USART frame parity.
  * @retval SET (__PARITY__ is valid) or RESET (__PARITY__ is invalid)
  */
#define IS_USART_PARITY(__PARITY__) (((__PARITY__) == USART_PARITY_NONE) || \
                                     ((__PARITY__) == USART_PARITY_EVEN) || \
                                     ((__PARITY__) == USART_PARITY_ODD))

/**
  * @brief Ensure that USART communication mode is valid.
  * @param __MODE__ USART communication mode.
  * @retval SET (__MODE__ is valid) or RESET (__MODE__ is invalid)
  */
#define IS_USART_MODE(__MODE__) ((((__MODE__) & 0xFFFFFFF3U) == 0x00U) && ((__MODE__) != 0x00U))

/**
  * @brief Ensure that USART clock state is valid.
  * @param __CLOCK__ USART clock state.
  * @retval SET (__CLOCK__ is valid) or RESET (__CLOCK__ is invalid)
  */
#define IS_USART_CLOCK(__CLOCK__) (((__CLOCK__) == USART_CLOCK_DISABLE) || \
                                   ((__CLOCK__) == USART_CLOCK_ENABLE))

/**
  * @brief Ensure that USART frame polarity is valid.
  * @param __CPOL__ USART frame polarity.
  * @retval SET (__CPOL__ is valid) or RESET (__CPOL__ is invalid)
  */
#define IS_USART_POLARITY(__CPOL__) (((__CPOL__) == USART_POLARITY_LOW) || ((__CPOL__) == USART_POLARITY_HIGH))

/**
  * @brief Ensure that USART frame phase is valid.
  * @param __CPHA__ USART frame phase.
  * @retval SET (__CPHA__ is valid) or RESET (__CPHA__ is invalid)
  */
#define IS_USART_PHASE(__CPHA__) (((__CPHA__) == USART_PHASE_1EDGE) || ((__CPHA__) == USART_PHASE_2EDGE))

/**
  * @brief Ensure that USART frame last bit clock pulse setting is valid.
  * @param __LASTBIT__ USART frame last bit clock pulse setting.
  * @retval SET (__LASTBIT__ is valid) or RESET (__LASTBIT__ is invalid)
  */
#define IS_USART_LASTBIT(__LASTBIT__) (((__LASTBIT__) == USART_LASTBIT_DISABLE) || \
                                       ((__LASTBIT__) == USART_LASTBIT_ENABLE))

/**
  * @brief Ensure that USART request parameter is valid.
  * @param __PARAM__ USART request parameter.
  * @retval SET (__PARAM__ is valid) or RESET (__PARAM__ is invalid)
  */
#define IS_USART_REQUEST_PARAMETER(__PARAM__) (((__PARAM__) == USART_RXDATA_FLUSH_REQUEST) || \
                                               ((__PARAM__) == USART_TXDATA_FLUSH_REQUEST))

#define USART_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))
#define USART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (USART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define USART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        (((USART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (USART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U + 50U) / 100U)
/* USART BRR = mantissa + overflow + fraction
             = (USART DIVMANT << 4) + (USART DIVFRAQ & 0xF0) + (USART DIVFRAQ & 0x0FU) */
#define USART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((USART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                        (USART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (USART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

#define USART_DIV_SAMPLING8(_PCLK_, _BAUD_)             (((_PCLK_)*25U)/(2U*(_BAUD_)))
#define USART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (USART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
#define USART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         (((USART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (USART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U + 50U) / 100U)
/* USART BRR = mantissa + overflow + fraction
             = (USART DIVMANT << 4) + ((USART DIVFRAQ & 0xF8) << 1) + (USART DIVFRAQ & 0x07U) */
#define USART_BRR_SAMPLING8(_PCLK_, _BAUD_)             (((USART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                        ((USART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U)) + \
                                                        (USART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))

/**
  * @}
  */

/* Include USART HAL Extended module */
#include "py32e407_hal_usart_ex.h"

/* Exported functions --------------------------------------------------------*/
/** @addtogroup USART_Exported_Functions USART Exported Functions
  * @{
  */
/** @addtogroup USART_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */

/* Initialization and de-initialization functions  ****************************/
HAL_StatusTypeDef HAL_USART_Init(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_DeInit(USART_HandleTypeDef *husart);
void HAL_USART_MspInit(USART_HandleTypeDef *husart);
void HAL_USART_MspDeInit(USART_HandleTypeDef *husart);

/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_USART_RegisterCallback(USART_HandleTypeDef *husart, HAL_USART_CallbackIDTypeDef CallbackID,
                                             pUSART_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_USART_UnRegisterCallback(USART_HandleTypeDef *husart, HAL_USART_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_USART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup USART_Exported_Functions_Group2 IO operation functions
  * @{
  */

/* IO operation functions *****************************************************/
HAL_StatusTypeDef HAL_USART_Transmit(USART_HandleTypeDef *husart, uint8_t *pTxData, uint32_t Size,
                                     uint32_t Timeout);
HAL_StatusTypeDef HAL_USART_Receive(USART_HandleTypeDef *husart, uint8_t *pRxData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_USART_TransmitReceive(USART_HandleTypeDef *husart, uint8_t *pTxData, uint8_t *pRxData,
                                            uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_USART_Transmit_IT(USART_HandleTypeDef *husart, uint8_t *pTxData, uint32_t Size);
HAL_StatusTypeDef HAL_USART_Receive_IT(USART_HandleTypeDef *husart, uint8_t *pRxData, uint32_t Size);
HAL_StatusTypeDef HAL_USART_TransmitReceive_IT(USART_HandleTypeDef *husart, uint8_t *pTxData, uint8_t *pRxData,
                                               uint32_t Size);
HAL_StatusTypeDef HAL_USART_Transmit_DMA(USART_HandleTypeDef *husart, uint8_t *pTxData, uint32_t Size);
HAL_StatusTypeDef HAL_USART_Receive_DMA(USART_HandleTypeDef *husart, uint8_t *pRxData, uint32_t Size);
HAL_StatusTypeDef HAL_USART_TransmitReceive_DMA(USART_HandleTypeDef *husart, uint8_t *pTxData, uint8_t *pRxData,
                                                uint32_t Size);
HAL_StatusTypeDef HAL_USART_DMAPause(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_DMAResume(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_DMAStop(USART_HandleTypeDef *husart);
/* Transfer Abort functions */
HAL_StatusTypeDef HAL_USART_Abort(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_Abort_IT(USART_HandleTypeDef *husart);

void HAL_USART_IRQHandler(USART_HandleTypeDef *husart);
void HAL_USART_TxSrcCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_TxBlockCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_TxHalfBlockCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_TxCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_RxCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_RxDstCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_RxBlockCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_RxHalfBlockCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_TxRxCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_ErrorCallback(USART_HandleTypeDef *husart);
void HAL_USART_AbortCpltCallback(USART_HandleTypeDef *husart);
/**
  * @}
  */

/** @addtogroup USART_Exported_Functions_Group3 Peripheral State and Error functions
  * @{
  */

/* Peripheral State and Error functions ***************************************/
HAL_USART_StateTypeDef HAL_USART_GetState(USART_HandleTypeDef *husart);
uint32_t               HAL_USART_GetError(USART_HandleTypeDef *husart);

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

#endif /* __PY32E407_HAL_USART_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
