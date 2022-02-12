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

#include "module/log/mlog.h"
#include "module/param/param.h"
#include "module/sensor/sensor_hub.h"

/* INS input bus */
MCN_DECLARE(sensor_imu0);
MCN_DECLARE(sensor_mag0);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(sensor_rangefinder);
MCN_DECLARE(sensor_optflow);

/* INS output bus */
MCN_DEFINE(ins_output, sizeof(INS_Out_Bus));

/* define log data */
static mlog_elem_t IMU_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(gyr_x, MLOG_FLOAT),
    MLOG_ELEMENT(gyr_y, MLOG_FLOAT),
    MLOG_ELEMENT(gyr_z, MLOG_FLOAT),
    MLOG_ELEMENT(acc_x, MLOG_FLOAT),
    MLOG_ELEMENT(acc_y, MLOG_FLOAT),
    MLOG_ELEMENT(acc_z, MLOG_FLOAT),
};
MLOG_BUS_DEFINE(IMU, IMU_Elems);

static mlog_elem_t MAG_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(mag_x, MLOG_FLOAT),
    MLOG_ELEMENT(mag_y, MLOG_FLOAT),
    MLOG_ELEMENT(mag_z, MLOG_FLOAT),
};
MLOG_BUS_DEFINE(MAG, MAG_Elems);

static mlog_elem_t Barometer_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(pressure, MLOG_FLOAT),
    MLOG_ELEMENT(temperature, MLOG_FLOAT),
};
MLOG_BUS_DEFINE(Barometer, Barometer_Elems);

static mlog_elem_t GPS_uBlox_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(iTOW, MLOG_UINT32),
    MLOG_ELEMENT(year, MLOG_UINT16),
    MLOG_ELEMENT(month, MLOG_UINT8),
    MLOG_ELEMENT(day, MLOG_UINT8),
    MLOG_ELEMENT(hour, MLOG_UINT8),
    MLOG_ELEMENT(min, MLOG_UINT8),
    MLOG_ELEMENT(sec, MLOG_UINT8),
    MLOG_ELEMENT(valid, MLOG_UINT8),
    MLOG_ELEMENT(tAcc, MLOG_UINT32),
    MLOG_ELEMENT(nano, MLOG_INT32),
    MLOG_ELEMENT(fixType, MLOG_UINT8),
    MLOG_ELEMENT(flags, MLOG_UINT8),
    MLOG_ELEMENT(reserved1, MLOG_UINT8),
    MLOG_ELEMENT(numSV, MLOG_UINT8),
    MLOG_ELEMENT(lon, MLOG_INT32),
    MLOG_ELEMENT(lat, MLOG_INT32),
    MLOG_ELEMENT(height, MLOG_INT32),
    MLOG_ELEMENT(hMSL, MLOG_INT32),
    MLOG_ELEMENT(hAcc, MLOG_UINT32),
    MLOG_ELEMENT(vAcc, MLOG_UINT32),
    MLOG_ELEMENT(velN, MLOG_INT32),
    MLOG_ELEMENT(velE, MLOG_INT32),
    MLOG_ELEMENT(velD, MLOG_INT32),
    MLOG_ELEMENT(gSpeed, MLOG_INT32),
    MLOG_ELEMENT(heading, MLOG_INT32),
    MLOG_ELEMENT(sAcc, MLOG_UINT32),
    MLOG_ELEMENT(headingAcc, MLOG_UINT32),
    MLOG_ELEMENT(pDOP, MLOG_UINT16),
    MLOG_ELEMENT(reserved2, MLOG_UINT16),
};
MLOG_BUS_DEFINE(GPS_uBlox, GPS_uBlox_Elems);

mlog_elem_t Rangefinder_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(distance_m, MLOG_FLOAT),
};
MLOG_BUS_DEFINE(Rangefinder, Rangefinder_Elems);

mlog_elem_t Optflow_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(vx, MLOG_FLOAT),
    MLOG_ELEMENT(vy, MLOG_FLOAT),
    MLOG_ELEMENT(valid, MLOG_UINT32),
};
MLOG_BUS_DEFINE(OpticalFlow, Optflow_Elems);

