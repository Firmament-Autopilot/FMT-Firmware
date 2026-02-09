/***************************************************************************//**
* PSE84 device GPIO header for BGA-220 package
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef _GPIO_PSE84_BGA_220_H_
#define _GPIO_PSE84_BGA_220_H_

#define CY_GPIO_PACKAGE_TYPE_BGA
#define CY_GPIO_PIN_COUNT               220u

/* AMUXBUS Segments */
enum
{
    AMUXBUS_CHIP,
    AMUXBUS_DLL,
    AMUXBUS_LPCOMP,
    AMUXBUS_PASS,
    AMUXBUS_RRAM,
    AMUXBUS_SRSS,
    AMUXBUS_TEST,
    AMUXBUS_USBHS,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_0                = 0x0000u,  /* Left = AMUXBUS_TEST; Right = AMUXBUS_CHIP */
    AMUX_SPLIT_CTL_1                = 0x0001u,  /* Left = AMUXBUS_CHIP; Right = AMUXBUS_SRSS */
    AMUX_SPLIT_CTL_2                = 0x0002u,  /* Left = AMUXBUS_CHIP; Right = AMUXBUS_DLL */
    AMUX_SPLIT_CTL_3                = 0x0003u,  /* Left = AMUXBUS_CHIP; Right = AMUXBUS_LPCOMP */
    AMUX_SPLIT_CTL_4                = 0x0004u,  /* Left = AMUXBUS_CHIP; Right = AMUXBUS_PASS */
    AMUX_SPLIT_CTL_5                = 0x0005u,  /* Left = AMUXBUS_CHIP; Right = AMUXBUS_USBHS */
    AMUX_SPLIT_CTL_6                = 0x0006u   /* Left = AMUXBUS_CHIP; Right = AMUXBUS_RRAM */
} cy_en_amux_split_t;

/* Port List */
/* PORT 0 (GPIO) */
#define P0_0_PORT                       GPIO_PRT0
#define P0_0_PIN                        0u
#define P0_0_NUM                        0u
#define P0_1_PORT                       GPIO_PRT0
#define P0_1_PIN                        1u
#define P0_1_NUM                        1u

/* PORT 1 (AUX) */
#define SMIF0_SPIHB_DATA0_PORT          ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF0_SPIHB_DATA0_PIN           0u
#define SMIF0_SPIHB_DATA0_NUM           0u
#define P1_0_PORT                       ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define P1_0_PIN                        0u
#define P1_0_NUM                        0u
#define SMIF0_SPIHB_DATA1_PORT          ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF0_SPIHB_DATA1_PIN           1u
#define SMIF0_SPIHB_DATA1_NUM           1u
#define P1_1_PORT                       ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define P1_1_PIN                        1u
#define P1_1_NUM                        1u
#define SMIF0_SPIHB_DATA2_PORT          ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF0_SPIHB_DATA2_PIN           2u
#define SMIF0_SPIHB_DATA2_NUM           2u
#define P1_2_PORT                       ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define P1_2_PIN                        2u
#define P1_2_NUM                        2u
#define SMIF0_SPIHB_DATA3_PORT          ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF0_SPIHB_DATA3_PIN           3u
#define SMIF0_SPIHB_DATA3_NUM           3u
#define P1_3_PORT                       ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define P1_3_PIN                        3u
#define P1_3_NUM                        3u
#define SMIF0_SPIHB_DATA4_PORT          ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF0_SPIHB_DATA4_PIN           4u
#define SMIF0_SPIHB_DATA4_NUM           4u
#define P1_4_PORT                       ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define P1_4_PIN                        4u
#define P1_4_NUM                        4u
#define SMIF0_SPIHB_DATA5_PORT          ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF0_SPIHB_DATA5_PIN           5u
#define SMIF0_SPIHB_DATA5_NUM           5u
#define P1_5_PORT                       ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define P1_5_PIN                        5u
#define P1_5_NUM                        5u
#define SMIF0_SPIHB_DATA6_PORT          ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF0_SPIHB_DATA6_PIN           6u
#define SMIF0_SPIHB_DATA6_NUM           6u
#define P1_6_PORT                       ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define P1_6_PIN                        6u
#define P1_6_NUM                        6u
#define SMIF0_SPIHB_DATA7_PORT          ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF0_SPIHB_DATA7_PIN           7u
#define SMIF0_SPIHB_DATA7_NUM           7u
#define P1_7_PORT                       ((GPIO_PRT_Type*) SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define P1_7_PIN                        7u
#define P1_7_NUM                        7u

/* PORT 2 (GPIO) */
#define P2_0_PORT                       GPIO_PRT2
#define P2_0_PIN                        0u
#define P2_0_NUM                        0u

/* PORT 3 (GPIO) */
#define P3_0_PORT                       GPIO_PRT3
#define P3_0_PIN                        0u
#define P3_0_NUM                        0u
#define P3_1_PORT                       GPIO_PRT3
#define P3_1_PIN                        1u
#define P3_1_NUM                        1u

/* PORT 4 (AUX) */
#define SMIF1_SPIHB_DATA0_PORT          ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF1_SPIHB_DATA0_PIN           0u
#define SMIF1_SPIHB_DATA0_NUM           0u
#define P4_0_PORT                       ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define P4_0_PIN                        0u
#define P4_0_NUM                        0u
#define SMIF1_SPIHB_DATA1_PORT          ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF1_SPIHB_DATA1_PIN           1u
#define SMIF1_SPIHB_DATA1_NUM           1u
#define P4_1_PORT                       ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define P4_1_PIN                        1u
#define P4_1_NUM                        1u
#define SMIF1_SPIHB_DATA2_PORT          ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF1_SPIHB_DATA2_PIN           2u
#define SMIF1_SPIHB_DATA2_NUM           2u
#define P4_2_PORT                       ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define P4_2_PIN                        2u
#define P4_2_NUM                        2u
#define SMIF1_SPIHB_DATA3_PORT          ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF1_SPIHB_DATA3_PIN           3u
#define SMIF1_SPIHB_DATA3_NUM           3u
#define P4_3_PORT                       ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define P4_3_PIN                        3u
#define P4_3_NUM                        3u
#define SMIF1_SPIHB_DATA4_PORT          ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF1_SPIHB_DATA4_PIN           4u
#define SMIF1_SPIHB_DATA4_NUM           4u
#define P4_4_PORT                       ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define P4_4_PIN                        4u
#define P4_4_NUM                        4u
#define SMIF1_SPIHB_DATA5_PORT          ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF1_SPIHB_DATA5_PIN           5u
#define SMIF1_SPIHB_DATA5_NUM           5u
#define P4_5_PORT                       ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define P4_5_PIN                        5u
#define P4_5_NUM                        5u
#define SMIF1_SPIHB_DATA6_PORT          ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF1_SPIHB_DATA6_PIN           6u
#define SMIF1_SPIHB_DATA6_NUM           6u
#define P4_6_PORT                       ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define P4_6_PIN                        6u
#define P4_6_NUM                        6u
#define SMIF1_SPIHB_DATA7_PORT          ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define SMIF1_SPIHB_DATA7_PIN           7u
#define SMIF1_SPIHB_DATA7_NUM           7u
#define P4_7_PORT                       ((GPIO_PRT_Type*) SMIF1_CORE_SMIF_GPIO_SMIF_PRT0)
#define P4_7_PIN                        7u
#define P4_7_NUM                        7u

/* PORT 5 (GPIO) */
#define P5_0_PORT                       GPIO_PRT5
#define P5_0_PIN                        0u
#define P5_0_NUM                        0u

/* PORT 6 (GPIO) */
#define P6_0_PORT                       GPIO_PRT6
#define P6_0_PIN                        0u
#define P6_0_NUM                        0u
#define P6_1_PORT                       GPIO_PRT6
#define P6_1_PIN                        1u
#define P6_1_NUM                        1u
#define P6_2_PORT                       GPIO_PRT6
#define P6_2_PIN                        2u
#define P6_2_NUM                        2u
#define P6_3_PORT                       GPIO_PRT6
#define P6_3_PIN                        3u
#define P6_3_NUM                        3u
#define P6_4_PORT                       GPIO_PRT6
#define P6_4_PIN                        4u
#define P6_4_NUM                        4u
#define P6_5_PORT                       GPIO_PRT6
#define P6_5_PIN                        5u
#define P6_5_NUM                        5u
#define P6_6_PORT                       GPIO_PRT6
#define P6_6_PIN                        6u
#define P6_6_NUM                        6u
#define P6_7_PORT                       GPIO_PRT6
#define P6_7_PIN                        7u
#define P6_7_NUM                        7u

/* PORT 7 (GPIO) */
#define P7_0_PORT                       GPIO_PRT7
#define P7_0_PIN                        0u
#define P7_0_NUM                        0u
#define P7_1_PORT                       GPIO_PRT7
#define P7_1_PIN                        1u
#define P7_1_NUM                        1u
#define P7_2_PORT                       GPIO_PRT7
#define P7_2_PIN                        2u
#define P7_2_NUM                        2u
#define P7_3_PORT                       GPIO_PRT7
#define P7_3_PIN                        3u
#define P7_3_NUM                        3u
#define P7_4_PORT                       GPIO_PRT7
#define P7_4_PIN                        4u
#define P7_4_NUM                        4u
#define P7_5_PORT                       GPIO_PRT7
#define P7_5_PIN                        5u
#define P7_5_NUM                        5u
#define P7_6_PORT                       GPIO_PRT7
#define P7_6_PIN                        6u
#define P7_6_NUM                        6u
#define P7_7_PORT                       GPIO_PRT7
#define P7_7_PIN                        7u
#define P7_7_NUM                        7u

/* PORT 8 (GPIO) */
#define P8_0_PORT                       GPIO_PRT8
#define P8_0_PIN                        0u
#define P8_0_NUM                        0u
#define P8_1_PORT                       GPIO_PRT8
#define P8_1_PIN                        1u
#define P8_1_NUM                        1u
#define P8_2_PORT                       GPIO_PRT8
#define P8_2_PIN                        2u
#define P8_2_NUM                        2u
#define P8_3_PORT                       GPIO_PRT8
#define P8_3_PIN                        3u
#define P8_3_NUM                        3u
#define P8_4_PORT                       GPIO_PRT8
#define P8_4_PIN                        4u
#define P8_4_NUM                        4u
#define P8_5_PORT                       GPIO_PRT8
#define P8_5_PIN                        5u
#define P8_5_NUM                        5u
#define P8_6_PORT                       GPIO_PRT8
#define P8_6_PIN                        6u
#define P8_6_NUM                        6u
#define P8_7_PORT                       GPIO_PRT8
#define P8_7_PIN                        7u
#define P8_7_NUM                        7u

/* PORT 9 (GPIO) */
#define P9_0_PORT                       GPIO_PRT9
#define P9_0_PIN                        0u
#define P9_0_NUM                        0u
#define P9_1_PORT                       GPIO_PRT9
#define P9_1_PIN                        1u
#define P9_1_NUM                        1u
#define P9_2_PORT                       GPIO_PRT9
#define P9_2_PIN                        2u
#define P9_2_NUM                        2u
#define P9_3_PORT                       GPIO_PRT9
#define P9_3_PIN                        3u
#define P9_3_NUM                        3u

/* PORT 10 (GPIO) */
#define P10_0_PORT                      GPIO_PRT10
#define P10_0_PIN                       0u
#define P10_0_NUM                       0u
#define P10_1_PORT                      GPIO_PRT10
#define P10_1_PIN                       1u
#define P10_1_NUM                       1u
#define P10_2_PORT                      GPIO_PRT10
#define P10_2_PIN                       2u
#define P10_2_NUM                       2u
#define P10_3_PORT                      GPIO_PRT10
#define P10_3_PIN                       3u
#define P10_3_NUM                       3u
#define P10_4_PORT                      GPIO_PRT10
#define P10_4_PIN                       4u
#define P10_4_NUM                       4u
#define P10_5_PORT                      GPIO_PRT10
#define P10_5_PIN                       5u
#define P10_5_NUM                       5u
#define P10_6_PORT                      GPIO_PRT10
#define P10_6_PIN                       6u
#define P10_6_NUM                       6u
#define P10_7_PORT                      GPIO_PRT10
#define P10_7_PIN                       7u
#define P10_7_NUM                       7u

/* PORT 11 (GPIO_OVT) */
#define P11_0_PORT                      GPIO_PRT11
#define P11_0_PIN                       0u
#define P11_0_NUM                       0u
#define P11_1_PORT                      GPIO_PRT11
#define P11_1_PIN                       1u
#define P11_1_NUM                       1u
#define P11_2_PORT                      GPIO_PRT11
#define P11_2_PIN                       2u
#define P11_2_NUM                       2u
#define P11_3_PORT                      GPIO_PRT11
#define P11_3_PIN                       3u
#define P11_3_NUM                       3u
#define P11_4_PORT                      GPIO_PRT11
#define P11_4_PIN                       4u
#define P11_4_NUM                       4u
#define P11_5_PORT                      GPIO_PRT11
#define P11_5_PIN                       5u
#define P11_5_NUM                       5u
#define P11_6_PORT                      GPIO_PRT11
#define P11_6_PIN                       6u
#define P11_6_NUM                       6u
#define P11_7_PORT                      GPIO_PRT11
#define P11_7_PIN                       7u
#define P11_7_NUM                       7u

