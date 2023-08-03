/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#include "Controller_types.h"
#include "ecl_wrapper.h"
#include "module/log/mlog.h"
#include "module/param/param.h"
#include "module/sensor/sensor_hub.h"

#ifdef BIT
    #undef BIT
#endif
#define BIT(u, n) (u & (1 << n))

#define SIGN(x) ((x > 0) - (x < 0))

// Bit locations for mag_declination_source
#define MASK_USE_GEO_DECL  (1 << 0) ///< set to true to use the declination from the geo library when the GPS position becomes available, set to false to always use the EKF2_MAG_DECL value
#define MASK_SAVE_GEO_DECL (1 << 1) ///< set to true to set the EKF2_MAG_DECL parameter to the value returned by the geo library
#define MASK_FUSE_DECL     (1 << 2) ///< set to true if the declination is always fused as an observation to constrain drift when 3-axis fusion is performed

// Integer definitions for mag_fusion_type
#define MAG_FUSE_TYPE_AUTO    0 ///< The selection of either heading or 3D magnetometer fusion will be automatic
#define MAG_FUSE_TYPE_HEADING 1 ///< Simple yaw angle fusion will always be used. This is less accurate, but less affected by earth field distortions. It should not be used for pitch angles outside the range from -60 to +60 deg
#define MAG_FUSE_TYPE_3D      2 ///< Magnetometer 3-axis fusion will always be used. This is more accurate, but more affected by localised earth field distortions
#define MAG_FUSE_TYPE_UNUSED  3 ///< Not implemented
#define MAG_FUSE_TYPE_INDOOR  4 ///< The same as option 0, but magnetometer or yaw fusion will not be used unless earth frame external aiding (GPS or External Vision) is being used. This prevents inconsistent magnetic fields associated with indoor operation degrading state estimates.
#define MAG_FUSE_TYPE_NONE    5 ///< Do not use magnetometer under any circumstance. Other sources of yaw may be used if selected via the EKF2_AID_MASK parameter.

// GPS pre-flight check bit locations
#define MASK_GPS_NSATS  (1 << 0)
#define MASK_GPS_PDOP   (1 << 1)
#define MASK_GPS_HACC   (1 << 2)
#define MASK_GPS_VACC   (1 << 3)
#define MASK_GPS_SACC   (1 << 4)
#define MASK_GPS_HDRIFT (1 << 5)
#define MASK_GPS_VDRIFT (1 << 6)
#define MASK_GPS_HSPD   (1 << 7)
#define MASK_GPS_VSPD   (1 << 8)

// Bit locations for fusion_mode
#define MASK_USE_GPS          (1 << 0) ///< set to true to use GPS data
#define MASK_USE_OF           (1 << 1) ///< set to true to use optical flow data
#define MASK_INHIBIT_ACC_BIAS (1 << 2) ///< set to true to inhibit estimation of accelerometer delta velocity bias
#define MASK_USE_EVPOS        (1 << 3) ///< set to true to use external vision position data
#define MASK_USE_EVYAW        (1 << 4) ///< set to true to use external vision quaternion data for yaw
#define MASK_USE_DRAG         (1 << 5) ///< set to true to use the multi-rotor drag model to estimate wind
#define MASK_ROTATE_EV        (1 << 6) ///< set to true to if the EV observations are in a non NED reference frame and need to be rotated before being used
#define MASK_USE_GPSYAW       (1 << 7) ///< set to true to use GPS yaw data if available
#define MASK_USE_EVVEL        (1 << 8) ///< set to true to use external vision velocity data

// Integer definitions for vdist_sensor_type
#define VDIST_SENSOR_BARO  0 ///< Use baro height
#define VDIST_SENSOR_GPS   1 ///< Use GPS height
#define VDIST_SENSOR_RANGE 2 ///< Use range finder height
#define VDIST_SENSOR_EV    3 ///< Use external vision

#define TERRAIN_FUSE_RANGEFINDER (1 << 0)
#define TERRAIN_FUSE_OPTICALFLOW (1 << 1)

