/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: driver_mutex.c
Description: 
Author: Wumin @ Artosy Software Team
Version: 0.0.1
Date: 2017/17/19
History:
         0.0.1    2017/08/02    for driver mutex used
*****************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "driver_module_init.h"
#include "debuglog.h"
#include "memory_config.h"
#include "cpu_info.h"

DRIVER_INIT_DATA g_s_driverInit = {0};

void COMMON_driverInitSet(emu_driver_init e_driver, uint32_t u32_channel)
{
    switch (e_driver)
    {
        case INITED_UART:
            g_s_driverInit.uart |= 1<<u32_channel;
        break;

        case INITED_SPI:
            g_s_driverInit.spi |= 1<<u32_channel;
        break;

        case INITED_CAN:
            g_s_driverInit.can |= 1<<u32_channel;
        break;

        case INITED_I2C:
            g_s_driverInit.i2c |= 1<<u32_channel;
        break;

        case INITED_TIMER:
            g_s_driverInit.timer |= 1<<u32_channel;
        break;

        case INITED_NOR_FLASH:
            g_s_driverInit.nor_flash |= 1<<u32_channel;
        break;

        default:
        break;
    }
}

int8_t COMMON_driverInitGet(emu_driver_init e_driver, uint32_t u32_channel)
{
    // uint32_t tmp;

    switch (e_driver)
    {
        case INITED_UART:
            if ( 0 == ((g_s_driverInit.uart >> u32_channel) & 0x1) ) 
            {
                return -1;
            }
        break;

        case INITED_SPI:
            if ( 0 == ((g_s_driverInit.spi >> u32_channel) & 0x1) ) 
            {
                return -1;
            }
        break;

        case INITED_CAN:
            if ( 0 == ((g_s_driverInit.can >> u32_channel) & 0x1) ) 
            {
                return -1;
            }
        break;

        case INITED_I2C:
            if ( 0 == ((g_s_driverInit.i2c >> u32_channel) & 0x1) ) 
            {
                return -1;
            }
        break;

        case INITED_TIMER:
            if ( 0 == ((g_s_driverInit.timer >> u32_channel) & 0x1) ) 
            {
                return -1;
            }
        break;

        case INITED_NOR_FLASH:
            if ( 0 == ((g_s_driverInit.nor_flash >> u32_channel) & 0x1) ) 
            {
                return -1;
            }
        break;

        default:
        break;
    }

    return 0;
}

