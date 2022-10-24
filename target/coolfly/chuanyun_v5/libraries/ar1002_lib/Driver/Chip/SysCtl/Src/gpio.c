#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "gpio.h"
#include "debuglog.h" 
#include "reg_rw.h"
#include "interrupt.h"


//#define GPIO_DEBUGE

#ifdef GPIO_DEBUGE
#define DLOG_INFO(...) DLOG_Info(__VA_ARGS__)
#else
#define DLOG_INFO(...)
#endif

void GPIO_SetMode(uint32_t gpioNum, uint32_t mode)
{

    uint32_t u32_GroupNoAddr = 0;
    uint8_t u8_GroupNo = 0;
    
    u8_GroupNo = (gpioNum>>4);
   
    u32_GroupNoAddr = u8_GroupNo*0x04 + GPIO_MODE0_ADDR;

    
    Reg_Write32_Mask(u32_GroupNoAddr, (mode << ((gpioNum % 16)<<1)), (0x3 << ((gpioNum % 16)<<1)));
  
    DLOG_INFO("\n SetMode %x %x \n", u32_GroupNoAddr, Reg_Read32(u32_GroupNoAddr));
}

#if MULTIPLE
void GPIO_ModeRange(uint32_t gpioNum1, uint32_t gpioNum2, uint32_t mode)
{
    uint32_t i;
    uint32_t GPIOregVal;

    DLOG_INFO("\nModeRange\n");
    for (i = gpioNum1; i <= gpioNum2; ++i)
    {
		GPIO_SetMode(i, mode);
        GPIO_SetPinDirect(i, GPIO_DATA_DIRECT_OUTPUT);
        GPIO_SetPinCtrl(i, GPIO_CTRL_SOFTWARE);
    }
}

void GPIO_ModeListVal(uint32_t *pList, uint32_t size, uint32_t mode)
{
    uint32_t i;
    DLOG_INFO("\nModeListVal\n");
    for (i = 0; i <= size; ++i)
    {
		GPIO_SetMode((*pList), mode);
        GPIO_SetPinDirect((*pList), GPIO_DATA_DIRECT_OUTPUT);
        GPIO_SetPinCtrl((*pList), GPIO_CTRL_SOFTWARE);
	    ++pList;
    }
}


void GPIO_ModeListList(uint32_t *pList, uint32_t size, uint32_t *mode)
{
    uint32_t i;
    DLOG_INFO("\nModeListList\n");
    for (i = 0; i <= size; ++i)
    {
		GPIO_SetMode((*pList), (*mode));
        GPIO_SetPinDirect((*pList), GPIO_DATA_DIRECT_OUTPUT);
        GPIO_SetPinCtrl((*pList), GPIO_CTRL_SOFTWARE);
	    ++pList;
	    ++mode;
    }
}
#endif

void GPIO_SetPin(uint32_t gpioNum, uint32_t value)
{
    DLOG_INFO("\n SetPin \n");
    
    uint32_t u32_RegNoAddr = 0;
    uint32_t u32_GroupNoAddr = 0;
    uint8_t u8_PinNo = ((gpioNum%32)%8);
    
    switch((gpioNum>>5))
    {
        case 0:
        {
            u32_GroupNoAddr = GPIO0_BASE_ADDR;
            break;
        }
        case 1:
        {
            u32_GroupNoAddr = GPIO1_BASE_ADDR;
            break;
        }
        case 2:
        {
            u32_GroupNoAddr = GPIO2_BASE_ADDR;
            break;
        }
        case 3:
        {
            u32_GroupNoAddr = GPIO3_BASE_ADDR;
            break;
        }
        default:
            return ;
    }
    switch(((gpioNum%32)>>3))
    {
        case 0:
        {
            u32_RegNoAddr = GPIO_DATA_A_OFFSET;
            break;
        }
        case 1:
        {
            u32_RegNoAddr = GPIO_DATA_B_OFFSET;
            break;
        }
        case 2:
        {
            u32_RegNoAddr = GPIO_DATA_C_OFFSET;
            break;
        }
        case 3:
        {
            u32_RegNoAddr = GPIO_DATA_D_OFFSET;
            break;
        }
        default:
            return ;
    }

    if (value == 0)
    {
        Reg_Write32_Mask(u32_GroupNoAddr + u32_RegNoAddr, 0, (1 << u8_PinNo));
    }
    else
    {
        Reg_Write32_Mask(u32_GroupNoAddr + u32_RegNoAddr, (1 << u8_PinNo), (1 << u8_PinNo));
    }

}
#if MULTIPLE
void GPIO_SetPinRange(uint32_t gpioNum1, uint32_t gpioNum2, uint32_t mode)
{
    uint32_t i;
    uint32_t GPIOregVal;

    DLOG_INFO("\n SetPinRange \n");
    for (i = gpioNum1; i <= gpioNum2; ++i)
    {
        GPIO_SetPin(i, mode);
    }
}

