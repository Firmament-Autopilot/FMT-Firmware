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

#include "drv_usart.h"
#include "hal/serial/serial.h"
#include <firmament.h>

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

// #define USING_UART1
#define USING_UART2
#define USING_UART3
#define USING_UART4
#define USING_UART6
#define USING_UART7
#define USING_UART8

/* UART GPIO define. */
#define UART1_GPIO_TX       GPIO_Pin_9
#define UART1_TX_PIN_SOURCE GPIO_PinSource9
#define UART1_GPIO_RX       GPIO_Pin_10
#define UART1_RX_PIN_SOURCE GPIO_PinSource10
#define UART1_GPIO          GPIOA
#define UART1_GPIO_RCC      RCC_AHB1Periph_GPIOA
#define RCC_APBPeriph_UART1 RCC_APB2Periph_USART1

#define UART2_GPIO_CTS       GPIO_Pin_3
#define UART2_CTS_PIN_SOURCE GPIO_PinSource3
#define UART2_GPIO_RTS       GPIO_Pin_4
#define UART2_RTS_PIN_SOURCE GPIO_PinSource4
#define UART2_GPIO_TX        GPIO_Pin_5
#define UART2_TX_PIN_SOURCE  GPIO_PinSource5
#define UART2_GPIO_RX        GPIO_Pin_6
#define UART2_RX_PIN_SOURCE  GPIO_PinSource6
#define UART2_GPIO           GPIOD
#define UART2_GPIO_RCC       RCC_AHB1Periph_GPIOD
#define RCC_APBPeriph_UART2  RCC_APB1Periph_USART2

#define UART3_GPIO_CTS       GPIO_Pin_11
#define UART3_CTS_PIN_SOURCE GPIO_PinSource11
#define UART3_GPIO_RTS       GPIO_Pin_12
#define UART3_RTS_PIN_SOURCE GPIO_PinSource12
#define UART3_GPIO_TX        GPIO_Pin_8
#define UART3_TX_PIN_SOURCE  GPIO_PinSource8
#define UART3_GPIO_RX        GPIO_Pin_9
#define UART3_RX_PIN_SOURCE  GPIO_PinSource9
#define UART3_GPIO           GPIOD
#define UART3_GPIO_RCC       RCC_AHB1Periph_GPIOD
#define RCC_APBPeriph_UART3  RCC_APB1Periph_USART3

#define UART4_GPIO_TX       GPIO_Pin_0
#define UART4_TX_PIN_SOURCE GPIO_PinSource0
#define UART4_GPIO_RX       GPIO_Pin_1
#define UART4_RX_PIN_SOURCE GPIO_PinSource1
#define UART4_GPIO          GPIOA
#define UART4_GPIO_RCC      RCC_AHB1Periph_GPIOA
#define RCC_APBPeriph_UART4 RCC_APB1Periph_UART4

#define UART6_GPIO_TX       GPIO_Pin_6
#define UART6_TX_PIN_SOURCE GPIO_PinSource6
#define UART6_GPIO_RX       GPIO_Pin_7
#define UART6_RX_PIN_SOURCE GPIO_PinSource7
#define UART6_GPIO          GPIOC
#define UART6_GPIO_RCC      RCC_AHB1Periph_GPIOC
#define RCC_APBPeriph_UART6 RCC_APB2Periph_USART6

#define UART7_GPIO_TX       GPIO_Pin_8
#define UART7_TX_PIN_SOURCE GPIO_PinSource8
#define UART7_GPIO_RX       GPIO_Pin_7
#define UART7_RX_PIN_SOURCE GPIO_PinSource7
#define UART7_GPIO          GPIOE
#define UART7_GPIO_RCC      RCC_AHB1Periph_GPIOE
#define RCC_APBPeriph_UART7 RCC_APB1Periph_UART7

#define UART8_GPIO_TX       GPIO_Pin_1
#define UART8_TX_PIN_SOURCE GPIO_PinSource1
#define UART8_GPIO_RX       GPIO_Pin_0
#define UART8_RX_PIN_SOURCE GPIO_PinSource0
#define UART8_GPIO          GPIOE
#define UART8_GPIO_RCC      RCC_AHB1Periph_GPIOE
#define RCC_APBPeriph_UART8 RCC_APB1Periph_UART8

