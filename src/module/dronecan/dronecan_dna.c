#include "dronecan_dna.h"

enum DNA_STEP {
    step0 = 0,
    step1 = 1,
    step2 = 2,
    step3 = 3,
};

typedef struct
{
    uint8_t dna_step;

    uint8_t dna_send_step;

    uint8_t slave_id;

    uint8_t unique_id[16];

    struct uavcan_protocol_dynamic_node_id_Allocation dna_msg;

    uint8_t allocation_request[UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_MAX_SIZE];

} DroneCANDNA_struct, *DroneCANDNA_struct_ptr;
static DroneCANDNA_struct droneCANDNA_struct;
DroneCANDNA_struct_ptr droneCANDNA_struct_ptr = &droneCANDNA_struct;

#define MAX_NODE_ID (125)
#define MIN_NODE_ID (11)
#define ACCESS_NODE (MAX_NODE_ID - MIN_NODE_ID)
struct uavcan_protocol_dynamic_node_id_server_Entry slave_node_entry[MAX_NODE_ID + 1];

static uint8_t makeSlaveNodeID(uint8_t* unique_id)
{
    for (uint8_t i = MAX_NODE_ID; i > MIN_NODE_ID; i--) {
        if (strncmp((char*)unique_id, (char*)slave_node_entry[i].unique_id, 16) == 0) {
            return i;
        }
    }

    for (uint8_t i = MAX_NODE_ID; i > MIN_NODE_ID; i--) {
        if (slave_node_entry[i].term == 0) {
            slave_node_entry[i].term = 0xff;
            slave_node_entry[i].node_id = i;
            strncpy((char*)slave_node_entry[i].unique_id, (char*)unique_id, 16);
            return i;
        }
    }

    return 0;
}

static void makeThirdDNA(CanardInstance* ins, DroneCANDNA_struct_ptr struct_ptr)
{
    struct_ptr->dna_msg.first_part_of_unique_id = false;
    struct_ptr->dna_msg.unique_id.len = 16;

    memcpy(struct_ptr->unique_id + 12, struct_ptr->dna_msg.unique_id.data, 4);
    memcpy(struct_ptr->dna_msg.unique_id.data, struct_ptr->unique_id, 16);

    struct_ptr->slave_id = makeSlaveNodeID(struct_ptr->unique_id);
    struct_ptr->dna_msg.node_id = struct_ptr->slave_id;
    printf("struct_ptr->slave_id=%d\n", struct_ptr->slave_id);

    uint16_t len = uavcan_protocol_dynamic_node_id_Allocation_encode(&struct_ptr->dna_msg, struct_ptr->allocation_request);
    static uint8_t transfer_id; // Note that the transfer ID variable MUST BE STATIC (or heap-allocated)!

    canardBroadcast(ins,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID,
                    &transfer_id,
                    CANARD_TRANSFER_PRIORITY_MEDIUM,
                    struct_ptr->allocation_request,
                    (uint16_t)len);
}

static void makeSecondDNA(CanardInstance* ins, DroneCANDNA_struct_ptr struct_ptr)
{
    struct_ptr->dna_msg.first_part_of_unique_id = false;
    struct_ptr->dna_msg.unique_id.len = 12;

    memcpy(struct_ptr->unique_id + 6, struct_ptr->dna_msg.unique_id.data, 6);
    memcpy(struct_ptr->dna_msg.unique_id.data, struct_ptr->unique_id, 12);

    uint16_t len = uavcan_protocol_dynamic_node_id_Allocation_encode(&struct_ptr->dna_msg, struct_ptr->allocation_request);
    static uint8_t transfer_id; // Note that the transfer ID variable MUST BE STATIC (or heap-allocated)!

    canardBroadcast(ins,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID,
                    &transfer_id,
                    CANARD_TRANSFER_PRIORITY_MEDIUM,
                    struct_ptr->allocation_request,
                    (uint16_t)len);
}

static void makeFirstDNA(CanardInstance* ins, DroneCANDNA_struct_ptr struct_ptr)
{
    struct_ptr->dna_msg.first_part_of_unique_id = 0;
    struct_ptr->dna_msg.unique_id.len = 6;

    memcpy(struct_ptr->unique_id, struct_ptr->dna_msg.unique_id.data, 6);

    uint16_t len = uavcan_protocol_dynamic_node_id_Allocation_encode(&struct_ptr->dna_msg, struct_ptr->allocation_request);
    static uint8_t transfer_id; // Note that the transfer ID variable MUST BE STATIC (or heap-allocated)!

    canardBroadcast(ins,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE,
                    UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID,
                    &transfer_id,
                    CANARD_TRANSFER_PRIORITY_MEDIUM,
                    struct_ptr->allocation_request,
                    (uint16_t)len);
}

void makeDNAUpate(CanardInstance* ins, uint8_t step, DroneCANDNA_struct_ptr struct_ptr)
{
    switch (step) {
    case step1:
        makeFirstDNA(ins, struct_ptr);
        break;

    case step2:
        makeSecondDNA(ins, struct_ptr);
        break;

    case step3:
        makeThirdDNA(ins, struct_ptr);
        break;

    default:
        break;
    }
}

void dronecan_dynamic_allocation_id(CanardInstance* ins, CanardRxTransfer* transfer)
{
    uavcan_protocol_dynamic_node_id_Allocation_decode(transfer, &droneCANDNA_struct_ptr->dna_msg);

    switch (droneCANDNA_struct_ptr->dna_step) {
    case step0:
        if (droneCANDNA_struct_ptr->dna_msg.first_part_of_unique_id == true) {
            droneCANDNA_struct_ptr->dna_step = step1;
            makeDNAUpate(ins, step1, droneCANDNA_struct_ptr);
            break;
        } else {
            droneCANDNA_struct_ptr->dna_step = step0;
        }
        break;

    case step1:
        if (droneCANDNA_struct_ptr->dna_msg.first_part_of_unique_id == false) {
            droneCANDNA_struct_ptr->dna_step = step2;
            makeDNAUpate(ins, step2, droneCANDNA_struct_ptr);
            break;
        } else {
            droneCANDNA_struct_ptr->dna_step = step0;
            break;
        }

    case step2:
        if (droneCANDNA_struct_ptr->dna_msg.first_part_of_unique_id == false) {
            droneCANDNA_struct_ptr->dna_step = step0;
            makeDNAUpate(ins, step3, droneCANDNA_struct_ptr);
            break;
        } else {
            droneCANDNA_struct_ptr->dna_step = step0;
            break;
        }
    }
}
