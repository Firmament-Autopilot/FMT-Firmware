/***************************************************************************//**
* \file cy_autanalog.h
* \version 2.0
*
* \brief
* Provides an API declaration of the Autonomous Analog driver.
*
********************************************************************************
* \copyright
* Copyright(c) 2022-2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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


/**
* \addtogroup group_autanalog AUTONOMOUS ANALOG (Autonomous Analog Block)
* \{
* This driver provides API functions to configure the Autonomous Analog.
*
* The Autonomous Analog can sense a voltage or current, convert it to digital code,
* post process conversion data, and thus make the first-level decisions as close to the sensor as possible.
*
* It is a low power reconfigurable mixed signal sense, condition, and respond system,
* which can be fully functional and autonomous in all power modes except Hibernate
* (see \ref group_syspm_power_modes chapter for the device).
*
* The Autonomous Analog is entirely controlled and determined by a Finite-State Machine sequencer,
* (see \ref group_autanalog_ac for more details) which works of a State Transition Table
* (see \ref cy_stc_autanalog_stt_t for more details), to transition appropriately through various
* pre-defined states, based on the Timer and/or Events.
*
* The following diagram shows the subsystems of the Autonomous Analog.
* See the device datasheet for the exact location of pins.
*
* \image html LPPASS_General.png
*
* \section group_autanalog_glossary Glossary
* * AC    - Autonomous Controller, the state machine engine for the Autonomous Analog
* * API   - Application Programming Interface
* * EOS   - End Of Scan
* * FIR   - Finite Impulse Response digital filter
* * FSM   - Finite State Machine
* * GPIO  - General Purpose Input/Output
* * HS    - High Speed operating mode of the Autonomous Analog
* * LP    - Low Power operating mode of the Autonomous Analog
* * LPOSC - Local Low Power Oscillator
* * LSB   - Least Significant Bit
* * LUT   - Look Up Table
* * MMIO  - Memory Mapped Input/Output register
* * MUX   - Multiplexer
* * MSB   - Most Significant Bit
* * OPAMP - Operational Amplifier
* * PGA   - Programmable Gain Amplifier
* * PRB   - Programmable Reference, defines reference level of the voltage
* * SAR   - Successive Approximation Register
* * S/H   - Sample and Hold mode
* * SRSS  - System Resource Subsystem
* * STT   - State Transition Table, the table of state machine states for the Autonomous Analog,
*           essentially, the 'program' for the AC (for more details, see \ref cy_stc_autanalog_stt_t)
* * TIA   - Trans-impedance Amplifier
* * TRM   - Technical Reference Manual
* * TC    - Timer/Counter, the sub-block of the AC
* * VBGR  - Temperature-independent, band-gap voltage reference, used for e.g. PRB
* * VDDA  - Supplies voltage for all analog peripherals and analog core regulators in the device
* * Vref  - Reference Voltage
*
* \section group_autanalog_external_clocks SRSS Clocks
*
* The Autonomous Analog can use the following externally supplied clocks:
* * SRSS peripheral clock Clk_HF9 in chip Active mode using Peri 0 Clock Group 2 8-bit divider in the clock chain,\n
*   refer to the \ref group_autanalog_ac_mode chapter for AC\n
* * SRSS low frequency clock CLK_LF 32kHz used for AC wake-up Timer,\n
*   refer to the AC wake-up Timer configuration structure \ref cy_stc_autanalog_timer_t
*
*    \note The maximum clock frequency for Autonomous Analog is 80MHz
*
* \section group_autanalog_external_Vref External Vref
*
* The Autonomous Analog can use a locally generated Vref (refer to the PRB configuration structure \ref cy_stc_autanalog_prb_cfg_t) or\n
* a Vref supplied externally via the pin (refer to \ref group_autanalog_sar_vref chapter for SAR ADC)

*    \note The maximum level of the external Vref must not exceed the supply voltage for Autonomous Analog, which is 1.8V
*
* \section group_autanalog_section_configuration General Configuration Considerations
*
* \subsection group_autanalog_section_configuration_personalities Use ModusToolbox Device Configurator Tool to generate initialization code
* The steps to generate initialization code using the ModusToolbox Device Configurator:
* 1. Launch the ModusToolbox Device Configurator.
* 2. Enable the Autonomous Analog under the Analog category.
* 3. Select the clock source for the Autonomous Analog according to the intended operating mode\n
*    (refer to \ref group_autanalog_ac_mode chapter for AC) and set the clock divider value to achieve the desired clock rate.
* 4. Preserve the use of the appropriate pins for the required subsystems of the Autonomous Analog.
* 5. Enable the control of the \ref group_autanalog_ac_dout (if required).
* 6. Enable AC \ref group_autanalog_ac_out_trigg (if required).
* 7. Enable AC \ref group_autanalog_ac_in_trigg (if required).
* 8. Enable and configure \ref group_autanalog_ac
*    \note The AC first sate must be set to "Wait Blocks Ready",\n
*    (refer to configuration structure \ref cy_en_autanalog_stt_ac_condition_t)
*    when using subsystems other than AC.
* 9. Enable and configure other required subsystems:\n
*       \ref group_autanalog_ctb;\n
*       \ref group_autanalog_ptcomp;\n
*       \ref group_autanalog_dac;\n
*       \ref group_autanalog_sar;\n
*       \ref group_autanalog_fifo;\n
*
* \section group_autanalog_section_more_information More Information
*
* For more information on the Autonomous Analog,
* refer to the device Architecture Technical Reference Manual (TRM).
*
* \defgroup group_autanalog_ac     AC      (Autonomous Controller)
* \defgroup group_autanalog_ctb    CTB     (Continuous Time Block)
* \defgroup group_autanalog_ptcomp PTComp  (Programmable Threshold Comparator)
* \defgroup group_autanalog_dac    CT DAC  (Continuous Time Digital to Analog Converter)
* \defgroup group_autanalog_sar    SAR ADC (Successive-Approximation Register Analog to Digital Converter)
* \defgroup group_autanalog_fifo   FIFO    (The buffer block to store collected data)
* \defgroup group_autanalog_gen    General section of the API
* \{
*   \defgroup group_autanalog_macros Macros
*   \defgroup group_autanalog_functions Functions
*     \{
*         \defgroup group_autanalog_functions_init Initialization/Deinitialization Functions
*         \defgroup group_autanalog_functions_int Interrupt Functions
*     \}
*   \defgroup group_autanalog_data_structures Data Structures
*   \defgroup group_autanalog_enums Enumerated Types
* \}
*/

