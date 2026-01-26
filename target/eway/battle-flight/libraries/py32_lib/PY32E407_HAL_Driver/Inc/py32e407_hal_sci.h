/**
  ******************************************************************************
  * @file    py32e407_hal_sci.h
  * @author  MCU Application Team
  * @brief   Header file of SCI HAL module.
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
#ifndef __PY32E407_HAL_SCI_H
#define __PY32E407_HAL_SCI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup SCI
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup SCI_Exported_Types SCI Exported Types
  * @{
  */

/**
  * @brief SCI Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< This member configures the SCI communication baud rate. */

  uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref SCIEx_Word_Length. */

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref SCI_Stop_Bits. */

  uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref SCI_Parity */

  uint32_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref SCI_Mode. */

  uint32_t HwFlowCtl;                 /*!< Specifies whether the hardware flow control mode is enabled or disabled.
                                           This parameter can be a value of @ref SCI_Hardware_Flow_Control */

  uint32_t OverSampling;              /*!< Specifies whether the Over sampling 8 or Over sampling 16.
                                           This parameter can be a value of @ref SCI_Over_Sampling. */
} SCI_InitTypeDef;

/**
  * @brief  SCI Advanced Features initialization structure definition
  */
typedef struct
{
  uint32_t AdvFeatureInit;        /*!< Specifies which advanced SCI features is initialized. Several
                                       Advanced Features may be initialized at the same time .
                                       This parameter can be a value of
                                       @ref SCI_Advanced_Features_Initialization_Type. */

  uint32_t TxPinLevelInvert;      /*!< Specifies whether the TX pin active level is inverted.
                                       This parameter can be a value of @ref SCI_Tx_Inv. */

  uint32_t RxPinLevelInvert;      /*!< Specifies whether the RX pin active level is inverted.
                                       This parameter can be a value of @ref SCI_Rx_Inv. */

  uint32_t DataInvert;            /*!< Specifies whether data are inverted (positive/direct logic
                                       vs negative/inverted logic).
                                       This parameter can be a value of @ref SCI_Data_Inv. */

  uint32_t Swap;                  /*!< Specifies whether TX and RX pins are swapped.
                                       This parameter can be a value of @ref SCI_Rx_Tx_Swap. */

  uint32_t AutoBaudRateEnable;    /*!< Specifies whether auto Baud rate detection is enabled.
                                       This parameter can be a value of @ref SCI_AutoBaudRate_Enable. */

  uint32_t AutoBaudRateMode;      /*!< If auto Baud rate detection is enabled, specifies how the rate
                                       detection is carried out.
                                       This parameter can be a value of @ref SCI_AutoBaud_Rate_Mode. */

  uint32_t MSBFirst;              /*!< Specifies whether MSB is sent first on SCI line.
                                       This parameter can be a value of @ref SCI_MSB_First. */
} SCI_AdvFeatureInitTypeDef;

/**
  * @brief HAL SCI State structures definition
  * @note  HAL SCI State value is a combination of 2 different substates: gState and RxState.
  *        - gState contains SCI state information related to global Handle management
  *          and also information related to Tx operations.
  *          gState value coding follow below described bitmap :
  *          b7-b6  Error information
  *             00 : No Error
  *             01 : (Not Used)
  *             10 : Timeout
  *             11 : Error
  *          b5     Peripheral initialization status
  *             0  : Reset (Peripheral not initialized)
  *             1  : Init done (Peripheral not initialized. HAL SCI Init function already called)
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
  HAL_SCI_STATE_RESET             = 0x00U,    /*!< Peripheral is not yet Initialized
                                                   Value is allowed for gState and RxState */
  HAL_SCI_STATE_READY             = 0x20U,    /*!< Peripheral Initialized and ready for use
                                                   Value is allowed for gState and RxState */
  HAL_SCI_STATE_BUSY              = 0x24U,    /*!< an internal process is ongoing
                                                   Value is allowed for gState only */
  HAL_SCI_STATE_BUSY_TX           = 0x21U,    /*!< Data Transmission process is ongoing
                                                   Value is allowed for gState only */
  HAL_SCI_STATE_BUSY_RX           = 0x22U,    /*!< Data Reception process is ongoing
                                                   Value is allowed for RxState only */
  HAL_SCI_STATE_BUSY_TX_RX        = 0x23U,    /*!< Data Transmission and Reception process is ongoing
                                                   Not to be used for neither gState nor RxState.
                                                   Value is result of combination (Or) between gState and RxState values */
  HAL_SCI_STATE_TIMEOUT           = 0xA0U,    /*!< Timeout state
                                                   Value is allowed for gState only */
  HAL_SCI_STATE_ERROR             = 0xE0U     /*!< Error
                                                   Value is allowed for gState only */
} HAL_SCI_StateTypeDef;

/**
  * @brief SCI clock sources definition
  */
typedef enum
{
  SCI_CLOCKSOURCE_PCLK1      = 0x00U,    /*!< PCLK1 clock source  */
  SCI_CLOCKSOURCE_PCLK2      = 0x01U,    /*!< PCLK2 clock source  */
  SCI_CLOCKSOURCE_HSI        = 0x02U,    /*!< HSI clock source    */
  SCI_CLOCKSOURCE_SYSCLK     = 0x04U,    /*!< SYSCLK clock source */
  SCI_CLOCKSOURCE_LSE        = 0x08U,    /*!< LSE clock source       */
  SCI_CLOCKSOURCE_UNDEFINED  = 0x10U     /*!< Undefined clock source */
} SCI_ClockSourceTypeDef;

/**
  * @brief HAL SCI Reception type definition
  * @note  HAL SCI Reception type value aims to identify which type of Reception is ongoing.
  *        This parameter can be a value of @ref SCI_Reception_Type_Values :
  *           HAL_SCI_RECEPTION_STANDARD         = 0x00U,
  *           HAL_SCI_RECEPTION_TOIDLE           = 0x01U,
  *           HAL_SCI_RECEPTION_TORTO            = 0x02U,
  *           HAL_SCI_RECEPTION_TOCHARMATCH      = 0x03U,
  */
typedef uint32_t HAL_SCI_RxTypeTypeDef;

/**
  * @brief HAL SCI Rx Event type definition
  * @note  HAL SCI Rx Event type value aims to identify which type of Event has occurred
  *        leading to call of the RxEvent callback.
  *        This parameter can be a value of @ref SCI_RxEvent_Type_Values :
  *           HAL_SCI_RXEVENT_TC                 = 0x00U,
  *           HAL_SCI_RXEVENT_HT                 = 0x01U,
  *           HAL_SCI_RXEVENT_IDLE               = 0x02U,
  */
typedef uint32_t HAL_SCI_RxEventTypeTypeDef;

/**
  * @brief  SCI handle Structure definition
  */
