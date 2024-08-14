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
#include "com.himark.servo.ServoCmd.h"
#ifdef SOC_SERIES_STM32H7
#include "canard_stm32H7.h"
#endif

#ifdef SOC_SERIES_GD32F450
#include "canard_gd32f4xx.h"
#endif

#include "driver/gps/gps_dronecan.h"

#include "module/param/param.h"
#include "model/control/control_interface.h"
#include "../ipc/uMCN.h"
#include <FMS.h>

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

#define HAL_CAN_DEFAULT_NODE_ID 1
#ifndef HAL_CAN_DEFAULT_NODE_ID
    #define HAL_CAN_DEFAULT_NODE_ID CANARD_BROADCAST_NODE_ID
#endif

uint8_t PreferredNodeID = HAL_CAN_DEFAULT_NODE_ID;

CanardInstance g_canard;                   ///< The library instance
static uint8_t g_canard_memory_pool[2048]; ///< Arena for memory allocation, used by the library

static rt_device_t fdcan_dev[HAL_MAX_FDCAN_NUM];

struct uavcan_protocol_param_GetSetResponse uavcan_protocol_param_GetSetResponse_msg;
struct uavcan_protocol_NodeStatus uavcan_protocol_NodeStatus_msg;

// 华迈舵机发送
#define CAN_SERVO_DETACH_CMD    1020
static McnNode_t        control_out_nod;
static McnNode_t        fms_out_nod;
MCN_DECLARE(control_output);
MCN_DECLARE(fms_output);

// 华迈舵机接收处理
static void HimarkInfoHandleCanard(CanardRxTransfer* receive);
MCN_DEFINE(Himark_Back, sizeof(Himark_Back_t));

static void onTransferReceived(CanardInstance* ins,
                               CanardRxTransfer* transfer)
{
    if (transfer->data_type_id == UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID
        && transfer->source_node_id == CANARD_BROADCAST_NODE_ID) {
        dronecan_dynamic_allocation_id(&g_canard, transfer);
    }

    switch (transfer->data_type_id) {
    case UAVCAN_PROTOCOL_NODESTATUS_ID:
        uavcan_protocol_NodeStatus_decode(transfer, &uavcan_protocol_NodeStatus_msg);
        break;

    case UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH_ID:
        break;

    case UAVCAN_PROTOCOL_DEBUG_KEYVALUE_ID:
        break;
    
    case COM_HIMARK_SERVO_SERVOINFO_ID:
        // printf("rec himark data\r\n");
        HimarkInfoHandleCanard(transfer);
        break;

    default:
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
        *out_data_type_signature = UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE;
        return true;

    case UAVCAN_PROTOCOL_NODESTATUS_ID:
        *out_data_type_signature = UAVCAN_PROTOCOL_NODESTATUS_SIGNATURE;
        return true;


    case UAVCAN_EQUIPMENT_GNSS_AUXILIARY_ID:
        *out_data_type_signature = UAVCAN_EQUIPMENT_GNSS_AUXILIARY_SIGNATURE;
        return true;

    case UAVCAN_EQUIPMENT_GNSS_FIX2_ID:
        *out_data_type_signature = UAVCAN_EQUIPMENT_GNSS_FIX2_SIGNATURE;
        return true;

    case UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH_ID:
        *out_data_type_signature = UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH_SIGNATURE;
        return true;

    case COM_HIMARK_SERVO_SERVOINFO_ID:
        *out_data_type_signature = COM_HIMARK_SERVO_SERVOINFO_SIGNATURE;
        return true;
    }

    return false;
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
                    CANARD_TRANSFER_PRIORITY_LOW,
                    node_msg_buffer,
                    (uint16_t)total_size);
}
fmt_err_t send_himark_cmd(void)
{
    uint8_t himark_cmd_msg_buffer[COM_HIMARK_SERVO_SERVOCMD_MAX_SIZE];
    struct com_himark_servo_ServoCmd himark_cmd_msg;
    Control_Out_Bus control_out;
    FMS_Out_Bus FMS_Out;

    if (mcn_poll(control_out_nod) == false) {
        return FMT_ERROR;
    }
    mcn_copy(MCN_HUB(control_output), control_out_nod, &control_out);

    if (mcn_poll(fms_out_nod) == false) {
        return FMT_ERROR;
    }
    mcn_copy(MCN_HUB(fms_output), fms_out_nod, &FMS_Out);

    // 舵机最大12个，只发12个舵机数据减小总线带宽
    for(uint8_t i=0; i<12; i++)
    {
        if(FMS_Out.status==3)
        {
            // 解锁状态，发送舵机控制指令
            himark_cmd_msg.cmd.data[i] = control_out.actuator_cmd[i];
        }
        else
        {
            // 未解锁时解除舵机控制
            himark_cmd_msg.cmd.data[i] = CAN_SERVO_DETACH_CMD;
        }
        
    }
    himark_cmd_msg.cmd.len = 12;
    
    uint16_t total_size = com_himark_servo_ServoCmd_encode(&himark_cmd_msg, himark_cmd_msg_buffer);

    static uint8_t transfer_id; // Note that the transfer ID variable MUST BE STATIC (or heap-allocated)!

    canardBroadcast(&g_canard,
                    COM_HIMARK_SERVO_SERVOCMD_SIGNATURE,
                    COM_HIMARK_SERVO_SERVOCMD_ID,
                    &transfer_id,
                    CANARD_TRANSFER_PRIORITY_LOW,
                    himark_cmd_msg_buffer,
                    (uint16_t)total_size);

    return FMT_EOK;
}

