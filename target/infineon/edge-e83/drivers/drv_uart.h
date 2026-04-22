/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef __DRV_UART_H__
#define __DRV_UART_H__

#include <rtdevice.h>
#include <rthw.h>

#include "board.h"
#include "hal/serial/serial.h"
#include "mtb_hal_uart.h"

#define UART_TX_BUFFER_SIZE 256

struct ifx_uart_config {
    mtb_hal_uart_t* uart_obj;
    const char* name;
    const cy_stc_scb_uart_config_t* uart_config;
    const mtb_hal_uart_configurator_t* hal_uart_configurator;
    uint32_t* actualbaud;
    CySCB_Type* usart_x;
    cy_stc_scb_uart_context_t* uart_context;
    IRQn_Type intrSrc;
    cy_israddress userIsr;
    cy_stc_sysint_t* UART_SCB_IRQ_cfg;

#if defined(BSP_USING_UART1_DMA_TX) || defined(BSP_USING_UART2_DMA_TX) || defined(BSP_USING_UART4_DMA_TX) || defined(BSP_USING_UART5_DMA_TX)
    uint8_t* tx_buffer;
    cy_stc_dma_descriptor_t* tx_dma_descriptor;
    volatile uint8_t tx_dma_done;
    uint8_t dma_enabled;
    uint8_t dma_initialized;
    rt_sem_t tx_dma_sem;

    const cy_stc_dma_descriptor_config_t* tx_dma_descriptor_config;
    const cy_stc_dma_channel_config_t* tx_dma_channel_config;
    cy_stc_sysint_t* tx_dma_int_cfg;
    cy_israddress tx_dma_isr;
    IRQn_Type tx_dma_irq;
    uint8_t tx_dma_channel;
    DW_Type* tx_dma_hw;
#endif
};

struct ifx_uart {
    struct ifx_uart_config* config;
    struct serial_device serial;
};

rt_err_t drv_usart_init(void);

#endif /* __DRV_UART_H__ */