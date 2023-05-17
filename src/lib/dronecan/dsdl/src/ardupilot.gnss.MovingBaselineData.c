#define CANARD_DSDLC_INTERNAL
#include <ardupilot.gnss.MovingBaselineData.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t ardupilot_gnss_MovingBaselineData_encode(struct ardupilot_gnss_MovingBaselineData* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, ARDUPILOT_GNSS_MOVINGBASELINEDATA_MAX_SIZE);
    _ardupilot_gnss_MovingBaselineData_encode(buffer, &bit_ofs, msg, 
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
bool ardupilot_gnss_MovingBaselineData_decode(const CanardRxTransfer* transfer, struct ardupilot_gnss_MovingBaselineData* msg) {
    uint32_t bit_ofs = 0;
    _ardupilot_gnss_MovingBaselineData_decode(transfer, &bit_ofs, msg, 
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
struct ardupilot_gnss_MovingBaselineData sample_ardupilot_gnss_MovingBaselineData_msg(void) {
    struct ardupilot_gnss_MovingBaselineData msg;

    msg.data.len = (uint16_t)random_range_unsigned_val(0, 300);
    for (size_t i=0; i < msg.data.len; i++) {
        msg.data.data[i] = (uint8_t)random_bitlen_unsigned_val(8);
    }
    return msg;
}
#endif
