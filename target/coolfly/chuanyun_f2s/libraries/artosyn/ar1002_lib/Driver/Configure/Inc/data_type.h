
#ifndef __DATATYPE_H
#define __DATATYPE_H

#define ECHO
#define ENUMERATE
#define FPGA

#define USE_FULL_ASSERT
/* shift bit field */
#define SBF(v, f)    ((v) << (f))

#ifndef BIT
#define BIT(n)    ((uint32_t)1 << (n))
#endif/* BIT */

/** @addtogroup Exported_macro
 * * @{
 * */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))

#define __IO    volatile             /*!< Defines 'read / write' permissions */

#define m7_malloc             pvPortMalloc
#define m7_free               vPortFree

#define TRUE  (1)
#define FALSE (0)

#endif

