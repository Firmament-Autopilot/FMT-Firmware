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

static const struct dfs_mount_tbl mnt_table[] = {
    { "sd0", "/", "elm", 0, NULL }
};

static const char* rfs_folder[] = {
    "/sys",
    "/usr",
    "/log",
    NULL /* NULL indicate the end */
};

// static fmt_err create_log_session(void)
// {
// }

/**
 * Create rootfs folders if not existed.
 * 
 * @return FMT Errors.
 */
static fmt_err create_rootfs(void)
{
    struct stat buf;
    int i = 0;

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