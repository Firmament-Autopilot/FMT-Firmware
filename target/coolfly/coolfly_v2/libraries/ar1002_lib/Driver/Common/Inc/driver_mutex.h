/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: driver_mutex.h
Description: 
Author: Wumin @ Artosy Software Team
Version: 0.0.1
Date: 2017/17/19
History:
         0.0.1    2017/08/02    for driver mutex used
*****************************************************************************/
#ifndef _DRIVER_MUTEX_H
#define _DRIVER_MUTEX_H

typedef struct
{
    uint32_t timer0to7;
    uint32_t timer8to15;
    uint32_t timer16to23;
}TIMER_MUTEX_DATA;

typedef struct
{
    uint32_t uart;
    uint32_t spi;
    uint32_t can;
    uint32_t i2c;
    TIMER_MUTEX_DATA s_timer;
    uint32_t nor_flash;
    uint32_t dma;
}DRIVER_MUTEX_DATA;

typedef enum _emu_driver_mutex
{
    MUTEX_UART = 0,
    MUTEX_SPI,
    MUTEX_CAN,
    MUTEX_I2C,
    MUTEX_TIMER,
    MUTEX_NOR_FLASH,
    MUTEX_DMA
}emu_driver_mutex;


void COMMON_driverMutexInit(void);

void COMMON_driverMutexFree(emu_driver_mutex driver, uint32_t channel);
void COMMON_driverMutexSet(emu_driver_mutex driver, uint32_t channel);
int8_t COMMON_driverMutexGet(emu_driver_mutex driver, uint32_t channel);

#endif
