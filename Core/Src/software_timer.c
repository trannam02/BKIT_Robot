/*
 * software_timer.c
 *
 *  Created on: May 26, 2025
 *      Author: NAM
 */
#include "software_timer.h"

int timerArray[10];
int timerFlag[10];
int timerArrayCount = 0;
void setTimer(int timer, int duration){
	if(timer >= timerArrayCount) timerArrayCount++;
	timerArray[timer] = duration;
	timerFlag[timer] = 0;
};
int getFlag(int timer){
	return timerFlag[timer];
}
void timerRun(){
	// loop all element in timerArray, decrease by 1
	timerArray[0]--;
	timerArray[1]--;
	timerArray[2]--;
	timerArray[3]--;
	timerArray[4]--;
	timerArray[5]--;
	if(timerArray[0] <= 0){
		timerFlag[0] = 1;
	};
	if(timerArray[1] <= 0){
		timerFlag[1] = 1;
	};
	if(timerArray[2] <= 0){
		timerFlag[2] = 1;
	};
	if(timerArray[3] <= 0){
		timerFlag[3] = 1;
	};
	if(timerArray[4] <= 0){
		timerFlag[4] = 1;
	};
	if(timerArray[5] <= 0){
		timerFlag[5] = 1;
	};
};