#if !defined(CY_AUTANALOG_H)
#define CY_AUTANALOG_H

#include "cy_autanalog_common.h"
#include "cy_autanalog_ac.h"

#ifdef CY_IP_MXS22LPPASS

#ifdef CY_IP_MXS22LPPASS_CTB
#include "cy_autanalog_ctb.h"
#endif /* CY_IP_MXS22LPPASS_CTB */

#ifdef CY_IP_MXS22LPPASS_PTC
#include "cy_autanalog_ptc.h"
#endif /* CY_IP_MXS22LPPASS_PTC */

#ifdef CY_IP_MXS22LPPASS_DAC
#include "cy_autanalog_dac.h"
#endif /* CY_IP_MXS22LPPASS_DAC */

#ifdef CY_IP_MXS22LPPASS_SAR
#include "cy_autanalog_sar.h"
#endif /* CY_IP_MXS22LPPASS_SAR */

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_autanalog_macros
* \{
*/
/**
 * The number of programmable reference voltage blocks,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_PRB_NUM                                     (2U)
/**
 * The number of configurations for priority enabler,
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_PRIORITY_ENABLER_NUM                        (4U)

/* The set of interrupt masks to configure interrupts within the Autonomous Analog */
#define CY_AUTANALOG_INT_CTB0_COMP0       (LPPASS_MMIO_INTR_CAUSE_CTBL0_COMP0_INT_Msk)     /**< CTB0 COMP0 interrupt */
#define CY_AUTANALOG_INT_CTB0_COMP1       (LPPASS_MMIO_INTR_CAUSE_CTBL0_COMP1_INT_Msk)     /**< CTB0 COMP1 interrupt */
#define CY_AUTANALOG_INT_CTB1_COMP0       (LPPASS_MMIO_INTR_CAUSE_CTBL1_COMP0_INT_Msk)     /**< CTB1 COMP0 interrupt */
#define CY_AUTANALOG_INT_CTB1_COMP1       (LPPASS_MMIO_INTR_CAUSE_CTBL1_COMP1_INT_Msk)     /**< CTB1 COMP1 interrupt */
#define CY_AUTANALOG_INT_PTC0_COMP0       (LPPASS_MMIO_INTR_CAUSE_PTC_COMP0_INT_Msk)       /**< PTC0 COMP0 interrupt */
#define CY_AUTANALOG_INT_PTC0_COMP1       (LPPASS_MMIO_INTR_CAUSE_PTC_COMP1_INT_Msk)       /**< PTC0 COMP1 interrupt */
#define CY_AUTANALOG_INT_PTC0_RANGE0      (LPPASS_MMIO_INTR_CAUSE_PTC_RANGE0_INT_Msk)      /**< PTC0 RANGE0 interrupt */
#define CY_AUTANALOG_INT_PTC0_RANGE1      (LPPASS_MMIO_INTR_CAUSE_PTC_RANGE1_INT_Msk)      /**< PTC0 RANGE1 interrupt */
#define CY_AUTANALOG_INT_DAC0_RANGE0      (LPPASS_MMIO_INTR_CAUSE_DAC0_RANGE0_INT_Msk)     /**< DAC0 RANGE0 interrupt */
#define CY_AUTANALOG_INT_DAC0_RANGE1      (LPPASS_MMIO_INTR_CAUSE_DAC0_RANGE1_INT_Msk)     /**< DAC0 RANGE1 interrupt */
#define CY_AUTANALOG_INT_DAC0_RANGE2      (LPPASS_MMIO_INTR_CAUSE_DAC0_RANGE2_INT_Msk)     /**< DAC0 RANGE2 interrupt */
#define CY_AUTANALOG_INT_DAC0_EPOCH       (LPPASS_MMIO_INTR_CAUSE_DAC0_EPOCH_INT_Msk)      /**< DAC0 EPOCH interrupt */
#define CY_AUTANALOG_INT_DAC0_EMPTY       (LPPASS_MMIO_INTR_CAUSE_DAC0_EMPTY_INT_Msk)      /**< DAC0 EMPTY interrupt */
#define CY_AUTANALOG_INT_DAC1_RANGE0      (LPPASS_MMIO_INTR_CAUSE_DAC1_RANGE0_INT_Msk)     /**< DAC1 RANGE0 interrupt */
#define CY_AUTANALOG_INT_DAC1_RANGE1      (LPPASS_MMIO_INTR_CAUSE_DAC1_RANGE1_INT_Msk)     /**< DAC1 RANGE1 interrupt */
#define CY_AUTANALOG_INT_DAC1_RANGE2      (LPPASS_MMIO_INTR_CAUSE_DAC1_RANGE2_INT_Msk)     /**< DAC1 RANGE2 interrupt */
#define CY_AUTANALOG_INT_DAC1_EPOCH       (LPPASS_MMIO_INTR_CAUSE_DAC1_EPOCH_INT_Msk)      /**< DAC1 EPOCH interrupt */
#define CY_AUTANALOG_INT_DAC1_EMPTY       (LPPASS_MMIO_INTR_CAUSE_DAC1_EMPTY_INT_Msk)      /**< DAC1 EMPTY interrupt */
#define CY_AUTANALOG_INT_SAR0_DONE        (LPPASS_MMIO_INTR_CAUSE_SAR_DONE_INT_Msk)        /**< SAR0 DONE interrupt */
#define CY_AUTANALOG_INT_SAR0_EOS         (LPPASS_MMIO_INTR_CAUSE_SAR_EOS_INT_Msk)         /**< SAR0 EOS interrupt */
#define CY_AUTANALOG_INT_SAR0_RESULT      (LPPASS_MMIO_INTR_CAUSE_SAR_RESULT_INT_Msk)      /**< SAR0 RESULT interrupt */
#define CY_AUTANALOG_INT_SAR0_RANGE0      (LPPASS_MMIO_INTR_CAUSE_SAR_RANGE0_INT_Msk)      /**< SAR0 RANGE0 interrupt */
#define CY_AUTANALOG_INT_SAR0_RANGE1      (LPPASS_MMIO_INTR_CAUSE_SAR_RANGE1_INT_Msk)      /**< SAR0 RANGE1 interrupt */
#define CY_AUTANALOG_INT_SAR0_RANGE2      (LPPASS_MMIO_INTR_CAUSE_SAR_RANGE2_INT_Msk)      /**< SAR0 RANGE2 interrupt */
#define CY_AUTANALOG_INT_SAR0_RANGE3      (LPPASS_MMIO_INTR_CAUSE_SAR_RANGE3_INT_Msk)      /**< SAR0 RANGE3 interrupt */
#define CY_AUTANALOG_INT_SAR0_FIR0_RESULT (LPPASS_MMIO_INTR_CAUSE_SAR_FIR0_RESULT_INT_Msk) /**< SAR0 FIR0 RESULT interrupt */
#define CY_AUTANALOG_INT_SAR0_FIR1_RESULT (LPPASS_MMIO_INTR_CAUSE_SAR_FIR1_RESULT_INT_Msk) /**< SAR0 FIR1 RESULT interrupt */
#define CY_AUTANALOG_INT_AC               (LPPASS_MMIO_INTR_CAUSE_AC_INT_Msk)              /**< AC interrupt */

/** \cond INTERNAL */

/** The combined interrupt mask for all available interrupts within the Autonomous Analog */
#define CY_AUTANALOG_INTR                 (CY_AUTANALOG_INT_CTB0_COMP0       | \
                                           CY_AUTANALOG_INT_CTB0_COMP1       | \
                                           CY_AUTANALOG_INT_CTB1_COMP0       | \
                                           CY_AUTANALOG_INT_CTB1_COMP1       | \
                                           CY_AUTANALOG_INT_PTC0_COMP0       | \
                                           CY_AUTANALOG_INT_PTC0_COMP1       | \
                                           CY_AUTANALOG_INT_PTC0_RANGE0      | \
                                           CY_AUTANALOG_INT_PTC0_RANGE1      | \
                                           CY_AUTANALOG_INT_DAC0_RANGE0      | \
                                           CY_AUTANALOG_INT_DAC0_RANGE1      | \
                                           CY_AUTANALOG_INT_DAC0_RANGE2      | \
                                           CY_AUTANALOG_INT_DAC0_EPOCH       | \
                                           CY_AUTANALOG_INT_DAC0_EMPTY       | \
                                           CY_AUTANALOG_INT_DAC1_RANGE0      | \
                                           CY_AUTANALOG_INT_DAC1_RANGE1      | \
                                           CY_AUTANALOG_INT_DAC1_RANGE2      | \
                                           CY_AUTANALOG_INT_DAC1_EPOCH       | \
                                           CY_AUTANALOG_INT_DAC1_EMPTY       | \
                                           CY_AUTANALOG_INT_SAR0_DONE        | \
                                           CY_AUTANALOG_INT_SAR0_EOS         | \
                                           CY_AUTANALOG_INT_SAR0_RESULT      | \
                                           CY_AUTANALOG_INT_SAR0_RANGE0      | \
                                           CY_AUTANALOG_INT_SAR0_RANGE1      | \
                                           CY_AUTANALOG_INT_SAR0_RANGE2      | \
                                           CY_AUTANALOG_INT_SAR0_RANGE3      | \
                                           CY_AUTANALOG_INT_SAR0_FIR0_RESULT | \
                                           CY_AUTANALOG_INT_SAR0_FIR1_RESULT | \
                                           CY_AUTANALOG_INT_AC)

