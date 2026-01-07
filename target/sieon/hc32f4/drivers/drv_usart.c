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

#define LL_PERIPH_SEL       (LL_PERIPH_GPIO | LL_PERIPH_FCG | LL_PERIPH_PWC_CLK_RMU | LL_PERIPH_EFM | LL_PERIPH_SRAM)

/* USART RX/TX pin definition */
#define USART_RX_PORT       (GPIO_PORT_E) /* PH13: USART1_RX */
#define USART_RX_PIN        (GPIO_PIN_11)
#define USART_RX_GPIO_FUNC  (GPIO_FUNC_37)

// #define USART_TX_PORT                   (GPIO_PORT_E)   /* PH15: USART1_TX */
// #define USART_TX_PIN                    (GPIO_PIN_12)
// #define USART_TX_GPIO_FUNC              (GPIO_FUNC_36)

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

/* GD32 uart driver */
// Todo: compress uart info
struct wl32_uart {
    uint32_t uart_periph;
    uint32_t per_clk;
    uint32_t tx_port;
    uint16_t tx_af;
    uint16_t tx_pin;
    uint32_t rx_port;
    uint16_t rx_af;
    uint16_t rx_pin;

    uint32_t rx_full_irqn;
    uint32_t rx_full_int_src;
    void (*rx_full_irq_call_back)(void);

    uint32_t rx_timo_irqn;
    uint32_t rx_timo_int_src;
    void (*rx_timo_irq_call_back)(void);
};

static struct serial_device serial0;
static struct serial_device serial1;

static uint8_t usart1_rx_data_runing = 0;
static uint8_t usart1_rx_data_cnt = 0;
static uint8_t usart1_rx_data_addr = 0;
static uint8_t usart1_rx_dell = 0;
void usart1_irq_full_callback(void)
{
    rt_interrupt_enter();
    // if(usart1_rx_dell)
    //     return;
    hal_serial_isr(&serial0, SERIAL_EVENT_RX_IND);
    usart1_rx_data_addr++;
    usart1_rx_data_runing = 1;
    // uart_isr(&serial0);
    rt_interrupt_leave();
}

#ifdef USING_UART5
static uint8_t usart6_rx_data_runing = 0;
static uint8_t usart6_rx_data_cnt = 0;
static uint8_t usart6_rx_data_addr = 0;
static uint8_t usart6_rx_dell = 0;
void usart5_rx_full_irq_callback(void)
{
    rt_interrupt_enter();
    if (usart6_rx_dell)
        return;
    hal_serial_isr(&serial0, SERIAL_EVENT_RX_IND);
    usart6_rx_data_addr++;
    usart6_rx_data_runing = 1;
    // uart_isr(&serial0);
    rt_interrupt_leave();
}

void usart5_rx_timo_irq_callback(void)
{

    rt_interrupt_enter();

    // hal_serial_isr(&serial0, SERIAL_EVENT_RX_IND);
    // uart_isr(&serial0);
    rt_interrupt_leave();
}

static struct wl32_uart uart6 = {
    .uart_periph = (uint32_t)CM_USART5,
    .per_clk = FCG3_PERIPH_USART5,
    .rx_full_irqn = INT001_IRQn,
    .rx_full_int_src = INT_SRC_USART6_RI,
    .rx_full_irq_call_back = usart5_rx_full_irq_callback,
    .rx_timo_irqn = INT002_IRQn,
    .rx_timo_int_src = INT_SRC_USART6_RTO,
    .rx_timo_irq_call_back = usart5_rx_timo_irq_callback,
    .tx_port = GPIO_PORT_A,
    .tx_pin = GPIO_PIN_02,
    .tx_af = GPIO_FUNC_36,
    .rx_port = GPIO_PORT_A,
    .rx_pin = GPIO_PIN_00,
    .rx_af = GPIO_FUNC_37,

};
#endif

/**
 * Serial port receive idle process. This need add to uart idle ISR.
 *
 * @param serial serial device
 */

static uint8_t drv_usart_task_creat = 0;
static uint8_t drv_usart_task_run = 1;
static rt_thread_t drv_usart_rx_time;

uint16_t tmp_usb_cnt = 0;
uint16_t delay_tmp_cnt = 0;

void send_rc_channe(void);
#ifdef USING_UART1

static struct wl32_uart uart1 = {
    .uart_periph = (uint32_t)CM_USART1,
    .per_clk = FCG3_PERIPH_USART1,
    .rx_full_irqn = INT001_IRQn,
    .rx_full_int_src = INT_SRC_USART1_RI,
    .rx_full_irq_call_back = usart1_irq_full_callback,
    .rx_timo_irq_call_back = NULL,

