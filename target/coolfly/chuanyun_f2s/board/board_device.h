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

#ifndef BOARD_DEVICE_H__
#define BOARD_DEVICE_H__

// #define BOARD_JM_250
// #define BOARD_F2S 1
#define BOARD_LT_V1 1
// #define BOARD_HK_HELI     1

#ifdef BOARD_JM_250
    // #define USED_RAMTRON   1

    // #define USED_BMI055   1
    #define USED_BMI088       1

    #define USED_SPL06        1
    // #define USED_MS5611     1
    #define USED_RGB          1

    #define USED_MMC5983MA    1

    #define WD_DONE_GPIO      HAL_GPIO_NUM74
    #define VIDEO_LED_GPIO    HAL_GPIO_NUM55
    #define LINK_LED_GPIO     HAL_GPIO_NUM54

    #define RGB_R_GPIO        HAL_GPIO_NUM66
    #define RGB_G_GPIO        HAL_GPIO_NUM62
    #define RGB_B_GPIO        HAL_GPIO_NUM58

    #define SENSOR_POWER_GPIO HAL_GPIO_NUM70

    #define SPI1_SPEED_HZ     9000000
#endif

#ifdef BOARD_F2S
    // #define USED_RAMTRON   1

    // #define USED_BMI055   1
    #define USED_BMI088       1

    #define USED_SPL06        1
    // #define USED_MS5611     1
    #define USED_RGB          1

    #define USED_MMC5983MA    1

    #define WD_DONE_GPIO      HAL_GPIO_NUM74
    #define VIDEO_LED_GPIO    HAL_GPIO_NUM55
    #define LINK_LED_GPIO     HAL_GPIO_NUM54

    #define RGB_R_GPIO        HAL_GPIO_NUM66
    #define RGB_G_GPIO        HAL_GPIO_NUM62
    #define RGB_B_GPIO        HAL_GPIO_NUM58

    #define SENSOR_POWER_GPIO HAL_GPIO_NUM70

    #define SPI1_SPEED_HZ     9000000
#endif

#ifdef BOARD_LT_V1
    // #define USED_RAMTRON   1

    // #define USED_BMI055   1
    #define USED_BMI088    1

    // #define USED_SPL06 1
    #define USED_MS5611    1
    #define USED_RGB       1

    #define USED_MMC5983MA 1

    // #define USED_IST8310 1

    #define WD_DONE_GPIO   HAL_GPIO_NUM74
    #define VIDEO_LED_GPIO HAL_GPIO_NUM55
    #define LINK_LED_GPIO  HAL_GPIO_NUM54

    #define FUM_CTRL_GPIO  HAL_GPIO_NUM88

    // #define RGB_R_GPIO HAL_GPIO_NUM66
    // #define RGB_G_GPIO HAL_GPIO_NUM62
    // #define RGB_B_GPIO HAL_GPIO_NUM58

    // #define SENSOR_POWER_GPIO HAL_GPIO_NUM70

    #define SPI1_SPEED_HZ  9000000
#endif

#ifdef BOARD_HK_HELI
    // #define USED_RAMTRON   1

    #define USED_BMI055    1
    // #define USED_BMI088 1

    #define USED_SPL06     1
    // #define USED_MS5611 1
    // #define USED_RGB    1

    #define USED_IST8310   1

    #define WD_DONE_GPIO   HAL_GPIO_NUM74
    #define VIDEO_LED_GPIO HAL_GPIO_NUM55
    #define LINK_LED_GPIO  HAL_GPIO_NUM54

    // #define RGB_R_GPIO HAL_GPIO_NUM66
    // #define RGB_G_GPIO HAL_GPIO_NUM62
    // #define RGB_B_GPIO HAL_GPIO_NUM58

    // #define SENSOR_POWER_GPIO HAL_GPIO_NUM70

    #define SPI1_SPEED_HZ  9000000
#endif
#endif