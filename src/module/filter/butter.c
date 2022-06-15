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

#include "module/filter/butter.h"

Butter3* butter3_filter_create(float b[4], float a[4])
{
    Butter3* butter = rt_malloc(sizeof(Butter3));
    if (butter == NULL) {
        return NULL;
    }
    for (uint8_t i = 0; i < 4; i++) {
        butter->B[i] = b[i];
        butter->A[i] = a[i];
        butter->X[i] = butter->Y[i] = 0.0f;
    }

    return butter;
}

float butter3_filter_process(float in, Butter3* butter)
{
    float out;
    butter->X[3] = in;
    /* a(1)*y(n) = b(1)*x(n) + b(2)*x(n-1) + ... + b(nb+1)*x(n-nb)
                         - a(2)*y(n-1) - ... - a(na+1)*y(n-na)  */
    butter->Y[3] = butter->B[0] * butter->X[3] + butter->B[1] * butter->X[2] + butter->B[2] * butter->X[1]
        + butter->B[3] * butter->X[0] - butter->A[1] * butter->Y[2] - butter->A[2] * butter->Y[1] - butter->A[3] * butter->Y[0];

    /* we assume a(1)=1 */
    out = butter->Y[3];

    /* move X and Y */
    butter->X[0] = butter->X[1];
    butter->X[1] = butter->X[2];
    butter->X[2] = butter->X[3];
    butter->Y[0] = butter->Y[1];
    butter->Y[1] = butter->Y[2];
    butter->Y[2] = butter->Y[3];

    return out;
}