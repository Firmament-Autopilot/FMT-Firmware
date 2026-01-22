/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-1      Rbb666       first version
 */
#include <firmament.h>

#include <msh.h>
#include <shell.h>
#include <string.h>

#include "drv_common.h"
#include "drv_uart.h"
#include "drv_gpio.h"
#include "model/control/control_interface.h"
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/console/console_config.h"
#include "module/file_manager/file_manager.h"
#include "module/mavproxy/mavproxy.h"
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
// #define DBG_TAG "drv_common"
// #define DBG_LVL DBG_INFO
// #include <rtdbg.h>

#ifdef RT_USING_FINSH
#include <finsh.h>
static void reboot(uint8_t argc, char **argv)
{
    rt_hw_cpu_reset();
}
MSH_CMD_EXPORT(reboot, Reboot System);
#endif /* RT_USING_FINSH */

/**
 * this is the timer interrupt service routine.
 */
void SysTick_Handler_CB(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    rt_tick_increase();

    /* leave interrupt */
    rt_interrupt_leave();
}

/* systick configuration */
void rt_hw_systick_init(void)
{
    Cy_SysTick_Init(CY_SYSTICK_CLOCK_SOURCE_CLK_CPU, SystemCoreClock / RT_TICK_PER_SECOND);
    Cy_SysTick_SetCallback(0, SysTick_Handler_CB);
    Cy_SysTick_EnableInterrupt();
}

/**
 * @brief  this function is executed in case of error occurrence.
 * @param  none
 * @retval none
 */
void _Error_Handler(char *s, int num)
{
    /* User can add his own implementation to report the HAL error return state */
    LOG_E("Error_Handler at file:%s num:%d", s, num);

    while (1)
    {
    }
}

/**
 * this function will delay for some us.
 *
 * @param us the delay time of us
 */
void rt_hw_us_delay(rt_uint32_t us)
{
    rt_uint32_t start, now, delta, reload, us_tick;
    start = SysTick->VAL;
    reload = SysTick->LOAD;
    us_tick = SystemCoreClock / 1000000UL;

    do
    {
        now = SysTick->VAL;
        delta = start > now ? start - now : reload + start - now;
    }
    while (delta < us_tick * us);
}

