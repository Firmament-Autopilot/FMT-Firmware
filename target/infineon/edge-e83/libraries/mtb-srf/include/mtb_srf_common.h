/*******************************************************************************
* \file mtb_srf_common.h
*
* \brief
* Provides private helpers for the SRF implementation
*
*******************************************************************************
* \copyright
* (c) (2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

// This function is only needed on the non-secure side, and its implementation depends
// on HAL headers. To avoid unnecessary compilation dependencies, do not include it
// when building for the secure world. This can be relaxed in the future
// if there is a need to call this function on the secure world, but there are no known
// situations in which the secure world SRF should be busy-waiting.
#ifdef COMPONENT_NON_SECURE_DEVICE
/**
 * \cond INTERNAL
 * Waits for the specified interval. Also decrements the timeout unless it is "never timeout"
 *
 * @param[in,out] timeout_us timeout in microseconds. To wait forever, use MTB_SRF_NEVER_TIMEOUT.
 *                           Updated with the remaining time to wait
 * @param[in]     interval_us The amount of time to delay before returning
 */
void _mtb_srf_wait(uint32_t* timeout_us, uint32_t interval_us);

/** \endcond */
#endif /* COMPONENT_NON_SECURE_DEVICE */
