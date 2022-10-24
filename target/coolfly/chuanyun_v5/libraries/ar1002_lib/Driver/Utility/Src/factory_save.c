#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "memory_config.h"
#include "debuglog.h"
#include "quad_spi_ctrl.h"
#include "nor_flash.h"
#include "cfg_parser.h"
#include "factory.h"


extern STRU_FACTORY_SETTING *pst_factory_defaultcfgnode;
extern int FCT_ListAllNode(STRU_FACTORY_SETTING *fct, STRU_NODE_LIST *p_nodelist);

void FCT_SaveToFlashTest(void)
{
    DLOG_Info("pst_factory_defaultcfgnode = 0x%lx", (uint32_t)pst_factory_defaultcfgnode);

    if (NULL == pst_factory_defaultcfgnode)
    {
        return;
    }

    FCT_Save2Flash((STRU_FACTORY_SETTING *)pst_factory_defaultcfgnode);
}


/*
 * write data & checksum to flash
*/
int FCT_Save2Flash(STRU_FACTORY_SETTING * fct)
{
    uint32_t i         = 0;
    uint32_t checksum  = 0;
    uint8_t *pdata     = (uint8_t *)fct;
    uint32_t totalsize = sizeof(STRU_FACTORY_SETTING);
    uint32_t writesize = 0;
    STRU_NODE_LIST tmpnode;

    //check node valid
    if (FCT_ListAllNode(fct, &tmpnode) <= 0)
    {
        return 0;
    }

    for (i = 0; i < totalsize; i++)
    {
        checksum += pdata[i];
    }

    DLOG_Info("save to flash: 0x%x 0x%x", NV_FLASH_FCT_START_ADDR_0, NV_FLASH_FCT_START_ADDR_1);

    //erase flash ADDR_0
    writesize = 0;
    do
    {
        NOR_FLASH_EraseSector(NV_FLASH_FCT_START_ADDR_0 + writesize);
        writesize += (4 * 1024);
    }while(writesize < totalsize);

    //write data
    NOR_FLASH_WriteByteBuffer(NV_FLASH_FCT_START_ADDR_0, pdata, totalsize);
    //write checksum
    NOR_FLASH_WriteByteBuffer(NV_FLASH_FCT_START_ADDR_0 + totalsize, (uint8_t *)&checksum, sizeof(checksum));

    //erase flash ADDR_1
    writesize = 0;
    do
    {
        NOR_FLASH_EraseSector(NV_FLASH_FCT_START_ADDR_1 + writesize);
        writesize += (4 * 1024);
    }while(writesize < totalsize);

    NOR_FLASH_WriteByteBuffer(NV_FLASH_FCT_START_ADDR_1, pdata, totalsize);
    NOR_FLASH_WriteByteBuffer(NV_FLASH_FCT_START_ADDR_1 + totalsize, (uint8_t *)&checksum, sizeof(checksum));

    return 1;
}

/*
 * reset factory setting
*/
void FCT_Reset(void)
{
    uint32_t writesize = 0;
    uint32_t totalsize = NV_FLASH_FCT_SIZE;

    do
    {
        NOR_FLASH_EraseSector(NV_FLASH_FCT_START_ADDR_0 + writesize);
        writesize += (4 * 1024);
    }while(writesize < totalsize);

}
