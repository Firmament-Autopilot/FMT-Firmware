/***************************************************************************//**
* \file cy_lvd.h
* \version 1.80
*
* \brief
* The header file of the LVD driver.
*
********************************************************************************
* \copyright
* Copyright(c) 2017-2025 Infineon Technologies AG or an affiliate of
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
* \addtogroup group_lvd
* \{
* The LVD driver provides an API to manage the Low Voltage Detection block.
*
* The functions and other declarations used in this driver are in cy_lvd.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* The LVD block provides a status of currently observed VDDD voltage
* and triggers an interrupt when the observed voltage crosses an adjusted
* threshold.
*
* \section group_lvd_configuration_considerations Configuration Considerations
* To set up an LVD, configure the voltage threshold by the
* \ref Cy_LVD_SetThreshold function, ensure that the LVD block itself and LVD
* interrupt are disabled (by the \ref Cy_LVD_Disable and
* \ref Cy_LVD_ClearInterruptMask functions correspondingly) before changing the
* threshold to prevent propagating a false interrupt.
* Then configure interrupts by the \ref Cy_LVD_SetInterruptConfig function, do
* not forget to initialize an interrupt handler (the interrupt source number
* is srss_interrupt_IRQn).
* Then enable LVD by the \ref Cy_LVD_Enable function, then wait for at least 20us
* to get the circuit stabilized and clear the possible false interrupts by the
* \ref Cy_LVD_ClearInterrupt, and finally the LVD interrupt can be enabled by
* the \ref Cy_LVD_SetInterruptMask function.
*
* For example:
* \snippet lvd/snippet/main.c Cy_LVD_Snippet
*
* Note that the LVD circuit is available only in Low Power and Ultra Low Power
* modes. If an LVD is required in Deep Sleep mode, then the device
* should be configured to periodically wake up from Deep Sleep using a
* Deep Sleep wakeup source. This makes sure a LVD check is performed during
* Low Power or Ultra Low Power modes.
*
* \section group_lvd_more_information More Information
* See the LVD chapter of the device technical reference manual (TRM).
*
* \defgroup group_lvd_macros Macros
* \defgroup group_lvd_functions Functions
*   \{
*       \defgroup group_lvd_functions_syspm_callback  Low Power Callback
*   \}
* \defgroup group_lvd_enums Enumerated Types
*/


#if !defined(CY_LVD_H)
#define CY_LVD_H

#include "cy_device.h"

#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION == 1)) || defined (CY_IP_MXS22SRSS)

