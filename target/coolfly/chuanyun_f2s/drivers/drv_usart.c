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

#include "ar1002_hal.h"
#include "serial.h"

#include <firmament.h>

struct up_dev_s {
    uint32_t uartbase;  /* Base address of UART registers */
    uint32_t baud;      /* Configured baud */
    uint32_t ier;       /* Saved IER value */
    uint8_t  irq;       /* IRQ associated with this UART */
    uint8_t  parity;    /* 0=none, 1=odd, 2=even */
    uint8_t  bits;      /* Number of bits (7 or 8) */
    bool     stopbits2; /* true: Configure with 2 stop bits instead of 1 */
};

typedef struct
{
    __IO uint32_t LISR;  /*!< DMA low interrupt status register,      Address offset: 0x00 */
    __IO uint32_t HISR;  /*!< DMA high interrupt status register,     Address offset: 0x04 */
    __IO uint32_t LIFCR; /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
    __IO uint32_t HIFCR; /*!< DMA high interrupt flag clear register, Address offset: 0x0C */
} DMA_TypeDef;

struct ar_uart {
    struct up_dev_s uart_device;
    IRQn_Type       irq;
    struct ar_uart_dma {
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

/* Default config for serial_configure structure */
#define SERIAL0_DEFAULT_CONFIG                    \
    {                                             \
        BAUD_RATE_460800,    /* 57600 bits/s */   \
            DATA_BITS_8,     /* 8 databits */     \
            STOP_BITS_1,     /* 1 stopbit */      \
            PARITY_NONE,     /* No parity  */     \
            BIT_ORDER_LSB,   /* LSB first sent */ \
            NRZ_NORMAL,      /* Normal mode */    \
            SERIAL_RB_BUFSZ, /* Buffer size */    \
            0                                     \
    }

/* Default config for serial_configure structure */
#define SERIAL1_DEFAULT_CONFIG                    \
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

/* Default config for serial_configure structure */
#define SERIAL4_DEFAULT_CONFIG                    \
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

/* Default config for serial_configure structure */
#define SERIAL5_DEFAULT_CONFIG                    \
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

/* Default config for serial_configure structure */
#define SERIAL6_DEFAULT_CONFIG                    \
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

/* Default config for serial_configure structure */
#define SERIAL7_DEFAULT_CONFIG                    \
    {                                             \
        BAUD_RATE_460800,    /* 57600 bits/s */   \
            DATA_BITS_8,     /* 8 databits */     \
            STOP_BITS_1,     /* 1 stopbit */      \
            PARITY_NONE,     /* No parity  */     \
            BIT_ORDER_LSB,   /* LSB first sent */ \
            NRZ_NORMAL,      /* Normal mode */    \
            SERIAL_RB_BUFSZ, /* Buffer size */    \
            0                                     \
    }

static int      usart_getc(struct serial_device* serial);
static int      usart_putc(struct serial_device* serial, char c);
static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg);
static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg);
static void     uart_isr(struct serial_device* serial);

// #ifdef USING_UART7
static struct serial_device serial0; // FMU Debug
static struct serial_device serial1; // GPS
static struct serial_device serial4; // dis
static struct serial_device serial5; // flow
static struct serial_device serial6; // opt
static struct serial_device serial7; // MAVLINK

/* UART0 device driver structure */
struct ar_uart uart0 = {
    .uart_device = UART0_BASE,
    .irq         = UART_INTR0_VECTOR_NUM,
    .dma         = { 0 },
};

struct ar_uart uart1 = {
    .uart_device = UART1_BASE,
    .irq         = UART_INTR1_VECTOR_NUM,
    .dma         = { 0 },
};

struct ar_uart uart4 = {
    .uart_device = UART4_BASE,
    .irq         = UART_INTR4_VECTOR_NUM,
    .dma         = { 0 },
};

struct ar_uart uart5 = {
    .uart_device = UART5_BASE,
    .irq         = UART_INTR5_VECTOR_NUM,
    .dma         = { 0 },
};

struct ar_uart uart6 = {
    .uart_device = UART6_BASE,
    .irq         = UART_INTR6_VECTOR_NUM,
    .dma         = { 0 },
};

struct ar_uart uart7 = {
    .uart_device = UART7_BASE,
    .irq         = UART_INTR7_VECTOR_NUM,
    .dma         = { 0 },
};

void UART0_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial0);
    /* leave interrupt */
    rt_interrupt_leave();
}

