/***************************************************************************//**
* \file cy_syspm.h
* \version 5.180
*
* Provides the function definitions for the power management API.
*
********************************************************************************
* \copyright
* Copyright (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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
*
*******************************************************************************/

/**
* \addtogroup group_syspm
* \{
* \defgroup group_syspm_pdcm            PDCM (Power Dependency Control Matrix)
* \defgroup group_syspm_ppu             PPU (Power Policy Unit)
* \} */

/**
* \addtogroup group_syspm
* \{
*
* Use the System Power Management (SysPm) driver to change power modes and
* reduce system power consumption in power sensitive designs.
*
* The functions and other declarations used in this driver are in cy_syspm.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* For multi-CPU devices, this library allows you to individually enter low power
* modes for each CPU.
*
* This document contains the following topics:
*
* * \ref group_syspm_power_modes
* * \ref group_syspm_system_power_modes
*   - \ref group_syspm_switching_into_ulp
*     - \ref group_syspm_ulp_limitations
*   - \ref group_syspm_switching_into_lp
*     - \ref group_syspm_lp_limitations
*   - \ref group_syspm_switching_into_sleep
*   - \ref group_syspm_switching_into_lpactivelpsleep
*   - \ref group_syspm_switching_into_deepsleep
*   - \ref group_syspm_switching_into_deepsleep-ram
*   - \ref group_syspm_switching_into_deepsleep-off
*   - \ref group_syspm_wakingup_from_sleep_deepsleep
*   - \ref group_syspm_switching_into_hibernate
*   - \ref group_syspm_wakingup_from_hibernate
* * \ref group_syspm_system_active_state_transitions
*   - \ref group_syspm_system_ulp_to_lp_transition
*   - \ref group_syspm_system_lp_to_hp_transition
*   - \ref group_syspm_system_hp_to_lp_transition
*   - \ref group_syspm_system_lp_to_ulp_transition
*  - \ref group_syspm_system_transition_abs_levels
* * \ref group_syspm_system_reg_curr_mode
*   - \ref group_syspm_system_set_min_reg_curr_mode
*   - \ref group_syspm_system_set_normal_reg_curr_mode
* * \ref group_syspm_cb
*   - \ref group_syspm_cb_example
*   - \ref group_syspm_cb_config_consideration
*     - \ref group_syspm_cb_parameters
*     - \ref group_syspm_cb_structures
*     - \ref group_syspm_cb_function_implementation
*     - \ref group_syspm_cb_flow
*     - \ref group_syspm_cb_registering
*     - \ref group_syspm_cb_unregistering
* * \ref group_syspm_definitions
*
* \section group_syspm_section_configuration Configuration Considerations
* \subsection group_syspm_power_modes Power Modes
* This device adopts the <b>ARM Power Control Architecture</b>. It supports the following power modes:
*
* * <b>ACTIVE, SLEEP </b> - standard ARM defined power modes, supported by
*   the ARM CPUs and ISA.
* * <b>LPACTIVE/LPSLEEP</b> - are low power profiles implemented as register
*   configurations within ACTIVE/SLEEP modes.
* * <b>DEEPSLEEP </b> - a lower power mode where high-frequency clocks are
*   disabled.  Most register state is retained and the platform supports saving
*   a configurable amount of SRAM state.
* * <b>DEEPSLEEP-RAM </b> -  a lower mode than DEEPSLEEP that keeps DeepSleep
*   peripherals running, but on wakeup the CPU (and most peripherals) go
*   through a reset.  A configurable amount of system RAM is retained.
* * <b>DEEPSLEEP-OFF </b> -   similar to DEEPSLEEP-RAM but does not retain
*   system RAM.
* * <b>HIBERNATE </b> -   is an even lower power mode than DEEPSLEEP-OFF, but
*   on wakeup the CPU (and almost all peripherals) go through a full reset.
*   DeepSleep peripherals do not operate in HIBERNATE.
* * <b>XRES </b> - occurs when an external reset is applied, either XRES or
*   alternate XRES (AXRES).  It is also considered a power mode with a current
*   target spec.
* * <b>OFF </b> - state simply represents the state of the part with no power
*   applied to it.
*
* * SRSS implements an ARM Power Policy Unit (PPU) that provides the software
* interface to power mode control for VCCACT_PD.The PPU interacts with a
* Power Control State Machine (PSCM) that interfaces with the core SRSS
* to enter/exit DEEPSLEEP*.
* * SRSS implements a Power Dependency Control Matrix (PDCM) that allows hardware
* and software to specify dependencies between power domains.
*
*
* \subsection group_syspm_system_power_modes System Power Modes
* * <b>LP</b> - In this mode, code is executed and all logic and
*   memories are powered. Firmware may disable/reduce clocks for specific
*   peripherals and power down specific analog power domains.
*
* * <b>ULP</b> - This power mode is like LP mode, but
*   with clock restrictions and limited/slower peripherals to achieve lower
*   current consumption. Refer to \ref group_syspm_switching_into_ulp in
*   Configuration considerations.
*
* * <b>LPACTIVE/LPSLEEP</b> - low power profiles implemented as register
*   configurations within ACTIVE/SLEEP modes.Refer to
*   \ref group_syspm_switching_into_lpactivelpsleep in Configuration considerations.
*
* * <b>DEEPSLEEP</b> - Is a lower power mode where high-frequency clocks are
*   disabled. Refer to \ref group_syspm_switching_into_deepsleep in
*   Configuration considerations. Deep-sleep-capable peripherals are available.
*   A normal wakeup from Deep Sleep returns to either system LP or ULP mode,
*   depending on the previous state and programmed behavior for the configured
*   wakeup interrupt. Likewise, a debug wakes up from system Deep Sleep and
*   woken CPU returns to CPU Sleep. Refer
*   to \ref group_syspm_wakingup_from_sleep_deepsleep in Configuration
*   considerations.
*
* * <b>DEEPSLEEP-RAM</b> - a lower mode than DEEPSLEEP that keeps DeepSleep
*   peripherals running, but on wakeup the CPU (and most peripherals) go through
*   a reset. A configurable amount of system RAM is retained.Refer to
*   \ref group_syspm_switching_into_deepsleep-ram in Configuration considerations.
*   Refer to \ref group_syspm_wakingup_from_sleep_deepsleep in Configuration
*   considerations.
*
* * <b>DEEPSLEEP-OFF</b> -  similar to DEEPSLEEP-RAM but does not retain system RAM.
*   Refer to \ref group_syspm_switching_into_deepsleep-off in Configuration considerations.
*   Refer to \ref group_syspm_wakingup_from_sleep_deepsleep in Configuration
*   considerations.
*
* * <b>Hibernate</b> - Is the lowest power mode that is entered from
*   firmware. Refer to \ref group_syspm_switching_into_hibernate in
*   Configuration considerations. On wakeup the CPU(s) and all peripherals
*   go through a full reset. The I/O's state is frozen so that the
*   output driver state is held in system Hibernate. Note that in this mode,
*   the CPU(s) and all peripherals lose their states, so the system and firmware
*   reboot on a wakeup event. Backup memory (if present) can be used to store
*   limited system state for use on the next reboot. Refer to
*   \ref group_syspm_wakingup_from_hibernate in Configuration considerations.
*
* \warning * Above is list of all the System Power modes in general, a device
* support subset of the above System Power modes.Please refer to TRM for more information.
*
* \subsubsection group_syspm_switching_into_lp Switching the System into Low Power
* To set system LP mode you need to set LP voltage for the active core
* regulator:
* * If active core regulator is the LDO, call:
*   \code{.c}
*   Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_LP);
*   \endcode
* * If active core regulator is the Buck, call:
*   \code{.c}
*   Cy_SysPm_BuckSetVoltage1(CY_SYSPM_BUCK_OUT1_VOLTAGE_LP)
*   \endcode
*
* After switching into system LP mode, the operating frequency and current
* consumption may now be increased up to \ref group_syspm_lp_limitations.
* The wait states for flash may be changed to increase device performance by
* calling SysLib function Cy_SysLib_SetWaitStates(true, hfClkFreqMz), where
* hfClkFreqMz is the frequency of HfClk0 in MHz.
*
* \subsubsection group_syspm_lp_limitations LP Limitations
* When the system is in LP mode, the core regulator voltage is set to
* <b>1.1 V (nominal)</b> and the following limitations must be met:
*
*   - The maximum operating frequency for all Clk_HF paths must not exceed
*     <b>150 MHz*</b>, and peripheral and slow clock must
*     not exceed <b>100 MHz *</b>
*
*   - The total current consumption must be less than or equal to
*     <b>250 mA *</b>
*
* \warning * - Numbers shown are approximate and real limit values may be
* different because they are device specific. You should refer to the device
* datasheet for exact values of maximum frequency and current in system LP mode.
*
* \subsubsection group_syspm_switching_into_ulp Switching the System into Ultra Low Power
* Before switching into system ULP mode, ensure that the device meets
* \ref group_syspm_ulp_limitations. Decrease the clock frequencies,
* and slow or disable peripherals. Also ensure that appropriate wait state
* values are set for the flash. Flash wait states can be set by calling
* SysLib function Cy_SysLib_SetWaitStates(true, hfClkFreqMz), where hfClkFreqMz
* is the frequency of HfClk0 in MHz.
*
* After the \ref group_syspm_ulp_limitations are met and appropriate wait
* states are set, you must set ULP voltage for the active core regulator:
* * If active core regulator is the LDO Core Voltage Regulator, call
* Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_ULP)
* * If active core regulator is the Buck Core Voltage Regulator, then call
* Cy_SysPm_BuckSetVoltage1(CY_SYSPM_BUCK_OUT1_VOLTAGE_ULP)
*
* \subsubsection group_syspm_ulp_limitations ULP Limitations
* When the system is in ULP mode the core regulator voltage is set to <b>0.9 V
* (nominal)</b> and the following limitations must be meet:
*
*   - The maximum operating frequency for all Clk_HF paths must not exceed
*     <b>50 MHz *</b>, whereas the peripheral and slow clock must not exceed
*     <b>25 MHz *</b>.
*
*   - The total current consumption must be less than or equal
*     to <b>20 mA*</b>
*
*   - the flash write operations are prohibited. The flash works in the
*     Read-only operation. If Write operations are required, you must switch to
*     the system LP mode.
*
* \warning * - Numbers shown are approximate and real limit values may be
* different because they are device specific. You should refer to the device
* datasheet for exact values of maximum frequency and current in system
* ULP mode.
*
* \subsubsection group_syspm_switching_into_lpactivelpsleep Switching the System into LPACTIVE/LPSLEEP
* Call Cy_SysPm_SystemLpActiveEnter() to enter LPACTIVE/LPSLEEP mode and
* Cy_SysPm_SystemLpActiveExit() to exit.
*
* \subsubsection group_syspm_switching_into_sleep Switching CPU into Sleep
* For multi-CPU devices, the Cy_SysPm_CpuEnterSleep() switches only the CPU
* that calls the function into the CPU Sleep power mode.
*
* All pending interrupts must be cleared before the CPU is put into a
* Sleep mode, even if they are masked.
*
* The CPU event register can be set in the past, for example, as a result of
* internal system calls. So an old event can cause the CPU to not enter
* Sleep mode upon WFE(). Therefore usually the WFE() is used in an idle loop or
* polling loop as it might or might not cause entering of CPU Sleep mode. If
* the idle loop or polling loop is not used, then it is recommended to use
* WFI() instruction.
*
* \subsubsection group_syspm_switching_into_deepsleep Switching the System or CPU into Deep Sleep
* For multi-CPU devices, the Cy_SysPm_CpuEnterDeepSleep() function switches
* only the CPU that calls the function into the CPU Deep Sleep power mode.
* To set the whole system into Deep Sleep power mode, ensure that all CPUs call
* the Cy_SysPm_CpuEnterDeepSleep() function.
*
*
* \subsubsection group_syspm_switching_into_deepsleep-ram Switching the System or CPU into Deep Sleep-RAM
* For multi-CPU devices, the Cy_SysPm_CpuEnterDeepSleep() function switches
* only the CPU that calls the function into the CPU DEEPSLEEP-RAM power mode.
* To set the whole system into Deep Sleep power mode, ensure that all CPUs call
* the Cy_SysPm_CpuEnterDeepSleep() function.
*
*
* \subsubsection group_syspm_switching_into_deepsleep-off Switching the System or CPU into Deep Sleep-OFF
* For multi-CPU devices, the Cy_SysPm_CpuEnterDeepSleep() function switches
* only the CPU that calls the function into the CPU DEEPSLEEP-OFF power mode.
* To set the whole system into Deep Sleep power mode, ensure that all CPUs call
* the Cy_SysPm_CpuEnterDeepSleep() function.
*
*
* There are situations when the system does not switch into the Deep Sleep
* power mode immediately after the last CPU calls Cy_SysPm_CpuEnterDeepSleep().
* The system will switch into Deep Sleep mode automatically a short time later,
* after the low power circuits are ready to switch into Deep Sleep. Refer to
* the Cy_SysPm_CpuEnterDeepSleep() description for more detail.
*
* All pending interrupts must be cleared before the system is put into a
* Deep Sleep mode, even if they are masked.
*
* The CPU event register can be set in the past, for example, as a result of
* internal system calls. So an old event can cause the CPU to not enter Deep
* Sleep mode upon WFE(). Therefore usually the WFE() is used in an idle loop or
* polling loop as it might or might not cause entering of CPU Deep Sleep mode.
* If the idle loop or polling loop is not used, then it is recommended to use
* WFI() instruction.
*
* For single-CPU devices, SysPm functions that return the status of the
* unsupported CPU always return CY_SYSPM_STATUS_<CPU>_DEEPSLEEP.
*
* \subsubsection group_syspm_wakingup_from_sleep_deepsleep Waking Up from Sleep or Deep Sleep
* For Arm-based devices, an interrupt is required for the CPU to wake up.
* For multi-CPU devices, one CPU can wake up the other CPU by sending the
* event instruction. Use the Cy_SysPm_CpuSendWakeupEvent() function.
*
* \subsubsection group_syspm_switching_into_hibernate Switching System to Hibernate
* If you call Cy_SysPm_SystemEnterHibernate() from either CPU, the system will
* be switched into the Hibernate power mode directly, because there is no
* handshake between CPUs.
*
* \subsubsection group_syspm_wakingup_from_hibernate Waking Up from Hibernate
*
* The system can wake up from Hibernate mode by configuring the following wakeup
* sources:
* - Wakeup pin
* - LP Comparator
* - RTC alarm
* - WDT interrupt
*
* Wakeup is supported from device specific pin(s) with programmable polarity.
* Additionally, unregulated peripherals can wake the system under some
* conditions. For example, a low power comparator can wake the system by
* comparing two external voltages, but does not support comparison to an
* internally-generated voltage. The backup power domain remains functional, and
* if present it can schedule an alarm to wake the system from Hibernate using
* the RTC. Alternatively, the Watchdog Timer (WDT) can be configured to wake-up
* the system by WDT interrupt. Refer to \ref Cy_SysPm_SetHibernateWakeupSource()
* for more detail.
*
* \subsection group_syspm_system_active_state_transitions System Active state Transitions
*
* The system operates in three defined active modes, each tailored for specific
* performance and power requirements:
* - ULP (Ultra Low Power)
* - LP (Low Power)
* - HP (High Performance)
*
*
* Transitioning between these operational modes requires meticulous adherence to
* defined sequences to prevent timing-related issues.
* The application is responsible for managing system frequency during these transitions,
* ensuring it stays within the valid range for both current and target modes.
* The driver assumes all frequency requirements are met before mode transition
* APIs are called.
*
* \attention Transitions from ULP to HP modes (or vice versa) are only allowed in steps.
* These transitions must proceed via the intermediate LP mode
* (ULP -> LP -> HP or the reverse). This staged approach ensures system stability
* and reliable operations. These steps are handled internally by the driver
* when using one of the APIs: \ref Cy_SysPm_SystemEnterHp(),
* \ref Cy_SysPm_SystemEnterLp(), or \ref Cy_SysPm_SystemEnterUlp().
*
* The driver provides dedicated APIs for transitions:
* - \ref Cy_SysPm_SystemTransitionUlpToLp() - Transition from ULP to LP
* - \ref Cy_SysPm_SystemTransitionLpToHp() - Transition from LP to HP
* - \ref Cy_SysPm_SystemTransitionHpToLp() - Transition from HP to LP
* - \ref Cy_SysPm_SystemTransitionLpToUlp() - Transition from LP to ULP
*
* The following sections outline the required conditions and sequence of operations
* for each supported transition.
*
* \subsection group_syspm_system_ulp_to_lp_transition System ULP to LP Transition
*
* To transition the system from Ultra Low Power (ULP) to Low Power (LP) mode, follow
* these steps in the secure processing environment:
* -# Suspend Operations:
*    1. Initiate M0SECCPUSS suspension with ifx_se_disable().
* -# Reduce Operating Frequency:
*    2. Lower the \ref group_syspm_sram_transition_clock frequency by at least 18%.
* -# Initiate Transition:
*    3. Call \ref Cy_SysPm_SystemTransitionUlpToLp() to perform the mode change.
* -# Restore Frequency:
*    4. After the transition, the \ref group_syspm_sram_transition_clock frequency
*    can be increased up to the new mode's
*    maximum.
* -# Resume Operations:
*    5. Instruct M0SECCPUSS to resume operations by calling ifx_se_enable().
*
* \subsection group_syspm_system_lp_to_hp_transition System LP to HP Transition
*
* To transition the system from Low Power (LP) to High Power (HP) mode, follow
* these steps in the secure processing environment:
* -# Suspend Operations:
*    1. Initiate M0SECCPUSS suspension with ifx_se_disable().
* -# Reduce Operating Frequency:
*    2. Lower the \ref group_syspm_sram_transition_clock frequency by at least 38%.
* -# Initiate Transition:
*    3. Call \ref Cy_SysPm_SystemTransitionLpToHp() to perform the mode change.
* -# Restore Frequency:
*    4. After the transition, the \ref group_syspm_sram_transition_clock frequency
*    can be increased up to the new mode's maximum.
* -# Resume Operations:
*    5. Instruct M0SECCPUSS to resume operations by calling ifx_se_enable().
*
* \subsection group_syspm_system_hp_to_lp_transition System HP to LP Transition
*
* To transition the system from High Power (HP) to Low Power (LP) mode, follow
* these steps in the secure processing environment:
* -# Suspend Operations:
*    1. Initiate M0SECCPUSS suspension with ifx_se_disable().
* -# Reduce Operating Frequency:
*    2. Lower the \ref group_syspm_sram_transition_clock frequency by at least 82%.
* -# Initiate Transition:
*    3. Call \ref Cy_SysPm_SystemTransitionHpToLp() to perform the mode change.
* -# Restore Frequency:
*    4. After the transition, the \ref group_syspm_sram_transition_clock frequency
*    can be increased up to the new mode's maximum.
* -# Resume Operations:
*    5. Instruct M0SECCPUSS to resume operations by calling ifx_se_enable().
*
* \subsection group_syspm_system_lp_to_ulp_transition System LP to ULP Transition
*
* To transition the system from Low Power (LP) to Ultra Low Power (ULP) mode, follow
* these steps in the secure processing environment:
* -# Suspend Operations:
*    1. Initiate M0SECCPUSS suspension with ifx_se_disable().
* -# Reduce Operating Frequency:
*    2. Lower the \ref group_syspm_sram_transition_clock frequency by at least 66%.
* -# Initiate Transition:
*    3. Call \ref Cy_SysPm_SystemTransitionLpToUlp() to perform the mode change.
* -# Restore Frequency:
*    4. After the transition, the \ref group_syspm_sram_transition_clock frequency
*    can be increased up to the new mode's maximum.
* -# Resume Operations:
*    5. Instruct M0SECCPUSS to resume operations by calling ifx_se_enable().
*
* \subsection group_syspm_system_transition_abs_levels System Transitions
* (Levels of Abstraction)
*
* The driver supports two operational abstraction levels for system transitions:
* -# High Level - The application invokes a single API that manages the entire
* transition workflow internally. This method simplifies development, requiring minimum
* user intervention, but offers limited opportunity for customization or speed optimization.
* -# Low Level - The application remains responsible for all prerequisite checks and initiates
* each step of the transition sequence. This grants granular control, allowing adjustments for
* specialized use cases or the fastest possible transitions.
*
* \attention The application is responsible for invoking the correct steps at the appropriate
* stage of transition:
* - High Level Approach:
*   + Reduce operating frequency within the CY_SYSPM_BEFORE_TRANSITION callback.
*   + Use the relevant transition function: \ref Cy_SysPm_SystemEnterHp(),
*   \ref Cy_SysPm_SystemEnterLp(), or \ref Cy_SysPm_SystemEnterUlp().
*   + Restore operating frequency in the CY_SYSPM_AFTER_TRANSITION callback.
*
* - Low Level Approach:
*   + The application must carefully follow the outlined sequences described in
*   \ref group_syspm_system_active_state_transitions for the desired transition.
*
*
* \subsubsection group_syspm_sram_transition_clock SRAM Clock
* When the system is performing a power transition all the clocks used to access the SRAM
* must be adapted to the new power mode. The SRAM clock frequency must be reduced
* before the transition and can be increased after the transition is completed.
* \subsection group_syspm_system_reg_curr_mode System Regulator Current Mode
* In addition to system ULP and LP modes, the five different resource
* power settings can be configured to reduce current consumption:
* -# <b>Linear regulator low power mode</b>. Can be used only if core current
*    is below the LDO regulator LP threshold.
* -# <b>POR/BOD circuit low power mode</b>. Requires compatible power supply
*    stability due to stability increase response time.
* -# <b>Bandgap reference circuits low power mode</b> (turns on Deep Sleep
*    Bandgap). Requires design to accept reduced Vref accuracy. Active ref can
*    be turned off after this feature is enabled.
* -# <b>Reference buffer circuit low power mode</b>. Requires design to accept
*    reduced Vref accuracy.
* -# <b>Current reference circuit low power mode</b>. Require design to accept
*    reduced Iref accuracy.
*
* These five sub features can modify both system LP or ULP modes as they are
* independent from LP/ULP settings.
* When all five sub features are set to their low power modes, the system
* operates in regulator minimum current mode. In regulator minimum current mode,
* the system current consumption is limited to a device-specific value. Refer to
* the device datasheet for the exact current consumption value in regulator
* minimum current mode.
*
* When all five sub features are set to their normal mode, the system operates
* in regulator normal current mode. When regulator normal current mode is set,
* the system may operate at device maximum current.
*
* \subsection group_syspm_system_set_min_reg_curr_mode Setting Minimum System Regulator Current Mode
*
* Before setting the regulator minimum current mode ensure that current limits
* are be met. After current limits are met, call the
* Cy_SysPm_SystemSetMinRegulatorCurrent() function.
*
* \subsection group_syspm_system_set_normal_reg_curr_mode Setting Normal System Regulator Current Mode
*
* To set regulator normal current mode, call the
* Cy_SysPm_SystemSetNormalRegulatorCurrent() function. After the function call,
* the current limits can be increased to a maximum current, depending on what
* system power mode is set: LP or ULP.
*
* \subsection group_syspm_cb SysPm Callbacks
* The SysPm driver handles low power callbacks declared in the application.
*
* If there are no callbacks registered, the device executes the power mode
* transition. However, frequently your application firmware must make
* modifications for low power mode. For example, you may need to disable a
* peripheral, or ensure that a message is not being transmitted or received.
*
* To enable this, the SysPm driver implements a callback mechanism. When a lower
* power mode transition is about to take place (either entering or exiting
* \ref group_syspm_system_power_modes), the registered callbacks for that
* transition are called.
*
* The SysPm driver organizes all the callbacks into a linked list. While
* entering a low power mode, SysPm goes through that linked list from first to
* last, executing the callbacks one after another. While exiting low power mode,
* SysPm goes through that linked list again, but in the opposite direction from
* last to first. This ordering supports prioritization of callbacks relative to
* the transition event.
*
* For example, the picture below shows three callback structures organized into
* a linked list: myDeepSleep1, myDeepSleep2, myDeepSleep3 (represented with the
* \ref cy_stc_syspm_callback_t configuration structure). Each structure
* contains, among other fields, the address of the callback function. The code
* snippets below set this up so that myDeepSleep1 is called first when entering
* the low power mode. This also means that myDeepSleep1 will be the last one to
* execute when exiting the low power mode.
*
* The callback structures after registration:
* \image html syspm_register_eq.png
*
* Your application must register each callback, so that SysPm can execute it.
* Upon registration, the linked list is built by the SysPm driver. Notice
* the &myDeepSleep1 address in the myDeepSleep1
* \ref cy_stc_syspm_callback_t structure. This is filled in by the SysPm driver,
* when you register myDeepSleep1. The cy_stc_syspm_callback_t.order element
* defines the order of their execution by the SysPm driver.
* Call \ref Cy_SysPm_RegisterCallback() to register each callback function.
*
* A callback function is typically associated with a particular driver that
* handles the peripheral. So the callback mechanism enables a peripheral to
* prepare for a low power mode (for instance, shutting down the analog part);
* or to perform tasks while exiting a low power mode (like enabling the analog
* part again).
*
* With the callback mechanism you can prevent switching into a low power mode if
* a peripheral is not ready. For example, driver X is in the process of
* receiving a message. In the callback function implementation simply return
* CY_SYSPM_FAIL in a response to CY_SYSPM_CHECK_READY.
*
* If success is returned while executing a callback, the SysPm driver calls the
* next callback and so on to the end of the list. If at some point a callback
* returns CY_SYSPM_FAIL in response to the CY_SYSPM_CHECK_READY step, all the
* callbacks that have already executed are executed in reverse order, with the
* CY_SYSPM_CHECK_FAIL mode parameter. This allows each callback to know that
* entering the low power mode has failed. The callback can then undo whatever it
* did to prepare for low power mode, if required. For example, if the driver X
* callback shut down the analog part, it can re-enable the analog part.
*
* Let's switch to an example explaining the implementation, setup, and
* registration of three callbacks (myDeepSleep1, myDeepSleep2, myDeepSleep2) in
* the application. The \ref group_syspm_cb_config_consideration are provided
* after the \ref group_syspm_cb_example.
*
* \subsection group_syspm_cb_example SysPm Callbacks Example
*
* The following code snippets demonstrate how use the SysPm callbacks mechanism.
* We will build the prototype for an application that registers
* three callback functions:
*    -# myDeepSleep1 - Handles CPU Deep Sleep.
*    -# myDeepSleep2 - Handles CPU Deep Sleep and is associated with peripheral
*       HW1_address (see <a href="..\..\pdl_user_guide.pdf">PDL Design</a>
*       section to learn about the base hardware address).
*    -# myDeepSleep3 - Handles entering and exiting system Deep Sleep and is
*       associated with peripheral HW2_address.
*
* We set things up so that the myDeepSleep1 and myDeepSleep2 callbacks do
* nothing while entering the low power mode (skip on
* CY_SYSPM_SKIP_BEFORE_TRANSITION -
* see \ref group_syspm_cb_function_implementation in
* \ref group_syspm_cb_config_consideration).
* Skipping the actions while entering low power might be useful if you need
* to save time while switching low power modes. This is because the callback
* function with a skipped mode is not even called avoiding the call and return
* overhead.
*
* Let's first declare the callback functions. Each gets the pointer to the
* \ref cy_stc_syspm_callback_params_t structure as the argument.
*
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Func_Declaration
*
* Now we setup the \ref cy_stc_syspm_callback_params_t structures that we will
* pass to the callback functions. Note that for the myDeepSleep2 and
* myDeepSleep3 callbacks we also pass pointers to the peripherals related to
* that callback (see <a href="..\..\pdl_user_guide.pdf">PDL Design</a> section
* to learn about base hardware addresses).
* The configuration considerations related to this structure are described
* in \ref group_syspm_cb_parameters in \ref group_syspm_cb_config_consideration.
*
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Params_Declaration
*
* Now we setup the actual callback configuration structures. Each of these
* contains, among the other fields, the address of the
* \ref cy_stc_syspm_callback_params_t we just set up. We will use the callback
* configuration structures later in the code to register the callbacks in the
* SysPm driver. Again, we set things up so that the myDeepSleep1 and
* myDeepSleep2 callbacks do nothing while entering the low power mode
* (skip on CY_SYSPM_SKIP_BEFORE_TRANSITION) - see
* \ref group_syspm_cb_function_implementation in
* \ref group_syspm_cb_config_consideration.
*
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Structure_Declaration
*
* Note that in each case the last two fields are NULL. These are fields used by
* the SysPm driver to set up the linked list of callback functions.
*
* The callback structures are now defined and allocated in the user's
* memory space:
* \image html syspm_before_registration.png
*
* Now we implement the callback functions. See
* \ref group_syspm_cb_function_implementation in
* \ref group_syspm_cb_config_consideration for the instructions on how the
* callback functions should be implemented.
*
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Func_Implementation
*
* Finally, we register the callbacks so that the SysPm driver knows about them.
* The order in which the callbacks will be called depends upon the order in
* which the callbacks are registered. If there are no callbacks registered,
* the device just executes the power mode transition.
*
* Callbacks that reconfigure global resources, such as clock frequencies, should
* be registered last. They then modify global resources as the final step before
* entering the low power mode, and restore those resources first, as the system
* returns from low power mode.
*
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_RegisterCallback
*
* We are done configuring three callbacks. Now the SysPm driver will execute the
* callbacks appropriately whenever there is a call to a power mode transition
* function: \ref Cy_SysPm_CpuEnterSleep(), \ref Cy_SysPm_CpuEnterDeepSleep(),
* \ref Cy_SysPm_SystemEnterUlp(), \ref Cy_SysPm_SystemEnterLp(), and
* \ref Cy_SysPm_SystemEnterHibernate().
* \note On a wakeup from hibernate the device goes through a reset, so the
* callbacks with CY_SYSPM_AFTER_TRANSITION are not executed. Refer to
* \ref Cy_SysPm_SystemEnterHibernate() for more detail.
*
* Refer to \ref group_syspm_cb_unregistering in
* \ref group_syspm_cb_config_consideration to learn what to do if you need to
* remove the callback from the linked list. You might want to unregister the
* callback for debug purposes.
*
* Refer to \ref group_syspm_cb_flow in \ref group_syspm_cb_config_consideration
* to learn about how the SysPm processes the callbacks.
*
* \subsection group_syspm_cb_config_consideration Callback Configuration Considerations
*
* \subsubsection group_syspm_cb_parameters Callback Function Parameters
*
* The <b>callbackParams</b> parameter of the callback function is a
* \ref cy_stc_syspm_callback_params_t structure. The second parameter
* (<b>mode</b>) is for internal use. In the example code we used a
* dummy value CY_SYSPM_CHECK_READY to eliminate compilation errors associated
* with the enumeration. The driver sets the <b>mode</b> field to the correct
* value when calling the callback functions (the mode is referred to as step in
* the \ref group_syspm_cb_function_implementation). The callback function reads
* the value and executes code based on the mode set by the SysPm driver.
* The <b>base</b> and <b>context</b> fields are optional and can be NULL.
* Some drivers require a base hardware address and context to store information
* about the mode transition. If your callback routine requires access to the
* driver registers or context, provide those values
* (see <a href="..\..\pdl_user_guide.pdf">PDL Design</a> section
* to learn about Base Hardware Address). Be aware of MISRA warnings if these
* parameters are NULL.
*
* \subsubsection group_syspm_cb_structures Callback Function Structure
* For each callback, provide a \ref cy_stc_syspm_callback_t structure. Some
* fields in this structure are maintained by the driver. Use NULL for
* cy_stc_syspm_callback_t.prevItm and cy_stc_syspm_callback_t.nextItm.
* Driver uses these fields to build a linked list of callback functions.
* The value of cy_stc_syspm_callback_t.order element is used to define the order
* how the callbacks are put into linked list, and sequentially, how the
* callbacks are executed. See \ref group_syspm_cb_registering section.
*
* \warning The Cy_SysPm_RegisterCallback() function stores a pointer to the
* cy_stc_syspm_callback_t structure. Do not modify elements of the
* cy_stc_syspm_callback_t structure after the callback is registered.
* You are responsible for ensuring that the structure remains in scope.
* Typically the structure is declared as a global or static variable, or as a
* local variable in the main() function.
*
* \subsubsection group_syspm_cb_function_implementation Callback Function Implementation
*
* Every callback function should handle four possible steps (referred to as
* "mode") defined in \ref cy_en_syspm_callback_mode_t :
*    * CY_SYSPM_CHECK_READY - Check if ready to enter a power mode.
*    * CY_SYSPM_BEFORE_TRANSITION - The actions to be done before entering
*      the low power mode.
*    * CY_SYSPM_AFTER_TRANSITION - The actions to be done after exiting the
*      low power mode.
*    * CY_SYSPM_CHECK_FAIL - Roll back any actions performed in the callback
*      executed previously with CY_SYSPM_CHECK_READY.
*
* A callback function can skip steps (see \ref group_syspm_skip_callback_modes).
* In our example myDeepSleep1 and myDeepSleep2 callbacks do nothing while
* entering the low power mode (skip on CY_SYSPM_BEFORE_TRANSITION). If there is
* anything preventing low power mode entry - return CY_SYSPM_FAIL in response to
* CY_SYSPM_CHECK_READY in your callback implementation. Note that the callback
* should return CY_SYSPM_FAIL only in response to CY_SYSPM_CHECK_READY. The
* callback function should always return CY_SYSPM_PASS for other modes:
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* (see \ref group_syspm_cb_flow).
*
* \subsubsection group_syspm_cb_flow Callbacks Execution Flow
*
* This section explains what happens during a power transition, when callbacks
* are implemented and set up correctly. The following discussion assumes:
* * All required callback functions are defined and implemented
* * All cy_stc_syspm_callback_t structures are filled with required values
* * All callbacks are successfully registered
*
* User calls one of the power mode transition functions: \ref Cy_SysPm_CpuEnterSleep(),
* \ref Cy_SysPm_CpuEnterDeepSleep(), \ref Cy_SysPm_SystemEnterUlp(),
* \ref Cy_SysPm_SystemEnterLp(), or \ref Cy_SysPm_SystemEnterHibernate().
* It calls each callback with the mode set to CY_SYSPM_CHECK_READY. This
* triggers execution of the code for that mode inside of each user callback.
*
* The intent of CY_SYSPM_CHECK_READY is to only signal if the resources is ready
* to transition. Ideally, no transition changes should be made at this time.
* In some cases a small change may be required. For example a communication
* resource callback may set a flag telling firmware not to start any new
* transition.

* If that process is successful for all callbacks, then
* \ref Cy_SysPm_ExecuteCallback() calls each callback with the mode set to
* CY_SYSPM_BEFORE_TRANSITION. This triggers execution of the code for that mode
* inside each user callback. We then enter the low power mode after all callback
* are executed.
*
* When exiting the low power mode, the SysPm driver executes
* \ref Cy_SysPm_ExecuteCallback() again. This time it calls each callback in
* reverse order, with the mode set to CY_SYSPM_AFTER_TRANSITION. This triggers
* execution of the code for that mode inside each user callback. The final
* execution of callbacks depends on the low power mode in which callbacks were
* called:
* * For CPU Sleep or Deep Sleep power modes, the CY_SYSPM_AFTER_TRANSITION mode
*   is called after the CPU wakes from Sleep or Deep Sleep.
* * For system Hibernate, the CY_SYSPM_AFTER_TRANSITION mode is not executed
*   because the device reboots after the wakeup from the Hibernate.
* * For system LP and ULP modes, after the CY_SYSPM_AFTER_TRANSITION mode was
*   called the system remains in the new power mode: LP or ULP.
*
* A callback can return CY_SYSPM_FAIL only while executing the
* CY_SYSPM_CHECK_READY mode. If that happens, then the remaining callbacks are
* not executed. Any callbacks that have already executed are called again, in
* reverse order, with CY_SYSPM_CHECK_FAIL. This allows the system to return to
* the previous state. If a callback returns a fail then any of the functions
* (\ref Cy_SysPm_CpuEnterSleep(), \ref Cy_SysPm_CpuEnterDeepSleep(),
* \ref Cy_SysPm_SystemEnterUlp(), \ref Cy_SysPm_SystemEnterLp(), or
* \ref Cy_SysPm_SystemEnterHibernate()) that attempt to switch the device into
* a low power mode will also return CY_SYSPM_FAIL.
*
* Callbacks that reconfigure global resources, such as clock frequencies,
* should be registered last. They then modify global resources as the final
* step before entering the low power mode, and restore those resources first,
* as the system returns from low power mode.
*
* \subsubsection group_syspm_cb_registering Callback Registering
* While registration the callback is put into the linked list. The
* place where the callback structure is put into the linked list is based on
* cy_stc_syspm_callback_t.order. The callback with the lowest
* cy_stc_syspm_callback_t.order value will be placed at the beginning of linked
* list. The callback with the highest cy_stc_syspm_callback_t.order value will
* be placed at the end of the linked list.
* If there is already a callback structure in the linked list with the same
* cy_stc_syspm_callback_t.order value as you attend to register, then your
* callback will be placed right after such a callback.
*
* Such a registration order defines how the callbacks are executed:
* * Callbacks with the lower cy_stc_syspm_callback_t.order are executed first
* when entering into low power and last when exiting from low power.
* * Callbacks with the higher cy_stc_syspm_callback_t.order are executed last
* when entering into low power and first when exiting from low power.
*
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_RegisterCallback
*
* Callbacks with equal cy_stc_syspm_callback_t.order values are
* registered in the same order as they are registered:
* \image html syspm_register_eq.png

* Callbacks with a different cy_stc_syspm_callback_t.order value will be
* stored based on the cy_stc_syspm_callback_t.order value, with no matter when
* they when registered:
*
* \image html syspm_register_dif.png
*
* This can be useful to ensure that system resources (clock dividers, etc) are
* changed right before entering low power mode and immediately after exiting
* from low power.
*
* \subsubsection group_syspm_cb_unregistering Callback Unregistering
*
* Unregistering the callback might be useful when you need to dynamically manage
* the callbacks.
*
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_UnregisterCallback
* The callback structures after myDeepSleep2 callback is unregistered:
* \image html syspm_unregistration.png
*
* \section group_syspm_section_secure_aware Secure Aware SYSPM
* Some SYSPM APIs are marked as Secure Aware. This means that if the resource in SYSPM
* is marked as a secure region in the Peripheral Protection Controller (PPC) and these
* APIs are called from a non-secure CPU state, the PDL will submit a request to the
* Secure Request Framework (SRF) middleware to transition to a secure CPU state to
* perform the operation. From the application's perspective, the API will behave
* the same whether it is called from a secure or non-secure CPU state albeit slower.
*
* This functionality is automatically enabled on devices with ARM TrustZone processors.
* To disable, set the DEFINE+=CY_PDL_ENABLE_SECURE_AWARE_SYSPM=0 in the application
* Makefile.
*
* For more information on Secure Aware PDL behavior, see \ref group_pdl_srf_general.
*
* \section group_syspm_definitions Definitions
*
* <table class="doxtable">
*   <tr>
*     <th>Term</th>
*     <th>Definition</th>
*   </tr>
*
*   <tr>
*     <td>LDO</td>
*     <td>Low dropout linear regulator. The functions that manage this
*         block are grouped as \ref group_syspm_functions_ldo under
*         \ref group_syspm_functions_core_regulators</td>
*   </tr>
*
*   <tr>
*     <td>SIMO Buck</td>
*     <td>Single inductor multiple Output Buck regulator, referred as
*         "Buck regulator" throughout the documentation. The functions that
*         manage this block are grouped as \ref group_syspm_functions_buck under
*         \ref group_syspm_functions_core_regulators</td>
*   </tr>
*
*   <tr>
*     <td>SISO Buck</td>
*     <td>Single inductor single output Buck regulator, referred as
*         "Buck regulator" throughout the documentation. The functions that
*         manage this block are grouped as \ref group_syspm_functions_buck under
*         \ref group_syspm_functions_core_regulators</td>
*   </tr>

*   <tr>
*     <td>PMIC</td>
*     <td>Power management integrated circuit. The functions that manage this
*         block are grouped as \ref group_syspm_functions_pmic</td>
*   </tr>
*
*   <tr>
*     <td>LP</td>
*     <td>System low power mode. See the \ref group_syspm_switching_into_lp
*         section for details.</td>
*   </tr>
*
*   <tr>
*     <td>ULP</td>
*     <td>System ultra low power mode. See the
*         \ref group_syspm_switching_into_ulp section for details.</td>
*   </tr>
* </table>
*
* \section group_syspm_section_more_information More Information
* For more information on the SysPm driver,
* refer to the technical reference manual (TRM).
*
* \defgroup group_syspm_macros Macros
* \defgroup group_syspm_functions Functions
* \{
    \defgroup group_syspm_functions_general        General
*   \defgroup group_syspm_functions_power          Power Modes
*   \defgroup group_syspm_functions_power_status   Power Status
*   \defgroup group_syspm_functions_iofreeze       I/Os Freeze
*   \defgroup group_syspm_functions_core_regulators    Core Voltage Regulation
*   \{
*     \defgroup group_syspm_functions_ldo      LDO
*     \defgroup group_syspm_functions_buck     Buck
*   \}
*   \defgroup group_syspm_functions_callback   Low Power Callbacks
* \}
* \defgroup group_syspm_data_structures Data Structures
* \defgroup group_syspm_data_enumerates Enumerated Types
*/