typedef struct __SCI_HandleTypeDef
{
  USART_TypeDef                 *Instance;           /*!< SCI registers base address        */

  SCI_InitTypeDef               Init;                /*!< SCI communication parameters      */

  SCI_AdvFeatureInitTypeDef     AdvancedInit;        /*!< SCI Advanced Features initialization parameters */

  const uint8_t                 *pTxBuffPtr;         /*!< Pointer to SCI Tx transfer Buffer */

  uint32_t                      TxXferSize;          /*!< SCI Tx Transfer size              */

  __IO uint32_t                 TxXferCount;         /*!< SCI Tx Transfer Counter           */

  uint8_t                       *pRxBuffPtr;         /*!< Pointer to SCI Rx transfer Buffer */

  uint32_t                      RxXferSize;          /*!< SCI Rx Transfer size              */

  __IO uint32_t                 RxXferCount;         /*!< SCI Rx Transfer Counter           */

  uint16_t                      Mask;                /*!< SCI Rx RDR register mask          */

  uint32_t                      FifoMode;            /*!< Specifies if the FIFO mode will be used. This parameter can be a value
                                                          of @ref SCIEx_FIFO_mode. */

  uint32_t                      NbRxDataToProcess;   /*!< Number of data to process during RX SR execution */

  uint32_t                      NbTxDataToProcess;   /*!< Number of data to process during TX SR execution */

  __IO HAL_SCI_RxTypeTypeDef    ReceptionType;       /*!< Type of ongoing reception          */

  __IO HAL_SCI_RxEventTypeTypeDef RxEventType;       /*!< Type of Rx Event                   */

  void (*RxISR)(struct __SCI_HandleTypeDef *hsci);   /*!< Function pointer on Rx IRQ handler */

  void (*TxISR)(struct __SCI_HandleTypeDef *hsci);   /*!< Function pointer on Tx IRQ handler  */

  DMA_HandleTypeDef             *hdmatx;             /*!< SCI Tx DMA Handle parameters      */

  DMA_HandleTypeDef             *hdmarx;             /*!< SCI Rx DMA Handle parameters      */

  HAL_LockTypeDef               Lock;                /*!< Locking object                      */

  __IO HAL_SCI_StateTypeDef     gState;              /*!< SCI communication state           */

  __IO HAL_SCI_StateTypeDef     RxState;             /*!< SCI state information related to Rx operations.
                                                          This parameter can be a value of @ref HAL_SCI_StateTypeDef */

  __IO uint32_t                 ErrorCode;           /*!< SCI Error code                    */

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
  void (* TxBlockCpltCallback)(struct __SCI_HandleTypeDef *hsci);       /*!< SCI Tx Block Complete Callback       */
  void (* TxHalfBlockCpltCallback)(struct __SCI_HandleTypeDef *hsci);   /*!< SCI Tx Half Block Complete Callback  */
  void (* TxSrcCpltCallback)(struct __SCI_HandleTypeDef *hsci);         /*!< SCI Tx Source Complete Callback      */
  void (* TxCpltCallback)(struct __SCI_HandleTypeDef *hsci);            /*!< SCI Tx Complete Callback             */
  void (* RxBlockCpltCallback)(struct __SCI_HandleTypeDef *hsci);       /*!< SCI Rx Block Complete Callback       */
  void (* RxHalfBlockCpltCallback)(struct __SCI_HandleTypeDef *hsci);   /*!< SCI Rx Half Block Complete Callback  */
  void (* RxDstCpltCallback)(struct __SCI_HandleTypeDef *hsci);         /*!< SCI Rx Destination Complete Callback */
  void (* RxCpltCallback)(struct __SCI_HandleTypeDef *hsci);            /*!< SCI Rx Complete Callback             */
  void (* ErrorCallback)(struct __SCI_HandleTypeDef *hsci);             /*!< SCI Error Callback                   */
  void (* AbortCpltCallback)(struct __SCI_HandleTypeDef *hsci);         /*!< SCI Abort Complete Callback          */
  void (* AbortTransmitCpltCallback)(struct __SCI_HandleTypeDef *hsci); /*!< SCI Abort Transmit Complete Callback */
  void (* AbortReceiveCpltCallback)(struct __SCI_HandleTypeDef *hsci);  /*!< SCI Abort Receive Complete Callback  */
  void (* WakeupCallback)(struct __SCI_HandleTypeDef *hsci);            /*!< SCI Wakeup Callback                  */
  void (* RxFifoFullCallback)(struct __SCI_HandleTypeDef *hsci);       /*!< SCI Rx Fifo Full Callback            */
  void (* TxFifoEmptyCallback)(struct __SCI_HandleTypeDef *hsci);      /*!< SCI Tx Fifo Empty Callback           */
  void (* RxEventCallback)(struct __SCI_HandleTypeDef *hsci, uint32_t Pos); /*!< SCI Reception Event Callback     */

  void (* MspInitCallback)(struct __SCI_HandleTypeDef *hsci);           /*!< SCI Msp Init callback                */
  void (* MspDeInitCallback)(struct __SCI_HandleTypeDef *hsci);         /*!< SCI Msp DeInit callback              */
#endif  /* USE_HAL_SCI_REGISTER_CALLBACKS */

} SCI_HandleTypeDef;

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL SCI Callback ID enumeration definition
  */
typedef enum
{
  HAL_SCI_TX_BLOCKCOMPLETE_CB_ID        = 0x00U,    /*!< SCI Tx Block Complete Callback ID       */
  HAL_SCI_TX_HALFBLOCKCOMPLETE_CB_ID    = 0x01U,    /*!< SCI Tx Half Block Complete Callback ID  */
  HAL_SCI_TX_SRCCOMPLETE_CB_ID          = 0x02U,    /*!< SCI Tx Source Complete Callback ID      */
  HAL_SCI_TX_COMPLETE_CB_ID             = 0x03U,    /*!< SCI Tx Complete Callback ID             */
  HAL_SCI_RX_BLOCKCOMPLETE_CB_ID        = 0x04U,    /*!< SCI Rx Block Complete Callback ID       */
  HAL_SCI_RX_HALFBLOCKCOMPLETE_CB_ID    = 0x05U,    /*!< SCI Rx Half Block Complete Callback ID  */
  HAL_SCI_RX_DSTCOMPLETE_CB_ID          = 0x06U,    /*!< SCI Rx Destination Complete Callback ID */
  HAL_SCI_RX_COMPLETE_CB_ID             = 0x07U,    /*!< SCI Rx Complete Callback ID             */
  HAL_SCI_ERROR_CB_ID                   = 0x08U,    /*!< SCI Error Callback ID                   */
  HAL_SCI_ABORT_COMPLETE_CB_ID          = 0x09U,    /*!< SCI Abort Complete Callback ID          */
  HAL_SCI_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x0AU,    /*!< SCI Abort Transmit Complete Callback ID */
  HAL_SCI_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x0BU,    /*!< SCI Abort Receive Complete Callback ID  */
  HAL_SCI_WAKEUP_CB_ID                  = 0x0CU,    /*!< SCI Wakeup Callback ID                  */
  HAL_SCI_RX_FIFO_FULL_CB_ID            = 0x0DU,    /*!< SCI Rx Fifo Full Callback ID            */
  HAL_SCI_TX_FIFO_EMPTY_CB_ID           = 0x0EU,    /*!< SCI Tx Fifo Empty Callback ID           */

  HAL_SCI_MSPINIT_CB_ID                 = 0x0FU,    /*!< SCI MspInit callback ID                 */
  HAL_SCI_MSPDEINIT_CB_ID               = 0x10U     /*!< SCI MspDeInit callback ID               */

} HAL_SCI_CallbackIDTypeDef;

/**
  * @brief  HAL SCI Callback pointer definition
  */
typedef  void (*pSCI_CallbackTypeDef)(SCI_HandleTypeDef *hsci);  /*!< pointer to an SCI callback function */
typedef  void (*pSCI_RxEventCallbackTypeDef)
(struct __SCI_HandleTypeDef *h, uint32_t Pos); /*!< pointer to a SCI Rx Event specific callback function */

