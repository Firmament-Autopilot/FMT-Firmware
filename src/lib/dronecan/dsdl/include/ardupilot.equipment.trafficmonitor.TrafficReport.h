#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>
#include <uavcan.Timestamp.h>


#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_MAX_SIZE 47
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_SIGNATURE (0x68E45DB60B6981F8ULL)
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_ID 20790

#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_SOURCE_ADSB 0
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_SOURCE_ADSB_UAT 1
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_SOURCE_FLARM 2
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_UNKNOWN 0
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_LIGHT 1
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_SMALL 2
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_LARGE 3
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_HIGH_VORTEX_LARGE 4
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_HEAVY 5
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_HIGHLY_MANUV 6
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_ROTOCRAFT 7
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_GLIDER 9
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_LIGHTER_THAN_AIR 10
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_PARACHUTE 11
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_ULTRA_LIGHT 12
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_UAV 14
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_SPACE 15
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_EMERGENCY_SURFACE 17
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_SERVICE_SURFACE 18
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_TRAFFIC_TYPE_POINT_OBSTACLE 19
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_ALT_TYPE_ALT_UNKNOWN 0
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_ALT_TYPE_PRESSURE_AMSL 1
#define ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_ALT_TYPE_WGS84 2

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class ardupilot_equipment_trafficmonitor_TrafficReport_cxx_iface;
#endif

struct ardupilot_equipment_trafficmonitor_TrafficReport {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = ardupilot_equipment_trafficmonitor_TrafficReport_cxx_iface;
#endif
    struct uavcan_Timestamp timestamp;
    uint32_t icao_address;
    uint16_t tslc;
    int32_t latitude_deg_1e7;
    int32_t longitude_deg_1e7;
    float alt_m;
    float heading;
    float velocity[3];
    uint16_t squawk;
    uint8_t callsign[9];
    uint8_t source;
    uint8_t traffic_type;
    uint8_t alt_type;
    bool lat_lon_valid;
    bool heading_valid;
    bool velocity_valid;
    bool callsign_valid;
    bool ident_valid;
    bool simulated_report;
    bool vertical_velocity_valid;
    bool baro_valid;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t ardupilot_equipment_trafficmonitor_TrafficReport_encode(struct ardupilot_equipment_trafficmonitor_TrafficReport* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool ardupilot_equipment_trafficmonitor_TrafficReport_decode(const CanardRxTransfer* transfer, struct ardupilot_equipment_trafficmonitor_TrafficReport* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _ardupilot_equipment_trafficmonitor_TrafficReport_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_equipment_trafficmonitor_TrafficReport* msg, bool tao);
static inline void _ardupilot_equipment_trafficmonitor_TrafficReport_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_equipment_trafficmonitor_TrafficReport* msg, bool tao);
void _ardupilot_equipment_trafficmonitor_TrafficReport_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_equipment_trafficmonitor_TrafficReport* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    _uavcan_Timestamp_encode(buffer, bit_ofs, &msg->timestamp, false);
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->icao_address);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->tslc);
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->latitude_deg_1e7);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->longitude_deg_1e7);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->alt_m);
    *bit_ofs += 32;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->heading);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    for (size_t i=0; i < 3; i++) {
        {
            uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->velocity[i]);
            canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
        }
        *bit_ofs += 16;
    }
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->squawk);
    *bit_ofs += 16;
    for (size_t i=0; i < 9; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 8, &msg->callsign[i]);
        *bit_ofs += 8;
    }
    canardEncodeScalar(buffer, *bit_ofs, 3, &msg->source);
    *bit_ofs += 3;
    canardEncodeScalar(buffer, *bit_ofs, 5, &msg->traffic_type);
    *bit_ofs += 5;
    canardEncodeScalar(buffer, *bit_ofs, 7, &msg->alt_type);
    *bit_ofs += 7;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->lat_lon_valid);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->heading_valid);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->velocity_valid);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->callsign_valid);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->ident_valid);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->simulated_report);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->vertical_velocity_valid);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->baro_valid);
    *bit_ofs += 1;
}

void _ardupilot_equipment_trafficmonitor_TrafficReport_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_equipment_trafficmonitor_TrafficReport* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    _uavcan_Timestamp_decode(transfer, bit_ofs, &msg->timestamp, false);

    canardDecodeScalar(transfer, *bit_ofs, 32, false, &msg->icao_address);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->tslc);
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->latitude_deg_1e7);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->longitude_deg_1e7);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->alt_m);
    *bit_ofs += 32;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->heading = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    for (size_t i=0; i < 3; i++) {
        {
            uint16_t float16_val;
            canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
            msg->velocity[i] = canardConvertFloat16ToNativeFloat(float16_val);
        }
        *bit_ofs += 16;
    }

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->squawk);
    *bit_ofs += 16;

    for (size_t i=0; i < 9; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->callsign[i]);
        *bit_ofs += 8;
    }

    canardDecodeScalar(transfer, *bit_ofs, 3, false, &msg->source);
    *bit_ofs += 3;

    canardDecodeScalar(transfer, *bit_ofs, 5, false, &msg->traffic_type);
    *bit_ofs += 5;

    canardDecodeScalar(transfer, *bit_ofs, 7, false, &msg->alt_type);
    *bit_ofs += 7;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->lat_lon_valid);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->heading_valid);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->velocity_valid);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->callsign_valid);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->ident_valid);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->simulated_report);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->vertical_velocity_valid);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->baro_valid);
    *bit_ofs += 1;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_equipment_trafficmonitor_TrafficReport sample_ardupilot_equipment_trafficmonitor_TrafficReport_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(ardupilot_equipment_trafficmonitor_TrafficReport, ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_ID, ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_SIGNATURE, ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_MAX_SIZE);
#endif
#endif