/* Helper macro for validation of the subsystem ID within the Autonomous Analog */
#define CY_AUTANALOG_SUBSYSTEM_ID(value)   ((value) <= CY_AUTANALOG_SAR)
/* Helper macro to validate configured interrupts */
#define CY_AUTANALOG_INTR_MASK(interrupt)  (0UL == ((interrupt) & ~CY_AUTANALOG_INTR))

/** \endcond */

/** \} group_autanalog_macros */

/***************************************
*       Enumerated Types
***************************************/

/**
* \addtogroup group_autanalog_enums
* \{
*/

/**
 * Select the source voltage for the PRB (Vsrc),
 * for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_PRB_VBGR = 0UL, /**< The reference is derived from VBGR, the nominal value of Vsrc is 0.9V */
    CY_AUTANALOG_PRB_VDDA = 1UL  /**< The reference is derived from VDDA, the maximum value of Vsrc is 1.8V */

} cy_en_autanalog_prb_src_t;


/**
 * The position of the TAP to select the required Vref from the PRB,
 * the actual value of the Vref depends on the source voltage for PRB (Vsrc), see \ref cy_en_autanalog_prb_src_t.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_PRB_TAP_0  = 0UL,  /**< Vref = 0.06 * Vsrc */
    CY_AUTANALOG_PRB_TAP_1  = 1UL,  /**< Vref = 0.13 * Vsrc */
    CY_AUTANALOG_PRB_TAP_2  = 2UL,  /**< Vref = 0.19 * Vsrc */
    CY_AUTANALOG_PRB_TAP_3  = 3UL,  /**< Vref = 0.25 * Vsrc */
    CY_AUTANALOG_PRB_TAP_4  = 4UL,  /**< Vref = 0.31 * Vsrc */
    CY_AUTANALOG_PRB_TAP_5  = 5UL,  /**< Vref = 0.38 * Vsrc */
    CY_AUTANALOG_PRB_TAP_6  = 6UL,  /**< Vref = 0.44 * Vsrc */
    CY_AUTANALOG_PRB_TAP_7  = 7UL,  /**< Vref = 0.50 * Vsrc */
    CY_AUTANALOG_PRB_TAP_8  = 8UL,  /**< Vref = 0.56 * Vsrc */
    CY_AUTANALOG_PRB_TAP_9  = 9UL,  /**< Vref = 0.63 * Vsrc */
    CY_AUTANALOG_PRB_TAP_10 = 10UL, /**< Vref = 0.69 * Vsrc */
    CY_AUTANALOG_PRB_TAP_11 = 11UL, /**< Vref = 0.75 * Vsrc */
    CY_AUTANALOG_PRB_TAP_12 = 12UL, /**< Vref = 0.81 * Vsrc */
    CY_AUTANALOG_PRB_TAP_13 = 13UL, /**< Vref = 0.88 * Vsrc */
    CY_AUTANALOG_PRB_TAP_14 = 14UL, /**< Vref = 0.94 * Vsrc */
    CY_AUTANALOG_PRB_TAP_15 = 15UL, /**< Vref = 1.00 * Vsrc */

} cy_en_autanalog_prb_tap_t;