#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup SCI_Exported_Constants SCI Exported Constants
  * @{
  */

/** @defgroup SCI_Error_Definition   SCI Error Definition
  * @{
  */
#define HAL_SCI_ERROR_NONE             (0x00000000U)    /*!< No error                  */
#define HAL_SCI_ERROR_PE               (0x00000001U)    /*!< Parity error              */
#define HAL_SCI_ERROR_NE               (0x00000002U)    /*!< Noise error               */
#define HAL_SCI_ERROR_FE               (0x00000004U)    /*!< Frame error               */
#define HAL_SCI_ERROR_ORE              (0x00000008U)    /*!< Overrun error             */
#define HAL_SCI_ERROR_DMA              (0x00000010U)    /*!< DMA transfer error        */
#define HAL_SCI_ERROR_RTO              (0x00000020U)    /*!< Receiver Timeout error  */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
#define HAL_SCI_ERROR_INVALID_CALLBACK (0x00000040U)    /*!< Invalid Callback error    */
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup SCI_Stop_Bits  SCI Number of Stop Bits
  * @{
  */
#define SCI_STOPBITS_0_5                   USART_CR2_STOP_0                     /*!< SCI frame with 0.5 stop bit  */
#define SCI_STOPBITS_1                     0x00000000U                          /*!< SCI frame with 1 stop bit    */
#define SCI_STOPBITS_1_5                  (USART_CR2_STOP_0 | USART_CR2_STOP_1) /*!< SCI frame with 1.5 stop bits */
#define SCI_STOPBITS_2                     USART_CR2_STOP_1                     /*!< SCI frame with 2 stop bits   */
/**
  * @}
  */

/** @defgroup SCI_Parity    SCI Parity
  * @{
  */
#define SCI_PARITY_NONE                    0x00000000U                      /*!< No parity   */
#define SCI_PARITY_EVEN                    USART_CR1_PCE                    /*!< Even parity */
#define SCI_PARITY_ODD                     (USART_CR1_PCE | USART_CR1_PS)   /*!< Odd parity  */
/**
  * @}
  */

/** @defgroup SCI_Hardware_Flow_Control SCI Hardware Flow Control
  * @{
  */
#define SCI_HWCONTROL_NONE                 0x00000000U                       /*!< No hardware control       */
#define SCI_HWCONTROL_RTS                  USART_CR3_RTSE                    /*!< Request To Send           */
#define SCI_HWCONTROL_CTS                  USART_CR3_CTSE                    /*!< Clear To Send             */
#define SCI_HWCONTROL_RTS_CTS              (USART_CR3_RTSE | USART_CR3_CTSE) /*!< Request and Clear To Send */
/**
  * @}
  */

/** @defgroup SCI_Mode   SCI Mode
  * @{
  */
#define SCI_MODE_RX                        USART_CR1_RE                    /*!< RX mode        */
#define SCI_MODE_TX                        USART_CR1_TE                    /*!< TX mode        */
#define SCI_MODE_TX_RX                     (USART_CR1_TE | USART_CR1_RE)   /*!< RX and TX mode */
/**
  * @}
  */

/** @defgroup SCI_State  SCI State
  * @{
  */
#define SCI_STATE_DISABLE                  0x00000000U         /*!< SCI disabled  */
#define SCI_STATE_ENABLE                   USART_CR1_UE        /*!< SCI enabled   */
/**
  * @}
  */

/** @defgroup SCI_Over_Sampling SCI Over Sampling
  * @{
  */
#define SCI_OVERSAMPLING_16                    0x00000000U
#define SCI_OVERSAMPLING_8                     ((uint32_t)USART_CR3_OVER8)

/**
  * @}
  */

/** @defgroup SCI_AutoBaud_Rate_Mode    SCI Advanced Feature AutoBaud Rate Mode
  * @{
  */
#define SCI_ADVFEATURE_AUTOBAUDRATE_ONSTARTBIT    0x00000000U          /*!< Auto Baud rate detection
                                                                            on start bit              */
#define SCI_ADVFEATURE_AUTOBAUDRATE_ONFALLINGEDGE USART_CR3_ABRMOD   /*!< Auto Baud rate detection
                                                                            on falling edge           */
/**
  * @}
  */

/** @defgroup SCI_Receiver_Timeout SCI Receiver Timeout
  * @{
  */
#define SCI_RECEIVER_TIMEOUT_DISABLE       0x00000000U                /*!< SCI Receiver Timeout disable */
#define SCI_RECEIVER_TIMEOUT_ENABLE        USART_CR2_RTOEN            /*!< SCI Receiver Timeout enable  */
/**
  * @}
  */

/** @defgroup SCI_LIN    SCI Local Interconnection Network mode
  * @{
  */
#define SCI_LIN_DISABLE                    0x00000000U                /*!< Local Interconnect Network disable */
#define SCI_LIN_ENABLE                     USART_CR2_LINEN            /*!< Local Interconnect Network enable  */
/**
  * @}
  */

/** @defgroup SCI_LIN_Break_Detection_Length  SCI LIN Break Detection Length
  * @{
  */
#define SCI_LINBREAKDETECTLENGTH_10B      0x00000000U                /*!< LIN 10-bit break detection length */
#define SCI_LINBREAKDETECTLENGTH_11B      USART_CR2_LBDL             /*!< LIN 11-bit break detection length */
/**
  * @}
  */

/** @defgroup SCI_DMA_Tx    SCI DMA Tx
  * @{
  */
#define SCI_DMA_TX_DISABLE                 0x00000000U                /*!< SCI DMA TX disabled */
#define SCI_DMA_TX_ENABLE                  USART_CR3_DMAT             /*!< SCI DMA TX enabled  */
/**
  * @}
  */

/** @defgroup SCI_DMA_Rx   SCI DMA Rx
  * @{
  */
#define SCI_DMA_RX_DISABLE                 0x00000000U                 /*!< SCI DMA RX disabled */
#define SCI_DMA_RX_ENABLE                  USART_CR3_DMAR              /*!< SCI DMA RX enabled  */
/**
  * @}
  */

/** @defgroup SCI_Half_Duplex_Selection  SCI Half Duplex Selection
  * @{
  */
#define SCI_HALF_DUPLEX_DISABLE            0x00000000U                 /*!< SCI half-duplex disabled */
#define SCI_HALF_DUPLEX_ENABLE             USART_CR3_HDSEL             /*!< SCI half-duplex enabled  */
/**
  * @}
  */

/** @defgroup SCI_WakeUp_functions  SCI Wakeup Functions
  * @{
  */
#define SCI_WAKEUPMETHOD_IDLELINE       0x00000000U                   /*!< SCI wake-up on idle line    */
#define SCI_WAKEUPMETHOD_ADDRESSMARK    USART_CR1_WAKE                /*!< SCI wake-up on address mark */
/**
  * @}
  */

/** @defgroup SCI_Request_Parameters  SCI Request Parameters
  * @{
  */
#define SCI_SENDBREAK_REQUEST           USART_CR1_SBK        /*!< Send Break Request          */
#define SCI_RXDATA_FLUSH_REQUEST        USART_CR1_RXFRQ        /*!< Receive Data flush Request  */
#define SCI_TXDATA_FLUSH_REQUEST        USART_CR1_TXFRQ        /*!< Transmit data flush Request */
/**
  * @}
  */

/** @defgroup SCI_Advanced_Features_Initialization_Type  SCI Advanced Feature Initialization Type
  * @{
  */
#define SCI_ADVFEATURE_NO_INIT                 0x00000000U          /*!< No advanced feature initialization       */
#define SCI_ADVFEATURE_TXINVERT_INIT           0x00000001U          /*!< TX pin active level inversion            */
#define SCI_ADVFEATURE_RXINVERT_INIT           0x00000002U          /*!< RX pin active level inversion            */
#define SCI_ADVFEATURE_DATAINVERT_INIT         0x00000004U          /*!< Binary data inversion                    */
#define SCI_ADVFEATURE_SWAP_INIT               0x00000008U          /*!< TX/RX pins swap                          */
#define SCI_ADVFEATURE_AUTOBAUDRATE_INIT       0x00000010U          /*!< Auto Baud rate detection initialization  */
#define SCI_ADVFEATURE_MSBFIRST_INIT           0x00000020U          /*!< Most significant bit sent/received first */
/**
  * @}
  */

/** @defgroup SCI_Tx_Inv SCI Advanced Feature TX Pin Active Level Inversion
  * @{
  */
#define SCI_ADVFEATURE_TXINV_DISABLE       0x00000000U              /*!< TX pin active level inversion disable */
#define SCI_ADVFEATURE_TXINV_ENABLE        USART_CR1_TX_INV         /*!< TX pin active level inversion enable  */
/**
  * @}
  */

/** @defgroup SCI_Rx_Inv SCI Advanced Feature RX Pin Active Level Inversion
  * @{
  */
#define SCI_ADVFEATURE_RXINV_DISABLE       0x00000000U              /*!< RX pin active level inversion disable */
#define SCI_ADVFEATURE_RXINV_ENABLE        USART_CR1_RX_INV         /*!< RX pin active level inversion enable  */
/**
  * @}
  */

/** @defgroup SCI_Data_Inv  SCI Advanced Feature Binary Data Inversion
  * @{
  */
#define SCI_ADVFEATURE_DATAINV_DISABLE     0x00000000U              /*!< Binary data inversion disable */
#define SCI_ADVFEATURE_DATAINV_ENABLE      USART_CR1_DATAINV       /*!< Binary data inversion enable  */
/**
  * @}
  */

/** @defgroup SCI_Rx_Tx_Swap SCI Advanced Feature RX TX Pins Swap
  * @{
  */
#define SCI_ADVFEATURE_SWAP_DISABLE        0x00000000U             /*!< TX/RX pins swap disable */
#define SCI_ADVFEATURE_SWAP_ENABLE         USART_CR1_SWAP          /*!< TX/RX pins swap enable  */
/**
  * @}
  */

/** @defgroup SCI_AutoBaudRate_Enable  SCI Advanced Feature Auto BaudRate Enable
  * @{
  */
#define SCI_ADVFEATURE_AUTOBAUDRATE_DISABLE   0x00000000U          /*!< RX Auto Baud rate detection enable  */
#define SCI_ADVFEATURE_AUTOBAUDRATE_ENABLE    USART_CR3_ABREN      /*!< RX Auto Baud rate detection disable */
/**
  * @}
  */

/** @defgroup SCI_MSB_First  SCI Advanced Feature MSB First
  * @{
  */
#define SCI_ADVFEATURE_MSBFIRST_DISABLE    0x00000000U             /*!< Most significant bit sent/received first disable                      */
#define SCI_ADVFEATURE_MSBFIRST_ENABLE     USART_CR1_MSB           /*!< Most significant bit sent/received first enable                       */
/**
  * @}
  */

/** @defgroup SCI_DriverEnable_Polarity      SCI DriverEnable Polarity
  * @{
  */
#define SCI_DE_POLARITY_HIGH              0x00000000U      /*!< Driver enable signal is active high */
#define SCI_DE_POLARITY_LOW               USART_CR2_DEP    /*!< Driver enable signal is active low  */
/**
  * @}
  */


/** @defgroup SCI_CR3_DEAT_ADDRESS_LSB_POS    SCI Driver Enable Assertion Time LSB Position In CR3 Register
  * @{
  */
#define SCI_CR3_DEAT_ADDRESS_LSB_POS       24U      /*!< SCI Driver Enable assertion time LSB
                                                         position in CR1 register */
/**
  * @}
  */

/** @defgroup SCI_CR1_DEDT_ADDRESS_LSB_POS    SCI Driver Enable DeAssertion Time LSB Position In CR3 Register
  * @{
  */
#define SCI_CR3_DEDT_ADDRESS_LSB_POS       19U      /*!< SCI Driver Enable de-assertion time LSB
                                                         position in CR1 register */
/**
  * @}
  */

/** @defgroup SCI_Interruption_Mask    SCI Interruptions Flag Mask
  * @{
  */
#define SCI_IT_MASK                        0x001FU  /*!< SCI interruptions flags mask */
/**
  * @}
  */

/** @defgroup SCI_TimeOut_Value    SCI polling-based communications time-out value
  * @{
  */
#define HAL_SCI_TIMEOUT_VALUE              0x1FFFFFFU  /*!< SCI polling-based communications time-out value */
/**
  * @}
  */

/** @defgroup SCI_Flags      SCI Flags
  *        Elements values convention: 0xXXXX
  *           - 0xXXXX  : Flag mask in the SR register
  * @{
  */
#define SCI_FLAG_RTOF                     USART_SR_RTOF          /*!< SCI receiver timeout flag                */
#define SCI_FLAG_EOBF                     USART_SR_EOBF          /*!< SCI block end flag                       */
#define SCI_FLAG_RXFF                     USART_SR_RXFF          /*!< SCI RXFIFO Full flag                     */
#define SCI_FLAG_TXFE                     USART_SR_TXFE          /*!< SCI TXFIFO Empty flag                    */
#define SCI_FLAG_TXFT                     USART_SR_TXFT          /*!< SCI TXFIFO threshold flag                */
#define SCI_FLAG_RXFT                     USART_SR_RXFT          /*!< SCI RXFIFO threshold flag                */
#define SCI_FLAG_ABRRQ                    USART_SR_ABRRQ         /*!< SCI auto BRR request flag                */
#define SCI_FLAG_ABRE                     USART_SR_ABRE          /*!< SCI auto BRR error flag                  */
#define SCI_FLAG_ABRF                     USART_SR_ABRF          /*!< SCI auto BRR detection flag              */
#define SCI_FLAG_CTS                      USART_SR_CTS           /*!< SCI CTS flag                             */
#define SCI_FLAG_LBD                      USART_SR_LBD           /*!< SCI LIN break detection flag             */
#define SCI_FLAG_TXE                      USART_SR_TXE           /*!< SCI transmit data register empty         */
#define SCI_FLAG_TC                       USART_SR_TC            /*!< SCI transmission complete                */
#define SCI_FLAG_RXNE                     USART_SR_RXNE          /*!< SCI read data register not empty         */
#define SCI_FLAG_IDLE                     USART_SR_IDLE          /*!< SCI idle flag                            */
#define SCI_FLAG_ORE                      USART_SR_ORE           /*!< SCI overrun error                        */
#define SCI_FLAG_NE                       USART_SR_NE            /*!< SCI noise error                          */
#define SCI_FLAG_FE                       USART_SR_FE            /*!< SCI frame error                          */
#define SCI_FLAG_PE                       USART_SR_PE            /*!< SCI parity error                         */
/**
  * @}
  */
/** @defgroup SCI_Private_Constants SCI Private Constants
  * @{
  */
/** @brief SCI interruptions flag mask
  *
  */

#define SCI_CR1_REG_INDEX               1U
#define SCI_CR2_REG_INDEX               2U
#define SCI_CR3_REG_INDEX               3U
/**
  * @}
  */

/** @defgroup SCI_Interrupt_definition SCI Interrupts Definition

  *        Elements values convention: 000ZZZZZ0XXYYYYYb
  *           - YYYYY  : Interrupt source position in the XX register (5bits)
  *           - XX  : Interrupt source register (2bits)
  *                 - 01: CR1 register
  *                 - 10: CR2 register
  *                 - 11: CR3 register
  *           - ZZZZZ  : Flag position in the SR register(5bits)
  *        Elements values convention: 000000000XXYYYYYb
  *           - YYYYY  : Interrupt source position in the XX register (5bits)
  *           - XX  : Interrupt source register (2bits)
  *                 - 01: CR1 register
  *                 - 10: CR2 register
  *                 - 11: CR3 register
  *        Elements values convention: 000ZZZZZ00000000b
  *           - ZZZZZ  : Flag position in the SR register(5bits)
  * @{
  */

#define SCI_IT_PE                          0x0028U  /*!< SCI parity error interruption                 */
#define SCI_IT_TXE                         0x0727U  /*!< SCI transmit data register empty interruption */
#define SCI_IT_TC                          0x0626U  /*!< SCI transmission complete interruption        */
#define SCI_IT_RXNE                        0x0525U  /*!< SCI read data register not empty interruption */
#define SCI_IT_IDLE                        0x0424U  /*!< SCI idle interruption                         */
#define SCI_IT_LBD                         0x0846U  /*!< SCI LBD interruption                          */
#define SCI_IT_EOB                         0x127EU  /*!< SCI EOB interruption                          */
#define SCI_IT_RTO                         0x137DU  /*!< SCI RTO interruption                          */
#define SCI_IT_RXFF                        0x0F6FU  /*!< SCI RXFIFO full interruption                  */
#define SCI_IT_TXFE                        0x1070U  /*!< SCI TXFIFO empty interruption                 */
#define SCI_IT_RXFT                        0x0E71U  /*!< SCI RXFIFO threshold reached interruption     */
#define SCI_IT_TXFT                        0x0D72U  /*!< SCI TXFIFO threshold reached interruption     */
#define SCI_IT_CTS                         0x096AU  /*!< SCI fCTS interruption                         */

#define SCI_IT_ERR                         0x0060U  /*!< SCI error interruption                        */
#define SCI_IT_ORE                         0x0300U  /*!< SCI overrun error interruption                */
#define SCI_IT_NE                          0x0200U  /*!< SCI noise error interruption                  */
#define SCI_IT_FE                          0x0100U  /*!< SCI frame error interruption                  */

/**
  * @}
  */


/** @defgroup SCI_Reception_Type_Values  SCI Reception type values
  * @{
  */
#define HAL_SCI_RECEPTION_STANDARD          (0x00000000U)             /*!< Standard reception                       */
#define HAL_SCI_RECEPTION_TOIDLE            (0x00000001U)             /*!< Reception till completion or IDLE event  */
#define HAL_SCI_RECEPTION_TORTO             (0x00000002U)             /*!< Reception till completion or RTO event   */
#define HAL_SCI_RECEPTION_TOCHARMATCH       (0x00000003U)             /*!< Reception till completion or CM event    */
/**
  * @}
  */

/** @defgroup SCI_RxEvent_Type_Values  SCI RxEvent type values
  * @{
  */
#define HAL_SCI_RXEVENT_TC                  (0x00000000U)             /*!< RxEvent linked to Transfer Complete event */
#define HAL_SCI_RXEVENT_HT                  (0x00000001U)             /*!< RxEvent linked to Half Transfer event     */
#define HAL_SCI_RXEVENT_IDLE                (0x00000002U)             /*!< RxEvent linked to IDLE event              */
/**
  * @}
  */

/**
  * @}
  */
 
/* Exported macros -----------------------------------------------------------*/
/** @defgroup SCI_Exported_Macros SCI Exported Macros
  * @{
  */

/** @brief Reset SCI handle state.
  * @param  __HANDLE__ SCI handle.
  * @retval None
  */
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
#define __HAL_SCI_RESET_HANDLE_STATE(__HANDLE__)  do{                                                 \
                                                        (__HANDLE__)->gState = HAL_SCI_STATE_RESET;   \
                                                        (__HANDLE__)->RxState = HAL_SCI_STATE_RESET;  \
                                                        (__HANDLE__)->MspInitCallback = NULL;         \
                                                        (__HANDLE__)->MspDeInitCallback = NULL;       \
                                                      } while(0U)
#else
#define __HAL_SCI_RESET_HANDLE_STATE(__HANDLE__)  do{                                                 \
                                                       (__HANDLE__)->gState = HAL_SCI_STATE_RESET;    \
                                                       (__HANDLE__)->RxState = HAL_SCI_STATE_RESET;   \
                                                     } while(0U)
