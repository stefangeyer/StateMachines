/**
 ******************************************************************************
 * @file		state.h
 * @author		Stefan Geyer
 * @version		1.0
 * @date		20151126
 * @brief		Includes related libs, defines prototypes and enums.
 *
 * @bug		No known bugs.
 ******************************************************************************
 */
#ifndef STATE
#define STATE

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "led_helper.h"

typedef enum {
	RED,
	YELLOW,
	GREEN,
	RED_YELLOW,
	GREEN_BLINKING,
	YELLOW_BLINKING
} trafficlight_state;

/**
 * @brief		This enum defines the available events
 *
 * The different events
 */
typedef enum {
	// yellow-red
	STOP,						/**< Event for RED*/
	// red-red yellow
	PREPARE,					/**< Event for RED-YELLOW*/
	// yellow-red green
	GO,							/**< Event for GREEN*/
	// green-blinking green
	PREPARE2,					/**< Event for GREEN-BLINK*/
	// blinking green-yellow
	CAUTION,					/**< Event for YELLOW*/
	// error state
	ERR							/**< Event for YELLOW-BLINK*/
} trafficlight_event;

/**
 * @brief		This struct contains all the data that is used within the execution
 *
 * This struct contains the event, state, blink_counter and interruped
 */
typedef struct {
	trafficlight_state state;
	trafficlight_event event;
	int blink_counter;
	bool interrupted;
	bool night;
} trafficlight_data;

/**
 * @brief Computes the next traffic_light state.
 *
 * There are several implementations for this method
 *
 * @param t_light The struct that contains the data
 * @retval void None
 */
void trafficlight(trafficlight_data* t_light);

#endif /* STATE_MACHINE */
