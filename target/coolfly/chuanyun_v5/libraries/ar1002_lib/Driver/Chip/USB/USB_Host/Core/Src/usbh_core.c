/**
  ******************************************************************************
  * @file    usbh_core.c 
  * @author  MCD Application Team
  * @version V3.2.2
  * @date    07-July-2015
  * @brief   This file implements the functions for the core state machine process
  *          the enumeration and the control transfer process
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 
/* Includes ------------------------------------------------------------------*/

#include "usbh_core.h"
#include "debuglog.h"
#include "drv_systick.h"
#include "hal_usb_otg.h"
#include "sys_event.h"
// #include "cmsis_os.h"

#define USB_HUB_BASE_CLASS       0x09

uint8_t usb_dev_info[0x100] = {0};
/** @addtogroup USBH_LIB
  * @{
  */

/** @addtogroup USBH_LIB_CORE
  * @{
  */

/** @defgroup USBH_CORE 
  * @brief This file handles the basic enumeration when a device is connected 
  *          to the host.
  * @{
  */ 


/** @defgroup USBH_CORE_Private_Defines
  * @{
  */ 
#define USBH_ADDRESS_DEFAULT                     0
#define USBH_ADDRESS_ASSIGNED                    1      
#define USBH_MPS_DEFAULT                         0x40
/**
  * @}
  */ 

/** @defgroup USBH_CORE_Private_Macros
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup USBH_CORE_Private_Variables
  * @{
  */ 
/**
  * @}
  */ 
 

/** @defgroup USBH_CORE_Private_Functions
  * @{
  */ 
static USBH_StatusTypeDef  USBH_HandleEnum    (USBH_HandleTypeDef *phost);
static void                USBH_HandleSof     (USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef  DeInitStateMachine(USBH_HandleTypeDef *phost);
static void USBH_NotifyErrMsg(ENUM_USBH_ERR_MSG_TYPE err_type);

#if (USBH_USE_OS == 1)  
static void USBH_Process_OS(void const * argument);
#endif

void USBH_NotifyErrMsg(ENUM_USBH_ERR_MSG_TYPE err_type)
{
    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USB_HOST_ERR_MSG, (void *)&err_type);
}

/**
  * @brief  HCD_Init 
  *         Initialize the HOST Core.
  * @param  phost: Host Handle
  * @param  pUsrFunc: User Callback
  * @retval USBH Status
  */
USBH_StatusTypeDef  USBH_Init(USBH_HandleTypeDef *phost, void (*pUsrFunc)(USBH_HandleTypeDef *phost, uint8_t ), uint8_t id)
{
  /* Check whether the USB Host handle is valid */
  if(phost == NULL)
  {
    DLOG_Error("Invalid Host handle\n");
    return USBH_FAIL; 
  }
  
  /* Set DRiver ID */
  phost->id = id;
  
  /* Unlink class*/
  phost->pActiveClass = NULL;
  phost->ClassNumber = 0;
  
  /* Restore default states and prepare EP0 */ 
  DeInitStateMachine(phost);
  
  /* Assign User process */
  if(pUsrFunc != NULL)
  {
    phost->pUser = pUsrFunc;
  }
  
#if (USBH_USE_OS == 1) 
  
  /* Create USB Host Queue */
  osMessageQDef(USBH_Queue, 10, uint16_t);
  phost->os_event = osMessageCreate (osMessageQ(USBH_Queue), NULL); 
  
  /*Create USB Host Task */
#if defined (USBH_PROCESS_STACK_SIZE)
  osThreadDef(USBH_Thread, USBH_Process_OS, USBH_PROCESS_PRIO, 0, USBH_PROCESS_STACK_SIZE);
#else
  osThreadDef(USBH_Thread, USBH_Process_OS, USBH_PROCESS_PRIO, 0, 8 * configMINIMAL_STACK_SIZE);
#endif  
  phost->thread = osThreadCreate (osThread(USBH_Thread), phost);
#endif  
  
  /* Initialize low level driver */
  USBH_LL_Init(phost);

  g_ll_usbCurrentMode[id] = 1;
  return USBH_OK;
}

/**
  * @brief  HCD_Init 
  *         De-Initialize the Host portion of the driver.
  * @param  phost: Host Handle
  * @retval USBH Status
  */
USBH_StatusTypeDef  USBH_DeInit(USBH_HandleTypeDef *phost)
{
  DeInitStateMachine(phost);
  
  if(phost->pData != NULL)
  {
    phost->pActiveClass->pData = NULL;
    USBH_LL_Stop(phost);
  }

  return USBH_OK;
}

/**
  * @brief  DeInitStateMachine 
  *         De-Initialize the Host state machine.
  * @param  phost: Host Handle
  * @retval USBH Status
  */
