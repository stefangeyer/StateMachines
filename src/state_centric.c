/*
 * state_centric.c
 *
 *  Created on: 01. Okt. 2015
 *      Author: Stefan
 */

#include "state_machine.h"

void traffic_light1(traffic_light_data* t_light) {
	// the event changes after the led delay ran out.
	// you can check the led delays in the led_functions.c file
	switch (t_light->state) {
	case RED:
		if (t_light->event == STOP) {
			t_light->event = PREPARE;
			led_red();
			t_light->state = RED_YELLOW;
		}
		break;
	case RED_YELLOW:
		if (t_light->event == PREPARE) {
			t_light->event = GO;
			led_red_yellow();
			t_light->state = GREEN;
		}
		break;
	case GREEN:
		if (t_light->event == GO) {
			t_light->event = PREPARE2;
			led_green();
			t_light->state = GREEN_BLINK;
		}
		break;
	case GREEN_BLINK:
		if (t_light->event == PREPARE2) {
			if (t_light->blink_counter >= 4) {
				t_light->event = CAUTION;
				t_light->state = YELLOW;
				t_light->blink_counter = 0;
			} else {
				led_green_blink();
				t_light->blink_counter += 1;
			}
		}
		break;
	case YELLOW:
		if (t_light->event == CAUTION) {
			t_light->event = STOP;
			led_yellow();
			t_light->state = RED;
		}
		break;
	case YELLOW_BLINK:
		led_yellow_blink();
		t_light->state = YELLOW_BLINK;
		break;
	default:
		t_light->state = RED;
		t_light->event = STOP;
		break;
	}
}
