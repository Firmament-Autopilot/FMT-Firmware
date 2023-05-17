#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>
#include <uavcan.equipment.actuator.Command.h>


#define UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND_MAX_SIZE 61
#define UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND_SIGNATURE (0xD8A7486238EC3AF3ULL)
#define UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND_ID 1010

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class uavcan_equipment_actuator_ArrayCommand_cxx_iface;
#endif

struct uavcan_equipment_actuator_ArrayCommand {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = uavcan_equipment_actuator_ArrayCommand_cxx_iface;
#endif
    struct { uint8_t len; struct uavcan_equipment_actuator_Command data[15]; }commands;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t uavcan_equipment_actuator_ArrayCommand_encode(struct uavcan_equipment_actuator_ArrayCommand* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_equipment_actuator_ArrayCommand_decode(const CanardRxTransfer* transfer, struct uavcan_equipment_actuator_ArrayCommand* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _uavcan_equipment_actuator_ArrayCommand_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_equipment_actuator_ArrayCommand* msg, bool tao);
static inline void _uavcan_equipment_actuator_ArrayCommand_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_equipment_actuator_ArrayCommand* msg, bool tao);
void _uavcan_equipment_actuator_ArrayCommand_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_equipment_actuator_ArrayCommand* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    if (!tao) {
        canardEncodeScalar(buffer, *bit_ofs, 4, &msg->commands.len);
        *bit_ofs += 4;
    }
    for (size_t i=0; i < msg->commands.len; i++) {
        _uavcan_equipment_actuator_Command_encode(buffer, bit_ofs, &msg->commands.data[i], false);
    }
}

void _uavcan_equipment_actuator_ArrayCommand_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_equipment_actuator_ArrayCommand* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    if (!tao) {
        canardDecodeScalar(transfer, *bit_ofs, 4, false, &msg->commands.len);
        *bit_ofs += 4;
    }


    if (tao) {
        msg->commands.len = 0;
        while ((transfer->payload_len*8) > *bit_ofs) {
            _uavcan_equipment_actuator_Command_decode(transfer, bit_ofs, &msg->commands.data[msg->commands.len], false);
            msg->commands.len++;
        }
    } else {
        for (size_t i=0; i < msg->commands.len; i++) {
            _uavcan_equipment_actuator_Command_decode(transfer, bit_ofs, &msg->commands.data[i], false);
        }
    }

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_equipment_actuator_ArrayCommand sample_uavcan_equipment_actuator_ArrayCommand_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(uavcan_equipment_actuator_ArrayCommand, UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND_ID, UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND_SIGNATURE, UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND_MAX_SIZE);
#endif
#endif
