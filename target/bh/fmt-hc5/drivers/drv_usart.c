/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

#define USING_UART1
#define USING_UART2
#define USING_UART3
#define USING_UART4
#define USING_UART5
#define USING_UART7
#define USING_UART8

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
    IRQn_Type rx_err_irq;
    en_int_src_t rx_err_int_src;
    func_ptr_t rx_err_callback;
    IRQn_Type rx_full_irq;
    en_int_src_t rx_full_int_src;
    func_ptr_t rx_full_callback;
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
        IRQn_Type dma_tx_tc_irq;
        en_int_src_t dma_tx_tc_int_src;
        func_ptr_t dma_tx_tc_callback;
        uint32_t dma_tx_tc_flag;
        uint32_t dma_tx_trig_sel;
        en_event_src_t dma_tx_trig_evt_src;
        uint32_t dma_tx_tc_int;
        IRQn_Type tx_cplt_irq;
        en_int_src_t tx_cplt_int_src;
        func_ptr_t tx_cplt_callback;
    } dma;
};

#ifdef USING_UART5
static void USART5_RxError_IrqCallback(void);
static void USART5_RxFull_IrqCallback(void);

static struct serial_device serial0;
static struct hc32_uart uart5 = {
    .uart_periph = CM_USART5,
    .rx_err_irq = USART5_RX_ERR_IRQn,
    .rx_err_int_src = INT_SRC_USART5_EI,
    .rx_err_callback = &USART5_RxError_IrqCallback,
    .rx_full_irq = USART5_RX_FULL_IRQn,
    .rx_full_int_src = INT_SRC_USART5_RI,
    .rx_full_callback = &USART5_RxFull_IrqCallback,
};

static void USART5_RxError_IrqCallback(void)
{
    rt_interrupt_enter();
    (void)USART_ReadData(uart5.uart_periph);
    USART_ClearStatus(uart5.uart_periph, (USART_FLAG_PARITY_ERR | USART_FLAG_FRAME_ERR | USART_FLAG_OVERRUN));
    rt_interrupt_leave();
}

static void USART5_RxFull_IrqCallback(void)
{
    rt_interrupt_enter();
    hal_serial_isr(&serial0, SERIAL_EVENT_RX_IND);
    rt_interrupt_leave();
}
#endif

#ifdef USING_UART7
static void USART7_RxError_IrqCallback(void);
static void USART7_RxFull_IrqCallback(void);
static void USART7_TX_DMA_TC_IrqCallback(void);
static void USART7_TxComplete_IrqCallback(void);

static struct serial_device serial1;
static struct hc32_uart uart7 = {
    .uart_periph = CM_USART7,
    .rx_err_irq = USART7_RX_ERR_IRQn,
    .rx_err_int_src = INT_SRC_USART7_EI,
    .rx_err_callback = &USART7_RxError_IrqCallback,
    .rx_full_irq = USART7_RX_FULL_IRQn,
    .rx_full_int_src = INT_SRC_USART7_RI,
    .rx_full_callback = &USART7_RxFull_IrqCallback,
    .dma = {
        .dma_periph = USART7_TX_DMA_UNIT,
        .dma_tx_ch = USART7_TX_DMA_CH,
        .dma_tx_tc_irq = USART7_TX_DMA_TC_IRQn,
        .dma_tx_tc_int_src = USART7_TX_DMA_TC_INT_SRC,
        .dma_tx_tc_callback = &USART7_TX_DMA_TC_IrqCallback,
        .dma_tx_tc_flag = USART7_TX_DMA_TC_FLAG,
        .dma_tx_trig_sel = USART7_TX_DMA_TRIG_SEL,
        .dma_tx_trig_evt_src = EVT_SRC_USART7_TI,
        .dma_tx_tc_int = USART7_TX_DMA_TC_INT,
        .tx_cplt_irq = USART7_TX_CPLT_IRQn,
        .tx_cplt_int_src = INT_SRC_USART7_TCI,
        .tx_cplt_callback = &USART7_TxComplete_IrqCallback,
    }
};

static void USART7_RxError_IrqCallback(void)
{
    rt_interrupt_enter();
    (void)USART_ReadData(uart7.uart_periph);
    USART_ClearStatus(uart7.uart_periph, (USART_FLAG_PARITY_ERR | USART_FLAG_FRAME_ERR | USART_FLAG_OVERRUN));
    rt_interrupt_leave();
}

