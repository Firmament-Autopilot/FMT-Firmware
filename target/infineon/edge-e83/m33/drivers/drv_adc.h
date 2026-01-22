/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-03-28     shelton      first version
 */

#ifndef __ADC_CONFIG_H__
#define __ADC_CONFIG_H__

#include <rtthread.h>
#include "mtb_hal_adc.h"



#ifdef __cplusplus
extern "C"
{
#endif

#if defined(BSP_USING_ADC1) || defined(BSP_USING_ADC2)


mtb_hal_adc_channel_t adc_chan_obj;

#endif

#ifndef ADC1_CONFIG
#define ADC1_CONFIG                 \
    {                               \
        .adc_ch = &adc_chan_obj,    \
        .name = "adc1",             \
    }
#endif /* ADC1_CONFIG */


#ifdef __cplusplus
}
#endif

#endif /* __ADC_CONFIG_H__ */
