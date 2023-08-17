#include "r8152.h"
#include "usbh_def.h"
#include "usbh_ctlreq.h"
#include "usbh_cdc.h"
#include "debuglog.h"
#include "drv_systick.h"
#include "memory.h"


static const struct r8152_version const r8152_versions[R8152_VERSION_NUM] = {
    { 0x4c00, RTL_VER_01, 0 },
    { 0x4c10, RTL_VER_02, 0 },
    { 0x5c00, RTL_VER_03, 1 },
    { 0x5c10, RTL_VER_04, 1 },
    { 0x5c20, RTL_VER_05, 1 },
    { 0x5c30, RTL_VER_06, 1 },
    { 0x4800, RTL_VER_07, 0 },
};


STRU_R8152_DEF  g_stR8152;


static USBH_StatusTypeDef get_registers(USBH_HandleTypeDef *phost, uint16_t value, uint16_t index, uint16_t size, void *data)
{
    USBH_StatusTypeDef   ret = USBH_BUSY;
    uint32_t             trycnt = 0;

    phost->Control.setup.b.bmRequestType    = RTL8152_REQT_READ;
    phost->Control.setup.b.bRequest         = RTL8152_REQ_GET_REGS;
    phost->Control.setup.b.wValue.w         = value;
    phost->Control.setup.b.wIndex.w         = index;
    phost->Control.setup.b.wLength.w        = size;

    while (USBH_BUSY == ret && trycnt < 1000)
    {
        ret = USBH_CtlReq(phost, (uint8_t *)data, size);
        ++trycnt;
    }

    if(trycnt >= 1000)
    {
        DLOG_Error("get reg fail");
    }

    return ret;
}


static USBH_StatusTypeDef set_registers(USBH_HandleTypeDef *phost, uint16_t value, uint16_t index, uint16_t size, void *data)
{
    USBH_StatusTypeDef   ret = USBH_BUSY;
    uint32_t             trycnt = 0;

    phost->Control.setup.b.bmRequestType    = RTL8152_REQT_WRITE;
    phost->Control.setup.b.bRequest         = RTL8152_REQ_SET_REGS;
    phost->Control.setup.b.wValue.w         = value;
    phost->Control.setup.b.wIndex.w         = index;
    phost->Control.setup.b.wLength.w        = size;

    while (USBH_BUSY == ret && trycnt < 1000)
    {
        ret = USBH_CtlReq(phost, (uint8_t *)data , size);
        ++trycnt;
    }

    if(trycnt >= 1000)
    {
        DLOG_Error("set reg fail");
    }

    return ret;
}


void generic_ocp_read(USBH_HandleTypeDef *phost, uint16_t index, uint16_t size, void *data, uint16_t type)
{
    uint16_t            burst_size = 64;
    USBH_StatusTypeDef  ret;
    int32_t             txsize;

    /* both size and index must be 4 bytes align */
    if ((size & 3) || !size || (index & 3) || !data)
    {
        DLOG_Error("invalid parm in generic_ocp_read: size: %d, index: %d, data: 0x%08x",
                    size, index, data);

        return;
    }

    if (index + size > 0xffff)
    {
        DLOG_Error("error param: index: %d, size: %d",
                    index, size);

        return;
    }

    while (size)
    {
        txsize = MIN(size, burst_size);

        ret = get_registers(phost, index, type, txsize, data);

        if (USBH_OK != ret)
        {
            DLOG_Error("get_registers fail in generic_ocp_read");

            return;
        }

        index += txsize;
        data  += txsize;
        size  -= txsize;
    }

	return;
}


void generic_ocp_write(USBH_HandleTypeDef *phost, uint16_t index, uint16_t byteen, uint16_t size, void *data, uint16_t type)
{
    USBH_StatusTypeDef  ret;
    uint16_t            byteen_start;
    uint16_t            byteen_end;
    uint16_t            byte_en_to_hw;
    uint16_t            burst_size = 512;
    int32_t             txsize;

    /* both size and index must be 4 bytes align */
    if ((size & 3) || !size || (index & 3) || !data)
    {
        DLOG_Error("invalid parm in generic_ocp_read: size: %d, index: %d, data: 0x%08x",
                    size, index, data);

        return;
    }

    if (index + size > 0xffff)
    {
        DLOG_Error("error param: index: %d, size: %d",
                    index, size);

        return;
    }

    byteen_start    = byteen & BYTE_EN_START_MASK;
    byteen_end      = byteen & BYTE_EN_END_MASK;

    byte_en_to_hw   = byteen_start | (byteen_start << 4);

    ret = set_registers(phost, index, type | byte_en_to_hw, 4, data);

    if (USBH_OK != ret)
    {
        DLOG_Error("get_registers fail in generic_ocp_write");

        return;
    }

    index   += 4;
    data    += 4;
    size    -= 4;

    if (size)
    {
        size -= 4;

        while (size)
        {
            txsize = MIN(size, burst_size);

            ret = set_registers(phost, index, type | BYTE_EN_DWORD, txsize, data);

            if (USBH_OK != ret)
            {
                DLOG_Error("set_registers fail in generic_ocp_write");
            }

            index   += txsize;
            data    += txsize;
            size    -= txsize;
        }

        byte_en_to_hw = byteen_end | (byteen_end >> 4);

        ret = set_registers(phost, index, type | byte_en_to_hw, 4, data);

        if (USBH_OK != ret)
        {
            DLOG_Error("set_registers fail in generic_ocp_write");
        }
    }
}


