/*
 * fsm_automatic.c
 *
 *  Created on: Nov 1, 2022
 *      Author: Linh
 */

#include "fsm_automatic.h"

void fsm_automatic1_run() {
	switch (status1) {
	case INIT:
		//TODO
		setDefault1();

		status1 = AUTO_RED;
		setTimer1(5000);
		break;
	case AUTO_RED:
		//TODO
		setRed1Light();
		mode1_control();

		if (timer1_flag == 1) {
			setTimer1(3000);
			status1 = AUTO_GREEN;
		}
		if (isButton1Pressed() == 1) {
			setTimer1(10000);
			status1 = MAN_RED;
		}
		if (isButton2Pressed() == 1) {
			setTimer1(10000);
			status1 = MAN_RED;
		}
		break;
	case AUTO_GREEN:
		//TODO
		setGreen1Light();

		if (timer1_flag == 1) {
			setTimer1(2000);
			status1 = AUTO_YELLOW;
		}
		break;
	case AUTO_YELLOW:
		//TODO
		setYellow1Light();


		if (timer1_flag == 1) {
			setTimer1(5000);
			status1 = AUTO_RED;
		}
		break;
	default:
		break;
	}
}

void fsm_automatic2_run() {
	switch (status2) {
	case INIT:
		//TODO
		setDefault2();

		status2 = AUTO_GREEN;
		setTimer3(3000);
		break;
	case AUTO_RED:
		//TODO
		setRed2Light();

		if (timer3_flag == 1) {
			setTimer3(3000);
			status2 = AUTO_GREEN;
		}
		if (isButton1Pressed() == 1) {
			setTimer3(10000);
			status2 = MAN_RED;
		}
		if (isButton2Pressed() == 1) {
			setTimer3(10000);
			status2 = MAN_RED;
		}
		break;
	case AUTO_GREEN:
		//TODO
		setGreen2Light();

		if (timer3_flag == 1) {
			setTimer3(2000);
			status2 = AUTO_YELLOW;
		}
		break;
	case AUTO_YELLOW:
		//TODO
		setYellow2Light();


		if (timer3_flag == 1) {
			setTimer3(5000);
			status2 = AUTO_RED;
		}
		break;
	default:
		break;
	}
}

