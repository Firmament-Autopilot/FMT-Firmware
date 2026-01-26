/***************************************************************************//**
* \file cy_autanalog_ac.h
* \version 2.0
*
* \brief
* Header file for the Autonomous Controller (AC) subsystem of the Autonomous Analog.
*
********************************************************************************
* \copyright
* Copyright(c) 2023-2025 Infineon Technologies AG or an affiliate of
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
* \addtogroup group_autanalog_ac
* \{
* This driver provides API functions to configure the Autonomous Controller (AC) subsystem within the Autonomous Analog.
*
* The AC controls the entire operation of the Autonomous Analog. This includes enabling/disabling analog blocks,
* configuring them using the dynamic part of the configuration, checking state/status and handling events by
* taking conditional actions, managing intermediate data and notifying the host MCU/peripheral using interrupts/triggers.
*
* The diagram below shows the AC simplified internals.
*
* \image html LPPASS_AC_General.png
*
* For more information on the AC,
* refer to the device Architecture Technical Reference Manual (TRM).\n
* For the exact location of the digital outputs pins, see the device datasheet.
*
* \section group_autanalog_ac_stt State Transition Table
*
* The AC FSM is based on a sequencer that can operate in all power modes except Hibernate.
* The set of operating states for this sequencer is named the State Transition Table (STT).
* The total number of the states in the STT is 64. The STT of Autonomous Analog is defined by \ref cy_stc_autanalog_stt_t
* and illustrated on the diagram below.
*
* \image html LPPASS_STT.png
*
* The AC part of the STT (STT AC) is configured with \ref cy_stc_autanalog_stt_ac_t and described below.
* The STTs for other subsystems are described in the relevant chapter for each subsystem.
*
* In each state of the STT, the AC interacts with other subsystems of the Autonomous Analog via a standard interface
* (see \ref group_autanalog_ac_interface chapter). This interaction includes receiving the subsystem status and
* issuing the appropriate action (if any), see \ref group_autanalog_ac_cond_act chapter.
*
* The AC can change the STT state sequentially or take branch conditionally,
* depending on events from the subsystems of the Autonomous Analog.
*
* \subsection group_autanalog_ac_interface AC Interface
*
* The AC has a standard interface for each sub-system of the Autonomous Analog:
* - Enable sub-system (used to enable/disable, gate resets/clocks, and power analog macros)\n
*   e.g. \ref cy_stc_autanalog_stt_ctb_t::enableOpamp0 for the CTB;
* - Static Configuration Selection for channel selection (to sub-systems like the ADC and DAC)\n
*   e.g. \ref cy_stc_autanalog_stt_dac_t::channel for the DAC;
* - Dynamic Configuration Selection for routing and/or gain (for sub-systems like the PTComp and CTB)\n
*   e.g. \ref cy_stc_autanalog_stt_ptcomp_t::dynCfgIdxComp0;
* - Condition(s) (varies per sub-system)
*   e.g. \ref cy_en_autanalog_stt_ac_condition_t::CY_AUTANALOG_STT_AC_CONDITION_SAR_DONE;
* - Action Trigger(s) (internal triggers for the clocked sub-systems like the ADC and DAC)
*   e.g. \ref cy_stc_autanalog_stt_sar_t::trigger;
*
* The subsystems provide their interfaces for the AC in the \ref cy_stc_autanalog_stt_t configuration structure.
* The complete STT configuration contains the total number of states used in the STT (\ref cy_stc_autanalog_t::numSttEntries)
* and a pointer to the array of configured interfaces of that size (\ref cy_stc_autanalog_t::stateTransitionTable).
*
* \subsection group_autanalog_ac_cond_act AC Conditions and Actions
*
* The CONDITION events (\ref cy_en_autanalog_stt_ac_condition_t) are statuses from the sub-systems of the Autonomous Analog
* for the AC that can be used to branch (\ref cy_en_autanalog_stt_ac_action_t) the program execution (i.e. change the STT state)
* and/or triggering an appropriate action for the subsystem (e.g. cy_stc_autanalog_stt_dac_t::trigger).
*
* \section group_autanalog_ac_tc AC Loop/Interval Counters
*
* The AC contains four Loop/Interval counters that are programmatically assigned to the STT states. These down counters are
* used by the AC to implement delays in a given STT state (interval) or loop constructions that may contain several
* STT states. The AC can support up to 4 loop counters, or up to 3 loop counters and 1 interval counter. The counters periods are
* programmed with \ref cy_stc_autanalog_stt_ac_t::count. Every AC clock cycle (see \ref group_autanalog_ac_clock chapter),
* the counter value decrements. When the counter value reaches zero (terminal count), the counter asserts a CNT_DONE trigger
* that is read by the AC.
*
* The current state of the Loop/Interval Counter represents \ref cy_stc_autanalog_state_tc_t configuration structure.
*
* \subsection group_autanalog_ac_lc Loop Counters
*
* The loop counters are used for repeating certain STT states for a finite number of times. The user requests a
* Loop Counter by programming a particular STT state with the BRANCH_IF_* action and CNT_DONE condition.
*
* \note When programming the AC to jump back to a particular state,\n
* it is recommended to use ACTION = BRANCH_IF_TRUE/BRANCH_IF_TRUE_CLR, CONDITION = TRUE.\n
* Avoid using ACTION = BRANCH_IF_FALSE/BRANCH_IF_FALSE_CLR, CONDITION = FALSE,\n
* as it could may cause unexpected issues.
*
* \subsection group_autanalog_ac_ic Interval Counter
*
* The interval counters are used for waiting in a particular STT state for a finite amount of time. The user requests an
* Interval Counter by programming a particular STT state with the WAIT_FOR action and CNT_DONE condition.
*
* \section group_autanalog_ac_state AC State
*
* The current AC state represents the \ref cy_stc_autanalog_state_ac_t configuration structure.
*
* \section group_autanalog_aa_state Autonomous Analog State
*
* The current Autonomous Analog state represents the \ref cy_stc_autanalog_state_t configuration structure.
*
* \section group_autanalog_ac_mode High Speed and Low Power operation
*
* The AC is available in both High Speed (HS) and Low Power (LP) modes. The operational mode of the AC determines the
* actual operation mode for the entire Autonomous Analog block (see \ref cy_stc_autanalog_stt_ac_t::lpMode).
*
* \section group_autanalog_ac_clock AC Clock
*
* In HS mode, the AC is clocked from CLK_HF9 directly (80MHz max) and functions only in chip Active mode.\n
* In LP mode, the AC is clocked from CLK_LPOSC (4.096MHz nominal) and functions in chip Active and Deep Sleep modes.
*
* \section group_autanalog_ac_pm Power Management
*
* In LP mode, the AC uses a dedicated logic for the Autonomous Analog digital logic duty cycling and minimizing both
* switching and leakage currents.
*
* \subsection group_autanalog_ac_dc Duty Cycling
*
* The AC requests a duty cycling event based on the programming of the ACTION and CONDITION
* (\ref cy_en_autanalog_stt_ac_action_t and \ref cy_en_autanalog_stt_ac_condition_t). Whenever the AC state is programmed with
* WAIT_FOR action and *_WAKEUP condition, a sleep request is sent to the duty cycle FSM.
*
* For configuration settings, see the \ref cy_stc_autanalog_stt_t configuration structure and refer to \ref group_autanalog_ac_stt
* chapter for more information.
*
* \subsection group_autanalog_ac_wakeup Wake-up Events and Wake-up Timer
*
* The duty cycling FSM supports several different wake-up sources:
* - Wake-up Timer;
* - See the rest of *_WAKEUP conditions in \ref cy_en_autanalog_stt_ac_condition_t;
*
* The wake-up Timer can be clocked from the 32kHz low frequency clock (CLK_LF) or
* (at the expense of additional switching current) the 4.096MHz low power oscillator (CLK_LPOSC).
*
* For configuration settings, see the \ref cy_stc_autanalog_timer_t configuration structure.
*
* \section group_autanalog_ac_cfg AC Configuration
*
* The AC configuration includes:
* - Wake-up timer (\ref group_autanalog_ac_wakeup chapter);
* - Enable the control a set of digital outputs (\ref group_autanalog_ac_dout chapter);
* - The set of masks to control output triggers (\ref group_autanalog_ac_trigg chapter);
*
* For configuration settings, see the \ref cy_stc_autanalog_ac_t configuration structure.
*
* \section group_autanalog_ac_dout AC Digital Outputs
*
* Four GPIOs can be directly controlled by the AC (\ref cy_stc_autanalog_stt_ac_t::gpioOut) in runtime. Before using this option,
* they must be enabled in the AC configuration (\ref cy_stc_autanalog_ac_t::gpioOutEn) and unlocked for a given state in the
* State Transition Table (\ref cy_stc_autanalog_stt_ac_t::unlockGpioOut). The digital waveforms are constructed based on the
* duration of a current state in the State Transition Table (\ref group_autanalog_ac_stt) and the order of state execution.
*
* For more details, refer to the \ref group_autanalog_ac_cfg and \ref group_autanalog_ac_stt chapters.
*
* \section group_autanalog_ac_trigg External Triggers
*
* The trigger is the method to start the activity in a given chip block without MCU intervention.
* The AC supports four (hardware/firmware) input triggers and eight (\ref cy_en_autanalog_ac_out_trigger_idx_t) output triggers.
*
* \subsection group_autanalog_ac_in_trigg Input Triggers
*
* The input trigger can be initiated by an event on external block (HW trigger) or from the API (FW trigger, \ref cy_en_autanalog_fw_trigger_t).
*
* \subsection group_autanalog_ac_fw_trigg Firmware Triggers
*
* The AC can use the FW triggers as the CONDITIONS (*_TR_AUTANALOG_IN*, \ref cy_en_autanalog_stt_ac_condition_t) for
* the available ACTIONS (\ref cy_en_autanalog_stt_ac_action_t).
*
* For more details about the AC CONDITIONS and ACTIONS, refer to the \ref group_autanalog_ac_cond_act chapter.
*
* The FW trigger can be issued by means of the provided API, \ref Cy_AutAnalog_FwTrigger.
*
* \subsection group_autanalog_ac_out_trigg Output Triggers
*
* The output trigger can be initiated in response to an event within the Autonomous Analog. The set of such events is defined in
* \ref cy_en_autanalog_ac_out_trigger_mask_t. The required output triggers must be enabled in the AC configuration structure
* (\ref cy_stc_autanalog_ac_t::mask). Also, you can modify them at runtime using the provided API.
* \ref Cy_AutAnalog_GetOutputTriggerMask, \ref Cy_AutAnalog_SetOutputTriggerMask.
*
* \section group_autanalog_ac_sample Sample use case: Interrupt and FW Trigger
*
* The blinky LED example is based on the AC and State Transition Table.\n
* The AC operates within the four states of the State Transition Table:\n
* - State #0 is used to initialize the enabled subsystems of the Autonomous Analog;\n
* - In state #1, the AC generates an interrupt;\n
* - In State #2, the AC is used to wait for the FW trigger;\n
* - State #3 is used for an unconditional return to State #1.\n
* \n
* The following Autonomous Analog configuration structures are automatically generated by the Device Configurator.
*
* \snippet autanalog/snippet/autanalog_ac_int.c SNIPPET_AC_INT_DEVICE_CONFIGURATOR_SECTION
* The content of the application is presented below:
* \snippet autanalog/snippet/autanalog_ac_int.c SNIPPET_AC_INT_APPLICATION_SECTION
* The content of main.c is shown below:
* \snippet autanalog/snippet/autanalog_ac_int.c SNIPPET_AC_INT_MAIN_SECTION
*
* \defgroup group_autanalog_ac_macros Macros
* \defgroup group_autanalog_ac_functions Functions
* \defgroup group_autanalog_ac_data_structures Data Structures
* \defgroup group_autanalog_ac_enums Enumerated Types
*/

