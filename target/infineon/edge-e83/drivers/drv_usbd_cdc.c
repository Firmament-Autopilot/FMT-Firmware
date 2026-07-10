/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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

#include "hal/usb/usbd_cdc.h"
#include "USB.h"
#include "USB_CDC.h"
#include "usb_config.h"

#define VENDOR_ID              0xFFFF
#define PRODUCT_ID             0xFFFF
#define USB_ENABLE_FLAG        0u
#define USB_BULK_IN_INTERVAL   0u
#define USB_BULK_OUT_INTERVAL  0u
#define USB_INT_INTERVAL       16u
#define USB_THREAD_STACK       3072u
#define USB_THREAD_PRIO        8u
#define USB_THREAD_TICK        10u
#define USB_START_DELAY_MS     50u
#define USB_RX_POLL_MS         2u
#define USB_TX_READY_TIMEOUT   50u
#define USB_TX_DONE_TIMEOUT    200u
#define USB_DCACHE_ALIGN       __SCB_DCACHE_LINE_SIZE
#define USB_TX_BUFFER_SIZE     1024u

static const USB_DEVICE_INFO usb_device_info = {
    VENDOR_ID,
    PRODUCT_ID,
    "Firmament",
    "Firmament CDC Device",
    "2024010001"
};

static struct usbd_cdc_dev cdc_device;
static USB_CDC_HANDLE usb_cdc_handle;
static volatile bool usb_configured = false;
static volatile bool usb_stack_started = false;
static rt_thread_t usb_thread = RT_NULL;
static volatile bool usb_tx_pending = false;
static volatile bool usb_tx_abort_pending = false;
static volatile bool usb_tx_slot_busy = false;
static rt_size_t usb_tx_size = 0u;
static rt_sem_t usb_tx_sem = RT_NULL;

USB_NOCACHE_RAM_SECTION
CY_ALIGN(USB_DCACHE_ALIGN)
static uint8_t read_buffer[USB_HS_BULK_MAX_PACKET_SIZE];

USB_NOCACHE_RAM_SECTION
CY_ALIGN(USB_DCACHE_ALIGN)
static uint8_t write_buffer[USB_TX_BUFFER_SIZE];

USB_NOCACHE_RAM_SECTION
CY_ALIGN(USB_DCACHE_ALIGN)
static U8 out_ep_buffer[USB_HS_BULK_MAX_PACKET_SIZE];

static void usb_dcache_clean(const void* addr, rt_size_t size)
{
    (void)addr;
    (void)size;
}

static void usb_dcache_invalidate(const void* addr, rt_size_t size)
{
    (void)addr;
    (void)size;
}

static void usb_add_cdc(void)
{
    USB_CDC_INIT_DATA init_data;
    USB_ADD_EP_INFO ep_bulk_in;
    USB_ADD_EP_INFO ep_bulk_out;
    USB_ADD_EP_INFO ep_int_in;

    memset(&init_data, 0, sizeof(init_data));
    memset(&ep_bulk_in, 0, sizeof(ep_bulk_in));
    memset(&ep_bulk_out, 0, sizeof(ep_bulk_out));
    memset(&ep_int_in, 0, sizeof(ep_int_in));

    ep_bulk_in.Flags = USB_ENABLE_FLAG;
    ep_bulk_in.InDir = USB_DIR_IN;
    ep_bulk_in.Interval = USB_BULK_IN_INTERVAL;
    ep_bulk_in.MaxPacketSize = USB_HS_BULK_MAX_PACKET_SIZE;
    ep_bulk_in.TransferType = USB_TRANSFER_TYPE_BULK;
    init_data.EPIn = USBD_AddEPEx(&ep_bulk_in, NULL, 0);

    ep_bulk_out.Flags = USB_ENABLE_FLAG;
    ep_bulk_out.InDir = USB_DIR_OUT;
    ep_bulk_out.Interval = USB_BULK_OUT_INTERVAL;
    ep_bulk_out.MaxPacketSize = USB_HS_BULK_MAX_PACKET_SIZE;
    ep_bulk_out.TransferType = USB_TRANSFER_TYPE_BULK;
    init_data.EPOut = USBD_AddEPEx(&ep_bulk_out, out_ep_buffer, sizeof(out_ep_buffer));

    ep_int_in.Flags = USB_ENABLE_FLAG;
    ep_int_in.InDir = USB_DIR_IN;
    ep_int_in.Interval = USB_INT_INTERVAL;
    ep_int_in.MaxPacketSize = USB_HS_INT_MAX_PACKET_SIZE;
    ep_int_in.TransferType = USB_TRANSFER_TYPE_INT;
    init_data.EPInt = USBD_AddEPEx(&ep_int_in, NULL, 0);

    usb_cdc_handle = USBD_CDC_Add(&init_data);
}

