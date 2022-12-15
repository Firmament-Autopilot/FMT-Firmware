

#define CANARD_DSDLC_INTERNAL
#include <uavcan.equipment.camera_gimbal.GEOPOICommand.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t uavcan_equipment_camera_gimbal_GEOPOICommand_encode(struct uavcan_equipment_camera_gimbal_GEOPOICommand* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, UAVCAN_EQUIPMENT_CAMERA_GIMBAL_GEOPOICOMMAND_MAX_SIZE);
    _uavcan_equipment_camera_gimbal_GEOPOICommand_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool uavcan_equipment_camera_gimbal_GEOPOICommand_decode(const CanardRxTransfer* transfer, struct uavcan_equipment_camera_gimbal_GEOPOICommand* msg) {
    uint32_t bit_ofs = 0;
    _uavcan_equipment_camera_gimbal_GEOPOICommand_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_equipment_camera_gimbal_GEOPOICommand sample_uavcan_equipment_camera_gimbal_GEOPOICommand_msg(void) {

    struct uavcan_equipment_camera_gimbal_GEOPOICommand msg;






    msg.gimbal_id = (uint8_t)random_bitlen_unsigned_val(8);






    msg.mode = sample_uavcan_equipment_camera_gimbal_Mode_msg();






    msg.longitude_deg_1e7 = (int32_t)random_bitlen_signed_val(32);







    msg.latitude_deg_1e7 = (int32_t)random_bitlen_signed_val(32);







    msg.height_cm = (int32_t)random_bitlen_signed_val(22);







    msg.height_reference = (uint8_t)random_bitlen_unsigned_val(2);





    return msg;

}
#endif