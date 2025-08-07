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

#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_dev.h"
#include "hal/mag/mag.h"

#define DRV_DBG(...)     printf(__VA_ARGS__)

#define REG_DATA_OUT_X_L 0x00
#define REG_DATA_OUT_X_H 0x01
#define REG_DATA_OUT_Y_L 0x02
#define REG_DATA_OUT_Y_H 0x03
#define REG_DATA_OUT_Z_L 0x04
#define REG_DATA_OUT_Z_H 0x05
#define REG_STATUS       0x06
#define REG_TEMP_DATA_L  0x07
#define REG_TEMP_DATA_H  0x08
#define REG_CONTROL1     0x09
#define REG_CONTROL2     0x0A
#define REG_PERIOD       0x0B
#define REG_CHIP_ID      0x0D

#define CHIP_ID          0xFF

#define QMC5883L_CONFIG_DEFAULT                    \
    {                                              \
        100,               /* 100hz sample rate */ \
            50,            /* 64 OSR */            \
            MAG_RANGE_8GA, /* +-8guess */          \
    }

static rt_device_t i2c_dev;
static float range_scale = 1.0 / 3000;

/* Re-implement this function to define customized rotation */
RT_WEAK void qmc5883l_rotate_to_frd(float* data, uint8_t dev_id)
{
    /* do nothing */
    (void)data;
    (void)dev_id;
}

static rt_err_t probe(void)
{
    uint8_t chip_id = 0;

    RT_TRY(i2c_read_reg(i2c_dev, REG_CHIP_ID, &chip_id));

    if (chip_id != CHIP_ID) {
        DRV_DBG("qmc5883l id unmatched: 0x%x\n", chip_id);
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t qmc5883l_init(void)
{
    /* check if device connected */
    RT_TRY(probe());

    RT_CHECK(i2c_write_reg(i2c_dev, REG_CONTROL2, 0x80)); /* software reset */

    systime_mdelay(2);
    
    RT_CHECK(i2c_write_reg(i2c_dev, REG_PERIOD, 0x01)); /* set to continious mode */

    systime_mdelay(2);

    /* configure control register 3 */
    RT_CHECK(i2c_write_reg(i2c_dev, REG_CONTROL1, 0xD9)); /* 64 OSR, 8 Gauss, 100 Hz, Continue mode */

    return RT_EOK;
}

static rt_err_t mag_measure(mag_dev_t mag_dev, float mag[3])
{
    int16_t raw[3];
    uint8_t buf[6];

    RT_TRY(i2c_read_regs(i2c_dev, REG_DATA_OUT_X_L, buf, sizeof(buf)));

    raw[0] = (int16_t)(((uint16_t)buf[1] << 8) | buf[0]);
    raw[1] = (int16_t)(((uint16_t)buf[3] << 8) | buf[2]);
    raw[2] = (int16_t)(((uint16_t)buf[5] << 8) | buf[3]);
    mag[0] = range_scale * raw[0];
    mag[1] = range_scale * raw[1];
    mag[2] = range_scale * raw[2];

    qmc5883l_rotate_to_frd(mag, (uint32_t)mag_dev->parent.user_data & 0x7F);

    return RT_EOK;
}

static rt_size_t qmc5883l_read(mag_dev_t mag, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == RT_NULL) {
        return 0;
    }

    if (mag_measure(mag, ((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
}

const static struct mag_ops __mag_ops = {
    .mag_config = NULL,
    .mag_control = NULL,
    .mag_read = qmc5883l_read,
};

rt_err_t drv_qmc5883l_init(const char* i2c_device_name, const char* mag_device_name, uint32_t dev_flags)
{
    static struct mag_device mag_dev = {
        .ops = &__mag_ops,
        .config = QMC5883L_CONFIG_DEFAULT,
        .bus_type = MAG_I2C_BUS_TYPE
    };

    i2c_dev = rt_device_find(i2c_device_name);

    RT_ASSERT(i2c_dev != NULL);

    RT_CHECK(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(qmc5883l_init());

    RT_CHECK(hal_mag_register(&mag_dev, mag_device_name, RT_DEVICE_FLAG_RDWR, (void*)dev_flags));

    return RT_EOK;
}
