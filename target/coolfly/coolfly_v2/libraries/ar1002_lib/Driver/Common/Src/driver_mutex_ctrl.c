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
#include "driver_mutex.h"
#include "debuglog.h"
#include "memory_config.h"
#include "cpu_info.h"

extern DRIVER_MUTEX_DATA *g_ps_periMutex;

void COMMON_driverMutexFree(emu_driver_mutex e_driver, uint32_t u32_channel)
{
    switch (e_driver)
    {
        case MUTEX_UART:
            g_ps_periMutex->uart &=~ (1 << (u32_channel*3));
            g_ps_periMutex->uart &=~ (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;

        case MUTEX_SPI:
            g_ps_periMutex->spi &=~ (1 << (u32_channel*3));
            g_ps_periMutex->spi &=~ (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;

        case MUTEX_CAN:
            g_ps_periMutex->can &=~ (1 << (u32_channel*3));
            g_ps_periMutex->can &=~ (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;

        case MUTEX_I2C:
            g_ps_periMutex->i2c &=~ (1 << (u32_channel*3));
            g_ps_periMutex->i2c &=~ (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;
        
        case MUTEX_TIMER:
            if (u32_channel < 8)
            {
                g_ps_periMutex->s_timer.timer0to7 &=~ (1 << (u32_channel*3));
                g_ps_periMutex->s_timer.timer0to7 &=~ (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
            }
            else if (u32_channel < 16)
            {
                g_ps_periMutex->s_timer.timer8to15 &=~ (1 << ((u32_channel-8)*3));
                g_ps_periMutex->s_timer.timer8to15 &=~ (CPUINFO_GetLocalCpuId() << ((u32_channel-8)*3+1));
            }
            else
            {
                g_ps_periMutex->s_timer.timer16to23 &=~ (1 << ((u32_channel-16)*3));
                g_ps_periMutex->s_timer.timer16to23 &=~ (CPUINFO_GetLocalCpuId() << ((u32_channel-16)*3+1));
            }
        break;

        case MUTEX_NOR_FLASH:
            g_ps_periMutex->nor_flash &=~ (1 << (u32_channel*3));
            g_ps_periMutex->nor_flash &=~ (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;

        case MUTEX_DMA:
            g_ps_periMutex->dma &=~ (1 << (u32_channel*3));
            g_ps_periMutex->dma &=~ (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;

        default:break;
    }
}

void COMMON_driverMutexSet(emu_driver_mutex e_driver, uint32_t u32_channel)
{
    switch (e_driver)
    {
        case MUTEX_UART:
            g_ps_periMutex->uart |= (1 << (u32_channel*3));
            g_ps_periMutex->uart |= (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;

        case MUTEX_SPI:
            g_ps_periMutex->spi |= (1 << (u32_channel*3));
            g_ps_periMutex->spi |= (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;

        case MUTEX_CAN:
            g_ps_periMutex->can |= (1 << (u32_channel*3));
            g_ps_periMutex->can |= (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;

        case MUTEX_I2C:
            g_ps_periMutex->i2c |= (1 << (u32_channel*3));
            g_ps_periMutex->i2c |= (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;

        case MUTEX_TIMER:
            if (u32_channel < 8)
            {
                g_ps_periMutex->s_timer.timer0to7 |= (1 << (u32_channel*3));
                g_ps_periMutex->s_timer.timer0to7 |= (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
            }
            else if (u32_channel < 16)
            {
                g_ps_periMutex->s_timer.timer8to15 |= (1 << ((u32_channel-8)*3));
                g_ps_periMutex->s_timer.timer8to15 |= (CPUINFO_GetLocalCpuId() << ((u32_channel-8)*3+1));
            }
            else
            {
                g_ps_periMutex->s_timer.timer16to23 |= (1 << ((u32_channel-16)*3));
                g_ps_periMutex->s_timer.timer16to23 |= (CPUINFO_GetLocalCpuId() << ((u32_channel-16)*3+1));
            }
        break;

        case MUTEX_NOR_FLASH:
            g_ps_periMutex->nor_flash |= (1 << (u32_channel*3));
            g_ps_periMutex->nor_flash |= (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;

        case MUTEX_DMA:
            g_ps_periMutex->dma |= (1 << (u32_channel*3));
            g_ps_periMutex->dma |= (CPUINFO_GetLocalCpuId() << (u32_channel*3+1));
        break;

        default:break;
    }
}

int8_t COMMON_driverMutexGet(emu_driver_mutex e_driver, uint32_t u32_channel)
{
    uint32_t u32_cpu_id;
    uint32_t u32_cpu_id_mask = 0;

/*
    DLOG_Info("addr of g_ps_periMutex = %p", g_ps_periMutex);
    DLOG_Info("addr of g_ps_periMutex->uart = 0x%08x", g_ps_periMutex->uart);
    DLOG_Info("addr of g_ps_periMutex->spi = 0x%08x", g_ps_periMutex->spi);
    DLOG_Info("addr of g_ps_periMutex->can = 0x%08x", g_ps_periMutex->can);
*/
    u32_cpu_id_mask |= (3 << ((u32_channel*3)+1));
    
    switch (e_driver)
    {
        case MUTEX_UART:
            if( g_ps_periMutex->uart & (1 << (u32_channel*3)) )
            {
                u32_cpu_id = ( (g_ps_periMutex->uart & u32_cpu_id_mask) >> (u32_channel*3 + 1) );
                if (u32_cpu_id != CPUINFO_GetLocalCpuId())
                {
                    DLOG_Error("uart u32_channel:%ld occupied", u32_channel);
                    return -1;
                }
            }
        break;

        case MUTEX_SPI:
            if( g_ps_periMutex->spi & (1 << (u32_channel*3)) )
            {
                u32_cpu_id = ( (g_ps_periMutex->spi & u32_cpu_id_mask) >> (u32_channel*3 + 1) );
                if (u32_cpu_id != CPUINFO_GetLocalCpuId())
                {
                    DLOG_Error("spi channel:%ld occupied", u32_channel);
                    return -1;
                }
            }

        break;

        case MUTEX_CAN:
            if( g_ps_periMutex->can & (1 << (u32_channel*3)) )
            {
                u32_cpu_id = ( (g_ps_periMutex->can & u32_cpu_id_mask) >> (u32_channel*3 + 1) );
                if (u32_cpu_id != CPUINFO_GetLocalCpuId())
                {
                    DLOG_Error("can channel:%ld occupied", u32_channel);
                    return -1;
                }
            }

        break;

        case MUTEX_I2C:
            if( g_ps_periMutex->i2c & (1 << (u32_channel*3)) )
            {
                u32_cpu_id = ( (g_ps_periMutex->i2c & u32_cpu_id_mask) >> (u32_channel*3 + 1) );
                if (u32_cpu_id != CPUINFO_GetLocalCpuId())
                {
                    DLOG_Error("i2c channel:%ld occupied", u32_channel);
                    return -1;
                }
            }
        break;

        case MUTEX_TIMER:
            if (u32_channel < 8)
            {
                if( g_ps_periMutex->s_timer.timer0to7 & (1 << (u32_channel*3) ) )
                {
                    u32_cpu_id = ( (g_ps_periMutex->s_timer.timer0to7 & u32_cpu_id_mask) >> (u32_channel*3 + 1) );
                    if (u32_cpu_id != CPUINFO_GetLocalCpuId())
                    {
                        DLOG_Error("timer channel:%ld occupied", u32_channel);
                        return -1;
                    }
                }
            }
            else if (u32_channel < 16)
            {
                u32_cpu_id_mask = 0;
                u32_cpu_id_mask |= (3 << (((u32_channel-8)*3)+1));
                if( g_ps_periMutex->s_timer.timer8to15 & (1 << ((u32_channel-8)*3) ) )
                {
                    u32_cpu_id = ( (g_ps_periMutex->s_timer.timer8to15 & u32_cpu_id_mask) >> ((u32_channel-8)*3 + 1) );
                    if (u32_cpu_id != CPUINFO_GetLocalCpuId())
                    {
                        DLOG_Error("timer channel:%ld occupied", u32_channel);
                        return -1;
                    }
                }
            }
            else
            {
                u32_cpu_id_mask = 0;
                u32_cpu_id_mask |= (3 << (((u32_channel-16)*3)+1));
                if( g_ps_periMutex->s_timer.timer16to23 & (1 << ((u32_channel-16)*3) ) )
                {
                    u32_cpu_id = ( (g_ps_periMutex->s_timer.timer16to23 & u32_cpu_id_mask) >> ((u32_channel-16)*3 + 1) );
                    if (u32_cpu_id != CPUINFO_GetLocalCpuId())
                    {
                        DLOG_Error("timer channel:%ld occupied", u32_channel);
                        return -1;
                    }
                }
            }
        break;

        case MUTEX_NOR_FLASH:
            if( g_ps_periMutex->nor_flash & (1 << (u32_channel*3)) )
            {
                u32_cpu_id = ( (g_ps_periMutex->nor_flash & u32_cpu_id_mask) >> (u32_channel*3 + 1) );
                if (u32_cpu_id != CPUINFO_GetLocalCpuId())
                {
                    DLOG_Error("nor flash occupied");
                    return -1;
                }
            }
        break;

        case MUTEX_DMA:
            if( g_ps_periMutex->dma & (1 << (u32_channel*3)) )
            {
                u32_cpu_id = ( (g_ps_periMutex->dma & u32_cpu_id_mask) >> (u32_channel*3 + 1) );
                if (u32_cpu_id != CPUINFO_GetLocalCpuId())
                {
                    DLOG_Error("i2c channel:%ld occupied", u32_channel);
                    return -1;
                }
            }
        break;

        default:break;
    }

    return 0;
}