static void usb_update_connection_state(void)
{
    uint32_t state;

    state = USBD_GetState();

    if (!usb_configured) {
        if ((state & (USB_STAT_CONFIGURED | USB_STAT_SUSPENDED)) == USB_STAT_CONFIGURED) {
            usb_configured = true;
            hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_CONNECT);
        }
    } else if ((state & USB_STAT_CONFIGURED) == 0u) {
        bool need_release = usb_tx_slot_busy;

        usb_configured = false;
        usb_tx_pending = false;
        usb_tx_size = 0u;
        usb_tx_abort_pending = true;
        usb_tx_slot_busy = false;
        if (need_release && usb_tx_sem) {
            rt_sem_release(usb_tx_sem);
        }
        hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_DISCONNECT);
        if (cdc_device.rx_rb) {
            ringbuffer_flush(cdc_device.rx_rb);
        }
    }
}

static void usb_cdc_process_tx(void)
{
    int ret;
    int wait_ret;

    if (usb_tx_abort_pending) {
        usb_tx_abort_pending = false;
        if (usb_tx_slot_busy) {
            usb_tx_slot_busy = false;
            if (usb_tx_sem) {
                rt_sem_release(usb_tx_sem);
            }
        }
        }

    if (!usb_tx_pending) {
        return;
    }

    if (!usb_stack_started || !usb_configured || usb_tx_size == 0u) {
        usb_tx_pending = false;
        usb_tx_size = 0u;
        if (usb_tx_slot_busy) {
            usb_tx_slot_busy = false;
            if (usb_tx_sem) {
                rt_sem_release(usb_tx_sem);
            }
        }
        return;
    }

    usb_dcache_clean(write_buffer, usb_tx_size);

    ret = USBD_CDC_WaitForTXReady(usb_cdc_handle, USB_TX_READY_TIMEOUT);
    if (ret < 0) {
        usb_tx_pending = false;
        usb_tx_size = 0u;
        if (usb_tx_slot_busy) {
            usb_tx_slot_busy = false;
            if (usb_tx_sem) {
                rt_sem_release(usb_tx_sem);
            }
        }
        return;
    }

    ret = USBD_CDC_Write(usb_cdc_handle, write_buffer, (unsigned)usb_tx_size, 0);
    if (ret < 0) {
        usb_tx_pending = false;
        usb_tx_size = 0u;
        if (usb_tx_slot_busy) {
            usb_tx_slot_busy = false;
            if (usb_tx_sem) {
                rt_sem_release(usb_tx_sem);
            }
        }
        return;
    }

    wait_ret = USBD_CDC_WaitForTX(usb_cdc_handle, USB_TX_DONE_TIMEOUT);
    if (wait_ret < 0) {
        USBD_CDC_CancelWrite(usb_cdc_handle);
        usb_tx_pending = false;
        usb_tx_size = 0u;
        if (usb_tx_slot_busy) {
            usb_tx_slot_busy = false;
            if (usb_tx_sem) {
                rt_sem_release(usb_tx_sem);
            }
        }
        return;
    }

    usb_tx_pending = false;
    usb_tx_size = 0u;
    if (usb_tx_slot_busy) {
        usb_tx_slot_busy = false;
        if (usb_tx_sem) {
            rt_sem_release(usb_tx_sem);
        }
    }
    hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_TX_COMPLETE);
}

