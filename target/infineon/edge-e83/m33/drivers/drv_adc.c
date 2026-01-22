/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-04     Rbb666       first version
 */

#include <rtthread.h>
#include "drv_adc.h"
#include "board.h"
#include "mtb_hal_adc.h"

#if defined(BSP_USING_ADC1) || defined(BSP_USING_ADC2)

//#define DRV_DEBUG
#define LOG_TAG             "drv.adc"
#include <drv_log.h>

#ifdef SOC_SERIES_IFX_PSOCE84
    #define VPLUS_CHANNEL_0     (P15_5)
    #define SAR_ADC_INDEX               (0U)
    #define SAR_ADC_SEQENCER            (0U)
    #define SAR_ADC_CHANNEL             (0U)
    #define SAR_ADC_VREF_MV             (1800U)
#endif

struct ifx_adc
{
    struct rt_adc_device ifx_adc_device;
    mtb_hal_adc_channel_t *adc_ch;
    char *name;
};

static struct ifx_adc ifx_adc_obj[] =
{
#ifdef BSP_USING_ADC1
    ADC1_CONFIG,
#endif
};

static rt_err_t ifx_adc_enabled(struct rt_adc_device *device, rt_int8_t channel, rt_bool_t enabled)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    result = Cy_AutAnalog_Init(&autonomous_analog_init);
    if (CY_AUTANALOG_SUCCESS != result)
    {
        rt_kprintf("Autonomous control initialization failed!\n");
    }
    Cy_AutAnalog_SetInterruptMask(CY_AUTANALOG_INT_SAR0_RESULT);
    Cy_AutAnalog_StartAutonomousControl();

    return RT_EOK;
}


static rt_err_t ifx_get_adc_value(struct rt_adc_device *device, rt_int8_t channel, rt_uint32_t *value)
{
    uint32_t sar_adc_count;
    uint16_t sar_adc_mv;

    sar_adc_count = Cy_AutAnalog_SAR_ReadResult(SAR_ADC_INDEX,
                    CY_AUTANALOG_SAR_INPUT_GPIO,
                    SAR_ADC_CHANNEL);

    sar_adc_mv = Cy_AutAnalog_SAR_CountsTo_mVolts(SAR_ADC_INDEX, false,
                 SAR_ADC_SEQENCER,
                 CY_AUTANALOG_SAR_INPUT_GPIO,
                 SAR_ADC_CHANNEL,
                 SAR_ADC_VREF_MV,
                 sar_adc_count);

    *value = sar_adc_mv;
    return RT_EOK;
}

static const struct rt_adc_ops at_adc_ops =
{
    .enabled = ifx_adc_enabled,
    .convert = ifx_get_adc_value,
};

static int rt_hw_adc_init(void)
{
    int result = RT_EOK;
    int i = 0;

    for (i = 0; i < sizeof(ifx_adc_obj) / sizeof(ifx_adc_obj[0]); i++)
    {
        /* register ADC device */
        if (rt_hw_adc_register(&ifx_adc_obj[i].ifx_adc_device, ifx_adc_obj[i].name, &at_adc_ops, ifx_adc_obj[i].adc_ch) == RT_EOK)
        {
            LOG_D("%s register success", at32_adc_obj[i].name);
        }
        else
        {
            LOG_E("%s register failed", ifx_adc_obj[i].name);
            result = -RT_ERROR;
        }
    }

    return result;
}
INIT_BOARD_EXPORT(rt_hw_adc_init);

#endif /* BSP_USING_ADC */