#if !defined (CY_SYSPM_H)
#define CY_SYSPM_H

#include "cy_device.h"

#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)

#include <stdbool.h>
#include <stddef.h>

#include "cy_device_headers.h"
#include "cy_syslib.h"

#if ((CY_CPU_CORTEX_M4) && (defined (CY_DEVICE_SECURE)))
    #include "cy_pra.h"
#endif /* #if ((CY_CPU_CORTEX_M4) && (defined (CY_DEVICE_SECURE))) */

#include "cy_pdl_srf.h"
#include "cy_pdl_srf_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
*       Register Constants
*******************************************************************************/

/**
* \addtogroup group_syspm_macros
* \{
*/

/** Driver major version */
#define CY_SYSPM_DRV_VERSION_MAJOR       5

/** Driver minor version */
#define CY_SYSPM_DRV_VERSION_MINOR       190

/** SysPm driver identifier */
#define CY_SYSPM_ID                      (CY_PDL_DRV_ID(0x10U))


/*******************************************************************************
*       Internal Defines
*******************************************************************************/

/** \cond INTERNAL */

/* The internal define of the tries number in the
* CoreBuck and LDO status functions
*/
#define CY_SYSPM_CBUCK_BUSY_RETRY_COUNT         (100000U)
#define CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_US      (1U)

/* Macro to validate parameters in Cy_SysPm_SetHibernateWakeupSource() and for Cy_SysPm_ClearHibernateWakeupSource() function */
#define CY_SYSPM_IS_WAKE_UP_SOURCE_VALID(wakeupSource)   (0UL == ((wakeupSource) & \
                                                          ((uint32_t) ~(CY_SYSPM_HIB_WAKEUP_SOURCE_MASK))))


/* Macro to validate parameters in Cy_SysPm_ExecuteCallback() function */

#if defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

#define CY_SYSPM_IS_CALLBACK_TYPE_VALID(type)           (((type) == CY_SYSPM_SLEEP)         || \
                                                         ((type) == CY_SYSPM_DEEPSLEEP)     || \
                                                         ((type) == CY_SYSPM_DEEPSLEEP_RAM) || \
                                                         ((type) == CY_SYSPM_DEEPSLEEP_OFF) || \
                                                         ((type) == CY_SYSPM_LP) || \
                                                         ((type) == CY_SYSPM_ULP) || \
                                                         ((type) == CY_SYSPM_HP) || \
                                                         ((type) == CY_SYSPM_HIBERNATE))

/* Macro to validate parameters in Cy_SysPm_CoreBuckSetVoltage() & Cy_SysPm_CoreBuckConfig functions */
#define CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(voltage)    (((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_58V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_60V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_62V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_64V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_66V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_68V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_70V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_72V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_74V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_76V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_78V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_80V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_82V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_84V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_86V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_88V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_90V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_92V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_94V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_96V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_98V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_00V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_02V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_04V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_06V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_08V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_10V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_12V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_14V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_16V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_18V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_20V))

/* Macro to validate core buck profile in Cy_SysPm_CoreBuckSetProfile() function */
#define CY_SYSPM_IS_CORE_BUCK_PROFILE_VALID(mode)           (((mode) == CY_SYSPM_CORE_BUCK_PROFILE_HP)     || \
                                                             ((mode) == CY_SYSPM_CORE_BUCK_PROFILE_LP)     || \
                                                             ((mode) == CY_SYSPM_CORE_BUCK_PROFILE_SKIP)     || \
                                                             ((mode) == CY_SYSPM_CORE_BUCK_PROFILE_ULP))

/* Macro to validate parameters in Cy_SysPm_RetLdoConfigure() */
#define CY_SYSPM_IS_RETLDO_VOLTAGE_VALID(voltage)    (((voltage) <= CY_SYSPM_RETLDO_VOLTAGE_LVL_31))

/* Macro to validate parameters in Cy_SysPm_RetLdoConfigure() */
#define CY_SYSPM_IS_RETLDO_GAIN_VALID(voltage)    (((voltage) == CY_SYSPM_RETLDO_GAIN_2) || \
                                                         ((voltage) == CY_SYSPM_RETLDO_GAIN_2_47))

/* Macro to validate parameters in Cy_SysPm_SramLdoConfigure() */
#define CY_SYSPM_IS_SRAMLDO_VOLTAGE_VALID(voltage)    (((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_58V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_60V)  || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_62V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_64V)  || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_66V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_68V)  || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_70V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_72V)  || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_74V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_76V)  || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_78V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_80V)  || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_82V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_84V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_86V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_88V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_90V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_92V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_94V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_96V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_0_98V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_1_00V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_1_02V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_1_04V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_1_06V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_1_08V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_1_10V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_1_12V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_1_14V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_1_16V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_1_18V) || \
                                                         ((voltage) == CY_SYSPM_SRAMLDO_VOLTAGE_1_20V))