#include "cy_syspm.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \addtogroup group_lvd_macros
* \{
*/

/** The driver major version */
#define CY_LVD_DRV_VERSION_MAJOR       1

/** The driver minor version */
#define CY_LVD_DRV_VERSION_MINOR       80

/** The LVD driver identifier */
#define CY_LVD_ID                      (CY_PDL_DRV_ID(0x39U))



#if defined (CY_IP_MXS22SRSS)
/** Interrupt mask for \ref Cy_LVD_GetInterruptStatus(),
                       \ref Cy_LVD_ClearInterrupt() */
#define CY_LVD_SRSS_INTR_HVLVD1_MASK        (SRSS_SRSS_AINTR_HVLVD_Msk)

/** Interrupt mask for \ref Cy_LVD_SetInterrupt() */
#define CY_LVD_SRSS_INTR_SET_HVLVD1_MASK    (SRSS_SRSS_AINTR_SET_HVLVD_Msk)

/** Interrupt mask for \ref Cy_LVD_GetInterruptMask(),
                       \ref Cy_LVD_SetInterruptMask() and
                       \ref Cy_LVD_ClearInterruptMask() */
#define CY_LVD_SRSS_INTR_MASK_HVLVD1_MASK   (SRSS_SRSS_AINTR_MASK_HVLVD_Msk)

/** Interrupt mask for \ref Cy_LVD_GetInterruptStatusMasked() */
#define CY_LVD_SRSS_INTR_MASKED_HVLVD1_MASK (SRSS_SRSS_AINTR_MASKED_HVLVD_Msk)

/** Enable mask for \ref Cy_LVD_Enable() and /ref Cy_LVD_Disable() */
#define CY_LVD_SRSS_PWR_LVD_CTL_HVLVD_EN_Msk   (SRSS_PWR_LVD_CTL_HVLVD_EN_Msk)
#endif


/** \} group_lvd_macros */


/** \addtogroup group_lvd_enums
* \{
*/


/**
 * LVD reference voltage select.
 */
#if defined (CY_IP_MXS22SRSS)
typedef enum
{
    CY_LVD_THRESHOLD_2_75_V    = 0x0U, /**<Select LVD reference voltage: 2.75V */
    CY_LVD_THRESHOLD_2_85_V    = 0x1U, /**<Select LVD reference voltage: 2.85V */
    CY_LVD_THRESHOLD_2_95_V    = 0x2U, /**<Select LVD reference voltage: 2.95V */
    CY_LVD_THRESHOLD_3_05_V    = 0x3U, /**<Select LVD reference voltage: 3.05V */
    CY_LVD_THRESHOLD_3_15_V    = 0x4U, /**<Select LVD reference voltage: 3.15V */
} cy_en_lvd_tripsel_t;
#endif
 /**
 * LVD interrupt configuration select.
 */
typedef enum
{
    CY_LVD_INTR_DISABLE    = 0x0U,  /**<Select LVD interrupt: disabled */
    CY_LVD_INTR_RISING     = 0x1U,  /**<Select LVD interrupt: rising edge */
    CY_LVD_INTR_FALLING    = 0x2U,  /**<Select LVD interrupt: falling edge */
    CY_LVD_INTR_BOTH       = 0x3U,  /**<Select LVD interrupt: both edges */
} cy_en_lvd_intr_config_t;

/**
 * LVD output status.
 */
typedef enum
{
    CY_LVD_STATUS_BELOW   = 0x0U,  /**<The voltage is below the threshold */
    CY_LVD_STATUS_ABOVE   = 0x1U,  /**<The voltage is above the threshold */
} cy_en_lvd_status_t;

/**
 * LVD Voltage Source.
 */
typedef enum
{
    CY_LVD_SOURCE_VDDD       = 0x0U,  /**<Selects VDDD */
    CY_LVD_SOURCE_AMUXBUSA   = 0x1U,  /**<Selects AMUXBUSA*/
    CY_LVD_SOURCE_RES        = 0x2U,  /**<Reserved */
    CY_LVD_SOURCE_VDDIO      = 0x3U,  /**<Selects VDDIO, Currently Reserved , Selects VDDD */
    CY_LVD_SOURCE_AMUXBUSB   = 0x4U,  /**<Selects AMUXBUSB*/
} cy_en_lvd_source_t;

/**
 * LVD Action
 */
typedef enum
{
    CY_LVD_ACTION_INTERRUPT    = 0x0U,  /**<Select LVD Action : Interrupt */
    CY_LVD_ACTION_FAULT        = 0x1U,  /**<Select LVD Action : Fault */
} cy_en_lvd_action_config_t;

/** \} group_lvd_enums */

/** \cond internal */
/* Macros for conditions used by CY_ASSERT calls */
#if defined (CY_IP_MXS22SRSS)
#define CY_LVD_CHECK_TRIPSEL(threshold)  (((threshold) == CY_LVD_THRESHOLD_2_75_V) || \
                                          ((threshold) == CY_LVD_THRESHOLD_2_85_V) || \
                                          ((threshold) == CY_LVD_THRESHOLD_2_95_V) || \
                                          ((threshold) == CY_LVD_THRESHOLD_3_05_V) || \
                                          ((threshold) == CY_LVD_THRESHOLD_3_15_V))

#endif
 #define CY_LVD_CHECK_INTR_CFG(intrCfg)   (((intrCfg) == CY_LVD_INTR_DISABLE) || \
                                          ((intrCfg) == CY_LVD_INTR_RISING) || \
                                          ((intrCfg) == CY_LVD_INTR_FALLING) || \
                                          ((intrCfg) == CY_LVD_INTR_BOTH))

/* Added for backward Compatibility */
#define CY_LVD_INTR        (CY_LVD_SRSS_INTR_HVLVD1_MASK)

#define CY_LVD_CHECK_ACTION_CFG(actionCfg)   (((actionCfg) == CY_LVD_ACTION_INTERRUPT) || \
                                              ((actionCfg) == CY_LVD_ACTION_FAULT))

/** \endcond */

/**
* \addtogroup group_lvd_functions
* \{
*/
__STATIC_INLINE void Cy_LVD_Enable(void);
__STATIC_INLINE void Cy_LVD_Disable(void);
__STATIC_INLINE void Cy_LVD_SetThreshold(cy_en_lvd_tripsel_t threshold);
__STATIC_INLINE cy_en_lvd_status_t Cy_LVD_GetStatus(void);
__STATIC_INLINE uint32_t Cy_LVD_GetInterruptStatus(void);
__STATIC_INLINE void Cy_LVD_ClearInterrupt(void);
__STATIC_INLINE void Cy_LVD_SetInterrupt(void);
__STATIC_INLINE uint32_t Cy_LVD_GetInterruptMask(void);
__STATIC_INLINE void Cy_LVD_SetInterruptMask(void);
__STATIC_INLINE void Cy_LVD_ClearInterruptMask(void);
__STATIC_INLINE uint32_t Cy_LVD_GetInterruptStatusMasked(void);
__STATIC_INLINE void Cy_LVD_SetInterruptConfig(cy_en_lvd_intr_config_t lvdInterruptConfig);

