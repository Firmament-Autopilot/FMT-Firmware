/***************************************************************************//**
* RTC IP definitions
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

#ifndef _CYIP_RTC_V1_1_H_
#define _CYIP_RTC_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     RTC
*******************************************************************************/

#define RTC_CSV_RTC_CSV_SECTION_SIZE            0x00000010UL
#define RTC_CSV_RTC_SECTION_SIZE                0x00000010UL
#define RTC_SECTION_SIZE                        0x00010000UL

/**
  * \brief clk_bak Backup domain Clock Supervisor registers (RTC_CSV_RTC_CSV)
  */
typedef struct {
  __IOM uint32_t REF_CTL;                       /*!< 0x00000000 Clock Supervision Reference Control */
  __IOM uint32_t REF_LIMIT;                     /*!< 0x00000004 Clock Supervision Reference Limits */
  __IOM uint32_t MON_CTL;                       /*!< 0x00000008 Clock Supervision Monitor Control */
   __IM uint32_t RESERVED;
} RTC_CSV_RTC_CSV_Type;                         /*!< Size = 16 (0x10) */

/**
  * \brief CSV registers for clk_rtc clock (RTC_CSV_RTC)
  */
typedef struct {
        RTC_CSV_RTC_CSV_Type CSV;               /*!< 0x00000000 clk_bak Backup domain Clock Supervisor registers */
} RTC_CSV_RTC_Type;                             /*!< Size = 16 (0x10) */

/**
  * \brief SRSS RTC Registers (RTC)
  */
typedef struct {
   __IM uint32_t RESERVED[2];
  __IOM uint32_t RTC_RW;                        /*!< 0x00000008 RTC Read Write register */
  __IOM uint32_t CAL_CTL;                       /*!< 0x0000000C Oscillator calibration for absolute frequency */
   __IM uint32_t STATUS;                        /*!< 0x00000010 Status */
  __IOM uint32_t RTC_TIME;                      /*!< 0x00000014 Calendar Seconds, Minutes, Hours, Day of Week */
  __IOM uint32_t RTC_DATE;                      /*!< 0x00000018 Calendar Day of Month, Month,  Year */
  __IOM uint32_t ALM1_TIME;                     /*!< 0x0000001C Alarm 1 Seconds, Minute, Hours, Day of Week */
  __IOM uint32_t ALM1_DATE;                     /*!< 0x00000020 Alarm 1 Day of Month, Month */
  __IOM uint32_t ALM2_TIME;                     /*!< 0x00000024 Alarm 2 Seconds, Minute, Hours, Day of Week */
  __IOM uint32_t ALM2_DATE;                     /*!< 0x00000028 Alarm 2 Day of Month, Month */
  __IOM uint32_t INTR;                          /*!< 0x0000002C Interrupt request register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000030 Interrupt set request register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000034 Interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x00000038 Interrupt masked request register */
   __IM uint32_t RESERVED1[3];
  __IOM uint32_t RESET;                         /*!< 0x00000048 RTC reset register */
   __IM uint32_t RESERVED2[17];
  __IOM uint32_t CSV_RTC_REF_SEL;               /*!< 0x00000090 Select CSV Reference clock for RTC clock */
   __IM uint32_t RESERVED3[27];
        RTC_CSV_RTC_Type CSV_RTC;               /*!< 0x00000100 CSV registers for clk_rtc clock */
   __IM uint32_t RESERVED4[956];
  __IOM uint32_t BREG_SET0[4];                  /*!< 0x00001000 Backup register region 0 */
  __IOM uint32_t BREG_SET1[4];                  /*!< 0x00001010 Backup register region 1 */
  __IOM uint32_t BREG_SET2[8];                  /*!< 0x00001020 Backup register region 2 */
   __IM uint32_t RESERVED5[16];
  __IOM uint32_t BREG_SET3[48];                 /*!< 0x00001080 Backup register region 3 */
} RTC_Type;                                     /*!< Size = 4416 (0x1140) */


