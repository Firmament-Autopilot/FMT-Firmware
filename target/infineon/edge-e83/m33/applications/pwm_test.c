#include "hal/actuator/actuator.h"
#include <rtdevice.h>
#include <rtthread.h>

#ifdef RT_USING_FINSH
    #include <finsh.h>
#endif

void pwm_test(void)
{
    rt_device_t dev;
    rt_uint16_t chan_val[4];
    rt_uint16_t chan_mask = 0x01;

    dev = rt_device_find("main_out");
    if (dev == RT_NULL) {
        rt_kprintf("actuator device main_out not found!\n");
        return;
    }

    rt_kprintf("actuator device main_out found!\n");

    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        rt_kprintf("Failed to open actuator device!\n");
        return;
    }

    rt_kprintf("Actuator device opened and enabled!\n");

    chan_val[0] = 1500;

    if (rt_device_write(dev, chan_mask, chan_val, 1) != 1) {
        rt_kprintf("Failed to write actuator values!\n");
        rt_device_close(dev);
        return;
    }

    rt_kprintf("PWM value set: %d us\n", chan_val[0]);

    rt_kprintf("PWM test running at 400Hz on channel 0\n");
    rt_kprintf("Device will remain open. Use 'pwm_test_stop' to close.\n");
}

void pwm_test_stop(void)
{
    rt_device_t dev;

    dev = rt_device_find("main_out");
    if (dev == RT_NULL) {
        rt_kprintf("actuator device main_out not found!\n");
        return;
    }

    if (rt_device_close(dev) == RT_EOK) {
        rt_kprintf("Actuator device closed and disabled.\n");
    } else {
        rt_kprintf("Failed to close actuator device!\n");
    }
}

#ifdef RT_USING_FINSH
MSH_CMD_EXPORT(pwm_test, PWM test function for FMT framework);
MSH_CMD_EXPORT(pwm_test_stop, Stop PWM test and close device);
#endif