/* config for serial_configure structure */
#define SERIAL2_DEFAULT_CONFIG                    \
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

#define SERIAL3_DEFAULT_CONFIG                    \
    {                                             \
        BAUD_RATE_115200,    /* 115200 bits/s */  \
            DATA_BITS_8,     /* 8 databits */     \
            STOP_BITS_1,     /* 1 stopbit */      \
            PARITY_NONE,     /* No parity  */     \
            BIT_ORDER_LSB,   /* LSB first sent */ \
            NRZ_NORMAL,      /* Normal mode */    \
            SERIAL_RB_BUFSZ, /* Buffer size */    \
            0                                     \
    }

#define SERIAL4_DEFAULT_CONFIG                    \
    {                                             \
        BAUD_RATE_115200,    /* 115200 bits/s */  \
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
        /* rx dma stream */
        DMA_Stream_TypeDef* rx_stream;
        /* dma channel */
        uint32_t rx_ch;
        /* dma flag */
        uint32_t rx_flag;
        /* dma irq channel */
        uint8_t rx_irq_ch;
        /* setting receive len */
        rt_size_t setting_recv_len;
        /* last receive index */
        rt_size_t last_recv_index;
        /* tx dma stream */
        DMA_Stream_TypeDef* tx_stream;
        /* dma channel */
        uint32_t tx_ch;
        /* dma flag */
        uint32_t tx_flag;
        /* dma irq channel */
        uint8_t tx_irq_ch;
    } dma;
};

static rt_size_t usart_dma_transmit(struct serial_device* serial, rt_uint8_t* buf, rt_size_t size, int direction);
static int usart_getc(struct serial_device* serial);
static int usart_putc(struct serial_device* serial, char c);
static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg);
static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg);

static struct serial_device serial0; // CONSOLE
static struct serial_device serial1; // MAVPROXY
static struct serial_device serial2; // GPS
static struct serial_device serial3; // SERIAL4
static struct serial_device serial4; // SERIAL5
static struct serial_device serial5; // FMTIO
// static struct serial_device serial6;

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

    /* disable interrupt */
    level = rt_hw_interrupt_disable();

    recv_total_index = uart->dma.setting_recv_len - DMA_GetCurrDataCounter(uart->dma.rx_stream);
    recv_len = recv_total_index - uart->dma.last_recv_index;
    uart->dma.last_recv_index = recv_total_index;
    /* enable interrupt */
    rt_hw_interrupt_enable(level);

    if (recv_len)
        hal_serial_isr(serial, SERIAL_EVENT_RX_DMADONE | (recv_len << 8));
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

    if (DMA_GetFlagStatus(uart->dma.rx_stream, uart->dma.rx_flag) != RESET) {
        /* disable interrupt */
        level = rt_hw_interrupt_disable();

        recv_len = uart->dma.setting_recv_len - uart->dma.last_recv_index;
        /* reset last recv index */
        uart->dma.last_recv_index = 0;
        /* enable interrupt */
        rt_hw_interrupt_enable(level);

        if (recv_len)
            hal_serial_isr(serial, SERIAL_EVENT_RX_DMADONE | (recv_len << 8));

        /* start receive data */
        DMA_ClearFlag(uart->dma.rx_stream, uart->dma.rx_flag);
    }
}

/**
 * DMA receive done process. This need add to DMA receive done ISR.
 *
 * @param serial serial device
 */
static void dma_tx_done_isr(struct serial_device* serial)
{
    struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;

    if (DMA_GetFlagStatus(uart->dma.tx_stream, uart->dma.tx_flag) != RESET) {
        hal_serial_isr(serial, SERIAL_EVENT_TX_DMADONE);

        /* start receive data */
        DMA_ClearFlag(uart->dma.tx_stream, uart->dma.tx_flag);
    }
}

/**
 * Uart common interrupt process. This need add to uart ISR.
 *
 * @param serial serial device
 */
