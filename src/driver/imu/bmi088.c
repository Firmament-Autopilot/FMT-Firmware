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

#include "board_device.h"
#include "driver/imu/bmi088.h"
#include "hal/accel/accel.h"
#include "hal/gyro/gyro.h"
#include "hal/spi/spi.h"

#define DRV_DBG(...)
// #define DRV_DBG(...) console_printf(__VA_ARGS__)

#ifdef BIT
    #undef BIT
#endif

#define BIT(_idx) (1 << _idx)
#define REG_VAL(_setbits, _clearbits) \
    (reg_val_t) { .setbits = (_setbits), .clearbits = (_clearbits) }

// #define BMI088_ACC_I2C_ADDR1        0x18                 //SDO is low(GND)
// #define BMI088_ACC_I2C_ADDR2        0x19                 //SDO is high(VCC)
// #define BMI088_ACC_DEFAULT_ADDRESS  BMI088_ACC_I2C_ADDR2 //in the LPC54102 SPM-S

#define BMI088_ACC_BGW_CHIPID_VALUE 0x1E
#define BMI088_ACC_BGW_CHIPID       0x00

#define BMI088_ACC_ERR_REG 0x02
#define BMI088_ACC_STATUS  0x03

#define BMI088_ACCD_X_LSB   0x12
#define BMI088_ACCD_X_MSB   0x13
#define BMI088_ACCD_Y_LSB   0x14
#define BMI088_ACCD_Y_MSB   0x15
#define BMI088_ACCD_Z_LSB   0x16
#define BMI088_ACCD_Z_MSB   0x17
#define BMI088_SENSORTIME_0 0x18
#define BMI088_SENSORTIME_1 0x19
#define BMI088_SENSORTIME_2 0x1A

#define BMI088_INT_STAT_1 0x1D

#define BMI088_INT_TEMP_MSB 0x22
#define BMI088_INT_TEMP_LSB 0x23

#define BMI088_ACC_CONF  0x40
#define BMI088_ACC_RANGE 0x41

#define BMI088_ACC_PWR_CONF  0x7C
#define BMI088_ACC_PWR_CTRL  0x7D
#define BMI088_ACC_SOFTRESET 0x7E

// #define BMI088_GYRO_I2C_ADDR1        0x68 //SDO is low(GND)
// #define BMI088_GYRO_I2C_ADDR2        0x69 //SDO is high(VCC)
// #define BMI088_GYRO_DEFAULT_ADDRESS  BMI088_GYRO_I2C_ADDR2

#define BMI088_GRRO_CHIP_ID 0x0F
#define BMI088_CHIP_ID_ADDR 0x00

#define BMI088_RATE_X_LSB_ADDR 0x02
#define BMI088_RATE_X_MSB_ADDR 0x03
#define BMI088_RATE_Y_LSB_ADDR 0x04
#define BMI088_RATE_Y_MSB_ADDR 0x05
#define BMI088_RATE_Z_LSB_ADDR 0x06
#define BMI088_RATE_Z_MSB_ADDR 0x07

#define BMI088_INTR_STAT1_ADDR 0x0A

#define BMI088_RANGE_ADDR 0x0F

#define BMI088_BW_ADDR 0x10

#define BMI088_MODE_LPM1_ADDR 0x11

#define BMI088_BGW_SOFT_RST_ADDR 0x14

#define BMI088_INTR_ENABLE0_ADDR 0x15
#define BMI088_INTR_ENABLE1_ADDR 0x16

#define BMI088_SELECTF_TEST_ADDR 0x3C

#define BMI088_GYRO_RANGE_2000_DPS REG_VAL(0, BIT(2) | BIT(1) | BIT(0))
#define BMI088_GYRO_RANGE_1000_DPS REG_VAL(BIT(0), BIT(2) | BIT(1))
#define BMI088_GYRO_RANGE_500_DPS  REG_VAL(BIT(1), BIT(2) | BIT(0))
#define BMI088_GYRO_RANGE_250_DPS  REG_VAL(BIT(1) | BIT(0), BIT(2))
#define BMI088_GYRO_RANGE_125_DPS  REG_VAL(BIT(2), BIT(1) | BIT(0))

