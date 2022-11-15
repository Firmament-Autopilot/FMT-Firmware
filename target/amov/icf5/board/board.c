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

#include "default_config.h"
#include "driver/barometer/ms5611.h"
#include "driver/barometer/spl06.h"
#include "driver/gps/gps_m8n.h"
#include "driver/imu/bmi088.h"
#include "driver/imu/icm20948.h"
#include "driver/imu/icm42688.h"
#include "driver/mag/bmm150.h"
#include "driver/mtd/w25q16.h"
#include "drv_i2c.h"
#include "drv_pwm.h"
#include "drv_rc.h"
#include "drv_sdio.h"
#include "drv_spi.h"
#include "drv_systick.h"
#include "drv_usart.h"
#include "drv_usbd_cdc.h"
#include "model/control/control_interface.h"
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/console/console_config.h"
#include "module/file_manager/file_manager.h"
#include "module/mavproxy/mavproxy.h"
#include "module/mavproxy/mavproxy_config.h"
#include "module/pmu/power_manager.h"
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

static const struct dfs_mount_tbl mnt_table[] = {
    { "sd0", "/", "elm", 0, NULL },
    { NULL } /* NULL indicate the end */
};

static toml_table_t* __toml_root_tab = NULL;

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
    banner_item("Vehicle", VEHICLE_TYPE, '.', BANNER_ITEM_LEN);
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

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
    printf("Enter Error_Handler\n");
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    // __disable_irq();
    while (1) {
    }
    /* USER CODE END Error_Handler_Debug */
}

static void NVIC_Configuration(void)
{
    extern const int _stext;

    /* NVIC Configuration */
#define NVIC_VTOR_MASK 0x3FFFFF80
#ifdef VECT_TAB_RAM
    /* Set the Vector Table base location at 0x10000000 */
    SCB->VTOR = (0x10000000 & NVIC_VTOR_MASK);
#else /* VECT_TAB_FLASH  */
    /* Set the Vector Table base location at 0x08000000 */
    SCB->VTOR = ((uint32_t)&_stext & NVIC_VTOR_MASK);
#endif
}

/* this function will be called before rtos start, which is not in the thread context */
void bsp_early_initialize(void)
{
    NVIC_Configuration();

    /* init system heap */
    rt_system_heap_init((void*)SYSTEM_FREE_MEM_BEGIN, (void*)SYSTEM_FREE_MEM_END);

    /* usart driver init */
    RT_CHECK(drv_usart_init());

    /* init console to enable console output */
    FMT_CHECK(console_init());

    /* systick driver init */
    RT_CHECK(drv_systick_init());

    /* system time module init */
    FMT_CHECK(systime_init());

    /* spi driver init */
    RT_CHECK(drv_spi_init());

    /* i2c driver init */
    RT_CHECK(drv_i2c_init());

    /* pwm driver init */
    // RT_CHECK(drv_pwm_init());

    /* init remote controller driver */
    // RT_CHECK(drv_rc_init());

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

    /* init parameter system */
    FMT_CHECK(param_init());

    /* init usbd_cdc */
    RT_CHECK(drv_usb_cdc_init());

#if defined(FMT_USING_SIH) || defined(FMT_USING_HIL)
    FMT_CHECK(advertise_sensor_imu(0));
    FMT_CHECK(advertise_sensor_mag(0));
    FMT_CHECK(advertise_sensor_baro(0));
    FMT_CHECK(advertise_sensor_gps(0));
#else
    /* init onboard sensors */
    RT_CHECK(drv_bmi088_init("spi0_dev1", "spi0_dev0", "gyro0", "accel0", 0));
    RT_CHECK(drv_bmm150_init("spi0_dev2", "mag0"));
    RT_CHECK(drv_icm42688_init("spi0_dev4", "gyro1", "accel1"));
    RT_CHECK(drv_spl06_init("spi0_dev3", "barometer"));

    RT_CHECK(gps_m8n_init("serial4", "gps"));

    // spi_parameter_struct spi_init_struct;
    // spi_init_struct.trans_mode = SPI_TRANSMODE_FULLDUPLEX;
    // spi_init_struct.device_mode = SPI_MASTER;
    // spi_init_struct.frame_size = SPI_FRAMESIZE_8BIT;
    // spi_init_struct.clock_polarity_phase = SPI_CK_PL_LOW_PH_2EDGE;
    // spi_init_struct.nss = SPI_NSS_SOFT;
    // spi_init_struct.prescale = SPI_PSC_256;
    // spi_init_struct.endian = SPI_ENDIAN_MSB;
    // spi_init(SPI1, &spi_init_struct);

    // spi_enable(SPI1);
    // while (1) {
    //     spi_i2s_data_transmit(SPI1, 0x99);
    // }

    drv_w25q16_init("spi1_dev0", "w25q16");
    RT_CHECK(drv_ms5611_init("spi1_dev2", "barometer2"));
    drv_icm20948_init("spi1_dev1", "gyro2", "accel2", "mag2");

    // RT_CHECK(drv_icm20689_init("spi1_dev1", "gyro0", "accel0"));
    // RT_CHECK(drv_bmi055_init("spi1_dev3", "gyro1", "accel1"));
    // RT_CHECK(drv_ms5611_init("spi4_dev1", "barometer"));
    // /* if no gps mag then use onboard mag */
    // if (drv_ist8310_init("i2c1_dev1", "mag0") != RT_EOK) {
    //     RT_CHECK(drv_ist8310_init("i2c3_dev1", "mag0"));
    // }
    // RT_CHECK(pmw3901_fl04_drv_init("serial6"));
    // RT_CHECK(gps_m8n_init("serial3", "gps"));

    /* register sensor to sensor hub */
    FMT_CHECK(register_sensor_imu("gyro0", "accel0", 0));
    FMT_CHECK(register_sensor_mag("mag0", 0));
    FMT_CHECK(register_sensor_barometer("barometer"));
    // FMT_CHECK(advertise_sensor_optflow(0));
    // FMT_CHECK(advertise_sensor_rangefinder(0));

    // if (drv_ms4525_init("i2c2_dev1", "airspeed") == RT_EOK) {
    //     FMT_CHECK(register_sensor_airspeed("airspeed"));
    // } else {
    //     printf("ms4525 driver init fail!\n");
    // }
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

    /* init rc */
    // FMT_CHECK(pilot_cmd_init());

    /* init gcs */
    FMT_CHECK(gcs_cmd_init());

    /* init auto command */
    FMT_CHECK(auto_cmd_init());

    /* init mission data */
    FMT_CHECK(mission_data_init());

#if defined(FMT_HIL_WITH_ACTUATOR) || (!defined(FMT_USING_HIL) && !defined(FMT_USING_SIH))
    /* init actuator */
    FMT_CHECK(actuator_init());
#endif

    /* start device message queue work */
    FMT_CHECK(devmq_start_work());

    /* initialize power management unit */
    // FMT_CHECK(pmu_init());

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