void UART1_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial1);
    /* leave interrupt */
    rt_interrupt_leave();
}

void UART4_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial4);
    /* leave interrupt */
    rt_interrupt_leave();
}

void UART5_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial5);
    /* leave interrupt */
    rt_interrupt_leave();
}

void UART6_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial6);
    /* leave interrupt */
    rt_interrupt_leave();
}

void UART7_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial7);
    /* leave interrupt */
    rt_interrupt_leave();
}

#define getreg32(a)    (*(volatile uint32_t*)(a))
#define putreg32(v, a) (*(volatile uint32_t*)(a) = (v))

// read
static inline uint32_t up_serialin(struct up_dev_s* priv, int offset)
{
    return getreg32(priv->uartbase + offset);
}

// write
static inline void up_serialout(struct up_dev_s* priv, int offset, uint32_t value)
{
    putreg32(value, priv->uartbase + offset);
}

static int up_setup(struct up_dev_s* dev)
{
    struct up_dev_s* priv = dev;
    uint16_t         dl;
    uint32_t         lcr;
    up_serialout(priv, AR_UART_FCR_OFFSET, (UART_FCR_RXRST | UART_FCR_TXRST));

    if (priv->uartbase == AR_UART0_BASE) {
        up_serialout(priv, AR_UART_FCR_OFFSET, (UART_FCR_FIFOEN | UART_FCR_RXTRIGGER_0));
    } else {
        up_serialout(priv, AR_UART_FCR_OFFSET, (UART_FCR_FIFOEN | UART_FCR_RXTRIGGER_14));
    }

    priv->ier = up_serialin(priv, AR_UART_IER_OFFSET);

    lcr = 0;

    // if (priv->bits == 7)
    // {
    //     lcr |= UART_LCR_DLS_7BIT;
    // }
    // else
    // {
    //     lcr |= UART_LCR_DLS_8BIT;
    // }

    lcr |= UART_LCR_DLS_8BIT;

    if (priv->stopbits2) {
        lcr |= UART_LCR_STOP;
    }

    if (priv->parity == 1) {
        lcr |= (UART_LCR_PE | UART_LCR_PS_ODD);
    } else if (priv->parity == 2) {
        lcr |= (UART_LCR_PE | UART_LCR_PS_EVEN);
    }

    /* Enter DLAB=1 */
    up_serialout(priv, AR_UART_LCR_OFFSET, (lcr | UART_LCR_DLAB));

    /* Set the BAUD divisor */
    dl = 100000000 / (16 * priv->baud);

    up_serialout(priv, AR_UART_DLH_OFFSET, dl >> 8);
    up_serialout(priv, AR_UART_DLL_OFFSET, dl & 0xff);

    up_serialout(priv, AR_UART_LCR_OFFSET, lcr);

    if (priv->uartbase == AR_UART0_BASE) {
        up_serialout(priv, AR_UART_FCR_OFFSET, (UART_FCR_RXTRIGGER_0 | UART_FCR_TXRST | UART_FCR_RXRST | UART_FCR_FIFOEN));
    } else {
        up_serialout(priv, AR_UART_FCR_OFFSET, (UART_FCR_RXTRIGGER_14 | UART_FCR_TXRST | UART_FCR_RXRST | UART_FCR_FIFOEN));
    }
    return 0;
}

// disable the all int
static inline void up_disableuartint(struct up_dev_s* priv, uint32_t* ier)
{
    if (ier) {
        *ier = priv->ier & UART_IER_ALLIE;
    }

    priv->ier &= ~UART_IER_ALLIE;
    up_serialout(priv, AR_UART_IER_OFFSET, priv->ier);
}

static void up_shutdown(struct up_dev_s* dev)
{
    struct up_dev_s* priv = dev;
    up_disableuartint(priv, NULL);
}

/****************************************************************************
 * Name: up_rxint
 *
 * Description:
 *   Call to enable or disable RX interrupts
 *
 ****************************************************************************/

static void up_rxint(struct up_dev_s* dev, bool enable)
{
    struct up_dev_s* priv = dev;
    if (enable) {
        // #ifndef CONFIG_SUPPRESS_SERIAL_INTS
        priv->ier |= UART_IER_ERBFI;
        // #endif
    } else {
        priv->ier &= ~UART_IER_ERBFI;
    }

    up_serialout(priv, AR_UART_IER_OFFSET, priv->ier);
}

