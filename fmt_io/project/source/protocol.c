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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "protocol.h"
#include "ppm_decoder.h"
#include "usart.h"
#include "pwm.h"

/* Work as client */
#define PROTOCOL_CLIENT

#define PROTOCOL_SERVER_HEAD        0x5A
#define PROTOCOL_CLIENT_HEAD        0x5B

#define PROTOCOL_HEAD_MAGIC         0xFA
#ifdef PROTOCOL_SERVER
	#define PROTOCOL_HEAD_TX        PROTOCOL_SERVER_HEAD
	#define PROTOCOL_HEAD_RX        PROTOCOL_CLIENT_HEAD
#elif defined (PROTOCOL_CLIENT)
	#define PROTOCOL_HEAD_TX        PROTOCOL_CLIENT_HEAD
	#define PROTOCOL_HEAD_RX        PROTOCOL_SERVER_HEAD
#else
	#error Please define PROTOCOL_SERVER or PROTOCOL_CLIENT
#endif
#define PROTOCOL_END                0xFC

/**************************** Local Function ********************************/

static void _fill_head(PackageStruct* pkg)
{
	pkg->head[0] = PROTOCOL_HEAD_MAGIC;
	pkg->head[1] = PROTOCOL_HEAD_TX;
}

static void _fill_end(PackageStruct* pkg)
{
	pkg->end = PROTOCOL_END;
}

static uint16_t _calc_checksum(PackageStruct* pkg)
{
	uint16_t cheksum;
	uint16_t i;

	cheksum = pkg->head[0] + pkg->head[1] + ((pkg->len & 0xFF) + ((pkg->len >> 8) & 0xFF)) + pkg->cmd;

	for(i = 0 ; i < pkg->len ; i++) {
		cheksum += pkg->content[i];
	}

	cheksum += pkg->alloc;

	return cheksum;
}

/**************************** Public Function ********************************/

FMT_Error init_package(uint16_t cmd, uint16_t buff_len, PackageStruct* pkg)
{
	/* fill head */
	_fill_head(pkg);

	/* set length filed */
	pkg->len = 0;
	/* set command filed */
	pkg->cmd = cmd;

	/* content filed allocation */
	if(buff_len) {
		pkg->content = malloc(buff_len);

		if(pkg->content == NULL) {
			return SYS_ERROR;
		}
	} else {
		pkg->content = NULL;
	}

	/* set default value */
	pkg->alloc = 1;

	if(pkg->len == 0) {
		/* calculate init checksum */
		pkg->checksum = _calc_checksum(pkg);
	} else {
		pkg->checksum  = 0;
	}

	/* fill end */
	_fill_end(pkg);

	return SYS_EOK;
}

FMT_Error init_static_package(uint16_t cmd, uint8_t* buffer, PackageStruct* pkg)
{
	if(buffer == NULL)
		return SYS_EINVAL;

	/* fill head */
	_fill_head(pkg);

	/* set length filed */
	pkg->len = 0;
	/* set command filed */
	pkg->cmd = cmd;
	/* allocate a static memory for content filed */
	pkg->content = buffer;
	/* set default value */
	pkg->alloc = 0;

	if(pkg->len == 0) {
		/* calculate init checksum */
		pkg->checksum = _calc_checksum(pkg);
	}

	/* fill end */
	_fill_end(pkg);

	return SYS_EOK;
}

FMT_Error write_package(uint8_t* content, uint16_t len, PackageStruct* pkg)
{
	pkg->len = len;

	/* check if content filed valid */
	if(pkg->len && pkg->content == NULL) {
		return SYS_ERROR;
	}

	/* copy content */
	if(pkg->len && content && pkg->content != content) {
		memcpy(pkg->content, content, pkg->len);
	}

	/* calculate checksum */
	pkg->checksum = _calc_checksum(pkg);

	return SYS_EOK;
}

void free_package(PackageStruct* pkg)
{
	if(pkg->alloc == 1 && pkg->content) {
		/* free memory if it's allocated before */
		free(pkg->content);
		pkg->content = NULL;
		pkg->alloc = 0;
	}
}

