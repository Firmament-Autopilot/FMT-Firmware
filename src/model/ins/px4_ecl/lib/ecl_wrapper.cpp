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
#include <common.h>
#include <ecl.h>
#include <ekf.h>
#include <mathlib.h>

#include "INS.h"
#include "fmtconfig.h"
#include "land_detector/LandDetector.h"
#include "module/math/quaternion.h"

#ifdef VEHICLE_TYPE_QUADCOPTER
    #include "land_detector/MulticopterLandDetector.h"
#endif
#ifdef VEHICLE_TYPE_FIXWING
    #include "land_detector/FixedwingLandDetector.h"
#endif

Ekf* _ekf;
imuSample _newest_imu_sample {};

extern "C" {

void Ekf_create(void)
{
    _ekf = new Ekf;
}

void Ekf_set_min_required_gps_health_time(uint32_t time_us)
{
    _ekf->set_min_required_gps_health_time(time_us);
}

void* Ekf_getParamHandle(void)
{
    return (void*)_ekf->getParamHandle();
}

int32_t* Ekf_get_params_vdist_sensor_type()
{
    return &(_ekf->getParamHandle()->vdist_sensor_type);
}

//*************************** set params ***************************//
void Ekf_set_param_ekf2_gyr_noise(float ekf2_gyr_noise)
{
    _ekf->getParamHandle()->gyro_noise = ekf2_gyr_noise;
}

void Ekf_set_param_ekf2_acc_noise(float ekf2_acc_noise)
{
    _ekf->getParamHandle()->accel_noise = ekf2_acc_noise;
}

void Ekf_set_param_ekf2_gyr_b_noise(float ekf2_gyr_b_noise)
{
    _ekf->getParamHandle()->gyro_bias_p_noise = ekf2_gyr_b_noise;
}

void Ekf_set_param_ekf2_acc_b_noise(float ekf2_acc_b_noise)
{
    _ekf->getParamHandle()->accel_bias_p_noise = ekf2_acc_b_noise;
}

void Ekf_set_param_ekf2_mag_e_noise(float ekf2_mag_e_noise)
{
    _ekf->getParamHandle()->mage_p_noise = ekf2_mag_e_noise;
}

void Ekf_set_param_ekf2_mag_b_noise(float ekf2_mag_b_noise)
{
    _ekf->getParamHandle()->magb_p_noise = ekf2_mag_b_noise;
}

void Ekf_set_param_ekf2_wind_noise(float ekf2_wind_noise)
{
    _ekf->getParamHandle()->wind_vel_p_noise = ekf2_wind_noise;
}

void Ekf_set_param_ekf2_noaid_noise(float ekf2_noaid_noise)
{
    _ekf->getParamHandle()->pos_noaid_noise = ekf2_noaid_noise;
}

void Ekf_set_param_ekf2_baro_noise(float ekf2_baro_noise)
{
    _ekf->getParamHandle()->baro_noise = ekf2_baro_noise;
}

void Ekf_set_param_ekf2_gnd_eff_dz(float ekf2_gnd_eff_dz)
{
    _ekf->getParamHandle()->gnd_effect_deadzone = ekf2_gnd_eff_dz;
}

void Ekf_set_param_ekf2_gnd_max_hgt(float ekf2_gnd_max_hgt)
{
    _ekf->getParamHandle()->gnd_effect_max_hgt = ekf2_gnd_max_hgt;
}

void Ekf_set_param_ekf2_head_noise(float ekf2_head_noise)
{
    _ekf->getParamHandle()->mag_heading_noise = ekf2_head_noise;
}

void Ekf_set_param_ekf2_mag_noise(float ekf2_mag_noise)
{
    _ekf->getParamHandle()->mag_noise = ekf2_mag_noise;
}

void Ekf_set_param_ekf2_eas_noise(float ekf2_eas_noise)
{
    _ekf->getParamHandle()->eas_noise = ekf2_eas_noise;
}

void Ekf_set_param_ekf2_beta_noise(float ekf2_beta_noise)
{
    _ekf->getParamHandle()->beta_noise = ekf2_beta_noise;
}

void Ekf_set_param_ekf2_mag_decl(float ekf2_mag_decl)
{
    _ekf->getParamHandle()->mag_declination_deg = ekf2_mag_decl;
}

void Ekf_set_param_ekf2_decl_type(int32_t ekf2_decl_type)
{
    _ekf->getParamHandle()->mag_declination_source = ekf2_decl_type;
}

void Ekf_set_param_ekf2_mag_type(int32_t ekf2_mag_type)
{
    _ekf->getParamHandle()->mag_fusion_type = ekf2_mag_type;
}

void Ekf_set_param_ekf2_gps_check(int32_t ekf2_gps_check)
{
    _ekf->getParamHandle()->gps_check_mask = ekf2_gps_check;
}

void Ekf_set_param_ekf2_aid_mask(int32_t ekf2_aid_mask)
{
    _ekf->getParamHandle()->fusion_mode = ekf2_aid_mask;
}

void Ekf_set_param_ekf2_hgt_mode(int32_t ekf2_hgt_mode)
{
    _ekf->getParamHandle()->vdist_sensor_type = ekf2_hgt_mode;
}

void Ekf_set_param_ekf2_terr_mask(int32_t ekf2_terr_mask)
{
    _ekf->getParamHandle()->terrain_fusion_mode = ekf2_terr_mask;
}

void Ekf_set_param_ekf2_rng_noise(float ekf2_rng_noise)
{
    _ekf->getParamHandle()->range_noise = ekf2_rng_noise;
}

void Ekf_set_param_ekf2_rng_aid(int32_t ekf2_rng_aid)
{
    _ekf->getParamHandle()->range_aid = ekf2_rng_aid;
}

void Ekf_set_param_ekf2_of_n_min(float ekf2_of_n_min)
{
    _ekf->getParamHandle()->flow_noise = ekf2_of_n_min;
}

void Ekf_set_param_ekf2_of_n_max(float ekf2_of_n_max)
{
    _ekf->getParamHandle()->flow_noise_qual_min = ekf2_of_n_max;
}

void Ekf_set_param_ekf2_arsp_thr(float ekf2_arsp_thr)
{
    _ekf->getParamHandle()->arsp_thr = ekf2_arsp_thr;
}

void Ekf_set_param_ekf2_drag_noise(float ekf2_drag_noise)
{
    _ekf->getParamHandle()->drag_noise = ekf2_drag_noise;
}

void Ekf_set_param_ekf2_mag_check(int32_t ekf2_mag_check)
{
    _ekf->getParamHandle()->check_mag_strength = ekf2_mag_check;
}

void Ekf_set_param_ekf2_synthetic_mag_z(int32_t ekf2_synthetic_mag_z)
{
    _ekf->getParamHandle()->synthesize_mag_z = ekf2_synthetic_mag_z;
}
//*************************** set params ***************************//

int32_t* Ekf_get_params_sensor_interval_min_ms()
{
    return &(_ekf->getParamHandle()->sensor_interval_min_ms);
}

int32_t* Ekf_get_params_mag_fusion_type()
{
    return &(_ekf->getParamHandle()->mag_fusion_type);
}

void Ekf_setEkfGlobalOrigin(const double latitude, const double longitude, const float altitude)
{
    _ekf->setEkfGlobalOrigin(latitude, longitude, altitude);
}

void EKf_getEkfGlobalOrigin(uint64_t& origin_time, double& latitude, double& longitude, float& origin_alt)
{
    _ekf->getEkfGlobalOrigin(origin_time, latitude, longitude, origin_alt);
}

void Ekf_set_AccelBias_uncertain(float uncertain)
{
    ((parameters*)_ekf->getParamHandle())->switch_on_accel_bias = uncertain;
}

void Ekf_set_GyroBias_uncertain(float uncertain)
{
    ((parameters*)_ekf->getParamHandle())->switch_on_gyro_bias = uncertain;
}

void Ekf_resetAccelBias(void)
{
    _ekf->resetAccelBias();
}

void Ekf_resetGyroBias(void)
{
    _ekf->resetGyroBias();
}

void Ekf_set_fuse_beta_flag(bool fuse_beta)
{
    _ekf->set_fuse_beta_flag(fuse_beta);
}

void Ekf_set_is_fixed_wing(bool is_fixed_wing)
{
    _ekf->set_is_fixed_wing(is_fixed_wing);
}

void Ekf_set_gnd_effect_flag(bool gnd_effect)
{
    _ekf->set_gnd_effect_flag(gnd_effect);
}

void Ekf_set_in_air_status(bool in_air)
{
    _ekf->set_in_air_status(in_air);
}

void Ekf_IMU_update(uint32_t timestamp_ms, uint32_t dt_ms, float gyr_B_radDs[3], float acc_B_mDs2[3], bool clipping[3])
{
    imuSample imu_sample_new {};

    imu_sample_new.time_us = timestamp_ms * 1.0e3f;
    imu_sample_new.delta_ang_dt = dt_ms * 1.0e-3f;
    imu_sample_new.delta_ang = Vector3f { gyr_B_radDs } * imu_sample_new.delta_ang_dt;
    imu_sample_new.delta_vel_dt = dt_ms * 1.0e-3f;
    imu_sample_new.delta_vel = Vector3f { acc_B_mDs2 } * imu_sample_new.delta_vel_dt;
    imu_sample_new.delta_vel_clipping[0] = clipping[0];
    imu_sample_new.delta_vel_clipping[1] = clipping[1];
    imu_sample_new.delta_vel_clipping[2] = clipping[2];

    _ekf->setIMUData(imu_sample_new);

    _newest_imu_sample = imu_sample_new;
}

void Ekf_MAG_update(uint32_t timestamp_ms, float mag_B_gauss[3])
{
    magSample mag_sample_new {};

    mag_sample_new.time_us = timestamp_ms * 1.0e3f;
    mag_sample_new.mag = Vector3f { mag_B_gauss };

    _ekf->setMagData(mag_sample_new);
}

void Ekf_BARO_update(uint32_t timestamp_ms, float pressure_alt_meter)
{
    baroSample baro_sample_new {};

    baro_sample_new.time_us = timestamp_ms * 1.0e3f;
    baro_sample_new.hgt = pressure_alt_meter;

    _ekf->setBaroData(baro_sample_new);
}

void Ekf_GPS_update(uint32_t timestamp_ms, int32_t lon, int32_t lat, int32_t height,
                    float hAcc, float vAcc, float velN, float velE, float velD, float vel, float cog,
                    float sAcc, uint8_t fixType, uint8_t numSV)
{
    gps_message gps_message_new;

    gps_message_new.time_usec = timestamp_ms * 1.0e3f;
    gps_message_new.lat = lat;
    gps_message_new.lon = lon;
    gps_message_new.alt = height;
    gps_message_new.yaw = NAN;
    gps_message_new.yaw_offset = 0;
    gps_message_new.fix_type = fixType,
    gps_message_new.eph = hAcc;
    gps_message_new.epv = vAcc;
    gps_message_new.sacc = sAcc;
    gps_message_new.vel_m_s = vel;
    gps_message_new.vel_ned = Vector3f { velN, velE, velD };
    gps_message_new.vel_ned_valid = true;
    gps_message_new.nsats = numSV;
    gps_message_new.pdop = sqrt(hAcc * hAcc + vAcc * vAcc);

    _ekf->setGpsData(gps_message_new);
}

void Ekf_RANGEFINDER_update(uint32_t timestamp_ms, float rng, int8_t quality)
{
    rangeSample rangeSample_new;

    rangeSample_new.time_us = timestamp_ms * 1.0e3f;
    rangeSample_new.rng = rng;
    rangeSample_new.quality = quality; // default 100

    _ekf->setRangeData(rangeSample_new);
}

void Ekf_AIRSPEED_update(uint32_t timestamp_ms, float true_airspeed, float eas2tas)
{
    airspeedSample airspeedSample_new;

    airspeedSample_new.time_us = timestamp_ms * 1.0e3f;
    airspeedSample_new.true_airspeed = true_airspeed;
    airspeedSample_new.eas2tas = eas2tas;

    _ekf->setAirspeedData(airspeedSample_new);
}

bool Ekf_step(void)
{
    return _ekf->update();
}

void Ekf_get_attitude(void)
{
    if (_ekf->attitude_valid()) {
        const Quatf q { _ekf->calculate_quaternion() };
        px4_ecl_out_bus.quat[0] = q(0);
        px4_ecl_out_bus.quat[1] = q(1);
        px4_ecl_out_bus.quat[2] = q(2);
        px4_ecl_out_bus.quat[3] = q(3);

        const Eulerf euler(q);
        px4_ecl_out_bus.phi = euler(0);
        px4_ecl_out_bus.theta = euler(1);
        px4_ecl_out_bus.psi = euler(2);

        const Vector3f gyro_bias = _ekf->getGyroBias();
        const Vector3f rates(_newest_imu_sample.delta_ang / _newest_imu_sample.delta_ang_dt);

        px4_ecl_out_bus.p = rates(0) - gyro_bias(0);
        px4_ecl_out_bus.q = rates(1) - gyro_bias(1);
        px4_ecl_out_bus.r = rates(2) - gyro_bias(2);

        px4_ecl_out_bus.flag |= (1 << 2) | (1 << 3);
    } else {
        px4_ecl_out_bus.flag &= ~((1 << 2) | (1 << 3));
    }
}

void Ekf_get_local_position(void)
{
    const decltype(filter_control_status_u::flags) flags = _ekf->control_status_flags();

    // Position of body origin in local NED frame
    const Vector3f position = _ekf->getPosition();
    px4_ecl_out_bus.x_R = position(0);
    px4_ecl_out_bus.y_R = position(1);
    px4_ecl_out_bus.h_R = -position(2);

    // Velocity of body origin in local NED frame (m/s)
    const Vector3f velocity = _ekf->getVelocity();
    px4_ecl_out_bus.vn = velocity(0);
    px4_ecl_out_bus.ve = velocity(1);
    px4_ecl_out_bus.vd = velocity(2);

    if (_ekf->local_position_is_valid()) {
        px4_ecl_out_bus.flag |= (1 << 4) | (1 << 6);
    } else {
        px4_ecl_out_bus.flag &= ~((1 << 4) | (1 << 6));
    }

    /* check if local height valid */
    if (flags.gps_hgt || flags.baro_hgt || flags.rng_hgt || flags.ev_hgt) {
        px4_ecl_out_bus.flag |= 1 << 7;
    } else {
        px4_ecl_out_bus.flag &= ~(1 << 7);
    }
}

void Ekf_get_global_position(void)
{
    const Vector3f position = _ekf->getPosition();
    const map_projection_reference_s ref_pos = _ekf->global_origin();
    const float ref_alt = _ekf->getEkfGlobalOriginAltitude();

    map_projection_reproject(&ref_pos, position(0), position(1), &px4_ecl_out_bus.lat, &px4_ecl_out_bus.lon);

    px4_ecl_out_bus.lat = math::radians(px4_ecl_out_bus.lat);
    px4_ecl_out_bus.lon = math::radians(px4_ecl_out_bus.lon);
    px4_ecl_out_bus.alt = -position(2) + ref_alt;
    px4_ecl_out_bus.lat_0 = ref_pos.lat_rad;
    px4_ecl_out_bus.lon_0 = ref_pos.lon_rad;
    px4_ecl_out_bus.alt_0 = ref_alt;

    if (_ekf->global_position_is_valid()) {
        px4_ecl_out_bus.flag |= 1 << 5;
    } else {
        px4_ecl_out_bus.flag &= ~(1 << 5);
    }
}

void Ekf_get_acc(void)
{
    const Quatf q { _ekf->calculate_quaternion() };
    const Vector3f vel_deriv { _ekf->getVelocityDerivative() };
    quaternion quat = { q(0), q(1), q(2), q(3) };
    float acc_O[3] = { vel_deriv(0), vel_deriv(1), vel_deriv(2) - 9.81f };
    float acc_B[3];

    quaternion_inv_rotateVector(&quat, acc_O, acc_B);

    px4_ecl_out_bus.ax = acc_B[0];
    px4_ecl_out_bus.ay = acc_B[1];
    px4_ecl_out_bus.az = acc_B[2];
}

void Ekf_get_TerrainVertPos(void)
{
    if (_ekf->isTerrainEstimateValid()) {
        px4_ecl_out_bus.h_AGL = _ekf->getTerrainVertPos();
        px4_ecl_out_bus.flag |= 1 << 8;
    } else {
        px4_ecl_out_bus.flag &= ~(1 << 8);
    }
}

#ifdef VEHICLE_TYPE_QUADCOPTER
MulticopterLandDetector* _ld;
#endif
#ifdef VEHICLE_TYPE_FIXWING
FixedwingLandDetector* _ld;
#endif

void ld_creat(void)
{
#ifdef VEHICLE_TYPE_QUADCOPTER
    _ld = new MulticopterLandDetector;
#endif
#ifdef VEHICLE_TYPE_FIXWING
    _ld = new FixedwingLandDetector;
#endif
}

void ld_set_time(uint64_t nowUs)
{
    *(_ld->return_nowUs()) = nowUs;
}

void ld_set_armed(bool armed)
{
    *(_ld->return_armed()) = armed;
}

void ld_set_IMU_data(float gyroRate[3], float acceleration[3])
{
    *(_ld->return_acceleration()) = Vector3f { acceleration };
    *(_ld->return_angular_velocity()) = Vector3f { gyroRate };
}

void ld_set_dist_bottom_is_observable(bool observable)
{
    *(_ld->return_dist_bottom_is_observable()) = observable;
}

void ld_set_vehicle_local_position(uint64_t timeStampUs)
{

    vehicle_local_position_s* vehicle_local_position = _ld->return_vehicle_local_position();

    vehicle_local_position->timeStampUs = timeStampUs;

    // Velocity of body origin in local NED frame (m/s)
    const Vector3f velocity { _ekf->getVelocity() };
    vehicle_local_position->vx = velocity(0);
    vehicle_local_position->vy = velocity(1);
    vehicle_local_position->vz = velocity(2);

    vehicle_local_position->v_xy_valid = _ekf->local_position_is_valid();
    vehicle_local_position->v_z_valid = _ekf->local_position_is_valid();

    // Distance to bottom surface (ground) in meters
    // constrain the distance to ground to _rng_gnd_clearance
    vehicle_local_position->dist_bottom = math::max(_ekf->getTerrainVertPos() - _ekf->getPosition()(2), _ekf->getParamHandle()->rng_gnd_clearance);
    vehicle_local_position->dist_bottom_valid = _ekf->isTerrainEstimateValid();
    vehicle_local_position->dist_bottom_sensor_bitfield = _ekf->getTerrainEstimateSensorBitfield();
}

void ld_set_vehicle_imu_status(uint64_t timeStampUs)
{
    vehicle_imu_status_s* _imu_status {};
    _imu_status = _ld->return_vehicle_imu_status();
    _imu_status->timeStampUs = timeStampUs;
    _imu_status->gyro_vibration_metric = (_ekf->getImuVibrationMetrics())(1);
    _imu_status->accel_vibration_metric = (_ekf->getImuVibrationMetrics())(2);
}

bool ld_get_landed_state(void)
{
    if (_ld->return_vehicle_land_detected()->landed) {
        px4_ecl_out_bus.flag |= 1 << 1;
        return true;
    } else {
        px4_ecl_out_bus.flag &= ~(1 << 1);
        return false;
    }
}

bool ld_get_gnd_effect(void)
{
    return _ld->return_vehicle_land_detected()->in_ground_effect;
}

bool ld_IsUpdated(void)
{
    return _ld->return_vehicle_land_detected()->updated;
}

#ifdef VEHICLE_TYPE_QUADCOPTER
void ld_set_actuator_controls_throttle(float throttle)
{
    *(_ld->return_actuator_controls_throttle()) = throttle;
}

void ld_set_flag_control_climb_rate_enabled(bool enable)
{
    *(_ld->return_flag_control_climb_rate_enabled()) = enable;
}

void ld_set_trajectory_vz(float vz)
{
    *(_ld->return_trajectory_vz()) = vz;
}

void ld_set_hover_thrust_estimate(uint64_t nowUs, float hover_thrust, bool valid)
{
    hover_thrust_estimate_s* hover_thrust_estimate = _ld->return_hover_thrust_estimate();
    hover_thrust_estimate->timeStampUs = nowUs;
    hover_thrust_estimate->hover_thrust = hover_thrust;
    hover_thrust_estimate->valid = valid;
}
#endif

#ifdef VEHICLE_TYPE_FIXWING
void ld_set_airspeed_validated(uint64_t timeStampUs, float true_airspeed_m_s)
{
    airspeed_validated_s* airspeed_validated = _ld->return_airspeed_validated();
    airspeed_validated->timeStampUs = timeStampUs;
    airspeed_validated->true_airspeed_m_s = true_airspeed_m_s;
}
#endif

void ld_step(void)
{

    uint64_t nowUs = systime_now_us();
    ld_set_time(nowUs);
    ld_set_vehicle_local_position(nowUs);
    ld_set_vehicle_imu_status(nowUs);

    _ld->update();
}
}