/* Macro to validate parameters in Cy_SysPm_MiscLdoConfigure() */
#define CY_SYSPM_IS_MISCLDO_VOLTAGE_VALID(voltage)    (((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_58V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_60V)  || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_62V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_64V)  || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_66V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_68V)  || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_70V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_72V)  || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_74V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_76V)  || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_78V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_80V)  || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_82V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_84V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_86V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_88V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_90V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_92V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_94V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_96V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_0_98V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_1_00V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_1_02V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_1_04V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_1_06V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_1_08V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_1_10V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_1_12V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_1_14V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_1_16V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_1_18V) || \
                                                         ((voltage) == CY_SYSPM_MISCLDO_VOLTAGE_1_20V))

/* Macro to validate parameters in Cy_SysPm_MiscLdoConfigure() */
#define CY_SYSPM_IS_MISCLDO_MODE_VALID(mode)    (((mode) == CY_SYSPM_MISCLDO_VCCACT) || \
                                                         ((mode) == CY_SYSPM_MISCLDO_VOUT))


/* Macro to validate parameters in Cy_SysPm_MiscLdoConfigure() */
#define CY_SYSPM_IS_MISCLDO_VCCACT_TRIM_VALID(trim)    (((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_0) || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_5)  || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_10) || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_15)  || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_20) || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_25)  || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_30) || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_35)  || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_40) || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_35)  || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_30) || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_25)  || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_20) || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_15) || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_10) || \
                                                         ((trim) == CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_5))

#endif /* defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) */

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/* Macro to validate deep sleep modes in Cy_SysPm_CpuEnterDeepSleep() function */
#define CY_SYSPM_IS_DEEPSLEEP_MODE_VALID(mode)             (((mode) == CY_SYSPM_DEEPSLEEP)     || \
                                                            ((mode) == CY_SYSPM_DEEPSLEEP_RAM) || \
                                                            ((mode) == CY_SYSPM_DEEPSLEEP_OFF))
/* Macro to validate parameters in Cy_SysPm_SetupDeepSleepRAM() function */
#define CY_SYSPM_IS_DSRAM_CHECK_VALID(dsramCheck)          (((dsramCheck) == CY_SYSPM_PRE_DSRAM) || \
                                                            ((dsramCheck) == CY_SYSPM_POST_DSRAM))

/* Macro to validate core buck mode in Cy_SysPm_CoreBuckConfig() function */
#define CY_SYSPM_IS_CORE_BUCK_MODE_VALID(mode)           (((mode) == CY_SYSPM_CORE_BUCK_MODE_LP)     || \
                                                          ((mode) == CY_SYSPM_CORE_BUCK_MODE_HP))

/* Macro to validate SOCMEM SRAM Power modes in Cy_SysPm_SetSOCMemPartitionPwrMode() function */
#define CY_SYSPM_IS_SOCMEM_PWR_MODE_VALID(mode)             (((mode) == CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_ON)     || \
                                                            ((mode) == CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_OFF) || \
                                                            ((mode) == CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_ON) || \
                                                            ((mode) == CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_OFF))

#endif



/* Macro to validate parameters in Cy_SysPm_ExecuteCallback() function */

#if !defined(CY_IP_MXS40SSRSS)
#define CY_SYSPM_IS_CALLBACK_MODE_VALID(mode)           (((mode) == CY_SYSPM_CHECK_READY) || \
                                                          ((mode) == CY_SYSPM_CHECK_FAIL) || \
                                                          ((mode) == CY_SYSPM_BEFORE_TRANSITION) || \
                                                          ((mode) == CY_SYSPM_AFTER_TRANSITION))
#endif


/* Macro to validate parameters in Cy_SysPm_CpuEnterSleep() and for Cy_SysPm_CpuEnterDeepSleep() function */
#define CY_SYSPM_IS_WAIT_FOR_VALID(waitFor)             (((waitFor) == CY_SYSPM_WAIT_FOR_INTERRUPT) || \
                                                         ((waitFor) == CY_SYSPM_WAIT_FOR_EVENT))

/* Macro to validate parameters in Cy_SysPm_BackupSetSupply() function */
#define CY_SYSPM_IS_VDDBACKUP_VALID(vddBackControl)      (((vddBackControl) == CY_SYSPM_VDDBACKUP_DEFAULT) || \
                                                          ((vddBackControl) == CY_SYSPM_VDDBACKUP_VBACKUP))

/* Macro to validate parameters in Cy_SysPm_BackupSuperCapCharge() function */
#define CY_SYSPM_IS_SC_CHARGE_KEY_VALID(key)            (((key) == CY_SYSPM_SC_CHARGE_ENABLE) || \
                                                         ((key) == CY_SYSPM_SC_CHARGE_DISABLE))

/* Macro to validate parameters in Cy_SysPm_LdoSetMode() function */
#define CY_SYSPM_IS_LDO_MODE_VALID(key)            (((mode) == CY_SYSPM_LDO_MODE_DISABLED) || \
                                                    ((mode) == CY_SYSPM_LDO_MODE_NORMAL) || \
                                                    ((mode) == CY_SYSPM_LDO_MODE_MIN))

/* Macro to validate parameters in Cy_SysPm_WriteVoltageBitForFlash() function */
#define CY_SYSPM_IS_BIT_FOR_FLASH_VALID(value)     (((value) == CY_SYSPM_FLASH_VOLTAGE_BIT_ULP) || \
                                                    ((value) == CY_SYSPM_FLASH_VOLTAGE_BIT_LP))

/** The internal define of the SRAM PWR MACRO register key for write operation */
#define CY_SYSPM_PWR_MACRO_CTL_WRITE_KEY            (0x05FAU)

/** The internal define of the unlock value for the PMIC functions */
#define CY_SYSPM_PMIC_UNLOCK_KEY                    (0x3AU)

/** The internal define of the first wakeup pin bit used in the
* Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN0_POS                (1UL)

/** The internal define of the second wakeup pin bit
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN1_POS                (2UL)

/**
* The internal define of the first LPComparator bit
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS             (4UL)

/**
* The internal define for the second LPComparator bit
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS             (8UL)

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/**
* The internal define of the first LPComparator value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_LPCOMP0_MASK    (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS))

/**
* The internal define of the second LPComparator value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_LPCOMP1_MASK    (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS))

/**
* The internal define of the first wake-up pin value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN0_MASK    (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN0_POS))

/**
* The internal define of the second wake-up pin value used
* in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN1_MASK    (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN1_POS))

/** The internal define for the first LPComparator polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS))

/** The internal define for the second LPComparator polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS))

/** The internal define for the first wake-up pin polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN0_POS))

/** The internal define for the second wake-up pin polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN1_POS))

/**
* The internal define of the WDT wakeup source
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_WDT_MASK    SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_WDT_Msk

/**
* The internal define of the WDT wakeup source
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_RTC_MASK    SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_RTC_Msk
#endif

/* Internal macro of all possible wakeup sources from hibernate power mode */
#define CY_SYSPM_HIB_WAKEUP_SOURCE_MASK    (CY_SYSPM_HIBERNATE_LPCOMP0_LOW | CY_SYSPM_HIBERNATE_LPCOMP0_HIGH |\
                                            CY_SYSPM_HIBERNATE_LPCOMP1_LOW | CY_SYSPM_HIBERNATE_LPCOMP1_HIGH |\
                                            CY_SYSPM_HIBERNATE_RTC_ALARM   | CY_SYSPM_HIBERNATE_WDT |\
                                            CY_SYSPM_HIBERNATE_PIN0_LOW    | CY_SYSPM_HIBERNATE_PIN0_HIGH |\
                                            CY_SYSPM_HIBERNATE_PIN1_LOW    | CY_SYSPM_HIBERNATE_PIN1_HIGH)


/* The mask for low power modes the power circuits (POR/BOD, Bandgap
*  reference, Reference buffer, Current reference) when active core regulator is
*  LDO
*/
#define CY_SYSPM_PWR_CIRCUITS_LPMODE_ACTIVE_LDO_MASK    (SRSS_PWR_CTL2_LINREG_LPMODE_Msk | CY_SYSPM_PWR_CIRCUITS_LPMODE_ACTIVE_BUCK_MASK)

/* The mask for low power modes the power circuits (POR/BOD, Bandgap
*  reference, Reference buffer, Current reference) when active core regulator is
*  Buck
*/
#define CY_SYSPM_PWR_CIRCUITS_LPMODE_ACTIVE_BUCK_MASK    (SRSS_PWR_CTL2_PORBOD_LPMODE_Msk |\
                                                          SRSS_PWR_CTL2_REFVBUF_DIS_Msk |\
                                                          SRSS_PWR_CTL2_BGREF_LPMODE_Msk)

/* Macro to validate the word index supported in Backup Domain for Store/Restore */
#define CY_SYSPM_IS_WORD_INDEX_VALID(index)    ((index < CY_SRSS_BACKUP_NUM_BREG) && \
                                                 (index > 0U))

/* Macro to validate number of words supported in Backup Domain for Store/Restore */
#define CY_SYSPM_IS_WORD_SIZE_VALID(size)    ((size) <= CY_SRSS_BACKUP_NUM_BREG)

/** \endcond */

/**
* \defgroup group_syspm_return_status The Power Mode Status Defines
* \{
* Defines for the CPU and system power modes status.
*/




#if defined (CY_IP_MXS22SRSS)

/** The CM33 is Active */
#define CY_SYSPM_STATUS_CM33_ACTIVE       ((uint32_t) ((uint32_t)0x1U << 16U))

/** The CM33 is in Sleep */
#define CY_SYSPM_STATUS_CM33_SLEEP        ((uint32_t) ((uint32_t)0x2U << 16U))

/** The CM33 is in DeepSleep */
#define CY_SYSPM_STATUS_CM33_DEEPSLEEP    ((uint32_t) ((uint32_t)0x4U << 16U))


/** The CM55 is Active */
#define CY_SYSPM_STATUS_CM55_ACTIVE       ((uint32_t) ((uint32_t)0x1U << 20U))

/** The CM55 is in Sleep */
#define CY_SYSPM_STATUS_CM55_SLEEP        ((uint32_t) ((uint32_t)0x2U << 20U))

/** The CM55 is in DeepSleep */
#define CY_SYSPM_STATUS_CM55_DEEPSLEEP    ((uint32_t) ((uint32_t)0x4U << 20U))

#endif /* defined (CY_IP_MXS22SRSS) */

/** The system is Low Power mode */
#define CY_SYSPM_STATUS_SYSTEM_LP        ((uint32_t) ((uint32_t)0x80U))

/** The system is in Ultra Low Power mode */
#define CY_SYSPM_STATUS_SYSTEM_ULP       ((uint32_t) ((uint32_t)0x08U << 8U))

/** The system is LPACTIVE Power mode */
#define CY_SYSPM_STATUS_SYSTEM_LPACTIVE  ((uint32_t) ((uint32_t)0x08UL << 16U))

#if defined (CY_IP_MXS22SRSS)
/** The system is HP Power mode */
#define CY_SYSPM_STATUS_SYSTEM_HP        ((uint32_t) ((uint32_t)0x08UL << 24U))
#endif

/** The system is OD Low Power mode */
#define CY_SYSPM_STATUS_SYSTEM_OD        ((uint32_t) ((uint32_t)0x08UL << 28U))

/** The wait time for transition of the device from the Active into
* the LPActive (Low Power Active)
*/
#define CY_SYSPM_ACTIVE_TO_LP_WAIT_US           (1u)

/** The wait delay time which occurs before the Active reference is settled.
* This delay is used in transition of the device from Active into the
* LPACTIVE (Low Power Active) mode
*/
#define CY_SYSPM_LP_TO_ACTIVE_WAIT_BEFORE_US    (8u)

/** The wait delay time which occurs after the Active reference is settled.
* This delay is used in transition the device from Active into the
* LPACTIVE (Low Power Active) mode
*/
#define CY_SYSPM_LP_TO_ACTIVE_WAIT_AFTER_US    (1u)

/** The internal define of the tries number in the Cy_SysPm_ExitLpMode()
* function
 */
#define CY_SYSPM_WAIT_DELAY_TRIES                        (100u)

/** \} group_syspm_return_status */

/** \} group_syspm_macros */

/*******************************************************************************
*       Configuration Structures
*******************************************************************************/

/**
* \addtogroup group_syspm_data_enumerates
* \{
*/

/** The SysPm function return value status definitions. */
typedef enum
{
    CY_SYSPM_SUCCESS         = 0x0U,                                         /**< Successful. */
    CY_SYSPM_BAD_PARAM       = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x01U,    /**< One or more invalid parameters. */
    CY_SYSPM_TIMEOUT         = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x02U,    /**< A time-out occurred. */
    CY_SYSPM_INVALID_STATE   = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x03U,    /**< The operation is not setup or is in an
                                                                                  improper state. */
    CY_SYSPM_CANCELED        = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x04U,    /**< Operation canceled. */
    CY_SYSPM_SYSCALL_PENDING = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x05U,    /**< Canceled due syscall operation pending. */
    CY_SYSPM_FAIL            = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0xFFU     /**< Unknown failure. */
} cy_en_syspm_status_t;

/**
* This enumeration is used to initialize the functions wait action. The wait actions can be -
* an interrupt or an event. Refer to the CMSIS for WFE and WFI instruction explanations.
*/
typedef enum
{
    CY_SYSPM_WAIT_FOR_INTERRUPT,    /**< Wait for an interrupt. */
    CY_SYSPM_WAIT_FOR_EVENT         /**< Wait for an event. */
} cy_en_syspm_waitfor_t;


/** This enumeration is used to configure wakeup sources for the System Hibernate
*   power mode.
*/
#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

