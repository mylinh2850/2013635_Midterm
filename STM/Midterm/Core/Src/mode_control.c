/*
 * mode_control.c
 *
 *  Created on: Nov 2, 2022
 *      Author: Linh
 */

#include "mode_control.h"

void normal_mode() {

	if (timeCounter == 0) {
		timeCounter = 100;
		if (counter == 0) {
			counter = redTime + greenTime + yellowTime;
		}

		if (counter == redTime + greenTime + yellowTime) {
			//Red1 led and Green2 led on.
			//Red1 led
			setRed1Light();
			time1_display = redTime;
			//Green2 led
			setGreen2Light();
			time2_display = greenTime;
		}

		else if (counter == redTime + yellowTime) {
			//Red1 led and Yellow2 led on.
			//Yellow2 led
			setYellow2Light();
			time2_display = yellowTime;
		}

		else if (counter == greenTime + yellowTime) {
			//Green1 led and Red2 led on.
			//Green1 led
			setGreen1Light();
			time1_display = greenTime;
			//Red2 led
			setRed2Light();
			time2_display = redTime;
		}

		else if (counter == yellowTime) {
			//Yellow1 led and Red2 led on.
			//Yellow1 led
			setYellow1Light();
			time1_display = yellowTime;
		}

		counter--;
	}

	if (timeCounter == 100) {
		update7SEG1(0);
		update7SEG2(0);
	}

	else if (timeCounter == 50) {
		update7SEG1(1);
		update7SEG2(1);

		time1_display--;
		time2_display--;
	}

	timeCounter--;
}

void mode1_control() {
	if (isButton1Pressed() == 1) {
		modeCounter++;
		if (modeCounter > 4) {
			modeCounter = 1;
		}
	}

	switch (modeCounter) {
	case 1:
		normal_mode();
		break;
	case 2:
		mode2_control();
		break;
	case 3:
		mode3_control();
		break;
	case 4:
		mode4_control();
		break;
	default:
		break;
	}
}

void mode2_control() {
	time2_display = 2;

	if (isButton2Pressed() == 1) {
		red_temp++;
		time1_display++;
		if (red_temp > 99 || time1_display > 99) {
			red_temp = 1;
			time1_display = 1;
		}
	}

	if (isButton3Pressed() == 1)
	{
		redTime = red_temp;
		counter = red_temp + green_temp + yellow_temp;
	}

	if (timeCounter == 0) {
		timeCounter = 100;
	}

	if (timeCounter == 100 || timeCounter == 50) {
		HAL_GPIO_TogglePin(R1_GPIO_Port, R1_Pin);
		HAL_GPIO_TogglePin(R2_GPIO_Port, R2_Pin);

		if (timeCounter == 100) {
			update7SEG1(0);
			update7SEG2(0);
		} else if (timeCounter == 50) {
			update7SEG1(1);
			update7SEG2(1);
		}
	}



	timeCounter--;
}



void mode3_control() {
	time2_display = 3;

	if (isButton2Pressed() == 1) {
		yellow_temp++;
		time1_display++;
		if (yellow_temp > 99 || time1_display > 99) {
			yellow_temp = 1;
			time1_display = 1;
		}
	}

	if (isButton3Pressed() == 1)
	{
		yellowTime = yellow_temp;
		counter = red_temp + green_temp + yellow_temp;
	}

	if (timeCounter == 0) {
		timeCounter = 100;
	}

	if (timeCounter == 100 || timeCounter == 50) {
		HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin);
		HAL_GPIO_TogglePin(Y2_GPIO_Port, Y2_Pin);

		if (timeCounter == 100) {
			update7SEG1(0);
			update7SEG2(0);
		} else if (timeCounter == 50) {
			update7SEG1(1);
			update7SEG2(1);
		}
	}



	timeCounter--;
}


void mode4_control() {
	time2_display = 4;

	if (isButton2Pressed() == 1) {
		green_temp++;
		time1_display++;
		if (green_temp > 99 || time1_display > 99) {
			green_temp = 1;
			time1_display = 1;
		}
	}

	if (isButton3Pressed() == 1)
	{
		greenTime = green_temp;
		counter = red_temp + green_temp + yellow_temp;
	}

	if (timeCounter == 0) {
		timeCounter = 100;
	}

	if (timeCounter == 100 || timeCounter == 50) {
		HAL_GPIO_TogglePin(G1_GPIO_Port, G1_Pin);
		HAL_GPIO_TogglePin(G2_GPIO_Port, G2_Pin);

		if (timeCounter == 100) {
			update7SEG1(0);
			update7SEG2(0);
		} else if (timeCounter == 50) {
			update7SEG1(1);
			update7SEG2(1);
		}
	}



	timeCounter--;
}