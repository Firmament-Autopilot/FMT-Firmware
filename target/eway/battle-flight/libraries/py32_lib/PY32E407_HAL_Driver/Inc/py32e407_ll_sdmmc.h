/**
  ******************************************************************************
  * @file    py32e407_ll_sdmmc.h
  * @author  MCU Application Team
  * @brief   Header file of SDMMC HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by Puya under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PY32E407_LL_SDMMC_H
#define PY32E407_LL_SDMMC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

/** @addtogroup SDMMC_LL SDMMC
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/ 
/** @defgroup SDMMC_LL_Exported_Types SDMMC Exported Types
  * @{
  */
  
/** 
  * @brief  SDMMC Configuration Structure definition  
  */
typedef struct
{

  uint32_t ClockSel;             /*!< Specifies the SDMMC controller Clock output select.
                                      This parameter can be a value of @ref SDIO_LL_Clock_Select           */

  uint32_t BusWide;              /*!< Specifies the SDMMC bus width.
                                      This parameter can be a value of @ref SDIO_LL_Bus_Wide                   */

  uint32_t ClockDiv;             /*!< Specifies the clock frequency of the SDMMC controller.
                                      This parameter can be a value between Min_Data = 0 and Max_Data = 255    */ 

  uint32_t ClockPowerSave;       /*!< Specifies whether SDMMC Clock output is enabled or
                                      disabled when the bus is idle.
                                      This parameter can be a value of @ref SDIO_LL_Clock_Power_Save           */ 
  
  uint32_t PreSampling;          /*!< Specifies whether SDMMC controller preSampling Clock 
                                      is enabled or disabled.
                                      This parameter can be a value of @ref SDIO_LL_PreSampling               */

  uint32_t PreSamplingClockSel;  /*!< Specifies the SDMMC preSampling Clock select.
                                      This parameter can be a value of @ref SDIO_LL_PreSampling_Clock_Select               */
                                      
}SDIO_InitTypeDef;
  

/** 
  * @brief  SDMMC Command Control structure 
  */
typedef struct                                                                                            
{
  uint32_t Argument;            /*!< Specifies the SDMMC command argument which is sent
                                     to a card as part of a command message. If a command
                                     contains an argument, it must be loaded into this register
                                     before writing the command to the command register.              */

  uint32_t CmdIndex;            /*!< Specifies the SDMMC command index. It must be Min_Data = 0 and 
                                     Max_Data = 64                                                    */

  uint32_t Response;            /*!< Specifies the SDMMC response type.
                                     This parameter can be a value of @ref SDIO_LL_Response_Type         */

  uint32_t WaitPend;            /*!< Specifies whether to wait for the data transfer to before 
                                     sending the command, request is enabled or disabled.
                                     This parameter can be a value of @ref SDIO_LL_Wait_Pend  */
    
  uint32_t AutoInit;            /*!< Specifies whether Send initialization sequence before sending command.
                                     This parameter can be a value of @ref SDIO_LL_AutoInit */

  uint32_t CheckCRC;            /*!< Specifies whether Check CRC response.
                                     This parameter can be a value of @ref SDIO_LL_Check_CRC */

  uint32_t DataTransfer;        /*!< Specifies whether Expected data transfer.
                                     This parameter can be a value of @ref SDIO_LL_DataTransfer */

  uint32_t CPSM;                /*!< Specifies whether SDMMC Command path state machine (CPSM)
                                     is enabled or disabled.
                                     This parameter can be a value of @ref SDIO_LL_CPSM_State            */
  
}SDIO_CmdInitTypeDef;


/** 
  * @brief  SDMMC Data Control structure 
  */
typedef struct
{
  uint32_t DataTimeOut;         /*!< Specifies the data timeout period in card bus clock periods.  */

  uint32_t DataLength;          /*!< Specifies the number of data bytes to be transferred.         */
 
  uint32_t DataBlockSize;       /*!< Specifies the data block size for block transfer.
                                     It must be Min_Data = 0x0 and Max_Data = 0xFFFF    */
 
  uint32_t TransferDir;         /*!< Specifies the data transfer direction, whether the transfer
                                     is a read or write.
                                     This parameter can be a value of @ref SDIO_LL_Transfer_Direction */
 
  uint32_t TransferMode;        /*!< Specifies whether data transfer is in stream or block mode.
                                     This parameter can be a value of @ref SDIO_LL_Transfer_Type      */
 
}SDIO_DataInitTypeDef;

/**
  * @}
  */
  
/* Exported constants --------------------------------------------------------*/
/** @defgroup SDMMC_LL_Exported_Constants SDMMC Exported Constants
  * @{
  */

/** @defgroup SDMMC_LL_Error_Code SDMMC Error Code
  * @{
  */  
#define SDMMC_ERROR_NONE                     ((uint32_t)0x00000000U)   /*!< No error                                                      */
#define SDMMC_ERROR_CMD_CRC_FAIL             ((uint32_t)0x00000001U)   /*!< Command response received (but CRC check failed)              */
#define SDMMC_ERROR_DATA_CRC_FAIL            ((uint32_t)0x00000002U)   /*!< Data block sent/received (CRC check failed)                   */
#define SDMMC_ERROR_CMD_RSP_TIMEOUT          ((uint32_t)0x00000004U)   /*!< Command response timeout                                      */
#define SDMMC_ERROR_DATA_TIMEOUT             ((uint32_t)0x00000008U)   /*!< Data timeout                                                  */
#define SDMMC_ERROR_FIFO_ERR                 ((uint32_t)0x00000010U)   /*!< FIFO error                                                    */
#define SDMMC_ERROR_CMD_RSP_ERR              ((uint32_t)0x00000020U)   /*!< Command response error                                        */
#define SDMMC_ERROR_ADDR_MISALIGNED          ((uint32_t)0x00000040U)   /*!< Misaligned address                                            */
#define SDMMC_ERROR_BLOCK_LEN_ERR            ((uint32_t)0x00000080U)   /*!< Transferred block length is not allowed for the card or the
                                                                            number of transferred bytes does not match the block length   */
#define SDMMC_ERROR_ERASE_SEQ_ERR            ((uint32_t)0x00000100U)   /*!< An error in the sequence of erase command occurs              */
#define SDMMC_ERROR_BAD_ERASE_PARAM          ((uint32_t)0x00000200U)   /*!< An invalid selection for erase groups                         */
#define SDMMC_ERROR_WRITE_PROT_VIOLATION     ((uint32_t)0x00000400U)   /*!< Attempt to program a write protect block                      */
#define SDMMC_ERROR_LOCK_UNLOCK_FAILED       ((uint32_t)0x00000800U)   /*!< Sequence or password error has been detected in unlock
                                                                            command or if there was an attempt to access a locked card    */
#define SDMMC_ERROR_COM_CRC_FAILED           ((uint32_t)0x00001000U)   /*!< CRC check of the previous command failed                      */
#define SDMMC_ERROR_ILLEGAL_CMD              ((uint32_t)0x00002000U)   /*!< Command is not legal for the card state                       */
#define SDMMC_ERROR_CARD_ECC_FAILED          ((uint32_t)0x00004000U)   /*!< Card internal ECC was applied but failed to correct the data  */
#define SDMMC_ERROR_CC_ERR                   ((uint32_t)0x00008000U)   /*!< Internal card controller error                                */
#define SDMMC_ERROR_GENERAL_UNKNOWN_ERR      ((uint32_t)0x00010000U)   /*!< General or unknown error                                      */
#define SDMMC_ERROR_STREAM_READ_UNDERRUN     ((uint32_t)0x00020000U)   /*!< The card could not sustain data reading in stream rmode       */
#define SDMMC_ERROR_STREAM_WRITE_OVERRUN     ((uint32_t)0x00040000U)   /*!< The card could not sustain data programming in stream mode    */
#define SDMMC_ERROR_CID_CSD_OVERWRITE        ((uint32_t)0x00080000U)   /*!< CID/CSD overwrite error                                       */
#define SDMMC_ERROR_WP_ERASE_SKIP            ((uint32_t)0x00100000U)   /*!< Only partial address space was erased                         */
#define SDMMC_ERROR_CARD_ECC_DISABLED        ((uint32_t)0x00200000U)   /*!< Command has been executed without using internal ECC          */
#define SDMMC_ERROR_ERASE_RESET              ((uint32_t)0x00400000U)   /*!< Erase sequence was cleared before executing because an out
                                                                            of erase sequence command was received                        */
