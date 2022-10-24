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
#include "driver/barometer/spl06.h"
#include "hal/barometer/barometer.h"
#include "hal/spi/spi.h"
#include "module/math/conversion.h"
#include <firmament.h>
#include <math.h>


#define DRV_DBG(...) console_printf(__VA_ARGS__)
#define POW2(_x)     ((_x) * (_x))

struct {
	struct {
		int16_t c0, c1;
		int32_t c00, c10;
		int16_t c01, c11, c20, c21, c30;
	} coe;

	float kt;
	float kp;

	int32_t press_raw;
	int32_t temp_raw;

	// uint64_t t_start;      // measurement start timestamp
	// uint8_t measure_phase; // 0-temperature 1-pressure
	uint8_t t_start_temperature; // 0-temperature 1-pressure
	uint8_t t_start_presssure; // 0-temperature 1-pressure

	int inited;

} _spl;


#define SPL06_CHIP_ID                          0x10

#define SPL06_REG_PRESSURE_B2                  0x00    // Pressure MSB Register
#define SPL06_REG_PRESSURE_B1                  0x01    // Pressure middle byte Register
#define SPL06_REG_PRESSURE_B0                  0x02    // Pressure LSB Register
#define SPL06_REG_PRESSURE_START               SPL06_REG_PRESSURE_B2
#define SPL06_PRESSURE_LEN                     3       // 24 bits, 3 bytes
#define SPL06_REG_TEMPERATURE_B2               0x03    // Temperature MSB Register
#define SPL06_REG_TEMPERATURE_B1               0x04    // Temperature middle byte Register
#define SPL06_REG_TEMPERATURE_B0               0x05    // Temperature LSB Register
#define SPL06_REG_TEMPERATURE_START            SPL06_REG_TEMPERATURE_B2
#define SPL06_TEMPERATURE_LEN                  3       // 24 bits, 3 bytes
#define SPL06_REG_PRESSURE_CFG                 0x06    // Pressure config
#define SPL06_REG_TEMPERATURE_CFG              0x07    // Temperature config
#define SPL06_REG_MODE_AND_STATUS              0x08    // Mode and status
#define SPL06_REG_INT_AND_FIFO_CFG             0x09    // Interrupt and FIFO config
#define SPL06_REG_INT_STATUS                   0x0A    // Interrupt and FIFO config
#define SPL06_REG_FIFO_STATUS                  0x0B    // Interrupt and FIFO config
#define SPL06_REG_RST                          0x0C    // Softreset Register
#define SPL06_REG_CHIP_ID                      0x0D    // Chip ID Register
#define SPL06_REG_CALIB_COEFFS_START           0x10
#define SPL06_REG_CALIB_COEFFS_END             0x21


#define REG_MODE_AND_STATUS__TEMP_RDY          (1 << 5)
#define REG_MODE_AND_STATUS__PRS_RDY          (1 << 4)

#define SPL06_CALIB_COEFFS_LEN                 (SPL06_REG_CALIB_COEFFS_END - SPL06_REG_CALIB_COEFFS_START + 1)



typedef struct {
    uint16_t factory_data;
    uint16_t c1;
    uint16_t c2;
    uint16_t c3;
    uint16_t c4;
    uint16_t c5;
    uint16_t c6;
    uint16_t crc;
} spl06_prom_t;

/* spl06 report read state */
enum {
    S_CONV_1 = 0,
    S_RAW_PRESS,
    S_CONV_2,
    S_RAW_TEMP,
    S_COLLECT_REPORT
};

static rt_device_t spi_device;
uint32_t _raw_temperature, _raw_pressure;

static baro_report_t _baro_report;
static uint8_t _updated = 0;


static rt_err_t _collect_report(baro_report_t* report)
{

	// calculate
    float ftsc = (float)_spl.temp_raw / _spl.kt;
    float fpsc = (float)_spl.press_raw / _spl.kp;
    float qua2 = (float)_spl.coe.c10 + fpsc * ((float)_spl.coe.c20 + fpsc * (float)_spl.coe.c30);
    float qua3 = ftsc * fpsc * ((float)_spl.coe.c11 + fpsc * (float)_spl.coe.c21);

    float fp = (float)_spl.coe.c00 + fpsc * qua2 + ftsc * (float)_spl.coe.c01 + qua3;

    // altitude calculations based on http://www.kansasflyer.org/index.asp?nav=Avi&sec=Alti&tab=Theory&pg=1

    // tropospheric properties (0-11km) for standard atmosphere
    const float T1 = 15.0f + 273.15f;   // temperature at base height in Kelvin
    const float a  = -6.5f / 1000.0f;   // temperature gradient in degrees per metre
    const float g  = 9.80665f;          // gravity constant in m/s/s
    const float R  = 287.05f;           // ideal gas constant in J/kg/K
    const float msl_pressure = 101325;  // in Pa
    float pK = fp / msl_pressure;

    /*
        * Solve:
        *
        *     /        -(aR / g)     \
        *    | (p / p1)          . T1 | - T1
        *     \                      /
        * h = -------------------------------  + h1
        *                   a
        */

    report->raw_temperature = _spl.temp_raw;
    report->raw_pressure = _spl.press_raw;


    report->temperature_deg =(float)_spl.coe.c0 * 0.5f + (float)_spl.coe.c1 * ftsc; // in deg
    report->pressure_Pa = fp;          // in Pa

    report->altitude_m = (((powf(pK, (-(a * R) / g))) * T1) - T1) / a;

    report->timestamp_ms = systime_now_ms();

    return RT_EOK;
}

