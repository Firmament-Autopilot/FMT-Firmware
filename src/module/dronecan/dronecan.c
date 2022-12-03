#include "dronecan.h"

#include "canard.h"

#include "uavcan.protocol.NodeStatus.h"
#include "uavcan.protocol.dynamic_node_id.Allocation.h"

#ifndef HAL_CAN_POOL_SIZE
    #if HAL_CANFD_SUPPORTED
        #define HAL_CAN_POOL_SIZE 16000
    #else
        #define HAL_CAN_POOL_SIZE 4000
    #endif
#endif

#ifndef HAL_PERIPH_LOOP_DELAY_US
    // delay between can loop updates. This needs to be longer on F4
    #if defined(STM32H7)
        #define HAL_PERIPH_LOOP_DELAY_US 64
    #else
        #define HAL_PERIPH_LOOP_DELAY_US 1024
    #endif
#endif

#ifndef HAL_CAN_DEFAULT_NODE_ID
    #define HAL_CAN_DEFAULT_NODE_ID CANARD_BROADCAST_NODE_ID
#endif
uint8_t PreferredNodeID = HAL_CAN_DEFAULT_NODE_ID;

static struct dronecan_protocol_t {
    CanardInstance canard;
    uint32_t canard_memory_pool[HAL_CAN_POOL_SIZE / sizeof(uint32_t)];

    uint32_t send_next_node_id_allocation_request_at_ms; ///< When the next node ID allocation request should be sent
    uint8_t node_id_allocation_unique_id_offset;         ///< Depends on the stage of the next request
    uint8_t tx_fail_count;
    uint8_t dna_interface;
} dronecan;

static void onTransferReceived(CanardInstance* ins,
                               CanardRxTransfer* transfer)
{
}

static bool shouldAcceptTransfer(const CanardInstance* ins,
                                 uint64_t* out_data_type_signature,
                                 uint16_t data_type_id,
                                 CanardTransferType transfer_type,
                                 uint8_t source_node_id)
{
}

static int dronecan_init()
{
    canardInit(&dronecan.canard, (uint8_t*)dronecan.canard_memory_pool, sizeof(dronecan.canard_memory_pool), onTransferReceived, shouldAcceptTransfer, NULL);

    if (PreferredNodeID != CANARD_BROADCAST_NODE_ID) {
        canardSetLocalNodeID(&dronecan.canard, PreferredNodeID);
    }
}