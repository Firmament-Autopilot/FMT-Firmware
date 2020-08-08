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
#include "fmu_manager.h"
#include "led.h"
#include "lidar_lite.h"
#include "ppm_decoder.h"
#include "protocol.h"
#include "pwm.h"
#include "sbus.h"
#include "time.h"
#include "usart.h"
#include <stdio.h>

/* io rx pkg */
static uint8_t _rx_pkg_buff[MAX_PACKAGE_SIZE];
static PackageStruct _rx_pkg = {
    .content = _rx_pkg_buff
};

int main(void)
{
    uint8_t ch;
    uint32_t time_led, time_sync;
    uint32_t now;
    LED_Type led_type;

    usart_init();
    pwm_init();
    time_init();
    ppm_decoder_init();
    sbus_init();
    led_init();
#ifdef USE_LIDAR
    lidar_lite_init();
#endif
    debug_init();

    led_on(LED_BLUE);
    led_on(LED_RED);

    while (1) {
        if (read_ch(&ch)) {
            if (proto_parse_package(ch, &_rx_pkg) == SYS_EOK) {
                handle_fmu_package(&_rx_pkg);
            }
        }

        if (fmt_sync_finish()) {
            led_type = LED_BLUE;
            led_on(LED_RED);

            //send_sbus_value();

            if (ppm_ready()) {
                send_ppm_value();
            }
        } else {
            led_type = LED_RED;
            led_on(LED_BLUE);

            /* try send sync cmd to fmu */
            TIMETAG_CHECK_EXECUTE(fmu_sync, 200, fmt_send_message(PROTO_CMD_SYNC, NULL, 0);)
        }

        TIMETAG_CHECK_EXECUTE(led_toggle, 1000, led_toggle(led_type);)
    }
}
