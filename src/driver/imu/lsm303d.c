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
#include "hal/accel/accel.h"
#include "hal/mag/mag.h"
#include "hal/spi/spi.h"
#include <firmament.h>

#define DRV_DBG(...) console_printf(__VA_ARGS__)

#define SLAVE_ADDR 0x1D

/* SPI protocol address bits */
#define DIR_READ       (1 << 7)
#define DIR_WRITE      (0 << 7)
#define ADDR_INCREMENT (1 << 6)

/* register addresses: A: accel, M: mag, T: temp */
#define ADDR_WHO_AM_I 0x0F
#define WHO_I_AM      0x49

#define ADDR_OUT_TEMP_L 0x05
#define ADDR_OUT_TEMP_H 0x06
#define ADDR_STATUS_M   0x07
#define ADDR_OUT_X_L_M  0x08
#define ADDR_OUT_X_H_M  0x09
#define ADDR_OUT_Y_L_M  0x0A
#define ADDR_OUT_Y_H_M  0x0B
#define ADDR_OUT_Z_L_M  0x0C
#define ADDR_OUT_Z_H_M  0x0D

#define ADDR_INT_CTRL_M  0x12
#define ADDR_INT_SRC_M   0x13
#define ADDR_REFERENCE_X 0x1c
#define ADDR_REFERENCE_Y 0x1d
#define ADDR_REFERENCE_Z 0x1e

#define ADDR_STATUS_A  0x27
#define ADDR_OUT_X_L_A 0x28
#define ADDR_OUT_X_H_A 0x29
#define ADDR_OUT_Y_L_A 0x2A
#define ADDR_OUT_Y_H_A 0x2B
#define ADDR_OUT_Z_L_A 0x2C
#define ADDR_OUT_Z_H_A 0x2D

#define ADDR_CTRL_REG0 0x1F
#define ADDR_CTRL_REG1 0x20
#define ADDR_CTRL_REG2 0x21
#define ADDR_CTRL_REG3 0x22
#define ADDR_CTRL_REG4 0x23
#define ADDR_CTRL_REG5 0x24
#define ADDR_CTRL_REG6 0x25
#define ADDR_CTRL_REG7 0x26

#define ADDR_FIFO_CTRL 0x2e
#define ADDR_FIFO_SRC  0x2f

#define ADDR_IG_CFG1      0x30
#define ADDR_IG_SRC1      0x31
#define ADDR_IG_THS1      0x32
#define ADDR_IG_DUR1      0x33
#define ADDR_IG_CFG2      0x34
#define ADDR_IG_SRC2      0x35
#define ADDR_IG_THS2      0x36
#define ADDR_IG_DUR2      0x37
#define ADDR_CLICK_CFG    0x38
#define ADDR_CLICK_SRC    0x39
#define ADDR_CLICK_THS    0x3a
#define ADDR_TIME_LIMIT   0x3b
#define ADDR_TIME_LATENCY 0x3c
#define ADDR_TIME_WINDOW  0x3d
#define ADDR_ACT_THS      0x3e
#define ADDR_ACT_DUR      0x3f

#define REG1_RATE_BITS_A    ((1 << 7) | (1 << 6) | (1 << 5) | (1 << 4))
#define REG1_POWERDOWN_A    ((0 << 7) | (0 << 6) | (0 << 5) | (0 << 4))
#define REG1_RATE_3_125HZ_A ((0 << 7) | (0 << 6) | (0 << 5) | (1 << 4))
#define REG1_RATE_6_25HZ_A  ((0 << 7) | (0 << 6) | (1 << 5) | (0 << 4))
#define REG1_RATE_12_5HZ_A  ((0 << 7) | (0 << 6) | (1 << 5) | (1 << 4))
#define REG1_RATE_25HZ_A    ((0 << 7) | (1 << 6) | (0 << 5) | (0 << 4))
#define REG1_RATE_50HZ_A    ((0 << 7) | (1 << 6) | (0 << 5) | (1 << 4))
#define REG1_RATE_100HZ_A   ((0 << 7) | (1 << 6) | (1 << 5) | (0 << 4))
#define REG1_RATE_200HZ_A   ((0 << 7) | (1 << 6) | (1 << 5) | (1 << 4))
#define REG1_RATE_400HZ_A   ((1 << 7) | (0 << 6) | (0 << 5) | (0 << 4))
#define REG1_RATE_800HZ_A   ((1 << 7) | (0 << 6) | (0 << 5) | (1 << 4))
#define REG1_RATE_1600HZ_A  ((1 << 7) | (0 << 6) | (1 << 5) | (0 << 4))

