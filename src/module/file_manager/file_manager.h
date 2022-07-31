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

#ifndef FILE_MANAGER_H__
#define FILE_MANAGER_H__

#include <dfs_posix.h>
#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

fmt_err_t file_manager_init(const struct dfs_mount_tbl* mnt_table);
fmt_err_t current_log_session(char* path);

/* file extended operation */
int fm_fprintf(int fd, const char* fmt, ...);
int fm_deldir(const char* path);

#ifdef __cplusplus
}
#endif

#endif
