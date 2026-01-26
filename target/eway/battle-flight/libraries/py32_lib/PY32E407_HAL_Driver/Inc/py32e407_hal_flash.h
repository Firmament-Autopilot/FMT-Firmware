/**
  ******************************************************************************
  * @file    py32e407_hal_flash.h
  * @author  MCU Application Team
  * @brief   Header file of FLASH HAL module.
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
#ifndef __PY32E407_HAL_FLASH_H
#define __PY32E407_HAL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup FLASH
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup FLASH_Exported_Types FLASH Exported Types
  * @{
  */

/**
  * @brief  FLASH Erase structure definition
  */
typedef struct
{
  uint32_t TypeErase;        /*!< Mass erase or page erase.
                                  This parameter can be a value of @ref FLASH_Type_Erase */
  uint32_t Banks;            /*!< Select bank to erase.
                                  This parameter must be a value of @ref FLASH_Banks*/
  uint32_t PageAddress;      /*!< PageAdress: Initial FLASH page address to erase when mass erase /sector erase /block erase is disabled
                                  This parameter must be a number between Min_Data = FLASH_BASE and Max_Data = FLASH_END */
  uint32_t NbPages;          /*!< Number of pages to be erased.
                                  This parameter must be a value between 1 and (FLASH_PAGE_NB - value of initial page)*/
  uint32_t SectorAddress;    /*!< SectorAddress: Initial FLASH sector address to erase when mass erase /page erase /block erase is disabled
                                  This parameter must be a number between Min_Data = FLASH_BASE and Max_Data = FLASH_END */    
  uint32_t NbSectors;        /*!< Number of sectors to be erased.
                                  This parameter must be a value between 1 and (FLASH_SECTOR_NB - value of initial sector)*/
  uint32_t BlockAddress;     /*!< BlockAddress: Initial FLASH block address to erase when mass erase /page erase /sector erase is disabled
                                  This parameter must be a number between Min_Data = FLASH_BASE and Max_Data = FLASH_END */    
  uint32_t NbBlocks;         /*!< Number of blocks to be erased.
                                  This parameter must be a value between 1 and (FLASH_BLOCK_NB - value of initial block)*/    
} FLASH_EraseInitTypeDef;

/**
  * @brief  FLASH Option Bytes PROGRAM structure definition
  */
typedef struct
{
  uint32_t  OptionType;         /*!< OptionType: Option byte to be configured.
                                     This parameter can be a value of @ref FLASH_Option_Type */

  uint32_t  WRPBlock;           /*!< WRPBlock: This bitfield specifies the block (s) which are write protected.
                                     This parameter can be a combination of @ref FLASH_Option_Bytes_Write_Protection */
      
  uint32_t  RDPLevel;           /*!< RDPLevel: Set the read protection level.
                                     This parameter can be a value of @ref FLASH_OB_Read_Protection */
  
  uint32_t  USERType;           /*!< User option byte(s) to be configured (used for OPTIONBYTE_USER).
                                     This parameter can be a combination of @ref FLASH_OB_USER_Type */

  uint32_t  USERConfig;         /*!< Value of the user option byte (used for OPTIONBYTE_USER).
                                     This parameter can be a combination of 
                                     @ref FLASH_OB_USER_IWDG_SW,
                                     @ref FLASH_OB_USER_NRST_STOP,
                                     @ref FLASH_OB_USER_nRST_STANDBY,
                                     @ref FLASH_OB_USER_IWDG_STOP,
                                     @ref FLASH_OB_USER_IWDG_STANDBY,
                                     @ref FLASH_OB_USER_IWDG_STOP,
                                     @ref FLASH_OB_USER_BFB,
                                     @ref FLASH_OB_USER_NBOOT1,
                                     @ref FLASH_OB_USER_SRAM_PE,
                                     @ref FLASH_OB_USER_CCMSRAM_RST,
                                     @ref FLASH_OB_USER_nSWBOOT0,
                                     @ref FLASH_OB_USER_nBOOT0,
                                     @ref FLASH_OB_USER_NRST_MODE */
  uint32_t  PCROPConfig;        /*!< Configuration of the PCROP (used for OPTIONBYTE_PCROP).
                                     This parameter can be a combination of @ref FLASH_Banks */  
  uint32_t  PCROPStartAddr;     /*!< PCROP Start address (used for OPTIONBYTE_PCROP).
                                     This parameter must be a value between begin and end of bank
                                     => Be careful of the bank swapping for the address */
  uint32_t  PCROPEndAddr;       /*!< PCROP End address (used for OPTIONBYTE_PCROP).
                                     This parameter must be a value between PCROP Start address and end of bank */
  uint32_t BootEntryPoint;      /*!< Set the Boot Lock (used for OPTIONBYTE_BOOT_LOCK).
                                     This parameter can be a value of @ref FLASH_OB_USER_BOOT_LOCK */
} FLASH_OBProgramInitTypeDef; 

