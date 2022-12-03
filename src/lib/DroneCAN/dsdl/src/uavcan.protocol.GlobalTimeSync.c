

#define CANARD_DSDLC_INTERNAL
#include <uavcan.protocol.GlobalTimeSync.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t uavcan_protocol_GlobalTimeSync_encode(struct uavcan_protocol_GlobalTimeSync* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, UAVCAN_PROTOCOL_GLOBALTIMESYNC_MAX_SIZE);
    _uavcan_protocol_GlobalTimeSync_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool uavcan_protocol_GlobalTimeSync_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_GlobalTimeSync* msg) {
    uint32_t bit_ofs = 0;
    _uavcan_protocol_GlobalTimeSync_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_GlobalTimeSync sample_uavcan_protocol_GlobalTimeSync_msg(void) {

    struct uavcan_protocol_GlobalTimeSync msg;






    msg.previous_transmission_timestamp_usec = (uint64_t)random_bitlen_unsigned_val(56);





    return msg;

}
#endif