// Integer determine source of vision observation noise
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_X_VARIANCE         0
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_Y_VARIANCE         6
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_Z_VARIANCE         11
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_ROLL_VARIANCE      15
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_PITCH_VARIANCE     18
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_YAW_VARIANCE       20
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_VX_VARIANCE        0
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_VY_VARIANCE        6
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_VZ_VARIANCE        11
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_ROLLRATE_VARIANCE  15
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_PITCHRATE_VARIANCE 18
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_YAWRATE_VARIANCE   20
#define VEHICLE_ODOMETRY_LOCAL_FRAME_NED                      0
#define VEHICLE_ODOMETRY_LOCAL_FRAME_FRD                      1
#define VEHICLE_ODOMETRY_LOCAL_FRAME_OTHER                    2
#define VEHICLE_ODOMETRY_BODY_FRAME_FRD                       3

/* INS input bus */
MCN_DECLARE(sensor_imu0);
MCN_DECLARE(sensor_mag0);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(sensor_rangefinder);
MCN_DECLARE(sensor_optflow);
MCN_DECLARE(sensor_airspeed);

/* FMS input bus */
MCN_DECLARE(fms_output);

/* Control input bus*/
MCN_DECLARE(control_output);

/* External Position */
MCN_DEFINE(external_pos, sizeof(External_Pos_Bus));

/* INS output bus */
MCN_DEFINE(ins_output, sizeof(INS_Out_Bus));

