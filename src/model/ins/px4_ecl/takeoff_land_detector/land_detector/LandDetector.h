/****************************************************************************
 *
 *   Copyright (c) 2013-2017 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file LandDetector.h
 * Land detector interface for multicopter, fixedwing and VTOL implementations.
 *
 * @author Johan Jansen <jnsn.johan@gmail.com>
 * @author Julian Oes <julian@oes.ch>
 * @author Lorenz Meier <lorenz@px4.io>
 */

#pragma once

#include <float.h>
#include <math.h>

#include <lib/hysteresis/hysteresis.h>
#include <lib/perf/perf_counter.h>
#include <px4_platform_common/defines.h>
#include <px4_platform_common/module.h>
#include <px4_platform_common/module.h>
#include <px4_platform_common/module_params.h>
#include <px4_platform_common/module_params.h>
#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/px4_work_queue/ScheduledWorkItem.hpp>
#include <uORB/Publication.hpp>
#include <uORB/Subscription.hpp>
#include <uORB/SubscriptionCallback.hpp>
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/parameter_update.h>
#include <uORB/topics/sensor_selection.h>
#include <uORB/topics/vehicle_acceleration.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/vehicle_imu_status.h>
#include <uORB/topics/vehicle_land_detected.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_status.h>

#ifdef __cplusplus
struct __EXPORT actuator_armed_s {
#else
struct actuator_armed_s {
#endif

	uint64_t timeStampUs;
	bool armed;
	bool updated;

#ifdef __cplusplus

#endif
};

#ifdef __cplusplus
struct __EXPORT vehicle_acceleration_s {
#else
struct vehicle_acceleration_s {
#endif

	uint64_t timeStampUs;
	matrix::Vector3f acceleration;
	bool updated;

#ifdef __cplusplus

#endif
};

#ifdef __cplusplus
struct __EXPORT vehicle_angular_velocity_s {
#else
struct vehicle_angular_velocity_s {
#endif

	uint64_t timeStampUs_sample;
	matrix::Vector3f vehicle_angular_velocity;
	bool updated;

#ifdef __cplusplus

#endif
};

#ifdef __cplusplus
struct __EXPORT vehicle_local_position_s {
#else
struct vehicle_local_position_s {
#endif

	uint64_t timestamp;
	float vx;
	float vy;
	float vz;
	bool v_xy_valid;
	bool v_z_valid;
	bool dist_bottom_valid;
	uint8_t dist_bottom_sensor_bitfield;
	bool updated;

#ifdef __cplusplus
	static constexpr uint8_t DIST_BOTTOM_SENSOR_NONE = 0;
	static constexpr uint8_t DIST_BOTTOM_SENSOR_RANGE = 1;
	static constexpr uint8_t DIST_BOTTOM_SENSOR_FLOW = 2;

#endif
};

#ifdef __cplusplus
struct __EXPORT sensor_selection_s {
#else
struct sensor_selection_s {
#endif

	uint64_t timeStampUs;
	uint32_t accel_device_id;
	uint32_t gyro_device_id;
	bool updated;

#ifdef __cplusplus

#endif
};

#ifdef __cplusplus
struct __EXPORT vehicle_imu_status_s {
#else
struct vehicle_imu_status_s {
#endif

	uint64_t timestamp;
	float accel_vibration_metric;
	float gyro_vibration_metric;
	bool updated;

#ifdef __cplusplus

#endif
};

using namespace time_literals;

namespace land_detector
{

class LandDetector : public ModuleBase<LandDetector>, ModuleParams, px4::ScheduledWorkItem
{
public:
	LandDetector();
	virtual ~LandDetector();

	/** @see ModuleBase */
	static int custom_command(int argc, char *argv[])
	{
		return print_usage("unknown command");
	}

	/** @see ModuleBase */
	static int print_usage(const char *reason = nullptr);

	/** @see ModuleBase::print_status() */
	int print_status() override;

	/**
	 * Get the work queue going.
	 */
	void start();

	static int task_spawn(int argc, char *argv[]);

	// c/c++ interface(uorb) for usr
	void set_armed(bool armed, uint64_t timeStampUs, bool updated){
		_actuator_armed.timeStampUs = timeStampUs;
		_actuator_armed.armed 		= armed;	
		_actuator_armed.updated 	= updated
	};
	void set_acceleration(matrix::Vector3f acceleration, uint64_t timeStampUs, bool updated){
		_vehicle_acceleration.timeStampUs 	= timeStampUs;
		_vehicle_acceleration.acceleration 	= acceleration;
		_vehicle_acceleration.updated 		= updated;	
	};
	void set_angular_velocity(matrix::Vector3f angularVelocity, uint64_t timeStampUs_sample, bool updated){
		_vehicle_angular_velocity.timeStampUs_sample 		= timeStampUs_sample;
		_vehicle_angular_velocity.vehicle_angular_velocity 	= angularVelocity;
		_vehicle_angular_velocity.updated 					= updated;
	};
	void set_vehicle_local_position(uint64_t timestamp,
									float vx,
									float vy,
									float vz,
									bool v_xy_valid,
									bool v_z_valid,
									bool dist_bottom_valid,
									uint8_t dist_bottom_sensor_bitfield,
									bool updated){
		_vehicle_local_position.timestamp 						= timestamp;
		_vehicle_local_position.vx 								= vx;
		_vehicle_local_position.vy 								= vy;
		_vehicle_local_position.vz 								= vz;
		_vehicle_local_position.v_xy_valid 						= v_xy_valid;
		_vehicle_local_position.v_z_valid 						= v_z_valid;
		_vehicle_local_position.dist_bottom_valid 				= dist_bottom_valid;
		_vehicle_local_position.dist_bottom_sensor_bitfield 	= dist_bottom_sensor_bitfield;
		_vehicle_local_position.updated 						= updated;
	};
	void set_sensor_selection(uint32_t accel_device_id, uint32_t gyro_device_id, uint64_t timeStampUs, bool updated){
		_sensor_selection.timeStampUs 		= timeStampUs;
		_sensor_selection.accel_device_id 	= accel_device_id;
		_sensor_selection.gyro_device_id 	= gyro_device_id;
		_sensor_selection.updated 			= updated;
	};
	void set_imu_status(float accel_vibration_metric, float gyro_vibration_metric, uint64_t timeStampUs, bool updated){
		_imu_status.accel_vibration_metric 	= accel_vibration_metric;
		_imu_status.gyro_vibration_metric 	= gyro_vibration_metric;
		_imu_status.timeStampUs 			= timeStampUs;
		_imu_status.updated 				= updated;
	};

