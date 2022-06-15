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

#include "module/buzzer/buzzer.h"
#include <firmament.h>

/* Tone alarm output */
#define TONE_ALARM_TIMER     2 /* timer 2 */
#define TONE_ALARM_CHANNEL   1 /* channel 1 */
#define GPIO_TONE_ALARM_IDLE (GPIO_OUTPUT | GPIO_PUSHPULL | GPIO_SPEED_2MHz | GPIO_OUTPUT_CLEAR | GPIO_PORTA | GPIO_PIN15)
#define GPIO_TONE_ALARM      (GPIO_ALT | GPIO_AF1 | GPIO_SPEED_2MHz | GPIO_PUSHPULL | GPIO_PORTA | GPIO_PIN15)

/* Check that buzzer alarm and HRT timers are different */
#if defined(TONE_ALARM_TIMER) && defined(HRT_TIMER)
    #if TONE_ALARM_TIMER == HRT_TIMER
        #error TONE_ALARM_TIMER and HRT_TIMER must use different timers.
    #endif
#endif

/* Period of the free-running counter, in microseconds. */
#ifndef TONE_ALARM_COUNTER_PERIOD
    #define TONE_ALARM_COUNTER_PERIOD 65536
#endif

/* Tone alarm configuration  TONE_ALARM_TIMER == 2 */

#define STM32_SYSCLK_FREQUENCY 168000000ul
#define STM32_HCLK_FREQUENCY   STM32_SYSCLK_FREQUENCY
#define STM32_PCLK1_FREQUENCY  (STM32_HCLK_FREQUENCY / 4)
/* Timers driven from APB1 will be twice PCLK1 */
#define STM32_APB1_TIM2_CLKIN (2 * STM32_PCLK1_FREQUENCY)

#define TONE_ALARM_BASE  TIM2_BASE
#define TONE_ALARM_CLOCK STM32_APB1_TIM2_CLKIN
// # define TONE_ALARM_CLOCK_ENABLE        RCC_APB1ENR_TIM2EN
// # define TONE_ALARM_CLOCK_POWER_REG     RCC_APB1ENR

#if TONE_ALARM_CHANNEL == 1
    #define TONE_CCER  (1 << 0)
    #define TONE_CCMR1 (3 << 4)
    #define TONE_CCMR2 0
    #define TONE_rCCR  rCCR1
#elif TONE_ALARM_CHANNEL == 2
    #define TONE_CCER  (1 << 4)
    #define TONE_CCMR1 (3 << 12)
    #define TONE_CCMR2 0
    #define TONE_rCCR  rCCR2
#elif TONE_ALARM_CHANNEL == 3
    #define TONE_CCER  (1 << 8)
    #define TONE_CCMR1 0
    #define TONE_CCMR2 (3 << 4)
    #define TONE_rCCR  rCCR3
#elif TONE_ALARM_CHANNEL == 4
    #define TONE_CCER  (1 << 12)
    #define TONE_CCMR1 0
    #define TONE_CCMR2 (3 << 12)
    #define TONE_rCCR  rCCR4
#else
    #error Must set TONE_ALARM_CHANNEL to a value between 1 and 4 to use this driver.
#endif // TONE_ALARM_CHANNEL

/* Timer register accessors. */
// #define REG(_reg)       (*(volatile uint32_t *)(TONE_ALARM_BASE + _reg))

#define rARR   TIM2->ARR
#define rCCER  TIM2->CCER
#define rCCMR1 TIM2->CCMR1
#define rCCMR2 TIM2->CCMR2
#define rCCR1  TIM2->CCR1
#define rCCR2  TIM2->CCR2
#define rCCR3  TIM2->CCR3
#define rCCR4  TIM2->CCR4
#define rCNT   TIM2->CNT
#define rCR1   TIM2->CR1
#define rCR2   TIM2->CR2
#define rDCR   TIM2->DCR
#define rDIER  TIM2->DIER
#define rDMAR  TIM2->DMAR
#define rEGR   TIM2->EGR
#define rPSC   TIM2->PSC
#define rRCR   TIM2->RCR
#define rSMCR  TIM2->SMCR
#define rSR    TIM2->SR

static void _buzzer_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* TIM2 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    /* GPIOA clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* Connect TIM2 pins to AF */
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_TIM2);
}

