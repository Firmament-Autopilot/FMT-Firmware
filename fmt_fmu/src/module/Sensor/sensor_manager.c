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

#include "module/filter/butter.h"
#include "module/sensor/sensor_baro.h"
#include "module/sensor/sensor_gps.h"
#include "module/sensor/sensor_imu.h"
#include "module/sensor/sensor_mag.h"
#include "module/sensor/sensor_manager.h"

static IMU_Report _imu_report;
static Mag_Report _mag_report;
static Baro_Report _baro_report;
static GPS_Report _gps_report;

MCN_DEFINE(sensor_imu, sizeof(IMU_Report));
MCN_DEFINE(sensor_mag, sizeof(Mag_Report));
MCN_DEFINE(sensor_baro, sizeof(Baro_Report));
MCN_DEFINE(sensor_gps, sizeof(GPS_Report));

static Butter3* _butter3_gyr[3];
static Butter3* _butter3_acc[3];

static int SENSOR_IMU_echo(void* param)
{
    fmt_err err;
    IMU_Report imu_report;

    err = mcn_copy_from_hub((McnHub*)param, &imu_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("gyr:%f %f %f acc:%f %f %f\n",
        imu_report.gyr_B_radDs[0], imu_report.gyr_B_radDs[1], imu_report.gyr_B_radDs[2],
        imu_report.acc_B_mDs2[0], imu_report.acc_B_mDs2[1], imu_report.acc_B_mDs2[2]);

    return 0;
}

static int SENSOR_MAG_echo(void* param)
{
    fmt_err err;
    Mag_Report mag_report;

    err = mcn_copy_from_hub((McnHub*)param, &mag_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("mag:%f %f %f\n",
        mag_report.mag_B_gauss[0], mag_report.mag_B_gauss[1], mag_report.mag_B_gauss[2]);

    return 0;
}

static int SENSOR_BARO_echo(void* param)
{
    fmt_err err;
    Baro_Report baro_report;

    err = mcn_copy_from_hub((McnHub*)param, &baro_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("timestamp:%d pressure:%d temperature:%f altitude:%f\n",
        baro_report.timestamp_ms, baro_report.pressure_pa, baro_report.temperature_deg,
        baro_report.altitude_m);

    return 0;
}

static int SENSOR_GPS_echo(void* param)
{
    fmt_err err;
    GPS_Report gps_report;

    err = mcn_copy_from_hub((McnHub*)param, &gps_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("lon:%d lat:%d alt:%d fixType:%d numSV:%d hAcc:%f sAcc:%f\n", gps_report.lon, gps_report.lat,
        gps_report.height, gps_report.fixType, gps_report.numSV, gps_report.hAcc, gps_report.sAcc);

    return 0;
}

// should be called in each 1ms
void sensor_collect(void)
{
    DEFINE_TIMETAG(mag_update, 10);
    DEFINE_TIMETAG(baro_update, 5);

    _imu_report.timestamp_ms = systime_now_ms();
    sensor_gyr_measure(_imu_report.gyr_B_radDs, 0);
    sensor_acc_measure(_imu_report.acc_B_mDs2, 0);

    if (PARAM_GET_UINT8(INS, USE_EXTERN_FILTER)) {
        float temp[3];

        /* do calibration */
        _imu_report.gyr_B_radDs[0] -= PARAM_GET_FLOAT(CALIB, GYRO0_XOFF);
        _imu_report.gyr_B_radDs[1] -= PARAM_GET_FLOAT(CALIB, GYRO0_YOFF);
        _imu_report.gyr_B_radDs[2] -= PARAM_GET_FLOAT(CALIB, GYRO0_ZOFF);

        _imu_report.acc_B_mDs2[0] -= PARAM_GET_FLOAT(CALIB, ACC0_XOFF);
        _imu_report.acc_B_mDs2[1] -= PARAM_GET_FLOAT(CALIB, ACC0_YOFF);
        _imu_report.acc_B_mDs2[2] -= PARAM_GET_FLOAT(CALIB, ACC0_ZOFF);

        temp[0] = _imu_report.acc_B_mDs2[0] * PARAM_GET_FLOAT(CALIB, ACC0_XXSCALE)
            + _imu_report.acc_B_mDs2[1] * PARAM_GET_FLOAT(CALIB, ACC0_XYSCALE)
            + _imu_report.acc_B_mDs2[2] * PARAM_GET_FLOAT(CALIB, ACC0_XZSCALE);
        temp[1] = _imu_report.acc_B_mDs2[0] * PARAM_GET_FLOAT(CALIB, ACC0_XYSCALE)
            + _imu_report.acc_B_mDs2[1] * PARAM_GET_FLOAT(CALIB, ACC0_YYSCALE)
            + _imu_report.acc_B_mDs2[2] * PARAM_GET_FLOAT(CALIB, ACC0_YZSCALE);
        temp[2] = _imu_report.acc_B_mDs2[0] * PARAM_GET_FLOAT(CALIB, ACC0_XZSCALE)
            + _imu_report.acc_B_mDs2[1] * PARAM_GET_FLOAT(CALIB, ACC0_YZSCALE)
            + _imu_report.acc_B_mDs2[2] * PARAM_GET_FLOAT(CALIB, ACC0_ZZSCALE);
        _imu_report.acc_B_mDs2[0] = temp[0];
        _imu_report.acc_B_mDs2[1] = temp[1];
        _imu_report.acc_B_mDs2[2] = temp[2];

        /* do filtering */
        _imu_report.gyr_B_radDs[0] = butter3_filter_process(_imu_report.gyr_B_radDs[0], _butter3_gyr[0]);
        _imu_report.gyr_B_radDs[1] = butter3_filter_process(_imu_report.gyr_B_radDs[1], _butter3_gyr[1]);
        _imu_report.gyr_B_radDs[2] = butter3_filter_process(_imu_report.gyr_B_radDs[2], _butter3_gyr[2]);

        _imu_report.acc_B_mDs2[0] = butter3_filter_process(_imu_report.acc_B_mDs2[0], _butter3_acc[0]);
        _imu_report.acc_B_mDs2[1] = butter3_filter_process(_imu_report.acc_B_mDs2[1], _butter3_acc[1]);
        _imu_report.acc_B_mDs2[2] = butter3_filter_process(_imu_report.acc_B_mDs2[2], _butter3_acc[2]);
    }

    mcn_publish(MCN_ID(sensor_imu), &_imu_report);

    if (check_timetag(TIMETAG(mag_update))) {

        _mag_report.timestamp_ms = systime_now_ms();
        sensor_mag_measure(_mag_report.mag_B_gauss, 0);

        mcn_publish(MCN_ID(sensor_mag), &_mag_report);
    }

    if (check_timetag(TIMETAG(baro_update))) {
        sensor_baro_update();
        if (sensor_baro_check_update()) {
            baro_report_t report;

            if (sensor_baro_get_report(&report) == FMT_EOK) {
                _baro_report.temperature_deg = report.temperature_deg;
                _baro_report.pressure_pa = report.pressure_Pa;
                _baro_report.altitude_m = report.altitude_m;
                _baro_report.timestamp_ms = report.timestamp_ms;

                mcn_publish(MCN_ID(sensor_baro), &_baro_report);
            }
        }
    }

    if (sensor_gps_report_ready()) {

        sensor_gps_get_report(&_gps_report);

        mcn_publish(MCN_ID(sensor_gps), &_gps_report);
    }
}

fmt_err sensor_manager_init(void)
{
    fmt_err err = FMT_EOK;

    err |= sensor_imu_init();
    err |= sensor_mag_init();
    err |= sensor_baro_init();
    err |= sensor_gps_init();

    /* advertise sensor data */
    err |= mcn_advertise(MCN_ID(sensor_imu), SENSOR_IMU_echo);
    err |= mcn_advertise(MCN_ID(sensor_mag), SENSOR_MAG_echo);
    err |= mcn_advertise(MCN_ID(sensor_baro), SENSOR_BARO_echo);
    err |= mcn_advertise(MCN_ID(sensor_gps), SENSOR_GPS_echo);

    if (PARAM_GET_UINT8(INS, USE_EXTERN_FILTER)) {
        /* 30Hz cut-off frequency, 1000Hz sampling frequency */
        float B[4] = { 0.0007, 0.0021, 0.0021, 0.0007 };
        float A[4] = { 1.0, -2.6236, 2.3147, -0.6855 };

        console_printf("use external filter\n");

        _butter3_gyr[0] = butter3_filter_create(B, A);
        _butter3_gyr[1] = butter3_filter_create(B, A);
        _butter3_gyr[2] = butter3_filter_create(B, A);

        if (_butter3_gyr[0] == NULL || _butter3_gyr[1] == NULL || _butter3_gyr[2] == NULL) {
            console_printf("Fail to create butter filter for gyr!\n");
            return FMT_ERROR;
        }

        _butter3_acc[0] = butter3_filter_create(B, A);
        _butter3_acc[1] = butter3_filter_create(B, A);
        _butter3_acc[2] = butter3_filter_create(B, A);

        if (_butter3_acc[0] == NULL || _butter3_acc[1] == NULL || _butter3_acc[2] == NULL) {
            console_printf("Fail to create butter filter for acc!\n");
            return FMT_ERROR;
        }
    }

    return err == FMT_EOK ? FMT_EOK : FMT_ERROR;
}