#if !defined(CY_AUTANALOG_AC_H)
#define CY_AUTANALOG_AC_H

#include "cy_autanalog_common.h"

#ifdef CY_IP_MXS22LPPASS

#include "cy_syspm.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_autanalog_ac_macros
* \{
*/

/** The maximum number of states in the State Transition Table (STT),
 *  for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_STATE_TRANSITION_TABLE_STATES_NUM           (64U)

/** The maximum number of Loop/Interval counters that can be used by the AC,
 *  for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_TC_NUM                                      (4U)

/** The maximum number of output triggers for the AC,
 *  for more details, refer to the device Architecture Technical Reference Manual.
 */
#define CY_AUTANALOG_TRIG_OUT_NUM                                (8U)

/** \cond INTERNAL */

/* Validation macro for State Transition Table register of AC */
#define AUTANALOG_STT_AC_CFG0_DOUT(value)                        ((value) <= ACTRLR_TTCFG_TT_CFG0_DOUT_Msk)

/* The SysPm callback structure */
extern cy_stc_syspm_callback_t deepSleepCallback;

/** \endcond */

/** \} group_autanalog_ac_macros */

/***************************************
*       Enumerated Types
***************************************/

/**
* \addtogroup group_autanalog_ac_enums
* \{
*/

/** The AC operation status, see \ref cy_stc_autanalog_state_ac_t::status,
 *  for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_AC_STATUS_STOPPED = 0UL, /**< The AC is idle */
    CY_AUTANALOG_AC_STATUS_RUNNING = 1UL, /**< The AC is running */
    CY_AUTANALOG_AC_STATUS_PAUSED  = 2UL, /**< The AC is paused */

} cy_en_autanalog_ac_status_t;


/**
* The set of masks to control the four GPIO outputs with the AC, see \ref cy_stc_autanalog_ac_t::gpioOutEn,
* for more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_STT_AC_GPIO_OUT_DISABLED = 0x0UL, /**< Control of the GPIO outs is disabled */
    CY_AUTANALOG_STT_AC_GPIO_OUT0         = 0x1UL, /**< The GPIO out0 */
    CY_AUTANALOG_STT_AC_GPIO_OUT1         = 0x2UL, /**< The GPIO out1 */
    CY_AUTANALOG_STT_AC_GPIO_OUT2         = 0x4UL, /**< The GPIO out2 */
    CY_AUTANALOG_STT_AC_GPIO_OUT3         = 0x8UL, /**< The GPIO out3 */

} cy_en_autanalog_stt_ac_gpio_out_t;


/**
* The set of ACTIONS for the AC to change the STT state,
* for more details, refer to the device Architecture Technical Reference Manual,
* \ref group_autanalog_ac_stt chapter and \ref cy_stc_autanalog_stt_ac_t::condition field in the AC STT.
*/
typedef enum
{
    CY_AUTANALOG_STT_AC_ACTION_STOP                = 0UL,  /**< Stop the AC */
    CY_AUTANALOG_STT_AC_ACTION_NEXT                = 1UL,  /**< Proceed to the next state in the STT */
    CY_AUTANALOG_STT_AC_ACTION_WAIT_FOR            = 2UL,  /**< Wait (indefinitely) for the associated CONDITION
                                                            *   to be TRUE before moving to the next state,
                                                            *   see \ref cy_stc_autanalog_stt_ac_t::condition */
    CY_AUTANALOG_STT_AC_ACTION_BRANCH_IF_TRUE      = 3UL,  /**< Check if CONDITION has occurred
                                                            *   If it occurred, take the indicated branch
                                                            *   \ref cy_stc_autanalog_stt_ac_t::branchState,
                                                            *   if not, proceed to the next state */
    CY_AUTANALOG_STT_AC_ACTION_BRANCH_IF_FALSE     = 4UL,  /**< Check if CONDITION has occurred
                                                            *   If it occurred, proceed to the next state,
                                                            *   if not, take the indicated branch
                                                            *   \ref cy_stc_autanalog_stt_ac_t::branchState
                                                            *   \note When programming the AC to jump back to a particular state,
                                                            *   it is recommended to use ACTION = BRANCH_IF_TRUE, CONDITION = TRUE.
                                                            *   Avoid using ACTION = BRANCH_IF_FALSE, CONDITION = FALSE,
                                                            *   as it could may cause unexpected issues. */
    CY_AUTANALOG_STT_AC_ACTION_BRANCH_IF_TRUE_CLR  = 5UL,  /**< Check if CONDITION has occurred
                                                            *   If it occurred, take the indicated branch
                                                            *   \ref cy_stc_autanalog_stt_ac_t::branchState,
                                                            *   if not, proceed to the next state
                                                            *   \note If the indicated branch is taken,
                                                            *   all loop counters are cleared (reset).
                                                            *   \note If the CONDITION is set to CNT_DONE,
                                                            *   (\ref cy_en_autanalog_stt_ac_condition_t)
                                                            *   then the loop counters are not cleared (reset). */
    CY_AUTANALOG_STT_AC_ACTION_BRANCH_IF_FALSE_CLR = 6UL,  /**< Check if CONDITION has occurred
                                                            *   If it occurred proceed to the next state,
                                                            *   if not, take the indicated branch.
                                                            *   \note If the indicated branch is taken,
                                                            *   all loop counters are cleared (reset).
                                                            *   \note If the CONDITION is set to CNT_DONE,
                                                            *   (\ref cy_en_autanalog_stt_ac_condition_t)
                                                            *   then the loop counters are not cleared (reset).
                                                            *   \note When programming the AC to jump back to a particular state,
                                                            *   it is recommended to use ACTION = BRANCH_IF_TRUE_CLR, CONDITION = TRUE.
                                                            *   Avoid using ACTION = BRANCH_IF_FALSE_CLR, CONDITION = FALSE,
                                                            *   as it could may cause unexpected issues. */
} cy_en_autanalog_stt_ac_action_t;


