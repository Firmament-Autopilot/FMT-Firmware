/**
  ******************************************************************************
  * @file    py32e407_ll_flash.h
  * @author  MCU Application Team
  * @brief   Header file of FLASH LL module.
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
#ifndef PY32E407_LL_FLASH_H
#define PY32E407_LL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (FLASH)

/** @defgroup FLASH_LL FLASH
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup FLASH_LL_Exported_Constants FLASH Exported Constants
  * @{
  */
 /** @defgroup FLASH_LL_EC_USERSTYPE FLASH Users Type
  * @{
  */
#define LL_FLASH_OPTR_IWDG_STOP      FLASH_OPTR1_IWDG_STOP
#define LL_FLASH_OPTR_IWDG_STDBY     FLASH_OPTR1_IWDG_STDBY
#define LL_FLASH_OPTR_BFB            FLASH_OPTR1_BFB
#define LL_FLASH_OPTR_IWDG_SW        FLASH_OPTR1_IWDG_SW
#define LL_FLASH_OPTR_NRST_STOP      FLASH_OPTR1_NRST_STOP
#define LL_FLASH_OPTR_NRST_STDBY     FLASH_OPTR1_NRST_STDBY
#define LL_FLASH_OPTR_WWDG_SW        FLASH_OPTR1_WWDG_SW
#define LL_FLASH_OPTR_RDP            FLASH_OPTR1_RDP

