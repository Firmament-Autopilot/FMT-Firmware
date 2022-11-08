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
#include "hal_gpio.h"

#include "drv_usart.h"

STRU_NODE_LIST st_node_list_default  = {0};
STRU_NODE_LIST st_node_list_user = {0};


STRU_FACTORY_SETTING *pst_factory_defaultcfgnode = NULL;

#define FLASH_APB_FCT_START_ADDR_0  (NV_FLASH_FCT_START_ADDR_0 + FLASH_APB_BASE_ADDR)
#define FLASH_APB_FCT_START_ADDR_1  (NV_FLASH_FCT_START_ADDR_1 + FLASH_APB_BASE_ADDR)


/*
 * 1: valid
 * 0: unvalid
*/
static uint8_t FCT_CheckFlashSettingValid(STRU_FACTORY_SETTING *fct)
{
    uint8_t *pdata         = (uint8_t *)fct;

    STRU_cfgNode *fct_node = &(fct->st_factoryNode);

    uint8_t  valid = 0;
    uint32_t fct_len = sizeof(STRU_cfgNode) + fct_node->nodeDataSize;
    uint32_t i;
    uint32_t checksum = 0;

    if (fct_len > 4 * 1024) //sector size: 4 * 1024 
    {
        BOOT_Printf("Error: factory len = 0x%p 0x%lx \r\n", fct, fct_len);
        return 0;
    }

    //checksum
    for (i = 0; i < fct_len; i++)
    {
        checksum += pdata[i];
    }

    valid = (checksum == *(uint32_t *)(pdata + fct_len));
    if (valid == 0)
    {
        BOOT_Printf("fct checksum error: %p %ld %ld \r\n", pdata, checksum, *(uint32_t *)(pdata + fct_len));
        BOOT_Printf("fct_len: %ld \r\n", fct_len);

    }

    return valid;
}


/*
 * return: factory node count
*/
int FCT_ListAllNode(STRU_FACTORY_SETTING *fct, STRU_NODE_LIST *p_nodelist)
{
    STRU_FACTORY_SETTING_DATA *fct_data = (STRU_FACTORY_SETTING_DATA *)&fct->st_factorySetting;
    uint32_t fct_datasize = fct->st_factoryNode.nodeDataSize;
    uint32_t cur_datasize = 0;
    p_nodelist->nodecnt   = 0;

    if (FACTORY_SETTING_NODE_ID != fct->st_factoryNode.nodeId)
    {
        BOOT_Printf("No factorySetting data addr=0x%lx \r\n", (uint32_t)fct);
        return 0;
    }
    BOOT_Printf("fct data addr=0x%lx 0x%lx size=%ld \r\n", (uint32_t)fct, (uint32_t)fct_data, fct_datasize);

    //because node parse is 4bytes aligned
    if (fct_datasize & 0x03)
    {
        fct_datasize += (fct_datasize + 4) & (~0x03);
    }

    //parse factory data to get sub node 
    while (cur_datasize < fct_datasize)
    {
        STRU_cfgNode * node = (STRU_cfgNode *)((uint8_t *)fct_data + cur_datasize);
        // BOOT_Printf("node ptr=0x% 0x%x %d \r\n", node, node->nodeId, node->nodeDataSize);

        if ( (node->nodeId & FACTORY_NODE_ID_MASK) != FACTORY_NODE_ID_MASK)
        {
            p_nodelist->nodecnt = 0;
            BOOT_Printf("fct node id=%d \r\n", node->nodeId);
            return 0;
        }

        if (p_nodelist->nodecnt < MAX_FCT_NODE)
        {
            p_nodelist->offset_to_fct_node[p_nodelist->nodecnt] = ((uint32_t)node - (uint32_t)fct);
            p_nodelist->nodeid[p_nodelist->nodecnt] = node->nodeId;
            p_nodelist->nodecnt ++;
        }

        cur_datasize += sizeof(STRU_cfgNode);

        if (node->nodeDataSize & 0x03)
        {
            cur_datasize += (node->nodeDataSize + 4) & (~0x03);  //STRU_cfgNode is 4bytes-align alignment
        }
        else
        {
            cur_datasize += node->nodeDataSize;
        }
    }

    //check if some error happen when node parse
    if (cur_datasize != fct_datasize)
    {
        p_nodelist->nodecnt = 0;
        BOOT_Printf("Fct setting parser error %d %d \r\n", cur_datasize, fct_datasize);
    }

    return (p_nodelist->nodecnt);
}


