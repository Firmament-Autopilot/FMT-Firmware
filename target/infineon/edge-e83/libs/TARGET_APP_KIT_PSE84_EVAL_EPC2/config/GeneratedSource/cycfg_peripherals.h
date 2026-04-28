/*******************************************************************************
 * File Name: cycfg_peripherals.h
 *
 * Description:
 * Analog configuration
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

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_autanalog.h"
#include "cy_sysclk.h"
#include "cy_i3c.h"
#include "cy_scb_i2c.h"
#include "cy_scb_uart.h"
#include "cy_scb_spi.h"
#include "cy_sd_host.h"
#include "cy_smif.h"
#include "cycfg_qspi_memslot.h"
#include "cy_mcwdt.h"
#include "cy_tcpwm_pwm.h"
#include "cycfg_routing.h"
#include "cy_tcpwm_counter.h"

#if defined (COMPONENT_MTB_HAL)
#include "mtb_hal.h"
#include "cycfg_peripheral_clocks.h"
#include "mtb_hal_hw_types.h"
#include "mtb_hal_clock.h"
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define CYBSP_AUTONOMOUS_ANALOG_ENABLED 1U
#define AUTANALOG_CLOCK_DIV_PRIO_HS_DEFAULT 20
#define CYBSP_AUTONOMOUS_ANALOG_lppass_IRQ pass_interrupt_lppass_IRQn
#define CYBSP_AUTONOMOUS_ANALOG_fifo_IRQ pass_interrupt_fifo_IRQn
#define CYBSP_AUTONOMOUS_CONTROLLER_ENABLED 1U
#define CYBSP_SAR_ADC_ENABLED 1U
#define CYBSP_AUTONOMOUS_CONTROLLER_STATE_0_ENABLED 1U
#define CYBSP_AUTONOMOUS_CONTROLLER_STATE_1_ENABLED 1U
#define CYBSP_AUTONOMOUS_CONTROLLER_STATE_2_ENABLED 1U
#define pass_0_sar_0_gpiochan_0_ENABLED 1U
#define pass_0_sar_0_gpiochan_1_ENABLED 1U
#define pass_0_sar_0_gpiochan_2_ENABLED 1U
#define pass_0_sar_0_gpiochan_3_ENABLED 1U
#define CYBSP_SAR_ADC_SCAN_GRP_0_ENABLED 1U
#define CYBSP_SAR_ADC_SCAN_GRP_0_SCAN_0_ENABLED 1U
#define pass_0_sar_0_group_0_scan_1_ENABLED 1U
#define pass_0_sar_0_group_0_scan_2_ENABLED 1U
#define pass_0_sar_0_group_0_scan_3_ENABLED 1U
#define eth_0_ENABLED 1U
#define ETH_PHY_LAN8710AI 
#define eth_0_PHY_ADDR 0
#define eth_0_PHY_INTERFACE 1u
#define eth_0_PHY_SPEED 3
#define eth_0_PHY_MODE 2
#define eth_0_MAC_ADDR0 0x00U
#define eth_0_MAC_ADDR1 0x03U
#define eth_0_MAC_ADDR2 0x19U
#define eth_0_MAC_ADDR3 0x45U
#define eth_0_MAC_ADDR4 0x00U
#define eth_0_MAC_ADDR5 0x00U
#define eth_0_MAC_ADDR (((uint64_t)eth_0_MAC_ADDR0<<0) | ((uint64_t)eth_0_MAC_ADDR1<<8) | ((uint64_t)eth_0_MAC_ADDR2<<16) | ((uint64_t)eth_0_MAC_ADDR3<<24) | ((uint64_t)eth_0_MAC_ADDR4<<32) | ((uint64_t)eth_0_MAC_ADDR5<<40))
#define eth_0_STATIC_IP 0
#define eth_0_MAC_CLOCK 0u
#define eth_0_PROMISCUOUS_MODE false
#define eth_0_ACCEPT_BROADCAST_FRAMES true
#define eth_0_ETHERNET_INDEX 0
#define eth_0_INTRSRC_Q0 (eth_interrupt_eth_0_IRQn)
#define eth_0_INTRSRC_Q1 (eth_interrupt_eth_1_IRQn)
#define eth_0_INTRSRC_Q2 (eth_interrupt_eth_2_IRQn)
#define eth_0_INTRPRIORITY 3UL
#define CYCFG_TCPIP_THREAD_PRIO 4
#define CYCFG_TCPIP_THREAD_STACKSIZE 4096
#define CYCFG_IP_OPTIONS_ALLOWED 1
#define CYCFG_LWIP_IPV6 1
#define CYCFG_IP_FRAG 0
#define CYCFG_IP_REASSEMBLY 0
#define CYCFG_IP_DEFAULT_TTL 255
#define CYCFG_ARP_TABLE_SIZE 10
#define CYCFG_LWIP_AUTOIP 0
#define CYCFG_LWIP_ICMP 1
#define CYCFG_LWIP_IGMP 1
#define CYCFG_LWIP_TCP 1
#define CYCFG_TCP_MSS 1460
#define CYCFG_TCP_WND 5840
#define CYCFG_TCP_SND_BUF 5840
#define CYCFG_TCP_SND_QUEUELEN 25
#define CYCFG_LWIP_UDP 1
#define CYCFG_MEM_SIZE 1600
#define CYCFG_PBUF_POOL_SIZE 50
#define CYCFG_MEMP_NUM_PBUF 16
#define CYCFG_MEMP_NUM_RAW_PCB 4
#define CYCFG_MEMP_NUM_UDP_PCB 8
#define CYCFG_MEMP_NUM_TCP_PCB 8
#define CYCFG_MEMP_NUM_TCP_PCB_LISTEN 1
#define CYCFG_MEMP_NUM_TCP_SEG 27
#define CYCFG_MEMP_NUM_ARP_QUEUE 30
#define CYCFG_MEMP_NUM_NETBUF 8
#define CYCFG_MEMP_NUM_NETCONN 16
#define CYCFG_MEMP_NUM_TCPIP_MSG_API 8
#define CYCFG_MEMP_NUM_TCPIP_MSG_INPKT 8
#define CYBSP_I3C_CONTROLLER_ENABLED 1U
#define CYBSP_I3C_CONTROLLER_HW I3C_CORE
#define CYBSP_I3C_CONTROLLER_IRQ i3c_interrupt_IRQn
#define CYBSP_I2C_CONTROLLER_ENABLED 1U
#define CYBSP_I2C_CONTROLLER_HW SCB0
#define CYBSP_I2C_CONTROLLER_IRQ scb_0_interrupt_IRQn
#define CYBSP_UART2_ENABLED 1U
#define CYBSP_UART2_HW SCB2
#define CYBSP_UART2_IRQ scb_2_interrupt_IRQn
#define CYBSP_SPI3_ENABLED 1U
#define CYBSP_SPI3_HW SCB3
#define CYBSP_SPI3_IRQ scb_3_interrupt_IRQn
#define CYBSP_DEBUG_UART_ENABLED 1U
#define CYBSP_DEBUG_UART_HW SCB4
#define CYBSP_DEBUG_UART_IRQ scb_4_interrupt_IRQn
#define CYBSP_UART5_ENABLED 1U
#define CYBSP_UART5_HW SCB5
#define CYBSP_UART5_IRQ scb_5_interrupt_IRQn
#define scb_8_ENABLED 1U
#define scb_8_HW SCB8
#define scb_8_IRQ scb_8_interrupt_IRQn
#define CYBSP_SDHC_1_ENABLED 1U
#define CYBSP_SDHC_1_HW SDHC1
#define CYBSP_SDHC_1_IRQ sdhc_1_interrupt_general_IRQn
#define CYBSP_USB_DEVICE_0_ENABLED 1U
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_ENABLED 1U
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_HW SMIF0_CORE
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_IRQ smif_0_smif0_interrupt_nsec_IRQn
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_MEMORY_MODE_ALIGMENT_ERROR (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_RX_DATA_FIFO_UNDERFLOW (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_TX_COMMAND_FIFO_OVERFLOW (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_TX_DATA_FIFO_OVERFLOW (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_RX_DMA_TRIGGER_OUT_USED (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_TX_DMA_TRIGGER_OUT_USED (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_RX_FIFO_TRIGGER_LEVEL (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_TX_FIFO_TRIGGER_LEVEL (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_DATALINES0_1 (1UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_DATALINES2_3 (1UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_DATALINES4_5 (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_DATALINES6_7 (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_SS0 (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_SS1 (1UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_SS2 (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_SS3 (0UL)
#define CYBSP_SMIF_CORE_0_XSPI_FLASH_DESELECT_DELAY 7
#define CYBSP_SMIF_CORE_1_PSRAM_ENABLED 1U
#define CYBSP_SMIF_CORE_1_PSRAM_HW SMIF1_CORE
#define CYBSP_SMIF_CORE_1_PSRAM_IRQ smif_1_smif0_interrupt_nsec_IRQn
#define CYBSP_SMIF_CORE_1_PSRAM_MEMORY_MODE_ALIGMENT_ERROR (0UL)
#define CYBSP_SMIF_CORE_1_PSRAM_RX_DATA_FIFO_UNDERFLOW (0UL)
#define CYBSP_SMIF_CORE_1_PSRAM_TX_COMMAND_FIFO_OVERFLOW (0UL)
#define CYBSP_SMIF_CORE_1_PSRAM_TX_DATA_FIFO_OVERFLOW (0UL)
#define CYBSP_SMIF_CORE_1_PSRAM_RX_DMA_TRIGGER_OUT_USED (0UL)
#define CYBSP_SMIF_CORE_1_PSRAM_TX_DMA_TRIGGER_OUT_USED (0UL)
#define CYBSP_SMIF_CORE_1_PSRAM_RX_FIFO_TRIGGER_LEVEL (0UL)
#define CYBSP_SMIF_CORE_1_PSRAM_TX_FIFO_TRIGGER_LEVEL (0UL)
#define CYBSP_SMIF_CORE_1_PSRAM_DATALINES0_1 (1UL)
#define CYBSP_SMIF_CORE_1_PSRAM_DATALINES2_3 (1UL)
#define CYBSP_SMIF_CORE_1_PSRAM_DATALINES4_5 (1UL)
#define CYBSP_SMIF_CORE_1_PSRAM_DATALINES6_7 (1UL)
#define CYBSP_SMIF_CORE_1_PSRAM_SS0 (0UL)
#define CYBSP_SMIF_CORE_1_PSRAM_SS1 (0UL)
#define CYBSP_SMIF_CORE_1_PSRAM_SS2 (1UL)
#define CYBSP_SMIF_CORE_1_PSRAM_SS3 (0UL)
#define CYBSP_SMIF_CORE_1_PSRAM_DESELECT_DELAY 7
#define CYBSP_CM33_LPTIMER_0_ENABLED 1U
#define CYBSP_CM33_LPTIMER_0_HW MCWDT_STRUCT0
#define CYBSP_CM33_LPTIMER_0_IRQ srss_interrupt_mcwdt_0_IRQn
#define CYBSP_CM55_LPTIMER_1_ENABLED 1U
#define CYBSP_CM55_LPTIMER_1_HW MCWDT_STRUCT1
#define CYBSP_CM55_LPTIMER_1_IRQ srss_interrupt_mcwdt_1_IRQn
#define CYBSP_GENERAL_PURPOSE_TIMER_ENABLED 1U
#define CYBSP_GENERAL_PURPOSE_TIMER_HW TCPWM0
#define CYBSP_GENERAL_PURPOSE_TIMER_NUM 0UL
#define CYBSP_USB_OS_TIMER_COUNTER_ENABLED 1U
#define CYBSP_USB_OS_TIMER_COUNTER_HW TCPWM0
#define CYBSP_USB_OS_TIMER_COUNTER_NUM 1UL
#define tcpwm_0_group_0_cnt_2_ENABLED 1U
#define tcpwm_0_group_0_cnt_2_HW TCPWM0
#define tcpwm_0_group_0_cnt_2_NUM 2UL
#define tcpwm_0_group_0_cnt_3_ENABLED 1U
#define tcpwm_0_group_0_cnt_3_HW TCPWM0
#define tcpwm_0_group_0_cnt_3_NUM 3UL
#define tcpwm_0_group_0_cnt_4_ENABLED 1U
#define tcpwm_0_group_0_cnt_4_HW TCPWM0
#define tcpwm_0_group_0_cnt_4_NUM 4UL
#define tcpwm_0_group_0_cnt_5_ENABLED 1U
#define tcpwm_0_group_0_cnt_5_HW TCPWM0
#define tcpwm_0_group_0_cnt_5_NUM 5UL
#define tcpwm_0_group_1_cnt_0_ENABLED 1U
#define emUSB_OS_Timer_HW TCPWM0
#define emUSB_OS_Timer_NUM 256UL
#define emUSB_OS_Timer_IRQ tcpwm_0_interrupts_256_IRQn
#define tcpwm_0_group_1_cnt_2_ENABLED 1U
#define tcpwm_0_group_1_cnt_2_HW TCPWM0
#define tcpwm_0_group_1_cnt_2_NUM 258UL
#define tcpwm_0_group_1_cnt_3_ENABLED 1U
#define tcpwm_0_group_1_cnt_3_HW TCPWM0
#define tcpwm_0_group_1_cnt_3_NUM 259UL
#define tcpwm_0_group_1_cnt_4_ENABLED 1U
#define tcpwm_0_group_1_cnt_4_HW TCPWM0
#define tcpwm_0_group_1_cnt_4_NUM 260UL
#define tcpwm_0_group_1_cnt_5_ENABLED 1U
#define tcpwm_0_group_1_cnt_5_HW TCPWM0
#define tcpwm_0_group_1_cnt_5_NUM 261UL
#define tcpwm_0_group_1_cnt_8_ENABLED 1U
#define tcpwm_0_group_1_cnt_8_HW TCPWM0
#define tcpwm_0_group_1_cnt_8_NUM 264UL
#define tcpwm_0_group_1_cnt_9_ENABLED 1U
#define tcpwm_0_group_1_cnt_9_HW TCPWM0
#define tcpwm_0_group_1_cnt_9_NUM 265UL
#define tcpwm_0_group_1_cnt_10_ENABLED 1U
#define tcpwm_0_group_1_cnt_10_HW TCPWM0
#define tcpwm_0_group_1_cnt_10_NUM 266UL
#define tcpwm_0_group_1_cnt_11_ENABLED 1U
#define tcpwm_0_group_1_cnt_11_HW TCPWM0
#define tcpwm_0_group_1_cnt_11_NUM 267UL
#define tcpwm_0_group_1_cnt_13_ENABLED 1U
#define tcpwm_0_group_1_cnt_13_HW TCPWM0
#define tcpwm_0_group_1_cnt_13_NUM 269UL
#define tcpwm_0_group_1_cnt_15_ENABLED 1U
#define tcpwm_0_group_1_cnt_15_HW TCPWM0
#define tcpwm_0_group_1_cnt_15_NUM 271UL
#define tcpwm_0_group_1_cnt_17_ENABLED 1U
#define tcpwm_0_group_1_cnt_17_HW TCPWM0
#define tcpwm_0_group_1_cnt_17_NUM 273UL
#define tcpwm_0_group_1_cnt_19_ENABLED 1U
#define tcpwm_0_group_1_cnt_19_HW TCPWM0
#define tcpwm_0_group_1_cnt_19_NUM 275UL
#define RC_TIMER_ENABLED 1U
#define RC_TIMER_HW TCPWM0
#define RC_TIMER_NUM 276UL
#define RC_TIMER_IRQ tcpwm_0_interrupts_276_IRQn
#define tcpwm_0_group_1_cnt_22_ENABLED 1U
#define tcpwm_0_group_1_cnt_22_HW TCPWM0
#define tcpwm_0_group_1_cnt_22_NUM 278UL
#define tcpwm_0_group_1_cnt_23_ENABLED 1U
#define tcpwm_0_group_1_cnt_23_HW TCPWM0
#define tcpwm_0_group_1_cnt_23_NUM 279UL

extern cy_stc_autanalog_cfg_t autonomous_analog_cfg;
extern cy_stc_autanalog_stt_t autonomous_analog_stt[];
extern cy_stc_autanalog_t autonomous_analog_init;
extern cy_en_autanalog_ac_out_trigger_mask_t CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[];
extern cy_stc_autanalog_ac_t CYBSP_AUTONOMOUS_CONTROLLER_cfg;
extern cy_stc_autanalog_stt_ac_t CYBSP_AUTONOMOUS_CONTROLLER_stt[];
extern cy_stc_autanalog_sar_hs_chan_t CYBSP_SAR_ADC_gpio_ch_cfg[];
extern cy_stc_autanalog_sar_sta_hs_t CYBSP_SAR_ADC_sta_hs_cfg;
extern cy_stc_autanalog_sar_sta_t CYBSP_SAR_ADC_sta_cfg;
extern cy_stc_autanalog_sar_seq_tab_hs_t CYBSP_SAR_ADC_seq_hs_cfg[];
extern cy_stc_autanalog_sar_t CYBSP_SAR_ADC_cfg;
extern cy_stc_autanalog_stt_sar_t CYBSP_SAR_ADC_stt[];

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_ADC)
extern mtb_hal_adc_configurator_t CYBSP_SAR_ADC_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_ADC) */

