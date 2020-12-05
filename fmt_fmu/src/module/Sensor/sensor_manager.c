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

#include "module/filter/butter.h"
#include "module/math/light_matrix.h"
#include "module/sensor/sensor_baro.h"
#include "module/sensor/sensor_gps.h"
#include "module/sensor/sensor_imu.h"
#include "module/sensor/sensor_mag.h"
#include "module/sensor/sensor_manager.h"

MCN_DEFINE(sensor_imu, sizeof(IMU_Report));
MCN_DEFINE(sensor_imu_scale, sizeof(IMU_Report));
MCN_DEFINE(sensor_mag, sizeof(Mag_Report));
MCN_DEFINE(sensor_mag_scale, sizeof(Mag_Report));
MCN_DEFINE(sensor_baro, sizeof(Baro_Report));
MCN_DEFINE(sensor_gps, sizeof(GPS_Report));

static IMU_Report _imu_report;
static Mag_Report _mag_report;
static Baro_Report _baro_report;
static GPS_Report _gps_report;
static Butter3* _butter3_gyr[3];
static Butter3* _butter3_acc[3];
static sensor_imu_t _imu0_dev = NULL;
// static sensor_imu_t _imu1_dev = NULL;
static sensor_mag_t _mag0_dev = NULL;
// static sensor_mag_t _mag1_dev = NULL;

static void dcm_from_euler(const float rpy[3], float dcm[9])
{
    float cosPhi = arm_cos_f32(rpy[0]);
    float sinPhi = arm_sin_f32(rpy[0]);
    float cosThe = arm_cos_f32(rpy[1]);
    float sinThe = arm_sin_f32(rpy[1]);
    float cosPsi = arm_cos_f32(rpy[2]);
    float sinPsi = arm_sin_f32(rpy[2]);

    dcm[0] = cosThe * cosPsi;
    dcm[1] = -cosPhi * sinPsi + sinPhi * sinThe * cosPsi;
    dcm[2] = sinPhi * sinPsi + cosPhi * sinThe * cosPsi;

    dcm[3] = cosThe * sinPsi;
    dcm[4] = cosPhi * cosPsi + sinPhi * sinThe * sinPsi;
    dcm[5] = -sinPhi * cosPsi + cosPhi * sinThe * sinPsi;

    dcm[6] = -sinThe;
    dcm[7] = sinPhi * cosThe;
    dcm[8] = cosPhi * cosThe;
}

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

static void _init_rotation(void)
{
    Mat level_rot;
    Mat gyr_rot;
    Mat acc_rot, acc_scale;
    Mat mag_rot, mag_scale;
    float val_level_rot[9];
    float val_acc_scale[] = {
        PARAM_GET_FLOAT(CALIB, ACC0_XXSCALE), PARAM_GET_FLOAT(CALIB, ACC0_XYSCALE), PARAM_GET_FLOAT(CALIB, ACC0_XZSCALE),
        PARAM_GET_FLOAT(CALIB, ACC0_XYSCALE), PARAM_GET_FLOAT(CALIB, ACC0_YYSCALE), PARAM_GET_FLOAT(CALIB, ACC0_YZSCALE),
        PARAM_GET_FLOAT(CALIB, ACC0_XZSCALE), PARAM_GET_FLOAT(CALIB, ACC0_YZSCALE), PARAM_GET_FLOAT(CALIB, ACC0_ZZSCALE)
    };
    float val_mag_scale[] = {
        PARAM_GET_FLOAT(CALIB, MAG0_XXSCALE), PARAM_GET_FLOAT(CALIB, MAG0_XYSCALE), PARAM_GET_FLOAT(CALIB, MAG0_XZSCALE),
        PARAM_GET_FLOAT(CALIB, MAG0_XYSCALE), PARAM_GET_FLOAT(CALIB, MAG0_YYSCALE), PARAM_GET_FLOAT(CALIB, MAG0_YZSCALE),
        PARAM_GET_FLOAT(CALIB, MAG0_XZSCALE), PARAM_GET_FLOAT(CALIB, MAG0_YZSCALE), PARAM_GET_FLOAT(CALIB, MAG0_ZZSCALE)
    };
    float level_rpy[] = {
        PARAM_GET_FLOAT(CALIB, LEVEL_XOFF), PARAM_GET_FLOAT(CALIB, LEVEL_YOFF), PARAM_GET_FLOAT(CALIB, LEVEL_ZOFF)
    };

    /* get level calibration dcm */
    dcm_from_euler(level_rpy, val_level_rot);
    /* create and init matrix */
    MatSetVal(MatCreate(&gyr_rot, 3, 3), val_level_rot);
    MatSetVal(MatCreate(&acc_scale, 3, 3), val_acc_scale);
    MatSetVal(MatCreate(&mag_scale, 3, 3), val_mag_scale);
    MatSetVal(MatCreate(&level_rot, 3, 3), val_level_rot);
    /* calculate rotation matrix */
    MatMul(&level_rot, &acc_scale, MatCreate(&acc_rot, 3, 3));
    MatMul(&level_rot, &mag_scale, MatCreate(&mag_rot, 3, 3));
    /* set rotation */
    sensor_gyr_set_rotation(_imu0_dev, gyr_rot.buffer);
    sensor_acc_set_rotation(_imu0_dev, acc_rot.buffer);
    /* delete matrix */
    MatDelete(&gyr_rot);
    MatDelete(&acc_rot);
    MatDelete(&mag_rot);
    MatDelete(&acc_scale);
    MatDelete(&mag_scale);
    MatDelete(&level_rot);
}

