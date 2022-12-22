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

#include "LandDetector.h"
#include <matrix/math.hpp>

struct airspeed_validated_s {
    uint64_t timeStampUs;
    float true_airspeed_m_s;
};

class FixedwingLandDetector final : public LandDetector {
public:
    FixedwingLandDetector();
    ~FixedwingLandDetector() override = default;

    airspeed_validated_s* return_airspeed_validated(void) { return &_airspeed_validated; };

protected:
    bool _get_landed_state() override;
    void _set_hysteresis_factor(const int factor) override {};

private:
    /** Time in us that landing conditions have to hold before triggering a land. */
    static constexpr uint64_t LANDED_TRIGGER_TIME_US = 2_s;
    static constexpr uint64_t FLYING_TRIGGER_TIME_US = 0_us;

    float _airspeed_filtered { 0.0f };
    float _velocity_xy_filtered { 0.0f };
    float _velocity_z_filtered { 0.0f };
    float _xy_accel_filtered { 0.0f };

    airspeed_validated_s _airspeed_validated {};
};