#define SDMMC_ERROR_AKE_SEQ_ERR              ((uint32_t)0x00800000U)   /*!< Error in sequence of authentication                           */
#define SDMMC_ERROR_INVALID_VOLTRANGE        ((uint32_t)0x01000000U)   /*!< Error in case of invalid voltage range                        */
#define SDMMC_ERROR_ADDR_OUT_OF_RANGE        ((uint32_t)0x02000000U)   /*!< Error when addressed block is out of range                    */
#define SDMMC_ERROR_REQUEST_NOT_APPLICABLE   ((uint32_t)0x04000000U)   /*!< Error when command request is not applicable                  */
#define SDMMC_ERROR_INVALID_PARAMETER        ((uint32_t)0x08000000U)   /*!< the used parameter is not valid                               */
#define SDMMC_ERROR_UNSUPPORTED_FEATURE      ((uint32_t)0x10000000U)   /*!< Error when feature is not insupported                         */
#define SDMMC_ERROR_BUSY                     ((uint32_t)0x20000000U)   /*!< Error when transfer process is busy                           */
#define SDMMC_ERROR_DMA                      ((uint32_t)0x40000000U)   /*!< Error while DMA transfer                                      */
#define SDMMC_ERROR_TIMEOUT                  ((uint32_t)0x80000000U)   /*!< Timeout error                                                 */
/**
  * @}
  */

 /** @defgroup SDMMC_LL_CMD_INDEX SDMMC Commands Index
  * @{
  */  
#define SDMMC_CMD_GO_IDLE_STATE                       ((uint8_t)0U)   /*!< Resets the SD memory card.                                                               */
#define SDMMC_CMD_SEND_OP_COND                        ((uint8_t)1U)   /*!< Sends host capacity support information and activates the card's initialization process. */
#define SDMMC_CMD_ALL_SEND_CID                        ((uint8_t)2U)   /*!< Asks any card connected to the host to send the CID numbers on the CMD line.             */
#define SDMMC_CMD_SET_REL_ADDR                        ((uint8_t)3U)   /*!< Asks the card to publish a new relative address (RCA).                                   */
#define SDMMC_CMD_SET_DSR                             ((uint8_t)4U)   /*!< Programs the DSR of all cards.                                                           */
#define SDMMC_CMD_SDMMC_SEN_OP_COND                   ((uint8_t)5U)   /*!< Sends host capacity support information (HCS) and asks the accessed card to send its
                                                                           operating condition register (OCR) content in the response on the CMD line.                  */
#define SDMMC_CMD_HS_SWITCH                           ((uint8_t)6U)   /*!< Checks switchable function (mode 0) and switch card function (mode 1).                   */
#define SDMMC_CMD_SEL_DESEL_CARD                      ((uint8_t)7U)   /*!< Selects the card by its own relative address and gets deselected by any other address    */
#define SDMMC_CMD_HS_SEND_EXT_CSD                     ((uint8_t)8U)   /*!< Sends SD Memory Card interface condition, which includes host supply voltage information
                                                                           and asks the card whether card supports voltage.                                             */
#define SDMMC_CMD_SEND_CSD                            ((uint8_t)9U)   /*!< Addressed card sends its card specific data (CSD) on the CMD line.                       */
#define SDMMC_CMD_SEND_CID                            ((uint8_t)10U)  /*!< Addressed card sends its card identification (CID) on the CMD line.                      */
#define SDMMC_CMD_READ_DAT_UNTIL_STOP                 ((uint8_t)11U)  /*!< SD card doesn't support it.                                                              */
#define SDMMC_CMD_STOP_TRANSMISSION                   ((uint8_t)12U)  /*!< Forces the card to stop transmission.                                                    */
#define SDMMC_CMD_SEND_STATUS                         ((uint8_t)13U)  /*!< Addressed card sends its status register.                                                */
#define SDMMC_CMD_HS_BUSTEST_READ                     ((uint8_t)14U)  /*!< Reserved                                                                                 */
#define SDMMC_CMD_GO_INACTIVE_STATE                   ((uint8_t)15U)  /*!< Sends an addressed card into the inactive state.                                         */
#define SDMMC_CMD_SET_BLOCKLEN                        ((uint8_t)16U)  /*!< Sets the block length (in bytes for SDSC) for all following block commands
                                                                           (read, write, lock). Default block length is fixed to 512 Bytes. Not effective 
                                                                           for SDHS and SDXC.                                                                       */
#define SDMMC_CMD_READ_SINGLE_BLOCK                   ((uint8_t)17U)  /*!< Reads single block of size selected by SET_BLOCKLEN in case of SDSC, and a block of
                                                                           fixed 512 bytes in case of SDHC and SDXC.                                                */
#define SDMMC_CMD_READ_MULT_BLOCK                     ((uint8_t)18U)  /*!< Continuously transfers data blocks from card to host until interrupted by
                                                                           STOP_TRANSMISSION command.                                                               */
#define SDMMC_CMD_HS_BUSTEST_WRITE                    ((uint8_t)19U)  /*!< 64 bytes tuning pattern is sent for SDR50 and SDR104.                                    */
#define SDMMC_CMD_WRITE_DAT_UNTIL_STOP                ((uint8_t)20U)  /*!< Speed class control command.                                                             */
#define SDMMC_CMD_SET_BLOCK_COUNT                     ((uint8_t)23U)  /*!< Specify block count for CMD18 and CMD25.                                                 */
#define SDMMC_CMD_WRITE_SINGLE_BLOCK                  ((uint8_t)24U)  /*!< Writes single block of size selected by SET_BLOCKLEN in case of SDSC, and a block of
                                                                           fixed 512 bytes in case of SDHC and SDXC.                                                */
#define SDMMC_CMD_WRITE_MULT_BLOCK                    ((uint8_t)25U)  /*!< Continuously writes blocks of data until a STOP_TRANSMISSION follows.                    */
#define SDMMC_CMD_PROG_CID                            ((uint8_t)26U)  /*!< Reserved for manufacturers.                                                              */
#define SDMMC_CMD_PROG_CSD                            ((uint8_t)27U)  /*!< Programming of the programmable bits of the CSD.                                         */
#define SDMMC_CMD_SET_WRITE_PROT                      ((uint8_t)28U)  /*!< Sets the write protection bit of the addressed group.                                    */
#define SDMMC_CMD_CLR_WRITE_PROT                      ((uint8_t)29U)  /*!< Clears the write protection bit of the addressed group.                                  */
#define SDMMC_CMD_SEND_WRITE_PROT                     ((uint8_t)30U)  /*!< Asks the card to send the status of the write protection bits.                           */
#define SDMMC_CMD_SD_ERASE_GRP_START                  ((uint8_t)32U)  /*!< Sets the address of the first write block to be erased. (For SD card only).              */
#define SDMMC_CMD_SD_ERASE_GRP_END                    ((uint8_t)33U)  /*!< Sets the address of the last write block of the continuous range to be erased.           */
#define SDMMC_CMD_ERASE_GRP_START                     ((uint8_t)35U)  /*!< Sets the address of the first write block to be erased. Reserved for each command
                                                                           system set by switch function command (CMD6).                                            */
#define SDMMC_CMD_ERASE_GRP_END                       ((uint8_t)36U)  /*!< Sets the address of the last write block of the continuous range to be erased.
                                                                           Reserved for each command system set by switch function command (CMD6).                  */
