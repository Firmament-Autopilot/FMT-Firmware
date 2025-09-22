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

int cmd_test(int argc, char** argv)
{
    /* add your test code here */
    int parse_nmea_sentence(const char* sentence);

    parse_nmea_sentence("$GNRMC,092721.00,A,2926.688113,N,11127.771644,E,0.780,,200520,,,D,V*1D");

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_test, __cmd_test, user test command);