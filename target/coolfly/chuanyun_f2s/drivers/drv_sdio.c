/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include <firmament.h>

#include "board.h"
#include "drv_sdio.h"
#include "hal/sd/sd.h"

#define SD_TIMEOUT    5000
#define EVENT_TX_CPLT 0x00000001
#define EVENT_RX_CPLT 0x00000002
#define EVENT_ERROR   0x00000004
#define EVENT_ABORT   0x00000008


// /* SDMMC1 */
// static SD_HandleTypeDef hsd1;
// static DMA_HandleTypeDef hdma_sdmmc1_rx;
// static DMA_HandleTypeDef hdma_sdmmc1_tx;
// static struct sd_device sd0_dev;

// void HAL_SD_TxCpltCallback(SD_HandleTypeDef* hsd)
// {
//     if (hsd == &hsd1) {
//         rt_event_send(&sd0_dev.event, EVENT_TX_CPLT);
//     }
// }

// void HAL_SD_RxCpltCallback(SD_HandleTypeDef* hsd)
// {
//     if (hsd == &hsd1) {
//         rt_event_send(&sd0_dev.event, EVENT_RX_CPLT);
//     }
// }

// void HAL_SD_ErrorCallback(SD_HandleTypeDef* hsd)
// {
//     if (hsd == &hsd1) {
//         rt_event_send(&sd0_dev.event, EVENT_ERROR);
//     }
// }

// void HAL_SD_AbortCallback(SD_HandleTypeDef* hsd)
// {
//     if (hsd == &hsd1) {
//         rt_event_send(&sd0_dev.event, EVENT_ABORT);
//     }
// }

// /**
//   * @brief This function handles SDMMC1 global interrupt.
//   */
// void SDMMC1_IRQHandler(void)
// {
//     HAL_SD_IRQHandler(&hsd1);
// }

// /**
//   * @brief This function handles DMA2 stream3 global interrupt.
//   */
// void DMA2_Stream3_IRQHandler(void)
// {
//     HAL_DMA_IRQHandler(&hdma_sdmmc1_tx);
// }

// /**
//   * @brief This function handles DMA2 stream6 global interrupt.
//   */
// void DMA2_Stream6_IRQHandler(void)
// {
//     HAL_DMA_IRQHandler(&hdma_sdmmc1_rx);
// }

// void HAL_SD_MspInit(SD_HandleTypeDef* sdHandle)
// {

// }

// void HAL_SD_MspDeInit(SD_HandleTypeDef* sdHandle)
// {
  
// }

// static rt_err_t sdio_wait_complete(sd_dev_t sd_dev, rt_uint32_t* status)
// {

//     return RT_EOK;
// }

// static rt_err_t init(sd_dev_t sd)
// {
 
//     return RT_EOK;
// }

// static rt_err_t write_disk(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
// {
//     rt_err_t err = RT_EOK;

//     return err;
// }

// static rt_err_t read_disk(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
// {
//     rt_err_t err = RT_EOK;

//     return err;
// }

// static rt_err_t io_control(sd_dev_t sd, int cmd, void* arg)
// {
   
//     return RT_EOK;
// }

// const static struct sd_ops dev_ops = {
//     .init = init,
//     .write_disk = write_disk,
//     .read_disk = read_disk,
//     .io_control = io_control
// };

rt_err_t drv_sdio_init(void)
{
    // sd0_dev.ops = &dev_ops;

    // if (rt_event_init(&sd0_dev.event, "sdio", RT_IPC_FLAG_FIFO) != RT_EOK) {
    //     console_printf("fail to init sdio event\n");
    //     return RT_ERROR;
    // }

    // return hal_sd_register(&sd0_dev, "sd0",
    //     RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE | RT_DEVICE_FLAG_STANDALONE, &hsd1);

    return RT_EOK;
}