void pla_ocp_read(USBH_HandleTypeDef *phost, uint16_t index, uint16_t size, void *data)
{
    generic_ocp_read(phost, index, size, data, MCU_TYPE_PLA);
}


void pla_ocp_write(USBH_HandleTypeDef *phost, uint16_t index, uint16_t byteen, uint16_t size, void *data)
{
    generic_ocp_write(phost, index, byteen, size, data, MCU_TYPE_PLA);
}


void usb_ocp_read(USBH_HandleTypeDef *phost, uint16_t index, uint16_t size, void *data)
{
    generic_ocp_read(phost, index, size, data, MCU_TYPE_USB);
}


void usb_ocp_write(USBH_HandleTypeDef *phost, uint16_t index, uint16_t byteen, uint16_t size, void *data)
{
    generic_ocp_write(phost, index, byteen, size, data, MCU_TYPE_USB);
}


void ocp_read_dword(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data)
{
    generic_ocp_read(phost, index, sizeof(uint32_t), data, type);
}


void ocp_write_dword(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data)
{
    generic_ocp_write(phost, index, BYTE_EN_DWORD, sizeof(uint32_t), data, type);
}


void ocp_read_word(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data)
{
    uint8_t shift = index & 2;

    index &= ~3;

    generic_ocp_read(phost, index, sizeof(uint32_t), data, type);

    *data >>= (shift * 8);
    *data &= 0xffff;
}


void ocp_write_word(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data)
{
	uint32_t mask = 0xffff;
	uint16_t byen = BYTE_EN_WORD;
	uint8_t  shift = index & 2;

    *data &= mask;

    if (index & 2)
    {
        byen  <<= shift;
        mask  <<= (shift * 8);
        *data <<= (shift * 8);
        index  &= ~3;
    }

    generic_ocp_write(phost, index, byen, sizeof(uint32_t), data, type);
}


void ocp_read_byte(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data)
{
    uint8_t shift = index & 3;

    index &= ~3;

    generic_ocp_read(phost, index, sizeof(uint32_t), data, type);

    *data >>= (shift * 8);
    *data  &= 0xff;
}


void ocp_write_byte(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data)
{
    uint32_t            mask = 0xff;
    uint16_t            byen = BYTE_EN_BYTE;
    uint8_t             shift = index & 3;

    *data &= mask;

    if (index & 3)
    {
        byen  <<= shift;
        mask  <<= (shift * 8);
        *data <<= (shift * 8);
        index  &= ~3;
    }

    generic_ocp_write(phost, index, byen, sizeof(uint32_t), data, type);
}


void ocp_reg_read(USBH_HandleTypeDef *phost, uint16_t addr, uint32_t *data)
{
    uint16_t            ocp_index;
    uint32_t            ocp_base;

    ocp_base = addr & 0xf000;

    if (ocp_base != g_stR8152.ocp_base)
    {
        ocp_write_word(phost, MCU_TYPE_PLA, PLA_OCP_GPHY_BASE, &ocp_base);

        g_stR8152.ocp_base = ocp_base;
    }

    ocp_index = (addr & 0x0fff) | 0xb000;

    ocp_read_word(phost, MCU_TYPE_PLA, ocp_index, data);
}


void ocp_reg_write(USBH_HandleTypeDef *phost, uint16_t addr, uint32_t *data)
{
    uint16_t            ocp_index;
    uint32_t            ocp_base;

    ocp_base = addr & 0xf000;

    if (ocp_base != g_stR8152.ocp_base)
    {
        ocp_write_word(phost, MCU_TYPE_PLA, PLA_OCP_GPHY_BASE, &ocp_base);

        g_stR8152.ocp_base = ocp_base;
    }

    ocp_index = (addr & 0x0fff) | 0xb000;

    ocp_write_word(phost, MCU_TYPE_PLA, ocp_index, data);
}


static void r8152_mdio_write(USBH_HandleTypeDef *phost, uint32_t reg_addr, uint32_t *value)
{
    ocp_reg_write(phost, OCP_BASE_MII + reg_addr * 2, value);
}


static void r8152_mdio_read(USBH_HandleTypeDef *phost, uint32_t reg_addr, uint32_t *value)
{
    ocp_reg_read(phost, OCP_BASE_MII + reg_addr * 2, value);
}


USBH_StatusTypeDef r8152_wait_for_bit(USBH_HandleTypeDef *phost, uint8_t ocp_reg, uint16_t type, uint16_t index,
		       const uint32_t mask, uint8_t set, uint32_t timeout)
{
    uint32_t val;
    USBH_StatusTypeDef ret = USBH_BUSY;
    uint32_t wait_for_bit;

    while (timeout--)
    {
        if (ocp_reg)
        {
            ocp_reg_read(phost, index, &wait_for_bit);
        }
        else
        {
            ocp_read_dword(phost, type, index, &wait_for_bit);
        }

        if (!set)
        {
            wait_for_bit = ~wait_for_bit;
        }

        if ((wait_for_bit & mask) == mask)
        {
            return USBH_OK;
        }
    }

    DLOG_Error("r8152_wait_for_bit ---> timeout");

    return USBH_FAIL;
}


