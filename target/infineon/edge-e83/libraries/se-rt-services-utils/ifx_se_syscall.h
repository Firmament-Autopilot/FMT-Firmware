/***************************************************************************//**
* \file ifx_se_syscall.h
* \version 1.2.0
*
* \brief
* This is the header file for low-level syscall functions.
*
********************************************************************************
* \copyright
* Copyright 2022-2025, Cypress Semiconductor Corporation (an Infineon company).
* All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/*******************************************************************************
* IFX SE syscalls prototypes
****************************************************************************//**
*
* \defgroup syscalls     IFX SE low-level Syscall API
* \brief
*  IFX SE low-level Syscall functions
*
* \{
*   \defgroup syscall_errors Error codes
*       Error codes definitions
*   \defgroup syscall_macros Syscall macros
*       Syscall macros definitions
*   \defgroup syscall_funcs Syscall functions
*       Syscall functions definitions
* \}
*
*******************************************************************************/

#ifndef IFX_SE_SYSCALL_H
#define IFX_SE_SYSCALL_H

#include <stdint.h>

#if defined(IFX_SE_CONFIG_FILE)
    #include IFX_SE_CONFIG_FILE
#endif /* IFX_SE_CONFIG_FILE */

#include "ifx_se_fih.h"
#include "ifx_se_crc32.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Secure Runtime Services functions groups */
#define IFX_SE_SYSCALL_GROUP_MASK                          (0xFFFFFF00u)
#define IFX_SE_SYSCALL_GROUP_PSA_CRYPTO                    (0x752B4600u)
#define IFX_SE_SYSCALL_GROUP_RB_COUNTER                    (0x7B56C500u)
#define IFX_SE_SYSCALL_GROUP_SERVICES                      (0xD40ABF00u)
#define IFX_SE_SYSCALL_GROUP_ATTESTATION                   (0xC3456400u)
#define IFX_SE_SYSCALL_GROUP_PROTECTION                    (0xA25B2700u)
#define IFX_SE_SYSCALL_GROUP_WIFI                          (0x5B719A00u)
#define IFX_SE_SYSCALL_GROUP_TEST                          (0xFFFFFF00u)

/* Make Secure Runtime Services FIH based command IDs */
#define IFX_SE_SYSCALL_CODE(grp_id, cmd_id)                IFX_SE_FIH_UINT_INIT((uint32_t)(grp_id) | (uint32_t)(cmd_id))

/* Make Secure Runtime Services FIH based command Groups */
#define IFX_SE_SYSCALL_GROUP(grp_id)                       IFX_SE_SYSCALL_CODE(grp_id, 0)

/* Get Secure Runtime Services group value from FIH based command ID */
#define IFX_SE_SYSCALL_GET_GROUP(cmd)                      ifx_se_fih_uint_and(cmd, \
                                                             IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_MASK, 0))
