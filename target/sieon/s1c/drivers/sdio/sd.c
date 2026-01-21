/**
 *******************************************************************************
 * @file  sd.c
 * @brief This file provides firmware functions to manage the Secure Digital(SD).
 @verbatim
   Change Logs:
   Date             Author          Notes
   2022-03-31       CDT             First version
   2023-01-15       CDT             Modify the error of CSD parameter calculation
   2023-09-30       CDT             Rename function SDMMC_ACMD41_SendOperatCond to SDMMC_ACMD41_SendOperateCond
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2022-2025, wlhc Semiconductor Co., Ltd. All rights reserved.
 *
 * This software component is licensed by WLHC under BSD 3-Clause license
 * (the "License"); You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                    opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "sd.h"
#include "wl32_ll.h"

/**
 * @addtogroup LL_SDIOC_LIB
 * @{
 */

/**
 * @defgroup SDIOC_SD_Card SDIOC SD Card
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup SD_Local_Macros SD Local Macros
 * @{
 */

/* Block size is 512 bytes */
#define SD_CARD_BLOCK_SIZE                      (512U)

/* Switch to high speed mode */
#define SD_SET_FUNC_HIGH_SPEED                  (0x80FFFF01UL)
#define SD_CMD6_RESULT_FUNC_GRP_BIT1            (0x0002U)

/**
 * @}
 */

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static void SD_DmaTransConfig(const stc_sd_handle_t *handle, uint8_t u8Ch, uint32_t u32SrcAddr,
                              uint32_t u32DestAddr, uint16_t u16BlockSize, uint16_t u16TransCount);
static int32_t SD_GetSCR(stc_sd_handle_t *handle, uint32_t pu32SCR[]);
static int32_t SD_SetSpeedMode(stc_sd_handle_t *handle);
static int32_t SD_SetBusWidth(stc_sd_handle_t *handle);
static int32_t SD_InitCard(stc_sd_handle_t *handle);
static int32_t SD_PowerCmd(stc_sd_handle_t *handle, en_functional_state_t enNewState);
static int32_t SD_GetCurrCardStatus(stc_sd_handle_t *handle, uint32_t *pu32CardStatus);
static int32_t SD_GetCurrSDStatus(stc_sd_handle_t *handle, uint32_t *pu32SDStatus);
static int32_t SD_ReadWriteFifo(stc_sd_handle_t *handle, const stc_sdioc_data_config_t *pstcDataConfig,
                                uint8_t pu8Data[], uint32_t u32Timeout);
static int32_t SD_ExtractCardCSD(stc_sd_handle_t *handle);

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @defgroup SD_Global_Functions SD Global Functions
 * @{
 */

/**
 * @brief  De-Initialize SD.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @retval int32_t:
 *           - LL_OK: SD De-Initialize success
 *           - LL_ERR_INVD_PARAM: handle == NULL
 */
int32_t SD_DeInit(stc_sd_handle_t *handle)
{
    int32_t i32Ret = LL_OK;

    if (NULL == handle) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        /* Set SD power state to off */
        (void)SD_PowerCmd(handle, DISABLE);
        handle->u32ErrorCode = SDMMC_ERR_NONE;
    }

    return i32Ret;
}

/**
 * @brief  Initialize SD.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @retval int32_t:
 *           - LL_OK: SD Initialize success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 *           - LL_ERR_INVD_MD: The Bus clock frequency is too high
 */
#if 0
int32_t SD_Init(stc_sd_handle_t *handle)
{
    int32_t i32Ret;
    stc_sdioc_init_t stcSdInit;
    uint16_t u16ClkDiv = 0U;

    if (NULL == handle) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        /* Check the SDIOC clock is over 25Mhz or 50Mhz */
        i32Ret = SDIOC_VerifyClockDiv(SDIOC_MD_SD, handle->stcSdiocInit.u8SpeedMode, handle->stcSdiocInit.u16ClockDiv);
        if (LL_OK != i32Ret) {
            return LL_ERR_INVD_MD;
        }

        /* Default SDIOC configuration for SD card initialization */
        (void)SDIOC_StructInit(&stcSdInit);
        i32Ret = SDIOC_GetOptimumClockDiv(SDIOC_OUTPUT_CLK_FREQ_400K, &u16ClkDiv);
        if (LL_OK != i32Ret) {
            return LL_ERR_INVD_MD;
        }
        stcSdInit.u16ClockDiv   = u16ClkDiv;
        stcSdInit.u32Mode       = handle->stcSdiocInit.u32Mode;
        stcSdInit.u8CardDetect  = handle->stcSdiocInit.u8CardDetect;
        /* Set Power State to ON */
        SDIOC_PowerCmd(handle->SDIOCx, ENABLE);
        /* Initialize SDIOC with default configure */
        (void)SDIOC_Init(handle->SDIOCx, &stcSdInit);
        /* Wait for the SDIOC to initialization */
        DDL_DelayMS(2U);

        /* Identify card operating voltage */
        i32Ret = SD_PowerCmd(handle, ENABLE);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
        /* Card initialization */
        i32Ret = SD_InitCard(handle);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
        /* Get SCR Register */
        i32Ret = SD_GetSCR(handle, handle->u32SCR);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
        /* Configure SD Bus width */
        i32Ret = SD_SetBusWidth(handle);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
        /* Configure SD High speed mode */
        i32Ret = SD_SetSpeedMode(handle);

        /* Initialize the error code */
        handle->u32ErrorCode = SDMMC_ERR_NONE;
        /* Initialize the SD operation */
        handle->u32Context = SD_CONTEXT_NONE;
    }

    return i32Ret;
}
#else
int32_t SD_Init(stc_sd_handle_t *handle)
{
  int32_t i32Ret;
  stc_sdioc_init_t stcSdInit;
  uint16_t u16ClkDiv = 0U;

  if (NULL == handle) {
    i32Ret = LL_ERR_INVD_PARAM;
  } else {
    CLK_SetClockDiv(CLK_BUS_CLK_ALL, \
                   (CLK_PCLK0_DIV1 | CLK_PCLK1_DIV4 | CLK_PCLK2_DIV4 | \
                    CLK_PCLK3_DIV4 | CLK_PCLK4_DIV2 | CLK_EXCLK_DIV2 | \
                    CLK_HCLK_DIV1));
    /* Check the SDIOC clock is over 25Mhz or 50Mhz */
    i32Ret = SDIOC_VerifyClockDiv(SDIOC_MD_SD, handle->stcSdiocInit.u8SpeedMode, handle->stcSdiocInit.u16ClockDiv);
    if (LL_OK != i32Ret) {
      CLK_SetClockDiv(CLK_BUS_CLK_ALL, \
                     (CLK_PCLK0_DIV1 | CLK_PCLK1_DIV2 | CLK_PCLK2_DIV4 | \
                      CLK_PCLK3_DIV4 | CLK_PCLK4_DIV2 | CLK_EXCLK_DIV2 | \
                      CLK_HCLK_DIV1));
      return LL_ERR_INVD_MD;
    }

    /* Default SDIOC configuration for SD card initialization */
    (void)SDIOC_StructInit(&stcSdInit);
    i32Ret = SDIOC_GetOptimumClockDiv(SDIOC_OUTPUT_CLK_FREQ_400K, &u16ClkDiv);
    if (LL_OK != i32Ret) {
      CLK_SetClockDiv(CLK_BUS_CLK_ALL, \
                     (CLK_PCLK0_DIV1 | CLK_PCLK1_DIV2 | CLK_PCLK2_DIV4 | \
                      CLK_PCLK3_DIV4 | CLK_PCLK4_DIV2 | CLK_EXCLK_DIV2 | \
                      CLK_HCLK_DIV1));
      return LL_ERR_INVD_MD;
    }
    stcSdInit.u16ClockDiv   = u16ClkDiv;
    stcSdInit.u32Mode       = handle->stcSdiocInit.u32Mode;
    stcSdInit.u8CardDetect  = handle->stcSdiocInit.u8CardDetect;
    /* Set Power State to ON */
    SDIOC_PowerCmd(handle->SDIOCx, ENABLE);
    /* Initialize SDIOC with default configure */
    (void)SDIOC_Init(handle->SDIOCx, &stcSdInit);
    /* Wait for the SDIOC to initialization */
    DDL_DelayMS(2U);

    /* Identify card operating voltage */
    i32Ret = SD_PowerCmd(handle, ENABLE);
    if (LL_OK != i32Ret) {
      CLK_SetClockDiv(CLK_BUS_CLK_ALL, \
                     (CLK_PCLK0_DIV1 | CLK_PCLK1_DIV2 | CLK_PCLK2_DIV4 | \
                      CLK_PCLK3_DIV4 | CLK_PCLK4_DIV2 | CLK_EXCLK_DIV2 | \
                      CLK_HCLK_DIV1));
      return i32Ret;
    }
    CLK_SetClockDiv(CLK_BUS_CLK_ALL, \
                   (CLK_PCLK0_DIV1 | CLK_PCLK1_DIV2 | CLK_PCLK2_DIV4 | \
                    CLK_PCLK3_DIV4 | CLK_PCLK4_DIV2 | CLK_EXCLK_DIV2 | \
                    CLK_HCLK_DIV1));
    /* Card initialization */
    i32Ret = SD_InitCard(handle);
    if (LL_OK != i32Ret) {
      return i32Ret;
    }
    /* Get SCR Register */
    i32Ret = SD_GetSCR(handle, handle->u32SCR);
    if (LL_OK != i32Ret) {
      return i32Ret;
    }
    /* Configure SD Bus width */
    i32Ret = SD_SetBusWidth(handle);
    if (LL_OK != i32Ret) {
      return i32Ret;
    }
    /* Configure SD High speed mode */
    i32Ret = SD_SetSpeedMode(handle);

    /* Initialize the error code */
    handle->u32ErrorCode = SDMMC_ERR_NONE;
    /* Initialize the SD operation */
    handle->u32Context = SD_CONTEXT_NONE;
  }
  return i32Ret;
}
#endif

/**
 * @brief  Get the current sd card state.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [out] peCardState            Pointer to a @ref en_sd_card_state_t enumeration
 * @retval int32_t:
 *           - LL_OK: Get sd card state success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or peCardState == NULL or
 *                                An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
int32_t SD_GetCardState(stc_sd_handle_t *handle, en_sd_card_state_t *peCardState)
{
    int32_t i32Ret;
    uint32_t u32Response = 0UL;

    if ((NULL == peCardState) || (NULL == handle)) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        i32Ret = SD_GetCurrCardStatus(handle, &u32Response);
        *peCardState = (en_sd_card_state_t)(uint32_t)((u32Response >> SDMMC_STATUS_CURR_STATE_POS) & 0x0FU);
    }

    return i32Ret;
}

/**
 * @brief  Get information of the card which CID register.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [out] pstcCardCID            Pointer to a @ref stc_sd_card_cid_t structure
 * @retval int32_t:
 *           - LL_OK: Get sd card CID register success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or pstcCardCID == NULL
 */