static void r8152b_reset_packet_filter(USBH_HandleTypeDef *phost)
{
    uint32_t reset_packet_filter;

    ocp_read_word(phost, MCU_TYPE_PLA, PLA_FMC, &reset_packet_filter);
    reset_packet_filter &= ~FMC_FCR_MCU_EN;

    ocp_write_word(phost, MCU_TYPE_PLA, PLA_FMC, &reset_packet_filter);
    reset_packet_filter |= FMC_FCR_MCU_EN;

    ocp_write_word(phost, MCU_TYPE_PLA, PLA_FMC, &reset_packet_filter);
}


static void rtl8152_wait_fifo_empty(USBH_HandleTypeDef *phost)
{
    USBH_StatusTypeDef ret;

    ret = r8152_wait_for_bit(phost, 0, MCU_TYPE_PLA, PLA_PHY_PWR, PLA_PHY_PWR_TXEMP, 1, R8152_WAIT_TIMEOUT);

    if (USBH_FAIL == ret)
    {
        DLOG_Warning("Timeout waiting for FIFO empty");

        return;
    }

    ret = r8152_wait_for_bit(phost, 0, MCU_TYPE_PLA, PLA_TCR0, TCR0_TX_EMPTY, 1, R8152_WAIT_TIMEOUT);

    if (USBH_FAIL == ret)
    {
        DLOG_Warning("Timeout waiting for TX empty");

        return;
    }
}


static void rtl8152_nic_reset(USBH_HandleTypeDef *phost)
{
    USBH_StatusTypeDef      ret;
    uint32_t                retry_count = 0;
    uint32_t                nic_reset = 0;

    nic_reset = CR_RST;

    ocp_write_byte(phost, MCU_TYPE_PLA, PLA_CR, &nic_reset);
    nic_reset |= BIST_CTRL_SW_RESET;

    ocp_read_byte(phost, MCU_TYPE_PLA, PLA_CR, &nic_reset);

    if (!(nic_reset & CR_RST))
    {
        return;
    }
    else
    {
        retry_count++;

        if (retry_count >= 20)
        {
            retry_count = 0;

            DLOG_Error("nic reset timeout");

            return;
        }
    }
}


static void rtl8152_get_speed(USBH_HandleTypeDef *phost, uint32_t *get_speed)
{
    ocp_read_byte(phost, MCU_TYPE_PLA, PLA_PHYSTATUS, get_speed);
}


static void rtl_set_eee_plus(USBH_HandleTypeDef *phost)
{
    uint32_t set_eee_plus;

    ocp_read_word(phost, MCU_TYPE_PLA, PLA_EEEP_CR, &set_eee_plus);
    set_eee_plus &= ~EEEP_CR_EEEP_TX;

    ocp_write_word(phost, MCU_TYPE_PLA, PLA_EEEP_CR, &set_eee_plus);
}


static void rxdy_gated_en(USBH_HandleTypeDef *phost, uint8_t enable)
{
    uint32_t g_rxdy_gated_en;

    ocp_read_word(phost, MCU_TYPE_PLA, PLA_MISC_1, &g_rxdy_gated_en);

    if (enable)
    {
        g_rxdy_gated_en |= RXDY_GATED_EN;
    }
    else
    {
        g_rxdy_gated_en &= ~RXDY_GATED_EN;
    }

    ocp_write_word(phost, MCU_TYPE_PLA, PLA_MISC_1, &g_rxdy_gated_en);
}


static void rtl8152_set_rx_mode(USBH_HandleTypeDef *phost)
{
    uint32_t            g_set_rx_mode;
    CDC_HandleTypeDef  *cdc_handler = (CDC_HandleTypeDef *)phost->pActiveClass->pData;

    g_set_rx_mode = 0xFFFFFFFF;
    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_MAR, &g_set_rx_mode);

    g_set_rx_mode = 0xFFFFFFFF;
    ocp_write_dword(phost, MCU_TYPE_PLA, (PLA_MAR + 4), &g_set_rx_mode);

    ocp_read_dword(phost, MCU_TYPE_PLA, PLA_RCR, &g_set_rx_mode);

    if (cdc_handler->netcard_mode)
    {
        g_set_rx_mode |= RCR_AAP | RCR_AM;
        DLOG_Error("set Promiscuous mode");
    }
    else
    {
        g_set_rx_mode |= RCR_APM | RCR_AM | RCR_AB;
    }

    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RCR, &g_set_rx_mode);
}


static void rtl_enable(USBH_HandleTypeDef *phost)
{
    uint32_t g_rtl_enable;

    uint32_t    ocp_data;

    r8152b_reset_packet_filter(phost);

    ocp_read_byte(phost, MCU_TYPE_PLA, PLA_CR, &g_rtl_enable);

    g_rtl_enable |= PLA_CR_RE | PLA_CR_TE;
    ocp_write_byte(phost, MCU_TYPE_PLA, PLA_CR, &g_rtl_enable);

    rxdy_gated_en(phost, 0);

    rtl8152_set_rx_mode(phost);
}

