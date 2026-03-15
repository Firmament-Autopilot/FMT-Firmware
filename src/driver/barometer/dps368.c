/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#include "hal/barometer/barometer.h"
#include "hal/i2c/i2c.h"

#define TMP_RATE_1   0
#define TMP_RATE_2   1
#define TMP_RATE_4   2
#define TMP_RATE_8   3
#define TMP_RATE_16  4
#define TMP_RATE_32  5
#define TMP_RATE_64  6
#define TMP_RATE_128 7

#define TMP_PRC_2    1
#define TMP_PRC_4    2
#define TMP_PRC_8    3
#define TMP_PRC_16   4
#define TMP_PRC_32   5
#define TMP_PRC_64   6
#define TMP_PRC_128  7

#define PM_RATE_1    0
#define PM_RATE_2    1
#define PM_RATE_4    2
#define PM_RATE_8    3
#define PM_RATE_16   4
#define PM_RATE_32   5
#define PM_RATE_64   6
#define PM_RATE_128  7

#define PM_PRC_1     0
#define PM_PRC_2     1
#define PM_PRC_4     2
#define PM_PRC_8     3
#define PM_PRC_16    4
#define PM_PRC_32    5
#define PM_PRC_64    6
#define PM_PRC_128   7

static rt_device_t bus_dev;
static uint8_t tmp_ext;
static float last_temp;
static uint8_t m_temp_prc;
static uint8_t m_pressure_prc;

static int32_t c0_half;
static int32_t c1;
static int32_t c00;
static int32_t c10;
static int32_t c01;
static int32_t c11;
static int32_t c20;
static int32_t c21;
static int32_t c30;

const int32_t scaling_facts[] = { 524288, 1572864, 3670016, 7864320, 253952, 516096, 1040384, 2088960 };

static void getTwosComplement(int32_t* raw, uint8_t length)
{
    if (*raw & ((uint32_t)1 << (length - 1))) {
        *raw -= (uint32_t)1 << length;
    }
}

static rt_err_t config_temp(uint8_t temp_rate, uint8_t temp_prc)
{
    uint8_t reg_val = tmp_ext | (temp_rate << 4) | temp_prc;

    RT_TRY(i2c_write_reg(bus_dev, 0x07, reg_val));

    // set TEMP SHIFT ENABLE if oversampling rate higher than eight
    RT_TRY(i2c_read_reg(bus_dev, 0x09, &reg_val));
    if (temp_prc > PM_PRC_8) {
        reg_val |= (1 << 2);
    } else {
        reg_val &= 0xFB;
    }
    RT_TRY(i2c_write_reg(bus_dev, 0x09, reg_val));

    m_temp_prc = temp_prc;

    return RT_EOK;
}

static rt_err_t config_pressure(uint8_t pressure_rate, uint8_t pressure_prc)
{
    uint8_t reg_val = (pressure_rate << 4) | pressure_prc;

    RT_TRY(i2c_write_reg(bus_dev, 0x06, reg_val));

    // set PM SHIFT ENABLE if oversampling rate higher than eight
    RT_TRY(i2c_read_reg(bus_dev, 0x09, &reg_val));
    if (pressure_prc > TMP_PRC_8) {
        reg_val |= (1 << 3);
    } else {
        reg_val &= 0xF7;
    }
    RT_TRY(i2c_write_reg(bus_dev, 0x09, reg_val));

    m_pressure_prc = pressure_prc;

    return RT_EOK;
}

static rt_err_t read_coeffs(void)
{
    uint8_t buffer[18] = { 0 };

    RT_TRY(i2c_read_regs(bus_dev, 0x10, buffer, sizeof(buffer)));

    c0_half = ((uint32_t)buffer[0] << 4) | (((uint32_t)buffer[1] >> 4) & 0x0F);
    getTwosComplement(&c0_half, 12);
    // c0 is only used as c0*0.5, so c0_half is calculated immediately
    c0_half = c0_half / 2U;

    // now do the same thing for all other coefficients
    c1 = (((uint32_t)buffer[1] & 0x0F) << 8) | (uint32_t)buffer[2];
    getTwosComplement(&c1, 12);
    c00 = ((uint32_t)buffer[3] << 12) | ((uint32_t)buffer[4] << 4) | (((uint32_t)buffer[5] >> 4) & 0x0F);
    getTwosComplement(&c00, 20);
    c10 = (((uint32_t)buffer[5] & 0x0F) << 16) | ((uint32_t)buffer[6] << 8) | (uint32_t)buffer[7];
    getTwosComplement(&c10, 20);

    c01 = ((uint32_t)buffer[8] << 8) | (uint32_t)buffer[9];
    getTwosComplement(&c01, 16);

    c11 = ((uint32_t)buffer[10] << 8) | (uint32_t)buffer[11];
    getTwosComplement(&c11, 16);
    c20 = ((uint32_t)buffer[12] << 8) | (uint32_t)buffer[13];
    getTwosComplement(&c20, 16);
    c21 = ((uint32_t)buffer[14] << 8) | (uint32_t)buffer[15];
    getTwosComplement(&c21, 16);
    c30 = ((uint32_t)buffer[16] << 8) | (uint32_t)buffer[17];
    getTwosComplement(&c30, 16);

    return RT_EOK;
}

