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

#include "module/log/mlog.h"
#include "module/param/param.h"
#include "module/sensor/sensor_hub.h"

#define TAG "Plant"

#ifdef FMT_USING_SIH

/* Plant output bus */
MCN_DEFINE(plant_states, sizeof(Plant_States_Bus));
/* sensor topics to publish */
MCN_DECLARE(sensor_imu0);
MCN_DECLARE(sensor_mag0);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
/* plant model input */
MCN_DECLARE(control_output);
MCN_DECLARE(environment_info);

/* define log data */
static mlog_elem_t Plant_States_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(phi, MLOG_FLOAT),
    MLOG_ELEMENT(theta, MLOG_FLOAT),
    MLOG_ELEMENT(psi, MLOG_FLOAT),
    MLOG_ELEMENT(rot_x_B, MLOG_FLOAT),
    MLOG_ELEMENT(rot_y_B, MLOG_FLOAT),
    MLOG_ELEMENT(rot_z_B, MLOG_FLOAT),
    MLOG_ELEMENT(acc_x_O, MLOG_FLOAT),
    MLOG_ELEMENT(acc_y_O, MLOG_FLOAT),
    MLOG_ELEMENT(acc_z_O, MLOG_FLOAT),
    MLOG_ELEMENT(vel_x_O, MLOG_FLOAT),
    MLOG_ELEMENT(vel_y_O, MLOG_FLOAT),
    MLOG_ELEMENT(vel_z_O, MLOG_FLOAT),
    MLOG_ELEMENT(x_R, MLOG_FLOAT),
    MLOG_ELEMENT(y_R, MLOG_FLOAT),
    MLOG_ELEMENT(h_R, MLOG_FLOAT),
    MLOG_ELEMENT(lat, MLOG_DOUBLE),
    MLOG_ELEMENT(lon, MLOG_DOUBLE),
    MLOG_ELEMENT(alt, MLOG_DOUBLE),
    MLOG_ELEMENT(lat_0, MLOG_DOUBLE),
    MLOG_ELEMENT(lon_0, MLOG_DOUBLE),
    MLOG_ELEMENT(alt_0, MLOG_DOUBLE),
};
MLOG_BUS_DEFINE(Plant_States, Plant_States_Elems);

static mlog_elem_t Environment_Info_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT_VEC(hit_point, MLOG_FLOAT, 3),
    MLOG_ELEMENT_VEC(hit_normal, MLOG_FLOAT, 3),
    MLOG_ELEMENT_VEC(hit_location, MLOG_FLOAT, 3),
    MLOG_ELEMENT_VEC(torque, MLOG_FLOAT, 3),
    MLOG_ELEMENT_VEC(force, MLOG_FLOAT, 3),
};
MLOG_BUS_DEFINE(Environment_Info, Environment_Info_Elems);

static McnNode_t control_out_nod;
static McnNode_t environment_info_nod;
static uint32_t  imu_timestamp  = 0xFFFF;
static uint32_t  mag_timestamp  = 0xFFFF;
static uint32_t  baro_timestamp = 0xFFFF;
static uint32_t  gps_timestamp  = 0xFFFF;
static uint8_t   environment_info_updated;

static int Plant_States_ID;
static int Environment_Info_ID;

fmt_model_info_t plant_model_info;

static int plant_states_echo(void* param)
{
    Plant_States_Bus plant_states;

    mcn_copy_from_hub((McnHub*)param, &plant_states);

    printf("timestamp:%u\n", plant_states.timestamp);
    printf("att: %.2f %.2f %.2f\n", RAD2DEG(plant_states.phi), RAD2DEG(plant_states.theta), RAD2DEG(plant_states.psi));
    printf("rate: %.2f %.2f %.2f\n", plant_states.rot_x_B, plant_states.rot_y_B, plant_states.rot_z_B);
    printf("accel: %.2f %.2f %.2f\n", plant_states.acc_x_O, plant_states.acc_y_O, plant_states.acc_y_O);
    printf("vel: %.2f %.2f %.2f\n", plant_states.vel_x_O, plant_states.vel_y_O, plant_states.vel_z_O);
    printf("xyh: %.2f %.2f %.2f\n", plant_states.x_R, plant_states.y_R, plant_states.h_R);
    printf("LLA: %lf %lf %f LLA0: %lf %lf %f\n", plant_states.lat, plant_states.lon, plant_states.alt, plant_states.lat_0, plant_states.lon_0, plant_states.alt_0);
    printf("------------------------------------------\n");

    return 0;
}

static void mlog_start_cb(void)
{
    /* when mlog started, record at least first data even there is no data publiced */
    environment_info_updated = 1;
}