static void USART7_RxFull_IrqCallback(void)
{
    rt_interrupt_enter();
    hal_serial_isr(&serial1, SERIAL_EVENT_RX_IND);
    rt_interrupt_leave();
}

static void USART7_TX_DMA_TC_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart7.uart_periph, USART_INT_TX_CPLT, ENABLE);
    DMA_ClearTransCompleteStatus(uart7.dma.dma_periph, uart7.dma.dma_tx_tc_flag);
    rt_interrupt_leave();
}

static void USART7_TxComplete_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart7.uart_periph, (USART_TX | USART_INT_TX_CPLT), DISABLE);
    hal_serial_isr(&serial1, SERIAL_EVENT_TX_DMADONE);
    rt_interrupt_leave();
}
#endif

#ifdef USING_UART3
static void USART3_RxError_IrqCallback(void);
static void USART3_RxFull_IrqCallback(void);
static void USART3_TX_DMA_TC_IrqCallback(void);
static void USART3_TxComplete_IrqCallback(void);

static struct serial_device serial3;
static struct hc32_uart uart3 = {
    .uart_periph = CM_USART3,
    .rx_err_irq = USART3_RX_ERR_IRQn,
    .rx_err_int_src = INT_SRC_USART3_EI,
    .rx_err_callback = &USART3_RxError_IrqCallback,
    .rx_full_irq = USART3_RX_FULL_IRQn,
    .rx_full_int_src = INT_SRC_USART3_RI,
    .rx_full_callback = &USART3_RxFull_IrqCallback,
    .dma = {
        .dma_periph = USART3_TX_DMA_UNIT,
        .dma_tx_ch = USART3_TX_DMA_CH,
        .dma_tx_tc_irq = USART3_TX_DMA_TC_IRQn,
        .dma_tx_tc_int_src = USART3_TX_DMA_TC_INT_SRC,
        .dma_tx_tc_callback = &USART3_TX_DMA_TC_IrqCallback,
        .dma_tx_tc_flag = USART3_TX_DMA_TC_FLAG,
        .dma_tx_trig_sel = USART3_TX_DMA_TRIG_SEL,
        .dma_tx_trig_evt_src = EVT_SRC_USART3_TI,
        .dma_tx_tc_int = USART3_TX_DMA_TC_INT,
        .tx_cplt_irq = USART3_TX_CPLT_IRQn,
        .tx_cplt_int_src = INT_SRC_USART3_TCI,
        .tx_cplt_callback = &USART3_TxComplete_IrqCallback,
    }
};

static void USART3_RxError_IrqCallback(void)
{
    rt_interrupt_enter();
    (void)USART_ReadData(uart3.uart_periph);
    USART_ClearStatus(uart3.uart_periph, (USART_FLAG_PARITY_ERR | USART_FLAG_FRAME_ERR | USART_FLAG_OVERRUN));
    rt_interrupt_leave();
}

static void USART3_RxFull_IrqCallback(void)
{
    rt_interrupt_enter();
    hal_serial_isr(&serial3, SERIAL_EVENT_RX_IND);
    rt_interrupt_leave();
}

static void USART3_TX_DMA_TC_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart3.uart_periph, USART_INT_TX_CPLT, ENABLE);
    DMA_ClearTransCompleteStatus(uart3.dma.dma_periph, uart3.dma.dma_tx_tc_flag);
    rt_interrupt_leave();
}

static void USART3_TxComplete_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart3.uart_periph, (USART_TX | USART_INT_TX_CPLT), DISABLE);
    hal_serial_isr(&serial3, SERIAL_EVENT_TX_DMADONE);
    rt_interrupt_leave();
}
#endif

#ifdef USING_UART2
static void USART2_RxError_IrqCallback(void);
static void USART2_RxFull_IrqCallback(void);
static void USART2_TX_DMA_TC_IrqCallback(void);
static void USART2_TxComplete_IrqCallback(void);

