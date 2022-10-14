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

#ifndef AUTO_CMD_H__
#define AUTO_CMD_H__

#include <FMS.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    // NED (North-East-Down) Global (WGS84) coordinate frame
    FRAME_GLOBAL_NED = 0,
    // FRD (Front-Right-Down) Local coordinate frame with origin fixed relative to earth.
    // The forward axis is aligned to the front of the vehicle when offboard entered
    FRAME_LOCAL_FRD,
    // FRD (Front-Right-Down) Local coordinate frame with an origin that travels with vehicle.
    // The forward axis is aligned to the front of the vehicle
    FRAME_BODY_FRD,
};

enum {
    P_CMD_VALID = 1 << 0,
    Q_CMD_VALID = 1 << 1,
    R_CMD_VALID = 1 << 2,
    PHI_CMD_VALID = 1 << 3,
    THETA_CMD_VALID = 1 << 4,
    PSI_CMD_VALID = 1 << 5,
    PSI_RATE_CMD_VALID = 1 << 6,
    X_CMD_VALID = 1 << 7,
    Y_CMD_VALID = 1 << 8,
    Z_CMD_VALID = 1 << 9,
    LAT_CMD_VALID = 1 << 10,
    LON_CMD_VALID = 1 << 11,
    ALT_CMD_VALID = 1 << 12,
    U_CMD_VALID = 1 << 13,
    V_CMD_VALID = 1 << 14,
    W_CMD_VALID = 1 << 15,
    AX_CMD_VALID = 1 << 16,
    AY_CMD_VALID = 1 << 17,
    AZ_CMD_VALID = 1 << 18,
    THROTTLE_CMD_VALID = 1 << 19,
};

fmt_err_t auto_cmd_init(void);

#ifdef __cplusplus
}
#endif

#endif
