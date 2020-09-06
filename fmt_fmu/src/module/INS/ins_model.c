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

#include <INS.h>
#include <firmament.h>

#include "module/sensor/sensor_manager.h"
#include "task/task_logger.h"

/* INS output bus */
MCN_DEFINE(ins_output, sizeof(INS_Out_Bus));

/* for input */
MCN_DECLARE(sensor_imu);
MCN_DECLARE(sensor_mag);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);

struct INS_Handler {
    McnNode_t imu_sub_node_t;
    McnNode_t mag_sub_node_t;
    McnNode_t baro_sub_node_t;
    McnNode_t gps_sub_node_t;

    IMU_Report imu_report;
    Mag_Report mag_report;
    Baro_Report baro_report;
    GPS_Report gps_report;

    uint32_t start_time;
    uint8_t imu_updated;
    uint8_t mag_updated;
    uint8_t baro_updated;
    uint8_t gps_updated;
} ins_handle = {
    .start_time = 0,
    .imu_updated = 1, /* log data in the first run */
    .mag_updated = 1,
    .baro_updated = 1,
    .gps_updated = 1
};

static int _ins_output_echo(void* param)
{
    INS_Out_Bus ins_out;

    mcn_copy_from_hub((McnHub*)param, &ins_out);

    console_printf("euler angle(deg) %.2f %.2f %.2f\n", RAF2DEG(ins_out.phi), RAF2DEG(ins_out.theta), RAF2DEG(ins_out.psi));

    return 0;
}

static void _blog_start_cb(void)
{
    ins_handle.imu_updated = 1;
    ins_handle.mag_updated = 1;
    ins_handle.baro_updated = 1;
    ins_handle.gps_updated = 1;
}

void _update_ins_parameter(void)
{
    INS_PARAM.GyroBias[0] = PARAM_GET_FLOAT(CALIB, GYRO0_XOFF);
    INS_PARAM.GyroBias[1] = PARAM_GET_FLOAT(CALIB, GYRO0_YOFF);
    INS_PARAM.GyroBias[2] = PARAM_GET_FLOAT(CALIB, GYRO0_ZOFF);

    INS_PARAM.AccBias[0] = PARAM_GET_FLOAT(CALIB, ACC0_XOFF);
    INS_PARAM.AccBias[1] = PARAM_GET_FLOAT(CALIB, ACC0_YOFF);
    INS_PARAM.AccBias[2] = PARAM_GET_FLOAT(CALIB, ACC0_ZOFF);
    INS_PARAM.AccRotMat[0] = PARAM_GET_FLOAT(CALIB, ACC0_XXSCALE);
    INS_PARAM.AccRotMat[1] = PARAM_GET_FLOAT(CALIB, ACC0_XYSCALE);
    INS_PARAM.AccRotMat[2] = PARAM_GET_FLOAT(CALIB, ACC0_XZSCALE);
    INS_PARAM.AccRotMat[3] = PARAM_GET_FLOAT(CALIB, ACC0_XYSCALE);
    INS_PARAM.AccRotMat[4] = PARAM_GET_FLOAT(CALIB, ACC0_YYSCALE);
    INS_PARAM.AccRotMat[5] = PARAM_GET_FLOAT(CALIB, ACC0_YZSCALE);
    INS_PARAM.AccRotMat[6] = PARAM_GET_FLOAT(CALIB, ACC0_XZSCALE);
    INS_PARAM.AccRotMat[7] = PARAM_GET_FLOAT(CALIB, ACC0_YZSCALE);
    INS_PARAM.AccRotMat[8] = PARAM_GET_FLOAT(CALIB, ACC0_ZZSCALE);

    INS_PARAM.MagBias[0] = PARAM_GET_FLOAT(CALIB, MAG0_XOFF);
    INS_PARAM.MagBias[1] = PARAM_GET_FLOAT(CALIB, MAG0_YOFF);
    INS_PARAM.MagBias[2] = PARAM_GET_FLOAT(CALIB, MAG0_ZOFF);
    INS_PARAM.MagRotMat[0] = PARAM_GET_FLOAT(CALIB, MAG0_XXSCALE);
    INS_PARAM.MagRotMat[1] = PARAM_GET_FLOAT(CALIB, MAG0_XYSCALE);
    INS_PARAM.MagRotMat[2] = PARAM_GET_FLOAT(CALIB, MAG0_XZSCALE);
    INS_PARAM.MagRotMat[3] = PARAM_GET_FLOAT(CALIB, MAG0_XYSCALE);
    INS_PARAM.MagRotMat[4] = PARAM_GET_FLOAT(CALIB, MAG0_YYSCALE);
    INS_PARAM.MagRotMat[5] = PARAM_GET_FLOAT(CALIB, MAG0_YZSCALE);
    INS_PARAM.MagRotMat[6] = PARAM_GET_FLOAT(CALIB, MAG0_XZSCALE);
    INS_PARAM.MagRotMat[7] = PARAM_GET_FLOAT(CALIB, MAG0_YZSCALE);
    INS_PARAM.MagRotMat[8] = PARAM_GET_FLOAT(CALIB, MAG0_ZZSCALE);

    INS_PARAM.USE_EXTERN_FILTER = PARAM_GET_UINT8(INS, USE_EXTERN_FILTER);
}