static struct serial_device serial2;
static struct hc32_uart uart2 = {
    .uart_periph = CM_USART2,
    .rx_err_irq = USART2_RX_ERR_IRQn,
    .rx_err_int_src = INT_SRC_USART2_EI,
    .rx_err_callback = &USART2_RxError_IrqCallback,
    .rx_full_irq = USART2_RX_FULL_IRQn,
    .rx_full_int_src = INT_SRC_USART2_RI,
    .rx_full_callback = &USART2_RxFull_IrqCallback,
    .dma = {
        // .dma_rx_ch = DMA_CH0,
        // .dma_rx_tc_int = DMA_INT_TC_CH0,
        // .dma_rx_reconfig_trig_sel = AOS_DMA_RC,
        // .dma_rx_reconfig_trig_evt_src = EVT_SRC_AOS_STRG,
        // .dma_rx_rc_flag = DMA_FLAG_TC_CH0,
        // .dma_rx_trig_sel = AOS_DMA1_0,
        // .dma_rx_trig_evt_src = EVT_SRC_USART2_RI,
        // .dma_rx_tc_int_src = INT_SRC_DMA1_TC0,
        .dma_periph = USART2_TX_DMA_UNIT,
        .dma_tx_ch = USART2_TX_DMA_CH,
        .dma_tx_tc_irq = USART2_TX_DMA_TC_IRQn,
        .dma_tx_tc_int_src = USART2_TX_DMA_TC_INT_SRC,
        .dma_tx_tc_callback = &USART2_TX_DMA_TC_IrqCallback,
        .dma_tx_tc_flag = USART2_TX_DMA_TC_FLAG,
        .dma_tx_trig_sel = USART2_TX_DMA_TRIG_SEL,
        .dma_tx_trig_evt_src = EVT_SRC_USART2_TI,
        .dma_tx_tc_int = USART2_TX_DMA_TC_INT,
        .tx_cplt_irq = USART2_TX_CPLT_IRQn,
        .tx_cplt_int_src = INT_SRC_USART2_TCI,
        .tx_cplt_callback = &USART2_TxComplete_IrqCallback,
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

#ifdef USING_UART1
static void USART1_RxError_IrqCallback(void);
static void USART1_RxFull_IrqCallback(void);
static void USART1_TX_DMA_TC_IrqCallback(void);
static void USART1_TxComplete_IrqCallback(void);

static struct serial_device serial4;
static struct hc32_uart uart1 = {
    .uart_periph = CM_USART1,
    .rx_err_irq = USART1_RX_ERR_IRQn,
    .rx_err_int_src = INT_SRC_USART1_EI,
    .rx_err_callback = &USART1_RxError_IrqCallback,
    .rx_full_irq = USART1_RX_FULL_IRQn,
    .rx_full_int_src = INT_SRC_USART1_RI,
    .rx_full_callback = &USART1_RxFull_IrqCallback,
    .dma = {
        .dma_periph = USART1_TX_DMA_UNIT,
        .dma_tx_ch = USART1_TX_DMA_CH,
        .dma_tx_tc_irq = USART1_TX_DMA_TC_IRQn,
        .dma_tx_tc_int_src = USART1_TX_DMA_TC_INT_SRC,
        .dma_tx_tc_callback = &USART1_TX_DMA_TC_IrqCallback,
        .dma_tx_tc_flag = USART1_TX_DMA_TC_FLAG,
        .dma_tx_trig_sel = USART1_TX_DMA_TRIG_SEL,
        .dma_tx_trig_evt_src = EVT_SRC_USART1_TI,
        .dma_tx_tc_int = USART1_TX_DMA_TC_INT,
        .tx_cplt_irq = USART1_TX_CPLT_IRQn,
        .tx_cplt_int_src = INT_SRC_USART1_TCI,
        .tx_cplt_callback = &USART1_TxComplete_IrqCallback,
    }
};

static void USART1_RxError_IrqCallback(void)
{
    rt_interrupt_enter();
    (void)USART_ReadData(uart1.uart_periph);
    USART_ClearStatus(uart1.uart_periph, (USART_FLAG_PARITY_ERR | USART_FLAG_FRAME_ERR | USART_FLAG_OVERRUN));
    rt_interrupt_leave();
}

static void USART1_RxFull_IrqCallback(void)
{
    rt_interrupt_enter();
    hal_serial_isr(&serial4, SERIAL_EVENT_RX_IND);
    rt_interrupt_leave();
}

static void USART1_TX_DMA_TC_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart1.uart_periph, USART_INT_TX_CPLT, ENABLE);
    DMA_ClearTransCompleteStatus(uart1.dma.dma_periph, uart1.dma.dma_tx_tc_flag);
    rt_interrupt_leave();
}

