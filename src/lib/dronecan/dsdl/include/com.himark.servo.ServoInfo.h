#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define COM_HIMARK_SERVO_SERVOINFO_MAX_SIZE 12
#define COM_HIMARK_SERVO_SERVOINFO_SIGNATURE (0xCA8F4B8F97D23B57ULL)
#define COM_HIMARK_SERVO_SERVOINFO_ID 2019

#define COM_HIMARK_SERVO_SERVOINFO_ERROR_STATUS_NO_ERROR 0
#define COM_HIMARK_SERVO_SERVOINFO_ERROR_STATUS_DATA_ERROR 1

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class com_himark_servo_ServoInfo_cxx_iface;
#endif

struct com_himark_servo_ServoInfo {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = com_himark_servo_ServoInfo_cxx_iface;
#endif
    uint8_t servo_id;
    uint16_t pwm_input;
    int16_t pos_cmd;
    int16_t pos_sensor;
    uint16_t voltage;
    uint16_t current;
    uint16_t pcb_temp;
    uint16_t motor_temp;
    uint8_t error_status;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t com_himark_servo_ServoInfo_encode(struct com_himark_servo_ServoInfo* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool com_himark_servo_ServoInfo_decode(const CanardRxTransfer* transfer, struct com_himark_servo_ServoInfo* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _com_himark_servo_ServoInfo_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_himark_servo_ServoInfo* msg, bool tao);
static inline void _com_himark_servo_ServoInfo_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_himark_servo_ServoInfo* msg, bool tao);
void _com_himark_servo_ServoInfo_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_himark_servo_ServoInfo* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 5, &msg->servo_id);
    *bit_ofs += 5;
    canardEncodeScalar(buffer, *bit_ofs, 12, &msg->pwm_input);
    *bit_ofs += 12;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->pos_cmd);
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->pos_sensor);
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 12, &msg->voltage);
    *bit_ofs += 12;
    canardEncodeScalar(buffer, *bit_ofs, 10, &msg->current);
    *bit_ofs += 10;
    canardEncodeScalar(buffer, *bit_ofs, 10, &msg->pcb_temp);
    *bit_ofs += 10;
    canardEncodeScalar(buffer, *bit_ofs, 10, &msg->motor_temp);
    *bit_ofs += 10;
    canardEncodeScalar(buffer, *bit_ofs, 5, &msg->error_status);
    *bit_ofs += 5;
}

void _com_himark_servo_ServoInfo_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_himark_servo_ServoInfo* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardDecodeScalar(transfer, *bit_ofs, 5, false, &msg->servo_id);
    *bit_ofs += 5;

    canardDecodeScalar(transfer, *bit_ofs, 12, false, &msg->pwm_input);
    *bit_ofs += 12;

    canardDecodeScalar(transfer, *bit_ofs, 16, true, &msg->pos_cmd);
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 16, true, &msg->pos_sensor);
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 12, false, &msg->voltage);
    *bit_ofs += 12;

    canardDecodeScalar(transfer, *bit_ofs, 10, false, &msg->current);
    *bit_ofs += 10;

    canardDecodeScalar(transfer, *bit_ofs, 10, false, &msg->pcb_temp);
    *bit_ofs += 10;

    canardDecodeScalar(transfer, *bit_ofs, 10, false, &msg->motor_temp);
    *bit_ofs += 10;

    canardDecodeScalar(transfer, *bit_ofs, 5, false, &msg->error_status);
    *bit_ofs += 5;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct com_himark_servo_ServoInfo sample_com_himark_servo_ServoInfo_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(com_himark_servo_ServoInfo, COM_HIMARK_SERVO_SERVOINFO_ID, COM_HIMARK_SERVO_SERVOINFO_SIGNATURE, COM_HIMARK_SERVO_SERVOINFO_MAX_SIZE);
#endif
#endif
