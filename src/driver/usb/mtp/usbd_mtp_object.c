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

#include "driver/usb/mtp/usbd_mtp_object.h"
#include "driver/usb/mtp/usbd_mtp.h"
#include "usb_log.h"
#include <string.h>
#include <stdlib.h>
#include <rtthread.h>

/* Hash function: Generate stable handle based on path */
/* Using FNV-1a hash algorithm variant */
static uint32_t mtp_hash_path(uint32_t storage_id, uint32_t parent_handle, const char *path) {
    uint32_t hash = 2166136261u; /* FNV offset basis */

    /* Mix storage_id and parent_handle */
    hash ^= (storage_id << 8) | (storage_id >> 24);
    hash *= 16777619u; /* FNV prime */

    hash ^= parent_handle;
    hash *= 16777619u;

    /* Mix path string */
    const unsigned char *str = (const unsigned char *)path;
    while (*str) {
        hash ^= *str++;
        hash *= 16777619u;
    }

    /* Ensure hash value is within valid range (avoid special values) */
    /* MTP specification: 0 means invalid, 0xFFFFFFFF means root directory */
    /* Map hash to [1, 0xFFFFFFFE] range */
    hash = hash & 0xFFFFFFFEu; /* Clear lowest bit to avoid 0 */
    if (hash == 0) hash = 1; /* Ensure non-zero */
    if (hash == 0xFFFFFFFF) hash = 0xFFFFFFFE; /* Avoid using root directory marker */

    return hash;
}

/* Initialize object manager */
int mtp_object_manager_init(mtp_object_manager_t *manager) {
    if (!manager) return -1;

    /* Fully initialize structure */
    memset(manager, 0, sizeof(mtp_object_manager_t));

    /* Create mutex */
    manager->mutex = rt_mutex_create("mtp_obj", RT_IPC_FLAG_PRIO);
    if (!manager->mutex) {
        return -1;
    }

    USB_LOG_DBG("MTP object manager initialized (hash mode)\n");
    return 0;
}

/* Deinitialize object manager */
void mtp_object_manager_deinit(mtp_object_manager_t *manager) {
    if (!manager) return;

    if (manager->mutex) {
        rt_mutex_delete(manager->mutex);
        manager->mutex = NULL;
    }

    USB_LOG_DBG("MTP object manager deinitialized\n");
}

/* Find object by handle (must be called while holding lock) */
static int mtp_find_object_by_handle_unlocked(mtp_object_manager_t *manager,
                                                uint32_t handle,
                                                mtp_object_t **obj) {
    if (!manager || handle == 0 || !obj) return -1;

    /* Linear search for object (handle == matching handle) */
    for (uint32_t i = 0; i < MTP_HANDLE_POOL_SIZE; i++) {
        if (manager->objects[i].handle == handle) {
            *obj = &manager->objects[i];
            return 0;
        }
    }

    return -1; /* Not found */
}

/* Forward declaration: Rebuild full path of object (unlocked version) */
static int mtp_rebuild_full_path_unlocked(mtp_object_manager_t *manager, uint32_t handle,
                                          char *full_path, size_t max_len);