/* RTC_CSV_RTC_CSV.REF_CTL */
#define RTC_CSV_RTC_CSV_REF_CTL_CSV_STARTUP_Pos 0UL
#define RTC_CSV_RTC_CSV_REF_CTL_CSV_STARTUP_Msk 0xFFUL
#define RTC_CSV_RTC_CSV_REF_CTL_CSV_EN_Pos      31UL
#define RTC_CSV_RTC_CSV_REF_CTL_CSV_EN_Msk      0x80000000UL
/* RTC_CSV_RTC_CSV.REF_LIMIT */
#define RTC_CSV_RTC_CSV_REF_LIMIT_CSV_LOWER_Pos 0UL
#define RTC_CSV_RTC_CSV_REF_LIMIT_CSV_LOWER_Msk 0xFFUL
#define RTC_CSV_RTC_CSV_REF_LIMIT_CSV_UPPER_Pos 16UL
#define RTC_CSV_RTC_CSV_REF_LIMIT_CSV_UPPER_Msk 0xFF0000UL
/* RTC_CSV_RTC_CSV.MON_CTL */
#define RTC_CSV_RTC_CSV_MON_CTL_CSV_PERIOD_Pos  0UL
#define RTC_CSV_RTC_CSV_MON_CTL_CSV_PERIOD_Msk  0xFFUL


