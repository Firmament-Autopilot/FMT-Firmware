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

#include "drv_uart.h"
#include <rtthread.h>

#include "cy_scb_uart.h"
#include "cycfg_dmas.h"
#include "uart_config.h"

#if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
#define UART_DCACHE_CLEAN(addr, size) \
SCB_CleanDCache_by_Addr((void*)(addr), (int32_t)(size))
#define UART_DCACHE_INVALIDATE(addr, size) \
SCB_InvalidateDCache_by_Addr((void*)(addr), (int32_t)(size))
#else
#define UART_DCACHE_CLEAN(addr, size)      ((void)0)
#define UART_DCACHE_INVALIDATE(addr, size) ((void)0)
#endif

#if defined(BSP_USING_UART1_DMA_TX) || defined(BSP_USING_UART2_DMA_TX) || defined(BSP_USING_UART4_DMA_TX) || defined(BSP_USING_UART5_DMA_TX)

#ifdef BSP_USING_UART1_DMA_TX
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static uint8_t uart1_tx_buf[UART_TX_BUFFER_SIZE];
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static cy_stc_dma_descriptor_t uart1_tx_desc;
#endif

#ifdef BSP_USING_UART2_DMA_TX
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static uint8_t uart2_tx_buf[UART_TX_BUFFER_SIZE];
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static cy_stc_dma_descriptor_t uart2_tx_desc;
#endif

#ifdef BSP_USING_UART4_DMA_TX
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static uint8_t uart4_tx_buf[UART_TX_BUFFER_SIZE];
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static cy_stc_dma_descriptor_t uart4_tx_desc;
#endif

#ifdef BSP_USING_UART5_DMA_TX
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static uint8_t uart5_tx_buf[UART_TX_BUFFER_SIZE];
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static cy_stc_dma_descriptor_t uart5_tx_desc;
#endif

#endif /* BSP_USING_UARTx_DMA_TX */

enum {
#ifdef BSP_USING_UART1
    UART1_INDEX,
#endif
#if defined(BSP_USING_UART2) || defined(BSP_USING_UART2_DMA_TX)
    UART2_INDEX,
#endif
#ifdef BSP_USING_UART4
    UART4_INDEX,
#endif
#ifdef BSP_USING_UART5
    UART5_INDEX,
#endif
};

static struct ifx_uart_config uart_config[] = {
#ifdef BSP_USING_UART1
    UART1_CONFIG,
#endif
#if defined(BSP_USING_UART2) || defined(BSP_USING_UART2_DMA_TX)
    UART2_CONFIG,
#endif
#ifdef BSP_USING_UART4
    UART4_CONFIG,
#endif
#ifdef BSP_USING_UART5
    UART5_CONFIG,
#endif
};

static struct ifx_uart uart_obj[sizeof(uart_config) / sizeof(uart_config[0])] = { 0 };

#if defined(BSP_USING_UART1_DMA_TX) || defined(BSP_USING_UART2_DMA_TX) || defined(BSP_USING_UART4_DMA_TX) || defined(BSP_USING_UART5_DMA_TX)

