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
#include "hal/gyro/gyro.h"
#include "hal/spi/spi.h"
#include <firmament.h>

#define DRV_DBG(...) console_printf(__VA_ARGS__)

/* SPI protocol address bits */
#define DIR_READ       (1 << 7)
#define DIR_WRITE      (0 << 7)
#define ADDR_INCREMENT (1 << 6)

/* register addresses */
#define ADDR_WHO_AM_I 0x0F
#define WHO_I_AM_H    0xD7
#define WHO_I_AM      0xD4

#define ADDR_CTRL_REG1    0x20
#define REG1_RATE_LP_MASK 0xF0 /* Mask to guard partial register update */

/* keep lowpass low to avoid noise issues */
#define RATE_95HZ_LP_25HZ   ((0 << 7) | (0 << 6) | (0 << 5) | (1 << 4))
#define RATE_190HZ_LP_25HZ  ((0 << 7) | (1 << 6) | (0 << 5) | (1 << 4))
#define RATE_190HZ_LP_50HZ  ((0 << 7) | (1 << 6) | (1 << 5) | (0 << 4))
#define RATE_190HZ_LP_70HZ  ((0 << 7) | (1 << 6) | (1 << 5) | (1 << 4))
#define RATE_380HZ_LP_20HZ  ((1 << 7) | (0 << 6) | (1 << 5) | (0 << 4))
#define RATE_380HZ_LP_25HZ  ((1 << 7) | (0 << 6) | (0 << 5) | (1 << 4))
#define RATE_380HZ_LP_50HZ  ((1 << 7) | (0 << 6) | (1 << 5) | (0 << 4))
#define RATE_380HZ_LP_100HZ ((1 << 7) | (0 << 6) | (1 << 5) | (1 << 4))
#define RATE_760HZ_LP_30HZ  ((1 << 7) | (1 << 6) | (0 << 5) | (0 << 4))
#define RATE_760HZ_LP_35HZ  ((1 << 7) | (1 << 6) | (0 << 5) | (1 << 4))
#define RATE_760HZ_LP_50HZ  ((1 << 7) | (1 << 6) | (1 << 5) | (0 << 4))
#define RATE_760HZ_LP_100HZ ((1 << 7) | (1 << 6) | (1 << 5) | (1 << 4))

#define ADDR_CTRL_REG2 0x21
#define ADDR_CTRL_REG3 0x22
#define ADDR_CTRL_REG4 0x23

#define ADDR_CTRL_REG5     0x24
#define ADDR_REFERENCE     0x25
#define ADDR_OUT_TEMP      0x26
#define ADDR_STATUS_REG    0x27
#define ADDR_OUT_X_L       0x28
#define ADDR_OUT_X_H       0x29
#define ADDR_OUT_Y_L       0x2A
#define ADDR_OUT_Y_H       0x2B
#define ADDR_OUT_Z_L       0x2C
#define ADDR_OUT_Z_H       0x2D
#define ADDR_FIFO_CTRL_REG 0x2E
#define ADDR_FIFO_SRC_REG  0x2F
#define ADDR_INT1_CFG      0x30
#define ADDR_INT1_SRC      0x31
#define ADDR_INT1_TSH_XH   0x32
#define ADDR_INT1_TSH_XL   0x33
#define ADDR_INT1_TSH_YH   0x34
#define ADDR_INT1_TSH_YL   0x35
#define ADDR_INT1_TSH_ZH   0x36
#define ADDR_INT1_TSH_ZL   0x37
#define ADDR_INT1_DURATION 0x38
#define ADDR_LOW_ODR       0x39

/* Internal configuration values */
#define REG1_POWER_NORMAL       (1 << 3)
#define REG1_Z_ENABLE           (1 << 2)
#define REG1_Y_ENABLE           (1 << 0)
#define REG1_X_ENABLE           (1 << 1)
#define REG1_ODR_800_CUTOFF_100 ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))

#define REG3_DRDY_ENABLE (1 << 3)

#define REG4_BDU           (1 << 7)
#define REG4_BLE           (1 << 6)
#define REG4_RANGE_MASK    0x30 /* Mask to guard partial register update */
#define RANGE_250DPS       (0 << 4)
#define RANGE_500DPS       (1 << 4)
#define RANGE_2000DPS      (3 << 4)
#define REG4_SELF_TEST_POS ((0 << 2) | (1 << 1))
#define REG4_SELF_TEST_NEG ((1 << 2) | (1 << 1))

#define REG5_FIFO_ENABLE   (1 << 6)
#define REG5_REBOOT_MEMORY (1 << 7)

