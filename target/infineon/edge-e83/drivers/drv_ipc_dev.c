#include <rtdevice.h>
#include <rtthread.h>
#include <string.h>

#include "drv_ipc.h"
#include "ipc_common.h"
#include "module/system/systime.h"
#include "module/utils/ringbuffer.h"

static rt_device_t g_ipc_dev = RT_NULL;
static edge_rc_frame_t rx;
static edge_rc_frame_t tx;
static ringbuffer* rx_rb;
static struct rt_completion rx_ind;
static const uint32_t ipc_channel_size = sizeof(tx.channel);

static rt_err_t ipc_dev_rx_indicate(rt_device_t dev, rt_size_t size)
{
    while (rt_device_read(g_ipc_dev, 0, &rx, 1) == 1) {
        ringbuffer_put(rx_rb, (uint8_t*)rx.channel, rx.seq);
    }

    rt_completion_done(&rx_ind);

    return RT_EOK;
}

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
        if (rt_device_write(g_ipc_dev, pos, &tx, 1) != 1)
            return 0;
    }

    if (size % ipc_channel_size) {
        ipc_fill_packet(&tx, (void*)((uint32_t)buffer + i * ipc_channel_size), size % ipc_channel_size);
        if (rt_device_write(g_ipc_dev, pos, &tx, 1) != 1)
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
    rx_cnt = ringbuffer_get(rx_rb, buffer, size);

    /* if timeout is not 0, then check if required length data read */
    if (timeout != 0) {
        uint32_t time_start, elapse_time;
        /* if not enough data reveived, wait it */
        while (rx_cnt < size) {
            time_start = systime_now_ms();
            /* wait until something reveived (synchronized read) */
            if (rt_completion_wait(&rx_ind, timeout) != RT_EOK) {
                break;
            }
            if (timeout > 0) {
                elapse_time = systime_now_ms() - time_start;
                timeout -= elapse_time;
                if (timeout <= 0) {
                    /* timeout */
                    break;
                }
            }
            /* read rest data */
            rx_cnt += ringbuffer_get(rx_rb, (void*)((uint32_t)buffer + rx_cnt), size - rx_cnt);
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

    rx_rb = ringbuffer_create(sizeof(tx.channel) * 20);
    if (rx_rb == RT_NULL) {
        return -RT_ENOMEM;
    }

    rt_completion_init(&rx_ind);

    g_ipc_dev->rx_indicate = ipc_dev_rx_indicate;

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