/**
  ******************************************************************************
  * @file    py32e407_hal_lpuart.h
  * @author  MCU Application Team
  * @brief   Header file of LPUART HAL module.
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
#ifndef __PY32E407_HAL_LPUART_H
#define __PY32E407_HAL_LPUART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup LPUART
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup LPUART_Exported_Types LPUART Exported Types
  * @{
  */

/**
  * @brief LPUART Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< This member configures the LPUART communication baud rate. */

  uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref LPUARTEx_Word_Length. */

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref LPUART_Stop_Bits. */

  uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref LPUART_Parity */

  uint32_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref LPUART_Mode. */

  uint32_t HwFlowCtl;                 /*!< Specifies whether the hardware flow control mode is enabled
                                           or disabled.
                                           This parameter can be a value of @ref LPUART_Hardware_Flow_Control. */

  uint32_t ClockPrescaler;            /*!< Specifies the prescaler value used to divide the LPUART clock source.
                                           This parameter can be a value of @ref LPUART_ClockPrescaler. */

} LPUART_InitTypeDef;

/**
  * @brief  LPUART Advanced Features initialization structure definition
  */
typedef struct
{
  uint32_t AdvFeatureInit;        /*!< Specifies which advanced LPUART features is initialized. Several
                                       Advanced Features may be initialized at the same time .
                                       This parameter can be a value of
                                       @ref LPUART_Advanced_Features_Initialization_Type. */

  uint32_t TxPinLevelInvert;      /*!< Specifies whether the TX pin active level is inverted.
                                       This parameter can be a value of @ref LPUART_Tx_Inv. */

  uint32_t RxPinLevelInvert;      /*!< Specifies whether the RX pin active level is inverted.
                                       This parameter can be a value of @ref LPUART_Rx_Inv. */

  uint32_t DataInvert;            /*!< Specifies whether data are inverted (positive/direct logic
                                       vs negative/inverted logic).
                                       This parameter can be a value of @ref LPUART_Data_Inv. */

  uint32_t Swap;                  /*!< Specifies whether TX and RX pins are swapped.
                                       This parameter can be a value of @ref LPUART_Rx_Tx_Swap. */

  uint32_t OverrunDisable;        /*!< Specifies whether the reception overrun detection is disabled.
                                       This parameter can be a value of @ref LPUART_Overrun_Disable. */

  uint32_t DMADisableonRxError;   /*!< Specifies whether the DMA is disabled in case of reception error.
                                       This parameter can be a value of @ref LPUART_DMA_Disable_on_Rx_Error. */

  uint32_t MSBFirst;              /*!< Specifies whether MSB is sent first on LPUART line.
                                       This parameter can be a value of @ref LPUART_MSB_First. */
  uint32_t TxoeAlway;             /*!< Specifies whether LPUART output enable control.
                                       This parameter can be a value of @ref LPUART_TXOE_ALWAYS_ON. */
} LPUART_AdvFeatureInitTypeDef;

/**
  * @brief HAL LPUART State definition
  * @note  HAL LPUART State value is a combination of 2 different substates:
  *        gState and RxState (see @ref LPUART_State_Definition).
  *        - gState contains LPUART state information related to global Handle management
  *          and also information related to Tx operations.
  *          gState value coding follow below described bitmap :
  *          b7-b6  Error information
  *             00 : No Error
  *             01 : (Not Used)
  *             10 : Timeout
  *             11 : Error
  *          b5     Peripheral initialization status
  *             0  : Reset (Peripheral not initialized)
  *             1  : Init done (Peripheral not initialized. HAL LPUART Init function already called)
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
typedef uint32_t HAL_LPUART_StateTypeDef;

/**
  * @brief LPUART clock sources definition
  */
typedef enum
{
  LPUART_CLOCKSOURCE_PCLK1      = 0x00U,    /*!< PCLK1 clock source  */
  LPUART_CLOCKSOURCE_PCLK2      = 0x01U,    /*!< PCLK2 clock source  */
  LPUART_CLOCKSOURCE_HSI        = 0x02U,    /*!< HSI clock source    */
  LPUART_CLOCKSOURCE_SYSCLK     = 0x04U,    /*!< SYSCLK clock source */
  LPUART_CLOCKSOURCE_LSE        = 0x08U,    /*!< LSE clock source       */
  LPUART_CLOCKSOURCE_UNDEFINED  = 0x10U     /*!< Undefined clock source */
} LPUART_ClockSourceTypeDef;

/**
  * @brief  LPUART handle Structure definition
  */
typedef struct __LPUART_HandleTypeDef
{
  LPUART_TypeDef              *Instance;                 /*!< LPUART registers base address        */

  LPUART_InitTypeDef           Init;                     /*!< LPUART communication parameters      */

  LPUART_AdvFeatureInitTypeDef AdvancedInit;             /*!< LPUART Advanced Features initialization parameters */

  uint8_t                      *pTxBuffPtr;              /*!< Pointer to LPUART Tx transfer Buffer */

  uint32_t                     TxXferSize;               /*!< LPUART Tx Transfer size              */

  __IO uint32_t                TxXferCount;              /*!< LPUART Tx Transfer Counter           */

  uint8_t                      *pRxBuffPtr;              /*!< Pointer to LPUART Rx transfer Buffer */

  uint32_t                     RxXferSize;               /*!< LPUART Rx Transfer size              */

  __IO uint32_t                RxXferCount;              /*!< LPUART Rx Transfer Counter           */

  uint16_t                     Mask;                     /*!< LPUART Rx RDR register mask          */

  uint32_t                     FifoMode;                 /*!< Specifies if the FIFO mode is being used.
                                                              This parameter can be a value of @ref LPUARTEx_FIFO_mode. */

  uint32_t                     NbRxDataToProcess;        /*!< Number of data to process during RX ISR execution */

  uint32_t                     NbTxDataToProcess;        /*!< Number of data to process during TX ISR execution */

  void (*RxISR)(struct __LPUART_HandleTypeDef *hlpuart); /*!< Function pointer on Rx IRQ handler */

  void (*TxISR)(struct __LPUART_HandleTypeDef *hlpuart); /*!< Function pointer on Tx IRQ handler */

  DMA_HandleTypeDef            *hdmatx;                  /*!< LPUART Tx DMA Handle parameters      */

  DMA_HandleTypeDef            *hdmarx;                  /*!< LPUART Rx DMA Handle parameters      */

  HAL_LockTypeDef              Lock;                     /*!< Locking object                     */

  __IO HAL_LPUART_StateTypeDef gState;                   /*!< LPUART state information related to global Handle management
                                                              and also related to Tx operations. This parameter
                                                              can be a value of @ref HAL_LPUART_StateTypeDef */

  __IO HAL_LPUART_StateTypeDef RxState;                  /*!< LPUART state information related to Rx operations. This
                                                              parameter can be a value of @ref HAL_LPUART_StateTypeDef */

  __IO uint32_t                ErrorCode;                /*!< LPUART Error code                    */

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
  void (* TxBlockCpltCallback)(struct __LPUART_HandleTypeDef *hlpuart);       /*!< LPUART Tx Block Complete Callback       */
  void (* TxHalfBlockCpltCallback)(struct __LPUART_HandleTypeDef *hlpuart);   /*!< LPUART Tx Half Block Complete Callback  */
  void (* TxSrcCpltCallback)(struct __LPUART_HandleTypeDef *hlpuart);         /*!< LPUART Tx Source Complete Callback      */
  void (* TxCpltCallback)(struct __LPUART_HandleTypeDef *hlpuart);            /*!< LPUART Tx Complete Callback             */
  void (* RxBlockCpltCallback)(struct __LPUART_HandleTypeDef *hlpuart);       /*!< LPUART Rx Block Complete Callback       */
  void (* RxHalfBlockCpltCallback)(struct __LPUART_HandleTypeDef *hlpuart);   /*!< LPUART Rx Half Block Complete Callback  */
  void (* RxDstCpltCallback)(struct __LPUART_HandleTypeDef *hlpuart);         /*!< LPUART Rx Destination Complete Callback */
  void (* RxCpltCallback)(struct __LPUART_HandleTypeDef *hlpuart);            /*!< LPUART Rx Complete Callback             */
  void (* ErrorCallback)(struct __LPUART_HandleTypeDef *hlpuart);             /*!< LPUART Error Callback                   */
  void (* AbortCpltCallback)(struct __LPUART_HandleTypeDef *hlpuart);         /*!< LPUART Abort Complete Callback          */
  void (* AbortTransmitCpltCallback)(struct __LPUART_HandleTypeDef *hlpuart); /*!< LPUART Abort Transmit Complete Callback */
  void (* AbortReceiveCpltCallback)(struct __LPUART_HandleTypeDef *hlpuart);  /*!< LPUART Abort Receive Complete Callback  */
  void (* WakeupCallback)(struct __LPUART_HandleTypeDef *hlpuart);            /*!< LPUART Wakeup Callback                  */
  void (* RxFifoFullCallback)(struct __LPUART_HandleTypeDef *hlpuart);        /*!< LPUART Rx Fifo Full Callback            */
  void (* TxFifoEmptyCallback)(struct __LPUART_HandleTypeDef *hlpuart);       /*!< LPUART Tx Fifo Empty Callback           */

  void (* MspInitCallback)(struct __LPUART_HandleTypeDef *hlpuart);           /*!< LPUART Msp Init callback                */
  void (* MspDeInitCallback)(struct __LPUART_HandleTypeDef *hlpuart);         /*!< LPUART Msp DeInit callback              */
#endif  /* USE_HAL_LPUART_REGISTER_CALLBACKS */

} LPUART_HandleTypeDef;

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL LPUART Callback ID enumeration definition
  */
