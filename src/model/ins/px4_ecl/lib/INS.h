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
#ifndef INS_H__
#define INS_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DEFINED_TYPEDEF_FOR_IMU_Bus_
    #define DEFINED_TYPEDEF_FOR_IMU_Bus_

typedef struct {
    uint32_t timestamp;
    float gyr_x;
    float gyr_y;
    float gyr_z;
    float acc_x;
    float acc_y;
    float acc_z;
} IMU_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MAG_Bus_
    #define DEFINED_TYPEDEF_FOR_MAG_Bus_

typedef struct {
    uint32_t timestamp;
    float mag_x;
    float mag_y;
    float mag_z;
} MAG_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Barometer_Bus_
    #define DEFINED_TYPEDEF_FOR_Barometer_Bus_

typedef struct {
    uint32_t timestamp;
    float pressure;
    float temperature;
} Barometer_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_
    #define DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_

typedef struct {
    uint32_t timestamp;
    uint32_t iTOW;
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    uint8_t valid;
    uint32_t tAcc;
    int32_t nano;
    uint8_t fixType;
    uint8_t flags;
    uint8_t reserved1;
    uint8_t numSV;
    int32_t lon;
    int32_t lat;
    int32_t height;
    int32_t hMSL;
    uint32_t hAcc;
    uint32_t vAcc;
    int32_t velN;
    int32_t velE;
    int32_t velD;
    int32_t gSpeed;
    int32_t heading;
    uint32_t sAcc;
    uint32_t headingAcc;
    uint16_t pDOP;
    uint16_t reserved2;
} GPS_uBlox_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Rangefinder_Bus_
    #define DEFINED_TYPEDEF_FOR_Rangefinder_Bus_

typedef struct {
    uint32_t timestamp;
    float distance_m;
} Rangefinder_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Optical_Flow_Bus_
    #define DEFINED_TYPEDEF_FOR_Optical_Flow_Bus_

typedef struct {
    uint32_t timestamp;
    float vx;
    float vy;
    uint8_t quality;
    uint8_t reserved1;
    uint16_t reserved2;
} Optical_Flow_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_AirSpeed_Bus_
    #define DEFINED_TYPEDEF_FOR_AirSpeed_Bus_

typedef struct {
    uint32_t timestamp;
    float diff_pressure;
    float temperature;
} AirSpeed_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_External_Pos_Bus_
#define DEFINED_TYPEDEF_FOR_External_Pos_Bus_

typedef struct {
  uint32_t timestamp;
  uint32_t field_valid;
  float x;
  float y;
  float z;
  float phi;
  float theta;
  float psi;
} External_Pos_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_INS_Out_Bus_
    #define DEFINED_TYPEDEF_FOR_INS_Out_Bus_

typedef struct {
    uint32_t timestamp;
    float phi;
    float theta;
    float psi;
    float quat[4];
    float p;
    float q;
    float r;
    float ax;
    float ay;
    float az;
    float vn;
    float ve;
    float vd;
    float airspeed;
    double lat;
    double lon;
    double alt;
    double lat_0;
    double lon_0;
    double alt_0;
    double dx_dlat;
    double dy_dlon;
    float x_R;
    float y_R;
    float h_R;
    float h_AGL;
    uint32_t flag;
    uint32_t status;
} INS_Out_Bus;

#endif

typedef struct {
    float ekf2_gyr_noise;         ///< IMU angular rate noise used for covariance prediction (rad/sec)
    float ekf2_acc_noise;         ///< IMU acceleration noise use for covariance prediction (m/sec**2)
    float ekf2_gyr_b_noise;       ///< process noise for IMU rate gyro bias prediction (rad/sec**2)
    float ekf2_acc_b_noise;       ///< process noise for IMU accelerometer bias prediction (m/sec**3)
    float ekf2_mag_e_noise;       ///< process noise for earth magnetic field prediction (Gauss/sec)
    float ekf2_mag_b_noise;       ///< process noise for body magnetic field prediction (Gauss/sec)
    float ekf2_wind_noise;        ///< process noise for wind velocity prediction (m/sec**2)
    float ekf2_noaid_noise;       ///< observation noise for non-aiding position fusion (m)
    float ekf2_baro_noise;        ///< observation noise for barometric height fusion (m)
    float ekf2_gnd_eff_dz;        ///< barometric deadzone range for negative innovations (m)
    float ekf2_gnd_max_hgt;       ///< maximum height above the ground level for expected negative baro innovations (m)
    float ekf2_head_noise;        ///< measurement noise used for simple heading fusion (rad)
    float ekf2_mag_noise;         ///< measurement noise used for 3-axis magnetoemeter fusion (Gauss)
    float ekf2_eas_noise;         ///< measurement noise used for airspeed fusion (m/sec)
    float ekf2_beta_noise;        ///< synthetic sideslip noise (rad)
    float ekf2_mag_decl;          ///< magnetic declination (degrees)
    int32_t ekf2_decl_type;       ///< bitmask used to control the handling of declination data
    int32_t ekf2_mag_type;        ///< integer used to specify the type of magnetometer fusion used
    int32_t ekf2_gps_check;       ///< bitmask used to control which GPS quality checks are used
    int32_t ekf2_aid_mask;        ///< bitmasked integer that selects which of the GPS and optical flow aiding sources will be used
    int32_t ekf2_hgt_mode;        ///< selects the primary source for height data
    int32_t ekf2_terr_mask;       ///< bitmasked integer that selects which of range finder and optical flow aiding sources will be used for terrain estimation
    float ekf2_rng_noise;         ///< observation noise for range finder measurements (m)
    int32_t ekf2_rng_aid;         ///< enables use of a range finder even if primary height source is not range finder
    int32_t ekf2_ev_noise_md;     ///< determine source of vision observation noise
    float ekf2_evp_noise;         ///< default position observation noise for exernal vision measurements (m)
    float ekf2_evv_noise;         ///< default velocity observation noise for exernal vision measurements (m/s)
    float ekf2_eva_noise;         ///< default angular observation noise for exernal vision measurements (rad)
    float ekf2_of_n_min;          ///< best quality observation noise for optical flow LOS rate measurements (rad/sec)
    float ekf2_of_n_max;          ///< worst quality observation noise for optical flow LOS rate measurements (rad/sec)
    float ekf2_arsp_thr;          ///< A value of zero will disabled airspeed fusion. Any positive value sets the minimum airspeed which will be used (m/sec)
    int32_t ekf2_fuse_beta;       ///< Controls synthetic sideslip fusion, 0 disables, 1 enables
    float ekf2_drag_noise;        ///< observation noise variance for drag specific force measurements (m/sec**2)**2
    int32_t ekf2_mag_check;       ///< Mag field strength check
    int32_t ekf2_synthetic_mag_z; ///< Enables the use of a synthetic value for the Z axis of the magnetometer calculated from the 3D magnetic field vector at the location of the drone.
    float ekf2_req_gps_h;         ///< Required GPS health time
} INS_Params;

extern INS_Out_Bus px4_ecl_out_bus;
extern INS_Params px4_ecl_params;

void px4_ecl_init(void);
void px4_ecl_step(void);

#ifdef __cplusplus
}
#endif

#endif
