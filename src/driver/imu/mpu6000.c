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
#include <firmament.h>

#include "driver/imu/mpu6000.h"
#include "hal/accel/accel.h"
#include "hal/gyro/gyro.h"
#include "hal/spi/spi.h"
#include "module/math/conversion.h"

#define DRV_DBG(...) console_printf(__VA_ARGS__)

#define DIR_READ  0x80
#define DIR_WRITE 0x00

// MPU 6000 registers
#define MPUREG_WHOAMI       0x75
#define MPUREG_SMPLRT_DIV   0x19
#define MPUREG_CONFIG       0x1A
#define MPUREG_GYRO_CONFIG  0x1B
#define MPUREG_ACCEL_CONFIG 0x1C
#define MPUREG_FIFO_EN      0x23
#define MPUREG_INT_PIN_CFG  0x37
#define MPUREG_INT_ENABLE   0x38
#define MPUREG_INT_STATUS   0x3A
#define MPUREG_ACCEL_XOUT_H 0x3B
#define MPUREG_ACCEL_XOUT_L 0x3C
#define MPUREG_ACCEL_YOUT_H 0x3D
#define MPUREG_ACCEL_YOUT_L 0x3E
#define MPUREG_ACCEL_ZOUT_H 0x3F
#define MPUREG_ACCEL_ZOUT_L 0x40
#define MPUREG_TEMP_OUT_H   0x41
#define MPUREG_TEMP_OUT_L   0x42
#define MPUREG_GYRO_XOUT_H  0x43
#define MPUREG_GYRO_XOUT_L  0x44
#define MPUREG_GYRO_YOUT_H  0x45
#define MPUREG_GYRO_YOUT_L  0x46
#define MPUREG_GYRO_ZOUT_H  0x47
#define MPUREG_GYRO_ZOUT_L  0x48
#define MPUREG_USER_CTRL    0x6A
#define MPUREG_PWR_MGMT_1   0x6B
#define MPUREG_PWR_MGMT_2   0x6C
#define MPUREG_FIFO_COUNTH  0x72
#define MPUREG_FIFO_COUNTL  0x73
#define MPUREG_FIFO_R_W     0x74
#define MPUREG_PRODUCT_ID   0x0C
#define MPUREG_TRIM1        0x0D
#define MPUREG_TRIM2        0x0E
#define MPUREG_TRIM3        0x0F
#define MPUREG_TRIM4        0x10

// Configuration bits MPU 3000 and MPU 6000 (not revised)?
#define BIT_SLEEP                  0x40
#define BIT_H_RESET                0x80
#define BITS_CLKSEL                0x07
#define MPU_CLK_SEL_PLLGYROX       0x01
#define MPU_CLK_SEL_PLLGYROZ       0x03
#define MPU_EXT_SYNC_GYROX         0x02
#define BITS_GYRO_ST_X             0x80
#define BITS_GYRO_ST_Y             0x40
#define BITS_GYRO_ST_Z             0x20
#define BITS_FS_250DPS             0x00
#define BITS_FS_500DPS             0x08
#define BITS_FS_1000DPS            0x10
#define BITS_FS_2000DPS            0x18
#define BITS_FS_MASK               0x18
#define BITS_DLPF_CFG_256HZ_NOLPF2 0x00
#define BITS_DLPF_CFG_188HZ        0x01
#define BITS_DLPF_CFG_98HZ         0x02
#define BITS_DLPF_CFG_42HZ         0x03
#define BITS_DLPF_CFG_20HZ         0x04
#define BITS_DLPF_CFG_10HZ         0x05
#define BITS_DLPF_CFG_5HZ          0x06
#define BITS_DLPF_CFG_2100HZ_NOLPF 0x07
#define BITS_DLPF_CFG_MASK         0x07
#define BIT_INT_ANYRD_2CLEAR       0x10
#define BIT_RAW_RDY_EN             0x01
#define BIT_I2C_IF_DIS             0x10
#define BIT_INT_STATUS_DATA        0x01

#define MPU_WHOAMI_6000  0x68
#define ICM_WHOAMI_20608 0xaf

// ICM2608 specific registers

/* this is an undocumented register which
   if set incorrectly results in getting a 2.7m/s/s offset
   on the Y axis of the accelerometer
*/
#define MPUREG_ICM_UNDOC1       0x11
#define MPUREG_ICM_UNDOC1_VALUE 0xc9

// Product ID Description for ICM2608
// There is none

#define ICM20608_REV_00 0

