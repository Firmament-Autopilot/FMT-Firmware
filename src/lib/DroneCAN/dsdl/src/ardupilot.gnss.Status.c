

#define CANARD_DSDLC_INTERNAL
#include <ardupilot.gnss.Status.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t ardupilot_gnss_Status_encode(struct ardupilot_gnss_Status* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, ARDUPILOT_GNSS_STATUS_MAX_SIZE);
    _ardupilot_gnss_Status_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool ardupilot_gnss_Status_decode(const CanardRxTransfer* transfer, struct ardupilot_gnss_Status* msg) {
    uint32_t bit_ofs = 0;
    _ardupilot_gnss_Status_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_gnss_Status sample_ardupilot_gnss_Status_msg(void) {

    struct ardupilot_gnss_Status msg;






    msg.error_codes = (uint32_t)random_bitlen_unsigned_val(32);







    msg.healthy = (bool)random_bitlen_unsigned_val(1);







    msg.status = (uint32_t)random_bitlen_unsigned_val(23);





    return msg;

}
#endif