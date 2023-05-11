/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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
#include "driver/imu/bmi055.h"
#include "hal/accel/accel.h"
#include "hal/gyro/gyro.h"
#include "hal/spi/spi.h"

#define DRV_DBG(...)

#define BIT(_idx) (1 << _idx)
#define REG_VAL(_setbits, _clearbits) \
    (reg_val_t) { .setbits = (_setbits), .clearbits = (_clearbits) }

#define BMI055_ACC_I2C_ADDR1        0x18                 //SDO is low(GND)
#define BMI055_ACC_I2C_ADDR2        0x19                 //SDO is high(VCC)
#define BMI055_ACC_DEFAULT_ADDRESS  BMI055_ACC_I2C_ADDR2 //in the LPC54102 SPM-S
#define BMI055_ACC_BGW_CHIPID_VALUE 0xFA
#define BMI055_ACC_BGW_CHIPID       0x00
#define BMI055_ACCD_X_LSB           0x02
#define BMI055_ACCD_X_MSB           0x03
#define BMI055_ACCD_Y_LSB           0x04
#define BMI055_ACCD_Y_MSB           0x05
#define BMI055_ACCD_Z_LSB           0x06
#define BMI055_ACCD_Z_MSB           0x07
#define BMI055_ACCD_TEMP            0x08
#define BMI055_INT_STATUS_0         0x09
#define BMI055_INT_STATUS_1         0x0A
#define BMI055_INT_STATUS_2         0x0B
#define BMI055_INT_STATUS_3         0x0C
#define BMI055_FIFO_STATUS          0x0E
#define BMI055_PMU_RANGE            0x0F
#define BMI055_PMU_BW               0x10
#define BMI055_PMU_LPW              0x11
#define BMI055_PMU_LOW_POWER        0x12
#define BMI055_ACCD_HBW             0x13
#define BMI055_BGW_SOFTRESET        0x14
#define BMI055_INT_EN_0             0x16
#define BMI055_INT_EN_1             0x17
#define BMI055_INT_EN_2             0x18
#define BMI055_INT_MAP_0            0x19
#define BMI055_INT_MAP_1            0x1A
#define BMI055_INT_MAP_2            0x1B
#define BMI055_INT_SRC              0x1E
#define BMI055_INT_OUT_CTRL         0x20
#define BMI055_INT_RST_LATCH        0x21
#define BMI055_INT_0                0x22
#define BMI055_INT_1                0x23
#define BMI055_INT_2                0x24
#define BMI055_INT_3                0x25
#define BMI055_INT_4                0x26
#define BMI055_INT_5                0x27
#define BMI055_INT_6                0x28
#define BMI055_INT_7                0x29
#define BMI055_INT_8                0x2A
#define BMI055_INT_9                0x2B
#define BMI055_INT_A                0x2C
#define BMI055_INT_B                0x2D
#define BMI055_INT_C                0x2E
#define BMI055_INT_D                0x2F
#define BMI055_FIFO_CONFIG_0        0x30
#define BMI055_PMU_SELF_TEST        0x32
#define BMI055_TRIM_NVM_CTRL        0x33
#define BMI055_BGW_SPI3_WDT         0x34
#define BMI055_OFC_CTRL             0x36
#define BMI055_OFC_SETTING          0x37
#define BMI055_OFC_OFFSET_X         0x38
#define BMI055_OFC_OFFSET_Y         0x39
#define BMI055_OFC_OFFSET_Z         0x3A
#define BMI055_TRIM_GP0             0x3B
#define BMI055_TRIM_GP1             0x3C
#define BMI055_FIFO_CONFIG_1        0x3E
#define BMI055_FIFO_DATA            0x3F

