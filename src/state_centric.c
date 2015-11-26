/**
 ******************************************************************************
 * @file		state_centric.c
 * @author		Stefan Geyer
 * @version		1.0
 * @date		20151126
 * @brief		State centric state machine
 *
 * An state based implementation of the traffic_light
 * This can be used if there are a lot of states but less events.
 *
 * @bug		No known bugs.
 ******************************************************************************
 */

#include "state.h"
#include "led_helper.h"
#include <stdbool.h>

void trafficlight(trafficlight_data* t_light) {
	// counter for timer interrupts
	static int counter = 0;
	// increment counter to be able to know how long we have waited
	counter++;
	switch (t_light->state) {
	case RED:
		// if night state was activated, switch to yellow blinking
		if (t_light->night) {
			led_green_off();
			led_red_off();
			t_light->state = YELLOW_BLINKING;
			t_light->event = ERR;
		}
		if (t_light->event == STOP) {
			// turn on red led
			led_red();
			// wait until counter reached 2000 = 2 secs
			// then proceed to next state
			if (counter >= 2000) {
				counter = 0;
				t_light->event = PREPARE;
				t_light->state = RED_YELLOW;
			}
		}
		break;
	case RED_YELLOW:
		if (t_light->event == PREPARE) {
			led_red_yellow();
			// see case RED
			if (counter >= 1600) {
				counter = 0;
				t_light->event = GO;
				t_light->state = GREEN;
			}
		}
		break;
	case GREEN:
		if (t_light->event == GO) {
			led_green();
			// see case RED
			if (counter >= 2000) {
				counter = 0;
				t_light->event = PREPARE2;
				t_light->state = GREEN_BLINKING;
			}
		}
		break;
	case GREEN_BLINKING:
		if (t_light->event == PREPARE2) {
			if (t_light->blink_counter >= 9) {
				t_light->blink_counter = 0;
				t_light->event = CAUTION;
				t_light->state = YELLOW;
			} else {
				// toogle green led every 500ms
				if (counter >= 500) {
					counter = 0;
					t_light->blink_counter += 1;
					toggle_led_green();
				}
			}
		}
		break;
	case YELLOW:
		if (t_light->event == CAUTION) {
			led_yellow();
			if (counter >= 1800) {
				counter = 0;
				t_light->state = RED;
				t_light->event = STOP;
			}
		}
		break;
	case YELLOW_BLINKING:
		// night state
		t_light->state = YELLOW_BLINKING;
		if (counter >= 500) {
			counter = 0;
			toggle_led_orange();
		}
		break;
	default:
		t_light->state = RED;
		t_light->event = STOP;
		break;
	}
}