#define SDMMC_CMD_ERASE                               ((uint8_t)38U)  /*!< Reserved for SD security applications.                                                   */
#define SDMMC_CMD_FAST_IO                             ((uint8_t)39U)  /*!< SD card doesn't support it (Reserved).                                                   */
#define SDMMC_CMD_GO_IRQ_STATE                        ((uint8_t)40U)  /*!< SD card doesn't support it (Reserved).                                                   */
#define SDMMC_CMD_LOCK_UNLOCK                         ((uint8_t)42U)  /*!< Sets/resets the password or lock/unlock the card. The size of the data block is set by
                                                                           the SET_BLOCK_LEN command.                                                               */
#define SDMMC_CMD_APP_CMD                             ((uint8_t)55U)  /*!< Indicates to the card that the next command is an application specific command rather
                                                                           than a standard command.                                                                 */
#define SDMMC_CMD_GEN_CMD                             ((uint8_t)56U)  /*!< Used either to transfer a data block to the card or to get a data block from the card
                                                                           for general purpose/application specific commands.                                       */
#define SDMMC_CMD_NO_CMD                              ((uint8_t)64U)  /*!< No command                                                                               */
/**
  * @}
  */

 /** @defgroup SDMMC_LL_SPECIFIC_CMD SDMMC Specific commands
   * @brief Following commands are SD Card Specific commands.
   *        SDMMC_APP_CMD should be sent before sending these commands.
   * @{
   */
#define SDMMC_CMD_APP_SD_SET_BUSWIDTH                 ((uint8_t)6U)   /*!< (ACMD6) Defines the data bus width to be used for data transfer. The allowed data bus
                                                                            widths are given in SCR register.                                                       */
#define SDMMC_CMD_SD_APP_STATUS                       ((uint8_t)13U)  /*!< (ACMD13) Sends the SD status.                                                            */
#define SDMMC_CMD_SD_APP_SEND_NUM_WRITE_BLOCKS        ((uint8_t)22U)  /*!< (ACMD22) Sends the number of the written (without errors) write blocks. Responds with
                                                                           32bit+CRC data block.                                                                    */
#define SDMMC_CMD_SD_APP_OP_COND                      ((uint8_t)41U)  /*!< (ACMD41) Sends host capacity support information (HCS) and asks the accessed card to
                                                                           send its operating condition register (OCR) content in the response on the CMD line.     */
#define SDMMC_CMD_SD_APP_SET_CLR_CARD_DETECT          ((uint8_t)42U)  /*!< (ACMD42) Connect/Disconnect the 50 KOhm pull-up resistor on CD/DAT3 (pin 1) of the card  */
#define SDMMC_CMD_SD_APP_SEND_SCR                     ((uint8_t)51U)  /*!< Reads the SD Configuration Register (SCR).                                               */
#define SDMMC_CMD_SDMMC_RW_DIRECT                     ((uint8_t)52U)  /*!< For SD I/O card only, reserved for security specification.                               */
#define SDMMC_CMD_SDMMC_RW_EXTENDED                   ((uint8_t)53U)  /*!< For SD I/O card only, reserved for security specification.                               */
/**
  * @}
  */

 /** @defgroup SDMMC_LL_SPECIFIC_SECURITY_CMD SDMMC Specific security commands
   * @brief Following commands are SD Card Specific security commands.
   *         SDMMC_CMD_APP_CMD should be sent before sending these commands. 
   * @{
   */
#define SDMMC_CMD_SD_APP_GET_MKB                      ((uint8_t)43U)
#define SDMMC_CMD_SD_APP_GET_MID                      ((uint8_t)44U)
#define SDMMC_CMD_SD_APP_SET_CER_RN1                  ((uint8_t)45U)
#define SDMMC_CMD_SD_APP_GET_CER_RN2                  ((uint8_t)46U)
#define SDMMC_CMD_SD_APP_SET_CER_RES2                 ((uint8_t)47U)
#define SDMMC_CMD_SD_APP_GET_CER_RES1                 ((uint8_t)48U)
#define SDMMC_CMD_SD_APP_SECURE_READ_MULTIPLE_BLOCK   ((uint8_t)18U)
#define SDMMC_CMD_SD_APP_SECURE_WRITE_MULTIPLE_BLOCK  ((uint8_t)25U)
#define SDMMC_CMD_SD_APP_SECURE_ERASE                 ((uint8_t)38U)
#define SDMMC_CMD_SD_APP_CHANGE_SECURE_AREA           ((uint8_t)49U)
#define SDMMC_CMD_SD_APP_SECURE_WRITE_MKB             ((uint8_t)48U)
/**
  * @}
  */

 /** @defgroup SDMMC_LL_ERROR_STATUS Masks for errors Card Status R1
   * @brief  Masks for errors Card Status R1 (OCR Register)  
  * @{
  */
#define SDMMC_OCR_ADDR_OUT_OF_RANGE        ((uint32_t)0x80000000U)
#define SDMMC_OCR_ADDR_MISALIGNED          ((uint32_t)0x40000000U)
#define SDMMC_OCR_BLOCK_LEN_ERR            ((uint32_t)0x20000000U)
#define SDMMC_OCR_ERASE_SEQ_ERR            ((uint32_t)0x10000000U)
#define SDMMC_OCR_BAD_ERASE_PARAM          ((uint32_t)0x08000000U)
#define SDMMC_OCR_WRITE_PROT_VIOLATION     ((uint32_t)0x04000000U)
#define SDMMC_OCR_LOCK_UNLOCK_FAILED       ((uint32_t)0x01000000U)
#define SDMMC_OCR_COM_CRC_FAILED           ((uint32_t)0x00800000U)
#define SDMMC_OCR_ILLEGAL_CMD              ((uint32_t)0x00400000U)
#define SDMMC_OCR_CARD_ECC_FAILED          ((uint32_t)0x00200000U)
#define SDMMC_OCR_CC_ERROR                 ((uint32_t)0x00100000U)
#define SDMMC_OCR_GENERAL_UNKNOWN_ERROR    ((uint32_t)0x00080000U)
#define SDMMC_OCR_STREAM_READ_UNDERRUN     ((uint32_t)0x00040000U)
#define SDMMC_OCR_STREAM_WRITE_OVERRUN     ((uint32_t)0x00020000U)
#define SDMMC_OCR_CID_CSD_OVERWRITE        ((uint32_t)0x00010000U)
#define SDMMC_OCR_WP_ERASE_SKIP            ((uint32_t)0x00008000U)
#define SDMMC_OCR_CARD_ECC_DISABLED        ((uint32_t)0x00004000U)
#define SDMMC_OCR_ERASE_RESET              ((uint32_t)0x00002000U)
#define SDMMC_OCR_AKE_SEQ_ERROR            ((uint32_t)0x00000008U)
#define SDMMC_OCR_ERRORBITS                ((uint32_t)0xFDFFE008U)
/**
  * @}
  */

 /** @defgroup SDMMC_LL_RESPONSE Masks for R6 Response
  * @{
  */
#define SDMMC_R6_GENERAL_UNKNOWN_ERROR     ((uint32_t)0x00002000U)
#define SDMMC_R6_ILLEGAL_CMD               ((uint32_t)0x00004000U)
#define SDMMC_R6_COM_CRC_FAILED            ((uint32_t)0x00008000U)

#define SDMMC_VOLTAGE_WINDOW_SD            ((uint32_t)0x80100000U)
#define SDMMC_HIGH_CAPACITY                ((uint32_t)0x40000000U)
#define SDMMC_STD_CAPACITY                 ((uint32_t)0x00000000U)
#define SDMMC_CHECK_PATTERN                ((uint32_t)0x000001AAU)
#define SD_SWITCH_1_8V_CAPACITY            ((uint32_t)0x01000000U)

#define SDMMC_MAX_VOLT_TRIAL               ((uint32_t)0x0000FFFFU)

#define SDMMC_MAX_TRIAL                    ((uint32_t)0x0000FFFFU)

#define SDMMC_ALLZERO                      ((uint32_t)0x00000000U)

#define SDMMC_WIDE_BUS_SUPPORT             ((uint32_t)0x00040000U)
#define SDMMC_SINGLE_BUS_SUPPORT           ((uint32_t)0x00010000U)
#define SDMMC_CARD_LOCKED                  ((uint32_t)0x02000000U)

#define SDMMC_DATATIMEOUT                  ((uint32_t)0xFFFFFFFFU)

