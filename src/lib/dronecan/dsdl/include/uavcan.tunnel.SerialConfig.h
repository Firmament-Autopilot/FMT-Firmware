
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_TUNNEL_SERIALCONFIG_MAX_SIZE 8
#define UAVCAN_TUNNEL_SERIALCONFIG_SIGNATURE (0x4237AACEE87E82ADULL)

#define UAVCAN_TUNNEL_SERIALCONFIG_ID 2011




struct uavcan_tunnel_SerialConfig {



    uint8_t channel_id;



    uint32_t baud;



    uint32_t options;



};

uint32_t uavcan_tunnel_SerialConfig_encode(struct uavcan_tunnel_SerialConfig* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_tunnel_SerialConfig_decode(const CanardRxTransfer* transfer, struct uavcan_tunnel_SerialConfig* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_tunnel_SerialConfig_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_tunnel_SerialConfig* msg, bool tao);
static inline void _uavcan_tunnel_SerialConfig_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_tunnel_SerialConfig* msg, bool tao);
void _uavcan_tunnel_SerialConfig_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_tunnel_SerialConfig* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->channel_id);

    *bit_ofs += 8;






    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->baud);

    *bit_ofs += 32;






    canardEncodeScalar(buffer, *bit_ofs, 24, &msg->options);

    *bit_ofs += 24;





}

void _uavcan_tunnel_SerialConfig_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_tunnel_SerialConfig* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->channel_id);

    *bit_ofs += 8;







    canardDecodeScalar(transfer, *bit_ofs, 32, false, &msg->baud);

    *bit_ofs += 32;







    canardDecodeScalar(transfer, *bit_ofs, 24, false, &msg->options);

    *bit_ofs += 24;






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_tunnel_SerialConfig sample_uavcan_tunnel_SerialConfig_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
