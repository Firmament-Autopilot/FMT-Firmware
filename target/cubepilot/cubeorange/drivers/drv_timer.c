#include "drv_timer.h"
#include "stm32h7xx_ll_tim.h"

void drv_timer_init(void)
{
    /* USER CODE BEGIN TIM6_Init 0 */

    /* USER CODE END TIM6_Init 0 */

    LL_TIM_InitTypeDef TIM_InitStruct = { 0 };

    /* Peripheral clock enable */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM6);

    /* TIM6 interrupt Init */
    NVIC_SetPriority(TIM6_DAC_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 2, 0));
    NVIC_EnableIRQ(TIM6_DAC_IRQn);

    /* USER CODE BEGIN TIM6_Init 1 */

    /* USER CODE END TIM6_Init 1 */
    TIM_InitStruct.Prescaler = 240 - 1;
    TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
    TIM_InitStruct.Autoreload = 2000 - 1;
    LL_TIM_Init(TIM6, &TIM_InitStruct);
    LL_TIM_DisableARRPreload(TIM6);
    LL_TIM_SetTriggerOutput(TIM6, LL_TIM_TRGO_RESET);
    LL_TIM_DisableMasterSlaveMode(TIM6);
    /* USER CODE BEGIN TIM6_Init 2 */
    LL_TIM_EnableCounter(TIM6);   // 使能计数
    LL_TIM_EnableIT_UPDATE(TIM6); // 使能更新中断
    LL_TIM_EnableAllOutputs(TIM6);
    /* USER CODE END TIM6_Init 2 */
}
