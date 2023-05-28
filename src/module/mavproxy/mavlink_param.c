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
#include <string.h>

#include "module/mavproxy/mavproxy.h"

#define MAV_PARAM_COUNT (sizeof(mav_param_list_t) / sizeof(mav_param_t))

/* These are parameters required by QGC, should not be used by FMT */
static mav_param_list_t mavlink_param = {
    MAVLINK_PARAM_DEFINE(SYS_AUTOSTART, 4001),
    MAVLINK_PARAM_DEFINE(SYS_AUTOCONFIG, 0),
    MAVLINK_PARAM_DEFINE(SYS_PARAM_VER, 0.2),
    MAVLINK_PARAM_DEFINE(MAV_SYS_ID, 0),
    MAVLINK_PARAM_DEFINE(MAV_COMP_ID, 0),
#ifdef FMT_USING_MAVLINK_V2
    MAVLINK_PARAM_DEFINE(MAV_PROTO_VER, 2), /* Mavlink Version */
#else
    MAVLINK_PARAM_DEFINE(MAV_PROTO_VER, 1), /* Mavlink Version */
#endif
    MAVLINK_PARAM_DEFINE(MAV_RADIO_ID, 0),
    MAVLINK_PARAM_DEFINE(MAV_TYPE, MAV_TYPE_QUADROTOR),
    MAVLINK_PARAM_DEFINE(MAV_USEHILGPS, 0),
    MAVLINK_PARAM_DEFINE(MAV_FWDEXTSP, 0),
    MAVLINK_PARAM_DEFINE(MAV_BROADCAST, 0),
    MAVLINK_PARAM_DEFINE(CAL_BOARD_ID, 0),
    MAVLINK_PARAM_DEFINE(CAL_GYRO0_ID, 125),
    MAVLINK_PARAM_DEFINE(CAL_GYRO0_XOFF, 0),
    MAVLINK_PARAM_DEFINE(CAL_GYRO0_YOFF, 0),
    MAVLINK_PARAM_DEFINE(CAL_GYRO0_ZOFF, 0),
    MAVLINK_PARAM_DEFINE(CAL_GYRO0_XSCALE, 1),
    MAVLINK_PARAM_DEFINE(CAL_GYRO0_YSCALE, 1),
    MAVLINK_PARAM_DEFINE(CAL_GYRO0_ZSCALE, 1),
    MAVLINK_PARAM_DEFINE(CAL_MAG0_ID, 130),
    MAVLINK_PARAM_DEFINE(CAL_MAG1_ID, 0),
    MAVLINK_PARAM_DEFINE(CAL_MAG2_ID, 0),
    MAVLINK_PARAM_DEFINE(CAL_MAG0_ROT, ROTATION_NONE),
    MAVLINK_PARAM_DEFINE(CAL_MAG1_ROT, ROTATION_NONE),
    MAVLINK_PARAM_DEFINE(CAL_MAG2_ROT, ROTATION_NONE),
    MAVLINK_PARAM_DEFINE(CAL_MAG0_XOFF, 0),
    MAVLINK_PARAM_DEFINE(CAL_MAG0_YOFF, 0),
    MAVLINK_PARAM_DEFINE(CAL_MAG0_ZOFF, 0),
    MAVLINK_PARAM_DEFINE(CAL_MAG0_XSCALE, 1),
    MAVLINK_PARAM_DEFINE(CAL_MAG0_YSCALE, 1),
    MAVLINK_PARAM_DEFINE(CAL_MAG0_ZSCALE, 1),
    MAVLINK_PARAM_DEFINE(CAL_ACC0_ID, 120),
    MAVLINK_PARAM_DEFINE(CAL_ACC0_XOFF, 0),
    MAVLINK_PARAM_DEFINE(CAL_ACC0_YOFF, 0),
    MAVLINK_PARAM_DEFINE(CAL_ACC0_ZOFF, 0),
    MAVLINK_PARAM_DEFINE(CAL_ACC0_XSCALE, 1),
    MAVLINK_PARAM_DEFINE(CAL_ACC0_YSCALE, 1),
    MAVLINK_PARAM_DEFINE(CAL_ACC0_ZSCALE, 1),
    MAVLINK_PARAM_DEFINE(CAL_ACC_PRIME, 125),
    MAVLINK_PARAM_DEFINE(CAL_GYRO_PRIME, 120),
    MAVLINK_PARAM_DEFINE(CAL_MAG_PRIME, 130),
    MAVLINK_PARAM_DEFINE(CAL_MAG_SIDES, 63), /* 6 side calibration */
    MAVLINK_PARAM_DEFINE(CAL_BARO_PRIME, 0),
    MAVLINK_PARAM_DEFINE(SENS_DPRES_OFF, 0),
    MAVLINK_PARAM_DEFINE(SENS_DPRES_ANSC, 0),
    MAVLINK_PARAM_DEFINE(SENS_BARO_QNH, 1013.25f),
    MAVLINK_PARAM_DEFINE(SENS_BOARD_ROT, ROTATION_NONE),
    MAVLINK_PARAM_DEFINE(SENS_FLOW_ROT, ROTATION_NONE),
    MAVLINK_PARAM_DEFINE(SENS_BOARD_X_OFF, 1),
    MAVLINK_PARAM_DEFINE(SENS_BOARD_Y_OFF, 1),
    MAVLINK_PARAM_DEFINE(SENS_BOARD_Z_OFF, 1),
    MAVLINK_PARAM_DEFINE(SENS_EXT_MAG_ROT, ROTATION_NONE),
    MAVLINK_PARAM_DEFINE(SENS_EXT_MAG, ROTATION_NONE),
    MAVLINK_PARAM_DEFINE(TRIM_ROLL, 0),
    MAVLINK_PARAM_DEFINE(TRIM_PITCH, 0),
    MAVLINK_PARAM_DEFINE(TRIM_YAW, 0),
    MAVLINK_PARAM_DEFINE(RC1_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC1_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC1_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC1_REV, 1),
    MAVLINK_PARAM_DEFINE(RC1_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC2_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC2_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC2_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC2_REV, 1),
    MAVLINK_PARAM_DEFINE(RC2_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC3_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC3_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC3_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC3_REV, 1),
    MAVLINK_PARAM_DEFINE(RC3_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC4_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC4_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC4_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC4_REV, 1),
    MAVLINK_PARAM_DEFINE(RC4_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC5_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC5_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC5_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC5_REV, 1),
    MAVLINK_PARAM_DEFINE(RC5_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC6_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC6_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC6_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC6_REV, 1),
    MAVLINK_PARAM_DEFINE(RC6_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC7_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC7_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC7_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC7_REV, 1),
    MAVLINK_PARAM_DEFINE(RC7_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC8_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC8_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC8_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC8_REV, 1),
    MAVLINK_PARAM_DEFINE(RC8_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC9_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC9_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC9_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC9_REV, 1),
    MAVLINK_PARAM_DEFINE(RC9_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC10_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC10_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC10_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC10_REV, 1),
    MAVLINK_PARAM_DEFINE(RC10_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC11_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC11_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC11_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC11_REV, 1),
    MAVLINK_PARAM_DEFINE(RC11_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC12_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC12_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC12_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC12_REV, 1),
    MAVLINK_PARAM_DEFINE(RC12_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC13_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC13_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC13_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC13_REV, 1),
    MAVLINK_PARAM_DEFINE(RC13_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC14_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC14_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC14_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC14_REV, 1),
    MAVLINK_PARAM_DEFINE(RC14_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC15_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC15_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC15_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC15_REV, 1),
    MAVLINK_PARAM_DEFINE(RC15_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC16_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC16_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC16_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC16_REV, 1),
    MAVLINK_PARAM_DEFINE(RC16_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC17_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC17_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC17_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC17_REV, 1),
    MAVLINK_PARAM_DEFINE(RC17_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC18_MIN, 1000),
    MAVLINK_PARAM_DEFINE(RC18_TRIM, 1500),
    MAVLINK_PARAM_DEFINE(RC18_MAX, 2000),
    MAVLINK_PARAM_DEFINE(RC18_REV, 1),
    MAVLINK_PARAM_DEFINE(RC18_DZ, 50),
    MAVLINK_PARAM_DEFINE(RC_MAP_ROLL, 1),
    MAVLINK_PARAM_DEFINE(RC_MAP_PITCH, 2),
    MAVLINK_PARAM_DEFINE(RC_MAP_YAW, 4),
    MAVLINK_PARAM_DEFINE(RC_MAP_THROTTLE, 3),
    MAVLINK_PARAM_DEFINE(RC_MAP_FAILSAFE, 0),
    MAVLINK_PARAM_DEFINE(RC_MAP_MODE_SW, 5),
    MAVLINK_PARAM_DEFINE(RC_MAP_RETURN_SW, 7),
    MAVLINK_PARAM_DEFINE(RC_MAP_FLAPS, 0),
    MAVLINK_PARAM_DEFINE(RC_MAP_RATT_SW, 0),
    MAVLINK_PARAM_DEFINE(RC_MAP_POSCTL_SW, 0),
    MAVLINK_PARAM_DEFINE(RC_MAP_LOITER_SW, 0),
    MAVLINK_PARAM_DEFINE(RC_MAP_ACRO_SW, 0),
    MAVLINK_PARAM_DEFINE(RC_MAP_OFFB_SW, 0),
    MAVLINK_PARAM_DEFINE(RC_MAP_KILL_SW, 9),
    MAVLINK_PARAM_DEFINE(RC_MAP_AUX1, 5),
    MAVLINK_PARAM_DEFINE(RC_MAP_AUX2, 6),
    MAVLINK_PARAM_DEFINE(RC_MAP_AUX3, 7),
    MAVLINK_PARAM_DEFINE(RC_MAP_AUX4, 8),
    MAVLINK_PARAM_DEFINE(RC_MAP_AUX5, 0),
    MAVLINK_PARAM_DEFINE(RC_MAP_PARAM1, 0),
    MAVLINK_PARAM_DEFINE(RC_MAP_PARAM2, 0),
    MAVLINK_PARAM_DEFINE(RC_MAP_PARAM3, 0),
    MAVLINK_PARAM_DEFINE(RC_MAP_FLTMODE, 0),
    MAVLINK_PARAM_DEFINE(RC_FAILS_THR, 0),
    MAVLINK_PARAM_DEFINE(RC_ASSIST_TH, 0.25),
    MAVLINK_PARAM_DEFINE(RC_AUTO_TH, 0.75),
    MAVLINK_PARAM_DEFINE(RC_RATT_TH, 0.5),
    MAVLINK_PARAM_DEFINE(RC_POSCTL_TH, 0.5),
    MAVLINK_PARAM_DEFINE(RC_RETURN_TH, 0.5),
    MAVLINK_PARAM_DEFINE(RC_LOITER_TH, 0.5),
    MAVLINK_PARAM_DEFINE(RC_ACRO_TH, 0.5),
    MAVLINK_PARAM_DEFINE(RC_OFFB_TH, 0.5),
    MAVLINK_PARAM_DEFINE(RC_KILLSWITCH_TH, 0.7),
    MAVLINK_PARAM_DEFINE(RC_CHAN_CNT, 0),
    MAVLINK_PARAM_DEFINE(RC_TH_USER, 1),
    MAVLINK_PARAM_DEFINE(COM_DL_LOSS_T, 10),
    MAVLINK_PARAM_DEFINE(COM_DL_REG_T, 0),
    MAVLINK_PARAM_DEFINE(COM_EF_THROT, 0.5),
    MAVLINK_PARAM_DEFINE(COM_EF_C2T, 5),
    MAVLINK_PARAM_DEFINE(COM_EF_TIME, 10),
    MAVLINK_PARAM_DEFINE(COM_RC_LOSS_T, 0.5),
    MAVLINK_PARAM_DEFINE(COM_HOME_H_T, 5),
    MAVLINK_PARAM_DEFINE(COM_HOME_V_T, 10),
    MAVLINK_PARAM_DEFINE(COM_AUTOS_PAR, 1),
    MAVLINK_PARAM_DEFINE(COM_RC_IN_MODE, 0),
    MAVLINK_PARAM_DEFINE(COM_RC_ARM_HYST, 1000),
    MAVLINK_PARAM_DEFINE(COM_DISARM_LAND, 2),
    MAVLINK_PARAM_DEFINE(COM_LOW_BAT_ACT, 1),
    MAVLINK_PARAM_DEFINE(BAT_H_CURR, 12),
    MAVLINK_PARAM_DEFINE(BAT_V_CURR, 10),
    MAVLINK_PARAM_DEFINE(BAT_C_SAFE, 700),
    MAVLINK_PARAM_DEFINE(BAT_C_SAFE_UB, 1500),
    MAVLINK_PARAM_DEFINE(BAT_V_SCALE_IO, 100),
    MAVLINK_PARAM_DEFINE(BAT_CNT_V_VOLT, -1),
    MAVLINK_PARAM_DEFINE(BAT_CNT_V_CURR, -1),
    MAVLINK_PARAM_DEFINE(BAT_V_OFFS_CURR, 0),
    MAVLINK_PARAM_DEFINE(BAT_V_DIV, 10.19699955),
    MAVLINK_PARAM_DEFINE(BAT_A_PER_V, -1),
    MAVLINK_PARAM_DEFINE(BAT_V_EMPTY, 3.2),
    MAVLINK_PARAM_DEFINE(BAT_V_CHARGED, 4.2),
    MAVLINK_PARAM_DEFINE(BAT_LOW_THR, 0.2),
    MAVLINK_PARAM_DEFINE(BAT_CRIT_THR, 0.1),
    MAVLINK_PARAM_DEFINE(BAT_EMERGEN_THR, 0.05),
    MAVLINK_PARAM_DEFINE(BAT_V_LOAD_DROP, 0.3),
    MAVLINK_PARAM_DEFINE(BAT_N_CELLS, 4),
    MAVLINK_PARAM_DEFINE(BAT_CAPACITY, -1),
    MAVLINK_PARAM_DEFINE(NAV_DLL_ACT, 0),
    MAVLINK_PARAM_DEFINE(NAV_RCL_ACT, 2),
    MAVLINK_PARAM_DEFINE(RTL_RETURN_ALT, 15),
    MAVLINK_PARAM_DEFINE(RTL_DESCEND_ALT, 30),
    MAVLINK_PARAM_DEFINE(RTL_LAND_DELAY, 3),
    MAVLINK_PARAM_DEFINE(RTL_MIN_DIST, 0.5),
    MAVLINK_PARAM_DEFINE(COM_FLTMODE1, 0),
    MAVLINK_PARAM_DEFINE(COM_FLTMODE2, 1),
    MAVLINK_PARAM_DEFINE(COM_FLTMODE3, 2),
    MAVLINK_PARAM_DEFINE(COM_FLTMODE4, 3),
    MAVLINK_PARAM_DEFINE(COM_FLTMODE5, 4),
    MAVLINK_PARAM_DEFINE(COM_FLTMODE6, 5),
    MAVLINK_PARAM_DEFINE(GF_ACTION, 1),
    MAVLINK_PARAM_DEFINE(GF_ALTMODE, 0),
    MAVLINK_PARAM_DEFINE(GF_SOURCE, 0),
    MAVLINK_PARAM_DEFINE(GF_COUNT, -1),
    MAVLINK_PARAM_DEFINE(GF_MAX_HOR_DIST, -1),
    MAVLINK_PARAM_DEFINE(GF_MAX_VER_DIST, -1),
    MAVLINK_PARAM_DEFINE(GF_FENCE_SW, 1),
    MAVLINK_PARAM_DEFINE(MC_ROLL_TC, 0.0),
    MAVLINK_PARAM_DEFINE(MC_PITCH_TC, 0.0),
    MAVLINK_PARAM_DEFINE(MC_ROLL_P, 0.0),
    MAVLINK_PARAM_DEFINE(MC_ROLLRATE_P, 0.0),
    MAVLINK_PARAM_DEFINE(MC_ROLLRATE_I, 0.0),
    MAVLINK_PARAM_DEFINE(MC_ROLLRATE_D, 0.0),
    MAVLINK_PARAM_DEFINE(MC_PITCH_P, 0.0),
    MAVLINK_PARAM_DEFINE(MC_PITCHRATE_P, 0.0),
    MAVLINK_PARAM_DEFINE(MC_PITCHRATE_I, 0.0),
    MAVLINK_PARAM_DEFINE(MC_PITCHRATE_D, 0.0),
    MAVLINK_PARAM_DEFINE(MC_YAW_P, 0.0),
    MAVLINK_PARAM_DEFINE(MC_YAWRATE_P, 0.0),
    MAVLINK_PARAM_DEFINE(MC_YAWRATE_I, 0.0),
    MAVLINK_PARAM_DEFINE(MC_YAWRATE_D, 0.0),
    MAVLINK_PARAM_DEFINE(MPC_THR_MIN, 0.15),
    MAVLINK_PARAM_DEFINE(MPC_THR_HOVER, 0.5),
    MAVLINK_PARAM_DEFINE(MPC_THR_MAX, 0.9),
    MAVLINK_PARAM_DEFINE(MPC_MANTHR_MIN, 0.15),
    MAVLINK_PARAM_DEFINE(MPC_MANTHR_MAX, 0.9),
    MAVLINK_PARAM_DEFINE(MPC_Z_P, 0.0),
    MAVLINK_PARAM_DEFINE(MPC_Z_VEL_P, 0.0),
    MAVLINK_PARAM_DEFINE(MPC_Z_VEL_I, 0.0),
    MAVLINK_PARAM_DEFINE(MPC_Z_VEL_D, 0.0),
    MAVLINK_PARAM_DEFINE(MPC_XY_P, 0.0),
    MAVLINK_PARAM_DEFINE(MPC_XY_VEL_P, 0.0),
    MAVLINK_PARAM_DEFINE(MPC_XY_VEL_I, 0.0),
    MAVLINK_PARAM_DEFINE(MPC_XY_VEL_D, 0.0),
};

