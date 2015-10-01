/*
 * table_driven.c
 *
 *  Created on: 28. Sep. 2015
 *      Author: Stefan
 */

#include "state_machine.h"

typedef enum {
	kRedState = 0,
	kRedYellowState = 1,
	kGreenState = 2,
	kGreenBlinkState = 3,
	kYellowState = 4,
	kYellowBlinkState = 5
} tState;

struct sStateTableEntry {
	traffic_state state;
	tState go;
	tState stop;
	tState error;
};

struct sStateTableEntry stateTable[] = {
//State             Go	                    Stop
{ RED,				kRedYellowState,		kRedYellowState, 		kYellowBlinkState},
{ RED_YELLOW,		kGreenState, 			kGreenState, 			kYellowBlinkState},
{ GREEN,			kGreenBlinkState,		kGreenBlinkState, 		kYellowBlinkState},
{ GREEN_BLINK,		kGreenBlinkState,		kYellowState, 			kYellowBlinkState},
{ YELLOW, 			kRedState, 				kRedState, 				kYellowBlinkState},
{ YELLOW_BLINK,		kGreenBlinkState,		kRedState,			 	kYellowBlinkState},
};
