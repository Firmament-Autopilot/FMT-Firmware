/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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

#include "protocol/nmea/nmea.h"
#include <string.h>

nmea_decoder_t decoder;

int nmea_rx_handle(uint16_t msg_id)
{
    printf("id:%d\n", msg_id);

    return 0;
}

int cmd_test(int argc, char** argv)
{
    /* add your test code here */
    // int parse_nmea_sentence(const char* sentence);

    // parse_nmea_sentence("$KSXT,20190909084745.00,116.23662400,40.07897925,68.3830,299.22,-67.03,190.28,0.022,,1,3,46,28,,,,-0.004,-0.021,-0.020,,*27");

    init_nmea_decoder(&decoder, (rt_device_t)1, nmea_rx_handle);

    char nmea_str[] = "$KSXT,20250930073655.00,113.02365270,28.14124270,66.6339,299.14,40.52,72.01,0.321,0.00,1,2,8,21,,,,0.305,0.099,0.125,,*3B";
    // char nmea_str[] = "$GPGGA,092725.00,4717.11399,N,00833.91590,E,1,08,1.01,499.6,M,48.0,M,,*5b";

    for (int i = 0; i < strlen(nmea_str); i++) {
        parse_nmea_char(&decoder, nmea_str[i]);
    }

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_test, __cmd_test, user test command);