static int get_index(const mav_param_t* param)
{
    mav_param_t* mav_param = (mav_param_t*)&mavlink_param;

    return param - mav_param;
}

static mav_param_t* get_mavparam_by_index(uint32_t index)
{
    mav_param_t* mav_param = (mav_param_t*)&mavlink_param;

    return &mav_param[index];
}

static void make_mavparam_msg(mavlink_message_t* msg_t, const mav_param_t* param)
{
    mavlink_param_value_t mav_param_value;
    uint16_t len = strlen(param->name);
    mavlink_system_t mavlink_system = mavproxy_get_system();

    mav_param_value.param_count = MAV_PARAM_COUNT + param_get_count();
    mav_param_value.param_index = get_index(param);
    memset(mav_param_value.param_id, 0, 16);
    memcpy(mav_param_value.param_id, param->name, len < 16 ? len : 16);

    mav_param_value.param_type = MAVLINK_TYPE_FLOAT;
    mav_param_value.param_value = param->value;

    mavlink_msg_param_value_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &mav_param_value);
}

fmt_err_t send_mavparam_by_name(char* name)
{
    mav_param_t* mav_param;
    mavlink_message_t msg;

    for (uint32_t i = 0; i < MAV_PARAM_COUNT; i++) {
        mav_param = get_mavparam_by_index(i);
        if (mav_param == NULL) {
            return FMT_EEMPTY;
        }

        if (strcmp(mav_param->name, name) == 0) {
            make_mavparam_msg(&msg, mav_param);
            mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, true);
            return FMT_EOK;
        }
    }

    return FMT_EINVAL;
}

