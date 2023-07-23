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

#define SET_BIT(REG, BIT)   ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)  ((REG) & (BIT))

#define UART_ENABLE_IRQ(n)  NVIC_EnableIRQ((n))
#define UART_DISABLE_IRQ(n) NVIC_DisableIRQ((n))

#define USING_UART0
#define USING_UART1
#define USING_UART2
#define USING_UART6
#define USING_UART7

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

/* GD32 uart driver */
// Todo: compress uart info
struct gd32_uart {
    uint32_t uart_periph;
    IRQn_Type irqn;
    rcu_periph_enum per_clk;
    rcu_periph_enum tx_gpio_clk;
    rcu_periph_enum rx_gpio_clk;
    uint32_t tx_port;
    uint16_t tx_af;
    uint16_t tx_pin;
    uint32_t rx_port;
    uint16_t rx_af;
    uint16_t rx_pin;
    struct gd32_uart_dma {
        /* dma instance */
        uint32_t dma_periph;
        /* dma clock */
        rcu_periph_enum clock;
        /* dma rx channel */
        dma_channel_enum rx_ch;
        /* dma rx irq */
        uint8_t rx_irq;
        /* dma tx channel */
        dma_channel_enum tx_ch;
        /* dma tx irq */
        uint8_t tx_irq;
        /* dma peripheral select */
        dma_subperipheral_enum sub_periph;
        /* setting receive len */
        rt_size_t setting_recv_len;
        /* last receive index */
        rt_size_t last_recv_index;
    } dma;
};

/**
 * Serial port receive idle process. This need add to uart idle ISR.
 *
 * @param serial serial device
 */
static void dma_uart_rx_idle_isr(struct serial_device* serial)
{
    struct gd32_uart* uart = (struct gd32_uart*)serial->parent.user_data;
    rt_size_t recv_total_index, recv_len;
    rt_base_t level;
    uint32_t remain_bytes;

    /* disable interrupt */
    level = rt_hw_interrupt_disable();
    /* check remain bytes to receive */
    remain_bytes = dma_transfer_number_get(uart->dma.dma_periph, uart->dma.rx_ch);
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
    struct gd32_uart* uart = (struct gd32_uart*)serial->parent.user_data;
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

static void uart_isr(struct serial_device* serial)
{
    struct gd32_uart* uart = (struct gd32_uart*)serial->parent.user_data;

    if ((usart_interrupt_flag_get(uart->uart_periph, USART_INT_FLAG_RBNE) != RESET) && (usart_flag_get(uart->uart_periph, USART_FLAG_RBNE) != RESET)) {
        /* high-level ISR routine */
        hal_serial_isr(serial, SERIAL_EVENT_RX_IND);
        /* Clear RXNE interrupt flag */
        usart_flag_clear(uart->uart_periph, USART_FLAG_RBNE);
    }

    if ((usart_interrupt_flag_get(uart->uart_periph, USART_INT_FLAG_IDLE) != RESET) && (usart_flag_get(uart->uart_periph, USART_FLAG_IDLE) != RESET)) {
        dma_uart_rx_idle_isr(serial);
        /* Read USART_DATA to clear IDLE interrupt flag */
        usart_data_receive(uart->uart_periph);
    }

    if ((usart_interrupt_flag_get(uart->uart_periph, USART_INT_FLAG_TC) != RESET) && (usart_flag_get(uart->uart_periph, USART_FLAG_TC) != RESET)) {
        /* Clear TC interrupt flag */
        usart_flag_clear(uart->uart_periph, USART_FLAG_TC);
    }
}

#ifdef USING_UART6
static struct serial_device serial0;
static struct gd32_uart uart6 = {
    .uart_periph = UART6,
    .irqn = UART6_IRQn,
    .per_clk = RCU_UART6,
    .tx_gpio_clk = RCU_GPIOE,
    .rx_gpio_clk = RCU_GPIOE,
    .tx_port = GPIOE,
    .tx_af = GPIO_AF_8,
    .tx_pin = GPIO_PIN_8,
    .rx_port = GPIOE,
    .rx_af = GPIO_AF_8,
    .rx_pin = GPIO_PIN_7,
};

void UART6_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial0);
    /* leave interrupt */
    rt_interrupt_leave();
}
#endif /* USING_UART6 */