/** \cond INTERNAL */

/**
 * Default values for start-up/settling delay counters
 */
typedef enum
{
    CY_AUTANALOG_PRIORITY_GROUP0_CNT = 11U, /**< 3uS */
    CY_AUTANALOG_PRIORITY_GROUP1_CNT = 7U,  /**< 2uS */
    CY_AUTANALOG_PRIORITY_GROUP2_CNT = 19U, /**< 5uS */
    CY_AUTANALOG_PRIORITY_GROUP3_CNT = 39U, /**< 10uS */

} cy_en_autanalog_priority_group_counter_t;

/** \endcond */

/** \} group_autanalog_enums */

/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_autanalog_data_structures
* \{
*/

/** The configuration structure for the PRB,
 *  used in \ref cy_stc_autanalog_prb_t
 */
typedef struct
{
    bool                      enable; /**< Enable the PRB Vref control */
    cy_en_autanalog_prb_src_t src;    /**< The selector of the source voltage for PRB */
    cy_en_autanalog_prb_tap_t tap;    /**< Selector of the tap for the required Vref from PRB */

} cy_stc_autanalog_prb_cfg_t;


/** The high-level configuration structure for the infrastructure of the Autonomous Analog,
 *  used in \ref Cy_AutAnalog_PRB_LoadConfig.
 */
typedef struct
{
    /** PRB */
    cy_stc_autanalog_prb_cfg_t  * prb[CY_AUTANALOG_PRB_NUM]; /**< The configuration structure for the PRB */

} cy_stc_autanalog_prb_t;


/** The PRB section in the State Transition Table state,
 *  used in \ref cy_stc_autanalog_stt_t.
 *  For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef struct
{
    bool                      unlock;      /**< PRB Unlock:\n
                                            * FALSE - Locked:\n
                                            *    Data from fields prbVrefxFw and prbVrefxTap
                                            *    will NOT be taken into account in
                                            *    the corresponding state of STT\n
                                            * TRUE - Unlocked:\n
                                            *    Data from fields prbVrefxFw and prbVrefxTap
                                            *    will be used in the STT corresponding state
                                            */
    /** PRB Vref0 */
    bool                      prbVref0Fw;  /**< The control of PRB Vref0 from the firmware,
                                            *   Vref0 must be enabled in \ref cy_stc_autanalog_prb_cfg_t\n
                                            * FALSE - the PRB output determined by the field prbVref0Tap in this structure\n
                                            * TRUE  - the PRB output determined by the tap field, defined in
                                            *        \ref cy_stc_autanalog_prb_cfg_t
                                            */
    cy_en_autanalog_prb_tap_t prbVref0Tap; /**< The tap selector for the required Vref0 */

    /** PRB Vref1 */
    bool                      prbVref1Fw;  /**< The control of PRB Vref0 from the firmware,
                                            *   Vref1 must be enabled in \ref cy_stc_autanalog_prb_cfg_t\n
                                            * FALSE - the PRB output determined by the field prbVref1Tap in this structure\n
                                            * TRUE  - the PRB output determined by the tap field, defined in
                                            *        \ref cy_stc_autanalog_prb_cfg_t
                                            */
    cy_en_autanalog_prb_tap_t prbVref1Tap; /**< The tap selector for the required Vref1 */

} cy_stc_autanalog_stt_prb_t;


