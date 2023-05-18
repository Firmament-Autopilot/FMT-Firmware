#ifndef DRONECAN_DNA_H__
#define DRONECAN_DNA_H__

#include "canard.h"
#include "dronecan.h"
#include "dronecan_drv.h"

#include "uavcan.protocol.dynamic_node_id.Allocation.h"
#include "uavcan.protocol.dynamic_node_id.server.Entry.h"

void dronecan_dynamic_allocation_id(CanardInstance* ins, CanardRxTransfer* transfer);

#endif