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

#include "driver/usb/mtp/usbd_mtp_file.h"
#include "stdio.h"
#include "fcntl.h"
#include "dirent.h"
#include "unistd.h"
#include "sys/stat.h"
#include "sys/statfs.h"
#include "string.h"

static const char mtp_root_path[] = CONFIG_USBDEV_MTP_ROOT_PATH;

const char *usbd_mtp_fs_root_path(void)
{
    return mtp_root_path;
}

/* directory operation */
int usbd_mtp_mkdir(const char *path)
{
    return mkdir(path, 0);
}

int usbd_mtp_rmdir(const char *path)
{
    return rmdir(path);
}

int usbd_mtp_rmdir_recursive(const char *path)
{
    #define MAX_PATH_DEPTH 16
    int depth_len[MAX_PATH_DEPTH];          /* records the depth of the path*/
    int stack_top = 0;
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char full_path[CONFIG_USBDEV_MTP_MAX_PATHNAME];
    int has_subdir;
    int ret = 0;

    /* Initialize path */
    strncpy(full_path, path, CONFIG_USBDEV_MTP_MAX_PATHNAME - 1);
    full_path[CONFIG_USBDEV_MTP_MAX_PATHNAME - 1] = '\0';
    depth_len[0] = strlen(full_path);

    while (stack_top >= 0) {
        /* Try to delete directory, empty or not */
        if (rmdir(full_path) == 0) {
            /* Deletion succeeded, directory is empty or already an empty directory */
            stack_top--;
            if (stack_top >= 0) {
                full_path[depth_len[stack_top]] = '\0';  /* Fallback to parent directory */
            }
            continue;
        }

        /* rmdir failed, directory is not empty, need to traverse and delete contents */
        dir = opendir(full_path);
        if (dir == NULL) {
            USB_LOG_ERR("[MTP_RMDIR] Failed to open directory: %s\n", full_path);
            stack_top--;
            if (stack_top >= 0) {
                full_path[depth_len[stack_top]] = '\0';  /* Fallback to parent directory */
            }
            ret = -1;
            continue;
        }

        has_subdir = 0;

        /* Traverse all entries in the directory */
        while ((entry = readdir(dir)) != NULL) {
            /* Skip "." and ".." */
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            /* Build full path */
            int current_len = strlen(full_path);
            snprintf(full_path + current_len, PATH_MAX - current_len, "/%s", entry->d_name);

            /* Get file status */
            if (stat(full_path, &statbuf) != 0) {
                USB_LOG_ERR("[MTP_RMDIR] Failed to stat: %s\n", full_path);
                ret = -1;
                full_path[current_len] = '\0';  /* Restore original path */
                continue;
            }

            /* If it is a subdirectory */
            if (S_ISDIR(statbuf.st_mode)) {
                /* Check stack depth */
                if (stack_top >= MAX_PATH_DEPTH - 1) {
                    USB_LOG_ERR("[MTP_RMDIR] Directory depth exceeds %d levels: %s\n", MAX_PATH_DEPTH, full_path);
                    closedir(dir);
                    return -1;
                }

                /* Save current path length and enter subdirectory */
                stack_top++;
                depth_len[stack_top] = strlen(full_path);
                has_subdir = 1;
                break;
            } else {
                /* If it is a file, delete directly */
                if (unlink(full_path) != 0) {
                    USB_LOG_ERR("[MTP_RMDIR] Failed to unlink file: %s\n", full_path);
                    ret = -1;
                }
                full_path[current_len] = '\0';  /* Restore original path */
            }
        }

        closedir(dir);

        /* If no subdirectory, try to delete current directory again and fallback */
        if (!has_subdir) {
            if (rmdir(full_path) != 0) {
                USB_LOG_ERR("[MTP_RMDIR] Failed to remove directory: %s\n", full_path);
                ret = -1;
            }
            stack_top--;
            if (stack_top >= 0) {
                full_path[depth_len[stack_top]] = '\0';  /* Fallback to parent directory */
            }
        }
    }

    return ret;
}

