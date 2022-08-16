#ifndef REG_RW_H
#define REG_RW_H

uint32_t Reg_Read32(uint32_t regAddr);
void Reg_Write32(uint32_t regAddr, uint32_t regData);
void Reg_Write32_Mask(uint32_t regAddr, uint32_t regData, uint32_t regDataMask);

void write_reg32(uint32_t *addr, uint32_t data);
uint32_t read_reg32(uint32_t *addr);

uint64_t Reg_Read64(uint32_t regAddr);

#endif
