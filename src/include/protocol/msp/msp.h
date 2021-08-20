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
#ifndef MSP_H__
#define MSP_H__

#include <firmament.h>

#include "protocol/msp/msp_protocol_v2_sensor.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MSP_V2_FRAME_ID      255
#define MSP_PORT_INBUF_SIZE  192
#define MSP_PORT_OUTBUF_SIZE 512

typedef struct __attribute__((packed)) {
    uint8_t size;
    uint8_t cmd;
} mspHeaderV1_t;

typedef struct __attribute__((packed)) {
    uint8_t flags;
    uint16_t cmd;
    uint16_t size;
} mspHeaderV2_t;

typedef enum {
    MSP_V1 = 0,
    MSP_V2_OVER_V1 = 1,
    MSP_V2_NATIVE = 2,
    MSP_VERSION_COUNT
} mspVersion_e;

#define MSP_VERSION_MAGIC_INITIALIZER \
    {                                 \
        'M', 'M', 'X'                 \
    }

// return positive for ACK, negative on error, zero for no reply
typedef enum {
    MSP_RESULT_ACK = 1,
    MSP_RESULT_ERROR = -1,
    MSP_RESULT_NO_REPLY = 0
} mspResult_e;

typedef enum {
    MSP_FLAG_DONT_REPLY = (1 << 0),
} mspFlags_e;

typedef struct mspPacket_s {
    uint8_t* buf;
    int16_t cmd;
    uint8_t flags;
    int16_t result;
} mspPacket_t;

typedef enum {
    MSP_IDLE,
    MSP_HEADER_START,
    MSP_HEADER_M,
    MSP_HEADER_X,

    MSP_HEADER_V1,
    MSP_PAYLOAD_V1,
    MSP_CHECKSUM_V1,

    MSP_HEADER_V2_OVER_V1,
    MSP_PAYLOAD_V2_OVER_V1,
    MSP_CHECKSUM_V2_OVER_V1,

    MSP_HEADER_V2_NATIVE,
    MSP_PAYLOAD_V2_NATIVE,
    MSP_CHECKSUM_V2_NATIVE,

    MSP_COMMAND_RECEIVED
} mspState_e;

typedef enum {
    MSP_EVALUATE_NON_MSP_DATA,
    MSP_SKIP_NON_MSP_DATA
} mspEvaluateNonMspData_e;

typedef enum {
    MSP_PENDING_NONE,
    MSP_PENDING_BOOTLOADER,
    MSP_PENDING_CLI
} mspPendingSystemRequest_e;

typedef mspResult_e (*mspProcessCommandFnPtr)(mspPacket_t* cmd, mspPacket_t* reply);
typedef struct mspPort_s {
    rt_device_t dev;
    uint32_t lastActivityMs;
    mspPendingSystemRequest_e pendingRequest;
    mspState_e c_state;
    uint8_t inBuf[MSP_PORT_INBUF_SIZE];
    uint_fast16_t offset;
    uint_fast16_t dataSize;
    mspVersion_e mspVersion;
    uint8_t cmdFlags;
    uint16_t cmdMSP;
    uint8_t checksum1;
    uint8_t checksum2;
    mspProcessCommandFnPtr mspProcessCommandFn;
} mspPort_t;

mspPort_t* msp_register(rt_device_t dev, mspProcessCommandFnPtr mspProcessCommandFn);
fmt_err_t msp_server_start(void);

#ifdef __cplusplus
}
#endif

#endif
