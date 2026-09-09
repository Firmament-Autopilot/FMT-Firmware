/***************************************************************************//**
* \file ifx_se_platform.h
* \version 1.2.0
*
* \brief
* This is the header file for utility syscall functions.
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
* IFX SE Generic Syscall API definitions
****************************************************************************//**
*
* \defgroup platform     IFX SE Generic Syscall API
* \brief
*  IFX SE Generic Syscall functions
*
* \{
*   \defgroup platform_power Enable/Disable/Power control
*       Enable/Disable/Power control definitions
*   \defgroup platform_rollbacks Anti-rollback counter manipulation
*       Anti-rollback counter manipulation definitions
*   \defgroup platform_attestation Initial Attestation Token
*       Initial Attestation Token definitions
*   \defgroup platform_mpc MPC protection management
*       MPC protection management definitions
*   \defgroup platform_ppc PPC protection management
*       PPC protection management definitions
*   \defgroup platform_wifi WiFi SS control
*       WiFi SS control definitions
* \}
*
*******************************************************************************/

#ifndef IFX_SE_PLATFORM_H
#define IFX_SE_PLATFORM_H

#include "ifx_se_syscall.h"
#include "ifx_se_psacrypto_types.h"
#include "cy_utils.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined(CY_IP_MXS22WIFI1X1AX20TBSS) && defined(CY_IP_MXS22BTSS)
    /* Syscall handler is placed at fixed address in S RT Services code */
    #define IFX_SE_SYSCALL_HANDLER_ADDR         0x120143a5u
#endif /* defined(CY_IP_MXS22WIFI1X1AX20TBSS) && defined(CY_IP_MXS22BTSS) */

/* Public APIs */

/* SE RT Services OTP anti-rollback counters are numbered 0..7 */
#define IFX_SE_OTP_ROLLBACK_COUNTER_NUM_MIN     0u
#define IFX_SE_OTP_ROLLBACK_COUNTER_NUM_MAX     7u

/* SE RT Services RRAM anti-rollback counters are numbered 8..15 */
#define IFX_SE_RRAM_ROLLBACK_COUNTER_NUM_MIN    8u
#define IFX_SE_RRAM_ROLLBACK_COUNTER_NUM_MAX    15u

/* Minimum allowed value of a key tag */
#define IFX_SE_MIN_USER_ALLOWED_KEY_TAG         (IFX_SE_KEY_ID_VENDOR_MAX + 1u)

/** \addtogroup platform_rollbacks
 * \{
 */

/*******************************************************************************
 * Function Name: ifx_se_get_rollback_counter
 ***************************************************************************//**
 *
 * This function reads the Anti-rollback counter.
 *
 * \param[in] number     Anti-rollback counter number (0-15).
 * \param[out] value     The pointer to the counter value of ifx_se_fih_uint
 *                       type.
 * \param[in] ctx        The pointer to the SE syscall context that contain
 *                       a special syscall data (IPC release callback etc).
 *
 * \note For OTP counters if the function is called in concurrent environment
 *       and RRAM controller is locked by another PC, the function immediately
 *       returns an error.
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_get_rollback_counter(ifx_se_fih_t number, ifx_se_fih_ptr_t value, void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_update_rollback_counter
 ***************************************************************************//**
 *
 * Updates the anti-rollback counter to a higher value only.
 *
 * Counters 0...7 are stored in OTP.
 * Counters 8...15 are stored in SFLASH.
 *
 * \param[in] number     Anti-rollback counter number (0-15).
 * \param[in] value      A new 32-bit counter value.
 * \param[in] ctx        The pointer to the SE syscall context that contain
 *                       a special syscall data (IPC release callback etc).
 *
 * \note For OTP counters if the function is called in concurrent environment
 *       and RRAM controller is locked by another PC, the function immediately
 *       returns an error.
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_update_rollback_counter(ifx_se_fih_t number, ifx_se_fih_t value, void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_get_usage_limit_counter
 ***************************************************************************//**
 *
 * This function reads the usage limit counter value for the given key.
 *
 * \param[in] key        Identifier of the key which usage limit counter to read.
 * \param[out] value     The pointer to the 32-bit counter value.
 * \param[in] ctx        The pointer to the SE syscall context that contain
 *                       a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_get_usage_limit_counter(ifx_se_key_id_fih_t key, ifx_se_fih_ptr_t value, void *ctx);

/** \} */

/** \addtogroup platform_power
 * \{
 */

