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

#include "default_config.h"
#include "driver/barometer/ms5611.h"
#include "driver/gps/gps_dronecan.h"
#include "driver/gps/gps_ubx.h"
#include "driver/imu/bmi055.h"
#include "driver/imu/icm20649.h"
#include "driver/imu/icm20948.h"
#include "driver/mag/ist8310.h"
#include "driver/mtd/ramtron.h"
#include "driver/rgb_led/rgb_dronecan.h"
#include "drv_adc.h"
#include "drv_fdcan.h"
#include "drv_gpio.h"
#include "drv_i2c.h"
#include "drv_pwm.h"
#include "drv_sdio.h"
#include "drv_spi.h"
#include "drv_systick.h"
#include "drv_timer.h"
#include "drv_usart.h"
#include "drv_usbd_cdc.h"
#include "led.h"
#include "model/control/control_interface.h"
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/console/console_config.h"
#include "module/dronecan/dronecan.h"
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
 * @brief Enable on-board device power supply
 *
 */
static void EnablePower(void)
{
    /* do nothing */
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
    HAL_RCC_DeInit();

    __set_PRIMASK(0);
    __set_BASEPRI(0);

    LL_FLASH_SetLatency(LL_FLASH_LATENCY_4);
    while (LL_FLASH_GetLatency() != LL_FLASH_LATENCY_4) {
    }
    LL_PWR_ConfigSupply(LL_PWR_LDO_SUPPLY);
    LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE0);
    while (LL_PWR_IsActiveFlag_VOS() == 0) {
    }
    LL_RCC_HSE_Enable();

    /* Wait till HSE is ready */
    while (LL_RCC_HSE_IsReady() != 1) {
    }
    LL_RCC_PLL_SetSource(LL_RCC_PLLSOURCE_HSE);
    LL_RCC_PLL1P_Enable();
    LL_RCC_PLL1Q_Enable();
    LL_RCC_PLL1R_Enable();
    LL_RCC_PLL1_SetVCOInputRange(LL_RCC_PLLINPUTRANGE_8_16);
    LL_RCC_PLL1_SetVCOOutputRange(LL_RCC_PLLVCORANGE_WIDE);
    LL_RCC_PLL1_SetM(2);
    LL_RCC_PLL1_SetN(80);
    LL_RCC_PLL1_SetP(2);
    LL_RCC_PLL1_SetQ(8);
    LL_RCC_PLL1_SetR(2);
    LL_RCC_PLL1_Enable();

    /* Wait till PLL is ready */
    while (LL_RCC_PLL1_IsReady() != 1) {
    }

    /* Intermediate AHB prescaler 2 when target frequency clock is higher than 80 MHz */
    LL_RCC_SetAHBPrescaler(LL_RCC_AHB_DIV_2);

    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL1);

    /* Wait till System clock is ready */
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL1) {
    }
    LL_RCC_SetSysPrescaler(LL_RCC_SYSCLK_DIV_1);
    LL_RCC_SetAHBPrescaler(LL_RCC_AHB_DIV_2);
    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
    LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_2);
    LL_RCC_SetAPB3Prescaler(LL_RCC_APB3_DIV_2);
    LL_RCC_SetAPB4Prescaler(LL_RCC_APB4_DIV_2);
    LL_SetSystemCoreClock(480000000);

    LL_RCC_PLL3Q_Enable();
    LL_RCC_PLL3_SetVCOInputRange(LL_RCC_PLLINPUTRANGE_1_2);
    LL_RCC_PLL3_SetVCOOutputRange(LL_RCC_PLLVCORANGE_WIDE);
    LL_RCC_PLL3_SetM(14);
    LL_RCC_PLL3_SetN(140);
    LL_RCC_PLL3_SetP(5);
    LL_RCC_PLL3_SetQ(5);
    LL_RCC_PLL3_SetR(2);
    LL_RCC_PLL3_Enable();

    /* Wait till PLL is ready */
    while (LL_RCC_PLL3_IsReady() != 1) {
    }

    /* Update the time base */
    if (HAL_InitTick(TICK_INT_PRIORITY) != HAL_OK) {
        Error_Handler();
    }

    LL_RCC_SetSPIClockSource(LL_RCC_SPI123_CLKSOURCE_PLL1Q);
    LL_RCC_SetSPIClockSource(LL_RCC_SPI45_CLKSOURCE_PCLK2);
    LL_RCC_SetSDMMCClockSource(LL_RCC_SDMMC_CLKSOURCE_PLL1Q);
    LL_RCC_SetUSARTClockSource(LL_RCC_USART16_CLKSOURCE_PCLK2);
    LL_RCC_SetUSARTClockSource(LL_RCC_USART234578_CLKSOURCE_PCLK1);
    LL_RCC_SetFDCANClockSource(LL_RCC_FDCAN_CLKSOURCE_PLL1Q);
    LL_RCC_SetUSBClockSource(LL_RCC_USB_CLKSOURCE_PLL3Q);

    __HAL_RCC_D2SRAM1_CLK_ENABLE();
    __HAL_RCC_D2SRAM2_CLK_ENABLE();
    __HAL_RCC_D2SRAM3_CLK_ENABLE();
}

