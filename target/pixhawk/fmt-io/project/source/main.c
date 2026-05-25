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

#include "board_config.h"
#include "debug.h"
#include "heat.h"
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

int main(void)
{
    uint8_t ch;
    uint32_t time_led, time_sync;
    uint32_t now;
    LED_Type led_type;
    int prev_led = -1;

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

    /* ensure leds are off at start; logic will control them */
    led_off(LED_BLUE);
    led_off(LED_RED);

    while (1) {
        interface_listen();

        if (sync_finish()) {
            /* Normal: blue blinking, red off */
            led_type = LED_BLUE;
            /* only update outputs when state changes */
            if (prev_led != led_type) {
                led_off(LED_RED);
                led_on(LED_BLUE);
                prev_led = led_type;
            }

            if (rc_config.protocol == 1) {
                send_sbus_value();
            } else if (rc_config.protocol == 2) {
                send_ppm_value();
            }
        } else {
            /* Fault: red steady, blue off */
            led_type = LED_RED;
            /* only update outputs when state changes */
            if (prev_led != led_type) {
                led_on(LED_RED);
                led_off(LED_BLUE);
                prev_led = led_type;
            }

            /* try send sync cmd to fmu */
            PERIOD_EXECUTE(fmu_sync, 200, send_io_cmd(IO_CODE_SYNC, NULL, 0);)
        }

        /* Only toggle blue when in normal state */
        PERIOD_EXECUTE(led_toggle, 1000, if (led_type == LED_BLUE) led_toggle(LED_BLUE);)
    }
}
