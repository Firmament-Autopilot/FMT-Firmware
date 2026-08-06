#include "driver/pmu/ina228.h"

#define INA228_REG_CONFIG        0x00
#define INA228_REG_ADC_CONFIG    0x01
#define INA228_REG_SHUNT_CAL     0x02
#define INA228_REG_SHUNT_VOLTAGE 0x04
#define INA228_REG_BUS_VOLTAGE   0x05
#define INA228_REG_TEMPERATURE   0x06
#define INA228_REG_CURRENT       0x07
#define INA228_REG_DIAG_ALERT    0x0B
#define INA228_REG_MANUFACTURER  0x3E
#define INA228_REG_DEVICE_ID     0x3F

#define INA228_CFG_RSTACC   0x4000
#define INA228_CFG_ADCRANGE 0x0010

#define INA228_ADC_MODE   0xF000
#define INA228_ADC_VBUSCT 0x0E00
#define INA228_ADC_VSHCT  0x01C0
#define INA228_ADC_VTCT   0x0038
#define INA228_ADC_AVG    0x0007

static rt_err_t ina228_read_reg(ina228_t* dev, rt_uint8_t reg, rt_uint8_t bytes, rt_uint32_t* value)
{
    rt_uint8_t buf[5] = { 0 };
    struct rt_i2c_msg msgs[2];
    rt_uint32_t result = 0;

    if ((dev == RT_NULL) || (dev->bus == RT_NULL) || (value == RT_NULL) || (bytes == 0) || (bytes > sizeof(buf))) {
        return -RT_EINVAL;
    }

    msgs[0].flags = RT_I2C_WR;
    msgs[0].buf = &reg;
    msgs[0].len = 1;

    msgs[1].flags = RT_I2C_RD;
    msgs[1].buf = buf;
    msgs[1].len = bytes;

    if (rt_i2c_transfer(dev->bus, dev->addr, msgs, 2) != 2) {
        dev->last_error = -RT_ERROR;
        return dev->last_error;
    }

    for (rt_uint8_t i = 0; i < bytes; i++) {
        result <<= 8;
        result |= buf[i];
    }

    *value = result;
    dev->last_error = RT_EOK;
    return RT_EOK;
}

static rt_err_t ina228_write_reg(ina228_t* dev, rt_uint8_t reg, rt_uint16_t value)
{
    rt_uint8_t buf[3];

    if ((dev == RT_NULL) || (dev->bus == RT_NULL)) {
        return -RT_EINVAL;
    }

    buf[0] = reg;
    buf[1] = (rt_uint8_t)(value >> 8);
    buf[2] = (rt_uint8_t)(value & 0xFF);

    if (rt_i2c_master_send(dev->bus, dev->addr, 0, buf, sizeof(buf)) != sizeof(buf)) {
        dev->last_error = -RT_ERROR;
        return dev->last_error;
    }

    dev->last_error = RT_EOK;
    return RT_EOK;
}

static rt_err_t ina228_read_u16(ina228_t* dev, rt_uint8_t reg, rt_uint16_t* value)
{
    rt_uint32_t raw = 0;
    rt_err_t result;

    if (value == RT_NULL) {
        return -RT_EINVAL;
    }

    result = ina228_read_reg(dev, reg, 2, &raw);
    if (result == RT_EOK) {
        *value = (rt_uint16_t)raw;
    }

    return result;
}

static rt_int32_t ina228_sign_extend_20(rt_uint32_t value)
{
    value >>= 4;
    if ((value & 0x00080000) != 0) {
        value |= 0xFFF00000;
    }

    return (rt_int32_t)value;
}

rt_err_t ina228_init(ina228_t* dev, const char* i2c_bus_name, rt_uint8_t addr)
{
    rt_err_t result;

    if ((dev == RT_NULL) || (i2c_bus_name == RT_NULL)) {
        return -RT_EINVAL;
    }

    rt_memset(dev, 0, sizeof(*dev));
    dev->bus = (struct rt_i2c_bus*)rt_device_find(i2c_bus_name);
    if ((dev->bus == RT_NULL) || (dev->bus->parent.type != RT_Device_Class_I2CBUS)) {
        return -RT_ENOSYS;
    }

    dev->addr = addr;
    dev->shunt_ohm = 0.0005f;
    dev->max_current_a = 50.0f;
    dev->current_lsb = dev->max_current_a * 1.9073486328125e-6f;
    dev->adc_range_41mv = RT_FALSE;

    result = ina228_get_adc_range(dev, &dev->adc_range_41mv);
    if (result != RT_EOK) {
        return result;
    }

    return RT_EOK;
}