static rt_err_t _init(void)
{
    rt_err_t ret = RT_EOK;
    
    ret |= rt_device_open(spi_device, RT_DEVICE_OFLAG_RDWR);
    if(ret != RT_EOK)
    {
        return ret;
    }

    /* get chip ID */
    uint8_t chip_id;
    RT_TRY(spi_read_reg8(spi_device, 0x0d, &chip_id));
    if (chip_id != SPL06_CHIP_ID) {
        DRV_DBG("spl06 unmatched chip id:0x%x\n", chip_id);
        return FMT_ERROR;
    }

    systime_mdelay(10);

	uint8_t buf[18] = { 0 };

	spi_read_multi_reg8(spi_device, SPL06_REG_CALIB_COEFFS_START, buf, sizeof(buf));

	_spl.coe.c0 = (uint16_t)buf[0] << 4 | (uint16_t)buf[1] >> 4;
	_spl.coe.c0 = (_spl.coe.c0 & 1 << 11) ? (0xf000 | _spl.coe.c0) : _spl.coe.c0;

	_spl.coe.c1 = (uint16_t)(buf[1] & 0x0f) << 8 | (uint16_t)buf[2];
	_spl.coe.c1 = (_spl.coe.c1 & 1 << 11) ? (0xf000 | _spl.coe.c1) : _spl.coe.c1;

	_spl.coe.c00 = (uint32_t)buf[3] << 12 | (uint32_t)buf[4] << 4 | (uint16_t)buf[5] >> 4;
	_spl.coe.c00 = (_spl.coe.c00 & 1 << 19) ? (0xfff00000 | _spl.coe.c00) : _spl.coe.c00;

	_spl.coe.c10 = (uint32_t)(buf[5] & 0x0f) << 16 | (uint32_t)buf[6] << 8 | (uint32_t)buf[7];
	_spl.coe.c10 = (_spl.coe.c10 & 1 << 19) ? (0xfff00000 | _spl.coe.c10) : _spl.coe.c10;

	_spl.coe.c01 = (uint16_t)buf[8] << 8 | buf[9];
	_spl.coe.c11 = (uint16_t)buf[10] << 8 | buf[11];
	_spl.coe.c20 = (uint16_t)buf[12] << 8 | buf[13];
	_spl.coe.c21 = (uint16_t)buf[14] << 8 | buf[15];
	_spl.coe.c30 = (uint16_t)buf[16] << 8 | buf[17];

    
    int state = 0;

	// compensation scale factors
	//
	// oversampling rate  : single | 2       | 4       | 8       | 16     | 32     | 64      | 128
	// scale factor(KP/KT): 524288 | 1572864 | 3670016 | 7864320 | 253952 | 516096 | 1040384 | 2088960

	// configuration of pressure measurement rate (PM_RATE) and resolution (PM_PRC)
	//
	// measurement rate: 1 | 2 | 4 | 8 | 16 | 32 | 64 | 128
	// PM_RATE[6:4]    : 0 | 1 | 2 | 3 | 4  | 5  | 6  | 7
	// note: applicable for measurements in background mode only
	//
	// PM_PRC[3:0]         : 0      | 1   | 2   | 3    | 4    | 5    | 6     | 7
	// oversampling (times): single | 2   | 4   | 8    | 16   | 32   | 64    | 128
	// measurement time(ms): 3.6    | 5.2 | 8.4 | 14.8 | 27.6 | 53.2 | 104.4 | 206.8
	// precision(PaRMS)    : 5.0    |     | 2.5 |      | 1.2  | 0.9  | 0.5   |
	// note: use in combination with a bit shift when the oversampling rate is > 8 times. see CFG_REG(0x19) register
	state += spi_write_reg8(spi_device, 0x06, 0x44);
	_spl.kp = 253952.0f;

	// configuration of temperature measurment rate (TMP_RATE) and resolution (TMP_PRC)
	//
	// temperature measurement: internal sensor (in ASIC) | external sensor (in pressure sensor MEMS element
	// TMP_EXT[7]             : 0                         | 1
	// note: it is highly recommended to use the same temperature sensor as the source of the calibration coefficients wihch can be read from reg 0x28
	//
	// measurement rate: 1 | 2 | 4 | 8 | 16 | 32 | 64 | 128
	// TMP_RATE[6:4]   : 0 | 1 | 2 | 3 | 4  | 5  | 6  | 7
	//
	// oversampling (times): single | 2 | 4 | 8 | 16 | 32 | 64 | 128
	// TMP_PRC[2:0]        : 0      | 1 | 2 | 3 | 4  | 5  | 6  | 7
	// note: single(default) measurement time 3.6ms, other settings are optional, and may not be relevant
	// note: use in combination with a bit shift when the oversampling rate is > 8 times. see CFG_REG(0x19) register
	state += spi_write_reg8(spi_device, 0x07, 1 << 7);
	_spl.kt = 524288.0f;

	// diasble all interrupts and FIFO
	//
	// bit0: set to '0' for 4-wire interface
	//       set to '1' for 3-wire interface
	//
	// bit1: set to '1' for FIFO enable
	//
	// note: bit2 must be set to '1' when the pressure oversampling rate is > 8 times
	// note: bit3 must be set to '1' when the temperature oversampling rate is > 8 times
	//
	// bit4: set to '1' for temperature measurement ready interrupt
	// bit5: set to '1' for pressure measurement ready interrupt
	// bit6: set to '1' for FIFO full interrupt
	//
	// bit7: interrupt(on SDO pin) active level
	//       0-active low  1-active hight
	state += spi_write_reg8(spi_device, 0x09, 1 << 2);

	// start temperature measurement
	// uint8_t cmd = 0x02;
	// write_reg(0x08, cmd);
	// _spl.measure_phase = 0;
	spi_write_reg8(spi_device, 0x08, 0x07);	// 开启连续采集模式
	_spl.t_start_temperature = systime_now_us();
	_spl.t_start_presssure = systime_now_us();

	if (!state) {
		_spl.inited = 1;
		DRV_DBG("spl06-007 init success!\r\n");

	} else {
		DRV_DBG(" spl06 init fail !!!\r\n");
        return FMT_ERROR;
	}

    return ret;
}

