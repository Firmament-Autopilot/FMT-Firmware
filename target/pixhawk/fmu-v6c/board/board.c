/******************************************************************************
 * Copyright 2023 The Firmament Authors. All Rights Reserved.
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

#include <board.h>
#include <board_device.h>
#include <firmament.h>
#include <msh.h>
#include <shell.h>
#include <string.h>

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
#include "module/system/statistic.h"
#include "module/task_manager/task_manager.h"
#include "module/toml/toml.h"
#include "module/utils/devmq.h"
#include "module/workqueue/workqueue_manager.h"

// Default Configuration
#include "default_config.h"

// Hardware Drivers
#include "drv_adc.h"
#include "drv_gpio.h"
#include "drv_i2c.h"
#include "drv_pwm.h"
#include "drv_sdio.h"
#include "drv_spi.h"
#include "drv_systick.h"
#include "drv_usart.h"
#include "hal/i2c/i2c.h"
#include "led.h"
#include "stm32h7xx_ll_i2c.h"
#include "usbd/drv_usbd_cdc.h"

// Sensor Drivers
#include "driver/barometer/ms5611.h"
#include "driver/gps/gps_ubx.h"
#include "driver/imu/bmi055.h"
#include "driver/imu/icm42688p.h"
#include "driver/mag/ist8310.h"
#include "driver/mtd/ramtron.h"
#include "driver/vision_flow/mtf_01.h"

// System Init
#include "module/log/boot_log.h"
#include "module/param/param.h"
#include "module/system/systime.h"
#ifdef FMT_USING_SIH
    #include "model/plant/plant_interface.h"
#endif

#define MATCH(a, b)     (strcmp(a, b) == 0)
#define SYS_CONFIG_FILE "/sys/sysconfig.toml"
#define SYS_INIT_SCRIPT "/sys/init.sh"

// Mount Table
static const struct dfs_mount_tbl mnt_table[] = {
    { "sd0", "/", "elm", 0, NULL },
    /* FRAM (mtdblk0) is NOT mounted as filesystem.
     * It is used for direct parameter backup storage.
     * Parameters are automatically backed up to FRAM when saved to SD card,
     * and loaded from FRAM if SD card fails to load. */
    { NULL } /* NULL indicate the end */
};

/* Empty mount table for fallback when SD card fails */
const struct dfs_mount_tbl mnt_table_empty[] = {
    { NULL }
};

void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
void Error_Handler(void);

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

static void MPU_Config(void)
{
    MPU_Region_InitTypeDef MPU_InitStruct = { 0 };

    /* Disable the MPU before configure */
    HAL_MPU_Disable();

    /* Configure the MPU attributes as WT for AXI SRAM */
    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.BaseAddress = 0x24000000;
    MPU_InitStruct.Size = MPU_REGION_SIZE_512KB;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER0;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    // MPU_REGION_NUMBER1 reserved for stack/heap override if needed

    /* Configure the MPU attributes as Device not cacheable
       for ETH DMA descriptors */
    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.BaseAddress = 0x30040000;
    MPU_InitStruct.Size = MPU_REGION_SIZE_256B;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER2;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    /* Configure the MPU attributes as Cacheable write through
       for LwIP RAM heap which contains the Tx buffers */
    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.BaseAddress = 0x30044000;
    MPU_InitStruct.Size = MPU_REGION_SIZE_16KB;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER3;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    /* Enable the MPU */
    HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

static void CPU_Config(void)
{
    MPU_Config();

    /* Enable I-Cache */
    SCB_EnableICache();

    /* Enable D-Cache */
    // SCB_EnableDCache();
}

static void EnableSensorPower(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    /* Enable GPIO Clocks */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();

    /* Common Configuration */
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    /* PB2: VDD_3V3_SENSORS_EN (Pull High to Enable per user request)
     * Enable 3.3V sensors rail for sensors
     */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    /* Drive PB2 HIGH to enable 3.3V sensors rail */
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);

    /* PC10: N_VDD_5V_HIPOWER_EN (active low). Enable 5V high-power rail for peripherals */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    /* Drive PC10 LOW (active low) to enable 5V high-power rail */
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET);

    /* PE2: N_VDD_5V_PERIPH_EN (active low). Enable 5V peripheral rail for GPS/peripherals */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
    /* Drive PE2 LOW (active low) to enable 5V peripheral rail */
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);

    /* Power rail stabilization delay - 100ms at 480MHz */
    for (volatile uint32_t i = 0; i < 24000000; i++) {
        __NOP();
    }
}

