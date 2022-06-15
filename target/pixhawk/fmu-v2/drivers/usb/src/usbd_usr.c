/**
  ******************************************************************************
  * @file    usbd_usr.c
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    09-November-2015
  * @brief   This file includes the user application layer
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
#include "usbd_usr.h"

void drv_usbd_cdc_connect_cb(void);
void drv_usbd_cdc_disconnect_cb(void);

USBD_Usr_cb_TypeDef USR_cb = {
    USBD_USR_Init,
    USBD_USR_DeviceReset,
    USBD_USR_DeviceConfigured,
    USBD_USR_DeviceSuspended,
    USBD_USR_DeviceResumed,

    USBD_USR_DeviceConnected,
    USBD_USR_DeviceDisconnected,
};

extern void cdc_connected_status_change(uint8_t connected);

/**
* @}
*/

/** @defgroup USBD_USR_Private_Constants
* @{
*/

/**
* @}
*/

/** @defgroup USBD_USR_Private_FunctionPrototypes
* @{
*/
/**
* @}
*/

/** @defgroup USBD_USR_Private_Functions
* @{
*/

/**
* @brief  USBD_USR_Init
*         Displays the message on LCD for host lib initialization
* @param  None
* @retval None
*/
void USBD_USR_Init(void)
{
    //printf("USBD_USR_Init\n");
}

/**
* @brief  USBD_USR_DeviceReset
*         Displays the message on LCD on device Reset Event
* @param  speed : device speed
* @retval None
*/
void USBD_USR_DeviceReset(uint8_t speed)
{
    switch (speed) {
    case USB_OTG_SPEED_HIGH:
        //printf("USB Device Library v1.2.0 [HS]\n");
        break;

    case USB_OTG_SPEED_FULL:
        //printf("USB Device Library v1.2.0 [FS]\n");
        break;
        // default:
        //	 printf("USB Device Library v1.2.0 [??]\n");
    }
}

/**
* @brief  USBD_USR_DeviceConfigured
*         Displays the message on LCD on device configuration Event
* @param  None
* @retval Status
*/
void USBD_USR_DeviceConfigured(void)
{
    //printf("> VCP Interface configured.\n");
}

/**
* @brief  USBD_USR_DeviceSuspended
*         Displays the message on LCD on device suspend Event
* @param  None
* @retval None
*/
void USBD_USR_DeviceSuspended(void)
{
    //printf("> USB Device in Suspend Mode.\n");
    /* Users can do their application actions here for the USB-Reset */
}

/**
* @brief  USBD_USR_DeviceResumed
*         Displays the message on LCD on device resume Event
* @param  None
* @retval None
*/
void USBD_USR_DeviceResumed(void)
{
    //printf("> USB Device in Idle Mode.\n");
    /* Users can do their application actions here for the USB-Reset */
}

/**
* @brief  USBD_USR_DeviceConnected
*         Displays the message on LCD on device connection Event
* @param  None
* @retval Status
*/
void USBD_USR_DeviceConnected(void)
{
    drv_usbd_cdc_connect_cb();
}

/**
* @brief  USBD_USR_DeviceDisonnected
*         Displays the message on LCD on device disconnection Event
* @param  None
* @retval Status
*/
void USBD_USR_DeviceDisconnected(void)
{
    drv_usbd_cdc_disconnect_cb();
}

/**
* @}
*/

/**
* @}
*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
