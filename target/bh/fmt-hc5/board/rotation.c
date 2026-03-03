/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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
#include "module/math/rotation.h"
#include <firmament.h>

void sh5001_rotate_to_frd(float val[3])
{
    float tmp = val[0];
    val[0] = val[1];
    val[1] = tmp;
    val[2] = -val[2];
}

void qmi8a01_rotate_to_frd(float* val)
{
    float tmp = val[0];
    val[0] = val[1];
    val[1] = tmp;
    val[2] = -val[2];
}
