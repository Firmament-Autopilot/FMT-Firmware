/**
  ******************************************************************************
  * @file    py32e407_ll_usart.h
  * @author  MCU Application Team
  * @brief   Header file of USART LL module.
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
#ifndef __PY32E407_LL_USART_H
#define __PY32E407_LL_USART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (USART1) || defined (USART2) || defined (USART3)

/** @defgroup USART_LL USART
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup USART_LL_Private_Constants USART Private Constants
  * @{
  */

/* Defines used for the bit position in the register and perform offsets*/
#define USART_POSITION_GTPR_GT                  USART_GTPR_GT_Pos
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup USART_LL_Private_Macros USART Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup USART_LL_ES_INIT USART Exported Init structures
  * @{
  */

/**
  * @brief LL USART Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< This field defines expected Usart communication baud rate.

                                           This feature can be modified afterwards using unitary function @ref LL_USART_SetBaudRate().*/

  uint32_t DataWidth;                 /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref USART_LL_EC_DATAWIDTH.

                                           This feature can be modified afterwards using unitary function @ref LL_USART_SetDataWidth().*/

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref USART_LL_EC_STOPBITS.

                                           This feature can be modified afterwards using unitary function @ref LL_USART_SetStopBitsLength().*/

  uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref USART_LL_EC_PARITY.

                                           This feature can be modified afterwards using unitary function @ref LL_USART_SetParity().*/

  uint32_t TransferDirection;         /*!< Specifies whether the Receive and/or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref USART_LL_EC_DIRECTION.

                                           This feature can be modified afterwards using unitary function @ref LL_USART_SetTransferDirection().*/

  uint32_t HardwareFlowControl;       /*!< Specifies whether the hardware flow control mode is enabled or disabled.
                                           This parameter can be a value of @ref USART_LL_EC_HWCONTROL.

                                           This feature can be modified afterwards using unitary function @ref LL_USART_SetHWFlowCtrl().*/

  uint32_t OverSampling;              /*!< Specifies whether USART oversampling mode is 16 or 8.
                                           This parameter can be a value of @ref USART_LL_EC_OVERSAMPLING.

                                           This feature can be modified afterwards using unitary function @ref LL_USART_SetOverSampling().*/

} LL_USART_InitTypeDef, LL_SCI_InitTypeDef;

/**
  * @brief LL USART Clock Init Structure definition
  */
typedef struct
{
  uint32_t ClockOutput;               /*!< Specifies whether the USART clock is enabled or disabled.
                                           This parameter can be a value of @ref USART_LL_EC_CLOCK.

                                           USART HW configuration can be modified afterwards using unitary functions
                                           @ref LL_USART_EnableSCLKOutput() or @ref LL_USART_DisableSCLKOutput().
                                           For more details, refer to description of this function. */

  uint32_t ClockPolarity;             /*!< Specifies the steady state of the serial clock.
                                           This parameter can be a value of @ref USART_LL_EC_POLARITY.

                                           USART HW configuration can be modified afterwards using unitary functions @ref LL_USART_SetClockPolarity().
                                           For more details, refer to description of this function. */

  uint32_t ClockPhase;                /*!< Specifies the clock transition on which the bit capture is made.
                                           This parameter can be a value of @ref USART_LL_EC_PHASE.

                                           USART HW configuration can be modified afterwards using unitary functions @ref LL_USART_SetClockPhase().
                                           For more details, refer to description of this function. */

  uint32_t LastBitClockPulse;         /*!< Specifies whether the clock pulse corresponding to the last transmitted
                                           data bit (MSB) has to be output on the SCLK pin in synchronous mode.
                                           This parameter can be a value of @ref USART_LL_EC_LASTCLKPULSE.

                                           USART HW configuration can be modified afterwards using unitary functions @ref LL_USART_SetLastClkPulseOutput().
                                           For more details, refer to description of this function. */

} LL_USART_ClockInitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup USART_LL_Exported_Constants USART Exported Constants
  * @{
  */

/** @defgroup USART_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_USART_ReadReg function
  * @{
  */
#define LL_USART_SR_PE                          USART_SR_PE                   /*!< Parity error flag */
#define LL_USART_SR_FE                          USART_SR_FE                   /*!< Framing error flag */
#define LL_USART_SR_NE                          USART_SR_NE                   /*!< Noise detected flag */
#define LL_USART_SR_ORE                         USART_SR_ORE                  /*!< Overrun error flag */
#define LL_USART_SR_IDLE                        USART_SR_IDLE                 /*!< Idle line detected flag */
#define LL_USART_SR_RXNE                        USART_SR_RXNE                 /*!< Read data register not empty flag */
#define LL_USART_SR_TC                          USART_SR_TC                   /*!< Transmission complete flag */
#define LL_USART_SR_TXE                         USART_SR_TXE                  /*!< Transmit data register empty flag */
#define LL_USART_SR_LBD                         USART_SR_LBD                  /*!< LIN break detection flag */
#define LL_USART_SR_CTS                         USART_SR_CTS                  /*!< CTS flag */
#define LL_USART_SR_ABRF                        USART_SR_ABRF                 /*!< Auto baud rate flag */
#define LL_USART_SR_ABRE                        USART_SR_ABRE                 /*!< Auto baud rate error flag */
#define LL_USART_SR_EOBF                        USART_SR_EOBF                 /*!< End of block flag */
#define LL_USART_SR_RTOF                        USART_SR_RTOF                 /*!< Receiver timeout flag */
#define LL_USART_SR_FXFT                        USART_SR_TXFT                 /*!< TX FIFO threshold flag */
#define LL_USART_SR_RXFT                        USART_SR_RXFT                 /*!< RX FIFO threshold flag */
#define LL_USART_SR_RXFF                        USART_SR_RXFF                 /*!< RX FIFO full flag */
#define LL_USART_SR_TXFE                        USART_SR_TXFE                 /*!< TX FIFO empty flag */
/**
  * @}
  */

/** @defgroup USART_LL_EC_IT IT Defines
  * @brief    IT defines which can be used with LL_USART_ReadReg and  LL_USART_WriteReg functions
  * @{
  */
#define LL_USART_CR1_IDLEIE                     USART_CR1_IDLEIE              /*!< IDLE interrupt enable */
#define LL_USART_CR1_RXNEIE                     USART_CR1_RXNEIE              /*!< Read data register not empty interrupt enable */
#define LL_USART_CR1_TCIE                       USART_CR1_TCIE                /*!< Transmission complete interrupt enable */
#define LL_USART_CR1_TXEIE                      USART_CR1_TXEIE               /*!< Transmit data register empty interrupt enable */
#define LL_USART_CR1_PEIE                       USART_CR1_PEIE                /*!< Parity error */
#define LL_USART_CR2_LBDIE                      USART_CR2_LBDIE               /*!< LIN break detection interrupt enable */
#define LL_USART_CR3_EIE                        USART_CR3_EIE                 /*!< Error interrupt enable */
#define LL_USART_CR3_CTSIE                      USART_CR3_CTSIE               /*!< CTS interrupt enable */
#define LL_USART_CR3_RTOIE                      USART_CR3_RTOIE               /*!< Receiver timeout interrupt enable */
#define LL_USART_CR3_EOBIE                      USART_CR3_EOBIE               /*!< End of Block interrupt enable */
#define LL_USART_CR3_TXFTIE                     USART_CR3_TXFTIE              /*!< TX FIFO threshold interrupt enable */
#define LL_USART_CR3_RXFTIE                     USART_CR3_RXFTIE              /*!< RX FIFO threshold interrupt enable */
#define LL_USART_CR3_RXFFIE                     USART_CR3_RXFFIE              /*!< RX FIFO full interrupt enable */
#define LL_USART_CR3_TXFEIE                     USART_CR3_TXFEIE              /*!< TX FIFO empty interrupt enable */
/**
  * @}
  */

/** @defgroup USART_LL_EC_FIFOTHRESHOLD FIFO Threshold
  * @{
  */
#define LL_USART_FIFOTHRESHOLD_1_8              0x00000000U /*!< FIFO reaches 1/8 of its depth */
#define LL_USART_FIFOTHRESHOLD_1_4              0x00000001U /*!< FIFO reaches 1/4 of its depth */
#define LL_USART_FIFOTHRESHOLD_1_2              0x00000002U /*!< FIFO reaches 1/2 of its depth */
#define LL_USART_FIFOTHRESHOLD_3_4              0x00000003U /*!< FIFO reaches 3/4 of its depth */
#define LL_USART_FIFOTHRESHOLD_7_8              0x00000004U /*!< FIFO reaches 7/8 of its depth */
#define LL_USART_FIFOTHRESHOLD_8_8              0x00000005U /*!< FIFO becomes empty for TX and full for RX */
/**
  * @}
  */

/** @defgroup USART_LL_EC_DIRECTION Communication Direction
  * @{
  */
#define LL_USART_DIRECTION_NONE                 0x00000000U                        /*!< Transmitter and Receiver are disabled */
#define LL_USART_DIRECTION_RX                   USART_CR1_RE                       /*!< Transmitter is disabled and Receiver is enabled */
#define LL_USART_DIRECTION_TX                   USART_CR1_TE                       /*!< Transmitter is enabled and Receiver is disabled */
#define LL_USART_DIRECTION_TX_RX                (USART_CR1_TE |USART_CR1_RE)       /*!< Transmitter and Receiver are enabled */
/**
  * @}
  */

/** @defgroup USART_LL_EC_PARITY Parity Control
  * @{
  */
#define LL_USART_PARITY_NONE                    0x00000000U                          /*!< Parity control disabled */
#define LL_USART_PARITY_EVEN                    USART_CR1_PCE                        /*!< Parity control enabled and Even Parity is selected */
#define LL_USART_PARITY_ODD                     (USART_CR1_PCE | USART_CR1_PS)       /*!< Parity control enabled and Odd Parity is selected */
/**
  * @}
  */

/** @defgroup USART_LL_EC_WAKEUP Wakeup
  * @{
  */
#define LL_USART_WAKEUP_IDLELINE                0x00000000U           /*!<  USART wake up from Mute mode on Idle Line */
#define LL_USART_WAKEUP_ADDRESSMARK             USART_CR1_WAKE        /*!<  USART wake up from Mute mode on Address Mark */
/**
  * @}
  */

/** @defgroup USART_LL_EC_DATAWIDTH Datawidth
  * @{
  */
#define LL_USART_DATAWIDTH_7B                   USART_CR1_M1            /*!< 7 bits word length : Start bit, 7 data bits, n stop bits */
#define LL_USART_DATAWIDTH_8B                   0x00000000U             /*!< 8 bits word length : Start bit, 8 data bits, n stop bits */
#define LL_USART_DATAWIDTH_9B                   USART_CR1_M0            /*!< 9 bits word length : Start bit, 9 data bits, n stop bits */
/**
  * @}
  */

/** @defgroup USART_LL_EC_BITORDER Bit Order
  * @{
  */
#define LL_USART_BITORDER_LSBFIRST              0x00000000U           /*!< data is transmitted/received with data bit 0 first, following the start bit */
#define LL_USART_BITORDER_MSBFIRST              USART_CR1_MSB         /*!< data is transmitted/received with the MSB first, following the start bit */
/**
  * @}
  */

/** @defgroup USART_LL_EC_TXRX TX RX Pins Swap
  * @{
  */
#define LL_USART_TXRX_STANDARD                  0x00000000U           /*!< TX/RX pins are used as defined in standard pinout */
#define LL_USART_TXRX_SWAPPED                   (USART_CR1_SWAP)      /*!< TX and RX pins functions are swapped.             */
/**
  * @}
  */

/** @defgroup USART_LL_EC_BINARY_LOGIC Binary Data Inversion
  * @{
  */
#define LL_USART_BINARY_LOGIC_POSITIVE          0x00000000U           /*!< Logical data from the data register are send/received in positive/direct logic. (1=H, 0=L) */
#define LL_USART_BINARY_LOGIC_NEGATIVE          USART_CR1_DATAINV     /*!< Logical data from the data register are send/received in negative/inverse logic. (1=L, 0=H). The parity bit is also inverted. */
/**
  * @}
  */

/** @defgroup USART_LL_EC_OVERSAMPLING Oversampling
  * @{
  */
#define LL_USART_OVERSAMPLING_16                0x00000000U            /*!< Oversampling by 16 */
#if  defined(USART_CR3_OVER8)
#define LL_USART_OVERSAMPLING_8                 USART_CR3_OVER8        /*!< Oversampling by 8 */
#endif /* USART_OverSampling_Feature */
/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup USART_LL_EC_CLOCK Clock Signal
  * @{
  */

#define LL_USART_CLOCK_DISABLE                  0x00000000U            /*!< Clock signal not provided */
#define LL_USART_CLOCK_ENABLE                   USART_CR2_CLKEN        /*!< Clock signal provided */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/** @defgroup USART_LL_EC_LASTCLKPULSE Last Clock Pulse
  * @{
  */
#define LL_USART_LASTCLKPULSE_NO_OUTPUT         0x00000000U           /*!< The clock pulse of the last data bit is not output to the SCLK pin */
#define LL_USART_LASTCLKPULSE_OUTPUT            USART_CR2_LBCL        /*!< The clock pulse of the last data bit is output to the SCLK pin */
/**
  * @}
  */

/** @defgroup USART_LL_EC_PHASE Clock Phase
  * @{
  */
#define LL_USART_PHASE_1EDGE                    0x00000000U           /*!< The first clock transition is the first data capture edge */
#define LL_USART_PHASE_2EDGE                    USART_CR2_CPHA        /*!< The second clock transition is the first data capture edge */
/**
  * @}
  */

/** @defgroup USART_LL_EC_POLARITY Clock Polarity
  * @{
  */
#define LL_USART_POLARITY_LOW                   0x00000000U           /*!< Steady low value on SCLK pin outside transmission window*/
#define LL_USART_POLARITY_HIGH                  USART_CR2_CPOL        /*!< Steady high value on SCLK pin outside transmission window */
/**
  * @}
  */

/** @defgroup USART_LL_EC_STOPBITS Stop Bits
  * @{
  */
#define LL_USART_STOPBITS_0_5                   USART_CR2_STOP_0                           /*!< 0.5 stop bit */
#define LL_USART_STOPBITS_1                     0x00000000U                                /*!< 1 stop bit */
#define LL_USART_STOPBITS_1_5                   (USART_CR2_STOP_0 | USART_CR2_STOP_1)      /*!< 1.5 stop bits */
#define LL_USART_STOPBITS_2                     USART_CR2_STOP_1                           /*!< 2 stop bits */
/**
  * @}
  */

/** @defgroup USART_LL_EC_AUTOBAUD_DETECT_ON Autobaud Detection
  * @{
  */
#define LL_USART_AUTOBAUD_DETECT_ON_STARTBIT    0x00000000U                             /*!< Measurement of the start bit is used to detect the baud rate */
#define LL_USART_AUTOBAUD_DETECT_ON_FALLINGEDGE USART_CR3_ABRMOD                        /*!< Falling edge to falling edge measurement. Received frame must start with a single bit = 1 -> Frame = Start10xxxxxx */
/**
  * @}
  */

/** @defgroup USART_LL_EC_ADDRESS_DETECT Address Length Detection
  * @{
  */
#define LL_USART_ADDRESS_DETECT_4B              0x00000000U           /*!< 4-bit address detection method selected */
#define LL_USART_ADDRESS_DETECT_7B              USART_CR1_ADDM7       /*!< 7-bit address detection (in 8-bit data mode) method selected */
/**
  * @}
  */

/** @defgroup USART_LL_EC_HWCONTROL Hardware Control
  * @{
  */
#define LL_USART_HWCONTROL_NONE                 0x00000000U                          /*!< CTS and RTS hardware flow control disabled */
#define LL_USART_HWCONTROL_RTS                  USART_CR3_RTSE                       /*!< RTS output enabled, data is only requested when there is space in the receive buffer */
#define LL_USART_HWCONTROL_CTS                  USART_CR3_CTSE                       /*!< CTS mode enabled, data is only transmitted when the nCTS input is asserted (tied to 0) */
#define LL_USART_HWCONTROL_RTS_CTS              (USART_CR3_RTSE | USART_CR3_CTSE)    /*!< CTS and RTS hardware flow control enabled */
/**
  * @}
  */

/** @defgroup USART_LL_EC_IRDA_POWER IrDA Power
  * @{
  */
#define LL_USART_IRDA_POWER_NORMAL              0x00000000U           /*!< IrDA normal power mode */
#define LL_USART_IRDA_POWER_LOW                 USART_CR3_IRLP        /*!< IrDA low power mode */
/**
  * @}
  */

/** @defgroup USART_LL_EC_LINBREAK_DETECT LIN Break Detection Length
  * @{
  */
#define LL_USART_LINBREAK_DETECT_10B            0x00000000U           /*!< 10-bit break detection method selected */
#define LL_USART_LINBREAK_DETECT_11B            USART_CR2_LBDL        /*!< 11-bit break detection method selected */
/**
  * @}
  */

/** @defgroup USART_LL_EC_DE_POLARITY Driver Enable Polarity
  * @{
  */
 #define LL_USART_DE_POLARITY_HIGH               0x00000000U           /*!< DE signal is active high */
 #define LL_USART_DE_POLARITY_LOW                USART_CR2_DEP         /*!< DE signal is active low */
 /**
   * @}
   */
 
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup USART_LL_Exported_Macros USART Exported Macros
  * @{
  */

/** @defgroup USART_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in USART register
  * @param  __INSTANCE__ USART Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_USART_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in USART register
  * @param  __INSTANCE__ USART Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_USART_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup USART_LL_EM_Exported_Macros_Helper Exported_Macros_Helper
  * @{
  */

/**
  * @brief  Compute USARTDIV value according to Peripheral Clock and
  *         expected Baud Rate in 8 bits sampling mode (32 bits value of USARTDIV is returned)
  * @param  __PERIPHCLK__ Peripheral Clock frequency used for USART instance
  * @param  __BAUDRATE__ Baud rate value to achieve
  * @retval USARTDIV value to be used for BRR register filling in OverSampling_8 case
  */
#define __LL_USART_DIV_SAMPLING8_100(__PERIPHCLK__, __BAUDRATE__)      (((__PERIPHCLK__)*25)/(2*(__BAUDRATE__)))
#define __LL_USART_DIVMANT_SAMPLING8(__PERIPHCLK__, __BAUDRATE__)      (__LL_USART_DIV_SAMPLING8_100((__PERIPHCLK__), (__BAUDRATE__))/100)
#define __LL_USART_DIVFRAQ_SAMPLING8(__PERIPHCLK__, __BAUDRATE__)      (((__LL_USART_DIV_SAMPLING8_100((__PERIPHCLK__), (__BAUDRATE__)) - (__LL_USART_DIVMANT_SAMPLING8((__PERIPHCLK__), (__BAUDRATE__)) * 100)) * 8 + 50) / 100)
/* USART BRR = mantissa + overflow + fraction
            = (USART DIVMANT << 4) + ((USART DIVFRAQ & 0xF8) << 1) + (USART DIVFRAQ & 0x07) */
#define __LL_USART_DIV_SAMPLING8(__PERIPHCLK__, __BAUDRATE__)             (((__LL_USART_DIVMANT_SAMPLING8((__PERIPHCLK__), (__BAUDRATE__)) << 4) + \
                                                                           ((__LL_USART_DIVFRAQ_SAMPLING8((__PERIPHCLK__), (__BAUDRATE__)) & 0xF8) << 1)) + \
                                                                           (__LL_USART_DIVFRAQ_SAMPLING8((__PERIPHCLK__), (__BAUDRATE__)) & 0x07))

/**
  * @brief  Compute USARTDIV value according to Peripheral Clock and
  *         expected Baud Rate in 16 bits sampling mode (32 bits value of USARTDIV is returned)
  * @param  __PERIPHCLK__ Peripheral Clock frequency used for USART instance
  * @param  __BAUDRATE__ Baud rate value to achieve
  * @retval USARTDIV value to be used for BRR register filling in OverSampling_16 case
  */
#define __LL_USART_DIV_SAMPLING16_100(__PERIPHCLK__, __BAUDRATE__)     (((__PERIPHCLK__)*25)/(4*(__BAUDRATE__)))
#define __LL_USART_DIVMANT_SAMPLING16(__PERIPHCLK__, __BAUDRATE__)     (__LL_USART_DIV_SAMPLING16_100((__PERIPHCLK__), (__BAUDRATE__))/100)
#define __LL_USART_DIVFRAQ_SAMPLING16(__PERIPHCLK__, __BAUDRATE__)     (((__LL_USART_DIV_SAMPLING16_100((__PERIPHCLK__), (__BAUDRATE__)) - (__LL_USART_DIVMANT_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) * 100)) * 16 + 50) / 100)
/* USART BRR = mantissa + overflow + fraction
            = (USART DIVMANT << 4) + (USART DIVFRAQ & 0xF0) + (USART DIVFRAQ & 0x0F) */
#define __LL_USART_DIV_SAMPLING16(__PERIPHCLK__, __BAUDRATE__)            (((__LL_USART_DIVMANT_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) << 4) + \
                                                                           (__LL_USART_DIVFRAQ_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) & 0xF0)) + \
                                                                           (__LL_USART_DIVFRAQ_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) & 0x0F))

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup USART_LL_Exported_Functions USART Exported Functions
  * @{
  */

/** @defgroup USART_LL_EF_Configuration Configuration functions
  * @{
  */

/**
  * @brief  USART Enable
  * @rmtoll CR1          UE            LL_USART_Enable
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_Enable(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_UE);
}

/**
  * @brief  USART Disable (all USART prescalers and outputs are disabled)
  * @note   When USART is disabled, USART prescalers and outputs are stopped immediately,
  *         and current operations are discarded. The configuration of the USART is kept, but all the status
  *         flags, in the USARTx_SR are set to their default values.
  * @rmtoll CR1          UE            LL_USART_Disable
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_Disable(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_UE);
}

/**
  * @brief  Indicate if USART is enabled
  * @rmtoll CR1          UE            LL_USART_IsEnabled
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabled(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_UE) == (USART_CR1_UE));
}

/**
  * @brief  FIFO Mode Enable
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR1          FIFOEN        LL_USART_EnableFIFO
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableFIFO(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_FIFOEN);
}

/**
  * @brief  FIFO Mode Disable
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR1          FIFOEN        LL_USART_DisableFIFO
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableFIFO(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_FIFOEN);
}

/**
  * @brief  Indicate if FIFO Mode is enabled
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR1          FIFOEN        LL_USART_IsEnabledFIFO
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledFIFO(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_FIFOEN) == (USART_CR1_FIFOEN)) ? 1UL : 0UL);
}

/**
  * @brief  Configure TX FIFO Threshold
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR1          TXFTCFG       LL_USART_SetTXFIFOThreshold
  * @param  USARTx USART Instance
  * @param  Threshold This parameter can be one of the following values:
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_2
  *         @arg @ref LL_USART_FIFOTHRESHOLD_3_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_7_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_8_8
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetTXFIFOThreshold(USART_TypeDef *USARTx, uint32_t Threshold)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_TXFTCFG, Threshold << USART_CR1_TXFTCFG_Pos);
}

/**
  * @brief  Return TX FIFO Threshold Configuration
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR1          TXFTCFG       LL_USART_GetTXFIFOThreshold
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_2
  *         @arg @ref LL_USART_FIFOTHRESHOLD_3_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_7_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_8_8
  */
__STATIC_INLINE uint32_t LL_USART_GetTXFIFOThreshold(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_TXFTCFG) >> USART_CR1_TXFTCFG_Pos);
}

