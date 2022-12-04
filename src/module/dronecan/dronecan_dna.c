#include "dronecan_dna.h"

static uint8_t unique_id[16];
static uint8_t alloc_step = 0;
static struct uavcan_protocol_dynamic_node_id_Allocation dynamic_node_id_allocation_msg;
static uint8_t allocation_request[UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_MAX_SIZE];

void dronecan_dynamic_allocation_id(const CanardInstance* ins, CanardRxTransfer* transfer, uint8_t master_id, uint8_t slave_id)
{
    switch (alloc_step) {
    case 0:
        uavcan_protocol_dynamic_node_id_Allocation_decode(transfer, &dynamic_node_id_allocation_msg);

        if (dynamic_node_id_allocation_msg.first_part_of_unique_id == true) {
            // printf("dynamic_node_id_allocation_msg.node_id=%d\n", dynamic_node_id_allocation_msg.node_id);
            // printf("dynamic_node_id_allocation_msg.first_part_of_unique_id=%d\n", dynamic_node_id_allocation_msg.first_part_of_unique_id);
            // printf("dynamic_node_id_allocation_msg.unique_id.len=%d\n", dynamic_node_id_allocation_msg.unique_id.len);

            memcpy(unique_id, dynamic_node_id_allocation_msg.unique_id.data, 6);
            dynamic_node_id_allocation_msg.first_part_of_unique_id = 0;
            dynamic_node_id_allocation_msg.unique_id.len = 6;

            uint16_t len = uavcan_protocol_dynamic_node_id_Allocation_encode(&dynamic_node_id_allocation_msg, allocation_request);
            int16_t bcast_res = canardBroadcast(ins,
                                                UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE,
                                                UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID,
                                                &master_id,
                                                CANARD_TRANSFER_PRIORITY_LOW,
                                                allocation_request,
                                                (uint16_t)len);
            alloc_step = 1;
            break;
        } else {
            alloc_step = 0;
        }
        break;

    case 1:
        uavcan_protocol_dynamic_node_id_Allocation_decode(transfer, &dynamic_node_id_allocation_msg);

        if (dynamic_node_id_allocation_msg.first_part_of_unique_id == false) {
            // printf("dynamic_node_id_allocation_msg.node_id=%d\n", dynamic_node_id_allocation_msg.node_id);
            // printf("dynamic_node_id_allocation_msg.first_part_of_unique_id=%d\n", dynamic_node_id_allocation_msg.first_part_of_unique_id);
            // printf("dynamic_node_id_allocation_msg.unique_id.len=%d\n", dynamic_node_id_allocation_msg.unique_id.len);

            memcpy(unique_id + 6, dynamic_node_id_allocation_msg.unique_id.data, 6);
            memcpy(dynamic_node_id_allocation_msg.unique_id.data, unique_id, 12);

            dynamic_node_id_allocation_msg.first_part_of_unique_id = 0;
            dynamic_node_id_allocation_msg.unique_id.len = 12;

            uint16_t len = uavcan_protocol_dynamic_node_id_Allocation_encode(&dynamic_node_id_allocation_msg, allocation_request);
            int16_t bcast_res = canardBroadcast(ins,
                                                UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE,
                                                UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID,
                                                &master_id,
                                                CANARD_TRANSFER_PRIORITY_LOW,
                                                allocation_request,
                                                (uint16_t)len);
            alloc_step = 2;
            break;
        } else {
            alloc_step = 0;
            break;
        }

    case 2:
        uavcan_protocol_dynamic_node_id_Allocation_decode(transfer, &dynamic_node_id_allocation_msg);

        if (dynamic_node_id_allocation_msg.first_part_of_unique_id == false) {
            memcpy(unique_id + 12, dynamic_node_id_allocation_msg.unique_id.data, 4);
            memcpy(dynamic_node_id_allocation_msg.unique_id.data, unique_id, 16);

            dynamic_node_id_allocation_msg.first_part_of_unique_id = 0;
            dynamic_node_id_allocation_msg.unique_id.len = 16;
            dynamic_node_id_allocation_msg.node_id = slave_id;

            uint32_t len = uavcan_protocol_dynamic_node_id_Allocation_encode(&dynamic_node_id_allocation_msg, allocation_request);
            int16_t bcast_res = canardBroadcast(ins,
                                                UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE,
                                                UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID,
                                                &master_id,
                                                CANARD_TRANSFER_PRIORITY_LOW,
                                                allocation_request,
                                                (uint16_t)len);
            alloc_step = 0;
            printf("dynamic_alloc_ok..............\n");

            break;
        } else {
            alloc_step = 0;
            break;
        }
    }
}