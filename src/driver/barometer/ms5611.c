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
#include <math.h>

#include "driver/barometer/ms5611.h"
#include "hal/barometer/barometer.h"
#include "hal/spi/spi.h"
#include "module/math/conversion.h"
#include "module/workqueue/workqueue_manager.h"

#define DRV_DBG(...) printf(__VA_ARGS__)
#define POW2(_x)     ((_x) * (_x))

/* SPI protocol address bits */
#define DIR_READ  (1 << 7)
#define DIR_WRITE (0 << 7)

#define ADDR_RESET_CMD  0x1E /* write to this address to reset chip */
#define ADDR_ADC        0x00 /* address of 3 bytes / 32bit pressure data */
#define ADDR_PROM_SETUP 0xA0 /* address of 8x 2 bytes factory and calibration data */
#define ADDR_PROM_C1    0xA2 /* address of 6x 2 bytes calibration data */
#define ADDR_PROM_C2    0xA4
#define ADDR_PROM_C3    0xA6
#define ADDR_PROM_C4    0xA8
#define ADDR_PROM_C5    0xAA
#define ADDR_PROM_C6    0xAC
#define ADDR_PROM_CRC   0xAE

#define BARO_OSR_256  0
#define BARO_OSR_512  1
#define BARO_OSR_1024 2
#define BARO_OSR_2048 3
#define BARO_OSR_4096 4

#define DEFAULT_OSR BARO_OSR_2048

static uint8_t CMD_CONVERT_D1_ADDR[5] = {
    0x40, // OSR=256
    0x42, // OSR=512
    0x44, // OSR=1024
    0x46, // OSR=2048
    0x48  // OSR=4096
};

static uint8_t CMD_CONVERT_D2_ADDR[5] = {
    0x50, // OSR=256
    0x52, // OSR=512
    0x54, // OSR=1024
    0x56, // OSR=2048
    0x58  // OSR=4096
};

static uint8_t CONV_TIME_INTERVAL[5] = {
    1, // OSR=256
    2, // OSR=512
    3, // OSR=1024
    5, // OSR=2048
    10 // OSR=4096
};

typedef struct {
    uint16_t factory_data;
    uint16_t c1;
    uint16_t c2;
    uint16_t c3;
    uint16_t c4;
    uint16_t c5;
    uint16_t c6;
    uint16_t crc;
} ms5611_prom_t;

/* ms5611 report read state */
enum {
    S_CONV_1 = 0,
    S_RAW_PRESS,
    S_CONV_2,
    S_RAW_TEMP,
    S_COLLECT_REPORT
};

static rt_device_t spi_device;
uint32_t _raw_temperature, _raw_pressure;
static ms5611_prom_t _prom;
static uint8_t _ms5611_state;
static baro_report_t _baro_report;
static uint8_t _updated = 0;

static rt_err_t write_cmd(rt_uint8_t cmd)
{
    rt_uint8_t send_buffer;
    rt_size_t w_byte;

    send_buffer = DIR_WRITE | cmd;
    w_byte = rt_device_write(spi_device, 0, &send_buffer, sizeof(send_buffer));

    return w_byte == sizeof(send_buffer) ? RT_EOK : RT_ERROR;
}

static rt_err_t read_adc(uint32_t* buff)
{
    rt_uint8_t send_val;
    rt_err_t res;

    send_val = ADDR_ADC;

    res = rt_spi_send_then_recv((struct rt_spi_device*)spi_device, (void*)&send_val, 1, (void*)buff, 3);
    //big-endian to little-endian
    Msb2Lsb((uint8_t*)buff, 3);

    return res;
}

static rt_err_t read_prom_reg(rt_uint8_t cmd, uint16_t* buff)
{
    rt_uint8_t send_val;
    rt_err_t res;

    send_val = DIR_READ | cmd;

    res = rt_spi_send_then_recv((struct rt_spi_device*)spi_device, (void*)&send_val, 1, (void*)buff, 2);
    //big-endian to little-endian
    Msb2Lsb((uint8_t*)buff, 2);

    return res;
}

static rt_bool_t crc_check(uint16_t* n_prom)
{
    int16_t cnt;
    uint16_t n_rem;
    uint16_t crc_read;
    uint8_t n_bit;

    n_rem = 0x00;

    /* save the read crc */
    crc_read = n_prom[7];

    /* remove CRC byte */
    n_prom[7] = (0xFF00 & (n_prom[7]));

    for (cnt = 0; cnt < 16; cnt++) {
        /* uneven bytes */
        if (cnt & 1) {
            n_rem ^= (uint8_t)((n_prom[cnt >> 1]) & 0x00FF);

        } else {
            n_rem ^= (uint8_t)(n_prom[cnt >> 1] >> 8);
        }

        for (n_bit = 8; n_bit > 0; n_bit--) {
            if (n_rem & 0x8000) {
                n_rem = (n_rem << 1) ^ 0x3000;

            } else {
                n_rem = (n_rem << 1);
            }
        }
    }

    /* final 4 bit remainder is CRC value */
    n_rem = (0x000F & (n_rem >> 12));
    n_prom[7] = crc_read;

    /* return true if CRCs match */
    return (0x000F & crc_read) == (n_rem ^ 0x00);
}

static rt_err_t load_prom(void)
{
    for (uint8_t i = 0; i < 8; i++) {
        RT_TRY(read_prom_reg(ADDR_PROM_SETUP + (i << 1), ((uint16_t*)&_prom) + i));
    }

    return crc_check((uint16_t*)&_prom) ? RT_EOK : RT_ERROR;
}

