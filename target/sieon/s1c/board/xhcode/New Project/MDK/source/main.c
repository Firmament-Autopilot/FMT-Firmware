/**
 *******************************************************************************
 * @file  main.c
 * @brief Main program.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2026-01-20       CDT             First version
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2022-2025, Xiaohua Semiconductor Co., Ltd. All rights reserved.
 *
 * This software component is licensed by XHSC under BSD 3-Clause license
 * (the "License"); You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                    opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "main.h"

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
/* Configures USARTx. */
static void App_USARTxCfg(void);
/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
//Clock Config
static void App_ClkCfg(void)
{
    /* Set bus clock div. */
    CLK_SetClockDiv(CLK_BUS_CLK_ALL, (CLK_HCLK_DIV1 | CLK_EXCLK_DIV2 | CLK_PCLK0_DIV1 | CLK_PCLK1_DIV2 | \
                                   CLK_PCLK2_DIV4 | CLK_PCLK3_DIV4 | CLK_PCLK4_DIV2));
    /* sram init include read/write wait cycle setting */
    SRAM_SetWaitCycle(SRAM_SRAM_ALL, SRAM_WAIT_CYCLE1, SRAM_WAIT_CYCLE1);
    SRAM_SetWaitCycle(SRAM_SRAMH, SRAM_WAIT_CYCLE0, SRAM_WAIT_CYCLE0);
    /* flash read wait cycle setting */
    EFM_SetWaitCycle(EFM_WAIT_CYCLE5);
    /* XTAL config */
    stc_clock_xtal_init_t stcXtalInit;
    (void)CLK_XtalStructInit(&stcXtalInit);
    stcXtalInit.u8State = CLK_XTAL_ON;
    stcXtalInit.u8Drv = CLK_XTAL_DRV_HIGH;
    stcXtalInit.u8Mode = CLK_XTAL_MD_OSC;
    stcXtalInit.u8StableTime = CLK_XTAL_STB_2MS;
    (void)CLK_XtalInit(&stcXtalInit);
    /* PLLH config */
    stc_clock_pll_init_t stcPLLHInit;
    (void)CLK_PLLStructInit(&stcPLLHInit);
    stcPLLHInit.PLLCFGR = 0UL;
    stcPLLHInit.PLLCFGR_f.PLLM = (1UL - 1UL);
    stcPLLHInit.PLLCFGR_f.PLLN = (120UL - 1UL);
    stcPLLHInit.PLLCFGR_f.PLLP = (4UL - 1UL);
    stcPLLHInit.PLLCFGR_f.PLLQ = (4UL - 1UL);
    stcPLLHInit.PLLCFGR_f.PLLR = (4UL - 1UL);
    stcPLLHInit.u8PLLState = CLK_PLL_ON;
    stcPLLHInit.PLLCFGR_f.PLLSRC = CLK_PLL_SRC_XTAL;
    (void)CLK_PLLInit(&stcPLLHInit);
    /* PLLA config */
    stc_clock_pllx_init_t stcPLLAInit;
    (void)CLK_PLLxStructInit(&stcPLLAInit);
    stcPLLAInit.PLLCFGR = 0UL;
    stcPLLAInit.PLLCFGR_f.PLLM = (2UL - 1UL);
    stcPLLAInit.PLLCFGR_f.PLLN = (60UL - 1UL);
    stcPLLAInit.PLLCFGR_f.PLLP = (2UL - 1UL);
    stcPLLAInit.PLLCFGR_f.PLLQ = (2UL - 1UL);
    stcPLLAInit.PLLCFGR_f.PLLR = (5UL - 1UL);
    stcPLLAInit.u8PLLState = CLK_PLLX_ON;
    (void)CLK_PLLxInit(&stcPLLAInit);
    /* 4 cycles for 200MHz ~ 250MHz */
    GPIO_SetReadWaitCycle(GPIO_RD_WAIT4);
    /* Set the system clock source */
    CLK_SetSysClockSrc(CLK_SYSCLK_SRC_PLL);
}