#define SDMMC_0TO7BITS                     ((uint32_t)0x000000FFU)
#define SDMMC_8TO15BITS                    ((uint32_t)0x0000FF00U)
#define SDMMC_16TO23BITS                   ((uint32_t)0x00FF0000U)
#define SDMMC_24TO31BITS                   ((uint32_t)0xFF000000U)
#define SDMMC_MAX_DATA_LENGTH              ((uint32_t)0x01FFFFFFU)

#define SDMMC_HALFFIFO                     ((uint32_t)0x00000008U)
#define SDMMC_HALFFIFOBYTES                ((uint32_t)0x00000020U)
/**
  * @}
  */

 /** @defgroup SDMMC_LL_CMD_CLASS Command Class supported
  * @{
  */
#define SDIO_CCCC_ERASE                   ((uint32_t)0x00000020U)

#define SDIO_CMDTIMEOUT                   ((uint32_t)5000U)        /* Command send and response timeout */
#define SDIO_MAXERASETIMEOUT              ((uint32_t)63000U)       /* Max erase Timeout 63 s            */
#define SDIO_STOPTRANSFERTIMEOUT          ((uint32_t)100000000U)   /* Timeout for STOP TRANSMISSION command */
/**
  * @}
  */

/** @defgroup SDIO_LL_Clock_Select Clock select
  * @{
  */
#define SDIO_CLOCK_OFFSET_90C              ((uint32_t)0x00000000U)
#define SDIO_CLOCK_OFFSET_180C             SDIO_CLKCR_CKSEL

#define IS_SDIO_CLOCK_SEL(CLKSEL)          (((CLKSEL) == SDIO_CLOCK_OFFSET_90C) || \
                                            ((CLKSEL) == SDIO_CLOCK_OFFSET_180C))
/**
  * @}
  */

/** @defgroup SDIO_LL_PreSampling PreSampling clock
  * @{
  */
#define SDIO_PRE_SAMPLING_DISABLE          ((uint32_t)0x00000000U)
#define SDIO_PRE_SAMPLING_ENABLE           SDIO_CLKCR_SMPEN   

#define IS_SDIO_PRE_SAMPLING(SMPEN)        (((SMPEN) == SDIO_PRE_SAMPLING_DISABLE) || \
                                            ((SMPEN) == SDIO_PRE_SAMPLING_ENABLE))
/**
  * @}
  */ 

/** @defgroup SDIO_LL_PreSampling_Clock_Select Hardware Flow Control
  * @{
  */
#define SDIO_PRE_SAMPLING_CLOCK_OFFSET_NONE     ((uint32_t)0x00000000U)
#define SDIO_PRE_SAMPLING_CLOCK_OFFSET_270C     SDIO_CLKCR_SMPCLKSEL

#define IS_SDIO_PRE_SAMPLING_CLOCK(CONTROL)     (((CONTROL) == SDIO_PRE_SAMPLING_CLOCK_OFFSET_NONE) || \
                                                 ((CONTROL) == SDIO_PRE_SAMPLING_CLOCK_OFFSET_270C))
/**
  * @}
  */

/** @defgroup SDIO_LL_Clock_Power_Save Clock Power Saving
  * @{
  */
#define SDIO_CLOCK_POWER_SAVE_DISABLE      ((uint32_t)0x00000000U)
#define SDIO_CLOCK_POWER_SAVE_ENABLE       SDIO_CLKCR_PWRSAV

#define IS_SDIO_CLOCK_POWER_SAVE(SAVE)     (((SAVE) == SDIO_CLOCK_POWER_SAVE_DISABLE) || \
                                            ((SAVE) == SDIO_CLOCK_POWER_SAVE_ENABLE))
/**
  * @}
  */

/** @defgroup SDIO_LL_Bus_Wide Bus Width
  * @{
  */
#define SDIO_BUS_WIDE_1B                   ((uint32_t)0x00000000U)
#define SDIO_BUS_WIDE_4B                   SDIO_CLKCR_WIDBUS_0
#define SDIO_BUS_WIDE_8B                   SDIO_CLKCR_WIDBUS_1

#define IS_SDIO_BUS_WIDE(WIDE)             (((WIDE) == SDIO_BUS_WIDE_1B) || \
                                            ((WIDE) == SDIO_BUS_WIDE_4B) || \
                                            ((WIDE) == SDIO_BUS_WIDE_8B))
/**
  * @}
  */
  
/** @defgroup SDIO_LL_Clock_Division Clock Division
  * @{
  */
#define IS_SDIO_CLKDIV(DIV)   ((DIV) <= 0xFFU)
/**
  * @}
  */  
    
/** @defgroup SDIO_LL_Command_Index Command Index
  * @{
  */
#define IS_SDIO_CMD_INDEX(INDEX)            ((INDEX) < 0x40U)
/**
  * @}
  */

/** @defgroup SDIO_LL_Response_Type Response Type
  * @{
  */
#define SDIO_RESPONSE_NO                    ((uint32_t)0x00000000U)
#define SDIO_RESPONSE_SHORT                 SDIO_CMD_WAITRESP
#define SDIO_RESPONSE_LONG                  (SDIO_CMD_WAITRESP | SDIO_CMD_RESPLEN)

#define IS_SDIO_RESPONSE(RESPONSE) (((RESPONSE) == SDIO_RESPONSE_NO)    || \
                                            ((RESPONSE) == SDIO_RESPONSE_SHORT) || \
                                            ((RESPONSE) == SDIO_RESPONSE_LONG))
/**
  * @}
  */

/** @defgroup SDIO_LL_Wait_Pend Wait pend config
  * @{
  */
#define SDIO_WAIT_PEND_DISABLE              ((uint32_t)0x00000000U)
#define SDIO_WAIT_PEND_ENABLE               SDIO_CMD_WAITPEND 

#define IS_SDIO_WAITPEND(WAIT)                  (((WAIT) == SDIO_WAIT_PEND_DISABLE) || \
                                             ((WAIT) == SDIO_WAIT_PEND_ENABLE))
/**
  * @}
  */

/** @defgroup SDIO_LL_AutoInit Send initialization sequence (80 clocks)
  * @{
  */
#define SDIO_AUTO_INIT_DISABLE              ((uint32_t)0x00000000U)
#define SDIO_AUTO_INIT_ENABLE               SDIO_CMD_AUTOINIT

#define IS_SDIO_AUTOINIT(AUTOINIT)          (((AUTOINIT) == SDIO_AUTO_INIT_DISABLE) || \
                                             ((AUTOINIT) == SDIO_AUTO_INIT_ENABLE))
/**
  * @}
  */

/** @defgroup SDIO_LL_Check_CRC  Check response crc
  * @{
  */
#define SDIO_CHECK_CRC_DISABLE              ((uint32_t)0x00000000U)
#define SDIO_CHECK_CRC_ENABLE               SDIO_CMD_CHECKRESPCRC

#define IS_SDIO_CHECKCRC(CHECKCRC)          (((CHECKCRC) == SDIO_CHECK_CRC_DISABLE) || \
                                             ((CHECKCRC) == SDIO_CHECK_CRC_ENABLE))
/**
  * @}
  */

/** @defgroup SDIO_LL_DataTransfer  Expected data transmission
  * @{
  */
#define SDIO_DATA_TRANSFER_DISABLE          ((uint32_t)0x00000000U)
#define SDIO_DATA_TRANSFER_ENABLE           SDIO_CMD_DEXPECT

#define IS_SDIO_DATATRANSFER(DEXPECT)       (((DEXPECT) == SDIO_DATA_TRANSFER_DISABLE) || \
                                             ((DEXPECT) == SDIO_DATA_TRANSFER_ENABLE))
/**
  * @}
  */

/** @defgroup SDIO_LL_CPSM_State CPSM State
  * @{
  */
#define SDIO_CPSM_DISABLE                   ((uint32_t)0x00000000U)
#define SDIO_CPSM_ENABLE                    SDIO_CMD_STARTCMD