rt_bool_t ina228_is_connected(ina228_t* dev)
{
    rt_uint16_t manufacturer = 0;

    if (ina228_get_manufacturer(dev, &manufacturer) != RT_EOK) {
        return RT_FALSE;
    }

    return (manufacturer == INA228_MANUFACTURER_ID) ? RT_TRUE : RT_FALSE;
}

rt_err_t ina228_reset_accumulation(ina228_t* dev)
{
    rt_uint16_t value = 0;
    rt_err_t result = ina228_read_u16(dev, INA228_REG_CONFIG, &value);

    if (result != RT_EOK) {
        return result;
    }

    return ina228_write_reg(dev, INA228_REG_CONFIG, value | INA228_CFG_RSTACC);
}

rt_err_t ina228_set_adc_range(ina228_t* dev, rt_bool_t range_41mv)
{
    rt_uint16_t value = 0;
    rt_err_t result = ina228_read_u16(dev, INA228_REG_CONFIG, &value);

    if (result != RT_EOK) {
        return result;
    }

    if (range_41mv == RT_TRUE) {
        value |= INA228_CFG_ADCRANGE;
    } else {
        value &= (rt_uint16_t)~INA228_CFG_ADCRANGE;
    }

    result = ina228_write_reg(dev, INA228_REG_CONFIG, value);
    if (result == RT_EOK) {
        dev->adc_range_41mv = range_41mv;
    }

    return result;
}

rt_err_t ina228_get_adc_range(ina228_t* dev, rt_bool_t* range_41mv)
{
    rt_uint16_t value = 0;
    rt_err_t result;

    if (range_41mv == RT_NULL) {
        return -RT_EINVAL;
    }

    result = ina228_read_u16(dev, INA228_REG_CONFIG, &value);
    if (result == RT_EOK) {
        *range_41mv = ((value & INA228_CFG_ADCRANGE) != 0) ? RT_TRUE : RT_FALSE;
        dev->adc_range_41mv = *range_41mv;
    }

    return result;
}

rt_err_t ina228_set_mode(ina228_t* dev, rt_uint8_t mode)
{
    rt_uint16_t value = 0;
    rt_err_t result;

    if (mode > 0x0F) {
        return -RT_EINVAL;
    }

    result = ina228_read_u16(dev, INA228_REG_ADC_CONFIG, &value);
    if (result != RT_EOK) {
        return result;
    }

    value &= (rt_uint16_t)~INA228_ADC_MODE;
    value |= (rt_uint16_t)(mode << 12);

    return ina228_write_reg(dev, INA228_REG_ADC_CONFIG, value);
}

rt_err_t ina228_set_average(ina228_t* dev, rt_uint8_t average)
{
    rt_uint16_t value = 0;
    rt_err_t result;

    if (average > 7) {
        return -RT_EINVAL;
    }

    result = ina228_read_u16(dev, INA228_REG_ADC_CONFIG, &value);
    if (result != RT_EOK) {
        return result;
    }

    value &= (rt_uint16_t)~INA228_ADC_AVG;
    value |= average;

    return ina228_write_reg(dev, INA228_REG_ADC_CONFIG, value);
}

rt_err_t ina228_set_bus_voltage_conversion_time(ina228_t* dev, rt_uint8_t timing)
{
    rt_uint16_t value = 0;
    rt_err_t result;

    if (timing > 7) {
        return -RT_EINVAL;
    }

    result = ina228_read_u16(dev, INA228_REG_ADC_CONFIG, &value);
    if (result != RT_EOK) {
        return result;
    }

    value &= (rt_uint16_t)~INA228_ADC_VBUSCT;
    value |= (rt_uint16_t)(timing << 9);

    return ina228_write_reg(dev, INA228_REG_ADC_CONFIG, value);
}

