#define CANARD_DSDLC_INTERNAL
#include <ardupilot.equipment.power.BatteryInfoAux.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t ardupilot_equipment_power_BatteryInfoAux_encode(struct ardupilot_equipment_power_BatteryInfoAux* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, ARDUPILOT_EQUIPMENT_POWER_BATTERYINFOAUX_MAX_SIZE);
    _ardupilot_equipment_power_BatteryInfoAux_encode(buffer, &bit_ofs, msg, 
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
bool ardupilot_equipment_power_BatteryInfoAux_decode(const CanardRxTransfer* transfer, struct ardupilot_equipment_power_BatteryInfoAux* msg) {
    uint32_t bit_ofs = 0;
    _ardupilot_equipment_power_BatteryInfoAux_decode(transfer, &bit_ofs, msg, 
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
struct ardupilot_equipment_power_BatteryInfoAux sample_ardupilot_equipment_power_BatteryInfoAux_msg(void) {
    struct ardupilot_equipment_power_BatteryInfoAux msg;

    msg.timestamp = sample_uavcan_Timestamp_msg();
    msg.voltage_cell.len = (uint8_t)random_range_unsigned_val(0, 255);
    for (size_t i=0; i < msg.voltage_cell.len; i++) {
        msg.voltage_cell.data[i] = random_float16_val();
    }
    msg.cycle_count = (uint16_t)random_bitlen_unsigned_val(16);
    msg.over_discharge_count = (uint16_t)random_bitlen_unsigned_val(16);
    msg.max_current = random_float16_val();
    msg.nominal_voltage = random_float16_val();
    msg.is_powering_off = (bool)random_bitlen_unsigned_val(1);
    msg.battery_id = (uint8_t)random_bitlen_unsigned_val(8);
    return msg;
}
#endif
