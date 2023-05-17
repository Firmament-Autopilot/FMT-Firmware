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

#include "canard_stm32H7.h"

#define HAL_MAX_FDCAN_NUM 1

#ifndef HAL_CAN_POOL_SIZE
    #if HAL_CANFD_SUPPORTED
        #define HAL_CAN_POOL_SIZE 16000
    #else
        #define HAL_CAN_POOL_SIZE 4096
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

/*
 * Library instance.
 * In simple applications it makes sense to make it static, but it is not necessary.
 */
static CanardInstance g_canard;            ///< The library instance
static uint8_t g_canard_memory_pool[2048]; ///< Arena for memory allocation, used by the library

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
    if (transfer->data_type_id == UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID
        && transfer->source_node_id == CANARD_BROADCAST_NODE_ID) {
        dronecan_dynamic_allocation_id(&g_canard, transfer, PreferredNodeID, SALVE_NODE_ID);
    }

    switch (transfer->data_type_id) {
    case UAVCAN_PROTOCOL_PARAM_GETSET_RESPONSE_ID:
        // uavcan_protocol_param_GetSetResponse_decode(transfer, &uavcan_protocol_param_GetSetResponse_msg);
        // printf("GETSET_RESPONSE_ID tag:%d,value=%d,name=%d\n",
        //        uavcan_protocol_param_GetSetResponse_msg.value.union_tag,
        //        uavcan_protocol_param_GetSetResponse_msg.value.integer_value,
        //        uavcan_protocol_param_GetSetResponse_msg.name.len);
        break;

    case UAVCAN_PROTOCOL_NODESTATUS_ID:
        // printf("NODESTATUS\n");
        uavcan_protocol_NodeStatus_decode(transfer, &uavcan_protocol_NodeStatus_msg);
        // printf("mode %d\n", uavcan_protocol_NodeStatus_msg.mode);
        break;

    case UAVCAN_EQUIPMENT_GNSS_FIX2_ID:
        printf("GNSS_FIX2\n");
        break;

    case UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH_ID:
        // printf("MAGNETICFIELDSTRENGTH\n");
        break;

    case UAVCAN_PROTOCOL_DEBUG_KEYVALUE_ID:
        // printf("onTransferReceived UAVCAN_PROTOCOL_DEBUG_KEYVALUE_ID\n");
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

    case UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH_ID:
        // printf("UAVCAN_EQUIPMENT_GNSS_FIX2_ID\n");
        *out_data_type_signature = UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH_SIGNATURE;
        return true;

    case UAVCAN_PROTOCOL_DEBUG_KEYVALUE_ID:
        // printf("UAVCAN_PROTOCOL_DEBUG_KEYVALUE_ID\n");
        *out_data_type_signature = UAVCAN_PROTOCOL_DEBUG_KEYVALUE_SIGNATURE;
        return true;
    }

    return false;
}

void makeLightsRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    static struct uavcan_equipment_indication_LightsCommand LightsCommand_msg;
    static uint8_t buffer[UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_MAX_SIZE];

    LightsCommand_msg.commands.len = 1;
    LightsCommand_msg.commands.data[0].color.red = red >> 3;
    LightsCommand_msg.commands.data[0].color.green = (green << 1) >> 3;
    LightsCommand_msg.commands.data[0].color.blue = blue >> 3;

    uint32_t total_size = uavcan_equipment_indication_LightsCommand_encode(&LightsCommand_msg, buffer);

    static uint8_t transfer_id; // Note that the transfer ID variable MUST BE STATIC (or heap-allocated)!

    canardBroadcast(&g_canard,
                    UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_SIGNATURE,
                    UAVCAN_EQUIPMENT_INDICATION_LIGHTSCOMMAND_ID,
                    &transfer_id,
                    CANARD_TRANSFER_PRIORITY_MEDIUM,
                    buffer,
                    (int16_t)total_size);
}

void makeNodeStatus(uint32_t time_ms)
{
    static uint8_t node_msg_buffer[UAVCAN_PROTOCOL_NODESTATUS_MAX_SIZE];
    static struct uavcan_protocol_NodeStatus NodeStatus_msg;

    NodeStatus_msg.health = UAVCAN_PROTOCOL_NODESTATUS_HEALTH_OK;
    NodeStatus_msg.mode = UAVCAN_PROTOCOL_NODESTATUS_MODE_OPERATIONAL;
    NodeStatus_msg.uptime_sec = time_ms / 1000;
    uint16_t total_size = uavcan_protocol_NodeStatus_encode(&NodeStatus_msg, node_msg_buffer);

    static uint8_t transfer_id; // Note that the transfer ID variable MUST BE STATIC (or heap-allocated)!

    canardBroadcast(&g_canard,
                    UAVCAN_PROTOCOL_NODESTATUS_SIGNATURE,
                    UAVCAN_PROTOCOL_NODESTATUS_ID,
                    &transfer_id,
                    CANARD_TRANSFER_PRIORITY_MEDIUM,
                    node_msg_buffer,
                    (uint16_t)total_size);
}

void receiveCanard(void)
{
    // Receiving
    uint64_t timestamp = systime_now_us();

    CanardCANFrame rx_frame;

    int16_t rx_res = dronecanReceive(fdcan_dev[0], &rx_frame);
    if (rx_res > 0) {
        canardHandleRxFrame(&g_canard, &rx_frame, timestamp);
    }
}

/**
 * Transmits all frames from the TX queue, receives up to one frame.
 */
void sendCanard(void)
{
    for (const CanardCANFrame* txf = NULL; (txf = canardPeekTxQueue(&g_canard)) != NULL;) {
        int16_t tx_res = dronecanTransmit(fdcan_dev[0], txf);

        if (tx_res > 0) {
            canardPopTxQueue(&g_canard);
        } else {
            canardPopTxQueue(&g_canard);
        }
        // canardCleanupStaleTransfers(&g_canard, systime_now_us());
    }
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

extern uint8_t dna_send_step;
uint8_t dna_test_step = 2;
void dronecan_loop(uint32_t time_ms)
{
    static uint16_t tick = 0;

    makeDNAUpate(&g_canard, &dna_send_step);

    tick++;
    if ((tick % 1000) == 0) {
        makeNodeStatus(time_ms);
    }

    if ((tick % 300) == 0) {
        makeLightsRGB(0, 100, 0);
    } else if ((tick % 200) == 0) {
        makeLightsRGB(0, 0, 100);
    } else if ((tick % 100) == 0) {
        makeLightsRGB(100, 100, 0);
    }

    sendCanard();

    receiveCanard();
}