#define LL_FLASH_OPTR_NBOOT1         FLASH_OPTR2_NBOOT1             /*!< Boot configuration */
#define LL_FLASH_OPTR_NRST_MODE      FLASH_OPTR2_NRST_MODE          /*!< Reset pin configuration */
#define LL_FLASH_OPTR_NRST_MODE0     FLASH_OPTR2_NRST_MODE_0        /*!< Reset pin configuration */
#define LL_FLASH_OPTR_NRST_MODE1     FLASH_OPTR2_NRST_MODE_1        /*!< Reset pin configuration */
#define LL_FLASH_OPTR_SRAM_PE        FLASH_OPTR2_SRAM_PE            /*!< SRAM1 and CCM SRAM parity check permission bit */
#define LL_FLASH_OPTR_CCMSRAM_RST    FLASH_OPTR2_CCMSRAM_RST        /*!< CCM SRAM erasure configuration during system reset */
#define LL_FLASH_OPTR_NSWBOOT0       FLASH_OPTR2_NSWBOOT0           /*!< Software BOOT0 */
#define LL_FLASH_OPTR_NBOOT0         FLASH_OPTR2_NBOOT0             /*!< nBOOT0 option bit */
#define LL_FLASH_OPTR_BOOT_LOCK      FLASH_OPTR2_BOOT_LOCK          /*!< Force boot from user Flash area bit */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_BOOT_LOCK BOOT Lock
  * @{
  */
#define LL_FLASH_BOOT_FROM_OB         0x00000000U              /*!< BOOT from IO or OB */
#define LL_FLASH_BOOT_FROM_MAINFLASH  (FLASH_OPTR2_BOOT_LOCK)  /*!< BOOT from MainFlash */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_BFB BFB Mode
  * @{
  */
#define LL_FLASH_BFB_START_BANK0          (0x00000000U)       /*!< Hardware WWDG selected */
#define LL_FLASH_BFB_START_BANK1          (FLASH_OPTR1_BFB)   /*!< Software WWDG selected */
/**
  * @}
  */

/** @defgroup FLASH_LL_NBOOT1 FLASH Option Bytes User nBOOT1 Type
  * @{
  */
#define LL_FLASH_NBOOT1_SRAM                   0x00000000U                  /*!< Embedded SRAM1 is selected as boot space (if BOOT0=1) */
#define LL_FLASH_NBOOT1_SYSTEM                 (FLASH_OPTR2_NBOOT1)         /*!< System memory is selected as boot space (if BOOT0=1) */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_SRAMPE Sram Parity Enable
  * @{
  */
 #define LL_FLASH_SRAM_PARITY_DISABLE          (0x00000000U)               /*!< Disable SRAM1 and CCM SRAM parity check permission bit */
 #define LL_FLASH_SRAM_PARITY_ENABLE           (FLASH_OPTR2_SRAM_PE)       /*!< Enable SRAM1 and CCM SRAM parity check permission bit */
 /**
   * @}
   */
 
/** @defgroup FLASH_LL_EC_NRSTMODE NRST Mode
  * @{
  */
#define LL_FLASH_NRST_MODE_RESET_INPUT_ONLY   (FLASH_OPTR2_NRST_MODE_0)   /*!< Reset pin is in Reset input mode only */
#define LL_FLASH_NRST_MODE_GPIO               (FLASH_OPTR2_NRST_MODE_1)   /*!< Reset pin is in GPIO mode only */
#define LL_FLASH_NRST_MODE_RESET_INPUT_OUTPUT (FLASH_OPTR2_NRST_MODE  )   /*!< Reset pin is in reset input and output mode */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_WWDGMODE WWDG Mode
  * @{
  */
#define LL_FLASH_WWDG_MODE_HW          (0x00000000U)                        /*!< Hardware WWDG selected */
#define LL_FLASH_WWDG_MODE_SW          (FLASH_OPTR1_WWDG_SW)                /*!< Software WWDG selected */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_IWDGMODE IWDG Mode
  * @{
  */
#define LL_FLASH_IWDG_MODE_HW          (0x00000000U)                        /*!< Hardware IWDG selected */
#define LL_FLASH_IWDG_MODE_SW          (FLASH_OPTR1_IWDG_SW)                /*!< Software IWDG selected */
/**
  * @}
  */

/** @defgroup FLASH_OB_USER_IWDG_STANDBY FLASH Option Bytes User IWDG Mode On Standby
  * @{
  */
#define LL_FLASH_IWDG_INSTANDBY_FREEZE            0x00000000U               /*!< Independent watchdog counter is frozen in Standby mode */
#define LL_FLASH_IWDG_INSTANDBY_ACTIVE            FLASH_OPTR1_IWDG_STDBY    /*!< Independent watchdog counter is running in Standby mode */
/**
  * @}
  */
  
/** @defgroup FLASH_OB_USER_IWDG_STOP FLASH Option Bytes User IWDG Mode On Stop
  * @{
  */
#define LL_FLASH_IWDG_INSTOP_FREEZE             0x00000000U                 /*!< Independent watchdog counter is frozen in Stop mode */
#define LL_FLASH_IWDG_INSTOP_ACTIVE             FLASH_OPTR1_IWDG_STOP       /*!< Independent watchdog counter is running in Stop mode */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_STOP_RST_MODE STOP RST Mode
  * @{
  */
#define LL_FLASH_STOP_RST              (0x00000000U)                        /*!< Reset generated when entering Stop mode */
#define LL_FLASH_STOP_NORST            (FLASH_OPTR1_NRST_STOP)              /*!< No reset generated when entering Stop mode */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_STANDBY_RST_MODE STANDBY RST Mode
  * @{
  */
#define LL_FLASH_STANDBY_RST           (0x00000000U)                        /*!< Reset generated when entering Standby mode */
#define LL_FLASH_STANDBY_NORST         (FLASH_OPTR1_NRST_STDBY)             /*!< No reset generated when entering Standby mode */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_RDP RDP Mode
  * @{
  */
#define LL_FLASH_RDP_LEVEL_0         ((uint8_t)0xAAU)
#define LL_FLASH_RDP_LEVEL_1         ((uint8_t)0x55U)
/**
  * @}
  */

/** @defgroup FLASH_Banks FLASH Banks
  * @{
  */
#define LL_FLASH_BANK_0                    0x00000001U   /*!< Bank0   */
#define LL_FLASH_BANK_1                    0x00000002U   /*!< Bank1   */
#define LL_FLASH_BANK_MSK                  (LL_FLASH_BANK_0 | LL_FLASH_BANK_1) /*!< Bank0 and Bank1 */
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_ECC_DETECT FLASH ECC DETECT
  * @{
  */          
#define LL_FLASH_ECC_DETECTIN_SYSTEMFLASH      ((uint32_t)FLASH_ECCR_SYSF_ECC)
#define LL_FLASH_ECC_DETECTIN_BANK0            ((uint32_t)0x00000000U)
#define LL_FLASH_ECC_DETECTIN_BANK1            ((uint32_t)FLASH_ECCR_BK_ECC)
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_WRP Write Protection
  * @{
  */
#define LL_FLASH_WRP_DISABLE          ((uint32_t)0x00000000)   /* Write protection disable */
#define LL_FLASH_WRP_BLOCK_0          ((uint32_t)0x00000001)   /* Write protection of Block0 */
#define LL_FLASH_WRP_BLOCK_1          ((uint32_t)0x00000002)   /* Write protection of Block1 */
#define LL_FLASH_WRP_BLOCK_2          ((uint32_t)0x00000004)   /* Write protection of Block2 */
#define LL_FLASH_WRP_BLOCK_3          ((uint32_t)0x00000008)   /* Write protection of Block3 */
#define LL_FLASH_WRP_BLOCK_4          ((uint32_t)0x00000010)   /* Write protection of Block4 */
#define LL_FLASH_WRP_BLOCK_5          ((uint32_t)0x00000020)   /* Write protection of Block5 */
#define LL_FLASH_WRP_BLOCK_6          ((uint32_t)0x00000040)   /* Write protection of Block6 */
#define LL_FLASH_WRP_BLOCK_7          ((uint32_t)0x00000080)   /* Write protection of Block7 */

#define LL_FLASH_WRP_Pages0to127      LL_FLASH_WRP_BLOCK_0     /* Write protection of Block0 */
#define LL_FLASH_WRP_Pages128to255    LL_FLASH_WRP_BLOCK_1     /* Write protection of Block1 */
#define LL_FLASH_WRP_Pages256to383    LL_FLASH_WRP_BLOCK_2     /* Write protection of Block2 */
#define LL_FLASH_WRP_Pages384to511    LL_FLASH_WRP_BLOCK_3     /* Write protection of Block3 */
#define LL_FLASH_WRP_Pages512to639    LL_FLASH_WRP_BLOCK_4     /* Write protection of Block4 */
#define LL_FLASH_WRP_Pages640to767    LL_FLASH_WRP_BLOCK_5     /* Write protection of Block5 */
#define LL_FLASH_WRP_Pages768to895    LL_FLASH_WRP_BLOCK_6     /* Write protection of Block6 */
#define LL_FLASH_WRP_Pages896to1023   LL_FLASH_WRP_BLOCK_7     /* Write protection of Block7 */
#define LL_FLASH_WRP_AllPages         FLASH_WRPR_WRP           /* Write protection of all Blocks */

/**
  * @}
  */

/** @defgroup FLASH_LL_EC_KEY Key Value
  * @{
  */
#define LL_FLASH_KEY1                  (FLASH_KEY1)
#define LL_FLASH_KEY2                  (FLASH_KEY2)
/**
  * @}
  */

/** @defgroup FLASH_LL_EC_OPTKEY Optkey Value
  * @{
  */
#define LL_FLASH_OPTKEY1               (FLASH_OPTKEY1)
#define LL_FLASH_OPTKEY2               (FLASH_OPTKEY2)
/**
  * @}
  */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup FLASH_LL_Exported_Macros FLASH Exported Macros
  * @{
  */

/** @defgroup FLASH_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in FLASH register
  * @param  __INSTANCE__ FLASH Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_FLASH_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in FLASH register
  * @param  __INSTANCE__ FLASH Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_FLASH_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup FLASH_LL_Exported_Functions FLASH Exported Functions
  * @{
  */

/** @defgroup FLASH_LL_EF_FLAG_Management Flag Management
  * @{
  */

/**
  * @brief  Indicate the status of End of operation flag.
  * @rmtoll SR          EOP              LL_FLASH_IsActiveFlag_EOP
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_EOP(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_EOP) == (FLASH_SR_EOP));
}

/**
  * @brief  Indicate the status of WRPERR flag.
  * @rmtoll SR          WPRERR           LL_FLASH_IsActiveFlag_WRPERR
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_WRPERR(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_WRPERR) == (FLASH_SR_WRPERR));
}

/**
  * @brief  Indicate the status of RDERR flag.
  * @rmtoll SR          RDERR              LL_FLASH_IsActiveFlag_RDERR
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_RDERR(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_RDERR) == (FLASH_SR_RDERR));
}

/**
  * @brief  Indicate the status of OPTVERR flag.
  * @rmtoll SR          OPTVERR          LL_FLASH_IsActiveFlag_OPTVERR
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_OPTVERR(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_OPTVERR) == (FLASH_SR_OPTVERR));
}

/**
  * @brief  Indicate the status of BUSY0 flag.
  * @rmtoll SR          BSY0              LL_FLASH_IsActiveFlag_BUSY0
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_BUSY0(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_BSY0) == (FLASH_SR_BSY0));
}

/**
  * @brief  Indicate the status of BUSY1 flag.
  * @rmtoll SR          BSY1              LL_FLASH_IsActiveFlag_BUSY1
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_BUSY1(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->SR, FLASH_SR_BSY1) == (FLASH_SR_BSY1));
}

/**
  * @brief  Indicate the status of ECCD flag.
  * @rmtoll ECCR          ECCD              LL_FLASH_IsActiveFlag_ECCD
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_ECCD(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->ECCR, FLASH_ECCR_ECCD) == (FLASH_ECCR_ECCD));
}

/**
  * @brief  Indicate the status of ECCC flag.
  * @rmtoll ECCR          ECCC              LL_FLASH_IsActiveFlag_ECCC
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsActiveFlag_ECCC(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->ECCR, FLASH_ECCR_ECCC) == (FLASH_ECCR_ECCC));
}

/**
  * @brief  Clear End of operation flag.
  * @rmtoll SR          EOP              LL_FLASH_ClearFlag_EOP
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_EOP(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->SR, FLASH_SR_EOP);
}

/**
  * @brief  Clear WRPERR flag.
  * @rmtoll SR          WRPERR           LL_FLASH_ClearFlag_WRPERR
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_WRPERR(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->SR, FLASH_SR_WRPERR);
}

/**
  * @brief  Clear RDERR flag.
  * @rmtoll SR          RDERR           LL_FLASH_ClearFlag_RDERR
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_RDERR(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->SR, FLASH_SR_RDERR);
}

/**
  * @brief  Clear OPTVERR flag.
  * @rmtoll SR          OPTVERR          LL_FLASH_ClearFlag_OPTVERR
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_OPTVERR(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->SR, FLASH_SR_OPTVERR);
}

/**
  * @brief  Clear ECCD flag.
  * @rmtoll ECCR          ECCD          LL_FLASH_ClearFlag_ECCD
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_ECCD(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->ECCR,FLASH_ECCR_ECCD);
}

/**
  * @brief  Clear ECCC flag.
  * @rmtoll ECCR          ECCC          LL_FLASH_ClearFlag_ECCC
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_ClearFlag_ECCC(FLASH_TypeDef *FLASHx)
{
  WRITE_REG(FLASHx->ECCR,FLASH_ECCR_ECCC);
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_ERASE_Management Erase Management
  * @{
  */

/**
  * @brief  Enable Page Program
  * @rmtoll CR          PG               LL_FLASH_EnablePageProgram
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnablePageProgram(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_PG);
}

/**
  * @brief  Enable Page Erase
  * @rmtoll CR          PER              LL_FLASH_EnablePageErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnablePageErase(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_PER);
}

/**
  * @brief  Enable Mass Erase Bank0
  * @rmtoll CR          MER0              LL_FLASH_EnableMassEraseBank0
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableMassEraseBank0(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_MER0);
}

/**
  * @brief  Enable Mass Erase Bank1
  * @rmtoll CR          MER1              LL_FLASH_EnableMassEraseBank1
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableMassEraseBank1(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_MER1);
}

/**
  * @brief  Enable Sector Erase
  * @rmtoll CR          SER              LL_FLASH_EnableSectorErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableSectorErase(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_SER);
}

/**
  * @brief  Enable Block Erase
  * @rmtoll CR          BER              LL_FLASH_EnableBlockErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
 __STATIC_INLINE void LL_FLASH_EnableBlockErase(FLASH_TypeDef *FLASHx)
 {
   SET_BIT(FLASHx->CR, FLASH_CR_BER);
 }
  
/**
  * @brief  Disable Page Program
  * @rmtoll CR          PG               LL_FLASH_DisablePageProgram
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisablePageProgram(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_PG);
}

/**
  * @brief  Disable Page Erase
  * @rmtoll CR          PER              LL_FLASH_DisablePageErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisablePageErase(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_PER);
}

/**
  * @brief  Disable Mass Erase Bank0
  * @rmtoll CR          MER0              LL_FLASH_DisableMassEraseBank0
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableMassEraseBank0(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_MER0);
}

/**
  * @brief  Disable Mass Erase Bank1
  * @rmtoll CR          MER1              LL_FLASH_DisableMassEraseBank1
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableMassEraseBank1(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_MER1);
}

/**
  * @brief  Disable Sector Erase
  * @rmtoll CR          SER              LL_FLASH_DisableSectorErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableSectorErase(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_SER);
}

/**
  * @brief  Disable Sector Erase
  * @rmtoll CR          BER              LL_FLASH_DisableBlockErase
  * @param  FLASHx FLASH Instance
  * @retval None
  */
 __STATIC_INLINE void LL_FLASH_DisableBlockErase(FLASH_TypeDef *FLASHx)
 {
   CLEAR_BIT(FLASHx->CR, FLASH_CR_BER);
 }
  
/**
  * @brief  Check if Page Program is enabled
  * @rmtoll CR          PG               LL_FLASH_IsEnabledPageProgram
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledPageProgram(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_PG) == (FLASH_CR_PG)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Page erase is enabled
  * @rmtoll CR          PER              LL_FLASH_IsEnabledPageErase
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledPageErase(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_PER) == (FLASH_CR_PER)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Bank0 Mass erase is enabled
  * @rmtoll CR          MER0              LL_FLASH_IsEnabledMassEraseBank0
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledMassEraseBank0(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_MER0) == (FLASH_CR_MER0)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Bank1 Mass erase is enabled
  * @rmtoll CR          MER1              LL_FLASH_IsEnabledMassEraseBank1
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledMassEraseBank1(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_MER1) == (FLASH_CR_MER1)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Sector Erase is enabled
  * @rmtoll CR          SER              LL_FLASH_IsEnabledSectorErase
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledSectorErase(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_SER) == (FLASH_CR_SER)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Sector Erase is enabled
  * @rmtoll CR          BER              LL_FLASH_IsEnabledBlockErase
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
 __STATIC_INLINE uint32_t LL_FLASH_IsEnabledBlockErase(FLASH_TypeDef *FLASHx)
 {
   return ((READ_BIT(FLASHx->CR, FLASH_CR_BER) == (FLASH_CR_BER)) ? 1UL : 0UL);
 }
  
/**
  * @brief  Set the Erase Address
  * @rmtoll LL_FLASH_SetEraseAddress
  * @param  FLASHx FLASH Instance
  * @param  address Erase address
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetEraseAddress(FLASH_TypeDef *FLASHx,uint32_t address)
{
  *(__IO uint32_t *)(address) = 0xFFFFFFFF;
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_Lock_Management Lock Management
  * @{
  */

/**
  * @brief Unlock the Flash
  * @rmtoll KEYR        KEYR             LL_FLASH_Unlock
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_Unlock(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->KEYR, LL_FLASH_KEY1);
  SET_BIT(FLASHx->KEYR, LL_FLASH_KEY2);
}

/**
  * @brief  Unlock the Option
  * @rmtoll OPTKEYR     OPTKEYR          LL_FLASH_OBUnlock
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_OBUnlock(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->OPTKEYR, LL_FLASH_OPTKEY1);
  SET_BIT(FLASHx->OPTKEYR, LL_FLASH_OPTKEY2);
}


/**
  * @brief  Lock the Flash
  * @rmtoll CR          LOCK             LL_FLASH_Lock
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_Lock(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_LOCK);
}

/**
  * @brief  Lock the Option
  * @rmtoll CR          OPTLOCK          LL_FLASH_OBLock
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_OBLock(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_OPTLOCK);
}

/**
  * @brief  Check if Flash is locked
  * @rmtoll CR          LOCK             LL_FLASH_IsLocked
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsLocked(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_LOCK) == (FLASH_CR_LOCK)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Option is locked
  * @rmtoll CR          OPTLOCK          LL_FLASH_IsOBLocked
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsOBLocked(FLASH_TypeDef *FLASHx)
{
  return ((READ_BIT(FLASHx->CR, FLASH_CR_OPTLOCK) == (FLASH_CR_OPTLOCK)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_LAUNCH_Management Launch Management
  * @{
  */

/**
  * @brief  Force the Option byte loading
  * @rmtoll CR          OBL_LAUNCH       LL_FLASH_Launch
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_Launch(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_OBL_LAUNCH);
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_IT_Management Interrupt Management
  * @{
  */

/**
  * @brief  Enable Error interrupts.
  * @rmtoll CR          ERRIR            LL_FLASH_EnableIT_ERR
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableIT_ERR(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_ERRIE);
}

/**
  * @brief  Enable End of operation interrupts.
  * @rmtoll CR          EOPIE            LL_FLASH_EnableIT_EOP
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableIT_EOP(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_EOPIE);
}


/**
  * @brief  Enable PCROP0 Read error interrupts.
  * @rmtoll CR          RDERRIE            LL_FLASH_EnableIT_RDERR
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableIT_RDERR(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_RDERRIE);
}

/**
  * @brief  Enable eccc interrupts.
  * @rmtoll ECCR          ECCCIE            LL_FLASH_EnableIT_ECCC
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableIT_ECCC(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->ECCR, FLASH_ECCR_ECCCIE);
}

/**
  * @brief  Disable Error interrupts.
  * @rmtoll CR          ERRIE            LL_FLASH_DisableIT_ERR
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableIT_ERR(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_ERRIE);
}

/**
  * @brief  Disable End of operation interrupts.
  * @rmtoll CR          EOPIE            LL_FLASH_DisableIT_EOP
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableIT_EOP(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_EOPIE);
}

/**
  * @brief  Disable End of operation interrupts.
  * @rmtoll CR          RDERRIE            LL_FLASH_DisableIT_RDERR
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableIT_RDERR(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_RDERRIE);
}

/**
  * @brief  Disable ECCC interrupts.
  * @rmtoll ECCR          ECCCIE            LL_FLASH_DisableIT_ECCC
  * @param  FLASHx FLASH Instance.
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableIT_ECCC(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->ECCR, FLASH_ECCR_ECCCIE);
}

/**
  * @brief  Check if Error interrupts are enabled or disabled.
  * @rmtoll CR          ERRIE            LL_FLASH_IsEnabledIT_ERR
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledIT_ERR(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->CR, FLASH_CR_ERRIE) == (FLASH_CR_ERRIE));
}

/**
  * @brief  Check if End of operation interrupts are enabled or disabled.
  * @rmtoll CR          EOPIE            LL_FLASH_IsEnabledIT_EOP
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledIT_EOP(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->CR, FLASH_CR_EOPIE) == (FLASH_CR_EOPIE));
}

/**
  * @brief  Check if PCROP0 Read error interrupts are enabled or disabled.
  * @rmtoll CR          RDERRIE            LL_FLASH_IsEnabledIT_RDERR
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledIT_RDERR(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->CR, FLASH_CR_RDERRIE) == (FLASH_CR_RDERRIE));
}

/**
  * @brief  Check if ECCC interrupts are enabled or disabled.
  * @rmtoll ECCR          ECCCIE            LL_FLASH_IsEnabledIT_ECCC
  * @param  FLASHx FLASH Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledIT_ECCC(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->ECCR, FLASH_ECCR_ECCCIE) == (FLASH_ECCR_ECCCIE));
}

/**
  * @brief  Return ECC Area.
  * @rmtoll ECCR          BK_ECC            LL_FLASH_GetECCDetectArea
  * @rmtoll ECCR          SYSF_ECC          LL_FLASH_GetECCDetectArea
  * @param  FLASHx FLASH Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_ECC_DETECTIN_SYSTEMFLASH
  *         @arg @ref LL_FLASH_ECC_DETECTIN_BANK0
  *         @arg @ref LL_FLASH_ECC_DETECTIN_BANK1
  */
__STATIC_INLINE uint32_t LL_FLASH_GetECCDetectArea(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->ECCR, FLASH_ECCR_BK_ECC | FLASH_ECCR_SYSF_ECC);
}

/**
  * @brief  Return ECC Address.
  * @rmtoll ECCR          ADDR_ECC            LL_FLASH_GetECCDetectAddress
  * @param  FLASHx FLASH Instance.
  * @retval Returned the ECC Detect Address
  */
__STATIC_INLINE uint32_t LL_FLASH_GetECCDetectAddress(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->ECCR, FLASH_ECCR_ADDR_ECC);
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_PROGRAM_Management Program Management
  * @{
  */

/**
  * @brief  Enable Page Program Start
  * @rmtoll CR          PGSTRT           LL_FLASH_EnablePageProgramStart
  * @param  FLASHx FLASH Instance
  * @retval None.
  */
__STATIC_INLINE void LL_FLASH_EnablePageProgramStart(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_PGSTRT);
}

/**
  * @brief  Enable Option Program Start
  * @rmtoll CR          OPTSTRT          LL_FLASH_EnableOptionProgramStart
  * @param  FLASHx FLASH Instance
  * @retval None.
  */
__STATIC_INLINE void LL_FLASH_EnableOptionProgramStart(FLASH_TypeDef *FLASHx)
{
  SET_BIT(FLASHx->CR, FLASH_CR_OPTSTRT);
}

/**
  * @brief Disable Page Program start
  * @rmtoll CR          PGSTRT           LL_FLASH_DisablePageProgramStart
  * @param  FLASHx FLASH Instance
  * @retval None.
  */
__STATIC_INLINE void LL_FLASH_DisablePageProgramStart(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_PGSTRT);
}

/**
  * @brief  Disable Option Program start
  * @rmtoll CR          OPTSTRT          LL_FLASH_DisableOptionProgramStart
  * @param  FLASHx FLASH Instance
  * @retval None.
  */
__STATIC_INLINE void LL_FLASH_DisableOptionProgramStart(FLASH_TypeDef *FLASHx)
{
  CLEAR_BIT(FLASHx->CR, FLASH_CR_OPTSTRT);
}

/**
  * @brief  Check if Page Program start is enabled
  * @rmtoll CR          PGSTRT              LL_FLASH_IsEnabledPageProgramStart
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledPageProgramStart(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->CR, FLASH_CR_PGSTRT) == (FLASH_CR_PGSTRT));
}

/**
  * @brief  Check if Option program Start is enabled
  * @rmtoll CR          OPTSTRT         LL_FLASH_IsEnabledOptionProgramStart
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_FLASH_IsEnabledOptionProgramStart(FLASH_TypeDef *FLASHx)
{
  return (READ_BIT(FLASHx->CR, FLASH_CR_OPTSTRT) == (FLASH_CR_OPTSTRT));
}

/**
  * @brief  Trigger the Option Program
  * @param  FLASHx FLASH Instance
  * @retval None.
  */
__STATIC_INLINE void LL_FLASH_TriggerOptionProgramStart(FLASH_TypeDef *FLASHx)
{
  *((__IO uint32_t *)(0x1FFF7400)) = 0xff;
}

/**
  * @brief  Program the page
  * @rmtoll CR          PGSTRT          LL_FLASH_PageProgram
  * @param  FLASHx FLASH Instance
  * @param  Address   Program Address
  * @param  DataAddress Data Address
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_PageProgram(FLASH_TypeDef *FLASHx,uint32_t Address, uint32_t * DataAddress)
{
  uint8_t index=0;
  uint32_t dest = Address;
  uint32_t * src = DataAddress;
  uint32_t primask_bit;
  /* Enter critical section */
  primask_bit = __get_PRIMASK();
  __disable_irq();
  /* 128 words*/
  while(index < 128U)
  {
    *(uint32_t *)dest = *src;
    src += 1U;
    dest += 4U;
    index++;
    if(index == 127)
    {
      LL_FLASH_EnablePageProgramStart(FLASHx);
    }
  }

  /* Exit critical section: restore previous priority mask */
  __set_PRIMASK(primask_bit);
}

/**
  * @}
  */

/** @defgroup FLASH_LL_EF_WRP_Management WRP Management
  * @{
  */

/**
  * @brief  Set WRP Address
  * @rmtoll WRPR        WRP             LL_FLASH_SetWRPRAddress
  * @param  FLASHx FLASH Instance
  * @param  Address This parameter can be a combination of the following values:
  *         @arg @ref LL_FLASH_WRP_DISABLE
  *         @arg @ref LL_FLASH_WRP_BLOCK_0
  *         @arg @ref LL_FLASH_WRP_BLOCK_1
  *         @arg @ref LL_FLASH_WRP_BLOCK_2
  *         @arg @ref LL_FLASH_WRP_BLOCK_3
  *         @arg @ref LL_FLASH_WRP_BLOCK_4
  *         @arg @ref LL_FLASH_WRP_BLOCK_5
  *         @arg @ref LL_FLASH_WRP_BLOCK_6
  *         @arg @ref LL_FLASH_WRP_BLOCK_7
  *         @arg @ref LL_FLASH_WRP_Pages0to127
  *         @arg @ref LL_FLASH_WRP_Pages128to255
  *         @arg @ref LL_FLASH_WRP_Pages256to383
  *         @arg @ref LL_FLASH_WRP_Pages384to511
  *         @arg @ref LL_FLASH_WRP_Pages512to639
  *         @arg @ref LL_FLASH_WRP_Pages640to767
  *         @arg @ref LL_FLASH_WRP_Pages768to895
  *         @arg @ref LL_FLASH_WRP_Pages896to1023
  *         @arg @ref LL_FLASH_WRP_AllPages
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetWRPRAddress(FLASH_TypeDef *FLASHx,uint32_t Address)
{
  MODIFY_REG(FLASHx->WRPR, FLASH_WRPR_WRP, ((~(Address) & 0xFFFF) & (FLASH_WRPR_WRP)));
}

/**
  * @brief  Get WRP Address
  * @rmtoll WRPR        WRP             LL_FLASH_GetWRPRAddress
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be a combination of the following values:
  *         @arg @ref LL_FLASH_WRP_DISABLE
  *         @arg @ref LL_FLASH_WRP_BLOCK_0
  *         @arg @ref LL_FLASH_WRP_BLOCK_1
  *         @arg @ref LL_FLASH_WRP_BLOCK_2
  *         @arg @ref LL_FLASH_WRP_BLOCK_3
  *         @arg @ref LL_FLASH_WRP_BLOCK_4
  *         @arg @ref LL_FLASH_WRP_BLOCK_5
  *         @arg @ref LL_FLASH_WRP_BLOCK_6
  *         @arg @ref LL_FLASH_WRP_BLOCK_7
  *         @arg @ref LL_FLASH_WRP_Pages0to127
  *         @arg @ref LL_FLASH_WRP_Pages128to255
  *         @arg @ref LL_FLASH_WRP_Pages256to383
  *         @arg @ref LL_FLASH_WRP_Pages384to511
  *         @arg @ref LL_FLASH_WRP_Pages512to639
  *         @arg @ref LL_FLASH_WRP_Pages640to767
  *         @arg @ref LL_FLASH_WRP_Pages768to895
  *         @arg @ref LL_FLASH_WRP_Pages896to1023
  *         @arg @ref LL_FLASH_WRP_AllPages
  */
__STATIC_INLINE uint32_t LL_FLASH_GetWRPRAddress(FLASH_TypeDef *FLASHx)
{
  return (~(READ_BIT(FLASHx->WRPR, FLASH_WRPR_WRP))) & (FLASH_WRPR_WRP);
}

/**
  * @brief  Set PCROP
  * @rmtoll PCROPR0        PCROP0SR             LL_FLASH_SetBank0PCROP
  * @rmtoll PCROPR0        PCROP0ER             LL_FLASH_SetBank0PCROP
  * @param  FLASHx FLASH Instance
  * @param  PCROPStartAddr This parameter can be StartAdress of bank0 pcrop
  * @param  PCROPEndAddr This parameter can be EndAdress of bank0 pcrop
  * @retval None
  */
__STATIC_INLINE uint32_t LL_FLASH_SetBank0PCROP(FLASH_TypeDef *FLASHx, uint32_t PCROPStartAddr,uint32_t PCROPEndAddr)
{
  uint32_t reg_value;
  uint32_t bank0_addr;

  /* Get the information about the bank swapping */
  if (READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_BFB) == 0U)
  {
    bank0_addr = FLASH_BASE;
  }
  else
  {
    bank0_addr = FLASH_BASE + (FLASH_SIZE >> 1);
  }

  /* Configure the Proprietary code readout protection */
  if((PCROPStartAddr >= bank0_addr) && (PCROPEndAddr < (bank0_addr + (FLASH_SIZE >> 1))))
  {
    /* Calculate the location of the PCROPStartAddr in FLASH */
    reg_value = ((PCROPStartAddr - bank0_addr) >> 9);
    MODIFY_REG(FLASH->PCROP0SR, FLASH_PCROP0SR_PCROP0SR, reg_value);

    reg_value = ((PCROPEndAddr - bank0_addr) >> 9);
    MODIFY_REG(FLASH->PCROP0ER, FLASH_PCROP0ER_PCROP0ER, reg_value);
  }
  else
  {
    /* PCROPStartAddr or PCROPEndAddr is Invalid address */
    return ERROR;
  }

  return SUCCESS;
}

/**
  * @brief  Set PCROP
  * @rmtoll PCROPR1        PCROP1SR             LL_FLASH_SetBank1PCROP
  * @rmtoll PCROPR1        PCROP1ER             LL_FLASH_SetBank1PCROP
  * @param  FLASHx FLASH Instance
  * @param  PCROPStartAddr This parameter can be StartAdress of bank1 pcrop
  * @param  PCROPEndAddr This parameter can be EndAdress of bank1 pcrop
  * @retval None
  */
__STATIC_INLINE uint32_t LL_FLASH_SetBank1PCROP(FLASH_TypeDef *FLASHx, uint32_t PCROPStartAddr,uint32_t PCROPEndAddr)
{
  uint32_t reg_value;
  uint32_t bank1_addr;

  /* Get the information about the bank swapping */
  if (READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_BFB) == 0U)
  {
    bank1_addr = FLASH_BASE + (FLASH_SIZE >> 1);
  }
  else
  {
    bank1_addr = FLASH_BASE;
  }

  /* Configure the Proprietary code readout protection */
  if((PCROPStartAddr >= bank1_addr) && (PCROPEndAddr < (bank1_addr + (FLASH_SIZE >> 1))))
  {
    /* Calculate the location of the PCROPStartAddr in FLASH */
    reg_value = ((PCROPStartAddr - bank1_addr) >> 9);
    MODIFY_REG(FLASH->PCROP1SR, FLASH_PCROP1SR_PCROP1SR, reg_value);

    reg_value = ((PCROPEndAddr - bank1_addr) >> 9);
    MODIFY_REG(FLASH->PCROP1ER, FLASH_PCROP1ER_PCROP1ER, reg_value);
  }
  else
  {
    /* PCROPStartAddr or PCROPEndAddr is Invalid address */
    return ERROR;
  }

  return SUCCESS;
}

/**
  * @brief  Get PCROP
  * @rmtoll PCROPR0        PCROP0SR             LL_FLASH_GetBank0PCROP
  * @rmtoll PCROPR0        PCROP0ER             LL_FLASH_GetBank0PCROP
  * @param  FLASHx FLASH Instance
  * @param  PCROPStartAddr This parameter can be StartAdress of bank0 pcrop
  * @param  PCROPEndAddr This parameter can be EndAdress of bank0 pcrop
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_GetBank0PCROP(FLASH_TypeDef *FLASHx, uint32_t *PCROPStartAddr,uint32_t *PCROPEndAddr)
{
  uint32_t reg_value;
  uint32_t bank0_addr;

  /* Get the information about the bank swapping */
  if (READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_BFB) == 0U)
  {
    bank0_addr = FLASH_BASE;
  }
  else
  {
    bank0_addr = FLASH_BASE + (FLASH_SIZE >> 1);
  }

  /* Calculate PCROPStartAddr by FLASH->PCROP0SR */
  reg_value       = ((READ_REG(FLASH->PCROP0SR) & FLASH_PCROP0SR_PCROP0SR) << 9);
  *PCROPStartAddr = (reg_value) + bank0_addr;

  /* Calculate PCROPEndAddr by FLASH->PCROP0ER */
  reg_value     = ((READ_REG(FLASH->PCROP0ER) & FLASH_PCROP0ER_PCROP0ER) << 9);
  *PCROPEndAddr = (reg_value) + bank0_addr;
}

/**
  * @}
  */

/**
  * @brief  Get PCROP
  * @rmtoll PCROPR1        PCROP1SR             LL_FLASH_GetBank1PCROP
  * @rmtoll PCROPR1        PCROP1ER             LL_FLASH_GetBank1PCROP
  * @param  FLASHx FLASH Instance
  * @param  PCROPStartAddr This parameter can be StartAdress of bank1 pcrop
  * @param  PCROPEndAddr This parameter can be EndAdress of bank1 pcrop
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_GetBank1PCROP(FLASH_TypeDef *FLASHx, uint32_t *PCROPStartAddr,uint32_t *PCROPEndAddr)
{
  uint32_t reg_value;
  uint32_t bank1_addr;

  /* Get the information about the bank swapping */
  if (READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_BFB) == 0U)
  {
    bank1_addr = FLASH_BASE + (FLASH_SIZE >> 1);
  }
  else
  {
    bank1_addr = FLASH_BASE;
  }

  /* Calculate PCROPStartAddr by FLASH->PCROP1SR */
  reg_value       = ((READ_REG(FLASH->PCROP1SR) & FLASH_PCROP1SR_PCROP1SR) << 9);
  *PCROPStartAddr = (reg_value) + bank1_addr;

  /* Calculate PCROPEndAddr by FLASH->PCROP1ER */
  reg_value     = ((READ_REG(FLASH->PCROP1ER) & FLASH_PCROP1ER_PCROP1ER) << 9);
  *PCROPEndAddr = (reg_value) + bank1_addr;
}

/**
  * @}
  */

/**
  * @brief  Set Optr
  * @rmtoll OPTR1           RDP                 LL_FLASH_SetOPTR1
  * @rmtoll OPTR1           IWDG_STOP           LL_FLASH_SetOPTR1
  * @rmtoll OPTR1           IWDG_STDBY          LL_FLASH_SetOPTR1
  * @rmtoll OPTR1           BFB                 LL_FLASH_SetOPTR1
  * @rmtoll OPTR1           IWDG_SW             LL_FLASH_SetOPTR1
  * @rmtoll OPTR1           NRST_STOP           LL_FLASH_SetOPTR1
  * @rmtoll OPTR1           NRST_STDBY          LL_FLASH_SetOPTR1
  * @rmtoll OPTR1           WWDG_SW             LL_FLASH_SetOPTR1
  * @param  FLASHx FLASH Instance
  * @param  USERType This parameter can be a combination of following values:
  *         @arg @ref LL_FLASH_OPTR_RDP
  *         @arg @ref LL_FLASH_OPTR_IWDG_STOP
  *         @arg @ref LL_FLASH_OPTR_IWDG_STDBY
  *         @arg @ref LL_FLASH_OPTR_BFB
  *         @arg @ref LL_FLASH_OPTR_IWDG_SW
  *         @arg @ref LL_FLASH_OPTR_NRST_STOP
  *         @arg @ref LL_FLASH_OPTR_NRST_STDBY
  *         @arg @ref LL_FLASH_OPTR_WWDG_SW
  * @param  USERConfig Optr value need to be config by USERType
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetOPTR1(FLASH_TypeDef *FLASHx,uint32_t USERType,uint32_t USERConfig)
{
  MODIFY_REG(FLASHx->OPTR1, USERType, (USERConfig & 0xFFFFU));
}

/**
  * @brief  Set Optr
  * @rmtoll OPTR2           NBOOT1              LL_FLASH_SetOPTR2
  * @rmtoll OPTR2           NRST_MODE           LL_FLASH_SetOPTR2
  * @rmtoll OPTR2           SRAM_PE             LL_FLASH_SetOPTR2
  * @rmtoll OPTR2           CCMSRAM_RST         LL_FLASH_SetOPTR2
  * @rmtoll OPTR2           NSWBOOT0            LL_FLASH_SetOPTR2
  * @rmtoll OPTR2           NBOOT0              LL_FLASH_SetOPTR2
  * @rmtoll OPTR2           BOOT_LOCK           LL_FLASH_SetOPTR2
  * @param  FLASHx FLASH Instance
  * @param  USERType This parameter can be a combination of following values:
  *         @arg @ref LL_FLASH_OPTR_NBOOT1 
  *         @arg @ref LL_FLASH_OPTR_NRST_MODE
  *         @arg @ref LL_FLASH_OPTR_NRST_MODE0
  *         @arg @ref LL_FLASH_OPTR_NRST_MODE1
  *         @arg @ref LL_FLASH_OPTR_SRAM_PE
  *         @arg @ref LL_FLASH_OPTR_CCMSRAM_RST 
  *         @arg @ref LL_FLASH_OPTR_NSWBOOT0
  *         @arg @ref LL_FLASH_OPTR_NBOOT0
  *         @arg @ref LL_FLASH_OPTR_BOOT_LOCK
  * @param  USERConfig Optr value need to be config by USERType
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetOPTR2(FLASH_TypeDef *FLASHx,uint32_t USERType,uint32_t USERConfig)
{
  MODIFY_REG(FLASHx->OPTR2, USERType, (USERConfig & 0xFFFFU));
}

/**
  * @brief Get BOOT Lock
  * @rmtoll OPTR1        BOOT_LOCK          LL_FLASH_GetBOOTLock
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_BOOT_FROM_OB
  *         @arg @ref LL_FLASH_BOOT_FROM_MAINFLASH
  */
__STATIC_INLINE uint32_t LL_FLASH_GetBOOTLock(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR2, FLASH_OPTR2_BOOT_LOCK);
}

/**
  * @brief Get BFB Mode
  * @rmtoll OPTR1        BFB          LL_FLASH_GetBFBMode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_BFB_START_BANK0
  *         @arg @ref LL_FLASH_BFB_START_BANK1
  */
__STATIC_INLINE uint32_t LL_FLASH_GetBFBMode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_BFB);
}

