#define CANARD_DSDLC_INTERNAL
#include <ardupilot.gnss.Heading.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t ardupilot_gnss_Heading_encode(struct ardupilot_gnss_Heading* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, ARDUPILOT_GNSS_HEADING_MAX_SIZE);
    _ardupilot_gnss_Heading_encode(buffer, &bit_ofs, msg, 
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
bool ardupilot_gnss_Heading_decode(const CanardRxTransfer* transfer, struct ardupilot_gnss_Heading* msg) {
    uint32_t bit_ofs = 0;
    _ardupilot_gnss_Heading_decode(transfer, &bit_ofs, msg, 
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
struct ardupilot_gnss_Heading sample_ardupilot_gnss_Heading_msg(void) {
    struct ardupilot_gnss_Heading msg;

    msg.heading_valid = (bool)random_bitlen_unsigned_val(1);
    msg.heading_accuracy_valid = (bool)random_bitlen_unsigned_val(1);
    msg.heading_rad = random_float16_val();
    msg.heading_accuracy_rad = random_float16_val();
    return msg;
}
#endif
