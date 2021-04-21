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

#ifndef __FMTIO_PROTOCOL_H__
#define __FMTIO_PROTOCOL_H__

#include <firmament.h>

#define MAX_PACKAGE_SIZE            128

typedef struct {
	uint8_t		head[2];
	uint16_t	len;
	uint16_t	cmd;
	uint8_t* 	content;
	uint8_t     alloc;
	uint16_t 	checksum;
	uint8_t		end;
} PackageStruct;

typedef struct {
	uint8_t* 	send_buff;
	uint16_t 	buff_size;
} SendPkgStruct;

enum {
	PROTO_CMD_SYNC = 1,
	PROTO_ACK_SYNC = 2,
	PROTO_CMD_REBOOT = 3,
	PROTO_DBG_TEXT = 4,
	PROTO_DATA_RC = 5,
	PROTO_CMD_MOTOR = 6,
	PROTO_GET_MOTOR_VAL = 7,
	PROTO_ACK_MOTOR_VAL = 8,
	PROTO_CMD_PWM_SWITCH = 9,
	PROTO_CMD_DEV_CONFIG = 10,
    PROTO_CMD_RC_CONFIG = 11,
    PROTO_CMD_MOTOR_CONFIG = 12,
};

fmt_err_t create_io_package(uint16_t cmd, uint16_t buff_len, PackageStruct* pkg);
fmt_err_t init_io_package(uint16_t cmd, uint8_t* buffer, PackageStruct* pkg);
fmt_err_t fill_io_package(const void* content, uint16_t len, PackageStruct* pkg);
void free_io_package(PackageStruct* pkg);
fmt_err_t make_send_package(const PackageStruct pkg, SendPkgStruct* send_pkg);
fmt_err_t proto_parse_package(uint8_t c, PackageStruct* pkg);

#endif
