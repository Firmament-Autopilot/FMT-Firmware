/******************************************************************************
 * Copyright 2023 The Firmament Authors. All Rights Reserved.
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
#include <string.h>

#include "module/syscmd/optparse.h"
#include "module/syscmd/syscmd.h"

int cmd_delay(int argc, char** argv)
{
    int res = EXIT_SUCCESS;

    if (argc < 2) {
        printf("usage: delay <ms>\n");
        return EXIT_FAILURE;
    }

    systime_mdelay(atoi(argv[1]));

    return res;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_delay, __cmd_delay, Delay for a period of time (ms).);