#endif /*USE_HAL_SCI_REGISTER_CALLBACKS */

/** @brief  Flushes the SCI DR register
  * @param  __HANDLE__ specifies the SCI Handle.
  *         SCI Handle selects the SCIx or SCIy peripheral
  *         (SCI,SCI availability and x,y values depending on device).
  */
#define __HAL_SCI_FLUSH_DRREGISTER(__HANDLE__) ((__HANDLE__)->Instance->DR)

/** @brief  Clears the specified SCI pending flag.
  * @param  __HANDLE__ specifies the SCI Handle.
  *         SCI Handle selects the SCIx or SCIy peripheral
  *         (SCI,SCI availability and x,y values depending on device).
  * @param  __FLAG__ specifies the flag to check.
  *          This parameter can be any combination of the following values:
  *            @arg SCI_FLAG_CTS:  CTS Change flag .
  *            @arg SCI_FLAG_LBD:  LIN Break detection flag.
  *            @arg SCI_FLAG_TC:   Transmission Complete flag.
  *            @arg SCI_FLAG_RXNE: Receive data register not empty flag.
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
#define __HAL_SCI_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/** @brief  Clear the SCI EOB pending flag.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @retval None
  */
#define __HAL_SCI_CLEAR_EOBFLAG(__HANDLE__) ((__HANDLE__)->Instance->SR &= (~USART_SR_EOBF))

/** @brief  Clear the SCI RTOF pending flag.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @retval None
  */
#define __HAL_SCI_CLEAR_RTOFLAG(__HANDLE__) ((__HANDLE__)->Instance->SR &= (~USART_SR_RTOF))

/** @brief  Clears the SCI PE pending flag.
  * @param  __HANDLE__ specifies the SCI Handle.
  *         SCI Handle selects the SCIx or SCIy peripheral
  *         SCI,SCI availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_SCI_CLEAR_PEFLAG(__HANDLE__)      \
  do{                                           \
    __IO uint32_t tmpreg = 0x00U;               \
    tmpreg = (__HANDLE__)->Instance->SR;        \
    tmpreg = (__HANDLE__)->Instance->DR;        \
    UNUSED(tmpreg);                             \
  } while(0U)

/** @brief  Clears the SCI FE pending flag.
  * @param  __HANDLE__ specifies the SCI Handle.
  *         SCI Handle selects the SCIx or SCIy peripheral
  *         SCI,SCI availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_SCI_CLEAR_FEFLAG(__HANDLE__) __HAL_SCI_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clears the SCI NE pending flag.
  * @param  __HANDLE__ specifies the SCI Handle.
  *         SCI Handle selects the SCIx or SCIy peripheral
  *         SCI,SCI availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_SCI_CLEAR_NEFLAG(__HANDLE__) __HAL_SCI_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clears the SCI ORE pending flag.
  * @param  __HANDLE__ specifies the SCI Handle.
  *         SCI Handle selects the SCIx or SCIy peripheral
  *         SCI,SCI availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_SCI_CLEAR_OREFLAG(__HANDLE__) __HAL_SCI_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clears the SCI IDLE pending flag.
  * @param  __HANDLE__ specifies the SCI Handle.
  *         SCI Handle selects the SCIx or SCIy peripheral
  *         SCI,SCI availability and x,y values depending on device).
  * @retval None
  */
