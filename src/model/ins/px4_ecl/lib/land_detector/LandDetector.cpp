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

/*
 * @file LandDetector.cpp
 *
 * @author Johan Jansen <jnsn.johan@gmail.com>
 * @author Julian Oes <julian@oes.ch>
 */

#include "LandDetector.h"

LandDetector::LandDetector()
{
    _land_detected.ground_contact = true;
    _land_detected.maybe_landed = true;
    _land_detected.landed = true;
    _land_detected.in_ground_effect = true;
    _land_detected.in_descend = false;
    _land_detected.has_low_throttle = false;
    _land_detected.vertical_movement = false;
    _land_detected.horizontal_movement = false;
    _land_detected.rotational_movement = false;
    _land_detected.close_to_ground_or_skipped_check = true;
    _land_detected.at_rest = true;
}

LandDetector::~LandDetector()
{
}

void LandDetector::update()
{
    static constexpr float GYRO_NORM_MAX = math::radians(3.f); // 3 degrees/second

    if (_angular_velocity.norm() > GYRO_NORM_MAX) {
        _time_last_move_detect_us = _nowUs; //_angular_velocity.timeStampUs;
    }

    _update_topics();

    if (!_dist_bottom_is_observable) {
        // we consider the distance to the ground observable if the system is using a range sensor
        _dist_bottom_is_observable = _vehicle_local_position.dist_bottom_sensor_bitfield & vehicle_local_position_s::DIST_BOTTOM_SENSOR_RANGE;
    }

    // Increase land detection time if not close to ground
    if (_dist_bottom_is_observable && !_vehicle_local_position.dist_bottom_valid) {
        _set_hysteresis_factor(3);

    } else {
        _set_hysteresis_factor(1);
    }

    _freefall_hysteresis.set_state_and_update(_get_freefall_state(), _nowUs);
    _ground_contact_hysteresis.set_state_and_update(_get_ground_contact_state(), _nowUs);
    _maybe_landed_hysteresis.set_state_and_update(_get_maybe_landed_state(), _nowUs);
    _landed_hysteresis.set_state_and_update(_get_landed_state(), _nowUs);
    _ground_effect_hysteresis.set_state_and_update(_get_ground_effect_state(), _nowUs);

    const bool freefallDetected = _freefall_hysteresis.get_state();
    const bool ground_contactDetected = _ground_contact_hysteresis.get_state();
    const bool maybe_landedDetected = _maybe_landed_hysteresis.get_state();
    const bool landDetected = _landed_hysteresis.get_state();
    const bool in_ground_effect = _ground_effect_hysteresis.get_state();

    UpdateVehicleAtRest();

    const bool at_rest = landDetected && _at_rest;

    // publish at 1 Hz, very first time, or when the result has changed
    if ((_nowUs - _land_detected.timeStampUs >= 1_s) || (_land_detected.landed != landDetected) || (_land_detected.freefall != freefallDetected) || (_land_detected.maybe_landed != maybe_landedDetected) || (_land_detected.ground_contact != ground_contactDetected) || (_land_detected.in_ground_effect != in_ground_effect) || (_land_detected.at_rest != at_rest)) {

        if (!landDetected && _land_detected.landed && _takeoff_time == 0) { /* only set take off time once, until disarming */
            // We did take off
            _takeoff_time = _nowUs;
        }

        _land_detected.landed = landDetected;
        _land_detected.freefall = freefallDetected;
        _land_detected.maybe_landed = maybe_landedDetected;
        _land_detected.ground_contact = ground_contactDetected;
        _land_detected.in_ground_effect = in_ground_effect;
        _land_detected.in_descend = _get_in_descend();
        _land_detected.has_low_throttle = _get_has_low_throttle();
        _land_detected.horizontal_movement = _get_horizontal_movement();
        _land_detected.vertical_movement = _get_vertical_movement();
        _land_detected.rotational_movement = _get_rotational_movement();
        _land_detected.close_to_ground_or_skipped_check = _get_close_to_ground_or_skipped_check();
        _land_detected.at_rest = at_rest;
        _land_detected.timeStampUs = _nowUs;
        _land_detected.updated = true;
    }else{
        _land_detected.updated = false;
    }

    // set the flight time when disarming (not necessarily when landed, because all param changes should
    // happen on the same event and it's better to set/save params while not in armed state)
    if (_takeoff_time != 0 && !_armed && _previous_armed_state) {
        _takeoff_time = 0;
    }

    _previous_armed_state = _armed;
}

void LandDetector::UpdateVehicleAtRest()
{
    static constexpr float IS_MOVING_SCALER = 1.0f;

    if ((_imu_status.gyro_vibration_metric * 4.0E4f > IS_MOVING_SCALER)
        || (_imu_status.accel_vibration_metric * 2.1E2f > IS_MOVING_SCALER)) {

        _time_last_move_detect_us = _imu_status.timeStampUs;
    }

    _at_rest = (_nowUs - _time_last_move_detect_us > 1_s);
}