/* Secure Runtime Services functions */
/* IFX_SE_SYSCALL_GROUP_TEST service IDs */
#define IFX_SE_SYSCALL_TEST                                IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_TEST, 0)
/* IFX_SE_SYSCALL_GROUP_PSA_CRYPTO service IDs */
#define IFX_SE_SYSCALL_PSA_HASH_SETUP                      IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO,  1)
#define IFX_SE_SYSCALL_PSA_HASH_UPDATE                     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO,  2)
#define IFX_SE_SYSCALL_PSA_HASH_FINISH                     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO,  3)
#define IFX_SE_SYSCALL_PSA_HASH_VERIFY                     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO,  4)
#define IFX_SE_SYSCALL_PSA_HASH_ABORT                      IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO,  5)
#define IFX_SE_SYSCALL_PSA_HASH_COMPUTE                    IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO,  6)
#define IFX_SE_SYSCALL_PSA_HASH_CLONE                      IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO,  7)
#define IFX_SE_SYSCALL_PSA_CIPHER_ENCRYPT                  IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 10)
#define IFX_SE_SYSCALL_PSA_CIPHER_DECRYPT                  IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 11)
#define IFX_SE_SYSCALL_PSA_CIPHER_ENCRYPT_SETUP            IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 12)
#define IFX_SE_SYSCALL_PSA_CIPHER_DECRYPT_SETUP            IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 13)
#define IFX_SE_SYSCALL_PSA_CIPHER_GENERATE_IV              IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 14)
#define IFX_SE_SYSCALL_PSA_CIPHER_SET_IV                   IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 15)
#define IFX_SE_SYSCALL_PSA_CIPHER_UPDATE                   IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 16)
#define IFX_SE_SYSCALL_PSA_CIPHER_ABORT                    IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 17)
#define IFX_SE_SYSCALL_PSA_CIPHER_FINISH                   IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 18)
#define IFX_SE_SYSCALL_PSA_SIGN_MESSAGE                    IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 20)
#define IFX_SE_SYSCALL_PSA_VERIFY_MESSAGE                  IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 21)
#define IFX_SE_SYSCALL_PSA_SIGN_HASH                       IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 22)
#define IFX_SE_SYSCALL_PSA_VERIFY_HASH                     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 23)
#define IFX_SE_SYSCALL_PSA_MAC_COMPUTE                     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 30)
#define IFX_SE_SYSCALL_PSA_MAC_VERIFY                      IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 31)
#define IFX_SE_SYSCALL_PSA_MAC_SIGN_SETUP                  IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 32)
#define IFX_SE_SYSCALL_PSA_MAC_VERIFY_SETUP                IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 33)
#define IFX_SE_SYSCALL_PSA_MAC_UPDATE                      IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 34)
#define IFX_SE_SYSCALL_PSA_MAC_SIGN_FINISH                 IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 35)
#define IFX_SE_SYSCALL_PSA_MAC_VERIFY_FINISH               IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 36)
#define IFX_SE_SYSCALL_PSA_MAC_ABORT                       IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 37)
#define IFX_SE_SYSCALL_PSA_AEAD_ENCRYPT                    IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 40)
#define IFX_SE_SYSCALL_PSA_AEAD_DECRYPT                    IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 41)
#define IFX_SE_SYSCALL_PSA_AEAD_ENCRYPT_SETUP              IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 42)
#define IFX_SE_SYSCALL_PSA_AEAD_DECRYPT_SETUP              IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 43)
#define IFX_SE_SYSCALL_PSA_AEAD_GENERATE_NONCE             IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 44)
#define IFX_SE_SYSCALL_PSA_AEAD_SET_NONCE                  IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 45)
#define IFX_SE_SYSCALL_PSA_AEAD_SET_LENGTHS                IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 46)
#define IFX_SE_SYSCALL_PSA_AEAD_UPDATE_AD                  IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 47)
#define IFX_SE_SYSCALL_PSA_AEAD_UPDATE                     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 48)
#define IFX_SE_SYSCALL_PSA_AEAD_FINISH                     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 49)
#define IFX_SE_SYSCALL_PSA_AEAD_VERIFY                     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 50)
#define IFX_SE_SYSCALL_PSA_AEAD_ABORT                      IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 51)
#define IFX_SE_SYSCALL_PSA_IMPORT_KEY                      IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 60)
#define IFX_SE_SYSCALL_PSA_GENERATE_KEY                    IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 61)
#define IFX_SE_SYSCALL_PSA_COPY_KEY                        IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 62)
#define IFX_SE_SYSCALL_PSA_DESTROY_KEY                     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 63)
#define IFX_SE_SYSCALL_PSA_PURGE_KEY                       IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 64)
#define IFX_SE_SYSCALL_PSA_EXPORT_KEY                      IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 65)
#define IFX_SE_SYSCALL_PSA_EXPORT_PUBLIC_KEY               IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 66)
#define IFX_SE_SYSCALL_PSA_GET_KEY_ATTRIBUTES              IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 67)
#define IFX_SE_SYSCALL_PSA_GET_RANDOM                      IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 68)
#define IFX_SE_SYSCALL_PSA_KEY_DERIVATION_SETUP            IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 70)
#define IFX_SE_SYSCALL_PSA_KEY_DERIVATION_GET_CAPACITY     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 71)
#define IFX_SE_SYSCALL_PSA_KEY_DERIVATION_SET_CAPACITY     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 72)
#define IFX_SE_SYSCALL_PSA_KEY_DERIVATION_INPUT_BYTES      IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 73)
#define IFX_SE_SYSCALL_PSA_KEY_DERIVATION_INPUT_KEY        IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 74)
#define IFX_SE_SYSCALL_PSA_KEY_DERIVATION_OUTPUT_BYTES     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 75)
#define IFX_SE_SYSCALL_PSA_KEY_DERIVATION_OUTPUT_KEY       IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 76)
#define IFX_SE_SYSCALL_PSA_KEY_DERIVATION_ABORT            IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 77)
#define IFX_SE_SYSCALL_PSA_KEY_DERIVATION_AGREEMENT        IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 78)
#define IFX_SE_SYSCALL_PSA_RAW_KEY_AGREEMENT               IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PSA_CRYPTO, 79)

