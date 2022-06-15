
#include "rotation.h"

#define HALF_SQRT_2 0.7071067811865f

void rotation(enum Rotation rotation, float* x, float* y, float* z)
{
    float tmp;
    switch (rotation) {
    case ROTATION_NONE:
        return;
    case ROTATION_YAW_45: {
        tmp = HALF_SQRT_2 * (float)(*x - *y);
        *y = HALF_SQRT_2 * (float)(*x + *y);
        *x = tmp;
        return;
    }
    case ROTATION_YAW_90: {
        tmp = *x;
        *x = -*y;
        *y = tmp;
        return;
    }
    case ROTATION_YAW_135: {
        tmp = -HALF_SQRT_2 * (float)(*x + *y);
        *y = HALF_SQRT_2 * (float)(*x - *y);
        *x = tmp;
        return;
    }
    case ROTATION_YAW_180:
        *x = -*x;
        *y = -*y;
        return;
    case ROTATION_YAW_225: {
        tmp = HALF_SQRT_2 * (float)(*y - *x);
        *y = -HALF_SQRT_2 * (float)(*x + *y);
        *x = tmp;
        return;
    }
    case ROTATION_YAW_270: {
        tmp = *x;
        *x = *y;
        *y = -tmp;
        return;
    }
    case ROTATION_YAW_315: {
        tmp = HALF_SQRT_2 * (float)(*x + *y);
        *y = HALF_SQRT_2 * (float)(*y - *x);
        *x = tmp;
        return;
    }
    case ROTATION_ROLL_180: {
        *y = -*y;
        *z = -*z;
        return;
    }
    case ROTATION_ROLL_180_YAW_45: {
        tmp = HALF_SQRT_2 * (float)(*x + *y);
        *y = HALF_SQRT_2 * (float)(*x - *y);
        *x = tmp;
        *z = -*z;
        return;
    }
    case ROTATION_ROLL_180_YAW_90:
    case ROTATION_PITCH_180_YAW_270: {
        tmp = *x;
        *x = *y;
        *y = tmp;
        *z = -*z;
        return;
    }
    case ROTATION_ROLL_180_YAW_135: {
        tmp = HALF_SQRT_2 * (float)(*y - *x);
        *y = HALF_SQRT_2 * (float)(*y + *x);
        *x = tmp;
        *z = -*z;
        return;
    }
    case ROTATION_PITCH_180: {
        *x = -*x;
        *z = -*z;
        return;
    }
    case ROTATION_ROLL_180_YAW_225: {
        tmp = -HALF_SQRT_2 * (float)(*x + *y);
        *y = HALF_SQRT_2 * (float)(*y - *x);
        *x = tmp;
        *z = -*z;
        return;
    }
    case ROTATION_ROLL_180_YAW_270:
    case ROTATION_PITCH_180_YAW_90: {
        tmp = *x;
        *x = -*y;
        *y = -tmp;
        *z = -*z;
        return;
    }
    case ROTATION_ROLL_180_YAW_315: {
        tmp = HALF_SQRT_2 * (float)(*x - *y);
        *y = -HALF_SQRT_2 * (float)(*x + *y);
        *x = tmp;
        *z = -*z;
        return;
    }
    case ROTATION_ROLL_90: {
        tmp = *z;
        *z = *y;
        *y = -tmp;
        return;
    }
    case ROTATION_ROLL_90_YAW_45: {
        tmp = *z;
        *z = *y;
        *y = -tmp;
        tmp = HALF_SQRT_2 * (float)(*x - *y);
        *y = HALF_SQRT_2 * (float)(*x + *y);
        *x = tmp;
        return;
    }
    case ROTATION_ROLL_90_YAW_90: {
        tmp = *z;
        *z = *y;
        *y = -tmp;
        tmp = *x;
        *x = -*y;
        *y = tmp;
        return;
    }
    case ROTATION_ROLL_90_YAW_135: {
        tmp = *z;
        *z = *y;
        *y = -tmp;
        tmp = -HALF_SQRT_2 * (float)(*x + *y);
        *y = HALF_SQRT_2 * (float)(*x - *y);
        *x = tmp;
        return;
    }
    case ROTATION_ROLL_270: {
        tmp = *z;
        *z = -*y;
        *y = tmp;
        return;
    }
    case ROTATION_ROLL_270_YAW_45: {
        tmp = *z;
        *z = -*y;
        *y = tmp;
        tmp = HALF_SQRT_2 * (float)(*x - *y);
        *y = HALF_SQRT_2 * (float)(*x + *y);
        *x = tmp;
        return;
    }
    case ROTATION_ROLL_270_YAW_90: {
        tmp = *z;
        *z = -*y;
        *y = tmp;
        tmp = *x;
        *x = -*y;
        *y = tmp;
        return;
    }
    case ROTATION_ROLL_270_YAW_135: {
        tmp = *z;
        *z = -*y;
        *y = tmp;
        tmp = -HALF_SQRT_2 * (float)(*x + *y);
        *y = HALF_SQRT_2 * (float)(*x - *y);
        *x = tmp;
        return;
    }
    case ROTATION_PITCH_90: {
        tmp = *z;
        *z = -*x;
        *x = tmp;
        return;
    }
    case ROTATION_PITCH_270: {
        tmp = *z;
        *z = *x;
        *x = -tmp;
        return;
    }
    case ROTATION_ROLL_90_PITCH_90: {
        tmp = *z;
        *z = *y;
        *y = -tmp;
        tmp = *z;
        *z = -*x;
        *x = tmp;
        return;
    }
    case ROTATION_ROLL_180_PITCH_90: {
        *y = -*y;
        *z = -*z;
        tmp = *z;
        *z = -*x;
        *x = tmp;
        return;
    }
    case ROTATION_ROLL_270_PITCH_90: {
        tmp = *z;
        *z = -*y;
        *y = tmp;
        tmp = *z;
        *z = -*x;
        *x = tmp;
        return;
    }
    case ROTATION_ROLL_90_PITCH_180: {
        tmp = *z;
        *z = *y;
        *y = -tmp;
        *x = -*x;
        *z = -*z;
        return;
    }
    case ROTATION_ROLL_270_PITCH_180: {
        tmp = *z;
        *z = -*y;
        *y = tmp;
        *x = -*x;
        *z = -*z;
        return;
    }
    case ROTATION_ROLL_90_PITCH_270: {
        tmp = *z;
        *z = *y;
        *y = -tmp;
        tmp = *z;
        *z = *x;
        *x = -tmp;
        return;
    }
    case ROTATION_ROLL_180_PITCH_270: {
        *y = -*y;
        *z = -*z;
        tmp = *z;
        *z = *x;
        *x = -tmp;
        return;
    }
    case ROTATION_ROLL_270_PITCH_270: {
        tmp = *z;
        *z = -*y;
        *y = tmp;
        tmp = *z;
        *z = *x;
        *x = -tmp;
        return;
    }
    case ROTATION_ROLL_90_PITCH_180_YAW_90: {
        tmp = *z;
        *z = *y;
        *y = -tmp;
        *x = -*x;
        *z = -*z;
        tmp = *x;
        *x = -*y;
        *y = tmp;
        return;
    }
    case ROTATION_ROLL_90_YAW_270: {
        tmp = *z;
        *z = *y;
        *y = -tmp;
        tmp = *x;
        *x = *y;
        *y = -tmp;
        return;
    }
    case ROTATION_ROLL_90_PITCH_68_YAW_293: {
        float tmpx = *x;
        float tmpy = *y;
        float tmpz = *z;
        *x = 0.14303897231223747232853327204793 * tmpx + 0.36877648650320382639478111741482 * tmpy + -0.91844638134308709265241077446262 * tmpz;
        *y = -0.33213277779664740485543461545603 * tmpx + -0.85628942146641884303193137384369 * tmpy + -0.39554550256296522325882847326284 * tmpz;
        *z = -0.93232380121551217122544130688766 * tmpx + 0.36162457008209242248497616856184 * tmpy + 0.00000000000000002214311861220361 * tmpz;
        return;
    }
    case ROTATION_PITCH_315: {
        tmp = HALF_SQRT_2 * (float)(*x - *z);
        *z = HALF_SQRT_2 * (float)(*x + *z);
        *x = tmp;
        return;
    }
    case ROTATION_ROLL_90_PITCH_315: {
        tmp = *z;
        *z = *y;
        *y = -tmp;
        tmp = HALF_SQRT_2 * (float)(*x - *z);
        *z = HALF_SQRT_2 * (float)(*x + *z);
        *x = tmp;
        return;
    }
    case ROTATION_PITCH_7: {
        const float sin_pitch = 0.1218693434051474899781908334262;  // sinF(pitch);
        const float cos_pitch = 0.99254615164132198312785249072476; // cosF(pitch);
        float tmpx = *x;
        float tmpz = *z;
        *x = cos_pitch * tmpx + sin_pitch * tmpz;
        *z = -sin_pitch * tmpx + cos_pitch * tmpz;
        return;
    }
    case ROTATION_ROLL_45: {
        tmp = HALF_SQRT_2 * (float)(*y - *z);
        *z = HALF_SQRT_2 * (float)(*y + *z);
        *y = tmp;
        return;
    }
    case ROTATION_ROLL_315: {
        tmp = HALF_SQRT_2 * (float)(*y + *z);
        *z = HALF_SQRT_2 * (float)(*z - *y);
        *y = tmp;
        return;
    }
    }
}