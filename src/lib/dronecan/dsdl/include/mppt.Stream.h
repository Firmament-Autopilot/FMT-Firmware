#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define MPPT_STREAM_MAX_SIZE 14
#define MPPT_STREAM_SIGNATURE (0xDD7096B255FB6358ULL)
#define MPPT_STREAM_ID 20009

#define MPPT_STREAM_OV_FAULT 1
#define MPPT_STREAM_UV_FAULT 2
#define MPPT_STREAM_OC_FAULT 4
#define MPPT_STREAM_OT_FAULT 8

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class mppt_Stream_cxx_iface;
#endif

struct mppt_Stream {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = mppt_Stream_cxx_iface;
#endif
    uint8_t fault_flags;
    int8_t temperature;
    float input_voltage;
    float input_current;
    float input_power;
    float output_voltage;
    float output_current;
    float output_power;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t mppt_Stream_encode(struct mppt_Stream* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool mppt_Stream_decode(const CanardRxTransfer* transfer, struct mppt_Stream* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _mppt_Stream_encode(uint8_t* buffer, uint32_t* bit_ofs, struct mppt_Stream* msg, bool tao);
static inline void _mppt_Stream_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct mppt_Stream* msg, bool tao);
void _mppt_Stream_encode(uint8_t* buffer, uint32_t* bit_ofs, struct mppt_Stream* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->fault_flags);
    *bit_ofs += 8;
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->temperature);
    *bit_ofs += 8;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->input_voltage);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->input_current);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->input_power);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->output_voltage);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->output_current);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->output_power);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
}

void _mppt_Stream_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct mppt_Stream* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->fault_flags);
    *bit_ofs += 8;

    canardDecodeScalar(transfer, *bit_ofs, 8, true, &msg->temperature);
    *bit_ofs += 8;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->input_voltage = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->input_current = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->input_power = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->output_voltage = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->output_current = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->output_power = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct mppt_Stream sample_mppt_Stream_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(mppt_Stream, MPPT_STREAM_ID, MPPT_STREAM_SIGNATURE, MPPT_STREAM_MAX_SIZE);
#endif
#endif