static void init_uart_tx_dma(struct ifx_uart* uart)
{
    struct ifx_uart_config* config = uart->config;
    volatile cy_en_dma_status_t st;

    RT_ASSERT(config->tx_buffer != RT_NULL);
    RT_ASSERT(config->tx_dma_descriptor != RT_NULL);

    st = Cy_DMA_Descriptor_Init(config->tx_dma_descriptor,
                                config->tx_dma_descriptor_config);
    RT_ASSERT(st == CY_DMA_SUCCESS);

    st = Cy_DMA_Channel_Init(config->tx_dma_hw,
                             config->tx_dma_channel,
                             config->tx_dma_channel_config);
    RT_ASSERT(st == CY_DMA_SUCCESS);

    Cy_DMA_Descriptor_SetDescriptorType(config->tx_dma_descriptor,
                                        CY_DMA_1D_TRANSFER);
    Cy_DMA_Descriptor_SetInterruptType(config->tx_dma_descriptor,
                                       CY_DMA_DESCR);
    Cy_DMA_Descriptor_SetChannelState(config->tx_dma_descriptor,
                                      CY_DMA_CHANNEL_DISABLED);
    Cy_DMA_Descriptor_SetNextDescriptor(config->tx_dma_descriptor, NULL);

    Cy_DMA_Descriptor_SetDataSize(config->tx_dma_descriptor,
                                  CY_DMA_BYTE);
    Cy_DMA_Descriptor_SetSrcTransferSize(config->tx_dma_descriptor,
                                         CY_DMA_TRANSFER_SIZE_DATA);
    Cy_DMA_Descriptor_SetDstTransferSize(config->tx_dma_descriptor,
                                         CY_DMA_TRANSFER_SIZE_WORD);

    Cy_DMA_Descriptor_SetTriggerInType(config->tx_dma_descriptor,
                                       CY_DMA_1ELEMENT);
    Cy_DMA_Descriptor_SetTriggerOutType(config->tx_dma_descriptor,
                                        CY_DMA_DESCR);
    Cy_DMA_Descriptor_SetXloopSrcIncrement(config->tx_dma_descriptor, 1);
    Cy_DMA_Descriptor_SetXloopDstIncrement(config->tx_dma_descriptor, 0);

    Cy_DMA_Descriptor_SetDstAddress(config->tx_dma_descriptor,
                                    (void*)&config->usart_x->TX_FIFO_WR);

    Cy_SysInt_Init(config->tx_dma_int_cfg, config->tx_dma_isr);
    NVIC_EnableIRQ(config->tx_dma_irq);
    Cy_DMA_Channel_SetInterruptMask(config->tx_dma_hw,
                                    config->tx_dma_channel,
                                    CY_DMA_INTR_MASK);
    Cy_DMA_Channel_ClearInterrupt(config->tx_dma_hw,
                                  config->tx_dma_channel);

    Cy_DMA_Enable(config->tx_dma_hw);
}

static void uart_dma_tx_send_chunk(struct ifx_uart_config* config,
                                   const uint8_t* src, rt_size_t len)
{
    rt_sem_take(config->tx_dma_sem, RT_WAITING_FOREVER);

    rt_memcpy(config->tx_buffer, src, len);

    UART_DCACHE_CLEAN(config->tx_buffer, (int32_t)UART_TX_BUFFER_SIZE);

    Cy_DMA_Descriptor_SetSrcAddress(config->tx_dma_descriptor,
                                    config->tx_buffer);
    Cy_DMA_Descriptor_SetXloopDataCount(config->tx_dma_descriptor,
                                        (uint32_t)len);

    UART_DCACHE_CLEAN(config->tx_dma_descriptor,
                      sizeof(cy_stc_dma_descriptor_t));

    config->tx_dma_done = 0u;

    Cy_DMA_Channel_ClearInterrupt(config->tx_dma_hw,
                                  config->tx_dma_channel);

    Cy_DMA_Channel_SetDescriptor(config->tx_dma_hw,
                                 config->tx_dma_channel,
                                 config->tx_dma_descriptor);

    Cy_DMA_Channel_Enable(config->tx_dma_hw, config->tx_dma_channel);
}

static void uart_dma_tx_isr(struct ifx_uart* uart)
{
    rt_interrupt_enter();

    struct ifx_uart_config* config = uart->config;
    cy_en_dma_intr_cause_t status = Cy_DMA_Channel_GetStatus(config->tx_dma_hw, config->tx_dma_channel);

    if ((status == CY_DMA_INTR_CAUSE_COMPLETION) || (status == CY_DMA_INTR_CAUSE_CURR_PTR_NULL)) {
        config->tx_dma_done = 1u;
        rt_sem_release(config->tx_dma_sem);
        hal_serial_isr(&uart->serial, SERIAL_EVENT_TX_DMADONE);
    } else {
        rt_kprintf("[UART DMA] %s error, status=%d\n",
                   config->name,
                   (int)status);
        config->tx_dma_done = 1u;
        rt_sem_release(config->tx_dma_sem);
        hal_serial_isr(&uart->serial, SERIAL_EVENT_TX_DMADONE);
    }

    Cy_DMA_Channel_ClearInterrupt(config->tx_dma_hw, config->tx_dma_channel);

    rt_interrupt_leave();
}

#endif /* BSP_USING_UARTx_DMA_TX */

static void uart_isr(struct serial_device* serial)
{
    RT_ASSERT(serial != RT_NULL);
    struct ifx_uart* uart = (struct ifx_uart*)serial->parent.user_data;
    RT_ASSERT(uart != RT_NULL);

    if ((uart->config->usart_x->INTR_RX_MASKED
         & SCB_INTR_RX_MASKED_NOT_EMPTY_Msk)
        != 0) {
        uart->config->usart_x->INTR_RX = uart->config->usart_x->INTR_RX & SCB_INTR_RX_NOT_EMPTY_Msk;
        hal_serial_isr(serial, SERIAL_EVENT_RX_IND);
    }
}

