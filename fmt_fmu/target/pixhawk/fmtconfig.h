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

#ifndef __FMTCONFIG_H__
#define __FMTCONFIG_H__

#define FMT_BUILD_CHECK

/* HIL simulation */
//#define FMT_USING_HIL

#ifdef FMT_USING_HIL
    /* Simulator-in-hardware simulation, if not defined, the standard HIL will be used */
    #define FMT_USING_SIH   

    /* enable actuator output in simulation mode */
    // #define FMT_HIL_WITH_ACTUATOR   

    /* send out pilot_cmd by mavlink */ 
    #define FMT_OUTPUT_PILOT_CMD    
#endif

/* Mavlink */
#define FMT_USING_MAVLINK_V2
#define FMT_MAVLINK_SYS_ID  1
#define FMT_MAVLINK_COMP_ID 1

/* ULog */
#define FMT_USING_ULOG
#ifdef FMT_USING_ULOG
// #define ENABLE_ULOG_FS_BACKEND
#define ENABLE_ULOG_CONSOLE_BACKEND
#endif

/* Cortex-M Backtrace */
#define FMT_USING_CM_BACKTRACE

#define FMT_USING_AUX_MOTOR

#define FMT_ONLINE_PARAM_TUNING

#define FMT_RECORD_CALIBRATION_DATA

// #define FMT_TEST_MOTOR

#endif
