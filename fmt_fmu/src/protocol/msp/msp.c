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

#include "protocol/msp/msp.h"

#define MAX_MSP_PORTS    5
#define EVENT_MSP_UPDATE (1 << 0)

static rt_thread_t mspThread = NULL;
static mspPort_t* mspPorts[MAX_MSP_PORTS] = { 0 };
static struct rt_timer timer_msp;
static struct rt_event event_msp;

static uint8_t crc8_dvb_s2(uint8_t crc, unsigned char a)
{
    crc ^= a;
    for (int ii = 0; ii < 8; ++ii) {
        if (crc & 0x80) {
            crc = (crc << 1) ^ 0xD5;
        } else {
            crc = crc << 1;
        }
    }
    return crc;
}

static void msp_timer_update(void* parameter)
{
    rt_event_send(&event_msp, EVENT_MSP_UPDATE);
}

static bool msp_process_rx_data(mspPort_t* mspPort, uint8_t c)
{
    switch (mspPort->c_state) {
    default:
    case MSP_IDLE: // Waiting for '$' character
        if (c == '$') {
            mspPort->mspVersion = MSP_V1;
            mspPort->c_state = MSP_HEADER_START;
        } else {
            return false;
        }
        break;

    case MSP_HEADER_START: // Waiting for 'M' (MSPv1 / MSPv2_over_v1) or 'X' (MSPv2 native)
        switch (c) {
        case 'M':
            mspPort->c_state = MSP_HEADER_M;
            break;
        case 'X':
            mspPort->c_state = MSP_HEADER_X;
            break;
        default:
            mspPort->c_state = MSP_IDLE;
            break;
        }
        break;

    case MSP_HEADER_M: // Waiting for '<'
        if (c == '<') {
            mspPort->offset = 0;
            mspPort->checksum1 = 0;
            mspPort->checksum2 = 0;
            mspPort->c_state = MSP_HEADER_V1;
        } else {
            mspPort->c_state = MSP_IDLE;
        }
        break;

    case MSP_HEADER_X:
        if (c == '<') {
            mspPort->offset = 0;
            mspPort->checksum2 = 0;
            mspPort->mspVersion = MSP_V2_NATIVE;
            mspPort->c_state = MSP_HEADER_V2_NATIVE;
        } else {
            mspPort->c_state = MSP_IDLE;
        }
        break;

    case MSP_HEADER_V1: // Now receive v1 header (size/cmd), this is already checksummable
        mspPort->inBuf[mspPort->offset++] = c;
        mspPort->checksum1 ^= c;
        if (mspPort->offset == sizeof(mspHeaderV1_t)) {
            mspHeaderV1_t* hdr = (mspHeaderV1_t*)&mspPort->inBuf[0];
            // Check incoming buffer size limit
            if (hdr->size > MSP_PORT_INBUF_SIZE) {
                mspPort->c_state = MSP_IDLE;
            } else if (hdr->cmd == MSP_V2_FRAME_ID) {
                // MSPv1 payload must be big enough to hold V2 header + extra checksum
                if (hdr->size >= sizeof(mspHeaderV2_t) + 1) {
                    mspPort->mspVersion = MSP_V2_OVER_V1;
                    mspPort->c_state = MSP_HEADER_V2_OVER_V1;
                } else {
                    mspPort->c_state = MSP_IDLE;
                }
            } else {
                mspPort->dataSize = hdr->size;
                mspPort->cmdMSP = hdr->cmd;
                mspPort->cmdFlags = 0;
                mspPort->offset = 0;                                                         // re-use buffer
                mspPort->c_state = mspPort->dataSize > 0 ? MSP_PAYLOAD_V1 : MSP_CHECKSUM_V1; // If no payload - jump to checksum byte
            }
        }
        break;

    case MSP_PAYLOAD_V1:
        mspPort->inBuf[mspPort->offset++] = c;
        mspPort->checksum1 ^= c;
        if (mspPort->offset == mspPort->dataSize) {
            mspPort->c_state = MSP_CHECKSUM_V1;
        }
        break;

    case MSP_CHECKSUM_V1:
        if (mspPort->checksum1 == c) {
            mspPort->c_state = MSP_COMMAND_RECEIVED;
        } else {
            mspPort->c_state = MSP_IDLE;
        }
        break;

    case MSP_HEADER_V2_OVER_V1: // V2 header is part of V1 payload - we need to calculate both checksums now
        mspPort->inBuf[mspPort->offset++] = c;
        mspPort->checksum1 ^= c;
        mspPort->checksum2 = crc8_dvb_s2(mspPort->checksum2, c);
        if (mspPort->offset == (sizeof(mspHeaderV2_t) + sizeof(mspHeaderV1_t))) {
            mspHeaderV2_t* hdrv2 = (mspHeaderV2_t*)&mspPort->inBuf[sizeof(mspHeaderV1_t)];
            mspPort->dataSize = hdrv2->size;

            // Check for potential buffer overflow
            if (hdrv2->size > MSP_PORT_INBUF_SIZE) {
                mspPort->c_state = MSP_IDLE;
            } else {
                mspPort->cmdMSP = hdrv2->cmd;
                mspPort->cmdFlags = hdrv2->flags;
                mspPort->offset = 0; // re-use buffer
                mspPort->c_state = mspPort->dataSize > 0 ? MSP_PAYLOAD_V2_OVER_V1 : MSP_CHECKSUM_V2_OVER_V1;
            }
        }
        break;

    case MSP_PAYLOAD_V2_OVER_V1:
        mspPort->checksum2 = crc8_dvb_s2(mspPort->checksum2, c);
        mspPort->checksum1 ^= c;
        mspPort->inBuf[mspPort->offset++] = c;

        if (mspPort->offset == mspPort->dataSize) {
            mspPort->c_state = MSP_CHECKSUM_V2_OVER_V1;
        }
        break;

    case MSP_CHECKSUM_V2_OVER_V1:
        mspPort->checksum1 ^= c;
        if (mspPort->checksum2 == c) {
            mspPort->c_state = MSP_CHECKSUM_V1; // Checksum 2 correct - verify v1 checksum
        } else {
            mspPort->c_state = MSP_IDLE;
        }
        break;

    case MSP_HEADER_V2_NATIVE:
        mspPort->inBuf[mspPort->offset++] = c;
        mspPort->checksum2 = crc8_dvb_s2(mspPort->checksum2, c);
        if (mspPort->offset == sizeof(mspHeaderV2_t)) {
            mspHeaderV2_t* hdrv2 = (mspHeaderV2_t*)&mspPort->inBuf[0];

            // Check for potential buffer overflow
            if (hdrv2->size > MSP_PORT_INBUF_SIZE) {
                mspPort->c_state = MSP_IDLE;
            } else {
                mspPort->dataSize = hdrv2->size;
                mspPort->cmdMSP = hdrv2->cmd;
                mspPort->cmdFlags = hdrv2->flags;
                mspPort->offset = 0; // re-use buffer
                mspPort->c_state = mspPort->dataSize > 0 ? MSP_PAYLOAD_V2_NATIVE : MSP_CHECKSUM_V2_NATIVE;
            }
        }
        break;

    case MSP_PAYLOAD_V2_NATIVE:
        mspPort->checksum2 = crc8_dvb_s2(mspPort->checksum2, c);
        mspPort->inBuf[mspPort->offset++] = c;

        if (mspPort->offset == mspPort->dataSize) {
            mspPort->c_state = MSP_CHECKSUM_V2_NATIVE;
        }
        break;

    case MSP_CHECKSUM_V2_NATIVE:
        if (mspPort->checksum2 == c) {
            mspPort->c_state = MSP_COMMAND_RECEIVED;
        } else {
            mspPort->c_state = MSP_IDLE;
        }
        break;
    }

    return true;
}

