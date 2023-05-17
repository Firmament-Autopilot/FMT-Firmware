#define CANARD_DSDLC_INTERNAL
#include <mppt.OutputEnable_res.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t mppt_OutputEnableResponse_encode(struct mppt_OutputEnableResponse* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, MPPT_OUTPUTENABLE_RESPONSE_MAX_SIZE);
    _mppt_OutputEnableResponse_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

/*
  return true if the decode is invalid
 */
bool mppt_OutputEnableResponse_decode(const CanardRxTransfer* transfer, struct mppt_OutputEnableResponse* msg) {
    uint32_t bit_ofs = 0;
    _mppt_OutputEnableResponse_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    const uint32_t byte_len = (bit_ofs+7U)/8U;
#if CANARD_ENABLE_TAO_OPTION
    // if this could be CANFD then the dlc could indicating more bytes than
    // we actually have
    if (!transfer->tao) {
        return byte_len > transfer->payload_len;
    }
#endif
    return byte_len != transfer->payload_len;
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct mppt_OutputEnableResponse sample_mppt_OutputEnableResponse_msg(void) {
    struct mppt_OutputEnableResponse msg;

    msg.enabled = (bool)random_bitlen_unsigned_val(1);
    return msg;
}
#endif
