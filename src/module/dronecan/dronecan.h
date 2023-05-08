#ifndef __DRONECAN_H__
#define __DRONECAN_H__
#include <firmament.h>

fmt_err_t dronecan_init(void);

void dronecan_loop(void);
void receiveCanard(void);
void sendCanard(void);
void makeLightsRGB(uint8_t red, uint8_t green, uint8_t blue);
void spinCanard(void);
#endif