static void up_send(struct up_dev_s* dev, int ch)
{
    struct up_dev_s* priv = dev;
    up_serialout(priv, AR_UART_THR_OFFSET, (uint32_t)ch);

    uint32_t value;
    do {
        value = up_serialin(priv, AR_UART_LSR_OFFSET);
    } while ((value & UART_LSR_THRE) != UART_LSR_THRE);
}

/****************************************************************************
 * Name: up_receive
 *
 * Description:
 *   Called (usually) from the interrupt level to receive one
 *   character from the UART.  Error bits associated with the
 *   receipt are provided in the return 'status'.
 *
 ****************************************************************************/

static int up_receive(struct up_dev_s* dev, uint32_t* status)
{
    struct up_dev_s* priv = dev;
    uint32_t         rbr;

    *status = up_serialin(priv, AR_UART_LSR_OFFSET);
    rbr     = up_serialin(priv, AR_UART_RBR_OFFSET);

    return rbr;
}

/////////////////////////////////////////////////////////////////////////

/**
 * Uart common interrupt process. This need add to uart ISR.
 *
 * @param serial serial device
 */
static void uart_isr(struct serial_device* serial)
{
    struct ar_uart* uart = (struct ar_uart*)serial->parent.user_data;

    uint32_t status;
    int      passes;

    for (passes = 0; passes < 256; passes++) {

        status = up_serialin(&uart->uart_device, AR_UART_IIR_OFFSET);

        if ((status & UART_IIR_INTID_MASK) == UART_IIR_INTID_NIP) //
        {
            /* Break out of the loop when there is no longer a
             * pending interrupt
             */

            break;
            // return;
        }

        /* Handle the interrupt by its interrupt ID field */
        switch (status & UART_IIR_INTID_MASK) {
        /* Handle incoming, receive bytes (with or without timeout) */
        case UART_IIR_INTID_CTI:
        case UART_IIR_INTID_RDA: {

            struct serial_rx_fifo* rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;
            if (rx_fifo != RT_NULL) {
                hal_serial_isr(serial, SERIAL_EVENT_RX_IND);
            } else {
                while (1) {
                    int ch = usart_getc(serial);

                    if (ch == -1)
                        break;
                }
            }

            break;
        }

            /* Handle outgoing, transmit bytes */

        case UART_IIR_INTID_THRE: {
            hal_serial_isr(serial, SERIAL_EVENT_TX_DONE);
            break;
        }

            /* Just clear modem status interrupts */

        case UART_IIR_INTID_MSI: {
            /* Read the modem status register (MSR) to clear */

            status = up_serialin(&uart->uart_device, AR_UART_MSR_OFFSET);
            break;
        }

            /* Just clear any line status interrupts */

        case UART_IIR_INTID_RLS: {
            /* Read the line status register (LSR) to clear */

            status = up_serialin(&uart->uart_device, AR_UART_LSR_OFFSET);
            break;
        }

        case UART_IIR_INTID_BUSY: {
            status = up_serialin(&uart->uart_device, AR_UART_USR_OFFSET);
            break;
        }

            /* There should be no other values */

        default: {
            break;
        }
        }
    }
}

static void GPIO_Configuration(void)
{
}

static void NVIC_Configuration(struct ar_uart* uart)
{
    // TODO: configure the PreemptionPriority and SubPriority

    /* enable the usart interrupt */
    NVIC_SetPriority(uart->irq, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
    NVIC_EnableIRQ(uart->irq);
}

static void _close_usart(struct serial_device* serial)
{
    struct ar_uart* uart = (struct ar_uart*)serial->parent.user_data;

    up_shutdown(&uart->uart_device);
}

static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg)
{
    struct ar_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    uart = (struct ar_uart*)serial->parent.user_data;

    uart->uart_device.baud = cfg->baud_rate;

    if (cfg->data_bits == DATA_BITS_8) {
        uart->uart_device.bits = 8;
    } else if (cfg->data_bits == DATA_BITS_9) {
        ;
    }

    if (cfg->stop_bits == STOP_BITS_1) {
        uart->uart_device.stopbits2 = 0;
    } else if (cfg->stop_bits == STOP_BITS_2) {
        uart->uart_device.stopbits2 = 1;
    }

    if (cfg->parity == PARITY_NONE) {
        uart->uart_device.parity = 0;
    } else if (cfg->parity == PARITY_ODD) {
        uart->uart_device.parity = 1;
    } else if (cfg->parity == PARITY_EVEN) {
        uart->uart_device.parity = 2;
    }

    /* USART need be disabled first in order to configure it */
    up_setup(&uart->uart_device);

    return RT_EOK;
}

