#ifndef INA228_H__
#define INA228_H__

#include "hal/i2c/i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

#define INA228_DEFAULT_ADDR_7BIT 0x45
#define INA228_DEFAULT_ADDR      INA228_DEFAULT_ADDR_7BIT
#define INA228_MANUFACTURER_ID   0x5449
#define INA228_DIE_ID            0x0228

enum ina228_mode {
    INA228_MODE_SHUTDOWN            = 0x00,
    INA228_MODE_TRIG_BUS            = 0x01,
    INA228_MODE_TRIG_SHUNT          = 0x02,
    INA228_MODE_TRIG_BUS_SHUNT      = 0x03,
    INA228_MODE_TRIG_TEMP           = 0x04,
    INA228_MODE_TRIG_TEMP_BUS       = 0x05,
    INA228_MODE_TRIG_TEMP_SHUNT     = 0x06,
    INA228_MODE_TRIG_TEMP_BUS_SHUNT = 0x07,
    INA228_MODE_SHUTDOWN2           = 0x08,
    INA228_MODE_CONT_BUS            = 0x09,
    INA228_MODE_CONT_SHUNT          = 0x0A,
    INA228_MODE_CONT_BUS_SHUNT      = 0x0B,
    INA228_MODE_CONT_TEMP           = 0x0C,
    INA228_MODE_CONT_TEMP_BUS       = 0x0D,
    INA228_MODE_CONT_TEMP_SHUNT     = 0x0E,
    INA228_MODE_CONT_TEMP_BUS_SHUNT = 0x0F,
};

enum ina228_average {
    INA228_1_SAMPLE     = 0,
    INA228_4_SAMPLES    = 1,
    INA228_16_SAMPLES   = 2,
    INA228_64_SAMPLES   = 3,
    INA228_128_SAMPLES  = 4,
    INA228_256_SAMPLES  = 5,
    INA228_512_SAMPLES  = 6,
    INA228_1024_SAMPLES = 7,
};

enum ina228_timing {
    INA228_50_US   = 0,
    INA228_84_US   = 1,
    INA228_150_US  = 2,
    INA228_280_US  = 3,
    INA228_540_US  = 4,
    INA228_1052_US = 5,
    INA228_2074_US = 6,
    INA228_4120_US = 7,
};

typedef struct ina228_device {
    struct rt_i2c_bus* bus;
    rt_uint8_t addr;
    float current_lsb;
    float shunt_ohm;
    float max_current_a;
    rt_bool_t adc_range_41mv;
    rt_err_t last_error;
} ina228_t;

rt_err_t ina228_init(ina228_t* dev, const char* i2c_bus_name, rt_uint8_t addr);
rt_bool_t ina228_is_connected(ina228_t* dev);
rt_err_t ina228_reset_accumulation(ina228_t* dev);
rt_err_t ina228_set_adc_range(ina228_t* dev, rt_bool_t range_41mv);
rt_err_t ina228_get_adc_range(ina228_t* dev, rt_bool_t* range_41mv);
rt_err_t ina228_set_mode(ina228_t* dev, rt_uint8_t mode);
rt_err_t ina228_set_average(ina228_t* dev, rt_uint8_t average);
rt_err_t ina228_set_bus_voltage_conversion_time(ina228_t* dev, rt_uint8_t timing);
rt_err_t ina228_set_shunt_voltage_conversion_time(ina228_t* dev, rt_uint8_t timing);
rt_err_t ina228_set_temperature_conversion_time(ina228_t* dev, rt_uint8_t timing);
rt_err_t ina228_set_max_current_shunt(ina228_t* dev, float max_current_a, float shunt_ohm);
rt_err_t ina228_get_bus_voltage(ina228_t* dev, float* voltage_v);
rt_err_t ina228_get_current(ina228_t* dev, float* current_a);
rt_err_t ina228_get_temperature(ina228_t* dev, float* temperature_c);
rt_err_t ina228_get_manufacturer(ina228_t* dev, rt_uint16_t* value);
rt_err_t ina228_get_die_id(ina228_t* dev, rt_uint16_t* die_id, rt_uint16_t* revision);

#ifdef __cplusplus
}
#endif

#endif