void receiveCanard(void)
{
    // Receiving
    uint64_t timestamp = systime_now_us();

    CanardCANFrame rx_frame;

    int16_t rx_res = dronecanReceive(fdcan_dev[0], &rx_frame);
    if (rx_res > 0) {
        rx_res = canardHandleRxFrame(&g_canard, &rx_frame, timestamp);
    }
}

/**
 * Transmits all frames from the TX queue, receives up to one frame.
 */
void sendCanard(void)
{
    const CanardCANFrame* txf = canardPeekTxQueue(&g_canard); 
    while(txf)
    {
        const int NodeStatus_tx_res = dronecanTransmit(fdcan_dev[0],txf);
        if (NodeStatus_tx_res < 0)                  // Failure - drop the frame and report
        {
            __ASM volatile("BKPT #01");  			// TODO: handle the error properly
        }
        if(NodeStatus_tx_res > 0)
        {
            canardPopTxQueue(&g_canard);
        }
        txf = canardPeekTxQueue(&g_canard);
        canardCleanupStaleTransfers(&g_canard, systime_now_us());
    }
}

static int Himark_Back_echo(void* param)
{
    fmt_err_t  err;
    Himark_Back_t himark_report;

    err = mcn_copy_from_hub((McnHub*)param, &himark_report);

    if (err != FMT_EOK) {
        return -1;
    }

    return 0;
}

fmt_err_t dronecan_init(void)
{
#ifdef SOC_SERIES_STM32H7    
    fdcan_dev[0] = rt_device_find("fdcan1");
#endif
#ifdef SOC_SERIES_GD32F450
    fdcan_dev[0] = rt_device_find("can0");
    printf("board type SOC_SERIES_GD32F450\n");
#endif    
    RT_ASSERT(fdcan_dev[0] != NULL);

    RT_CHECK(rt_device_open(fdcan_dev[0], RT_DEVICE_OFLAG_RDWR));

    mcn_advertise(MCN_HUB(Himark_Back), Himark_Back_echo);

    fms_out_nod = mcn_subscribe(MCN_HUB(fms_output), NULL, NULL);
    control_out_nod = mcn_subscribe(MCN_HUB(control_output), NULL, NULL);

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

void dronecan_loop(uint32_t time_ms)
{
    static uint16_t tick = 0;

    tick++;
    if ((tick % 1000) == 0) {
        makeNodeStatus(time_ms);
    }

    // 200Hz 华迈舵机控制数据
    if((tick % 5) == 0)
    {
        send_himark_cmd();
    }

    sendCanard();

    // receiveCanard();
}


static void HimarkInfoHandleCanard(CanardRxTransfer* receive)
{
    Himark_Back_t msg;

    if(com_himark_servo_ServoInfo_decode(receive, &msg.srv_data) == FMT_EOK)
    {
        msg.timestamp_ms = systime_now_ms();
        /* publish Himark Back data */
        mcn_publish(MCN_HUB(Himark_Back), &msg);

    }
}