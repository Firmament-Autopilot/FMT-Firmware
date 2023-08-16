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

#include "ar1002_chip.h"
#include "ar1002_hal.h"
#include "factory.h"
#include "module/mavproxy/mavproxy.h"
#include "module/mavproxy/mavproxy_config.h"
#include "module/syscmd/optparse.h"
#include "module/syscmd/syscmd.h"

////////////////////////////////////////////////////////////////////////////
// reboot
static int handle_reboot_cmd(int argc, char** argv, int optc, optv_t* optv)
{
    printf("rebooting...\n");
    printf("chuanyun will reboot in 3 seconds\n");

    sys_msleep(1000);
    printf("chuanyun will reboot in 2 seconds\n");
    sys_msleep(1000);

    printf("chuanyun will reboot in 1 seconds\n");
    sys_msleep(1000);

    printf("goodbye ~~~~~\n");

    HAL_GPIO_SetPin(HAL_GPIO_NUM74, HAL_GPIO_PIN_RESET);

    return 0;
}

int cmd_reboot(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_reboot_cmd);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_reboot, __cmd_reboot, reboot the system);

////////////////////////////////////////////////////////////////////////////
// reset_fct
static int handle_reset_fct(int argc, char** argv, int optc, optv_t* optv)
{
    FCT_Reset();
    // FCT_SaveToFlashTest();

    printf("fct reset finish~ \r\n");
    return 0;
}

int cmd_reset_fct(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_reset_fct);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_reset_fct, __cmd_reset_fct, reset the RF factory setting);

// set_bb_id
static int handle_set_bb_id(int argc, char** argv, int optc, optv_t* optv)
{

    uint8_t idArr[5];
    uint8_t vtidArr[2];

    idArr[0] = (uint8_t)(strtoul(argv[1], NULL, 0));
    idArr[1] = (uint8_t)(strtoul(argv[2], NULL, 0));
    idArr[2] = (uint8_t)(strtoul(argv[3], NULL, 0));
    idArr[3] = (uint8_t)(strtoul(argv[4], NULL, 0));
    idArr[4] = (uint8_t)(strtoul(argv[5], NULL, 0));

    vtidArr[0] = (uint8_t)(strtoul(argv[6], NULL, 0));
    vtidArr[1] = (uint8_t)(strtoul(argv[7], NULL, 0));

    HAL_BB_SaveRcId(idArr, vtidArr);

    DLOG_Critical("id:0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x", idArr[0], idArr[1], idArr[2], idArr[3], idArr[4], vtidArr[0], vtidArr[1]);

    return 0;
}

int cmd_set_bb_id(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_set_bb_id);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_set_bb_id, __cmd_set_bb_id, set basebase rc id<rc id1 ~5><vt id0 ~1>);

////////////////////////////////////////////////////////////////////////////
// set_chip_id
static int handle_set_chip_id(int argc, char** argv, int optc, optv_t* optv)
{
    uint8_t idArr[5];

    idArr[0] = (uint8_t)(strtoul(argv[0], NULL, 0));
    idArr[1] = (uint8_t)(strtoul(argv[1], NULL, 0));
    idArr[2] = (uint8_t)(strtoul(argv[2], NULL, 0));
    idArr[3] = (uint8_t)(strtoul(argv[3], NULL, 0));
    idArr[4] = (uint8_t)(strtoul(argv[4], NULL, 0));

    HAL_NV_SaveChipId(idArr);

    DLOG_Critical("chip id:0x%x 0x%x 0x%x 0x%x 0x%x", idArr[0], idArr[1], idArr[2], idArr[3], idArr[4]);

    return 0;
}

int cmd_set_chip_id(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_set_chip_id);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_set_chip_id, __cmd_set_chip_id, set<chip id1 ~5>);

////////////////////////////////////////////////////////////////////////////
// testlog
static int handle_testlog_cmd(int argc, char** argv, int optc, optv_t* optv)
{

    // SYS_EVENT_DumpAllListNodes();
    SYS_EVENT_MallocFreeCntCheck();

    return 0;
}

int cmd_testlog(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_testlog_cmd);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_testlog, __cmd_testlog, testlog the system);
// /* coolfly use to switch mavlink channle */
// fmt_err_t __switch_mavlink_to_device(rt_device_t dev)
// {
//     fmt_err_t ret = RT_ERROR;

//     mavproxy_device_info* list = get_device_list();

//     for (int idx = 0; idx < get_device_num(); idx++) {
//         if (rt_device_find(list->name) == dev) {
//             ret = mavproxy_set_channel(idx);
//             break;
//         }
//         list++;
//     }

//     return ret;
// }

// static void sw_mav_show_usage(void)
// {
//     COMMAND_USAGE("sw_mav", "[options]");

//     PRINT_STRING("options:\n");
//     SHELL_COMMAND("serial", "swtich the mavlink to uart7");
//     SHELL_COMMAND("usb", "swtich the mavlink to usb");
//     SHELL_COMMAND("bb_com", "swtich the mavlink to bb_com, use Remote to show the mavlink");
// }

// static int sw_mav_channel(const char* dev)
// {
//     fmt_err_t ret = RT_ERROR;

//     rt_device_t set_dev = rt_device_find(dev);

//     if (set_dev != RT_NULL) {
//         ret = __switch_mavlink_to_device(set_dev);
//         if (ret != RT_EOK) {
//             DLOG_Critical("mavproxy_set_channel %s failed!!! \n", dev);
//         }
//     } else {
//         DLOG_Critical(" can't find the %s \n", dev);
//     }
//     return ret;
// }

// static int handle_sw_mav_cmd(int argc, char** argv, int optc, optv_t* optv)
// {
//     char* arg;
//     struct optparse options;
//     int res = EXIT_SUCCESS;

//     optparse_init(&options, argv);

//     arg = optparse_arg(&options);
//     if (arg) {
//         if (STRING_COMPARE(arg, "serial")) {
//             res = sw_mav_channel("serial7");
//         } else if (STRING_COMPARE(arg, "usb0")) {
//             res = sw_mav_channel("usb");
//         } else if (STRING_COMPARE(arg, "bb_com")) {
//             res = sw_mav_channel("bb_com3");
//         } else {
//             sw_mav_show_usage();
//         }
//     } else {
//         sw_mav_show_usage();
//     }

//     return res;
// }

// int cmd_sw_mav(int argc, char** argv)
// {
//     return syscmd_process(argc, argv, handle_sw_mav_cmd);
// }
// FINSH_FUNCTION_EXPORT_ALIAS(cmd_sw_mav, __cmd_sw_mav, swtich mavlink channel);