#define BMI055_GYRO_I2C_ADDR1        0x68 //SDO is low(GND)
#define BMI055_GYRO_I2C_ADDR2        0x69 //SDO is high(VCC)
#define BMI055_GYRO_DEFAULT_ADDRESS  BMI055_GYRO_I2C_ADDR2
#define BMI055_GRRO_CHIP_ID          0x0F
#define BMI055_CHIP_ID_ADDR          0x00
#define BMI055_RATE_X_LSB_ADDR       0x02
#define BMI055_RATE_X_MSB_ADDR       0x03
#define BMI055_RATE_Y_LSB_ADDR       0x04
#define BMI055_RATE_Y_MSB_ADDR       0x05
#define BMI055_RATE_Z_LSB_ADDR       0x06
#define BMI055_RATE_Z_MSB_ADDR       0x07
#define BMI055_TEMP_ADDR             0x08
#define BMI055_INTR_STAT0_ADDR       0x09
#define BMI055_INTR_STAT1_ADDR       0x0A
#define BMI055_INTR_STAT2_ADDR       0x0B
#define BMI055_INTR_STAT3_ADDR       0x0C
#define BMI055_FIFO_STAT_ADDR        0x0E
#define BMI055_RANGE_ADDR            0x0F
#define BMI055_BW_ADDR               0x10
#define BMI055_MODE_LPM1_ADDR        0x11
#define BMI055_MODE_LPM2_ADDR        0x12
#define BMI055_HIGH_BW_ADDR          0x13
#define BMI055_BGW_SOFT_RST_ADDR     0x14
#define BMI055_INTR_ENABLE0_ADDR     0x15
#define BMI055_INTR_ENABLE1_ADDR     0x16
#define BMI055_INTR_MAP_ZERO_ADDR    0x17
#define BMI055_INTR_MAP_ONE_ADDR     0x18
#define BMI055_INTR_MAP_TWO_ADDR     0x19
#define BMI055_INTR_ZERO_ADDR        0x1A
#define BMI055_INTR_ONE_ADDR         0x1B
#define BMI055_INTR_TWO_ADDR         0x1C
#define BMI055_INTR_4_ADDR           0x1E
#define BMI055_RST_LATCH_ADDR        0x21
#define BMI055_HIGHRATE_THRES_X_ADDR 0x22
#define BMI055_HIGHRATE_DURN_X_ADDR  0x23
#define BMI055_HIGHRATE_THRES_Y_ADDR 0x24
#define BMI055_HIGHRATE_DURN_Y_ADDR  0x25
#define BMI055_HIGHRATE_THRES_Z_ADDR 0x26
#define BMI055_HIGHRATE_DURN_Z_ADDR  0x27
#define BMI055_SOC_ADDR              0x31
#define BMI055_A_FOC_ADDR            0x32
#define BMI055_TRIM_NVM_CTRL_ADDR    0x33
#define BMI055_BGW_SPI3_WDT_ADDR     0x34
#define BMI055_OFC1_ADDR             0x36
#define BMI055_OFC2_ADDR             0x37
#define BMI055_OFC3_ADDR             0x38
#define BMI055_OFC4_ADDR             0x39
#define BMI055_TRIM_GP0_ADDR         0x3A
#define BMI055_TRIM_GP1_ADDR         0x3B
#define BMI055_SELECTF_TEST_ADDR     0x3C
#define BMI055_FIFO_CGF1_ADDR        0x3D
#define BMI055_FIFO_CGF0_ADDR        0x3E
#define BMI055_FIFO_DATA_ADDR        0x3F

#define BMI055_GYRO_RANGE_2000_DPS REG_VAL(0, BIT(2) | BIT(1) | BIT(0))
#define BMI055_GYRO_RANGE_1000_DPS REG_VAL(BIT(0), BIT(2) | BIT(1))
#define BMI055_GYRO_RANGE_500_DPS  REG_VAL(BIT(1), BIT(2) | BIT(0))
#define BMI055_GYRO_RANGE_250_DPS  REG_VAL(BIT(1) | BIT(0), BIT(2))
#define BMI055_GYRO_RANGE_125_DPS  REG_VAL(BIT(2), BIT(1) | BIT(0))

#define BMI055_GYRO_RATE_100  REG_VAL(BIT(2) | BIT(1) | BIT(0), BIT(3))
#define BMI055_GYRO_RATE_200  REG_VAL(BIT(2) | BIT(1), BIT(3) | BIT(0))
#define BMI055_GYRO_RATE_400  REG_VAL(BIT(1) | BIT(0), BIT(3) | BIT(2))
#define BMI055_GYRO_RATE_1000 REG_VAL(BIT(1), BIT(3) | BIT(2) | BIT(0))
#define BMI055_GYRO_RATE_2000 REG_VAL(BIT(0), BIT(3) | BIT(2) | BIT(1))