/* Allocate handle (Hash-based allocation, automatic persistence) */
/* Same path always generates same handle, no additional persistence mechanism needed */
int mtp_alloc_handle(mtp_object_manager_t *manager, uint32_t storage_id,
                     uint32_t parent_handle, const char *path,
                     uint16_t format, uint32_t size, bool is_dir) {
    if (!manager || !path) return 0;

    rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

    /* ========== Hash-based handle allocation ========== */
    /* Same path generates same handle, naturally supports persistence */
    uint32_t new_handle = mtp_hash_path(storage_id, parent_handle, path);

    /* Check if handle already exists */
    mtp_object_t *existing_obj = NULL;
    if (mtp_find_object_by_handle_unlocked(manager, new_handle, &existing_obj) == 0) {
        /* Handle already exists, update object info (same path, reuse directly) */
        USB_LOG_DBG("[MTP_REUSE] Reusing hash handle 0x%lx for %s\n",
                  (unsigned long)new_handle, path);

        existing_obj->format = format;
        existing_obj->size = size;
        existing_obj->is_dir = is_dir ? 1 : 0;
        existing_obj->timestamp = rt_tick_get();

        rt_mutex_release(manager->mutex);
        return new_handle;
    }

    /* ========== Handle does not exist, allocate new object ========== */
    USB_LOG_DBG("[MTP_ALLOC] Allocated hash handle 0x%lx for %s\n",
              (unsigned long)new_handle, path);

    /* Find free slot */
    int obj_index = -1;
    for (uint32_t i = 0; i < MTP_HANDLE_POOL_SIZE; i++) {
        if (manager->objects[i].handle == 0) {
            obj_index = (int)i;
            break;
        }
    }

    if (obj_index < 0) {
        USB_LOG_ERR("Object pool full!\n");
        rt_mutex_release(manager->mutex);
        return 0;
    }

    /* Extract object name (last component of path) */
    const char *name_start = strrchr(path, '/');
    if (name_start) {
        name_start++; /* Skip '/' */
    } else {
        name_start = path;
    }

    size_t name_len = strlen(name_start);
    if (name_len == 0 || name_len >= sizeof(manager->objects[0].name)) {
        USB_LOG_ERR("Invalid name length: %zu\n", name_len);
        rt_mutex_release(manager->mutex);
        return 0;
    }

    /* Initialize object */
    mtp_object_t *obj = &manager->objects[obj_index];

    /* Increment object count */
    manager->total_objects++;

    obj->handle = new_handle;
    obj->storage_id = storage_id;
    obj->parent_handle = parent_handle;
    obj->format = format;
    obj->size = size;
    obj->is_dir = is_dir ? 1 : 0;
    obj->is_hidden = 0;
    obj->is_readonly = 0;
    obj->timestamp = rt_tick_get();

    /* Only store object name (not full path) */
    strncpy(obj->name, name_start, sizeof(obj->name) - 1);
    obj->name[sizeof(obj->name) - 1] = '\0';

    USB_LOG_DBG("Allocated handle 0x%lx for %s (parent=0x%lx)\n",
              (unsigned long)obj->handle, path, (unsigned long)parent_handle);

    rt_mutex_release(manager->mutex);
    return obj->handle;
}

/* Free handle */
int mtp_free_handle(mtp_object_manager_t *manager, uint32_t handle) {
    if (!manager || handle == 0) return -1;

    rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

    mtp_object_t *obj;
    if (mtp_find_object_by_handle_unlocked(manager, handle, &obj) != 0) {
        rt_mutex_release(manager->mutex);
        return -1;
    }

    /* Clear object (mark as free) */
    USB_LOG_DBG("Freeing handle 0x%lx (%s)\n", (unsigned long)handle, obj->name);
    memset(obj, 0, sizeof(mtp_object_t));
    manager->total_objects--;

    rt_mutex_release(manager->mutex);
    return 0;
}

