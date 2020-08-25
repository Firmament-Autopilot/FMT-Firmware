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

#include <firmament.h>

#include "module/fs_manager/fs_manager.h"

#define BOOT_LOG_FILE        "/log/boot_log.txt"
#define BOOT_LOG_BUFFER_SIZE 4096

static char* _buffer_ptr = NULL;
static uint32_t _index;

uint32_t boot_log_printf(const char* fmt, ...)
{
    RT_ASSERT(_buffer_ptr != NULL);

    va_list args;
    int length;

    if (_index >= BOOT_LOG_BUFFER_SIZE) {
        console_printf("boot log buffer full\n");
        return 0;
    }

    va_start(args, fmt);
    length = vsnprintf(&_buffer_ptr[_index], BOOT_LOG_BUFFER_SIZE - _index, fmt, args);
    va_end(args);

    console_write(&_buffer_ptr[_index], length);

    _index += length;

    return length;
}

fmt_err boot_log_dump(void)
{
    RT_ASSERT(_buffer_ptr != NULL);

    int fd;
    fmt_err res = FMT_EOK;

    fd = open(BOOT_LOG_FILE, O_CREAT | O_WRONLY | O_TRUNC);

    if (fd < 0) {
        console_printf("fail to create boot log file: %s\n", BOOT_LOG_FILE);
        res = FMT_ERROR;
    }

    /* dump boot log buffer */
    if (_index && fd >= 0) {
        int wb = write(fd, _buffer_ptr, _index);

        if (wb != _index) {
            console_printf("dump boot log fail\n");
            res = FMT_ERROR;
        }

        close(fd);
    }

    /* release buffer */
    rt_free(_buffer_ptr);
    _buffer_ptr = NULL;

    return res;
}

fmt_err boot_log_init(void)
{
    RT_ASSERT(_buffer_ptr == NULL);

    _buffer_ptr = (char*)rt_malloc(BOOT_LOG_BUFFER_SIZE);

    if (_buffer_ptr == NULL) {
        return FMT_ERROR;
    }

    _index = 0; // buffer index

    return FMT_EOK;
}