
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_REQUEST_MAX_SIZE 95
#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_REQUEST_SIGNATURE (0x196AE06426A3B5D8ULL)

#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_REQUEST_ID 15



#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_REQUEST_TIMEOUT_CANCEL 0

#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_REQUEST_TIMEOUT_INFINITE 65535




struct uavcan_protocol_enumeration_BeginRequest {



    uint16_t timeout_sec;



    struct { uint8_t len; uint8_t data[92]; }parameter_name;



};

uint32_t uavcan_protocol_enumeration_BeginRequest_encode(struct uavcan_protocol_enumeration_BeginRequest* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_protocol_enumeration_BeginRequest_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_enumeration_BeginRequest* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_protocol_enumeration_BeginRequest_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_enumeration_BeginRequest* msg, bool tao);
static inline void _uavcan_protocol_enumeration_BeginRequest_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_enumeration_BeginRequest* msg, bool tao);
void _uavcan_protocol_enumeration_BeginRequest_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_enumeration_BeginRequest* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->timeout_sec);

    *bit_ofs += 16;







    if (!tao) {


        canardEncodeScalar(buffer, *bit_ofs, 7, &msg->parameter_name.len);
        *bit_ofs += 7;


    }

    for (size_t i=0; i < msg->parameter_name.len; i++) {




        canardEncodeScalar(buffer, *bit_ofs, 8, &msg->parameter_name.data[i]);

        *bit_ofs += 8;


    }





}

void _uavcan_protocol_enumeration_BeginRequest_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_enumeration_BeginRequest* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->timeout_sec);

    *bit_ofs += 16;








    if (!tao) {


        canardDecodeScalar(transfer, *bit_ofs, 7, false, &msg->parameter_name.len);
        *bit_ofs += 7;



    } else {

        msg->parameter_name.len = ((transfer->payload_len*8)-*bit_ofs)/8;


    }



    for (size_t i=0; i < msg->parameter_name.len; i++) {




        canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->parameter_name.data[i]);

        *bit_ofs += 8;


    }







}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_enumeration_BeginRequest sample_uavcan_protocol_enumeration_BeginRequest_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