static USBH_StatusTypeDef  DeInitStateMachine(USBH_HandleTypeDef *phost)
{
  uint32_t i = 0;

  /* Clear Pipes flags*/
  for ( ; i < USBH_MAX_PIPES_NBR; i++)
  {
    phost->Pipes[i] = 0;
  }
  
  for(i = 0; i< USBH_MAX_DATA_BUFFER; i++)
  {
    phost->device.Data[i] = 0;
  }
  
  phost->gState = HOST_IDLE;
  phost->EnumState = ENUM_IDLE;
  phost->RequestState = CMD_SEND;
  phost->Timer = 0;  
  
  phost->Control.state = CTRL_SETUP;
  phost->Control.pipe_size = USBH_MPS_DEFAULT;  
  phost->Control.errorcount = 0;
  
  phost->device.address = USBH_ADDRESS_DEFAULT;
  phost->device.speed   = USBH_SPEED_FULL;
  
  return USBH_OK;
}

/**
  * @brief  USBH_RegisterClass 
  *         Link class driver to Host Core.
  * @param  phost : Host Handle
  * @param  pclass: Class handle
  * @retval USBH Status
  */
USBH_StatusTypeDef  USBH_RegisterClass(USBH_HandleTypeDef *phost, USBH_ClassTypeDef *pclass)
{
  USBH_StatusTypeDef   status = USBH_OK;
  
  if(pclass != 0)
  {
    if(phost->ClassNumber < USBH_MAX_NUM_SUPPORTED_CLASS)
    {
      /* link the class to the USB Host handle */
      phost->pClass[phost->ClassNumber++] = pclass;
      status = USBH_OK;
    }
    else
    {
      DLOG_Error("Max Class Number reached\n");
      status = USBH_FAIL; 
    }
  }
  else
  {
    DLOG_Error("Invalid Class handle\n");
    status = USBH_FAIL; 
  }
  
  return status;
}

/**
  * @brief  USBH_SelectInterface 
  *         Select current interface.
  * @param  phost: Host Handle
  * @param  interface: Interface number
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_SelectInterface(USBH_HandleTypeDef *phost, uint8_t interface)
{
  USBH_StatusTypeDef   status = USBH_OK;
  
  if(interface < phost->device.CfgDesc.bNumInterfaces)
  {
    phost->device.current_interface = interface;
    DLOG_Info("Switching to Interface (#%d)", interface);
    DLOG_Info("Class    : %xh", phost->device.CfgDesc.Itf_Desc[interface].bInterfaceClass );
    DLOG_Info("SubClass : %xh", phost->device.CfgDesc.Itf_Desc[interface].bInterfaceSubClass );
    DLOG_Info("Protocol : %xh", phost->device.CfgDesc.Itf_Desc[interface].bInterfaceProtocol );                 
  }
  else
  {
    DLOG_Error("Cannot Select This Interface.\n");
    status = USBH_FAIL; 
  }
  return status;  
}

/**
  * @brief  USBH_GetActiveClass 
  *         Return Device Class.
  * @param  phost: Host Handle
  * @param  interface: Interface index
  * @retval Class Code
  */
uint8_t USBH_GetActiveClass(USBH_HandleTypeDef *phost)
{
   return (phost->device.CfgDesc.Itf_Desc[0].bInterfaceClass);            
}
/**
  * @brief  USBH_FindInterface 
  *         Find the interface index for a specific class.
  * @param  phost: Host Handle
  * @param  Class: Class code
  * @param  SubClass: SubClass code
  * @param  Protocol: Protocol code
  * @retval interface index in the configuration structure
  * @note : (1)interface index 0xFF means interface index not found
  */
uint8_t  USBH_FindInterface(USBH_HandleTypeDef *phost, uint8_t Class, uint8_t SubClass, uint8_t Protocol)
{
  USBH_InterfaceDescTypeDef    *pif ;
  USBH_CfgDescTypeDef          *pcfg ;
  int8_t                        if_ix = 0;
  
  pif = (USBH_InterfaceDescTypeDef *)0;
  pcfg = &phost->device.CfgDesc;  
 
  DLOG_Critical("%d, %d, %d, %d, %d, %d, %d, %d",
	pcfg->bLength,
  	pcfg->bDescriptorType,
  	pcfg->wTotalLength,
  	pcfg->bNumInterfaces,
  	pcfg->bConfigurationValue,
  	pcfg->iConfiguration,
  	pcfg->bmAttributes,
  	pcfg->bMaxPower);

  while (if_ix < USBH_MAX_NUM_INTERFACES)
  {
    pif = &pcfg->Itf_Desc[if_ix];

    DLOG_Critical("%d, %d, %d, %d, %d, %d, %d, %d, %d",
				pif->bLength,
				pif->bDescriptorType,
				pif->bInterfaceNumber,
				pif->bAlternateSetting,
				pif->bNumEndpoints,
				pif->bInterfaceClass,
				pif->bInterfaceSubClass,
				pif->bInterfaceProtocol,
				pif->iInterface);

    DLOG_Critical("%d, %d, %d, %d, %d, %d",
		pif->Ep_Desc[0].bLength,
		pif->Ep_Desc[0].bDescriptorType,
		pif->Ep_Desc[0].bEndpointAddress,
		pif->Ep_Desc[0].bmAttributes,
		pif->Ep_Desc[0].wMaxPacketSize,
		pif->Ep_Desc[0].bInterval);

    DLOG_Critical("%d, %d, %d, %d, %d, %d",
		pif->Ep_Desc[1].bLength,
		pif->Ep_Desc[1].bDescriptorType,
		pif->Ep_Desc[1].bEndpointAddress,
		pif->Ep_Desc[1].bmAttributes,
		pif->Ep_Desc[1].wMaxPacketSize,
		pif->Ep_Desc[1].bInterval);

    DLOG_Critical("%d, %d, %d, %d, %d, %d",
		pif->Ep_Desc[2].bLength,
		pif->Ep_Desc[2].bDescriptorType,
		pif->Ep_Desc[2].bEndpointAddress,
		pif->Ep_Desc[2].bmAttributes,
		pif->Ep_Desc[2].wMaxPacketSize,
		pif->Ep_Desc[2].bInterval);

    if(((pif->bInterfaceClass == Class) || (Class == 0xFF))&&
       ((pif->bInterfaceSubClass == SubClass) || (SubClass == 0xFF))&&
         ((pif->bInterfaceProtocol == Protocol) || (Protocol == 0xFF)))
    {
      return  if_ix;
    }
    if_ix++;
  }
  return 0xFF;
}

