/**
  ******************************************************************************
  * @file    py32e4xx.h
  * @brief   CMSIS PY32E4xx Device Peripheral Access Layer Header File.
  * @version v1.0.0
  *
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

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup py32e4xx
  * @{
  */

#ifndef __PY32E4xx_H
#define __PY32E4xx_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * @brief PY32 Family
  */
#if !defined  (PY32E4)
#define PY32E4
#endif /* PY32E4 */

#if (defined(PY32E407x4) || defined(PY32E407x6) || defined(PY32E407x8) || defined(PY32E407xB) || defined(PY32E407xC) || defined(PY32E407xD) || defined(PY32E407xE))
#define PY32E407PRE
#endif

/* Uncomment the line below according to the target PY32 device used in your
   application
  */

#if !defined (PY32E407x4) && !defined (PY32E407x6) && !defined (PY32E407x8) && !defined (PY32E407xB) && !defined (PY32E407xC) && !defined (PY32E407xD) && !defined (PY32E407xE)
/* #define PY32E407x4  */  /*!< PY32E407x4  Devices (PY32E407xx  microcontrollers where the Flash memory is 16  Kbytes)              */
/* #define PY32E407x6  */  /*!< PY32E407x6  Devices (PY32E407xx  microcontrollers where the Flash memory is 32  Kbytes)              */
/* #define PY32E407x8  */  /*!< PY32E407x8  Devices (PY32E407xx  microcontrollers where the Flash memory is 64  Kbytes)              */
/* #define PY32E407xB  */  /*!< PY32E407xB  Devices (PY32E407xx  microcontrollers where the Flash memory is 128 Kbytes)              */
/* #define PY32E407xC  */  /*!< PY32E407xC  Devices (PY32E407xx  microcontrollers where the Flash memory is 256 Kbytes)              */
/* #define PY32E407xD  */  /*!< PY32E407xD  Devices (PY32E407xx  microcontrollers where the Flash memory is 384 Kbytes)              */
/* #define PY32E407xE  */  /*!< PY32E407xE  Devices (PY32E407xx  microcontrollers where the Flash memory is 512 Kbytes)              */
#endif

/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */
#if !defined  (USE_HAL_DRIVER)
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will
   be based on direct access to peripherals registers
   */
/*#define USE_HAL_DRIVER */
#endif /* USE_HAL_DRIVER */

/**
  * @brief CMSIS Device version number V1.0.0
  */
#define __PY32E4_DEVICE_VERSION_MAIN   (0x01) /*!< [31:24] main version */
#define __PY32E4_DEVICE_VERSION_SUB1   (0x00) /*!< [23:16] sub1 version */
#define __PY32E4_DEVICE_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version */
#define __PY32E4_DEVICE_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define __PY32E4_DEVICE_VERSION         ((__PY32E4_DEVICE_VERSION_MAIN << 24)\
                                        |(__PY32E4_DEVICE_VERSION_SUB1 << 16)\
                                        |(__PY32E4_DEVICE_VERSION_SUB2 << 8 )\
                                        |(__PY32E4_DEVICE_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Device_Included
  * @{
  */

#if defined(PY32E407x4)
#include "py32e407x4.h"
#elif defined(PY32E407x6)
#include "py32e407x6.h"
#elif defined(PY32E407x8)
#include "py32e407x8.h"
#elif defined(PY32E407xB)
#include "py32e407xB.h"
#elif defined(PY32E407xC)
#include "py32e407xC.h"
#elif defined(PY32E407xD)
#include "py32e407xD.h"
#elif defined(PY32E407xE)
#include "py32e407xE.h"
#else
#error "Please select first the target PY32E4xx device used in your application (in py32e4xx.h file)"
#endif

/**
  * @}
  */

/** @addtogroup Exported_types
  * @{
  */
typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum 
{
  SUCCESS = 0U,
  ERROR = !SUCCESS
} ErrorStatus;

/**
  * @}
  */


/** @addtogroup Exported_macros
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))

/* Use of interrupt control for register exclusive access */
/* Atomic 32-bit register access macro to set one or several bits */
#define ATOMIC_SET_BIT(REG, BIT)                             \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    SET_BIT((REG), (BIT));                                   \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 32-bit register access macro to clear one or several bits */
#define ATOMIC_CLEAR_BIT(REG, BIT)                           \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    CLEAR_BIT((REG), (BIT));                                 \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 32-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFY_REG(REG, CLEARMSK, SETMASK)            \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    MODIFY_REG((REG), (CLEARMSK), (SETMASK));                \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 16-bit register access macro to set one or several bits */
#define ATOMIC_SETH_BIT(REG, BIT) ATOMIC_SET_BIT(REG, BIT)                                   \

/* Atomic 16-bit register access macro to clear one or several bits */
#define ATOMIC_CLEARH_BIT(REG, BIT) ATOMIC_CLEAR_BIT(REG, BIT)                               \

/* Atomic 16-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFYH_REG(REG, CLEARMSK, SETMASK) ATOMIC_MODIFY_REG(REG, CLEARMSK, SETMASK) \

#define HW32_REG(ADDRESS)     ( * ((volatile unsigned           int * )(ADDRESS)))

#define HW16_REG(ADDRESS)     ( * ((volatile unsigned short     int * )(ADDRESS)))

#define HW8_REG(ADDRESS)      ( * ((volatile unsigned          char * )(ADDRESS)))

#define M32(ADDRESS)          HW32_REG(ADDRESS)

#define M16(ADDRESS)          HW16_REG(ADDRESS)

#define M8(ADDRESS)           HW8_REG(ADDRESS)

/**
  * @}
  */

#if defined (USE_HAL_DRIVER)
 #include "py32e4xx_hal.h"
#endif /* USE_HAL_DRIVER */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PY32E4xx_H */
/**
  * @}
  */

/**
  * @}
  */


/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