typedef enum
{
  HAL_LPUART_TX_BLOCKCOMPLETE_CB_ID        = 0x00U,    /*!< LPUART Tx Block Complete Callback ID       */
  HAL_LPUART_TX_HALFBLOCKCOMPLETE_CB_ID    = 0x01U,    /*!< LPUART Tx Half Block Complete Callback ID  */
  HAL_LPUART_TX_SRCCOMPLETE_CB_ID          = 0x02U,    /*!< LPUART Tx Source Complete Callback ID      */
  HAL_LPUART_TX_COMPLETE_CB_ID             = 0x03U,    /*!< LPUART Tx Complete Callback ID             */
  HAL_LPUART_RX_BLOCKCOMPLETE_CB_ID        = 0x04U,    /*!< LPUART Rx Block Complete Callback ID       */
  HAL_LPUART_RX_HALFBLOCKCOMPLETE_CB_ID    = 0x05U,    /*!< LPUART Rx Half Block Complete Callback ID  */
  HAL_LPUART_RX_DSTCOMPLETE_CB_ID          = 0x06U,    /*!< LPUART Rx Destination Complete Callback ID */
  HAL_LPUART_RX_COMPLETE_CB_ID             = 0x07U,    /*!< LPUART Rx Complete Callback ID             */
  HAL_LPUART_ERROR_CB_ID                   = 0x08U,    /*!< LPUART Error Callback ID                   */
  HAL_LPUART_ABORT_COMPLETE_CB_ID          = 0x09U,    /*!< LPUART Abort Complete Callback ID          */
  HAL_LPUART_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x0AU,    /*!< LPUART Abort Transmit Complete Callback ID */
  HAL_LPUART_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x0BU,    /*!< LPUART Abort Receive Complete Callback ID  */
  HAL_LPUART_WAKEUP_CB_ID                  = 0x0CU,    /*!< LPUART Wakeup Callback ID                  */
  HAL_LPUART_RX_FIFO_FULL_CB_ID            = 0x0DU,    /*!< LPUART Rx Fifo Full Callback ID            */
  HAL_LPUART_TX_FIFO_EMPTY_CB_ID           = 0x0EU,    /*!< LPUART Tx Fifo Empty Callback ID           */

  HAL_LPUART_MSPINIT_CB_ID                 = 0x0FU,    /*!< LPUART MspInit callback ID                 */
  HAL_LPUART_MSPDEINIT_CB_ID               = 0x10U     /*!< LPUART MspDeInit callback ID               */

} HAL_LPUART_CallbackIDTypeDef;

/**
  * @brief  HAL LPUART Callback pointer definition
  */
typedef  void (*pLPUART_CallbackTypeDef)(LPUART_HandleTypeDef *hlpuart);  /*!< pointer to an LPUART callback function */