static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg)
{
    struct ar_uart* uart;
    rt_uint32_t     ctrl_arg = (rt_uint32_t)(arg);

    RT_ASSERT(serial != RT_NULL);
    uart = (struct ar_uart*)serial->parent.user_data;

    switch (cmd) {
    case RT_DEVICE_CTRL_CLR_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {
            /* disable rx irq */
            NVIC_DisableIRQ(uart->irq);
            /* disable interrupt */
            up_rxint(&uart->uart_device, false);
        }
        break;

    case RT_DEVICE_CTRL_SET_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {
            /* enable rx irq */
            NVIC_EnableIRQ(uart->irq);
            /* enable interrupt */
            up_rxint(&uart->uart_device, true);
        }
        break;

    /* USART DMA config */
    case RT_DEVICE_CTRL_CONFIG:
        // AR1002 has no dma  ~LIUWEI
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
    struct ar_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct ar_uart*)serial->parent.user_data;
    up_send(&uart->uart_device, c);

    return 1;
}

static int usart_getc(struct serial_device* serial)
{
    int             ch = -1;
    struct ar_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct ar_uart*)serial->parent.user_data;

    // volatile uint32_t status = up_serialin(&uart->uart_device, AR_UART_LSR_OFFSET);

    uint32_t IIR_sta = up_serialin(&uart->uart_device, AR_UART_IIR_OFFSET);

    switch (IIR_sta & UART_IIR_INTID_MASK) {
    /* Handle incoming, receive bytes (with or without timeout) */
    case UART_IIR_INTID_CTI:
    case UART_IIR_INTID_RDA:
        ch = up_serialin(&uart->uart_device, AR_UART_RBR_OFFSET);
        break;
    default:
        break;
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

#define UART5_TX_Pin HAL_GPIO_NUM115
#define UART5_RX_Pin HAL_GPIO_NUM108

#define UART6_TX_Pin HAL_GPIO_NUM116
#define UART6_RX_Pin HAL_GPIO_NUM109

rt_err_t drv_usart_init(void)
{

    HAL_GPIO_SetMode(UART5_TX_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(UART5_RX_Pin, HAL_GPIO_PIN_MODE0);

    HAL_GPIO_SetMode(UART6_TX_Pin, HAL_GPIO_PIN_MODE0);
    HAL_GPIO_SetMode(UART6_RX_Pin, HAL_GPIO_PIN_MODE0);

    rt_err_t rt_err = RT_EOK;

    // DEBUG
    serial0.ops = &_usart_ops;

    struct serial_configure serial0_config = SERIAL0_DEFAULT_CONFIG;
    serial0.config                         = serial0_config;

    NVIC_Configuration(&uart0);

    /* register serial device */
    rt_err |= hal_serial_register(&serial0,
                                  "serial0",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart0);

    // GPS
    serial1.ops = &_usart_ops;

    struct serial_configure serial1_config = SERIAL1_DEFAULT_CONFIG;
    serial1.config                         = serial1_config;

    NVIC_Configuration(&uart1);

    /* register serial device */
    rt_err |= hal_serial_register(&serial1,
                                  "serial1",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart1);

    serial4.ops = &_usart_ops;

    struct serial_configure serial4_config = SERIAL4_DEFAULT_CONFIG;
    serial4.config                         = serial4_config;

    NVIC_Configuration(&uart4);

    /* register serial device */
    rt_err |= hal_serial_register(&serial4,
                                  "serial4",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart4);

    // flow
    serial5.ops = &_usart_ops;

    struct serial_configure serial5_config = SERIAL5_DEFAULT_CONFIG;
    serial5.config                         = serial5_config;

    NVIC_Configuration(&uart5);

    /* register serial device */
    rt_err |= hal_serial_register(&serial5,
                                  "serial5",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart5);

    //
    serial6.ops = &_usart_ops;

    struct serial_configure serial6_config = SERIAL6_DEFAULT_CONFIG;
    serial6.config                         = serial6_config;

    NVIC_Configuration(&uart6);

    /* register serial device */
    rt_err |= hal_serial_register(&serial6,
                                  "serial6",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart6);

    // mavlink
    serial7.ops = &_usart_ops;

    struct serial_configure serial7_config = SERIAL7_DEFAULT_CONFIG;
    serial7.config                         = serial7_config;

    NVIC_Configuration(&uart7);

    /* register serial device */
    rt_err |= hal_serial_register(&serial7,
                                  "serial7",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart7);

    return rt_err;
}

///////////////////////////////////////////////////////////////////////////////////////////

void ar_uart_init(unsigned char index, unsigned int baud_rate)
{
    int                 devisor;
    volatile uart_type* uart_regs = (uart_type*)UART0_BASE;
    uart_regs->IIR_FCR            = UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT | UART_FCR_TRIGGER_14;
    uart_regs->DLH_IER            = 0x00000000;
    uart_regs->LCR                = UART_LCR_WLEN8 & ~(UART_LCR_STOP | UART_LCR_PARITY);

    devisor = 100000000 / (16 * baud_rate);
    uart_regs->LCR |= UART_LCR_DLAB;
    uart_regs->DLH_IER     = (devisor >> 8) & 0x000000ff;
    uart_regs->RBR_THR_DLL = devisor & 0x000000ff;
    uart_regs->LCR &= ~UART_LCR_DLAB;
    uart_regs->DLH_IER = 0x1;
}

static inline int isdigit(int ch)
{
    return (ch >= '0') && (ch <= '9');
}

static int skip_atoi(const char** s)
{
    int i = 0;

    while (isdigit(**s))
        i = i * 10 + *((*s)++) - '0';
    return i;
}

#define ZEROPAD           1  /* pad with zero */
#define SIGN              2  /* unsigned/signed long */
#define PLUS              4  /* show plus */
#define SPACE             8  /* space if plus */
#define LEFT              16 /* left justified */
#define SMALL             32 /* Must be 32 == 0x20 */
#define SPECIAL           64 /* 0x */

#define __do_div(n, base) ({ \
int __res; \
__res = ((unsigned long) n) % (unsigned) base; \
n = ((unsigned long) n) / (unsigned) base; \
__res; })

