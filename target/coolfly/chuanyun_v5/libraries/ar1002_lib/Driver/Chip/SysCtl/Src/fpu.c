#include <stdint.h>
#include "reg_rw.h"
#include "fpu.h"

void FPU_AccessEnable(void)
{
    Reg_Write32_Mask(0xE000ED88, 0xF << 20, 0xF << 20);
}

void FPU_AccessDisable(void)
{
    Reg_Write32_Mask(0xE000ED88, 0, 0xF << 20);
}