extern const cy_stc_i3c_config_t CYBSP_I3C_CONTROLLER_config;
extern const cy_stc_scb_i2c_config_t CYBSP_I2C_CONTROLLER_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t CYBSP_I2C_CONTROLLER_clock_ref;
extern const mtb_hal_clock_t CYBSP_I2C_CONTROLLER_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_I2C)
extern const mtb_hal_i2c_configurator_t CYBSP_I2C_CONTROLLER_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_I2C) */

extern const cy_stc_scb_uart_config_t CYBSP_UART2_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t CYBSP_UART2_clock_ref;
extern const mtb_hal_clock_t CYBSP_UART2_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART)
extern const mtb_hal_uart_configurator_t CYBSP_UART2_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART) */

extern const cy_stc_scb_spi_config_t CYBSP_SPI3_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t CYBSP_SPI3_clock_ref;
extern const mtb_hal_clock_t CYBSP_SPI3_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
extern const mtb_hal_spi_configurator_t CYBSP_SPI3_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

extern const cy_stc_scb_uart_config_t CYBSP_DEBUG_UART_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t CYBSP_DEBUG_UART_clock_ref;
extern const mtb_hal_clock_t CYBSP_DEBUG_UART_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART)
extern const mtb_hal_uart_configurator_t CYBSP_DEBUG_UART_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART) */