static void usb_cdc_thread_entry(void* parameter)
{
    int recv_len;
    uint32_t pushed_len;

    (void)parameter;

    rt_thread_mdelay(USB_START_DELAY_MS);

    USBD_Init();
    usb_add_cdc();
    USBD_SetDeviceInfo(&usb_device_info);
    USBD_Start();
    usb_stack_started = true;

    while (1) {
        usb_update_connection_state();

        if (!usb_configured) {
            continue;
        }

        recv_len = USBD_CDC_Receive(usb_cdc_handle, read_buffer, sizeof(read_buffer), USB_RX_POLL_MS);
        if (recv_len > 0) {
            usb_dcache_invalidate(read_buffer, (rt_size_t)recv_len);

            pushed_len = ringbuffer_put(cdc_device.rx_rb, read_buffer, (uint32_t)recv_len);
            if (pushed_len > 0u) {
                hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_RX);
            }
        }

        usb_cdc_process_tx();
    }
}

static rt_err_t cdc_dev_init(usbd_cdc_dev_t dev)
{
    (void)dev;

    if (usb_thread != RT_NULL) {
        return RT_EOK;
    }

    usb_tx_sem = rt_sem_create("usb_txq", 1, RT_IPC_FLAG_FIFO);
    if (usb_tx_sem == RT_NULL) {
        return RT_ENOMEM;
    }

    usb_thread = rt_thread_create("usb_cdc",
                                  usb_cdc_thread_entry,
                                  RT_NULL,
                                  USB_THREAD_STACK,
                                  USB_THREAD_PRIO,
                                  USB_THREAD_TICK);
    if (usb_thread == RT_NULL) {
        return RT_ENOMEM;
    }

    rt_thread_startup(usb_thread);
    return RT_EOK;
}

static rt_size_t cdc_dev_read(usbd_cdc_dev_t dev, rt_off_t pos, void* buf, rt_size_t size)
{
    (void)pos;

    return ringbuffer_get(dev->rx_rb, buf, (uint32_t)size);
}

static rt_size_t cdc_dev_write(usbd_cdc_dev_t dev, rt_off_t pos, const void* buf, rt_size_t size)
{
    (void)dev;
    (void)pos;

    if (!usb_stack_started || !usb_configured || buf == RT_NULL || size == 0u) {
        return 0u;
    }

    if (size > sizeof(write_buffer) || usb_tx_sem == RT_NULL) {
        return 0u;
    }

    if (rt_sem_take(usb_tx_sem, TICKS_FROM_MS(USB_TX_DONE_TIMEOUT)) != RT_EOK) {
        return 0u;
    }

    if (!usb_stack_started || !usb_configured) {
        rt_sem_release(usb_tx_sem);
        return 0u;
    }

    memcpy(write_buffer, buf, size);
    usb_tx_slot_busy = true;
    usb_tx_size = size;
    usb_tx_pending = true;

    return size;
}

static rt_err_t cdc_dev_control(usbd_cdc_dev_t dev, int cmd, void* arg)
{
    (void)dev;
    (void)cmd;
    (void)arg;
    return RT_EOK;
}

static struct usbd_cdc_ops cdc_ops = {
    .dev_init = NULL,
    .dev_read = cdc_dev_read,
    .dev_write = cdc_dev_write,
    .dev_control = cdc_dev_control
};

rt_err_t drv_usb_cdc_init(void)
{
    rt_err_t ret;

    memset(&cdc_device, 0, sizeof(cdc_device));
    cdc_device.ops = &cdc_ops;
    cdc_device.status = USBD_STATUS_DISCONNECT;

    ret = hal_usbd_cdc_register(&cdc_device,
                                "usbd_cdc",
                                RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX,
                                NULL);
    if (ret != RT_EOK) {
        return ret;
    }

    ret = cdc_dev_init(&cdc_device);
    if (ret != RT_EOK) {
        return ret;
    }

    return RT_EOK;
}
