

#define CANARD_DSDLC_INTERNAL
#include <uavcan.equipment.gnss.Auxiliary.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t uavcan_equipment_gnss_Auxiliary_encode(struct uavcan_equipment_gnss_Auxiliary* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, UAVCAN_EQUIPMENT_GNSS_AUXILIARY_MAX_SIZE);
    _uavcan_equipment_gnss_Auxiliary_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool uavcan_equipment_gnss_Auxiliary_decode(const CanardRxTransfer* transfer, struct uavcan_equipment_gnss_Auxiliary* msg) {
    uint32_t bit_ofs = 0;
    _uavcan_equipment_gnss_Auxiliary_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_equipment_gnss_Auxiliary sample_uavcan_equipment_gnss_Auxiliary_msg(void) {

    struct uavcan_equipment_gnss_Auxiliary msg;






    msg.gdop = random_float16_val();







    msg.pdop = random_float16_val();







    msg.hdop = random_float16_val();







    msg.vdop = random_float16_val();







    msg.tdop = random_float16_val();







    msg.ndop = random_float16_val();







    msg.edop = random_float16_val();







    msg.sats_visible = (uint8_t)random_bitlen_unsigned_val(7);







    msg.sats_used = (uint8_t)random_bitlen_unsigned_val(6);





    return msg;

}
#endif