fmt_err_t send_mavparam_by_index(int16_t index)
{
    mav_param_t* mav_param = get_mavparam_by_index(index);
    mavlink_message_t msg;

    if (mav_param == NULL) {
        return FMT_EINVAL;
    }

    make_mavparam_msg(&msg, mav_param);
    mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, true);

    return FMT_EOK;
}

uint16_t get_mavparam_num(void)
{
    return MAV_PARAM_COUNT;
}

static void make_mavlink_param_msg(mavlink_message_t* msg_t, const param_t* param)
{
    mavlink_param_value_t mav_param_value;
    uint16_t len = strlen(param->name);
    mavlink_system_t mavlink_system = mavproxy_get_system();

    mav_param_value.param_count = MAV_PARAM_COUNT + param_get_count();
    mav_param_value.param_index = MAV_PARAM_COUNT + param_get_index(param);
    memset(mav_param_value.param_id, 0, 16);
    memcpy(mav_param_value.param_id, param->name, len < 16 ? len : 16);

    switch (param->type) {
    case PARAM_TYPE_DOUBLE:
        /* mavlink param doesn't support double type, so transfer it to float */
        mav_param_value.param_type = MAVLINK_TYPE_FLOAT;
        mav_param_value.param_value = (float)param->val.lf;
        break;

    case PARAM_TYPE_FLOAT:
        mav_param_value.param_type = MAVLINK_TYPE_FLOAT;
        mav_param_value.param_value = param->val.f;
        break;

    case PARAM_TYPE_INT32:
        mav_param_value.param_type = MAVLINK_TYPE_INT32_T;
        memcpy(&(mav_param_value.param_value), &(param->val.i32), sizeof(param->val.i32));
        break;

    case PARAM_TYPE_UINT32:
        mav_param_value.param_type = MAVLINK_TYPE_UINT32_T;
        memcpy(&(mav_param_value.param_value), &(param->val.u32), sizeof(param->val.u32));
        break;

    case PARAM_TYPE_INT16:
        mav_param_value.param_type = MAVLINK_TYPE_INT16_T;
        memcpy(&(mav_param_value.param_value), &(param->val.i16), sizeof(param->val.i16));
        break;

    case PARAM_TYPE_UINT16:
        mav_param_value.param_type = MAVLINK_TYPE_UINT16_T;
        memcpy(&(mav_param_value.param_value), &(param->val.u16), sizeof(param->val.u16));
        break;

    case PARAM_TYPE_INT8:
        mav_param_value.param_type = MAVLINK_TYPE_INT8_T;
        memcpy(&(mav_param_value.param_value), &(param->val.i8), sizeof(param->val.i8));
        break;

    case PARAM_TYPE_UINT8:
        mav_param_value.param_type = MAVLINK_TYPE_UINT8_T;
        memcpy(&(mav_param_value.param_value), &(param->val.u8), sizeof(param->val.u8));
        break;

    default:
        console_printf("unknow parameter type: %d", param->type);
        return;
    }

    mavlink_msg_param_value_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &mav_param_value);
}

