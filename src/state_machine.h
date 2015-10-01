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
typedef enum {
	RED,
	RED_YELLOW,
	GREEN,
	GREEN_BLINK,
	YELLOW,
	YELLOW_BLINK
} traffic_state;

typedef enum {
	DAY,
	NIGHT
} system_mode;

// the structure where the current state is stored
typedef struct {
	traffic_state state;
} traffic_light_data;

void traffic_light(traffic_light_data* t_light);

#endif /* STATE_MACHINE */
