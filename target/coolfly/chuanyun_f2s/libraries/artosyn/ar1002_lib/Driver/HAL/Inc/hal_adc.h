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


#ifndef __HAL_ADC___
#define __HAL_ADC___

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>


/** 
 * @brief   read the ADC value from the input
 * @param   channel:         select the channel x input into AR8020
 * @param   nextChannel:     select the next channel x input into AR8020,
 * sample rate = 25MHz/12 = 2.0833MHz;
 * Sample interval = 0.48us;
 * Adc value = (3.3 / 1024 * adc_register_value) V
 * @return  the digital value of ADC register value
 */

uint32_t HAL_ADC_Read(uint8_t channel, uint8_t nextChannel);

#ifdef __cplusplus
}
#endif

#endif
