/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

#include "module/file_manager/file_manager.h"
#include "module/mavproxy/mavproxy.h"

#define MAVLOG_ROOT_DIR     "/log"
#define MAVLOG_MAX_FILE_NUM 256
#define MAVLOG_MAX_PATH_LEN 100

typedef struct {
    char path[MAVLOG_MAX_PATH_LEN];
    uint32_t size;
    uint32_t time_utc;
} mavlog_file_info_t;

static mavlog_file_info_t mavlog_file_table[MAVLOG_MAX_FILE_NUM];
static uint16_t mavlog_file_num;
static bool mavlog_cancel;
static int mavlog_download_fd = -1;
static uint16_t mavlog_download_id = 0xFFFF;
static uint32_t mavlog_download_ofs;

static void close_mlog_download_fd(void)
{
    if (mavlog_download_fd >= 0) {
        close(mavlog_download_fd);
        mavlog_download_fd = -1;
    }

    mavlog_download_id = 0xFFFF;
    mavlog_download_ofs = 0;
}

static bool is_mlog_file(const char* file_name)
{
    uint16_t name_len;

    if (file_name == NULL) {
        return false;
    }

    name_len = strlen(file_name);
    if (name_len < 8) {
        return false;
    }

    if (strncmp(file_name, "mlog", 4) != 0) {
        return false;
    }

    return strcmp(&file_name[name_len - 4], ".bin") == 0;
}

static void record_mlog_file(const char* path, const struct stat* sta)
{
    if (mavlog_file_num >= MAVLOG_MAX_FILE_NUM || path == NULL || sta == NULL) {
        return;
    }

    strncpy(mavlog_file_table[mavlog_file_num].path, path, MAVLOG_MAX_PATH_LEN - 1);
    mavlog_file_table[mavlog_file_num].path[MAVLOG_MAX_PATH_LEN - 1] = '\0';
    mavlog_file_table[mavlog_file_num].size = (uint32_t)sta->st_size;
    mavlog_file_table[mavlog_file_num].time_utc = sta->st_mtime > 0 ? (uint32_t)sta->st_mtime : 0;
    mavlog_file_num++;
}

static int compare_mlog_file_info(const void* lhs, const void* rhs)
{
    const mavlog_file_info_t* left = (const mavlog_file_info_t*)lhs;
    const mavlog_file_info_t* right = (const mavlog_file_info_t*)rhs;

    int cmp = strcmp(left->path, right->path);
    if (cmp != 0) {
        return cmp;
    }

    if (left->time_utc < right->time_utc) {
        return -1;
    }

    if (left->time_utc > right->time_utc) {
        return 1;
    }

    if (left->size < right->size) {
        return -1;
    }

    if (left->size > right->size) {
        return 1;
    }

    return 0;
}

static void scan_mlog_folder(const char* dir_path)
{
    DIR* dir;
    struct dirent* de;

    if (dir_path == NULL) {
        return;
    }

    dir = opendir(dir_path);
    if (dir == NULL) {
        return;
    }

    while ((de = readdir(dir)) != NULL) {
        char full_path[MAVLOG_MAX_PATH_LEN];
        struct stat sta;
        bool is_dir;

        if (de->d_name[0] == '.') {
            continue;
        }

        if (snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, de->d_name) >= sizeof(full_path)) {
            continue;
        }

        if (stat(full_path, &sta) < 0) {
            continue;
        }

        is_dir = (de->d_type == FT_DIRECTORY) || ((sta.st_mode & S_IFMT) == S_IFDIR);
        if (is_dir) {
            scan_mlog_folder(full_path);
            continue;
        }

        if (is_mlog_file(de->d_name)) {
            record_mlog_file(full_path, &sta);
        }
    }

    closedir(dir);
}

static void refresh_mlog_file_list(void)
{
    mavlog_file_num = 0;
    memset(mavlog_file_table, 0, sizeof(mavlog_file_table));
    scan_mlog_folder(MAVLOG_ROOT_DIR);

    if (mavlog_file_num > 1) {
        qsort(mavlog_file_table, mavlog_file_num, sizeof(mavlog_file_table[0]), compare_mlog_file_info);
    }
}

static void send_log_entry(uint16_t id, uint16_t num_logs, uint16_t last_log_num, uint32_t time_utc, uint32_t size, uint8_t chan)
{
    mavlink_system_t mav_sys = mavproxy_get_system();
    mavlink_message_t msg;

    mavlink_msg_log_entry_pack(mav_sys.sysid,
                               mav_sys.compid,
                               &msg,
                               id,
                               num_logs,
                               last_log_num,
                               time_utc,
                               size);

    mavproxy_send_immediate_msg(chan, &msg, true);
}

