
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_MAX_SIZE 7
#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_SIGNATURE (0x20271116A793C2DBULL)

#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_ID 4



#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_MAX_BROADCASTING_PERIOD_MS 1100

#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_MIN_BROADCASTING_PERIOD_MS 40

#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_RECOMMENDED_BROADCASTER_TIMEOUT_MS 2200




struct uavcan_protocol_GlobalTimeSync {



    uint64_t previous_transmission_timestamp_usec;



};

uint32_t uavcan_protocol_GlobalTimeSync_encode(struct uavcan_protocol_GlobalTimeSync* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_protocol_GlobalTimeSync_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_GlobalTimeSync* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_protocol_GlobalTimeSync_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_GlobalTimeSync* msg, bool tao);
static inline void _uavcan_protocol_GlobalTimeSync_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_GlobalTimeSync* msg, bool tao);
void _uavcan_protocol_GlobalTimeSync_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_GlobalTimeSync* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardEncodeScalar(buffer, *bit_ofs, 56, &msg->previous_transmission_timestamp_usec);

    *bit_ofs += 56;





}

void _uavcan_protocol_GlobalTimeSync_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_GlobalTimeSync* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardDecodeScalar(transfer, *bit_ofs, 56, false, &msg->previous_transmission_timestamp_usec);

    *bit_ofs += 56;






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_GlobalTimeSync sample_uavcan_protocol_GlobalTimeSync_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
