#ifndef DRONECAN_DRV_H__
#define DRONECAN_DRV_H__

#include "canard.h"
#include "dronecan.h"
#include "hal/can/can.h"
#include <firmament.h>

rt_inline int16_t dronecanTransmit(rt_device_t dronecan_dev, const CanardCANFrame* frame)
{
    return rt_device_write(dronecan_dev, 0, frame, sizeof(CanardCANFrame));
}

rt_inline int16_t dronecanReceive(rt_device_t dronecan_dev, CanardCANFrame* out_frame)
{
    return rt_device_read(dronecan_dev, 0, out_frame, sizeof(CanardCANFrame));
}

#endif