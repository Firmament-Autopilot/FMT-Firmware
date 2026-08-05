/*********************************************************************
*                   (c) SEGGER Microcontroller GmbH                  *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*       (c) 2003 - 2025     SEGGER Microcontroller GmbH              *
*                                                                    *
*       www.segger.com     Support: www.segger.com/ticket            *
*                                                                    *
**********************************************************************
*                                                                    *
*       emUSB-Device * USB Device stack for embedded applications    *
*                                                                    *
*       Please note: Knowledge of this file may under no             *
*       circumstances be used to write a similar product.            *
*       Thank you for your fairness !                                *
*                                                                    *
**********************************************************************
*                                                                    *
*       emUSB-Device version: V3.66.5                                *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
All Intellectual Property rights in the software belongs to SEGGER.
emUSB Device is protected by international copyright laws. This file
may only be used in accordance with the following terms:

The source code of the emUSB Device software has been licensed to Cypress
Semiconductor Corporation, whose registered office is 198 Champion
Court, San Jose, CA 95134, USA including the 
right to create and distribute the object code version of 
the emUSB Device software for its Cortex M0, M0+, M4, M33 and M55 based devices.
The object code version can be used by Cypress customers under the 
terms and conditions of the associated End User License Agreement.
Support for the object code version is provided by Cypress, 
full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information
Licensor:                 SEGGER Microcontroller Systems LLC
Licensed to:              Cypress Semiconductor Corp, 198 Champion Ct., San Jose, CA 95134, USA
Licensed SEGGER software: emUSB-Device
License number:           USBD-00500
License model:            Cypress Services and License Agreement, signed November 17th/18th, 2010
                          and Amendment Number One, signed December 28th, 2020 and February 10th, 2021
                          and Amendment Number Three, signed May 2nd, 2022 and May 5th, 2022 and Amendment Number Four, signed August 28th, 2023
Licensed platform:        Cypress devices containing ARM Cortex M cores: M0, M0+, M4, M33 and M55
----------------------------------------------------------------------
Support and Update Agreement (SUA)
SUA period:               2022-05-12 - 2026-05-19
Contact to extend SUA:    sales@segger.com
----------------------------------------------------------------------
Purpose : This file contains the default values for emUSB-Device
          configuration parameters. To allow easy updates please
          do not change the parameters here, but add them in the
          USB_Conf.h file, the defines there will replace the default
          values.
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef   USB_CONFDEFAULTS_H
#define   USB_CONFDEFAULTS_H

#include "USB_Conf.h"

//
// Set default debug level.
//
#ifndef  USB_DEBUG_LEVEL
  #if defined(DEBUG) && DEBUG > 0
    #define USB_DEBUG_LEVEL     2
  #endif
#endif

/*********************************************************************
*
*       USB_DEBUG_LEVEL
*
*  Description
*    emUSB-Device can be configured to display debug messages and warnings
*    to locate an error or potential problems. This can be useful for debugging.
*    In a release (production) build of a target system, they are typically not required
*    and should be switches off.
*
*    To output the messages, emUSB-Host uses the logging routines contained
*    in \file{USB_ConfigIO.c} which can be customized.
*
*    USB_DEBUG_LEVEL can be set to the following values:
*    * 0 - Used for release builds. Includes no debug options.
*    * 1 - Used in debug builds to include support for "panic" checks.
*    * 2 - Used in debug builds to include warning, log messages and "panic" checks.
*          This significantly increases the code size.
*/
#ifndef     USB_DEBUG_LEVEL
  #define   USB_DEBUG_LEVEL    0
#endif

/*********************************************************************
*
*       USB_SUPPORT_LOG
*
*  Description
*    Should log messages be supported?
*/
#ifndef     USB_SUPPORT_LOG
  #if       USB_DEBUG_LEVEL > 1
    #define USB_SUPPORT_LOG   1
  #else
    #define USB_SUPPORT_LOG   0
  #endif
#endif

/*********************************************************************
*
*       USB_SUPPORT_WARN
*
*  Description
*    Should warning messages be supported?
*/
#ifndef     USB_SUPPORT_WARN
  #if       USB_DEBUG_LEVEL > 1
    #define USB_SUPPORT_WARN  1
  #else
    #define USB_SUPPORT_WARN  0
  #endif
#endif


/*********************************************************************
*
*       USB_LOG_BUFFER_SIZE
*
*  Description
*    Maximum size of a debug / warning message (in characters) that can be output.
*    A buffer of this size is created on the stack when a message is output.
*/
#ifndef USB_LOG_BUFFER_SIZE
  #define USB_LOG_BUFFER_SIZE  100
#endif

/*********************************************************************
*
*       USB_SUPPORT_TRANSFER_ISO
*
*  Description
*    Must be set to 1 if the USB stack shall support isochronous transfers
*    (e.g. for audio and video applications).
*    If set to 0, all code that handles isochronous transfers is disabled,
*    which may significantly reduce the code size of the USB stack.
*/
#ifndef   USB_SUPPORT_TRANSFER_ISO
  #define USB_SUPPORT_TRANSFER_ISO 0
#endif