int32_t SD_GetCardCID(const stc_sd_handle_t *handle, stc_sd_card_cid_t *pstcCardCID)
{
    int32_t i32Ret = LL_OK;

    if ((NULL == pstcCardCID) || (NULL == handle)) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        pstcCardCID->u8ManufacturerID  = (uint8_t)((handle->u32CID[3] & 0xFF000000U) >> 24U);
        pstcCardCID->u16OemAppID       = (uint16_t)((handle->u32CID[3] & 0x00FFFF00U) >> 8U);
        pstcCardCID->u32ProductName1   = (uint32_t)(((handle->u32CID[3] & 0x000000FFU) << 24U) |
                                                    ((handle->u32CID[2] & 0xFFFFFF00U) >> 8U));
        pstcCardCID->u8ProductName2    = (uint8_t)(handle->u32CID[2] & 0x000000FFU);
        pstcCardCID->u8ProductRevision = (uint8_t)((handle->u32CID[1] & 0xFF000000U) >> 24U);
        pstcCardCID->u32ProductSN      = (uint32_t)(((handle->u32CID[1] & 0x00FFFFFFU) << 8U) |
                                                    ((handle->u32CID[0] & 0xFF000000U) >> 24U));
        pstcCardCID->u8Reserved1       = (uint8_t)((handle->u32CID[0] & 0x00F00000U) >> 20U);
        pstcCardCID->u16ManufactDate   = (uint16_t)((handle->u32CID[0] & 0x000FFF00U) >> 8U);
        pstcCardCID->u8CRCChecksum     = (uint8_t)((handle->u32CID[0] & 0x000000FEU) >> 1U);
        pstcCardCID->u8Reserved2       = 1U;
    }

    return i32Ret;
}

/**
 * @brief  Get information of the card which CSD register.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [out] pstcCardCSD            Pointer to a @ref stc_sd_card_csd_t structure
 * @retval int32_t:
 *           - LL_OK: Get sd card CSD register success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or pstcCardCSD == NULL
 */
int32_t SD_GetCardCSD(stc_sd_handle_t *handle, stc_sd_card_csd_t *pstcCardCSD)
{
    int32_t i32Ret = LL_OK;
    uint32_t u32Temp;

    if ((NULL == pstcCardCSD) || (NULL == handle)) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        u32Temp = (handle->u32CSD[3] & 0xFF000000U) >> 24U;
        pstcCardCSD->u8CSDStruct          = (uint8_t)((u32Temp & 0xC0U) >> 6U);
        pstcCardCSD->u8Reserved1          = 0U;
        pstcCardCSD->u8TAAC               = (uint8_t)((handle->u32CSD[3] & 0x00FF0000U) >> 16U);
        pstcCardCSD->u8NSAC               = (uint8_t)((handle->u32CSD[3] & 0x0000FF00U) >> 8U);
        pstcCardCSD->u8MaxBusClkFreq      = (uint8_t)(handle->u32CSD[3] & 0x000000FFU);
        pstcCardCSD->u16CardCmdClass      = (uint16_t)((handle->u32CSD[2] & 0xFFF00000U) >> 20U);
        pstcCardCSD->u8ReadBlockLen       = (uint8_t)((handle->u32CSD[2] & 0x000F0000U) >> 16U);

        u32Temp = (handle->u32CSD[2] & 0x0000F000U) >> 12U;
        pstcCardCSD->u8BlockReadPartial   = (uint8_t)((u32Temp & 0x08U) >> 3U);
        pstcCardCSD->u8WriteBlockMisalign = (uint8_t)((u32Temp & 0x04U) >> 2U);
        pstcCardCSD->u8ReadBlockMisalign  = (uint8_t)((u32Temp & 0x02U) >> 1U);
        pstcCardCSD->u8DSRImplement       = (uint8_t)((u32Temp & 0x01U) >> 0U);
        pstcCardCSD->u8Reserved2          = 0U;

        if (SD_CARD_SDSC == handle->stcSdCardInfo.u32CardType) {
            u32Temp = (uint8_t)((handle->u32CSD[1] & 0xFF000000U) >> 24U);
            pstcCardCSD->u32DeviceSize        = (uint32_t)(((handle->u32CSD[2] & 0x000003FFU) << 2U) |
                                                           ((u32Temp & 0xC0U) >> 6U));
            pstcCardCSD->u8MaxReadCurrVDDMin  = (uint8_t)((u32Temp & 0x38U) >> 3U);
            pstcCardCSD->u8MaxReadCurrVDDMax  = (uint8_t)(u32Temp & 0x07U);

            u32Temp = (uint8_t)((handle->u32CSD[1] & 0x00FF0000U) >> 16U);
            pstcCardCSD->u8MaxWriteCurrVDDMin = (uint8_t)((u32Temp & 0xE0U) >> 5U);
            pstcCardCSD->u8MaxWriteCurrVDDMax = (uint8_t)((u32Temp & 0x1CU) >> 2U);
            pstcCardCSD->u8DeviceSizeMul      = (uint8_t)((u32Temp & 0x03U) << 1U);

            u32Temp = (uint8_t)((handle->u32CSD[1] & 0x0000FF00U) >> 8U);
            pstcCardCSD->u8DeviceSizeMul     |= (uint8_t)((u32Temp & 0x80U) >> 7U);

            handle->stcSdCardInfo.u32BlockNum     = (pstcCardCSD->u32DeviceSize + 1U) ;
            handle->stcSdCardInfo.u32BlockNum     *= (1UL << (pstcCardCSD->u8DeviceSizeMul + 2U));
            handle->stcSdCardInfo.u32BlockSize    = 1UL << (pstcCardCSD->u8ReadBlockLen);
            if (handle->stcSdCardInfo.u32BlockSize >= 512U) {
                handle->stcSdCardInfo.u32LogBlockNum = handle->stcSdCardInfo.u32BlockNum *
                                                       (handle->stcSdCardInfo.u32BlockSize / 512U);
            } else {
                handle->stcSdCardInfo.u32LogBlockNum = (handle->stcSdCardInfo.u32BlockNum / 512U) *
                                                       handle->stcSdCardInfo.u32BlockSize;
            }
            handle->stcSdCardInfo.u32LogBlockSize = 512UL;
        } else if (SD_CARD_SDHC_SDXC == handle->stcSdCardInfo.u32CardType) {
            pstcCardCSD->u32DeviceSize = (uint32_t)(((handle->u32CSD[2] & 0x0000003FU) << 16U) |
                                                    ((handle->u32CSD[1] & 0xFFFF0000U) >> 16U));
            u32Temp = (uint8_t)((handle->u32CSD[1] & 0x0000FF00U) >> 8U);

            handle->stcSdCardInfo.u32BlockNum     = (pstcCardCSD->u32DeviceSize + 1U) * 1024U;
            handle->stcSdCardInfo.u32BlockSize    = 512U;
            handle->stcSdCardInfo.u32LogBlockNum  = handle->stcSdCardInfo.u32BlockNum;
            handle->stcSdCardInfo.u32LogBlockSize = handle->stcSdCardInfo.u32BlockSize;
        } else {
            handle->u32ErrorCode |= SDMMC_ERR_UNSUPPORT_FEATURE;
            return LL_ERR;
        }

        pstcCardCSD->u8EraseSingleBlockEn = (uint8_t)((u32Temp & 0x40U) >> 6U);
        pstcCardCSD->u8EraseSectorSize    = (uint8_t)((u32Temp & 0x3FU) << 1U);

        u32Temp = (uint8_t)(handle->u32CSD[1] & 0x000000FFU);
        pstcCardCSD->u8EraseSectorSize       |= (uint8_t)((u32Temp & 0x80U) >> 7U);
        pstcCardCSD->u8WriteProtectGroupSize = (uint8_t)(u32Temp & 0x7FU);

        u32Temp = (uint8_t)((handle->u32CSD[0] & 0xFF000000U) >> 24U);
        pstcCardCSD->u8WriteProtectGroupEn = (uint8_t)((u32Temp & 0x80U) >> 7U);
        pstcCardCSD->u8Reserved3           = 0U;
        pstcCardCSD->u8WriteSpeedFactor    = (uint8_t)((u32Temp & 0x1CU) >> 2U);
        pstcCardCSD->u8MaxWriteBlockLen    = (uint8_t)((u32Temp & 0x03U) << 2U);

        u32Temp = (uint8_t)((handle->u32CSD[0] & 0x00FF0000U) >> 16U);
        pstcCardCSD->u8MaxWriteBlockLen  |= (uint8_t)((u32Temp & 0xC0U) >> 6U);
        pstcCardCSD->u8WriteBlockPartial = (uint8_t)((u32Temp & 0x20U) >> 5U);
        pstcCardCSD->u8Reserved4         = 0U;

        u32Temp = (uint8_t)((handle->u32CSD[0] & 0x0000FF00U) >> 8U);
        pstcCardCSD->u8FileFormatGroup  = (uint8_t)((u32Temp & 0x80U) >> 7U);
        pstcCardCSD->u8CopyFlag         = (uint8_t)((u32Temp & 0x40U) >> 6U);
        pstcCardCSD->u8PermWriteProtect = (uint8_t)((u32Temp & 0x20U) >> 5U);
        pstcCardCSD->u8TempWriteProtect = (uint8_t)((u32Temp & 0x10U) >> 4U);
        pstcCardCSD->u8FileFormat       = (uint8_t)((u32Temp & 0x0CU) >> 2U);
        pstcCardCSD->u8Reserved5        = (uint8_t)(u32Temp & 0x03U);

        u32Temp = (uint8_t)(handle->u32CSD[0] & 0x000000FFU);
        pstcCardCSD->u8CRCChecksum = (uint8_t)((u32Temp & 0xFEU) >> 1U);
        pstcCardCSD->u8Reserved6   = 1U;
    }

    return i32Ret;
}