/*
 * 0: Fail to get factory setting
 * 1: suceess
*/
int FCT_Load2Sram(void)
{
    uint8_t  valid0 = 0, valid1 = 0;
    uint32_t flash_factoryAddr;


    // get sram config data & node
    void *p_sramcfgdata = CFGBIN_GetNodeAndData((STRU_cfgBin *)SRAM_CONFIGURE_MEMORY_ST_ADDR, FACTORY_SETTING_NODE_ID, (STRU_cfgNode **)&pst_factory_defaultcfgnode);
    if (p_sramcfgdata == NULL || pst_factory_defaultcfgnode == NULL)
    {
        BOOT_Printf("Fail get sram %p %p \r\n", p_sramcfgdata, pst_factory_defaultcfgnode);
        return -1;
    }

    BOOT_Printf("get sram %p %p \r\n", p_sramcfgdata, pst_factory_defaultcfgnode);

    int node_cnt0 = FCT_ListAllNode((STRU_FACTORY_SETTING *)pst_factory_defaultcfgnode, &st_node_list_default);

    //check FLASH_APB_FCT_START_ADDR_0 factory valid
    valid0 = FCT_CheckFlashSettingValid((STRU_FACTORY_SETTING *)FLASH_APB_FCT_START_ADDR_0);
    if (0 == valid0)
    {
        valid1 = FCT_CheckFlashSettingValid((STRU_FACTORY_SETTING *)FLASH_APB_FCT_START_ADDR_1);        
    }

    if (1 == valid0)
    {
        flash_factoryAddr = FLASH_APB_FCT_START_ADDR_0;
    }
    else if (1 == valid1)
    {
        flash_factoryAddr = FLASH_APB_FCT_START_ADDR_1;
    }
    else
    {
        
        BOOT_Printf("No valid flash factory setting \r\n");
        return 1;
    }

    //do replacement, list sram node, list flash node
    int node_cnt1 = FCT_ListAllNode((STRU_FACTORY_SETTING *)flash_factoryAddr,   &st_node_list_user);

    if (node_cnt0 > 0 && node_cnt1 > 0)
    {
        uint8_t i, j;
        // uint32_t flash_cfgdata = flash_factoryAddr + sizeof(STRU_cfgNode);

        for (i = 0 ; i < node_cnt0; i++)
        {
            for (j = 0 ; j < node_cnt1; j++)
            {
                STRU_cfgNode * node0 = (STRU_cfgNode *)((uint8_t *)pst_factory_defaultcfgnode + st_node_list_default.offset_to_fct_node[i]);
                STRU_cfgNode * node1 = (STRU_cfgNode *)(flash_factoryAddr + st_node_list_user.offset_to_fct_node[j]);

                if (st_node_list_default.nodeid[i] == st_node_list_user.nodeid[j])
                {
                    //do replacement, copy to sram
                    if ( node0->nodeDataSize == node1->nodeDataSize)
                    {
                        memcpy((void *)node0, (void *)node1, node0->nodeDataSize + sizeof(STRU_cfgNode));
                    }
                    else
                    {
                        BOOT_Printf("node size error %ld %ld \r\n", node0->nodeDataSize, node1->nodeDataSize);
                    }

                    break;
                }
            }
        }
    }
    
    return 1;
}


/*
 * copy factory setting to buffer
*/
int FCT_CopySetting(void *pdata, uint32_t size)
{
    uint32_t totalsize = sizeof(STRU_FACTORY_SETTING);
    if (size < totalsize)
    {
        return -1;
    }

    memcpy(pdata, (void *)pst_factory_defaultcfgnode, sizeof(STRU_FACTORY_SETTING));

    return totalsize;
}

void * FCT_GetNodeAndData(uint32_t u32_nodeId, STRU_cfgNode **pp_node)
{
    int i;

    if (pst_factory_defaultcfgnode == NULL)
    {
        void * pdata = CFGBIN_GetNodeAndData((STRU_cfgBin *)SRAM_CONFIGURE_MEMORY_ST_ADDR, FACTORY_SETTING_NODE_ID, (STRU_cfgNode **)&pst_factory_defaultcfgnode);
        if (pdata != NULL && pst_factory_defaultcfgnode != NULL)
        {
            FCT_ListAllNode((STRU_FACTORY_SETTING *)pst_factory_defaultcfgnode, &st_node_list_default);
        }
    }

    if (pst_factory_defaultcfgnode == NULL || st_node_list_default.nodecnt == 0)
    {
        BOOT_Printf("No factory node: %p %d \r\n", pst_factory_defaultcfgnode, st_node_list_default.nodecnt);
        return NULL;
    }

    for (i= 0; i < st_node_list_default.nodecnt; i++)
    {
        if (u32_nodeId == st_node_list_default.nodeid[i])
        {
            BOOT_Printf("find nod 0x%x \r\n", u32_nodeId);
            break;
        }
    }

    if (i < st_node_list_default.nodecnt)
    {
        uint8_t *pdata = (uint8_t *)pst_factory_defaultcfgnode;
        STRU_cfgNode *node = (STRU_cfgNode *)(pdata + st_node_list_default.offset_to_fct_node[i]);
        if (pp_node != NULL)
        {
            *pp_node = node;
        }

        return ((void *)(node + 1));
    }
    else
    {
        if (pp_node != NULL)
        {
            *pp_node = NULL;
        }

        return NULL;
    }
}




