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

#include <bsp.h>
#include <shell.h>
#include <string.h>

#include "driver/gpio.h"
#include "driver/systick_drv.h"
#include "driver/usart.h"

static void _print_line(const char* name, const char* content, uint32_t len)
{
    int pad_len = len - strlen(name) - strlen(content);

    if (pad_len < 1) {
        pad_len = 1;
    }

    console_printf("%s", name);

    while (pad_len--)
        console_write(".", 1);

    console_printf("%s\n", content);
}

void NVIC_Configuration(void)
{
#ifdef VECT_TAB_RAM
    /* Set the Vector Table base location at 0x20000000 */
    NVIC_SetVectorTable(NVIC_VectTab_RAM, INT_VECTOR_OFFSET);
#else /* VECT_TAB_FLASH  */
    /* Set the Vector Table base location at 0x8004000 */
    /* first 0x4000 is reserved for bootloader, so the vectortab offset is 0x4000 */
    NVIC_SetVectorTable(NVIC_VectTab_FLASH, INT_VECTOR_OFFSET);
#endif

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
}

void bsp_show_information(void)
{
    char buffer[50];
    uint32_t str_len = 42;

    console_println("   _____                               __ ");
    console_println("  / __(_)_____ _  ___ ___ _  ___ ___  / /_");
    console_println(" / _// / __/  ' \\/ _ `/  ' \\/ -_) _ \\/ __/");
    console_println("/_/ /_/_/ /_/_/_/\\_,_/_/_/_/\\__/_//_/\\__/ ");

    sprintf(buffer, "FMT FMU v%d.%d.%d", FMT_VERSION, FMT_SUBVERSION, FMT_REVISION);
    _print_line("Firmware", buffer, str_len);
    sprintf(buffer, "RT-Thread v%ld.%ld.%ld", RT_VERSION, RT_SUBVERSION, RT_REVISION);
    _print_line("Kernel", buffer, str_len);
    sprintf(buffer, "%d KB", SYSTEM_TOTAL_MEM_SIZE / 1024);
    _print_line("RAM", buffer, str_len);
    _print_line("Target", TARGET_NAME, str_len);
    _print_line("Vehicle", VEHICLE_TYPE, str_len);
//     _print_line("INS Model", (char*)INS_EXPORT.model_info, str_len);
//     _print_line("FMS Model", (char*)FMS_EXPORT.model_info, str_len);
//     _print_line("Control Model", (char*)CONTROL_EXPORT.model_info, str_len);
// #ifdef FMT_USING_SIH
//     _print_line("Plant Model", (char*)PLANT_EXPORT.model_info, str_len);
// #endif
    // console_println("Task Initialize:");
    // _print_line("  vehicle", "OK", str_len);
    // _print_line("  fmtio", "OK", str_len);
    // _print_line("  comm", "OK", str_len);
    // _print_line("  logger", "OK", str_len);
    // _print_line("  status", "OK", str_len);
}

/* this function will be called before rtos start, which is not in the thread context */
void bsp_early_initialize(void)
{
    /* interrupt controller init */
    NVIC_Configuration();

    /* system timer init */
    RTT_CHECK(systick_drv_init());

    /* system usart init */
    RTT_CHECK(usart_drv_init());

    /* system time module init */
    FMT_CHECK(systime_init());

    /* init console to enable console output */
    FMT_CHECK(console_init());

    /* init gpio, bus, etc. */
    RTT_CHECK(gpio_drv_init());
}

/* this function will be called after rtos start, which is in thread context */
void bsp_initialize(void)
{
#ifdef RT_USING_FINSH
    /* init finsh */
    finsh_system_init();
    /* Mount finsh to console after finsh system init */
    FMT_CHECK(console_enable_shell(NULL));
#endif

    /* system statistic module */
    FMT_CHECK(sys_stat_init());
}

void bsp_post_initialize(void)
{
    /* show system information */
    bsp_show_information();
}

/**
 * This function will initial STM32 board.
 */
void rt_hw_board_init()
{
    bsp_early_initialize();
}
