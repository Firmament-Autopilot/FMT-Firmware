
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#include <uavcan.protocol.file.EntryType.h>

#include <uavcan.protocol.file.Error.h>


#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_PROTOCOL_FILE_GETINFO_RESPONSE_MAX_SIZE 8
#define UAVCAN_PROTOCOL_FILE_GETINFO_RESPONSE_SIGNATURE (0x5004891EE8A27531ULL)

#define UAVCAN_PROTOCOL_FILE_GETINFO_RESPONSE_ID 45




struct uavcan_protocol_file_GetInfoResponse {



    uint64_t size;



    struct uavcan_protocol_file_Error error;



    struct uavcan_protocol_file_EntryType entry_type;



};

uint32_t uavcan_protocol_file_GetInfoResponse_encode(struct uavcan_protocol_file_GetInfoResponse* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_protocol_file_GetInfoResponse_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_file_GetInfoResponse* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_protocol_file_GetInfoResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_file_GetInfoResponse* msg, bool tao);
static inline void _uavcan_protocol_file_GetInfoResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_file_GetInfoResponse* msg, bool tao);
void _uavcan_protocol_file_GetInfoResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_file_GetInfoResponse* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardEncodeScalar(buffer, *bit_ofs, 40, &msg->size);

    *bit_ofs += 40;





    _uavcan_protocol_file_Error_encode(buffer, bit_ofs, &msg->error, false);





    _uavcan_protocol_file_EntryType_encode(buffer, bit_ofs, &msg->entry_type, tao);





}

void _uavcan_protocol_file_GetInfoResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_file_GetInfoResponse* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardDecodeScalar(transfer, *bit_ofs, 40, false, &msg->size);

    *bit_ofs += 40;






    _uavcan_protocol_file_Error_decode(transfer, bit_ofs, &msg->error, false);






    _uavcan_protocol_file_EntryType_decode(transfer, bit_ofs, &msg->entry_type, tao);






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_file_GetInfoResponse sample_uavcan_protocol_file_GetInfoResponse_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
