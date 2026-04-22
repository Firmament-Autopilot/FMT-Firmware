/*******************************************************************************
 * File Name: cycfg_routing.h
 *
 * Description:
 * Establishes all necessary connections between hardware elements.
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.70.0
 * device-db 4.37.0.10260
 * mtb-dsl-pse8xxgp 1.2.0.895
 *
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#if !defined(CYCFG_ROUTING_H)
#define CYCFG_ROUTING_H

#include "cycfg_notices.h"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define ioss_0_port_0_pin_1_HSIOM P0_1_SMIF1_SMIF0_SPIHB_SELECT2
#define ioss_0_port_2_pin_0_HSIOM P2_0_SMIF0_SMIF0_SPIHB_SELECT1
#define ioss_0_port_3_pin_0_HSIOM P3_0_I3C_I3C_SCL
#define ioss_0_port_3_pin_1_HSIOM P3_1_I3C_I3C_SDA
#define ioss_0_port_6_pin_5_HSIOM P6_5_SCB2_UART_RX
#define ioss_0_port_6_pin_7_HSIOM P6_7_SCB2_UART_TX
#define ioss_0_port_7_pin_0_HSIOM P7_0_SDHC1_CARD_CMD
#define ioss_0_port_7_pin_1_HSIOM P7_1_SDHC1_CLK_CARD
#define ioss_0_port_7_pin_3_HSIOM P7_3_SDHC1_CARD_DAT_3TO00
#define ioss_0_port_7_pin_5_HSIOM P7_5_SDHC1_CARD_DAT_3TO01
#define ioss_0_port_7_pin_6_HSIOM P7_6_SDHC1_CARD_DAT_3TO02
#define ioss_0_port_7_pin_7_HSIOM P7_7_SDHC1_CARD_DAT_3TO03
#define ioss_0_port_8_pin_0_HSIOM P8_0_SCB0_I2C_SCL
#define ioss_0_port_8_pin_1_HSIOM P8_1_SCB0_I2C_SDA
#define ioss_0_port_9_pin_0_HSIOM P9_0_TCPWM0_LINE7
#define ioss_0_port_9_pin_2_HSIOM P9_2_TCPWM0_LINE_COMPL7
#define ioss_0_port_10_pin_0_HSIOM P10_0_SCB4_UART_RX
#define ioss_0_port_10_pin_1_HSIOM P10_1_SCB4_UART_TX
#define ioss_0_port_10_pin_5_HSIOM P10_5_ETH_RX_CTL
#define ioss_0_port_10_pin_6_HSIOM P10_6_ETH_RXD0
#define ioss_0_port_10_pin_7_HSIOM P10_7_ETH_RXD1
#define ioss_0_port_11_pin_1_HSIOM P11_1_PERI1_TR_IO_INPUT1
#define ioss_0_port_11_pin_2_HSIOM P11_2_ETH_TXD0
#define ioss_0_port_11_pin_3_HSIOM P11_3_ETH_TXD1
#define ioss_0_port_11_pin_4_HSIOM P11_4_ETH_TX_CTL
#define ioss_0_port_11_pin_7_HSIOM P11_7_ETH_REF_CLK
#define ioss_0_port_13_pin_1_HSIOM P13_1_ETH_MDC
#define ioss_0_port_13_pin_6_HSIOM P13_6_ETH_MDIO
#define ioss_0_port_16_pin_0_HSIOM P16_0_SCB10_SPI_CLK
#define ioss_0_port_16_pin_1_HSIOM P16_1_SCB10_SPI_MOSI
#define ioss_0_port_16_pin_2_HSIOM P16_2_SCB10_SPI_MISO
#define ioss_0_port_16_pin_3_HSIOM P16_3_SCB10_SPI_SELECT0
#define ioss_0_port_16_pin_5_HSIOM P16_5_TCPWM0_LINE5
#define ioss_0_port_17_pin_0_HSIOM P17_0_SCB5_UART_RX
#define ioss_0_port_17_pin_1_HSIOM P17_1_SCB5_UART_TX
#define ioss_0_port_21_pin_4_HSIOM P21_4_SCB3_SPI_MISO
#define ioss_0_port_21_pin_5_HSIOM P21_5_SCB3_SPI_MOSI
#define ioss_0_port_21_pin_6_HSIOM P21_6_SCB3_SPI_CLK
#define CYBSP_ARD_D7_digital_in_0_TRIGGER_IN PERI_0_TRIG_IN_MUX_3_PERI1_HSIOM_TR_OUT1
#define CYBSP_ETH_RX_ER_digital_in_0_TRIGGER_IN CYBSP_ARD_D7_digital_in_0_TRIGGER_IN
#define CYBSP_UART2_tr_tx_req_0_TRIGGER_IN PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT2
#define CYBSP_UART2_TX_DMA_tr_in_0_TRIGGER_OUT PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN1
#define CYBSP_UART5_tr_tx_req_0_TRIGGER_IN PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT5
#define CYBSP_UART5_TX_DMA_tr_in_0_TRIGGER_OUT PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN2
#define RC_TIMER_capture0_0_TRIGGER_OUT PERI_0_TRIG_OUT_MUX_3_TCPWM0_ALL_CNT_TR_IN27
#define TCPWM0_GRP1_CNT20_CAPTURE0_VALUE 0x1E

void init_cycfg_routing(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_ROUTING_H */