/**
* The set of CONDITIONS (events) for the AC to change the STT state,
* for more details, refer to the device Architecture Technical Reference Manual,
* \ref group_autanalog_ac_stt chapter and \ref cy_stc_autanalog_stt_ac_t::condition field in the AC STT.
*/
typedef enum
{
    CY_AUTANALOG_STT_AC_CONDITION_FALSE                = 0UL,  /**< Unconditionally FALSE */
    CY_AUTANALOG_STT_AC_CONDITION_TRUE                 = 1UL,  /**< Unconditionally TRUE */
    CY_AUTANALOG_STT_AC_CONDITION_BLOCK_READY          = 2UL,  /**< Enabled subsystems of the Autonomous Analog
                                                                *   are initialized and ready for use */
    CY_AUTANALOG_STT_AC_CONDITION_CNT_DONE             = 3UL,  /**< Run-out for an interval timer
                                                                *   if the ACTION is WAIT_FOR,
                                                                *   or run-out for a loop counter,
                                                                *   if the ACTION is BRANCH IF
                                                                *   (\ref cy_en_autanalog_stt_ac_action_t) */
    CY_AUTANALOG_STT_AC_CONDITION_SAR_DONE             = 4UL,  /**< SAR Sequencer DONE.
                                                                *   This status is sticky.
                                                                *   It is set by the SAR when finishing a state
                                                                *   in the SAR sequencer table (HS/LP) where NEXT_STATE
                                                                *   cy_stc_autanalog_sar_seq_tab_hs_t::nextAction or
                                                                *   cy_stc_autanalog_sar_seq_tab_lp_t::nextAction
                                                                *   is set to STOP.
                                                                *   Do not use this field if the SAR is configured
                                                                *   for CONTINUOUS operation
                                                                *   (i.e. NEXT_STATE is set to GO_TO_ENTRY_ADDRESS,
                                                                *   see \ref cy_en_autanalog_sar_next_act_t).\n
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACTION is set to
                                                                *      WAIT_FOR or BRANCH_IF_* and CONDITION is set to SAR_DONE.
                                                                *   2. Executing an AC state where ACTION is set to WAIT_FOR
                                                                *      and CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   5. Disabling the SAR, see
                                                                *       \ref cy_stc_autanalog_stt_sar_t::enable
                                                                *   \note No overflow indication is provided for this bit.
                                                                *   Therefore, it is up to the user to program the AC
                                                                *   to read this status before an overflow occurs
                                                                *   (multiple SAR_DONEs).\n
                                                                *   \note This status does NOT indicate that the SAR data
                                                                *   has been written to the FIFO (indicated by SAR_FIFO_DONE). */
    CY_AUTANALOG_STT_AC_CONDITION_SAR_EOS              = 5UL,  /**< SAR End of Scan (EOS).
                                                                *   This status is sticky.
                                                                *   It is set by the SAR when finishing the state
                                                                *   in the SAR sequencer table (HS/LP) NEXT_STATE
                                                                *   cy_stc_autanalog_sar_seq_tab_hs_t::nextAction or
                                                                *   cy_stc_autanalog_sar_seq_tab_lp_t::nextAction
                                                                *   is set to GO_TO_ENTRY_ADDRESS or STOP,
                                                                *   see \ref cy_en_autanalog_sar_next_act_t.
                                                                *   The status is cleared by the AC when executing an AC state
                                                                *   with the CONDITION programmed to SAR_EOS.\n
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACT is set to WAIT_FOR or
                                                                *      BRANCH_IF_* and COND is set to SAR_EOS.
                                                                *   2. Executing an AC state where ACT is set to WAIT_FOR and
                                                                *      CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   5. Disabling the SAR, see
                                                                *      \ref cy_stc_autanalog_stt_sar_t::enable
                                                                *   \note No overflow indication is provided for this bit.
                                                                *   Therefore, it is up to the user to program the AC
                                                                *   to read this status before an overflow occurs
                                                                *   (multiple SAR_EOSs). */
    CY_AUTANALOG_STT_AC_CONDITION_SAR_RANGE0           = 6UL,  /**< SAR Range 0 detection.
                                                                *   This status is sticky.
                                                                *   It is set by the SAR if the RANGE0 condition is met
                                                                *   for a given channel with range 0 status enabled:
                                                                *   cy_stc_autanalog_sar_mux_chan_t::muxLimit
                                                                *   is equal to CY_AUTANALOG_SAR_LIMIT_STATUS_STC0 for LP/HS modes
                                                                *   OR cy_stc_autanalog_sar_hs_chan_t::hsLimit
                                                                *   is equal to CY_AUTANALOG_SAR_LIMIT_STATUS_STC0 for HS mode.\n
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACTION is set to
                                                                *      WAIT_FOR or BRANCH_IF_* and CONDITION is set to SAR_RANGE0.
                                                                *   2. Executing an AC state where ACTION is set to WAIT_FOR
                                                                *      and CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   5. Disabling the SAR, see
                                                                *      \ref cy_stc_autanalog_stt_sar_t::enable
                                                                *   \note No overflow indication is provided for this bit.
                                                                *   Therefore, it is up to the user to program the AC
                                                                *   to read this status before an overflow occurs
                                                                *   (multiple SAR_RANGE0s). */
    CY_AUTANALOG_STT_AC_CONDITION_SAR_RANGE1           = 7UL,  /**< SAR Range 1 detection. It is similar to range 0 detection. */
    CY_AUTANALOG_STT_AC_CONDITION_SAR_RANGE2           = 8UL,  /**< SAR Range 2 detection. It is similar to range 0 detection. */
    CY_AUTANALOG_STT_AC_CONDITION_SAR_RANGE3           = 9UL,  /**< SAR Range 3 detection. It is similar to range 0 detection. */
    CY_AUTANALOG_STT_AC_CONDITION_SAR_BUSY             = 10UL, /**< SAR BUSY detection.
                                                                *   This status is set whenever the SAR is running a scan.
                                                                *   This status is transparent from the SAR sequencer
                                                                *   (i.e. the status is not sticky). */
    CY_AUTANALOG_STT_AC_CONDITION_SAR_FIR0_DONE        = 11UL, /**< SAR FIR0 done detection.
                                                                *   This status is sticky.
                                                                *   It is set by the SAR FIR0 block whenever FIR0
                                                                *   produces a valid output.\n
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACTION is set to WAIT_FOR or
                                                                *      BRANCH_IF_* and CONDITION is set to SAR_FIR0_DONE.
                                                                *   2. Executing an AC state where ACTION is set to WAIT_FOR and
                                                                *      CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   5. Disabling the SAR, see
                                                                *      \ref cy_stc_autanalog_stt_sar_t::enable
                                                                *   \note No overflow indication is provided for this bit.
                                                                *   Therefore, it is up to the user to program the AC
                                                                *   to read this status before an overflow occurs
                                                                *   (multiple SAR_FIR0_DONEs).
                                                                *   \note This status does NOT indicate that the FIR0 data has been
                                                                *   written to the FIFO (indicated by SAR_FIR0_FIFO_DONE).*/
    CY_AUTANALOG_STT_AC_CONDITION_SAR_FIR1_DONE        = 12UL, /**< SAR FIR1 done detection. It is similar to FIR0 done detection. */
    CY_AUTANALOG_STT_AC_CONDITION_SAR_FIFO_DONE        = 13UL, /**< SAR FIFO done.
                                                                *   This status is SAR_DONE ANDED with FIFO writing complete.
                                                                *   Do not use this field if the SAR is configured for
                                                                *   for CONTINUOUS operation
                                                                *   (i.e. NEXT_STATE is set to GO_TO_ENTRY_ADDRESS,
                                                                *   see \ref cy_en_autanalog_sar_next_act_t)
                                                                *   since SAR_DONE is never asserted.
                                                                *   In that case, use the appropriate
                                                                *   FIFO_LEVEL triggers.\n
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACTION is set to WAIT_FOR or
                                                                *      BRANCH_IF_* and CONDITION is set to SAR_FIFO_DONE.
                                                                *   2. Executing an AC state where ACTION is set to WAIT_FOR and
                                                                *      CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   5. Disabling the SAR, see
                                                                *      \ref cy_stc_autanalog_stt_sar_t::enable
                                                                *   \note No overflow indication is provided for this bit.
                                                                *   Therefore, it is up to the user to program the AC
                                                                *   to read this status before an overflow occurs
                                                                *   (multiple SAR_FIFO_DONEs).
                                                                *   \note This status does NOT indicate that the SAR data has been
                                                                *   written to the FIFO (indicated by SAR_FIFO_DONE). */
    CY_AUTANALOG_STT_AC_CONDITION_SAR_FIR0_FIFO_DONE   = 14UL, /**< SAR FIR0 FIFO done detection.
                                                                *   This status is sticky.
                                                                *   It is set by the SAR FIR0 block whenever FIR0 data has been
                                                                *   written into the FIFO. When using this bit, it is expected that
                                                                *   FIR0 writes to the FIFO only once in a given SAR scan.\n
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACTION is set to WAIT_FOR or
                                                                *      BRANCH_IF_* and CONDITION is set to SAR_FIR0_FIFO_DONE.
                                                                *   2. Executing an AC state where ACTION is set to WAIT_FOR and
                                                                *      CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   5. Disabling the SAR, see
                                                                *      \ref cy_stc_autanalog_stt_sar_t::enable
                                                                *   \note No overflow indication is provided for this bit.
                                                                *   Therefore, it is up to the user to program the AC
                                                                *   to read this status before an overflow occurs
                                                                *   (multiple SAR_FIR0_FIFO_DONEs). */
    CY_AUTANALOG_STT_AC_CONDITION_SAR_FIR1_FIFO_DONE   = 15UL, /**< SAR FIR1 FIFO done detection. It is similar to
                                                                *   SAR FIR0 FIFO done detection. */
    CY_AUTANALOG_STT_AC_CONDITION_PTCOMP_STROBE0       = 16UL, /**< PTComp Post Processor 0 Strobe.
                                                                *   This status is set whenever the PTComp Post Processor 0
                                                                *   has valid data. This status is transparent from the PTComp
                                                                *   post processor (i.e. the status is not sticky).
                                                                *   The AC needs to poll this status
                                                                *   (i.e. ACTION is WAIT_FOR and CONDITION is PTCOMP_STROBE0)
                                                                *   prior to checking PTC_RANGE0. */
    CY_AUTANALOG_STT_AC_CONDITION_PTCOMP_STROBE1       = 17UL, /**< PTComp Post Processor 1 Strobe.
                                                                    It is similar to PTComp Post Processor 0 Strobe. */
    CY_AUTANALOG_STT_AC_CONDITION_PTCOMP_CMP0          = 18UL, /**< PTComp COMP0 output.
                                                                *   This status is sticky.
                                                                *   It is set by the PTComp Comparator 0 if the condition is met.
                                                                *   (\ref Cy_AutAnalog_PTComp_Read).
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACTION is set to WAIT_FOR or
                                                                *      BRANCH_IF_* and CONDITION is set to PTCOMP_CMP0.
                                                                *   2. Executing an AC state where ACT is set to WAIT_FOR and
                                                                *      CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   5.  Disabling PTComp comparator 0
                                                                *       (by clearing cy_stc_autanalog_stt_ptcomp_t::enableComp0)
                                                                *   \note No overflow indication is provided for this bit.
                                                                *   Therefore, it is up to the user to program the AC
                                                                *   to read this status before an overflow occurs
                                                                *   (multiple PTC_CMP0s). */
    CY_AUTANALOG_STT_AC_CONDITION_PTCOMP_CMP1          = 19UL, /**< PTComp COMP1 output. It is similar to PTComp COMP1 output. */
    CY_AUTANALOG_STT_AC_CONDITION_PTCOMP_RANGE0        = 20UL, /**< PTComp Post Processor 0 Range output.
                                                                *   This status is sticky.
                                                                *   It is set by the PTComp Post Processor if the RANGE0 condition
                                                                *   is met (\ref cy_stc_autanalog_ptcomp_comp_pp_t::limitCondition).
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACTION is set to WAIT_FOR or
                                                                *      BRANCH_IF_* and CONDITION is set to PTCOMP_RANGE0.
                                                                *   2. Executing an AC state where ACTION is set to WAIT_FOR and
                                                                *      CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   5. Disabling both PTComp comparators (by clearing
                                                                *      cy_stc_autanalog_stt_ptcomp_t::enableComp0 and
                                                                *      cy_stc_autanalog_stt_ptcomp_t::enableComp1)
                                                                *   \note No overflow indication is provided for this bit.
                                                                *   Therefore, it is up to the user to program the AC
                                                                *   to read this status before an overflow occurs
                                                                *   (multiple PTCOMP_RANGE0s). */
    CY_AUTANALOG_STT_AC_CONDITION_PTCOMP_RANGE1        = 21UL, /**< PTComp Post Processor 1 Range output. It is similar to
                                                                    PTComp Post Processor 0 Range output. */
    CY_AUTANALOG_STT_AC_CONDITION_CTB0_CMP0            = 22UL, /**< CTB0 COMP0 output.
                                                                *   This status is sticky.
                                                                *   It is set by the CTB0 Opamp0 Comparator if the condition is met
                                                                *   (\ref cy_stc_autanalog_ctb_sta_t::intComp0).\n
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACTION is set to WAIT_FOR or
                                                                *      BRANCH_IF_* and CONDITION is set to CTB0_CMP0.
                                                                *   2. Executing an AC state where ACTION is set to WAIT_FOR and
                                                                *      CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   5. Disabling CTB0 opamp0
                                                                *      (by clearing cy_stc_autanalog_stt_ctb_t::enableOpamp0)
                                                                *   \note No overflow indication is provided for this bit.
                                                                *   Therefore, it is up to the user to program the AC
                                                                *   to read this status before an overflow occurs
                                                                *   (multiple CTB0_CMP0s). */
    CY_AUTANALOG_STT_AC_CONDITION_CTB0_CMP1            = 23UL, /**< CTB0 COMP1 output. It is similar to CTB0 COMP0 output. */
    CY_AUTANALOG_STT_AC_CONDITION_CTB1_CMP0            = 24UL, /**< CTB1 COMP0 output. It is similar to CTB0 COMP0 output. */
    CY_AUTANALOG_STT_AC_CONDITION_CTB1_CMP1            = 25UL, /**< CTB1 COMP1 output. It is similar to CTB0 COMP0 output. */
    CY_AUTANALOG_STT_AC_CONDITION_CHIP_ACTIVE          = 32UL, /**< Chip Active Mode Status.
                                                                *   This status is set whenever the system is operating in
                                                                *   Active Mode (this includes all Low Power active modes)*/
    CY_AUTANALOG_STT_AC_CONDITION_CHIP_DEEPSLEEP       = 33UL, /**< Chip DeepSleep Mode Status.
                                                                *   This status is set whenever the system is operating in
                                                                *   DeepsSeep Mode (this includes all RAM power modes in DeepSleep) */
    CY_AUTANALOG_STT_AC_CONDITION_TR_AUTANALOG_IN0     = 34UL, /**< External trigger 0 (or the FW trigger 0).
                                                                *   This status is sticky.
                                                                *   It is set by the either the external hardware trigger 0 or
                                                                *   FW trigger 0 asserting.\n
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACTION is set to WAIT_FOR or
                                                                *      BRANCH_IF_* and CONDITION is set to TR_AUTANALOG_IN0.
                                                                *   2. Executing an AC state where ACTION is set to WAIT_FOR and
                                                                *      CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   \note No overflow indication is provided for this bit.
                                                                *    Therefore, it is up to the user to program the AC
                                                                *    to read this status before an overflow occurs
                                                                *    (multiple TR_LPPASS_IN0s). */
    CY_AUTANALOG_STT_AC_CONDITION_TR_AUTANALOG_IN1     = 35UL, /**< External trigger 1 (or the FW trigger 1).
                                                                *   It is similar to External trigger 0. */
    CY_AUTANALOG_STT_AC_CONDITION_TR_AUTANALOG_IN2     = 36UL, /**< External trigger 2 (or the FW trigger 2).
                                                                *   It is similar to External trigger 0. */
    CY_AUTANALOG_STT_AC_CONDITION_TR_AUTANALOG_IN3     = 37UL, /**< External trigger 3 (or the FW trigger 3).
                                                                *   It is similar to External trigger 0. */
    CY_AUTANALOG_STT_AC_CONDITION_TR_AUTANALOG_IN_WAKE = 38UL, /**< External Trigger Wake-up Source.
                                                                *   This condition is used to put the AC to sleep.
                                                                *   \note When using this condition,
                                                                *   the ACTION must be set to WAIT_FOR.
                                                                *   The AC will wake up when any external trigger
                                                                *   [0-3] is asserted.
                                                                *   \note When the AC is sleeping,
                                                                *   all registered AC conditions are cleared. */
    CY_AUTANALOG_STT_AC_CONDITION_TIMER_DONE_WAKE      = 39UL, /**< Timer Wakeup Source.
                                                                *   This condition is used to put the AC to sleep.
                                                                *   The AC will wake from sleep when the Wake-up Timer
                                                                *   reaches terminal count (\ref cy_stc_autanalog_state_t::tc).
                                                                *   \note When using this condition,
                                                                *   the ACTION must be set to WAIT_FOR.
                                                                *   The Wake-up Timer must also be configured
                                                                *   (\ref cy_stc_autanalog_ac_t::timer).
                                                                *   \note When the AC is sleeping, all registered AC conditions
                                                                *   are cleared. */
    CY_AUTANALOG_STT_AC_CONDITION_CTB0_CMP0_WAKE       = 40UL, /**< CTB0 comparator 0 wake-up.
                                                                *   This condition is used to put the AC to sleep.
                                                                *   The AC will wake up when CTB0 Comparator 0
                                                                *   meets the configured wake-up condition.
                                                                *   \note When using this condition, the ACTION must be set to
                                                                *   WAIT_FOR. The comparator wake-up condition is configured
                                                                *   per \ref cy_stc_autanalog_ctb_sta_t::intComp0.
                                                                *   The CTB0 comparator 0 must be enabled during sleep
                                                                *   (\ref cy_stc_autanalog_stt_ctb_t::enableOpamp0).
                                                                *   \note When the AC is sleeping, all registered AC conditions
                                                                *   are cleared. */
    CY_AUTANALOG_STT_AC_CONDITION_CTB0_CMP1_WAKE       = 41UL, /**< CTB0 comparator 1 wake-up.
                                                                *   It is similar to CTB0 comparator 0 wake-up. */
    CY_AUTANALOG_STT_AC_CONDITION_CTB1_CMP0_WAKE       = 42UL, /**< CTB1 comparator 0 wake-up.
                                                                *   It is similar to CTB0 comparator 0 wake-up. */
    CY_AUTANALOG_STT_AC_CONDITION_CTB1_CMP1_WAKE       = 43UL, /**< CTB1 comparator 1 wake-up.
                                                                *   It is similar to CTB0 comparator 0 wake-up. */
    CY_AUTANALOG_STT_AC_CONDITION_PTCOMP_CMP0_WAKE     = 44UL, /**< PTComp comparator 0 wake-up.
                                                                *   This condition is used to put the AC to sleep.
                                                                *   The AC will wake up when PTComp Comparator 0
                                                                *   meets the configured wake-up condition.
                                                                *   \note When using this condition, the ACTION must be set to
                                                                *   WAIT_FOR. The comparator wake-up condition is configured
                                                                *   per \ref cy_stc_autanalog_ptcomp_comp_sta_t::compEdgeComp0.
                                                                *   The PTC comparator 0 be enabled during aa sleep
                                                                *   (\ref cy_stc_autanalog_stt_ptcomp_t::enableComp0).
                                                                *   \note When the AC is sleeping, all registered AC conditions
                                                                *   are cleared. */
    CY_AUTANALOG_STT_AC_CONDITION_PTCOMP_CMP1_WAKE     = 45UL, /**< PTComp comparator 1 wake-up.
                                                                *   It is similar to PTComp comparator 0 wake-up. */
    CY_AUTANALOG_STT_AC_CONDITION_FIFO_LEVEL0          = 46UL, /**< FIFO Level 0 trigger.
                                                                *   This status is transparent from the FIFO
                                                                *   (i.e. the status is not sticky).
                                                                *   This status is set whenever FIFO0 level condition has been met
                                                                *   (\ref cy_stc_autanalog_fifo_cfg_t::level). */
    CY_AUTANALOG_STT_AC_CONDITION_FIFO_LEVEL1          = 47UL, /**< FIFO Level 1 trigger.
                                                                *   It is similar to FIFO Level 0 trigger.
                                                                *   \note This status requires that
                                                                *   corresponding buffers be enabled and configured. */
    CY_AUTANALOG_STT_AC_CONDITION_FIFO_LEVEL2          = 48UL, /**< FIFO Level 2 trigger.
                                                                *   It is similar to FIFO Level 0 trigger.
                                                                *   \note This status requires that
                                                                *   corresponding buffers be enabled and configured. */
    CY_AUTANALOG_STT_AC_CONDITION_FIFO_LEVEL3          = 49UL, /**< FIFO Level 3 trigger.
                                                                *   It is similar to FIFO Level 0 trigger.
                                                                *   \note This status requires that
                                                                *   corresponding buffers be enabled and configured. */
    CY_AUTANALOG_STT_AC_CONDITION_FIFO_LEVEL4          = 50UL, /**< FIFO Level 4 trigger.
                                                                *   It is similar to FIFO Level 0 trigger.
                                                                *   \note This status requires that
                                                                *   corresponding buffers be enabled and configured. */
    CY_AUTANALOG_STT_AC_CONDITION_FIFO_LEVEL5          = 51UL, /**< FIFO Level 5 trigger.
                                                                *   It is similar to FIFO Level 0 trigger.
                                                                *   \note This status requires that
                                                                *   corresponding buffers be enabled and configured. */
    CY_AUTANALOG_STT_AC_CONDITION_FIFO_LEVEL6          = 52UL, /**< FIFO Level 6 trigger.
                                                                *   It is similar to FIFO Level 0 trigger.
                                                                *   \note This status requires that
                                                                *   corresponding buffers be enabled and configured. */
    CY_AUTANALOG_STT_AC_CONDITION_FIFO_LEVEL7          = 53UL, /**< FIFO Level 7 trigger.
                                                                *   It is similar to FIFO Level 0 trigger.
                                                                *   \note This status requires that
                                                                *   corresponding buffers be enabled and configured. */
    CY_AUTANALOG_STT_AC_CONDITION_DAC0_RANGE0          = 54UL, /**< DAC0 Range 0 detection.
                                                                *   This status is sticky.
                                                                *   It is set by the DAC0 if the RANGE0 condition is met
                                                                *   for a given channel with range 0 status enabled
                                                                *   (i.e. \ref cy_stc_autanalog_dac_ch_t::statSel).
                                                                *   This status is not used when DAC0 is configured for FW mode.\n
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACTION is set to
                                                                *      WAIT_FOR or BRANCH_IF_* and CONDITION is set to DAC0_RANGE0.
                                                                *   2. Executing an AC state where ACTION is set to WAIT_FOR and
                                                                *      CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   5.  Disabling the DAC0
                                                                *       (by clearing \ref cy_stc_autanalog_stt_dac_t::enable).
                                                                *   \note No overflow indication is provided for this bit.
                                                                *   Therefore, it is up to the user to program the AC
                                                                *   to read this status before an overflow occurs
                                                                *   (multiple DAC0_RANGE0s). */
    CY_AUTANALOG_STT_AC_CONDITION_DAC0_RANGE1          = 55UL, /**< DAC0 Range 1 detection.
                                                                *   It is similar to DAC0 Range 0 detection */
    CY_AUTANALOG_STT_AC_CONDITION_DAC0_RANGE2          = 56UL, /**< DAC0 Range 2 detection.
                                                                *   It is similar to DAC0 Range 0 detection */
    CY_AUTANALOG_STT_AC_CONDITION_DAC0_EPOCH           = 57UL, /**< DAC0 End of Waveform event.
                                                                *   This status is sticky.
                                                                *   It is set by the DAC when finishing a waveform.
                                                                *   This condition is only used if the DAC channel
                                                                *   (pointed to by the AC when triggered)
                                                                *   is configured for LUT mode.\n
                                                                *   The status is cleared by the AC when any of the following occur:
                                                                *   1. Executing an AC state where ACTION is set to WAIT_FOR or
                                                                *      BRANCH_IF_* and CONDITION is set to DAC0_EPOCH.
                                                                *   2  Executing an AC state where ACTION is set to WAIT_FOR and
                                                                *      CONDITION is set to any of the *_WAKE.
                                                                *   3. Pausing the AC, see
                                                                *      \ref Cy_AutAnalog_PauseAutonomousControl or
                                                                *      \ref Cy_AutAnalog_SingleStepAutonomousControl
                                                                *   4. Disabling the AC, see
                                                                *      \ref Cy_AutAnalog_Disable
                                                                *   5. Disabling the DAC
                                                                *   (by clearing cy_stc_autanalog_stt_dac_t::enable)
                                                                *   \note No overflow indication is provided for this bit.
                                                                *   Therefore, it is up to the user to program the AC
                                                                *   to read this status before an overflow occurs
                                                                *   (multiple DAC0_EPOCHs). */
    CY_AUTANALOG_STT_AC_CONDITION_DAC0_STROBE          = 58UL, /**< DAC0 Strobe.
                                                                *   This status is transparent from the DAC
                                                                *   (i.e. the status is not sticky).
                                                                *   This status is set whenever the DAC output has been updated.
                                                                *   This status is typically used by the AC to poll when the DAC
                                                                *   has responded to the DAC_INC/DAC_DEC fields.\n
                                                                *   \note The AC needs to poll this status
                                                                *   (i.e. ACTION is WAIT_FOR and CONDITION is DAC0_STROBE)
                                                                *   prior to checking DAC_RANGE0 - DAC_RANGE2
                                                                *   or setting DAC_INC/DAC_DEC fields. */
    CY_AUTANALOG_STT_AC_CONDITION_DAC1_RANGE0          = 59UL, /**< DAC1 Range 0 detection.
                                                                *   It is similar to DAC0 Range 0 detection. */
    CY_AUTANALOG_STT_AC_CONDITION_DAC1_RANGE1          = 60UL, /**< DAC1 Range 1 detection.
                                                                *   It is similar to DAC0 Range 1 detection. */
    CY_AUTANALOG_STT_AC_CONDITION_DAC1_RANGE2          = 61UL, /**< DAC1 Range 2 detection.
                                                                *   It is similar to DAC0 Range 2 detection. */
    CY_AUTANALOG_STT_AC_CONDITION_DAC1_EPOCH           = 62UL, /**< DAC1 End of Waveform event.
                                                                *   It is similar to DAC0 End of Waveform event. */
    CY_AUTANALOG_STT_AC_CONDITION_DAC1_STROBE          = 63UL, /**< DAC1 Strobe.
                                                                *   It is similar to DAC0 Strobe. */
} cy_en_autanalog_stt_ac_condition_t;