/* IFX_SE_SYSCALL_GROUP_RB_COUNTER service IDs */
#define IFX_SE_SYSCALL_GET_ROLLBACK_COUNTER                IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_RB_COUNTER, 90)
#define IFX_SE_SYSCALL_UPDATE_ROLLBACK_COUNTER             IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_RB_COUNTER, 91)
#define IFX_SE_SYSCALL_GET_USAGE_LIMIT_COUNTER             IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_RB_COUNTER, 92)
/* IFX_SE_SYSCALL_GROUP_SERVICES service IDs */
#define IFX_SE_SYSCALL_DISABLE                             IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_SERVICES, 95)
#define IFX_SE_SYSCALL_ENABLE                              IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_SERVICES, 96)
#define IFX_SE_SYSCALL_SET_LPM                             IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_SERVICES, 97)
#define IFX_SE_SYSCALL_GET_INFO                            IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_SERVICES, 98)
/* IFX_SE_SYSCALL_GROUP_ATTESTATION service IDs */
#define IFX_SE_SYSCALL_SET_SHARED_DATA                     IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_ATTESTATION, 100)
#define IFX_SE_SYSCALL_LOCK_SHARED_DATA                    IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_ATTESTATION, 101)
#define IFX_SE_SYSCALL_INIT_ATTEST_GET_TOKEN               IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_ATTESTATION, 102)
#define IFX_SE_SYSCALL_INIT_ATTEST_GET_TOKEN_SIZE          IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_ATTESTATION, 103)
/* IFX_SE_SYSCALL_GROUP_PROTECTION service IDs */
#define IFX_SE_SYSCALL_MPC_CONFIG_ROT_MPC_STRUCT           IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PROTECTION, 110)
#define IFX_SE_SYSCALL_MPC_LOCK                            IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PROTECTION, 111)
#define IFX_SE_SYSCALL_PPC_CONFIG                          IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_PROTECTION, 112)
/* IFX_SE_SYSCALL_GROUP_WIFI service IDs */
#define IFX_SE_SYSCALL_ENABLE_WIFI                         IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_WIFI, 120)
#define IFX_SE_SYSCALL_DISABLE_WIFI                        IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_WIFI, 121)
#define IFX_SE_SYSCALL_ENABLE_WIFI_SRAM_ACCESS             IFX_SE_SYSCALL_CODE(IFX_SE_SYSCALL_GROUP_WIFI, 122)

/* Maximal number of parameters in ipc_packet */
#define SE_RT_MAX_PARAMETERS_NUM         (15u)

/* Calculate packet sizes in 32-bit words */
#define SE_RT_PACKET_CTL_SIZE            (2u) /* only control fields (size and CRC) */
#define SE_RT_PACKET_MIN_SIZE            (SE_RT_PACKET_CTL_SIZE + sizeof(ifx_se_fih_uint) / sizeof(uint32_t)) /* control fields + cmd */
#define SE_RT_PACKET_MAX_SIZE            (SE_RT_PACKET_CTL_SIZE + (SE_RT_MAX_PARAMETERS_NUM + 1u) * sizeof(ifx_se_fih_uint) / sizeof(uint32_t))