/**
 * The configuration structure to set up the entire Autonomous Analog
 * used with \ref cy_stc_autanalog_t and \ref Cy_AutAnalog_LoadConfig.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef struct
{
    cy_stc_autanalog_prb_t    * prb;                  /**< The pointer to the PRB configuration */
    cy_stc_autanalog_ac_t     * ac;                   /**< The pointer to the AC configurations */

#ifdef CY_IP_MXS22LPPASS_CTB
    cy_stc_autanalog_ctb_t    * ctb[PASS_NR_CTBLS];   /**< The array of pointers to the CTB subsystem configurations */
#endif /* CTBs */

#ifdef CY_IP_MXS22LPPASS_PTC
    cy_stc_autanalog_ptcomp_t * ptcomp[PASS_NR_PTCS]; /**< The array of pointers to the PTComp subsystem configurations */
#endif /* PTCs */

#ifdef CY_IP_MXS22LPPASS_DAC
    cy_stc_autanalog_dac_t    * dac[PASS_NR_DACS];    /**< The array of pointers to the DAC subsystem configurations */
#endif /* DACs */

#ifdef CY_IP_MXS22LPPASS_SAR
    cy_stc_autanalog_sar_t    * sar[PASS_NR_SARS];    /**< The array of pointers to the SAR subsystem configurations */
#endif /* SARs */

} cy_stc_autanalog_cfg_t;


/**
 * The configuration structure for one row of the State Transition Table,
 * the array of these structures defines the entire State Transition Table.
 * The State Transition Table may have maximum 64 rows.
 * Used in \ref cy_stc_autanalog_t and
 * \ref Cy_AutAnalog_LoadStateTransitionTable, \ref Cy_AutAnalog_UpdateStateTransitionTable.
 * For more details, refer to the device Architecture Technical Reference Manual.
 */