/**
  * @brief  Configure RX FIFO Threshold
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR1          RXFTCFG       LL_USART_SetRXFIFOThreshold
  * @param  USARTx USART Instance
  * @param  Threshold This parameter can be one of the following values:
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_2
  *         @arg @ref LL_USART_FIFOTHRESHOLD_3_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_7_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_8_8
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetRXFIFOThreshold(USART_TypeDef *USARTx, uint32_t Threshold)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_RXFTCFG, Threshold << USART_CR1_RXFTCFG_Pos);
}

/**
  * @brief  Return RX FIFO Threshold Configuration
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR1          RXFTCFG       LL_USART_GetRXFIFOThreshold
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_2
  *         @arg @ref LL_USART_FIFOTHRESHOLD_3_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_7_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_8_8
  */
__STATIC_INLINE uint32_t LL_USART_GetRXFIFOThreshold(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_RXFTCFG) >> USART_CR1_RXFTCFG_Pos);
}

/**
  * @brief  Configure TX and RX FIFOs Threshold
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR1          TXFTCFG       LL_USART_ConfigFIFOsThreshold\n
  *         CR1          RXFTCFG       LL_USART_ConfigFIFOsThreshold
  * @param  USARTx USART Instance
  * @param  TXThreshold This parameter can be one of the following values:
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_2
  *         @arg @ref LL_USART_FIFOTHRESHOLD_3_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_7_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_8_8
  * @param  RXThreshold This parameter can be one of the following values:
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_1_2
  *         @arg @ref LL_USART_FIFOTHRESHOLD_3_4
  *         @arg @ref LL_USART_FIFOTHRESHOLD_7_8
  *         @arg @ref LL_USART_FIFOTHRESHOLD_8_8
  * @retval None
  */
__STATIC_INLINE void LL_USART_ConfigFIFOsThreshold(USART_TypeDef *USARTx, uint32_t TXThreshold, uint32_t RXThreshold)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_TXFTCFG | USART_CR1_RXFTCFG, (TXThreshold << USART_CR1_TXFTCFG_Pos) |
             (RXThreshold << USART_CR1_RXFTCFG_Pos));
}

/**
  * @brief  Receiver Enable (Receiver is enabled and begins searching for a start bit)
  * @rmtoll CR1          RE            LL_USART_EnableDirectionRx
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableDirectionRx(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_RE);
}

/**
  * @brief  Receiver Disable
  * @rmtoll CR1          RE            LL_USART_DisableDirectionRx
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableDirectionRx(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_RE);
}

/**
  * @brief  Transmitter Enable
  * @rmtoll CR1          TE            LL_USART_EnableDirectionTx
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableDirectionTx(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_TE);
}

/**
  * @brief  Transmitter Disable
  * @rmtoll CR1          TE            LL_USART_DisableDirectionTx
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableDirectionTx(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_TE);
}

/**
  * @brief  Configure simultaneously enabled/disabled states
  *         of Transmitter and Receiver
  * @rmtoll CR1          RE            LL_USART_SetTransferDirection
  *         CR1          TE            LL_USART_SetTransferDirection
  * @param  USARTx USART Instance
  * @param  TransferDirection This parameter can be one of the following values:
  *         @arg @ref LL_USART_DIRECTION_NONE
  *         @arg @ref LL_USART_DIRECTION_RX
  *         @arg @ref LL_USART_DIRECTION_TX
  *         @arg @ref LL_USART_DIRECTION_TX_RX
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetTransferDirection(USART_TypeDef *USARTx, uint32_t TransferDirection)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_RE | USART_CR1_TE, TransferDirection);
}

/**
  * @brief  Return enabled/disabled states of Transmitter and Receiver
  * @rmtoll CR1          RE            LL_USART_GetTransferDirection
  *         CR1          TE            LL_USART_GetTransferDirection
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_DIRECTION_NONE
  *         @arg @ref LL_USART_DIRECTION_RX
  *         @arg @ref LL_USART_DIRECTION_TX
  *         @arg @ref LL_USART_DIRECTION_TX_RX
  */
__STATIC_INLINE uint32_t LL_USART_GetTransferDirection(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_RE | USART_CR1_TE));
}

/**
  * @brief  Configure Parity (enabled/disabled and parity mode if enabled).
  * @note   This function selects if hardware parity control (generation and detection) is enabled or disabled.
  *         When the parity control is enabled (Odd or Even), computed parity bit is inserted at the MSB position
  *         (9th or 8th bit depending on data width) and parity is checked on the received data.
  * @rmtoll CR1          PS            LL_USART_SetParity
  *         CR1          PCE           LL_USART_SetParity
  * @param  USARTx USART Instance
  * @param  Parity This parameter can be one of the following values:
  *         @arg @ref LL_USART_PARITY_NONE
  *         @arg @ref LL_USART_PARITY_EVEN
  *         @arg @ref LL_USART_PARITY_ODD
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetParity(USART_TypeDef *USARTx, uint32_t Parity)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_PS | USART_CR1_PCE, Parity);
}

/**
  * @brief  Return Parity configuration (enabled/disabled and parity mode if enabled)
  * @rmtoll CR1          PS            LL_USART_GetParity
  *         CR1          PCE           LL_USART_GetParity
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_PARITY_NONE
  *         @arg @ref LL_USART_PARITY_EVEN
  *         @arg @ref LL_USART_PARITY_ODD
  */