// Product ID Description for MPU6000
// high 4 bits 	low 4 bits
// Product Name	Product Revision
#define MPU6000ES_REV_C4 0x14
#define MPU6000ES_REV_C5 0x15
#define MPU6000ES_REV_D6 0x16
#define MPU6000ES_REV_D7 0x17
#define MPU6000ES_REV_D8 0x18
#define MPU6000_REV_C4   0x54
#define MPU6000_REV_C5   0x55
#define MPU6000_REV_D6   0x56
#define MPU6000_REV_D7   0x57
#define MPU6000_REV_D8   0x58
#define MPU6000_REV_D9   0x59
#define MPU6000_REV_D10  0x5A

#define MPU6000_ACCEL_DEFAULT_RANGE_G            8
#define MPU6000_ACCEL_DEFAULT_RATE               1000
#define MPU6000_ACCEL_DEFAULT_DRIVER_FILTER_FREQ 30

#define MPU6000_GYRO_DEFAULT_RANGE_G            8
#define MPU6000_GYRO_DEFAULT_RATE               1000
#define MPU6000_GYRO_DEFAULT_DRIVER_FILTER_FREQ 30

//#define MPU6000_DEFAULT_ONCHIP_FILTER_FREQ		42
#define MPU6000_DEFAULT_ONCHIP_FILTER_FREQ 256

#define MPU6000_ONE_G 9.80665f

#define M_PI_F 3.1415926f

static unsigned _sample_rate = 0;
static unsigned _dlpf_freq;
static uint8_t _product;
static float _gyro_range_scale;
static float _gyro_range_rad_s;
static float _accel_range_scale;
static float _accel_range_m_s2;
static rt_device_t spi_device;

/* Re-implement this function to define customized rotation */
RT_WEAK void mpu6000_rotate_to_frd(float* val)
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

