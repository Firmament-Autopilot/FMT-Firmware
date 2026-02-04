/******************************************************************************
 * Copyright 2023 The Firmament Authors. All Rights Reserved.
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
#include "module/math/rotation.h"

/**
 * @brief Rotate ICM42688P sensor data to FRD (Front-Right-Down) frame
 * 
 * @param data Pointer to sensor data array [x, y, z]
 * @param dev_id Device ID (0 for primary, 1 for backup)
 */
void icm42688_rotate_to_frd(float* data, uint8_t dev_id)
{
    rotation(ROTATION_PITCH_180_YAW_90, data, data + 1, data + 2);
}

/**
 * @brief Rotate BMI055 sensor data to FRD (Front-Right-Down) frame
 * 
 * @param data Pointer to sensor data array [x, y, z]
 * @param dev_id Device ID (0 for primary, 1 for backup)
 */
void bmi055_rotate_to_frd(float* data, uint8_t dev_id)
{
    rotation(ROTATION_PITCH_180_YAW_270, data, data + 1, data + 2);
}