typedef struct
{
    cy_stc_autanalog_stt_ac_t     * ac;                   /**< The pointer to the AC subsystem STT */
    cy_stc_autanalog_stt_prb_t    * prb;                  /**< The pointer to the PRB subsystem STT */

#ifdef CY_IP_MXS22LPPASS_CTB
    cy_stc_autanalog_stt_ctb_t    * ctb[PASS_NR_CTBLS];   /**< The array of pointers to the CTB subsystem STT */
#endif /* CTBs */

#ifdef CY_IP_MXS22LPPASS_PTC
    cy_stc_autanalog_stt_ptcomp_t * ptcomp[PASS_NR_PTCS]; /**< The array of pointers to the PTComp subsystem STT */
#endif /* PTCs*/

#ifdef CY_IP_MXS22LPPASS_DAC
    cy_stc_autanalog_stt_dac_t    * dac[PASS_NR_DACS];    /**< The array of pointers to the DAC subsystem STT */
#endif /* DACs */

#ifdef CY_IP_MXS22LPPASS_SAR
    cy_stc_autanalog_stt_sar_t    * sar[PASS_NR_SARS];    /**< The array of pointers to the SAR subsystem STT */
#endif /* SARs */

} cy_stc_autanalog_stt_t;


/**
 * The configuration and STT data to set up the entire Autonomous Analog,
 * used in \ref Cy_AutAnalog_Init.
 */
typedef struct
{
    cy_stc_autanalog_cfg_t * configuration;        /**< The pointer to the whole configuration structure */
    uint8_t                  numSttEntries;        /**< The number of states in the State Transition Table */
    cy_stc_autanalog_stt_t * stateTransitionTable; /**< The pointer to the array of the entire State Transition Table */

} cy_stc_autanalog_t;