#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup LPUART_Exported_Constants LPUART Exported Constants
  * @{
  */

/** @defgroup LPUART_State_Definition LPUART State Code Definition
  * @{
  */
#define  HAL_LPUART_STATE_RESET         0x00000000U    /*!< Peripheral is not initialized
                                                            Value is allowed for gState and RxState */
#define  HAL_LPUART_STATE_READY         0x00000020U    /*!< Peripheral Initialized and ready for use
                                                            Value is allowed for gState and RxState */
#define  HAL_LPUART_STATE_BUSY          0x00000024U    /*!< an internal process is ongoing
                                                            Value is allowed for gState only */
#define  HAL_LPUART_STATE_BUSY_TX       0x00000021U    /*!< Data Transmission process is ongoing
                                                            Value is allowed for gState only */
#define  HAL_LPUART_STATE_BUSY_RX       0x00000022U    /*!< Data Reception process is ongoing
                                                            Value is allowed for RxState only */
#define  HAL_LPUART_STATE_BUSY_TX_RX    0x00000023U    /*!< Data Transmission and Reception process is ongoing
                                                            Not to be used for neither gState nor RxState.Value is result
                                                            of combination (Or) between gState and RxState values */
#define  HAL_LPUART_STATE_TIMEOUT       0x000000A0U    /*!< Timeout state
                                                            Value is allowed for gState only */
#define  HAL_LPUART_STATE_ERROR         0x000000E0U    /*!< Error
                                                            Value is allowed for gState only */
/**
  * @}
  */

/** @defgroup LPUART_Error_Definition   LPUART Error Definition
  * @{
  */
#define  HAL_LPUART_ERROR_NONE             ((uint32_t)0x00000000U)    /*!< No error                */
#define  HAL_LPUART_ERROR_PE               ((uint32_t)0x00000001U)    /*!< Parity error            */
#define  HAL_LPUART_ERROR_NE               ((uint32_t)0x00000002U)    /*!< Noise error             */
#define  HAL_LPUART_ERROR_FE               ((uint32_t)0x00000004U)    /*!< Frame error             */
#define  HAL_LPUART_ERROR_ORE              ((uint32_t)0x00000008U)    /*!< Overrun error           */
#define  HAL_LPUART_ERROR_DMA              ((uint32_t)0x00000010U)    /*!< DMA transfer error      */
#define  HAL_LPUART_ERROR_RTO              ((uint32_t)0x00000020U)    /*!< Receiver Timeout error  */

#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
#define  HAL_LPUART_ERROR_INVALID_CALLBACK ((uint32_t)0x00000040U)    /*!< Invalid Callback error  */
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup LPUART_Stop_Bits   LPUART Number of Stop Bits
  * @{
  */
#define LPUART_STOPBITS_1                     0x00000000U                        /*!< LPUART frame with 1 stop bit    */
#define LPUART_STOPBITS_2                     LPUART_CR2_STOP_1                  /*!< LPUART frame with 2 stop bits   */
/**
  * @}
  */

/** @defgroup LPUART_Parity  LPUART Parity
  * @{
  */
#define LPUART_PARITY_NONE                    0x00000000U                        /*!< No parity   */
#define LPUART_PARITY_EVEN                    LPUART_CR1_PCE                     /*!< Even parity */
#define LPUART_PARITY_ODD                     (LPUART_CR1_PCE | LPUART_CR1_PS)   /*!< Odd parity  */
/**
  * @}
  */

/** @defgroup LPUART_Hardware_Flow_Control LPUART Hardware Flow Control
  * @{
  */
#define LPUART_HWCONTROL_NONE                  0x00000000U                          /*!< No hardware control       */
#define LPUART_HWCONTROL_RTS                   LPUART_CR3_RTSE                      /*!< Request To Send           */
#define LPUART_HWCONTROL_CTS                   LPUART_CR3_CTSE                      /*!< Clear To Send             */
#define LPUART_HWCONTROL_RTS_CTS               (LPUART_CR3_RTSE | LPUART_CR3_CTSE)  /*!< Request and Clear To Send */
/**
  * @}
  */

/** @defgroup LPUART_Mode LPUART Transfer Mode
  * @{
  */
#define LPUART_MODE_RX                        LPUART_CR1_RE                    /*!< RX mode        */
#define LPUART_MODE_TX                        LPUART_CR1_TE                    /*!< TX mode        */
#define LPUART_MODE_TX_RX                     (LPUART_CR1_TE | LPUART_CR1_RE)  /*!< RX and TX mode */
/**
  * @}
  */

/** @defgroup LPUART_State  LPUART State
  * @{
  */
#define LPUART_STATE_DISABLE                  0x00000000U         /*!< LPUART disabled  */
#define LPUART_STATE_ENABLE                   LPUART_CR1_UE       /*!< LPUART enabled   */
/**
  * @}
  */

/** @defgroup LPUART_ClockPrescaler  LPUART Clock Prescaler
  * @{
  */
#define LPUART_PRESCALER_DIV1    0x00000000U  /*!< fclk_pres = fclk     */
#define LPUART_PRESCALER_DIV2    0x00000001U  /*!< fclk_pres = fclk/2   */
#define LPUART_PRESCALER_DIV4    0x00000002U  /*!< fclk_pres = fclk/4   */
#define LPUART_PRESCALER_DIV6    0x00000003U  /*!< fclk_pres = fclk/6   */
#define LPUART_PRESCALER_DIV8    0x00000004U  /*!< fclk_pres = fclk/8   */
#define LPUART_PRESCALER_DIV10   0x00000005U  /*!< fclk_pres = fclk/10  */
#define LPUART_PRESCALER_DIV12   0x00000006U  /*!< fclk_pres = fclk/12  */
#define LPUART_PRESCALER_DIV16   0x00000007U  /*!< fclk_pres = fclk/16  */
#define LPUART_PRESCALER_DIV32   0x00000008U  /*!< fclk_pres = fclk/32  */
#define LPUART_PRESCALER_DIV64   0x00000009U  /*!< fclk_pres = fclk/64  */
#define LPUART_PRESCALER_DIV128  0x0000000AU  /*!< fclk_pres = fclk/128 */
#define LPUART_PRESCALER_DIV256  0x0000000BU  /*!< fclk_pres = fclk/256 */
/**
  * @}
  */

/** @defgroup LPUART_DMA_Tx    LPUART DMA Tx
  * @{
  */
#define LPUART_DMA_TX_DISABLE                 0x00000000U                /*!< LPUART DMA TX disabled */
#define LPUART_DMA_TX_ENABLE                  LPUART_CR3_DMAT            /*!< LPUART DMA TX enabled  */
/**
  * @}
  */

/** @defgroup LPUART_DMA_Rx   LPUART DMA Rx
  * @{
  */
#define LPUART_DMA_RX_DISABLE                 0x00000000U                 /*!< LPUART DMA RX disabled */
#define LPUART_DMA_RX_ENABLE                  LPUART_CR3_DMAR             /*!< LPUART DMA RX enabled  */
/**
  * @}
  */

/** @defgroup LPUART_Half_Duplex_Selection  LPUART Half Duplex Selection
  * @{
  */
#define LPUART_HALF_DUPLEX_DISABLE            0x00000000U                 /*!< LPUART half-duplex disabled */
#define LPUART_HALF_DUPLEX_ENABLE             LPUART_CR3_HDSEL            /*!< LPUART half-duplex enabled  */
/**
  * @}
  */

/** @defgroup LPUART_WakeUp_Methods   LPUART WakeUp Methods
  * @{
  */
#define LPUART_WAKEUPMETHOD_IDLELINE          0x00000000U                 /*!< LPUART wake-up on idle line    */
#define LPUART_WAKEUPMETHOD_ADDRESSMARK       LPUART_CR1_WAKE             /*!< LPUART wake-up on address mark */
/**
  * @}
  */

/** @defgroup LPUART_Request_Parameters LPUART Request Parameters
  * @{
  */
#define LPUART_SENDBREAK_REQUEST              LPUART_RQR_SBKRQ        /*!< Send Break Request          */
#define LPUART_MUTE_MODE_REQUEST              LPUART_RQR_MMRQ         /*!< Mute Mode Request           */
#define LPUART_RXDATA_FLUSH_REQUEST           LPUART_RQR_RXFRQ        /*!< Receive Data flush Request  */
#define LPUART_TXDATA_FLUSH_REQUEST           LPUART_RQR_TXFRQ        /*!< Transmit data flush Request */
/**
  * @}
  */

/** @defgroup LPUART_Advanced_Features_Initialization_Type  LPUART Advanced Feature Initialization Type
  * @{
  */
#define LPUART_ADVFEATURE_NO_INIT                 0x00000000U          /*!< No advanced feature initialization       */
#define LPUART_ADVFEATURE_TXINVERT_INIT           0x00000001U          /*!< TX pin active level inversion            */
#define LPUART_ADVFEATURE_RXINVERT_INIT           0x00000002U          /*!< RX pin active level inversion            */
#define LPUART_ADVFEATURE_DATAINVERT_INIT         0x00000004U          /*!< Binary data inversion                    */
#define LPUART_ADVFEATURE_SWAP_INIT               0x00000008U          /*!< TX/RX pins swap                          */
#define LPUART_ADVFEATURE_RXOVERRUNDISABLE_INIT   0x00000010U          /*!< RX overrun disable                       */
#define LPUART_ADVFEATURE_DMADISABLEONERROR_INIT  0x00000020U          /*!< DMA disable on Reception Error           */
#define LPUART_ADVFEATURE_MSBFIRST_INIT           0x00000080U          /*!< Most significant bit sent/received first */
/**
  * @}
  */

/** @defgroup LPUART_Tx_Inv LPUART Advanced Feature TX Pin Active Level Inversion
  * @{
  */
#define LPUART_ADVFEATURE_TXINV_DISABLE       0x00000000U             /*!< TX pin active level inversion disable */
#define LPUART_ADVFEATURE_TXINV_ENABLE        LPUART_CR2_TXINV        /*!< TX pin active level inversion enable  */
/**
  * @}
  */

/** @defgroup LPUART_Rx_Inv LPUART Advanced Feature RX Pin Active Level Inversion
  * @{
  */
#define LPUART_ADVFEATURE_RXINV_DISABLE       0x00000000U             /*!< RX pin active level inversion disable */
#define LPUART_ADVFEATURE_RXINV_ENABLE        LPUART_CR2_RXINV        /*!< RX pin active level inversion enable  */
/**
  * @}
  */

/** @defgroup LPUART_Data_Inv  LPUART Advanced Feature Binary Data Inversion
  * @{
  */
#define LPUART_ADVFEATURE_DATAINV_DISABLE     0x00000000U             /*!< Binary data inversion disable */
#define LPUART_ADVFEATURE_DATAINV_ENABLE      LPUART_CR2_DATAINV      /*!< Binary data inversion enable  */
/**
  * @}
  */

/** @defgroup LPUART_Rx_Tx_Swap LPUART Advanced Feature RX TX Pins Swap
  * @{
  */
#define LPUART_ADVFEATURE_SWAP_DISABLE        0x00000000U             /*!< TX/RX pins swap disable */
#define LPUART_ADVFEATURE_SWAP_ENABLE         LPUART_CR2_SWAP         /*!< TX/RX pins swap enable  */
/**
  * @}
  */

/** @defgroup LPUART_Overrun_Disable  LPUART Advanced Feature Overrun Disable
  * @{
  */
#define LPUART_ADVFEATURE_OVERRUN_ENABLE      0x00000000U             /*!< RX overrun enable  */
#define LPUART_ADVFEATURE_OVERRUN_DISABLE     LPUART_CR3_OVRDIS       /*!< RX overrun disable */
/**
  * @}
  */

/** @defgroup LPUART_DMA_Disable_on_Rx_Error   LPUART Advanced Feature DMA Disable On Rx Error
  * @{
  */
#define LPUART_ADVFEATURE_DMA_ENABLEONRXERROR    0x00000000U          /*!< DMA enable on Reception Error  */
#define LPUART_ADVFEATURE_DMA_DISABLEONRXERROR   LPUART_CR3_DDRE      /*!< DMA disable on Reception Error */
/**
  * @}
  */

/** @defgroup LPUART_MSB_First   LPUART Advanced Feature MSB First
  * @{
  */
#define LPUART_ADVFEATURE_MSBFIRST_DISABLE    0x00000000U             /*!< Most significant bit sent/received
                                                                           first disable                      */
#define LPUART_ADVFEATURE_MSBFIRST_ENABLE     LPUART_CR2_MSBFIRST     /*!< Most significant bit sent/received
                                                                           first enable                       */
/**
  * @}
  */

/** @defgroup LPUART_TXOE_ALWAYS_ON   LPUART Advanced Feature TXOE always on
  * @{
  */
#define LPUART_ADVFEATURE_TXOEALWAYSON_DISABLE    0x00000000U               /*!< LPUART output control by hardware */
#define LPUART_ADVFEATURE_TXOEALWAYSON_ENABLE     LPUART_CR2_TXOE_ALWAYS_ON /*!< LPUART output control by software */
/**
  * @}
  */

/** @defgroup LPUART_Stop_Mode_Enable   LPUART Advanced Feature Stop Mode Enable
  * @{
  */
#define LPUART_ADVFEATURE_STOPMODE_DISABLE    0x00000000U             /*!< LPUART stop mode disable */
#define LPUART_ADVFEATURE_STOPMODE_ENABLE     LPUART_CR1_UESM         /*!< LPUART stop mode enable  */
/**
  * @}
  */

/** @defgroup LPUART_Mute_Mode   LPUART Advanced Feature Mute Mode Enable
  * @{
  */
#define LPUART_ADVFEATURE_MUTEMODE_DISABLE    0x00000000U             /*!< LPUART mute mode disable */
#define LPUART_ADVFEATURE_MUTEMODE_ENABLE     LPUART_CR1_MME          /*!< LPUART mute mode enable  */
/**
  * @}
  */

/** @defgroup LPUART_CR2_ADDRESS_LSB_POS    LPUART Address-matching LSB Position In CR2 Register
  * @{
  */
#define LPUART_CR2_ADDRESS_LSB_POS             24U             /*!< LPUART address-matching LSB position in CR2 register */
/**
  * @}
  */

/** @defgroup LPUART_WakeUp_from_Stop_Selection   LPUART WakeUp From Stop Selection
  * @{
  */
#define LPUART_WAKEUP_ON_ADDRESS              0x00000000U             /*!< LPUART wake-up on address                     */
#define LPUART_WAKEUP_ON_STARTBIT             LPUART_CR3_WUS_1        /*!< LPUART wake-up on start bit                   */
#define LPUART_WAKEUP_ON_READDATA_NONEMPTY    LPUART_CR3_WUS          /*!< LPUART wake-up on receive data register
                                                                           not empty or RXFIFO is not empty            */
/**
  * @}
  */

/** @defgroup LPUART_DriverEnable_Polarity      LPUART DriverEnable Polarity
  * @{
  */
#define LPUART_DE_POLARITY_HIGH               0x00000000U             /*!< Driver enable signal is active high */
#define LPUART_DE_POLARITY_LOW                LPUART_CR3_DEP          /*!< Driver enable signal is active low  */
/**
  * @}
  */

/** @defgroup LPUART_CR1_DEAT_ADDRESS_LSB_POS    LPUART Driver Enable Assertion Time LSB Position In CR1 Register
  * @{
  */
#define LPUART_CR1_DEAT_ADDRESS_LSB_POS       21U      /*!< LPUART Driver Enable assertion time LSB
                                                            position in CR1 register */
/**
  * @}
  */

/** @defgroup LPUART_CR1_DEDT_ADDRESS_LSB_POS    LPUART Driver Enable DeAssertion Time LSB Position In CR1 Register
  * @{
  */
#define LPUART_CR1_DEDT_ADDRESS_LSB_POS       16U      /*!< LPUART Driver Enable de-assertion time LSB
                                                            position in CR1 register */
/**
  * @}
  */

/** @defgroup LPUART_TimeOut_Value    LPUART polling-based communications time-out value
  * @{
  */
#define HAL_LPUART_TIMEOUT_VALUE              0x1FFFFFFU  /*!< LPUART polling-based communications time-out value */
/**
  * @}
  */

/** @defgroup LPUART_Flags     LPUART Status Flags
  *        Elements values convention: 0xXXXX
  *           - 0xXXXX  : Flag mask in the ISR register
  * @{
  */
#define LPUART_FLAG_TXFT                      LPUART_ISR_TXFT          /*!< LPUART TXFIFO threshold flag                */
#define LPUART_FLAG_RXFT                      LPUART_ISR_RXFT          /*!< LPUART RXFIFO threshold flag                */
#define LPUART_FLAG_RXFF                      LPUART_ISR_RXFF          /*!< LPUART RXFIFO Full flag                     */
#define LPUART_FLAG_TXFE                      LPUART_ISR_TXFE          /*!< LPUART TXFIFO Empty flag                    */
#define LPUART_FLAG_REACK                     LPUART_ISR_REACK         /*!< LPUART receive enable acknowledge flag      */
#define LPUART_FLAG_TEACK                     LPUART_ISR_TEACK         /*!< LPUART transmit enable acknowledge flag     */
#define LPUART_FLAG_WUF                       LPUART_ISR_WUF           /*!< LPUART wake-up from stop mode flag          */
#define LPUART_FLAG_RWU                       LPUART_ISR_RWU           /*!< LPUART receiver wake-up from mute mode flag */
#define LPUART_FLAG_SBKF                      LPUART_ISR_SBKF          /*!< LPUART send break flag                      */
#define LPUART_FLAG_CMF                       LPUART_ISR_CMF           /*!< LPUART character match flag                 */
#define LPUART_FLAG_BUSY                      LPUART_ISR_BUSY          /*!< LPUART busy flag                            */
#define LPUART_FLAG_CTS                       LPUART_ISR_CTS           /*!< LPUART clear to send flag                   */
#define LPUART_FLAG_CTSIF                     LPUART_ISR_CTSIF         /*!< LPUART clear to send interrupt flag         */
#define LPUART_FLAG_TXE                       LPUART_ISR_TXE           /*!< LPUART transmit data register empty         */
#define LPUART_FLAG_TC                        LPUART_ISR_TC            /*!< LPUART transmission complete                */
#define LPUART_FLAG_RXNE                      LPUART_ISR_RXNE          /*!< LPUART read data register not empty         */
#define LPUART_FLAG_IDLE                      LPUART_ISR_IDLE          /*!< LPUART idle flag                            */
#define LPUART_FLAG_ORE                       LPUART_ISR_ORE           /*!< LPUART overrun error                        */
#define LPUART_FLAG_NE                        LPUART_ISR_NE            /*!< LPUART noise error                          */
#define LPUART_FLAG_FE                        LPUART_ISR_FE            /*!< LPUART frame error                          */
#define LPUART_FLAG_PE                        LPUART_ISR_PE            /*!< LPUART parity error                         */
/**
  * @}
  */
/** @brief LPUART interruptions flag mask
  *
  * @{
  */
#define LPUART_IT_MASK                     0x0000001FU

#define LPUART_CR1_REG_INDEX               1U
#define LPUART_CR2_REG_INDEX               2U
#define LPUART_CR3_REG_INDEX               3U
/**
  * @}
  */

/** @defgroup LPUART_Interrupt_definition LPUART Interrupts Definition
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
#define LPUART_IT_RXFF                        0x183FU        /*!< LPUART RXFIFO full interruption                  */
#define LPUART_IT_TXFE                        0x173EU        /*!< LPUART TXFIFO empty interruption                 */
#define LPUART_IT_IDLE                        0x0424U        /*!< LPUART idle interruption                         */
#define LPUART_IT_PE                          0x0028U        /*!< LPUART parity error interruption                 */
#define LPUART_IT_RXNE                        0x0525U        /*!< LPUART read data register not empty interruption */
#define LPUART_IT_TC                          0x0626U        /*!< LPUART transmission complete interruption        */
#define LPUART_IT_TXE                         0x0727U        /*!< LPUART transmit data register empty interruption */
#define LPUART_IT_CM                          0x112EU        /*!< LPUART Character Matching Interrupt interruption */
#define LPUART_IT_RXFT                        0x1A7CU        /*!< LPUART RXFIFO threshold reached interruption     */
#define LPUART_IT_TXFT                        0x1B77U        /*!< LPUART TXFIFO threshold reached interruption     */
#define LPUART_IT_WUF                         0x1476U        /*!< LPUART WUF interruption                         */
#define LPUART_IT_CTS                         0x096AU        /*!< LPUART fCTS interruption                         */
#define LPUART_IT_ERR                         0x0060U        /*!< LPUART error interruption                        */

#define LPUART_IT_ORE                         0x0300U        /*!< LPUART overrun error interruption                */
#define LPUART_IT_NE                          0x0200U        /*!< LPUART noise error interruption                  */
#define LPUART_IT_FE                          0x0100U        /*!< LPUART frame error interruption                  */

/**
  * @}
  */

/** @defgroup LPUART_IT_CLEAR_Flags  LPUART Interruption Clear Flags
  * @{
  */
#define LPUART_CLEAR_PEF                       LPUART_ICR_PECF            /*!< Parity Error Clear Flag           */
#define LPUART_CLEAR_FEF                       LPUART_ICR_FECF            /*!< Framing Error Clear Flag          */
#define LPUART_CLEAR_NEF                       LPUART_ICR_NECF            /*!< Noise Error detected Clear Flag   */
#define LPUART_CLEAR_OREF                      LPUART_ICR_ORECF           /*!< Overrun Error Clear Flag          */
#define LPUART_CLEAR_IDLEF                     LPUART_ICR_IDLECF          /*!< IDLE line detected Clear Flag     */
#define LPUART_CLEAR_TCF                       LPUART_ICR_TCCF            /*!< Transmission Complete Clear Flag  */
#define LPUART_CLEAR_CTSF                      LPUART_ICR_CTSCF           /*!< CTS Interrupt Clear Flag          */
#define LPUART_CLEAR_CMF                       LPUART_ICR_CMCF            /*!< Character Match Clear Flag        */
#define LPUART_CLEAR_WUF                       LPUART_ICR_WUCF            /*!< Wake Up from stop mode Clear Flag */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup LPUART_Exported_Macros LPUART Exported Macros
  * @{
  */

/** @brief  Reset LPUART handle states.
  * @param  __HANDLE__ LPUART handle.
  * @retval None
  */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
#define __HAL_LPUART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                         (__HANDLE__)->gState = HAL_LPUART_STATE_RESET;      \
                                                         (__HANDLE__)->RxState = HAL_LPUART_STATE_RESET;     \
                                                         (__HANDLE__)->MspInitCallback = NULL;             \
                                                         (__HANDLE__)->MspDeInitCallback = NULL;           \
                                                       } while(0U)
#else
#define __HAL_LPUART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                         (__HANDLE__)->gState = HAL_LPUART_STATE_RESET;      \
                                                         (__HANDLE__)->RxState = HAL_LPUART_STATE_RESET;     \
                                                       } while(0U)
#endif /*USE_HAL_LPUART_REGISTER_CALLBACKS */

/** @brief  Flush the LPUART Data registers.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_FLUSH_DRREGISTER(__HANDLE__)  \
  do{                \
    SET_BIT((__HANDLE__)->Instance->RQR, LPUART_RXDATA_FLUSH_REQUEST); \
    SET_BIT((__HANDLE__)->Instance->RQR, LPUART_TXDATA_FLUSH_REQUEST); \
  }  while(0U)

/** @brief  Clear the specified LPUART pending flag.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @param  __FLAG__ specifies the flag to check.
  *          This parameter can be any combination of the following values:
  *            @arg @ref LPUART_CLEAR_PEF      Parity Error Clear Flag
  *            @arg @ref LPUART_CLEAR_FEF      Framing Error Clear Flag
  *            @arg @ref LPUART_CLEAR_NEF      Noise detected Clear Flag
  *            @arg @ref LPUART_CLEAR_OREF     Overrun Error Clear Flag
  *            @arg @ref LPUART_CLEAR_IDLEF    IDLE line detected Clear Flag
  *            @arg @ref LPUART_CLEAR_TCF      Transmission Complete Clear Flag
  *            @arg @ref LPUART_CLEAR_CTSF     CTS Interrupt Clear Flag
  *            @arg @ref LPUART_CLEAR_CMF      Character Match Clear Flag
  *            @arg @ref LPUART_CLEAR_WUF      Wake Up from stop mode Clear Flag
  * @retval None
  */
#define __HAL_LPUART_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ICR = (__FLAG__))

/** @brief  Clear the LPUART PE pending flag.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_CLEAR_PEFLAG(__HANDLE__)   __HAL_LPUART_CLEAR_FLAG((__HANDLE__), LPUART_CLEAR_PEF)

/** @brief  Clear the LPUART FE pending flag.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_CLEAR_FEFLAG(__HANDLE__)   __HAL_LPUART_CLEAR_FLAG((__HANDLE__), LPUART_CLEAR_FEF)

/** @brief  Clear the LPUART NE pending flag.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_CLEAR_NEFLAG(__HANDLE__)  __HAL_LPUART_CLEAR_FLAG((__HANDLE__), LPUART_CLEAR_NEF)

/** @brief  Clear the LPUART ORE pending flag.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_CLEAR_OREFLAG(__HANDLE__)   __HAL_LPUART_CLEAR_FLAG((__HANDLE__), LPUART_CLEAR_OREF)

/** @brief  Clear the LPUART IDLE pending flag.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_CLEAR_IDLEFLAG(__HANDLE__)   __HAL_LPUART_CLEAR_FLAG((__HANDLE__), LPUART_CLEAR_IDLEF)

/** @brief  Check whether the specified LPUART flag is set or not.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @param  __FLAG__ specifies the flag to check.
  *        This parameter can be one of the following values:
  *            @arg @ref LPUART_FLAG_TXFT  TXFIFO threshold flag
  *            @arg @ref LPUART_FLAG_RXFT  RXFIFO threshold flag
  *            @arg @ref LPUART_FLAG_RXFF  RXFIFO Full flag
  *            @arg @ref LPUART_FLAG_TXFE  TXFIFO Empty flag
  *            @arg @ref LPUART_FLAG_REACK Receive enable acknowledge flag
  *            @arg @ref LPUART_FLAG_TEACK Transmit enable acknowledge flag
  *            @arg @ref LPUART_FLAG_WUF   Wake up from stop mode flag
  *            @arg @ref LPUART_FLAG_RWU   Receiver wake up flag (if the LPUART in mute mode)
  *            @arg @ref LPUART_FLAG_SBKF  Send Break flag
  *            @arg @ref LPUART_FLAG_CMF   Character match flag
  *            @arg @ref LPUART_FLAG_BUSY  Busy flag
  *            @arg @ref LPUART_FLAG_CTS   CTS Change flag
  *            @arg @ref LPUART_FLAG_TXE   Transmit data register empty flag
  *            @arg @ref LPUART_FLAG_TC    Transmission Complete flag
  *            @arg @ref LPUART_FLAG_RXNE  Receive data register not empty flag
  *            @arg @ref LPUART_FLAG_IDLE  Idle Line detection flag
  *            @arg @ref LPUART_FLAG_ORE   Overrun Error flag
  *            @arg @ref LPUART_FLAG_NE    Noise Error flag
  *            @arg @ref LPUART_FLAG_FE    Framing Error flag
  *            @arg @ref LPUART_FLAG_PE    Parity Error flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_LPUART_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->ISR & (__FLAG__)) == (__FLAG__))

/** @brief  Enable the specified LPUART interrupt.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @param  __INTERRUPT__ specifies the LPUART interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg @ref LPUART_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref LPUART_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref LPUART_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref LPUART_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref LPUART_IT_WUF   Wakeup from stop mode interrupt
  *            @arg @ref LPUART_IT_CM    Character match interrupt
  *            @arg @ref LPUART_IT_CTS   CTS change interrupt
  *            @arg @ref LPUART_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref LPUART_IT_TC    Transmission complete interrupt
  *            @arg @ref LPUART_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref LPUART_IT_IDLE  Idle line detection interrupt
  *            @arg @ref LPUART_IT_PE    Parity Error interrupt
  *            @arg @ref LPUART_IT_ERR   Error interrupt (frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_LPUART_ENABLE_IT(__HANDLE__, __INTERRUPT__) ( \
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == LPUART_CR1_REG_INDEX)?\
                                                           ((__HANDLE__)->Instance->CR1 |= (1U << ((__INTERRUPT__) & LPUART_IT_MASK))): \
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == LPUART_CR2_REG_INDEX)?\
                                                           ((__HANDLE__)->Instance->CR2 |= (1U << ((__INTERRUPT__) & LPUART_IT_MASK))): \
                                                           ((__HANDLE__)->Instance->CR3 |= (1U << ((__INTERRUPT__) & LPUART_IT_MASK))))

/** @brief  Disable the specified LPUART interrupt.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @param  __INTERRUPT__ specifies the LPUART interrupt source to disable.
  *          This parameter can be one of the following values:
  *            @arg @ref LPUART_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref LPUART_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref LPUART_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref LPUART_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref LPUART_IT_WUF   Wakeup from stop mode interrupt
  *            @arg @ref LPUART_IT_CM    Character match interrupt
  *            @arg @ref LPUART_IT_CTS   CTS change interrupt
  *            @arg @ref LPUART_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref LPUART_IT_TC    Transmission complete interrupt
  *            @arg @ref LPUART_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref LPUART_IT_IDLE  Idle line detection interrupt
  *            @arg @ref LPUART_IT_PE    Parity Error interrupt
  *            @arg @ref LPUART_IT_ERR   Error interrupt (Frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_LPUART_DISABLE_IT(__HANDLE__, __INTERRUPT__) ( \
                                                            ((((uint8_t)(__INTERRUPT__)) >> 5U) == LPUART_CR1_REG_INDEX)?\
                                                            ((__HANDLE__)->Instance->CR1 &= ~ (1U << ((__INTERRUPT__) & LPUART_IT_MASK))): \
                                                            ((((uint8_t)(__INTERRUPT__)) >> 5U) == LPUART_CR2_REG_INDEX)?\
                                                            ((__HANDLE__)->Instance->CR2 &= ~ (1U << ((__INTERRUPT__) & LPUART_IT_MASK))): \
                                                            ((__HANDLE__)->Instance->CR3 &= ~ (1U << ((__INTERRUPT__) & LPUART_IT_MASK))))

/** @brief  Check whether the specified LPUART interrupt has occurred or not.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @param  __INTERRUPT__ specifies the LPUART interrupt to check.
  *          This parameter can be one of the following values:
  *            @arg @ref LPUART_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref LPUART_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref LPUART_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref LPUART_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref LPUART_IT_WUF   Wakeup from stop mode interrupt
  *            @arg @ref LPUART_IT_CM    Character match interrupt
  *            @arg @ref LPUART_IT_CTS   CTS change interrupt
  *            @arg @ref LPUART_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref LPUART_IT_TC    Transmission complete interrupt
  *            @arg @ref LPUART_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref LPUART_IT_IDLE  Idle line detection interrupt
  *            @arg @ref LPUART_IT_PE    Parity Error interrupt
  *            @arg @ref LPUART_IT_ERR   Error interrupt (Frame error, noise error, overrun error)
  * @retval The new state of __INTERRUPT__ (SET or RESET).
  */
#define __HAL_LPUART_GET_IT(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->ISR & ((__INTERRUPT__) & LPUART_SR_MASK)) != 0U) ? SET : RESET)

/** @brief  Check whether the specified LPUART interrupt source is enabled or not.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @param  __INTERRUPT__ specifies the LPUART interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg @ref LPUART_IT_RXFF  RXFIFO Full interrupt
  *            @arg @ref LPUART_IT_TXFE  TXFIFO Empty interrupt
  *            @arg @ref LPUART_IT_RXFT  RXFIFO threshold interrupt
  *            @arg @ref LPUART_IT_TXFT  TXFIFO threshold interrupt
  *            @arg @ref LPUART_IT_WUF   Wakeup from stop mode interrupt
  *            @arg @ref LPUART_IT_CM    Character match interrupt
  *            @arg @ref LPUART_IT_CTS   CTS change interrupt
  *            @arg @ref LPUART_IT_TXE   Transmit Data Register empty interrupt
  *            @arg @ref LPUART_IT_TC    Transmission complete interrupt
  *            @arg @ref LPUART_IT_RXNE  Receive Data register not empty interrupt
  *            @arg @ref LPUART_IT_IDLE  Idle line detection interrupt
  *            @arg @ref LPUART_IT_PE    Parity Error interrupt
  *            @arg @ref LPUART_IT_ERR   Error interrupt (Frame error, noise error, overrun error)
  * @retval The new state of __INTERRUPT__ (SET or RESET).
  */
#define __HAL_LPUART_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ( \
                                                               (((((((uint8_t)(__INTERRUPT__)) >> 5U) == LPUART_CR1_REG_INDEX) ? (__HANDLE__)->Instance->CR1 : \
                                                                 (((((uint8_t)(__INTERRUPT__)) >> 5U) == LPUART_CR2_REG_INDEX) ? (__HANDLE__)->Instance->CR2 : \
                                                                   (__HANDLE__)->Instance->CR3)) & (1U << (((uint16_t)(__INTERRUPT__)) & LPUART_IT_MASK))) != RESET) ? SET : RESET)

