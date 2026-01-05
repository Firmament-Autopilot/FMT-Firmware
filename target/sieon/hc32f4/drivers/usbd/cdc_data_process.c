/**
 *******************************************************************************
 * @file  usb/usb_dev_cdc/source/cdc_data_process.c
 * @brief Generic media access Layer.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2022-03-31       CDT             First version
   2022-10-31       CDT             Modify for MISRAC
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2022-2023, wlhc Semiconductor Co., Ltd. All rights reserved.
 *
 * This software component is licensed by WLHC under BSD 3-Clause license
 * (the "License"); You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                    opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "cdc_data_process.h"

/**
 * @addtogroup WL32F436_DDL_Applications
 * @{
 */

/**
 * @addtogroup USB_Dev_Cdc
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
#define CDC_COMM                       ( CM_USART3 )
#define USART_FCG_ENABLE()             ( FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART3, ENABLE) )

/* UART RX/TX Port/Pin definition */
///< Disable JTAG's TRST(PB04),and turn to GPIO
#define USART_RX_PORT                  ( GPIO_PORT_B )/* PB4: USART3_RX */
#define USART_RX_PIN                   ( GPIO_PIN_04 )
#define USART_RX_GPIO_FUNC             ( GPIO_FUNC_37 )

#define USART_TX_PORT                  ( GPIO_PORT_B )/* PB5: USART3_TX */
#define USART_TX_PIN                   ( GPIO_PIN_05 )
#define USART_TX_GPIO_FUNC             ( GPIO_FUNC_36 )

/* UART unit definition */
#define USART_FUNCTION_CLK_GATE        ( PWC_FCG3_USART3 )

/* UART unit interrupt definition */
#define USART_UNIT_ERR_INT             ( INT_SRC_USART3_EI )
#define USART_UNIT_ERR_IRQn            ( INT000_IRQn)

#define USART_UNIT_RX_INT              ( INT_SRC_USART3_RI )
#define USART_UNIT_RX_IRQn             ( INT001_IRQn)

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static LINE_CODING linecoding =
{
    115200, /* baud rate - 115200 */
    0x00,   /* stop bits - 1 */
    0x00,   /* parity    - none */
    0x08    /* data bit  - 8 */
};

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

static uint16_t comport_config(void);
static void UsartErrIrqCallback(void);
static void UsartRxIrqCallback(void);
static void InstalIrqHandler(const stc_irq_signin_config_t *pstcConfig,
                             uint32_t u32Priority);



/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/

/**
 * @brief  Initializes the configuration of usart port
 * @param  None
 * @retval None
 */
void vcp_init(void)
{
    stc_irq_signin_config_t stcIrqSigninCfg;
    const stc_usart_uart_init_t stcUartInit =
    {
        .u32ClockSrc = USART_CLK_SRC_INTERNCLK,
        .u32ClockDiv = USART_CLK_DIV1,
        .u32Baudrate = 115200UL,//500000UL
        .u32FirstBit = USART_FIRST_BIT_LSB,
        .u32StopBit = USART_STOPBIT_1BIT,
        .u32Parity = USART_PARITY_NONE,
        .u32DataWidth = USART_DATA_WIDTH_8BIT,
        .u32CKOutput = USART_CK_OUTPUT_DISABLE,
        .u32OverSampleBit = USART_OVER_SAMPLE_8BIT,
        .u32StartBitPolarity = USART_START_BIT_FALLING,
        .u32HWFlowControl = USART_HW_FLOWCTRL_NONE
    };
    /* Configure USART RX/TX pin. */
    GPIO_REG_Unlock();
    GPIO_SetDebugPort(GPIO_PIN_TRST, DISABLE); ///< Disable JTAG's TDI TDO and TRST,and turn to GPIO,success
    GPIO_SetFunc(USART_RX_PORT, USART_RX_PIN, USART_RX_GPIO_FUNC);
    GPIO_SetFunc(USART_TX_PORT, USART_TX_PIN, USART_TX_GPIO_FUNC);

    /* Enable peripheral clock */
    USART_FCG_ENABLE();

    /* Initialize UART function. */
    if (LL_OK == USART_UART_Init(CDC_COMM, &stcUartInit, NULL))
    {
        /* Register error IRQ handler && configure NVIC. */
        stcIrqSigninCfg.enIRQn = USART_UNIT_ERR_IRQn;
        stcIrqSigninCfg.enIntSrc = USART_UNIT_ERR_INT;
        stcIrqSigninCfg.pfnCallback = &UsartErrIrqCallback;
        InstalIrqHandler(&stcIrqSigninCfg, DDL_IRQ_PRIO_01);

        /* Register RX IRQ handler && configure NVIC. */
        stcIrqSigninCfg.enIRQn = USART_UNIT_RX_IRQn;
        stcIrqSigninCfg.enIntSrc = USART_UNIT_RX_INT;
        stcIrqSigninCfg.pfnCallback = &UsartRxIrqCallback;
        InstalIrqHandler(&stcIrqSigninCfg, DDL_IRQ_PRIO_01);

        USART_FuncCmd(CDC_COMM, (USART_RX | USART_TX), ENABLE);
        USART_FuncCmd(CDC_COMM, USART_INT_RX, ENABLE);
    }
    else
    {
        return;
    }
}

