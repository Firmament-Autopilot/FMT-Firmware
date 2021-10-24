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
#include <board_device.h>
#include <shell.h>
#include <string.h>
#ifdef FMT_USING_CM_BACKTRACE
#include <cm_backtrace.h>
#endif
#ifdef FMT_USING_UNIT_TEST
#include <utest.h>
#endif

#include "driver/gps_m8n.h"
#include "driver/l3gd20h.h"
#include "driver/lsm303d.h"
#include "driver/mpu6000.h"
#include "driver/ms5611.h"
#include "driver/pmw3901_l0x.h"
#include "driver/tca62724.h"
#include "drv_gpio.h"
#include "drv_i2c_soft.h"
#include "drv_pwm.h"
#include "drv_sdio.h"
#include "drv_spi.h"
#include "drv_systick.h"
#include "drv_usart.h"
#include "drv_usbd_cdc.h"
#include "hal/fmtio_dev.h"
#include "led.h"
#include "module/console/console_config.h"
#include "module/control/control_interface.h"
#include "module/file_manager/file_manager.h"
#include "module/fms/fms_interface.h"
#include "module/ins/ins_interface.h"
#include "module/mavproxy/mavproxy_config.h"
#include "module/param/param.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/actuator_cmd.h"
#include "module/sysio/actuator_config.h"
#include "module/sysio/pilot_cmd.h"
#include "module/sysio/pilot_cmd_config.h"
#include "module/system/statistic.h"
#include "module/system/systime.h"
#include "module/task_manager/task_manager.h"
#include "module/toml/toml.h"
#include "module/utils/devmq.h"
#include "module/work_queue/workqueue_manager.h"
#ifdef FMT_USING_SIH
#include "module/plant/plant_interface.h"
#endif
#include "protocol/msp/msp.h"

static const struct dfs_mount_tbl mnt_table[] = {
    { "sd0", "/", "elm", 0, NULL },
    { NULL } /* NULL indicate the end */
};

#define DEFAULT_TOML_SYS_CONFIG "target = \"Pixhawk FMUv2\"\n\
[console]\n\
	[[console.devices]]\n\
	type = \"serial\"\n\
	name = \"serial0\"\n\
	baudrate = 57600\n\
	auto-switch = true\n\
	[[console.devices]]\n\
	type = \"mavlink\"\n\
	name = \"mav_console\"\n\
	auto-switch = true\n\
[mavproxy]\n\
	[[mavproxy.devices]]\n\
	type = \"serial\"\n\
	name = \"serial1\"\n\
	baudrate = 57600\n\
	[[mavproxy.devices]]\n\
	type = \"usb\"\n\
	name = \"usbd0\"\n\
    auto-switch = true"

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

static void NVIC_Configuration(void)
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
    print_item_line("INS Model", ins_model_info.info, '.', ITEM_LENGTH);
    print_item_line("FMS Model", fms_model_info.info, '.', ITEM_LENGTH);
    print_item_line("Control Model", control_model_info.info, '.', ITEM_LENGTH);
#ifdef FMT_USING_SIH
    print_item_line("Plant Model", plant_model_info.info, '.', ITEM_LENGTH);
#endif

    console_println("Task Initialize:");
    fmt_task_desc_t task_tab = get_task_table();
    for (uint32_t i = 0; i < get_task_num(); i++) {
        sprintf(buffer, "  %s", task_tab[i].name);
        /* task status must be okay to reach here */
        print_item_line(buffer, get_task_status(task_tab[i].name) == TASK_OK ? "OK" : "Fail", '.', ITEM_LENGTH);
    }
}

fmt_err_t bsp_parse_toml_sysconfig(toml_table_t* root_tab)
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
                    continue;
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
    /* interrupt controller init */
    NVIC_Configuration();

    /* init system heap */
    rt_system_heap_init((void*)SYSTEM_FREE_MEM_BEGIN, (void*)SYSTEM_FREE_MEM_END);

    /* system usart init */
    RT_CHECK(drv_usart_init());

    /* init console to enable console output */
    FMT_CHECK(console_init());

    /* system timer init */
    RT_CHECK(drv_systick_init());

    /* system time module init */
    FMT_CHECK(systime_init());

    /* init gpio, bus, etc. */
    RT_CHECK(drv_gpio_init());

    RT_CHECK(spi_drv_init());

    RT_CHECK(drv_pwm_init());

    /* system statistic module */
    FMT_CHECK(sys_stat_init());
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

    /* init storage devices */
    RT_CHECK(drv_sdio_init());
    /* init file system */
    FMT_CHECK(file_manager_init(mnt_table));

    drv_i2c_soft_init();

    /* init usb device */
    RT_CHECK(drv_usb_cdc_init());

    /* init imu0 */
    RT_CHECK(mpu6000_drv_init(MPU6000_SPI_DEVICE_NAME));

    /* init imu1 + mag0 */
    RT_CHECK(l3gd20h_drv_init(L3GD20H_SPI_DEVICE_NAME));
    RT_CHECK(lsm303d_drv_init(LSM303D_SPI_DEVICE_NAME));

    /* init barometer */
    RT_CHECK(ms5611_drv_init(MS5611_SPI_DEVICE_NAME));

    /* init gps */
    RT_CHECK(gps_m8n_init(GPS_SERIAL_DEVICE_NAME));

    /* init other devices */
    RT_CHECK(pmw3901_l0x_drv_init("serial3"));
    RT_CHECK(tca62724_drv_init());

    /* init parameter system */
    FMT_CHECK(param_init());

    /* register sensor to sensor hub */
    FMT_CHECK(register_sensor_imu("gyro0", "accel0", 0));
    FMT_CHECK(register_sensor_mag("mag0", 0));
    FMT_CHECK(register_sensor_barometer("barometer"));

    /* init finsh */
    finsh_system_init();
    /* Mount finsh to console after finsh system init */
    FMT_CHECK(console_enable_input());

#ifdef FMT_USING_CM_BACKTRACE
    /* cortex-m backtrace */
    cm_backtrace_init("fmt_fmu-v2", TARGET_NAME, FMT_VERSION);
#endif

#ifdef FMT_USING_UNIT_TEST
    utest_init();
#endif
}

void bsp_post_initialize(void)
{
    /* toml system configure */
    _toml_root_tab = toml_parse_config_file(SYS_CONFIG_FILE);
    if (!_toml_root_tab) {
        /* use default system configuration */
        _toml_root_tab = toml_parse_config_string(DEFAULT_TOML_SYS_CONFIG);
    }
    FMT_CHECK(bsp_parse_toml_sysconfig(_toml_root_tab));

    /* init rc */
    FMT_CHECK(pilot_cmd_init());

#if defined(FMT_HIL_WITH_ACTUATOR) || (!defined(FMT_USING_HIL) && !defined(FMT_USING_SIH))
    /* init actuator */
    FMT_CHECK(actuator_init());
#endif

    /* start msp server */
    FMT_CHECK(msp_server_start());

    /* start device message queue work */
    FMT_CHECK(devmq_start_work());

    /* init led control */
    FMT_CHECK(led_control_init());

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