typedef enum
{
    /** Wake on a low logic level for the LPComp0. */
    CY_SYSPM_HIBERNATE_LPCOMP0_LOW  = 0x1U,

    /** Wake on a high logic level for the LPComp0. */
    CY_SYSPM_HIBERNATE_LPCOMP0_HIGH = (0x1U << 1),

    /** Wake on a low logic level for the LPComp1. */
    CY_SYSPM_HIBERNATE_LPCOMP1_LOW  = (0x1U << 2),

    /** Wake on a high logic level for the LPComp1. */
    CY_SYSPM_HIBERNATE_LPCOMP1_HIGH = (0x1U << 3),

    /** Configure the RTC alarm as wakeup source. */
    CY_SYSPM_HIBERNATE_RTC_ALARM    = (0x1U << 4),

    /** Configure the WDT interrupt as wakeup source. */
    CY_SYSPM_HIBERNATE_WDT          = (0x1U << 5),

    /** Configure a low logic level for the first wakeup-pin. See device datasheet for specific pin. */
    CY_SYSPM_HIBERNATE_PIN0_LOW     = (0x1U << 6),

    /** Configure a high logic level for the first wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN0_HIGH    = (0x1U << 7),

    /** Configure a low logic level for the second wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN1_LOW     = (0x1U << 8),

    /** Configure a high logic level for the second wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN1_HIGH    = (0x1U << 9)
} cy_en_syspm_hibernate_wakeup_source_t;
#endif

#if !(defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))
/** This enumeration is used to select LDO regulator output voltage. */
typedef enum
{
    CY_SYSPM_LDO_VOLTAGE_ULP  = 0U,    /**< System ULP nominal LDO voltage.
                                            See device datasheet for specific voltage. */
    CY_SYSPM_LDO_VOLTAGE_LP   = 1U,    /**< System LP nominal LDO voltage.
                                            See device datasheet for specific voltage. */
    CY_SYSPM_LDO_VOLTAGE_0_9V = 0U,    /**< 0.9 V nominal LDO voltage */
    CY_SYSPM_LDO_VOLTAGE_1_1V = 1U     /**< 1.1 V nominal LDO voltage */
} cy_en_syspm_ldo_voltage_t;
#endif

/** This enumeration is used to select the LDO regulator operating mode. */
typedef enum
{
    CY_SYSPM_LDO_MODE_DISABLED = 0U,    /**< Disables the LDO. */
    CY_SYSPM_LDO_MODE_NORMAL   = 1U,    /**< Sets normal current mode. See device datasheet for
                                             specific maximum current limit. */
    CY_SYSPM_LDO_MODE_MIN      = 2U     /**< Sets minimum current mode. See device datasheet for
                                             specific  current limit.  */
} cy_en_syspm_ldo_mode_t;

/**
*  This enumeration is used to select the output voltage for the Buck regulator output 1.
*/
typedef enum
{
    CY_SYSPM_BUCK_OUT1_VOLTAGE_ULP  = 0x02U,    /**< System ULP nominal Buck voltage.
                                                     See device datasheet for specific voltage. */
    CY_SYSPM_BUCK_OUT1_VOLTAGE_LP   = 0x05U,    /**< LP nominal Buck voltage.
                                                     See device datasheet for specific voltage. */
    CY_SYSPM_BUCK_OUT1_VOLTAGE_0_9V = 0x02U,    /**< 0.9 V nominal Buck voltage */
    CY_SYSPM_BUCK_OUT1_VOLTAGE_1_1V = 0x05U     /**< 1.1 V nominal Buck voltage */
} cy_en_syspm_buck_voltage1_t;

/** This enumeration is used to select the Buck regulator outputs. */
typedef enum
{
    CY_SYSPM_BUCK_VBUCK_1 = 0x0U,    /**< Buck output 1 Voltage (Vbuck1). Typically used to
                                          supply the PSoC digital core logic. */
    CY_SYSPM_BUCK_VRF                /**< Buck out 2 Voltage (Vbuckrf). Typically used to
                                          supply the BLE radio logic. */
} cy_en_syspm_buck_out_t;

/**
* This enumeration is used to select the output voltage for the Buck regulator
* output 2, which can source the BLE radio.
*/
typedef enum
{
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_15V = 0U,    /**< 1.15 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_2V  = 1U,    /**< 1.20 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_25V = 2U,    /**< 1.25 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_3V  = 3U,    /**< 1.3 V nominal voltage.  */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_35V = 4U,    /**< 1.35 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_4V  = 5U,    /**< 1.4 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_45V = 6U,    /**< 1.45 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_5V  = 7U     /**< 1.5 V nominal voltage. */
} cy_en_syspm_buck_voltage2_t;

/**
* This enumeration is used to set the polarity for the PMIC input. The PMIC output is
* automatically enabled when the configured polarity of the PMIC input and the logic level
* driven to the pmic_wakeup_in pin match.
*
* \warning
* Do not use CY_SYSPM_PMIC_POLARITY_LOW as it is not supported by hardware.
*/
typedef enum
{
    CY_SYSPM_PMIC_POLARITY_LOW   = 0U,    /**< Set active low logic level for the PMIC input. */
    CY_SYSPM_PMIC_POLARITY_HIGH  = 1U     /**< Set active high logic level for the PMIC input. */
} cy_en_syspm_pmic_wakeup_polarity_t;

/** This enumeration selects Vbackup or Vddd to supply Vddbackup. */
typedef enum
{
    CY_SYSPM_VDDBACKUP_DEFAULT         = 0U,    /**< Logic automatically selects Vddd if present or
                                                     Vbackup if Vddd is not present to supply Vddbackup */
    CY_SYSPM_VDDBACKUP_VBACKUP         = 2U     /**< Sets only Vbackup to supply Vddbackup */
} cy_en_syspm_vddbackup_control_t;

/** This enumeration enables supercapacitor charging. */
typedef enum
{
    CY_SYSPM_SC_CHARGE_ENABLE     = 0x3CU,    /**< Enables supercapacitor charging */
    CY_SYSPM_SC_CHARGE_DISABLE    = 0x00U     /**< Disables supercapacitor charging */
} cy_en_syspm_sc_charge_key_t;

/** This enumeration configures the flash voltage bit for different system power modes. */
typedef enum
{
    CY_SYSPM_FLASH_VOLTAGE_BIT_LP  = 0U,    /**< Set the flash voltage bit for system LP mode */
    CY_SYSPM_FLASH_VOLTAGE_BIT_ULP = 1U,    /**< Set the flash voltage bit for system ULP mode */
} cy_en_syspm_flash_voltage_bit_t;

/**
* This enumeration is used to select the low power mode for which the
* appropriate registered callback handler will be executed. For example,
* the registered callback of the type CY_SYSPM_SLEEP will be executed while
* switching into the Sleep power mode.
*/
typedef enum
{
    CY_SYSPM_SLEEP          = 0U,    /**< The Sleep enum callback type */
    CY_SYSPM_DEEPSLEEP      = 1U,    /**< The Deep Sleep enum callback type */
    CY_SYSPM_HIBERNATE      = 2U,    /**< The Hibernate enum callback type */
#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) ||defined (CY_DOXYGEN)
    CY_SYSPM_LP             = 3U,    /**< The Low Power enum callback type */
    CY_SYSPM_ULP            = 4U,     /**< The Ultra Low Power enum callback type */
#endif
#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
    CY_SYSPM_DEEPSLEEP_RAM  = 5U,    /**< The Deep Sleep RAM enum callback type */
    CY_SYSPM_DEEPSLEEP_OFF  = 6U,    /**< The Deep Sleep OFF enum callback type */
#endif
#if defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
    CY_SYSPM_HP             = 7U,     /**< The High Performance mode enum callback type */
#endif

} cy_en_syspm_callback_type_t;

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/**
* This enumeration is used to list the available deep sleep modes.
*/
typedef enum
{
    CY_SYSPM_MODE_DEEPSLEEP        = CY_SYSPM_DEEPSLEEP,        /**< Deep Sleep Mode. */
    CY_SYSPM_MODE_DEEPSLEEP_RAM    = CY_SYSPM_DEEPSLEEP_RAM,    /**< Deep Sleep RAM Mode. */
    CY_SYSPM_MODE_DEEPSLEEP_OFF    = CY_SYSPM_DEEPSLEEP_OFF,    /**< Deep Sleep OFF Mode. */
    CY_SYSPM_MODE_DEEPSLEEP_NONE   = CY_SYSPM_SLEEP,                     /**< Not Deep Sleep Mode. */
} cy_en_syspm_deep_sleep_mode_t;

/**
* This enumeration is used to list the available wakeup modes after deepsleep.
*/
typedef enum
{
    CY_SYSPM_WARM_BOOT_MODE      = 0,    /**< Warm Boot - After DEEPSLEEP-RAM. */
    CY_SYSPM_COLD_BOOT_MODE      = 1,    /**< Cold Boot - After DEEPSLEEP-OFF. */
    CY_SYSPM_POR_BOOT_MODE       = 2,    /**< POR Boot  - After POR Wakeup. */
} cy_en_syspm_boot_mode_t;

/**
* This enumeration is used to select the mode for the
* Core Buck regulator.
*/
typedef enum
{
    CY_SYSPM_CORE_BUCK_MODE_LP    = 0x01U,    /**< Low Power Mode. */
    CY_SYSPM_CORE_BUCK_MODE_HP    = 0x11U,    /**< High Performance mode(Low Ripple Mode) */
} cy_en_syspm_core_buck_mode_t;


#if defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/**
* This enumeration is used to select the output voltage for the
* Core Buck regulator output.
*/

typedef enum
{
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_58V = 0U,    /**< 0.58 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_60V = 1U,    /**< 0.60 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_62V = 2U,    /**< 0.62 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_64V = 3U,    /**< 0.64 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_66V = 4U,    /**< 0.66 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_68V = 5U,    /**< 0.68 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_70V = 6U,    /**< 0.70 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_72V = 7U,    /**< 0.72 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_74V = 8U,    /**< 0.74 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_76V = 9U,    /**< 0.76 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_78V = 10U,   /**< 0.78 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_80V = 11U,   /**< 0.80 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_82V = 12U,   /**< 0.82 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_84V = 13U,   /**< 0.84 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_86V = 14U,   /**< 0.86 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_88V = 15U,   /**< 0.88 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_90V = 16U,   /**< 0.90 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_92V = 17U,   /**< 0.92 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_94V = 18U,   /**< 0.94 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_96V = 19U,   /**< 0.96 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_98V = 20U,   /**< 0.98 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_00V = 21U,   /**< 1.00 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_02V = 22U,   /**< 1.02 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_04V = 23U,   /**< 1.04 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_06V = 24U,   /**< 1.06 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_08V = 25U,   /**< 1.08 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_10V = 26U,   /**< 1.10 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_12V = 27U,   /**< 1.12 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_14V = 28U,   /**< 1.14 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_16V = 29U,   /**< 1.16 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_18V = 30U,   /**< 1.18 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_20V = 31U,   /**< 1.20 V nominal voltage. */
} cy_en_syspm_core_buck_voltage_t;


#else

typedef enum
{
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_76V = 0U,    /**< 0.76 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_78V = 1U,    /**< 0.78 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_80V = 2U,    /**< 0.80 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_82V = 3U,    /**< 0.82 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_84V = 4U,    /**< 0.84 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_86V = 5U,    /**< 0.86 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_88V = 6U,    /**< 0.88 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_90V = 7U,    /**< 0.90 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_92V = 8U,    /**< 0.92 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_94V = 9U,    /**< 0.94 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_96V = 10U,    /**< 0.96 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_98V = 11U,    /**< 0.98 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_00V = 12U,    /**< 1.00 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_02V = 13U,    /**< 1.02 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_04V = 14U,    /**< 1.04 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_06V = 15U,    /**< 1.06 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_08V = 16U,    /**< 1.08 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_10V = 17U,    /**< 1.10 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_12V = 18U,    /**< 1.12 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_14V = 19U,    /**< 1.14 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_16V = 20U,    /**< 1.16 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_18V = 21U,    /**< 1.18 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_20V = 22U,    /**< 1.20 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_22V = 23U,    /**< 1.22 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_24V = 24U,    /**< 1.24 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_26V = 25U,    /**< 1.26 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_28V = 26U,    /**< 1.28 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_30V = 27U,    /**< 1.30 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_32V = 28U,    /**< 1.32 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_34V = 29U,    /**< 1.34 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_36V = 30U,    /**< 1.36 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_38V = 31U,    /**< 1.38 V nominal voltage. */
} cy_en_syspm_core_buck_voltage_t;
#endif

#if defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/**
* This enumeration is used to select the mode for the
* Core Buck regulator.
*/
typedef enum
{
    CY_SYSPM_CORE_BUCK_PROFILE_LP    = 0x00U,    /**< Mode-0, LP Profile */
    CY_SYSPM_CORE_BUCK_PROFILE_ULP   = 0x01U,    /**< Mode-1, ULP Profile */
    CY_SYSPM_CORE_BUCK_PROFILE_HP    = 0x02U,    /**< Mode-2, HP Profile */
    CY_SYSPM_CORE_BUCK_PROFILE_SKIP  = 0x03U,    /**< Skip CBUCK Profile Usage */
} cy_en_syspm_core_buck_profile_t;


/**
* This enumeration is used to select the output voltage for the
* SRAMLDO.
*/

typedef enum
{
    CY_SYSPM_SRAMLDO_VOLTAGE_0_58V = 0U,    /**< 0.58 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_60V = 1U,    /**< 0.60 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_62V = 2U,    /**< 0.62 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_64V = 3U,    /**< 0.64 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_66V = 4U,    /**< 0.66 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_68V = 5U,    /**< 0.68 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_70V = 6U,    /**< 0.70 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_72V = 7U,    /**< 0.72 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_74V = 8U,    /**< 0.74 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_76V = 9U,    /**< 0.76 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_78V = 10U,   /**< 0.78 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_80V = 11U,   /**< 0.80 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_82V = 12U,   /**< 0.82 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_84V = 13U,   /**< 0.84 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_86V = 14U,   /**< 0.86 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_88V = 15U,   /**< 0.88 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_90V = 16U,   /**< 0.90 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_92V = 17U,   /**< 0.92 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_94V = 18U,   /**< 0.94 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_96V = 19U,   /**< 0.96 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_0_98V = 20U,   /**< 0.98 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_1_00V = 21U,   /**< 1.00 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_1_02V = 22U,   /**< 1.02 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_1_04V = 23U,   /**< 1.04 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_1_06V = 24U,   /**< 1.06 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_1_08V = 25U,   /**< 1.08 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_1_10V = 26U,   /**< 1.10 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_1_12V = 27U,   /**< 1.12 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_1_14V = 28U,   /**< 1.14 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_1_16V = 29U,   /**< 1.16 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_1_18V = 30U,   /**< 1.18 V nominal voltage. */
    CY_SYSPM_SRAMLDO_VOLTAGE_1_20V = 31U,   /**< 1.20 V nominal voltage. */
} cy_en_syspm_sramldo_voltage_t;



/**
* This enumeration is used to select the output voltage for the
* RETLDO.
*/
/*
RETLDO Voltage Level table:

-------------------------------------------------
      |  RETLDO gain = 0   |  RETLDO gain = 1   |
LVL   | Temp    | Temp     | Temp    | Temp     |
      | -40C    | 25C-125C | -40C    | 25C-125C |
-------------------------------------------------
00000   0.6150    0.550     0.7595      0.679
00001   0.6262    0.560     0.7733      0.691
00010   0.6374    0.570     0.7871      0.704
00011   0.6485    0.580     0.8010      0.716
00100   0.6597    0.590     0.8148      0.728
00101   0.6709    0.600     0.8286      0.741
00110   0.6821    0.610     0.8424      0.753
00111   0.6933    0.620     0.8562      0.765
01000   0.7045    0.630     0.8700      0.778
01001   0.7045    0.630     0.8700      0.778
01010   0.7045    0.630     0.8700      0.778
01011   0.7045    0.630     0.8700      0.778
01100   0.7045    0.630     0.8700      0.778
01101   0.7045    0.630     0.8700      0.778
01110   0.7045    0.630     0.8700      0.778
01111   0.7045    0.630     0.8700      0.778
10000   0.4361    0.390     0.5386      0.481
10001   0.4473    0.400     0.5524      0.494
10010   0.4585    0.410     0.5662      0.506
10011   0.4696    0.420     0.5800      0.519
10100   0.4808    0.430     0.5938      0.531
10101   0.4920    0.440     0.6076      0.543
10110   0.5032    0.450     0.6214      0.556
10111   0.5144    0.460     0.6352      0.568
11000   0.5255    0.470     0.6490      0.580
11001   0.5367    0.480     0.6629      0.593
11010   0.5479    0.490     0.6767      0.605
11011   0.5591    0.500     0.6905      0.617
11100   0.5703    0.510     0.7043      0.630
11101   0.5815    0.520     0.7181      0.642
11110   0.5926    0.530     0.7319      0.654
11111   0.6038    0.540     0.7457      0.667
*/
typedef enum
{
    CY_SYSPM_RETLDO_VOLTAGE_LVL_0 = 0U,    /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_1 = 1U,    /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_2 = 2U,    /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_3 = 3U,    /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_4 = 4U,    /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_5 = 5U,    /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_6 = 6U,    /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_7 = 7U,    /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_8 = 8U,    /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_9 = 9U,    /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_10 = 10U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_11 = 11U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_12 = 12U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_13 = 13U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_14 = 14U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_15 = 15U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_16 = 16U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_17 = 17U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_18 = 18,   /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_19 = 19U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_20 = 20U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_21 = 21U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_22 = 22U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_23 = 23U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_24 = 24U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_25 = 25U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_26 = 26U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_27 = 27U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_28 = 28U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_29 = 29U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_30 = 30U,  /**< Refer RETLDO Voltage Level table. */
    CY_SYSPM_RETLDO_VOLTAGE_LVL_31 = 31U,  /**< Refer RETLDO Voltage Level table. */
} cy_en_syspm_retldo_voltage_t;

/**
* For RETLDO, this enumeration is used to select the Gain value
*/
typedef enum
{
    CY_SYSPM_RETLDO_GAIN_2              = 0U,    /**< Gain = 2 */
    CY_SYSPM_RETLDO_GAIN_2_47           = 1U,    /**< Gain = 2.47 */
} cy_en_syspm_retldo_gain_t;


/**
* This enumeration is used to select the output voltage(VOUT) for the
* MISCLDO.
*/

typedef enum
{
    CY_SYSPM_MISCLDO_VOLTAGE_0_58V  = 0U,    /**< 0.58 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_60V  = 1U,    /**< 0.60 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_62V  = 2U,    /**< 0.62 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_64V  = 3U,    /**< 0.64 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_66V  = 4U,    /**< 0.66 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_68V  = 5U,    /**< 0.68 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_70V  = 6U,    /**< 0.70 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_72V  = 7U,    /**< 0.72 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_74V  = 8U,    /**< 0.74 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_76V  = 9U,    /**< 0.76 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_78V  = 10U,   /**< 0.78 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_80V  = 11U,   /**< 0.80 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_82V  = 12U,   /**< 0.82 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_84V  = 13U,   /**< 0.84 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_86V  = 14U,   /**< 0.86 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_88V  = 15U,   /**< 0.88 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_90V  = 16U,   /**< 0.90 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_92V  = 17U,   /**< 0.92 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_94V  = 18U,   /**< 0.94 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_96V  = 19U,   /**< 0.96 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_0_98V  = 20U,   /**< 0.98 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_1_00V = 21U,    /**< 1.00 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_1_02V = 22U,    /**< 1.02 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_1_04V = 23U,    /**< 1.04 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_1_06V = 24U,    /**< 1.06 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_1_08V = 25U,    /**< 1.08 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_1_10V = 26U,    /**< 1.10 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_1_12V = 27U,    /**< 1.12 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_1_14V = 28U,    /**< 1.14 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_1_16V = 29U,    /**< 1.16 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_1_18V = 30U,    /**< 1.18 V nominal voltage. */
    CY_SYSPM_MISCLDO_VOLTAGE_1_20V = 31U,    /**< 1.20 V nominal voltage. */
} cy_en_syspm_miscldo_voltage_t;

/**
* This enumeration is used to select the  trim settings for the
* VCCACT voltage of MISCLDO.
*/

typedef enum
{
    CY_SYSPM_MISCLDO_VCCACT_TRIM_0           = 0U,    /**< 0mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_5           = 1U,    /**< 5mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_10          = 2U,    /**< 10mV nominal voltage. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_15          = 3U,    /**< 15mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_20          = 4U,    /**< 20mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_25          = 5U,    /**< 25mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_30          = 6U,    /**< 30mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_35          = 7U,    /**< 35mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_40    = 8U,    /**< -40mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_35    = 9U,    /**< -35mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_30    = 10U,   /**< -30mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_25    = 11U,   /**< -25mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_20    = 12U,   /**< -20mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_15    = 13U,   /**< -15mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_10    = 14U,   /**< -10mV Trim Setting. */
    CY_SYSPM_MISCLDO_VCCACT_TRIM_MINUS_5     = 15U,   /**< -5mV Trim Setting. */
} cy_en_syspm_miscldo_vccact_trim_t;

/**
* For MISCLDO, this enumeration is used to select the output mode for MISCLDO
*/
typedef enum
{
    CY_SYSPM_MISCLDO_VCCACT   = 0U,    /**< MISCLDO output follows VCCACT_MISC */
    CY_SYSPM_MISCLDO_VOUT     = 1U,    /**< MISCLDO output follows VOUT */
} cy_en_syspm_miscldo_mode_t;

#endif /* defined (CY_IP_MXS22SRSS) */


/**
* For SDR's(Step Down Regulators), this enumeration is used to select the SDR0 or SDR1
*/
typedef enum
{
    CY_SYSPM_SDR_0              = 0U,    /**< SDR0 */
    CY_SYSPM_SDR_1              = 1U,    /**< SDR1 */
} cy_en_syspm_sdr_t;

/**
* This enumeration is used to select the output voltage for the
* SDR(Step Down Regulator) output.
*/
typedef enum
{
    CY_SYSPM_SDR_VOLTAGE_0_850V = 0U,    /**< 0.850 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_0_875V = 1U,    /**< 0.875 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_0_900V = 2U,    /**< 0.900 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_0_925V = 3U,    /**< 0.925 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_0_950V = 4U,    /**< 0.950 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_0_975V = 5U,    /**< 0.975 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_000V = 6U,    /**< 1.000 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_025V = 7U,    /**< 1.025 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_050V = 8U,    /**< 1.050 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_075V = 9U,    /**< 1.075 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_100V = 10U,   /**< 1.100 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_125V = 11U,   /**< 1.125 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_150V = 12U,   /**< 1.150 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_175V = 13U,   /**< 1.175 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_200V = 14U,   /**< 1.200 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_225V = 15U,   /**< 1.225 V nominal voltage. */
} cy_en_syspm_sdr_voltage_t;

/**
* This enumeration is used to select the output voltage for the
* HVLDO Regulator.
*/
typedef enum
{
    CY_SYSPM_HVLDO_VOLTAGE_1_800V = 0U,     /**< 1.800 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_1_900V = 1U,     /**< 1.900 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_000V = 2U,     /**< 2.000 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_100V = 3U,     /**< 2.100 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_200V = 4U,     /**< 2.200 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_300V = 5U,     /**< 2.300 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_400V = 6U,     /**< 2.400 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_500V = 7U,     /**< 2.500 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_600V = 8U,     /**< 2.600 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_700V = 9U,     /**< 2.700 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_800V = 10U,    /**< 2.800 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_900V = 11U,    /**< 2.900 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_000V = 12U,    /**< 3.000 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_100V = 13U,    /**< 3.100 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_200V = 14U,    /**< 3.200 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_300V = 15U,    /**< 3.300 V nominal voltage. */
} cy_en_syspm_hvldo_voltage_t;


#endif



/**
* For SRAM0, this enumeration represents the Macro Numbers
*/
typedef enum
{
    CY_SYSPM_SRAM0_MACRO_0              = 0U,    /**< SRAM0:Macro-0 */
    CY_SYSPM_SRAM0_MACRO_1              = 1U,    /**< SRAM0:Macro-1 */
    CY_SYSPM_SRAM0_MACRO_2              = 2U,    /**< SRAM0:Macro-2 */
    CY_SYSPM_SRAM0_MACRO_3              = 3U,    /**< SRAM0:Macro-3 */
    CY_SYSPM_SRAM0_MACRO_4              = 4U,    /**< SRAM0:Macro-4 */
    CY_SYSPM_SRAM0_MACRO_5              = 5U,    /**< SRAM0:Macro-5 */
    CY_SYSPM_SRAM0_MACRO_6              = 6U,    /**< SRAM0:Macro-6 */
    CY_SYSPM_SRAM0_MACRO_7              = 7U,    /**< SRAM0:Macro-7 */
} cy_en_syspm_sram0_macro_t;



/** This enumeration specifies the associated callback mode. This enum defines the callback mode. */
typedef enum
{
    CY_SYSPM_CHECK_READY        = 0x01U,    /**< Callbacks with this mode are executed before entering into the
                                                 low power mode. The purpose of his callback function is to check
                                                 if the device is ready to enter the low power mode. */
    CY_SYSPM_CHECK_FAIL         = 0x02U,    /**< Callbacks with this mode are executed after the CY_SYSPM_CHECK_READY
                                                 callbacks execution returns CY_SYSPM_FAIL.
                                                 The callback with the CY_SYSPM_CHECK_FAIL mode should roll back the
                                                 actions performed in the previously executed callback with
                                                 CY_SYSPM_CHECK_READY */
    CY_SYSPM_BEFORE_TRANSITION  = 0x04U,    /**< Callbacks with this mode are executed after the CY_SYSPM_CHECK_READY
                                                 callbacks execution returns CY_SYSPM_SUCCESS.
                                                 Performs the actions to be done before entering into the
                                                 low power mode. */
    CY_SYSPM_AFTER_TRANSITION         = 0x08U,     /**< Performs the actions to be done after exiting the low power mode
                                                 if entered. */
} cy_en_syspm_callback_mode_t;

/**
* This enumeration is used to select a particular SRAM.
*/
typedef enum
{
    CY_SYSPM_SRAM0_MEMORY      = 0U,    /**< SRAM0 Memory Area */
    CY_SYSPM_SRAM1_MEMORY      = 1U,    /**< SRAM1 Memory Area */
    CY_SYSPM_SRAM2_MEMORY      = 2U,    /**< SRAM2 Memory Area */
} cy_en_syspm_sram_index_t;

/**
* This enumeration is used to select a particular SRAM Power Mode.
*/
typedef enum
{
    CY_SYSPM_SRAM_PWR_MODE_OFF      = 0U,   /**< SRAM Power Mode OFF */
    CY_SYSPM_SRAM_PWR_MODE_INVALID  = 1U,   /**< Invalid SRAM Power Mode */
    CY_SYSPM_SRAM_PWR_MODE_ON       = 3U    /**< SRAM Power Mode ON */
} cy_en_syspm_sram_pwr_mode_t;

#if defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/**
* This enumeration is used to select a particular SOCMEM SRAM Partition Number.
*/
typedef enum
{
    CY_SYSPM_SOCMEM_SRAM_PARTITION0      = 0U,    /**< SOCMEM SRAM Partition-0 Number*/
    CY_SYSPM_SOCMEM_SRAM_PARTITION1      = 1U,    /**< SOCMEM SRAM Partition-1 Number*/
    CY_SYSPM_SOCMEM_SRAM_PARTITION2      = 2U,    /**< SOCMEM SRAM Partition-2 Number*/
    CY_SYSPM_SOCMEM_SRAM_PARTITION3      = 3U,    /**< SOCMEM SRAM Partition-3 Number*/
    CY_SYSPM_SOCMEM_SRAM_PARTITION4      = 4U,    /**< SOCMEM SRAM Partition-4 Number*/
    CY_SYSPM_SOCMEM_SRAM_PARTITION5      = 5U,    /**< SOCMEM SRAM Partition-5 Number*/
    CY_SYSPM_SOCMEM_SRAM_PARTITION6      = 6U,    /**< SOCMEM SRAM Partition-6 Number*/
    CY_SYSPM_SOCMEM_SRAM_PARTITION7      = 7U,    /**< SOCMEM SRAM Partition-7 Number*/
    CY_SYSPM_SOCMEM_SRAM_PARTITION8      = 8U,    /**< SOCMEM SRAM Partition-8 Number*/
    CY_SYSPM_SOCMEM_SRAM_PARTITION9      = 9U,    /**< SOCMEM SRAM Partition-9 Number*/
} cy_en_syspm_socmem_sram_partition_index_t;

/**
* This enumeration is used to select a particular SOCMEM SRAM Partition Power Mode.
*/
typedef enum
{
    CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_ON    = 0U,  /**< SOCMEM SRAM Partition ON during ACTIVE mode */
    CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_OFF   = 1U,  /**< SOCMEM SRAM Partition OFF during ACTIVE mode */
    CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_ON    = 2U,  /**< SOCMEM SRAM Partition Retention ON during DS mode */
    CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_OFF   = 3U,  /**< SOCMEM SRAM Partition Retention OFF during DS mode */
} cy_en_syspm_socmem_sram_pwr_mode_t;

#endif /* defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) */

/** \} group_syspm_data_enumerates */

/**
* \addtogroup group_syspm_macros
* \{
*/
/**
* \defgroup group_syspm_skip_callback_modes Defines to skip the callbacks modes
* \{
* Defines for the SysPm callbacks modes that can be skipped during execution.
* For more information about callbacks modes, refer
* to \ref cy_en_syspm_callback_mode_t.
*/
#define CY_SYSPM_SKIP_CHECK_READY                   (0x01U)   /**< Define to skip check ready mode in the syspm callback */
#define CY_SYSPM_SKIP_CHECK_FAIL                    (0x02U)   /**< Define to skip check fail mode in the syspm callback */
#define CY_SYSPM_SKIP_BEFORE_TRANSITION             (0x04U)   /**< Define to skip before transition mode in the syspm callback */
#define CY_SYSPM_SKIP_AFTER_TRANSITION              (0x08U)   /**< Define to skip after transition mode in the syspm callback */
/** \} group_syspm_skip_callback_modes */
/** \} group_syspm_macros */

/**
* \addtogroup group_syspm_data_structures
* \{
*/

/** The structure contains syspm callback parameters */
typedef struct
{
    void *base;         /**< Base address of a HW instance, matches name of the driver in
                             the API for the base address. Can be undefined if not required. Base address is not
                             required for the SysPm driver as the device has only one set of power modes */
    void *context;      /**< Context for the handler function. This item can be
                             skipped if not required. Can be undefined if not required. */

} cy_stc_syspm_callback_params_t;

/** The type for syspm callbacks */
typedef cy_en_syspm_status_t (*Cy_SysPmCallback) (cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);

/** Structure with syspm callback configuration elements */
typedef struct cy_stc_syspm_callback
{
    Cy_SysPmCallback callback;                         /**< The callback handler function. */
    cy_en_syspm_callback_type_t type;                  /**< The callback type, see \ref cy_en_syspm_callback_type_t. */
    uint32_t skipMode;                                 /**< The mask of modes to be skipped during callback
                                                            execution, see \ref group_syspm_skip_callback_modes. The
                                                            corresponding callback mode won't execute if the
                                                            appropriate define is set. These values can be ORed.
                                                            If all modes are required to be executed this element
                                                            should be equal to zero. Skipping unneeded callback modes speeds up
                                                            power mode transitions by skipping unneeded operations. */

    cy_stc_syspm_callback_params_t *callbackParams;    /**< The address of a cy_stc_syspm_callback_params_t,
                                                            the callback is executed with these parameters. */

    struct cy_stc_syspm_callback *prevItm;             /**< The previous list item. This element should not be
                                                            defined, or defined as NULL. It is for internal
                                                            usage to link this structure to the next registered
                                                            structure. It will be updated during callback
                                                            registration. Do not modify this element at run-time. */

    struct cy_stc_syspm_callback *nextItm;             /**< The next list item. This element should not be
                                                            defined, or defined as NULL. It is for internal usage to
                                                            link this structure to the previous registered structure.
                                                            It will be updated during callback registration. Do not
                                                            modify this element at run-time. */
    uint8_t order;                                     /**< Holds the callback execution order value. Range: 0-255.
                                                            While entering low power mode, callbacks with lower order values
                                                            are executed first. While exiting low power mode,
                                                            the callbacks are executed in the opposite order.
                                                            Callbacks with the same order value are executed in the
                                                            order they are registered in the application. */
} cy_stc_syspm_callback_t;


#if (defined(CY_DEVICE_SECURE))
/** PRA structure for Cy_SysPm_BuckSetVoltage2 function parameters */
typedef struct
{
    cy_en_syspm_buck_voltage2_t praVoltage;     /**< The voltage of the Buck regulator output 2 */
    bool praWaitToSettle;                       /**< Enable/disable the delay after setting a higher voltage */
} cy_stc_pra_voltage2_t;

typedef struct
{
    cy_en_syspm_sram_index_t sramNum;           /**< SRAM index */
    uint32_t sramMacroNum;                      /**< SRAM macro number */
    cy_en_syspm_sram_pwr_mode_t sramPwrMode;    /**< Power mode */
} cy_stc_pra_sram_power_mode_config_t;

#endif /* (defined(CY_DEVICE_SECURE)) */

#if defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/** The structure contains syspm RETLDO configuration parameters */
typedef struct
{
    cy_en_syspm_retldo_voltage_t   activeVoltSel;     /**< RETLDO Voltage Select \ref cy_en_syspm_retldo_voltage_t */
    cy_en_syspm_retldo_gain_t      activeGain;        /**< RETLDO Gain Select Select \ref cy_en_syspm_retldo_voltage_t */
    cy_en_syspm_retldo_voltage_t   deepsleepVoltSel;  /**< RETLDO Deepsleep Voltage Select \ref cy_en_syspm_retldo_voltage_t */
    cy_en_syspm_retldo_gain_t      deepsleepGain;     /**< RETLDO Deepsleep Gain Select \ref cy_en_syspm_retldo_voltage_t */
} cy_stc_syspm_retldo_params_t;

/** The structure contains syspm SRAMLDO configuration parameters */
typedef struct
{
    bool                            sramLdoEnable;          /**< SRAMLDO Enable/Disable */
    bool                            deepsleepSramLdoEnable; /**< SRAMLDO Enable/Disable during deepsleep */
    cy_en_syspm_sramldo_voltage_t   sramLdoVoltSel;         /**< SRAMLDO Voltage Select \ref cy_en_syspm_sramldo_voltage_t */
} cy_stc_syspm_sramldo_params_t;

/** The structure contains syspm MISCLDO configuration parameters */
typedef struct
{
    bool                                miscLdoEnable;          /**< MISCLDO Enable/Disable */
    cy_en_syspm_miscldo_mode_t          miscLdoMode;            /**< MISCLDO mode select , VCCACT or VOUT */
    cy_en_syspm_miscldo_voltage_t       miscLdoVoltSel;         /**< MISCLDO Voltage Select \ref cy_en_syspm_miscldo_voltage_t */
    cy_en_syspm_miscldo_vccact_trim_t   miscLdoVaccActTrimSel;  /**< MISCLDO VCCACT Voltage Trim Select \ref cy_en_syspm_miscldo_vccact_trim_t */
} cy_stc_syspm_miscldo_params_t;


#endif /* defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) */

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/** The structure contains warmboot entry point struct used during DEEPSLEEP-RAM entry*/
typedef struct
{
    uint32_t *stack_pointer;      /**< Stack Pointer */
    uint32_t *entry_pointer;      /**< Entry Function Address */
} cy_stc_syspm_warmboot_entrypoint_t;

/** The structure contains syspm core buck configuration parameters */
typedef struct
{
    uint8_t   voltageSel;      /**< Core Buck Voltage Select \ref cy_en_syspm_core_buck_voltage_t */
    uint8_t   mode;            /**< Core Buck Mode :
                                    0x01 - Low Power Mode,
                                    0x11 - High Performance mode(Low Ripple Mode) */
    bool      override;        /**< Core Buck Override : Forces Corebuck to
                                    use the setting in the PWR_CBUCK_CTL register */
    bool      copySettings;    /**< Core Buck Copy Settings :
                                    Copies the current CBUCK composite state to
                                    PWR_CBUCK_CTL register */
    bool      useSettings;     /**< Core Buck use Settings :
                                    Causes the settings in PWR_CBUCK_CTL to be
                                    used in CBUCK settings decision */
    uint8_t   inRushLimitSel;  /**< Core Buck In Rush Limit Selection
                                    0: 10mA  limit
                                    1: 100mA limit */
} cy_stc_syspm_core_buck_params_t;

/** The structure contains syspm SDR0/SDR1(Step Down Regulator) LDO configuration parameters */
typedef struct
{
    uint8_t   coreBuckVoltSel;     /**< Core Buck Voltage Select \ref cy_en_syspm_core_buck_voltage_t */
    uint8_t   coreBuckMode;        /**< Core Buck Mode :
                                    0x01 - Low Power Mode,
                                    0x11 - High Performance mode(Low Ripple Mode) */

    /* This field applicable only for SDR0 */
    uint8_t   coreBuckDpSlpVoltSel; /**< Deep Sleep Core Buck Voltage Select \ref cy_en_syspm_core_buck_voltage_t */

    /* This field applicable only for SDR0 */
    uint8_t   coreBuckDpSlpMode;    /**< Deep sleep Core Buck Mode :
                                     0x01 - Low Power Mode,
                                     0x11 - High Performance mode(Low Ripple Mode) */

    uint8_t   sdrVoltSel;           /**< SDR Regulator Voltage Select \ref cy_en_syspm_sdr_voltage_t */

    /* This field applicable only for SDR0 */
    uint8_t   sdr0DpSlpVoltSel;     /**< SDR Regulator Voltage Select \ref cy_en_syspm_sdr_voltage_t */

    /* This field applicable only for SDR0 */
    bool      sdr0Allowbypass;      /**< Allow SDR bypass :
                                     true  - Allow SDR to bypass
                                     false - SDR is not bypassed and will regulate */
    /* This field applicable only for SDR1 */
    bool      sdr1HwControl;        /**< Allow SDR1 HW Control :
                                     true  - sdr1Enable(bit: SDR1_ENABLE) is ignored, HW will control
                                     false - sdr1Enable(bit: SDR1_ENABLE) will control, HW control is ignored */
    /* This field applicable only for SDR1 */
    bool      sdr1Enable;           /**<  SDR1 Enable/Disable:
                                     true  - SDR1 is enabled
                                     false - SDR1 is disabled */
} cy_stc_syspm_sdr_params_t;

/** The structure contains syspm HVLDO configuration parameters */
typedef struct
{
    uint8_t   voltageSel;      /**< HVLDO Voltage Select \ref cy_en_syspm_hvldo_voltage_t */
    bool      hwSel;           /**< HVLDO HW Select :
                                    0 - HVLDO0_ENABLE controls SDR1,HW controls are ignored
                                    1 - HVLDO0_ENABLE is ignored and HW signal is used instead */
    bool      hvldoEnable;     /**< HVLDO Enable/Disable:
                                    true - HVLDO is enabled
                                    false - HVLDO is disabled */
} cy_stc_syspm_hvldo_params_t;


/** The structure contains syspm Extra Requestor configuration parameters */
typedef struct
{
    uint8_t   coreBuckVoltSel; /**< Core Buck Voltage Select \ref cy_en_syspm_core_buck_voltage_t */
    uint8_t   coreBuckMode;    /**< Core Buck Mode :
                                    0x00 - Low Power Mode,
                                    0x10 - Low Ripple(high power) */
    cy_stc_syspm_sdr_params_t *sdr0Config; /**< SDR-0 Parameters \ref cy_stc_syspm_sdr_params_t */
    cy_stc_syspm_sdr_params_t *sdr1Config; /**< SDR-1 Parameters \ref cy_stc_syspm_sdr_params_t */
} cy_stc_syspm_extraReq_params_t;

#endif

/** \cond INTERNAL */
#if defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
/** This is only used by secure-aware. The structure contains enable CM55 configuration parameters */
typedef struct {
    uint32_t vectorTableOffset;
    cy_app_cpu_dbg_port_type_t dbgMode;
    uint32_t waitus;
} cy_pdl_syspm_srf_syscm55enable_in_t;


/** This is only used by secure-aware. The structure contains reset CM55 configuration parameters */
typedef struct {
    uint32_t waitus;
} cy_pdl_syspm_srf_syscm55reset_in_t;

#endif
/** \endcond */
/** \} group_syspm_data_structures */

/**
* \addtogroup group_syspm_functions
* \{
*/

/**
* \addtogroup group_syspm_functions_general
* \{
*/

/*******************************************************************************
* Function Name: Cy_SysPm_SetSRAMMacroPwrMode
****************************************************************************//**
*
* Function to set Power Mode for each of the Macro in a particular SRAM.
*
* \param sramNum
* SRAM's index number has to be passed
* ex: CY_SYSPM_SRAM0_MEMORY or CY_SYSPM_SRAM1_MEMORY or CY_SYSPM_SRAM2_MEMORY
* See \ref cy_en_syspm_sram_index_t.
*
* \param sramMacroNum
* Macro number of a particular SRAM.
*
* \note
* If SRAM1 and SRAM2 consists of single power partition, power mode will be
* applied to whole SRAM region, so 0 must be passed for sramMacroNum parameter.
*
* \param sramPwrMode
* Power Mode that needs to be set.
*
* \return
* - CY_SYSPM_SUCCESS - SRAM MACRO power mode is set.
* - CY_SYSPM_BAD_PARAM - Input parameters are out of range.
* See \ref cy_en_syspm_status_t.
*
*
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetSRAMMacroPwrMode(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode);

/*******************************************************************************
* Function Name: Cy_SysPm_GetSRAMMacroPwrMode
****************************************************************************//**
*
* Function to get Power Mode for each of the Macro in a particular SRAM.
*
* \param sramNum
* SRAM's index number has to be passed
* ex: CY_SYSPM_SRAM0_MEMORY or CY_SYSPM_SRAM1_MEMORY or CY_SYSPM_SRAM2_MEMORY
* See \ref cy_en_syspm_sram_index_t.
*
* \param sramMacroNum
* Macro number of a particular SRAM.
*
* \note
* If SRAM1 and SRAM2 consists of single power partition, power mode will be
* applied to whole SRAM region, so 0 must be passed for sramMacroNum parameter,
* and the power mode obtained will be for whole SRAM.
*
* \return
* Returns SRAM power mode. See \ref cy_en_syspm_sram_pwr_mode_t.
*
*******************************************************************************/
cy_en_syspm_sram_pwr_mode_t Cy_SysPm_GetSRAMMacroPwrMode(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum);

/*******************************************************************************
* Function Name: Cy_SysPm_SetSRAMPwrMode
****************************************************************************//**
*
* Function to set Power Mode for all the Macros for a particular SRAM.
*
* \param sramNum
* SRAM's index number has to be passed
* ex: CY_SYSPM_SRAM0_MEMORY or CY_SYSPM_SRAM1_MEMORY or CY_SYSPM_SRAM2_MEMORY
* See \ref cy_en_syspm_sram_index_t.
*
* \param sramPwrMode
* Power Mode that needs to be set.
*
* \return
* - CY_SYSPM_SUCCESS - SRAM power mode is set.
* - CY_SYSPM_BAD_PARAM - Input parameters are out of range.
* See \ref cy_en_syspm_status_t.
*
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetSRAMPwrMode(cy_en_syspm_sram_index_t sramNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode);

#if defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_SetSOCMemPartActivePwrMode
****************************************************************************//**
*
* Set Active mode Power Mode for a particular partition of SRAM in SOCMEM
*
* \param socmemSramPartNum
* SOCMEM- SRAM's Partition Number
* See \ref cy_en_syspm_socmem_sram_partition_index_t.
*
* \param socmemSramPwrMode
* Power Mode that needs to be set.
* See \ref cy_en_syspm_socmem_sram_pwr_mode_t.
*
* \return
* - CY_SYSPM_SUCCESS - SRAM power mode is set.
* - CY_SYSPM_BAD_PARAM - Input parameters are out of range.
* See \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetSOCMemPartActivePwrMode(cy_en_syspm_socmem_sram_partition_index_t socmemSramPartNum, cy_en_syspm_socmem_sram_pwr_mode_t socmemSramPwrMode);

/*******************************************************************************
* Function Name: Cy_SysPm_SetSOCMemPartDsPwrMode
****************************************************************************//**
*
* Set DS mode Power Mode for a particular partition of SRAM in SOCMEM
*
* \param socmemSramPartNum
* SOCMEM- SRAM's Partition Number
* See \ref cy_en_syspm_socmem_sram_partition_index_t.
*
* \param socmemSramPwrMode
* Power Mode that needs to be set.
* See \ref cy_en_syspm_socmem_sram_pwr_mode_t.
*
* \return
* - CY_SYSPM_SUCCESS - SRAM power mode is set.
* - CY_SYSPM_BAD_PARAM - Input parameters are out of range.
* See \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetSOCMemPartDsPwrMode(cy_en_syspm_socmem_sram_partition_index_t socmemSramPartNum, cy_en_syspm_socmem_sram_pwr_mode_t socmemSramPwrMode);

/*******************************************************************************
* Function Name: Cy_SysPm_GetSOCMemSramPartActivePwrMode
****************************************************************************//**
*
* Function to get Active mode Power Mode for a particular SOCMEM SRAM Partition
*
* \param socmemSramPartNum
* SOCMEM- SRAM's Partition Number
* See \ref cy_en_syspm_socmem_sram_partition_index_t.
*
* \return
* Returns SRAM power mode. See \ref cy_en_syspm_socmem_sram_pwr_mode_t.
*
*******************************************************************************/
cy_en_syspm_socmem_sram_pwr_mode_t Cy_SysPm_GetSOCMemSramPartActivePwrMode(cy_en_syspm_socmem_sram_partition_index_t socmemSramPartNum);

/*******************************************************************************
* Function Name: Cy_SysPm_GetSOCMemSramPartDsPwrMode
****************************************************************************//**
*
* Function to get DS mode Power Mode for a particular SOCMEM SRAM Partition
*
* \param socmemSramPartNum
* SOCMEM- SRAM's Partition Number
* See \ref cy_en_syspm_socmem_sram_partition_index_t.
*
* \return
* Returns SRAM power mode. See \ref cy_en_syspm_socmem_sram_pwr_mode_t.
*
*******************************************************************************/
cy_en_syspm_socmem_sram_pwr_mode_t Cy_SysPm_GetSOCMemSramPartDsPwrMode(cy_en_syspm_socmem_sram_partition_index_t socmemSramPartNum);


#endif /* defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) */


/** \} group_syspm_functions_general */


/**
* \addtogroup group_syspm_functions_power_status
* \{
*/

#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_ReadStatus
****************************************************************************//**
*
* Reads the power modes status of the system and CPU(s).
*
* \return
* The current power mode. See \ref group_syspm_return_status.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_ReadStatus
*
*******************************************************************************/
uint32_t Cy_SysPm_ReadStatus(void);
#endif
/** \} group_syspm_functions_power_status */

/**
* \addtogroup group_syspm_functions_power
* \{
*/


/*******************************************************************************
* Function Name: Cy_SysPm_DeepSleepSetup
****************************************************************************//**
*
* Sets the startup deepsleep mode of \ref cy_DeepSleepMode variable.
*
* \param deepSleepMode
* CY_SYSPM_MODE_DEEPSLEEP or CY_SYSPM_MODE_DEEPSLEEP_RAM or CY_SYSPM_MODE_DEEPSLEEP_OFF
*
* \note This API does not take into account any run-time deepsleep mode updates.
* Should any updates occur, \ref Cy_SysPm_DeepSleepUpdate must be called afterwards
* on the CM33_NS and CM55.
*
*******************************************************************************/
void Cy_SysPm_DeepSleepSetup(cy_en_syspm_deep_sleep_mode_t deepSleepMode);

/*******************************************************************************
* Function Name: Cy_SysPm_DeepSleepUpdate
****************************************************************************//**
*
* Gets deepsleep mode and updates \ref cy_DeepSleepMode variable.
*
* Updates global variables used by the \ref Cy_SysPm_CpuEnterDeepSleep().
*
*******************************************************************************/
void Cy_SysPm_DeepSleepUpdate (void);


/*******************************************************************************
* Function Name: Cy_SysPm_CpuEnterSleep
****************************************************************************//**
*
* Sets executing CPU to Sleep mode.
*
* Puts the CPU executing this function into CPU Sleep power mode. If callback
* functions were registered they are also executed.
*
* For more detail about switching into CPU Sleep power mode and debug,
* refer to the device technical reference manual (TRM).
*
* If at least one callback function with the CY_SYSPM_SLEEP type was registered,
* the following algorithm is executed:
* Prior to entering CPU Sleep mode, all callback functions of the CY_SYSPM_SLEEP
* type with the CY_SYSPM_CHECK_READY parameter are called. This allows the
* driver to signal whether it is ready to enter the low power mode. If any of
* the callbacks of the CY_SYSPM_SLEEP type with the CY_SYSPM_CHECK_READY
* parameter returns CY_SYSPM_FAIL, the remaining callbacks of the
* CY_SYSPM_SLEEP type with the CY_SYSPM_CHECK_READY parameter are skipped.
* After the first CY_SYSPM_FAIL, all the CY_SYSPM_SLEEP callbacks that were
* previously executed before getting the CY_SYSPM_CHECK_FAIL are executed with
* the CY_SYSPM_CHECK_FAIL parameter. The CPU Sleep mode is not entered and the
* Cy_SysPm_CpuEnterSleep() function returns CY_SYSPM_FAIL.
*
* If all of the callbacks of the CY_SYSPM_SLEEP type with the
* CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS, then all
* callbacks of the CY_SYSPM_SLEEP type with the CY_SYSPM_CHECK_FAIL parameters
* calls are skipped. All callbacks of the CY_SYSPM_SLEEP type and then
* CY_SYSPM_BEFORE_TRANSITION parameter calls are executed, allowing the
* peripherals to prepare for CPU Sleep. The CPU then enters Sleep mode.
* This is a CPU-centric power mode. This means that the CPU has entered Sleep
* mode and its main clock is removed. Any enabled interrupt can cause a CPU
* wakeup from Sleep mode.
*
* For multi-core devices, CPU wakeup can also be performed using the Send Event
* (SEV) assembly instruction executed from the other active CPU. Such wakeup is
* expected only if the CPU Sleep power mode is done with WFE assembly
* instruction.
*
* After a wakeup from CPU Sleep, all of the registered callbacks of the
* CY_SYSPM_SLEEP type and with the CY_SYSPM_AFTER_TRANSITION parameter are
* executed to return the peripherals to CPU active operation.
* The Cy_SysPm_CpuEnterSleep() function returns CY_SYSPM_SUCCESS.
* No callbacks of the CY_SYSPM_SLEEP type with the CY_SYSPM_BEFORE_TRANSITION
* parameter or callbacks of the CY_SYSPM_SLEEP type and
* CY_SYSPM_AFTER_TRANSITION parameter callbacks are executed if CPU Sleep mode
* is not entered.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* To support control of callback execution order the following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.

* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* \ref cy_en_syspm_callback_mode_t, except the CY_SYSPM_CHECK_READY, are ignored
*
* \note The Arm BSD assembly instruction is not required in this function
* because the function implementation ensures the SLEEPDEEP bit of SCS register
* is settled prior executing WFI/WFE instruction.
*
* \note This API is secure aware but when running on the core without TrustZone,
* there will be no special security-related behavior. See header subsection Secure
* Aware SYSPM for further details.
*
* \param waitFor
* Selects wait for action. See \ref cy_en_syspm_waitfor_t.
*
* \return
* Entered status, see \ref cy_en_syspm_status_t.
*
* \sideeffect
* For CY8C6xx6, CY8C6xx7 devices this function clears the Event Register of the
* CM4 CPU after wakeup from WFE.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_CpuEnterSleep
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_CpuEnterSleep(cy_en_syspm_waitfor_t waitFor);

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_Init
****************************************************************************//**
*
* Initializes SysPm Driver
*
*******************************************************************************/
void Cy_SysPm_Init(void);
#endif

#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_IsLpmReady
****************************************************************************//**
*
* Checks if the system is LPM ready.
*
* \note This API is secure aware. See header subsection Secure Aware SYSPM for further details.
* The involved PPC regions is PROT_PERI0_SRSS_MAIN.
*
* \return
* - True if the system is LPM Ready.
* - False if the system is not LPM Ready.
*
*******************************************************************************/
bool Cy_SysPm_IsLpmReady(void);
#endif  /* defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_DOXYGEN) */


/*******************************************************************************
* Function Name: Cy_SysPm_StoreDSContext_Wfi
****************************************************************************//**
*
* Allow users to implement any context store required before entering deep sleep
* in RTOS based builds, It is defined weak to allow callers override the default
* PDL implementation.
*
*******************************************************************************/


#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_SetDeepSleepMode
****************************************************************************//**
*
* Set the deepsleep mode - deepsleep or deepsleep-ram or deepsleep-off
*
* \note
* If mode is set to CY_SYSPM_MODE_DEEPSLEEP_RAM && Application in Flash, user
* needs to take care of below
*
* Two types of images need to be generated
* 1. Flash image
*    - Contains the actual application.
*
* 2. RAM Image(Resides in RAM)
*    - Contains Warmboot Entry Point function.
*    - SMIF initialization is performed only during coldboot, and not in
*      warmboot, so RAM Image will have the code performing SMIF
*      initialization before jumping to Flash Image.
*
* Before entering CY_SYSPM_MODE_DEEPSLEEP_RAM, user need to take care of below
* 1. Entry point
*    - Set entry point to a function located in RAM Image using
*    - Cy_Syslib_SetWarmBootEntryPoint(Syslib Driver)
*
* After waking up from CY_SYSPM_MODE_DEEPSLEEP_RAM, bootrom jumps to
* entry point function located in RAM image code. Entry point function should
* take care of below
*
* 1. Vector table and Peripheral IP's enabling
*    - Set VTOR register with vector table address.
*    - Enable all the peripheral IP's using \ref Cy_SysClk_PeriGroupSetSlaveCtl.
* 2. SMIF Initialization
*    - Perform  SMIF Initialization.
* 3. Jump to API in the Flash.
*
* \param deepSleepMode
* CY_SYSPM_MODE_DEEPSLEEP or CY_SYSPM_MODE_DEEPSLEEP_RAM or CY_SYSPM_MODE_DEEPSLEEP_OFF
*
* \return
* - CY_SYSPM_SUCCESS - Deep sleep mode is set
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetDeepSleepMode(cy_en_syspm_deep_sleep_mode_t deepSleepMode);

#if defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_SetSysDeepSleepMode
****************************************************************************//**
*
* Set the deepsleep mode for SYS PPU Group- deepsleep or deepsleep-ram or deepsleep-off
*
* \note
* If mode is set to CY_SYSPM_MODE_DEEPSLEEP_RAM && Application in Flash, user
* needs to take care of below
*
* Two types of images need to be generated
* 1. Flash image
*    - Contains the actual application.
*
* 2. RAM Image(Resides in RAM)
*    - Contains Warmboot Entry Point function.
*    - SMIF initialization is performed only during coldboot, and not in
*      warmboot, so RAM Image will have the code performing SMIF
*      initialization before jumping to Flash Image.
*
* Before entering CY_SYSPM_MODE_DEEPSLEEP_RAM, user need to take care of below
* 1. Entry point
*    - Set entry point to a function located in RAM Image using
*    - Cy_Syslib_SetWarmBootEntryPoint(Syslib Driver)
*
* After waking up from CY_SYSPM_MODE_DEEPSLEEP_RAM, bootrom jumps to
* entry point function located in RAM image code. Entry point function should
* take care of below
*
* 1. Vector table and Peripheral IP's enabling
*    - Set VTOR register with vector table address.
*    - Enable all the peripheral IP's using \ref Cy_SysClk_PeriGroupSetSlaveCtl.
* 2. SMIF Initialization
*    - Perform  SMIF Initialization.
* 3. Jump to API in the Flash.
*
* \param deepSleepMode
* CY_SYSPM_MODE_DEEPSLEEP or CY_SYSPM_MODE_DEEPSLEEP_RAM or CY_SYSPM_MODE_DEEPSLEEP_OFF
*
* \return
* - CY_SYSPM_SUCCESS - Deep sleep mode is set
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetSysDeepSleepMode(cy_en_syspm_deep_sleep_mode_t deepSleepMode);

/*******************************************************************************
* Function Name: Cy_SysPm_SetAppDeepSleepMode
****************************************************************************//**
*
* Set the deepsleep mode for APP PPU Group- deepsleep or deepsleep-ram or deepsleep-off
*
* \note
* If mode is set to CY_SYSPM_MODE_DEEPSLEEP_RAM && Application in Flash, user
* needs to take care of below
*
* Two types of images need to be generated
* 1. Flash image
*    - Contains the actual application.
*
* 2. RAM Image(Resides in RAM)
*    - Contains Warmboot Entry Point function.
*    - SMIF initialization is performed only during coldboot, and not in
*      warmboot, so RAM Image will have the code performing SMIF
*      initialization before jumping to Flash Image.
*
* Before entering CY_SYSPM_MODE_DEEPSLEEP_RAM, user need to take care of below
* 1. Entry point
*    - Set entry point to a function located in RAM Image using
*    - Cy_Syslib_SetWarmBootEntryPoint(Syslib Driver)
*
* After waking up from CY_SYSPM_MODE_DEEPSLEEP_RAM, bootrom jumps to
* entry point function located in RAM image code. Entry point function should
* take care of below
*
* 1. Vector table and Peripheral IP's enabling
*    - Set VTOR register with vector table address.
*    - Enable all the peripheral IP's using \ref Cy_SysClk_PeriGroupSetSlaveCtl.
* 2. SMIF Initialization
*    - Perform  SMIF Initialization.
* 3. Jump to API in the Flash.
*
* \note This API is secure aware. See header subsection Secure Aware SYSPM for further details.
* The involved PPC regions are PROT_PERI0_PWRMODE_PWRMODE/PROT_PERI1_M55APPCPUSS
*
* \param deepSleepMode
* CY_SYSPM_MODE_DEEPSLEEP or CY_SYSPM_MODE_DEEPSLEEP_RAM or CY_SYSPM_MODE_DEEPSLEEP_OFF
*
* \return
* - CY_SYSPM_SUCCESS - Deep sleep mode is set
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
*
*******************************************************************************/

cy_en_syspm_status_t Cy_SysPm_SetAppDeepSleepMode(cy_en_syspm_deep_sleep_mode_t deepSleepMode);

/*******************************************************************************
* Function Name: Cy_SysPm_GetSysDeepSleepMode
****************************************************************************//**
*
* Get the SYS Power domain deepsleep mode - deepsleep or deepsleep-ram or deepsleep-off
*
* \note This API is secure aware. See header subsection Secure Aware SYSPM for further details.
* The involved PPC regions is PROT_PERI0_PWRMODE_PWRMODE.
*
* \return
* Returns \ref cy_en_syspm_deep_sleep_mode_t
*
*******************************************************************************/
cy_en_syspm_deep_sleep_mode_t Cy_SysPm_GetSysDeepSleepMode(void);

/*******************************************************************************
* Function Name: Cy_SysPm_GetAppDeepSleepMode
****************************************************************************//**
*
* Get the APP Power domain deepsleep mode - deepsleep or deepsleep-ram or deepsleep-off
*
* \return
* Returns \ref cy_en_syspm_deep_sleep_mode_t
*
*******************************************************************************/
cy_en_syspm_deep_sleep_mode_t Cy_SysPm_GetAppDeepSleepMode(void);


/*******************************************************************************
* Function Name: Cy_SysPm_SetSOCMEMDeepSleepMode
****************************************************************************//**
*
* Set the deepsleep mode for SOCMEM PPU - deepsleep or deepsleep-ram or deepsleep-off
*
* \note
* If mode is set to CY_SYSPM_MODE_DEEPSLEEP_RAM && Application in Flash, user
* needs to take care of below
*
* Two types of images need to be generated
* 1. Flash image
*    - Contains the actual application.
*
* 2. RAM Image(Resides in RAM)
*    - Contains Warmboot Entry Point function.
*    - SMIF initialization is performed only during coldboot, and not in
*      warmboot, so RAM Image will have the code performing SMIF
*      initialization before jumping to Flash Image.
*
* Before entering CY_SYSPM_MODE_DEEPSLEEP_RAM, user need to take care of below
* 1. Entry point
*    - Set entry point to a function located in RAM Image using
*    - Cy_Syslib_SetWarmBootEntryPoint(Syslib Driver)
*
* After waking up from CY_SYSPM_MODE_DEEPSLEEP_RAM, bootrom jumps to
* entry point function located in RAM image code. Entry point function should
* take care of below
*
* 1. Vector table and Peripheral IP's enabling
*    - Set VTOR register with vector table address.
*    - Enable all the peripheral IP's using \ref Cy_SysClk_PeriGroupSetSlaveCtl.
* 2. SMIF Initialization
*    - Perform  SMIF Initialization.
* 3. Jump to API in the Flash.
*
* \param deepSleepMode
* CY_SYSPM_MODE_DEEPSLEEP or CY_SYSPM_MODE_DEEPSLEEP_RAM or CY_SYSPM_MODE_DEEPSLEEP_OFF
*
* \return
* - CY_SYSPM_SUCCESS - Deep sleep mode is set
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetSOCMEMDeepSleepMode(cy_en_syspm_deep_sleep_mode_t deepSleepMode);

/*******************************************************************************
* Function Name: Cy_SysPm_SetPPUDeepSleepMode
****************************************************************************//**
*
* Set the deep sleep mode for a particular PPU - ON, FULL_RET, MEM_RET, OFF
*
* \param ppu
* Base address of the PPU that needs to be configured.
*
* \param mode
* Deep Sleep mode to be set for the PPU.
*
* \return
* - CY_SYSPM_SUCCESS - Deep sleep mode is set
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetPPUDeepSleepMode(uint32_t ppu, uint32_t mode);

/*******************************************************************************
* Function Name: Cy_SysPm_SystemTransitionHpToLp
****************************************************************************//**
*
* Performs system transition from High Performance mode(HP) to Low Power mode(LP) mode.
*
* \note This API is secure aware. See header subsection Secure Aware SYSPM for further details.
* The involved PPC regions is PROT_PERI0_SRSS_MAIN.
*
* \return
* - CY_SYSPM_SUCCESS - Successfully transitioned from HP to LP mode.
* - CY_SYSPM_FAIL - The transition failed.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemTransitionHpToLp(void);

/*******************************************************************************
* Function Name: Cy_SysPm_SystemTransitionLpToHp
****************************************************************************//**
*
* Performs system transition from Low Power mode(LP) to High Performance mode(HP) mode.
*
* \note This API is secure aware. See header subsection Secure Aware SYSPM for further details.
* The involved PPC regions is PROT_PERI0_SRSS_MAIN.
*
* \return
* - CY_SYSPM_SUCCESS - Successfully transitioned from LP to HP mode.
* - CY_SYSPM_FAIL - The transition failed.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemTransitionLpToHp(void);

/*******************************************************************************
* Function Name: Cy_SysPm_SystemTransitionUlpToLp
****************************************************************************//**
*
* Performs system transition from Ultra Low Power mode(ULP) to Low Power mode(LP) mode.
*
* \note This API is secure aware. See header subsection Secure Aware SYSPM for further details.
* The involved PPC regions is PROT_PERI0_SRSS_MAIN.
*
* \return
* - CY_SYSPM_SUCCESS - Successfully transitioned from ULP to LP mode.
* - CY_SYSPM_FAIL - The transition failed.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemTransitionUlpToLp(void);

/*******************************************************************************
* Function Name: Cy_SysPm_SystemTransitionLpToUlp
****************************************************************************//**
*
* Performs system transition from Low Power mode(LP) to Ultra Low Power mode(ULP) mode.
*
* \note This API is secure aware. See header subsection Secure Aware SYSPM for further details.
* The involved PPC regions is PROT_PERI0_SRSS_MAIN.
*
* \return
* - CY_SYSPM_SUCCESS - Successfully transitioned from LP to ULP mode.
* - CY_SYSPM_FAIL - The transition failed.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemTransitionLpToUlp(void);


#endif /* defined (CY_IP_MXS22SRSS) */

/*******************************************************************************
* Function Name: Cy_SysPm_GetDeepSleepMode
****************************************************************************//**
*
* Get the overall system's deepsleep mode - deepsleep or deepsleep-ram or deepsleep-off
*
* \return
* Returns \ref cy_en_syspm_deep_sleep_mode_t
*
* \note
* In a multi-core/multi-power domain architectures, CY_SYSPM_MODE_DEEPSLEEP_NONE
* will be returned by the API, if any of the following conditions are met ...
*
* 1) Main Power domains(PD0, PD1) are not at all configured for a particular DS.
*
* 2) A mix in DS states between power domains, for example
* PD0 configures deepsleep and PD1 configures deepsleep-RAM.
*
* \note
* This API should only be used after Cy_SysPm_SetDeepSleepMode, as it will give only
* the mode that is set by Cy_SysPm_SetDeepSleepMode.
*
* \note This API is secure aware. See header subsection Secure Aware SYSPM for further details.
* The involved PPC regions is PROT_PERI0_PWRMODE_PWRMODE.
*
*******************************************************************************/
cy_en_syspm_deep_sleep_mode_t Cy_SysPm_GetDeepSleepMode(void);


/*******************************************************************************
* Function Name: Cy_SysPm_GetBootMode
****************************************************************************//**
*
* Checks from which Deep Sleep mode the system has woke up.
*
* \return
* Returns CY_SYSPM_WARM_BOOT_MODE or CY_SYSPM_WARM_COLD_MODE, if system performs
* warm or cold, else return CY_SYSPM_POR_BOOT_MODE if its a normal(POR) boot.
*
* \note
* Use this API immediately after the boot, before writing any of the PPU
* registers,because this API depends on the programmed state of the PPU
* registers, so call it before the PPU registers get overwritten.
*
*******************************************************************************/
cy_en_syspm_boot_mode_t Cy_SysPm_GetBootMode(void);

/*******************************************************************************
* Function Name: Cy_SysPm_TriggerSoftReset
****************************************************************************//**
*
* Triggers the System Soft reset.
*
*******************************************************************************/
void Cy_SysPm_TriggerSoftReset(void);

/*******************************************************************************
* Function Name: Cy_SysPm_TriggerXRes
****************************************************************************//**
*
* Triggers the XRES  reset.
*
*******************************************************************************/
void Cy_SysPm_TriggerXRes(void);

#endif

/*******************************************************************************
* Function Name: Cy_SysPm_CpuEnterDeepSleep
****************************************************************************//**
*
* Sets executing CPU to the Deep Sleep mode.
*
* Puts the CPU executing the function into CPU Deep Sleep. For a single CPU
* devices the device will immediately transition to system Deep Sleep. For a
* dual CPU devices the device will transition to system Deep Sleep only after
* both CPUs are in CPU Deep Sleep power mode.
*
* Prior to entering the CPU Deep Sleep mode, all callbacks of the
* CY_SYSPM_DEEPSLEEP type with the CY_SYSPM_CHECK_READY parameter registered
* callbacks are called, allowing the driver to signal whether it is ready to
* enter the power mode. If any CY_SYSPM_DEEPSLEEP type with the
* CY_SYSPM_CHECK_READY parameter call returns CY_SYSPM_FAIL, the remaining
* callback CY_SYSPM_DEEPSLEEP type with the CY_SYSPM_CHECK_READY parameter are
* skipped. After the first CY_SYSPM_FAIL, all the CY_SYSPM_DEEPSLEEP callbacks
* that were previously executed before getting the CY_SYSPM_CHECK_FAIL are
* executed with the CY_SYSPM_CHECK_FAIL parameter. The CPU Deep Sleep mode is
* not entered and the Cy_SysPm_CpuEnterDeepSleep() function returns
* CY_SYSPM_FAIL.
*
* If all callbacks of the CY_SYSPM_DEEPSLEEP type with the CY_SYSPM_CHECK_READY
* parameter return CY_SYSPM_SUCCESS, then all callbacks of the
* CY_SYSPM_DEEPSLEEP type with the CY_SYSPM_CHECK_FAIL parameter calls are
* skipped. All callbacks of the CY_SYSPM_DEEPSLEEP type with the
* CY_SYSPM_BEFORE_TRANSITION parameter calls are then executed, allowing the
* peripherals to prepare for CPU Deep Sleep. The Deep Sleep mode is then
* entered. Any enabled interrupt can cause a wakeup from the Deep Sleep mode.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* For multi-CPU devices (except CY8C6xx6 and CY8C6xx7) there is a possible
* situation when a syscall operation (for example during flash read or write)
* is executing. If the CM0+ CPU tries to enter Deep Sleep, it will fail. All
* the CY_SYSPM_DEEPSLEEP callbacks that were previously executed, are executed
* with the CY_SYSPM_CHECK_FAIL parameter. Deep Sleep mode is not entered and
* the Cy_SysPm_CpuEnterDeepSleep() function returns CY_SYSPM_SYSCALL_PENDING.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* If the firmware attempts to enter this mode before the system is ready (that
* is, when PWR_CONTROL.LPM_READY = 0), then the CPU(s) will go into the CPU
* Sleep mode instead and automatically enter system Deep Sleep mode when the
* system is ready. On dual CPU devices, if one CPU enters CPU Deep Sleep and the
* other CPU remains active or is in CPU Sleep the first CPU will remain in CPU
* Deep Sleep. A CPU Deep Sleep is functionally identical to CPU Sleep.
*
* The device enters system Deep Sleep mode when all the CPU(s) are in CPU
* Deep Sleep, there are no busy peripherals, the debugger is not active, and the
* Deep Sleep power and reference are ready (PWR_CONTROL.LPM_READY=1).
*
* The peripherals that do not need a clock or that receive a clock from their
* external interface (e.g. I2C/SPI) may continue operating in system Deep Sleep.
* All circuits using current from Vccdpslp supply are limited by its maximum
* current specification of the Deep Sleep regulator.
*
* Wakeup occurs when an interrupt asserts from a Deep Sleep active peripheral.
* For more detail, see the corresponding peripheral's datasheet.
*
* For multi-core devices, CPU wakeup can also be performed using the Send Event
* (SEV) assembly instruction executed from the other active CPU. Such wakeup is
* expected only if the CPU Sleep power mode is done with WFE assembly
* instruction.
*
* \note
* For multi-CPU devices, the second CPU, if it did not participate in
* system wakeup, remains in CPU Deep Sleep mode. Any Deep Sleep capable
* interrupt routed to this CPU can also wake it.
*
* For more detail about switching into the system Deep Sleep power mode and
* debug, refer to the device TRM.
*
* A normal wakeup from the Deep Sleep power mode returns to either ULP or LP
* mode, depending on the previous state and programmed behavior for the
* particular wakeup interrupt. As soon as the system resumes LP or ULP mode the
* CPU(s) return to CPU Active or CPU Deep Sleep mode, depending on their
* configured wakeup settings.
*
* After wakeup from CPU Deep Sleep, all of the registered callbacks with
* CY_SYSPM_DEEPSLEEP type with CY_SYSPM_AFTER_TRANSITION are executed to return
* peripherals to active operation. The Cy_SysPm_CpuEnterDeepSleep() function
* returns CY_SYSPM_SUCCESS. No callbacks are executed with CY_SYSPM_DEEPSLEEP
* type with CY_SYSPM_BEFORE_TRANSITION or CY_SYSPM_AFTER_TRANSITION parameter,
* if Deep Sleep mode was not entered.
*
* To support control of callback execution order th following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.
*
* \note
* This function clears the reset reason before going to deep sleep
*
* \note This API is secure aware but when running on the core without TrustZone,
* there will be no special security-related behavior. See header subsection Secure
* Aware SYSPM for further details.
* The involved PPC regions is PROT_PERI0_SRSS_MAIN.
*
* \param waitFor
* Selects wait for action. See \ref cy_en_syspm_waitfor_t.
*
* \sideeffect
* For CY8C6xx6, CY8C6xx7 devices this function clears the Event Register of the
* CM4 CPU after wakeup from WFE.
*
* \sideeffect
* This function changes the slow and fast clock dividers right before
* entering into system Deep Sleep and restores these dividers after wakeup.
*
* \return
* Entered status, see \ref cy_en_syspm_status_t.
*
* \note
* The FLL/PLL are not restored right before the CPU(s) start executing the
* instructions after system Deep Sleep. This can affect the peripheral that is
* driven by PLL/FLL. Ensure that the PLL/FLL are properly restored (locked)
* after wakeup from System Deep Sleep. Refer to the
* \ref group_sysclk driver documentation for information about how to
* read the PLL/FLL lock statuses.
*
* \note The Arm BSD assembly instruction is not required in this function
* because the function implementation ensures the SLEEPDEEP bit of SCS register
* is settled prior executing the WFI/WFE instruction.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_CpuEnterDeepSleep
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_CpuEnterDeepSleep(cy_en_syspm_waitfor_t waitFor);

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_SystemEnterLp
****************************************************************************//**
*
* Sets device into system Low Power mode.
*
* Returns the system to the default LP mode by raising the core voltage.
* In the LP mode, the clock frequencies can be increased to t
he LP mode
* limitations. Refer to the device datasheet for frequency limitations in the
* LP mode. Approximate LP limit values - \ref group_syspm_lp_limitations.
*
* Prior to entering the system LP mode, all the registered CY_SYSPM_LP callbacks
* with CY_SYSPM_CHECK_READY parameter are called. This allows the driver to
* signal that it is not ready to enter the system LP mode. If any CY_SYSPM_LP
* callbacks with the CY_SYSPM_CHECK_READY parameter call return CY_SYSPM_FAIL,
* the remaining CY_SYSPM_LP callbacks with the
* CY_SYSPM_CHECK_READY parameter calls are skipped.
* All of the CY_SYSPM_LP callbacks with the CY_SYSPM_BEFORE_TRANSITION
* require to reduce the clock frequency before entering LP mode.
* All of the CY_SYSPM_LP callbacks with the CY_SYSPM_AFTER_TRANSITION
* may now increase the Clock frequency to the target for LP mode.
*
* After a CY_SYSPM_FAIL, all of the CY_SYSPM_LP callbacks with
* CY_SYSPM_CHECK_FAIL parameter are executed that correspond to the
* CY_SYSPM_LP callbacks with CY_SYSPM_CHECK_READY parameter that occurred up to
* the point of failure. System LP mode is not entered and the
* Cy_SysPm_SystemEnterLp() function returns CY_SYSPM_FAIL.
*
* If all CY_SYSPM_LP callbacks with the CY_SYSPM_CHECK_READY
* parameter return CY_SYSPM_SUCCESS, then all CY_SYSPM_LP callbacks with
* CY_SYSPM_CHECK_FAIL are skipped and all CY_SYSPM_LP callbacks with the
* CY_SYSPM_BEFORE_TRANSITION parameter are executed. This allows the
* peripherals to prepare for LP mode. The system LP mode is then entered.
*
* After entering the system LP mode, all of the registered
* CY_SYSPM_LP callbacks with the CY_SYSPM_AFTER_TRANSITION parameter
* are executed to complete preparing the peripherals for low power operation.
* The Cy_SysPm_SystemEnterLp() function returns CY_SYSPM_SUCCESS.
* No CY_SYSPM_LP callbacks with the CY_SYSPM_BEFORE_TRANSITION or
* CY_SYSPM_AFTER_TRANSITION parameter are executed if the system LP mode is not
* entered.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* \note It is not possible to transition directly between ULP and HP modes.
* The device must first be transitioned to LP mode and then to the desired mode.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* To support control of callback execution order th following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.
*
* \return
* - CY_SYSPM_SUCCESS - Entered the system LP mode or the device is already in LP mode.
* - CY_SYSPM_INVALID_STATE - The system LP mode was not set. The system LP mode
*   was not set because the protection context value is higher than zero
*   (PC > 0) or the device revision does not support modifying registers
*   (to enter LP mode) via syscall.
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
* - CY_SYSPM_FAIL - The system LP mode is not entered.
*   For the PSoC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSoC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemEnterLp
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemEnterLp(void);


/*******************************************************************************
* Function Name: Cy_SysPm_SystemEnterUlp
****************************************************************************//**
*
* Sets device into system Ultra Low Power mode.
*
* System ULP mode is similar to system LP mode. The difference is that the
* system is put under \ref group_syspm_ulp_limitations.
*
* Before entering system ULP mode, the user must configure the system so
* the maximum clock frequencies are less than the ULP mode specifications
* presented in the device datasheet. Refer to the device datasheet for
* the maximum clock limitations in the ULP mode with reduced core supply
* regulator voltages.
*
* Prior to entering system ULP mode, all the registered CY_SYSPM_ULP callbacks
* with CY_SYSPM_CHECK_READY parameter are called. This allows the driver to
* signal if it is not ready to enter system ULP mode. If any CY_SYSPM_ULP
* callback with the CY_SYSPM_CHECK_READY parameter call returns CY_SYSPM_FAIL,
* the remaining CY_SYSPM_ULP callbacks with the CY_SYSPM_CHECK_READY parameter
* are skipped.
*
* All of the CY_SYSPM_ULP callbacks with the CY_SYSPM_BEFORE_TRANSITION
* require to reduce the clock frequency before entering ULP mode.
* All of the CY_SYSPM_ULP callbacks with the CY_SYSPM_AFTER_TRANSITION
* may now increase the Clock frequency to the target for ULP mode.
*
* After a CY_SYSPM_FAIL, all of the CY_SYSPM_ULP callbacks with the
* CY_SYSPM_CHECK_FAIL parameter are executed that correspond to the
* CY_SYSPM_ULP callback with CY_SYSPM_CHECK_READY parameter that occurred up to
* the point of failure. System ULP mode is not entered
* and the Cy_SysPm_SystemEnterUlp() function returns CY_SYSPM_FAIL.
*
* If all CY_SYSPM_ULP callbacks with the CY_SYSPM_CHECK_READY
* parameter return CY_SYSPM_SUCCESS, then all CY_SYSPM_ULP
* callbacks with CY_SYSPM_CHECK_FAIL calls are skipped and all CY_SYSPM_ULP
* callbacks with the CY_SYSPM_BEFORE_TRANSITION parameter are executed. This
* allows preparation for ULP. The system ULP mode is then entered.
*
* After entering system ULP, all of the registered CY_SYSPM_ULP callbacks with
* the CY_SYSPM_AFTER_TRANSITION parameter are executed to complete preparing the
* peripherals for ULP operation. The Cy_SysPm_SystemEnterUlp() function
* returns CY_SYSPM_SUCCESS. No CY_SYSPM_ULP callbacks with the
* CY_SYSPM_BEFORE_TRANSITION or CY_SYSPM_AFTER_TRANSITION parameter are
* executed, if ULP mode is not entered.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* \note It is not possible to transition directly between ULP and HP modes.
* The device must first be transitioned to LP mode and then to the desired mode.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* To support control of callback execution order th following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.
*
* \return
* - CY_SYSPM_SUCCESS - Entered the system ULP mode or the device is already in ULP mode.
* - CY_SYSPM_INVALID_STATE - System ULP mode was not set. The ULP mode was not
*   set because the protection context value is higher than zero (PC > 0) or the
*   device revision does not support modifying registers (to enter system
*   ULP mode) via syscall.
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
* - CY_SYSPM_FAIL - The system ULP mode is not entered.
*   For the PSoC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSoC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemEnterUlp
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemEnterUlp(void);


#if defined (CY_IP_MXS22SRSS) || defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL) || defined (CY_DOXYGEN)

#if defined (CY_IP_MXS22SRSS)
/*******************************************************************************
* Function Name: Cy_SysPm_SystemEnterHp
****************************************************************************//**
*
* Sets device into System High Performance mode.
*
* System HP mode is similar to system LP and ULP mode. The difference is that the
* system is put at voltage which are above LP and ULP.
*
* Before entering system HP mode, the user must configure the system so
* the maximum clock frequencies are at HP mode specifications
* presented in the device datasheet. Refer to the device datasheet for
* the maximum clock limitations in the HP mode with reduced core supply
* regulator voltages.
*
* Prior to entering system HP mode, all the registered CY_SYSPM_HP callbacks
* with CY_SYSPM_CHECK_READY parameter are called. This allows the driver to
* signal if it is not ready to enter system HP mode. If any CY_SYSPM_HP
* callback with the CY_SYSPM_CHECK_READY parameter call returns CY_SYSPM_FAIL,
* the remaining CY_SYSPM_HP callbacks with the CY_SYSPM_CHECK_READY parameter
* are skipped.
* All of the CY_SYSPM_HP callbacks with the CY_SYSPM_BEFORE_TRANSITION
* require to reduce the clock frequency before entering HP mode.
* All of the CY_SYSPM_HP callbacks with the CY_SYSPM_AFTER_TRANSITION
* may now increase the Clock frequency to the target for HP mode.
*
* After a CY_SYSPM_FAIL, all of the CY_SYSPM_HP callbacks with the
* CY_SYSPM_CHECK_FAIL parameter are executed that correspond to the
* CY_SYSPM_HP callback with CY_SYSPM_CHECK_READY parameter that occurred up to
* the point of failure. System HP mode is not entered
* and the Cy_SysPm_SystemEnterHp() function returns CY_SYSPM_FAIL.
*
* If all CY_SYSPM_HP callbacks with the CY_SYSPM_CHECK_READY
* parameter return CY_SYSPM_SUCCESS, then all CY_SYSPM_HP
* callbacks with CY_SYSPM_CHECK_FAIL calls are skipped and all CY_SYSPM_HP
* callbacks with the CY_SYSPM_BEFORE_TRANSITION parameter are executed. This
* allows preparation for HP. The system HP mode is then entered.
*
* After entering system HP, all of the registered CY_SYSPM_HP callbacks with
* the CY_SYSPM_AFTER_TRANSITION parameter are executed to complete preparing the
* peripherals for HP operation. The Cy_SysPm_SystemEnterUlp() function
* returns CY_SYSPM_SUCCESS. No CY_SYSPM_HP callbacks with the
* CY_SYSPM_BEFORE_TRANSITION or CY_SYSPM_AFTER_TRANSITION parameter are
* executed, if HP mode is not entered.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* \note It is not possible to transition directly between ULP and HP modes.
* The device must first be transitioned to LP mode and then to the desired mode.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* To support control of callback execution order th following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.
*
* \return
* - CY_SYSPM_SUCCESS - Entered the system HP mode or the device is already in HP mode.
* - CY_SYSPM_INVALID_STATE - System HP mode was not set. The HP mode was not
*   set because the protection context value is higher than zero (PC > 0) or the
*   device revision does not support modifying registers (to enter system
*   HP mode) via syscall.
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
* - CY_SYSPM_FAIL - The system HP mode is not entered.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemEnterHp
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemEnterHp(void);

#endif


#if defined (CY_IP_MXS22SRSS)
/*******************************************************************************
* Function Name: Cy_SysPm_SetRamTrimsPreDs
****************************************************************************//**
*
* Sets RAM trims before entering Deepsleep.
*
*******************************************************************************/
void Cy_SysPm_SetRamTrimsPreDs(void);

/*******************************************************************************
* Function Name: Cy_SysPm_SetRamTrimsPostDs
****************************************************************************//**
*
* Sets RAM trims After exiting Deepsleep.
*
*******************************************************************************/
void Cy_SysPm_SetRamTrimsPostDs(void);

#endif

#endif /* CY_IP_MXS22SRSS || defined (CY_DOXYGEN)*/


#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) ||
           (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))*/