#ifdef USING_UART1
static struct serial_device serial1;
static struct gd32_uart uart1 = {
    .uart_periph = USART1,
    .irqn = USART1_IRQn,
    .per_clk = RCU_USART1,
    .tx_gpio_clk = RCU_GPIOD,
    .rx_gpio_clk = RCU_GPIOD,
    .tx_port = GPIOD,
    .tx_af = GPIO_AF_7,
    .tx_pin = GPIO_PIN_5,
    .rx_port = GPIOD,
    .rx_af = GPIO_AF_7,
    .rx_pin = GPIO_PIN_6,
    .dma = {
        .dma_periph = DMA0,
        .clock = RCU_DMA0,
        .rx_ch = DMA_CH5,
        .rx_irq = DMA0_Channel5_IRQn,
        .tx_ch = DMA_CH6,
        .tx_irq = DMA0_Channel6_IRQn,
        .sub_periph = DMA_SUBPERI4,
    }
};

void USART1_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial1);
    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA0_Channel6_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    if (dma_interrupt_flag_get(uart1.dma.dma_periph, uart1.dma.tx_ch, DMA_INT_FLAG_FTF)) {
        dma_tx_done_isr(&serial1);
        dma_interrupt_flag_clear(uart1.dma.dma_periph, uart1.dma.tx_ch, DMA_INT_FLAG_FTF);
    }
    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA0_Channel5_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    if (dma_interrupt_flag_get(uart1.dma.dma_periph, uart1.dma.rx_ch, DMA_INT_FLAG_FTF)) {
        dma_rx_done_isr(&serial1);
        dma_interrupt_flag_clear(uart1.dma.dma_periph, uart1.dma.rx_ch, DMA_INT_FLAG_FTF);
    }
    /* leave interrupt */
    rt_interrupt_leave();
}
#endif /* USING_UART1 */

#ifdef USING_UART2
static struct serial_device serial2;
static struct gd32_uart uart2 = {
    .uart_periph = USART2,
    .irqn = USART2_IRQn,
    .per_clk = RCU_USART2,
    .tx_gpio_clk = RCU_GPIOD,
    .rx_gpio_clk = RCU_GPIOD,
    .tx_port = GPIOD,
    .tx_af = GPIO_AF_7,
    .tx_pin = GPIO_PIN_8,
    .rx_port = GPIOD,
    .rx_af = GPIO_AF_7,
    .rx_pin = GPIO_PIN_9,
    .dma = {
        .dma_periph = DMA0,
        .clock = RCU_DMA0,
        .rx_ch = DMA_CH1,
        .rx_irq = DMA0_Channel1_IRQn,
        .tx_ch = DMA_CH3,
        .tx_irq = DMA0_Channel3_IRQn,
        .sub_periph = DMA_SUBPERI4,
    }
};

void USART2_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial2);
    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA0_Channel1_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    if (dma_interrupt_flag_get(uart2.dma.dma_periph, uart2.dma.rx_ch, DMA_INT_FLAG_FTF)) {
        dma_rx_done_isr(&serial2);
        dma_interrupt_flag_clear(uart2.dma.dma_periph, uart2.dma.rx_ch, DMA_INT_FLAG_FTF);
    }
    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA0_Channel3_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    if (dma_interrupt_flag_get(uart2.dma.dma_periph, uart2.dma.tx_ch, DMA_INT_FLAG_FTF)) {
        dma_tx_done_isr(&serial2);
        dma_interrupt_flag_clear(uart2.dma.dma_periph, uart2.dma.tx_ch, DMA_INT_FLAG_FTF);
    }
    /* leave interrupt */
    rt_interrupt_leave();
}
#endif /* USING_UART2 */

