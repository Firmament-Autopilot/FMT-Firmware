#ifndef UXR_CLIENT_PROFILE_TRANSPORT_SERIAL_EXTERNAL_H_
#define UXR_CLIENT_PROFILE_TRANSPORT_SERIAL_EXTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

// Place here your includes
#include <firmament.h>

typedef struct uxrSerialPlatform {
    // Place here your platform data
    rt_device_t dev;
} uxrSerialPlatform;

#ifdef __cplusplus
}
#endif

#endif // UXR_CLIENT_PROFILE_TRANSPORT_SERIAL_EXTERNAL_H_