/* Total packet size includes params, cmd, data size and CRC32 fields */
#define SE_RT_PACKET_CALC_SIZE(n)        (((2u * sizeof(uint32_t)) + (((n) + 1u) * sizeof(ifx_se_fih_uint))) / 4u)

/* Calculate packet sizes in 32-bit words */
#define SE_RT_PACKET_GET_SIZE(s)         ((s) / sizeof(uint32_t))

/* Get Params address inside ipc_packet to set parameters easily */
#define SE_RT_PARAMS_GET_PTR(p)          ((ifx_se_fih_uint *)(&(p)[1u]))

/* Get Command ID value from Params array inside ipc_packet */
#define SE_RT_PARAMS_GET_CMD(p)          (SE_RT_PARAMS_GET_PTR(p)[0])

/* Calc CRC32 of ipc_packet array of 32-bit word elements */
#define SE_RT_PACKET_FINALIZE(p)         { p[0] = sizeof(p); \
                                           p[(sizeof(p) / sizeof(uint32_t)) - 1u] = IFX_CRC32_CALC((uint8_t *)(p), sizeof(p) - sizeof(uint32_t)); }

typedef ifx_se_fih_uint ifx_se_status_t;

/** \addtogroup syscall_macros
 * \{
 */

/** Maximal number of images to store shared data */
#define IFX_SE_SHARED_DATA_IMAGES_NUM          (7u)

/** \} */

/** \addtogroup syscall_errors
 * \{
 */

/** Makes Secure Runtime Services Utility FIH based error code */
#define IFX_SE_ERROR_CODE(e)                   IFX_SE_FIH_UINT_INIT((uint32_t)(e))