#ifdef USING_UART0
static struct serial_device serial3;
static struct gd32_uart uart0 = {
    .uart_periph = USART0,
    .irqn = USART0_IRQn,
    .per_clk = RCU_USART0,
    .tx_gpio_clk = RCU_GPIOB,
    .rx_gpio_clk = RCU_GPIOB,
    .tx_port = GPIOB,
    .tx_af = GPIO_AF_7,
    .tx_pin = GPIO_PIN_6,
    .rx_port = GPIOB,
    .rx_af = GPIO_AF_7,
    .rx_pin = GPIO_PIN_7,
    .dma = {
        .dma_periph = DMA1,
        .clock = RCU_DMA1,
        .rx_ch = DMA_CH5,
        .rx_irq = DMA1_Channel5_IRQn,
        .tx_ch = DMA_CH7,
        .tx_irq = DMA1_Channel7_IRQn,
        .sub_periph = DMA_SUBPERI4,
    }
};

void USART0_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial3);
    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA1_Channel5_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    if (dma_interrupt_flag_get(uart0.dma.dma_periph, uart0.dma.rx_ch, DMA_INT_FLAG_FTF)) {
        dma_rx_done_isr(&serial3);
        dma_interrupt_flag_clear(uart0.dma.dma_periph, uart0.dma.rx_ch, DMA_INT_FLAG_FTF);
    }
    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA1_Channel7_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    if (dma_interrupt_flag_get(uart0.dma.dma_periph, uart0.dma.tx_ch, DMA_INT_FLAG_FTF)) {
        dma_tx_done_isr(&serial3);
        dma_interrupt_flag_clear(uart0.dma.dma_periph, uart0.dma.tx_ch, DMA_INT_FLAG_FTF);
    }
    /* leave interrupt */
    rt_interrupt_leave();
}
#endif /* USING_UART0 */

#ifdef USING_UART7
static struct serial_device serial4;
static struct gd32_uart uart7 = {
    .uart_periph = UART7,
    .irqn = UART7_IRQn,
    .per_clk = RCU_UART7,
    .tx_gpio_clk = RCU_GPIOE,
    .rx_gpio_clk = RCU_GPIOE,
    .tx_port = GPIOE,
    .tx_af = GPIO_AF_8,
    .tx_pin = GPIO_PIN_1,
    .rx_port = GPIOE,
    .rx_af = GPIO_AF_8,
    .rx_pin = GPIO_PIN_0,
    // .dma = {
    //     .dma_periph = DMA0,
    //     .clock = RCU_DMA0,
    //     .rx_ch = DMA_CH1,
    //     .rx_irq = DMA0_Channel1_IRQn,
    //     .tx_ch = DMA_CH3,
    //     .tx_irq = DMA0_Channel3_IRQn,
    //     .sub_periph = DMA_SUBPERI4,
    // }
};

void UART7_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial4);
    /* leave interrupt */
    rt_interrupt_leave();
}
#endif /* USING_UART7 */

static void _dma_transmit(struct gd32_uart* uart, rt_uint8_t* buf, rt_size_t size)
{
    /* wait current transfers are finished */
    while (READ_BIT(DMA_CHCTL(uart->dma.dma_periph, uart->dma.tx_ch), BIT(0)))
        ;

    dma_memory_address_config(uart->dma.dma_periph, uart->dma.tx_ch, 0, (uint32_t)buf);
    dma_transfer_number_config(uart->dma.dma_periph, uart->dma.tx_ch, size);

    /* enable DMA channel transfer complete interrupt */
    dma_interrupt_enable(uart->dma.dma_periph, uart->dma.tx_ch, DMA_CHXCTL_FTFIE);
    /* enable DMA channel7 */
    dma_channel_enable(uart->dma.dma_periph, uart->dma.tx_ch);
}

