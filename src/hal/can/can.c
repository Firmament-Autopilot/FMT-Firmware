#include "hal/can/can.h"
#include <firmament.h>

static rt_err_t hal_can_init(struct rt_device* dev)
{
    rt_err_t result = RT_EOK;
    can_dev_t can;

    RT_ASSERT(dev != RT_NULL);
    can = (can_dev_t)dev;

    /* init low-level device */
    if (can->ops->configure) {
        result = can->ops->configure(can, &can->config);
    }

    return result;
}

static rt_size_t hal_can_write(rt_device_t dev,
                               rt_off_t pos,
                               const void* buffer,
                               rt_size_t size)
{
    can_dev_t can_dev;

    RT_ASSERT(dev != RT_NULL);

    can_dev = (can_dev_t)dev;

    if (size == 0)
        return 0;

    return can_dev->ops->sendmsg(can_dev, buffer);
}

static rt_size_t hal_can_read(rt_device_t dev,
                              rt_off_t pos,
                              void* buffer,
                              rt_size_t size)
{

    can_dev_t can_dev;

    RT_ASSERT(dev != RT_NULL);

    can_dev = (can_dev_t)dev;

    return can_dev->ops->recvmsg(can_dev, buffer);
}

/*
 * can register
 */
rt_err_t hw_can_register(can_device* can,
                         const char* name,
                         rt_uint32_t flag,
                         void* data)
{
    rt_err_t ret;

    struct rt_device* device;
    RT_ASSERT(can != RT_NULL);

    device = &(can->parent);

    device->type = RT_Device_Class_CAN;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

#ifdef RT_USING_DEVICE_OPS
    device->ops = &can_device_ops;
#else
    device->init = hal_can_init;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = hal_can_read;
    device->write = hal_can_write;
    device->control = RT_NULL;
#endif

    device->user_data = data;

    ret = rt_device_register(device, name, flag);

    return ret;
}