#define IS_SDIO_CPSM(CPSM)                  (((CPSM) == SDIO_CPSM_DISABLE) || \
                                             ((CPSM) == SDIO_CPSM_ENABLE))
/**
  * @}
  */  

/** @defgroup SDIO_LL_Response_Registers Response Register
  * @{
  */
#define SDIO_RESP1                          ((uint32_t)0x00000000U)
#define SDIO_RESP2                          ((uint32_t)0x00000004U)
#define SDIO_RESP3                          ((uint32_t)0x00000008U)
#define SDIO_RESP4                          ((uint32_t)0x0000000CU)

#define IS_SDIO_RESP(RESP)                  (((RESP) == SDIO_RESP1) || \
                                             ((RESP) == SDIO_RESP2) || \
                                             ((RESP) == SDIO_RESP3) || \
                                             ((RESP) == SDIO_RESP4))
/**
  * @}
  */

/** @defgroup SDIO_LL_Data_Length Data Lenght
  * @{
  */
#define IS_SDIO_DATA_LENGTH(LENGTH) ((LENGTH) <= 0x01FFFFFFU)
/**
  * @}
  */

/** @defgroup SDIO_LL_Data_Block_Size  Data Block Size
  * @{
  */
  #define IS_SDIO_BLOCK_SIZE(SIZE) ((SIZE) < 0x00010000U) 
/**
  * @}
  */

/** @defgroup SDIO_LL_TIMEOUT  Data Block Size
  * @{
  */
  #define IS_SDIO_TIME_OUT(TIME) ((TIME) < 0x01000000U) 
/**
  * @}
  */

/** @defgroup SDIO_LL_Transfer_Direction Transfer Direction
  * @{
  */
#define SDIO_TRANSFER_DIR_TO_SDIO            ((uint32_t)0x00000000)
#define SDIO_TRANSFER_DIR_TO_CARD            SDIO_CMD_DIR

#define IS_SDIO_TRANSFER_DIR(DIR)            (((DIR) == SDIO_TRANSFER_DIR_TO_CARD) || \
                                              ((DIR) == SDIO_TRANSFER_DIR_TO_SDIO))
/**
  * @}
  */

/** @defgroup SDIO_LL_Transfer_Type Transfer Type
  * @{
  */
#define SDIO_TRANSFER_MODE_BLOCK             ((uint32_t)0x00000000U)
#define SDIO_TRANSFER_MODE_STREAM            SDIO_CMD_DTMODE

#define IS_SDIO_TRANSFER_MODE(MODE)          (((MODE) == SDIO_TRANSFER_MODE_BLOCK) || \
                                              ((MODE) == SDIO_TRANSFER_MODE_STREAM))
/**
  * @}
  */

/** @defgroup SDIO_LL_DPSM_State DPSM State
  * @{
  */
#define SDIO_DPSM_DISABLE                    ((uint32_t)0x00000000U)
#define SDIO_DPSM_ENABLE                     SDIO_DCTRL_DTEN

#define IS_SDIO_DPSM(DPSM)                   (((DPSM) == SDIO_DPSM_DISABLE) ||\
                                              ((DPSM) == SDIO_DPSM_ENABLE))
/**
  * @}
  */

/** @defgroup SDIO_LL_FIFO_Threshold FIFO Threshold
  * @{
  */
#define IS_FIFO_THRESHOLD(RX_THRESHOLD, TX_THRESHOLD) (((RX_THRESHOLD) <= 16U) &&\
                                                       ((TX_THRESHOLD) <= 16U))
/**
  * @}
  */

/** @defgroup SDIO_LL_Interrupt_sources Interrupt Sources
  * @{
  */
#define SDIO_IT_CAD                         SDIO_INTMASK_CADIE
#define SDIO_IT_RE                          SDIO_INTMASK_REIE
#define SDIO_IT_CD                          SDIO_INTMASK_CDIE
#define SDIO_IT_DTO                         SDIO_INTMASK_DTOIE
#define SDIO_IT_TXDR                        SDIO_INTMASK_TXDRIE
#define SDIO_IT_RXDR                        SDIO_INTMASK_RXDRIE
#define SDIO_IT_RCRC                        SDIO_INTMASK_RCRCIE
#define SDIO_IT_DCRC                        SDIO_INTMASK_DCRCIE
#define SDIO_IT_RTO_BAR                     SDIO_INTMASK_RTOIE
#define SDIO_IT_DRTO_BDS                    SDIO_INTMASK_DRTOIE
#define SDIO_IT_HTO                         SDIO_INTMASK_HTOIE
#define SDIO_IT_FRUN                        SDIO_INTMASK_FRUNIE
#define SDIO_IT_HLE                         SDIO_INTMASK_HLEIE
#define SDIO_IT_SBE                         SDIO_INTMASK_SBEIE
#define SDIO_IT_ACD                         SDIO_INTMASK_ACDIE
#define SDIO_IT_EBE                         SDIO_INTMASK_EBEIE
#define SDIO_IT_SDIOINT                     SDIO_INTMASK_SDIOINTIE
/**
  * @}
  */ 

/** @defgroup SDIO_LL_Flags Flags
  * @{
  */
#define SDIO_FLAG_CAD                       SDIO_INTSTS_CAD    
#define SDIO_FLAG_RE                        SDIO_INTSTS_RE     
#define SDIO_FLAG_CD                        SDIO_INTSTS_CD     
#define SDIO_FLAG_DTO                       SDIO_INTSTS_DTO    
#define SDIO_FLAG_TXDR                      SDIO_INTSTS_TXDR   
#define SDIO_FLAG_RXDR                      SDIO_INTSTS_RXDR   
#define SDIO_FLAG_RCRC                      SDIO_INTSTS_RCRC   
#define SDIO_FLAG_DCRC                      SDIO_INTSTS_DCRC   
#define SDIO_FLAG_RTO_BAR                   SDIO_INTSTS_RTO_BAR
#define SDIO_FLAG_DRTO_BDS                  SDIO_INTSTS_DRTO_BDS   
#define SDIO_FLAG_HTO                       SDIO_INTSTS_HTO    
#define SDIO_FLAG_FRUN                      SDIO_INTSTS_FRUN   
#define SDIO_FLAG_HLE                       SDIO_INTSTS_HLE    
#define SDIO_FLAG_SBE                       SDIO_INTSTS_SBE    
#define SDIO_FLAG_ACD                       SDIO_INTSTS_ACD    
#define SDIO_FLAG_EBE                       SDIO_INTSTS_EBE    
#define SDIO_FLAG_SDIOINT                   SDIO_INTSTS_SDIOINT
#define SDIO_STATIC_FLAGS                   ((uint32_t)(SDIO_FLAG_CAD | SDIO_FLAG_RE | SDIO_FLAG_CD | SDIO_FLAG_DTO |\
                                                        SDIO_FLAG_TXDR | SDIO_FLAG_RXDR | SDIO_FLAG_RCRC | SDIO_FLAG_DCRC |\
                                                        SDIO_FLAG_RTO_BAR  | SDIO_FLAG_DRTO_BDS | SDIO_FLAG_HTO |\
                                                        SDIO_FLAG_FRUN |SDIO_FLAG_HLE | SDIO_FLAG_SBE | SDIO_FLAG_ACD |\
                                                        SDIO_FLAG_EBE | SDIO_FLAG_SDIOINT))  

#define SDIO_STATIC_CMD_FLAGS               ((uint32_t)(SDIO_FLAG_CAD | SDIO_FLAG_RE | SDIO_FLAG_CD |\
                                                        SDIO_FLAG_RCRC | SDIO_FLAG_RTO_BAR | SDIO_FLAG_HTO |\
                                                        SDIO_FLAG_HLE | SDIO_FLAG_SBE | SDIO_FLAG_ACD))

#define SDIO_STATIC_DATA_FLAGS              ((uint32_t)(SDIO_FLAG_DTO | SDIO_FLAG_TXDR | SDIO_FLAG_DCRC |\
                                                        SDIO_FLAG_DRTO_BDS | SDIO_FLAG_HTO | SDIO_FLAG_FRUN |\
                                                        SDIO_FLAG_HLE | SDIO_FLAG_SBE | SDIO_FLAG_EBE))