/**
  * @brief  USBH_FindInterfaceIndex 
  *         Find the interface index for a specific class interface and alternate setting number.
  * @param  phost: Host Handle
  * @param  interface_number: interface number
  * @param  alt_settings    : alternate setting number
  * @retval interface index in the configuration structure
  * @note : (1)interface index 0xFF means interface index not found
  */
uint8_t  USBH_FindInterfaceIndex(USBH_HandleTypeDef *phost, uint8_t interface_number, uint8_t alt_settings)
{
  USBH_InterfaceDescTypeDef    *pif ;
  USBH_CfgDescTypeDef          *pcfg ;
  int8_t                        if_ix = 0;
  
  pif = (USBH_InterfaceDescTypeDef *)0;
  pcfg = &phost->device.CfgDesc;  
  
  while (if_ix < USBH_MAX_NUM_INTERFACES)
  {
    pif = &pcfg->Itf_Desc[if_ix];
    if((pif->bInterfaceNumber == interface_number) && (pif->bAlternateSetting == alt_settings))
    {
      return  if_ix;
    }
    if_ix++;
  }
  return 0xFF;
}

/**
  * @brief  USBH_Start 
  *         Start the USB Host Core.
  * @param  phost: Host Handle
  * @retval USBH Status
  */
USBH_StatusTypeDef  USBH_Start  (USBH_HandleTypeDef *phost)
{
  /* Start the low level driver  */
  USBH_LL_Start(phost);
  
  /* Activate VBUS on the port */ 
  //USBH_LL_DriverVBUS (phost, TRUE);
  
  return USBH_OK;  
}

/**
  * @brief  USBH_Stop 
  *         Stop the USB Host Core.
  * @param  phost: Host Handle
  * @retval USBH Status
  */
USBH_StatusTypeDef  USBH_Stop   (USBH_HandleTypeDef *phost)
{
  /* Stop and cleanup the low level driver  */
  USBH_LL_Stop(phost);  
  
  /* DeActivate VBUS on the port */ 
  //USBH_LL_DriverVBUS (phost, FALSE);
  
  /* FRee Control Pipes */
  USBH_FreePipe  (phost, phost->Control.pipe_in);
  USBH_FreePipe  (phost, phost->Control.pipe_out);  
  
  return USBH_OK;  
}

/**
  * @brief  HCD_ReEnumerate 
  *         Perform a new Enumeration phase.
  * @param  phost: Host Handle
  * @retval USBH Status
  */
USBH_StatusTypeDef  USBH_ReEnumerate   (USBH_HandleTypeDef *phost)
{
  /*Stop Host */ 
  USBH_Stop(phost);

  /*Device has disconnected, so wait for 200 ms */  
  USBH_Delay(200);
  
  /* Set State machines in default state */
  DeInitStateMachine(phost);
   
  /* Start again the host */
  USBH_Start(phost);

  USBH_LL_NotifyUSBHStateChange(phost);
#if (USBH_USE_OS == 1)
      osMessagePut ( phost->os_event, USBH_PORT_EVENT, 0);
#endif  
  return USBH_OK;  
}

/**
  * @brief  USBH_Process 
  *         Background process of the USB Core.
  * @param  phost: Host Handle
  * @retval USBH Status
  */
