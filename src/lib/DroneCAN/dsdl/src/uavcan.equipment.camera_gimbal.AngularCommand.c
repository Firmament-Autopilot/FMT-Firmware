

#define CANARD_DSDLC_INTERNAL
#include <uavcan.equipment.camera_gimbal.AngularCommand.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t uavcan_equipment_camera_gimbal_AngularCommand_encode(struct uavcan_equipment_camera_gimbal_AngularCommand* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, UAVCAN_EQUIPMENT_CAMERA_GIMBAL_ANGULARCOMMAND_MAX_SIZE);
    _uavcan_equipment_camera_gimbal_AngularCommand_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool uavcan_equipment_camera_gimbal_AngularCommand_decode(const CanardRxTransfer* transfer, struct uavcan_equipment_camera_gimbal_AngularCommand* msg) {
    uint32_t bit_ofs = 0;
    _uavcan_equipment_camera_gimbal_AngularCommand_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_equipment_camera_gimbal_AngularCommand sample_uavcan_equipment_camera_gimbal_AngularCommand_msg(void) {

    struct uavcan_equipment_camera_gimbal_AngularCommand msg;






    msg.gimbal_id = (uint8_t)random_bitlen_unsigned_val(8);






    msg.mode = sample_uavcan_equipment_camera_gimbal_Mode_msg();






    for (size_t i=0; i < 4; i++) {




        msg.quaternion_xyzw[i] = random_float16_val();



    }




    return msg;

}
#endif