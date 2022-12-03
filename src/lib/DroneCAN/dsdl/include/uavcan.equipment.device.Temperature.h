
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define UAVCAN_EQUIPMENT_DEVICE_TEMPERATURE_MAX_SIZE 5
#define UAVCAN_EQUIPMENT_DEVICE_TEMPERATURE_SIGNATURE (0x70261C28A94144C6ULL)

#define UAVCAN_EQUIPMENT_DEVICE_TEMPERATURE_ID 1110



#define UAVCAN_EQUIPMENT_DEVICE_TEMPERATURE_ERROR_FLAG_OVERHEATING 1

#define UAVCAN_EQUIPMENT_DEVICE_TEMPERATURE_ERROR_FLAG_OVERCOOLING 2




struct uavcan_equipment_device_Temperature {



    uint16_t device_id;



    float temperature;



    uint8_t error_flags;



};

uint32_t uavcan_equipment_device_Temperature_encode(struct uavcan_equipment_device_Temperature* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool uavcan_equipment_device_Temperature_decode(const CanardRxTransfer* transfer, struct uavcan_equipment_device_Temperature* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _uavcan_equipment_device_Temperature_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_equipment_device_Temperature* msg, bool tao);
static inline void _uavcan_equipment_device_Temperature_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_equipment_device_Temperature* msg, bool tao);
void _uavcan_equipment_device_Temperature_encode(uint8_t* buffer, uint32_t* bit_ofs, struct uavcan_equipment_device_Temperature* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->device_id);

    *bit_ofs += 16;






    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->temperature);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }

    *bit_ofs += 16;






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->error_flags);

    *bit_ofs += 8;





}

void _uavcan_equipment_device_Temperature_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct uavcan_equipment_device_Temperature* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->device_id);

    *bit_ofs += 16;







    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->temperature = canardConvertFloat16ToNativeFloat(float16_val);
    }

    *bit_ofs += 16;







    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->error_flags);

    *bit_ofs += 8;






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct uavcan_equipment_device_Temperature sample_uavcan_equipment_device_Temperature_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
