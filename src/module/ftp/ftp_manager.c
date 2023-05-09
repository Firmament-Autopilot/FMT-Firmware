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
#include <firmament.h>

#include "module/file_manager/file_manager.h"
#include "module/ftp/ftp_manager.h"
#include "module/mavproxy/mavproxy.h"

#define TAG "MAV_FTP"

// #define DBG_ENABLE

#ifdef DBG_ENABLE
    #define FTP_DBG(...) ulog_d(TAG, __VA_ARGS__)
#else
    #define FTP_DBG(...)
#endif

#define MAX_DIR_PATH_LEN 268

static const char kDirentFile = 'F'; ///< Identifies File returned from List command
static const char kDirentDir = 'D';  ///< Identifies Directory returned from List command
static const char kDirentSkip = 'S'; ///< Identifies Skipped entry from List command

static uint8_t _errno;
// static FIL _fp;
static int _fd = -1;
static StreamSession _stream_session = {
    .fd = -1,
};

/**************************** Local Function ********************************/

static uint8_t _request_list(FTP_Msg_Payload* payload)
{
    char dir_buffer[MAX_DIR_PATH_LEN + 1] = { 0 };
    char cur_path[50] = { 0 };
    char direntType;
    DIR* dir;
    struct dirent* de;
    uint8_t error = kErrNone;
    uint16_t size = 0;

    FTP_DBG("list %s, offset:%d", payload->data, payload->offset);

    if (payload->size > MAX_DIR_PATH_LEN) {
        FTP_DBG("path of root dir is too long:%d\n", payload->size);
        return kErrEOF;
    }

    strcpy(cur_path, payload->data);

    // console_printf("cur path:%s size:%d offset:%d\n", payload->data,payload->size, payload->offset);

    dir = opendir(cur_path);

    if (dir == NULL) {
        FTP_DBG("dir open fail");
        return kErrEOF;
    }

    uint32_t dir_offset = payload->offset;

    while (dir_offset--) {
        readdir(dir);
    }

    // seekdir(dir, payload->offset);

    while (1) {

        de = readdir(dir);

        if (de == NULL) {
#ifdef DBG_ENABLE

            for (int i = 0; i < size; i++) {
                if (payload->data[i] == '\0') {
                    console_printf("\\0");
                } else if (payload->data[i] == '\t') {
                    console_printf("\\t");
                } else {
                    console_printf("%c", payload->data[i]);
                }
            }

            console_printf("\n");
#endif

            if (size == 0) {
                error = kErrEOF;
            }

            break;
        }

        /* check if has enough space to add entry */
        uint16_t len;

        if (de->d_type == FT_DIRECTORY) {
            direntType = kDirentDir;
            strcpy(dir_buffer, de->d_name);
            len = de->d_namlen;
        } else if (de->d_name[0] == '.') {
            direntType = kDirentSkip;
            len = 0;
        } else {
            struct stat sta;
            direntType = kDirentFile;
            sprintf(dir_buffer, "%s/%s", cur_path, de->d_name);

            if (stat(dir_buffer, &sta) < 0) {
                console_printf("%s stat fail\n", dir_buffer);
                _errno = rt_get_errno();
                return kErrFailErrno;
            }

            sprintf(dir_buffer, "%s\t%ld", de->d_name, sta.st_size);
            len = strlen(dir_buffer);
        }

        /* 1 byte for type and 1byte for \0 */
        if (size + len + 2 > MAX_FTP_DATA_LEN) {
            error = kErrNone;
            break;
        }

        /* <type><file_or_folder_name>\t<file_size_in_bytes>\0 */
        payload->data[size++] = direntType;

        if (direntType == kDirentSkip) {
            payload->data[size++] = '\0';
        } else {
            strcpy(&payload->data[size], dir_buffer);
            size += len;
            payload->data[size++] = '\0';
        }
    }

    payload->size = size;
    closedir(dir);

    FTP_DBG("err code:%d, size:%d", error, payload->size);

    return error;
}