/**
 * @brief  Get the SD card status.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [out] pstcCardStatus         Pointer to a @ref stc_sd_card_status_t structure
 * @retval int32_t:
 *           - LL_OK: Get sd card status success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or pstcCardStatus == NULL or
 *                                An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
int32_t SD_GetCardStatus(stc_sd_handle_t *handle, stc_sd_card_status_t *pstcCardStatus)
{
    int32_t i32Ret;
    uint32_t u32SDStatus[16];

    if ((NULL == pstcCardStatus) || (NULL == handle)) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        i32Ret = SD_GetCurrSDStatus(handle, u32SDStatus);
        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        } else {
            pstcCardStatus->u8DataBusWidth       = (uint8_t)((u32SDStatus[0] & 0xC0U) >> 6U);
            pstcCardStatus->u8SecuredMode        = (uint8_t)((u32SDStatus[0] & 0x20U) >> 5U);
            pstcCardStatus->u16CardType          = (uint16_t)(((u32SDStatus[0] & 0x00FF0000U) >> 8U) |
                                                              ((u32SDStatus[0] & 0xFF000000U) >> 24U));
            pstcCardStatus->u32ProtectedAreaSize = (uint32_t)(((u32SDStatus[1] & 0x000000FFU) << 24U) |
                                                              ((u32SDStatus[1] & 0x0000FF00U) << 8U) |
                                                              ((u32SDStatus[1] & 0x00FF0000U) >> 8U)  |
                                                              ((u32SDStatus[1] & 0xFF000000U) >> 24U));
            pstcCardStatus->u8SpeedClass         = (uint8_t)((u32SDStatus[2] & 0xFFU));
            pstcCardStatus->u8PerformanceMove    = (uint8_t)((u32SDStatus[2] & 0xFF00U) >> 8U);
            pstcCardStatus->u8AllocUnitSize      = (uint8_t)((u32SDStatus[2] & 0xF00000U) >> 20U);
            pstcCardStatus->u16EraseSize         = (uint16_t)(((u32SDStatus[2] & 0xFF000000U) >> 16U) |
                                                              (u32SDStatus[3] & 0xFFU));
            pstcCardStatus->u8EraseTimeout       = (uint8_t)((u32SDStatus[3] & 0xFC00U) >> 10U);
            pstcCardStatus->u8EraseOffset        = (uint8_t)((u32SDStatus[3] & 0x0300U) >> 8U);
        }
    }

    return i32Ret;
}

/**
 * @brief  Get the SD card information.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [out] pstcCardInfo           Pointer to a @ref stc_sd_card_info_t structure
 * @retval int32_t:
 *           - LL_OK: Get sd card information success
 *           - LL_ERR_INVD_PARAM: handle == NULL or pstcCardInfo == NULL
 */
int32_t SD_GetCardInfo(stc_sd_handle_t *handle, stc_sd_card_info_t *pstcCardInfo)
{
    int32_t i32Ret = LL_OK;

    if ((NULL == pstcCardInfo) || (NULL == handle)) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        pstcCardInfo->u32CardType           = handle->stcSdCardInfo.u32CardType;
        pstcCardInfo->u32CardVersion        = handle->stcSdCardInfo.u32CardVersion;
        pstcCardInfo->u32Class              = handle->stcSdCardInfo.u32Class;
        pstcCardInfo->u32RelativeCardAddr   = handle->stcSdCardInfo.u32RelativeCardAddr;
        pstcCardInfo->u32BlockNum           = handle->stcSdCardInfo.u32BlockNum;
        pstcCardInfo->u32BlockSize          = handle->stcSdCardInfo.u32BlockSize;
        pstcCardInfo->u32LogBlockNum        = handle->stcSdCardInfo.u32LogBlockNum;
        pstcCardInfo->u32LogBlockSize       = handle->stcSdCardInfo.u32LogBlockSize;
    }

    return i32Ret;
}

/**
 * @brief  Get the SD error code.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [out] pu32ErrorCode          Pointer to the value of error code
 * @retval int32_t:
 *           - LL_OK: Get sd error code success
 *           - LL_ERR_INVD_PARAM: handle == NULL or pu32ErrorCode == NULL
 */
int32_t SD_GetErrorCode(const stc_sd_handle_t *handle, uint32_t *pu32ErrorCode)
{
    int32_t i32Ret = LL_OK;

    if ((NULL == pu32ErrorCode) || (NULL == handle)) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        *pu32ErrorCode = handle->u32ErrorCode;
    }

    return i32Ret;
}

/**
 * @brief  This function handles SD card interrupt request.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @retval None
 */
void SD_IRQHandler(stc_sd_handle_t *handle)
{
    int32_t i32Ret;
    en_sd_card_state_t enCardState = SD_CARD_STAT_IDLE;
    en_functional_state_t enTransState;
    en_functional_state_t enReceiveState;

    enTransState   = SDIOC_GetIntEnableState(handle->SDIOCx, SDIOC_INT_BWRSEN);
    enReceiveState = SDIOC_GetIntEnableState(handle->SDIOCx, SDIOC_INT_BRRSEN);
    /* Check for SDIO interrupt flags */
    if (RESET != SDIOC_GetIntStatus(handle->SDIOCx, SDIOC_INT_FLAG_TC)) {
        SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_FLAG_TC);
        SDIOC_IntCmd(handle->SDIOCx, (SDIOC_INT_DEBESEN | SDIOC_INT_DCESEN | SDIOC_INT_DTOESEN |
                                      SDIOC_INT_TCSEN   | SDIOC_INT_BRRSEN | SDIOC_INT_BWRSEN), DISABLE);
        if ((0UL != (handle->u32Context & SD_CONTEXT_INT)) || (0UL != (handle->u32Context & SD_CONTEXT_DMA))) {
            if ((0UL != (handle->u32Context & SD_CONTEXT_WR_MULTI_BLOCK)) ||
                (0UL != (handle->u32Context & SD_CONTEXT_RD_MULTI_BLOCK))) {
                /* Send stop transmission command */
                i32Ret = SDMMC_CMD12_StopTrans(handle->SDIOCx, &handle->u32ErrorCode);
                if (LL_OK != i32Ret) {
                    SD_ErrorCallback(handle);
                }
            }
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            if ((0UL != (handle->u32Context & SD_CONTEXT_WR_SINGLE_BLOCK)) ||
                (0UL != (handle->u32Context & SD_CONTEXT_WR_MULTI_BLOCK))) {
                SD_TxCompleteCallback(handle);
            } else {
                SD_RxCompleteCallback(handle);
            }
        }
    } else if ((RESET != SDIOC_GetHostStatus(handle->SDIOCx, SDIOC_HOST_FLAG_BWE)) &&
               (DISABLE != enTransState)) {
        (void)SDIOC_WriteBuffer(handle->SDIOCx, handle->pu8Buffer, 4UL);
        handle->pu8Buffer += 4U;
        handle->u32Len -= 4U;
        if (0UL == handle->u32Len) {
            SDIOC_IntCmd(handle->SDIOCx, SDIOC_INT_BWRSEN, DISABLE);
        }
    } else if ((RESET != SDIOC_GetHostStatus(handle->SDIOCx, SDIOC_HOST_FLAG_BRE)) &&
               (DISABLE != enReceiveState)) {
        (void)SDIOC_ReadBuffer(handle->SDIOCx, handle->pu8Buffer, 4UL);
        handle->pu8Buffer += 4U;
        handle->u32Len -= 4U;
        if (0UL == handle->u32Len) {
            SDIOC_IntCmd(handle->SDIOCx, SDIOC_INT_BRRSEN, DISABLE);
        }
    } else if (RESET != SDIOC_GetIntStatus(handle->SDIOCx, (SDIOC_INT_DEBESEN |
                                                            SDIOC_INT_DCESEN | SDIOC_INT_DTOESEN))) {
        /* Set LL_ERR code */
        if (RESET != SDIOC_GetIntStatus(handle->SDIOCx, SDIOC_INT_DEBESEN)) {
            handle->u32ErrorCode |= SDMMC_ERR_DATA_STOP_BIT;
        }
        if (RESET != SDIOC_GetIntStatus(handle->SDIOCx, SDIOC_INT_DCESEN)) {
            handle->u32ErrorCode |= SDMMC_ERR_DATA_CRC_FAIL;
        }
        if (RESET != SDIOC_GetIntStatus(handle->SDIOCx, SDIOC_INT_DTOESEN)) {
            handle->u32ErrorCode |= SDMMC_ERR_DATA_TIMEOUT;
        }

        /* Clear All flags */
        SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
        /* Disable all interrupts */
        SDIOC_IntCmd(handle->SDIOCx, (SDIOC_INT_DEBESEN | SDIOC_INT_DCESEN | SDIOC_INT_DTOESEN |
                                      SDIOC_INT_TCSEN   | SDIOC_INT_BRRSEN | SDIOC_INT_BWRSEN), DISABLE);
        if (0UL != (handle->u32Context & SD_CONTEXT_INT)) {
            SD_ErrorCallback(handle);
        } else if (0UL != (handle->u32Context & SD_CONTEXT_DMA)) {
            if (NULL != handle->DMAx) {
                /* Disable the DMA Channel */
                if ((0UL != (handle->u32Context & SD_CONTEXT_WR_SINGLE_BLOCK)) ||
                    (0UL != (handle->u32Context & SD_CONTEXT_WR_MULTI_BLOCK))) {
                    (void)DMA_ChCmd(handle->DMAx, handle->u8DmaTxCh, DISABLE);
                } else {
                    (void)DMA_ChCmd(handle->DMAx, handle->u8DmaRxCh, DISABLE);
                }
                /* Stop SD transfer */
                (void)SD_GetCardState(handle, &enCardState);
                handle->u32ErrorCode = SDMMC_ERR_NONE;
                if ((SD_CARD_STAT_TX_DATA == enCardState) || (SD_CARD_STAT_RX_DATA == enCardState)) {
                    /* Send stop transmission command */
                    (void)SDMMC_CMD12_StopTrans(handle->SDIOCx, &handle->u32ErrorCode);
                }
                SD_ErrorCallback(handle);
            }
        } else {
        }
    } else {
    }
}

/**
 * @brief  SD Tx completed callbacks
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @retval None
 */
__WEAKDEF void SD_TxCompleteCallback(stc_sd_handle_t *handle)
{
    (void)handle;
    /* NOTE: This function SD_TxCpltCallback can be implemented in the user file */
}

/**
 * @brief  SD Rx completed callbacks
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @retval None
 */
__WEAKDEF void SD_RxCompleteCallback(stc_sd_handle_t *handle)
{
    (void)handle;
    /* NOTE: This function SD_TxCpltCallback can be implemented in the user file */
}

/**
 * @brief  SD error callbacks
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @retval None
 */
__WEAKDEF void SD_ErrorCallback(stc_sd_handle_t *handle)
{
    (void)handle;
    /* NOTE: This function SD_TxCpltCallback can be implemented in the user file */
}

