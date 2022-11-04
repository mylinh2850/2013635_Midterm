/*
 * display7SEG.h
 *
 *  Created on: Nov 1, 2022
 *      Author: Linh
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "main.h"
#include "global.h"
#include "software_timer.h"

void display7SEG1(int num);
void display7SEG2(int num);

void update7SEG1(int index);
void update7SEG2(int index);

void mode1_control();


#endif /* INC_DISPLAY7SEG_H_ */
