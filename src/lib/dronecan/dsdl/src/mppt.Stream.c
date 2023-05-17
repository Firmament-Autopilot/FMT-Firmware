#define CANARD_DSDLC_INTERNAL
#include <mppt.Stream.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t mppt_Stream_encode(struct mppt_Stream* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, MPPT_STREAM_MAX_SIZE);
    _mppt_Stream_encode(buffer, &bit_ofs, msg, 
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
bool mppt_Stream_decode(const CanardRxTransfer* transfer, struct mppt_Stream* msg) {
    uint32_t bit_ofs = 0;
    _mppt_Stream_decode(transfer, &bit_ofs, msg, 
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
struct mppt_Stream sample_mppt_Stream_msg(void) {
    struct mppt_Stream msg;

    msg.fault_flags = (uint8_t)random_bitlen_unsigned_val(8);
    msg.temperature = (int8_t)random_bitlen_signed_val(8);
    msg.input_voltage = random_float16_val();
    msg.input_current = random_float16_val();
    msg.input_power = random_float16_val();
    msg.output_voltage = random_float16_val();
    msg.output_current = random_float16_val();
    msg.output_power = random_float16_val();
    return msg;
}
#endif