/** The AC FW input triggers, \ref Cy_AutAnalog_FwTrigger,
 *  for more details, refer to the device Architecture Technical Reference Manual.
 */
typedef enum
{
    CY_AUTANALOG_FW_TRIGGER0 = 0UL, /**< FW trigger 0 */
    CY_AUTANALOG_FW_TRIGGER1 = 1UL, /**< FW trigger 1 */
    CY_AUTANALOG_FW_TRIGGER2 = 2UL, /**< FW trigger 2 */
    CY_AUTANALOG_FW_TRIGGER3 = 3UL, /**< FW trigger 3 */

} cy_en_autanalog_fw_trigger_t;


/**
* The AC output triggers, \ref Cy_AutAnalog_GetOutputTriggerMask and \ref Cy_AutAnalog_SetOutputTriggerMask,
* for more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_AC_OUT_TRIGGER0 = 0UL, /**< Output trigger 0 */
    CY_AUTANALOG_AC_OUT_TRIGGER1 = 1UL, /**< Output trigger 1 */
    CY_AUTANALOG_AC_OUT_TRIGGER2 = 2UL, /**< Output trigger 2 */
    CY_AUTANALOG_AC_OUT_TRIGGER3 = 3UL, /**< Output trigger 3 */
    CY_AUTANALOG_AC_OUT_TRIGGER4 = 4UL, /**< Output trigger 4 */
    CY_AUTANALOG_AC_OUT_TRIGGER5 = 5UL, /**< Output trigger 5 */
    CY_AUTANALOG_AC_OUT_TRIGGER6 = 6UL, /**< Output trigger 6 */
    CY_AUTANALOG_AC_OUT_TRIGGER7 = 7UL, /**< Output trigger 7 */

} cy_en_autanalog_ac_out_trigger_idx_t;


