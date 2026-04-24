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

#include "hal/adc/adc.h"
#include <rtdevice.h>
#include <rtthread.h>

#ifdef RT_USING_FINSH
    #include <finsh.h>
#endif

#define ADC_TEST_STACK_SIZE 2048
#define ADC_TEST_PRIORITY   25
#define ADC_TEST_TICK       1000

/* ADC channel count: P15[4], P15[5], P15[6], P15[7] */
#define ADC_NUM_CHANNELS    4

/* Channel names for display */
static const char* adc_ch_names[ADC_NUM_CHANNELS] = {
    "P15[4]/ADC_CH0",
    "P15[5]/ADC_CH1",
    "P15[6]/ADC_CH2",
    "P15[7]/ADC_CH3",
};

static rt_thread_t adc_test_thread = RT_NULL;
static volatile rt_bool_t adc_test_running = RT_FALSE;
static uint32_t adc_test_interval = ADC_TEST_TICK;

/**
 * @brief Continuous ADC test thread - reads all 4 channels periodically
 */
static void adc_test_thread_entry(void* parameter)
{
    rt_device_t dev;
    uint32_t mv;
    rt_size_t result;
    rt_err_t ret;

    dev = rt_device_find("adc0");
    if (dev == RT_NULL) {
        rt_kprintf("ADC device not found!\n");
        adc_test_running = RT_FALSE;
        return;
    }

    ret = rt_device_open(dev, RT_DEVICE_OFLAG_RDONLY);
    if (ret != RT_EOK) {
        rt_kprintf("Failed to open ADC device! Error code: %d\n", ret);
        adc_test_running = RT_FALSE;
        return;
    }

    rt_kprintf("ADC continuous test started (all %d channels, interval %d ms)\n",
               ADC_NUM_CHANNELS, adc_test_interval);
    rt_kprintf("----------------------------------------------\n");

    while (adc_test_running) {
        rt_kprintf("[ADC] ");

        for (uint32_t ch = 0; ch < ADC_NUM_CHANNELS; ch++) {
            result = rt_device_read(dev, ch, &mv, sizeof(mv));

            if (result == sizeof(mv)) {
                rt_kprintf("%s: %4u mV  ", adc_ch_names[ch], mv);
            } else {
                rt_kprintf("%s: ERR  ", adc_ch_names[ch]);
            }
        }

        rt_kprintf("\n");
        rt_thread_mdelay(adc_test_interval);
    }

    rt_device_close(dev);
    rt_kprintf("ADC continuous test stopped\n");
}

/**
 * @brief Start continuous ADC test (all channels)
 */
void adc_test_start(void)
{
    if (adc_test_running) {
        rt_kprintf("ADC test thread is already running!\n");
        return;
    }

    adc_test_thread = rt_thread_create("adc_test",
                                       adc_test_thread_entry,
                                       RT_NULL,
                                       ADC_TEST_STACK_SIZE,
                                       ADC_TEST_PRIORITY,
                                       20);

    if (adc_test_thread == RT_NULL) {
        rt_kprintf("Failed to create ADC test thread!\n");
        return;
    }

    adc_test_running = RT_TRUE;
    rt_thread_startup(adc_test_thread);
    rt_kprintf("ADC test thread started with %d ms interval\n", adc_test_interval);
}

/**
 * @brief Stop continuous ADC test
 */
void adc_test_stop(void)
{
    if (!adc_test_running) {
        rt_kprintf("ADC test thread is not running!\n");
        return;
    }

    rt_kprintf("Stopping ADC test thread...\n");
    adc_test_running = RT_FALSE;

    if (adc_test_thread != RT_NULL) {
        rt_thread_mdelay(adc_test_interval + 100);
        adc_test_thread = RT_NULL;
    }

    rt_kprintf("ADC test thread stopped\n");
}

/**
 * @brief Set ADC test sampling interval
 */
void adc_test_set_interval(uint32_t interval_ms)
{
    if (interval_ms == 0) {
        rt_kprintf("Invalid interval! Must be > 0\n");
        return;
    }

    adc_test_interval = interval_ms;
    rt_kprintf("ADC test sampling interval set to %d ms\n", interval_ms);
}

/**
 * @brief Single-shot ADC test - read all 4 channels once
 */
void adc_test(void)
{
    rt_device_t dev;
    uint32_t mv;
    rt_size_t result;

    dev = rt_device_find("adc0");
    if (dev == RT_NULL) {
        rt_kprintf("ADC device not found!\n");
        return;
    }

    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDONLY) != RT_EOK) {
        rt_kprintf("Failed to open ADC device!\n");
        return;
    }

    rt_kprintf("=== ADC Single-Shot Test ===\n");
    rt_kprintf("Channel Map:\n");
    rt_kprintf("  CH0 = P15[4] (GPIO4), CH1 = P15[5] (GPIO5)\n");
    rt_kprintf("  CH2 = P15[6] (GPIO6), CH3 = P15[7] (GPIO7)\n");
    rt_kprintf("----------------------------\n");

    for (uint32_t ch = 0; ch < ADC_NUM_CHANNELS; ch++) {
        result = rt_device_read(dev, ch, &mv, sizeof(mv));

        if (result == sizeof(mv)) {
            rt_kprintf("  %s : %u mV\n", adc_ch_names[ch], mv);
        } else {
            rt_kprintf("  %s : Read FAILED\n", adc_ch_names[ch]);
        }
    }

    rt_kprintf("============================\n");

    rt_device_close(dev);
}

/**
 * @brief Read a specific ADC channel
 * Usage: adc_read <channel>  (channel: 0-3)
 */
static void adc_read(int argc, char** argv)
{
    rt_device_t dev;
    uint32_t mv;
    rt_size_t result;
    uint32_t channel;

    if (argc < 2) {
        rt_kprintf("Usage: adc_read <channel>\n");
        rt_kprintf("  channel: 0-3 (P15[4]-P15[7])\n");
        return;
    }

    channel = atoi(argv[1]);
    if (channel >= ADC_NUM_CHANNELS) {
        rt_kprintf("Invalid channel %d! Valid range: 0-%d\n", channel, ADC_NUM_CHANNELS - 1);
        return;
    }

    dev = rt_device_find("adc0");
    if (dev == RT_NULL) {
        rt_kprintf("ADC device not found!\n");
        return;
    }

    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDONLY) != RT_EOK) {
        rt_kprintf("Failed to open ADC device!\n");
        return;
    }

    result = rt_device_read(dev, channel, &mv, sizeof(mv));

    if (result == sizeof(mv)) {
        rt_kprintf("%s : %u mV\n", adc_ch_names[channel], mv);
    } else {
        rt_kprintf("%s : Read FAILED\n", adc_ch_names[channel]);
    }

    rt_device_close(dev);
}

#ifdef RT_USING_FINSH
MSH_CMD_EXPORT(adc_test, Single shot read all ADC channels);
MSH_CMD_EXPORT(adc_test_start, Start continuous ADC test for all channels);
MSH_CMD_EXPORT(adc_test_stop, Stop continuous ADC test);
MSH_CMD_EXPORT(adc_test_set_interval, Set ADC test sampling interval in ms);
MSH_CMD_EXPORT(adc_read, Read single ADC channel: adc_read <0-3>);
#endif
