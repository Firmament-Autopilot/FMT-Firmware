/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

#include "hal/adc/adc.h"
#include "hal/i2c/i2c.h"

#define INA228_REG_CONFIG        0x00
#define INA228_REG_ADC_CONFIG    0x01
#define INA228_REG_SHUNT_CAL     0x02
#define INA228_REG_SHUNT_TEMP_CO 0x03
#define INA228_REG_SHUNT_VOLTAGE 0x04
#define INA228_REG_BUS_VOLTAGE   0x05
#define INA228_REG_TEMPERATURE   0x06
#define INA228_REG_CURRENT       0x07
#define INA228_REG_POWER         0x08
#define INA228_REG_ENERGY        0x09
#define INA228_REG_CHARGE        0x0A
#define INA228_REG_DIAG_ALERT    0x0B
#define INA228_REG_MANUFACTURER  0x3E
#define INA228_REG_DEVICE_ID     0x3F

#define INA228_ADC_MODE_OFS      12
#define INA228_ADC_VBUSCT_OFS    9
#define INA228_ADC_VSHCT_OFS     6
#define INA228_ADC_VTCT_OFS      3

#define INA228_MAX_CURRENT_A     50.0f
#define INA228_SHUNT_OHM         0.0005f

static rt_device_t i2c_dev;
static float current_lsb;
static float shunt_cal;
static bool adc_range_41mv;

static int32_t ina228_sign_extend_20(uint32_t value)
{
    value >>= 4;
    if ((value & 0x00080000) != 0) {
        value |= 0xFFF00000;
    }

    return (int32_t)value;
}

static rt_err_t ina228_read_reg(rt_device_t i2c_dev, uint8_t reg, uint8_t* buffer, uint16_t count)
{
    uint8_t buf[5];

    if (count > 5)
        return RT_EINVAL;

    RT_TRY(i2c_read_regs(i2c_dev, reg, buf, 2));

    for (uint8_t i = 0; i < count; i++) {
        buffer[count - 1 - i] = buf[i];
    }

    return RT_EOK;
}

static rt_err_t ina228_write_reg(rt_device_t i2c_dev, uint8_t reg, uint16_t val)
{
    uint8_t buf[3];
    struct rt_i2c_device* i2c_device = (struct rt_i2c_device*)i2c_dev;

    buf[0] = reg;
    buf[1] = (rt_uint8_t)(val >> 8);
    buf[2] = (rt_uint8_t)(val & 0xFF);

    if (rt_i2c_master_send(i2c_device->bus, i2c_device->slave_addr, 0, buf, sizeof(buf)) != sizeof(buf)) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static float ina228_get_bus_voltage(rt_device_t i2c_dev)
{
    uint32_t raw = 0;
    float voltage_v = 0.0f;

    if (ina228_read_reg(i2c_dev, INA228_REG_BUS_VOLTAGE, &raw, 3) == RT_EOK) {
        voltage_v = (float)(raw >> 4) * 195.3125e-6f;
    }

    return voltage_v;
}

static float ina228_get_shunt_voltage(rt_device_t i2c_dev)
{
    uint32_t raw = 0;
    float shunt_lsb;

    float voltage_v = 0.0f;

    if (ina228_read_reg(i2c_dev, INA228_REG_SHUNT_VOLTAGE, &raw, 3) == RT_EOK) {
        shunt_lsb = (adc_range_41mv == RT_TRUE) ? 78.125e-9f : 312.5e-9f;
        voltage_v = (float)ina228_sign_extend_20(raw) * shunt_lsb;
    }

    return voltage_v;
}

static float ina228_get_current(rt_device_t i2c_dev)
{
    uint32_t raw = 0;
    float current_a = 0.0f;

    if (ina228_read_reg(i2c_dev, INA228_REG_CURRENT, &raw, 3) == RT_EOK) {
        current_a = (float)ina228_sign_extend_20(raw) * current_lsb;
    }

    return current_a;
}

static rt_err_t adc_measure(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt)
{
    float bus_volt, current;

    switch (channel) {
    case BAT1_V_CHANNEL:
        /* Bat1 Volt */
        bus_volt = ina228_get_bus_voltage(i2c_dev);
        *mVolt = bus_volt * 1000;
        break;
    case BAT1_I_CHANNEL:
        /* Bat1 Current */
        current = ina228_get_current(i2c_dev);
        *mVolt = current / PARAM_GET_FLOAT(POWER, BAT_A_PER_V) * 1000;
        break;
    default:
        return RT_EINVAL;
    }

    return RT_EOK;
}

static struct adc_device adc0;
static const struct adc_ops adc_ops = {
    .enable = NULL,
    .measure = adc_measure
};

rt_err_t drv_ina228_init(const char* i2c_device_name, const char* device_name)
{
    uint16_t reg_val;
    uint16_t dev_id;

    i2c_dev = rt_device_find(i2c_device_name);
    RT_ASSERT(i2c_dev != NULL);

    RT_TRY(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(ina228_read_reg(i2c_dev, INA228_REG_DEVICE_ID, &dev_id, 2));
    if (dev_id != 0x2281) {
        /* invalid id */
        return RT_ERROR;
    }

    /* set scale range of +-40.96mv */
    RT_TRY(ina228_write_reg(i2c_dev, INA228_REG_CONFIG, 1 << 4));

    current_lsb = INA228_MAX_CURRENT_A * 1.9073486328125e-6f;
    shunt_cal = 13107.2e6f * current_lsb * INA228_SHUNT_OHM;
    RT_TRY(ina228_read_reg(i2c_dev, INA228_REG_CONFIG, &reg_val, 2));
    adc_range_41mv = reg_val & (1 << 4);
    if (adc_range_41mv) {
        shunt_cal *= 4.0f;
    }
    RT_TRY(ina228_write_reg(i2c_dev, INA228_REG_SHUNT_CAL, (rt_uint16_t)(shunt_cal + 0.5f)));

    /*  Continuous shunt and bus voltage, 1052us conversion time, 16 samples */
    RT_TRY(ina228_write_reg(i2c_dev, INA228_REG_ADC_CONFIG, 0x0B << INA228_ADC_MODE_OFS | 5 << INA228_ADC_VBUSCT_OFS | 5 << INA228_ADC_VSHCT_OFS | 5 << INA228_ADC_VTCT_OFS | 2));

    /* We masquerade the INA228 as an ADC for use by the upper-level PMU module */
    adc0.ops = &adc_ops;
    RT_TRY(hal_adc_register(&adc0, "adc0", RT_DEVICE_FLAG_RDONLY, NULL));

    return RT_EOK;
}
