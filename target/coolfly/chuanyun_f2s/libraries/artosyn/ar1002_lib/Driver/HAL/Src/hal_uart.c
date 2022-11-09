/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_uart.c
Description: The external HAL APIs to use the UART controller.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/20
History: 
        0.0.1    2016/12/20    The initial version of hal_uart.c
*****************************************************************************/

#include "interrupt.h"
#include "serial.h"
#include "drv_systick.h"

#include "hal_nvic.h"
#include "hal_uart.h"
#include "hal.h"

#include "debuglog.h"
#include "driver_mutex.h"
#include "driver_module_init.h"


static const uint32_t s_u32_uartBaudrTbl[] = 
                      {
                          9600,        // 0
                          19200,       // 1
                          38400,       // 2
                          57600,       // 3
                          115200,      // 4
                          230400,      // 5
                          256000,      // 6
                          380400,      // 7
                          460800,      // 8                                                 
                          100000,      // 9
                          3125000,     // 10                          
                      };

HAL_RET_T HAL_UART_WaitTillIdle(ENUM_HAL_UART_COMPONENT e_uartComponent, uint32_t u32_timeoutms)
{
  uint32_t start;
    
    if (0 != u32_timeoutms)
    {
        start = SysTicks_GetTickCount();
        while (uart_checkoutFifoStatus(e_uartComponent))
        {
            if ((SysTicks_GetDiff(start, SysTicks_GetTickCount())) >= u32_timeoutms)
            {
                return HAL_UART_ERR_TIMEOUT;
            }
            
            SysTicks_DelayUS(100);
        }        
    }

    return HAL_OK;
}    

/**
* @brief  The UART initialization function which must be called 
*         before using the UART controller.
* @param  e_uartComponent   The UART controller number, the right number 
*                           should be 0-8 and totally 9 UART controllers 
*                           can be used by application.
*         e_uartBaudr       uart baud rate,can be 9600 19200 ... 460800.
*         pfun_rxFun        the uart receive data function.each time uart
*                           received data, it will be called.
*                           
* @retval HAL_OK            means the initializtion is well done.
*         HAL_UART_ERR_INIT means some error happens in the initializtion.
* @note   
*         pfun_rxFun be called in interrupt function,it should never block.
*         and try do less work,just read the data.
*/
HAL_RET_T HAL_UART_Init(ENUM_HAL_UART_COMPONENT e_uartComponent, 
                        ENUM_HAL_UART_BAUDR e_uartBaudr, 
                        HAL_UART_RxHandle pfun_rxFun)
{
    uint32_t u32_uartBaudr;
    uint8_t u8_uartCh;
    uint8_t u8_uartVecNum;

    //support uart9 and uart10
    if (e_uartComponent > HAL_UART_COMPONENT_7)
    {
        return HAL_UART_ERR_INIT;
    }
    if (e_uartBaudr > HAL_UART_BAUDR_460800)
    {
        return HAL_UART_ERR_INIT;
    }

    if ( -1 == COMMON_driverMutexGet(MUTEX_UART, e_uartComponent) )
    {
        DLOG_Error("fail, e_uartComponent = %d", e_uartComponent);
        return HAL_OCCUPIED;
    }
    COMMON_driverMutexSet(MUTEX_UART, (uint32_t)e_uartComponent);
    COMMON_driverInitSet(INITED_UART, (uint32_t)e_uartComponent);
    
    u8_uartCh = (uint8_t)(e_uartComponent);
    u8_uartVecNum = u8_uartCh + HAL_NVIC_UART_INTR0_VECTOR_NUM;
    //first ,disable uart_x interrupt.
    HAL_NVIC_DisableIrq(u8_uartVecNum);
    
    //record user function
    UART_RegisterUserRxHandler(u8_uartCh, pfun_rxFun);
    
    // uart hadrware init.
    u32_uartBaudr = s_u32_uartBaudrTbl[(uint8_t)(e_uartBaudr)];
    
    // set uart interrupt Priority
    HAL_NVIC_SetPriority(u8_uartVecNum, INTR_NVIC_PRIORITY_UART_DEFAULT, 0);
    //connect uart interrupt service function
    HAL_NVIC_RegisterHandler(u8_uartVecNum, 
                             UART_IntrSrvc, 
                             NULL);
    uart_init(u8_uartCh, u32_uartBaudr);
   
    if (NULL != pfun_rxFun) // enable uart_x interrupt.
    {
        HAL_NVIC_EnableIrq(u8_uartVecNum);
    }
 
    return HAL_OK;
}