/* define parameters */
static param_t __param_list[] = {
    PARAM_FLOAT(ekf2_gyr_noise, 1.5e-2f, false), ///< IMU angular rate noise used for covariance prediction (rad/sec)
    PARAM_FLOAT(ekf2_acc_noise, 3.5e-1f, false), ///< IMU acceleration noise use for covariance prediction (m/sec**2)

    PARAM_FLOAT(ekf2_gyr_b_noise, 1.0e-3f, false), ///< process noise for IMU rate gyro bias prediction (rad/sec**2)
    PARAM_FLOAT(ekf2_acc_b_noise, 1.0e-2f, false), ///< process noise for IMU accelerometer bias prediction (m/sec**3)
    PARAM_FLOAT(ekf2_mag_e_noise, 1.0e-3f, false), ///< process noise for earth magnetic field prediction (Gauss/sec)
    PARAM_FLOAT(ekf2_mag_b_noise, 1.0e-4f, false), ///< process noise for body magnetic field prediction (Gauss/sec)
    PARAM_FLOAT(ekf2_wind_noise, 1.0e-1f, false),  ///< process noise for wind velocity prediction (m/sec**2)

    PARAM_FLOAT(ekf2_gnd_eff_dz, 5.0f, false),  ///< barometric deadzone range for negative innovations (m)
    PARAM_FLOAT(ekf2_gnd_max_hgt, 0.5f, false), ///< maximum height above the ground level for expected negative baro innovations (m)

    // control of magnetometer fusion
    PARAM_FLOAT(ekf2_head_noise, 3.0e-1f, false), ///< measurement noise used for simple heading fusion (rad)
    PARAM_FLOAT(ekf2_mag_noise, 5.0e-2f, false),  ///< measurement noise used for 3-axis magnetoemeter fusion (Gauss)
    PARAM_FLOAT(ekf2_eas_noise, 1.4f, false),     ///< measurement noise used for airspeed fusion (m/sec)
    PARAM_FLOAT(ekf2_beta_noise, 0.3f, false),    ///< synthetic sideslip noise (rad)

    PARAM_FLOAT(ekf2_noaid_noise, 10.0f, false), ///< observation noise for non-aiding position fusion (m)
    PARAM_FLOAT(ekf2_baro_noise, 2.0f, false),   ///< observation noise for barometric height fusion (m)

    PARAM_FLOAT(ekf2_mag_decl, 0.0f, false), ///< magnetic declination (degrees)

    PARAM_INT32(ekf2_decl_type, MASK_USE_GEO_DECL | MASK_SAVE_GEO_DECL | MASK_FUSE_DECL, false), ///< bitmask used to control the handling of declination data

    PARAM_INT32(ekf2_mag_type, MAG_FUSE_TYPE_HEADING, false), ///< integer used to specify the type of magnetometer fusion used

    PARAM_INT32(ekf2_gps_check, MASK_GPS_SACC | MASK_GPS_HACC | MASK_GPS_NSATS, false), ///< bitmask used to control which GPS quality checks are used

    // measurement source control
    PARAM_INT32(ekf2_aid_mask, MASK_USE_GPS, false),                                         ///< bitmasked integer that selects which of the GPS and optical flow aiding sources will be used
    PARAM_INT32(ekf2_hgt_mode, VDIST_SENSOR_GPS, false),                                     ///< selects the primary source for height data
    PARAM_INT32(ekf2_terr_mask, TERRAIN_FUSE_RANGEFINDER | TERRAIN_FUSE_OPTICALFLOW, false), ///< bitmasked integer that selects which of range finder and optical flow aiding sources will be used for terrain estimation

    // range finder fusion
    PARAM_FLOAT(ekf2_rng_noise, 0.1f, false), ///< observation noise for range finder measurements (m)
    PARAM_INT32(ekf2_rng_aid, 0, false),      ///< enables use of a range finder even if primary height source is not range finder

    // vision estimate fusion
    PARAM_INT32(ekf2_ev_noise_md, VEHICLE_ODOMETRY_COVARIANCE_MATRIX_X_VARIANCE, false), ///< determine source of vision observation noise
    PARAM_FLOAT(ekf2_evp_noise, 0.1f, false),                                            ///< default position observation noise for exernal vision measurements (m)
    PARAM_FLOAT(ekf2_evv_noise, 0.1f, false),                                            ///< default velocity observation noise for exernal vision measurements (m/s)
    PARAM_FLOAT(ekf2_eva_noise, 0.05f, false),                                           ///< default angular observation noise for exernal vision measurements (rad)

    // optical flow fusion
    PARAM_FLOAT(ekf2_of_n_min, 0.15f, false), ///< best quality observation noise for optical flow LOS rate measurements (rad/sec)
    PARAM_FLOAT(ekf2_of_n_max, 0.5f, false),  ///< worst quality observation noise for optical flow LOS rate measurements (rad/sec)

    // control of airspeed and sideslip fusion
    PARAM_FLOAT(ekf2_arsp_thr, 2.0f, false), ///< A value of zero will disabled airspeed fusion. Any positive value sets the minimum airspeed which will be used (m/sec)
    PARAM_INT32(ekf2_fuse_beta, 0, false),   ///< Controls synthetic sideslip fusion, 0 disables, 1 enables

    // Multi-rotor drag specific force fusion
    PARAM_FLOAT(ekf2_drag_noise, 2.5f, false), ///< observation noise variance for drag specific force measurements (m/sec**2)**2

    PARAM_INT32(ekf2_mag_check, 0, false), ///< Mag field strength check

    PARAM_INT32(ekf2_synthetic_mag_z, 0, false), ///< Enables the use of a synthetic value for the Z axis of the magnetometer calculated from the 3D magnetic field vector at the location of the drone.

    PARAM_FLOAT(ekf2_req_gps_h, 10.0f, false) ///< Required GPS health time
};
PARAM_GROUP_DEFINE(INS, __param_list);

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
    MLOG_ELEMENT(airspeed, MLOG_FLOAT),
    MLOG_ELEMENT(lat, MLOG_DOUBLE),
    MLOG_ELEMENT(lon, MLOG_DOUBLE),
    MLOG_ELEMENT(alt, MLOG_DOUBLE),
    MLOG_ELEMENT(lat_0, MLOG_DOUBLE),
    MLOG_ELEMENT(lon_0, MLOG_DOUBLE),
    MLOG_ELEMENT(alt_0, MLOG_DOUBLE),
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
    McnNode_t airspeed_sub_node_t;

    imu_data_t imu_report;
    mag_data_t mag_report;
    baro_data_t baro_report;
    gps_data_t gps_report;
    rf_data_t rf_report;
    optflow_data_t optflow_report;
    airspeed_data_t airspeed_report;
} ins_handle;