#define BMI088_GYRO_RATE_100  REG_VAL(BIT(2) | BIT(1) | BIT(0), BIT(3))
#define BMI088_GYRO_RATE_200  REG_VAL(BIT(2) | BIT(1), BIT(3) | BIT(0))
#define BMI088_GYRO_RATE_400  REG_VAL(BIT(1) | BIT(0), BIT(3) | BIT(2))
#define BMI088_GYRO_RATE_1000 REG_VAL(BIT(1), BIT(3) | BIT(2) | BIT(0))
#define BMI088_GYRO_RATE_2000 REG_VAL(BIT(0), BIT(3) | BIT(2) | BIT(1))

#define BMI088_ACCEL_RANGE_3_G  0x00
#define BMI088_ACCEL_RANGE_6_G  0x01
#define BMI088_ACCEL_RANGE_12_G 0x02
#define BMI088_ACCEL_RANGE_24_G 0x03

#define BMI088_ACCEL_BW_12_5 0xA5
#define BMI088_ACCEL_BW_25   0xA6
#define BMI088_ACCEL_BW_50   0xA7
#define BMI088_ACCEL_BW_100  0xA8
#define BMI088_ACCEL_BW_200  0xA9
#define BMI088_ACCEL_BW_400  0xAA
#define BMI088_ACCEL_BW_800  0xAB
#define BMI088_ACCEL_BW_1600 0xAC

#define BMI088_ACCEL_RATE_12_5 REG_VAL(BIT(0) | BIT(2), BIT(1) | BIT(3))
#define BMI088_ACCEL_RATE_25   REG_VAL(BIT(1) | BIT(2), BIT(0) | BIT(3))
#define BMI088_ACCEL_RATE_50   REG_VAL(BIT(0) | BIT(1) | BIT(2), BIT(3))
#define BMI088_ACCEL_RATE_100  REG_VAL(BIT(3), BIT(0) | BIT(1) | BIT(2))
#define BMI088_ACCEL_RATE_200  REG_VAL(BIT(0) | BIT(3), BIT(1) | BIT(2))
#define BMI088_ACCEL_RATE_400  REG_VAL(BIT(1) | BIT(3), BIT(0) | BIT(2))
#define BMI088_ACCEL_RATE_800  REG_VAL(BIT(0) | BIT(1) | BIT(3), BIT(2))
#define BMI088_ACCEL_RATE_1600 REG_VAL(BIT(2) | BIT(3), BIT(0) | BIT(1))

#define BMI088_ACCEL_OSR_0 REG_VAL(BIT(5) | BIT(7), BIT(4) | BIT(6))
#define BMI088_ACCEL_OSR_2 REG_VAL(BIT(4) | BIT(7), BIT(5) | BIT(6))
#define BMI088_ACCEL_OSR_4 REG_VAL(BIT(7), BIT(4) | BIT(5) | BIT(6))

#define DIR_READ     0x80
#define DIR_WRITE    0x00
#define M_PI_F       3.1415926f
#define BMI088_ONE_G 9.80665f

typedef struct {
    uint8_t setbits;
    uint8_t clearbits;
} reg_val_t;

static rt_device_t gyro_spi_dev;
static rt_device_t accel_spi_dev;
static float gyro_range_scale;
static float accel_range_scale;
static float sample_rate;

/* Re-implement this function to define customized rotation */
RT_WEAK void bmi088_rotate_to_frd(float* data, uint32_t dev_id)
{
    /* do nothing */
    (void)data;
    (void)dev_id;
}

static rt_err_t __write_checked_reg(rt_device_t spi_device, rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t r_val;

    RT_TRY(spi_write_reg8(spi_device, reg, val));
    /* In case of read operations of the accelerometer part, the requested data is not sent 
    immediately, but instead first a dummy byte is sent, and after this dummy byte the actual 
    reqested register content is transmitted. */
    RT_TRY(spi_read_reg8(spi_device, reg, &r_val));
    RT_TRY(spi_read_reg8(spi_device, reg, &r_val));

    return (r_val == val) ? RT_EOK : RT_ERROR;
}

