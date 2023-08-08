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
#include <msh.h>
#include <shell.h>
#include <string.h>
#ifdef FMT_USING_CM_BACKTRACE
    #include <cm_backtrace.h>
#endif
#ifdef FMT_USING_UNIT_TEST
    #include <utest.h>
#endif

#include "default_config.h"
#include "driver/airspeed/ms4525.h"
#include "driver/barometer/ms5611.h"
#include "driver/gps/gps_ubx.h"
#include "driver/imu/l3gd20h.h"
#include "driver/imu/lsm303d.h"
#include "driver/imu/mpu6000.h"
#include "driver/rgb_led/tca62724.h"
#include "driver/uwb/nlink_linktrack/nlink_linktrack.h"
#include "driver/vision_flow/mtf_01.h"
#include "drv_adc.h"
#include "drv_gpio.h"
#include "drv_i2c_soft.h"
#include "drv_pwm.h"
#include "drv_sdio.h"
#include "drv_spi.h"
#include "drv_systick.h"
#include "drv_usart.h"
#include "drv_usbd_cdc.h"
#include "hal/fmtio_dev/fmtio_dev.h"
#include "led.h"
#include "model/control/control_interface.h"
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/console/console_config.h"
#include "module/file_manager/file_manager.h"
#include "module/mavproxy/mavproxy_config.h"
#include "module/param/param.h"
#include "module/pmu/power_manager.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/actuator_cmd.h"
#include "module/sysio/actuator_config.h"
#include "module/sysio/auto_cmd.h"
#include "module/sysio/gcs_cmd.h"
#include "module/sysio/mission_data.h"
#include "module/sysio/pilot_cmd.h"
#include "module/sysio/pilot_cmd_config.h"
#include "module/system/statistic.h"
#include "module/system/systime.h"
#include "module/task_manager/task_manager.h"
#include "module/toml/toml.h"
#include "module/utils/devmq.h"
#include "module/workqueue/workqueue_manager.h"

#ifdef FMT_USING_SIH
    #include "model/plant/plant_interface.h"
#endif
#include "protocol/msp/msp.h"

#define MATCH(a, b)     (strcmp(a, b) == 0)
#define SYS_CONFIG_FILE "/sys/sysconfig.toml"
#define SYS_INIT_SCRIPT "/sys/init.sh"

static const struct dfs_mount_tbl mnt_table[] = {
    { "sd0", "/", "elm", 0, NULL },
    { NULL } /* NULL indicate the end */
};

static toml_table_t* _toml_root_tab = NULL;

rt_device_t main_out_dev = NULL;
rt_device_t aux_out_dev = NULL;

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

/**
 * @brief Enable on-board device power supply
 * 
 */
static void EnablePower(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = { 0 };

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA, GPIO_Pin_8);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    GPIO_SetBits(GPIOE, GPIO_Pin_3);

    /* Wait some time for power becoming stable */
    systime_mdelay(100);
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

    /* spi driver init */
    RT_CHECK(drv_spi_init());

    /* init soft i2c */
    RT_CHECK(drv_i2c_soft_init());

    /* pwm driver init */
    RT_CHECK(drv_pwm_init());

    /* system statistic module */
    FMT_CHECK(sys_stat_init());
}

/* this function will be called after rtos start, which is in thread context */
void bsp_initialize(void)
{
    EnablePower();

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

    /* init parameter system */
    FMT_CHECK(param_init());

    /* init usb device */
    RT_CHECK(drv_usb_cdc_init());

    /* adc driver init */
    RT_CHECK(drv_adc_init());

    /* init other devices */
    RT_CHECK(tca62724_drv_init("i2c2"));

    /* register sensor to sensor hub */
#if defined(FMT_USING_SIH) || defined(FMT_USING_HIL)
    FMT_CHECK(advertise_sensor_imu(0));
    FMT_CHECK(advertise_sensor_mag(0));
    FMT_CHECK(advertise_sensor_baro(0));
    FMT_CHECK(advertise_sensor_gps(0));
    FMT_CHECK(advertise_sensor_airspeed(0));
#else
    /* init onboard sensors */

    /* init imu0 */
    RT_CHECK(mpu6000_drv_init("spi1_dev4", "gyro0", "accel0"));
    /* init imu1 + mag0 */
    RT_CHECK(l3gd20h_drv_init("spi1_dev2", "gyro1"));
    RT_CHECK(lsm303d_drv_init("spi1_dev1", "mag0", "accel1"));
    /* init barometer */
    RT_CHECK(drv_ms5611_init("spi1_dev3", "barometer"));
    /* init optical flow module (a mini tf included) */
    RT_CHECK(drv_mtf_01_init("serial3"));
    /* init gps */
    RT_CHECK(gps_ubx_init("serial2", "gps"));

    // drv_nlink_linktrack_init("serial4");

    /* register sensor to sensor hub */
    FMT_CHECK(register_sensor_imu("gyro0", "accel0", 0));
    FMT_CHECK(register_sensor_mag("mag0", 0));
    FMT_CHECK(register_sensor_barometer("barometer"));
    FMT_CHECK(advertise_sensor_optflow(0));
    FMT_CHECK(advertise_sensor_rangefinder(0));
    if (strcmp(STR(VEHICLE_TYPE), "Fixwing") == 0) {
        RT_CHECK(drv_ms4525_init("i2c1_dev1", "airspeed"));
        FMT_CHECK(register_sensor_airspeed("airspeed"));
    }
#endif

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
        _toml_root_tab = toml_parse_config_string(default_conf);
    }
    FMT_CHECK(bsp_parse_toml_sysconfig(_toml_root_tab));

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

    /* start msp server */
    FMT_CHECK(msp_server_start());

    /* start device message queue work */
    FMT_CHECK(devmq_start_work());

    /* init led control */
    FMT_CHECK(led_control_init());

    /* initialize power management unit */
    FMT_CHECK(pmu_init());

    /* show system information */
    bsp_show_information();

    /* execute init script */
    msh_exec_script(SYS_INIT_SCRIPT, strlen(SYS_INIT_SCRIPT));

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