/* RTC.RTC_RW */
#define RTC_RTC_RW_READ_Pos                     0UL
#define RTC_RTC_RW_READ_Msk                     0x1UL
#define RTC_RTC_RW_WRITE_Pos                    1UL
#define RTC_RTC_RW_WRITE_Msk                    0x2UL
/* RTC.CAL_CTL */
#define RTC_CAL_CTL_CALIB_VAL_Pos               0UL
#define RTC_CAL_CTL_CALIB_VAL_Msk               0x3FUL
#define RTC_CAL_CTL_CALIB_SIGN_Pos              6UL
#define RTC_CAL_CTL_CALIB_SIGN_Msk              0x40UL
#define RTC_CAL_CTL_CAL_COMP_PER_MIN_Pos        16UL
#define RTC_CAL_CTL_CAL_COMP_PER_MIN_Msk        0x30000UL
#define RTC_CAL_CTL_CAL_SEL_Pos                 28UL
#define RTC_CAL_CTL_CAL_SEL_Msk                 0x30000000UL
#define RTC_CAL_CTL_CAL_OUT_Pos                 31UL
#define RTC_CAL_CTL_CAL_OUT_Msk                 0x80000000UL
/* RTC.STATUS */
#define RTC_STATUS_RTC_BUSY_Pos                 0UL
#define RTC_STATUS_RTC_BUSY_Msk                 0x1UL
/* RTC.RTC_TIME */
#define RTC_RTC_TIME_RTC_SEC_Pos                0UL
#define RTC_RTC_TIME_RTC_SEC_Msk                0x3FUL
#define RTC_RTC_TIME_RTC_MIN_Pos                8UL
#define RTC_RTC_TIME_RTC_MIN_Msk                0x3F00UL
#define RTC_RTC_TIME_RTC_HOUR_Pos               16UL
#define RTC_RTC_TIME_RTC_HOUR_Msk               0x1F0000UL
#define RTC_RTC_TIME_CTRL_12HR_Pos              22UL
#define RTC_RTC_TIME_CTRL_12HR_Msk              0x400000UL
#define RTC_RTC_TIME_RTC_DAY_Pos                24UL
#define RTC_RTC_TIME_RTC_DAY_Msk                0x7000000UL
/* RTC.RTC_DATE */
#define RTC_RTC_DATE_RTC_DATE_Pos               0UL
#define RTC_RTC_DATE_RTC_DATE_Msk               0x1FUL
#define RTC_RTC_DATE_RTC_MON_Pos                8UL
#define RTC_RTC_DATE_RTC_MON_Msk                0xF00UL
#define RTC_RTC_DATE_RTC_YEAR_Pos               16UL
#define RTC_RTC_DATE_RTC_YEAR_Msk               0x7F0000UL
/* RTC.ALM1_TIME */
#define RTC_ALM1_TIME_ALM_SEC_Pos               0UL
#define RTC_ALM1_TIME_ALM_SEC_Msk               0x3FUL
#define RTC_ALM1_TIME_ALM_SEC_EN_Pos            7UL
#define RTC_ALM1_TIME_ALM_SEC_EN_Msk            0x80UL
#define RTC_ALM1_TIME_ALM_MIN_Pos               8UL
#define RTC_ALM1_TIME_ALM_MIN_Msk               0x3F00UL
#define RTC_ALM1_TIME_ALM_MIN_EN_Pos            15UL
#define RTC_ALM1_TIME_ALM_MIN_EN_Msk            0x8000UL
#define RTC_ALM1_TIME_ALM_HOUR_Pos              16UL
#define RTC_ALM1_TIME_ALM_HOUR_Msk              0x1F0000UL
#define RTC_ALM1_TIME_ALM_HOUR_EN_Pos           23UL
#define RTC_ALM1_TIME_ALM_HOUR_EN_Msk           0x800000UL
#define RTC_ALM1_TIME_ALM_DAY_Pos               24UL
#define RTC_ALM1_TIME_ALM_DAY_Msk               0x7000000UL
#define RTC_ALM1_TIME_ALM_DAY_EN_Pos            31UL
#define RTC_ALM1_TIME_ALM_DAY_EN_Msk            0x80000000UL
/* RTC.ALM1_DATE */
#define RTC_ALM1_DATE_ALM_DATE_Pos              0UL
#define RTC_ALM1_DATE_ALM_DATE_Msk              0x1FUL
#define RTC_ALM1_DATE_ALM_DATE_EN_Pos           7UL
#define RTC_ALM1_DATE_ALM_DATE_EN_Msk           0x80UL
#define RTC_ALM1_DATE_ALM_MON_Pos               8UL
#define RTC_ALM1_DATE_ALM_MON_Msk               0xF00UL
#define RTC_ALM1_DATE_ALM_MON_EN_Pos            15UL
#define RTC_ALM1_DATE_ALM_MON_EN_Msk            0x8000UL
#define RTC_ALM1_DATE_ALM_EN_Pos                31UL
#define RTC_ALM1_DATE_ALM_EN_Msk                0x80000000UL
/* RTC.ALM2_TIME */
#define RTC_ALM2_TIME_ALM_SEC_Pos               0UL
#define RTC_ALM2_TIME_ALM_SEC_Msk               0x3FUL
#define RTC_ALM2_TIME_ALM_SEC_EN_Pos            7UL
#define RTC_ALM2_TIME_ALM_SEC_EN_Msk            0x80UL
#define RTC_ALM2_TIME_ALM_MIN_Pos               8UL
#define RTC_ALM2_TIME_ALM_MIN_Msk               0x3F00UL
#define RTC_ALM2_TIME_ALM_MIN_EN_Pos            15UL
#define RTC_ALM2_TIME_ALM_MIN_EN_Msk            0x8000UL
#define RTC_ALM2_TIME_ALM_HOUR_Pos              16UL
#define RTC_ALM2_TIME_ALM_HOUR_Msk              0x1F0000UL
#define RTC_ALM2_TIME_ALM_HOUR_EN_Pos           23UL
#define RTC_ALM2_TIME_ALM_HOUR_EN_Msk           0x800000UL
#define RTC_ALM2_TIME_ALM_DAY_Pos               24UL
#define RTC_ALM2_TIME_ALM_DAY_Msk               0x7000000UL
#define RTC_ALM2_TIME_ALM_DAY_EN_Pos            31UL
#define RTC_ALM2_TIME_ALM_DAY_EN_Msk            0x80000000UL
/* RTC.ALM2_DATE */
#define RTC_ALM2_DATE_ALM_DATE_Pos              0UL
#define RTC_ALM2_DATE_ALM_DATE_Msk              0x1FUL
#define RTC_ALM2_DATE_ALM_DATE_EN_Pos           7UL
#define RTC_ALM2_DATE_ALM_DATE_EN_Msk           0x80UL
#define RTC_ALM2_DATE_ALM_MON_Pos               8UL
#define RTC_ALM2_DATE_ALM_MON_Msk               0xF00UL
#define RTC_ALM2_DATE_ALM_MON_EN_Pos            15UL
#define RTC_ALM2_DATE_ALM_MON_EN_Msk            0x8000UL
#define RTC_ALM2_DATE_ALM_EN_Pos                31UL
#define RTC_ALM2_DATE_ALM_EN_Msk                0x80000000UL
/* RTC.INTR */
#define RTC_INTR_ALARM1_Pos                     0UL
#define RTC_INTR_ALARM1_Msk                     0x1UL
#define RTC_INTR_ALARM2_Pos                     1UL
#define RTC_INTR_ALARM2_Msk                     0x2UL
#define RTC_INTR_CENTURY_Pos                    2UL
#define RTC_INTR_CENTURY_Msk                    0x4UL
#define RTC_INTR_CSV_RTC_Pos                    3UL
#define RTC_INTR_CSV_RTC_Msk                    0x8UL
/* RTC.INTR_SET */
#define RTC_INTR_SET_ALARM1_Pos                 0UL
#define RTC_INTR_SET_ALARM1_Msk                 0x1UL
#define RTC_INTR_SET_ALARM2_Pos                 1UL
#define RTC_INTR_SET_ALARM2_Msk                 0x2UL
#define RTC_INTR_SET_CENTURY_Pos                2UL
#define RTC_INTR_SET_CENTURY_Msk                0x4UL
#define RTC_INTR_SET_CSV_RTC_Pos                3UL
#define RTC_INTR_SET_CSV_RTC_Msk                0x8UL
/* RTC.INTR_MASK */
#define RTC_INTR_MASK_ALARM1_Pos                0UL
#define RTC_INTR_MASK_ALARM1_Msk                0x1UL
#define RTC_INTR_MASK_ALARM2_Pos                1UL
#define RTC_INTR_MASK_ALARM2_Msk                0x2UL
#define RTC_INTR_MASK_CENTURY_Pos               2UL
#define RTC_INTR_MASK_CENTURY_Msk               0x4UL
#define RTC_INTR_MASK_CSV_RTC_Pos               3UL
#define RTC_INTR_MASK_CSV_RTC_Msk               0x8UL
/* RTC.INTR_MASKED */
#define RTC_INTR_MASKED_ALARM1_Pos              0UL
#define RTC_INTR_MASKED_ALARM1_Msk              0x1UL
#define RTC_INTR_MASKED_ALARM2_Pos              1UL
#define RTC_INTR_MASKED_ALARM2_Msk              0x2UL
#define RTC_INTR_MASKED_CENTURY_Pos             2UL
#define RTC_INTR_MASKED_CENTURY_Msk             0x4UL
#define RTC_INTR_MASKED_CSV_RTC_Pos             3UL
#define RTC_INTR_MASKED_CSV_RTC_Msk             0x8UL
/* RTC.RESET */
#define RTC_RESET_RESET_Pos                     31UL
#define RTC_RESET_RESET_Msk                     0x80000000UL
/* RTC.CSV_RTC_REF_SEL */
#define RTC_CSV_RTC_REF_SEL_RTC_REF_MUX_Pos     0UL
#define RTC_CSV_RTC_REF_SEL_RTC_REF_MUX_Msk     0x3UL
/* RTC.BREG_SET0 */
#define RTC_BREG_SET0_BREG_Pos                  0UL
#define RTC_BREG_SET0_BREG_Msk                  0xFFFFFFFFUL
/* RTC.BREG_SET1 */
#define RTC_BREG_SET1_BREG_Pos                  0UL
#define RTC_BREG_SET1_BREG_Msk                  0xFFFFFFFFUL
/* RTC.BREG_SET2 */
#define RTC_BREG_SET2_BREG_Pos                  0UL
#define RTC_BREG_SET2_BREG_Msk                  0xFFFFFFFFUL
/* RTC.BREG_SET3 */
#define RTC_BREG_SET3_BREG_Pos                  0UL
#define RTC_BREG_SET3_BREG_Msk                  0xFFFFFFFFUL


#endif /* _CYIP_RTC_V1_1_H_ */


/* [] END OF FILE */