/*******************************************************************************
 * Function Name: ifx_se_disable
 ***************************************************************************//**
 *
 * Disables Clock Supervisor Fault and SE RT Services except Disable and Enable
 * syscalls.
 *
 * \param[in] ctx    The pointer to the SE syscall context that contain
 *                   a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 * \note This function can be used by TF-M to hold SE RT Services
 *       for the clocks and/or power setting update in the SOC.
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_disable(void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_enable
 ***************************************************************************//**
 *
 * Validates clock and power configuration, measures actual device temperature
 * (only on EPC4 device when temperature measurement during boot is out of
 * valid range), configures and enables Clock Supervisor
 * then enables SE RT Services.
 *
 *
 * \param[in] ctx   The pointer to the SE syscall context that contain
 *                  a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success
 * \return    \ref IFX_SE_SYSCALL_RRAM_CLK_ERROR when RRAM clock (HFCLK0)
 *            not corresponding to selected RRAM power mode (LP/ULP)
 * \return    \ref IFX_SE_SYSCALL_INVALID_CLOCK when CPU clock (HFCLK0)
 *            frequency not in the supported range (3,6MHz - 210MHz)
 * \return    \ref IFX_SE_SYSCALL_INVALID_TEMPERATURE when measured temperature
 *            is not in supported range (-40C - +125C)
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_enable(void *ctx);

/** SE power mode */
typedef enum {
    IFX_SE_PM_DEEP_SLEEP = 0,           /**< DeepSleep mode */
    IFX_SE_PM_DEEP_SLEEP_RAM = 1,       /**< DeepSleep RAM mode (obsoleted) */
    IFX_SE_PM_SHUT_OFF = 2,             /**< Shut off mode */
    IFX_SE_PM_MAX                       /**< Maximum value to fix enum size */
} ifx_se_en_power_mode_t;

/*******************************************************************************
 * Function Name: ifx_se_set_lpm
 ***************************************************************************//**
 *
 * Sets power mode which SE RT Services will use during wait for event state.
 *
 * \param[in] mode   Power mode value.
 * \param[in] ctx    The pointer to the SE syscall context that contain
 *                   a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 * \note  This function is only for internal use and couldn't be called directly.
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_set_lpm(ifx_se_en_power_mode_t mode, void *ctx);


/** The structure of data which provides provisioned data shared by RRAM Boot during initialization */
typedef struct
{
#if defined(CY_IP_MXS22WIFI1X1AX20TBSS) && defined(CY_IP_MXS22BTSS)
    uint32_t wifi_ap_ctl;       /**<  WIFI access port control */
    uint32_t wifi_wounding[2];  /**<  1st word is HW wounding, 2nd is SW wounding */
    uint32_t bt_ap_ctl;         /**<  BT access port control */
    uint32_t bt_wounding[2];    /**<  1st word is HW wounding, 2nd is SW wounding */
#else
    int32_t temperature;        /**<  Temperature measured during boot */
#endif /* defined(CY_IP_MXS22WIFI1X1AX20TBSS) && defined(CY_IP_MXS22BTSS) */
} ifx_se_rt_info_t;

/*******************************************************************************
 * Function Name: ifx_se_get_info
 ***************************************************************************//**
 *
 * This function reads the system information passed from RRAM Boot and copies it
 * to output buffer.
 *
 * \param[out] output      Buffer where the output is to be written.
 * \param[in] output_size  Size of the \p output buffer in bytes.
 * \param[in] ctx          The pointer to the SE syscall context that contain
 *                         a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 ******************************************************************************/
ifx_se_status_t ifx_se_get_info(ifx_se_rt_info_t *output, size_t output_size, void *ctx);


/** \} */

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 3.1', 2, \
    'The character sequence "//" is a part of http URL.')

