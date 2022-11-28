/****************************************************************************
 *
 *   Copyright (c) 2013-2016 PX4 Development Team. All rights reserved.
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
 * @file FixedwingLandDetector.h
 * Land detector implementation for fixedwing.
 *
 * @author Johan Jansen <jnsn.johan@gmail.com>
 * @author Morten Lysgaard <morten@lysgaard.no>
 * @author Julian Oes <julian@oes.ch>
 */

#pragma once

#include <matrix/math.hpp>
#include <uORB/topics/airspeed_validated.h>

#include "LandDetector.h"

using namespace time_literals;

#ifdef __cplusplus
struct __EXPORT airspeed_validated_s {
#else
struct airspeed_validated_s {
#endif

	uint64_t timeStampUs;
	uint64_t nowTimeUs;
	float true_airspeed_m_s;
	bool updated;

#ifdef __cplusplus

#endif
};

namespace land_detector
{

class FixedwingLandDetector final : public LandDetector
{
public:
	FixedwingLandDetector();
	~FixedwingLandDetector() override = default;

	void set_airspeed_validated(float true_airspeed_m_s, uint64_t timeStampUs, uint64_t nowTimeUs, bool updated){
		_airspeed_validated.true_airspeed_m_s 	= true_airspeed_m_s;
		_airspeed_validated.timeStampUs 		= timeStampUs;
		_airspeed_validated.nowTimeUs 			= nowTimeUs;
		_airspeed_validated.updated 			= updated;
	}

	void set_fw_params(	float _param_lndfw_xyaccel_max,
						float _param_lndfw_airspd,
						float _param_lndfw_vel_xy_max,
						float _param_lndfw_vel_z_max){
		_fw_params._param_lndfw_xyaccel_max = _param_lndfw_xyaccel_max;
		_fw_params._param_lndfw_airspd 		= _param_lndfw_airspd;
		_fw_params._param_lndfw_vel_xy_max 	= _param_lndfw_vel_xy_max;
		_fw_params._param_lndfw_vel_z_max 	= _param_lndfw_vel_z_max;
	}

protected:

	bool _get_landed_state() override;
	void _set_hysteresis_factor(const int factor) override {};
	void set_airspeed(float airspeed_m_s, bool valid, uint64_t nowTime, uint64_t timeStamp);

	airspeed_validated_s _airspeed_validated{};

private:

	/** Time in us that landing conditions have to hold before triggering a land. */
	static constexpr uint64_t LANDED_TRIGGER_TIME_US = 2_s;
	static constexpr uint64_t FLYING_TRIGGER_TIME_US = 0_us;

	uORB::Subscription _airspeed_validated_sub{ORB_ID(airspeed_validated)};

	float _airspeed_filtered{0.0f};
	float _velocity_xy_filtered{0.0f};
	float _velocity_z_filtered{0.0f};
	float _xy_accel_filtered{0.0f};

	DEFINE_PARAMETERS_CUSTOM_PARENT(
		LandDetector,
		(ParamFloat<px4::params::LNDFW_XYACC_MAX>)  _param_lndfw_xyaccel_max,
		(ParamFloat<px4::params::LNDFW_AIRSPD_MAX>) _param_lndfw_airspd,
		(ParamFloat<px4::params::LNDFW_VEL_XY_MAX>) _param_lndfw_vel_xy_max,
		(ParamFloat<px4::params::LNDFW_VEL_Z_MAX>)  _param_lndfw_vel_z_max
	);

	struct{
		float _param_lndfw_xyaccel_max,
		float _param_lndfw_airspd,
		float _param_lndfw_vel_xy_max,
		float _param_lndfw_vel_z_max
	}_fw_params{};
};

} // namespace land_detector
