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

#include "hal/adc/adc.h"
#include "module/log/mlog.h"
#include "module/pmu/battery.h"
#include "module/pmu/power_manager.h"

MCN_DEFINE(bat_status, sizeof(struct battery_status));

/* define parameters */
static param_t __param_list[] = {
    /* Battery Voltage Divider */
    PARAM_FLOAT(BAT_V_DIV, 1.0, false),
    /* Battery Current Ampere per Volt */
    PARAM_FLOAT(BAT_A_PER_V, 1.0, false),
    /* Battery Cells Number */
    PARAM_UINT8(BAT_N_CELLS, 0, false),
    /* Battery Capacity */
    PARAM_FLOAT(CAPACITY_OF_BAT, 3500.0, false),
    PARAM_FLOAT(VOLTAGE_EMPTY, 3.0, false),
    PARAM_FLOAT(VOLTAGE_CHARGED, 4.2, false),
    PARAM_FLOAT(R_INTERNAL_CONST, -0.005, false),
    PARAM_FLOAT(R_INTERNAL, 0.010, false),
    PARAM_FLOAT(LOW_THR, 3.5, false),
    PARAM_FLOAT(CRIT_THR, 3.4, false),
    PARAM_FLOAT(EMERGEN_THR, 3.3, false),
};
PARAM_GROUP_DEFINE(POWER, __param_list);

static mlog_elem_t Battery_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(voltage, MLOG_FLOAT),
    MLOG_ELEMENT(current, MLOG_FLOAT),
    MLOG_ELEMENT(remaining, MLOG_FLOAT),
    MLOG_ELEMENT(remaining_c, MLOG_FLOAT),
    MLOG_ELEMENT(remaining_v, MLOG_FLOAT),
    MLOG_ELEMENT(SOH, MLOG_FLOAT),
    MLOG_ELEMENT(initial, MLOG_UINT8),
    MLOG_ELEMENT(connected, MLOG_UINT8),
    MLOG_ELEMENT(reserved1, MLOG_UINT8),
    MLOG_ELEMENT(reserved2, MLOG_UINT8),
    MLOG_ELEMENT(uctimestamp, MLOG_UINT32),
    MLOG_ELEMENT(init_SOC, MLOG_FLOAT),
    MLOG_ELEMENT(resistance, MLOG_FLOAT),
    MLOG_ELEMENT(cvoltage, MLOG_FLOAT),
    MLOG_ELEMENT(cvoltage_orin, MLOG_FLOAT),
};
MLOG_BUS_DEFINE(BATTERY, Battery_Elems);

static rt_device_t adc_dev;
static Battery battery;
static battery_params_t battery_params = { 0 };
static uint32_t timestamps;
static int BATTERY_ID;

static int echo_battery_status(void* parameter)
{
    struct battery_status bat_status;

    if (mcn_copy_from_hub((McnHub*)parameter, &bat_status) != FMT_EOK) {
        return -1;
    }

    console_printf("Voltage: %3.3f mV, Current: %3.3f mA, Internal Resistance: %3.3f\n"
                   "Init SOC: %3.3f, Remaining: %3.3f%%, Remaining_C: %3.3f%%, Remaing_V: %3.3f%%\n"
                   "Cell Voltage: %3.3f, Cell Voltage Origin: %3.3f\n\n",
                   bat_status.battery_voltage,
                   bat_status.battery_current,
                   bat_status.internal_resistance,
                   bat_status.init_SOC,
                   bat_status.battery_remaining,
                   bat_status.remaining_c,
                   bat_status.remaining_v,
                   bat_status.cell_voltage,
                   bat_status.cell_voltage_origin);

    return 0;
}

fmt_err_t pmu_poll_battery_status(void)
{
    struct battery_status bat_status;
    uint32_t value;
    timestamps = systime_now_ms();

    if (adc_dev == NULL) {
        return FMT_EEMPTY;
    }

    battery.timestamp = timestamps;
    bat_status.timestamp = timestamps;
    bat_status.reserved1 = 0;
    bat_status.reserved2 = 0;

    if (rt_device_read(adc_dev, BAT1_V_CHANNEL, &value, sizeof(value)) == sizeof(value)) {
        bat_status.battery_voltage = value * PARAM_GET_FLOAT(POWER, BAT_V_DIV); /* mV */
        battery_update_voltage(&battery, bat_status.battery_voltage / 1000.0f);
    } else {
        bat_status.battery_voltage = 0;
    }

    if (rt_device_read(adc_dev, BAT1_I_CHANNEL, &value, sizeof(value)) == sizeof(value)) {
        bat_status.battery_current = value * PARAM_GET_FLOAT(POWER, BAT_A_PER_V); /* mA */
        battery_update_current(&battery, bat_status.battery_current / 1000.0f);
    } else {
        bat_status.battery_current = -1;
    }

    battery_update_state_of_charge(&battery, timestamps);

    bat_status.battery_remaining = battery.state_of_charge;
    bat_status.remaining_c = battery.state_of_charge_current_based;
    bat_status.remaining_v = battery.state_of_charge_volt_based;
    bat_status.state_of_health = battery.state_of_health;
    bat_status.battery_init = battery.battery_initialized;
    bat_status.last_unconnected_timestamp = battery.last_unconnected_timestamp;
    bat_status.connected = battery.connected;
    bat_status.init_SOC = battery.state_of_charge_init;
    bat_status.internal_resistance = battery.internal_resistance;
    bat_status.cell_voltage = battery.cell_voltage;
    bat_status.cell_voltage_origin = battery.cell_voltage_origin;

    /* publish battery 1 status */
    if (mcn_publish(MCN_HUB(bat_status), &bat_status) != FMT_EOK) {
        return FMT_ERROR;
    }

    if (mlog_push_msg((uint8_t*)&bat_status, BATTERY_ID, sizeof(bat_status)) != FMT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err_t pmu_init(void)
{
    FMT_CHECK(mcn_advertise(MCN_HUB(bat_status), echo_battery_status));

    adc_dev = rt_device_find("adc0");
    if (adc_dev != NULL) {
        if (rt_device_open(adc_dev, RT_DEVICE_FLAG_RDONLY) == RT_EOK) {
            BATTERY_ID = mlog_get_bus_id("BATTERY");
            timestamps = systime_now_ms();
            battery_init(&battery, &battery_params, 0, timestamps);
            return FMT_EOK;
        }
    }

    return FMT_ERROR;
}
