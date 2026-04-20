#include <rtdevice.h>
#include <rtthread.h>
#include <string.h>

#include "drv_ipc.h"
#include "ipc_common.h"

void ipc_dev_test_run(void)
{
    rt_device_t dev;
    uint8_t buffer[20] = { 0 };

    dev = rt_device_find("ipc0_dev");

    if (dev == NULL) {
        rt_kprintf("[M33][IPC_DEV] can't find ipc device\r\n");
        return;
    }

    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        rt_kprintf("[M33][IPC_DEV] open device failed\r\n");
        return;
    }

    while (1) {
        for (int8_t i = 0; i < sizeof(buffer); i++) {
            buffer[i] = i;
        }
        rt_device_write(dev, 0, buffer, sizeof(buffer));

        memset(buffer, 0, sizeof(buffer));
        rt_device_read(dev, RT_WAITING_FOREVER, buffer, sizeof(buffer));
        rt_kprintf("[M33][IPC_DEV] recv data:");
        for (int8_t i = 0; i < sizeof(buffer); i++) {
            rt_kprintf("%d,", buffer[i]);
        }
        rt_kprintf("\r\n");

        rt_thread_mdelay(100U);
    }
}
MSH_CMD_EXPORT(ipc_dev_test_run, M33 ipc dev test);