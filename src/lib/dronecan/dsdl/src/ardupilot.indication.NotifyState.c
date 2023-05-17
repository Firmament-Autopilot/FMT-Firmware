#define CANARD_DSDLC_INTERNAL
#include <ardupilot.indication.NotifyState.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t ardupilot_indication_NotifyState_encode(struct ardupilot_indication_NotifyState* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, ARDUPILOT_INDICATION_NOTIFYSTATE_MAX_SIZE);
    _ardupilot_indication_NotifyState_encode(buffer, &bit_ofs, msg, 
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
bool ardupilot_indication_NotifyState_decode(const CanardRxTransfer* transfer, struct ardupilot_indication_NotifyState* msg) {
    uint32_t bit_ofs = 0;
    _ardupilot_indication_NotifyState_decode(transfer, &bit_ofs, msg, 
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
struct ardupilot_indication_NotifyState sample_ardupilot_indication_NotifyState_msg(void) {
    struct ardupilot_indication_NotifyState msg;

    msg.aux_data_type = (uint8_t)random_bitlen_unsigned_val(8);
    msg.aux_data.len = (uint8_t)random_range_unsigned_val(0, 255);
    for (size_t i=0; i < msg.aux_data.len; i++) {
        msg.aux_data.data[i] = (uint8_t)random_bitlen_unsigned_val(8);
    }
    msg.vehicle_state = (uint64_t)random_bitlen_unsigned_val(64);
    return msg;
}
#endif