static void USART1_TxComplete_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart1.uart_periph, (USART_TX | USART_INT_TX_CPLT), DISABLE);
    hal_serial_isr(&serial4, SERIAL_EVENT_TX_DMADONE);
    rt_interrupt_leave();
}
#endif

#ifdef USING_UART8
static void USART8_RxError_IrqCallback(void);
static void USART8_RxFull_IrqCallback(void);
static void USART8_TX_DMA_TC_IrqCallback(void);
static void USART8_TxComplete_IrqCallback(void);

static struct serial_device serial5;
static struct hc32_uart uart8 = {
    .uart_periph = CM_USART8,
    .rx_err_irq = USART8_RX_ERR_IRQn,
    .rx_err_int_src = INT_SRC_USART8_EI,
    .rx_err_callback = &USART8_RxError_IrqCallback,
    .rx_full_irq = USART8_RX_FULL_IRQn,
    .rx_full_int_src = INT_SRC_USART8_RI,
    .rx_full_callback = &USART8_RxFull_IrqCallback,
    .dma = {
        .dma_periph = USART8_TX_DMA_UNIT,
        .dma_tx_ch = USART8_TX_DMA_CH,
        .dma_tx_tc_irq = USART8_TX_DMA_TC_IRQn,
        .dma_tx_tc_int_src = USART8_TX_DMA_TC_INT_SRC,
        .dma_tx_tc_callback = &USART8_TX_DMA_TC_IrqCallback,
        .dma_tx_tc_flag = USART8_TX_DMA_TC_FLAG,
        .dma_tx_trig_sel = USART8_TX_DMA_TRIG_SEL,
        .dma_tx_trig_evt_src = EVT_SRC_USART8_TI,
        .dma_tx_tc_int = USART8_TX_DMA_TC_INT,
        .tx_cplt_irq = USART8_TX_CPLT_IRQn,
        .tx_cplt_int_src = INT_SRC_USART8_TCI,
        .tx_cplt_callback = &USART8_TxComplete_IrqCallback,
    }
};

static void USART8_RxError_IrqCallback(void)
{
    rt_interrupt_enter();
    (void)USART_ReadData(uart8.uart_periph);
    USART_ClearStatus(uart8.uart_periph, (USART_FLAG_PARITY_ERR | USART_FLAG_FRAME_ERR | USART_FLAG_OVERRUN));
    rt_interrupt_leave();
}

static void USART8_RxFull_IrqCallback(void)
{
    rt_interrupt_enter();
    hal_serial_isr(&serial5, SERIAL_EVENT_RX_IND);
    rt_interrupt_leave();
}

static void USART8_TX_DMA_TC_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart8.uart_periph, USART_INT_TX_CPLT, ENABLE);
    DMA_ClearTransCompleteStatus(uart8.dma.dma_periph, uart8.dma.dma_tx_tc_flag);
    rt_interrupt_leave();
}

static void USART8_TxComplete_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart8.uart_periph, (USART_TX | USART_INT_TX_CPLT), DISABLE);
    hal_serial_isr(&serial5, SERIAL_EVENT_TX_DMADONE);
    rt_interrupt_leave();
}
#endif

#ifdef USING_UART4
static void USART4_RxError_IrqCallback(void);
static void USART4_RxFull_IrqCallback(void);
static void USART4_TX_DMA_TC_IrqCallback(void);
static void USART4_TxComplete_IrqCallback(void);