MTP_DIR *usbd_mtp_opendir(const char *path)
{
    return opendir(path);
}

int usbd_mtp_closedir(MTP_DIR *d)
{
    DIR *dir = (DIR *)d;
    return closedir(dir);
}

struct mtp_dirent *usbd_mtp_readdir(MTP_DIR *d)
{
    DIR *dir = (DIR *)d;
    struct dirent *dirent;
    static struct mtp_dirent mtp_dirent;

    dirent = readdir(dir);
    if (dirent == NULL)
        return NULL;

    mtp_dirent.d_type = dirent->d_type;
    mtp_dirent.d_namlen = dirent->d_namlen;
    mtp_dirent.d_reclen = dirent->d_reclen;
    strcpy(mtp_dirent.d_name, dirent->d_name);

    return &mtp_dirent;
}

MTP_DIRENT *usbd_mtp_readdir_raw(MTP_DIR *d)
{
    DIR *dir = (DIR *)d;
    struct dirent *dirent = readdir(dir);
    if (dirent == NULL) {
        USB_LOG_DBG("[MTP_READDIR] readdir returned NULL\r\n");
    } else {
        USB_LOG_DBG("[MTP_READDIR] Got file: %s (len=%d)\r\n", dirent->d_name, dirent->d_namlen);
    }
    return (MTP_DIRENT *)dirent;
}

int usbd_mtp_make_fullpath(char *path, MTP_DIRENT *d)
{
    struct dirent *dirent = (struct dirent *)d;
    strcat(path, "/");
    strcat(path, dirent->d_name);
    return 0;
}

int usbd_mtp_get_file_info(void *d,
                            char *file_name,
                            uint8_t *file_name_len,
                            uint32_t *protection_status)
{
    DIR *dir = (DIR *)d;
    struct dirent *dirent;

    dirent = readdir(dir);
    if (dirent == NULL) {
        USB_LOG_DBG("[MTP_READDIR] readdir returned NULL\r\n");
        return 0;
    }

    *file_name_len = dirent->d_namlen;
    strcpy(file_name, dirent->d_name);
    *protection_status = 0;

    USB_LOG_DBG("[MTP_READDIR] Got file: %s (len=%d)\r\n", dirent->d_name, dirent->d_namlen);

    return 1; /* if still read the file, please return 1 */
}

/* directory operation */
int usbd_mtp_unlink(const char *pathname)
{
    return unlink(pathname);
}

int usbd_mtp_open(const char *path, int flags, int mode)
{
    return open(path, flags, mode);
}

int usbd_mtp_close(int fd)
{
    return close(fd);
}

int usbd_mtp_read(int fd, void *buf, size_t len)
{
    return read(fd, (char *)buf, len);
}

int usbd_mtp_write(int fd, const void *buf, size_t len)
{
    return write(fd, buf, len);
}

int usbd_mtp_statfs(const char *path, struct mtp_statfs *buf)
{
    struct statfs s;
    if(statfs(path, &s) < 0)
        return -1;
    buf->f_bfree = s.f_bfree;
    buf->f_blocks = s.f_blocks;
    buf->f_bsize = s.f_bsize;
    USB_LOG_DBG("max_capability:%lld free_space:%lld\n", 
        (uint64_t)buf->f_bsize * (uint64_t)buf->f_blocks, 
        (uint64_t)buf->f_bsize * (uint64_t)buf->f_bfree);

    return 0;
}

int usbd_mtp_stat(const char *file, struct stat *buf)
{
    struct stat s;
    if(stat(file, &s) < 0)
        return -1;
    
    *buf = s;

    return 0;
}

uint32_t usbd_mtp_get_file_size(const char *file)
{
    struct stat s;
    if(stat(file, &s) < 0)
        return -1;

    return s.st_size;
}

int usbd_mtp_get_fullpath(char *buf, const char *directory, const char *filename)
{
    char *fullpath;
    fullpath = dfs_normalize_path(directory, filename);
    strcpy(buf, fullpath);
    rt_free(fullpath);
    return 0;
}