/**
* The set of masks to control the AC output trigger, see \ref cy_stc_autanalog_ac_t::mask and
* \ref Cy_AutAnalog_GetOutputTriggerMask, \ref Cy_AutAnalog_SetOutputTriggerMask.
* For more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY         =       0UL,        /**< The output trigger is disabled */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_CTB0_COMP0    =       1UL << 0U,  /**< The CTB0, Comp0 trigger.
                                                                     *   It is generated by the CTB0 Opamp0 Comparator
                                                                     *   if the condition is met
                                                                     *   (i.e. \ref cy_stc_autanalog_ctb_sta_t::intComp0)*/
    CY_AUTANALOG_AC_OUT_TRIG_MASK_CTB0_COMP1    =       1UL << 1U,  /**< The CTB0, Comp1 trigger.
                                                                     *   It is generated by the CTB0 Opamp1 Comparator
                                                                     *   if the condition is met
                                                                     *   (i.e. \ref cy_stc_autanalog_ctb_sta_t::intComp1)*/
    CY_AUTANALOG_AC_OUT_TRIG_MASK_CTB1_COMP0    =       1UL << 2U,  /**< The CTB1, Comp0 trigger.
                                                                     *   It is similar to CTB0, Comp0 trigger. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_CTB1_COMP1    =       1UL << 3U,  /**< The CTB1, Comp1 trigger.
                                                                     *   It is similar to CTB1, Comp1 trigger. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_PTCOMP_CMP0   =       1UL << 4U,  /**< The PTComp Comp0 trigger.
                                                                     *   It is set by the PTComp Comparator 0
                                                                     *   if the condition is met
                                                                     *   (cy_stc_autanalog_ptcomp_comp_sta_t::compEdgeComp0).*/
    CY_AUTANALOG_AC_OUT_TRIG_MASK_PTCOMP_CMP1   =       1UL << 5U,  /**< The PTComp Comp1 trigger.
                                                                     *   It is similar to PTComp Comp0 trigger. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_PTCOMP_RANGE0 =       1UL << 6U,  /**< The PTComp Post Processor 0 Range trigger
                                                                     *   It is generated by the PTComp Post Processor
                                                                     *   if the RANGE0 condition is met
                                                                     *   (\ref cy_stc_autanalog_ptcomp_comp_pp_t::limitCondition) */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_PTCOMP_RANGE1 =       1UL << 7U,  /**< The PTComp Post Processor 1 Range trigger.
                                                                     *   It is similar to PTComp Post Processor 0 Range trigger. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_DAC0_RANGE0   =       1UL << 8U,  /**< The DAC0 Range 0 trigger.
                                                                     *   It is generated by the DAC0 if the RANGE0
                                                                     *   condition is met for a given channel
                                                                     *   with range 0 status enabled
                                                                     *   (\ref cy_stc_autanalog_dac_ch_t::statSel).
                                                                     *   \note The interrupt is disabled when DAC0 is configured
                                                                     *   for FW mode. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_DAC0_RANGE1   =       1UL << 9U,  /**< The DAC0 Range 1 trigger.
                                                                     *   It is similar to DAC0 Range 0 trigger. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_DAC0_RANGE2   =       1UL << 10U, /**< The DAC0 Range 2 trigger.
                                                                     *   It is similar to DAC0 Range 0 trigger. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_DAC0_EPOCH    =       1UL << 11U, /**< The DAC0 End of Waveform trigger.
                                                                     *   It is generated by DAC0 when finishing a waveform.
                                                                     *   This condition is only used if the DAC0 channel
                                                                     *   (pointed to by the AC when triggered)
                                                                     *   is configured for LUT mode. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_DAC1_RANGE0   =       1UL << 13U, /**< The DAC1 Range 0 trigger.
                                                                     *   It is similar to DAC0 Range 0 trigger. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_DAC1_RANGE1   =       1UL << 14U, /**< The DAC1 Range 1 trigger.
                                                                     *   It is similar to DAC0 Range 1 trigger. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_DAC1_RANGE2   =       1UL << 15U, /**< The DAC1 Range 2 trigger.
                                                                     *   It is similar to DAC0 Range 2 trigger. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_DAC1_EPOCH    =       1UL << 16U, /**< The DAC1 End of Waveform trigger.
                                                                     *   It is similar to DAC0 End of Waveform trigger. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_FIFO_LEVEL0   =       1UL << 17U, /**< The FIFO Level 0 trigger.
                                                                     *   This is a level-sensitive trigger
                                                                     *   that is generated by the FIFO
                                                                     *   whenever FIFO 0 meets the condition
                                                                     *   cy_stc_autanalog_fifo_cfg_t::level */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_SAR_DONE      =       1UL << 18U, /**< The SAR Sequencer Done trigger.
                                                                     *   This trigger is set by the SAR when finishing a state
                                                                     *   in the SAR sequencer table (HS or LP) where
                                                                     *   \ref cy_stc_autanalog_sar_seq_tab_hs_t::nextAction or
                                                                     *   \ref cy_stc_autanalog_sar_seq_tab_lp_t::nextAction
                                                                     *   is set to STOP.
                                                                     *   \note The interrupt is not generated if the SAR
                                                                     *   is configured for CONTINUOUS operation
                                                                     *   (i.e. \ref cy_stc_autanalog_sar_seq_tab_hs_t::nextAction
                                                                     *   or \ref cy_stc_autanalog_sar_seq_tab_lp_t::nextAction
                                                                     *   is set to GO_TO_ENTRY_ADDRESS).
                                                                     *   This trigger does NOT indicate that the SAR data
                                                                     *   has been written to the FIFO
                                                                     *   (use the FIFO level triggers instead). */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_SAR_EOS       =       1UL << 19U, /**< The SAR Sequencer EOS trigger.
                                                                     *   This trigger is set by the SAR when finishing
                                                                     *   the state in the SAR sequencer table (HS or LP) where
                                                                     *   \ref cy_stc_autanalog_sar_seq_tab_hs_t::nextAction or
                                                                     *   \ref cy_stc_autanalog_sar_seq_tab_lp_t::nextAction
                                                                     *   is set to GO_TO_ENTRY_ADDRESS or STOP.
                                                                     *   \note This trigger does NOT indicate that the SAR data
                                                                     *   has been written to the FIFO
                                                                     *   (use the FIFO level triggers instead). */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_FIFO_LEVEL1   =       1UL << 20U, /**< The FIFO Level 1 trigger.
                                                                     *   It is similar to FIFO Level 0 trigger.
                                                                     *   \note This trigger is only generated if the FIFO
                                                                     *   is configured for multiple FIFOs
                                                                     *   (cy_stc_autanalog_fifo_cfg_t::split
                                                                     *   is not equal to CY_AUTANALOG_FIFO_SPLIT1). */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_SAR_RANGE0    =       1UL << 21U, /**< The SAR, range 0 */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_SAR_RANGE1    =       1UL << 22U, /**< The SAR, range 1 */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_SAR_RANGE2    =       1UL << 23U, /**< The SAR, range 2 */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_SAR_RANGE3    =       1UL << 24U, /**< The SAR, range 3 */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_FIFO_LEVEL2   =       1UL << 25U, /**< The FIFO Level 2 trigger.
                                                                     *   It is similar to FIFO Level 0 trigger.
                                                                     *   \note This trigger is only generated if the FIFO
                                                                     *   is configured for multiple FIFOs. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_FIFO_LEVEL3   =       1UL << 26U, /**< The FIFO Level 3 trigger.
                                                                     *   It is similar to FIFO Level 0 trigger.
                                                                     *   \note This trigger is only generated if the FIFO
                                                                     *   is configured for multiple FIFOs. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_FIFO_LEVEL4   =       1UL << 27U, /**< The FIFO Level 4 trigger.
                                                                     *   It is similar to FIFO Level 0 trigger.
                                                                     *   \note This trigger is only generated if the FIFO
                                                                     *   is configured for multiple FIFOs. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_FIFO_LEVEL5   =       1UL << 28U, /**< The FIFO Level 5 trigger.
                                                                     *   It is similar to FIFO Level 0 trigger.
                                                                     *   \note This trigger is only generated if the FIFO
                                                                     *   is configured for multiple FIFOs. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_FIFO_LEVEL6   =       1UL << 29U, /**< The FIFO Level 6 trigger.
                                                                     *   It is similar to FIFO Level 0 trigger.
                                                                     *   \note This trigger is only generated if the FIFO
                                                                     *   is configured for multiple FIFOs. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_FIFO_LEVEL7   =       1UL << 30U, /**< The FIFO Level 7 trigger.
                                                                     *   It is similar to FIFO Level 0 trigger.
                                                                     *   \note This trigger is only generated if the FIFO
                                                                     *   is configured for multiple FIFOs. */
    CY_AUTANALOG_AC_OUT_TRIG_MASK_AC            = ((int32_t)(1UL << 31U)), /**< The AC trigger.
                                                                     *   This trigger is set by the AC
                                                                     *   whenever executing a state with
                                                                     *   cy_stc_autanalog_stt_ac_t::trigInt = true. */
} cy_en_autanalog_ac_out_trigger_mask_t;


