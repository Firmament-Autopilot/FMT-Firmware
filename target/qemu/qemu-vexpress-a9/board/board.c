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

#include <board.h>
#include <mmu.h>
#include <shell.h>
#include <string.h>

#include "drv_pwm.h"
#include "drv_sdio.h"
#include "drv_systick.h"
#include "drv_usart.h"
#include <drivers/mmcsd_core.h>


#include "default_config.h"
#include "model/control/control_interface.h"
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/console/console_config.h"
#include "module/file_manager/file_manager.h"
#include "module/mavproxy/mavproxy_config.h"
#include "module/param/param.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/actuator_cmd.h"
#include "module/sysio/actuator_config.h"
#include "module/sysio/auto_cmd.h"
#include "module/sysio/gcs_cmd.h"
#include "module/sysio/mission_data.h"
#include "module/sysio/pilot_cmd.h"
#include "module/sysio/pilot_cmd_config.h"
#include "module/task_manager/task_manager.h"
#include "module/toml/toml.h"
#include "module/utils/devmq.h"
#include "module/workqueue/workqueue_manager.h"
#ifdef FMT_USING_SIH
    #include "model/plant/plant_interface.h"
#endif

#define MATCH(a, b)     (strcmp(a, b) == 0)
#define SYS_CONFIG_FILE "/sys/sysconfig.toml"

#define SYS_CTRL __REG32(REALVIEW_SCTL_BASE)

struct mem_desc platform_mem_desc[] = {
    { 0x10000000, 0x50000000, 0x10000000, DEVICE_MEM },
    { 0x60000000, 0xe0000000, 0x60000000, NORMAL_MEM }
};

static const struct dfs_mount_tbl mnt_table[] = {
    { "sd0", "/", "elm", 0, NULL },
    { NULL } /* NULL indicate the end */
};

static toml_table_t* __toml_root_tab = NULL;

const rt_uint32_t platform_mem_desc_size = sizeof(platform_mem_desc) / sizeof(platform_mem_desc[0]);

static void banner_item(const char* name, const char* content, char pad, uint32_t len)
{
    int pad_len;

    if (content == NULL) {
        content = "NULL";
    }

    pad_len = len - strlen(name) - strlen(content);

    if (pad_len < 1) {
        pad_len = 1;
    }
    // e.g, name..............content
    console_printf("%s", name);
    while (pad_len--) {
        console_write(&pad, 1);
    }

    console_printf("%s\n", content);
}

#define BANNER_ITEM_LEN 42
static void bsp_show_information(void)
{
    char buffer[50];

    console_printf("\n");
    console_println("   _____                               __ ");
    console_println("  / __(_)_____ _  ___ ___ _  ___ ___  / /_");
    console_println(" / _// / __/  ' \\/ _ `/  ' \\/ -_) _ \\/ __/");
    console_println("/_/ /_/_/ /_/_/_/\\_,_/_/_/_/\\__/_//_/\\__/ ");

    sprintf(buffer, "FMT FW %s", FMT_VERSION);
    banner_item("Firmware", buffer, '.', BANNER_ITEM_LEN);
    sprintf(buffer, "RT-Thread v%ld.%ld.%ld", RT_VERSION, RT_SUBVERSION, RT_REVISION);
    banner_item("Kernel", buffer, '.', BANNER_ITEM_LEN);
    sprintf(buffer, "%d KB", SYSTEM_TOTAL_MEM_SIZE / 1024);
    banner_item("RAM", buffer, '.', BANNER_ITEM_LEN);
    banner_item("Target", TARGET_NAME, '.', BANNER_ITEM_LEN);
    banner_item("Vehicle", STR(VEHICLE_TYPE), '.', BANNER_ITEM_LEN);
    banner_item("Airframe", STR(AIRFRAME), '.', BANNER_ITEM_LEN);
    banner_item("INS Model", ins_model_info.info, '.', BANNER_ITEM_LEN);
    banner_item("FMS Model", fms_model_info.info, '.', BANNER_ITEM_LEN);
    banner_item("Control Model", control_model_info.info, '.', BANNER_ITEM_LEN);
#ifdef FMT_USING_SIH
    banner_item("Plant Model", plant_model_info.info, '.', BANNER_ITEM_LEN);
#endif

    console_println("Task Initialize:");
    fmt_task_desc_t task_tab = get_task_table();
    for (uint32_t i = 0; i < get_task_num(); i++) {
        sprintf(buffer, "  %s", task_tab[i].name);
        /* task status must be okay to reach here */
        banner_item(buffer, get_task_status(task_tab[i].name) == TASK_READY ? "OK" : "Fail", '.', BANNER_ITEM_LEN);
    }
}

static void idle_wfi(void)
{
    asm volatile("wfi");
}

