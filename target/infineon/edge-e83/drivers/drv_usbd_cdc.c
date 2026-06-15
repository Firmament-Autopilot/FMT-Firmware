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
#include "usbd_cdc.h"
#include "usbd_cdc_acm.h"
#include "usbd_core.h"
#include "module/task_manager/task_manager.h"

#define CDC_IN_EP          0x81
#define CDC_OUT_EP         0x02
#define CDC_INT_EP         0x83

#define USBD_VID           0xFFFF
#define USBD_PID           0xFFFF
#define USBD_MAX_POWER     100
#define USBD_LANGID_STRING 1033

#define USB_CONFIG_SIZE    (9 + CDC_ACM_DESCRIPTOR_LEN)

#ifdef CONFIG_USB_HS
    #define CDC_MAX_MPS 512
#else
    #define CDC_MAX_MPS 64
#endif

static const uint8_t device_descriptor[] = {
    USB_DEVICE_DESCRIPTOR_INIT(USB_2_0, 0xEF, 0x02, 0x01, USBD_VID, USBD_PID, 0x0100, 0x01)
};

static const uint8_t config_descriptor[] = {
    USB_CONFIG_DESCRIPTOR_INIT(USB_CONFIG_SIZE, 0x02, 0x01, USB_CONFIG_BUS_POWERED, USBD_MAX_POWER),
    CDC_ACM_DESCRIPTOR_INIT(0x00, CDC_INT_EP, CDC_OUT_EP, CDC_IN_EP, CDC_MAX_MPS, 0x02)
};

static const uint8_t device_quality_descriptor[] = {
    0x0a,
    USB_DESCRIPTOR_TYPE_DEVICE_QUALIFIER,
    0x00,
    0x02,
    0x00,
    0x00,
    0x00,
    0x40,
    0x00,
    0x00,
};

static const char* string_descriptors[] = {
    (const char[]) { 0x09, 0x04 },
    "Firmament",
    "Firmament CDC Device",
    "2024010001",
};

static const uint8_t* device_descriptor_callback(uint8_t speed)
{
    return device_descriptor;
}

static const uint8_t* config_descriptor_callback(uint8_t speed)
{
    return config_descriptor;
}

static const uint8_t* device_quality_descriptor_callback(uint8_t speed)
{
    return device_quality_descriptor;
}

static const char* string_descriptor_callback(uint8_t speed, uint8_t index)
{
    if (index > 3) {
        return NULL;
    }
    return string_descriptors[index];
}

const struct usb_descriptor cdc_descriptor = {
    .device_descriptor_callback = device_descriptor_callback,
    .config_descriptor_callback = config_descriptor_callback,
    .device_quality_descriptor_callback = device_quality_descriptor_callback,
    .string_descriptor_callback = string_descriptor_callback
};

USB_NOCACHE_RAM_SECTION USB_MEM_ALIGNX uint8_t usb_read_buffer[CDC_MAX_MPS];
USB_NOCACHE_RAM_SECTION USB_MEM_ALIGNX uint8_t usb_write_buffer[USBD_CDC_TX_BUFSIZE];

static struct usbd_cdc_dev cdc_device;
static volatile bool ep_tx_busy_flag = false;
static uint8_t usb_busid = 0;
static struct usbd_interface intf0;
static struct usbd_interface intf1;

static fmt_err_t task_init(void)
{
    return FMT_EOK;
}

static void task_entry(void* parameter)
{
    extern void usbd_poll_connect_status(uint8_t busid);
    while (1) {
        usbd_poll_connect_status(0);
        sys_msleep(500);
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name = "usbd",
    .init = task_init,
    .entry = task_entry,
    .priority = 24,
    .auto_start = true,
    .stack_size = 4096,
    .param = NULL,
    .dependency = NULL
};

void usbd_cdc_acm_bulk_out(uint8_t busid, uint8_t ep, uint32_t nbytes)
{
    if (nbytes > 0) {
        rt_size_t written = ringbuffer_put(cdc_device.rx_rb, usb_read_buffer, nbytes);

        if (written > 0) {
            hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_RX);
        }
    }
    usbd_ep_start_read(busid, CDC_OUT_EP, usb_read_buffer, CDC_MAX_MPS);
}

void usbd_cdc_acm_bulk_in(uint8_t busid, uint8_t ep, uint32_t nbytes)
{
    if ((nbytes % usbd_get_ep_mps(busid, ep)) == 0 && nbytes) {
        usbd_ep_start_write(busid, CDC_IN_EP, NULL, 0);
    } else {
        ep_tx_busy_flag = false;
        hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_TX_COMPLETE);
    }
}

struct usbd_endpoint cdc_out_ep = {
    .ep_addr = CDC_OUT_EP,
    .ep_cb = usbd_cdc_acm_bulk_out
};

