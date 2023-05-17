#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define MPPT_OUTPUTENABLE_RESPONSE_MAX_SIZE 1
#define MPPT_OUTPUTENABLE_RESPONSE_SIGNATURE (0xEA251F2A6DD1D8A5ULL)
#define MPPT_OUTPUTENABLE_RESPONSE_ID 240

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class mppt_OutputEnable_cxx_iface;
#endif

struct mppt_OutputEnableResponse {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = mppt_OutputEnable_cxx_iface;
#endif
    bool enabled;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t mppt_OutputEnableResponse_encode(struct mppt_OutputEnableResponse* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool mppt_OutputEnableResponse_decode(const CanardRxTransfer* transfer, struct mppt_OutputEnableResponse* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _mppt_OutputEnableResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct mppt_OutputEnableResponse* msg, bool tao);
static inline void _mppt_OutputEnableResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct mppt_OutputEnableResponse* msg, bool tao);
void _mppt_OutputEnableResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct mppt_OutputEnableResponse* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    *bit_ofs += 7;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->enabled);
    *bit_ofs += 1;
}

void _mppt_OutputEnableResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct mppt_OutputEnableResponse* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    *bit_ofs += 7;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->enabled);
    *bit_ofs += 1;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct mppt_OutputEnableResponse sample_mppt_OutputEnableResponse_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
#endif
#endif