/**
  * @}
  */

/**
  * @}
  */
  
/* Exported macro ------------------------------------------------------------*/
/** @defgroup SDMMC_LL_Exported_macros SDMMC Exported Macros
  * @{
  */

/** @defgroup SDMMC_LL_Register Bits And Addresses Definitions
  * @brief SDMMC_LL registers bit address in the alias region
  * @{
  */
/* ---------------------- SDIO registers bit mask --------------------------- */
/* --- CLKCR Register ---*/
/* CLKCR register clear mask */ 
#define CLKCR_CLEAR_MASK         ((uint32_t)(SDIO_CLKCR_CLKDIV  | SDIO_CLKCR_PWRSAV |\
                                             SDIO_CLKCR_CKSEL   | SDIO_CLKCR_WIDBUS |\
                                             SDIO_CLKCR_SMPEN   | SDIO_CLKCR_SMPCLKSEL))

/* --- CMD Register ---*/
/* CMD Register clear mask */
#define CMD_CLEAR_MASK           ((uint32_t)(SDIO_CMD_CMDINDEX_Msk | SDIO_CMD_WAITRESP_Msk |\
                                             SDIO_CMD_RESPLEN_Msk  | SDIO_CMD_CHECKRESPCRC_Msk |\
                                             SDIO_CMD_DEXPECT_Msk  | SDIO_CMD_WAITPEND_Msk |\
                                             SDIO_CMD_STARTCMD_Msk | SDIO_CMD_AUTOINIT_Msk |\
                                             SDIO_CMD_REGSYNC_Msk))

/* SDIO Initialization Frequency (400KHz max) */
#define SDIO_INIT_CLK_DIV     (SystemCoreClock/(400000<<1))   /* SystemCoreClock / (SDMMC_INIT_CLK_DIV * 2) < 400KHz */

/* SDIO Data Transfer Frequency (25MHz max) */
#define SDIO_TRANSFER_CLK_DIV ((uint8_t)0x5)
/**
  * @}
  */

/** @defgroup SDMMC_LL_Interrupt_Clock Interrupt And Clock Configuration
 *  @brief macros to handle interrupts and specific clock configurations
 * @{
 */
 
/**
  * @brief  Enable the SDIO device.
  * @param  __INSTANCE__: SDIO Instance  
  * @retval None
  */
#define __SDIO_ENABLE(__INSTANCE__)  SET_BIT((__INSTANCE__)->CLKCR, SDIO_CLKCR_CLKEN)

/**
  * @brief  Disable the SDIO device.
  * @param  __INSTANCE__: SDIO Instance  
  * @retval None
  */
#define __SDIO_DISABLE(__INSTANCE__)  CLEAR_BIT((__INSTANCE__)->CLKCR, SDIO_CLKCR_CLKEN)

/**
  * @brief  Enable the SDIO DMA transfer.
  * @param  __INSTANCE__: SDIO Instance  
  * @retval None
  */
#define __SDIO_DMA_ENABLE(__INSTANCE__)  SET_BIT((__INSTANCE__)->CTRL, SDIO_CTRL_DMAEN)

/**
  * @brief  Disable the SDIO DMA transfer.
  * @param  __INSTANCE__: SDIO Instance   
  * @retval None
  */
#define __SDIO_DMA_DISABLE(__INSTANCE__)  CLEAR_BIT((__INSTANCE__)->CTRL, SDIO_CTRL_DMAEN)

/**
  * @brief  Enable the SDIO auto send stop command.
  * @param  __INSTANCE__: SDIO Instance  
  * @retval None
  */
#define __SDIO_AUTO_STOP_CMD_ENABLE(__INSTANCE__)  SET_BIT((__INSTANCE__)->CMD, SDIO_CMD_AUTOSTOP)

/**
  * @brief  Disable the SDIO auto send stop command.
  * @param  __INSTANCE__: SDIO Instance  
  * @retval None
  */
#define __SDIO_AUTO_STOP_CMD_DISABLE(__INSTANCE__)  CLEAR_BIT((__INSTANCE__)->CMD, SDIO_CMD_AUTOSTOP)

/**
  * @brief  Whether AutoStop is enable.
  * @param  __INSTANCE__: SDIO Instance   
  * @retval None
  */
#define __SDIO_IS_ENABLE_AUTO_STOP(__INSTANCE__)  (((__INSTANCE__)->CMD & SDIO_CMD_AUTOSTOP) == SDIO_CMD_AUTOSTOP)

/**
  * @brief  Whether card is busy.
  * @param  __INSTANCE__: SDIO Instance   
  * @retval None
  */
#define __SDIO_IS_CARD_BUSY(__INSTANCE__)  (((__INSTANCE__)->STATUS & SDIO_STATUS_CARDBSY) == SDIO_STATUS_CARDBSY)

/**
  * @brief  Whether FIFO is empty.
  * @param  __INSTANCE__: SDIO Instance   
  * @retval None
  */
#define __SDIO_IS_FIFO_EMPTY(__INSTANCE__)  (((__INSTANCE__)->STATUS & SDIO_STATUS_FIFOE) == SDIO_STATUS_FIFOE)

/**
  * @brief  Whether FIFO is full.
  * @param  __INSTANCE__: SDIO Instance   
  * @retval None
  */
#define __SDIO_IS_FIFO_FULL(__INSTANCE__)  (((__INSTANCE__)->STATUS & SDIO_STATUS_FIFOF) == SDIO_STATUS_FIFOF)

/**
  * @brief  Enable SDIO global interrupt.
  * @param  __INSTANCE__: SDIO Instance   
  * @retval None
  */
#define __SDIO_ENABLE_GLOBAL_IT(__INSTANCE__)  SET_BIT((__INSTANCE__)->CTRL, SDIO_CTRL_INTEN)

/**
  * @brief  Disable SDIO global interrupt.
  * @param  __INSTANCE__: SDIO Instance   
  * @retval None
  */
#define __SDIO_DISABLE_GLOBAL_IT(__INSTANCE__)  CLEAR_BIT((__INSTANCE__)->CTRL, SDIO_CTRL_INTEN)

/**
  * @brief  Enable the SDIO device interrupt.
  * @param  __INSTANCE__ : Pointer to SDIO register base  
  * @param  __INTERRUPT__ : specifies the SDIO interrupt sources to be enabled.
  *         This parameter can be one or a combination of the following values:
  *            @arg SDIO_IT_CAD:      Card detect interrupt
  *            @arg SDIO_IT_RE:       Response error interrupt
  *            @arg SDIO_IT_CD:       Command completion interrupt
  *            @arg SDIO_IT_DTO:      Data transfer completion interrupt
  *            @arg SDIO_IT_TXDR:     Transmit FIFO request interrupt
  *            @arg SDIO_IT_RXDR:     Received FIFO request interrupt
  *            @arg SDIO_IT_RCRC:     Command response CRC check error interrupt
  *            @arg SDIO_IT_DCRC:     Data CRC check error interrupt
  *            @arg SDIO_IT_RTO_BAR:  Command response timeout interrupt
  *            @arg SDIO_IT_DRTO_BDS: Data timeout interrupt
  *            @arg SDIO_IT_HTO:      Host timeout interrupt
  *            @arg SDIO_IT_FRUN:     FIFO underrun interrupt
  *            @arg SDIO_IT_HLE:      Hardware lock write interrupt
  *            @arg SDIO_IT_SBE:      Start bit error interrupt
  *            @arg SDIO_IT_ACD:      Automatic command completion interrupt
  *            @arg SDIO_IT_EBE:      End bit error interrupt
  *            @arg SDIO_IT_SDIOINT:  Detect SDIO card interrupt
  * @retval None
  */
#define __SDIO_ENABLE_IT(__INSTANCE__, __INTERRUPT__)  ((__INSTANCE__)->INTMASK |= (__INTERRUPT__))