#define REG1_BDU_UPDATE (1 << 3)
#define REG1_Z_ENABLE_A (1 << 2)
#define REG1_Y_ENABLE_A (1 << 1)
#define REG1_X_ENABLE_A (1 << 0)

#define REG2_ANTIALIAS_FILTER_BW_BITS_A ((1 << 7) | (1 << 6))
#define REG2_AA_FILTER_BW_773HZ_A       ((0 << 7) | (0 << 6))
#define REG2_AA_FILTER_BW_194HZ_A       ((0 << 7) | (1 << 6))
#define REG2_AA_FILTER_BW_362HZ_A       ((1 << 7) | (0 << 6))
#define REG2_AA_FILTER_BW_50HZ_A        ((1 << 7) | (1 << 6))

#define REG2_FULL_SCALE_BITS_A ((1 << 5) | (1 << 4) | (1 << 3))
#define REG2_FULL_SCALE_2G_A   ((0 << 5) | (0 << 4) | (0 << 3))
#define REG2_FULL_SCALE_4G_A   ((0 << 5) | (0 << 4) | (1 << 3))
#define REG2_FULL_SCALE_6G_A   ((0 << 5) | (1 << 4) | (0 << 3))
#define REG2_FULL_SCALE_8G_A   ((0 << 5) | (1 << 4) | (1 << 3))
#define REG2_FULL_SCALE_16G_A  ((1 << 5) | (0 << 4) | (0 << 3))

#define REG5_ENABLE_T (1 << 7)

#define REG5_RES_HIGH_M ((1 << 6) | (1 << 5))
#define REG5_RES_LOW_M  ((0 << 6) | (0 << 5))

#define REG5_RATE_BITS_M       ((1 << 4) | (1 << 3) | (1 << 2))
#define REG5_RATE_3_125HZ_M    ((0 << 4) | (0 << 3) | (0 << 2))
#define REG5_RATE_6_25HZ_M     ((0 << 4) | (0 << 3) | (1 << 2))
#define REG5_RATE_12_5HZ_M     ((0 << 4) | (1 << 3) | (0 << 2))
#define REG5_RATE_25HZ_M       ((0 << 4) | (1 << 3) | (1 << 2))
#define REG5_RATE_50HZ_M       ((1 << 4) | (0 << 3) | (0 << 2))
#define REG5_RATE_100HZ_M      ((1 << 4) | (0 << 3) | (1 << 2))
#define REG5_RATE_DO_NOT_USE_M ((1 << 4) | (1 << 3) | (0 << 2))

#define REG6_FULL_SCALE_BITS_M ((1 << 6) | (1 << 5))
#define REG6_FULL_SCALE_2GA_M  ((0 << 6) | (0 << 5))
#define REG6_FULL_SCALE_4GA_M  ((0 << 6) | (1 << 5))
#define REG6_FULL_SCALE_8GA_M  ((1 << 6) | (0 << 5))
#define REG6_FULL_SCALE_12GA_M ((1 << 6) | (1 << 5))

#define REG7_CONT_MODE_M ((0 << 1) | (0 << 0))

/* default values for this device */
#define LSM303D_ACCEL_DEFAULT_RANGE_G 8
#define LSM303D_ACCEL_DEFAULT_RATE    800
//#define LSM303D_ACCEL_DEFAULT_RATE					1600
//#define LSM303D_ACCEL_DEFAULT_ONCHIP_FILTER_FREQ	362
#define LSM303D_ACCEL_DEFAULT_ONCHIP_FILTER_FREQ 50
#define LSM303D_ACCEL_DEFAULT_DRIVER_FILTER_FREQ 30

#define LSM303D_MAG_DEFAULT_RANGE_GA 2
#define LSM303D_MAG_DEFAULT_RATE     100

#define LSM303D_ONE_G 9.80665f

static rt_device_t spi_device;

float _accel_range_scale = 0.0f;
float _mag_range_scale = 0.0f;

/* Re-implement this function to define customized rotation */
RT_WEAK void lsm303d_rotate_to_frd(float* data)
{
    /* do nothing */
}

