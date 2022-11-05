/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Linh
 */

#include "fsm_simple_buttons.h"

void fsm_simple_buttons_run() {
	//Led toggle every 0.5s
	if (timer1_flag == 1) {
		setTimer1(500);
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	}

	switch (status) {
	case INIT:
		status = AUTO;
		counter = 9;
		display7SEG(counter);
		break;

	case RST:
		if (isButtonPressed(0) == 1) {
			//RESET button is pressed
			status = RST;
			setTimer2(10000);
			counter = 0;
			display7SEG(counter);
		} else if (isButtonPressed(1) == 1) {
			//INC button is pressed
			status = INC;
			setTimer2(10000);
			counter++;
			if (counter > 9)
				counter = 0;
			display7SEG(counter);
		} else if (isButtonPressed(2) == 1) {
			//DEC button is pressed
			status = DEC;
			setTimer2(10000);
			counter--;
			if (counter < 0)
				counter = 9;
			display7SEG(counter);
		} else if (timer2_flag == 1) {
			status = AUTO;
			setTimer3(1000);
			display7SEG(counter);
			counter--;
			if (counter < 0)
				counter = 0;
		}
		break;

	case INC:
		if (isButtonPressed(0) == 1) {
			//RESET button is pressed
			status = RST;
			setTimer2(10000);
			counter = 0;
			display7SEG(counter);
		} else if (isButtonPressed(1) == 1) {
			//INC button is pressed
			status = INC;
			setTimer2(10000);
			counter++;
			if (counter > 9)
				counter = 0;
			display7SEG(counter);
		} else if (isButtonPressed(2) == 1) {
			//DEC button is pressed
			status = DEC;
			setTimer2(10000);
			counter--;
			if (counter < 0)
				counter = 9;
			display7SEG(counter);
		} else if (timer2_flag == 1) {
			status = AUTO;
			setTimer3(1000);
			display7SEG(counter);
			counter--;
			if (counter < 0)
				counter = 0;
		}
		break;

	case DEC:
		if (isButtonPressed(0) == 1) {
			//RESET button is pressed
			status = RST;
			setTimer2(10000);
			counter = 0;
			display7SEG(counter);
		} else if (isButtonPressed(1) == 1) {
			//INC button is pressed
			status = INC;
			setTimer2(10000);
			counter++;
			if (counter > 9)
				counter = 0;
			display7SEG(counter);
		} else if (isButtonPressed(2) == 1) {
			//DEC button is pressed
			status = DEC;
			setTimer2(10000);
			counter--;
			if (counter < 0)
				counter = 9;
			display7SEG(counter);
		} else if (timer2_flag == 1) {
			status = AUTO;
			setTimer3(1000);
			display7SEG(counter);
			counter--;
			if (counter < 0)
				counter = 0;
		}
		break;

	case AUTO:
		if (timer3_flag == 1) {
			setTimer3(1000);
			display7SEG(counter);
			counter--;
			if (counter < 0)
				counter = 0;
		}

		if (isButtonPressed(0) == 1) {
			//RESET button is pressed
			status = RST;
			setTimer2(10000);
			counter = 0;
			display7SEG(counter);
		} else if (isButtonPressed(1) == 1) {
			//INC button is pressed
			status = INC;
			setTimer2(10000);
			counter++;
			if (counter > 9)
				counter = 0;
			display7SEG(counter);
		} else if (isButtonPressed(2) == 1) {
			//DEC button is pressed
			status = DEC;
			setTimer2(10000);
			counter--;
			if (counter < 0)
				counter = 9;
			display7SEG(counter);
		}

	default:
		break;
	}
}
