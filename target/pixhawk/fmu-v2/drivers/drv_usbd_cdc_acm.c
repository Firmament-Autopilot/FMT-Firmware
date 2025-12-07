/******************************************************************************
 * Copyright 2020-2025 The Firmament Authors. All Rights Reserved.
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
#include "usbd_core.h"
#include "usbd_cdc_acm.h"
#include "hal/usb/usbd_cdc.h"
#include "drv_usbd_cdc_acm.h"

/* endpoint address */
#define CDC_IN_EP  0x81
#define CDC_OUT_EP 0x02
#define CDC_INT_EP 0x83

#define USBD_VID           0x0483
#define USBD_PID           0x5740
#define USBD_MAX_POWER     250
#define USBD_LANGID_STRING 1033

/* config descriptor size */
#define USB_CONFIG_SIZE (9 + CDC_ACM_DESCRIPTOR_LEN)

#ifdef CONFIG_USB_HS
#define CDC_MAX_MPS 512
#else
#define CDC_MAX_MPS 64
#endif

static struct usbd_cdc_dev usbd_dev = { 0 };

#ifdef CONFIG_USBDEV_ADVANCE_DESC
static const uint8_t device_descriptor[] = {
    USB_DEVICE_DESCRIPTOR_INIT(USB_2_0, 0xEF, 0x02, 0x01, USBD_VID, USBD_PID, 0x0100, 0x01)
};

static const uint8_t config_descriptor[] = {
    USB_CONFIG_DESCRIPTOR_INIT(USB_CONFIG_SIZE, 0x02, 0x01, USB_CONFIG_BUS_POWERED, USBD_MAX_POWER),
    CDC_ACM_DESCRIPTOR_INIT(0x00, CDC_INT_EP, CDC_OUT_EP, CDC_IN_EP, CDC_MAX_MPS, 0x02)
};