/**
* @brief  FLASH handle Structure definition
*/
typedef struct
{
  HAL_LockTypeDef   Lock;                           /* FLASH locking object */
  uint32_t          ErrorCode;                      /* FLASH error code */
  uint32_t          Busy;                           /* Internal variable to define the current Bank which is erasing or program in IT context */
  uint32_t          ProcedureOnGoing;               /* Internal variable to indicate which procedure is ongoing or not in IT context */
  uint32_t          Address;                        /* Internal variable to save address selected for program in IT context */
  uint32_t          Bank;                           /* Internal variable to save current bank selected during erase in IT context */
  uint32_t          PageOrSectorOrBlock;            /* Internal variable to define the current page or sector or block which is erasing in IT context */
  uint32_t          NbPagesSectorsBlocksToErase;    /* Internal variable to save the remaining pages to erase in IT context */
} FLASH_ProcessTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup FLASH_Exported_Constants FLASH Exported Constants
  * @{
  */

/** @defgroup FLASH_Error FLASH Error
  * @{
  */
#define HAL_FLASH_ERROR_NONE            0x00000000U
#define HAL_FLASH_ERROR_WRP             FLASH_FLAG_WRPERR
#define HAL_FLASH_ERROR_RD              FLASH_FLAG_RDERR
#define HAL_FLASH_ERROR_OPTV            FLASH_FLAG_OPTVERR
#define HAL_FLASH_ERROR_ECCC            FLASH_FLAG_ECCC
#define HAL_FLASH_ERROR_ECCD            FLASH_FLAG_ECCD
/**
  * @}
  */

/** @defgroup FLASH_Type_Erase FLASH erase type
  * @{
  */
#define FLASH_TYPEERASE_MASSERASE       (FLASH_CR_MER0)   /*!<Flash mass erase activation*/
#define FLASH_TYPEERASE_PAGEERASE       (FLASH_CR_PER)  /*!<Flash page erase activation*/
#define FLASH_TYPEERASE_SECTORERASE     (FLASH_CR_SER)  /*!<Flash sector erase activation*/ 
#define FLASH_TYPEERASE_BLOCKERASE      (FLASH_CR_BER)  /*!<Flash block erase activation*/
/**
  * @}
  */

/** @defgroup FLASH_Banks FLASH Banks
  * @{
  */
#define FLASH_BANK_0                     0x00000001U   /*!< Bank0   */
#define FLASH_BANK_1                     0x00000002U   /*!< Bank1   */
#define FLASH_BANK_MSK                  (FLASH_BANK_0 | FLASH_BANK_1) /*!< Bank0 and Bank1 */
/**
  * @}
  */

/** @defgroup FLASH_Option_Type FLASH Option Bytes Type
  * @{
  */
#define OPTIONBYTE_WRP                  0x01U     /*!< WRP option byte configuration */
#define OPTIONBYTE_RDP                  0x02U     /*!< RDP option byte configuration */
#define OPTIONBYTE_USER                 0x04U     /*!< USER option byte configuration */
#define OPTIONBYTE_PCROP                0x08U     /*!< PCROP option byte configuration */
#define OPTIONBYTE_BOOT_LOCK            0x10U     /*!< Boot lock option byte configuration */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_BOOT_LOCK FLASH Boot Lock
  * @{
  */
#define OB_BOOT_LOCK_DISABLE            0x00000000U                    /*!< Boot Lock Disable */
#define OB_BOOT_LOCK_ENABLE             (FLASH_OPTR2_BOOT_LOCK << 16)  /*!< Boot Lock Enable */
/**
  * @}
  */

/** @defgroup FLASH_OB_Read_Protection FLASH Option Bytes Read Protection
  * @{
  */
#define OB_RDP_LEVEL_0                  ((uint8_t)0xAAU)
#define OB_RDP_LEVEL_1                  ((uint8_t)0x55U)
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_Type FLASH User Option Type
  * @{
  */
#define OB_USER_IWDG_SW                 FLASH_OPTR1_IWDG_SW
#define OB_USER_IWDG_STOP               FLASH_OPTR1_IWDG_STOP
#define OB_USER_IWDG_STDBY              FLASH_OPTR1_IWDG_STDBY
#define OB_USER_BFB                     FLASH_OPTR1_BFB
#define OB_USER_NRST_STOP               FLASH_OPTR1_NRST_STOP
#define OB_USER_NRST_STDBY              FLASH_OPTR1_NRST_STDBY
#define OB_USER_WWDG_SW                 FLASH_OPTR1_WWDG_SW

#define OB_USER_NBOOT1                  (FLASH_OPTR2_NBOOT1 << 16)             /*!< Boot configuration */
#define OB_USER_NRST_MODE0              (FLASH_OPTR2_NRST_MODE_0 << 16)        /*!< Reset pin configuration */
#define OB_USER_NRST_MODE1              (FLASH_OPTR2_NRST_MODE_1 << 16)        /*!< Reset pin configuration */
#define OB_USER_NRST_MODE               (FLASH_OPTR2_NRST_MODE << 16)          /*!< Reset pin configuration */
#define OB_USER_SRAM_PE                 (FLASH_OPTR2_SRAM_PE << 16)            /*!< SRAM parity check enable (first 32kB of SRAM1 + CCM SRAM) */
#define OB_USER_CCMSRAM_RST             (FLASH_OPTR2_CCMSRAM_RST << 16)        /*!< CCMSRAM Erase when system reset */
#define OB_USER_NSWBOOT0                (FLASH_OPTR2_NSWBOOT0 << 16)           /*!< Software BOOT0 */
#define OB_USER_NBOOT0                  (FLASH_OPTR2_NBOOT0 << 16)             /*!< nBOOT0 option bit */
#define OB_USER_BOOT_LOCK               (FLASH_OPTR2_BOOT_LOCK << 16)          /*!< Force boot from user Flash area bit */

#define OB_USER_OPTR1_MSK               (OB_USER_IWDG_SW  | OB_USER_IWDG_STOP | OB_USER_IWDG_STDBY | \
                                         OB_USER_BFB      | OB_USER_NRST_STOP | OB_USER_NRST_STDBY | \
                                         OB_USER_WWDG_SW)
#define OB_USER_OPTR2_MSK               (OB_USER_NBOOT1   | OB_USER_SRAM_PE   | OB_USER_CCMSRAM_RST| \
                                         OB_USER_NSWBOOT0 | OB_USER_NBOOT0    | OB_USER_NRST_MODE0 | \
                                         OB_USER_NRST_MODE1 | OB_USER_BOOT_LOCK)
#define OB_USER_OPTR_MSK                (OB_USER_OPTR1_MSK | OB_USER_OPTR2_MSK)
/**
  * @}
  */

/** @defgroup FLASH_Option_Bytes_Write_Protection FLASH Option Bytes Write Protection
  * @{
  */
#define FLASH_WRPR_WRP_0                0x00000001U  /* Write protection of Block0 */
#define FLASH_WRPR_WRP_1                0x00000002U  /* Write protection of Block1 */
#define FLASH_WRPR_WRP_2                0x00000004U  /* Write protection of Block2 */
#define FLASH_WRPR_WRP_3                0x00000008U  /* Write protection of Block3 */
#define FLASH_WRPR_WRP_4                0x00000010U  /* Write protection of Block4 */
#define FLASH_WRPR_WRP_5                0x00000020U  /* Write protection of Block5 */
#define FLASH_WRPR_WRP_6                0x00000040U  /* Write protection of Block6 */
#define FLASH_WRPR_WRP_7                0x00000080U  /* Write protection of Block7 */

#define OB_WRP_BLOCK_0                  FLASH_WRPR_WRP_0  /* Write protection of Block0 */
#define OB_WRP_BLOCK_1                  FLASH_WRPR_WRP_1  /* Write protection of Block1 */
#define OB_WRP_BLOCK_2                  FLASH_WRPR_WRP_2  /* Write protection of Block2 */
#define OB_WRP_BLOCK_3                  FLASH_WRPR_WRP_3  /* Write protection of Block3 */
#define OB_WRP_BLOCK_4                  FLASH_WRPR_WRP_4  /* Write protection of Block4 */
#define OB_WRP_BLOCK_5                  FLASH_WRPR_WRP_5  /* Write protection of Block5 */
#define OB_WRP_BLOCK_6                  FLASH_WRPR_WRP_6  /* Write protection of Block6 */
#define OB_WRP_BLOCK_7                  FLASH_WRPR_WRP_7  /* Write protection of Block7 */

#define OB_WRP_Pages0to127              OB_WRP_BLOCK_0    /* Write protection of Block0 */
#define OB_WRP_Pages128to255            OB_WRP_BLOCK_1    /* Write protection of Block1 */
#define OB_WRP_Pages256to383            OB_WRP_BLOCK_2    /* Write protection of Block2 */
#define OB_WRP_Pages384to511            OB_WRP_BLOCK_3    /* Write protection of Block3 */
#define OB_WRP_Pages512to639            OB_WRP_BLOCK_4    /* Write protection of Block4 */
#define OB_WRP_Pages640to767            OB_WRP_BLOCK_5    /* Write protection of Block5 */
#define OB_WRP_Pages768to895            OB_WRP_BLOCK_6    /* Write protection of Block6 */
#define OB_WRP_Pages896to1023           OB_WRP_BLOCK_7    /* Write protection of Block7 */
#define OB_WRP_AllPages                 FLASH_WRPR_WRP    /* Write protection of all Blocks */
/**
  * @}
  */
  
/** @defgroup FLASH_Type_Program FLASH type program
  * @{
  */
#define FLASH_TYPEPROGRAM_PAGE          FLASH_CR_PG  /*!<Program 256bytes at a specified address.*/  
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_NRST_STOP FLASH Option Bytes NRST_STOP
  * @{
  */
#define OB_STOP_RST                     0x00000000U           /*!< Reset generated when entering Stop mode */
#define OB_STOP_NORST                   FLASH_OPTR1_NRST_STOP /*!< No reset generated when entering Stop mode*/
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_nRST_STANDBY FLASH Option Bytes User Reset On Standby
  * @{
  */
#define OB_STANDBY_RST                  0x00000000U              /*!< Reset generated when entering the standby mode */
#define OB_STANDBY_NORST                FLASH_OPTR1_NRST_STDBY   /*!< No reset generated when entering the standby mode */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_IWDG_SW FLASH Option Bytes IWatchdog
  * @{
  */
#define OB_IWDG_HW                      0x00000000U          /*!< Hardware IWDG selected */
#define OB_IWDG_SW                      FLASH_OPTR1_IWDG_SW  /*!< Software IWDG selected */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_IWDG_STOP FLASH Option Bytes User IWDG Mode On Stop
  * @{
  */
#define OB_IWDG_STOP_FREEZE             0x00000000U              /*!< Independent watchdog counter is frozen in Stop mode */
#define OB_IWDG_STOP_RUN                FLASH_OPTR1_IWDG_STOP    /*!< Independent watchdog counter is running in Stop mode */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_IWDG_STANDBY FLASH Option Bytes User IWDG Mode On Standby
  * @{
  */
#define OB_IWDG_STDBY_FREEZE            0x00000000U              /*!< Independent watchdog counter is frozen in Standby mode */
#define OB_IWDG_STDBY_RUN               FLASH_OPTR1_IWDG_STDBY    /*!< Independent watchdog counter is running in Standby mode */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_WWDG_SW FLASH Option Bytes User WWDG Type
  * @{
  */
#define OB_WWDG_HW                      0x00000000U              /*!< Hardware window watchdog */
#define OB_WWDG_SW                      FLASH_OPTR1_WWDG_SW      /*!< Software window watchdog */
/**
  * @}
  */
  
/** @defgroup FLASH_OB_USER_BFB FLASH Option Bytes User BFB Mode
  * @{
  */
#define OB_BFB_START_BANK0              0x00000000U              /*!< FLASH start from BANK0 */
#define OB_BFB_START_BANK1              FLASH_OPTR1_BFB          /*!< FLASH start from BANK1 */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_NBOOT1 FLASH Option Bytes User BOOT1 Type
  * @{
  */
#define OB_BOOT1_SRAM                   0x00000000U                 /*!< Embedded SRAM1 is selected as boot space (if BOOT0=1) */
#define OB_BOOT1_SYSTEM                 (FLASH_OPTR2_NBOOT1 << 16)  /*!< System memory is selected as boot space (if BOOT0=1) */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_SRAM_PE FLASH Option Bytes User SRAM Parity Check Type
  * @{
  */
#define OB_SRAM_PARITY_ENABLE           0x00000000U                  /*!< SRAM parity check enable (first 32kB of SRAM1 + CCM SRAM) */
#define OB_SRAM_PARITY_DISABLE          (FLASH_OPTR2_SRAM_PE << 16)  /*!< SRAM parity check disable (first 32kB of SRAM1 + CCM SRAM) */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_CCMSRAM_RST FLASH Option Bytes User CCMSRAM Erase On Reset Type
  * @{
  */
#define OB_CCMSRAM_RST_ERASE            0x00000000U                       /*!< CCMSRAM erased when a system reset occurs */
#define OB_CCMSRAM_RST_NOT_ERASE        (FLASH_OPTR2_CCMSRAM_RST << 16)  /*!< CCMSRAM is not erased when a system reset occurs */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_nSWBOOT0 FLASH Option Bytes User Software BOOT0
  * @{
  */
#define OB_BOOT0_FROM_OB                0x00000000U                   /*!< BOOT0 taken from the option bit nBOOT0 */
#define OB_BOOT0_FROM_PIN               (FLASH_OPTR2_NSWBOOT0 << 16)  /*!< BOOT0 taken from BOOT0 pin */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_nBOOT0 FLASH Option Bytes User nBOOT0 option bit
  * @{
  */
#define OB_NBOOT0_RESET                 0x00000000U                 /*!< nBOOT0 = 0 */
#define OB_NBOOT0_SET                   (FLASH_OPTR2_NBOOT0 << 16)  /*!< nBOOT0 = 1 */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_NRST_MODE FLASH Option Bytes User NRST mode bit
  * @{
  */
#define OB_NRST_MODE_INPUT_ONLY         (FLASH_OPTR2_NRST_MODE_0 << 16)   /*!< Reset pin is in Reset input mode only */
#define OB_NRST_MODE_GPIO               (FLASH_OPTR2_NRST_MODE_1 << 16)  /*!< Reset pin is in GPIO mode only */
#define OB_NRST_MODE_INPUT_OUTPUT       (FLASH_OPTR2_NRST_MODE   << 16)  /*!< Reset pin is in reset input and output mode */
/**
  * @}
  */

/** @defgroup FLASH_Latency FLASH Latency
  * @{
  */
#define FLASH_LATENCY_0                 (0x00000000UL)                                                                           /*!< FLASH 0 wait state */
#define FLASH_LATENCY_1                 (                                                                  FLASH_ACR_LATENCY_0)  /*!< FLASH 1 wait state */
#define FLASH_LATENCY_3                 (                                            FLASH_ACR_LATENCY_1 | FLASH_ACR_LATENCY_0)  /*!< FLASH 3 wait state */
#define FLASH_LATENCY_4                 (                      FLASH_ACR_LATENCY_2                                            )  /*!< FLASH 4 wait state */
#define FLASH_LATENCY_5                 (                      FLASH_ACR_LATENCY_2                       | FLASH_ACR_LATENCY_0)  /*!< FLASH 5 wait state */
#define FLASH_LATENCY_6                 (                      FLASH_ACR_LATENCY_2 | FLASH_ACR_LATENCY_1                      )  /*!< FLASH 6 wait state */
#define FLASH_LATENCY_7                 (                      FLASH_ACR_LATENCY_2 | FLASH_ACR_LATENCY_1 | FLASH_ACR_LATENCY_0)  /*!< FLASH 7 wait state */
/**
  * @}
  */

/** @defgroup FLASH_Flags FLASH Flags Definition
  * @{
  */
#define FLASH_FLAG_EOP                  FLASH_SR_EOP       /*!< FLASH End of operation flag */
#define FLASH_FLAG_WRPERR               FLASH_SR_WRPERR    /*!< FLASH Write protection error flag */
#define FLASH_FLAG_RDERR                FLASH_SR_RDERR     /*!< FLASH Write protection error flag */
#define FLASH_FLAG_OPTVERR              FLASH_SR_OPTVERR   /*!< FLASH Option validity error flag */
#define FLASH_FLAG_BSY0                 FLASH_SR_BSY0      /*!< FLASH Operation Busy0 flag */
#define FLASH_FLAG_BSY1                 FLASH_SR_BSY1      /*!< FLASH Operation Busy1 flag */
#define FLASH_FLAG_ECCC                 FLASH_ECCR_ECCC    /*!< FLASH ECC correction */
#define FLASH_FLAG_ECCD                 FLASH_ECCR_ECCD    /*!< FLASH ECC detection */

#define FLASH_FLAG_SR_ERRORS            (FLASH_FLAG_WRPERR | FLASH_FLAG_RDERR | FLASH_FLAG_OPTVERR)
#define FLASH_FLAG_ECCR_ERRORS          (FLASH_FLAG_ECCC   | FLASH_FLAG_ECCD)

#define FLASH_FLAG_ALL_ERRORS           (FLASH_FLAG_SR_ERRORS | FLASH_FLAG_ECCR_ERRORS)
/**
  * @}
  */

/** @defgroup FLASH_Interrupt_definition FLASH Interrupts Definition
  * @brief FLASH Interrupt definition
  * @{
  */
#define FLASH_IT_EOP                    FLASH_CR_EOPIE              /*!< End of FLASH Operation Interrupt source */
#define FLASH_IT_OPERR                  FLASH_CR_ERRIE              /*!< Error Interrupt source */
#define FLASH_IT_RDERR                  FLASH_CR_RDERRIE            /*!< PCROP Read Error Interrupt source*/
#define FLASH_IT_ECCC                   (FLASH_ECCR_ECCCIE >> 24U)  /*!< ECC Correction Interrupt source */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup FLASH_Exported_Macros FLASH Exported Macros
  *  @brief macros to control FLASH features
  *  @{
  */

/**
  * @brief  Set the FLASH Latency.
  * @param  __LATENCY__ FLASH Latency
  *         This parameter can be one of the following values :
  *     @arg @ref FLASH_LATENCY_0 FLASH Zero wait state
  *     @arg @ref FLASH_LATENCY_1 FLASH One wait state
  *     @arg @ref FLASH_LATENCY_3 LASH Three wait states
  *     @arg @ref FLASH_LATENCY_4 FLASH Four wait states
  *     @arg @ref FLASH_LATENCY_5 FLASH Five wait states
  *     @arg @ref FLASH_LATENCY_6 FLASH Six wait states
  *     @arg @ref FLASH_LATENCY_7 FLASH Seven wait states
  * @retval None
  */
#define __HAL_FLASH_SET_LATENCY(__LATENCY__)    MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, (__LATENCY__))

/**
  * @brief  Get the FLASH Latency.
  * @retval FLASH Latency
  *         Returned value can be one of the following values :
  *     @arg @ref FLASH_LATENCY_0 FLASH Zero wait state
  *     @arg @ref FLASH_LATENCY_1 FLASH One wait state
  *     @arg @ref FLASH_LATENCY_3 LASH Three wait states
  *     @arg @ref FLASH_LATENCY_4 FLASH Four wait states
  *     @arg @ref FLASH_LATENCY_5 FLASH Five wait states
  *     @arg @ref FLASH_LATENCY_6 FLASH Six wait states
  *     @arg @ref FLASH_LATENCY_7 FLASH Seven wait states
  */
#define __HAL_FLASH_GET_LATENCY()               READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY)

/** @defgroup FLASH_Interrupt FLASH Interrupts Macros
 *  @brief macros to handle FLASH interrupts
 * @{
 */

/**
  * @brief  Enable the FLASH prefetch buffer.
  * @retval None
  */
#define __HAL_FLASH_PREFETCH_BUFFER_ENABLE()    SET_BIT(FLASH->ACR, FLASH_ACR_PRFTEN)

/**
  * @brief  Disable the FLASH prefetch buffer.
  * @retval None
  */
#define __HAL_FLASH_PREFETCH_BUFFER_DISABLE()   CLEAR_BIT(FLASH->ACR, FLASH_ACR_PRFTEN)

/**
  * @brief  Enable the FLASH instruction cache.
  * @retval none
  */
#define __HAL_FLASH_INSTRUCTION_CACHE_ENABLE()  SET_BIT(FLASH->ACR, FLASH_ACR_ICEN)

/**
  * @brief  Disable the FLASH instruction cache.
  * @retval none
  */
#define __HAL_FLASH_INSTRUCTION_CACHE_DISABLE() CLEAR_BIT(FLASH->ACR, FLASH_ACR_ICEN)

/**
  * @brief  Enable the FLASH data cache.
  * @retval none
  */
#define __HAL_FLASH_DATA_CACHE_ENABLE()         SET_BIT(FLASH->ACR, FLASH_ACR_DCEN)

/**
  * @brief  Disable the FLASH data cache.
  * @retval none
  */
#define __HAL_FLASH_DATA_CACHE_DISABLE()        CLEAR_BIT(FLASH->ACR, FLASH_ACR_DCEN)

/**
  * @brief  Enable the specified FLASH interrupt.
  * @param  __INTERRUPT__ FLASH interrupt
  *         This parameter can be any combination of the following values:
  *     @arg @ref FLASH_IT_EOP End of FLASH Operation Interrupt
  *     @arg @ref FLASH_IT_OPERR Error Interrupt
  *     @arg @ref FLASH_IT_RDERR PCROP Read Error Interrupt
  *     @arg @ref FLASH_IT_ECCC  ECC Correction Interrupt
  * @retval none
  */
#define __HAL_FLASH_ENABLE_IT(__INTERRUPT__)    do { if(((__INTERRUPT__) & FLASH_IT_ECCC) != 0U) { SET_BIT(FLASH->ECCR, FLASH_ECCR_ECCCIE); }\
                                                     if(((__INTERRUPT__) & (~FLASH_IT_ECCC)) != 0U) { SET_BIT(FLASH->CR, ((__INTERRUPT__) & (~FLASH_IT_ECCC))); }\
                                                   } while (0)

/**
  * @brief  Disable the specified FLASH interrupt.
  * @param  __INTERRUPT__ FLASH interrupt
  *         This parameter can be any combination of the following values:
  *     @arg @ref FLASH_IT_EOP End of FLASH Operation Interrupt
  *     @arg @ref FLASH_IT_OPERR Error Interrupt
  *     @arg @ref FLASH_IT_RDERR PCORP Read Error Interrupt
  *     @arg @ref FLASH_IT_ECCC  ECC Correction Interrupt
  * @retval none
  */
#define __HAL_FLASH_DISABLE_IT(__INTERRUPT__)   do { if(((__INTERRUPT__) & FLASH_IT_ECCC) != 0U) { CLEAR_BIT(FLASH->ECCR, FLASH_ECCR_ECCCIE); }\
                                                     if(((__INTERRUPT__) & (~FLASH_IT_ECCC)) != 0U) { CLEAR_BIT(FLASH->CR, ((__INTERRUPT__) & (~FLASH_IT_ECCC))); }\
                                                   } while (0)

/**
  * @brief  Check whether the specified FLASH flag is set or not.
  * @param  __FLAG__ specifies the FLASH flag to check.
  *   This parameter can be one of the following values:
  *     @arg @ref FLASH_FLAG_EOP FLASH End of Operation flag
  *     @arg @ref FLASH_FLAG_WRPERR FLASH Write protection error flag
  *     @arg @ref FLASH_FLAG_RDERR FLASH Read protection error flag
  *     @arg @ref FLASH_FLAG_OPTVERR FLASH Option validity error flag
  *     @arg @ref FLASH_FLAG_ECCC FLASH one ECC error has been detected and corrected
  *     @arg @ref FLASH_FLAG_ECCD FLASH two ECC errors have been detected
  * @retval The new state of FLASH_FLAG (SET or RESET).
  */
#define __HAL_FLASH_GET_FLAG(__FLAG__)          ((((__FLAG__) & FLASH_FLAG_ECCR_ERRORS) != 0U) ? \
                                                 (READ_BIT(FLASH->ECCR, (__FLAG__)) == (__FLAG__)) : \
                                                 (READ_BIT(FLASH->SR,   (__FLAG__)) == (__FLAG__)))

/**
  * @brief  Clear the FLASHs pending flags.
  * @param  __FLAG__ specifies the FLASH flags to clear.
  *   This parameter can be any combination of the following values:
  *     @arg @ref FLASH_FLAG_EOP FLASH End of Operation flag
  *     @arg @ref FLASH_FLAG_WRPERR FLASH Write protection error flag
  *     @arg @ref FLASH_FLAG_RDERR FLASH Read protection error flag
  *     @arg @ref FLASH_FLAG_OPTVERR FLASH Option validity error flag
  *     @arg @ref FLASH_FLAG_ECCC FLASH one ECC error has been detected and corrected
  *     @arg @ref FLASH_FLAG_ECCD FLASH two ECC errors have been detected
  * @retval None
  */
#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)        do { if(((__FLAG__) & FLASH_FLAG_ECCR_ERRORS) != 0U) { SET_BIT(FLASH->ECCR, ((__FLAG__) & FLASH_FLAG_ECCR_ERRORS)); }\
                                                     if(((__FLAG__) & ~(FLASH_FLAG_ECCR_ERRORS)) != 0U) { WRITE_REG(FLASH->SR, ((__FLAG__) & ~(FLASH_FLAG_ECCR_ERRORS))); }\
                                                   } while (0)

/**
  * @}
  */

/**
  * @}
  */
/* Include FLASH HAL Extended module */
#include "py32e407_hal_flash_ex.h"

/* Exported variables --------------------------------------------------------*/
/** @defgroup FLASH_Exported_Variables FLASH Exported Variables
  * @{
  */
extern FLASH_ProcessTypeDef pFlash;
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup FLASH_Exported_Functions
  * @{
  */

/* Program operation functions  ***********************************************/
/** @addtogroup FLASH_Exported_Functions_Group1
  * @{
  */
HAL_StatusTypeDef  HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint32_t *DataAddr );
HAL_StatusTypeDef  HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint32_t *DataAddr);
HAL_StatusTypeDef  HAL_FLASH_PageProgram(uint32_t Address, uint32_t *DataAddr );
HAL_StatusTypeDef  HAL_FLASH_PageProgram_IT(uint32_t Address, uint32_t *DataAddr);
/* FLASH IRQ handler method */
void               HAL_FLASH_IRQHandler(void);
/* Callbacks in non blocking modes */
void               HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue);
void               HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue);

#define HAL_FLASH_Erase        HAL_FLASHEx_Erase
#define HAL_FLASH_Erase_IT     HAL_FLASHEx_Erase_IT
#define HAL_FLASH_OBProgram    HAL_FLASHEx_OBProgram
/**
  * @}
  */

/* Peripheral Control functions  **********************************************/
/** @addtogroup FLASH_Exported_Functions_Group2
  * @{
  */
HAL_StatusTypeDef  HAL_FLASH_Unlock(void);
HAL_StatusTypeDef  HAL_FLASH_Lock(void);
/* Option bytes control */
HAL_StatusTypeDef  HAL_FLASH_OB_Unlock(void);
HAL_StatusTypeDef  HAL_FLASH_OB_Lock(void);
HAL_StatusTypeDef  HAL_FLASH_OB_Launch(void);

void               HAL_FLASH_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);
HAL_StatusTypeDef  HAL_FLASH_OB_RDP_LevelConfig(uint8_t ReadProtectLevel);
HAL_StatusTypeDef  HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);
HAL_StatusTypeDef  HAL_FLASH_OB_RDPConfig(uint32_t RDPLevel);


/**
  * @}
  */

/* Peripheral State functions  ************************************************/
/** @addtogroup FLASH_Exported_Functions_Group3
  * @{
  */
uint32_t HAL_FLASH_GetError(void);
uint32_t HAL_FLASH_ECCCheckStatus(void);
/**
  * @}
  */

/**
  * @}
  */

/* Private functions --------------------------------------------------------*/
/** @defgroup FLASH_Private_Functions FLASH Private Functions
  * @{
  */
HAL_StatusTypeDef  FLASH_WaitForLastOperation(uint32_t Timeout);

/**
  * @}
  */

/* Private constants --------------------------------------------------------*/
/** @defgroup FLASH_Private_Constants FLASH Private Constants
  * @{
  */
#define FLASH_TIMEOUT_VALUE             1000U          /*!< FLASH Execution Timeout, 1 s */

#define FLASH_TYPENONE                  0x00000000U    /*!< No Programmation Procedure On Going */

#define FLASH_FLAG_SR_ERROR             (FLASH_FLAG_OPTVERR  | FLASH_FLAG_WRPERR | FLASH_FLAG_RDERR)     /*!< All SR error flags */

#define FLASH_FLAG_SR_CLEAR             (FLASH_FLAG_SR_ERROR | FLASH_SR_EOP)
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup FLASH_Private_Macros FLASH Private Macros
 *  @{
 */
#define IS_FLASH_TYPEERASE(__VALUE__)                 (((__VALUE__) == FLASH_TYPEERASE_PAGEERASE)   || \
                                                       ((__VALUE__) == FLASH_TYPEERASE_SECTORERASE) || \
                                                       ((__VALUE__) == FLASH_TYPEERASE_BLOCKERASE)  || \
                                                       ((__VALUE__) == FLASH_TYPEERASE_MASSERASE))

#define IS_FLASH_BANK(__BANK__)                       (((__BANK__) == FLASH_BANK_0)  || \
                                                       ((__BANK__) == FLASH_BANK_1)  || \
                                                       ((__BANK__) == FLASH_BANK_MSK))

#define IS_FLASH_BANK_EXCLUSIVE(__BANK__)             (((__BANK__) == FLASH_BANK_0)  || \
                                                       ((__BANK__) == FLASH_BANK_1))
                                            
#define IS_FLASH_MAIN_MEM_ADDRESS(__ADDRESS__)        (((__ADDRESS__) >= (FLASH_BASE)) && ((__ADDRESS__) <= (FLASH_BASE + FLASH_SIZE - 1UL)))

#define IS_FLASH_PROGRAM_MAIN_MEM_ADDRESS(__ADDRESS__) (((__ADDRESS__) >= (FLASH_BASE)) && ((__ADDRESS__) <= (FLASH_BASE + FLASH_SIZE - 512UL)))

#define IS_FLASH_PROGRAM_ADDRESS(__ADDRESS__)         (IS_FLASH_PROGRAM_MAIN_MEM_ADDRESS(__ADDRESS__))

#define IS_FLASH_NB_PAGES(__ADDRESS__, __VALUE__)     (((__ADDRESS__) >= (FLASH_BASE)) && ((__ADDRESS__ + ((__VALUE__*FLASH_PAGE_SIZE)) - 1) <= (FLASH_BASE + FLASH_SIZE - 1UL))&&(__VALUE__ >0 ))

#define IS_FLASH_NB_SECTORS(__ADDRESS__, __VALUE__)   (((__ADDRESS__) >= (FLASH_BASE)) && ((__ADDRESS__ + ((__VALUE__*FLASH_SECTOR_SIZE)) - 1) <= (FLASH_BASE + FLASH_SIZE - 1UL))&&(__VALUE__>0 ))

#define IS_FLASH_NB_BLOCKS(__ADDRESS__, __VALUE__)    (((__ADDRESS__) >= (FLASH_BASE)) && ((__ADDRESS__ + ((__VALUE__*FLASH_BLOCK_SIZE)) - 1) <= (FLASH_BASE + FLASH_SIZE - 1UL)) &&(__VALUE__ >0 ))

#define IS_FLASH_PAGE(__PAGE__)                       ((__PAGE__) < FLASH_PAGE_NB)

#define IS_OPTIONBYTE(__VALUE__)                      (((__VALUE__) <= (OPTIONBYTE_WRP | OPTIONBYTE_RDP | OPTIONBYTE_USER | OPTIONBYTE_PCROP)))

#define IS_FLASH_TYPEPROGRAM(__VALUE__)               ((__VALUE__) == FLASH_TYPEPROGRAM_PAGE)

#define IS_OB_WRPAREA(__VALUE__)                      (((__VALUE__) == OB_WRP_BLOCK_0) || \
                                                       ((__VALUE__) == OB_WRP_BLOCK_1) || \
                                                       ((__VALUE__) == OB_WRP_BLOCK_2) || \
                                                       ((__VALUE__) == OB_WRP_BLOCK_3) || \
                                                       ((__VALUE__) == OB_WRP_BLOCK_4) || \
                                                       ((__VALUE__) == OB_WRP_BLOCK_5) || \
                                                       ((__VALUE__) == OB_WRP_BLOCK_6) || \
                                                       ((__VALUE__) == OB_WRP_BLOCK_7))

#define IS_OB_BOOT_LOCK(__VALUE__)                    (((__VALUE__) == OB_BOOT_LOCK_ENABLE) || \
                                                       ((__VALUE__) == OB_BOOT_LOCK_DISABLE))

#define IS_OB_RDP_LEVEL(__LEVEL__)                     (((__LEVEL__) == OB_RDP_LEVEL_0) || \
                                                        ((__LEVEL__) == OB_RDP_LEVEL_1))

