/***************************************************************************//**
* \file ifx_se_config_template.h
* \version 1.2.0
*
* \brief
* This is a template of configuration header file which can be used to redefine 
* default values set in source code.
*
* To use this file simply rename it to your preference and pass to build system
* or Makefile in a following way:
*   -DIFX_SE_CONFIG_FILE="\"ifx_se_user_config.h\""
* 
********************************************************************************
* \copyright
* Copyright 2022-2025, Cypress Semiconductor Corporation (an Infineon company).
* All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef IFX_SE_CONFIG_H
#define IFX_SE_CONFIG_H

/* IPC channel to transfer data to SE RT Services */
/* #define IFX_SE_IPC_SYSCALL                     (0U) */

/* IPC interrupt channel to notify SE RT Services for new request */
/* #define IFX_SE_IPC_INTR_ACQ                    (0U) */

/* IPC interrupt channel to notify client from SE RT Services for processed request */
/* #define IFX_SE_IPC_INTR_REL                    (1U) */

#endif /* IFX_SE_CONFIG_H */