/* Cascading delete object and its children (using DFS post-order traversal) */
/* delete_file: Callback function to delete files */
/* delete_dir:  Callback function to delete directories */
int mtp_free_handle_recursive(mtp_object_manager_t *manager,
                              uint32_t handle,
                              mtp_delete_file_fn delete_file,
                              mtp_delete_dir_fn delete_dir) {
    if (!manager || handle == 0) return -1;
    if (!delete_file || !delete_dir) return -1;

    uint32_t *delete_stack = NULL;
    uint16_t stack_top = 0;
    char path_buffer[CONFIG_USBDEV_MTP_MAX_PATHNAME];

    delete_stack = (uint32_t *)usb_osal_malloc(sizeof(uint32_t) * manager->total_objects);
    if (delete_stack == NULL) {
        USB_LOG_ERR("Failed to allocate memory for delete stack\n");
        return -1;
    }

    /* Push initial handle onto stack */
    delete_stack[stack_top++] = handle;

    while (stack_top > 0) {
        uint32_t cur_handle = delete_stack[--stack_top]; /* Pop */

        rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

        /* Get current object */
        mtp_object_t *obj = NULL;
        int found = mtp_find_object_by_handle_unlocked(manager, cur_handle, &obj);

        if (found != 0 || !obj) {
            rt_mutex_release(manager->mutex);
            USB_LOG_DBG("[MTP_DEL] Skip removed handle 0x%lx\n", (unsigned long)cur_handle);
            continue; /* Object already deleted, skip */
        }

        if (obj->format == MTP_FORMAT_ASSOCIATION) {
            /* Directory: Check if there are child objects */
            /* static uint32_t children[64]; */
            /* uint32_t child_count = 0; */
            bool need_push_parent = true;

            /* Get child objects while holding lock */
            for (uint32_t i = 0; i < MTP_HANDLE_POOL_SIZE; i++) {
                if (manager->objects[i].handle != 0 &&
                    manager->objects[i].parent_handle == cur_handle) {
                    if (need_push_parent) {
                        USB_LOG_DBG("[MTP_DEL] Directory handle 0x%lx has children, postponing delete\n",
                                    (unsigned long)cur_handle);
                        need_push_parent = false;
                        if (stack_top < manager->total_objects) {
                            delete_stack[stack_top++] = cur_handle;
                        }
                    }
                    if (stack_top < manager->total_objects) {
                        delete_stack[stack_top++] = manager->objects[i].handle;
                    }
                }
            }

            if (stack_top >= manager->total_objects) {
                USB_LOG_ERR("Delete stack overflow!\n");
                rt_mutex_release(manager->mutex);
                usb_osal_free(delete_stack);
                return -1;
            }

            if (need_push_parent == false) {
                /* Has children: Push current directory back onto stack (delete parent later) */
                rt_mutex_release(manager->mutex);
                continue; /* Children already stacked, skip current round deletion */
            }
            /* No children: Continue with delete empty directory logic */
        }

        /* Rebuild path (must be done while holding lock) */
        int path_ret = mtp_rebuild_full_path_unlocked(manager, cur_handle,
                                                      path_buffer, sizeof(path_buffer));
        rt_mutex_release(manager->mutex);

        /* Execute file system delete operation (not within lock to avoid deadlock) */
        if (path_ret == 0) {
            if (obj->format == MTP_FORMAT_ASSOCIATION) {
                delete_dir(path_buffer); /* Delete empty directory */
            } else {
                delete_file(path_buffer); /* Delete file */
            }
        }

        /* Free handle */
        mtp_free_handle(manager, cur_handle);
    }

    usb_osal_free(delete_stack);
    return 0;
}

/* Rebuild full path of object (unlocked version, must be called while holding lock) */
/* Used for internal path checking in mtp_alloc_handle to avoid deadlock */
/* Optimization: Store object pointers directly to avoid repeated lookups */
static int mtp_rebuild_full_path_unlocked(mtp_object_manager_t *manager, uint32_t handle,
                                          char *full_path, size_t max_len) {
    if (!manager || handle == 0 || !full_path || max_len == 0) return -1;

    /* Store object pointers (32 bytes stack space, acceptable) */
    mtp_object_t *components[MTP_MAX_DIR_DEPTH];
    int component_count = 0;
    uint32_t current_handle = handle;

    /* Traverse upwards to collect object pointers (maximum 8 levels) */
    while (component_count < MTP_MAX_DIR_DEPTH && current_handle != 0xFFFFFFFF) {
        mtp_object_t *obj = NULL;
        if (mtp_find_object_by_handle_unlocked(manager, current_handle, &obj) != 0 || !obj) {
            break; /* Object does not exist */
        }

        components[component_count++] = obj;
        current_handle = obj->parent_handle;

        if (obj->parent_handle == 0xFFFFFFFF) {
            break; /* Reached root directory */
        }
    }

    if (component_count == 0) return -1;

    /* Reverse concatenate full path (from root to leaf, using safe string operations) */
    full_path[0] = '\0';
    size_t current_len = 0;

    for (int i = component_count - 1; i >= 0; i--) {
        mtp_object_t *obj = components[i];
        size_t name_len = strlen(obj->name);

        /* Check if there's space to add "/" and name */
        if (current_len + 1 + name_len + 1 > max_len) {
            USB_LOG_DBG("Path too long during rebuild\n");
            return -1; /* Path too long */
        }

        /* Add path separator */
        if (current_len > 0 || full_path[0] != '/') {
            strcpy(full_path + current_len, "/");
            current_len += 1;
        }

        /* Add name */
        strcpy(full_path + current_len, obj->name);
        current_len += name_len;
    }

    if (current_len >= max_len) {
        USB_LOG_DBG("Path too long, current_len=%d, max_len=%d\n", current_len, max_len);
        return -1; /* Path too long */
    }

    full_path[current_len] = '\0';
    return 0;
}

