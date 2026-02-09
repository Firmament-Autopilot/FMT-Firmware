/***************************************************************************//**
* \file ifx_se_syscall.c
* \version 1.2.0
*
* \brief
* This is the source code file for syscall caller function.
*
********************************************************************************
* \copyright
* Copyright 2022-2025, Cypress Semiconductor Corporation (an Infineon company).
* All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ifx_se_syscall.h"

#include "cy_syslib.h"

__WEAK ifx_se_status_t ifx_se_syscall(ifx_se_fih_ptr_t ipc_packet, ifx_se_fih_t ipc_packet_size, void *ctx)
{
    /* ipc_packet_size is unused in default implementation */
    (void)ipc_packet_size;

    return ifx_se_syscall_builtin(ipc_packet, ctx);
}
