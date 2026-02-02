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

#include <firmament.h>
#include <board.h>
#include <string.h>

#include "module/console/console_config.h"
#include "module/file_manager/file_manager.h"
#include "module/pmu/power_manager.h"
#include "module/sysio/actuator_cmd.h"
#include "module/sysio/actuator_config.h"
#include "module/sysio/pilot_cmd.h"
#include "module/sysio/pilot_cmd_config.h"
#include "module/task_manager/task_manager.h"
#include "module/workqueue/workqueue_manager.h"
#include "module/toml/toml.h"
#include "module/sensor/sensor_hub.h"
#include "module/mavproxy/mavproxy.h"
#include "drv_usbd_cdc.h"

// Hardware Drivers
#include "drv_gpio.h"
#include "drv_usart.h"
#include "drv_spi.h"
#include "drv_i2c.h"
#include "drv_pwm.h"
#include "drv_systick.h"
#include "drv_sdio.h"

// Sensor Drivers
#include "driver/imu/bmi088.h"
#include "driver/imu/bmi055.h"
#include "driver/imu/icm42688p.h"
#include "driver/mtd/ramtron.h"

// System Init
#include "module/param/param.h"
#include "module/system/systime.h"
#include "module/mavproxy/mavproxy.h"

// Missing declarations
extern void finsh_system_init(void);

// Mount Table
static const struct dfs_mount_tbl mnt_table[] = {
    { "sd0", "/", "elm", 0, NULL },
    { "mtdblk0", "/mnt/mtdblk0", "elm", 0, NULL },
    { NULL } /* NULL indicate the end */
};

/* Empty mount table for fallback when SD card fails */
const struct dfs_mount_tbl mnt_table_empty[] = {
    { NULL }
};

void SystemClock_Config(void);
void Error_Handler(void);