/**
  * @brief Get NBoot1 Mode
  * @rmtoll OPTR2        NBOOT1          LL_FLASH_GetnBOOT1Mode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_NBOOT1_SRAM
  *         @arg @ref LL_FLASH_NBOOT1_SYSTEM
  */
__STATIC_INLINE uint32_t LL_FLASH_GetnBOOT1Mode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR2, FLASH_OPTR2_NBOOT1);
}

/**
  * @brief Get NRST Mode
  * @rmtoll OPTR2        NRST_MODE          LL_FLASH_GetNrstMode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_NRST_MODE_RESET_INPUT_ONLY
  *         @arg @ref LL_FLASH_NRST_MODE_GPIO
  *         @arg @ref LL_FLASH_NRST_MODE_RESET_INPUT_OUTPUT
  */
__STATIC_INLINE uint32_t LL_FLASH_GetNrstMode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR2, FLASH_OPTR2_NRST_MODE);
}

/**
  * @brief Get SRAM_PE Mode
  * @rmtoll OPTR2        SRAM_PE          LL_FLASH_GetSRAMPE
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_SRAM_PARITY_DISABLE
  *         @arg @ref LL_FLASH_SRAM_PARITY_ENABLE
  */
 __STATIC_INLINE uint32_t LL_FLASH_GetSRAMPE(FLASH_TypeDef *FLASHx)
 {
   return READ_BIT(FLASHx->OPTR2, FLASH_OPTR2_SRAM_PE);
 }
 