/** \addtogroup group_lvd_functions_syspm_callback
* The driver supports SysPm callback for Deep Sleep transition.
* \{
*/
cy_en_syspm_status_t Cy_LVD_DeepSleepCallback(cy_stc_syspm_callback_params_t * callbackParams, cy_en_syspm_callback_mode_t mode);
/** \} */

/*******************************************************************************
* Function Name: Cy_LVD_Enable
****************************************************************************//**
*
*  Enables the output of the LVD block when the VDDD voltage is
*  at or below the threshold.
*  See the Configuration Considerations section for details.
*
*******************************************************************************/
__STATIC_INLINE void Cy_LVD_Enable(void)
{
        SRSS_PWR_LVD_CTL |= CY_LVD_SRSS_PWR_LVD_CTL_HVLVD_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_LVD_Disable
****************************************************************************//**
*
*  Disables the LVD block. A low voltage detection interrupt is disabled.
*
*******************************************************************************/
__STATIC_INLINE void Cy_LVD_Disable(void)
{
        SRSS_PWR_LVD_CTL &= (uint32_t) ~CY_LVD_SRSS_PWR_LVD_CTL_HVLVD_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_LVD_SetThreshold
****************************************************************************//**
*
*  Sets a threshold for monitoring the VDDD voltage.
*  To prevent propagating a false interrupt, before changing the threshold
*  ensure that the LVD block itself and LVD interrupt are disabled by the
*  \ref Cy_LVD_Disable and \ref Cy_LVD_ClearInterruptMask functions
*  correspondingly.
*
*  \param threshold
*  Threshold selection for Low Voltage Detect circuit, \ref cy_en_lvd_tripsel_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_LVD_SetThreshold(cy_en_lvd_tripsel_t threshold)
{
    CY_ASSERT_L3(CY_LVD_CHECK_TRIPSEL(threshold));
    SRSS_PWR_LVD_CTL = _CLR_SET_FLD32U(SRSS_PWR_LVD_CTL, SRSS_PWR_LVD_CTL_HVLVD_TRIPSEL, threshold);
 }


/*******************************************************************************
* Function Name: Cy_LVD_GetStatus
****************************************************************************//**
*
*  Returns the status of LVD.
*  SRSS LVD Status Register (PWR_LVD_STATUS).
*
*  \return LVD status, \ref cy_en_lvd_status_t.
*
*******************************************************************************/
__STATIC_INLINE cy_en_lvd_status_t Cy_LVD_GetStatus(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','SRSS_PWR_LVD_STATUS_HVLVD_OK_Msk extracts only 1 bit value');
    return ((cy_en_lvd_status_t) _FLD2VAL(SRSS_PWR_LVD_STATUS_HVLVD_OK, SRSS_PWR_LVD_STATUS));
 }


/*******************************************************************************
* Function Name: Cy_LVD_GetInterruptStatus
****************************************************************************//**
*
*  Returns the status of LVD interrupt.
*  SRSS Interrupt Register (SRSS_INTR).
*
*  \return SRSS Interrupt status, \ref CY_LVD_SRSS_INTR_HVLVD1_MASK.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_LVD_GetInterruptStatus(void)
{
    return (SRSS_SRSS_AINTR & CY_LVD_SRSS_INTR_HVLVD1_MASK);
 }


/*******************************************************************************
* Function Name: Cy_LVD_ClearInterrupt
****************************************************************************//**
*
*  Clears LVD interrupt.
*  SRSS Interrupt Register (SRSS_INTR).
*
*******************************************************************************/
__STATIC_INLINE void Cy_LVD_ClearInterrupt(void)
{
    SRSS_SRSS_AINTR = CY_LVD_SRSS_INTR_HVLVD1_MASK;
    /* This dummy reading is necessary here. It provides a guarantee that interrupt is cleared at returning from this function. */
    (void) SRSS_SRSS_INTR;
 }


/*******************************************************************************
* Function Name: Cy_LVD_SetInterrupt
****************************************************************************//**
*
*  Triggers the device to generate interrupt for LVD.
*  SRSS Interrupt Set Register (SRSS_INTR_SET).
*
*******************************************************************************/
__STATIC_INLINE void Cy_LVD_SetInterrupt(void)
{
    SRSS_SRSS_AINTR_SET = CY_LVD_SRSS_INTR_SET_HVLVD1_MASK;
 }


/*******************************************************************************
* Function Name:  Cy_LVD_GetInterruptMask
****************************************************************************//**
*
*  Returns the mask value of LVD interrupts.
*  SRSS Interrupt Mask Register (SRSS_INTR_MASK).
*
*  \return SRSS Interrupt Mask value, \ref CY_LVD_SRSS_INTR_HVLVD1_MASK.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_LVD_GetInterruptMask(void)
{
    return (SRSS_SRSS_AINTR_MASK & CY_LVD_SRSS_INTR_MASK_HVLVD1_MASK);
 }


/*******************************************************************************
* Function Name: Cy_LVD_SetInterruptMask
****************************************************************************//**
*
* Enables LVD interrupts.
* Sets the LVD interrupt mask in the SRSS_INTR_MASK register.
*
*******************************************************************************/
__STATIC_INLINE void Cy_LVD_SetInterruptMask(void)
{
    SRSS_SRSS_AINTR_MASK |= CY_LVD_SRSS_INTR_MASK_HVLVD1_MASK;
 }


/*******************************************************************************
* Function Name: Cy_LVD_ClearInterruptMask
****************************************************************************//**
*
* Disables LVD interrupts.
* Clears the LVD interrupt mask in the SRSS_INTR_MASK register.
*
*******************************************************************************/
__STATIC_INLINE void Cy_LVD_ClearInterruptMask(void)
{
    SRSS_SRSS_AINTR_MASK &= (uint32_t) ~CY_LVD_SRSS_INTR_MASK_HVLVD1_MASK;
 }


/*******************************************************************************
* Function Name: Cy_LVD_GetInterruptStatusMasked
****************************************************************************//**
*
*  Returns the masked interrupt status which is a bitwise AND between the
*  interrupt status and interrupt mask registers.
*  SRSS Interrupt Masked Register (SRSS_INTR_MASKED).
*
*  \return SRSS Interrupt Masked value, \ref CY_LVD_SRSS_INTR_MASKED_HVLVD1_MASK.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_LVD_GetInterruptStatusMasked(void)
{
    return (SRSS_SRSS_AINTR_MASKED & CY_LVD_SRSS_INTR_MASKED_HVLVD1_MASK);
 }


/*******************************************************************************
* Function Name: Cy_LVD_SetInterruptConfig
****************************************************************************//**
*
*  Sets a configuration for LVD interrupt.
*  SRSS Interrupt Configuration Register (SRSS_INTR_CFG).
*
*  \param lvdInterruptConfig \ref cy_en_lvd_intr_config_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_LVD_SetInterruptConfig(cy_en_lvd_intr_config_t lvdInterruptConfig)
{
    CY_ASSERT_L3(CY_LVD_CHECK_INTR_CFG(lvdInterruptConfig));



#if defined (CY_IP_MXS22SRSS)
        SRSS_PWR_LVD_CTL = _CLR_SET_FLD32U(SRSS_PWR_LVD_CTL, SRSS_PWR_LVD_CTL_HVLVD_EDGE_SEL, lvdInterruptConfig);
#endif

    /* This dummy reading is necessary here. It provides a guarantee that interrupt is cleared at returning from this function. */
    (void) lvdInterruptConfig;
}

#if defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_LVD_SetActionConfig
****************************************************************************//**
*
*  Sets a action configuration after LVD block reaches threshold.
*
*  \param lvdActionConfig \ref cy_en_lvd_action_config_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_LVD_SetActionConfig(cy_en_lvd_action_config_t lvdActionConfig)
{
    CY_ASSERT_L3(CY_LVD_CHECK_ACTION_CFG(lvdActionConfig));

    SRSS_PWR_LVD_CTL = _CLR_SET_FLD32U(SRSS_PWR_LVD_CTL, SRSS_PWR_LVD_CTL_HVLVD_ACTION, lvdActionConfig);
}

/*******************************************************************************
* Function Name: Cy_LVD_GetActionConfig
****************************************************************************//**
*
*  Gets the action configured after LVD reaches threshold.
*
*  \return \ref cy_en_lvd_action_config_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_lvd_action_config_t Cy_LVD_GetActionConfig(void)
{
    return (((SRSS_PWR_LVD_CTL & SRSS_PWR_LVD_CTL_HVLVD_ACTION_Msk) != 0UL) ? CY_LVD_ACTION_FAULT : CY_LVD_ACTION_INTERRUPT);
}
#endif


/** \} group_lvd_functions */

#ifdef __cplusplus
}
#endif

#endif /* (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 3)) || defined (CY_IP_MXS22SRSS) */

#endif /* CY_LVD_H */

/** \} group_lvd */


/* [] END OF FILE */
