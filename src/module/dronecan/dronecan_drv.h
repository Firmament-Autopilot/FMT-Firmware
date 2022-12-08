#ifndef DRONECAN_DRV_H__
#define DRONECAN_DRV_H__

#include "canard.h"
#include "dronecan.h"
#include "hal/can/can.h"
#include <firmament.h>

int16_t dronecanTransmit(rt_device_t dronecan_dev, const CanardCANFrame* frame);
int16_t dronecanReceive(rt_device_t dronecan_dev, CanardCANFrame* out_frame);

#endif