/* Get object by handle */
int mtp_get_object_by_handle(mtp_object_manager_t *manager, uint32_t handle,
                              mtp_object_t **obj) {
    if (!manager || handle == 0 || !obj) return -1;

    rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

    int ret = mtp_find_object_by_handle_unlocked(manager, handle, obj);

    rt_mutex_release(manager->mutex);
    return ret;
}

/* Get parent handle by handle */
int mtp_get_parent_by_handle(mtp_object_manager_t *manager, uint32_t handle,
                              uint32_t *parent_handle) {
    mtp_object_t *obj = NULL;
    if (!manager || handle == 0 || !parent_handle) return -1;

    rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

    int ret = mtp_find_object_by_handle_unlocked(manager, handle, &obj);
    if (ret == 0 && obj) {
        *parent_handle = obj->parent_handle;
    }

    rt_mutex_release(manager->mutex);
    return ret;
}

/* Rebuild full path of object (recursively search upwards for parent objects) */
/* Optimized version: Use handle array instead of string array, greatly reduce stack usage (2048 bytes -> 32 bytes) */
int mtp_rebuild_full_path(mtp_object_manager_t *manager, uint32_t handle,
                          char *full_path, size_t max_len) {
    if (!manager || handle == 0 || !full_path || max_len == 0) return -1;

    rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

    /* Optimization: Only store handle (4 bytes) instead of string (64 bytes), greatly reduce stack usage */
    /* Reduced from 2048 bytes (32×64) to 32 bytes (8×4) */
    uint32_t component_handles[MTP_MAX_DIR_DEPTH];
    int component_count = 0;
    uint32_t current_handle = handle;
    bool success = false;

    /* Traverse upwards to build path components (maximum 8 levels depth) */
    /* Actual file systems rarely exceed 8 levels depth, this limit is sufficient */
    for (int depth = 0; depth < MTP_MAX_DIR_DEPTH && current_handle != 0xFFFFFFFF; depth++) {
        mtp_object_t *obj = NULL;
        int ret = mtp_find_object_by_handle_unlocked(manager, current_handle, &obj);
        if (ret != 0 || !obj) {
            break; /* Object does not exist, stop */
        }

        /* Store handle instead of string (reduce stack usage) */
        component_handles[component_count++] = current_handle;
        current_handle = obj->parent_handle;

        /* Check if reached root directory */
        if (obj->parent_handle == 0xFFFFFFFF) {
            success = true;
            break;
        }
    }

    if (success && component_count > 0) {
        /* Reverse concatenate full path (from root to leaf, using safe string operations) */
        full_path[0] = '\0';
        size_t current_len = 0;

        for (int i = component_count - 1; i >= 0; i--) {
            mtp_object_t *obj = NULL;
            if (mtp_find_object_by_handle_unlocked(manager, component_handles[i], &obj) != 0) {
                rt_mutex_release(manager->mutex);
                return -1; /* Object lost */
            }

            size_t name_len = strlen(obj->name);

            /* Check if there's space to add "/" and name */
            if (current_len + 1 + name_len + 1 > max_len) {
                rt_mutex_release(manager->mutex);
                return -1; /* Path too long */
            }

            /* Add path separator (needed before each component) */
            strcpy(full_path + current_len, "/");
            current_len += 1;
            strcpy(full_path + current_len, obj->name);
            current_len += name_len;
        }

        full_path[current_len] = '\0';
        rt_mutex_release(manager->mutex);
        return 0;
    }

    rt_mutex_release(manager->mutex);
    return -1;
}

