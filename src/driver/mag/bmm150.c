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

#include "driver/mag/bmm150.h"
#include "hal/mag/mag.h"
#include "hal/spi/spi.h"

#define DRV_DBG(...) printf(__VA_ARGS__)

#ifdef BIT
    #undef BIT
#endif

#define BIT(_idx) (1 << _idx)
#define REG_VAL(_setbits, _clearbits) \
    (reg_val_t) { .setbits = (_setbits), .clearbits = (_clearbits) }

#define BMM150_CHIP_ID       0x40 // magnetometer chip identification number
#define BMM150_DATAX_LSB     0x42 // 5-bit LSB of x-axis magnetic field data
#define BMM150_DATAX_MSB     0x43 // 8-bit MSB of x-axis magnetic field data
#define BMM150_DATAY_LSB     0x44 // 5-bit LSB of y-axis magnetic field data
#define BMM150_DATAY_MSB     0x45 // 8-bit MSB of y-axis magnetic field data
#define BMM150_DATAZ_LSB     0x46 // 7-bit LSB of z-axis magnetic field data
#define BMM150_DATAZ_MSB     0x47 // 8-bit MSB of z-axis magnetic field data
#define BMM150_RHALL_LSB     0x48 // 6-bit LSB of hall resistance
#define BMM150_RHALL_MSB     0x49 // 8-bit MSB of hall resistance
#define BMM150_STATUS        0x4A // Status register
#define BMM150_POWER_CONTROL 0x4B // power control, soft reset and interface SPI mode selection
#define BMM150_OP_MODE       0x4C // operation mode, output data rate and self-test
#define BMM150_REPXY         0x51 // number of repetitions for x/y-axis
#define BMM150_REPZ          0x52 // number of repetitions for z-axis
#define BMM150_DIG_X1        0x5D
#define BMM150_DIG_Z4_LSB    0x62
#define BMM150_DIG_Z2_LSB    0x68

/* Trim Extended Registers */
#define BMM150_DIG_X1       0x5D
#define BMM150_DIG_Y1       0x5E
#define BMM150_DIG_Z4_LSB   0x62
#define BMM150_DIG_Z4_MSB   0x63
#define BMM150_DIG_X2       0x64
#define BMM150_DIG_Y2       0x65
#define BMM150_DIG_Z2_LSB   0x68
#define BMM150_DIG_Z2_MSB   0x69
#define BMM150_DIG_Z1_LSB   0x6A
#define BMM150_DIG_Z1_MSB   0x6B
#define BMM150_DIG_XYZ1_LSB 0x6C
#define BMM150_DIG_XYZ1_MSB 0x6D
#define BMM150_DIG_Z3_LSB   0x6E
#define BMM150_DIG_Z3_MSB   0x6F
#define BMM150_DIG_XY2      0x70
#define BMM150_DIG_XY1      0x71

/* Data rate value definitions */
#define BMM150_DATA_RATE_10HZ REG_VAL(0, BIT(3) | BIT(4) | BIT(5))
#define BMM150_DATA_RATE_02HZ REG_VAL(BIT(3), BIT(4) | BIT(5))
#define BMM150_DATA_RATE_06HZ REG_VAL(BIT(4), BIT(3) | BIT(5))
#define BMM150_DATA_RATE_08HZ REG_VAL(BIT(3) | BIT(4), BIT(5))
#define BMM150_DATA_RATE_15HZ REG_VAL(BIT(5), BIT(3) | BIT(4))
#define BMM150_DATA_RATE_20HZ REG_VAL(BIT(3) | BIT(5), BIT(4))
#define BMM150_DATA_RATE_25HZ REG_VAL(BIT(4) | BIT(5), BIT(3))
#define BMM150_DATA_RATE_30HZ REG_VAL(BIT(3) | BIT(4) | BIT(5), 0)

/* Power modes value definitions */
#define BMM150_NORMAL_MODE REG_VAL(0, BIT(1) | BIT(2))
#define BMM150_FORCED_MODE REG_VAL(BIT(1), BIT(2))
#define BMM150_SLEEP_MODE  REG_VAL(BIT(1) | BIT(2), 0)