/**
 * @brief  Erases the specified memory area of the given SD card.
 * @note   This API should be followed by a check on the card state through SD_GetCardState().
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [in] u32BlockStartAddr       Start Block address
 * @param  [in] u32BlockEndAddr         End Block address
 * @retval int32_t:
 *           - LL_OK: Erases the SD card success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
int32_t SD_Erase(stc_sd_handle_t *handle, uint32_t u32BlockStartAddr, uint32_t u32BlockEndAddr)
{
    int32_t i32Ret;
    uint32_t u32CardSta = 0UL;

    if ((u32BlockEndAddr < u32BlockStartAddr) || (NULL == handle)) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        if (u32BlockEndAddr > (handle->stcSdCardInfo.u32LogBlockNum)) {
            handle->u32ErrorCode |= SDMMC_ERR_ADDR_OUT_OF_RANGE;
            return LL_ERR;
        }
        /* Check if the card command class supports erase command */
        if (0UL == ((handle->stcSdCardInfo.u32Class) & SDMMC_CSD_SUPPORT_CLASS5_ERASE)) {
            handle->u32ErrorCode |= SDMMC_ERR_REQ_NOT_APPLICABLE;
            return LL_ERR;
        }
        /* Check the lock status */
        i32Ret = SD_GetCurrCardStatus(handle, &u32CardSta);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
        if (SDMMC_STATUS_CARD_IS_LOCKED == (u32CardSta & SDMMC_STATUS_CARD_IS_LOCKED)) {
            handle->u32ErrorCode |= SDMMC_ERR_LOCK_UNLOCK_FAILED;
            return LL_ERR;
        }
        /* Get start and end block for high capacity cards */
        if (SD_CARD_SDHC_SDXC != handle->stcSdCardInfo.u32CardType) {
            u32BlockStartAddr *= 512U;
            u32BlockEndAddr   *= 512U;
        }

        /* According to sd-card spec 1.0 ERASE_GROUP_START (CMD32) and erase_group_end(CMD33) */
        if (SD_CARD_SECURED != handle->stcSdCardInfo.u32CardType) {
            /* Send CMD32 ERASE_WR_BLK_START with argument as addr  */
            i32Ret = SDMMC_CMD32_EraseBlockStartAddr(handle->SDIOCx, u32BlockStartAddr, &handle->u32ErrorCode);
            if (LL_OK != i32Ret) {
                SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
                return i32Ret;
            }
            /* Send CMD33 ERASE_WR_BLK_END with argument as addr  */
            i32Ret = SDMMC_CMD33_EraseBlockEndAddr(handle->SDIOCx, u32BlockEndAddr, &handle->u32ErrorCode);
            if (LL_OK != i32Ret) {
                SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
                return i32Ret;
            }
        }
        /* Send CMD38 ERASE */
        i32Ret = SDMMC_CMD38_Erase(handle->SDIOCx, 0U, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
    }

    return i32Ret;
}

/**
 * @brief  Reads block(s) from a specified address in a card.
 * @note   The Data transfer is managed by polling mode.
 * @note   This API should be followed by a check on the card state through SD_GetCardState().
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [in] u32BlockAddr            Block Address
 * @param  [in] u16BlockCount           Block Count
 * @param  [out] pu8Data                Pointer to the buffer that will contain the received data
 * @param  [in] u32Timeout              Read timeout value
 * @retval int32_t:
 *           - LL_OK: Read block(s) success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or pu8Data == NULL or
 *                                An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
int32_t SD_ReadBlocks(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount,
                      uint8_t *pu8Data, uint32_t u32Timeout)
{
    int32_t i32Ret;
    stc_sdioc_data_config_t stcDataCfg;

    if ((NULL == pu8Data) || (NULL == handle)) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        handle->u32ErrorCode = SDMMC_ERR_NONE;
        if ((u32BlockAddr + u16BlockCount) > (handle->stcSdCardInfo.u32LogBlockNum)) {
            handle->u32ErrorCode |= SDMMC_ERR_ADDR_OUT_OF_RANGE;
            return LL_ERR;
        }
        if (SD_CARD_SDHC_SDXC != handle->stcSdCardInfo.u32CardType) {
            u32BlockAddr *= 512U;
        }

        /* Set Block Size for Card */
        i32Ret = SDMMC_CMD16_SetBlockLength(handle->SDIOCx, SD_CARD_BLOCK_SIZE, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
        /* Configure the SD data transfer */
        stcDataCfg.u16BlockSize     = SD_CARD_BLOCK_SIZE;
        stcDataCfg.u16BlockCount    = u16BlockCount;
        stcDataCfg.u16TransDir      = SDIOC_TRANS_DIR_TO_HOST;
        stcDataCfg.u16AutoCmd12     = SDIOC_AUTO_SEND_CMD12_DISABLE;
        stcDataCfg.u16DataTimeout   = SDIOC_DATA_TIMEOUT_CLK_2E27;
        stcDataCfg.u16TransMode     = (u16BlockCount > 1U) ? (uint16_t)SDIOC_TRANS_MD_MULTI :
                                      (uint16_t)SDIOC_TRANS_MD_SINGLE;
        (void)SDIOC_ConfigData(handle->SDIOCx, &stcDataCfg);
        /* Read block(s) in polling mode */
        if (u16BlockCount > 1U) {
            handle->u32Context = SD_CONTEXT_RD_MULTI_BLOCK;
            /* Read Multi Block command */
            i32Ret = SDMMC_CMD18_ReadMultipleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        } else {
            handle->u32Context = SD_CONTEXT_RD_SINGLE_BLOCK;
            /* Read Single Block command */
            i32Ret = SDMMC_CMD17_ReadSingleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        }

        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
        /* Get data */
        i32Ret = SD_ReadWriteFifo(handle, &stcDataCfg, (uint8_t *)pu8Data, u32Timeout);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
    }

    return i32Ret;
}

/**
 * @brief  Write block(s) to a specified address in a card.
 * @note   The Data transfer is managed by polling mode.
 * @note   This API should be followed by a check on the card state through SD_GetCardState().
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [in] u32BlockAddr            Block Address
 * @param  [in] u16BlockCount           Block Count
 * @param  [in] pu8Data                 Pointer to the buffer that will contain the data to transmit
 * @param  [in] u32Timeout              Write timeout value
 * @retval int32_t:
 *           - LL_OK: Write block(s) success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or pu8Data == NULL or
 *                                An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
int32_t SD_WriteBlocks(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount,
                       uint8_t *pu8Data, uint32_t u32Timeout)
{
    int32_t i32Ret;
    stc_sdioc_data_config_t stcDataCfg;

    if ((NULL == pu8Data) || (NULL == handle)) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        handle->u32ErrorCode = SDMMC_ERR_NONE;
        if ((u32BlockAddr + u16BlockCount) > (handle->stcSdCardInfo.u32LogBlockNum)) {
            handle->u32ErrorCode |= SDMMC_ERR_ADDR_OUT_OF_RANGE;
            return LL_ERR;
        }
        if (SD_CARD_SDHC_SDXC != handle->stcSdCardInfo.u32CardType) {
            u32BlockAddr *= 512U;
        }

        /* Set Block Size for Card */
        i32Ret = SDMMC_CMD16_SetBlockLength(handle->SDIOCx, SD_CARD_BLOCK_SIZE, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
        /* Configure the SD data transfer */
        stcDataCfg.u16BlockSize     = SD_CARD_BLOCK_SIZE;
        stcDataCfg.u16BlockCount    = u16BlockCount;
        stcDataCfg.u16TransDir      = SDIOC_TRANS_DIR_TO_CARD;
        stcDataCfg.u16AutoCmd12     = SDIOC_AUTO_SEND_CMD12_DISABLE;
        stcDataCfg.u16DataTimeout   = SDIOC_DATA_TIMEOUT_CLK_2E27;
        stcDataCfg.u16TransMode     = (u16BlockCount > 1U) ? (uint16_t)SDIOC_TRANS_MD_MULTI :
                                      (uint16_t)SDIOC_TRANS_MD_SINGLE;
        (void)SDIOC_ConfigData(handle->SDIOCx, &stcDataCfg);
        /* Write block(s) in polling mode */
        if (u16BlockCount > 1U) {
            handle->u32Context = SD_CONTEXT_WR_MULTI_BLOCK;
            /* Write Multi Block command */
            i32Ret = SDMMC_CMD25_WriteMultipleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        } else {
            handle->u32Context = SD_CONTEXT_WR_SINGLE_BLOCK;
            /* Write Single Block command */
            i32Ret = SDMMC_CMD24_WriteSingleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        }

        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
        /* Get data */
        i32Ret = SD_ReadWriteFifo(handle, &stcDataCfg, (uint8_t *)pu8Data, u32Timeout);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
    }

    return i32Ret;
}

/**
 * @brief  Reads block(s) from a specified address in a card.
 * @note   The Data transfer is managed by interrupt mode.
 * @note   This API should be followed by a check on the card state through SD_GetCardState().
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [in] u32BlockAddr            Block Address
 * @param  [in] u16BlockCount           Block Count
 * @param  [out] pu8Data                Pointer to the buffer that will contain the received data
 * @retval int32_t:
 *           - LL_OK: Read block(s) success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or pu8Data == NULL or
 *                                An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
int32_t SD_ReadBlocks_INT(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount, uint8_t *pu8Data)
{
    int32_t i32Ret;
    stc_sdioc_data_config_t stcDataCfg;

    if ((NULL == pu8Data) || (NULL == handle)) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        handle->u32ErrorCode = SDMMC_ERR_NONE;
        if ((u32BlockAddr + u16BlockCount) > (handle->stcSdCardInfo.u32LogBlockNum)) {
            handle->u32ErrorCode |= SDMMC_ERR_ADDR_OUT_OF_RANGE;
            return LL_ERR;
        }
        if (SD_CARD_SDHC_SDXC != handle->stcSdCardInfo.u32CardType) {
            u32BlockAddr *= 512U;
        }

        /* Set Block Size for Card */
        i32Ret = SDMMC_CMD16_SetBlockLength(handle->SDIOCx, SD_CARD_BLOCK_SIZE, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
        /* Configure interrupt transfer parameters */
        handle->pu8Buffer = pu8Data;
        handle->u32Len = (uint32_t)u16BlockCount * SD_CARD_BLOCK_SIZE;
        SDIOC_ClearIntStatus(handle->SDIOCx, (SDIOC_INT_FLAG_BWR | SDIOC_INT_FLAG_BRR));
        /* Enable SDIOC interrupt */
        SDIOC_IntCmd(handle->SDIOCx, (SDIOC_INT_DEBESEN | SDIOC_INT_DCESEN | SDIOC_INT_DTOESEN |
                                      SDIOC_INT_TCSEN   | SDIOC_INT_BRRSEN), ENABLE);
        /* Configure the SD data transfer */
        stcDataCfg.u16BlockSize     = SD_CARD_BLOCK_SIZE;
        stcDataCfg.u16BlockCount    = u16BlockCount;
        stcDataCfg.u16TransDir      = SDIOC_TRANS_DIR_TO_HOST;
        stcDataCfg.u16AutoCmd12     = SDIOC_AUTO_SEND_CMD12_DISABLE;
        stcDataCfg.u16DataTimeout   = SDIOC_DATA_TIMEOUT_CLK_2E27;
        stcDataCfg.u16TransMode     = (u16BlockCount > 1U) ? (uint16_t)SDIOC_TRANS_MD_MULTI :
                                      (uint16_t)SDIOC_TRANS_MD_SINGLE;
        (void)SDIOC_ConfigData(handle->SDIOCx, &stcDataCfg);
        /* Read block(s) in interrupt mode */
        if (u16BlockCount > 1U) {
            handle->u32Context = SD_CONTEXT_RD_MULTI_BLOCK | SD_CONTEXT_INT;
            /* Read Multi Block command */
            i32Ret = SDMMC_CMD18_ReadMultipleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        } else {
            handle->u32Context = SD_CONTEXT_RD_SINGLE_BLOCK | SD_CONTEXT_INT;
            /* Read Single Block command */
            i32Ret = SDMMC_CMD17_ReadSingleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        }

        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
    }

    return i32Ret;
}