static size_t boot_strnlen(const char* s, size_t maxlen)
{
    const char* es = s;
    while (*es && maxlen) {
        es++;
        maxlen--;
    }

    return (es - s);
}

static char* number(char* str, long num, int base, int size, int precision,
                    int type)
{
    /* we are called with base 8, 10 or 16, only, thus don't need "G..."  */
    static const char digits[16] = "0123456789ABCDEF"; /* "GHIJKLMNOPQRSTUVWXYZ"; */

    char tmp[66];
    char c, sign, locase;
    int  i;

    /* locase = 0 or 0x20. ORing digits or letters with 'locase'
     * produces same digits or (maybe lowercased) letters */
    locase = (type & SMALL);
    if (type & LEFT)
        type &= ~ZEROPAD;
    if (base < 2 || base > 16)
        return NULL;
    c    = (type & ZEROPAD) ? '0' : ' ';
    sign = 0;
    if (type & SIGN) {
        if (num < 0) {
            sign = '-';
            num  = -num;
            size--;
        } else if (type & PLUS) {
            sign = '+';
            size--;
        } else if (type & SPACE) {
            sign = ' ';
            size--;
        }
    }
    if (type & SPECIAL) {
        if (base == 16)
            size -= 2;
        else if (base == 8)
            size--;
    }
    i = 0;
    if (num == 0)
        tmp[i++] = '0';
    else
        while (num != 0)
            tmp[i++] = (digits[__do_div(num, base)] | locase);
    if (i > precision)
        precision = i;
    size -= precision;
    if (!(type & (ZEROPAD + LEFT)))
        while (size-- > 0)
            *str++ = ' ';
    if (sign)
        *str++ = sign;
    if (type & SPECIAL) {
        if (base == 8)
            *str++ = '0';
        else if (base == 16) {
            *str++ = '0';
            *str++ = ('X' | locase);
        }
    }
    if (!(type & LEFT))
        while (size-- > 0)
            *str++ = c;
    while (i < precision--)
        *str++ = '0';
    while (i-- > 0)
        *str++ = tmp[i];
    while (size-- > 0)
        *str++ = ' ';
    return str;
}

