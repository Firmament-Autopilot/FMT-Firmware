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
 * @file MulticopterLandDetector.h
 * Land detection implementation for multicopters.
 *
 * @author Johan Jansen <jnsn.johan@gmail.com>
 * @author Morten Lysgaard <morten@lysgaard.no>
 * @author Julian Oes <julian@oes.ch>
 */

#pragma once

#include "LandDetector.h"

struct hover_thrust_estimate_s {
    uint64_t timeStampUs;
    float hover_thrust;
    bool valid;
};

struct takeoff_status_s {
    static constexpr uint8_t TAKEOFF_STATE_UNINITIALIZED = 0;
    static constexpr uint8_t TAKEOFF_STATE_DISARMED = 1;
    static constexpr uint8_t TAKEOFF_STATE_SPOOLUP = 2;
    static constexpr uint8_t TAKEOFF_STATE_READY_FOR_TAKEOFF = 3;
    static constexpr uint8_t TAKEOFF_STATE_RAMPUP = 4;
    static constexpr uint8_t TAKEOFF_STATE_FLIGHT = 5;
};

class MulticopterLandDetector : public LandDetector {
public:
    MulticopterLandDetector();
    ~MulticopterLandDetector() override = default;

    float* return_actuator_controls_throttle(void) { return &_actuator_controls_throttle; };
    bool* return_flag_control_climb_rate_enabled(void) { return &_flag_control_climb_rate_enabled; };
    float* return_trajectory_vz(void) { return &_trajectory_vz; };
    hover_thrust_estimate_s* return_hover_thrust_estimate(void) { return &_hover_thrust_estimate; };

protected:
    void _update_params() override;
    void _update_topics() override;

    bool _get_landed_state() override;
    bool _get_ground_contact_state() override;
    bool _get_maybe_landed_state() override;
    bool _get_freefall_state() override;
    bool _get_ground_effect_state() override;
    bool _get_in_descend() override { return _in_descend; }
    bool _get_has_low_throttle() override { return _has_low_throttle; }
    bool _get_horizontal_movement() override { return _horizontal_movement; }
    bool _get_vertical_movement() override { return _vertical_movement; }
    bool _get_rotational_movement() override { return _rotational_movement; }
    bool _get_close_to_ground_or_skipped_check() override { return _close_to_ground_or_skipped_check; }

    void _set_hysteresis_factor(const int factor) override;

private:
    bool _is_close_to_ground();

    /** Time in us that freefall has to hold before triggering freefall */
    static constexpr uint64_t FREEFALL_TRIGGER_TIME_US = 300_ms;

    /** Distance above ground below which entering ground contact state is possible when distance to ground is available. */
    static constexpr float DIST_FROM_GROUND_THRESHOLD = 1.0f;

    uint64_t _hover_thrust_estimate_last_valid { 0 };
    bool _hover_thrust_estimate_valid { false };

    bool _flag_control_climb_rate_enabled { false };
    bool _hover_thrust_initialized { false };

    float _actuator_controls_throttle { 0.f };

    uint8_t _takeoff_state { takeoff_status_s::TAKEOFF_STATE_DISARMED };

    Hysteresis _minimum_thrust_8s_hysteresis { false };

    bool _in_descend { false };          ///< vehicle is commanded to desend
    bool _horizontal_movement { false }; ///< vehicle is moving horizontally
    bool _vertical_movement { false };
    bool _rotational_movement { false };
    bool _has_low_throttle { false };
    bool _close_to_ground_or_skipped_check { false };
    bool _below_gnd_effect_hgt { false }; ///< vehicle height above ground is below height where ground effect occurs

    hover_thrust_estimate_s _hover_thrust_estimate {};
    float _trajectory_vz { 0.0f };
};