/**
 * @brief  Write block(s) to a specified address in a card.
 * @note   The Data transfer is managed by interrupt mode.
 * @note   This API should be followed by a check on the card state through SD_GetCardState().
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [in] u32BlockAddr            Block Address
 * @param  [in] u16BlockCount           Block Count
 * @param  [in] pu8Data                 Pointer to the buffer that will contain the data to transmit
 * @retval int32_t:
 *           - LL_OK: Write block(s) success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or pu8Data == NULL or
 *                                An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
int32_t SD_WriteBlocks_INT(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount, uint8_t *pu8Data)
{
    int32_t i32Ret;
    stc_sdioc_data_config_t stcDataCfg;

    if ((NULL == pu8Data) || (NULL == handle)) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        handle->u32ErrorCode = SDMMC_ERR_NONE;
        if ((u32BlockAddr + u16BlockCount) > (handle->stcSdCardInfo.u32LogBlockNum)) {
            handle->u32ErrorCode |= SDMMC_ERR_ADDR_OUT_OF_RANGE;
            return LL_ERR;
        }
        if (SD_CARD_SDHC_SDXC != handle->stcSdCardInfo.u32CardType) {
            u32BlockAddr *= 512U;
        }

        /* Set Block Size for Card */
        i32Ret = SDMMC_CMD16_SetBlockLength(handle->SDIOCx, SD_CARD_BLOCK_SIZE, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
        /* Configure interrupt transfer parameters */
        handle->pu8Buffer = pu8Data;
        handle->u32Len = (uint32_t)u16BlockCount * SD_CARD_BLOCK_SIZE;
        SDIOC_ClearIntStatus(handle->SDIOCx, (SDIOC_INT_FLAG_BWR | SDIOC_INT_FLAG_BRR));
        /* Enable SDIOC interrupt */
        SDIOC_IntCmd(handle->SDIOCx, (SDIOC_INT_DEBESEN | SDIOC_INT_DCESEN | SDIOC_INT_DTOESEN |
                                      SDIOC_INT_TCSEN   | SDIOC_INT_BWRSEN), ENABLE);
        /* Configure the SD data transfer */
        stcDataCfg.u16BlockSize     = SD_CARD_BLOCK_SIZE;
        stcDataCfg.u16BlockCount    = u16BlockCount;
        stcDataCfg.u16TransDir      = SDIOC_TRANS_DIR_TO_CARD;
        stcDataCfg.u16AutoCmd12     = SDIOC_AUTO_SEND_CMD12_DISABLE;
        stcDataCfg.u16DataTimeout   = SDIOC_DATA_TIMEOUT_CLK_2E27;
        stcDataCfg.u16TransMode     = (u16BlockCount > 1U) ? (uint16_t)SDIOC_TRANS_MD_MULTI :
                                      (uint16_t)SDIOC_TRANS_MD_SINGLE;
        (void)SDIOC_ConfigData(handle->SDIOCx, &stcDataCfg);
        /* Write block(s) in interrupt mode */
        if (u16BlockCount > 1U) {
            handle->u32Context = SD_CONTEXT_WR_MULTI_BLOCK | SD_CONTEXT_INT;
            /* Write Multi Block command */
            i32Ret = SDMMC_CMD25_WriteMultipleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        } else {
            handle->u32Context = SD_CONTEXT_WR_SINGLE_BLOCK | SD_CONTEXT_INT;
            /* Write Single Block command */
            i32Ret = SDMMC_CMD24_WriteSingleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        }

        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
    }

    return i32Ret;
}

/**
 * @brief  Reads block(s) from a specified address in a card.
 * @note   The Data transfer is managed by DMA mode.
 * @note   This API should be followed by a check on the card state through SD_GetCardState().
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [in] u32BlockAddr            Block Address
 * @param  [in] u16BlockCount           Block Count
 * @param  [out] pu8Data                Pointer to the buffer that will contain the received data
 * @retval int32_t:
 *           - LL_OK: Read block(s) success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or pu8Data == NULL or NULL == handle->DMAx or
 *                                    An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
int32_t SD_ReadBlocks_DMA(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount, uint8_t *pu8Data)
{
    int32_t i32Ret;
    stc_sdioc_data_config_t stcDataCfg;

    if ((NULL == pu8Data) || (NULL == handle) || (NULL == handle->DMAx) || (0U != ((uint32_t)pu8Data % 4U))) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        handle->u32ErrorCode = SDMMC_ERR_NONE;
        if ((u32BlockAddr + u16BlockCount) > (handle->stcSdCardInfo.u32LogBlockNum)) {
            handle->u32ErrorCode |= SDMMC_ERR_ADDR_OUT_OF_RANGE;
            return LL_ERR;
        }
        if (SD_CARD_SDHC_SDXC != handle->stcSdCardInfo.u32CardType) {
            u32BlockAddr *= 512U;
        }

        /* Set Block Size for Card */
        i32Ret = SDMMC_CMD16_SetBlockLength(handle->SDIOCx, SD_CARD_BLOCK_SIZE, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
        /* Enable SDIOC transfer complete and errors interrupt */
        SDIOC_IntCmd(handle->SDIOCx, (SDIOC_INT_TCSEN  | SDIOC_INT_DEBESEN |
                                      SDIOC_INT_DCESEN | SDIOC_INT_DTOESEN), ENABLE);
        /* Configure DMA parameters */
        SD_DmaTransConfig(handle, handle->u8DmaRxCh, (uint32_t)(&handle->SDIOCx->BUF0), (uint32_t)pu8Data,
                          (SD_CARD_BLOCK_SIZE / 4U), u16BlockCount);
        /* Enable the DMA Channel */
        (void)DMA_ChCmd(handle->DMAx, handle->u8DmaRxCh, ENABLE);
        /* Configure the SD data transfer */
        stcDataCfg.u16BlockSize     = SD_CARD_BLOCK_SIZE;
        stcDataCfg.u16BlockCount    = u16BlockCount;
        stcDataCfg.u16TransDir      = SDIOC_TRANS_DIR_TO_HOST;
        stcDataCfg.u16AutoCmd12     = SDIOC_AUTO_SEND_CMD12_DISABLE;
        stcDataCfg.u16DataTimeout   = SDIOC_DATA_TIMEOUT_CLK_2E27;
        stcDataCfg.u16TransMode     = (u16BlockCount > 1U) ? (uint16_t)SDIOC_TRANS_MD_MULTI :
                                      (uint16_t)SDIOC_TRANS_MD_SINGLE;
        (void)SDIOC_ConfigData(handle->SDIOCx, &stcDataCfg);
        /* Read block(s) in DMA mode */
        if (u16BlockCount > 1U) {
            handle->u32Context = SD_CONTEXT_RD_MULTI_BLOCK | SD_CONTEXT_DMA;
            /* Read Multi Block command */
            i32Ret = SDMMC_CMD18_ReadMultipleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        } else {
            handle->u32Context = SD_CONTEXT_RD_SINGLE_BLOCK | SD_CONTEXT_DMA;
            /* Read Single Block command */
            i32Ret = SDMMC_CMD17_ReadSingleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        }

        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
    }

    return i32Ret;
}

/**
 * @brief  Write block(s) to a specified address in a card.
 * @note   The Data transfer is managed by DMA mode.
 * @note   This API should be followed by a check on the card state through SD_GetCardState().
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [in] u32BlockAddr            Block Address
 * @param  [in] u16BlockCount           Block Count
 * @param  [in] pu8Data                 Pointer to the buffer that will contain the data to transmit
 * @retval int32_t:
 *           - LL_OK: Write block(s) success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or pu8Data == NULL or NULL == handle->DMAx or
 *                                An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
int32_t SD_WriteBlocks_DMA(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount, uint8_t *pu8Data)
{
    int32_t i32Ret;
    stc_sdioc_data_config_t stcDataCfg;

    if ((NULL == pu8Data) || (NULL == handle) || (NULL == handle->DMAx) || (0U != ((uint32_t)pu8Data % 4U))) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        handle->u32ErrorCode = SDMMC_ERR_NONE;
        if ((u32BlockAddr + u16BlockCount) > (handle->stcSdCardInfo.u32LogBlockNum)) {
            handle->u32ErrorCode |= SDMMC_ERR_ADDR_OUT_OF_RANGE;
            return LL_ERR;
        }
        if (SD_CARD_SDHC_SDXC != handle->stcSdCardInfo.u32CardType) {
            u32BlockAddr *= 512U;
        }

        /* Set Block Size for Card */
        i32Ret = SDMMC_CMD16_SetBlockLength(handle->SDIOCx, SD_CARD_BLOCK_SIZE, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
        /* Enable SDIOC transfer complete and errors interrupt */
        SDIOC_IntCmd(handle->SDIOCx, (SDIOC_INT_TCSEN  | SDIOC_INT_DEBESEN |
                                      SDIOC_INT_DCESEN | SDIOC_INT_DTOESEN), ENABLE);
        /* Configure DMA parameters */
        SD_DmaTransConfig(handle, handle->u8DmaTxCh, (uint32_t)pu8Data, (uint32_t)(&handle->SDIOCx->BUF0),
                          (SD_CARD_BLOCK_SIZE / 4U), u16BlockCount);
        /* Enable the DMA Channel */
        (void)DMA_ChCmd(handle->DMAx, handle->u8DmaTxCh, ENABLE);
        /* Configure the SD data transfer */
        stcDataCfg.u16BlockSize     = SD_CARD_BLOCK_SIZE;
        stcDataCfg.u16BlockCount    = u16BlockCount;
        stcDataCfg.u16TransDir      = SDIOC_TRANS_DIR_TO_CARD;
        stcDataCfg.u16AutoCmd12     = SDIOC_AUTO_SEND_CMD12_DISABLE;
        stcDataCfg.u16DataTimeout   = SDIOC_DATA_TIMEOUT_CLK_2E27;
        stcDataCfg.u16TransMode     = (u16BlockCount > 1U) ? (uint16_t)SDIOC_TRANS_MD_MULTI :
                                      (uint16_t)SDIOC_TRANS_MD_SINGLE;
        (void)SDIOC_ConfigData(handle->SDIOCx, &stcDataCfg);
        /* Write block(s) in DMA mode */
        if (u16BlockCount > 1U) {
            handle->u32Context = SD_CONTEXT_WR_MULTI_BLOCK | SD_CONTEXT_DMA;
            /* Write Multi Block command */
            i32Ret = SDMMC_CMD25_WriteMultipleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        } else {
            handle->u32Context = SD_CONTEXT_WR_SINGLE_BLOCK | SD_CONTEXT_DMA;
            /* Write Single Block command */
            i32Ret = SDMMC_CMD24_WriteSingleBlock(handle->SDIOCx, u32BlockAddr, &handle->u32ErrorCode);
        }

        if (LL_OK != i32Ret) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return i32Ret;
        }
    }

    return i32Ret;
}

