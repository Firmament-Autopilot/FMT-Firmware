/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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
#include <firmament.h>

#include "adc_config.h"
#include "board.h"
#include "cy_autanalog.h"
#include "hal/adc/adc.h"

struct ifx_adc {
    struct adc_device adc_dev;
    const struct ifx_sar_adc_config* cfg;
    const char* name;
};

static struct ifx_adc ifx_adc_obj[] = {
#ifdef BSP_USING_ADC0
    ADC0_CONFIG,
#endif
};

static rt_bool_t autonomous_initialized = RT_FALSE;

static rt_err_t ifx_autonomous_analog_init_once(void)
{
    if (autonomous_initialized)
        return RT_EOK;

    if (Cy_AutAnalog_Init(&autonomous_analog_init) != CY_AUTANALOG_SUCCESS) {
        rt_kprintf("Autonomous Analog init failed\n");
        return RT_ERROR;
    }

    Cy_AutAnalog_SetInterruptMask(CY_AUTANALOG_INT_SAR0_RESULT);
    Cy_AutAnalog_StartAutonomousControl();

    autonomous_initialized = RT_TRUE;

    return RT_EOK;
}

static rt_err_t ifx_adc_enable(adc_dev_t adc_dev, uint8_t enable)
{
    if (!autonomous_initialized) {
        return RT_ERROR;
    }

    if (enable == ADC_CMD_ENABLE) {
        rt_kprintf("ADC enabled\n");
    } else if (enable == ADC_CMD_DISABLE) {
        rt_kprintf("ADC disabled\n");
    } else {
        return RT_EINVAL;
    }

    return RT_EOK;
}

static rt_err_t ifx_adc_measure(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt)
{
    struct ifx_adc* adc;
    const struct ifx_sar_adc_config* cfg;
    int32_t counts;
    int32_t mv;
    uint8_t phy_channel;

    adc = rt_container_of(adc_dev, struct ifx_adc, adc_dev);
    cfg = adc->cfg;

    /* Validate logical channel range */
    if (channel >= cfg->num_channels) {
        rt_kprintf("ADC: invalid logical channel %d (max %d)\n", channel, cfg->num_channels - 1);
        return RT_EINVAL;
    }

    /* Map logical channel to SAR result channel (GPIO0..GPIO7) */
    phy_channel = cfg->channel_map[channel];

    if (phy_channel >= 8) {
        rt_kprintf("ADC: invalid physical channel %d\n", phy_channel);
        return RT_EINVAL;
    }

    /* Force one fresh conversion result for this channel to avoid stale data. */
    {
        uint8_t ch_mask = (uint8_t)(1u << phy_channel);
        uint32_t timeout = 100000U;

        Cy_AutAnalog_SAR_ClearHSchanResultStatus(cfg->sar_idx, ch_mask);
        Cy_AutAnalog_StartAutonomousControl();

        while (timeout-- > 0U) {
            if ((Cy_AutAnalog_SAR_GetHSchanResultStatus(cfg->sar_idx) & ch_mask) != 0U) {
                break;
            }
        }

        if (timeout == 0U) {
            rt_kprintf("ADC: wait channel %d result timeout\n", phy_channel);
            return -RT_ETIMEOUT;
        }
    }

    /* Read SAR conversion result */
    counts = Cy_AutAnalog_SAR_ReadResult(
        cfg->sar_idx,
        cfg->input,
        phy_channel);

    /* Convert raw counts to millivolts */
    mv = Cy_AutAnalog_SAR_CountsTo_mVolts(
        cfg->sar_idx,
        cfg->low_power,
        cfg->sequencer,
        cfg->input,
        phy_channel,
        cfg->vref_mv,
        counts);

    /* Single-ended channels should not report negative voltage */
    if (mv < 0) {
        mv = 0;
    }

    *mVolt = (uint32_t)mv;

    return RT_EOK;
}

static const struct adc_ops ifx_adc_ops = {
    .enable = ifx_adc_enable,
    .measure = ifx_adc_measure,
};

int drv_adc_init(void)
{
    rt_err_t result;

    result = ifx_autonomous_analog_init_once();
    if (result != RT_EOK) {
        return result;
    }

    for (int i = 0;
         i < (int)(sizeof(ifx_adc_obj) / sizeof(ifx_adc_obj[0]));
         i++) {
        ifx_adc_obj[i].adc_dev.ops = &ifx_adc_ops;
        result = hal_adc_register(&ifx_adc_obj[i].adc_dev,
                                  ifx_adc_obj[i].name,
                                  RT_DEVICE_FLAG_RDONLY,
                                  RT_NULL);
        if (result != RT_EOK) {
            rt_kprintf("ADC device %s register failed: %d\n", ifx_adc_obj[i].name, result);
            return result;
        }
        rt_kprintf("ADC device %s registered (%d channels)\n",
                   ifx_adc_obj[i].name,
                   ifx_adc_obj[i].cfg->num_channels);
    }

    return RT_EOK;
}
