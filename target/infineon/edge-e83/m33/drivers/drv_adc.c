/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <rtthread.h>
#include <rtdevice.h>
#include "drv_adc.h"
#include "adc_config.h"
#include "board.h"
#include "cy_autanalog.h"

#if defined(BSP_USING_ADC1)

/*#define DRV_DEBUG*/
#define LOG_TAG "drv.adc"
#include <drv_log.h>

struct ifx_adc
{
    struct rt_adc_device adc_dev;
    const struct ifx_sar_adc_config *cfg;
    const char *name;
};

static struct ifx_adc ifx_adc_obj[] =
{
    ADC1_CONFIG,
};

static rt_bool_t autanalog_inited = RT_FALSE;

static void ifx_autanalog_init_once(void)
{
    if (autanalog_inited)
        return;

    if (Cy_AutAnalog_Init(&autonomous_analog_init) != CY_AUTANALOG_SUCCESS)
    {
        LOG_E("Autonomous Analog init failed");
        return;
    }

    Cy_AutAnalog_SetInterruptMask(CY_AUTANALOG_INT_SAR0_RESULT);
    Cy_AutAnalog_StartAutonomousControl();

    autanalog_inited = RT_TRUE;
}

/* ADC enable */
static rt_err_t ifx_adc_enabled(struct rt_adc_device *device,
                               rt_uint32_t channel,
                               rt_bool_t enabled)
{
    ifx_autanalog_init_once();
    return RT_EOK;
}

/* ADC convert */
static rt_err_t ifx_adc_convert(struct rt_adc_device *device,
                                rt_uint32_t channel,
                                rt_uint32_t *value)
{
    struct ifx_adc *adc;
    const struct ifx_sar_adc_config *cfg;
    int32_t counts;
    int16_t mv;

    adc = rt_container_of(device, struct ifx_adc, adc_dev);
    cfg = adc->cfg;

    counts = Cy_AutAnalog_SAR_ReadResult(
                cfg->sar_idx,
                cfg->input,
                cfg->channel);

    mv = Cy_AutAnalog_SAR_CountsTo_mVolts(
                cfg->sar_idx,
                cfg->low_power,
                cfg->sequencer,
                cfg->input,
                cfg->channel,
                cfg->vref_mv,
                counts);

    *value = (rt_uint32_t)mv;
    return RT_EOK;
}

static const struct rt_adc_ops ifx_adc_ops =
{
    .enabled = ifx_adc_enabled,
    .convert = ifx_adc_convert,
};

int rt_hw_adc_init(void)
{
    rt_err_t result;

    for (int i = 0;
         i < (int)(sizeof(ifx_adc_obj) / sizeof(ifx_adc_obj[0]));
         i++)
    {
        result = rt_hw_adc_register(&ifx_adc_obj[i].adc_dev,
                                    ifx_adc_obj[i].name,
                                    &ifx_adc_ops,
                                    RT_NULL);
        if (result != RT_EOK)
        {
            LOG_E("%s register failed", ifx_adc_obj[i].name);
            return result;
        }
    }

    return RT_EOK;
}
INIT_BOARD_EXPORT(rt_hw_adc_init);

#endif /* BSP_USING_ADC1*/
