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
-------------------------- END-OF-HEADER -----------------------------

File    : SEGGER.h
Purpose : Global types etc & general purpose utility functions.
Revision: $Rev: 31583 $
*/

#ifndef SEGGER_H            // Guard against multiple inclusion
#define SEGGER_H

#include <stdarg.h>         // For va_list.
#include "Global.h"         // Type definitions: U8, U16, U32, I8, I16, I32

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Keywords/specifiers
*
**********************************************************************
*/

#ifndef INLINE
  #if (defined(__ICCARM__) || defined(__RX) || defined(__ICCRX__) || defined(__ICC430__))
    //
    // Various known compilers.
    //
    #define INLINE  inline
  #else
    #if   defined(_MSC_VER)
      #if (_MSC_VER >= 1200)
        //
        // Microsoft VC6 and newer.
        // Force inlining without cost checking.
        //
        #define INLINE  __forceinline
      #endif
    #elif defined(__GNUC__) || defined(__clang__) || defined(__SEGGER_CC__)
      //
      // Force inlining with GCC & clang.
      //
      #define INLINE inline __attribute__((always_inline))
    #elif defined(__CC_ARM)
      //
      // Force inlining with ARMCC (Keil).
      //
      #define INLINE  __inline
    #endif
  #endif
#endif
#ifndef INLINE
  //
  // Unknown compiler.
  //
  #define INLINE
#endif

/*********************************************************************
*
*       Function-like macros
*
**********************************************************************
*/

#define SEGGER_COUNTOF(a)          (sizeof((a))/sizeof((a)[0]))
#define SEGGER_MIN(a,b)            (((a) < (b)) ? (a) : (b))
#define SEGGER_MAX(a,b)            (((a) > (b)) ? (a) : (b))

#ifndef   SEGGER_USE_PARA                   // Some compiler complain about unused parameters.
  #define SEGGER_USE_PARA(Para) (void)Para  // This works for most compilers.
#endif

#define SEGGER_ADDR2PTR(Type, Addr)  (/*lint -e(923) -e(9078)*/((Type*)((PTR_ADDR)(Addr))))                    // Allow cast from address to pointer.
#define SEGGER_PTR2ADDR(p)           (/*lint -e(923) -e(9078)*/((PTR_ADDR)(p)))                                // Allow cast from pointer to address.
#define SEGGER_PTR2PTR(Type, p)      (/*lint -e(740) -e(826) -e(9079) -e(9087)*/((Type*)((void*)(p))))         // Allow cast from one pointer type to another (ignore different size).
                                                                                                               // Cast into void* first as some architectures/compilers might output
                                                                                                               // a warning when casting from potentially unaligned types like U8 to
                                                                                                               // higher aligned types (e.g. CC-RL compiler).
#define SEGGER_CONSTPTR2PTR(Type, p)  (/*lint -e(740) -e(826) -e(9079) -e(9087)*/((Type*)((void const*)(p))))  // Allow cast from one pointer type to another (ignore different size).
                                                                                                               // Same as SEGGER_PTR2PTR() but for const source pointers so the const
                                                                                                               // modifier is not removed during the cast and causes a warning.
#define SEGGER_PTR_DISTANCE(p0, p1)  (SEGGER_PTR2ADDR(p0) - SEGGER_PTR2ADDR(p1))

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

#define SEGGER_PRINTF_FLAG_ADJLEFT    (1 << 0)
#define SEGGER_PRINTF_FLAG_SIGNFORCE  (1 << 1)
#define SEGGER_PRINTF_FLAG_SIGNSPACE  (1 << 2)
#define SEGGER_PRINTF_FLAG_PRECEED    (1 << 3)
#define SEGGER_PRINTF_FLAG_ZEROPAD    (1 << 4)
#define SEGGER_PRINTF_FLAG_NEGATIVE   (1 << 5)

#ifndef SEGGER_IS_CORTEX_M
  //
  // According to ARM IHI 0053D section 'Architectural profile'
  // __ARM_ARCH_PROFILE is set to 'M' / 77 / 0x4d on Cortex-M targets
  //
  #if (defined(__ARM_ARCH_PROFILE) && (__ARM_ARCH_PROFILE == 'M'))
    #define SEGGER_IS_CORTEX_M 1
  #else
    #define SEGGER_IS_CORTEX_M 0
  #endif
#endif

/*********************************************************************
*
*       Types
*
**********************************************************************
*/

typedef struct {
  char* pBuffer;
  int   BufferSize;
  int   Cnt;
} SEGGER_BUFFER_DESC;

