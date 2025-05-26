#include <led_control.h>

uint8_t data_buffer[3] = {0, 0, 0};
uint8_t led_control_state = 0;

/**
 * @brief  Init for led control
 * @retval None
 */
void LED_init(){
	LED7SEG_DISABLE_1;
	LED7SEG_DISABLE_2;
	LED_DISABLE;
	HAL_GPIO_WritePin(LED_LATCH_GPIO_Port, LED_LATCH_Pin, GPIO_PIN_RESET);
};

/**
 * @brief  Main fsm for led control
 * @retval None
 */
void LED_fsm_run(){
switch(led_control_state){
case INIT:
	led_control_state = SEG1_ACTIVE;
	break;
case SEG1_ACTIVE:
	LED7SEG_ENABLE_1;
	LED7SEG_DISABLE_2;
	LED_DISABLE;
	latch_data(data_buffer[0]);
	if(1){ // check timer to switch state
		led_control_state = SEG2_ACTIVE;
	};
	break;
case SEG2_ACTIVE:
	LED7SEG_DISABLE_1;
	LED7SEG_ENABLE_2;
	LED_DISABLE;
	latch_data(data_buffer[1]);
	if(1){ // check timer to switch state
		led_control_state = LED_ARRAY_ACTIVE;
	};
	break;
case LED_ARRAY_ACTIVE:
	LED7SEG_DISABLE_1;
	LED7SEG_DISABLE_2;
	LED_ENABLE;
	latch_data(data_buffer[2]);
	if(1){ // check timer to switch state
		led_control_state = SEG1_ACTIVE;
	};
	break;
}
};

/**
 * @brief  Load data from input to output of 595 IC
 * @param data: input
 * @retval None
 */
void latch_data(uint8_t data){
  HAL_SPI_Transmit(&hspi1, &data, 1, 1000);
  HAL_GPIO_WritePin(LED_LATCH_GPIO_Port, LED_LATCH_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED_LATCH_GPIO_Port, LED_LATCH_Pin, GPIO_PIN_RESET);
};


void set_seg_1(uint8_t data){
	data_buffer[0] = data;
};
void set_seg_2(uint8_t data){
	data_buffer[1] = data;
};
void set_led_array(uint8_t data){
	data_buffer[2] = data;
};