static void uart_isr(struct serial_device* serial)
{
    struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;

    if (USART_GetITStatus(uart->uart_device, USART_IT_RXNE) != RESET) {
        hal_serial_isr(serial, SERIAL_EVENT_RX_IND);
        /* clear interrupt */
        USART_ClearITPendingBit(uart->uart_device, USART_IT_RXNE);
    }

    if (USART_GetITStatus(uart->uart_device, USART_IT_IDLE) != RESET) {
        if ((uart->uart_device->CR3 & USART_CR3_DMAR)) {
            dma_uart_rx_idle_isr(serial);
        }
        /* read a data for clear receive idle interrupt flag */
        USART_ReceiveData(uart->uart_device);
    }

    if (USART_GetITStatus(uart->uart_device, USART_IT_TC) != RESET) {
        /* clear interrupt */
        USART_ClearITPendingBit(uart->uart_device, USART_IT_TC);
    }

    if (USART_GetFlagStatus(uart->uart_device, USART_FLAG_ORE) == SET) {
        usart_getc(serial);
    }
}

#ifdef USING_UART1
/* UART1 device driver structure */
struct stm32_uart uart1 = {
    USART1,
    USART1_IRQn,
    {
        DMA2_Stream5,
        DMA_Channel_4,
        DMA_FLAG_TCIF5,
        DMA2_Stream5_IRQn,
        0,
        0,
        DMA2_Stream7,
        DMA_Channel_4,
        DMA_FLAG_TCIF7,
        DMA2_Stream7_IRQn,
    },
};

void USART1_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    uart_isr(&serial6);

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA2_Stream5_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    dma_rx_done_isr(&serial6);

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA2_Stream7_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    dma_tx_done_isr(&serial6);

    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART1

#ifdef USING_UART2
/* UART2 device driver structure */
struct stm32_uart uart2 = {
    USART2,
    USART2_IRQn,
    {
        DMA1_Stream5,
        DMA_Channel_4,
        DMA_FLAG_TCIF5,
        DMA1_Stream5_IRQn,
        0,
        0,
        DMA1_Stream6,
        DMA_Channel_4,
        DMA_FLAG_TCIF6,
        DMA1_Stream6_IRQn,
    },
};

void USART2_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    uart_isr(&serial1);

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA1_Stream5_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    dma_rx_done_isr(&serial1);

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA1_Stream6_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    dma_tx_done_isr(&serial1);

    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART2

#ifdef USING_UART3
/* UART3 device driver structure */
struct stm32_uart uart3 = {
    USART3,
    USART3_IRQn,
    {
        DMA1_Stream1,
        DMA_Channel_4,
        DMA_FLAG_TCIF1,
        DMA1_Stream1_IRQn,
        0,
        0,
        DMA1_Stream3,
        DMA_Channel_4,
        DMA_FLAG_TCIF3,
        DMA1_Stream3_IRQn,
    },
};

void USART3_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    uart_isr(&serial0);

    /* leave interrupt */
    rt_interrupt_leave();
}

/* uart3 and uart7 share the same DMA stream. disable DMA on usart3 and enable DMA for uart7 */
// void DMA1_Stream1_IRQHandler(void)
// {
// 	/* enter interrupt */
// 	rt_interrupt_enter();

// 	dma_rx_done_isr(&serial0);

// 	/* leave interrupt */
// 	rt_interrupt_leave();
// }

// void DMA1_Stream3_IRQHandler(void)
// {
// 	/* enter interrupt */
// 	rt_interrupt_enter();

// 	dma_tx_done_isr(&serial0);

// 	/* leave interrupt */
// 	rt_interrupt_leave();
// }
#endif // USING_UART3

#ifdef USING_UART4
/* UART4 device driver structure */
struct stm32_uart uart4 = {
    UART4,
    UART4_IRQn,
    {
        DMA1_Stream2,
        DMA_Channel_4,
        DMA_FLAG_TCIF2,
        DMA1_Stream2_IRQn,
        0,
        0,
        DMA1_Stream4,
        DMA_Channel_4,
        DMA_FLAG_TCIF4,
        DMA1_Stream4_IRQn,
    },
};

