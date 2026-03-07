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

#include "usbd_core.h"
#include "usbd_cdc.h"
#include "driver/usb/mtp/usbd_mtp.h"
#include "driver/usb/usbd_cdc_mtp.h"
#include "hal/usb/usbd_cdc.h"

/*!< endpoint address */
#define MTP_IN_EP  0x81
#define MTP_OUT_EP 0x01
#define MTP_INT_EP 0x82

#define CDC_IN_EP  0x83
#define CDC_OUT_EP 0x03
#define CDC_INT_EP 0x84

#define USBD_VID           CONFIG_USBD_VID
#define USBD_PID           CONFIG_USBD_PID
#define USBD_MAX_POWER     500

/*!< config descriptor size */
#define USB_CONFIG_SIZE          (9 + CDC_ACM_DESCRIPTOR_LEN + MTP_DESCRIPTOR_LEN)
#define INTF_NUM 3 // mtp(1) + cdc(2)

#ifdef CONFIG_USB_HS
#define CDC_MAX_MPS 512
#define MTP_EP_MPS 512
#else
#define CDC_MAX_MPS 64
#define MTP_EP_MPS 64
#endif

static struct usbd_cdc_dev usbd_dev = { 0 };

#define WCID_VENDOR_CODE 0x01

__ALIGN_BEGIN const uint8_t WCID_StringDescriptor_MSOS[18] __ALIGN_END = {
    ///////////////////////////////////////
    /// MS OS string descriptor
    ///////////////////////////////////////
    0x12,                       /* bLength */
    USB_DESCRIPTOR_TYPE_STRING, /* bDescriptorType */
    /* MSFT100 */
    'M', 0x00, 'S', 0x00, 'F', 0x00, 'T', 0x00, /* wcChar_7 */
    '1', 0x00, '0', 0x00, '0', 0x00,            /* wcChar_7 */
    WCID_VENDOR_CODE,                           /* bVendorCode */
    0x00,                                       /* bReserved */
};

__ALIGN_BEGIN const uint8_t WINUSB_WCIDDescriptor[40] __ALIGN_END = {
    ///////////////////////////////////////
    /// WCID descriptor
    ///////////////////////////////////////
    0x28, 0x00, 0x00, 0x00,                   /* dwLength */
    0x00, 0x01,                               /* bcdVersion */
    0x04, 0x00,                               /* wIndex */
    0x01,                                     /* bCount */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* bReserved_7 */

    ///////////////////////////////////////
    /// WCID function descriptor
    ///////////////////////////////////////
    0x00, /* bFirstInterfaceNumber */
    0x01, /* bReserved */
    /* MTP */
    'M', 'T', 'P', 0x00, 0x00, 0x00, 0x00, 0x00, /* cCID_8 */
    /*  */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* cSubCID_8 */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,             /* bReserved_6 */
};

__ALIGN_BEGIN const uint8_t WINUSB_IF0_WCIDProperties[142] __ALIGN_END = {
    ///////////////////////////////////////
    /// WCID property descriptor
    ///////////////////////////////////////
    0x8e, 0x00, 0x00, 0x00, /* dwLength */
    0x00, 0x01,             /* bcdVersion */
    0x05, 0x00,             /* wIndex */
    0x01, 0x00,             /* wCount */

    ///////////////////////////////////////
    /// registry propter descriptor
    ///////////////////////////////////////
    0x84, 0x00, 0x00, 0x00, /* dwSize */
    0x01, 0x00, 0x00, 0x00, /* dwPropertyDataType */
    0x28, 0x00,             /* wPropertyNameLength */
    /* DeviceInterfaceGUID */
    'D', 0x00, 'e', 0x00, 'v', 0x00, 'i', 0x00,  /* wcName_20 */
    'c', 0x00, 'e', 0x00, 'I', 0x00, 'n', 0x00,  /* wcName_20 */
    't', 0x00, 'e', 0x00, 'r', 0x00, 'f', 0x00,  /* wcName_20 */
    'a', 0x00, 'c', 0x00, 'e', 0x00, 'G', 0x00,  /* wcName_20 */
    'U', 0x00, 'I', 0x00, 'D', 0x00, 0x00, 0x00, /* wcName_20 */
    0x4e, 0x00, 0x00, 0x00,                      /* dwPropertyDataLength */

    /* {1D4B2365-4749-48EA-B38A-7C6FDDDD7E26} */
    '{', 0x00, '1', 0x00, 'D', 0x00, '4', 0x00, /* wcData_39 */
    'B', 0x00, '2', 0x00, '3', 0x00, '6', 0x00, /* wcData_39 */
    '5', 0x00, '-', 0x00, '4', 0x00, '7', 0x00, /* wcData_39 */
    '4', 0x00, '9', 0x00, '-', 0x00, '4', 0x00, /* wcData_39 */
    '8', 0x00, 'E', 0x00, 'A', 0x00, '-', 0x00, /* wcData_39 */
    'B', 0x00, '3', 0x00, '8', 0x00, 'A', 0x00, /* wcData_39 */
    '-', 0x00, '7', 0x00, 'C', 0x00, '6', 0x00, /* wcData_39 */
    'F', 0x00, 'D', 0x00, 'D', 0x00, 'D', 0x00, /* wcData_39 */
    'D', 0x00, '7', 0x00, 'E', 0x00, '2', 0x00, /* wcData_39 */
    '6', 0x00, '}', 0x00, 0x00, 0x00,           /* wcData_39 */

};