    .tx_port = GPIO_PORT_B,
    .tx_pin = GPIO_PIN_09,
    .tx_af = GPIO_FUNC_32,
    .rx_port = GPIO_PORT_B,
    .rx_pin = GPIO_PIN_08,
    .rx_af = GPIO_FUNC_33,

};
#endif /* USING_UART1 */

#ifdef USING_UART4

void usart4_irq_full_callback(void)
{
    rt_interrupt_enter();
    if (usart4_rx_dell)
        return;
    hal_serial_isr(&serial1, SERIAL_EVENT_RX_IND);
    usart4_rx_data_addr++;
    usart4_rx_data_runing = 1;
    // uart_isr(&serial0);
    rt_interrupt_leave();
}

static struct wl32_uart uart4 = {
    .uart_periph = (uint32_t)CM_USART4,
    .per_clk = FCG3_PERIPH_USART4,
    .rx_full_irqn = INT003_IRQn,
    .rx_full_int_src = INT_SRC_USART4_RI,
    .rx_full_irq_call_back = usart4_irq_full_callback,
    .rx_timo_irq_call_back = NULL,

    .tx_port = GPIO_PORT_A,
    .tx_pin = GPIO_PIN_06,
    .tx_af = GPIO_FUNC_38,
    .rx_port = GPIO_PORT_E,
    .rx_pin = GPIO_PIN_09,
    .rx_af = GPIO_FUNC_33,

};

#endif

static void INTC_IrqInstalHandler(const stc_irq_signin_config_t* pstcConfig, uint32_t u32Priority)
{
    if (NULL != pstcConfig) {
        (void)INTC_IrqSignIn(pstcConfig);
        NVIC_ClearPendingIRQ(pstcConfig->enIRQn);
        NVIC_SetPriority(pstcConfig->enIRQn, u32Priority);
        NVIC_EnableIRQ(pstcConfig->enIRQn);
    }
}
static void TX_DMA_TC_IrqCallback(void)
{
    USART_FuncCmd(CM_USART4, USART_INT_TX_CPLT, ENABLE);

    DMA_ClearTransCompleteStatus(CM_DMA2, DMA_FLAG_TC_CH0);
}
static void USART_TxComplete_IrqCallback(void)
{
    hal_serial_isr(&serial1, SERIAL_EVENT_TX_DMADONE);
    USART_FuncCmd(CM_USART4, (USART_TX | USART_INT_TX_CPLT), DISABLE);
}

#define APP_FRAME_LEN_MAX (500U)

static uint8_t m_au8RxBuf[APP_FRAME_LEN_MAX];
void dma_init(void)
{
    int32_t i32Ret;
    stc_dma_init_t stcDmaInit;
    stc_dma_llp_init_t stcDmaLlpInit;
    stc_irq_signin_config_t stcIrqSignConfig;
    static stc_dma_llp_descriptor_t stcLlpDesc;

    /* DMA&AOS FCG enable */
    FCG_Fcg0PeriphClockCmd(FCG0_PERIPH_DMA2, ENABLE);
    FCG_Fcg0PeriphClockCmd(FCG0_PERIPH_AOS, ENABLE);

    /* USART_TX_DMA */
    (void)DMA_StructInit(&stcDmaInit);
    stcDmaInit.u32IntEn = DMA_INT_ENABLE;
    stcDmaInit.u32BlockSize = 1UL;
    stcDmaInit.u32TransCount = ARRAY_SZ(m_au8RxBuf);
    stcDmaInit.u32DataWidth = DMA_DATAWIDTH_8BIT;
    stcDmaInit.u32DestAddr = (uint32_t)(&CM_USART4->TDR);
    stcDmaInit.u32SrcAddr = (uint32_t)m_au8RxBuf;
    stcDmaInit.u32SrcAddrInc = DMA_SRC_ADDR_INC;
    stcDmaInit.u32DestAddrInc = DMA_DEST_ADDR_FIX;
    i32Ret = DMA_Init(CM_DMA2, DMA_CH0, &stcDmaInit);
    if (LL_OK == i32Ret) {
        stcIrqSignConfig.enIntSrc = INT_SRC_DMA2_TC0;
        stcIrqSignConfig.enIRQn = INT007_IRQn;
        stcIrqSignConfig.pfnCallback = &TX_DMA_TC_IrqCallback;
        (void)INTC_IrqSignIn(&stcIrqSignConfig);
        NVIC_ClearPendingIRQ(stcIrqSignConfig.enIRQn);
        NVIC_SetPriority(stcIrqSignConfig.enIRQn, DDL_IRQ_PRIO_DEFAULT);
        NVIC_EnableIRQ(stcIrqSignConfig.enIRQn);

        AOS_SetTriggerEventSrc(AOS_DMA2_0, EVT_SRC_USART4_TI);

        DMA_Cmd(CM_DMA2, ENABLE);
        DMA_TransCompleteIntCmd(CM_DMA2, DMA_INT_TC_CH0, ENABLE);
    }
}

