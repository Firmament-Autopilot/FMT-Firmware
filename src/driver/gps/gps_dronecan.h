#ifndef __GPS_DRONECAN_H__
#define __GPS_DRONECAN_H__

#include <firmament.h>

#include "hal/gps/gps.h"

#include "uavcan.equipment.gnss.Auxiliary.h"
#include "uavcan.equipment.gnss.Fix2.h"

void handle_gnss_Fix2(CanardRxTransfer* transfer);
void handle_gnss_Auxiliary(CanardRxTransfer* transfer);

rt_err_t gps_dronecan_init(const char* dronecan_device_name, const char* gps_device_name);

#endif