/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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

#include "board.h"
#include <firmament.h>

#include <msh.h>
#include <shell.h>
#include <string.h>

#include "drv_adc.h"
#include "drv_eth.h"
#include "drv_gpio.h"
#include "drv_i2c.h"
#include "drv_pwm.h"
#include "drv_sdio.h"
#include "drv_spi.h"
#include "drv_systick.h"
#include "drv_uart.h"
#include "drv_usbd_cdc.h"
// #define DBG_TAG "board"
// #define DBG_LVL DBG_INFO
// #include <rtdbg.h>

void cy_bsp_all_init(void)
{
    cy_rslt_t result;

    /* Initialize the device and board peripherals */
    result = cybsp_init();

    /* Board init failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS) {
        CY_ASSERT(0);
    }

#ifdef SOC_Enable_CM55
    Cy_SysEnableCM55(MXCM55, CY_CM55_APP_BOOT_ADDR, 10);
#endif
#ifdef SOC_Enable_CM33_DeepSleep
    while (1) {
        Cy_SysPm_CpuEnterDeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
    }
#endif
}

/**
 * @brief  this function is executed in case of error occurrence.
 * @param  none
 * @retval none
 */
void _Error_Handler(char* s, int num)
{
    /* User can add his own implementation to report the HAL error return state */
    rt_kprintf("Error_Handler at file:%s num:%d\n", s, num);

    while (1) {
    }
}

#ifdef RT_USING_FINSH
static void reboot(uint8_t argc, char** argv)
{
    rt_hw_cpu_reset();
}
MSH_CMD_EXPORT(reboot, Reboot System);
#endif /* RT_USING_FINSH */

void bsp_early_initialize(void)
{
    cy_bsp_all_init();

    /* heap initialization */

    rt_system_heap_init((void*)HEAP_BEGIN, (void*)HEAP_END);

    /* gpio driver init */
    RT_CHECK(drv_gpio_init());

    /* usart driver init */
    RT_CHECK(drv_usart_init());

    /* init console to enable console output */
    FMT_CHECK(console_init());

    /* systick driver init */
    RT_CHECK(drv_systick_init());

    /* pwm driver init */
    RT_CHECK(drv_pwm_init());

    /* init RC */
    RT_CHECK(drv_rc_init());

    /* system statistic module */
    FMT_CHECK(sys_stat_init());
}

void bsp_initialize(void)
{
    /* system time module init */
    FMT_CHECK(systime_init());

    /* adc driver init */
    RT_CHECK(drv_adc_init());

    /* init finsh */
    finsh_system_init();
    /* Mount finsh to console after finsh system init */
    FMT_CHECK(console_enable_input());
}

void bsp_post_initialize(void)
{
}

void _start(void)
{
    extern int main(void);
    main();
    while (1)
        ;
    __builtin_unreachable();
}

/**
 * This function will initial STM32 board.
 */
void rt_hw_board_init()
{
    bsp_early_initialize();
}
