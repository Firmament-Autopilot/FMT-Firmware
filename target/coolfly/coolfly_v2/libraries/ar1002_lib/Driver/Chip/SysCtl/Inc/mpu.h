#ifndef __MPU_H__
#define __MPU_H__

#include "ar8020.h"

#define MPU_DEFS_RASR_SIZE_32B                  (0x04 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_64B                  (0x05 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_128B                 (0x06 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_256B                 (0x07 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_512B                 (0x08 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_1KB                  (0x09 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_2KB                  (0x0A << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_4KB                  (0x0B << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_8KB                  (0x0C << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_16KB                 (0x0D << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_32KB                 (0x0E << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_64KB                 (0x0F << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_128KB                (0x10 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_256KB                (0x11 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_512KB                (0x12 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_1MB                  (0x13 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_2MB                  (0x14 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_4MB                  (0x15 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_8MB                  (0x16 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_16MB                 (0x17 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_32MB                 (0x18 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_64MB                 (0x19 << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_128MB                (0x1A << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_256MB                (0x1B << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_512MB                (0x1C << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_1GB                  (0x1D << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_2GB                  (0x1E << MPU_RASR_SIZE_Pos)
#define MPU_DEFS_RASR_SIZE_4GB                  (0x1F << MPU_RASR_SIZE_Pos)

#define MPU_DEFS_RASE_AP_NO_ACCESS              (0x0 << MPU_RASR_AP_Pos)
#define MPU_DEFS_RASE_AP_PRIV_RW                (0x1 << MPU_RASR_AP_Pos)
#define MPU_DEFS_RASE_AP_PRIV_RW_USER_RO        (0x2 << MPU_RASR_AP_Pos)
#define MPU_DEFS_RASE_AP_FULL_ACCESS            (0x3 << MPU_RASR_AP_Pos)
#define MPU_DEFS_RASE_AP_PRIV_RO                (0x5 << MPU_RASR_AP_Pos)
#define MPU_DEFS_RASE_AP_RO                     (0x6 << MPU_RASR_AP_Pos)

#define MPU_DEFS_NORMAL_MEMORY_WT               (MPU_RASR_C_Msk)
#define MPU_DEFS_NORMAL_MEMORY_WB               (MPU_RASR_C_Msk | MPU_RASR_B_Msk)
#define MPU_DEFS_NORMAL_SHARED_MEMORY_WT        (MPU_RASR_C_Msk | MPU_RASR_S_Msk)
#define MPU_DEFS_NORMAL_SHARED_MEMORY_WB        (MPU_DEFS_NORMAL_MEMORY_WB | MPU_RASR_S_Msk)

#define MPU_DEFS_SHARED_DEVICE                  (MPU_RASR_B_Msk)
#define MPU_DEFS_STRONGLY_ORDERED_DEVICE        (0x0)


// SRAM DCache disable
#define SRAM_MEMORY_MPU_REGION_NUMBER                    0
#define SRAM_MEMORY_MPU_REGION_ST_ADDR                   0x21000000
#define SRAM_MEMORY_MPU_REGION_ATTR                      (MPU_DEFS_RASE_AP_FULL_ACCESS) | \
                                                         (1  << 19) | \
                                                         (MPU_DEFS_RASR_SIZE_32KB) | \
                                                         (MPU_RASR_ENABLE_Msk)

#define SRAM_CONFIGURE_MEMORY_MPU_REGION_NUMBER          1
#define SRAM_CONFIGURE_MEMORY_MPU_REGION_ST_ADDR         SRAM_CONFIGURE_MEMORY_ST_ADDR
#define SRAM_CONFIGURE_MEMORY_MPU_REGION_ATTR            (0  << 28) | \
                                                         (MPU_DEFS_RASE_AP_FULL_ACCESS) | \
                                                         (1  << 19) | \
                                                         (MPU_DEFS_RASR_SIZE_16KB) | \
                                                         (MPU_RASR_ENABLE_Msk)

#define SRAM_DEBUG_MEMORY_MPU_REGION_NUMBER              2
#define SRAM_DEBUG_MEMORY_MPU_REGION_ST_ADDR             SRAM_DEBUG_LOG_BUFFER_ST_ADDR
#define SRAM_DEBUG_MEMORY_MPU_REGION_ATTR                (MPU_DEFS_RASE_AP_FULL_ACCESS) | \
                                                         (1  << 19) | \
                                                         (MPU_DEFS_RASR_SIZE_8KB) | \
                                                         (MPU_RASR_ENABLE_Msk)                                                      

#define WDT0_1_MPU_REGION_NUMBER                         3
#define WDT0_1_MPU_REGION_ST_ADDR                        0x40600000
#define WDT0_1_MPU_REGION_ATTR                           (MPU_DEFS_RASE_AP_NO_ACCESS) | \
                                                         (1  << 19) | \
                                                         (MPU_DEFS_RASR_SIZE_1MB) | \
                                                         (MPU_RASR_ENABLE_Msk)

#define WDT2_MPU_REGION_NUMBER                           4
#define WDT2_MPU_REGION_ST_ADDR                          0xA0200000
#define WDT2_MPU_REGION_ATTR                             (MPU_DEFS_RASE_AP_NO_ACCESS) | \
                                                         (1  << 19) | \
                                                         (MPU_DEFS_RASR_SIZE_64KB) | \
                                                         (MPU_RASR_ENABLE_Msk)                                                    

#define FALSH_MEMORY_MPU_REGION_NUMBER                   5
#define FALSH_MEMORY_MPU_REGION_ST_ADDR                  0x10000000
#define FALSH_MEMORY_MPU_REGION_ATTR                     (MPU_DEFS_RASE_AP_FULL_ACCESS) | \
                                                         (1  << 19) | \
                                                         (MPU_DEFS_RASR_SIZE_16MB) | \
                                                         (MPU_RASR_ENABLE_Msk)

#define QUAD_SPI_MPU_REGION_NUMBER                       6
#define QUAD_SPI_MPU_REGION_ST_ADDR                      0x40C00000
#define QUAD_SPI_MPU_REGION_ATTR                         (MPU_DEFS_RASE_AP_RO) | \
                                                         (1  << 19) | \
                                                         (MPU_DEFS_RASR_SIZE_512B) | \
                                                         (MPU_RASR_ENABLE_Msk)



int32_t MPU_QuadspiProtectDisable(void);
int32_t MPU_QuadspiProtectEnable(void);
int32_t MPU_SetUp(void);

#endif
