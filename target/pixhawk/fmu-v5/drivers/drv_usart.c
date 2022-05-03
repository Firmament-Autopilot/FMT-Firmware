/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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
#include <firmament.h>

#include "drv_usart.h"
#include "hal/serial/serial.h"
#include "stm32f7xx_ll_usart.h"

#define UART_ENABLE_IRQ(n)  NVIC_EnableIRQ((n))
#define UART_DISABLE_IRQ(n) NVIC_DisableIRQ((n))

/*
    UART1 ==> IO Debug Console
    UART2 ==> Serial1 (TELEM1)
    UART3 ==> Serial2 (TELEM2)
    UART4 ==> Serial3 (GPS)
    UART6 ==> FMU/IO Serial
    UART7 ==> Serial5 (SERIAL 4/5)
    UART8 ==> Serial4 (SERIAL 4/5)
*/

#define USING_UART1
#define USING_UART2
#define USING_UART3
// #define USING_UART4
// #define USING_UART5
// #define USING_UART6  /* disable USART6, as it conflicts with io sbus input */
#define USING_UART7
#define USING_UART8

/* config for serial_configure structure */
#define SERIAL3_DEFAULT_CONFIG                    \
    {                                             \
        BAUD_RATE_9600,      /* 9600 bits/s */    \
            DATA_BITS_8,     /* 8 databits */     \
            STOP_BITS_1,     /* 1 stopbit */      \
            PARITY_NONE,     /* No parity  */     \
            BIT_ORDER_LSB,   /* LSB first sent */ \
            NRZ_NORMAL,      /* Normal mode */    \
            SERIAL_RB_BUFSZ, /* Buffer size */    \
            0                                     \
    }

#define SERIAL5_DEFAULT_CONFIG                  \
    {                                           \
        BAUD_RATE_230400,  /* 115200 bits/s */  \
            DATA_BITS_8,   /* 8 databits */     \
            STOP_BITS_1,   /* 1 stopbit */      \
            PARITY_NONE,   /* No parity  */     \
            BIT_ORDER_LSB, /* LSB first sent */ \
            NRZ_NORMAL,    /* Normal mode */    \
            1024,          /* Buffer size */    \
            0                                   \
    }

/* STM32 uart driver */
struct stm32_uart {
    USART_TypeDef* uart_device;
    IRQn_Type irq;
    struct stm32_uart_dma {
        /* dma instance */
        DMA_TypeDef* dma_device;
        /* rx dma stream */
        uint32_t rx_stream;
        /* dma channel */
        uint32_t rx_ch;
        /* dma rx irq */
        uint8_t rx_irq;
        /* tx dma stream */
        uint32_t tx_stream;
        /* dma channel */
        uint32_t tx_ch;
        /* dma tx irq */
        uint8_t tx_irq;
        /* setting receive len */
        rt_size_t setting_recv_len;
        /* last receive index */
        rt_size_t last_recv_index;
    } dma;
};

static rt_size_t usart_dma_transmit(struct serial_device* serial, rt_uint8_t* buf, rt_size_t size, int direction);
static int usart_getc(struct serial_device* serial);
static int usart_putc(struct serial_device* serial, char c);
static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg);
static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg);

static void _dma_clear_flags(DMA_TypeDef* dma, uint32_t stream)
{
    static const uint8_t flagBitshiftOffset[8] = { 0U, 6U, 16U, 22U, 0U, 6U, 16U, 22U };

    uint8_t stream_index = flagBitshiftOffset[stream];
    if (stream < LL_DMA_STREAM_4) {
        dma->LIFCR = 0x3DU << stream_index;
    } else {
        dma->HIFCR = 0x3DU << stream_index;
    }
}

/**
 * Serial port receive idle process. This need add to uart idle ISR.
 *
 * @param serial serial device
 */
static void dma_uart_rx_idle_isr(struct serial_device* serial)
{
    struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;
    rt_size_t recv_total_index, recv_len;
    rt_base_t level;
    uint32_t remain_bytes;

    /* disable interrupt */
    level = rt_hw_interrupt_disable();
    /* check remain bytes to receive */
    remain_bytes = LL_DMA_GetDataLength(uart->dma.dma_device, uart->dma.rx_stream);
    /* total received bytes */
    recv_total_index = uart->dma.setting_recv_len - remain_bytes;
    /* received bytes at this time */
    recv_len = recv_total_index - uart->dma.last_recv_index;
    /* update last received total bytes */
    uart->dma.last_recv_index = recv_total_index;
    /* enable interrupt */
    rt_hw_interrupt_enable(level);

    if (recv_len) {
        /* high-level ISR routine */
        hal_serial_isr(serial, SERIAL_EVENT_RX_DMADONE | (recv_len << 8));
    }
}

