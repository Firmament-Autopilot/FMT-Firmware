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

uint8_t err_motor_idx = 0;

int cmd_test(int argc, char** argv)
{
    /* add your test code here */
    err_motor_idx = math_hex2dec(argv[1]);
    printf("err_motor_idx:%x\n", err_motor_idx);

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_test, __cmd_test, user test command);