/**
 * @brief  deInitializes the Media
 * @param  None
 * @retval None
 */
void vcp_deinit(void)
{
}

extern uint8_t u8UsbCdcConnected;
/**
 * @brief  Manage the CDC class requests
 * @param  [in] Cmd     Command code
 * @param  [in] Buf     data to be sent or received
 * @param  [in] Len     data length in bytes
 * @retval status
 */
void vcp_ctrlpare(uint32_t Cmd, uint8_t *Buf, uint32_t Len)
{
    switch (Cmd)
    {
    case SEND_ENCAPSULATED_COMMAND:
        /* Not  needed for this driver */
        break;

    case GET_ENCAPSULATED_RESPONSE:
        /* Not  needed for this driver */
        break;

    case SET_COMM_FEATURE:
        /* Not  needed for this driver */
        break;

    case GET_COMM_FEATURE:
        /* Not  needed for this driver */
        break;

    case CLEAR_COMM_FEATURE:
        /* Not  needed for this driver */
        break;

    case SET_LINE_CODING:
        linecoding.bitrate = ((uint32_t)Buf[0U] | ((uint32_t)Buf[1U] << 8U) | ((uint32_t)Buf[2U] << 16U) | ((uint32_t)Buf[3U] << 24U));
        linecoding.format = Buf[4];
        linecoding.paritytype = Buf[5U];
        linecoding.datatype = Buf[6U];
        /* Set the new configuration */
        (void)comport_config();
        break;
    case GET_LINE_CODING:
        Buf[0U] = (uint8_t)(linecoding.bitrate);
        Buf[1U] = (uint8_t)(linecoding.bitrate >> 8U);
        Buf[2U] = (uint8_t)(linecoding.bitrate >> 16U);
        Buf[3U] = (uint8_t)(linecoding.bitrate >> 24U);
        Buf[4U] = linecoding.format;
        Buf[5U] = linecoding.paritytype;
        Buf[6U] = linecoding.datatype;
        break;
    case SET_CONTROL_LINE_STATE:

//        if (0x00 == Buf[2])
//        {
//            u8UsbCdcConnected = 0;//��
//        }
//        else if (0x01 == Buf[2])
//        {
//            u8UsbCdcConnected = 1;//��
//        }
        /* Not  needed for this driver */
        break;
    case SEND_BREAK:
        /* Not  needed for this driver */
        break;
    default:
        break;
    }
}

/**
 * @brief  Receive data from USART and save in the buffer usb_tx_buffer, the
 *         received number is counted by APP_Tx_ptr_in
 * @param  None
 * @retval None
 */
