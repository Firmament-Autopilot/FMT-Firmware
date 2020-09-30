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

#ifndef __TASK_FMTIO_H__
#define __TASK_FMTIO_H__

#include <firmament.h>
#include "module/fmtio/fmtio_protocol.h"

#define FMT_IO_BUFFER_SIZE				10
#define	FMT_IO_PKG_DATA_SIZE			256

#define FMTIO_MOTOR_CHANNEL_NUM     8
#define FMTIO_RC_CHANNEL_NUM        8

/* fmtio configuration, 0 means unchange */
typedef struct {
    uint32_t baud_rate;     // serial baudrate
    uint16_t pwm_freq;      // pwm output frequency
    uint16_t rc_proto;       // 1:sbus 2:ppm
} fmtio_config_t;

fmt_err task_fmtio_init(void);
void task_fmtio_entry(void* parameter);
fmt_err fmtio_init_pkg(uint16_t cmd, void* buffer, PackageStruct* pkg);
fmt_err fmtio_create_pkg(uint16_t cmd, uint16_t buff_len, PackageStruct* pkg);
fmt_err fmtio_send_pkg(const void* data, uint16_t len, PackageStruct* pkg);
fmt_err fmtio_send_message(uint16_t cmd, const void* data, uint16_t len);
void fmtio_suspend_comm(uint8_t suspend);
rt_device_t fmtio_get_device(void);
fmt_err fmtio_config(fmtio_config_t* io_config);

#endif