struct usbd_endpoint cdc_in_ep = {
    .ep_addr = CDC_IN_EP,
    .ep_cb = usbd_cdc_acm_bulk_in
};

static void usbd_event_handler(uint8_t busid, uint8_t event)
{
    switch (event) {
    case USBD_EVENT_RESET:
        break;

    case USBD_EVENT_CONNECTED:
        break;

    case USBD_EVENT_DISCONNECTED:
        ep_tx_busy_flag = false;
        hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_DISCONNECT);
        break;

    case USBD_EVENT_RESUME:
        break;

    case USBD_EVENT_SUSPEND:
        break;

    case USBD_EVENT_CONFIGURED:
        ep_tx_busy_flag = false;
        usbd_ep_start_read(busid, CDC_OUT_EP, usb_read_buffer, CDC_MAX_MPS);
        hal_usbd_cdc_notify_status(&cdc_device, USBD_STATUS_CONNECT);
        break;

    case USBD_EVENT_SET_REMOTE_WAKEUP:
        break;

    case USBD_EVENT_CLR_REMOTE_WAKEUP:
        break;

    default:
        break;
    }
}

static rt_err_t cdc_dev_init(usbd_cdc_dev_t dev)
{
    (void)dev;

    usbd_desc_register(usb_busid, &cdc_descriptor);

    usbd_add_interface(usb_busid, usbd_cdc_acm_init_intf(usb_busid, &intf0));
    usbd_add_interface(usb_busid, usbd_cdc_acm_init_intf(usb_busid, &intf1));

    usbd_add_endpoint(usb_busid, &cdc_out_ep);
    usbd_add_endpoint(usb_busid, &cdc_in_ep);

    usbd_initialize(usb_busid, USBHS_BASE, usbd_event_handler);

    return RT_EOK;
}

static rt_size_t cdc_dev_read(usbd_cdc_dev_t dev, rt_off_t pos, void* buf, rt_size_t size)
{
    rt_size_t read_len = 0;

    if (dev->rx_rb == NULL || buf == NULL || size == 0) {
        return 0;
    }

    read_len = ringbuffer_get(dev->rx_rb, (uint8_t*)buf, size);

    return read_len;
}

static rt_size_t cdc_dev_write(usbd_cdc_dev_t dev, rt_off_t pos, const void* buf, rt_size_t size)
{
    rt_size_t tx_size;
    rt_tick_t start_tick;
    rt_tick_t timeout_tick;
    int ret;

    (void)dev;

    if (buf == NULL || size == 0) {
        return 0;
    }

    timeout_tick = (rt_tick_t)pos;
    start_tick = rt_tick_get();
    while (ep_tx_busy_flag) {
        if (timeout_tick == 0) {
            return 0;
        }

        if (timeout_tick != RT_WAITING_FOREVER && rt_tick_get() - start_tick >= timeout_tick) {
            return 0;
        }

        rt_thread_mdelay(1);
    }

    tx_size = (size > USBD_CDC_TX_BUFSIZE) ? USBD_CDC_TX_BUFSIZE : size;
    memcpy(usb_write_buffer, buf, tx_size);

    ep_tx_busy_flag = true;
    ret = usbd_ep_start_write(usb_busid, CDC_IN_EP, usb_write_buffer, tx_size);
    if (ret < 0) {
        ep_tx_busy_flag = false;
        return 0;
    }

    return tx_size;
}

static rt_err_t cdc_dev_control(usbd_cdc_dev_t dev, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case RT_DEVICE_CTRL_CLR_INT:
        break;

    case RT_DEVICE_CTRL_SET_INT:
        break;

    default:
        ret = RT_ENOSYS;
        break;
    }

    return ret;
}

static struct usbd_cdc_ops cdc_ops = {
    .dev_init = NULL,
    .dev_read = cdc_dev_read,
    .dev_write = cdc_dev_write,
    .dev_control = cdc_dev_control
};

rt_err_t drv_usb_cdc_init(void)
{
    rt_err_t ret = RT_EOK;

    cdc_out_ep.ep_addr = CDC_OUT_EP;
    cdc_out_ep.ep_cb = usbd_cdc_acm_bulk_out;

    cdc_in_ep.ep_addr = CDC_IN_EP;
    cdc_in_ep.ep_cb = usbd_cdc_acm_bulk_in;

    memset(&cdc_device, 0, sizeof(cdc_device));
    cdc_device.ops = &cdc_ops;
    cdc_device.status = USBD_STATUS_DISCONNECT;

    ret = hal_usbd_cdc_register(&cdc_device, "usbd_cdc", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX, NULL);
    if (ret != RT_EOK) {
        return ret;
    }

    ret = cdc_dev_init(&cdc_device);
    if (ret != RT_EOK) {
        return ret;
    }

    return ret;
}
