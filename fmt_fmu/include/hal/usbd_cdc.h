#ifndef __USBD_CDC_H__
#define __USBD_CDC_H__

#include "module/utils/ringbuffer.h"
#include "rtdef.h"
#include "string.h"
#include <firmament.h>

#define USBD_CDC_TX_BUFSIZE 1280
#define USBD_CDC_RX_BUFSIZE 1280

#define USBD_STATUS_DISCONNECT  0
#define USBD_STATUS_CONNECT     1
#define USBD_STATUS_TX_COMPLETE 2
#define USBD_STATUS_RX          3

/* usbd driver opeations */
// struct usbd_cdc_ops {
//     rt_err_t  (*usbd_cdc_dev_write)(rt_device_t device, rt_off_t pos, void* buf, rt_size_t size);
//     rt_size_t (*usbd_cdc_dev_read)(rt_device_t device, rt_off_t pos, void* buf, rt_size_t size);
//     rt_err_t  (*usbd_cdc_dev_init)(rt_device_t device);
//     rt_size_t  (*usbd_cdc_dev_ringbuf_put)(rt_device_t device,uint8_t* Buf, uint32_t *Len);
// };

struct usbd_cdc_dev {
    struct rt_device parent;
    struct usbd_cdc_ops* ops;
    ringbuffer* rx_rb;
    struct rt_completion tx_cplt;
    rt_mutex_t tx_lock;
    int status;
};
typedef struct usbd_cdc_dev* usbd_cdc_dev_t;

struct usbd_cdc_ops {
    rt_err_t (*dev_init)(usbd_cdc_dev_t usbd);
    rt_size_t (*dev_read)(usbd_cdc_dev_t usbd, rt_off_t pos, void* buf, rt_size_t size);
    rt_size_t (*dev_write)(usbd_cdc_dev_t usbd, rt_off_t pos, const void* buf, rt_size_t size);
    rt_err_t (*dev_control)(usbd_cdc_dev_t usbd, int cmd, void* arg);
};

rt_err_t hal_usbd_cdc_register(usbd_cdc_dev_t usbd, const char* name, rt_uint16_t flag, void* data);
void hal_usbd_cdc_notify_status(usbd_cdc_dev_t usbd, int status);

#endif