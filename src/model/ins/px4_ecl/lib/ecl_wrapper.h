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
#ifndef ECL_WRAPPER_H
#define ECL_WRAPPER_H

// modify for fmt interface
void Ekf_create(void);
void* Ekf_getParamHandle(void);
int32_t* Ekf_get_params_vdist_sensor_type();
int32_t* Ekf_get_params_sensor_interval_min_ms();
int32_t* Ekf_get_params_mag_fusion_type();
//*************************** set params ***************************//
void Ekf_set_param_ekf2_gyr_noise(float ekf2_gyr_noise);
void Ekf_set_param_ekf2_acc_noise(float ekf2_acc_noise);
void Ekf_set_param_ekf2_gyr_b_noise(float ekf2_gyr_b_noise);
void Ekf_set_param_ekf2_acc_b_noise(float ekf2_acc_b_noise);
void Ekf_set_param_ekf2_mag_e_noise(float ekf2_mag_e_noise);
void Ekf_set_param_ekf2_mag_b_noise(float ekf2_mag_b_noise);
void Ekf_set_param_ekf2_wind_noise(float ekf2_wind_noise);
void Ekf_set_param_ekf2_noaid_noise(float ekf2_noaid_noise);
void Ekf_set_param_ekf2_baro_noise(float ekf2_baro_noise);
void Ekf_set_param_ekf2_gnd_eff_dz(float ekf2_gnd_eff_dz);
void Ekf_set_param_ekf2_gnd_max_hgt(float ekf2_gnd_max_hgt);
void Ekf_set_param_ekf2_head_noise(float ekf2_head_noise);
void Ekf_set_param_ekf2_mag_noise(float ekf2_mag_noise);
void Ekf_set_param_ekf2_eas_noise(float ekf2_eas_noise);
void Ekf_set_param_ekf2_beta_noise(float ekf2_beta_noise);
void Ekf_set_param_ekf2_mag_decl(float ekf2_mag_decl);
void Ekf_set_param_ekf2_decl_type(int32_t ekf2_decl_type);
void Ekf_set_param_ekf2_mag_type(int32_t ekf2_mag_type);
void Ekf_set_param_ekf2_gps_check(int32_t ekf2_gps_check);
void Ekf_set_param_ekf2_aid_mask(int32_t ekf2_aid_mask);
void Ekf_set_param_ekf2_hgt_mode(int32_t ekf2_hgt_mode);
void Ekf_set_param_ekf2_terr_mask(int32_t ekf2_terr_mask);
void Ekf_set_param_ekf2_rng_noise(float ekf2_rng_noise);
void Ekf_set_param_ekf2_rng_aid(int32_t ekf2_rng_aid);
void Ekf_set_param_ekf2_of_n_min(float ekf2_of_n_min);
void Ekf_set_param_ekf2_of_n_max(float ekf2_of_n_max);
void Ekf_set_param_ekf2_arsp_thr(float ekf2_arsp_thr);
void Ekf_set_param_ekf2_drag_noise(float ekf2_drag_noise);
void Ekf_set_param_ekf2_mag_check(int32_t ekf2_mag_check);
void Ekf_set_param_ekf2_synthetic_mag_z(int32_t ekf2_synthetic_mag_z);
//*************************** set params ***************************//
void Ekf_set_min_required_gps_health_time(uint32_t time_us);
void Ekf_setEkfGlobalOrigin(const double latitude, const double longitude, const float altitude);
void Ekf_set_AccelBias_uncertain(float uncertain);
void Ekf_set_GyroBias_uncertain(float uncertain);
void Ekf_resetAccelBias(void);
void Ekf_resetGyroBias(void);
void Ekf_set_fuse_beta_flag(bool fuse_beta);
void Ekf_set_is_fixed_wing(bool is_fixed_wing);
void Ekf_set_gnd_effect_flag(bool gnd_effect);
void Ekf_set_in_air_status(bool in_air);
void Ekf_IMU_update(uint32_t timestamp_ms, uint32_t dt_ms, float gyr_B_radDs[3], float acc_B_mDs2[3], bool clipping[3]);
void Ekf_MAG_update(uint32_t timestamp_ms, float mag_B_gauss[3]);
void Ekf_BARO_update(uint32_t timestamp_ms, float pressure_alt_meter);
void Ekf_GPS_update(uint32_t timestamp_ms, int32_t lon, int32_t lat, int32_t height,
                    float hAcc, float vAcc, float velN, float velE, float velD, float vel, float cog,
                    float sAcc, uint8_t fixType, uint8_t numSV);
void Ekf_RANGEFINDER_update(uint32_t timestamp_ms, float rng, int8_t quality);
void Ekf_AIRSPEED_update(uint32_t timestamp_ms, float true_airspeed, float eas2tas);
bool Ekf_step(void);
void Ekf_get_attitude(void);
void Ekf_get_acc(void);
void Ekf_get_local_position(void);
void Ekf_get_global_position(void);
void Ekf_get_TerrainVertPos(void);

// land detector
void ld_creat(void);
void ld_set_time(uint64_t nowUs);
void ld_set_armed(bool armed);
void ld_set_IMU_data(float gyroRate[3], float acceleration[3]);
void ld_set_dist_bottom_is_observable(bool observable);
void ld_set_vehicle_local_position(void);
void ld_set_vehicle_imu_status(uint64_t timeStampUs);
bool ld_get_landed_state(void);
bool ld_get_gnd_effect(void);
bool ld_IsUpdated(void);

#ifdef VEHICLE_TYPE_QUADCOPTER
void ld_set_actuator_controls_throttle(float throttle);
void ld_set_flag_control_climb_rate_enabled(bool enable);
void ld_set_hover_thrust_estimate(uint64_t nowUs, float hover_thrust, bool valid);
void ld_set_trajectory_vz(float vz);
#endif
#ifdef VEHICLE_TYPE_FIXWING
void ld_set_airspeed_validated(uint64_t timeStampUs, float true_airspeed_m_s);
#endif

void ld_step(void);

#endif