/*******************************************************************************
* Function Name: Cy_SysPm_SystemEnterHibernate
****************************************************************************//**
*
* Sets the device into system Hibernate mode.
*
* Puts the device into the system Hibernate power mode. Prior to entering
* Hibernate mode, all callbacks of the CY_SYSPM_HIBERNATE type are executed.
*
* First, callbacks of the CY_SYSPM_HIBERNATE type are called with the
* CY_SYSPM_CHECK_READY parameter. This allows the callback to signal that the
* driver is not ready to enter the system Hibernate power mode. If any of the
* callback return CY_SYSPM_FAIL, the remaining CY_SYSPM_HIBERNATE callbacks are
* skipped. In this case, all of the callbacks that have already been called are
* called again with the CY_SYSPM_CHECK_FAIL parameter. System Hibernate mode is
* not entered and the Cy_SysPm_SystemEnterHibernate() function returns
* CY_SYSPM_FAIL.
*
* If all CY_SYSPM_HIBERNATE callbacks with the CY_SYSPM_CHECK_READY parameter
* return CY_SYSPM_SUCCESS, then all CY_SYSPM_HIBERNATE callbacks with
* CY_SYSPM_CHECK_FAIL calls are skipped and all CY_SYSPM_HIBERNATE callbacks
* with CY_SYSPM_BEFORE_TRANSITION parameter are executed allowing the
* peripherals to prepare for system Hibernate.
*
* The I/O output state is automatically frozen by hardware system and Hibernate
* mode is then entered. In Hibernate mode, all internal supplies are off and no
* internal state is retained. The only exception is resources powered by the
* Vbackup domain continue to operate, if enabled. For multi-CPU devices, there
* is no handshake with the CPUs and the chip will enter Hibernate power
* mode immediately.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* Wakeup from system Hibernate is triggered by toggling the wakeup pin(s), WDT
* match, or back-up domain RTC alarm expiration, depending on how the they are
* configured. A wakeup causes a normal boot procedure.
* To configure the wakeup pin(s), a digital input pin must be configured, and
* resistively pulled up or down to the inverse state of the wakeup polarity. To
* distinguish a Hibernate mode from a general reset wakeup event, the
* Cy_SysLib_GetResetReason() function can be used. The wakeup pin and low-power
* comparators are active-low by default. The wakeup pin or the LPComparators
* polarity can be changed with the \ref Cy_SysPm_SetHibernateWakeupSource()
* function.
* This function call will not return if system Hibernate mode is entered.
* The CY_SYSPM_HIBERNATE callbacks with the CY_SYSPM_AFTER_TRANSITION parameter
* are never executed.
*
* This function freezes the I/O pins implicitly. Entering system Hibernate mode
* before freezing the I/O pins is not possible. The I/O pins remain frozen after
* waking from Hibernate mode until the firmware unfreezes them with
* a \ref Cy_SysPm_IoUnfreeze() function call.
*
* Boot firmware should reconfigure the I/O pins as required by the application
* prior unfreezing them.
*
* To support control of callback execution order the following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.
*
* \note This API is secure aware but when running on the core without TrustZone,
* there will be no special security-related behavior. See header subsection Secure
* Aware SYSPM for further details.
* If Secure Aware SYSPM is enabled and the corresponding SYSPM PPC region is secured,
* we don't allow the CM55 to request hibernate entry on its own, since that is a system-wide impact.
* The involved PPC regions are PROT_PERI0_SRSS_MAIN/PROT_PERI0_SRSS_HIB_DATA.
* Both PROT_PERI0_SRSS_MAIN/PROT_PERI0_SRSS_HIB_DATA should be either secure or non-secure.
*
* \return
* Entered status, see \ref cy_en_syspm_status_t.
* For the PSoC 64 devices there are possible situations when function returns
* the PRA error status code. This is because for PSoC 64 devices the function
* uses the PRA driver to change the protected registers. Refer to
* \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemEnterHibernate
*
* \note In order to get correct value of hibernate wake up cause at next hibernation,
* upper layer have to clear the interrupt register first
* and then clear the hibernate wake up cause \ref Cy_SysPm_ClearHibernateWakeupCause()
* for the current hibernation.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemEnterHibernate(void);


/*******************************************************************************
* Function Name: Cy_SysPm_SetHibernateWakeupSource
****************************************************************************//**
*
* This function configures sources to wake up the device from the system
* Hibernate power mode. Sources can be wakeup pins, LPComparators, Watchdog (WDT)
* interrupt, or a Real-Time clock (RTC) alarm (interrupt). Wakeup from system
* Hibernate always results in a device reset and normal boot process.
*
* Wakeup pins:
*
* A wakeup is supported by up to two pins with programmable polarity. These pins
* are typically connected to the GPIO pins or on-chip peripherals under some
* conditions. See device datasheet for specific pin connections.
* Setting the wakeup pin to this level will cause a wakeup from system Hibernate
* mode. The wakeup pins are active-low by default.
*
* LPComparators:
*
* A wakeup is supported by up to two LPComps with programmable polarity.
* Setting the LPComp to this level will cause a wakeup from system Hibernate
* mode. The wakeup LPComps are active-low by default.
*
* \note The low-power comparators should be configured and enabled before
* switching to system Hibernate mode. Refer to the LPComp
* driver description for more detail.
*
* Watchdog Timer:
*
* \note The WDT should be configured and enabled before entering to system
* Hibernate mode.
*
* A wakeup is performed by a WDT interrupt.
*
* Real-time Clock:
*
* A wakeup is performed by the RTC alarm.
* Refer to the Real-Time Clock (RTC) driver description for more detail.
*
* For information about wakeup sources and their assignment in specific
* devices, refer to the appropriate device TRM.
*
* \param wakeupSource
* The source to be configured as a wakeup source from
* the system Hibernate power mode, see \ref cy_en_syspm_hibernate_wakeup_source_t.
* The input parameter values can be ORed. For example, if you want to enable
* LPComp0 (active high) and WDT, call this function:
* Cy_SysPm_SetHibernateWakeupSource(CY_SYSPM_HIBERNATE_LPCOMP0_HIGH | CY_SYSPM_HIBERNATE_WDT).
*
* \warning Do not call this function with different polarity levels for the same
* wakeup source. For example, do not call a function like this:
* Cy_SysPm_SetHibernateWakeupSource(CY_SYSPM_HIBERNATE_LPCOMP0_LOW, CY_SYSPM_HIBERNATE_LPCOMP0_HIGH);
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SetHibernateWakeupSource
*
*******************************************************************************/
void Cy_SysPm_SetHibernateWakeupSource(uint32_t wakeupSource);


