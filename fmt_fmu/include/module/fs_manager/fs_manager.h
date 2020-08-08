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

#ifndef __FS_MANAGER_H__
#define __FS_MANAGER_H__

#include <firmament.h>
#include <dfs_posix.h>

fmt_err fs_manager_init(const char* device_name, const char* path);

bool fs_file_exist(const char* path);
fmt_err fs_deldir(const char* path);
int fs_fprintf(int fd, const char* fmt, ...);

#endif