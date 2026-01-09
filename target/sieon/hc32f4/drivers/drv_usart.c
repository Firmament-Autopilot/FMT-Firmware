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
#define USING_UART2

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
    struct hc32_uart_dma {
        /* dma instance */
        CM_DMA_TypeDef* dma_periph;
        // /* rx dma chan */
        // uint8_t dma_rx_ch;
        // uint32_t dma_rx_tc_int;
        // uint32_t dma_rx_reconfig_trig_sel;
        // en_event_src_t dma_rx_reconfig_trig_evt_src;
        // uint32_t dma_rx_rc_flag;
        // uint32_t dma_rx_trig_sel;
        // en_event_src_t dma_rx_trig_evt_src;
        // en_int_src_t dma_rx_tc_int_src;
        /* tx dma chan */
        uint8_t dma_tx_ch;
        en_int_src_t dma_tx_tc_int_src;
        uint32_t dma_tx_tc_flag;
        IRQn_Type dma_tx_tc_irq;
        uint32_t dma_tx_trig_sel;
        en_event_src_t dma_tx_trig_evt_src;
        uint32_t dma_tx_tc_int;
    } dma;
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

#ifdef USING_UART2
static struct serial_device serial2;
static struct hc32_uart uart2 = {
    .uart_periph = CM_USART2,
    .dma = {
        .dma_periph = CM_DMA1,
        .dma_tx_ch = DMA_CH0,
        .dma_tx_tc_int_src = INT_SRC_DMA1_TC0,
        .dma_tx_tc_flag = DMA_FLAG_TC_CH0,
        .dma_tx_tc_irq = INT004_IRQn,
        .dma_tx_trig_sel = AOS_DMA1_0,
        .dma_tx_trig_evt_src = EVT_SRC_USART2_TI,
        .dma_tx_tc_int = DMA_INT_TC_CH0,
        // .dma_rx_ch = DMA_CH0,
        // .dma_rx_tc_int = DMA_INT_TC_CH0,
        // .dma_rx_reconfig_trig_sel = AOS_DMA_RC,
        // .dma_rx_reconfig_trig_evt_src = EVT_SRC_AOS_STRG,
        // .dma_rx_rc_flag = DMA_FLAG_TC_CH0,
        // .dma_rx_trig_sel = AOS_DMA1_0,
        // .dma_rx_trig_evt_src = EVT_SRC_USART2_RI,
        // .dma_rx_tc_int_src = INT_SRC_DMA1_TC0,
    }
};

static void USART2_RxError_IrqCallback(void)
{
    rt_interrupt_enter();
    (void)USART_ReadData(uart2.uart_periph);
    USART_ClearStatus(uart2.uart_periph, (USART_FLAG_PARITY_ERR | USART_FLAG_FRAME_ERR | USART_FLAG_OVERRUN));
    rt_interrupt_leave();
}

static void USART2_RxFull_IrqCallback(void)
{
    rt_interrupt_enter();
    hal_serial_isr(&serial2, SERIAL_EVENT_RX_IND);
    rt_interrupt_leave();
}

static void USART2_TX_DMA_TC_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart2.uart_periph, USART_INT_TX_CPLT, ENABLE);
    DMA_ClearTransCompleteStatus(uart2.dma.dma_periph, uart2.dma.dma_tx_tc_flag);
    rt_interrupt_leave();
}

static void USART2_TxComplete_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart2.uart_periph, (USART_TX | USART_INT_TX_CPLT), DISABLE);
    hal_serial_isr(&serial2, SERIAL_EVENT_TX_DMADONE);
    rt_interrupt_leave();
}

// static void USART2_RX_DMA_TC_IrqCallback(void)
// {
//     // m_enRxFrameEnd = SET;
//     // m_u16RxLen = APP_FRAME_LEN_MAX;

//     rt_size_t recv_len = DMA_GetTransCount(uart2.dma.dma_periph, uart2.dma.dma_rx_ch);

//     USART_FuncCmd(uart2.uart_periph, USART_RX_TIMEOUT, DISABLE);

//     DMA_ClearTransCompleteStatus(uart2.dma.dma_periph, uart2.dma.dma_rx_rc_flag);

//     if (recv_len) {
//         /* high-level ISR routine */
//         hal_serial_isr(&serial2, SERIAL_EVENT_RX_DMADONE | (recv_len << 8));
//     }
// }
#endif

/**
 * @brief  Instal IRQ handler.
 * @param  [in] pstcConfig      Pointer to struct @ref stc_irq_signin_config_t
 * @param  [in] u32Priority     Interrupt priority
 * @retval None
 */
static void INTC_IrqInstalHandler(const stc_irq_signin_config_t* pstcConfig, uint32_t u32Priority)
{
    if (NULL != pstcConfig) {
        (void)INTC_IrqSignIn(pstcConfig);
        NVIC_ClearPendingIRQ(pstcConfig->enIRQn);
        NVIC_SetPriority(pstcConfig->enIRQn, u32Priority);
        NVIC_EnableIRQ(pstcConfig->enIRQn);
    }
}