/**
 * @brief  Abort the current transfer and disable the SD.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @retval int32_t:
 *           - LL_OK: Abort transfer success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: handle == NULL or
 *                                An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
int32_t SD_Abort(stc_sd_handle_t *handle)
{
    int32_t i32Ret = LL_OK;
    en_sd_card_state_t enCardState = SD_CARD_STAT_IDLE;

    if (NULL == handle) {
        i32Ret = LL_ERR_INVD_PARAM;
    } else {
        /* Disable All interrupts */
        SDIOC_IntCmd(handle->SDIOCx, (SDIOC_INT_DEBESEN | SDIOC_INT_DCESEN | SDIOC_INT_DTOESEN |
                                      SDIOC_INT_TCSEN   | SDIOC_INT_BRRSEN | SDIOC_INT_BWRSEN), DISABLE);
        /* Clear All flags */
        SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);

        if (0UL != (handle->u32Context & SD_CONTEXT_DMA)) {
            if (NULL != handle->DMAx) {
                /* Disable the DMA Channel */
                if ((0UL != (handle->u32Context & SD_CONTEXT_WR_SINGLE_BLOCK)) ||
                    (0UL != (handle->u32Context & SD_CONTEXT_WR_MULTI_BLOCK))) {
                    (void)DMA_ChCmd(handle->DMAx, handle->u8DmaTxCh, DISABLE);
                } else {
                    (void)DMA_ChCmd(handle->DMAx, handle->u8DmaRxCh, DISABLE);
                }
            }
        }
        /* Stop SD transfer */
        (void)SD_GetCardState(handle, &enCardState);
        handle->u32ErrorCode = SDMMC_ERR_NONE;
        if ((SD_CARD_STAT_TX_DATA == enCardState) || (SD_CARD_STAT_RX_DATA == enCardState)) {
            /* Send stop transmission command */
            (void)SDMMC_CMD12_StopTrans(handle->SDIOCx, &handle->u32ErrorCode);
        }
    }

    return i32Ret;
}

/**
 * @brief  Configure the Dma transfer parameters.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [in] u8Ch                    DMA transfer channel
 * @param  [in] u32SrcAddr              Source Address
 * @param  [in] u32DestAddr             Destination Address
 * @param  [in] u16BlockSize            Block Size
 * @param  [in] u16TransCount           Transfer Count
 * @retval None
 */
static void SD_DmaTransConfig(const stc_sd_handle_t *handle, uint8_t u8Ch, uint32_t u32SrcAddr, uint32_t u32DestAddr,
                              uint16_t u16BlockSize, uint16_t u16TransCount)
{
    /* Stop Configure channel */
    (void)DMA_ChCmd(handle->DMAx, u8Ch, DISABLE);
    DMA_ClearTransCompleteStatus(handle->DMAx, (uint32_t)(0x1UL << u8Ch));

    /* Config DMA source and destination address */
    (void)DMA_SetSrcAddr(handle->DMAx, u8Ch, u32SrcAddr);
    (void)DMA_SetDestAddr(handle->DMAx, u8Ch, u32DestAddr);
    /* Config DMA block size and transfer count */
    (void)DMA_SetBlockSize(handle->DMAx, u8Ch, u16BlockSize);
    (void)DMA_SetTransCount(handle->DMAx, u8Ch, u16TransCount);
}

/**
 * @brief  Get the SD card SCR register value.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [out] pu32SCR                Pointer to the value of SD card SCR register
 * @retval int32_t:
 *           - LL_OK: Get the SCR register value success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
static int32_t SD_GetSCR(stc_sd_handle_t *handle, uint32_t pu32SCR[])
{
    stc_sdioc_data_config_t stcDataCfg;
    int32_t i32Ret;
    uint32_t u32CardSta = 0UL;
    uint32_t u32TempSCR[2] = {0UL, 0UL};

    /* Check the lock status */
    i32Ret = SD_GetCurrCardStatus(handle, &u32CardSta);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }
    if (SDMMC_STATUS_CARD_IS_LOCKED == (u32CardSta & SDMMC_STATUS_CARD_IS_LOCKED)) {
        handle->u32ErrorCode |= SDMMC_ERR_LOCK_UNLOCK_FAILED;
        return LL_ERR;
    }

    /* Set Block Size To 8 Bytes */
    i32Ret = SDMMC_CMD16_SetBlockLength(handle->SDIOCx, 8UL, &handle->u32ErrorCode);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }
    /* Send CMD55 APP_CMD with argument as card's RCA */
    i32Ret = SDMMC_CMD55_AppCmd(handle->SDIOCx, (uint32_t)(handle->stcSdCardInfo.u32RelativeCardAddr << 16U),
                                &handle->u32ErrorCode);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }
    /* Configure the SD data transfer */
    stcDataCfg.u16BlockSize     = 8U;
    stcDataCfg.u16BlockCount    = 1U;
    stcDataCfg.u16TransDir      = SDIOC_TRANS_DIR_TO_HOST;
    stcDataCfg.u16AutoCmd12     = SDIOC_AUTO_SEND_CMD12_DISABLE;
    stcDataCfg.u16TransMode     = SDIOC_TRANS_MD_SINGLE;
    stcDataCfg.u16DataTimeout   = SDIOC_DATA_TIMEOUT_CLK_2E27;
    (void)SDIOC_ConfigData(handle->SDIOCx, &stcDataCfg);
    /* Send ACMD51 SD_APP_SEND_SCR with argument as 0 */
    i32Ret = SDMMC_ACMD51_SendSCR(handle->SDIOCx, &handle->u32ErrorCode);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }

    i32Ret = SD_ReadWriteFifo(handle, &stcDataCfg, (uint8_t *)(&u32TempSCR[0]), SDMMC_DATA_TIMEOUT);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }
    pu32SCR[1] = ((u32TempSCR[0] & 0x000000FFUL) << 24U) | ((u32TempSCR[0] & 0x0000FF00UL) << 8U) |
                 ((u32TempSCR[0] & 0x00FF0000UL) >> 8U)  | ((u32TempSCR[0] & 0xFF000000UL) >> 24U);
    pu32SCR[0] = ((u32TempSCR[1] & 0x000000FFUL) << 24U) | ((u32TempSCR[1] & 0x0000FF00UL) << 8U) |
                 ((u32TempSCR[1] & 0x00FF0000UL) >> 8U)  | ((u32TempSCR[1] & 0xFF000000UL) >> 24U);

    return i32Ret;
}

/**
 * @brief  Set the speed mode of the SD card.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @retval int32_t:
 *           - LL_OK: Set speed mode success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
static int32_t SD_SetSpeedMode(stc_sd_handle_t *handle)
{
    int32_t i32Ret = LL_OK;
    stc_sdioc_data_config_t stcDataCfg;
    uint32_t u32SDStatus[16];
    uint16_t u16Grp1Func;

    if (SD_CARD_SECURED != handle->stcSdCardInfo.u32CardType) {
        if (SDIOC_SPEED_MD_HIGH == handle->stcSdiocInit.u8SpeedMode) {
            /* Supports Specification version V1.1 or V2.0 */
            if ((SDMMC_SCR_PHY_SPEC_VER_1P1 == (handle->u32SCR[1] & SDMMC_SCR_PHY_SPEC_VER_1P1)) ||
                (SDMMC_SCR_PHY_SPEC_VER_2P0 == (handle->u32SCR[1] & SDMMC_SCR_PHY_SPEC_VER_2P0))) {
                /* Set Block Size To 64 Bytes */
                i32Ret = SDMMC_CMD16_SetBlockLength(handle->SDIOCx, 64UL, &handle->u32ErrorCode);
                if (LL_OK != i32Ret) {
                    return i32Ret;
                }
                /* Configure the SD data transfer */
                stcDataCfg.u16BlockSize    = 64U;
                stcDataCfg.u16BlockCount   = 1U;
                stcDataCfg.u16TransDir  = SDIOC_TRANS_DIR_TO_HOST;
                stcDataCfg.u16AutoCmd12  = SDIOC_AUTO_SEND_CMD12_DISABLE;
                stcDataCfg.u16TransMode = SDIOC_TRANS_MD_SINGLE;
                stcDataCfg.u16DataTimeout  = SDIOC_DATA_TIMEOUT_CLK_2E27;
                (void)SDIOC_ConfigData(handle->SDIOCx, &stcDataCfg);
                /* Send CMD6 SWITCH_FUNC with argument */
                i32Ret = SDMMC_CMD6_SwitchFunc(handle->SDIOCx, SD_SET_FUNC_HIGH_SPEED, &handle->u32ErrorCode);
                if (LL_OK != i32Ret) {
                    return i32Ret;
                }

                /* Get status data */
                i32Ret = SD_ReadWriteFifo(handle, &stcDataCfg, (uint8_t *)(&u32SDStatus[0]), SDMMC_DATA_TIMEOUT);
                if (LL_OK != i32Ret) {
                    return i32Ret;
                }
                /* Check the result of switch function */
                u16Grp1Func = (uint16_t)(((u32SDStatus[3] & 0x000000FFUL) << 8U) |
                                         ((u32SDStatus[3] & 0x0000FF00UL) >> 8U));
                if (SD_CMD6_RESULT_FUNC_GRP_BIT1 != (u16Grp1Func & SD_CMD6_RESULT_FUNC_GRP_BIT1)) {
                    handle->u32ErrorCode |= SDMMC_ERR_SWITCH_ERR;
                    return LL_ERR;
                }
            } else {
                handle->u32ErrorCode |= SDMMC_ERR_REQ_NOT_APPLICABLE;
                return LL_ERR;
            }
        }
    } else {
        /* MMC Card does not support this feature */
        handle->u32ErrorCode |= SDMMC_ERR_UNSUPPORT_FEATURE;
        return LL_ERR;
    }
    /* Set the clock division and speed mode of SDIOC */
    SDIOC_SetSpeedMode(handle->SDIOCx, handle->stcSdiocInit.u8SpeedMode);
    SDIOC_SetClockDiv(handle->SDIOCx, handle->stcSdiocInit.u16ClockDiv);

    return i32Ret;
}