void GPIO_SetPinListVal(uint32_t *pList, uint32_t size, uint32_t mode)
{
    uint32_t i;
    DLOG_INFO("\n SetPinListVal \n");
    for (i = 0; i <= size; ++i)
    {
        GPIO_SetPin((*pList), mode);
        ++pList;
    }
}

void GPIO_SetPinListList(uint32_t *pList, uint32_t size, uint32_t *mode)
{
    uint32_t i;
    DLOG_INFO("\n SetPinListList \n");
    for (i = 0; i <= size; ++i)
    {
        GPIO_SetPin((*pList), (*mode));
        ++pList;
        ++mode;
    }
}
#endif
uint32_t GPIO_Get(uint32_t gpioNum)
{
    uint32_t u32_RegNoAddr = 0;
    // uint32_t u32_PinNoAddr = 0;
    uint32_t u32_GroupNoAddr = 0;
    uint8_t u8_RegNo = 0;
    uint8_t u8_PinNo = 0;
    uint8_t u8_GroupNo = 0;
    uint32_t u32_GpioRegVal = 0;

    
    u8_GroupNo = (gpioNum>>5);
    u8_RegNo = (gpioNum%32)>>3;
    u8_PinNo = (gpioNum%32)%8;
    
    
    u32_GroupNoAddr = u8_GroupNo*0x40000 + GPIO0_BASE_ADDR;
    u32_RegNoAddr = u8_RegNo*0x04 + GPIO_EXT_PORT_A_OFFSET;
    
    u32_GpioRegVal = Reg_Read32(u32_GroupNoAddr + u32_RegNoAddr);
    return ((u32_GpioRegVal >> u8_PinNo) & 1);
}

uint32_t GPIO_GetPin(uint32_t gpioNum)
{

    return GPIO_Get(gpioNum);
}

void GPIO_SetPinDirect(uint32_t gpioNum, uint32_t mode)
{
    uint32_t u32_GroupNoAddr = 0;
    uint32_t u32_RegNoAddr = 0;
    uint8_t  u8_RegNo = 0;
    uint8_t  u8_PinNo = 0;
    uint8_t  u8_GroupNo = 0;
    uint32_t u32_GpioRegVal = 0;
    
    u8_GroupNo = (gpioNum>>5);
    u8_RegNo = (gpioNum%32)>>3;
    u8_PinNo = (gpioNum%32)%8;

    u32_GroupNoAddr = u8_GroupNo*0x40000 + GPIO0_BASE_ADDR;
    u32_RegNoAddr = u8_RegNo*0x0C + GPIO_DATA_DIRECT_A_OFFSET;   
    u32_GpioRegVal = Reg_Read32(u32_GroupNoAddr + u32_RegNoAddr);
    if(GPIO_DATA_DIRECT_OUTPUT == mode)
    {        
        u32_GpioRegVal |= (mode << u8_PinNo);
    }
    else
    {
        u32_GpioRegVal &= ~(1 << u8_PinNo);
    }
    
    Reg_Write32(u32_GroupNoAddr + u32_RegNoAddr, u32_GpioRegVal);

    DLOG_INFO("\n DataDirect %x\n",Reg_Read32(u32_GroupNoAddr + u32_RegNoAddr));
}

