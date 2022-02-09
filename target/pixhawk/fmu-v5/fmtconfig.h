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

#ifndef FMTCONFIG_H__
#define FMTCONFIG_H__

#define FMT_USING_CHECKED

/* HIL simulation */
// #define FMT_USING_HIL
/* SIG simulation */
// #define FMT_USING_SIH

/* Mavlink */
#define FMT_USING_MAVLINK_V2
#define FMT_MAVLINK_SYS_ID  1
#define FMT_MAVLINK_COMP_ID 1

/* Send out pilot cmd via mavlink */
#define FMT_OUTPUT_PILOT_CMD

/* MLog */
#define MLOG_BUFFER_SIZE         80 * 1024
#define MLOG_SECTOR_SIZE         4096
#define MLOG_MAX_SECTOR_TO_WRITE 5

/* ULog */
#define FMT_USING_ULOG
#ifdef FMT_USING_ULOG
// #define ENABLE_ULOG_FS_BACKEND
#define ENABLE_ULOG_CONSOLE_BACKEND
#endif

/* Cortex-M Backtrace */
#define FMT_USING_CM_BACKTRACE

/* Unit Test */
// #define FMT_USING_UNIT_TEST

// #define FMT_RECORD_CALIBRATION_DATA

#endif
