/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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

#include "module/pmu/power_manager.h"

MCN_DEFINE(bat_status, sizeof(struct battery_status));

static rt_device_t adc_dev;

static int echo_battery_status(void* parameter)
{
    struct battery_status bat_status;

    if (mcn_copy_from_hub((McnHub*)parameter, &bat_status) != FMT_EOK) {
        return -1;
    }

    console_printf("voltage:%5d mV, current:%5d mA, remaining:%3u%%\n",
                   bat_status.battery_voltage,
                   bat_status.battery_current,
                   bat_status.battery_remaining);

    return 0;
}

fmt_err_t pmu_poll_battery_status(void)
{
    struct battery_status bat_status;
    uint32_t value;

    if (adc_dev == NULL) {
        return FMT_EEMPTY;
    }

    if (rt_device_read(adc_dev, 0, &value, sizeof(value)) != sizeof(value)) {
        return FMT_ERROR;
    }
    bat_status.battery_voltage = value * PARAM_GET_FLOAT(CALIB, BAT_V_DIV); /* millivolt */

    if (rt_device_read(adc_dev, 1, &value, sizeof(value)) != sizeof(value)) {
        return FMT_ERROR;
    }
    bat_status.battery_current = value; /* millicurrent */
    bat_status.battery_remaining = 0;

    /* publish battery 0 status */
    if (mcn_publish(MCN_HUB(bat_status), &bat_status) != FMT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err_t pmu_init(void)
{
    FMT_CHECK(mcn_advertise(MCN_HUB(bat_status), echo_battery_status));

    adc_dev = rt_device_find("adc0");
    RT_ASSERT(adc_dev != NULL);

    RT_CHECK(rt_device_open(adc_dev, RT_DEVICE_FLAG_RDONLY));

    return FMT_EOK;
}
