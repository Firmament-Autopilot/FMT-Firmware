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

#include "debug.h"
#include "interface.h"
#include "led.h"
#include "lidar_lite.h"
#include "ppm_decoder.h"
#include "protocol.h"
#include "pwm.h"
#include "sbus.h"
#include "time.h"
#include "usart.h"
#include <stdio.h>
#include "board_config.h"
#include "heat.h"
int main(void)
{
    uint8_t ch;
    uint32_t time_led, time_sync;
    uint32_t now;
    LED_Type led_type;

    usart_init();

    interface_init();

    pwm_init();
    time_init();

    if (rc_config.protocol == 1) {
        sbus_init();
    } else if (rc_config.protocol == 2) {
        ppm_decoder_init();
    }

    led_init();
#ifdef USE_LIDAR
    lidar_lite_init();
#endif

#ifdef USE_IMU_HEAT
    heat_init();
#endif

    led_on(LED_BLUE);
    led_on(LED_RED);

    while (1) {
        interface_listen();

        if (sync_finish()) {
            led_type = LED_BLUE;
            led_on(LED_RED);

            if (rc_config.protocol == 1) {
                send_sbus_value();
            } else if (rc_config.protocol == 2) {
                send_ppm_value();
            }
        } else {
            led_type = LED_RED;
            led_on(LED_BLUE);

            /* try send sync cmd to fmu */
            PERIOD_EXECUTE(fmu_sync, 200, send_io_cmd(IO_CODE_SYNC, NULL, 0);)
        }

        PERIOD_EXECUTE(led_toggle, 1000, led_toggle(led_type);)
    }
}
