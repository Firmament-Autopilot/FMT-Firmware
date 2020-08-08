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
#include <stdarg.h>
#include <stdio.h>

#define DEBUG_BUFFER_SIZE 100

static char _dbg_buf[DEBUG_BUFFER_SIZE];
static PackageStruct _dbg_pkg;

int debug(const char* fmt, ...)
{
    va_list args;
    int length;

    // TODO, current not support %f
    va_start(args, fmt);
    //length = vsprintf(_dbg_buf, fmt, args);
    length = vsnprintf(_dbg_buf, DEBUG_BUFFER_SIZE, fmt, args);
    va_end(args);

    /* send dbg info to FMU */
    if (length <= DEBUG_BUFFER_SIZE && length) {
        fmt_send_pkg(_dbg_buf, length, &_dbg_pkg);
    }

    return length;
}

void debug_init(void)
{
    // fmt_create_pkg(PROTO_DBG_TEXT, DEBUG_BUFFER_SIZE, _dbg_buf, &_dbg_pkg);
    fmt_init_pkg(PROTO_DBG_TEXT, _dbg_buf, &_dbg_pkg);
}
