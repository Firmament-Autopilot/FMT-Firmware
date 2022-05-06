#include "module/math/rotation.h"

void l3gd20h_rotate_to_ned(float *data)
{
    rotation(ROTATION_YAW_270, data, data + 1, data + 2);
}

void mpu6000_rotate_to_ned(float *data)
{
    rotation(ROTATION_YAW_270, data, data + 1, data + 2);
}