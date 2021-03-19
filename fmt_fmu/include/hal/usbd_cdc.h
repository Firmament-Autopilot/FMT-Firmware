#ifndef __USBD_CDC_H__
#define __USBD_CDC_H__

#include "firmament.h"
#include "string.h"
#include "module/utils/ringbuffer.h"
#include "rtdef.h"

#define USBD_CDC_TX_BUFSIZE 1280
#define USBD_CDC_RX_BUFSIZE 1280

/* usbd driver opeations */
struct usbd_cdc_ops {
    rt_err_t  (*usbd_cdc_dev_write)(rt_device_t device, rt_off_t pos, void* buf, rt_size_t size);
    rt_size_t (*usbd_cdc_dev_read)(rt_device_t device, rt_off_t pos, void* buf, rt_size_t size);
    rt_err_t  (*usbd_cdc_dev_init)(rt_device_t device);
    rt_size_t  (*usbd_cdc_dev_ringbuf_put)(rt_device_t device,uint8_t* Buf, uint32_t *Len);
};
typedef struct usbd_cdc_ops* usbd_cdc_ops_t;

struct usbd_cdc_dev {
    struct rt_device parent;
    usbd_cdc_ops_t   ops;
    ringbuffer*      rx_ringbuf;
    __IO uint32_t*   tx_stutus;
    __IO uint32_t*   rx_status;
    uint8_t*         connect_status;
};
typedef struct usbd_cdc_dev* usbd_cdc_dev_t;

rt_err_t hal_usbd_cdc_register(usbd_cdc_dev_t device, const char* name, rt_uint16_t flag, void* data);

#endif