/**
 * DMA receive done process. This need add to DMA receive done ISR.
 *
 * @param serial serial device
 */
static void dma_rx_done_isr(struct serial_device* serial)
{
    struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;
    rt_size_t recv_len;
    rt_base_t level;

    /* disable interrupt */
    level = rt_hw_interrupt_disable();
    /* received bytes at this time */
    recv_len = uart->dma.setting_recv_len - uart->dma.last_recv_index;
    /* reset last recv index */
    uart->dma.last_recv_index = 0;
    /* enable interrupt */
    rt_hw_interrupt_enable(level);

    if (recv_len) {
        /* high-level ISR routine */
        hal_serial_isr(serial, SERIAL_EVENT_RX_DMADONE | (recv_len << 8));
    }
}

/**
 * DMA transmit done process. This need add to DMA receive done ISR.
 *
 * @param serial serial device
 */
static void dma_tx_done_isr(struct serial_device* serial)
{
    /* high-level ISR routine */
    hal_serial_isr(serial, SERIAL_EVENT_TX_DMADONE);
}

/**
 * Uart common interrupt process. This need add to uart ISR.
 *
 * @param serial serial device
 */
static void uart_isr(struct serial_device* serial)
{
    struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;

    if (LL_USART_IsActiveFlag_RXNE(uart->uart_device)
        && LL_USART_IsEnabledIT_RXNE(uart->uart_device)) {
        /* high-level ISR routine */
        hal_serial_isr(serial, SERIAL_EVENT_RX_IND);
        /* the RXNE flag is cleared by reading the USART_RDR register */
    }

    if (LL_USART_IsActiveFlag_IDLE(uart->uart_device)
        && LL_USART_IsEnabledIT_IDLE(uart->uart_device)) {
        if (LL_USART_IsEnabledDMAReq_RX(uart->uart_device)) {
            dma_uart_rx_idle_isr(serial);
        }
        /* clear interrupt flag */
        LL_USART_ClearFlag_IDLE(uart->uart_device);
    }

    if (LL_USART_IsActiveFlag_TC(uart->uart_device)
        && LL_USART_IsEnabledIT_TC(uart->uart_device)) {
        // TODO: this can be used for TX_INT mode?
        /* high-level ISR routine */
        // hal_serial_isr(serial, SERIAL_EVENT_TX_DONE);

        /* clear interrupt */
        LL_USART_ClearFlag_TC(uart->uart_device);
    }

    if (LL_USART_IsActiveFlag_ORE(uart->uart_device) != RESET) {
        usart_getc(serial);
        LL_USART_ClearFlag_ORE(uart->uart_device);
    }
}

#ifdef USING_UART1
static struct serial_device serial3; // GPS

/* UART2 device driver structure */
struct stm32_uart uart1 = {
    .uart_device = USART1,
    .irq = USART1_IRQn,
    .dma = {
        .dma_device = DMA2,
        .rx_stream = LL_DMA_STREAM_2,
        .rx_ch = LL_DMA_CHANNEL_4,
        .rx_irq = DMA2_Stream2_IRQn,
        .tx_stream = LL_DMA_STREAM_7,
        .tx_ch = LL_DMA_CHANNEL_4,
        .tx_irq = DMA2_Stream7_IRQn,
        .setting_recv_len = 0,
        .last_recv_index = 0,
    },
};