static void rtl8152_enable(USBH_HandleTypeDef *phost)
{
    rtl_set_eee_plus(phost);

    rtl_enable(phost);
}


static void rtl_disable(USBH_HandleTypeDef *phost)
{
    uint32_t g_rtl_disable = 0;

    ocp_read_dword(phost, MCU_TYPE_PLA, PLA_RCR, &g_rtl_disable);

    g_rtl_disable &= ~RCR_ACPT_ALL;
    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RCR, &g_rtl_disable);

    rxdy_gated_en(phost, 1);

    rtl8152_wait_fifo_empty(phost);

    rtl8152_nic_reset(phost);
}


static void r8152_power_cut_en(USBH_HandleTypeDef *phost, uint8_t enable)
{
    uint32_t power_cut_en;

    ocp_read_word(phost, MCU_TYPE_USB, USB_UPS_CTRL, &power_cut_en);

    if (enable)
    {
        power_cut_en |= POWER_CUT;
    }
    else
    {
        power_cut_en &= ~POWER_CUT;
    }

    ocp_write_word(phost, MCU_TYPE_USB, USB_UPS_CTRL, &power_cut_en);

    ocp_read_word(phost, MCU_TYPE_USB, USB_PM_CTRL_STATUS, &power_cut_en);

    power_cut_en &= ~RESUME_INDICATE;
    ocp_write_word(phost, MCU_TYPE_USB, USB_PM_CTRL_STATUS, &power_cut_en);
}


static void rtl_rx_vlan_en(USBH_HandleTypeDef *phost, uint8_t enable)
{
    uint32_t rx_vlan_en;

    ocp_read_word(phost, MCU_TYPE_PLA, PLA_CPCR, &rx_vlan_en);

    if (enable)
    {
        rx_vlan_en |= CPCR_RX_VLAN;
    }
    else
    {
        rx_vlan_en &= ~CPCR_RX_VLAN;
    }

    ocp_write_word(phost, MCU_TYPE_PLA, PLA_CPCR, &rx_vlan_en);
}


static void r8152_read_mac(USBH_HandleTypeDef *phost)
{
    CDC_HandleTypeDef *cdc_handler = (CDC_HandleTypeDef *)phost->pActiveClass->pData;

    pla_ocp_read(phost, PLA_IDR, 8, g_stR8152.mac_addr);

    memcpy(cdc_handler->enetaddr, g_stR8152.mac_addr, ETH_ALEN);
}


void r8152_set_mac(USBH_HandleTypeDef *phost, void *p)
{
    uint32_t g_write_hwaddr = CRWECR_CONFIG;
    ocp_write_byte(phost, MCU_TYPE_PLA, PLA_CRWECR, &g_write_hwaddr);
    
    pla_ocp_write(phost, PLA_IDR, BYTE_EN_SIX_BYTES, 8, p);
    
    g_write_hwaddr = CRWECR_NORAML;
    ocp_write_byte(phost, MCU_TYPE_PLA, PLA_CRWECR, &g_write_hwaddr);
}



static void r8152b_disable_aldps(USBH_HandleTypeDef *phost)
{
    uint32_t    g_aldps_config = ENPDNPS | LINKENA | DIS_SDSAVE;

    ocp_reg_write(phost, OCP_ALDPS_CONFIG, &g_aldps_config);

    /* delay 20 ms */
    ar_osDelay(20);
}


static void r8152b_enable_aldps(USBH_HandleTypeDef *phost)
{
    uint32_t    g_aldps_config = ENPWRSAVE | ENPDNPS | LINKENA | DIS_SDSAVE;

    ocp_reg_write(phost, OCP_ALDPS_CONFIG, &g_aldps_config);
}


static void rtl8152_disable(USBH_HandleTypeDef *phost)
{
    r8152b_disable_aldps(phost);

    rtl_disable(phost);

    r8152b_enable_aldps(phost);
}


static void r8152b_hw_phy_cfg(USBH_HandleTypeDef *phost)
{
    uint32_t g_hw_phy_cfg;

    r8152_mdio_read(phost, MII_BMCR, &g_hw_phy_cfg);

    if (g_hw_phy_cfg & BMCR_PDOWN)
    {
        g_hw_phy_cfg &= ~BMCR_PDOWN;
    }

    r8152_mdio_write(phost, MII_BMCR, &g_hw_phy_cfg);
}


static void rtl8152_reinit_ll(USBH_HandleTypeDef *phost)
{
    uint32_t g_reinit_ll;
    USBH_StatusTypeDef ret;

    ret = r8152_wait_for_bit(phost, 0, MCU_TYPE_PLA, PLA_PHY_PWR, PLA_PHY_PWR_LLR, 1, R8152_WAIT_TIMEOUT);
    if (ret == USBH_FAIL)
    {
        DLOG_Error("reinit ll timeout");

        return;
    }

    ocp_read_word(phost, MCU_TYPE_PLA, PLA_SFF_STS_7, &g_reinit_ll);
    g_reinit_ll |= RE_INIT_LL;
    ocp_write_word(phost, MCU_TYPE_PLA, PLA_SFF_STS_7, &g_reinit_ll);

    ret = r8152_wait_for_bit(phost, 0, MCU_TYPE_PLA, PLA_PHY_PWR, PLA_PHY_PWR_LLR, 1, R8152_WAIT_TIMEOUT);
    if (USBH_FAIL == ret)
    {
        DLOG_Error("Timeout waiting for link list ready\n");

        return;
    }
}