/* this function will be called before rtos start, which is not in the thread context */
void bsp_early_initialize(void)
{
    /* Enable CPU L1-cache */
    CPU_CACHE_Enable();

    /* init system heap */
    // rt_system_heap_init((void*)SYSTEM_FREE_MEM_BEGIN, (void*)SYSTEM_FREE_MEM_END);
    rt_system_heap_init((void*)SYSTEM_FREE_MEM_BEGIN, (void*)SYSTEM_FREE_MEM_END);

    /* HAL library initialization */
    HAL_Init();

    /* System clock initialization */
    SystemClock_Config();

    /* usart driver init */
    RT_CHECK(drv_usart_init());

    /* init console to enable console output */
    FMT_CHECK(console_init());

    /* systick driver init */
    RT_CHECK(drv_systick_init());

    /* system time module init */
    FMT_CHECK(systime_init());

    /* gpio driver init */
    RT_CHECK(drv_gpio_init());

    /* spi driver init */
    RT_CHECK(drv_spi_init());

    /* i2c driver init */
    RT_CHECK(drv_i2c_init());

    /* pwm driver init */
    RT_CHECK(drv_pwm_init());

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

    /* init storage devices */
    RT_CHECK(drv_sdio_init());

    /* fdcan driver init */
    RT_CHECK(drv_fdcan_init());

    RT_CHECK(dronecan_init());

    /* fram init */
    RT_CHECK(drv_ramtron_init("spi2_dev1"));

    /* init file system */
    FMT_CHECK(file_manager_init(mnt_table));

    /* init parameter system */
    FMT_CHECK(param_init());

    /* init usbd_cdc */
    RT_CHECK(drv_usb_cdc_init());

    /* adc driver init */
    RT_CHECK(drv_adc_init());

    /* ist8310 and ncp5623c are on gps module and possibly it is not connected */
    drv_rgb_dronecan_init("fdcan1");

#if defined(FMT_USING_SIH) || defined(FMT_USING_HIL)
    FMT_CHECK(advertise_sensor_imu(0));
    FMT_CHECK(advertise_sensor_mag(0));
    FMT_CHECK(advertise_sensor_baro(0));
    FMT_CHECK(advertise_sensor_gps(0));
    FMT_CHECK(advertise_sensor_airspeed(0));
#else
    /* init onboard sensors */
    RT_CHECK(drv_icm20649_init("spi1_dev1", "gyro0", "accel0"));
    RT_CHECK(drv_icm20948_init("spi4_dev2", "gyro1", "accel1", "mag0"));
    RT_CHECK(drv_ms5611_init("spi1_dev2", "barometer"));
    RT_CHECK(gps_dronecan_init("fdcan1", "can_gps"));

    // // /* register sensor to sensor hub */
    FMT_CHECK(register_sensor_imu("gyro0", "accel0", 0));
    FMT_CHECK(register_sensor_mag("mag0", 0));
    FMT_CHECK(register_sensor_barometer("barometer"));
#endif

    /* init finsh */
    finsh_system_init();
    /* Mount finsh to console after finsh system init */
    FMT_CHECK(console_enable_input());

#ifdef FMT_USING_CM_BACKTRACE
    /* cortex-m backtrace */
    cm_backtrace_init("fmt_fmu-v5", TARGET_NAME, FMT_VERSION);
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

    /* init auto command */
    FMT_CHECK(auto_cmd_init());

    /* init mission data */
    FMT_CHECK(mission_data_init());

    /* init actuator */
    FMT_CHECK(actuator_init());

    /* start device message queue work */
    FMT_CHECK(devmq_start_work());

    /* initialize led */
    FMT_CHECK(led_control_init());

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