/*******************************************************************************
* Function Name: Cy_SysPm_ClearHibernateWakeupSource
****************************************************************************//**
*
* This function disables a wakeup source that was previously configured to
* wake up the device from the system Hibernate mode.
*
* \param wakeupSource
* For the source to be disabled, see \ref cy_en_syspm_hibernate_wakeup_source_t.
* The input parameters values can be ORed. For example, if you want to disable
* LPComp0 (active high) and WDT call this function:
* Cy_SysPm_ClearHibernateWakeupSource(CY_SYSPM_HIBERNATE_LPCOMP0_HIGH | CY_SYSPM_HIBERNATE_WDT).
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_ClearHibernateWakeupSource
*
*******************************************************************************/
void Cy_SysPm_ClearHibernateWakeupSource(uint32_t wakeupSource);

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION == 3u) && defined (CY_IP_MXS40SRSS_VERSION_MINOR) && (CY_IP_MXS40SRSS_VERSION_MINOR >= 3u)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_GetHibernateWakeupCause
****************************************************************************//**
*
* This function gets the wakeup cause for Hibernate mode.
*
* \return
* Wakeup Reason \ref cy_en_syspm_hibernate_wakeup_source_t
*
*******************************************************************************/
cy_en_syspm_hibernate_wakeup_source_t Cy_SysPm_GetHibernateWakeupCause(void);