__STATIC_INLINE uint32_t LL_USART_GetParity(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_PS | USART_CR1_PCE));
}

/**
  * @brief  Set Receiver Wake Up method from Mute mode.
  * @rmtoll CR1          WAKE          LL_USART_SetWakeUpMethod
  * @param  USARTx USART Instance
  * @param  Method This parameter can be one of the following values:
  *         @arg @ref LL_USART_WAKEUP_IDLELINE
  *         @arg @ref LL_USART_WAKEUP_ADDRESSMARK
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetWakeUpMethod(USART_TypeDef *USARTx, uint32_t Method)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_WAKE, Method);
}

/**
  * @brief  Return Receiver Wake Up method from Mute mode
  * @rmtoll CR1          WAKE          LL_USART_GetWakeUpMethod
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_WAKEUP_IDLELINE
  *         @arg @ref LL_USART_WAKEUP_ADDRESSMARK
  */
__STATIC_INLINE uint32_t LL_USART_GetWakeUpMethod(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_WAKE));
}

/**
  * @brief  Set Word length (i.e. nb of data bits, excluding start and stop bits)
  * @rmtoll CR1          M             LL_USART_SetDataWidth
  * @param  USARTx USART Instance
  * @param  DataWidth This parameter can be one of the following values:
  *         @arg @ref LL_USART_DATAWIDTH_7B
  *         @arg @ref LL_USART_DATAWIDTH_8B
  *         @arg @ref LL_USART_DATAWIDTH_9B
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetDataWidth(USART_TypeDef *USARTx, uint32_t DataWidth)
{
  MODIFY_REG(USARTx->CR1, (USART_CR1_M0 | USART_CR1_M1), DataWidth);
}

/**
  * @brief  Return Word length (i.e. nb of data bits, excluding start and stop bits)
  * @rmtoll CR1          M             LL_USART_GetDataWidth
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_DATAWIDTH_7B
  *         @arg @ref LL_USART_DATAWIDTH_8B
  *         @arg @ref LL_USART_DATAWIDTH_9B
  */
__STATIC_INLINE uint32_t LL_USART_GetDataWidth(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, (USART_CR1_M0 | USART_CR1_M1)));
}

#if defined(USART_CR3_OVER8)
/**
  * @brief  Set Oversampling to 8-bit or 16-bit mode
  * @rmtoll CR3          OVER8         LL_USART_SetOverSampling
  * @param  USARTx USART Instance
  * @param  OverSampling This parameter can be one of the following values:
  *         @arg @ref LL_USART_OVERSAMPLING_16
  *         @arg @ref LL_USART_OVERSAMPLING_8
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetOverSampling(USART_TypeDef *USARTx, uint32_t OverSampling)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_OVER8, OverSampling);
}

/**
  * @brief  Return Oversampling mode
  * @rmtoll CR3          OVER8         LL_USART_GetOverSampling
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_OVERSAMPLING_16
  *         @arg @ref LL_USART_OVERSAMPLING_8
  */
__STATIC_INLINE uint32_t LL_USART_GetOverSampling(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_OVER8));
}

#endif /* USART_OverSampling_Feature */
/**
  * @brief  Configure if Clock pulse of the last data bit is output to the SCLK pin or not
  * @note   Macro @ref IS_USART_INSTANCE(USARTx) can be used to check whether or not
  *         Synchronous mode is supported by the USARTx instance.
  * @rmtoll CR2          LBCL          LL_USART_SetLastClkPulseOutput
  * @param  USARTx USART Instance
  * @param  LastBitClockPulse This parameter can be one of the following values:
  *         @arg @ref LL_USART_LASTCLKPULSE_NO_OUTPUT
  *         @arg @ref LL_USART_LASTCLKPULSE_OUTPUT
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetLastClkPulseOutput(USART_TypeDef *USARTx, uint32_t LastBitClockPulse)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_LBCL, LastBitClockPulse);
}

/**
  * @brief  Retrieve Clock pulse of the last data bit output configuration
  *         (Last bit Clock pulse output to the SCLK pin or not)
  * @note   Macro @ref IS_USART_INSTANCE(USARTx) can be used to check whether or not
  *         Synchronous mode is supported by the USARTx instance.
  * @rmtoll CR2          LBCL          LL_USART_GetLastClkPulseOutput
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_LASTCLKPULSE_NO_OUTPUT
  *         @arg @ref LL_USART_LASTCLKPULSE_OUTPUT
  */
__STATIC_INLINE uint32_t LL_USART_GetLastClkPulseOutput(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_LBCL));
}

/**
  * @brief  Select the phase of the clock output on the SCLK pin in synchronous mode
  * @note   Macro @ref IS_USART_INSTANCE(USARTx) can be used to check whether or not
  *         Synchronous mode is supported by the USARTx instance.
  * @rmtoll CR2          CPHA          LL_USART_SetClockPhase
  * @param  USARTx USART Instance
  * @param  ClockPhase This parameter can be one of the following values:
  *         @arg @ref LL_USART_PHASE_1EDGE
  *         @arg @ref LL_USART_PHASE_2EDGE
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetClockPhase(USART_TypeDef *USARTx, uint32_t ClockPhase)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_CPHA, ClockPhase);
}

/**
  * @brief  Return phase of the clock output on the SCLK pin in synchronous mode
  * @note   Macro @ref IS_USART_INSTANCE(USARTx) can be used to check whether or not
  *         Synchronous mode is supported by the USARTx instance.
  * @rmtoll CR2          CPHA          LL_USART_GetClockPhase
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_PHASE_1EDGE
  *         @arg @ref LL_USART_PHASE_2EDGE
  */
__STATIC_INLINE uint32_t LL_USART_GetClockPhase(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_CPHA));
}

/**
  * @brief  Select the polarity of the clock output on the SCLK pin in synchronous mode
  * @note   Macro @ref IS_USART_INSTANCE(USARTx) can be used to check whether or not
  *         Synchronous mode is supported by the USARTx instance.
  * @rmtoll CR2          CPOL          LL_USART_SetClockPolarity
  * @param  USARTx USART Instance
  * @param  ClockPolarity This parameter can be one of the following values:
  *         @arg @ref LL_USART_POLARITY_LOW
  *         @arg @ref LL_USART_POLARITY_HIGH
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetClockPolarity(USART_TypeDef *USARTx, uint32_t ClockPolarity)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_CPOL, ClockPolarity);
}

/**
  * @brief  Return polarity of the clock output on the SCLK pin in synchronous mode
  * @note   Macro @ref IS_USART_INSTANCE(USARTx) can be used to check whether or not
  *         Synchronous mode is supported by the USARTx instance.
  * @rmtoll CR2          CPOL          LL_USART_GetClockPolarity
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_POLARITY_LOW
  *         @arg @ref LL_USART_POLARITY_HIGH
  */
__STATIC_INLINE uint32_t LL_USART_GetClockPolarity(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_CPOL));
}

/**
  * @brief  Configure Clock signal format (Phase Polarity and choice about output of last bit clock pulse)
  * @note   Macro @ref IS_USART_INSTANCE(USARTx) can be used to check whether or not
  *         Synchronous mode is supported by the USARTx instance.
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Clock Phase configuration using @ref LL_USART_SetClockPhase() function
  *         - Clock Polarity configuration using @ref LL_USART_SetClockPolarity() function
  *         - Output of Last bit Clock pulse configuration using @ref LL_USART_SetLastClkPulseOutput() function
  * @rmtoll CR2          CPHA          LL_USART_ConfigClock
  *         CR2          CPOL          LL_USART_ConfigClock
  *         CR2          LBCL          LL_USART_ConfigClock
  * @param  USARTx USART Instance
  * @param  Phase This parameter can be one of the following values:
  *         @arg @ref LL_USART_PHASE_1EDGE
  *         @arg @ref LL_USART_PHASE_2EDGE
  * @param  Polarity This parameter can be one of the following values:
  *         @arg @ref LL_USART_POLARITY_LOW
  *         @arg @ref LL_USART_POLARITY_HIGH
  * @param  LBCPOutput This parameter can be one of the following values:
  *         @arg @ref LL_USART_LASTCLKPULSE_NO_OUTPUT
  *         @arg @ref LL_USART_LASTCLKPULSE_OUTPUT
  * @retval None
  */
__STATIC_INLINE void LL_USART_ConfigClock(USART_TypeDef *USARTx, uint32_t Phase, uint32_t Polarity, uint32_t LBCPOutput)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_CPHA | USART_CR2_CPOL | USART_CR2_LBCL, Phase | Polarity | LBCPOutput);
}

/**
  * @brief  Enable Clock output on SCLK pin
  * @note   Macro @ref IS_USART_INSTANCE(USARTx) can be used to check whether or not
  *         Synchronous mode is supported by the USARTx instance.
  * @rmtoll CR2          CLKEN         LL_USART_EnableSCLKOutput
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableSCLKOutput(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_CLKEN);
}

/**
  * @brief  Disable Clock output on SCLK pin
  * @note   Macro @ref IS_USART_INSTANCE(USARTx) can be used to check whether or not
  *         Synchronous mode is supported by the USARTx instance.
  * @rmtoll CR2          CLKEN         LL_USART_DisableSCLKOutput
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableSCLKOutput(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_CLKEN);
}

/**
  * @brief  Indicate if Clock output on SCLK pin is enabled
  * @note   Macro @ref IS_USART_INSTANCE(USARTx) can be used to check whether or not
  *         Synchronous mode is supported by the USARTx instance.
  * @rmtoll CR2          CLKEN         LL_USART_IsEnabledSCLKOutput
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledSCLKOutput(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR2, USART_CR2_CLKEN) == (USART_CR2_CLKEN));
}

/**
  * @brief  Set the length of the stop bits
  * @rmtoll CR2          STOP          LL_USART_SetStopBitsLength
  * @param  USARTx USART Instance
  * @param  StopBits This parameter can be one of the following values:
  *         @arg @ref LL_USART_STOPBITS_0_5
  *         @arg @ref LL_USART_STOPBITS_1
  *         @arg @ref LL_USART_STOPBITS_1_5
  *         @arg @ref LL_USART_STOPBITS_2
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetStopBitsLength(USART_TypeDef *USARTx, uint32_t StopBits)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_STOP, StopBits);
}

/**
  * @brief  Retrieve the length of the stop bits
  * @rmtoll CR2          STOP          LL_USART_GetStopBitsLength
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_STOPBITS_0_5
  *         @arg @ref LL_USART_STOPBITS_1
  *         @arg @ref LL_USART_STOPBITS_1_5
  *         @arg @ref LL_USART_STOPBITS_2
  */
__STATIC_INLINE uint32_t LL_USART_GetStopBitsLength(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_STOP));
}

/**
  * @brief  Configure Character frame format (Datawidth, Parity control, Stop Bits)
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Data Width configuration using @ref LL_USART_SetDataWidth() function
  *         - Parity Control and mode configuration using @ref LL_USART_SetParity() function
  *         - Stop bits configuration using @ref LL_USART_SetStopBitsLength() function
  * @rmtoll CR1          PS            LL_USART_ConfigCharacter
  *         CR1          PCE           LL_USART_ConfigCharacter
  *         CR1          M0            LL_USART_ConfigCharacter
  *         CR1          M1            LL_USART_ConfigCharacter
  *         CR2          STOP          LL_USART_ConfigCharacter
  * @param  USARTx USART Instance
  * @param  DataWidth This parameter can be one of the following values:
  *         @arg @ref LL_USART_DATAWIDTH_7B
  *         @arg @ref LL_USART_DATAWIDTH_8B
  *         @arg @ref LL_USART_DATAWIDTH_9B
  * @param  Parity This parameter can be one of the following values:
  *         @arg @ref LL_USART_PARITY_NONE
  *         @arg @ref LL_USART_PARITY_EVEN
  *         @arg @ref LL_USART_PARITY_ODD
  * @param  StopBits This parameter can be one of the following values:
  *         @arg @ref LL_USART_STOPBITS_0_5
  *         @arg @ref LL_USART_STOPBITS_1
  *         @arg @ref LL_USART_STOPBITS_1_5
  *         @arg @ref LL_USART_STOPBITS_2
  * @retval None
  */
__STATIC_INLINE void LL_USART_ConfigCharacter(USART_TypeDef *USARTx, uint32_t DataWidth, uint32_t Parity,
                                              uint32_t StopBits)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_PS | USART_CR1_PCE | USART_CR1_M0 | USART_CR1_M1, Parity | DataWidth);
  MODIFY_REG(USARTx->CR2, USART_CR2_STOP, StopBits);
}

/**
  * @brief  Configure TX/RX pins swapping setting.
  * @rmtoll CR1          SWAP          LL_USART_SetTXRXSwap
  * @param  USARTx USART Instance
  * @param  SwapConfig This parameter can be one of the following values:
  *         @arg @ref LL_USART_TXRX_STANDARD
  *         @arg @ref LL_USART_TXRX_SWAPPED
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetTXRXSwap(USART_TypeDef *USARTx, uint32_t SwapConfig)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_SWAP, SwapConfig);
}

/**
  * @brief  Retrieve TX/RX pins swapping configuration.
  * @rmtoll CR1          SWAP          LL_USART_GetTXRXSwap
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_TXRX_STANDARD
  *         @arg @ref LL_USART_TXRX_SWAPPED
  */
__STATIC_INLINE uint32_t LL_USART_GetTXRXSwap(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_SWAP));
}

/**
  * @brief  Configure Binary data logic.
  * @note   Allow to define how Logical data from the data register are send/received :
  *         either in positive/direct logic (1=H, 0=L) or in negative/inverse logic (1=L, 0=H)
  * @rmtoll CR1          DATAINV       LL_USART_SetBinaryDataLogic
  * @param  USARTx USART Instance
  * @param  DataLogic This parameter can be one of the following values:
  *         @arg @ref LL_USART_BINARY_LOGIC_POSITIVE
  *         @arg @ref LL_USART_BINARY_LOGIC_NEGATIVE
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetBinaryDataLogic(USART_TypeDef *USARTx, uint32_t DataLogic)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_DATAINV, DataLogic);
}

/**
  * @brief  Retrieve Binary data configuration
  * @rmtoll CR1          DATAINV       LL_USART_GetBinaryDataLogic
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_BINARY_LOGIC_POSITIVE
  *         @arg @ref LL_USART_BINARY_LOGIC_NEGATIVE
  */