USBH_StatusTypeDef  status_last = HOST_IDLE;
uint8_t             fail_count = 0;
USBH_StatusTypeDef  USBH_Process(USBH_HandleTypeDef *phost)
{
  __IO USBH_StatusTypeDef status = USBH_FAIL;
  uint8_t idx = 0;

  ((USB_OTG_GlobalTypeDef *)((HCD_HandleTypeDef *)(phost->pData))->Instance)->GINTMSK &= ~USB_OTG_GINTSTS_HPRTINT;
  ((USB_OTG_GlobalTypeDef *)((HCD_HandleTypeDef *)(phost->pData))->Instance)->GINTMSK &= ~USB_OTG_GINTSTS_DISCINT;

  switch (phost->gState)
  {
  case HOST_IDLE :
    
    if (phost->device.is_connected)  
    {
      /* Wait for 200 ms after connection */
      phost->gState = HOST_DEV_WAIT_FOR_ATTACHMENT; 
      USBH_Delay(200); 
      USBH_LL_ResetPort(phost);

      USBH_LL_NotifyUSBHStateChange(phost);

      fail_count = 0;

#if (USBH_USE_OS == 1)
      osMessagePut ( phost->os_event, USBH_PORT_EVENT, 0);
#endif
    }
    else
    {
        USBH_Delay(1);
    }
    break;
    
  case HOST_DEV_WAIT_FOR_ATTACHMENT:
    break;    
    
  case HOST_DEV_ATTACHED :
    
    DLOG_Info("USB Device Attached\n");
    /* Wait for 100 ms after Reset */
    USBH_Delay(100); 
          
    phost->device.speed = USBH_LL_GetSpeed(phost);
    
    phost->gState = HOST_ENUMERATION;
    
    phost->Control.pipe_out = USBH_AllocPipe (phost, 0x00);
    phost->Control.pipe_in  = USBH_AllocPipe (phost, 0x80);    
    
    
    /* Open Control pipes */
    USBH_OpenPipe (phost,
                   phost->Control.pipe_in,
                   0x80,
                   phost->device.address,
                   phost->device.speed,
                   USBH_EP_CONTROL,
                   phost->Control.pipe_size); 
    
    /* Open Control pipes */
    USBH_OpenPipe (phost,
                   phost->Control.pipe_out,
                   0x00,
                   phost->device.address,
                   phost->device.speed,
                   USBH_EP_CONTROL,
                   phost->Control.pipe_size);
    
    USBH_LL_NotifyUSBHStateChange(phost);
#if (USBH_USE_OS == 1)
    osMessagePut ( phost->os_event, USBH_PORT_EVENT, 0);
#endif    
    
    break;
    
  case HOST_ENUMERATION:     
    /* Check for enumeration status */  
    if ((status = USBH_HandleEnum(phost)) == USBH_OK)
    { 
      /* The function shall return USBH_OK when full enumeration is complete */
      DLOG_Info("Enumeration done.\n");
      phost->device.current_interface = 0;
      if(phost->device.DevDesc.bNumConfigurations == 1)
      {
        DLOG_Info("This device has only 1 configuration.\n");
        phost->gState  = HOST_SET_CONFIGURATION;        
        
      }
      else
      {
        phost->gState  = HOST_INPUT; 
      }
    }
    else if(USBH_FAIL == status)
    {
        DLOG_Error("ENUMERATION failed!");
        USBH_ReEnumerate(phost);
    }
    break;

  case HOST_INPUT:
    {
      /* user callback for end of device basic enumeration */
      if(phost->pUser != NULL)
      {
        phost->pUser(phost, HOST_USER_SELECT_CONFIGURATION);
        phost->gState = HOST_SET_CONFIGURATION;
        
        USBH_LL_NotifyUSBHStateChange(phost);
#if (USBH_USE_OS == 1)
        osMessagePut ( phost->os_event, USBH_STATE_CHANGED_EVENT, 0);
#endif         
      }
    }
    break;
    
  case HOST_SET_CONFIGURATION:
    /* set configuration */
    if ((status = USBH_SetCfg(phost, phost->device.CfgDesc.bConfigurationValue)) == USBH_OK)
    {
      phost->gState  = HOST_CHECK_CLASS;
      DLOG_Info("Default configuration set.");
      //fail_count = 0;
    }
    else if(USBH_NOT_SUPPORTED == status)
    {
        DLOG_Error("SET_CONFIGURATION failed!");
        USBH_LL_Disconnect(phost);

        USBH_NotifyErrMsg(ENUM_USB_DEVICE_UN_SUPPORTED);
        /*if(++fail_count > 10)
        {
            USBH_LL_Disconnect(phost);
            fail_count = 0;
        }*/
    }

    break;

  case HOST_CHECK_CLASS:
    
    if(phost->ClassNumber == 0)
    {
      DLOG_Error("No Class has been registered.");
    }
    else
    {
      phost->pActiveClass = NULL;

      //For SAMSUNG S7 Mobile
      if (phost->device.DevDesc.idProduct == 0x685d)
            phost->device.CfgDesc.Itf_Desc[0].bInterfaceClass = 0xFF;

      for (idx = 0; idx < USBH_MAX_NUM_SUPPORTED_CLASS ; idx ++)
      {
        if(phost->pClass[idx]->ClassCode == phost->device.CfgDesc.Itf_Desc[0].bInterfaceClass)
        {
          phost->pActiveClass = phost->pClass[idx];

          /* Inform user that a class has been activated */
          phost->pUser(phost, HOST_USER_CLASS_SELECTED);
        }
      }

      if (phost->device.CfgDesc.Itf_Desc[0].bInterfaceClass == 0xFF)
      {
          if(phost->device.DevDesc.idProduct == 0x8152)
          {
              phost->pActiveClass = phost->pClass[2]; // Only USB Net Adapter Class
          }
          else
          {
              phost->pActiveClass = phost->pClass[USBH_MAX_NUM_SUPPORTED_CLASS - 1]; // MTP
          }
      }

      if(phost->pActiveClass != NULL)
      {
        if(phost->pActiveClass->Init(phost)== USBH_OK)
        {
          phost->gState  = HOST_CLASS_REQUEST;
          DLOG_Info("%s class started.\n", phost->pActiveClass->Name);
          phost->timeout_count = 0;
          phost->ClassRequestState = 0;
        }
        else
        {
          phost->gState  = HOST_ABORT_STATE;
          DLOG_Error("Device not supporting %s class.\n", phost->pActiveClass->Name);

          USBH_NotifyErrMsg(ENUM_USB_DEVICE_UN_SUPPORTED);
        }
      }
      else
      {
        phost->gState  = HOST_ABORT_STATE;
        DLOG_Error("No registered class for this device.\n");
        if(phost->device.CfgDesc.Itf_Desc[0].bInterfaceClass == USB_HUB_BASE_CLASS) {
            DLOG_Critical("USB HUB Base Class");
            USBH_NotifyErrMsg(ENUM_USB_HUB_UN_SUPPORTED);
        } else{
            USBH_NotifyErrMsg(ENUM_USB_DEVICE_UN_SUPPORTED);
        }
      }
    }
    
    USBH_LL_NotifyUSBHStateChange(phost);
#if (USBH_USE_OS == 1)
    osMessagePut ( phost->os_event, USBH_STATE_CHANGED_EVENT, 0);
#endif 
    break;    
    
  case HOST_CLASS_REQUEST:  
    /* process class standard control requests state machine */
    if(phost->pActiveClass != NULL)
    {
      status = phost->pActiveClass->Requests(phost);
      
      if(status == USBH_OK)
      {
        phost->gState  = HOST_CLASS;
        fail_count = 0;
      }
      else if(status == USBH_BUSY)
      {
        
      }
      else if(status == USBH_FAIL)
      {
        DLOG_Error("Class Requests failed!");

        if(++fail_count > 10)
        {
            USBH_LL_Disconnect(phost);
            fail_count = 0;
        }
      }
      else if(status == USBH_NOT_SUPPORTED)
      {
        USBH_NotifyErrMsg(ENUM_USB_DEVICE_UN_SUPPORTED);

        //Solve sometime interrupt not detected in HAL_PCD_IRQHandler
        DLOG_Error("Class Requests USBH_NOT_SUPPORTED!");
        HCD_HandleTypeDef *hhcd = (HCD_HandleTypeDef *)(phost->pData);
        USB_OTG_GlobalTypeDef *USBx = hhcd->Instance;
        USBx_HPRT0 &= ~(USB_OTG_HPRT_PENA | USB_OTG_HPRT_PCDET | USB_OTG_HPRT_PENCHNG | USB_OTG_HPRT_POCCHNG);
        USBH_LL_Disconnect(phost);
        fail_count = 0;
      }
    }
    else
    {
      phost->gState  = HOST_ABORT_STATE;
      DLOG_Info("Invalid Class Driver.\n");
    
    USBH_LL_NotifyUSBHStateChange(phost);
#if (USBH_USE_OS == 1)
    osMessagePut ( phost->os_event, USBH_STATE_CHANGED_EVENT, 0);
#endif       
    }
    
    break;    
  case HOST_CLASS:   
    /* process class state machine */
    if(phost->pActiveClass != NULL)
    { 
      phost->pActiveClass->BgndProcess(phost);
    }
    else if(HOST_CLASS == status_last)
    {
        USBH_LL_Disconnect(phost);
    }
    break;       

  case HOST_DEV_DISCONNECTED :
    
    DeInitStateMachine(phost);  
    
    /* Re-Initilaize Host for new Enumeration */
    if(phost->pActiveClass != NULL)
    {
      phost->pActiveClass->DeInit(phost); 
      phost->pActiveClass = NULL;
    }     
    USBH_Delay(10);

    if (HOST_CLASS_REQUEST != status_last && \
        SysTicks_GetDiff(phost->connect_tick, SysTicks_GetTickCount()) > 1000)
    {
        DLOG_Info("Normal disconnect");
        USBH_LL_Init(phost);
    }

    /* Start the low level driver  */
    USBH_LL_Start(phost);
    break;
    
  case HOST_ABORT_STATE:
  default :
    break;
  }

  status_last = phost->gState;
  
  //__HAL_HCD_CLEAR_FLAG((HCD_HandleTypeDef *)(phost->pData), USB_OTG_GINTSTS_DISCINT);
  ((USB_OTG_GlobalTypeDef *)((HCD_HandleTypeDef *)(phost->pData))->Instance)->GINTMSK |= USB_OTG_GINTSTS_DISCINT;
  ((USB_OTG_GlobalTypeDef *)((HCD_HandleTypeDef *)(phost->pData))->Instance)->GINTMSK |= USB_OTG_GINTSTS_HPRTINT;

 return USBH_OK;  
}


