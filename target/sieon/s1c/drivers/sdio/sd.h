/**
 *******************************************************************************
 * @file  sd.h
 * @brief This file contains all the functions prototypes of the Secure
 *        Digital(SD) driver library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2022-03-31       CDT             First version
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
#ifndef __SD_H__
#define __SD_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "wl32_ll_sdioc.h"
#include "wl32_ll_dma.h"
#include "wl32_ll_utility.h"

/**
 * @addtogroup LL_SDIOC_LIB
 * @{
 */

/**
 * @addtogroup SDIOC_SD_Card
 * @{
 */

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/
/**
 * @defgroup SD_Global_Types SD Global Types
 * @{
 */

/**
 * @brief SD Card State enumeration structure definition
 */
typedef enum {
    SD_CARD_STAT_IDLE       = 0x00U,    /*!< Card state is idle                      */
    SD_CARD_STAT_RDY        = 0x01U,    /*!< Card state is ready                     */
    SD_CARD_STAT_IDENTIFY   = 0x02U,    /*!< Card is in identification state         */
    SD_CARD_STAT_STANDBY    = 0x03U,    /*!< Card is in standby state                */
    SD_CARD_STAT_TRANS      = 0x04U,    /*!< Card is in transfer state               */
    SD_CARD_STAT_TX_DATA    = 0x05U,    /*!< Card is sending an operation            */
    SD_CARD_STAT_RX_DATA    = 0x06U,    /*!< Card is receiving operation information */
    SD_CARD_STAT_PGM        = 0x07U,    /*!< Card is in programming state            */
    SD_CARD_STAT_DISCONNECT = 0x08U     /*!< Card is disconnected                    */
} en_sd_card_state_t;

/**
 * @brief SD Card Information Structure definition
 */
typedef struct {
    uint32_t u32CardType;               /*!< Specifies the card Type                       */
    uint32_t u32CardVersion;            /*!< Specifies the card version                    */
    uint32_t u32Class;                  /*!< Specifies the class of the card class         */
    uint32_t u32RelativeCardAddr;       /*!< Specifies the Relative Card Address           */
    uint32_t u32BlockNum;               /*!< Specifies the Card Capacity in blocks         */
    uint32_t u32BlockSize;              /*!< Specifies one block size in bytes             */
    uint32_t u32LogBlockNum;            /*!< Specifies the Card logical Capacity in blocks */
    uint32_t u32LogBlockSize;           /*!< Specifies logical block size in bytes         */
} stc_sd_card_info_t;

/**
 * @brief SD Card Specific Data(CSD Register) Structure definition
 */
typedef struct {
    uint8_t  u8CSDStruct;               /*!< CSD structure                         */
    uint8_t  u8Reserved1;               /*!< Reserved                              */
    uint8_t  u8TAAC;                    /*!< Data read access time 1               */
    uint8_t  u8NSAC;                    /*!< Data read access time 2 in CLK cycles */
    uint8_t  u8MaxBusClkFreq;           /*!< Max. bus clock frequency              */
    uint16_t u16CardCmdClass;           /*!< Card command classes                  */
    uint8_t  u8ReadBlockLen;            /*!< Max. read data block length           */
    uint8_t  u8BlockReadPartial;        /*!< Partial blocks for read allowed       */
    uint8_t  u8WriteBlockMisalign;      /*!< Write block misalignment              */
    uint8_t  u8ReadBlockMisalign;       /*!< Read block misalignment               */
    uint8_t  u8DSRImplement;            /*!< DSR implemented                       */
    uint8_t  u8Reserved2;               /*!< Reserved                              */
    uint32_t u32DeviceSize;             /*!< Device Size                           */
    uint8_t  u8MaxReadCurrVDDMin;       /*!< Max. read current @ VDD min           */
    uint8_t  u8MaxReadCurrVDDMax;       /*!< Max. read current @ VDD max           */
    uint8_t  u8MaxWriteCurrVDDMin;      /*!< Max. write current @ VDD min          */
    uint8_t  u8MaxWriteCurrVDDMax;      /*!< Max. write current @ VDD max          */
    uint8_t  u8DeviceSizeMul;           /*!< Device size multiplier                */
    uint8_t  u8EraseSingleBlockEn;      /*!< Erase single block enable             */
    uint8_t  u8EraseSectorSize;         /*!< Erase sector size                     */
    uint8_t  u8WriteProtectGroupSize;   /*!< Write protect group size              */
    uint8_t  u8WriteProtectGroupEn;     /*!< Write protect group enable            */
    uint8_t  u8Reserved3;               /*!< Reserved                              */
    uint8_t  u8WriteSpeedFactor;        /*!< Write speed factor                    */
    uint8_t  u8MaxWriteBlockLen;        /*!< Max. write data block length          */
    uint8_t  u8WriteBlockPartial;       /*!< Partial blocks for write allowed      */
    uint8_t  u8Reserved4;               /*!< Reserved                              */
    uint8_t  u8FileFormatGroup;         /*!< File format group                     */
    uint8_t  u8CopyFlag;                /*!< Copy flag (OTP)                       */
    uint8_t  u8PermWriteProtect;        /*!< Permanent write protection            */
    uint8_t  u8TempWriteProtect;        /*!< Temporary write protection            */
    uint8_t  u8FileFormat;              /*!< File format                           */
    uint8_t  u8Reserved5;               /*!< Reserved                              */
    uint8_t  u8CRCChecksum;             /*!< CSD CRC7 checksum                     */
    uint8_t  u8Reserved6;               /*!< Always 1                              */
} stc_sd_card_csd_t;