#define __HAL_SCI_CLEAR_IDLEFLAG(__HANDLE__) __HAL_SCI_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Check whether the specified SCI flag is set or not.
  * @param  __HANDLE__ specifies the SCI Handle
  * @param  __FLAG__ specifies the flag to check.
  *        This parameter can be one of the following values:
  *            @arg @ref SCI_FLAG_RTOF   Receiver timeout flag
  *            @arg @ref SCI_FLAG_EOBF   Block end flag
  *            @arg @ref SCI_FLAG_RXFF   RXFIFO Full flag
  *            @arg @ref SCI_FLAG_TXFE   TXFIFO Empty flag
  *            @arg @ref SCI_FLAG_TXFT   TXFIFO threshold flag
  *            @arg @ref SCI_FLAG_RXFT   RXFIFO threshold flag
  *            @arg @ref SCI_FLAG_ABRRQ  Auto BRR request flag
  *            @arg @ref SCI_FLAG_ABRE   Auto BRR error flag
  *            @arg @ref SCI_FLAG_ABRF   Auto BRR detection flag
  *            @arg @ref SCI_FLAG_CTS    CTS flag
  *            @arg @ref SCI_FLAG_LBD    LIN break detection flag
  *            @arg @ref SCI_FLAG_TXE    Transmit data register empty flag
  *            @arg @ref SCI_FLAG_TC     Transmission complete flag
  *            @arg @ref SCI_FLAG_RXNE   Read data register not empty flag
  *            @arg @ref SCI_FLAG_IDLE   IDLE flag
  *            @arg @ref SCI_FLAG_ORE    Overrun error flag
  *            @arg @ref SCI_FLAG_NE     Noising Error flag
  *            @arg @ref SCI_FLAG_FE     Framing Error flag
  *            @arg @ref SCI_FLAG_PE     Parity Error flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_SCI_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))

/** @brief  Enable the specified SCI interrupt.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @param  __INTERRUPT__ specifies the SCI interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg @ref SCI_IT_LBD   LBD interrupt
  *            @arg @ref SCI_IT_EOB   EOB interrupt
  *            @arg @ref SCI_IT_RTO   RTO interrupt
  *            @arg @ref SCI_IT_CTS   CTS interrupt
  *            @arg @ref SCI_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref SCI_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref SCI_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref SCI_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref SCI_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref SCI_IT_TC    Transmission complete interrupt
  *            @arg @ref SCI_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref SCI_IT_IDLE  Idle line detection interrupt
  *            @arg @ref SCI_IT_PE    Parity Error interrupt
  *            @arg @ref SCI_IT_ERR   Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_SCI_ENABLE_IT(__HANDLE__, __INTERRUPT__)  ( \
                                                         ((((uint8_t)(__INTERRUPT__)) >> 5U) == SCI_CR1_REG_INDEX)?((__HANDLE__)->Instance->CR1 |= (1U << ((__INTERRUPT__) & SCI_IT_MASK))): \
                                                         ((((uint8_t)(__INTERRUPT__)) >> 5U) == SCI_CR2_REG_INDEX)?((__HANDLE__)->Instance->CR2 |= (1U << ((__INTERRUPT__) & SCI_IT_MASK))): \
                                                         ((__HANDLE__)->Instance->CR3 |= (1U << ((__INTERRUPT__) & SCI_IT_MASK))))

/** @brief  Disable the specified SCI interrupt.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @param  __INTERRUPT__ specifies the SCI interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg @ref SCI_IT_LBD   LBD interrupt
  *            @arg @ref SCI_IT_EOB   EOB interrupt
  *            @arg @ref SCI_IT_RTO   RTO interrupt
  *            @arg @ref SCI_IT_CTS   CTS interrupt
  *            @arg @ref SCI_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref SCI_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref SCI_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref SCI_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref SCI_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref SCI_IT_TC    Transmission complete interrupt
  *            @arg @ref SCI_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref SCI_IT_IDLE  Idle line detection interrupt
  *            @arg @ref SCI_IT_PE    Parity Error interrupt
  *            @arg @ref SCI_IT_ERR   Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_SCI_DISABLE_IT(__HANDLE__, __INTERRUPT__) ( \
                                                         ((((uint8_t)(__INTERRUPT__)) >> 5U) == SCI_CR1_REG_INDEX)?((__HANDLE__)->Instance->CR1 &= ~(1U << ((__INTERRUPT__) & SCI_IT_MASK))): \
                                                         ((((uint8_t)(__INTERRUPT__)) >> 5U) == SCI_CR2_REG_INDEX)?((__HANDLE__)->Instance->CR2 &= ~(1U << ((__INTERRUPT__) & SCI_IT_MASK))): \
                                                         ((__HANDLE__)->Instance->CR3 &= ~(1U << ((__INTERRUPT__) & SCI_IT_MASK))))

/** @brief  Check whether the specified SCI interrupt has occurred or not.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @param  __INTERRUPT__ specifies the SCI interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg @ref SCI_IT_LBD   LBD interrupt
  *            @arg @ref SCI_IT_EOB   EOB interrupt
  *            @arg @ref SCI_IT_RTO   RTO interrupt
  *            @arg @ref SCI_IT_CTS   CTS interrupt
  *            @arg @ref SCI_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref SCI_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref SCI_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref SCI_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref SCI_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref SCI_IT_TC    Transmission complete interrupt
  *            @arg @ref SCI_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref SCI_IT_IDLE  Idle line detection interrupt
  *            @arg @ref SCI_IT_PE    Parity Error interrupt
  *            @arg @ref SCI_IT_ERR   Error interrupt(Frame error, noise error, overrun error)
  * @retval The new state of __INTERRUPT__ (SET or RESET).
  */
#define __HAL_SCI_GET_IT(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->SR & (1U << ((__INTERRUPT__)>> 8U))) != RESET) ? SET : RESET)

/** @brief  Check whether the specified SCI interrupt has occurred or not.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @param  __INTERRUPT__ specifies the SCI interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg @ref SCI_IT_LBD   LBD interrupt
  *            @arg @ref SCI_IT_EOB   EOB interrupt
  *            @arg @ref SCI_IT_RTO   RTO interrupt
  *            @arg @ref SCI_IT_CTS   CTS interrupt
  *            @arg @ref SCI_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref SCI_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref SCI_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref SCI_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref SCI_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref SCI_IT_TC    Transmission complete interrupt
  *            @arg @ref SCI_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref SCI_IT_IDLE  Idle line detection interrupt
  *            @arg @ref SCI_IT_PE    Parity Error interrupt
  *            @arg @ref SCI_IT_ERR   Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_SCI_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((((((uint8_t)(__INTERRUPT__)) >> 5U) == SCI_CR1_REG_INDEX) ? (__HANDLE__)->Instance->CR1 : \
                                                              (((((uint8_t)(__INTERRUPT__)) >> 5U) == SCI_CR2_REG_INDEX) ? (__HANDLE__)->Instance->CR2 : \
                                                              (__HANDLE__)->Instance->CR3)) & (1U << (((uint16_t)(__INTERRUPT__)) & SCI_IT_MASK))) != RESET) ? SET : RESET)

/** @brief  Set a specific SCI request flag.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @param  __REQ__ specifies the request flag to set.
  *          This parameter can be one of the following values: 
  *            @arg @ref SCI_SENDBREAK_REQUEST Send Break Request
  *            @arg @ref SCI_RXDATA_FLUSH_REQUEST Receive Data flush Request
  *            @arg @ref SCI_TXDATA_FLUSH_REQUEST Transmit data flush Request
  *
  * @retval None
  */
#define __HAL_SCI_SEND_REQ(__HANDLE__, __REQ__)      ((__HANDLE__)->Instance->CR1 |= (uint16_t)(__REQ__))


/** @brief  Enable SCI.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @retval None
  */
#define __HAL_SCI_ENABLE(__HANDLE__)                 ((__HANDLE__)->Instance->CR1 |= USART_CR1_UE)

/** @brief  Disable SCI.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @retval None
  */
#define __HAL_SCI_DISABLE(__HANDLE__)                ((__HANDLE__)->Instance->CR1 &= ~USART_CR1_UE)

/** @brief  Enable CTS flow control
  * @note   This macro allows to enable CTS hardware flow control for a given SCI instance,
  *         without need to call HAL_SCI_Init() function.
  *         As involving direct access to USART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying CTS Hw flow control feature activation, without need
  *         for SCI instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - SCI instance should have already been initialised (through call of HAL_SCI_Init() )
  *           - macro could only be called when corresponding SCI instance is disabled (i.e __HAL_SCI_DISABLE(__HANDLE__))
  *             and should be followed by an Enable macro (i.e __HAL_SCI_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the SCI Handle.
  *         The Handle Instance can be any SCIx (supporting the HW Flow control feature).
  *         It is used to select the SCI peripheral (SCI availability and x value depending on device).
  * @retval None
  */