int boot_vsprintf(char* buf, const char* fmt, va_list args)
{
    int           len;
    unsigned long num;
    int           i, base;
    char*         str;
    const char*   s;

    int flags; /* flags to number() */

    int field_width; /* width of output field */
    int precision;   /* min. # of digits for integers; max
                                   number of chars for from string */
    int qualifier;   /* 'h', 'l', or 'L' for integer fields */

    for (str = buf; *fmt; ++fmt) {
        if (*fmt != '%') {
            *str++ = *fmt;
            continue;
        }

        /* process flags */
        flags = 0;
    repeat:
        ++fmt; /* this also skips first '%' */
        switch (*fmt) {
        case '-':
            flags |= LEFT;
            goto repeat;
        case '+':
            flags |= PLUS;
            goto repeat;
        case ' ':
            flags |= SPACE;
            goto repeat;
        case '#':
            flags |= SPECIAL;
            goto repeat;
        case '0':
            flags |= ZEROPAD;
            goto repeat;
        }

        /* get field width */
        field_width = -1;
        if (isdigit(*fmt))
            field_width = skip_atoi(&fmt);
        else if (*fmt == '*') {
            ++fmt;
            /* it's the next argument */
            field_width = va_arg(args, int);
            if (field_width < 0) {
                field_width = -field_width;
                flags |= LEFT;
            }
        }

        /* get the precision */
        precision = -1;
        if (*fmt == '.') {
            ++fmt;
            if (isdigit(*fmt))
                precision = skip_atoi(&fmt);
            else if (*fmt == '*') {
                ++fmt;
                /* it's the next argument */
                precision = va_arg(args, int);
            }
            if (precision < 0)
                precision = 0;
        }

        /* get the conversion qualifier */
        qualifier = -1;
        if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L') {
            qualifier = *fmt;
            ++fmt;
        }

        /* default base */
        base = 10;

        switch (*fmt) {
        case 'c':
            if (!(flags & LEFT))
                while (--field_width > 0)
                    *str++ = ' ';
            *str++ = (unsigned char)va_arg(args, int);
            while (--field_width > 0)
                *str++ = ' ';
            continue;

        case 's':
            s   = va_arg(args, char*);
            len = boot_strnlen(s, precision);

            if (!(flags & LEFT))
                while (len < field_width--)
                    *str++ = ' ';
            for (i = 0; i < len; ++i)
                *str++ = *s++;
            while (len < field_width--)
                *str++ = ' ';
            continue;

        case 'p':
            if (field_width == -1) {
                field_width = 2 * sizeof(void*);
                flags |= ZEROPAD;
            }
            str = number(str,
                         (unsigned long)va_arg(args, void*),
                         16,
                         field_width,
                         precision,
                         flags);
            continue;

        case 'n':
            if (qualifier == 'l') {
                long* ip = va_arg(args, long*);
                *ip      = (str - buf);
            } else {
                int* ip = va_arg(args, int*);
                *ip     = (str - buf);
            }
            continue;

        case '%':
            *str++ = '%';
            continue;

            /* integer number formats - set up the flags and "break" */
        case 'o':
            base = 8;
            break;

        case 'x':
            flags |= SMALL;
        case 'X':
            base = 16;
            break;

        case 'd':
        case 'i':
            flags |= SIGN;
        case 'u':
            break;

        default:
            *str++ = '%';
            if (*fmt)
                *str++ = *fmt;
            else
                --fmt;
            continue;
        }
        if (qualifier == 'l')
            num = va_arg(args, unsigned long);
        else if (qualifier == 'h') {
            num = (unsigned short)va_arg(args, int);
            if (flags & SIGN)
                num = (short)num;
        } else if (flags & SIGN)
            num = va_arg(args, int);
        else
            num = va_arg(args, unsigned int);
        str = number(str, num, base, field_width, precision, flags);
    }
    *str = '\0';
    return str - buf;
}

void boot_uart_putc(unsigned char index, unsigned char c)
{
    volatile uart_type* uart_regs = (uart_type*)UART0_BASE;

    while ((uart_regs->LSR & UART_LSR_THRE) != UART_LSR_THRE)
        ;
    uart_regs->RBR_THR_DLL = c;
}

void boot_uart_puts(unsigned char index, const char* s)
{
    while (*s) {
        boot_uart_putc(index, *s++);
    }
}

int BOOT_Printf(const char* fmt, ...)
{
    char    printf_buf[1024];
    va_list args;
    int     printed;

    va_start(args, fmt);
    printed = boot_vsprintf(printf_buf, fmt, args);
    va_end(args);

    boot_uart_puts(0, printf_buf);

    return printed;
}