void GPIO_SetPinCtrl(uint32_t gpioNum, uint32_t mode)
{
    uint32_t u32_GroupNoAddr = 0;
    uint32_t u32_RegNoAddr = 0;
    uint8_t  u8_RegNo = 0;
    uint8_t  u8_PinNo = 0;
    uint8_t  u8_GroupNo = 0;
    uint32_t u32_GpioRegVal = 0;
    

    u8_GroupNo = (gpioNum>>5);
    u8_RegNo = (gpioNum%32)>>3;
    u8_PinNo = (gpioNum%32)%8;

    u32_GroupNoAddr = u8_GroupNo*0x40000 + GPIO0_BASE_ADDR;
    u32_RegNoAddr = u8_RegNo*0x0C + GPIO_CTRL_A_OFFSET;   
    u32_GpioRegVal = Reg_Read32(u32_GroupNoAddr + u32_RegNoAddr);
    if(GPIO_CTRL_SOFTWARE == mode)
    {                
        u32_GpioRegVal &= ~(1 << u8_PinNo);
    }
    else
    {
        u32_GpioRegVal |= (mode << u8_PinNo);
    }
    
    Reg_Write32(u32_GroupNoAddr + u32_RegNoAddr, u32_GpioRegVal);

    DLOG_INFO("\n SetPinCtrl %x\n",Reg_Read32(u32_GroupNoAddr + u32_RegNoAddr));
}

void GPIO_Intr_SetPinIntrEn(uint32_t gpioNum, uint32_t mode)
{
    // uint32_t u32_PinNoAddr = 0;
    uint32_t u32_GroupNoAddr = 0;
    // uint8_t  u8_RegNo = 0;
    uint8_t  u8_PinNo = 0;
    uint8_t  u8_GroupNo = 0;
    uint32_t u32_GpioRegVal = 0;
    
    u8_GroupNo = (gpioNum>>5);
    // u8_RegNo = (gpioNum%32)>>3;
    u8_PinNo = (gpioNum%32)%8;
    

    u32_GroupNoAddr = u8_GroupNo*0x40000 + GPIO0_BASE_ADDR;    
    u32_GpioRegVal = Reg_Read32(u32_GroupNoAddr + GPIO_INTEN_OFFSET);
    if(GPIO_INTEN_INTERRUPT == mode)
    {        
        u32_GpioRegVal |= (mode << u8_PinNo);
    }
    else
    {
        u32_GpioRegVal &= ~(1 << u8_PinNo);
    }

    Reg_Write32(u32_GroupNoAddr + GPIO_INTEN_OFFSET, u32_GpioRegVal);
    DLOG_INFO("\n SetPinInten %x\n",Reg_Read32(u32_GroupNoAddr + GPIO_INTEN_OFFSET));

}
void GPIO_Intr_SetPinIntrMask(uint32_t gpioNum, uint32_t mode)
{
    uint32_t u32_GroupNoAddr = 0;
    // uint8_t  u8_RegNo = 0;
    uint8_t  u8_PinNo = 0;
    uint8_t  u8_GroupNo = 0;
    uint32_t u32_GpioRegVal = 0;
    
    u8_GroupNo = (gpioNum>>5);
    // u8_RegNo = (gpioNum%32)>>3;
    u8_PinNo = (gpioNum%32)%8;
    

    u32_GroupNoAddr = u8_GroupNo*0x40000 + GPIO0_BASE_ADDR;    
    u32_GpioRegVal = Reg_Read32(u32_GroupNoAddr + GPIO_MASK_OFFSET);
    if(GPIO_MASK_MASK == mode)
    {
        u32_GpioRegVal &= ~(1 << u8_PinNo);
    }
    else
    {
        u32_GpioRegVal |= (mode << u8_PinNo);
    }

    Reg_Write32(u32_GroupNoAddr + GPIO_MASK_OFFSET, u32_GpioRegVal);
    DLOG_INFO("\n SetPinMask %x\n",Reg_Read32(u32_GroupNoAddr + GPIO_MASK_OFFSET));

}