static float calc_temp(int32_t raw)
{
    float temp = raw;

    // scale temperature according to scaling table and oversampling
    temp /= scaling_facts[m_temp_prc];

    // update last measured temperature
    // it will be used for pressure compensation
    last_temp = temp;

    // Calculate compensated temperature in Deg
    temp = c0_half + c1 * temp;

    return temp;
}

static float calc_pressure(int32_t raw)
{
    float prs = raw;

    // scale pressure according to scaling table and oversampling
    prs /= scaling_facts[m_pressure_prc];

    // Calculate compensated pressure in Pa
    prs = c00 + prs * (c10 + prs * (c20 + prs * c30)) + last_temp * (c01 + prs * (c11 + prs * c21));

    // return pressure
    return prs;
}

static rt_err_t get_raw_result(uint8_t reg, int32_t* raw)
{
    uint8_t buffer[3] = { 0 };

    RT_TRY(i2c_read_regs(bus_dev, reg, buffer, sizeof(buffer)));

    *raw = (uint32_t)buffer[0] << 16 | (uint32_t)buffer[1] << 8 | (uint32_t)buffer[2];

    getTwosComplement(raw, 24);

    return RT_EOK;
}

static rt_err_t baro_control(baro_dev_t baro, int cmd, void* arg)
{
    rt_err_t res = RT_EOK;

    switch (cmd) {
    case BARO_CMD_CHECK_READY: {
        DEFINE_TIMETAG(baro_interval, 10);
        *(uint8_t*)arg = check_timetag(TIMETAG(baro_interval));

        // uint8_t reg_val = 0;
        // res = i2c_read_reg(bus_dev, 0x08, &reg_val);
        // if (res == RT_EOK) {
        //     *(uint8_t*)arg = ((reg_val & 0x30) == 0x30);
        // } else {
        //     *(uint8_t*)arg = 0;
        // }
    } break;

    default:
        break;
    }

    return res;
}

static rt_size_t baro_read(baro_dev_t baro, baro_report_t* report)
{
    int32_t raw;
    float temp, pressure;

    if (get_raw_result(0x03, &raw) == RT_EOK) {
        temp = calc_temp(raw);
    } else {
        return 0;
    }

    if (get_raw_result(0x00, &raw) == RT_EOK) {
        pressure = calc_pressure(raw);
    } else {
        return 0;
    }

    report->pressure_Pa = pressure;
    report->temperature_deg = temp;
    report->altitude_m = 44330.0f * (1.0f - powf(report->pressure_Pa / 101325.0f, 1.0f / 5.255f));
    report->timestamp_ms = systime_now_ms();

    return sizeof(baro_report_t);
}

static rt_err_t dps368_init(void)
{
    uint8_t reg_val = 0;

    RT_TRY(i2c_read_reg(bus_dev, 0x0D, &reg_val));

    if (0x10 != reg_val) {
        return RT_ERROR;
    }

    RT_TRY(i2c_read_reg(bus_dev, 0x28, &reg_val));
    tmp_ext |= reg_val & 0x80;

    RT_TRY(read_coeffs());

    RT_TRY(config_temp(TMP_RATE_128, TMP_PRC_2));
    RT_TRY(config_pressure(PM_RATE_128, PM_PRC_4));

    RT_TRY(i2c_write_reg(bus_dev, 0x08, 0x07)); /* continues pressure and temperature measurement */

    return RT_EOK;
}

static struct baro_ops _baro_ops = {
    .baro_control = baro_control,
    .baro_read = baro_read
};

rt_err_t drv_dps368_init(const char* device_name, const char* baro_device_name)
{
    static struct baro_device baro_dev = {
        .ops = &_baro_ops
    };

    bus_dev = rt_device_find(device_name);
    RT_ASSERT(bus_dev != NULL);

    RT_TRY(rt_device_open(bus_dev, RT_DEVICE_OFLAG_RDWR));

    /* sensor initialization */
    RT_TRY(dps368_init());

    /* register barometer device */
    RT_TRY(hal_baro_register(&baro_dev, baro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}