const uint8_t bos_descriptor[] = {
    0x05, 0x0f, 0x16, 0x00, 0x02,
    0x07, 0x10, 0x02, 0x06, 0x00, 0x00, 0x00,
    0x0a, 0x10, 0x03, 0x00, 0x0f, 0x00, 0x01, 0x01, 0xf4, 0x01
};


static const uint8_t device_descriptor[] = {
    USB_DEVICE_DESCRIPTOR_INIT(USB_2_0, 0xEF, 0x02, 0x01, USBD_VID, USBD_PID, 0x0200, 0x01)
};

static const uint8_t config_descriptor_hs[] = {
    USB_CONFIG_DESCRIPTOR_INIT(USB_CONFIG_SIZE, INTF_NUM, 0x01, USB_CONFIG_BUS_POWERED, USBD_MAX_POWER),
    MTP_DESCRIPTOR_INIT(0x00, MTP_OUT_EP, MTP_IN_EP, MTP_INT_EP, USB_BULK_EP_MPS_HS, 0x02),
    CDC_ACM_DESCRIPTOR_INIT(0x01, CDC_INT_EP, CDC_OUT_EP, CDC_IN_EP, CDC_MAX_MPS, 0x02),
};

static const uint8_t config_descriptor_fs[] = {
    USB_CONFIG_DESCRIPTOR_INIT(USB_CONFIG_SIZE, INTF_NUM, 0x01, USB_CONFIG_BUS_POWERED, USBD_MAX_POWER),
    MTP_DESCRIPTOR_INIT(0x00, MTP_OUT_EP, MTP_IN_EP, MTP_INT_EP, USB_BULK_EP_MPS_FS, 0x02),
    CDC_ACM_DESCRIPTOR_INIT(0x01, CDC_INT_EP, CDC_OUT_EP, CDC_IN_EP, CDC_MAX_MPS, 0x02),
};

static const uint8_t device_quality_descriptor[] = {
    USB_DEVICE_QUALIFIER_DESCRIPTOR_INIT(USB_2_0, 0x00, 0x00, 0x00, 0x01),
};

static const uint8_t other_speed_config_descriptor_hs[] = {
    USB_OTHER_SPEED_CONFIG_DESCRIPTOR_INIT(USB_CONFIG_SIZE, INTF_NUM, 0x01, USB_CONFIG_BUS_POWERED, USBD_MAX_POWER),
    MTP_DESCRIPTOR_INIT(0x00, MTP_OUT_EP, MTP_IN_EP, MTP_INT_EP, USB_BULK_EP_MPS_FS, 0x02),
    CDC_ACM_DESCRIPTOR_INIT(0x01, CDC_INT_EP, CDC_OUT_EP, CDC_IN_EP, CDC_MAX_MPS, 0x02),
};

static const uint8_t other_speed_config_descriptor_fs[] = {
    USB_OTHER_SPEED_CONFIG_DESCRIPTOR_INIT(USB_CONFIG_SIZE, INTF_NUM, 0x01, USB_CONFIG_BUS_POWERED, USBD_MAX_POWER),
    MTP_DESCRIPTOR_INIT(0x00, MTP_OUT_EP, MTP_IN_EP, MTP_INT_EP, USB_BULK_EP_MPS_HS, 0x02),
    CDC_ACM_DESCRIPTOR_INIT(0x01, CDC_INT_EP, CDC_OUT_EP, CDC_IN_EP, CDC_MAX_MPS, 0x02),
};