/** @brief  Clear the specified LPUART ISR flag, in setting the proper ICR register flag.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @param  __IT_CLEAR__ specifies the interrupt clear register flag that needs to be set
  *                       to clear the corresponding interrupt
  *          This parameter can be one of the following values:
  *            @arg @ref LPUART_CLEAR_PEF    Parity Error Clear Flag
  *            @arg @ref LPUART_CLEAR_FEF    Framing Error Clear Flag
  *            @arg @ref LPUART_CLEAR_NEF    Noise detected Clear Flag
  *            @arg @ref LPUART_CLEAR_OREF   Overrun Error Clear Flag
  *            @arg @ref LPUART_CLEAR_IDLEF  IDLE line detected Clear Flag
  *            @arg @ref LPUART_CLEAR_TCF    Transmission Complete Clear Flag
  *            @arg @ref LPUART_CLEAR_CTSF   CTS Interrupt Clear Flag
  *            @arg @ref LPUART_CLEAR_CMF    Character Match Clear Flag
  *            @arg @ref LPUART_CLEAR_WUF    Wake Up from stop mode Clear Flag
  * @retval None
  */
#define __HAL_LPUART_CLEAR_IT(__HANDLE__, __IT_CLEAR__) ((__HANDLE__)->Instance->ICR = (uint32_t)(__IT_CLEAR__))