/**
* The AC clock source for wake-up Timer, see \ref cy_stc_autanalog_timer_t::clkSrc,
* for more details, refer to the device Architecture Technical Reference Manual.
*/
typedef enum
{
    CY_AUTANALOG_TIMER_CLK_LP = 0UL, /**< The Timer clocked from CLK_LPOSC (nominally 4.096MHz) */
    CY_AUTANALOG_TIMER_CLK_LF = 1UL, /**< The Timer clocked from CLK_LF (nominally 32kHz) */

} cy_en_autanalog_timer_clk_src_t;

/** \} group_autanalog_ac_enums */

/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_autanalog_ac_data_structures
* \{
*/

/**
 * The AC wake-up Timer configuration structure.
 * Used in cy_stc_autanalog_ac_t.
 */
typedef struct
{
    bool                            enable;  /**< Enable the wake-up Timer
                                              * - FALSE - Disabled;
                                              * - TRUE - Enabled;
                                              *
                                              *   This Timer (down counter) is used by the AC as a wake-up source
                                              *   (ACTION is WAIT_FOR and CONDITION is TIMER_DONE_WAKE).
                                              *   \note Even if enabled, it is held in Reset until the AC is running
                                              *   (\ref cy_stc_autanalog_state_ac_t::status).
                                              *   \note The Timer automatically resets whenever the AC transitions between
                                              *   HS and LP modes, is paused, or disabled.
                                              *   \note The Timer will generate a wake-up signal to the AC
                                              *   whenever it reaches Terminal Count (0) */
    cy_en_autanalog_timer_clk_src_t clkSrc;  /**< The AC Timer clock source */
    uint16_t                        period;  /**< The Timer period in clocks,
                                              *   actual timer period is PER_VAL + 1 (1 to 65536) */
} cy_stc_autanalog_timer_t;


/**
 * The AC configuration structure.
 * Used in \ref Cy_AutAnalog_AC_LoadConfig.
 */
typedef struct
{
    cy_en_autanalog_stt_ac_gpio_out_t       gpioOutEn;                       /**< Control four GPIO outputs with the AC, see also
                                                                              *   \ref cy_stc_autanalog_stt_ac_t::unlockGpioOut.
                                                                              *   \note Set the bits in this field
                                                                              *   prior to writing to
                                                                              *   \ref cy_stc_autanalog_stt_ac_t::gpioOut */
    cy_en_autanalog_ac_out_trigger_mask_t * mask[CY_AUTANALOG_TRIG_OUT_NUM]; /**< Control the AC output triggers */
    cy_stc_autanalog_timer_t                timer;                           /**< The AC wake-up Timer */

} cy_stc_autanalog_ac_t;


/**
 * The AC state configuration structure.
 * Used in \ref cy_stc_autanalog_state_t.
 */
typedef struct
{
    cy_en_autanalog_ac_status_t status; /**< Current status of the AC */
    uint8_t                     state;  /**< Current state of the AC in the STT.
                                         *   This field indicates where which AC State (0-63) the AC will execute instructions
                                         *   from when it receives a RUN or SINGLE_STEP command. Hardware updates this field
                                         *   whenever the AC transitions from RUNNING to STOPPED or PAUSED.
                                         *   When STOPPED or PAUSED, firmware can overwrite this field to force the AC
                                         *   to execute from a specific STATE when triggered by a subsequent RUN or SINGLE_STEP
                                         *   command.
                                         *   \note This field must never be written to if cy_stc_autanalog_state_ac_t::status
                                         *   is equal to CY_AUTANALOG_AC_STATUS_RUNNING.
                                         *   \note This register is reset whenever the following occurs:
                                         *    1. The AC is disabled (\ref Cy_AutAnalog_Disable)
                                         *    2. The Autonomous Analog is configured for HS mode
                                         *       (\ref cy_stc_autanalog_state_t::lpModeEnabled)
                                         *    and the chip leaves an Active Mode. */
} cy_stc_autanalog_state_ac_t;


/**
 * The AC Loop/Interval counter state configuration structure.
 * Used in \ref cy_stc_autanalog_state_t.
 */
typedef struct
{
    uint16_t                val;   /**< The current value of the Loop/Interval counter */
    uint8_t                 state; /**< The current STT state tied to this Loop/Interval counter (valid numbers are 0-63) */
    bool                    busy;  /**< The current Loop/Interval counter busy status (i.e. count value is non-zero) */

} cy_stc_autanalog_state_tc_t;


/**
 * The Autonomous Analog state.
 * Used in \ref Cy_AutAnalog_GetControllerState */
typedef struct
{
    bool                        lpModeEnabled;           /**< Current operational mode of the Autonomous Analog
                                                          *   - FALSE - HS mode;
                                                          *   - TRUE - LP mode;
                                                          *
                                                          *   \note In HS mode, the Autonomous Analog is functional only in
                                                          *   chip Active modes. The Autonomous Analog is clocked from a
                                                          *   peripheral source derived from CLK_HF,
                                                          *   \ref group_autanalog_section_configuration;
                                                          *
                                                          *   \note In LP mode, the Autonomous Analog is functional in both
                                                          *   chip Active and DeepSleep modes. The Autonomous Analog is clocked from
                                                          *   the internal LPOSC.
                                                          *
                                                          *   \note The Autonomous Analog always resets to HS mode.
                                                          *
                                                          *   \note This field is reset whenever the following occurs:
                                                          *   1. The AC is disabled (\ref Cy_AutAnalog_Disable)
                                                          *   2. The Autonomous Analog is configured for HS mode
                                                          *      (cy_stc_autanalog_state_t::lpModeEnabled is false)
                                                          *      and the chip leaves an Active Mode */
    cy_stc_autanalog_state_ac_t ac;                      /**< Current operational state of the AC */
    cy_stc_autanalog_state_tc_t tc[CY_AUTANALOG_TC_NUM]; /**< Current operational state of the Loop/Interval counters,
                                                          *   \note Four Loop/Interval counters or up to 3 loop counters
                                                          *   and 1 interval counter are available for the AC */
} cy_stc_autanalog_state_t;


/** The AC section in the State Transition Table state.
 * Used in \ref cy_stc_autanalog_stt_t.
 * For more details, refer to the device Architecture Technical Reference Manual.
 * \warning Program \ref cy_stc_autanalog_stt_ac_t::unlock and \ref cy_stc_autanalog_stt_ac_t::lpMode
 * only in one AC state when switching between modes and NOT in every AC state!
 */
typedef struct
{
    bool                               unlock;        /**< AC mode unlock:
                                                       *  - FALSE - Locked:\n
                                                       *    the AC operating mode
                                                       *    will NOT be taken into account in
                                                       *    the corresponding state of STT
                                                       *  - TRUE - Unlocked:\n
                                                       *    the AC operating mode
                                                       *    will be used in the STT corresponding state
                                                       */
    bool                               lpMode;        /**< The operational mode of the Autonomous Analog
                                                       *  - FALSE - HS mode;
                                                       *  - TRUE - LP mode;
                                                       *
                                                       *    \note In HS mode, the AC is clocked from CLK_HF
                                                       *    directly (nominally 80MHz) and functions only in chip Active mode
                                                       *    (i.e. the IP is reset in chip DeepSleep and Hibernate).
                                                       *
                                                       *    \note In LP mode, the AC is clocked from CLK_LPOSC
                                                       *    (4.096MHz) and functions only in chip Active and Deep Sleep mode
                                                       *    (i.e. the IP is only reset in Hibernate). */
    cy_en_autanalog_stt_ac_condition_t condition;     /**< The AC CONDITION in the corresponding state of the STT */
    cy_en_autanalog_stt_ac_action_t    action;        /**< The AC ACTION in the corresponding state of the STT */
    uint8_t                            branchState;   /**< The AC branch state depends on cy_stc_autanalog_stt_ac_t::condition.
                                                       *   The range is 0 to 63
                                                       *   \note This field in only used if the AC ACTION is set to BRANCH_IF_*
                                                       *   and the CONDITION is met. */
    bool                               trigInt;       /**< AC Interrupt Set.
                                                       *   This field is used for setting the AC Interrupt and/or trigger.
                                                       *   When set in a particular state, the AC generates a single cycle pulse
                                                       *   to the interrupt logic. The AC interrupt or AC trigger must be unmasked
                                                       *   for this field to generate an interrupt/trigger.
                                                       *   \note If ACTION is WAIT_FOR, the single cycle pulse is generated after
                                                       *   the CONDITION occurs, otherwise the single cycle pulse is sent
                                                       *   immediately upon entering the state where the field is set. */
    uint16_t                           count;         /**< This field is used to set the value for both interval
                                                       *   and loop counts. The actual count is CNT + 1. Therefore, the range is
                                                       *   1 to 4096. The value of 1 is degenerate.
                                                       *   \note This field is only valid if the ACTION is set to WAIT_FOR or
                                                       *   BRANCH_IF_* and the CONDITION is set to CNT_DONE.
                                                       *   \note If ACTION is set to WAIT_FOR, the counter is first loaded with
                                                       *   CNT + 1 and is subsequently decremented every clock cycle
                                                       *   (clock set by cy_stc_autanalog_stt_ac_t::lpMode).
                                                       *   On terminal count, the CNT_DONE trigger is asserted.
                                                       *   \note If ACTION is set to BRANCH_IF_*, the counter is first checked if
                                                       *   it is busy (count value is non-zero). If busy, the counter is
                                                       *   decremented. If not busy, the counter is loaded with CNT + 1.
                                                       *   On terminal count, the CNT_DONE trigger is asserted. */
    bool                               unlockGpioOut; /**< Unlock the AC digital output:
                                                       *   - FALSE - Locked:\n
                                                       *     Data from field
                                                       *     cy_stc_autanalog_stt_ac_t::gpioOut
                                                       *     of this structure
                                                       *     is NOT taken into account in
                                                       *     the corresponding state of STT;
                                                       *   - TRUE - Unlocked:\n
                                                       *     Data from field
                                                       *     cy_stc_autanalog_stt_ac_t::gpioOut
                                                       *     of this structure
                                                       *     are used in the STT corresponding state;
                                                       */
    cy_en_autanalog_stt_ac_gpio_out_t  gpioOut;       /**< The Autonomous Analog data out generation
                                                       *   (the corresponding bit in cy_stc_autanalog_ac_t::gpioOutEn
                                                       *   must be set when using this field).
                                                       *   \note The data out bus is driven directly to the GPIO HSIO interface.
                                                       *   The HSIO interface must be programmed properly for the DOUT bus to be
                                                       *   observed on the GPIO pins. */
} cy_stc_autanalog_stt_ac_t;

/** \} group_autanalog_ac_data_structures */


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_autanalog_ac_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_AutAnalog_AC_LoadConfig
****************************************************************************//**
*
* Configures the AC per provided settings.
*
* \param acCfg
* Pointer to a structure containing configuration data for the AC,
* \ref cy_stc_autanalog_ac_t.
*
* \return
* Status of initialization, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_AC_LoadConfig(const cy_stc_autanalog_ac_t * acCfg);


/*******************************************************************************
* Function Name: Cy_AutAnalog_StartAutonomousControl
****************************************************************************//**
*
* Enables the AC for operation.
* \note This function is applicable while the AC is in STOPPED or PAUSED state.
* See \ref cy_stc_autanalog_state_ac_t for more details.
* By default, the AC starts running from State 0.
* The \ref Cy_AutAnalog_OverrideControllerState can be used to overwrite
* the STT current state.
* \note The AC will stop whenever the following occurs:
* 1. The AC is disabled (\ref Cy_AutAnalog_Disable);
* 2. The Autonomous Analog is configured for HS mode
* (cy_stc_autanalog_state_t::lpModeEnabled is false) and the chip leaves an Active Mode.
*
*******************************************************************************/
void Cy_AutAnalog_StartAutonomousControl(void);


/*******************************************************************************
* Function Name: Cy_AutAnalog_PauseAutonomousControl
****************************************************************************//**
*
* Pauses the AC during operation. The state in the STT does not change.
* \note This field is used for debug purposes only.
*
* The AC waits for the present state to complete before pausing.
* If the present state cannot complete (i.e. the ACTION and CONDITION are programmed improperly),
* the AC will not pause. Do not use this command when executing an AC sleep state
* (ACTION is set to WAIT_FOR and CONDITION is set to WAKE_*).
*
* When the AC is paused, all AC registered conditions are cleared.
* This command is ignored if AC is already PAUSED or STOPPED,
* \ref cy_stc_autanalog_state_t::ac.
*
* \return
* The current state in the State Transition Table.
*
*******************************************************************************/
uint8_t Cy_AutAnalog_PauseAutonomousControl(void);


/*******************************************************************************
* Function Name: Cy_AutAnalog_SingleStepAutonomousControl
****************************************************************************//**
*
* Executes the single-step in the STT.
* \note This field is used for debug purposes only.
*
* If the present state cannot complete (i.e. the ACTION and CONDITION are programmed improperly),
* the AC will not pause. Do not use this command when executing an AC sleep state
* (ACTION is set to WAIT_FOR and CONDITION is set to WAKE_*).
*
* When the AC is paused, all AC registered conditions are cleared.
* This command is ignored if AC is already PAUSED or STOPPED,
* \ref cy_stc_autanalog_state_t::ac.
*
*******************************************************************************/
void Cy_AutAnalog_SingleStepAutonomousControl(void);


/*******************************************************************************
* Function Name: Cy_AutAnalog_GetControllerState
****************************************************************************//**
*
* Provides the operating status of the AC.
*
* \warning If the AC state is RUNNING, the AHB cannot read or write the State Transition Table!
*
* \param ctrlState
* Pointer to a structure for receiving the current operating status.
*
* \return
* Status of execution, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
cy_en_autanalog_status_t Cy_AutAnalog_GetControllerState(cy_stc_autanalog_state_t * ctrlState);


/*******************************************************************************
* Function Name: Cy_AutAnalog_OverrideControllerState
****************************************************************************//**
*
* Override current state in the STT with new one.
*
* \note This command must never be executed when the AC state is RUNNING,
* \ref cy_stc_autanalog_state_t::ac.
*
* \param newState
* New state in the State Transition Table.
*
*******************************************************************************/
void Cy_AutAnalog_OverrideControllerState(uint8_t newState);


/*******************************************************************************
* Function Name: Cy_AutAnalog_RunControllerState
****************************************************************************//**
*
* Triggers the AC to override the current state and
* forces it to run from the STT new state.
*
* \note This command must never be executed when the AC state is RUNNING,
* \ref cy_stc_autanalog_state_t::ac.
*
* \param newState
* Jumping to the new state in the State Transition Table.
*
*******************************************************************************/
void Cy_AutAnalog_RunControllerState(uint8_t newState);


/*******************************************************************************
* Function Name: Cy_AutAnalog_IsBusy
****************************************************************************//**
*
* Check if the AC is currently executing (RUNNING or STOPPED/PAUSED).
*
* \return
* Operating status, returns FALSE if STOPPED or PAUSED and TRUE if RUNNING.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_AutAnalog_IsBusy(void)
{
    /* Get the AC status */
    return ((uint32_t)CY_AUTANALOG_AC_STATUS_RUNNING == _FLD2VAL(ACTRLR_STATUS_STATUS, AUTANALOG_AC_STATUS(ACTRLR_BASE)));
}


