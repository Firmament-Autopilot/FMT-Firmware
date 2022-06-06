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
#include <dfs_posix.h>
#include <firmament.h>

static void __deldir(char* path)
{
    DIR* dir = opendir(path);
    struct dirent* dr = readdir(dir);

    while (dr) {
        strcat(path, "/");
        strcat(path, dr->d_name);

        if (dr->d_type == FT_DIRECTORY) {
            __deldir(path);
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

int fm_deldir(const char* path)
{
    char temp_path[100];
    struct stat buf;

    if (stat(path, &buf) < 0) {
        /* not existed path */
        return 0;
    }

    strcpy(temp_path, path);
    __deldir(temp_path);

    // TODO, check success
    return 0;
}