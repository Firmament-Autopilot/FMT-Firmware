#include "cy_pdl.h"
#include "cybsp.h"
#include "mtb_hal.h"
#include "cycfg_qspi_memslot.h"
#include "mtb_serial_memory.h"
#include "rtthread.h"

#define DRV_DEBUG
#define LOG_TAG         "drv_hyperam"
#include <drv_log.h>

#define PSRAM_ADDRESS                 (0x64800000) /* PSRAM test address */

#ifdef BSP_USING_HYPERAM
#ifdef RT_USING_MEMHEAP_AS_HEAP
    struct rt_memheap system_heap;
#endif

static int hyperam_init(void)
{
    LOG_D("hyperam init success, mapped at 0x%X, size is %d bytes, data width is %d", PSRAM_ADDRESS, BSP_USING_HYPERAM_SIZE, 16);
#ifdef RT_USING_MEMHEAP_AS_HEAP
    /* If RT_USING_MEMHEAP_AS_HEAP is enabled, HYPERAM is initialized to the heap */
    rt_memheap_init(&system_heap, "hyperam", (void *)PSRAM_ADDRESS, BSP_USING_HYPERAM_SIZE);
#endif
    return RT_EOK;
}
INIT_BOARD_EXPORT(hyperam_init);
#endif