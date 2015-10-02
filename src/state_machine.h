/*
 * state_machine.h
 *
 *  Created on: 26. Sep. 2015
 *      Author: Stefan
 */

#ifndef STATE_MACHINE
#define STATE_MACHINE

// include needed headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "led_functions.h"

// the enumeration for the different traffic light states
// states should be self explaining
typedef enum {
	RED,
	RED_YELLOW,
	GREEN,
	GREEN_BLINK,
	YELLOW,
	YELLOW_BLINK
} traffic_state;

typedef enum {
	// yellow to red
	STOP,
	// red to red-yellow
	PREPARE,
	// yellow-red to green
	GO,
	// green to green-blink
	PREPARE2,
	// green-blink to yellow
	CAUTION,
	// error state in case something goes wrong
	ERR
} traffic_event;

// the structure where the current state is stored
typedef struct {
	traffic_state state;
	traffic_event event;
	int blink_counter;
	bool interrupted;
} traffic_light_data;

void traffic_light(traffic_light_data* t_light);

#endif /* STATE_MACHINE */