static rt_err_t _write_reg(rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t send_buffer[2];
    rt_size_t w_byte;

    send_buffer[0] = DIR_WRITE | reg;
    send_buffer[1] = val;
    w_byte = rt_device_write(spi_device, 0, send_buffer, sizeof(send_buffer));

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
    rt_uint8_t r_buff;
    rt_err_t res = RT_EOK;

    res |= _write_reg(reg, val);
    res |= _read_reg(reg, &r_buff);

    if (r_buff != val || res != RT_EOK) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t _accel_set_range(uint8_t max_g)
{
    uint8_t setbits = 0;
    uint8_t r_val;
    float acc_sensity = 0.0f;

    if (max_g == 0)
        max_g = 16;

    if (max_g <= 2) {
        setbits |= REG2_FULL_SCALE_2G_A;
        acc_sensity = 0.061e-3f;
    } else if (max_g <= 4) {
        setbits |= REG2_FULL_SCALE_4G_A;
        acc_sensity = 0.122e-3f;
    } else if (max_g <= 6) {
        setbits |= REG2_FULL_SCALE_6G_A;
        acc_sensity = 0.183e-3f;
    } else if (max_g <= 8) {
        setbits |= REG2_FULL_SCALE_8G_A;
        acc_sensity = 0.244e-3f;
    } else if (max_g <= 16) {
        setbits |= REG2_FULL_SCALE_16G_A;
        acc_sensity = 0.732e-3f;
    } else {
        return RT_ERROR;
    }

    _accel_range_scale = acc_sensity * LSM303D_ONE_G;

    if (_read_reg(ADDR_CTRL_REG2, &r_val) == RT_ERROR) {
        return RT_ERROR;
    }

    if (_write_checked_reg(ADDR_CTRL_REG2, r_val | setbits) == RT_ERROR) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t _accel_set_samplerate(uint32_t frequency)
{
    uint8_t setbits = 0;
    uint8_t r_val;

    if (frequency == 0) {
        frequency = 1600;
    }

    if (frequency <= 100) {
        setbits |= REG1_RATE_100HZ_A;

    } else if (frequency <= 200) {
        setbits |= REG1_RATE_200HZ_A;

    } else if (frequency <= 400) {
        setbits |= REG1_RATE_400HZ_A;

    } else if (frequency <= 800) {
        setbits |= REG1_RATE_800HZ_A;

    } else if (frequency <= 1600) {
        setbits |= REG1_RATE_1600HZ_A;

    } else {
        return RT_ERROR;
    }

    if (_read_reg(ADDR_CTRL_REG1, &r_val) == RT_ERROR) {
        return RT_ERROR;
    }

    if (_write_checked_reg(ADDR_CTRL_REG1, r_val | setbits) == RT_ERROR) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t _accel_set_lpf_bandwidth(uint32_t bandwidth)
{
    uint8_t setbits = 0;
    uint8_t clearbits = REG2_ANTIALIAS_FILTER_BW_BITS_A;

    uint8_t r_val;

    if (bandwidth == 0)
        bandwidth = 773;

    if (bandwidth <= 50) {
        setbits |= REG2_AA_FILTER_BW_50HZ_A;

    } else if (bandwidth <= 194) {
        setbits |= REG2_AA_FILTER_BW_194HZ_A;

    } else if (bandwidth <= 362) {
        setbits |= REG2_AA_FILTER_BW_362HZ_A;

    } else if (bandwidth <= 773) {
        setbits |= REG2_AA_FILTER_BW_773HZ_A;

    } else {
        return -RT_ERROR;
    }

    if (_read_reg(ADDR_CTRL_REG2, &r_val) == RT_ERROR) {
        return RT_ERROR;
    }

    r_val &= ~clearbits;
    r_val |= setbits;

    if (_write_checked_reg(ADDR_CTRL_REG2, r_val) == RT_ERROR) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t _mag_set_range(uint8_t max_ga)
{
    uint8_t setbits = 0;
    uint8_t r_val;
    float mag_sensity = 0.0f;

    if (max_ga == 0)
        max_ga = 12;

    if (max_ga <= 2) {
        setbits |= REG6_FULL_SCALE_2GA_M;
        mag_sensity = 0.080e-3f;
    } else if (max_ga <= 4) {
        setbits |= REG6_FULL_SCALE_4GA_M;
        mag_sensity = 0.160e-3f;
    } else if (max_ga <= 8) {
        setbits |= REG6_FULL_SCALE_8GA_M;
        mag_sensity = 0.320e-3f;
    } else if (max_ga <= 12) {
        setbits |= REG6_FULL_SCALE_12GA_M;
        mag_sensity = 0.479e-3f;
    } else {
        return RT_ERROR;
    }

    _mag_range_scale = mag_sensity;

    if (_read_reg(ADDR_CTRL_REG6, &r_val) == RT_ERROR) {
        return RT_ERROR;
    }

    if (_write_checked_reg(ADDR_CTRL_REG6, r_val | setbits) == RT_ERROR) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t _mag_set_samplerate(uint32_t frequency)
{
    uint8_t setbits = 0;
    uint8_t r_val;

    if (frequency == 0)
        frequency = 100;

    if (frequency <= 25) {
        setbits |= REG5_RATE_25HZ_M;

    } else if (frequency <= 50) {
        setbits |= REG5_RATE_50HZ_M;

    } else if (frequency <= 100) {
        setbits |= REG5_RATE_100HZ_M;

    } else {
        return RT_ERROR;
    }

    if (_read_reg(ADDR_CTRL_REG5, &r_val) == RT_ERROR) {
        return RT_ERROR;
    }

    if (_write_checked_reg(ADDR_CTRL_REG5, r_val | setbits) == RT_ERROR) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static uint8_t _read_device_id(void)
{
    uint8_t id;

    _read_reg(ADDR_WHO_AM_I, &id);

    return id;
}

static rt_err_t _mag_raw_measure(int16_t mag[3])
{
    rt_err_t res = RT_EOK;
    uint8_t r_val_l, r_val_h;

    res |= _read_reg(ADDR_OUT_X_L_M, &r_val_l);
    res |= _read_reg(ADDR_OUT_X_H_M, &r_val_h);
    //mag[0] = (int16_t)((r_val_h<<8) | r_val_l);
    mag[0] = (((int16_t)r_val_h << 8) | r_val_l);

    res |= _read_reg(ADDR_OUT_Y_L_M, &r_val_l);
    res |= _read_reg(ADDR_OUT_Y_H_M, &r_val_h);
    //mag[1] = (int16_t)((r_val_h<<8) | r_val_l);
    mag[1] = (((int16_t)r_val_h << 8) | r_val_l);

    res |= _read_reg(ADDR_OUT_Z_L_M, &r_val_l);
    res |= _read_reg(ADDR_OUT_Z_H_M, &r_val_h);
    //mag[2] = (int16_t)((r_val_h<<8) | r_val_l);
    mag[2] = (int16_t)((r_val_h << 8) | r_val_l);

    return res;
}

static rt_err_t _mag_measure(float mag[3])
{
    rt_err_t res;
    int16_t raw[3];

    res = _mag_raw_measure(raw);

    mag[0] = raw[0] * _mag_range_scale;
    mag[1] = raw[1] * _mag_range_scale;
    mag[2] = raw[2] * _mag_range_scale;

    lsm303d_rotate_to_frd(mag);

    return res;
}

static rt_err_t _acc_raw_measure(int16_t acc[3])
{
    rt_err_t res = RT_EOK;
    uint8_t r_val_l, r_val_h;

    res |= _read_reg(ADDR_OUT_X_L_A, &r_val_l);
    res |= _read_reg(ADDR_OUT_X_H_A, &r_val_h);
    acc[0] = (int16_t)((r_val_h << 8) | r_val_l);
    //acc[0] = (((int16_t)r_val_h<<8) | r_val_l);
    //console_printf("drive %d %d\n", r_val_h, r_val_l);

    res |= _read_reg(ADDR_OUT_Y_L_A, &r_val_l);
    res |= _read_reg(ADDR_OUT_Y_H_A, &r_val_h);
    acc[1] = (int16_t)((r_val_h << 8) | r_val_l);
    //acc[1] = (((int16_t)r_val_h<<8) | r_val_l);
    //console_printf("drive %d %d\n", r_val_h, r_val_l);

    res |= _read_reg(ADDR_OUT_Z_L_A, &r_val_l);
    res |= _read_reg(ADDR_OUT_Z_H_A, &r_val_h);
    acc[2] = (int16_t)((r_val_h << 8) | r_val_l);
    //acc[2] = (((int16_t)r_val_h<<8) | r_val_l);
    //console_printf("drive %d %d\n", r_val_h, r_val_l);

    //console_printf("drive raw acc:%d %d %d\n", acc[0], acc[1], acc[2]);

    return res;
}

static rt_err_t _acc_measure(float acc[3])
{
    rt_err_t res;
    int16_t raw[3];

    res = _acc_raw_measure(raw);

    acc[0] = raw[0] * _accel_range_scale;
    acc[1] = raw[1] * _accel_range_scale;
    acc[2] = raw[2] * _accel_range_scale;

    return res;
}

static rt_err_t _init(void)
{
    rt_err_t res = RT_EOK;

    rt_device_open(spi_device, RT_DEVICE_OFLAG_RDWR);

    /* enable accel*/
    //res |= _write_checked_reg(ADDR_CTRL_REG0, 0x00);	//disable FIFO
    res |= _write_checked_reg(ADDR_CTRL_REG1,
                              REG1_X_ENABLE_A | REG1_Y_ENABLE_A | REG1_Z_ENABLE_A | REG1_BDU_UPDATE | REG1_RATE_800HZ_A);

    /* enable mag */
    res |= _write_checked_reg(ADDR_CTRL_REG7, REG7_CONT_MODE_M);
    res |= _write_checked_reg(ADDR_CTRL_REG5, REG5_RES_HIGH_M | REG5_ENABLE_T);
    res |= _write_checked_reg(ADDR_CTRL_REG3, 0x04); // DRDY on ACCEL on INT1
    res |= _write_checked_reg(ADDR_CTRL_REG4, 0x04); // DRDY on MAG on INT2

    _accel_set_range(LSM303D_ACCEL_DEFAULT_RANGE_G);
    _accel_set_samplerate(LSM303D_ACCEL_DEFAULT_RATE);

    _accel_set_lpf_bandwidth(LSM303D_ACCEL_DEFAULT_ONCHIP_FILTER_FREQ);

    _mag_set_range(LSM303D_MAG_DEFAULT_RANGE_GA);
    _mag_set_samplerate(LSM303D_MAG_DEFAULT_RATE);

    return res;
}

//--------------------accel------------------------
static rt_err_t accel_config(accel_dev_t accel, const struct accel_configure* cfg)
{
    rt_err_t ret = RT_EOK;

    if (cfg == RT_NULL) {
        return RT_EINVAL;
    }

    ret |= _accel_set_range(cfg->acc_range_g);

    ret |= _accel_set_samplerate(cfg->sample_rate_hz);

    ret |= _accel_set_lpf_bandwidth(cfg->dlpf_freq_hz);

    accel->config = *cfg;

    return ret;
}

static rt_err_t accel_control(accel_dev_t accel, int cmd, void* arg)
{
    return RT_EOK;
}

static rt_size_t accel_read(accel_dev_t accel, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == RT_NULL) {
        return 0;
    }

    if (_acc_measure(((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
}

const static struct accel_ops _accel_ops = {
    accel_config,
    accel_control,
    accel_read,
};

//--------------------magl------------------------
static rt_err_t mag_config(mag_dev_t mag, const struct mag_configure* cfg)
{
    rt_err_t ret = RT_EOK;

    if (cfg == RT_NULL) {
        return RT_EINVAL;
    }

    ret |= _mag_set_range(cfg->mag_range_ga);

    ret |= _mag_set_samplerate(cfg->sample_rate_hz);

    // no cfg->dlpf_freq_hz

    mag->config = *cfg;

    return ret;
}

static rt_err_t mag_control(mag_dev_t mag, int cmd, void* arg)
{
    return RT_EOK;
}

static rt_size_t mag_read(mag_dev_t mag, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == RT_NULL) {
        return 0;
    }

    if (_mag_measure(((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
}

const static struct mag_ops _mag_ops = {
    mag_config,
    mag_control,
    mag_read,
};

#define LSM303D_ACC_CONFIG_DEFAULT                             \
    {                                                          \
        800,                /* 1K sample rate */               \
            260,            /* 260Hz internal lpf for accel */ \
            ACCEL_RANGE_8G, /* +-8g */                         \
    }

rt_err_t lsm303d_drv_init(const char* spi_device_name, const char* mag_device_name, const char* accel_device_name)
{
    rt_err_t ret = RT_EOK;
    static struct accel_device accel_dev = {
        .ops = &_accel_ops,
        .config = LSM303D_ACC_CONFIG_DEFAULT,
        .bus_type = ACCEL_SPI_BUS_TYPE
    };
    static struct mag_device mag_dev = {
        .ops = &_mag_ops,
        .config = MAG_CONFIG_DEFAULT,
        .bus_type = MAG_SPI_BUS_TYPE
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

    /* register mag hal device */
    ret |= hal_mag_register(&mag_dev, mag_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL);

    /* register accel hal device */
    ret |= hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL);

    return ret;
}