/* compensated output value returned if sensor had overflow */
#define BMM150_OVERFLOW_OUTPUT       -32768
#define BMM150_OVERFLOW_OUTPUT_S32   ((int32_t)(-2147483647 - 1))
#define BMM150_OVERFLOW_OUTPUT_FLOAT 0.0f
#define BMM150_FLIP_OVERFLOW_ADCVAL  -4096
#define BMM150_HALL_OVERFLOW_ADCVAL  -16384

typedef struct {
    uint8_t setbits;
    uint8_t clearbits;
} reg_val_t;

static rt_device_t mag_spi_dev;

static int8_t _dig_x1;     /**< trim x1 data */
static int8_t _dig_y1;     /**< trim y1 data */
static int8_t _dig_x2;     /**< trim x2 data */
static int8_t _dig_y2;     /**< trim y2 data */
static uint16_t _dig_z1;   /**< trim z1 data */
static int16_t _dig_z2;    /**< trim z2 data */
static int16_t _dig_z3;    /**< trim z3 data */
static int16_t _dig_z4;    /**< trim z4 data */
static uint8_t _dig_xy1;   /**< trim xy1 data */
static int8_t _dig_xy2;    /**< trim xy2 data */
static uint16_t _dig_xyz1; /**< trim xyz1 data */

/* Re-implement this function to define customized rotation */
RT_WEAK void bmm150_rotate_to_frd(float* data, uint32_t dev_id)
{
    /* do nothing */
    (void)data;
    (void)dev_id;
}

static rt_err_t write_checked_reg(rt_device_t spi_device, rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t r_val;

    RT_TRY(spi_write_reg8(spi_device, reg, val));

    /* if read immediately after write would result in read failed value, so insert a delay here */
    systime_udelay(100);

    RT_TRY(spi_read_reg8(spi_device, reg, &r_val));

    return (r_val == val) ? RT_EOK : RT_ERROR;
}

static rt_err_t modify_reg(rt_device_t spi_device, rt_uint8_t reg, reg_val_t reg_val)
{
    uint8_t value;

    RT_TRY(spi_read_reg8(spi_device, reg, &value));

    value &= ~reg_val.clearbits;
    value |= reg_val.setbits;

    RT_TRY(write_checked_reg(spi_device, reg, value));

    return RT_EOK;
}

static rt_err_t set_date_rate(reg_val_t data_rate)
{
    return modify_reg(mag_spi_dev, BMM150_OP_MODE, data_rate);
}

