/*
 * input_scan.c
 *
 *  Created on: May 27, 2025
 *      Author: NAM
 */
#include "input_scan.h"

uint8_t data_input_0, data_input_1, data_input_2;
uint8_t compare_1, compare_2;

void INPUT_SCAN_fsm_run(){
	data_input_2 = data_input_1;
	data_input_1 = data_input_0;

	HAL_GPIO_WritePin(INPUT_LOAD_GPIO_Port, INPUT_LOAD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(INPUT_LOAD_GPIO_Port, INPUT_LOAD_Pin, GPIO_PIN_SET);
	HAL_SPI_Receive(&hspi1, &data_input_0, 1, 1000);

	compare_1 = data_input_0 ^ data_input_1;
	compare_2 = data_input_1 ^ data_input_2;


};
void INPUT_SCAN_init(){
	HAL_GPIO_WritePin(INPUT_LOAD_GPIO_Port, INPUT_LOAD_Pin, GPIO_PIN_SET);
};
