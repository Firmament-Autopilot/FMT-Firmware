
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_EQUIPMENT_HARDPOINT_COMMAND_MAX_SIZE 3
#define UAVCAN_EQUIPMENT_HARDPOINT_COMMAND_SIGNATURE (0xA1A036268B0C3455ULL)

#define UAVCAN_EQUIPMENT_HARDPOINT_COMMAND_ID 1070




struct uavcan_equipment_hardpoint_Command {



    uint8_t hardpoint_id;



    uint16_t command;



};

uint32_t uavcan_equipment_hardpoint_Command_encode(struct uavcan_equipment_hardpoint_Command* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_equipment_hardpoint_Command_decode(const CanardRxTransfer* transfer, struct uavcan_equipment_hardpoint_Command* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_equipment_hardpoint_Command_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_equipment_hardpoint_Command* msg, bool tao);
static inline void _uavcan_equipment_hardpoint_Command_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_equipment_hardpoint_Command* msg, bool tao);
void _uavcan_equipment_hardpoint_Command_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_equipment_hardpoint_Command* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->hardpoint_id);

    *bit_ofs += 8;






    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->command);

    *bit_ofs += 16;





}

void _uavcan_equipment_hardpoint_Command_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_equipment_hardpoint_Command* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->hardpoint_id);

    *bit_ofs += 8;







    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->command);

    *bit_ofs += 16;






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_equipment_hardpoint_Command sample_uavcan_equipment_hardpoint_Command_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