/**
  * @brief  USBH_HandleEnum 
  *         This function includes the complete enumeration process
  * @param  phost: Host Handle
  * @retval USBH_Status
  */
static USBH_StatusTypeDef USBH_HandleEnum (USBH_HandleTypeDef *phost)
{
  USBH_StatusTypeDef Status = USBH_BUSY; 
  USBH_StatusTypeDef tmp_status = USBH_BUSY; 

  switch (phost->EnumState)
  {
  case ENUM_IDLE:  
    /* Get Device Desc for only 1st 8 bytes : To get EP0 MaxPacketSize */
    DLOG_Info("Get Device Desc\n");
    
    if ((tmp_status = USBH_Get_DevDesc(phost, 8)) == USBH_OK)
    {
      DLOG_Info("Get Device Desc finish\n");
        
      phost->Control.pipe_size = phost->device.DevDesc.bMaxPacketSize;

      phost->EnumState = ENUM_GET_FULL_DEV_DESC;
      
      /* modify control channels configuration for MaxPacket size */
      USBH_OpenPipe (phost,
                           phost->Control.pipe_in,
                           0x80,
                           phost->device.address,
                           phost->device.speed,
                           USBH_EP_CONTROL,
                           phost->Control.pipe_size); 
      
      /* Open Control pipes */
      USBH_OpenPipe (phost,
                           phost->Control.pipe_out,
                           0x00,
                           phost->device.address,
                           phost->device.speed,
                           USBH_EP_CONTROL,
                           phost->Control.pipe_size);           
      
    }
    else if(USBH_FAIL == tmp_status || USBH_NOT_SUPPORTED == tmp_status)
    {
        Status = USBH_FAIL;
        USBH_LL_NotifyUSBHStateChange(phost);
    }
    break;
    
  case ENUM_GET_FULL_DEV_DESC:  
    /* Get FULL Device Desc  */
    if ((tmp_status = USBH_Get_DevDesc(phost, USB_DEVICE_DESC_SIZE)) == USBH_OK)
    {
      DLOG_Info("PID: %xh\n", phost->device.DevDesc.idProduct );  
      DLOG_Info("VID: %xh\n", phost->device.DevDesc.idVendor );  

      //USB Authentication: MQP Device (VID: 0x1A0A PID: 0x0201) should be informed 'Not Support'
      if ((phost->device.DevDesc.idVendor == 0x1A0A) && (phost->device.DevDesc.idProduct == 0x0201)) {
        USBH_NotifyErrMsg(ENUM_USB_DEVICE_UN_SUPPORTED);
      }

      phost->EnumState = ENUM_SET_ADDR;
    }
    else if(USBH_FAIL == tmp_status || USBH_NOT_SUPPORTED == tmp_status)
    {
        Status = USBH_FAIL;
        USBH_LL_NotifyUSBHStateChange(phost);

        USBH_NotifyErrMsg(ENUM_USB_DEVICE_UN_SUPPORTED);
    }
    break;
   
  case ENUM_SET_ADDR: 
    /* set address */
    if ((tmp_status = USBH_SetAddress(phost, USBH_DEVICE_ADDRESS)) == USBH_OK)
    {
      USBH_Delay(2);
      phost->device.address = USBH_DEVICE_ADDRESS;
      
      /* user callback for device address assigned */
      DLOG_Info("Address (#%d) assigned.\n", phost->device.address);
      phost->EnumState = ENUM_GET_CFG_DESC;
      
      /* modify control channels to update device address */
      USBH_OpenPipe (phost,
                           phost->Control.pipe_in,
                           0x80,
                           phost->device.address,
                           phost->device.speed,
                           USBH_EP_CONTROL,
                           phost->Control.pipe_size); 
      
      /* Open Control pipes */
      USBH_OpenPipe (phost,
                           phost->Control.pipe_out,
                           0x00,
                           phost->device.address,
                           phost->device.speed,
                           USBH_EP_CONTROL,
                           phost->Control.pipe_size);        
    }
    else if(USBH_FAIL == tmp_status)
    {
        Status = USBH_FAIL;
        USBH_LL_NotifyUSBHStateChange(phost);
    }
    break;
    
  case ENUM_GET_CFG_DESC:  
    /* get standard configuration descriptor */
    if ((tmp_status = USBH_Get_CfgDesc(phost, 
                          USB_CONFIGURATION_DESC_SIZE)) == USBH_OK)
    {
      phost->EnumState = ENUM_GET_FULL_CFG_DESC;        
    }
    else if(USBH_FAIL == tmp_status)
    {
        Status = USBH_FAIL;
        USBH_LL_NotifyUSBHStateChange(phost);
    }
    break;
    
  case ENUM_GET_FULL_CFG_DESC:  
    /* get FULL config descriptor (config, interface, endpoints) */
    if ((tmp_status = USBH_Get_CfgDesc(phost, 
                         phost->device.CfgDesc.wTotalLength)) == USBH_OK)
    {
      phost->EnumState = ENUM_GET_MFC_STRING_DESC;       
    }
    else if(USBH_FAIL == tmp_status)
    {
        Status = USBH_FAIL;
        USBH_LL_NotifyUSBHStateChange(phost);
    }
    break;
    
  case ENUM_GET_MFC_STRING_DESC:  
    if (phost->device.DevDesc.iManufacturer != 0)
    { /* Check that Manufacturer String is available */
      
      if ((tmp_status = USBH_Get_StringDesc(phost,
                               phost->device.DevDesc.iManufacturer, 
                                phost->device.Data , 
                               0xff)) == USBH_OK)
      {
        /* User callback for Manufacturing string */
        DLOG_Critical("Manufacturer : %s, len is: %d",  (char *)phost->device.Data, strlen(phost->device.Data));
        phost->EnumState = ENUM_GET_PRODUCT_STRING_DESC;
        if (phost->device.Data != NULL)
        {
            memset(usb_dev_info, 0x00, sizeof(usb_dev_info));
            memcpy(usb_dev_info, phost->device.Data, strlen(phost->device.Data));

#ifdef C201S_ZZ
            ENUM_USB_OTG_IDTENTITY usb_type;
            if ((usb_dev_info != NULL) && (strlen(usb_dev_info) >= 10))
            {
                if (strncmp(usb_dev_info, "Apple Inc.", 10) == 0)
                {
                    usb_type = ENUM_USB_APPLE_DEVICE;
                    DLOG_Critical("Notify to App that it is a Apple Device.");
                    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USB_DEVICE_IDENTITY, (void *)&usb_type);
                }
                else
                {
                    usb_type = ENUM_USB_ANDROID_DEVICE;
                    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USB_DEVICE_IDENTITY, (void *)&usb_type);
                    DLOG_Critical("Notify to App that it is a Android Device.");
                }
            }
            else
            {
                usb_type = ENUM_USB_ANDROID_DEVICE;
                SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USB_DEVICE_IDENTITY, (void *)&usb_type);
                DLOG_Critical("Notify to App that it is a Android Device.");
            }
#endif
        }
        
        USBH_LL_NotifyUSBHStateChange(phost);
#if (USBH_USE_OS == 1)
    osMessagePut ( phost->os_event, USBH_STATE_CHANGED_EVENT, 0);
#endif          
      }
      else if(USBH_FAIL == tmp_status)
      {
          Status = USBH_FAIL;
          USBH_LL_NotifyUSBHStateChange(phost);
      }
    }
    else
    {
     DLOG_Info("Manufacturer : N/A");      
     phost->EnumState = ENUM_GET_PRODUCT_STRING_DESC; 
     
     USBH_LL_NotifyUSBHStateChange(phost);
#if (USBH_USE_OS == 1)
    osMessagePut ( phost->os_event, USBH_STATE_CHANGED_EVENT, 0);
#endif       
    }
    break;
    
  case ENUM_GET_PRODUCT_STRING_DESC:   
    if (phost->device.DevDesc.iProduct != 0)
    { /* Check that Product string is available */
      if ((tmp_status = USBH_Get_StringDesc(phost,
                               phost->device.DevDesc.iProduct, 
                               phost->device.Data, 
                               0xff)) == USBH_OK)
      {
        /* User callback for Product string */
        DLOG_Critical("Product : %s",  (char *)phost->device.Data);
        phost->EnumState = ENUM_GET_SERIALNUM_STRING_DESC;        
      }
      else if(USBH_FAIL == tmp_status)
      {
          Status = USBH_FAIL;
          USBH_LL_NotifyUSBHStateChange(phost);
      }
    }
    else
    {
      DLOG_Info("Product : N/A");
      phost->EnumState = ENUM_GET_SERIALNUM_STRING_DESC; 

      USBH_LL_NotifyUSBHStateChange(phost);

#if (USBH_USE_OS == 1)
    osMessagePut ( phost->os_event, USBH_STATE_CHANGED_EVENT, 0);
#endif        
    } 
    break;
    
  case ENUM_GET_SERIALNUM_STRING_DESC:   
    if (phost->device.DevDesc.iSerialNumber != 0)
    { /* Check that Serial number string is available */    
      if ((tmp_status = USBH_Get_StringDesc(phost,
                               phost->device.DevDesc.iSerialNumber, 
                               phost->device.Data, 
                               0xff)) == USBH_OK)
      {
        /* User callback for Serial number string */
        DLOG_Info("Serial Number : %s",  (char *)phost->device.Data);
        Status = USBH_OK;
      }
      else if(USBH_FAIL == tmp_status)
      {
          Status = USBH_FAIL;
          USBH_LL_NotifyUSBHStateChange(phost);
      }
    }
    else
    {
      DLOG_Info("Serial Number : N/A"); 
      Status = USBH_OK;

      USBH_LL_NotifyUSBHStateChange(phost);

#if (USBH_USE_OS == 1)
    osMessagePut ( phost->os_event, USBH_STATE_CHANGED_EVENT, 0);
#endif        
    }  
    break;
    
  default:
    break;
  }  
  return Status;
}

