/**
 ******************************************************************************
 * @file		state_machine.h
 * @author		Stefan Geyer
 * @version		1.0
 * @date		20151126
 * @brief		Includes related libs, defines prototypes and enums.
 *
 * @bug		No known bugs.
 ******************************************************************************
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

/**
 * @brief		This enum defines the available events
 *
 * The different events
 */
typedef enum {
	// yellow to red
	STOP,											/**< Event for RED*/
	// red to red-yellow
	PREPARE,										/**< Event for RED-YELLOW*/
	// yellow-red to green
	GO,												/**< Event for GREEN*/
	// green to green-blink
	PREPARE2,										/**< Event for GREEN-BLINK*/
	// green-blink to yellow
	CAUTION,										/**< Event for YELLOW*/
	// error state in case something goes wrong
	ERR												/**< Event for YELLOW-BLINK*/
} traffic_event;

/**
 * @brief		This struct contains all the data that is used within the execution
 *
 * This struct contains the event, state, blink_counter and interruped
 */
typedef struct {
	traffic_state state;
	traffic_event event;
	int blink_counter;
	bool interrupted;
} traffic_light_data;

/**
 * @brief Computes the next traffic_light state.
 *
 * There are several implementations for this method
 *
 * @param t_light The struct that contains the data
 * @retval void None
 */
void traffic_light(traffic_light_data* t_light);

#endif /* STATE_MACHINE */
