/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_uart.h
Description: The external HAL APIs to use the UART controller.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/12/20
History: 
        0.0.1    2016/12/20    The initial version of hal_uart.h
*****************************************************************************/
#ifndef __HAL_UART_H__
#define __HAL_UART_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "hal_ret_type.h"


//uart read data function define.just read u8_len bytes from pu8_rxBuf
typedef uint32_t (*HAL_UART_RxHandle)(uint8_t *pu8_rxBuf, uint8_t u8_len);

typedef enum
{
    HAL_UART_COMPONENT_0 = 0,
    HAL_UART_COMPONENT_1,
    HAL_UART_COMPONENT_2,
    HAL_UART_COMPONENT_3,
    HAL_UART_COMPONENT_4,
    HAL_UART_COMPONENT_5,
    HAL_UART_COMPONENT_6,
    HAL_UART_COMPONENT_7,
} ENUM_HAL_UART_COMPONENT;

//Baud Rate
typedef enum
{
    HAL_UART_BAUDR_9600 = 0,    // 0
    HAL_UART_BAUDR_19200,       // 1
    HAL_UART_BAUDR_38400,       // 2
    HAL_UART_BAUDR_57600,       // 3
    HAL_UART_BAUDR_115200,      // 4
    HAL_UART_BAUDR_230400,      // 5
    HAL_UART_BAUDR_256000,      // 6
    HAL_UART_BAUDR_380400,      // 7
    HAL_UART_BAUDR_460800       // 8
} ENUM_HAL_UART_BAUDR;

#define HAL_UART_DEFAULT_TIMEOUTMS                   (2)
/**
* @brief  The UART initialization function which must be called 
*         before using the UART controller.
* @param  e_uartComponent   The UART controller number, the right number 
*                           should be 0-8 and totally 9 UART controllers 
*                           can be used by application.
*         e_uartBaudr       uart baud rate,can be 9600 19200 ... 115200.
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
                        HAL_UART_RxHandle pfun_rxFun);

HAL_RET_T HAL_UART_SET_BAUDRATE(ENUM_HAL_UART_COMPONENT e_uartComponent, 
                        ENUM_HAL_UART_BAUDR e_uartBaudr);

HAL_RET_T HAL_SBUS_Init(ENUM_HAL_UART_COMPONENT e_uartComponent, 
                        uint32_t baudr, 
                        HAL_UART_RxHandle pfun_rxFun);

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
                          uint32_t u32_timeoutms);

#ifdef __cplusplus
}
#endif

#endif
