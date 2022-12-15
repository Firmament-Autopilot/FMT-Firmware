
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#include <uavcan.protocol.file.Error.h>


#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_PROTOCOL_FILE_WRITE_RESPONSE_MAX_SIZE 2
#define UAVCAN_PROTOCOL_FILE_WRITE_RESPONSE_SIGNATURE (0x515AA1DC77E58429ULL)

#define UAVCAN_PROTOCOL_FILE_WRITE_RESPONSE_ID 49




struct uavcan_protocol_file_WriteResponse {



    struct uavcan_protocol_file_Error error;



};

uint32_t uavcan_protocol_file_WriteResponse_encode(struct uavcan_protocol_file_WriteResponse* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_protocol_file_WriteResponse_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_file_WriteResponse* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_protocol_file_WriteResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_file_WriteResponse* msg, bool tao);
static inline void _uavcan_protocol_file_WriteResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_file_WriteResponse* msg, bool tao);
void _uavcan_protocol_file_WriteResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_file_WriteResponse* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;





    _uavcan_protocol_file_Error_encode(buffer, bit_ofs, &msg->error, tao);





}

void _uavcan_protocol_file_WriteResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_file_WriteResponse* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;





    _uavcan_protocol_file_Error_decode(transfer, bit_ofs, &msg->error, tao);






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_file_WriteResponse sample_uavcan_protocol_file_WriteResponse_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