/*********************************************************************
*
*       USB_MAX_POWER
*
*  Description
*    The maximum current consumption of the device in x*2 mA (e.g. 50 means 100 mA).
*    Default value, can be overwritten in software using USBD_SetMaxPower().
*/
#ifndef   USB_MAX_POWER
  #define USB_MAX_POWER  50u
#endif

/*********************************************************************
*
*       USB_SUPPORT_TEST_MODE
*
*  Description
*    USB test mode enable. This can be set to 1 to enable support for USB
*    high-speed test mode. It is disabled by default to reduce memory footprint
*    of the USB stack.
*/
#ifndef   USB_SUPPORT_TEST_MODE
  #define USB_SUPPORT_TEST_MODE        0
#endif

/*********************************************************************
*
*       USBD_SUPPORT_PROFILE
*
*  Description
*    Enables USB API instrumentation for SystemView.
*/
#ifndef   USBD_SUPPORT_PROFILE
  #define USBD_SUPPORT_PROFILE  0
#endif

/*********************************************************************
*
*       USBD_OS_USE_USBD_X_INTERRUPT
*
*  Description
*    If set emUSB-Device will use the functions USBD_X_EnableInterrupt() and USBD_X_DisableInterrupt()
*    instead of disabling/enabling the interrupts globally. Those functions only disable/enable the USB interrupt.
*    The functions are MCU specific and must be defined in the corresponding USB_Config_*.c file.
*/
#ifndef USBD_OS_USE_USBD_X_INTERRUPT
  #define USBD_OS_USE_USBD_X_INTERRUPT  0
#endif

/*********************************************************************
*
*       USBD_OS_USE_ISR_FLAG
*
*  Description
*    Enable flag to indicate execution of USB interrupt.
*    May be needed by some RTOS layer in combination with USBD_OS_USE_USBD_X_INTERRUPT=1 (experimental).
*/
#ifndef USBD_OS_USE_ISR_FLAG
  #define USBD_OS_USE_ISR_FLAG          0
#endif

/*********************************************************************
*
*       USB_NUM_EPS
*
*  Description
*    Maximum number of endpoints that can be used in the main stack.
*    A table is stored in static memory with USB_NUM_EPS entries, each
*    allocates 56 bytes.
*/
#ifndef   USB_NUM_EPS
  #define USB_NUM_EPS 8u
#endif

/*********************************************************************
*
*       USB_MAX_NUM_IF
*
*  Description
*    Maximum number of USB interfaces the device can support. Each USB class
*    has one or more interfaces. For a USB composite device USB_MAX_NUM_IF
*    must be >= the sum of the number of interfaces for all classes configured.
*    Information about all interfaces are stored into a table, which
*    allocates about USB_MAX_NUM_IF * 9 words in static memory (word = sizeof(void *)).
*/
#ifndef   USB_MAX_NUM_IF
  #define USB_MAX_NUM_IF 4u
#endif

/*********************************************************************
*
*       USB_MAX_NUM_ALT_IF
*
*  Description
*    Maximum number of USB alternate settings the device can support. Some USB interfaces
*    may have alternate settings to select different operating modes / configurations.
*    USB_MAX_NUM_ALT_IF must be >= the sum of the number of all alternate settings of all interfaces
*    of all classes configured.
*    Information about all alternates settings are stored into a table, which
*    allocates about USB_MAX_NUM_ALT_IF * 10 words in static memory (word = sizeof(void *)).
*/
#ifndef   USB_MAX_NUM_ALT_IF
  #define USB_MAX_NUM_ALT_IF 2u
#endif

/*********************************************************************
*
*       USB_DESC_BUFFER_SIZE
*
*  Description
*    Maximum size of a USB configuration descriptor. The configuration descriptor
*    consists of a header and the concatenation of configurations for all configured
*    USB classes. The configuration descriptors are small for most classes, but for the audio
*    or video class it may get large and require to increase the size of this buffer.
*/
#ifndef   USB_DESC_BUFFER_SIZE
  #define USB_DESC_BUFFER_SIZE  256
#endif

/*********************************************************************
*
*       USB_MAX_NUM_IAD
*
*  Description
*    Maximum number of interface association descriptors.
*/
#ifndef   USB_MAX_NUM_IAD
  #define USB_MAX_NUM_IAD 3u
#endif

//
// Maximum number of Microsoft OS descriptors.
//
#ifndef   USB_MAX_NUM_MS_DESC
  #define USB_MAX_NUM_MS_DESC   USB_MAX_NUM_IF
#endif

//
// Maximum number of callbacks which can be registered for EP0 via USBD_SetOnRxEP0().
// Normally one class component registers one EP0 receive callback.
//
#ifndef   USB_MAX_NUM_COMPONENTS
  #define USB_MAX_NUM_COMPONENTS  USB_MAX_NUM_IF
#endif

//
// Specifies the number of additional event objects.
// The stack allocates as many events as there are configured endpoints (USB_NUM_EPS),
// the additional events are for the use by class modules through USB__AllocEvent().
//
#ifndef   USB_EXTRA_EVENTS
  #define USB_EXTRA_EVENTS 0u
#endif

