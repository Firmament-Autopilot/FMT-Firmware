
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define ARDUPILOT_INDICATION_NOTIFYSTATE_MAX_SIZE 265
#define ARDUPILOT_INDICATION_NOTIFYSTATE_SIGNATURE (0x631F2A9C1651FDECULL)

#define ARDUPILOT_INDICATION_NOTIFYSTATE_ID 20007



#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_INITIALISING 0

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_ARMED 1

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_FLYING 2

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_PREARM 3

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_PREARM_GPS 4

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_SAVE_TRIM 5

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_ESC_CALIBRATION 6

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_FAILSAFE_RADIO 7

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_FAILSAFE_BATT 8

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_FAILSAFE_GCS 9

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_CHUTE_RELEASED 10

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_EKF_BAD 11

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_FW_UPDATE 12

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_MAGCAL_RUN 13

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_LEAK_DET 14

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_GPS_FUSION 15

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_GPS_GLITCH 16

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_POS_ABS_AVAIL 17

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_LOST 18

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_THROW_READY 19

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_POWERING_OFF 20

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_STATE_VIDEO_RECORDING 21

#define ARDUPILOT_INDICATION_NOTIFYSTATE_VEHICLE_YAW_EARTH_CENTIDEGREES 0




struct ardupilot_indication_NotifyState {



    uint8_t aux_data_type;



    struct { uint8_t len; uint8_t data[255]; }aux_data;



    uint64_t vehicle_state;



};

uint32_t ardupilot_indication_NotifyState_encode(struct ardupilot_indication_NotifyState* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool ardupilot_indication_NotifyState_decode(const CanardRxTransfer* transfer, struct ardupilot_indication_NotifyState* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _ardupilot_indication_NotifyState_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_indication_NotifyState* msg, bool tao);
static inline void _ardupilot_indication_NotifyState_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_indication_NotifyState* msg, bool tao);
void _ardupilot_indication_NotifyState_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_indication_NotifyState* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->aux_data_type);

    *bit_ofs += 8;







    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->aux_data.len);
    *bit_ofs += 8;

    for (size_t i=0; i < msg->aux_data.len; i++) {




        canardEncodeScalar(buffer, *bit_ofs, 8, &msg->aux_data.data[i]);

        *bit_ofs += 8;


    }






    canardEncodeScalar(buffer, *bit_ofs, 64, &msg->vehicle_state);

    *bit_ofs += 64;





}

void _ardupilot_indication_NotifyState_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_indication_NotifyState* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->aux_data_type);

    *bit_ofs += 8;








    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->aux_data.len);
    *bit_ofs += 8;


    for (size_t i=0; i < msg->aux_data.len; i++) {




        canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->aux_data.data[i]);

        *bit_ofs += 8;


    }








    canardDecodeScalar(transfer, *bit_ofs, 64, false, &msg->vehicle_state);

    *bit_ofs += 64;






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_indication_NotifyState sample_ardupilot_indication_NotifyState_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