extern const cy_stc_scb_uart_config_t CYBSP_UART5_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t CYBSP_UART5_clock_ref;
extern const mtb_hal_clock_t CYBSP_UART5_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART)
extern const mtb_hal_uart_configurator_t CYBSP_UART5_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_UART) */

extern const cy_stc_scb_spi_config_t scb_8_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t scb_8_clock_ref;
extern const mtb_hal_clock_t scb_8_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI)
extern const mtb_hal_spi_configurator_t scb_8_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SPI) */

extern cy_en_sd_host_card_capacity_t CYBSP_SDHC_1_cardCapacity;
extern cy_en_sd_host_card_type_t CYBSP_SDHC_1_cardType;
extern uint32_t CYBSP_SDHC_1_rca;
extern const cy_stc_sd_host_init_config_t CYBSP_SDHC_1_config;
extern cy_stc_sd_host_sd_card_config_t CYBSP_SDHC_1_card_cfg;

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SDHC)
extern const mtb_hal_peri_div_t CYBSP_SDHC_1_clock_ref;
extern const mtb_hal_clock_t CYBSP_SDHC_1_hal_clock;
extern const mtb_hal_sdhc_configurator_t CYBSP_SDHC_1_sdhc_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SDHC) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SDIO)
extern const mtb_hal_sdio_configurator_t CYBSP_SDHC_1_sdio_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_SDIO) */