void USART1_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial3);
    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA2_Stream2_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    if (LL_DMA_IsActiveFlag_TC2(DMA2)) {
        dma_rx_done_isr(&serial3);
        /* clear the interrupt flag */
        LL_DMA_ClearFlag_TC2(DMA2);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA2_Stream7_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    if (LL_DMA_IsActiveFlag_TC7(DMA2)) {
        dma_tx_done_isr(&serial3);
        /* clear the interrupt flag */
        LL_DMA_ClearFlag_TC7(DMA2);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART1

#ifdef USING_UART2
static struct serial_device serial1; // TELEM1
/* UART2 device driver structure */
struct stm32_uart uart2 = {
    .uart_device = USART2,
    .irq = USART2_IRQn,
    .dma = { 0 }
};

void USART2_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial1);
    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART2

#ifdef USING_UART3
static struct serial_device serial2; // TELEM2

/* UART3 device driver structure */
struct stm32_uart uart3 = {
    .uart_device = USART3,
    .irq = USART3_IRQn,
    .dma = {
        .dma_device = DMA1,
        .rx_stream = LL_DMA_STREAM_1,
        .rx_ch = LL_DMA_CHANNEL_4,
        .rx_irq = DMA1_Stream1_IRQn,
        .tx_stream = LL_DMA_STREAM_3,
        .tx_ch = LL_DMA_CHANNEL_4,
        .tx_irq = DMA1_Stream3_IRQn,
        .setting_recv_len = 0,
        .last_recv_index = 0,
    },
};

void USART3_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial2);
    /* leave interrupt */
    rt_interrupt_leave();
}

/* uart3 and uart7 share the same DMA stream. disable DMA on usart3 and enable DMA for uart7 */
void DMA1_Stream1_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    if (LL_DMA_IsActiveFlag_TC1(DMA1)) {
        dma_rx_done_isr(&serial2);
        /* clear the interrupt flag */
        LL_DMA_ClearFlag_TC1(DMA1);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA1_Stream3_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    if (LL_DMA_IsActiveFlag_TC3(DMA1)) {
        dma_tx_done_isr(&serial2);
        /* clear the interrupt flag */
        LL_DMA_ClearFlag_TC3(DMA1);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART3

#ifdef USING_UART6
static struct serial_device serial4; // TELEM3

/* UART6 device driver structure */
struct stm32_uart uart6 = {
    .uart_device = USART6,
    .irq = USART6_IRQn,
    .dma = { 0 }
};

void USART6_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial4);
    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART6

#ifdef USING_UART7
static struct serial_device serial0; // FMU Debug

/* UART7 device driver structure */
struct stm32_uart uart7 = {
    .uart_device = UART7,
    .irq = UART7_IRQn,
    .dma = { 0 }
};

void UART7_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial0);
    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART7

#ifdef USING_UART8
static struct serial_device serial5; // FMTIO

/* UART7 device driver structure */
struct stm32_uart uart8 = {
    .uart_device = UART8,
    .irq = UART8_IRQn,
    .dma = {
        .dma_device = DMA1,
        .rx_stream = LL_DMA_STREAM_6,
        .rx_ch = LL_DMA_CHANNEL_5,
        .rx_irq = DMA1_Stream6_IRQn,
        .tx_stream = LL_DMA_STREAM_0,
        .tx_ch = LL_DMA_CHANNEL_5,
        .tx_irq = DMA1_Stream0_IRQn,
        .setting_recv_len = 0,
        .last_recv_index = 0,
    },
};

void UART8_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial5);
    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA1_Stream6_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    if (LL_DMA_IsActiveFlag_TC6(DMA1)) {
        dma_rx_done_isr(&serial5);
        /* clear the interrupt flag */
        LL_DMA_ClearFlag_TC6(DMA1);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA1_Stream0_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    if (LL_DMA_IsActiveFlag_TC0(DMA1)) {
        dma_tx_done_isr(&serial5);
        /* clear the interrupt flag */
        LL_DMA_ClearFlag_TC0(DMA1);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART8

static void RCC_Configuration(void)
{
#ifdef USING_UART1
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);
#endif /* USING_UART1 */

#ifdef USING_UART2
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART2);
#endif /* USING_UART2 */

#ifdef USING_UART3
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART3);
#endif /* USING_UART3 */

#ifdef USING_UART6
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART6);
#endif /* USING_UART6 */

#ifdef USING_UART7
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_UART7);
#endif /* USING_UART7 */

#ifdef USING_UART8
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_UART8);
#endif /* USING_UART8 */

    /* DMA controller clock enable */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA2);
}

