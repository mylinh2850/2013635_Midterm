/*
 * setTrafficLight.c
 *
 *  Created on: Nov 1, 2022
 *      Author: Linh
 */


#include "setTrafficLight.h"

void setDefault1() {
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
}

void setDefault2() {
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);
	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
}

void setRed1Light() {
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
}

void setGreen1Light() {
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
}

void setYellow1Light() {
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
}

void setRed2Light() {
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, SET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);
	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
}

void setGreen2Light() {
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
}

void setYellow2Light() {
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);
	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, SET);
}