static struct serial_device serial6;
static struct hc32_uart uart4 = {
    .uart_periph = CM_USART4,
    .rx_err_irq = USART4_RX_ERR_IRQn,
    .rx_err_int_src = INT_SRC_USART4_EI,
    .rx_err_callback = &USART4_RxError_IrqCallback,
    .rx_full_irq = USART4_RX_FULL_IRQn,
    .rx_full_int_src = INT_SRC_USART4_RI,
    .rx_full_callback = &USART4_RxFull_IrqCallback,
    .dma = {
        .dma_periph = USART4_TX_DMA_UNIT,
        .dma_tx_ch = USART4_TX_DMA_CH,
        .dma_tx_tc_irq = USART4_TX_DMA_TC_IRQn,
        .dma_tx_tc_int_src = USART4_TX_DMA_TC_INT_SRC,
        .dma_tx_tc_callback = &USART4_TX_DMA_TC_IrqCallback,
        .dma_tx_tc_flag = USART4_TX_DMA_TC_FLAG,
        .dma_tx_trig_sel = USART4_TX_DMA_TRIG_SEL,
        .dma_tx_trig_evt_src = EVT_SRC_USART4_TI,
        .dma_tx_tc_int = USART4_TX_DMA_TC_INT,
        .tx_cplt_irq = USART4_TX_CPLT_IRQn,
        .tx_cplt_int_src = INT_SRC_USART4_TCI,
        .tx_cplt_callback = &USART4_TxComplete_IrqCallback,
    }
};

static void USART4_RxError_IrqCallback(void)
{
    rt_interrupt_enter();
    (void)USART_ReadData(uart4.uart_periph);
    USART_ClearStatus(uart4.uart_periph, (USART_FLAG_PARITY_ERR | USART_FLAG_FRAME_ERR | USART_FLAG_OVERRUN));
    rt_interrupt_leave();
}

static void USART4_RxFull_IrqCallback(void)
{
    rt_interrupt_enter();
    hal_serial_isr(&serial6, SERIAL_EVENT_RX_IND);
    rt_interrupt_leave();
}

static void USART4_TX_DMA_TC_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart4.uart_periph, USART_INT_TX_CPLT, ENABLE);
    DMA_ClearTransCompleteStatus(uart4.dma.dma_periph, uart4.dma.dma_tx_tc_flag);
    rt_interrupt_leave();
}

static void USART4_TxComplete_IrqCallback(void)
{
    rt_interrupt_enter();
    USART_FuncCmd(uart4.uart_periph, (USART_TX | USART_INT_TX_CPLT), DISABLE);
    hal_serial_isr(&serial6, SERIAL_EVENT_TX_DMADONE);
    rt_interrupt_leave();
}
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

static void dma_tx_config(struct hc32_uart* uart)
{
    int32_t i32Ret;
    stc_dma_init_t stcDmaInit;
    stc_irq_signin_config_t stcIrqSigninConfig;

    /* USART_TX_DMA */
    (void)DMA_StructInit(&stcDmaInit);
    stcDmaInit.u32IntEn = DMA_INT_ENABLE;
    stcDmaInit.u32BlockSize = 1;
    stcDmaInit.u32TransCount = 0;
    stcDmaInit.u32DataWidth = DMA_DATAWIDTH_8BIT;
    stcDmaInit.u32DestAddr = (uint32_t)(&uart->uart_periph->TDR);
    stcDmaInit.u32SrcAddr = 0x00000000;
    stcDmaInit.u32SrcAddrInc = DMA_SRC_ADDR_INC;
    stcDmaInit.u32DestAddrInc = DMA_DEST_ADDR_FIX;
    i32Ret = DMA_Init(uart->dma.dma_periph, uart->dma.dma_tx_ch, &stcDmaInit);
    if (LL_OK == i32Ret) {
        /* Register TX complete IRQ handler && configure NVIC. */
        stcIrqSigninConfig.enIRQn = uart->dma.tx_cplt_irq;
        stcIrqSigninConfig.enIntSrc = uart->dma.tx_cplt_int_src;
        stcIrqSigninConfig.pfnCallback = uart->dma.tx_cplt_callback;
        INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);

        /* Register DMA Tx Cplt IRQ handler && configure NVIC. */
        stcIrqSigninConfig.enIRQn = uart->dma.dma_tx_tc_irq;
        stcIrqSigninConfig.enIntSrc = uart->dma.dma_tx_tc_int_src;
        stcIrqSigninConfig.pfnCallback = uart->dma.dma_tx_tc_callback;
        INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);

        AOS_SetTriggerEventSrc(uart->dma.dma_tx_trig_sel, uart->dma.dma_tx_trig_evt_src);

        DMA_Cmd(uart->dma.dma_periph, ENABLE);
        DMA_TransCompleteIntCmd(uart->dma.dma_periph, uart->dma.dma_tx_tc_int, ENABLE);
    }
}