/**
  * @brief  USBH_LL_SetTimer 
  *         Set the initial Host Timer tick
  * @param  phost: Host Handle
  * @retval None
  */
void  USBH_LL_SetTimer  (USBH_HandleTypeDef *phost, uint32_t time)
{
  phost->Timer = time;
}
/**
  * @brief  USBH_LL_IncTimer 
  *         Increment Host Timer tick
  * @param  phost: Host Handle
  * @retval None
  */
void  USBH_LL_IncTimer  (USBH_HandleTypeDef *phost)
{
  phost->Timer ++;
  USBH_HandleSof(phost);
}

/**
  * @brief  USBH_HandleSof 
  *         Call SOF process
  * @param  phost: Host Handle
  * @retval None
  */
void  USBH_HandleSof  (USBH_HandleTypeDef *phost)
{
  if((phost->gState == HOST_CLASS)&&(phost->pActiveClass != NULL))
  {
    phost->pActiveClass->SOFProcess(phost);
  }
}
/**
  * @brief  USBH_LL_Connect 
  *         Handle USB Host connexion event
  * @param  phost: Host Handle
  * @retval USBH_Status
  */
USBH_StatusTypeDef  USBH_LL_Connect  (USBH_HandleTypeDef *phost)
{
  DLOG_Error("usbh ll connect: tick:%d, state:%d", SysTicks_GetTickCount(), phost->gState);

  if (phost->gState != HOST_IDLE)// && phost->gState != HOST_DEV_DISCONNECTED
  {
    if ((SysTicks_GetDiff(phost->connect_tick, SysTicks_GetTickCount()) < 200)&& // 200
        (phost->gState == HOST_DEV_WAIT_FOR_ATTACHMENT))
    {
      phost->gState = HOST_IDLE;
    }
    else if (phost->gState != HOST_DEV_WAIT_FOR_ATTACHMENT)
    {
      //USBH_LL_Disconnect(phost);
      /*DLOG_Critical("invalid usb connect state timediff %d", SysTicks_GetDiff(phost->connect_tick, SysTicks_GetTickCount()));
      return USBH_OK;*/
    }
  }

  if(phost->gState == HOST_IDLE )
  {
    phost->device.is_connected = 1;

    if(phost->pUser != NULL)
    {
      phost->pUser(phost, HOST_USER_CONNECTION);
    }

    phost->connect_tick = SysTicks_GetTickCount();
  }
  else if(phost->gState == HOST_DEV_WAIT_FOR_ATTACHMENT )
  {
    phost->gState = HOST_DEV_ATTACHED ;
  }

  USBH_LL_NotifyUSBHStateChange(phost);
#if (USBH_USE_OS == 1)
  osMessagePut ( phost->os_event, USBH_PORT_EVENT, 0);
#endif

  return USBH_OK;
}

