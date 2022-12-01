#ifndef __DRV_FDCAN_H__
#define __DRV_FDCAN_H__

#include "board.h"
#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

rt_err_t drv_fdcan_init(void);

int fdcan_send(void);
uint8_t fdcan_recv(uint8_t* buf);

#ifdef __cplusplus
}
#endif

#endif