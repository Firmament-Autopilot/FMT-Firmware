/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2013-03-30     Bernard      the first verion
 */
/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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

#define UART_DR(base)   __REG32(base + 0x00)
#define UART_FR(base)   __REG32(base + 0x18)
#define UART_CR(base)   __REG32(base + 0x30)
#define UART_IMSC(base) __REG32(base + 0x38)
#define UART_ICR(base)  __REG32(base + 0x44)

#define UARTFR_RXFE   0x10
#define UARTFR_TXFF   0x20
#define UARTIMSC_RXIM 0x10
#define UARTIMSC_TXIM 0x20
#define UARTICR_RXIC  0x10
#define UARTICR_TXIC  0x20

struct hw_uart_device {
    rt_uint32_t hw_base;
    rt_uint32_t irqno;
};

static int usart_getc(struct serial_device* serial);
static int usart_putc(struct serial_device* serial, char c);
static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg);
static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg);

static struct serial_device serial0;
static struct serial_device serial1;
static struct serial_device serial2;

#define USING_UART0
#define USING_UART1
#define USING_UART2

#ifdef USING_UART0
/* UART device driver structure */
static struct hw_uart_device _uart0_device = {
    REALVIEW_UART0_BASE,
    IRQ_PBA8_UART0,
};
#endif

#ifdef USING_UART1
/* UART1 device driver structure */
static struct hw_uart_device _uart1_device = {
    REALVIEW_UART1_BASE,
    IRQ_PBA8_UART1,
};
#endif

#ifdef USING_UART2
/* UART2 device driver structure */
static struct hw_uart_device _uart2_device = {
    REALVIEW_UART2_BASE,
    IRQ_PBA8_UART2,
};
#endif

/**
 * Uart common interrupt process. This need add to uart ISR.
 *
 * @param serial serial device
 */
static void uart_isr(struct serial_device* serial, int event)
{
    switch (event & 0xff) {
    case SERIAL_EVENT_RX_IND:
        /* high-level ISR routine */
        hal_serial_isr(serial, SERIAL_EVENT_RX_IND);
        break;
    }
}

static void rt_hw_uart_isr(int irqno, void* param)
{
    struct serial_device* serial = (struct serial_device*)param;

    uart_isr(serial, SERIAL_EVENT_RX_IND);
}

static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg)
{
    return RT_EOK;
}

static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg)
{
    struct hw_uart_device* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct hw_uart_device*)serial->parent.user_data;

    switch (cmd) {
    case RT_DEVICE_CTRL_CLR_INT:
        /* disable rx irq */
        UART_IMSC(uart->hw_base) &= ~UARTIMSC_RXIM;
        break;

    case RT_DEVICE_CTRL_SET_INT:
        /* enable rx irq */
        UART_IMSC(uart->hw_base) |= UARTIMSC_RXIM;
        rt_hw_interrupt_umask(uart->irqno);
        break;
    }

    return RT_EOK;
}

static int usart_putc(struct serial_device* serial, char c)
{
    struct hw_uart_device* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct hw_uart_device*)serial->parent.user_data;

    while (UART_FR(uart->hw_base) & UARTFR_TXFF)
        ;
    UART_DR(uart->hw_base) = c;

    return 1;
}

static int usart_getc(struct serial_device* serial)
{
    int ch = -1;
    struct hw_uart_device* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct hw_uart_device*)serial->parent.user_data;

    if (!(UART_FR(uart->hw_base) & UARTFR_RXFE)) {
        ch = UART_DR(uart->hw_base) & 0xff;
    }

    return ch;
}

/* usart driver operations */
static const struct usart_ops _usart_ops = {
    usart_configure,
    usart_control,
    usart_putc,
    usart_getc,
    NULL
};

#define SERIAL1_DEFAULT_CONFIG                    \
    {                                             \
        BAUD_RATE_921600,    /* 57600 bits/s */   \
            DATA_BITS_8,     /* 8 databits */     \
            STOP_BITS_1,     /* 1 stopbit */      \
            PARITY_NONE,     /* No parity  */     \
            BIT_ORDER_LSB,   /* LSB first sent */ \
            NRZ_NORMAL,      /* Normal mode */    \
            SERIAL_RB_BUFSZ, /* Buffer size */    \
            0                                     \
    }

#define SERIAL2_DEFAULT_CONFIG                    \
    {                                             \
        BAUD_RATE_115200,    /* 57600 bits/s */   \
            DATA_BITS_8,     /* 8 databits */     \
            STOP_BITS_1,     /* 1 stopbit */      \
            PARITY_NONE,     /* No parity  */     \
            BIT_ORDER_LSB,   /* LSB first sent */ \
            NRZ_NORMAL,      /* Normal mode */    \
            SERIAL_RB_BUFSZ, /* Buffer size */    \
            0                                     \
    }

rt_err_t drv_usart_init(void)
{
    rt_err_t rt_err = RT_EOK;
    struct serial_configure config = SERIAL_DEFAULT_CONFIG;

#ifdef USING_UART0
    serial0.ops = &_usart_ops;
    #ifdef SERIAL0_DEFAULT_CONFIG
    struct serial_configure serial0_config = SERIAL0_DEFAULT_CONFIG;
    serial0.config = serial0_config;
    #else
    serial0.config = config;
    #endif

    /* register serial device */
    rt_err |= hal_serial_register(&serial0,
                                  "serial0",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &_uart0_device);

    rt_hw_interrupt_install(_uart0_device.irqno, rt_hw_uart_isr, &serial0, "uart0");
    /* enable Rx and Tx of UART */
    UART_CR(_uart0_device.hw_base) = (1 << 0) | (1 << 8) | (1 << 9);
#endif /* USING_UART1 */

#ifdef USING_UART1
    serial1.ops = &_usart_ops;
    #ifdef SERIAL1_DEFAULT_CONFIG
    struct serial_configure serial1_config = SERIAL1_DEFAULT_CONFIG;
    serial1.config = serial1_config;
    #else
    serial1.config = config;
    #endif

    /* register serial device */
    rt_err |= hal_serial_register(&serial1,
                                  "serial1",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &_uart1_device);

    rt_hw_interrupt_install(_uart1_device.irqno, rt_hw_uart_isr, &serial1, "uart1");
    /* enable Rx and Tx of UART */
    UART_CR(_uart1_device.hw_base) = (1 << 0) | (1 << 8) | (1 << 9);
#endif /* USING_UART1 */

#ifdef USING_UART2
    serial2.ops = &_usart_ops;
    #ifdef SERIAL2_DEFAULT_CONFIG
    struct serial_configure serial2_config = SERIAL2_DEFAULT_CONFIG;
    serial2.config = serial2_config;
    #else
    serial2.config = config;
    #endif

    /* register serial device */
    rt_err |= hal_serial_register(&serial2,
                                  "serial2",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &_uart2_device);

    rt_hw_interrupt_install(_uart2_device.irqno, rt_hw_uart_isr, &serial2, "uart2");
    /* enable Rx and Tx of UART */
    UART_CR(_uart2_device.hw_base) = (1 << 0) | (1 << 8) | (1 << 9);
#endif /* USING_UART2 */

    return rt_err;
}