void GPIO_Intr_SetPinIntrType(uint32_t gpioNum, uint32_t mode)
{
    uint32_t u32_GroupNoAddr = 0;
    // uint8_t  u8_RegNo = 0;
    uint8_t  u8_PinNo = 0;
    uint8_t  u8_GroupNo = 0;
    uint32_t u32_GpioRegVal = 0;
    

    u8_GroupNo = (gpioNum>>5);
    // u8_RegNo = (gpioNum%32)>>3;
    u8_PinNo = (gpioNum%32)%8;
    

    u32_GroupNoAddr = u8_GroupNo*0x40000 + GPIO0_BASE_ADDR;    
    u32_GpioRegVal = Reg_Read32(u32_GroupNoAddr + GPIO_INTTYPE_OFFSET);
    if(GPIO_INTTYPE_EDGE == mode)
    {        
        u32_GpioRegVal |= (mode << u8_PinNo);
    }
    else
    {
        u32_GpioRegVal &= ~(1 << u8_PinNo);
    }
    
    Reg_Write32(u32_GroupNoAddr + GPIO_INTTYPE_OFFSET, u32_GpioRegVal);

    DLOG_INFO("\n SetPinInttype %x\n",Reg_Read32(u32_GroupNoAddr + GPIO_INTTYPE_OFFSET));
}
void GPIO_Intr_SetPinIntrPol(uint32_t gpioNum, uint32_t mode)
{
    uint32_t u32_GroupNoAddr = 0;
    // uint8_t  u8_RegNo = 0;
    uint8_t  u8_PinNo = 0;
    uint8_t  u8_GroupNo = 0;
    uint32_t u32_GpioRegVal = 0;
    
    u8_GroupNo = (gpioNum>>5);
    // u8_RegNo = (gpioNum%32)>>3;
    u8_PinNo = (gpioNum%32)%8;
    

    u32_GroupNoAddr = u8_GroupNo*0x40000 + GPIO0_BASE_ADDR;    
    u32_GpioRegVal = Reg_Read32(u32_GroupNoAddr + GPIO_INTPOL_OFFSET);
    if(GPIO_INTPOL_HIGH == mode)
    {        
        u32_GpioRegVal |= (mode << u8_PinNo);
    }
    else
    {
        u32_GpioRegVal &= ~(1 << u8_PinNo);
    }
    
    Reg_Write32(u32_GroupNoAddr + GPIO_INTPOL_OFFSET, u32_GpioRegVal);

    DLOG_INFO("\n SetPinIntpol %x\n",Reg_Read32(u32_GroupNoAddr + GPIO_INTPOL_OFFSET));

}
#if 0
void GPIO_SetPinDebounce(uint32_t gpioNum, uint32_t mode)
{
    uint32_t u32_GroupNoAddr = 0;
    uint8_t  u8_RegNo = 0;
    uint8_t  u8_PinNo = 0;
    uint8_t  u8_GroupNo = 0;
    uint32_t u32_GpioRegVal = 0;
    

    u8_GroupNo = (gpioNum>>5);
    u8_RegNo = (gpioNum%32)>>3;
    u8_PinNo = (gpioNum%32)%8;

    u32_GroupNoAddr = u8_GroupNo*0x40000 + GPIO0_BASE_ADDR;    
    u32_GpioRegVal = Reg_Read32(u32_GroupNoAddr + GPIO_DEBOUNCE_OFFSET);
    if(GPIO_DEBOUNCE_ON == mode)
    {        
        u32_GpioRegVal |= (mode << u8_PinNo);
    }
    else
    {
        u32_GpioRegVal &= ~(1 << u8_PinNo);
    }
    
    Reg_Write32(u32_GroupNoAddr + GPIO_DEBOUNCE_OFFSET, u32_GpioRegVal);

    DLOG_INFO("\n SetPinDebounce %x\n",Reg_Read32(u32_GroupNoAddr + GPIO_DEBOUNCE_OFFSET));
}
#endif

uint32_t GPIO_Intr_GetIntrStatus(uint32_t gpioNum)
{
    uint32_t u32_GroupNoAddr = 0;
    // uint8_t  u8_RegNo = 0;
    uint8_t u8_PinNo = 0;
    uint8_t u8_GroupNo = 0;
    uint32_t u32_GpioRegVal = 0;

    u8_GroupNo = (gpioNum>>5);
    // u8_RegNo = (gpioNum%32)>>3;
    u8_PinNo = (gpioNum%32)%8;

        
    u32_GroupNoAddr = u8_GroupNo*0x40000 + GPIO0_BASE_ADDR;
    
    u32_GpioRegVal = Reg_Read32(u32_GroupNoAddr + GPIO_INTSTATUS_OFFSET);
    return ((u32_GpioRegVal >> u8_PinNo) & 1);
}