void UART4_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    uart_isr(&serial2);

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA1_Stream2_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    dma_rx_done_isr(&serial2);

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA1_Stream4_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    dma_tx_done_isr(&serial2);

    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART4

#ifdef USING_UART6
/* UART6 device driver structure */
struct stm32_uart uart6 = {
    USART6,
    USART6_IRQn,
    {
        DMA2_Stream1,
        DMA_Channel_5,
        DMA_FLAG_TCIF1,
        DMA2_Stream1_IRQn,
        0,
        0,
        DMA2_Stream6,
        DMA_Channel_5,
        DMA_FLAG_TCIF6,
        DMA2_Stream6_IRQn,
    },
};

void USART6_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    uart_isr(&serial5);

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA2_Stream1_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    dma_rx_done_isr(&serial5);

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA2_Stream6_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    dma_tx_done_isr(&serial5);

    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART6

#ifdef USING_UART7
/* UART7 device driver structure */
struct stm32_uart uart7 = {
    UART7,
    UART7_IRQn,
    {
        DMA1_Stream3,
        DMA_Channel_5,
        DMA_FLAG_TCIF3,
        DMA1_Stream3_IRQn,
        0,
        0,
        DMA1_Stream1,
        DMA_Channel_5,
        DMA_FLAG_TCIF1,
        DMA1_Stream1_IRQn,
    },
};

void UART7_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    uart_isr(&serial4);

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA1_Stream3_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    dma_rx_done_isr(&serial4);

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA1_Stream1_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    dma_tx_done_isr(&serial4);

    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART7

#ifdef USING_UART8
/* UART8 device driver structure */
struct stm32_uart uart8 = {
    UART8,
    UART8_IRQn,
    {
        DMA1_Stream6,
        DMA_Channel_5,
        DMA_FLAG_TCIF6,
        DMA1_Stream6_IRQn,
        0,
        0,
        DMA1_Stream0,
        DMA_Channel_5,
        DMA_FLAG_TCIF0,
        DMA1_Stream0_IRQn,
    },
};

void UART8_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    uart_isr(&serial3);

    /* leave interrupt */
    rt_interrupt_leave();
}

// void DMA1_Stream6_IRQHandler(void)
// {
//     /* enter interrupt */
//     rt_interrupt_enter();

//     dma_rx_done_isr(&serial3);

//     /* leave interrupt */
//     rt_interrupt_leave();
// }

// void DMA1_Stream0_IRQHandler(void)
// {
//     /* enter interrupt */
//     rt_interrupt_enter();

//     dma_tx_done_isr(&serial3);

//     /* leave interrupt */
//     rt_interrupt_leave();
// }
#endif // USING_UART8