/**
 * @brief  Set the bus width of the SD card.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @retval int32_t:
 *           - LL_OK: Set bus width success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
static int32_t SD_SetBusWidth(stc_sd_handle_t *handle)
{
    int32_t i32Ret;
    uint32_t u32BusWidth;

    if (SD_CARD_SECURED != handle->stcSdCardInfo.u32CardType) {
        if (SDIOC_BUS_WIDTH_1BIT == handle->stcSdiocInit.u8BusWidth) {
            u32BusWidth = 0UL;      /* 1 Bit */
        } else if (SDIOC_BUS_WIDTH_4BIT == handle->stcSdiocInit.u8BusWidth) {
            u32BusWidth = 2UL;      /* 4 Bit */
        } else {
            return LL_ERR_INVD_PARAM;
        }
    } else {
        /* MMC Card does not support this feature */
        handle->u32ErrorCode |= SDMMC_ERR_UNSUPPORT_FEATURE;
        return LL_ERR;
    }

    /* Supports wide bus or 1 bit mode operation */
    if ((SDMMC_SCR_BUS_WIDTH_4BIT == (handle->u32SCR[1] & SDMMC_SCR_BUS_WIDTH_4BIT)) ||
        (SDMMC_SCR_BUS_WIDTH_1BIT == (handle->u32SCR[1] & SDMMC_SCR_BUS_WIDTH_1BIT))) {
        /* Send CMD55 APP_CMD with argument as card's RCA.*/
        i32Ret = SDMMC_CMD55_AppCmd(handle->SDIOCx, (uint32_t)(handle->stcSdCardInfo.u32RelativeCardAddr << 16U),
                                    &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
        /* Send ACMD6 APP_CMD with argument */
        i32Ret = SDMMC_ACMD6_SetBusWidth(handle->SDIOCx, u32BusWidth, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
    } else {
        handle->u32ErrorCode |= SDMMC_ERR_REQ_NOT_APPLICABLE;
        return LL_ERR;
    }
    /* Set the bus width of SDIOC */
    SDIOC_SetBusWidth(handle->SDIOCx, handle->stcSdiocInit.u8BusWidth);

    return i32Ret;
}

/**
 * @brief  Initializes the sd card.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @retval int32_t:
 *           - LL_OK: SD card Initialize success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
static int32_t SD_InitCard(stc_sd_handle_t *handle)
{
    int32_t i32Ret;
    uint16_t u16RcaVal = 0U;
    uint32_t u32TempBuffer[4];

    /* Check the power State */
    if (DISABLE == SDIOC_GetPowerState(handle->SDIOCx)) {
        handle->u32ErrorCode |= SDMMC_ERR_REQ_NOT_APPLICABLE;
        return LL_ERR;
    }

    if (SD_CARD_SECURED != handle->stcSdCardInfo.u32CardType) {
        /* Send CMD2 ALL_SEND_CID */
        i32Ret = SDMMC_CMD2_AllSendCID(handle->SDIOCx, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
        /* Get Card identification number data */
        (void)SDIOC_GetResponse(handle->SDIOCx, SDIOC_RESP_REG_BIT0_31,   &u32TempBuffer[0]);
        (void)SDIOC_GetResponse(handle->SDIOCx, SDIOC_RESP_REG_BIT32_63,  &u32TempBuffer[1]);
        (void)SDIOC_GetResponse(handle->SDIOCx, SDIOC_RESP_REG_BIT64_95,  &u32TempBuffer[2]);
        (void)SDIOC_GetResponse(handle->SDIOCx, SDIOC_RESP_REG_BIT96_127, &u32TempBuffer[3]);
        handle->u32CID[0] = (u32TempBuffer[0] << 8U);
        handle->u32CID[1] = (u32TempBuffer[1] << 8U) | ((u32TempBuffer[0] >> 24U) & 0xFFU);
        handle->u32CID[2] = (u32TempBuffer[2] << 8U) | ((u32TempBuffer[1] >> 24U) & 0xFFU);
        handle->u32CID[3] = (u32TempBuffer[3] << 8U) | ((u32TempBuffer[2] >> 24U) & 0xFFU);
        /* Send CMD3 SET_REL_ADDR with argument 0 */
        /* SD Card publishes its RCA */
        i32Ret = SDMMC_CMD3_SendRelativeAddr(handle->SDIOCx, &u16RcaVal, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
        /* Get the SD card RCA */
        handle->stcSdCardInfo.u32RelativeCardAddr = u16RcaVal;
        /* Send CMD9 SEND_CSD with argument as card's RCA */
        i32Ret = SDMMC_CMD9_SendCSD(handle->SDIOCx, (uint32_t)(handle->stcSdCardInfo.u32RelativeCardAddr << 16U),
                                    &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
        /* Get Card Specific Data */
        (void)SDIOC_GetResponse(handle->SDIOCx, SDIOC_RESP_REG_BIT0_31,   &u32TempBuffer[0]);
        (void)SDIOC_GetResponse(handle->SDIOCx, SDIOC_RESP_REG_BIT32_63,  &u32TempBuffer[1]);
        (void)SDIOC_GetResponse(handle->SDIOCx, SDIOC_RESP_REG_BIT64_95,  &u32TempBuffer[2]);
        (void)SDIOC_GetResponse(handle->SDIOCx, SDIOC_RESP_REG_BIT96_127, &u32TempBuffer[3]);
        handle->u32CSD[0] = (u32TempBuffer[0] << 8U);
        handle->u32CSD[1] = (u32TempBuffer[1] << 8U) | ((u32TempBuffer[0] >> 24U) & 0xFFU);
        handle->u32CSD[2] = (u32TempBuffer[2] << 8U) | ((u32TempBuffer[1] >> 24U) & 0xFFU);
        handle->u32CSD[3] = (u32TempBuffer[3] << 8U) | ((u32TempBuffer[2] >> 24U) & 0xFFU);
    }

    /* Get the Card Class */
    handle->stcSdCardInfo.u32Class = handle->u32CSD[2] >> 20U;
    /* Get CSD parameters */
    (void)SD_ExtractCardCSD(handle);
    /* Select the Card */
    i32Ret = SDMMC_CMD7_SelectDeselectCard(handle->SDIOCx, (uint32_t)(handle->stcSdCardInfo.u32RelativeCardAddr << 16U),
                                           &handle->u32ErrorCode);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }

    return i32Ret;
}

/**
 * @brief  Enable or disable SD power.
 * @note   At the power-on, Enquires cards about their operating voltage and configures
 *         clock controls and stores SD information.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [in] enNewState              An @ref en_functional_state_t enumeration value.
 * @retval int32_t:
 *           - LL_OK: Enable or disable SD power success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
static int32_t SD_PowerCmd(stc_sd_handle_t *handle, en_functional_state_t enNewState)
{
    uint32_t u32Response = 0UL, u32PowerSta = 0UL;
    __IO uint32_t u32Count = 0UL;
    int32_t i32Ret = LL_OK;

    if (DISABLE != enNewState) {
        /* CMD0: GO_IDLE_STATE */
        i32Ret = SDMMC_CMD0_GoIdleState(handle->SDIOCx, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            return i32Ret;
        }
        /* Wait for reset to completed */
        DDL_DelayMS(1U);
        /* CMD8: SEND_IF_COND: Command available only on V2.0 cards */
        i32Ret = SDMMC_CMD8_SendInterfaceCond(handle->SDIOCx, &handle->u32ErrorCode);
        if (LL_OK != i32Ret) {
            handle->stcSdCardInfo.u32CardVersion = SD_CARD_V1_X;
            /* Send ACMD41 SD_APP_OP_COND with Argument 0x80100000 */
            while (0UL == u32PowerSta) {
                if (u32Count++ >= SDMMC_MAX_VOLT_TRIAL) {
                    handle->u32ErrorCode |= SDMMC_ERR_INVD_VOLT;
                    return LL_ERR;
                }

                /* SEND CMD55 APP_CMD with RCA as 0 */
                i32Ret = SDMMC_CMD55_AppCmd(handle->SDIOCx, 0UL, &handle->u32ErrorCode);
                if (LL_OK != i32Ret) {
                    handle->u32ErrorCode |= SDMMC_ERR_UNSUPPORT_FEATURE;
                    return LL_ERR;
                }
                /* Send ACMD41 */
                i32Ret = SDMMC_ACMD41_SendOperateCond(handle->SDIOCx, SDMMC_OCR_STD_CAPACITY,
                                                      &handle->u32ErrorCode);
                if (LL_OK != i32Ret) {
                    handle->u32ErrorCode |= SDMMC_ERR_UNSUPPORT_FEATURE;
                    return LL_ERR;
                }

                /* Get command response */
                (void)SDIOC_GetResponse(handle->SDIOCx, SDIOC_RESP_REG_BIT0_31, &u32Response);
                /* Get Card power up status bit (busy) */
                u32PowerSta = (((u32Response >> 31U) == 1UL) ? 1UL : 0UL);
            }
            /* Card type is SDSC */
            handle->stcSdCardInfo.u32CardType = SD_CARD_SDSC;
        } else {
            handle->stcSdCardInfo.u32CardVersion = SD_CARD_V2_X;
            /* Send ACMD41 SD_APP_OP_COND with Argument 0x80100000 */
            while (0UL == u32PowerSta) {
                if (u32Count++ >= SDMMC_MAX_VOLT_TRIAL) {
                    handle->u32ErrorCode |= SDMMC_ERR_INVD_VOLT;
                    return LL_ERR;
                }

                /* SEND CMD55 APP_CMD with RCA as 0 */
                i32Ret = SDMMC_CMD55_AppCmd(handle->SDIOCx, 0UL, &handle->u32ErrorCode);
                if (LL_OK != i32Ret) {
                    return i32Ret;
                }
                /* Send ACMD41 */
                i32Ret = SDMMC_ACMD41_SendOperateCond(handle->SDIOCx, SDMMC_OCR_HIGH_CAPACITY, &handle->u32ErrorCode);
                if (LL_OK != i32Ret) {
                    return i32Ret;
                }
                /* Get command response */
                (void)SDIOC_GetResponse(handle->SDIOCx, SDIOC_RESP_REG_BIT0_31, &u32Response);
                /* Get Card power up status bit (busy) */
                u32PowerSta = (((u32Response >> 31U) == 1UL) ? 1UL : 0UL);
            }

            if (SDMMC_OCR_HIGH_CAPACITY == (u32Response & SDMMC_OCR_HIGH_CAPACITY)) {
                handle->stcSdCardInfo.u32CardType = SD_CARD_SDHC_SDXC;
            } else {
                handle->stcSdCardInfo.u32CardType = SD_CARD_SDSC;
            }
        }
    } else {
        /* Set Power State to OFF */
        SDIOC_ClockCmd(handle->SDIOCx, DISABLE);
        SDIOC_PowerCmd(handle->SDIOCx, DISABLE);
    }

    return i32Ret;
}

