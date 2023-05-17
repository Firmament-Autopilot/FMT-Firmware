#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define ARDUPILOT_EQUIPMENT_PROXIMITY_SENSOR_PROXIMITY_MAX_SIZE 8
#define ARDUPILOT_EQUIPMENT_PROXIMITY_SENSOR_PROXIMITY_SIGNATURE (0x99DD3985FB3222CEULL)
#define ARDUPILOT_EQUIPMENT_PROXIMITY_SENSOR_PROXIMITY_ID 21910

#define ARDUPILOT_EQUIPMENT_PROXIMITY_SENSOR_PROXIMITY_READING_TYPE_NO_DATA 0
#define ARDUPILOT_EQUIPMENT_PROXIMITY_SENSOR_PROXIMITY_READING_TYPE_NOT_CONNECTED 1
#define ARDUPILOT_EQUIPMENT_PROXIMITY_SENSOR_PROXIMITY_READING_TYPE_GOOD 2
#define ARDUPILOT_EQUIPMENT_PROXIMITY_SENSOR_PROXIMITY_FLAGS_NONE 0

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class ardupilot_equipment_proximity_sensor_Proximity_cxx_iface;
#endif

struct ardupilot_equipment_proximity_sensor_Proximity {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = ardupilot_equipment_proximity_sensor_Proximity_cxx_iface;
#endif
    uint8_t sensor_id;
    uint8_t reading_type;
    uint8_t flags;
    float yaw;
    float pitch;
    float distance;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t ardupilot_equipment_proximity_sensor_Proximity_encode(struct ardupilot_equipment_proximity_sensor_Proximity* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool ardupilot_equipment_proximity_sensor_Proximity_decode(const CanardRxTransfer* transfer, struct ardupilot_equipment_proximity_sensor_Proximity* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _ardupilot_equipment_proximity_sensor_Proximity_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_equipment_proximity_sensor_Proximity* msg, bool tao);
static inline void _ardupilot_equipment_proximity_sensor_Proximity_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_equipment_proximity_sensor_Proximity* msg, bool tao);
void _ardupilot_equipment_proximity_sensor_Proximity_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_equipment_proximity_sensor_Proximity* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->sensor_id);
    *bit_ofs += 8;
    canardEncodeScalar(buffer, *bit_ofs, 3, &msg->reading_type);
    *bit_ofs += 3;
    canardEncodeScalar(buffer, *bit_ofs, 5, &msg->flags);
    *bit_ofs += 5;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->yaw);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->pitch);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->distance);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }
    *bit_ofs += 16;
}

void _ardupilot_equipment_proximity_sensor_Proximity_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_equipment_proximity_sensor_Proximity* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->sensor_id);
    *bit_ofs += 8;

    canardDecodeScalar(transfer, *bit_ofs, 3, false, &msg->reading_type);
    *bit_ofs += 3;

    canardDecodeScalar(transfer, *bit_ofs, 5, false, &msg->flags);
    *bit_ofs += 5;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->yaw = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->pitch = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->distance = canardConvertFloat16ToNativeFloat(float16_val);
    }
    *bit_ofs += 16;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_equipment_proximity_sensor_Proximity sample_ardupilot_equipment_proximity_sensor_Proximity_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(ardupilot_equipment_proximity_sensor_Proximity, ARDUPILOT_EQUIPMENT_PROXIMITY_SENSOR_PROXIMITY_ID, ARDUPILOT_EQUIPMENT_PROXIMITY_SENSOR_PROXIMITY_SIGNATURE, ARDUPILOT_EQUIPMENT_PROXIMITY_SENSOR_PROXIMITY_MAX_SIZE);
#endif
#endif