/*******************************************************************************
* Function Name: Cy_SysPm_ClearHibernateWakeupCause
****************************************************************************//**
*
* This function Clears the wakeup cause register.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_ClearHibernateWakeupCause(void)
{
    uint32_t temp = SRSS_PWR_HIB_WAKE_CAUSE;
    SRSS_PWR_HIB_WAKE_CAUSE = temp;
}

#endif



/*******************************************************************************
* Function Name: Cy_SysPm_SystemSetMinRegulatorCurrent
****************************************************************************//**
*
* Sets the system into minimum core regulator current mode. This mode limits
* maximum current available for the system core logic.
*
* Minimum regulator current mode modifies operation of the system in LP or ULP
* modes to further reduce current consumption. If the system current is below
* datasheet current limits for the active core voltage regulator (LDO or Buck),
* this mode may be entered. The user is responsible for ensuring the
* regulator current limit is met in their application.
*
* When in minimum regulator current mode, the following system resources are
* also set to their LP mode:
* - Linear regulator (If LDO is active regulator)
* - POR/BOD circuit
* - Bandgap reference circuit
* - Reference buffer circuit
* - Current reference circuit
*
* The LDO and Buck current limits must be met prior to entering this
* mode. If these are not met, the device may brown out, resulting in an
* exception or reset. These changes also reduce power supply rejection of
* the affected system resources, which can result in increased noise or response
* time. These effects must be evaluated in each application.
*
* \return
* See \ref cy_en_syspm_status_t.
* - CY_SYSPM_SUCCESS - Minimum regulator current mode was set
* - CY_SYSPM_CANCELED - The power circuits were not ready to enter into
*   minimum current mode. You should call the function again.
*   For the PSoC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSoC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* Refer to device datasheet for maximum current value in regulator minimum
* current mode.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemSetMinRegulatorCurrent
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemSetMinRegulatorCurrent(void);


/*******************************************************************************
* Function Name: Cy_SysPm_SystemSetNormalRegulatorCurrent
****************************************************************************//**
*
* Sets the system to normal regulator current mode.
*
* Normal regulator current mode modifies operation of the system in LP or ULP
* modes to provide maximum core current consumption. If the LDO core regulator
* is in use, the normal mode output current limits may be used. If the buck
* regulator is in use, its reduced current output limits still apply.
*
* When in normal regulator current mode, the following system resources are set
* to their normal mode:
* - Linear regulator (If LDO is active regulator)
* - POR/BOD circuit
* - Bandgap reference circuit
* - Reference buffer circuit
* - Current reference circuit
*
* \return
* - CY_SYSPM_SUCCESS - Normal regulator current mode was set
* - CY_SYSPM_TIMEOUT - The timeout occurred because device was not
*   ready to enter into the normal regulator current mode
*   For the PSoC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSoC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemSetNormalRegulatorCurrent
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemSetNormalRegulatorCurrent(void);


/*******************************************************************************
* Function Name: Cy_SysPm_CpuSleepOnExit
****************************************************************************//**
*
* This function configures the sleep-on-exit feature of the CPU.
*
* This API sets the SLEEPONEXIT bit of the SCR register.
*
* When the sleep-on-exit feature is enabled (the SLEEPONEXIT bit is set),
* the CPU wakes up to service the interrupt and then immediately goes
* back to sleep. Because of this, the unstacking process is not carried out, so
* this feature is useful for interrupt driven application and helps to
* reduce unnecessary stack push and pop operations.
* The CPU does not go to sleep if the interrupt handler returns to
* another interrupt handler (nested interrupt).
* You can use this feature in applications that require the CPU to only run
* when an interrupt occurs.
*
* When the sleep-on-exit feature is disabled (the SLEEPONEXIT bit is cleared),
* the CPU returns back to the main thread after servicing the interrupt
* without going back to sleep.
*
* Refer to the Arm documentation about the sleep-on-exit feature and
* SLEEPONEXIT in the SCR register.
*
* \param enable
* - True if enable sleep-on-exit feature.
* - False if disable sleep-on-exit feature.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_CpuSleepOnExit
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_CpuSleepOnExit(bool enable)
{
    if(enable)
    {
        /* Enable sleep-on-exit feature */
        SCB_SCR |= SCB_SCR_SLEEPONEXIT_Msk;
    }
    else
    {
        /* Disable sleep-on-exit feature */
        SCB_SCR &= (uint32_t) ~(SCB_SCR_SLEEPONEXIT_Msk);
    }
}

/** \} group_syspm_functions_power */


/**
* \addtogroup group_syspm_functions_power
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysPm_CpuSendWakeupEvent
****************************************************************************//**
*
* Sends the SEV (Send Event) ARM instruction to the system.
*
* \note In secure settings, this API is safe to call from both a secure and
* non-secure CPU state. See header subsection Secure Aware SYSPM for further details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_CpuSendWakeupEvent
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_CpuSendWakeupEvent(void)
{
    __SEV();
}

#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_SystemIsMinRegulatorCurrentSet
****************************************************************************//**
*
* Check whether the system regulator is set to minimal current mode.
*
* \return
* - True - system is in regulator minimum current mode.
* - False - system is in normal regulator current mode.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemSetNormalRegulatorCurrent
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysPm_SystemIsMinRegulatorCurrentSet(void)
{
    return ((0U == _FLD2VAL(SRSS_PWR_CTL2_REFSYS_VBUF_DIS, SRSS_PWR_CTL2)) ? false : true);
}
#endif /* defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN) */
/** \} group_syspm_functions_power */

/**
* \addtogroup group_syspm_functions_ldo
* \{
*/


/*******************************************************************************
* Function Name: Cy_SysPm_LdoSetMode
****************************************************************************//**
*
* Configures the core LDO regulator operating mode to one of three modes.
* Disabled - turns off the LDO regulator and should be selected only after the
* Buck regulator is operating. Normal mode configures the LDO for operation at
* the maximum output current limit. Minimal current mode optimizes the LDO at a
* reduced output current limit. Specific device current limits can be found in
* the device datasheet.
*
* \param mode
* The desired LDO regulator operating mode.
* See \ref cy_en_syspm_ldo_mode_t mode
*
* \return
* - CY_SYSPM_SUCCESS - Requested regulator current mode was set
* - CY_SYSPM_CANCELED - The power circuits were not ready to enter into
*   minimum current mode. You should try to call the function again
* - CY_SYSPM_TIMEOUT - Timeout occurred because of active reference was not
*   ready to enter into the normal regulator current mode
* - CY_SYSPM_FAIL - incorrect mode value was passed
*   For the PSoC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSoC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* \sideeffect
* For PSoC 64 series devices CY_SYSPM_LDO_MODE_DISABLED mode is not supported.
* Use \ref Cy_SysPm_BuckEnable() instead.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_LdoSetMode(cy_en_syspm_ldo_mode_t mode);


/*******************************************************************************
* Function Name: Cy_SysPm_LdoGetMode
****************************************************************************//**
*
* Returns the current core LDO regulator operating mode.
*
* \return
* The LDO regulator operating mode.
* See \ref cy_en_syspm_ldo_mode_t mode
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_ldo_mode_t Cy_SysPm_LdoGetMode(void)
{
    cy_en_syspm_ldo_mode_t retVal;

    if (Cy_SysPm_SystemIsMinRegulatorCurrentSet())
    {
        retVal = CY_SYSPM_LDO_MODE_MIN;
    }
    else
    {
        retVal = CY_SYSPM_LDO_MODE_NORMAL;
    }

    return retVal;
}

/** \} group_syspm_functions_ldo */

/**
* \addtogroup group_syspm_functions_callback
* \{
*/


/*******************************************************************************
* Function Name: Cy_SysPm_RegisterCallback
****************************************************************************//**
*
* Registers a new syspm callback.
*
* A callback is a function called after an event in the driver or
* middleware module has occurred. The handler callback API will be executed if
* the specific event occurs. SysPm callbacks are called when changing power
* modes. See \ref cy_stc_syspm_callback_t.
*
* \note The registered callbacks are executed in two orders, based on callback
* mode \ref cy_en_syspm_callback_mode_t. For modes CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION, the order is same order as callbacks were
* registered.
* For modes CY_SYSPM_AFTER_TRANSITION and CY_SYSPM_CHECK_FAIL, the order is
* reverse as the order callbacks were registered.
*
* \param handler
* The address of the syspm callback structure.
* See \ref cy_stc_syspm_callback_t.
*
* \return
* - True if a callback was registered.
* - False if a callback was not registered.
*
* \note Do not modify the registered structure in run-time.
* \warning After being registered, the SysPm callback structures must be
* allocated during power mode transition.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Func_Declaration
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Params_Declaration
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Structure_Declaration
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Func_Implementation
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_RegisterCallback
*
*******************************************************************************/
bool Cy_SysPm_RegisterCallback(cy_stc_syspm_callback_t *handler);


/*******************************************************************************
* Function Name: Cy_SysPm_UnregisterCallback
****************************************************************************//**
*
* This function unregisters a callback.
*
* The registered callback can be unregistered and the function returns true.
* Otherwise, false is returned.
*
* \param handler The item that should be unregistered.
* See \ref cy_stc_syspm_callback_t.
*
* \return
* - True if callback was unregistered.
* - False if it was not unregistered or no callbacks are registered.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_UnregisterCallback
*
*******************************************************************************/
bool Cy_SysPm_UnregisterCallback(cy_stc_syspm_callback_t const *handler);


