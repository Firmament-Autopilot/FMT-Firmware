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

#ifndef FTP_MANAGER_H__
#define FTP_MANAGER_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_FTP_DATA_LEN 239

__PACKED__(
    typedef struct {
        uint16_t seq_number;    ///< sequence number for message
        uint8_t session;        ///< Session id for read and write commands
        uint8_t opcode;         ///< Command opcode
        uint8_t size;           ///< Size of data
        uint8_t req_opcode;     ///< Request opcode returned in kRspAck, kRspNak message
        uint8_t burst_complete; ///< Only used if req_opcode=kCmdBurstReadFile - 1: set of burst packets complete, 0: More burst packets coming.
        uint8_t padding;        ///< 32 bit aligment padding
        uint32_t offset;        ///< Offsets for List and Read commands
        char data[];            ///< command data, varies by Opcode
    })
FTP_Msg_Payload;

enum Opcode {
    kCmdNone = 0,         ///< ignored, always acked
    kCmdTerminateSession, ///< Terminates open Read session
    kCmdResetSessions,    ///< Terminates all open Read sessions
    kCmdListDirectory,    ///< List files in <path> from <offset>
    kCmdOpenFileRO,       ///< Opens file at <path> for reading, returns <session>
    kCmdReadFile,         ///< Reads <size> bytes from <offset> in <session>
    kCmdCreateFile,       ///< Creates file at <path> for writing, returns <session>
    kCmdWriteFile,        ///< Writes <size> bytes to <offset> in <session>
    kCmdRemoveFile,       ///< Remove file at <path>
    kCmdCreateDirectory,  ///< Creates directory at <path>
    kCmdRemoveDirectory,  ///< Removes Directory at <path>, must be empty
    kCmdOpenFileWO,       ///< Opens file at <path> for writing, returns <session>
    kCmdTruncateFile,     ///< Truncate file at <path> to <offset> length
    kCmdRename,           ///< Rename <path1> to <path2>
    kCmdCalcFileCRC32,    ///< Calculate CRC32 for file at <path>
    kCmdBurstReadFile,    ///< Burst download session file

    kRspAck = 128, ///< Ack response
    kRspNak        ///< Nak response
};

enum ErrorCode {
    kErrNone,
    kErrFail,                ///< Unknown failure
    kErrFailErrno,           ///< Command failed, errno sent back in PayloadHeader.data[1]
    kErrInvalidDataSize,     ///< PayloadHeader.size is invalid
    kErrInvalidSession,      ///< Session is not currently open
    kErrNoSessionsAvailable, ///< All available Sessions in use
    kErrEOF,                 ///< Offset past end of file for List and Read commands
    kErrUnknownCommand,      ///< Unknown command opcode
    kErrFailFileExists,      ///< File exists already
    kErrFailFileProtected    ///< File is write protected
};

typedef struct {
    int fd;
    uint32_t file_size;
    uint32_t stream_offset;
    uint16_t stream_seq_number;
    uint8_t stream_target_system_id;
    uint8_t stream_target_component_id;
    uint8_t complete;
} StreamSession;

fmt_err_t ftp_process_request(uint8_t* payload, uint8_t target_system, uint8_t target_component);
fmt_err_t ftp_stream_send(StreamSession* stream_session);

#ifdef __cplusplus
}
#endif

#endif