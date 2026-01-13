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
#include "stm32h7xx_ll_usart.h"

#define UART_ENABLE_IRQ(n)  NVIC_EnableIRQ((n))
#define UART_DISABLE_IRQ(n) NVIC_DisableIRQ((n))

#define USING_UART1

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
        uint32_t rx_request;
        /* dma rx irq */
        uint8_t rx_irq;
        /* tx dma stream */
        uint32_t tx_stream;
        /* dma channel */
        uint32_t tx_request;
        /* dma tx irq */
        uint8_t tx_irq;
        /* setting receive len */
        rt_size_t setting_recv_len;
        /* last receive index */
        rt_size_t last_recv_index;
    } dma;
};

// static rt_size_t usart_dma_transmit(struct serial_device* serial, rt_uint8_t* buf, rt_size_t size, int direction);
static int usart_getc(struct serial_device* serial);
static int usart_putc(struct serial_device* serial, char c);
static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg);
static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg);

/**
 * Uart common interrupt process. This need add to uart ISR.
 *
 * @param serial serial device
 */
static void uart_isr(struct serial_device* serial)
{
    struct stm32_uart* uart = (struct stm32_uart*)serial->parent.user_data;

    if (LL_USART_IsActiveFlag_RXNE(uart->uart_device) && LL_USART_IsEnabledIT_RXNE(uart->uart_device)) {
        /* high-level ISR routine */
        hal_serial_isr(serial, SERIAL_EVENT_RX_IND);
        /* the RXNE flag is cleared by reading the USART_RDR register */
    }

    // if (LL_USART_IsActiveFlag_IDLE(uart->uart_device) && LL_USART_IsEnabledIT_IDLE(uart->uart_device)) {
    //     if (LL_USART_IsEnabledDMAReq_RX(uart->uart_device)) {
    //         dma_uart_rx_idle_isr(serial);
    //     }
    //     /* clear interrupt flag */
    //     LL_USART_ClearFlag_IDLE(uart->uart_device);
    // }

    if (LL_USART_IsActiveFlag_TC(uart->uart_device) && LL_USART_IsEnabledIT_TC(uart->uart_device)) {
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

    if (LL_USART_IsActiveFlag_FE(uart->uart_device) != RESET) {
        LL_USART_ClearFlag_FE(uart->uart_device);
    }

    if (LL_USART_IsActiveFlag_NE(uart->uart_device) != RESET) {
        LL_USART_ClearFlag_NE(uart->uart_device);
    }
}

#ifdef USING_UART1
static struct serial_device serial0;
struct stm32_uart uart1 = {
    .uart_device = USART1,
    .irq = USART1_IRQn,
};

void USART1_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial0);
    /* leave interrupt */
    rt_interrupt_leave();
}
#endif // USING_UART1

static void RCC_Configuration(void)
{
    LL_RCC_SetUSARTClockSource(LL_RCC_USART234578_CLKSOURCE_PCLK1);
    LL_RCC_SetUSARTClockSource(LL_RCC_USART16_CLKSOURCE_PCLK2);

#ifdef USING_UART1
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOB);
#endif

    /* DMA controller clock enable */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA2);
}

static void GPIO_Configuration(void)
{
    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

#ifdef USING_UART1
    /**USART1 GPIO Configuration
    PB14   ------> USART1_TX
    PB15   ------> USART1_RX
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_14 | LL_GPIO_PIN_15;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
#endif /* USING_UART1 */
}

static void NVIC_Configuration(struct stm32_uart* uart)
{
    // TODO: configure the PreemptionPriority and SubPriority

    /* disable usart device by default, incase that enter irq before usart has been configured */
    LL_USART_Disable(uart->uart_device);

    /* enable the usart interrupt */
    NVIC_SetPriority(uart->irq, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
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
    LL_USART_DisableIT_ERROR(uart->uart_device); /* Disable error interrupt */
    LL_USART_Enable(uart->uart_device);

    /* Polling USART initialisation */
    while ((!(LL_USART_IsActiveFlag_TEACK(uart->uart_device))) || (!(LL_USART_IsActiveFlag_REACK(uart->uart_device)))) {
    }

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
        }
        break;

    case RT_DEVICE_CTRL_SET_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {
            /* enable rx irq */
        }
        break;

    /* USART DMA config */
    case RT_DEVICE_CTRL_CONFIG:
        if (ctrl_arg == RT_DEVICE_FLAG_DMA_RX) {

        }

        if (ctrl_arg == RT_DEVICE_FLAG_DMA_TX) {

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

// static rt_size_t usart_dma_transmit(struct serial_device* serial, rt_uint8_t* buf, rt_size_t size, int direction)
// {
//     if (direction == SERIAL_DMA_TX && size > 0) {
//         _dma_transmit(serial->parent.user_data, buf, size);
//     }

//     return size;
// }

/* usart driver operations */
static const struct usart_ops _usart_ops = {
    usart_configure,
    usart_control,
    usart_putc,
    usart_getc,
    .dma_transmit = NULL
};

rt_err_t drv_usart_init(void)
{
    rt_err_t rt_err = RT_EOK;
    struct serial_configure config = SERIAL_DEFAULT_CONFIG;

    RCC_Configuration();
    GPIO_Configuration();

#ifdef USING_UART1
    serial0.ops = &_usart_ops;
    #ifdef SERIAL0_DEFAULT_CONFIG
    struct serial_configure serial0_config = SERIAL0_DEFAULT_CONFIG;
    serial0.config = serial0_config;
    #else
    serial0.config = config;
    #endif

    NVIC_Configuration(&uart1);

    /* register serial device */
    rt_err |= hal_serial_register(
        &serial0,
        "serial0",
        RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
        &uart1);
#endif /* USING_UART1 */

    return RT_EOK;
}
