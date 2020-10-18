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
#ifdef FMT_USING_CM_BACKTRACE
#include <cm_backtrace.h>
#endif
#ifdef FMT_USING_UNIT_TEST
#include <utest.h>
#endif

#include "driver/gpio.h"
#include "driver/gps.h"
#include "driver/l3gd20h.h"
#include "driver/lsm303d.h"
#include "driver/mpu6000.h"
#include "driver/ms5611.h"
#include "driver/pwm_drv.h"
#include "driver/spi_drv.h"
#include "driver/systick_drv.h"
#include "driver/tca62724.h"
#include "driver/usart.h"
#include "hal/cdcacm.h"
#include "hal/fmtio_dev.h"
#include "module/controller/controller_model.h"
#include "module/fms/fms_model.h"
#include "module/fs_manager/fs_manager.h"
#include "module/ins/ins_model.h"
#include "module/param/param.h"
#include "module/sensor/sensor_manager.h"
#include "module/sysio/actuator_cmd.h"
#include "module/sysio/pilot_cmd.h"
#include "module/system/statistic.h"
#include "module/system/systime.h"
#include "module/toml/toml.h"
#ifdef FMT_USING_SIH
#include "module/plant/plant_model.h"
#endif

#define MATCH(a, b)     (strcmp(a, b) == 0)
#define SYS_CONFIG_FILE "/sys/sysconfig.toml"

static toml_table_t* _toml_root_tab = NULL;

rt_device_t main_out_dev = NULL;
rt_device_t aux_out_dev = NULL;

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
    _print_line("INS Model", (char*)INS_EXPORT.model_info, str_len);
    _print_line("FMS Model", (char*)FMS_EXPORT.model_info, str_len);
    _print_line("Control Model", (char*)CONTROL_EXPORT.model_info, str_len);
#ifdef FMT_USING_SIH
    _print_line("Plant Model", (char*)PLANT_EXPORT.model_info, str_len);
#endif
    console_println("Task Initialize:");
    _print_line("  vehicle", "OK", str_len);
    _print_line("  fmtio", "OK", str_len);
    _print_line("  comm", "OK", str_len);
    _print_line("  logger", "OK", str_len);
    _print_line("  status", "OK", str_len);
}

// fmt_err console_toml_init(toml_table_t* table);
fmt_err bsp_parse_toml_sysconfig(toml_table_t* root_tab)
{
    fmt_err err = FMT_EOK;
    toml_table_t* sub_tab;
    const char* key;
    const char* raw;
    char* target;
    int i;

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
                    err = console_toml_init(sub_tab);
                } else {
                    console_printf("unknown table: %s\n", key);
                }
            }
        }
    }

    /* free toml root table */
    toml_free(root_tab);

    return err;
}

/* this function will be called before rtos start, which is not thread context */
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
    FMT_CHECK(console_init(CONSOLE_DEVICE_NAME));

    /* init gpio, bus, etc. */
    RTT_CHECK(gpio_drv_init());

    RTT_CHECK(spi_drv_init());

    RTT_CHECK(pwm_drv_init());
}

/* this function will be called after rtos start, which is in thread context */
void bsp_initialize(void)
{
    /* init boot log */
    FMT_CHECK(boot_log_init());

    /* init uMCN */
    FMT_CHECK(mcn_init());

    /* init file manager */
    FMT_CHECK(fs_manager_init(FS_DEVICE_NAME, "/"));

    /* init usb device */
    FMT_CHECK(usb_cdc_init());

    /* init imu0 */
    RTT_CHECK(mpu6000_drv_init(MPU6000_SPI_DEVICE_NAME));

    /* init imu1 + mag0 */
    RTT_CHECK(l3gd20h_drv_init(L3GD20H_SPI_DEVICE_NAME));
    RTT_CHECK(lsm303d_drv_init(LSM303D_SPI_DEVICE_NAME));

    /* init barometer */
    RTT_CHECK(ms5611_drv_init(MS5611_SPI_DEVICE_NAME));

    /* init gps */
    RTT_CHECK(drv_gps_init(GPS_SERIAL_DEVICE_NAME));

    /* init other device */
    RTT_CHECK(tca62724_drv_init());

    /* init parameter system */
    FMT_CHECK(param_init());

    /* init sensor manager */
    FMT_CHECK(sensor_manager_init());

    //     /* GDB STUB */
    // #ifdef RT_USING_GDB
    //     gdb_set_device(GDB_DEVICE_NAME);
    //     gdb_start();
    // #endif

#ifdef RT_USING_FINSH
    /* init finsh */
    finsh_system_init();
    /* Mount finsh to console after finsh system init */
    FMT_CHECK(console_enable_shell(NULL));
#endif

    /* system statistic module */
    FMT_CHECK(sys_stat_init());

#ifdef FMT_USING_CM_BACKTRACE
    /* cortex-m backtrace */
    cm_backtrace_init("fmt_fmu", TARGET_NAME, "v0.1");
#endif

#ifdef FMT_USING_UNIT_TEST
    utest_init();
#endif
}

void bsp_post_initialize(void)
{
    FMT_CHECK(pilot_cmd_init());

#if defined(FMT_HIL_WITH_ACTUATOR) || !defined(FMT_USING_HIL)
    /* init main out */
    main_out_dev = rt_device_find("motor_main");
    FMT_CHECK(actuator_init(main_out_dev));
    /* init aux out */
    aux_out_dev = rt_device_find("motor_aux");
    FMT_CHECK(actuator_init(aux_out_dev));
#endif

    /* toml system configure */
    _toml_root_tab = toml_parse_config_file(SYS_CONFIG_FILE);
    if (_toml_root_tab) {
        FMT_CHECK(bsp_parse_toml_sysconfig(_toml_root_tab));
    }

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