/**
  * @brief  Disable the SDIO device interrupt.
  * @param  __INSTANCE__ : Pointer to SDIO register base   
  * @param  __INTERRUPT__ : specifies the SDIO interrupt sources to be disabled.
  *          This parameter can be one or a combination of the following values:
  *            @arg SDIO_IT_CAD:      Card detect interrupt
  *            @arg SDIO_IT_RE:       Response error interrupt
  *            @arg SDIO_IT_CD:       Command completion interrupt
  *            @arg SDIO_IT_DTO:      Data transfer completion interrupt
  *            @arg SDIO_IT_TXDR:     Transmit FIFO request interrupt
  *            @arg SDIO_IT_RXDR:     Received FIFO request interrupt
  *            @arg SDIO_IT_RCRC:     Command response CRC check error interrupt
  *            @arg SDIO_IT_DCRC:     Data CRC check error interrupt
  *            @arg SDIO_IT_RTO_BAR:  Command response timeout interrupt
  *            @arg SDIO_IT_DRTO_BDS: Data timeout interrupt
  *            @arg SDIO_IT_HTO:      Host timeout interrupt
  *            @arg SDIO_IT_FRUN:     FIFO underrun interrupt
  *            @arg SDIO_IT_HLE:      Hardware lock write interrupt
  *            @arg SDIO_IT_SBE:      Start bit error interrupt
  *            @arg SDIO_IT_ACD:      Automatic command completion interrupt
  *            @arg SDIO_IT_EBE:      End bit error interrupt
  *            @arg SDIO_IT_SDIOINT:  Detect SDIO card interrupt
  * @retval None
  */
#define __SDIO_DISABLE_IT(__INSTANCE__, __INTERRUPT__)  ((__INSTANCE__)->INTMASK &= ~(__INTERRUPT__))

/**
  * @brief  Checks whether the specified SDIO flag is set or not. 
  * @param  __INSTANCE__ : Pointer to SDIO register base   
  * @param  __FLAG__: specifies the flag to check. 
  *          This parameter can be one of the following values:
  *            @arg SDIO_FLAG_CAD:      Card detect interrupt
  *            @arg SDIO_FLAG_RE:       Response error interrupt
  *            @arg SDIO_FLAG_CD:       Command completion interrupt
  *            @arg SDIO_FLAG_DTO:      Data transfer completion interrupt
  *            @arg SDIO_FLAG_TXDR:     Transmit FIFO request interrupt
  *            @arg SDIO_FLAG_RXDR:     Received FIFO request interrupt
  *            @arg SDIO_FLAG_RCRC:     Command response CRC check error interrupt
  *            @arg SDIO_FLAG_DCRC:     Data CRC check error interrupt
  *            @arg SDIO_FLAG_RTO_BAR:  Command response timeout interrupt
  *            @arg SDIO_FLAG_DRTO_BDS: Data timeout interrupt
  *            @arg SDIO_FLAG_HTO:      Host timeout interrupt
  *            @arg SDIO_FLAG_FRUN:     FIFO underrun interrupt
  *            @arg SDIO_FLAG_HLE:      Hardware lock write interrupt
  *            @arg SDIO_FLAG_SBE:      Start bit error interrupt
  *            @arg SDIO_FLAG_ACD:      Automatic command completion interrupt
  *            @arg SDIO_FLAG_EBE:      End bit error interrupt
  *            @arg SDIO_FLAG_SDIOINT:  Detect SDIO card interrupt
  * @retval The new state of SDIO_FLAG (SET or RESET).
  */
#define __SDIO_GET_FLAG(__INSTANCE__, __FLAG__)  (((__INSTANCE__)->INTSTS &(__FLAG__)) != 0U)


/**
  * @brief  Clears the SDIO specified flags.
  * @param  __INSTANCE__ : Pointer to SDIO register base  
  * @param  __FLAG__: specifies the flag to clear.  
  *          This parameter can be one or a combination of the following values:
  *            @arg SDIO_FLAG_CAD:      Card detect interrupt
  *            @arg SDIO_FLAG_RE:       Response error interrupt
  *            @arg SDIO_FLAG_CD:       Command completion interrupt
  *            @arg SDIO_FLAG_DTO:      Data transfer completion interrupt
  *            @arg SDIO_FLAG_TXDR:     Transmit FIFO request interrupt
  *            @arg SDIO_FLAG_RXDR:     Received FIFO request interrupt
  *            @arg SDIO_FLAG_RCRC:     Command response CRC check error interrupt
  *            @arg SDIO_FLAG_DCRC:     Data CRC check error interrupt
  *            @arg SDIO_FLAG_RTO_BAR:  Command response timeout interrupt
  *            @arg SDIO_FLAG_DRTO_BDS: Data timeout interrupt
  *            @arg SDIO_FLAG_HTO:      Host timeout interrupt
  *            @arg SDIO_FLAG_FRUN:     FIFO underrun interrupt
  *            @arg SDIO_FLAG_HLE:      Hardware lock write interrupt
  *            @arg SDIO_FLAG_SBE:      Start bit error interrupt
  *            @arg SDIO_FLAG_ACD:      Automatic command completion interrupt
  *            @arg SDIO_FLAG_EBE:      End bit error interrupt
  *            @arg SDIO_FLAG_SDIOINT:  Detect SDIO card interrupt
  * @retval None
  */
#define __SDIO_CLEAR_FLAG(__INSTANCE__, __FLAG__)  ((__INSTANCE__)->INTSTS = (__FLAG__))

/**
  * @brief  Enable CMD pullup.
  * @retval None
  */    
#define __SDIO_OD_PULLUP_ENABLE(__INSTANCE__)    SET_BIT((__INSTANCE__)->CTRL, SDIO_CTRL_ODPUEN)
  
/**
  * @brief  Disable CMD pullup.
  * @retval None
  */    
#define __SDIO_OD_PULLUP_DISABLE(__INSTANCE__)    CLEAR_BIT((__INSTANCE__)->CTRL, SDIO_CTRL_ODPUEN)
  
/**
  * @brief  Enables the SDIO card to suspend queues.
  * @retval None
  */    
#define __SDIO_PEND_QUEUSE()         SET_BIT(SDIO->CTRL, SDIO_CTRL_ABORTRD)

/**
  * @brief  Send automatic IRQ response.
  * @retval None
  */    
#define __SDIO_SEND_IRQ()            SET_BIT(SDIO->CTRL, SDIO_CTRL_AUTOIRQRESP)

/**
  * @brief  Send read wait to SDIO card
  * @retval None
  */    
#define __SDIO_SEND_READ_WAIT()      SET_BIT(SDIO->CTRL, SDIO_CTRL_READWAIT)

/**
  * @brief  Reset FIFO
  * @retval None
  */    
#define __SDIO_FIFO_RESET()      SET_BIT(SDIO->CTRL, SDIO_CTRL_FIFORST)

/**
  * @brief  Reset SDIO controller
  * @retval None
  */    
#define __SDIO_CONTR_RESET()      SET_BIT(SDIO->CTRL, SDIO_CTRL_SDIORST)

/**
  * @brief  Send CCSD to CE-ATA.
  * @retval None
  */    
#define __SDIO_CEATA_SEND_CCSD()    SET_BIT(SDIO->CTRL, SDIO_CTRL_CCSDEN)
  
/**
  * @brief  Automatically send STOP after sending CCSD to CE-ATA.
  * @retval None
  */    
#define __SDIO_CEATA_SEND_STOP()    SET_BIT(SDIO->CTRL, SDIO_CTRL_AUTOSTOPCCSD)

/**
  * @brief  Enable the CE-ATA device interrupt.
  * @retval None
  */    
#define __SDIO_CEATA_DEVICE_ENABLE_IT()    SET_BIT(SDIO->CTRL, SDIO_CTRL_CEATAINTEN)

/**
  * @brief  Disable the CE-ATA device interrupt.
  * @retval None
  */  
#define __SDIO_CEATA_DEVICE_DISABLE_IT()   CLEAR_BIT(SDIO->CTRL, SDIO_CTRL_CEATAINTEN)

/**
  * @brief  Enable the CE-ATA interrupt.
  * @retval None
  */    
#define __SDIO_CEATA_ENABLE_IT()    SET_BIT(SDIO->CMD, SDIO_CMD_IEN)

