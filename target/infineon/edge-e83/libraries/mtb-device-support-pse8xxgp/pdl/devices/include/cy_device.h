/***************************************************************************//**
* \file cy_device.h
* \version 2.0
*
* This file specifies the structure for core and peripheral block HW base
* addresses, versions, and parameters.
*
********************************************************************************/
#ifndef CY_DEVICE_H_
#define CY_DEVICE_H_

#include <stdint.h>
#include <stddef.h>

#include "cy_utils.h"
#include "startup_edge.h"
#include "cmsis_compiler.h"
#ifndef PSE84_PSVP_UUT
#include "cy_device_headers.h"
#endif
/* CM55 NPU global defines */
#ifndef ETHOSU55
#define ETHOSU55
#endif
#ifndef ETHOSU_ARCH
#define ETHOSU_ARCH u55
#endif

/* This is a feature flag available only for PSoC Edge devices supporting Cy_SysClk_PeriGroupSlaveInit
*/
#define CY_DEVICE_CONFIGURATOR_IP_ENABLE_FEATURE

/* The SW workaround for RRAM on PSE84 silicon */
#if (defined(CY_IP_MXS22RRAMC_VERSION) && (CY_IP_MXS22RRAMC_VERSION) < 2) && !defined(COMPONENT_CM0P)
#define WA__PM_0159902_6
#endif

/* Defines a start address of the default vector table */
#ifndef CY_SYS_CM55_DEFAULT_VECTOR_ADDRESS
/* For PSE84 the default vector table is in ITCM memory */
#define CY_SYS_CM55_DEFAULT_VECTOR_ADDRESS    (CY_CM55_ITCM_NS_SBUS_BASE)
#endif /* CY_SYS_DEFAULT_VECTOR_ADDRESS */

#if (defined(CY_IP_MXS22SRSS_VERSION) && (CY_IP_MXS22SRSS_VERSION == 1))
/* This forces the DPLL LP trim values to be updated in the personality */
#define UPDATE_DPLL_LP_TRIM_VALUES
#endif /* (defined(CY_IP_MXS22SRSS_VERSION) && (CY_IP_MXS22SRSS_VERSION == 1)) */