static rt_err_t collect_data(baro_report_t* report)
{
    int32_t _dT;
    int32_t _temp;
    int32_t _pressure;

    _dT = _raw_temperature - ((int32_t)_prom.c5 << 8);
    _temp = 2000 + (int32_t)(((int64_t)_dT * _prom.c6) >> 23);

    int64_t OFF = ((int64_t)_prom.c2 << 16) + (((int64_t)_prom.c4 * _dT) >> 7);
    int64_t SENS = ((int64_t)_prom.c1 << 15) + (((int64_t)_prom.c3 * _dT) >> 8);

    /* temperature compensation */
    if (_temp < 2000) {
        int32_t T2 = POW2(_dT) >> 31;

        int64_t f = POW2((int64_t)_temp - 2000);
        int64_t OFF2 = 5 * f >> 1;
        int64_t SENS2 = 5 * f >> 2;

        if (_temp < -1500) {
            int64_t f2 = POW2(_temp + 1500);
            OFF2 += 7 * f2;
            SENS2 += 11 * f2 >> 1;
        }

        _temp -= T2;
        OFF -= OFF2;
        SENS -= SENS2;
    }

    _pressure = (((_raw_pressure * SENS) >> 21) - OFF) >> 15;

    report->temperature_deg = _temp / 100.0f; // in deg
    report->pressure_Pa = _pressure;          // in Pa

    /* tropospheric properties (0-11km) for standard atmosphere */
    const double T1 = 15.0 + 273.15; /* temperature at base height in Kelvin, [K] = [°C] + 273.15 */
    const double a = -6.5 / 1000;    /* temperature gradient in degrees per metre */
    const double g = 9.80665;        /* gravity constant in m/s/s */
    const double R = 287.05;         /* ideal gas constant in J/kg/K */

    /* current pressure at MSL in kPa */
    double p1 = 101325.0 / 1000.0;

    /* measured pressure in kPa */
    double p = _pressure / 1000.0;

    /*
	 * Solve:
	 *
	 *     /        -(aR / g)     \
	 *    | (p / p1)          . T1 | - T1
	 *     \                      /
	 * h = -------------------------------  + h1
	 *                   a
	 */
    //report->altitude = (((exp((-(a * R) / g) * log((p / p1)))) * T1) - T1) / a;
    report->altitude_m = (((pow((p / p1), (-(a * R) / g))) * T1) - T1) / a;

    report->timestamp_ms = systime_now_ms();

    return RT_EOK;
}

static void ms5611_measure(void* parameter)
{
    switch (_ms5611_state) {

    case S_CONV_1: {
        if (write_cmd(CMD_CONVERT_D1_ADDR[DEFAULT_OSR]) == RT_EOK) {
            _ms5611_state = S_CONV_2;
        }
    } break;

    case S_CONV_2: {
        _ms5611_state = S_CONV_1;

        /* read raw pressure */
        if (read_adc(&_raw_pressure) == RT_EOK) {
            /* trigger D2 conversion immediately */
            if (write_cmd(CMD_CONVERT_D2_ADDR[DEFAULT_OSR]) == RT_EOK) {
                _ms5611_state = S_COLLECT_REPORT;
            }
        }
    } break;

    case S_COLLECT_REPORT: {
        _ms5611_state = S_CONV_1;

        /* read raw temperature */
        if (read_adc(&_raw_temperature) == RT_EOK) {
            if (collect_data(&_baro_report) == RT_EOK) {
                /* trigger D1 conversion immediately */
                if (write_cmd(CMD_CONVERT_D1_ADDR[DEFAULT_OSR]) == RT_EOK) {
                    _ms5611_state = S_CONV_2;
                }

                /* set updated flag, baro report is ready */
                _updated = 1;
            }
        }
    } break;

    default:
        break;
    }
}

static rt_err_t lowlevel_init(void)
{
    RT_TRY(rt_device_open(spi_device, RT_DEVICE_OFLAG_RDWR));

    /* reset first */
    RT_TRY(write_cmd(ADDR_RESET_CMD));

    /* device need 2.8ms reload time */
    systime_mdelay(10);

    /* load prom */
    RT_TRY(load_prom());

    _raw_temperature = _raw_pressure = 0;
    _updated = 0;
    _ms5611_state = S_CONV_1;

    return RT_EOK;
}

static rt_err_t baro_control(baro_dev_t baro, int cmd, void* arg)
{
    switch (cmd) {
    case BARO_CMD_CHECK_READY: {
        *(uint8_t*)arg = _updated;
    } break;

    default:
        break;
    }

    return RT_EOK;
}

static rt_size_t baro_read(baro_dev_t baro, baro_report_t* report)
{
    if (!_updated)
        return 0;

    *report = _baro_report;

    /* read will reset updated flag */
    _updated = 0;

    return sizeof(baro_report_t);
}

static struct baro_ops _baro_ops = {
    baro_control,
    baro_read
};

static struct WorkItem ms5611_work = {
    .name = "ms5611",
    .period = 0,
    .schedule_time = 0,
    .run = ms5611_measure
};

rt_err_t drv_ms5611_init(const char* spi_device_name, const char* baro_device_name)
{
    static struct baro_device baro_device = {
        .ops = &_baro_ops
    };

    spi_device = rt_device_find(spi_device_name);
    RT_ASSERT(spi_device != NULL);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_device;

        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;
        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* driver internal init */
    RT_TRY(lowlevel_init());

    /* find high-priority workqueue */
    WorkQueue_t hp_wq = workqueue_find("wq:hp_work");
    /* set period based on osr */
    ms5611_work.period = CONV_TIME_INTERVAL[DEFAULT_OSR];
    /* schedule the work */
    FMT_CHECK(workqueue_schedule_work(hp_wq, &ms5611_work));

    RT_TRY(hal_baro_register(&baro_device, baro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}
