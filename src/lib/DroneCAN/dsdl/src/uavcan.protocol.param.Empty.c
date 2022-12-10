

#define CANARD_DSDLC_INTERNAL
#include <uavcan.protocol.param.Empty.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t uavcan_protocol_param_Empty_encode(struct uavcan_protocol_param_Empty* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, UAVCAN_PROTOCOL_PARAM_EMPTY_MAX_SIZE);
    _uavcan_protocol_param_Empty_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool uavcan_protocol_param_Empty_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_param_Empty* msg) {
    uint32_t bit_ofs = 0;
    _uavcan_protocol_param_Empty_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_param_Empty sample_uavcan_protocol_param_Empty_msg(void) {

    struct uavcan_protocol_param_Empty msg;




    return msg;

}
#endif