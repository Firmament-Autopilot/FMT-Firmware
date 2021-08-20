/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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

#ifndef PROTOCOL_H__
#define PROTOCOL_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define IO_BUFFER_SIZE 256

#define IO_PKT_HEAD     0xFA5C
#define IO_REBOOT_MAGIC 0x315C

#define IO_CODE_SYNC            0x00
#define IO_CODE_REBOOT          0x01
#define IO_CODE_W_ACTUATOR      0x02
#define IO_CODE_CTRL_ACTUATOR   0x03
#define IO_CODE_CONFIG_ACTUATOR 0x05
#define IO_CODE_CONFIG_RC       0x06
#define IO_CODE_RC_DATA         0x07
#define IO_CODE_DBG_TEXT        0x08

#define PKT_SIZE(_pkt) (sizeof(struct IOPacket) - IO_BUFFER_SIZE + (_pkt)->len)

#pragma pack(push, 1)
struct IOPacket {
    uint16_t head;
    uint8_t code;
    uint16_t len;
    uint8_t crc;
    uint8_t data[IO_BUFFER_SIZE];
};
#pragma pack(pop)

typedef enum {
    RXState_HEAD,
    RXState_CODE,
    RXState_LEN,
    RXState_CRC,
    RXState_DATA,
} IO_RXState;

/* fmtio actuator configuration */
typedef struct {
    uint16_t pwm_freq; // pwm output frequency
} IO_ActuatorConfig;

/* fmtio rc configuration */
typedef struct {
    uint16_t protocol; // 1:sbus 2:ppm
    float sample_time; // rc sample time in seconds (-1 for inherits)
} IO_RCConfig;

void init_io_pkt(struct IOPacket* pkt);
struct IOPacket* create_io_pkt(void);
void delete_io_pkt(struct IOPacket* pkt);
fmt_err_t set_io_pkt(struct IOPacket* pkt, uint8_t code, void* data, uint16_t len);
fmt_err_t io_parse_char(struct IOPacket* pkt, uint8_t c);
uint8_t crc_packet(struct IOPacket* pkt);

#ifdef __cplusplus
}
#endif

#endif