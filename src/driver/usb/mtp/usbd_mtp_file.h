/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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

#ifndef __USBD_MTP_FILE_H__
#define __USBD_MTP_FILE_H__ 

#include <sys/stat.h>
#include <fcntl.h>
#include "usbd_core.h"

/* gcc toolchain does not implement dirent.h, so we define our own MTP_DIR and mtp_dirent */

typedef void MTP_DIR;

typedef void MTP_DIRENT;

struct mtp_statfs {
    size_t f_bsize;  /* block size */
    size_t f_blocks; /* total data blocks in file system */
    size_t f_bfree;  /* free blocks in file system */
};

struct mtp_dirent {
    uint8_t d_type;                              /* The type of the file */
    uint8_t d_namlen;                            /* The length of the not including the terminating null file name */
    uint16_t d_reclen;                           /* length of this record */
    char d_name[CONFIG_USBDEV_MTP_MAX_PATHNAME]; /* The null-terminated file name */
};

struct mtp_file {
    uint32_t handle;
    int fd;
    int offset;
    int32_t data_length;
};

const char *usbd_mtp_fs_root_path(void);
const char *usbd_mtp_fs_description(void);

int usbd_mtp_mkdir(const char *path);
int usbd_mtp_rmdir(const char *path);
int usbd_mtp_rmdir_recursive(const char *path);
MTP_DIR *usbd_mtp_opendir(const char *name);
int usbd_mtp_closedir(MTP_DIR *d);
struct mtp_dirent *usbd_mtp_readdir(MTP_DIR *d);

int usbd_mtp_statfs(const char *path, struct mtp_statfs *buf);
int usbd_mtp_stat(const char *file, struct stat *buf);

int usbd_mtp_open(const char *path, int flags, int mode);
int usbd_mtp_close(int fd);
int usbd_mtp_read(int fd, void *buf, size_t len);
int usbd_mtp_write(int fd, const void *buf, size_t len);

int usbd_mtp_unlink(const char *path);

MTP_DIRENT *usbd_mtp_readdir_raw(MTP_DIR *d);

int usbd_mtp_get_file_info(void *d,
                           char *file_name,
                           uint8_t *file_name_len,
                           uint32_t *protection_status);

int usbd_mtp_set_file_mtime(const char *dfs_path, struct tm *p_tm);
int usbd_mtp_make_fullpath(char *path, MTP_DIRENT *d);
int usbd_mtp_get_fullpath(char *buf, const char *directory, const char *filename);
uint32_t usbd_mtp_get_file_size(const char *file);

#endif