static rt_err_t mag_measure(float mag[3])
{
    rt_err_t res = RT_EOK;
    uint8_t mag_data[8];
    uint16_t lsb, msb, msblsb, rhall;
    int16_t mag_raw[3];
    float x, y, z;

    /* Array holding the mag XYZ and R data
	mag_data[0] - X LSB
	mag_data[1] - X MSB
	mag_data[2] - Y LSB
	mag_data[3] - Y MSB
	mag_data[4] - Z LSB
	mag_data[5] - Z MSB
    mag_data[6] - R LSB
	mag_data[7] - R MSB
	*/
    res = spi_read_multi_reg8(mag_spi_dev, BMM150_DATAX_LSB, mag_data, sizeof(mag_data));
    if (res != RT_EOK) {
        goto exit;
    }

    if ((mag_data[6] & 0x01) == 0) {
        /* Data is not ready, do not trigger the next measurement */
        return RT_EIO;
    }

    /* Extract X axis data */
    lsb = ((mag_data[0] & 0xF8));
    msb = ((uint16_t)(mag_data[1]) << 8);
    msblsb = (msb | lsb);
    mag_raw[0] = (int16_t)msblsb / 8;

    /* Extract Y axis data */
    lsb = ((mag_data[2] & 0xF8));
    msb = (((uint16_t)(mag_data[3])) << 8);
    msblsb = (msb | lsb);
    mag_raw[1] = (int16_t)msblsb / 8;

    /* Extract Z axis data */
    lsb = ((mag_data[4] & 0xFE));
    msb = (((uint16_t)(mag_data[5])) << 8);
    msblsb = (msb | lsb);
    mag_raw[2] = (int16_t)msblsb / 2;

    /* Extract Resistance data */
    lsb = ((mag_data[6] & 0xFC));
    msb = (((uint16_t)mag_data[7]) << 8);
    msblsb = (msb | lsb);
    rhall = (uint16_t)msblsb / 4;

    /* Compensation for X axis */
    if (mag_raw[0] != BMM150_FLIP_OVERFLOW_ADCVAL) {
        /* no overflow */
        if ((rhall != 0) && (_dig_xyz1 != 0)) {
            /* this is not documented, but derived from https://github.com/BoschSensortec/BMM150-Sensor-API/blob/master/bmm150.c */
            x = ((_dig_xyz1 * 16384.0f / rhall) - 16384.0f);
            x = (((mag_raw[0] * ((((_dig_xy2 * ((float)(x * x / 268435456.0f)) + x * _dig_xy1 / 16384.0f)) + 256.0f) * (_dig_x2 + 160.0f))) / 8192.0f) + (_dig_x1 * 8.0f)) / 16.0f;

        } else {
            x = BMM150_OVERFLOW_OUTPUT_FLOAT;
        }

    } else {
        x = BMM150_OVERFLOW_OUTPUT_FLOAT;
    }

    /* Compensation for Y axis */
    if (mag_raw[1] != BMM150_FLIP_OVERFLOW_ADCVAL) {
        /* no overflow */
        if ((rhall != 0) && (_dig_xyz1 != 0)) {

            y = ((((float)_dig_xyz1) * 16384.0f / rhall) - 16384.0f);
            y = (((mag_raw[1] * ((((_dig_xy2 * (y * y / 268435456.0f) + y * _dig_xy1 / 16384.0f)) + 256.0f) * (_dig_y2 + 160.0f))) / 8192.0f) + (_dig_y1 * 8.0f)) / 16.0f;

        } else {
            y = BMM150_OVERFLOW_OUTPUT_FLOAT;
        }

    } else {
        /* overflow, set output to 0.0f */
        y = BMM150_OVERFLOW_OUTPUT_FLOAT;
    }

    /* Compensation for Z axis */
    if (mag_raw[2] != BMM150_HALL_OVERFLOW_ADCVAL) {
        /* no overflow */
        if ((_dig_z2 != 0) && (_dig_z1 != 0) && (_dig_xyz1 != 0) && (rhall != 0)) {
            z = ((((mag_raw[2] - _dig_z4) * 131072.0f) - (_dig_z3 * (rhall - _dig_xyz1))) / ((_dig_z2 + _dig_z1 * rhall / 32768.0f) * 4.0f)) / 16.0f;
        }

    } else {
        /* overflow, set output to 0.0f */
        z = BMM150_OVERFLOW_OUTPUT_FLOAT;
    }

    /* uT to gauss */
    mag[0] = x * 0.01f;
    mag[1] = y * 0.01f;
    mag[2] = z * 0.01f;

    /* rotate to ned */
    bmm150_rotate_to_frd(mag, 0);

exit:
    /* trigger the next measurement */
    RT_TRY(modify_reg(mag_spi_dev, BMM150_OP_MODE, BMM150_FORCED_MODE));

    return res;
}