static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg)
{
    stc_usart_uart_init_t stcUartInit;
    stc_irq_signin_config_t stcIrqSigninConfig;
    struct wl32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    uart = (struct wl32_uart*)serial->parent.user_data;

    LL_PERIPH_WE(LL_PERIPH_SEL);

    if (uart->uart_periph == (uint32_t)CM_USART4) {
        dma_init();
    }

    /* Configure USART RX/TX pin. */
    GPIO_SetFunc(uart->rx_port, uart->rx_pin, uart->rx_af);
    GPIO_SetFunc(uart->tx_port, uart->tx_pin, uart->tx_af);

    /* Enable peripheral clock */
    FCG_Fcg3PeriphClockCmd(uart->per_clk, ENABLE);

    /* Initialize UART. */
    (void)USART_UART_StructInit(&stcUartInit);

    stcUartInit.u32Baudrate = cfg->baud_rate;
    switch (cfg->data_bits) {
    case DATA_BITS_9:
        stcUartInit.u32DataWidth = USART_DATA_WIDTH_9BIT;
        break;

    default:
        stcUartInit.u32DataWidth = USART_DATA_WIDTH_8BIT;
        break;
    }

    switch (cfg->stop_bits) {
    case STOP_BITS_2:
        stcUartInit.u32StopBit = USART_STOPBIT_2BIT;
        break;
    default:
        stcUartInit.u32StopBit = USART_STOPBIT_1BIT;
        break;
    }
    switch (cfg->parity) {
    case PARITY_ODD:
        stcUartInit.u32Parity = USART_PARITY_ODD;
        break;
    case PARITY_EVEN:
        stcUartInit.u32Parity = USART_PARITY_EVEN;
        break;
    default:
        stcUartInit.u32Parity = USART_PARITY_NONE;
        break;
    }

    stcUartInit.u32ClockDiv = USART_CLK_DIV64;
    stcUartInit.u32OverSampleBit = USART_OVER_SAMPLE_8BIT;
    if (LL_OK != USART_UART_Init(uart->uart_periph, &stcUartInit, NULL)) {
        // BSP_LED_On(LED_RED);
        for (;;) {
        }
    }

    if (uart->uart_periph == (uint32_t)CM_USART4) {
        stcIrqSigninConfig.enIRQn = INT009_IRQn;
        stcIrqSigninConfig.enIntSrc = INT_SRC_USART4_TCI;
        stcIrqSigninConfig.pfnCallback = &USART_TxComplete_IrqCallback;
        (void)INTC_IrqSignIn(&stcIrqSigninConfig);
        NVIC_ClearPendingIRQ(stcIrqSigninConfig.enIRQn);
        NVIC_SetPriority(stcIrqSigninConfig.enIRQn, DDL_IRQ_PRIO_DEFAULT);
        NVIC_EnableIRQ(stcIrqSigninConfig.enIRQn);
    }

    /* Register RX full IRQ handler && configure NVIC. */
    stcIrqSigninConfig.enIRQn = uart->rx_full_irqn;
    stcIrqSigninConfig.enIntSrc = uart->rx_full_int_src;
    stcIrqSigninConfig.pfnCallback = uart->rx_full_irq_call_back;
    INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);
    NVIC_ClearPendingIRQ(stcIrqSigninConfig.enIRQn);
    NVIC_SetPriority(stcIrqSigninConfig.enIRQn, DDL_IRQ_PRIO_DEFAULT);
    NVIC_DisableIRQ(stcIrqSigninConfig.enIRQn);

    if (uart->rx_timo_irq_call_back != NULL) {
        /* Register RX full IRQ handler && configure NVIC. */
        stcIrqSigninConfig.enIRQn = uart->rx_timo_irqn;
        stcIrqSigninConfig.enIntSrc = uart->rx_timo_int_src;
        stcIrqSigninConfig.pfnCallback = uart->rx_timo_irq_call_back;
        INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);
        NVIC_ClearPendingIRQ(stcIrqSigninConfig.enIRQn);
        NVIC_SetPriority(stcIrqSigninConfig.enIRQn, DDL_IRQ_PRIO_DEFAULT);
        NVIC_DisableIRQ(stcIrqSigninConfig.enIRQn);
    }
    /* MCU Peripheral registers write protected */
    LL_PERIPH_WP(LL_PERIPH_SEL);

    if (uart->uart_periph == (uint32_t)CM_USART4) {
        USART_FuncCmd((CM_USART_TypeDef*)uart->uart_periph, (USART_RX | USART_INT_RX), ENABLE);
        drv_usart_task_run = 0;
        return RT_EOK;
    }
    /* Enable RX/TX function */
    if (uart->rx_timo_irq_call_back != NULL)
        USART_FuncCmd((CM_USART_TypeDef*)uart->uart_periph, (USART_RX | USART_INT_RX | USART_TX | USART_RX_TIMEOUT), ENABLE);
    else
        USART_FuncCmd((CM_USART_TypeDef*)uart->uart_periph, (USART_RX | USART_INT_RX | USART_TX), ENABLE);
    drv_usart_task_run = 0;
    return RT_EOK;
}
static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg)
{
    struct wl32_uart* uart;
    rt_uint32_t ctrl_arg = (rt_uint32_t)(arg);

    RT_ASSERT(serial != RT_NULL);
    uart = (struct wl32_uart*)serial->parent.user_data;
    LL_PERIPH_WE(LL_PERIPH_SEL);

    switch (cmd) {
    case RT_DEVICE_CTRL_CLR_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {

            NVIC_ClearPendingIRQ(uart->rx_full_irqn);
            NVIC_DisableIRQ(uart->rx_full_irqn);

            if (uart->rx_timo_irq_call_back != NULL) {
                drv_usart_task_run = 0;
                NVIC_ClearPendingIRQ(uart->rx_timo_irqn);
                NVIC_DisableIRQ(uart->rx_timo_irqn);
            }
        }
        break;

    case RT_DEVICE_CTRL_SET_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {

            NVIC_ClearPendingIRQ(uart->rx_full_irqn);
            NVIC_EnableIRQ(uart->rx_full_irqn);

            if (uart->rx_timo_irq_call_back != NULL) {
                drv_usart_task_run = 1;
                NVIC_ClearPendingIRQ(uart->rx_timo_irqn);
                NVIC_EnableIRQ(uart->rx_timo_irqn);
            }
        }
        break;

        /* USART DMA config */
    case RT_DEVICE_CTRL_CONFIG:
        break;

    case RT_DEVICE_CTRL_SUSPEND:
        NVIC_ClearPendingIRQ(uart->rx_full_irqn);
        NVIC_DisableIRQ(uart->rx_full_irqn);
        if (uart->rx_timo_irq_call_back != NULL) {
            drv_usart_task_run = 0;
            NVIC_ClearPendingIRQ(uart->rx_timo_irqn);
            NVIC_DisableIRQ(uart->rx_timo_irqn);
        }
        //_close_usart(serial);
        break;

    default:
        break;
    }

    LL_PERIPH_WP(LL_PERIPH_SEL);
    return RT_EOK;
}