extern const cy_stc_smif_config_t CYBSP_SMIF_CORE_0_XSPI_FLASH_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_hf_clock_t CYBSP_SMIF_CORE_0_XSPI_FLASH_clock_ref;
extern const mtb_hal_clock_t CYBSP_SMIF_CORE_0_XSPI_FLASH_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_MEMORYSPI)
extern const mtb_hal_memoryspi_configurator_t CYBSP_SMIF_CORE_0_XSPI_FLASH_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_MEMORYSPI) */

extern const cy_stc_smif_config_t CYBSP_SMIF_CORE_1_PSRAM_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_hf_clock_t CYBSP_SMIF_CORE_1_PSRAM_clock_ref;
extern const mtb_hal_clock_t CYBSP_SMIF_CORE_1_PSRAM_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_MEMORYSPI)
extern const mtb_hal_memoryspi_configurator_t CYBSP_SMIF_CORE_1_PSRAM_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_MEMORYSPI) */

extern const cy_stc_mcwdt_config_t CYBSP_CM33_LPTIMER_0_config;

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_LPTIMER)
extern const mtb_hal_lptimer_configurator_t CYBSP_CM33_LPTIMER_0_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_LPTIMER) */

extern const cy_stc_mcwdt_config_t CYBSP_CM55_LPTIMER_1_config;

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_LPTIMER)
extern const mtb_hal_lptimer_configurator_t CYBSP_CM55_LPTIMER_1_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_LPTIMER) */