/** Success operation */
#define IFX_SE_SUCCESS                         IFX_SE_ERROR_CODE(0xAA5533CCu)
/** The fail status of the SE RT Services return value */
#define IFX_SE_INVALID                         IFX_SE_ERROR_CODE(0xFF000000u)
/** Returned when SE RT Services in disabled state */
#define IFX_SE_DISABLED                        IFX_SE_ERROR_CODE(0xFF000001u)
/** Returned for non-supported algorithms or operations */
#define IFX_SE_SYSCALL_NOT_SUPPORTED           IFX_SE_ERROR_CODE(0xFF000002u)
/** Returned on general uncategorized error */
#define IFX_SE_SYSCALL_GENERAL_ERROR           IFX_SE_ERROR_CODE(0xFF000003u)
/** Returned by all APIs when client doesn't have access to region it is using for passing arguments. */
#define IFX_SE_SYSCALL_ADDR_PROTECTED          IFX_SE_ERROR_CODE(0xFF000004u)
/** Returned if a master with PC > 2 tries to use PSA syscall */
#define IFX_SE_SYSCALL_PROTECTED               IFX_SE_ERROR_CODE(0xFF000005u)
/** The opcode is not a valid API opcode. */
#define IFX_SE_SYSCALL_INVALID_OPCODE          IFX_SE_ERROR_CODE(0xFF000006u)
/** Returned if invalid arguments are passed to a API or SysCall */
#define IFX_SE_SYSCALL_INVALID_ARGUMENT        IFX_SE_ERROR_CODE(0xFF000007u)
/** \cond INTERNAL */
#define IFX_SE_SYSCALL_KEY_PROTECTED           IFX_SE_ERROR_CODE(0xFF000008u)
/** \endcond */
/** Returned when parameters data in non-supported memory regions (MAIN_NVM, SRAM, SOCMEM_RAM or XIP) */
#define IFX_SE_SYSCALL_ADDR_OUT_OF_RANGE       IFX_SE_ERROR_CODE(0xFF000009u)
/** Returned when Fault Injection attack detected */
#define IFX_SE_SYSCALL_FI_DETECTED             IFX_SE_ERROR_CODE(0xFF00000Au)
/** Returned on storage failures */
#define IFX_SE_SYSCALL_STORAGE_FAILURE         IFX_SE_ERROR_CODE(0xFF00000Bu)
/** Returned when data not written during defined timeout */
#define IFX_SE_SYSCALL_STORAGE_TIMEOUT         IFX_SE_ERROR_CODE(0xFF00000Cu)
/** Returned when over-voltage detected during syscall execution */
#define IFX_SE_SYSCALL_OV_DETECTED             IFX_SE_ERROR_CODE(0xFF00000Du)
/** Returned when RRAM clock (HFCLK0) not corresponding to selected RRAM power mode (LP/ULP) */
#define IFX_SE_SYSCALL_RRAM_CLK_ERROR          IFX_SE_ERROR_CODE(0xFF00000Eu)
/** Returned when CPU clock (HFCLK0) frequency not in the supported range (3,6MHz - 210MHz) */
#define IFX_SE_SYSCALL_INVALID_CLOCK           IFX_SE_ERROR_CODE(0xFF00000Fu)
/** Returned on data integrity (CRC check) error */
#define IFX_SE_SYSCALL_INTEGRITY_FAILURE       IFX_SE_ERROR_CODE(0xFF000010u)
/** Returned when input data bigger then supported */
#define IFX_SE_SYSCALL_INSUFFICIENT_STORAGE    IFX_SE_ERROR_CODE(0xFF000011u)
/** Returned when the output buffer is too small to store the operation output data */
#define IFX_SE_SYSCALL_BUFFER_TOO_SMALL        IFX_SE_ERROR_CODE(0xFF000012u)
/** Returned on output data preparation error */
#define IFX_SE_SYSCALL_DATA_INVALID            IFX_SE_ERROR_CODE(0xFF000013u)
/** Returned when address not aligned */
#define IFX_SE_SYSCALL_ADDR_NOT_ALIGNED        IFX_SE_ERROR_CODE(0xFF000014u)
/** Returned when input data size less then expected */
#define IFX_SE_SYSCALL_INSUFFICIENT_DATA       IFX_SE_ERROR_CODE(0xFF000015u)
/** Returned when number of syscall parameters is incorrect */
#define IFX_SE_SYSCALL_INVALID_PARAM_NUM       IFX_SE_ERROR_CODE(0xFF000016u)
/** Returned when syscall packet data is empty */
#define IFX_SE_SYSCALL_INVALID_PACKET_DATA     IFX_SE_ERROR_CODE(0xFF000017u)
/** Returned when syscall packet size is incorrect */
#define IFX_SE_SYSCALL_INVALID_PACKET_SIZE     IFX_SE_ERROR_CODE(0xFF000018u)
/** Returned when syscall packet data has damaged FIH parameters */
#define IFX_SE_SYSCALL_INVALID_PACKET_PARAM    IFX_SE_ERROR_CODE(0xFF000019u)
/** Returned when no operation context is available */
#define IFX_SE_SYSCALL_INSUFFICIENT_CONTEXT    IFX_SE_ERROR_CODE(0xFF00001Au)
/** Returned when measured temperature is not in supported range (-40C - +125C)
 *
 * Temperature is measured during EPC4 device boot process.
 * User application may read its status by \ref ifx_se_get_info API.
 *
 * When temperature error occurs, it is no longer possible to perform the next
 * operations:
 * - generate key
 * - generate IV, nonce, random data
 * - sign hash or message
 * - key derivation
 * - generate attestation token.
 *
 * To return the Secure Runtime Services to the normal operational state
 * the user application should call sequence of \ref ifx_se_disable and
 * \ref ifx_se_enable when device temperature is returned to allowed range. */