void ins_model_step(void)
{
    DEFINE_TIMETAG(ins_output, 100);

    uint32_t time_now = systime_now_ms();

    if (ins_handle.start_time == 0) {
        /* record first execution time */
        ins_handle.start_time = time_now;
    }

    /* get sensor data */
    if (mcn_poll(ins_handle.imu_sub_node_t)) {
        mcn_copy(MCN_ID(sensor_imu), ins_handle.imu_sub_node_t, &ins_handle.imu_report);

        INS_U.IMU1.gyr_x = ins_handle.imu_report.gyr_B_radDs[0];
        INS_U.IMU1.gyr_y = ins_handle.imu_report.gyr_B_radDs[1];
        INS_U.IMU1.gyr_z = ins_handle.imu_report.gyr_B_radDs[2];
        INS_U.IMU1.acc_x = ins_handle.imu_report.acc_B_mDs2[0];
        INS_U.IMU1.acc_y = ins_handle.imu_report.acc_B_mDs2[1];
        INS_U.IMU1.acc_z = ins_handle.imu_report.acc_B_mDs2[2];
        INS_U.IMU1.timestamp = time_now - ins_handle.start_time;

        ins_handle.imu_updated = 1;
    }

    if (mcn_poll(ins_handle.mag_sub_node_t)) {
        mcn_copy(MCN_ID(sensor_mag), ins_handle.mag_sub_node_t, &ins_handle.mag_report);

        INS_U.MAG.mag_x = ins_handle.mag_report.mag_B_gauss[0];
        INS_U.MAG.mag_y = ins_handle.mag_report.mag_B_gauss[1];
        INS_U.MAG.mag_z = ins_handle.mag_report.mag_B_gauss[2];
        INS_U.MAG.timestamp = time_now - ins_handle.start_time;

        ins_handle.mag_updated = 1;
    }

    if (mcn_poll(ins_handle.baro_sub_node_t)) {
        mcn_copy(MCN_ID(sensor_baro), ins_handle.baro_sub_node_t, &ins_handle.baro_report);

        INS_U.Barometer.pressure = (float)ins_handle.baro_report.pressure_pa;
        INS_U.Barometer.temperature = ins_handle.baro_report.temperature_deg;
        INS_U.Barometer.timestamp = time_now - ins_handle.start_time;

        ins_handle.baro_updated = 1;
    }

    /* update gps data */
    if (mcn_poll(ins_handle.gps_sub_node_t)) {
        mcn_copy(MCN_ID(sensor_gps), ins_handle.gps_sub_node_t, &ins_handle.gps_report);

        INS_U.GPS_uBlox.fixType = ins_handle.gps_report.fixType;
        INS_U.GPS_uBlox.lat = ins_handle.gps_report.lat;
        INS_U.GPS_uBlox.lon = ins_handle.gps_report.lon;
        INS_U.GPS_uBlox.height = ins_handle.gps_report.height;
        INS_U.GPS_uBlox.velN = (int32_t)(ins_handle.gps_report.velN * 1e3);
        INS_U.GPS_uBlox.velE = (int32_t)(ins_handle.gps_report.velE * 1e3);
        INS_U.GPS_uBlox.velD = (int32_t)(ins_handle.gps_report.velD * 1e3);
        INS_U.GPS_uBlox.hAcc = (uint32_t)(ins_handle.gps_report.hAcc * 1e3);
        INS_U.GPS_uBlox.vAcc = (uint32_t)(ins_handle.gps_report.vAcc * 1e3);
        INS_U.GPS_uBlox.sAcc = (uint32_t)(ins_handle.gps_report.sAcc * 1e3);
        INS_U.GPS_uBlox.numSV = ins_handle.gps_report.numSV;
        INS_U.GPS_uBlox.timestamp = time_now - ins_handle.start_time;

        ins_handle.gps_updated = 1;
    }

    /* run INS */
    INS_step();

    /* publish INS output */
    mcn_publish(MCN_ID(ins_output), &INS_Y.INS_Out);

    /* record INS input bus data if updated */
    if (ins_handle.imu_updated) {
        /* Log IMU data if IMU updated */
        if (blog_push_msg((uint8_t*)&INS_U.IMU1, BLOG_IMU_ID, sizeof(INS_U.IMU1)) == FMT_EOK) {
            ins_handle.imu_updated = 0;
        }
    }

    if (ins_handle.mag_updated) {
        /* Log Magnetometer data */
        if (blog_push_msg((uint8_t*)&INS_U.MAG, BLOG_MAG_ID, sizeof(INS_U.MAG)) == FMT_EOK) {
            ins_handle.mag_updated = 0;
        }
    }

    if (ins_handle.baro_updated) {
        /* Log Barometer data */
        if (blog_push_msg((uint8_t*)&INS_U.Barometer, BLOG_BARO_ID, sizeof(INS_U.Barometer)) == FMT_EOK) {
            ins_handle.baro_updated = 0;
        }
    }

    if (ins_handle.gps_updated) {
        /* Log GPS data */
        if (blog_push_msg((uint8_t*)&INS_U.GPS_uBlox, BLOG_GPS_ID, sizeof(INS_U.GPS_uBlox)) == FMT_EOK) {
            ins_handle.gps_updated = 0;
        }
    }

    /* Log INS output bus data */
    if (check_timetag(TIMETAG(ins_output))) {
        /* rewrite timestmp */
        INS_Y.INS_Out.timestamp = time_now - ins_handle.start_time;
        /* Log INS out data */
        blog_push_msg((uint8_t*)&INS_Y.INS_Out, BLOG_INS_OUT_ID, sizeof(INS_Y.INS_Out));
    }
}

void ins_model_init(void)
{
    mcn_advertise(MCN_ID(ins_output), _ins_output_echo);

    ins_handle.imu_sub_node_t = mcn_subscribe(MCN_ID(sensor_imu), NULL, NULL);
    ins_handle.mag_sub_node_t = mcn_subscribe(MCN_ID(sensor_mag), NULL, NULL);
    ins_handle.baro_sub_node_t = mcn_subscribe(MCN_ID(sensor_baro), NULL, NULL);
    ins_handle.gps_sub_node_t = mcn_subscribe(MCN_ID(sensor_gps), NULL, NULL);

    blog_register_callback(BLOG_CB_START, _blog_start_cb);

    INS_init();

    _update_ins_parameter();

    INS_U.reset = 0;
}