typedef struct {
  unsigned int CacheLineSize;                             // 0: No Cache. Most Systems such as ARM9 use a 32 bytes cache line size.
  void (*pfDMB)       (void);                             // Optional DMB function for Data Memory Barrier to make sure all memory operations are completed.
  void (*pfClean)     (void *p, unsigned long NumBytes);  // Optional clean function for cached memory.
  void (*pfInvalidate)(void *p, unsigned long NumBytes);  // Optional invalidate function for cached memory.
} SEGGER_CACHE_CONFIG;

typedef struct SEGGER_SNPRINTF_CONTEXT_struct SEGGER_SNPRINTF_CONTEXT;

struct SEGGER_SNPRINTF_CONTEXT_struct {
  void*               pContext;                       // Application specific context.
  SEGGER_BUFFER_DESC* pBufferDesc;                    // Buffer descriptor to use for output.
  void (*pfFlush)(SEGGER_SNPRINTF_CONTEXT* pContext); // Callback executed once the buffer is full. Callback decides if the buffer gets cleared to store more or not.
};

typedef struct {
  void (*pfStoreChar)       (SEGGER_BUFFER_DESC* pBufferDesc, SEGGER_SNPRINTF_CONTEXT* pContext, char c);
  int  (*pfPrintUnsigned)   (SEGGER_BUFFER_DESC* pBufferDesc, SEGGER_SNPRINTF_CONTEXT* pContext, U32 v, unsigned Base, char Flags, int Width, int Precision);
  int  (*pfPrintInt)        (SEGGER_BUFFER_DESC* pBufferDesc, SEGGER_SNPRINTF_CONTEXT* pContext, I32 v, unsigned Base, char Flags, int Width, int Precision);
} SEGGER_PRINTF_API;

typedef void (*SEGGER_pFormatter)(SEGGER_BUFFER_DESC* pBufferDesc, SEGGER_SNPRINTF_CONTEXT* pContext, const SEGGER_PRINTF_API* pApi, va_list* pParamList, char Lead, int Width, int Precision);

typedef struct SEGGER_PRINTF_FORMATTER {
  struct SEGGER_PRINTF_FORMATTER* pNext;              // Pointer to next formatter.
  SEGGER_pFormatter               pfFormatter;        // Formatter function.
  char                            Specifier;          // Format specifier.
} SEGGER_PRINTF_FORMATTER;

typedef struct {
  U32 (*pfGetHPTimestamp)(void);          // Mandatory, pfGetHPTimestamp
  int (*pfGetUID)        (U8 abUID[16]);  // Optional,  pfGetUID
} SEGGER_BSP_API;

typedef enum {
  SEGGER_PARSE_IP_STATUS_OK = 0,              // O.K., address successfully parsed.
  SEGGER_PARSE_IP_STATUS_ERROR,               // Other error (parameter error; not an IPv4/6 address but a domain ?).
  SEGGER_PARSE_IP_STATUS_INVALID_CHAR,        // Error, invalid character found (valid characters are upper/lower '0'-'f' and ':' for IPv6).
  SEGGER_PARSE_IP_STATUS_NUM_CHARS_IN_BLOCK,  // Error, too many characters in address block.
  SEGGER_PARSE_IP_STATUS_INVALID_COMP,        // Error, illegal number of colons in a row (":::") in IPv6 address.
  SEGGER_PARSE_IP_STATUS_START_SINGLE_COLON,  // Error, address starts with a single colon.
  SEGGER_PARSE_IP_STATUS_END_SINGLE_COLON,    // Error, address ends with a single colon.
  SEGGER_PARSE_IP_STATUS_MULTIPLE_COMP,       // Error, zero compression used more than once.
  SEGGER_PARSE_IP_STATUS_TOO_LONG,            // Error, too many characters in address.
  SEGGER_PARSE_IP_STATUS_TOO_SHORT,           // Error, not enough characters in address.
  SEGGER_PARSE_IP_STATUS_SEPARATOR_ERROR      // Too many or not enough '.' or ':' found in address or in an unexpected position.
} SEGGER_PARSE_IP_STATUS;

typedef enum {
  SEGGER_PARSE_IP_TYPE_OTHER = 0,  // IP address not parsed, host name ?
  SEGGER_PARSE_IP_TYPE_IPV4,       // Parsed address is an IPv4 address.
  SEGGER_PARSE_IP_TYPE_IPV6        // Parsed address is an IPv6 address.
} SEGGER_PARSE_IP_TYPE;

/*********************************************************************
*
*       Macros
*
*  Pre-selection for various stdlib functions via macro to be able to
*  switch between implementations across various SEGGER products from
*  a central point.
*
*  Decisions whether to use a stdlib routine or not as the default
*  might depend upon knowledge of standard librarie internals.
*
**********************************************************************
*/