static void RCC_Configuration(void)
{
#ifdef USING_UART1
    /* Enable UART1 GPIO clocks */
    RCC_AHB1PeriphClockCmd(UART1_GPIO_RCC, ENABLE);
    /* Enable UART1 clock */
    RCC_APB2PeriphClockCmd(RCC_APBPeriph_UART1, ENABLE);
#endif /* USING_UART1 */

#ifdef USING_UART2
    /* Enable UART2 GPIO clocks */
    RCC_AHB1PeriphClockCmd(UART2_GPIO_RCC, ENABLE);
    /* Enable UART2 clock */
    RCC_APB1PeriphClockCmd(RCC_APBPeriph_UART2, ENABLE);
#endif /* USING_UART1 */

#ifdef USING_UART3
    /* Enable UART3 GPIO clocks */
    RCC_AHB1PeriphClockCmd(UART3_GPIO_RCC, ENABLE);
    /* Enable UART3 clock */
    RCC_APB1PeriphClockCmd(RCC_APBPeriph_UART3, ENABLE);
#endif /* USING_UART3 */

#ifdef USING_UART4
    /* Enable UART4 GPIO clocks */
    RCC_AHB1PeriphClockCmd(UART4_GPIO_RCC, ENABLE);
    /* Enable UART4 clock */
    RCC_APB1PeriphClockCmd(RCC_APBPeriph_UART4, ENABLE);
#endif /* USING_UART4 */

#ifdef USING_UART6
    /* Enable UART6 GPIO clocks */
    RCC_AHB1PeriphClockCmd(UART6_GPIO_RCC, ENABLE);
    /* Enable UART6 clock */
    RCC_APB2PeriphClockCmd(RCC_APBPeriph_UART6, ENABLE);
#endif /* USING_UART6 */

#ifdef USING_UART7
    /* Enable UART7 GPIO clocks */
    RCC_AHB1PeriphClockCmd(UART7_GPIO_RCC, ENABLE);
    /* Enable UART7 clock */
    RCC_APB1PeriphClockCmd(RCC_APBPeriph_UART7, ENABLE);
#endif /* USING_UART7 */

#ifdef USING_UART8
    /* Enable UART8 GPIO clocks */
    RCC_AHB1PeriphClockCmd(UART8_GPIO_RCC, ENABLE);
    /* Enable UART8 clock */
    RCC_APB1PeriphClockCmd(RCC_APBPeriph_UART8, ENABLE);
#endif /* USING_UART8 */

    /* DMA clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
}

static void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

#ifdef USING_UART1
    /* Configure USART1 Rx/tx PIN */
    GPIO_InitStructure.GPIO_Pin = UART1_GPIO_RX | UART1_GPIO_TX;
    GPIO_Init(UART1_GPIO, &GPIO_InitStructure);

    /* Connect alternate function */
    GPIO_PinAFConfig(UART1_GPIO, UART1_TX_PIN_SOURCE, GPIO_AF_USART1);
    GPIO_PinAFConfig(UART1_GPIO, UART1_RX_PIN_SOURCE, GPIO_AF_USART1);
#endif /* USING_UART1 */

#ifdef USING_UART2
    /* Configure USART2 Rx/tx PIN */
    GPIO_InitStructure.GPIO_Pin = UART2_GPIO_RX | UART2_GPIO_TX;
    GPIO_Init(UART2_GPIO, &GPIO_InitStructure);

    /* Connect alternate function */
    GPIO_PinAFConfig(UART2_GPIO, UART2_TX_PIN_SOURCE, GPIO_AF_USART2);
    GPIO_PinAFConfig(UART2_GPIO, UART2_RX_PIN_SOURCE, GPIO_AF_USART2);
#endif /* USING_UART2 */

#ifdef USING_UART3
    /* Configure USART3 Rx/tx PIN */
    GPIO_InitStructure.GPIO_Pin = UART3_GPIO_TX | UART3_GPIO_RX;
    GPIO_Init(UART3_GPIO, &GPIO_InitStructure);

    /* Connect alternate function */
    GPIO_PinAFConfig(UART3_GPIO, UART3_TX_PIN_SOURCE, GPIO_AF_USART3);
    GPIO_PinAFConfig(UART3_GPIO, UART3_RX_PIN_SOURCE, GPIO_AF_USART3);
#endif /* USING_UART3 */

#ifdef USING_UART4
    /* Configure USART4 Rx/tx PIN */
    GPIO_InitStructure.GPIO_Pin = UART4_GPIO_TX | UART4_GPIO_RX;
    GPIO_Init(UART4_GPIO, &GPIO_InitStructure);

    /* Connect alternate function */
    GPIO_PinAFConfig(UART4_GPIO, UART4_TX_PIN_SOURCE, GPIO_AF_UART4);
    GPIO_PinAFConfig(UART4_GPIO, UART4_RX_PIN_SOURCE, GPIO_AF_UART4);
#endif /* USING_UART4 */

#ifdef USING_UART6
    /* Configure USART6 Rx/tx PIN */
    GPIO_InitStructure.GPIO_Pin = UART6_GPIO_RX | UART6_GPIO_TX;
    GPIO_Init(UART6_GPIO, &GPIO_InitStructure);

    /* Connect alternate function */
    GPIO_PinAFConfig(UART6_GPIO, UART6_TX_PIN_SOURCE, GPIO_AF_USART6);
    GPIO_PinAFConfig(UART6_GPIO, UART6_RX_PIN_SOURCE, GPIO_AF_USART6);
#endif /* USING_UART6 */

#ifdef USING_UART7
    /* Configure USART7 Rx/tx PIN */
    GPIO_InitStructure.GPIO_Pin = UART7_GPIO_RX | UART7_GPIO_TX;
    GPIO_Init(UART7_GPIO, &GPIO_InitStructure);

    /* Connect alternate function */
    GPIO_PinAFConfig(UART7_GPIO, UART7_TX_PIN_SOURCE, GPIO_AF_UART7);
    GPIO_PinAFConfig(UART7_GPIO, UART7_RX_PIN_SOURCE, GPIO_AF_UART7);
#endif /* USING_UART7 */

#ifdef USING_UART8
    /* Configure USART8 Rx/tx PIN */
    GPIO_InitStructure.GPIO_Pin = UART8_GPIO_RX | UART8_GPIO_TX;
    GPIO_Init(UART8_GPIO, &GPIO_InitStructure);

    /* Connect alternate function */
    GPIO_PinAFConfig(UART8_GPIO, UART8_TX_PIN_SOURCE, GPIO_AF_UART8);
    GPIO_PinAFConfig(UART8_GPIO, UART8_RX_PIN_SOURCE, GPIO_AF_UART8);
#endif /* USING_UART8 */
}

