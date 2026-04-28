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
#include "module/file_manager/file_manager.h"
#include "module/mavproxy/mavproxy.h"
#include "module/param/param.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/actuator_cmd.h"
#include "module/sysio/auto_cmd.h"
#include "module/sysio/gcs_cmd.h"
#include "module/sysio/mission_data.h"
#include "module/sysio/pilot_cmd.h"
#include "module/task_manager/task_manager.h"
#include "module/utils/devmq.h"
#include "module/workqueue/workqueue_manager.h"

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

const rt_uint32_t platform_mem_desc_size = sizeof(platform_mem_desc) / sizeof(platform_mem_desc[0]);

static void idle_wfi(void)
{
    asm volatile("wfi");
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

    /* init mavproxy */
    FMT_CHECK(mavproxy_init());

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
    if (bsp_parse_toml_sysconfig(toml_parse_config_file(SYS_CONFIG_FILE)) != FMT_EOK) {
        /* use default system configuration */
        FMT_CHECK(bsp_parse_toml_sysconfig(toml_parse_config_string(default_conf)));
        printf("Default configuration loaded.\n");
    }

    /* init rc */
    FMT_CHECK(pilot_cmd_init());

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
