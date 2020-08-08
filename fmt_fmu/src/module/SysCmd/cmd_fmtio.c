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

#include "hal/fmtio_dev.h"
#include "hal/serial.h"
#include "module/fmtio/fmtio_uploader.h"
#include "module/syscmd/syscmd.h"
#include "task/task_fmtio.h"

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
	uint32_t baud_rate = 0;
	uint16_t rc_chan_num = 0;
	uint16_t pwm_freq = 0;

	/* handle operation */
	for(uint16_t i = 0; i < optc; i++) {
		if(STRING_COMPARE(optv[i].opt, "-h") || STRING_COMPARE(optv[i].opt, "--help")) {
			show_usage();
			return 0;
		}

		if(STRING_COMPARE(optv[i].opt, "--baud-rate")) {
			if(syscmd_is_num(optv[i].val)) {
				baud_rate = atoi(optv[i].val);
			}
		}

		if(STRING_COMPARE(optv[i].opt, "--rc-chan-num")) {
			if(syscmd_is_num(optv[i].val)) {
				rc_chan_num = atoi(optv[i].val);
			}
		}

		if(STRING_COMPARE(optv[i].opt, "--pwm-freq")) {
			if(syscmd_is_num(optv[i].val)) {
				pwm_freq = atoi(optv[i].val);
			}
		}
	}

	if(argc >= 2) {
		if(STRING_COMPARE(argv[1], "upload")) {
			if(argc >= 3) {
				fmtio_upload(argv[2]);
			} else {
				fmtio_upload(NULL);
			}
		} else if(STRING_COMPARE(argv[1], "hello")) {
			/* say hello to fmt io */
			fmtio_send_message(PROTO_DBG_TEXT, "hello", strlen("hello"));
		} else if(STRING_COMPARE(argv[1], "config")) {
			/* config fmt io */
			fmtio_config(baud_rate, rc_chan_num, pwm_freq);

			if(baud_rate) {
				struct serial_configure serial_config = RT_SERIAL4_CONFIG;
				serial_config.baud_rate = baud_rate;

				// this is tricky, we need wait config msg send finish
				rt_thread_delay(50);
				rt_device_control(fmtio_get_device(), FMTIO_DEV_CMD_CONFIG, &serial_config);
			}
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