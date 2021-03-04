/**
  ******************************************************************************
  * @file    sdmmc.c
  * @brief   This file provides code for the configuration
  *          of the SDMMC instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "drv_sdio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

SD_HandleTypeDef hsd1;
DMA_HandleTypeDef hdma_sdmmc1_rx;
DMA_HandleTypeDef hdma_sdmmc1_tx;

/**
  * @brief This function handles SDMMC1 global interrupt.
  */
void SDMMC1_IRQHandler(void)
{
    /* USER CODE BEGIN SDMMC1_IRQn 0 */

    /* USER CODE END SDMMC1_IRQn 0 */
    HAL_SD_IRQHandler(&hsd1);
    /* USER CODE BEGIN SDMMC1_IRQn 1 */

    /* USER CODE END SDMMC1_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream3 global interrupt.
  */
void DMA2_Stream3_IRQHandler(void)
{
    /* USER CODE BEGIN DMA2_Stream3_IRQn 0 */

    /* USER CODE END DMA2_Stream3_IRQn 0 */
    HAL_DMA_IRQHandler(&hdma_sdmmc1_tx);
    /* USER CODE BEGIN DMA2_Stream3_IRQn 1 */

    /* USER CODE END DMA2_Stream3_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream6 global interrupt.
  */
void DMA2_Stream6_IRQHandler(void)
{
    /* USER CODE BEGIN DMA2_Stream6_IRQn 0 */

    /* USER CODE END DMA2_Stream6_IRQn 0 */
    HAL_DMA_IRQHandler(&hdma_sdmmc1_rx);
    /* USER CODE BEGIN DMA2_Stream6_IRQn 1 */

    /* USER CODE END DMA2_Stream6_IRQn 1 */
}

/**
  * Enable DMA controller clock
  */
void MX_DMA_Init(void)
{
    /* Init with LL driver */
    /* DMA controller clock enable */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA2);

    /* DMA2_Stream3_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream3_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream3_IRQn);
    /* DMA2_Stream6_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream6_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream6_IRQn);
}

void MX_GPIO_Init(void)
{

    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    /* GPIO Ports Clock Enable */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);

    /**/
    LL_GPIO_SetOutputPin(GPIOG, LL_GPIO_PIN_7);

    /**/
    GPIO_InitStruct.Pin = LL_GPIO_PIN_7;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOG, &GPIO_InitStruct);
}

/* SDMMC1 init function */

uint8_t tx_buffer[512] = { 0 };
uint8_t rx_buffer[512] = { 0 };
void MX_SDMMC1_SD_Init(void)
{
    /* GPIO Ports Clock Enable */
    MX_GPIO_Init();

    MX_DMA_Init();

    hsd1.Instance = SDMMC1;
    hsd1.Init.ClockEdge = SDMMC_CLOCK_EDGE_RISING;
    hsd1.Init.ClockBypass = SDMMC_CLOCK_BYPASS_DISABLE;
    hsd1.Init.ClockPowerSave = SDMMC_CLOCK_POWER_SAVE_DISABLE;
    hsd1.Init.BusWide = SDMMC_BUS_WIDE_1B;
    hsd1.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
    hsd1.Init.ClockDiv = 0;
    if (HAL_SD_Init(&hsd1) != HAL_OK) {
        Error_Handler();
    }
    if (HAL_SD_ConfigWideBusOperation(&hsd1, SDMMC_BUS_WIDE_4B) != HAL_OK) {
        Error_Handler();
    }

    HAL_SD_CardInfoTypeDef pCardInfo;
    if (HAL_SD_GetCardInfo(&hsd1, &pCardInfo) == HAL_OK) {
        console_printf("CardType:%u\n", pCardInfo.CardType);
        console_printf("CardVersion:%u\n", pCardInfo.CardVersion);
        console_printf("Class:%u\n", pCardInfo.Class);
        console_printf("RelCardAdd:%x\n", pCardInfo.RelCardAdd);
        console_printf("BlockNbr:%u\n", pCardInfo.BlockNbr);
        console_printf("BlockSize:%u\n", pCardInfo.BlockSize);
        console_printf("LogBlockNbr:%u\n", pCardInfo.LogBlockNbr);
        console_printf("LogBlockSize:%u\n", pCardInfo.LogBlockSize);
    } else {
        console_printf("fail to get card info\n");
    }

    int i;
    memset(tx_buffer, 0x66, 512);
    if (HAL_SD_WriteBlocks_DMA(&hsd1, tx_buffer, 0, 1) != HAL_OK) {
        console_printf("write fail!\n");
        return;
    }
    while (HAL_SD_GetCardState(&hsd1) != HAL_SD_CARD_TRANSFER)
        ;

    memset(tx_buffer, 0x77, 512);
    if (HAL_SD_WriteBlocks_DMA(&hsd1, tx_buffer, 1, 1) != HAL_OK) {
        console_printf("write fail!\n");
        return;
    }
    while (HAL_SD_GetCardState(&hsd1) != HAL_SD_CARD_TRANSFER)
        ;

    if (HAL_SD_ReadBlocks_DMA(&hsd1, rx_buffer, 0, 1) != HAL_OK) {
        console_printf("read fail!\n");
        return;
    }
    while (HAL_SD_GetCardState(&hsd1) != HAL_SD_CARD_TRANSFER)
        ;

    for (i = 0; i < 10; i++) {
        console_printf("%x,", rx_buffer[i]);
    }
    console_printf("\n");

    if (HAL_SD_ReadBlocks_DMA(&hsd1, rx_buffer, 1, 1) != HAL_OK) {
        console_printf("read fail!\n");
        return;
    }
    while (HAL_SD_GetCardState(&hsd1) != HAL_SD_CARD_TRANSFER)
        ;

    for (i = 0; i < 10; i++) {
        console_printf("%x,", rx_buffer[i]);
    }
}

