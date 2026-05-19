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
#include <stdint.h>


#include "cy_scb_uart.h"
#include "cycfg_dmas.h"
#include "cymem_CM55_0.h"
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

#if defined(BSP_USING_UART1_DMA_TX) || defined(BSP_USING_UART2_DMA_TX) || defined(BSP_USING_UART4_DMA_TX) || defined(BSP_USING_UART5_DMA_TX) || defined(BSP_USING_UART9_DMA_TX) || defined(BSP_USING_UART10_DMA_TX) || defined(BSP_USING_UART11_DMA_TX)
    #define UART_DMA_TX_SUPPORTED
    #define UART_DMA_XCOUNT_MAX 256u
#endif

#ifdef UART_DMA_TX_SUPPORTED

CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static uint8_t uart_dma_tx_bounce_buf[UART_DMA_XCOUNT_MAX];

static rt_sem_t uart_dma_bounce_sem = RT_NULL;

    #ifdef BSP_USING_UART1_DMA_TX
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static cy_stc_dma_descriptor_t uart1_tx_desc;
    #endif

    #ifdef BSP_USING_UART2_DMA_TX
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static cy_stc_dma_descriptor_t uart2_tx_desc;
    #endif

    #ifdef BSP_USING_UART4_DMA_TX
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static cy_stc_dma_descriptor_t uart4_tx_desc;
    #endif

    #ifdef BSP_USING_UART5_DMA_TX
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static cy_stc_dma_descriptor_t uart5_tx_desc;
    #endif

    #ifdef BSP_USING_UART9_DMA_TX
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static cy_stc_dma_descriptor_t uart9_tx_desc;
    #endif

    #ifdef BSP_USING_UART10_DMA_TX
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static cy_stc_dma_descriptor_t uart10_tx_desc;
    #endif

    #ifdef BSP_USING_UART11_DMA_TX
CY_SECTION(".cy_sharedmem")
CY_ALIGN(32)
static cy_stc_dma_descriptor_t uart11_tx_desc;
    #endif

#endif /* BSP_USING_UARTx_DMA_TX */

#ifdef UART_DMA_TX_SUPPORTED
static void uart_dma_bind_resource(struct ifx_uart_config* config)
{
    #ifdef BSP_USING_UART1_DMA_TX
    if (config->usart_x == SCB1) {
        config->dma_enabled = 1u;
        config->tx_dma_descriptor = &uart1_tx_desc;
        return;
    }
    #endif
    #ifdef BSP_USING_UART2_DMA_TX
    if (config->usart_x == SCB2) {
        config->dma_enabled = 1u;
        config->tx_dma_descriptor = &uart2_tx_desc;
        return;
    }
    #endif
    #ifdef BSP_USING_UART4_DMA_TX
    if (config->usart_x == SCB4) {
        config->dma_enabled = 1u;
        config->tx_dma_descriptor = &uart4_tx_desc;
        return;
    }
    #endif
    #ifdef BSP_USING_UART5_DMA_TX
    if (config->usart_x == SCB5) {
        config->dma_enabled = 1u;
        config->tx_dma_descriptor = &uart5_tx_desc;
        return;
    }
    #endif
    #ifdef BSP_USING_UART9_DMA_TX
    if (config->usart_x == SCB9) {
        config->dma_enabled = 1u;
        config->tx_dma_descriptor = &uart9_tx_desc;
        return;
    }
    #endif
    #ifdef BSP_USING_UART10_DMA_TX
    if (config->usart_x == SCB10) {
        config->dma_enabled = 1u;
        config->tx_dma_descriptor = &uart10_tx_desc;
        return;
    }
    #endif
    #ifdef BSP_USING_UART11_DMA_TX
    if (config->usart_x == SCB11) {
        config->dma_enabled = 1u;
        config->tx_dma_descriptor = &uart11_tx_desc;
        return;
    }
    #endif
}

static void uart_dma_prepare(struct ifx_uart_config* config)
{
    config->tx_dma_descriptor = RT_NULL;
    config->tx_dma_done = 1u;
    config->tx_using_bounce = 0u;
    config->dma_enabled = 0u;
    config->dma_initialized = 0u;

    uart_dma_bind_resource(config);

    if (config->dma_enabled) {
        char sem_name[RT_NAME_MAX];
        rt_snprintf(sem_name, sizeof(sem_name), "%s_dma", config->name);
        config->tx_dma_sem = rt_sem_create(sem_name, 1, RT_IPC_FLAG_FIFO);
        RT_ASSERT(config->tx_dma_sem != RT_NULL);
    }
}

