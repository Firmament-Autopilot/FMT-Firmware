/****************************************************************************
 *
 *   Copyright (c) 2013-2022 PX4 Development Team. All rights reserved.
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
 * @file MulticopterLandDetector.cpp
 *
 *The MC land-detector goes through 3 states before it will detect landed:
 *
 *State 1 (=ground_contact):
 *ground_contact is detected once the vehicle is not moving along the NED-z direction and has
 *a thrust value below 0.3 of the thrust_range (thrust_hover - thrust_min). The condition has to be true
 *for GROUND_CONTACT_TRIGGER_TIME_US in order to detect ground_contact
 *
 *State 2 (=maybe_landed):
 *maybe_landed can only occur if the internal ground_contact hysteresis state is true. maybe_landed criteria requires to have no motion in x and y,
 *no rotation and a thrust below 0.1 of the thrust_range (thrust_hover - thrust_min). In addition, the mc_pos_control turns off the thrust_sp in
 *body frame along x and y which helps to detect maybe_landed. The criteria for maybe_landed needs to be true for (LNDMC_TRIG_TIME / 3) seconds.
 *
 *State 3 (=landed)
 *landed can only be detected if maybe_landed is true for LAND_DETECTOR_TRIGGER_TIME_US. No farther criteria is tested, but the mc_pos_control goes into
 *idle (thrust_sp = 0) which helps to detect landed. By doing this the thrust-criteria of State 2 will always be met, however the remaining criteria of no rotation and no motion still
 *have to be valid.

 *It is to note that if one criteria is not met, then vehicle exits the state directly without blocking.
 *
 *If the land-detector does not detect ground_contact, then the vehicle is either flying or falling, where free fall detection heavily relies
 *on the acceleration. TODO: verify that free fall is reliable
 *
 * @author Johan Jansen <jnsn.johan@gmail.com>
 * @author Morten Lysgaard <morten@lysgaard.no>
 * @author Julian Oes <julian@oes.ch>
 */

#include <math.h>
#include <mathlib/mathlib.h>
#include <matrix/math.hpp>

#include "MulticopterLandDetector.h"

using matrix::Vector2f;
using matrix::Vector3f;

MulticopterLandDetector::MulticopterLandDetector()
{
    _minimum_thrust_8s_hysteresis.set_hysteresis_time_from(false, 8_s);
}

void MulticopterLandDetector::_update_topics()
{
    if (_param_mc.useHoverThrustEstimate) {
        if (_hover_thrust_estimate.valid) {
            _param_mc.hoverThrottle = _hover_thrust_estimate.hover_thrust;
            _hover_thrust_estimate_last_valid = _hover_thrust_estimate.timeStampUs;
        }
    }
}

void MulticopterLandDetector::_update_params()
{

    // 1.2 corresponds to the margin between the default parameters LNDMC_Z_VEL_MAX = MPC_LAND_CRWL / 1.2
    const float lndmc_upper_threshold = math::min(_param_mc.crawlSpeed, _param_mc.landSpeed) / 1.2f;

    if (_param_mc.z_vel_max > lndmc_upper_threshold) {
        _param_mc.z_vel_max = lndmc_upper_threshold;
        // _param_mc.z_vel_max.commit_no_notification();
    }

    if (!_param_mc.useHoverThrustEstimate || !_hover_thrust_initialized) {
        // HTE runs based on the position controller so, even if we wish to use
        // the estimate, it is only available in altitude and position modes.
        // Therefore, we need to always initialize the hoverThrottle using the hover
        // thrust parameter in case we fly in stabilized
        // TODO: this can be removed once HTE runs in all modes
        _hover_thrust_initialized = true;
    }
}

bool MulticopterLandDetector::_get_freefall_state()
{
    // norm of specific force. Should be close to 9.8 m/s^2 when landed.
    return _acceleration.norm() < 2.f;
}

