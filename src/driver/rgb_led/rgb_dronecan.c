/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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
#include "driver/rgb_led/rgb_dronecan.h"

#include "module/dronecan/dronecan.h"
#include "uavcan.equipment.indication.LightsCommand.h"

#define LED_CURRENT 0xff

extern CanardInstance g_canard;
static rt_device_t can_dev;

static uint8_t r;
static uint8_t g;
static uint8_t b;

static void makeLightsRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    static struct uavcan_equipment_indication_LightsCommand LightsCommand_msg;
    static uint8_t buffer[UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_MAX_SIZE];

    LightsCommand_msg.commands.len = 1;
    LightsCommand_msg.commands.data[0].color.red = red >> 3;
    LightsCommand_msg.commands.data[0].color.green = (green << 1) >> 3;
    LightsCommand_msg.commands.data[0].color.blue = blue >> 3;

    uint32_t total_size = uavcan_equipment_indication_LightsCommand_encode(&LightsCommand_msg, buffer);

    static uint8_t transfer_id; // Note that the transfer ID variable MUST BE STATIC (or heap-allocated)!

    canardBroadcast(&g_canard,
                    UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_SIGNATURE,
                    UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_ID,
                    &transfer_id,
                    CANARD_TRANSFER_PRIORITY_MEDIUM,
                    buffer,
                    (int16_t)total_size);
}

static rt_err_t droencan_control(rt_device_t dev, int cmd, void* args)
{
    uint8_t color;

    switch (cmd) {
    case DRONECAN_CMD_SET_COLOR:
        color = (uint32_t)args;
        if (color == DRONECAN_LED_RED) {
            r = LED_CURRENT;
            g = 0;
            b = 0;
        } else if (color == DRONECAN_LED_GREEN) {
            r = 0;
            g = LED_CURRENT;
            b = 0;
        } else if (color == DRONECAN_LED_BLUE) {
            r = 0;
            g = 0;
            b = LED_CURRENT;
        } else if (color == DRONECAN_LED_YELLOW) {
            r = LED_CURRENT;
            g = LED_CURRENT;
            b = 0;
        } else if (color == DRONECAN_LED_PURPLE) {
            r = LED_CURRENT;
            g = 0;
            b = LED_CURRENT;
        } else if (color == DRONECAN_LED_CYAN) {
            r = 0;
            g = LED_CURRENT;
            b = LED_CURRENT;
        } else if (color == DRONECAN_LED_WHITE) {
            r = LED_CURRENT;
            g = LED_CURRENT;
            b = LED_CURRENT;
        } else {
            /* unknown color, just close rgd leds */
            r = 0;
            g = 0;
            b = 0;
        }
        makeLightsRGB(r, g, b);
        break;

    case DRONECAN_CMD_SET_BRIGHT:

        break;

    default:
        return RT_EINVAL;
    }

    return RT_EOK;
}

rt_err_t drv_rgb_dronecan_init(const char* can_dev_name)
{
    static struct rt_device rgb_can_dev;

    can_dev = rt_device_find(can_dev_name);
    RT_ASSERT(can_dev != NULL);

    RT_CHECK(rt_device_open(can_dev, RT_DEVICE_OFLAG_RDWR));

    rgb_can_dev.type = RT_Device_Class_Char;
    rgb_can_dev.rx_indicate = RT_NULL;
    rgb_can_dev.tx_complete = RT_NULL;
    rgb_can_dev.user_data = RT_NULL;

    rgb_can_dev.init = RT_NULL;
    rgb_can_dev.open = RT_NULL;
    rgb_can_dev.close = RT_NULL;
    rgb_can_dev.read = RT_NULL;
    rgb_can_dev.write = RT_NULL;
    rgb_can_dev.control = droencan_control;

    RT_CHECK(rt_device_register(&rgb_can_dev, "can_rgb", RT_DEVICE_OFLAG_RDWR));

    return RT_EOK;
}
