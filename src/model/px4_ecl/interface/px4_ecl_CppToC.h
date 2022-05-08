#ifndef PX4_ECL_CPPTOC_H
#define PX4_ECL_CPPTOC_H

// modify for fmt interface
void Ekf_new(void);
void* Ekf_getParamHandle(void);
int32_t* Ekf_get_params_vdist_sensor_type();
int32_t* Ekf_get_params_sensor_interval_min_ms();
int32_t* Ekf_get_params_mag_fusion_type();
//*************************** set params ***************************//
void Ekf_set_param_ekf2_gyr_noise(float _param_ekf2_gyr_noise);
void Ekf_set_param_ekf2_acc_noise(float _param_ekf2_acc_noise);
void Ekf_set_param_ekf2_gyr_b_noise(float _param_ekf2_gyr_b_noise);
void Ekf_set_param_ekf2_acc_b_noise(float _param_ekf2_acc_b_noise);
void Ekf_set_param_ekf2_mag_e_noise(float _param_ekf2_mag_e_noise);
void Ekf_set_param_ekf2_mag_b_noise(float _param_ekf2_mag_b_noise);
void Ekf_set_param_ekf2_wind_noise(float _param_ekf2_wind_noise);
void Ekf_set_param_ekf2_noaid_noise(float _param_ekf2_noaid_noise);
void Ekf_set_param_ekf2_baro_noise(float _param_ekf2_baro_noise);
void Ekf_set_param_ekf2_gnd_eff_dz(float _param_ekf2_gnd_eff_dz);
void Ekf_set_param_ekf2_gnd_max_hgt(float _param_ekf2_gnd_max_hgt);
void Ekf_set_param_ekf2_head_noise(float _param_ekf2_head_noise);
void Ekf_set_param_ekf2_mag_noise(float _param_ekf2_mag_noise);
void Ekf_set_param_ekf2_eas_noise(float _param_ekf2_eas_noise);
void Ekf_set_param_ekf2_beta_noise(float _param_ekf2_beta_noise);
void Ekf_set_param_ekf2_mag_decl(float _param_ekf2_mag_decl);
void Ekf_set_param_ekf2_decl_type(int32_t _param_ekf2_decl_type);
void Ekf_set_param_ekf2_mag_type(int32_t _param_ekf2_mag_type);
void Ekf_set_param_ekf2_gps_check(int32_t _param_ekf2_gps_check);
void Ekf_set_param_ekf2_aid_mask(int32_t _param_ekf2_aid_mask);
void Ekf_set_param_ekf2_hgt_mode(int32_t _param_ekf2_hgt_mode);
void Ekf_set_param_ekf2_terr_mask(int32_t _param_ekf2_terr_mask);
void Ekf_set_param_ekf2_rng_noise(float _param_ekf2_rng_noise);
void Ekf_set_param_ekf2_rng_aid(int32_t _param_ekf2_rng_aid);
void Ekf_set_param_ekf2_of_n_min(float _param_ekf2_of_n_min);
void Ekf_set_param_ekf2_of_n_max(float _param_ekf2_of_n_max);
void Ekf_set_param_ekf2_arsp_thr(float _param_ekf2_arsp_thr);
void Ekf_set_param_ekf2_drag_noise(float _param_ekf2_drag_noise);
void Ekf_set_param_ekf2_mag_check(int32_t _param_ekf2_mag_check);
void Ekf_set_param_ekf2_synthetic_mag_z(int32_t _param_ekf2_synthetic_mag_z);
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
void Ekf_IMU_update(bool updated, uint32_t timestamp_ms, uint32_t dt_ms, float gyr_B_radDs[3], float acc_B_mDs2[3], bool clipping[3]);
void Ekf_MAG_update(bool updated, uint32_t timestamp_ms, float mag_B_gauss[3]);
void Ekf_BARO_update(bool updated, uint32_t timestamp_ms, float pressure_alt_meter);
void Ekf_GPS_update(bool updated, uint32_t timestamp_ms, int32_t lon, int32_t lat, int32_t height, 
					float hAcc, float vAcc, float velN, float velE,	float velD,	float vel,float cog, 
					float sAcc, uint8_t fixType, uint8_t numSV);
bool Ekf_step(void);
bool Ekf_get_estimator_quaternion(void);
void Ekf_get_estimator_angrate(void);
void Ekf_get_estimator_acc(void);
void Ekf_get_estimator_vel(void);
void Ekf_get_estimator_position(void);
void Ekf_get_estimator_global_position(void);
void Ekf_get_estimator_TerrainVertPos(void);

#endif