fmt_err_t mavlink_param_set(const char* name, float val, uint8_t mav_param_type)
{
    fmt_err_t err;
    param_t* param;
    int8_t i8val;
    uint8_t u8val;
    int16_t i16val;
    uint16_t u16val;
    int32_t i32val;
    uint32_t u32val;
    float fval;
    double lfval;

    param = param_get_by_name(name);

    if (param == NULL) {
        return FMT_ERROR;
    }

    switch (param->type) {
    case PARAM_TYPE_INT8:
        if (mav_param_type == MAV_PARAM_TYPE_REAL32 || mav_param_type == MAV_PARAM_TYPE_REAL64) {
            i8val = (int8_t)val;
        } else {
            memcpy(&i8val, &val, sizeof(i8val));
        }
        err = param_set_val(param, &i8val);
        break;
    case PARAM_TYPE_UINT8:
        if (mav_param_type == MAV_PARAM_TYPE_REAL32 || mav_param_type == MAV_PARAM_TYPE_REAL64) {
            u8val = (uint8_t)val;
        } else {
            memcpy(&u8val, &val, sizeof(u8val));
        }
        err = param_set_val(param, &u8val);
        break;
    case PARAM_TYPE_INT16:
        if (mav_param_type == MAV_PARAM_TYPE_REAL32 || mav_param_type == MAV_PARAM_TYPE_REAL64) {
            i16val = (int16_t)val;
        } else {
            memcpy(&i16val, &val, sizeof(i16val));
        }
        err = param_set_val(param, &i16val);
        break;
    case PARAM_TYPE_UINT16:
        if (mav_param_type == MAV_PARAM_TYPE_REAL32 || mav_param_type == MAV_PARAM_TYPE_REAL64) {
            u16val = (uint16_t)val;
        } else {
            memcpy(&u16val, &val, sizeof(u16val));
        }
        err = param_set_val(param, &u16val);
        break;
    case PARAM_TYPE_INT32:
        if (mav_param_type == MAV_PARAM_TYPE_REAL32 || mav_param_type == MAV_PARAM_TYPE_REAL64) {
            i32val = (int32_t)val;
        } else {
            memcpy(&i32val, &val, sizeof(i32val));
        }
        err = param_set_val(param, &i32val);
        break;
    case PARAM_TYPE_UINT32:
        if (mav_param_type == MAV_PARAM_TYPE_REAL32 || mav_param_type == MAV_PARAM_TYPE_REAL64) {
            u32val = (uint32_t)val;
        } else {
            memcpy(&u32val, &val, sizeof(u32val));
        }
        err = param_set_val(param, &u32val);
        break;
    case PARAM_TYPE_FLOAT:
        fval = val;
        err = param_set_val(param, &fval);
        break;
    case PARAM_TYPE_DOUBLE:
        lfval = (double)val;
        err = param_set_val(param, &lfval);
        break;
    default:
        return FMT_EINVAL;
    }

    return err;
}

fmt_err_t mavlink_param_send(const param_t* param)
{
    mavlink_message_t msg;

    if (param == NULL) {
        return FMT_EINVAL;
    }

    make_mavlink_param_msg(&msg, param);
    mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, false);

    return FMT_EOK;
}

void mavlink_param_sendall(void)
{
    mavlink_message_t msg;
    param_t* param;
    param_group_t* gp = param_get_table();
    mav_param_t* mav_param;

    for (uint32_t i = 0; i < MAV_PARAM_COUNT; i++) {
        mav_param = get_mavparam_by_index(i);

        if (!mav_param) {
            break;
        }

        make_mavparam_msg(&msg, mav_param);
        mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, true);
    }

    for (uint32_t i = 0; i < param_get_group_count(); i++) {
        param = gp->param_list;

        for (uint32_t j = 0; j < gp->param_num; j++) {
            make_mavlink_param_msg(&msg, param);
            mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, true);
            param++;
        }

        gp++;
    }
}
