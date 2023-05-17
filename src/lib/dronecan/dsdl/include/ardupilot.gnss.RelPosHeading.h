#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>
#include <uavcan.Timestamp.h>


#define ARDUPILOT_GNSS_RELPOSHEADING_MAX_SIZE 20
#define ARDUPILOT_GNSS_RELPOSHEADING_SIGNATURE (0xA1727AF295F94478ULL)
#define ARDUPILOT_GNSS_RELPOSHEADING_ID 20006

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class ardupilot_gnss_RelPosHeading_cxx_iface;
#endif

struct ardupilot_gnss_RelPosHeading {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = ardupilot_gnss_RelPosHeading_cxx_iface;
#endif
    struct uavcan_Timestamp timestamp;
    bool reported_heading_acc_available;
    float reported_heading_deg;
    float reported_heading_acc_deg;
    float relative_distance_m;
    float relative_down_pos_m;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t ardupilot_gnss_RelPosHeading_encode(struct ardupilot_gnss_RelPosHeading* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool ardupilot_gnss_RelPosHeading_decode(const CanardRxTransfer* transfer, struct ardupilot_gnss_RelPosHeading* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _ardupilot_gnss_RelPosHeading_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_gnss_RelPosHeading* msg, bool tao);
static inline void _ardupilot_gnss_RelPosHeading_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_gnss_RelPosHeading* msg, bool tao);
void _ardupilot_gnss_RelPosHeading_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_gnss_RelPosHeading* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    _uavcan_Timestamp_encode(buffer, bit_ofs, &msg->timestamp, false);
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->reported_heading_acc_available);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->reported_heading_deg);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->reported_heading_acc_deg);
    *bit_ofs += 32;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->relative_distance_m);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->relative_down_pos_m);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
}

void _ardupilot_gnss_RelPosHeading_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_gnss_RelPosHeading* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    _uavcan_Timestamp_decode(transfer, bit_ofs, &msg->timestamp, false);

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->reported_heading_acc_available);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->reported_heading_deg);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->reported_heading_acc_deg);
    *bit_ofs += 32;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->relative_distance_m = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->relative_down_pos_m = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_gnss_RelPosHeading sample_ardupilot_gnss_RelPosHeading_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(ardupilot_gnss_RelPosHeading, ARDUPILOT_GNSS_RELPOSHEADING_ID, ARDUPILOT_GNSS_RELPOSHEADING_SIGNATURE, ARDUPILOT_GNSS_RELPOSHEADING_MAX_SIZE);
#endif
#endif