#define IFX_SE_SYSCALL_INVALID_TEMPERATURE     IFX_SE_ERROR_CODE(0xFF00001Bu)
/** Returned when no key usage Limit counter is available */
#define IFX_SE_SYSCALL_INSUFFICIENT_COUNTER    IFX_SE_ERROR_CODE(0xFF00001Cu)
/** Returned when syscall didn't respond until defined timeout */
#define IFX_SE_SYSCALL_TIMEOUT_ERROR           IFX_SE_ERROR_CODE(0xFF0000FEu)
/** Returned when memory allocation failed */
#define IFX_SE_SYSCALL_INVALID_MEM_ALLOC       IFX_SE_ERROR_CODE(0xFF0000FFu)
/** Returned when subsystem is attempted to be powered on but it is already in ON state */
#define IFX_SE_SYSCALL_SS_ON                   IFX_SE_ERROR_CODE(0xFF000100u)
/** Returned when the subsystem is failed to power on */
#define IFX_SE_SYSCALL_SS_POWERON_FAIL         IFX_SE_ERROR_CODE(0xFF000101u)
/** Returned when the subsystem is failed to come out of reset */
#define IFX_SE_SYSCALL_SS_RESET_FAIL           IFX_SE_ERROR_CODE(0xFF000102u)
/** Returned when the subsystem could not transition to the required state to execute the service */
#define IFX_SE_SYSCALL_SS_INVALID_STATE        IFX_SE_ERROR_CODE(0xFF000103u)
/** Returned when data corruption detected */
#define IFX_SE_SYSCALL_CORRUPTION_DETECTED     IFX_SE_ERROR_CODE(0xFFBADBADu)

/** \} */

/** \addtogroup syscall_macros
 * \{
 */

/** \cond INTERNAL */
#define IFX_SE_STATUS_CHECK(x, y)              ifx_se_fih_uint_eq(x, y)
#define IFX_SE_IS_STATUS_SUCCESS(y)            IFX_SE_STATUS_CHECK(IFX_SE_SUCCESS, y)
/** \endcond */

/** SE RT Services user defined syscall context */
#define IFX_SE_NULL_CTX                        NULL

/** Fault injection hardening, IPC data mask */
#define IFX_SE_IPC_FIH_MASK                    (uint32_t)(0x53AD6CB9UL)

/** \} */

/*******************************************************************************
 * SE RT Services syscall communication uses the next IPC settings by default:
 *
 * IPC channel to transfer data to SE RT Services
 * IFX_SE_IPC_SYSCALL =          (0u)
 *
 * IPC interrupt channel to notify SE RT Services for new request
 * IFX_SE_IPC_INTR_ACQ =         (0u)
 *
 * IPC interrupt channel to notify client from SE RT Services
 *                                        for processed request
 * IFX_SE_IPC_INTR_REL =         (1u)
 *
 * \note Syscall communication may be initiated by multiple hosts in a multicore
 *       system. In this case each host should specify its own IPC channel by setting
 *       -DIFX_SE_IPC_SYSCALL = xU, where 'x' is a channel number, in Makefile of its
 *       project, pass this define in build command or use ifx_se_config_template.h.
 *       to define alternative values.
 *
 *       Currently supported channels:
 *
 *          0U for application in PC2;
 *          2U for applications in PC6;
 *
 *       Interrupt channel remains the same and release channel is not used.
 *       IPC channels are subjects for peripheral protections applications set in
 *       SE RT Services.
 *
 * \note For this notification user should setup appropriate
 *       interrupt handler in his code.
 * \note SE RT Services library does not setup this notification handler
 *       by default by using blocking mode to wait for completion.
 *
 *******************************************************************************
 */

/* IPC channel to transfer data to SE RT Services */
#if !defined(IFX_SE_IPC_SYSCALL)
    #define IFX_SE_IPC_SYSCALL                     (0U)
#endif /* IFX_SE_IPC_SYSCALL */

/* IPC interrupt channel to notify SE RT Services for new request */
#if !defined(IFX_SE_IPC_INTR_ACQ)
    #define IFX_SE_IPC_INTR_ACQ                    (0U)