static fmt_err_t bsp_parse_toml_sysconfig(toml_table_t* root_tab)
{
    fmt_err_t err = FMT_EOK;
    toml_table_t* sub_tab;
    const char* key;
    const char* raw;
    char* target;
    int i;

    if (root_tab == NULL) {
        return FMT_ERROR;
    }

    /* target should be defined and match with bsp */
    if ((raw = toml_raw_in(root_tab, "target")) != 0) {
        if (toml_rtos(raw, &target) != 0) {
            console_printf("Error: fail to parse type value\n");
            err = FMT_ERROR;
        }
        if (!MATCH(target, TARGET_NAME)) {
            /* check if target match */
            console_printf("Error: target name doesn't match\n");
            err = FMT_ERROR;
        }
        rt_free(target);
    } else {
        console_printf("Error: can not find target key\n");
        err = FMT_ERROR;
    }

    if (err == FMT_EOK) {
        /* traverse all sub-table */
        for (i = 0; 0 != (key = toml_key_in(root_tab, i)); i++) {
            /* handle all sub tables */
            if (0 != (sub_tab = toml_table_in(root_tab, key))) {
                if (MATCH(key, "console")) {
                    err = console_toml_config(sub_tab);
                } else if (MATCH(key, "mavproxy")) {
                    err = mavproxy_toml_config(sub_tab);
                } else if (MATCH(key, "pilot-cmd")) {
                    err = pilot_cmd_toml_config(sub_tab);
                } else if (MATCH(key, "actuator")) {
                    err = actuator_toml_config(sub_tab);
                } else {
                    console_printf("unknown table: %s\n", key);
                }
                if (err != FMT_EOK) {
                    console_printf("fail to parse %s\n", key);
                }
            }
        }
    }

    /* free toml root table */
    toml_free(root_tab);

    return err;
}

/* this function will be called before rtos start, which is not in the thread context */
void bsp_early_initialize(void)
{
    /* initialize hardware interrupt */
    rt_hw_interrupt_init();

    /* init system heap */
    rt_system_heap_init((void*)SYSTEM_FREE_MEM_BEGIN, (void*)SYSTEM_FREE_MEM_END);

    /* usart driver init */
    RT_CHECK(drv_usart_init());

    /* init console to enable console output */
    FMT_CHECK(console_init());

    /* systick driver init */
    RT_CHECK(drv_systick_init());

    RT_CHECK(drv_pwm_init());

    /* system time module init */
    FMT_CHECK(systime_init());

    /* system statistic module */
    FMT_CHECK(sys_stat_init());

    rt_thread_idle_sethook(idle_wfi);
}

/* this function will be called after rtos start, which is in thread context */
void bsp_initialize(void)
{
    /* start recording boot log */
    FMT_CHECK(boot_log_init());

    /* init uMCN */
    FMT_CHECK(mcn_init());

    /* create workqueue */
    FMT_CHECK(workqueue_manager_init());

    /* mmcsd core init */
    RT_CHECK(rt_mmcsd_core_init());
    /* sdio driver init */
    RT_CHECK(pl180_init());
    /* init file system */
    rt_thread_delay(RT_TICK_PER_SECOND); /* wait sd card detected */
    file_manager_init(mnt_table);

    /* init parameter system */
    FMT_CHECK(param_init());

#if defined(FMT_USING_SIH) || defined(FMT_USING_HIL)
    FMT_CHECK(advertise_sensor_imu(0));
    FMT_CHECK(advertise_sensor_mag(0));
    FMT_CHECK(advertise_sensor_baro(0));
    FMT_CHECK(advertise_sensor_gps(0));
    FMT_CHECK(advertise_sensor_airspeed(0));
#else
    #error QEMU only support SIH or HIL mode
#endif

    /* init finsh */
    finsh_system_init();
    /* Mount finsh to console after finsh system init */
    FMT_CHECK(console_enable_input());
}

void bsp_post_initialize(void)
{
    /* toml system configure */
    __toml_root_tab = toml_parse_config_file(SYS_CONFIG_FILE);
    if (!__toml_root_tab) {
        /* use default system configuration */
        __toml_root_tab = toml_parse_config_string(default_conf);
    }
    FMT_CHECK(bsp_parse_toml_sysconfig(__toml_root_tab));

    /* init gcs */
    FMT_CHECK(gcs_cmd_init());

    /* init auto command */
    FMT_CHECK(auto_cmd_init());

    /* init mission data */
    FMT_CHECK(mission_data_init());

    /* init actuator */
    FMT_CHECK(actuator_init());

    /* start device message queue work */
    FMT_CHECK(devmq_start_work());

    /* show system information */
    bsp_show_information();

    /* dump boot log to file */
    boot_log_dump();
}

/**
 * This function will initial STM32 board.
 */
void rt_hw_board_init()
{
    bsp_early_initialize();
}
