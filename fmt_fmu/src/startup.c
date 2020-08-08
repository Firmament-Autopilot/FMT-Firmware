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

#include "board.h"
#include "task/task_comm.h"
#include "task/task_fmtio.h"
#include "task/task_logger.h"
#include "task/task_status.h"
#include "task/task_vehicle.h"
#include <firmament.h>

static rt_thread_t tid0;

// Task Stack
static char thread_vehicle_stack[10240];
struct rt_thread thread_vehicle_handle;

static char thread_comm_stack[8192];
struct rt_thread thread_comm_handle;

static char thread_fmtio_stack[2048];
struct rt_thread thread_fmtio_handle;

static char thread_logger_stack[2048];
struct rt_thread thread_logger_handle;

static char thread_status_stack[1024];
struct rt_thread thread_status_handle;

/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(uint8_t* file, uint32_t line)
{
    rt_kprintf("\n\r Wrong parameter value detected on\r\n");
    rt_kprintf("       file  %s\r\n", file);
    rt_kprintf("       line  %d\r\n", line);

    while (1)
        ;
}

static void rt_init_thread_entry(void* parameter)
{
    rt_err_t res;

    /********************* board init *********************/
    board_init();

    /********************* init tasks *********************/
    FMT_CHECK(task_vehicle_init());
    console_printf("task vehicle init success\n");
    FMT_CHECK(task_fmtio_init());
    console_printf("task fmtio init success\n");
    FMT_CHECK(task_comm_init());
    console_printf("task comm init success\n");
    FMT_CHECK(task_logger_init());
    console_printf("task logger init success\n");
    FMT_CHECK(task_status_init());
    console_printf("task status init success\n");

#ifdef FMT_USING_HIL
    console_printf("Using HIL Simulation.\n");
#endif

    /********************* board post init *********************/
    board_post_init();

    /********************* start tasks *********************/
    res = rt_thread_init(&thread_vehicle_handle,
        "vehicle",
        task_vehicle_entry,
        RT_NULL,
        &thread_vehicle_stack[0],
        sizeof(thread_vehicle_stack), VEHICLE_THREAD_PRIORITY, 1);
    RT_ASSERT(res == RT_EOK);
    rt_thread_startup(&thread_vehicle_handle);

    res = rt_thread_init(&thread_fmtio_handle,
        "fmtio",
        task_fmtio_entry,
        RT_NULL,
        &thread_fmtio_stack[0],
        sizeof(thread_fmtio_stack), FMTIO_THREAD_PRIORITY, 1);
    RT_ASSERT(res == RT_EOK);
    rt_thread_startup(&thread_fmtio_handle);

    res = rt_thread_init(&thread_comm_handle,
        "comm",
        task_comm_entry,
        RT_NULL,
        &thread_comm_stack[0],
        sizeof(thread_comm_stack), COMM_THREAD_PRIORITY, 1);
    RT_ASSERT(res == RT_EOK);
    rt_thread_startup(&thread_comm_handle);

    res = rt_thread_init(&thread_logger_handle,
        "logger",
        task_logger_entry,
        RT_NULL,
        &thread_logger_stack[0],
        sizeof(thread_logger_stack), LOGGER_THREAD_PRIORITY, 1);
    RT_ASSERT(res == RT_EOK);
    rt_thread_startup(&thread_logger_handle);

    res = rt_thread_init(&thread_status_handle,
        "status",
        task_status_entry,
        RT_NULL,
        &thread_status_stack[0],
        sizeof(thread_status_stack), STATUS_THREAD_PRIORITY, 1);
    RT_ASSERT(res == RT_EOK);
    rt_thread_startup(&thread_status_handle);

    /* delete itself */
    rt_thread_delete(tid0);
}

int rt_application_init()
{
    tid0 = rt_thread_create("init",
        rt_init_thread_entry, RT_NULL,
        8192, RT_THREAD_PRIORITY_MAX / 2, 20);

    if (tid0 != RT_NULL)
        rt_thread_startup(tid0);

    return 0;
}

/**
 * This function will startup RT-Thread RTOS.
 */
void rtthread_startup(void)
{
    /* init board */
    rt_hw_board_init();

    /* show system version */
    // rt_show_version();

    /* init tick */
    rt_system_tick_init();

    /* init kernel object */
    rt_system_object_init();

    /* init timer system */
    rt_system_timer_init();

    rt_system_heap_init((void*)SYSTEM_FREE_MEM_BEGIN, (void*)SYSTEM_FREE_MEM_END);

    /* init scheduler system */
    rt_system_scheduler_init();

    /* init application */
    rt_application_init();

    /* init timer thread */
    rt_system_timer_thread_init();

    /* init idle thread */
    rt_thread_idle_init();

    /* start scheduler */
    rt_system_scheduler_start();

    /* never reach here */
    return;
}

int main(void)
{
    /* disable interrupt first */
    rt_hw_interrupt_disable();

    /* startup RT-Thread RTOS */
    rtthread_startup();

    return 0;
}
