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
#include "uavcan.protocol.debug.KeyValue.h"
#include "uavcan.protocol.dynamic_node_id.Allocation.h"
#include "uavcan.protocol.param.GetSet_req.h"
#include "uavcan.protocol.param.GetSet_res.h"

#define HAL_MAX_FDCAN_NUM 1

#ifndef HAL_CAN_POOL_SIZE
    #if HAL_CANFD_SUPPORTED
        #define HAL_CAN_POOL_SIZE 16000
    #else
        #define HAL_CAN_POOL_SIZE 2048
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

#define SALVE_NODE_ID 125

static CanardInstance g_canard;
static uint8_t g_canard_memory_pool[HAL_CAN_POOL_SIZE];

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

uint8_t flag_alloc = 0;

struct uavcan_protocol_param_GetSetResponse uavcan_protocol_param_GetSetResponse_msg;
struct uavcan_protocol_NodeStatus uavcan_protocol_NodeStatus_msg;

static void onTransferReceived(CanardInstance* ins,
                               CanardRxTransfer* transfer)
{
    switch (transfer->data_type_id) {
    case UAVCAN_PROTOCOL_PARAM_GETSET_RESPONSE_ID:
        // uavcan_protocol_param_GetSetResponse_decode(transfer, &uavcan_protocol_param_GetSetResponse_msg);
        // printf("GETSET_RESPONSE_ID tag:%d,value=%d,name=%d\n",
        //        uavcan_protocol_param_GetSetResponse_msg.value.union_tag,
        //        uavcan_protocol_param_GetSetResponse_msg.value.integer_value,
        //        uavcan_protocol_param_GetSetResponse_msg.name.len);
        break;

    case UAVCAN_PROTOCOL_NODESTATUS_ID:
        printf("onTransferReceived UAVCAN_PROTOCOL_NODESTATUS_ID\n");
        uavcan_protocol_NodeStatus_decode(transfer, &uavcan_protocol_NodeStatus_msg);
        // printf("mode %d\n", uavcan_protocol_NodeStatus_msg.mode);
        break;

    case UAVCAN_EQUIPMENT_GNSS_FIX2_ID:
        printf("onTransferReceived UAVCAN_EQUIPMENT_GNSS_FIX2_ID\n");
        break;

    case UAVCAN_PROTOCOL_DEBUG_KEYVALUE_ID:
        printf("onTransferReceived UAVCAN_PROTOCOL_DEBUG_KEYVALUE_ID\n");
        break;
    }
}

static bool shouldAcceptTransfer(const CanardInstance* ins,
                                 uint64_t* out_data_type_signature,
                                 uint16_t data_type_id,
                                 CanardTransferType transfer_type,
                                 uint8_t source_node_id)
{
    (void)source_node_id;

    switch (data_type_id) {
    case UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID:
        // printf("UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID\n");
        *out_data_type_signature = UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE;
        return true;

    case UAVCAN_PROTOCOL_NODESTATUS_ID:
        // printf("UAVCAN_PROTOCOL_NODESTATUS_ID,source_node_id=%d\n", source_node_id);
        *out_data_type_signature = UAVCAN_PROTOCOL_NODESTATUS_SIGNATURE;
        return true;

    case UAVCAN_EQUIPMENT_GNSS_FIX2_ID:
        // printf("UAVCAN_EQUIPMENT_GNSS_FIX2_ID\n");
        *out_data_type_signature = UAVCAN_EQUIPMENT_GNSS_FIX2_SIGNATURE;
        return true;

    case UAVCAN_PROTOCOL_DEBUG_KEYVALUE_ID:
        // printf("UAVCAN_PROTOCOL_DEBUG_KEYVALUE_ID\n");
        *out_data_type_signature = UAVCAN_PROTOCOL_DEBUG_KEYVALUE_SIGNATURE;
        return true;
    }

    return false;
}

void setRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    // struct uavcan_equipment_indication_LightsCommand LightsCommand_msg;
    // uint8_t buffer[UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_MAX_SIZE];

    // LightsCommand_msg.commands.len = 1;
    // LightsCommand_msg.commands.data[0].color.red = red >> 3;
    // LightsCommand_msg.commands.data[0].color.green = (green << 1) >> 3;
    // LightsCommand_msg.commands.data[0].color.blue = blue >> 3;

    // uint16_t total_size = uavcan_equipment_indication_LightsCommand_encode(&LightsCommand_msg, buffer);

    // int16_t resp_res = canardBroadcast(&g_canard,
    //                                    UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_SIGNATURE,
    //                                    UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_ID,
    //                                    &PreferredNodeID,
    //                                    CANARD_TRANSFER_PRIORITY_MEDIUM,
    //                                    buffer,
    //                                    (uint16_t)total_size);
}

/**
 * Transmits all frames from the TX queue, receives up to one frame.
 */
static void sendCanard(void)
{
    for (const CanardCANFrame* txf = NULL; (txf = canardPeekTxQueue(&g_canard)) != NULL;) {
        const int16_t tx_res = dronecanTransmit(fdcan_dev[0], txf);
        if (tx_res < 0) // Failure - drop the frame and report
        {
            ;
        } else if (tx_res > 0) // Success - just drop the frame
        {
            canardPopTxQueue(&g_canard);
        }
    }
}

void receiveCanard(void)
{
    // Receiving
    uint64_t timestamp = systime_now_us();

    CanardCANFrame rx_frame;

    int16_t rx_res = fdCANReceive(0, &rx_frame);

    // printf("rx_frame=%d\n", rx_frame.data_len);

    // int16_t rx_res = dronecanReceive(fdcan_dev[0], &rx_frame);
    if (rx_res > 0) {
        canardHandleRxFrame(&g_canard, &rx_frame, timestamp);
    }
}

static uint8_t node_msg_buffer[UAVCAN_PROTOCOL_NODESTATUS_MAX_SIZE];
struct uavcan_protocol_NodeStatus NodeStatus_msg;
static void spinCanard(void)
{
    static uint32_t spin_time = 0;
    if (systime_now_ms() < spin_time + 1000) {
        return;
    } // rate limiting

    spin_time = systime_now_ms();

    NodeStatus_msg.health = UAVCAN_PROTOCOL_NODESTATUS_HEALTH_OK;
    NodeStatus_msg.mode = UAVCAN_PROTOCOL_NODESTATUS_MODE_OPERATIONAL;
    NodeStatus_msg.uptime_sec = systime_now_ms() / 1000;
    uint16_t total_size = uavcan_protocol_NodeStatus_encode(&NodeStatus_msg, node_msg_buffer);

    canardBroadcast(&g_canard,
                    UAVCAN_PROTOCOL_NODESTATUS_SIGNATURE,
                    UAVCAN_PROTOCOL_NODESTATUS_ID,
                    &PreferredNodeID,
                    CANARD_TRANSFER_PRIORITY_LOW,
                    node_msg_buffer,
                    (uint16_t)total_size);
}

fmt_err_t dronecan_init(void)
{
    fdcan_dev[0] = rt_device_find("fdcan1");
    RT_ASSERT(fdcan_dev[0] != NULL);

    RT_CHECK(rt_device_open(fdcan_dev[0], RT_DEVICE_OFLAG_RDWR));

    /////////////////////////////////////////////////////////
    canardInit(&g_canard,
               g_canard_memory_pool,
               sizeof(g_canard_memory_pool),
               onTransferReceived,
               shouldAcceptTransfer,
               NULL);

    canardSetLocalNodeID(&g_canard, PreferredNodeID);

    return FMT_EOK;
}

void dronecan_loop(void)
{
}