static void _dma_tx_config(struct gd32_uart* uart)
{
    dma_single_data_parameter_struct dma_init_struct;

    /* enable dma tx interrupt */
    nvic_irq_enable(uart->dma.tx_irq, 0, 1);

    dma_deinit(uart->dma.dma_periph, uart->dma.tx_ch);
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPH;
    dma_init_struct.memory0_addr = 0x00000000U; /* will be configured later */
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.periph_memory_width = DMA_PERIPH_WIDTH_8BIT;
    dma_init_struct.number = 0x00000000U; /* will be configured later */
    dma_init_struct.periph_addr = (uint32_t)&USART_DATA(uart->uart_periph);
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
    dma_init_struct.circular_mode = DMA_CIRCULAR_MODE_DISABLE;
    dma_single_data_mode_init(uart->dma.dma_periph, uart->dma.tx_ch, &dma_init_struct);

    /* configure DMA mode */
    dma_channel_subperipheral_select(uart->dma.dma_periph, uart->dma.tx_ch, uart->dma.sub_periph);
    /* USART DMA enable for transmission */
    usart_dma_transmit_config(uart->uart_periph, USART_DENT_ENABLE);
}

static void _dma_rx_config(struct gd32_uart* uart, rt_uint8_t* buf, rt_size_t size)
{
    dma_single_data_parameter_struct dma_init_struct;

    /* set expected receive length */
    uart->dma.setting_recv_len = size;

    nvic_irq_enable(uart->dma.rx_irq, 0, 0);
    /* Enable USART IDLE interrupt, which is used by DMA rx */
    usart_interrupt_enable(uart->uart_periph, USART_INT_IDLE);

    dma_deinit(uart->dma.dma_periph, uart->dma.rx_ch);
    dma_init_struct.direction = DMA_PERIPH_TO_MEMORY;
    dma_init_struct.memory0_addr = (uint32_t)buf;
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.number = size;
    dma_init_struct.periph_addr = (uint32_t)&USART_DATA(uart->uart_periph);
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_memory_width = DMA_PERIPH_WIDTH_8BIT;
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
    dma_init_struct.circular_mode = DMA_CIRCULAR_MODE_ENABLE;
    dma_single_data_mode_init(uart->dma.dma_periph, uart->dma.rx_ch, &dma_init_struct);

    /* configure DMA mode */
    dma_channel_subperipheral_select(uart->dma.dma_periph, uart->dma.rx_ch, uart->dma.sub_periph);
    /* enable DMA channel transfer complete interrupt */
    dma_interrupt_enable(uart->dma.dma_periph, uart->dma.rx_ch, DMA_CHXCTL_FTFIE);
    /* enable DMA channel */
    dma_channel_enable(uart->dma.dma_periph, uart->dma.rx_ch);
    /* USART DMA enable for reception */
    usart_dma_receive_config(uart->uart_periph, USART_DENR_ENABLE);
}

static void _close_usart(struct serial_device* serial)
{
    struct gd32_uart* uart = (struct gd32_uart*)serial->parent.user_data;

    if (serial->parent.open_flag & RT_DEVICE_FLAG_INT_RX) {
        /* disable interrupt */
        usart_interrupt_disable(uart->uart_periph, USART_INT_RBNE);
    }

    if (serial->parent.open_flag & RT_DEVICE_FLAG_DMA_RX) {
        /* disable DMA channel transfer complete interrupt */
        dma_interrupt_disable(uart->dma.dma_periph, uart->dma.rx_ch, DMA_CHXCTL_FTFIE);
        /* disable rx idle interrupt */
        usart_interrupt_disable(uart->uart_periph, USART_INT_IDLE);
        /* disable DMA channel */
        dma_channel_disable(uart->dma.dma_periph, uart->dma.rx_ch);
        /* USART DMA disable for reception */
        usart_dma_receive_config(uart->uart_periph, USART_DENR_DISABLE);
    }

    if (serial->parent.open_flag & RT_DEVICE_FLAG_DMA_TX) {
        /* disable DMA channel transfer complete interrupt */
        dma_interrupt_disable(uart->dma.dma_periph, uart->dma.tx_ch, DMA_CHXCTL_FTFIE);
        /* disable DMA channel */
        dma_channel_disable(uart->dma.dma_periph, uart->dma.tx_ch);
        /* USART DMA disable for transmission */
        usart_dma_receive_config(uart->uart_periph, USART_DENT_ENABLE);
    }
    /* reset last recv index */
    uart->dma.last_recv_index = 0;
}

