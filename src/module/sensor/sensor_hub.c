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
#include "module/math/rotation.h"
#include "module/sensor/sensor_airspeed.h"
#include "module/sensor/sensor_baro.h"
#include "module/sensor/sensor_gps.h"
#include "module/sensor/sensor_hub.h"
#include "module/sensor/sensor_imu.h"
#include "module/sensor/sensor_mag.h"

#define MAX_IMU_DEV_NUM 2
#define MAX_MAG_DEV_NUM 2

MCN_DEFINE(sensor_imu0_0, sizeof(imu_data_t));
MCN_DEFINE(sensor_imu0, sizeof(imu_data_t));

MCN_DEFINE(sensor_imu1_0, sizeof(imu_data_t));
MCN_DEFINE(sensor_imu1, sizeof(imu_data_t));

MCN_DEFINE(sensor_mag0_0, sizeof(mag_data_t));
MCN_DEFINE(sensor_mag0, sizeof(mag_data_t));

MCN_DEFINE(sensor_mag1_0, sizeof(mag_data_t));
MCN_DEFINE(sensor_mag1, sizeof(mag_data_t));

MCN_DEFINE(sensor_baro, sizeof(baro_data_t));

MCN_DEFINE(sensor_airspeed, sizeof(airspeed_data_t));

MCN_DEFINE(sensor_gps, sizeof(gps_data_t));

MCN_DEFINE(sensor_optflow, sizeof(optflow_data_t));

MCN_DEFINE(sensor_rangefinder, sizeof(rf_data_t));

static sensor_imu_t imu_dev[MAX_IMU_DEV_NUM] = { NULL };
static sensor_mag_t mag_dev[MAX_MAG_DEV_NUM] = { NULL };
static sensor_baro_t baro_dev = NULL;
static sensor_gps_t gps_dev = NULL;
static sensor_airspeed_t airspeed_dev = NULL;

static Butter3* butter3_gyr[MAX_IMU_DEV_NUM][3];
static Butter3* butter3_acc[MAX_IMU_DEV_NUM][3];

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
                   imu_report.gyr_B_radDs[0],
                   imu_report.gyr_B_radDs[1],
                   imu_report.gyr_B_radDs[2],
                   imu_report.acc_B_mDs2[0],
                   imu_report.acc_B_mDs2[1],
                   imu_report.acc_B_mDs2[2]);

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
                   mag_report.mag_B_gauss[0],
                   mag_report.mag_B_gauss[1],
                   mag_report.mag_B_gauss[2]);

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

    console_printf("timestamp:%u pressure:%.2f temperature:%.2f altitude:%.2f\n",
                   baro_report.timestamp_ms,
                   baro_report.pressure_pa,
                   baro_report.temperature_deg,
                   baro_report.altitude_m);

    return 0;
}

