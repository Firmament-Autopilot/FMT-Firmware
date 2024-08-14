#ifndef __SERVO_HIMARK_H__
#define __SERVO_HIMARK_H__

#include <firmament.h>

#include "hal/can/can.h"

#include "com.himark.servo.ServoInfo.c"

void handle_servo_info(CanardRxTransfer* transfer);

rt_err_t servo_himark_init(const char* dronecan_device_name, const char* servo_device_name);

#endif