static void gd32_uart_gpio_init(struct gd32_uart* uart)
{
    /* enable USART clock */
    rcu_periph_clock_enable(uart->tx_gpio_clk);
    rcu_periph_clock_enable(uart->rx_gpio_clk);
    rcu_periph_clock_enable(uart->per_clk);
    if (uart->dma.clock == RCU_DMA0 || uart->dma.clock == RCU_DMA1) {
        /* enable DMA1 clock */
        rcu_periph_clock_enable(uart->dma.clock);
    }

    /* connect port to USARTx_Tx */
    gpio_af_set(uart->tx_port, uart->tx_af, uart->tx_pin);
    /* connect port to USARTx_Rx */
    gpio_af_set(uart->rx_port, uart->rx_af, uart->rx_pin);

    /* configure USART Tx as alternate function push-pull */
    gpio_mode_set(uart->tx_port, GPIO_MODE_AF, GPIO_PUPD_PULLUP, uart->tx_pin);
    gpio_output_options_set(uart->tx_port, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, uart->tx_pin);

    /* configure USART Rx as alternate function push-pull */
    gpio_mode_set(uart->rx_port, GPIO_MODE_AF, GPIO_PUPD_PULLUP, uart->rx_pin);
    gpio_output_options_set(uart->rx_port, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, uart->rx_pin);

    NVIC_SetPriority(uart->irqn, 0);
    NVIC_EnableIRQ(uart->irqn);
}

static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg)
{
    struct gd32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    uart = (struct gd32_uart*)serial->parent.user_data;

    gd32_uart_gpio_init(uart);

    usart_baudrate_set(uart->uart_periph, cfg->baud_rate);

    switch (cfg->data_bits) {
    case DATA_BITS_9:
        usart_word_length_set(uart->uart_periph, USART_WL_9BIT);
        break;

    default:
        usart_word_length_set(uart->uart_periph, USART_WL_8BIT);
        break;
    }

    switch (cfg->stop_bits) {
    case STOP_BITS_2:
        usart_stop_bit_set(uart->uart_periph, USART_STB_2BIT);
        break;
    default:
        usart_stop_bit_set(uart->uart_periph, USART_STB_1BIT);
        break;
    }

    switch (cfg->parity) {
    case PARITY_ODD:
        usart_parity_config(uart->uart_periph, USART_PM_ODD);
        break;
    case PARITY_EVEN:
        usart_parity_config(uart->uart_periph, USART_PM_EVEN);
        break;
    default:
        usart_parity_config(uart->uart_periph, USART_PM_NONE);
        break;
    }

    usart_receive_config(uart->uart_periph, USART_RECEIVE_ENABLE);
    usart_transmit_config(uart->uart_periph, USART_TRANSMIT_ENABLE);
    usart_enable(uart->uart_periph);

    return RT_EOK;
}

static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg)
{
    struct gd32_uart* uart;
    rt_uint32_t ctrl_arg = (rt_uint32_t)(arg);

    RT_ASSERT(serial != RT_NULL);
    uart = (struct gd32_uart*)serial->parent.user_data;

    switch (cmd) {
    case RT_DEVICE_CTRL_CLR_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {
            /* disable rx irq */
            NVIC_DisableIRQ(uart->irqn);
            /* disable interrupt */
            usart_interrupt_disable(uart->uart_periph, USART_INT_RBNE);
        }
        break;

    case RT_DEVICE_CTRL_SET_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {
            /* enable rx irq */
            NVIC_EnableIRQ(uart->irqn);
            /* enable interrupt */
            usart_interrupt_enable(uart->uart_periph, USART_INT_RBNE);
        }
        break;

        /* USART DMA config */
    case RT_DEVICE_CTRL_CONFIG:
        if (ctrl_arg == RT_DEVICE_FLAG_DMA_RX) {
            struct serial_rx_fifo* rx_fifo = (struct serial_rx_fifo*)serial->serial_rx;
            struct gd32_uart* uart = (struct gd32_uart*)serial->parent.user_data;

            if (READ_BIT(DMA_CHCTL(uart->dma.dma_periph, uart->dma.rx_ch), BIT(0))) {
                return RT_EBUSY;
            }

            _dma_rx_config(uart, rx_fifo->buffer, serial->config.bufsz);
        }

        if (ctrl_arg == RT_DEVICE_FLAG_DMA_TX) {
            struct gd32_uart* uart = (struct gd32_uart*)serial->parent.user_data;

            if (READ_BIT(DMA_CHCTL(uart->dma.dma_periph, uart->dma.tx_ch), 0)) {
                return RT_EBUSY;
            }

            _dma_tx_config(uart);
        }
        break;

    case RT_DEVICE_CTRL_SUSPEND:
        _close_usart(serial);
        break;

    default:
        break;
    }

    return RT_EOK;
}

