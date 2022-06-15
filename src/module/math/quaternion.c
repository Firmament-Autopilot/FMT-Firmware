/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <firmament.h>
#include <math.h>

#include "module/math/ap_math.h"
#include "module/math/quaternion.h"

void quaternion_normalize(quaternion* q)
{
    float norm_r = math_rsqrt(q->w * q->w + q->x * q->x + q->y * q->y + q->z * q->z);
    q->w *= norm_r;
    q->x *= norm_r;
    q->y *= norm_r;
    q->z *= norm_r;
}

void quaternion_add(quaternion* result, const quaternion* left, const quaternion* right)
{
    result->w = left->w + right->w;
    result->x = left->x + right->x;
    result->y = left->y + right->y;
    result->z = left->z + right->z;
}

void quaternion_mult(quaternion* result, const quaternion* left, const quaternion* right)
{
    result->w = left->w * right->w - left->x * right->x - left->y * right->y - left->z * right->z;
    result->x = left->x * right->w + left->w * right->x + left->y * right->z - left->z * right->y;
    result->y = left->y * right->w + left->w * right->y + left->z * right->x - left->x * right->z;
    result->z = left->z * right->w + left->w * right->z + left->x * right->y - left->y * right->x;
}

// transfer from body frame to navigation frame ,v_n = C * v_b
void quaternion_rotateVector(const quaternion* rotation, const float from[3], float to[3])
{
    float x2 = rotation->x * 2.0f;
    float y2 = rotation->y * 2.0f;
    float z2 = rotation->z * 2.0f;
    float wx2 = rotation->w * x2;
    float wy2 = rotation->w * y2;
    float wz2 = rotation->w * z2;
    float xx2 = rotation->x * x2;
    float yy2 = rotation->y * y2;
    float zz2 = rotation->z * z2;
    float xy2 = rotation->x * y2;
    float yz2 = rotation->y * z2;
    float xz2 = rotation->z * x2;
    //
    to[0] = from[0] * (1.0f - yy2 - zz2) + from[1] * (xy2 - wz2) + from[2] * (xz2 + wy2);
    to[1] = from[0] * (xy2 + wz2) + from[1] * (1.0f - xx2 - zz2) + from[2] * (yz2 - wx2);
    to[2] = from[0] * (xz2 - wy2) + from[1] * (yz2 + wx2) + from[2] * (1.0f - xx2 - yy2);
}

// transfer from navigation frame to body frame ,v_b = C^T * v_n
void quaternion_inv_rotateVector(const quaternion* rotation, const float from[3], float to[3])
{
    float x2 = rotation->x * 2.0f;
    float y2 = rotation->y * 2.0f;
    float z2 = rotation->z * 2.0f;
    float wx2 = rotation->w * x2;
    float wy2 = rotation->w * y2;
    float wz2 = rotation->w * z2;
    float xx2 = rotation->x * x2;
    float yy2 = rotation->y * y2;
    float zz2 = rotation->z * z2;
    float xy2 = rotation->x * y2;
    float yz2 = rotation->y * z2;
    float xz2 = rotation->z * x2;
    //
    to[0] = from[0] * (1.0f - yy2 - zz2) + from[1] * (xy2 + wz2) + from[2] * (xz2 - wy2);
    to[1] = from[0] * (xy2 - wz2) + from[1] * (1.0f - xx2 - zz2) + from[2] * (yz2 + wx2);
    to[2] = from[0] * (xz2 + wy2) + from[1] * (yz2 - wx2) + from[2] * (1.0f - xx2 - yy2);
}

void quaternion_conjugate(const quaternion* q, quaternion* res)
{
    res->w = q->w;
    res->x = -q->x;
    res->y = -q->y;
    res->z = -q->z;
}

void quaternion_create(quaternion* q, float theta, float axis[3])
{
    float half_theta = 0.5f * theta;
    float sin_half_theta = arm_sin_f32(half_theta);

    Vector3_Normalize(axis, axis);

    q->w = arm_cos_f32(half_theta);
    q->x = axis[0] * sin_half_theta;
    q->y = axis[1] * sin_half_theta;
    q->z = axis[2] * sin_half_theta;

    quaternion_normalize(q);
}