static rt_err_t init_trim_registers(void)
{
    uint8_t data[2] = { 0 };
    uint16_t msb, lsb, msblsb;

    RT_TRY(spi_read_reg8(mag_spi_dev, BMM150_DIG_X1, (uint8_t*)&_dig_x1));
    RT_TRY(spi_read_reg8(mag_spi_dev, BMM150_DIG_Y1, (uint8_t*)&_dig_y1));
    RT_TRY(spi_read_reg8(mag_spi_dev, BMM150_DIG_X2, (uint8_t*)&_dig_x2));
    RT_TRY(spi_read_reg8(mag_spi_dev, BMM150_DIG_Y2, (uint8_t*)&_dig_y2));
    RT_TRY(spi_read_reg8(mag_spi_dev, BMM150_DIG_XY1, (uint8_t*)&_dig_xy1));
    RT_TRY(spi_read_reg8(mag_spi_dev, BMM150_DIG_XY2, (uint8_t*)&_dig_xy2));

    RT_TRY(spi_read_multi_reg8(mag_spi_dev, BMM150_DIG_Z1_LSB, data, 2));
    lsb = data[0];
    msb = ((uint16_t)data[1]) << 8;
    msblsb = (msb | lsb);
    _dig_z1 = (uint16_t)msblsb;

    RT_TRY(spi_read_multi_reg8(mag_spi_dev, BMM150_DIG_Z2_LSB, data, 2));
    lsb = data[0];
    msb = ((uint16_t)data[1]) << 8;
    msblsb = (msb | lsb);
    _dig_z2 = (int16_t)msblsb;

    RT_TRY(spi_read_multi_reg8(mag_spi_dev, BMM150_DIG_Z3_LSB, data, 2));
    lsb = data[0];
    msb = ((uint16_t)data[1]) << 8;
    msblsb = (msb | lsb);
    _dig_z3 = (int16_t)msblsb;

    RT_TRY(spi_read_multi_reg8(mag_spi_dev, BMM150_DIG_Z4_LSB, data, 2));
    lsb = data[0];
    msb = ((uint16_t)data[1]) << 8;
    msblsb = (msb | lsb);
    _dig_z4 = (int16_t)msblsb;

    RT_TRY(spi_read_multi_reg8(mag_spi_dev, BMM150_DIG_XYZ1_LSB, data, 2));
    lsb = data[0];
    msb = ((uint16_t)(data[1] & 0x7F) << 8);
    msblsb = (msb | lsb);
    _dig_xyz1 = (uint16_t)msblsb;

    return RT_EOK;
}

static rt_err_t lowlevel_init(void)
{
    uint8_t mag_id;

    /* init spi bus */
    RT_TRY(rt_device_open(mag_spi_dev, RT_DEVICE_OFLAG_RDWR));
    /* power on and reset */
    RT_TRY(spi_write_reg8(mag_spi_dev, BMM150_POWER_CONTROL, BIT(0) | BIT(1) | BIT(7)));
    /* wait the chip power on */
    systime_mdelay(3);

    RT_TRY(spi_read_reg8(mag_spi_dev, BMM150_CHIP_ID, &mag_id));
    if (mag_id != 0x32) {
        DRV_DBG("bmm150 wrong chip id:0x%x\n", mag_id);
        return RT_ERROR;
    }

    RT_TRY(init_trim_registers());

    /* Regular preset, RepXY:9 RepZ:15, Max 100Hz ODR in forced mode  */
    RT_TRY(write_checked_reg(mag_spi_dev, BMM150_REPXY, 4));
    RT_TRY(write_checked_reg(mag_spi_dev, BMM150_REPZ, 14));

    /* set default data rate in normal mode */
    RT_TRY(set_date_rate(BMM150_DATA_RATE_30HZ));

    /* trigger the first measurement */
    RT_TRY(modify_reg(mag_spi_dev, BMM150_OP_MODE, BMM150_FORCED_MODE));

    return RT_EOK;
}

static rt_size_t bmm150_read(mag_dev_t mag, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == RT_NULL) {
        return 0;
    }

    if (mag_measure(((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
}

const static struct mag_ops __mag_ops = {
    NULL,
    NULL,
    bmm150_read,
};

rt_err_t drv_bmm150_init(const char* spi_device_name, const char* mag_device_name)
{
    static struct mag_device mag_dev = {
        .ops = &__mag_ops,
        .config = { 0 },
        .bus_type = MAG_SPI_BUS_TYPE
    };

    mag_spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(mag_spi_dev != NULL);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)mag_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    RT_TRY(lowlevel_init());

    RT_TRY(hal_mag_register(&mag_dev, mag_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}