static uint8_t _request_open(FTP_Msg_Payload* payload, int oflag)
{
    char file_name[MAX_DIR_PATH_LEN + 1];
    struct stat fno;

    FTP_DBG("open file:%s, oflag:%x", payload->data, oflag);

    if (_stream_session.fd >= 0 && _stream_session.complete) {
        close(_stream_session.fd);
        _stream_session.fd = -1;
        _stream_session.file_size = 0;
    }

    if (_stream_session.fd >= 0) {
        FTP_DBG("no available session\n");
        return kErrNoSessionsAvailable;
    }

    strncpy(file_name, payload->data, payload->size);
    file_name[payload->size] = '\0';

    if (stat(file_name, &fno) < 0 && !(oflag & O_CREAT)) {
        FTP_DBG("no file existed\n");
        _errno = rt_get_errno();
        return kErrFailErrno;
    }

    _fd = open(file_name, oflag);

    if (_fd < 0) {
        _errno = rt_get_errno();
        FTP_DBG("open fail:%d", _errno);
        return kErrFailErrno;
    }

    payload->session = 0;
    payload->size = sizeof(uint32_t);
    memcpy(payload->data, &fno.st_size, payload->size);

    _stream_session.fd = _fd;
    _stream_session.file_size = fno.st_size;

    FTP_DBG("open success, fd:%d", _stream_session.fd);

    return kErrNone;
}

static uint8_t _request_burst(FTP_Msg_Payload* payload, uint8_t target_system, uint8_t target_component)
{
    if (payload->session != 0 || _stream_session.fd < 0) {
        FTP_DBG("no valid session:%d fd:%d\n", payload->session, _stream_session.fd);
        return kErrInvalidSession;
    }

    _stream_session.stream_seq_number = payload->seq_number + 1;
    _stream_session.stream_offset = payload->offset;
    _stream_session.stream_target_system_id = target_system;
    _stream_session.stream_target_component_id = target_component;
    _stream_session.complete = 0;

    mavproxy_cmd_set(MAVCMD_STREAM_SESSION, &_stream_session);

    FTP_DBG("burst read, session seq:%d offset:%d sys_id:%d comp_id:%d", _stream_session.stream_seq_number, _stream_session.stream_offset, _stream_session.stream_target_system_id, _stream_session.stream_target_component_id);

    return kErrNone;
}

static uint8_t _request_read(FTP_Msg_Payload* payload)
{
    // FRESULT fres;
    // UINT br;
    int br;

    FTP_DBG("read %s, offset:%d fd:%d", payload->data, payload->offset, _stream_session.fd);

    if (payload->session != 0 || _stream_session.fd < 0) {
        FTP_DBG("no valid session:%d fd:%d", payload->session, _stream_session.fd);
        return kErrInvalidSession;
    }

    if (payload->offset >= _stream_session.file_size) {
        /* request past EOF */
        FTP_DBG("request past EOF offset:%d file size:%d", payload->offset, _stream_session.file_size);
        return kErrEOF;
    }

    // fres = f_lseek(_stream_session.fd, payload->offset);
    off_t off = lseek(_stream_session.fd, payload->offset, SEEK_SET);

    if (off != payload->offset) {
        _errno = rt_get_errno();
        return kErrFailErrno;
    }

    // fres = f_read(_stream_session.fd, payload->data, MAX_FTP_DATA_LEN, &br);
    br = read(_stream_session.fd, payload->data, MAX_FTP_DATA_LEN);

    if (br != MAX_FTP_DATA_LEN) {
        _errno = rt_get_errno();
        return kErrFailErrno;
    }

    payload->size = br;

    if (br == 0) {
        return kErrEOF;
    }

    FTP_DBG("read complete");
    return kErrNone;
}

