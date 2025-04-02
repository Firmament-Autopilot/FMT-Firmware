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

#include "hal/barometer/barometer.h"
#include "hal/spi/spi.h"

#define DRV_DBG(...)               printf(__VA_ARGS__)

// #ifdef BIT
//     #undef BIT
// #endif
// #define BIT(_idx) (1 << _idx)

#define BMP581_ID                  0x50

#define BMP581_REG_CHIP_ID         0x01
#define BMP581_REG_REV_ID          0x02
#define BMP581_REG_CHIP_STATUS     0x11
#define BMP581_REG_DRIVE_CONFIG    0x13
#define BMP581_REG_INT_CONFIG      0x14
#define BMP581_REG_INT_SOURCE      0x15
#define BMP581_REG_FIFO_CONFIG     0x16
#define BMP581_REG_FIFO_COUNT      0x17
#define BMP581_REG_FIFO_SEL        0x18
#define BMP581_REG_TEMP_DATA_XLSB  0x1D
#define BMP581_REG_TEMP_DATA_LSB   0x1E
#define BMP581_REG_TEMP_DATA_MSB   0x1F
#define BMP581_REG_PRESS_DATA_XLSB 0x20
#define BMP581_REG_PRESS_DATA_LSB  0x21
#define BMP581_REG_PRESS_DATA_MSB  0x22
#define BMP581_REG_INT_STATUS      0x27
#define BMP581_REG_STATUS          0x28
#define BMP581_REG_FIFO_DATA       0x29
#define BMP581_REG_NVM_ADDR        0x2B
#define BMP581_REG_NVM_DATA_LSB    0x2C
#define BMP581_REG_NVM_DATA_MSB    0x2D
#define BMP581_REG_DSP_CONFIG      0x30
#define BMP581_REG_DSP_IIR         0x31
#define BMP581_REG_OOR_THR_P_LSB   0x32
#define BMP581_REG_OOR_THR_P_MSB   0x33
#define BMP581_REG_OOR_RANGE       0x34
#define BMP581_REG_OOR_CONFIG      0x35
#define BMP581_REG_OSR_CONFIG      0x36
#define BMP581_REG_ODR_CONFIG      0x37
#define BMP581_REG_OSR_EFF         0x38
#define BMP581_REG_CMD             0x7E

typedef struct {
    uint8_t setbits;
    uint8_t clearbits;
} reg_val_t;

static rt_device_t baro_spi_dev;

static rt_err_t modify_reg(rt_device_t spi_device, rt_uint8_t reg, reg_val_t reg_val)
{
    uint8_t value;

    RT_TRY(spi_read_reg8(spi_device, reg, &value));

    value &= ~reg_val.clearbits;
    value |= reg_val.setbits;

    RT_TRY(spi_write_reg8(spi_device, reg, value));

    return RT_EOK;
}

static rt_err_t write_checked_reg(rt_device_t spi_device, rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t r_val;

    RT_TRY(spi_write_reg8(spi_device, reg, val));
    RT_TRY(spi_read_reg8(spi_device, reg, &r_val));

    return (r_val == val) ? RT_EOK : RT_ERROR;
}

static rt_err_t lowlevel_init(void)
{
    uint8_t value;
    // uint8_t reg_val;

    RT_TRY(rt_device_open(baro_spi_dev, RT_DEVICE_OFLAG_RDWR));

    /* check chip id, a dummy read switch to SPI mode */
    RT_TRY(spi_read_reg8(baro_spi_dev, BMP581_REG_CHIP_ID, &value));
    RT_TRY(spi_read_reg8(baro_spi_dev, BMP581_REG_CHIP_ID, &value));
    if (value != BMP581_ID) {
        DRV_DBG("bmp581 wrong chip id:0x%x\n", value);
        return RT_ERROR;
    }

    RT_TRY(spi_read_reg8(baro_spi_dev, BMP581_REG_STATUS, &value));
    if ((value & 0b10) == 0 || (value & 0b100) == 1) {
        return RT_ERROR;
    }

    RT_TRY(spi_read_reg8(baro_spi_dev, BMP581_REG_INT_STATUS, &value));
    if ((value & 0x10) == 0) {
        return RT_ERROR;
    }

    // Standby mode
    RT_TRY(write_checked_reg(baro_spi_dev, BMP581_REG_ODR_CONFIG, 0));

    // Press EN | osr_p 64X | osr_t 4X
    RT_TRY(write_checked_reg(baro_spi_dev, BMP581_REG_OSR_CONFIG, 0b01110010));

    // ORD 50Hz | Normal Mode
    RT_TRY(write_checked_reg(baro_spi_dev, BMP581_REG_ODR_CONFIG, 0b0111101));

    return RT_EOK;
}

static rt_err_t baro_control(baro_dev_t baro, int cmd, void* arg)
{
    switch (cmd) {
    case BARO_CMD_CHECK_READY: {
        DEFINE_TIMETAG(baro_interval, 10);
        *(uint8_t*)arg = check_timetag(TIMETAG(baro_interval));
    } break;
    default:
        break;
    }

    return RT_EOK;
}

static rt_size_t baro_read(baro_dev_t baro, baro_report_t* report)
{
    rt_size_t size = 0;
    uint8_t buf[6];

    if (spi_read_multi_reg8(baro_spi_dev, BMP581_REG_TEMP_DATA_XLSB, buf, sizeof(buf)) != RT_EOK) {
        return 0;
    }

    if (buf[0] != 0x7f || buf[1] != 0x7f || buf[2] != 0x7f || buf[3] != 0x7f || buf[4] != 0x7f || buf[5] != 0x7f) {
        size = sizeof(baro_report_t);
    }

    return size;
}

static struct baro_ops _baro_ops = {
    .baro_control = baro_control,
    .baro_read = baro_read
};

rt_err_t drv_bmp581_init(const char* spi_device_name, const char* baro_device_name)
{
    static struct baro_device baro_dev = {
        .ops = &_baro_ops
    };

    baro_spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(baro_spi_dev != NULL);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)baro_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* device low-level initialization */
    RT_TRY(lowlevel_init());
    /* register barometer device */
    RT_TRY(hal_baro_register(&baro_dev, baro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}