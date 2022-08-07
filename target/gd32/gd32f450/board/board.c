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
#include "drv_systick.h"
#include "drv_usart.h"
// #include "drv_usbd_cdc.h"
#include "module/file_manager/file_manager.h"
#include "module/task_manager/task_manager.h"
#include "module/toml/toml.h"

#define MATCH(a, b)     (strcmp(a, b) == 0)
#define SYS_CONFIG_FILE "/sys/sysconfig.toml"

static const struct dfs_mount_tbl mnt_table[] = {
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

#define ITEM_LENGTH 42
static void bsp_show_information(void)
{
    char buffer[50];

    console_printf("\n");
    console_println("   _____                               __ ");
    console_println("  / __(_)_____ _  ___ ___ _  ___ ___  / /_");
    console_println(" / _// / __/  ' \\/ _ `/  ' \\/ -_) _ \\/ __/");
    console_println("/_/ /_/_/ /_/_/_/\\_,_/_/_/_/\\__/_//_/\\__/ ");

    sprintf(buffer, "FMT FW %s", FMT_VERSION);
    banner_item("Firmware", buffer, '.', ITEM_LENGTH);
    sprintf(buffer, "RT-Thread v%ld.%ld.%ld", RT_VERSION, RT_SUBVERSION, RT_REVISION);
    banner_item("Kernel", buffer, '.', ITEM_LENGTH);
    sprintf(buffer, "%d KB", SYSTEM_TOTAL_MEM_SIZE / 1024);
    banner_item("RAM", buffer, '.', ITEM_LENGTH);
    banner_item("Target", TARGET_NAME, '.', ITEM_LENGTH);
    banner_item("Vehicle", VEHICLE_TYPE, '.', ITEM_LENGTH);
    //     banner_item("INS Model", ins_model_info.info, '.', ITEM_LENGTH);
    //     banner_item("FMS Model", fms_model_info.info, '.', ITEM_LENGTH);
    //     banner_item("Control Model", control_model_info.info, '.', ITEM_LENGTH);
    // #ifdef FMT_USING_SIH
    //     banner_item("Plant Model", plant_model_info.info, '.', ITEM_LENGTH);
    // #endif

    console_println("Task Initialize:");
    fmt_task_desc_t task_tab = get_task_table();
    for (uint32_t i = 0; i < get_task_num(); i++) {
        sprintf(buffer, "  %s", task_tab[i].name);
        /* task status must be okay to reach here */
        banner_item(buffer, get_task_status(task_tab[i].name) == TASK_OK ? "OK" : "Fail", '.', ITEM_LENGTH);
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
                    // err = console_toml_config(sub_tab);
                } else if (MATCH(key, "mavproxy")) {
                    // err = mavproxy_toml_config(sub_tab);
                } else if (MATCH(key, "pilot-cmd")) {
                    // err = pilot_cmd_toml_config(sub_tab);
                } else if (MATCH(key, "actuator")) {
                    // err = actuator_toml_config(sub_tab);
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
    // LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    // LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
    // LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);

    // /* init gpio */
    // GPIO_InitStruct.Pin = LL_GPIO_PIN_3;
    // GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    // GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    // GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    // GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    // LL_GPIO_Init(GPIOE, &GPIO_InitStruct);
    // /* VDD_3V3_Sensor_EN active high */
    // LL_GPIO_SetOutputPin(GPIOE, LL_GPIO_PIN_3);

    // /* init gpio */
    // GPIO_InitStruct.Pin = LL_GPIO_PIN_5;
    // GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    // GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    // GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    // GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    // LL_GPIO_Init(GPIOG, &GPIO_InitStruct);
    // /* VDD_5V_RC_EN active high */
    // LL_GPIO_SetOutputPin(GPIOG, LL_GPIO_PIN_5);

    // /* init gpio */
    // GPIO_InitStruct.Pin = LL_GPIO_PIN_7;
    // GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    // GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    // GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    // GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    // LL_GPIO_Init(GPIOG, &GPIO_InitStruct);
    // /* SD_CARD_EN active high */
    // LL_GPIO_SetOutputPin(GPIOG, LL_GPIO_PIN_7);

    // /* Wait some time for power becoming stable */
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
    printf("Enter Error_Handler\n");
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    // __disable_irq();
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
    // LL_FLASH_SetLatency(LL_FLASH_LATENCY_7);
    // while (LL_FLASH_GetLatency() != LL_FLASH_LATENCY_7) {
    // }
    // LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
    // LL_PWR_EnableOverDriveMode();
    // LL_RCC_HSE_Enable();

    // /* Wait till HSE is ready */
    // while (LL_RCC_HSE_IsReady() != 1) {
    // }
    // LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_8, 216, LL_RCC_PLLP_DIV_2);
    // LL_RCC_PLL_ConfigDomain_48M(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_8, 216, LL_RCC_PLLQ_DIV_9);
    // LL_RCC_PLL_Enable();

    // /* Wait till PLL is ready */
    // while (LL_RCC_PLL_IsReady() != 1) {
    // }
    // LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
    // LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_4);
    // LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_2);
    // LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

    // /* Wait till System clock is ready */
    // while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL) {
    // }
    // LL_SetSystemCoreClock(216000000);

    // /* Update the time base */
    // if (HAL_InitTick(TICK_INT_PRIORITY) != HAL_OK) {
    //     Error_Handler();
    // }
    // LL_RCC_SetCK48MClockSource(LL_RCC_CK48M_CLKSOURCE_PLL);
    // LL_RCC_SetUSBClockSource(LL_RCC_USB_CLKSOURCE_PLL);
    // LL_RCC_SetSDMMCClockSource(LL_RCC_SDMMC1_CLKSOURCE_PLL48CLK);
    // LL_RCC_SetUSARTClockSource(LL_RCC_USART1_CLKSOURCE_PCLK2);
    // LL_RCC_SetUSARTClockSource(LL_RCC_USART2_CLKSOURCE_PCLK1);
    // LL_RCC_SetUSARTClockSource(LL_RCC_USART3_CLKSOURCE_PCLK1);
    // LL_RCC_SetUSARTClockSource(LL_RCC_USART6_CLKSOURCE_PCLK2);
    // LL_RCC_SetUARTClockSource(LL_RCC_UART7_CLKSOURCE_PCLK1);
    // LL_RCC_SetI2CClockSource(LL_RCC_I2C1_CLKSOURCE_PCLK1);
    // LL_RCC_SetI2CClockSource(LL_RCC_I2C2_CLKSOURCE_PCLK1);
    // LL_RCC_SetI2CClockSource(LL_RCC_I2C3_CLKSOURCE_PCLK1);
    // LL_RCC_SetI2CClockSource(LL_RCC_I2C4_CLKSOURCE_PCLK1);
}

static void NVIC_Configuration(void)
{
    // #ifdef VECT_TAB_RAM
    //     /* Set the Vector Table base location at 0x20000000 */
    //     NVIC_SetVectorTable(NVIC_VectTab_RAM, INT_VECTOR_OFFSET);
    // #else /* VECT_TAB_FLASH  */
    //     /* Set the Vector Table base location at 0x8004000 */
    //     /* first 0x4000 is reserved for bootloader, so the vectortab offset is 0x4000 */
    //     NVIC_SetVectorTable(NVIC_VectTab_FLASH, INT_VECTOR_OFFSET);
    // #endif

    //     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    /* NVIC Configuration */
#define NVIC_VTOR_MASK 0x3FFFFF80
#ifdef VECT_TAB_RAM
    /* Set the Vector Table base location at 0x10000000 */
    SCB->VTOR = (0x10000000 & NVIC_VTOR_MASK);
#else /* VECT_TAB_FLASH  */
    /* Set the Vector Table base location at 0x08000000 */
    SCB->VTOR = (0x08000000 & NVIC_VTOR_MASK);
#endif
}

/* this function will be called before rtos start, which is not in the thread context */
void bsp_early_initialize(void)
{
    /* Enable CPU L1-cache */
    // CPU_CACHE_Enable();

    NVIC_Configuration();

    /* init system heap */
    rt_system_heap_init((void*)SYSTEM_FREE_MEM_BEGIN, (void*)SYSTEM_FREE_MEM_END);

    /* HAL library initialization */
    // HAL_Init();

    /* System clock initialization */
    // SystemClock_Config();

    /* usart driver init */
    RT_CHECK(drv_usart_init());

    /* init console to enable console output */
    FMT_CHECK(console_init());

    /* systick driver init */
    RT_CHECK(drv_systick_init());

    /* system time module init */
    FMT_CHECK(systime_init());

    /* system statistic module */
    FMT_CHECK(sys_stat_init());
}

/* this function will be called after rtos start, which is in thread context */
void bsp_initialize(void)
{
    /* init file system */
    FMT_CHECK(file_manager_init(mnt_table));

    /* init usbd_cdc */
    // RT_CHECK(drv_usb_cdc_init());

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
