/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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

#include "board.h"
#include "model/control/control_interface.h"
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/config/actuator_config.h"
#include "module/config/console_config.h"
#include "module/config/ethernet_config.h"
#include "module/config/mavproxy_config.h"
#include "module/config/pilot_cmd_config.h"
#include "module/task_manager/task_manager.h"

#if defined(FMT_USING_SIH)
    #include "model/plant/plant_interface.h"
#endif
#ifdef FMT_USING_CM_BACKTRACE
    #include <cm_backtrace.h>
#endif

#define MATCH(a, b) (strcmp(a, b) == 0)

static rt_thread_t tid0;

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

void assert_failed(uint8_t* file, uint32_t line)
{
    rt_hw_interrupt_disable();

#ifdef FMT_USING_CM_BACKTRACE
    cm_backtrace_assert(cmb_get_sp());
#endif

    while (1)
        ;
}

static void assert_hook(const char* ex, const char* func, rt_size_t line)
{
    printf("(%s) assertion failed at function:%s, line number:%ld \n", ex, func, line);

#ifdef FMT_USING_CHECKED
    assert_failed((uint8_t*)func, (uint32_t)line);
#endif
}

static void rt_init_thread_entry(void* parameter)
{
#if defined(RT_USING_CPLUSPLUS)
    /* c++ component initialization */
    int cplusplus_system_init(void);
    cplusplus_system_init();
#endif

    /* bsp initialization */
    bsp_initialize();

    /* task initialization */
    task_manager_init();

    /* bsp post initialization */
    bsp_post_initialize();

    /* start task */
    task_manager_start();
}

void bsp_show_information(void)
{
#define BANNER_ITEM_LEN 42
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
#if !defined(FMT_SIM_PLANT)
    banner_item("INS Model", ins_model_info.info, '.', BANNER_ITEM_LEN);
    banner_item("FMS Model", fms_model_info.info, '.', BANNER_ITEM_LEN);
    banner_item("Control Model", control_model_info.info, '.', BANNER_ITEM_LEN);
#endif
#if defined(FMT_USING_SIH)
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

RT_WEAK fmt_err_t bsp_parse_toml_sysconfig(toml_table_t* root_tab)
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
            printf("Error: fail to parse type value\n");
            err = FMT_ERROR;
        }
        if (!MATCH(target, TARGET_NAME)) {
            /* check if target match */
            printf("Error: target name doesn't match\n");
            err = FMT_ERROR;
        }
        rt_free(target);
    } else {
        printf("Error: can not find target key\n");
        err = FMT_ERROR;
    }

    if (err == FMT_EOK) {
#ifdef RT_USING_LWIP
        /* handle ethernet table first if exist */
        for (i = 0; 0 != (key = toml_key_in(root_tab, i)); i++) {
            if (0 != (sub_tab = toml_table_in(root_tab, key))) {
                if (MATCH(key, "ethernet")) {
                    err = ethernet_toml_config(sub_tab);
                }
            }
        }
#endif

        /* traverse all other sub-table */
        for (i = 0; 0 != (key = toml_key_in(root_tab, i)); i++) {
            if (0 != (sub_tab = toml_table_in(root_tab, key))) {
                if (MATCH(key, "ethernet")) {
                    continue;
                }

                if (MATCH(key, "console")) {
                    err = console_toml_config(sub_tab);
                } else if (MATCH(key, "mavproxy")) {
                    err = mavproxy_toml_config(sub_tab);
                } else if (MATCH(key, "pilot-cmd")) {
                    err = pilot_cmd_toml_config(sub_tab);
                } else if (MATCH(key, "actuator")) {
                    err = actuator_toml_config(sub_tab);
                } else {
                    printf("unknown table: %s\n", key);
                }
                if (err != FMT_EOK) {
                    printf("fail to parse %s\n", key);
                }
            }
        }
    }

    /* free toml root table */
    toml_free(root_tab);

    return err;
}

int rt_application_init()
{
    tid0 = rt_thread_create("init",
                            rt_init_thread_entry,
                            RT_NULL,
                            10240,
                            RT_THREAD_PRIORITY_MAX / 2,
                            20);

    if (tid0 != RT_NULL)
        rt_thread_startup(tid0);

    return 0;
}

/**
 * This function will startup RT-Thread RTOS.
 */
void rtthread_startup(void)
{
    /* disable interrupt first */
    rt_hw_interrupt_disable();

    rt_assert_set_hook(assert_hook);

    /* board level initialization
     * NOTE: please initialize heap inside board initialization.
     */
    rt_hw_board_init();

    /* init timer system */
    rt_system_timer_init();

    /* init scheduler system */
    rt_system_scheduler_init();

#ifdef RT_USING_SIGNALS
    /* signal system initialization */
    rt_system_signal_init();
#endif

    /* init application */
    rt_application_init();

    /* init timer thread */
    rt_system_timer_thread_init();

    /* init idle thread */
    rt_thread_idle_init();

#ifdef RT_USING_SMP
    rt_hw_spin_lock(&_cpus_lock);
#endif /*RT_USING_SMP*/

    /* start scheduler */
    rt_system_scheduler_start();

    /* never reach here */
    return;
}

int main(void)
{
    /* startup RT-Thread RTOS */
    rtthread_startup();

    return 0;
}