uint32_t GPIO_Intr_GetIntrGroupStatus(uint32_t u32_vectorNum)
{
    uint32_t u32_GroupNoAddr = 0;
   
    switch(u32_vectorNum)
    {
        case GPIO_INTR_N0_VECTOR_NUM:
        {
            u32_GroupNoAddr = GPIO0_BASE_ADDR;
            break;
        }
        case GPIO_INTR_N1_VECTOR_NUM:
        {
            u32_GroupNoAddr = GPIO1_BASE_ADDR;
            break;
        }
        case GPIO_INTR_N2_VECTOR_NUM:
        {
            u32_GroupNoAddr = GPIO2_BASE_ADDR;
            break;
        }
        case GPIO_INTR_N3_VECTOR_NUM:
        {
            u32_GroupNoAddr = GPIO3_BASE_ADDR;
            break;
        }
        default:
            return 0;
    }

    return Reg_Read32(u32_GroupNoAddr + GPIO_INTSTATUS_OFFSET);
}

uint32_t GPIO_Intr_GetRawIntrStatus(uint32_t gpioNum)
{
    uint32_t u32_GroupNoAddr = 0;
    // uint8_t  u8_RegNo = 0;
    uint8_t  u8_PinNo = 0;
    uint8_t  u8_GroupNo = 0;
    uint32_t u32_GpioRegVal = 0;
    
    u8_GroupNo = (gpioNum>>5);
    // u8_RegNo = (gpioNum%32)>>3;
    u8_PinNo = (gpioNum%32)%8;

    u32_GroupNoAddr = u8_GroupNo*0x40000 + GPIO0_BASE_ADDR;    

    u32_GpioRegVal = Reg_Read32(u32_GroupNoAddr + GPIO_RAW_INTSTATUS_OFFSET);
    return ((u32_GpioRegVal >> u8_PinNo) & 1);

}

void GPIO_Intr_ClearIntr(uint32_t gpioNum)
{
    uint32_t u32_GroupNoAddr = 0;
    // uint8_t u8_RegNo = 0;
    uint8_t u8_PinNo = 0;
    uint8_t u8_GroupNo = 0;
    uint32_t u32_GpioRegVal = 0;

    
    u8_GroupNo = (gpioNum>>5);
    u8_PinNo = (gpioNum%32)%8;
    
    
    u32_GroupNoAddr = u8_GroupNo*0x40000 + GPIO0_BASE_ADDR;
    DLOG_INFO("\n ClearInt %x %x \n",u32_GpioRegVal,GPIO_Intr_GetIntrStatus(gpioNum));
    u32_GpioRegVal |= 1 << u8_PinNo;
    Reg_Write32(u32_GroupNoAddr + GPIO_CLEARINT_OFFSET, u32_GpioRegVal);
}

void GPIO_Intr_ClearIntrGroup(uint32_t u32_vectorNum, uint8_t u8_flag)
{
   
    uint32_t u32_GroupNoAddr = 0;
   
    switch(u32_vectorNum)
    {
        case GPIO_INTR_N0_VECTOR_NUM:
        {
            u32_GroupNoAddr = GPIO0_BASE_ADDR + GPIO_CLEARINT_OFFSET;
            break;
        }
        case GPIO_INTR_N1_VECTOR_NUM:
        {
            u32_GroupNoAddr = GPIO1_BASE_ADDR + GPIO_CLEARINT_OFFSET;
            break;
        }
        case GPIO_INTR_N2_VECTOR_NUM:
        {
            u32_GroupNoAddr = GPIO2_BASE_ADDR + GPIO_CLEARINT_OFFSET;
            break;
        }
        case GPIO_INTR_N3_VECTOR_NUM:
        {
            u32_GroupNoAddr = GPIO3_BASE_ADDR + GPIO_CLEARINT_OFFSET;
            break;
        }
        default:
            return ;
    }

    Reg_Write32(u32_GroupNoAddr, u8_flag);
}