static void publish_sensor_data(uint32_t timestamp)
{
    if (Plant_Y.IMU.timestamp != imu_timestamp) {
        imu_data_t imu_report;

        imu_report.timestamp_ms   = timestamp;
        imu_report.gyr_B_radDs[0] = Plant_Y.IMU.gyr_x;
        imu_report.gyr_B_radDs[1] = Plant_Y.IMU.gyr_y;
        imu_report.gyr_B_radDs[2] = Plant_Y.IMU.gyr_z;
        imu_report.acc_B_mDs2[0]  = Plant_Y.IMU.acc_x;
        imu_report.acc_B_mDs2[1]  = Plant_Y.IMU.acc_y;
        imu_report.acc_B_mDs2[2]  = Plant_Y.IMU.acc_z;
        // publish sensor_imu data
        mcn_publish(MCN_HUB(sensor_imu0), &imu_report);

        imu_timestamp = Plant_Y.IMU.timestamp;
    }

    if (Plant_Y.MAG.timestamp != mag_timestamp) {
        mag_data_t mag_report;

        mag_report.timestamp_ms   = timestamp;
        mag_report.mag_B_gauss[0] = Plant_Y.MAG.mag_x;
        mag_report.mag_B_gauss[1] = Plant_Y.MAG.mag_y;
        mag_report.mag_B_gauss[2] = Plant_Y.MAG.mag_z;
        // publish sensor_mag data
        mcn_publish(MCN_HUB(sensor_mag0), &mag_report);

        mag_timestamp = Plant_Y.MAG.timestamp;
    }

    if (Plant_Y.Barometer.timestamp != baro_timestamp) {
        baro_data_t baro_report;

        baro_report.timestamp_ms    = timestamp;
        baro_report.temperature_deg = Plant_Y.Barometer.temperature;
        baro_report.pressure_pa     = Plant_Y.Barometer.pressure;

        /* tropospheric properties (0-11km) for standard atmosphere */
        const double T1 = 15.0 + 273.15; /* temperature at base height in Kelvin, [K] = [°C] + 273.15 */
        const double a  = -6.5 / 1000;   /* temperature gradient in degrees per metre */
        const double g  = 9.80665;       /* gravity constant in m/s/s */
        const double R  = 287.05;        /* ideal gas constant in J/kg/K */
        /* current pressure at MSL in kPa */
        double p1 = 101325.0 / 1000.0;
        /* measured pressure in kPa */
        double p = baro_report.pressure_pa / 1000.0;

        /*
         * Solve:
         *
         *     /        -(aR / g)     \
         *    | (p / p1)          . T1 | - T1
         *     \                      /
         * h = -------------------------------  + h1
         *                   a
         */
        baro_report.altitude_m = (((pow((p / p1), (-(a * R) / g))) * T1) - T1) / a;

        // publish SNESOR_BARO data
        mcn_publish(MCN_HUB(sensor_baro), &baro_report);

        baro_timestamp = Plant_Y.Barometer.timestamp;
    }

    if (Plant_Y.GPS.timestamp != gps_timestamp) {
        gps_data_t gps_report;

        gps_report.timestamp_ms = timestamp;
        gps_report.fixType      = Plant_Y.GPS.fixType;
        gps_report.numSV        = Plant_Y.GPS.numSV;
        gps_report.lon          = Plant_Y.GPS.lon;
        gps_report.lat          = Plant_Y.GPS.lat;
        gps_report.height       = Plant_Y.GPS.height;
        gps_report.hAcc         = (float)Plant_Y.GPS.hAcc * 1e-3;
        gps_report.vAcc         = (float)Plant_Y.GPS.vAcc * 1e-3;
        gps_report.velN         = (float)Plant_Y.GPS.velN * 1e-3;
        gps_report.velE         = (float)Plant_Y.GPS.velE * 1e-3;
        gps_report.velD         = (float)Plant_Y.GPS.velD * 1e-3;
        gps_report.sAcc         = (float)Plant_Y.GPS.sAcc * 1e-3;
        // publish sensor_gps data
        mcn_publish(MCN_HUB(sensor_gps), &gps_report);

        gps_timestamp = Plant_Y.GPS.timestamp;
    }
}

void plant_interface_step(uint32_t timestamp)
{
    if (mcn_poll(control_out_nod)) {
        mcn_copy(MCN_HUB(control_output), control_out_nod, &Plant_U.Control_Out);
    }

    if (mcn_poll(environment_info_nod)) {
        mcn_copy(MCN_HUB(environment_info), environment_info_nod, &Plant_U.Environment_Info);

        Plant_U.Environment_Info.timestamp = systime_now_ms();

        environment_info_updated = 1;
    }

    /* run plant model */
    Plant_step();

    /* publish plant output */
    mcn_publish(MCN_HUB(plant_states), &Plant_Y.Plant_States);

    /* Log Plant output bus data */
    DEFINE_TIMETAG(plant_output, 100);
    if (check_timetag(TIMETAG(plant_output))) {
        /* Log Control out data */
        mlog_push_msg((uint8_t*)&Plant_Y.Plant_States, Plant_States_ID, sizeof(Plant_States_Bus));
    }

    if (environment_info_updated) {
        environment_info_updated = 0;
        /* Log environment info data */
        mlog_push_msg((uint8_t*)&Plant_U.Environment_Info, Environment_Info_ID, sizeof(Plant_U.Environment_Info));
    }

    /* publish sensor model's data */
    publish_sensor_data(timestamp);
}

void plant_interface_init(void)
{
    plant_model_info.period = PLANT_EXPORT.period;
    plant_model_info.info   = (char*)PLANT_EXPORT.model_info;

    mcn_advertise(MCN_HUB(plant_states), plant_states_echo);

    control_out_nod      = mcn_subscribe(MCN_HUB(control_output), NULL, NULL);
    environment_info_nod = mcn_subscribe(MCN_HUB(environment_info), NULL, NULL);

    Plant_States_ID = mlog_get_bus_id("Plant_States");
    FMT_ASSERT(Plant_States_ID >= 0);

    Environment_Info_ID = mlog_get_bus_id("Environment_Info");
    FMT_ASSERT(Environment_Info_ID >= 0);

    if (control_out_nod == NULL) {
        ulog_e(TAG, "uMCN topic control_output subscribe fail!\n");
    }

    if (environment_info_nod == NULL) {
        ulog_e(TAG, "uMCN topic environment_info subscribe fail!\n");
    }

    mlog_register_callback(MLOG_CB_START, mlog_start_cb);

    Plant_init();
}

#endif