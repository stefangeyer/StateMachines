/*
 * table_driven.c
 *
 *  Created on: 28. Sep. 2015
 *      Author: Stefan
 *
 *  BUGGY!!!
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
	traffic_state light; // all states have associated lights
	tState goEvent; // state to enter when go event occurs
	tState stopEvent; // ... when stop event occurs
	tState timeoutEvent; // ... when timeout occurs
};

struct sStateTableEntry stateTable[] = {
//State             Go	                    Stop					Timeout
{ RED,				kRedYellowState,		kRedYellowState, 		kYellowBlinkState},
{ RED_YELLOW,		kGreenState, 			kGreenState, 			kYellowBlinkState},
{ GREEN,			kGreenBlinkState,		kGreenBlinkState, 		kYellowBlinkState},
{ GREEN_BLINK,		kGreenBlinkState,		kYellowState, 			kYellowBlinkState},
{ YELLOW, 			kRedState, 				kRedState, 				kYellowBlinkState},
{ YELLOW_BLINK,		kGreenBlinkState,		kRedState,			 	kYellowBlinkState},
};

/**
 * Will set the state and execute the matching led function
 */
void switch_state(traffic_state new_state, traffic_light_data* data) {
	data->state = new_state;
	switch(new_state) {
	case RED:
		led_red();
		break;
	case RED_YELLOW:
		led_red_yellow();
		break;
	case GREEN:
		led_green();
		break;
	case GREEN_BLINK:
		led_green_blink();
		break;
	case YELLOW:
		led_yellow();
		break;
	case YELLOW_BLINK:
		led_yellow_blink();
	}
}

void table_driven(traffic_light_data* t_light, struct sStateTableEntry *currentState, int* i)
{
	//switch_state(currentState->light, t_light);

	if(*i%9 == 0) {
		*currentState = *&stateTable[currentState->stopEvent];
		//*i = 1;
	} else {
		*currentState = *&stateTable[currentState->goEvent];
		if(currentState->light == GREEN_BLINK) {
			*i += 1;
		}
	}

	switch_state(currentState->light, t_light);
}

int main(int argn, char** argv) {
	traffic_light_data data;

	traffic_light_data* data_pointer = &data;
	int i = 1;
	int* i_p = &i;
	struct sStateTableEntry *currentState = &stateTable[4];

	data_pointer->state = currentState->light;

	while(1)
	{
		table_driven(data_pointer, currentState, i_p);
	}


	return EXIT_SUCCESS;
}
