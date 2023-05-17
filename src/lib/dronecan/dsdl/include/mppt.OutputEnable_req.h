#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define MPPT_OUTPUTENABLE_REQUEST_MAX_SIZE 1
#define MPPT_OUTPUTENABLE_REQUEST_SIGNATURE (0xEA251F2A6DD1D8A5ULL)
#define MPPT_OUTPUTENABLE_REQUEST_ID 240

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class mppt_OutputEnable_cxx_iface;
#endif

struct mppt_OutputEnableRequest {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = mppt_OutputEnable_cxx_iface;
#endif
    bool enable;
    bool disable;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t mppt_OutputEnableRequest_encode(struct mppt_OutputEnableRequest* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool mppt_OutputEnableRequest_decode(const CanardRxTransfer* transfer, struct mppt_OutputEnableRequest* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _mppt_OutputEnableRequest_encode(uint8_t* buffer, uint32_t* bit_ofs, struct mppt_OutputEnableRequest* msg, bool tao);
static inline void _mppt_OutputEnableRequest_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct mppt_OutputEnableRequest* msg, bool tao);
void _mppt_OutputEnableRequest_encode(uint8_t* buffer, uint32_t* bit_ofs, struct mppt_OutputEnableRequest* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    *bit_ofs += 6;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->enable);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->disable);
    *bit_ofs += 1;
}

void _mppt_OutputEnableRequest_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct mppt_OutputEnableRequest* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    *bit_ofs += 6;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->enable);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->disable);
    *bit_ofs += 1;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct mppt_OutputEnableRequest sample_mppt_OutputEnableRequest_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
#endif
#endif
