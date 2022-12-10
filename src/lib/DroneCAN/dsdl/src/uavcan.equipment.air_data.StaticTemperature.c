

#define CANARD_DSDLC_INTERNAL
#include <uavcan.equipment.air_data.StaticTemperature.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t uavcan_equipment_air_data_StaticTemperature_encode(struct uavcan_equipment_air_data_StaticTemperature* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, UAVCAN_EQUIPMENT_AIR_DATA_STATICTEMPERATURE_MAX_SIZE);
    _uavcan_equipment_air_data_StaticTemperature_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool uavcan_equipment_air_data_StaticTemperature_decode(const CanardRxTransfer* transfer, struct uavcan_equipment_air_data_StaticTemperature* msg) {
    uint32_t bit_ofs = 0;
    _uavcan_equipment_air_data_StaticTemperature_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_equipment_air_data_StaticTemperature sample_uavcan_equipment_air_data_StaticTemperature_msg(void) {

    struct uavcan_equipment_air_data_StaticTemperature msg;






    msg.static_temperature = random_float16_val();







    msg.static_temperature_variance = random_float16_val();





    return msg;

}
#endif