void bsp_early_initialize(void)
{
    /* CPU config */
    CPU_Config();

    /* Manually zero SPI handles to ensure clean state */
    extern SPI_HandleTypeDef hspi1, hspi2;
    memset(&hspi1, 0, sizeof(hspi1));
    memset(&hspi2, 0, sizeof(hspi2));

    /* init system heap */
    // Ensure 4-byte alignment
    rt_ubase_t heap_start = (rt_ubase_t)SYSTEM_FREE_MEM_BEGIN;
    if (heap_start & 0x03) {
        heap_start = (heap_start + 4) & ~0x03;
    }

    // [Fix] Ensure heap starts AFTER the stack, not just after BSS
    extern int _estack;
    if (heap_start < (rt_ubase_t)&_estack) {
        heap_start = (rt_ubase_t)&_estack;
    }

    rt_system_heap_init((void*)heap_start, (void*)SYSTEM_FREE_MEM_END);

    /* HAL library initialization */
    HAL_Init();

    /* initialize simple LED GPIOs immediately so boot failures show red */
    led_early_init();

    /* System clock initialization */
    SystemClock_Config();
    PeriphCommonClock_Config();

    /* gpio driver init */
    RT_CHECK(drv_gpio_init());

    /* usart driver init */
    RT_CHECK(drv_usart_init());

    /* init console to enable console output */
    FMT_CHECK(console_init());

    /* systick driver init */
    RT_CHECK(drv_systick_init());

    /* early debug info */
    console_println("FMT Pixhawk 6C Booting...");

    /* Enable sensor power BEFORE initializing SPI */
    EnableSensorPower();

    /* i2c driver init */
    RT_CHECK(drv_i2c_init());

    /* spi driver init */
    RT_CHECK(drv_spi_init());

    /* pwm driver init */
    RT_CHECK(drv_pwm_init());

    /* system statistic module */
    FMT_CHECK(sys_stat_init());

    __set_BASEPRI(0);
}

/* this function will be called after rtos start, which is in thread context */
void bsp_initialize(void)
{
    /* system time module init */
    FMT_CHECK(systime_init());

    /* start recording boot log */
    FMT_CHECK(boot_log_init());

    /* init uMCN */
    FMT_CHECK(mcn_init());

    /* create workqueue */
    FMT_CHECK(workqueue_manager_init());

    /* init storage devices */
    RT_CHECK(drv_sdio_init());

    /* Delay for SPI2 and FRAM power stabilization */
    RT_CHECK(drv_ramtron_init("spi2_dev1"));

    /* Check SD card status to prevent crash in file_manager_init */
    rt_device_t sd0 = rt_device_find("sd0");
    rt_err_t sd_stat = RT_ERROR;

    if (sd0) {
        sd_stat = rt_device_init(sd0);
        if (sd_stat != RT_EOK) {
            console_println("Info: SD card not detected or init failed");
        }
    }

    /* Init file system */
    if (sd_stat == RT_EOK) {
        FMT_CHECK(file_manager_init(mnt_table));
    } else {
        FMT_CHECK(file_manager_init(mnt_table_empty));
    }

    /* init parameter system */
    FMT_CHECK(param_init());

    /* init mavproxy */
    FMT_CHECK(mavproxy_init());

    /* init usbd_cdc */
    RT_CHECK(drv_usb_cdc_init());

    /* init ADC driver */
    RT_CHECK(drv_adc_init());

    /* allow some time for sensors to power up */
    rt_thread_mdelay(100);

#if defined(FMT_USING_SIH) || defined(FMT_USING_HIL)
    FMT_CHECK(advertise_sensor_imu(0));
    FMT_CHECK(advertise_sensor_mag(0));
    FMT_CHECK(advertise_sensor_baro(0));
    FMT_CHECK(advertise_sensor_gps(0));
    FMT_CHECK(advertise_sensor_airspeed(0));
    FMT_CHECK(advertise_sensor_optflow(0));
    FMT_CHECK(advertise_sensor_rangefinder(0));
#else
    /* Init onboard sensors */
    /* ICM42688P as primary (ID=0), BMI055 as backup (ID=1)*/
    /* Warm up ICM42688 SPI device via drv_spi helper to avoid including
       HAL SPI internals in board code. */
    drv_spi_warmup_device("spi1_dev3", 0x75);
    RT_CHECK(drv_icm42688_init("spi1_dev3", "gyro0", "accel0", 0));
    RT_CHECK(drv_bmi055_init("spi1_dev2", "spi1_dev1", "gyro1", "accel1", 1));
    RT_CHECK(drv_ms5611_init("i2c4_dev2", "barometer"));
    RT_CHECK(drv_ist8310_init("i2c4_dev1", "mag0", 0));
    // RT_CHECK(drv_mtf_01_init("serial4"));
    RT_CHECK(gps_ubx_init("serial2", "gps")); // GPS1
    // RT_CHECK(gps_ubx_init("serial3", "gps")); //GPS2

    /* register sensor to sensor hub */
    FMT_CHECK(register_sensor_imu("gyro0", "accel0", 0));
    FMT_CHECK(register_sensor_imu("gyro1", "accel1", 1));
    FMT_CHECK(register_sensor_barometer("barometer"));
    FMT_CHECK(register_sensor_mag("mag0", 0));

#endif

    /* init finsh */
    finsh_system_init();

    /* Mount finsh to console after finsh system init */
    FMT_CHECK(console_enable_input());
}

