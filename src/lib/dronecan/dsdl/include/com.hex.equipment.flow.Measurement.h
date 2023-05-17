#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define COM_HEX_EQUIPMENT_FLOW_MEASUREMENT_MAX_SIZE 21
#define COM_HEX_EQUIPMENT_FLOW_MEASUREMENT_SIGNATURE (0x6A908866BCB49C18ULL)
#define COM_HEX_EQUIPMENT_FLOW_MEASUREMENT_ID 20200

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class com_hex_equipment_flow_Measurement_cxx_iface;
#endif

struct com_hex_equipment_flow_Measurement {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = com_hex_equipment_flow_Measurement_cxx_iface;
#endif
    float integration_interval;
    float rate_gyro_integral[2];
    float flow_integral[2];
    uint8_t quality;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t com_hex_equipment_flow_Measurement_encode(struct com_hex_equipment_flow_Measurement* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool com_hex_equipment_flow_Measurement_decode(const CanardRxTransfer* transfer, struct com_hex_equipment_flow_Measurement* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _com_hex_equipment_flow_Measurement_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_hex_equipment_flow_Measurement* msg, bool tao);
static inline void _com_hex_equipment_flow_Measurement_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_hex_equipment_flow_Measurement* msg, bool tao);
void _com_hex_equipment_flow_Measurement_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_hex_equipment_flow_Measurement* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->integration_interval);
    *bit_ofs += 32;
    for (size_t i=0; i < 2; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 32, &msg->rate_gyro_integral[i]);
        *bit_ofs += 32;
    }
    for (size_t i=0; i < 2; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 32, &msg->flow_integral[i]);
        *bit_ofs += 32;
    }
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->quality);
    *bit_ofs += 8;
}

void _com_hex_equipment_flow_Measurement_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_hex_equipment_flow_Measurement* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->integration_interval);
    *bit_ofs += 32;

    for (size_t i=0; i < 2; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->rate_gyro_integral[i]);
        *bit_ofs += 32;
    }

    for (size_t i=0; i < 2; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->flow_integral[i]);
        *bit_ofs += 32;
    }

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->quality);
    *bit_ofs += 8;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct com_hex_equipment_flow_Measurement sample_com_hex_equipment_flow_Measurement_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(com_hex_equipment_flow_Measurement, COM_HEX_EQUIPMENT_FLOW_MEASUREMENT_ID, COM_HEX_EQUIPMENT_FLOW_MEASUREMENT_SIGNATURE, COM_HEX_EQUIPMENT_FLOW_MEASUREMENT_MAX_SIZE);
#endif
#endif