static int echo_sensor_airspeed(void* param)
{
    fmt_err_t err;
    airspeed_data_t airspeed_report;

    err = mcn_copy_from_hub((McnHub*)param, &airspeed_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("timestamp:%u diff_pressure:%f temperature:%f\n",
                   airspeed_report.timestamp_ms,
                   airspeed_report.diff_pressure_pa,
                   airspeed_report.temperature_deg);

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

    console_printf("lon:%d lat:%d alt:%d fixType:%d numSV:%d hAcc:%.2f vAcc:%.2f sAcc:%.2f\n", gps_report.lon, gps_report.lat, gps_report.height, gps_report.fixType, gps_report.numSV, gps_report.hAcc, gps_report.vAcc, gps_report.sAcc);

    return 0;
}

static int echo_sensor_optflow(void* param)
{
    optflow_data_t optflow_report;

    if (mcn_copy_from_hub((McnHub*)param, &optflow_report) != FMT_EOK) {
        return -1;
    }

    console_printf("timestsamp:%u vx:%.2f vy:%.2f quality:%d\n", optflow_report.timestamp_ms, optflow_report.vx_mPs, optflow_report.vy_mPs, optflow_report.quality);

    return 0;
}

static int echo_sensor_rangefinder(void* param)
{
    rf_data_t rf_report;

    if (mcn_copy_from_hub((McnHub*)param, &rf_report) != FMT_EOK) {
        return -1;
    }

    console_printf("timestamp:%u distance:%.2f\n", rf_report.timestamp_ms, rf_report.distance_m);

    return 0;
}

static void imu_rotation_init(uint8_t id)
{
    Mat level_rot;
    Mat gyr_rot;
    Mat acc_rot, acc_scale;
    float val_level_rot[9];
    float level_rpy[] = {
        PARAM_GET_FLOAT(CALIB, LEVEL_XOFF), PARAM_GET_FLOAT(CALIB, LEVEL_YOFF), PARAM_GET_FLOAT(CALIB, LEVEL_ZOFF)
    };

    /* Create Matrix */
    MatCreate(&gyr_rot, 3, 3);
    MatCreate(&acc_scale, 3, 3);
    MatCreate(&level_rot, 3, 3);
    MatCreate(&acc_rot, 3, 3);

    /* Get level calibration dcm */
    dcm_from_euler(level_rpy, val_level_rot);

    /* Init matrix value */
    MatSetVal(&level_rot, val_level_rot);
    MatSetVal(&gyr_rot, val_level_rot);

    if (id == 0) {
        float val_acc0_scale[] = {
            PARAM_GET_FLOAT(CALIB, ACC0_XXSCALE), PARAM_GET_FLOAT(CALIB, ACC0_XYSCALE), PARAM_GET_FLOAT(CALIB, ACC0_XZSCALE), PARAM_GET_FLOAT(CALIB, ACC0_XYSCALE), PARAM_GET_FLOAT(CALIB, ACC0_YYSCALE), PARAM_GET_FLOAT(CALIB, ACC0_YZSCALE), PARAM_GET_FLOAT(CALIB, ACC0_XZSCALE), PARAM_GET_FLOAT(CALIB, ACC0_YZSCALE), PARAM_GET_FLOAT(CALIB, ACC0_ZZSCALE)
        };
        /* calculate rotation matrix */
        MatSetVal(&acc_scale, val_acc0_scale);
        MatMul(&level_rot, &acc_scale, &acc_rot);
        /* set rotation */
        sensor_gyr_set_rotation(imu_dev[id], gyr_rot.buffer);
        sensor_acc_set_rotation(imu_dev[id], acc_rot.buffer);
    } else if (id == 1) {
        float val_acc1_scale[] = {
            PARAM_GET_FLOAT(CALIB, ACC1_XXSCALE), PARAM_GET_FLOAT(CALIB, ACC1_XYSCALE), PARAM_GET_FLOAT(CALIB, ACC1_XZSCALE), PARAM_GET_FLOAT(CALIB, ACC1_XYSCALE), PARAM_GET_FLOAT(CALIB, ACC1_YYSCALE), PARAM_GET_FLOAT(CALIB, ACC1_YZSCALE), PARAM_GET_FLOAT(CALIB, ACC1_XZSCALE), PARAM_GET_FLOAT(CALIB, ACC1_YZSCALE), PARAM_GET_FLOAT(CALIB, ACC1_ZZSCALE)
        };
        /* calculate rotation matrix */
        MatSetVal(&acc_scale, val_acc1_scale);
        MatMul(&level_rot, &acc_scale, &acc_rot);
        /* set rotation */
        sensor_gyr_set_rotation(imu_dev[id], gyr_rot.buffer);
        sensor_acc_set_rotation(imu_dev[id], acc_rot.buffer);
    } else {
        RT_ASSERT(false);
    }

    /* Delete matrix */
    MatDelete(&gyr_rot);
    MatDelete(&acc_rot);
    MatDelete(&acc_scale);
    MatDelete(&level_rot);
}

static void mag_rotation_init(uint8_t id)
{
    Mat level_rot;
    Mat mag_rot, mag_scale;
    float val_level_rot[9];
    float level_rpy[] = {
        PARAM_GET_FLOAT(CALIB, LEVEL_XOFF), PARAM_GET_FLOAT(CALIB, LEVEL_YOFF), PARAM_GET_FLOAT(CALIB, LEVEL_ZOFF)
    };

    /* Create Matrix */
    MatCreate(&mag_scale, 3, 3);
    MatCreate(&level_rot, 3, 3);
    MatCreate(&mag_rot, 3, 3);

    /* Get level calibration dcm */
    dcm_from_euler(level_rpy, val_level_rot);

    /* Init matrix value */
    MatSetVal(&level_rot, val_level_rot);

    if (id == 0) {
        float val_mag0_scale[] = {
            PARAM_GET_FLOAT(CALIB, MAG0_XXSCALE), PARAM_GET_FLOAT(CALIB, MAG0_XYSCALE), PARAM_GET_FLOAT(CALIB, MAG0_XZSCALE), PARAM_GET_FLOAT(CALIB, MAG0_XYSCALE), PARAM_GET_FLOAT(CALIB, MAG0_YYSCALE), PARAM_GET_FLOAT(CALIB, MAG0_YZSCALE), PARAM_GET_FLOAT(CALIB, MAG0_XZSCALE), PARAM_GET_FLOAT(CALIB, MAG0_YZSCALE), PARAM_GET_FLOAT(CALIB, MAG0_ZZSCALE)
        };
        /* Calculate rotation matrix */
        MatSetVal(&mag_scale, val_mag0_scale);
        MatMul(&level_rot, &mag_scale, &mag_rot);
        /* Set rotation */
        sensor_mag_set_rotation(mag_dev[id], mag_rot.buffer);
    } else if (id == 1) {
        float val_mag1_scale[] = {
            PARAM_GET_FLOAT(CALIB, MAG1_XXSCALE), PARAM_GET_FLOAT(CALIB, MAG1_XYSCALE), PARAM_GET_FLOAT(CALIB, MAG1_XZSCALE), PARAM_GET_FLOAT(CALIB, MAG1_XYSCALE), PARAM_GET_FLOAT(CALIB, MAG1_YYSCALE), PARAM_GET_FLOAT(CALIB, MAG1_YZSCALE), PARAM_GET_FLOAT(CALIB, MAG1_XZSCALE), PARAM_GET_FLOAT(CALIB, MAG1_YZSCALE), PARAM_GET_FLOAT(CALIB, MAG1_ZZSCALE)
        };
        /* Calculate rotation matrix */
        MatSetVal(&mag_scale, val_mag1_scale);
        MatMul(&level_rot, &mag_scale, &mag_rot);
        /* Set rotation */
        sensor_mag_set_rotation(mag_dev[id], mag_rot.buffer);
    } else {
        RT_ASSERT(false);
    }

    /* Delete matrix */
    MatDelete(&mag_rot);
    MatDelete(&mag_scale);
    MatDelete(&level_rot);
}

static void imu_offset_init(uint8_t id)
{
    if (id == 0) {
        float gyr0_offset[] = {
            PARAM_GET_FLOAT(CALIB, GYRO0_XOFF), PARAM_GET_FLOAT(CALIB, GYRO0_YOFF), PARAM_GET_FLOAT(CALIB, GYRO0_ZOFF)
        };
        float acc0_offset[] = {
            PARAM_GET_FLOAT(CALIB, ACC0_XOFF), PARAM_GET_FLOAT(CALIB, ACC0_YOFF), PARAM_GET_FLOAT(CALIB, ACC0_ZOFF)
        };
        /* Set offset */
        sensor_gyr_set_offset(imu_dev[id], gyr0_offset);
        sensor_acc_set_offset(imu_dev[id], acc0_offset);
    } else if (id == 1) {
        float gyr1_offset[] = {
            PARAM_GET_FLOAT(CALIB, GYRO1_XOFF), PARAM_GET_FLOAT(CALIB, GYRO1_YOFF), PARAM_GET_FLOAT(CALIB, GYRO1_ZOFF)
        };
        float acc1_offset[] = {
            PARAM_GET_FLOAT(CALIB, ACC1_XOFF), PARAM_GET_FLOAT(CALIB, ACC1_YOFF), PARAM_GET_FLOAT(CALIB, ACC1_ZOFF)
        };
        /* Set offset */
        sensor_gyr_set_offset(imu_dev[id], gyr1_offset);
        sensor_acc_set_offset(imu_dev[id], acc1_offset);
    } else {
        RT_ASSERT(false);
    }
}

static void mag_offset_init(uint8_t id)
{
    if (id == 0) {
        float mag0_offset[] = {
            PARAM_GET_FLOAT(CALIB, MAG0_XOFF), PARAM_GET_FLOAT(CALIB, MAG0_YOFF), PARAM_GET_FLOAT(CALIB, MAG0_ZOFF)
        };
        /* Set offset */
        sensor_mag_set_offset(mag_dev[id], mag0_offset);
    } else if (id == 1) {
        float mag1_offset[] = {
            PARAM_GET_FLOAT(CALIB, MAG1_XOFF), PARAM_GET_FLOAT(CALIB, MAG1_YOFF), PARAM_GET_FLOAT(CALIB, MAG1_ZOFF)
        };
        /* Set offset */
        sensor_mag_set_offset(mag_dev[id], mag1_offset);
    } else {
        RT_ASSERT(false);
    }
}

static void imu_filter_init(uint8_t id)
{
    RT_ASSERT(id < MAX_IMU_DEV_NUM);

    /* 30Hz cut-off frequency, 1000Hz sampling frequency */
    float B1[4] = { 0.0007, 0.0021, 0.0021, 0.0007 };
    float A1[4] = { 1.0, -2.6236, 2.3147, -0.6855 };

    /* 15Hz cut-off frequency, 1000Hz sampling frequency */
    float B2[4] = { 0.0000954, 0.0002863, 0.0002863, 0.0000954 };
    float A2[4] = { 1.0000, -2.8116, 2.6405, -0.8281 };

    butter3_gyr[id][0] = butter3_filter_create(B1, A1);
    butter3_gyr[id][1] = butter3_filter_create(B1, A1);
    butter3_gyr[id][2] = butter3_filter_create(B1, A1);
    RT_ASSERT(butter3_gyr[id][0] != NULL);
    RT_ASSERT(butter3_gyr[id][1] != NULL);
    RT_ASSERT(butter3_gyr[id][2] != NULL);

    butter3_acc[id][0] = butter3_filter_create(B2, A2);
    butter3_acc[id][1] = butter3_filter_create(B2, A2);
    butter3_acc[id][2] = butter3_filter_create(B2, A2);
    RT_ASSERT(butter3_acc[id][0] != NULL);
    RT_ASSERT(butter3_acc[id][1] != NULL);
    RT_ASSERT(butter3_acc[id][2] != NULL);
}

static void mag_filter_init(uint8_t id)
{
    /* do nothing */
}

/**
 * @brief Advertise sensor imu topic
 * 
 * @param id sensor id
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t advertise_sensor_imu(uint8_t id)
{
    switch (id) {
    case 0:
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_imu0_0), echo_sensor_imu));
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_imu0), echo_sensor_imu));
        break;
    case 1:
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_imu1_0), echo_sensor_imu));
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_imu1), echo_sensor_imu));
        break;
    default:
        return FMT_EINVAL;
    }

    return FMT_EOK;
}

/**
 * @brief Advertise sensor mag topic
 * 
 * @param id sensor id
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t advertise_sensor_mag(uint8_t id)
{
    switch (id) {
    case 0:
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_mag0_0), echo_sensor_mag));
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_mag0), echo_sensor_mag));
        break;
    case 1:
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_mag1_0), echo_sensor_mag));
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_mag1), echo_sensor_mag));
        break;
    default:
        return FMT_EINVAL;
    }

    return FMT_EOK;
}

/**
 * @brief Advertise sensor barometer topic
 * 
 * @param id sensor topic
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t advertise_sensor_baro(uint8_t id)
{
    switch (id) {
    case 0:
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_baro), echo_sensor_baro));
        break;
    default:
        return FMT_EINVAL;
    }

    return FMT_EOK;
}

/**
 * @brief Advertise sensor airspeed topic
 * 
 * @param id sensor topic
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t advertise_sensor_airspeed(uint8_t id)
{
    switch (id) {
    case 0:
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_airspeed), echo_sensor_airspeed));
        break;
    default:
        return FMT_EINVAL;
    }

    return FMT_EOK;
}

/**
 * @brief Advertise sensor gps topic
 * 
 * @param id sensor topic
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t advertise_sensor_gps(uint8_t id)
{
    switch (id) {
    case 0:
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_gps), echo_sensor_gps));
        break;
    default:
        return FMT_EINVAL;
    }

    return FMT_EOK;
}

/**
 * @brief Advertise sensor optical flow topic
 * 
 * @param id sensor topic
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t advertise_sensor_optflow(uint8_t id)
{
    switch (id) {
    case 0:
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_optflow), echo_sensor_optflow));
        break;
    default:
        return FMT_EINVAL;
    }

    return FMT_EOK;
}

/**
 * @brief Advertise sensor range finder topic
 * 
 * @param id sensor topic
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t advertise_sensor_rangefinder(uint8_t id)
{
    switch (id) {
    case 0:
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_rangefinder), echo_sensor_rangefinder));
        break;
    default:
        return FMT_EINVAL;
    }

    return FMT_EOK;
}

/**
 * @brief Register imu sensor
 * 
 * @param gyr_dev_name Gyroscope device name
 * @param acc_dev_name Accelerometer device name
 * @param id Sensor id to be registered, start from 0
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t register_sensor_imu(const char* gyr_dev_name, const char* acc_dev_name, uint8_t id)
{
    RT_ASSERT(id < MAX_IMU_DEV_NUM);

    imu_dev[id] = sensor_imu_init(gyr_dev_name, acc_dev_name);
    if (imu_dev[id] == NULL) {
        return FMT_ERROR;
    }

    /* Initialize imu rotation matrix */
    imu_rotation_init(id);
    /* Initialize imu offset */
    imu_offset_init(id);
    /* Initialize imu filter */
    imu_filter_init(id);

    return advertise_sensor_imu(id);
}

