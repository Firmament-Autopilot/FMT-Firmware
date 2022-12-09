
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#include <uavcan.protocol.file.Error.h>


#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_PROTOCOL_FILE_DELETE_RESPONSE_MAX_SIZE 2
#define UAVCAN_PROTOCOL_FILE_DELETE_RESPONSE_SIGNATURE (0x78648C99170B47AAULL)

#define UAVCAN_PROTOCOL_FILE_DELETE_RESPONSE_ID 47




struct uavcan_protocol_file_DeleteResponse {



    struct uavcan_protocol_file_Error error;



};

uint32_t uavcan_protocol_file_DeleteResponse_encode(struct uavcan_protocol_file_DeleteResponse* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_protocol_file_DeleteResponse_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_file_DeleteResponse* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_protocol_file_DeleteResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_file_DeleteResponse* msg, bool tao);
static inline void _uavcan_protocol_file_DeleteResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_file_DeleteResponse* msg, bool tao);
void _uavcan_protocol_file_DeleteResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_file_DeleteResponse* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;





    _uavcan_protocol_file_Error_encode(buffer, bit_ofs, &msg->error, tao);





}

void _uavcan_protocol_file_DeleteResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_file_DeleteResponse* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;





    _uavcan_protocol_file_Error_decode(transfer, bit_ofs, &msg->error, tao);






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_file_DeleteResponse sample_uavcan_protocol_file_DeleteResponse_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