static const uint8_t device_quality_descriptor[] = {
    ///////////////////////////////////////
    /// device qualifier descriptor
    ///////////////////////////////////////
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

static const char *string_descriptors[] = {
    (const char[]){ 0x09, 0x04 }, /* Langid */
    "Firmament",                  /* Manufacturer */
    "Firmament AutoPilot",         /* Product */
    // "FMT-12345678",                 /* Serial Number */
};

/* Serial Number */
static char serial_number[16] = { 0 };

static const uint8_t *device_descriptor_callback(uint8_t speed)
{
    return device_descriptor;
}

static const uint8_t *config_descriptor_callback(uint8_t speed)
{
    return config_descriptor;
}

static const uint8_t *device_quality_descriptor_callback(uint8_t speed)
{
    return device_quality_descriptor;
}

static const char *string_get_serialnumber(void)
{
    #define DEVICE_ID1 (0x1FFF7A10)
    #define DEVICE_ID2 (0x1FFF7A14)
    #define DEVICE_ID3 (0x1FFF7A18)

    uint32_t deviceserial0, deviceserial1, deviceserial2;

    deviceserial0 = *(uint32_t*)DEVICE_ID1;
    deviceserial1 = *(uint32_t*)DEVICE_ID2;
    deviceserial2 = *(uint32_t*)DEVICE_ID3;

    deviceserial0 += deviceserial2;

    rt_snprintf((char *)serial_number, sizeof(serial_number), "FMT-%04x%04x\0",
                    (uint16_t)deviceserial0, (uint16_t)deviceserial1);
    return (const char *)serial_number;
}

static const char *string_descriptor_callback(uint8_t speed, uint8_t index)
{
    if (index > 3) {
        return NULL;
    }
    if (index == 3) {
        return string_get_serialnumber();
    }
    return string_descriptors[index];
}

const struct usb_descriptor cdc_descriptor = {
    .device_descriptor_callback = device_descriptor_callback,
    .config_descriptor_callback = config_descriptor_callback,
    .device_quality_descriptor_callback = device_quality_descriptor_callback,
    .string_descriptor_callback = string_descriptor_callback
};
#else
/* global descriptor */
static const uint8_t cdc_descriptor[] = {
    USB_DEVICE_DESCRIPTOR_INIT(USB_2_0, 0xEF, 0x02, 0x01, USBD_VID, USBD_PID, 0x0100, 0x01),
    USB_CONFIG_DESCRIPTOR_INIT(USB_CONFIG_SIZE, 0x02, 0x01, USB_CONFIG_BUS_POWERED, USBD_MAX_POWER),
    CDC_ACM_DESCRIPTOR_INIT(0x00, CDC_INT_EP, CDC_OUT_EP, CDC_IN_EP, CDC_MAX_MPS, 0x02),
    ///////////////////////////////////////
    /// string0 descriptor
    ///////////////////////////////////////
    USB_LANGID_INIT(USBD_LANGID_STRING),
    ///////////////////////////////////////
    /// string1 descriptor
    /// "Firmament"
    ///////////////////////////////////////
    0x14,                       /* bLength */
    USB_DESCRIPTOR_TYPE_STRING, /* bDescriptorType */
    'F', 0x00,                  /* wcChar0 */
    'i', 0x00,                  /* wcChar1 */
    'r', 0x00,                  /* wcChar2 */
    'm', 0x00,                  /* wcChar3 */
    'a', 0x00,                  /* wcChar4 */
    'm', 0x00,                  /* wcChar5 */
    'e', 0x00,                  /* wcChar6 */
    'n', 0x00,                  /* wcChar7 */
    't', 0x00,                  /* wcChar8 */
    ///////////////////////////////////////
    /// string2 descriptor
    /// "Firmament AutoPilot"
    ///////////////////////////////////////
    0x28,                       /* bLength */
    USB_DESCRIPTOR_TYPE_STRING, /* bDescriptorType */
    'F', 0x00,                  /* wcChar0 */
    'i', 0x00,                  /* wcChar1 */
    'r', 0x00,                  /* wcChar2 */
    'm', 0x00,                  /* wcChar3 */
    'a', 0x00,                  /* wcChar4 */
    'm', 0x00,                  /* wcChar5 */
    'e', 0x00,                  /* wcChar6 */
    'n', 0x00,                  /* wcChar7 */
    't', 0x00,                  /* wcChar8 */
    ' ', 0x00,                  /* wcChar9 */
    'A', 0x00,                  /* wcChar10 */
    'u', 0x00,                  /* wcChar11 */
    't', 0x00,                  /* wcChar12 */
    'o', 0x00,                  /* wcChar13 */
    'P', 0x00,                  /* wcChar14 */
    'i', 0x00,                  /* wcChar15 */
    'l', 0x00,                  /* wcChar16 */
    'o', 0x00,                  /* wcChar17 */
    't', 0x00,                  /* wcChar18 */
    ///////////////////////////////////////
    /// string3 descriptor
    /// "FMT-12345678"
    ///////////////////////////////////////
    0x1A,                       /* bLength */
    USB_DESCRIPTOR_TYPE_STRING, /* bDescriptorType */
    'F', 0x00,                  /* wcChar0 */
    'M', 0x00,                  /* wcChar1 */
    'T', 0x00,                  /* wcChar2 */
    '-', 0x00,                  /* wcChar3 */
    '1', 0x00,                  /* wcChar4 */
    '2', 0x00,                  /* wcChar5 */
    '3', 0x00,                  /* wcChar6 */
    '4', 0x00,                  /* wcChar7 */
    '5', 0x00,                  /* wcChar8 */
    '6', 0x00,                  /* wcChar9 */
    '7', 0x00,                  /* wcChar10 */
    '8', 0x00,                  /* wcChar11 */
#ifdef CONFIG_USB_HS
    ///////////////////////////////////////
    /// device qualifier descriptor
    ///////////////////////////////////////
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
#endif
    0x00
};
#endif

#define MSG_MAX_MPS  CDC_MAX_MPS
static bool is_read_busy = false;
USB_NOCACHE_RAM_SECTION USB_MEM_ALIGNX uint8_t read_buffer[MSG_MAX_MPS];
USB_NOCACHE_RAM_SECTION USB_MEM_ALIGNX uint8_t write_buffer[MSG_MAX_MPS];

struct usb_xfer_msg {
    uint8_t *msg_buffer;        /** Data buffer */
    void *user_ptr;             /** User buf address */
    uint32_t total_nbytes;      /** User buffer length */
    uint32_t total_xfer_nbytes; /** The total number of bytes transferred */
    bool  is_unalign;           /** Is the user buffer misaligned */
};

static struct usb_xfer_msg cdc_tx_msg = {.msg_buffer = write_buffer};

static void usbd_event_handler(uint8_t busid, uint8_t event)
{
    switch (event) {
        case USBD_EVENT_RESET:
            break;
        case USBD_EVENT_CONNECTED:
            // hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_CONNECT);
            // console_printf("usb connected\r\n");
            break;
        case USBD_EVENT_DISCONNECTED:
            hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_DISCONNECT);
            console_printf("usb disconnected\r\n");
            break;
        case USBD_EVENT_RESUME:
            break;
        case USBD_EVENT_SUSPEND:
            break;
        case USBD_EVENT_CONFIGURED:
            /* setup first out ep read transfer */
            usbd_ep_start_read(busid, CDC_OUT_EP, read_buffer, MSG_MAX_MPS);
            hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_CONNECT);
            console_printf("usb connected\r\n");
            break;
        case USBD_EVENT_SET_REMOTE_WAKEUP:
            break;
        case USBD_EVENT_CLR_REMOTE_WAKEUP:
            break;

        default:
            break;
    }
}