static uint8_t _request_write(FTP_Msg_Payload* payload)
{
    // FRESULT fres;
    // UINT bw;
    int bw;

    if (payload->session != 0 && _stream_session.fd < 0) {
        return kErrInvalidSession;
    }

    // fres = f_lseek(_stream_session.fd, payload->offset);
    off_t off = lseek(_stream_session.fd, payload->offset, SEEK_SET);

    if (off != payload->offset) {
        _errno = rt_get_errno();
        return kErrFailErrno;
    }

    // if(fres != FR_OK) {
    // 	_errno = fres;
    // 	return kErrFailErrno;
    // }

    // fres = f_write(_stream_session.fd, payload->data, payload->size, &bw);
    bw = write(_stream_session.fd, payload->data, payload->size);

    if (bw != payload->size) {
        _errno = rt_get_errno();
        return kErrFailErrno;
    }

    payload->size = sizeof(uint32_t);
    memcpy(payload->data, &bw, payload->size);

    return kErrNone;
}

static uint8_t _request_terminate(FTP_Msg_Payload* payload)
{
    if (payload->session != 0 || _stream_session.fd < 0) {
        return kErrInvalidSession;
    }

    // f_close(_stream_session.fd);
    close(_stream_session.fd);
    _stream_session.fd = -1;
    _stream_session.file_size = 0;

    mavproxy_cmd_reset(MAVCMD_STREAM_SESSION);

    payload->size = 0;

    return kErrNone;
}

static uint8_t _request_reset(FTP_Msg_Payload* payload)
{

    if (_stream_session.fd) {
        // f_close(_stream_session.fd);
        close(_stream_session.fd);
        _stream_session.fd = -1;
        _stream_session.file_size = 0;

        mavproxy_cmd_reset(MAVCMD_STREAM_SESSION);
    }

    payload->size = 0;

    return kErrNone;
}

/**************************** Public Function ********************************/

fmt_err_t ftp_process_request(uint8_t* payload, uint8_t target_system, uint8_t target_component)
{
    uint8_t err_code;
    FTP_Msg_Payload* ftp_payload = (FTP_Msg_Payload*)payload;

    FTP_DBG("session:%d opcode:%d seq:%d size:%d", ftp_payload->session, ftp_payload->opcode, ftp_payload->seq_number, ftp_payload->size);

    switch (ftp_payload->opcode) {
    case kCmdTerminateSession: {
        err_code = _request_terminate(ftp_payload);
    } break;

    case kCmdResetSessions: {
        err_code = _request_reset(ftp_payload);
    } break;

    case kCmdListDirectory: {
        err_code = _request_list(ftp_payload);
    } break;

    case kCmdOpenFileRO: {
        err_code = _request_open(ftp_payload, O_RDONLY);
    } break;

    case kCmdCreateFile: {
        err_code = _request_open(ftp_payload, O_CREAT | O_TRUNC | O_WRONLY);
    } break;

    case kCmdOpenFileWO: {
        err_code = _request_open(ftp_payload, O_WRONLY);
    } break;

    case kCmdReadFile: {
        err_code = _request_read(ftp_payload);
    } break;

    case kCmdBurstReadFile: {
        err_code = _request_burst(ftp_payload, target_system, target_component);
        /* do not need send ack here */
        return FMT_ENOTHANDLE;
    } break;

    case kCmdWriteFile: {
        err_code = _request_write(ftp_payload);
    } break;

    default: {
        console_printf("ftp unknow opcode:%d\n", ftp_payload->opcode);
        return FMT_ENOTHANDLE;
    }
    }

    ftp_payload->seq_number++;

    if (err_code == kErrNone) {
        ftp_payload->req_opcode = ftp_payload->opcode;
        ftp_payload->opcode = kRspAck;
    } else {
        ftp_payload->req_opcode = ftp_payload->opcode;
        ftp_payload->opcode = kRspNak;
        ftp_payload->size = 1;
        ftp_payload->data[0] = err_code;

        if (err_code == kErrFailErrno) {
            ftp_payload->size = 2;
            ftp_payload->data[1] = _errno;
        }
    }

    return FMT_EOK;
}