static void GPIO_Configuration(void)
{
    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;

#ifdef USING_UART1
    GPIO_InitStruct.Pin = LL_GPIO_PIN_7;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
#endif /* USING_UART1 */

#ifdef USING_UART2
    GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
    LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_5;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
    LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
#endif /* USING_UART2 */

#ifdef USING_UART3
    GPIO_InitStruct.Pin = LL_GPIO_PIN_9;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
    LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_8;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
    LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
#endif /* USING_UART3 */

#ifdef USING_UART6
    GPIO_InitStruct.Pin = LL_GPIO_PIN_14;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
    LL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_9;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
    LL_GPIO_Init(GPIOG, &GPIO_InitStruct);
#endif /* USING_UART6 */

#ifdef USING_UART7
    GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_8;
    LL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_8;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_8;
    LL_GPIO_Init(GPIOE, &GPIO_InitStruct);
#endif /* USING_UART7 */

#ifdef USING_UART8
    GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_8;
    LL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_8;
    LL_GPIO_Init(GPIOE, &GPIO_InitStruct);
#endif /* USING_UART8 */
}

static void NVIC_Configuration(struct stm32_uart* uart)
{
    // TODO: configure the PreemptionPriority and SubPriority

    /* enable the usart interrupt */
    NVIC_SetPriority(uart->irq, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
    NVIC_EnableIRQ(uart->irq);

    /* enable the dma interrupt */
    if (uart->dma.rx_irq > 0) {
        NVIC_SetPriority(uart->dma.rx_irq, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 2, 0));
        NVIC_EnableIRQ(uart->dma.rx_irq);
    }

    if (uart->dma.tx_irq > 0) {
        NVIC_SetPriority(uart->dma.tx_irq, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 2, 0));
        NVIC_EnableIRQ(uart->dma.tx_irq);
    }
}

static void _dma_transmit(struct stm32_uart* uart, rt_uint8_t* buf, rt_size_t size)
{
    if (LL_DMA_IsEnabledStream(uart->dma.dma_device, uart->dma.tx_stream)) {
        /* if the dma stream is enabled, disable it */
        LL_DMA_DisableStream(uart->dma.dma_device, uart->dma.tx_stream);
        /* wait all current transfers are finished */
        while (LL_DMA_IsEnabledStream(uart->dma.dma_device, uart->dma.tx_stream))
            ;
    }

    /* all interrupt flags much be cleared before the stream can be re-enabled */
    _dma_clear_flags(uart->dma.dma_device, uart->dma.tx_stream);
    /* set data length */
    LL_DMA_SetDataLength(uart->dma.dma_device, uart->dma.tx_stream, size);
    /* configure dma address */
    LL_DMA_SetMemoryAddress(uart->dma.dma_device, uart->dma.tx_stream, (uint32_t)buf);
    /* enable common interrupts */
    LL_DMA_EnableIT_TC(uart->dma.dma_device, uart->dma.tx_stream);
    /* enable the specified dma stream */
    LL_DMA_EnableStream(uart->dma.dma_device, uart->dma.tx_stream);

    /* clear uart transmission complete flag */
    LL_USART_ClearFlag_TC(uart->uart_device);
    /* enable the uart dma transmit */
    LL_USART_EnableDMAReq_TX(uart->uart_device);
}

static void _dma_receive(struct stm32_uart* uart)
{
    /* all interrupt flags much be cleared before the stream can be re-enabled */
    _dma_clear_flags(uart->dma.dma_device, uart->dma.rx_stream);
    /* enable common interrupts */
    LL_DMA_EnableIT_TC(uart->dma.dma_device, uart->dma.tx_stream);
    LL_USART_EnableIT_IDLE(uart->uart_device);
    /* enable the specified dma stream */
    LL_DMA_EnableStream(uart->dma.dma_device, uart->dma.rx_stream);

    /* clear uart transmission complete flag */
    LL_USART_ClearFlag_TC(uart->uart_device);
    /* enable the uart dma receive */
    LL_USART_EnableDMAReq_RX(uart->uart_device);
}