void usbd_cdc_acm_bulk_out(uint8_t busid, uint8_t ep, uint32_t nbytes)
{
    uint32_t size;
    size = ringbuffer_put(usbd_dev.rx_rb, read_buffer, nbytes);
    if (size != nbytes) {
        console_printf("usb rx buffer full\r\n");
    }
    /* setup next out ep read transfer */
    if ((usbd_dev.rx_rb->size - ringbuffer_getlen(usbd_dev.rx_rb) - 1) >= MSG_MAX_MPS) {
        usbd_ep_start_read(busid, CDC_OUT_EP, read_buffer, MSG_MAX_MPS);
    } else {
        is_read_busy = true;
    }
    
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_RX);
}

void usbd_cdc_acm_bulk_in(uint8_t busid, uint8_t ep, uint32_t nbytes)
{
    cdc_tx_msg.total_xfer_nbytes += nbytes;
    if ((nbytes % usbd_get_ep_mps(busid, ep)) == 0 && nbytes) {
        /* send zlp */
        usbd_ep_start_write(busid, CDC_IN_EP, NULL, 0);
    } else {
        /* unalign transfer */
        if (cdc_tx_msg.is_unalign)
        {
            if (cdc_tx_msg.total_xfer_nbytes < cdc_tx_msg.total_nbytes)
            {
                int ret = 0;
                uint32_t bufsz = cdc_tx_msg.total_nbytes - cdc_tx_msg.total_xfer_nbytes;
                uint8_t *ptr = (uint8_t *)cdc_tx_msg.user_ptr + cdc_tx_msg.total_xfer_nbytes;
                if (bufsz > MSG_MAX_MPS)
                    bufsz = MSG_MAX_MPS;
                memcpy(cdc_tx_msg.msg_buffer, ptr, bufsz);
                /**
                 * @brief 启动下一次传输
                 */
                ret = usbd_ep_start_write(busid, CDC_IN_EP, cdc_tx_msg.msg_buffer, bufsz);
                if (ret)
                {
                    USB_LOG_ERR("cdc ep write err:%d\n", ret);
                }
                else
                {
                    return;
                }
            }
        }

        hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_TX_COMPLETE);
    }
}

/* endpoint call back */
struct usbd_endpoint cdc_out_ep = {
    .ep_addr = CDC_OUT_EP,
    .ep_cb = usbd_cdc_acm_bulk_out
};

