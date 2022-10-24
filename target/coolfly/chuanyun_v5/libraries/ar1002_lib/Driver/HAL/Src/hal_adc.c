/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_adc.h
Description: The external HAL APIs to use the I2C controller.
Author: Artosy Software Team
Version: 0.0.1
Date: 2017/1/23
History: 
        0.0.1    2017/1/23    The initial version of hal_adc.h
*****************************************************************************/


#include <stdint.h>
#include "reg_rw.h"
#include "debuglog.h"
#include "drv_systick.h"
#include "hal_adc.h"

/** 
 * @brief   read the ADC value from the input
 * @param   channel:         select the channel x input into AR8020
 * @param   nextChannel:     select the next channel x input into AR8020,
 * sample rate = 25MHz/12 = 2.0833MHz;
 * Sample interval = 0.48us;
 * Adc value = (3.3 / 1024 * adc_register_value) V
 * @return  the digital value of ADC register value
 */

uint8_t  s_u8_AdcChannelBack = 0;
uint64_t s_u64_AdcTickBack = 0;

uint32_t HAL_ADC_Read(uint8_t channel, uint8_t nextChannel)
{
    uint32_t u32_dateAddr = 0x40B000F4;
    uint32_t u32_SarAddr = 0x40B000EC;
    
    if (s_u8_AdcChannelBack != channel)
    {
        Reg_Write32(u32_SarAddr, channel << 2);
        SysTicks_DelayUS(5);
        s_u8_AdcChannelBack = channel;
    }
    else
    {
        uint64_t u64_usDiff = SysTicks_GetUsDiff(s_u64_AdcTickBack, SysTicks_GetUsTickCount());
        if (u64_usDiff < 5)
        {
            SysTicks_DelayUS(5-u64_usDiff);
        }
    }
    
    uint32_t u32_recValue = Reg_Read32(u32_dateAddr);

    if (s_u8_AdcChannelBack != nextChannel)
    {
        Reg_Write32(u32_SarAddr, nextChannel << 2);
        s_u8_AdcChannelBack = nextChannel;
        s_u64_AdcTickBack = SysTicks_GetUsTickCount();
    }


    return u32_recValue;
}
