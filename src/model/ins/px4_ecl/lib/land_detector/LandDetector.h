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
#include <stdint.h>

#include "hysteresis/hysteresis.h"
#include "mathlib/mathlib.h"
#include "matrix/math.hpp"
// #include "FixedwingLandDetector.h"
// #include "MulticopterLandDetector.h"

using matrix::Vector2f;
using matrix::Vector3f;

constexpr uint64_t operator"" _s(unsigned long long seconds)
{
    return uint64_t(seconds * 1000000ULL);
}

constexpr uint64_t operator"" _ms(unsigned long long milliseconds)
{
    return uint64_t(milliseconds * 1000ULL);
}

constexpr uint64_t operator"" _us(unsigned long long microseconds)
{
    return uint64_t(microseconds);
}

struct parameters_ld_mc_s {
    float trig_time { 1.0f };      //	@unit s
    float rot_max { 20.0f };       // 	@unit deg/s
    float xy_vel_max { 1.5f };     //	@unit m/s
    float z_vel_max { 0.25f };     //	@unit m/s
    float alt_gnd_effect { 2.0f }; //	@unit m
    bool useHoverThrustEstimate { false };
    float hoverThrottle { 0.5f };   //	@unit norm
    float minThrottle { 0.12f };    //	@unit norm
    float minManThrottle { 0.08f }; //	@unit norm
    float crawlSpeed { 0.3f };      //	@unit m/s
    float landSpeed { 0.7f };       //	@unit m/s
};

struct parameters_ld_fw_s {
    float xyaccel_max { 8.0f }; //	@unit m/s^2
    float airspd { 6.00f };     //	@unit m/s
    float vel_xy_max { 5.0f };  //	@unit m/s
    float vel_z_max { 2.0f };   //	@unit m/s
};

struct imu_status_s {
    float gyro_vibration_metric;
    float accel_vibration_metric;
    uint64_t timeStampUs;
};

struct vehicle_land_detected_s {
    uint64_t timeStampUs;
    bool freefall;
    bool ground_contact;
    bool maybe_landed;
    bool landed;
    bool in_ground_effect;
    bool in_descend;
    bool has_low_throttle;
    bool vertical_movement;
    bool horizontal_movement;
    bool rotational_movement;
    bool close_to_ground_or_skipped_check;
    bool at_rest;
    bool updated;
};

struct vehicle_local_position_s {
    uint64_t timeStampUs;
    float vx;
    float vy;
    float vz;
    float dist_bottom;
    bool v_xy_valid;
    bool v_z_valid;
    bool dist_bottom_valid;
    uint8_t dist_bottom_sensor_bitfield;

    static constexpr uint8_t DIST_BOTTOM_SENSOR_NONE = 0;
    static constexpr uint8_t DIST_BOTTOM_SENSOR_RANGE = 1;
    static constexpr uint8_t DIST_BOTTOM_SENSOR_FLOW = 2;
};

struct vehicle_imu_status_s {
    uint64_t timeStampUs;
    float accel_vibration_metric;
    float gyro_vibration_metric;
};

class LandDetector {
public:
    LandDetector();
    virtual ~LandDetector();

    void update();

    bool* return_armed(void) { return &_armed; };
    uint64_t* return_nowUs(void) { return &_nowUs; };
    matrix::Vector3f* return_acceleration(void) { return &_acceleration; };
    matrix::Vector3f* return_angular_velocity(void) { return &_angular_velocity; };
    vehicle_local_position_s* return_vehicle_local_position(void) { return &_vehicle_local_position; };
    bool* return_dist_bottom_is_observable(void) { return &_dist_bottom_is_observable; };
    vehicle_imu_status_s* return_vehicle_imu_status(void) { return &_imu_status; };
    vehicle_land_detected_s* return_vehicle_land_detected(void) { return &_land_detected; };

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
    virtual bool _get_close_to_ground_or_skipped_check() { return false; }
    virtual void _set_hysteresis_factor(const int factor) = 0;

    Hysteresis _freefall_hysteresis { false };
    Hysteresis _landed_hysteresis { true };
    Hysteresis _maybe_landed_hysteresis { true };
    Hysteresis _ground_contact_hysteresis { true };
    Hysteresis _ground_effect_hysteresis { false };

    vehicle_local_position_s _vehicle_local_position {};

    matrix::Vector3f _acceleration {};
    matrix::Vector3f _angular_velocity {};

    bool _armed { false };
    bool _previous_armed_state { false }; ///< stores the previous actuator_armed.armed state
    bool _dist_bottom_is_observable { false };

    uint64_t _nowUs;

    parameters_ld_mc_s _param_mc {};
    parameters_ld_fw_s _param_fw {};

    vehicle_imu_status_s _imu_status {};

private:
    void UpdateVehicleAtRest();

    vehicle_land_detected_s _land_detected {};
    uint64_t _takeoff_time { 0 };
    uint64_t _total_flight_time { 0 }; ///< total vehicle flight time in microseconds

    uint64_t _time_last_move_detect_us { 0 }; // timestamp of last movement detection event in microseconds

    uint32_t _device_id_gyro { 0 };

    bool _at_rest { true };
};
