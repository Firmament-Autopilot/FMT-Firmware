#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>
#include <uavcan.Timestamp.h>


#define ARDUPILOT_EQUIPMENT_POWER_BATTERYINFOAUX_MAX_SIZE 528
#define ARDUPILOT_EQUIPMENT_POWER_BATTERYINFOAUX_SIGNATURE (0x7D7F49FC75484882ULL)
#define ARDUPILOT_EQUIPMENT_POWER_BATTERYINFOAUX_ID 20004

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class ardupilot_equipment_power_BatteryInfoAux_cxx_iface;
#endif

struct ardupilot_equipment_power_BatteryInfoAux {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = ardupilot_equipment_power_BatteryInfoAux_cxx_iface;
#endif
    struct uavcan_Timestamp timestamp;
    struct { uint8_t len; float data[255]; }voltage_cell;
    uint16_t cycle_count;
    uint16_t over_discharge_count;
    float max_current;
    float nominal_voltage;
    bool is_powering_off;
    uint8_t battery_id;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t ardupilot_equipment_power_BatteryInfoAux_encode(struct ardupilot_equipment_power_BatteryInfoAux* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool ardupilot_equipment_power_BatteryInfoAux_decode(const CanardRxTransfer* transfer, struct ardupilot_equipment_power_BatteryInfoAux* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _ardupilot_equipment_power_BatteryInfoAux_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_equipment_power_BatteryInfoAux* msg, bool tao);
static inline void _ardupilot_equipment_power_BatteryInfoAux_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_equipment_power_BatteryInfoAux* msg, bool tao);
void _ardupilot_equipment_power_BatteryInfoAux_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_equipment_power_BatteryInfoAux* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    _uavcan_Timestamp_encode(buffer, bit_ofs, &msg->timestamp, false);
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->voltage_cell.len);
    *bit_ofs += 8;
    for (size_t i=0; i < msg->voltage_cell.len; i++) {
        {
            uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->voltage_cell.data[i]);
            canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
        }
        *bit_ofs += 16;
    }
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->cycle_count);
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->over_discharge_count);
    *bit_ofs += 16;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->max_current);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->nominal_voltage);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->is_powering_off);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->battery_id);
    *bit_ofs += 8;
}

void _ardupilot_equipment_power_BatteryInfoAux_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_equipment_power_BatteryInfoAux* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    _uavcan_Timestamp_decode(transfer, bit_ofs, &msg->timestamp, false);

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->voltage_cell.len);
    *bit_ofs += 8;
    for (size_t i=0; i < msg->voltage_cell.len; i++) {
        {
            uint16_t float16_val;
            canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
            msg->voltage_cell.data[i] = canardConvertFloat16ToNativeFloat(float16_val);
        }
        *bit_ofs += 16;
    }

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->cycle_count);
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->over_discharge_count);
    *bit_ofs += 16;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->max_current = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->nominal_voltage = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->is_powering_off);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->battery_id);
    *bit_ofs += 8;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_equipment_power_BatteryInfoAux sample_ardupilot_equipment_power_BatteryInfoAux_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(ardupilot_equipment_power_BatteryInfoAux, ARDUPILOT_EQUIPMENT_POWER_BATTERYINFOAUX_ID, ARDUPILOT_EQUIPMENT_POWER_BATTERYINFOAUX_SIGNATURE, ARDUPILOT_EQUIPMENT_POWER_BATTERYINFOAUX_MAX_SIZE);
#endif
#endif
