/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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

#include "module/file_manager/file_manager.h"

#define BOOT_LOG_BUFFER_SIZE 4096

static char* log_buffer = NULL;
static uint32_t buffer_index;
static uint8_t boot_logging = 0;

/**
 * Reimplement the console write hook function.
 */
void console_write_hook(const char* content, uint32_t len)
{
    if (boot_logging) {
        boot_log_push(content, len);
    }
}

/**
 * Push content into boot log buffer.
 * 
 * @return the length of data have been written.
 */
uint32_t boot_log_push(const char* content, uint32_t len)
{
    uint32_t len_to_end = BOOT_LOG_BUFFER_SIZE - buffer_index;
    uint32_t len_to_write;

    len_to_write = len_to_end < len ? len_to_end : len;

    if (len_to_write > 0) {
        memcpy(&log_buffer[buffer_index], content, len_to_write);
        buffer_index += len_to_write;
    }

    return len_to_write;
}

/**
 * Dump boot log from buffer into file.
 * 
 * @return FMT Errors.
 */
fmt_err_t boot_log_dump(void)
{
    char file[100];
    int fd;
    fmt_err_t res = FMT_EOK;

    RT_ASSERT(log_buffer != NULL);

    /* clear boot logging flag */
    boot_logging = 0;
    /* get full path of the boot log file */
    current_log_session(file);
    strcat(file, "/boot_log.txt");
    /* create boot log file */
    fd = open(file, O_CREAT | O_WRONLY | O_TRUNC);
    if (fd < 0) {
        console_printf("fail to create boot log file: %s, errno:%ld\n", file, rt_get_errno());
        res = FMT_ERROR;
    }
    /* dump boot log buffer if there are any */
    if (buffer_index > 0) {
        int wb = write(fd, log_buffer, buffer_index);

        if (wb != buffer_index) {
            console_printf("dump boot log fail\n");
            res = FMT_ERROR;
        }

        close(fd);
    }
    /* release buffer */
    rt_free(log_buffer);
    log_buffer = NULL;

    return res;
}

/**
 * Initialize boot log module.
 * 
 * @return FMT Errors.
 */
fmt_err_t boot_log_init(void)
{
    RT_ASSERT(log_buffer == NULL);

    /* malloc boot log buffer */
    log_buffer = (char*)rt_malloc(BOOT_LOG_BUFFER_SIZE);
    if (log_buffer == NULL) {
        return FMT_ERROR;
    }
    /* reset buffer index */
    buffer_index = 0;
    /* set boot logging flag */
    boot_logging = 1;

    return FMT_EOK;
}