
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_PROTOCOL_RESTARTNODE_RESPONSE_MAX_SIZE 1
#define UAVCAN_PROTOCOL_RESTARTNODE_RESPONSE_SIGNATURE (0x569E05394A3017F0ULL)

#define UAVCAN_PROTOCOL_RESTARTNODE_RESPONSE_ID 5




struct uavcan_protocol_RestartNodeResponse {



    bool ok;



};

uint32_t uavcan_protocol_RestartNodeResponse_encode(struct uavcan_protocol_RestartNodeResponse* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_protocol_RestartNodeResponse_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_RestartNodeResponse* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_protocol_RestartNodeResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_RestartNodeResponse* msg, bool tao);
static inline void _uavcan_protocol_RestartNodeResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_RestartNodeResponse* msg, bool tao);
void _uavcan_protocol_RestartNodeResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_RestartNodeResponse* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->ok);

    *bit_ofs += 1;





}

void _uavcan_protocol_RestartNodeResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_RestartNodeResponse* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->ok);

    *bit_ofs += 1;






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_RestartNodeResponse sample_uavcan_protocol_RestartNodeResponse_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
