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

#include "module/sensor/sensor_hub.h"
// #include "task/task_logger.h"

/* INS output bus */
MCN_DEFINE(ins_output, sizeof(INS_Out_Bus));

/* INS input bus */
MCN_DECLARE(sensor_imu0);
MCN_DECLARE(sensor_mag0);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(sensor_rangefinder);
MCN_DECLARE(sensor_optflow);

struct INS_Handler {
    McnNode_t imu_sub_node_t;
    McnNode_t mag_sub_node_t;
    McnNode_t baro_sub_node_t;
    McnNode_t gps_sub_node_t;
    McnNode_t rf_sub_node_t;
    McnNode_t optflow_sub_node_t;

    imu_data_t imu_report;
    mag_data_t mag_report;
    baro_data_t baro_report;
    gps_data_t gps_report;
    rf_data_t rf_report;
    optflow_data_t optflow_report;

    uint32_t start_time;
    uint8_t imu_updated;
    uint8_t mag_updated;
    uint8_t baro_updated;
    uint8_t gps_updated;
    uint8_t rf_updated;
    uint8_t optflow_updated;
} ins_handle = {
    .start_time = 0,
    .imu_updated = 1, /* log data in the first run */
    .mag_updated = 1,
    .baro_updated = 1,
    .gps_updated = 1,
    .rf_updated = 1,
    .optflow_updated = 1
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
        mcn_copy(MCN_HUB(sensor_imu0), ins_handle.imu_sub_node_t, &ins_handle.imu_report);

        INS_U.IMU.gyr_x = ins_handle.imu_report.gyr_B_radDs[0];
        INS_U.IMU.gyr_y = ins_handle.imu_report.gyr_B_radDs[1];
        INS_U.IMU.gyr_z = ins_handle.imu_report.gyr_B_radDs[2];
        INS_U.IMU.acc_x = ins_handle.imu_report.acc_B_mDs2[0];
        INS_U.IMU.acc_y = ins_handle.imu_report.acc_B_mDs2[1];
        INS_U.IMU.acc_z = ins_handle.imu_report.acc_B_mDs2[2];
        INS_U.IMU.timestamp = time_now - ins_handle.start_time;

        ins_handle.imu_updated = 1;
    }

    if (mcn_poll(ins_handle.mag_sub_node_t)) {
        mcn_copy(MCN_HUB(sensor_mag0), ins_handle.mag_sub_node_t, &ins_handle.mag_report);

        INS_U.MAG.mag_x = ins_handle.mag_report.mag_B_gauss[0];
        INS_U.MAG.mag_y = ins_handle.mag_report.mag_B_gauss[1];
        INS_U.MAG.mag_z = ins_handle.mag_report.mag_B_gauss[2];
        INS_U.MAG.timestamp = time_now - ins_handle.start_time;

        ins_handle.mag_updated = 1;
    }

    if (mcn_poll(ins_handle.baro_sub_node_t)) {
        mcn_copy(MCN_HUB(sensor_baro), ins_handle.baro_sub_node_t, &ins_handle.baro_report);

        INS_U.Barometer.pressure = (float)ins_handle.baro_report.pressure_pa;
        INS_U.Barometer.temperature = ins_handle.baro_report.temperature_deg;
        INS_U.Barometer.timestamp = time_now - ins_handle.start_time;

        ins_handle.baro_updated = 1;
    }

    /* update gps data */
    if (mcn_poll(ins_handle.gps_sub_node_t)) {
        mcn_copy(MCN_HUB(sensor_gps), ins_handle.gps_sub_node_t, &ins_handle.gps_report);

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

    /* update rangefinder data */
    if (mcn_poll(ins_handle.rf_sub_node_t)) {
        mcn_copy(MCN_HUB(sensor_rangefinder), ins_handle.rf_sub_node_t, &ins_handle.rf_report);

        // INS_U.Rangefinder.distance_m = ins_handle.rf_report.distance_m;
        // INS_U.Rangefinder.timestamp = time_now - ins_handle.start_time;

        ins_handle.rf_updated = 1;
    }

    /* update optical flow data */
    if (mcn_poll(ins_handle.optflow_sub_node_t)) {
        mcn_copy(MCN_HUB(sensor_optflow), ins_handle.optflow_sub_node_t, &ins_handle.optflow_report);

        ins_handle.optflow_updated = 1;
    }

    /* run INS */
    INS_step();

    /* publish INS output */
    mcn_publish(MCN_HUB(ins_output), &INS_Y.INS_Out);

    /* record INS input bus data if updated */
    if (ins_handle.imu_updated) {
        /* Log IMU data if IMU updated */
        if (blog_push_msg((uint8_t*)&INS_U.IMU, BLOG_IMU_ID, sizeof(INS_U.IMU)) == FMT_EOK) {
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

    if (ins_handle.rf_updated) {
        /* Log Rangefinder data */
        if (blog_push_msg((uint8_t*)&ins_handle.rf_report, BLOG_RANGEFINDER_ID, sizeof(ins_handle.rf_report)) == FMT_EOK) {
            ins_handle.rf_updated = 0;
        }
    }

    if (ins_handle.optflow_updated) {
        /* Log Optical Flow data */
        if (blog_push_msg((uint8_t*)&ins_handle.optflow_report, BLOG_OPTICAL_FLOW_ID, sizeof(ins_handle.optflow_report)) == FMT_EOK) {
            ins_handle.optflow_updated = 0;
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
    mcn_advertise(MCN_HUB(ins_output), _ins_output_echo);

    ins_handle.imu_sub_node_t = mcn_subscribe(MCN_HUB(sensor_imu0), NULL, NULL);
    ins_handle.mag_sub_node_t = mcn_subscribe(MCN_HUB(sensor_mag0), NULL, NULL);
    ins_handle.baro_sub_node_t = mcn_subscribe(MCN_HUB(sensor_baro), NULL, NULL);
    ins_handle.gps_sub_node_t = mcn_subscribe(MCN_HUB(sensor_gps), NULL, NULL);
    ins_handle.rf_sub_node_t = mcn_subscribe(MCN_HUB(sensor_rangefinder), NULL, NULL);
    ins_handle.optflow_sub_node_t = mcn_subscribe(MCN_HUB(sensor_optflow), NULL, NULL);

    blog_register_callback(BLOG_CB_START, _blog_start_cb);

    INS_init();

    _update_ins_parameter();
}
