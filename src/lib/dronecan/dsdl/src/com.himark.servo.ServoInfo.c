#define CANARD_DSDLC_INTERNAL
#include <com.himark.servo.ServoInfo.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t com_himark_servo_ServoInfo_encode(struct com_himark_servo_ServoInfo* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, COM_HIMARK_SERVO_SERVOINFO_MAX_SIZE);
    _com_himark_servo_ServoInfo_encode(buffer, &bit_ofs, msg, 
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
bool com_himark_servo_ServoInfo_decode(const CanardRxTransfer* transfer, struct com_himark_servo_ServoInfo* msg) {
    uint32_t bit_ofs = 0;
    _com_himark_servo_ServoInfo_decode(transfer, &bit_ofs, msg, 
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
struct com_himark_servo_ServoInfo sample_com_himark_servo_ServoInfo_msg(void) {
    struct com_himark_servo_ServoInfo msg;

    msg.servo_id = (uint8_t)random_bitlen_unsigned_val(5);
    msg.pwm_input = (uint16_t)random_bitlen_unsigned_val(12);
    msg.pos_cmd = (int16_t)random_bitlen_signed_val(16);
    msg.pos_sensor = (int16_t)random_bitlen_signed_val(16);
    msg.voltage = (uint16_t)random_bitlen_unsigned_val(12);
    msg.current = (uint16_t)random_bitlen_unsigned_val(10);
    msg.pcb_temp = (uint16_t)random_bitlen_unsigned_val(10);
    msg.motor_temp = (uint16_t)random_bitlen_unsigned_val(10);
    msg.error_status = (uint8_t)random_bitlen_unsigned_val(5);
    return msg;
}
#endif
