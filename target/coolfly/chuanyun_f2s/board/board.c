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

#include "board_device.h"
#include "driver/barometer/ms5611.h"
#include "driver/barometer/spl06.h"
#include "driver/gps/gps_ubx.h"
#include "driver/imu/bmi055.h"
#include "driver/imu/bmi088.h"
// #include "driver/imu/icm20600.h"
#include "driver/mag/ist8310.h"
#include "driver/mag/mmc5983ma.h"
#include "driver/mtd/ramtron.h"
// #include "driver/range_finder/tfmini_s.h"
#include "driver/mtd/spi_tfcard.h"
#include "driver/rgb_led/aw2023.h"
// #include "driver/rgb_led/ncp5623c.h"
// #include "driver/vision_flow/lc307.h"

#include "driver/vision_flow/pmw3901_fl04.h"
#include "ntc.h"

#include "drv_adc.h"
#include "drv_gpio.h"
#include "drv_i2c.h"
#include "drv_pwm.h"
#include "drv_sdio.h"
#include "drv_spi.h"
#include "drv_systick.h"
#include "drv_usart.h"
// #include "drv_usbd_cdc.h"
#include "led.h"
// #include "tone_alarm.h"
#include "drv_buzzer_pwm.h"

#include "default_config.h"
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
#include "module/sysio/gcs_cmd.h"
#include "module/sysio/mission_data.h"
#include "module/sysio/pilot_cmd.h"
#include "module/sysio/pilot_cmd_config.h"
#include "module/task_manager/task_manager.h"
#include "module/toml/toml.h"
#include "module/utils/devmq.h"
#include "module/workqueue/workqueue_manager.h"

#include "tone_alarm.h"

#ifdef FMT_USING_SIH
    #include "model/plant/plant_interface.h"
#endif

#include "ar1002_chip.h"
#include "ar1002_hal.h"
#include "cmd_line.h"
#include "debuglog.h"

#include "bb_com.h"
#include "bb_led.h"
#include "sensor_temperature.h"
#include "sky_sbus.h"
#include "xc7027.h"

#define MATCH(a, b)     (strcmp(a, b) == 0)
#define SYS_CONFIG_FILE "/sys/sysconfig.toml"

static const struct dfs_mount_tbl mnt_table[] = {

#ifdef USED_RAMTRON
    { "mtdblk0", "/", "elm", 0, NULL },
#else
    { "tfcard", "/", "elm", 0, NULL },
#endif
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

    //
    // console_println("            :1tfffffffffffffffffffffffffffffffffffti,              ");
    // console_println("        .1fffffffffffffffffffffffffffffffffffffffffffft;           ");
    // console_println("      :tfffffffffffffffffffffffffffffffffffffffffffffffff1         ");
    // console_println("    .tffffffffffti:::itffffffffffffffffffffffffffffffffffff;       ");
    // console_println("   ,fffffffft,           ,tfffffffffffffffffffffffffffffffff1      ");
    // console_println("  ,ffffffft.    ,itfti,    .1ffffffffffffffffffff1   ;fffffffi     ");
    // console_println("  tffffffi   .1fffffffff1.   .tfffffffffffffffffff:   ,fffffff:    ");
    // console_println(" ,fffffff.  .tfft,   ,tffft,   1ffffffffffi    ifff1   :fffffft    ");
    // console_println(" ;ffffff1   ifft      .ffffff1;:fffffffff;      ;fff.  .fffffff.   ");
    // console_println(" ;ffffff1   ;fff.     ,ffLffffff1 ,itffffi      ifff.  .fffffff.   ");
    // console_println(" ,fffffff,   1fffi:,:1fffffffffffi   .1ffft;,,;tfff:   iffffff1    ");
    // console_println("  1fffffft    ;ffffffffffffffffffft.   .1ffffffff1.   ;fffffff,    ");
    // console_println("  .tfffffff;  :ffffffffffffffffffffft.    .,::,.    .1fffffff;     ");
    // console_println("   .tffffffffffffffffffffffffffffffffft;          ;tffffffff;      ");
    // console_println("     ;fffffffffffffffffffffffffffffffffffffttttffffffffffft.       ");
    // console_println("       ifffffffffffffffffffffffffffffffffffffffffffffffff,         ");
    // console_println("         ,tfffffffffffffffffffffffffffffffffffffffffff;            ");
    // console_println("             .itfffffffffffffffffffffffffffffffft1:                ");

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

static fmt_err_t bsp_parse_toml_sysconfig(toml_table_t* root_tab)
{
    fmt_err_t     err = FMT_EOK;
    toml_table_t* sub_tab;
    const char*   key;
    const char*   raw;
    char*         target;
    int           i;

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
 * @brief Enable on-board device power supply
 *
 */
static void EnablePower(void)
{
    /* Wait some time for power becoming stable */
    // systime_mdelay(100);
}

/*
 * When enabling the D-cache there is cache coherency issue.
 * This matter crops up when multiple masters (CPU, DMAs...)
 * share the memory. If the CPU writes something to an area
 * that has a write-back cache attribute (example SRAM), the
 * write result is not seen on the SRAM as the access is
 * buffered, and then if the DMA reads the same memory area
 * to perform a data transfer, the values read do not match
 * the intended data. The issue occurs for DMA read as well.
 * Currently not all drivers can ensure the data coherency
 * when D-Cache enabled, so disable it by default.
 */
/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void)
{
    /* Enable I-Cache */
    // SCB_EnableICache();

    /* Enable D-Cache */
    // SCB_EnableDCache();
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
    console_printf("Enter Error_Handler\n");
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) {
    }
    /* USER CODE END Error_Handler_Debug */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
}