#define __HAL_SCI_HWCONTROL_CTS_ENABLE(__HANDLE__)        \
  do{                                                      \
    SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE);  \
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_CTSE;        \
  } while(0U)

/** @brief  Disable CTS flow control
  * @note   This macro allows to disable CTS hardware flow control for a given SCI instance,
  *         without need to call HAL_SCI_Init() function.
  *         As involving direct access to USART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying CTS Hw flow control feature activation, without need
  *         for SCI instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - SCI instance should have already been initialised (through call of HAL_SCI_Init() )
  *           - macro could only be called when corresponding SCI instance is disabled (i.e __HAL_SCI_DISABLE(__HANDLE__))
  *             and should be followed by an Enable macro (i.e __HAL_SCI_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the SCI Handle.
  *         The Handle Instance can be any SCIx (supporting the HW Flow control feature).
  *         It is used to select the SCI peripheral (SCI availability and x value depending on device).
  * @retval None
  */
#define __HAL_SCI_HWCONTROL_CTS_DISABLE(__HANDLE__)        \
  do{                                                       \
    CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE); \
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_CTSE);      \
  } while(0U)

/** @brief  Enable RTS flow control
  *         This macro allows to enable RTS hardware flow control for a given SCI instance,
  *         without need to call HAL_SCI_Init() function.
  *         As involving direct access to USART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying RTS Hw flow control feature activation, without need
  *         for SCI instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - SCI instance should have already been initialised (through call of HAL_SCI_Init() )
  *           - macro could only be called when corresponding SCI instance is disabled (i.e __HAL_SCI_DISABLE(__HANDLE__))
  *             and should be followed by an Enable macro (i.e __HAL_SCI_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the SCI Handle.
  *         The Handle Instance can be any SCIx (supporting the HW Flow control feature).
  *         It is used to select the SCI peripheral (SCI availability and x value depending on device).
  * @retval None
  */
#define __HAL_SCI_HWCONTROL_RTS_ENABLE(__HANDLE__)       \
  do{                                                     \
    SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE); \
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_RTSE;       \
  } while(0U)

/** @brief  Disable RTS flow control
  *         This macro allows to disable RTS hardware flow control for a given SCI instance,
  *         without need to call HAL_SCI_Init() function.
  *         As involving direct access to USART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying RTS Hw flow control feature activation, without need
  *         for SCI instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - SCI instance should have already been initialised (through call of HAL_SCI_Init() )
  *           - macro could only be called when corresponding USART instance is disabled (i.e __HAL_SCI_DISABLE(__HANDLE__))
  *             and should be followed by an Enable macro (i.e __HAL_SCI_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the SCI Handle.
  *         The Handle Instance can be any SCIx (supporting the HW Flow control feature).
  *         It is used to select the SCI peripheral (SCI availability and x value depending on device).
  * @retval None
  */
#define __HAL_SCI_HWCONTROL_RTS_DISABLE(__HANDLE__)       \
  do{                                                      \
    CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE);\
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_RTSE);     \
  } while(0U)

/** @brief  Send Auto-Baud Rate Request.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @retval None
  */
#define __HAL_SCI_SEND_AUTOBAUD_REQ(__HANDLE__)     ((__HANDLE__)->Instance->SR |= (uint16_t)(USART_SR_ABRRQ))

/**
  * @}
  */

/* Private macros --------------------------------------------------------*/
/** @defgroup SCI_Private_Macros   SCI Private Macros
  * @{
  */

/** @brief  Report the SCI clock source.
  * @param  __HANDLE__ specifies the SCI Handle.
  * @param  __CLOCKSOURCE__ output variable.
  * @retval the SCI clocking source, written in __CLOCKSOURCE__.
  */
#define SCI_GETCLOCKSOURCE(__HANDLE__,__CLOCKSOURCE__)       \
  do {                                                         \
    if((__HANDLE__)->Instance == USART1)                       \
    {                                                          \
      switch(__HAL_RCC_GET_USART1_SOURCE())                    \
      {                                                        \
        case RCC_USART1CLKSOURCE_PCLK2:                        \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_PCLK2;         \
          break;                                               \
        case RCC_USART1CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_HSI;           \
          break;                                               \
        case RCC_USART1CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_SYSCLK;        \
          break;                                               \
        case RCC_USART1CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_LSE;           \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_UNDEFINED;     \
          break;                                               \
      }                                                        \
    }                                                          \
    else if((__HANDLE__)->Instance == USART2)                  \
    {                                                          \
      switch(__HAL_RCC_GET_USART2_SOURCE())                    \
      {                                                        \
        case RCC_USART2CLKSOURCE_PCLK1:                        \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_PCLK1;         \
          break;                                               \
        case RCC_USART2CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_HSI;           \
          break;                                               \
        case RCC_USART2CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_SYSCLK;        \
          break;                                               \
        case RCC_USART2CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_LSE;           \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_UNDEFINED;     \
          break;                                               \
      }                                                        \
    }                                                          \
    else if((__HANDLE__)->Instance == USART3)                  \
    {                                                          \
      switch(__HAL_RCC_GET_USART3_SOURCE())                    \
      {                                                        \
        case RCC_USART3CLKSOURCE_PCLK1:                        \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_PCLK1;         \
          break;                                               \
        case RCC_USART3CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_HSI;           \
          break;                                               \
        case RCC_USART3CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_SYSCLK;        \
          break;                                               \
        case RCC_USART3CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_LSE;           \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_UNDEFINED;     \
          break;                                               \
      }                                                        \
    }                                                          \
    else                                                       \
    {                                                          \
      (__CLOCKSOURCE__) = SCI_CLOCKSOURCE_UNDEFINED;         \
    }                                                          \
  } while(0)

/** @brief  Check SCI Baud rate.
  * @param  __BAUDRATE__ Baudrate specified by the user.
  *         The maximum Baud Rate is derived from the maximum clock on E4
  *         divided by the smallest oversampling used on the SCI
  * @retval SET (__BAUDRATE__ is valid) or RESET (__BAUDRATE__ is invalid)  */
#define IS_SCI_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) <= 4500000U)

/** @brief  Check SCI assertion time.
  * @param  __TIME__ 5-bit value assertion time.
  * @retval Test result (TRUE or FALSE).
  */
#define IS_SCI_ASSERTIONTIME(__TIME__)    ((__TIME__) <= 0x1FU)

/** @brief  Check SCI deassertion time.
  * @param  __TIME__ 5-bit value deassertion time.
  * @retval Test result (TRUE or FALSE).
  */
#define IS_SCI_DEASSERTIONTIME(__TIME__) ((__TIME__) <= 0x1FU)

/**
  * @brief Ensure that SCI frame number of stop bits is valid.
  * @param __STOPBITS__ SCI frame number of stop bits.
  * @retval SET (__STOPBITS__ is valid) or RESET (__STOPBITS__ is invalid)
  */
#define IS_SCI_STOPBITS(__STOPBITS__) (((__STOPBITS__)   == SCI_STOPBITS_0_5) || \
                                         ((__STOPBITS__) == SCI_STOPBITS_1)   || \
                                         ((__STOPBITS__) == SCI_STOPBITS_1_5) || \
                                         ((__STOPBITS__) == SCI_STOPBITS_2))
/**
  * @brief Ensure that SCI frame parity is valid.
  * @param __PARITY__ SCI frame parity.
  * @retval SET (__PARITY__ is valid) or RESET (__PARITY__ is invalid)
  */
#define IS_SCI_PARITY(__PARITY__) (((__PARITY__) == SCI_PARITY_NONE) || \
                                   ((__PARITY__) == SCI_PARITY_EVEN) || \
                                   ((__PARITY__) == SCI_PARITY_ODD))

/**
  * @brief Ensure that SCI hardware flow control is valid.
  * @param __CONTROL__ SCI hardware flow control.
  * @retval SET (__CONTROL__ is valid) or RESET (__CONTROL__ is invalid)
  */
#define IS_SCI_HARDWARE_FLOW_CONTROL(__CONTROL__)\
  (((__CONTROL__) == SCI_HWCONTROL_NONE) || \
   ((__CONTROL__) == SCI_HWCONTROL_RTS)  || \
   ((__CONTROL__) == SCI_HWCONTROL_CTS)  || \
   ((__CONTROL__) == SCI_HWCONTROL_RTS_CTS))

/**
  * @brief Ensure that SCI communication mode is valid.
  * @param __MODE__ SCI communication mode.
  * @retval SET (__MODE__ is valid) or RESET (__MODE__ is invalid)
  */
#define IS_SCI_MODE(__MODE__) ((((__MODE__) & (~((uint32_t)(SCI_MODE_TX_RX)))) == 0x00U) && ((__MODE__) != 0x00U))

/**
  * @brief Ensure that SCI state is valid.
  * @param __STATE__ SCI state.
  * @retval SET (__STATE__ is valid) or RESET (__STATE__ is invalid)
  */
#define IS_SCI_STATE(__STATE__) (((__STATE__) == SCI_STATE_DISABLE) || \
                                 ((__STATE__) == SCI_STATE_ENABLE))

/**
  * @brief Ensure that SCI oversampling is valid.
  * @param __SAMPLING__ SCI oversampling.
  * @retval SET (__SAMPLING__ is valid) or RESET (__SAMPLING__ is invalid)
  */
