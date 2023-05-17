#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define ARDUPILOT_GNSS_MOVINGBASELINEDATA_MAX_SIZE 302
#define ARDUPILOT_GNSS_MOVINGBASELINEDATA_SIGNATURE (0x9F323748C32133AULL)
#define ARDUPILOT_GNSS_MOVINGBASELINEDATA_ID 20005

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class ardupilot_gnss_MovingBaselineData_cxx_iface;
#endif

struct ardupilot_gnss_MovingBaselineData {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = ardupilot_gnss_MovingBaselineData_cxx_iface;
#endif
    struct { uint16_t len; uint8_t data[300]; }data;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t ardupilot_gnss_MovingBaselineData_encode(struct ardupilot_gnss_MovingBaselineData* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool ardupilot_gnss_MovingBaselineData_decode(const CanardRxTransfer* transfer, struct ardupilot_gnss_MovingBaselineData* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _ardupilot_gnss_MovingBaselineData_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_gnss_MovingBaselineData* msg, bool tao);
static inline void _ardupilot_gnss_MovingBaselineData_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_gnss_MovingBaselineData* msg, bool tao);
void _ardupilot_gnss_MovingBaselineData_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_gnss_MovingBaselineData* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    if (!tao) {
        canardEncodeScalar(buffer, *bit_ofs, 9, &msg->data.len);
        *bit_ofs += 9;
    }
    for (size_t i=0; i < msg->data.len; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 8, &msg->data.data[i]);
        *bit_ofs += 8;
    }
}

void _ardupilot_gnss_MovingBaselineData_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_gnss_MovingBaselineData* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    if (!tao) {
        canardDecodeScalar(transfer, *bit_ofs, 9, false, &msg->data.len);
        *bit_ofs += 9;
    } else {
        msg->data.len = ((transfer->payload_len*8)-*bit_ofs)/8;
    }

    for (size_t i=0; i < msg->data.len; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->data.data[i]);
        *bit_ofs += 8;
    }

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_gnss_MovingBaselineData sample_ardupilot_gnss_MovingBaselineData_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(ardupilot_gnss_MovingBaselineData, ARDUPILOT_GNSS_MOVINGBASELINEDATA_ID, ARDUPILOT_GNSS_MOVINGBASELINEDATA_SIGNATURE, ARDUPILOT_GNSS_MOVINGBASELINEDATA_MAX_SIZE);
#endif
#endif