/** @brief  Set a specific LPUART request flag.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @param  __REQ__ specifies the request flag to set
  *          This parameter can be one of the following values:
  *            @arg @ref LPUART_SENDBREAK_REQUEST Send Break Request
  *            @arg @ref LPUART_MUTE_MODE_REQUEST Mute Mode Request
  *            @arg @ref LPUART_RXDATA_FLUSH_REQUEST Receive Data flush Request
  *            @arg @ref LPUART_TXDATA_FLUSH_REQUEST Transmit data flush Request
  * @retval None
  */
#define __HAL_LPUART_SEND_REQ(__HANDLE__, __REQ__) ((__HANDLE__)->Instance->RQR |= (uint16_t)(__REQ__))

/** @brief  Enable LPUART.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_ENABLE(__HANDLE__)                   ((__HANDLE__)->Instance->CR1 |= LPUART_CR1_UE)

/** @brief  Disable LPUART.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_DISABLE(__HANDLE__)                  ((__HANDLE__)->Instance->CR1 &= ~LPUART_CR1_UE)

/** @brief  Enable CTS flow control.
  * @note   This macro allows to enable CTS hardware flow control for a given LPUART instance,
  *         without need to call HAL_LPUART_Init() function.
  *         As involving direct access to LPUART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying CTS Hw flow control feature activation, without need
  *         for LPUART instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - LPUART instance should have already been initialised (through call of HAL_LPUART_Init() )
  *           - macro could only be called when corresponding LPUART instance is disabled
  *             (i.e. __HAL_LPUART_DISABLE(__HANDLE__)) and should be followed by an Enable
  *              macro (i.e. __HAL_LPUART_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_HWCONTROL_CTS_ENABLE(__HANDLE__)        \
  do{                                                       \
    SET_BIT((__HANDLE__)->Instance->CR3, LPUART_CR3_CTSE);  \
    (__HANDLE__)->Init.HwFlowCtl |= LPUART_CR3_CTSE;        \
  } while(0U)

/** @brief  Disable CTS flow control.
  * @note   This macro allows to disable CTS hardware flow control for a given LPUART instance,
  *         without need to call HAL_LPUART_Init() function.
  *         As involving direct access to LPUART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying CTS Hw flow control feature activation, without need
  *         for LPUART instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - LPUART instance should have already been initialised (through call of HAL_LPUART_Init() )
  *           - macro could only be called when corresponding LPUART instance is disabled
  *             (i.e. __HAL_LPUART_DISABLE(__HANDLE__)) and should be followed by an Enable
  *              macro (i.e. __HAL_LPUART_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_HWCONTROL_CTS_DISABLE(__HANDLE__)        \
  do{                                                       \
    CLEAR_BIT((__HANDLE__)->Instance->CR3, LPUART_CR3_CTSE); \
    (__HANDLE__)->Init.HwFlowCtl &= ~(LPUART_CR3_CTSE);      \
  } while(0U)

/** @brief  Enable RTS flow control.
  * @note   This macro allows to enable RTS hardware flow control for a given LPUART instance,
  *         without need to call HAL_LPUART_Init() function.
  *         As involving direct access to LPUART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying RTS Hw flow control feature activation, without need
  *         for LPUART instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - LPUART instance should have already been initialised (through call of HAL_LPUART_Init() )
  *           - macro could only be called when corresponding LPUART instance is disabled
  *             (i.e. __HAL_LPUART_DISABLE(__HANDLE__)) and should be followed by an Enable
  *              macro (i.e. __HAL_LPUART_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_HWCONTROL_RTS_ENABLE(__HANDLE__)       \
  do{                                                     \
    SET_BIT((__HANDLE__)->Instance->CR3, LPUART_CR3_RTSE); \
    (__HANDLE__)->Init.HwFlowCtl |= LPUART_CR3_RTSE;       \
  } while(0U)

/** @brief  Disable RTS flow control.
  * @note   This macro allows to disable RTS hardware flow control for a given LPUART instance,
  *         without need to call HAL_LPUART_Init() function.
  *         As involving direct access to LPUART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying RTS Hw flow control feature activation, without need
  *         for LPUART instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - LPUART instance should have already been initialised (through call of HAL_LPUART_Init() )
  *           - macro could only be called when corresponding LPUART instance is disabled
  *             (i.e. __HAL_LPUART_DISABLE(__HANDLE__)) and should be followed by an Enable
  *              macro (i.e. __HAL_LPUART_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval None
  */