static void NVIC_Configuration(struct stm32_uart* uart)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    /* Enable the USART1 Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = uart->irq;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void _dma_rx_config(struct serial_device* serial, rt_uint8_t* buf, rt_size_t size)
{
    struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;
    DMA_InitTypeDef DMA_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    /* rx dma interrupt config */
    NVIC_InitStructure.NVIC_IRQChannel = uart->dma.rx_irq_ch;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /* rx dma config */
    uart->dma.setting_recv_len = size;
    DMA_DeInit(uart->dma.rx_stream);

    while (DMA_GetCmdStatus(uart->dma.rx_stream) != DISABLE)
        ;

    DMA_InitStructure.DMA_Channel = uart->dma.rx_ch;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t) & (uart->uart_device->DR);
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)buf;
    DMA_InitStructure.DMA_BufferSize = uart->dma.setting_recv_len;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular; /* since we are using circular buffer */
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

    DMA_Init(uart->dma.rx_stream, &DMA_InitStructure);

    DMA_ClearFlag(uart->dma.rx_stream, uart->dma.rx_flag);

    /* DMA IT Interrupt will be trigger if DMA_InitStructure.DMA_BufferSize bytes has been received */
    DMA_ITConfig(uart->dma.rx_stream, DMA_IT_TC, ENABLE);

    /* We will also reveice data in usart idle irq */
    USART_ITConfig(uart->uart_device, USART_IT_IDLE, ENABLE);

    USART_DMACmd(uart->uart_device, USART_DMAReq_Rx, ENABLE);

    DMA_Cmd(uart->dma.rx_stream, ENABLE);
}

static void _dma_tx_config(struct serial_device* serial)
{
    struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;
    NVIC_InitTypeDef NVIC_InitStructure;

    /* tx dma interrupt config */
    NVIC_InitStructure.NVIC_IRQChannel = uart->dma.tx_irq_ch;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void _dma_transmit(struct serial_device* serial, rt_uint8_t* buf, rt_size_t size)
{
    struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;
    DMA_InitTypeDef DMA_InitStructure;

    /* tx dma config */
    DMA_DeInit(uart->dma.tx_stream);

    while (DMA_GetCmdStatus(uart->dma.tx_stream) != DISABLE)
        ;

    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)buf;
    DMA_InitStructure.DMA_BufferSize = size;
    DMA_InitStructure.DMA_Channel = uart->dma.tx_ch;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t) & (uart->uart_device->DR);
    DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    DMA_Init(uart->dma.tx_stream, &DMA_InitStructure);

    DMA_ClearFlag(uart->dma.tx_stream, uart->dma.tx_flag);

    DMA_ITConfig(uart->dma.tx_stream, DMA_IT_TC, ENABLE);

    USART_DMACmd(uart->uart_device, USART_DMAReq_Tx, ENABLE);

    DMA_Cmd(uart->dma.tx_stream, ENABLE);
}