	// c/c++ interface(params) for usr
	void set_params(float _param_total_flight_time_high,
					float _param_total_flight_time_low){
		_params._param_total_flight_time_high 	= _param_total_flight_time_high;
		_params._param_total_flight_time_low 	= _param_total_flight_time_low;
	}

protected:

	/**
	 * Updates parameters.
	 */
	virtual void _update_params() {};

	/**
	 * Updates subscribed uORB topics.
	 */
	virtual void _update_topics() {};

	/**
	 * @return true if UAV is in a landed state.
	 */
	virtual bool _get_landed_state() = 0;

	/**
	 * @return true if UAV is in almost landed state
	 */
	virtual bool _get_maybe_landed_state() { return false; }

	/**
	 * @return true if UAV is touching ground but not landed
	 */
	virtual bool _get_ground_contact_state() { return false; }

	/**
	 * @return true if UAV is in free-fall state.
	 */
	virtual bool _get_freefall_state() { return false; }

	/**
	 *  @return true if vehicle could be in ground effect (close to ground)
	 */
	virtual bool _get_ground_effect_state() { return false; }

	virtual bool _get_in_descend() { return false; }
	virtual bool _get_has_low_throttle() { return false; }
	virtual bool _get_horizontal_movement() { return false; }
	virtual bool _get_vertical_movement() { return false; }
	virtual bool _get_rotational_movement() { return false; }
	virtual bool _get_close_to_ground_or_skipped_check() {  return false; }
	virtual void _set_hysteresis_factor(const int factor) = 0;

	systemlib::Hysteresis _freefall_hysteresis{false};
	systemlib::Hysteresis _landed_hysteresis{true};
	systemlib::Hysteresis _maybe_landed_hysteresis{true};
	systemlib::Hysteresis _ground_contact_hysteresis{true};
	systemlib::Hysteresis _ground_effect_hysteresis{false};

	vehicle_local_position_s 	_vehicle_local_position{};
	vehicle_status_s         	_vehicle_status{};
	actuator_armed_s 			_actuator_armed{};
	sensor_selection_s 			_sensor_selection{};
	vehicle_acceleration_s 		_vehicle_acceleration{};
	vehicle_angular_velocity_s 	_vehicle_angular_velocity{};
	vehicle_imu_status_s 		_imu_status;

	matrix::Vector3f _acceleration{};
	matrix::Vector3f _angular_velocity{};

	bool _armed{false};
	bool _previous_armed_state{false};	///< stores the previous actuator_armed.armed state
	bool _dist_bottom_is_observable{false};

private:
	void Run() override;

	void UpdateVehicleAtRest();

	vehicle_land_detected_s _land_detected{};
	uint64_t _takeoff_time{0};
	uint64_t _total_flight_time{0};	///< total vehicle flight time in microseconds

	uint64_t _time_last_move_detect_us{0};	// timestamp of last movement detection event in microseconds

	perf_counter_t _cycle_perf{perf_alloc(PC_ELAPSED, MODULE_NAME": cycle")};

	uORB::Publication<vehicle_land_detected_s> _vehicle_land_detected_pub{ORB_ID(vehicle_land_detected)};

	uORB::SubscriptionInterval _parameter_update_sub{ORB_ID(parameter_update), 1_s};

	uORB::Subscription _actuator_armed_sub{ORB_ID(actuator_armed)};
	uORB::Subscription _sensor_selection_sub{ORB_ID(sensor_selection)};
	uORB::Subscription _vehicle_acceleration_sub{ORB_ID(vehicle_acceleration)};
	uORB::Subscription _vehicle_angular_velocity_sub{ORB_ID(vehicle_angular_velocity)};
	uORB::Subscription _vehicle_imu_status_sub{ORB_ID(vehicle_imu_status)};
	uORB::Subscription _vehicle_status_sub{ORB_ID(vehicle_status)};

	uORB::SubscriptionCallbackWorkItem _vehicle_local_position_sub{this, ORB_ID(vehicle_local_position)};

	uint32_t _device_id_gyro{0};

	bool _at_rest{true};

	DEFINE_PARAMETERS_CUSTOM_PARENT(
		ModuleParams,
		(ParamInt<px4::params::LND_FLIGHT_T_HI>) _param_total_flight_time_high,
		(ParamInt<px4::params::LND_FLIGHT_T_LO>) _param_total_flight_time_low
	);

	struct {
		float _param_total_flight_time_high;
		float _param_total_flight_time_low;
	}_params;
};

} // namespace land_detector