#define __HAL_LPUART_HWCONTROL_RTS_DISABLE(__HANDLE__)       \
  do{                                                      \
    CLEAR_BIT((__HANDLE__)->Instance->CR3, LPUART_CR3_RTSE);\
    (__HANDLE__)->Init.HwFlowCtl &= ~(LPUART_CR3_RTSE);     \
  } while(0U)
/**
  * @}
  */

/* Private macros --------------------------------------------------------*/
/** @defgroup LPUART_Private_Macros   LPUART Private Macros
  * @{
  */
/** @brief  Get LPUART clok division factor from clock prescaler value.
  * @param  __CLOCKPRESCALER__ LPUART prescaler value.
  * @retval LPUART clock division factor
  */
#define LPUART_GET_DIV_FACTOR(__CLOCKPRESCALER__) \
  (((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV1)   ? 1U :       \
   ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV2)   ? 2U :       \
   ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV4)   ? 4U :       \
   ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV6)   ? 6U :       \
   ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV8)   ? 8U :       \
   ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV10)  ? 10U :      \
   ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV12)  ? 12U :      \
   ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV16)  ? 16U :      \
   ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV32)  ? 32U :      \
   ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV64)  ? 64U :      \
   ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV128) ? 128U :     \
   ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV256) ? 256U : 1U)


/** @brief  BRR division operation to set BRR register with LPUART.
  * @param  __PCLK__ LPUART clock.
  * @param  __BAUD__ Baud rate set by the user.
  * @param  __CLOCKPRESCALER__ LPUART prescaler value.
  * @retval Division result
  */
#define LPUART_DIV_LPUART(__PCLK__, __BAUD__, __CLOCKPRESCALER__)                        \
  ((uint32_t)((((((uint64_t)(__PCLK__))/(LPUARTPrescTable[(__CLOCKPRESCALER__)]))*256U)+ \
               (uint32_t)((__BAUD__)/2U)) / (__BAUD__))                                \
  )

/** @brief  BRR division operation to set BRR register in 8-bit oversampling mode.
  * @param  __PCLK__ LPUART clock.
  * @param  __BAUD__ Baud rate set by the user.
  * @param  __CLOCKPRESCALER__ LPUART prescaler value.
  * @retval Division result
  */
#define LPUART_DIV_SAMPLING8(__PCLK__, __BAUD__, __CLOCKPRESCALER__)                        \
  (((((__PCLK__)/LPUARTPrescTable[(__CLOCKPRESCALER__)])*2U) + ((__BAUD__)/2U)) / (__BAUD__))

/** @brief  BRR division operation to set BRR register in 16-bit oversampling mode.
  * @param  __PCLK__ LPUART clock.
  * @param  __BAUD__ Baud rate set by the user.
  * @param  __CLOCKPRESCALER__ LPUART prescaler value.
  * @retval Division result
  */
#define LPUART_DIV_SAMPLING16(__PCLK__, __BAUD__, __CLOCKPRESCALER__)                       \
  ((((__PCLK__)/LPUARTPrescTable[(__CLOCKPRESCALER__)]) + ((__BAUD__)/2U)) / (__BAUD__))