void vcp_txdata(void)
{
//    if (linecoding.datatype == 7U)
//    {
//        usb_tx_buffer[APP_Tx_ptr_in] = (uint8_t)USART_ReadData(CDC_COMM) & 0x7FU;
//    }
//    else if (linecoding.datatype == 8U)
//    {
//        usb_tx_buffer[APP_Tx_ptr_in] = (uint8_t)USART_ReadData(CDC_COMM);
//    }
//    else
//    {
//        ;
//    }

//    APP_Tx_ptr_in++;

//    /* To avoid buffer overflow */
//    if (APP_Tx_ptr_in == APP_TX_DATA_SIZE)
//    {
//        APP_Tx_ptr_in = 0U;
//    }
}

/**
 * @brief  Data received from USB are sent to uart port
 * @param  [in] Buf     buffer to be sent to uart port
 * @param  [in] Len     data length in bytes
 * @retval None
 */
void vcp_rxdata(uint8_t *Buf, uint32_t Len)
{
    uint32_t i;

    for (i = 0UL; i < Len; i++)
    {
        while (SET != USART_GetStatus(CDC_COMM, USART_FLAG_TX_EMPTY))
        {
            ;
        }
        USART_WriteData(CDC_COMM, (uint16_t)Buf[i]);
    }
}

/**
 * @brief  configure the uart port
 * @param  None
 * @retval None
 */
static uint16_t VCP_COMConfigDefault(void)
{

    uint16_t u16Res = USB_DEV_OK;
    uint8_t u8Cnt;
    float32_t fErr;

    for (u8Cnt = 0U; u8Cnt < 4U; u8Cnt++)
    {
        if (LL_OK == USART_SetBaudrate(CDC_COMM, 115200UL, &fErr))
        {
            USART_FuncCmd(CDC_COMM, (USART_RX | USART_TX), ENABLE);
            USART_FuncCmd(CDC_COMM, USART_INT_RX, ENABLE);
            break;
        }
        else
        {
            USART_SetClockDiv(CDC_COMM, u8Cnt);
        }
    }
    if (u8Cnt == 4U)
    {
        u16Res = USB_DEV_FAIL;
    }
    return u16Res;
}

/**
 * @brief  configure the uart port
 * @param  None
 * @retval None
 */
