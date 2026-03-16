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

#ifndef __USBD_MTP_OBJECT_H__
#define __USBD_MTP_OBJECT_H__

#include <stdint.h>
#include <stdbool.h>
#include <rtthread.h>
#include "usb_config.h"
#include "driver/usb/mtp/usb_mtp.h"

#define MTP_HANDLE_POOL_SIZE    CONFIG_USBDEV_MTP_MAX_OBJECTS   /* handle pool size */
#define MTP_MAX_DIR_DEPTH      16    /* max directory depth */

/* MTP object entry */
typedef struct {
    uint32_t handle;               /* MTP handle (handle == 0 as empty) */
    uint32_t storage_id;           /* Storage ID */
    uint32_t parent_handle;        /* Parent object handle (0xFFFFFFFF as root directory) */
    char name[64];                /* Object name (filename or directory name, max 63 bytes + '\0') */
    uint32_t size;                 /* File size (directory is 0) */
    uint32_t timestamp;            /* timestamp */
    uint16_t format;               /* Object format */
    uint8_t is_dir;                /* is directory */
    uint8_t is_hidden;             /* is hidden */
    uint8_t is_readonly;           /* is readonly */
} mtp_object_t;

/* objects manager */
typedef struct {
    mtp_object_t objects[MTP_HANDLE_POOL_SIZE];  /* objects pool */
    uint32_t next_handle;                         /* Next allocated handle */
    uint32_t total_objects;                       /* Current number of objects */
    rt_mutex_t mutex;                             /* Mutex lock */
} mtp_object_manager_t;

/* delete callback function type (for cascade delete) */
typedef int (*mtp_delete_file_fn)(const char *path);  /* delete file callback */
typedef int (*mtp_delete_dir_fn)(const char *path);   /* delete directory callback */

int mtp_object_manager_init(mtp_object_manager_t *manager);
void mtp_object_manager_deinit(mtp_object_manager_t *manager);

int mtp_alloc_handle(mtp_object_manager_t *manager, uint32_t storage_id,
                     uint32_t parent_handle, const char *path,
                     uint16_t format, uint32_t size, bool is_dir);
int mtp_free_handle(mtp_object_manager_t *manager, uint32_t handle);
int mtp_free_handle_recursive(mtp_object_manager_t *manager,
                              uint32_t handle,
                              mtp_delete_file_fn delete_file,
                              mtp_delete_dir_fn delete_dir);  /* cascade delete (including sub-objects) */
int mtp_get_object_by_handle(mtp_object_manager_t *manager, uint32_t handle,
                              mtp_object_t **obj);
int mtp_get_parent_by_handle(mtp_object_manager_t *manager, uint32_t handle,
                              uint32_t *parent_handle);
int mtp_rebuild_full_path(mtp_object_manager_t *manager, uint32_t handle,
                          char *full_path, size_t max_len);

#endif /* __USBD_MTP_OBJECT_H__ */
