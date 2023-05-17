#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define UAVCAN_PROTOCOL_FILE_PATH_MAX_SIZE 201
#define UAVCAN_PROTOCOL_FILE_PATH_SIGNATURE (0x12AEFC50878A43E2ULL)

#define UAVCAN_PROTOCOL_FILE_PATH_SEPARATOR 47


struct uavcan_protocol_file_Path {
    struct { uint8_t len; uint8_t data[200]; }path;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t uavcan_protocol_file_Path_encode(struct uavcan_protocol_file_Path* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_protocol_file_Path_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_file_Path* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _uavcan_protocol_file_Path_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_file_Path* msg, bool tao);
static inline void _uavcan_protocol_file_Path_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_file_Path* msg, bool tao);
void _uavcan_protocol_file_Path_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_file_Path* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    if (!tao) {
        canardEncodeScalar(buffer, *bit_ofs, 8, &msg->path.len);
        *bit_ofs += 8;
    }
    for (size_t i=0; i < msg->path.len; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 8, &msg->path.data[i]);
        *bit_ofs += 8;
    }
}

void _uavcan_protocol_file_Path_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_file_Path* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    if (!tao) {
        canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->path.len);
        *bit_ofs += 8;
    } else {
        msg->path.len = ((transfer->payload_len*8)-*bit_ofs)/8;
    }

    for (size_t i=0; i < msg->path.len; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->path.data[i]);
        *bit_ofs += 8;
    }

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_file_Path sample_uavcan_protocol_file_Path_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
#endif
#endif