static struct FMS_Handler {
    McnNode_t fms_sub_node_t;
    FMS_Out_Bus fms_report;
} fms_handle;

static struct Control_Handler {
    McnNode_t control_sub_node_t;
    Control_Out_Bus control_report;
} control_handle;

static uint8_t imu_data_updated;
static uint8_t mag_data_updated;
static uint8_t baro_data_updated;
static uint8_t gps_data_updated;
static uint8_t rf_data_updated;
static uint8_t optflow_data_updated;
static uint8_t airspeed_data_updated;

static int IMU_ID;
static int MAG_ID;
static int Barometer_ID;
static int GPS_ID;
static int Rangefinder_ID;
static int OpticalFlow_ID;
static int INS_Out_ID;

static char* model_info = "PX4 EKF v1.0.0";

fmt_model_info_t ins_model_info;

static int ins_output_echo(void* param)
{
    INS_Out_Bus ins_out;

    mcn_copy_from_hub((McnHub*)param, &ins_out);

    printf("timestamp:%u\n", ins_out.timestamp);
    printf("att: %.2f %.2f %.2f\n", RAD2DEG(ins_out.phi), RAD2DEG(ins_out.theta), RAD2DEG(ins_out.psi));
    printf("rate: %.2f %.2f %.2f\n", ins_out.p, ins_out.q, ins_out.r);
    printf("accel: %.2f %.2f %.2f\n", ins_out.ax, ins_out.ay, ins_out.az);
    printf("vel: %.2f %.2f %.2f\n", ins_out.vn, ins_out.ve, ins_out.vd);
    printf("xyh: %.2f %.2f %.2f, h_AGL: %.2f\n", ins_out.x_R, ins_out.y_R, ins_out.h_R, ins_out.h_AGL);
    printf("LLA: %lf %lf %f\n", ins_out.lat, ins_out.lon, ins_out.alt);
    printf("LLA0: %lf %lf %f\n", ins_out.lat_0, ins_out.lon_0, ins_out.alt_0);
    printf("standstill:%d att:%d heading:%d vel:%d LLA:%d xy:%d h:%d h_AGL:%d\n",
           BIT(ins_out.flag, 1) > 0,
           BIT(ins_out.flag, 2) > 0,
           BIT(ins_out.flag, 3) > 0,
           BIT(ins_out.flag, 4) > 0,
           BIT(ins_out.flag, 5) > 0,
           BIT(ins_out.flag, 6) > 0,
           BIT(ins_out.flag, 7) > 0,
           BIT(ins_out.flag, 8) > 0);
    printf("sensor valid, imu1:%d imu2:%d mag:%d baro:%d gps:%d\n", BIT(ins_out.status, 0) > 0, BIT(ins_out.status, 1) > 0, BIT(ins_out.status, 2) > 0, BIT(ins_out.status, 3) > 0, BIT(ins_out.status, 4) > 0);
    printf("------------------------------------------\n");

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

static void init_parameter(void)
{
    // FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_predict_us), &px4_ecl_params.ekf2_predict_us));
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_gyr_noise), &px4_ecl_params.ekf2_gyr_noise)); ///< IMU angular rate noise used for covariance prediction (rad/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_acc_noise), &px4_ecl_params.ekf2_acc_noise)); ///< IMU acceleration noise use for covariance prediction (m/sec**2)
    // process noise
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_gyr_b_noise), &px4_ecl_params.ekf2_gyr_b_noise)); ///< process noise for IMU rate gyro bias prediction (rad/sec**2)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_acc_b_noise), &px4_ecl_params.ekf2_acc_b_noise)); ///< process noise for IMU accelerometer bias prediction (m/sec**3)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_mag_e_noise), &px4_ecl_params.ekf2_mag_e_noise)); ///< process noise for earth magnetic field prediction (Gauss/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_mag_b_noise), &px4_ecl_params.ekf2_mag_b_noise)); ///< process noise for body magnetic field prediction (Gauss/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_wind_noise), &px4_ecl_params.ekf2_wind_noise));   ///< process noise for wind velocity prediction (m/sec**2)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_noaid_noise), &px4_ecl_params.ekf2_noaid_noise)); ///< observation noise for non-aiding position fusion (m)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_baro_noise), &px4_ecl_params.ekf2_baro_noise));   ///< observation noise for barometric height fusion (m)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_gnd_eff_dz), &px4_ecl_params.ekf2_gnd_eff_dz));   ///< barometric deadzone range for negative innovations (m)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_gnd_max_hgt), &px4_ecl_params.ekf2_gnd_max_hgt)); ///< maximum height above the ground level for expected negative baro innovations (m)
    // control of magnetometer fusion
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_head_noise), &px4_ecl_params.ekf2_head_noise)); ///< measurement noise used for simple heading fusion (rad)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_mag_noise), &px4_ecl_params.ekf2_mag_noise));   ///< measurement noise used for 3-axis magnetoemeter fusion (Gauss)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_eas_noise), &px4_ecl_params.ekf2_eas_noise));   ///< measurement noise used for airspeed fusion (m/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_beta_noise), &px4_ecl_params.ekf2_beta_noise)); ///< synthetic sideslip noise (rad)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_mag_decl), &px4_ecl_params.ekf2_mag_decl));     ///< magnetic declination (degrees)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_decl_type), &px4_ecl_params.ekf2_decl_type));   ///< bitmask used to control the handling of declination data
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_mag_type), &px4_ecl_params.ekf2_mag_type));     ///< integer used to specify the type of magnetometer fusion used
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_gps_check), &px4_ecl_params.ekf2_gps_check));   ///< bitmask used to control which GPS quality checks are used
    // measurement source control
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_aid_mask), &px4_ecl_params.ekf2_aid_mask));   ///< bitmasked integer that selects which of the GPS and optical flow aiding sources will be used
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_hgt_mode), &px4_ecl_params.ekf2_hgt_mode));   ///< selects the primary source for height data
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_terr_mask), &px4_ecl_params.ekf2_terr_mask)); ///< bitmasked integer that selects which of range finder and optical flow aiding sources will be used for terrain estimation
    // range finder fusion
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_rng_noise), &px4_ecl_params.ekf2_rng_noise)); ///< observation noise for range finder measurements (m)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_rng_aid), &px4_ecl_params.ekf2_rng_aid));     ///< enables use of a range finder even if primary height source is not range finder
    // vision estimate fusion
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_ev_noise_md), &px4_ecl_params.ekf2_ev_noise_md)); ///< determine source of vision observation noise
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_evp_noise), &px4_ecl_params.ekf2_evp_noise));     ///< default position observation noise for exernal vision measurements (m)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_evv_noise), &px4_ecl_params.ekf2_evv_noise));     ///< default velocity observation noise for exernal vision measurements (m/s)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_eva_noise), &px4_ecl_params.ekf2_eva_noise));     ///< default angular observation noise for exernal vision measurements (rad)
    // optical flow fusion
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_of_n_min), &px4_ecl_params.ekf2_of_n_min)); ///< best quality observation noise for optical flow LOS rate measurements (rad/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_of_n_max), &px4_ecl_params.ekf2_of_n_max)); ///< worst quality observation noise for optical flow LOS rate measurements (rad/sec)
    // control of airspeed and sideslip fusion
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_arsp_thr), &px4_ecl_params.ekf2_arsp_thr));   ///< A value of zero will disabled airspeed fusion. Any positive value sets the minimum airspeed which will be used (m/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_fuse_beta), &px4_ecl_params.ekf2_fuse_beta)); ///< Controls synthetic sideslip fusion, 0 disables, 1 enables
    // Multi-rotor drag specific force fusion
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_drag_noise), &px4_ecl_params.ekf2_drag_noise));           ///< observation noise variance for drag specific force measurements (m/sec**2)**2
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_mag_check), &px4_ecl_params.ekf2_mag_check));             ///< Mag field strength check
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_synthetic_mag_z), &px4_ecl_params.ekf2_synthetic_mag_z)); ///< Enables the use of a synthetic value for the Z axis of the magnetometer calculated from the 3D magnetic field vector at the location of the drone.
    FMT_CHECK(param_link_variable(PARAM_GET(INS, ekf2_req_gps_h), &px4_ecl_params.ekf2_req_gps_h));             ///< Required GPS health time
}

