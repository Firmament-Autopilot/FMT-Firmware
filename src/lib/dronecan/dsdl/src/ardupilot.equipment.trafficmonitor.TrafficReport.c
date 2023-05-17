#define CANARD_DSDLC_INTERNAL
#include <ardupilot.equipment.trafficmonitor.TrafficReport.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t ardupilot_equipment_trafficmonitor_TrafficReport_encode(struct ardupilot_equipment_trafficmonitor_TrafficReport* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, ARDUPILOT_EQUIPMENT_TRAFFICMONITOR_TRAFFICREPORT_MAX_SIZE);
    _ardupilot_equipment_trafficmonitor_TrafficReport_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

/*
  return true if the decode is invalid
 */
bool ardupilot_equipment_trafficmonitor_TrafficReport_decode(const CanardRxTransfer* transfer, struct ardupilot_equipment_trafficmonitor_TrafficReport* msg) {
    uint32_t bit_ofs = 0;
    _ardupilot_equipment_trafficmonitor_TrafficReport_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    const uint32_t byte_len = (bit_ofs+7U)/8U;
#if CANARD_ENABLE_TAO_OPTION
    // if this could be CANFD then the dlc could indicating more bytes than
    // we actually have
    if (!transfer->tao) {
        return byte_len > transfer->payload_len;
    }
#endif
    return byte_len != transfer->payload_len;
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_equipment_trafficmonitor_TrafficReport sample_ardupilot_equipment_trafficmonitor_TrafficReport_msg(void) {
    struct ardupilot_equipment_trafficmonitor_TrafficReport msg;

    msg.timestamp = sample_uavcan_Timestamp_msg();
    msg.icao_address = (uint32_t)random_bitlen_unsigned_val(32);
    msg.tslc = (uint16_t)random_bitlen_unsigned_val(16);
    msg.latitude_deg_1e7 = (int32_t)random_bitlen_signed_val(32);
    msg.longitude_deg_1e7 = (int32_t)random_bitlen_signed_val(32);
    msg.alt_m = random_float_val();
    msg.heading = random_float16_val();
    for (size_t i=0; i < 3; i++) {
        msg.velocity[i] = random_float16_val();
    }
    msg.squawk = (uint16_t)random_bitlen_unsigned_val(16);
    for (size_t i=0; i < 9; i++) {
        msg.callsign[i] = (uint8_t)random_bitlen_unsigned_val(8);
    }
    msg.source = (uint8_t)random_bitlen_unsigned_val(3);
    msg.traffic_type = (uint8_t)random_bitlen_unsigned_val(5);
    msg.alt_type = (uint8_t)random_bitlen_unsigned_val(7);
    msg.lat_lon_valid = (bool)random_bitlen_unsigned_val(1);
    msg.heading_valid = (bool)random_bitlen_unsigned_val(1);
    msg.velocity_valid = (bool)random_bitlen_unsigned_val(1);
    msg.callsign_valid = (bool)random_bitlen_unsigned_val(1);
    msg.ident_valid = (bool)random_bitlen_unsigned_val(1);
    msg.simulated_report = (bool)random_bitlen_unsigned_val(1);
    msg.vertical_velocity_valid = (bool)random_bitlen_unsigned_val(1);
    msg.baro_valid = (bool)random_bitlen_unsigned_val(1);
    return msg;
}
#endif
