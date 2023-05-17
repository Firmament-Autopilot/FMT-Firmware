#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>
#include <uavcan.protocol.HardwareVersion.h>
#include <uavcan.protocol.NodeStatus.h>
#include <uavcan.protocol.SoftwareVersion.h>


#define UAVCAN_PROTOCOL_GETNODEINFO_RESPONSE_MAX_SIZE 377
#define UAVCAN_PROTOCOL_GETNODEINFO_RESPONSE_SIGNATURE (0xEE468A8121C46A9EULL)
#define UAVCAN_PROTOCOL_GETNODEINFO_RESPONSE_ID 1

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class uavcan_protocol_GetNodeInfo_cxx_iface;
#endif

struct uavcan_protocol_GetNodeInfoResponse {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = uavcan_protocol_GetNodeInfo_cxx_iface;
#endif
    struct uavcan_protocol_NodeStatus status;
    struct uavcan_protocol_SoftwareVersion software_version;
    struct uavcan_protocol_HardwareVersion hardware_version;
    struct { uint8_t len; uint8_t data[80]; }name;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t uavcan_protocol_GetNodeInfoResponse_encode(struct uavcan_protocol_GetNodeInfoResponse* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_protocol_GetNodeInfoResponse_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_GetNodeInfoResponse* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _uavcan_protocol_GetNodeInfoResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_GetNodeInfoResponse* msg, bool tao);
static inline void _uavcan_protocol_GetNodeInfoResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_GetNodeInfoResponse* msg, bool tao);
void _uavcan_protocol_GetNodeInfoResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_GetNodeInfoResponse* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    _uavcan_protocol_NodeStatus_encode(buffer, bit_ofs, &msg->status, false);
    _uavcan_protocol_SoftwareVersion_encode(buffer, bit_ofs, &msg->software_version, false);
    _uavcan_protocol_HardwareVersion_encode(buffer, bit_ofs, &msg->hardware_version, false);
    if (!tao) {
        canardEncodeScalar(buffer, *bit_ofs, 7, &msg->name.len);
        *bit_ofs += 7;
    }
    for (size_t i=0; i < msg->name.len; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 8, &msg->name.data[i]);
        *bit_ofs += 8;
    }
}

void _uavcan_protocol_GetNodeInfoResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_GetNodeInfoResponse* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    _uavcan_protocol_NodeStatus_decode(transfer, bit_ofs, &msg->status, false);

    _uavcan_protocol_SoftwareVersion_decode(transfer, bit_ofs, &msg->software_version, false);

    _uavcan_protocol_HardwareVersion_decode(transfer, bit_ofs, &msg->hardware_version, false);

    if (!tao) {
        canardDecodeScalar(transfer, *bit_ofs, 7, false, &msg->name.len);
        *bit_ofs += 7;
    } else {
        msg->name.len = ((transfer->payload_len*8)-*bit_ofs)/8;
    }

    for (size_t i=0; i < msg->name.len; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->name.data[i]);
        *bit_ofs += 8;
    }

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_GetNodeInfoResponse sample_uavcan_protocol_GetNodeInfoResponse_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
#endif
#endif
