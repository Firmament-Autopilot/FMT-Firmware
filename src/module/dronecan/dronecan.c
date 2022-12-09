#include "dronecan.h"
#include "canard.h"
#include "dronecan_dna.h"
#include "dronecan_drv.h"

#include "ardupilot.gnss.Status.h"
#include "uavcan.equipment.ahrs.MagneticFieldStrength.h"
#include "uavcan.equipment.gnss.Auxiliary.h"
#include "uavcan.equipment.gnss.Fix.h"
#include "uavcan.equipment.gnss.Fix2.h"
#include "uavcan.equipment.indication.LightsCommand.h"
#include "uavcan.protocol.GetNodeInfo.h"
#include "uavcan.protocol.NodeStatus.h"
#include "uavcan.protocol.dynamic_node_id.Allocation.h"

#define HAL_MAX_FDCAN_NUM 2

#ifndef HAL_CAN_POOL_SIZE
    #if HAL_CANFD_SUPPORTED
        #define HAL_CAN_POOL_SIZE 16000
    #else
        #define HAL_CAN_POOL_SIZE 1024
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

#define HAL_CAN_DEFAULT_NODE_ID 10
#ifndef HAL_CAN_DEFAULT_NODE_ID
    #define HAL_CAN_DEFAULT_NODE_ID CANARD_BROADCAST_NODE_ID
#endif

uint8_t PreferredNodeID = HAL_CAN_DEFAULT_NODE_ID;

#define SALVE_NODE_ID 100

static struct dronecan_protocol_t {
    CanardInstance canard;
    uint8_t canard_memory_pool[HAL_CAN_POOL_SIZE];

    uint32_t send_next_node_id_allocation_request_at_ms; ///< When the next node ID allocation request should be sent
    uint8_t node_id_allocation_unique_id_offset;         ///< Depends on the stage of the next request
    uint8_t tx_fail_count;
    uint8_t dna_interface;
} dronecan;

static rt_device_t fdcan_dev[HAL_MAX_FDCAN_NUM];

// static float getRandomFloat(void)
// {
//     static bool initialized = false;
//     if (!initialized) // This is not thread safe, but a race condition here is not harmful.
//     {
//         initialized = true;
//         srand((uint32_t)time(NULL));
//     }
//     // coverity[dont_call]
//     return (float)rand() / (float)RAND_MAX;
// }

static void onTransferReceived(CanardInstance* ins,
                               CanardRxTransfer* transfer)
{
    if (transfer->transfer_type == CanardTransferTypeBroadcast) {
        switch (transfer->data_type_id) {
        case UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID:
            dronecan_dynamic_allocation_id(ins, transfer, PreferredNodeID, SALVE_NODE_ID);

        default:
            break;
        }
    }
}

static bool shouldAcceptTransfer(const CanardInstance* ins,
                                 uint64_t* out_data_type_signature,
                                 uint16_t data_type_id,
                                 CanardTransferType transfer_type,
                                 uint8_t source_node_id)
{
    (void)source_node_id;

    if (transfer_type == CanardTransferTypeBroadcast) {
        switch (data_type_id) {
        case UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID:
            printf("UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID\n");
            *out_data_type_signature = UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE;

            return true;
        case UAVCAN_PROTOCOL_NODESTATUS_ID:
            printf("UAVCAN_PROTOCOL_NODESTATUS_ID,source_node_id=%d\n", source_node_id);
            *out_data_type_signature = UAVCAN_PROTOCOL_NODESTATUS_SIGNATURE;
            return true;

        case UAVCAN_EQUIPMENT_GNSS_FIX2_ID:
            // printf("UAVCAN_EQUIPMENT_GNSS_FIX2_ID\n");
            *out_data_type_signature = UAVCAN_EQUIPMENT_GNSS_FIX2_SIGNATURE;
            return true;

        case ARDUPILOT_GNSS_STATUS_ID:
            printf("ARDUPILOT_GNSS_STATUS_ID\n");
            *out_data_type_signature = ARDUPILOT_GNSS_STATUS_SIGNATURE;
            return true;

        case UAVCAN_EQUIPMENT_GNSS_AUXILIARY_ID:
            // printf("UAVCAN_EQUIPMENT_GNSS_AUXILIARY_ID\n");
            *out_data_type_signature = UAVCAN_EQUIPMENT_GNSS_AUXILIARY_SIGNATURE;
            return true;

        case UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH_ID:
            // printf("UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH_ID\n");
            *out_data_type_signature = UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH_SIGNATURE;
            return true;

        default:
            break;
        }
    } else if (transfer_type == CanardTransferTypeResponse) {
        switch (data_type_id) {
        case UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_ID:
            printf("UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_ID\n");
            *out_data_type_signature = UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_SIGNATURE;
            return true;
        }
    }
    return false;
}