/** @brief  Check whether or not LPUART instance is Low Power LPUART.
  * @param  __HANDLE__ specifies the LPUART Handle.
  * @retval SET (instance is LPUART) or RESET (instance isn't LPUART)
  */
#define LPUART_INSTANCE_LOWPOWER(__HANDLE__) (IS_LPUART_INSTANCE((__HANDLE__)->Instance))

/** @brief  Check LPUART Baud rate.
  * @param  __BAUDRATE__ Baudrate specified by the user.
  *         The maximum Baud Rate is derived from the maximum clock on E4
  *         divided by the smallest oversampling used on the LPUART
  * @retval SET (__BAUDRATE__ is valid) or RESET (__BAUDRATE__ is invalid)
  */
#define IS_LPUART_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) < 18750001U)

/** @brief  Check LPUART assertion time.
  * @param  __TIME__ 5-bit value assertion time.
  * @retval Test result (TRUE or FALSE).
  */
#define IS_LPUART_ASSERTIONTIME(__TIME__)    ((__TIME__) <= 0x1FU)

/** @brief  Check LPUART deassertion time.
  * @param  __TIME__ 5-bit value deassertion time.
  * @retval Test result (TRUE or FALSE).
  */
#define IS_LPUART_DEASSERTIONTIME(__TIME__) ((__TIME__) <= 0x1FU)

/**
  * @brief Ensure that LPUART frame number of stop bits is valid.
  * @param __STOPBITS__ LPUART frame number of stop bits.
  * @retval SET (__STOPBITS__ is valid) or RESET (__STOPBITS__ is invalid)
  */
#define IS_LPUART_STOPBITS(__STOPBITS__) (((__STOPBITS__) == LPUART_STOPBITS_1) || \
                                          ((__STOPBITS__) == LPUART_STOPBITS_2))

/**
  * @brief Ensure that LPUART frame parity is valid.
  * @param __PARITY__ LPUART frame parity.
  * @retval SET (__PARITY__ is valid) or RESET (__PARITY__ is invalid)
  */
#define IS_LPUART_PARITY(__PARITY__) (((__PARITY__) == LPUART_PARITY_NONE) || \
                                      ((__PARITY__) == LPUART_PARITY_EVEN) || \
                                      ((__PARITY__) == LPUART_PARITY_ODD))

/**
  * @brief Ensure that LPUART hardware flow control is valid.
  * @param __CONTROL__ LPUART hardware flow control.
  * @retval SET (__CONTROL__ is valid) or RESET (__CONTROL__ is invalid)
  */
#define IS_LPUART_HARDWARE_FLOW_CONTROL(__CONTROL__)\
  (((__CONTROL__) == LPUART_HWCONTROL_NONE) || \
   ((__CONTROL__) == LPUART_HWCONTROL_RTS)  || \
   ((__CONTROL__) == LPUART_HWCONTROL_CTS)  || \
   ((__CONTROL__) == LPUART_HWCONTROL_RTS_CTS))

/**
  * @brief Ensure that LPUART communication mode is valid.
  * @param __MODE__ LPUART communication mode.
  * @retval SET (__MODE__ is valid) or RESET (__MODE__ is invalid)
  */
#define IS_LPUART_MODE(__MODE__) ((((__MODE__) & (~((uint32_t)(LPUART_MODE_TX_RX)))) == 0x00U) && ((__MODE__) != 0x00U))

/**
  * @brief Ensure that LPUART state is valid.
  * @param __STATE__ LPUART state.
  * @retval SET (__STATE__ is valid) or RESET (__STATE__ is invalid)
  */
#define IS_LPUART_STATE(__STATE__) (((__STATE__) == LPUART_STATE_DISABLE) || \
                                    ((__STATE__) == LPUART_STATE_ENABLE))

/**
  * @brief Ensure that LPUART DMA TX state is valid.
  * @param __DMATX__ LPUART DMA TX state.
  * @retval SET (__DMATX__ is valid) or RESET (__DMATX__ is invalid)
  */
#define IS_LPUART_DMA_TX(__DMATX__)     (((__DMATX__) == LPUART_DMA_TX_DISABLE) || \
                                         ((__DMATX__) == LPUART_DMA_TX_ENABLE))

/**
  * @brief Ensure that LPUART DMA RX state is valid.
  * @param __DMARX__ LPUART DMA RX state.
  * @retval SET (__DMARX__ is valid) or RESET (__DMARX__ is invalid)
  */
#define IS_LPUART_DMA_RX(__DMARX__)     (((__DMARX__) == LPUART_DMA_RX_DISABLE) || \
                                         ((__DMARX__) == LPUART_DMA_RX_ENABLE))

/**
  * @brief Ensure that LPUART half-duplex state is valid.
  * @param __HDSEL__ LPUART half-duplex state.
  * @retval SET (__HDSEL__ is valid) or RESET (__HDSEL__ is invalid)
  */
#define IS_LPUART_HALF_DUPLEX(__HDSEL__)     (((__HDSEL__) == LPUART_HALF_DUPLEX_DISABLE) || \
                                              ((__HDSEL__) == LPUART_HALF_DUPLEX_ENABLE))

/**
  * @brief Ensure that LPUART wake-up method is valid.
  * @param __WAKEUP__ LPUART wake-up method .
  * @retval SET (__WAKEUP__ is valid) or RESET (__WAKEUP__ is invalid)
  */
#define IS_LPUART_WAKEUPMETHOD(__WAKEUP__) (((__WAKEUP__) == LPUART_WAKEUPMETHOD_IDLELINE) || \
                                            ((__WAKEUP__) == LPUART_WAKEUPMETHOD_ADDRESSMARK))

/**
  * @brief Ensure that LPUART request parameter is valid.
  * @param __PARAM__ LPUART request parameter.
  * @retval SET (__PARAM__ is valid) or RESET (__PARAM__ is invalid)
  */
#define IS_LPUART_REQUEST_PARAMETER(__PARAM__) (((__PARAM__) == LPUART_SENDBREAK_REQUEST)    || \
                                                ((__PARAM__) == LPUART_MUTE_MODE_REQUEST)    || \
                                                ((__PARAM__) == LPUART_RXDATA_FLUSH_REQUEST) || \
                                                ((__PARAM__) == LPUART_TXDATA_FLUSH_REQUEST))

/**
  * @brief Ensure that LPUART advanced features initialization is valid.
  * @param __INIT__ LPUART advanced features initialization.
  * @retval SET (__INIT__ is valid) or RESET (__INIT__ is invalid)
  */
#define IS_LPUART_ADVFEATURE_INIT(__INIT__) ((__INIT__) <= (LPUART_ADVFEATURE_NO_INIT                | \
                                                            LPUART_ADVFEATURE_TXINVERT_INIT          | \
                                                            LPUART_ADVFEATURE_RXINVERT_INIT          | \
                                                            LPUART_ADVFEATURE_DATAINVERT_INIT        | \
                                                            LPUART_ADVFEATURE_SWAP_INIT              | \
                                                            LPUART_ADVFEATURE_RXOVERRUNDISABLE_INIT  | \
                                                            LPUART_ADVFEATURE_DMADISABLEONERROR_INIT | \
                                                            LPUART_ADVFEATURE_MSBFIRST_INIT))

/**
  * @brief Ensure that LPUART frame TX inversion setting is valid.
  * @param __TXINV__ LPUART frame TX inversion setting.
  * @retval SET (__TXINV__ is valid) or RESET (__TXINV__ is invalid)
  */
#define IS_LPUART_ADVFEATURE_TXINV(__TXINV__) (((__TXINV__) == LPUART_ADVFEATURE_TXINV_DISABLE) || \
                                               ((__TXINV__) == LPUART_ADVFEATURE_TXINV_ENABLE))

/**
  * @brief Ensure that LPUART frame RX inversion setting is valid.
  * @param __RXINV__ LPUART frame RX inversion setting.
  * @retval SET (__RXINV__ is valid) or RESET (__RXINV__ is invalid)
  */
#define IS_LPUART_ADVFEATURE_RXINV(__RXINV__) (((__RXINV__) == LPUART_ADVFEATURE_RXINV_DISABLE) || \
                                               ((__RXINV__) == LPUART_ADVFEATURE_RXINV_ENABLE))

/**
  * @brief Ensure that LPUART frame data inversion setting is valid.
  * @param __DATAINV__ LPUART frame data inversion setting.
  * @retval SET (__DATAINV__ is valid) or RESET (__DATAINV__ is invalid)
  */
#define IS_LPUART_ADVFEATURE_DATAINV(__DATAINV__) (((__DATAINV__) == LPUART_ADVFEATURE_DATAINV_DISABLE) || \
                                                   ((__DATAINV__) == LPUART_ADVFEATURE_DATAINV_ENABLE))

/**
  * @brief Ensure that LPUART frame RX/TX pins swap setting is valid.
  * @param __SWAP__ LPUART frame RX/TX pins swap setting.
  * @retval SET (__SWAP__ is valid) or RESET (__SWAP__ is invalid)
  */
#define IS_LPUART_ADVFEATURE_SWAP(__SWAP__) (((__SWAP__) == LPUART_ADVFEATURE_SWAP_DISABLE) || \
                                             ((__SWAP__) == LPUART_ADVFEATURE_SWAP_ENABLE))

