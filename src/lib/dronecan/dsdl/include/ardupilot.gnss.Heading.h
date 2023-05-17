#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define ARDUPILOT_GNSS_HEADING_MAX_SIZE 5
#define ARDUPILOT_GNSS_HEADING_SIGNATURE (0x315CAE39ECED3412ULL)
#define ARDUPILOT_GNSS_HEADING_ID 20002

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class ardupilot_gnss_Heading_cxx_iface;
#endif

struct ardupilot_gnss_Heading {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = ardupilot_gnss_Heading_cxx_iface;
#endif
    bool heading_valid;
    bool heading_accuracy_valid;
    float heading_rad;
    float heading_accuracy_rad;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t ardupilot_gnss_Heading_encode(struct ardupilot_gnss_Heading* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool ardupilot_gnss_Heading_decode(const CanardRxTransfer* transfer, struct ardupilot_gnss_Heading* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _ardupilot_gnss_Heading_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_gnss_Heading* msg, bool tao);
static inline void _ardupilot_gnss_Heading_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_gnss_Heading* msg, bool tao);
void _ardupilot_gnss_Heading_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_gnss_Heading* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->heading_valid);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->heading_accuracy_valid);
    *bit_ofs += 1;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->heading_rad);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->heading_accuracy_rad);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
}

void _ardupilot_gnss_Heading_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_gnss_Heading* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->heading_valid);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->heading_accuracy_valid);
    *bit_ofs += 1;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->heading_rad = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->heading_accuracy_rad = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_gnss_Heading sample_ardupilot_gnss_Heading_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(ardupilot_gnss_Heading, ARDUPILOT_GNSS_HEADING_ID, ARDUPILOT_GNSS_HEADING_SIGNATURE, ARDUPILOT_GNSS_HEADING_MAX_SIZE);
#endif
#endif
