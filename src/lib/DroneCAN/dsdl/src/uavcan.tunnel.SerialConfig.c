

#define CANARD_DSDLC_INTERNAL
#include <uavcan.tunnel.SerialConfig.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t uavcan_tunnel_SerialConfig_encode(struct uavcan_tunnel_SerialConfig* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, UAVCAN_TUNNEL_SERIALCONFIG_MAX_SIZE);
    _uavcan_tunnel_SerialConfig_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool uavcan_tunnel_SerialConfig_decode(const CanardRxTransfer* transfer, struct uavcan_tunnel_SerialConfig* msg) {
    uint32_t bit_ofs = 0;
    _uavcan_tunnel_SerialConfig_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_tunnel_SerialConfig sample_uavcan_tunnel_SerialConfig_msg(void) {

    struct uavcan_tunnel_SerialConfig msg;






    msg.channel_id = (uint8_t)random_bitlen_unsigned_val(8);







    msg.baud = (uint32_t)random_bitlen_unsigned_val(32);







    msg.options = (uint32_t)random_bitlen_unsigned_val(24);





    return msg;

}
#endif