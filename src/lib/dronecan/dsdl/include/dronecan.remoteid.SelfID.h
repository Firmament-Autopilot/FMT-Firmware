#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define DRONECAN_REMOTEID_SELFID_MAX_SIZE 46
#define DRONECAN_REMOTEID_SELFID_SIGNATURE (0x59BE81DC4C06A185ULL)
#define DRONECAN_REMOTEID_SELFID_ID 20032

#define DRONECAN_REMOTEID_SELFID_ODID_DESC_TYPE_TEXT 0

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class dronecan_remoteid_SelfID_cxx_iface;
#endif

struct dronecan_remoteid_SelfID {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = dronecan_remoteid_SelfID_cxx_iface;
#endif
    struct { uint8_t len; uint8_t data[20]; }id_or_mac;
    uint8_t description_type;
    struct { uint8_t len; uint8_t data[23]; }description;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t dronecan_remoteid_SelfID_encode(struct dronecan_remoteid_SelfID* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool dronecan_remoteid_SelfID_decode(const CanardRxTransfer* transfer, struct dronecan_remoteid_SelfID* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _dronecan_remoteid_SelfID_encode(uint8_t* buffer, uint32_t* bit_ofs, struct dronecan_remoteid_SelfID* msg, bool tao);
static inline void _dronecan_remoteid_SelfID_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct dronecan_remoteid_SelfID* msg, bool tao);
void _dronecan_remoteid_SelfID_encode(uint8_t* buffer, uint32_t* bit_ofs, struct dronecan_remoteid_SelfID* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 5, &msg->id_or_mac.len);
    *bit_ofs += 5;
    for (size_t i=0; i < msg->id_or_mac.len; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 8, &msg->id_or_mac.data[i]);
        *bit_ofs += 8;
    }
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->description_type);
    *bit_ofs += 8;
    if (!tao) {
        canardEncodeScalar(buffer, *bit_ofs, 5, &msg->description.len);
        *bit_ofs += 5;
    }
    for (size_t i=0; i < msg->description.len; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 8, &msg->description.data[i]);
        *bit_ofs += 8;
    }
}

void _dronecan_remoteid_SelfID_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct dronecan_remoteid_SelfID* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardDecodeScalar(transfer, *bit_ofs, 5, false, &msg->id_or_mac.len);
    *bit_ofs += 5;
    for (size_t i=0; i < msg->id_or_mac.len; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->id_or_mac.data[i]);
        *bit_ofs += 8;
    }

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->description_type);
    *bit_ofs += 8;

    if (!tao) {
        canardDecodeScalar(transfer, *bit_ofs, 5, false, &msg->description.len);
        *bit_ofs += 5;
    } else {
        msg->description.len = ((transfer->payload_len*8)-*bit_ofs)/8;
    }

    for (size_t i=0; i < msg->description.len; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->description.data[i]);
        *bit_ofs += 8;
    }

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct dronecan_remoteid_SelfID sample_dronecan_remoteid_SelfID_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(dronecan_remoteid_SelfID, DRONECAN_REMOTEID_SELFID_ID, DRONECAN_REMOTEID_SELFID_SIGNATURE, DRONECAN_REMOTEID_SELFID_MAX_SIZE);
#endif
#endif
