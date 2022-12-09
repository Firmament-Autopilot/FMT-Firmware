
#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>



#ifdef __cplusplus
extern "C"
{
#endif

#define ARDUPILOT_GNSS_STATUS_MAX_SIZE 7
#define ARDUPILOT_GNSS_STATUS_SIGNATURE (0xBA3CB4ABBB007F69ULL)

#define ARDUPILOT_GNSS_STATUS_ID 20003



#define ARDUPILOT_GNSS_STATUS_STATUS_LOGGING 1

#define ARDUPILOT_GNSS_STATUS_STATUS_ARMABLE 2




struct ardupilot_gnss_Status {



    uint32_t error_codes;



    bool healthy;



    uint32_t status;



};

uint32_t ardupilot_gnss_Status_encode(struct ardupilot_gnss_Status* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool ardupilot_gnss_Status_decode(const CanardRxTransfer* transfer, struct ardupilot_gnss_Status* msg);

#if defined(CANARD_DSDLC_INTERNAL)

static inline void _ardupilot_gnss_Status_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_gnss_Status* msg, bool tao);
static inline void _ardupilot_gnss_Status_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_gnss_Status* msg, bool tao);
void _ardupilot_gnss_Status_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_gnss_Status* msg, bool tao) {

    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->error_codes);

    *bit_ofs += 32;






    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->healthy);

    *bit_ofs += 1;






    canardEncodeScalar(buffer, *bit_ofs, 23, &msg->status);

    *bit_ofs += 23;





}

void _ardupilot_gnss_Status_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_gnss_Status* msg, bool tao) {

    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;






    canardDecodeScalar(transfer, *bit_ofs, 32, false, &msg->error_codes);

    *bit_ofs += 32;







    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->healthy);

    *bit_ofs += 1;







    canardDecodeScalar(transfer, *bit_ofs, 23, false, &msg->status);

    *bit_ofs += 23;






}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_gnss_Status sample_ardupilot_gnss_Status_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"
#endif