static void _close_usart(struct serial_device* serial)
{
    struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;

    if (serial->parent.open_flag & RT_DEVICE_FLAG_INT_RX) {
        /* disable rx irq */
        //UART_DISABLE_IRQ(uart->irq);	/* we don't disable rx irq, since dma rx need it */
        /* disable interrupt */
        USART_ITConfig(uart->uart_device, USART_IT_RXNE, DISABLE);
    }

    if (serial->parent.open_flag & RT_DEVICE_FLAG_DMA_RX) {
        DMA_ClearFlag(uart->dma.rx_stream, uart->dma.rx_flag);
        DMA_ITConfig(uart->dma.rx_stream, DMA_IT_TC, DISABLE);
        USART_ITConfig(uart->uart_device, USART_IT_IDLE, DISABLE);
        USART_DMACmd(uart->uart_device, USART_DMAReq_Rx, DISABLE);
        DMA_Cmd(uart->dma.rx_stream, DISABLE);
    }

    if (serial->parent.open_flag & RT_DEVICE_FLAG_DMA_TX) {
        DMA_ClearFlag(uart->dma.tx_stream, uart->dma.tx_flag);
        DMA_ITConfig(uart->dma.tx_stream, DMA_IT_TC, DISABLE);
        USART_DMACmd(uart->uart_device, USART_DMAReq_Tx, DISABLE);
        DMA_Cmd(uart->dma.tx_stream, DISABLE);
    }

    /* reset last recv index */
    uart->dma.last_recv_index = 0;
}

static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg)
{
    struct stm32_uart* uart;
    USART_InitTypeDef USART_InitStructure;

    RT_ASSERT(serial != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    uart = (struct stm32_uart*)serial->parent.user_data;

    USART_InitStructure.USART_BaudRate = cfg->baud_rate;

    if (cfg->data_bits == DATA_BITS_8) {
        USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    } else if (cfg->data_bits == DATA_BITS_9) {
        USART_InitStructure.USART_WordLength = USART_WordLength_9b;
    }

    if (cfg->stop_bits == STOP_BITS_1) {
        USART_InitStructure.USART_StopBits = USART_StopBits_1;
    } else if (cfg->stop_bits == STOP_BITS_2) {
        USART_InitStructure.USART_StopBits = USART_StopBits_2;
    }

    if (cfg->parity == PARITY_NONE) {
        USART_InitStructure.USART_Parity = USART_Parity_No;
    } else if (cfg->parity == PARITY_ODD) {
        USART_InitStructure.USART_Parity = USART_Parity_Odd;
    } else if (cfg->parity == PARITY_EVEN) {
        USART_InitStructure.USART_Parity = USART_Parity_Even;
    }

    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    /* Disable USART before configuration */
    USART_Cmd(uart->uart_device, DISABLE);
    USART_Init(uart->uart_device, &USART_InitStructure);
    /* Enable USART */
    USART_Cmd(uart->uart_device, ENABLE);

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
            UART_DISABLE_IRQ(uart->irq);
            /* disable interrupt */
            USART_ITConfig(uart->uart_device, USART_IT_RXNE, DISABLE);
        }

        break;

    case RT_DEVICE_CTRL_SET_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {
            /* enable rx irq */
            UART_ENABLE_IRQ(uart->irq);
            /* enable interrupt */
            USART_ITConfig(uart->uart_device, USART_IT_RXNE, ENABLE);
        }

        break;

    /* USART DMA config */
    case RT_DEVICE_CTRL_CONFIG: {
        if (ctrl_arg == RT_DEVICE_FLAG_DMA_RX) {
            struct serial_rx_fifo* rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;

            _dma_rx_config(serial, rx_fifo->buffer, serial->config.bufsz);
        }

        if (ctrl_arg == RT_DEVICE_FLAG_DMA_TX) {
            _dma_tx_config(serial);
        }
    } break;

    /* close device */
    case RT_DEVICE_CTRL_SUSPEND: {
        _close_usart(serial);
    }
    }

    return RT_EOK;
}

static int usart_putc(struct serial_device* serial, char c)
{
    struct stm32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct stm32_uart*)serial->parent.user_data;

    /* wait transmit register become empty */
    while (!(uart->uart_device->SR & USART_FLAG_TXE))
        ;

    uart->uart_device->DR = c;

    return 1;
}