#define IS_SCI_OVERSAMPLING(__SAMPLING__) (((__SAMPLING__) == SCI_OVERSAMPLING_16) || \
                                           ((__SAMPLING__) == SCI_OVERSAMPLING_8))

/**
  * @brief Ensure that SCI auto Baud rate detection mode is valid.
  * @param __MODE__ SCI auto Baud rate detection mode.
  * @retval SET (__MODE__ is valid) or RESET (__MODE__ is invalid)
  */
#define IS_SCI_ADVFEATURE_AUTOBAUDRATEMODE(__MODE__)  (((__MODE__) == SCI_ADVFEATURE_AUTOBAUDRATE_ONSTARTBIT)    || \
                                                       ((__MODE__) == SCI_ADVFEATURE_AUTOBAUDRATE_ONFALLINGEDGE) || \
                                                       ((__MODE__) == SCI_ADVFEATURE_AUTOBAUDRATE_ON0X7FFRAME)   || \
                                                       ((__MODE__) == SCI_ADVFEATURE_AUTOBAUDRATE_ON0X55FRAME))

/**
  * @brief Ensure that SCI receiver timeout setting is valid.
  * @param __TIMEOUT__ SCI receiver timeout setting.
  * @retval SET (__TIMEOUT__ is valid) or RESET (__TIMEOUT__ is invalid)
  */
#define IS_SCI_RECEIVER_TIMEOUT(__TIMEOUT__)  (((__TIMEOUT__) == SCI_RECEIVER_TIMEOUT_DISABLE) || \
                                               ((__TIMEOUT__) == SCI_RECEIVER_TIMEOUT_ENABLE))

/** @brief  Check the receiver timeout value.
  * @note   The maximum SCI receiver timeout value is 0xFFFFFF.
  * @param  __TIMEOUTVALUE__ receiver timeout value.
  * @retval Test result (TRUE or FALSE)
  */
#define IS_SCI_RECEIVER_TIMEOUT_VALUE(__TIMEOUTVALUE__)  ((__TIMEOUTVALUE__) <= 0xFFFFFFU)

/**
  * @brief Ensure that SCI LIN state is valid.
  * @param __LIN__ SCI LIN state.
  * @retval SET (__LIN__ is valid) or RESET (__LIN__ is invalid)
  */
#define IS_SCI_LIN(__LIN__)        (((__LIN__) == SCI_LIN_DISABLE) || \
                                    ((__LIN__) == SCI_LIN_ENABLE))

/**
  * @brief Ensure that SCI LIN break detection length is valid.
  * @param __LENGTH__ SCI LIN break detection length.
  * @retval SET (__LENGTH__ is valid) or RESET (__LENGTH__ is invalid)
  */
#define IS_SCI_LIN_BREAK_DETECT_LENGTH(__LENGTH__) (((__LENGTH__) == SCI_LINBREAKDETECTLENGTH_10B) || \
                                                    ((__LENGTH__) == SCI_LINBREAKDETECTLENGTH_11B))

/**
  * @brief Ensure that SCI DMA TX state is valid.
  * @param __DMATX__ SCI DMA TX state.
  * @retval SET (__DMATX__ is valid) or RESET (__DMATX__ is invalid)
  */
#define IS_SCI_DMA_TX(__DMATX__)     (((__DMATX__) == SCI_DMA_TX_DISABLE) || \
                                      ((__DMATX__) == SCI_DMA_TX_ENABLE))

/**
  * @brief Ensure that SCI DMA RX state is valid.
  * @param __DMARX__ SCI DMA RX state.
  * @retval SET (__DMARX__ is valid) or RESET (__DMARX__ is invalid)
  */
#define IS_SCI_DMA_RX(__DMARX__)     (((__DMARX__) == SCI_DMA_RX_DISABLE) || \
                                      ((__DMARX__) == SCI_DMA_RX_ENABLE))

/**
  * @brief Ensure that SCI half-duplex state is valid.
  * @param __HDSEL__ SCI half-duplex state.
  * @retval SET (__HDSEL__ is valid) or RESET (__HDSEL__ is invalid)
  */
#define IS_SCI_HALF_DUPLEX(__HDSEL__)     (((__HDSEL__) == SCI_HALF_DUPLEX_DISABLE) || \
                                           ((__HDSEL__) == SCI_HALF_DUPLEX_ENABLE))

/**
  * @brief Ensure that SCI wakeup is valid.
  * @param WAKEUP SCI wakeup.
  * @retval SET (WAKEUP is valid) or RESET (WAKEUP is invalid)
  */
#define IS_SCI_WAKEUPMETHOD(WAKEUP) (((WAKEUP) == SCI_WAKEUPMETHOD_IDLELINE) || \
                                     ((WAKEUP) == SCI_WAKEUPMETHOD_ADDRESSMARK))
/**
  * @brief Ensure that SCI request parameter is valid.
  * @param __PARAM__ SCI request parameter.
  * @retval SET (__PARAM__ is valid) or RESET (__PARAM__ is invalid)
  */
#define IS_SCI_REQUEST_PARAMETER(__PARAM__) (((__PARAM__) == SCI_SENDBREAK_REQUEST)    || \
                                             ((__PARAM__) == SCI_RXDATA_FLUSH_REQUEST) || \
                                             ((__PARAM__) == SCI_TXDATA_FLUSH_REQUEST))

/**
  * @brief Ensure that SCI advanced features initialization is valid.
  * @param __INIT__ SCI advanced features initialization.
  * @retval SET (__INIT__ is valid) or RESET (__INIT__ is invalid)
  */
#define IS_SCI_ADVFEATURE_INIT(__INIT__)   ((__INIT__) <=  (SCI_ADVFEATURE_NO_INIT                | \
                                                            SCI_ADVFEATURE_TXINVERT_INIT          | \
                                                            SCI_ADVFEATURE_RXINVERT_INIT          | \
                                                            SCI_ADVFEATURE_DATAINVERT_INIT        | \
                                                            SCI_ADVFEATURE_SWAP_INIT              | \
                                                            SCI_ADVFEATURE_AUTOBAUDRATE_INIT      | \
                                                            SCI_ADVFEATURE_MSBFIRST_INIT))

/**
  * @brief Ensure that SCI frame TX inversion setting is valid.
  * @param __TXINV__ SCI frame TX inversion setting.
  * @retval SET (__TXINV__ is valid) or RESET (__TXINV__ is invalid)
  */
#define IS_SCI_ADVFEATURE_TXINV(__TXINV__)  (((__TXINV__) == SCI_ADVFEATURE_TXINV_DISABLE) || \
                                             ((__TXINV__) == SCI_ADVFEATURE_TXINV_ENABLE))

/**
  * @brief Ensure that SCI frame RX inversion setting is valid.
  * @param __RXINV__ SCI frame RX inversion setting.
  * @retval SET (__RXINV__ is valid) or RESET (__RXINV__ is invalid)
  */
#define IS_SCI_ADVFEATURE_RXINV(__RXINV__)  (((__RXINV__) == SCI_ADVFEATURE_RXINV_DISABLE) || \
                                             ((__RXINV__) == SCI_ADVFEATURE_RXINV_ENABLE))

/**
  * @brief Ensure that SCI frame data inversion setting is valid.
  * @param __DATAINV__ SCI frame data inversion setting.
  * @retval SET (__DATAINV__ is valid) or RESET (__DATAINV__ is invalid)
  */
#define IS_SCI_ADVFEATURE_DATAINV(__DATAINV__)  (((__DATAINV__) == SCI_ADVFEATURE_DATAINV_DISABLE) || \
                                                 ((__DATAINV__) == SCI_ADVFEATURE_DATAINV_ENABLE))

/**
  * @brief Ensure that SCI frame RX/TX pins swap setting is valid.
  * @param __SWAP__ SCI frame RX/TX pins swap setting.
  * @retval SET (__SWAP__ is valid) or RESET (__SWAP__ is invalid)
  */
#define IS_SCI_ADVFEATURE_SWAP(__SWAP__)  (((__SWAP__) == SCI_ADVFEATURE_SWAP_DISABLE) || \
                                           ((__SWAP__) == SCI_ADVFEATURE_SWAP_ENABLE))

/**
  * @brief Ensure that SCI auto Baud rate state is valid.
  * @param __AUTOBAUDRATE__ SCI auto Baud rate state.
  * @retval SET (__AUTOBAUDRATE__ is valid) or RESET (__AUTOBAUDRATE__ is invalid)
  */
#define IS_SCI_ADVFEATURE_AUTOBAUDRATE(__AUTOBAUDRATE__)  (((__AUTOBAUDRATE__) == SCI_ADVFEATURE_AUTOBAUDRATE_DISABLE) || \
                                                           ((__AUTOBAUDRATE__) == SCI_ADVFEATURE_AUTOBAUDRATE_ENABLE))

/**
  * @brief Ensure that SCI frame MSB first setting is valid.
  * @param __MSBFIRST__ SCI frame MSB first setting.
  * @retval SET (__MSBFIRST__ is valid) or RESET (__MSBFIRST__ is invalid)
  */
#define IS_SCI_ADVFEATURE_MSBFIRST(__MSBFIRST__)  (((__MSBFIRST__) == SCI_ADVFEATURE_MSBFIRST_DISABLE) || \
                                                   ((__MSBFIRST__) == SCI_ADVFEATURE_MSBFIRST_ENABLE))

