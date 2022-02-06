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

/* INS output bus */
MCN_DEFINE(ins_output, sizeof(INS_Out_Bus));

/* INS input bus */
MCN_DECLARE(sensor_imu0);
MCN_DECLARE(sensor_mag0);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(sensor_rangefinder);
MCN_DECLARE(sensor_optflow);

static struct INS_Handler {
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
} ins_handle;

static uint8_t imu_data_updated;
static uint8_t mag_data_updated;
static uint8_t baro_data_updated;
static uint8_t gps_data_updated;
static uint8_t rf_data_updated;
static uint8_t optflow_data_updated;

fmt_model_info_t ins_model_info;

static int ins_output_echo(void* param)
{
    INS_Out_Bus ins_out;

    mcn_copy_from_hub((McnHub*)param, &ins_out);

    console_printf("euler angle(deg) %.2f %.2f %.2f\n", RAF2DEG(ins_out.phi), RAF2DEG(ins_out.theta), RAF2DEG(ins_out.psi));

    return 0;
}

static void mlog_start_cb(void)
{
    /* when mlog started, record at least first data even there is no data publiced */
    imu_data_updated = 1;
    mag_data_updated = 1;
    baro_data_updated = 1;
    gps_data_updated = 1;
    rf_data_updated = 1;
    optflow_data_updated = 1;
}

void ins_interface_step(uint32_t timestamp)
{
    /* get sensor data */
    if (mcn_poll(ins_handle.imu_sub_node_t)) {
        mcn_copy(MCN_HUB(sensor_imu0), ins_handle.imu_sub_node_t, &ins_handle.imu_report);

        INS_U.IMU.gyr_x = ins_handle.imu_report.gyr_B_radDs[0];
        INS_U.IMU.gyr_y = ins_handle.imu_report.gyr_B_radDs[1];
        INS_U.IMU.gyr_z = ins_handle.imu_report.gyr_B_radDs[2];
        INS_U.IMU.acc_x = ins_handle.imu_report.acc_B_mDs2[0];
        INS_U.IMU.acc_y = ins_handle.imu_report.acc_B_mDs2[1];
        INS_U.IMU.acc_z = ins_handle.imu_report.acc_B_mDs2[2];
        // INS_U.IMU.timestamp = time_now - ins_handle.start_time;
        INS_U.IMU.timestamp = timestamp;

        imu_data_updated = 1;
    }

    if (mcn_poll(ins_handle.mag_sub_node_t)) {
        mcn_copy(MCN_HUB(sensor_mag0), ins_handle.mag_sub_node_t, &ins_handle.mag_report);

        INS_U.MAG.mag_x = ins_handle.mag_report.mag_B_gauss[0];
        INS_U.MAG.mag_y = ins_handle.mag_report.mag_B_gauss[1];
        INS_U.MAG.mag_z = ins_handle.mag_report.mag_B_gauss[2];
        INS_U.MAG.timestamp = timestamp;

        mag_data_updated = 1;
    }

    if (mcn_poll(ins_handle.baro_sub_node_t)) {
        mcn_copy(MCN_HUB(sensor_baro), ins_handle.baro_sub_node_t, &ins_handle.baro_report);

        INS_U.Barometer.pressure = (float)ins_handle.baro_report.pressure_pa;
        INS_U.Barometer.temperature = ins_handle.baro_report.temperature_deg;
        INS_U.Barometer.timestamp = timestamp;

        baro_data_updated = 1;
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
        INS_U.GPS_uBlox.timestamp = timestamp;

        gps_data_updated = 1;
    }

    /* update rangefinder data */
    if (mcn_poll(ins_handle.rf_sub_node_t)) {
        mcn_copy(MCN_HUB(sensor_rangefinder), ins_handle.rf_sub_node_t, &ins_handle.rf_report);

        // TODO
        rf_data_updated = 1;
    }

    /* update optical flow data */
    if (mcn_poll(ins_handle.optflow_sub_node_t)) {
        mcn_copy(MCN_HUB(sensor_optflow), ins_handle.optflow_sub_node_t, &ins_handle.optflow_report);

        // TODO
        optflow_data_updated = 1;
    }

    /* run INS */
    INS_step();

    /* publish INS output */
    mcn_publish(MCN_HUB(ins_output), &INS_Y.INS_Out);

    /* record INS input bus data if updated */
    if (imu_data_updated) {
        imu_data_updated = 0;
        /* Log IMU data if IMU updated */
        mlog_push_msg((uint8_t*)&INS_U.IMU, MLOG_IMU_ID, sizeof(INS_U.IMU));
    }

    if (mag_data_updated) {
        mag_data_updated = 0;
        /* Log Magnetometer data */
        mlog_push_msg((uint8_t*)&INS_U.MAG, MLOG_MAG_ID, sizeof(INS_U.MAG));
    }

    if (baro_data_updated) {
        baro_data_updated = 0;
        /* Log Barometer data */
        mlog_push_msg((uint8_t*)&INS_U.Barometer, MLOG_BARO_ID, sizeof(INS_U.Barometer));
    }

    if (gps_data_updated) {
        gps_data_updated = 0;
        /* Log GPS data */
        mlog_push_msg((uint8_t*)&INS_U.GPS_uBlox, MLOG_GPS_ID, sizeof(INS_U.GPS_uBlox));
    }

    if (rf_data_updated) {
        rf_data_updated = 0;
        /* Log Rangefinder data */
        mlog_push_msg((uint8_t*)&ins_handle.rf_report, MLOG_RANGEFINDER_ID, sizeof(ins_handle.rf_report));
    }

    if (optflow_data_updated) {
        optflow_data_updated = 0;
        /* Log Optical Flow data */
        mlog_push_msg((uint8_t*)&ins_handle.optflow_report, MLOG_OPTICAL_FLOW_ID, sizeof(ins_handle.optflow_report));
    }

    /* Log INS output bus data */
    DEFINE_TIMETAG(ins_output, 100);
    if (check_timetag(TIMETAG(ins_output))) {
        /* Log INS out data */
        mlog_push_msg((uint8_t*)&INS_Y.INS_Out, MLOG_INS_OUT_ID, sizeof(INS_Y.INS_Out));
    }
}

void ins_interface_init(void)
{
    ins_model_info.period = INS_EXPORT.period;
    ins_model_info.info = (char*)INS_EXPORT.model_info;

    mcn_advertise(MCN_HUB(ins_output), ins_output_echo);

    ins_handle.imu_sub_node_t = mcn_subscribe(MCN_HUB(sensor_imu0), NULL, NULL);
    ins_handle.mag_sub_node_t = mcn_subscribe(MCN_HUB(sensor_mag0), NULL, NULL);
    ins_handle.baro_sub_node_t = mcn_subscribe(MCN_HUB(sensor_baro), NULL, NULL);
    ins_handle.gps_sub_node_t = mcn_subscribe(MCN_HUB(sensor_gps), NULL, NULL);
    ins_handle.rf_sub_node_t = mcn_subscribe(MCN_HUB(sensor_rangefinder), NULL, NULL);
    ins_handle.optflow_sub_node_t = mcn_subscribe(MCN_HUB(sensor_optflow), NULL, NULL);

    mlog_register_callback(MLOG_CB_START, mlog_start_cb);

    INS_init();
}
