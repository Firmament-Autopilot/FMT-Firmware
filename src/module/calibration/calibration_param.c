/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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

#include <firmament.h>

#include "module/math/rotation.h"
#include "module/param/param.h"

/* define parameters */
static param_t __param_list[] = {
    /* GYRO_CAL = GYRO - OFFSET */
    PARAM_FLOAT(GYRO0_XOFF, 0.0, false),
    PARAM_FLOAT(GYRO0_YOFF, 0.0, false),
    PARAM_FLOAT(GYRO0_ZOFF, 0.0, false),
    /* ACC_CAL = ROT_M * (ACC-OFFSET)
	           |  XX  XY  XZ |
	   ROT_M = |  XY  YY  YZ |
	           |  XZ  YZ  ZZ |   */
    PARAM_FLOAT(ACC0_XOFF, 0.0, false),
    PARAM_FLOAT(ACC0_YOFF, 0.0, false),
    PARAM_FLOAT(ACC0_ZOFF, 0.0, false),
    PARAM_FLOAT(ACC0_XXSCALE, 1.0, false),
    PARAM_FLOAT(ACC0_YYSCALE, 1.0, false),
    PARAM_FLOAT(ACC0_ZZSCALE, 1.0, false),
    PARAM_FLOAT(ACC0_XYSCALE, 0.0, false),
    PARAM_FLOAT(ACC0_XZSCALE, 0.0, false),
    PARAM_FLOAT(ACC0_YZSCALE, 0.0, false),
    /* MAG_CAL = ROT_M * (MAG-OFFSET)
	           |  XX  XY  XZ |
	   ROT_M = |  XY  YY  YZ |
	           |  XZ  YZ  ZZ |   */
    PARAM_FLOAT(MAG0_XOFF, 0.0, false),
    PARAM_FLOAT(MAG0_YOFF, 0.0, false),
    PARAM_FLOAT(MAG0_ZOFF, 0.0, false),
    PARAM_FLOAT(MAG0_XXSCALE, 1.0, false),
    PARAM_FLOAT(MAG0_YYSCALE, 1.0, false),
    PARAM_FLOAT(MAG0_ZZSCALE, 1.0, false),
    PARAM_FLOAT(MAG0_XYSCALE, 0.0, false),
    PARAM_FLOAT(MAG0_XZSCALE, 0.0, false),
    PARAM_FLOAT(MAG0_YZSCALE, 0.0, false),

    PARAM_FLOAT(GYRO1_XOFF, 0.0, false),
    PARAM_FLOAT(GYRO1_YOFF, 0.0, false),
    PARAM_FLOAT(GYRO1_ZOFF, 0.0, false),

    PARAM_FLOAT(ACC1_XOFF, 0.0, false),
    PARAM_FLOAT(ACC1_YOFF, 0.0, false),
    PARAM_FLOAT(ACC1_ZOFF, 0.0, false),
    PARAM_FLOAT(ACC1_XXSCALE, 1.0, false),
    PARAM_FLOAT(ACC1_YYSCALE, 1.0, false),
    PARAM_FLOAT(ACC1_ZZSCALE, 1.0, false),
    PARAM_FLOAT(ACC1_XYSCALE, 0.0, false),
    PARAM_FLOAT(ACC1_XZSCALE, 0.0, false),
    PARAM_FLOAT(ACC1_YZSCALE, 0.0, false),

    PARAM_FLOAT(MAG1_XOFF, 0.0, false),
    PARAM_FLOAT(MAG1_YOFF, 0.0, false),
    PARAM_FLOAT(MAG1_ZOFF, 0.0, false),
    PARAM_FLOAT(MAG1_XXSCALE, 1.0, false),
    PARAM_FLOAT(MAG1_YYSCALE, 1.0, false),
    PARAM_FLOAT(MAG1_ZZSCALE, 1.0, false),
    PARAM_FLOAT(MAG1_XYSCALE, 0.0, false),
    PARAM_FLOAT(MAG1_XZSCALE, 0.0, false),
    PARAM_FLOAT(MAG1_YZSCALE, 0.0, false),
    /* Level Calibration. Roll,Pitch,Yaw offset in rad */
    PARAM_FLOAT(LEVEL_XOFF, 0.0, false),
    PARAM_FLOAT(LEVEL_YOFF, 0.0, false),
    PARAM_FLOAT(LEVEL_ZOFF, 0.0, false),
    /* Airspeed Calibration */
    PARAM_FLOAT(DIFF_PRESS_OFFSET, 0.0, false),
    /* Battery Voltage Divider */
    PARAM_FLOAT(BAT_V_DIV, 1.0, false),
    PARAM_UINT8(BAT_N_CELLS, 0, false),
    /* Board Rotation */
    PARAM_UINT8(SENS_BOARD_ROT, ROTATION_NONE, false),
};
PARAM_GROUP_DEFINE(CALIB, __param_list);