__STATIC_INLINE uint32_t LL_USART_GetBinaryDataLogic(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_DATAINV));
}

/**
  * @brief  Configure transfer bit order (either Less or Most Significant Bit First)
  * @note   MSB First means data is transmitted/received with the MSB first, following the start bit.
  *         LSB First means data is transmitted/received with data bit 0 first, following the start bit.
  * @rmtoll CR1          MSBFIRST      LL_USART_SetTransferBitOrder
  * @param  USARTx USART Instance
  * @param  BitOrder This parameter can be one of the following values:
  *         @arg @ref LL_USART_BITORDER_LSBFIRST
  *         @arg @ref LL_USART_BITORDER_MSBFIRST
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetTransferBitOrder(USART_TypeDef *USARTx, uint32_t BitOrder)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_MSB, BitOrder);
}

/**
  * @brief  Return transfer bit order (either Less or Most Significant Bit First)
  * @note   MSB First means data is transmitted/received with the MSB first, following the start bit.
  *         LSB First means data is transmitted/received with data bit 0 first, following the start bit.
  * @rmtoll CR1          MSBFIRST      LL_USART_GetTransferBitOrder
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_BITORDER_LSBFIRST
  *         @arg @ref LL_USART_BITORDER_MSBFIRST
  */
__STATIC_INLINE uint32_t LL_USART_GetTransferBitOrder(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_MSB));
}

/**
  * @brief  Enable Receiver Timeout
  * @rmtoll CR2          RTOEN         LL_USART_EnableRxTimeout
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableRxTimeout(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_RTOEN);
}

/**
  * @brief  Disable Receiver Timeout
  * @rmtoll CR2          RTOEN         LL_USART_DisableRxTimeout
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableRxTimeout(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_RTOEN);
}

/**
  * @brief  Indicate if Receiver Timeout feature is enabled
  * @rmtoll CR2          RTOEN         LL_USART_IsEnabledRxTimeout
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledRxTimeout(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR2, USART_CR2_RTOEN) == (USART_CR2_RTOEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set Address of the USART node.
  * @note   This is used in multiprocessor communication during Mute mode or Stop mode,
  *         for wake up with address mark detection.
  * @note   4bits address node is used when 4-bit Address Detection is selected in ADDM7.
  *         (b7-b4 should be set to 0)
  *         8bits address node is used when 7-bit Address Detection is selected in ADDM7.
  *         (This is used in multiprocessor communication during Mute mode or Stop mode,
  *         for wake up with 7-bit address mark detection.
  *         The MSB of the character sent by the transmitter should be equal to 1.
  *         It may also be used for character detection during normal reception,
  *         Mute mode inactive (for example, end of block detection in ModBus protocol).
  *         In this case, the whole received character (8-bit) is compared to the ADD[7:0]
  *         value and CMF flag is set on match)
  * @rmtoll CR2          ADD           LL_USART_ConfigNodeAddress
  *         CR1          ADDM7         LL_USART_ConfigNodeAddress
  * @param  USARTx USART Instance
  * @param  AddressLen This parameter can be one of the following values:
  *         @arg @ref LL_USART_ADDRESS_DETECT_4B
  *         @arg @ref LL_USART_ADDRESS_DETECT_7B
  * @param  NodeAddress 4 or 7 bit Address of the USART node.
  * @retval None
  */
__STATIC_INLINE void LL_USART_ConfigNodeAddress(USART_TypeDef *USARTx, uint32_t AddressLen, uint32_t NodeAddress)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_ADD, (uint32_t)(NodeAddress << USART_CR2_ADD_Pos));
  MODIFY_REG(USARTx->CR1, USART_CR1_ADDM7, (uint32_t)(AddressLen));
}

/**
  * @brief  Return 8 bit Address of the USART node as set in ADD field of CR2.
  * @note   If 4-bit Address Detection is selected in ADDM7,
  *         only 4bits (b3-b0) of returned value are relevant (b31-b4 are not relevant)
  *         If 7-bit Address Detection is selected in ADDM7,
  *         only 8bits (b7-b0) of returned value are relevant (b31-b8 are not relevant)
  * @rmtoll CR2          ADD           LL_USART_GetNodeAddress
  * @param  USARTx USART Instance
  * @retval Address of the USART node (Value between Min_Data=0 and Max_Data=255)
  */
__STATIC_INLINE uint32_t LL_USART_GetNodeAddress(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_ADD) >> USART_CR2_ADD_Pos);
}

/**
  * @brief  Return Length of Node Address used in Address Detection mode (7-bit or 4-bit)
  * @rmtoll CR1          ADDM7         LL_USART_GetNodeAddressLen
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_ADDRESS_DETECT_4B
  *         @arg @ref LL_USART_ADDRESS_DETECT_7B
  */
__STATIC_INLINE uint32_t LL_USART_GetNodeAddressLen(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_ADDM7));
}

/**
  * @brief  Enable RTS HW Flow Control
  * @note   Macro @ref IS_SCI_HWFLOW_INSTANCE(USARTx) can be used to check whether or not
  *         Hardware Flow control feature is supported by the USARTx instance.
  * @rmtoll CR3          RTSE          LL_USART_EnableRTSHWFlowCtrl
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableRTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_RTSE);
}

/**
  * @brief  Disable RTS HW Flow Control
  * @note   Macro @ref IS_SCI_HWFLOW_INSTANCE(USARTx) can be used to check whether or not
  *         Hardware Flow control feature is supported by the USARTx instance.
  * @rmtoll CR3          RTSE          LL_USART_DisableRTSHWFlowCtrl
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableRTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_RTSE);
}

/**
  * @brief  Enable CTS HW Flow Control
  * @note   Macro @ref IS_SCI_HWFLOW_INSTANCE(USARTx) can be used to check whether or not
  *         Hardware Flow control feature is supported by the USARTx instance.
  * @rmtoll CR3          CTSE          LL_USART_EnableCTSHWFlowCtrl
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableCTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_CTSE);
}

/**
  * @brief  Disable CTS HW Flow Control
  * @note   Macro @ref IS_SCI_HWFLOW_INSTANCE(USARTx) can be used to check whether or not
  *         Hardware Flow control feature is supported by the USARTx instance.
  * @rmtoll CR3          CTSE          LL_USART_DisableCTSHWFlowCtrl
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableCTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_CTSE);
}

/**
  * @brief  Configure HW Flow Control mode (both CTS and RTS)
  * @note   Macro @ref IS_SCI_HWFLOW_INSTANCE(USARTx) can be used to check whether or not
  *         Hardware Flow control feature is supported by the USARTx instance.
  * @rmtoll CR3          RTSE          LL_USART_SetHWFlowCtrl
  *         CR3          CTSE          LL_USART_SetHWFlowCtrl
  * @param  USARTx USART Instance
  * @param  HardwareFlowControl This parameter can be one of the following values:
  *         @arg @ref LL_USART_HWCONTROL_NONE
  *         @arg @ref LL_USART_HWCONTROL_RTS
  *         @arg @ref LL_USART_HWCONTROL_CTS
  *         @arg @ref LL_USART_HWCONTROL_RTS_CTS
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetHWFlowCtrl(USART_TypeDef *USARTx, uint32_t HardwareFlowControl)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_RTSE | USART_CR3_CTSE, HardwareFlowControl);
}

/**
  * @brief  Return HW Flow Control configuration (both CTS and RTS)
  * @note   Macro @ref IS_SCI_HWFLOW_INSTANCE(USARTx) can be used to check whether or not
  *         Hardware Flow control feature is supported by the USARTx instance.
  * @rmtoll CR3          RTSE          LL_USART_GetHWFlowCtrl
  *         CR3          CTSE          LL_USART_GetHWFlowCtrl
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_HWCONTROL_NONE
  *         @arg @ref LL_USART_HWCONTROL_RTS
  *         @arg @ref LL_USART_HWCONTROL_CTS
  *         @arg @ref LL_USART_HWCONTROL_RTS_CTS
  */
__STATIC_INLINE uint32_t LL_USART_GetHWFlowCtrl(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_RTSE | USART_CR3_CTSE));
}

#if defined(USART_CR3_OVER8)
/**
  * @brief  Configure USART BRR register for achieving expected Baud Rate value.
  * @note   Compute and set USARTDIV value in BRR Register (full BRR content)
  *         according to used Peripheral Clock, Oversampling mode, and expected Baud Rate values
  * @note   Peripheral clock and Baud rate values provided as function parameters should be valid
  *         (Baud rate value != 0)
  * @rmtoll BRR          BRR           LL_USART_SetBaudRate
  * @param  USARTx USART Instance
  * @param  PeriphClk Peripheral Clock
  * @param  OverSampling This parameter can be one of the following values:
  *         @arg @ref LL_USART_OVERSAMPLING_16
  *         @arg @ref LL_USART_OVERSAMPLING_8
  * @param  BaudRate Baud Rate
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetBaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t OverSampling,
                                          uint32_t BaudRate)
{
  uint64_t usartdiv;
  uint64_t brrtemp;

  if (OverSampling == LL_USART_OVERSAMPLING_8)
  {
    usartdiv = (uint16_t)(__LL_USART_DIV_SAMPLING8(PeriphClk, BaudRate));
    brrtemp  = usartdiv & 0xFFF0U;
    brrtemp |= (uint16_t)((usartdiv & (uint16_t)0x000FU) >> 1U);
    USARTx->BRR = brrtemp;
  }
  else
  {
    USARTx->BRR = (uint16_t)(__LL_USART_DIV_SAMPLING16(PeriphClk, BaudRate));
  }
}

/**
  * @brief  Return current Baud Rate value, according to USARTDIV present in BRR register
  *         (full BRR content), and to used Peripheral Clock and Oversampling mode values
  * @note   In case of non-initialized or invalid value stored in BRR register, value 0 will be returned.
  * @rmtoll BRR          BRR           LL_USART_GetBaudRate
  * @param  USARTx USART Instance
  * @param  PeriphClk Peripheral Clock
  * @param  OverSampling This parameter can be one of the following values:
  *         @arg @ref LL_USART_OVERSAMPLING_16
  *         @arg @ref LL_USART_OVERSAMPLING_8
  * @retval Baud Rate
  */
__STATIC_INLINE uint32_t LL_USART_GetBaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t OverSampling)
{
  register uint32_t usartdiv = 0x0U;
  register uint32_t brrresult = 0x0U;

  usartdiv = USARTx->BRR;

  if (OverSampling == LL_USART_OVERSAMPLING_8)
  {
    if ((usartdiv & 0xFFF7U) != 0U)
    {
      usartdiv = (uint16_t)((usartdiv & 0xFFF0U) | ((usartdiv & 0x0007U) << 1U)) ;
      brrresult = (PeriphClk * 2U) / usartdiv;
    }
  }
  else
  {
    if ((usartdiv & 0xFFFFU) != 0U)
    {
      brrresult = PeriphClk / usartdiv;
    }
  }
  return (brrresult);
}
#else
/**
  * @brief  Configure USART BRR register for achieving expected Baud Rate value.
  * @note   Compute and set USARTDIV value in BRR Register (full BRR content)
  *         according to used Peripheral Clock, Oversampling mode, and expected Baud Rate values
  * @note   Peripheral clock and Baud rate values provided as function parameters should be valid
  *         (Baud rate value != 0)
  * @rmtoll BRR          BRR           LL_USART_SetBaudRate
  * @param  USARTx USART Instance
  * @param  PeriphClk Peripheral Clock
  * @param  BaudRate Baud Rate
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetBaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
  USARTx->BRR = (uint16_t)(__LL_USART_DIV_SAMPLING16(PeriphClk, BaudRate));
}

/**
  * @brief  Return current Baud Rate value, according to USARTDIV present in BRR register
  *         (full BRR content), and to used Peripheral Clock and Oversampling mode values
  * @note   In case of non-initialized or invalid value stored in BRR register, value 0 will be returned.
  * @rmtoll BRR          BRR           LL_USART_GetBaudRate
  * @param  USARTx USART Instance
  * @param  PeriphClk Peripheral Clock
  * @retval Baud Rate
  */
__STATIC_INLINE uint32_t LL_USART_GetBaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk)
{
  register uint32_t usartdiv = 0x0U;
  register uint32_t brrresult = 0x0U;

  usartdiv = USARTx->BRR;

  if ((usartdiv & 0xFFFFU) != 0U)
  {
    brrresult = PeriphClk / usartdiv;
  }
  return (brrresult);
}
#endif /* USART_OverSampling_Feature */

/**
  * @brief  Set Receiver Time Out Value (expressed in nb of bits duration)
  * @rmtoll RTOR         RTO           LL_USART_SetRxTimeout
  * @param  USARTx USART Instance
  * @param  Timeout Value between Min_Data=0x00 and Max_Data=0x00FFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetRxTimeout(USART_TypeDef *USARTx, uint32_t Timeout)
{
  MODIFY_REG(USARTx->RTOR, USART_RTOR_RTO, Timeout);
}

/**
  * @brief  Get Receiver Time Out Value (expressed in nb of bits duration)
  * @rmtoll RTOR         RTO           LL_USART_GetRxTimeout
  * @param  USARTx USART Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x00FFFFFF
  */
__STATIC_INLINE uint32_t LL_USART_GetRxTimeout(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->RTOR, USART_RTOR_RTO));
}

/**
  * @brief  Set Block Length value in reception
  * @rmtoll RTOR         BLEN          LL_USART_SetBlockLength
  * @param  USARTx USART Instance
  * @param  BlockLength Value between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetBlockLength(USART_TypeDef *USARTx, uint32_t BlockLength)
{
  MODIFY_REG(USARTx->RTOR, USART_RTOR_BLEN, BlockLength << USART_RTOR_BLEN_Pos);
}

/**
  * @brief  Get Block Length value in reception
  * @rmtoll RTOR         BLEN          LL_USART_GetBlockLength
  * @param  USARTx USART Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_USART_GetBlockLength(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->RTOR, USART_RTOR_BLEN) >> USART_RTOR_BLEN_Pos);
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_Configuration_IRDA Configuration functions related to Irda feature
  * @{
  */