void ins_interface_step(uint32_t timestamp)
{
    static uint32_t last_timestamp;
    static IMU_Bus imu_bus;
    static MAG_Bus mag_bus;
    static Barometer_Bus baro_bus;
    static GPS_uBlox_Bus gps_bus;
    static Rangefinder_Bus rnf_bus;
    static Optical_Flow_Bus opt_flow_bus;
    static AirSpeed_Bus airspeed_bus;

    /* get sensor data */
    if (mcn_poll(ins_handle.imu_sub_node_t)) {
        mcn_copy(MCN_HUB(sensor_imu0), ins_handle.imu_sub_node_t, &ins_handle.imu_report);

        imu_bus.timestamp = timestamp;
        imu_bus.gyr_x = ins_handle.imu_report.gyr_B_radDs[0];
        imu_bus.gyr_y = ins_handle.imu_report.gyr_B_radDs[1];
        imu_bus.gyr_z = ins_handle.imu_report.gyr_B_radDs[2];
        imu_bus.acc_x = ins_handle.imu_report.acc_B_mDs2[0];
        imu_bus.acc_y = ins_handle.imu_report.acc_B_mDs2[1];
        imu_bus.acc_z = ins_handle.imu_report.acc_B_mDs2[2];

        bool clipping[3] = { false, false, false };
        uint32_t dt_imu = (timestamp >= last_timestamp) ? (timestamp - last_timestamp) : (0xFFFFFFFF - last_timestamp + timestamp);
        last_timestamp = timestamp;

        Ekf_IMU_update(timestamp, dt_imu, ins_handle.imu_report.gyr_B_radDs, ins_handle.imu_report.acc_B_mDs2, clipping);

        ld_set_IMU_data(ins_handle.imu_report.gyr_B_radDs, ins_handle.imu_report.acc_B_mDs2);

        imu_data_updated = 1;

        if (mcn_poll(ins_handle.mag_sub_node_t)) {
            mcn_copy(MCN_HUB(sensor_mag0), ins_handle.mag_sub_node_t, &ins_handle.mag_report);

            mag_bus.timestamp = timestamp;
            mag_bus.mag_x = ins_handle.mag_report.mag_B_gauss[0];
            mag_bus.mag_y = ins_handle.mag_report.mag_B_gauss[1];
            mag_bus.mag_z = ins_handle.mag_report.mag_B_gauss[2];

            Ekf_MAG_update(timestamp, ins_handle.mag_report.mag_B_gauss);

            mag_data_updated = 1;
        }

        if (mcn_poll(ins_handle.baro_sub_node_t)) {
            mcn_copy(MCN_HUB(sensor_baro), ins_handle.baro_sub_node_t, &ins_handle.baro_report);

            baro_bus.timestamp = timestamp;
            baro_bus.pressure = ins_handle.baro_report.pressure_pa;
            baro_bus.temperature = ins_handle.baro_report.temperature_deg;

            Ekf_BARO_update(timestamp, ins_handle.baro_report.altitude_m);

            baro_data_updated = 1;
        }

        /* update gps data */
        if (mcn_poll(ins_handle.gps_sub_node_t)) {
            mcn_copy(MCN_HUB(sensor_gps), ins_handle.gps_sub_node_t, &ins_handle.gps_report);

            gps_bus.timestamp = timestamp;
            gps_bus.fixType = ins_handle.gps_report.fixType;
            gps_bus.lat = ins_handle.gps_report.lat;
            gps_bus.lon = ins_handle.gps_report.lon;
            gps_bus.height = ins_handle.gps_report.height;
            gps_bus.velN = (int32_t)(ins_handle.gps_report.velN * 1e3);
            gps_bus.velE = (int32_t)(ins_handle.gps_report.velE * 1e3);
            gps_bus.velD = (int32_t)(ins_handle.gps_report.velD * 1e3);
            gps_bus.hAcc = (uint32_t)(ins_handle.gps_report.hAcc * 1e3);
            gps_bus.vAcc = (uint32_t)(ins_handle.gps_report.vAcc * 1e3);
            gps_bus.sAcc = (uint32_t)(ins_handle.gps_report.sAcc * 1e3);
            gps_bus.numSV = ins_handle.gps_report.numSV;

            Ekf_GPS_update(timestamp, ins_handle.gps_report.lon, ins_handle.gps_report.lat, ins_handle.gps_report.height, ins_handle.gps_report.hAcc, ins_handle.gps_report.vAcc, ins_handle.gps_report.velN, ins_handle.gps_report.velE, ins_handle.gps_report.velD, ins_handle.gps_report.vel, ins_handle.gps_report.cog, ins_handle.gps_report.sAcc, ins_handle.gps_report.fixType, ins_handle.gps_report.numSV);

            gps_data_updated = 1;
        }

        /* update rangefinder data */
        if (mcn_poll(ins_handle.rf_sub_node_t)) {
            mcn_copy(MCN_HUB(sensor_rangefinder), ins_handle.rf_sub_node_t, &ins_handle.rf_report);

            rnf_bus.timestamp = timestamp;
            rnf_bus.distance_m = ins_handle.rf_report.distance_m;

            if (ins_handle.rf_report.distance_m >= 0) {
                Ekf_RANGEFINDER_update(timestamp, ins_handle.rf_report.distance_m, 100);
            } else {
                Ekf_RANGEFINDER_update(timestamp, ins_handle.rf_report.distance_m, 0);
            }

            rf_data_updated = 1;
        }

        /* update optical flow data */
        if (mcn_poll(ins_handle.optflow_sub_node_t)) {
            mcn_copy(MCN_HUB(sensor_optflow), ins_handle.optflow_sub_node_t, &ins_handle.optflow_report);

            // TODO
            optflow_data_updated = 1;
        }

        /* update airspeed data */
        if (mcn_poll(ins_handle.airspeed_sub_node_t)) {
            mcn_copy(MCN_HUB(sensor_airspeed), ins_handle.airspeed_sub_node_t, &ins_handle.airspeed_report);

            airspeed_bus.timestamp = timestamp;

            float true_airspeed = sqrtf(fabs(airspeed_bus.diff_pressure) * 2 / 1.225f) * SIGN(airspeed_bus.diff_pressure);
            Ekf_AIRSPEED_update(timestamp, true_airspeed, 1);
#ifdef VEHICLE_TYPE_FIXWING
            ld_set_airspeed_validated((uint64_t)timestamp, airspeed_bus.true_airspeed);
#endif
            airspeed_data_updated = 1;
        }

        if (mcn_poll(fms_handle.fms_sub_node_t)) {
            mcn_copy(MCN_HUB(fms_output), fms_handle.fms_sub_node_t, &fms_handle.fms_report);

            switch (fms_handle.fms_report.status) {
            case 1:
                ld_set_armed(false);
                break;
            case 2:
                ld_set_armed(true);
                break;
            case 3:
                ld_set_armed(true);
                break;
            }

#ifdef VEHICLE_TYPE_QUADCOPTER
            ld_set_trajectory_vz(fms_handle.fms_report.w_cmd);
            ld_set_flag_control_climb_rate_enabled(true);
#endif
        }

#ifdef VEHICLE_TYPE_QUADCOPTER
        if (mcn_poll(control_handle.control_sub_node_t)) {
            mcn_copy(MCN_HUB(control_output), control_handle.control_sub_node_t, &control_handle.control_report);

            uint64_t actuator_count = 0;
            float thr = 0;
            for (int i = 0; i < 16; i++) {
                if (control_handle.control_report.actuator_cmd[i] != 0) {
                    thr += ((float)control_handle.control_report.actuator_cmd[i] - 1000.0f) / 1000.0f;
                    actuator_count += 1;
                }
            }
            if (actuator_count > 0)
                thr /= actuator_count;

            ld_set_actuator_controls_throttle(thr);
        }
#endif
        /* run INS */
        px4_ecl_step();
    }

    /* update ins output timestamp */
    px4_ecl_out_bus.timestamp = timestamp;

    /* publish INS output */
    mcn_publish(MCN_HUB(ins_output), &px4_ecl_out_bus);

    /* record INS input bus data if updated */
    if (imu_data_updated) {
        imu_data_updated = 0;
        /* Log IMU data if IMU updated */
        mlog_push_msg((uint8_t*)&imu_bus, IMU_ID, sizeof(imu_bus));
    }

    if (mag_data_updated) {
        mag_data_updated = 0;
        /* Log Magnetometer data */
        mlog_push_msg((uint8_t*)&mag_bus, MAG_ID, sizeof(mag_bus));
    }

    if (baro_data_updated) {
        baro_data_updated = 0;
        /* Log Barometer data */
        mlog_push_msg((uint8_t*)&baro_bus, Barometer_ID, sizeof(baro_bus));
    }

    if (gps_data_updated) {
        gps_data_updated = 0;
        /* Log GPS data */
        mlog_push_msg((uint8_t*)&gps_bus, GPS_ID, sizeof(gps_bus));
    }

    if (rf_data_updated) {
        rf_data_updated = 0;
        /* Log Rangefinder data */
        mlog_push_msg((uint8_t*)&rnf_bus, Rangefinder_ID, sizeof(rnf_bus));
    }

    if (optflow_data_updated) {
        optflow_data_updated = 0;
        /* Log Optical Flow data */
        mlog_push_msg((uint8_t*)&opt_flow_bus, OpticalFlow_ID, sizeof(opt_flow_bus));
    }

    /* Log INS output bus data */
    DEFINE_TIMETAG(ins_output, 100);
    if (check_timetag(TIMETAG(ins_output))) {
        /* Log INS out data */
        mlog_push_msg((uint8_t*)&px4_ecl_out_bus, INS_Out_ID, sizeof(px4_ecl_out_bus));
    }
}

