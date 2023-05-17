#include "dronecan_dna.h"

uint8_t dna_step = 0;
uint8_t dna_send_step = 0;

static uint8_t unique_id[16];
static struct uavcan_protocol_dynamic_node_id_Allocation dna_msg;
static uint8_t allocation_request[UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_MAX_SIZE];

void makeThirdDNA(CanardInstance* ins, struct uavcan_protocol_dynamic_node_id_Allocation* dna_send_msg, uint8_t* allocation_request, uint8_t* unique_id)
{
    dna_send_msg->first_part_of_unique_id = false;
    dna_send_msg->unique_id.len = 16;
    dna_send_msg->node_id = 125;

    memcpy(unique_id + 12, dna_send_msg->unique_id.data, 4);
    memcpy(dna_send_msg->unique_id.data, unique_id, 16);

    uint16_t len = uavcan_protocol_dynamic_node_id_Allocation_encode(dna_send_msg, allocation_request);
    static uint8_t transfer_id; // Note that the transfer ID variable MUST BE STATIC (or heap-allocated)!

    canardBroadcast(ins,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID,
                    &transfer_id,
                    CANARD_TRANSFER_PRIORITY_MEDIUM,
                    allocation_request,
                    (uint16_t)len);
}

void makeSecondDNA(CanardInstance* ins, struct uavcan_protocol_dynamic_node_id_Allocation* dna_send_msg, uint8_t* allocation_request, uint8_t* unique_id)
{
    dna_send_msg->first_part_of_unique_id = false;
    dna_send_msg->unique_id.len = 12;

    memcpy(unique_id + 6, dna_send_msg->unique_id.data, 6);
    memcpy(dna_send_msg->unique_id.data, unique_id, 12);

    uint16_t len = uavcan_protocol_dynamic_node_id_Allocation_encode(dna_send_msg, allocation_request);
    static uint8_t transfer_id; // Note that the transfer ID variable MUST BE STATIC (or heap-allocated)!

    canardBroadcast(ins,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID,
                    &transfer_id,
                    CANARD_TRANSFER_PRIORITY_MEDIUM,
                    allocation_request,
                    (uint16_t)len);
}

void makeFirstDNA(CanardInstance* ins, struct uavcan_protocol_dynamic_node_id_Allocation* dna_send_msg, uint8_t* allocation_request, uint8_t* unique_id)
{
    dna_send_msg->first_part_of_unique_id = 0;
    dna_send_msg->unique_id.len = 6;

    memcpy(unique_id, dna_send_msg->unique_id.data, 6);

    uint16_t len = uavcan_protocol_dynamic_node_id_Allocation_encode(dna_send_msg, allocation_request);
    static uint8_t transfer_id; // Note that the transfer ID variable MUST BE STATIC (or heap-allocated)!

    canardBroadcast(ins,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID,
                    &transfer_id,
                    CANARD_TRANSFER_PRIORITY_MEDIUM,
                    allocation_request,
                    (uint16_t)len);
}

void makeDNAUpate(CanardInstance* ins, uint8_t* step)
{
    switch (*step) {
    case 1:
        makeFirstDNA(ins, &dna_msg, allocation_request, unique_id);
        *step = 0;
        break;

    case 2:
        makeSecondDNA(ins, &dna_msg, allocation_request, unique_id);
        *step = 0;
        break;

    case 3:
        makeThirdDNA(ins, &dna_msg, allocation_request, unique_id);
        *step = 0;

        break;

    default:
        break;
    }
}

void dronecan_dynamic_allocation_id(CanardInstance* ins, CanardRxTransfer* transfer, uint8_t master_id, uint8_t slave_id)
{
    switch (dna_step) {
    case 0:
        uavcan_protocol_dynamic_node_id_Allocation_decode(transfer, &dna_msg);
        if (dna_msg.first_part_of_unique_id == true) {
            dna_send_step = dna_step = 1;

            break;
        } else {
            dna_step = 0;
        }
        break;

    case 1:
        uavcan_protocol_dynamic_node_id_Allocation_decode(transfer, &dna_msg);
        if (dna_msg.first_part_of_unique_id == false) {
            dna_send_step = dna_step = 2;
            break;
        } else {
            dna_step = 0;
            break;
        }

    case 2:
        uavcan_protocol_dynamic_node_id_Allocation_decode(transfer, &dna_msg);
        if (dna_msg.first_part_of_unique_id == false) {
            dna_send_step = 3;
            dna_step = 0;
            break;
        } else {
            dna_step = 0;
            break;
        }
    }
}