/**
 * @brief SD Card Identification Data(CID Register) Structure definition
 */
typedef struct {
    uint8_t  u8ManufacturerID;          /*!< Manufacturer ID       */
    uint16_t u16OemAppID;               /*!< OEM/Application ID    */
    uint32_t u32ProductName1;           /*!< Product Name part1    */
    uint8_t  u8ProductName2;            /*!< Product Name part2    */
    uint8_t  u8ProductRevision;         /*!< Product Revision      */
    uint32_t u32ProductSN;              /*!< Product Serial Number */
    uint8_t  u8Reserved1;               /*!< Reserved1             */
    uint16_t u16ManufactDate;           /*!< Manufacturing Date    */
    uint8_t  u8CRCChecksum;             /*!< CRC7 checksum         */
    uint8_t  u8Reserved2;               /*!< Always 1              */
} stc_sd_card_cid_t;

/**
 * @brief SD Card Status Structure definition (returned by ACMD13)
 */
typedef struct {
    uint8_t  u8DataBusWidth;            /*!< Shows the currently defined data bus width                 */
    uint8_t  u8SecuredMode;             /*!< Card is in secured mode of operation                       */
    uint16_t u16CardType;               /*!< Carries information about card type                        */
    uint32_t u32ProtectedAreaSize;      /*!< Carries information about the capacity of protected area   */
    uint8_t  u8SpeedClass;              /*!< Carries information about the speed class of the card      */
    uint8_t  u8PerformanceMove;         /*!< Carries information about the card's performance move      */
    uint8_t  u8AllocUnitSize;           /*!< Carries information about the card's allocation unit size  */
    uint16_t u16EraseSize;              /*!< Determines the number of AUs to be erased in one operation */
    uint8_t  u8EraseTimeout;            /*!< Determines the timeout for any number of AU erase          */
    uint8_t  u8EraseOffset;             /*!< Carries information about the erase offset                 */
} stc_sd_card_status_t;

/**
 * @brief SD handle Structure definition
 */
typedef struct {
    CM_SDIOC_TypeDef    *SDIOCx;        /*!< Pointer to SDIOC registers base address            */
    stc_sdioc_init_t    stcSdiocInit;   /*!< SDIOC Initialize structure @ref stc_sdioc_init_t   */
    CM_DMA_TypeDef      *DMAx;          /*!< Pointer to DMA registers base address              */
    uint8_t             u8DmaTxCh;      /*!< Specifies the DMA channel used to send             */
    uint8_t             u8DmaRxCh;      /*!< Specifies the DMA channel used to receive          */
    uint8_t             *pu8Buffer;     /*!< Pointer to SD Tx/Rx transfer Buffer                */
    uint32_t            u32Len;         /*!< SD Tx/Rx Transfer length                           */
    uint32_t            u32Context;     /*!< SD transfer context                                */
    uint32_t            u32ErrorCode;   /*!< SD Card Error codes                                */
    stc_sd_card_info_t  stcSdCardInfo;  /*!< SD Card information                                */
    uint32_t            u32CSD[4];      /*!< SD card specific data table                        */
    uint32_t            u32CID[4];      /*!< SD card identification number table                */
    uint32_t            u32SCR[2];      /*!< SD Configuration Register table                    */
} stc_sd_handle_t;