/**
  * @brief  USBH_LL_Disconnect 
  *         Handle USB Host disconnection event
  * @param  phost: Host Handle
  * @retval USBH_Status
  */
USBH_StatusTypeDef  USBH_LL_Disconnect  (USBH_HandleTypeDef *phost)
{
  phost->disconn_tick = SysTicks_GetTickCount();
  /*Stop Host */ 
  USBH_LL_Stop(phost);  
  
  /* FRee Control Pipes */
  USBH_FreePipe  (phost, phost->Control.pipe_in);
  USBH_FreePipe  (phost, phost->Control.pipe_out);

  phost->device.is_connected = 0; 
   
  if(phost->pUser != NULL)
  {
    phost->pUser(phost, HOST_USER_DISCONNECTION);
  }
  DLOG_Critical("USB Device disconnected: %d", SysTicks_GetTickCount());

  USB_DisableGlobalInt(((HCD_HandleTypeDef *)phost->pData)->Instance);

  
  phost->gState = HOST_DEV_DISCONNECTED;
  
  USBH_LL_NotifyUSBHStateChange(phost);
#if (USBH_USE_OS == 1)
  osMessagePut ( phost->os_event, USBH_PORT_EVENT, 0);
#endif 
  return USBH_OK;
}


USBH_StatusTypeDef  USBH_LL_IsocURBDone(USBH_HandleTypeDef *phost)
{
    if (phost->isocURBDone != NULL)
    {
        phost->isocURBDone(phost);
    }
}