static void r8152b_exit_oob(USBH_HandleTypeDef *phost)
{
    uint32_t delay_count;
    uint32_t g_exit_oob;

    ocp_read_dword(phost, MCU_TYPE_PLA, PLA_RCR, &g_exit_oob);
    g_exit_oob &= ~RCR_ACPT_ALL;
    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RCR, &g_exit_oob);

    rxdy_gated_en(phost, 1);

    ocp_read_word(phost, MCU_TYPE_PLA, PLA_TEREDO_CFG, &g_exit_oob);
    g_exit_oob &= ~(TEREDO_SEL | TEREDO_RS_EVENT_MASK | OOB_TEREDO_EN);
    ocp_write_word(phost, MCU_TYPE_PLA, PLA_TEREDO_CFG, &g_exit_oob);

    g_exit_oob = WDT6_SET_MODE;
    ocp_write_word(phost, MCU_TYPE_PLA, PLA_WDT6_CTRL, &g_exit_oob);

    g_exit_oob = 0;
    ocp_write_word(phost, MCU_TYPE_PLA, PLA_REALWOW_TIMER, &g_exit_oob);

    g_exit_oob = 0;
    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_TEREDO_TIMER, &g_exit_oob);

    g_exit_oob = CRWECR_NORAML;
    ocp_write_byte(phost, MCU_TYPE_PLA, PLA_CRWECR, &g_exit_oob);

    g_exit_oob = 0x00;
    ocp_write_byte(phost, MCU_TYPE_PLA, PLA_CR, &g_exit_oob);

    ocp_read_byte(phost, MCU_TYPE_PLA, PLA_OOB_CTRL, &g_exit_oob);
    g_exit_oob &= ~NOW_IS_OOB;
    ocp_write_byte(phost, MCU_TYPE_PLA, PLA_OOB_CTRL, &g_exit_oob);

    ocp_read_word(phost, MCU_TYPE_PLA, PLA_SFF_STS_7, &g_exit_oob);
    g_exit_oob &= ~MCU_BORW_EN;

    ocp_write_word(phost, MCU_TYPE_PLA, PLA_SFF_STS_7, &g_exit_oob);

    delay_count = 0;
    while (delay_count < 2000)
    {
        ocp_read_byte(phost, MCU_TYPE_PLA, PLA_OOB_CTRL, &g_exit_oob);

        if (g_exit_oob & LINK_LIST_READY)
        {
            break;
        }

        delay_count++;
    }
    if (delay_count >= 2000)
    {
        DLOG_Error("exit oob time out");
    }

    ocp_read_word(phost, MCU_TYPE_PLA, PLA_SFF_STS_7, &g_exit_oob);
    g_exit_oob |= RE_INIT_LL;
    ocp_write_word(phost, MCU_TYPE_PLA, PLA_SFF_STS_7, &g_exit_oob);

    delay_count = 0;
    while (delay_count < 2000)
    {
        ocp_read_byte(phost, MCU_TYPE_PLA, PLA_OOB_CTRL, &g_exit_oob);

        if (g_exit_oob & LINK_LIST_READY)
        {
            break;
        }

        delay_count++;
    }
    if (delay_count >= 2000)
    {
        DLOG_Error("exit oob time out");
    }

    rtl8152_nic_reset(phost);

    g_exit_oob = RXFIFO_THR1_NORMAL;
    /* rx share fifo credit full threshold */
    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RXFIFO_CTRL0, &g_exit_oob);

    if (phost->device.speed == USB_SPEED_FULL ||
        phost->device.speed == USB_SPEED_LOW)
    {
        g_exit_oob = RXFIFO_THR2_FULL;
        ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RXFIFO_CTRL1, &g_exit_oob);

        g_exit_oob = RXFIFO_THR3_FULL;
        ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RXFIFO_CTRL2, &g_exit_oob);
    }
    else
    {
        g_exit_oob = RXFIFO_THR2_HIGH;
        ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RXFIFO_CTRL1, &g_exit_oob);

        g_exit_oob = RXFIFO_THR3_HIGH;
        ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RXFIFO_CTRL2, &g_exit_oob);
    }

    g_exit_oob = TXFIFO_THR_NORMAL;
    /* TX share fifo free credit full threshold */
    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_TXFIFO_CTRL, &g_exit_oob);

    g_exit_oob = TX_AGG_MAX_THRESHOLD;
    ocp_write_byte(phost, MCU_TYPE_USB, USB_TX_AGG, &g_exit_oob);

    g_exit_oob = RX_THR_HIGH;
    ocp_write_dword(phost, MCU_TYPE_USB, USB_RX_BUF_TH, &g_exit_oob);

    g_exit_oob = TEST_MODE_DISABLE | TX_SIZE_ADJUST1;
    ocp_write_dword(phost, MCU_TYPE_USB, USB_TX_DMA, &g_exit_oob);

    rtl_rx_vlan_en(phost, 1);

    g_exit_oob = RTL8152_RMS;
    ocp_write_word(phost, MCU_TYPE_PLA, PLA_RMS, &g_exit_oob);

    g_exit_oob = PLA_TCR0;
    ocp_read_word(phost, MCU_TYPE_PLA, PLA_TCR0, &g_exit_oob);

    g_exit_oob |= TCR0_AUTO_FIFO;
    ocp_write_word(phost, MCU_TYPE_PLA, PLA_TCR0, &g_exit_oob);
}