static void uart_dma_clean_src_cache(const void* src, rt_size_t len)
{
    #if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    if (src == RT_NULL || len == 0u) {
        return;
    }

    uintptr_t start = (uintptr_t)src & ~((uintptr_t)__SCB_DCACHE_LINE_SIZE - 1u);
    uintptr_t end = ((uintptr_t)src + len + __SCB_DCACHE_LINE_SIZE - 1u) & ~((uintptr_t)__SCB_DCACHE_LINE_SIZE - 1u);

    SCB_CleanDCache_by_Addr((void*)start, (int32_t)(end - start));
    #else
    (void)src;
    (void)len;
    #endif
}

static rt_bool_t uart_dma_src_accessible(const void* src, rt_size_t len)
{
    if (src == RT_NULL || len == 0u) {
        return RT_FALSE;
    }

    uintptr_t addr = (uintptr_t)src;
    uintptr_t start = (uintptr_t)CYMEM_CM55_0_m55_allocatable_shared_START;
    uintptr_t end = start + (uintptr_t)CYMEM_CM55_0_m55_allocatable_shared_SIZE;

    if (addr < start || addr >= end) {
        return RT_FALSE;
    }

    return (end - addr) >= (uintptr_t)len;
}
#endif

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
#ifdef BSP_USING_UART9
    UART9_INDEX,
#endif
#ifdef BSP_USING_UART10
    UART10_INDEX,
#endif
#ifdef BSP_USING_UART11
    UART11_INDEX,
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
#ifdef BSP_USING_UART9
    UART9_CONFIG,
#endif
#ifdef BSP_USING_UART10
    UART10_CONFIG,
#endif
#ifdef BSP_USING_UART11
    UART11_CONFIG,
#endif
};

#define UART_OBJ_NUM (sizeof(uart_config) / sizeof(uart_config[0]))

static struct ifx_uart uart_obj[UART_OBJ_NUM] = { 0 };
static mtb_hal_uart_t uart_hal_obj[UART_OBJ_NUM];
static cy_stc_scb_uart_context_t uart_hal_context[UART_OBJ_NUM];

#ifdef UART_DMA_TX_SUPPORTED

