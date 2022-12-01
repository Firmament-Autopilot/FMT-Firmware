#include "hal/fdcan/fdcan.h"
#include <firmament.h>

static rt_err_t hal_fdcan_init(struct rt_device* dev)
{
    rt_err_t result = RT_EOK;
    fdcan_dev_t fdcan;

    RT_ASSERT(dev != RT_NULL);
    fdcan = (fdcan_dev_t)dev;

    /* init low-level device */
    if (fdcan->ops->configure) {
        result = fdcan->ops->configure(fdcan, &fdcan->config);
    }

    return result;
}

static rt_size_t hal_fdcan_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    fdcan_dev_t fdcan_dev;

    RT_ASSERT(dev != RT_NULL);

    fdcan_dev = (fdcan_dev_t)dev;

    if (size == 0)
        return 0;

    return fdcan_dev->ops->sendmsg(fdcan_dev, buffer, size);
}

static rt_size_t hal_fdcan_read(rt_device_t dev,
                                rt_off_t pos,
                                void* buffer,
                                rt_size_t size)
{
    uint32_t count;

    fdcan_dev_t fdcan_dev;

    RT_ASSERT(dev != RT_NULL);

    fdcan_dev = (fdcan_dev_t)dev;

    fdcan_dev->ops->recvmsg(fdcan_dev, buffer, &count);

    return count;
}

/*
 * can register
 */
rt_err_t rt_hw_can_register(struct fdcan_device* fdcan, const char* name, rt_uint32_t flag, void* data)
{
    rt_err_t ret;

    struct rt_device* device;
    RT_ASSERT(fdcan != RT_NULL);

    device = &(fdcan->parent);

    device->type = RT_Device_Class_CAN;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    fdcan->can_rx = RT_NULL;
    fdcan->can_tx = RT_NULL;

#ifdef RT_USING_DEVICE_OPS
    device->ops = &fdcan_device_ops;
#else
    device->init = hal_fdcan_init;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = hal_fdcan_read;
    device->write = hal_fdcan_write;
    device->control = RT_NULL;
#endif

    device->user_data = data;

    ret = rt_device_register(device, name, flag);

    return ret;
}