HAL_RET_T HAL_SBUS_Init(ENUM_HAL_UART_COMPONENT e_uartComponent, 
                        uint32_t baudr, 
                        HAL_UART_RxHandle pfun_rxFun)
{
    uint8_t u8_uartCh;
    uint8_t u8_uartVecNum;

    //support uart9 and uart10
    if (e_uartComponent > HAL_UART_COMPONENT_7)
    {
        return HAL_UART_ERR_INIT;
    }

    if ( -1 == COMMON_driverMutexGet(MUTEX_UART, e_uartComponent) )
    {
        DLOG_Error("fail, e_uartComponent = %d", e_uartComponent);
        return HAL_OCCUPIED;
    }
    COMMON_driverMutexSet(MUTEX_UART, (uint32_t)e_uartComponent);
    COMMON_driverInitSet(INITED_UART, (uint32_t)e_uartComponent);
    
    u8_uartCh = (uint8_t)(e_uartComponent);
    u8_uartVecNum = u8_uartCh + HAL_NVIC_UART_INTR0_VECTOR_NUM;
    //first ,disable uart_x interrupt.
    HAL_NVIC_DisableIrq(u8_uartVecNum);
    
    //record user function
    UART_RegisterUserRxHandler(u8_uartCh, pfun_rxFun);
    
    // set uart interrupt Priority
    HAL_NVIC_SetPriority(u8_uartVecNum, INTR_NVIC_PRIORITY_UART_DEFAULT, 0);
    //connect uart interrupt service function
    HAL_NVIC_RegisterHandler(u8_uartVecNum, 
                             UART_IntrSrvc, 
                             NULL);
    sbus_init(u8_uartCh, baudr);
   
    if (NULL != pfun_rxFun) // enable uart_x interrupt.
    {
        HAL_NVIC_EnableIrq(u8_uartVecNum);
    }
 
    return HAL_OK;
}


/**
* @brief  The uart data send function which can be used to send out uart 
*         data by the uart controller.
* @param  e_uartComponent         The UART controller number, the right number 
*                                 should be 0-8 and totally 9 UART controllers 
*                                 can be used by application.
*         pu8_txBuf               The transmit buffer pointer to be sent out by uart.
*         u32_len                 The transmit buffer size in byte. 
*         u32_timeoutms           timeout ms. 
* @retval HAL_OK                  means the UART data write is well done.
*         HAL_UART_ERR_WRITE_DATA means some error happens in the UART data .
* @note   None.
*/
HAL_RET_T HAL_UART_TxData(ENUM_HAL_UART_COMPONENT e_uartComponent, 
                          uint8_t *pu8_txBuf, 
                          uint32_t u32_len,
                          uint32_t u32_timeoutms)
{
    uint8_t u8_uartCh;
    // uint32_t u32_uartTxCnt = 0;
    
    //support uart9 and uart10
    if (e_uartComponent > HAL_UART_COMPONENT_7)
    {
        return HAL_UART_ERR_WRITE_DATA;
    }
    if (NULL == pu8_txBuf)
    {
        return HAL_UART_ERR_WRITE_DATA;
    }
    if (0 == u32_len)
    {
        return HAL_UART_ERR_WRITE_DATA;
    }

    if ( -1 == COMMON_driverInitGet(INITED_UART, e_uartComponent) )
    {
        DLOG_Error("fail, e_uartComponent = %d", e_uartComponent);
        return HAL_NOT_INITED;
    }

    u8_uartCh = (uint8_t)(e_uartComponent);

    if (1 == uart_checkoutFifoStatus(u8_uartCh))
    {
      return HAL_BUSY;
    }
    
    uart_putdata(u8_uartCh, (char *)pu8_txBuf, u32_len);

    HAL_UART_WaitTillIdle(u8_uartCh, u32_timeoutms);
    
    return HAL_OK;
}





HAL_RET_T HAL_UART_SET_BAUDRATE(ENUM_HAL_UART_COMPONENT e_uartComponent, 
                        ENUM_HAL_UART_BAUDR e_uartBaudr)
{
    // uint32_t u32_uartBaudr;
    // uint8_t u8_uartCh;
    // uint8_t u8_uartVecNum;

    //support uart9 and uart10
    if (e_uartComponent > HAL_UART_COMPONENT_7)
    {
        return HAL_UART_ERR_INIT;
    }
    if (e_uartBaudr > HAL_UART_BAUDR_460800)
    {
        return HAL_UART_ERR_INIT;
    }

    uart_set_baudrate((uint8_t)(e_uartComponent),s_u32_uartBaudrTbl[(uint8_t)(e_uartBaudr)]);
    return HAL_OK;
}