// calculate quaternion rotate from q1 to q2
void quaternion_fromTwoQuaternionRotation(quaternion* q, const quaternion* q1, const quaternion* q2)
{
    quaternion cj_q;

    quaternion_conjugate(q1, &cj_q);
    quaternion_normalize(&cj_q);
    quaternion_mult(q, q2, &cj_q);
}

// calculate quaternion rotate from vector1 to vector2
void quaternion_fromTwoVectorRotation(quaternion* result, const float from[3], const float to[3])
{
    float n[3], a[3], b[3];
    float theta;
    float sin_half_theta;

    Vector3_Normalize(a, from);
    Vector3_Normalize(b, to);
    theta = acos(Vector3_DotProduct(a, b));
    Vector3_CrossProduct(n, a, b);
    Vector3_Normalize(n, n);

    //sin_half_theta = sin(theta*0.5);
    sin_half_theta = arm_sin_f32(theta * 0.5f);
    //result->w = cos(theta*0.5);
    result->w = arm_cos_f32(theta * 0.5f);
    result->x = n[0] * sin_half_theta;
    result->y = n[1] * sin_half_theta;
    result->z = n[2] * sin_half_theta;

    quaternion_normalize(result);
}

//euler[3]: roll pitch yaw	unit:rad
void quaternion_toEuler(const quaternion* q, Euler* e)
{
    double ysqr = q->y * q->y;

    // roll (x-axis rotation)
    double t0 = +2.0f * (q->w * q->x + q->y * q->z);
    double t1 = +1.0f - 2.0f * (q->x * q->x + ysqr);
    e->roll = atan2f(t0, t1);

    // pitch (y-axis rotation)
    double t2 = +2.0f * (q->w * q->y - q->z * q->x);
    t2 = t2 > 1.0f ? 1.0f : t2;
    t2 = t2 < -1.0f ? -1.0f : t2;
    e->pitch = asinf(t2);

    // yaw (z-axis rotation)
    double t3 = +2.0f * (q->w * q->z + q->x * q->y);
    double t4 = +1.0f - 2.0f * (ysqr + q->z * q->z);
    e->yaw = atan2f(t3, t4);
}

//euler[3]: roll pitch yaw	 unit:rad
void quaternion_fromEuler(const Euler e, quaternion* q)
{
    //	double cr = cos(e.roll * 0.5);
    //	double sr = sin(e.roll * 0.5);
    //	double cp = cos(e.pitch * 0.5);
    //	double sp = sin(e.pitch * 0.5);
    //	double cy = cos(e.yaw * 0.5);
    //	double sy = sin(e.yaw * 0.5);
    float cr = arm_cos_f32(e.roll * 0.5f);
    float sr = arm_sin_f32(e.roll * 0.5f);
    float cp = arm_cos_f32(e.pitch * 0.5f);
    float sp = arm_sin_f32(e.pitch * 0.5f);
    float cy = arm_cos_f32(e.yaw * 0.5f);
    float sy = arm_sin_f32(e.yaw * 0.5f);

    q->w = cy * cr * cp + sy * sr * sp;
    q->x = cy * sr * cp - sy * cr * sp;
    q->y = cy * cr * sp + sy * sr * cp;
    q->z = sy * cr * cp - cy * sr * sp;
}

float quaternion_getEuler(const quaternion q, int index)
{
    if (index == 0) {
        // roll
        double t0 = +2.0f * (q.w * q.x + q.y * q.z);
        double t1 = +1.0f - 2.0f * (q.x * q.x + q.y * q.y);
        return atan2(t0, t1);
    } else if (index == 1) {
        // pitch
        double t2 = +2.0f * (q.w * q.y - q.z * q.x);
        t2 = t2 > 1.0f ? 1.0f : t2;
        t2 = t2 < -1.0f ? -1.0f : t2;
        return asin(t2);
    } else {
        // yaw
        double t3 = +2.0f * (q.w * q.z + q.x * q.y);
        double t4 = +1.0f - 2.0f * (q.y * q.y + q.z * q.z);
        return atan2(t3, t4);
    }
}
