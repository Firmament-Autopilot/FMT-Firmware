#include <firmament.h>
#include <rtthread.h>
#include "usbd_cdc.h"

#define CDC_THREAD_STACK_SIZE 1024
#define CDC_THREAD_PRIORITY   20
#define CDC_THREAD_TICK       10

static rt_thread_t cdc_thread = RT_NULL;

static void usbd_cdc_thread_entry(void* parameter)
{
    rt_device_t usb_dev;
    uint8_t rx_buffer[128];
    rt_size_t len;
    rt_tick_t last_hello_tick = 0;

    usb_dev = rt_device_find("usbd_cdc");
    if (usb_dev == RT_NULL) {
        rt_kprintf("USB CDC device not found!\n");
        return;
    }

    if (rt_device_open(usb_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        rt_kprintf("Failed to open USB CDC device!\n");
        return;
    }

    rt_kprintf("USB CDC thread started\n");

    while (1) {
        len = rt_device_read(usb_dev, 0, rx_buffer, sizeof(rx_buffer) - 1);
        if (len > 0) {
            rx_buffer[len] = '\0';
            rt_kprintf("%s", rx_buffer);
        }

        if (rt_tick_get() - last_hello_tick >= RT_TICK_PER_SECOND) {
            const char* msg = "Hello from Firmament USB CDC!\r\n";
            rt_device_write(usb_dev, 0, msg, rt_strlen(msg));
            last_hello_tick = rt_tick_get();
        }

        rt_thread_mdelay(10);
    }
}

void usbd_cdc_thread_start(void)
{
    if (cdc_thread != RT_NULL) {
        return;
    }

    cdc_thread = rt_thread_create(
        "cdc_echo",
        usbd_cdc_thread_entry,
        RT_NULL,
        CDC_THREAD_STACK_SIZE,
        CDC_THREAD_PRIORITY,
        CDC_THREAD_TICK);

    if (cdc_thread != RT_NULL) {
        rt_thread_startup(cdc_thread);
    } else {
        rt_kprintf("Failed to create USB CDC thread\n");
    }
}

MSH_CMD_EXPORT(usbd_cdc_thread_start, start USB CDC echo thread);
