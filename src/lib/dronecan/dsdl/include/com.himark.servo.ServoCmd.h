#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define COM_HIMARK_SERVO_SERVOCMD_MAX_SIZE 22
#define COM_HIMARK_SERVO_SERVOCMD_SIGNATURE (0x5D09E48551CE9194ULL)
#define COM_HIMARK_SERVO_SERVOCMD_ID 2018

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class com_himark_servo_ServoCmd_cxx_iface;
#endif

struct com_himark_servo_ServoCmd {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = com_himark_servo_ServoCmd_cxx_iface;
#endif
    struct { uint8_t len; uint16_t data[17]; }cmd;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t com_himark_servo_ServoCmd_encode(struct com_himark_servo_ServoCmd* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool com_himark_servo_ServoCmd_decode(const CanardRxTransfer* transfer, struct com_himark_servo_ServoCmd* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _com_himark_servo_ServoCmd_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_himark_servo_ServoCmd* msg, bool tao);
static inline void _com_himark_servo_ServoCmd_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_himark_servo_ServoCmd* msg, bool tao);
void _com_himark_servo_ServoCmd_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_himark_servo_ServoCmd* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    if (!tao) {
        canardEncodeScalar(buffer, *bit_ofs, 5, &msg->cmd.len);
        *bit_ofs += 5;
    }
    for (size_t i=0; i < msg->cmd.len; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 10, &msg->cmd.data[i]);
        *bit_ofs += 10;
    }
}

void _com_himark_servo_ServoCmd_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_himark_servo_ServoCmd* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    if (!tao) {
        canardDecodeScalar(transfer, *bit_ofs, 5, false, &msg->cmd.len);
        *bit_ofs += 5;
    } else {
        msg->cmd.len = ((transfer->payload_len*8)-*bit_ofs)/10;
    }

    for (size_t i=0; i < msg->cmd.len; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 10, false, &msg->cmd.data[i]);
        *bit_ofs += 10;
    }

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct com_himark_servo_ServoCmd sample_com_himark_servo_ServoCmd_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(com_himark_servo_ServoCmd, COM_HIMARK_SERVO_SERVOCMD_ID, COM_HIMARK_SERVO_SERVOCMD_SIGNATURE, COM_HIMARK_SERVO_SERVOCMD_MAX_SIZE);
#endif
#endif