/* PORT 12 (GPIO) */
#define P12_0_PORT                      GPIO_PRT12
#define P12_0_PIN                       0u
#define P12_0_NUM                       0u
#define P12_1_PORT                      GPIO_PRT12
#define P12_1_PIN                       1u
#define P12_1_NUM                       1u
#define P12_2_PORT                      GPIO_PRT12
#define P12_2_PIN                       2u
#define P12_2_NUM                       2u
#define P12_3_PORT                      GPIO_PRT12
#define P12_3_PIN                       3u
#define P12_3_NUM                       3u
#define P12_4_PORT                      GPIO_PRT12
#define P12_4_PIN                       4u
#define P12_4_NUM                       4u
#define P12_5_PORT                      GPIO_PRT12
#define P12_5_PIN                       5u
#define P12_5_NUM                       5u

/* PORT 13 (GPIO) */
#define P13_0_PORT                      GPIO_PRT13
#define P13_0_PIN                       0u
#define P13_0_NUM                       0u
#define P13_1_PORT                      GPIO_PRT13
#define P13_1_PIN                       1u
#define P13_1_NUM                       1u
#define P13_2_PORT                      GPIO_PRT13
#define P13_2_PIN                       2u
#define P13_2_NUM                       2u
#define P13_3_PORT                      GPIO_PRT13
#define P13_3_PIN                       3u
#define P13_3_NUM                       3u
#define P13_4_PORT                      GPIO_PRT13
#define P13_4_PIN                       4u
#define P13_4_NUM                       4u
#define P13_5_PORT                      GPIO_PRT13
#define P13_5_PIN                       5u
#define P13_5_NUM                       5u
#define P13_6_PORT                      GPIO_PRT13
#define P13_6_PIN                       6u
#define P13_6_NUM                       6u
#define P13_7_PORT                      GPIO_PRT13
#define P13_7_PIN                       7u
#define P13_7_NUM                       7u

/* PORT 14 (GPIO) */
#define P14_0_PORT                      GPIO_PRT14
#define P14_0_PIN                       0u
#define P14_0_NUM                       0u
#define P14_1_PORT                      GPIO_PRT14
#define P14_1_PIN                       1u
#define P14_1_NUM                       1u
#define P14_2_PORT                      GPIO_PRT14
#define P14_2_PIN                       2u
#define P14_2_NUM                       2u
#define P14_3_PORT                      GPIO_PRT14
#define P14_3_PIN                       3u
#define P14_3_NUM                       3u
#define P14_4_PORT                      GPIO_PRT14
#define P14_4_PIN                       4u
#define P14_4_NUM                       4u
#define P14_5_PORT                      GPIO_PRT14
#define P14_5_PIN                       5u
#define P14_5_NUM                       5u
#define P14_6_PORT                      GPIO_PRT14
#define P14_6_PIN                       6u
#define P14_6_NUM                       6u
#define P14_7_PORT                      GPIO_PRT14
#define P14_7_PIN                       7u
#define P14_7_NUM                       7u

/* PORT 15 (GPIO) */
#define P15_0_PORT                      GPIO_PRT15
#define P15_0_PIN                       0u
#define P15_0_NUM                       0u
#define P15_0_AMUXSEGMENT               AMUXBUS_TEST
#define P15_1_PORT                      GPIO_PRT15
#define P15_1_PIN                       1u
#define P15_1_NUM                       1u
#define P15_2_PORT                      GPIO_PRT15
#define P15_2_PIN                       2u
#define P15_2_NUM                       2u
#define P15_3_PORT                      GPIO_PRT15
#define P15_3_PIN                       3u
#define P15_3_NUM                       3u
#define P15_4_PORT                      GPIO_PRT15
#define P15_4_PIN                       4u
#define P15_4_NUM                       4u
#define P15_5_PORT                      GPIO_PRT15
#define P15_5_PIN                       5u
#define P15_5_NUM                       5u
#define P15_6_PORT                      GPIO_PRT15
#define P15_6_PIN                       6u
#define P15_6_NUM                       6u
#define P15_7_PORT                      GPIO_PRT15
#define P15_7_PIN                       7u
#define P15_7_NUM                       7u

/* PORT 16 (GPIO) */
#define P16_0_PORT                      GPIO_PRT16
#define P16_0_PIN                       0u
#define P16_0_NUM                       0u
#define P16_1_PORT                      GPIO_PRT16
#define P16_1_PIN                       1u
#define P16_1_NUM                       1u
#define P16_2_PORT                      GPIO_PRT16
#define P16_2_PIN                       2u
#define P16_2_NUM                       2u
#define P16_3_PORT                      GPIO_PRT16
#define P16_3_PIN                       3u
#define P16_3_NUM                       3u
#define P16_4_PORT                      GPIO_PRT16
#define P16_4_PIN                       4u
#define P16_4_NUM                       4u
#define P16_5_PORT                      GPIO_PRT16
#define P16_5_PIN                       5u
#define P16_5_NUM                       5u
#define P16_6_PORT                      GPIO_PRT16
#define P16_6_PIN                       6u
#define P16_6_NUM                       6u
#define P16_7_PORT                      GPIO_PRT16
#define P16_7_PIN                       7u
#define P16_7_NUM                       7u

/* PORT 17 (GPIO) */
#define P17_0_PORT                      GPIO_PRT17
#define P17_0_PIN                       0u
#define P17_0_NUM                       0u
#define P17_1_PORT                      GPIO_PRT17
#define P17_1_PIN                       1u
#define P17_1_NUM                       1u
#define P17_2_PORT                      GPIO_PRT17
#define P17_2_PIN                       2u
#define P17_2_NUM                       2u
#define P17_3_PORT                      GPIO_PRT17
#define P17_3_PIN                       3u
#define P17_3_NUM                       3u
#define P17_4_PORT                      GPIO_PRT17
#define P17_4_PIN                       4u
#define P17_4_NUM                       4u
#define P17_5_PORT                      GPIO_PRT17
#define P17_5_PIN                       5u
#define P17_5_NUM                       5u
#define P17_6_PORT                      GPIO_PRT17
#define P17_6_PIN                       6u
#define P17_6_NUM                       6u
#define P17_7_PORT                      GPIO_PRT17
#define P17_7_PIN                       7u
#define P17_7_NUM                       7u

/* PORT 18 (GPIO) */
#define P18_0_PORT                      GPIO_PRT18
#define P18_0_PIN                       0u
#define P18_0_NUM                       0u
#define P18_1_PORT                      GPIO_PRT18
#define P18_1_PIN                       1u
#define P18_1_NUM                       1u

/* PORT 19 (GPIO) */
#define P19_0_PORT                      GPIO_PRT19
#define P19_0_PIN                       0u
#define P19_0_NUM                       0u
#define P19_1_PORT                      GPIO_PRT19
#define P19_1_PIN                       1u
#define P19_1_NUM                       1u

/* PORT 20 (GPIO) */
#define P20_0_PORT                      GPIO_PRT20
#define P20_0_PIN                       0u
#define P20_0_NUM                       0u
#define P20_1_PORT                      GPIO_PRT20
#define P20_1_PIN                       1u
#define P20_1_NUM                       1u
#define P20_2_PORT                      GPIO_PRT20
#define P20_2_PIN                       2u
#define P20_2_NUM                       2u
#define P20_3_PORT                      GPIO_PRT20
#define P20_3_PIN                       3u
#define P20_3_NUM                       3u
#define P20_4_PORT                      GPIO_PRT20
#define P20_4_PIN                       4u
#define P20_4_NUM                       4u
#define P20_5_PORT                      GPIO_PRT20
#define P20_5_PIN                       5u
#define P20_5_NUM                       5u
#define P20_6_PORT                      GPIO_PRT20
#define P20_6_PIN                       6u
#define P20_6_NUM                       6u
#define P20_7_PORT                      GPIO_PRT20
#define P20_7_PIN                       7u
#define P20_7_NUM                       7u

/* PORT 21 (GPIO) */
#define P21_0_PORT                      GPIO_PRT21
#define P21_0_PIN                       0u
#define P21_0_NUM                       0u
#define P21_1_PORT                      GPIO_PRT21
#define P21_1_PIN                       1u
#define P21_1_NUM                       1u
#define P21_2_PORT                      GPIO_PRT21
#define P21_2_PIN                       2u
#define P21_2_NUM                       2u
#define P21_3_PORT                      GPIO_PRT21
#define P21_3_PIN                       3u
#define P21_3_NUM                       3u
#define P21_4_PORT                      GPIO_PRT21
#define P21_4_PIN                       4u
#define P21_4_NUM                       4u
#define P21_5_PORT                      GPIO_PRT21
#define P21_5_PIN                       5u
#define P21_5_NUM                       5u
#define P21_6_PORT                      GPIO_PRT21
#define P21_6_PIN                       6u
#define P21_6_NUM                       6u
#define P21_7_PORT                      GPIO_PRT21
#define P21_7_PIN                       7u
#define P21_7_NUM                       7u

/* Analog Connections */
#define IOSS_ADFT0_NET0_PORT            15u
#define IOSS_ADFT0_NET0_PIN             0u
#define IOSS_ADFT1_NET0_PORT            15u
#define IOSS_ADFT1_NET0_PIN             1u
#define LPCOMP_INN_COMP0_PORT           10u
#define LPCOMP_INN_COMP0_PIN            5u
#define LPCOMP_INN_COMP1_PORT           10u
#define LPCOMP_INN_COMP1_PIN            7u
#define LPCOMP_INP_COMP0_PORT           10u
#define LPCOMP_INP_COMP0_PIN            4u
#define LPCOMP_INP_COMP1_PORT           10u
#define LPCOMP_INP_COMP1_PIN            6u
#define PASS_CTBL_OA0_OUT_10X0_PORT     14u
#define PASS_CTBL_OA0_OUT_10X0_PIN      2u
#define PASS_CTBL_OA0_OUT_10X1_PORT     13u
#define PASS_CTBL_OA0_OUT_10X1_PIN      2u
#define PASS_CTBL_OA1_OUT_10X0_PORT     14u
#define PASS_CTBL_OA1_OUT_10X0_PIN      3u
#define PASS_CTBL_OA1_OUT_10X1_PORT     13u
#define PASS_CTBL_OA1_OUT_10X1_PIN      3u
#define PASS_CTBL_PADS0_PORT            14u
#define PASS_CTBL_PADS0_PIN             0u
#define PASS_CTBL_PADS1_PORT            14u
#define PASS_CTBL_PADS1_PIN             1u
#define PASS_CTBL_PADS10_PORT           13u
#define PASS_CTBL_PADS10_PIN            2u
#define PASS_CTBL_PADS11_PORT           13u
#define PASS_CTBL_PADS11_PIN            3u
#define PASS_CTBL_PADS12_PORT           13u
#define PASS_CTBL_PADS12_PIN            4u
#define PASS_CTBL_PADS13_PORT           13u
#define PASS_CTBL_PADS13_PIN            5u
#define PASS_CTBL_PADS14_PORT           13u
#define PASS_CTBL_PADS14_PIN            6u
#define PASS_CTBL_PADS15_PORT           13u
#define PASS_CTBL_PADS15_PIN            7u
#define PASS_CTBL_PADS2_PORT            14u
#define PASS_CTBL_PADS2_PIN             2u
#define PASS_CTBL_PADS3_PORT            14u
#define PASS_CTBL_PADS3_PIN             3u
#define PASS_CTBL_PADS4_PORT            14u
#define PASS_CTBL_PADS4_PIN             4u
#define PASS_CTBL_PADS5_PORT            14u
#define PASS_CTBL_PADS5_PIN             5u
#define PASS_CTBL_PADS6_PORT            14u
#define PASS_CTBL_PADS6_PIN             6u
#define PASS_CTBL_PADS7_PORT            14u
#define PASS_CTBL_PADS7_PIN             7u
#define PASS_CTBL_PADS8_PORT            13u
#define PASS_CTBL_PADS8_PIN             0u
#define PASS_CTBL_PADS9_PORT            13u
#define PASS_CTBL_PADS9_PIN             1u
#define PASS_DAC_PADS0_PORT             14u
#define PASS_DAC_PADS0_PIN              6u
#define PASS_DAC_PADS1_PORT             13u
#define PASS_DAC_PADS1_PIN              6u
#define PASS_PTC_PADS0_PORT             15u
#define PASS_PTC_PADS0_PIN              0u
#define PASS_PTC_PADS1_PORT             15u
#define PASS_PTC_PADS1_PIN              1u
#define PASS_PTC_PADS2_PORT             15u
#define PASS_PTC_PADS2_PIN              2u
#define PASS_PTC_PADS3_PORT             15u
#define PASS_PTC_PADS3_PIN              3u
#define PASS_PTC_PADS4_PORT             15u
#define PASS_PTC_PADS4_PIN              4u
#define PASS_PTC_PADS5_PORT             15u
#define PASS_PTC_PADS5_PIN              5u
#define PASS_PTC_PADS6_PORT             15u
#define PASS_PTC_PADS6_PIN              6u
#define PASS_PTC_PADS7_PORT             15u
#define PASS_PTC_PADS7_PIN              7u
#define PASS_SARMUX_PADS0_PORT          15u
#define PASS_SARMUX_PADS0_PIN           0u
#define PASS_SARMUX_PADS1_PORT          15u
#define PASS_SARMUX_PADS1_PIN           1u
#define PASS_SARMUX_PADS2_PORT          15u
#define PASS_SARMUX_PADS2_PIN           2u
#define PASS_SARMUX_PADS3_PORT          15u
#define PASS_SARMUX_PADS3_PIN           3u
#define PASS_SARMUX_PADS4_PORT          15u
#define PASS_SARMUX_PADS4_PIN           4u
#define PASS_SARMUX_PADS5_PORT          15u
#define PASS_SARMUX_PADS5_PIN           5u
#define PASS_SARMUX_PADS6_PORT          15u
#define PASS_SARMUX_PADS6_PIN           6u
#define PASS_SARMUX_PADS7_PORT          15u
#define PASS_SARMUX_PADS7_PIN           7u
#define SRSS_ECO_IN_PORT                19u
#define SRSS_ECO_IN_PIN                 0u
#define SRSS_ECO_OUT_PORT               19u
#define SRSS_ECO_OUT_PIN                1u
#define SRSS_POR_TEST_ADFTPAD_HV_PORT   8u
#define SRSS_POR_TEST_ADFTPAD_HV_PIN    1u
#define SRSS_WCO_IN_PORT                18u
#define SRSS_WCO_IN_PIN                 1u
#define SRSS_WCO_OUT_PORT               18u
#define SRSS_WCO_OUT_PIN                0u