bool MulticopterLandDetector::_get_ground_contact_state()
{
    const uint64_t time_now_us = _nowUs;

    const bool lpos_available = ((time_now_us - _vehicle_local_position.timeStampUs) < 1_s);

    if (lpos_available && _vehicle_local_position.v_z_valid) {
        // Check if we are moving vertically.
        // Use wider threshold if currently in "maybe landed" state, as estimation for
        // vertical speed is often deteriorated when on the ground or due to propeller
        // up/down throttling.

        float vertical_velocity_threshold = _param_mc.z_vel_max;

        if (_landed_hysteresis.get_state()) {
            vertical_velocity_threshold *= 2.5f;
        }

        _vertical_movement = (fabsf(_vehicle_local_position.vz) > vertical_velocity_threshold);

    } else {
        _vertical_movement = true;
    }

    // Check if we are moving horizontally.
    if (lpos_available && _vehicle_local_position.v_xy_valid) {
        const Vector2f v_xy { _vehicle_local_position.vx, _vehicle_local_position.vy };
        _horizontal_movement = v_xy.longerThan(_param_mc.xy_vel_max);

    } else {
        _horizontal_movement = false; // not known
    }

    if (lpos_available && _param_mc.alt_gnd_effect > 0) {
        _below_gnd_effect_hgt = _vehicle_local_position.dist_bottom < _param_mc.alt_gnd_effect;

    } else {
        _below_gnd_effect_hgt = false;
    }

    const bool hover_thrust_estimate_valid = ((time_now_us - _hover_thrust_estimate_last_valid) < 1_s);

    if (!_in_descend || hover_thrust_estimate_valid) {
        // continue using valid hover thrust if it became invalid during descent
        _hover_thrust_estimate_valid = hover_thrust_estimate_valid;
    }

    // low thrust: 30% of throttle range between min and hover, relaxed to 60% if hover thrust estimate available
    const float thr_pct_hover = _hover_thrust_estimate_valid ? 0.6f : 0.3f;
    const float sys_low_throttle = _param_mc.minThrottle + (_param_mc.hoverThrottle - _param_mc.minThrottle) * thr_pct_hover;
    _has_low_throttle = (_actuator_controls_throttle <= sys_low_throttle);
    bool ground_contact = _has_low_throttle;

    // if we have a valid velocity setpoint and the vehicle is demanded to go down but no vertical movement present,
    // we then can assume that the vehicle hit ground
    if (_flag_control_climb_rate_enabled) {

        // Setpoints can be NAN
        _in_descend = (_trajectory_vz >= 1.5f * _vehicle_local_position.vz);

        // ground contact requires commanded descent until landed
        if (!_maybe_landed_hysteresis.get_state() && !_landed_hysteresis.get_state()) {
            ground_contact &= _in_descend;
        }

    } else {
        _in_descend = false;
    }

    // if there is no distance to ground estimate available then don't enforce using it.
    // if a distance to the ground estimate is generally available (_dist_bottom_is_observable=true), then
    // we already increased the hysteresis for the land detection states in order to reduce the chance of false positives.
    const bool skip_close_to_ground_check = !_dist_bottom_is_observable || !_vehicle_local_position.dist_bottom_valid;
    _close_to_ground_or_skipped_check = _is_close_to_ground() || skip_close_to_ground_check;

    // TODO: we need an accelerometer based check for vertical movement for flying without GPS
    return !_armed || (_close_to_ground_or_skipped_check && ground_contact && !_horizontal_movement && !_vertical_movement);
}

bool MulticopterLandDetector::_get_maybe_landed_state()
{
    uint64_t now = _nowUs;

    float minimum_thrust_threshold { 0.f };

    if (_flag_control_climb_rate_enabled) {
        // 20% of throttle range between min and hover
        minimum_thrust_threshold = _param_mc.minThrottle + (_param_mc.hoverThrottle - _param_mc.minThrottle) * 0.2f;

    } else {
        minimum_thrust_threshold = (_param_mc.minManThrottle + 0.01f);
    }

    const bool minimum_thrust_now = _actuator_controls_throttle <= minimum_thrust_threshold;
    _minimum_thrust_8s_hysteresis.set_state_and_update(minimum_thrust_now, now);

    // Next look if vehicle is not rotating (do not consider yaw)
    float max_rotation_threshold = math::radians(_param_mc.rot_max);

    // Widen max rotation thresholds if either in landed state, thus making it harder
    // to trigger a false positive !landed e.g. due to propeller throttling up/down.
    if (_landed_hysteresis.get_state()) {
        max_rotation_threshold *= 2.5f;
    }

    _rotational_movement = _angular_velocity.xy().norm() > max_rotation_threshold;

    // If vertical velocity is available: ground contact, no thrust, no movement -> landed
    const bool local_position_updated = (now - _vehicle_local_position.timeStampUs) < 1_s;
    const bool vertical_velocity_valid = _vehicle_local_position.v_z_valid;
    const bool vertical_estimate = local_position_updated && vertical_velocity_valid;

    return !_armed || (minimum_thrust_now && !_freefall_hysteresis.get_state() && !_rotational_movement && ((vertical_estimate && _ground_contact_hysteresis.get_state()) || (!vertical_estimate && _minimum_thrust_8s_hysteresis.get_state())));
}

bool MulticopterLandDetector::_get_landed_state()
{
    // all maybe_landed conditions need to hold longer
    return !_armed || _maybe_landed_hysteresis.get_state();
}

bool MulticopterLandDetector::_get_ground_effect_state()
{
    return (_actuator_controls_throttle > 0.1f && !_horizontal_movement && _below_gnd_effect_hgt);
}

bool MulticopterLandDetector::_is_close_to_ground()
{
    if (_vehicle_local_position.dist_bottom_valid) {
        return _vehicle_local_position.dist_bottom < DIST_FROM_GROUND_THRESHOLD;

    } else {
        return false;
    }
}

void MulticopterLandDetector::_set_hysteresis_factor(const int factor)
{
    _ground_contact_hysteresis.set_hysteresis_time_from(false, _param_mc.trig_time * 1_s / 3 * factor);
    _landed_hysteresis.set_hysteresis_time_from(false, _param_mc.trig_time * 1_s / 3 * factor);
    _maybe_landed_hysteresis.set_hysteresis_time_from(false, _param_mc.trig_time * 1_s / 3 * factor);
    _freefall_hysteresis.set_hysteresis_time_from(false, FREEFALL_TRIGGER_TIME_US);
}
