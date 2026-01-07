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

#define USING_UART5

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

/* HC32 uart driver */
struct hc32_uart {
    CM_USART_TypeDef* uart_periph;
};


#ifdef USING_UART5
static struct serial_device serial0;
static struct hc32_uart uart5 = {
    .uart_periph = CM_USART5,
};

static void USART5_RxError_IrqCallback(void)
{
    (void)USART_ReadData(uart5.uart_periph);

    USART_ClearStatus(uart5.uart_periph, (USART_FLAG_PARITY_ERR | USART_FLAG_FRAME_ERR | USART_FLAG_OVERRUN));
}

static void USART5_RxFull_IrqCallback(void)
{
    rt_interrupt_enter();
    hal_serial_isr(&serial0, SERIAL_EVENT_RX_IND);
    rt_interrupt_leave();    
}
#endif

/**
 * @brief  Instal IRQ handler.
 * @param  [in] pstcConfig      Pointer to struct @ref stc_irq_signin_config_t
 * @param  [in] u32Priority     Interrupt priority
 * @retval None
 */
static void INTC_IrqInstalHandler(const stc_irq_signin_config_t *pstcConfig, uint32_t u32Priority)
{
    if (NULL != pstcConfig) {
        (void)INTC_IrqSignIn(pstcConfig);
        NVIC_ClearPendingIRQ(pstcConfig->enIRQn);
        NVIC_SetPriority(pstcConfig->enIRQn, u32Priority);
        NVIC_EnableIRQ(pstcConfig->enIRQn);
    }
}

static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg)
{
    struct hc32_uart* uart;
    stc_usart_uart_init_t stcUartInit;

    RT_ASSERT(serial != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    uart = (struct hc32_uart*)serial->parent.user_data;

    // LL_PERIPH_WE(LL_PERIPH_ALL);

    USART_DeInit(uart->uart_periph);
    (void)USART_UART_StructInit(&stcUartInit);

    stcUartInit.u32Baudrate = cfg->baud_rate;

    if (cfg->data_bits == DATA_BITS_8) {
        stcUartInit.u32DataWidth = USART_DATA_WIDTH_8BIT;
    } else if (cfg->data_bits == DATA_BITS_9) {
        stcUartInit.u32DataWidth = USART_DATA_WIDTH_9BIT;
    }

    if (cfg->stop_bits == STOP_BITS_1) {
        stcUartInit.u32StopBit = USART_STOPBIT_1BIT;
    } else if (cfg->stop_bits == STOP_BITS_2) {
        stcUartInit.u32StopBit = USART_STOPBIT_2BIT;
    }

    if (cfg->parity == PARITY_NONE) {
        stcUartInit.u32Parity = USART_PARITY_NONE;
    } else if (cfg->parity == PARITY_ODD) {
        stcUartInit.u32Parity = USART_PARITY_ODD;
    } else if (cfg->parity == PARITY_EVEN) {
        stcUartInit.u32Parity = USART_PARITY_EVEN;
    }

    stcUartInit.u32HWFlowControl = USART_HW_FLOWCTRL_NONE;
    stcUartInit.u32OverSampleBit = USART_OVER_SAMPLE_16BIT;
    stcUartInit.u32FirstBit = USART_FIRST_BIT_LSB;
    stcUartInit.u32StartBitPolarity = USART_START_BIT_FALLING;
    USART_UART_Init(uart->uart_periph, &stcUartInit, NULL);

    /* Enable USART_TX | USART_RX function */
    USART_FuncCmd(uart->uart_periph, (USART_TX | USART_RX | USART_INT_RX), ENABLE);

    // LL_PERIPH_WP(LL_PERIPH_ALL);

    return RT_EOK;
}
static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg)
{
    struct hc32_uart* uart;
    rt_uint32_t ctrl_arg = (rt_uint32_t)(arg);

    RT_ASSERT(serial != RT_NULL);
    uart = (struct hc32_uart*)serial->parent.user_data;

    switch (cmd) {
    case RT_DEVICE_CTRL_CLR_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {
        }
        break;

    case RT_DEVICE_CTRL_SET_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {
        }
        break;

        /* USART DMA config */
    case RT_DEVICE_CTRL_CONFIG:
        break;

    case RT_DEVICE_CTRL_SUSPEND:
        break;

    default:
        break;
    }

    return RT_EOK;
}

static int usart_putc(struct serial_device* serial, char ch)
{
    struct hc32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct hc32_uart*)serial->parent.user_data;

    /* Wait Tx data register empty */
    while (RESET == USART_GetStatus(uart->uart_periph, USART_FLAG_TX_EMPTY)) {
    }

    USART_WriteData(uart->uart_periph, ch);

    return RT_EOK;
}

static int usart_getc(struct serial_device* serial)
{
    int ch = -1;
    struct hc32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct hc32_uart*)serial->parent.user_data;

    if (SET == USART_GetStatus(uart->uart_periph, USART_FLAG_RX_FULL))
        ch = USART_ReadData(uart->uart_periph);

    return ch;
}

static rt_size_t usart_dma_transmit(struct serial_device* serial, rt_uint8_t* buf, rt_size_t size, int direction)
{
    return size;
}

/* usart driver operations */
static const struct usart_ops __usart_ops = {
    .configure = usart_configure,
    .control = usart_control,
    .putc = usart_putc,
    .getc = usart_getc,
    .dma_transmit = usart_dma_transmit,
};

static void uart_peripheral_init(void)
{
    stc_irq_signin_config_t stcIrqSigninConfig;

    /* MCU Peripheral registers write unprotected */
    // LL_PERIPH_WE(LL_PERIPH_ALL);

    /* Configure USART RX/TX pin. */
    GPIO_SetFunc(GPIO_PORT_C, GPIO_PIN_12, GPIO_FUNC_20); // USART5-TX
    GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_02, GPIO_FUNC_20); // USART5-RX

    /* Enable USART5 clock */
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART5, ENABLE);

    /* Register RX error IRQ handler && configure NVIC. */
    stcIrqSigninConfig.enIRQn = INT000_IRQn;
    stcIrqSigninConfig.enIntSrc = INT_SRC_USART5_EI;
    stcIrqSigninConfig.pfnCallback = &USART5_RxError_IrqCallback;
    INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);

    /* Register RX full IRQ handler && configure NVIC. */
    stcIrqSigninConfig.enIRQn = INT001_IRQn;
    stcIrqSigninConfig.enIntSrc = INT_SRC_USART5_RI;
    stcIrqSigninConfig.pfnCallback = &USART5_RxFull_IrqCallback;
    INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);

    /* MCU Peripheral registers write protected */
    // LL_PERIPH_WP(LL_PERIPH_ALL);
}

rt_err_t drv_usart_init(void)
{
    rt_err_t rt_err = RT_EOK;
    struct serial_configure config = SERIAL_DEFAULT_CONFIG;

    uart_peripheral_init();

#ifdef USING_UART5
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
                                  &uart5);
#endif /* USING_UART5 */

    return rt_err;
}
