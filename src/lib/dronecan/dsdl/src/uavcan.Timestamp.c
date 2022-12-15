

#define CANARD_DSDLC_INTERNAL
#include <uavcan.Timestamp.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t uavcan_Timestamp_encode(struct uavcan_Timestamp* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, UAVCAN_TIMESTAMP_MAX_SIZE);
    _uavcan_Timestamp_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool uavcan_Timestamp_decode(const CanardRxTransfer* transfer, struct uavcan_Timestamp* msg) {
    uint32_t bit_ofs = 0;
    _uavcan_Timestamp_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_Timestamp sample_uavcan_Timestamp_msg(void) {

    struct uavcan_Timestamp msg;






    msg.usec = (uint64_t)random_bitlen_unsigned_val(56);





    return msg;

}
#endif