/**
 * @}
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup SD_Global_Macros SD Global Macros
 * @{
 */

/**
 * @defgroup SD_Transfer_Context SD Transfer Context
 * @{
 */
#define SD_CONTEXT_NONE                         (0x00UL)    /*!< None                             */
#define SD_CONTEXT_RD_SINGLE_BLOCK              (0x01UL)    /*!< Read single block operation      */
#define SD_CONTEXT_RD_MULTI_BLOCK               (0x02UL)    /*!< Read multiple blocks operation   */
#define SD_CONTEXT_WR_SINGLE_BLOCK              (0x10UL)    /*!< Write single block operation     */
#define SD_CONTEXT_WR_MULTI_BLOCK               (0x20UL)    /*!< Write multiple blocks operation  */
#define SD_CONTEXT_INT                          (0x40UL)    /*!< Process in Interrupt mode        */
#define SD_CONTEXT_DMA                          (0x80UL)    /*!< Process in DMA mode              */
/**
 * @}
 */

/**
 * @defgroup SD_Support_Memory_Card SD Support Memory Card
 * @{
 */
#define SD_CARD_SDSC                            (0x00UL)
#define SD_CARD_SDHC_SDXC                       (0x01UL)
#define SD_CARD_SECURED                         (0x03UL)
/**
 * @}
 */

/**
 * @defgroup SD_Support_Version SD Support Version
 * @{
 */
#define SD_CARD_V1_X                            (0x00UL)  /*!< SD Card version: 1.x */
#define SD_CARD_V2_X                            (0x01UL)  /*!< SD Card version: 2.x */
/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/*******************************************************************************
  Global function prototypes (definition in C source)
 ******************************************************************************/
/**
 * @addtogroup SD_Global_Functions
 * @{
 */
int32_t SD_DeInit(stc_sd_handle_t *handle);
int32_t SD_Init(stc_sd_handle_t *handle);
int32_t SD_GetCardState(stc_sd_handle_t *handle, en_sd_card_state_t *peCardState);
int32_t SD_GetCardCID(const stc_sd_handle_t *handle, stc_sd_card_cid_t *pstcCardCID);
int32_t SD_GetCardCSD(stc_sd_handle_t *handle, stc_sd_card_csd_t *pstcCardCSD);
int32_t SD_GetCardStatus(stc_sd_handle_t *handle, stc_sd_card_status_t *pstcCardStatus);
int32_t SD_GetCardInfo(stc_sd_handle_t *handle, stc_sd_card_info_t *pstcCardInfo);
int32_t SD_GetErrorCode(const stc_sd_handle_t *handle, uint32_t *pu32ErrorCode);

/* Callback in non blocking modes */
void SD_IRQHandler(stc_sd_handle_t *handle);
void SD_TxCompleteCallback(stc_sd_handle_t *handle);
void SD_RxCompleteCallback(stc_sd_handle_t *handle);
void SD_ErrorCallback(stc_sd_handle_t *handle);

/* Polling Mode */
int32_t SD_Erase(stc_sd_handle_t *handle, uint32_t u32BlockStartAddr, uint32_t u32BlockEndAddr);
int32_t SD_ReadBlocks(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount,
                      uint8_t *pu8Data, uint32_t u32Timeout);
int32_t SD_WriteBlocks(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount,
                       uint8_t *pu8Data, uint32_t u32Timeout);
/* Interrupt Mode */
int32_t SD_ReadBlocks_INT(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount, uint8_t *pu8Data);
int32_t SD_WriteBlocks_INT(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount, uint8_t *pu8Data);
/* DMA Mode */
int32_t SD_ReadBlocks_DMA(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount, uint8_t *pu8Data);
int32_t SD_WriteBlocks_DMA(stc_sd_handle_t *handle, uint32_t u32BlockAddr, uint16_t u16BlockCount, uint8_t *pu8Data);
/* Abort */
int32_t SD_Abort(stc_sd_handle_t *handle);

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __SD_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
