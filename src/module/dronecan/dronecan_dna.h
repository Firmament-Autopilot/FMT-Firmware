#ifndef DRONECAN_DNA_H__
#define DRONECAN_DNA_H__

#include "canard.h"
#include "dronecan.h"
#include "dronecan_drv.h"

#include "uavcan.protocol.dynamic_node_id.Allocation.h"

void dronecan_dynamic_allocation_id(const CanardInstance* ins, CanardRxTransfer* transfer, uint8_t master_id, uint8_t slave_id);

#endif