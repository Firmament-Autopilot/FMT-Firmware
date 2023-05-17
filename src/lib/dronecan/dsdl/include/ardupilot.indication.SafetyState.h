#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define ARDUPILOT_INDICATION_SAFETYSTATE_MAX_SIZE 1
#define ARDUPILOT_INDICATION_SAFETYSTATE_SIGNATURE (0xE965701A95A1A6A1ULL)
#define ARDUPILOT_INDICATION_SAFETYSTATE_ID 20000

#define ARDUPILOT_INDICATION_SAFETYSTATE_STATUS_SAFETY_ON 0
#define ARDUPILOT_INDICATION_SAFETYSTATE_STATUS_SAFETY_OFF 255

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class ardupilot_indication_SafetyState_cxx_iface;
#endif

struct ardupilot_indication_SafetyState {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = ardupilot_indication_SafetyState_cxx_iface;
#endif
    uint8_t status;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t ardupilot_indication_SafetyState_encode(struct ardupilot_indication_SafetyState* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool ardupilot_indication_SafetyState_decode(const CanardRxTransfer* transfer, struct ardupilot_indication_SafetyState* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _ardupilot_indication_SafetyState_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_indication_SafetyState* msg, bool tao);
static inline void _ardupilot_indication_SafetyState_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_indication_SafetyState* msg, bool tao);
void _ardupilot_indication_SafetyState_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_indication_SafetyState* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->status);
    *bit_ofs += 8;
}

void _ardupilot_indication_SafetyState_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_indication_SafetyState* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->status);
    *bit_ofs += 8;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_indication_SafetyState sample_ardupilot_indication_SafetyState_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(ardupilot_indication_SafetyState, ARDUPILOT_INDICATION_SAFETYSTATE_ID, ARDUPILOT_INDICATION_SAFETYSTATE_SIGNATURE, ARDUPILOT_INDICATION_SAFETYSTATE_MAX_SIZE);
#endif
#endif
