/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

#include "driver/barometer/spl06.h"
#include "hal/barometer/barometer.h"
#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_dev.h"
#include "hal/spi/spi.h"
#include "module/workqueue/workqueue_manager.h"

#define DRV_DBG(...) printf(__VA_ARGS__)

#ifdef BIT
    #undef BIT
#endif
#define BIT(_idx)               (1 << _idx)

#define ICP201XX_ID             0x63

#define CONVERSION_INTERVAL     25000

#define REG_EMPTY               0x00
#define REG_TRIM1_MSB           0x05
#define REG_TRIM2_LSB           0x06
#define REG_TRIM2_MSB           0x07
#define REG_DEVICE_ID           0x0C
#define REG_OTP_MTP_OTP_CFG1    0xAC
#define REG_OTP_MTP_MR_LSB      0xAD
#define REG_OTP_MTP_MR_MSB      0xAE
#define REG_OTP_MTP_MRA_LSB     0xAF
#define REG_OTP_MTP_MRA_MSB     0xB0
#define REG_OTP_MTP_MRB_LSB     0xB1
#define REG_OTP_MTP_MRB_MSB     0xB2
#define REG_OTP_MTP_OTP_ADDR    0xB5
#define REG_OTP_MTP_OTP_CMD     0xB6
#define REG_OTP_MTP_RD_DATA     0xB8
#define REG_OTP_MTP_OTP_STATUS  0xB9
#define REG_OTP_DEBUG2          0xBC
#define REG_MASTER_LOCK         0xBE
#define REG_OTP_MTP_OTP_STATUS2 0xBF
#define REG_MODE_SELECT         0xC0
#define REG_INTERRUPT_STATUS    0xC1
#define REG_INTERRUPT_MASK      0xC2
#define REG_FIFO_CONFIG         0xC3
#define REG_FIFO_FILL           0xC4
#define REG_SPI_MODE            0xC5
#define REG_PRESS_ABS_LSB       0xC7
#define REG_PRESS_ABS_MSB       0xC8
#define REG_PRESS_DELTA_LSB     0xC9
#define REG_PRESS_DELTA_MSB     0xCA
#define REG_DEVICE_STATUS       0xCD
#define REG_I3C_INFO            0xCE
#define REG_VERSION             0xD3
#define REG_FIFO_BASE           0xFA

enum op_mode {
    OP_MODE0 = 0, /* Mode 0: Bw:6.25 Hz ODR: 25Hz */
    OP_MODE1,     /* Mode 1: Bw:30 Hz ODR: 120Hz */
    OP_MODE2,     /* Mode 2: Bw:10 Hz ODR: 40Hz */
    OP_MODE3,     /* Mode 3: Bw:0.5 Hz ODR: 2Hz */
    OP_MODE4,     /* Mode 4: User configurable Mode */
};

enum fifo_readout_mode {
    FIFO_READOUT_MODE_PRES_TEMP = 0, /* Pressure and temperature as pair and address wraps to the start address of the Pressure value ( pressure first ) */
    FIFO_READOUT_MODE_TEMP_ONLY = 1, /* Temperature only reporting */
    FIFO_READOUT_MODE_TEMP_PRES = 2, /* Pressure and temperature as pair and address wraps to the start address of the Temperature value ( Temperature first ) */
    FIFO_READOUT_MODE_PRES_ONLY = 3  /* Pressure only reporting */
};

enum power_mode {
    POWER_MODE_NORMAL = 0, /* Normal Mode: Device is in standby and goes to active mode during the execution of a measurement */
    POWER_MODE_ACTIVE = 1  /* Active Mode: Power on DVDD and enable the high frequency clock */
};

enum meas_mode {
    MEAS_MODE_FORCED_TRIGGER = 0, /* Force trigger mode based on icp201xx_forced_meas_trigger_t **/
    MEAS_MODE_CONTINUOUS = 1      /* Continuous measurements based on selected mode ODR settings*/
};

enum force_meas_trigger {
    FORCE_MEAS_STANDBY = 0,           /* Stay in Stand by */
    FORCE_MEAS_TRIGGER_FORCE_MEAS = 1 /* Trigger for forced measurements */
};

static rt_device_t dev;

static rt_err_t mode_select(uint8_t mode)
{
    uint8_t mode_sync_status = 0;

    do {
        i2c_read_reg(dev, REG_DEVICE_STATUS, &mode_sync_status);

        if (mode_sync_status & 0x01) {
            break;
        }
        systime_mdelay(1);
    } while (1);

    RT_TRY(i2c_write_reg(dev, REG_MODE_SELECT, mode));

    return RT_EOK;
}

static rt_err_t flush_fifo(void)
{
    uint8_t reg_value;

    RT_TRY(i2c_read_reg(dev, REG_FIFO_FILL, &reg_value));

    reg_value |= 0x80;

    RT_TRY(i2c_write_reg(dev, REG_FIFO_FILL, reg_value));

    return RT_EOK;
}

static rt_err_t soft_reset(void)
{
    /* Stop the measurement */
    RT_TRY(mode_select(0x00));
    systime_mdelay(2);

    /* Flush FIFO */
    RT_TRY(flush_fifo());

    /* Mask all interrupts */
    RT_TRY(i2c_write_reg(dev, REG_FIFO_CONFIG, 0x00));
    RT_TRY(i2c_write_reg(dev, REG_INTERRUPT_MASK, 0xFF));

    return RT_EOK;
}

