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

#define uart_isr_callback(name) name##_isr_callback

struct ifx_uart_config {
    mtb_hal_uart_t* uart_obj;
    const char* name;
    const cy_stc_scb_uart_config_t* uart_config;
    const mtb_hal_uart_configurator_t* hal_uart_configurator;
    uint32_t* actualbaud;
    CySCB_Type* usart_x;
    cy_stc_scb_uart_context_t* uart_context;
#if defined(SOC_SERIES_IFX_XMC)
    rt_uint32_t intrSrc;
#else
    IRQn_Type intrSrc;
#endif
    cy_israddress userIsr;
    cy_stc_sysint_t* UART_SCB_IRQ_cfg;
};

struct ifx_uart {
    struct ifx_uart_config* config;
    struct serial_device serial;
};

rt_err_t drv_usart_init(void);

#endif