static void r8152b_enter_oob(USBH_HandleTypeDef *phost)
{
    uint32_t g_enter_oob;

    ocp_read_byte(phost, MCU_TYPE_PLA, PLA_OOB_CTRL, &g_enter_oob);
    g_enter_oob &= ~NOW_IS_OOB;
    ocp_write_byte(phost, MCU_TYPE_PLA, PLA_OOB_CTRL, &g_enter_oob);

    g_enter_oob = RXFIFO_THR1_OOB;
    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RXFIFO_CTRL0, &g_enter_oob);

    g_enter_oob = RXFIFO_THR2_OOB;
    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RXFIFO_CTRL1, &g_enter_oob);

    g_enter_oob = RXFIFO_THR3_OOB;
    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RXFIFO_CTRL2, &g_enter_oob);

    rtl_disable(phost);

    rtl8152_reinit_ll(phost);

    g_enter_oob = RTL8152_RMS;
    ocp_write_word(phost, MCU_TYPE_PLA, PLA_RMS, &g_enter_oob);

    rtl_rx_vlan_en(phost, 0);

    ocp_read_word(phost, MCU_TYPE_PLA, PAL_BDC_CR, &g_enter_oob);
    g_enter_oob |= ALDPS_PROXY_MODE;

    ocp_write_word(phost, MCU_TYPE_PLA, PAL_BDC_CR, &g_enter_oob);

    ocp_read_byte(phost, MCU_TYPE_PLA, PLA_OOB_CTRL, &g_enter_oob);
    g_enter_oob |= NOW_IS_OOB | DIS_MCU_CLROOB;

    ocp_write_byte(phost, MCU_TYPE_PLA, PLA_OOB_CTRL, &g_enter_oob);

    rxdy_gated_en(phost, 0);

    ocp_read_dword(phost, MCU_TYPE_PLA, PLA_RCR, &g_enter_oob);
    g_enter_oob |= RCR_APM | RCR_AM | RCR_AB;

    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_RCR, &g_enter_oob);
}


static void rtl8152_set_speed(USBH_HandleTypeDef *phost, uint8_t autoneg, uint16_t speed, uint8_t duplex)
{
    uint32_t bmcr;
    uint32_t anar;
    uint32_t gbcr;

    r8152_mdio_read(phost, MII_ADVERTISE, &anar);
    anar &= ~(ADVERTISE_10HALF | ADVERTISE_10FULL | ADVERTISE_100HALF | ADVERTISE_100FULL);

    if (g_stR8152.supports_gmii)
    {
        r8152_mdio_read(phost, MII_CTRL1000, &gbcr);
        {
            gbcr &= ~(ADVERTISE_1000FULL | ADVERTISE_1000HALF);
        }
    }
    else
    {
        gbcr = 0;
    }

    if (autoneg == AUTONEG_DISABLE)
    {
        if (speed == SPEED_10)
        {
            bmcr = 0;
            anar |= ADVERTISE_10HALF | ADVERTISE_10FULL;
        }
        else if (speed == SPEED_100)
        {
            bmcr = BMCR_SPEED100;
            anar |= ADVERTISE_100HALF | ADVERTISE_100FULL;
        }
        else if (speed == SPEED_1000 && g_stR8152.supports_gmii)
        {
            bmcr = BMCR_SPEED1000;
            gbcr |= ADVERTISE_1000FULL | ADVERTISE_1000HALF;
        }
        else
        {
            DLOG_Error("invalid speed");

            return;
        }

        if (duplex == DUPLEX_FULL)
            bmcr |= BMCR_FULLDPLX;
    }
    else
    {
        if (speed == SPEED_10)
        {
            if (duplex == DUPLEX_FULL)
                anar |= ADVERTISE_10HALF | ADVERTISE_10FULL;
            else
                anar |= ADVERTISE_10HALF;
        }
        else if (speed == SPEED_100)
        {
            if (duplex == DUPLEX_FULL)
            {
                anar |= ADVERTISE_10HALF | ADVERTISE_10FULL;
                anar |= ADVERTISE_100HALF | ADVERTISE_100FULL;
            }
            else
            {
                anar |= ADVERTISE_10HALF;
                anar |= ADVERTISE_100HALF;
            }
        }
        else if (speed == SPEED_1000 && g_stR8152.supports_gmii)
        {
            if (duplex == DUPLEX_FULL)
            {
                anar |= ADVERTISE_10HALF | ADVERTISE_10FULL;
                anar |= ADVERTISE_100HALF | ADVERTISE_100FULL;
                gbcr |= ADVERTISE_1000FULL | ADVERTISE_1000HALF;
            }
            else
            {
                anar |= ADVERTISE_10HALF;
                anar |= ADVERTISE_100HALF;
                gbcr |= ADVERTISE_1000HALF;
            }
        }
        else
        {
            DLOG_Error("invalid speed into");

            return;
        }

        bmcr = BMCR_ANENABLE | BMCR_ANRESTART;
    }

    if (g_stR8152.supports_gmii)
    {
        r8152_mdio_write(phost, MII_CTRL1000, &gbcr);
    }

    r8152_mdio_write(phost, MII_ADVERTISE, &anar);
    r8152_mdio_write(phost, MII_BMCR, &bmcr);
}


