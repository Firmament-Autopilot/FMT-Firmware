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

#include "hal/serial/serial.h"
#include "module/sensor/sensor_hub.h"
#include "protocol/msp/msp.h"

// TBD
#define OPFLOW_SQUAL_THRESHOLD_HIGH 90
#define OPFLOW_SQUAL_THRESHOLD_LOW  50

typedef struct __attribute__((packed)) {
    uint8_t quality;    // [0;255]
    int32_t distanceMm; // Negative value for out of range
} mspRangefinderSensor_t;

typedef struct __attribute__((packed)) {
    uint8_t quality; // [0;255]
    int32_t motionX;
    int32_t motionY;
} mspOpflowSensor_t;

// MCN_DEFINE(sensor_optflow, sizeof(optflow_data_t));
// MCN_DEFINE(sensor_rangefinder, sizeof(rf_data_t));

MCN_DECLARE(sensor_optflow);
MCN_DECLARE(sensor_rangefinder);

static rf_data_t rangefinder_report = { .timestamp_ms = 0, .distance_m = -1.0f };
static optflow_data_t optflow_report = { 0 };

static int sensor_opt_flow_echo(void* param)
{
    fmt_err_t err;
    optflow_data_t optflow_report;

    err = mcn_copy_from_hub((McnHub*)param, &optflow_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("timestamp:%-8d vx:%.2f vy:%.2f valid:%d\n", optflow_report.timestamp_ms, optflow_report.vx_mPs, optflow_report.vy_mPs, optflow_report.valid);

    return 0;
}

static int sensor_rangefinder_echo(void* param)
{
    fmt_err_t err;
    rf_data_t rangefinder_report;

    err = mcn_copy_from_hub((McnHub*)param, &rangefinder_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("timestamp:%-8d distance:%.3f\n", rangefinder_report.timestamp_ms, rangefinder_report.distance_m);

    return 0;
}

static mspResult_e mspFcProcessCommand(mspPacket_t* cmd, mspPacket_t* reply)
{
    const uint16_t cmdMSP = cmd->cmd;

    if (MSP2_IS_SENSOR_MESSAGE(cmdMSP)) {
        switch (cmdMSP) {
        case MSP2_SENSOR_RANGEFINDER: {
            const mspRangefinderSensor_t* pkt = (const mspRangefinderSensor_t*)cmd->buf;

            rangefinder_report.timestamp_ms = systime_now_ms();
            rangefinder_report.distance_m = pkt->distanceMm > 0 ? (float)pkt->distanceMm * 0.001f : -1.0f;

            mcn_publish(MCN_HUB(sensor_rangefinder), &rangefinder_report);

        } break;

        case MSP2_SENSOR_OPTIC_FLOW: {
            const mspOpflowSensor_t* pkt = (const mspOpflowSensor_t*)cmd->buf;

            optflow_report.timestamp_ms = systime_now_ms();
            /* rotate to Body frame */
            optflow_report.vx_mPs = (float)(pkt->motionY * -0.01f);
            optflow_report.vy_mPs = (float)(pkt->motionX * 0.01f);
            /* opt flow valid only if rangefinder valid and opt flow's quality is okay */
            if (rangefinder_report.distance_m > 0.0f) {
                if (pkt->quality >= OPFLOW_SQUAL_THRESHOLD_HIGH) {
                    optflow_report.valid = 1;
                }
                if (pkt->quality <= OPFLOW_SQUAL_THRESHOLD_LOW) {
                    optflow_report.valid = 0;
                }
            } else {
                optflow_report.valid = 0;
            }

            mcn_publish(MCN_HUB(sensor_optflow), &optflow_report);
        } break;

        default:
            break;
        }
    }

    return MSP_RESULT_NO_REPLY;
}

rt_err_t pmw3901_l0x_drv_init(const char* serial_dev_name)
{
    rt_device_t dev = rt_device_find(serial_dev_name);

    if (dev == NULL) {
        return RT_ERROR;
    }

    if (msp_register(dev, mspFcProcessCommand) == NULL) {
        return RT_ERROR;
    }

    // mcn_advertise(MCN_HUB(sensor_optflow), sensor_opt_flow_echo);
    // mcn_advertise(MCN_HUB(sensor_rangefinder), sensor_rangefinder_echo);

    return RT_EOK;
}