static int usart_putc(struct serial_device* serial, char ch)
{
    struct gd32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct gd32_uart*)serial->parent.user_data;

    usart_data_transmit(uart->uart_periph, ch);

    /* wait transmit finish */
    while ((usart_flag_get(uart->uart_periph, USART_FLAG_TBE) == RESET))
        ;

    return RT_EOK;
}

static int usart_getc(struct serial_device* serial)
{
    int ch = -1;
    struct gd32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct gd32_uart*)serial->parent.user_data;

    if (usart_flag_get(uart->uart_periph, USART_FLAG_RBNE) != RESET)
        ch = usart_data_receive(uart->uart_periph);

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
static const struct usart_ops __usart_ops = {
    .configure = usart_configure,
    .control = usart_control,
    .putc = usart_putc,
    .getc = usart_getc,
    .dma_transmit = usart_dma_transmit,
};

rt_err_t drv_usart_init(void)
{
    rt_err_t rt_err = RT_EOK;
    struct serial_configure config = SERIAL_DEFAULT_CONFIG;

#ifdef USING_UART6
    serial0.ops = &__usart_ops;
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
                                  &uart6);
#endif /* USING_UART6 */

#ifdef USING_UART1
    serial1.ops = &__usart_ops;
    #ifdef SERIAL1_DEFAULT_CONFIG
    struct serial_configure serial1_config = SERIAL1_DEFAULT_CONFIG;
    serial1.config = serial1_config;
    #else
    serial1.config = config;
    #endif

    /* register serial device */
    rt_err |= hal_serial_register(&serial1,
                                  "serial1",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX,
                                  &uart1);
#endif /* USING_UART2 */

#ifdef USING_UART2
    serial2.ops = &__usart_ops;
    #ifdef SERIAL2_DEFAULT_CONFIG
    struct serial_configure serial2_config = SERIAL2_DEFAULT_CONFIG;
    serial2.config = serial2_config;
    #else
    serial2.config = config;
    #endif

    /* register serial device */
    rt_err |= hal_serial_register(&serial2,
                                  "serial2",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX,
                                  &uart2);
#endif /* USING_UART2 */

#ifdef USING_UART0
    serial3.ops = &__usart_ops;
    #ifdef SERIAL3_DEFAULT_CONFIG
    struct serial_configure serial3_config = SERIAL3_DEFAULT_CONFIG;
    serial3.config = serial3_config;
    #else
    serial3.config = config;
    #endif

    /* register serial device */
    rt_err |= hal_serial_register(&serial3,
                                  "serial3",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX,
                                  &uart0);
#endif /* USING_UART0 */

#ifdef USING_UART7
    serial4.ops = &__usart_ops;
    #ifdef SERIAL4_DEFAULT_CONFIG
    struct serial_configure serial4_config = SERIAL4_DEFAULT_CONFIG;
    serial4.config = serial4_config;
    #else
    serial4.config = config;
    #endif

    /* register serial device */
    rt_err |= hal_serial_register(&serial4,
                                  "serial4",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart7);
#endif /* USING_UART7 */

    return rt_err;
}
