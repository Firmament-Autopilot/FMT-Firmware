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

#include "dfs_elm.h"
#include "dfs_fs.h"
#include "shell.h"
#include "yxml.h"
#include <firmament.h>
#include <string.h>

#include "driver/sd_dev.h"
#include "module/fs_manager/fs_manager.h"

#define FS_TYPE "elm"

static fmt_err _mk_rootfs(void)
{
    struct stat buf;

    if (stat("/sys", &buf) < 0) {
        mkdir("/sys", 0x777);
    }

    if (stat("/usr", &buf) < 0) {
        mkdir("/usr", 0x777);
    }

    if (stat("/log", &buf) < 0) {
        mkdir("/log", 0x777);
    }

    return FMT_EOK;
}

static void _deldir(char* path)
{
    DIR* dir = opendir(path);

    struct dirent* dr = readdir(dir);

    while (dr) {
        strcat(path, "/");
        strcat(path, dr->d_name);

        if (dr->d_type == FT_DIRECTORY) {
            _deldir(path);
        } else {
            unlink(path);
        }

        for (int i = strlen(path) - 1; i >= 0; i--) {
            if (path[i] == '/') {
                path[i] = '\0';
                break;
            }

            path[i] = 0;
        }

        dr = readdir(dir);
    }

    closedir(dir);
    unlink(path);
}

//===================================================================================

fmt_err fs_deldir(const char* path)
{
    char temp_path[100];

    strcpy(temp_path, path);
    _deldir(temp_path);

    // TODO, check path
    return FMT_EOK;
}

bool fs_file_exist(const char* path)
{
    struct stat buf;

    if (stat(path, &buf) == 0) {
        return true;
    } else {
        return false;
    }

    // return (fres == FR_OK);
}

int fs_fprintf(int fd, const char* fmt, ...)
{
    va_list args;
    int length;
    char buffer[256];

    va_start(args, fmt);
    length = vsprintf(buffer, fmt, args);
    va_end(args);

    return write(fd, buffer, length);
}

fmt_err fs_manager_init(const char* device_name, const char* path)
{
    /* init dfs system */
    dfs_init();

    /* init storage devices */
    // dev_sd_init(device_name);

    elm_init();

    int res = dfs_mount(device_name, path, FS_TYPE, 0, NULL);

    if (res != 0) {
        console_printf("dfs mount fail\n");
        return FMT_ERROR;
    }

    /* make root fs system */
    _mk_rootfs();

    return FMT_EOK;
}
