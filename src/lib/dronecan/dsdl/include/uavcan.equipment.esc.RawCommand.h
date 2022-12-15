
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_EQUIPMENT_ESC_RAWCOMMAND_MAX_SIZE 36
#define UAVCAN_EQUIPMENT_ESC_RAWCOMMAND_SIGNATURE (0x217F5C87D7EC951DULL)

#define UAVCAN_EQUIPMENT_ESC_RAWCOMMAND_ID 1030




struct uavcan_equipment_esc_RawCommand {



    struct { uint8_t len; int16_t data[20]; }cmd;



};

uint32_t uavcan_equipment_esc_RawCommand_encode(struct uavcan_equipment_esc_RawCommand* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_equipment_esc_RawCommand_decode(const CanardRxTransfer* transfer, struct uavcan_equipment_esc_RawCommand* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_equipment_esc_RawCommand_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_equipment_esc_RawCommand* msg, bool tao);
static inline void _uavcan_equipment_esc_RawCommand_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_equipment_esc_RawCommand* msg, bool tao);
void _uavcan_equipment_esc_RawCommand_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_equipment_esc_RawCommand* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;







    if (!tao) {


        canardEncodeScalar(buffer, *bit_ofs, 5, &msg->cmd.len);
        *bit_ofs += 5;


    }

    for (size_t i=0; i < msg->cmd.len; i++) {




        canardEncodeScalar(buffer, *bit_ofs, 14, &msg->cmd.data[i]);

        *bit_ofs += 14;


    }





}

void _uavcan_equipment_esc_RawCommand_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_equipment_esc_RawCommand* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;







    if (!tao) {


        canardDecodeScalar(transfer, *bit_ofs, 5, false, &msg->cmd.len);
        *bit_ofs += 5;



    } else {

        msg->cmd.len = ((transfer->payload_len*8)-*bit_ofs)/14;


    }



    for (size_t i=0; i < msg->cmd.len; i++) {




        canardDecodeScalar(transfer, *bit_ofs, 14, true, &msg->cmd.data[i]);

        *bit_ofs += 14;


    }







}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_equipment_esc_RawCommand sample_uavcan_equipment_esc_RawCommand_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