/** \} group_autanalog_data_structures */


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_autanalog_functions
* \{
*/
__STATIC_INLINE uint32_t Cy_AutAnalog_GetInterruptCause(void);
__STATIC_INLINE uint32_t Cy_AutAnalog_GetInterruptStatus(void);
__STATIC_INLINE void     Cy_AutAnalog_ClearInterrupt(uint32_t interrupt);
__STATIC_INLINE void     Cy_AutAnalog_SetInterrupt(uint32_t interrupt);
__STATIC_INLINE void     Cy_AutAnalog_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t Cy_AutAnalog_GetInterruptMask(void);
__STATIC_INLINE uint32_t Cy_AutAnalog_GetInterruptStatusMasked(void);


/** \cond INTERNAL */

/*******************************************************************************
* Function Name: Cy_AutAnalog_AdvPowerControl
****************************************************************************//**
*
* Advanced power control API for the Autonomous Analog.
*
* \param sleepModeAC
* Controls the digital power supply for the Autonomous Analog when AC is asleep:\n
* - False - keeps the entire Autonomous Analog digital supply powered
* when AC is asleep (i.e. AC ACTION = WAIT_FOR, \ref cy_en_autanalog_stt_ac_action_t and
* AC CONDITION = wake-up source, \ref cy_en_autanalog_stt_ac_condition_t)\n
* - True - powers down the digital supply for the Autonomous Analog
* when AC is asleep (i.e. AC ACTION = WAIT_FOR, AC CONDITION = wake-up source)\n
* \note This option has the following consequences:\n
* - the digital leakage is reduced (all logic on the switched supply is powered off)
* - CTBs, SAR, FIRs and the DACs loose all configuration\n
*   (must be re-configured to be functional again)\n
* - the wake-up time is increased by 3us
*
* \param lpOscDutyCycle
* The LPOSC operation mode, \ref cy_en_autanalog_timer_clk_src_t:\n
* - False - LPOSC is always ON;\n
* - True - the LPOSC duty cycled is based on AC wake-up signal.
*
* \param sarLpCorePowerCycle
* Disable SAR core and Channel Buffers after conversion in Low Power operating mode
* (recommended for use with duty cycle enabled, see lpOscDutyCycle)\n
* - False - SAR core and Channel Buffers always enabled;\n
* - True - SAR core and Channel Buffers are disabled after conversion.
*
*******************************************************************************/
#if !((CY_IP_MXS22LPPASS_VERSION == 1UL) && (CY_IP_MXS22LPPASS_VERSION_MINOR == 0UL))
void Cy_AutAnalog_AdvPowerControl(bool sleepModeAC, bool lpOscDutyCycle, bool sarLpCorePowerCycle);
#else
void Cy_AutAnalog_AdvPowerControl(bool sleepModeAC, bool lpOscDutyCycle);
#endif

/** \endcond */


/**
* \addtogroup group_autanalog_functions_init
* This set of functions is used to Init/Deinit the Autonomous Analog.
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_Clear
****************************************************************************//**
*
* Clears the SAR ADC FIFO, the DAC LUT (the entire SRAM) and the State Transition Table,
* but leaves the Autonomous Analog configuration in the MMIO.
*
*******************************************************************************/
void Cy_AutAnalog_Clear(void);


/*******************************************************************************
* Function Name: Cy_AutAnalog_Init
****************************************************************************//**
*
* Initializes the entire Autonomous Analog with the configuration and states provided.
*
* \param cfgAndStates
* The pointer to the structure containing the configuration data and the content of
* the State Transition Table for the entire Autonomous Analog.
**
* \return
* The combined value of all the subsystem statuses, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
uint32_t Cy_AutAnalog_Init(const cy_stc_autanalog_t * cfgAndStates);


/*******************************************************************************
* Function Name: Cy_AutAnalog_Disable
****************************************************************************//**
*
* Disables the Autonomous Analog and powers down the digital supply to reduce the leakage.
* \note The configuration of the Autonomous Analog in the MMIO,
* the content of the State Transition Table, data in the SAR ADC FIFO, and
* the DAC LUT will be lost.
*
*******************************************************************************/
void Cy_AutAnalog_Disable(void);


/*******************************************************************************
* Function Name: Cy_AutAnalog_Enable
****************************************************************************//**
*
* Enable the Autonomous Analog for operation.
* \note This API does not start the Autonomous Controller,
* use \ref Cy_AutAnalog_StartAutonomousControl for the actual start.
*
*******************************************************************************/
void Cy_AutAnalog_Enable(void);


/*******************************************************************************
* Function Name: Cy_AutAnalog_LoadConfig
****************************************************************************//**
*
* Configures the Autonomous Analog per provided settings.
* \note This function also
* * enables the IP block;
* * configures individual initialization delays for enabled subsystems;
* * loads trimming values for Autonomous Analog;
*
* \param analogCfg
* The pointer to the structure containing configuration data
* for the entire Autonomous Analog.
*
* \return
* The combined value of all the subsystem statuses, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
uint32_t Cy_AutAnalog_LoadConfig(const cy_stc_autanalog_cfg_t * analogCfg);


/*******************************************************************************
* Function Name: Cy_AutAnalog_LoadStateTransitionTable
****************************************************************************//**
*
* Configures the State Transition Table of the the Autonomous Controller
* per provided settings.
*
* \param numEntries
* Number of entries in the State Transition Table.
*
* \param stateTransitionTable
* The pointer to an array containing configuration data for the entire State Transition Table.
*
* \return
* The combined value of all the subsystem statuses, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_LoadStateTransitionTable(uint8_t numEntries, const cy_stc_autanalog_stt_t * stateTransitionTable);


/*******************************************************************************
* Function Name: Cy_AutAnalog_UpdateStateTransitionTable
****************************************************************************//**
*
* Add or replace states in the State Transition Table.
*
* \param numEntries
* The number of entries in the State Transition Table for add/replace.
*
* \param stateTransitionTable
* The pointer to an array containing a new set of configuration data for the State Transition Table,
* to be added or replaced.
*
* \param startState
* Defines the state in the State Transition Table from which the content update starts.
*
* \return
* Combined value of all the subsystem statuses, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_UpdateStateTransitionTable(uint8_t numEntries, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t startState);


/*******************************************************************************
* Function Name: Cy_AutAnalog_PRB_LoadConfig
****************************************************************************//**
*
* Configures the PRB instance per settings in the configuration structure.
*
* \param prbIdx
* Index of the PRB block within the Autonomous Analog infrastructure.
*
* \param prbCfg
* The pointer to a structure containing configuration data
* for the PRB subsystem.
*
* \return
* The status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_PRB_LoadConfig(uint8_t prbIdx, const cy_stc_autanalog_prb_t * prbCfg);


/** \} group_autanalog_functions_init */

/*******************************************************************************
* Function Name: Cy_AutAnalog_PRB_Write
****************************************************************************//**
*
* Immediately updates the PRB output.
* \note Only applicable if firmware mode for Vref is enabled in the State Transition Table,
* \ref cy_stc_autanalog_stt_prb_t::prbVref0Fw, \ref cy_stc_autanalog_stt_prb_t::prbVref1Fw.
*
* \param prbIdx
* The index of the PRB block within the Autonomous Analog infrastructure.
*
* \param tap
* The location of the TAP for the required Vref from the PRB.
*
*******************************************************************************/
void Cy_AutAnalog_PRB_Write(uint8_t prbIdx, cy_en_autanalog_prb_tap_t tap);

/**
* \addtogroup group_autanalog_functions_int
* This set of functions is used to handle general interrupts in the Autonomous Analog.
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_GetInterruptCause
****************************************************************************//**
*
* Returns the cause of the interrupt for the Autonomous Analog.
*
* \return
* The mask of the event, which causes an interrupt in the Autonomous Analog.
* See \ref group_autanalog_macros section for defined interrupts in the Autonomous Analog.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_AutAnalog_GetInterruptCause(void)
{
    return AUTANALOG_MMIO_INTR_CAUSE(LPPASS_MMIO_BASE);
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_GetInterruptStatus
****************************************************************************//**
*
* Returns the status of combined Autonomous Analog interrupt requests.
*
* \return
* The combined mask of interrupt requests for the Autonomous Analog.
* See \ref group_autanalog_macros section for defined interrupts in the Autonomous Analog.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_AutAnalog_GetInterruptStatus(void)
{
    return AUTANALOG_MMIO_INTR(LPPASS_MMIO_BASE);
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_ClearInterrupt
****************************************************************************//**
*
* Clears the interrupts for the Autonomous Analog.
*
* \param interrupt
* The mask of the interrupts to be cleared. Each bit of this mask is responsible for
* clearing of the corresponding interrupt in the Autonomous Analog.
* See \ref group_autanalog_macros section for defined interrupts in the Autonomous Analog.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_ClearInterrupt(uint32_t interrupt)
{
    CY_ASSERT_L2(CY_AUTANALOG_INTR_MASK(interrupt));

    AUTANALOG_MMIO_INTR(LPPASS_MMIO_BASE) = CY_AUTANALOG_INTR & interrupt;

    /*
     * This dummy read guarantees that the interrupt will be cleared on return from this function.
     */
    (void) AUTANALOG_MMIO_INTR(LPPASS_MMIO_BASE);
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SetInterrupt
****************************************************************************//**
*
* Sets a software interrupt request for the Autonomous Analog.
*
* \param interrupt
* The mask of the interrupts to be set. Each bit of this mask is responsible for
* triggering of the corresponding interrupt in the Autonomous Analog.
* See \ref group_autanalog_macros section for defined interrupts in the Autonomous Analog.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_SetInterrupt(uint32_t interrupt)
{
    CY_ASSERT_L2(CY_AUTANALOG_INTR_MASK(interrupt));

    AUTANALOG_MMIO_INTR_SET(LPPASS_MMIO_BASE) = CY_AUTANALOG_INTR & interrupt;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SetInterruptMask
****************************************************************************//**
*
* Configures which bits of the interrupt request register will trigger
* an interrupt event in the Autonomous Analog.
*
* \param mask
* The mask of interrupts allowed to be activated. Each bit of this mask
* allows the corresponding interrupt to be triggered in the Autonomous Analog.
* See \ref group_autanalog_macros section for defined interrupts in the Autonomous Analog.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_SetInterruptMask(uint32_t mask)
{
    CY_ASSERT_L2(CY_AUTANALOG_INTR_MASK(mask));

    AUTANALOG_MMIO_INTR_MASK(LPPASS_MMIO_BASE) = CY_AUTANALOG_INTR & mask;
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_ClearInterruptMask
****************************************************************************//**
*
* Configures which bits of the interrupt request register will be cleared
* in the Autonomous Analog.
*
* \param mask
* The mask for the clearing of the bits of the interrupt request register
* in the Autonomous Analog.
* See \ref group_autanalog_macros section for defined interrupts
* in the Autonomous Analog.
*
*******************************************************************************/
__STATIC_INLINE void Cy_AutAnalog_ClearInterruptMask(uint32_t mask)
{
    CY_ASSERT_L2(CY_AUTANALOG_INTR_MASK(mask));

    AUTANALOG_MMIO_INTR_MASK(LPPASS_MMIO_BASE) &= CY_AUTANALOG_INTR & (~mask);
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_GetInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask. Each bit of this mask represents an interrupt
* that is allowed in the Autonomous Analog.
*
* \return
* The mask of the interrupts that can be activated.
* See \ref group_autanalog_macros section for defined interrupts in the Autonomous Analog.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_AutAnalog_GetInterruptMask(void)
{
    return AUTANALOG_MMIO_INTR_MASK(LPPASS_MMIO_BASE);
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the result of the bitwise AND operation between the
* corresponding interrupt request and mask bits.
* See \ref Cy_AutAnalog_GetInterruptStatus and \ref Cy_AutAnalog_SetInterruptMask.
*
* \return
* The masked status of combined interrupt requests for the Autonomous Analog.
* See \ref group_autanalog_macros section for defined interrupts in the Autonomous Analog.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_AutAnalog_GetInterruptStatusMasked(void)
{
    return AUTANALOG_MMIO_INTR_MASKED(LPPASS_MMIO_BASE);
}

/** \} group_autanalog_functions_int */

/** \} group_autanalog_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22LPPASS */

#endif /** !defined(CY_AUTANALOG_H) */

/** \} group_autanalog */

/* [] END OF FILE */
