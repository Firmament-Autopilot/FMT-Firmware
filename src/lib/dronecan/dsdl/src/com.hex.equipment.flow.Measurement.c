#define CANARD_DSDLC_INTERNAL
#include <com.hex.equipment.flow.Measurement.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t com_hex_equipment_flow_Measurement_encode(struct com_hex_equipment_flow_Measurement* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, COM_HEX_EQUIPMENT_FLOW_MEASUREMENT_MAX_SIZE);
    _com_hex_equipment_flow_Measurement_encode(buffer, &bit_ofs, msg, 
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
bool com_hex_equipment_flow_Measurement_decode(const CanardRxTransfer* transfer, struct com_hex_equipment_flow_Measurement* msg) {
    uint32_t bit_ofs = 0;
    _com_hex_equipment_flow_Measurement_decode(transfer, &bit_ofs, msg, 
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
struct com_hex_equipment_flow_Measurement sample_com_hex_equipment_flow_Measurement_msg(void) {
    struct com_hex_equipment_flow_Measurement msg;

    msg.integration_interval = random_float_val();
    for (size_t i=0; i < 2; i++) {
        msg.rate_gyro_integral[i] = random_float_val();
    }
    for (size_t i=0; i < 2; i++) {
        msg.flow_integral[i] = random_float_val();
    }
    msg.quality = (uint8_t)random_bitlen_unsigned_val(8);
    return msg;
}
#endif
