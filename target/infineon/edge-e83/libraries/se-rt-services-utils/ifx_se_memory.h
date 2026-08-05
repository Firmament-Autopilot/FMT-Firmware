/***************************************************************************//**
* \file ifx_se_memory.h
* \version 1.2.0
*
* Provides IFX SE memory abstraction layer
*
********************************************************************************
* \copyright
* Copyright 2022-2025, Cypress Semiconductor Corporation (an Infineon company).
* All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(IFX_SE_MEMORY_H_)
#define IFX_SE_MEMORY_H_

#include "ifx_se_syscall.h"
#include "ifx_se_fih.h"
#include "cy_syslib.h"
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define ifx_se_calloc(...)              calloc(__VA_ARGS__)
#define ifx_se_free(...)                free(__VA_ARGS__)

__STATIC_INLINE ifx_se_status_t ifx_se_memcpy(void *dst, const void *src, size_t len)
{
    (void)memcpy(dst, src, len);
    return IFX_SE_SUCCESS;
}
__STATIC_INLINE ifx_se_status_t ifx_se_memset(void *dst, int32_t val, size_t len)
{
    (void)memset(dst, val, len);
    return IFX_SE_SUCCESS;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IFX_SE_MEMORY_H_ */