static rt_err_t read_multi_reg(rt_uint8_t reg, rt_uint8_t* buff, uint8_t len)
{
    rt_uint8_t cmd;
    rt_err_t res;

    cmd = DIR_READ | reg;

    res = rt_spi_send_then_recv((struct rt_spi_device*)spi_device, (void*)&cmd, 1, (void*)buff, len);

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

static rt_err_t _set_sample_rate(unsigned desired_sample_rate_hz)
{
    rt_err_t res;

    if (desired_sample_rate_hz == 0) {
        desired_sample_rate_hz = MPU6000_GYRO_DEFAULT_RATE;
    }

    /* if DLPF is disabled, the output rate is 8K, otherwise is 1K */
    uint8_t div = 1000 / desired_sample_rate_hz;

    if (div > 200) {
        div = 200;
    }

    if (div < 1) {
        div = 1;
    }

    res = _write_checked_reg(MPUREG_SMPLRT_DIV, div - 1);
    _sample_rate = 1000 / div;

    return res;
}

static rt_err_t _set_dlpf_filter(uint16_t frequency_hz)
{
    uint8_t filter;

    /*
	   choose next highest filter frequency available
	 */
    if (frequency_hz == 0) {
        _dlpf_freq = 0;
        filter = BITS_DLPF_CFG_2100HZ_NOLPF;

    } else if (frequency_hz <= 5) {
        _dlpf_freq = 5;
        filter = BITS_DLPF_CFG_5HZ;

    } else if (frequency_hz <= 10) {
        _dlpf_freq = 10;
        filter = BITS_DLPF_CFG_10HZ;

    } else if (frequency_hz <= 21) {
        _dlpf_freq = 21;
        filter = BITS_DLPF_CFG_20HZ;

    } else if (frequency_hz <= 44) {
        _dlpf_freq = 44;
        filter = BITS_DLPF_CFG_42HZ;

    } else if (frequency_hz <= 98) {
        _dlpf_freq = 98;
        filter = BITS_DLPF_CFG_98HZ;

    } else if (frequency_hz <= 188) {
        _dlpf_freq = 188;
        filter = BITS_DLPF_CFG_188HZ;

    } else if (frequency_hz <= 260) {
        _dlpf_freq = 260;
        filter = BITS_DLPF_CFG_256HZ_NOLPF2;

    } else {
        _dlpf_freq = 0;
        filter = BITS_DLPF_CFG_2100HZ_NOLPF;
    }

    return _write_checked_reg(MPUREG_CONFIG, filter);
}

static rt_err_t _set_accel_range(unsigned max_g_in)
{
    // workaround for bugged versions of MPU6k (rev C)
    switch (_product) {
    case MPU6000ES_REV_C4:
    case MPU6000ES_REV_C5:
    case MPU6000_REV_C4:
    case MPU6000_REV_C5:
        _write_checked_reg(MPUREG_ACCEL_CONFIG, 1 << 3);
        _accel_range_scale = (MPU6000_ONE_G / 4096.0f);
        _accel_range_m_s2 = 8.0f * MPU6000_ONE_G;
        return RT_EOK;
    }

    uint8_t afs_sel;
    float lsb_per_g;
    float max_accel_g;

    if (max_g_in > 8) { // 16g - AFS_SEL = 3
        afs_sel = 3;
        lsb_per_g = 2048;
        max_accel_g = 16;

    } else if (max_g_in > 4) { //  8g - AFS_SEL = 2
        afs_sel = 2;
        lsb_per_g = 4096;
        max_accel_g = 8;

    } else if (max_g_in > 2) { //  4g - AFS_SEL = 1
        afs_sel = 1;
        lsb_per_g = 8192;
        max_accel_g = 4;

    } else { //  2g - AFS_SEL = 0
        afs_sel = 0;
        lsb_per_g = 16384;
        max_accel_g = 2;
    }

    _accel_range_scale = (MPU6000_ONE_G / lsb_per_g);
    _accel_range_m_s2 = max_accel_g * MPU6000_ONE_G;

    return _write_checked_reg(MPUREG_ACCEL_CONFIG, afs_sel << 3);
}

static rt_err_t _set_gyro_range(unsigned max_dps)
{
    rt_uint8_t fs_sel;

    if (max_dps <= 250) {
        fs_sel = BITS_FS_250DPS;
    } else if (max_dps <= 500) {
        fs_sel = BITS_FS_500DPS;
    } else if (max_dps <= 1000) {
        fs_sel = BITS_FS_1000DPS;
    } else {
        fs_sel = BITS_FS_2000DPS;
    }

    _gyro_range_scale = (M_PI_F / 180.0f) / (32768.0f / (float)max_dps);
    _gyro_range_rad_s = (float)max_dps * (M_PI_F / 180.0f);

    return _write_checked_reg(MPUREG_GYRO_CONFIG, fs_sel);
}

static rt_err_t _init(void)
{
    rt_err_t res = RT_EOK;

    /* init spi bus */
    rt_device_open(spi_device, RT_DEVICE_OFLAG_RDWR);

    // if the mpu6000 is initialised after the l3gd20 and lsm303d
    // then if we don't do an irqsave/irqrestore here the mpu6000
    // frequenctly comes up in a bad state where all transfers
    // come as zero
    uint8_t tries = 5;
    uint8_t reg_val;
    rt_err_t r_res;

    /* read product id */
    _read_reg(MPUREG_PRODUCT_ID, &_product);

    while (--tries != 0) {
        _write_reg(MPUREG_PWR_MGMT_1, BIT_H_RESET);
        systime_udelay(10000);

        // Wake up device and select GyroZ clock. Note that the
        // MPU6000 starts up in sleep mode, and it can take some time
        // for it to come out of sleep
        _write_checked_reg(MPUREG_PWR_MGMT_1, MPU_CLK_SEL_PLLGYROZ);
        systime_udelay(1000);

        // Disable I2C bus (recommended on datasheet)
        _write_checked_reg(MPUREG_USER_CTRL, BIT_I2C_IF_DIS);

        r_res = _read_reg(MPUREG_PWR_MGMT_1, &reg_val);

        if (r_res == RT_EOK && reg_val == MPU_CLK_SEL_PLLGYROZ) {
            break;
        }

        systime_udelay(2000);
    }

    r_res = _read_reg(MPUREG_PWR_MGMT_1, &reg_val);

    if (reg_val != MPU_CLK_SEL_PLLGYROZ) {
        return RT_ERROR;
    }

    systime_udelay(1000);

    // SAMPLE RATE
    if (_set_sample_rate(MPU6000_ACCEL_DEFAULT_RATE) != RT_EOK) {
        DRV_DBG("err, mpu6000, set sample rate fail\n");
        return RT_ERROR;
    }

    systime_udelay(1000);

    // FS & DLPF   FS=2000 deg/s, DLPF = 20Hz (low pass filter)
    // was 90 Hz, but this ruins quality and does not improve the
    // system response
    if (_set_dlpf_filter(MPU6000_DEFAULT_ONCHIP_FILTER_FREQ) != RT_EOK) {
        DRV_DBG("err, mpu6000, set lpf fail\n");
        return RT_ERROR;
    }

    systime_udelay(1000);

    _set_gyro_range(2000);

    systime_udelay(1000);

    _set_accel_range(8);

    systime_udelay(1000);

    // INT CFG => Interrupt on Data Ready
    _write_checked_reg(MPUREG_INT_ENABLE, BIT_RAW_RDY_EN); // INT: Raw data ready
    systime_udelay(1000);
    _write_checked_reg(MPUREG_INT_PIN_CFG, BIT_INT_ANYRD_2CLEAR); // INT: Clear on any read
    systime_udelay(1000);

    // if (is_icm_device()) {
    // 	_write_checked_reg(MPUREG_ICM_UNDOC1, MPUREG_ICM_UNDOC1_VALUE);
    // }

    // Oscillator set
    // _write_reg(MPUREG_PWR_MGMT_1,MPU_CLK_SEL_PLLGYROZ);
    // systime_udelay(1000);

    return res;
}

static rt_err_t mpu6000_gyr_read_raw(int16_t gyr[3])
{
    rt_err_t res;
    uint16_t raw[3];
    res = read_multi_reg(MPUREG_GYRO_XOUT_H, (uint8_t*)raw, 6);
    // big-endian to little-endian
    gyr[0] = int16_t_from_bytes((uint8_t*)&raw[0]);
    gyr[1] = int16_t_from_bytes((uint8_t*)&raw[1]);
    gyr[2] = int16_t_from_bytes((uint8_t*)&raw[2]);

    return res;
}

static rt_err_t mpu6000_gyr_read_rad(float gyr[3])
{
    int16_t gyr_raw[3];
    rt_err_t res;
    res = mpu6000_gyr_read_raw(gyr_raw);

    gyr[0] = _gyro_range_scale * gyr_raw[0];
    gyr[1] = _gyro_range_scale * gyr_raw[1];
    gyr[2] = _gyro_range_scale * gyr_raw[2];

    mpu6000_rotate_to_frd(gyr);

    return res;
}

static rt_err_t mpu6000_acc_read_raw(int16_t acc[3])
{
    int16_t raw[3];
    rt_err_t res;
    res = read_multi_reg(MPUREG_ACCEL_XOUT_H, (rt_uint8_t*)raw, 6);
    // big-endian to little-endian
    acc[0] = int16_t_from_bytes((uint8_t*)&raw[0]);
    acc[1] = int16_t_from_bytes((uint8_t*)&raw[1]);
    acc[2] = int16_t_from_bytes((uint8_t*)&raw[2]);

    return res;
}

static rt_err_t mpu6000_acc_read_m_s2(float acc[3])
{
    int16_t acc_raw[3];
    rt_err_t res;
    res = mpu6000_acc_read_raw(acc_raw);

    acc[0] = _accel_range_scale * acc_raw[0];
    acc[1] = _accel_range_scale * acc_raw[1];
    acc[2] = _accel_range_scale * acc_raw[2];

    mpu6000_rotate_to_frd(acc);

    return res;
}

static rt_err_t gyro_config(gyro_dev_t gyro, const struct gyro_configure* cfg)
{
    rt_err_t ret = RT_EOK;

    if (cfg == RT_NULL) {
        return RT_EINVAL;
    }

    ret |= _set_gyro_range(cfg->gyro_range_dps);

    ret |= _set_sample_rate(cfg->sample_rate_hz);

    ret |= _set_dlpf_filter(cfg->dlpf_freq_hz);

    gyro->config = *cfg;

    return ret;
}

static rt_err_t gyro_control(gyro_dev_t gyro, int cmd, void* arg)
{
    return RT_EOK;
}

static rt_size_t gyro_read(gyro_dev_t gyro, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == RT_NULL) {
        return 0;
    }

    if (mpu6000_gyr_read_rad(((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
}

const static struct gyro_ops _gyro_ops = {
    gyro_config,
    gyro_control,
    gyro_read,
};

static rt_err_t accel_config(accel_dev_t accel, const struct accel_configure* cfg)
{
    rt_err_t ret = RT_EOK;

    if (cfg == RT_NULL) {
        return RT_EINVAL;
    }

    ret |= _set_accel_range(cfg->acc_range_g);

    ret |= _set_sample_rate(cfg->sample_rate_hz);

    ret |= _set_dlpf_filter(cfg->dlpf_freq_hz);

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

    if (mpu6000_acc_read_m_s2(((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
}

const static struct accel_ops _accel_ops = {
    accel_config,
    accel_control,
    accel_read,
};

rt_err_t mpu6000_drv_init(const char* spi_device_name, const char* gyro_device_name, const char* accel_device_name)
{
    rt_err_t ret = RT_EOK;
    static struct accel_device accel_dev = {
        .ops = &_accel_ops,
        .config = ACCEL_CONFIG_DEFAULT,
        .bus_type = GYRO_SPI_BUS_TYPE
    };
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

    /* register accel hal device */
    ret |= hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL);

    return ret;
}