static rt_err_t configure(void)
{
    uint8_t reg_value = 0;

    /* Initiate Triggered Operation: Stay in Standby mode */
    reg_value |= (reg_value & (~0x10)) | ((uint8_t)FORCE_MEAS_STANDBY << 4);

    /* Power Mode Selection: Normal Mode */
    reg_value |= (reg_value & (~0x04)) | ((uint8_t)POWER_MODE_NORMAL << 2);

    /* FIFO Readout Mode Selection: Pressure first. */
    reg_value |= (reg_value & (~0x03)) | ((uint8_t)(FIFO_READOUT_MODE_PRES_TEMP));

    /* Measurement Configuration: Mode1*/
    reg_value |= (reg_value & (~0xE0)) | (((uint8_t)OP_MODE2) << 5);

    /* Measurement Mode Selection: Continuous Measurements (duty cycled) */
    reg_value |= (reg_value & (~0x08)) | ((uint8_t)MEAS_MODE_CONTINUOUS << 3);

    return mode_select(reg_value);
}

static void wait_read(void)
{
    /*
     * If FIR filter is enabled, it will cause a settling effect on the first 14 pressure values.
     * Therefore the first 14 pressure output values are discarded.
     **/
    uint8_t fifo_packets = 0;
    uint8_t fifo_packets_to_skip = 14;

    do {
        systime_mdelay(10);
        i2c_read_reg(dev, REG_FIFO_FILL, &fifo_packets);
        fifo_packets = (uint8_t)(fifo_packets & 0x1F);
    } while (fifo_packets >= fifo_packets_to_skip);

    flush_fifo();
    fifo_packets = 0;

    do {
        systime_mdelay(10);
        i2c_read_reg(dev, REG_FIFO_FILL, &fifo_packets);
        fifo_packets = (uint8_t)(fifo_packets & 0x1F);
    } while (fifo_packets == 0);
}

static rt_err_t measure(baro_report_t* report)
{
    uint8_t fifo_data[96] = { 0 };
    uint8_t fifo_packets = 0;
    int32_t data_temp = 0;
    int32_t data_press = 0;
    float pressure = 0;
    float temperature = 0;

    if (i2c_read_reg(dev, REG_FIFO_FILL, &fifo_packets) == RT_EOK) {
        fifo_packets = (uint8_t)(fifo_packets & 0x1F);
        if (fifo_packets > 16) {
            flush_fifo();
            return RT_ERROR;
        }
        if (fifo_packets > 0 && fifo_packets <= 16 && i2c_read_regs(dev, REG_FIFO_BASE, fifo_data, fifo_packets * 2 * 3) == RT_EOK) {
            uint8_t offset = 0;

            for (uint8_t i = 0; i < fifo_packets; i++) {
                data_press = (int32_t)(((fifo_data[offset + 2] & 0x0f) << 16) | (fifo_data[offset + 1] << 8) | fifo_data[offset]);
                if (data_press & 0x080000) {
                    data_press |= 0xFFF00000;
                }
                /* P = (POUT/2^17)*40kPa + 70kPa */
                pressure += ((float)(data_press)*40 / 131072) + 70;
                offset += 3;

                data_temp = (int32_t)(((fifo_data[offset + 2] & 0x0f) << 16) | (fifo_data[offset + 1] << 8) | fifo_data[offset]);
                if (data_temp & 0x080000) {
                    data_temp |= 0xFFF00000;
                }
                /* T = (TOUT/2^18)*65C + 25C */
                temperature += ((float)(data_temp)*65 / 262144) + 25;
                offset += 3;
            }

            report->pressure_Pa = pressure * 1000 / fifo_packets;
            report->temperature_deg = temperature / fifo_packets;
            report->altitude_m = 44330.0f * (1.0f - powf(report->pressure_Pa / 101325.0f, 1.0f / 5.255f));
            report->timestamp_ms = systime_now_ms();

            // PERIOD_EXECUTE(test, 500, printf("press:%f temp:%f alt:%f\n", report->pressure_Pa, report->temperature_deg, report->altitude_m););

            return RT_EOK;
        }
    }

    return RT_ERROR;
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

    if (measure(report) == RT_EOK) {
        size = sizeof(baro_report_t);
    }

    return size;
}

static struct baro_ops _baro_ops = {
    .baro_control = baro_control,
    .baro_read = baro_read
};

static rt_err_t lowlevel_init(void)
{
    uint8_t id;
    uint8_t ver;

    RT_TRY(i2c_read_reg(dev, REG_DEVICE_ID, &id));
    if (id != ICP201XX_ID) {
        DRV_DBG("icp201xx id unmatched!\n", id);
        return RT_ERROR;
    }

    RT_TRY(i2c_read_reg(dev, REG_VERSION, &ver));
    if (ver != 0xB2) {
        return RT_ERROR;
    }

    RT_TRY(soft_reset());

    RT_TRY(configure());

    wait_read();

    return RT_EOK;
}

static struct baro_device baro_dev = {
    .ops = &_baro_ops
};

rt_err_t drv_icp201xx_init(const char* device_name, const char* baro_device_name)
{
    dev = rt_device_find(device_name);
    RT_ASSERT(dev != NULL);

    RT_CHECK(rt_device_open(dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(lowlevel_init());

    /* register barometer device */
    RT_TRY(hal_baro_register(&baro_dev, baro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}