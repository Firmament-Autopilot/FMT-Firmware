/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal.c
Description: The external HAL APIs for common driver functions.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2016/1/4
History: 
        0.0.1    2016/1/4    The initial version of hal_dma.c
                   2017/5/5    change the HAL api for users
*****************************************************************************/

#include <stdint.h>
#include "drv_systick.h"
#include "hal_ret_type.h"
#include "hal.h"
#include "dma.h"
#include "debuglog.h"
// // #include "cmsis_os.h"
#include "hal_dma.h"
#include "driver_mutex.h"
#include "driver_module_init.h"

HAL_RET_T HAL_DMA_init(uint32_t u32_channels)
{
    uint8_t channel = 0;

    //check channel available
    for (channel = 0 ; channel < 4; channel++)
    {
        if (u32_channels & (0x01 << channel))
        {
            if (-1 == COMMON_driverMutexGet(MUTEX_DMA, channel))
            {
                DLOG_Error("fail, channel = %d", channel);
                return HAL_OCCUPIED;
            }
        }
    }

    //get channels
    for (channel = 0 ; channel < 4; channel++)
    {
        if (u32_channels & (0x01 << channel))
        {
            COMMON_driverMutexSet(MUTEX_DMA, channel);
        }
    }

    DMA_init();

    return HAL_OK;
}


/** 
 * @brief   Start the DMA Transfer
 * @param   u8_chanIndex  : The channel number
 * @param   u32_srcAddress: The source memory Buffer address
 * @param   u32_dstAddress: The destination memory Buffer address
 * @param   u32_dataLength: The length of data to be transferred from source to destination
 * @param   u32_timeOut: timeout threshold, unit:ms
 * @return  none
 */
HAL_RET_T HAL_DMA_Transfer(ENUM_DMA_chan e_channel,
                                            uint32_t u32_srcAddr, 
                                            uint32_t u32_dstAddr, 
                                            uint32_t u32_transByteNum, 
                                            uint32_t u32_timeOut)
{
    uint8_t hw_channel = ((e_channel == DMA_CHAN3)?3:(e_channel >> 1));
    if (hw_channel >= 4)
    {
        return HAL_DMA_CH_NO_AVAILABLE;
    }

    if (DMA_CheckChAvail(hw_channel, 4 + hw_channel) < 0)
    {
        return HAL_BUSY;
    }

    DMA_transfer(u32_srcAddr, u32_dstAddr, u32_transByteNum, hw_channel, LINK_LIST_ITEM);
    if (0 != u32_timeOut)
    {
        uint32_t u32_start = SysTicks_GetTickCount();

        while(DMA_getStatus(hw_channel) == 0)
        {
            if ((SysTicks_GetDiff(u32_start, SysTicks_GetTickCount())) >= u32_timeOut)            
            {                 
                return HAL_TIME_OUT;            
            }            

            SysTicks_DelayUS(5);
        }
    }

    return HAL_OK;
}

