#pragma once
#include <mppt.OutputEnable_req.h>
#include <mppt.OutputEnable_res.h>

#define MPPT_OUTPUTENABLE_ID 240
#define MPPT_OUTPUTENABLE_SIGNATURE (0xEA251F2A6DD1D8A5ULL)

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
#include <canard/cxx_wrappers.h>
SERVICE_MESSAGE_CXX_IFACE(mppt_OutputEnable, MPPT_OUTPUTENABLE_ID, MPPT_OUTPUTENABLE_SIGNATURE, MPPT_OUTPUTENABLE_REQUEST_MAX_SIZE, MPPT_OUTPUTENABLE_RESPONSE_MAX_SIZE);
#endif