static int usart_getc(struct serial_device* serial)
{
    int ch = -1;
    struct stm32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct stm32_uart*)serial->parent.user_data;

    /* check if read data register is not empty */
    if (uart->uart_device->SR & USART_FLAG_RXNE) {
        /* read DR will clear RXNE */
        ch = uart->uart_device->DR & 0xff;
    }

    return ch;
}

static rt_size_t usart_dma_transmit(struct serial_device* serial, rt_uint8_t* buf, rt_size_t size, int direction)
{
    if (direction == SERIAL_DMA_TX) {

        _dma_transmit(serial, buf, size);

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
    rt_uint32_t flag = RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX;

    RCC_Configuration();
    GPIO_Configuration();

#ifdef USING_UART1
    serial6.ops = &_usart_ops;
    #ifdef SERIAL6_DEFAULT_CONFIG
    struct serial_configure serial6_config = SERIAL6_DEFAULT_CONFIG;
    serial6.config = serial6_config;
    #else
    serial6.config = config;
    #endif

    NVIC_Configuration(&uart1);

    /* register UART1 device */
    rt_err |= hal_serial_register(&serial6,
                                  "serial6",
                                  flag,
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

    /* register UART1 device */
    rt_err |= hal_serial_register(&serial1,
                                  "serial1",
                                  flag,
                                  &uart2);
#endif /* USING_UART2 */

#ifdef USING_UART3
    serial0.ops = &_usart_ops;
    #ifdef SERIAL0_DEFAULT_CONFIG
    struct serial_configure serial0_config = SERIAL0_DEFAULT_CONFIG;
    serial0.config = serial0_config;
    #else
    serial0.config = config;
    #endif

    NVIC_Configuration(&uart3);

    /* register UART3 device */
    rt_err |= hal_serial_register(&serial0,
                                  "serial0",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart3);
#endif /* USING_UART3 */

#ifdef USING_UART4
    serial2.ops = &_usart_ops;
    #ifdef SERIAL2_DEFAULT_CONFIG
    struct serial_configure serial2_config = SERIAL2_DEFAULT_CONFIG;
    serial2.config = serial2_config;
    #else
    serial2.config = config;
    #endif

    NVIC_Configuration(&uart4);

    /* register UART4 device */
    rt_err |= hal_serial_register(&serial2,
                                  "serial2",
                                  flag,
                                  &uart4);
#endif /* USING_UART4 */

#ifdef USING_UART6
    serial5.ops = &_usart_ops;
    #ifdef SERIAL5_DEFAULT_CONFIG
    struct serial_configure serial5_config = SERIAL5_DEFAULT_CONFIG;
    serial5.config = serial5_config;
    #else
    serial5.config = config;
    #endif

    NVIC_Configuration(&uart6);

    /* register UART6 device */
    rt_err |= hal_serial_register(&serial5,
                                  "serial5",
                                  flag,
                                  &uart6);
#endif /* USING_UART6 */

#ifdef USING_UART7
    serial4.ops = &_usart_ops;
    #ifdef SERIAL4_DEFAULT_CONFIG
    struct serial_configure serial4_config = SERIAL4_DEFAULT_CONFIG;
    serial4.config = serial4_config;
    #else
    serial4.config = config;
    #endif

    NVIC_Configuration(&uart7);

    /* register UART6 device */
    rt_err |= hal_serial_register(&serial4,
                                  "serial4",
                                  flag,
                                  &uart7);
#endif /* USING_UART7 */

#ifdef USING_UART8
    serial3.ops = &_usart_ops;
    #ifdef SERIAL3_DEFAULT_CONFIG
    struct serial_configure serial3_config = SERIAL3_DEFAULT_CONFIG;
    serial3.config = serial3_config;
    #else
    serial3.config = config;
    #endif

    NVIC_Configuration(&uart8);

    /* register UART6 device */
    rt_err |= hal_serial_register(&serial3,
                                  "serial3",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart8);
#endif /* USING_UART8 */

    return rt_err;
}
// INIT_BOARD_EXPORT(usart_drv_init);
