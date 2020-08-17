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

#include <board.h>
#include <firmament.h>
#include <shell.h>
#ifdef FMT_USING_CM_BACKTRACE
#include <cm_backtrace.h>
#endif

#include "module/fs_manager/fs_manager.h"
#include "module/param/param.h"
#include "module/sensor/sensor_manager.h"
#include "module/sysio/actuator_cmd.h"
#include "module/sysio/pilot_cmd.h"
#include "module/system/statistic.h"
#include "module/system/systime.h"

#include "hal/cdcacm.h"
#include "hal/fmtio_dev.h"

#include "driver/gpio.h"
#include "driver/l3gd20h.h"
#include "driver/lsm303d.h"
#include "driver/mpu6000.h"
#include "driver/ms5611.h"
#include "driver/pwm_drv.h"
#include "driver/spi_drv.h"
#include "driver/systick_drv.h"
#include "driver/tca62724.h"
#include "driver/usart.h"

/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configures Vector Table base location.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_Configuration(void)
{
#ifdef VECT_TAB_RAM
    /* Set the Vector Table base location at 0x20000000 */
    NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
#else /* VECT_TAB_FLASH  */
    /* Set the Vector Table base location at 0x08000000 */
    /* app start from 0x8004000,so need configure vectortab offset to 0x4000 */
    NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x4000);
#endif

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
}

void board_show_version(void)
{
    console_printf("\n");
    console_println("   _____                               __ ");
    console_println("  / __(_)_____ _  ___ ___ _  ___ ___  / /_");
    console_println(" / _// / __/  ' \\/ _ `/  ' \\/ -_) _ \\/ __/");
    console_println("/_/ /_/_/ /_/_/_/\\_,_/_/_/_/\\__/_//_/\\__/ ");

    console_println("Version: Firmament v%d.%d.%d", FMT_VERSION, FMT_SUBVERSION, FMT_REVISION);
    console_println("RTOS: RT-Thread v%d.%d.%d", RT_VERSION, RT_SUBVERSION, RT_REVISION);
    console_println("RAM: %d KB", SYSTEM_TOTAL_MEM_SIZE / 1024);
    console_println("Board: %s", BOARD_NAME);
    console_println("Vehicle Type: %s", VEHICLE_TYPE);
    console_println("INS Model: CF INS");
    console_println("FMS Model: UAV FMS");
    console_println("Control Model: PID Controller");
    console_println("Task Initialize:");
    console_println("  vehicle: OK");
    console_println("    fmtio: OK");
    console_println("     comm: OK");
    console_println("   logger: OK");
    console_println("   status: OK");
}

/* this function will be called before rtos start, which is not thread context */
void board_early_init(void)
{
    /* system time module init */
    systime_init();

    /* init console to enable console output */
    console_init(CONSOLE_DEVICE_NAME);

    gpio_drv_init();

    spi_drv_init();

    pwm_drv_init();
}

/* this function will be called after rtos start, which is in thread context */
void board_init(void)
{
    /* init file manager */
    fs_manager_init(FS_DEVICE_NAME, "/");

    /* init usb device */
    usb_cdc_init();

    /* init sensor drivers */
    mpu6000_drv_init(MPU6000_SPI_DEVICE_NAME);

    l3gd20h_drv_init(L3GD20H_SPI_DEVICE_NAME);

    ms5611_drv_init(MS5611_SPI_DEVICE_NAME);

    lsm303d_drv_init(LSM303D_SPI_DEVICE_NAME);

    /* init parameter system */
    param_init();

    /* init sensor manager */
    sensor_manager_init();

    /* RGB led device init */
    tca62724_drv_init();

    /* GDB STUB */
#ifdef RT_USING_GDB
    gdb_set_device(GDB_DEVICE_NAME);
    gdb_start();
#endif

#ifdef RT_USING_FINSH
    /* init finsh */
    finsh_system_init();
    /* Mount finsh to console after finsh system init */
    console_mount_shell(NULL);
#endif

    sys_stat_init();

#ifdef FMT_USING_CM_BACKTRACE
    // cortex-m backtrace
    cm_backtrace_init("fmt_fmu", BOARD_NAME, "v0.1");
#endif
}

void board_post_init(void)
{
    pilot_cmd_init();

#if defined(FMT_HIL_WITH_ACTUATOR) || !defined(FMT_USING_HIL)
#ifdef FMT_USING_AUX_MOTOR
    actuator_init("motor_aux");
#else
    actuator_init("motor_main");
#endif
#endif

    board_show_version();
}

/**
 * This function will initial STM32 board.
 */
void rt_hw_board_init()
{
    /* interrupt controller init */
    NVIC_Configuration();

    /* system timer init */
    systick_drv_init();

    /* system usart init */
    usart_drv_init();

    board_early_init();
}
