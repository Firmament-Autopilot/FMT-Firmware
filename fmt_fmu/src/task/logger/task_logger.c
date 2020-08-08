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

#include "task/task_logger.h"
#include "module/fs_manager/fs_manager.h"

#define TAG                             "Logger"

#define MAX_LOG_SESSION_NUM             10
#define LOG_SESSION_FOLDER              "/log"
#define LOG_SESSION_ID_FILE             "session_id.txt"
#define ULOG_FILE_NAME                  "ulog.txt"
// #define BLOG_FILE_NAME                  "blog.bin"

static struct rt_event _log_event;
static int _ulog_fd = -1;
static uint16_t _log_session_id = 0;

static fmt_err _get_log_session(char* session);

/**************************** Callback Function ********************************/

static void ulog_console_backend_output(struct ulog_backend* backend, rt_uint32_t level, const char* tag, rt_bool_t is_raw,
                                        const char* log, size_t len)
{
	console_write(log, len);
}

static void ulog_fs_backend_init(struct ulog_backend* backend)
{
	char file_name[50];
	char log_session[50];

	if(_get_log_session(log_session) == FMT_EOK) {
		sprintf(file_name, "%s/%s", log_session, ULOG_FILE_NAME);

		_ulog_fd = open(file_name, O_CREAT | O_WRONLY);

		if(_ulog_fd < 0) {
			console_printf("ulog fs backend init fail\n");
		}
	}
}

static void ulog_fs_backend_output(struct ulog_backend* backend, rt_uint32_t level, const char* tag, rt_bool_t is_raw,
                                   const char* log, size_t len)
{
	if(_ulog_fd >= 0) {
		write(_ulog_fd, log, len);
	}
}

static void ulog_fs_backend_deinit(struct ulog_backend* backend)
{
	if(_ulog_fd >= 0) {
		close(_ulog_fd);
		_ulog_fd = -1;
	}
}

/**************************** Local Function ********************************/

static fmt_err _create_log_session(void)
{
	char session_name[50];

	if(_get_log_session(session_name) != FMT_EOK) {
		return FMT_ERROR;
	}

	// if exist, delete it first
	if(fs_file_exist(session_name)) {
		if(fs_deldir(session_name) != FMT_EOK) {
			console_printf("fail to delete %s\n", session_name);
			return FMT_ERROR;
		}
	}

	// create log session
	if(mkdir(session_name, 0x777) < 0) {
		console_printf("fail to create %s\n", session_name);
		return FMT_ERROR;
	}

	return FMT_EOK;
}

static fmt_err _get_log_session(char* session)
{
	if(_log_session_id == 0)    return FMT_ERROR;

	sprintf(session, "%s/session_%d", LOG_SESSION_FOLDER, _log_session_id);

	return FMT_EOK;
}

static uint16_t _update_log_session_id(bool create_new)
{
	int fd;
	uint16_t id = 0;
	char file_name[50];
	char id_buffer[6];

	sprintf(file_name, "%s/%s", LOG_SESSION_FOLDER, LOG_SESSION_ID_FILE);

	if(fs_file_exist(file_name)) {
		fd = open(file_name, O_WRONLY);

		if(fd < 0) {
			goto Out;
		}

		int rb = read(fd, id_buffer, 5);

		// check if is valid number
		for(uint8_t i = 0; i < rb; i++) {
			if(id_buffer[i] < '0' || id_buffer[i] > '9') {
				goto Out;
			}
		}

		id_buffer[rb] = '\0';
		id = atoi(id_buffer);
	} else if(create_new) {
		// create a new session id file
		fd = open(file_name, O_CREAT | O_WRONLY);

		if(fd < 0) {
			goto Out;
		}

		id = 0;

		console_printf("create session_id.txt\n");
	} else {
		id = 0;
		goto Out;
	}

	if(fd) close(fd);

	// update id
	id = id % MAX_LOG_SESSION_NUM;
	id++;

	sprintf(file_name, "%s/%s", LOG_SESSION_FOLDER, LOG_SESSION_ID_FILE);
	fd = open(file_name, O_TRUNC | O_WRONLY);

	if(fd < 0) {
		console_printf("fail to update log session id\n");
		id = 0;
		goto Out;
	}

	fs_fprintf(fd, "%d", id);

Out:

	if(fd) {
		close(fd);
	}

	return id;
}

/**************************** Public Function ********************************/

fmt_err logger_start_blog(char* path)
{
	char log_name[100];
	static uint8_t blog_id = 0;

	if(path) {
		/* if a valid path is provided, use it for blog */
		return blog_start(path);
	}

	if(_log_session_id == 0) {
		console_printf("no available log session\n");
		return FMT_ERROR;
	}

	sprintf(log_name, "%s/session_%d/blog%d.bin", LOG_SESSION_FOLDER, _log_session_id, ++blog_id);

	return blog_start(log_name);
}

void logger_stop_blog(void)
{
	blog_stop();
}

fmt_err logger_send_event(uint32_t event)
{
	if(rt_event_send(&_log_event, event) == RT_EOK) {
		return FMT_EOK;
	}

	return FMT_ERROR;
}

fmt_err task_logger_init(void)
{
	/* create log event */
	if(rt_event_init(&_log_event, "logger", RT_IPC_FLAG_FIFO) != RT_EOK) {
		console_printf("log event create fail\n");
		return FMT_ERROR;
	}

	/* init binary log */
	blog_init();

	/* init ulog */
	ulog_init();

	/* get log session id */
	_log_session_id = _update_log_session_id(true);

	if(_log_session_id == 0) {
		console_printf("fail to get log session id\n");
	} else {
		_create_log_session();
	}

	if(PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 2 || PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 3) {
		logger_start_blog(NULL);
	}

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

	return FMT_EOK;
}

void task_logger_entry(void* parameter)
{
	rt_err_t rt_err;
	rt_uint32_t recv_set = 0;
	rt_uint32_t wait_set = EVENT_BLOG_UPDATE | EVENT_ULOG_UPDATE;

	while(1) {
		/* wait event happen */
		rt_err = rt_event_recv(&_log_event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
		                       20, &recv_set);

		if(rt_err == RT_EOK) {
			if(recv_set & EVENT_BLOG_UPDATE) {
				blog_async_output();
			}

			if(recv_set & EVENT_ULOG_UPDATE) {
				ulog_async_output();
			}
		} else if(rt_err == -RT_ETIMEOUT) {
			/* if timeout, check if there are log data need to send */
			blog_async_output();
			ulog_async_output();

			if(_ulog_fd >= 0) {
				fsync(_ulog_fd);
			}
		} else {
			/* some other error happen */
		}
	}
}