#define IS_OB_USER_TYPE(__TYPE__)                     ((((__TYPE__) & OB_USER_OPTR_MSK) != 0x00U) && \
                                                       (((__TYPE__) & ~OB_USER_OPTR_MSK) == 0x00U))

#define IS_OB_USER_CONFIG(__TYPE__,__CONFIG__)         ((~(__TYPE__) & (__CONFIG__)) == 0x00U)

#define IS_OB_USER_STOP(__VALUE__)                    (((__VALUE__) == OB_STOP_RST) || \
                                                       ((__VALUE__) == OB_STOP_NORST))

#define IS_OB_USER_STANDBY(__VALUE__)                 (((__VALUE__) == OB_STANDBY_RST) || \
                                                       ((__VALUE__) == OB_STANDBY_NORST))

#define IS_OB_USER_IWDG(__VALUE__)                    (((__VALUE__) == OB_IWDG_HW) || \
                                                       ((__VALUE__) == OB_IWDG_SW))

#define IS_OB_USER_IWDG_STOP(__VALUE__)               (((__VALUE__) == OB_IWDG_STOP_FREEZE) || \
                                                       ((__VALUE__) == OB_IWDG_STOP_RUN))

#define IS_OB_USER_IWDG_STDBY(__VALUE__)              (((__VALUE__) == OB_IWDG_STDBY_FREEZE) || \
                                                       ((__VALUE__) == OB_IWDG_STDBY_RUN))

