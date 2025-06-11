/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include <firmament.h>

#include "module/mavproxy/mavproxy_dev.h"
#include "hal/serial/serial.h"

struct mavdev {
    rt_device_t dev;
    rt_err_t (*tx_done)(rt_device_t dev, void* buffer);
    rt_err_t (*rx_ind)(rt_device_t dev, rt_size_t size);
    fmt_err_t (*mav_rx_ind)(uint32_t size);
};

static struct mavdev mavdev_list[MAXPROXY_MAX_CHAN];

static rt_err_t mavdev_tx_done(rt_device_t dev, void* buffer)
{
    return RT_EOK;
}

static rt_err_t mavdev_rx_ind(rt_device_t dev, rt_size_t size)
{
    for (uint8_t chan = 0; chan < MAXPROXY_MAX_CHAN; chan++) {
        if (dev == mavdev_list[chan].dev) {
            /* find device channel */
            if (mavdev_list[chan].mav_rx_ind) {
                mavdev_list[chan].mav_rx_ind(size);
            }
        }
    }

    return RT_EOK;
}

rt_size_t mavproxy_dev_write(uint8_t chan, const void* buffer, uint32_t len, int32_t timeout)
{
    if (mavdev_list[chan].dev == NULL) {
        /* mavproxy device not initialized */
        return 0;
    }

    return rt_device_write(mavdev_list[chan].dev, timeout, buffer, len);
}

rt_size_t mavproxy_dev_read(uint8_t chan, void* buffer, uint32_t len, int32_t timeout)
{
    if (mavdev_list[chan].dev == NULL) {
        /* mavproxy device not initialized */
        return 0;
    }

    return rt_device_read(mavdev_list[chan].dev, timeout, buffer, len);
}

fmt_err_t mavproxy_dev_set_rx_indicate(uint8_t chan, fmt_err_t (*rx_ind)(uint32_t size))
{
    mavdev_list[chan].mav_rx_ind = rx_ind;

    return FMT_EOK;
}

fmt_err_t mavproxy_dev_set_device(uint8_t chan, const char* dev_name)
{
    rt_device_t new_dev;

    new_dev = rt_device_find(dev_name);

    if (new_dev == RT_NULL) {
        return FMT_EEMPTY;
    }

    if (new_dev != mavdev_list[chan].dev) {
        rt_uint16_t flag = RT_DEVICE_OFLAG_RDWR;

        /* if device support DMA, then use it */
        if (new_dev->flag & RT_DEVICE_FLAG_DMA_RX) {
            flag |= RT_DEVICE_FLAG_DMA_RX;
        } else {
            flag |= RT_DEVICE_FLAG_INT_RX;
        }

        if (new_dev->flag & RT_DEVICE_FLAG_DMA_TX) {
            flag |= RT_DEVICE_FLAG_DMA_TX;
        }

        rt_err_t err = rt_device_open(new_dev, flag);
        if (err != RT_EOK) {
            return FMT_ERROR;
        }
        mavdev_list[chan].dev = new_dev;
    }

    /* set callback functions */
    rt_device_set_tx_complete(new_dev, mavdev_list[chan].tx_done);
    rt_device_set_rx_indicate(new_dev, mavdev_list[chan].rx_ind);

    return FMT_EOK;
}

rt_device_t mavproxy_dev_get_device(uint8_t chan)
{
    return mavdev_list[chan].dev;
}

/**
 * @brief  Get the bandwidth of a mavlink channel
 *
 * @param  chan: mavlink channel
 *
 * @return bandwidth unit: bytes/s
 */
uint32_t mavproxy_dev_get_bw(uint8_t chan)
{
    uint32_t bw = 0;
    struct serial_device* serial;
    rt_device_t dev = mavdev_list[chan].dev;
    if (dev == RT_NULL) {
        /* mavproxy device not initialized */
        return 0;
    }

    if (dev->type == RT_Device_Class_Char) {
        serial = (struct serial_device*)dev;
        bw = serial->config.baud_rate / 10; // convert bits to bytes minus overhead
    } else if (dev->type == RT_Device_Class_USBDevice) {
        bw = 250 * 1024;                    // The USB Full Speed (FS) transmission rate is conservatively estimated at 2 Mbps.
    } else {
        console_printf("Error device type %d\n", dev->type);
        bw = 0;
    }

    return bw;
}

fmt_err_t mavproxy_dev_init(void)
{
    for (uint8_t i = 0; i < MAXPROXY_MAX_CHAN; i++) {
        mavdev_list[i].tx_done = mavdev_tx_done;
        mavdev_list[i].rx_ind = mavdev_rx_ind;
    }
    
    return FMT_EOK;
}
