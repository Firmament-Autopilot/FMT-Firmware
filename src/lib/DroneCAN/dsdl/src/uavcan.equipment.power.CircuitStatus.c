

#define CANARD_DSDLC_INTERNAL
#include <uavcan.equipment.power.CircuitStatus.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t uavcan_equipment_power_CircuitStatus_encode(struct uavcan_equipment_power_CircuitStatus* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS_MAX_SIZE);
    _uavcan_equipment_power_CircuitStatus_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool uavcan_equipment_power_CircuitStatus_decode(const CanardRxTransfer* transfer, struct uavcan_equipment_power_CircuitStatus* msg) {
    uint32_t bit_ofs = 0;
    _uavcan_equipment_power_CircuitStatus_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_equipment_power_CircuitStatus sample_uavcan_equipment_power_CircuitStatus_msg(void) {

    struct uavcan_equipment_power_CircuitStatus msg;






    msg.circuit_id = (uint16_t)random_bitlen_unsigned_val(16);







    msg.voltage = random_float16_val();







    msg.current = random_float16_val();







    msg.error_flags = (uint8_t)random_bitlen_unsigned_val(8);





    return msg;

}
#endif