/* MSH command: Display MTP object manager status
 * Usage:
 *   mtp_obj           - Show overview statistics
 *   mtp_obj stat      - Show detailed statistics
 *   mtp_obj handles   - Show all handles
 *   mtp_obj dirs      - Show directories only
 *   mtp_obj files     - Show files only
 *   mtp_obj <handle>  - Show specific handle details
 */
static int msh_mtp_obj(int argc, char **argv)
{
    mtp_object_manager_t *manager = usbd_mtp_get_obj_manager();
    if (!manager) {
        console_printf("MTP object manager not initialized\n");
        return -1;
    }

    /* No parameters: Show overview statistics */
    if (argc == 1) {
        rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

        uint32_t used = 0;
        uint32_t dirs = 0;
        uint32_t files = 0;

        for (uint32_t i = 0; i < MTP_HANDLE_POOL_SIZE; i++) {
            if (manager->objects[i].handle != 0) {
                used++;
                if (manager->objects[i].is_dir) {
                    dirs++;
                } else {
                    files++;
                }
            }
        }

        rt_mutex_release(manager->mutex);

        console_printf("========== MTP Object Manager Status ==========\n");
        console_printf("Total objects: %lu / %u\n", (unsigned long)manager->total_objects, MTP_HANDLE_POOL_SIZE);
        console_printf("  - Dirs:  %lu\n", (unsigned long)dirs);
        console_printf("  - Files: %lu\n", (unsigned long)files);
        console_printf("Usage: %.1f%%\n", (float)used * 100.0f / MTP_HANDLE_POOL_SIZE);
        console_printf("\n");
        console_printf("Commands:\n");
        console_printf("  mtp_obj stat        - Show detailed statistics\n");
        console_printf("  mtp_obj handles     - List all handles\n");
        console_printf("  mtp_obj dirs        - List directories only\n");
        console_printf("  mtp_obj files       - List files only\n");
        console_printf("  mtp_obj <handle>    - Show handle details\n");
        return 0;
    }

    const char *cmd = argv[1];

    /* Detailed statistics */
    if (strcmp(cmd, "stat") == 0) {
        rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

        uint32_t used = 0;
        uint32_t dirs = 0;
        uint32_t files = 0;
        uint32_t hidden = 0;
        uint32_t readonly = 0;
        uint32_t total_size = 0;

        for (uint32_t i = 0; i < MTP_HANDLE_POOL_SIZE; i++) {
            if (manager->objects[i].handle != 0) {
                used++;
                if (manager->objects[i].is_dir) {
                    dirs++;
                } else {
                    files++;
                    total_size += manager->objects[i].size;
                }
                if (manager->objects[i].is_hidden) hidden++;
                if (manager->objects[i].is_readonly) readonly++;
            }
        }

        rt_mutex_release(manager->mutex);

        console_printf("========== MTP Object Manager Statistics ==========\n");
        console_printf("Pool Size:     %u\n", MTP_HANDLE_POOL_SIZE);
        console_printf("Total Objects: %lu\n", (unsigned long)manager->total_objects);
        console_printf("Used Slots:    %lu\n", (unsigned long)used);
        console_printf("Free Slots:    %lu\n", (unsigned long)(MTP_HANDLE_POOL_SIZE - used));
        console_printf("Usage:         %.2f%%\n", (float)used * 100.0f / MTP_HANDLE_POOL_SIZE);
        console_printf("\n");
        console_printf("Object Types:\n");
        console_printf("  Directories: %lu\n", (unsigned long)dirs);
        console_printf("  Files:       %lu\n", (unsigned long)files);
        console_printf("\n");
        console_printf("Attributes:\n");
        console_printf("  Hidden:      %lu\n", (unsigned long)hidden);
        console_printf("  Read-only:   %lu\n", (unsigned long)readonly);
        console_printf("\n");
        console_printf("Total File Size: %lu bytes (%.2f KB)\n",
                   (unsigned long)total_size, (float)total_size / 1024.0f);
        return 0;
    }

    /* Show all handles */
    if (strcmp(cmd, "handles") == 0) {
        rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

        console_printf("========== MTP Object Handles ==========\n");
        console_printf("%-10s %-6s %-10s %-8s %-10s %s\n",
                   "Handle", "Type", "Format", "Size", "Parent", "Name");
        console_printf("%s\n", "------------------------------------------------------------");

        uint32_t count = 0;
        for (uint32_t i = 0; i < MTP_HANDLE_POOL_SIZE; i++) {
            if (manager->objects[i].handle != 0) {
                mtp_object_t *obj = &manager->objects[i];
                const char *type = obj->is_dir ? "DIR " : "FILE";

                char parent_str[16];
                if (obj->parent_handle == 0xFFFFFFFF) {
                    strcpy(parent_str, "ROOT");
                } else if (obj->parent_handle == 0) {
                    strcpy(parent_str, "-");
                } else {
                    snprintf(parent_str, sizeof(parent_str), "0x%08lx",
                             (unsigned long)obj->parent_handle);
                }

                console_printf("0x%08lx %-6s 0x%04x     %-8lu %s %s\n",
                           (unsigned long)obj->handle,
                           type,
                           obj->format,
                           (unsigned long)obj->size,
                           parent_str,
                           obj->name);
                count++;
            }
        }

        rt_mutex_release(manager->mutex);

        console_printf("\nTotal: %lu objects\n", (unsigned long)count);
        return 0;
    }

    /* Show directories only */
    if (strcmp(cmd, "dirs") == 0) {
        rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

        console_printf("========== MTP Directories ==========\n");
        console_printf("%-10s %-10s %-10s %s\n", "Handle", "Format", "Parent", "Name");
        console_printf("%s\n", "----------------------------------------------");

        uint32_t count = 0;
        for (uint32_t i = 0; i < MTP_HANDLE_POOL_SIZE; i++) {
            if (manager->objects[i].handle != 0 && manager->objects[i].is_dir) {
                mtp_object_t *obj = &manager->objects[i];

                char parent_str[16];
                if (obj->parent_handle == 0xFFFFFFFF) {
                    strcpy(parent_str, "ROOT");
                } else if (obj->parent_handle == 0) {
                    strcpy(parent_str, "-");
                } else {
                    snprintf(parent_str, sizeof(parent_str), "0x%08lx",
                             (unsigned long)obj->parent_handle);
                }

                console_printf("0x%08lx 0x%04x     %s %s\n",
                           (unsigned long)obj->handle,
                           obj->format,
                           parent_str,
                           obj->name);
                count++;
            }
        }

        rt_mutex_release(manager->mutex);

        console_printf("\nTotal: %lu directories\n", (unsigned long)count);
        return 0;
    }

    /* Show files only */
    if (strcmp(cmd, "files") == 0) {
        rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

        console_printf("========== MTP Files ==========\n");
        console_printf("%-10s %-6s %-10s %-10s %s\n",
                   "Handle", "Format", "Size", "Parent", "Name");
        console_printf("%s\n", "--------------------------------------------------------");

        uint32_t count = 0;
        uint32_t total_size = 0;
        for (uint32_t i = 0; i < MTP_HANDLE_POOL_SIZE; i++) {
            if (manager->objects[i].handle != 0 && !manager->objects[i].is_dir) {
                mtp_object_t *obj = &manager->objects[i];

                char parent_str[16];
                if (obj->parent_handle == 0xFFFFFFFF) {
                    strcpy(parent_str, "ROOT");
                } else if (obj->parent_handle == 0) {
                    strcpy(parent_str, "-");
                } else {
                    snprintf(parent_str, sizeof(parent_str), "0x%08lx",
                             (unsigned long)obj->parent_handle);
                }

                console_printf("0x%08lx %-6s %-10lu %s %s\n",
                           (unsigned long)obj->handle,
                           "FILE",
                           (unsigned long)obj->size,
                           parent_str,
                           obj->name);
                total_size += obj->size;
                count++;
            }
        }

        rt_mutex_release(manager->mutex);

        console_printf("\nTotal: %lu files, %lu bytes (%.2f KB)\n",
                   (unsigned long)count, (unsigned long)total_size, (float)total_size / 1024.0f);
        return 0;
    }

    /* Show specific handle details */
    if (argc == 2) {
        /* Try to parse as handle value */
        uint32_t handle = 0;
        if (strncmp(cmd, "0x", 2) == 0 || strncmp(cmd, "0X", 2) == 0) {
            handle = (uint32_t)strtoul(cmd, NULL, 16);
        } else {
            handle = (uint32_t)atoi(cmd);
        }

        if (handle != 0) {
            rt_mutex_take(manager->mutex, RT_WAITING_FOREVER);

            mtp_object_t *obj = NULL;
            int ret = mtp_find_object_by_handle_unlocked(manager, handle, &obj);

            if (ret == 0 && obj) {
                char path_buffer[CONFIG_USBDEV_MTP_MAX_PATHNAME];
                int path_ret = mtp_rebuild_full_path_unlocked(manager, handle,
                                                              path_buffer, sizeof(path_buffer));

                console_printf("========== MTP Object Details ==========\n");
                console_printf("Handle:     0x%08lx (%lu)\n",
                           (unsigned long)obj->handle, (unsigned long)obj->handle);
                console_printf("Name:       %s\n", obj->name);
                if (path_ret == 0) {
                    console_printf("Full Path:  %s\n", path_buffer);
                }
                console_printf("Storage ID: 0x%08lx\n", (unsigned long)obj->storage_id);
                console_printf("Parent:     0x%08lx %s\n",
                           (unsigned long)obj->parent_handle,
                           (obj->parent_handle == 0xFFFFFFFF) ? "(ROOT)" :
                           (obj->parent_handle == 0) ? "(NONE)" : "");
                console_printf("Format:     0x%04x\n", obj->format);
                console_printf("Type:       %s\n", obj->is_dir ? "Directory" : "File");
                console_printf("Size:       %lu bytes\n", (unsigned long)obj->size);
                console_printf("Hidden:     %s\n", obj->is_hidden ? "Yes" : "No");
                console_printf("Read-only:  %s\n", obj->is_readonly ? "Yes" : "No");
                console_printf("Timestamp:  %lu ticks\n", (unsigned long)obj->timestamp);

                /* Show child objects */
                if (obj->is_dir) {
                    uint32_t children[64];
                    uint32_t child_count = 0;

                    for (uint32_t i = 0; i < MTP_HANDLE_POOL_SIZE; i++) {
                        if (manager->objects[i].handle != 0 &&
                            manager->objects[i].parent_handle == handle) {
                            if (child_count < 64) {
                                children[child_count++] = manager->objects[i].handle;
                            }
                        }
                    }

                    if (child_count > 0) {
                        console_printf("\nChildren (%lu):\n", (unsigned long)child_count);
                        for (uint32_t i = 0; i < child_count; i++) {
                            mtp_object_t *child_obj = NULL;
                            if (mtp_find_object_by_handle_unlocked(manager, children[i], &child_obj) == 0) {
                                console_printf("  [0x%08lx] %s%s\n",
                                           (unsigned long)child_obj->handle,
                                           child_obj->name,
                                           child_obj->is_dir ? "/" : "");
                            }
                        }
                    }
                }

                rt_mutex_release(manager->mutex);
                return 0;
            } else {
                rt_mutex_release(manager->mutex);
                console_printf("Handle 0x%08lx not found\n", (unsigned long)handle);
                return -1;
            }
        }
    }

    /* Unknown command */
    console_printf("Usage:\n");
    console_printf("  mtp_obj           - Show overview\n");
    console_printf("  mtp_obj stat      - Show statistics\n");
    console_printf("  mtp_obj handles   - List all handles\n");
    console_printf("  mtp_obj dirs      - List directories\n");
    console_printf("  mtp_obj files     - List files\n");
    console_printf("  mtp_obj <handle>  - Show handle details\n");
    return -1;
}
MSH_CMD_EXPORT(msh_mtp_obj, MTP object manager status);