#define IS_OB_USER_WWDG(__VALUE__)                    (((__VALUE__) == OB_WWDG_HW) || \
                                                       ((__VALUE__) == OB_WWDG_SW))
                                                       
#define IS_OB_USER_BFB(__VALUE__)                     (((__VALUE__) == OB_BFB_START_BANK0) || \
                                                       ((__VALUE__) == OB_BFB_START_BANK1))

#define IS_OB_USER_BOOT1(__VALUE__)                   (((__VALUE__) == OB_BOOT1_SRAM) || \
                                                       ((__VALUE__) == OB_BOOT1_SYSTEM))

#define IS_OB_USER_SRAM_PARITY(__VALUE__)             (((__VALUE__) == OB_SRAM_PARITY_ENABLE) || \
                                                       ((__VALUE__) == OB_SRAM_PARITY_DISABLE))

#define IS_OB_USER_CCMSRAM_RST(__VALUE__)             (((__VALUE__) == OB_CCMSRAM_RST_ERASE) || \
                                                       ((__VALUE__) == OB_CCMSRAM_RST_NOT_ERASE))

#define IS_OB_USER_SWBOOT0(__VALUE__)                 (((__VALUE__) == OB_BOOT0_FROM_OB) || \
                                                       ((__VALUE__) == OB_BOOT0_FROM_PIN))

#define IS_OB_USER_BOOT0(__VALUE__)                   (((__VALUE__) == OB_NBOOT0_RESET) || \
                                                       ((__VALUE__) == OB_NBOOT0_SET))

#define IS_OB_USER_NRST_MODE(__VALUE__)               (((__VALUE__) == OB_NRST_MODE_GPIO) || \
                                                       ((__VALUE__) == OB_NRST_MODE_INPUT_ONLY) || \
                                                       ((__VALUE__) == OB_NRST_MODE_INPUT_OUTPUT))

#define IS_FLASH_LATENCY(__LATENCY__)                  (((__LATENCY__) == FLASH_LATENCY_0)  || \
                                                        ((__LATENCY__) == FLASH_LATENCY_1)  || \
                                                        ((__LATENCY__) == FLASH_LATENCY_3)  || \
                                                        ((__LATENCY__) == FLASH_LATENCY_4)  || \
                                                        ((__LATENCY__) == FLASH_LATENCY_5)  || \
                                                        ((__LATENCY__) == FLASH_LATENCY_6)  || \
                                                        ((__LATENCY__) == FLASH_LATENCY_7))

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

#endif /* __PY32E407_HAL_FLASH_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