//
// Specifies the number of RTOS mutexes that can be allocated.
// Currently only used by the MTP class.
//
#ifndef   USB_NUM_MUTEXES
  #define USB_NUM_MUTEXES   1
#endif

//
// Maximum number of string descriptors.
//
#ifndef USB_MAX_STRING_DESC
  #define USB_MAX_STRING_DESC   (USB_MAX_NUM_IF + USB_MAX_NUM_ALT_IF)
#endif

//
// For full-speed only devices, this can be set to 0 to save a few bytes of code.
//
#ifndef   USB_SUPPORT_HIGH_SPEED
  #define USB_SUPPORT_HIGH_SPEED 1
#endif

//
// Support other speed descriptor?
// Only necessary if the target supports high-speed.
//
#ifndef   USB_OTHER_SPEED_DESC
  #define USB_OTHER_SPEED_DESC         USB_SUPPORT_HIGH_SPEED
#endif

//
// Compatibility define for migration from emUSB-Device V2 DevInfo to V3 DevInfo
//
#ifndef USB_V2_V3_MIGRATION_DEVINFO
  #define USB_V2_V3_MIGRATION_DEVINFO   0
#endif
#ifndef USB_V2_V3_MIGRATION_API
  #define USB_V2_V3_MIGRATION_API       USB_V2_V3_MIGRATION_DEVINFO
#endif

//
// Compatibility define for migration from emUSB-Device V2 config method to V3 config method.
//
#ifndef USB_V2_V3_MIGRATION_CONFIG
  #define USB_V2_V3_MIGRATION_CONFIG    0
#endif

//
// Do not change. USBD_OS_LAYER_EX != 1 is no longer supported.
//
#ifndef USBD_OS_LAYER_EX
  #define USBD_OS_LAYER_EX       1
#endif

//
// Should class requests be supported?
// Note: setting this to 0 is not recommended and is only intended for absolutely minimal configurations.
//
#ifndef   USB_SUPPORT_CLASS_REQUESTS
  #define USB_SUPPORT_CLASS_REQUESTS 1
#endif

//
// Should vendor requests be supported?
// Note: setting this to 0 is not recommended and is only intended for absolutely minimal configurations.
//
#ifndef   USB_SUPPORT_VENDOR_REQUESTS
  #define USB_SUPPORT_VENDOR_REQUESTS 1
#endif

//
// Should status requests be supported?
// Note: setting this to 0 is not recommended and is only intended for absolutely minimal configurations.
//
#ifndef USB_SUPPORT_STATUS
  #define USB_SUPPORT_STATUS 1
#endif

//
// Support a callback functions on 'Get Interface' control requests.
//
#ifndef   USB_SUPPORT_GET_INTERFACE_CB
  #define USB_SUPPORT_GET_INTERFACE_CB 0
#endif

//
// If a read transfers is canceled (e.g. by a timeout event) when part of the data was already transfered,
// then some USB controllers are not able to report the read data to the user application and
// then this data is lost.
// Setting the following option to 1 implements a workaround: In case of a aborted transfer
// always the exact size of data already read is reported to the application.
//
#ifndef USB_EXACT_DATASIZE_ON_CANCEL
  #define USB_EXACT_DATASIZE_ON_CANCEL 1
#endif


//
// Macro overwrite for memcpy.
//
#ifndef   USB_MEMCPY
  #include <string.h>
  #define USB_MEMCPY  memcpy                          /*lint -e{9087,9005} D:105[b] */
#endif

//
// Macro overwrite for memset.
//
#ifndef   USB_MEMSET
  #include <string.h>
  #define USB_MEMSET  memset                          /*lint -e{9087,9005} D:105[b] */
#endif

//
// Macro overwrite for memcmp.
//
#ifndef   USB_MEMCMP
  #include <string.h>
  #define USB_MEMCMP  memcmp                          /*lint -e{9087,9005} D:105[b] */
  //lint -sem(memcmp, pure)          N:100
#endif

//
// Macro overwrite for memmove
//
#ifndef   USB_MEMMOVE
  #include <string.h>
  #define USB_MEMMOVE  memmove                         /*lint -e{9087,9005} D:105[b] */
#endif

//
// Macro overwrite for strlen
//
#ifndef   USB_STRLEN
  #include <string.h>
  #define USB_STRLEN   strlen
#endif

//
// Macro overwrite for strcat
//
#ifndef   USB_STRCAT
  #include <string.h>
  #define USB_STRCAT   strcat
#endif

//
// Macro overwrite for strrchr
//
#ifndef   USB_STRRCHR
  #include <string.h>
  #define USB_STRRCHR  strrchr
#endif

//
// Macro overwrite for strncpy
//
#ifndef   USB_STRNCPY
  #include <string.h>
  #define USB_STRNCPY  strncpy
#endif

//
// Macro overwrite for strcmp
//
#ifndef   USB_STRCMP
  #include <string.h>
  #define USB_STRCMP   strcmp
#endif

//
// Macro used in order to avoid warnings for undefined parameters
//
#ifndef USB_USE_PARA
  #define USB_USE_PARA(para) (void)(para)
#endif

#endif

/*************************** End of file ****************************/