#ifndef   SEGGER_MEMCPY
  #define SEGGER_MEMCPY       memcpy
#endif

#ifndef   SEGGER_MEMSET
  #define SEGGER_MEMSET       memset
#endif

#ifndef   SEGGER_ATOI
  #define SEGGER_ATOI         SEGGER_atoi
#endif

#ifndef   SEGGER_ISALNUM
  #define SEGGER_ISALNUM      SEGGER_isalnum
#endif

#ifndef   SEGGER_ISALPHA
  #define SEGGER_ISALPHA      SEGGER_isalpha
#endif

#ifndef   SEGGER_STRLEN
  #define SEGGER_STRLEN       SEGGER_strlen
#endif

#ifndef   SEGGER_TOLOWER
  #define SEGGER_TOLOWER      SEGGER_tolower
#endif

#ifndef   SEGGER_STRCASECMP
  #define SEGGER_STRCASECMP   SEGGER_strcasecmp
#endif

#ifndef   SEGGER_STRNCASECMP
  #define SEGGER_STRNCASECMP  SEGGER_strncasecmp
#endif

#ifndef   SEGGER_SNPRINTF
  #define SEGGER_SNPRINTF     SEGGER_snprintf
#endif

#ifndef   SEGGER_VSNPRINTF
  #define SEGGER_VSNPRINTF    SEGGER_vsnprintf
#endif

/*********************************************************************
*
*       Utility functions
*
**********************************************************************
*/

//
// Memory operations.
//
void SEGGER_ARM_memcpy(void* pDest, const void* pSrc, int NumBytes);
void SEGGER_memcpy    (void* pDest, const void* pSrc, unsigned NumBytes);
void SEGGER_memxor    (void* pDest, const void* pSrc, unsigned NumBytes);

//
// String functions.
//
int      SEGGER_atoi       (const char* s);
int      SEGGER_isalnum    (int c);
int      SEGGER_isalpha    (int c);
unsigned SEGGER_strlen     (const char* s);
int      SEGGER_tolower    (int c);
int      SEGGER_strcasecmp (const char* sText1, const char* sText2);
int      SEGGER_strncasecmp(const char *sText1, const char *sText2, unsigned Count);

//
// Buffer/printf related.
//
void SEGGER_StoreChar    (SEGGER_BUFFER_DESC* pBufferDesc, char c);
void SEGGER_PrintUnsigned(SEGGER_BUFFER_DESC* pBufferDesc, U32 v, unsigned Base, int Precision);
void SEGGER_PrintInt     (SEGGER_BUFFER_DESC* pBufferDesc, I32 v, unsigned Base, int Precision);
int  SEGGER_snprintf     (char* pBuffer, int BufferSize, const char* sFormat, ...);
int  SEGGER_vsnprintf    (char* pBuffer, int BufferSize, const char* sFormat, va_list ParamList);
int  SEGGER_vsnprintfEx  (SEGGER_SNPRINTF_CONTEXT* pContext, const char* sFormat, va_list ParamList);

int  SEGGER_PRINTF_AddFormatter       (SEGGER_PRINTF_FORMATTER* pFormatter, SEGGER_pFormatter pfFormatter, char c);
void SEGGER_PRINTF_AddDoubleFormatter (void);
void SEGGER_PRINTF_AddIPFormatter     (void);
void SEGGER_PRINTF_AddBLUEFormatter   (void);
void SEGGER_PRINTF_AddCONNECTFormatter(void);
void SEGGER_PRINTF_AddSSLFormatter    (void);
void SEGGER_PRINTF_AddSSHFormatter    (void);
void SEGGER_PRINTF_AddHTMLFormatter   (void);

//
// BSP abstraction API.
//
int  SEGGER_BSP_GetUID  (U8 abUID[16]);
int  SEGGER_BSP_GetUID32(U32* pUID);
void SEGGER_BSP_SetAPI  (const SEGGER_BSP_API* pAPI);
void SEGGER_BSP_SeedUID (void);

//
// Other API.
//
void                   SEGGER_VERSION_GetString(char acText[8], unsigned Version);
SEGGER_PARSE_IP_STATUS SEGGER_ParseIP          (const char* sHost, U8* pBuffer, unsigned BufferSize, SEGGER_PARSE_IP_TYPE* pType);

#if defined(__cplusplus)
}                /* Make sure we have C-declarations in C++ programs */
#endif

#endif                      // Avoid multiple inclusion

/*************************** End of file ****************************/
