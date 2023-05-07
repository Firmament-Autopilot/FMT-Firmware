#ifndef __DRONECAN_H__
#define __DRONECAN_H__
#include <firmament.h>

fmt_err_t dronecan_init(void);

void dronecan_loop(void);
void receiveCanard(void);

#endif