/**
  * @brief  Enable IrDA mode
  * @note   Macro @ref IS_IRDA_INSTANCE(USARTx) can be used to check whether or not
  *         IrDA feature is supported by the USARTx instance.
  * @rmtoll CR3          IREN          LL_USART_EnableIrda
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIrda(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_IREN);
}

/**
  * @brief  Disable IrDA mode
  * @note   Macro @ref IS_IRDA_INSTANCE(USARTx) can be used to check whether or not
  *         IrDA feature is supported by the USARTx instance.
  * @rmtoll CR3          IREN          LL_USART_DisableIrda
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIrda(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_IREN);
}

/**
  * @brief  Indicate if IrDA mode is enabled
  * @note   Macro @ref IS_IRDA_INSTANCE(USARTx) can be used to check whether or not
  *         IrDA feature is supported by the USARTx instance.
  * @rmtoll CR3          IREN          LL_USART_IsEnabledIrda
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIrda(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_IREN) == (USART_CR3_IREN));
}

/**
  * @brief  Configure IrDA Power Mode (Normal or Low Power)
  * @note   Macro @ref IS_IRDA_INSTANCE(USARTx) can be used to check whether or not
  *         IrDA feature is supported by the USARTx instance.
  * @rmtoll CR3          IRLP          LL_USART_SetIrdaPowerMode
  * @param  USARTx USART Instance
  * @param  PowerMode This parameter can be one of the following values:
  *         @arg @ref LL_USART_IRDA_POWER_NORMAL
  *         @arg @ref LL_USART_IRDA_POWER_LOW
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetIrdaPowerMode(USART_TypeDef *USARTx, uint32_t PowerMode)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_IRLP, PowerMode);
}

/**
  * @brief  Retrieve IrDA Power Mode configuration (Normal or Low Power)
  * @note   Macro @ref IS_IRDA_INSTANCE(USARTx) can be used to check whether or not
  *         IrDA feature is supported by the USARTx instance.
  * @rmtoll CR3          IRLP          LL_USART_GetIrdaPowerMode
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_IRDA_POWER_NORMAL
  *         @arg @ref LL_USART_PHASE_2EDGE
  */
__STATIC_INLINE uint32_t LL_USART_GetIrdaPowerMode(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_IRLP));
}

/**
  * @brief  Set Irda prescaler value, used for dividing the USART clock source
  *         to achieve the Irda Low Power frequency (8 bits value)
  * @note   Macro @ref IS_IRDA_INSTANCE(USARTx) can be used to check whether or not
  *         IrDA feature is supported by the USARTx instance.
  * @rmtoll GTPR         PSC           LL_USART_SetIrdaPrescaler
  * @param  USARTx USART Instance
  * @param  PrescalerValue Value between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetIrdaPrescaler(USART_TypeDef *USARTx, uint32_t PrescalerValue)
{
  MODIFY_REG(USARTx->GTPR, USART_GTPR_PSC, PrescalerValue);
}

/**
  * @brief  Return Irda prescaler value, used for dividing the USART clock source
  *         to achieve the Irda Low Power frequency (8 bits value)
  * @note   Macro @ref IS_IRDA_INSTANCE(USARTx) can be used to check whether or not
  *         IrDA feature is supported by the USARTx instance.
  * @rmtoll GTPR         PSC           LL_USART_GetIrdaPrescaler
  * @param  USARTx USART Instance
  * @retval Irda prescaler value (Value between Min_Data=0x00 and Max_Data=0xFF)
  */
__STATIC_INLINE uint32_t LL_USART_GetIrdaPrescaler(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->GTPR, USART_GTPR_PSC));
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_Configuration_Smartcard Configuration functions related to Smartcard feature
  * @{
  */

/**
  * @brief  Enable Smartcard NACK transmission
  * @note   Macro @ref IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @rmtoll CR3          NACK          LL_USART_EnableSmartcardNACK
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableSmartcardNACK(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_NACK);
}

/**
  * @brief  Disable Smartcard NACK transmission
  * @note   Macro @ref IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @rmtoll CR3          NACK          LL_USART_DisableSmartcardNACK
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableSmartcardNACK(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_NACK);
}

/**
  * @brief  Indicate if Smartcard NACK transmission is enabled
  * @note   Macro @ref IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @rmtoll CR3          NACK          LL_USART_IsEnabledSmartcardNACK
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledSmartcardNACK(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_NACK) == (USART_CR3_NACK));
}

/**
  * @brief  Enable Smartcard mode
  * @note   Macro @ref IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @rmtoll CR3          SCEN          LL_USART_EnableSmartcard
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableSmartcard(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_SCEN);
}

/**
  * @brief  Disable Smartcard mode
  * @note   Macro @ref IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @rmtoll CR3          SCEN          LL_USART_DisableSmartcard
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableSmartcard(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_SCEN);
}

/**
  * @brief  Indicate if Smartcard mode is enabled
  * @note   Macro @ref IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @rmtoll CR3          SCEN          LL_USART_IsEnabledSmartcard
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledSmartcard(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_SCEN) == (USART_CR3_SCEN));
}

/**
  * @brief  Set Smartcard prescaler value, used for dividing the USART clock
  *         source to provide the SMARTCARD Clock (5 bits value)
  * @note   Macro @ref IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @rmtoll GTPR         PSC           LL_USART_SetSmartcardPrescaler
  * @param  USARTx USART Instance
  * @param  PrescalerValue Value between Min_Data=0 and Max_Data=31
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetSmartcardPrescaler(USART_TypeDef *USARTx, uint32_t PrescalerValue)
{
  MODIFY_REG(USARTx->GTPR, USART_GTPR_PSC, PrescalerValue);
}

/**
  * @brief  Return Smartcard prescaler value, used for dividing the USART clock
  *         source to provide the SMARTCARD Clock (5 bits value)
  * @note   Macro @ref IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @rmtoll GTPR         PSC           LL_USART_GetSmartcardPrescaler
  * @param  USARTx USART Instance
  * @retval Smartcard prescaler value (Value between Min_Data=0 and Max_Data=31)
  */
__STATIC_INLINE uint32_t LL_USART_GetSmartcardPrescaler(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->GTPR, USART_GTPR_PSC));
}

/**
  * @brief  Set Smartcard Guard time value, expressed in nb of baud clocks periods
  *         (GT[7:0] bits : Guard time value)
  * @note   Macro @ref IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @rmtoll GTPR         GT            LL_USART_SetSmartcardGuardTime
  * @param  USARTx USART Instance
  * @param  GuardTime Value between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetSmartcardGuardTime(USART_TypeDef *USARTx, uint32_t GuardTime)
{
  MODIFY_REG(USARTx->GTPR, USART_GTPR_GT, GuardTime << USART_POSITION_GTPR_GT);
}

/**
  * @brief  Return Smartcard Guard time value, expressed in nb of baud clocks periods
  *         (GT[7:0] bits : Guard time value)
  * @note   Macro @ref IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @rmtoll GTPR         GT            LL_USART_GetSmartcardGuardTime
  * @param  USARTx USART Instance
  * @retval Smartcard Guard time value (Value between Min_Data=0x00 and Max_Data=0xFF)
  */
__STATIC_INLINE uint32_t LL_USART_GetSmartcardGuardTime(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->GTPR, USART_GTPR_GT) >> USART_POSITION_GTPR_GT);
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_Configuration_HalfDuplex Configuration functions related to Half Duplex feature
  * @{
  */

/**
  * @brief  Enable Single Wire Half-Duplex mode
  * @note   Macro @ref IS_SCI_HALFDUPLEX_INSTANCE(USARTx) can be used to check whether or not
  *         Half-Duplex mode is supported by the USARTx instance.
  * @rmtoll CR3          HDSEL         LL_USART_EnableHalfDuplex
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableHalfDuplex(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_HDSEL);
}

/**
  * @brief  Disable Single Wire Half-Duplex mode
  * @note   Macro @ref IS_SCI_HALFDUPLEX_INSTANCE(USARTx) can be used to check whether or not
  *         Half-Duplex mode is supported by the USARTx instance.
  * @rmtoll CR3          HDSEL         LL_USART_DisableHalfDuplex
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableHalfDuplex(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_HDSEL);
}

/**
  * @brief  Indicate if Single Wire Half-Duplex mode is enabled
  * @note   Macro @ref IS_SCI_HALFDUPLEX_INSTANCE(USARTx) can be used to check whether or not
  *         Half-Duplex mode is supported by the USARTx instance.
  * @rmtoll CR3          HDSEL         LL_USART_IsEnabledHalfDuplex
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledHalfDuplex(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_HDSEL) == (USART_CR3_HDSEL));
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_Configuration_LIN Configuration functions related to LIN feature
  * @{
  */

/**
  * @brief  Set LIN Break Detection Length
  * @note   Macro @ref IS_SCI_LIN_INSTANCE(USARTx) can be used to check whether or not
  *         LIN feature is supported by the USARTx instance.
  * @rmtoll CR2          LBDL          LL_USART_SetLINBrkDetectionLen
  * @param  USARTx USART Instance
  * @param  LINBDLength This parameter can be one of the following values:
  *         @arg @ref LL_USART_LINBREAK_DETECT_10B
  *         @arg @ref LL_USART_LINBREAK_DETECT_11B
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetLINBrkDetectionLen(USART_TypeDef *USARTx, uint32_t LINBDLength)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_LBDL, LINBDLength);
}

/**
  * @brief  Return LIN Break Detection Length
  * @note   Macro @ref IS_SCI_LIN_INSTANCE(USARTx) can be used to check whether or not
  *         LIN feature is supported by the USARTx instance.
  * @rmtoll CR2          LBDL          LL_USART_GetLINBrkDetectionLen
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_LINBREAK_DETECT_10B
  *         @arg @ref LL_USART_LINBREAK_DETECT_11B
  */
__STATIC_INLINE uint32_t LL_USART_GetLINBrkDetectionLen(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_LBDL));
}

/**
  * @brief  Enable LIN mode
  * @note   Macro @ref IS_SCI_LIN_INSTANCE(USARTx) can be used to check whether or not
  *         LIN feature is supported by the USARTx instance.
  * @rmtoll CR2          LINEN         LL_USART_EnableLIN
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableLIN(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_LINEN);
}

/**
  * @brief  Disable LIN mode
  * @note   Macro @ref IS_SCI_LIN_INSTANCE(USARTx) can be used to check whether or not
  *         LIN feature is supported by the USARTx instance.
  * @rmtoll CR2          LINEN         LL_USART_DisableLIN
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableLIN(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_LINEN);
}

/**
  * @brief  Indicate if LIN mode is enabled
  * @note   Macro @ref IS_SCI_LIN_INSTANCE(USARTx) can be used to check whether or not
  *         LIN feature is supported by the USARTx instance.
  * @rmtoll CR2          LINEN         LL_USART_IsEnabledLIN
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledLIN(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR2, USART_CR2_LINEN) == (USART_CR2_LINEN));
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_Configuration_DE Configuration functions related to Driver Enable feature
  * @{
  */

/**
  * @brief  Set DEDT (Driver Enable De-Assertion Time), Time value expressed on 5 bits ([4:0] bits).
  * @note   Macro IS_UART_DRIVER_ENABLE_INSTANCE(USARTx) can be used to check whether or not
  *         Driver Enable feature is supported by the USARTx instance.
  * @rmtoll CR3          DEDT          LL_USART_SetDEDeassertionTime
  * @param  USARTx USART Instance
  * @param  Time Value between Min_Data=0 and Max_Data=31
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetDEDeassertionTime(USART_TypeDef *USARTx, uint32_t Time)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_DEDT, Time << USART_CR3_DEDT_Pos);
}

/**
  * @brief  Return DEDT (Driver Enable De-Assertion Time)
  * @note   Macro IS_UART_DRIVER_ENABLE_INSTANCE(USARTx) can be used to check whether or not
  *         Driver Enable feature is supported by the USARTx instance.
  * @rmtoll CR3          DEDT          LL_USART_GetDEDeassertionTime
  * @param  USARTx USART Instance
  * @retval Time value expressed on 5 bits ([4:0] bits) : Value between Min_Data=0 and Max_Data=31
  */
__STATIC_INLINE uint32_t LL_USART_GetDEDeassertionTime(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_DEDT) >> USART_CR3_DEDT_Pos);
}

/**
  * @brief  Set DEAT (Driver Enable Assertion Time), Time value expressed on 5 bits ([4:0] bits).
  * @note   Macro IS_UART_DRIVER_ENABLE_INSTANCE(USARTx) can be used to check whether or not
  *         Driver Enable feature is supported by the USARTx instance.
  * @rmtoll CR3          DEAT          LL_USART_SetDEAssertionTime
  * @param  USARTx USART Instance
  * @param  Time Value between Min_Data=0 and Max_Data=31
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetDEAssertionTime(USART_TypeDef *USARTx, uint32_t Time)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_DEAT, Time << USART_CR3_DEAT_Pos);
}

/**
  * @brief  Return DEAT (Driver Enable Assertion Time)
  * @note   Macro IS_UART_DRIVER_ENABLE_INSTANCE(USARTx) can be used to check whether or not
  *         Driver Enable feature is supported by the USARTx instance.
  * @rmtoll CR3          DEAT          LL_USART_GetDEAssertionTime
  * @param  USARTx USART Instance
  * @retval Time value expressed on 5 bits ([4:0] bits) : Value between Min_Data=0 and Max_Data=31
  */
__STATIC_INLINE uint32_t LL_USART_GetDEAssertionTime(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_DEAT) >> USART_CR3_DEAT_Pos);
}

