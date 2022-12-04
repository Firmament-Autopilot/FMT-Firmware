#ifndef __DRONECAN_H__
#define __DRONECAN_H__
#include <firmament.h>

void processTxRxOnce(int32_t timeout_msec);
fmt_err_t dronecan_init(void);

#endif