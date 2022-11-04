/*
 * fsm_manual.c
 *
 *  Created on: Nov 1, 2022
 *      Author: Linh
 */


#include "fsm_manual.h"

void fsm_manual_run() {
	switch (status1) {
	case MAN_RED:
		//TODO
		setRed1Light();

		if (timer1_flag == 1) {
			setTimer1(5000);
			status1 = AUTO_RED;
		}
		if (isButton1Pressed() == 1) {
			setTimer1(10000);
			status1 = MAN_GREEN;
		}
		if (isButton2Pressed() == 1) {
			setTimer2(10000);
			status1 = MAN_YELLOW;
		}
		break;
	case MAN_GREEN:
		//TODO
		setGreen1Light();

		if (timer1_flag == 1) {
			setTimer1(3000);
			status1 = AUTO_GREEN;
		}
		if (isButton1Pressed() == 1) {
			setTimer1(10000);
			status1 = MAN_YELLOW;
		}
		if (isButton2Pressed() == 1) {
			setTimer2(10000);
			status1 = MAN_RED;
		}
		break;
	case MAN_YELLOW:
		//TODO
		setYellow1Light();

		if (timer1_flag == 1) {
			setTimer1(2000);
			status1 = AUTO_YELLOW;
		}
		if (isButton1Pressed() == 1) {
			setTimer1(10000);
			status1 = MAN_RED;
		}
		if (isButton2Pressed() == 1) {
			setTimer2(10000);
			status1 = MAN_GREEN;
		}
		break;
	default:
		break;
	}
}
