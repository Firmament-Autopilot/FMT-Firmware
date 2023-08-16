#include "stm32f7xx_ll_usb.h"
#include "hal_usb_otg.h"
#include "hal_usb_device.h"
#include "hal_usb_host.h"
#include "sys_event.h"
#include "debuglog.h"


#include "usbd_def.h"
#include "usbh_def.h"

extern USBD_HandleTypeDef USBD_Device[USBD_PORT_NUM];
extern USBH_HandleTypeDef hUSBHost[USBH_PORT_NUM];

static ENUM_HAL_USB_DR_MODE HAL_INIT_USB_MODE[HAL_USB_PORT_NUM];
/**
* @brief  the callback of otg switch interrupt
* @param  void* p       param for otg switch callback
* @retval   void
* @note  
*/
static void HAL_USB_SwitchOTGCallback(void* p)
{
    STRU_SysEvent_OTG_HOST_DEV_SWITCH *stOTGHostDevSwitch;

    stOTGHostDevSwitch      = (STRU_SysEvent_OTG_HOST_DEV_SWITCH *)p;

    /* switch to host */
    if (stOTGHostDevSwitch->otg_state == 1)
    {
        DLOG_Info("switch to host");
        if(HAL_INIT_USB_MODE[(ENUM_HAL_USB_PORT)stOTGHostDevSwitch->otg_port_id] == HAL_USB_DR_MODE_OTG)
        {
            HAL_USB_InitHost((ENUM_HAL_USB_PORT)stOTGHostDevSwitch->otg_port_id,
                          HAL_USB_DR_MODE_OTG);
        }
        else
        {
            HAL_USB_InitHost((ENUM_HAL_USB_PORT)stOTGHostDevSwitch->otg_port_id,
                          HAL_USB_DR_MODE_HOST);

            HAL_INIT_USB_MODE[(ENUM_HAL_USB_PORT)stOTGHostDevSwitch->otg_port_id] = HAL_USB_DR_MODE_HOST;
        }
    }
    /* switch to device */
    else if (stOTGHostDevSwitch->otg_state == 0)
    {
        DLOG_Info("switch to device");

        if(HAL_INIT_USB_MODE[(ENUM_HAL_USB_PORT)stOTGHostDevSwitch->otg_port_id] == HAL_USB_DR_MODE_OTG)
        {
            HAL_USB_InitHost((ENUM_HAL_USB_PORT)stOTGHostDevSwitch->otg_port_id,
                          HAL_USB_DR_MODE_OTG);
        }
        else
        {
            HAL_USB_InitDevice((ENUM_HAL_USB_PORT)stOTGHostDevSwitch->otg_port_id,
                            HAL_USB_DR_MODE_DEVICE);

            HAL_INIT_USB_MODE[(ENUM_HAL_USB_PORT)stOTGHostDevSwitch->otg_port_id] = HAL_USB_DR_MODE_DEVICE;
        }
    }
    else
    {
        DLOG_Error("otg switch state error");
    }
}


/**
* @brief    initiate the USB Port
* @param  void
* @retval   void
* @note  
*/
void HAL_USB_Init(ENUM_HAL_USB_PORT e_usbPort, ENUM_HAL_USB_DR_MODE e_usbDrMode)
{
    USB_OTG_GlobalTypeDef *p_otgGlobalType[HAL_USB_PORT_NUM] = {USB_OTG0_HS, USB_OTG1_HS};

    SYS_EVENT_RegisterHandler(SYS_EVENT_ID_USB_SWITCH_HOST_DEVICE, HAL_USB_SwitchOTGCallback);

    if (e_usbPort >= HAL_USB_PORT_NUM)
    {
        DLOG_Error("invalid usb port num");

        return;
    }

    if ((e_usbDrMode == HAL_USB_DR_MODE_DEVICE)||
         ((e_usbDrMode == HAL_USB_DR_MODE_OTG)&&(USB_LL_GetCurrentOTGIDStatus(p_otgGlobalType[e_usbPort]))))
    {
        HAL_USB_InitDevice(e_usbPort, e_usbDrMode);
    }
    else
    {
        HAL_USB_InitHost(e_usbPort, e_usbDrMode);
    }

    HAL_INIT_USB_MODE[e_usbPort] = e_usbDrMode;
}

HAL_RET_T HAL_USB_SendCtrl(uint8_t *buff, uint32_t u32_len, uint8_t u8_portId)
{
    // DLOG_Info("PortId: %d", u8_portId);
    if(HAL_USB_DR_MODE_DEVICE == HAL_INIT_USB_MODE[u8_portId])
    {
        return HAL_USB_DeviceSendCtrl(buff, u32_len, u8_portId);
    }
    else if(HAL_USB_DR_MODE_HOST == HAL_INIT_USB_MODE[u8_portId])
    {
        return HAL_USB_HostSendCtrl(buff, u32_len, u8_portId);
    }
    else if(HAL_USB_DR_MODE_OTG == HAL_INIT_USB_MODE[u8_portId])
    {
        USB_OTG_GlobalTypeDef *p_otgGlobalType[HAL_USB_PORT_NUM] = {USB_OTG0_HS, USB_OTG1_HS};
        
        if(USB_LL_GetCurrentOTGIDStatus(p_otgGlobalType[u8_portId]))// device
        {
            return HAL_USB_DeviceSendCtrl(buff, u32_len, u8_portId);
        }
        else// host
        {
            return HAL_USB_HostSendCtrl(buff, u32_len, u8_portId);
        }
    }
    else// unknown type
    {
        return HAL_NOT_INITED;
    }
}

/**
* @brief    Configure the parameters optimized by IC Designer
* @param  void
* @retval   void
* @note  
*/
void HAL_USB_ConfigPHY(void)
{
    USB_LL_ConfigPhy();
}

uint8_t HAL_USB_Get_ID_State(ENUM_HAL_USB_PORT e_usbPort)
{
    USB_OTG_GlobalTypeDef *p_otgGlobalType[HAL_USB_PORT_NUM] = {USB_OTG0_HS, USB_OTG1_HS};

    return USB_LL_GetCurrentOTGIDStatus(p_otgGlobalType[e_usbPort]);
}

void HAL_USB_ConfigHighImpedance(ENUM_HAL_USB_PORT e_usbPort)
{
    USB_OTG_GlobalTypeDef *p_otgGlobalType[HAL_USB_PORT_NUM] = {USB_OTG0_HS, USB_OTG1_HS};

    USB_LL_SetHighImpedance(p_otgGlobalType[e_usbPort]);
}


ENUM_HAL_USB_DR_MODE HAL_USB_Get_USB_DR_Mode(ENUM_HAL_USB_PORT e_usbPort)
{
	return HAL_INIT_USB_MODE[e_usbPort];
}



HAL_RET_T HAL_USB_GetConnState(uint8_t u8_usbPortId)
{
    USBD_HandleTypeDef *pdev  = &USBD_Device[u8_usbPortId];
    USBH_HandleTypeDef *phost = &hUSBHost[u8_usbPortId];

    if (pdev->u8_connState && phost->device.is_connected)
    {
        DLOG_Critical("USB can't be configured to host and device simultaneously");
        return HAL_USB_ERR_PORT_INVALID;
    }

    if (pdev->u8_connState != 0 || phost->device.is_connected != 0)
        return HAL_OK;

    return HAL_USB_ERR_PORT_INVALID;
}
