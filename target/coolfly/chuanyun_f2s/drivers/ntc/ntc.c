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
#include "board.h"
#include <firmament.h>
#include <math.h>

#include "hal_temperature.h"
#include "module/math/conversion.h"
#include "module/workqueue/workqueue_manager.h"
#include "ntc.h"

#define DRV_DBG(...) printf(__VA_ARGS__)
#define POW2(_x)     ((_x) * (_x))

static rt_device_t adc_device;

#define PULLUP_PARTICAL_RESISTANCE (10000) // 10k
#define NTC_ADC_CHANNEL            (9)     // adc7

const uint16_t NTC_4K7_B3475_T0d_T99d_table[100] = {
    13954, 13309, 12698, 12119, 11571, 11051, 10558, 10090, 9646, 9224, 8824, 8443, 8082, 7738, 7412, 7101, 6805, 6523, 6255, 6000, 5757, 5525, 5304, 5093, 4892, 4700, 4517, 4342, 4175, 4015, 3863, 3717, 3578, 3445, 3317, 3195, 3079, 2967, 2860, 2757, 2659, 2565, 2475, 2388, 2305, 2226, 2149, 2076, 2006, 1938, 1873, 1811, 1751, 1694, 1638, 1585, 1534, 1485, 1437, 1392, 1348, 1305, 1265, 1226, 1188, 1152, 1116, 1083, 1050, 1019, 988, 959, 931, 904, 877, 852, 828, 804, 781, 759, 738, 717, 697, 678, 659, 641, 624, 607, 591, 575, 560, 545, 530, 517, 503, 490, 477, 465, 453, 442
};

_EXT_DTCM1
uint32_t Convert_ADC_Valure_to_Voltage(uint32_t adc_val)
{
    // Para: void
    // return Voltage in mV
    return ((adc_val * 3300) >> 10);
}

_EXT_DTCM1
uint32_t Calc_NTC_Resistance(uint32_t voltage_mv)
{
    uint32_t Res = voltage_mv * PULLUP_PARTICAL_RESISTANCE / (3300 - voltage_mv);
    return Res;
}

_EXT_DTCM1
uint8_t Calc_NTC_Temperature_Celsius_Degree(uint32_t ntc_res)
{
    // uint32_t ntc_res,  NTC resistor value
    // return: uint8_t ,  temperature in Celsius degree
    if ((ntc_res > NTC_4K7_B3475_T0d_T99d_table[0]) || (ntc_res < NTC_4K7_B3475_T0d_T99d_table[99])) {
        return 0xFF;
    }

    uint8_t i;
    for (i = 0; i < 99; i++) {
        if (ntc_res > NTC_4K7_B3475_T0d_T99d_table[i]) {
            return i;
        }
    }

    return 0xFF;
}

_EXT_DTCM1
static rt_err_t read_adc(uint32_t* buff)
{
    if (rt_device_read(adc_device, NTC_ADC_CHANNEL, buff, 1) != 1) {
        console_printf("read adc9 fail\r\n");
        return RT_ERROR;
    }

    // console_printf("read adc val=%d" , buff[0]);

    return RT_EOK;
}

_EXT_DTCM1
static void ntc_measure(float* temp)
{
    uint32_t voltage_mv;
    uint32_t ntc_res;
    uint8_t  ntc_temp;
    /* read raw pressure */
    if (read_adc(&voltage_mv) == RT_EOK) {
        // voltage_mv = Convert_ADC_Valure_to_Voltage(_raw_adc_value);
        ntc_res  = Calc_NTC_Resistance(voltage_mv);
        ntc_temp = Calc_NTC_Temperature_Celsius_Degree(ntc_res);
    }

    *temp = (float)ntc_temp;
    // console_printf("ntc temp=%d\r\n" , ntc_temp);
}

_EXT_DTCM1
static rt_size_t ntc_read(temperature_dev_t ntc_dev, temperature_report_t* report)
{
    float temp;
    ntc_measure(&temp);

    report->timestamp_ms    = systime_now_ms();
    report->temperature_deg = temp;

    // console_printf("ntc temp=%f, return %d byte\r\n" , report->temperature_deg, sizeof(temperature_report_t));
    return sizeof(temperature_report_t);
}

static struct temperature_ops _temperature_ops = {
    ntc_read,
};

_EXT_DTCM1
rt_err_t drv_ntc_init(const char* adc_device_name, const char* temperature_device_name)
{
    static struct temperature_device temperature_device = {
        .ops = &_temperature_ops
    };

    adc_device = rt_device_find(adc_device_name);
    RT_ASSERT(adc_device != NULL);

    RT_CHECK(rt_device_open(adc_device, RT_DEVICE_OFLAG_RDONLY));

    RT_TRY(hal_temperature_register(&temperature_device, temperature_device_name, RT_DEVICE_FLAG_RDONLY, RT_NULL));

    return RT_EOK;
}