void HAL_SD_MspInit(SD_HandleTypeDef* sdHandle)
{

    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    if (sdHandle->Instance == SDMMC1) {
        /* USER CODE BEGIN SDMMC1_MspInit 0 */

        /* USER CODE END SDMMC1_MspInit 0 */
        /* SDMMC1 clock enable */
        __HAL_RCC_SDMMC1_CLK_ENABLE();

        __HAL_RCC_GPIOC_CLK_ENABLE();
        __HAL_RCC_GPIOD_CLK_ENABLE();
        /**SDMMC1 GPIO Configuration
    PC12     ------> SDMMC1_CK
    PC11     ------> SDMMC1_D3
    PC10     ------> SDMMC1_D2
    PD2     ------> SDMMC1_CMD
    PC9     ------> SDMMC1_D1
    PC8     ------> SDMMC1_D0
    */
        GPIO_InitStruct.Pin = GPIO_PIN_12;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF12_SDMMC1;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_11 | GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF12_SDMMC1;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_2;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF12_SDMMC1;
        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        /* SDMMC1 DMA Init */
        /* SDMMC1_TX Init */
        hdma_sdmmc1_tx.Instance = DMA2_Stream3;
        hdma_sdmmc1_tx.Init.Channel = DMA_CHANNEL_4;
        hdma_sdmmc1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
        hdma_sdmmc1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_sdmmc1_tx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_sdmmc1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
        hdma_sdmmc1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
        hdma_sdmmc1_tx.Init.Mode = DMA_PFCTRL;
        hdma_sdmmc1_tx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_sdmmc1_tx.Init.FIFOMode = DMA_FIFOMODE_ENABLE;
        hdma_sdmmc1_tx.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
        hdma_sdmmc1_tx.Init.MemBurst = DMA_MBURST_INC4;
        hdma_sdmmc1_tx.Init.PeriphBurst = DMA_PBURST_INC4;
        if (HAL_DMA_Init(&hdma_sdmmc1_tx) != HAL_OK) {
            Error_Handler();
        }

        __HAL_LINKDMA(sdHandle, hdmatx, hdma_sdmmc1_tx);

        /* SDMMC1_RX Init */
        hdma_sdmmc1_rx.Instance = DMA2_Stream6;
        hdma_sdmmc1_rx.Init.Channel = DMA_CHANNEL_4;
        hdma_sdmmc1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
        hdma_sdmmc1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_sdmmc1_rx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_sdmmc1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
        hdma_sdmmc1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
        hdma_sdmmc1_rx.Init.Mode = DMA_PFCTRL;
        hdma_sdmmc1_rx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_sdmmc1_rx.Init.FIFOMode = DMA_FIFOMODE_ENABLE;
        hdma_sdmmc1_rx.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
        hdma_sdmmc1_rx.Init.MemBurst = DMA_MBURST_INC4;
        hdma_sdmmc1_rx.Init.PeriphBurst = DMA_PBURST_INC4;
        if (HAL_DMA_Init(&hdma_sdmmc1_rx) != HAL_OK) {
            Error_Handler();
        }

        __HAL_LINKDMA(sdHandle, hdmarx, hdma_sdmmc1_rx);

        /* SDMMC1 interrupt Init */
        HAL_NVIC_SetPriority(SDMMC1_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(SDMMC1_IRQn);
        /* USER CODE BEGIN SDMMC1_MspInit 1 */

        /* USER CODE END SDMMC1_MspInit 1 */
    }
}

void HAL_SD_MspDeInit(SD_HandleTypeDef* sdHandle)
{

    if (sdHandle->Instance == SDMMC1) {
        /* USER CODE BEGIN SDMMC1_MspDeInit 0 */

        /* USER CODE END SDMMC1_MspDeInit 0 */
        /* Peripheral clock disable */
        __HAL_RCC_SDMMC1_CLK_DISABLE();

        /**SDMMC1 GPIO Configuration
    PC12     ------> SDMMC1_CK
    PC11     ------> SDMMC1_D3
    PC10     ------> SDMMC1_D2
    PD2     ------> SDMMC1_CMD
    PC9     ------> SDMMC1_D1
    PC8     ------> SDMMC1_D0
    */
        HAL_GPIO_DeInit(GPIOC, GPIO_PIN_12 | GPIO_PIN_11 | GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8);

        HAL_GPIO_DeInit(GPIOD, GPIO_PIN_2);

        /* SDMMC1 DMA DeInit */
        HAL_DMA_DeInit(sdHandle->hdmatx);
        HAL_DMA_DeInit(sdHandle->hdmarx);

        /* SDMMC1 interrupt Deinit */
        HAL_NVIC_DisableIRQ(SDMMC1_IRQn);
        /* USER CODE BEGIN SDMMC1_MspDeInit 1 */

        /* USER CODE END SDMMC1_MspDeInit 1 */
    }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