/**
  * @brief Get WWDG Mode
  * @rmtoll OPTR1        WWDG_SW          LL_FLASH_GetWWDGMode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_WWDG_MODE_HW
  *         @arg @ref LL_FLASH_WWDG_MODE_SW
  */
__STATIC_INLINE uint32_t LL_FLASH_GetWWDGMode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_WWDG_SW);
}

/**
  * @brief Get IWDG Mode
  * @rmtoll OPTR1        IWDG_SW          LL_FLASH_GetIWDGMode
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_IWDG_MODE_HW
  *         @arg @ref LL_FLASH_IWDG_MODE_SW
  */
__STATIC_INLINE uint32_t LL_FLASH_GetIWDGMode(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_IWDG_SW);
}

/**
  * @brief Get IWDG In Stop
  * @rmtoll OPTR1        IWDG_STOP          LL_FLASH_GetIWDGInStop
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_IWDG_INSTOP_FREEZE
  *         @arg @ref LL_FLASH_IWDG_INSTOP_ACTIVE
  */
__STATIC_INLINE uint32_t LL_FLASH_GetIWDGInStop(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_IWDG_STOP);
}

/**
  * @brief Get IWDG In Standby
  * @rmtoll OPTR1        IWDG_STDBY          LL_FLASH_GetIWDGInStandby
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_IWDG_INSTANDBY_FREEZE
  *         @arg @ref LL_FLASH_IWDG_INSTANDBY_ACTIVE
  */