static void _buzzer_gpio_idel(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* TIM2 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    /* GPIOA clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA, GPIO_PinSource15);
}

void buzzer_start_note(unsigned frequency)
{
    // Calculate the signal switching period.
    // (Signal switching period is one half of the frequency period).
    float signal_period = (1.0f / frequency) * 0.5f;

    // Calculate the hardware clock divisor rounded to the nearest integer.
    unsigned int divisor = round(signal_period * TONE_ALARM_CLOCK);

    // Pick the lowest prescaler value that we can use.
    // (Note that the effective prescale value is 1 greater.)
    unsigned int prescale = divisor / TONE_ALARM_COUNTER_PERIOD;

    // Calculate the period for the selected prescaler value.
    unsigned int period = (divisor / (prescale + 1)) - 1;

    rPSC = prescale;    // Load new prescaler.
    rARR = period;      // Load new toggle period.
    rEGR = TIM_EGR_UG;  // Force a reload of the period.
    rCCER |= TONE_CCER; // Enable the output.

    // Configure the GPIO to enable timer output.
    _buzzer_gpio_init();
}

void buzzer_set_freq(unsigned frequency)
{
    // Calculate the signal switching period.
    // (Signal switching period is one half of the frequency period).
    float signal_period = (1.0f / frequency) * 0.5f;

    // Calculate the hardware clock divisor rounded to the nearest integer.
    unsigned int divisor = round(signal_period * TONE_ALARM_CLOCK);

    // Pick the lowest prescaler value that we can use.
    // (Note that the effective prescale value is 1 greater.)
    unsigned int prescale = divisor / TONE_ALARM_COUNTER_PERIOD;

    // Calculate the period for the selected prescaler value.
    unsigned int period = (divisor / (prescale + 1)) - 1;

    rPSC = prescale; // Load new prescaler.
    rARR = period;   // Load new toggle period.
    // rEGR = TIM_EGR_UG;	// Force a reload of the period.
    rCCER |= TONE_CCER; // Enable the output.
}

void buzzer_stop_note()
{
    // Stop the current note.
    rCCER &= ~TONE_CCER;

    // Ensure the GPIO is not driving the speaker.
    _buzzer_gpio_idel();
}

//2349 2637 3136
int cmd_test_buzzer(int argc, char** argv)
{
    buzzer_init();
    buzzer_start_note(1174);
    rt_thread_mdelay(200);
    buzzer_set_freq(1318);
    rt_thread_mdelay(200);
    buzzer_set_freq(1568);
    rt_thread_mdelay(500);
    // for(int i=0;i<20;i++)
    // {
    // 	buzzer_set_freq(1568+i);
    // 	rt_thread_mdelay(10);
    // }

    buzzer_stop_note();
    return 0;
}

int buzzer_init(void)
{
    _buzzer_gpio_idel();

    // Clock/power on our timer.
    // modifyreg32(TONE_ALARM_CLOCK_POWER_REG, 0, TONE_ALARM_CLOCK_ENABLE);

    // Initialize the timer.
    rCCER &= TONE_CCER; // Unlock CCMR* registers.
    rCCER = TONE_CCER;
    rCCMR1 = TONE_CCMR1;
    rCCMR2 = TONE_CCMR2;
    rCR1 = 0;
    rCR2 = 0;
    rDCR = 0;
    rDIER = 0;
    rSMCR = 0;

#ifdef rBDTR               // If using an advanced timer, you need to activate the output.
    rBDTR = ATIM_BDTR_MOE; // Enable the main output of the advanced timer.
#endif

    TONE_rCCR = 1;      // Toggle the CC output each time the count passes 1.
    rPSC = 0;           // Default the timer to a prescale value of 1; playing notes will change this.
    rCR1 = TIM_CR1_CEN; // Ensure the timer is running.

    return 0;
}

// 开启pwm
int buzzer_on(void)
{
    _buzzer_gpio_init();

    return 0;
}

//关闭pwm
int buzzer_off(void)
{
    // _buzzer_gpio_idel();
    buzzer_stop_note();
    return 0;
}

int buzzer_set(uint16_t freq, uint8_t volume)
{
    // Calculate the signal switching period.
    // (Signal switching period is one half of the frequency period).
    float signal_period = (1.0f / freq) * 0.5f;

    // Calculate the hardware clock divisor rounded to the nearest integer.
    unsigned int divisor = round(signal_period * TONE_ALARM_CLOCK);

    // Pick the lowest prescaler value that we can use.
    // (Note that the effective prescale value is 1 greater.)
    unsigned int prescale = divisor / TONE_ALARM_COUNTER_PERIOD;

    // Calculate the period for the selected prescaler value.
    unsigned int period = (divisor / (prescale + 1)) - 1;

    rPSC = prescale; // Load new prescaler.
    rARR = period;   // Load new toggle period.
    // rEGR = TIM_EGR_UG;	// Force a reload of the period.
    rCCER |= TONE_CCER; // Enable the output.
    return 0;
}

void buzzer_play_startup(void)
{
    cmd_test_buzzer(RT_NULL, RT_NULL);
}

FINSH_FUNCTION_EXPORT_ALIAS(cmd_test_buzzer, __cmd_test_buzzer, user test buzzer command);