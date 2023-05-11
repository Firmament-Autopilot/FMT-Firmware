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

#include "shell.h"
#include <firmament.h>
#include <string.h>

#include "hal/serial/serial.h"
#include "module/syscmd/syscmd.h"

extern struct finsh_shell* shell;

static uint8_t _is_option(char* str)
{
    if (strlen(str) < 2)
        return 0;

    if (str[0] == '-' && !(str[1] >= '0' && str[1] <= '9')) {
        // the case of negative number, like -3, -2.1, these are not options
        return 1;
    } else {
        return 0;
    }
}

bool syscmd_is_hex(const char* str)
{
    if (str == NULL)
        return false;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            continue;
        }

        if (str[i] >= 'a' && str[i] <= 'f') {
            continue;
        }

        if (str[i] >= 'A' && str[i] <= 'F') {
            continue;
        }

        return false;
    }

    return true;
}

bool syscmd_is_num(const char* str)
{
    uint8_t dot_cnt = 0;

    if (str == NULL)
        return false;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            continue;
        }

        if (str[i] == '.' && dot_cnt == 0) {
            dot_cnt++;
            continue;
        }

        if (str[i] == '-' && i == 0) {
            continue;
        }

        return false;
    }

    return true;
}

char syscmd_getc(void)
{
    char ch[SERIAL_RB_BUFSZ];
    // struct finsh_shell* shell = finsh_get_shell();

    syscmd_flush();

    if (rt_sem_take(&shell->rx_sem, RT_WAITING_FOREVER) != RT_EOK)
        return -1;

    rt_device_read(shell->device, 0, &ch, SERIAL_RB_BUFSZ);

    return ch[0];
}

bool syscmd_has_input(void)
{
    // struct finsh_shell* shell = finsh_get_shell();

    return rt_sem_trytake(&shell->rx_sem) == RT_EOK;
}

void syscmd_flush(void)
{
    // struct finsh_shell* shell = finsh_get_shell();

    char ch[SERIAL_RB_BUFSZ];
    rt_device_read(shell->device, 0, &ch, SERIAL_RB_BUFSZ);
}

void syscmd_putc(const char c, int cnt)
{
    while (cnt--)
        console_write(&c, 1);
}

void syscmd_printf(const char pad, uint32_t len, uint8_t align, const char* fmt, ...)
{
    va_list args;
    char buffer[100];
    int length;

    va_start(args, fmt);
    length = vsprintf(buffer, fmt, args);
    va_end(args);

    if (len <= length) {
        console_write(buffer, length);
        return;
    }

    if (align == SYSCMD_ALIGN_LEFT) {
        console_write(buffer, length);
        syscmd_putc(pad, len - length);
    } else if (align == SYSCMD_ALIGN_MIDDLE) {
        uint32_t hl = (len - length + 1) / 2;
        syscmd_putc(pad, hl);
        console_write(buffer, length);
        syscmd_putc(pad, (len - length) - hl);
    } else {
        syscmd_putc(pad, len - length);
        console_write(buffer, length);
    }
}

int syscmd_process(int argc, char** argv, shell_handle_func func)
{
    int res = 1;
    int arg_c = 0;
    int opt_c = 0;
    char** arg_v = NULL;
    optv_t* opt_v = NULL;

    // pre-process to determine arguments and options count
    for (int i = 0; i < argc; i++) {
        if (_is_option(argv[i])) {
            opt_c++;
        } else {
            arg_c++;
        }
    }

    arg_v = (char**)rt_malloc(arg_c * sizeof(char*));

    if (arg_v == NULL)
        return -1;

    if (opt_c) {
        opt_v = (optv_t*)rt_malloc(opt_c * sizeof(optv_t));

        if (opt_v == NULL) {
            rt_free(arg_v);
            return -1;
        }
    }

    int arg_cnt = 0;
    int opt_cnt = 0;

    // process for arguments and options
    for (int i = 0; i < argc; i++) {
        if (_is_option(argv[i])) {
            /* handle option */
            int argv_len = strlen(argv[i]);
            int opt_len = argv_len;
            int val_len = 0;
            int val_start = 0;

            // find option value if existed
            for (int n = 1; n < argv_len - 1; n++) {
                if (argv[i][n] == '=') {
                    val_start = n + 1;
                    opt_len = n;
                    break;
                }
            }

            // parse opt value
            if (val_start) {
                int pos = val_start;

                // handle string
                if (argv[i][pos] == '"') {
                    pos++;
                    val_start = pos;

                    while (pos < argv_len) {
                        if (argv[i][pos] == '"') {
                            val_len = pos - val_start;
                            break;
                        }

                        pos++;
                    }
                } else {
                    val_len = argv_len - val_start;
                }
            }

            // set opt
            opt_v[opt_cnt].opt = (char*)rt_malloc(opt_len + 1); // 1byte for '\0'

            if (opt_v[opt_cnt].opt == NULL) {
                console_printf("opt malloc err\n");
                goto opt_release;
            }

            memcpy(opt_v[opt_cnt].opt, argv[i], opt_len);
            opt_v[opt_cnt].opt[opt_len] = '\0';

            // set opt val
            if (val_len) {
                opt_v[opt_cnt].val = (char*)rt_malloc(val_len + 1);

                if (opt_v[opt_cnt].val == NULL) {
                    console_printf("opt val malloc err\n");
                    goto opt_release;
                }

                memcpy(opt_v[opt_cnt].val, &argv[i][val_start], val_len);
                opt_v[opt_cnt].val[val_len] = '\0';
            } else {
                opt_v[opt_cnt].val = NULL;
            }

            //console_printf("opt:%s val:%s\n", opt_v[opt_cnt].opt, opt_v[opt_cnt].val);

            opt_cnt++;
        } else {
            /* handle argument */
            int arg_len = strlen(argv[i]);

            arg_v[arg_cnt] = (char*)rt_malloc(arg_len + 1);

            if (arg_v[arg_cnt] == NULL) {
                console_printf("arg malloc err\n");
                goto opt_release;
            }

            memcpy(arg_v[arg_cnt], argv[i], arg_len);
            arg_v[arg_cnt][arg_len] = '\0';

            //console_printf("arg:%s\n", arg_v[arg_cnt]);

            arg_cnt++;
        }
    }

    // invoke handle function
    if (func != NULL) {
        res = func(arg_c, arg_v, opt_c, opt_v);
    }

opt_release:

    // release memory
    if (arg_v != NULL) {
        for (int i = 0; i < arg_c; i++) {
            if (arg_v[i] != NULL) {
                rt_free(arg_v[i]);
            }
        }

        rt_free(arg_v);
    }

    if (opt_v != NULL) {
        for (int i = 0; i < opt_c; i++) {
            if (opt_v[i].opt != NULL) {
                rt_free(opt_v[i].opt);
            }

            if (opt_v[i].val != NULL) {
                rt_free(opt_v[i].val);
            }
        }

        rt_free(opt_v);
    }

    return res;
}