static int usart_putc(struct serial_device* serial, char ch)
{
    struct wl32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct wl32_uart*)serial->parent.user_data;

    /* Wait Tx data register empty */
    while (RESET == USART_GetStatus((CM_USART_TypeDef*)uart->uart_periph, USART_FLAG_TX_EMPTY)) {
    }
    USART_WriteData((CM_USART_TypeDef*)uart->uart_periph, ch);

    return RT_EOK;
}

static volatile uint8_t tmp_rx_buf[100] = { 0 };
static volatile uint8_t tmp_rx_add = 0;
static int usart_getc(struct serial_device* serial)
{
    int ch = -1;
    struct wl32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct wl32_uart*)serial->parent.user_data;

    if (SET == USART_GetStatus((CM_USART_TypeDef*)uart->uart_periph, USART_FLAG_RX_FULL)) {
        ch = USART_ReadData((CM_USART_TypeDef*)uart->uart_periph);
        tmp_rx_buf[tmp_rx_add] = ch;
        if (++tmp_rx_add >= 100)
            tmp_rx_add = 0;
    }

    return ch;
}
uint8_t tmp_dma_sendddd[] = "hello word\n";
void tmp_dma_send(uint8_t* buf, uint32_t size)
{
    DMA_SetSrcAddr(CM_DMA2, DMA_CH0, (uint32_t)buf);

    DMA_SetTransCount(CM_DMA2, DMA_CH0, size);

    (void)DMA_ChCmd(CM_DMA2, DMA_CH0, ENABLE);

    USART_FuncCmd(CM_USART4, USART_TX, ENABLE);
}
static rt_size_t usart_dma_transmit(struct serial_device* serial, rt_uint8_t* buf, rt_size_t size, int direction)
{
    tmp_dma_send(buf, size);
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

rt_err_t drv_usart_init(void)
{
    rt_err_t rt_err = RT_EOK;
    struct serial_configure config = SERIAL_DEFAULT_CONFIG;

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
                                  &uart1);
#endif /* USING_UART5 */

    return rt_err;
}
