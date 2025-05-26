/*
 * led_7_seg.h
 *
 *  Created on: May 26, 2025
 *      Author: NAM
 */

#ifndef INC_LED_CONTROL_H_
#define INC_LED_CONTROL_H_

#include "main.h"
#include "spi.h"
#include "software_timer.h"

// Some macro
#define LED7SEG_ENABLE_1 HAL_GPIO_WritePin(LED7_EN1_GPIO_Port, LED7_EN1_Pin, GPIO_PIN_RESET);
#define LED7SEG_DISABLE_1 HAL_GPIO_WritePin(LED7_EN1_GPIO_Port, LED7_EN1_Pin, GPIO_PIN_SET);
#define LED7SEG_ENABLE_2 HAL_GPIO_WritePin(LED7_EN2_GPIO_Port, LED7_EN2_Pin, GPIO_PIN_RESET);
#define LED7SEG_DISABLE_2 HAL_GPIO_WritePin(LED7_EN2_GPIO_Port, LED7_EN2_Pin, GPIO_PIN_SET);
#define LED_ENABLE HAL_GPIO_WritePin(LED_EN_GPIO_Port, LED_EN_Pin, GPIO_PIN_RESET);
#define LED_DISABLE HAL_GPIO_WritePin(LED_EN_GPIO_Port, LED_EN_Pin, GPIO_PIN_SET);

// State
#define INIT 0
#define SEG1_ACTIVE 1
#define SEG2_ACTIVE 2
#define LED_ARRAY_ACTIVE 3


void LED_init();
void LED_fsm_run();
void test_led_control();

void set_seg_1(uint8_t data);
void set_seg_2(uint8_t data);
void set_led_array(uint8_t data);
#endif /* INC_LED_CONTROL_H_ */