static void close_usart(struct serial_device* serial)
{
    struct hc32_uart* uart = (struct hc32_uart*)serial->parent.user_data;

    if (serial->parent.open_flag & RT_DEVICE_FLAG_INT_RX) {
        /* disable int rx irq */
        NVIC_ClearPendingIRQ(uart->rx_err_irq);
        NVIC_DisableIRQ(uart->rx_err_irq);

        NVIC_ClearPendingIRQ(uart->rx_full_irq);
        NVIC_DisableIRQ(uart->rx_full_irq);

        USART_FuncCmd(uart->uart_periph, USART_INT_RX, DISABLE);
    }

    if (serial->parent.open_flag & RT_DEVICE_FLAG_DMA_RX) {
        /* disable dma rx irq and disable rx dma */
    }

    if (serial->parent.open_flag & RT_DEVICE_FLAG_DMA_TX) {
        /* disable dma tx irq and disable tx dma */
        NVIC_ClearPendingIRQ(uart->dma.dma_tx_tc_irq);
        NVIC_DisableIRQ(uart->dma.dma_tx_tc_irq);

        NVIC_ClearPendingIRQ(uart->dma.tx_cplt_irq);
        NVIC_DisableIRQ(uart->dma.tx_cplt_irq);

        DMA_ChCmd(uart->dma.dma_periph, uart->dma.dma_tx_ch, DISABLE);
        DMA_Cmd(uart->dma.dma_periph, DISABLE);
        DMA_TransCompleteIntCmd(uart->dma.dma_periph, uart->dma.dma_tx_tc_int, DISABLE);
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
    uint32_t func_state = USART_TX | USART_RX;

    RT_ASSERT(serial != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    uart = (struct hc32_uart*)serial->parent.user_data;

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

    if (cfg->bit_order == BIT_ORDER_LSB) {
        stcUartInit.u32FirstBit = USART_FIRST_BIT_LSB;
    } else {
        stcUartInit.u32FirstBit = USART_FIRST_BIT_MSB;
    }

    stcUartInit.u32HWFlowControl = USART_HW_FLOWCTRL_NONE;
    stcUartInit.u32OverSampleBit = USART_OVER_SAMPLE_16BIT;
    stcUartInit.u32ClockDiv = USART_CLK_DIV16;

    if (USART_GetFuncState(uart->uart_periph, USART_INT_RX)) {
        /* The deinit/init operation would clear function state, so recover it if INT_RX configured */
        func_state |= USART_INT_RX;
    }

    USART_DeInit(uart->uart_periph);
    USART_UART_Init(uart->uart_periph, &stcUartInit, NULL);

    /* Set usart function */
    USART_FuncCmd(uart->uart_periph, func_state, ENABLE);

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
            NVIC_ClearPendingIRQ(uart->rx_err_irq);
            NVIC_DisableIRQ(uart->rx_err_irq);

            NVIC_ClearPendingIRQ(uart->rx_full_irq);
            NVIC_DisableIRQ(uart->rx_full_irq);

            USART_FuncCmd(uart->uart_periph, USART_INT_RX, DISABLE);
        }
        break;

    case RT_DEVICE_CTRL_SET_INT:
        if (ctrl_arg == RT_DEVICE_FLAG_INT_RX) {
            stc_irq_signin_config_t stcIrqSigninConfig;

            /* Register RX error IRQ handler && configure NVIC. */
            stcIrqSigninConfig.enIRQn = uart->rx_err_irq;
            stcIrqSigninConfig.enIntSrc = uart->rx_err_int_src;
            stcIrqSigninConfig.pfnCallback = uart->rx_err_callback;
            INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);

            /* Register RX full IRQ handler && configure NVIC. */
            stcIrqSigninConfig.enIRQn = uart->rx_full_irq;
            stcIrqSigninConfig.enIntSrc = uart->rx_full_int_src;
            stcIrqSigninConfig.pfnCallback = uart->rx_full_callback;
            INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);

            USART_FuncCmd(uart->uart_periph, USART_INT_RX, ENABLE);
        }
        break;

        /* USART DMA config */
    case RT_DEVICE_CTRL_CONFIG:
        if (ctrl_arg == RT_DEVICE_FLAG_DMA_TX) {
            /* the USART_TX cmd will be enabled when dma configured */
            USART_FuncCmd(uart->uart_periph, (USART_TX | USART_INT_TX_CPLT), DISABLE);
            /* configure dma tx */
            dma_tx_config(uart);
        }
        break;

    case RT_DEVICE_CTRL_SUSPEND:
        close_usart(serial);
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

        USART_FuncCmd(uart->uart_periph, USART_TX | USART_INT_TX_CPLT, DISABLE);
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
    /* DMA&AOS FCG enable */
    FCG_Fcg0PeriphClockCmd(FCG0_PERIPH_DMA1, ENABLE);
    FCG_Fcg0PeriphClockCmd(FCG0_PERIPH_DMA2, ENABLE);
    FCG_Fcg0PeriphClockCmd(FCG0_PERIPH_AOS, ENABLE);

    /**** USART5 Init ****/
    GPIO_SetFunc(GPIO_PORT_C, GPIO_PIN_12, GPIO_FUNC_20); // USART5-TX
    GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_02, GPIO_FUNC_20); // USART5-RX
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART5, ENABLE);

    /**** USART7 Init ****/
    GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_07, GPIO_FUNC_39); // USART7-RX
    GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_08, GPIO_FUNC_38); // USART7-TX
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART7, ENABLE);

    /**** USART3 Init ****/
    GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_08, GPIO_FUNC_36); // USART3-TX
    GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_09, GPIO_FUNC_37); // USART3-RX
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART3, ENABLE);

    /**** USART2 Init ****/
    GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_05, GPIO_FUNC_20); // USART2-TX
    GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_06, GPIO_FUNC_20); // USART2-RX
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART2, ENABLE);

    /**** USART1 Init ****/
    GPIO_SetFunc(GPIO_PORT_B, GPIO_PIN_06, GPIO_FUNC_32); // USART1-TX
    GPIO_SetFunc(GPIO_PORT_B, GPIO_PIN_07, GPIO_FUNC_33); // USART1-RX
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART1, ENABLE);

    /**** USART8 Init ****/
    GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_00, GPIO_FUNC_20); // USART8-RX
    GPIO_SetFunc(GPIO_PORT_E, GPIO_PIN_01, GPIO_FUNC_20); // USART8-TX
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART8, ENABLE);

    /**** USART4 Init ****/
    GPIO_SetFunc(GPIO_PORT_C, GPIO_PIN_10, GPIO_FUNC_20); // USART4-TX
    GPIO_SetFunc(GPIO_PORT_C, GPIO_PIN_11, GPIO_FUNC_20); // USART4-RX
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART4, ENABLE);
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