static void _spl06_StateMchine()
{
    
    // uint64_t t = HAL_GetSysUsTick();

	uint8_t buffer[3] = { 0 };

	// temperature measurement
	// cf_log("reg06 = %02x",read_reg_single(0x06));
	// cf_log("reg07 = %02x",read_reg_single(0x07));
	// cf_log("reg08 = %02x",read_reg_single(0x08));
	// cf_log("reg09 = %02x",read_reg_single(0x09));
	// if (t > _spl.t_start_temperature + 3600 && read_reg_single(0x08) & (1 << 5)) {
    uint8_t buf[1];
	spi_read_reg8(spi_device, 0x08, buf);
	if (buf[0] & (1 << 5)) {

		spi_read_multi_reg8(spi_device, 0x03, buffer, 3);

		_spl.temp_raw = (int32_t)buffer[0] << 16 | (int32_t)buffer[1] << 8 | (int32_t)buffer[2];
		_spl.temp_raw = (_spl.temp_raw & 1 << 23) ? (0xff000000 | _spl.temp_raw) : _spl.temp_raw;

	}

	spi_read_reg8(spi_device, 0x08, buf);
	if (buf[0] & (1 << 4)) {

		spi_read_multi_reg8(spi_device, 0x00, buffer, 3);

		_spl.press_raw = (int32_t)buffer[0] << 16 | (int32_t)buffer[1] << 8 | (int32_t)buffer[2];
		_spl.press_raw = (_spl.press_raw & 1 << 23) ? (0xff000000 | _spl.press_raw) : _spl.press_raw;

        _updated = 1;
	}
}

static rt_err_t baro_config(baro_dev_t baro, const struct baro_configure* cfg)
{
    baro->config = *cfg;
    _updated = 0;

    return RT_EOK;
}

static rt_err_t baro_control(baro_dev_t baro, int cmd, void* arg)
{
    switch (cmd) {
    case BARO_CMD_CHECK_READY: {
        *(uint8_t*)arg = _updated;
    } break;

    case BARO_CMD_UPDATE: {
        _spl06_StateMchine();
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

    _collect_report(&_baro_report);
    *report = _baro_report;

    /* read will reset updated flag */
    _updated = 0;

    return sizeof(baro_report_t);
}

static struct baro_ops _baro_ops = {
    baro_config,
    baro_control,
    baro_read
};

rt_err_t drv_spl06_init(const char* spi_device_name, const char* sensor_device_name)
{
    rt_err_t ret = RT_EOK;
    static struct baro_device baro_device = {
        .ops = &_baro_ops,
        .config = BARO_CONFIG_DEFAULT   // noused
    };

    spi_device = rt_device_find(spi_device_name);

    if (spi_device == RT_NULL) {
        return RT_EEMPTY;
    }

    /* driver internal init */
    ret |= _init();

    ret |= hal_baro_register(&baro_device, sensor_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL);

    return ret;
}