#define BMI055_ACCEL_RANGE_2_G  REG_VAL(BIT(1) | BIT(0), BIT(3) | BIT(2))
#define BMI055_ACCEL_RANGE_4_G  REG_VAL(BIT(2) | BIT(0), BIT(3) | BIT(1))
#define BMI055_ACCEL_RANGE_8_G  REG_VAL(BIT(3), BIT(2) | BIT(1) | BIT(0))
#define BMI055_ACCEL_RANGE_16_G REG_VAL(BIT(3) | BIT(2), BIT(1) | BIT(0))

#define BMI055_ACCEL_BW_7_81  REG_VAL(BIT(3), BIT(4) | BIT(2) | BIT(1) | BIT(0))
#define BMI055_ACCEL_BW_15_63 REG_VAL(BIT(3) | BIT(0), BIT(4) | BIT(2) | BIT(1))
#define BMI055_ACCEL_BW_31_25 REG_VAL(BIT(3) | BIT(1), BIT(4) | BIT(2) | BIT(0))
#define BMI055_ACCEL_BW_62_5  REG_VAL(BIT(3) | BIT(1) | BIT(0), BIT(4) | BIT(2))
#define BMI055_ACCEL_BW_125   REG_VAL(BIT(3) | BIT(2), BIT(4) | BIT(1) | BIT(0))
#define BMI055_ACCEL_BW_250   REG_VAL(BIT(3) | BIT(2) | BIT(0), BIT(4) | BIT(1))
#define BMI055_ACCEL_BW_500   REG_VAL(BIT(3) | BIT(2) | BIT(1), BIT(4) | BIT(0))
#define BMI055_ACCEL_BW_1000  REG_VAL(BIT(3) | BIT(2) | BIT(1) | BIT(0), BIT(4))

#define DIR_READ     0x80
#define DIR_WRITE    0x00
#define M_PI_F       3.1415926f
#define BMI055_ONE_G 9.80665f

typedef struct {
    uint8_t setbits;
    uint8_t clearbits;
} reg_val_t;

static rt_device_t gyro_spi_dev;
static rt_device_t accel_spi_dev;
static float gyro_range_scale;
static float accel_range_scale;

/* Re-implement this function to define customized rotation */
RT_WEAK void bmi055_rotate_to_frd(float val[3])
{
    /* do nothing */
}

static rt_err_t __write_checked_reg(rt_device_t spi_device, rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t r_val;

    RT_TRY(spi_write_reg8(spi_device, reg, val));
    RT_TRY(spi_read_reg8(spi_device, reg, &r_val));

    return (r_val == val) ? RT_EOK : RT_ERROR;
}

static rt_err_t __modify_reg(rt_device_t spi_device, rt_uint8_t reg, reg_val_t reg_val)
{
    uint8_t value;

    RT_TRY(spi_read_reg8(spi_device, reg, &value));

    value &= ~reg_val.clearbits;
    value |= reg_val.setbits;

    RT_TRY(__write_checked_reg(spi_device, reg, value));

    return RT_EOK;
}

