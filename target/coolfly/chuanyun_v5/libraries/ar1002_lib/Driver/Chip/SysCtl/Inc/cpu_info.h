#ifndef CPU_ID_H
#define CPU_ID_H

#include <stdint.h>

#define CPU_ID_INFO_ADDRESS 0x0000018C

typedef enum
{
    ENUM_CPU0_ID = 0,
    ENUM_CPU1_ID = 1,
    ENUM_CPU2_ID = 2,
}ENUM_CPU_ID;

ENUM_CPU_ID CPUINFO_GetLocalCpuId(void);
void CPUINFO_ICacheEnable(uint8_t u8_icacheEnable);
void CPUINFO_DCacheEnable(uint8_t u8_dcacheEnable);
void CPUINFO_ICacheInvalidate(void);
void CPUINFO_DCacheInvalidate(void);
void CPUINFO_DCacheClean(void);
void CPUINFO_DCacheCleanInvalidate(void);
void CPUINFO_DCacheInvalidateByAddr(uint32_t *addr, int32_t dsize);
void CPUINFO_DCacheCleanByAddr(uint32_t *addr, int32_t dsize);
void CPUINFO_DCacheCleanInvalidateByAddr(uint32_t *addr, int32_t dsize);


/* add for dma address and dtcm address convert */
#define DTCM_START_ADDR                 0x20000000
#define DTCM_END_ADDR                   0x20040000
#define DTCM_CPU0_DMA_ADDR_OFFSET       0x24080000
#define DTCM_CPU1_DMA_ADDR_OFFSET       0x24180000
#define DTCM_CPU2_DMA_ADDR_OFFSET       0xB0080000

#define ITCM_START_ADDR                 0x00000000
#define ITCM_END_ADDR                   0x00080000
#define ITCM_CPU0_DMA_ADDR_OFFSET       0x44000000
#define ITCM_CPU1_DMA_ADDR_OFFSET       0x44100000
#define ITCM_CPU2_DMA_ADDR_OFFSET       0xB0000000

uint32_t peripheralAddrConvert(uint32_t addr);

#endif