/**
  * @brief  Disable the CE-ATA interrupt.
  * @retval None
  */  
#define __SDIO_CEATA_DISABLE_IT()   CLEAR_BIT(SDIO->CMD, SDIO_CMD_IEN)

/**
  * @brief  Enable send CE-ATA command (CMD61).
  * @retval None
  */  
#define __SDIO_CEATA_SENDCMD_ENABLE()   SET_BIT(SDIO->CMD, SDIO_CMD_STARTCMD)

/**
  * @brief  Disable send CE-ATA command (CMD61).
  * @retval None
  */  
#define __SDIO_CEATA_SENDCMD_DISABLE()   CLEAR_BIT(SDIO->CMD, SDIO_CMD_STARTCMD)

/**
  * @brief  Force start operation.
  * @retval None
  */  
#define __SDIO_EMMC_BOOT_MODE_FORCE()   SET_BIT(SDIO->CMD, SDIO_CMD_BOOTMODE)

/**
  * @brief  Backup startup operation.
  * @retval None
  */  
#define __SDIO_EMMC_BOOT_MODE_BACKUP()   CLEAR_BIT(SDIO->CMD, SDIO_CMD_BOOTMODE)

/**
  * @brief  Enable boot startup.
  * @retval None
  */  
#define __SDIO_EMMC_BOOT_ENABLE()   MODIFY_REG(SDIO->CMD, (SDIO_CMD_BOOTEN| SDIO_CMD_BOOTDIS), \
                                                          (SDIO_CMD_BOOTEN| ~SDIO_CMD_BOOTDIS))

/**
  * @brief  Disable boot startup.
  * @retval None
  */  
#define __SDIO_EMMC_BOOT_DISABLE()   MODIFY_REG(SDIO->CMD, (SDIO_CMD_BOOTEN| SDIO_CMD_BOOTDIS), \
                                                           (~SDIO_CMD_BOOTEN| SDIO_CMD_BOOTDIS))

/**
  * @brief  Reset boot startup.
  * @retval None
  */  
#define __SDIO_EMMC_BOOT_RESET()   CLEAR_BIT(SDIO->CMD,(SDIO_CMD_BOOTEN| SDIO_CMD_BOOTDIS))

/**
  * @brief  Expect boot ack ensable.
  * @retval None
  */  
#define __SDIO_EMMC_BOOT_ACK_ENABLE()   SET_BIT(SDIO->CMD, SDIO_CMD_BOOTMODE)

/**
  * @brief  Expect boot ack disable.
  * @retval None
  */  
#define __SDIO_EMMC_BOOT_ACK_DISABLE()   CLEAR_BIT(SDIO->CMD, SDIO_CMD_BOOTMODE)
/**
  * @}
  */
   
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup SDMMC_LL_Exported_Functions
  * @{
  */
  
/* Initialization/de-initialization functions  **********************************/
/** @addtogroup HAL_SDMMC_LL_Group1
  * @{
  */
HAL_StatusTypeDef SDIO_Init(SDIO_TypeDef *SDIOx, SDIO_InitTypeDef Init);
void SDIO_ClockEnable(SDIO_TypeDef *SDIOx);
void SDIO_ClockDisable(SDIO_TypeDef *SDIOx);
void SDIO_SetClock(SDIO_TypeDef *SDIOx,uint32_t SDIO_ClkDiv);
/**
  * @}
  */
  
/* I/O operation functions  *****************************************************/
/** @addtogroup HAL_SDMMC_LL_Group2
  * @{
  */
uint32_t SDIO_ReadFIFO(SDIO_TypeDef *SDIOx);
HAL_StatusTypeDef SDIO_WriteFIFO(SDIO_TypeDef *SDIOx, uint32_t *pWriteData);
/**
  * @}
  */
  
/* Peripheral Control functions  ************************************************/
/** @addtogroup HAL_SDMMC_LL_Group3
  * @{
  */
HAL_StatusTypeDef SDIO_PowerState_ON(SDIO_TypeDef *SDIOx);
HAL_StatusTypeDef SDIO_PowerState_OFF(SDIO_TypeDef *SDIOx);
uint32_t SDIO_GetPowerState(SDIO_TypeDef *SDIOx);
HAL_StatusTypeDef SDIO_SendCommand(SDIO_TypeDef *SDIOx, SDIO_CmdInitTypeDef *Command);
uint8_t SDIO_GetCommandResponse(SDIO_TypeDef *SDIOx);
uint32_t SDIO_GetResponse(SDIO_TypeDef *SDIOx, uint32_t Response);
HAL_StatusTypeDef SDIO_ConfigData(SDIO_TypeDef *SDIOx, SDIO_DataInitTypeDef* Data);
uint32_t SDIO_GetFIFOCount(SDIO_TypeDef *SDIOx);
HAL_StatusTypeDef SDIO_SetFifoThreshold(SDIO_TypeDef *SDIOx, uint32_t RxWatermark, uint32_t TxWatermark);
/**
  * @}
  */

/* Command management functions  ************************************************/
/** @addtogroup HAL_SDMMC_LL_Group4
  * @{
  */
uint32_t SDMMC_CmdBlockLength(SDIO_TypeDef *SDIOx, uint32_t BlockSize);
uint32_t SDMMC_CmdReadSingleBlock(SDIO_TypeDef *SDIOx, uint32_t ReadAdd);
uint32_t SDMMC_CmdReadMultiBlock(SDIO_TypeDef *SDIOx, uint32_t ReadAdd);
uint32_t SDMMC_CmdWriteSingleBlock(SDIO_TypeDef *SDIOx, uint32_t WriteAdd);
uint32_t SDMMC_CmdWriteMultiBlock(SDIO_TypeDef *SDIOx, uint32_t WriteAdd);
uint32_t SDMMC_CmdSDEraseStartAdd(SDIO_TypeDef *SDIOx, uint32_t StartAdd);
uint32_t SDMMC_CmdSDEraseEndAdd(SDIO_TypeDef *SDIOx, uint32_t EndAdd);
uint32_t SDMMC_CmdEraseStartAdd(SDIO_TypeDef *SDIOx, uint32_t StartAdd);
uint32_t SDMMC_CmdEraseEndAdd(SDIO_TypeDef *SDIOx, uint32_t EndAdd);
uint32_t SDMMC_CmdErase(SDIO_TypeDef *SDIOx);
uint32_t SDMMC_CmdStopTransfer(SDIO_TypeDef *SDIOx);
uint32_t SDMMC_CmdSelDesel(SDIO_TypeDef *SDIOx, uint64_t Addr);
uint32_t SDMMC_CmdGoIdleState(SDIO_TypeDef *SDIOx);
uint32_t SDMMC_CmdOperCond(SDIO_TypeDef *SDIOx);
uint32_t SDMMC_CmdAppCommand(SDIO_TypeDef *SDIOx, uint32_t Argument);
uint32_t SDMMC_CmdAppOperCommand(SDIO_TypeDef *SDIOx, uint32_t Argument);
uint32_t SDMMC_CmdBusWidth(SDIO_TypeDef *SDIOx, uint32_t BusWidth);
uint32_t SDMMC_CmdSendSCR(SDIO_TypeDef *SDIOx);
uint32_t SDMMC_CmdSendCID(SDIO_TypeDef *SDIOx);
uint32_t SDMMC_CmdSendCSD(SDIO_TypeDef *SDIOx, uint32_t Argument);
uint32_t SDMMC_CmdSetRelAdd(SDIO_TypeDef *SDIOx, uint16_t *pRCA);
uint32_t SDMMC_CmdSendStatus(SDIO_TypeDef *SDIOx, uint32_t Argument);
uint32_t SDMMC_CmdStatusRegister(SDIO_TypeDef *SDIOx);
uint32_t SDMMC_CmdOpCondition(SDIO_TypeDef *SDIOx, uint32_t Argument);
uint32_t SDMMC_CmdSwitch(SDIO_TypeDef *SDIOx, uint32_t Argument);
/**
  * @}
  */

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

#endif /* PY32E407_LL_SDMMC_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