static void _dma_rx_config(struct stm32_uart* uart, rt_uint8_t* buf, rt_size_t size)
{
    LL_DMA_InitTypeDef DMA_InitStruct;

    /* set expected receive length */
    uart->dma.setting_recv_len = size;

    DMA_InitStruct.PeriphOrM2MSrcAddress = (uint32_t)&uart->uart_device->RDR;
    DMA_InitStruct.MemoryOrM2MDstAddress = (uint32_t)buf;
    DMA_InitStruct.Direction = LL_DMA_DIRECTION_PERIPH_TO_MEMORY;
    DMA_InitStruct.Mode = LL_DMA_MODE_CIRCULAR;
    DMA_InitStruct.PeriphOrM2MSrcIncMode = LL_DMA_PERIPH_NOINCREMENT;
    DMA_InitStruct.MemoryOrM2MDstIncMode = LL_DMA_MEMORY_INCREMENT;
    DMA_InitStruct.PeriphOrM2MSrcDataSize = LL_DMA_PDATAALIGN_BYTE;
    DMA_InitStruct.MemoryOrM2MDstDataSize = LL_DMA_MDATAALIGN_BYTE;
    DMA_InitStruct.NbData = size;
    DMA_InitStruct.Channel = uart->dma.rx_ch;
    DMA_InitStruct.Priority = LL_DMA_PRIORITY_HIGH;
    DMA_InitStruct.FIFOMode = LL_DMA_FIFOMODE_DISABLE;
    DMA_InitStruct.FIFOThreshold = LL_DMA_FIFOTHRESHOLD_1_4;
    DMA_InitStruct.MemBurst = LL_DMA_MBURST_SINGLE;
    DMA_InitStruct.PeriphBurst = LL_DMA_PBURST_SINGLE;
    /* init rx dma */
    LL_DMA_Init(uart->dma.dma_device, uart->dma.rx_stream, &DMA_InitStruct);

    /* disable double buffer mode */
    LL_DMA_DisableDoubleBufferMode(uart->dma.dma_device, uart->dma.rx_stream);
    LL_DMA_DisableFifoMode(uart->dma.dma_device, uart->dma.rx_stream);

    /* start to receive data */
    _dma_receive(uart);
}

static void _dma_tx_config(struct stm32_uart* uart)
{
    LL_DMA_InitTypeDef DMA_InitStruct;

    DMA_InitStruct.PeriphOrM2MSrcAddress = (uint32_t)&uart->uart_device->TDR;
    DMA_InitStruct.MemoryOrM2MDstAddress = 0x00000000U; /* will be configured later */
    DMA_InitStruct.Direction = LL_DMA_DIRECTION_MEMORY_TO_PERIPH;
    DMA_InitStruct.Mode = LL_DMA_MODE_NORMAL;
    DMA_InitStruct.PeriphOrM2MSrcIncMode = LL_DMA_PERIPH_NOINCREMENT;
    DMA_InitStruct.MemoryOrM2MDstIncMode = LL_DMA_MEMORY_INCREMENT;
    DMA_InitStruct.PeriphOrM2MSrcDataSize = LL_DMA_PDATAALIGN_BYTE;
    DMA_InitStruct.MemoryOrM2MDstDataSize = LL_DMA_MDATAALIGN_BYTE;
    DMA_InitStruct.NbData = 0x00000000U; /* will be configured later */
    DMA_InitStruct.Channel = uart->dma.tx_ch;
    DMA_InitStruct.Priority = LL_DMA_PRIORITY_HIGH;
    DMA_InitStruct.FIFOMode = LL_DMA_FIFOMODE_DISABLE;
    DMA_InitStruct.FIFOThreshold = LL_DMA_FIFOTHRESHOLD_1_4;
    DMA_InitStruct.MemBurst = LL_DMA_MBURST_SINGLE;
    DMA_InitStruct.PeriphBurst = LL_DMA_PBURST_SINGLE;
    /* init tx dma */
    LL_DMA_Init(uart->dma.dma_device, uart->dma.tx_stream, &DMA_InitStruct);

    /* disable double buffer mode */
    LL_DMA_DisableDoubleBufferMode(uart->dma.dma_device, uart->dma.tx_stream);
    LL_DMA_DisableFifoMode(uart->dma.dma_device, uart->dma.tx_stream);
}

static void _close_usart(struct serial_device* serial)
{
    struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;

    if (serial->parent.open_flag & RT_DEVICE_FLAG_INT_RX) {
        /* disable int rx irq */
        LL_USART_DisableIT_RXNE(uart->uart_device);
    }

    if (serial->parent.open_flag & RT_DEVICE_FLAG_DMA_RX) {
        /* disable dma rx irq and disable rx dma */
        LL_DMA_DisableIT_TC(uart->dma.dma_device, uart->dma.rx_stream);
        LL_USART_DisableIT_IDLE(uart->uart_device);
        LL_DMA_DisableStream(uart->dma.dma_device, uart->dma.rx_stream);
        LL_USART_DisableDMAReq_RX(uart->uart_device);
    }

    if (serial->parent.open_flag & RT_DEVICE_FLAG_DMA_TX) {
        /* disable dma tx irq and disable tx dma */
        LL_DMA_DisableIT_TC(uart->dma.dma_device, uart->dma.tx_stream);
        LL_DMA_DisableStream(uart->dma.dma_device, uart->dma.tx_stream);
        LL_USART_DisableDMAReq_TX(uart->uart_device);
    }
    /* reset last recv index */
    uart->dma.last_recv_index = 0;
}

