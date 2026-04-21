#include <rtdevice.h>
#include <rtthread.h>
#include <string.h>

#include "drv_ipc.h"
#include "ipc_common.h"

#define SNED_DATA   "pongpongpongpongpong\r\n"

void ipc_dev_test_run(void)
{
    rt_device_t dev;
    uint8_t ch;

    dev = rt_device_find("ipc0_dev");

    if (dev == NULL) {
        rt_kprintf("[M55][IPC_DEV] can't find ipc device\r\n");
        return;
    }

    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        rt_kprintf("[M55][IPC_DEV] open device failed\r\n");
        return;
    }

    while (1) {
        rt_device_write(dev, RT_WAITING_FOREVER, SNED_DATA, strlen(SNED_DATA));

        while(rt_device_read(dev, 100, &ch, 1)) {
            rt_kprintf("%c", ch);
        }

        rt_thread_mdelay(500U);
    }
}
MSH_CMD_EXPORT(ipc_dev_test_run, M33 ipc dev test);