#include "ekf.h"
#include <ecl.h>
#include <mathlib/mathlib.h>
#include "px4_ecl_interface.h"

// modify for fmt interface
Ekf *_ekf;
extern "C" {

void Ekf_new(void){
	_ekf = new Ekf;
}

void Ekf_set_min_required_gps_health_time(uint32_t time_us){
	_ekf->set_min_required_gps_health_time(time_us);
}

void* Ekf_getParamHandle(void){
	return (void*)_ekf->getParamHandle();
}

int32_t* Ekf_get_params_vdist_sensor_type(){
	return &(_ekf->getParamHandle()->vdist_sensor_type);
}

//*************************** set params ***************************//
void Ekf_set_param_ekf2_gyr_noise(float _param_ekf2_gyr_noise){
	_ekf->getParamHandle()->gyro_noise = _param_ekf2_gyr_noise;
}

void Ekf_set_param_ekf2_acc_noise(float _param_ekf2_acc_noise){
	_ekf->getParamHandle()->accel_noise = _param_ekf2_acc_noise;
}

void Ekf_set_param_ekf2_gyr_b_noise(float _param_ekf2_gyr_b_noise){
	_ekf->getParamHandle()->gyro_bias_p_noise = _param_ekf2_gyr_b_noise;
}

void Ekf_set_param_ekf2_acc_b_noise(float _param_ekf2_acc_b_noise){
	_ekf->getParamHandle()->accel_bias_p_noise = _param_ekf2_acc_b_noise;
}

void Ekf_set_param_ekf2_mag_e_noise(float _param_ekf2_mag_e_noise){
	_ekf->getParamHandle()->mage_p_noise = _param_ekf2_mag_e_noise;
}

void Ekf_set_param_ekf2_mag_b_noise(float _param_ekf2_mag_b_noise){
	_ekf->getParamHandle()->magb_p_noise = _param_ekf2_mag_b_noise;
}

void Ekf_set_param_ekf2_wind_noise(float _param_ekf2_wind_noise){
	_ekf->getParamHandle()->wind_vel_p_noise = _param_ekf2_wind_noise;
}

void Ekf_set_param_ekf2_noaid_noise(float _param_ekf2_noaid_noise){
	_ekf->getParamHandle()->pos_noaid_noise = _param_ekf2_noaid_noise;
}

void Ekf_set_param_ekf2_baro_noise(float _param_ekf2_baro_noise){
	_ekf->getParamHandle()->baro_noise = _param_ekf2_baro_noise;
}

void Ekf_set_param_ekf2_gnd_eff_dz(float _param_ekf2_gnd_eff_dz){
	_ekf->getParamHandle()->gnd_effect_deadzone = _param_ekf2_gnd_eff_dz;
}

void Ekf_set_param_ekf2_gnd_max_hgt(float _param_ekf2_gnd_max_hgt){
	_ekf->getParamHandle()->gnd_effect_max_hgt = _param_ekf2_gnd_max_hgt;
}

void Ekf_set_param_ekf2_head_noise(float _param_ekf2_head_noise){
	_ekf->getParamHandle()->mag_heading_noise = _param_ekf2_head_noise;
}

void Ekf_set_param_ekf2_mag_noise(float _param_ekf2_mag_noise){
	_ekf->getParamHandle()->mag_noise = _param_ekf2_mag_noise;
}

void Ekf_set_param_ekf2_eas_noise(float _param_ekf2_eas_noise){
	_ekf->getParamHandle()->eas_noise = _param_ekf2_eas_noise;
}

void Ekf_set_param_ekf2_beta_noise(float _param_ekf2_beta_noise){
	_ekf->getParamHandle()->beta_noise = _param_ekf2_beta_noise;
}

void Ekf_set_param_ekf2_mag_decl(float _param_ekf2_mag_decl){
	_ekf->getParamHandle()->mag_declination_deg = _param_ekf2_mag_decl;
}

void Ekf_set_param_ekf2_decl_type(int32_t _param_ekf2_decl_type){
	_ekf->getParamHandle()->mag_declination_source = _param_ekf2_decl_type;
}

void Ekf_set_param_ekf2_mag_type(int32_t _param_ekf2_mag_type){
	_ekf->getParamHandle()->mag_fusion_type = _param_ekf2_mag_type;
}

void Ekf_set_param_ekf2_gps_check(int32_t _param_ekf2_gps_check){
	_ekf->getParamHandle()->gps_check_mask = _param_ekf2_gps_check;
}

void Ekf_set_param_ekf2_aid_mask(int32_t _param_ekf2_aid_mask){
	_ekf->getParamHandle()->fusion_mode = _param_ekf2_aid_mask;
}

void Ekf_set_param_ekf2_hgt_mode(int32_t _param_ekf2_hgt_mode){
	_ekf->getParamHandle()->vdist_sensor_type = _param_ekf2_hgt_mode;
}

void Ekf_set_param_ekf2_terr_mask(int32_t _param_ekf2_terr_mask){
	_ekf->getParamHandle()->terrain_fusion_mode = _param_ekf2_terr_mask;
}

void Ekf_set_param_ekf2_rng_noise(float _param_ekf2_rng_noise){
	_ekf->getParamHandle()->range_noise = _param_ekf2_rng_noise;
}

void Ekf_set_param_ekf2_rng_aid(int32_t _param_ekf2_rng_aid){
	_ekf->getParamHandle()->range_aid = _param_ekf2_rng_aid;
}

void Ekf_set_param_ekf2_of_n_min(float _param_ekf2_of_n_min){
	_ekf->getParamHandle()->flow_noise = _param_ekf2_of_n_min;
}

void Ekf_set_param_ekf2_of_n_max(float _param_ekf2_of_n_max){
	_ekf->getParamHandle()->flow_noise_qual_min = _param_ekf2_of_n_max;
}

void Ekf_set_param_ekf2_arsp_thr(float _param_ekf2_arsp_thr){
	_ekf->getParamHandle()->arsp_thr = _param_ekf2_arsp_thr;
}

void Ekf_set_param_ekf2_drag_noise(float _param_ekf2_drag_noise){
	_ekf->getParamHandle()->drag_noise = _param_ekf2_drag_noise;
}

void Ekf_set_param_ekf2_mag_check(int32_t _param_ekf2_mag_check){
	_ekf->getParamHandle()->check_mag_strength = _param_ekf2_mag_check;
}

void Ekf_set_param_ekf2_synthetic_mag_z(int32_t _param_ekf2_synthetic_mag_z){
	_ekf->getParamHandle()->synthesize_mag_z = _param_ekf2_synthetic_mag_z;
}
//*************************** set params ***************************//
 
int32_t* Ekf_get_params_sensor_interval_min_ms(){
	return &(_ekf->getParamHandle()->sensor_interval_min_ms);
}

int32_t* Ekf_get_params_mag_fusion_type(){
	return &(_ekf->getParamHandle()->mag_fusion_type);
}

void Ekf_setEkfGlobalOrigin(const double latitude, const double longitude, const float altitude){
	_ekf->setEkfGlobalOrigin(latitude, longitude, altitude);

}

void EKf_getEkfGlobalOrigin(uint64_t &origin_time, double &latitude, double &longitude, float &origin_alt){
	_ekf->getEkfGlobalOrigin(origin_time,latitude,longitude,origin_alt);
}

void Ekf_set_AccelBias_uncertain(float uncertain){ 
	((parameters*)_ekf->getParamHandle())->switch_on_accel_bias = uncertain;
}

void Ekf_set_GyroBias_uncertain(float uncertain){ 
	((parameters*)_ekf->getParamHandle())->switch_on_gyro_bias = uncertain;
}

void Ekf_resetAccelBias(void){
	_ekf->resetAccelBias();
}

void Ekf_resetGyroBias(void){
	_ekf->resetGyroBias();
}

void Ekf_set_fuse_beta_flag(bool fuse_beta){
	_ekf->set_fuse_beta_flag(fuse_beta);
}

void Ekf_set_is_fixed_wing(bool is_fixed_wing){
	_ekf->set_is_fixed_wing(is_fixed_wing);
}

void Ekf_set_gnd_effect_flag(bool gnd_effect){
	_ekf->set_gnd_effect_flag(gnd_effect);
}

void Ekf_set_in_air_status(bool in_air){
	_ekf->set_in_air_status(in_air);
}

void Ekf_IMU_update(bool updated, uint32_t timestamp_ms, uint32_t dt_ms, float gyr_B_radDs[3], float acc_B_mDs2[3], bool clipping[3]){

	if (updated) {

		imuSample imu_sample_new {};

		imu_sample_new.time_us = timestamp_ms * 1.0e3f;

		imu_sample_new.delta_ang_dt = dt_ms * 1.0e-3f;
		imu_sample_new.delta_ang = Vector3f{gyr_B_radDs} * imu_sample_new.delta_ang_dt;

		imu_sample_new.delta_vel_dt = dt_ms * 1.0e-3f;
		imu_sample_new.delta_vel = Vector3f{acc_B_mDs2} * imu_sample_new.delta_vel_dt;

		imu_sample_new.delta_vel_clipping[0] = clipping[0];
		imu_sample_new.delta_vel_clipping[1] = clipping[1];
		imu_sample_new.delta_vel_clipping[2] = clipping[2];

		_ekf->setIMUData(imu_sample_new);
	}

}

void Ekf_MAG_update(bool updated, uint32_t timestamp_ms, float mag_B_gauss[3]){ 

	if (updated) {

		magSample mag_sample_new {};

		mag_sample_new.time_us = timestamp_ms * 1.0e3f;
		mag_sample_new.mag = Vector3f{mag_B_gauss};

		_ekf->setMagData(mag_sample_new);
	}

}

void Ekf_BARO_update(bool updated, uint32_t timestamp_ms, float pressure_alt_meter){

	if (updated) {

		baroSample baro_sample_new {};

		baro_sample_new.time_us = timestamp_ms * 1.0e3f;
		baro_sample_new.hgt = pressure_alt_meter;

		_ekf->setBaroData(baro_sample_new);
	}
}

void Ekf_GPS_update(bool updated, uint32_t timestamp_ms, int32_t lon, int32_t lat, int32_t height, 
					float hAcc, float vAcc, float velN, float velE,	float velD,	float vel,float cog, 
					float sAcc, uint8_t fixType, uint8_t numSV){

	if (updated) {

		gps_message gps_message_new;

		gps_message_new.time_usec = timestamp_ms * 1.0e3f;
		gps_message_new.lat = lat;
		gps_message_new.lon = lon;
		gps_message_new.alt = height;
		gps_message_new.yaw = NAN;
		gps_message_new.yaw_offset = 0;
		// gps_message_new.fix_type = fixType,
		gps_message_new.eph = hAcc * 1.0e-3f;
		gps_message_new.epv = vAcc * 1.0e-3f;
		gps_message_new.sacc = sAcc * 1.0e-3f;
		gps_message_new.vel_m_s = sqrt(velN*velN + velE*velE + velD*velD) * 1.0e-3f;
		gps_message_new.vel_ned = Vector3f{velN * 1.0e-3f, velE * 1.0e-3f, velD * 1.0e-3f};
		gps_message_new.vel_ned_valid = true;
		gps_message_new.nsats = numSV;
		gps_message_new.pdop = sqrt(hAcc*hAcc + vAcc*vAcc) * 1.0e-3f;

		switch(fixType){
			case 0x02:
				gps_message_new.fix_type = 2;
				break;
			case 0x03:
				gps_message_new.fix_type = 3;
				break;
			default:
				gps_message_new.fix_type = 0;
				break;
		}

		_ekf->setGpsData(gps_message_new);
	}
}

bool Ekf_step(void){
	return _ekf->update();
}


extern PX4_ECL_Out_Bus px4_ecl_out_bus;
bool Ekf_get_estimator_quaternion(void){
	
	if(_ekf->attitude_valid()){

		const Quatf q{_ekf->calculate_quaternion()};
		px4_ecl_out_bus.quat[0] = q(0);
		px4_ecl_out_bus.quat[1] = q(1);
		px4_ecl_out_bus.quat[2] = q(2);
		px4_ecl_out_bus.quat[3] = q(3);

        const Eulerf euler(q);
		px4_ecl_out_bus.phi 	= euler(0);
		px4_ecl_out_bus.theta 	= euler(1);
		px4_ecl_out_bus.psi 	= euler(2);

		px4_ecl_out_bus.flag |= 1<<2;
		px4_ecl_out_bus.flag |= 1<<3;

		return true;
	}else{
		return false;
	}
}

void Ekf_get_estimator_angrate(void){
	
	const Vector3f gyro_bias{_ekf->getGyroBias()};
	const imuSample imusample(_ekf->get_imu_sample_delayed());
	const Vector3f rates{imusample.delta_ang / imusample.delta_ang_dt};
	px4_ecl_out_bus.p = rates(0) - gyro_bias(0);
	px4_ecl_out_bus.q = rates(1) - gyro_bias(1);
	px4_ecl_out_bus.r = rates(2) - gyro_bias(2);
	px4_ecl_out_bus.flag |= (1<<2 | 1<<3);
}

void Ekf_get_estimator_acc(void){

	// get the velocity derivative in earth frame
	// note : in earth frame not in body frame
	const Vector3f vel_deriv{_ekf->getVelocityDerivative()};
	px4_ecl_out_bus.ax = vel_deriv(0);
	px4_ecl_out_bus.ay = vel_deriv(1);
	px4_ecl_out_bus.az = vel_deriv(2);
}

void Ekf_get_estimator_vel(void){

	// Vehicle odometry linear velocity
	// note : local NED earth frame velocity
	const Vector3f velocity{_ekf->getVelocity()};
	px4_ecl_out_bus.vn = velocity(0);
	px4_ecl_out_bus.ve = velocity(1);
	px4_ecl_out_bus.vd = velocity(2);
	px4_ecl_out_bus.flag |= 1<<4;
}

void Ekf_get_estimator_position(void){

	// Position of body origin in local NED frame
	const Vector3f position{_ekf->getPosition()};
	px4_ecl_out_bus.x_R = position(0);
	px4_ecl_out_bus.y_R = position(1);
	px4_ecl_out_bus.h_R = position(2);
	px4_ecl_out_bus.flag |= 1<<6;
}

void Ekf_get_estimator_global_position(void){

	const Vector3f position{_ekf->getPosition()};
 	map_projection_reproject(&(_ekf->global_origin()), position(0), position(1), &px4_ecl_out_bus.lat, &px4_ecl_out_bus.lon);
	px4_ecl_out_bus.alt = -position(2) + _ekf->getEkfGlobalOriginAltitude(); // Altitude AMSL in meters
	px4_ecl_out_bus.flag |= (1<<5 | 1<<7);
}


void Ekf_get_estimator_TerrainVertPos(void){
	px4_ecl_out_bus.h_AGL = _ekf->getTerrainVertPos();
	px4_ecl_out_bus.flag |= 1<<8;
}

}