void cf_delay_ms(uint32_t num)
{
    volatile uint32_t i;

    for (i = 0; i < (num * 1000); i++) {
        ;
    }
}

// void test_led(void)
// {
//     // test_led
//     HAL_GPIO_OutPut(HAL_GPIO_NUM61);
//     uint8_t i = 5;
//     while (i--) {
//         HAL_GPIO_SetPin(HAL_GPIO_NUM61, HAL_GPIO_PIN_SET);
//         cf_delay_ms(1000);
//         HAL_GPIO_SetPin(HAL_GPIO_NUM61, HAL_GPIO_PIN_RESET);
//         cf_delay_ms(1000);
//     }
// }

#define MAX_WQ_SIZE 10
extern WorkQueue_t wq_list[MAX_WQ_SIZE];

fmt_err_t chuanyun_workqueue_manager_init(void)
{
    wq_list[2] = workqueue_create("wq:sysevent_work", 5, 8192, 1);
    RT_ASSERT(wq_list[2] != NULL);

    return FMT_EOK;
}

/* this function will be called before rtos start, which is not in the thread context */
void bsp_early_initialize(void)
{
    // /* Enable CPU L1-cache */
    // CPU_CACHE_Enable();

    HAL_GPIO_OutPut(WD_DONE_GPIO); // wd_done
    HAL_GPIO_SetPin(WD_DONE_GPIO, HAL_GPIO_PIN_SET);

#ifdef SENSOR_POWER_GPIO
    HAL_GPIO_OutPut(SENSOR_POWER_GPIO); //
    HAL_GPIO_SetPin(SENSOR_POWER_GPIO, HAL_GPIO_PIN_RESET);
#endif

    HAL_GPIO_OutPut(LINK_LED_GPIO); // blue led close
    HAL_GPIO_SetPin(LINK_LED_GPIO, HAL_GPIO_PIN_SET);

    HAL_GPIO_OutPut(VIDEO_LED_GPIO); // red led close
    HAL_GPIO_SetPin(VIDEO_LED_GPIO, HAL_GPIO_PIN_SET);

#ifdef RGB_R_GPIO
    HAL_GPIO_OutPut(RGB_R_GPIO); // rgb1 R led close
    HAL_GPIO_SetPin(RGB_R_GPIO, HAL_GPIO_PIN_RESET);
#endif

#ifdef RGB_G_GPIO
    HAL_GPIO_OutPut(RGB_G_GPIO); // rgb1 G led close
    HAL_GPIO_SetPin(RGB_G_GPIO, HAL_GPIO_PIN_RESET);
#endif

#ifdef RGB_B_GPIO
    HAL_GPIO_OutPut(RGB_B_GPIO); // rgb1 B led close
    HAL_GPIO_SetPin(RGB_B_GPIO, HAL_GPIO_PIN_RESET);
#endif

#ifdef SENSOR_POWER_GPIO
    HAL_GPIO_SetPin(SENSOR_POWER_GPIO, HAL_GPIO_PIN_SET);
#endif

#ifdef FUM_CTRL_GPIO
    HAL_GPIO_OutPut(FUM_CTRL_GPIO);
    HAL_GPIO_SetPin(FUM_CTRL_GPIO, HAL_GPIO_PIN_SET);
#endif

    /* init system heap */
    rt_system_heap_init((void*)SYSTEM_FREE_MEM_BEGIN, (void*)SYSTEM_FREE_MEM_END);

    dlog_set_output_level(4);

    STRU_HAL_SYS_CTL_CONFIG* pst_cfg;
    HAL_SYS_CTL_GetConfig(&pst_cfg);

    /* System clock initialization */
    /* ICATCH  DCATCH         */
    pst_cfg->u8_workMode = 0;
    HAL_SYS_CTL_Init(pst_cfg);

    SYS_EVENT_RegisterHandler(SYS_EVENT_ID_BB_EVENT, bb_led_status_EventHandler);

    // SystemClock_Config();

    /* usart driver init */
    RT_CHECK(drv_usart_init());

    /* init console to enable console output */
    FMT_CHECK(console_init());

    // console_println("------------------FMT Firmware---------------------");
    console_println("Build time: %s %s", __DATE__, __TIME__);

    DLOG_Init(NULL, NULL, DLOG_SERVER_PROCESSOR);
    DLOG_Process(NULL);

    /* systick driver init */
    RT_CHECK(drv_systick_init());

    /* system time module init */
    FMT_CHECK(systime_init());

    HAL_NV_Init();

    HAL_USB_ConfigPHY();

    /* gpio driver init */
    RT_CHECK(drv_gpio_init());

    /* spi driver init */
    RT_CHECK(drv_spi_init());

    /* i2c driver init */
    RT_CHECK(drv_i2c_init());

    /* pwm driver init */
    RT_CHECK(drv_pwm_init());

    /* buzzer pwm driver init */
    RT_CHECK(drv_buzzer_pwm_init());

    /* system statistic module */
    FMT_CHECK(sys_stat_init());
}