fmt_err_t ftp_stream_send(StreamSession* stream_session)
{
    mavlink_file_transfer_protocol_t ftp_protocol_t;
    FTP_Msg_Payload* ftp_msg_t = (FTP_Msg_Payload*)ftp_protocol_t.payload;
    mavlink_message_t msg;
    // FRESULT fres;
    // UINT br;
    uint8_t err_code = kCmdNone;
    uint8_t err_no;
    mavlink_system_t system;
    int br;

    FTP_DBG("send stream, seq:%d offset:%d fd:%d", stream_session->stream_seq_number, stream_session->stream_offset, stream_session->fd);

    if (stream_session->fd < 0) {
        FTP_DBG("no valid session");
        return FMT_ERROR;
    }

    ftp_msg_t->seq_number = stream_session->stream_seq_number;
    ftp_msg_t->offset = stream_session->stream_offset;
    ftp_msg_t->session = 0;
    ftp_msg_t->burst_complete = 0;
    ftp_msg_t->opcode = kRspAck;
    ftp_msg_t->req_opcode = kCmdBurstReadFile;

    stream_session->stream_seq_number++;

    if (ftp_msg_t->offset >= stream_session->file_size) {
        /* stream session complete */
        mavproxy_cmd_reset(MAVCMD_STREAM_SESSION);

        stream_session->complete = 1;

        err_code = kErrEOF;

        FTP_DBG("stream session complete");
        goto Out;
    }

    // fres = f_lseek(stream_session->fd, ftp_msg_t->offset);
    // if(fres != FR_OK) {
    // 	err_code = kErrFailErrno;
    // 	err_no = fres;
    // 	goto Out;
    // }

    off_t off = lseek(stream_session->fd, ftp_msg_t->offset, SEEK_SET);

    if (off != ftp_msg_t->offset) {
        err_no = rt_get_errno();
        err_code = kErrFailErrno;

        FTP_DBG("seek fail:%d, offset:%d cur_offset:%d", err_no, ftp_msg_t->offset, off);
        goto Out;
    }

    // fres = f_read(stream_session->fd, ftp_msg_t->data, MAX_FTP_DATA_LEN, &br);
    size_t len_to_read = stream_session->file_size - ftp_msg_t->offset;
    len_to_read = len_to_read > MAX_FTP_DATA_LEN ? MAX_FTP_DATA_LEN : len_to_read;
    br = read(stream_session->fd, ftp_msg_t->data, len_to_read);

    // if(fres != FR_OK) {
    // 	err_code = kErrFailErrno;
    // 	err_no = fres;
    // 	goto Out;
    // }

    if (br != len_to_read) {
        err_code = kErrFailErrno;
        err_no = rt_get_errno();

        FTP_DBG("read fail:%d, len:%d br:%d", err_no, len_to_read, br);
        goto Out;
    }

    ftp_msg_t->size = br;

Out:

    if (err_code == kErrNone) {
        ftp_msg_t->opcode = kRspAck;
        stream_session->stream_offset += ftp_msg_t->size;

        if (stream_session->stream_offset >= stream_session->file_size) {
            ftp_msg_t->burst_complete = 1;
        }

        FTP_DBG("RspAck, size:%d offset:%d complete:%d", ftp_msg_t->size, stream_session->stream_offset, ftp_msg_t->burst_complete);
    } else {
        ftp_msg_t->opcode = kRspNak;
        ftp_msg_t->size = 1;
        ftp_msg_t->data[0] = err_code;

        FTP_DBG("err code:%d", ftp_msg_t->data[0]);

        if (err_code == kErrFailErrno) {
            ftp_msg_t->size = 2;
            ftp_msg_t->data[1] = err_no;

            FTP_DBG("err no:%d", ftp_msg_t->data[1]);
        }
    }

    ftp_protocol_t.target_system = _stream_session.stream_target_system_id;
    ftp_protocol_t.target_component = _stream_session.stream_target_component_id;
    ftp_protocol_t.target_network = 0;

    system = mavproxy_get_system();

    mavlink_msg_file_transfer_protocol_encode(system.sysid, system.compid, &msg, &ftp_protocol_t);
    mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, true);

    return FMT_EOK;
}
