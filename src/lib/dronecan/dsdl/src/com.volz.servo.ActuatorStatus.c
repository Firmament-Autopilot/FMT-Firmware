#define CANARD_DSDLC_INTERNAL
#include <com.volz.servo.ActuatorStatus.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t com_volz_servo_ActuatorStatus_encode(struct com_volz_servo_ActuatorStatus* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, COM_VOLZ_SERVO_ACTUATORSTATUS_MAX_SIZE);
    _com_volz_servo_ActuatorStatus_encode(buffer, &bit_ofs, msg, 
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
bool com_volz_servo_ActuatorStatus_decode(const CanardRxTransfer* transfer, struct com_volz_servo_ActuatorStatus* msg) {
    uint32_t bit_ofs = 0;
    _com_volz_servo_ActuatorStatus_decode(transfer, &bit_ofs, msg, 
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
struct com_volz_servo_ActuatorStatus sample_com_volz_servo_ActuatorStatus_msg(void) {
    struct com_volz_servo_ActuatorStatus msg;

    msg.actuator_id = (uint8_t)random_bitlen_unsigned_val(8);
    msg.actual_position = random_float16_val();
    msg.current = (uint8_t)random_bitlen_unsigned_val(8);
    msg.voltage = (uint8_t)random_bitlen_unsigned_val(8);
    msg.motor_pwm = (uint8_t)random_bitlen_unsigned_val(8);
    msg.motor_temperature = (uint8_t)random_bitlen_unsigned_val(8);
    return msg;
}
#endif