/* this function will be called before rtos start, which is not in the thread context */
void bsp_early_initialize(void)
{
    cy_bsp_all_init();

    /* systick init */
    rt_hw_systick_init();

    /* heap initialization */

    rt_system_heap_init((void *)HEAP_BEGIN, (void *)HEAP_END);

    /* gpio driver init */
    RT_CHECK(drv_gpio_init());

    /* usart driver init */
    RT_CHECK(drv_usart_init());

    /* init console to enable console output */
    FMT_CHECK(console_init());

    // /* systick driver init */
    // RT_CHECK(drv_systick_init());

    // /* i2c driver init */
    // RT_CHECK(drv_i2c_init());

    // /* spi driver init */
    // RT_CHECK(drv_spi_init());

    // /* pwm driver init */
    // RT_CHECK(drv_pwm_init());

    // /* can driver init */
    // RT_CHECK(drv_fdcan_init());

    // /* init remote controller driver */
    // RT_CHECK(drv_rc_init());

    /* system statistic module */
    FMT_CHECK(sys_stat_init());
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

//     /* init storage devices */
//     RT_CHECK(drv_sdio_init());
//     RT_CHECK(drv_gd25qxx_init("spi5_dev1", "mtdblk0"));
//     /* init file system */
//     FMT_CHECK(file_manager_init(mnt_table));

//     /* init parameter system */
//     FMT_CHECK(param_init());

//     /* init mavproxy */
//     FMT_CHECK(mavproxy_init());

//     /* init usbd_cdc */
//     RT_CHECK(drv_usb_cdc_init());

//     /* adc driver init */
//     RT_CHECK(drv_adc_init());

//     /* init rt_workqueue, which is used by tcpip stack */
//     FMT_CHECK(rt_work_sys_workqueue_init());

//     /* init lwip */
//     extern int lwip_system_init();
//     FMT_CHECK(lwip_system_init());

//     /* eth driver init */
//     RT_CHECK(drv_eth_init());

// #if defined(FMT_USING_SIH) || defined(FMT_USING_HIL)
//     FMT_CHECK(advertise_sensor_imu(0));
//     FMT_CHECK(advertise_sensor_mag(0));
//     FMT_CHECK(advertise_sensor_baro(0));
//     FMT_CHECK(advertise_sensor_gps(0));
//     FMT_CHECK(advertise_sensor_airspeed(0));
// #else
//     /* init onboard sensors */
//     RT_CHECK(drv_bmi088_init("spi4_dev1", "spi4_dev2", "gyro0", "accel0", 0));
//     RT_CHECK(drv_icm42688_init("spi4_dev3", "gyro1", "accel1", 0));
//     RT_CHECK(drv_bmm150_init("spi4_dev4", "mag0", 0));
//     // RT_CHECK(drv_qmc5883l_init("i2c1_dev2", "mag0", EXTERNAL_DEV | 0));
//     RT_CHECK(drv_spl06_init("spi1_dev1", "barometer"));
//     RT_CHECK(gps_ubx_init("serial3", "gps"));
//     // RT_CHECK(gps_nmea_init("serial3", "gps"));
//     // RT_CHECK(drv_tofsense_init("serial5"));

//     FMT_CHECK(register_sensor_imu("gyro0", "accel0", 0));
//     FMT_CHECK(register_sensor_mag("mag0", 0));
//     FMT_CHECK(register_sensor_barometer("barometer"));
//     FMT_CHECK(advertise_sensor_optflow(0));
//     FMT_CHECK(advertise_sensor_rangefinder(0));

//     if (strcmp(STR(VEHICLE_TYPE), "Fixwing") == 0 || strcmp(STR(VEHICLE_TYPE), "VTOL") == 0) {
//         if (drv_ms4525_init("i2c3_dev1", "airspeed") == RT_EOK) {
//             FMT_CHECK(register_sensor_airspeed("airspeed"));
//         } else {
//             printf("airspeed sensor init failed!\n");
//         }
//     }
// #endif

    /* init finsh */
    finsh_system_init();
    /* Mount finsh to console after finsh system init */
    FMT_CHECK(console_enable_input());

#ifdef FMT_USING_UNIT_TEST
    utest_init();
#endif
}

void bsp_post_initialize(void)
{
    // if (bsp_parse_toml_sysconfig(toml_parse_config_file(SYS_CONFIG_FILE)) != FMT_EOK) {
    //     /* use default system configuration */
    //     FMT_CHECK(bsp_parse_toml_sysconfig(toml_parse_config_string(default_conf)));
    //     printf("Default configuration loaded.\n");
    // }

    // /* init rc */
    // FMT_CHECK(pilot_cmd_init());

    // /* init gcs */
    // FMT_CHECK(gcs_cmd_init());

    // /* init auto command */
    // FMT_CHECK(auto_cmd_init());

    // /* init mission data */
    // FMT_CHECK(mission_data_init());

    // /* init actuator */
    // FMT_CHECK(actuator_init());

    // /* start device message queue work */
    // FMT_CHECK(devmq_start_work());

    // /* init led control */
    // FMT_CHECK(led_control_init());

    // /* initialize power management unit */
    // FMT_CHECK(pmu_init());

    // /* show system information */
    // bsp_show_information();

    // /* execute init script */
    // msh_exec_script(SYS_INIT_SCRIPT, strlen(SYS_INIT_SCRIPT));

    // /* dump boot log to file */
    // boot_log_dump();
}

/**
 * This function will initial STM32 board.
 */
void rt_hw_board_init()
{
    bsp_early_initialize();
}