static const char *string_descriptors[] = {
    (const char[]){ 0x09, 0x04 }, /* Langid */
    "Firmament",                  /* Manufacturer */
    "Firmament AutoPilot",         /* Product */
    "2025053000",                 /* Serial Number */
};

/* Serial Number */
static char serial_number[16] = { 0 };

static const uint8_t *device_descriptor_callback(uint8_t speed)
{
    (void)speed;

    return device_descriptor;
}

static const uint8_t *config_descriptor_callback(uint8_t speed)
{
    if (speed == USB_SPEED_HIGH) {
        return config_descriptor_hs;
    } else if (speed == USB_SPEED_FULL) {
        return config_descriptor_fs;
    } else {
        return NULL;
    }
}

static const uint8_t *device_quality_descriptor_callback(uint8_t speed)
{
    (void)speed;

    return device_quality_descriptor;
}

static const uint8_t *other_speed_config_descriptor_callback(uint8_t speed)
{
    if (speed == USB_SPEED_HIGH) {
        return other_speed_config_descriptor_hs;
    } else if (speed == USB_SPEED_FULL) {
        return other_speed_config_descriptor_fs;
    } else {
        return NULL;
    }
}

static const char *string_get_serialnumber(void)
{
    uint32_t deviceserial0, deviceserial1, deviceserial2;

    deviceserial0 = *(uint32_t*)UID_BASE;
    deviceserial1 = *(uint32_t*)(UID_BASE + 4);
    deviceserial2 = *(uint32_t*)(UID_BASE + 8);

    deviceserial0 += deviceserial2;

    rt_snprintf((char *)serial_number, sizeof(serial_number), "FMT-%04x%04x\0",
                    (uint16_t)deviceserial0, (uint16_t)deviceserial1);
    return (const char *)serial_number;
}

static const char *string_descriptor_callback(uint8_t speed, uint8_t index)
{
    (void)speed;

    if (index >= (sizeof(string_descriptors) / sizeof(char *))) {
        return NULL;
    }
    if (index == 3) { // Serial Number
        return string_get_serialnumber();
    }
    return string_descriptors[index];
}

const uint8_t *WINUSB_IFx_WCIDProperties[] = {
    WINUSB_IF0_WCIDProperties,
};

struct usb_msosv1_descriptor msosv1_desc = {
    .string = WCID_StringDescriptor_MSOS,
    .vendor_code = WCID_VENDOR_CODE,
    .compat_id = WINUSB_WCIDDescriptor,
    .comp_id_property = WINUSB_IFx_WCIDProperties,
};

const struct usb_bos_descriptor bos_desc = {
    .string = bos_descriptor,
    .string_len = 22
};

const struct usb_descriptor fmt_descriptor = {
    .device_descriptor_callback = device_descriptor_callback,
    .config_descriptor_callback = config_descriptor_callback,
    .device_quality_descriptor_callback = device_quality_descriptor_callback,
    .other_speed_descriptor_callback = other_speed_config_descriptor_callback,
    .string_descriptor_callback = string_descriptor_callback,
    .bos_descriptor = &bos_desc,
    .msosv1_descriptor = &msosv1_desc,
};

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
                 * @brief started next transmit
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

static struct usbd_interface intf2;

void mtp_init(uint8_t busid, uint32_t reg_base)
{
    usbd_desc_register(busid, &fmt_descriptor);
    usbd_add_interface(busid, usbd_cdc_acm_init_intf(busid, &intf0));
    usbd_add_interface(busid, usbd_cdc_acm_init_intf(busid, &intf1));
    usbd_add_endpoint(busid, &cdc_out_ep);
    usbd_add_endpoint(busid, &cdc_in_ep);
    usbd_add_interface(busid, usbd_mtp_init_intf(busid, &intf2, MTP_OUT_EP, MTP_IN_EP, MTP_INT_EP));
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
    err = hal_usbd_cdc_register(&usbd_dev, "usbd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX, RT_NULL);
    if (err != RT_EOK) {
        return err;
    }
    mtp_init(0, USB_OTG_FS_BASE_ADDR);
    return RT_EOK;
}