/* HSIOM Connections */
typedef enum
{
    /* Generic HSIOM connections */
    HSIOM_SEL_GPIO                  =  0,       /* GPIO controls 'out' */
    HSIOM_SEL_GPIO_DSI              =  1,       /* GPIO controls 'out', DSI controls 'output enable' */
    HSIOM_SEL_DSI_DSI               =  2,       /* DSI controls 'out' and 'output enable' */
    HSIOM_SEL_DSI_GPIO              =  3,       /* DSI controls 'out', GPIO controls 'output enable' */
    HSIOM_SEL_AMUXA                 =  4,       /* Analog mux bus A */
    HSIOM_SEL_AMUXB                 =  5,       /* Analog mux bus B */
    HSIOM_SEL_AMUXA_DSI             =  6,       /* Analog mux bus A, DSI control */
    HSIOM_SEL_AMUXB_DSI             =  7,       /* Analog mux bus B, DSI control */
    HSIOM_SEL_ACT_0                 =  8,       /* Active functionality 0 */
    HSIOM_SEL_ACT_1                 =  9,       /* Active functionality 1 */
    HSIOM_SEL_ACT_2                 = 10,       /* Active functionality 2 */
    HSIOM_SEL_ACT_3                 = 11,       /* Active functionality 3 */
    HSIOM_SEL_DS_0                  = 12,       /* DeepSleep functionality 0 */
    HSIOM_SEL_DS_1                  = 13,       /* DeepSleep functionality 1 */
    HSIOM_SEL_DS_2                  = 14,       /* DeepSleep functionality 2 */
    HSIOM_SEL_DS_3                  = 15,       /* DeepSleep functionality 3 */
    HSIOM_SEL_ACT_4                 = 16,       /* Active functionality 4 */
    HSIOM_SEL_ACT_5                 = 17,       /* Active functionality 5 */
    HSIOM_SEL_ACT_6                 = 18,       /* Active functionality 6 */
    HSIOM_SEL_ACT_7                 = 19,       /* Active functionality 7 */
    HSIOM_SEL_ACT_8                 = 20,       /* Active functionality 8 */
    HSIOM_SEL_ACT_9                 = 21,       /* Active functionality 9 */
    HSIOM_SEL_ACT_10                = 22,       /* Active functionality 10 */
    HSIOM_SEL_ACT_11                = 23,       /* Active functionality 11 */
    HSIOM_SEL_ACT_12                = 24,       /* Active functionality 12 */
    HSIOM_SEL_ACT_13                = 25,       /* Active functionality 13 */
    HSIOM_SEL_ACT_14                = 26,       /* Active functionality 14 */
    HSIOM_SEL_ACT_15                = 27,       /* Active functionality 15 */
    HSIOM_SEL_DS_4                  = 28,       /* DeepSleep functionality 4 */
    HSIOM_SEL_DS_5                  = 29,       /* DeepSleep functionality 5 */
    HSIOM_SEL_DS_6                  = 30,       /* DeepSleep functionality 6 */
    HSIOM_SEL_DS_7                  = 31,       /* DeepSleep functionality 7 */

    /* P0.0 */
    P0_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_0_SMIF1_SMIF0_SPIHB_SELECT1  =  8,       /* Digital Active - smif[1].smif0_spihb_select1 */
    P0_0_TCPWM0_LINE0               =  9,       /* Digital Active - tcpwm[0].line[0]:0 */
    P0_0_TCPWM0_LINE256             = 10,       /* Digital Active - tcpwm[0].line[256]:0 */
    P0_0_SCB3_SPI_SELECT0           = 16,       /* Digital Active - scb[3].spi_select0 */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_1_SMIF1_SMIF0_SPIHB_SELECT2  =  8,       /* Digital Active - smif[1].smif0_spihb_select2 */
    P0_1_TCPWM0_LINE_COMPL0         =  9,       /* Digital Active - tcpwm[0].line_compl[0]:0 */
    P0_1_TCPWM0_LINE_COMPL256       = 10,       /* Digital Active - tcpwm[0].line_compl[256]:0 */

    /* SMIF0_SPIHB_DATA0 */
    SMIF0_SPIHB_DATA0_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF0_SPIHB_DATA0_TCPWM0_LINE1  =  9,       /* Digital Active - tcpwm[0].line[1]:0 */
    SMIF0_SPIHB_DATA0_TCPWM0_LINE257 = 10,      /* Digital Active - tcpwm[0].line[257]:0 */

    /* SMIF0_SPIHB_DATA1 */
    SMIF0_SPIHB_DATA1_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF0_SPIHB_DATA1_TCPWM0_LINE_COMPL1 =  9,  /* Digital Active - tcpwm[0].line_compl[1]:0 */
    SMIF0_SPIHB_DATA1_TCPWM0_LINE_COMPL257 = 10, /* Digital Active - tcpwm[0].line_compl[257]:0 */

    /* SMIF0_SPIHB_DATA2 */
    SMIF0_SPIHB_DATA2_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF0_SPIHB_DATA2_TCPWM0_LINE2  =  9,       /* Digital Active - tcpwm[0].line[2]:0 */
    SMIF0_SPIHB_DATA2_TCPWM0_LINE258 = 10,      /* Digital Active - tcpwm[0].line[258]:0 */

    /* SMIF0_SPIHB_DATA3 */
    SMIF0_SPIHB_DATA3_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF0_SPIHB_DATA3_TCPWM0_LINE_COMPL2 =  9,  /* Digital Active - tcpwm[0].line_compl[2]:0 */
    SMIF0_SPIHB_DATA3_TCPWM0_LINE_COMPL258 = 10, /* Digital Active - tcpwm[0].line_compl[258]:0 */

    /* SMIF0_SPIHB_DATA4 */
    SMIF0_SPIHB_DATA4_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF0_SPIHB_DATA4_TCPWM0_LINE3  =  9,       /* Digital Active - tcpwm[0].line[3]:0 */
    SMIF0_SPIHB_DATA4_TCPWM0_LINE259 = 10,      /* Digital Active - tcpwm[0].line[259]:0 */

    /* SMIF0_SPIHB_DATA5 */
    SMIF0_SPIHB_DATA5_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF0_SPIHB_DATA5_TCPWM0_LINE_COMPL3 =  9,  /* Digital Active - tcpwm[0].line_compl[3]:0 */
    SMIF0_SPIHB_DATA5_TCPWM0_LINE_COMPL259 = 10, /* Digital Active - tcpwm[0].line_compl[259]:0 */

    /* SMIF0_SPIHB_DATA6 */
    SMIF0_SPIHB_DATA6_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF0_SPIHB_DATA6_TCPWM0_LINE4  =  9,       /* Digital Active - tcpwm[0].line[4]:0 */
    SMIF0_SPIHB_DATA6_TCPWM0_LINE260 = 10,      /* Digital Active - tcpwm[0].line[260]:0 */

    /* SMIF0_SPIHB_DATA7 */
    SMIF0_SPIHB_DATA7_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF0_SPIHB_DATA7_TCPWM0_LINE_COMPL4 =  9,  /* Digital Active - tcpwm[0].line_compl[4]:0 */
    SMIF0_SPIHB_DATA7_TCPWM0_LINE_COMPL260 = 10, /* Digital Active - tcpwm[0].line_compl[260]:0 */

    /* P2.0 */
    P2_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_0_SMIF0_SMIF0_SPIHB_SELECT1  =  8,       /* Digital Active - smif[0].smif0_spihb_select1 */
    P2_0_TCPWM0_LINE5               =  9,       /* Digital Active - tcpwm[0].line[5]:0 */
    P2_0_TCPWM0_LINE261             = 10,       /* Digital Active - tcpwm[0].line[261]:0 */
    P2_0_DFT_RODIV8K                = 27,       /* Digital Active - dft.ROdiv8k */

    /* P3.0 */
    P3_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_0_TCPWM0_LINE_COMPL5         =  9,       /* Digital Active - tcpwm[0].line_compl[5]:0 */
    P3_0_TCPWM0_LINE_COMPL261       = 10,       /* Digital Active - tcpwm[0].line_compl[261]:0 */
    P3_0_SDHC1_CARD_MECH_WRITE_PROT = 26,       /* Digital Active - sdhc[1].card_mech_write_prot:1 */
    P3_0_I3C_I3C_SCL                = 27,       /* Digital Active - i3c.i3c_scl */

    /* P3.1 */
    P3_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_1_TCPWM0_LINE6               =  9,       /* Digital Active - tcpwm[0].line[6]:0 */
    P3_1_TCPWM0_LINE262             = 10,       /* Digital Active - tcpwm[0].line[262]:0 */
    P3_1_I3C_I3C_SDA                = 27,       /* Digital Active - i3c.i3c_sda */

    /* SMIF1_SPIHB_DATA0 */
    SMIF1_SPIHB_DATA0_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF1_SPIHB_DATA0_TCPWM0_LINE_COMPL6 =  9,  /* Digital Active - tcpwm[0].line_compl[6]:0 */
    SMIF1_SPIHB_DATA0_TCPWM0_LINE_COMPL262 = 10, /* Digital Active - tcpwm[0].line_compl[262]:0 */

    /* SMIF1_SPIHB_DATA1 */
    SMIF1_SPIHB_DATA1_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF1_SPIHB_DATA1_TCPWM0_LINE7  =  9,       /* Digital Active - tcpwm[0].line[7]:0 */
    SMIF1_SPIHB_DATA1_TCPWM0_LINE263 = 10,      /* Digital Active - tcpwm[0].line[263]:0 */

    /* SMIF1_SPIHB_DATA2 */
    SMIF1_SPIHB_DATA2_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF1_SPIHB_DATA2_TCPWM0_LINE_COMPL7 =  9,  /* Digital Active - tcpwm[0].line_compl[7]:0 */
    SMIF1_SPIHB_DATA2_TCPWM0_LINE_COMPL263 = 10, /* Digital Active - tcpwm[0].line_compl[263]:0 */

    /* SMIF1_SPIHB_DATA3 */
    SMIF1_SPIHB_DATA3_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF1_SPIHB_DATA3_TCPWM0_LINE0  =  9,       /* Digital Active - tcpwm[0].line[0]:1 */
    SMIF1_SPIHB_DATA3_TCPWM0_LINE264 = 10,      /* Digital Active - tcpwm[0].line[264]:0 */
    SMIF1_SPIHB_DATA3_DEBUG600_TRACE_CLOCK = 27, /* Digital Active - debug600.trace_clock:0 */

    /* SMIF1_SPIHB_DATA4 */
    SMIF1_SPIHB_DATA4_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF1_SPIHB_DATA4_TCPWM0_LINE_COMPL0 =  9,  /* Digital Active - tcpwm[0].line_compl[0]:1 */
    SMIF1_SPIHB_DATA4_TCPWM0_LINE_COMPL264 = 10, /* Digital Active - tcpwm[0].line_compl[264]:0 */
    SMIF1_SPIHB_DATA4_DEBUG600_TRACE_DATA0 = 27, /* Digital Active - debug600.trace_data[0]:0 */

    /* SMIF1_SPIHB_DATA5 */
    SMIF1_SPIHB_DATA5_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF1_SPIHB_DATA5_TCPWM0_LINE1  =  9,       /* Digital Active - tcpwm[0].line[1]:1 */
    SMIF1_SPIHB_DATA5_TCPWM0_LINE265 = 10,      /* Digital Active - tcpwm[0].line[265]:0 */
    SMIF1_SPIHB_DATA5_DEBUG600_TRACE_DATA1 = 27, /* Digital Active - debug600.trace_data[1]:0 */

    /* SMIF1_SPIHB_DATA6 */
    SMIF1_SPIHB_DATA6_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF1_SPIHB_DATA6_TCPWM0_LINE_COMPL1 =  9,  /* Digital Active - tcpwm[0].line_compl[1]:1 */
    SMIF1_SPIHB_DATA6_TCPWM0_LINE_COMPL265 = 10, /* Digital Active - tcpwm[0].line_compl[265]:0 */
    SMIF1_SPIHB_DATA6_DEBUG600_TRACE_DATA2 = 27, /* Digital Active - debug600.trace_data[2]:0 */

    /* SMIF1_SPIHB_DATA7 */
    SMIF1_SPIHB_DATA7_GPIO          =  0,       /* GPIO controls 'out' */
    SMIF1_SPIHB_DATA7_TCPWM0_LINE2  =  9,       /* Digital Active - tcpwm[0].line[2]:1 */
    SMIF1_SPIHB_DATA7_TCPWM0_LINE266 = 10,      /* Digital Active - tcpwm[0].line[266]:0 */
    SMIF1_SPIHB_DATA7_DEBUG600_TRACE_DATA3 = 27, /* Digital Active - debug600.trace_data[3]:0 */

    /* P5.0 */
    P5_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_0_SMIF0_SMIF0_SPIHB_SELECT0  =  8,       /* Digital Active - smif[0].smif0_spihb_select0 */
    P5_0_TCPWM0_LINE_COMPL2         =  9,       /* Digital Active - tcpwm[0].line_compl[2]:1 */
    P5_0_TCPWM0_LINE_COMPL266       = 10,       /* Digital Active - tcpwm[0].line_compl[266]:0 */

    /* P6.0 */
    P6_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_0_TCPWM0_LINE3               =  9,       /* Digital Active - tcpwm[0].line[3]:1 */
    P6_0_TCPWM0_LINE267             = 10,       /* Digital Active - tcpwm[0].line[267]:0 */
    P6_0_SDHC1_CARD_MECH_WRITE_PROT = 26,       /* Digital Active - sdhc[1].card_mech_write_prot:0 */
    P6_0_DEBUG600_SWJ_SWO_TDO       = 29,       /* Digital Deep Sleep - debug600.swj_swo_tdo */
    P6_0_IOSS_DDFT_PIN0             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[0]:1 */

    /* P6.1 */
    P6_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_1_TCPWM0_LINE_COMPL3         =  9,       /* Digital Active - tcpwm[0].line_compl[3]:1 */
    P6_1_TCPWM0_LINE_COMPL267       = 10,       /* Digital Active - tcpwm[0].line_compl[267]:0 */
    P6_1_SDHC1_LED_CTRL             = 27,       /* Digital Active - sdhc[1].led_ctrl */
    P6_1_DEBUG600_SWJ_SWDOE_TDI     = 29,       /* Digital Deep Sleep - debug600.swj_swdoe_tdi */
    P6_1_IOSS_DDFT_PIN0             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[0]:0 */

    /* P6.2 */
    P6_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_2_TCPWM0_LINE4               =  9,       /* Digital Active - tcpwm[0].line[4]:1 */
    P6_2_TCPWM0_LINE268             = 10,       /* Digital Active - tcpwm[0].line[268]:0 */
    P6_2_SDHC1_CARD_IF_PWR_EN       = 27,       /* Digital Active - sdhc[1].card_if_pwr_en */
    P6_2_DEBUG600_SWJ_SWDIO_TMS     = 29,       /* Digital Deep Sleep - debug600.swj_swdio_tms */

    /* P6.3 */
    P6_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_3_TCPWM0_LINE_COMPL4         =  9,       /* Digital Active - tcpwm[0].line_compl[4]:1 */
    P6_3_TCPWM0_LINE_COMPL268       = 10,       /* Digital Active - tcpwm[0].line_compl[268]:0 */
    P6_3_SCB2_SPI_SELECT1           = 18,       /* Digital Active - scb[2].spi_select1 */
    P6_3_SDHC1_IO_VOLT_SEL          = 27,       /* Digital Active - sdhc[1].io_volt_sel */
    P6_3_DEBUG600_CLK_SWJ_SWCLK_TCLK = 29,      /* Digital Deep Sleep - debug600.clk_swj_swclk_tclk */

    /* P6.4 */
    P6_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_4_TCPWM0_LINE5               =  9,       /* Digital Active - tcpwm[0].line[5]:1 */
    P6_4_TCPWM0_LINE269             = 10,       /* Digital Active - tcpwm[0].line[269]:0 */
    P6_4_SCB2_SPI_MISO              = 18,       /* Digital Active - scb[2].spi_miso */
    P6_4_SCB2_UART_CTS              = 20,       /* Digital Active - scb[2].uart_cts:0 */
    P6_4_SDHC1_CARD_DAT_7TO40       = 27,       /* Digital Active - sdhc[1].card_dat_7to4[0] */

    /* P6.5 */
    P6_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_5_TCPWM0_LINE_COMPL5         =  9,       /* Digital Active - tcpwm[0].line_compl[5]:1 */
    P6_5_TCPWM0_LINE_COMPL269       = 10,       /* Digital Active - tcpwm[0].line_compl[269]:0 */
    P6_5_SCB2_SPI_CLK               = 18,       /* Digital Active - scb[2].spi_clk */
    P6_5_SCB2_I2C_SCL               = 19,       /* Digital Active - scb[2].i2c_scl:0 */
    P6_5_SCB2_UART_RX               = 20,       /* Digital Active - scb[2].uart_rx:0 */
    P6_5_SDHC1_CARD_DAT_7TO41       = 27,       /* Digital Active - sdhc[1].card_dat_7to4[1] */

    /* P6.6 */
    P6_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_6_TCPWM0_LINE6               =  9,       /* Digital Active - tcpwm[0].line[6]:1 */
    P6_6_TCPWM0_LINE270             = 10,       /* Digital Active - tcpwm[0].line[270]:0 */
    P6_6_SCB2_SPI_SELECT0           = 18,       /* Digital Active - scb[2].spi_select0 */
    P6_6_SCB2_UART_RTS              = 20,       /* Digital Active - scb[2].uart_rts:0 */
    P6_6_SDHC1_CARD_DAT_7TO42       = 27,       /* Digital Active - sdhc[1].card_dat_7to4[2] */

    /* P6.7 */
    P6_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_7_SMIF0_SMIF0_SPIHB_SELECT2  =  8,       /* Digital Active - smif[0].smif0_spihb_select2 */
    P6_7_TCPWM0_LINE_COMPL6         =  9,       /* Digital Active - tcpwm[0].line_compl[6]:1 */
    P6_7_TCPWM0_LINE_COMPL270       = 10,       /* Digital Active - tcpwm[0].line_compl[270]:0 */
    P6_7_SCB2_SPI_MOSI              = 18,       /* Digital Active - scb[2].spi_mosi */
    P6_7_SCB2_I2C_SDA               = 19,       /* Digital Active - scb[2].i2c_sda:0 */
    P6_7_SCB2_UART_TX               = 20,       /* Digital Active - scb[2].uart_tx:0 */
    P6_7_SDHC1_CARD_DAT_7TO43       = 27,       /* Digital Active - sdhc[1].card_dat_7to4[3] */

    /* P7.0 */
    P7_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_0_SMIF0_SMIF0_SPIHB_SELECT3  =  8,       /* Digital Active - smif[0].smif0_spihb_select3 */
    P7_0_TCPWM0_LINE7               =  9,       /* Digital Active - tcpwm[0].line[7]:1 */
    P7_0_TCPWM0_LINE271             = 10,       /* Digital Active - tcpwm[0].line[271]:0 */
    P7_0_M33SYSCPUSS_FAULT0         = 11,       /* Digital Active - m33syscpuss.fault[0]:0 */
    P7_0_PERI0_TR_IO_OUTPUT0        = 22,       /* Digital Active - peri[0].tr_io_output[0]:0 */
    P7_0_PERI1_TR_IO_OUTPUT0        = 23,       /* Digital Active - peri[1].tr_io_output[0]:0 */
    P7_0_SDHC1_CARD_CMD             = 27,       /* Digital Active - sdhc[1].card_cmd */

    /* P7.1 */
    P7_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_1_TCPWM0_LINE_COMPL7         =  9,       /* Digital Active - tcpwm[0].line_compl[7]:1 */
    P7_1_TCPWM0_LINE_COMPL271       = 10,       /* Digital Active - tcpwm[0].line_compl[271]:0 */
    P7_1_M33SYSCPUSS_FAULT1         = 11,       /* Digital Active - m33syscpuss.fault[1]:0 */
    P7_1_PERI0_TR_IO_OUTPUT1        = 22,       /* Digital Active - peri[0].tr_io_output[1]:0 */
    P7_1_PERI1_TR_IO_OUTPUT1        = 23,       /* Digital Active - peri[1].tr_io_output[1]:0 */
    P7_1_SDHC1_CLK_CARD             = 27,       /* Digital Active - sdhc[1].clk_card */

    /* P7.2 */
    P7_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_2_TCPWM0_LINE0               =  9,       /* Digital Active - tcpwm[0].line[0]:2 */
    P7_2_TCPWM0_LINE272             = 10,       /* Digital Active - tcpwm[0].line[272]:0 */
    P7_2_SDHC1_CARD_EMMC_RESET_N    = 27,       /* Digital Active - sdhc[1].card_emmc_reset_n */
    P7_2_DEBUG600_RST_SWJ_TRSTN     = 29,       /* Digital Deep Sleep - debug600.rst_swj_trstn */
    P7_2_IOSS_DDFT_PIN1             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[1]:1 */

    /* P7.3 */
    P7_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_3_TCPWM0_LINE_COMPL0         =  9,       /* Digital Active - tcpwm[0].line_compl[0]:2 */
    P7_3_TCPWM0_LINE_COMPL272       = 10,       /* Digital Active - tcpwm[0].line_compl[272]:0 */
    P7_3_SDHC1_CARD_DAT_3TO00       = 27,       /* Digital Active - sdhc[1].card_dat_3to0[0] */

    /* P7.4 */
    P7_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_4_TCPWM0_LINE1               =  9,       /* Digital Active - tcpwm[0].line[1]:2 */
    P7_4_TCPWM0_LINE273             = 10,       /* Digital Active - tcpwm[0].line[273]:0 */
    P7_4_SRSS_EXT_CLK               = 16,       /* Digital Active - srss.ext_clk */
    P7_4_SDHC1_CARD_DETECT_N        = 27,       /* Digital Active - sdhc[1].card_detect_n */
    P7_4_IOSS_DDFT_PIN1             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[1]:0 */

    /* P7.5 */
    P7_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_5_TCPWM0_LINE_COMPL1         =  9,       /* Digital Active - tcpwm[0].line_compl[1]:2 */
    P7_5_TCPWM0_LINE_COMPL273       = 10,       /* Digital Active - tcpwm[0].line_compl[273]:0 */
    P7_5_PERI0_TR_IO_INPUT4         = 22,       /* Digital Active - peri[0].tr_io_input[4]:0 */
    P7_5_PERI1_TR_IO_INPUT4         = 23,       /* Digital Active - peri[1].tr_io_input[4]:0 */
    P7_5_SDHC1_CARD_DAT_3TO01       = 27,       /* Digital Active - sdhc[1].card_dat_3to0[1] */

    /* P7.6 */
    P7_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_6_TCPWM0_LINE2               =  9,       /* Digital Active - tcpwm[0].line[2]:2 */
    P7_6_TCPWM0_LINE274             = 10,       /* Digital Active - tcpwm[0].line[274]:0 */
    P7_6_PERI0_TR_IO_INPUT5         = 22,       /* Digital Active - peri[0].tr_io_input[5]:0 */
    P7_6_PERI1_TR_IO_INPUT5         = 23,       /* Digital Active - peri[1].tr_io_input[5]:0 */
    P7_6_SDHC1_CARD_DAT_3TO02       = 27,       /* Digital Active - sdhc[1].card_dat_3to0[2] */

    /* P7.7 */
    P7_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_7_TCPWM0_LINE_COMPL2         =  9,       /* Digital Active - tcpwm[0].line_compl[2]:2 */
    P7_7_TCPWM0_LINE_COMPL274       = 10,       /* Digital Active - tcpwm[0].line_compl[274]:0 */
    P7_7_PERI0_TR_IO_INPUT6         = 22,       /* Digital Active - peri[0].tr_io_input[6]:0 */
    P7_7_PERI1_TR_IO_INPUT6         = 23,       /* Digital Active - peri[1].tr_io_input[6]:0 */
    P7_7_SDHC1_CARD_DAT_3TO03       = 27,       /* Digital Active - sdhc[1].card_dat_3to0[3] */

    /* P8.0 */
    P8_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_0_TCPWM0_LINE3               =  9,       /* Digital Active - tcpwm[0].line[3]:2 */
    P8_0_TCPWM0_LINE275             = 10,       /* Digital Active - tcpwm[0].line[275]:0 */
    P8_0_SCB0_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[0].spi_clk */
    P8_0_SCB0_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */
    P8_0_PERI0_TR_IO_INPUT7         = 22,       /* Digital Active - peri[0].tr_io_input[7]:0 */
    P8_0_PERI1_TR_IO_INPUT7         = 23,       /* Digital Active - peri[1].tr_io_input[7]:0 */
    P8_0_M0SECCPUSS_M0SEC_SWD       = 29,       /* Digital Deep Sleep - m0seccpuss.m0sec_swd */

    /* P8.1 */
    P8_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_1_TCPWM0_LINE_COMPL3         =  9,       /* Digital Active - tcpwm[0].line_compl[3]:2 */
    P8_1_TCPWM0_LINE_COMPL275       = 10,       /* Digital Active - tcpwm[0].line_compl[275]:0 */
    P8_1_SCB0_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[0].spi_mosi */
    P8_1_SCB0_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */
    P8_1_M0SECCPUSS_CLK_M0SEC_SWD   = 29,       /* Digital Deep Sleep - m0seccpuss.clk_m0sec_swd */

    /* P8.2 */
    P8_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_2_TCPWM0_LINE4               =  9,       /* Digital Active - tcpwm[0].line[4]:2 */
    P8_2_TCPWM0_LINE276             = 10,       /* Digital Active - tcpwm[0].line[276]:0 */
    P8_2_SCB0_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[0].spi_select0 */
    P8_2_PDM_PDM_CLK2               = 21,       /* Digital Active - pdm.pdm_clk[2] */

    /* P8.3 */
    P8_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_3_TCPWM0_LINE_COMPL4         =  9,       /* Digital Active - tcpwm[0].line_compl[4]:2 */
    P8_3_TCPWM0_LINE_COMPL276       = 10,       /* Digital Active - tcpwm[0].line_compl[276]:0 */
    P8_3_SCB0_SPI_SELECT1           = 14,       /* Digital Deep Sleep - scb[0].spi_select1 */

    /* P8.4 */
    P8_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_4_TCPWM0_LINE5               =  9,       /* Digital Active - tcpwm[0].line[5]:2 */
    P8_4_TCPWM0_LINE277             = 10,       /* Digital Active - tcpwm[0].line[277]:0 */
    P8_4_SCB0_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[0].spi_miso */
    P8_4_SRSS_CAL_WAVE              = 15,       /* Digital Deep Sleep - srss.cal_wave */
    P8_4_PDM_PDM_DATA2              = 21,       /* Digital Active - pdm.pdm_data[2] */

    /* P8.5 */
    P8_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_5_TCPWM0_LINE_COMPL5         =  9,       /* Digital Active - tcpwm[0].line_compl[5]:2 */
    P8_5_TCPWM0_LINE_COMPL277       = 10,       /* Digital Active - tcpwm[0].line_compl[277]:0 */
    P8_5_PDM_PDM_CLK3               = 21,       /* Digital Active - pdm.pdm_clk[3] */

    /* P8.6 */
    P8_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_6_TCPWM0_LINE6               =  9,       /* Digital Active - tcpwm[0].line[6]:2 */
    P8_6_TCPWM0_LINE278             = 10,       /* Digital Active - tcpwm[0].line[278]:0 */
    P8_6_PDM_PDM_DATA3              = 21,       /* Digital Active - pdm.pdm_data[3] */

    /* P8.7 */
    P8_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_7_TCPWM0_LINE_COMPL6         =  9,       /* Digital Active - tcpwm[0].line_compl[6]:2 */
    P8_7_TCPWM0_LINE_COMPL278       = 10,       /* Digital Active - tcpwm[0].line_compl[278]:0 */
    P8_7_SRSS_DDFT_CLK_DIRECT       = 27,       /* Digital Active - srss.ddft_clk_direct */

    /* P9.0 */
    P9_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_0_TCPWM0_LINE7               =  9,       /* Digital Active - tcpwm[0].line[7]:2 */
    P9_0_TCPWM0_LINE_COMPL279       = 10,       /* Digital Active - tcpwm[0].line_compl[279]:0 */
    P9_0_SCB1_SPI_SELECT0           = 18,       /* Digital Active - scb[1].spi_select0 */
    P9_0_SCB1_UART_RTS              = 20,       /* Digital Active - scb[1].uart_rts:0 */
    P9_0_PDM_PDM_CLK5               = 21,       /* Digital Active - pdm.pdm_clk[5] */

    /* P9.1 */
    P9_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_1_TCPWM0_LINE0               =  9,       /* Digital Active - tcpwm[0].line[0]:3 */
    P9_1_TCPWM0_LINE_COMPL256       = 10,       /* Digital Active - tcpwm[0].line_compl[256]:1 */
    P9_1_SCB1_SPI_MISO              = 18,       /* Digital Active - scb[1].spi_miso */
    P9_1_SCB1_UART_CTS              = 20,       /* Digital Active - scb[1].uart_cts:0 */
    P9_1_PDM_PDM_DATA5              = 21,       /* Digital Active - pdm.pdm_data[5] */

    /* P9.2 */
    P9_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_2_TCPWM0_LINE_COMPL7         =  9,       /* Digital Active - tcpwm[0].line_compl[7]:2 */
    P9_2_TCPWM0_LINE279             = 10,       /* Digital Active - tcpwm[0].line[279]:0 */
    P9_2_SCB1_SPI_MOSI              = 18,       /* Digital Active - scb[1].spi_mosi */
    P9_2_SCB1_I2C_SDA               = 19,       /* Digital Active - scb[1].i2c_sda:0 */
    P9_2_SCB1_UART_TX               = 20,       /* Digital Active - scb[1].uart_tx:0 */
    P9_2_PDM_PDM_CLK4               = 21,       /* Digital Active - pdm.pdm_clk[4] */

    /* P9.3 */
    P9_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_3_TCPWM0_LINE_COMPL0         =  9,       /* Digital Active - tcpwm[0].line_compl[0]:3 */
    P9_3_TCPWM0_LINE256             = 10,       /* Digital Active - tcpwm[0].line[256]:1 */
    P9_3_SCB1_SPI_CLK               = 18,       /* Digital Active - scb[1].spi_clk */
    P9_3_SCB1_I2C_SCL               = 19,       /* Digital Active - scb[1].i2c_scl:0 */
    P9_3_SCB1_UART_RX               = 20,       /* Digital Active - scb[1].uart_rx:0 */
    P9_3_PDM_PDM_DATA4              = 21,       /* Digital Active - pdm.pdm_data[4] */

    /* P10.0 */
    P10_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_0_TCPWM0_LINE1              =  9,       /* Digital Active - tcpwm[0].line[1]:3 */
    P10_0_TCPWM0_LINE257            = 10,       /* Digital Active - tcpwm[0].line[257]:1 */
    P10_0_M33SYSCPUSS_FAULT0        = 11,       /* Digital Active - m33syscpuss.fault[0]:1 */
    P10_0_SCB4_I2C_SCL              = 19,       /* Digital Active - scb[4].i2c_scl:0 */
    P10_0_SCB4_UART_RX              = 20,       /* Digital Active - scb[4].uart_rx:0 */
    P10_0_ETH_TXD3                  = 27,       /* Digital Active - eth.txd[3] */

    /* P10.1 */
    P10_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_1_TCPWM0_LINE_COMPL1        =  9,       /* Digital Active - tcpwm[0].line_compl[1]:3 */
    P10_1_TCPWM0_LINE_COMPL257      = 10,       /* Digital Active - tcpwm[0].line_compl[257]:1 */
    P10_1_M33SYSCPUSS_FAULT1        = 11,       /* Digital Active - m33syscpuss.fault[1]:1 */
    P10_1_SCB4_SPI_CLK              = 18,       /* Digital Active - scb[4].spi_clk */
    P10_1_SCB4_I2C_SDA              = 19,       /* Digital Active - scb[4].i2c_sda:0 */
    P10_1_SCB4_UART_TX              = 20,       /* Digital Active - scb[4].uart_tx:0 */
    P10_1_ETH_RX_CLK                = 27,       /* Digital Active - eth.rx_clk */

    /* P10.2 */
    P10_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_2_TCPWM0_LINE2              =  9,       /* Digital Active - tcpwm[0].line[2]:3 */
    P10_2_TCPWM0_LINE258            = 10,       /* Digital Active - tcpwm[0].line[258]:1 */
    P10_2_LPCOMP_DSI_COMP1          = 15,       /* Digital Deep Sleep - lpcomp.dsi_comp1 */
    P10_2_SCB4_SPI_MOSI             = 18,       /* Digital Active - scb[4].spi_mosi */
    P10_2_SCB4_UART_CTS             = 20,       /* Digital Active - scb[4].uart_cts:0 */
    P10_2_ETH_TX_ER                 = 27,       /* Digital Active - eth.tx_er */

    /* P10.3 */
    P10_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_3_TCPWM0_LINE_COMPL2        =  9,       /* Digital Active - tcpwm[0].line_compl[2]:3 */
    P10_3_TCPWM0_LINE_COMPL258      = 10,       /* Digital Active - tcpwm[0].line_compl[258]:1 */
    P10_3_LPCOMP_DSI_COMP0          = 15,       /* Digital Deep Sleep - lpcomp.dsi_comp0 */
    P10_3_SCB4_SPI_MISO             = 18,       /* Digital Active - scb[4].spi_miso */
    P10_3_SCB4_UART_RTS             = 20,       /* Digital Active - scb[4].uart_rts:0 */
    P10_3_ETH_ETH_TSU_TIMER_CMP_VAL = 27,       /* Digital Active - eth.eth_tsu_timer_cmp_val */

    /* P10.4 */
    P10_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_4_TCPWM0_LINE3              =  9,       /* Digital Active - tcpwm[0].line[3]:3 */
    P10_4_TCPWM0_LINE259            = 10,       /* Digital Active - tcpwm[0].line[259]:1 */
    P10_4_SCB4_SPI_SELECT0          = 18,       /* Digital Active - scb[4].spi_select0 */
    P10_4_ETH_RXD3                  = 27,       /* Digital Active - eth.rxd[3] */

    /* P10.5 */
    P10_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_5_TCPWM0_LINE_COMPL3        =  9,       /* Digital Active - tcpwm[0].line_compl[3]:3 */
    P10_5_TCPWM0_LINE_COMPL259      = 10,       /* Digital Active - tcpwm[0].line_compl[259]:1 */
    P10_5_SCB4_SPI_SELECT1          = 18,       /* Digital Active - scb[4].spi_select1 */
    P10_5_ETH_RX_CTL                = 27,       /* Digital Active - eth.rx_ctl */

    /* P10.6 */
    P10_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_6_TCPWM0_LINE4              =  9,       /* Digital Active - tcpwm[0].line[4]:3 */
    P10_6_TCPWM0_LINE260            = 10,       /* Digital Active - tcpwm[0].line[260]:1 */
    P10_6_ETH_RXD0                  = 27,       /* Digital Active - eth.rxd[0] */

    /* P10.7 */
    P10_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_7_TCPWM0_LINE_COMPL4        =  9,       /* Digital Active - tcpwm[0].line_compl[4]:3 */
    P10_7_TCPWM0_LINE_COMPL260      = 10,       /* Digital Active - tcpwm[0].line_compl[260]:1 */
    P10_7_ETH_RXD1                  = 27,       /* Digital Active - eth.rxd[1] */

    /* P11.0 */
    P11_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_0_TCPWM0_LINE5              =  9,       /* Digital Active - tcpwm[0].line[5]:3 */
    P11_0_TCPWM0_LINE261            = 10,       /* Digital Active - tcpwm[0].line[261]:1 */
    P11_0_TDM_TDM_TX_SCK1           = 17,       /* Digital Active - tdm.tdm_tx_sck[1] */
    P11_0_SCB6_SPI_CLK              = 18,       /* Digital Active - scb[6].spi_clk */
    P11_0_SCB6_I2C_SCL              = 19,       /* Digital Active - scb[6].i2c_scl:0 */
    P11_0_SCB6_UART_RX              = 20,       /* Digital Active - scb[6].uart_rx:0 */
    P11_0_PERI0_TR_IO_INPUT0        = 22,       /* Digital Active - peri[0].tr_io_input[0]:0 */
    P11_0_PERI1_TR_IO_INPUT0        = 23,       /* Digital Active - peri[1].tr_io_input[0]:0 */
    P11_0_ETH_RXD2                  = 27,       /* Digital Active - eth.rxd[2] */

    /* P11.1 */
    P11_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_1_TCPWM0_LINE_COMPL5        =  9,       /* Digital Active - tcpwm[0].line_compl[5]:3 */
    P11_1_TCPWM0_LINE_COMPL261      = 10,       /* Digital Active - tcpwm[0].line_compl[261]:1 */
    P11_1_TDM_TDM_TX_FSYNC1         = 17,       /* Digital Active - tdm.tdm_tx_fsync[1] */
    P11_1_SCB6_SPI_MOSI             = 18,       /* Digital Active - scb[6].spi_mosi */
    P11_1_SCB6_I2C_SDA              = 19,       /* Digital Active - scb[6].i2c_sda:0 */
    P11_1_SCB6_UART_TX              = 20,       /* Digital Active - scb[6].uart_tx:0 */
    P11_1_PERI0_TR_IO_INPUT1        = 22,       /* Digital Active - peri[0].tr_io_input[1]:0 */
    P11_1_PERI1_TR_IO_INPUT1        = 23,       /* Digital Active - peri[1].tr_io_input[1]:0 */
    P11_1_ETH_RX_ER                 = 27,       /* Digital Active - eth.rx_er */

    /* P11.2 */
    P11_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_2_TCPWM0_LINE6              =  9,       /* Digital Active - tcpwm[0].line[6]:3 */
    P11_2_TCPWM0_LINE262            = 10,       /* Digital Active - tcpwm[0].line[262]:1 */
    P11_2_TDM_TDM_TX_SD1            = 17,       /* Digital Active - tdm.tdm_tx_sd[1] */
    P11_2_SCB6_SPI_MISO             = 18,       /* Digital Active - scb[6].spi_miso */
    P11_2_SCB6_UART_CTS             = 20,       /* Digital Active - scb[6].uart_cts:0 */
    P11_2_PERI0_TR_IO_INPUT2        = 22,       /* Digital Active - peri[0].tr_io_input[2]:0 */
    P11_2_PERI1_TR_IO_INPUT2        = 23,       /* Digital Active - peri[1].tr_io_input[2]:0 */
    P11_2_ETH_TXD0                  = 27,       /* Digital Active - eth.txd[0] */

    /* P11.3 */
    P11_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_3_TCPWM0_LINE_COMPL6        =  9,       /* Digital Active - tcpwm[0].line_compl[6]:3 */
    P11_3_TCPWM0_LINE_COMPL262      = 10,       /* Digital Active - tcpwm[0].line_compl[262]:1 */
    P11_3_TDM_TDM_RX_MCK1           = 17,       /* Digital Active - tdm.tdm_rx_mck[1] */
    P11_3_SCB6_SPI_SELECT0          = 18,       /* Digital Active - scb[6].spi_select0 */
    P11_3_SCB6_UART_RTS             = 20,       /* Digital Active - scb[6].uart_rts:0 */
    P11_3_PERI0_TR_IO_INPUT3        = 22,       /* Digital Active - peri[0].tr_io_input[3]:0 */
    P11_3_PERI1_TR_IO_INPUT3        = 23,       /* Digital Active - peri[1].tr_io_input[3]:0 */
    P11_3_ETH_TXD1                  = 27,       /* Digital Active - eth.txd[1] */

    /* P11.4 */
    P11_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_4_TCPWM0_LINE7              =  9,       /* Digital Active - tcpwm[0].line[7]:3 */
    P11_4_TCPWM0_LINE263            = 10,       /* Digital Active - tcpwm[0].line[263]:1 */
    P11_4_TDM_TDM_RX_SCK1           = 17,       /* Digital Active - tdm.tdm_rx_sck[1] */
    P11_4_SCB6_SPI_SELECT1          = 18,       /* Digital Active - scb[6].spi_select1 */
    P11_4_ETH_TX_CTL                = 27,       /* Digital Active - eth.tx_ctl */

    /* P11.5 */
    P11_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_5_TCPWM0_LINE_COMPL7        =  9,       /* Digital Active - tcpwm[0].line_compl[7]:3 */
    P11_5_TCPWM0_LINE_COMPL263      = 10,       /* Digital Active - tcpwm[0].line_compl[263]:1 */
    P11_5_TDM_TDM_RX_FSYNC1         = 17,       /* Digital Active - tdm.tdm_rx_fsync[1] */
    P11_5_ETH_TX_CLK                = 27,       /* Digital Active - eth.tx_clk */

    /* P11.6 */
    P11_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_6_TCPWM0_LINE0              =  9,       /* Digital Active - tcpwm[0].line[0]:4 */
    P11_6_TCPWM0_LINE264            = 10,       /* Digital Active - tcpwm[0].line[264]:1 */
    P11_6_TDM_TDM_RX_SD1            = 17,       /* Digital Active - tdm.tdm_rx_sd[1] */
    P11_6_ETH_TXD2                  = 27,       /* Digital Active - eth.txd[2] */

    /* P11.7 */
    P11_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_7_TCPWM0_LINE_COMPL0        =  9,       /* Digital Active - tcpwm[0].line_compl[0]:4 */
    P11_7_TCPWM0_LINE_COMPL264      = 10,       /* Digital Active - tcpwm[0].line_compl[264]:1 */
    P11_7_TDM_TDM_TX_MCK1           = 17,       /* Digital Active - tdm.tdm_tx_mck[1] */
    P11_7_ETH_REF_CLK               = 27,       /* Digital Active - eth.ref_clk */

    /* P12.0 */
    P12_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_0_TCPWM0_LINE1              =  9,       /* Digital Active - tcpwm[0].line[1]:4 */
    P12_0_TCPWM0_LINE265            = 10,       /* Digital Active - tcpwm[0].line[265]:1 */
    P12_0_SDHC0_CLK_CARD            = 27,       /* Digital Active - sdhc[0].clk_card */

    /* P12.1 */
    P12_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_1_TCPWM0_LINE_COMPL1        =  9,       /* Digital Active - tcpwm[0].line_compl[1]:4 */
    P12_1_TCPWM0_LINE_COMPL265      = 10,       /* Digital Active - tcpwm[0].line_compl[265]:1 */
    P12_1_SDHC0_CARD_DAT_3TO00      = 27,       /* Digital Active - sdhc[0].card_dat_3to0[0] */

    /* P12.2 */
    P12_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_2_TCPWM0_LINE2              =  9,       /* Digital Active - tcpwm[0].line[2]:4 */
    P12_2_TCPWM0_LINE266            = 10,       /* Digital Active - tcpwm[0].line[266]:1 */
    P12_2_SDHC0_CARD_DAT_3TO01      = 27,       /* Digital Active - sdhc[0].card_dat_3to0[1] */

    /* P12.3 */
    P12_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_3_SMIF1_SMIF0_SPIHB_SELECT3 =  8,       /* Digital Active - smif[1].smif0_spihb_select3 */
    P12_3_TCPWM0_LINE_COMPL2        =  9,       /* Digital Active - tcpwm[0].line_compl[2]:4 */
    P12_3_TCPWM0_LINE_COMPL266      = 10,       /* Digital Active - tcpwm[0].line_compl[266]:1 */
    P12_3_TDM_TDM_TX_FSYNC0         = 19,       /* Digital Active - tdm.tdm_tx_fsync[0] */

    /* P12.4 */
    P12_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_4_TCPWM0_LINE3              =  9,       /* Digital Active - tcpwm[0].line[3]:4 */
    P12_4_TCPWM0_LINE267            = 10,       /* Digital Active - tcpwm[0].line[267]:1 */
    P12_4_SDHC0_CARD_DAT_3TO02      = 27,       /* Digital Active - sdhc[0].card_dat_3to0[2] */

    /* P12.5 */
    P12_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_5_TCPWM0_LINE_COMPL3        =  9,       /* Digital Active - tcpwm[0].line_compl[3]:4 */
    P12_5_TCPWM0_LINE_COMPL267      = 10,       /* Digital Active - tcpwm[0].line_compl[267]:1 */
    P12_5_SDHC0_CARD_DAT_3TO03      = 27,       /* Digital Active - sdhc[0].card_dat_3to0[3] */

    /* P13.0 */
    P13_0_GPIO                      =  0,       /* GPIO controls 'out' */

    /* P13.1 */
    P13_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_1_TCPWM0_LINE4              =  9,       /* Digital Active - tcpwm[0].line[4]:4 */
    P13_1_TCPWM0_LINE268            = 10,       /* Digital Active - tcpwm[0].line[268]:1 */
    P13_1_SCB7_SPI_CLK              = 18,       /* Digital Active - scb[7].spi_clk */
    P13_1_SCB7_I2C_SCL              = 19,       /* Digital Active - scb[7].i2c_scl:0 */
    P13_1_SCB7_UART_RX              = 20,       /* Digital Active - scb[7].uart_rx:0 */
    P13_1_ETH_MDC                   = 27,       /* Digital Active - eth.mdc */

    /* P13.2 */
    P13_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_2_TCPWM0_LINE_COMPL4        =  9,       /* Digital Active - tcpwm[0].line_compl[4]:4 */
    P13_2_TCPWM0_LINE_COMPL268      = 10,       /* Digital Active - tcpwm[0].line_compl[268]:1 */
    P13_2_SCB7_SPI_MOSI             = 18,       /* Digital Active - scb[7].spi_mosi */
    P13_2_SCB7_I2C_SDA              = 19,       /* Digital Active - scb[7].i2c_sda:0 */
    P13_2_SCB7_UART_TX              = 20,       /* Digital Active - scb[7].uart_tx:0 */
    P13_2_PDM_PDM_CLK1              = 21,       /* Digital Active - pdm.pdm_clk[1] */

    /* P13.3 */
    P13_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_3_TCPWM0_LINE5              =  9,       /* Digital Active - tcpwm[0].line[5]:4 */
    P13_3_TCPWM0_LINE269            = 10,       /* Digital Active - tcpwm[0].line[269]:1 */
    P13_3_SCB7_SPI_MISO             = 18,       /* Digital Active - scb[7].spi_miso */
    P13_3_SCB7_UART_CTS             = 20,       /* Digital Active - scb[7].uart_cts:0 */
    P13_3_PDM_PDM_DATA1             = 21,       /* Digital Active - pdm.pdm_data[1] */

    /* P13.4 */
    P13_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_4_TCPWM0_LINE_COMPL5        =  9,       /* Digital Active - tcpwm[0].line_compl[5]:4 */
    P13_4_TCPWM0_LINE_COMPL269      = 10,       /* Digital Active - tcpwm[0].line_compl[269]:1 */
    P13_4_SCB7_SPI_SELECT0          = 18,       /* Digital Active - scb[7].spi_select0 */
    P13_4_SCB7_UART_RTS             = 20,       /* Digital Active - scb[7].uart_rts:0 */

    /* P13.5 */
    P13_5_GPIO                      =  0,       /* GPIO controls 'out' */

    /* P13.6 */
    P13_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_6_TCPWM0_LINE6              =  9,       /* Digital Active - tcpwm[0].line[6]:4 */
    P13_6_TCPWM0_LINE270            = 10,       /* Digital Active - tcpwm[0].line[270]:1 */
    P13_6_SCB7_SPI_SELECT1          = 18,       /* Digital Active - scb[7].spi_select1 */
    P13_6_ETH_MDIO                  = 27,       /* Digital Active - eth.mdio */

    /* P13.7 */
    P13_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_7_TCPWM0_LINE_COMPL6        =  9,       /* Digital Active - tcpwm[0].line_compl[6]:4 */
    P13_7_TCPWM0_LINE_COMPL270      = 10,       /* Digital Active - tcpwm[0].line_compl[270]:1 */
    P13_7_SCB8_SPI_MISO             = 18,       /* Digital Active - scb[8].spi_miso */
    P13_7_SCB8_UART_CTS             = 20,       /* Digital Active - scb[8].uart_cts:0 */

    /* P14.0 */
    P14_0_GPIO                      =  0,       /* GPIO controls 'out' */

    /* P14.1 */
    P14_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_1_TCPWM0_LINE7              =  9,       /* Digital Active - tcpwm[0].line[7]:4 */
    P14_1_TCPWM0_LINE271            = 10,       /* Digital Active - tcpwm[0].line[271]:1 */
    P14_1_PDM_PDM_CLK0              = 21,       /* Digital Active - pdm.pdm_clk[0] */

    /* P14.2 */
    P14_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_2_TCPWM0_LINE_COMPL7        =  9,       /* Digital Active - tcpwm[0].line_compl[7]:4 */
    P14_2_TCPWM0_LINE_COMPL271      = 10,       /* Digital Active - tcpwm[0].line_compl[271]:1 */

    /* P14.3 */
    P14_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_3_TCPWM0_LINE0              =  9,       /* Digital Active - tcpwm[0].line[0]:5 */
    P14_3_TCPWM0_LINE272            = 10,       /* Digital Active - tcpwm[0].line[272]:1 */
    P14_3_SCB8_SPI_MOSI             = 18,       /* Digital Active - scb[8].spi_mosi */
    P14_3_SCB8_I2C_SDA              = 19,       /* Digital Active - scb[8].i2c_sda:0 */
    P14_3_SCB8_UART_TX              = 20,       /* Digital Active - scb[8].uart_tx:0 */

    /* P14.4 */
    P14_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_4_TCPWM0_LINE_COMPL0        =  9,       /* Digital Active - tcpwm[0].line_compl[0]:5 */
    P14_4_TCPWM0_LINE_COMPL272      = 10,       /* Digital Active - tcpwm[0].line_compl[272]:1 */
    P14_4_SCB8_SPI_CLK              = 18,       /* Digital Active - scb[8].spi_clk */
    P14_4_SCB8_I2C_SCL              = 19,       /* Digital Active - scb[8].i2c_scl:0 */
    P14_4_SCB8_UART_RX              = 20,       /* Digital Active - scb[8].uart_rx:0 */
    P14_4_PDM_PDM_DATA0             = 21,       /* Digital Active - pdm.pdm_data[0] */

    /* P14.5 */
    P14_5_GPIO                      =  0,       /* GPIO controls 'out' */

    /* P14.6 */
    P14_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_6_TCPWM0_LINE1              =  9,       /* Digital Active - tcpwm[0].line[1]:5 */
    P14_6_TCPWM0_LINE273            = 10,       /* Digital Active - tcpwm[0].line[273]:1 */
    P14_6_SCB8_SPI_SELECT1          = 18,       /* Digital Active - scb[8].spi_select1 */

    /* P14.7 */
    P14_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_7_TCPWM0_LINE_COMPL1        =  9,       /* Digital Active - tcpwm[0].line_compl[1]:5 */
    P14_7_TCPWM0_LINE_COMPL273      = 10,       /* Digital Active - tcpwm[0].line_compl[273]:1 */
    P14_7_SCB8_SPI_SELECT0          = 18,       /* Digital Active - scb[8].spi_select0 */
    P14_7_SCB8_UART_RTS             = 20,       /* Digital Active - scb[8].uart_rts:0 */

    /* P15.0 */
    P15_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_0_TCPWM0_LINE2              =  9,       /* Digital Active - tcpwm[0].line[2]:5 */
    P15_0_TCPWM0_LINE274            = 10,       /* Digital Active - tcpwm[0].line[274]:1 */
    P15_0_SCB9_SPI_CLK              = 18,       /* Digital Active - scb[9].spi_clk */
    P15_0_SCB9_I2C_SCL              = 19,       /* Digital Active - scb[9].i2c_scl:0 */
    P15_0_SCB9_UART_RX              = 20,       /* Digital Active - scb[9].uart_rx:0 */

    /* P15.1 */
    P15_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_1_TCPWM0_LINE_COMPL2        =  9,       /* Digital Active - tcpwm[0].line_compl[2]:5 */
    P15_1_TCPWM0_LINE_COMPL274      = 10,       /* Digital Active - tcpwm[0].line_compl[274]:1 */
    P15_1_SCB9_SPI_MOSI             = 18,       /* Digital Active - scb[9].spi_mosi */
    P15_1_SCB9_I2C_SDA              = 19,       /* Digital Active - scb[9].i2c_sda:0 */
    P15_1_SCB9_UART_TX              = 20,       /* Digital Active - scb[9].uart_tx:0 */

    /* P15.2 */
    P15_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_2_TCPWM0_LINE3              =  9,       /* Digital Active - tcpwm[0].line[3]:5 */
    P15_2_TCPWM0_LINE275            = 10,       /* Digital Active - tcpwm[0].line[275]:1 */
    P15_2_SCB9_SPI_MISO             = 18,       /* Digital Active - scb[9].spi_miso */
    P15_2_SCB9_UART_CTS             = 20,       /* Digital Active - scb[9].uart_cts:0 */

    /* P15.3 */
    P15_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_3_TCPWM0_LINE_COMPL3        =  9,       /* Digital Active - tcpwm[0].line_compl[3]:5 */
    P15_3_TCPWM0_LINE_COMPL275      = 10,       /* Digital Active - tcpwm[0].line_compl[275]:1 */
    P15_3_SCB9_SPI_SELECT0          = 18,       /* Digital Active - scb[9].spi_select0 */
    P15_3_SCB9_UART_RTS             = 20,       /* Digital Active - scb[9].uart_rts:0 */

    /* P15.4 */
    P15_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_4_TCPWM0_LINE4              =  9,       /* Digital Active - tcpwm[0].line[4]:5 */
    P15_4_TCPWM0_LINE276            = 10,       /* Digital Active - tcpwm[0].line[276]:1 */
    P15_4_SCB9_SPI_SELECT1          = 18,       /* Digital Active - scb[9].spi_select1 */

    /* P15.5 */
    P15_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_5_TCPWM0_LINE_COMPL4        =  9,       /* Digital Active - tcpwm[0].line_compl[4]:5 */
    P15_5_TCPWM0_LINE_COMPL276      = 10,       /* Digital Active - tcpwm[0].line_compl[276]:1 */

    /* P15.6 */
    P15_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_6_TCPWM0_LINE5              =  9,       /* Digital Active - tcpwm[0].line[5]:5 */
    P15_6_TCPWM0_LINE277            = 10,       /* Digital Active - tcpwm[0].line[277]:1 */

    /* P15.7 */
    P15_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_7_TCPWM0_LINE_COMPL5        =  9,       /* Digital Active - tcpwm[0].line_compl[5]:5 */
    P15_7_TCPWM0_LINE_COMPL277      = 10,       /* Digital Active - tcpwm[0].line_compl[277]:1 */

    /* P16.0 */
    P16_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_0_TCPWM0_LINE0              =  9,       /* Digital Active - tcpwm[0].line[0]:6 */
    P16_0_TCPWM0_LINE256            = 10,       /* Digital Active - tcpwm[0].line[256]:2 */
    P16_0_CANFD0_TTCAN_RX0          = 16,       /* Digital Active - canfd[0].ttcan_rx[0]:0 */
    P16_0_SCB10_SPI_CLK             = 18,       /* Digital Active - scb[10].spi_clk */
    P16_0_SCB10_I2C_SCL             = 19,       /* Digital Active - scb[10].i2c_scl:0 */
    P16_0_SCB10_UART_RX             = 20,       /* Digital Active - scb[10].uart_rx:0 */
    P16_0_GFXSS_DBI_CSX             = 26,       /* Digital Active - gfxss.dbi_csx */
    P16_0_GFXSS_SPI_CSX             = 27,       /* Digital Active - gfxss.spi_csx */

    /* P16.1 */
    P16_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_1_TCPWM0_LINE1              =  9,       /* Digital Active - tcpwm[0].line[1]:6 */
    P16_1_TCPWM0_LINE257            = 10,       /* Digital Active - tcpwm[0].line[257]:2 */
    P16_1_CANFD0_TTCAN_TX0          = 16,       /* Digital Active - canfd[0].ttcan_tx[0]:0 */
    P16_1_SCB10_SPI_MOSI            = 18,       /* Digital Active - scb[10].spi_mosi */
    P16_1_SCB10_I2C_SDA             = 19,       /* Digital Active - scb[10].i2c_sda:0 */
    P16_1_SCB10_UART_TX             = 20,       /* Digital Active - scb[10].uart_tx:0 */
    P16_1_GFXSS_DBI_WRX             = 25,       /* Digital Active - gfxss.dbi_wrx */
    P16_1_GFXSS_DBI_E               = 26,       /* Digital Active - gfxss.dbi_e */
    P16_1_GFXSS_SPI_SCL             = 27,       /* Digital Active - gfxss.spi_scl */

    /* P16.2 */
    P16_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_2_TCPWM0_LINE2              =  9,       /* Digital Active - tcpwm[0].line[2]:6 */
    P16_2_TCPWM0_LINE258            = 10,       /* Digital Active - tcpwm[0].line[258]:2 */
    P16_2_CANFD0_TTCAN_RX1          = 16,       /* Digital Active - canfd[0].ttcan_rx[1]:0 */
    P16_2_SCB10_SPI_MISO            = 18,       /* Digital Active - scb[10].spi_miso */
    P16_2_SCB10_UART_CTS            = 20,       /* Digital Active - scb[10].uart_cts:0 */
    P16_2_GFXSS_DBI_DCX             = 26,       /* Digital Active - gfxss.dbi_dcx */
    P16_2_GFXSS_SPI_DOUT            = 27,       /* Digital Active - gfxss.spi_dout */

    /* P16.3 */
    P16_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_3_TCPWM0_LINE3              =  9,       /* Digital Active - tcpwm[0].line[3]:6 */
    P16_3_TCPWM0_LINE259            = 10,       /* Digital Active - tcpwm[0].line[259]:2 */
    P16_3_CANFD0_TTCAN_TX1          = 16,       /* Digital Active - canfd[0].ttcan_tx[1]:0 */
    P16_3_SCB10_SPI_SELECT0         = 18,       /* Digital Active - scb[10].spi_select0 */
    P16_3_SCB10_UART_RTS            = 20,       /* Digital Active - scb[10].uart_rts:0 */
    P16_3_GFXSS_DBI_D0              = 26,       /* Digital Active - gfxss.dbi_d[0] */
    P16_3_GFXSS_SPI_DCX             = 27,       /* Digital Active - gfxss.spi_dcx */

    /* P16.4 */
    P16_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_4_TCPWM0_LINE4              =  9,       /* Digital Active - tcpwm[0].line[4]:6 */
    P16_4_TCPWM0_LINE260            = 10,       /* Digital Active - tcpwm[0].line[260]:2 */
    P16_4_SCB10_SPI_SELECT1         = 18,       /* Digital Active - scb[10].spi_select1 */
    P16_4_GFXSS_DBI_D1              = 26,       /* Digital Active - gfxss.dbi_d[1] */

    /* P16.5 */
    P16_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_5_TCPWM0_LINE5              =  9,       /* Digital Active - tcpwm[0].line[5]:6 */
    P16_5_TCPWM0_LINE261            = 10,       /* Digital Active - tcpwm[0].line[261]:2 */
    P16_5_SCB5_SPI_MISO             = 18,       /* Digital Active - scb[5].spi_miso */
    P16_5_SCB5_UART_CTS             = 20,       /* Digital Active - scb[5].uart_cts:0 */
    P16_5_GFXSS_DBI_D2              = 26,       /* Digital Active - gfxss.dbi_d[2] */

    /* P16.6 */
    P16_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_6_TCPWM0_LINE6              =  9,       /* Digital Active - tcpwm[0].line[6]:5 */
    P16_6_TCPWM0_LINE278            = 10,       /* Digital Active - tcpwm[0].line[278]:1 */
    P16_6_SCB5_SPI_SELECT0          = 18,       /* Digital Active - scb[5].spi_select0 */
    P16_6_SCB5_UART_RTS             = 20,       /* Digital Active - scb[5].uart_rts:0 */
    P16_6_GFXSS_DBI_D3              = 26,       /* Digital Active - gfxss.dbi_d[3] */

    /* P16.7 */
    P16_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_7_TCPWM0_LINE7              =  9,       /* Digital Active - tcpwm[0].line[7]:5 */
    P16_7_TCPWM0_LINE279            = 10,       /* Digital Active - tcpwm[0].line[279]:1 */
    P16_7_SCB5_SPI_SELECT1          = 18,       /* Digital Active - scb[5].spi_select1 */
    P16_7_GFXSS_DBI_D4              = 26,       /* Digital Active - gfxss.dbi_d[4] */

    /* P17.0 */
    P17_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_0_TCPWM0_LINE_COMPL0        =  9,       /* Digital Active - tcpwm[0].line_compl[0]:6 */
    P17_0_TCPWM0_LINE_COMPL256      = 10,       /* Digital Active - tcpwm[0].line_compl[256]:2 */
    P17_0_SCB5_SPI_CLK              = 18,       /* Digital Active - scb[5].spi_clk */
    P17_0_SCB5_I2C_SCL              = 19,       /* Digital Active - scb[5].i2c_scl:0 */
    P17_0_SCB5_UART_RX              = 20,       /* Digital Active - scb[5].uart_rx:0 */
    P17_0_GFXSS_DBI_D5              = 26,       /* Digital Active - gfxss.dbi_d[5] */

    /* P17.1 */
    P17_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_1_TCPWM0_LINE_COMPL1        =  9,       /* Digital Active - tcpwm[0].line_compl[1]:6 */
    P17_1_TCPWM0_LINE_COMPL257      = 10,       /* Digital Active - tcpwm[0].line_compl[257]:2 */
    P17_1_SCB5_SPI_MOSI             = 18,       /* Digital Active - scb[5].spi_mosi */
    P17_1_SCB5_I2C_SDA              = 19,       /* Digital Active - scb[5].i2c_sda:0 */
    P17_1_SCB5_UART_TX              = 20,       /* Digital Active - scb[5].uart_tx:0 */
    P17_1_GFXSS_DBI_D6              = 26,       /* Digital Active - gfxss.dbi_d[6] */

    /* P17.2 */
    P17_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_2_TCPWM0_LINE_COMPL2        =  9,       /* Digital Active - tcpwm[0].line_compl[2]:6 */
    P17_2_TCPWM0_LINE_COMPL258      = 10,       /* Digital Active - tcpwm[0].line_compl[258]:2 */
    P17_2_SCB11_SPI_CLK             = 18,       /* Digital Active - scb[11].spi_clk */
    P17_2_SCB11_I2C_SCL             = 19,       /* Digital Active - scb[11].i2c_scl:0 */
    P17_2_SCB11_UART_RX             = 20,       /* Digital Active - scb[11].uart_rx:0 */
    P17_2_GFXSS_DBI_D7              = 26,       /* Digital Active - gfxss.dbi_d[7] */

    /* P17.3 */
    P17_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_3_TCPWM0_LINE_COMPL3        =  9,       /* Digital Active - tcpwm[0].line_compl[3]:6 */
    P17_3_TCPWM0_LINE_COMPL259      = 10,       /* Digital Active - tcpwm[0].line_compl[259]:2 */
    P17_3_SCB11_SPI_MOSI            = 18,       /* Digital Active - scb[11].spi_mosi */
    P17_3_SCB11_I2C_SDA             = 19,       /* Digital Active - scb[11].i2c_sda:0 */
    P17_3_SCB11_UART_TX             = 20,       /* Digital Active - scb[11].uart_tx:0 */

    /* P17.4 */
    P17_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_4_TCPWM0_LINE_COMPL4        =  9,       /* Digital Active - tcpwm[0].line_compl[4]:6 */
    P17_4_TCPWM0_LINE_COMPL260      = 10,       /* Digital Active - tcpwm[0].line_compl[260]:2 */
    P17_4_PASS_LPPASS_DOUT0         = 28,       /* Digital Deep Sleep - pass.lppass_dout[0]:0 */

    /* P17.5 */
    P17_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_5_TCPWM0_LINE_COMPL5        =  9,       /* Digital Active - tcpwm[0].line_compl[5]:6 */
    P17_5_TCPWM0_LINE_COMPL261      = 10,       /* Digital Active - tcpwm[0].line_compl[261]:2 */
    P17_5_SCB11_SPI_MISO            = 18,       /* Digital Active - scb[11].spi_miso */
    P17_5_SCB11_UART_CTS            = 20,       /* Digital Active - scb[11].uart_cts:0 */
    P17_5_PASS_LPPASS_DOUT1         = 28,       /* Digital Deep Sleep - pass.lppass_dout[1]:0 */

    /* P17.6 */
    P17_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_6_TCPWM0_LINE_COMPL6        =  9,       /* Digital Active - tcpwm[0].line_compl[6]:5 */
    P17_6_TCPWM0_LINE_COMPL278      = 10,       /* Digital Active - tcpwm[0].line_compl[278]:1 */
    P17_6_SCB11_SPI_SELECT0         = 18,       /* Digital Active - scb[11].spi_select0 */
    P17_6_SCB11_UART_RTS            = 20,       /* Digital Active - scb[11].uart_rts:0 */
    P17_6_PASS_LPPASS_DOUT2         = 28,       /* Digital Deep Sleep - pass.lppass_dout[2]:0 */

    /* P17.7 */
    P17_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_7_TCPWM0_LINE_COMPL7        =  9,       /* Digital Active - tcpwm[0].line_compl[7]:5 */
    P17_7_TCPWM0_LINE_COMPL279      = 10,       /* Digital Active - tcpwm[0].line_compl[279]:1 */
    P17_7_SCB11_SPI_SELECT1         = 18,       /* Digital Active - scb[11].spi_select1 */
    P17_7_PASS_LPPASS_DOUT3         = 28,       /* Digital Deep Sleep - pass.lppass_dout[3]:0 */

    /* P18.0 */
    P18_0_GPIO                      =  0,       /* GPIO controls 'out' */

    /* P18.1 */
    P18_1_GPIO                      =  0,       /* GPIO controls 'out' */

    /* P19.0 */
    P19_0_GPIO                      =  0,       /* GPIO controls 'out' */

    /* P19.1 */
    P19_1_GPIO                      =  0,       /* GPIO controls 'out' */

    /* P20.0 */
    P20_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_0_TCPWM0_LINE7              =  9,       /* Digital Active - tcpwm[0].line[7]:6 */
    P20_0_TCPWM0_LINE_COMPL263      = 10,       /* Digital Active - tcpwm[0].line_compl[263]:2 */
    P20_0_SCB1_SPI_SELECT1          = 18,       /* Digital Active - scb[1].spi_select1 */
    P20_0_DEBUG600_TRACE_CLOCK      = 27,       /* Digital Active - debug600.trace_clock:1 */
    P20_0_PASS_LPPASS_OBSRV0        = 29,       /* Digital Deep Sleep - pass.lppass_obsrv[0] */

    /* P20.1 */
    P20_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_1_TCPWM0_LINE0              =  9,       /* Digital Active - tcpwm[0].line[0]:7 */
    P20_1_TCPWM0_LINE_COMPL264      = 10,       /* Digital Active - tcpwm[0].line_compl[264]:2 */
    P20_1_DEBUG600_TRACE_DATA3      = 27,       /* Digital Active - debug600.trace_data[3]:1 */
    P20_1_PASS_LPPASS_OBSRV1        = 29,       /* Digital Deep Sleep - pass.lppass_obsrv[1] */

    /* P20.2 */
    P20_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_2_TCPWM0_LINE1              =  9,       /* Digital Active - tcpwm[0].line[1]:7 */
    P20_2_TCPWM0_LINE_COMPL265      = 10,       /* Digital Active - tcpwm[0].line_compl[265]:2 */
    P20_2_DEBUG600_TRACE_DATA2      = 27,       /* Digital Active - debug600.trace_data[2]:1 */
    P20_2_PASS_LPPASS_OBSRV2        = 29,       /* Digital Deep Sleep - pass.lppass_obsrv[2] */

    /* P20.3 */
    P20_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_3_TCPWM0_LINE2              =  9,       /* Digital Active - tcpwm[0].line[2]:7 */
    P20_3_TCPWM0_LINE_COMPL266      = 10,       /* Digital Active - tcpwm[0].line_compl[266]:2 */
    P20_3_DEBUG600_TRACE_DATA1      = 27,       /* Digital Active - debug600.trace_data[1]:1 */
    P20_3_PASS_LPPASS_OBSRV3        = 29,       /* Digital Deep Sleep - pass.lppass_obsrv[3] */

    /* P20.4 */
    P20_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_4_TCPWM0_LINE_COMPL7        =  9,       /* Digital Active - tcpwm[0].line_compl[7]:6 */
    P20_4_TCPWM0_LINE263            = 10,       /* Digital Active - tcpwm[0].line[263]:2 */
    P20_4_CANFD0_TTCAN_RX0          = 16,       /* Digital Active - canfd[0].ttcan_rx[0]:1 */
    P20_4_DEBUG600_TRACE_DATA0      = 27,       /* Digital Active - debug600.trace_data[0]:1 */
    P20_4_PASS_LPPASS_DOUT0         = 28,       /* Digital Deep Sleep - pass.lppass_dout[0]:1 */
    P20_4_PASS_LPPASS_OBSRV4        = 29,       /* Digital Deep Sleep - pass.lppass_obsrv[4] */

    /* P20.5 */
    P20_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_5_TCPWM0_LINE_COMPL0        =  9,       /* Digital Active - tcpwm[0].line_compl[0]:7 */
    P20_5_TCPWM0_LINE264            = 10,       /* Digital Active - tcpwm[0].line[264]:2 */
    P20_5_CANFD0_TTCAN_TX0          = 16,       /* Digital Active - canfd[0].ttcan_tx[0]:1 */
    P20_5_PASS_LPPASS_DOUT1         = 28,       /* Digital Deep Sleep - pass.lppass_dout[1]:1 */
    P20_5_PASS_LPPASS_OBSRV5        = 29,       /* Digital Deep Sleep - pass.lppass_obsrv[5] */

    /* P20.6 */
    P20_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_6_TCPWM0_LINE_COMPL1        =  9,       /* Digital Active - tcpwm[0].line_compl[1]:7 */
    P20_6_TCPWM0_LINE265            = 10,       /* Digital Active - tcpwm[0].line[265]:2 */
    P20_6_CANFD0_TTCAN_RX1          = 16,       /* Digital Active - canfd[0].ttcan_rx[1]:1 */
    P20_6_PASS_LPPASS_DOUT2         = 28,       /* Digital Deep Sleep - pass.lppass_dout[2]:1 */
    P20_6_PASS_LPPASS_OBSRV6        = 29,       /* Digital Deep Sleep - pass.lppass_obsrv[6] */

    /* P20.7 */
    P20_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_7_TCPWM0_LINE_COMPL2        =  9,       /* Digital Active - tcpwm[0].line_compl[2]:7 */
    P20_7_TCPWM0_LINE266            = 10,       /* Digital Active - tcpwm[0].line[266]:2 */
    P20_7_CANFD0_TTCAN_TX1          = 16,       /* Digital Active - canfd[0].ttcan_tx[1]:1 */
    P20_7_PASS_LPPASS_DOUT3         = 28,       /* Digital Deep Sleep - pass.lppass_dout[3]:1 */
    P20_7_PASS_LPPASS_OBSRV7        = 29,       /* Digital Deep Sleep - pass.lppass_obsrv[7] */

    /* P21.0 */
    P21_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_0_TCPWM0_LINE3              =  9,       /* Digital Active - tcpwm[0].line[3]:7 */
    P21_0_TCPWM0_LINE267            = 10,       /* Digital Active - tcpwm[0].line[267]:2 */
    P21_0_SDHC0_CARD_CMD            = 27,       /* Digital Active - sdhc[0].card_cmd */

    /* P21.1 */
    P21_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_1_TCPWM0_LINE_COMPL3        =  9,       /* Digital Active - tcpwm[0].line_compl[3]:7 */
    P21_1_TCPWM0_LINE_COMPL267      = 10,       /* Digital Active - tcpwm[0].line_compl[267]:2 */
    P21_1_TDM_TDM_TX_SD0            = 19,       /* Digital Active - tdm.tdm_tx_sd[0] */
    P21_1_SDHC0_CARD_DETECT_N       = 27,       /* Digital Active - sdhc[0].card_detect_n */

    /* P21.2 */
    P21_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_2_TCPWM0_LINE4              =  9,       /* Digital Active - tcpwm[0].line[4]:7 */
    P21_2_TCPWM0_LINE268            = 10,       /* Digital Active - tcpwm[0].line[268]:2 */
    P21_2_TDM_TDM_TX_SCK0           = 19,       /* Digital Active - tdm.tdm_tx_sck[0] */
    P21_2_SDHC0_CARD_MECH_WRITE_PROT = 27,      /* Digital Active - sdhc[0].card_mech_write_prot */

    /* P21.3 */
    P21_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_3_TCPWM0_LINE_COMPL4        =  9,       /* Digital Active - tcpwm[0].line_compl[4]:7 */
    P21_3_TCPWM0_LINE_COMPL268      = 10,       /* Digital Active - tcpwm[0].line_compl[268]:2 */
    P21_3_TDM_TDM_TX_MCK0           = 19,       /* Digital Active - tdm.tdm_tx_mck[0] */
    P21_3_SDHC0_IO_VOLT_SEL         = 27,       /* Digital Active - sdhc[0].io_volt_sel */

    /* P21.4 */
    P21_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_4_TCPWM0_LINE5              =  9,       /* Digital Active - tcpwm[0].line[5]:7 */
    P21_4_TCPWM0_LINE269            = 10,       /* Digital Active - tcpwm[0].line[269]:2 */
    P21_4_SCB3_SPI_MISO             = 16,       /* Digital Active - scb[3].spi_miso */
    P21_4_SCB3_UART_CTS             = 18,       /* Digital Active - scb[3].uart_cts:0 */
    P21_4_TDM_TDM_RX_SD0            = 19,       /* Digital Active - tdm.tdm_rx_sd[0] */
    P21_4_SDHC0_CARD_IF_PWR_EN      = 27,       /* Digital Active - sdhc[0].card_if_pwr_en */

    /* P21.5 */
    P21_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_5_TCPWM0_LINE_COMPL5        =  9,       /* Digital Active - tcpwm[0].line_compl[5]:7 */
    P21_5_TCPWM0_LINE_COMPL269      = 10,       /* Digital Active - tcpwm[0].line_compl[269]:2 */
    P21_5_SCB3_SPI_MOSI             = 16,       /* Digital Active - scb[3].spi_mosi */
    P21_5_SCB3_I2C_SDA              = 17,       /* Digital Active - scb[3].i2c_sda:0 */
    P21_5_SCB3_UART_TX              = 18,       /* Digital Active - scb[3].uart_tx:0 */
    P21_5_TDM_TDM_RX_FSYNC0         = 19,       /* Digital Active - tdm.tdm_rx_fsync[0] */

    /* P21.6 */
    P21_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_6_TCPWM0_LINE6              =  9,       /* Digital Active - tcpwm[0].line[6]:6 */
    P21_6_TCPWM0_LINE270            = 10,       /* Digital Active - tcpwm[0].line[270]:2 */
    P21_6_SCB3_SPI_CLK              = 16,       /* Digital Active - scb[3].spi_clk */
    P21_6_SCB3_I2C_SCL              = 17,       /* Digital Active - scb[3].i2c_scl:0 */
    P21_6_SCB3_UART_RX              = 18,       /* Digital Active - scb[3].uart_rx:0 */
    P21_6_TDM_TDM_RX_SCK0           = 19,       /* Digital Active - tdm.tdm_rx_sck[0] */

    /* P21.7 */
    P21_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_7_SMIF1_SMIF0_SPIHB_SELECT0 =  8,       /* Digital Active - smif[1].smif0_spihb_select0 */
    P21_7_TCPWM0_LINE_COMPL6        =  9,       /* Digital Active - tcpwm[0].line_compl[6]:6 */
    P21_7_TCPWM0_LINE_COMPL270      = 10,       /* Digital Active - tcpwm[0].line_compl[270]:2 */
    P21_7_SCB3_SPI_SELECT1          = 16,       /* Digital Active - scb[3].spi_select1 */
    P21_7_SCB3_UART_RTS             = 18,       /* Digital Active - scb[3].uart_rts:0 */
    P21_7_TDM_TDM_RX_MCK0           = 19        /* Digital Active - tdm.tdm_rx_mck[0] */
} en_hsiom_sel_t;

#endif /* _GPIO_PSE84_BGA_220_H_ */


/* [] END OF FILE */