/**
  * @brief Ensure that LPUART frame overrun setting is valid.
  * @param __OVERRUN__ LPUART frame overrun setting.
  * @retval SET (__OVERRUN__ is valid) or RESET (__OVERRUN__ is invalid)
  */
#define IS_LPUART_OVERRUN(__OVERRUN__)     (((__OVERRUN__) == LPUART_ADVFEATURE_OVERRUN_ENABLE) || \
                                            ((__OVERRUN__) == LPUART_ADVFEATURE_OVERRUN_DISABLE))

/**
  * @brief Ensure that LPUART DMA enabling or disabling on error setting is valid.
  * @param __DMA__ LPUART DMA enabling or disabling on error setting.
  * @retval SET (__DMA__ is valid) or RESET (__DMA__ is invalid)
  */
#define IS_LPUART_ADVFEATURE_DMAONRXERROR(__DMA__)  (((__DMA__) == LPUART_ADVFEATURE_DMA_ENABLEONRXERROR) || \
                                                     ((__DMA__) == LPUART_ADVFEATURE_DMA_DISABLEONRXERROR))

/**
  * @brief Ensure that LPUART frame MSB first setting is valid.
  * @param __MSBFIRST__ LPUART frame MSB first setting.
  * @retval SET (__MSBFIRST__ is valid) or RESET (__MSBFIRST__ is invalid)
  */
#define IS_LPUART_ADVFEATURE_MSBFIRST(__MSBFIRST__) (((__MSBFIRST__) == LPUART_ADVFEATURE_MSBFIRST_DISABLE) || \
                                                     ((__MSBFIRST__) == LPUART_ADVFEATURE_MSBFIRST_ENABLE))

/**
  * @brief Ensure that LPUART stop mode state is valid.
  * @param __STOPMODE__ LPUART stop mode state.
  * @retval SET (__STOPMODE__ is valid) or RESET (__STOPMODE__ is invalid)
  */
#define IS_LPUART_ADVFEATURE_STOPMODE(__STOPMODE__) (((__STOPMODE__) == LPUART_ADVFEATURE_STOPMODE_DISABLE) || \
                                                     ((__STOPMODE__) == LPUART_ADVFEATURE_STOPMODE_ENABLE))

/**
  * @brief Ensure that LPUART mute mode state is valid.
  * @param __MUTE__ LPUART mute mode state.
  * @retval SET (__MUTE__ is valid) or RESET (__MUTE__ is invalid)
  */
#define IS_LPUART_MUTE_MODE(__MUTE__)       (((__MUTE__) == LPUART_ADVFEATURE_MUTEMODE_DISABLE) || \
                                             ((__MUTE__) == LPUART_ADVFEATURE_MUTEMODE_ENABLE))

/**
  * @brief Ensure that LPUART wake-up selection is valid.
  * @param __WAKE__ LPUART wake-up selection.
  * @retval SET (__WAKE__ is valid) or RESET (__WAKE__ is invalid)
  */
#define IS_LPUART_WAKEUP_SELECTION(__WAKE__) (((__WAKE__) == LPUART_WAKEUP_ON_ADDRESS)           || \
                                              ((__WAKE__) == LPUART_WAKEUP_ON_STARTBIT)          || \
                                              ((__WAKE__) == LPUART_WAKEUP_ON_READDATA_NONEMPTY))

/**
  * @brief Ensure that LPUART driver enable polarity is valid.
  * @param __POLARITY__ LPUART driver enable polarity.
  * @retval SET (__POLARITY__ is valid) or RESET (__POLARITY__ is invalid)
  */
#define IS_LPUART_DE_POLARITY(__POLARITY__)    (((__POLARITY__) == LPUART_DE_POLARITY_HIGH) || \
                                                ((__POLARITY__) == LPUART_DE_POLARITY_LOW))

/**
  * @brief Ensure that LPUART Prescaler is valid.
  * @param __CLOCKPRESCALER__ LPUART Prescaler value.
  * @retval SET (__CLOCKPRESCALER__ is valid) or RESET (__CLOCKPRESCALER__ is invalid)
  */
#define IS_LPUART_PRESCALER(__CLOCKPRESCALER__) (((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV1)   || \
                                                 ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV2)   || \
                                                 ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV4)   || \
                                                 ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV6)   || \
                                                 ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV8)   || \
                                                 ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV10)  || \
                                                 ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV12)  || \
                                                 ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV16)  || \
                                                 ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV32)  || \
                                                 ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV64)  || \
                                                 ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV128) || \
                                                 ((__CLOCKPRESCALER__) == LPUART_PRESCALER_DIV256))

/**
  * @}
  */

/* Include LPUART HAL Extended module */
#include "py32e407_hal_lpuart_ex.h"


/* Prescaler Table used in BRR computation macros.
   Declared as extern here to allow use of private LPUART macros, outside of HAL LPUART functions */
extern const uint16_t LPUARTPrescTable[12];


/* Exported functions --------------------------------------------------------*/
/** @addtogroup LPUART_Exported_Functions LPUART Exported Functions
  * @{
  */

/** @addtogroup LPUART_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */

/* Initialization and de-initialization functions  ****************************/
HAL_StatusTypeDef HAL_LPUART_Init(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_DeInit(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_MspInit(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_MspDeInit(LPUART_HandleTypeDef *hlpuart);

/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_LPUART_RegisterCallback(LPUART_HandleTypeDef *hlpuart, HAL_LPUART_CallbackIDTypeDef CallbackID,
                                              pLPUART_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_LPUART_UnRegisterCallback(LPUART_HandleTypeDef *hlpuart, HAL_LPUART_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup LPUART_Exported_Functions_Group2 IO operation functions
  * @{
  */

/* IO operation functions *****************************************************/
HAL_StatusTypeDef HAL_LPUART_Transmit(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_LPUART_Receive(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_LPUART_Transmit_IT(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_LPUART_Receive_IT(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_LPUART_Transmit_DMA(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_LPUART_Receive_DMA(LPUART_HandleTypeDef *hlpuart, uint8_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_LPUART_DMAPause(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_DMAResume(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_DMAStop(LPUART_HandleTypeDef *hlpuart);
/* Transfer Abort functions */
HAL_StatusTypeDef HAL_LPUART_Abort(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_AbortTransmit(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_AbortReceive(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_Abort_IT(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_AbortTransmit_IT(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_AbortReceive_IT(LPUART_HandleTypeDef *hlpuart);

void HAL_LPUART_IRQHandler(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_TxBlockCpltCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_TxHalfBlockCpltCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_TxSrcCpltCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_TxCpltCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_RxBlockCpltCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_RxHalfBlockCpltCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_RxDstCpltCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_RxCpltCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_ErrorCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_AbortCpltCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_AbortTransmitCpltCallback(LPUART_HandleTypeDef *hlpuart);
void HAL_LPUART_AbortReceiveCpltCallback(LPUART_HandleTypeDef *hlpuart);

/**
  * @}
  */

/** @addtogroup LPUART_Exported_Functions_Group3 Peripheral Control functions
  * @{
  */

/* Peripheral Control functions  ************************************************/
void              HAL_LPUART_ReceiverTimeout_Config(LPUART_HandleTypeDef *hlpuart, uint32_t TimeoutValue);
HAL_StatusTypeDef HAL_LPUART_EnableReceiverTimeout(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_DisableReceiverTimeout(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_MultiProcessor_EnableMuteMode(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_MultiProcessor_DisableMuteMode(LPUART_HandleTypeDef *hlpuart);
void              HAL_LPUART_MultiProcessor_EnterMuteMode(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_HalfDuplex_EnableTransmitter(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_HalfDuplex_EnableReceiver(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_HalfDuplex_Init(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef HAL_LPUART_MultiProcessor_Init(LPUART_HandleTypeDef *hlpuart, uint8_t Address, uint32_t WakeUpMethod);

/**
  * @}
  */

/** @addtogroup LPUART_Exported_Functions_Group4 Peripheral State and Error functions
  * @{
  */

/* Peripheral State and Errors functions  **************************************************/
HAL_LPUART_StateTypeDef HAL_LPUART_GetState(LPUART_HandleTypeDef *hlpuart);
uint32_t                HAL_LPUART_GetError(LPUART_HandleTypeDef *hlpuart);

/**
  * @}
  */

/**
  * @}
  */

/* Private functions -----------------------------------------------------------*/
/** @addtogroup LPUART_Private_Functions LPUART Private Functions
  * @{
  */
#if (USE_HAL_LPUART_REGISTER_CALLBACKS == 1)
void LPUART_InitCallbacksToDefault(LPUART_HandleTypeDef *hlpuart);
#endif /* USE_HAL_LPUART_REGISTER_CALLBACKS */
HAL_StatusTypeDef LPUART_SetConfig(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef LPUART_CheckIdleState(LPUART_HandleTypeDef *hlpuart);
HAL_StatusTypeDef LPUART_WaitOnFlagUntilTimeout(LPUART_HandleTypeDef *hlpuart, uint32_t Flag, FlagStatus Status,
                                              uint32_t Tickstart, uint32_t Timeout);
void LPUART_AdvFeatureConfig(LPUART_HandleTypeDef *hlpuart);

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

#endif /* PY32E407_HAL_LPUART_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
