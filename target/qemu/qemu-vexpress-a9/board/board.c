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

#include "drv_sdio.h"
#include "drv_systick.h"
#include "drv_usart.h"
#include <drivers/mmcsd_core.h>

#include "module/file_manager/file_manager.h"
#include "module/param/param.h"
#include "module/task_manager/task_manager.h"

#define DEFAULT_TOML_SYS_CONFIG "target = \"QEMU vexpress-a9\"\n\
[console]\n\
	[[console.devices]]\n\
	type = \"serial\"\n\
	name = \"serial0\"\n\
	baudrate = 57600"

#define MATCH(a, b)     (strcmp(a, b) == 0)
#define SYS_CONFIG_FILE "/sys/sysconfig.toml"

#define SYS_CTRL __REG32(REALVIEW_SCTL_BASE)

struct mem_desc platform_mem_desc[] = {
    { 0x10000000, 0x50000000, 0x10000000, DEVICE_MEM },
    { 0x60000000, 0xe0000000, 0x60000000, NORMAL_MEM }
};

const rt_uint32_t platform_mem_desc_size = sizeof(platform_mem_desc) / sizeof(platform_mem_desc[0]);

static const struct dfs_mount_tbl mnt_table[] = {
    { "sd0", "/", "elm", 0, NULL },
    { NULL } /* NULL indicate the end */
};

void idle_wfi(void)
{
    asm volatile("wfi");
}

#define ITEM_LENGTH 42
void bsp_show_information(void)
{
    char buffer[50];

    console_printf("\n");
    console_println("   _____                               __ ");
    console_println("  / __(_)_____ _  ___ ___ _  ___ ___  / /_");
    console_println(" / _// / __/  ' \\/ _ `/  ' \\/ -_) _ \\/ __/");
    console_println("/_/ /_/_/ /_/_/_/\\_,_/_/_/_/\\__/_//_/\\__/ ");

    sprintf(buffer, "FMT FMU %s", FMT_VERSION);
    print_item_line("Firmware", buffer, '.', ITEM_LENGTH);
    sprintf(buffer, "RT-Thread v%ld.%ld.%ld", RT_VERSION, RT_SUBVERSION, RT_REVISION);
    print_item_line("Kernel", buffer, '.', ITEM_LENGTH);
    sprintf(buffer, "%d KB", SYSTEM_TOTAL_MEM_SIZE / 1024);
    print_item_line("RAM", buffer, '.', ITEM_LENGTH);
    print_item_line("Target", TARGET_NAME, '.', ITEM_LENGTH);
    print_item_line("Vehicle", VEHICLE_TYPE, '.', ITEM_LENGTH);
    //     print_item_line("INS Model", ins_model_info.info, '.', ITEM_LENGTH);
    //     print_item_line("FMS Model", fms_model_info.info, '.', ITEM_LENGTH);
    //     print_item_line("Control Model", control_model_info.info, '.', ITEM_LENGTH);
    // #ifdef FMT_USING_SIH
    //     print_item_line("Plant Model", plant_model_info.info, '.', ITEM_LENGTH);
    // #endif

    console_println("Task Initialize:");
    fmt_task_desc_t task_tab = get_task_table();
    for (uint32_t i = 0; i < get_task_num(); i++) {
        sprintf(buffer, "  %s", task_tab[i].name);
        /* task status must be okay to reach here */
        print_item_line(buffer, task_tab[i].status == TASK_OK ? "OK" : "Fail", '.', ITEM_LENGTH);
    }
}

/* this function will be called before rtos start, which is not in the thread context */
void bsp_early_initialize(void)
{
    /* initialize hardware interrupt */
    rt_hw_interrupt_init();

    /* init system heap */
    rt_system_heap_init((void*)SYSTEM_FREE_MEM_BEGIN, (void*)SYSTEM_FREE_MEM_END);

    /* systick driver init */
    RT_CHECK(drv_systick_init());

    /* usart driver init */
    RT_CHECK(drv_usart_init());

    /* system time module init */
    FMT_CHECK(systime_init());

    /* init console to enable console output */
    FMT_CHECK(console_init());

    rt_thread_idle_sethook(idle_wfi);
}

/* this function will be called after rtos start, which is in thread context */
void bsp_initialize(void)
{
    /* start recording boot log */
    // FMT_CHECK(boot_log_init());

    /* init uMCN */
    FMT_CHECK(mcn_init());

    /* mmcsd core init */
    RT_CHECK(rt_mmcsd_core_init());
    /* sdio driver init */
    RT_CHECK(pl180_init());
    /* init file system */
    rt_thread_delay(RT_TICK_PER_SECOND); /* wait sd card detected */
    FMT_CHECK(file_manager_init(mnt_table));

    /* init finsh */
    finsh_system_init();
    /* Mount finsh to console after finsh system init */
    FMT_CHECK(console_enable_input());
}

void bsp_post_initialize(void)
{
    /* show system information */
    bsp_show_information();

    /* dump boot log to file */
    // boot_log_dump();
}

/**
 * This function will initial STM32 board.
 */
void rt_hw_board_init()
{
    bsp_early_initialize();
}
