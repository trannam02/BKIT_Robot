/*
 * softwareTimer.h
 *
 *  Created on: May 26, 2025
 *      Author: NAM
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

// Timer
// Timer 0: test
// Timer 1: Led scan
void setTimer(int timer, int duration);
int getFlag(int timer);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