static void _init_offset(void)
{
    float gyr_off[] = {
        PARAM_GET_FLOAT(CALIB, GYRO0_XOFF), PARAM_GET_FLOAT(CALIB, GYRO0_YOFF), PARAM_GET_FLOAT(CALIB, GYRO0_ZOFF)
    };
    float acc_off[] = {
        PARAM_GET_FLOAT(CALIB, ACC0_XOFF), PARAM_GET_FLOAT(CALIB, ACC0_YOFF), PARAM_GET_FLOAT(CALIB, ACC0_ZOFF)
    };
    float mag_off[] = {
        PARAM_GET_FLOAT(CALIB, MAG0_XOFF), PARAM_GET_FLOAT(CALIB, MAG0_YOFF), PARAM_GET_FLOAT(CALIB, MAG0_ZOFF)
    };

    sensor_gyr_set_offset(_imu0_dev, gyr_off);
    sensor_acc_set_offset(_imu0_dev, acc_off);
    sensor_mag_set_offset(_mag0_dev, mag_off);
}

static fmt_err _init_filter(void)
{
    /* 30Hz cut-off frequency, 1000Hz sampling frequency */
    float B[4] = { 0.0007, 0.0021, 0.0021, 0.0007 };
    float A[4] = { 1.0, -2.6236, 2.3147, -0.6855 };

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

    return FMT_EOK;
}

// should be called in each 1ms
void sensor_collect(void)
{
    DEFINE_TIMETAG(mag_update, 10);
    DEFINE_TIMETAG(baro_update, 5);

    float temp[3];

    /*************** Collect IMU Data ***************/
    _imu_report.timestamp_ms = systime_now_ms();
    sensor_gyr_measure(_imu0_dev, _imu_report.gyr_B_radDs);
    sensor_acc_measure(_imu0_dev, _imu_report.acc_B_mDs2);
    /* publish scale imu data without calibration and filtering */
    mcn_publish(MCN_HUB(sensor_imu_scale), &_imu_report);
    /* do calibration */
    sensor_gyr_correct(_imu0_dev, _imu_report.gyr_B_radDs, temp);
    _imu_report.gyr_B_radDs[0] = temp[0];
    _imu_report.gyr_B_radDs[1] = temp[1];
    _imu_report.gyr_B_radDs[2] = temp[2];
    sensor_acc_correct(_imu0_dev, _imu_report.acc_B_mDs2, temp);
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
    /* publish calibrated & filtered imu data */
    mcn_publish(MCN_HUB(sensor_imu), &_imu_report);

    /*************** Collect MAG Data ***************/
    if (check_timetag(TIMETAG(mag_update))) {
        _mag_report.timestamp_ms = systime_now_ms();
        sensor_mag_measure(_mag0_dev, _mag_report.mag_B_gauss);
        mcn_publish(MCN_HUB(sensor_mag_scale), &_mag_report);
        /* do calibration */
        sensor_mag_correct(_mag0_dev, _mag_report.mag_B_gauss, temp);
        _mag_report.mag_B_gauss[0] = temp[0];
        _mag_report.mag_B_gauss[1] = temp[1];
        _mag_report.mag_B_gauss[2] = temp[2];
        /* do filtering */
        // TBD
        /* publish calibrated & filtered mag data */
        mcn_publish(MCN_HUB(sensor_mag), &_mag_report);
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

                mcn_publish(MCN_HUB(sensor_baro), &_baro_report);
            }
        }
    }

    if (sensor_gps_report_ready()) {

        sensor_gps_get_report(&_gps_report);

        mcn_publish(MCN_HUB(sensor_gps), &_gps_report);
    }
}

fmt_err sensor_manager_init(void)
{
    fmt_err err = FMT_EOK;

    _imu0_dev = sensor_imu_init("gyro0", "accel0");
    _mag0_dev = sensor_mag_init("mag0");
    err |= sensor_baro_init();
    err |= sensor_gps_init();

    if (_imu0_dev == NULL || _mag0_dev == NULL) {
        return FMT_ERROR;
    }

    /* advertise sensor data */
    err |= mcn_advertise(MCN_HUB(sensor_imu), SENSOR_IMU_echo);
    err |= mcn_advertise(MCN_HUB(sensor_imu_scale), SENSOR_IMU_echo);
    err |= mcn_advertise(MCN_HUB(sensor_mag), SENSOR_MAG_echo);
    err |= mcn_advertise(MCN_HUB(sensor_mag_scale), SENSOR_MAG_echo);
    err |= mcn_advertise(MCN_HUB(sensor_baro), SENSOR_BARO_echo);
    err |= mcn_advertise(MCN_HUB(sensor_gps), SENSOR_GPS_echo);

    _init_rotation();
    _init_offset();
    err |= _init_filter();

    return err == FMT_EOK ? FMT_EOK : FMT_ERROR;
}