/**
 * @brief  Get the current card status.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [out] pu32CardStatus         Pointer to the value of current card status
 * @retval int32_t:
 *           - LL_OK: Get card status success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
static int32_t SD_GetCurrCardStatus(stc_sd_handle_t *handle, uint32_t *pu32CardStatus)
{
    int32_t i32Ret;

    /* Send Status command */
    i32Ret = SDMMC_CMD13_SendStatus(handle->SDIOCx, (uint32_t)(handle->stcSdCardInfo.u32RelativeCardAddr << 16U),
                                    &handle->u32ErrorCode);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }
    /* Get SD card status */
    (void)SDIOC_GetResponse(handle->SDIOCx, SDIOC_RESP_REG_BIT0_31, pu32CardStatus);

    return i32Ret;
}

/**
 * @brief  Get the current SD status.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [out] pu32SDStatus           Pointer to the buffer of current SD status
 * @retval int32_t:
 *           - LL_OK: Get card status success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
static int32_t SD_GetCurrSDStatus(stc_sd_handle_t *handle, uint32_t *pu32SDStatus)
{
    int32_t i32Ret;
    stc_sdioc_data_config_t stcDataCfg;
    uint32_t u32CardSta = 0UL;

    /* Check the lock status */
    i32Ret = SD_GetCurrCardStatus(handle, &u32CardSta);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }
    if (SDMMC_STATUS_CARD_IS_LOCKED == (u32CardSta & SDMMC_STATUS_CARD_IS_LOCKED)) {
        handle->u32ErrorCode |= SDMMC_ERR_LOCK_UNLOCK_FAILED;
        return LL_ERR;
    }

    /* Set Block Size To 64 Bytes */
    i32Ret = SDMMC_CMD16_SetBlockLength(handle->SDIOCx, 64UL, &handle->u32ErrorCode);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }
    /* Send CMD55 APP_CMD with argument as card's RCA.*/
    i32Ret = SDMMC_CMD55_AppCmd(handle->SDIOCx, (uint32_t)(handle->stcSdCardInfo.u32RelativeCardAddr << 16U),
                                &handle->u32ErrorCode);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }
    /* Configure the SD data transfer */
    stcDataCfg.u16BlockSize    = 64U;
    stcDataCfg.u16BlockCount   = 1U;
    stcDataCfg.u16TransDir  = SDIOC_TRANS_DIR_TO_HOST;
    stcDataCfg.u16AutoCmd12  = SDIOC_AUTO_SEND_CMD12_DISABLE;
    stcDataCfg.u16TransMode = SDIOC_TRANS_MD_SINGLE;
    stcDataCfg.u16DataTimeout  = SDIOC_DATA_TIMEOUT_CLK_2E27;
    (void)SDIOC_ConfigData(handle->SDIOCx, &stcDataCfg);
    /* Send ACMD13 SD_STATUS */
    i32Ret = SDMMC_ACMD13_SendStatus(handle->SDIOCx, &handle->u32ErrorCode);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }

    /* Get status data */
    i32Ret = SD_ReadWriteFifo(handle, &stcDataCfg, (uint8_t *)pu32SDStatus, SDMMC_DATA_TIMEOUT);
    if (LL_OK != i32Ret) {
        return i32Ret;
    }

    return i32Ret;
}

/**
 * @brief  Read or Write the SD Card FIFO.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @param  [in] pstcDataConfig          Pointer to a @ref stc_sdioc_data_config_t structure
 * @param  [out] pu8Data                Pointer to the value of read/write fifo
 * @param  [in] u32Timeout              The timeout time
 * @retval int32_t:
 *           - LL_OK: Read or Write the FIFO success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 *           - LL_ERR_INVD_PARAM: An invalid parameter was write to the send command
 *           - LL_ERR_TIMEOUT: Send command timeout
 */
static int32_t SD_ReadWriteFifo(stc_sd_handle_t *handle, const stc_sdioc_data_config_t *pstcDataConfig,
                                uint8_t pu8Data[], uint32_t u32Timeout)
{
    __IO uint32_t u32Count;
    int32_t i32Ret = LL_OK;
    uint32_t u32Index = 0UL;

    /* The u32Timeout is expressed in ms */
    u32Count = u32Timeout * (HCLK_VALUE / 20000UL);
    while (RESET == SDIOC_GetIntStatus(handle->SDIOCx, (SDIOC_INT_FLAG_DEBE | SDIOC_INT_FLAG_DCE |
                                                        SDIOC_INT_FLAG_DTOE | SDIOC_INT_FLAG_TC))) {
        if (SDIOC_TRANS_DIR_TO_CARD != pstcDataConfig->u16TransDir) {
            /* Read buffer data */
            if (SET == SDIOC_GetHostStatus(handle->SDIOCx, SDIOC_HOST_FLAG_BRE)) {
                (void)SDIOC_ReadBuffer(handle->SDIOCx, (uint8_t *)&pu8Data[u32Index],
                                       (uint32_t)(pstcDataConfig->u16BlockSize));
                u32Index += pstcDataConfig->u16BlockSize;
            }
        } else {
            /* Write buffer data */
            if (SET == SDIOC_GetHostStatus(handle->SDIOCx, SDIOC_HOST_FLAG_BWE)) {
                (void)SDIOC_WriteBuffer(handle->SDIOCx, (uint8_t *)&pu8Data[u32Index],
                                        (uint32_t)(pstcDataConfig->u16BlockSize));
                u32Index += pstcDataConfig->u16BlockSize;
            }
        }
        if (0UL == u32Count) {
            SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
            return LL_ERR_TIMEOUT;
        }
        u32Count--;
    }

    /* Send stop transmission command in case of multiblock read/write */
    if ((SET == SDIOC_GetIntStatus(handle->SDIOCx, SDIOC_INT_FLAG_TC)) && (pstcDataConfig->u16BlockCount > 1U)) {
        if (SD_CARD_SECURED != handle->stcSdCardInfo.u32CardType) {
            /* Send stop transmission command */
            i32Ret = SDMMC_CMD12_StopTrans(handle->SDIOCx, &handle->u32ErrorCode);
            if (LL_OK != i32Ret) {
                SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
                return i32Ret;
            }
        }
    }

    /* Get error state */
    if (SET == SDIOC_GetIntStatus(handle->SDIOCx, SDIOC_INT_FLAG_DEBE)) {
        SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
        handle->u32ErrorCode |= SDMMC_ERR_DATA_STOP_BIT;
        return LL_ERR;
    } else if (SET == SDIOC_GetIntStatus(handle->SDIOCx, SDIOC_INT_FLAG_DCE)) {
        SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
        handle->u32ErrorCode |= SDMMC_ERR_DATA_CRC_FAIL;
        return LL_ERR;
    } else if (SET == SDIOC_GetIntStatus(handle->SDIOCx, SDIOC_INT_FLAG_DTOE)) {
        SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
        handle->u32ErrorCode |= SDMMC_ERR_DATA_TIMEOUT;
        return LL_ERR;
    } else {
        /* Empty FIFO if there is still any data */
        if (SDIOC_TRANS_DIR_TO_CARD != pstcDataConfig->u16TransDir) {
            u32Count = u32Timeout * (HCLK_VALUE / 20000UL);
            while (SET == SDIOC_GetHostStatus(handle->SDIOCx, SDIOC_HOST_FLAG_BRE)) {
                (void)SDIOC_ReadBuffer(handle->SDIOCx, (uint8_t *)&pu8Data[u32Index],
                                       (uint32_t)(pstcDataConfig->u16BlockSize));
                u32Index += pstcDataConfig->u16BlockSize;
                if (0UL == u32Count) {
                    SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
                    return LL_ERR_TIMEOUT;
                }
                u32Count--;
            }
        }
        /* Clear all the error and completed flags */
        SDIOC_ClearIntStatus(handle->SDIOCx, SDIOC_INT_STATIC_FLAGS);
    }

    return i32Ret;
}

/**
 * @brief  Extract information of the card which CSD register.
 * @param  [in] handle                  Pointer to a @ref stc_sd_handle_t structure
 * @retval int32_t:
 *           - LL_OK: Get sd card CSD register success
 *           - LL_ERR: Refer to u32ErrorCode for the reason of error
 */
static int32_t SD_ExtractCardCSD(stc_sd_handle_t *handle)
{
    int32_t i32Ret = LL_OK;
    uint32_t u32Temp;
    stc_sd_card_csd_t stcCardCSD;

    stcCardCSD.u8ReadBlockLen = (uint8_t)((handle->u32CSD[2] & 0x000F0000U) >> 16U);
    if (SD_CARD_SDSC == handle->stcSdCardInfo.u32CardType) {
        u32Temp = (uint8_t)((handle->u32CSD[1] & 0xFF000000U) >> 24U);
        stcCardCSD.u32DeviceSize    = (uint32_t)(((handle->u32CSD[2] & 0x000003FFU) << 2U) | ((u32Temp & 0xC0U) >> 6U));
        u32Temp = (uint8_t)((handle->u32CSD[1] & 0x00FF0000U) >> 16U);
        stcCardCSD.u8DeviceSizeMul  = (uint8_t)((u32Temp & 0x03U) << 1U);
        u32Temp = (uint8_t)((handle->u32CSD[1] & 0x0000FF00U) >> 8U);
        stcCardCSD.u8DeviceSizeMul  |= (uint8_t)((u32Temp & 0x80U) >> 7U);

        handle->stcSdCardInfo.u32BlockNum     = (stcCardCSD.u32DeviceSize + 1U) ;
        handle->stcSdCardInfo.u32BlockNum     *= (1UL << (stcCardCSD.u8DeviceSizeMul + 2U));
        handle->stcSdCardInfo.u32BlockSize    = 1UL << (stcCardCSD.u8ReadBlockLen);
        if (handle->stcSdCardInfo.u32BlockSize >= 512U) {
            handle->stcSdCardInfo.u32LogBlockNum = handle->stcSdCardInfo.u32BlockNum *
                                                   (handle->stcSdCardInfo.u32BlockSize / 512U);
        } else {
            handle->stcSdCardInfo.u32LogBlockNum = (handle->stcSdCardInfo.u32BlockNum / 512U) *
                                                   handle->stcSdCardInfo.u32BlockSize;
        }
        handle->stcSdCardInfo.u32LogBlockSize = 512UL;
    } else if (SD_CARD_SDHC_SDXC == handle->stcSdCardInfo.u32CardType) {
        stcCardCSD.u32DeviceSize = (uint32_t)(((handle->u32CSD[2] & 0x0000003FU) << 16U) |
                                              ((handle->u32CSD[1] & 0xFFFF0000U) >> 16U));

        handle->stcSdCardInfo.u32BlockNum     = (stcCardCSD.u32DeviceSize + 1U) * 1024U;
        handle->stcSdCardInfo.u32BlockSize    = 512U;
        handle->stcSdCardInfo.u32LogBlockNum  = handle->stcSdCardInfo.u32BlockNum;
        handle->stcSdCardInfo.u32LogBlockSize = handle->stcSdCardInfo.u32BlockSize;
    } else {
        handle->u32ErrorCode |= SDMMC_ERR_UNSUPPORT_FEATURE;
        return LL_ERR;
    }

    return i32Ret;
}

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/