#define STATUS_ZYXOR (1 << 7)
#define STATUS_ZOR   (1 << 6)
#define STATUS_YOR   (1 << 5)
#define STATUS_XOR   (1 << 4)
#define STATUS_ZYXDA (1 << 3)
#define STATUS_ZDA   (1 << 2)
#define STATUS_YDA   (1 << 1)
#define STATUS_XDA   (1 << 0)

#define FIFO_CTRL_BYPASS_MODE           (0 << 5)
#define FIFO_CTRL_FIFO_MODE             (1 << 5)
#define FIFO_CTRL_STREAM_MODE           (1 << 6)
#define FIFO_CTRL_STREAM_TO_FIFO_MODE   (3 << 5)
#define FIFO_CTRL_BYPASS_TO_STREAM_MODE (1 << 7)

#define REGODR_I2C_DIS (1 << 3)

#define L3GD20_DEFAULT_RATE        760
#define L3G4200D_DEFAULT_RATE      800
#define L3GD20_DEFAULT_RANGE_DPS   2000
#define L3GD20_DEFAULT_FILTER_FREQ 30
#define L3GD20_TEMP_OFFSET_CELSIUS 40

#define DEG2RAD_FACTOR 0.01745329f

static rt_device_t spi_device;
static float _gyro_range_scale;

/* Re-implement this function to define customized rotation */
RT_WEAK void l3gd20h_rotate_to_frd(float* data)
{
    /* do nothing */
}

static rt_err_t _write_reg(rt_uint8_t reg, rt_uint8_t val)
{
    rt_size_t w_byte;
    rt_uint8_t send_buffer[2];

    send_buffer[0] = DIR_WRITE | reg;
    send_buffer[1] = val;
    w_byte = rt_device_write(spi_device, 0, send_buffer, 2);

    return w_byte == sizeof(send_buffer) ? RT_EOK : RT_ERROR;
}

static rt_err_t _read_reg(rt_uint8_t reg, rt_uint8_t* buff)
{
    rt_uint8_t send_val, recv_val;
    rt_err_t res;

    send_val = DIR_READ | reg;

    res = rt_spi_send_then_recv((struct rt_spi_device*)spi_device, (void*)&send_val, 1, (void*)&recv_val, 1);
    *buff = recv_val;

    return res;
}