/**
 * Transmits all frames from the TX queue, receives up to one frame.
 */
void processTxRxOnce(int32_t timeout_msec)
{
    for (const CanardCANFrame* txf = NULL; (txf = canardPeekTxQueue(&dronecan.canard)) != NULL;) {
        const int16_t tx_res = dronecanTransmit(fdcan_dev[0], txf);
        if (tx_res < 0) // Failure - drop the frame and report
        {
            canardPopTxQueue(&dronecan.canard);
        } else if (tx_res > 0) // Success - just drop the frame
        {
            canardPopTxQueue(&dronecan.canard);
        } else // Timeout - just exit and try again later
        {
            break;
        }
    }

    // Receiving
    CanardCANFrame rx_frame;
    uint64_t timestamp = systime_now_us();

    int16_t rx_res = dronecanReceive(fdcan_dev[0], &rx_frame);

    if (rx_res < 0) // Failure - report
    {
        ;
    } else if (rx_res > 0) // Success - process the frame
    {
        rx_res = canardHandleRxFrame(&dronecan.canard, &rx_frame, timestamp);
    } else {
        ; // Timeout - nothing to do
    }
}

void setRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    struct uavcan_equipment_indication_LightsCommand LightsCommand_msg;
    uint8_t buffer[UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_MAX_SIZE];

    LightsCommand_msg.commands.len = 1;
    LightsCommand_msg.commands.data[0].color.red = red >> 3;
    LightsCommand_msg.commands.data[0].color.green = (green << 1) >> 3;
    LightsCommand_msg.commands.data[0].color.blue = blue >> 3;

    uint16_t total_size = uavcan_equipment_indication_LightsCommand_encode(&LightsCommand_msg, buffer);

    int16_t resp_res = canardBroadcast(&dronecan.canard,
                                       UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_SIGNATURE,
                                       UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_ID,
                                       &PreferredNodeID,
                                       CANARD_TRANSFER_PRIORITY_MEDIUM,
                                       buffer,
                                       (uint16_t)total_size);
}

fmt_err_t dronecan_init(void)
{
    fdcan_dev[0] = rt_device_find("fdcan1");
    RT_ASSERT(fdcan_dev[0] != NULL);

    // fdcan_dev[1] = rt_device_find("fdcan2");
    // RT_ASSERT(fdcan_dev[1] != NULL);

    RT_CHECK(rt_device_open(fdcan_dev[0], RT_DEVICE_OFLAG_RDWR));
    // RT_CHECK(rt_device_open(fdcan_dev[1], RT_DEVICE_OFLAG_RDWR));

    /////////////////////////////////////////////////////////
    canardInit(&dronecan.canard,
               (uint8_t*)dronecan.canard_memory_pool,
               sizeof(dronecan.canard_memory_pool),
               onTransferReceived,
               shouldAcceptTransfer,
               NULL);

    canardSetLocalNodeID(&dronecan.canard, PreferredNodeID);

    return FMT_EOK;
}