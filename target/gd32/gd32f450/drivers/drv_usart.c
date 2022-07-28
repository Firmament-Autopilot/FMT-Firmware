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

// #include "gd32f4xx_gpio.h"
// #include "gd32f4xx_usart.h"

#include "drv_usart.h"
#include "hal/serial/serial.h"

#define UART_ENABLE_IRQ(n)  NVIC_EnableIRQ((n))
#define UART_DISABLE_IRQ(n) NVIC_DisableIRQ((n))

/* GD32 uart driver */
// Todo: compress uart info
struct gd32_uart {
    uint32_t uart_periph;        //Todo: 3bits
    IRQn_Type irqn;              //Todo: 7bits
    rcu_periph_enum per_clk;     //Todo: 5bits
    rcu_periph_enum tx_gpio_clk; //Todo: 5bits
    rcu_periph_enum rx_gpio_clk; //Todo: 5bits
    uint32_t tx_port;            //Todo: 4bits
    uint16_t tx_af;              //Todo: 4bits
    uint16_t tx_pin;             //Todo: 4bits
    uint32_t rx_port;            //Todo: 4bits
    uint16_t rx_af;              //Todo: 4bits
    uint16_t rx_pin;             //Todo: 4bits
};

#define USING_UART0
#define USING_UART6

static struct serial_device serial0;
static struct serial_device serial1;

static struct gd32_uart uart0 = {
    .uart_periph = USART0,
    .irqn = USART0_IRQn,
    .per_clk = RCU_USART0,
    .tx_gpio_clk = RCU_GPIOA,
    .rx_gpio_clk = RCU_GPIOA,
    .tx_port = GPIOA,
    .tx_af = GPIO_AF_7,
    .tx_pin = GPIO_PIN_9,
    .rx_port = GPIOA,
    .rx_af = GPIO_AF_7,
    .rx_pin = GPIO_PIN_10,
};

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

static void uart_isr(struct serial_device* serial)
{
    struct gd32_uart* uart = (struct gd32_uart*)serial->parent.user_data;

    /* UART in mode Receiver -------------------------------------------------*/

    if ((usart_interrupt_flag_get(uart->uart_periph, USART_INT_FLAG_RBNE) != RESET) && (usart_flag_get(uart->uart_periph, USART_FLAG_RBNE) != RESET)) {
        /* high-level ISR routine */
        hal_serial_isr(serial, SERIAL_EVENT_RX_IND);
        /* Clear RXNE interrupt flag */
        usart_flag_clear(uart->uart_periph, USART_FLAG_RBNE);
    }
}

void USART0_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial0);
    /* leave interrupt */
    rt_interrupt_leave();
}

void UART6_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    /* uart isr routine */
    uart_isr(&serial1);
    /* leave interrupt */
    rt_interrupt_leave();
}

void gd32_uart_gpio_init(struct gd32_uart* uart)
{
    /* enable USART clock */
    rcu_periph_clock_enable(uart->tx_gpio_clk);
    rcu_periph_clock_enable(uart->rx_gpio_clk);
    rcu_periph_clock_enable(uart->per_clk);

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
    usart_interrupt_enable(uart->uart_periph, USART_INT_RBNE);
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
    while ((usart_flag_get(uart->uart_periph, USART_FLAG_TBE) == RESET))
        ;

    return RT_EOK;
}

static int usart_getc(struct serial_device* serial)
{
    int ch;
    struct gd32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct gd32_uart*)serial->parent.user_data;

    ch = -1;
    if (usart_flag_get(uart->uart_periph, USART_FLAG_RBNE) != RESET)
        ch = usart_data_receive(uart->uart_periph);

    return ch;
}

/* usart driver operations */
static const struct usart_ops __usart_ops = {
    .configure = usart_configure,
    .control = usart_control,
    .putc = usart_putc,
    .getc = usart_getc,
    NULL
};

rt_err_t drv_usart_init(void)
{
    rt_err_t rt_err = RT_EOK;
    struct serial_configure config = SERIAL_DEFAULT_CONFIG;

#ifdef USING_UART0
    serial0.ops = &__usart_ops;
    #ifdef SERIAL4_DEFAULT_CONFIG
    struct serial_configure serial0_config = SERIAL0_DEFAULT_CONFIG;
    serial0.config = serial0_config;
    #else
    serial0.config = config;
    #endif

    // NVIC_Configuration(&uart6);
    /* register serial device */
    rt_err |= hal_serial_register(&serial0,
                                  "serial0",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart0);
#endif /* USING_UART0 */

#ifdef USING_UART6
    serial1.ops = &__usart_ops;
    #ifdef SERIAL4_DEFAULT_CONFIG
    struct serial_configure serial1_config = SERIAL1_DEFAULT_CONFIG;
    serial1.config = serial1_config;
    #else
    serial1.config = config;
    #endif

    // NVIC_Configuration(&uart6);
    /* register serial device */
    rt_err |= hal_serial_register(&serial1,
                                  "serial1",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart6);
#endif /* USING_UART6 */

    return rt_err;
}
