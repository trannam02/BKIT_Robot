/*
 * buzzer.h
 *
 *  Created on: May 27, 2025
 *      Author: NAM
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "main.h"
#include "tim.h"
#include "software_timer.h"

#define BEEP beep(150);

void beep(uint32_t duration_ms);
void BUZZER_fsm_run();

#endif /* INC_BUZZER_H_ */
