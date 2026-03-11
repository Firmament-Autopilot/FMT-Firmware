#include "dshot.h"

uint16_t dshot_pack_frame(uint16_t value, bool telemetry)
{
    value &= 0x07FFU;

    uint16_t packet = (value << 1) | (telemetry ? 1u : 0u);

    uint16_t csum = (packet ^ (packet >> 4) ^ (packet >> 8)) & 0x0Fu;

    return (uint16_t)((packet << 4) | csum);
}

uint16_t dshot_throttle_to_value(float norm_throttle)
{
    if (norm_throttle < 0.0f) {
        norm_throttle = 0.0f;
    } else if (norm_throttle > 1.0f) {
        norm_throttle = 1.0f;
    }

    return (uint16_t)(DSHOT_MIN_THROTTLE + (uint16_t)(norm_throttle * DSHOT_RANGE));
}