FMT_Error make_send_package(const PackageStruct pkg, SendPkgStruct* send_pkg)
{
	/* user should assgin a valid address for send_buff */
	if(send_pkg->send_buff == NULL)
		return SYS_EINVAL;

	send_pkg->send_buff[0] = pkg.head[0];
	send_pkg->send_buff[1] = pkg.head[1];

	/* little-endian */
	*((uint16_t*)&send_pkg->send_buff[2]) = pkg.len;
	*((uint16_t*)&send_pkg->send_buff[4]) = pkg.cmd;

	if(pkg.len > 0) {
		memcpy(&send_pkg->send_buff[6], pkg.content, pkg.len);
	}

	send_pkg->send_buff[6 + pkg.len] = pkg.alloc;

	*((uint16_t*)&send_pkg->send_buff[7 + pkg.len]) = pkg.checksum;
	send_pkg->send_buff[9 + pkg.len] = pkg.end;

	/* buff_size = content_len + len_except_content */
	send_pkg->buff_size = pkg.len + 10;

	return SYS_EOK;
}

/* pkg parse states define */
#define STATE_HEAD_1	        0x00
#define STATE_HEAD_2	        0x01
#define STATE_LEN_1	            0x02
#define STATE_LEN_2	            0x03
#define STATE_CMD_1	            0x04
#define STATE_CMD_2	            0x05
#define STATE_CONTENT	        0x06
#define STATE_ALLOC             0x07
#define STATE_CS_1	            0x08
#define STATE_CS_2	            0x09
#define STATE_END	            0x0A

FMT_Error proto_parse_package(uint8_t c, PackageStruct* pkg)
{
	FMT_Error err = SYS_ERROR;
	static uint8_t state = STATE_HEAD_1;
	static uint16_t data_cnt;

	switch(state) {
		case STATE_HEAD_1:
			if(c == PROTOCOL_HEAD_MAGIC) {
				pkg->head[0] = c;

				state = STATE_HEAD_2;
			}

			/* wait more data */
			err = SYS_EEMPTY;
			break;

		case STATE_HEAD_2:
			if(c == PROTOCOL_HEAD_RX) {
				pkg->head[1] = c;

				state = STATE_LEN_1;
			} else {
				/* wrong data, go back to init state */
				state = STATE_HEAD_1;
			}

			err = SYS_EEMPTY;
			break;

		case STATE_LEN_1:
			/* little-endian, so we first receive low byte data */
			pkg->len = c;

			state = STATE_LEN_2;
			err = SYS_EEMPTY;
			break;

		case STATE_LEN_2:
			/* little-endian, receive high byte data */
			pkg->len |= c << 8;

			if(pkg->len > MAX_PACKAGE_SIZE) {
				state = STATE_HEAD_1;
			} else {
				state = STATE_CMD_1;
			}

			err = SYS_EEMPTY;
			break;

		case STATE_CMD_1:
			pkg->cmd = c;

			state = STATE_CMD_2;
			err = SYS_EEMPTY;
			break;

		case STATE_CMD_2:
			pkg->cmd |= c << 8;

			if(pkg->len) {
				data_cnt = 0;
				state = STATE_CONTENT;
			} else {
				/* if there is no content, we skip content state */
				state = STATE_ALLOC;
			}

			err = SYS_EEMPTY;
			break;

		case STATE_CONTENT:
			pkg->content[data_cnt++] = c;

			if(data_cnt >= pkg->len) {
				state = STATE_ALLOC;
			}

			err = SYS_EEMPTY;
			break;

		case STATE_ALLOC:
			pkg->alloc = c;

			state = STATE_CS_1;
			err = SYS_EEMPTY;
			break;

		case STATE_CS_1:
			pkg->checksum = c;

			state = STATE_CS_2;
			err = SYS_EEMPTY;
			break;

		case STATE_CS_2:
			pkg->checksum |= c << 8;

			if(_calc_checksum(pkg) != pkg->checksum) {
				state = STATE_HEAD_1;
			} else {
				state = STATE_END;
			}

			err = SYS_EEMPTY;
			break;

		case STATE_END:
			if(c == PROTOCOL_END) {
				pkg->end = c;
				/* we have received a complate pkg */
				state = STATE_HEAD_1;
				err = SYS_EOK;
			} else {
				state = STATE_HEAD_1;
				err = SYS_EEMPTY;
			}

			break;
	}

	return err;
}

