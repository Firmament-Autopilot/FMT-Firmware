

#define CANARD_DSDLC_INTERNAL
#include <uavcan.equipment.camera_gimbal.Status.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t uavcan_equipment_camera_gimbal_Status_encode(struct uavcan_equipment_camera_gimbal_Status* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, UAVCAN_EQUIPMENT_CAMERA_GIMBAL_STATUS_MAX_SIZE);
    _uavcan_equipment_camera_gimbal_Status_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool uavcan_equipment_camera_gimbal_Status_decode(const CanardRxTransfer* transfer, struct uavcan_equipment_camera_gimbal_Status* msg) {
    uint32_t bit_ofs = 0;
    _uavcan_equipment_camera_gimbal_Status_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_equipment_camera_gimbal_Status sample_uavcan_equipment_camera_gimbal_Status_msg(void) {

    struct uavcan_equipment_camera_gimbal_Status msg;






    msg.gimbal_id = (uint8_t)random_bitlen_unsigned_val(8);






    msg.mode = sample_uavcan_equipment_camera_gimbal_Mode_msg();






    for (size_t i=0; i < 4; i++) {




        msg.camera_orientation_in_body_frame_xyzw[i] = random_float16_val();



    }






    msg.camera_orientation_in_body_frame_covariance.len = (uint8_t)random_range_unsigned_val(0, 9);
    for (size_t i=0; i < msg.camera_orientation_in_body_frame_covariance.len; i++) {




        msg.camera_orientation_in_body_frame_covariance.data[i] = random_float16_val();



    }




    return msg;

}
#endif