static rt_err_t gyro_set_sample_rate(uint32_t frequency_hz)
{
    reg_val_t reg_val;

    if (frequency_hz <= 100) {
        reg_val = BMI055_GYRO_RATE_100;
    } else if (frequency_hz <= 200) {
        reg_val = BMI055_GYRO_RATE_200;
    } else if (frequency_hz <= 400) {
        reg_val = BMI055_GYRO_RATE_400;
    } else if (frequency_hz <= 1000) {
        reg_val = BMI055_GYRO_RATE_1000;
    } else if (frequency_hz <= 2000) {
        reg_val = BMI055_GYRO_RATE_2000;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(__modify_reg(gyro_spi_dev, BMI055_BW_ADDR, reg_val));

    return RT_EOK;
}

static rt_err_t gyro_set_dlpf_filter(uint16_t frequency_hz)
{
    /* lpf bw is set by BMI055_BW_ADDR */
    return RT_EOK;
}

static rt_err_t gyro_set_range(unsigned max_dps)
{
    reg_val_t reg_val;
    float lsb_per_dps;

    if (max_dps == 0) {
        max_dps = 2000;
    }

    if (max_dps <= 125) {
        reg_val = BMI055_GYRO_RANGE_125_DPS;
        lsb_per_dps = 262.4;
    } else if (max_dps <= 250) {
        reg_val = BMI055_GYRO_RANGE_250_DPS;
        lsb_per_dps = 131.2;
    } else if (max_dps <= 500) {
        reg_val = BMI055_GYRO_RANGE_500_DPS;
        lsb_per_dps = 65.6;
    } else if (max_dps <= 1000) {
        reg_val = BMI055_GYRO_RANGE_1000_DPS;
        lsb_per_dps = 32.8;
    } else if (max_dps <= 2000) {
        reg_val = BMI055_GYRO_RANGE_2000_DPS;
        lsb_per_dps = 16.4;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(__modify_reg(gyro_spi_dev, BMI055_RANGE_ADDR, reg_val));

    gyro_range_scale = (M_PI_F / (180.0f * lsb_per_dps));

    return RT_EOK;
}

static rt_err_t gyro_read_raw(int16_t gyr[3])
{
    RT_TRY(spi_read_multi_reg8(gyro_spi_dev, BMI055_RATE_X_LSB_ADDR, (uint8_t*)gyr, 6));

    return RT_EOK;
}

static rt_err_t gyro_read_rad(float gyr[3])
{
    int16_t gyr_raw[3];

    RT_TRY(gyro_read_raw(gyr_raw));

    gyr[0] = gyro_range_scale * gyr_raw[0];
    gyr[1] = gyro_range_scale * gyr_raw[1];
    gyr[2] = gyro_range_scale * gyr_raw[2];
    // change to NED coordinate
    bmi055_rotate_to_frd(gyr);
    return RT_EOK;
}

static rt_err_t gyroscope_init(void)
{
    uint8_t gyro_id;

    /* init spi bus */
    RT_TRY(rt_device_open(gyro_spi_dev, RT_DEVICE_OFLAG_RDWR));

    spi_read_reg8(gyro_spi_dev, BMI055_CHIP_ID_ADDR, &gyro_id);
    if (gyro_id != BMI055_GRRO_CHIP_ID) {
        DRV_DBG("Warning: not found BMI055 gyro id: %02x\n", gyro_id);
        return RT_ERROR;
    }

    /* soft reset */
    RT_TRY(spi_write_reg8(gyro_spi_dev, BMI055_BGW_SOFT_RST_ADDR, 0xB6));
    systime_udelay(5000);

    RT_TRY(gyro_set_range(2000));       /* 2000dps */
    RT_TRY(gyro_set_sample_rate(1000)); /* OSR 1000KHz, Filter BW: 116Hz */

    /* enable gyroscope */
    RT_TRY(__modify_reg(gyro_spi_dev, BMI055_MODE_LPM1_ADDR, REG_VAL(0, BIT(7) | BIT(5)))); /* {0; 0}  NORMAL mode */
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

    if (gyro_read_rad(((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
}

const static struct gyro_ops __gyro_ops = {
    gyro_config,
    gyro_control,
    gyro_read,
};

static rt_err_t accel_set_sample_rate(uint32_t frequency_hz)
{
    return RT_EOK;
}

static rt_err_t accel_set_dlpf_filter(uint16_t frequency_hz)
{
    reg_val_t reg_val;

    if (frequency_hz <= (781 / 100)) {
        reg_val = BMI055_ACCEL_BW_7_81;
    } else if (frequency_hz <= (1563 / 100)) {
        reg_val = BMI055_ACCEL_BW_15_63;
    } else if (frequency_hz <= (3125 / 100)) {
        reg_val = BMI055_ACCEL_BW_31_25;
    } else if (frequency_hz <= 6250 / 100) {
        reg_val = BMI055_ACCEL_BW_62_5;
    } else if (frequency_hz <= 125) {
        reg_val = BMI055_ACCEL_BW_125;
    } else if (frequency_hz <= 250) {
        reg_val = BMI055_ACCEL_BW_250;
    } else if (frequency_hz <= 500) {
        reg_val = BMI055_ACCEL_BW_500;
    } else if (frequency_hz <= 1000) {
        reg_val = BMI055_ACCEL_BW_1000;
    } else {
        return -EINVAL;
    }

    RT_TRY(__modify_reg(accel_spi_dev, BMI055_PMU_BW, reg_val));

    return RT_EOK;
}

static rt_err_t accel_set_range(uint32_t max_g)
{
    reg_val_t reg_val;
    float lsb_per_g;

    if (max_g == 0) {
        max_g = 16;
    }

    if (max_g <= 2) {
        reg_val = BMI055_ACCEL_RANGE_2_G;
        lsb_per_g = 1024;
    } else if (max_g <= 4) {
        reg_val = BMI055_ACCEL_RANGE_4_G;
        lsb_per_g = 512;
    } else if (max_g <= 8) {
        reg_val = BMI055_ACCEL_RANGE_8_G;
        lsb_per_g = 256;
    } else if (max_g <= 16) {
        reg_val = BMI055_ACCEL_RANGE_16_G;
        lsb_per_g = 128;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(__modify_reg(accel_spi_dev, BMI055_PMU_RANGE, reg_val));

    accel_range_scale = (BMI055_ONE_G / lsb_per_g);

    return RT_EOK;
}

static rt_err_t accelerometer_init(void)
{
    uint8_t accel_id;

    /* init spi bus */
    RT_TRY(rt_device_open(accel_spi_dev, RT_DEVICE_OFLAG_RDWR));

    spi_read_reg8(accel_spi_dev, BMI055_ACC_BGW_CHIPID, &accel_id);
    if (accel_id != BMI055_ACC_BGW_CHIPID_VALUE) {
        DRV_DBG("Warning: not found BMI055 accel id: %02x\n", accel_id);
        return RT_ERROR;
    }

    /* soft reset */
    RT_TRY(spi_write_reg8(accel_spi_dev, BMI055_BGW_SOFTRESET, 0xB6));
    systime_udelay(5000);

    RT_TRY(accel_set_range(2));          /* 2g */
    RT_TRY(accel_set_dlpf_filter(1000)); /* 1000Hz BW */

    /* enable gyroscope */
    RT_TRY(__modify_reg(accel_spi_dev, BMI055_PMU_LPW, REG_VAL(0, BIT(7) | BIT(6) | BIT(5)))); /* {0; 0; 0}  NORMAL mode */
    systime_udelay(1000);

    return RT_EOK;
}

static rt_err_t accel_read_raw(int16_t acc[3])
{
    uint8_t buffer[6];
    int16_t msblsb;

    RT_TRY(spi_read_multi_reg8(accel_spi_dev, BMI055_ACCD_X_LSB, buffer, 6));

    msblsb = buffer[1] << 8 | buffer[0];
    acc[0] = msblsb >> 4;
    msblsb = buffer[3] << 8 | buffer[2];
    acc[1] = msblsb >> 4;
    msblsb = buffer[5] << 8 | buffer[4];
    acc[2] = msblsb >> 4;

    return RT_EOK;
}

static rt_err_t accel_read_m_s2(float acc[3])
{
    int16_t acc_raw[3];

    RT_TRY(accel_read_raw(acc_raw));

    acc[0] = accel_range_scale * acc_raw[0];
    acc[1] = accel_range_scale * acc_raw[1];
    acc[2] = accel_range_scale * acc_raw[2];

    // change to NED coordinate
    bmi055_rotate_to_frd(acc);

    return RT_EOK;
}

static rt_err_t accel_config(accel_dev_t accel, const struct accel_configure* cfg)
{
    RT_ASSERT(cfg != NULL);

    RT_TRY(accel_set_range(cfg->acc_range_g));

    RT_TRY(accel_set_sample_rate(cfg->sample_rate_hz));

    RT_TRY(accel_set_dlpf_filter(cfg->dlpf_freq_hz));

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
            92,                 /* 256Hz bandwidth */ \
            GYRO_RANGE_2000DPS, /* +-2000 deg/s */    \
    }

#define ACCEL_CONFIG                               \
    {                                              \
        1000,                /* 1K sample rate */  \
            125,             /* 125Hz bandwidth */ \
            ACCEL_RANGE_16G, /* +-16g */           \
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

rt_err_t drv_bmi055_init(const char* spi_device_name, const char* gyro_device_name, const char* accel_device_name)
{
    /* Initialize gyroscope */

    gyro_spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(gyro_spi_dev != NULL);
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = SPI1_SPEED_HZ;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)gyro_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }
    /* gyroscope low-level init */
    RT_TRY(gyroscope_init());
    /* register gyro hal device */
    RT_TRY(hal_gyro_register(&gyro_dev, gyro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    /* Initialize accelerometer */

    accel_spi_dev = rt_device_find("spi1_dev4");
    RT_ASSERT(accel_spi_dev != NULL);
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = SPI1_SPEED_HZ;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)accel_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* accelerometer low-level init */
    RT_TRY(accelerometer_init());

    /* register accel hal device */
    RT_TRY(hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}
