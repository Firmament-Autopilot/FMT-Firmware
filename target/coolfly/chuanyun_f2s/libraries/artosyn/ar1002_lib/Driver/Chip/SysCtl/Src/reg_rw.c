#include "stddef.h"
#include "stdint.h"
#include "reg_rw.h"

uint32_t Reg_Read32(uint32_t regAddr)
{
    return *((volatile uint32_t*)regAddr);
}

void Reg_Write32(uint32_t regAddr, uint32_t regData)
{
    *((volatile uint32_t*)regAddr) = regData;
}

void Reg_Write32_Mask(uint32_t regAddr, uint32_t regData, uint32_t regDataMask)
{
    uint32_t u32_regDataTmp;

    u32_regDataTmp = *((volatile uint32_t*)regAddr);
    u32_regDataTmp &= ~regDataMask;
    u32_regDataTmp |= regData & regDataMask; 
        
    *((volatile uint32_t*)regAddr) = u32_regDataTmp;
}

void write_reg32(uint32_t *addr, uint32_t data)
{
    *((volatile uint32_t*)addr) = data;
}

uint32_t read_reg32(uint32_t *addr)
{
    return *((volatile uint32_t*)addr);
}

uint64_t Reg_Read64(uint32_t regAddr)
{
    volatile uint64_t* ptr_regAddr = (uint64_t*)regAddr;
    return *ptr_regAddr;
}
