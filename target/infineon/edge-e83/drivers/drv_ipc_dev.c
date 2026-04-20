#include <rtdevice.h>
#include <rtthread.h>
#include <string.h>

#include "module/system/systime.h"
#include "drv_ipc.h"
#include "ipc_common.h"

static rt_device_t g_ipc_dev = RT_NULL;
static edge_rc_frame_t rx;
static edge_rc_frame_t tx;
static const uint32_t ipc_channel_size = sizeof(tx.channel);

static void ipc_fill_packet(edge_rc_frame_t* frame, const void* data, rt_size_t size)
{
    frame->client_id = CM33_IPC_PIPE_CLIENT_ID;
    frame->intr_mask = (rt_uint16_t)CY_IPC_CYPIPE_INTR_MASK_EP1;
    frame->role = RC_ROLE_M55_ECHO;
    frame->magic = RC_MAGIC_WORD;
    frame->seq = size; /* use seq as size */

    rt_memcpy((void*)tx.channel, data, size);

    frame->checksum = edge_rc_checksum(frame);
}

static rt_size_t ipc_dev_write(struct rt_device* dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    uint32_t i;

    for (i = 0; i < size / ipc_channel_size; i++) {
        ipc_fill_packet(&tx, (void*)((uint32_t)buffer + i * ipc_channel_size), ipc_channel_size);
        if (rt_device_write(g_ipc_dev, 0, &tx, 1) != 1)
            return 0;
    }

    if (size % ipc_channel_size) {
        ipc_fill_packet(&tx, (void*)((uint32_t)buffer + i * ipc_channel_size), size % ipc_channel_size);
        if (rt_device_write(g_ipc_dev, 0, &tx, 1) != 1)
            return 0;
    }

    return size;
}

static rt_size_t ipc_dev_read(struct rt_device* dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    rt_size_t rx_cnt = 0;
    rt_int32_t timeout = pos;

    if (size == 0) {
        return 0;
    }

    if ((dev == RT_NULL) || (buffer == RT_NULL)) {
        return 0;
    }

    if (size == 0)
        return 0;

    /* try to read data */
    while (rt_device_read(g_ipc_dev, 0, &rx, 1) == 1) {
        rt_memcpy((void*)((uint32_t)buffer + rx_cnt), (void*)rx.channel, rx.seq);
        rx_cnt += rx.seq;
        if (rx_cnt >= size)
            break;
    }

    /* if timeout is not 0, then check if required length data read */
    if (timeout != 0) {
        uint32_t time_start = systime_now_ms();

        /* if not enough data reveived, wait it */
        while (rx_cnt < size) {
            if (timeout > 0) {
                if ((systime_now_ms() - time_start) >= timeout) {
                    /* timeout */
                    break;
                }
            }
            /* read rest data */
            while (rt_device_read(g_ipc_dev, 0, &rx, 1) == 1) {
                rt_memcpy((void*)((uint32_t)buffer + rx_cnt), (void*)rx.channel, rx.seq);
                rx_cnt += rx.seq;
                if (rx_cnt >= size)
                    break;
            }

            /* sleep to do not block the system */
            sys_msleep(1);
        }
    }

    return rx_cnt;
}

static rt_err_t ipc_dev_init(struct rt_device* dev)
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

    return RT_EOK;
}

static rt_err_t ipc_dev_open(struct rt_device* dev, rt_uint16_t oflag)
{
    if (rt_device_open(g_ipc_dev, oflag) != RT_EOK) {
        rt_kprintf("[M55][IPC] open device failed\r\n");
        return -RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t ipc_dev_close(struct rt_device* dev)
{
    if (rt_device_close(g_ipc_dev) != RT_EOK) {
        rt_kprintf("[M55][IPC] close device failed\r\n");
        return -RT_ERROR;
    }

    return RT_EOK;
}

rt_err_t drv_ipc_dev_init(void)
{
    static struct rt_device device;

    device.type = RT_Device_Class_Char;
    device.ref_count = 0;
    device.rx_indicate = RT_NULL;
    device.tx_complete = RT_NULL;

    device.init = ipc_dev_init;
    device.open = ipc_dev_open;
    device.close = ipc_dev_close;
    device.read = ipc_dev_read;
    device.write = ipc_dev_write;
    device.control = RT_NULL;
    device.user_data = RT_NULL;

    /* register character to system */
    return rt_device_register(&device, "ipc0_dev", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
}