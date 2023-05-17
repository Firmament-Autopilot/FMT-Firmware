#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>
#include <uavcan.protocol.CANIfaceStats.h>


#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_RESPONSE_MAX_SIZE 73
#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_RESPONSE_SIGNATURE (0xBE6F76A7EC312B04ULL)
#define UAVCAN_PROTOCOL_GETTRANSPORTSTATS_RESPONSE_ID 4

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class uavcan_protocol_GetTransportStats_cxx_iface;
#endif

struct uavcan_protocol_GetTransportStatsResponse {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = uavcan_protocol_GetTransportStats_cxx_iface;
#endif
    uint64_t transfers_tx;
    uint64_t transfers_rx;
    uint64_t transfer_errors;
    struct { uint8_t len; struct uavcan_protocol_CANIfaceStats data[3]; }can_iface_stats;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t uavcan_protocol_GetTransportStatsResponse_encode(struct uavcan_protocol_GetTransportStatsResponse* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_protocol_GetTransportStatsResponse_decode(const CanardRxTransfer* transfer, struct uavcan_protocol_GetTransportStatsResponse* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _uavcan_protocol_GetTransportStatsResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_GetTransportStatsResponse* msg, bool tao);
static inline void _uavcan_protocol_GetTransportStatsResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_GetTransportStatsResponse* msg, bool tao);
void _uavcan_protocol_GetTransportStatsResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_protocol_GetTransportStatsResponse* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 48, &msg->transfers_tx);
    *bit_ofs += 48;
    canardEncodeScalar(buffer, *bit_ofs, 48, &msg->transfers_rx);
    *bit_ofs += 48;
    canardEncodeScalar(buffer, *bit_ofs, 48, &msg->transfer_errors);
    *bit_ofs += 48;
    if (!tao) {
        canardEncodeScalar(buffer, *bit_ofs, 2, &msg->can_iface_stats.len);
        *bit_ofs += 2;
    }
    for (size_t i=0; i < msg->can_iface_stats.len; i++) {
        _uavcan_protocol_CANIfaceStats_encode(buffer, bit_ofs, &msg->can_iface_stats.data[i], false);
    }
}

void _uavcan_protocol_GetTransportStatsResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_protocol_GetTransportStatsResponse* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardDecodeScalar(transfer, *bit_ofs, 48, false, &msg->transfers_tx);
    *bit_ofs += 48;

    canardDecodeScalar(transfer, *bit_ofs, 48, false, &msg->transfers_rx);
    *bit_ofs += 48;

    canardDecodeScalar(transfer, *bit_ofs, 48, false, &msg->transfer_errors);
    *bit_ofs += 48;

    if (!tao) {
        canardDecodeScalar(transfer, *bit_ofs, 2, false, &msg->can_iface_stats.len);
        *bit_ofs += 2;
    }


    if (tao) {
        msg->can_iface_stats.len = 0;
        while ((transfer->payload_len*8) > *bit_ofs) {
            _uavcan_protocol_CANIfaceStats_decode(transfer, bit_ofs, &msg->can_iface_stats.data[msg->can_iface_stats.len], false);
            msg->can_iface_stats.len++;
        }
    } else {
        for (size_t i=0; i < msg->can_iface_stats.len; i++) {
            _uavcan_protocol_CANIfaceStats_decode(transfer, bit_ofs, &msg->can_iface_stats.data[i], false);
        }
    }

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_protocol_GetTransportStatsResponse sample_uavcan_protocol_GetTransportStatsResponse_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
#endif
#endif
