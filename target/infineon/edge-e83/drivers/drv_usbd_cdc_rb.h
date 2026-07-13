#ifndef __DRV_USBD_CDC_RB_H__
#define __DRV_USBD_CDC_RB_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t* buffer;
    uint32_t size;
    uint32_t head;
    uint32_t tail;
    uint32_t count;
} drv_usbd_cdc_rb_t;

rt_err_t drv_usbd_cdc_rb_init(drv_usbd_cdc_rb_t* rb, uint8_t* buffer, uint32_t size);
uint32_t drv_usbd_cdc_rb_put(drv_usbd_cdc_rb_t* rb, const uint8_t* data, uint32_t len);
uint32_t drv_usbd_cdc_rb_get(drv_usbd_cdc_rb_t* rb, uint8_t* data, uint32_t len);
uint32_t drv_usbd_cdc_rb_len(drv_usbd_cdc_rb_t* rb);
void drv_usbd_cdc_rb_flush(drv_usbd_cdc_rb_t* rb);

#ifdef __cplusplus
}
#endif

#endif
