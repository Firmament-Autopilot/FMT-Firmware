#include "module/math/rotation.h"

void icm20689_rotate_to_ned(float *data)
{
    rotation(ROTATION_PITCH_180_YAW_270, data, data + 1, data + 2);
}

void bmi055_rotate_to_ned(float *data)
{
    rotation(ROTATION_PITCH_180_YAW_270, data, data + 1, data + 2);
}