#ifdef USING_UART7
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
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX,
                                  &uart7);
#endif /* USING_UART7 */

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

#ifdef USING_UART3
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
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_TX,
                                  &uart3);
#endif /* USING_UART3 */

#ifdef USING_UART1
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
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_TX,
                                  &uart1);
#endif /* USING_UART1 */

#ifdef USING_UART8
    serial5.ops = &__usart_ops;
    #ifdef SERIAL5_DEFAULT_CONFIG
    struct serial_configure serial5_config = SERIAL5_DEFAULT_CONFIG;
    serial5.config = serial5_config;
    #else
    serial5.config = config;
    #endif

    /* register serial device */
    rt_err |= hal_serial_register(&serial5,
                                  "serial5",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_TX,
                                  &uart8);
#endif /* USING_UART8 */

#ifdef USING_UART4
    serial6.ops = &__usart_ops;
    #ifdef SERIAL6_DEFAULT_CONFIG
    struct serial_configure serial6_config = SERIAL6_DEFAULT_CONFIG;
    serial6.config = serial6_config;
    #else
    serial6.config = config;
    #endif

    /* register serial device */
    rt_err |= hal_serial_register(&serial6,
                                  "serial6",
                                  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_TX,
                                  &uart4);
#endif /* USING_UART4 */

    return rt_err;
}
