
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_REQUEST_MAX_SIZE 0
#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_REQUEST_SIGNATURE (0xBE6F76A7EC312B04ULL)

#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_REQUEST_ID 4




struct uavcan_protocol_GetTransportStatsRequest {



};

uint32_t uavcan_protocol_GetTransportStatsRequest_encode(struct uavcan_protocol_GetTransportStatsRequest* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_protocol_GetTransportStatsRequest_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_GetTransportStatsRequest* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_protocol_GetTransportStatsRequest_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_GetTransportStatsRequest* msg, bool tao);
static inline void _uavcan_protocol_GetTransportStatsRequest_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_GetTransportStatsRequest* msg, bool tao);
void _uavcan_protocol_GetTransportStatsRequest_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_GetTransportStatsRequest* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;





}

void _uavcan_protocol_GetTransportStatsRequest_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_GetTransportStatsRequest* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;





}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_GetTransportStatsRequest sample_uavcan_protocol_GetTransportStatsRequest_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
