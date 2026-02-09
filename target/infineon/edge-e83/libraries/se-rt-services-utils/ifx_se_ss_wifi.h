/***************************************************************************//**
* \file ifx_se_ss_wifi.h
* \version 1.2.0
*
* \brief
* This is the header file for utility syscall functions, related to wifi subsystem
*
********************************************************************************
* \copyright
* Copyright 2022-2025, Cypress Semiconductor Corporation (an Infineon company).
* All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#ifndef IFX_SE_SS_WIFI_H_
#define IFX_SE_SS_WIFI_H_

#include "ifx_se_platform.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** \addtogroup platform_wifi
 * \{
 */

/*******************************************************************************
 * Function Name: ifx_se_enable_wifi
 ***************************************************************************//**
 *
 * Performs HASH validation for RRAM WiFiSS FW Image and if success starts the
 * WIFI FW.
 *
 * \param[in] ctx           The pointer to the SE syscall context that contain
 *                          a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_enable_wifi(void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_disable_wifi
 ***************************************************************************//**
 *
 * Disables WiFiSS and power off the WIFI SS.
 *
 * \param[in] ctx           The pointer to the SE syscall context that contain
 *                          a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_disable_wifi(void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_enable_wifi_sram_access
 ***************************************************************************//**
 *
 * Enables only Wi-Fi SS SRAM for staging of RAM_APPs and allows CPUSS access
 *  to this memory.
 * WIFI SS needs to be turned off before calling this API.
 *
 * \param[in] ctx           The pointer to the SE syscall context that contain
 *                          a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_enable_wifi_sram_access(void *ctx);

/** \} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IFX_SE_SS_WIFI_H_*/