/*******************************************************************************
* Function Name: Cy_AutAnalog_SetOutputTriggerMask
****************************************************************************//**
*
* Configures which bits of the mask register generate a trigger output.
*
* \param trigIdx
* The AC trigger register to initialize the out trigger.
* See \ref cy_en_autanalog_ac_out_trigger_idx_t.
*
* \param mask
* The mask of triggers allowed to be activated.
* Each bit of this mask enables the corresponding out trigger in the AC.
* See \ref cy_en_autanalog_ac_out_trigger_mask_t.
*
*******************************************************************************/
void Cy_AutAnalog_SetOutputTriggerMask(cy_en_autanalog_ac_out_trigger_idx_t trigIdx, cy_en_autanalog_ac_out_trigger_mask_t mask);


/*******************************************************************************
* Function Name: Cy_AutAnalog_GetOutputTriggerMask
****************************************************************************//**
*
* Returns the AC out trigger mask.
* Each bit of this mask enables the corresponding out trigger in the AC.
*
* \param trigIdx
* The AC trigger register to initialize the out trigger.
* See \ref cy_en_autanalog_ac_out_trigger_idx_t.
*
* \return
* The mask of triggers allowed to be activated.
* Each bit of this mask enables the corresponding out trigger in the AC.
* See \ref cy_en_autanalog_ac_out_trigger_mask_t.
*
*******************************************************************************/
cy_en_autanalog_ac_out_trigger_mask_t Cy_AutAnalog_GetOutputTriggerMask(cy_en_autanalog_ac_out_trigger_idx_t trigIdx);