/**
  * @brief  Enable Driver Enable (DE) Mode
  * @note   Macro IS_UART_DRIVER_ENABLE_INSTANCE(USARTx) can be used to check whether or not
  *         Driver Enable feature is supported by the USARTx instance.
  * @rmtoll CR2          DEM           LL_USART_EnableDEMode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableDEMode(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_DEM);
}

/**
  * @brief  Disable Driver Enable (DE) Mode
  * @note   Macro IS_UART_DRIVER_ENABLE_INSTANCE(USARTx) can be used to check whether or not
  *         Driver Enable feature is supported by the USARTx instance.
  * @rmtoll CR2          DEM           LL_USART_DisableDEMode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableDEMode(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_DEM);
}

/**
  * @brief  Indicate if Driver Enable (DE) Mode is enabled
  * @note   Macro IS_UART_DRIVER_ENABLE_INSTANCE(USARTx) can be used to check whether or not
  *         Driver Enable feature is supported by the USARTx instance.
  * @rmtoll CR2          DEM           LL_USART_IsEnabledDEMode
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledDEMode(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR2, USART_CR2_DEM) == (USART_CR2_DEM)) ? 1UL : 0UL);
}

/**
  * @brief  Select Driver Enable Polarity
  * @note   Macro IS_UART_DRIVER_ENABLE_INSTANCE(USARTx) can be used to check whether or not
  *         Driver Enable feature is supported by the USARTx instance.
  * @rmtoll CR2          DEP           LL_USART_SetDESignalPolarity
  * @param  USARTx USART Instance
  * @param  Polarity This parameter can be one of the following values:
  *         @arg @ref LL_USART_DE_POLARITY_HIGH
  *         @arg @ref LL_USART_DE_POLARITY_LOW
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetDESignalPolarity(USART_TypeDef *USARTx, uint32_t Polarity)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_DEP, Polarity);
}

/**
  * @brief  Return Driver Enable Polarity
  * @note   Macro IS_UART_DRIVER_ENABLE_INSTANCE(USARTx) can be used to check whether or not
  *         Driver Enable feature is supported by the USARTx instance.
  * @rmtoll CR2          DEP           LL_USART_GetDESignalPolarity
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_DE_POLARITY_HIGH
  *         @arg @ref LL_USART_DE_POLARITY_LOW
  */
__STATIC_INLINE uint32_t LL_USART_GetDESignalPolarity(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_DEP));
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_Configuration_SMARTCARD Configuration functions related to SMARTCARD feature
  * @{
  */

/**
  * @}
  */

/** @defgroup USART_LL_EF_AdvancedConfiguration Advanced Configurations services
  * @{
  */

/**
  * @brief  Perform basic configuration of USART for enabling use in Asynchronous Mode (SCI)
  * @note   In SCI mode, the following bits must be kept cleared:
  *           - LINEN bit in the USART_CR2 register,
  *           - CLKEN bit in the USART_CR2 register,
  *           - SCEN bit in the USART_CR3 register,
  *           - IREN bit in the USART_CR3 register,
  *           - HDSEL bit in the USART_CR3 register.
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Clear LINEN in CR2 using @ref LL_USART_DisableLIN() function
  *         - Clear CLKEN in CR2 using @ref LL_USART_DisableSCLKOutput() function
  *         - Clear SCEN in CR3 using @ref LL_USART_DisableSmartcard() function
  *         - Clear IREN in CR3 using @ref LL_USART_DisableIrda() function
  *         - Clear HDSEL in CR3 using @ref LL_USART_DisableHalfDuplex() function
  * @note   Other remaining configurations items related to Asynchronous Mode
  *         (as Baud Rate, Word length, Parity, ...) should be set using
  *         dedicated functions
  * @rmtoll CR2          LINEN         LL_USART_ConfigAsyncMode
  *         CR2          CLKEN         LL_USART_ConfigAsyncMode
  *         CR3          SCEN          LL_USART_ConfigAsyncMode
  *         CR3          IREN          LL_USART_ConfigAsyncMode
  *         CR3          HDSEL         LL_USART_ConfigAsyncMode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ConfigAsyncMode(USART_TypeDef *USARTx)
{
  /* In Asynchronous mode, the following bits must be kept cleared:
  - LINEN, CLKEN bits in the USART_CR2 register,
  - SCEN, IREN and HDSEL bits in the USART_CR3 register.*/
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_IREN | USART_CR3_HDSEL));
}

/**
  * @brief  Perform basic configuration of USART for enabling use in Synchronous Mode
  * @note   In Synchronous mode, the following bits must be kept cleared:
  *           - LINEN bit in the USART_CR2 register,
  *           - SCEN bit in the USART_CR3 register,
  *           - IREN bit in the USART_CR3 register,
  *           - HDSEL bit in the USART_CR3 register.
  *         This function also sets the USART in Synchronous mode.
  * @note   Macro @ref IS_USART_INSTANCE(USARTx) can be used to check whether or not
  *         Synchronous mode is supported by the USARTx instance.
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Clear LINEN in CR2 using @ref LL_USART_DisableLIN() function
  *         - Clear IREN in CR3 using @ref LL_USART_DisableIrda() function
  *         - Clear SCEN in CR3 using @ref LL_USART_DisableSmartcard() function
  *         - Clear HDSEL in CR3 using @ref LL_USART_DisableHalfDuplex() function
  *         - Set CLKEN in CR2 using @ref LL_USART_EnableSCLKOutput() function
  * @note   Other remaining configurations items related to Synchronous Mode
  *         (as Baud Rate, Word length, Parity, Clock Polarity, ...) should be set using
  *         dedicated functions
  * @rmtoll CR2          LINEN         LL_USART_ConfigSyncMode
  *         CR2          CLKEN         LL_USART_ConfigSyncMode
  *         CR3          SCEN          LL_USART_ConfigSyncMode
  *         CR3          IREN          LL_USART_ConfigSyncMode
  *         CR3          HDSEL         LL_USART_ConfigSyncMode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ConfigSyncMode(USART_TypeDef *USARTx)
{
  /* In Synchronous mode, the following bits must be kept cleared:
  - LINEN bit in the USART_CR2 register,
  - SCEN, IREN and HDSEL bits in the USART_CR3 register.*/
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_IREN | USART_CR3_HDSEL));
  /* set the UART/USART in Synchronous mode */
  SET_BIT(USARTx->CR2, USART_CR2_CLKEN);
}

/**
  * @brief  Perform basic configuration of USART for enabling use in LIN Mode
  * @note   In LIN mode, the following bits must be kept cleared:
  *           - STOP and CLKEN bits in the USART_CR2 register,
  *           - SCEN bit in the USART_CR3 register,
  *           - IREN bit in the USART_CR3 register,
  *           - HDSEL bit in the USART_CR3 register.
  *         This function also set the SCI/USART in LIN mode.
  * @note   Macro @ref IS_SCI_LIN_INSTANCE(USARTx) can be used to check whether or not
  *         LIN feature is supported by the USARTx instance.
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Clear CLKEN in CR2 using @ref LL_USART_DisableSCLKOutput() function
  *         - Clear STOP in CR2 using @ref LL_USART_SetStopBitsLength() function
  *         - Clear SCEN in CR3 using @ref LL_USART_DisableSmartcard() function
  *         - Clear IREN in CR3 using @ref LL_USART_DisableIrda() function
  *         - Clear HDSEL in CR3 using @ref LL_USART_DisableHalfDuplex() function
  *         - Set LINEN in CR2 using @ref LL_USART_EnableLIN() function
  * @note   Other remaining configurations items related to LIN Mode
  *         (as Baud Rate, Word length, LIN Break Detection Length, ...) should be set using
  *         dedicated functions
  * @rmtoll CR2          CLKEN         LL_USART_ConfigLINMode
  *         CR2          STOP          LL_USART_ConfigLINMode
  *         CR2          LINEN         LL_USART_ConfigLINMode
  *         CR3          IREN          LL_USART_ConfigLINMode
  *         CR3          SCEN          LL_USART_ConfigLINMode
  *         CR3          HDSEL         LL_USART_ConfigLINMode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ConfigLINMode(USART_TypeDef *USARTx)
{
  /* In LIN mode, the following bits must be kept cleared:
  - STOP and CLKEN bits in the USART_CR2 register,
  - IREN, SCEN and HDSEL bits in the USART_CR3 register.*/
  CLEAR_BIT(USARTx->CR2, (USART_CR2_CLKEN | USART_CR2_STOP));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_IREN | USART_CR3_SCEN | USART_CR3_HDSEL));
  /* Set the SCI/USART in LIN mode */
  SET_BIT(USARTx->CR2, USART_CR2_LINEN);
}

/**
  * @brief  Perform basic configuration of USART for enabling use in Half Duplex Mode
  * @note   In Half Duplex mode, the following bits must be kept cleared:
  *           - LINEN bit in the USART_CR2 register,
  *           - CLKEN bit in the USART_CR2 register,
  *           - SCEN bit in the USART_CR3 register,
  *           - IREN bit in the USART_CR3 register,
  *         This function also sets the SCI/USART in Half Duplex mode.
  * @note   Macro @ref IS_SCI_HALFDUPLEX_INSTANCE(USARTx) can be used to check whether or not
  *         Half-Duplex mode is supported by the USARTx instance.
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Clear LINEN in CR2 using @ref LL_USART_DisableLIN() function
  *         - Clear CLKEN in CR2 using @ref LL_USART_DisableSCLKOutput() function
  *         - Clear SCEN in CR3 using @ref LL_USART_DisableSmartcard() function
  *         - Clear IREN in CR3 using @ref LL_USART_DisableIrda() function
  *         - Set HDSEL in CR3 using @ref LL_USART_EnableHalfDuplex() function
  * @note   Other remaining configurations items related to Half Duplex Mode
  *         (as Baud Rate, Word length, Parity, ...) should be set using
  *         dedicated functions
  * @rmtoll CR2          LINEN         LL_USART_ConfigHalfDuplexMode
  *         CR2          CLKEN         LL_USART_ConfigHalfDuplexMode
  *         CR3          HDSEL         LL_USART_ConfigHalfDuplexMode
  *         CR3          SCEN          LL_USART_ConfigHalfDuplexMode
  *         CR3          IREN          LL_USART_ConfigHalfDuplexMode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ConfigHalfDuplexMode(USART_TypeDef *USARTx)
{
  /* In Half Duplex mode, the following bits must be kept cleared:
  - LINEN and CLKEN bits in the USART_CR2 register,
  - SCEN and IREN bits in the USART_CR3 register.*/
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_IREN));
  /* set the SCI/USART in Half Duplex mode */
  SET_BIT(USARTx->CR3, USART_CR3_HDSEL);
}

/**
  * @brief  Perform basic configuration of USART for enabling use in Smartcard Mode
  * @note   In Smartcard mode, the following bits must be kept cleared:
  *           - LINEN bit in the USART_CR2 register,
  *           - IREN bit in the USART_CR3 register,
  *           - HDSEL bit in the USART_CR3 register.
  *         This function also configures Stop bits to 1.5 bits and
  *         sets the USART in Smartcard mode (SCEN bit).
  *         Clock Output is also enabled (CLKEN).
  * @note   Macro @ref IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Clear LINEN in CR2 using @ref LL_USART_DisableLIN() function
  *         - Clear IREN in CR3 using @ref LL_USART_DisableIrda() function
  *         - Clear HDSEL in CR3 using @ref LL_USART_DisableHalfDuplex() function
  *         - Configure STOP in CR2 using @ref LL_USART_SetStopBitsLength() function
  *         - Set CLKEN in CR2 using @ref LL_USART_EnableSCLKOutput() function
  *         - Set SCEN in CR3 using @ref LL_USART_EnableSmartcard() function
  * @note   Other remaining configurations items related to Smartcard Mode
  *         (as Baud Rate, Word length, Parity, ...) should be set using
  *         dedicated functions
  * @rmtoll CR2          LINEN         LL_USART_ConfigSmartcardMode
  *         CR2          STOP          LL_USART_ConfigSmartcardMode
  *         CR2          CLKEN         LL_USART_ConfigSmartcardMode
  *         CR3          HDSEL         LL_USART_ConfigSmartcardMode
  *         CR3          SCEN          LL_USART_ConfigSmartcardMode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ConfigSmartcardMode(USART_TypeDef *USARTx)
{
  /* In Smartcard mode, the following bits must be kept cleared:
  - LINEN bit in the USART_CR2 register,
  - IREN and HDSEL bits in the USART_CR3 register.*/
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_IREN | USART_CR3_HDSEL));
  /* Configure Stop bits to 1.5 bits */
  /* Synchronous mode is activated by default */
  SET_BIT(USARTx->CR2, (USART_CR2_STOP_0 | USART_CR2_STOP_1 | USART_CR2_CLKEN));
  /* set the SCI/USART in Smartcard mode */
  SET_BIT(USARTx->CR3, USART_CR3_SCEN);
}

/**
  * @brief  Perform basic configuration of USART for enabling use in Irda Mode
  * @note   In IRDA mode, the following bits must be kept cleared:
  *           - LINEN bit in the USART_CR2 register,
  *           - STOP and CLKEN bits in the USART_CR2 register,
  *           - SCEN bit in the USART_CR3 register,
  *           - HDSEL bit in the USART_CR3 register.
  *         This function also sets the SCI/USART in IRDA mode (IREN bit).
  * @note   Macro @ref IS_IRDA_INSTANCE(USARTx) can be used to check whether or not
  *         IrDA feature is supported by the USARTx instance.
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Clear LINEN in CR2 using @ref LL_USART_DisableLIN() function
  *         - Clear CLKEN in CR2 using @ref LL_USART_DisableSCLKOutput() function
  *         - Clear SCEN in CR3 using @ref LL_USART_DisableSmartcard() function
  *         - Clear HDSEL in CR3 using @ref LL_USART_DisableHalfDuplex() function
  *         - Configure STOP in CR2 using @ref LL_USART_SetStopBitsLength() function
  *         - Set IREN in CR3 using @ref LL_USART_EnableIrda() function
  * @note   Other remaining configurations items related to Irda Mode
  *         (as Baud Rate, Word length, Power mode, ...) should be set using
  *         dedicated functions
  * @rmtoll CR2          LINEN         LL_USART_ConfigIrdaMode
  *         CR2          CLKEN         LL_USART_ConfigIrdaMode
  *         CR2          STOP          LL_USART_ConfigIrdaMode
  *         CR3          SCEN          LL_USART_ConfigIrdaMode
  *         CR3          HDSEL         LL_USART_ConfigIrdaMode
  *         CR3          IREN          LL_USART_ConfigIrdaMode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ConfigIrdaMode(USART_TypeDef *USARTx)
{
  /* In IRDA mode, the following bits must be kept cleared:
  - LINEN, STOP and CLKEN bits in the USART_CR2 register,
  - SCEN and HDSEL bits in the USART_CR3 register.*/
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN | USART_CR2_STOP));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL));
  /* set the SCI/USART in IRDA mode */
  SET_BIT(USARTx->CR3, USART_CR3_IREN);
}

