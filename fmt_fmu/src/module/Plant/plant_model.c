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

#include <Plant.h>
#include <firmament.h>

#include "module/sensor/sensor_manager.h"

#define TAG "Plant"

#ifdef FMT_USING_SIH

// sensor topics to publish
MCN_DECLARE(sensor_imu);
MCN_DECLARE(sensor_mag);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);

// plant model input
MCN_DECLARE(control_output);

static McnNode_t _control_out_nod;

static void _publish_sensor_data(void)
{
    static uint32_t imu_timestamp = 0xFFFF;
    static uint32_t mag_timestamp = 0xFFFF;
    static uint32_t baro_timestamp = 0xFFFF;
    static uint32_t gps_timestamp = 0xFFFF;
    uint32_t time_now = systime_now_ms();

    if (Plant_Y.IMU.timestamp != imu_timestamp) {
        IMU_Report imu_report;

        imu_report.timestamp_ms = time_now;
        imu_report.gyr_B_radDs[0] = Plant_Y.IMU.gyr_x;
        imu_report.gyr_B_radDs[1] = Plant_Y.IMU.gyr_y;
        imu_report.gyr_B_radDs[2] = Plant_Y.IMU.gyr_z;
        imu_report.acc_B_mDs2[0] = Plant_Y.IMU.acc_x;
        imu_report.acc_B_mDs2[1] = Plant_Y.IMU.acc_y;
        imu_report.acc_B_mDs2[2] = Plant_Y.IMU.acc_z;
        // publish sensor_imu data
        mcn_publish(MCN_ID(sensor_imu), &imu_report);

        imu_timestamp = Plant_Y.IMU.timestamp;
    }

    if (Plant_Y.MAG.timestamp != mag_timestamp) {
        Mag_Report mag_report;

        mag_report.timestamp_ms = time_now;
        mag_report.mag_B_gauss[0] = Plant_Y.MAG.mag_x;
        mag_report.mag_B_gauss[1] = Plant_Y.MAG.mag_y;
        mag_report.mag_B_gauss[2] = Plant_Y.MAG.mag_z;
        // publish sensor_mag data
        mcn_publish(MCN_ID(sensor_mag), &mag_report);

        mag_timestamp = Plant_Y.MAG.timestamp;
    }

    if (Plant_Y.Barometer.timestamp != baro_timestamp) {
        Baro_Report baro_report;

        baro_report.timestamp_ms = time_now;
        baro_report.temperature_deg = Plant_Y.Barometer.temperature;
        baro_report.pressure_pa = Plant_Y.Barometer.pressure;
        // publish SNESOR_BARO data
        mcn_publish(MCN_ID(sensor_baro), &baro_report);

        baro_timestamp = Plant_Y.Barometer.timestamp;
    }

    if (Plant_Y.GPS_uBlox.timestamp != gps_timestamp) {
        GPS_Report gps_report;

        gps_report.timestamp_ms = time_now;
        gps_report.fixType = Plant_Y.GPS_uBlox.fixType;
        gps_report.numSV = Plant_Y.GPS_uBlox.numSV;
        gps_report.lon = Plant_Y.GPS_uBlox.lon;
        gps_report.lat = Plant_Y.GPS_uBlox.lat;
        gps_report.height = Plant_Y.GPS_uBlox.height;
        gps_report.hAcc = (float)Plant_Y.GPS_uBlox.hAcc * 1e-3;
        gps_report.vAcc = (float)Plant_Y.GPS_uBlox.vAcc * 1e-3;
        gps_report.velN = (float)Plant_Y.GPS_uBlox.velN * 1e-3;
        gps_report.velE = (float)Plant_Y.GPS_uBlox.velE * 1e-3;
        gps_report.velD = (float)Plant_Y.GPS_uBlox.velD * 1e-3;
        gps_report.sAcc = (float)Plant_Y.GPS_uBlox.sAcc * 1e-3;
        // publish sensor_gps data
        mcn_publish(MCN_ID(sensor_gps), &gps_report);

        gps_timestamp = Plant_Y.GPS_uBlox.timestamp;
    }
}

void plant_model_step(void)
{
    static uint32_t start_time = 0;
    uint32_t time_now = systime_now_ms();

    if (start_time == 0) {
        /* record first execution time */
        start_time = time_now;
    }

    if (mcn_poll(_control_out_nod)) {
        mcn_copy(MCN_ID(control_output), _control_out_nod, &Plant_U.Control_Out);
    }

    Plant_step();

    DEFINE_TIMETAG(plant_output, 100);

    /* Log Plant output bus data */
    if (check_timetag(TIMETAG(plant_output))) {
        /* rewrite timestmp */
        Plant_Y.Plant_States.timestamp = time_now - start_time;
        /* Log Control out data */
        blog_push_msg((uint8_t*)&Plant_Y.Plant_States, BLOG_PLANT_STATE_ID, sizeof(Plant_States_Bus));
    }

    _publish_sensor_data();
}

void plant_model_init(void)
{
    _control_out_nod = mcn_subscribe(MCN_ID(control_output), NULL, NULL);

    if (_control_out_nod == NULL) {
        ulog_e(TAG, "uMCN topic control_output subscribe fail!\n");
    }

    Plant_init();

    /* run plant model to ensure INS can get valid sensor in its first run */
    Plant_step();
    _publish_sensor_data();
}

#endif