#ifdef BSP_USING_UART1
void uart1_isr_callback(void)
{
    rt_interrupt_enter();
    uart_isr(&uart_obj[UART1_INDEX].serial);
    rt_interrupt_leave();
}
#endif

#if defined(BSP_USING_UART2) || defined(BSP_USING_UART2_DMA_TX)
void uart2_isr_callback(void)
{
    rt_interrupt_enter();
    uart_isr(&uart_obj[UART2_INDEX].serial);
    rt_interrupt_leave();
}
#endif

#ifdef BSP_USING_UART4
void uart4_isr_callback(void)
{
    rt_interrupt_enter();
    uart_isr(&uart_obj[UART4_INDEX].serial);
    rt_interrupt_leave();
}
#endif

#ifdef BSP_USING_UART5
void uart5_isr_callback(void)
{
    rt_interrupt_enter();
    uart_isr(&uart_obj[UART5_INDEX].serial);
    rt_interrupt_leave();
}
#endif

#ifdef BSP_USING_UART1_DMA_TX
void uart1_dma_tx_isr_callback(void) { uart_dma_tx_isr(&uart_obj[UART1_INDEX]); }
#endif
#ifdef BSP_USING_UART2_DMA_TX
void uart2_dma_tx_isr_callback(void) { uart_dma_tx_isr(&uart_obj[UART2_INDEX]); }
#endif
#ifdef BSP_USING_UART4_DMA_TX
void uart4_dma_tx_isr_callback(void) { uart_dma_tx_isr(&uart_obj[UART4_INDEX]); }
#endif
#ifdef BSP_USING_UART5_DMA_TX
void uart5_dma_tx_isr_callback(void) { uart_dma_tx_isr(&uart_obj[UART5_INDEX]); }
#endif

static rt_err_t ifx_configure(struct serial_device* serial,
                              struct serial_configure* cfg)
{
    RT_ASSERT(serial != RT_NULL);
    struct ifx_uart* uart = (struct ifx_uart*)serial->parent.user_data;
    RT_ASSERT(uart != RT_NULL);

    cy_rslt_t result;
    result = Cy_SCB_UART_Init(uart->config->usart_x,
                              uart->config->uart_config,
                              uart->config->uart_context);
    Cy_SCB_UART_Enable(uart->config->usart_x);

    result = mtb_hal_uart_setup(uart->config->uart_obj,
                                uart->config->hal_uart_configurator,
                                uart->config->uart_context,
                                NULL);
    if (result == CY_RSLT_SUCCESS) {
        result = mtb_hal_uart_set_baud(uart->config->uart_obj,
                                       cfg->baud_rate,
                                       uart->config->actualbaud);
    }
    RT_ASSERT(result == RT_EOK);

#if defined(BSP_USING_UART1_DMA_TX) || defined(BSP_USING_UART2_DMA_TX) || defined(BSP_USING_UART4_DMA_TX) || defined(BSP_USING_UART5_DMA_TX)
    if (uart->config->dma_enabled && !uart->config->dma_initialized) {
        RT_ASSERT(uart->config->tx_buffer != RT_NULL);
        RT_ASSERT(uart->config->tx_dma_descriptor != RT_NULL);

        uart->config->tx_dma_done = 1u;
        init_uart_tx_dma(uart);
        uart->config->dma_initialized = 1u;
    }
#endif

    return RT_EOK;
}