/**
  * @brief  Perform basic configuration of USART for enabling use in Multi processor Mode
  *         (several USARTs connected in a network, one of the USARTs can be the master,
  *         its TX output connected to the RX inputs of the other slaves USARTs).
  * @note   In MultiProcessor mode, the following bits must be kept cleared:
  *           - LINEN bit in the USART_CR2 register,
  *           - CLKEN bit in the USART_CR2 register,
  *           - SCEN bit in the USART_CR3 register,
  *           - IREN bit in the USART_CR3 register,
  *           - HDSEL bit in the USART_CR3 register.
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Clear LINEN in CR2 using @ref LL_USART_DisableLIN() function
  *         - Clear CLKEN in CR2 using @ref LL_USART_DisableSCLKOutput() function
  *         - Clear SCEN in CR3 using @ref LL_USART_DisableSmartcard() function
  *         - Clear IREN in CR3 using @ref LL_USART_DisableIrda() function
  *         - Clear HDSEL in CR3 using @ref LL_USART_DisableHalfDuplex() function
  * @note   Other remaining configurations items related to Multi processor Mode
  *         (as Baud Rate, Wake Up Method, Node address, ...) should be set using
  *         dedicated functions
  * @rmtoll CR2          LINEN         LL_USART_ConfigMultiProcessMode
  *         CR2          CLKEN         LL_USART_ConfigMultiProcessMode
  *         CR3          SCEN          LL_USART_ConfigMultiProcessMode
  *         CR3          HDSEL         LL_USART_ConfigMultiProcessMode
  *         CR3          IREN          LL_USART_ConfigMultiProcessMode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ConfigMultiProcessMode(USART_TypeDef *USARTx)
{
  /* In Multi Processor mode, the following bits must be kept cleared:
  - LINEN and CLKEN bits in the USART_CR2 register,
  - IREN, SCEN and HDSEL bits in the USART_CR3 register.*/
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_FLAG_Management FLAG Management
  * @{
  */

/**
  * @brief  Check if the USART Parity Error Flag is set or not
  * @rmtoll SR           PE            LL_USART_IsActiveFlag_PE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_PE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_PE) == (USART_SR_PE));
}

/**
  * @brief  Check if the USART Framing Error Flag is set or not
  * @rmtoll SR           FE            LL_USART_IsActiveFlag_FE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_FE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_FE) == (USART_SR_FE));
}

/**
  * @brief  Check if the USART Noise error detected Flag is set or not
  * @rmtoll SR           NF            LL_USART_IsActiveFlag_NE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_NE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_NE) == (USART_SR_NE));
}

/**
  * @brief  Check if the USART OverRun Error Flag is set or not
  * @rmtoll SR           ORE           LL_USART_IsActiveFlag_ORE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_ORE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_ORE) == (USART_SR_ORE));
}

/**
  * @brief  Check if the USART IDLE line detected Flag is set or not
  * @rmtoll SR           IDLE          LL_USART_IsActiveFlag_IDLE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_IDLE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_IDLE) == (USART_SR_IDLE));
}

/**
  * @brief  Check if the USART Read Data Register Not Empty Flag is set or not
  * @rmtoll SR           RXNE          LL_USART_IsActiveFlag_RXNE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RXNE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_RXNE) == (USART_SR_RXNE));
}

/**
  * @brief  Check if the USART Transmission Complete Flag is set or not
  * @rmtoll SR           TC            LL_USART_IsActiveFlag_TC
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TC(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_TC) == (USART_SR_TC));
}

/**
  * @brief  Check if the USART Transmit Data Register Empty Flag is set or not
  * @rmtoll SR           TXE           LL_USART_IsActiveFlag_TXE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TXE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_TXE) == (USART_SR_TXE));
}

/**
  * @brief  Check if the USART LIN Break Detection Flag is set or not
  * @note   Macro @ref IS_SCI_LIN_INSTANCE(USARTx) can be used to check whether or not
  *         LIN feature is supported by the USARTx instance.
  * @rmtoll SR           LBD           LL_USART_IsActiveFlag_LBD
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_LBD(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_LBD) == (USART_SR_LBD));
}

/**
  * @brief  Check if the USART CTS Flag is set or not
  * @note   Macro @ref IS_SCI_HWFLOW_INSTANCE(USARTx) can be used to check whether or not
  *         Hardware Flow control feature is supported by the USARTx instance.
  * @rmtoll SR           CTS           LL_USART_IsActiveFlag_nCTS
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_nCTS(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_CTS) == (USART_SR_CTS));
}

/**
  * @brief  Check if the USART ABRF Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_ABRF(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_ABRF) == (USART_SR_ABRF));
}

/**
  * @brief  Check if the USART ABRE Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_ABRE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_ABRE) == (USART_SR_ABRE));
}

/**
  * @brief  Check if the USART End Of Block Flag is set or not
  * @note   Macro IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @rmtoll SR          EOBF          LL_USART_IsActiveFlag_EOB
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_EOB(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_EOBF) == (USART_SR_EOBF));
}

/**
  * @brief  Check if the USART Receiver Time Out Flag is set or not
  * @rmtoll SR          RTOF          LL_USART_IsActiveFlag_RTO
  * @note   Macro IS_SMARTCARD_INSTANCE(USARTx) can be used to check whether or not
  *         Smartcard feature is supported by the USARTx instance.
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RTO(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->SR, USART_SR_RTOF) == (USART_SR_RTOF));
}

/**
  * @brief  Check if the USART TX FIFO Empty Flag is set or not
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll SR          TXFE          LL_USART_IsActiveFlag_TXFE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TXFE(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->SR, USART_SR_TXFE) == (USART_SR_TXFE)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the USART RX FIFO Full Flag is set or not
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll SR          RXFF          LL_USART_IsActiveFlag_RXFF
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RXFF(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->SR, USART_SR_RXFF) == (USART_SR_RXFF)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the USART TX FIFO Threshold Flag is set or not
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll SR          TXFT          LL_USART_IsActiveFlag_TXFT
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TXFT(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->SR, USART_SR_TXFT) == (USART_SR_TXFT)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the USART RX FIFO Threshold Flag is set or not
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll SR          RXFT          LL_USART_IsActiveFlag_RXFT
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RXFT(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->SR, USART_SR_RXFT) == (USART_SR_RXFT)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the USART Send Break Flag is set or not
  * @rmtoll CR1          SBK           LL_USART_IsActiveFlag_SBK
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_SBK(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_SBK) == (USART_CR1_SBK));
}

/**
  * @brief  Check if the USART Receive Wake Up from mute mode Flag is set or not
  * @rmtoll CR1          RWU           LL_USART_IsActiveFlag_RWU
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RWU(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_RWU) == (USART_CR1_RWU));
}

/**
  * @brief  Clear Parity Error Flag
  * @note   Clearing this flag is done by a read access to the USARTx_SR
  *         register followed by a read access to the USARTx_DR register.
  * @note   Please also consider that when clearing this flag, other flags as
  *         NE, FE, ORE, IDLE would also be cleared.
  * @rmtoll SR           PE            LL_USART_ClearFlag_PE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ClearFlag_PE(USART_TypeDef *USARTx)
{
  __IO uint32_t tmpreg;
  tmpreg = USARTx->SR;
  (void) tmpreg;
  tmpreg = USARTx->DR;
  (void) tmpreg;
}

/**
  * @brief  Clear Framing Error Flag
  * @note   Clearing this flag is done by a read access to the USARTx_SR
  *         register followed by a read access to the USARTx_DR register.
  * @note   Please also consider that when clearing this flag, other flags as
  *         PE, NE, ORE, IDLE would also be cleared.
  * @rmtoll SR           FE            LL_USART_ClearFlag_FE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ClearFlag_FE(USART_TypeDef *USARTx)
{
  __IO uint32_t tmpreg;
  tmpreg = USARTx->SR;
  (void) tmpreg;
  tmpreg = USARTx->DR;
  (void) tmpreg;
}

/**
  * @brief  Clear Noise detected Flag
  * @note   Clearing this flag is done by a read access to the USARTx_SR
  *         register followed by a read access to the USARTx_DR register.
  * @note   Please also consider that when clearing this flag, other flags as
  *         PE, FE, ORE, IDLE would also be cleared.
  * @rmtoll SR           NF            LL_USART_ClearFlag_NE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ClearFlag_NE(USART_TypeDef *USARTx)
{
  __IO uint32_t tmpreg;
  tmpreg = USARTx->SR;
  (void) tmpreg;
  tmpreg = USARTx->DR;
  (void) tmpreg;
}

/**
  * @brief  Clear OverRun Error Flag
  * @note   Clearing this flag is done by a read access to the USARTx_SR
  *         register followed by a read access to the USARTx_DR register.
  * @note   Please also consider that when clearing this flag, other flags as
  *         PE, NE, FE, IDLE would also be cleared.
  * @rmtoll SR           ORE           LL_USART_ClearFlag_ORE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ClearFlag_ORE(USART_TypeDef *USARTx)
{
  __IO uint32_t tmpreg;
  tmpreg = USARTx->SR;
  (void) tmpreg;
  tmpreg = USARTx->DR;
  (void) tmpreg;
}

/**
  * @brief  Clear IDLE line detected Flag
  * @note   Clearing this flag is done by a read access to the USARTx_SR
  *         register followed by a read access to the USARTx_DR register.
  * @note   Please also consider that when clearing this flag, other flags as
  *         PE, NE, FE, ORE would also be cleared.
  * @rmtoll SR           IDLE          LL_USART_ClearFlag_IDLE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ClearFlag_IDLE(USART_TypeDef *USARTx)
{
  __IO uint32_t tmpreg;
  tmpreg = USARTx->SR;
  (void) tmpreg;
  tmpreg = USARTx->DR;
  (void) tmpreg;
}

/**
  * @brief  Clear RXNE line detected Flag
  * @note   Clearing this flag is done by a read access to the USARTx_DR
  *         register.
  * @rmtoll SR           RXNE          LL_USART_ClearFlag_RXNE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ClearFlag_RXNE(USART_TypeDef *USARTx)
{
  __IO uint32_t tmpreg;
  tmpreg = USARTx->DR;
  (void) tmpreg;
}

/**
  * @brief  Clear Transmission Complete Flag
  * @rmtoll SR           TC            LL_USART_ClearFlag_TC
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ClearFlag_TC(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->SR, ~(USART_SR_TC));
}

/**
  * @brief  Clear LIN Break Detection Flag
  * @note   Macro @ref IS_SCI_LIN_INSTANCE(USARTx) can be used to check whether or not
  *         LIN feature is supported by the USARTx instance.
  * @rmtoll SR           LBD           LL_USART_ClearFlag_LBD
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ClearFlag_LBD(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->SR, ~(USART_SR_LBD));
}

/**
  * @brief  Clear CTS Interrupt Flag
  * @note   Macro @ref IS_SCI_HWFLOW_INSTANCE(USARTx) can be used to check whether or not
  *         Hardware Flow control feature is supported by the USARTx instance.
  * @rmtoll SR           CTS           LL_USART_ClearFlag_nCTS
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ClearFlag_nCTS(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->SR, ~(USART_SR_CTS));
}

/**
  * @brief  Clear EOBF Interrupt Flag
  * @rmtoll SR           EOBF           LL_USART_ClearFlag_EOB
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ClearFlag_EOB(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->SR, ~(USART_SR_EOBF));
}

/**
  * @brief  Clear RTOF Interrupt Flag
  * @rmtoll SR           RTOF           LL_USART_ClearFlag_RTOF
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_ClearFlag_RTO(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->SR, ~(USART_SR_RTOF));
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_IT_Management IT Management
  * @{
  */

/**
  * @brief  Enable IDLE Interrupt
  * @rmtoll CR1          IDLEIE        LL_USART_EnableIT_IDLE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_IDLE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_IDLEIE);
}

/**
  * @brief  Enable RX Not Empty Interrupt
  * @rmtoll CR1          RXNEIE        LL_USART_EnableIT_RXNE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_RXNE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_RXNEIE);
}

/**
  * @brief  Enable Transmission Complete Interrupt
  * @rmtoll CR1          TCIE          LL_USART_EnableIT_TC
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_TC(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_TCIE);
}

/**
  * @brief  Enable TX Empty Interrupt
  * @rmtoll CR1          TXEIE         LL_USART_EnableIT_TXE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_TXE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_TXEIE);
}

/**
  * @brief  Enable Parity Error Interrupt
  * @rmtoll CR1          PEIE          LL_USART_EnableIT_PE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_PE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_PEIE);
}

/**
  * @brief  Enable LIN Break Detection Interrupt
  * @note   Macro @ref IS_SCI_LIN_INSTANCE(USARTx) can be used to check whether or not
  *         LIN feature is supported by the USARTx instance.
  * @rmtoll CR2          LBDIE         LL_USART_EnableIT_LBD
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_LBD(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_LBDIE);
}

/**
  * @brief  Enable Error Interrupt
  * @note   When set, Error Interrupt Enable Bit is enabling interrupt generation in case of a framing
  *         error, overrun error or noise flag (FE=1 or ORE=1 or NF=1 in the USARTx_SR register).
  *           0: Interrupt is inhibited
  *           1: An interrupt is generated when FE=1 or ORE=1 or NF=1 in the USARTx_SR register.
  * @rmtoll CR3          EIE           LL_USART_EnableIT_ERROR
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_ERROR(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_EIE);
}

/**
  * @brief  Enable CTS Interrupt
  * @note   Macro @ref IS_SCI_HWFLOW_INSTANCE(USARTx) can be used to check whether or not
  *         Hardware Flow control feature is supported by the USARTx instance.
  * @rmtoll CR3          CTSIE         LL_USART_EnableIT_CTS
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_CTS(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_CTSIE);
}

/**
  * @brief  Enable RTO Interrupt
  * @rmtoll CR3          RTOIE         LL_USART_EnableIT_RTO
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_RTO(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_RTOIE);
}

/**
  * @brief  Enable EOB Interrupt
  * @rmtoll CR3          EOBIE         LL_USART_EnableIT_EOB
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_EOB(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_EOBIE);
}

/**
  * @brief  Enable TX FIFO Empty Interrupt
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR3          TXFEIE        LL_USART_EnableIT_TXFE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_TXFE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_TXFEIE);
}

/**
  * @brief  Enable RX FIFO Full Interrupt
  * @rmtoll CR3          RXFFIE        LL_USART_EnableIT_RXFF
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_RXFF(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_RXFFIE);
}

/**
  * @brief  Enable TX FIFO Threshold Interrupt
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR3          TXFTIE        LL_USART_EnableIT_TXFT
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_TXFT(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_TXFTIE);
}

/**
  * @brief  Enable RX FIFO Threshold Interrupt
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR3          RXFTIE        LL_USART_EnableIT_RXFT
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableIT_RXFT(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_RXFTIE);
}

/**
  * @brief  Disable IDLE Interrupt
  * @rmtoll CR1          IDLEIE        LL_USART_DisableIT_IDLE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_IDLE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_IDLEIE);
}

/**
  * @brief  Disable RX Not Empty Interrupt
  * @rmtoll CR1          RXNEIE        LL_USART_DisableIT_RXNE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_RXNE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_RXNEIE);
}

/**
  * @brief  Disable Transmission Complete Interrupt
  * @rmtoll CR1          TCIE          LL_USART_DisableIT_TC
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_TC(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_TCIE);
}

/**
  * @brief  Disable TX Empty Interrupt
  * @rmtoll CR1          TXEIE         LL_USART_DisableIT_TXE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_TXE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_TXEIE);
}

/**
  * @brief  Disable Parity Error Interrupt
  * @rmtoll CR1          PEIE          LL_USART_DisableIT_PE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_PE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_PEIE);
}

/**
  * @brief  Disable LIN Break Detection Interrupt
  * @note   Macro @ref IS_SCI_LIN_INSTANCE(USARTx) can be used to check whether or not
  *         LIN feature is supported by the USARTx instance.
  * @rmtoll CR2          LBDIE         LL_USART_DisableIT_LBD
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_LBD(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_LBDIE);
}

/**
  * @brief  Disable Error Interrupt
  * @note   When set, Error Interrupt Enable Bit is enabling interrupt generation in case of a framing
  *         error, overrun error or noise flag (FE=1 or ORE=1 or NF=1 in the USARTx_SR register).
  *           0: Interrupt is inhibited
  *           1: An interrupt is generated when FE=1 or ORE=1 or NF=1 in the USARTx_SR register.
  * @rmtoll CR3          EIE           LL_USART_DisableIT_ERROR
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_ERROR(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_EIE);
}

/**
  * @brief  Disable CTS Interrupt
  * @note   Macro @ref IS_SCI_HWFLOW_INSTANCE(USARTx) can be used to check whether or not
  *         Hardware Flow control feature is supported by the USARTx instance.
  * @rmtoll CR3          CTSIE         LL_USART_DisableIT_CTS
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_CTS(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_CTSIE);
}

/**
  * @brief  Disable RTO Interrupt
  * @rmtoll CR3          RTOIE         LL_USART_DisableIT_RTO
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_RTO(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_RTOIE);
}

/**
  * @brief  Disable EOB Interrupt
  * @rmtoll CR3          EOBIE         LL_USART_DisableIT_EOB
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_EOB(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_EOBIE);
}

/**
  * @brief  Disable TX FIFO Empty Interrupt
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR3          TXFEIE        LL_USART_DisableIT_TXFE
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_TXFE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_TXFEIE);
}

/**
  * @brief  Disable RX FIFO Full Interrupt
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR3          RXFFIE        LL_USART_DisableIT_RXFF
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_RXFF(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_RXFFIE);
}

/**
  * @brief  Check if the USART IDLE Interrupt  source is enabled or disabled.
  * @rmtoll CR1          IDLEIE        LL_USART_IsEnabledIT_IDLE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_IDLE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_IDLEIE) == (USART_CR1_IDLEIE));
}

/**
  * @brief  Disable TX FIFO Threshold Interrupt
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR3          TXFTIE        LL_USART_DisableIT_TXFT
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_TXFT(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_TXFTIE);
}

/**
  * @brief  Disable RX FIFO Threshold Interrupt
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR3          RXFTIE        LL_USART_DisableIT_RXFT
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableIT_RXFT(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_RXFTIE);
}

/**
  * @brief  Check if the USART RX Not Empty Interrupt is enabled or disabled.
  * @rmtoll CR1          RXNEIE        LL_USART_IsEnabledIT_RXNE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_RXNE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_RXNEIE) == (USART_CR1_RXNEIE));
}

/**
  * @brief  Check if the USART Transmission Complete Interrupt is enabled or disabled.
  * @rmtoll CR1          TCIE          LL_USART_IsEnabledIT_TC
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TC(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_TCIE) == (USART_CR1_TCIE));
}

/**
  * @brief  Check if the USART TX Empty Interrupt is enabled or disabled.
  * @rmtoll CR1          TXEIE         LL_USART_IsEnabledIT_TXE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TXE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_TXEIE) == (USART_CR1_TXEIE));
}

/**
  * @brief  Check if the USART Parity Error Interrupt is enabled or disabled.
  * @rmtoll CR1          PEIE          LL_USART_IsEnabledIT_PE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_PE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_PEIE) == (USART_CR1_PEIE));
}

/**
  * @brief  Check if the USART LIN Break Detection Interrupt is enabled or disabled.
  * @note   Macro @ref IS_SCI_LIN_INSTANCE(USARTx) can be used to check whether or not
  *         LIN feature is supported by the USARTx instance.
  * @rmtoll CR2          LBDIE         LL_USART_IsEnabledIT_LBD
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_LBD(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR2, USART_CR2_LBDIE) == (USART_CR2_LBDIE));
}

/**
  * @brief  Check if the USART Error Interrupt is enabled or disabled.
  * @rmtoll CR3          EIE           LL_USART_IsEnabledIT_ERROR
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_ERROR(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_EIE) == (USART_CR3_EIE));
}

/**
  * @brief  Check if the USART CTS Interrupt is enabled or disabled.
  * @note   Macro @ref IS_SCI_HWFLOW_INSTANCE(USARTx) can be used to check whether or not
  *         Hardware Flow control feature is supported by the USARTx instance.
  * @rmtoll CR3          CTSIE         LL_USART_IsEnabledIT_CTS
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_CTS(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_CTSIE) == (USART_CR3_CTSIE));
}

/**
  * @brief  Check if the USART RTO Interrupt is enabled or disabled.
  * @rmtoll CR3          RTOIE         LL_USART_IsEnabledIT_RTO
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_RTO(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_RTOIE) == (USART_CR3_RTOIE));
}

/**
  * @brief  Check if the USART EOB Interrupt is enabled or disabled.
  * @rmtoll CR3          EOBIE         LL_USART_IsEnabledIT_EOB
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_EOB(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_EOBIE) == (USART_CR3_EOBIE));
}

/**
  * @brief  Check if the USART TX FIFO Empty Interrupt is enabled or disabled
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR3          TXFEIE        LL_USART_IsEnabledIT_TXFE
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TXFE(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_TXFEIE) == (USART_CR3_TXFEIE)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the USART RX FIFO Full Interrupt is enabled or disabled
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR3          RXFFIE        LL_USART_IsEnabledIT_RXFF
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_RXFF(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_RXFFIE) == (USART_CR3_RXFFIE)) ? 1UL : 0UL);
}

/**
  * @brief  Check if USART TX FIFO Threshold Interrupt is enabled or disabled
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR3          TXFTIE        LL_USART_IsEnabledIT_TXFT
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TXFT(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_TXFTIE) == (USART_CR3_TXFTIE)) ? 1UL : 0UL);
}

/**
  * @brief  Check if USART RX FIFO Threshold Interrupt is enabled or disabled
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR3          RXFTIE        LL_USART_IsEnabledIT_RXFT
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_RXFT(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_RXFTIE) == (USART_CR3_RXFTIE)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_DMA_Management DMA_Management
  * @{
  */

/**
  * @brief  Enable DMA Mode for reception
  * @rmtoll CR3          DMAR          LL_USART_EnableDMAReq_RX
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableDMAReq_RX(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_DMAR);
}

/**
  * @brief  Disable DMA Mode for reception
  * @rmtoll CR3          DMAR          LL_USART_DisableDMAReq_RX
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableDMAReq_RX(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_DMAR);
}

/**
  * @brief  Check if DMA Mode is enabled for reception
  * @rmtoll CR3          DMAR          LL_USART_IsEnabledDMAReq_RX
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledDMAReq_RX(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_DMAR) == (USART_CR3_DMAR));
}

/**
  * @brief  Enable DMA Mode for transmission
  * @rmtoll CR3          DMAT          LL_USART_EnableDMAReq_TX
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableDMAReq_TX(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_DMAT);
}

/**
  * @brief  Disable DMA Mode for transmission
  * @rmtoll CR3          DMAT          LL_USART_DisableDMAReq_TX
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableDMAReq_TX(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_DMAT);
}

/**
  * @brief  Check if DMA Mode is enabled for transmission
  * @rmtoll CR3          DMAT          LL_USART_IsEnabledDMAReq_TX
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledDMAReq_TX(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_DMAT) == (USART_CR3_DMAT));
}

/**
  * @brief  Get the data register address used for DMA transfer
  * @rmtoll DR           DR            LL_USART_DMA_GetRegAddr
  * @note   Address of Data Register is valid for both Transmit and Receive transfers.
  * @param  USARTx USART Instance
  * @retval Address of data register
  */
__STATIC_INLINE uint32_t LL_USART_DMA_GetRegAddr(USART_TypeDef *USARTx)
{
  /* return address of DR register */
  return ((uint32_t) & (USARTx->DR));
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_Data_Management Data_Management
  * @{
  */

/**
  * @brief  Read Receiver Data register (Receive Data value, 8 bits)
  * @rmtoll DR           DR            LL_USART_ReceiveData8
  * @param  USARTx USART Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint8_t LL_USART_ReceiveData8(USART_TypeDef *USARTx)
{
  return (uint8_t)(READ_BIT(USARTx->DR, USART_DR_DR));
}

/**
  * @brief  Read Receiver Data register (Receive Data value, 9 bits)
  * @rmtoll DR           DR            LL_USART_ReceiveData9
  * @param  USARTx USART Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x1FF
  */
__STATIC_INLINE uint16_t LL_USART_ReceiveData9(USART_TypeDef *USARTx)
{
  return (uint16_t)(READ_BIT(USARTx->DR, USART_DR_DR));
}

/**
  * @brief  Write in Transmitter Data Register (Transmit Data value, 8 bits)
  * @rmtoll DR           DR            LL_USART_TransmitData8
  * @param  USARTx USART Instance
  * @param  Value between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE void LL_USART_TransmitData8(USART_TypeDef *USARTx, uint8_t Value)
{
  USARTx->DR = Value;
}

/**
  * @brief  Write in Transmitter Data Register (Transmit Data value, 9 bits)
  * @rmtoll DR           DR            LL_USART_TransmitData9
  * @param  USARTx USART Instance
  * @param  Value between Min_Data=0x00 and Max_Data=0x1FF
  * @retval None
  */
__STATIC_INLINE void LL_USART_TransmitData9(USART_TypeDef *USARTx, uint16_t Value)
{
  USARTx->DR = Value & 0x1FFU;
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_Execution Execution
  * @{
  */

/**
  * @brief  Request Break sending
  * @rmtoll CR1          SBK           LL_USART_RequestBreakSending
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_RequestBreakSending(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_SBK);
}

/**
  * @brief  Put USART in Mute mode
  * @rmtoll CR1          RWU           LL_USART_RequestEnterMuteMode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_RequestEnterMuteMode(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_RWU);
}

/**
  * @brief  Put USART in Active mode
  * @rmtoll CR1          RWU           LL_USART_RequestExitMuteMode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_RequestExitMuteMode(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_RWU);
}

/**
  * @brief  Enable automatic baud rate detection
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_EnableAutoBaudRate(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_ABREN);
}

/**
  * @brief  Disable automatic baud rate detection
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_DisableAutoBaudRate(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_ABREN);
}

/**
  * @brief  Indicate if enable automatic baud rate detection
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_USART_IsEnabledAutoBaudRate(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_ABREN) == (USART_CR3_ABREN));
}

/**
  * @brief  Set auto baud rate detection mode
  * @param  USARTx USART Instance
  * @param  mode This parameter can be one of the following values:
  *         @arg @ref LL_USART_AUTOBAUD_DETECT_ON_STARTBIT
  *         @arg @ref LL_USART_AUTOBAUD_DETECT_ON_FALLINGEDGE
  * @retval None
  */
__STATIC_INLINE void LL_USART_SetAutoBaudRateMode(USART_TypeDef *USARTx, uint32_t mode)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_ABRMOD, mode);
}

/**
  * @brief  Get auto baud rate detection mode
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_USART_AUTOBAUD_DETECT_ON_STARTBIT
  *         @arg @ref LL_USART_AUTOBAUD_DETECT_ON_FALLINGEDGE
  */
__STATIC_INLINE uint32_t LL_USART_GetAutoBaudRateMode(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_ABRMOD));
}

/**
  * @brief  Request automatic baud rate detection
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_SendAutoBaudRateReq(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->SR, USART_SR_ABRRQ);
}

/**
  * @brief  Request a Receive Data and FIFO flush
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @note   Allows to discard the received data without reading them, and avoid an overrun
  *         condition.
  * @rmtoll CR1          RXFRQ         LL_USART_RequestRxDataFlush
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_RequestRxDataFlush(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, (uint16_t)USART_CR1_RXFRQ);
}

/**
  * @brief  Request a Transmit data and FIFO flush
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll CR1          TXFRQ         LL_USART_RequestTxDataFlush
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void LL_USART_RequestTxDataFlush(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, (uint16_t)USART_CR1_TXFRQ);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup USART_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_USART_DeInit(USART_TypeDef *USARTx);
ErrorStatus LL_USART_Init(USART_TypeDef *USARTx, LL_USART_InitTypeDef *USART_InitStruct);
void        LL_USART_StructInit(LL_USART_InitTypeDef *USART_InitStruct);
ErrorStatus LL_USART_ClockInit(USART_TypeDef *USARTx, LL_USART_ClockInitTypeDef *USART_ClockInitStruct);
void        LL_USART_ClockStructInit(LL_USART_ClockInitTypeDef *USART_ClockInitStruct);
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

#endif /* USART1 || USART2 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32E407_LL_USART_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
