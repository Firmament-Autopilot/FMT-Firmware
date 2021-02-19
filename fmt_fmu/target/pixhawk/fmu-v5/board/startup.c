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

#include <bsp.h>
#include <firmament.h>

#include "hal/pin.h"
#include "task_simple.h"

static rt_thread_t tid0;

static char thread_simple_stack[2048];
struct rt_thread thread_simple_handle;

void assert_failed(uint8_t* file, uint32_t line)
{

    while (1)
        ;
}

void assert_hook(const char* ex, const char* func, rt_size_t line)
{
    rt_kprintf("(%s) assertion failed at function:%s, line number:%d \n", ex, func, line);

    assert_failed((uint8_t*)func, (uint32_t)line);
}

static void rt_init_thread_entry(void* parameter)
{
    rt_err_t res;

    rt_assert_set_hook(assert_hook);

    /********************* bsp init *********************/
    bsp_initialize();

    /********************* init tasks *********************/
    FMT_CHECK(task_simple_init());

    /********************* bsp post init *********************/
    bsp_post_initialize();

    /********************* start tasks *********************/
    res = rt_thread_init(&thread_simple_handle,
        "simple",
        task_simple_entry,
        RT_NULL,
        &thread_simple_stack[0],
        sizeof(thread_simple_stack), 10, 1);
    RT_ASSERT(res == RT_EOK);
    rt_thread_startup(&thread_simple_handle);

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