/* DIE_ID and REV_ID registers located in the NS_SFLASH sub-region
   of the RRAM PROTECTED NVM region */
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE               (0x03C2B000UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_SI_REV            (0x03C2B010UL)

/* DIE_ID_0 register masks */
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_LOT0_Pos      (0UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_LOT0_Msk      (0xFFUL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_LOT1_Pos      (8UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_LOT1_Msk      (0xFF00UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_LOT2_Pos      (16UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_LOT2_Msk      (0xFF0000UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_WAFER_Pos     (24UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_WAFER_Msk     (0xFF000000UL)
/* DIE_ID_1 register masks */
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_X_Pos         (0UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_X_Msk         (0xFFUL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_Y_Pos         (8UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_Y_Msk         (0xFF00UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_SORT_Pos      (16UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_SORT_Msk      (0xFF0000UL)
/* DIE_ID_2 register masks */
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_YEAR_Pos      (8UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_DIE_YEAR_Msk      (0xFF00UL)
/* SI_REV register masks */
#define CY_RRAM_PROTECTED_NS_SFLASH_SI_REV_MINOR_Pos  (0UL)
#define CY_RRAM_PROTECTED_NS_SFLASH_SI_REV_MINOR_Msk  (0x1UL)


CY_MISRA_FP_BLOCK_START('MISRA C-2012 Rule 8.6', 1, \
'Checked manually. The definition is a part of linker script.')

/** Device descriptor type */
typedef struct
{
    /* Base HW addresses */
    uint32_t hsiomBase;
    uint32_t gpioBase;

    /* IP block versions: [7:4] major, [3:0] minor */
    uint8_t  dwVersion;

    /* Parameters */
    uint8_t  cpussDw0ChNr;
    uint8_t  cpussDw1ChNr;
    uint8_t  epMonitorNr;

    /* Peripheral register offsets */

   /* DW registers */
    uint16_t dwChOffset;
    uint16_t dwChSize;
    uint8_t  dwChCtlPrioPos;
    uint8_t  dwChCtlPreemptablePos;
    uint8_t  dwStatusChIdxPos;
    uint32_t dwStatusChIdxMsk;

    uint8_t  tcpwmCC1Present;
    uint8_t  tcpwmAMCPresent;
    uint8_t  tcpwmSMCPrecent;

} cy_stc_device_t;

/* Pointer to device configuration structure */
#define CY_DEVICE_CFG                   (&cy_deviceIpBlockCfg)

/*******************************************************************************
*                   Global Variables
*******************************************************************************/

extern const cy_stc_device_t   cy_deviceIpBlockCfg;
extern const cy_stc_device_t* cy_device;

/*******************************************************************************
*               Macro Definitions
*******************************************************************************/
#define SECURE_ALIAS_OFFSET                 0x10000000UL
#ifdef CY_PDL_TZ_ENABLED
#define GET_ALIAS_ADDRESS(addr)             ((uint32_t)((uint32_t)(addr) | SECURE_ALIAS_OFFSET))
#else
#define GET_ALIAS_ADDRESS(addr)             ((uint32_t)((uint32_t)(addr) & ~(SECURE_ALIAS_OFFSET)))
#endif
#define GET_NSALIAS_ADDRESS(addr)           ((uint32_t)((uint32_t)(addr) & ~(SECURE_ALIAS_OFFSET)))


/*******************************************************************************
*                   Function Prototypes
*******************************************************************************/

void Cy_PDL_Init(const cy_stc_device_t * device);

/*******************************************************************************
*               Register Access Helper Macros
*******************************************************************************/
#define CY_CRYPTO_V1                        (0U) /* We have mxcrypto_v2 IP */
typedef CRYPTO_V2_Type CRYPTO_Type;

/*******************************************************************************
*               SDHC
*******************************************************************************/
#define SDHC_WRAP_CTL(base)                     (((SDHC_Type *)(base))->WRAP.CTL)
#define SDHC_CORE_SDMASA_R(base)                (((SDHC_Type *)(base))->CORE.SDMASA_R)
#define SDHC_CORE_BLOCKSIZE_R(base)             (((SDHC_Type *)(base))->CORE.BLOCKSIZE_R)
#define SDHC_CORE_BLOCKCOUNT_R(base)            (((SDHC_Type *)(base))->CORE.BLOCKCOUNT_R)
#define SDHC_CORE_ARGUMENT_R(base)              (((SDHC_Type *)(base))->CORE.ARGUMENT_R)
#define SDHC_CORE_XFER_MODE_R(base)             (((SDHC_Type *)(base))->CORE.XFER_MODE_R)
#define SDHC_CORE_CMD_R(base)                   (((SDHC_Type *)(base))->CORE.CMD_R)
#define SDHC_CORE_RESP01_R(base)                (((SDHC_Type *)(base))->CORE.RESP01_R)
#define SDHC_CORE_RESP23_R(base)                (((SDHC_Type *)(base))->CORE.RESP23_R)
#define SDHC_CORE_RESP45_R(base)                (((SDHC_Type *)(base))->CORE.RESP45_R)
#define SDHC_CORE_RESP67_R(base)                (((SDHC_Type *)(base))->CORE.RESP67_R)
#define SDHC_CORE_BUF_DATA_R(base)              (((SDHC_Type *)(base))->CORE.BUF_DATA_R)
#define SDHC_CORE_PSTATE_REG(base)              (((SDHC_Type *)(base))->CORE.PSTATE_REG)
#define SDHC_CORE_HOST_CTRL1_R(base)            (((SDHC_Type *)(base))->CORE.HOST_CTRL1_R)
#define SDHC_CORE_PWR_CTRL_R(base)              (((SDHC_Type *)(base))->CORE.PWR_CTRL_R)
#define SDHC_CORE_BGAP_CTRL_R(base)             (((SDHC_Type *)(base))->CORE.BGAP_CTRL_R)
#define SDHC_CORE_WUP_CTRL_R(base)              (((SDHC_Type *)(base))->CORE.WUP_CTRL_R)
#define SDHC_CORE_CLK_CTRL_R(base)              (((SDHC_Type *)(base))->CORE.CLK_CTRL_R)
#define SDHC_CORE_TOUT_CTRL_R(base)             (((SDHC_Type *)(base))->CORE.TOUT_CTRL_R)
#define SDHC_CORE_SW_RST_R(base)                (((SDHC_Type *)(base))->CORE.SW_RST_R)
#define SDHC_CORE_NORMAL_INT_STAT_R(base)       (((SDHC_Type *)(base))->CORE.NORMAL_INT_STAT_R)
#define SDHC_CORE_ERROR_INT_STAT_R(base)        (((SDHC_Type *)(base))->CORE.ERROR_INT_STAT_R)
#define SDHC_CORE_NORMAL_INT_STAT_EN_R(base)    (((SDHC_Type *)(base))->CORE.NORMAL_INT_STAT_EN_R)
#define SDHC_CORE_ERROR_INT_STAT_EN_R(base)     (((SDHC_Type *)(base))->CORE.ERROR_INT_STAT_EN_R)
#define SDHC_CORE_NORMAL_INT_SIGNAL_EN_R(base)  (((SDHC_Type *)(base))->CORE.NORMAL_INT_SIGNAL_EN_R)
#define SDHC_CORE_ERROR_INT_SIGNAL_EN_R(base)   (((SDHC_Type *)(base))->CORE.ERROR_INT_SIGNAL_EN_R)
#define SDHC_CORE_AUTO_CMD_STAT_R(base)         (((SDHC_Type *)(base))->CORE.AUTO_CMD_STAT_R)
#define SDHC_CORE_HOST_CTRL2_R(base)            (((SDHC_Type *)(base))->CORE.HOST_CTRL2_R)
#define SDHC_CORE_CAPABILITIES1_R(base)         (((SDHC_Type *)(base))->CORE.CAPABILITIES1_R)
#define SDHC_CORE_CAPABILITIES2_R(base)         (((SDHC_Type *)(base))->CORE.CAPABILITIES2_R)
#define SDHC_CORE_CURR_CAPABILITIES1_R(base)    (((SDHC_Type *)(base))->CORE.CURR_CAPABILITIES1_R)
#define SDHC_CORE_CURR_CAPABILITIES2_R(base)    (((SDHC_Type *)(base))->CORE.CURR_CAPABILITIES2_R)
#define SDHC_CORE_ADMA_ERR_STAT_R(base)         (((SDHC_Type *)(base))->CORE.ADMA_ERR_STAT_R)
#define SDHC_CORE_ADMA_SA_LOW_R(base)           (((SDHC_Type *)(base))->CORE.ADMA_SA_LOW_R)
#define SDHC_CORE_ADMA_ID_LOW_R(base)           (((SDHC_Type *)(base))->CORE.ADMA_ID_LOW_R)
#define SDHC_CORE_EMMC_CTRL_R(base)             (((SDHC_Type *)(base))->CORE.EMMC_CTRL_R)
#define SDHC_CORE_GP_OUT_R(base)                (((SDHC_Type *)(base))->CORE.GP_OUT_R)

/*******************************************************************************
*                SMARTIO
*******************************************************************************/

#define SMARTIO_PRT_CTL(base)               (((SMARTIO_PRT_Type *)(base))->CTL)
#define SMARTIO_PRT_SYNC_CTL(base)          (((SMARTIO_PRT_Type *)(base))->SYNC_CTL)
#define SMARTIO_PRT_LUT_SEL(base, idx)      (((SMARTIO_PRT_Type *)(base))->LUT_SEL[idx])
#define SMARTIO_PRT_LUT_CTL(base, idx)      (((SMARTIO_PRT_Type *)(base))->LUT_CTL[idx])
#define SMARTIO_PRT_DU_SEL(base)            (((SMARTIO_PRT_Type *)(base))->DU_SEL)
#define SMARTIO_PRT_DU_CTL(base)            (((SMARTIO_PRT_Type *)(base))->DU_CTL)
#define SMARTIO_PRT_DATA(base)              (((SMARTIO_PRT_Type *)(base))->DATA)


/*******************************************************************************
*                SMIF
*******************************************************************************/

/* Feature Flags - Start
 * Few products have very less memory available in BOOT ROM and they do not require
 * SFDP enumeration of Octal parts. Hence, we introduce feature flags to enable
 * specific features only where Octal SFDP enumeration and Hyperbus devices are supported
 * using below feature flags
 */
#define SMIF_OCTAL_SFDP_SUPPORT
#define SMIF_HYPERBUS_DEVICE_SUPPORT
#define SMIF_JEDEC_STANDARD_DEVICE_RESET_SUPPORT
/* Feature Flags - End */

#define SMIF_DEVICE_CTL_WR_EN_Pos                    SMIF_CORE_DEVICE_CTL_WR_EN_Pos
#define SMIF_DEVICE_CTL_CRYPTO_EN_Pos                SMIF_CORE_DEVICE_CTL_CRYPTO_EN_Pos
#define SMIF_DEVICE_CTL_MERGE_EN_Pos                 SMIF_CORE_DEVICE_CTL_MERGE_EN_Pos
#define SMIF_DEVICE_CTL_MERGE_TIMEOUT_Pos            SMIF_CORE_DEVICE_CTL_MERGE_TIMEOUT_Pos
#define SMIF_DEVICE_CTL_TOTAL_TIMEOUT_Pos            SMIF_CORE_DEVICE_CTL_TOTAL_TIMEOUT_Pos
#define SMIF_DEVICE_CTL_TOTAL_TIMEOUT_EN_Pos         SMIF_CORE_DEVICE_CTL_TOTAL_TIMEOUT_EN_Pos
#define SMIF_DEVICE_CTL_ENABLED_Pos                  SMIF_CORE_DEVICE_CTL_ENABLED_Pos
#define SMIF_DEVICE_ADDR_ADDR_Pos                    SMIF_CORE_DEVICE_ADDR_ADDR_Pos
#define SMIF_DEVICE_ADDR_CTL_SIZE3_Pos               SMIF_CORE_DEVICE_ADDR_CTL_SIZE3_Pos
#define SMIF_DEVICE_ADDR_CTL_DIV2_Pos                SMIF_CORE_DEVICE_ADDR_CTL_DIV2_Pos
#define SMIF_DEVICE_RD_CMD_CTL_CODE_Pos              SMIF_CORE_DEVICE_RD_CMD_CTL_CODE_Pos
#define SMIF_DEVICE_RD_CMD_CTL_CODEH_Pos             SMIF_CORE_DEVICE_RD_CMD_CTL_CODEH_Pos
#define SMIF_DEVICE_RD_CMD_CTL_DDR_MODE_Pos          SMIF_CORE_DEVICE_RD_CMD_CTL_DDR_MODE_Pos
#define SMIF_DEVICE_RD_CMD_CTL_WIDTH_Pos             SMIF_CORE_DEVICE_RD_CMD_CTL_WIDTH_Pos
#define SMIF_DEVICE_RD_CMD_CTL_PRESENT2_Pos          SMIF_CORE_DEVICE_RD_CMD_CTL_PRESENT2_Pos
#define SMIF_DEVICE_RD_ADDR_CTL_WIDTH_Pos            SMIF_CORE_DEVICE_RD_ADDR_CTL_WIDTH_Pos
#define SMIF_DEVICE_RD_ADDR_CTL_DDR_MODE_Pos         SMIF_CORE_DEVICE_RD_ADDR_CTL_DDR_MODE_Pos
#define SMIF_DEVICE_RD_MODE_CTL_CODE_Pos             SMIF_CORE_DEVICE_RD_MODE_CTL_CODE_Pos
#define SMIF_DEVICE_RD_MODE_CTL_CODEH_Pos            SMIF_CORE_DEVICE_RD_MODE_CTL_CODEH_Pos
#define SMIF_DEVICE_RD_MODE_CTL_WIDTH_Pos            SMIF_CORE_DEVICE_RD_MODE_CTL_WIDTH_Pos
#define SMIF_DEVICE_RD_MODE_CTL_DDR_MODE_Pos         SMIF_CORE_DEVICE_RD_MODE_CTL_DDR_MODE_Pos
#define SMIF_DEVICE_RD_MODE_CTL_PRESENT2_Pos         SMIF_CORE_DEVICE_RD_MODE_CTL_PRESENT2_Pos
#define SMIF_DEVICE_RD_DUMMY_CTL_SIZE5_Pos           SMIF_CORE_DEVICE_RD_DUMMY_CTL_SIZE5_Pos
#define SMIF_DEVICE_RD_DUMMY_CTL_PRESENT2_Pos        SMIF_CORE_DEVICE_RD_DUMMY_CTL_PRESENT2_Pos
#define SMIF_DEVICE_RD_DATA_CTL_WIDTH_Pos            SMIF_CORE_DEVICE_RD_DATA_CTL_WIDTH_Pos
#define SMIF_DEVICE_RD_DATA_CTL_DDR_MODE_Pos         SMIF_CORE_DEVICE_RD_DATA_CTL_DDR_MODE_Pos
#define SMIF_DEVICE_WR_CMD_CTL_CODE_Pos              SMIF_CORE_DEVICE_WR_CMD_CTL_CODE_Pos
#define SMIF_DEVICE_WR_CMD_CTL_CODEH_Pos             SMIF_CORE_DEVICE_WR_CMD_CTL_CODEH_Pos
#define SMIF_DEVICE_WR_CMD_CTL_DDR_MODE_Pos          SMIF_CORE_DEVICE_WR_CMD_CTL_DDR_MODE_Pos
#define SMIF_DEVICE_WR_CMD_CTL_WIDTH_Pos             SMIF_CORE_DEVICE_WR_CMD_CTL_WIDTH_Pos
#define SMIF_DEVICE_WR_CMD_CTL_PRESENT2_Pos          SMIF_CORE_DEVICE_WR_CMD_CTL_PRESENT2_Pos
#define SMIF_DEVICE_WR_ADDR_CTL_WIDTH_Pos            SMIF_CORE_DEVICE_WR_ADDR_CTL_WIDTH_Pos
#define SMIF_DEVICE_WR_ADDR_CTL_DDR_MODE_Pos         SMIF_CORE_DEVICE_WR_ADDR_CTL_DDR_MODE_Pos
#define SMIF_DEVICE_WR_MODE_CTL_CODE_Pos             SMIF_CORE_DEVICE_WR_MODE_CTL_CODE_Pos
#define SMIF_DEVICE_WR_MODE_CTL_CODEH_Pos            SMIF_CORE_DEVICE_WR_MODE_CTL_CODEH_Pos
#define SMIF_DEVICE_WR_MODE_CTL_WIDTH_Pos            SMIF_CORE_DEVICE_WR_MODE_CTL_WIDTH_Pos
#define SMIF_DEVICE_WR_MODE_CTL_DDR_MODE_Pos         SMIF_CORE_DEVICE_WR_MODE_CTL_DDR_MODE_Pos
#define SMIF_DEVICE_WR_MODE_CTL_PRESENT2_Pos         SMIF_CORE_DEVICE_WR_MODE_CTL_PRESENT2_Pos
#define SMIF_DEVICE_WR_DUMMY_CTL_SIZE5_Pos           SMIF_CORE_DEVICE_WR_DUMMY_CTL_SIZE5_Pos
#define SMIF_DEVICE_WR_DUMMY_CTL_PRESENT2_Pos        SMIF_CORE_DEVICE_WR_DUMMY_CTL_PRESENT2_Pos
#define SMIF_DEVICE_WR_DUMMY_CTL_RWDS_EN_Pos         SMIF_CORE_DEVICE_WR_DUMMY_CTL_RWDS_EN_Pos
#define SMIF_DEVICE_WR_DATA_CTL_WIDTH_Pos            SMIF_CORE_DEVICE_WR_DATA_CTL_WIDTH_Pos
#define SMIF_DEVICE_WR_DATA_CTL_DDR_MODE_Pos         SMIF_CORE_DEVICE_WR_DATA_CTL_DDR_MODE_Pos
#define SMIF_DEVICE_RD_BOUND_CTL_SIZE5_Pos           SMIF_CORE_DEVICE_RD_BOUND_CTL_SIZE5_Pos
#define SMIF_DEVICE_RD_BOUND_CTL_SUB_PAGE_SIZE_Pos   SMIF_CORE_DEVICE_RD_BOUND_CTL_SUB_PAGE_SIZE_Pos
#define SMIF_DEVICE_RD_BOUND_CTL_SUB_PAGE_NR_Pos     SMIF_CORE_DEVICE_RD_BOUND_CTL_SUB_PAGE_NR_Pos
#define SMIF_DEVICE_RD_BOUND_CTL_SUBSEQ_BOUND_EN_Pos SMIF_CORE_DEVICE_RD_BOUND_CTL_SUBSEQ_BOUND_EN_Pos
#define SMIF_DEVICE_RD_BOUND_CTL_PRESENT_Pos         SMIF_CORE_DEVICE_RD_BOUND_CTL_PRESENT_Pos

#define SMIF_DEVICE_CTL_WR_EN_Msk                  SMIF_CORE_DEVICE_CTL_WR_EN_Msk
#define SMIF_DEVICE_CTL_CRYPTO_EN_Msk              SMIF_CORE_DEVICE_CTL_CRYPTO_EN_Msk
#define SMIF_DEVICE_CTL_MERGE_EN_Msk               SMIF_CORE_DEVICE_CTL_MERGE_EN_Msk
#define SMIF_DEVICE_CTL_MERGE_TIMEOUT_Msk          SMIF_CORE_DEVICE_CTL_MERGE_TIMEOUT_Msk
#define SMIF_DEVICE_CTL_TOTAL_TIMEOUT_Msk          SMIF_CORE_DEVICE_CTL_TOTAL_TIMEOUT_Msk
#define SMIF_DEVICE_CTL_TOTAL_TIMEOUT_EN_Msk       SMIF_CORE_DEVICE_CTL_TOTAL_TIMEOUT_EN_Msk
#define SMIF_DEVICE_CTL_ENABLED_Msk                SMIF_CORE_DEVICE_CTL_ENABLED_Msk
#define SMIF_DEVICE_ADDR_ADDR_Msk                  SMIF_CORE_DEVICE_ADDR_ADDR_Msk
#define SMIF_DEVICE_ADDR_CTL_SIZE3_Msk             SMIF_CORE_DEVICE_ADDR_CTL_SIZE3_Msk
#define SMIF_DEVICE_ADDR_CTL_DIV2_Msk              SMIF_CORE_DEVICE_ADDR_CTL_DIV2_Msk
#define SMIF_DEVICE_RD_CMD_CTL_CODE_Msk            SMIF_CORE_DEVICE_RD_CMD_CTL_CODE_Msk
#define SMIF_DEVICE_RD_CMD_CTL_CODEH_Msk           SMIF_CORE_DEVICE_RD_CMD_CTL_CODEH_Msk
#define SMIF_DEVICE_RD_CMD_CTL_DDR_MODE_Msk        SMIF_CORE_DEVICE_RD_CMD_CTL_DDR_MODE_Msk
#define SMIF_DEVICE_RD_CMD_CTL_WIDTH_Msk           SMIF_CORE_DEVICE_RD_CMD_CTL_WIDTH_Msk
#define SMIF_DEVICE_RD_CMD_CTL_PRESENT2_Msk        SMIF_CORE_DEVICE_RD_CMD_CTL_PRESENT2_Msk
#define SMIF_DEVICE_RD_ADDR_CTL_WIDTH_Msk          SMIF_CORE_DEVICE_RD_ADDR_CTL_WIDTH_Msk
#define SMIF_DEVICE_RD_ADDR_CTL_DDR_MODE_Msk       SMIF_CORE_DEVICE_RD_ADDR_CTL_DDR_MODE_Msk
#define SMIF_DEVICE_RD_MODE_CTL_CODE_Msk           SMIF_CORE_DEVICE_RD_MODE_CTL_CODE_Msk
#define SMIF_DEVICE_RD_MODE_CTL_CODEH_Msk          SMIF_CORE_DEVICE_RD_MODE_CTL_CODEH_Msk
#define SMIF_DEVICE_RD_MODE_CTL_WIDTH_Msk          SMIF_CORE_DEVICE_RD_MODE_CTL_WIDTH_Msk
#define SMIF_DEVICE_RD_MODE_CTL_DDR_MODE_Msk       SMIF_CORE_DEVICE_RD_MODE_CTL_DDR_MODE_Msk
#define SMIF_DEVICE_RD_MODE_CTL_PRESENT2_Msk       SMIF_CORE_DEVICE_RD_MODE_CTL_PRESENT2_Msk
#define SMIF_DEVICE_RD_DUMMY_CTL_SIZE5_Msk         SMIF_CORE_DEVICE_RD_DUMMY_CTL_SIZE5_Msk
#define SMIF_DEVICE_RD_DUMMY_CTL_PRESENT2_Msk      SMIF_CORE_DEVICE_RD_DUMMY_CTL_PRESENT2_Msk
#define SMIF_DEVICE_RD_DATA_CTL_WIDTH_Msk          SMIF_CORE_DEVICE_RD_DATA_CTL_WIDTH_Msk
#define SMIF_DEVICE_RD_DATA_CTL_DDR_MODE_Msk       SMIF_CORE_DEVICE_RD_DATA_CTL_DDR_MODE_Msk
#define SMIF_DEVICE_WR_CMD_CTL_CODE_Msk            SMIF_CORE_DEVICE_WR_CMD_CTL_CODE_Msk
#define SMIF_DEVICE_WR_CMD_CTL_CODEH_Msk           SMIF_CORE_DEVICE_WR_CMD_CTL_CODEH_Msk
#define SMIF_DEVICE_WR_CMD_CTL_DDR_MODE_Msk        SMIF_CORE_DEVICE_WR_CMD_CTL_DDR_MODE_Msk
#define SMIF_DEVICE_WR_CMD_CTL_WIDTH_Msk           SMIF_CORE_DEVICE_WR_CMD_CTL_WIDTH_Msk
#define SMIF_DEVICE_WR_CMD_CTL_PRESENT2_Msk        SMIF_CORE_DEVICE_WR_CMD_CTL_PRESENT2_Msk
#define SMIF_DEVICE_WR_ADDR_CTL_WIDTH_Msk          SMIF_CORE_DEVICE_WR_ADDR_CTL_WIDTH_Msk
#define SMIF_DEVICE_WR_ADDR_CTL_DDR_MODE_Msk       SMIF_CORE_DEVICE_WR_ADDR_CTL_DDR_MODE_Msk
#define SMIF_DEVICE_WR_MODE_CTL_CODE_Msk           SMIF_CORE_DEVICE_WR_MODE_CTL_CODE_Msk
#define SMIF_DEVICE_WR_MODE_CTL_CODEH_Msk          SMIF_CORE_DEVICE_WR_MODE_CTL_CODEH_Msk
#define SMIF_DEVICE_WR_MODE_CTL_WIDTH_Msk          SMIF_CORE_DEVICE_WR_MODE_CTL_WIDTH_Msk
#define SMIF_DEVICE_WR_MODE_CTL_DDR_MODE_Msk       SMIF_CORE_DEVICE_WR_MODE_CTL_DDR_MODE_Msk
#define SMIF_DEVICE_WR_MODE_CTL_PRESENT2_Msk       SMIF_CORE_DEVICE_WR_MODE_CTL_PRESENT2_Msk
#define SMIF_DEVICE_WR_DUMMY_CTL_SIZE5_Msk         SMIF_CORE_DEVICE_WR_DUMMY_CTL_SIZE5_Msk
#define SMIF_DEVICE_WR_DUMMY_CTL_PRESENT2_Msk      SMIF_CORE_DEVICE_WR_DUMMY_CTL_PRESENT2_Msk
#define SMIF_DEVICE_WR_DUMMY_CTL_RWDS_EN_Msk       SMIF_CORE_DEVICE_WR_DUMMY_CTL_RWDS_EN_Msk
#define SMIF_DEVICE_WR_DATA_CTL_WIDTH_Msk          SMIF_CORE_DEVICE_WR_DATA_CTL_WIDTH_Msk
#define SMIF_DEVICE_WR_DATA_CTL_DDR_MODE_Msk       SMIF_CORE_DEVICE_WR_DATA_CTL_DDR_MODE_Msk
#define SMIF_DEVICE_MASK_MASK_Msk                  SMIF_CORE_DEVICE_MASK_MASK_Msk

#define SMIF_DEVICE_RD_BOUND_CTL_SIZE5_Msk           SMIF_CORE_DEVICE_RD_BOUND_CTL_SIZE5_Msk
#define SMIF_DEVICE_RD_BOUND_CTL_SUB_PAGE_SIZE_Msk   SMIF_CORE_DEVICE_RD_BOUND_CTL_SUB_PAGE_SIZE_Msk
#define SMIF_DEVICE_RD_BOUND_CTL_SUB_PAGE_NR_Msk     SMIF_CORE_DEVICE_RD_BOUND_CTL_SUB_PAGE_NR_Msk
#define SMIF_DEVICE_RD_BOUND_CTL_SUBSEQ_BOUND_EN_Msk SMIF_CORE_DEVICE_RD_BOUND_CTL_SUBSEQ_BOUND_EN_Msk
#define SMIF_DEVICE_RD_BOUND_CTL_PRESENT_Msk         SMIF_CORE_DEVICE_RD_BOUND_CTL_PRESENT_Msk

#define SMIF_RX_DATA_FIFO_CTL                      SMIF_RX_DATA_MMIO_FIFO_CTL
#define SMIF_RX_DATA_FIFO_RD4                      SMIF_RX_DATA_MMIO_FIFO_RD4
#define SMIF_RX_DATA_FIFO_RD1                      SMIF_RX_DATA_MMIO_FIFO_RD1
#define SMIF_RX_DATA_FIFO_RD2                      SMIF_RX_DATA_MMIO_FIFO_RD2

#define SMIF_TX_DATA_FIFO_CTL                      SMIF_TX_DATA_MMIO_FIFO_CTL
#define SMIF_TX_DATA_FIFO_WR4                      SMIF_TX_DATA_MMIO_FIFO_WR4
#define SMIF_TX_DATA_FIFO_WR1                      SMIF_TX_DATA_MMIO_FIFO_WR1
#define SMIF_TX_DATA_FIFO_WR2                      SMIF_TX_DATA_MMIO_FIFO_WR2

#define SMIF_TX_CMD_MMIO_FIFO_STATUS_USED4_Msk     SMIF_CORE_TX_CMD_MMIO_FIFO_STATUS_USED4_Msk
#define SMIF_TX_CMD_MMIO_FIFO_STATUS_USED4_Pos     SMIF_CORE_TX_CMD_MMIO_FIFO_STATUS_USED4_Pos

#define SMIF_TX_DATA_MMIO_FIFO_STATUS_USED4_Msk    SMIF_CORE_TX_DATA_MMIO_FIFO_STATUS_USED4_Msk
#define SMIF_TX_DATA_MMIO_FIFO_STATUS_USED4_Pos    SMIF_CORE_TX_DATA_MMIO_FIFO_STATUS_USED4_Pos

#define SMIF_RX_DATA_MMIO_FIFO_STATUS_USED4_Msk    SMIF_CORE_RX_DATA_MMIO_FIFO_STATUS_USED4_Msk
#define SMIF_RX_DATA_MMIO_FIFO_STATUS_USED4_Pos    SMIF_CORE_RX_DATA_MMIO_FIFO_STATUS_USED4_Pos

#define SMIF_STATUS_BUSY_Msk                       SMIF_CORE_STATUS_BUSY_Msk
#define SMIF_STATUS_BUSY_Pos                       SMIF_CORE_STATUS_BUSY_Pos
#define SMIF_DEVICE_Type                           SMIF_CORE_DEVICE_Type
#define SMIF_Type                                  SMIF_CORE_Type
#define SMIF_Base_Type                             SMIF_STRUCT_Type
#define CY_SMIF_CORE_COUNT                         (2U)
#if defined (SMIF_BRIDGE_PRESENT) && (SMIF_BRIDGE_PRESENT == 1U)
#define CY_SMIF_BRIDGE_REMAP_REGION_COUNT          (8U)
#endif

#define SMIF_FAST_CA_CMD_INV_Msk                   SMIF_CORE_FAST_CA_CMD_INV_Msk
#define SMIF_FAST_CA_CTL_PREF_EN_Msk               SMIF_CORE_FAST_CA_CTL_PREF_EN_Msk
#define SMIF_FAST_CA_CTL_ENABLED_Msk               SMIF_CORE_FAST_CA_CTL_ENABLED_Msk

#define SMIF_SLOW_CA_CMD_INV_Msk                   SMIF_CORE_SLOW_CA_CMD_INV_Msk
#define SMIF_SLOW_CA_CTL_ENABLED_Msk               SMIF_CORE_SLOW_CA_CTL_ENABLED_Msk
#define SMIF_SLOW_CA_CTL_PREF_EN_Msk               SMIF_CORE_SLOW_CA_CTL_PREF_EN_Msk

#define SMIF_SMIF_CRYPTO_CRYPTO_CMD_START_Pos      SMIF_CORE_SMIF_CRYPTO_CRYPTO_CMD_START_Pos
#define SMIF_SMIF_CRYPTO_CRYPTO_CMD_START_Msk      SMIF_CORE_SMIF_CRYPTO_CRYPTO_CMD_START_Msk

#define SMIF_DEVICE_CTL_CRYPTO_EN_Msk              SMIF_CORE_DEVICE_CTL_CRYPTO_EN_Msk
#define SMIF_INTR_TR_TX_REQ_Msk                    SMIF_CORE_INTR_TR_TX_REQ_Msk
#define SMIF_INTR_TR_RX_REQ_Msk                    SMIF_CORE_INTR_TR_RX_REQ_Msk
#define SMIF_INTR_XIP_ALIGNMENT_ERROR_Msk          SMIF_CORE_INTR_XIP_ALIGNMENT_ERROR_Msk
#define SMIF_INTR_TX_CMD_FIFO_OVERFLOW_Msk         SMIF_CORE_INTR_TX_CMD_FIFO_OVERFLOW_Msk
#define SMIF_INTR_TX_DATA_FIFO_OVERFLOW_Msk        SMIF_CORE_INTR_TX_DATA_FIFO_OVERFLOW_Msk
#define SMIF_INTR_TR_RX_REQ_Msk                    SMIF_CORE_INTR_TR_RX_REQ_Msk
#define SMIF_INTR_RX_DATA_FIFO_UNDERFLOW_Msk       SMIF_CORE_INTR_RX_DATA_MMIO_FIFO_UNDERFLOW_Msk
#define SMIF_STATUS_BUSY_Msk                       SMIF_CORE_STATUS_BUSY_Msk
#define SMIF_RX_DATA_MMIO_FIFO_STATUS_USED4_Msk    SMIF_CORE_RX_DATA_MMIO_FIFO_STATUS_USED4_Msk
#define SMIF_TX_DATA_MMIO_FIFO_STATUS_USED4_Msk    SMIF_CORE_TX_DATA_MMIO_FIFO_STATUS_USED4_Msk
#define SMIF_TX_CMD_MMIO_FIFO_STATUS_USED4_Msk     SMIF_CORE_TX_CMD_MMIO_FIFO_STATUS_USED4_Msk
#define SMIF_CTL_DESELECT_DELAY_Msk                SMIF_CORE_CTL_DESELECT_DELAY_Msk
#define SMIF_CTL_DESELECT_DELAY_Pos                SMIF_CORE_CTL_DESELECT_DELAY_Pos
#define SMIF_DEVICE_RD_DATA_CTL_DDR_MODE_Msk       SMIF_CORE_DEVICE_RD_DATA_CTL_DDR_MODE_Msk
#define SMIF_DEVICE_CTL_DATA_SEL_Msk               SMIF_CORE_DEVICE_CTL_DATA_SEL_Msk
#define SMIF_CTL_ENABLED_Msk                       SMIF_CORE_CTL_ENABLED_Msk
#define SMIF_CTL_ENABLED_Pos                       SMIF_CORE_CTL_ENABLED_Pos
#define SMIF_DEVICE_CTL_DATA_SEL_Msk               SMIF_CORE_DEVICE_CTL_DATA_SEL_Msk
#define SMIF_CTL_XIP_MODE_Pos                      SMIF_CORE_CTL_XIP_MODE_Pos
#define SMIF_CTL_XIP_MODE_Msk                      SMIF_CORE_CTL_XIP_MODE_Msk
#define SMIF_CTL_BLOCK_Pos                         SMIF_CORE_CTL_BLOCK_Pos
#define SMIF_CTL_BLOCK_Msk                         SMIF_CORE_CTL_BLOCK_Msk
#define SMIF_CTL_CLOCK_IF_SEL_Pos                  SMIF_CORE_CTL_CLOCK_IF_SEL_Pos
#define SMIF_CTL_CLOCK_IF_SEL_Msk                  SMIF_CORE_CTL_CLOCK_IF_SEL_Msk

#define SMIF_DEVICE_CTL_DATA_SEL_Pos               SMIF_CORE_DEVICE_CTL_DATA_SEL_Pos
#define SMIF_CRYPTO_CMD_START_Pos                  SMIF_CORE_SMIF_CRYPTO_CRYPTO_CMD_START_Pos
#define SMIF_CRYPTO_CMD_START_Msk                  SMIF_CORE_SMIF_CRYPTO_CRYPTO_CMD_START_Msk

#if defined (CY_IP_MXSMIF) && (CY_IP_MXSMIF_VERSION == 5)
#define CY_SMIF_GPIO_BASE                         ((uint32_t)SMIF0_CORE0_SMIF_GPIO_SMIF_PRT0)
#define CY_SMIF_HSIOM_BASE                        ((uint32_t)SMIF0_CORE0_SMIF_HSIOM_SMIF_PRT0)
#define CY_SMIF_SECURE_HSIOM_BASE                 ((uint32_t)SMIF0_CORE0_SMIF_HSIOM_SMIF_SECURE_PRT0)
#else
#define CY_SMIF_GPIO_BASE                         ((uint32_t)SMIF0_CORE_SMIF_GPIO_SMIF_PRT0)
#define CY_SMIF_HSIOM_BASE                        ((uint32_t)SMIF0_CORE_SMIF_HSIOM_SMIF_PRT0)
#define CY_SMIF_SECURE_HSIOM_BASE                 ((uint32_t)SMIF0_CORE_SMIF_HSIOM_SMIF_SECURE_PRT0)
#endif
#define SMIF_CRYPTO_CMD(base)            (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_CMD)
#define SMIF_CRYPTO_ADDR(base)           (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_ADDR)
#define SMIF_CRYPTO_MASK(base)           (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_MASK)
#define SMIF_CRYPTO_SUBREGION(base)      (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_SUBREGION)
#define SMIF_CRYPTO_INPUT0(base)         (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_INPUT0)
#define SMIF_CRYPTO_INPUT1(base)         (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_INPUT1)
#define SMIF_CRYPTO_INPUT2(base)         (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_INPUT2)
#define SMIF_CRYPTO_INPUT3(base)         (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_INPUT3)
#define SMIF_CRYPTO_KEY0(base)           (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_KEY0)
#define SMIF_CRYPTO_KEY1(base)           (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_KEY1)
#define SMIF_CRYPTO_KEY2(base)           (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_KEY2)
#define SMIF_CRYPTO_KEY3(base)           (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_KEY3)
#define SMIF_CRYPTO_OUTPUT0(base)        (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_OUTPUT0)
#define SMIF_CRYPTO_OUTPUT1(base)        (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_OUTPUT1)
#define SMIF_CRYPTO_OUTPUT2(base)        (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_OUTPUT2)
#define SMIF_CRYPTO_OUTPUT3(base)        (((SMIF_CORE_Type*) base)->SMIF_CRYPTO_BLOCK[0].CRYPTO_OUTPUT3)

#define SMIF_CRYPTO_IDX(base, deviceIndex)                 (((SMIF_CORE_Type *)(base))->SMIF_CRYPTO_BLOCK[deviceIndex])

#define SMIF_CRYPTO_IDX_CMD(base, deviceIndex)             (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_CMD)
#define SMIF_CRYPTO_IDX_ADDR(base, deviceIndex)            (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_ADDR)
#define SMIF_CRYPTO_IDX_MASK(base, deviceIndex)            (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_MASK)
#define SMIF_CRYPTO_IDX_SUBREGION(base, deviceIndex)       (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_SUBREGION)
#define SMIF_CRYPTO_IDX_INPUT0(base, deviceIndex)          (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_INPUT0)
#define SMIF_CRYPTO_IDX_INPUT1(base, deviceIndex)          (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_INPUT1)
#define SMIF_CRYPTO_IDX_INPUT2(base, deviceIndex)          (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_INPUT2)
#define SMIF_CRYPTO_IDX_INPUT3(base, deviceIndex)          (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_INPUT3)
#define SMIF_CRYPTO_IDX_KEY0(base, deviceIndex)            (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_KEY0)
#define SMIF_CRYPTO_IDX_KEY1(base, deviceIndex)            (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_KEY1)
#define SMIF_CRYPTO_IDX_KEY2(base, deviceIndex)            (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_KEY2)
#define SMIF_CRYPTO_IDX_KEY3(base, deviceIndex)            (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_KEY3)
#define SMIF_CRYPTO_IDX_OUTPUT0(base, deviceIndex)         (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_OUTPUT0)
#define SMIF_CRYPTO_IDX_OUTPUT1(base, deviceIndex)         (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_OUTPUT1)
#define SMIF_CRYPTO_IDX_OUTPUT2(base, deviceIndex)         (SMIF_CRYPTO_IDX(base, deviceIndex).CRYPTO_OUTPUT2)

#if defined (SMIF_BRIDGE_PRESENT) && (SMIF_BRIDGE_PRESENT == 1U)
#define SMIF_BRIDGE_CTL(base)                              ((((SMIF_Base_Type *)base)->SMIF_BRIDGE).CTL)
#define SMIF_REMAPREGION_CTL(base, index)                  (((((SMIF_Base_Type *)base)->SMIF_BRIDGE).SMIF_REMAP_REGION[index]).CTL)
#define SMIF_REMAPREGION_ADDR(base, index)                 (((((SMIF_Base_Type *)base)->SMIF_BRIDGE).SMIF_REMAP_REGION[index]).ADDR)
#define SMIF_REMAPREGION_MASK(base, index)                 (((((SMIF_Base_Type *)base)->SMIF_BRIDGE).SMIF_REMAP_REGION[index]).MASK)
#define SMIF_REMAPREGION_SMIF0_REMAP(base, index)          (((((SMIF_Base_Type *)base)->SMIF_BRIDGE).SMIF_REMAP_REGION[index]).SMIF0_REMAP)
#define SMIF_REMAPREGION_SMIF1_REMAP(base, index)          (((((SMIF_Base_Type *)base)->SMIF_BRIDGE).SMIF_REMAP_REGION[index]).SMIF1_REMAP)
#endif

#define SMIF_DEVICE_CTL(base)               (((SMIF_CORE_DEVICE_Type *)(base))->CTL)
#define SMIF_DEVICE_ADDR(base)              (((SMIF_CORE_DEVICE_Type *)(base))->ADDR)
#define SMIF_DEVICE_ADDR_CTL(base)          (((SMIF_CORE_DEVICE_Type *)(base))->ADDR_CTL)
#define SMIF_DEVICE_MASK(base)              (((SMIF_CORE_DEVICE_Type *)(base))->MASK)
#define SMIF_DEVICE_RD_CMD_CTL(base)        (((SMIF_CORE_DEVICE_Type *)(base))->RD_CMD_CTL)
#define SMIF_DEVICE_RD_ADDR_CTL(base)       (((SMIF_CORE_DEVICE_Type *)(base))->RD_ADDR_CTL)
#define SMIF_DEVICE_RD_MODE_CTL(base)       (((SMIF_CORE_DEVICE_Type *)(base))->RD_MODE_CTL)
#define SMIF_DEVICE_RD_DUMMY_CTL(base)      (((SMIF_CORE_DEVICE_Type *)(base))->RD_DUMMY_CTL)
#define SMIF_DEVICE_RD_DATA_CTL(base)       (((SMIF_CORE_DEVICE_Type *)(base))->RD_DATA_CTL)
#define SMIF_DEVICE_RD_BOUND_CTL(base)      (((SMIF_DEVICE_Type *)(base))->RD_BOUND_CTL)
#define SMIF_DEVICE_WR_CMD_CTL(base)        (((SMIF_CORE_DEVICE_Type *)(base))->WR_CMD_CTL)
#define SMIF_DEVICE_WR_ADDR_CTL(base)       (((SMIF_CORE_DEVICE_Type *)(base))->WR_ADDR_CTL)
#define SMIF_DEVICE_WR_MODE_CTL(base)       (((SMIF_CORE_DEVICE_Type *)(base))->WR_MODE_CTL)
#define SMIF_DEVICE_WR_DUMMY_CTL(base)      (((SMIF_CORE_DEVICE_Type *)(base))->WR_DUMMY_CTL)
#define SMIF_DEVICE_WR_DATA_CTL(base)       (((SMIF_CORE_DEVICE_Type *)(base))->WR_DATA_CTL)
#define SMIF_DEVICE_RX_CAPTURE_CONFIG(base) (((SMIF_CORE_DEVICE_Type *)(base))->RX_CAPTURE_CONFIG)
#define SMIF_DEVICE_HB_FW_DEL_TAP_SEL_0(base) (((SMIF_CORE_DEVICE_Type *)(base))->HB_FW_DEL_TAP_SEL_0)
#define SMIF_DEVICE_HB_FW_DEL_TAP_SEL_1(base) (((SMIF_CORE_DEVICE_Type *)(base))->HB_FW_DEL_TAP_SEL_1)


#define SMIF_DEVICE_IDX(base, deviceIndex)                 (((SMIF_CORE_Type *)(base))->DEVICE[deviceIndex])

#define SMIF_DEVICE_IDX_CTL(base, deviceIndex)             (SMIF_DEVICE_IDX(base, deviceIndex).CTL)
#define SMIF_DEVICE_IDX_ADDR(base, deviceIndex)            (SMIF_DEVICE_IDX(base, deviceIndex).ADDR)
#define SMIF_DEVICE_IDX_ADDR_CTL(base, deviceIndex)        (SMIF_DEVICE_IDX(base, deviceIndex).ADDR_CTL)
#define SMIF_DEVICE_IDX_MASK(base, deviceIndex)            (SMIF_DEVICE_IDX(base, deviceIndex).MASK)
#define SMIF_DEVICE_IDX_RD_CMD_CTL(base, deviceIndex)      (SMIF_DEVICE_IDX(base, deviceIndex).RD_CMD_CTL)
#define SMIF_DEVICE_IDX_RD_ADDR_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).RD_ADDR_CTL)
#define SMIF_DEVICE_IDX_RD_MODE_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).RD_MODE_CTL)
#define SMIF_DEVICE_IDX_RD_DUMMY_CTL(base, deviceIndex)    (SMIF_DEVICE_IDX(base, deviceIndex).RD_DUMMY_CTL)
#define SMIF_DEVICE_IDX_RD_DATA_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).RD_DATA_CTL)
#define SMIF_DEVICE_IDX_WR_CMD_CTL(base, deviceIndex)      (SMIF_DEVICE_IDX(base, deviceIndex).WR_CMD_CTL)
#define SMIF_DEVICE_IDX_WR_ADDR_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).WR_ADDR_CTL)
#define SMIF_DEVICE_IDX_WR_MODE_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).WR_MODE_CTL)
#define SMIF_DEVICE_IDX_WR_DUMMY_CTL(base, deviceIndex)    (SMIF_DEVICE_IDX(base, deviceIndex).WR_DUMMY_CTL)
#define SMIF_DEVICE_IDX_WR_DATA_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).WR_DATA_CTL)
#define SMIF_DEVICE_IDX_RX_CAPTURE_CONFIG(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).RX_CAPTURE_CONFIG)

#define SMIF_CORE_IDX(base, coreIndex)                     (((SMIF_Type *)(base))->CORE[coreIndex])

#define SMIF_CTL(base)                            (((SMIF_CORE_Type *)(base))->CTL)
#define SMIF_CTL2(base)                           (((SMIF_CORE_Type *)(base))->CTL2)
#define SMIF_STATUS(base)                         (((SMIF_CORE_Type *)(base))->STATUS)
#define SMIF_INT_CLOCK_DELAY_TAP_SEL0(base)       (((SMIF_CORE_Type *)(base))->INT_CLOCK_DELAY_TAP_SEL0)
#define SMIF_INT_CLOCK_DELAY_TAP_SEL1(base)       (((SMIF_CORE_Type *)(base))->INT_CLOCK_DELAY_TAP_SEL1)
#define SMIF_DLP_DELAY_TAP_SEL0(base)             (((SMIF_CORE_Type *)(base))->DLP_DELAY_TAP_SEL0)
#define SMIF_DLP_DELAY_TAP_SEL1(base)             (((SMIF_CORE_Type *)(base))->DLP_DELAY_TAP_SEL1)
#define SMIF_DLP_CTL(base)                        (((SMIF_CORE_Type *)(base))->DLP_CTL)
#define SMIF_DL_STATUS0(base)                     (((SMIF_CORE_Type *)(base))->DL_STATUS0)
#define SMIF_DL_STATUS1(base)                     (((SMIF_CORE_Type *)(base))->DL_STATUS1)
#define SMIF_TX_CMD_FIFO_STATUS(base)             (((SMIF_CORE_Type *)(base))->TX_CMD_FIFO_STATUS)
#define SMIF_TX_CMD_MMIO_FIFO_STATUS(base)        (((SMIF_CORE_Type *)(base))->TX_CMD_MMIO_FIFO_STATUS)
#define SMIF_TX_CMD_MMIO_FIFO_WR(base)            (((SMIF_CORE_Type *)(base))->TX_CMD_MMIO_FIFO_WR)
#define SMIF_TX_DATA_MMIO_FIFO_CTL(base)          (((SMIF_CORE_Type *)(base))->TX_DATA_MMIO_FIFO_CTL)
#define SMIF_TX_DATA_FIFO_STATUS(base)            (((SMIF_CORE_Type *)(base))->TX_DATA_FIFO_STATUS)
#define SMIF_TX_DATA_MMIO_FIFO_STATUS(base)       (((SMIF_CORE_Type *)(base))->TX_DATA_MMIO_FIFO_STATUS)
#define SMIF_TX_DATA_MMIO_FIFO_WR1(base)          (((SMIF_CORE_Type *)(base))->TX_DATA_MMIO_FIFO_WR1)
#define SMIF_TX_DATA_MMIO_FIFO_WR2(base)          (((SMIF_CORE_Type *)(base))->TX_DATA_MMIO_FIFO_WR2)
#define SMIF_TX_DATA_MMIO_FIFO_WR4(base)          (((SMIF_CORE_Type *)(base))->TX_DATA_MMIO_FIFO_WR4)
#define SMIF_TX_DATA_MMIO_FIFO_WR1ODD(base)       (((SMIF_CORE_Type *)(base))->TX_DATA_MMIO_FIFO_WR1ODD)
#define SMIF_RX_DATA_MMIO_FIFO_CTL(base)          (((SMIF_CORE_Type *)(base))->RX_DATA_MMIO_FIFO_CTL)
#define SMIF_RX_DATA_MMIO_FIFO_STATUS(base)       (((SMIF_CORE_Type *)(base))->RX_DATA_MMIO_FIFO_STATUS)
#define SMIF_RX_DATA_FIFO_STATUS(base)            (((SMIF_CORE_Type *)(base))->RX_DATA_FIFO_STATUS)
#define SMIF_RX_DATA_MMIO_FIFO_RD1(base)          (((SMIF_CORE_Type *)(base))->RX_DATA_MMIO_FIFO_RD1)
#define SMIF_RX_DATA_MMIO_FIFO_RD2(base)          (((SMIF_CORE_Type *)(base))->RX_DATA_MMIO_FIFO_RD2)
#define SMIF_RX_DATA_MMIO_FIFO_RD4(base)          (((SMIF_CORE_Type *)(base))->RX_DATA_MMIO_FIFO_RD4)
#define SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT(base)   (((SMIF_CORE_Type *)(base))->RX_DATA_MMIO_FIFO_RD1_SILENT)
#define SMIF_SLOW_CA_CTL(base)                    (((SMIF_CORE_Type *)(base))->SLOW_CA_CTL)
#define SMIF_SLOW_CA_CMD(base)                    (((SMIF_CORE_Type *)(base))->SLOW_CA_CMD)
#define SMIF_FAST_CA_CTL(base)                    (((SMIF_CORE_Type *)(base))->FAST_CA_CTL)
#define SMIF_FAST_CA_CMD(base)                    (((SMIF_CORE_Type *)(base))->FAST_CA_CMD)
#define SMIF_CRC_CMD(base)                        (((SMIF_CORE_Type *)(base))->CRC_CMD)
#define SMIF_CRC_INPUT0(base)                     (((SMIF_CORE_Type *)(base))->CRC_INPUT0)
#define SMIF_CRC_INPUT1(base)                     (((SMIF_CORE_Type *)(base))->CRC_INPUT1)
#define SMIF_CRC_OUTPUT(base)                     (((SMIF_CORE_Type *)(base))->CRC_OUTPUT)
#define SMIF_INTR(base)                           (((SMIF_CORE_Type *)(base))->INTR)
#define SMIF_INTR_SET(base)                       (((SMIF_CORE_Type *)(base))->INTR_SET)
#define SMIF_INTR_MASK(base)                      (((SMIF_CORE_Type *)(base))->INTR_MASK)
#define SMIF_INTR_MASKED(base)                    (((SMIF_CORE_Type *)(base))->INTR_MASKED)
#define SMIF_CLK_HSIOM(base)                      (((SMIF_CORE_Type *)(base))->SMIF_HSIOM.SMIF_PRT[1].PORT_SEL0)
#define SMIF_RWDS_HSIOM(base)                     (((SMIF_CORE_Type *)(base))->SMIF_HSIOM.SMIF_PRT[2].PORT_SEL0)
#define SMIF_CLK_DRIVEMODE(base)                  (((SMIF_CORE_Type *)(base))->SMIF_GPIO.SMIF_PRT[1].CFG)
#define SMIF_RWDS_DRIVEMODE(base)                 (((SMIF_CORE_Type *)(base))->SMIF_GPIO.SMIF_PRT[2].CFG)
#define SMIF_CLK_DRIVE_STRENGTH(base)             (((SMIF_CORE_Type *)(base))->SMIF_GPIO.SMIF_PRT[1].CFG_DRIVE_EXT0)
#define SMIF_RWDS_DRIVE_STRENGTH(base)            (((SMIF_CORE_Type *)(base))->SMIF_GPIO.SMIF_PRT[2].CFG_DRIVE_EXT0)
#define SMIF_IDAC(base)                           (((SMIF_CORE_Type *)(base))->DLL_IDAC)

#if (CY_IP_MXSMIF_VERSION == 6)
#define SMIF_DEVICE_NR SMIF0_DEVICE_NR
#endif

#ifndef SMIF_DELAY_TAPS_NR
#define SMIF_DELAY_TAPS_NR 16u
#endif

#define SMIF_CORE0_SS0_PORT           (GPIO_PRT5)
#define SMIF_CORE0_SS0_PIN            (0U)
#define SMIF_CORE0_SS1_PORT           (GPIO_PRT2)
#define SMIF_CORE0_SS1_PIN            (0U)
#define SMIF_CORE0_SS2_PORT           (GPIO_PRT6)
#define SMIF_CORE0_SS2_PIN            (7U)
#define SMIF_CORE0_SS3_PORT           (GPIO_PRT7)
#define SMIF_CORE0_SS3_PIN            (0U)

#define SMIF_CORE1_SS0_PORT           (GPIO_PRT21)
#define SMIF_CORE1_SS0_PIN            (0U)
#define SMIF_CORE1_SS1_PORT           (GPIO_PRT0)
#define SMIF_CORE1_SS1_PIN            (0U)
#define SMIF_CORE1_SS2_PORT           (GPIO_PRT0)
#define SMIF_CORE1_SS2_PIN            (1U)
#define SMIF_CORE1_SS3_PORT           (GPIO_PRT12)
#define SMIF_CORE1_SS3_PIN            (3U)

#define SMIF_CORE0_SS_PORT(slaveSelectId)       ((slaveSelectId == CY_SMIF_SLAVE_SELECT_0) ? SMIF_CORE0_SS0_PORT : \
                                                ((slaveSelectId == CY_SMIF_SLAVE_SELECT_1) ? SMIF_CORE0_SS1_PORT : \
												((slaveSelectId == CY_SMIF_SLAVE_SELECT_2) ? SMIF_CORE0_SS2_PORT : SMIF_CORE0_SS3_PORT)))
#define SMIF_CORE1_SS_PORT(slaveSelectId)       ((slaveSelectId == CY_SMIF_SLAVE_SELECT_0) ? SMIF_CORE1_SS0_PORT : \
                                                ((slaveSelectId == CY_SMIF_SLAVE_SELECT_1) ? SMIF_CORE1_SS1_PORT : \
												((slaveSelectId == CY_SMIF_SLAVE_SELECT_2) ? SMIF_CORE1_SS2_PORT : SMIF_CORE1_SS3_PORT)))

#define SMIF_CORE0_SS_PIN(slaveSelectId)        ((slaveSelectId == CY_SMIF_SLAVE_SELECT_0) ? SMIF_CORE0_SS0_PIN : \
                                                ((slaveSelectId == CY_SMIF_SLAVE_SELECT_1) ? SMIF_CORE0_SS1_PIN : \
												((slaveSelectId == CY_SMIF_SLAVE_SELECT_2) ? SMIF_CORE0_SS2_PIN : SMIF_CORE0_SS3_PIN)))
#define SMIF_CORE1_SS_PIN(slaveSelectId)        ((slaveSelectId == CY_SMIF_SLAVE_SELECT_0) ? SMIF_CORE1_SS0_PIN : \
                                                ((slaveSelectId == CY_SMIF_SLAVE_SELECT_1) ? SMIF_CORE1_SS1_PIN : \
												((slaveSelectId == CY_SMIF_SLAVE_SELECT_2) ? SMIF_CORE1_SS2_PIN : SMIF_CORE1_SS3_PIN)))

#if defined (CY_IP_MXSMIF) && (CY_IP_MXSMIF_VERSION == 6)
#define SMIF_SS_PORT(base, slaveIndex)  (((base) == SMIF0_CORE) ? (SMIF_CORE0_SS_PORT((slaveIndex))) : (SMIF_CORE1_SS_PORT((slaveIndex))))
#define SMIF_SS_PIN(base, slaveIndex)   (((base) == SMIF0_CORE) ? (SMIF_CORE0_SS_PIN((slaveIndex))) : (SMIF_CORE1_SS_PIN((slaveIndex))))
#define SMIF_DQ0_PORT(base)             (((base) == SMIF0_CORE) ? ((void *)SMIF0_CORE_SMIF_GPIO_SMIF_PRT0) : ((void *)SMIF1_CORE_SMIF_GPIO_SMIF_PRT0))
#endif


/* CY_XIP_BASE remaps the native XIP Base address definition below
   in order to match the API of other devices. */
#ifndef CY_XIP_BASE
#define CY_XIP_BASE                         CY_XIP_PORT0_BASE
#endif

/*******************************************************************************
*                DW
*******************************************************************************/


#define CY_DW                               (0UL)
#define CY_DW_CRC                           (1UL)
#define CY_DW0_BASE                         DW0
#define CY_DW1_BASE                         DW1
#define CY_DW0_CH_NR                        CPUSS_DW0_CH_NR
#define CY_DW1_CH_NR                        CPUSS_DW1_CH_NR

#define CY_DW_CH_CTL_PRIO_Pos               ((uint32_t)(DW_CH_STRUCT_CH_CTL_PRIO_Pos))
#define CY_DW_CH_CTL_PRIO_Msk               ((uint32_t)(0x3UL << CY_DW_CH_CTL_PRIO_Pos))
#define CY_DW_CH_CTL_PREEMPTABLE_Pos        ((uint32_t)(DW_CH_STRUCT_CH_CTL_PREEMPTABLE_Pos))
#define CY_DW_CH_CTL_PREEMPTABLE_Msk        ((uint32_t)(0x1UL << CY_DW_CH_CTL_PREEMPTABLE_Pos))
#define CY_DW_STATUS_CH_IDX_Pos             ((uint32_t)(DW_STATUS_CH_IDX_Pos))
#define CY_DW_STATUS_CH_IDX_Msk             (DW_STATUS_CH_IDX_Msk)

#define DW_CTL(base)                        (((DW_Type*)(base))->CTL)
#define DW_STATUS(base)                     (((DW_Type const*)(base))->STATUS)
#define DW_DESCR_SRC(base)                  (((DW_Type*)(base))->ACT_DESCR_SRC)
#define DW_DESCR_DST(base)                  (((DW_Type*)(base))->ACT_DESCR_DST)

#define DW_CRC_CTL(base)                    (((DW_Type*)(base))->CRC_CTL)
#define DW_CRC_DATA_CTL(base)               (((DW_Type*)(base))->CRC_DATA_CTL)
#define DW_CRC_REM_CTL(base)                (((DW_Type*)(base))->CRC_REM_CTL)
#define DW_CRC_POL_CTL(base)                (((DW_Type*)(base))->CRC_POL_CTL)
#define DW_CRC_LFSR_CTL(base)               (((DW_Type*)(base))->CRC_LFSR_CTL)

#define DW_CH_OFFSET                        (uint32_t)(offsetof(DW_Type, CH_STRUCT))
#define DW_CH_SIZE                            (uint32_t)(sizeof(DW_CH_STRUCT_Type))

#define DW_CH(base, chan)                    ((DW_CH_STRUCT_Type*)((uint32_t)(base) + DW_CH_OFFSET + (chan * DW_CH_SIZE)))
#define DW_CH_CTL(base, chan)               (DW_CH((base), (chan))->CH_CTL)
#define DW_CH_STATUS(base, chan)            (DW_CH((base), (chan))->CH_STATUS)
#define DW_CH_IDX(base, chan)               (DW_CH((base), (chan))->CH_IDX)
#define DW_CH_CURR_PTR(base, chan)          (DW_CH((base), (chan))->CH_CURR_PTR)

#define DW_CH_INTR(base, chan)              (DW_CH((base), (chan))->INTR)
#define DW_CH_INTR_SET(base, chan)          (DW_CH((base), (chan))->INTR_SET)
#define DW_CH_INTR_MASK(base, chan)         (DW_CH((base), (chan))->INTR_MASK)
#define DW_CH_INTR_MASKED(base, chan)       (DW_CH((base), (chan))->INTR_MASKED)
#define DW_CH_TR_CMD(base, chan)            (DW_CH((base), (chan))->TR_CMD)

#if defined (CY_IP_MXDW)
#define DW_V2_CRC_CTL_DATA_REVERSE_Msk DW_CRC_CTL_DATA_REVERSE_Msk
#define DW_V2_CRC_CTL_REM_REVERSE_Msk DW_CRC_CTL_REM_REVERSE_Msk
#define DW_V2_CRC_DATA_CTL_DATA_XOR_Msk DW_CRC_DATA_CTL_DATA_XOR_Msk
#define DW_V2_CRC_REM_CTL_REM_XOR_Msk DW_CRC_REM_CTL_REM_XOR_Msk
#define DW_V2_CRC_POL_CTL_POLYNOMIAL_Msk DW_CRC_POL_CTL_POLYNOMIAL_Msk
#define DW_V2_CRC_LFSR_CTL_LFSR32_Msk DW_CRC_LFSR_CTL_LFSR32_Msk
#define DW_V2_CRC_CTL_DATA_REVERSE_Pos DW_CRC_CTL_DATA_REVERSE_Pos
#define DW_V2_CRC_CTL_REM_REVERSE_Pos DW_CRC_CTL_REM_REVERSE_Pos
#define DW_V2_CRC_DATA_CTL_DATA_XOR_Pos DW_CRC_DATA_CTL_DATA_XOR_Pos
#define DW_V2_CRC_REM_CTL_REM_XOR_Pos DW_CRC_REM_CTL_REM_XOR_Pos
#define DW_V2_CRC_POL_CTL_POLYNOMIAL_Pos DW_CRC_POL_CTL_POLYNOMIAL_Pos
#define DW_V2_CRC_LFSR_CTL_LFSR32_Pos DW_CRC_LFSR_CTL_LFSR32_Pos
#endif /* CY_IP_MXDW */

/* Redefine M33 DMA macros */
#define cpuss_interrupts_dw0_0_IRQn  m33syscpuss_interrupts_dw0_0_IRQn
#define cpuss_interrupts_dw0_1_IRQn  m33syscpuss_interrupts_dw0_1_IRQn
#define cpuss_interrupts_dw0_2_IRQn  m33syscpuss_interrupts_dw0_2_IRQn
#define cpuss_interrupts_dw0_3_IRQn  m33syscpuss_interrupts_dw0_3_IRQn
#define cpuss_interrupts_dw0_4_IRQn  m33syscpuss_interrupts_dw0_4_IRQn
#define cpuss_interrupts_dw0_5_IRQn  m33syscpuss_interrupts_dw0_5_IRQn
#define cpuss_interrupts_dw0_6_IRQn  m33syscpuss_interrupts_dw0_6_IRQn
#define cpuss_interrupts_dw0_7_IRQn  m33syscpuss_interrupts_dw0_7_IRQn
#define cpuss_interrupts_dw0_8_IRQn  m33syscpuss_interrupts_dw0_8_IRQn
#define cpuss_interrupts_dw0_9_IRQn  m33syscpuss_interrupts_dw0_9_IRQn
#define cpuss_interrupts_dw0_10_IRQn m33syscpuss_interrupts_dw0_10_IRQn
#define cpuss_interrupts_dw0_11_IRQn m33syscpuss_interrupts_dw0_11_IRQn
#define cpuss_interrupts_dw0_12_IRQn m33syscpuss_interrupts_dw0_12_IRQn
#define cpuss_interrupts_dw0_13_IRQn m33syscpuss_interrupts_dw0_13_IRQn
#define cpuss_interrupts_dw0_14_IRQn m33syscpuss_interrupts_dw0_14_IRQn
#define cpuss_interrupts_dw0_15_IRQn m33syscpuss_interrupts_dw0_15_IRQn
#define cpuss_interrupts_dw1_0_IRQn  m33syscpuss_interrupts_dw1_0_IRQn
#define cpuss_interrupts_dw1_1_IRQn  m33syscpuss_interrupts_dw1_1_IRQn
#define cpuss_interrupts_dw1_2_IRQn  m33syscpuss_interrupts_dw1_2_IRQn
#define cpuss_interrupts_dw1_3_IRQn  m33syscpuss_interrupts_dw1_3_IRQn
#define cpuss_interrupts_dw1_4_IRQn  m33syscpuss_interrupts_dw1_4_IRQn
#define cpuss_interrupts_dw1_5_IRQn  m33syscpuss_interrupts_dw1_5_IRQn
#define cpuss_interrupts_dw1_6_IRQn  m33syscpuss_interrupts_dw1_6_IRQn
#define cpuss_interrupts_dw1_7_IRQn  m33syscpuss_interrupts_dw1_7_IRQn
#define cpuss_interrupts_dw1_8_IRQn  m33syscpuss_interrupts_dw1_8_IRQn
#define cpuss_interrupts_dw1_9_IRQn  m33syscpuss_interrupts_dw1_9_IRQn
#define cpuss_interrupts_dw1_10_IRQn m33syscpuss_interrupts_dw1_10_IRQn
#define cpuss_interrupts_dw1_11_IRQn m33syscpuss_interrupts_dw1_11_IRQn
#define cpuss_interrupts_dw1_12_IRQn m33syscpuss_interrupts_dw1_12_IRQn
#define cpuss_interrupts_dw1_13_IRQn m33syscpuss_interrupts_dw1_13_IRQn
#define cpuss_interrupts_dw1_14_IRQn m33syscpuss_interrupts_dw1_14_IRQn
#define cpuss_interrupts_dw1_15_IRQn m33syscpuss_interrupts_dw1_15_IRQn

/*******************************************************************************
*                AXIDMAC
*******************************************************************************/
#define AXI_DMAC_Type SAXI_DMAC_Type
#define CY_AXIDMAC_CH_NR                    (AXI_DMAC_CH_NR)
#define AXIDMAC_CTL(base)                   (((AXI_DMAC_Type*)(base))->CTL)
#define AXIDMAC_STATUS(base)                (((AXI_DMAC_Type*)(base))->STATUS)
#define AXIDMAC_ACTIVE(base)                (((AXI_DMAC_Type const*)(base))->ACTIVE)
#define AXIDMAC_CH(base, chan)              (&(((AXI_DMAC_Type*)(base))->CH[(chan)]))
#define AXIDMAC_CH_CTL(base, chan)          (AXIDMAC_CH(base, chan)->CTL)
#define AXIDMAC_CH_IDX(base, chan)          (AXIDMAC_CH(base, chan)->IDX)
#define AXIDMAC_CH_CURR(base, chan)         (AXIDMAC_CH(base, chan)->CURR)
#define AXIDMAC_CH_DESCR_SRC(base, chan)    (AXIDMAC_CH(base, chan)->DESCR_SRC)
#define AXIDMAC_CH_DESCR_DST(base, chan)    (AXIDMAC_CH(base, chan)->DESCR_DST)
#define AXIDMAC_CH_INTR(base, chan)         (AXIDMAC_CH(base, chan)->INTR)
#define AXIDMAC_CH_INTR_SET(base, chan)     (AXIDMAC_CH(base, chan)->INTR_SET)
#define AXIDMAC_CH_INTR_MASK(base, chan)    (AXIDMAC_CH(base, chan)->INTR_MASK)
#define AXIDMAC_CH_INTR_MASKED(base, chan)  (AXIDMAC_CH(base, chan)->INTR_MASKED)
#define AXIDMAC_CH_TR_CMD(base, chan)       (AXIDMAC_CH(base, chan)->TR_CMD)

/* SAXI_DMAC_CH.CTL */
#define AXI_DMAC_CH_CTL_P_Pos                  SAXI_DMAC_CH_CTL_P_Pos
#define AXI_DMAC_CH_CTL_P_Msk                  SAXI_DMAC_CH_CTL_P_Msk
#define AXI_DMAC_CH_CTL_NS_Pos                 SAXI_DMAC_CH_CTL_NS_Pos
#define AXI_DMAC_CH_CTL_NS_Msk                 SAXI_DMAC_CH_CTL_NS_Msk
#define AXI_DMAC_CH_CTL_B_Pos                  SAXI_DMAC_CH_CTL_B_Pos
#define AXI_DMAC_CH_CTL_B_Msk                  SAXI_DMAC_CH_CTL_B_Msk
#define AXI_DMAC_CH_CTL_PC_Pos                 SAXI_DMAC_CH_CTL_PC_Pos
#define AXI_DMAC_CH_CTL_PC_Msk                 SAXI_DMAC_CH_CTL_PC_Msk
#define AXI_DMAC_CH_CTL_PRIO_Pos               SAXI_DMAC_CH_CTL_PRIO_Pos
#define AXI_DMAC_CH_CTL_PRIO_Msk               SAXI_DMAC_CH_CTL_PRIO_Msk
#define AXI_DMAC_CH_CTL_ENABLED_Pos            SAXI_DMAC_CH_CTL_ENABLED_Pos
#define AXI_DMAC_CH_CTL_ENABLED_Msk            SAXI_DMAC_CH_CTL_ENABLED_Msk
/* SAXI_DMAC_CH.STATUS */
#define AXI_DMAC_CH_STATUS_ENABLED_Pos         SAXI_DMAC_CH_STATUS_ENABLED_Pos
#define AXI_DMAC_CH_STATUS_ENABLED_Msk         SAXI_DMAC_CH_STATUS_ENABLED_Msk
/* SAXI_DMAC_CH.IDX */
#define AXI_DMAC_CH_IDX_X_Pos                  SAXI_DMAC_CH_IDX_X_Pos
#define AXI_DMAC_CH_IDX_X_Msk                  SAXI_DMAC_CH_IDX_X_Msk
#define AXI_DMAC_CH_IDX_Y_Pos                  SAXI_DMAC_CH_IDX_Y_Pos
#define AXI_DMAC_CH_IDX_Y_Msk                  SAXI_DMAC_CH_IDX_Y_Msk
/* SAXI_DMAC_CH.SRC */
#define AXI_DMAC_CH_SRC_ADDR_Pos               SAXI_DMAC_CH_SRC_ADDR_Pos
#define AXI_DMAC_CH_SRC_ADDR_Msk               SAXI_DMAC_CH_SRC_ADDR_Msk
/* SAXI_DMAC_CH.DST */
#define AXI_DMAC_CH_DST_ADDR_Pos               SAXI_DMAC_CH_DST_ADDR_Pos
#define AXI_DMAC_CH_DST_ADDR_Msk               SAXI_DMAC_CH_DST_ADDR_Msk
/* SAXI_DMAC_CH.M_IDX */
#define AXI_DMAC_CH_M_IDX_M_Pos                SAXI_DMAC_CH_M_IDX_M_Pos
#define AXI_DMAC_CH_M_IDX_M_Msk                SAXI_DMAC_CH_M_IDX_M_Msk
/* SAXI_DMAC_CH.CURR */
#define AXI_DMAC_CH_CURR_PTR_Pos               SAXI_DMAC_CH_CURR_PTR_Pos
#define AXI_DMAC_CH_CURR_PTR_Msk               SAXI_DMAC_CH_CURR_PTR_Msk
/* SAXI_DMAC_CH.TR_CMD */
#define AXI_DMAC_CH_TR_CMD_ACTIVATE_Pos        SAXI_DMAC_CH_TR_CMD_ACTIVATE_Pos
#define AXI_DMAC_CH_TR_CMD_ACTIVATE_Msk        SAXI_DMAC_CH_TR_CMD_ACTIVATE_Msk
/* SAXI_DMAC_CH.DESCR_STATUS */
#define AXI_DMAC_CH_DESCR_STATUS_VALID_Pos     SAXI_DMAC_CH_DESCR_STATUS_VALID_Pos
#define AXI_DMAC_CH_DESCR_STATUS_VALID_Msk     SAXI_DMAC_CH_DESCR_STATUS_VALID_Msk
/* SAXI_DMAC_CH.DESCR_CTL */
#define AXI_DMAC_CH_DESCR_CTL_WAIT_FOR_DEACT_Pos     SAXI_DMAC_CH_DESCR_CTL_WAIT_FOR_DEACT_Pos
#define AXI_DMAC_CH_DESCR_CTL_WAIT_FOR_DEACT_Msk     SAXI_DMAC_CH_DESCR_CTL_WAIT_FOR_DEACT_Msk
#define AXI_DMAC_CH_DESCR_CTL_INTR_TYPE_Pos          SAXI_DMAC_CH_DESCR_CTL_INTR_TYPE_Pos
#define AXI_DMAC_CH_DESCR_CTL_INTR_TYPE_Msk          SAXI_DMAC_CH_DESCR_CTL_INTR_TYPE_Msk
#define AXI_DMAC_CH_DESCR_CTL_TR_OUT_TYPE_Pos        SAXI_DMAC_CH_DESCR_CTL_TR_OUT_TYPE_Pos
#define AXI_DMAC_CH_DESCR_CTL_TR_OUT_TYPE_Msk        SAXI_DMAC_CH_DESCR_CTL_TR_OUT_TYPE_Msk
#define AXI_DMAC_CH_DESCR_CTL_TR_IN_TYPE_Pos         SAXI_DMAC_CH_DESCR_CTL_TR_IN_TYPE_Pos
#define AXI_DMAC_CH_DESCR_CTL_TR_IN_TYPE_Msk         SAXI_DMAC_CH_DESCR_CTL_TR_IN_TYPE_Msk
#define AXI_DMAC_CH_DESCR_CTL_DATA_PREFETCH_Pos      SAXI_DMAC_CH_DESCR_CTL_DATA_PREFETCH_Pos
#define AXI_DMAC_CH_DESCR_CTL_DATA_PREFETCH_Msk      SAXI_DMAC_CH_DESCR_CTL_DATA_PREFETCH_Msk
#define AXI_DMAC_CH_DESCR_CTL_CH_DISABLE_Pos         SAXI_DMAC_CH_DESCR_CTL_CH_DISABLE_Pos
#define AXI_DMAC_CH_DESCR_CTL_CH_DISABLE_Msk         SAXI_DMAC_CH_DESCR_CTL_CH_DISABLE_Msk
#define AXI_DMAC_CH_DESCR_CTL_DESCR_TYPE_Pos         SAXI_DMAC_CH_DESCR_CTL_DESCR_TYPE_Pos
#define AXI_DMAC_CH_DESCR_CTL_DESCR_TYPE_Msk         SAXI_DMAC_CH_DESCR_CTL_DESCR_TYPE_Msk
/* SAXI_DMAC_CH.DESCR_SRC */
#define AXI_DMAC_CH_DESCR_SRC_ADDR_Pos         SAXI_DMAC_CH_DESCR_SRC_ADDR_Pos
#define AXI_DMAC_CH_DESCR_SRC_ADDR_Msk         SAXI_DMAC_CH_DESCR_SRC_ADDR_Msk
/* SAXI_DMAC_CH.DESCR_DST */
#define AXI_DMAC_CH_DESCR_DST_ADDR_Pos         SAXI_DMAC_CH_DESCR_DST_ADDR_Pos
#define AXI_DMAC_CH_DESCR_DST_ADDR_Msk         SAXI_DMAC_CH_DESCR_DST_ADDR_Msk
/* SAXI_DMAC_CH.DESCR_M_SIZE */
#define AXI_DMAC_CH_DESCR_M_SIZE_M_COUNT_Pos   SAXI_DMAC_CH_DESCR_M_SIZE_M_COUNT_Pos
#define AXI_DMAC_CH_DESCR_M_SIZE_M_COUNT_Msk   SAXI_DMAC_CH_DESCR_M_SIZE_M_COUNT_Msk
/* SAXI_DMAC_CH.DESCR_X_SIZE */
#define AXI_DMAC_CH_DESCR_X_SIZE_X_COUNT_Pos   SAXI_DMAC_CH_DESCR_X_SIZE_X_COUNT_Pos
#define AXI_DMAC_CH_DESCR_X_SIZE_X_COUNT_Msk   SAXI_DMAC_CH_DESCR_X_SIZE_X_COUNT_Msk
/* SAXI_DMAC_CH.DESCR_X_INCR */
#define AXI_DMAC_CH_DESCR_X_INCR_SRC_X_Pos     SAXI_DMAC_CH_DESCR_X_INCR_SRC_X_Pos
#define AXI_DMAC_CH_DESCR_X_INCR_SRC_X_Msk     SAXI_DMAC_CH_DESCR_X_INCR_SRC_X_Msk
#define AXI_DMAC_CH_DESCR_X_INCR_DST_X_Pos     SAXI_DMAC_CH_DESCR_X_INCR_DST_X_Pos
#define AXI_DMAC_CH_DESCR_X_INCR_DST_X_Msk     SAXI_DMAC_CH_DESCR_X_INCR_DST_X_Msk
/* SAXI_DMAC_CH.DESCR_Y_SIZE */
#define AXI_DMAC_CH_DESCR_Y_SIZE_Y_COUNT_Pos   SAXI_DMAC_CH_DESCR_Y_SIZE_Y_COUNT_Pos
#define AXI_DMAC_CH_DESCR_Y_SIZE_Y_COUNT_Msk   SAXI_DMAC_CH_DESCR_Y_SIZE_Y_COUNT_Msk
/* SAXI_DMAC_CH.DESCR_Y_INCR */
#define AXI_DMAC_CH_DESCR_Y_INCR_SRC_Y_Pos     SAXI_DMAC_CH_DESCR_Y_INCR_SRC_Y_Pos
#define AXI_DMAC_CH_DESCR_Y_INCR_SRC_Y_Msk     SAXI_DMAC_CH_DESCR_Y_INCR_SRC_Y_Msk
#define AXI_DMAC_CH_DESCR_Y_INCR_DST_Y_Pos     SAXI_DMAC_CH_DESCR_Y_INCR_DST_Y_Pos
#define AXI_DMAC_CH_DESCR_Y_INCR_DST_Y_Msk     SAXI_DMAC_CH_DESCR_Y_INCR_DST_Y_Msk
/* SAXI_DMAC_CH.DESCR_NEXT */
#define AXI_DMAC_CH_DESCR_NEXT_PTR_Pos         SAXI_DMAC_CH_DESCR_NEXT_PTR_Pos
#define AXI_DMAC_CH_DESCR_NEXT_PTR_Msk         SAXI_DMAC_CH_DESCR_NEXT_PTR_Msk
/* SAXI_DMAC_CH.INTR */
#define AXI_DMAC_CH_INTR_COMPLETION_Pos          SAXI_DMAC_CH_INTR_COMPLETION_Pos
#define AXI_DMAC_CH_INTR_COMPLETION_Msk          SAXI_DMAC_CH_INTR_COMPLETION_Msk
#define AXI_DMAC_CH_INTR_SRC_BUS_ERROR_Pos       SAXI_DMAC_CH_INTR_SRC_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_SRC_BUS_ERROR_Msk       SAXI_DMAC_CH_INTR_SRC_BUS_ERROR_Msk
#define AXI_DMAC_CH_INTR_DST_BUS_ERROR_Pos       SAXI_DMAC_CH_INTR_DST_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_DST_BUS_ERROR_Msk       SAXI_DMAC_CH_INTR_DST_BUS_ERROR_Msk
#define AXI_DMAC_CH_INTR_INVALID_DESCR_TYPE_Pos  SAXI_DMAC_CH_INTR_INVALID_DESCR_TYPE_Pos
#define AXI_DMAC_CH_INTR_INVALID_DESCR_TYPE_Msk  SAXI_DMAC_CH_INTR_INVALID_DESCR_TYPE_Msk
#define AXI_DMAC_CH_INTR_CURR_PTR_NULL_Pos       SAXI_DMAC_CH_INTR_CURR_PTR_NULL_Pos
#define AXI_DMAC_CH_INTR_CURR_PTR_NULL_Msk       SAXI_DMAC_CH_INTR_CURR_PTR_NULL_Msk
#define AXI_DMAC_CH_INTR_ACTIVE_CH_DISABLED_Pos  SAXI_DMAC_CH_INTR_ACTIVE_CH_DISABLED_Pos
#define AXI_DMAC_CH_INTR_ACTIVE_CH_DISABLED_Msk  SAXI_DMAC_CH_INTR_ACTIVE_CH_DISABLED_Msk
#define AXI_DMAC_CH_INTR_DESCR_BUS_ERROR_Pos     SAXI_DMAC_CH_INTR_DESCR_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_DESCR_BUS_ERROR_Msk     SAXI_DMAC_CH_INTR_DESCR_BUS_ERROR_Msk
/* SAXI_DMAC_CH.INTR_SET */
#define AXI_DMAC_CH_INTR_SET_COMPLETION_Pos          SAXI_DMAC_CH_INTR_SET_COMPLETION_Pos
#define AXI_DMAC_CH_INTR_SET_COMPLETION_Msk          SAXI_DMAC_CH_INTR_SET_COMPLETION_Msk
#define AXI_DMAC_CH_INTR_SET_SRC_BUS_ERROR_Pos       SAXI_DMAC_CH_INTR_SET_SRC_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_SET_SRC_BUS_ERROR_Msk       SAXI_DMAC_CH_INTR_SET_SRC_BUS_ERROR_Msk
#define AXI_DMAC_CH_INTR_SET_DST_BUS_ERROR_Pos       SAXI_DMAC_CH_INTR_SET_DST_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_SET_DST_BUS_ERROR_Msk       SAXI_DMAC_CH_INTR_SET_DST_BUS_ERROR_Msk
#define AXI_DMAC_CH_INTR_SET_INVALID_DESCR_TYPE_Pos  SAXI_DMAC_CH_INTR_SET_INVALID_DESCR_TYPE_Pos
#define AXI_DMAC_CH_INTR_SET_INVALID_DESCR_TYPE_Msk  SAXI_DMAC_CH_INTR_SET_INVALID_DESCR_TYPE_Msk
#define AXI_DMAC_CH_INTR_SET_CURR_PTR_NULL_Pos       SAXI_DMAC_CH_INTR_SET_CURR_PTR_NULL_Pos
#define AXI_DMAC_CH_INTR_SET_CURR_PTR_NULL_Msk       SAXI_DMAC_CH_INTR_SET_CURR_PTR_NULL_Msk
#define AXI_DMAC_CH_INTR_SET_ACTIVE_CH_DISABLED_Pos  SAXI_DMAC_CH_INTR_SET_ACTIVE_CH_DISABLED_Pos
#define AXI_DMAC_CH_INTR_SET_ACTIVE_CH_DISABLED_Msk  SAXI_DMAC_CH_INTR_SET_ACTIVE_CH_DISABLED_Msk
#define AXI_DMAC_CH_INTR_SET_DESCR_BUS_ERROR_Pos     SAXI_DMAC_CH_INTR_SET_DESCR_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_SET_DESCR_BUS_ERROR_Msk     SAXI_DMAC_CH_INTR_SET_DESCR_BUS_ERROR_Msk
/* SAXI_DMAC_CH.INTR_MASK */
#define AXI_DMAC_CH_INTR_MASK_COMPLETION_Pos          SAXI_DMAC_CH_INTR_MASK_COMPLETION_Pos
#define AXI_DMAC_CH_INTR_MASK_COMPLETION_Msk          SAXI_DMAC_CH_INTR_MASK_COMPLETION_Msk
#define AXI_DMAC_CH_INTR_MASK_SRC_BUS_ERROR_Pos       SAXI_DMAC_CH_INTR_MASK_SRC_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_MASK_SRC_BUS_ERROR_Msk       SAXI_DMAC_CH_INTR_MASK_SRC_BUS_ERROR_Msk
#define AXI_DMAC_CH_INTR_MASK_DST_BUS_ERROR_Pos       SAXI_DMAC_CH_INTR_MASK_DST_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_MASK_DST_BUS_ERROR_Msk       SAXI_DMAC_CH_INTR_MASK_DST_BUS_ERROR_Msk
#define AXI_DMAC_CH_INTR_MASK_INVALID_DESCR_TYPE_Pos  SAXI_DMAC_CH_INTR_MASK_INVALID_DESCR_TYPE_Pos
#define AXI_DMAC_CH_INTR_MASK_INVALID_DESCR_TYPE_Msk  SAXI_DMAC_CH_INTR_MASK_INVALID_DESCR_TYPE_Msk
#define AXI_DMAC_CH_INTR_MASK_CURR_PTR_NULL_Pos       SAXI_DMAC_CH_INTR_MASK_CURR_PTR_NULL_Pos
#define AXI_DMAC_CH_INTR_MASK_CURR_PTR_NULL_Msk       SAXI_DMAC_CH_INTR_MASK_CURR_PTR_NULL_Msk
#define AXI_DMAC_CH_INTR_MASK_ACTIVE_CH_DISABLED_Pos  SAXI_DMAC_CH_INTR_MASK_ACTIVE_CH_DISABLED_Pos
#define AXI_DMAC_CH_INTR_MASK_ACTIVE_CH_DISABLED_Msk  SAXI_DMAC_CH_INTR_MASK_ACTIVE_CH_DISABLED_Msk
#define AXI_DMAC_CH_INTR_MASK_DESCR_BUS_ERROR_Pos     SAXI_DMAC_CH_INTR_MASK_DESCR_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_MASK_DESCR_BUS_ERROR_Msk     SAXI_DMAC_CH_INTR_MASK_DESCR_BUS_ERROR_Msk
/* SAXI_DMAC_CH.INTR_MASKED */
#define AXI_DMAC_CH_INTR_MASKED_COMPLETION_Pos          SAXI_DMAC_CH_INTR_MASKED_COMPLETION_Pos
#define AXI_DMAC_CH_INTR_MASKED_COMPLETION_Msk          SAXI_DMAC_CH_INTR_MASKED_COMPLETION_Msk
#define AXI_DMAC_CH_INTR_MASKED_SRC_BUS_ERROR_Pos       SAXI_DMAC_CH_INTR_MASKED_SRC_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_MASKED_SRC_BUS_ERROR_Msk       SAXI_DMAC_CH_INTR_MASKED_SRC_BUS_ERROR_Msk
#define AXI_DMAC_CH_INTR_MASKED_DST_BUS_ERROR_Pos       SAXI_DMAC_CH_INTR_MASKED_DST_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_MASKED_DST_BUS_ERROR_Msk       SAXI_DMAC_CH_INTR_MASKED_DST_BUS_ERROR_Msk
#define AXI_DMAC_CH_INTR_MASKED_INVALID_DESCR_TYPE_Pos  SAXI_DMAC_CH_INTR_MASKED_INVALID_DESCR_TYPE_Pos
#define AXI_DMAC_CH_INTR_MASKED_INVALID_DESCR_TYPE_Msk  SAXI_DMAC_CH_INTR_MASKED_INVALID_DESCR_TYPE_Msk
#define AXI_DMAC_CH_INTR_MASKED_CURR_PTR_NULL_Pos       SAXI_DMAC_CH_INTR_MASKED_CURR_PTR_NULL_Pos
#define AXI_DMAC_CH_INTR_MASKED_CURR_PTR_NULL_Msk       SAXI_DMAC_CH_INTR_MASKED_CURR_PTR_NULL_Msk
#define AXI_DMAC_CH_INTR_MASKED_ACTIVE_CH_DISABLED_Pos  SAXI_DMAC_CH_INTR_MASKED_ACTIVE_CH_DISABLED_Pos
#define AXI_DMAC_CH_INTR_MASKED_ACTIVE_CH_DISABLED_Msk  SAXI_DMAC_CH_INTR_MASKED_ACTIVE_CH_DISABLED_Msk
#define AXI_DMAC_CH_INTR_MASKED_DESCR_BUS_ERROR_Pos     SAXI_DMAC_CH_INTR_MASKED_DESCR_BUS_ERROR_Pos
#define AXI_DMAC_CH_INTR_MASKED_DESCR_BUS_ERROR_Msk     SAXI_DMAC_CH_INTR_MASKED_DESCR_BUS_ERROR_Msk
/* SAXI_DMAC.CTL */
#define AXI_DMAC_CTL_ENABLED_Pos               SAXI_DMAC_CTL_ENABLED_Pos
#define AXI_DMAC_CTL_ENABLED_Msk               SAXI_DMAC_CTL_ENABLED_Msk
/* SAXI_DMAC.STATUS */
#define AXI_DMAC_STATUS_CH_EN_Pos              SAXI_DMAC_STATUS_CH_EN_Pos
#define AXI_DMAC_STATUS_CH_EN_Msk              SAXI_DMAC_STATUS_CH_EN_Msk
/* SAXI_DMAC.ACTIVE */
#define AXI_DMAC_ACTIVE_ACTIVE_Pos             SAXI_DMAC_ACTIVE_ACTIVE_Pos
#define AXI_DMAC_ACTIVE_ACTIVE_Msk             SAXI_DMAC_ACTIVE_ACTIVE_Msk

/*******************************************************************************
*                RRAM
*******************************************************************************/
#define RRAM_AHB_HRESP(base)                   (((RRAMC_Type*)(base))->RRAMC->AHB_HRESP)
#define RRAM_PC_MASK(base)                     (((RRAMC_Type*)(base))->RRAMC->PC_MASK)
#define RRAM_PROTECTED_LOCKABLE_LOCK(base)     (((RRAMC_Type*)(base))->RRAMC->PROTECTED_LOCKABLE_LOCK)
#define RRAM_UDS_CTL(base)                     (((RRAMC_Type*)(base))->RRAMC->UDS_CTL)
#define RRAM_NVM_PROG(base)                    (((RRAMC_Type*)(base))->RRAM_SFR.NVM_PROG)
#define RRAM_NVM_CONF1(base)                   (((RRAMC_Type*)(base))->RRAM_SFR.NVM_CONF1)
#define RRAM_NVM_HARDEN1(base)                 (((RRAMC_Type*)(base))->RRAM_SFR.NVM_HARDEN1)
#define RRAM_NVM_ADDR(base)                    (((RRAMC_Type*)(base))->RRAM_SFR.NVM_ADDR)
#define RRAM_NVM_HARDADDR(base)                (((RRAMC_Type*)(base))->RRAM_SFR.NVM_HARDADDR)
#define RRAM_NVM_STATUS(base)                  (((RRAMC_Type*)(base))->RRAM_SFR.NVM_STATUS)
#define RRAM_NVM_VMODE(base)                   (((RRAMC_Type*)(base))->RRAM_SFR.NVM_VMODE)
#define RRAM_NVM_ACC(base)                     (((RRAMC_Type*)(base))->RRAM_SFR.NVM_ACC)

/*******************************************************************************
*                IOSS
*******************************************************************************/

#define CY_GPIO_BASE                       ((uint32_t)GPIO_BASE)

#define GPIO_SEC_INTR_CAUSE0               ((GPIO)->SEC_INTR_CAUSE0)
#define GPIO_SEC_INTR_CAUSE1               ((GPIO)->SEC_INTR_CAUSE1)
#define GPIO_SEC_INTR_CAUSE2               ((GPIO)->SEC_INTR_CAUSE2)
#define GPIO_SEC_INTR_CAUSE3               ((GPIO)->SEC_INTR_CAUSE3)
#define GPIO_INTR_CAUSE0                   ((GPIO)->INTR_CAUSE0)
#define GPIO_INTR_CAUSE1                   ((GPIO)->INTR_CAUSE1)
#define GPIO_INTR_CAUSE2                   ((GPIO)->INTR_CAUSE2)
#define GPIO_INTR_CAUSE3                   ((GPIO)->INTR_CAUSE3)
#define GPIO_VDD_MODE_SEL                  ((GPIO)->VDD_MODE_SEL)

#define GPIO_PRT_OUT(base)                 (((GPIO_PRT_Type*)(base))->OUT)
#define GPIO_PRT_OUT_CLR(base)             (((GPIO_PRT_Type*)(base))->OUT_CLR)
#define GPIO_PRT_OUT_SET(base)             (((GPIO_PRT_Type*)(base))->OUT_SET)
#define GPIO_PRT_OUT_INV(base)             (((GPIO_PRT_Type*)(base))->OUT_INV)
#define GPIO_PRT_IN(base)                  (((GPIO_PRT_Type*)(base))->IN)
#define GPIO_PRT_INTR(base)                (((GPIO_PRT_Type*)(base))->INTR)
#define GPIO_PRT_INTR_MASK(base)           (((GPIO_PRT_Type*)(base))->INTR_MASK)
#define GPIO_PRT_INTR_MASKED(base)         (((GPIO_PRT_Type*)(base))->INTR_MASKED)
#define GPIO_PRT_INTR_SET(base)            (((GPIO_PRT_Type*)(base))->INTR_SET)
#define GPIO_PRT_INTR_CFG(base)            (((GPIO_PRT_Type*)(base))->INTR_CFG)
#define GPIO_PRT_CFG(base)                 (((GPIO_PRT_Type*)(base))->CFG)
#define GPIO_PRT_CFG_IN(base)              (((GPIO_PRT_Type*)(base))->CFG_IN)
#define GPIO_PRT_CFG_OUT(base)             (((GPIO_PRT_Type*)(base))->CFG_OUT)
#define GPIO_PRT_CFG_SIO(base)             (((GPIO_PRT_Type*)(base))->CFG_SIO)
#define GPIO_PRT_CFG_IN_AUTOLVL(base)      (((GPIO_PRT_Type*)(base))->CFG_IN_AUTOLVL)
#define GPIO_PRT_SLEW_EXT(base)            (((GPIO_PRT_Type*)(base))->CFG_SLEW_EXT)
#define GPIO_PRT_DRIVE_EXT0(base)          (((GPIO_PRT_Type*)(base))->CFG_DRIVE_EXT0)
#define GPIO_PRT_DRIVE_EXT1(base)          (((GPIO_PRT_Type*)(base))->CFG_DRIVE_EXT1)
#define GPIO_PRT_CFG_RES(base)             (((GPIO_PRT_Type*)(base))->CFG_RES)
#define GPIO_PRT_CFG_OUT3(base)            (((GPIO_PRT_Type*)(base))->CFG_OUT3)

#define CY_HSIOM_BASE                      ((uint32_t)HSIOM_BASE)

#define HSIOM_PRT_PORT_SEL0(base)          (((HSIOM_PRT_Type *)(base))->PORT_SEL0)
#define HSIOM_PRT_PORT_SEL1(base)          (((HSIOM_PRT_Type *)(base))->PORT_SEL1)

#define CY_HSIOM_SECURE_BASE               ((uint32_t)&HSIOM->SECURE_PRT[0])

#define HSIOM_SEC_PRT_NONSEC_MASK(base)    (((HSIOM_SECURE_PRT_Type *)(base))->NONSECURE_MASK)


#define HSIOM_AMUX_SPLIT_CTL(switchCtrl)    (((HSIOM_Type *)HSIOM_BASE)->AMUX_SPLIT_CTL[switchCtrl])

/*******************************************************************************
*                SCB
*******************************************************************************/
#define SCB_CTRL(base)                      (((CySCB_Type*) (base))->CTRL)
#define SCB_SPI_CTRL(base)                  (((CySCB_Type*) (base))->SPI_CTRL)
#define SCB_SPI_STATUS(base)                (((CySCB_Type*) (base))->SPI_STATUS)
#define SCB_SPI_TX_CTRL(base)              (((CySCB_Type*) (base))->SPI_TX_CTRL)
#define SCB_SPI_RX_CTRL(base)              (((CySCB_Type*) (base))->SPI_RX_CTRL)
#define SCB_UART_CTRL(base)                 (((CySCB_Type*) (base))->UART_CTRL)
#define SCB_UART_TX_CTRL(base)              (((CySCB_Type*) (base))->UART_TX_CTRL)
#define SCB_UART_RX_CTRL(base)              (((CySCB_Type*) (base))->UART_RX_CTRL)
#define SCB_UART_FLOW_CTRL(base)            (((CySCB_Type*) (base))->UART_FLOW_CTRL)
#define SCB_UART_RX_STATUS(base)            (((CySCB_Type*) (base))->UART_RX_STATUS)
#define SCB_I2C_CTRL(base)                  (((CySCB_Type*) (base))->I2C_CTRL)
#define SCB_I2C_STATUS(base)                (((CySCB_Type*) (base))->I2C_STATUS)
#define SCB_I2C_M_CMD(base)                 (((CySCB_Type*) (base))->I2C_M_CMD)
#define SCB_I2C_S_CMD(base)                 (((CySCB_Type*) (base))->I2C_S_CMD)
#define SCB_I2C_CFG(base)                   (((CySCB_Type*) (base))->I2C_CFG)
#define SCB_I2C_STRETCH_CTRL(base)          (((CySCB_Type*) (base))->I2C_STRETCH_CTRL)
#define SCB_I2C_STRETCH_STATUS(base)        (((CySCB_Type*) (base))->I2C_STRETCH_STATUS)
#define SCB_TX_CTRL(base)                   (((CySCB_Type*) (base))->TX_CTRL)
#define SCB_TX_FIFO_CTRL(base)              (((CySCB_Type*) (base))->TX_FIFO_CTRL)
#define SCB_TX_FIFO_STATUS(base)            (((CySCB_Type*) (base))->TX_FIFO_STATUS)
#define SCB_TX_FIFO_WR(base)                (((CySCB_Type*) (base))->TX_FIFO_WR)
#define SCB_RX_CTRL(base)                   (((CySCB_Type*) (base))->RX_CTRL)
#define SCB_RX_FIFO_CTRL(base)              (((CySCB_Type*) (base))->RX_FIFO_CTRL)
#define SCB_RX_FIFO_STATUS(base)            (((CySCB_Type*) (base))->RX_FIFO_STATUS)
#define SCB_RX_MATCH(base)                  (((CySCB_Type*) (base))->RX_MATCH)
#define SCB_RX_FIFO_RD(base)                (((CySCB_Type*) (base))->RX_FIFO_RD)
#define SCB_INTR_CAUSE(base)                (((CySCB_Type*) (base))->INTR_CAUSE)
#define SCB_INTR_I2C_EC(base)               (((CySCB_Type*) (base))->INTR_I2C_EC)
#define SCB_INTR_I2C_EC_MASK(base)          (((CySCB_Type*) (base))->INTR_I2C_EC_MASK)
#define SCB_INTR_I2C_EC_MASKED(base)        (((CySCB_Type*) (base))->INTR_I2C_EC_MASKED)
#define SCB_INTR_SPI_EC(base)               (((CySCB_Type*) (base))->INTR_SPI_EC)
#define SCB_INTR_SPI_EC_MASK(base)          (((CySCB_Type*) (base))->INTR_SPI_EC_MASK)
#define SCB_INTR_SPI_EC_MASKED(base)        (((CySCB_Type*) (base))->INTR_SPI_EC_MASKED)
#define SCB_INTR_M(base)                    (((CySCB_Type*) (base))->INTR_M)
#define SCB_INTR_M_SET(base)                (((CySCB_Type*) (base))->INTR_M_SET)
#define SCB_INTR_M_MASK(base)               (((CySCB_Type*) (base))->INTR_M_MASK)
#define SCB_INTR_M_MASKED(base)             (((CySCB_Type*) (base))->INTR_M_MASKED)
#define SCB_INTR_S(base)                    (((CySCB_Type*) (base))->INTR_S)
#define SCB_INTR_S_SET(base)                (((CySCB_Type*) (base))->INTR_S_SET)
#define SCB_INTR_S_MASK(base)               (((CySCB_Type*) (base))->INTR_S_MASK)
#define SCB_INTR_S_MASKED(base)             (((CySCB_Type*) (base))->INTR_S_MASKED)
#define SCB_INTR_TX(base)                   (((CySCB_Type*) (base))->INTR_TX)
#define SCB_INTR_TX_SET(base)               (((CySCB_Type*) (base))->INTR_TX_SET)
#define SCB_INTR_TX_MASK(base)              (((CySCB_Type*) (base))->INTR_TX_MASK)
#define SCB_INTR_TX_MASKED(base)            (((CySCB_Type*) (base))->INTR_TX_MASKED)
#define SCB_INTR_RX(base)                   (((CySCB_Type*) (base))->INTR_RX)
#define SCB_INTR_RX_SET(base)               (((CySCB_Type*) (base))->INTR_RX_SET)
#define SCB_INTR_RX_MASK(base)              (((CySCB_Type*) (base))->INTR_RX_MASK)
#define SCB_INTR_RX_MASKED(base)            (((CySCB_Type*) (base))->INTR_RX_MASKED)

#define SCB_SPI_CTRL_LATE_MISO_SAMPLE_Pos SCB_SPI_CTRL_LATE_SAMPLE_Pos
#define SCB_SPI_CTRL_LATE_MISO_SAMPLE_Msk SCB_SPI_CTRL_LATE_SAMPLE_Msk

/*******************************************************************************
*                I3C
*******************************************************************************/


#define I3C_CORE_DEVICE_CTRL(base)                         (((I3C_CORE_Type*) (base))->DEVICE_CTRL)
#define I3C_CORE_DEVICE_ADDR(base)                         (((I3C_CORE_Type*) (base))->DEVICE_ADDR)
#define I3C_CORE_HW_CAPABILITY(base)                     (((I3C_CORE_Type*) (base))->HW_CAPABILITY)
#define I3C_CORE_COMMAND_QUEUE_PORT(base)                 (((I3C_CORE_Type*) (base))->COMMAND_QUEUE_PORT)
#define I3C_CORE_RESPONSE_QUEUE_PORT(base)                 (((I3C_CORE_Type*) (base))->RESPONSE_QUEUE_PORT)
#define I3C_CORE_RX_DATA_PORT(base)                     (((I3C_CORE_Type*) (base))->TX_RX_DATA_PORT)
#define I3C_CORE_IBI_QUEUE_DATA(base)                   (((I3C_CORE_Type*) (base))->IBI_QUEUE_DATA)
#define I3C_CORE_QUEUE_THLD_CTRL(base)                     (((I3C_CORE_Type*) (base))->QUEUE_THLD_CTRL)
#define I3C_CORE_DATA_BUFFER_THLD_CTRL(base)            (((I3C_CORE_Type*) (base))->DATA_BUFFER_THLD_CTRL)
#define I3C_CORE_IBI_QUEUE_CTRL(base)                    (((I3C_CORE_Type*) (base))->IBI_QUEUE_CTRL)
#define I3C_CORE_IBI_CR_REQ_REJECT(base)                 (((I3C_CORE_Type*) (base))->IBI_CR_REQ_REJECT)
#define I3C_CORE_IBI_TIR_REQ_REJECT(base)               (((I3C_CORE_Type*) (base))->IBI_TIR_REQ_REJECT)
#define I3C_CORE_RESET_CTRL(base)                       (((I3C_CORE_Type*) (base))->RESET_CTRL)
#define I3C_CORE_TGT_EVENT_STATUS(base)                 (((I3C_CORE_Type*) (base))->TGT_EVENT_STATUS)
#define I3C_CORE_INTR_STATUS(base)                      (((I3C_CORE_Type*) (base))->INTR_STATUS)
#define I3C_CORE_INTR_STATUS_EN(base)                   (((I3C_CORE_Type*) (base))->INTR_STATUS_EN)
#define I3C_CORE_INTR_SIGNAL_EN(base)                   (((I3C_CORE_Type*) (base))->INTR_SIGNAL_EN)
#define I3C_CORE_INTR_FORCE(base)                       (((I3C_CORE_Type*) (base))->INTR_FORCE)
#define I3C_CORE_QUEUE_STATUS_LEVEL(base)               (((I3C_CORE_Type*) (base))->QUEUE_STATUS_LEVEL)
#define I3C_CORE_DATA_BUFFER_STATUS_LEVEL(base)         (((I3C_CORE_Type*) (base))->DATA_BUFFER_STATUS_LEVEL)
#define I3C_CORE_PRESENT_STATE(base)                     (((I3C_CORE_Type*) (base))->PRESENT_STATE)
#define I3C_CORE_CCC_DEVICE_STATUS(base)                (((I3C_CORE_Type*) (base))->CCC_DEVICE_STATUS)
#define I3C_CORE_DEVICE_ADDR_TABLE_POINTER(base)        (((I3C_CORE_Type*) (base))->DEVICE_ADDR_TABLE_POINTER)
#define I3C_CORE_DEV_CHAR_TABLE_POINTER(base)           (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE_POINTER)
#define I3C_CORE_VENDOR_SPECIFIC_REG_POINTER(base)      (((I3C_CORE_Type*) (base))->VENDOR_SPECIFIC_REG_POINTER)
#define I3C_CORE_TGT_MIPI_ID_VALUE(base)                (((I3C_CORE_Type*) (base))->TGT_MIPI_ID_VALUE)
#define I3C_CORE_TGT_PID_VALUE(base)                    (((I3C_CORE_Type*) (base))->TGT_PID_VALUE)
#define I3C_CORE_TGT_CHAR_CTRL(base)                    (((I3C_CORE_Type*) (base))->TGT_CHAR_CTRL)
#define I3C_CORE_TGT_MAX_LEN(base)                      (((I3C_CORE_Type*) (base))->TGT_MAX_LEN)
#define I3C_CORE_MAX_READ_TURNAROUND(base)              (((I3C_CORE_Type*) (base))->MAX_READ_TURNAROUND)
#define I3C_CORE_MAX_DATA_SPEED(base)                   (((I3C_CORE_Type*) (base))->MAX_DATA_SPEED)
#define I3C_CORE_TGT_INTR_REQ(base)                      (((I3C_CORE_Type*) (base))->TGT_INTR_REQ)
#define I3C_CORE_DEVICE_CTRL_EXTENDED(base)             (((I3C_CORE_Type*) (base))->DEVICE_CTRL_EXTENDED)
#define I3C_CORE_SCL_I3C_OD_TIMING(base)                (((I3C_CORE_Type*) (base))->SCL_I3C_OD_TIMING)
#define I3C_CORE_SCL_I3C_PP_TIMING(base)                (((I3C_CORE_Type*) (base))->SCL_I3C_PP_TIMING)
#define I3C_CORE_SCL_I2C_FM_TIMING(base)                (((I3C_CORE_Type*) (base))->SCL_I2C_FM_TIMING)
#define I3C_CORE_SCL_I2C_FMP_TIMING(base)               (((I3C_CORE_Type*) (base))->SCL_I2C_FMP_TIMING)
#define I3C_CORE_SCL_EXT_LCNT_TIMING(base)              (((I3C_CORE_Type*) (base))->SCL_EXT_LCNT_TIMING)
#define I3C_CORE_SCL_EXT_TERMN_LCNT_TIMING(base)        (((I3C_CORE_Type*) (base))->SCL_EXT_TERMN_LCNT_TIMING)
#define I3C_CORE_SDA_HOLD_SWITCH_DLY_TIMING(base)       (((I3C_CORE_Type*) (base))->SDA_HOLD_SWITCH_DLY_TIMING)
#define I3C_CORE_BUS_FREE_AVAIL_TIMING(base)            (((I3C_CORE_Type*) (base))->BUS_FREE_AVAIL_TIMING)
#define I3C_CORE_BUS_IDLE_TIMING(base)                   (((I3C_CORE_Type*) (base))->BUS_IDLE_TIMING)
#define I3C_CORE_I3C_VER_ID(base)                       (((I3C_CORE_Type*) (base))->I3C_VER_ID)
#define I3C_CORE_I3C_VER_TYPE(base)                     (((I3C_CORE_Type*) (base))->I3C_VER_TYPE)
#define I3C_CORE_QUEUE_SIZE_CAPABILITY(base)            (((I3C_CORE_Type*) (base))->QUEUE_SIZE_CAPABILITY)
#define I3C_CORE_DEV_CHAR_TABLE1_LOC1(base)                (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE1_LOC1)
#define I3C_CORE_DEV_CHAR_TABLE1_LOC2(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE1_LOC2)
#define I3C_CORE_DEV_CHAR_TABLE1_LOC3(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE1_LOC3)
#define I3C_CORE_DEV_CHAR_TABLE1_LOC4(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE1_LOC4)
#define I3C_CORE_DEV_CHAR_TABLE2_LOC1(base)                (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE2_LOC1)
#define I3C_CORE_DEV_CHAR_TABLE2_LOC2(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE2_LOC2)
#define I3C_CORE_DEV_CHAR_TABLE2_LOC3(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE2_LOC3)
#define I3C_CORE_DEV_CHAR_TABLE2_LOC4(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE2_LOC4)
#define I3C_CORE_DEV_CHAR_TABLE3_LOC1(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE3_LOC1)
#define I3C_CORE_DEV_CHAR_TABLE3_LOC2(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE3_LOC2)
#define I3C_CORE_DEV_CHAR_TABLE3_LOC3(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE3_LOC3)
#define I3C_CORE_DEV_CHAR_TABLE3_LOC4(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE3_LOC4)
#define I3C_CORE_DEV_CHAR_TABLE4_LOC1(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE4_LOC1)
#define I3C_CORE_DEV_CHAR_TABLE4_LOC2(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE4_LOC2)
#define I3C_CORE_DEV_CHAR_TABLE4_LOC3(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE4_LOC3)
#define I3C_CORE_DEV_CHAR_TABLE4_LOC4(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE4_LOC4)
#define I3C_CORE_DEV_CHAR_TABLE5_LOC1(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE5_LOC1)
#define I3C_CORE_DEV_CHAR_TABLE5_LOC2(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE5_LOC2)
#define I3C_CORE_DEV_CHAR_TABLE5_LOC3(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE5_LOC3)
#define I3C_CORE_DEV_CHAR_TABLE5_LOC4(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE5_LOC4)
#define I3C_CORE_DEV_CHAR_TABLE6_LOC1(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE6_LOC1)
#define I3C_CORE_DEV_CHAR_TABLE6_LOC2(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE6_LOC2)
#define I3C_CORE_DEV_CHAR_TABLE6_LOC3(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE6_LOC3)
#define I3C_CORE_DEV_CHAR_TABLE6_LOC4(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE6_LOC4)
#define I3C_CORE_DEV_CHAR_TABLE7_LOC1(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE7_LOC1)
#define I3C_CORE_DEV_CHAR_TABLE7_LOC2(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE7_LOC2)
#define I3C_CORE_DEV_CHAR_TABLE7_LOC3(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE7_LOC3)
#define I3C_CORE_DEV_CHAR_TABLE7_LOC4(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE7_LOC4)
#define I3C_CORE_DEV_CHAR_TABLE8_LOC1(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE8_LOC1)
#define I3C_CORE_DEV_CHAR_TABLE8_LOC2(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE8_LOC2)
#define I3C_CORE_DEV_CHAR_TABLE8_LOC3(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE8_LOC3)
#define I3C_CORE_DEV_CHAR_TABLE8_LOC4(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE8_LOC4)
#define I3C_CORE_DEV_CHAR_TABLE9_LOC1(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE9_LOC1)
#define I3C_CORE_DEV_CHAR_TABLE9_LOC2(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE9_LOC2)
#define I3C_CORE_DEV_CHAR_TABLE9_LOC3(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE9_LOC3)
#define I3C_CORE_DEV_CHAR_TABLE9_LOC4(base)             (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE9_LOC4)
#define I3C_CORE_DEV_CHAR_TABLE10_LOC1(base)            (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE10_LOC1)
#define I3C_CORE_DEV_CHAR_TABLE10_LOC2(base)            (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE10_LOC2)
#define I3C_CORE_DEV_CHAR_TABLE10_LOC3(base)            (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE10_LOC3)
#define I3C_CORE_DEV_CHAR_TABLE10_LOC4(base)            (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE10_LOC4)
#define I3C_CORE_DEV_CHAR_TABLE11_LOC1(base)            (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE11_LOC1)
#define I3C_CORE_DEV_CHAR_TABLE11_LOC2(base)            (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE11_LOC2)
#define I3C_CORE_DEV_CHAR_TABLE11_LOC3(base)            (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE11_LOC3)
#define I3C_CORE_DEV_CHAR_TABLE11_LOC4(base)            (((I3C_CORE_Type*) (base))->DEV_CHAR_TABLE11_LOC4)
#define I3C_CORE_DEV_ADDR_TABLE_LOC1(base)                (((I3C_CORE_Type*) (base))->DEV_ADDR_TABLE_LOC1)
#define I3C_CORE_DEV_ADDR_TABLE_LOC2(base)                (((I3C_CORE_Type*) (base))->DEV_ADDR_TABLE_LOC2)
#define I3C_CORE_DEV_ADDR_TABLE_LOC3(base)                (((I3C_CORE_Type*) (base))->DEV_ADDR_TABLE_LOC3)
#define I3C_CORE_DEV_ADDR_TABLE_LOC4(base)                (((I3C_CORE_Type*) (base))->DEV_ADDR_TABLE_LOC4)
#define I3C_CORE_DEV_ADDR_TABLE_LOC5(base)                (((I3C_CORE_Type*) (base))->DEV_ADDR_TABLE_LOC5)
#define I3C_CORE_DEV_ADDR_TABLE_LOC6(base)                (((I3C_CORE_Type*) (base))->DEV_ADDR_TABLE_LOC6)
#define I3C_CORE_DEV_ADDR_TABLE_LOC7(base)                (((I3C_CORE_Type*) (base))->DEV_ADDR_TABLE_LOC7)
#define I3C_CORE_DEV_ADDR_TABLE_LOC8(base)                (((I3C_CORE_Type*) (base))->DEV_ADDR_TABLE_LOC8)
#define I3C_CORE_DEV_ADDR_TABLE_LOC9(base)                (((I3C_CORE_Type*) (base))->DEV_ADDR_TABLE_LOC9)
#define I3C_CORE_DEV_ADDR_TABLE_LOC10(base)                (((I3C_CORE_Type*) (base))->DEV_ADDR_TABLE_LOC10)
#define I3C_CORE_DEV_ADDR_TABLE_LOC11(base)                (((I3C_CORE_Type*) (base))->DEV_ADDR_TABLE_LOC11)

/* I3C_CORE.IBI_QUEUE_STATUS */
#define I3C_CORE_IBI_QUEUE_STATUS(base)              I3C_CORE_IBI_QUEUE_DATA(base)
#define I3C_CORE_IBI_QUEUE_STATUS_DATA_LENGTH_Pos    0UL
#define I3C_CORE_IBI_QUEUE_STATUS_DATA_LENGTH_Msk    0xFFUL
#define I3C_CORE_IBI_QUEUE_STATUS_IBI_ID_Pos         8UL
#define I3C_CORE_IBI_QUEUE_STATUS_IBI_ID_Msk         0xFF00UL
#define I3C_CORE_IBI_QUEUE_STATUS_IBI_RESP_STS_Pos   28UL
#define I3C_CORE_IBI_QUEUE_STATUS_IBI_RESP_STS_Msk   0xF0000000UL

/*******************************************************************************
*                EFUSE
******************************************************************************/

#define EFUSE_CTL(base)                              (((EFUSE_Type *) (base))->CTL)
#define EFUSE_TEST(base)                             (((EFUSE_Type *) (base))->TEST)
#define EFUSE_CMD(base)                              (((EFUSE_Type *) (base))->CMD)
#define EFUSE_CONFIG(base)                           (((EFUSE_Type *) (base))->CONFIG)
#define EFUSE_SEQ_DEFAULT(base)                      (((EFUSE_Type *) (base))->SEQ_DEFAULT)
#define EFUSE_SEQ_READ_CTL_0(base)                   (((EFUSE_Type *) (base))->SEQ_READ_CTL_0)
#define EFUSE_SEQ_READ_CTL_1(base)                   (((EFUSE_Type *) (base))->SEQ_READ_CTL_1)
#define EFUSE_SEQ_READ_CTL_2(base)                   (((EFUSE_Type *) (base))->SEQ_READ_CTL_2)
#define EFUSE_SEQ_READ_CTL_3(base)                   (((EFUSE_Type *) (base))->SEQ_READ_CTL_3)
#define EFUSE_SEQ_READ_CTL_4(base)                   (((EFUSE_Type *) (base))->SEQ_READ_CTL_4)
#define EFUSE_SEQ_READ_CTL_5(base)                   (((EFUSE_Type *) (base))->SEQ_READ_CTL_5)
#define EFUSE_SEQ_READ_CTL_6(base)                   (((EFUSE_Type *) (base))->SEQ_READ_CTL_6)
#define EFUSE_SEQ_READ_CTL_7(base)                   (((EFUSE_Type *) (base))->SEQ_READ_CTL_7)
#define EFUSE_SEQ_PROGRAM_CTL_0(base)                (((EFUSE_Type *) (base))->SEQ_PROGRAM_CTL_0)
#define EFUSE_SEQ_PROGRAM_CTL_1(base)                (((EFUSE_Type *) (base))->SEQ_PROGRAM_CTL_1)
#define EFUSE_SEQ_PROGRAM_CTL_2(base)                (((EFUSE_Type *) (base))->SEQ_PROGRAM_CTL_2)
#define EFUSE_SEQ_PROGRAM_CTL_3(base)                (((EFUSE_Type *) (base))->SEQ_PROGRAM_CTL_3)
#define EFUSE_SEQ_PROGRAM_CTL_4(base)                (((EFUSE_Type *) (base))->SEQ_PROGRAM_CTL_4)
#define EFUSE_SEQ_PROGRAM_CTL_5(base)                (((EFUSE_Type *) (base))->SEQ_PROGRAM_CTL_5)
#define EFUSE_SEQ_PROGRAM_CTL_6(base)                (((EFUSE_Type *) (base))->SEQ_PROGRAM_CTL_6)
#define EFUSE_SEQ_PROGRAM_CTL_7(base)                (((EFUSE_Type *) (base))->SEQ_PROGRAM_CTL_7)
#define EFUSE_BOOTROW(base)                          (((EFUSE_Type *) (base))->BOOTROW)

/*******************************************************************************
*                FAULT
*******************************************************************************/

#define FAULT_CTL(base)                         (((FAULT_STRUCT_Type *)(base))->CTL)
#define FAULT_STATUS(base)                      (((FAULT_STRUCT_Type *)(base))->STATUS)
#define FAULT_DATA(base)                        (((FAULT_STRUCT_Type *)(base))->DATA)
#define FAULT_PENDING0(base)                    (((FAULT_STRUCT_Type *)(base))->PENDING0)
#define FAULT_PENDING1(base)                    (((FAULT_STRUCT_Type *)(base))->PENDING1)
#define FAULT_PENDING2(base)                    (((FAULT_STRUCT_Type *)(base))->PENDING2)
#define FAULT_MASK0(base)                       (((FAULT_STRUCT_Type *)(base))->MASK0)
#define FAULT_MASK1(base)                       (((FAULT_STRUCT_Type *)(base))->MASK1)
#define FAULT_MASK2(base)                       (((FAULT_STRUCT_Type *)(base))->MASK2)
#define FAULT_INTR(base)                        (((FAULT_STRUCT_Type *)(base))->INTR)
#define FAULT_INTR_SET(base)                    (((FAULT_STRUCT_Type *)(base))->INTR_SET)
#define FAULT_INTR_MASK(base)                   (((FAULT_STRUCT_Type *)(base))->INTR_MASK)
#define FAULT_INTR_MASKED(base)                 (((FAULT_STRUCT_Type *)(base))->INTR_MASKED)

/*******************************************************************************
*                PROFILE
*******************************************************************************/


#define CY_EP_MONITOR_COUNT                 ((uint32_t)(cy_device->epMonitorNr))
#define CY_EP_CNT_NR                        (8UL)
#define PROFILE_CTL                         (((PROFILE_Type*) PROFILE_BASE)->CTL)
#define PROFILE_STATUS                      (((PROFILE_Type*) PROFILE_BASE)->STATUS)
#define PROFILE_CMD                         (((PROFILE_Type*) PROFILE_BASE)->CMD)
#define PROFILE_INTR                        (((PROFILE_Type*) PROFILE_BASE)->INTR)
#define PROFILE_INTR_MASK                   (((PROFILE_Type*) PROFILE_BASE)->INTR_MASK)
#define PROFILE_INTR_MASKED                 (((PROFILE_Type*) PROFILE_BASE)->INTR_MASKED)
#define PROFILE_CNT_STRUCT                  (((PROFILE_Type*) PROFILE_BASE)->CNT_STRUCT)

/*******************************************************************************
*                SRSS
*******************************************************************************/

#define CY_SRSS_NUM_CLKPATH                 SRSS_NUM_CLKPATH
#define CY_SRSS_NUM_PLL                     SRSS_NUM_TOTAL_DPLL
#define CY_SRSS_NUM_HFROOT                  SRSS_NUM_HFROOT
#define CY_SRSS_ECO_PRESENT                 SRSS_ECO_PRESENT
#if defined(SRSS_FLL_PRESENT)
#define CY_SRSS_FLL_PRESENT                 SRSS_FLL_PRESENT
#endif /* defined (SRSS_FLL_PRESENT) */
#define CY_SRSS_PLL_PRESENT                 SRSS_NUM_TOTAL_DPLL
#if defined (SRSS_ALTHF_PRESENT)
#define CY_SRSS_ALTHF_PRESENT               SRSS_ALTHF_PRESENT
#endif /* defined SRSS_ALTHF_PRESENT */
#define CY_SRSS_PILO_PRESENT                SRSS_PILO_PRESENT
#define CY_SRSS_PLL400M_PRESENT             0
#define CY_SRSS_PLL200M_PRESENT             0
#define CY_SRSS_NUM_PLL400M                 0
#define CY_SRSS_DPLL_LP_PRESENT             SRSS_NUM_DPLL_LP
#define CY_SRSS_DPLL_HP_PRESENT             SRSS_NUM_DPLL_HP

#define CY_SRSS_IHO_PRESENT                 1
#define CY_SRSS_IMO_PRESENT                 SRSS_IMO_PRESENT
#define CY_SRSS_ILO_PRESENT                 SRSS_ILO_PRESENT

#define CY_SRSS_MFO_PRESENT                 0

#define SRSS_DPLL_LP_0_PATH_NUM  (0UL)
#define SRSS_DPLL_LP_1_PATH_NUM  (1UL)
#define SRSS_DPLL_HP_0_PATH_NUM  (2UL)

#define SRSS_DPLL_LP_FRAC_BIT_COUNT (24ULL)
#define SRSS_DPLL_HP_FRAC_BIT_COUNT (21ULL)

#define SRSS_DPLL_LP_INIT_DELAY_USEC (20U)
/** HF PATH # used for PERI PCLK */
#define CY_SYSCLK_CLK_PERI_HF_PATH_NUM     10U

/** HF PATH # used for Core */
#ifdef CORE_NAME_CM33_0
#define CY_SYSCLK_CLK_CORE_HF_PATH_NUM     0U
#else
#define CY_SYSCLK_CLK_CORE_HF_PATH_NUM     1U
#endif

/* HF PATH # Max Allowed Frequencies */
#define CY_SYSCLK_MAX_FREQ_HF0             200000000U
#define CY_SYSCLK_MAX_FREQ_HF1_3_4         400000000U
#define CY_SYSCLK_MAX_FREQ_HF2             300000000U
#define CY_SYSCLK_MAX_FREQ_HF5_6           208000000U
#define CY_SYSCLK_MAX_FREQ_HF7_9_10        100000000U
#define CY_SYSCLK_MAX_FREQ_HF8              50000000U
#define CY_SYSCLK_MAX_FREQ_HF12             64000000U
#define CY_SYSCLK_MAX_FREQ_HF13            125000000U

#define CY_SYSCLK_HF_MAX_FREQ(hfNum)     (((hfNum) == 0U) ? (CY_SYSCLK_MAX_FREQ_HF0) : \
                                          (((hfNum) == 1U || (hfNum) == 3U || (hfNum) == 4U) ? (CY_SYSCLK_MAX_FREQ_HF1_3_4) : \
                                          (((hfNum) == 2U) ? (CY_SYSCLK_MAX_FREQ_HF2) : \
                                          (((hfNum) == 5U || (hfNum) == 6U) ? (CY_SYSCLK_MAX_FREQ_HF5_6) : \
                                          (((hfNum) == 7U || (hfNum) == 9U || (hfNum) == 10U) ? (CY_SYSCLK_MAX_FREQ_HF7_9_10) : \
                                          (((hfNum) == 8U) ? (CY_SYSCLK_MAX_FREQ_HF8) : \
                                          (((hfNum) == 12U) ? (CY_SYSCLK_MAX_FREQ_HF12) : \
                                          (((hfNum) == 13U) ? (CY_SYSCLK_MAX_FREQ_HF13) : \
                                          (200000000U)))))))))


/* CLK_ECO.CONFIG */
#define SRSS_CLK_ECO_CONFIG_ECO_DIV_DISABLE_Pos      CLK_ECO_CONFIG_ECO_DIV_DISABLE_Pos
#define SRSS_CLK_ECO_CONFIG_ECO_DIV_DISABLE_Msk      CLK_ECO_CONFIG_ECO_DIV_DISABLE_Msk
#define SRSS_CLK_ECO_CONFIG_ECO_DIV_ENABLE_Pos       CLK_ECO_CONFIG_ECO_DIV_ENABLE_Pos
#define SRSS_CLK_ECO_CONFIG_ECO_DIV_ENABLE_Msk       CLK_ECO_CONFIG_ECO_DIV_ENABLE_Msk
#define SRSS_CLK_ECO_CONFIG_ECO_EN_Msk               CLK_ECO_CONFIG_ECO_EN_Msk
/* CLK_ECO.CONFIG2 */
#define SRSS_CLK_ECO_CONFIG2_ECO_TRIM_CL_Msk          CLK_ECO_CONFIG2_ECO_TRIM_CL_Msk
#define SRSS_CLK_ECO_CONFIG2_ECO_TRIM_CL_Pos          CLK_ECO_CONFIG2_ECO_TRIM_CL_Pos
#define SRSS_CLK_ECO_CONFIG2_ECO_TRIM_GAIN_Pos        CLK_ECO_CONFIG2_ECO_TRIM_GAIN_Pos
#define SRSS_CLK_ECO_CONFIG2_ECO_TRIM_GAIN_Msk        CLK_ECO_CONFIG2_ECO_TRIM_GAIN_Msk
#define SRSS_CLK_ECO_CONFIG2_ECO_CTRL_AMPDETEN_Pos    CLK_ECO_CONFIG2_ECO_CTRL_AMPDETEN_Pos
#define SRSS_CLK_ECO_CONFIG2_ECO_CTRL_AMPDETEN_Msk    CLK_ECO_CONFIG2_ECO_CTRL_AMPDETEN_Msk

/* CLK_ECO.STATUS */
#define SRSS_CLK_ECO_STATUS_ECO_OK_Pos      CLK_ECO_STATUS_ECO_OK_Pos
#define SRSS_CLK_ECO_STATUS_ECO_OK_Msk      CLK_ECO_STATUS_ECO_OK_Msk
#define SRSS_CLK_ECO_STATUS_ECO_READY_Pos   CLK_ECO_STATUS_ECO_READY_Pos
#define SRSS_CLK_ECO_STATUS_ECO_READY_Msk   CLK_ECO_STATUS_ECO_READY_Msk

/* Technology Independant Register set */
#define SRSS_CLK_DSI_SELECT                 (((SRSS_Type *) SRSS)->CLK_DSI_SELECT)
#define SRSS_CLK_OUTPUT_FAST                (((SRSS_Type *) SRSS)->CLK_OUTPUT_FAST)
#define SRSS_CLK_OUTPUT_SLOW                (((SRSS_Type *) SRSS)->CLK_OUTPUT_SLOW)
#define SRSS_CLK_CAL_CNT1                   (((SRSS_Type *) SRSS)->CLK_CAL_CNT1)
#define SRSS_CLK_CAL_CNT2                   (((SRSS_Type *) SRSS)->CLK_CAL_CNT2)
#define SRSS_SRSS_INTR                      (((SRSS_Type *) SRSS)->SRSS_INTR)
#define SRSS_SRSS_INTR_SET                  (((SRSS_Type *) SRSS)->SRSS_INTR_SET)
#define SRSS_SRSS_INTR_MASK                 (((SRSS_Type *) SRSS)->SRSS_INTR_MASK)
#define SRSS_SRSS_INTR_MASKED               (((SRSS_Type *) SRSS)->SRSS_INTR_MASKED)
#define SRSS_SRSS_AINTR                     (((SRSS_Type *) SRSS)->SRSS_AINTR)
#define SRSS_SRSS_AINTR_SET                 (((SRSS_Type *) SRSS)->SRSS_AINTR_SET)
#define SRSS_SRSS_AINTR_MASK                (((SRSS_Type *) SRSS)->SRSS_AINTR_MASK)
#define SRSS_SRSS_AINTR_MASKED              (((SRSS_Type *) SRSS)->SRSS_AINTR_MASKED)
#define SRSS_PWR_CTL                        (((SRSS_Type *) SRSS)->PWR_CTL)
#define SRSS_PWR_CTL2                       (((SRSS_Type *) SRSS)->PWR_CTL2)
#define SRSS_PWR_HIBERNATE                  (((SRSS_Type *) SRSS)->PWR_HIBERNATE)
#define SRSS_PWR_CTL3                       (((SRSS_Type *) SRSS)->PWR_CTL3)
#define SRSS_PWR_STATUS                     (((SRSS_Type *) SRSS)->PWR_STATUS)
#define SRSS_PWR_HIB_DATA                   (((SRSS_Type *) SRSS)->PWR_HIB_DATA)
#define SRSS_CLK_PATH_SELECT                (((SRSS_Type *) SRSS)->CLK_PATH_SELECT)
#define SRSS_CLK_ROOT_SELECT                (((SRSS_Type *) SRSS)->CLK_ROOT_SELECT)
#define SRSS_CLK_DIRECT_SELECT              (((SRSS_Type *) SRSS)->CLK_DIRECT_SELECT)
#define SRSS_CLK_ECO_STATUS                 (((SRSS_Type *) SRSS)->CLK_ECO_STRUCT.STATUS)
#define SRSS_CLK_ILO_CONFIG                 (((SRSS_Type *) SRSS)->CLK_ILO_CONFIG)
#define SRSS_CLK_TRIM_ILO_CTL               (((SRSS_Type *) SRSS)->CLK_TRIM_ILO_CTL)
#define SRSS_CLK_PILO_CONFIG                (((SRSS_Type *) SRSS)->CLK_PILO_CONFIG)
#define SRSS_CLK_ECO_CONFIG                 (((SRSS_Type *) SRSS)->CLK_ECO_STRUCT.CONFIG)
#define SRSS_CLK_ECO_CONFIG2                (((SRSS_Type *) SRSS)->CLK_ECO_STRUCT.CONFIG2)
#define SRSS_CLK_TRIM_ECO_CTL               (((SRSS_Type *) SRSS)->CLK_TRIM_ECO_CTL)
#define SRSS_CLK_MFO_CONFIG                 (((SRSS_Type *) SRSS)->CLK_MFO_CONFIG)
#define SRSS_CLK_IHO_CONFIG                 (((SRSS_Type *) SRSS)->CLK_IHO_CONFIG)
#define SRSS_CLK_ALTHF_CTL                  (((SRSS_Type *) SRSS)->CLK_ALTHF_CTL)

#define SRSS_CSV_HF_STRUCT                  (((SRSS_Type *) SRSS)->CSV_HF)
#define SRSS_CLK_SELECT                     (((SRSS_Type *) SRSS)->CLK_SELECT)
#define SRSS_CLK_TIMER_CTL                  (((SRSS_Type *) SRSS)->CLK_TIMER_CTL)
#define SRSS_CLK_IMO_CONFIG                 (((SRSS_Type *) SRSS)->CLK_IMO_CONFIG)
#define SRSS_CLK_ECO_PRESCALE               (((SRSS_Type *) SRSS)->CLK_ECO_PRESCALE)
#define SRSS_CLK_MF_SELECT                  (((SRSS_Type *) SRSS)->CLK_MF_SELECT)
#define SRSS_CSV_REF_SEL                    (((SRSS_Type *) SRSS)->CSV_REF_SEL)
#define SRSS_CSV_REF                        (((SRSS_Type *) SRSS)->CSV_REF)
#define SRSS_CSV_LF_STRUCT                  (((SRSS_Type *) SRSS)->CSV_LF)
#define SRSS_CSV_LF_REF_SEL                 (((SRSS_Type *) SRSS)->CSV_LF_REF_SEL)
#define SRSS_CSV_ILO                        (((SRSS_Type *) SRSS)->CSV_ILO)
#define SRSS_RES_CAUSE                      (((SRSS_Type *) SRSS)->RES_CAUSE)
#define SRSS_RES_CAUSE2                     (((SRSS_Type *) SRSS)->RES_CAUSE2)
#define SRSS_RES_CAUSE_EXTEND               (((SRSS_Type *) SRSS)->RES_CAUSE_EXTEND)
#define SRSS_PWR_CBUCK_CTL                  (((SRSS_Type *) SRSS)->PWR_CBUCK_CTL)
#define SRSS_PWR_CBUCK_CTL2                 (((SRSS_Type *) SRSS)->PWR_CBUCK_CTL2)
#define SRSS_PWR_CBUCK_DPSLP_CTL            (((SRSS_Type *) SRSS)->PWR_CBUCK_DPSLP_CTL)
#define SRSS_PWR_CBUCK_STATUS               (((SRSS_Type *) SRSS)->PWR_CBUCK_STATUS)
#define SRSS_PWR_SDR0_CTL                   (((SRSS_Type *) SRSS)->PWR_SDR0_CTL)
#define SRSS_PWR_SDR1_CTL                   (((SRSS_Type *) SRSS)->PWR_SDR1_CTL)
#define SRSS_PWR_HVLDO0_CTL                 (((SRSS_Type *) SRSS)->PWR_HVLDO0_CTL)
#define SRSS_CLK_DPLL_LP                    (((SRSS_Type *) SRSS)->CLK_DPLL_LP)
#define SRSS_CLK_DPLL_HP                    (((SRSS_Type *) SRSS)->CLK_DPLL_HP)
#define SRSS_PWR_RETLDO_CTL                 (((SRSS_Type *) SRSS)->PWR_RETLDO_CTL)
#define SRSS_PWR_SRAMLDO_CTL                (((SRSS_Type *) SRSS)->PWR_SRAMLDO_CTL)
#define SRSS_PWR_MISCLDO_CTL                (((SRSS_Type *) SRSS)->PWR_MISCLDO_CTL)

#define SRSS_DECODED_LCS_DATA               (((SRSS_Type *) SRSS)->DECODED_LCS_DATA)

#define SRSS_CLK_LP_PLL                     (((SRSS_Type *) SRSS)->CLK_LP_PLL)
#define SRSS_CLK_IHO                        (((SRSS_Type *) SRSS)->CLK_IHO)
#define SRSS_TST_XRES_SECURE                (((SRSS_Type *) SRSS)->TST_XRES_SECURE)
#define SRSS_RES_PXRES_CTL                  (((SRSS_Type *) SRSS)->RES_PXRES_CTL)
#define SRSS_WDT_CTL                        (((SRSS_Type *) SRSS)->WDT_CTL)
#define SRSS_WDT_CNT                        (((SRSS_Type *) SRSS)->WDT_CNT)
#define SRSS_WDT_MATCH                      (((SRSS_Type *) SRSS)->WDT_MATCH)
#define SRSS_WDT_MATCH2                      (((SRSS_Type *) SRSS)->WDT_MATCH2)

#define SRSS_PWR_LVD_CTL                    (((SRSS_Type *) SRSS)->PWR_LVD_CTL)
#define SRSS_PWR_LVD_STATUS                 (((SRSS_Type *) SRSS)->PWR_LVD_STATUS)

#define SRSS_PWR_HIB_WAKE_CTL               (((SRSS_Type *) SRSS)->PWR_HIB_WAKE_CTL)
#define SRSS_PWR_HIB_WAKE_CTL2              (((SRSS_Type *) SRSS)->PWR_HIB_WAKE_CTL2)
#define SRSS_PWR_HIB_WAKE_CAUSE             (((SRSS_Type *) SRSS)->PWR_HIB_WAKE_CAUSE)
#define SRSS_RES_SOFT_CTL                   (((SRSS_Type *) SRSS)->RES_SOFT_CTL)


#define SRSS_TST_DDFT_FAST_CTL_REG          (*(volatile uint32_t *)(SRSS_BASE + 0x1104U))
#define SRSS_TST_DDFT_SLOW_CTL_REG          (*(volatile uint32_t *)(SRSS_BASE + 0x1108U))

#define SRSS_TST_DDFT_SLOW_CTL_MASK         (0x00001F1EU)
#define SRSS_TST_DDFT_FAST_CTL_MASK         (62U)

#define SRSS_CLK_DPLL_LP_CONFIG(pllNum)     (((SRSS_Type *) SRSS)->CLK_DPLL_LP[pllNum].CONFIG)
#define SRSS_CLK_DPLL_LP_CONFIG2(pllNum)    (((SRSS_Type *) SRSS)->CLK_DPLL_LP[pllNum].CONFIG2)
#define SRSS_CLK_DPLL_LP_CONFIG3(pllNum)    (((SRSS_Type *) SRSS)->CLK_DPLL_LP[pllNum].CONFIG3)
#define SRSS_CLK_DPLL_LP_CONFIG4(pllNum)    (((SRSS_Type *) SRSS)->CLK_DPLL_LP[pllNum].CONFIG4)
#define SRSS_CLK_DPLL_LP_CONFIG5(pllNum)    (((SRSS_Type *) SRSS)->CLK_DPLL_LP[pllNum].CONFIG5)
#if CY_IP_MXS22SRSS_VERSION_MINOR == (1u)
#define SRSS_CLK_DPLL_LP_CONFIG6(pllNum)    (((SRSS_Type *) SRSS)->CLK_DPLL_LP[pllNum].CONFIG6)
#define SRSS_CLK_DPLL_LP_CONFIG7(pllNum)    (((SRSS_Type *) SRSS)->CLK_DPLL_LP[pllNum].CONFIG7)
#endif
#define SRSS_CLK_DPLL_LP_STATUS(pllNum)     (((SRSS_Type *) SRSS)->CLK_DPLL_LP[pllNum].STATUS)

#define SRSS_CLK_DPLL_HP_CONFIG(pllNum)         (((SRSS_Type *) SRSS)->CLK_DPLL_HP[pllNum].CONFIG)
#define SRSS_CLK_DPLL_HP_CONFIG2(pllNum)        (((SRSS_Type *) SRSS)->CLK_DPLL_HP[pllNum].CONFIG2)
#define SRSS_CLK_DPLL_HP_CONFIG3(pllNum)        (((SRSS_Type *) SRSS)->CLK_DPLL_HP[pllNum].CONFIG3)
#define SRSS_CLK_DPLL_HP_CONFIG4(pllNum)        (((SRSS_Type *) SRSS)->CLK_DPLL_HP[pllNum].CONFIG4)
#define SRSS_CLK_DPLL_HP_CONFIG5(pllNum)        (((SRSS_Type *) SRSS)->CLK_DPLL_HP[pllNum].CONFIG5)
#define SRSS_CLK_DPLL_HP_TRIGMOD(pllNum)        (((SRSS_Type *) SRSS)->CLK_DPLL_HP[pllNum].TRIGMOD)
#define SRSS_CLK_DPLL_HP_TRIGMOD2(pllNum)       (((SRSS_Type *) SRSS)->CLK_DPLL_HP[pllNum].TRIGMOD2)
#define SRSS_CLK_DPLL_HP_STATUS(pllNum)         (((SRSS_Type *) SRSS)->CLK_DPLL_HP[pllNum].STATUS)
#define SRSS_CLK_DPLL_HP_DUTYCAL_CTRL(pllNum)   (((SRSS_Type *) SRSS)->CLK_DPLL_HP[pllNum].DUTYCAL_CTRL)


#define SRSS_TRIM_RAM_CTL(index)                ((RAM_TRIM_Type*) &SRSS->RAM_TRIM_STRUCT)->TRIM_RAM_CTL[index]

#define SRSS_CSV_HF_CSV_REF_CTL(hf)             (((SRSS_Type *) SRSS)->CSV_HF_STRUCT.CSV[hf].REF_CTL)
#define SRSS_CSV_HF_CSV_REF_LIMIT(hf)           (((SRSS_Type *) SRSS)->CSV_HF_STRUCT.CSV[hf].REF_LIMIT)
#define SRSS_CSV_HF_CSV_MON_CTL(hf)             (((SRSS_Type *) SRSS)->CSV_HF_STRUCT.CSV[hf].MON_CTL)

#define SRSS_CSV_LF_CSV_REF_CTL                 (((SRSS_Type *) SRSS)->CSV_LF_STRUCT.CSV.REF_CTL)
#define SRSS_CSV_LF_CSV_REF_LIMIT               (((SRSS_Type *) SRSS)->CSV_LF_STRUCT.CSV.REF_LIMIT)
#define SRSS_CSV_LF_CSV_MON_CTL                 (((SRSS_Type *) SRSS)->CSV_LF_STRUCT.CSV.MON_CTL)
/*******************************************************************************
*                PERI
*******************************************************************************/
/*******************************************************************************
*                PERI PCLK
*******************************************************************************/

#define PERI_INSTANCE_COUNT                    (CY_IP_MXSPERI_INSTANCES)

#define PERI_PCLK_PERI_NUM_Msk                 (0x000000FFU)
#define PERI_PCLK_GR_NUM_Msk                   (0x0000FF00U)
#define PERI_PCLK_GR_NUM_Pos                   (8U)
#define PERI_PCLK_PERIPHERAL_GROUP_NUM         (1UL << PERI_PCLK_GR_NUM_Pos)
#define PERI_PCLK_INST_NUM_Msk                 (0x00FF0000U)
#define PERI_PCLK_INST_NUM_Pos                 (16U)

#define PERI_PCLK_GR_NUM(instNum)              (((instNum) == 0U)? PERI0_PCLK_GROUP_NR : PERI1_PCLK_GROUP_NR)

#define PERI_PCLK1_OFFSET                      (PERI_PCLK1_BASE - PERI_PCLK0_BASE)
#define PERI_PCLK_REG_BASE(instNum)            ((PERI_PCLK_Type*)(PERI_PCLK0_BASE + ((instNum) * PERI_PCLK1_OFFSET)))

#define PERI_DIV_8_CTL(instNum, grNum, divNum)                   ((PERI_PCLK_GR_Type*) &PERI_PCLK_REG_BASE(instNum)->GR[grNum])->DIV_8_CTL[divNum]
#define PERI_DIV_16_CTL(instNum, grNum, divNum)                  ((PERI_PCLK_GR_Type*) &PERI_PCLK_REG_BASE(instNum)->GR[grNum])->DIV_16_CTL[divNum]
#define PERI_DIV_16_5_CTL(instNum, grNum, divNum)                ((PERI_PCLK_GR_Type*) &PERI_PCLK_REG_BASE(instNum)->GR[grNum])->DIV_16_5_CTL[divNum]
#define PERI_DIV_24_5_CTL(instNum, grNum, divNum)                ((PERI_PCLK_GR_Type*) &PERI_PCLK_REG_BASE(instNum)->GR[grNum])->DIV_24_5_CTL[divNum]
#define PERI_CLOCK_CTL(instNum, grNum, periNum)                  ((PERI_PCLK_GR_Type*) &PERI_PCLK_REG_BASE(instNum)->GR[grNum])->CLOCK_CTL[periNum]
#define PERI_DIV_CMD(instNum, grNum)                             ((PERI_PCLK_GR_Type*) &PERI_PCLK_REG_BASE(instNum)->GR[grNum])->DIV_CMD

__STATIC_INLINE uint32_t PERI_PCLK_GR_DIV_8_NR(uint32_t instNum, uint32_t grNum)
{
    uint32_t divider_num = 0U;
    switch (instNum)
    {
        case 0:
        {
            switch(grNum)
            {
                case 0: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_8_VECT; break;
                case 1: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_8_VECT; break;
                case 2: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_8_VECT; break;
                case 3: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_8_VECT; break;
                case 4: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_8_VECT; break;
                case 5: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_8_VECT; break;
                case 6: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_8_VECT; break;
                case 7: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_8_VECT; break;
                case 8: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_8_VECT; break;
                case 9: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_8_VECT; break;
                default: /* Unsupported grp number */ break;
            }
        }break;
        case 1:
        {
            switch(grNum)
            {
                case 0: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_8_VECT; break;
                case 1: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_8_VECT; break;
                case 2: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_8_VECT; break;
                case 3: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_8_VECT; break;
                case 4: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_8_VECT; break;
                case 5: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_8_VECT; break;
                default: /* Unsupported grp number */ break;
            }
        }break;
        default: /* Unsupported instance number */ break;
    }
    return     divider_num;
}
__STATIC_INLINE uint32_t PERI_PCLK_GR_DIV_16_NR(uint32_t instNum, uint32_t grNum)
{
    uint32_t divider_num = 0U;
    switch (instNum)
    {
        case 0:
        {
            switch(grNum)
            {
                case 0: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_VECT; break;
                case 1: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_VECT; break;
                case 2: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_VECT; break;
                case 3: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_VECT; break;
                case 4: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_VECT; break;
                case 5: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_VECT; break;
                case 6: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_16_VECT; break;
                case 7: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_16_VECT; break;
                case 8: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_16_VECT; break;
                case 9: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_16_VECT; break;
                default: /* Unsupported grp number */ break;
            }
        }break;
        case 1:
        {
            switch(grNum)
            {
                case 0: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_VECT; break;
                case 1: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_VECT; break;
                case 2: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_VECT; break;
                case 3: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_VECT; break;
                case 4: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_VECT; break;
                case 5: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_VECT; break;
                default: /* Unsupported grp number */ break;
            }
        }break;
        default: /* Unsupported instance number */ break;
    }
    return divider_num;
}
__STATIC_INLINE uint32_t PERI_PCLK_GR_DIV_16_5_NR(uint32_t instNum, uint32_t grNum)
{
    uint32_t divider_num = 0U;
    switch (instNum)
    {
        case 0:
        {
            switch(grNum)
            {
                case 0: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_5_VECT; break;
                case 1: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_5_VECT; break;
                case 2: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_5_VECT; break;
                case 3: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_5_VECT; break;
                case 4: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_5_VECT; break;
                case 5: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_5_VECT; break;
                case 6: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_16_5_VECT; break;
                case 7: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_16_5_VECT; break;
                case 8: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_16_5_VECT; break;
                case 9: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_16_5_VECT; break;
                default: /* Unsupported grp number */ break;
            }
        }break;
        case 1:
        {
            switch(grNum)
            {
                case 0: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_5_VECT; break;
                case 1: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_5_VECT; break;
                case 2: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_5_VECT; break;
                case 3: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_5_VECT; break;
                case 4: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_5_VECT; break;
                case 5: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_5_VECT; break;
                default: /* Unsupported grp number */ break;
            }
        }break;
        default: /* Unsupported instance number */ break;
    }
    return     divider_num;
}
__STATIC_INLINE uint32_t PERI_PCLK_GR_DIV_24_5_NR(uint32_t instNum, uint32_t grNum)
{
    uint32_t divider_num = 0U;
    switch (instNum)
    {
        case 0:
        {
            switch(grNum)
            {
                case 0: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_24_5_VECT; break;
                case 1: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_24_5_VECT; break;
                case 2: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_24_5_VECT; break;
                case 3: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_24_5_VECT; break;
                case 4: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_24_5_VECT; break;
                case 5: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_24_5_VECT; break;
                case 6: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_24_5_VECT; break;
                case 7: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_24_5_VECT; break;
                case 8: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_24_5_VECT; break;
                case 9: divider_num = PERI0_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_24_5_VECT; break;
                default: /* Unsupported grp number */ break;
            }
        }break;
        case 1:
        {
            switch(grNum)
            {
                case 0: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_24_5_VECT; break;
                case 1: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_24_5_VECT; break;
                case 2: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_24_5_VECT; break;
                case 3: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_24_5_VECT; break;
                case 4: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_24_5_VECT; break;
                case 5: divider_num = PERI1_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_24_5_VECT; break;
                default: /* Unsupported grp number */ break;
            }
        }break;
        default: /* Unsupported      instance number */ break;
    }
    return     divider_num;
}

/* PERI_PCLK_GR.DIV_CMD */
#define CY_PERI_DIV_CMD_DIV_SEL_Pos             PERI_PCLK_GR_DIV_CMD_DIV_SEL_Pos
#define CY_PERI_DIV_CMD_DIV_SEL_Msk             PERI_PCLK_GR_DIV_CMD_DIV_SEL_Msk
#define CY_PERI_DIV_CMD_TYPE_SEL_Pos            PERI_PCLK_GR_DIV_CMD_TYPE_SEL_Pos
#define CY_PERI_DIV_CMD_TYPE_SEL_Msk            PERI_PCLK_GR_DIV_CMD_TYPE_SEL_Msk
#define CY_PERI_DIV_CMD_PA_DIV_SEL_Pos          PERI_PCLK_GR_DIV_CMD_PA_DIV_SEL_Pos
#define CY_PERI_DIV_CMD_PA_DIV_SEL_Msk          PERI_PCLK_GR_DIV_CMD_PA_DIV_SEL_Msk
#define CY_PERI_DIV_CMD_PA_TYPE_SEL_Pos         PERI_PCLK_GR_DIV_CMD_PA_TYPE_SEL_Pos
#define CY_PERI_DIV_CMD_PA_TYPE_SEL_Msk         PERI_PCLK_GR_DIV_CMD_PA_TYPE_SEL_Msk
#define CY_PERI_DIV_CMD_DISABLE_Pos             PERI_PCLK_GR_DIV_CMD_DISABLE_Pos
#define CY_PERI_DIV_CMD_DISABLE_Msk             PERI_PCLK_GR_DIV_CMD_DISABLE_Msk
#define CY_PERI_DIV_CMD_ENABLE_Pos              PERI_PCLK_GR_DIV_CMD_ENABLE_Pos
#define CY_PERI_DIV_CMD_ENABLE_Msk              PERI_PCLK_GR_DIV_CMD_ENABLE_Msk


#define PERI_DIV_CMD_DIV_SEL_Pos                PERI_PCLK_GR_DIV_CMD_DIV_SEL_Pos
#define PERI_DIV_CMD_DIV_SEL_Msk                PERI_PCLK_GR_DIV_CMD_DIV_SEL_Msk
#define PERI_DIV_CMD_TYPE_SEL_Pos               PERI_PCLK_GR_DIV_CMD_TYPE_SEL_Pos
#define PERI_DIV_CMD_TYPE_SEL_Msk               PERI_PCLK_GR_DIV_CMD_TYPE_SEL_Msk
#define PERI_DIV_CMD_PA_DIV_SEL_Pos             PERI_PCLK_GR_DIV_CMD_PA_DIV_SEL_Pos
#define PERI_DIV_CMD_PA_DIV_SEL_Msk             PERI_PCLK_GR_DIV_CMD_PA_DIV_SEL_Msk
#define PERI_DIV_CMD_PA_TYPE_SEL_Pos            PERI_PCLK_GR_DIV_CMD_PA_TYPE_SEL_Pos
#define PERI_DIV_CMD_PA_TYPE_SEL_Msk            PERI_PCLK_GR_DIV_CMD_PA_TYPE_SEL_Msk
#define PERI_DIV_CMD_DISABLE_Pos                PERI_PCLK_GR_DIV_CMD_DISABLE_Pos
#define PERI_DIV_CMD_DISABLE_Msk                PERI_PCLK_GR_DIV_CMD_DISABLE_Msk
#define PERI_DIV_CMD_ENABLE_Pos                 PERI_PCLK_GR_DIV_CMD_ENABLE_Pos
#define PERI_DIV_CMD_ENABLE_Msk                 PERI_PCLK_GR_DIV_CMD_ENABLE_Msk

/* PERI_PCLK_GR.CLOCK_CTL */
#define CY_PERI_CLOCK_CTL_DIV_SEL_Pos           PERI_PCLK_GR_CLOCK_CTL_DIV_SEL_Pos
#define CY_PERI_CLOCK_CTL_DIV_SEL_Msk           PERI_PCLK_GR_CLOCK_CTL_DIV_SEL_Msk
#define CY_PERI_CLOCK_CTL_TYPE_SEL_Pos          PERI_PCLK_GR_CLOCK_CTL_TYPE_SEL_Pos
#define CY_PERI_CLOCK_CTL_TYPE_SEL_Msk          PERI_PCLK_GR_CLOCK_CTL_TYPE_SEL_Msk
/* PERI.DIV_8_CTL */
#define PERI_DIV_8_CTL_EN_Pos                   PERI_PCLK_GR_DIV_8_CTL_EN_Pos
#define PERI_DIV_8_CTL_EN_Msk                   PERI_PCLK_GR_DIV_8_CTL_EN_Msk
#define PERI_DIV_8_CTL_INT8_DIV_Pos             PERI_PCLK_GR_DIV_8_CTL_INT8_DIV_Pos
#define PERI_DIV_8_CTL_INT8_DIV_Msk             PERI_PCLK_GR_DIV_8_CTL_INT8_DIV_Msk
/* PERI.DIV_16_CTL */
#define PERI_DIV_16_CTL_EN_Pos                  PERI_PCLK_GR_DIV_16_CTL_EN_Pos
#define PERI_DIV_16_CTL_EN_Msk                  PERI_PCLK_GR_DIV_16_CTL_EN_Msk
#define PERI_DIV_16_CTL_INT16_DIV_Pos           PERI_PCLK_GR_DIV_16_CTL_INT16_DIV_Pos
#define PERI_DIV_16_CTL_INT16_DIV_Msk           PERI_PCLK_GR_DIV_16_CTL_INT16_DIV_Msk
/* PERI.DIV_16_5_CTL */
#define PERI_DIV_16_5_CTL_EN_Pos                PERI_PCLK_GR_DIV_16_5_CTL_EN_Pos
#define PERI_DIV_16_5_CTL_EN_Msk                PERI_PCLK_GR_DIV_16_5_CTL_EN_Msk
#define PERI_DIV_16_5_CTL_FRAC5_DIV_Pos         PERI_PCLK_GR_DIV_16_5_CTL_FRAC5_DIV_Pos
#define PERI_DIV_16_5_CTL_FRAC5_DIV_Msk         PERI_PCLK_GR_DIV_16_5_CTL_FRAC5_DIV_Msk
#define PERI_DIV_16_5_CTL_INT16_DIV_Pos         PERI_PCLK_GR_DIV_16_5_CTL_INT16_DIV_Pos
#define PERI_DIV_16_5_CTL_INT16_DIV_Msk         PERI_PCLK_GR_DIV_16_5_CTL_INT16_DIV_Msk
/* PERI.DIV_24_5_CTL */
#define PERI_DIV_24_5_CTL_EN_Pos                PERI_PCLK_GR_DIV_24_5_CTL_EN_Pos
#define PERI_DIV_24_5_CTL_EN_Msk                PERI_PCLK_GR_DIV_24_5_CTL_EN_Msk
#define PERI_DIV_24_5_CTL_FRAC5_DIV_Pos         PERI_PCLK_GR_DIV_24_5_CTL_FRAC5_DIV_Pos
#define PERI_DIV_24_5_CTL_FRAC5_DIV_Msk         PERI_PCLK_GR_DIV_24_5_CTL_FRAC5_DIV_Msk
#define PERI_DIV_24_5_CTL_INT24_DIV_Pos         PERI_PCLK_GR_DIV_24_5_CTL_INT24_DIV_Pos
#define PERI_DIV_24_5_CTL_INT24_DIV_Msk         PERI_PCLK_GR_DIV_24_5_CTL_INT24_DIV_Msk

/*******************************************************************************
*                PERI-GROUP
*******************************************************************************/
#define CY_PERI_GROUP_NR                        6

#ifndef PERI0_BASE
#define PERI0_BASE PERI_BASE
#endif

#ifndef PERI1_BASE
#define PERI1_BASE 0U
#endif


#define PERI_GR_OFFSET                      (PERI1_BASE - PERI0_BASE)
#define PERI_GR_REG_BASE(instNum)           ((PERI_Type*)(PERI0_BASE + ((instNum) * PERI_GR_OFFSET)))

#define PERI_GR_INST_NUM_Msk                 (0x0000FF00U)
#define PERI_GR_INST_NUM_Pos                 (8U)


#define PERI_GR_CLOCK_CTL(instNum, grNum)   ((PERI_GR_Type*) &PERI_GR_REG_BASE(instNum)->GR[grNum])->CLOCK_CTL
#define PERI_GR_SL_CTL(instNum, grNum)      ((PERI_GR_Type*) &PERI_GR_REG_BASE(instNum)->GR[grNum])->SL_CTL
#define PERI_GR_SL_CTL2(instNum, grNum)     ((PERI_GR_Type*) &PERI_GR_REG_BASE(instNum)->GR[grNum])->SL_CTL2
#define PERI_GR_SL_CTL3(instNum, grNum)     ((PERI_GR_Type*) &PERI_GR_REG_BASE(instNum)->GR[grNum])->SL_CTL3

/* CLK_HF* to PERI PCLK Group Mapping */
#define PERI0_PCLK_GR_NUM_0_CLK_HF_NUM              (0U)
#define PERI0_PCLK_GR_NUM_1_CLK_HF_NUM              (10U)
#define PERI0_PCLK_GR_NUM_2_CLK_HF_NUM              (9U)
#define PERI0_PCLK_GR_NUM_3_CLK_HF_NUM              (5U)
#define PERI0_PCLK_GR_NUM_4_CLK_HF_NUM              (6U)
#define PERI0_PCLK_GR_NUM_5_CLK_HF_NUM              (10U)
#define PERI0_PCLK_GR_NUM_6_CLK_HF_NUM              (13U)
#define PERI0_PCLK_GR_NUM_7_CLK_HF_NUM              (1U)
#define PERI0_PCLK_GR_NUM_8_CLK_HF_NUM              (11U)
#define PERI0_PCLK_GR_NUM_9_CLK_HF_NUM              (13U)


#define PERI1_PCLK_GR_NUM_0_CLK_HF_NUM              (1U)
#define PERI1_PCLK_GR_NUM_1_CLK_HF_NUM              (7U)
#define PERI1_PCLK_GR_NUM_2_CLK_HF_NUM              (5U)
#define PERI1_PCLK_GR_NUM_3_CLK_HF_NUM              (6U)
#define PERI1_PCLK_GR_NUM_4_CLK_HF_NUM              (0U)
#define PERI1_PCLK_GR_NUM_5_CLK_HF_NUM              (2U)



/*******************************************************************************
*         PERI-TR
*******************************************************************************/

#define PERI_TR_CMD                         (((PERI_Type*) (PERI0_BASE))->TR_CMD)
#define PERI1_TR_CMD                         (((PERI_Type*) (PERI1_BASE))->TR_CMD)
#define PERI_TR_GR_TR_CTL(group, trCtl)     (*(volatile uint32_t*) ((uint32_t)PERI0_BASE+ (uint32_t)offsetof(PERI_Type,TR_GR) + \
                                            ((group) * (uint32_t)sizeof(PERI_TR_GR_Type)) + \
                                            ((trCtl) * (uint32_t)sizeof(uint32_t))))
#define PERI1_TR_GR_TR_CTL(group, trCtl)     (*(volatile uint32_t*) ((uint32_t)PERI1_BASE+ (uint32_t)offsetof(PERI_Type,TR_GR) + \
                                            ((group) * (uint32_t)sizeof(PERI_TR_GR_Type)) + \
                                            ((trCtl) * (uint32_t)sizeof(uint32_t))))

#if defined (CY_IP_MXSPERI)
#define PERI_TR_GR_TR_OUT_CTL_TR_SEL_Msk PERI_TR_GR_TR_CTL_TR_SEL_Msk
#define PERI_TR_GR_TR_OUT_CTL_TR_SEL_Pos PERI_TR_GR_TR_CTL_TR_SEL_Pos
#define CY_PERI_TR_CTL_SEL_Msk PERI_TR_GR_TR_CTL_TR_SEL_Msk
#define CY_PERI_TR_CTL_SEL_Pos PERI_TR_GR_TR_CTL_TR_SEL_Pos
#define PERI_V2_TR_CMD_OUT_SEL_Msk PERI_TR_CMD_OUT_SEL_Msk
#define PERI_V2_TR_CMD_OUT_SEL_Pos PERI_TR_CMD_OUT_SEL_Pos
#define PERI_V2_TR_CMD_GROUP_SEL_Msk PERI_TR_CMD_GROUP_SEL_Msk
#define PERI_V2_TR_CMD_GROUP_SEL_Pos PERI_TR_CMD_GROUP_SEL_Pos
#define CY_PERI_TR_CMD_GROUP_SEL_Msk PERI_TR_CMD_GROUP_SEL_Msk
#define CY_PERI_TR_CMD_GROUP_SEL_Pos PERI_TR_CMD_GROUP_SEL_Pos
#define CY_PERI_TR_CTL_SEL PERI_TR_GR_TR_CTL_TR_SEL
#define PERI_TR_GR_TR_OUT_CTL_TR_INV_Msk PERI_TR_GR_TR_CTL_TR_INV_Msk
#define PERI_TR_GR_TR_OUT_CTL_TR_INV_Pos PERI_TR_GR_TR_CTL_TR_INV_Pos
#define PERI_TR_GR_TR_OUT_CTL_TR_EDGE_Msk PERI_TR_GR_TR_CTL_TR_EDGE_Msk
#define PERI_TR_GR_TR_OUT_CTL_TR_EDGE_Pos PERI_TR_GR_TR_CTL_TR_EDGE_Pos
#define PERI_V2_TR_CMD_TR_EDGE_Msk PERI_TR_CMD_TR_EDGE_Msk
#define PERI_V2_TR_CMD_TR_EDGE_Pos PERI_TR_CMD_TR_EDGE_Pos
#define PERI_TR_1TO1_GR_V2_TR_CTL_TR_INV_Msk PERI_TR_1TO1_GR_TR_CTL_TR_INV_Msk
#define PERI_TR_1TO1_GR_V2_TR_CTL_TR_INV_Pos PERI_TR_1TO1_GR_TR_CTL_TR_INV_Pos
#define PERI_TR_1TO1_GR_V2_TR_CTL_TR_EDGE_Msk PERI_TR_1TO1_GR_TR_CTL_TR_EDGE_Msk
#define PERI_TR_1TO1_GR_V2_TR_CTL_TR_EDGE_Pos PERI_TR_1TO1_GR_TR_CTL_TR_EDGE_Pos
#define PERI_TR_1TO1_GR_V2_TR_CTL_TR_SEL_Msk PERI_TR_1TO1_GR_TR_CTL_TR_SEL_Msk
#define PERI_TR_1TO1_GR_V2_TR_CTL_TR_SEL_Pos PERI_TR_1TO1_GR_TR_CTL_TR_SEL_Pos
#define PERI_TR_GR_V2_TR_CTL_DBG_FREEZE_EN_Msk PERI_TR_GR_TR_CTL_DBG_FREEZE_EN_Msk
#define PERI_TR_GR_V2_TR_CTL_DBG_FREEZE_EN_Pos PERI_TR_GR_TR_CTL_DBG_FREEZE_EN_Pos

#if (CY_IP_MXSPERI_INSTANCES == 2U)
#define PERI_INSTANCE_1_IDENT_Pos 16UL
#define PERI_INSTANCE_1_IDENT_Msk 0x10000UL
#endif /* CY_IP_MXSPERI_INSTANCES == 2U */

#endif /* CY_IP_MXSPERI */


#define CY_SYSPM_BOOTROM_ENTRYPOINT_ADDR        ((uint32_t)(&BACKUP_BREG_SET1[0])) /* Boot ROM will check this address for locating the entry point after Warm Boot */
#define CY_SYSPM_BOOTROM_DSRAM_DBG_ENABLE_MASK  0x00000001U


/*******************************************************************************
*                MXCM33
*******************************************************************************/
#define MXCM33_CM33_NMI_CTL(nmi)              (((volatile uint32_t *) (MXCM33->CM33_NMI_CTL))[(nmi)])
#define CM55_0_CPU_EVENT                      (0xFU)

/*******************************************************************************
*                MXCM55
*******************************************************************************/
#define MXCM55_CM55_NMI_CTL(nmi)              (((volatile uint32_t *) (MXCM55->CM55_NMI_CTL))[(nmi)])
#define CM33_0_CPU_EVENT                      (0xFU)

/*******************************************************************************
*                M0SECCPUSS
*******************************************************************************/
#define M0SECCPUSS_CLK_SYNC_CTL                (((M0SECCPUSS_Type*) M0SECCPUSS_BASE)->CLK_SYNC_CTL)
#define M0SECCPUSS_CM0_MS_PC                   (((M0SECCPUSS_Type*) M0SECCPUSS_BASE)->CM0_MS_PC)

/*******************************************************************************
*                MCWDT
*******************************************************************************/

#define MCWDT_CNTLOW(base)      (((MCWDT_STRUCT_Type *)(base))->MCWDT_CNTLOW)
#define MCWDT_CNTHIGH(base)     (((MCWDT_STRUCT_Type *)(base))->MCWDT_CNTHIGH)
#define MCWDT_MATCH(base)       (((MCWDT_STRUCT_Type *)(base))->MCWDT_MATCH)
#define MCWDT_CONFIG(base)      (((MCWDT_STRUCT_Type *)(base))->MCWDT_CONFIG)
#define MCWDT_CTL(base)         (((MCWDT_STRUCT_Type *)(base))->MCWDT_CTL)
#define MCWDT_INTR(base)        (((MCWDT_STRUCT_Type *)(base))->MCWDT_INTR)
#define MCWDT_INTR_SET(base)    (((MCWDT_STRUCT_Type *)(base))->MCWDT_INTR_SET)
#define MCWDT_INTR_MASK(base)   (((MCWDT_STRUCT_Type *)(base))->MCWDT_INTR_MASK)
#define MCWDT_INTR_MASKED(base) (((MCWDT_STRUCT_Type *)(base))->MCWDT_INTR_MASKED)
#define MCWDT_LOCK(base)        (((MCWDT_STRUCT_Type *)(base))->MCWDT_LOCK)
#define MCWDT_LOWER_LIMIT(base) (((MCWDT_STRUCT_Type *)(base))->MCWDT_LOWER_LIMIT)

/*******************************************************************************
*                CPUSS
*******************************************************************************/
#if defined (CORE_NAME_CM55_0)
#define CPUSS_SYSTICK_NS_CTL                (((APPCPUSS_Type*) APPCPUSS_BASE)->SYSTICK_NS_CTL)
#define CPUSS_SYSTICK_S_CTL                 (((APPCPUSS_Type*) APPCPUSS_BASE)->SYSTICK_S_CTL)
#define CPUSS_PRODUCT_ID                    (((APPCPUSS_Type*) APPCPUSS_BASE)->PRODUCT_ID)
#else
#define CPUSS_SYSTICK_NS_CTL                (((CPUSS_Type*) CPUSS_BASE)->SYSTICK_NS_CTL)
#define CPUSS_SYSTICK_S_CTL                 (((CPUSS_Type*) CPUSS_BASE)->SYSTICK_S_CTL)
#define CPUSS_TRIM_ROM_CTL                  (((CPUSS_Type*) CPUSS_BASE)->TRIM_ROM_CTL)
#define CPUSS_PRODUCT_ID                    (((CPUSS_Type*) CPUSS_BASE)->PRODUCT_ID)
#endif

/* ARM core registers */
#define SYSTICK_CTRL                        (((SysTick_Type *)SysTick)->CTRL)
#define SYSTICK_LOAD                        (((SysTick_Type *)SysTick)->LOAD)
#define SYSTICK_VAL                         (((SysTick_Type *)SysTick)->VAL)
#define SYSTICK_NS_CTRL                     (((SysTick_Type *)SysTick_NS)->CTRL)
#define SYSTICK_NS_LOAD                     (((SysTick_Type *)SysTick_NS)->LOAD)
#define SYSTICK_NS_VAL                      (((SysTick_Type *)SysTick_NS)->VAL)
#define SCB_SCR                             (((SCB_Type *)SCB)->SCR)
#define SCB_CPACR                           (((SCB_Type *)SCB)->CPACR)

#define __CMSIS_VERSION_5_9 ((5 << 16U) | 9)
#define __CMSIS_VERSION_6_0 ((6 << 16U) | 0)

#define SCS_CPPWR_SU10_Msk                  (0x100000U)
#define SCB_ENABLE_CPACR_CP10_CP11          (0xFUL << 20u)
#define SCS_ENABLE_CPPWR_SU10_SU11          (0xFUL << 20u)

#if (__CM_CMSIS_VERSION >= __CMSIS_VERSION_6_0)

#if defined (CORE_NAME_CM33_0)
#define SCS_CPPWR                           (((SCnSCB_Type *)SCnSCB)->CPPWR)
#elif defined (CORE_NAME_CM55_0)
#define SCS_CPPWR                           (((ICB_Type *)ICB)->CPPWR)
#endif
#else /* <= __CMSIS_VERSION_5_9 */
#if defined (CORE_NAME_CM33_0) || defined (CORE_NAME_CM55_0)
#define SCS_CPPWR                           (((SCnSCB_Type *)SCnSCB)->CPPWR)
#endif

#endif //__CM_CMSIS_VERSION

#if defined (CORE_NAME_CM55_0)
#if (__CM_CMSIS_VERSION >= __CMSIS_VERSION_5_9)
#define MEM_CTL_MSCR                        (((MemSysCtl_Type *)MEMSYSCTL)->MSCR)
#define EWIC_EWCI_ASCR                      (((EWIC_Type *)EWIC)->EWIC_ASCR)
#else
/* Remove below when CMSIS versiongrater than 5.9 */
#define MEMSYSCTL_MSCR_ICACTIVE_Pos        13U                                         /*!< MEMSYSCTL MSCR: ICACTIVE Position */
#define MEMSYSCTL_MSCR_ICACTIVE_Msk        (0x1UL << MEMSYSCTL_MSCR_ICACTIVE_Pos)      /*!< MEMSYSCTL MSCR: ICACTIVE Mask */

#define MEMSYSCTL_MSCR_DCACTIVE_Pos        12U                                         /*!< MEMSYSCTL MSCR: DCACTIVE Position */
#define MEMSYSCTL_MSCR_DCACTIVE_Msk        (0x1UL << MEMSYSCTL_MSCR_DCACTIVE_Pos)      /*!< MEMSYSCTL MSCR: DCACTIVE Mask */

/* EWIC Automatic Sequence Control (EWIC_ASCR) Register Definitions */
#define EWIC_EWIC_ASCR_ASPU_Pos             1U                                         /*!< EWIC EWIC_ASCR: ASPU Position */
#define EWIC_EWIC_ASCR_ASPU_Msk            (0x1UL << EWIC_EWIC_ASCR_ASPU_Pos)          /*!< EWIC EWIC_ASCR: ASPU Mask */

#define MEM_CTL_MSCR                        (*(volatile uint32_t *)(0xE001E000U))
#define EWIC_EWCI_ASCR                      (*(volatile uint32_t *)(0xE0047004U))
#endif
#endif

/*******************************************************************************
*                LPCOMP
*******************************************************************************/

#define LPCOMP_CMP0_CTRL(base)              (((LPCOMP_Type *)(base))->CMP0_CTRL)
#define LPCOMP_CMP1_CTRL(base)              (((LPCOMP_Type *)(base))->CMP1_CTRL)
#define LPCOMP_CMP0_SW_CLEAR(base)          (((LPCOMP_Type *)(base))->CMP0_SW_CLEAR)
#define LPCOMP_CMP1_SW_CLEAR(base)          (((LPCOMP_Type *)(base))->CMP1_SW_CLEAR)
#define LPCOMP_CMP0_SW(base)                (((LPCOMP_Type *)(base))->CMP0_SW)
#define LPCOMP_CMP1_SW(base)                (((LPCOMP_Type *)(base))->CMP1_SW)
#define LPCOMP_STATUS(base)                 (((LPCOMP_Type *)(base))->STATUS)
#define LPCOMP_CONFIG(base)                 (((LPCOMP_Type *)(base))->CONFIG)
#define LPCOMP_INTR(base)                   (((LPCOMP_Type *)(base))->INTR)
#define LPCOMP_INTR_SET(base)               (((LPCOMP_Type *)(base))->INTR_SET)
#define LPCOMP_INTR_MASK(base)              (((LPCOMP_Type *)(base))->INTR_MASK)
#define LPCOMP_INTR_MASKED(base)            (((LPCOMP_Type *)(base))->INTR_MASKED)
#if defined (CY_IP_MXS22LPCOMP)
#define LPCOMP_CMP0_OFFSET_TRIM(base)       (((LPCOMP_Type *)(base))->CMP0_OFFSET_TRIM)
#define LPCOMP_CMP1_OFFSET_TRIM(base)       (((LPCOMP_Type *)(base))->CMP1_OFFSET_TRIM)
#endif


/*******************************************************************************
*                AUTANALOG INFRA
*******************************************************************************/

#define AUTANALOG_INFRA_CLOCK_PTC_LP_DIV(base)         (((INFRA_Type *)(base))->CLOCK_PTC_LP_DIV)
#define AUTANALOG_INFRA_CLOCK_DAC_LP_DIV(base, cfgIdx) (((INFRA_Type *)(base))->CLOCK_DAC_LP_DIV[cfgIdx])
#define AUTANALOG_INFRA_CLOCK_PRIO_HS_DIV(base)        (((INFRA_Type *)(base))->CLOCK_PRIO_HS_DIV)
#define AUTANALOG_INFRA_PRIO_CFG(base, cfgIdx)         (((INFRA_Type *)(base))->PRIO_CFG[cfgIdx])
#define AUTANALOG_INFRA_LPOSC_CFG(base)                (((INFRA_LPOSC_Type *) (&((INFRA_Type *)base)->LPOSC))->CFG)
#define AUTANALOG_INFRA_AREF_CTRL(base)                (((INFRA_AREF_Type *)  (&((INFRA_Type *)base)->AREF))->CTRL)
#define AUTANALOG_INFRA_PRB_VREF_CTRL(base, cfgIdx)    (((INFRA_PRB_Type *)   (&((INFRA_Type *)base)->PRB))->VREF_CTRL[cfgIdx])
#define AUTANALOG_INFRA_TIMER_CTRL(base)               (((INFRA_TIMER_Type *) (&((INFRA_Type *)base)->TIMER))->CTRL)
#define AUTANALOG_INFRA_TIMER_CFG(base)                (((INFRA_TIMER_Type *) (&((INFRA_Type *)base)->TIMER))->CFG)
#define AUTANALOG_INFRA_TIMER_PERIOD(base)             (((INFRA_TIMER_Type *) (&((INFRA_Type *)base)->TIMER))->PERIOD)


/*******************************************************************************
*                AUTANALOG AC
*******************************************************************************/

#define AUTANALOG_AC_CFG(base)                 (((ACTRLR_Type *)(base))->CFG)
#define AUTANALOG_AC_CTRL(base)                (((ACTRLR_Type *)(base))->CTRL)
#define AUTANALOG_AC_CMD_RUN(base)             (((ACTRLR_Type *)(base))->CMD_RUN)
#define AUTANALOG_AC_CMD_PAUSE(base)           (((ACTRLR_Type *)(base))->DEBUG_PAUSE)
#define AUTANALOG_AC_CMD_SINGLE_STEP(base)     (((ACTRLR_Type *)(base))->DEBUG_SINGLE_STEP)
#define AUTANALOG_AC_STATUS(base)              (((ACTRLR_Type *)(base))->STATUS)
#define AUTANALOG_AC_PWR_STATUS(base)          (((ACTRLR_Type *)(base))->PWR_STATUS)
#define AUTANALOG_AC_CNTR_STATUS(base, cntIdx) (((ACTRLR_Type *)(base))->CNTR_STATUS[cntIdx])
#define AUTANALOG_AC_CMD_STATE(base)           (((ACTRLR_Type *)(base))->CMD_STATE)
#define AUTANALOG_AC_FW_TR(base, triggIdx)     (((ACTRLR_Type *)(base))->FW_TR[triggIdx])
#define AUTANALOG_AC_TT_CFG0(base, stateIdx)   (((ACTRLR_TTCFG_Type *)(&((ACTRLR_Type *)base)->TTCFG[stateIdx]))->TT_CFG0)
#define AUTANALOG_AC_TT_CFG1(base, stateIdx)   (((ACTRLR_TTCFG_Type *)(&((ACTRLR_Type *)base)->TTCFG[stateIdx]))->TT_CFG1)
#define AUTANALOG_AC_TT_CFG2(base, stateIdx)   (((ACTRLR_TTCFG_Type *)(&((ACTRLR_Type *)base)->TTCFG[stateIdx]))->TT_CFG2)
#define AUTANALOG_AC_TT_CFG3(base, stateIdx)   (((ACTRLR_TTCFG_Type *)(&((ACTRLR_Type *)base)->TTCFG[stateIdx]))->TT_CFG3)
#define AUTANALOG_AC_TT_CFG4(base, stateIdx)   (((ACTRLR_TTCFG_Type *)(&((ACTRLR_Type *)base)->TTCFG[stateIdx]))->TT_CFG4)


/*******************************************************************************
*                AUTANALOG CTBL
*******************************************************************************/

#define AUTANALOG_CTBX_STA_CFG(base)         (((CTBL_STA_Type *)(&((CTBL_Type *)base)->STA))->CFG)
#define AUTANALOG_CTBX_DYN_CFG(base, cfgIdx) (((CTBL_DYN_Type *)(&((CTBL_Type *)base)->DYN[cfgIdx]))->OA_MUX_CFG)
#define AUTANALOG_CTBX_COMP_STATUS(base)     (((CTBL_STA_Type *)(&((CTBL_Type *)base)->STA))->COMP_STAT)


/*******************************************************************************
*                AUTANALOG PTC
*******************************************************************************/

#define AUTANALOG_PTC_STA_CFG(base)              (((PTC_STA_Type*)  (&((PTC_Type*) base)->STA))->CFG)
#define AUTANALOG_PTC_STA_PP_CFG(base, cfgIdx)   (((PTC_STA_Type*)  (&((PTC_Type*) base)->STA))->PP_CFG[cfgIdx])
#define AUTANALOG_PTC_COMP_STAT(base)            (((PTC_STA_Type*)  (&((PTC_Type*) base)->STA))->COMP_STAT)
#define AUTANALOG_PTC_DYN_CFG(base, cfgIdx)      (((PTC_DYN_Type*)  (&((PTC_Type*) base)->DYN[cfgIdx]))->MUX_CFG)
#define AUTANALOG_PTC_PP_CFG(base, cfgIdx)       (((PTC_PP_Type*)   (&((PTC_Type*) base)->PP[cfgIdx]))->CFG)
#define AUTANALOG_PTC_PP_FRAME(base, cfgIdx)     (((PTC_PP_Type*)   (&((PTC_Type*) base)->PP[cfgIdx]))->FRAME)
#define AUTANALOG_PTC_PP_WINDOW(base, cfgIdx)    (((PTC_PP_Type*)   (&((PTC_Type*) base)->PP[cfgIdx]))->WINDOW)
#define AUTANALOG_PTC_PP_THRESHOLD(base, cfgIdx) (((PTC_PP_Type*)   (&((PTC_Type*) base)->PP[cfgIdx]))->THRESHOLD)
#define AUTANALOG_PTC_TRIM_CMP0(base)            (((PTC_TRIM_Type*) (&((PTC_Type*) base)->TRIM))->CMP0_OFFSET_TRIM)
#define AUTANALOG_PTC_TRIM_CMP1(base)            (((PTC_TRIM_Type*) (&((PTC_Type*) base)->TRIM))->CMP1_OFFSET_TRIM)


/*******************************************************************************
*                AUTANALOG DAC
*******************************************************************************/

#define AUTANALOG_DAC_CTRL(base)                    (((DAC_STA_Type *) (&((DAC_Type *)base)->STA))->CTRL)
#define AUTANALOG_DAC_SAMPLE_TIME(base)             (((DAC_STA_Type *) (&((DAC_Type *)base)->STA))->SAMPLE_TIME)
#define AUTANALOG_DAC_STEP_VAL(base, cfgIdx)        (((DAC_STA_Type *) (&((DAC_Type *)base)->STA))->STEP_VAL[cfgIdx])
#define AUTANALOG_DAC_DEGLITCH_TIME(base)           (((DAC_STA_Type *) (&((DAC_Type *)base)->STA))->DEGLITCH_TIME)
#define AUTANALOG_DAC_CHAN_CFG(base, cfgIdx)        (((DAC_STA_Type *) (&((DAC_Type *)base)->STA))->CHAN_CFG[cfgIdx])
#define AUTANALOG_DAC_FW_DAC_VAL(base)              (((DAC_STA_Type *) (&((DAC_Type *)base)->STA))->FW_DAC_VAL)
#define AUTANALOG_DAC_FW_DAC_VAL_NXT(base)          (((DAC_STA_Type *) (&((DAC_Type *)base)->STA))->FW_DAC_VAL_NXT)
#define AUTANALOG_DAC_CHAN_STATUS_CFG(base, cfgIdx) (((DAC_STA_Type *) (&((DAC_Type *)base)->STA))->CHAN_STATUS_CFG[cfgIdx])
#define AUTANALOG_DAC_RANGE_STATUS(base)            (((DAC_STA_Type *) (&((DAC_Type *)base)->STA))->RANGE_STATUS)
#define AUTANALOG_DAC_LUT(base, lutIdx)             (((DAC_Type *)(base))->SRAM[lutIdx])


/*******************************************************************************
*                AUTANALOG SAR
*******************************************************************************/

#define AUTANALOG_SAR_SEQ_HS_DATA(base, cfgIdx)       (((SAR_Type *)(base))->SEQ_HS_DATA[cfgIdx])
#define AUTANALOG_SAR_SEQ_LP_DATA(base, cfgIdx)       (((SAR_Type *)(base))->SEQ_LP_DATA[cfgIdx])
#define AUTANALOG_SAR_CTRL(base)                      (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->CTRL)
#define AUTANALOG_SAR_FIR_CFG(base, cfgIdx)           (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->FIR_CFG[cfgIdx])
#define AUTANALOG_SAR_TR_SAMPLE_TIME(base)            (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->TR_SAMPLE_TIME)
#define AUTANALOG_SAR_SAMPLE_TIME(base, cfgIdx)       (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->SAMPLE_TIME[cfgIdx])
#define AUTANALOG_SAR_GPIO_CHAN_CFG(base, cfgIdx)     (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->GPIO_CHAN_CFG[cfgIdx])
#define AUTANALOG_SAR_MUX_CHAN_CFG(base, cfgIdx)      (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->MUX_CHAN_CFG[cfgIdx])
#define AUTANALOG_SAR_STATUS_CFG(base, cfgIdx)        (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->STATUS_CFG[cfgIdx])
#define AUTANALOG_SAR_STATUS_RANGE_LOW(base, cfgIdx)  (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->STATUS_RANGE_LOW[cfgIdx])
#define AUTANALOG_SAR_STATUS_RANGE_HIGH(base, cfgIdx) (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->STATUS_RANGE_HIGH[cfgIdx])
#define AUTANALOG_SAR_GPIO_CHAN_RESULT(base, ch)      (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->GPIO_CHAN_RESULT[ch])
#define AUTANALOG_SAR_MUX_CHAN_RESULT(base, ch)       (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->MUX_CHAN_RESULT[ch])
#define AUTANALOG_SAR_FIR_RESULT(base, firIdx)        (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->FIR_RESULT[firIdx])
#define AUTANALOG_SAR_CHAN_RESULT_MASK(base)          (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->CHAN_RESULT_MASK)
#define AUTANALOG_SAR_FIR_RESULT_MASK(base)           (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->FIR_RESULT_MASK)
#define AUTANALOG_SAR_CHAN_RESULT_STATUS(base)        (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->CHAN_RESULT_UPDATED)
#define AUTANALOG_SAR_FIR_RESULT_STATUS(base)         (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->FIR_RESULT_UPDATED)
#define AUTANALOG_SAR_STATUS(base)                    (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->STATUS)
#define AUTANALOG_SAR_RANGE_STATUS(base)              (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->RANGE_STATUS)
#define AUTANALOG_SAR_CHAN_COEFF(base, cfgIdx)        (((SAR_STA_Type *) (&((SAR_Type *)base)->STA))->CHAN_COEFF[cfgIdx])
#define AUTANALOG_SAR_FIR0_COEF(base, cfgIdx)         (((SAR_FIR0_Type *) (&((SAR_Type *)base)->FIR0))[cfgIdx].COEF)
#define AUTANALOG_SAR_FIR0_TAP(base, cfgIdx)          (((SAR_FIR0_Type *) (&((SAR_Type *)base)->FIR0))[cfgIdx].TAP)
#define AUTANALOG_SAR_FIR1_COEF(base, cfgIdx)         (((SAR_FIR1_Type *) (&((SAR_Type *)base)->FIR1))[cfgIdx].COEF)
#define AUTANALOG_SAR_FIR1_TAP(base, cfgIdx)          (((SAR_FIR1_Type *) (&((SAR_Type *)base)->FIR1))[cfgIdx].TAP)


/*******************************************************************************
*                AUTANALOG MMIO
*******************************************************************************/

#define AUTANALOG_MMIO_TR_OUT(base, triggIdx)          (((LPPASS_MMIO_Type *)(base))->TR_OUT[triggIdx])
#define AUTANALOG_MMIO_INTR_CAUSE(base)                (((LPPASS_MMIO_Type *)(base))->INTR_CAUSE)
#define AUTANALOG_MMIO_INTR(base)                      (((LPPASS_MMIO_Type *)(base))->INTR)
#define AUTANALOG_MMIO_INTR_SET(base)                  (((LPPASS_MMIO_Type *)(base))->INTR_SET)
#define AUTANALOG_MMIO_INTR_MASK(base)                 (((LPPASS_MMIO_Type *)(base))->INTR_MASK)
#define AUTANALOG_MMIO_INTR_MASKED(base)               (((LPPASS_MMIO_Type *)(base))->INTR_MASKED)
#define AUTANALOG_MMIO_FIFO_INTR_CAUSE(base)           (((LPPASS_MMIO_Type *)(base))->FIFO_INTR_CAUSE)
#define AUTANALOG_MMIO_FIFO_INTR(base)                 (((LPPASS_MMIO_Type *)(base))->FIFO_INTR)
#define AUTANALOG_MMIO_FIFO_INTR_SET(base)             (((LPPASS_MMIO_Type *)(base))->FIFO_INTR_SET)
#define AUTANALOG_MMIO_FIFO_INTR_MASK(base)            (((LPPASS_MMIO_Type *)(base))->FIFO_INTR_MASK)
#define AUTANALOG_MMIO_FIFO_INTR_MASKED(base)          (((LPPASS_MMIO_Type *)(base))->FIFO_INTR_MASKED)
#define AUTANALOG_MMIO_FIFO_STA_CFG(base)              (((LPPASS_MMIO_STA_Type *)(&((LPPASS_MMIO_Type *)base)->STA))->CFG)
#define AUTANALOG_MMIO_FIFO_STA_MODE(base)             (((LPPASS_MMIO_STA_Type *)(&((LPPASS_MMIO_Type *)base)->STA))->MODE)
#define AUTANALOG_MMIO_FIFO_STA_MODE_STATUS(base)      (((LPPASS_MMIO_STA_Type *)(&((LPPASS_MMIO_Type *)base)->STA))->MODE_STATUS)
#define AUTANALOG_MMIO_FIFO_STA_LEVEL(base, cfgIdx)    (((LPPASS_MMIO_STA_Type *)(&((LPPASS_MMIO_Type *)base)->STA))->LEVEL[cfgIdx])
#define AUTANALOG_MMIO_FIFO_STA_USED(base, buffIdx)    (((LPPASS_MMIO_STA_Type *)(&((LPPASS_MMIO_Type *)base)->STA))->USED[buffIdx])
#define AUTANALOG_MMIO_FIFO_STA_RD_DATA(base, buffIdx) (((LPPASS_MMIO_STA_Type *)(&((LPPASS_MMIO_Type *)base)->STA))->RD_DATA[buffIdx])


/*******************************************************************************
*                TCPWM
*******************************************************************************/

#define TCPWM_CTRL_SET(base)                (((TCPWM_Type *)(base))->CTRL_SET)
#define TCPWM_CTRL_CLR(base)                (((TCPWM_Type *)(base))->CTRL_CLR)
#define TCPWM_CMD_START(base)               (((TCPWM_Type *)(base))->CMD_START)
#define TCPWM_CMD_RELOAD(base)              (((TCPWM_Type *)(base))->CMD_RELOAD)
#define TCPWM_CMD_STOP(base)                (((TCPWM_Type *)(base))->CMD_STOP)
#define TCPWM_CMD_CAPTURE(base)             (((TCPWM_Type *)(base))->CMD_CAPTURE)

#define TCPWM_CNT_CTRL(base, cntNum)         (((TCPWM_Type *)(base))->CNT[cntNum].CTRL)
#define TCPWM_CNT_CC(base, cntNum)           (((TCPWM_Type *)(base))->CNT[cntNum].CC)
#define TCPWM_CNT_CC_BUFF(base, cntNum)      (((TCPWM_Type *)(base))->CNT[cntNum].CC_BUFF)
#define TCPWM_CNT_COUNTER(base, cntNum)      (((TCPWM_Type *)(base))->CNT[cntNum].COUNTER)
#define TCPWM_CNT_PERIOD(base, cntNum)       (((TCPWM_Type *)(base))->CNT[cntNum].PERIOD)
#define TCPWM_CNT_PERIOD_BUFF(base, cntNum)  (((TCPWM_Type *)(base))->CNT[cntNum].PERIOD_BUFF)
#define TCPWM_CNT_STATUS(base, cntNum)       (((TCPWM_Type *)(base))->CNT[cntNum].STATUS)
#define TCPWM_CNT_INTR(base, cntNum)         (((TCPWM_Type *)(base))->CNT[cntNum].INTR)
#define TCPWM_CNT_INTR_SET(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].INTR_SET)
#define TCPWM_CNT_INTR_MASK(base, cntNum)    (((TCPWM_Type *)(base))->CNT[cntNum].INTR_MASK)
#define TCPWM_CNT_INTR_MASKED(base, cntNum)  (((TCPWM_Type *)(base))->CNT[cntNum].INTR_MASKED)
#define TCPWM_CNT_TR_CTRL0(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL0)
#define TCPWM_CNT_TR_CTRL1(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL1)
#define TCPWM_CNT_TR_CTRL2(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL2)

#define TCPWM_GRP_CC1_PRESENT_STATUS (TCPWM_GRP_NR0_CNT_GRP_CC1_PRESENT | TCPWM_GRP_NR1_CNT_GRP_CC1_PRESENT << 1)
#define TCPWM_GRP_AMC_PRESENT_STATUS (TCPWM_GRP_NR0_CNT_GRP_AMC_PRESENT | TCPWM_GRP_NR1_CNT_GRP_AMC_PRESENT << 1)
#define TCPWM_GRP_SMC_PRESENT_STATUS (TCPWM_GRP_NR0_CNT_GRP_SMC_PRESENT | TCPWM_GRP_NR1_CNT_GRP_SMC_PRESENT << 1)

#define TCPWM_GRP_CC1(base, grp) ((bool)((TCPWM_GRP_CC1_PRESENT_STATUS >> (grp)) & 0x01U))
#define TCPWM_GRP_AMC(base, grp) ((bool)((TCPWM_GRP_AMC_PRESENT_STATUS >> (grp)) & 0x01U))
#define TCPWM_GRP_SMC(base, grp) ((bool)((TCPWM_GRP_SMC_PRESENT_STATUS >> (grp)) & 0x01U))

#define TCPWM_GRP_CNT_GET_GRP(cntNum)        ((cntNum )/ 256U)

#define TCPWM_GRP_CNT_CTRL(base, grp, cntNum)           (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].CTRL)
#define TCPWM_GRP_CNT_STATUS(base, grp, cntNum)         (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].STATUS)
#define TCPWM_GRP_CNT_COUNTER(base, grp, cntNum)        (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].COUNTER)
#define TCPWM_GRP_CNT_CC0(base, grp, cntNum)            (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].CC0)
#define TCPWM_GRP_CNT_CC0_BUFF(base, grp, cntNum)       (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].CC0_BUFF)
#define TCPWM_GRP_CNT_CC1(base, grp, cntNum)            (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].CC1)
#define TCPWM_GRP_CNT_CC1_BUFF(base, grp, cntNum)       (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].CC1_BUFF)
#define TCPWM_GRP_CNT_PERIOD(base, grp, cntNum)         (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].PERIOD)
#define TCPWM_GRP_CNT_PERIOD_BUFF(base, grp, cntNum)    (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].PERIOD_BUFF)
#define TCPWM_GRP_CNT_LINE_SEL(base, grp, cntNum)       (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].LINE_SEL)
#define TCPWM_GRP_CNT_LINE_SEL_BUFF(base, grp, cntNum)  (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].LINE_SEL_BUFF)
#define TCPWM_GRP_CNT_DT(base, grp, cntNum)             (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].DT)
#define TCPWM_GRP_CNT_TR_CMD(base, grp, cntNum)         (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].TR_CMD)
#define TCPWM_GRP_CNT_TR_IN_SEL0(base, grp, cntNum)     (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].TR_IN_SEL0)
#define TCPWM_GRP_CNT_TR_IN_SEL1(base, grp, cntNum)     (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].TR_IN_SEL1)
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL(base, grp, cntNum) (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].TR_IN_EDGE_SEL)
#define TCPWM_GRP_CNT_TR_PWM_CTRL(base, grp, cntNum)    (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].TR_PWM_CTRL)
#define TCPWM_GRP_CNT_TR_OUT_SEL(base, grp, cntNum)     (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].TR_OUT_SEL)
#define TCPWM_GRP_CNT_INTR(base, grp, cntNum)           (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].INTR)
#define TCPWM_GRP_CNT_INTR_SET(base, grp, cntNum)       (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].INTR_SET)
#define TCPWM_GRP_CNT_INTR_MASK(base, grp, cntNum)      (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].INTR_MASK)
#define TCPWM_GRP_CNT_INTR_MASKED(base, grp, cntNum)    (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % 256U)].INTR_MASKED)

#if (CY_IP_MXTCPWM_VERSION >= 2U)
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_CC0_Pos TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC0_Pos
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_CC0_Msk TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC0_Msk
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_CC1_Pos TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC1_Pos
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_CC1_Msk TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC1_Msk
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_PERIOD_Pos TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_PERIOD_Pos
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_PERIOD_Msk TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_PERIOD_Msk
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_LINE_SEL_Pos TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_LINE_SEL_Pos
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_LINE_SEL_Msk TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_LINE_SEL_Msk
#define TCPWM_GRP_CNT_V2_CTRL_CC0_MATCH_UP_EN_Pos TCPWM_GRP_CNT_CTRL_CC0_MATCH_UP_EN_Pos
#define TCPWM_GRP_CNT_V2_CTRL_CC0_MATCH_UP_EN_Msk TCPWM_GRP_CNT_CTRL_CC0_MATCH_UP_EN_Msk
#define TCPWM_GRP_CNT_V2_CTRL_CC0_MATCH_DOWN_EN_Pos TCPWM_GRP_CNT_CTRL_CC0_MATCH_DOWN_EN_Pos
#define TCPWM_GRP_CNT_V2_CTRL_CC0_MATCH_DOWN_EN_Msk TCPWM_GRP_CNT_CTRL_CC0_MATCH_DOWN_EN_Msk
#define TCPWM_GRP_CNT_V2_CTRL_CC1_MATCH_UP_EN_Pos TCPWM_GRP_CNT_CTRL_CC1_MATCH_UP_EN_Pos
#define TCPWM_GRP_CNT_V2_CTRL_CC1_MATCH_UP_EN_Msk TCPWM_GRP_CNT_CTRL_CC1_MATCH_UP_EN_Msk
#define TCPWM_GRP_CNT_V2_CTRL_CC1_MATCH_DOWN_EN_Pos TCPWM_GRP_CNT_CTRL_CC1_MATCH_DOWN_EN_Pos
#define TCPWM_GRP_CNT_V2_CTRL_CC1_MATCH_DOWN_EN_Msk TCPWM_GRP_CNT_CTRL_CC1_MATCH_DOWN_EN_Msk
#define TCPWM_GRP_CNT_V2_CTRL_PWM_IMM_KILL_Pos  TCPWM_GRP_CNT_CTRL_PWM_IMM_KILL_Pos
#define TCPWM_GRP_CNT_V2_CTRL_PWM_IMM_KILL_Msk  TCPWM_GRP_CNT_CTRL_PWM_IMM_KILL_Msk
#define TCPWM_GRP_CNT_V2_CTRL_PWM_STOP_ON_KILL_Pos TCPWM_GRP_CNT_CTRL_PWM_STOP_ON_KILL_Pos
#define TCPWM_GRP_CNT_V2_CTRL_PWM_STOP_ON_KILL_Msk TCPWM_GRP_CNT_CTRL_PWM_STOP_ON_KILL_Msk
#define TCPWM_GRP_CNT_V2_CTRL_PWM_SYNC_KILL_Pos TCPWM_GRP_CNT_CTRL_PWM_SYNC_KILL_Pos
#define TCPWM_GRP_CNT_V2_CTRL_PWM_SYNC_KILL_Msk TCPWM_GRP_CNT_CTRL_PWM_SYNC_KILL_Msk
#define TCPWM_GRP_CNT_V2_CTRL_PWM_DISABLE_MODE_Pos TCPWM_GRP_CNT_CTRL_PWM_DISABLE_MODE_Pos
#define TCPWM_GRP_CNT_V2_CTRL_PWM_DISABLE_MODE_Msk TCPWM_GRP_CNT_CTRL_PWM_DISABLE_MODE_Msk
#define TCPWM_GRP_CNT_V2_CTRL_UP_DOWN_MODE_Pos  TCPWM_GRP_CNT_CTRL_UP_DOWN_MODE_Pos
#define TCPWM_GRP_CNT_V2_CTRL_UP_DOWN_MODE_Msk  TCPWM_GRP_CNT_CTRL_UP_DOWN_MODE_Msk
#define TCPWM_GRP_CNT_V2_CTRL_ONE_SHOT_Pos      TCPWM_GRP_CNT_CTRL_ONE_SHOT_Pos
#define TCPWM_GRP_CNT_V2_CTRL_ONE_SHOT_Msk      TCPWM_GRP_CNT_CTRL_ONE_SHOT_Msk
#define TCPWM_GRP_CNT_V2_CTRL_QUAD_ENCODING_MODE_Pos TCPWM_GRP_CNT_CTRL_QUAD_ENCODING_MODE_Pos
#define TCPWM_GRP_CNT_V2_CTRL_QUAD_ENCODING_MODE_Msk TCPWM_GRP_CNT_CTRL_QUAD_ENCODING_MODE_Msk
#define TCPWM_GRP_CNT_V2_CTRL_MODE_Pos          TCPWM_GRP_CNT_CTRL_MODE_Pos
#define TCPWM_GRP_CNT_V2_CTRL_MODE_Msk          TCPWM_GRP_CNT_CTRL_MODE_Msk
#define TCPWM_GRP_CNT_V2_CTRL_DBG_FREEZE_EN_Pos TCPWM_GRP_CNT_CTRL_DBG_FREEZE_EN_Pos
#define TCPWM_GRP_CNT_V2_CTRL_DBG_FREEZE_EN_Msk TCPWM_GRP_CNT_CTRL_DBG_FREEZE_EN_Msk
#define TCPWM_GRP_CNT_V2_CTRL_ENABLED_Pos       TCPWM_GRP_CNT_CTRL_ENABLED_Pos
#define TCPWM_GRP_CNT_V2_CTRL_ENABLED_Msk       TCPWM_GRP_CNT_CTRL_ENABLED_Msk
/* TCPWM_GRP_CNT.STATUS */
#define TCPWM_GRP_CNT_V2_STATUS_DOWN_Pos        TCPWM_GRP_CNT_STATUS_DOWN_Pos
#define TCPWM_GRP_CNT_V2_STATUS_DOWN_Msk        TCPWM_GRP_CNT_STATUS_DOWN_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_CAPTURE0_Pos TCPWM_GRP_CNT_STATUS_TR_CAPTURE0_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_CAPTURE0_Msk TCPWM_GRP_CNT_STATUS_TR_CAPTURE0_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_COUNT_Pos    TCPWM_GRP_CNT_STATUS_TR_COUNT_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_COUNT_Msk    TCPWM_GRP_CNT_STATUS_TR_COUNT_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_RELOAD_Pos   TCPWM_GRP_CNT_STATUS_TR_RELOAD_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_RELOAD_Msk   TCPWM_GRP_CNT_STATUS_TR_RELOAD_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_STOP_Pos     TCPWM_GRP_CNT_STATUS_TR_STOP_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_STOP_Msk     TCPWM_GRP_CNT_STATUS_TR_STOP_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_START_Pos    TCPWM_GRP_CNT_STATUS_TR_START_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_START_Msk    TCPWM_GRP_CNT_STATUS_TR_START_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_CAPTURE1_Pos TCPWM_GRP_CNT_STATUS_TR_CAPTURE1_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_CAPTURE1_Msk TCPWM_GRP_CNT_STATUS_TR_CAPTURE1_Msk
#define TCPWM_GRP_CNT_V2_STATUS_LINE_OUT_Pos    TCPWM_GRP_CNT_STATUS_LINE_OUT_Pos
#define TCPWM_GRP_CNT_V2_STATUS_LINE_OUT_Msk    TCPWM_GRP_CNT_STATUS_LINE_OUT_Msk
#define TCPWM_GRP_CNT_V2_STATUS_LINE_COMPL_OUT_Pos TCPWM_GRP_CNT_STATUS_LINE_COMPL_OUT_Pos
#define TCPWM_GRP_CNT_V2_STATUS_LINE_COMPL_OUT_Msk TCPWM_GRP_CNT_STATUS_LINE_COMPL_OUT_Msk
#define TCPWM_GRP_CNT_V2_STATUS_RUNNING_Pos     TCPWM_GRP_CNT_STATUS_RUNNING_Pos
#define TCPWM_GRP_CNT_V2_STATUS_RUNNING_Msk     TCPWM_GRP_CNT_STATUS_RUNNING_Msk
#define TCPWM_GRP_CNT_V2_STATUS_DT_CNT_L_Pos    TCPWM_GRP_CNT_STATUS_DT_CNT_L_Pos
#define TCPWM_GRP_CNT_V2_STATUS_DT_CNT_L_Msk    TCPWM_GRP_CNT_STATUS_DT_CNT_L_Msk
#define TCPWM_GRP_CNT_V2_STATUS_DT_CNT_H_Pos    TCPWM_GRP_CNT_STATUS_DT_CNT_H_Pos
#define TCPWM_GRP_CNT_V2_STATUS_DT_CNT_H_Msk    TCPWM_GRP_CNT_STATUS_DT_CNT_H_Msk
/* TCPWM_GRP_CNT.COUNTER */
#define TCPWM_GRP_CNT_V2_COUNTER_COUNTER_Pos    TCPWM_GRP_CNT_COUNTER_COUNTER_Pos
#define TCPWM_GRP_CNT_V2_COUNTER_COUNTER_Msk    TCPWM_GRP_CNT_COUNTER_COUNTER_Msk
/* TCPWM_GRP_CNT.CC0 */
#define TCPWM_GRP_CNT_V2_CC0_CC_Pos             TCPWM_GRP_CNT_CC0_CC_Pos
#define TCPWM_GRP_CNT_V2_CC0_CC_Msk             TCPWM_GRP_CNT_CC0_CC_Msk
/* TCPWM_GRP_CNT.CC0_BUFF */
#define TCPWM_GRP_CNT_V2_CC0_BUFF_CC_Pos        TCPWM_GRP_CNT_CC0_BUFF_CC_Pos
#define TCPWM_GRP_CNT_V2_CC0_BUFF_CC_Msk        TCPWM_GRP_CNT_CC0_BUFF_CC_Msk
/* TCPWM_GRP_CNT.CC1 */
#define TCPWM_GRP_CNT_V2_CC1_CC_Pos             TCPWM_GRP_CNT_CC1_CC_Pos
#define TCPWM_GRP_CNT_V2_CC1_CC_Msk             TCPWM_GRP_CNT_CC1_CC_Msk
/* TCPWM_GRP_CNT.CC1_BUFF */
#define TCPWM_GRP_CNT_V2_CC1_BUFF_CC_Pos        TCPWM_GRP_CNT_CC1_BUFF_CC_Pos
#define TCPWM_GRP_CNT_V2_CC1_BUFF_CC_Msk        TCPWM_GRP_CNT_CC1_BUFF_CC_Msk
/* TCPWM_GRP_CNT.PERIOD */
#define TCPWM_GRP_CNT_V2_PERIOD_PERIOD_Pos      TCPWM_GRP_CNT_PERIOD_PERIOD_Pos
#define TCPWM_GRP_CNT_V2_PERIOD_PERIOD_Msk      TCPWM_GRP_CNT_PERIOD_PERIOD_Msk
/* TCPWM_GRP_CNT.PERIOD_BUFF */
#define TCPWM_GRP_CNT_V2_PERIOD_BUFF_PERIOD_Pos TCPWM_GRP_CNT_PERIOD_BUFF_PERIOD_Pos
#define TCPWM_GRP_CNT_V2_PERIOD_BUFF_PERIOD_Msk TCPWM_GRP_CNT_PERIOD_BUFF_PERIOD_Msk
/* TCPWM_GRP_CNT.LINE_SEL */
#define TCPWM_GRP_CNT_V2_LINE_SEL_OUT_SEL_Pos   TCPWM_GRP_CNT_LINE_SEL_OUT_SEL_Pos
#define TCPWM_GRP_CNT_V2_LINE_SEL_OUT_SEL_Msk   TCPWM_GRP_CNT_LINE_SEL_OUT_SEL_Msk
#define TCPWM_GRP_CNT_V2_LINE_SEL_COMPL_OUT_SEL_Pos TCPWM_GRP_CNT_LINE_SEL_COMPL_OUT_SEL_Pos
#define TCPWM_GRP_CNT_V2_LINE_SEL_COMPL_OUT_SEL_Msk TCPWM_GRP_CNT_LINE_SEL_COMPL_OUT_SEL_Msk
/* TCPWM_GRP_CNT.LINE_SEL_BUFF */
#define TCPWM_GRP_CNT_V2_LINE_SEL_BUFF_OUT_SEL_Pos TCPWM_GRP_CNT_LINE_SEL_BUFF_OUT_SEL_Pos
#define TCPWM_GRP_CNT_V2_LINE_SEL_BUFF_OUT_SEL_Msk TCPWM_GRP_CNT_LINE_SEL_BUFF_OUT_SEL_Msk
#define TCPWM_GRP_CNT_V2_LINE_SEL_BUFF_COMPL_OUT_SEL_Pos TCPWM_GRP_CNT_LINE_SEL_BUFF_COMPL_OUT_SEL_Pos
#define TCPWM_GRP_CNT_V2_LINE_SEL_BUFF_COMPL_OUT_SEL_Msk TCPWM_GRP_CNT_LINE_SEL_BUFF_COMPL_OUT_SEL_Msk
/* TCPWM_GRP_CNT.DT */
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_L_Pos   TCPWM_GRP_CNT_DT_DT_LINE_OUT_L_Pos
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_L_Msk   TCPWM_GRP_CNT_DT_DT_LINE_OUT_L_Msk
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_H_Pos   TCPWM_GRP_CNT_DT_DT_LINE_OUT_H_Pos
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_H_Msk   TCPWM_GRP_CNT_DT_DT_LINE_OUT_H_Msk
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_COMPL_OUT_Pos TCPWM_GRP_CNT_DT_DT_LINE_COMPL_OUT_Pos
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_COMPL_OUT_Msk TCPWM_GRP_CNT_DT_DT_LINE_COMPL_OUT_Msk
/* TCPWM_GRP_CNT.TR_CMD */
#define TCPWM_GRP_CNT_V2_TR_CMD_CAPTURE0_Pos    TCPWM_GRP_CNT_TR_CMD_CAPTURE0_Pos
#define TCPWM_GRP_CNT_V2_TR_CMD_CAPTURE0_Msk    TCPWM_GRP_CNT_TR_CMD_CAPTURE0_Msk
#define TCPWM_GRP_CNT_V2_TR_CMD_RELOAD_Pos      TCPWM_GRP_CNT_TR_CMD_RELOAD_Pos
#define TCPWM_GRP_CNT_V2_TR_CMD_RELOAD_Msk      TCPWM_GRP_CNT_TR_CMD_RELOAD_Msk
#define TCPWM_GRP_CNT_V2_TR_CMD_STOP_Pos        TCPWM_GRP_CNT_TR_CMD_STOP_Pos
#define TCPWM_GRP_CNT_V2_TR_CMD_STOP_Msk        TCPWM_GRP_CNT_TR_CMD_STOP_Msk
#define TCPWM_GRP_CNT_V2_TR_CMD_START_Pos       TCPWM_GRP_CNT_TR_CMD_START_Pos
#define TCPWM_GRP_CNT_V2_TR_CMD_START_Msk       TCPWM_GRP_CNT_TR_CMD_START_Msk
#define TCPWM_GRP_CNT_V2_TR_CMD_CAPTURE1_Pos    TCPWM_GRP_CNT_TR_CMD_CAPTURE1_Pos
#define TCPWM_GRP_CNT_V2_TR_CMD_CAPTURE1_Msk    TCPWM_GRP_CNT_TR_CMD_CAPTURE1_Msk
/* TCPWM_GRP_CNT.TR_IN_SEL0 */
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_CAPTURE0_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL0_CAPTURE0_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_CAPTURE0_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL0_CAPTURE0_SEL_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_COUNT_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL0_COUNT_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_COUNT_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL0_COUNT_SEL_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_RELOAD_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL0_RELOAD_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_RELOAD_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL0_RELOAD_SEL_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_STOP_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL0_STOP_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_STOP_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL0_STOP_SEL_Msk
/* TCPWM_GRP_CNT.TR_IN_SEL1 */
#define TCPWM_GRP_CNT_V2_TR_IN_SEL1_START_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL1_START_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL1_START_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL1_START_SEL_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_SEL1_CAPTURE1_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL1_CAPTURE1_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL1_CAPTURE1_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL1_CAPTURE1_SEL_Msk
/* TCPWM_GRP_CNT.TR_IN_EDGE_SEL */
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_CAPTURE0_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE0_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_CAPTURE0_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE0_EDGE_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_COUNT_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_COUNT_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_COUNT_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_COUNT_EDGE_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_RELOAD_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_RELOAD_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_RELOAD_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_RELOAD_EDGE_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_STOP_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_STOP_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_STOP_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_STOP_EDGE_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_START_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_START_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_START_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_START_EDGE_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_CAPTURE1_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE1_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_CAPTURE1_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE1_EDGE_Msk
/* TCPWM_GRP_CNT.TR_PWM_CTRL */
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_CC0_MATCH_MODE_Pos TCPWM_GRP_CNT_TR_PWM_CTRL_CC0_MATCH_MODE_Pos
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_CC0_MATCH_MODE_Msk TCPWM_GRP_CNT_TR_PWM_CTRL_CC0_MATCH_MODE_Msk
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_OVERFLOW_MODE_Pos TCPWM_GRP_CNT_TR_PWM_CTRL_OVERFLOW_MODE_Pos
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_OVERFLOW_MODE_Msk TCPWM_GRP_CNT_TR_PWM_CTRL_OVERFLOW_MODE_Msk
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_UNDERFLOW_MODE_Pos TCPWM_GRP_CNT_TR_PWM_CTRL_UNDERFLOW_MODE_Pos
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_UNDERFLOW_MODE_Msk TCPWM_GRP_CNT_TR_PWM_CTRL_UNDERFLOW_MODE_Msk
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_CC1_MATCH_MODE_Pos TCPWM_GRP_CNT_TR_PWM_CTRL_CC1_MATCH_MODE_Pos
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_CC1_MATCH_MODE_Msk TCPWM_GRP_CNT_TR_PWM_CTRL_CC1_MATCH_MODE_Msk
/* TCPWM_GRP_CNT.TR_OUT_SEL */
#define TCPWM_GRP_CNT_V2_TR_OUT_SEL_OUT0_Pos    TCPWM_GRP_CNT_TR_OUT_SEL_OUT0_Pos
#define TCPWM_GRP_CNT_V2_TR_OUT_SEL_OUT0_Msk    TCPWM_GRP_CNT_TR_OUT_SEL_OUT0_Msk
#define TCPWM_GRP_CNT_V2_TR_OUT_SEL_OUT1_Pos    TCPWM_GRP_CNT_TR_OUT_SEL_OUT1_Pos
#define TCPWM_GRP_CNT_V2_TR_OUT_SEL_OUT1_Msk    TCPWM_GRP_CNT_TR_OUT_SEL_OUT1_Msk
/* TCPWM_GRP_CNT.INTR */
#define TCPWM_GRP_CNT_V2_INTR_TC_Pos            TCPWM_GRP_CNT_INTR_TC_Pos
#define TCPWM_GRP_CNT_V2_INTR_TC_Msk            TCPWM_GRP_CNT_INTR_TC_Msk
#define TCPWM_GRP_CNT_V2_INTR_CC0_MATCH_Pos     TCPWM_GRP_CNT_INTR_CC0_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_CC0_MATCH_Msk     TCPWM_GRP_CNT_INTR_CC0_MATCH_Msk
#define TCPWM_GRP_CNT_V2_INTR_CC1_MATCH_Pos     TCPWM_GRP_CNT_INTR_CC1_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_CC1_MATCH_Msk     TCPWM_GRP_CNT_INTR_CC1_MATCH_Msk
/* TCPWM_GRP_CNT.INTR_SET */
#define TCPWM_GRP_CNT_V2_INTR_SET_TC_Pos        TCPWM_GRP_CNT_INTR_SET_TC_Pos
#define TCPWM_GRP_CNT_V2_INTR_SET_TC_Msk        TCPWM_GRP_CNT_INTR_SET_TC_Msk
#define TCPWM_GRP_CNT_V2_INTR_SET_CC0_MATCH_Pos TCPWM_GRP_CNT_INTR_SET_CC0_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_SET_CC0_MATCH_Msk TCPWM_GRP_CNT_INTR_SET_CC0_MATCH_Msk
#define TCPWM_GRP_CNT_V2_INTR_SET_CC1_MATCH_Pos TCPWM_GRP_CNT_INTR_SET_CC1_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_SET_CC1_MATCH_Msk TCPWM_GRP_CNT_INTR_SET_CC1_MATCH_Msk
/* TCPWM_GRP_CNT.INTR_MASK */
#define TCPWM_GRP_CNT_V2_INTR_MASK_TC_Pos       TCPWM_GRP_CNT_INTR_MASK_TC_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASK_TC_Msk       TCPWM_GRP_CNT_INTR_MASK_TC_Msk
#define TCPWM_GRP_CNT_V2_INTR_MASK_CC0_MATCH_Pos TCPWM_GRP_CNT_INTR_MASK_CC0_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASK_CC0_MATCH_Msk TCPWM_GRP_CNT_INTR_MASK_CC0_MATCH_Msk
#define TCPWM_GRP_CNT_V2_INTR_MASK_CC1_MATCH_Pos TCPWM_GRP_CNT_INTR_MASK_CC1_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASK_CC1_MATCH_Msk TCPWM_GRP_CNT_INTR_MASK_CC1_MATCH_Msk
/* TCPWM_GRP_CNT.INTR_MASKED */
#define TCPWM_GRP_CNT_V2_INTR_MASKED_TC_Pos     TCPWM_GRP_CNT_INTR_MASKED_TC_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASKED_TC_Msk     TCPWM_GRP_CNT_INTR_MASKED_TC_Msk
#define TCPWM_GRP_CNT_V2_INTR_MASKED_CC0_MATCH_Pos TCPWM_GRP_CNT_INTR_MASKED_CC0_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASKED_CC0_MATCH_Msk TCPWM_GRP_CNT_INTR_MASKED_CC0_MATCH_Msk
#define TCPWM_GRP_CNT_V2_INTR_MASKED_CC1_MATCH_Pos TCPWM_GRP_CNT_INTR_MASKED_CC1_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASKED_CC1_MATCH_Msk TCPWM_GRP_CNT_INTR_MASKED_CC1_MATCH_Msk

/* For backward compatibility, we set TCPWM_CNT_STATUS_RUNNING_Pos with TCPWM_GRP_CNT_V2_STATUS_RUNNING
we need to define this for version 2 only. */
#define TCPWM_CNT_STATUS_RUNNING_Pos 31UL
#endif

/*******************************************************************************
*               TDM
*******************************************************************************/

#define TDM_STRUCT_Type                                TDM_TDM_STRUCT_Type
#define TDM_TX_STRUCT_Type                            TDM_TDM_STRUCT_TDM_TX_STRUCT_Type
#define TDM_RX_STRUCT_Type                            TDM_TDM_STRUCT_TDM_RX_STRUCT_Type
#define TDM_STRUCT0                                 TDM0_TDM_STRUCT0
#define TDM_STRUCT1                                 TDM0_TDM_STRUCT1
#define TDM_STRUCT0_TX                                TDM0_TDM_STRUCT0_TDM_TX_STRUCT
#define TDM_STRUCT1_TX                                TDM0_TDM_STRUCT1_TDM_TX_STRUCT
#define TDM_STRUCT0_RX                                TDM0_TDM_STRUCT0_TDM_RX_STRUCT
#define TDM_STRUCT1_RX                                TDM0_TDM_STRUCT1_TDM_RX_STRUCT
#define TDM_STRUCT_TX_CTL(base)                     (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_CTL)
#define TDM_STRUCT_TX_IF_CTL(base)                     (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_IF_CTL)
#define TDM_STRUCT_TX_CH_CTL(base)                     (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_CH_CTL)
#define TDM_STRUCT_TX_TEST_CTL(base)                 (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_TEST_CTL)
#define TDM_STRUCT_TX_ROUTE_CTL(base)                 (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_ROUTE_CTL)
#define TDM_STRUCT_TX_FIFO_CTL(base)                 (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_FIFO_CTL)
#define TDM_STRUCT_TX_FIFO_STATUS(base)             (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_FIFO_STATUS)
#define TDM_STRUCT_TX_FIFO_WR(base)                 (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_FIFO_WR)
#define TDM_STRUCT_TX_INTR_TX(base)                 (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->INTR_TX)
#define TDM_STRUCT_TX_INTR_TX_SET(base)             (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->INTR_TX_SET)
#define TDM_STRUCT_TX_INTR_TX_MASK(base)             (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->INTR_TX_MASK)
#define TDM_STRUCT_TX_INTR_TX_MASKED(base)             (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->INTR_TX_MASKED)

#define TDM_STRUCT_RX_CTL(base)                     (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_CTL)
#define TDM_STRUCT_RX_IF_CTL(base)                     (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_IF_CTL)
#define TDM_STRUCT_RX_CH_CTL(base)                     (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_CH_CTL)
#define TDM_STRUCT_RX_TEST_CTL(base)                 (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_TEST_CTL)
#define TDM_STRUCT_RX_ROUTE_CTL(base)                 (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_ROUTE_CTL)
#define TDM_STRUCT_RX_FIFO_CTL(base)                 (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_FIFO_CTL)
#define TDM_STRUCT_RX_FIFO_STATUS(base)             (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_FIFO_STATUS)
#define TDM_STRUCT_RX_FIFO_RD(base)                 (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_FIFO_RD)
#define TDM_STRUCT_RX_FIFO_RD_SILENT(base)             (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_FIFO_RD_SILENT)
#define TDM_STRUCT_RX_INTR_RX(base)                 (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->INTR_RX)
#define TDM_STRUCT_RX_INTR_RX_SET(base)             (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->INTR_RX_SET)
#define TDM_STRUCT_RX_INTR_RX_MASK(base)             (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->INTR_RX_MASK)
#define TDM_STRUCT_RX_INTR_RX_MASKED(base)             (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->INTR_RX_MASKED)


/*******************************************************************************
*                PDM
*******************************************************************************/

#define PDM_PCM_CTL(base)                               (((PDM_Type*)(base))->CTL)
#define PDM_PCM_CTL_CLR(base)                           (((PDM_Type*)(base))->CTL_CLR)
#define PDM_PCM_CTL_SET(base)                           (((PDM_Type*)(base))->CTL_SET)
#define PDM_PCM_CLOCK_CTL(base)                           (((PDM_Type*)(base))->CLOCK_CTL)
#define PDM_PCM_ROUTE_CTL(base)                           (((PDM_Type*)(base))->ROUTE_CTL)
#define PDM_PCM_TEST_CTL(base)                           (((PDM_Type*)(base))->TEST_CTL)
#define PDM_PCM_FIR0_COEFF0(base)                       (((PDM_Type*)(base))->FIR0_COEFF0)
#define PDM_PCM_FIR0_COEFF1(base)                       (((PDM_Type*)(base))->FIR0_COEFF1)
#define PDM_PCM_FIR0_COEFF2(base)                       (((PDM_Type*)(base))->FIR0_COEFF2)
#define PDM_PCM_FIR0_COEFF3(base)                       (((PDM_Type*)(base))->FIR0_COEFF3)
#define PDM_PCM_FIR0_COEFF4(base)                       (((PDM_Type*)(base))->FIR0_COEFF4)
#define PDM_PCM_FIR0_COEFF5(base)                       (((PDM_Type*)(base))->FIR0_COEFF5)
#define PDM_PCM_FIR0_COEFF6(base)                       (((PDM_Type*)(base))->FIR0_COEFF6)
#define PDM_PCM_FIR0_COEFF7(base)                       (((PDM_Type*)(base))->FIR0_COEFF7)

#define PDM_PCM_FIR1_COEFF0(base)                       (((PDM_Type*)(base))->FIR1_COEFF0)
#define PDM_PCM_FIR1_COEFF1(base)                       (((PDM_Type*)(base))->FIR1_COEFF1)
#define PDM_PCM_FIR1_COEFF2(base)                       (((PDM_Type*)(base))->FIR1_COEFF2)
#define PDM_PCM_FIR1_COEFF3(base)                       (((PDM_Type*)(base))->FIR1_COEFF3)
#define PDM_PCM_FIR1_COEFF4(base)                       (((PDM_Type*)(base))->FIR1_COEFF4)
#define PDM_PCM_FIR1_COEFF5(base)                       (((PDM_Type*)(base))->FIR1_COEFF5)
#define PDM_PCM_FIR1_COEFF6(base)                       (((PDM_Type*)(base))->FIR1_COEFF6)
#define PDM_PCM_FIR1_COEFF7(base)                       (((PDM_Type*)(base))->FIR1_COEFF7)
#define PDM_PCM_FIR1_COEFF8(base)                       (((PDM_Type*)(base))->FIR1_COEFF8)
#define PDM_PCM_FIR1_COEFF9(base)                       (((PDM_Type*)(base))->FIR1_COEFF9)
#define PDM_PCM_FIR1_COEFF10(base)                       (((PDM_Type*)(base))->FIR1_COEFF10)
#define PDM_PCM_FIR1_COEFF11(base)                       (((PDM_Type*)(base))->FIR1_COEFF11)
#define PDM_PCM_FIR1_COEFF12(base)                       (((PDM_Type*)(base))->FIR1_COEFF12)
#define PDM_PCM_FIR1_COEFF13(base)                       (((PDM_Type*)(base))->FIR1_COEFF13)


#define PDM_PCM_CH_CTL(base, chnum)                   (((PDM_Type*)(base))->CH[chnum].CTL)
#define PDM_PCM_CH_IF_CTL(base, chnum)                   (((PDM_Type*)(base))->CH[chnum].IF_CTL)
#define PDM_PCM_CH_CIC_CTL(base, chnum)               (((PDM_Type*)(base))->CH[chnum].CIC_CTL)
#define PDM_PCM_CH_FIR0_CTL(base, chnum)              (((PDM_Type*)(base))->CH[chnum].FIR0_CTL)
#define PDM_PCM_CH_FIR1_CTL(base, chnum)              (((PDM_Type*)(base))->CH[chnum].FIR1_CTL)
#define PDM_PCM_CH_DC_BLOCK_CTL(base, chnum)          (((PDM_Type*)(base))->CH[chnum].DC_BLOCK_CTL)
#define PDM_PCM_INTR_RX_MASK(base, chnum)             (((PDM_Type*)(base))->CH[chnum].INTR_RX_MASK)
#define PDM_PCM_INTR_RX_MASKED(base, chnum)           (((PDM_Type*)(base))->CH[chnum].INTR_RX_MASKED)
#define PDM_PCM_INTR_RX(base, chnum)                  (((PDM_Type*)(base))->CH[chnum].INTR_RX)
#define PDM_PCM_INTR_RX_SET(base, chnum)              (((PDM_Type*)(base))->CH[chnum].INTR_RX_SET)
#define PDM_PCM_RX_FIFO_STATUS(base, chnum)              (((PDM_Type*)(base))->CH[chnum].RX_FIFO_STATUS)
#define PDM_PCM_RX_FIFO_CTL(base, chnum)                 (((PDM_Type*)(base))->CH[chnum].RX_FIFO_CTL)
#define PDM_PCM_RX_FIFO_RD(base, chnum)                  (((PDM_Type*)(base))->CH[chnum].RX_FIFO_RD)
#define PDM_PCM_RX_FIFO_RD_SILENT(base, chnum)           (((PDM_Type*)(base))->CH[chnum].RX_FIFO_RD_SILENT)


/*******************************************************************************
*                BACKUP
*******************************************************************************/

#define BACKUP_RESET                        (((RTC_Type *) RTC)->RESET)

#define BACKUP_RESET_RESET_Msk                 RTC_RESET_RESET_Msk
#define BACKUP_INTR_CENTURY_Msk                RTC_INTR_CENTURY_Msk
#define BACKUP_INTR_ALARM1_Msk                 RTC_INTR_ALARM1_Msk
#define BACKUP_INTR_ALARM2_Msk                 RTC_INTR_ALARM2_Msk
#define BACKUP_RTC_TIME_CTRL_12HR_Msk          RTC_RTC_TIME_CTRL_12HR_Msk
#define BACKUP_RTC_TIME_CTRL_12HR_Pos          RTC_RTC_TIME_CTRL_12HR_Pos
#define BACKUP_STATUS_RTC_BUSY_Msk             RTC_STATUS_RTC_BUSY_Msk
#define BACKUP_STATUS_RTC_BUSY_Pos            RTC_STATUS_RTC_BUSY_Pos
#define BACKUP_RTC_RW_WRITE_Msk                RTC_RTC_RW_WRITE_Msk
#define BACKUP_RTC_RW_WRITE_Pos                RTC_RTC_RW_WRITE_Pos
#define BACKUP_RTC_RW_READ_Msk                 RTC_RTC_RW_READ_Msk
#define BACKUP_RTC_RW_READ_Pos                 RTC_RTC_RW_READ_Pos
#define BACKUP_RTC_TIME_RTC_SEC_Msk            RTC_RTC_TIME_RTC_SEC_Msk
#define BACKUP_RTC_TIME_RTC_SEC_Pos            RTC_RTC_TIME_RTC_SEC_Pos
#define BACKUP_RTC_TIME_RTC_MIN_Msk            RTC_RTC_TIME_RTC_MIN_Msk
#define BACKUP_RTC_TIME_RTC_MIN_Pos            RTC_RTC_TIME_RTC_MIN_Pos
#define BACKUP_RTC_TIME_RTC_HOUR_Msk           RTC_RTC_TIME_RTC_HOUR_Msk
#define BACKUP_RTC_TIME_RTC_HOUR_Pos           RTC_RTC_TIME_RTC_HOUR_Pos
#define BACKUP_RTC_TIME_RTC_DAY_Msk            RTC_RTC_TIME_RTC_DAY_Msk
#define BACKUP_RTC_TIME_RTC_DAY_Pos            RTC_RTC_TIME_RTC_DAY_Pos
#define BACKUP_RTC_DATE_RTC_DATE_Msk           RTC_RTC_DATE_RTC_DATE_Msk
#define BACKUP_RTC_DATE_RTC_DATE_Pos           RTC_RTC_DATE_RTC_DATE_Pos
#define BACKUP_RTC_DATE_RTC_MON_Msk            RTC_RTC_DATE_RTC_MON_Msk
#define BACKUP_RTC_DATE_RTC_MON_Pos            RTC_RTC_DATE_RTC_MON_Pos
#define BACKUP_RTC_DATE_RTC_YEAR_Msk           RTC_RTC_DATE_RTC_YEAR_Msk
#define BACKUP_RTC_DATE_RTC_YEAR_Pos           RTC_RTC_DATE_RTC_YEAR_Pos
#define BACKUP_ALM1_TIME_ALM_SEC_Msk           RTC_ALM1_TIME_ALM_SEC_Msk
#define BACKUP_ALM1_TIME_ALM_SEC_Pos           RTC_ALM1_TIME_ALM_SEC_Pos
#define BACKUP_ALM1_TIME_ALM_SEC_EN_Msk        RTC_ALM1_TIME_ALM_SEC_EN_Msk
#define BACKUP_ALM1_TIME_ALM_SEC_EN_Pos        RTC_ALM1_TIME_ALM_SEC_EN_Pos
#define BACKUP_ALM1_TIME_ALM_MIN_Msk           RTC_ALM1_TIME_ALM_MIN_Msk
#define BACKUP_ALM1_TIME_ALM_MIN_Pos           RTC_ALM1_TIME_ALM_MIN_Pos
#define BACKUP_ALM1_TIME_ALM_MIN_EN_Msk        RTC_ALM1_TIME_ALM_MIN_EN_Msk
#define BACKUP_ALM1_TIME_ALM_MIN_EN_Pos        RTC_ALM1_TIME_ALM_MIN_EN_Pos
#define BACKUP_ALM1_TIME_ALM_HOUR_Msk          RTC_ALM1_TIME_ALM_HOUR_Msk
#define BACKUP_ALM1_TIME_ALM_HOUR_Pos          RTC_ALM1_TIME_ALM_HOUR_Pos
#define BACKUP_ALM1_TIME_ALM_HOUR_EN_Msk       RTC_ALM1_TIME_ALM_HOUR_EN_Msk
#define BACKUP_ALM1_TIME_ALM_HOUR_EN_Pos       RTC_ALM1_TIME_ALM_HOUR_EN_Pos
#define BACKUP_ALM1_TIME_ALM_DAY_Msk           RTC_ALM1_TIME_ALM_DAY_Msk
#define BACKUP_ALM1_TIME_ALM_DAY_Pos           RTC_ALM1_TIME_ALM_DAY_Pos
#define BACKUP_ALM1_TIME_ALM_DAY_EN_Msk        RTC_ALM1_TIME_ALM_DAY_EN_Msk
#define BACKUP_ALM1_TIME_ALM_DAY_EN_Pos        RTC_ALM1_TIME_ALM_DAY_EN_Pos
#define BACKUP_ALM1_DATE_ALM_EN_Msk            RTC_ALM1_DATE_ALM_EN_Msk
#define BACKUP_ALM1_DATE_ALM_EN_Pos            RTC_ALM1_DATE_ALM_EN_Pos
#define BACKUP_ALM1_DATE_ALM_DATE_Msk          RTC_ALM1_DATE_ALM_DATE_Msk
#define BACKUP_ALM1_DATE_ALM_DATE_Pos          RTC_ALM1_DATE_ALM_DATE_Pos
#define BACKUP_ALM1_DATE_ALM_DATE_EN_Msk       RTC_ALM1_DATE_ALM_DATE_EN_Msk
#define BACKUP_ALM1_DATE_ALM_DATE_EN_Pos       RTC_ALM1_DATE_ALM_DATE_EN_Pos
#define BACKUP_ALM1_DATE_ALM_MON_Msk           RTC_ALM1_DATE_ALM_MON_Msk
#define BACKUP_ALM1_DATE_ALM_MON_Pos           RTC_ALM1_DATE_ALM_MON_Pos
#define BACKUP_ALM1_DATE_ALM_MON_EN_Msk        RTC_ALM1_DATE_ALM_MON_EN_Msk
#define BACKUP_ALM1_DATE_ALM_MON_EN_Pos        RTC_ALM1_DATE_ALM_MON_EN_Pos
#define BACKUP_ALM1_DATE_ALM_YEAR_Msk          RTC_ALM1_DATE_ALM_YEAR_Msk
#define BACKUP_ALM1_DATE_ALM_YEAR_Pos          RTC_ALM1_DATE_ALM_YEAR_Pos
#define BACKUP_ALM1_DATE_ALM_YEAR_EN_Msk       RTC_ALM1_DATE_ALM_YEAR_EN_Msk
#define BACKUP_ALM1_DATE_ALM_YEAR_EN_Pos       RTC_ALM1_DATE_ALM_YEAR_EN_Pos
#define BACKUP_ALM2_TIME_ALM_SEC_Msk           RTC_ALM2_TIME_ALM_SEC_Msk
#define BACKUP_ALM2_TIME_ALM_SEC_Pos           RTC_ALM2_TIME_ALM_SEC_Pos
#define BACKUP_ALM2_TIME_ALM_SEC_EN_Msk        RTC_ALM2_TIME_ALM_SEC_EN_Msk
#define BACKUP_ALM2_TIME_ALM_SEC_EN_Pos        RTC_ALM2_TIME_ALM_SEC_EN_Pos
#define BACKUP_ALM2_TIME_ALM_MIN_Msk           RTC_ALM2_TIME_ALM_MIN_Msk
#define BACKUP_ALM2_TIME_ALM_MIN_Pos           RTC_ALM2_TIME_ALM_MIN_Pos
#define BACKUP_ALM2_TIME_ALM_MIN_EN_Msk        RTC_ALM2_TIME_ALM_MIN_EN_Msk
#define BACKUP_ALM2_TIME_ALM_MIN_EN_Pos        RTC_ALM2_TIME_ALM_MIN_EN_Pos
#define BACKUP_ALM2_TIME_ALM_HOUR_Msk          RTC_ALM2_TIME_ALM_HOUR_Msk
#define BACKUP_ALM2_TIME_ALM_HOUR_Pos          RTC_ALM2_TIME_ALM_HOUR_Pos
#define BACKUP_ALM2_TIME_ALM_HOUR_EN_Msk       RTC_ALM2_TIME_ALM_HOUR_EN_Msk
#define BACKUP_ALM2_TIME_ALM_HOUR_EN_Pos       RTC_ALM2_TIME_ALM_HOUR_EN_Pos
#define BACKUP_ALM2_TIME_ALM_DAY_Msk           RTC_ALM2_TIME_ALM_DAY_Msk
#define BACKUP_ALM2_TIME_ALM_DAY_Pos           RTC_ALM2_TIME_ALM_DAY_Pos
#define BACKUP_ALM2_TIME_ALM_DAY_EN_Msk        RTC_ALM2_TIME_ALM_DAY_EN_Msk
#define BACKUP_ALM2_TIME_ALM_DAY_EN_Pos        RTC_ALM2_TIME_ALM_DAY_EN_Pos
#define BACKUP_ALM2_DATE_ALM_EN_Msk            RTC_ALM2_DATE_ALM_EN_Msk
#define BACKUP_ALM2_DATE_ALM_EN_Pos            RTC_ALM2_DATE_ALM_EN_Pos
#define BACKUP_ALM2_DATE_ALM_EN_Msk            RTC_ALM2_DATE_ALM_EN_Msk
#define BACKUP_ALM2_DATE_ALM_EN_Pos            RTC_ALM2_DATE_ALM_EN_Pos
#define BACKUP_ALM2_DATE_ALM_DATE_Msk          RTC_ALM2_DATE_ALM_DATE_Msk
#define BACKUP_ALM2_DATE_ALM_DATE_Pos          RTC_ALM2_DATE_ALM_DATE_Pos
#define BACKUP_ALM2_DATE_ALM_DATE_EN_Msk       RTC_ALM2_DATE_ALM_DATE_EN_Msk
#define BACKUP_ALM2_DATE_ALM_DATE_EN_Pos       RTC_ALM2_DATE_ALM_DATE_EN_Pos
#define BACKUP_ALM2_DATE_ALM_MON_Msk           RTC_ALM2_DATE_ALM_MON_Msk
#define BACKUP_ALM2_DATE_ALM_MON_Pos           RTC_ALM2_DATE_ALM_MON_Pos
#define BACKUP_ALM2_DATE_ALM_MON_EN_Msk        RTC_ALM2_DATE_ALM_MON_EN_Msk
#define BACKUP_ALM2_DATE_ALM_MON_EN_Pos        RTC_ALM2_DATE_ALM_MON_EN_Pos
#define BACKUP_CAL_CTL_CALIB_VAL_Msk           RTC_CAL_CTL_CALIB_VAL_Msk
#define BACKUP_CAL_CTL_CALIB_VAL_Pos           RTC_CAL_CTL_CALIB_VAL_Pos
#define BACKUP_CAL_CTL_CALIB_SIGN_Msk          RTC_CAL_CTL_CALIB_SIGN_Msk
#define BACKUP_CAL_CTL_CALIB_SIGN_Pos          RTC_CAL_CTL_CALIB_SIGN_Pos
#define BACKUP_CAL_CTL_CAL_OUT_Msk             RTC_CAL_CTL_CAL_OUT_Msk
#define BACKUP_CAL_CTL_CAL_OUT_Pos             RTC_CAL_CTL_CAL_OUT_Pos
#define BACKUP_CAL_CTL_CAL_SEL_Msk             RTC_CAL_CTL_CAL_SEL_Msk
#define BACKUP_CAL_CTL_CAL_SEL_Pos             RTC_CAL_CTL_CAL_SEL_Pos

#define BACKUP_CTL                          (((SRSS_Type *) SRSS)->CLK_WCO_CONFIG)
#define BACKUP_RTC_RW                       (((RTC_Type *) RTC)->RTC_RW)
#define BACKUP_CAL_CTL                      (((RTC_Type *) RTC)->CAL_CTL)
#define BACKUP_STATUS                       (((RTC_Type *) RTC)->STATUS)
#define BACKUP_RTC_TIME                     (((RTC_Type *) RTC)->RTC_TIME)
#define BACKUP_RTC_DATE                     (((RTC_Type *) RTC)->RTC_DATE)
#define BACKUP_ALM1_TIME                    (((RTC_Type *) RTC)->ALM1_TIME)
#define BACKUP_ALM1_DATE                    (((RTC_Type *) RTC)->ALM1_DATE)
#define BACKUP_ALM2_TIME                    (((RTC_Type *) RTC)->ALM2_TIME)
#define BACKUP_ALM2_DATE                    (((RTC_Type *) RTC)->ALM2_DATE)
#define BACKUP_INTR                         (((RTC_Type *) RTC)->INTR)
#define BACKUP_INTR_SET                     (((RTC_Type *) RTC)->INTR_SET)
#define BACKUP_INTR_MASK                    (((RTC_Type *) RTC)->INTR_MASK)
#define BACKUP_INTR_MASKED                  (((RTC_Type *) RTC)->INTR_MASKED)
#define BACKUP_PMIC_CTL                     (((RTC_Type *) RTC)->PMIC_CTL)
#define BACKUP_RESET                        (((RTC_Type *) RTC)->RESET)
#define BACKUP_LPECO_CTL                    (((RTC_Type *) RTC)->LPECO_CTL)
#define BACKUP_LPECO_PRESCALE               (((RTC_Type *) RTC)->LPECO_PRESCALE)
#define BACKUP_LPECO_STATUS                 (((RTC_Type *) RTC)->LPECO_STATUS)
#define BACKUP_WCO_STATUS                   (((SRSS_Type *) SRSS)->CLK_WCO_STATUS)
#define BACKUP_BREG_SET0                    (((RTC_Type *) RTC)->BREG_SET0)
#define BACKUP_BREG_SET1                    (((RTC_Type *) RTC)->BREG_SET1)
#define BACKUP_BREG_SET2                    (((RTC_Type *) RTC)->BREG_SET2)
#define BACKUP_BREG_SET3                    (((RTC_Type *) RTC)->BREG_SET3)


#define CY_SRSS_BACKUP_NUM_BREG             (SRSS_RTC_NUM_BREG0 + SRSS_RTC_NUM_BREG1 + SRSS_RTC_NUM_BREG2 + SRSS_RTC_NUM_BREG3)
#define CY_SRSS_BACKUP_BREG0_START_POS      (0UL)
#define CY_SRSS_BACKUP_BREG1_START_POS      (SRSS_RTC_NUM_BREG0)
#define CY_SRSS_BACKUP_BREG2_START_POS      (SRSS_RTC_NUM_BREG0 + SRSS_RTC_NUM_BREG1)
#define CY_SRSS_BACKUP_BREG3_START_POS      (SRSS_RTC_NUM_BREG0 + SRSS_RTC_NUM_BREG1 + SRSS_RTC_NUM_BREG2)




/*******************************************************************************
*                CANFD
*******************************************************************************/

#define CANFD_CTL(base)                           (((CANFD_Type *)(base))->CTL)
#define CANFD_STATUS(base)                        (((CANFD_Type *)(base))->STATUS)
#define CANFD_NBTP(base, chan)                    (((CANFD_Type *)(base))->CH[chan].M_TTCAN.NBTP)
#define CANFD_IR(base, chan)                      (((CANFD_Type *)(base))->CH[chan].M_TTCAN.IR)
#define CANFD_IE(base, chan)                      (((CANFD_Type *)(base))->CH[chan].M_TTCAN.IE)
#define CANFD_ILS(base, chan)                     (((CANFD_Type *)(base))->CH[chan].M_TTCAN.ILS)
#define CANFD_ILE(base, chan)                     (((CANFD_Type *)(base))->CH[chan].M_TTCAN.ILE)
#define CANFD_CCCR(base, chan)                    (((CANFD_Type *)(base))->CH[chan].M_TTCAN.CCCR)
#define CANFD_SIDFC(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.SIDFC)
#define CANFD_XIDFC(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.XIDFC)
#define CANFD_XIDAM(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.XIDAM)
#define CANFD_RXESC(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXESC)
#define CANFD_RXF0C(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF0C)
#define CANFD_RXF1C(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF1C)
#define CANFD_RXFTOP_CTL(base, chan)              (((CANFD_Type *)(base))->CH[chan].RXFTOP_CTL)
#define CANFD_RXBC(base, chan)                    (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXBC)
#define CANFD_TXESC(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXESC)
#define CANFD_TXEFC(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXEFC)
#define CANFD_TXBC(base, chan)                    (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBC)
#define CANFD_DBTP(base, chan)                    (((CANFD_Type *)(base))->CH[chan].M_TTCAN.DBTP)
#define CANFD_TDCR(base, chan)                    (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TDCR)
#define CANFD_GFC(base, chan)                     (((CANFD_Type *)(base))->CH[chan].M_TTCAN.GFC)
#define CANFD_TXBRP(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBRP)
#define CANFD_TXBAR(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBAR)
#define CANFD_TXBCR(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBCR)
#define CANFD_TXBTO(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBTO)
#define CANFD_TXBCF(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBCF)
#define CANFD_TXBTIE(base, chan)                  (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBTIE)
#define CANFD_TXBCIE(base, chan)                  (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBCIE)
#define CANFD_NDAT1(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.NDAT1)
#define CANFD_NDAT2(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.NDAT2)
#define CANFD_RXF0S(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF0S)
#define CANFD_RXFTOP0_DATA(base, chan)            (((CANFD_Type *)(base))->CH[chan].RXFTOP0_DATA)
#define CANFD_RXFTOP1_DATA(base, chan)            (((CANFD_Type *)(base))->CH[chan].RXFTOP1_DATA)
#define CANFD_RXF0A(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF0A)
#define CANFD_RXF1S(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF1S)
#define CANFD_RXF1A(base, chan)                   (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF1A)
#define CANFD_PSR(base, chan)                     (((CANFD_Type *)(base))->CH[chan].M_TTCAN.PSR)
#define CANFD_TEST(base, chan)                    (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TEST)
#define CANFD_CREL(base, chan)                    (((CANFD_Type *)(base))->CH[chan].M_TTCAN.CREL)

#define CY_CANFD_CHANNELS_NUM                     (CANFD_CAN_NR)

/*******************************************************************************
*                MXOTPC
*******************************************************************************/
#define CY_MXOTPC_BASE                      (uint32_t)GET_ALIAS_ADDRESS(MXOTPC)

#define MXOTPC_CTL                          (((MXOTPC_Type *) CY_MXOTPC_BASE)->CTL)
#define MXOTPC_OTP_STATUS                   (((MXOTPC_Type *) CY_MXOTPC_BASE)->OTP_STATUS)
#define MXOTPC_OTP_CTL                      (((MXOTPC_Type *) CY_MXOTPC_BASE)->OTP_CTL)
#define MXOTPC_OTP_CMD                      (((MXOTPC_Type *) CY_MXOTPC_BASE)->OTP_CMD)
#define MXOTPC_LAYOUT                       (((MXOTPC_Type *) CY_MXOTPC_BASE)->LAYOUT)
#define MXOTPC_LAYOUT_EXT                   (((MXOTPC_Type *) CY_MXOTPC_BASE)->LAYOUT_EXT)
#define MXOTPC_OTP_PROGDATA                 (((MXOTPC_Type *) CY_MXOTPC_BASE)->OTP_PROGDATA)
#define MXOTPC_FOUT_ECC_STATUS              (((MXOTPC_Type *) CY_MXOTPC_BASE)->FOUT_ECC_STATUS)
#define MXOTPC_ECC_STATUS                   (((MXOTPC_Type *) CY_MXOTPC_BASE)->ECC_STATUS)
#define MXOTPC_CC312_ECC_STATUS             (((MXOTPC_Type *) CY_MXOTPC_BASE)->CC312_ECC_STATUS)
#define MXOTPC_CC312_ERROR_LOG              (((MXOTPC_Type *) CY_MXOTPC_BASE)->CC312_ERROR_LOG)
#define MXOTPC_CC312_CMD_SEL_LO             (((MXOTPC_Type *) CY_MXOTPC_BASE)->CC312_CMD_SEL_LO)
#define MXOTPC_CC312_CMD_SEL_HI             (((MXOTPC_Type *) CY_MXOTPC_BASE)->CC312_CMD_SEL_HI)
#define MXOTPC_LAYOUT_EXT1                  (((MXOTPC_Type *) CY_MXOTPC_BASE)->LAYOUT_EXT1)
#define MXOTPC_LAYOUT_EXT2                  (((MXOTPC_Type *) CY_MXOTPC_BASE)->LAYOUT_EXT2)
#define MXOTPC_LAYOUT_EXT3                  (((MXOTPC_Type *) CY_MXOTPC_BASE)->LAYOUT_EXT3)
#define MXOTPC_LAYOUT_EXT4                  (((MXOTPC_Type *) CY_MXOTPC_BASE)->LAYOUT_EXT4)
#define MXOTPC_CPU_PROG_CMD                 (((MXOTPC_Type *) CY_MXOTPC_BASE)->CPU_PROG_CMD)
#define MXOTPC_BOOTROW                      (((MXOTPC_Type *) CY_MXOTPC_BASE)->BOOTROW)
#define MXOTPC_CC312_RGN_LOCK_CTL           (((MXOTPC_Type *) CY_MXOTPC_BASE)->CC312_RGN_LOCK_CTL)
#define MXOTPC_ERR_RESP_CTL                 (((MXOTPC_Type *) CY_MXOTPC_BASE)->ERR_RESP_CTL)
#define MXOTPC_INTR_OTPC                    (((MXOTPC_Type *) CY_MXOTPC_BASE)->INTR_OTPC)
#define MXOTPC_INTR_OTPC_SET                (((MXOTPC_Type *) CY_MXOTPC_BASE)->INTR_OTPC_SET)
#define MXOTPC_INTR_OTPC_MASK               (((MXOTPC_Type *) CY_MXOTPC_BASE)->INTR_OTPC_MASK)
#define MXOTPC_INTR_OTPC_MASKED             (((MXOTPC_Type *) CY_MXOTPC_BASE)->INTR_OTPC_MASKED)
#define MXOTPC_CPU_ERROR_LOG                (((MXOTPC_Type *) CY_MXOTPC_BASE)->CPU_ERROR_LOG)

#define MXOTPC_BOOT_ROW_FOUT_ECC_DED_STATUS_Msk    0x00070000UL

/*******************************************************************************
*                MXSDIODEV
*******************************************************************************/

#define MXSDIO_CORECONTROL(base)         (((MXSDIO_Type *)(base))->CORECONTROL)
#define MXSDIO_CORESTATUS(base)              (((MXSDIO_Type *)(base))->CORESTATUS)
#define MXSDIO_BISTSTATUS(base)              (((MXSDIO_Type *)(base))->BISTSTATUS)
#define MXSDIO_INTSTATUS(base)               (((MXSDIO_Type *)(base))->INTSTATUS)
#define MXSDIO_INTHOSTMASK(base)             (((MXSDIO_Type *)(base))->INTHOSTMASK)
#define MXSDIO_INTSBMASK(base)               (((MXSDIO_Type *)(base))->INTSBMASK)
#define MXSDIO_SBINTSTATUS(base)             (((MXSDIO_Type *)(base))->SBINTSTATUS)
#define MXSDIO_SBINTMASK(base)               (((MXSDIO_Type *)(base))->SBINTMASK)
#define MXSDIO_SDIOFUNCINTMASK(base)         (((MXSDIO_Type *)(base))->SDIOFUNCINTMASK)
#define MXSDIO_TOSBMAILBOX(base)             (((MXSDIO_Type *)(base))->TOSBMAILBOX)
#define MXSDIO_TOHOSTMAILBOX(base)           (((MXSDIO_Type *)(base))->TOHOSTMAILBOX)
#define MXSDIO_TOSBMAILDATA(base)            (((MXSDIO_Type *)(base))->TOSBMAILDATA)
#define MXSDIO_TOHOSTMAILDATA(base)          (((MXSDIO_Type *)(base))->TOHOSTMAILDATA)
#define MXSDIO_SDIOACCESS(base)              (((MXSDIO_Type *)(base))->SDIOACCESS)
#define MXSDIO_UNUSEDINTFCTRL(base)          (((MXSDIO_Type *)(base))->UNUSEDINTFCTRL)
#define MXSDIO_INTRCVLAZY(base)              (((MXSDIO_Type *)(base))->INTRCVLAZY)
#define MXSDIO_CMD52RDCOUNT(base)            (((MXSDIO_Type *)(base))->CMD52RDCOUNT)
#define MXSDIO_CMD52WRCOUNT(base)            (((MXSDIO_Type *)(base))->CMD52WRCOUNT)
#define MXSDIO_CMD53RDCOUNT(base)            (((MXSDIO_Type *)(base))->CMD53RDCOUNT)
#define MXSDIO_CMD53WRCOUNT(base)            (((MXSDIO_Type *)(base))->CMD53WRCOUNT)
#define MXSDIO_ABORTCOUNT(base)              (((MXSDIO_Type *)(base))->ABORTCOUNT)
#define MXSDIO_CRCERRORCOUNT(base)           (((MXSDIO_Type *)(base))->CRCERRORCOUNT)
#define MXSDIO_RDOUTOFSYNCCOUNT(base)        (((MXSDIO_Type *)(base))->RDOUTOFSYNCCOUNT)
#define MXSDIO_WROUTOFSYNCCOUNT(base)        (((MXSDIO_Type *)(base))->WROUTOFSYNCCOUNT)
#define MXSDIO_WRITEBUSYCOUNT(base)          (((MXSDIO_Type *)(base))->WRITEBUSYCOUNT)
#define MXSDIO_READWAITCOUNT(base)         (((MXSDIO_Type *)(base))->READWAITCOUNT)
#define MXSDIO_RDTERMCOUNT(base)             (((MXSDIO_Type *)(base))->RDTERMCOUNT)
#define MXSDIO_WRTERMCOUNT(base)             (((MXSDIO_Type *)(base))->WRTERMCOUNT)
#define MXSDIO_CLOCKCTRLSTATUS(base)         (((MXSDIO_Type *)(base))->CLOCKCTRLSTATUS)
#define MXSDIO_WORKARND(base)                (((MXSDIO_Type *)(base))->WORKARND)
#define MXSDIO_PWRCTRL(base)                 (((MXSDIO_Type *)(base))->PWRCTRL)
#define MXSDIO_XMTCONTROL(base)              (((MXSDIO_Type *)(base))->XMTCONTROL)
#define MXSDIO_XMTPTR(base)                  (((MXSDIO_Type *)(base))->XMTPTR)
#define MXSDIO_XMTADDRESSLOW(base)           (((MXSDIO_Type *)(base))->XMTADDRESSLOW)
#define MXSDIO_XMTADDRESSHI(base)            (((MXSDIO_Type *)(base))->XMTADDRESSHI)
#define MXSDIO_XMTSTATUS0(base)              (((MXSDIO_Type *)(base))->XMTSTATUS0)
#define MXSDIO_XMTSTATUS1(base)              (((MXSDIO_Type *)(base))->XMTSTATUS1)
#define MXSDIO_RCVCONTROL(base)              (((MXSDIO_Type *)(base))->RCVCONTROL)
#define MXSDIO_RCVPTR(base)                  (((MXSDIO_Type *)(base))->RCVPTR)
#define MXSDIO_RCVADDRESSLOW(base)           (((MXSDIO_Type *)(base))->RCVADDRESSLOW)
#define MXSDIO_RCVADDRESSHI(base)            (((MXSDIO_Type *)(base))->RCVADDRESSHI)
#define MXSDIO_RCVSTATUS0(base)              (((MXSDIO_Type *)(base))->RCVSTATUS0)
#define MXSDIO_RCVSTATUS1(base)              (((MXSDIO_Type *)(base))->RCVSTATUS1)
#define MXSDIO_FIFOADDRESS(base)             (((MXSDIO_Type *)(base))->FIFOADDRESS)
#define MXSDIO_FIFODATAL(base)               (((MXSDIO_Type *)(base))->FIFODATAL)
#define MXSDIO_FIFODATAH(base)               (((MXSDIO_Type *)(base))->FIFODATAH)
#define MXSDIO_SDIOCLKRESETCTRLREG(base)     (((MXSDIO_Type *)(base))->SDIOCLKRESETCTRLREG)
#define MXSDIO_OTPSTATUSSHADOWREG(base)      (((MXSDIO_Type *)(base))->OTPSTATUSSHADOWREG)
#define MXSDIO_OTPLAYOUTSHADOWREG(base)      (((MXSDIO_Type *)(base))->OTPLAYOUTSHADOWREG)
#define MXSDIO_OTPSHADOWREG1(base)           (((MXSDIO_Type *)(base))->OTPSHADOWREG1)
#define MXSDIO_OTPSHADOWREG2(base)           (((MXSDIO_Type *)(base))->OTPSHADOWREG2)
#define MXSDIO_OTPSHADOWREG3(base)           (((MXSDIO_Type *)(base))->OTPSHADOWREG3)

/******************************************************************************
*                MXETH
*******************************************************************************/

#define ETH_CTL(base)                       (((ETH_Type*)(base))->CTL)
#define ETH_TX_Q_PTR(base)                  (((ETH_Type*)(base))->TRANSMIT_Q_PTR)
#define ETH_TX_Q1_PTR(base)                 (((ETH_Type*)(base))->TRANSMIT_Q1_PTR)
#define ETH_TX_Q2_PTR(base)                 (((ETH_Type*)(base))->TRANSMIT_Q2_PTR)
#define ETH_RX_Q_PTR(base)                  (((ETH_Type*)(base))->RECEIVE_Q_PTR)
#define ETH_RX_Q1_PTR(base)                 (((ETH_Type*)(base))->RECEIVE_Q1_PTR)
#define ETH_RX_Q2_PTR(base)                 (((ETH_Type*)(base))->RECEIVE_Q2_PTR)

/*******************************************************************************
*                PPU
*******************************************************************************/
#define CY_PPU_PD0_BASE                              ((uint32_t)PWRMODE_PPU_MAIN)
#define CY_PPU_PD1_BASE                              ((uint32_t)PWRMODE_PPU_PD1)
#define CY_PPU_SRAM0_BASE                            ((uint32_t)RAMC_PPU0_BASE)
#define CY_PPU_SRAM1_BASE                            ((uint32_t)RAMC_PPU1_BASE)
#define CY_PPU_SYSCPU_BASE                           ((uint32_t)CPUSS_PPU_BASE)
#define CY_PPU_APPCPUSS_BASE                         ((uint32_t)PPU_APPCPUSS_BASE)
#define CY_PPU_APPCPU_BASE                           ((uint32_t)PPU_CM55_0_BASE)
#define CY_PPU_SOCMEM_BASE                           ((uint32_t)SOCMEM_PPU_SOCMEM)
#define CY_PPU_U55_BASE                              ((uint32_t)U550_MXU55_PPU )

/* Alias name for PD0 PPU */
#define CY_PPU_MAIN_BASE                             CY_PPU_PD0_BASE

/* PPU configurations for DEEPSLEEP */
#define CY_SYSTEM_MAIN_PPU_DEEPSLEEP_MODE        PPU_V1_MODE_FULL_RET
#define CY_SYSTEM_PD1_PPU_DEEPSLEEP_MODE         PPU_V1_MODE_FULL_RET
#define CY_SYSTEM_SRAM0_PPU_DEEPSLEEP_MODE       PPU_V1_MODE_MEM_RET
#define CY_SYSTEM_SRAM1_PPU_DEEPSLEEP_MODE       PPU_V1_MODE_MEM_RET
#define CY_SYSTEM_SYSCPU_PPU_DEEPSLEEP_MODE      PPU_V1_MODE_FULL_RET
#define CY_SYSTEM_APPCPUSS_PPU_DEEPSLEEP_MODE    PPU_V1_MODE_FULL_RET
#define CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_MODE      PPU_V1_MODE_FULL_RET
#define CY_SYSTEM_SOCMEM_PPU_DEEPSLEEP_MODE      PPU_V1_MODE_MEM_RET
#define CY_SYSTEM_U55_PPU_DEEPSLEEP_MODE         PPU_V1_MODE_OFF


/* PPU configurations for DEEPSLEEP-RAM */
#define CY_SYSTEM_MAIN_PPU_DEEPSLEEP_RAM_MODE        PPU_V1_MODE_MEM_RET
#define CY_SYSTEM_PD1_PPU_DEEPSLEEP_RAM_MODE         PPU_V1_MODE_MEM_RET
#define CY_SYSTEM_SRAM0_PPU_DEEPSLEEP_RAM_MODE       PPU_V1_MODE_MEM_RET
#define CY_SYSTEM_SRAM1_PPU_DEEPSLEEP_RAM_MODE       PPU_V1_MODE_MEM_RET
#define CY_SYSTEM_SYSCPU_PPU_DEEPSLEEP_RAM_MODE      PPU_V1_MODE_OFF
#define CY_SYSTEM_APPCPUSS_PPU_DEEPSLEEP_RAM_MODE    PPU_V1_MODE_OFF
#define CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_RAM_MODE      PPU_V1_MODE_OFF
#define CY_SYSTEM_SOCMEM_PPU_DEEPSLEEP_RAM_MODE      PPU_V1_MODE_MEM_RET
#define CY_SYSTEM_U55_PPU_DEEPSLEEP_RAM_MODE         PPU_V1_MODE_OFF


/* PPU configurations for DEEPSLEEP-OFF */
#define CY_SYSTEM_MAIN_PPU_DEEPSLEEP_OFF_MODE        PPU_V1_MODE_OFF
#define CY_SYSTEM_PD1_PPU_DEEPSLEEP_OFF_MODE         PPU_V1_MODE_OFF
#define CY_SYSTEM_SRAM0_PPU_DEEPSLEEP_OFF_MODE       PPU_V1_MODE_OFF
#define CY_SYSTEM_SRAM1_PPU_DEEPSLEEP_OFF_MODE       PPU_V1_MODE_OFF
#define CY_SYSTEM_SYSCPU_PPU_DEEPSLEEP_OFF_MODE      PPU_V1_MODE_OFF
#define CY_SYSTEM_APPCPUSS_PPU_DEEPSLEEP_OFF_MODE    PPU_V1_MODE_OFF
#define CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_OFF_MODE      PPU_V1_MODE_OFF
#define CY_SYSTEM_SOCMEM_PPU_DEEPSLEEP_OFF_MODE      PPU_V1_MODE_OFF
#define CY_SYSTEM_U55_PPU_DEEPSLEEP_OFF_MODE         PPU_V1_MODE_OFF


/* System DEEPSLEEP Mode = (PPU_MAIN Mode)*/
#ifdef CORE_NAME_CM55_0
#define CY_SYSTEM_DEEPSLEEP_PPU_MODES        (uint32_t)((uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_MODE | ((uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_MODE << 8U))
#define CY_SYSTEM_DEEPSLEEP_RAM_PPU_MODES    (uint32_t)((uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_RAM_MODE | ((uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_RAM_MODE << 8U))
#define CY_SYSTEM_DEEPSLEEP_OFF_PPU_MODES    (uint32_t)((uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_OFF_MODE | ((uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_OFF_MODE << 8U))
#else
#define CY_SYSTEM_DEEPSLEEP_PPU_MODES        ((uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_MODE)
#define CY_SYSTEM_DEEPSLEEP_RAM_PPU_MODES    ((uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_RAM_MODE)
#define CY_SYSTEM_DEEPSLEEP_OFF_PPU_MODES    ((uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_OFF_MODE)
#endif



/*******************************************************************************
*                PDCM
*******************************************************************************/

#define CY_PDCM_PD_SENSE(pd_id)                        (((PWRMODE_PD_Type*) &PWRMODE->PD[pd_id])->PD_SENSE)
#define CY_PDCM_PD_SPT(pd_id)                          (((PWRMODE_PD_Type*) &PWRMODE->PD[pd_id])->PD_SPT)

/*******************************************************************************
*                PWRMODE
*******************************************************************************/

#define CY_PWRMODE_CLK_SELECT                          (((PWRMODE_Type*) PWRMODE_BASE)->CLK_SELECT)


/*******************************************************************************
*                IPC
*******************************************************************************/

#define REG_IPC_STRUCT_ACQUIRE(base)           (((IPC_STRUCT_Type*)(base))->ACQUIRE)
#define REG_IPC_STRUCT_RELEASE(base)           (((IPC_STRUCT_Type*)(base))->RELEASE)
#define REG_IPC_STRUCT_NOTIFY(base)            (((IPC_STRUCT_Type*)(base))->NOTIFY)
#define REG_IPC_STRUCT_DATA(base)              (((IPC_STRUCT_Type*)(base))->DATA0)
#define REG_IPC_STRUCT_DATA1(base)             (((IPC_STRUCT_Type*)(base))->DATA1)
#define REG_IPC_STRUCT_LOCK_STATUS(base)       (*(volatile uint32_t*)((uint32_t)(base) + offsetof(IPC_STRUCT_Type, LOCK_STATUS)))

#define REG_IPC_INTR_STRUCT_INTR(base)         (((IPC_INTR_STRUCT_Type*)(base))->INTR)
#define REG_IPC_INTR_STRUCT_INTR_SET(base)     (((IPC_INTR_STRUCT_Type*)(base))->INTR_SET)
#define REG_IPC_INTR_STRUCT_INTR_MASK(base)    (((IPC_INTR_STRUCT_Type*)(base))->INTR_MASK)
#define REG_IPC_INTR_STRUCT_INTR_MASKED(base)  (((IPC_INTR_STRUCT_Type*)(base))->INTR_MASKED)

#define CY_IPC_STRUCT_PTR_FOR_IP(ipcIndex, base)            ((IPC_STRUCT_Type*)((uint32_t)(base) + (sizeof(IPC_STRUCT_Type) * (ipcIndex))))
#define CY_IPC_INTR_STRUCT_PTR_FOR_IP(ipcIntrIndex, base)   (&(((IPC_Type *)(base))->INTR_STRUCT[(ipcIntrIndex)]))

#define CY_IPC_INSTANCES                       CY_IP_MXIPC_INSTANCES
#define CY_IPC_CHANNELS                        (CPUSS_IPC_NR + APPCPUSS_IPC_NR)
#define CY_IPC_CHANNELS_PER_INSTANCE           CPUSS_IPC_NR
#define CY_IPC_INTERRUPTS                      (CPUSS_IPC_IRQ_NR + APPCPUSS_IPC_IRQ_NR)
#define CY_IPC_INTERRUPTS_PER_INSTANCE         CPUSS_IPC_IRQ_NR
#define CY_IPC_IP0_CH                          CPUSS_IPC_NR
#define CY_IPC_IP0_INT                         CPUSS_IPC_IRQ_NR
#define CY_IPC_IP1_CH                          APPCPUSS_IPC_NR
#define CY_IPC_IP1_INT                         APPCPUSS_IPC_IRQ_NR
#define cpuss_interrupts_ipc_0_IRQn            m33syscpuss_interrupts_ipc_dpslp_0_IRQn
#define cpuss_interrupts_ipc_1_IRQn            m55appcpuss_interrupts_ipc_dpslp_0_IRQn

extern const uint32_t IPC_CHANNELS_NR[CY_IPC_INSTANCES];
extern const uint32_t IPC_IRQ_NR[CY_IPC_INSTANCES];
extern const uint32_t IPC_BASE_PTR[CY_IPC_INSTANCES];

#define CY_IPC_PIPE_IS_CHANNEL_INTR_COMBINATION_VALID(ipcChannel, ipcIntrIndex)  ((((ipcChannel) < CY_IPC_CHANNELS_PER_INSTANCE) && ((ipcIntrIndex) < CY_IPC_INTERRUPTS_PER_INSTANCE)) || \
                                                                                  (((ipcChannel) >= CY_IPC_CHANNELS_PER_INSTANCE) && ((ipcIntrIndex) >= CY_IPC_INTERRUPTS_PER_INSTANCE)))
#define CY_IPC_STRUCT_PTR(ipcIndex)                                              (((ipcIndex < (CY_IPC_CHANNELS_PER_INSTANCE * CY_IPC_INSTANCES)) && (ipcIndex > 0 )) ? \
                                                                                    CY_IPC_STRUCT_PTR_FOR_IP(((ipcIndex)%CY_IPC_CHANNELS_PER_INSTANCE), \
                                                                                    IPC_BASE_PTR[((ipcIndex)-((ipcIndex)%CY_IPC_CHANNELS_PER_INSTANCE))/CY_IPC_CHANNELS_PER_INSTANCE]) : \
                                                                                    ( (ipcIndex == 0) ? (CY_IPC_STRUCT_PTR_FOR_IP(0,IPC_BASE_PTR[0])) : \
                                                                                    ((ipcIndex == (CY_IPC_CHANNELS_PER_INSTANCE * CY_IPC_INSTANCES)) ? \
                                                                                    (CY_IPC_STRUCT_PTR_FOR_IP(((ipcIndex)%CY_IPC_CHANNELS_PER_INSTANCE),IPC_BASE_PTR[CY_IPC_INSTANCES -1])) : NULL   ) ))
#define CY_IPC_INTR_STRUCT_PTR(ipcIntrIndex)                                     CY_IPC_INTR_STRUCT_PTR_FOR_IP(((ipcIntrIndex)%CY_IPC_INTERRUPTS_PER_INSTANCE), IPC_BASE_PTR[((ipcIntrIndex)-((ipcIntrIndex)%CY_IPC_INTERRUPTS_PER_INSTANCE))/CY_IPC_INTERRUPTS_PER_INSTANCE])
/* ipcChannel comprises of total number of channels present in all IPC IP instances */
#define CY_IPC_PIPE_COMPUTE_INTR_MASK(ipcChannel, ipcIntrmask)                   (((ipcChannel)<CY_IPC_CHANNELS_PER_INSTANCE)?(ipcIntrmask):((((ipcIntrmask)&0xFFFF0000U) != 0x0U)?((ipcIntrmask)>>CY_IPC_CHANNELS_PER_INSTANCE):(ipcIntrmask)))
/* ipcChannel comprises of total number of channels present in all IPC IP instances */
#define CY_IPC_PIPE_CHANNEL_NUMBER_WITHIN_INSTANCE(ipcChannel)                  (((ipcChannel)%CY_IPC_CHANNELS_PER_INSTANCE))
#define CY_IPC_PIPE_INTR_NUMBER_WITHIN_INSTANCE(ipcIntr)                        (((ipcIntr)%CY_IPC_INTERRUPTS_PER_INSTANCE))

#define CY_IPC_CH_MASK(chIndex)         (0x1u << ((chIndex) % CY_IPC_CHANNELS_PER_INSTANCE))
#define CY_IPC_INTR_MASK(intrIndex)     (0x1u << ((intrIndex) % CY_IPC_INTERRUPTS_PER_INSTANCE))
#define CY_IPC0_INTR_MUX(intrIndex)     (cpuss_interrupts_ipc_0_IRQn + ((intrIndex) % CY_IPC_INTERRUPTS_PER_INSTANCE))
#define CY_IPC1_INTR_MUX(intrIndex)     (cpuss_interrupts_ipc_1_IRQn + ((intrIndex) % CY_IPC_INTERRUPTS_PER_INSTANCE))
#define CY_IPC_INTR_MUX(intrIndex)      (((intrIndex) < CY_IPC_INTERRUPTS_PER_INSTANCE) ? (CY_IPC0_INTR_MUX((intrIndex))) : (CY_IPC1_INTR_MUX((intrIndex))))

#define IPC0_SEMA_CH_NUM                (3UL)
#define IPC0_SEMA_CH_MASK               (CY_IPC_CH_MASK(IPC0_SEMA_CH_NUM))
/* Syspm IP Semaphore Macros */
#define CY_SYSPM_SEMA_NUM_MULTI_CORE         10UL
#define CY_SYSPM_SEMA_POST_TRIM_STATUS       11UL

#ifdef WA__PM_0159902_6
/* Used as lock for RRAM write operation */
#define CY_IPC_CHAN_RRAM_LOCK           (2UL)
#endif


/** IPC Semaphores allocation */
#define CY_IPC_SEMA_COUNT               (128UL)  /* <<< This will allow 128 (4*32) semaphores */

#define CY_IPC_SECURE_SEMA_DEVICE       (1UL)   /** Define this for enabling secure semaphore in ipc sema driver */

/* Secure Service IPC client */
#define CY_IPC_MSG_SECURE_SERVICES      (2UL)

/**
* \addtogroup group_ipc_macros
* \{
* * IPC0 CH  - 3 to 7 and 11 to 15
* * IPC0 INT - 3 to 5
* * IPC1 CH  - 17 to 31
* * IPC1 INT - 9 to 15
*
* \note If there are high level middleware libraries used such as MTB-IPC/MTB-SRF, please refer to BSP documentation
        for reservations under the section - MTB IPC Configuration
*/

/* user IPC channel */
#define CY_IPC0_CHAN_USER                (4u)   /**< User ipc channel index of IPC0 instance */
/* user IPC interrupt */
#define CY_IPC0_INTR_USER                (2u)   /**< First ipc interrupt index of IPC0 instance */

/* user IPC channel */
#define CY_IPC_CHAN_USER                 (1u + IPC0_IPC_NR)   /**< First ipc channel index of IPC1 instance meant for CM33 <-> CM55 */
/* user IPC interrupt */
#define CY_IPC_INTR_USER                 (1u + IPC0_IPC_IRQ_NR)   /**< First ipc interrupt index of IPC1 instance meant for CM33 <-> CM55 */

/** \} group_ipc_macros */

/* These definitions will be removed in the next release */
/* IPC0 channel-2 and interrupt-2 also reserved for secure domain */
#define CM33_NS_IPC0_CH_NUM             (0x5u)
#define CM33_NS_IPC0_CH_MASK            (CY_IPC_CH_MASK(CM33_NS_IPC0_CH_NUM))
#define CM33_NS_IPC0_INTR_NUM           (0x5u)
#define CM33_NS_IPC0_INTR_MASK          (CY_IPC_INTR_MASK(CM33_NS_IPC0_INTR_NUM))
#define CM33_NS_IPC0_INTR_MUX           (CY_IPC0_INTR_MUX(CM33_NS_IPC0_INTR_NUM))

/*******************************************************************************
*                LIN
*******************************************************************************/
#if defined (CY_IP_MXLIN)
#define LIN0_CH1                                ((LIN_CH_Type*) &LIN0->CH[1])
#define LIN0_CH2                                ((LIN_CH_Type*) &LIN0->CH[2])
#define LIN0_CH3                                ((LIN_CH_Type*) &LIN0->CH[3])
#define LIN0_CH4                                ((LIN_CH_Type*) &LIN0->CH[4])
#define LIN0_CH5                                ((LIN_CH_Type*) &LIN0->CH[5])
#define LIN0_CH6                                ((LIN_CH_Type*) &LIN0->CH[6])
#define LIN0_CH7                                ((LIN_CH_Type*) &LIN0->CH[7])
#define LIN0_CH8                                ((LIN_CH_Type*) &LIN0->CH[8])
#define LIN0_CH9                                ((LIN_CH_Type*) &LIN0->CH[9])
#define LIN0_CH10                               ((LIN_CH_Type*) &LIN0->CH[10])
#define LIN0_CH11                               ((LIN_CH_Type*) &LIN0->CH[11])
#define LIN0_CH12                               ((LIN_CH_Type*) &LIN0->CH[12])
#define LIN0_CH13                               ((LIN_CH_Type*) &LIN0->CH[13])
#define LIN0_CH14                               ((LIN_CH_Type*) &LIN0->CH[14])
#define LIN0_CH15                               ((LIN_CH_Type*) &LIN0->CH[15])
#define LIN0_CH16                               ((LIN_CH_Type*) &LIN0->CH[16])
#define LIN0_CH17                               ((LIN_CH_Type*) &LIN0->CH[17])
#define LIN0_CH18                               ((LIN_CH_Type*) &LIN0->CH[18])
#define LIN0_CH19                               ((LIN_CH_Type*) &LIN0->CH[19])
#define LIN0_CH20                               ((LIN_CH_Type*) &LIN0->CH[20])
#define LIN0_CH21                               ((LIN_CH_Type*) &LIN0->CH[21])
#define LIN0_CH22                               ((LIN_CH_Type*) &LIN0->CH[22])
#define LIN0_CH23                               ((LIN_CH_Type*) &LIN0->CH[23])
#define LIN0_CH24                               ((LIN_CH_Type*) &LIN0->CH[24])
#define LIN0_CH25                               ((LIN_CH_Type*) &LIN0->CH[25])
#define LIN0_CH26                               ((LIN_CH_Type*) &LIN0->CH[26])
#define LIN0_CH27                               ((LIN_CH_Type*) &LIN0->CH[27])
#define LIN0_CH28                               ((LIN_CH_Type*) &LIN0->CH[28])
#define LIN0_CH29                               ((LIN_CH_Type*) &LIN0->CH[29])
#define LIN0_CH30                               ((LIN_CH_Type*) &LIN0->CH[30])
#define LIN0_CH31                               ((LIN_CH_Type*) &LIN0->CH[31])

#define LIN_CH_CTL0(base)                       (((LIN_CH_Type *)(base))->CTL0)
#define LIN_CH_CTL1(base)                       (((LIN_CH_Type *)(base))->CTL1)
#define LIN_CH_STATUS(base)                     (((LIN_CH_Type *)(base))->STATUS)
#define LIN_CH_CMD(base)                        (((LIN_CH_Type *)(base))->CMD)
#define LIN_CH_TX_RX_STATUS(base)               (((LIN_CH_Type *)(base))->TX_RX_STATUS)
#define LIN_CH_PID_CHECKSUM(base)               (((LIN_CH_Type *)(base))->PID_CHECKSUM)
#define LIN_CH_DATA0(base)                      (((LIN_CH_Type *)(base))->DATA0)
#define LIN_CH_DATA1(base)                      (((LIN_CH_Type *)(base))->DATA1)
#define LIN_CH_INTR(base)                       (((LIN_CH_Type *)(base))->INTR)
#define LIN_CH_INTR_SET(base)                   (((LIN_CH_Type *)(base))->INTR_SET)
#define LIN_CH_INTR_MASK(base)                  (((LIN_CH_Type *)(base))->INTR_MASK)
#define LIN_CH_INTR_MASKED(base)                (((LIN_CH_Type *)(base))->INTR_MASKED)

#define LIN_ERROR_CTL(base)                     (((LIN_Type *)(base))->ERROR_CTL)
#define LIN_TEST_CTL(base)                      (((LIN_Type *)(base))->TEST_CTL)
#endif /* CY_IP_MXLIN */

/*******************************************************************************
*                MXKEYSCAN
*******************************************************************************/
#if defined (CY_IP_MXKEYSCAN)

#define KEYSCAN_CTL(base)                       (((MXKEYSCAN_Type *)(base))->KEYSCAN_CTL)
#define KEYSCAN_DEBOUNCE(base)                  (((MXKEYSCAN_Type *)(base))->DEBOUNCE)
#define KEYSCAN_KEYFIFO_CNT(base)               (((MXKEYSCAN_Type *)(base))->KEYFIFO_CNT)
#define KEYSCAN_KEYFIFO(base)                   (((MXKEYSCAN_Type *)(base))->KEYFIFO)
#define KEYSCAN_MIA_CTL(base)                   (((MXKEYSCAN_Type *)(base))->MIA_CTL)
#define KEYSCAN_MIA_STATUS(base)                (((MXKEYSCAN_Type *)(base))->MIA_STATUS)
#define KEYSCAN_KSI_USED(base)                  (((MXKEYSCAN_Type *)(base))->KSI_USED)
#define KEYSCAN_INTR(base)                      (((MXKEYSCAN_Type *)(base))->INTR)
#define KEYSCAN_INTR_SET(base)                  (((MXKEYSCAN_Type *)(base))->INTR_SET)
#define KEYSCAN_INTR_MASK(base)                 (((MXKEYSCAN_Type *)(base))->INTR_MASK)
#define KEYSCAN_INTR_MASKED(base)               (((MXKEYSCAN_Type *)(base))->INTR_MASKED)

#endif /* CY_IP_MXKEYSCAN */

#define MPC_Type                                 RAMC_MPC_Type
#ifdef RAMC_MPC_PC_NR
#define MPC_PC_NR                                RAMC_MPC_PC_NR
#else
#define MPC_PC_NR                                RAMC0_MPC_PC_NR
#endif

/*******************************************************************************
*                MS_CTL for SYSCPUSS
*******************************************************************************/
#if CY_IP_MXCM33_VERSION_MINOR == (0u)

#define MS_CTL_PC_CTL_VX(index)          (((MS_CTL_2_0_Type*) MS_CTL_2_0_BASE)->MS[(index)].CTL)
#define MS_CTL_PC_VAL_VX(index)          (((MS_CTL_2_0_Type*) MS_CTL_2_0_BASE)->MS_PC[(index)].PC)
#define MS_CTL_PC_READ_MIRROR_VX(index)  (((MS_CTL_2_0_Type*) GET_NSALIAS_ADDRESS(MS_CTL_2_0_BASE))->MS_PC[(index)].PC_READ_MIR)
#define MS_CTL_CODE_MS0_MSC_ACG_CTL_VX   (((MS_CTL_2_0_Type*) MS_CTL_2_0_BASE)->CODE_MS0_MSC_ACG_CTL)
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_VX    (((MS_CTL_2_0_Type*) MS_CTL_2_0_BASE)->SYS_MS0_MSC_ACG_CTL)
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_VX    (((MS_CTL_2_0_Type*) MS_CTL_2_0_BASE)->SYS_MS1_MSC_ACG_CTL)
#define MS_CTL_EXP_MS_MSC_ACG_CTL_VX     (((MS_CTL_2_0_Type*) MS_CTL_2_0_BASE)->EXP_MS_MSC_ACG_CTL)
#define MS_CTL_DMAC0_MSC_ACG_CTL_VX      (((MS_CTL_2_0_Type*) MS_CTL_2_0_BASE)->DMAC0_MSC_ACG_CTL)
#define MS_CTL_DMAC1_MSC_ACG_CTL_VX      (((MS_CTL_2_0_Type*) MS_CTL_2_0_BASE)->DMAC1_MSC_ACG_CTL)

/* MS_CTL.CODE_MS0_MSC_ACG_CTL */
#define MS_CTL_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos   MS_CTL_2_0_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk   MS_CTL_2_0_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_CODE_MS0_MSC_ACG_CTL_SEC_RESP_VX_Pos        MS_CTL_2_0_CODE_MS0_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_CODE_MS0_MSC_ACG_CTL_SEC_RESP_VX_Msk        MS_CTL_2_0_CODE_MS0_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.SYS_MS0_MSC_ACG_CTL */
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos    MS_CTL_2_0_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk    MS_CTL_2_0_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_VX_Pos         MS_CTL_2_0_SYS_MS0_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_VX_Msk         MS_CTL_2_0_SYS_MS0_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.SYS_MS1_MSC_ACG_CTL */
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos    MS_CTL_2_0_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk    MS_CTL_2_0_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_VX_Pos         MS_CTL_2_0_SYS_MS1_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_VX_Msk         MS_CTL_2_0_SYS_MS1_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.EXP_MS_MSC_ACG_CTL */
#define MS_CTL_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos     MS_CTL_2_0_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk     MS_CTL_2_0_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_EXP_MS_MSC_ACG_CTL_SEC_RESP_VX_Pos          MS_CTL_2_0_EXP_MS_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_EXP_MS_MSC_ACG_CTL_SEC_RESP_VX_Msk          MS_CTL_2_0_EXP_MS_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.DMAC0_MSC_ACG_CTL */
#define MS_CTL_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos      MS_CTL_2_0_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk      MS_CTL_2_0_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_DMAC0_MSC_ACG_CTL_SEC_RESP_VX_Pos           MS_CTL_2_0_DMAC0_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_DMAC0_MSC_ACG_CTL_SEC_RESP_VX_Msk           MS_CTL_2_0_DMAC0_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.DMAC1_MSC_ACG_CTL */
#define MS_CTL_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos      MS_CTL_2_0_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk      MS_CTL_2_0_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_DMAC1_MSC_ACG_CTL_SEC_RESP_VX_Pos           MS_CTL_2_0_DMAC1_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_DMAC1_MSC_ACG_CTL_SEC_RESP_VX_Msk           MS_CTL_2_0_DMAC1_MSC_ACG_CTL_SEC_RESP_Msk

#else

#define MS_CTL_PC_CTL_VX(index)          (((MS_CTL_2_1_Type*) MS_CTL_2_1_BASE)->MS[(index)].CTL)
#define MS_CTL_PC_VAL_VX(index)          (((MS_CTL_2_1_Type*) MS_CTL_2_1_BASE)->MS_PC[(index)].PC)
#define MS_CTL_PC_READ_MIRROR_VX(index)  (((MS_CTL_2_1_Type*) GET_NSALIAS_ADDRESS(MS_CTL_2_1_BASE))->MS_PC[(index)].PC_READ_MIR)
#define MS_CTL_CODE_MS0_MSC_ACG_CTL_VX   (((MS_CTL_2_1_Type*) MS_CTL_2_1_BASE)->CODE_MS0_MSC_ACG_CTL)
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_VX    (((MS_CTL_2_1_Type*) MS_CTL_2_1_BASE)->SYS_MS0_MSC_ACG_CTL)
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_VX    (((MS_CTL_2_1_Type*) MS_CTL_2_1_BASE)->SYS_MS1_MSC_ACG_CTL)
#define MS_CTL_EXP_MS_MSC_ACG_CTL_VX     (((MS_CTL_2_1_Type*) MS_CTL_2_1_BASE)->EXP_MS_MSC_ACG_CTL)
#define MS_CTL_DMAC0_MSC_ACG_CTL_VX      (((MS_CTL_2_1_Type*) MS_CTL_2_1_BASE)->DMAC0_MSC_ACG_CTL)
#define MS_CTL_DMAC1_MSC_ACG_CTL_VX      (((MS_CTL_2_1_Type*) MS_CTL_2_1_BASE)->DMAC1_MSC_ACG_CTL)

/* MS_CTL.CODE_MS0_MSC_ACG_CTL */
#define MS_CTL_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos   MS_CTL_2_1_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk   MS_CTL_2_1_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_CODE_MS0_MSC_ACG_CTL_SEC_RESP_VX_Pos        MS_CTL_2_1_CODE_MS0_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_CODE_MS0_MSC_ACG_CTL_SEC_RESP_VX_Msk        MS_CTL_2_1_CODE_MS0_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.SYS_MS0_MSC_ACG_CTL */
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos    MS_CTL_2_1_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk    MS_CTL_2_1_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_VX_Pos         MS_CTL_2_1_SYS_MS0_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_VX_Msk         MS_CTL_2_1_SYS_MS0_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.SYS_MS1_MSC_ACG_CTL */
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos    MS_CTL_2_1_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk    MS_CTL_2_1_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_VX_Pos         MS_CTL_2_1_SYS_MS1_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_VX_Msk         MS_CTL_2_1_SYS_MS1_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.EXP_MS_MSC_ACG_CTL */
#define MS_CTL_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos     MS_CTL_2_1_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk     MS_CTL_2_1_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_EXP_MS_MSC_ACG_CTL_SEC_RESP_VX_Pos          MS_CTL_2_1_EXP_MS_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_EXP_MS_MSC_ACG_CTL_SEC_RESP_VX_Msk          MS_CTL_2_1_EXP_MS_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.DMAC0_MSC_ACG_CTL */
#define MS_CTL_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos      MS_CTL_2_1_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk      MS_CTL_2_1_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_DMAC0_MSC_ACG_CTL_SEC_RESP_VX_Pos           MS_CTL_2_1_DMAC0_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_DMAC0_MSC_ACG_CTL_SEC_RESP_VX_Msk           MS_CTL_2_1_DMAC0_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.DMAC1_MSC_ACG_CTL */
#define MS_CTL_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos      MS_CTL_2_1_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk      MS_CTL_2_1_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_DMAC1_MSC_ACG_CTL_SEC_RESP_VX_Pos           MS_CTL_2_1_DMAC1_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_DMAC1_MSC_ACG_CTL_SEC_RESP_VX_Msk           MS_CTL_2_1_DMAC1_MSC_ACG_CTL_SEC_RESP_Msk

#endif

/*******************************************************************************
*                MS_CTL for APPCPUSS
*******************************************************************************/
#define MS_CTL_PC_CTL_V1(index)          (((MS_CTL_Type*) MS_CTL_BASE)->MS[(index)].CTL)
#define MS_CTL_PC_VAL_V1(index)          (((MS_CTL_Type*) MS_CTL_BASE)->MS_PC[(index)].PC)
#define MS_CTL_PC_READ_MIRROR_V1(index)  (((MS_CTL_Type*) MS_CTL_BASE)->MS_PC[(index)].PC_READ_MIR)
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_V1    (((MS_CTL_Type*) MS_CTL_BASE)->SYS_MS0_MSC_ACG_CTL)
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_V1    (((MS_CTL_Type*) MS_CTL_BASE)->SYS_MS1_MSC_ACG_CTL)
#define MS_CTL_AXIDMAC0_MSC_ACG_CTL_V1   (((MS_CTL_Type*) MS_CTL_BASE)->AXIDMAC0_MSC_ACG_CTL)
#define MS_CTL_AXIDMAC1_MSC_ACG_CTL_V1   (((MS_CTL_Type*) MS_CTL_BASE)->AXIDMAC1_MSC_ACG_CTL)
#define MS_CTL_AXI_MS0_MSC_ACG_CTL_V1    (((MS_CTL_Type*) MS_CTL_BASE)->AXI_MS0_MSC_ACG_CTL)
#define MS_CTL_AXI_MS1_MSC_ACG_CTL_V1    (((MS_CTL_Type*) MS_CTL_BASE)->AXI_MS1_MSC_ACG_CTL)
#define MS_CTL_AXI_MS2_MSC_ACG_CTL_V1    (((MS_CTL_Type*) MS_CTL_BASE)->AXI_MS2_MSC_ACG_CTL)
#define MS_CTL_AXI_MS3_MSC_ACG_CTL_V1    (((MS_CTL_Type*) MS_CTL_BASE)->AXI_MS3_MSC_ACG_CTL)
#define MS_CTL_EXP_MS0_MSC_ACG_CTL_V1    (((MS_CTL_Type*) MS_CTL_BASE)->EXP_MS0_MSC_ACG_CTL)
#define MS_CTL_EXP_MS1_MSC_ACG_CTL_V1    (((MS_CTL_Type*) MS_CTL_BASE)->EXP_MS1_MSC_ACG_CTL)
#define MS_CTL_EXP_MS2_MSC_ACG_CTL_V1    (((MS_CTL_Type*) MS_CTL_BASE)->EXP_MS2_MSC_ACG_CTL)
#define MS_CTL_EXP_MS3_MSC_ACG_CTL_V1    (((MS_CTL_Type*) MS_CTL_BASE)->EXP_MS3_MSC_ACG_CTL)

/* MS_CTL.SYS_MS0_MSC_ACG_CTL */
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos    MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk    MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_V1_Pos         MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk         MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.SYS_MS1_MSC_ACG_CTL */
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos    MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk    MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_V1_Pos         MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk         MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.AXIDMAC0_MSC_ACG_CTL */
#define MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos   MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk   MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_V1_Pos        MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_V1_Msk        MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.AXIDMAC1_MSC_ACG_CTL */
#define MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos   MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk   MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_V1_Pos        MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_V1_Msk        MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.AXI_MS0_MSC_ACG_CTL */
#define MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos    MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk    MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_V1_Pos         MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk         MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.AXI_MS1_MSC_ACG_CTL */
#define MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos    MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk    MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_V1_Pos         MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk         MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.AXI_MS2_MSC_ACG_CTL */
#define MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos    MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk    MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_V1_Pos         MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_V1_Msk         MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.AXI_MS3_MSC_ACG_CTL */
#define MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos    MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk    MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_V1_Pos         MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_V1_Msk         MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.EXP_MS0_MSC_ACG_CTL */
#define MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos    MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk    MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_V1_Pos         MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk         MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.EXP_MS1_MSC_ACG_CTL */
#define MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos    MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk    MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_V1_Pos         MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk         MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.EXP_MS2_MSC_ACG_CTL */
#define MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos    MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk    MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_V1_Pos         MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_V1_Msk         MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_Msk
/* MS_CTL.EXP_MS3_MSC_ACG_CTL */
#define MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos    MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_Pos
#define MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk    MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_Msk
#define MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_V1_Pos         MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_Pos
#define MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_V1_Msk         MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_Msk

/*******************************************************************************
*                MXSRAMC
*******************************************************************************/
#define CY_MXSRAMC_INST(sramNum)                        ((sramNum == 0) ? RAMC0 : RAMC1)
#define MXSRAMC_STATUS(sramNum)                         (CY_MXSRAMC_INST(sramNum)->STATUS)
#define MXSRAMC_PWR_MACRO_CTL(sramNum)                  (CY_MXSRAMC_INST(sramNum)->PWR_MACRO_CTL)
#define MXSRAMC_PWR_MACRO_CTL_LOCK(sramNum)             (CY_MXSRAMC_INST(sramNum)->PWR_MACRO_CTL_LOCK)


#define MXSRAMC_PWR_MACRO_CTL_LOCK_CLR0                 0X00000001U
#define MXSRAMC_PWR_MACRO_CTL_LOCK_CLR1                 0X00000002U
#define MXSRAMC_PWR_MACRO_CTL_LOCK_SET01                0X00000003U
#define CY_CPUSS_RAMC_MACRO_NR(sramNum)                 ((((uint32_t)(sramNum)) == 0U)? CPUSS_RAMC0_MACRO_NR : CPUSS_RAMC1_MACRO_NR)

/*******************************************************************************
*                MXSOCMEM
*******************************************************************************/
#define CY_SOCMEM_PARTITION_NR                          (SOCMEM_SRAM_PARTITION_NR)

#define SOCMEM_PWR_PARTITION_CTL_LOCK_CLR0              0X00000001U
#define SOCMEM_PWR_PARTITION_CTL_LOCK_CLR1              0X00000002U
#define SOCMEM_PWR_PARTITION_CTL_LOCK_SET01             0X00000003U


#define SOCMEM_PWR_PARTITION_CTL(partNum)               (((SOCMEM_Type *) SOCMEM)->PWR_PARTITION_CTL[partNum])
#define SOCMEM_PWR_PARTITION_CTL_LOCK                   (((SOCMEM_Type *) SOCMEM)->PWR_PARTITION_CTL_LOCK)
#define SOCMEM_PWR_STATUS                               (((SOCMEM_Type *) SOCMEM)->PWR_STATUS)


/*******************************************************************************
*                PPC
*******************************************************************************/

#define PPC_IS_VALID(ipInst, regionID)                  ((((ipInst) == PPC0) && ((regionID) <= (uint32_t)PROT_PERI0_END)) || \
                                                         (((ipInst) == PPC1) && ((regionID) >= (uint32_t)PROT_PERI1_START)   \
                                                                             && ((regionID) <= (uint32_t)PROT_PERI1_END))? true : false)

#define PPC_REGION_GET_ACTUAL(ipInst, regionID)         (((ipInst) == PPC1) ? ((regionID) & ~(PROT_PERI1_START)) : (regionID))

/*******************************************************************************
*                CRYPTO
*******************************************************************************/

/* The CRYPTO internal-memory buffer-size in 32-bit words. */
#define CY_CRYPTO_MEM_BUFF_SIZE_U32         (1024U)

/* Redirect to Crypto IP macros. Crypto IP macros don't have CPUSS_ prefix */
#define CPUSS_CRYPTO_ECC_PRESENT CRYPTO_ECC_PRESENT
#define CPUSS_CRYPTO_ECC_ADDR_PRESENT CRYPTO_ECC_ADDR_PRESENT
#define CPUSS_CRYPTO_AES CRYPTO_AES
#define CPUSS_CRYPTO_DES CRYPTO_DES
#define CPUSS_CRYPTO_CHACHA CRYPTO_CHACHA
#define CPUSS_CRYPTO_PR CRYPTO_PR
#define CPUSS_CRYPTO_SHA1 CRYPTO_SHA1
#define CPUSS_CRYPTO_SHA2 CRYPTO_SHA2
#define CPUSS_CRYPTO_SHA3 CRYPTO_SHA3
#define CPUSS_CRYPTO_CRC CRYPTO_CRC
#define CPUSS_CRYPTO_TR CRYPTO_TR
#define CPUSS_CRYPTO_VU CRYPTO_VU
#define CPUSS_CRYPTO_GCM CRYPTO_GCM

/*******************************************************************************
*                MXCM33
*******************************************************************************/
#define MXCM33_CM33_STATUS                     (((MXCM33_Type*) MXCM33_BASE)->CM33_STATUS)

/*******************************************************************************
*                MXCM55
*******************************************************************************/
#define MXCM55_CM55_STATUS                     (((MXCM55_Type*) MXCM55_BASE)->CM55_STATUS)


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.6')

#endif /* CY_DEVICE_H_ */

/* [] END OF FILE */
