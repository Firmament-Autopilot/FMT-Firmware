/***************************************************************************//**
* \file ifx_se_ss_wifi.c
* \version 1.2.0
*
* \brief
* This is the source code file for utility syscall functions related to WIFI
* Subsystem
*
********************************************************************************
* \copyright
* Copyright 2022-2025, Cypress Semiconductor Corporation (an Infineon company).
* All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_utils.h"
#include "ifx_se_ss_wifi.h"

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 5.1', 1, \
    'IFX SE Utilities library uses objects naming scheme with more then 32 symbols.');
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 13, \
    'Intentional typecast of "ipc_packet[]" to "ifx_se_fih_uint *" type.');
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.4', 13, \
    'Intentional typecast of "ipc_packet" to an integer type.');
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Directive 4.9', 4, \
    'Use function-like macro as simple inline functions.');

ifx_se_status_t ifx_se_enable_wifi(void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 0 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(0u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_ENABLE_WIFI;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_disable_wifi(void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 0 parameter */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(0u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_DISABLE_WIFI;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_enable_wifi_sram_access(void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 1 parameter */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(0u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_ENABLE_WIFI_SRAM_ACCESS;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 5.1');
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3');
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.4');
CY_MISRA_BLOCK_END('MISRA C-2012 Directive 4.9');