void bsp_post_initialize(void)
{
    if (bsp_parse_toml_sysconfig(toml_parse_config_file(SYS_CONFIG_FILE)) != FMT_EOK) {
        /* use default system configuration */
        printf("Default configuration loaded.\n");
        FMT_CHECK(bsp_parse_toml_sysconfig(toml_parse_config_string(default_conf)));
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

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
    RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

    /** Supply configuration update enable
     */
    HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

    /** Configure the main internal regulator output voltage
     */
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

    while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) { }

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSIState = RCC_HSI_DIV2;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 4;
    RCC_OscInitStruct.PLL.PLLN = 240;
    RCC_OscInitStruct.PLL.PLLP = 2;
    RCC_OscInitStruct.PLL.PLLQ = 8;
    RCC_OscInitStruct.PLL.PLLR = 2;
    RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
    RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
    RCC_OscInitStruct.PLL.PLLFRACN = 0;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
        | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2
        | RCC_CLOCKTYPE_D3PCLK1 | RCC_CLOCKTYPE_D1PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
    RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK) {
        Error_Handler();
    }

    /** Enables the Clock Security System
     */
    HAL_RCC_EnableCSS();
}

void PeriphCommonClock_Config(void)
{
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = { 0 };

    /** Initializes the peripherals clock
     */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USB | RCC_PERIPHCLK_FDCAN | RCC_PERIPHCLK_CKPER | RCC_PERIPHCLK_USART3 | RCC_PERIPHCLK_I2C123 | RCC_PERIPHCLK_I2C4;

    /* Configure USART3 clock source to PCLK1 (APB1)
     * APB1 = 120MHz (HCLK 240MHz / 2)
     * This ensures correct baud rate calculation
     */
    PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_D2PCLK1;

    /* Configure I2C clock sources */
    PeriphClkInitStruct.I2c123ClockSelection = RCC_I2C123CLKSOURCE_D2PCLK1; /* I2C1, I2C2, I2C3 */
    /* Use D3PCLK1 (alias PCLK4) for I2C4 - use HAL-defined macro */
    PeriphClkInitStruct.I2c4ClockSelection = RCC_I2C4CLKSOURCE_D3PCLK1; /* I2C4 -> D3PCLK1 (PCLK4) */

    /* Configure PLL3 for USB: 48MHz = HSE(16MHz) / PLL3M(4) * PLL3N(48) / PLL3Q(4) */
    PeriphClkInitStruct.PLL3.PLL3M = 4;
    PeriphClkInitStruct.PLL3.PLL3N = 48;
    PeriphClkInitStruct.PLL3.PLL3P = 2;
    PeriphClkInitStruct.PLL3.PLL3Q = 4; /* USB clock: 48MHz */
    PeriphClkInitStruct.PLL3.PLL3R = 2;
    PeriphClkInitStruct.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_2;
    PeriphClkInitStruct.PLL3.PLL3VCOSEL = RCC_PLL3VCOWIDE;
    PeriphClkInitStruct.PLL3.PLL3FRACN = 0;
    PeriphClkInitStruct.UsbClockSelection = RCC_USBCLKSOURCE_PLL3;

    /* PLL2 for FDCAN */
    PeriphClkInitStruct.PLL2.PLL2M = 1;
    PeriphClkInitStruct.PLL2.PLL2N = 10;
    PeriphClkInitStruct.PLL2.PLL2P = 2;
    PeriphClkInitStruct.PLL2.PLL2Q = 2;
    PeriphClkInitStruct.PLL2.PLL2R = 2;
    PeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_3;
    PeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOMEDIUM;
    PeriphClkInitStruct.PLL2.PLL2FRACN = 0;
    PeriphClkInitStruct.CkperClockSelection = RCC_CLKPSOURCE_HSI;
    PeriphClkInitStruct.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL2;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK) {
        Error_Handler();
    }
}

void Error_Handler(void)
{
    __disable_irq();
    /* attempt to indicate fatal error via LED */
    led_force_red();
    while (1) {
    }
}
