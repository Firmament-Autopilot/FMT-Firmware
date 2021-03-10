/******************************************************************************
 * Copyright 2020-2021 The Firmament-Autopilot Authors. All Rights Reserved.
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
#include <dfs_posix.h>

int fm_fprintf(int fd, const char* fmt, ...)
{
    va_list args;
    int length;
    char buffer[256];

    va_start(args, fmt);
    length = vsprintf(buffer, fmt, args);
    va_end(args);

    return write(fd, buffer, length);
}