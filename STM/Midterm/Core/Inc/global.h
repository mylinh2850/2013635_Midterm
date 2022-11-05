/*
 * global.h
 *
 *  Created on: Nov 1, 2022
 *      Author: Linh
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button.h"
#include "software_timer.h"
#include "display7SEG.h"
#include "fsm_simple_buttons.h"

#define INIT		1
#define RST			2
#define INC			3
#define DEC			4
#define AUTO		5


extern int status;
extern int counter;


#endif /* INC_GLOBAL_H_ */
