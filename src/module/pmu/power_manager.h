/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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
#ifndef POWER_MANAGER_H__
#define POWER_MANAGER_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

struct battery_status {
    uint32_t timestamp;
    float battery_voltage;
    float battery_current;
    float battery_remaining;
    float remaining_c;
    float remaining_v;
    float state_of_health;
    uint8_t battery_init;
    uint8_t connected;
    uint8_t reserved1;
    uint8_t reserved2;
    uint32_t last_unconnected_timestamp;
    float init_SOC;
    float internal_resistance;

    float cell_voltage;
    float cell_voltage_origin;
};

fmt_err_t pmu_init(void);
fmt_err_t pmu_poll_battery_status(void);

#ifdef __cplusplus
}
#endif

#endif