void ins_interface_init(void)
{
    ins_model_info.period = 2;
    ins_model_info.info = model_info;

    mcn_advertise(MCN_HUB(ins_output), ins_output_echo);

    ins_handle.imu_sub_node_t = mcn_subscribe(MCN_HUB(sensor_imu0), NULL, NULL);
    ins_handle.mag_sub_node_t = mcn_subscribe(MCN_HUB(sensor_mag0), NULL, NULL);
    ins_handle.baro_sub_node_t = mcn_subscribe(MCN_HUB(sensor_baro), NULL, NULL);
    ins_handle.gps_sub_node_t = mcn_subscribe(MCN_HUB(sensor_gps), NULL, NULL);
    ins_handle.rf_sub_node_t = mcn_subscribe(MCN_HUB(sensor_rangefinder), NULL, NULL);
    ins_handle.optflow_sub_node_t = mcn_subscribe(MCN_HUB(sensor_optflow), NULL, NULL);
    ins_handle.airspeed_sub_node_t = mcn_subscribe(MCN_HUB(sensor_airspeed), NULL, NULL);

    fms_handle.fms_sub_node_t = mcn_subscribe(MCN_HUB(fms_output), NULL, NULL);
    control_handle.control_sub_node_t = mcn_subscribe(MCN_HUB(control_output), NULL, NULL);

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

    init_parameter();

    px4_ecl_init();
}