static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg)
{
    struct stm32_uart* uart;
    LL_USART_InitTypeDef USART_InitStructure = { 0 };

    RT_ASSERT(serial != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    uart = (struct stm32_uart*)serial->parent.user_data;

    USART_InitStructure.BaudRate = cfg->baud_rate;

    if (cfg->data_bits == DATA_BITS_8) {
        USART_InitStructure.DataWidth = LL_USART_DATAWIDTH_8B;
    } else if (cfg->data_bits == DATA_BITS_9) {
        USART_InitStructure.DataWidth = LL_USART_DATAWIDTH_9B;
    }

    if (cfg->stop_bits == STOP_BITS_1) {
        USART_InitStructure.StopBits = LL_USART_STOPBITS_1;
    } else if (cfg->stop_bits == STOP_BITS_2) {
        USART_InitStructure.StopBits = LL_USART_STOPBITS_2;
    }

    if (cfg->parity == PARITY_NONE) {
        USART_InitStructure.Parity = LL_USART_PARITY_NONE;
    } else if (cfg->parity == PARITY_ODD) {
        USART_InitStructure.Parity = LL_USART_PARITY_ODD;
    } else if (cfg->parity == PARITY_EVEN) {
        USART_InitStructure.Parity = LL_USART_PARITY_EVEN;
    }
    // TODO: Add hw flow control
    USART_InitStructure.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
    USART_InitStructure.TransferDirection = LL_USART_DIRECTION_TX_RX;
    USART_InitStructure.OverSampling = LL_USART_OVERSAMPLING_16;

    /* USART need be disabled first in order to configure it */
    LL_USART_Disable(uart->uart_device);
    LL_USART_Init(uart->uart_device, &USART_InitStructure);
    LL_USART_ConfigAsyncMode(uart->uart_device);
    LL_USART_Enable(uart->uart_device);

    return RT_EOK;
}

static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg)
{
    struct stm32_uart* uart;
    rt_uint32_t ctrl_arg = (rt_uint32_t)(arg);

    RT_ASSERT(serial != RT_NULL);
    uart = (struct stm32_uart*)serial->parent.user_data;

    switch (cmd) {
    case RT_DEVICE_CTRL_CLR_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {
            /* disable rx irq */
            NVIC_DisableIRQ(uart->irq);
            /* disable interrupt */
            LL_USART_DisableIT_RXNE(uart->uart_device);
        }
        break;

    case RT_DEVICE_CTRL_SET_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {
            /* disable rx irq */
            NVIC_EnableIRQ(uart->irq);
            /* disable interrupt */
            LL_USART_EnableIT_RXNE(uart->uart_device);
        }
        break;

    /* USART DMA config */
    case RT_DEVICE_CTRL_CONFIG:
        if (ctrl_arg == RT_DEVICE_FLAG_DMA_RX) {
            struct serial_rx_fifo* rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;
            struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;

            if (LL_DMA_IsEnabledStream(uart->dma.dma_device, uart->dma.rx_stream)) {
                /* dma is busy */
                return RT_EBUSY;
            }
            _dma_rx_config(uart, rx_fifo->buffer, serial->config.bufsz);
        }

        if (ctrl_arg == RT_DEVICE_FLAG_DMA_TX) {
            struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;

            if (LL_DMA_IsEnabledStream(uart->dma.dma_device, uart->dma.tx_stream)) {
                /* dma is busy */
                return RT_EBUSY;
            }
            _dma_tx_config(uart);
        }
        break;

    /* close device */
    case RT_DEVICE_CTRL_SUSPEND:
        _close_usart(serial);
        break;

    default:
        break;
    }

    return RT_EOK;
}

static int usart_putc(struct serial_device* serial, char c)
{
    struct stm32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct stm32_uart*)serial->parent.user_data;

    // /* clear tc flag before write */
    // LL_USART_ClearFlag_TC(uart->uart_device);
    /* TC flag is cleared by a write to TDR */
    uart->uart_device->TDR = c;
    /* wait write finish */
    while (LL_USART_IsActiveFlag_TC(uart->uart_device) == RESET)
        ;

    return 1;
}

