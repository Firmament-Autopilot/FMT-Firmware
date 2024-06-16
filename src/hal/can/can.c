
#include <firmament.h>

#include "hal/can/can.h"

#define HAL_DBG(...) printf(__VA_ARGS__)

static rt_err_t hal_can_init(struct rt_device* dev)
{
    rt_err_t  ret = RT_EOK;
    can_dev_t can_dev;

    RT_ASSERT(dev != RT_NULL);
    can_dev = (can_dev_t)dev;

    /* configure low-level can device */
    if (can_dev->ops->configure) {
        ret = can_dev->ops->configure(can_dev, &can_dev->config);
    }

    return ret;
}

static rt_err_t hal_can_open(rt_device_t dev, rt_uint16_t oflag)
{
    rt_err_t  ret = RT_EOK;
    can_dev_t can_dev;

    RT_ASSERT(dev != RT_NULL);

    can_dev = (can_dev_t)dev;

    /* set open flags */
    dev->open_flag = (oflag & RT_DEVICE_OFLAG_MASK);

    if (can_dev->rx_fifo == RT_NULL) {
        can_dev->rx_fifo = ringbuffer_create(CAN_RX_FIFO_SIZE * CAN_MSG_LEN);
        if (can_dev->rx_fifo == RT_NULL) {
            return RT_ENOMEM;
        }
    }

    if (can_dev->ops->control) {
        ret = can_dev->ops->control(can_dev, CAN_OPEN_DEVICE, NULL);
    }

    return ret;
}

rt_err_t hal_can_close(rt_device_t dev)
{
    rt_err_t  ret = RT_EOK;
    can_dev_t can_dev;

    RT_ASSERT(dev != RT_NULL);

    can_dev = (can_dev_t)dev;

    dev->open_flag = RT_DEVICE_OFLAG_CLOSE;

    if (can_dev->rx_fifo) {
        ringbuffer_delete(can_dev->rx_fifo);
        can_dev->rx_fifo = RT_NULL;
    }

    if (can_dev->ops->control) {
        ret = can_dev->ops->control(can_dev, CAN_CLOSE_DEVICE, NULL);
    }

    return ret;
}

static rt_size_t hal_can_write(rt_device_t dev,
                               rt_off_t    pos,
                               const void* buffer,
                               rt_size_t   size)
{
    can_dev_t  can_dev;
    rt_size_t  s_size     = 0;
    rt_int32_t timeout    = (rt_int32_t)pos;
    can_msg_t  msg_buffer = (can_msg_t)buffer;

    RT_ASSERT(dev != RT_NULL);
    RT_ASSERT(buffer != RT_NULL);

    can_dev = (can_dev_t)dev;

    if (size == 0 || can_dev->ops->sendmsg == RT_NULL)
        return 0;

    /* take tx lock */
    if (rt_sem_take(can_dev->tx_lock, timeout) != RT_EOK)
        return 0;

    for (uint32_t i = 0; i < size; i++) {
        /* send can message */
        s_size += can_dev->ops->sendmsg(can_dev, msg_buffer++);
        /* wait write complete */
        rt_completion_wait(&can_dev->tx_cplt, timeout);
    }

    /* release tx lock */
    rt_sem_release(can_dev->tx_lock);

    return s_size;
}

static rt_size_t hal_can_read(rt_device_t dev,
                              rt_off_t    pos,
                              void*       buffer,
                              rt_size_t   size)
{
    can_dev_t  can_dev;
    uint32_t   r_size  = 0;
    rt_int32_t timeout = (rt_int32_t)pos;

    RT_ASSERT(dev != RT_NULL);
    RT_ASSERT(buffer != RT_NULL);

    can_dev = (can_dev_t)dev;

    if (size == 0)
        return 0;

    if (dev->open_flag & RT_DEVICE_FLAG_INT_RX) {
        r_size = ringbuffer_get(can_dev->rx_fifo, buffer, size * CAN_MSG_LEN) / CAN_MSG_LEN;

        while (r_size < size) {
            /* wait receive data */
            if (rt_completion_wait(&can_dev->rx_cplt, timeout) != RT_EOK) {
                return r_size;
            }
            /* read left data */
            r_size += ringbuffer_get(can_dev->rx_fifo, &((uint8_t*)buffer)[r_size * CAN_MSG_LEN], (size - r_size) * CAN_MSG_LEN) / CAN_MSG_LEN;
        }
    } else {
        can_msg_t can_buffer = buffer;

        if (can_dev->ops->recvmsg == RT_NULL)
            return 0;

        for (uint32_t i = 0; i < size; i++) {
            r_size += can_dev->ops->recvmsg(can_dev, can_buffer++);
        }
    }

    return r_size;
}

void hal_can_notify(can_device* can, int event, void* data)
{
    if (can == RT_NULL) {
        HAL_DBG("NULL check failed at function:%s, line number:%d\n", __FUNCTION__, __LINE__);
        return;
    }

    switch (event & 0xff) {
    case CAN_EVENT_RX_IND: {
        /* put can message to rx fifo. if fifo is full, the new msg data will be dropped */
        ringbuffer_put(can->rx_fifo, data, CAN_MSG_LEN);

        rt_completion_done(&can->rx_cplt);

        /* notify can message received */
        if (can->parent.rx_indicate != RT_NULL) {
            rt_size_t rx_length = ringbuffer_getlen(can->rx_fifo) / CAN_MSG_LEN;
            if (rx_length) {
                can->parent.rx_indicate(&can->parent, rx_length);
            }
        }
    } break;

    case CAN_EVENT_TX_DONE: {
        rt_completion_done(&can->tx_cplt);

        /* notify can message send complete */
        if (can->parent.tx_complete != RT_NULL) {
            can->parent.tx_complete(&can->parent, data);
        }
    } break;

    default:
        break;
    }
}

/*
 * can register
 */
rt_err_t hal_can_register(can_device* can,
                          const char* name,
                          rt_uint32_t flag,
                          void*       data)
{
    rt_err_t ret;

    struct rt_device* device;
    RT_ASSERT(can != RT_NULL);

    rt_completion_init(&can->tx_cplt);
    rt_completion_init(&can->rx_cplt);

    /* write lock */
    can->tx_lock = rt_sem_create(name, 1, RT_IPC_FLAG_FIFO);
    RT_ASSERT(can->tx_lock != NULL);

    device = &(can->parent);

    device->type        = RT_Device_Class_CAN;
    device->ref_count   = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init      = hal_can_init;
    device->open      = hal_can_open;
    device->close     = hal_can_close;
    device->read      = hal_can_read;
    device->write     = hal_can_write;
    device->control   = RT_NULL;
    device->user_data = data;

    ret = rt_device_register(device, name, flag);

    return ret;
}