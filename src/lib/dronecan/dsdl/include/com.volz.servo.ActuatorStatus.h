
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define COM_VOLZ_SERVO_ACTUATORSTATUS_MAX_SIZE 7
#define COM_VOLZ_SERVO_ACTUATORSTATUS_SIGNATURE (0x29BF0D53B4060263ULL)

#define COM_VOLZ_SERVO_ACTUATORSTATUS_ID 20020




struct com_volz_servo_ActuatorStatus {



    uint8_t actuator_id;



    float actual_position;



    uint8_t current;



    uint8_t voltage;



    uint8_t motor_pwm;



    uint8_t motor_temperature;



};

uint32_t com_volz_servo_ActuatorStatus_encode(struct com_volz_servo_ActuatorStatus* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool com_volz_servo_ActuatorStatus_decode(const CanardRxTransfer* transfer, struct com_volz_servo_ActuatorStatus* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _com_volz_servo_ActuatorStatus_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_volz_servo_ActuatorStatus* msg, bool tao);
static inline void _com_volz_servo_ActuatorStatus_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_volz_servo_ActuatorStatus* msg, bool tao);
void _com_volz_servo_ActuatorStatus_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_volz_servo_ActuatorStatus* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->actuator_id);

    *bit_ofs += 8;






    {
        uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->actual_position);
        canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
    }

    *bit_ofs += 16;






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->current);

    *bit_ofs += 8;






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->voltage);

    *bit_ofs += 8;






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->motor_pwm);

    *bit_ofs += 8;






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->motor_temperature);

    *bit_ofs += 8;





}

void _com_volz_servo_ActuatorStatus_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_volz_servo_ActuatorStatus* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->actuator_id);

    *bit_ofs += 8;







    {
        uint16_t float16_val;
        canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
        msg->actual_position = canardConvertFloat16ToNativeFloat(float16_val);
    }

    *bit_ofs += 16;







    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->current);

    *bit_ofs += 8;







    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->voltage);

    *bit_ofs += 8;







    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->motor_pwm);

    *bit_ofs += 8;







    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->motor_temperature);

    *bit_ofs += 8;






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct com_volz_servo_ActuatorStatus sample_com_volz_servo_ActuatorStatus_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
