#include <rtdevice.h>
#include <rtthread.h>
#include <string.h>

#include "drv_ipc.h"
#include "ipc_common.h"

static rt_device_t g_ipc_dev = RT_NULL;
static rt_thread_t g_ipc_thread = RT_NULL;

static void cm55_dump_frame(const edge_rc_frame_t* frame)
{
    rt_kprintf("[M55][IPC] rx seq=%lu ch=[%u,%u,%u,%u,%u,%u,%u,%u]\r\n",
               frame->seq,
               frame->channel[0],
               frame->channel[1],
               frame->channel[2],
               frame->channel[3],
               frame->channel[4],
               frame->channel[5],
               frame->channel[6],
               frame->channel[7]);
}

static rt_bool_t cm55_verify_request(const edge_rc_frame_t* frame)
{
    if (frame->role != RC_ROLE_M33 || frame->magic != RC_MAGIC_WORD) {
        return RT_FALSE;
    }

    if (edge_rc_checksum(frame) != frame->checksum) {
        return RT_FALSE;
    }

    return RT_TRUE;
}

void edge_ipc_demo_run(void)
{
    edge_rc_frame_t rx;
    edge_rc_frame_t tx;

    while (1) {
        while (rt_device_read(g_ipc_dev, 0, &rx, 1) == 1) {
            if (!cm55_verify_request(&rx)) {
                continue;
            }

            cm55_dump_frame(&rx);

            tx = rx;
            tx.role = RC_ROLE_M55_ECHO;
            tx.checksum = edge_rc_checksum(&tx);
            (void)rt_device_write(g_ipc_dev, 0, &tx, 1);
        }

        rt_thread_mdelay(1);
    }
}

static void edge_ipc_demo_entry(void* parameter)
{
    (void)parameter;
    edge_ipc_demo_run();
}

int ipc_test_run(void)
{
    g_ipc_dev = edge_ipc_device_find();
    if (g_ipc_dev == RT_NULL) {
        if (edge_ipc_device_register() != RT_EOK) {
            rt_kprintf("[M55][IPC] device register failed\r\n");
            return -RT_ERROR;
        }

        g_ipc_dev = edge_ipc_device_find();
        if (g_ipc_dev == RT_NULL) {
            rt_kprintf("[M55][IPC] device not found\r\n");
            return -RT_ERROR;
        }
    }

    if (rt_device_open(g_ipc_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        rt_kprintf("[M55][IPC] open device failed\r\n");
        return -RT_ERROR;
    }

    if (g_ipc_thread == RT_NULL) {
        g_ipc_thread = rt_thread_create("ipc_demo",
                                        edge_ipc_demo_entry,
                                        RT_NULL,
                                        2048,
                                        25,
                                        10);
        if (g_ipc_thread == RT_NULL) {
            rt_kprintf("[M55][IPC] create thread failed\r\n");
            return -RT_ENOMEM;
        }

        rt_thread_startup(g_ipc_thread);
        rt_kprintf("[M55][IPC] demo start\r\n");
    }

    return RT_EOK;
}
MSH_CMD_EXPORT(ipc_test_run, M55 ipc test);
