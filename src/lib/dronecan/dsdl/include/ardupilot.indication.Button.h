
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define ARDUPILOT_INDICATION_BUTTON_MAX_SIZE 2
#define ARDUPILOT_INDICATION_BUTTON_SIGNATURE (0x645A46EFBA7466EULL)

#define ARDUPILOT_INDICATION_BUTTON_ID 20001



#define ARDUPILOT_INDICATION_BUTTON_BUTTON_SAFETY 1




struct ardupilot_indication_Button {



    uint8_t button;



    uint8_t press_time;



};

uint32_t ardupilot_indication_Button_encode(struct ardupilot_indication_Button* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool ardupilot_indication_Button_decode(const CanardRxTransfer* transfer, struct ardupilot_indication_Button* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _ardupilot_indication_Button_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_indication_Button* msg, bool tao);
static inline void _ardupilot_indication_Button_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_indication_Button* msg, bool tao);
void _ardupilot_indication_Button_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_indication_Button* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->button);

    *bit_ofs += 8;






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->press_time);

    *bit_ofs += 8;





}

void _ardupilot_indication_Button_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_indication_Button* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->button);

    *bit_ofs += 8;







    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->press_time);

    *bit_ofs += 8;






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_indication_Button sample_ardupilot_indication_Button_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
