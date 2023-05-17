#define CANARD_DSDLC_INTERNAL
#include <ardupilot.gnss.RelPosHeading.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t ardupilot_gnss_RelPosHeading_encode(struct ardupilot_gnss_RelPosHeading* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, ARDUPILOT_GNSS_RELPOSHEADING_MAX_SIZE);
    _ardupilot_gnss_RelPosHeading_encode(buffer, &bit_ofs, msg, 
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
bool ardupilot_gnss_RelPosHeading_decode(const CanardRxTransfer* transfer, struct ardupilot_gnss_RelPosHeading* msg) {
    uint32_t bit_ofs = 0;
    _ardupilot_gnss_RelPosHeading_decode(transfer, &bit_ofs, msg, 
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
struct ardupilot_gnss_RelPosHeading sample_ardupilot_gnss_RelPosHeading_msg(void) {
    struct ardupilot_gnss_RelPosHeading msg;

    msg.timestamp = sample_uavcan_Timestamp_msg();
    msg.reported_heading_acc_available = (bool)random_bitlen_unsigned_val(1);
    msg.reported_heading_deg = random_float_val();
    msg.reported_heading_acc_deg = random_float_val();
    msg.relative_distance_m = random_float16_val();
    msg.relative_down_pos_m = random_float16_val();
    return msg;
}
#endif