rt_err_t ina228_set_shunt_voltage_conversion_time(ina228_t* dev, rt_uint8_t timing)
{
    rt_uint16_t value = 0;
    rt_err_t result;

    if (timing > 7) {
        return -RT_EINVAL;
    }

    result = ina228_read_u16(dev, INA228_REG_ADC_CONFIG, &value);
    if (result != RT_EOK) {
        return result;
    }

    value &= (rt_uint16_t)~INA228_ADC_VSHCT;
    value |= (rt_uint16_t)(timing << 6);

    return ina228_write_reg(dev, INA228_REG_ADC_CONFIG, value);
}

rt_err_t ina228_set_temperature_conversion_time(ina228_t* dev, rt_uint8_t timing)
{
    rt_uint16_t value = 0;
    rt_err_t result;

    if (timing > 7) {
        return -RT_EINVAL;
    }

    result = ina228_read_u16(dev, INA228_REG_ADC_CONFIG, &value);
    if (result != RT_EOK) {
        return result;
    }

    value &= (rt_uint16_t)~INA228_ADC_VTCT;
    value |= (rt_uint16_t)(timing << 3);

    return ina228_write_reg(dev, INA228_REG_ADC_CONFIG, value);
}

rt_err_t ina228_set_max_current_shunt(ina228_t* dev, float max_current_a, float shunt_ohm)
{
    float current_lsb;
    float shunt_cal;

    if ((dev == RT_NULL) || (max_current_a <= 0.0f) || (shunt_ohm < 0.0001f)) {
        return -RT_EINVAL;
    }

    current_lsb = max_current_a * 1.9073486328125e-6f;
    shunt_cal = 13107.2e6f * current_lsb * shunt_ohm;
    if (dev->adc_range_41mv == RT_TRUE) {
        shunt_cal *= 4.0f;
    }
    if ((shunt_cal <= 0.0f) || (shunt_cal > 65535.0f)) {
        return -RT_EINVAL;
    }

    dev->max_current_a = max_current_a;
    dev->shunt_ohm = shunt_ohm;
    dev->current_lsb = current_lsb;

    return ina228_write_reg(dev, INA228_REG_SHUNT_CAL, (rt_uint16_t)(shunt_cal + 0.5f));
}

rt_err_t ina228_get_bus_voltage(ina228_t* dev, float* voltage_v)
{
    rt_uint32_t raw = 0;
    rt_err_t result;

    if (voltage_v == RT_NULL) {
        return -RT_EINVAL;
    }

    result = ina228_read_reg(dev, INA228_REG_BUS_VOLTAGE, 3, &raw);
    if (result == RT_EOK) {
        *voltage_v = (float)(raw >> 4) * 195.3125e-6f;
    }

    return result;
}

rt_err_t ina228_get_current(ina228_t* dev, float* current_a)
{
    rt_uint32_t raw = 0;
    rt_err_t result;

    if (current_a == RT_NULL) {
        return -RT_EINVAL;
    }

    result = ina228_read_reg(dev, INA228_REG_CURRENT, 3, &raw);
    if (result == RT_EOK) {
        *current_a = (float)ina228_sign_extend_20(raw) * dev->current_lsb;
    }

    return result;
}

rt_err_t ina228_get_temperature(ina228_t* dev, float* temperature_c)
{
    rt_uint16_t raw = 0;
    rt_err_t result;

    if (temperature_c == RT_NULL) {
        return -RT_EINVAL;
    }

    result = ina228_read_u16(dev, INA228_REG_TEMPERATURE, &raw);
    if (result == RT_EOK) {
        *temperature_c = (float)((rt_int16_t)raw) * 7.8125e-3f;
    }

    return result;
}

rt_err_t ina228_get_manufacturer(ina228_t* dev, rt_uint16_t* value)
{
    return ina228_read_u16(dev, INA228_REG_MANUFACTURER, value);
}

rt_err_t ina228_get_die_id(ina228_t* dev, rt_uint16_t* die_id, rt_uint16_t* revision)
{
    rt_uint16_t value = 0;
    rt_err_t result;

    if ((die_id == RT_NULL) || (revision == RT_NULL)) {
        return -RT_EINVAL;
    }

    result = ina228_read_u16(dev, INA228_REG_DEVICE_ID, &value);
    if (result == RT_EOK) {
        *die_id = (value >> 4) & 0x0FFF;
        *revision = value & 0x000F;
    }

    return result;
}