#if (USBH_USE_OS == 1)  
/**
  * @brief  USB Host Thread task
  * @param  pvParameters not used
  * @retval None
  */
static void USBH_Process_OS(void const * argument)
{
  osEvent event;
  
  for(;;)
  {
    event = osMessageGet(((USBH_HandleTypeDef *)argument)->os_event, osWaitForever );
    
    if( event.status == osEventMessage )
    {
      USBH_Process((USBH_HandleTypeDef *)argument);
    }
  }
}

/**
* @brief  USBH_LL_NotifyURBChange 
*         Notify URB state Change
* @param  phost: Host handle
* @retval USBH Status
*/
USBH_StatusTypeDef  USBH_LL_NotifyURBChange (USBH_HandleTypeDef *phost)
{
  osMessagePut ( phost->os_event, USBH_URB_EVENT, 0);

  return USBH_OK;
}
#endif  


__attribute__((weak)) void ar_osUSBHEventMsgQGet(void *p)
{

}

__attribute__((weak)) void ar_osUSBHEventMsgQPut(void *p)
{

}

static USBH_EVENT_MSG   g_stUSBHEventMsg[2];

USBH_StatusTypeDef  USBH_LL_NotifyUSBHStateChange(USBH_HandleTypeDef *phost)
{
    uint8_t                 u8_portId = phost->id;
    USBH_EVENT_MSG          *pEventMsg;

    pEventMsg               = &g_stUSBHEventMsg[u8_portId];
    pEventMsg->u8_portId    = phost->id;
    pEventMsg->u8_msgType   = 0;

    ar_osUSBHEventMsgQPut((void *)pEventMsg);

    return USBH_OK;
}


/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
