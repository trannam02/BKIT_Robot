/*
 * buzzer.c
 *
 *  Created on: May 27, 2025
 *      Author: NAM
 */
#include "buzzer.h"
//void beep(uint32_t freq, uint32_t duration_ms, float duty_cycle) {
//	if (freq == 0) {
//		// rest
//		HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
//		HAL_Delay(duration_ms);
//		return;
//	}
//
//    uint32_t timer_clock = 64000000; // Timer clock 64 MHz
//    uint32_t arr = 100;
//    uint32_t psc = (timer_clock / ((arr + 1) * freq)) - 1;
//    uint32_t ccr = duty_cycle * arr;
//
//    __HAL_TIM_SET_PRESCALER(&htim2, psc);
//    __HAL_TIM_SET_AUTORELOAD(&htim2, arr);
//    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, ccr);
//
//    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
//    HAL_Delay(duration_ms);
//    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
//}

uint8_t is_beep = 0;

void beep(uint32_t duration_ms){
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	is_beep = 1;
	setTimer(3, duration_ms);
};

void BUZZER_fsm_run(){
	if(getFlag(3) == 1 && is_beep == 1){
		HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
		is_beep = 0;
	};
};

