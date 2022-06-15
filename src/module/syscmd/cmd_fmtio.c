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
#include <string.h>

#include "hal/fmtio_dev/fmtio_dev.h"
#include "hal/serial/serial.h"
#include "module/fmtio/fmtio.h"
#include "module/fmtio/fmtio_uploader.h"
#include "module/syscmd/syscmd.h"

static void show_usage(void)
{
    PRINT_USAGE(fmtio, [OPTION] ACTION[ARGS]);

    PRINT_STRING("\nAction:\n");
    PRINT_ACTION("upload", 6, "Upload firmware to FMT IO.");
    PRINT_ACTION("config", 6, "Configure FMT IO.");
    PRINT_ACTION("hello", 6, "Say hello to FMT IO.");

    PRINT_STRING("\nOption:\n");
    PRINT_ACTION("-h, --help", 13, "Show command usage.");
    PRINT_ACTION("--baud-rate", 13, "Config serial baud rate.");
    PRINT_ACTION("--rc-chan-num", 13, "Config RC channel number.");
    PRINT_ACTION("--pwm-freq", 13, "Config pwm output frequency.");
}

static int handle_cmd(int argc, char** argv, int optc, optv_t* optv)
{
    /* handle operation */
    for (uint16_t i = 0; i < optc; i++) {
        if (STRING_COMPARE(optv[i].opt, "-h") || STRING_COMPARE(optv[i].opt, "--help")) {
            show_usage();
            return 0;
        }
    }

    if (argc >= 2) {
        if (STRING_COMPARE(argv[1], "upload")) {
            if (argc >= 3) {
                fmtio_upload(argv[2]);
            } else {
                fmtio_upload(NULL);
            }
        } else if (STRING_COMPARE(argv[1], "hello")) {
            /* say hello to fmt io */
            // fmtio_send_cmd(PROTO_DBG_TEXT, "hello", strlen("hello"));
            send_io_cmd(IO_CODE_DBG_TEXT, "hello", strlen("hello"));
        } else {
            show_usage();
        }
    } else {
        show_usage();
    }

    return 0;
}

int cmd_fmtio(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_cmd);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_fmtio, __cmd_fmtio, FMT IO commands);