/*******************************************************************************
* Function Name: Cy_AutAnalog_FwTrigger
****************************************************************************//**
*
* Sends a firmware trigger to the AC.
*
* \note The AC can be programmed to respond to the firmware trigger
* by programming a state with a CONDITION TR_LPPASS_IN*.
* Additionally, this event will force the AC to wake up.
* Hardware clears this bit when the Autonomous Controller acknowledges the trigger.
* The firmware trigger is also reset whenever the following occurs:
* 1. The AC is disabled (\ref Cy_AutAnalog_Disable);
* 2. The Autonomous Analog is configured for HS mode
* (cy_stc_autanalog_state_t::lpModeEnabled is false)
* and the chip leaves Active mode.
*
* \param triggNum
* The AC trigger register to initialize the FW trigger.
* See \ref cy_en_autanalog_fw_trigger_t.
*
*******************************************************************************/
void Cy_AutAnalog_FwTrigger(cy_en_autanalog_fw_trigger_t triggNum);


/*******************************************************************************
* Function Name: Cy_AutAnalog_DeepSleepCallback
****************************************************************************//**
*
* Changes the FIFO mode to write only before entering into Deep Sleep mode
* and restores it to write/read upon wake-up.
*
* \note Changing the FIFO mode applies only to the AC in LP mode.
*
* \param callbackParams
* Callback parameters, see \ref cy_stc_syspm_callback_params_t
*
* \param mode
* Callback mode, see \ref cy_en_syspm_callback_mode_t
*
* \return
* \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t Cy_AutAnalog_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);

/** \} group_autanalog_ac_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22LPPASS */

#endif /** !defined(CY_AUTANALOG_AC_H) */

/** \} group_autanalog_ac */

/* [] END OF FILE */