static rt_err_t _write_checked_reg(rt_uint8_t reg, rt_uint8_t val)
{
    rt_err_t res = RT_EOK;
    rt_uint8_t r_buff;

    res |= _write_reg(reg, val);
    res |= _read_reg(reg, &r_buff);

    if (r_buff != val || res != RT_EOK) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t l3gd20h_read_raw(int16_t gyr[3])
{
    rt_err_t res = RT_EOK;
    uint8_t r_val_l, r_val_h;

    res |= _read_reg(ADDR_OUT_X_L, &r_val_l);
    res |= _read_reg(ADDR_OUT_X_H, &r_val_h);
    gyr[0] = (int16_t)((r_val_h << 8) | r_val_l);

    res |= _read_reg(ADDR_OUT_Y_L, &r_val_l);
    res |= _read_reg(ADDR_OUT_Y_H, &r_val_h);
    gyr[1] = (int16_t)((r_val_h << 8) | r_val_l);

    res |= _read_reg(ADDR_OUT_Z_L, &r_val_l);
    res |= _read_reg(ADDR_OUT_Z_H, &r_val_h);
    gyr[2] = (int16_t)((r_val_h << 8) | r_val_l);

    return res;
}

rt_err_t l3g_set_range(uint16_t max_dps)
{
    uint8_t bits = 0x00;
    float new_range_scale_dps_digit;

    uint8_t r_val;

    if (max_dps == 0) {
        max_dps = 2000;
    }

    if (max_dps <= 250) {
        bits |= RANGE_250DPS;
        new_range_scale_dps_digit = 8.75e-3f;

    } else if (max_dps <= 500) {
        bits |= RANGE_500DPS;
        new_range_scale_dps_digit = 17.5e-3f;

    } else if (max_dps <= 2000) {
        bits |= RANGE_2000DPS;
        new_range_scale_dps_digit = 70e-3f;

    } else {
        return RT_ERROR;
    }

    if (_read_reg(ADDR_CTRL_REG4, &r_val) == RT_ERROR) {
        return RT_ERROR;
    }

    if (_write_checked_reg(ADDR_CTRL_REG4, r_val | bits) == RT_ERROR) {
        return RT_ERROR;
    }

    _gyro_range_scale = new_range_scale_dps_digit;

    return RT_EOK;
}

static uint8_t l3gd20h_read_device_id(void)
{
    uint8_t id;

    _read_reg(ADDR_WHO_AM_I, &id);

    return id;
}

static rt_err_t l3gd20h_gyr_read_dps(float gyr[3])
{
    int16_t raw_gyr[3];

    if (l3gd20h_read_raw(raw_gyr) == RT_ERROR)
        return RT_ERROR;

    if (_gyro_range_scale == 0) {
        return RT_ERROR;
    }

    gyr[0] = raw_gyr[0] * _gyro_range_scale;
    gyr[1] = raw_gyr[1] * _gyro_range_scale;
    gyr[2] = raw_gyr[2] * _gyro_range_scale;

    l3gd20h_rotate_to_frd(gyr);

    return RT_EOK;
}

static rt_err_t l3gd20h_read_rad(float gyr[3])
{
    int16_t raw_gyr[3];

    if (l3gd20h_read_raw(raw_gyr) == RT_ERROR)
        return RT_ERROR;

    if (_gyro_range_scale == 0) {
        return RT_ERROR;
    }

    gyr[0] = raw_gyr[0] * _gyro_range_scale * DEG2RAD_FACTOR;
    gyr[1] = raw_gyr[1] * _gyro_range_scale * DEG2RAD_FACTOR;
    gyr[2] = raw_gyr[2] * _gyro_range_scale * DEG2RAD_FACTOR;

    l3gd20h_rotate_to_frd(gyr);

    return RT_EOK;
}

static rt_err_t gyro_config(gyro_dev_t gyro, const struct gyro_configure* cfg)
{
    rt_err_t ret = RT_EOK;

    if (cfg == RT_NULL) {
        return RT_EINVAL;
    }

    ret |= l3g_set_range(cfg->gyro_range_dps);

    // TODO, set rate and lpf

    gyro->config = *cfg;

    return ret;
}

static rt_err_t gyro_control(gyro_dev_t gyro, int cmd, void* arg)
{
    return RT_EOK;
}

static rt_size_t gyro_read(gyro_dev_t gyro, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == NULL) {
        return 0;
    }

    if (l3gd20h_read_rad(((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
}

static rt_err_t _init(void)
{
    rt_err_t res = RT_EOK;
    rt_device_open(spi_device, RT_DEVICE_OFLAG_RDWR);

    /* do not set low cut-off frequency here, let higher layer to filter the signal properly */
    res |= _write_checked_reg(ADDR_CTRL_REG1,
                              REG1_POWER_NORMAL | REG1_Z_ENABLE | REG1_Y_ENABLE | REG1_X_ENABLE | RATE_760HZ_LP_100HZ);
    res |= _write_checked_reg(ADDR_CTRL_REG2, 0x00);             /* disable high-pass filters */
    res |= _write_checked_reg(ADDR_CTRL_REG3, REG3_DRDY_ENABLE); /* DRDY enable on INT2*/
    res |= _write_checked_reg(ADDR_CTRL_REG4, REG4_BDU);
    res |= _write_checked_reg(ADDR_CTRL_REG5, 0x00);         /* disable FIFO, disable High Pass Filter */
    res |= _write_checked_reg(ADDR_LOW_ODR, REGODR_I2C_DIS); /* DRDY acitve high, LOW ODR disable, SPI only */
    res |= _write_checked_reg(ADDR_FIFO_CTRL_REG, FIFO_CTRL_BYPASS_MODE);

    res |= l3g_set_range(L3GD20_DEFAULT_RANGE_DPS);

    return res;
}

const static struct gyro_ops _gyro_ops = {
    gyro_config,
    gyro_control,
    gyro_read,
};

rt_err_t l3gd20h_drv_init(const char* spi_device_name, const char* gyro_device_name)
{
    rt_err_t ret = RT_EOK;
    static struct gyro_device gyro_dev = {
        .ops = &_gyro_ops,
        .config = GYRO_CONFIG_DEFAULT,
        .bus_type = GYRO_SPI_BUS_TYPE
    };

    spi_device = rt_device_find(spi_device_name);

    if (spi_device == RT_NULL) {
        console_printf("spi device %s not found!\r\n", spi_device_name);
        return RT_EEMPTY;
    }

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 3000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_device;

        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;
        ret |= rt_spi_configure(spi_device_t, &cfg);
    }

    /* driver internal init */
    ret |= _init();

    /* register gyro hal device */
    ret |= hal_gyro_register(&gyro_dev, gyro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL);

    return ret;
}
