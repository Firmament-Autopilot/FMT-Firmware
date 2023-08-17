#ifndef __USR_USB__
#define __USR_USB__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hal_sram_sky.h"

void usr_usb0_interface(void);
uint32_t get_usb_recv_size0(void);
uint32_t get_usb_recv_size1(void);
uint32_t usb_bypass_write(void *pbuf, uint32_t data_len);
uint32_t usb_bypass_read(void *pbuf, uint32_t max_len);

#ifdef __cplusplus
}
#endif

#endif

