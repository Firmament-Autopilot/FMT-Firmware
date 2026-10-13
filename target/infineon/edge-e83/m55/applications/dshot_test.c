/******************************************************************************
 * Copyright 2026 The Firmament Authors. All Rights Reserved.
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

#include "FMS.h"
#include "hal/actuator/actuator.h"
#include "module/syscmd/syscmd.h"

#define DSHOT_TEST_CHANNELS    4U
#define DSHOT_TEST_MASK        0x0FU
#define DSHOT_TEST_STOP        1000U
#define DSHOT_TEST_INTERVAL_MS 2U
#define DSHOT_TEST_INIT_MS     2000U
#define DSHOT_TEST_DEFAULT_MS  3000U
#define DSHOT_TEST_MAX_MS      30000U
#define DSHOT_TEST_STOP_FRAMES 50U

MCN_DECLARE(control_output);
MCN_DECLARE(fms_output);

static void dshot_test_usage(void)
{
    console_printf("usage: dshot_test <channel 1-4> <value 1000-2000> [duration_ms 1-30000]\n");
    console_printf("aux_out DShot300; 1000=STOP, 1001-2000=throttle. Default duration: 3000 ms.\n");
    console_printf("Sends STOP for 2000 ms first; press any key to stop. Remove all propellers.\n");
}

static bool dshot_test_parse(const char* arg, unsigned min, unsigned max, unsigned* result)
{
    unsigned value = 0;

    if (*arg == '\0') {
        return false;
    }
    while (*arg != '\0') {
        if (*arg < '0' || *arg > '9') {
            return false;
        }
        value = value * 10U + (unsigned)(*arg++ - '0');
        if (value > max) {
            return false;
        }
    }
    if (value < min) {
        return false;
    }
    *result = value;
    return true;
}

static bool dshot_test_disarmed(void)
{
    FMS_Out_Bus fms_out;

    if (mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out) != FMT_EOK) {
        console_printf("dshot_test: failed to read FMS status; stopping.\n");
        return false;
    }
    if (fms_out.status != VehicleStatus_Disarm) {
        console_printf("dshot_test: vehicle must stay Disarm; stopping.\n");
        return false;
    }
    return true;
}

static int dshot_test_run(rt_device_t dev, const uint16_t values[DSHOT_TEST_CHANNELS], unsigned duration_ms, bool* cancelled)
{
    uint32_t start_ms = systime_now_ms();

    do {
        if (syscmd_has_input()) {
            syscmd_flush();
            *cancelled = true;
            return EXIT_SUCCESS;
        }
        if (!dshot_test_disarmed()) {
            return EXIT_FAILURE;
        }
        if (rt_device_write(dev, DSHOT_TEST_MASK, values, DSHOT_TEST_CHANNELS) != DSHOT_TEST_CHANNELS) {
            console_printf("dshot_test: aux_out write failed.\n");
            return EXIT_FAILURE;
        }
        systime_msleep(DSHOT_TEST_INTERVAL_MS);
    } while ((uint32_t)(systime_now_ms() - start_ms) < duration_ms);

    return EXIT_SUCCESS;
}

static int dshot_test(int argc, char** argv)
{
    unsigned channel;
    unsigned value;
    unsigned duration_ms = DSHOT_TEST_DEFAULT_MS;
    uint16_t values[DSHOT_TEST_CHANNELS] = { DSHOT_TEST_STOP, DSHOT_TEST_STOP, DSHOT_TEST_STOP, DSHOT_TEST_STOP };
    const uint16_t stop[DSHOT_TEST_CHANNELS] = { DSHOT_TEST_STOP, DSHOT_TEST_STOP, DSHOT_TEST_STOP, DSHOT_TEST_STOP };
    bool cancelled = false;
    unsigned stop_failures = 0;
    int result;

    if (argc == 2 && (STRING_COMPARE(argv[1], "-h") || STRING_COMPARE(argv[1], "--help"))) {
        dshot_test_usage();
        return EXIT_SUCCESS;
    }
    if (argc < 3 || argc > 4
        || !dshot_test_parse(argv[1], 1U, DSHOT_TEST_CHANNELS, &channel)
        || !dshot_test_parse(argv[2], DSHOT_TEST_STOP, 2000U, &value)
        || (argc == 4 && !dshot_test_parse(argv[3], 1U, DSHOT_TEST_MAX_MS, &duration_ms))) {
        dshot_test_usage();
        return EXIT_FAILURE;
    }

    rt_device_t dev = rt_device_find("aux_out");
    if (dev == NULL) {
        console_printf("dshot_test: aux_out not found.\n");
        return EXIT_FAILURE;
    }
    actuator_dev_t act = (actuator_dev_t)dev;
    if (act->config.protocol != ACT_PROTOCOL_DSHOT || act->config.dshot_config.speed != 300U
        || act->config.dshot_config.telem_req) {
        console_printf("dshot_test: configure aux_out for DShot300 with telem-req=false, then reboot.\n");
        return EXIT_FAILURE;
    }
    if ((act->chan_mask & DSHOT_TEST_MASK) != DSHOT_TEST_MASK || act->config.chan_num < DSHOT_TEST_CHANNELS) {
        console_printf("dshot_test: aux_out channels 1-4 are unavailable.\n");
        return EXIT_FAILURE;
    }
    if (!(dev->flag & RT_DEVICE_FLAG_ACTIVATED) || dev->ref_count == 0 || act->suspend) {
        console_printf("dshot_test: aux_out must be initialized, opened and active by system startup.\n");
        return EXIT_FAILURE;
    }
    if (!dshot_test_disarmed()) {
        return EXIT_FAILURE;
    }

    /* Do not take over a topic already held by another test or command. */
    rt_enter_critical();
    if (MCN_HUB(control_output)->suspend) {
        rt_exit_critical();
        console_printf("dshot_test: control_output is already suspended.\n");
        return EXIT_FAILURE;
    }
    mcn_suspend(MCN_HUB(control_output));
    rt_exit_critical();

    syscmd_flush();
    console_printf("dshot_test: REMOVE PROPELLERS. aux_out channel %u, value %u, duration %u ms.\n",
                   channel,
                   value,
                   duration_ms);
    console_printf("Sending all-channel STOP for 2000 ms; press any key to stop.\n");
    result = dshot_test_run(dev, stop, DSHOT_TEST_INIT_MS, &cancelled);
    if (result == EXIT_SUCCESS && !cancelled) {
        values[channel - 1U] = (uint16_t)value;
        console_printf("Testing channel %u; other channels remain STOP.\n", channel);
        result = dshot_test_run(dev, values, duration_ms, &cancelled);
    }

    /* Attempt every STOP frame even when an earlier write failed. */
    for (unsigned i = 0; i < DSHOT_TEST_STOP_FRAMES; i++) {
        if (rt_device_write(dev, DSHOT_TEST_MASK, stop, DSHOT_TEST_CHANNELS) != DSHOT_TEST_CHANNELS) {
            stop_failures++;
        }
        systime_msleep(DSHOT_TEST_INTERVAL_MS);
    }
    mcn_resume(MCN_HUB(control_output));

    if (stop_failures != 0U) {
        console_printf("dshot_test: %u/%u final STOP writes failed; check ESC power and output.\n",
                       stop_failures,
                       DSHOT_TEST_STOP_FRAMES);
        result = EXIT_FAILURE;
    }
    console_printf("dshot_test: %s; control_output resumed.\n",
                   result != EXIT_SUCCESS ? "FAILED" : (cancelled ? "cancelled, STOP sent" : "complete, STOP sent"));
    return result;
}
MSH_CMD_EXPORT(dshot_test, timed DShot300 bench test on aux_out);