/* this function will be called after rtos start, which is in thread context */
void bsp_initialize(void)
{
    /* enable on-board power supply */
    EnablePower();

    /* start recording boot log */
    FMT_CHECK(boot_log_init());

    /* init uMCN */
    FMT_CHECK(mcn_init());

    /* create workqueue */
    FMT_CHECK(workqueue_manager_init());
    FMT_CHECK(chuanyun_workqueue_manager_init());

    /* init storage devices */
    // RT_CHECK(drv_sdio_init());
    // console_println("drv_sdio_init~");

    /* fram init */
#ifdef USED_RAMTRON
    if (FMT_EOK != drv_ramtron_init("spi6_dev1")) {
        console_println("=================> can't find the ramtron on spi6_dev1");
    }
#endif

    if (FMT_EOK != drv_spi_tfcard_init("spi1_dev1", "tfcard")) {
        console_println("tfcard init failed!");
    }

    /* init file system */
    if (FMT_EOK != file_manager_init(mnt_table)) {
        console_println("=================> mtd first used => pleaserun:  mkfs mtdblk0 ");
    }

    /* init parameter system */
    FMT_CHECK(param_init());

    /* init usbd_cdc */
    // RT_CHECK(drv_usb_cdc_init());

    /* adc driver init */
    RT_CHECK(drv_adc_init());

    RT_CHECK(drv_aw2023_init("i2c3_dev1"));

    /* ist8310 and ncp5623c are on gps module and possibly it is not connected */
    // drv_ncp5623c_init("i2c3_dev1");

#if defined(FMT_USING_SIH) || defined(FMT_USING_HIL)
    FMT_CHECK(advertise_sensor_imu(0));
    FMT_CHECK(advertise_sensor_mag(0));
    FMT_CHECK(advertise_sensor_baro(0));
    FMT_CHECK(advertise_sensor_gps(0));
#else

    /* init onboard sensors */
    // RT_CHECK(drv_icm20600_init("spi2_dev1", "gyro0", "accel0"));
    // RT_CHECK(drv_icm20689_init("spi1_dev1", "gyro0", "accel0"));

    #ifdef USED_BMI055
    RT_CHECK(drv_bmi055_init("spi2_dev2", "spi2_dev3", "gyro0", "accel0", 0));
    #endif

    #ifdef USED_BMI088
    RT_CHECK(drv_bmi088_init("spi2_dev2", "spi2_dev3", "gyro0", "accel0", 0));
    #endif

    #ifdef USED_MS5611
    RT_CHECK(drv_ms5611_init("spi3_dev1", "barometer"));
    #endif

    #ifdef USED_SPL06
    RT_CHECK(drv_spl06_init("spi3_dev2", "barometer"));
    #endif

    /* if no gps mag then use onboard mag */
    #ifdef USED_IST8310
    if (drv_ist8310_init("i2c3_dev2", "mag1") != FMT_EOK) {
        console_println("!!!!!!drv_ist8310_init i2c3_dev2 faild~!!!!");
    } else {
        console_println("drv_ist8310_init i2c3_dev2~");
        FMT_CHECK(register_sensor_mag("mag1", 1));
    }
    #endif

    #ifdef USED_MMC5983MA
    if (drv_mmc5983ma_init("i2c2_dev2", "mag0") != FMT_EOK) {
        console_println("!!!!!!mmc5983ma i2c2_dev2 faild~!!!!");
    } else {
        FMT_CHECK(register_sensor_mag("mag0", 0));
    }
    #endif

    RT_CHECK(gps_ubx_init("serial1", "gps"));

    RT_CHECK(drv_ntc_init("adc9", "temp_board"));

    // if (tfmini_s_drv_init("serial4") != FMT_EOK) {
    //     console_println("!!!!!!tfmini_s serial4 faild~!!!!");
    // } else {
    //     FMT_CHECK(advertise_sensor_rangefinder(0));
    // }

    // if (lc307_drv_init("serial5") != FMT_EOK) {
    //     console_println("!!!!!!lc307 serial5 faild~!!!!");
    // }
    // else
    // {
    //     FMT_CHECK(advertise_sensor_optflow(0));
    // }

    // if (pmw3901_xx_drv_init("serial4") != FMT_EOK) {
    //     console_println("!!!!!!pmw3901_xx serial4 faild~!!!!");
    // } else {
    //     // console_println("======> pmw3901_xx serial4 success !!!!");
    //     FMT_CHECK(advertise_sensor_rangefinder(0));
    //     FMT_CHECK(advertise_sensor_optflow(0));
    // }

    if (pmw3901_fl04_drv_init("serial5") != FMT_EOK) {
        console_println("!!!!!!pmw3901_fl04 serial5 faild~!!!!");
    } else {
        // console_println("======> pmw3901_xx serial4 success !!!!");
        FMT_CHECK(advertise_sensor_rangefinder(0));
        FMT_CHECK(advertise_sensor_optflow(0));
    }

    /* register sensor to sensor hub */
    FMT_CHECK(register_sensor_imu("gyro0", "accel0", 0));

    FMT_CHECK(register_sensor_barometer("barometer"));

    FMT_CHECK(register_sensor_temperature("temp_board", 0));

#endif

    FMT_CHECK(register_ar_rc());
    FMT_CHECK(register_bb_com());

    /* init finsh */
    finsh_system_init();

    /* Mount finsh to console after finsh system init */
    FMT_CHECK(console_enable_input());

#ifdef FMT_USING_CM_BACKTRACE
    /* cortex-m backtrace */
    cm_backtrace_init("fmt_chuanyun_f2s", TARGET_NAME, FMT_VERSION);

#endif
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
    FMT_CHECK(pilot_cmd_init());

    /* init gcs */
    FMT_CHECK(gcs_cmd_init());

    /* init mission data */
    FMT_CHECK(mission_data_init());

#if defined(FMT_HIL_WITH_ACTUATOR) || (!defined(FMT_USING_HIL) && !defined(FMT_USING_SIH))
    /* init actuator */
    FMT_CHECK(actuator_init());
#endif

    /* start device message queue work */
    FMT_CHECK(devmq_start_work());

#ifdef USED_RGB
    /* initialize led */
    FMT_CHECK(led_control_init());
#endif

    FMT_CHECK(xc7027_init());

    FMT_CHECK(tone_alarm_init("buzzer_pwm"));

    /* initialize power management unit */
    FMT_CHECK(pmu_init());

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

/* Re-implement this function to define customized rotation */
void icm20600_rotate_to_frd(float* val)
{
    float  tmp;
    float* x = val;
    float* y = val + 1;
    // float *z = *(val +2);

    tmp = *x;
    *x  = *y;
    *y  = -tmp;

    /* do nothing */
}

/* Re-implement this function to define customized rotation */
void bmi088_rotate_to_frd(float val[3])
{
    /* do nothing */
    float* x = val;
    float* y = val + 1;
    *x       = -*x;
    *y       = -*y;
}
