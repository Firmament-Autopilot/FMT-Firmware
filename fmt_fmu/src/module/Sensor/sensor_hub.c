/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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
#include <board_device.h>
#include <firmament.h>
#include <math.h>

#include "module/filter/butter.h"
#include "module/math/light_matrix.h"
#include "module/sensor/sensor_baro.h"
#include "module/sensor/sensor_gps.h"
#include "module/sensor/sensor_hub.h"
#include "module/sensor/sensor_imu.h"
#include "module/sensor/sensor_mag.h"

MCN_DEFINE(sensor_imu0_0, sizeof(imu_data_t));
MCN_DEFINE(sensor_imu0, sizeof(imu_data_t));

MCN_DEFINE(sensor_imu1_0, sizeof(imu_data_t));
MCN_DEFINE(sensor_imu1, sizeof(imu_data_t));

MCN_DEFINE(sensor_mag0_0, sizeof(mag_data_t));
MCN_DEFINE(sensor_mag0, sizeof(mag_data_t));

MCN_DEFINE(sensor_mag1_0, sizeof(mag_data_t));
MCN_DEFINE(sensor_mag1, sizeof(mag_data_t));

MCN_DEFINE(sensor_baro, sizeof(baro_data_t));

MCN_DEFINE(sensor_gps, sizeof(gps_data_t));

MCN_DEFINE(sensor_optflow, sizeof(optflow_data_t));

MCN_DEFINE(sensor_rangefinder, sizeof(rf_data_t));

/* Sensor devices */
#ifdef SENSOR_USING_IMU0
static sensor_imu_t imu0;
static Butter3* butter3_gyr0[3];
static Butter3* butter3_acc0[3];
#endif

#ifdef SENSOR_USING_IMU1
static sensor_imu_t imu1;
static Butter3* butter3_gyr1[3];
static Butter3* butter3_acc1[3];
#endif

#ifdef SENSOR_USING_MAG0
static sensor_mag_t mag0;
#endif

#ifdef SENSOR_USING_MAG1
static sensor_mag_t mag1;
#endif

#ifdef SENSOR_USING_BAROMETER
static sensor_baro_t barometer;
#endif

#ifdef SENSOR_USING_GPS
static sensor_gps_t gps;
#endif

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