static rt_err_t ifx_control(struct serial_device* serial, int cmd, void* arg)
{
    RT_ASSERT(serial != RT_NULL);
    struct ifx_uart* uart = (struct ifx_uart*)serial->parent.user_data;
    RT_ASSERT(uart != RT_NULL);

    switch (cmd) {
    case RT_DEVICE_CTRL_CLR_INT:
        uart->config->usart_x->INTR_RX_MASK &= ~SCB_INTR_RX_MASK_NOT_EMPTY_Msk;
#if defined(BSP_USING_UART1_DMA_TX) || defined(BSP_USING_UART2_DMA_TX) || defined(BSP_USING_UART4_DMA_TX) || defined(BSP_USING_UART5_DMA_TX)
        if (uart->config->dma_enabled) {
            Cy_DMA_Channel_Disable(uart->config->tx_dma_hw,
                                   uart->config->tx_dma_channel);
        } else
#endif
        {
            NVIC_DisableIRQ(uart->config->intrSrc);
        }
        break;

    case RT_DEVICE_CTRL_SET_INT:
        uart->config->usart_x->INTR_RX_MASK = SCB_INTR_RX_MASK_NOT_EMPTY_Msk;
        Cy_SysInt_Init(uart->config->UART_SCB_IRQ_cfg, uart->config->userIsr);
        NVIC_EnableIRQ(uart->config->intrSrc);
        break;

    case RT_DEVICE_CTRL_SUSPEND:
        if (serial->parent.open_flag & RT_DEVICE_FLAG_INT_RX) {
            uart->config->usart_x->INTR_RX_MASK &= ~SCB_INTR_RX_MASK_NOT_EMPTY_Msk;
            NVIC_DisableIRQ(uart->config->intrSrc);
        }
#if defined(BSP_USING_UART1_DMA_TX) || defined(BSP_USING_UART2_DMA_TX) || defined(BSP_USING_UART4_DMA_TX) || defined(BSP_USING_UART5_DMA_TX)
        if ((serial->parent.open_flag & RT_DEVICE_FLAG_DMA_TX) && uart->config->dma_enabled) {
            Cy_DMA_Channel_Disable(uart->config->tx_dma_hw,
                                   uart->config->tx_dma_channel);
        }
#endif
        break;

    case RT_DEVICE_CTRL_RESUME:
        if (serial->parent.open_flag & RT_DEVICE_FLAG_INT_RX) {
            uart->config->usart_x->INTR_RX_MASK = SCB_INTR_RX_MASK_NOT_EMPTY_Msk;
            NVIC_EnableIRQ(uart->config->intrSrc);
        }
#if defined(BSP_USING_UART1_DMA_TX) || defined(BSP_USING_UART2_DMA_TX) || defined(BSP_USING_UART4_DMA_TX) || defined(BSP_USING_UART5_DMA_TX)
#endif
        break;
    }

    return RT_EOK;
}

static int ifx_putc(struct serial_device* serial, char c)
{
    RT_ASSERT(serial != RT_NULL);
    struct ifx_uart* uart = (struct ifx_uart*)serial->parent.user_data;
    RT_ASSERT(uart != RT_NULL);

    uint32_t count = 0;
    while (count == 0) {
        count = Cy_SCB_UART_Put(uart->config->usart_x, c);
    }
    return 1;
}

static int ifx_getc(struct serial_device* serial)
{
    RT_ASSERT(serial != RT_NULL);
    struct ifx_uart* uart = (struct ifx_uart*)serial->parent.user_data;
    RT_ASSERT(uart != RT_NULL);

    uint8_t read_data;
    if (RT_EOK == mtb_hal_uart_get(uart->config->uart_obj, &read_data, 10)) {
        return (int)(read_data & 0xff);
    }
    return -1;
}

static rt_size_t ifx_dma_transmit(struct serial_device* serial,
                                  rt_uint8_t* buf,
                                  rt_size_t size,
                                  int direction)
{
    RT_ASSERT(serial != RT_NULL);

    if (direction != SERIAL_DMA_TX || !buf || size == 0) {
        return 0u;
    }

    struct ifx_uart* uart = (struct ifx_uart*)serial->parent.user_data;
    RT_ASSERT(uart != RT_NULL);

#if defined(BSP_USING_UART1_DMA_TX) || defined(BSP_USING_UART2_DMA_TX) || defined(BSP_USING_UART4_DMA_TX) || defined(BSP_USING_UART5_DMA_TX)
    if (uart->config->dma_enabled) {
        rt_size_t remaining = size;
        const uint8_t* ptr = buf;

        while (remaining > 0u) {
            rt_size_t chunk = (remaining > UART_TX_BUFFER_SIZE)
                ? (rt_size_t)UART_TX_BUFFER_SIZE
                : remaining;
            uart_dma_tx_send_chunk(uart->config, ptr, chunk);
            ptr += chunk;
            remaining -= chunk;
        }
        return size;
    }
#endif

    for (rt_size_t i = 0; i < size; i++) {
        uint32_t count = 0;
        while (count == 0) {
            count = Cy_SCB_UART_Put(uart->config->usart_x, buf[i]);
        }
    }
    return size;
}

const struct usart_ops _uart_ops = {
    ifx_configure,
    ifx_control,
    ifx_putc,
    ifx_getc,
    ifx_dma_transmit,
};