/** \addtogroup platform_attestation
 * \{
 *
 * SE RT Services supports Initial Attestation Token generation according to
 * "Arm's Platform Security Architecture (PSA) Attestation Token" RFC document
 * https://datatracker.ietf.org/doc/draft-tschofenig-rats-psa-token/
 *
 * SE RT Services provide Initial Attestation token generation in next steps:
 * - set shared data (measurements) of images by L1 and L2 bootloaders using
 *   \ref ifx_se_set_shared_data API.
 * - get Initial Attestation token size to allocate memory buffer for token
 * - get Initial Attestation token into provided buffer
 *
 * Shared data can be locked to prevent any changes of measurements
 * using \ref ifx_se_lock_shared_data API.
 *
 * Storage for shared data supports up to 7 data blocks of 0x80 bytes,
 * for IDs from 0 to 6.
 *
 * Attestation token \ref ifx_se_initial_attest_get_token_size API returns
 * MAXIMAL size of possible generated token in CBOR format calculated from:
 * - maximal size of challenge, 64 bytes
 * - size of Client ID, 4 bytes (integer value)
 * - maximal size of Verification Services, 32 bytes
 * - maximal size of Certification Reference (Hardware version),
 *   19 bytes (EAN-13-5 string)
 * - maximal size of Profile definition, 32 bytes
 * - maximal size of Implementation ID, 32 bytes
 * - maximal size of Instance ID, 33 bytes
 * - maximal size of Security lifecycle,  4 bytes (integer value)
 * - maximal size of Boot seed, 32 bytes
 * - software components data claim
 * - set of uploaded shared data blocks, max 0x80 per block
 * - system assets information for ROMBoot, RRAMBoot, L1_Boot, SE RT Services;
 *   data block of 384 bytes
 *
 * Maximal supported token size is 1510 bytes.
 *
 * \note SE RT Services supports only PSA 2.0.0 profile.
 *
 * Software components claim ALWAYS contain information of system assets:
 *
 * | Asset          | Name             | Version              | Descr  | Signer_ID                                                     | Value            |
 * |:---------------|:-----------------|:---------------------|:-------|:--------------------------------------------------------------|:-----------------|
 * | ROMBoot        | "ROM boot"       | actual asset version |        | -                                                             | -                |
 * | RRAMBoot       | "RRAM boot"      | actual asset version | SHA256 | -                                                             | asset image hash |
 * | L1_Boot        | "L1 boot"        | actual asset version | SHA256 | -                                                             | asset image hash |
 * | SE RT Services | "SE RT Services" | actual asset version | SHA256 | hash of the signing key <br>\ref IFX_SE_KEY_ID_BUILTIN_ATTEST | asset image hash |
 */

/*******************************************************************************
 * Function Name: ifx_se_set_shared_data
 ***************************************************************************//**
 *
 * Receives the boot status information (also known as measured boot)
 * in TLV format defined by MCUboot and TF-M design pages.
 *
 * Once data integrity is verified it should be stored in RRAM in SE to support
 * DEEP_SLEEP_RAM mode. Only one successful request should be supported
 * per boot process for L1 and L2 Bootloaders, so data can't be modified
 * by the following after OEM L2 Bootloader image.
 * This shared data will be used to create Initial Attestation Token
 * by ifx_se_initial_attest_get_token function.
 *
 * \param[in] image_id     The image_id to set shared data
 *                         (0 to \ref IFX_SE_SHARED_DATA_IMAGES_NUM - 1).
 * \param[in] data         The pointer to the memory buffer.
 * \param[in] data_size    Size of memory buffer (size_t).
 * \param[in] ctx          The pointer to the SE syscall context that contain
 *                         a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_set_shared_data(ifx_se_fih_t image_id,
                                       const ifx_se_fih_ptr_t data, ifx_se_fih_t data_size,
                                       void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_lock_shared_data
 ***************************************************************************//**
 *
 * Locks receiving the boot status information (also known as measured boot)
 * so the shared data can't be modified.
 *
 * \param[in] ctx          The pointer to the SE syscall context that contain
 *                         a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_lock_shared_data(void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_initial_attest_get_token
 ***************************************************************************//**
 *
 * Gets Initial Attestation Token created as described in the
 * Initial Attestation Service design page.
 *
 * It should support only asymmetric key algorithm based attestation (symmetric
 * attestation not supported).
 * It supports all required EAT claims that are defined in the PSA attestation
 * token specification for the new profile (http://arm.com/psa/2.0.0).
 *
 * \param[in] challenge       The challenge object.
 * \param[in] challenge_size  The length of the challenge object (size_t).
 * \param[in] client_id       The partition ID of that secure partition
 *                            or non-secure thread who called
 *                            the initial attestation API.
 * \param[in] verify_svc      The pointer to verification service id as
 *                            text string that can be used to locate
 *                            the service or a URL specifying the address
 *                            of the service.
 * \param[in] verify_svc_size The length of the verification service id
 *                            (size_t).
 * \param[in] hardware_ver    The pointer to the Certification Reference
 *                            (Hardware version) string that is used to link
 *                            the class of chip and PSA RoT of the attesting
 *                            device to an associated entry in the
 *                            PSA Certification database.
 *                            Must be represented as EAN-13-5 formatted string.
 * \param[in] hardware_ver_size The length of the hardware version (size_t).
 * \param[out] token_data     The pointer to the token buffer.
 * \param[in] token_size      The size of the token buffer (size_t).
 * \param[out] token_length   The pointer to the actual size of the generated
 *                            attestation token (size_t).
 * \param[in] ctx             The pointer to the SE syscall context that contain
 *                            a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 * \note For Secure device LCS the LIFECYCLE claim will contain
 * "Recoverable PSA RoT Debug" value with additional debug state
 * in the lowest byte instead of "Secured" when opened
 * or allowed at least one debug AP:
 * @verbatim
 *                          bits [2:0] - CM33 policy debug AP configuration:
 *                            000 - Disabled, CPU debugging is not allowed, and
 *                                  will be permanently disabled during boot.
 *                            001 - Enabled, CPU debugging will be enabled
 *                                  during boot.
 *                            010 - Allowed + Firmware, trusted Firmware can
 *                                  directly access DAP control register.
 *                            011 - Allowed + Certificate, firmware or SYS-AP
 *                                  must provide a debug certificate.
 *                            100 - Allowed + Open, any firmware can
 *                                  directly access DAP control register.
 *                          bit [3] - CM0+ debug AP is enabled
 *                          bit [4] - device provisioned for non-production
 *                                  (development) flow
 * @endverbatim
 *
 * \note The Implementation ID claim contains device specific data constructed
 * from DIE_ID, DEVICE_ID_TO and DEVICE_ID_MPN fields:
 * @verbatim
 *                          bytes [9:0]   - DIE_ID
 *                          bytes [12:10] - DEVICE_ID_TO
 *                          bytes [14:13] - DEVICE_ID_MPN
 * @endverbatim
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_initial_attest_get_token(const ifx_se_fih_ptr_t challenge,
                                                ifx_se_fih_t challenge_size,
                                                ifx_se_fih_t client_id,
                                                const ifx_se_fih_ptr_t verify_svc,
                                                ifx_se_fih_t verify_svc_size,
                                                const ifx_se_fih_ptr_t hardware_ver,
                                                ifx_se_fih_t hardware_ver_size,
                                                ifx_se_fih_ptr_t token_data,
                                                ifx_se_fih_t token_size,
                                                ifx_se_fih_ptr_t token_length,
                                                void *ctx);
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 3.1')

/*******************************************************************************
 * Function Name: ifx_se_initial_attest_get_token_size
 ***************************************************************************//**
 *
 * Gets Initial Attestation Token maximal size to allocate token buffer.
 *
 * Use this value to allocate space for ifx_se_initial_attest_get_token.
 *
 * \param[in] challenge_size  The length of the challenge object (size_t).
 * \param[out] token_size     The pointer to the actual length of the
 *                            attestation token (size_t).
 * \param[in] ctx             The pointer to the SE syscall context that contain
 *                            a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_initial_attest_get_token_size(ifx_se_fih_t challenge_size,
                                                     ifx_se_fih_ptr_t token_size,
                                                     void *ctx);
/** \} */