uint16_t comport_config(void)
{
    uint8_t u8Cnt;
    uint16_t u16Res = USB_DEV_OK;
    uint8_t u8ReturnFlag = 0U;
    float fErr;

    stc_usart_uart_init_t stcUartInit =
    {
        .u32ClockSrc = USART_CLK_SRC_INTERNCLK,
        .u32ClockDiv = USART_CLK_DIV1,
        .u32CKOutput = USART_CK_OUTPUT_DISABLE,
        .u32Baudrate = 115200UL,
        .u32DataWidth = USART_DATA_WIDTH_8BIT,
        .u32StopBit = USART_STOPBIT_1BIT,
        .u32OverSampleBit = USART_OVER_SAMPLE_8BIT,
        .u32FirstBit = USART_FIRST_BIT_LSB,
        .u32StartBitPolarity = USART_START_BIT_FALLING,
        .u32HWFlowControl = USART_HW_FLOWCTRL_NONE
    };

    /* set the Stop bit*/
    switch (linecoding.format)
    {
    case 0U:
        stcUartInit.u32StopBit = USART_STOPBIT_1BIT;
        break;
    case 1U:
        stcUartInit.u32StopBit = USART_STOPBIT_1BIT;
        break;
    case 2U:
        stcUartInit.u32StopBit = USART_STOPBIT_2BIT;
        break;
    default :
        (void)VCP_COMConfigDefault();
        u16Res = USB_DEV_FAIL;
        u8ReturnFlag = 1U;
        break;
    }

    if (1U != u8ReturnFlag)
    {
        /* set the parity bit*/
        switch (linecoding.paritytype)
        {
        case 0U:
            stcUartInit.u32Parity = USART_PARITY_NONE;
            break;
        case 1U:
            stcUartInit.u32Parity = USART_PARITY_EVEN;
            break;
        case 2U:
            stcUartInit.u32Parity = USART_PARITY_ODD;
            break;
        default :
            (void)VCP_COMConfigDefault();
            u16Res = USB_DEV_FAIL;
            u8ReturnFlag = 1U;
            break;
        }

        if (1U != u8ReturnFlag)
        {
            /*set the data type : only 8bits and 9bits is supported */
            switch (linecoding.datatype)
            {
            case 0x07U:
                /* With this configuration a parity (Even or Odd) should be set */
                stcUartInit.u32DataWidth = USART_DATA_WIDTH_8BIT;
                break;
            case 0x08U:
                if (stcUartInit.u32Parity == USART_PARITY_NONE)
                {
                    stcUartInit.u32DataWidth = USART_DATA_WIDTH_8BIT;
                }
                else
                {
                    stcUartInit.u32DataWidth = USART_DATA_WIDTH_9BIT;
                }
                break;
            default :
                (void)VCP_COMConfigDefault();
                u16Res = USB_DEV_FAIL;
                u8ReturnFlag = 1U;
                break;
            }

            if (1U != u8ReturnFlag)
            {
                stcUartInit.u32Baudrate = linecoding.bitrate;
                /* Configure and enable the USART */
                (void)USART_UART_Init(CDC_COMM, &stcUartInit, &fErr);

                for (u8Cnt = 0U; u8Cnt < 4U; u8Cnt++)
                {
                    if (LL_OK == USART_SetBaudrate(CDC_COMM, stcUartInit.u32Baudrate, &fErr))
                    {
                        /* Enable RX/TX function */
                        USART_FuncCmd(CDC_COMM, (USART_RX | USART_INT_RX | USART_TX), ENABLE);
                        break;
                    }
                    else
                    {
                        USART_SetClockDiv(CDC_COMM, u8Cnt);
                    }
                }
                if (u8Cnt == 4U)
                {
                    u16Res = USB_DEV_FAIL;
                }
            }
        }
    }
    return u16Res;
}

/**
 * @brief  USART RX irq callback function.
 * @param  None
 * @retval None
 */
void UsartRxIrqCallback(void)
{
    if (SET == USART_GetStatus(CDC_COMM, USART_FLAG_RX_FULL))
    {
//        /* Send the received data to the PC Host*/
//        vcp_txdata();
    }
}

/**
 * @brief  USART RX error irq callback function.
 * @param  None
 * @retval None
 */
void UsartErrIrqCallback(void)
{
    if (SET == USART_GetStatus(CDC_COMM, USART_FLAG_FRAME_ERR))
    {
        USART_ClearStatus(CDC_COMM, USART_FLAG_FRAME_ERR);
    }
    else
    {
    }

    if (SET == USART_GetStatus(CDC_COMM, USART_FLAG_PARITY_ERR))
    {
        USART_ClearStatus(CDC_COMM, USART_FLAG_PARITY_ERR);
    }
    else
    {
    }

    if (SET == USART_GetStatus(CDC_COMM, USART_FLAG_OVERRUN))
    {
        USART_ClearStatus(CDC_COMM, USART_FLAG_OVERRUN);
    }
    else
    {
    }
}

/**
 * @brief  Instal IRQ handler.
 * @param  [in] pstcConfig      Pointer to struct @ref stc_irq_signin_config_t
 * @param  [in] u32Priority     Interrupt priority
 * @retval None
 */
void InstalIrqHandler(const stc_irq_signin_config_t *pstcConfig,
                      uint32_t u32Priority)
{
    if (NULL != pstcConfig)
    {
        (void)INTC_IrqSignIn(pstcConfig);
        NVIC_ClearPendingIRQ(pstcConfig->enIRQn);
        NVIC_SetPriority(pstcConfig->enIRQn, u32Priority);
        NVIC_EnableIRQ(pstcConfig->enIRQn);
    }
}

/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
