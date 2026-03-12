#include "hal/adc/adc.h"
#include <rtdevice.h>
#include <rtthread.h>

#ifdef RT_USING_FINSH
    #include <finsh.h>
#endif

#define ADC_TEST_STACK_SIZE 1024
#define ADC_TEST_PRIORITY   25
#define ADC_TEST_TICK       1000

static rt_thread_t adc_test_thread = RT_NULL;
static volatile rt_bool_t adc_test_running = RT_FALSE;
static uint32_t adc_test_interval = ADC_TEST_TICK;

static void adc_test_thread_entry(void* parameter)
{
    rt_device_t dev;
    uint32_t mv;
    rt_size_t result;
    rt_err_t ret;
    uint32_t channel = (uint32_t)parameter;

    dev = rt_device_find("adc0");
    if (dev == RT_NULL) {
        rt_kprintf("ADC device not found!\n");
        adc_test_running = RT_FALSE;
        return;
    }

    rt_kprintf("ADC test thread started for channel %d\n", channel);

    ret = rt_device_open(dev, RT_DEVICE_OFLAG_RDONLY);
    if (ret != RT_EOK) {
        rt_kprintf("Failed to open ADC device! Error code: %d\n", ret);
        adc_test_running = RT_FALSE;
        return;
    }

    rt_kprintf("ADC device opened successfully\n");

    while (adc_test_running) {
        result = rt_device_read(dev, channel, &mv, sizeof(mv));

        if (result == sizeof(mv)) {
            rt_kprintf("ADC channel %d: %d mV\n", channel, mv);
        } else {
            rt_kprintf("Failed to read ADC channel %d\n", channel);
        }

        rt_thread_mdelay(adc_test_interval);
    }

    rt_device_close(dev);
    rt_kprintf("ADC test thread stopped\n");
}

void adc_test_start(void)
{
    if (adc_test_running) {
        rt_kprintf("ADC test thread is already running!\n");
        return;
    }

    adc_test_thread = rt_thread_create("adc_test",
                                       adc_test_thread_entry,
                                       (void*)BAT1_V_CHANNEL,
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

void adc_test_stop(void)
{
    if (!adc_test_running) {
        rt_kprintf("ADC test thread is not running!\n");
        return;
    }

    rt_kprintf("Stopping ADC test thread...\n");
    adc_test_running = RT_FALSE;

    if (adc_test_thread != RT_NULL) {
        rt_thread_mdelay(50);
        rt_thread_delete(adc_test_thread);
        adc_test_thread = RT_NULL;
    }

    rt_kprintf("ADC test thread stopped\n");
}

void adc_test_set_interval(uint32_t interval_ms)
{
    if (interval_ms == 0) {
        rt_kprintf("Invalid interval! Must be > 0\n");
        return;
    }

    adc_test_interval = interval_ms;
    rt_kprintf("ADC test sampling interval set to %d ms\n", interval_ms);
}

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

    rt_kprintf("ADC device found!\n");

    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDONLY) != RT_EOK) {
        rt_kprintf("Failed to open ADC device!\n");
        return;
    }

    rt_kprintf("ADC device opened\n");

    result = rt_device_read(dev, BAT1_V_CHANNEL, &mv, sizeof(mv));

    if (result == sizeof(mv)) {
        rt_kprintf("ADC channel %d: %d mV\n", BAT1_V_CHANNEL, mv);
    } else {
        rt_kprintf("Failed to read ADC channel %d\n", BAT1_V_CHANNEL);
    }

    rt_device_close(dev);
}

#ifdef RT_USING_FINSH
MSH_CMD_EXPORT(adc_test, Single ADC test function for FMT framework);
MSH_CMD_EXPORT(adc_test_start, Start continuous ADC test thread);
MSH_CMD_EXPORT(adc_test_stop, Stop continuous ADC test thread);
MSH_CMD_EXPORT(adc_test_set_interval, Set ADC test sampling interval(ms));
#endif