mlog_elem_t INS_Out_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(phi, MLOG_FLOAT),
    MLOG_ELEMENT(theta, MLOG_FLOAT),
    MLOG_ELEMENT(psi, MLOG_FLOAT),
    MLOG_ELEMENT_VEC(quat, MLOG_FLOAT, 4),
    MLOG_ELEMENT(p, MLOG_FLOAT),
    MLOG_ELEMENT(q, MLOG_FLOAT),
    MLOG_ELEMENT(r, MLOG_FLOAT),
    MLOG_ELEMENT(ax, MLOG_FLOAT),
    MLOG_ELEMENT(ay, MLOG_FLOAT),
    MLOG_ELEMENT(az, MLOG_FLOAT),
    MLOG_ELEMENT(vn, MLOG_FLOAT),
    MLOG_ELEMENT(ve, MLOG_FLOAT),
    MLOG_ELEMENT(vd, MLOG_FLOAT),
    MLOG_ELEMENT(reserved, MLOG_FLOAT),
    MLOG_ELEMENT(lon, MLOG_DOUBLE),
    MLOG_ELEMENT(lat, MLOG_DOUBLE),
    MLOG_ELEMENT(alt, MLOG_DOUBLE),
    MLOG_ELEMENT(x_R, MLOG_FLOAT),
    MLOG_ELEMENT(y_R, MLOG_FLOAT),
    MLOG_ELEMENT(h_R, MLOG_FLOAT),
    MLOG_ELEMENT(h_AGL, MLOG_FLOAT),
    MLOG_ELEMENT(flag, MLOG_UINT32),
    MLOG_ELEMENT(status, MLOG_UINT32),
};
MLOG_BUS_DEFINE(INS_Out, INS_Out_Elems);

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

static int IMU_ID;
static int MAG_ID;
static int Barometer_ID;
static int GPS_ID;
static int Rangefinder_ID;
static int OpticalFlow_ID;
static int INS_Out_ID;

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
        mlog_push_msg((uint8_t*)&INS_U.IMU, IMU_ID, sizeof(INS_U.IMU));
    }

    if (mag_data_updated) {
        mag_data_updated = 0;
        /* Log Magnetometer data */
        mlog_push_msg((uint8_t*)&INS_U.MAG, MAG_ID, sizeof(INS_U.MAG));
    }

    if (baro_data_updated) {
        baro_data_updated = 0;
        /* Log Barometer data */
        mlog_push_msg((uint8_t*)&INS_U.Barometer, Barometer_ID, sizeof(INS_U.Barometer));
    }

    if (gps_data_updated) {
        gps_data_updated = 0;
        /* Log GPS data */
        mlog_push_msg((uint8_t*)&INS_U.GPS_uBlox, GPS_ID, sizeof(INS_U.GPS_uBlox));
    }

    if (rf_data_updated) {
        rf_data_updated = 0;
        /* Log Rangefinder data */
        mlog_push_msg((uint8_t*)&ins_handle.rf_report, Rangefinder_ID, sizeof(ins_handle.rf_report));
    }

    if (optflow_data_updated) {
        optflow_data_updated = 0;
        /* Log Optical Flow data */
        mlog_push_msg((uint8_t*)&ins_handle.optflow_report, OpticalFlow_ID, sizeof(ins_handle.optflow_report));
    }

    /* Log INS output bus data */
    DEFINE_TIMETAG(ins_output, 100);
    if (check_timetag(TIMETAG(ins_output))) {
        /* Log INS out data */
        mlog_push_msg((uint8_t*)&INS_Y.INS_Out, INS_Out_ID, sizeof(INS_Y.INS_Out));
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

    IMU_ID = mlog_get_bus_id("IMU");
    MAG_ID = mlog_get_bus_id("MAG");
    Barometer_ID = mlog_get_bus_id("Barometer");
    GPS_ID = mlog_get_bus_id("GPS_uBlox");
    Rangefinder_ID = mlog_get_bus_id("Rangefinder");
    OpticalFlow_ID = mlog_get_bus_id("OpticalFlow");
    INS_Out_ID = mlog_get_bus_id("INS_Out");
    FMT_ASSERT(IMU_ID >= 0);
    FMT_ASSERT(MAG_ID >= 0);
    FMT_ASSERT(Barometer_ID >= 0);
    FMT_ASSERT(GPS_ID >= 0);
    FMT_ASSERT(Rangefinder_ID >= 0);
    FMT_ASSERT(OpticalFlow_ID >= 0);
    FMT_ASSERT(INS_Out_ID >= 0);

    mlog_register_callback(MLOG_CB_START, mlog_start_cb);

    INS_init();
}