/**
  * @brief Ensure that SCI receiver timeout setting is valid.
  * @param __TIMEOUT__ SCI receiver timeout setting.
  * @retval SET (__TIMEOUT__ is valid) or RESET (__TIMEOUT__ is invalid)
  */
#define IS_SCI_RECEIVER_TIMEOUT(__TIMEOUT__)  (((__TIMEOUT__) == SCI_RECEIVER_TIMEOUT_DISABLE) || \
                                               ((__TIMEOUT__) == SCI_RECEIVER_TIMEOUT_ENABLE))

/** @brief  Check the receiver timeout value.
  * @note   The maximum SCI receiver timeout value is 0xFFFFFF.
  * @param  __TIMEOUTVALUE__ receiver timeout value.
  * @retval Test result (TRUE or FALSE)
  */
#define IS_SCI_RECEIVER_TIMEOUT_VALUE(__TIMEOUTVALUE__)  ((__TIMEOUTVALUE__) <= 0xFFFFFFU)

#define IS_SCI_ADDRESS(ADDRESS) ((ADDRESS) <= 0xFFU)

/**
  * @brief Ensure that SCI driver enable polarity is valid.
  * @param __POLARITY__ SCI driver enable polarity.
  * @retval SET (__POLARITY__ is valid) or RESET (__POLARITY__ is invalid)
  */
#define IS_SCI_DE_POLARITY(__POLARITY__)    (((__POLARITY__) == SCI_DE_POLARITY_HIGH) || \
                                             ((__POLARITY__) == SCI_DE_POLARITY_LOW))

/**
  * @brief Ensure that SCI driver enable polarity is valid.
  * @param __POLARITY__ SCI driver enable polarity.
  * @retval SET (__POLARITY__ is valid) or RESET (__POLARITY__ is invalid)
  */
#define IS_SCI_DE_POLARITY(__POLARITY__)    (((__POLARITY__) == SCI_DE_POLARITY_HIGH) || \
                                             ((__POLARITY__) == SCI_DE_POLARITY_LOW))

#define IS_SCI_WORD_LENGTH(LENGTH) ((((LENGTH) == SCI_WORDLENGTH_7B) || \
                                     ((LENGTH) == SCI_WORDLENGTH_8B) || \
                                     ((LENGTH) == SCI_WORDLENGTH_9B)))

#define IS_SCI_RX_MATCH_ADDR(ADDR) ((ADDR) <= 0xFF)


#define SCI_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))
#define SCI_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (SCI_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define SCI_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        (((SCI_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (SCI_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U + 50U) / 100U)
/* SCI BRR = mantissa + overflow + fraction
           = (SCI DIVMANT << 4) + (SCI DIVFRAQ & 0xF0) + (SCI DIVFRAQ & 0x0FU) */
#define SCI_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((SCI_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                        (SCI_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (SCI_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

#define SCI_DIV_SAMPLING8(_PCLK_, _BAUD_)             (((_PCLK_)*25U)/(2U*(_BAUD_)))
#define SCI_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (SCI_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
#define SCI_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         (((SCI_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (SCI_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U + 50U) / 100U)
/* SCI BRR = mantissa + overflow + fraction
           = (SCI DIVMANT << 4) + ((SCI DIVFRAQ & 0xF8) << 1) + (SCI DIVFRAQ & 0x07U) */
#define SCI_BRR_SAMPLING8(_PCLK_, _BAUD_)             (((SCI_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                        ((SCI_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U)) + \
                                                        (SCI_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))

/**
  * @}
  */


#include "py32e407_hal_sci_ex.h"
/* Exported functions --------------------------------------------------------*/
/** @addtogroup SCI_Exported_Functions
  * @{
  */
/** @addtogroup SCI_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */

/* Initialization/de-initialization functions  **********************************/
HAL_StatusTypeDef HAL_SCI_Init(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_HalfDuplex_Init(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_LIN_Init(SCI_HandleTypeDef *hsci, uint32_t BreakDetectLength);
HAL_StatusTypeDef HAL_MultiProcessor_Init(SCI_HandleTypeDef *hsci, uint8_t Address, uint32_t WakeUpMethod);
HAL_StatusTypeDef HAL_SCI_DeInit(SCI_HandleTypeDef *hsci);
void HAL_SCI_MspInit(SCI_HandleTypeDef *hsci);
void HAL_SCI_MspDeInit(SCI_HandleTypeDef *hsci);

/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_SCI_RegisterCallback(SCI_HandleTypeDef *hsci, HAL_SCI_CallbackIDTypeDef CallbackID, pSCI_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_SCI_UnRegisterCallback(SCI_HandleTypeDef *hsci, HAL_SCI_CallbackIDTypeDef CallbackID);
HAL_StatusTypeDef HAL_SCI_RegisterRxEventCallback(SCI_HandleTypeDef *hsci, pSCI_RxEventCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_SCI_UnRegisterRxEventCallback(SCI_HandleTypeDef *hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup SCI_Exported_Functions_Group2 IO operation functions
  * @{
  */

/* IO operation functions *******************************************************/
HAL_StatusTypeDef HAL_SCI_Transmit(SCI_HandleTypeDef *hsci, uint8_t *pData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SCI_Receive(SCI_HandleTypeDef *hsci, uint8_t *pData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SCI_Transmit_IT(SCI_HandleTypeDef *hsci, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_SCI_Receive_IT(SCI_HandleTypeDef *hsci, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_SCI_Transmit_DMA(SCI_HandleTypeDef *hsci, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_SCI_Receive_DMA(SCI_HandleTypeDef *hsci, uint8_t *pRxData, uint32_t Size);
HAL_StatusTypeDef HAL_SCI_DMAPause(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_SCI_DMAResume(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_SCI_DMAStop(SCI_HandleTypeDef *hsci);
/* Transfer Abort functions */
HAL_StatusTypeDef HAL_SCI_Abort(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_SCI_AbortTransmit(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_SCI_AbortReceive(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_SCI_Abort_IT(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_SCI_AbortTransmit_IT(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_SCI_AbortReceive_IT(SCI_HandleTypeDef *hsci);

void HAL_SCI_IRQHandler(SCI_HandleTypeDef *hsci);
void HAL_SCI_TxCpltCallback(SCI_HandleTypeDef *hsci);
void HAL_SCI_TxBlockCpltCallback(SCI_HandleTypeDef *hsci);
void HAL_SCI_TxHalfBlockCpltCallback(SCI_HandleTypeDef *hsci);
void HAL_SCI_TxSrcCpltCallback(SCI_HandleTypeDef *hsci);
void HAL_SCI_RxCpltCallback(SCI_HandleTypeDef *hsci);
void HAL_SCI_RxBlockCpltCallback(SCI_HandleTypeDef *hsci);
void HAL_SCI_RxHalfBlockCpltCallback(SCI_HandleTypeDef *hsci);
void HAL_SCI_RxDstCpltCallback(SCI_HandleTypeDef *hsci);
void HAL_SCI_ErrorCallback(SCI_HandleTypeDef *hsci);
void HAL_SCI_AbortCpltCallback(SCI_HandleTypeDef *hsci);
void HAL_SCI_AbortTransmitCpltCallback(SCI_HandleTypeDef *hsci);
void HAL_SCI_AbortReceiveCpltCallback(SCI_HandleTypeDef *hsci);

void HAL_SCIEx_RxEventCallback(SCI_HandleTypeDef *hsci, uint32_t Size);

/**
  * @}
  */

/** @addtogroup SCI_Exported_Functions_Group3
  * @{
  */

/* Peripheral Control functions  ************************************************/
void HAL_SCI_ReceiverTimeout_Config(SCI_HandleTypeDef *hsci, uint32_t TimeoutValue);
HAL_StatusTypeDef HAL_SCI_EnableReceiverTimeout(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_SCI_DisableReceiverTimeout(SCI_HandleTypeDef *hsci);

HAL_StatusTypeDef HAL_LIN_SendBreak(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_MultiProcessor_EnableMuteMode(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_MultiProcessor_DisableMuteMode(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(SCI_HandleTypeDef *hsci);

/**
  * @}
  */

/** @addtogroup SCI_Exported_Functions_Group4
  * @{
  */
/* Peripheral State functions  **************************************************/
HAL_SCI_StateTypeDef HAL_SCI_GetState(SCI_HandleTypeDef *hsci);
uint32_t             HAL_SCI_GetError(SCI_HandleTypeDef *hsci);
/**
  * @}
  */

#if (USE_HAL_SCI_REGISTER_CALLBACKS == 1)
void              SCI_InitCallbacksToDefault(SCI_HandleTypeDef *hsci);
#endif /* USE_HAL_SCI_REGISTER_CALLBACKS */
void SCI_SetConfig(SCI_HandleTypeDef *hsci);
void SCI_AdvFeatureConfig(SCI_HandleTypeDef *hsci);
HAL_StatusTypeDef SCI_Start_Receive_IT(SCI_HandleTypeDef *hsci, uint8_t *pRxData, uint32_t Size);
HAL_StatusTypeDef SCI_Start_Receive_DMA(SCI_HandleTypeDef *hsci, uint8_t *pRxData, uint32_t Size);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif
#ifdef __cplusplus
}

#endif /* __PY32E407_HAL_SCI_H */
/************************ (C) COPYRIGHT Puya *****END OF FILE****/
