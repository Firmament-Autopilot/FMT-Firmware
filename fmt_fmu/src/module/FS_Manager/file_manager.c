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
#include <string.h>

#include "dfs_elm.h"
#include "dfs_fs.h"
#include "module/file_manager/file_manager.h"

#define MAX_LOG_SESSION_NUM 10
#define LOG_SESSION_FILE    "/log/session_id"

static int cws_id; /* current work session id */

static const struct dfs_mount_tbl mnt_table[] = {
    { "sd0", "/", "elm", 0, NULL }
};

static const char* rfs_folder[] = {
    "/sys",
    "/usr",
    "/log",
    NULL /* NULL indicate the end */
};

static int read_log_session_id(void)
{
    char id_buffer[5] = { 0 };
    struct stat sta;
    int id = -1;
    int fd;

    /* if file existed, read it */
    if (stat(LOG_SESSION_FILE, &sta) == 0) {
        int i;
        fd = open(LOG_SESSION_FILE, O_WRONLY);
        if (fd < 0) {
            return -1;
        }
        /* read session id from file */
        int rb = read(fd, id_buffer, sizeof(id_buffer) - 1);
        /* check if it's a valid number */
        for (i = 0; i < rb; i++) {
            /* session id starts from 1 */
            if (id_buffer[i] < '0' || id_buffer[i] > '9' || id_buffer[0] == '0') {
                /* illegal session id */
                close(fd);
                return -1;
            }
        }
        id = atoi(id_buffer);
    }
    close(fd);

    return id;
}

static fmt_err update_log_session(void)
{
    int fd;

    /* read current log session id */
    cws_id = read_log_session_id();
    if (cws_id < 0) {
        cws_id = 0;
    }

    /* increment session id */
    cws_id = (cws_id % MAX_LOG_SESSION_NUM) + 1;
    /* open or create the log session id file */
    fd = open(LOG_SESSION_FILE, O_TRUNC | O_CREAT | O_RDWR);
    if (fd < 0) {
        console_printf("fail to create log session id file! err:%d\n", rt_get_errno());
        return FMT_ERROR;
    }
    fm_fprintf(fd, "%d", cws_id);
    close(fd);

    return FMT_EOK;
}

/**
 * Create rootfs folders if not existed.
 * 
 * @return FMT Errors.
 */
static fmt_err create_rootfs(void)
{
    struct stat buf;
    int i = 0;

    /* create rootfs folder structure */
    while (1) {
        if (rfs_folder[i] != NULL) {
            if (stat(rfs_folder[i], &buf) < 0) {
                if (mkdir(rfs_folder[i], 0x777) < 0) {
                    console_printf("fail to create %s, errno:%d\n", rfs_folder[i], rt_get_errno());
                    return FMT_ERROR;
                }
            }
            i++;
        } else {
            break;
        }
    }
    /* update log session */
    if (update_log_session() != FMT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

/**
 * Initialize the file system.
 * 
 * @return FMT Errors.
 */
fmt_err file_manager_init(void)
{
    /* init dfs system */
    if (dfs_init() != 0) {
        console_printf("dfs init fail!\n");
        return FMT_ERROR;
    }
    /* init fatfs */
    if (elm_init() != 0) {
        console_printf("fatfs init fail!\n");
        return FMT_ERROR;
    }

    /* mount storage devices */
    for (int i = 0; i < sizeof(mnt_table) / sizeof(struct dfs_mount_tbl); i++) {
        if (dfs_mount(mnt_table[i].device_name,
                mnt_table[i].path,
                mnt_table[i].filesystemtype,
                mnt_table[i].rwflag,
                mnt_table[i].data)
            != 0) {
            console_printf("Fail to mount %s at %s!\n",
                mnt_table[i].device_name, mnt_table[i].path);
            return FMT_ERROR;
        }
    }

    create_rootfs();

    return FMT_EOK;
}