/** \addtogroup platform_mpc
 * \{
 */

/** MPC access permission */
typedef enum
{
    IFX_SE_MPC_ACCESS_DISABLED = 0x00,  /**< Read and Write disabled */
    IFX_SE_MPC_ACCESS_R = 0x01,         /**< Read enabled */
    IFX_SE_MPC_ACCESS_W = 0x02,         /**< Write enabled */
    IFX_SE_MPC_ACCESS_RW = 0x03,        /**< Read and Write enabled */
    IFX_SE_MPC_ACCESS_MAX = INT32_MAX,  /**< Maximum value to fix enum size */
} ifx_se_mpc_access_attr_t;

/** MPC security permission */
typedef enum
{
    IFX_SE_MPC_SECURE = 0x0,                /**< Secure */
    IFX_SE_MPC_NON_SECURE = 0x1,            /**< Non-secure */
    IFX_SE_MPC_SEC_ATTR_MAX = INT32_MAX,    /**< Maximum value to fix enum size */
} ifx_se_mpc_sec_attr_t;

/** MPC block size */
typedef enum
{
    IFX_SE_MPC_SIZE_4KB = 7,            /**< 4 Kilobytes */
    IFX_SE_MPC_SIZE_MAX = INT32_MAX,    /**< Maximum value to fix enum size */
} ifx_se_mpc_size_t;

/** MPC protection context */
typedef enum
{
    IFX_SE_MPC_PC_2 = 2,                /**< PC 2 */
    IFX_SE_MPC_PC_3 = 3,                /**< PC 3 */
    IFX_SE_MPC_PC_4 = 4,                /**< PC 4 */
    IFX_SE_MPC_PC_5 = 5,                /**< PC 5 */
    IFX_SE_MPC_PC_6 = 6,                /**< PC 6 */
    IFX_SE_MPC_PC_7 = 7,                /**< PC 7 */
    IFX_SE_MPC_PC_MAX = INT32_MAX,      /**< Maximum value to fix enum size */
} ifx_se_mpc_prot_context_t;