rt_err_t drv_usart_init(void)
{
    rt_err_t result;
    rt_size_t obj_num = sizeof(uart_obj) / sizeof(uart_obj[0]);
    struct serial_configure cfg = SERIAL_DEFAULT_CONFIG;

    for (int index = 0; index < obj_num; index++) {
        uart_obj[index].config = &uart_config[index];
        uart_obj[index].serial.ops = &_uart_ops;
        uart_obj[index].serial.config = cfg;

        uart_obj[index].config->uart_obj = rt_malloc(sizeof(mtb_hal_uart_t));
        uart_obj[index].config->uart_context = rt_malloc(sizeof(cy_stc_scb_uart_context_t));

        RT_ASSERT(uart_obj[index].config->uart_obj != RT_NULL);
        RT_ASSERT(uart_obj[index].config->uart_context != RT_NULL);

#if defined(BSP_USING_UART1_DMA_TX) || defined(BSP_USING_UART2_DMA_TX) || defined(BSP_USING_UART4_DMA_TX) || defined(BSP_USING_UART5_DMA_TX)
        uart_obj[index].config->tx_buffer = RT_NULL;
        uart_obj[index].config->tx_dma_descriptor = RT_NULL;
        uart_obj[index].config->tx_dma_done = 1u;
        uart_obj[index].config->dma_enabled = 0u;
        uart_obj[index].config->dma_initialized = 0u;

        if (0
    #ifdef BSP_USING_UART1_DMA_TX
            || uart_obj[index].config->usart_x == SCB1
    #endif
    #ifdef BSP_USING_UART2_DMA_TX
            || uart_obj[index].config->usart_x == SCB2
    #endif
        #ifdef BSP_USING_UART4_DMA_TX
            || uart_obj[index].config->usart_x == SCB4
        #endif
    #ifdef BSP_USING_UART5_DMA_TX
            || uart_obj[index].config->usart_x == SCB5
    #endif
        ) {
            uart_obj[index].config->dma_enabled = 1u;

    #ifdef BSP_USING_UART1_DMA_TX
            if (uart_obj[index].config->usart_x == SCB1) {
                uart_obj[index].config->tx_buffer = uart1_tx_buf;
                uart_obj[index].config->tx_dma_descriptor = &uart1_tx_desc;
            }
    #endif
    #ifdef BSP_USING_UART2_DMA_TX
            if (uart_obj[index].config->usart_x == SCB2) {
                uart_obj[index].config->tx_buffer = uart2_tx_buf;
                uart_obj[index].config->tx_dma_descriptor = &uart2_tx_desc;
            }
    #endif
    #ifdef BSP_USING_UART4_DMA_TX
            if (uart_obj[index].config->usart_x == SCB4) {
                uart_obj[index].config->tx_buffer = uart4_tx_buf;
                uart_obj[index].config->tx_dma_descriptor = &uart4_tx_desc;
            }
    #endif
    #ifdef BSP_USING_UART5_DMA_TX
            if (uart_obj[index].config->usart_x == SCB5) {
                uart_obj[index].config->tx_buffer = uart5_tx_buf;
                uart_obj[index].config->tx_dma_descriptor = &uart5_tx_desc;
            }
    #endif
        }

        if (uart_obj[index].config->dma_enabled) {
            char sem_name[RT_NAME_MAX];
            rt_snprintf(sem_name, sizeof(sem_name), "%s_dma", uart_obj[index].config->name);
            uart_obj[index].config->tx_dma_sem = rt_sem_create(sem_name, 1, RT_IPC_FLAG_FIFO);
            RT_ASSERT(uart_obj[index].config->tx_dma_sem != RT_NULL);
        }
#endif /* BSP_USING_UARTx_DMA_TX */

        rt_uint16_t flags = RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX;
#if defined(BSP_USING_UART1_DMA_TX) || defined(BSP_USING_UART2_DMA_TX) || defined(BSP_USING_UART4_DMA_TX) || defined(BSP_USING_UART5_DMA_TX)
        if (uart_obj[index].config->dma_enabled) {
            flags |= RT_DEVICE_FLAG_DMA_TX;
        }
#endif
        result = hal_serial_register(&uart_obj[index].serial,
                                     uart_obj[index].config->name,
                                     flags,
                                     &uart_obj[index]);
        RT_ASSERT(result == RT_EOK);
    }

    return RT_EOK;
}