__STATIC_INLINE uint32_t LL_FLASH_GetIWDGInStandby(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_IWDG_STDBY);
}

/**
  * @brief Get NRST STOP Mode
  * @rmtoll OPTR1        NRST_STOP          LL_FLASH_GetStopReset
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_STOP_RST
  *         @arg @ref LL_FLASH_STOP_NORST
  */
__STATIC_INLINE uint32_t LL_FLASH_GetSTOPReset(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_NRST_STOP);
}

/**
  * @brief Get NRST STDBY Mode
  * @rmtoll OPTR1        NRST_STDBY          LL_FLASH_GetStandbyReset
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_STANDBY_RST
  *         @arg @ref LL_FLASH_STANDBY_NORST
  */
__STATIC_INLINE uint32_t LL_FLASH_GetSTANDBYReset(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_NRST_STDBY);
}

/**
  * @brief Get RDP Level
  * @rmtoll OPTR1        RDP          LL_FLASH_GetRDP
  * @param  FLASHx FLASH Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_RDP_LEVEL_0
  *         @arg @ref LL_FLASH_RDP_LEVEL_1
  */
__STATIC_INLINE uint32_t LL_FLASH_GetRDP(FLASH_TypeDef *FLASHx)
{
  return READ_BIT(FLASHx->OPTR1, FLASH_OPTR1_RDP);
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
#endif /* defined (FLASH) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PY32E407_LL_FLASH_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