/*******************************************************************************
* Function Name: Cy_SysPm_ExecuteCallback
****************************************************************************//**
*
* The function executes all registered callbacks with provided type and mode.
* \note This low-level function is being used by \ref Cy_SysPm_CpuEnterSleep,
* \ref Cy_SysPm_CpuEnterDeepSleep, \ref Cy_SysPm_SystemEnterHibernate,
* \ref Cy_SysPm_SystemEnterUlp and \ref Cy_SysPm_SystemEnterLp API functions.
* However, it might be also useful as an independent API function in some custom
* applications.
*
* \note The registered callbacks will be executed in order based on
* \ref cy_en_syspm_callback_type_t value. There are two possible callback
* execution orders:
* * From first registered to last registered. This order applies to
*   callbacks with mode CY_SYSPM_CHECK_READY and CY_SYSPM_BEFORE_TRANSITION.
* * Backward flow execution:
*   - From last registered to the first registered. This order applies
*     to callbacks with mode CY_SYSPM_AFTER_TRANSITION.
*   - From last called to the first registered callback. This order applies
*     to callbacks with mode CY_SYSPM_CHECK_FAIL. Note that, the last called
*     callback function  that generated the CY_SYSPM_CHECK_FAIL is skipped when
*     mode CY_SYSPM_CHECK_FAIL. This is because the callback that returns
*     CY_SYSPM_FAIL already knows that it failed and will not take any action
*     that requires correction.
*
* If no callbacks are registered, returns CY_SYSPM_SUCCESS.
*
* \param type
* The callback type. See \ref cy_en_syspm_callback_type_t.
*
* \param mode
* The callback mode. See \ref cy_en_syspm_callback_mode_t.
*
* \return
* - CY_SYSPM_SUCCESS if callback successfully completed or nor callbacks
*   registered.
* - CY_SYSPM_FAIL one of the executed callback(s) returned fail.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_ExecuteCallback
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_ExecuteCallback(cy_en_syspm_callback_type_t type, cy_en_syspm_callback_mode_t mode);


/*******************************************************************************
* Function Name: Cy_SysPm_GetFailedCallback
****************************************************************************//**
*
* Reads the result of the callback execution after the power mode functions
* execution.
*
* This function reads the value of the pointer that stores the result of callback
* execution. It takes power mode as the parameter and returns the address of the
* callback configuration structure in the case of failure or NULL in the case of
* success. This address of the failed callback allows finding the callback that
* blocks entering power mode.
*
* \param type
* Power mode for which a callback execution result is required.
*
* \return
* - The address of the callback configuration structure if the callback handler
* function failed.
* - NULL if the callback skipped or executed successfully.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_GetFailedCallback
*
*******************************************************************************/
cy_stc_syspm_callback_t* Cy_SysPm_GetFailedCallback(cy_en_syspm_callback_type_t type);
/** \} group_syspm_functions_callback */

/**
* \addtogroup group_syspm_functions_power_status
* \{
*/
#if defined (CY_IP_MXS40SRSS)  || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || defined (CY_DOXYGEN)

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_IsSystemUlp
****************************************************************************//**
*
* Checks if the system is in ULP mode.
*
* \return
* - True the system is in ULP mode.
* - False the system is is not ULP mode.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_IsSystemUlp
*
*******************************************************************************/
bool Cy_SysPm_IsSystemUlp(void);
#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) */

#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) ||defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_IsSystemLp
****************************************************************************//**
*
* Checks if the system is in LP mode.
*
* \return
* - True the system is in LP mode.
* - False the system is not in LP mode.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_IsSystemLp
*
*******************************************************************************/
bool Cy_SysPm_IsSystemLp(void);
#endif


#if defined (CY_IP_MXS22SRSS)  || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_IsSystemHp
****************************************************************************//**
*
* Checks if the system is in HP mode.
*
* \return
* - True the system is in HP mode.
* - False the system is not in HP mode.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_IsSystemHp
*
*******************************************************************************/
bool Cy_SysPm_IsSystemHp(void);


#endif



#endif


#if defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_Cm33IsActive
****************************************************************************//**
*
* Checks if CM33 is in the active mode.
*
* \return
* true - if CM33 is in the active mode, false - if the CM33 is not in active mode.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysPm_Cm33IsActive(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_CM33_ACTIVE) != 0u);
}


/*******************************************************************************
* Function Name: Cy_SysPm_Cm33IsSleep
****************************************************************************//**
*
* Checks if the CM33 is in the sleep mode.
*
* \return
* true - if the CM33 is in the sleep mode,
* false - if the CM33 is not in the sleep mode.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysPm_Cm33IsSleep(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_CM33_SLEEP) != 0u);
}


/*******************************************************************************
* Function Name: Cy_SysPm_Cm33IsDeepSleep
****************************************************************************//**
*
* Checks if the CM33 is in the deep sleep mode.
*
* \return
* true - if CM33 is in the deep sleep mode, false - if the CM33 is not in
* the deep sleep mode.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysPm_Cm33IsDeepSleep(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_CM33_DEEPSLEEP) != 0u);
}

/*******************************************************************************
* Function Name: Cy_SysPm_Cm55IsActive
****************************************************************************//**
*
* Checks if CM55 is in the active mode.
*
* \return
* true - if CM55 is in the active mode, false - if the CM55 is not in active mode.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysPm_Cm55IsActive(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_CM55_ACTIVE) != 0u);
}


/*******************************************************************************
* Function Name: Cy_SysPm_Cm55IsSleep
****************************************************************************//**
*
* Checks if the CM55 is in the sleep mode.
*
* \return
* true - if the CM55 is in the sleep mode,
* false - if the CM55 is not in the sleep mode.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysPm_Cm55IsSleep(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_CM55_SLEEP) != 0u);
}


/*******************************************************************************
* Function Name: Cy_SysPm_Cm55IsDeepSleep
****************************************************************************//**
*
* Checks if the CM55 is in the deep sleep mode.
*
* \return
* true - if CM55 is in the deep sleep mode, false - if the CM55 is not in
* the deep sleep mode.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysPm_Cm55IsDeepSleep(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_CM55_DEEPSLEEP) != 0u);
}

#endif

/** \} group_syspm_functions_power_status */



#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/**
* \addtogroup group_syspm_functions_buck
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckStatus
****************************************************************************//**
*
* Get the status of Core Buck Regulator
*
* \return
* Gets enum value of type \ref cy_en_syspm_status_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_status_t Cy_SysPm_CoreBuckStatus(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;
    uint32_t syspmCbuckRetry = CY_SYSPM_CBUCK_BUSY_RETRY_COUNT;

    while((_FLD2VAL(SRSS_PWR_CBUCK_STATUS_PMU_DONE, SRSS_PWR_CBUCK_STATUS) == 0U) && (syspmCbuckRetry != 0U))
    {
        syspmCbuckRetry--;
        Cy_SysLib_DelayUs(CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_US);
    }

    if(syspmCbuckRetry != 0UL)
    {
        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckSetVoltage
****************************************************************************//**
*
* Set the Core Buck Regulator Voltage
*
* \param voltage
* Pick from \ref cy_en_syspm_core_buck_voltage_t
*
* \return
* see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_status_t Cy_SysPm_CoreBuckSetVoltage(cy_en_syspm_core_buck_voltage_t voltage)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(voltage));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL, SRSS_PWR_CBUCK_CTL_CBUCK_VSEL, voltage);

    return Cy_SysPm_CoreBuckStatus();
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckGetVoltage
****************************************************************************//**
*
* Get the Core Buck Regulator Voltage
*
* \return
* Gets enum value of type \ref cy_en_syspm_core_buck_voltage_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_core_buck_voltage_t Cy_SysPm_CoreBuckGetVoltage(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_voltage_t enum.');
    return (cy_en_syspm_core_buck_voltage_t)(_FLD2VAL(SRSS_PWR_CBUCK_CTL_CBUCK_VSEL, SRSS_PWR_CBUCK_CTL));
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckSetMode
****************************************************************************//**
*
* Set the Core Buck Regulator mode
*
* \param mode
* Pick from \ref cy_en_syspm_core_buck_mode_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_CoreBuckSetMode(cy_en_syspm_core_buck_mode_t mode)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_MODE_VALID(mode));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL, SRSS_PWR_CBUCK_CTL_CBUCK_MODE, mode);
}


/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckGetMode
****************************************************************************//**
*
* Get the Core Buck Regulator Mode
*
* \return
* Gets enum value of type \ref cy_en_syspm_core_buck_mode_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_core_buck_mode_t Cy_SysPm_CoreBuckGetMode(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_mode_t enum.');
    return (cy_en_syspm_core_buck_mode_t)(_FLD2VAL(SRSS_PWR_CBUCK_CTL_CBUCK_MODE, SRSS_PWR_CBUCK_CTL));
}


#if defined (CY_IP_MXS22SRSS)  || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckDpslpSetVoltage
****************************************************************************//**
*
* Set the Deepsleep mode Core Buck Regulator Voltage
*
* \param voltage
* Pick from \ref cy_en_syspm_core_buck_voltage_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_status_t Cy_SysPm_CoreBuckDpslpSetVoltage(cy_en_syspm_core_buck_voltage_t voltage)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(voltage));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_DPSLP_CTL, SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_VSEL, voltage);

    return Cy_SysPm_CoreBuckStatus();
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckDpslpGetVoltage
****************************************************************************//**
*
* Get the Deepsleep Core Buck Regulator Voltage
*
* \return
* Gets enum value of type \ref cy_en_syspm_core_buck_voltage_t
*
* \return
* see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_core_buck_voltage_t Cy_SysPm_CoreBuckDpslpGetVoltage(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_voltage_t enum.');
    return (cy_en_syspm_core_buck_voltage_t)(_FLD2VAL(SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_VSEL, SRSS_PWR_CBUCK_DPSLP_CTL));
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckDpslpSetMode
****************************************************************************//**
*
* Set the Deepsleep Core Buck Regulator mode
*
* \param mode
* Pick from \ref cy_en_syspm_core_buck_mode_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_CoreBuckDpslpSetMode(cy_en_syspm_core_buck_mode_t mode)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_MODE_VALID(mode));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_DPSLP_CTL, SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_MODE, mode);
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckDpslpGetMode
****************************************************************************//**
*
* Get the Deepsleep Core Buck Regulator Mode
*
* \return
* Gets enum value of type \ref cy_en_syspm_core_buck_mode_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_core_buck_mode_t Cy_SysPm_CoreBuckDpslpGetMode(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_mode_t enum.');
    return (cy_en_syspm_core_buck_mode_t)(_FLD2VAL(SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_MODE, SRSS_PWR_CBUCK_DPSLP_CTL));
}


/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckDpslpEnableOverride
****************************************************************************//**
*
* Enable the Override feature for core buck during Deepsleep
*
* \param enable
* true - enable, false - disable
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_CoreBuckDpslpEnableOverride(bool enable)
{
    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_DPSLP_CTL, SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_OVERRIDE, ((enable) ? 1UL : 0UL));
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckDpslpIsOverrideEnabled
****************************************************************************//**
*
* Checks if Override feature of core buck during deepsleep is enabled or not.
*
* \return
* True if enabled, False if disabled.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysPm_CoreBuckDpslpIsOverrideEnabled(void)
{
    return (_FLD2BOOL(SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_OVERRIDE, SRSS_PWR_CBUCK_DPSLP_CTL)? true : false);
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckSetProfile
****************************************************************************//**
*
* Set the Core Buck Regulator Profile
*
* \param profile
* Pick from \ref cy_en_syspm_core_buck_profile_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_CoreBuckSetProfile(cy_en_syspm_core_buck_profile_t profile)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_PROFILE_VALID(profile));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL2, SRSS_PWR_CBUCK_CTL2_CBUCK_PROFILE, profile);
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckGetProfile
****************************************************************************//**
*
* Get the Core Buck Regulator Profile
*
* \return
* Gets enum value of type \ref cy_en_syspm_core_buck_profile_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_core_buck_profile_t Cy_SysPm_CoreBuckGetProfile(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_profile_t enum.');
    return (cy_en_syspm_core_buck_profile_t)(_FLD2VAL(SRSS_PWR_CBUCK_CTL2_CBUCK_PROFILE, SRSS_PWR_CBUCK_CTL2));
}

/*******************************************************************************
* Function Name: Cy_SysPm_RetLdoStatus
****************************************************************************//**
*
* Get the status of RETLDO Regulator
*
* \return
* Gets enum value of type \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_RetLdoStatus(void);

/*******************************************************************************
* Function Name: Cy_SysPm_RetLdoConfigure
****************************************************************************//**
*
* Configures the RETLDO Regulator
*
* \param retLdoParam
* Structure containing the config parameters, \ref cy_stc_syspm_retldo_params_t
*
* \return
* see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_RetLdoConfigure(cy_stc_syspm_retldo_params_t *retLdoParam);

/*******************************************************************************
* Function Name: Cy_SysPm_SramLdoStatus
****************************************************************************//**
*
* Get the status of SRAMLDO Regulator
*
* \return
* Gets enum value of type \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SramLdoStatus(void);

/*******************************************************************************
* Function Name: Cy_SysPm_SramLdoConfigure
****************************************************************************//**
*
* Configures the SRAMLDO Regulator
*
* \param sramLdoParam
* Structure containing the config parameters, \ref cy_stc_syspm_sramldo_params_t
*
* \return
* see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SramLdoConfigure(cy_stc_syspm_sramldo_params_t *sramLdoParam);

/*******************************************************************************
* Function Name: Cy_SysPm_SramLdoEnable
****************************************************************************//**
*
* Enable/Disable SRAMLDO Regulator
*
* \param enable
* true - enable, false - disable
*
* \return
* see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_status_t Cy_SysPm_SramLdoEnable(bool enable)
{
    CY_REG32_CLR_SET(SRSS_PWR_SRAMLDO_CTL, SRSS_PWR_SRAMLDO_CTL_SRAMLDO_EN, (enable ? 1U : 0U));

    return Cy_SysPm_SramLdoStatus();
}

/*******************************************************************************
* Function Name: Cy_SysPm_SramLdoSetVoltage
****************************************************************************//**
*
* Set SRAM LDO Voltage
*
* \param voltage
* Enum \ref cy_en_syspm_sramldo_voltage_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_SramLdoSetVoltage(cy_en_syspm_sramldo_voltage_t voltage)
{
    CY_ASSERT_L2(CY_SYSPM_IS_SRAMLDO_VOLTAGE_VALID(voltage));

    CY_REG32_CLR_SET(SRSS_PWR_SRAMLDO_CTL, SRSS_PWR_SRAMLDO_CTL_SRAMLDO_VOUT, voltage);
}

/*******************************************************************************
* Function Name: Cy_SysPm_SramLdoGetVoltage
****************************************************************************//**
*
* Get the SRAM LDO Voltage
*
* \return
* Gets enum value of type \ref cy_en_syspm_sramldo_voltage_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_sramldo_voltage_t Cy_SysPm_SramLdoGetVoltage(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_sramldo_voltage_t enum.');
    return (cy_en_syspm_sramldo_voltage_t)(_FLD2VAL(SRSS_PWR_SRAMLDO_CTL_SRAMLDO_VOUT, SRSS_PWR_SRAMLDO_CTL));
}

/*******************************************************************************
* Function Name: Cy_SysPm_MiscLdoStatus
****************************************************************************//**
*
* Get the status of MISCLDO Regulator
*
* \return
* Gets enum value of type \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_MiscLdoStatus(void);

/*******************************************************************************
* Function Name: Cy_SysPm_MiscLdoConfigure
****************************************************************************//**
*
* Configures the MISCLDO Regulator
*
* \param miscLdoParam
* Structure containing the config parameters, \ref cy_stc_syspm_miscldo_params_t
*
* \return
* see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_MiscLdoConfigure(cy_stc_syspm_miscldo_params_t *miscLdoParam);



#endif /* defined (CY_IP_MXS22SRSS)  || defined (CY_DOXYGEN) */


/** \} group_syspm_functions_buck */
#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) */



/**
* \addtogroup group_syspm_functions_iofreeze
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysPm_IoIsFrozen
****************************************************************************//**
*
* Checks whether IOs are frozen.
*
* \return
* - True if IOs are frozen.
* - False if IOs are unfrozen.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_IoUnfreeze
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysPm_IoIsFrozen(void)
{
    return (0U != _FLD2VAL(SRSS_PWR_HIBERNATE_FREEZE, SRSS_PWR_HIBERNATE));
}

/*******************************************************************************
* Function Name: Cy_SysPm_IoUnfreeze
****************************************************************************//**
*
* This function unfreezes the I/O cells that are automatically frozen when
* Hibernate is entered with the call to \ref Cy_SysPm_SystemEnterHibernate().
*
* I/O cells remain frozen after a wakeup from Hibernate mode until the
* firmware unfreezes them by calling this function.
*
* If the firmware must retain the data value on the pin, then the
* value must be read and re-written to the pin's port data register before
* calling this function. Furthermore, the drive mode must be re-programmed
* before the pins are unfrozen. If this is not done, the pin will change to
* the default state the moment the freeze is removed.
*
* Note that I/O cell configuration can be changed while frozen. The new
* configuration becomes effective only after the pins are unfrozen.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_IoUnfreeze
*
*******************************************************************************/
void Cy_SysPm_IoUnfreeze(void);


#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_DeepSleepIoIsFrozen
****************************************************************************//**
*
* Checks whether IOs are frozen during DEEPSLEEP-RAM/OFF
*
* \return
* - True if IOs are frozen.
* - False if IOs are unfrozen.
*
*******************************************************************************/
bool Cy_SysPm_DeepSleepIoIsFrozen(void);

/*******************************************************************************
* Function Name: Cy_SysPm_DeepSleepIoUnfreeze
****************************************************************************//**
*
* This function unfreezes the I/O cells that are automatically frozen when
* DEEPSLEEP-RAM/OFF is entered.
*
* I/O cells remain frozen after a wakeup from DEEPSLEEP_RAM/OFF mode until the
* firmware unfreezes them by calling this function.
*
* If the firmware must retain the data value on the pin, then the
* value must be read and re-written to the pin's port data register before
* calling this function. Furthermore, the drive mode must be re-programmed
* before the pins are unfrozen. If this is not done, the pin will change to
* the default state the moment the freeze is removed.
*
* Note that I/O cell configuration can be changed while frozen. The new
* configuration becomes effective only after the pins are unfrozen.
*
*******************************************************************************/
void Cy_SysPm_DeepSleepIoUnfreeze(void);

#endif  /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) */

/** \} group_syspm_functions_iofreeze */



/** \} group_syspm_functions */

/** \cond INTERNAL */

/*******************************************************************************
* Backward compatibility macro. The following code is DEPRECATED and must
* not be used in new projects
*******************************************************************************/


#define CY_SYSPM_LPCOMP0_LOW                 CY_SYSPM_HIBERNATE_LPCOMP0_LOW
#define CY_SYSPM_LPCOMP0_HIGH                CY_SYSPM_HIBERNATE_LPCOMP0_HIGH
#define CY_SYSPM_LPCOMP1_LOW                 CY_SYSPM_HIBERNATE_LPCOMP1_LOW
#define CY_SYSPM_LPCOMP1_HIGH                CY_SYSPM_HIBERNATE_LPCOMP1_HIGH
#define CY_SYSPM_HIBALARM                    CY_SYSPM_HIBERNATE_RTC_ALARM
#define CY_SYSPM_HIBWDT                      CY_SYSPM_HIBERNATE_WDT
#define CY_SYSPM_HIBPIN0_LOW                 CY_SYSPM_HIBERNATE_PIN0_LOW
#define CY_SYSPM_HIBPIN0_HIGH                CY_SYSPM_HIBERNATE_PIN0_HIGH
#define CY_SYSPM_HIBPIN1_LOW                 CY_SYSPM_HIBERNATE_PIN1_LOW
#define CY_SYSPM_HIBPIN1_HIGH                CY_SYSPM_HIBERNATE_PIN1_HIGH



typedef cy_en_syspm_hibernate_wakeup_source_t  cy_en_syspm_hib_wakeup_source_t;

/* BWC defines related to hibernation functions */
#define Cy_SysPm_SetHibWakeupSource          Cy_SysPm_SetHibernateWakeupSource
#define Cy_SysPm_ClearHibWakeupSource        Cy_SysPm_ClearHibernateWakeupSource
#define Cy_SysPm_GetIoFreezeStatus           Cy_SysPm_IoIsFrozen

/* BWC defines for Backup related functions */
#define Cy_SysPm_SetBackupSupply             Cy_SysPm_BackupSetSupply
#define Cy_SysPm_GetBackupSupply             Cy_SysPm_BackupGetSupply
#define Cy_SysPm_EnableBackupVMeasure        Cy_SysPm_BackupEnableVoltageMeasurement
#define Cy_SysPm_DisableBackupVMeasure       Cy_SysPm_BackupDisableVoltageMeasurement


/* BWC defines for functions related to low power transition */
#define Cy_SysPm_Sleep                       Cy_SysPm_CpuEnterSleep
#define Cy_SysPm_DeepSleep                   Cy_SysPm_CpuEnterDeepSleep
#define Cy_SysPm_Hibernate                   Cy_SysPm_SystemEnterHibernate

#define Cy_SysPm_SleepOnExit                 Cy_SysPm_CpuSleepOnExit

/* BWC defines for functions related to low power transition */
#define Cy_SysPm_EnterLpMode                 Cy_SysPm_EnterLowPowerMode
#define Cy_SysPm_ExitLpMode                  Cy_SysPm_ExitLowPowerMode
#define Cy_SysPm_IsLowPower                  Cy_SysPm_IsSystemUlp

#define Cy_SysPm_EnterLowPowerMode           Cy_SysPm_SystemSetMinRegulatorCurrent
#define Cy_SysPm_ExitLowPowerMode            Cy_SysPm_SystemSetNormalRegulatorCurrent

#define CY_SYSPM_WAKEUP_PIN0_BIT             CY_SYSPM_HIB_WAKEUP_PIN0_POS
#define CY_SYSPM_WAKEUP_PIN1_BIT             CY_SYSPM_HIB_WAKEUP_PIN1_POS
#define CY_SYSPM_WAKEUP_LPCOMP0_BIT          CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS
#define CY_SYSPM_WAKEUP_LPCOMP1_BIT          CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS

#define CY_SYSPM_WAKEUP_LPCOMP0                  CY_SYSPM_HIB_WAKEUP_LPCOMP0_MASK
#define CY_SYSPM_WAKEUP_LPCOMP1                  CY_SYSPM_HIB_WAKEUP_LPCOMP1_MASK
#define CY_SYSPM_WAKEUP_PIN0                     CY_SYSPM_HIB_WAKEUP_PIN0_MASK
#define CY_SYSPM_WAKEUP_PIN1                     CY_SYSPM_HIB_WAKEUP_PIN1_MASK
#define CY_SYSPM_WAKEUP_LPCOMP0_POLARITY_HIGH    CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK
#define CY_SYSPM_WAKEUP_LPCOMP1_POLARITY_HIGH    CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK
#define CY_SYSPM_WAKEUP_PIN0_POLARITY_HIGH       CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK
#define CY_SYSPM_WAKEUP_PIN1_POLARITY_HIGH       CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK

#define CY_SYSPM_PWR_TOKEN_HIBERNATE             HIBERNATE_TOKEN
#define CY_SYSPM_PWR_WAKEUP_HIB_MASK             HIBERNATE_WAKEUP_MASK
#define CY_SYSPM_PWR_RETAIN_HIBERNATE_STATUS     HIBERNATE_RETAIN_STATUS_MASK
#define CY_SYSPM_PWR_SET_HIBERNATE               SET_HIBERNATE_MODE
#define CY_SYSPM_PWR_HIBERNATE_UNLOCK            HIBERNATE_UNLOCK_VAL

/** \endcond */

#ifdef __cplusplus
}
#endif

#endif /* defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) */

#endif /* CY_SYSPM_H */

/** \} group_syspm */


/* [] END OF FILE */