//Port Config
static void App_PortCfg(void)
{
    GPIO_SetFunc(GPIO_PORT_B,GPIO_PIN_09,GPIO_FUNC_32);//USART1-TX
    
    GPIO_SetFunc(GPIO_PORT_I,GPIO_PIN_04,GPIO_FUNC_32;Digi);//USART1-RX
    
    GPIO_SetFunc(GPIO_PORT_A,GPIO_PIN_00,GPIO_FUNC_37);//USART6-RX
    
    GPIO_SetFunc(GPIO_PORT_A,GPIO_PIN_03,GPIO_FUNC_36);//USART6-TX
    
}


/**
 * @brief  Main function of the project
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    /* Register write unprotected for some required peripherals. */
    LL_PERIPH_WE(LL_PERIPH_ALL);
    //Clock Config
    App_ClkCfg();
    //Port Config
    App_PortCfg();
    //USARTx Config
    App_USARTxCfg();
    /* Register write protected for some required peripherals. */
    LL_PERIPH_WP(LL_PERIPH_ALL);
    for (;;) {

    }
}


//USARTx Config
static void App_USARTxCfg(void)
{
    stc_usart_uart_init_t stcUartInit;

    /* Enable USART1 clock */
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART1, ENABLE);
    /************************* Configure USART1***************************/
    USART_DeInit(CM_USART1);
    (void)USART_UART_StructInit(&stcUartInit);
    stcUartInit.u32ClockSrc = USART_CLK_SRC_INTERNCLK;
    stcUartInit.u32ClockDiv = USART_CLK_DIV1;
    stcUartInit.u32CKOutput = USART_CK_OUTPUT_DISABLE;
    stcUartInit.u32Baudrate = 9600UL;
    stcUartInit.u32DataWidth = USART_DATA_WIDTH_8BIT;
    stcUartInit.u32StopBit = USART_STOPBIT_1BIT;
    stcUartInit.u32Parity = USART_PARITY_NONE;
    stcUartInit.u32OverSampleBit = USART_OVER_SAMPLE_16BIT;
    stcUartInit.u32FirstBit = USART_FIRST_BIT_LSB;
    stcUartInit.u32StartBitPolarity = USART_START_BIT_FALLING;
    stcUartInit.u32HWFlowControl = USART_HW_FLOWCTRL_NONE;
    USART_UART_Init(CM_USART1, &stcUartInit, NULL);
    /* Enable USART_TX | USART_RX function */
    USART_FuncCmd(CM_USART1, (USART_TX | USART_RX), ENABLE);

    /* Enable USART6 clock */
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_USART6, ENABLE);
    /************************* Configure USART6***************************/
    USART_DeInit(CM_USART6);
    (void)USART_UART_StructInit(&stcUartInit);
    stcUartInit.u32ClockSrc = USART_CLK_SRC_INTERNCLK;
    stcUartInit.u32ClockDiv = USART_CLK_DIV1;
    stcUartInit.u32CKOutput = USART_CK_OUTPUT_DISABLE;
    stcUartInit.u32Baudrate = 9600UL;
    stcUartInit.u32DataWidth = USART_DATA_WIDTH_8BIT;
    stcUartInit.u32StopBit = USART_STOPBIT_1BIT;
    stcUartInit.u32Parity = USART_PARITY_NONE;
    stcUartInit.u32OverSampleBit = USART_OVER_SAMPLE_16BIT;
    stcUartInit.u32FirstBit = USART_FIRST_BIT_LSB;
    stcUartInit.u32StartBitPolarity = USART_START_BIT_FALLING;
    stcUartInit.u32HWFlowControl = USART_HW_FLOWCTRL_NONE;
    USART_UART_Init(CM_USART6, &stcUartInit, NULL);
    /* Enable USART_TX | USART_RX function */
    USART_FuncCmd(CM_USART6, (USART_TX | USART_RX), ENABLE);
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