static void msp_process_port(mspPort_t* mspPort)
{
    const uint8_t c;

    while (rt_device_read(mspPort->dev, 0, (void*)&c, 1)) {
        msp_process_rx_data(mspPort, c);

        if (mspPort->c_state == MSP_COMMAND_RECEIVED) {
            uint8_t outBuf[MSP_PORT_OUTBUF_SIZE];

            mspPacket_t reply = {
                .buf = outBuf,
                .cmd = -1,
                .flags = 0,
                .result = 0,
            };

            mspPacket_t command = {
                .buf = mspPort->inBuf,
                .cmd = mspPort->cmdMSP,
                .flags = mspPort->cmdFlags,
                .result = 0,
            };

            const mspResult_e status = mspPort->mspProcessCommandFn(&command, &reply);

            if (status != MSP_RESULT_NO_REPLY) {
                //TODO: add reply here
            }

            mspPort->c_state = MSP_IDLE;

            break; // process one command at a time so as not to block.
        }
    }
}

static void msp_server_main(void* args)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_MSP_UPDATE;

    /* register timer event */
    rt_timer_init(&timer_msp, "msp_update", msp_timer_update, RT_NULL, 2,
        RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);

    if (rt_timer_start(&timer_msp) != RT_EOK) {
        console_printf("Error, msp timer start fail!\n");
        return;
    }

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&event_msp, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK) {
            if (recv_set & EVENT_MSP_UPDATE) {
                /* handle msp ports data */
                for (int i = 0; i < MAX_MSP_PORTS; i++) {
                    if (mspPorts[i] != NULL) {
                        msp_process_port(mspPorts[i]);
                    } else {
                        /* NULL indicates the end */
                        break;
                    }
                }
            }
        } else {
            console_printf("Error, msp event recv fail\n");
        }
    }
}

mspPort_t* msp_register(rt_device_t dev, mspProcessCommandFnPtr mspProcessCommandFn)
{
    int idx;

    if (dev == NULL || mspProcessCommandFn == NULL) {
        return NULL;
    }

    for (idx = 0; idx < MAX_MSP_PORTS; idx++) {
        if (mspPorts[idx] == NULL) {
            break;
        }
    }

    if (idx >= MAX_MSP_PORTS) {
        return NULL;
    }

    /* open device */
    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX) != RT_EOK) {
        return NULL;
    }

    mspPorts[idx] = (mspPort_t*)rt_malloc(sizeof(mspPort_t));
    if (mspPorts[idx] == NULL) {
        rt_device_close(dev);
        return NULL;
    }

    /* initialize msp port */
    memset(mspPorts[idx], 0, sizeof(mspPort_t));
    mspPorts[idx]->dev = dev;
    mspPorts[idx]->c_state = MSP_IDLE;
    mspPorts[idx]->mspProcessCommandFn = mspProcessCommandFn;

    /* create msp server if it's not created before */
    if (mspThread == NULL) {
        mspThread = rt_thread_create("msp", msp_server_main, RT_NULL, 8192, 5, 1);
        RT_ASSERT(mspThread != NULL);
        console_printf("MSP server created\n");
    }

    return mspPorts[idx];
}

fmt_err msp_server_start(void)
{
    if (mspThread) {
        if (rt_thread_startup(mspThread) != RT_EOK) {
            return FMT_ERROR;
        }
        console_printf("MSP server started\n");
    }

    return FMT_EOK;
}