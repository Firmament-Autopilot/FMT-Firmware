#define CANARD_DSDLC_INTERNAL
#include <cuav.equipment.power.CBAT.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t cuav_equipment_power_CBAT_encode(struct cuav_equipment_power_CBAT* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, CUAV_EQUIPMENT_POWER_CBAT_MAX_SIZE);
    _cuav_equipment_power_CBAT_encode(buffer, &bit_ofs, msg, 
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
bool cuav_equipment_power_CBAT_decode(const CanardRxTransfer* transfer, struct cuav_equipment_power_CBAT* msg) {
    uint32_t bit_ofs = 0;
    _cuav_equipment_power_CBAT_decode(transfer, &bit_ofs, msg, 
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
struct cuav_equipment_power_CBAT sample_cuav_equipment_power_CBAT_msg(void) {
    struct cuav_equipment_power_CBAT msg;

    msg.temperature = random_float_val();
    msg.voltage = random_float_val();
    msg.voltage_cell.len = (uint8_t)random_range_unsigned_val(0, 15);
    for (size_t i=0; i < msg.voltage_cell.len; i++) {
        msg.voltage_cell.data[i] = random_float_val();
    }
    msg.cell_count = (uint8_t)random_bitlen_unsigned_val(8);
    msg.current = random_float_val();
    msg.average_current = random_float_val();
    msg.average_power = random_float_val();
    msg.available_energy = random_float_val();
    msg.remaining_capacity = random_float_val();
    msg.full_charge_capacity = random_float_val();
    msg.design_capacity = random_float_val();
    msg.average_time_to_empty = (uint16_t)random_bitlen_unsigned_val(16);
    msg.average_time_to_full = (uint16_t)random_bitlen_unsigned_val(16);
    msg.state_of_health = (uint8_t)random_bitlen_unsigned_val(7);
    msg.state_of_charge = (uint8_t)random_bitlen_unsigned_val(7);
    msg.max_error = (uint8_t)random_bitlen_unsigned_val(7);
    msg.serial_number = (uint16_t)random_bitlen_unsigned_val(16);
    msg.manufacture_date = (uint16_t)random_bitlen_unsigned_val(16);
    msg.cycle_count = (uint16_t)random_bitlen_unsigned_val(16);
    msg.over_discharge_count = (uint16_t)random_bitlen_unsigned_val(16);
    msg.passed_charge = random_float_val();
    msg.nominal_voltage = random_float_val();
    msg.is_powering_off = (bool)random_bitlen_unsigned_val(1);
    msg.interface_error = (uint16_t)random_bitlen_unsigned_val(16);
    msg.status_flags = (uint16_t)random_bitlen_unsigned_val(11);
    return msg;
}
#endif