static void send_log_data(uint16_t id, uint32_t ofs, uint8_t count, const uint8_t* data, uint8_t chan)
{
    mavlink_system_t mav_sys = mavproxy_get_system();
    mavlink_message_t msg;

    mavlink_msg_log_data_pack(mav_sys.sysid,
                              mav_sys.compid,
                              &msg,
                              id,
                              ofs,
                              count,
                              data);

    mavproxy_send_immediate_msg(chan, &msg, true);
}

void handle_log_request_list(mavlink_message_t* msg, mavlink_system_t this_system, uint8_t chan)
{
    mavlink_log_request_list_t request = { 0 };
    uint16_t start;
    uint16_t end;

    mavlink_msg_log_request_list_decode(msg, &request);

    if (request.target_system != this_system.sysid) {
        return;
    }

    mavlog_cancel = false;
    refresh_mlog_file_list();

    if (mavlog_file_num == 0) {
        send_log_entry(0, 0, 0, 0, 0, chan);
        return;
    }

    start = request.start;
    end = request.end;

    if (start >= mavlog_file_num) {
        start = mavlog_file_num - 1;
    }

    if (end == 0xFFFF || end >= mavlog_file_num) {
        end = mavlog_file_num - 1;
    }

    if (start > end) {
        return;
    }

    for (uint16_t id = start; id <= end; id++) {
        send_log_entry(id,
                       mavlog_file_num,
                       mavlog_file_num - 1,
                       mavlog_file_table[id].time_utc,
                       mavlog_file_table[id].size,
                       chan);
    }
}

void handle_log_request_data(mavlink_message_t* msg, mavlink_system_t this_system, uint8_t chan)
{
    mavlink_log_request_data_t request = { 0 };
    uint8_t data[MAVLINK_MSG_LOG_DATA_FIELD_DATA_LEN] = { 0 };
    uint32_t remaining;
    uint32_t offset;

    mavlink_msg_log_request_data_decode(msg, &request);

    if (request.target_system != this_system.sysid) {
        return;
    }

    if (mavlog_cancel) {
        return;
    }

    if (request.id >= mavlog_file_num) {
        return;
    }

    if (request.ofs >= mavlog_file_table[request.id].size) {
        send_log_data(request.id, request.ofs, 0, data, chan);
        return;
    }

    if (mavlog_download_id != request.id || mavlog_download_fd < 0) {
        close_mlog_download_fd();
        mavlog_download_fd = open(mavlog_file_table[request.id].path, O_RDONLY);
        if (mavlog_download_fd < 0) {
            return;
        }
        mavlog_download_id = request.id;
    }

    if (mavlog_download_ofs != request.ofs) {
        if (lseek(mavlog_download_fd, request.ofs, SEEK_SET) < 0) {
            close_mlog_download_fd();
            return;
        }
        mavlog_download_ofs = request.ofs;
    }

    remaining = request.count;
    if (remaining > (mavlog_file_table[request.id].size - request.ofs)) {
        remaining = mavlog_file_table[request.id].size - request.ofs;
    }

    offset = request.ofs;
    while (remaining > 0 && !mavlog_cancel) {
        uint8_t read_size = remaining > MAVLINK_MSG_LOG_DATA_FIELD_DATA_LEN ? MAVLINK_MSG_LOG_DATA_FIELD_DATA_LEN : (uint8_t)remaining;
        int rb = read(mavlog_download_fd, data, read_size);

        if (rb <= 0) {
            break;
        }

        send_log_data(request.id, offset, (uint8_t)rb, data, chan);

        offset += rb;
        remaining -= rb;
        mavlog_download_ofs = offset;
    }
}

void handle_log_erase(mavlink_message_t* msg, mavlink_system_t this_system)
{
    mavlink_log_erase_t request = { 0 };

    mavlink_msg_log_erase_decode(msg, &request);

    if (request.target_system != this_system.sysid) {
        return;
    }

    mavlog_cancel = true;
    close_mlog_download_fd();
    refresh_mlog_file_list();

    for (uint16_t i = 0; i < mavlog_file_num; i++) {
        unlink(mavlog_file_table[i].path);
    }

    refresh_mlog_file_list();
    mavlog_cancel = false;
}

void handle_log_request_end(mavlink_message_t* msg, mavlink_system_t this_system)
{
    mavlink_log_request_end_t request = { 0 };

    mavlink_msg_log_request_end_decode(msg, &request);

    if (request.target_system != this_system.sysid) {
        return;
    }

    mavlog_cancel = true;
    close_mlog_download_fd();
}
