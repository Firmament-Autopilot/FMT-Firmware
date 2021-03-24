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
#include <string.h>

#include "module/file_manager/file_manager.h"
#include "task/task_logger.h"

#define TAG "Logger"

#define ULOG_FILE_NAME      "ulog.txt"

static struct rt_event _log_event;

#ifdef ENABLE_ULOG_CONSOLE_BACKEND
static void ulog_console_backend_output(struct ulog_backend* backend, rt_uint32_t level, const char* tag, rt_bool_t is_raw,
    const char* log, size_t len)
{
    console_write(log, len);
}
#endif /* ENABLE_ULOG_CONSOLE_BACKEND */

#ifdef ENABLE_ULOG_FS_BACKEND
static int _ulog_fd = -1;
static void ulog_fs_backend_init(struct ulog_backend* backend)
{
    char file_name[50];
    char log_session[50];

    if (current_log_session(log_session) == FMT_EOK) {
        sprintf(file_name, "%s/%s", log_session, ULOG_FILE_NAME);

        _ulog_fd = open(file_name, O_CREAT | O_WRONLY);

        if (_ulog_fd < 0) {
            console_printf("ulog fs backend init fail\n");
        }
    }
}

static void ulog_fs_backend_output(struct ulog_backend* backend, rt_uint32_t level, const char* tag, rt_bool_t is_raw,
    const char* log, size_t len)
{
    if (_ulog_fd >= 0) {
        write(_ulog_fd, log, len);
    }
}

static void ulog_fs_backend_deinit(struct ulog_backend* backend)
{
    if (_ulog_fd >= 0) {
        close(_ulog_fd);
        _ulog_fd = -1;
    }
}
#endif /* ENABLE_ULOG_FS_BACKEND */

static void blog_update_cb(void)
{
    rt_event_send(&_log_event, EVENT_BLOG_UPDATE);
}

static void ulog_update_cb(void)
{
    rt_event_send(&_log_event, EVENT_ULOG_UPDATE);
}

fmt_err logger_start_blog(char* path)
{
    char log_name[100];
    char file_name[50];
    static uint8_t blog_id = 0;

    if (path) {
        /* if a valid path is provided, use it for blog */
        return blog_start(path);
    }

    if (current_log_session(log_name) != FMT_EOK) {
        console_printf("no available log session\n");
        return FMT_ERROR;
    }
    sprintf(file_name, "/blog%d.bin", ++blog_id);
    strcat(log_name, file_name);

    return blog_start(log_name);
}

void logger_stop_blog(void)
{
    blog_stop();
}

fmt_err task_logger_init(void)
{
    /* create log event */
    if (rt_event_init(&_log_event, "logger", RT_IPC_FLAG_FIFO) != RT_EOK) {
        console_printf("log event create fail\n");
        return FMT_ERROR;
    }

    /* init binary log */
    binary_log_init();

    /* init ulog */
    ulog_init();

#ifdef ENABLE_ULOG_CONSOLE_BACKEND
    static struct ulog_backend console;
    /* register ulog console backend */
    console.output = ulog_console_backend_output;
    ulog_backend_register(&console, "console", RT_FALSE);
#endif

#ifdef ENABLE_ULOG_FS_BACKEND
    static struct ulog_backend fs;
    /* register ulog filesystem backend */
    fs.init = ulog_fs_backend_init;
    fs.output = ulog_fs_backend_output;
    fs.deinit = ulog_fs_backend_deinit;
    ulog_backend_register(&fs, "filesystem", RT_FALSE);
#endif

    if (PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 2 || PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 3) {
        logger_start_blog(NULL);
    }

    return FMT_EOK;
}

void task_logger_entry(void* parameter)
{
    rt_err_t rt_err;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_BLOG_UPDATE | EVENT_ULOG_UPDATE;

    blog_register_callback(BLOG_CB_UPDATE, blog_update_cb);
    ulog_register_callback(ulog_update_cb);

    while (1) {
        /* wait event happen */
        rt_err = rt_event_recv(&_log_event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            20, &recv_set);

        if (rt_err == RT_EOK) {
            if (recv_set & EVENT_BLOG_UPDATE) {
                blog_async_output();
            }

            if (recv_set & EVENT_ULOG_UPDATE) {
                ulog_async_output();
            }
        } else if (rt_err == -RT_ETIMEOUT) {
            /* if timeout, check if there are log data need to send */
            blog_async_output();
            ulog_async_output();

#ifdef ENABLE_ULOG_FS_BACKEND
            fsync(_ulog_fd);
#endif
        } else {
            /* some other error happen */
        }
    }
}