static uint8_t m_au8RxBuf[500];
static void dma_tx_config(struct hc32_uart* uart)
{
    int32_t i32Ret;
    stc_dma_init_t stcDmaInit;
    // stc_dma_llp_init_t stcDmaLlpInit;
    stc_irq_signin_config_t stcIrqSignConfig;
    // static stc_dma_llp_descriptor_t stcLlpDesc;

    /* USART_TX_DMA */
    (void)DMA_StructInit(&stcDmaInit);
    stcDmaInit.u32IntEn = DMA_INT_ENABLE;
    stcDmaInit.u32BlockSize = 1;
    stcDmaInit.u32TransCount = 500;
    stcDmaInit.u32DataWidth = DMA_DATAWIDTH_8BIT;
    stcDmaInit.u32DestAddr = (uint32_t)(&uart->uart_periph->TDR);
    stcDmaInit.u32SrcAddr = (uint32_t)m_au8RxBuf;
    stcDmaInit.u32SrcAddrInc = DMA_SRC_ADDR_INC;
    stcDmaInit.u32DestAddrInc = DMA_DEST_ADDR_FIX;
    i32Ret = DMA_Init(uart->dma.dma_periph, uart->dma.dma_tx_ch, &stcDmaInit);
    if (LL_OK == i32Ret) {
        stcIrqSignConfig.enIntSrc = uart->dma.dma_tx_tc_int_src;
        stcIrqSignConfig.enIRQn = uart->dma.dma_tx_tc_irq;
        stcIrqSignConfig.pfnCallback = &USART2_TX_DMA_TC_IrqCallback;
        (void)INTC_IrqSignIn(&stcIrqSignConfig);
        NVIC_ClearPendingIRQ(stcIrqSignConfig.enIRQn);
        NVIC_SetPriority(stcIrqSignConfig.enIRQn, DDL_IRQ_PRIO_DEFAULT);
        NVIC_EnableIRQ(stcIrqSignConfig.enIRQn);

        AOS_SetTriggerEventSrc(uart->dma.dma_tx_trig_sel, uart->dma.dma_tx_trig_evt_src);

        DMA_Cmd(uart->dma.dma_periph, ENABLE);
        DMA_TransCompleteIntCmd(uart->dma.dma_periph, uart->dma.dma_tx_tc_int, ENABLE);
    }
}