/**
 * @brief Register magnetometer sensor
 * 
 * @param dev_name Magnetometer device name
 * @param id Sensor id to be registered, start from 0
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t register_sensor_mag(const char* dev_name, uint8_t id)
{
    RT_ASSERT(id < MAX_MAG_DEV_NUM);

    mag_dev[id] = sensor_mag_init(dev_name);
    if (mag_dev[id] == NULL) {
        return FMT_ERROR;
    }

    /* Initialize mag rotation matrix */
    mag_rotation_init(id);
    /* Initialize mag offset */
    mag_offset_init(id);
    /* Initialize mag filter */
    mag_filter_init(id);

    return advertise_sensor_mag(id);
}

/**
 * @brief Register barometer sensor
 * 
 * @param dev_name Barometer device name
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t register_sensor_barometer(const char* dev_name)
{
    baro_dev = sensor_baro_init(dev_name);
    if (baro_dev == NULL) {
        return FMT_ERROR;
    }

    return advertise_sensor_baro(0);
}

/**
 * @brief Register gps sensor
 * 
 * @param dev_name GPS device name
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t register_sensor_gps(const char* dev_name)
{
    gps_dev = sensor_gps_init(dev_name);
    if (gps_dev == NULL) {
        return FMT_ERROR;
    }

    return advertise_sensor_gps(0);
}

fmt_err_t register_sensor_optflow(const char* dev_name)
{
    //TODO
    FMT_TRY(mcn_advertise(MCN_HUB(sensor_optflow), NULL));
    return FMT_EOK;
}

fmt_err_t register_sensor_rangefinder(const char* dev_name)
{
    //TODO
    FMT_TRY(mcn_advertise(MCN_HUB(sensor_rangefinder), NULL));
    return FMT_EOK;
}

/**
 * @brief Register airspeed sensor
 * 
 * @param dev_name Airspeed device name
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t register_sensor_airspeed(const char* dev_name)
{
    airspeed_dev = sensor_airspeed_init(dev_name);
    if (airspeed_dev == NULL) {
        return FMT_ERROR;
    }

    return advertise_sensor_airspeed(0);
}

/**
 * @brief Collect sensor data
 * @note Should be invoked periodically. e.g, at 1KHz
 */
