#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>
#include <uavcan.protocol.param.NumericValue.h>


#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_MAX_SIZE 102
#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_SIGNATURE (0x884CB63050A84F35ULL)
#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_ID 380

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class uavcan_protocol_enumeration_Indication_cxx_iface;
#endif

struct uavcan_protocol_enumeration_Indication {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = uavcan_protocol_enumeration_Indication_cxx_iface;
#endif
    struct uavcan_protocol_param_NumericValue value;
    struct { uint8_t len; uint8_t data[92]; }parameter_name;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t uavcan_protocol_enumeration_Indication_encode(struct uavcan_protocol_enumeration_Indication* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_protocol_enumeration_Indication_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_enumeration_Indication* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _uavcan_protocol_enumeration_Indication_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_enumeration_Indication* msg, bool tao);
static inline void _uavcan_protocol_enumeration_Indication_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_enumeration_Indication* msg, bool tao);
void _uavcan_protocol_enumeration_Indication_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_enumeration_Indication* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    *bit_ofs += 6;
    _uavcan_protocol_param_NumericValue_encode(buffer, bit_ofs, &msg->value, false);
    if (!tao) {
        canardEncodeScalar(buffer, *bit_ofs, 7, &msg->parameter_name.len);
        *bit_ofs += 7;
    }
    for (size_t i=0; i < msg->parameter_name.len; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 8, &msg->parameter_name.data[i]);
        *bit_ofs += 8;
    }
}

void _uavcan_protocol_enumeration_Indication_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_enumeration_Indication* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    *bit_ofs += 6;

    _uavcan_protocol_param_NumericValue_decode(transfer, bit_ofs, &msg->value, false);

    if (!tao) {
        canardDecodeScalar(transfer, *bit_ofs, 7, false, &msg->parameter_name.len);
        *bit_ofs += 7;
    } else {
        msg->parameter_name.len = ((transfer->payload_len*8)-*bit_ofs)/8;
    }

    for (size_t i=0; i < msg->parameter_name.len; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->parameter_name.data[i]);
        *bit_ofs += 8;
    }

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_enumeration_Indication sample_uavcan_protocol_enumeration_Indication_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(uavcan_protocol_enumeration_Indication, UAVCAN_PROTOCOL_ENUMERATION_INDICATION_ID, UAVCAN_PROTOCOL_ENUMERATION_INDICATION_SIGNATURE, UAVCAN_PROTOCOL_ENUMERATION_INDICATION_MAX_SIZE);
#endif
#endif