void rtl8152_up(USBH_HandleTypeDef *phost)
{
    r8152b_disable_aldps(phost);

    r8152b_exit_oob(phost);

    r8152b_enable_aldps(phost);
}


void rtl8152_down(USBH_HandleTypeDef *phost)
{
    r8152_power_cut_en(phost, 0);

    r8152b_disable_aldps(phost);

    r8152b_enter_oob(phost);

    r8152b_enable_aldps(phost);
}


static void r8152b_get_version(USBH_HandleTypeDef *phost)
{
    uint32_t    g_r8152b_get_version;
    uint16_t    tcr;
    uint8_t     i;

    ocp_read_word(phost, MCU_TYPE_PLA, PLA_TCR1, &g_r8152b_get_version);

    tcr = (uint16_t)(g_r8152b_get_version & VERSION_MASK);

    for (i = 0; i < R8152_VERSION_NUM; i++)
    {
        if (tcr == r8152_versions[i].tcr)
        {
            /* Found a supported version */
            g_stR8152.version = r8152_versions[i].version;
            g_stR8152.supports_gmii = r8152_versions[i].gmii;
            break;
        }
    }

    if (g_stR8152.version == RTL_VER_UNKNOWN)
    {
        DLOG_Error("r8152 Unknown tcr version 0x%04x\n", tcr);
    }

    rtl8152_set_speed(phost, AUTONEG_ENABLE, SPEED_100, DUPLEX_FULL);
}


static void rtl_tally_reset(USBH_HandleTypeDef *phost)
{
    uint32_t g_rtl_tally_reset;

    ocp_read_word(phost, MCU_TYPE_PLA, PLA_RSTTALLY, &g_rtl_tally_reset);

    g_rtl_tally_reset |= TALLY_RESET;

    ocp_write_word(phost, MCU_TYPE_PLA, PLA_RSTTALLY, &g_rtl_tally_reset);
}


void r8152b_init(USBH_HandleTypeDef *phost)
{
    uint32_t g_r8152b_init;

    r8152_mdio_read(phost, MII_BMCR, &g_r8152b_init);

    if (g_r8152b_init & BMCR_PDOWN)
    {
        g_r8152b_init &= ~BMCR_PDOWN;

        r8152_mdio_write(phost, MII_BMCR, &g_r8152b_init);
    }

    r8152b_disable_aldps(phost);

    r8152_power_cut_en(phost, 0);

    ocp_read_word(phost, MCU_TYPE_PLA, PLA_PHY_PWR, &g_r8152b_init);
    g_r8152b_init |= TX_10M_IDLE_EN | PFM_PWM_SWITCH;
    ocp_write_word(phost, MCU_TYPE_PLA, PLA_PHY_PWR, &g_r8152b_init);

    ocp_read_dword(phost, MCU_TYPE_PLA, PLA_MAC_PWR_CTRL, &g_r8152b_init);
    g_r8152b_init &= ~MCU_CLK_RATIO_MASK;
    g_r8152b_init |= MCU_CLK_RATIO | D3_CLK_GATED_EN;
    ocp_write_dword(phost, MCU_TYPE_PLA, PLA_MAC_PWR_CTRL, &g_r8152b_init);

    g_r8152b_init = GPHY_STS_MSK | SPEED_DOWN_MSK | SPDWN_RXDV_MSK | SPDWN_LINKCHG_MSK;
    ocp_write_word(phost, MCU_TYPE_PLA, PLA_GPHY_INTR_IMR, &g_r8152b_init);

    rtl_tally_reset(phost);

    /* disable rx aggregation */
    ocp_read_word(phost, MCU_TYPE_USB, USB_USB_CTRL, &g_r8152b_init);
    g_r8152b_init |= RX_AGG_DISABLE;
    ocp_write_word(phost, MCU_TYPE_USB, USB_USB_CTRL, &g_r8152b_init);

    /* enable rx aggregation */
    /*ocp_read_word(phost, MCU_TYPE_USB, USB_USB_CTRL, &g_r8152b_init);
    g_r8152b_init &= ~(RX_AGG_DISABLE | RX_ZERO_EN);
    ocp_write_word(phost, MCU_TYPE_USB, USB_USB_CTRL, &g_r8152b_init);*/
}


static void rtl8152_unload(USBH_HandleTypeDef *phost)
{
    r8152_power_cut_en(phost, 1);
}


