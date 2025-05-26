#include <led_control.h>

uint8_t data_buffer[3] = {0, 0, 0};
uint8_t led_control_state = INIT;

uint8_t seven_seg_digits[10] = {
  0b00111111, // 0 → segments a b c d e f
  0b00000110, // 1 → segments b c
  0b01011011, // 2 → segments a b d e g
  0b01001111, // 3 → segments a b c d g
  0b01100110, // 4 → segments b c f g
  0b01101101, // 5 → segments a c d f g
  0b01111101, // 6 → segments a c d e f g
  0b00000111, // 7 → segments a b c
  0b01111111, // 8 → all segments
  0b01101111  // 9 → segments a b c d f g
};


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
 * @brief  Load data from input to output of 595 IC
 * @param data: input
 * @retval None
 */
void latch_data(uint8_t data){
  HAL_SPI_Transmit(&hspi1, &data, 1, 1000);
  HAL_GPIO_WritePin(LED_LATCH_GPIO_Port, LED_LATCH_Pin, GPIO_PIN_SET);
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
			setTimer(1, 10);
			break;
		case SEG1_ACTIVE:
			LED7SEG_ENABLE_1;
			LED7SEG_DISABLE_2;
			LED_DISABLE;
			latch_data(data_buffer[0]);
			if(getFlag(1) == 1){ // check timer to switch state
				led_control_state = SEG2_ACTIVE;
				setTimer(1, 10);
			};
			break;
		case SEG2_ACTIVE:
			LED7SEG_DISABLE_1;
			LED7SEG_ENABLE_2;
			LED_DISABLE;
			latch_data(data_buffer[1]);
			if(getFlag(1) == 1){ // check timer to switch state
				led_control_state = LED_ARRAY_ACTIVE;
				setTimer(1, 10);
			};
			break;
		case LED_ARRAY_ACTIVE:
			LED7SEG_DISABLE_1;
			LED7SEG_DISABLE_2;
			LED_ENABLE;
			latch_data(data_buffer[2]);
			if(getFlag(1) == 1){ // check timer to switch state
				led_control_state = SEG1_ACTIVE;
				setTimer(1, 10);
			};
			break;
		default: break;
	}
};



/**
 * @brief  Convert BCD number to 7 segment LED signal
 * @param digit: number to convert/number for converting
 * @retval Signal to display 7 segment LED
 */
uint8_t digit_to_segment(uint8_t digit) {
  if (digit > 9) return 0;
  return seven_seg_digits[digit];
}
void set_seg_1(uint8_t data){
	data_buffer[0] = digit_to_segment(data);
};
void set_seg_2(uint8_t data){
	data_buffer[1] = digit_to_segment(data);
};
void set_led_array(uint8_t data){
	data_buffer[2] = data;
};


/**
 * @brief  Used to test some functions of this API
 * @retval None
 */
void test_led_control(){
	set_seg_1(8);
	set_seg_2(5);
	set_led_array(0b10101010);
};