struct usbd_endpoint cdc_in_ep = {
    .ep_addr = CDC_IN_EP,
    .ep_cb = usbd_cdc_acm_bulk_in
};

static struct usbd_interface intf0;
static struct usbd_interface intf1;

void cdc_acm_init(uint8_t busid, uintptr_t reg_base)
{
#ifdef CONFIG_USBDEV_ADVANCE_DESC
    usbd_desc_register(busid, &cdc_descriptor);
#else
    usbd_desc_register(busid, cdc_descriptor);
#endif
    usbd_add_interface(busid, usbd_cdc_acm_init_intf(busid, &intf0));
    usbd_add_interface(busid, usbd_cdc_acm_init_intf(busid, &intf1));
    usbd_add_endpoint(busid, &cdc_out_ep);
    usbd_add_endpoint(busid, &cdc_in_ep);
    usbd_initialize(busid, reg_base, usbd_event_handler);
}

static rt_size_t usbd_cdc_read(usbd_cdc_dev_t usbd, rt_off_t pos, void* buf, rt_size_t size)
{
    rt_size_t rb;

    RT_ASSERT(usbd->rx_rb != NULL);

    rb = ringbuffer_get(usbd->rx_rb, buf, size);
    if (is_read_busy && ((usbd_dev.rx_rb->size - ringbuffer_getlen(usbd_dev.rx_rb) - 1) >= MSG_MAX_MPS)) {
        is_read_busy = false;
        usbd_ep_start_read(0, CDC_OUT_EP, read_buffer, MSG_MAX_MPS);
    }
    return rb;
}

static rt_size_t usbd_cdc_write(usbd_cdc_dev_t usbd, rt_off_t pos, const void* buf, rt_size_t size)
{
    rt_err_t res = RT_EOK;
    rt_size_t tx_size = 0;
    uint32_t bufsz = 0;
    uint8_t *send_ptr = (uint8_t *)buf;
    cdc_tx_msg.user_ptr = (void *)buf;
    cdc_tx_msg.total_nbytes = size;
    cdc_tx_msg.total_xfer_nbytes = 0;

    if ((uintptr_t)buf & 0x3) { /** check if buffer is aligned to 4 bytes */
        cdc_tx_msg.is_unalign = true;
        if (cdc_tx_msg.total_nbytes > MSG_MAX_MPS)
        {
            bufsz = MSG_MAX_MPS;
        }
        else
        {
            bufsz = cdc_tx_msg.total_nbytes;
        }
        memcpy(cdc_tx_msg.msg_buffer, cdc_tx_msg.user_ptr, bufsz);
        send_ptr = (uint8_t *)cdc_tx_msg.msg_buffer;
    } else {
        cdc_tx_msg.is_unalign = false;
        send_ptr = (uint8_t *)buf;
        bufsz = size;
    }

    res = usbd_ep_start_write(0, CDC_IN_EP, send_ptr, bufsz);
    if (res)
    {
        USB_LOG_ERR("cdc ep write err:%d\n", res);
        tx_size = 0;
    }
    else
    {
        tx_size = size;
    }

    return tx_size;
}

struct usbd_cdc_ops usbd_ops = {
    .dev_init = NULL,
    .dev_read = usbd_cdc_read,
    .dev_write = usbd_cdc_write,
    .dev_control = NULL
};

rt_err_t drv_usb_cdc_init(void)
{
    rt_err_t err;
    usbd_dev.ops = &usbd_ops;
    usbd_dev.rx_rb = ringbuffer_create(1024);
    if (usbd_dev.rx_rb == NULL) {
        return FMT_ENOMEM;
    }

    err = hal_usbd_cdc_register(&usbd_dev, "usbd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX, RT_NULL);
    if (err != RT_EOK) {
        return err;
    }

    /* init usbd after devmq has been registered */
    cdc_acm_init(0, USB_OTG_FS_BASE_ADDR);

    return RT_EOK;
}