static int usart_getc(struct serial_device* serial)
{
    int ch = -1;
    struct stm32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct stm32_uart*)serial->parent.user_data;

    /* check if read data register is not empty */
    if (LL_USART_IsActiveFlag_RXNE(uart->uart_device)) {
        /* read DR will clear RXNE */
        ch = uart->uart_device->RDR & 0xff;
    }

    return ch;
}

static rt_size_t usart_dma_transmit(struct serial_device* serial, rt_uint8_t* buf, rt_size_t size, int direction)
{
    if (direction == SERIAL_DMA_TX) {
        _dma_transmit(serial->parent.user_data, buf, size);
        return size;
    }

    return 0;
}

/* usart driver operations */
static const struct usart_ops _usart_ops = {
    usart_configure,
    usart_control,
    usart_putc,
    usart_getc,
    usart_dma_transmit
};

rt_err_t drv_usart_init(void)
{
    rt_err_t rt_err = RT_EOK;
    struct serial_configure config = SERIAL_DEFAULT_CONFIG;

    RCC_Configuration();
    GPIO_Configuration();

#ifdef USING_UART1
    serial3.ops = &_usart_ops;
#ifdef SERIAL3_DEFAULT_CONFIG
    struct serial_configure serial3_config = SERIAL3_DEFAULT_CONFIG;
    serial3.config = serial3_config;
#else
    serial3.config = config;
#endif

    NVIC_Configuration(&uart1);
    /* register serial device */
    rt_err |= hal_serial_register(&serial3,
        "serial3",
        RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX,
        &uart1);
#endif /* USING_UART1 */

#ifdef USING_UART2
    serial1.ops = &_usart_ops;
#ifdef SERIAL1_DEFAULT_CONFIG
    struct serial_configure serial1_config = SERIAL1_DEFAULT_CONFIG;
    serial1.config = serial1_config;
#else
    serial1.config = config;
#endif

    NVIC_Configuration(&uart2);
    /* register serial device */
    rt_err |= hal_serial_register(&serial1,
        "serial1",
        RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
        &uart2);
#endif /* USING_UART2 */

#ifdef USING_UART3
    serial2.ops = &_usart_ops;
#ifdef SERIAL2_DEFAULT_CONFIG
    struct serial_configure serial2_config = SERIAL2_DEFAULT_CONFIG;
    serial2.config = serial2_config;
#else
    serial2.config = config;
#endif

    NVIC_Configuration(&uart3);
    /* register serial device */
    rt_err |= hal_serial_register(&serial2,
        "serial2",
        RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX,
        &uart3);
#endif /* USING_UART3 */

#ifdef USING_UART6
    serial4.ops = &_usart_ops;
#ifdef SERIAL4_DEFAULT_CONFIG
    struct serial_configure serial4_config = SERIAL4_DEFAULT_CONFIG;
    serial4.config = serial4_config;
#else
    serial4.config = config;
#endif

    NVIC_Configuration(&uart6);
    /* register serial device */
    rt_err |= hal_serial_register(&serial4,
        "serial4",
        RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
        &uart6);
#endif /* USING_UART6 */

#ifdef USING_UART7
    serial0.ops = &_usart_ops;
#ifdef SERIAL0_DEFAULT_CONFIG
    struct serial_configure serial0_config = SERIAL0_DEFAULT_CONFIG;
    serial0.config = serial0_config;
#else
    serial0.config = config;
#endif

    NVIC_Configuration(&uart7);
    /* register serial device */
    rt_err |= hal_serial_register(&serial0,
        "serial0",
        RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
        &uart7);
#endif /* USING_UART7 */

#ifdef USING_UART8
    serial5.ops = &_usart_ops;
#ifdef SERIAL5_DEFAULT_CONFIG
    struct serial_configure serial5_config = SERIAL5_DEFAULT_CONFIG;
    serial5.config = serial5_config;
#else
    serial5.config = config;
#endif

    NVIC_Configuration(&uart8);
    /* register serial device */
    rt_err |= hal_serial_register(&serial5,
        "serial5",
        RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX,
        &uart8);
#endif /* USING_UART8 */

    return rt_err;
}