void sensor_collect(void)
{
    float temp[3];
    enum Rotation board_rot = PARAM_GET_UINT8(CALIB, SENS_BOARD_ROT);

    /*
     * Collect imu data
     */
    imu_data_t imu_data;
    DEFINE_TIMETAG(imu_interval, 1);

    if (check_timetag(TIMETAG(imu_interval))) {
        imu_data.timestamp_ms = systime_now_ms();

        /* Collect imu0 data */
        if (imu_dev[0] != NULL) {
            if (sensor_gyr_measure(imu_dev[0], imu_data.gyr_B_radDs) == FMT_EOK
                && sensor_acc_measure(imu_dev[0], imu_data.acc_B_mDs2) == FMT_EOK) {
                /* publish scaled imu data without calibration and filtering */
                mcn_publish(MCN_HUB(sensor_imu0_0), &imu_data);
                /* do calibration */
                sensor_gyr_correct(imu_dev[0], imu_data.gyr_B_radDs, temp);
                imu_data.gyr_B_radDs[0] = temp[0];
                imu_data.gyr_B_radDs[1] = temp[1];
                imu_data.gyr_B_radDs[2] = temp[2];
                sensor_acc_correct(imu_dev[0], imu_data.acc_B_mDs2, temp);
                imu_data.acc_B_mDs2[0] = temp[0];
                imu_data.acc_B_mDs2[1] = temp[1];
                imu_data.acc_B_mDs2[2] = temp[2];
                /* do filtering */
                imu_data.gyr_B_radDs[0] = butter3_filter_process(imu_data.gyr_B_radDs[0], butter3_gyr[0][0]);
                imu_data.gyr_B_radDs[1] = butter3_filter_process(imu_data.gyr_B_radDs[1], butter3_gyr[0][1]);
                imu_data.gyr_B_radDs[2] = butter3_filter_process(imu_data.gyr_B_radDs[2], butter3_gyr[0][2]);
                imu_data.acc_B_mDs2[0] = butter3_filter_process(imu_data.acc_B_mDs2[0], butter3_acc[0][0]);
                imu_data.acc_B_mDs2[1] = butter3_filter_process(imu_data.acc_B_mDs2[1], butter3_acc[0][1]);
                imu_data.acc_B_mDs2[2] = butter3_filter_process(imu_data.acc_B_mDs2[2], butter3_acc[0][2]);
                /* do board rotation */
                rotation(board_rot, &imu_data.gyr_B_radDs[0], &imu_data.gyr_B_radDs[1], &imu_data.gyr_B_radDs[2]);
                rotation(board_rot, &imu_data.acc_B_mDs2[0], &imu_data.acc_B_mDs2[1], &imu_data.acc_B_mDs2[2]);
                /* publish calibrated & filtered imu data */
                mcn_publish(MCN_HUB(sensor_imu0), &imu_data);
            }
        }

        /* Collect imu1 data */
        if (imu_dev[1] != NULL) {
            if (sensor_gyr_measure(imu_dev[1], imu_data.gyr_B_radDs) == FMT_EOK
                && sensor_acc_measure(imu_dev[1], imu_data.acc_B_mDs2) == FMT_EOK) {
                /* publish scaled imu data without calibration and filtering */
                mcn_publish(MCN_HUB(sensor_imu1_0), &imu_data);
                /* do calibration */
                sensor_gyr_correct(imu_dev[1], imu_data.gyr_B_radDs, temp);
                imu_data.gyr_B_radDs[0] = temp[0];
                imu_data.gyr_B_radDs[1] = temp[1];
                imu_data.gyr_B_radDs[2] = temp[2];
                sensor_acc_correct(imu_dev[1], imu_data.acc_B_mDs2, temp);
                imu_data.acc_B_mDs2[0] = temp[0];
                imu_data.acc_B_mDs2[1] = temp[1];
                imu_data.acc_B_mDs2[2] = temp[2];
                /* do filtering */
                imu_data.gyr_B_radDs[0] = butter3_filter_process(imu_data.gyr_B_radDs[0], butter3_gyr[1][0]);
                imu_data.gyr_B_radDs[1] = butter3_filter_process(imu_data.gyr_B_radDs[1], butter3_gyr[1][1]);
                imu_data.gyr_B_radDs[2] = butter3_filter_process(imu_data.gyr_B_radDs[2], butter3_gyr[1][2]);
                imu_data.acc_B_mDs2[0] = butter3_filter_process(imu_data.acc_B_mDs2[0], butter3_acc[1][0]);
                imu_data.acc_B_mDs2[1] = butter3_filter_process(imu_data.acc_B_mDs2[1], butter3_acc[1][1]);
                imu_data.acc_B_mDs2[2] = butter3_filter_process(imu_data.acc_B_mDs2[2], butter3_acc[1][2]);
                /* do board rotation */
                rotation(board_rot, &imu_data.gyr_B_radDs[0], &imu_data.gyr_B_radDs[1], &imu_data.gyr_B_radDs[2]);
                rotation(board_rot, &imu_data.acc_B_mDs2[0], &imu_data.acc_B_mDs2[1], &imu_data.acc_B_mDs2[2]);
                /* publish calibrated & filtered imu data */
                mcn_publish(MCN_HUB(sensor_imu1), &imu_data);
            }
        }
    }

    /*
     * Collect magnetometer data
     */
    mag_data_t mag_data;
    DEFINE_TIMETAG(mag_interval, 10);

    if (check_timetag(TIMETAG(mag_interval))) {
        mag_data.timestamp_ms = systime_now_ms();

        /* Collect mag0 data */
        if (mag_dev[0] != NULL) {
            if (sensor_mag_measure(mag_dev[0], mag_data.mag_B_gauss) == FMT_EOK) {
                mcn_publish(MCN_HUB(sensor_mag0_0), &mag_data);
                /* do calibration */
                sensor_mag_correct(mag_dev[0], mag_data.mag_B_gauss, temp);
                mag_data.mag_B_gauss[0] = temp[0];
                mag_data.mag_B_gauss[1] = temp[1];
                mag_data.mag_B_gauss[2] = temp[2];
                /* do board rotation */
                rotation(board_rot, &mag_data.mag_B_gauss[0], &mag_data.mag_B_gauss[1], &mag_data.mag_B_gauss[2]);
                /* publish calibrated mag data */
                mcn_publish(MCN_HUB(sensor_mag0), &mag_data);
            }
        }

        /* Collect mag1 data */
        if (mag_dev[1] != NULL) {
            if (sensor_mag_measure(mag_dev[1], mag_data.mag_B_gauss) == FMT_EOK) {
                mcn_publish(MCN_HUB(sensor_mag1_0), &mag_data);
                /* do calibration */
                sensor_mag_correct(mag_dev[1], mag_data.mag_B_gauss, temp);
                mag_data.mag_B_gauss[0] = temp[0];
                mag_data.mag_B_gauss[1] = temp[1];
                mag_data.mag_B_gauss[2] = temp[2];
                /* do board rotation */
                rotation(board_rot, &mag_data.mag_B_gauss[0], &mag_data.mag_B_gauss[1], &mag_data.mag_B_gauss[2]);
                /* publish calibrated mag data */
                mcn_publish(MCN_HUB(sensor_mag1), &mag_data);
            }
        }
    }

    /*
     * Collect barometer data
     */
    baro_data_t baro_data;
    if (baro_dev != NULL) {
        if (sensor_baro_check_ready(baro_dev)) {
            if (sensor_baro_read(baro_dev, &baro_data) == FMT_EOK) {
                /* publish barometer data */
                mcn_publish(MCN_HUB(sensor_baro), &baro_data);
            }
        }
    }

    /*
     * Collect gps data
     */
    gps_data_t gps_data;
    if (gps_dev != NULL) {
        if (sensor_gps_check_ready(gps_dev)) {
            /* read gps data */
            sensor_gps_read(gps_dev, &gps_data);
            /* publish gps data */
            mcn_publish(MCN_HUB(sensor_gps), &gps_data);
        }
    }

    /*
     * Collect airspeed data
     */
    airspeed_data_t airspeed_data;
    DEFINE_TIMETAG(airspeed_interval, 10);

    if (check_timetag(TIMETAG(airspeed_interval))) {
        if (airspeed_dev != NULL) {
            if (sensor_airspeed_measure(airspeed_dev, &airspeed_data) == FMT_EOK) {
                /* publish barometer data */
                mcn_publish(MCN_HUB(sensor_airspeed), &airspeed_data);
            }
        }
    }
}