#endif /* IFX_SE_IPC_INTR_ACQ */

/* IPC interrupt channel to notify client from SE RT Services for processed request */
#if !defined(IFX_SE_IPC_INTR_REL)
    #define IFX_SE_IPC_INTR_REL                    (1U)
#endif /* IFX_SE_IPC_INTR_REL */

/** \addtogroup syscall_funcs
 * \{
 */

/*******************************************************************************
 * Function Name: ifx_se_syscall
 ***************************************************************************//**
 *
 * Used to call syscall to SE RT Services.
 *
 * \param[in] ipc_packet: The pointer to the buffer with syscall parameters.
 *
 * \param[in] ipc_packet_size: The size of the buffer with syscall parameters.
 *
 * \param[in] *ctx: The pointer to the SE syscall context that contain a special
 * syscall data (IPC release callback etc).
 *
 * \return \ref IFX_SE_SUCCESS for success or error code
 *
 * \note This function is marked as WEAK so user can replace it
 * by own implementation according to the platform environment
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_syscall(ifx_se_fih_ptr_t ipc_packet, ifx_se_fih_t ipc_packet_size, void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_syscall_builtin
 ***************************************************************************//**
 *
 * Used to perform syscall to SE RT Services.
 *
 * \param[in] ipc_packet: The pointer to the buffer with syscall parameters.
 *
 * \param[in] *ctx: The pointer to the SE syscall context that contain a special
 * syscall data (IPC release callback etc).
 *
 * \return \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_syscall_builtin(ifx_se_fih_ptr_t ipc_packet, void *ctx);

/* Syscall HAL APIs */
/*******************************************************************************
 * Function Name: ifx_se_hal_syscall_lock
 ***************************************************************************//**
 *
 * Used to set syscall execution mutex in multi-threaded environments.
 *
 * Default implementation is not thread-safe and provided as template.
 *
 * \param[in] *ctx: The pointer to the SE syscall context that contain a special
 * syscall data (IPC release callback etc).
 *
 * \return \ref IFX_SE_SUCCESS for success otherwise timeout error.
 *
 * \note This function is marked as WEAK so user can replace it
 * by own implementation according to the platform environment
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_hal_syscall_lock(void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_hal_syscall_start
 ***************************************************************************//**
 *
 * Used to acquire syscall IPC structure.
 * Additionally can be used to register IPC Release event callback.
 *
 * Should use Cy_IPC_Drv_LockAcquire to acquire syscall IPC structure.
 *
 * \param[in] *ctx: The pointer to the SE syscall context that contain a special
 * syscall data (IPC release callback etc).
 *
 * \return \ref IFX_SE_SUCCESS for success otherwise timeout error.
 *
 * \note This function is marked as WEAK so user can replace it
 * by own implementation according to the platform environment
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_hal_syscall_start(void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_hal_syscall_wait_response
 ***************************************************************************//**
 *
 * Used to waiting the syscall response.
 *
 * Should use Cy_IPC_Drv_GetLockStatus or Cy_IPC_Drv_IsLockAcquired
 * to check syscall IPC structure status on waiting.
 *
 * \param[in] *ctx: The pointer to the SE syscall context that contain a special
 * syscall data (IPC release callback etc).
 *
 * \return \ref IFX_SE_SUCCESS for success otherwise timeout error.
 *
 * \note This function is marked as WEAK so user can replace it
 * by own implementation according to the platform environment
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_hal_syscall_wait_response(void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_hal_syscall_release
 ***************************************************************************//**
 *
 * Used to release syscall execution mutex in multi-threaded environments.
 *
 * Default implementation is not thread-safe and provided as template.
 *
 * \param[in] *ctx: The pointer to the SE syscall context that contain a special
 * syscall data (IPC release callback etc).
 *
 * \note This function is marked as WEAK so user can replace it
 * by own implementation according to the platform environment
 *
 ******************************************************************************/
void ifx_se_hal_syscall_release(void *ctx);

/** \} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IFX_SE_SYSCALL_H */