/** MPC configuration structure */
typedef struct
{
    uint32_t addr_offset;               /**< Offset in the memory from the memory start address */
    uint32_t size;                      /**< Size of the memory */
    ifx_se_mpc_size_t region_size;      /**< Size of the memory region */
    ifx_se_mpc_prot_context_t pc;       /**< Protection Context */
    ifx_se_mpc_sec_attr_t secure;       /**< Security permissions for the region */
    ifx_se_mpc_access_attr_t access;    /**< Access permissions for the region */
} ifx_se_mpc_rot_cfg_t;

/** MPC configuration structure with checksum */
typedef struct
{
    ifx_se_mpc_rot_cfg_t mpc_config;    /**< MPC configuration data */
    uint32_t crc;                       /**< checksum */
} ifx_se_mpc_rot_cfg_crc_t;

/*******************************************************************************
 * Function Name: ifx_se_mpc_config_rot_mpc_struct
 ***************************************************************************//**
 *
 * Initializes the MPC by setting the PC, NS/S and RW/R/W permissions
 * for RRAM memory region.
 *
 * This function allows to configure only one MPC structure: RRAM Host port
 * with permissions for PC>1. Can be called by PC=2 only and does not allow
 * to modify MPC configuration for the regions PC=2 does not have access to.
 *
 * \param[in] mpc_config    The pointer to the MPC configuration structure.
 * \param[in] ctx           The pointer to the SE syscall context that contain
 *                          a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_mpc_config_rot_mpc_struct(const ifx_se_mpc_rot_cfg_crc_t *mpc_config, void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_mpc_lock
 ***************************************************************************//**
 *
 * Locks the MPC configuration.
 * This function allows to lock only one MPC structure: RRAM Host port
 *
 * \param[in] ctx    The pointer to the SE syscall context that contain
 *                   a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_mpc_lock(void *ctx);

/** \} */

/** \addtogroup platform_ppc
 * \{
 */

/** PPC security attributes */
typedef enum
{
    IFX_SE_PPC_SECURE     = 0,          /**< PPC region is Secure */
    IFX_SE_PPC_NON_SECURE = 1,          /**< PPC region is Non-secure */
    IFX_SE_PPC_MAX        = INT32_MAX,  /**< Maximum value to fix enum size */
} ifx_se_ppc_sec_attribute_t;

/** PPC Non-secure privilege attributes */
typedef enum
{
    IFX_SE_PPC_NON_SEC_PRIV    = 0,          /**< Privilege access to non-secure region */
    IFX_SE_PPC_NON_SEC_NONPRIV = 1,          /**< Privilege and non-privilege access to non-secure region  */
    IFX_SE_PPC_NON_SEC_MAX     = INT32_MAX,  /**< Maximum value to fix enum size */
} ifx_se_ppc_nspriv_attribute_t;

/** PPC Secure privilege attributes */
typedef enum
{
    IFX_SE_PPC_SEC_PRIV    = 0,          /**< Privilege access to secure region */
    IFX_SE_PPC_SEC_NONPRIV = 1,          /**< Privilege and non-privilege access to secure region  */
    IFX_SE_PPC_SEC_MAX     = INT32_MAX,  /**< Maximum value to fix enum size */
} ifx_se_ppc_secpriv_attribute_t;

/** PPC configuration structure */
typedef struct {
    uint32_t start_region;                             /**< Starting peripheral region ID */
    uint32_t end_region;                               /**< Ending peripheral region ID. To apply policy to a single peripheral region, assign the same value to start_region and endRegion */
    ifx_se_ppc_sec_attribute_t sec_attribute;          /**< Security attribute */
    ifx_se_ppc_secpriv_attribute_t sec_priv_attribute; /**< Secure Privilege attribute */
    ifx_se_ppc_nspriv_attribute_t ns_priv_attribute;   /**< Non-secure Privilege attribute */
    uint32_t pc_mask;                                  /**< PC mask */
} ifx_se_ppc_config_t;


/*******************************************************************************
 * Function Name: ifx_se_ppc_config
 ***************************************************************************//**
 *
 * Configures the PPC with the PC mask, security and access attributes
 *
 * This function allows to configure only WiFi SS SRAM PPC regions.
 * Returns error if this function is called outside of WiFi SS PC.
 *
 * \param[in] ppc_config    The pointer to the PPC configuration structure.
 * \param[in] ctx           The pointer to the SE syscall context that contain
 *                          a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_ppc_config(const ifx_se_ppc_config_t *ppc_config, void *ctx);

/** \} */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IFX_SE_PLATFORM_H */