static int echo_sensor_imu(void* param)
{
    fmt_err_t err;
    imu_data_t imu_report;

    err = mcn_copy_from_hub((McnHub*)param, &imu_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("gyr:%f %f %f acc:%f %f %f\n",
        imu_report.gyr_B_radDs[0], imu_report.gyr_B_radDs[1], imu_report.gyr_B_radDs[2],
        imu_report.acc_B_mDs2[0], imu_report.acc_B_mDs2[1], imu_report.acc_B_mDs2[2]);

    return 0;
}

static int echo_sensor_mag(void* param)
{
    fmt_err_t err;
    mag_data_t mag_report;

    err = mcn_copy_from_hub((McnHub*)param, &mag_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("mag:%f %f %f\n",
        mag_report.mag_B_gauss[0], mag_report.mag_B_gauss[1], mag_report.mag_B_gauss[2]);

    return 0;
}

static int echo_sensor_baro(void* param)
{
    fmt_err_t err;
    baro_data_t baro_report;

    err = mcn_copy_from_hub((McnHub*)param, &baro_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("timestamp:%d pressure:%d temperature:%f altitude:%f\n",
        baro_report.timestamp_ms, baro_report.pressure_pa, baro_report.temperature_deg,
        baro_report.altitude_m);

    return 0;
}

static int echo_sensor_gps(void* param)
{
    fmt_err_t err;
    gps_data_t gps_report;

    err = mcn_copy_from_hub((McnHub*)param, &gps_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("lon:%d lat:%d alt:%d fixType:%d numSV:%d hAcc:%f sAcc:%f\n", gps_report.lon, gps_report.lat,
        gps_report.height, gps_report.fixType, gps_report.numSV, gps_report.hAcc, gps_report.sAcc);

    return 0;
}

/**
 * @brief Initialize sensor rotation matrix
 * 
 */
static void rotation_init(void)
{
    Mat level_rot;
    Mat gyr_rot;
    Mat acc_rot, acc_scale;
    Mat mag_rot, mag_scale;
    float val_level_rot[9];
    float level_rpy[] = {
        PARAM_GET_FLOAT(CALIB, LEVEL_XOFF), PARAM_GET_FLOAT(CALIB, LEVEL_YOFF), PARAM_GET_FLOAT(CALIB, LEVEL_ZOFF)
    };

    /* Create Matrix */
    MatCreate(&gyr_rot, 3, 3);
    MatCreate(&acc_scale, 3, 3);
    MatCreate(&mag_scale, 3, 3);
    MatCreate(&level_rot, 3, 3);
    MatCreate(&acc_rot, 3, 3);
    MatCreate(&mag_rot, 3, 3);

    /* Get level calibration dcm */
    dcm_from_euler(level_rpy, val_level_rot);

    /* Init matrix value */
    MatSetVal(&level_rot, val_level_rot);
    MatSetVal(&gyr_rot, val_level_rot);

#ifdef SENSOR_USING_IMU0
    float val_acc0_scale[] = {
        PARAM_GET_FLOAT(CALIB, ACC0_XXSCALE), PARAM_GET_FLOAT(CALIB, ACC0_XYSCALE), PARAM_GET_FLOAT(CALIB, ACC0_XZSCALE),
        PARAM_GET_FLOAT(CALIB, ACC0_XYSCALE), PARAM_GET_FLOAT(CALIB, ACC0_YYSCALE), PARAM_GET_FLOAT(CALIB, ACC0_YZSCALE),
        PARAM_GET_FLOAT(CALIB, ACC0_XZSCALE), PARAM_GET_FLOAT(CALIB, ACC0_YZSCALE), PARAM_GET_FLOAT(CALIB, ACC0_ZZSCALE)
    };
    /* calculate rotation matrix */
    MatSetVal(&acc_scale, val_acc0_scale);
    MatMul(&level_rot, &acc_scale, &acc_rot);
    /* set rotation */
    sensor_gyr_set_rotation(imu0, gyr_rot.buffer);
    sensor_acc_set_rotation(imu0, acc_rot.buffer);
#endif

#ifdef SENSOR_USING_IMU1
    float val_acc1_scale[] = {
        PARAM_GET_FLOAT(CALIB, ACC1_XXSCALE), PARAM_GET_FLOAT(CALIB, ACC1_XYSCALE), PARAM_GET_FLOAT(CALIB, ACC1_XZSCALE),
        PARAM_GET_FLOAT(CALIB, ACC1_XYSCALE), PARAM_GET_FLOAT(CALIB, ACC1_YYSCALE), PARAM_GET_FLOAT(CALIB, ACC1_YZSCALE),
        PARAM_GET_FLOAT(CALIB, ACC1_XZSCALE), PARAM_GET_FLOAT(CALIB, ACC1_YZSCALE), PARAM_GET_FLOAT(CALIB, ACC1_ZZSCALE)
    };
    /* Calculate rotation matrix */
    MatSetVal(&acc_scale, val_acc1_scale);
    MatMul(&level_rot, &acc_scale, &acc_rot);
    /* Set rotation */
    sensor_gyr_set_rotation(imu1, gyr_rot.buffer);
    sensor_acc_set_rotation(imu1, acc_rot.buffer);
#endif

#ifdef SENSOR_USING_MAG0
    float val_mag0_scale[] = {
        PARAM_GET_FLOAT(CALIB, MAG0_XXSCALE), PARAM_GET_FLOAT(CALIB, MAG0_XYSCALE), PARAM_GET_FLOAT(CALIB, MAG0_XZSCALE),
        PARAM_GET_FLOAT(CALIB, MAG0_XYSCALE), PARAM_GET_FLOAT(CALIB, MAG0_YYSCALE), PARAM_GET_FLOAT(CALIB, MAG0_YZSCALE),
        PARAM_GET_FLOAT(CALIB, MAG0_XZSCALE), PARAM_GET_FLOAT(CALIB, MAG0_YZSCALE), PARAM_GET_FLOAT(CALIB, MAG0_ZZSCALE)
    };
    /* Calculate rotation matrix */
    MatSetVal(&mag_scale, val_mag0_scale);
    MatMul(&level_rot, &mag_scale, &mag_rot);
    /* Set rotation */
    sensor_mag_set_rotation(mag0, mag_rot.buffer);
#endif

#ifdef SENSOR_USING_MAG1
    float val_mag1_scale[] = {
        PARAM_GET_FLOAT(CALIB, MAG1_XXSCALE), PARAM_GET_FLOAT(CALIB, MAG1_XYSCALE), PARAM_GET_FLOAT(CALIB, MAG1_XZSCALE),
        PARAM_GET_FLOAT(CALIB, MAG1_XYSCALE), PARAM_GET_FLOAT(CALIB, MAG1_YYSCALE), PARAM_GET_FLOAT(CALIB, MAG1_YZSCALE),
        PARAM_GET_FLOAT(CALIB, MAG1_XZSCALE), PARAM_GET_FLOAT(CALIB, MAG1_YZSCALE), PARAM_GET_FLOAT(CALIB, MAG1_ZZSCALE)
    };
    /* Calculate rotation matrix */
    MatSetVal(&mag_scale, val_mag1_scale);
    MatMul(&level_rot, &mag_scale, &mag_rot);
    /* Set rotation */
    sensor_mag_set_rotation(mag1, mag_rot.buffer);
#endif

    /* Delete matrix */
    MatDelete(&gyr_rot);
    MatDelete(&acc_rot);
    MatDelete(&mag_rot);
    MatDelete(&acc_scale);
    MatDelete(&mag_scale);
    MatDelete(&level_rot);
}

/**
 * @brief Initialize sensor offset
 * 
 */
static void offset_init(void)
{
#ifdef SENSOR_USING_IMU0
    float gyr0_offset[] = {
        PARAM_GET_FLOAT(CALIB, GYRO0_XOFF), PARAM_GET_FLOAT(CALIB, GYRO0_YOFF), PARAM_GET_FLOAT(CALIB, GYRO0_ZOFF)
    };
    float acc0_offset[] = {
        PARAM_GET_FLOAT(CALIB, ACC0_XOFF), PARAM_GET_FLOAT(CALIB, ACC0_YOFF), PARAM_GET_FLOAT(CALIB, ACC0_ZOFF)
    };
    /* Set offset */
    sensor_gyr_set_offset(imu0, gyr0_offset);
    sensor_acc_set_offset(imu0, acc0_offset);
#endif

#ifdef SENSOR_USING_IMU1
    float gyr1_offset[] = {
        PARAM_GET_FLOAT(CALIB, GYRO1_XOFF), PARAM_GET_FLOAT(CALIB, GYRO1_YOFF), PARAM_GET_FLOAT(CALIB, GYRO1_ZOFF)
    };
    float acc1_offset[] = {
        PARAM_GET_FLOAT(CALIB, ACC1_XOFF), PARAM_GET_FLOAT(CALIB, ACC1_YOFF), PARAM_GET_FLOAT(CALIB, ACC1_ZOFF)
    };
    /* Set offset */
    sensor_gyr_set_offset(imu1, gyr1_offset);
    sensor_acc_set_offset(imu1, acc1_offset);
#endif

#ifdef SENSOR_USING_MAG0
    float mag0_offset[] = {
        PARAM_GET_FLOAT(CALIB, MAG0_XOFF), PARAM_GET_FLOAT(CALIB, MAG0_YOFF), PARAM_GET_FLOAT(CALIB, MAG0_ZOFF)
    };
    /* Set offset */
    sensor_mag_set_offset(mag0, mag0_offset);
#endif

#ifdef SENSOR_USING_MAG1
    float mag1_offset[] = {
        PARAM_GET_FLOAT(CALIB, MAG1_XOFF), PARAM_GET_FLOAT(CALIB, MAG1_YOFF), PARAM_GET_FLOAT(CALIB, MAG1_ZOFF)
    };
    /* Set offset */
    sensor_mag_set_offset(mag1, mag1_offset);
#endif
}

/**
 * @brief Initialize sensor filter
 * 
 */
static void filter_init(void)
{
    /* 30Hz cut-off frequency, 1000Hz sampling frequency */
    float B[4] = { 0.0007, 0.0021, 0.0021, 0.0007 };
    float A[4] = { 1.0, -2.6236, 2.3147, -0.6855 };

#ifdef SENSOR_USING_IMU0
    butter3_gyr0[0] = butter3_filter_create(B, A);
    butter3_gyr0[1] = butter3_filter_create(B, A);
    butter3_gyr0[2] = butter3_filter_create(B, A);
    RT_ASSERT(butter3_gyr0[0] != NULL);
    RT_ASSERT(butter3_gyr0[1] != NULL);
    RT_ASSERT(butter3_gyr0[2] != NULL);

    butter3_acc0[0] = butter3_filter_create(B, A);
    butter3_acc0[1] = butter3_filter_create(B, A);
    butter3_acc0[2] = butter3_filter_create(B, A);
    RT_ASSERT(butter3_acc0[0] != NULL);
    RT_ASSERT(butter3_acc0[1] != NULL);
    RT_ASSERT(butter3_acc0[2] != NULL);
#endif

#ifdef SENSOR_USING_IMU1
    butter3_gyr1[0] = butter3_filter_create(B, A);
    butter3_gyr1[1] = butter3_filter_create(B, A);
    butter3_gyr1[2] = butter3_filter_create(B, A);
    RT_ASSERT(butter3_gyr1[0] != NULL);
    RT_ASSERT(butter3_gyr1[1] != NULL);
    RT_ASSERT(butter3_gyr1[2] != NULL);

    butter3_acc1[0] = butter3_filter_create(B, A);
    butter3_acc1[1] = butter3_filter_create(B, A);
    butter3_acc1[2] = butter3_filter_create(B, A);
    RT_ASSERT(butter3_acc1[0] != NULL);
    RT_ASSERT(butter3_acc1[1] != NULL);
    RT_ASSERT(butter3_acc1[2] != NULL);
#endif
}

/**
 * @brief Collect sensor data
 * @note Should be invoked periodically. e.g, at 1KHz
 */
void sensor_collect(void)
{
    float temp[3];

    /*
     * Collect imu data
     */
#if defined(SENSOR_USING_IMU0) || defined(SENSOR_USING_IMU1)
    static imu_data_t __imu_data;
    DEFINE_TIMETAG(imu_collect, 1);

    if (check_timetag(TIMETAG(imu_collect))) {
        __imu_data.timestamp_ms = systime_now_ms();

#ifdef SENSOR_USING_IMU0
        if (sensor_gyr_measure(imu0, __imu_data.gyr_B_radDs) == FMT_EOK
            && sensor_acc_measure(imu0, __imu_data.acc_B_mDs2) == FMT_EOK) {
            /* publish scaled imu data without calibration and filtering */
            mcn_publish(MCN_HUB(sensor_imu0_0), &__imu_data);
            /* do calibration */
            sensor_gyr_correct(imu0, __imu_data.gyr_B_radDs, temp);
            __imu_data.gyr_B_radDs[0] = temp[0];
            __imu_data.gyr_B_radDs[1] = temp[1];
            __imu_data.gyr_B_radDs[2] = temp[2];
            sensor_acc_correct(imu0, __imu_data.acc_B_mDs2, temp);
            __imu_data.acc_B_mDs2[0] = temp[0];
            __imu_data.acc_B_mDs2[1] = temp[1];
            __imu_data.acc_B_mDs2[2] = temp[2];
            /* do filtering */
            __imu_data.gyr_B_radDs[0] = butter3_filter_process(__imu_data.gyr_B_radDs[0], butter3_gyr0[0]);
            __imu_data.gyr_B_radDs[1] = butter3_filter_process(__imu_data.gyr_B_radDs[1], butter3_gyr0[1]);
            __imu_data.gyr_B_radDs[2] = butter3_filter_process(__imu_data.gyr_B_radDs[2], butter3_gyr0[2]);
            __imu_data.acc_B_mDs2[0] = butter3_filter_process(__imu_data.acc_B_mDs2[0], butter3_acc0[0]);
            __imu_data.acc_B_mDs2[1] = butter3_filter_process(__imu_data.acc_B_mDs2[1], butter3_acc0[1]);
            __imu_data.acc_B_mDs2[2] = butter3_filter_process(__imu_data.acc_B_mDs2[2], butter3_acc0[2]);
            /* publish calibrated & filtered imu data */
            mcn_publish(MCN_HUB(sensor_imu0), &__imu_data);
        }
#endif

#ifdef SENSOR_USING_IMU1
        if (sensor_gyr_measure(imu1, __imu_data.gyr_B_radDs) == FMT_EOK
            && sensor_acc_measure(imu1, __imu_data.acc_B_mDs2) == FMT_EOK) {
            /* publish scaled imu data without calibration and filtering */
            mcn_publish(MCN_HUB(sensor_imu1_0), &__imu_data);
            /* do calibration */
            sensor_gyr_correct(imu1, __imu_data.gyr_B_radDs, temp);
            __imu_data.gyr_B_radDs[0] = temp[0];
            __imu_data.gyr_B_radDs[1] = temp[1];
            __imu_data.gyr_B_radDs[2] = temp[2];
            sensor_acc_correct(imu1, __imu_data.acc_B_mDs2, temp);
            __imu_data.acc_B_mDs2[0] = temp[0];
            __imu_data.acc_B_mDs2[1] = temp[1];
            __imu_data.acc_B_mDs2[2] = temp[2];
            /* do filtering */
            __imu_data.gyr_B_radDs[0] = butter3_filter_process(__imu_data.gyr_B_radDs[0], butter3_gyr1[0]);
            __imu_data.gyr_B_radDs[1] = butter3_filter_process(__imu_data.gyr_B_radDs[1], butter3_gyr1[1]);
            __imu_data.gyr_B_radDs[2] = butter3_filter_process(__imu_data.gyr_B_radDs[2], butter3_gyr1[2]);
            __imu_data.acc_B_mDs2[0] = butter3_filter_process(__imu_data.acc_B_mDs2[0], butter3_acc1[0]);
            __imu_data.acc_B_mDs2[1] = butter3_filter_process(__imu_data.acc_B_mDs2[1], butter3_acc1[1]);
            __imu_data.acc_B_mDs2[2] = butter3_filter_process(__imu_data.acc_B_mDs2[2], butter3_acc1[2]);
            /* publish calibrated & filtered imu data */
            mcn_publish(MCN_HUB(sensor_imu1), &__imu_data);
        }
#endif
    }
#endif

    /*
     * Collect magnetometer data
     */
#if defined(SENSOR_USING_MAG0) || defined(SENSOR_USING_MAG1)
    static mag_data_t __mag_data;
    DEFINE_TIMETAG(mag_collect, 10);

    if (check_timetag(TIMETAG(mag_collect))) {
        __mag_data.timestamp_ms = systime_now_ms();

#ifdef SENSOR_USING_MAG0
        if (sensor_mag_measure(mag0, __mag_data.mag_B_gauss) == FMT_EOK) {
            mcn_publish(MCN_HUB(sensor_mag0_0), &__mag_data);
            /* do calibration */
            sensor_mag_correct(mag0, __mag_data.mag_B_gauss, temp);
            __mag_data.mag_B_gauss[0] = temp[0];
            __mag_data.mag_B_gauss[1] = temp[1];
            __mag_data.mag_B_gauss[2] = temp[2];
            /* publish calibrated mag data */
            mcn_publish(MCN_HUB(sensor_mag0), &__mag_data);
        }
#endif

#ifdef SENSOR_USING_MAG1
        if (sensor_mag_measure(mag1, __mag_data.mag_B_gauss) == FMT_EOK) {
            mcn_publish(MCN_HUB(sensor_mag1_0), &__mag_data);
            /* do calibration */
            sensor_mag_correct(mag1, __mag_data.mag_B_gauss, temp);
            __mag_data.mag_B_gauss[0] = temp[0];
            __mag_data.mag_B_gauss[1] = temp[1];
            __mag_data.mag_B_gauss[2] = temp[2];
            /* publish calibrated mag data */
            mcn_publish(MCN_HUB(sensor_mag1), &__mag_data);
        }
#endif
    }
#endif

    /*
     * Collect barometer data
     */
#ifdef SENSOR_USING_BAROMETER
    static baro_data_t __baro_data;
    DEFINE_TIMETAG(baro_collect, 5);

    if (check_timetag(TIMETAG(baro_collect))) {
        /* Update barometer state */
        sensor_baro_update(barometer);
        if (sensor_baro_check_ready(barometer)) {
            if (sensor_baro_read(barometer, &__baro_data) == FMT_EOK) {
                /* publish barometer data */
                mcn_publish(MCN_HUB(sensor_baro), &__baro_data);
            }
        }
    }
#endif

    /*
     * Collect gps data
     */
#ifdef SENSOR_USING_GPS
    static gps_data_t __gps_data;

    if (sensor_gps_check_ready(gps)) {
        /* read gps data */
        sensor_gps_read(gps, &__gps_data);
        /* publish gps data */
        mcn_publish(MCN_HUB(sensor_gps), &__gps_data);
    }
#endif
}

/**
 * @brief Initialize sensor hub module
 * 
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t sensor_hub_init(void)
{
#ifdef SENSOR_USING_IMU0
    imu0 = sensor_imu_init("gyro0", "accel0");
    RT_ASSERT(imu0 != NULL);

    FMT_CHECK(mcn_advertise(MCN_HUB(sensor_imu0_0), echo_sensor_imu));
    FMT_CHECK(mcn_advertise(MCN_HUB(sensor_imu0), echo_sensor_imu));
#endif

#ifdef SENSOR_USING_IMU1
    imu1 = sensor_imu_init("gyro1", "accel1");
    RT_ASSERT(imu1 != NULL);

    FMT_CHECK(mcn_advertise(MCN_HUB(sensor_imu1_0), echo_sensor_imu));
    FMT_CHECK(mcn_advertise(MCN_HUB(sensor_imu1), echo_sensor_imu));
#endif

#ifdef SENSOR_USING_MAG0
    mag0 = sensor_mag_init("mag0");
    RT_ASSERT(mag0 != NULL);

    FMT_CHECK(mcn_advertise(MCN_HUB(sensor_mag0_0), echo_sensor_mag));
    FMT_CHECK(mcn_advertise(MCN_HUB(sensor_mag0), echo_sensor_mag));
#endif

#ifdef SENSOR_USING_MAG1
    mag1 = sensor_mag_init("mag1");
    RT_ASSERT(mag1 != NULL);

    FMT_CHECK(mcn_advertise(MCN_HUB(sensor_mag1), echo_sensor_mag));
    FMT_CHECK(mcn_advertise(MCN_HUB(sensor_mag1_0), echo_sensor_mag));
#endif

#ifdef SENSOR_USING_BAROMETER
    barometer = sensor_baro_init("barometer");
    RT_ASSERT(barometer != NULL);

    FMT_CHECK(mcn_advertise(MCN_HUB(sensor_baro), echo_sensor_baro));
#endif

#ifdef SENSOR_USING_GPS
    gps = sensor_gps_init("gps");
    RT_ASSERT(gps != NULL);

    FMT_CHECK(mcn_advertise(MCN_HUB(sensor_gps), echo_sensor_gps));
#endif

    mcn_advertise(MCN_HUB(sensor_optflow), NULL);
    mcn_advertise(MCN_HUB(sensor_rangefinder), NULL);

    /* Initialize sensor rotation matrix */
    rotation_init();
    /* Initialize sensor offset */
    offset_init();
    /* Initialize sensor filter */
    filter_init();

    return FMT_EOK;
}