static rt_err_t __modify_reg(rt_device_t spi_device, rt_uint8_t reg, reg_val_t reg_val)
{
    uint8_t value;

    /* In case of read operations of the accelerometer part, the requested data is not sent 
    immediately, but instead first a dummy byte is sent, and after this dummy byte the actual 
    reqested register content is transmitted. */
    RT_TRY(spi_read_reg8(spi_device, reg, &value));
    RT_TRY(spi_read_reg8(spi_device, reg, &value));

    value &= ~reg_val.clearbits;
    value |= reg_val.setbits;

    RT_TRY(__write_checked_reg(spi_device, reg, value));

    return RT_EOK;
}

static rt_err_t gyro_set_sample_rate(uint32_t frequency_hz)
{
    reg_val_t reg_val;

    if (frequency_hz <= 150) {
        reg_val = BMI088_GYRO_RATE_100;
    } else if (frequency_hz <= 300) {
        reg_val = BMI088_GYRO_RATE_200;
    } else if (frequency_hz <= 700) {
        reg_val = BMI088_GYRO_RATE_400;
    } else if (frequency_hz <= 1500) {
        reg_val = BMI088_GYRO_RATE_1000;
    } else if (frequency_hz <= 2000) {
        reg_val = BMI088_GYRO_RATE_2000;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(__modify_reg(gyro_spi_dev, BMI088_BW_ADDR, reg_val));

    return RT_EOK;
}

static rt_err_t gyro_set_dlpf_filter(uint16_t frequency_hz)
{
    /* lpf bw is set by BMI088_BW_ADDR */
    (void)frequency_hz;

    return RT_EOK;
}

static rt_err_t gyro_set_range(unsigned max_dps)
{
    reg_val_t reg_val;
    float lsb_per_dps;

    if (max_dps == 0) {
        max_dps = 2000;
    }

    if (max_dps <= 187) {
        reg_val = BMI088_GYRO_RANGE_125_DPS;
        lsb_per_dps = 262.4;
    } else if (max_dps <= 375) {
        reg_val = BMI088_GYRO_RANGE_250_DPS;
        lsb_per_dps = 131.2;
    } else if (max_dps <= 750) {
        reg_val = BMI088_GYRO_RANGE_500_DPS;
        lsb_per_dps = 65.6;
    } else if (max_dps <= 1500) {
        reg_val = BMI088_GYRO_RANGE_1000_DPS;
        lsb_per_dps = 32.8;
    } else if (max_dps <= 2000) {
        reg_val = BMI088_GYRO_RANGE_2000_DPS;
        lsb_per_dps = 16.4;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(__modify_reg(gyro_spi_dev, BMI088_RANGE_ADDR, reg_val));

    gyro_range_scale = (M_PI_F / (180.0f * lsb_per_dps));

    return RT_EOK;
}

static rt_err_t gyro_read_raw(int16_t gyr[3])
{
    RT_TRY(spi_read_multi_reg8(gyro_spi_dev, BMI088_RATE_X_LSB_ADDR, (uint8_t*)gyr, 6));

    return RT_EOK;
}

static rt_err_t gyro_read_rad(float gyr[3])
{
    int16_t gyr_raw[3];

    RT_TRY(gyro_read_raw(gyr_raw));

    gyr[0] = gyro_range_scale * gyr_raw[0];
    gyr[1] = gyro_range_scale * gyr_raw[1];
    gyr[2] = gyro_range_scale * gyr_raw[2];

    return RT_EOK;
}

static rt_err_t gyroscope_init(void)
{
    uint8_t gyro_id;

    /* init spi bus */
    RT_TRY(rt_device_open(gyro_spi_dev, RT_DEVICE_OFLAG_RDWR));

    spi_read_reg8(gyro_spi_dev, BMI088_CHIP_ID_ADDR, &gyro_id);
    if (gyro_id != BMI088_GRRO_CHIP_ID) {
        DRV_DBG("Warning: not found BMI088 gyro id: %02x\n", gyro_id);
        return RT_ERROR;
    }

    /* soft reset */
    RT_TRY(spi_write_reg8(gyro_spi_dev, BMI088_BGW_SOFT_RST_ADDR, 0xB6));
    systime_udelay(35000); // > 30ms delay

    RT_TRY(gyro_set_range(2000));       /* 2000dps */
    RT_TRY(gyro_set_sample_rate(1000)); /* OSR 1000KHz, Filter BW: 116Hz */

    /* enable gyroscope */
    RT_TRY(__modify_reg(gyro_spi_dev, BMI088_MODE_LPM1_ADDR, REG_VAL(0, BIT(7) | BIT(5)))); /* {0; 0}  NORMAL mode */
    systime_udelay(1000);

    return RT_EOK;
}

static rt_err_t gyro_config(gyro_dev_t gyro, const struct gyro_configure* cfg)
{
    RT_ASSERT(cfg != RT_NULL);

    RT_TRY(gyro_set_range(cfg->gyro_range_dps));

    RT_TRY(gyro_set_sample_rate(cfg->sample_rate_hz));

    RT_TRY(gyro_set_dlpf_filter(cfg->dlpf_freq_hz));

    gyro->config = *cfg;

    return RT_EOK;
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

    if (gyro_read_rad((float*)data) != RT_EOK) {
        return 0;
    }

    // change to NED coordinate
    bmi088_rotate_to_frd((float*)data, (uint32_t)gyro->parent.user_data);

    return size;
}

const static struct gyro_ops __gyro_ops = {
    gyro_config,
    gyro_control,
    gyro_read,
};

static rt_err_t accel_set_sample_rate(uint32_t frequency_hz)
{
    reg_val_t reg_val;

    if (frequency_hz <= (125 / 10)) {
        reg_val = BMI088_ACCEL_RATE_12_5;
        sample_rate = 12.5;
    } else if (frequency_hz <= 25) {
        reg_val = BMI088_ACCEL_RATE_25;
        sample_rate = 25;
    } else if (frequency_hz <= 50) {
        reg_val = BMI088_ACCEL_RATE_50;
        sample_rate = 50;
    } else if (frequency_hz <= 100) {
        reg_val = BMI088_ACCEL_RATE_100;
        sample_rate = 100;
    } else if (frequency_hz <= 200) {
        reg_val = BMI088_ACCEL_RATE_200;
        sample_rate = 200;
    } else if (frequency_hz <= 400) {
        reg_val = BMI088_ACCEL_RATE_400;
        sample_rate = 400;
    } else if (frequency_hz <= 800) {
        reg_val = BMI088_ACCEL_RATE_800;
        sample_rate = 800;
    } else if (frequency_hz <= 1600) {
        reg_val = BMI088_ACCEL_RATE_1600;
        sample_rate = 1600;
    } else {
        return EINVAL;
    }

    RT_TRY(__modify_reg(accel_spi_dev, BMI088_ACC_CONF, reg_val));

    return RT_EOK;
}

static rt_err_t accel_set_bwp_odr(uint16_t dlpf_freq_hz)
{
    reg_val_t reg_val;

    if (sample_rate <= 12.5) {
        if (dlpf_freq_hz <= 1) {
            // 1Hz
            reg_val = BMI088_ACCEL_OSR_4;
        }
        if (dlpf_freq_hz <= 3) {
            // 2Hz
            reg_val = BMI088_ACCEL_OSR_2;
        } else {
            // 5Hz
            reg_val = BMI088_ACCEL_OSR_0;
        }
    } else if (sample_rate <= 25) {
        if (dlpf_freq_hz <= 4) {
            // 3Hz
            reg_val = BMI088_ACCEL_OSR_4;
        }
        if (dlpf_freq_hz <= 7) {
            // 5Hz
            reg_val = BMI088_ACCEL_OSR_2;
        } else {
            // 10Hz
            reg_val = BMI088_ACCEL_OSR_0;
        }
    } else if (sample_rate <= 50) {
        if (dlpf_freq_hz <= 7) {
            // 5Hz
            reg_val = BMI088_ACCEL_OSR_4;
        }
        if (dlpf_freq_hz <= 14) {
            // 9Hz
            reg_val = BMI088_ACCEL_OSR_2;
        } else {
            // 20Hz
            reg_val = BMI088_ACCEL_OSR_0;
        }
    } else if (sample_rate <= 100) {
        if (dlpf_freq_hz <= 14) {
            // 10Hz
            reg_val = BMI088_ACCEL_OSR_4;
        }
        if (dlpf_freq_hz <= 29) {
            // 19Hz
            reg_val = BMI088_ACCEL_OSR_2;
        } else {
            // 40Hz
            reg_val = BMI088_ACCEL_OSR_0;
        }
    } else if (sample_rate <= 200) {
        if (dlpf_freq_hz <= 29) {
            // 20Hz
            reg_val = BMI088_ACCEL_OSR_4;
        }
        if (dlpf_freq_hz <= 59) {
            // 38Hz
            reg_val = BMI088_ACCEL_OSR_2;
        } else {
            // 80Hz
            reg_val = BMI088_ACCEL_OSR_0;
        }
    } else if (sample_rate <= 400) {
        if (dlpf_freq_hz <= 52) {
            // 40Hz
            reg_val = BMI088_ACCEL_OSR_4;
        }
        if (dlpf_freq_hz <= 110) {
            // 75Hz
            reg_val = BMI088_ACCEL_OSR_2;
        } else {
            // 145Hz
            reg_val = BMI088_ACCEL_OSR_0;
        }
    } else if (sample_rate <= 800) {
        if (dlpf_freq_hz <= 110) {
            // 80Hz
            reg_val = BMI088_ACCEL_OSR_4;
        }
        if (dlpf_freq_hz <= 175) {
            // 140Hz
            reg_val = BMI088_ACCEL_OSR_2;
        } else {
            // 230Hz
            reg_val = BMI088_ACCEL_OSR_0;
        }
    } else if (sample_rate <= 1600) {
        if (dlpf_freq_hz <= 199) {
            // 145Hz
            reg_val = BMI088_ACCEL_OSR_4;
        }
        if (dlpf_freq_hz <= 257) {
            // 234Hz
            reg_val = BMI088_ACCEL_OSR_2;
        } else {
            // 280Hz
            reg_val = BMI088_ACCEL_OSR_0;
        }
    } else {
        return EINVAL;
    }

    RT_TRY(__modify_reg(accel_spi_dev, BMI088_ACC_CONF, reg_val));
    return RT_EOK;
}

static rt_err_t accel_set_range(uint32_t max_g)
{
    uint8_t reg_val;

    if (max_g == 0) {
        max_g = 24;
    }

    if (max_g <= 3) {
        reg_val = BMI088_ACCEL_RANGE_3_G;
        accel_range_scale = (3 * BMI088_ONE_G / 32768);
    } else if (max_g <= 6) {
        reg_val = BMI088_ACCEL_RANGE_6_G;
        accel_range_scale = (6 * BMI088_ONE_G / 32768);
    } else if (max_g <= 12) {
        reg_val = BMI088_ACCEL_RANGE_12_G;
        accel_range_scale = (12 * BMI088_ONE_G / 32768);
    } else if (max_g <= 24) {
        reg_val = BMI088_ACCEL_RANGE_24_G;
        accel_range_scale = (24 * BMI088_ONE_G / 32768);
    } else {
        return RT_EINVAL;
    }

    RT_TRY(spi_write_reg8(accel_spi_dev, BMI088_ACC_RANGE, reg_val));
    return RT_EOK;
}

static rt_err_t accelerometer_init(void)
{
    uint8_t accel_id;

    /* init spi bus */
    RT_TRY(rt_device_open(accel_spi_dev, RT_DEVICE_OFLAG_RDWR));

    /* dummy read to let accel enter SPI mode */
    RT_TRY(spi_read_reg8(accel_spi_dev, BMI088_ACC_BGW_CHIPID, &accel_id));

    /* read accel id */
    RT_TRY(spi_read_reg8(accel_spi_dev, BMI088_ACC_BGW_CHIPID, &accel_id));
    if (accel_id != BMI088_ACC_BGW_CHIPID_VALUE) {
        DRV_DBG("Warning: not found BMI088 accel id: %02x\n", accel_id);
        return RT_ERROR;
    }

    /* soft reset */
    RT_TRY(spi_write_reg8(accel_spi_dev, BMI088_ACC_SOFTRESET, 0xB6));
    systime_udelay(2000);
    /* dummy read to let accel enter SPI mode */
    RT_TRY(spi_read_reg8(accel_spi_dev, BMI088_ACC_BGW_CHIPID, &accel_id));
    /* enter normal mode */
    RT_TRY(spi_write_reg8(accel_spi_dev, BMI088_ACC_PWR_CTRL, 0x04));
    systime_udelay(55000);

    /* set default range and bandwidth */
    RT_TRY(accel_set_range(24));         /* 24g */
    RT_TRY(accel_set_sample_rate(1600)); /* 1600Hz sample rate */
    RT_TRY(accel_set_bwp_odr(280));      /* Normal BW */

    /* enter active mode */
    RT_TRY(spi_write_reg8(accel_spi_dev, BMI088_ACC_PWR_CONF, 0x00));
    systime_udelay(1000);

    return RT_EOK;
}

static rt_err_t accel_read_raw(int16_t acc[3])
{
    uint8_t buffer[7];

    /* In case of read operations of the accelerometer part, the requested data is not sent 
    immediately, but instead first a dummy byte is sent, and after this dummy byte the actual 
    reqested register content is transmitted. */
    RT_TRY(spi_read_multi_reg8(accel_spi_dev, BMI088_ACCD_X_LSB, buffer, 7));

    acc[0] = buffer[2] << 8 | buffer[1];
    acc[1] = buffer[4] << 8 | buffer[3];
    acc[2] = buffer[6] << 8 | buffer[5];

    return RT_EOK;
}

static rt_err_t accel_read_m_s2(float acc[3])
{
    int16_t acc_raw[3];

    RT_TRY(accel_read_raw(acc_raw));

    acc[0] = accel_range_scale * acc_raw[0];
    acc[1] = accel_range_scale * acc_raw[1];
    acc[2] = accel_range_scale * acc_raw[2];

    return RT_EOK;
}

static rt_err_t accel_config(accel_dev_t accel, const struct accel_configure* cfg)
{

    RT_ASSERT(cfg != NULL);

    RT_TRY(accel_set_range(cfg->acc_range_g));

    RT_TRY(accel_set_sample_rate(cfg->sample_rate_hz));

    RT_TRY(accel_set_bwp_odr(cfg->dlpf_freq_hz));

    accel->config = *cfg;

    return RT_EOK;
}

static rt_err_t accel_control(accel_dev_t accel, int cmd, void* arg)
{
    return RT_EOK;
}

static rt_size_t accel_read(accel_dev_t accel, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == NULL) {
        return 0;
    }

    if (accel_read_m_s2(((float*)data)) != RT_EOK) {
        return 0;
    }

    // change to NED coordinate
    bmi088_rotate_to_frd((float*)data, (uint32_t)accel->parent.user_data);

    return size;
}

const static struct accel_ops __accel_ops = {
    accel_config,
    accel_control,
    accel_read,
};

#define GYRO_CONFIG                                   \
    {                                                 \
        1000,                   /* 1K sample rate */  \
            116,                /* 116Hz bandwidth */ \
            GYRO_RANGE_2000DPS, /* +-2000 deg/s */    \
    }

#define ACCEL_CONFIG                          \
    {                                         \
        1600,    /* 1K sample rate */         \
            145, /* OSR4 145Hz cutoff freq */ \
            12,  /* +-12g */                  \
    }

static struct gyro_device gyro_dev = {
    .ops = &__gyro_ops,
    .config = GYRO_CONFIG,
    .bus_type = GYRO_SPI_BUS_TYPE
};

static struct accel_device accel_dev = {
    .ops = &__accel_ops,
    .config = ACCEL_CONFIG,
    .bus_type = GYRO_SPI_BUS_TYPE
};

rt_err_t drv_bmi088_init(const char* gyro_spi_device_name, const char* accel_spi_device_name,
                         const char* gyro_device_name, const char* accel_device_name, uint32_t dev_id)
{
    /* Initialize gyroscope */

    gyro_spi_dev = rt_device_find(gyro_spi_device_name);
    RT_ASSERT(gyro_spi_dev != NULL);
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)gyro_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }
    /* gyroscope low-level init */
    RT_TRY(gyroscope_init());
    /* register gyro hal device */
    RT_TRY(hal_gyro_register(&gyro_dev, gyro_device_name, RT_DEVICE_FLAG_RDWR, (void*)dev_id));

    /* Initialize accelerometer */

    accel_spi_dev = rt_device_find(accel_spi_device_name);
    RT_ASSERT(accel_spi_dev != NULL);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)accel_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* accelerometer low-level init */
    RT_TRY(accelerometer_init());
    /* register accel hal device */
    RT_TRY(hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, (void*)dev_id));

    return RT_EOK;
}