static void r8152_init_common(USBH_HandleTypeDef *phost)
{
    uint32_t link_detected = 0;
    uint32_t timeout = 0;
    uint32_t g_get_speed;

    while ((!link_detected) && (timeout < PHY_CONNECT_TIMEOUT))
    {
        rtl8152_get_speed(phost, &g_get_speed);

        link_detected = g_get_speed & LINK_STATUS;
        if (!link_detected)
        {
            if (timeout == 0)
            {
                DLOG_Info("waiting for ethernet connection ...");
            }

            ar_osDelay(TIMEOUT_RESOLUTION);

            timeout += TIMEOUT_RESOLUTION;
        }
    }

    if (link_detected)
    {
        rtl8152_enable(phost);
    }
}


void r8152_init(USBH_HandleTypeDef *phost)
{
	return r8152_init_common(phost);
}


static void r8152_write_hwaddr(USBH_HandleTypeDef *phost)
{
    uint8_t             g_enetaddr[8] = {0};
    uint32_t            g_write_hwaddr;
    CDC_HandleTypeDef  *cdc_handler = (CDC_HandleTypeDef *)phost->pActiveClass->pData;

    memcpy(g_enetaddr, cdc_handler->enetaddr, ETH_ALEN);

    g_write_hwaddr = CRWECR_CONFIG;
    ocp_write_byte(phost, MCU_TYPE_PLA, PLA_CRWECR, &g_write_hwaddr);

    pla_ocp_write(phost, PLA_IDR, BYTE_EN_SIX_BYTES, 8, g_enetaddr);
    g_write_hwaddr = CRWECR_NORAML;

    ocp_write_byte(phost, MCU_TYPE_PLA, PLA_CRWECR, &g_write_hwaddr);

    DLOG_Info("MAC %pM\n", g_enetaddr);
}


/* Probe to see if a new device is actually an realtek device */
void r8152_eth_probe(USBH_HandleTypeDef *phost)
{
    r8152_read_mac(phost);

    r8152b_get_version(phost);

    r8152b_init(phost);

    r8152_buff_init();
}


uint32_t r8152_send_process(uint8_t *send_buff, uint8_t *raw_data, uint32_t data_len)
{
    uint32_t            total_len;
    R8152_TX_DESC      *pTxDesc = (R8152_TX_DESC *)send_buff;

    /* add rtl8152 header for transmit */
    pTxDesc->opts1  = data_len | TX_FS | TX_LS;
    pTxDesc->opts2  = 0;

    memcpy((void *)(send_buff + sizeof(R8152_TX_DESC)),
           (void *)raw_data,
           data_len);

    total_len = sizeof(R8152_TX_DESC) + data_len;

    return total_len;
}


uint8_t *r8152_parse_header(uint8_t *recv_buff, uint32_t *total_size, uint32_t *data_len, uint32_t *header_size)
{
    R8152_RX_DESC      *pRxDesc = NULL;
    uint8_t            *pRawDataBuff = NULL;

    *header_size        = sizeof(R8152_RX_DESC);

    pRxDesc             = (R8152_RX_DESC *)recv_buff;

    *total_size         = (pRxDesc->opts1 & 0x7FFF) + *header_size;

    if (*total_size & 0x7)
    {
        *total_size    += (8 - (*total_size & 0x7));
    }

    *data_len           = (pRxDesc->opts1 & 0x7FFF) - CRC_SIZE;

    if(pRxDesc->opts5 == 0 && pRxDesc->opts6 == 0)
    {
        pRawDataBuff        = recv_buff + *header_size;
    }
    else
    {
        DLOG_Error("Not header!");
    }

    return pRawDataBuff;
}


uint8_t *r8152_parse_header_no_agg(uint8_t *recv_buff, uint32_t *total_size, uint32_t *data_len, uint32_t *header_size)
{
    R8152_RX_DESC      *pRxDesc = NULL;
    uint8_t            *pRawDataBuff = NULL;

    *header_size        = sizeof(R8152_RX_DESC);

    pRxDesc             = (R8152_RX_DESC *)recv_buff;

    *total_size         = (pRxDesc->opts1 & 0x7FFF) + *header_size;

    *data_len           = (pRxDesc->opts1 & 0x7FFF) - CRC_SIZE;

    if(pRxDesc->opts5 == 0 && pRxDesc->opts6 == 0)
    {
        pRawDataBuff        = recv_buff + *header_size;
    }
    else
    {
        DLOG_Error("Not header!");
    }

    return pRawDataBuff;
}



uint8_t *r8152_get_rx_buff(void)
{
    return g_stR8152.net_recv_buf;
}


uint8_t *r8152_get_tx_buff(void)
{
    return g_stR8152.net_send_buff;
}


void r8152_buff_init(void)
{
    if(NULL == g_stR8152.net_recv_buf)
    {
        g_stR8152.net_recv_buf  = (uint8_t *)rt_malloc(RTL8152_AGG_BUF_SZ);
    }

    if(NULL == g_stR8152.net_send_buff)
    {
        g_stR8152.net_send_buff = (uint8_t *)rt_malloc(PKTSIZE_ALIGN);
    }
}

