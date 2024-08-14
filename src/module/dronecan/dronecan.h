#ifndef __DRONECAN_H__
#define __DRONECAN_H__
#include <firmament.h>
#include <rtconfig.h>

#include "com.himark.servo.ServoInfo.h"

typedef struct {
    uint32_t timestamp_ms;
    struct com_himark_servo_ServoInfo srv_data;
} Himark_Back_t;

void receiveCanard(void);
void sendCanard(void);

fmt_err_t dronecan_init(void);
void dronecan_loop(uint32_t time_ms);

// void makeLightsRGB(uint8_t red, uint8_t green, uint8_t blue);
void makeNodeStatus(uint32_t time_ms);

#endif