
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#include <uavcan.tunnel.Protocol.h>


#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_TUNNEL_BROADCAST_MAX_SIZE 63
#define UAVCAN_TUNNEL_BROADCAST_SIGNATURE (0x5AA2D4D9CF4B1E85ULL)

#define UAVCAN_TUNNEL_BROADCAST_ID 2010




struct uavcan_tunnel_Broadcast {



    struct uavcan_tunnel_Protocol protocol;



    uint8_t channel_id;



    struct { uint8_t len; uint8_t data[60]; }buffer;



};

uint32_t uavcan_tunnel_Broadcast_encode(struct uavcan_tunnel_Broadcast* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_tunnel_Broadcast_decode(const CanardRxTransfer* transfer, struct uavcan_tunnel_Broadcast* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_tunnel_Broadcast_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_tunnel_Broadcast* msg, bool tao);
static inline void _uavcan_tunnel_Broadcast_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_tunnel_Broadcast* msg, bool tao);
void _uavcan_tunnel_Broadcast_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_tunnel_Broadcast* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;





    _uavcan_tunnel_Protocol_encode(buffer, bit_ofs, &msg->protocol, false);






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->channel_id);

    *bit_ofs += 8;







    if (!tao) {


        canardEncodeScalar(buffer, *bit_ofs, 6, &msg->buffer.len);
        *bit_ofs += 6;


    }

    for (size_t i=0; i < msg->buffer.len; i++) {




        canardEncodeScalar(buffer, *bit_ofs, 8, &msg->buffer.data[i]);

        *bit_ofs += 8;


    }





}

void _uavcan_tunnel_Broadcast_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_tunnel_Broadcast* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;





    _uavcan_tunnel_Protocol_decode(transfer, bit_ofs, &msg->protocol, false);







    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->channel_id);

    *bit_ofs += 8;








    if (!tao) {


        canardDecodeScalar(transfer, *bit_ofs, 6, false, &msg->buffer.len);
        *bit_ofs += 6;



    } else {

        msg->buffer.len = ((transfer->payload_len*8)-*bit_ofs)/8;


    }



    for (size_t i=0; i < msg->buffer.len; i++) {




        canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->buffer.data[i]);

        *bit_ofs += 8;


    }







}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_tunnel_Broadcast sample_uavcan_tunnel_Broadcast_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