extern const cy_stc_tcpwm_pwm_config_t CYBSP_GENERAL_PURPOSE_TIMER_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t CYBSP_GENERAL_PURPOSE_TIMER_clock_ref;
extern const mtb_hal_clock_t CYBSP_GENERAL_PURPOSE_TIMER_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t CYBSP_GENERAL_PURPOSE_TIMER_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t CYBSP_USB_OS_TIMER_COUNTER_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t CYBSP_USB_OS_TIMER_COUNTER_clock_ref;
extern const mtb_hal_clock_t CYBSP_USB_OS_TIMER_COUNTER_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t CYBSP_USB_OS_TIMER_COUNTER_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_0_cnt_2_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_0_cnt_2_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_0_cnt_2_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_0_cnt_2_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_0_cnt_3_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_0_cnt_3_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_0_cnt_3_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_0_cnt_3_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_0_cnt_4_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_0_cnt_4_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_0_cnt_4_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_0_cnt_4_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_0_cnt_5_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_0_cnt_5_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_0_cnt_5_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_0_cnt_5_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern cy_stc_tcpwm_counter_config_t emUSB_OS_Timer_config;

#if defined (COMPONENT_MTB_HAL)
extern mtb_hal_peri_div_t emUSB_OS_Timer_clock_ref;
extern mtb_hal_clock_t emUSB_OS_Timer_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
extern mtb_hal_timer_configurator_t emUSB_OS_Timer_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_2_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_2_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_2_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_2_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_3_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_3_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_3_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_3_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_4_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_4_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_4_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_4_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_5_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_5_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_5_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_5_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_8_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_8_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_8_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_8_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_9_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_9_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_9_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_9_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_10_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_10_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_10_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_10_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_11_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_11_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_11_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_11_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_13_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_13_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_13_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_13_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_15_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_15_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_15_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_15_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_17_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_17_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_17_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_17_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_19_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_19_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_19_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_19_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_counter_config_t RC_TIMER_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t RC_TIMER_clock_ref;
extern const mtb_hal_clock_t RC_TIMER_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER)
extern const mtb_hal_timer_configurator_t RC_TIMER_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_TIMER) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_22_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_22_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_22_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_22_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

extern const cy_stc_tcpwm_pwm_config_t tcpwm_0_group_1_cnt_23_config;

#if defined (COMPONENT_MTB_HAL)
extern const mtb_hal_peri_div_t tcpwm_0_group_1_cnt_23_clock_ref;
extern const mtb_hal_clock_t tcpwm_0_group_1_cnt_23_hal_clock;
#endif /* defined (COMPONENT_MTB_HAL) */

#if defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM)
extern const mtb_hal_pwm_configurator_t tcpwm_0_group_1_cnt_23_hal_config;
#endif /* defined (COMPONENT_MTB_HAL) && (MTB_HAL_DRIVER_AVAILABLE_PWM) */

void init_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PERIPHERALS_H */