static void MPU_Config(void)
{
    MPU_Region_InitTypeDef MPU_InitStruct = { 0 };

    /* Disable the MPU before configure */
    HAL_MPU_Disable();

    /* Configure the MPU attributes for AXI SRAM (0x24000000) */
    /* Since D-Cache is disabled, set as NOT cacheable to match actual CPU state */
    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.BaseAddress = 0x24000000;
    MPU_InitStruct.Size = MPU_REGION_SIZE_512KB;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;  // Match D-Cache disabled state
    MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER0;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    /* Enable the MPU */
    HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

static void CPU_Config(void)
{
    /* Enable MPU with proper configuration */
    MPU_Config();

    /* Disable unaligned access trap - Cortex-M7 supports unaligned access in hardware */
    /* Some bootloaders may enable UNALIGN_TRP, we need to disable it */
    SCB->CCR &= ~SCB_CCR_UNALIGN_TRP_Msk;

    /* Enable I-Cache for better performance */
    SCB_EnableICache();
    
    /* Keep D-Cache disabled to avoid DMA coherency issues with SDMMC */
    // SCB_EnableDCache();
}

void bsp_early_initialize(void)
{
    /* HAL Initialization */
    HAL_Init();
    
    /* Freeze watchdog during debug */
    __HAL_DBGMCU_FREEZE_IWDG1();
    __HAL_DBGMCU_FREEZE_WWDG1();

    /* System Clock Config */
    SystemClock_Config();

    /* CPU Config - MPU and Cache */
    CPU_Config();

    /* Init system heap */
    rt_system_heap_init((void*)SYSTEM_FREE_MEM_BEGIN, (void*)SYSTEM_FREE_MEM_END);

    /* GPIO Driver Initialization */
    RT_CHECK(drv_gpio_init());

    /* Usart Driver Initialization */
    RT_CHECK(drv_usart_init());

    /* Console Initialization */
    FMT_CHECK(console_init());
    
    /* Set console to serial3 (USART3 - Debug Console, PD8/PD9) */
    rt_device_t console_dev = rt_device_find("serial3");
    if (console_dev != RT_NULL) {
        if (rt_device_open(console_dev, RT_DEVICE_OFLAG_WRONLY | RT_DEVICE_FLAG_STREAM) == RT_EOK) {
            rt_console_set_device(console_dev->parent.name);
        }
    }
    
    /* Early debug output */
    rt_kprintf("\r\n\r\n");
    rt_kprintf("====================================\r\n");
    rt_kprintf("FMT Pixhawk 6C Early Boot (GPIO disabled)\r\n");
    rt_kprintf("Console: serial3 (USART3 PD8/PD9)\r\n");
    rt_kprintf("====================================\r\n");

    /* System Tick Configuration */
    RT_CHECK(drv_systick_init());

    /* I2C Driver Initialization */
    RT_CHECK(drv_i2c_init());

    /* SPI Driver Initialization */
    RT_CHECK(drv_spi_init());

    /* PWM Driver Initialization */
    // RT_CHECK(drv_pwm_init());  // Keep PWM disabled for now

    /* System statistic module */
    FMT_CHECK(sys_stat_init());
    
    /* Clear BASEPRI to allow interrupts after scheduler starts */
    /* Do this LAST, after all hardware is initialized */
    __set_BASEPRI(0);
}

static void EnableSensorPower(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
    
    /* Busy-loop delay - 20ms at 480MHz (HAL_Delay doesn't work in early boot) */
    for (volatile uint32_t i = 0; i < 4800000; i++) {
        __NOP();
    }
}

/* This function will be called after RTOS start, which is in thread context */
void bsp_initialize(void)
{
    /* System time module init */
    FMT_CHECK(systime_init());

    /* Start recording boot log */
    FMT_CHECK(boot_log_init());

    /* Enable sensor power */
    EnableSensorPower();

    /* Init uMCN */
    FMT_CHECK(mcn_init());

    /* Create workqueue */
    FMT_CHECK(workqueue_manager_init());

    /* Init storage devices */
    RT_CHECK(drv_sdio_init());
    
    /* Init FRAM */
    RT_CHECK(drv_ramtron_init("spi2_dev1"));
    
    /* Check SD card status to prevent crash in file_manager_init */
    rt_device_t sd0 = rt_device_find("sd0");
    rt_err_t sd_stat = RT_ERROR;
    if (sd0) {
        sd_stat = rt_device_init(sd0);
    }

    /* Init file system */
    if (sd_stat == RT_EOK) {
        FMT_CHECK(file_manager_init(mnt_table));
    } else {
        FMT_CHECK(file_manager_init(mnt_table_empty));
    }

    /* Init parameter system */
    FMT_CHECK(param_init());

    /* Init mavproxy */
    FMT_CHECK(mavproxy_init());

    /* Init usbd_cdc */
    // RT_CHECK(drv_usb_cdc_init());  // Skip USB for now

    /* Give a little delay for threads to settle */
    rt_thread_mdelay(50);

    /* Init onboard sensors */
    int bmi088_started = 0;
    if (drv_bmi088_init("spi1_dev1", "spi1_dev2", "gyro0", "accel0", 0) != RT_EOK) {
        // Try BMI055 if BMI088 fails
        if (drv_bmi055_init("spi1_dev1", "spi1_dev2", "gyro0", "accel0", 0) == RT_EOK) {
            bmi088_started = 1;
        }
    } else {
        bmi088_started = 1;
    }
    
    int icm42688_started = 0;
    if (drv_icm42688_init("spi1_dev3", "gyro1", "accel1", 1) == RT_EOK) {
        icm42688_started = 1;
    }

    /* Register IMUs */
    if (bmi088_started) {
        FMT_CHECK(register_sensor_imu("gyro0", "accel0", 0));
    }
    if (icm42688_started) {
        FMT_CHECK(register_sensor_imu("gyro1", "accel1", 1));
    }

    /* Advertise other sensors */
    FMT_CHECK(advertise_sensor_mag(0));
    FMT_CHECK(advertise_sensor_baro(0));
    FMT_CHECK(advertise_sensor_gps(0));
    FMT_CHECK(advertise_sensor_optflow(0));
    FMT_CHECK(advertise_sensor_rangefinder(0));

    /* Init finsh */
    finsh_system_init();
    
    /* Fallback: if console device is not set (e.g. no SD card config), force it to serial3 */
    if (console_get_device() == NULL) {
        console_set_device("serial3");
    }

    /* Enable console input */
    FMT_CHECK(console_enable_input());
}

void bsp_post_initialize(void)
{
    /* Init rc */
    FMT_CHECK(pilot_cmd_init());

    /* Init actuator */
    FMT_CHECK(actuator_init());

    /* Initialize power management unit */
    FMT_CHECK(pmu_init());
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
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /* Configure the main internal regulator output voltage */
  /* STM32H743VI on Pixhawk 6C uses SMPS */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);
  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 240;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 20;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_1;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) { Error_Handler(); }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2|RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK) { Error_Handler(); }

  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_SPI1|RCC_PERIPHCLK_SPI2|RCC_PERIPHCLK_I2C4;
  PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_D2PCLK1;
  PeriphClkInitStruct.Spi123ClockSelection = RCC_SPI123CLKSOURCE_PLL;
  PeriphClkInitStruct.I2c4ClockSelection = RCC_I2C4CLKSOURCE_D3PCLK1;

  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK) { Error_Handler(); }
}

void Error_Handler(void)
{
    __disable_irq();
    while (1)
    {
    }
}