static void dma_rx_config(struct hc32_uart* uart, rt_uint8_t* buf, rt_size_t size)
{
    // int32_t i32Ret;
    // stc_dma_init_t stcDmaInit;
    // stc_dma_llp_init_t stcDmaLlpInit;
    // stc_irq_signin_config_t stcIrqSignConfig;
    // static stc_dma_llp_descriptor_t stcLlpDesc;

    // /* USART_RX_DMA */
    // (void)DMA_StructInit(&stcDmaInit);
    // stcDmaInit.u32IntEn = DMA_INT_ENABLE;
    // stcDmaInit.u32BlockSize = 1UL;
    // stcDmaInit.u32TransCount = size;
    // stcDmaInit.u32DataWidth = DMA_DATAWIDTH_8BIT;
    // stcDmaInit.u32DestAddr = (uint32_t)buf;
    // stcDmaInit.u32SrcAddr = (uint32_t)(&uart->uart_periph->RDR);
    // stcDmaInit.u32SrcAddrInc = DMA_SRC_ADDR_FIX;
    // stcDmaInit.u32DestAddrInc = DMA_DEST_ADDR_INC;
    // i32Ret = DMA_Init(uart->dma.dma_periph, uart->dma.dma_rx_ch, &stcDmaInit);
    // if (LL_OK == i32Ret) {
    //     (void)DMA_LlpStructInit(&stcDmaLlpInit);
    //     stcDmaLlpInit.u32State = DMA_LLP_ENABLE;
    //     stcDmaLlpInit.u32Mode = DMA_LLP_WAIT;
    //     stcDmaLlpInit.u32Addr = (uint32_t)&stcLlpDesc;
    //     (void)DMA_LlpInit(uart->dma.dma_periph, uart->dma.dma_rx_ch, &stcDmaLlpInit);

    //     stcLlpDesc.SARx = stcDmaInit.u32SrcAddr;
    //     stcLlpDesc.DARx = stcDmaInit.u32DestAddr;
    //     stcLlpDesc.DTCTLx = (stcDmaInit.u32TransCount << DMA_DTCTL_CNT_POS) | (stcDmaInit.u32BlockSize << DMA_DTCTL_BLKSIZE_POS);
    //     stcLlpDesc.LLPx = (uint32_t)&stcLlpDesc;
    //     stcLlpDesc.CHCTLx = stcDmaInit.u32SrcAddrInc | stcDmaInit.u32DestAddrInc | stcDmaInit.u32DataWidth | stcDmaInit.u32IntEn | stcDmaLlpInit.u32State | stcDmaLlpInit.u32Mode;

    //     // DMA_ReconfigLlpCmd(uart->dma.dma_periph, uart->dma.dma_rx_ch, ENABLE);
    //     // DMA_ReconfigCmd(uart->dma.dma_periph, ENABLE);
    //     // AOS_SetTriggerEventSrc(uart->dma.dma_rx_reconfig_trig_sel, uart->dma.dma_rx_reconfig_trig_evt_src);

    //     stcIrqSignConfig.enIntSrc = uart->dma.dma_rx_tc_int_src;
    //     stcIrqSignConfig.enIRQn = INT004_IRQn;
    //     stcIrqSignConfig.pfnCallback = &USART2_RX_DMA_TC_IrqCallback;
    //     (void)INTC_IrqSignIn(&stcIrqSignConfig);
    //     NVIC_ClearPendingIRQ(stcIrqSignConfig.enIRQn);
    //     NVIC_SetPriority(stcIrqSignConfig.enIRQn, DDL_IRQ_PRIO_DEFAULT);
    //     NVIC_EnableIRQ(stcIrqSignConfig.enIRQn);

    //     AOS_SetTriggerEventSrc(uart->dma.dma_rx_trig_sel, uart->dma.dma_rx_trig_evt_src);

    //     DMA_Cmd(uart->dma.dma_periph, ENABLE);
    //     DMA_TransCompleteIntCmd(uart->dma.dma_periph, uart->dma.dma_rx_tc_int, ENABLE);
    //     (void)DMA_ChCmd(uart->dma.dma_periph, uart->dma.dma_rx_ch, ENABLE);
    // }
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
    (void)uart;

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
        if (ctrl_arg == RT_DEVICE_FLAG_DMA_TX) {
            struct hc32_uart* uart = (struct hc32_uart*)serial->parent.user_data;

            // if (LL_DMA_IsEnabledStream(uart->dma.dma_device, uart->dma.tx_stream)) {
            //     /* dma is busy */
            //     return RT_EBUSY;
            // }

            /* the USART_TX cmd will be enabled when dma configured */
            USART_FuncCmd(uart2.uart_periph, (USART_TX | USART_INT_TX_CPLT), DISABLE);

            dma_tx_config(uart);
        }
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
    if (direction == SERIAL_DMA_TX && size > 0) {
        struct hc32_uart* uart = (struct hc32_uart*)serial->parent.user_data;
        uint16_t trimmed_size = size > 65535 ? 65535 : size; /* the maximul dma transfer block is 65535 */

        DMA_SetSrcAddr(uart->dma.dma_periph, uart->dma.dma_tx_ch, (uint32_t)buf);
        DMA_SetTransCount(uart->dma.dma_periph, uart->dma.dma_tx_ch, trimmed_size);
        DMA_ChCmd(uart->dma.dma_periph, uart->dma.dma_tx_ch, ENABLE);
        USART_FuncCmd(uart->uart_periph, USART_TX, ENABLE);

        return trimmed_size;
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

static void uart_peripheral_init(void)
{
    stc_irq_signin_config_t stcIrqSigninConfig;

    /* MCU Peripheral registers write unprotected */
    // LL_PERIPH_WE(LL_PERIPH_ALL);

    /* DMA&AOS FCG enable */
    FCG_Fcg0PeriphClockCmd(FCG0_PERIPH_DMA1, ENABLE);
    FCG_Fcg0PeriphClockCmd(FCG0_PERIPH_DMA2, ENABLE);
    FCG_Fcg0PeriphClockCmd(FCG0_PERIPH_AOS, ENABLE);

    /* USART6 Init */
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

    /* USART2 Init */
    GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_05, GPIO_FUNC_20); // USART2-TX
    GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_06, GPIO_FUNC_20); // USART2-RX

    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART2, ENABLE);

    /* Register RX error IRQ handler && configure NVIC. */
    stcIrqSigninConfig.enIRQn = INT002_IRQn;
    stcIrqSigninConfig.enIntSrc = INT_SRC_USART2_EI;
    stcIrqSigninConfig.pfnCallback = &USART2_RxError_IrqCallback;
    INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);

    /* Register RX full IRQ handler && configure NVIC. */
    stcIrqSigninConfig.enIRQn = INT003_IRQn;
    stcIrqSigninConfig.enIntSrc = INT_SRC_USART2_RI;
    stcIrqSigninConfig.pfnCallback = &USART2_RxFull_IrqCallback;
    INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);

    stcIrqSigninConfig.enIRQn = INT005_IRQn;
    stcIrqSigninConfig.enIntSrc = INT_SRC_USART2_TCI;
    stcIrqSigninConfig.pfnCallback = &USART2_TxComplete_IrqCallback;
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
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_TX,
                                  &uart2);
#endif /* USING_UART2 */

    return rt_err;
}