static void init_uart_tx_dma(struct ifx_uart* uart)
{
    struct ifx_uart_config* config = uart->config;
    volatile cy_en_dma_status_t st;

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
    const uint8_t* dma_src = src;

    RT_ASSERT(len > 0u && len <= UART_DMA_XCOUNT_MAX);

    rt_sem_take(config->tx_dma_sem, RT_WAITING_FOREVER);
    config->tx_using_bounce = 0u;

    if (!uart_dma_src_accessible(src, len)) {
        RT_ASSERT(uart_dma_bounce_sem != RT_NULL);
        rt_sem_take(uart_dma_bounce_sem, RT_WAITING_FOREVER);

        rt_memcpy(uart_dma_tx_bounce_buf, src, len);
        dma_src = uart_dma_tx_bounce_buf;
        config->tx_using_bounce = 1u;
    }

    uart_dma_clean_src_cache(dma_src, len);

    Cy_DMA_Descriptor_SetSrcAddress(config->tx_dma_descriptor,
                                    (void*)dma_src);
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

    if (config->tx_using_bounce) {
        config->tx_using_bounce = 0u;
        if (uart_dma_bounce_sem != RT_NULL) {
            rt_sem_release(uart_dma_bounce_sem);
        }
    }

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

#ifdef BSP_USING_UART9
void uart9_isr_callback(void)
{
    rt_interrupt_enter();
    uart_isr(&uart_obj[UART9_INDEX].serial);
    rt_interrupt_leave();
}
#endif

#ifdef BSP_USING_UART10
void uart10_isr_callback(void)
{
    rt_interrupt_enter();
    uart_isr(&uart_obj[UART10_INDEX].serial);
    rt_interrupt_leave();
}
#endif

#ifdef BSP_USING_UART11
void uart11_isr_callback(void)
{
    rt_interrupt_enter();
    uart_isr(&uart_obj[UART11_INDEX].serial);
    rt_interrupt_leave();
}
#endif

#ifdef BSP_USING_UART1_DMA_TX
void uart1_dma_tx_isr_callback(void)
{
    uart_dma_tx_isr(&uart_obj[UART1_INDEX]);
}
#endif
#ifdef BSP_USING_UART2_DMA_TX
void uart2_dma_tx_isr_callback(void)
{
    uart_dma_tx_isr(&uart_obj[UART2_INDEX]);
}
#endif
#ifdef BSP_USING_UART4_DMA_TX
void uart4_dma_tx_isr_callback(void)
{
    uart_dma_tx_isr(&uart_obj[UART4_INDEX]);
}
#endif
#ifdef BSP_USING_UART5_DMA_TX
void uart5_dma_tx_isr_callback(void)
{
    uart_dma_tx_isr(&uart_obj[UART5_INDEX]);
}
#endif
#ifdef BSP_USING_UART9_DMA_TX
void uart9_dma_tx_isr_callback(void)
{
    uart_dma_tx_isr(&uart_obj[UART9_INDEX]);
}
#endif
#ifdef BSP_USING_UART10_DMA_TX
void uart10_dma_tx_isr_callback(void)
{
    uart_dma_tx_isr(&uart_obj[UART10_INDEX]);
}
#endif
#ifdef BSP_USING_UART11_DMA_TX
void uart11_dma_tx_isr_callback(void)
{
    uart_dma_tx_isr(&uart_obj[UART11_INDEX]);
}
#endif

static rt_err_t ifx_control(struct serial_device* serial, int cmd, void* arg);

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

#ifdef UART_DMA_TX_SUPPORTED
    if (uart->config->dma_enabled && !uart->config->dma_initialized) {
        RT_ASSERT(uart->config->tx_dma_descriptor != RT_NULL);

        uart->config->tx_dma_done = 1u;
        init_uart_tx_dma(uart);
        uart->config->dma_initialized = 1u;
    }
#endif

    if (serial->parent.open_flag & RT_DEVICE_FLAG_INT_RX) {
        ifx_control(serial, RT_DEVICE_CTRL_SET_INT, (void*)RT_DEVICE_FLAG_INT_RX);
    }

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
#ifdef UART_DMA_TX_SUPPORTED
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
#ifdef UART_DMA_TX_SUPPORTED
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

    uint32_t read_data = Cy_SCB_UART_Get(uart->config->usart_x);

    if (read_data == CY_SCB_UART_RX_NO_DATA) {
        return -1;
    }

    return (int)(read_data & 0xff);
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

#ifdef UART_DMA_TX_SUPPORTED
    if (uart->config->dma_enabled) {
        rt_size_t remaining = size;
        const uint8_t* ptr = (const uint8_t*)buf;

        while (remaining > 0u) {
            rt_size_t chunk = (remaining > UART_DMA_XCOUNT_MAX)
                ? (rt_size_t)UART_DMA_XCOUNT_MAX
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
    struct serial_configure cfg = SERIAL_DEFAULT_CONFIG;

#ifdef UART_DMA_TX_SUPPORTED
    if (uart_dma_bounce_sem == RT_NULL) {
        uart_dma_bounce_sem = rt_sem_create("uart_dbuf", 1, RT_IPC_FLAG_FIFO);
        RT_ASSERT(uart_dma_bounce_sem != RT_NULL);
    }
#endif

    for (rt_size_t index = 0; index < UART_OBJ_NUM; index++) {
        uart_obj[index].config = &uart_config[index];
        uart_obj[index].serial.ops = &_uart_ops;
        uart_obj[index].serial.config = cfg;

        uart_obj[index].config->uart_obj = &uart_hal_obj[index];
        uart_obj[index].config->uart_context = &uart_hal_context[index];

#ifdef UART_DMA_TX_SUPPORTED
        uart_dma_prepare(uart_obj[index].config);
#endif /* BSP_USING_UARTx_DMA_TX */

        rt_uint16_t flags = RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX;
#ifdef UART_DMA_TX_SUPPORTED
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