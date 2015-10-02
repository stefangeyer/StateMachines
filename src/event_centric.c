/*
 * event_centric.c
 *
 *  Created on: 01. Okt. 2015
 *      Author: Stefan
 */

#include "state_machine.h"

void traffic_light(traffic_light_data* t_light) {
	// the event changes after the led delay ran out.
	// you can check the led delays in the led_functions.c file
	switch (t_light->event) {
	case STOP:
		if (t_light->state == RED) {
			led_red();
			t_light->state = RED_YELLOW;
			t_light->event = PREPARE;
		} else {
			led_reset();
			t_light->event = ERR;
		}
		break;
	case PREPARE:
		if (t_light->state == RED_YELLOW) {
			led_red_yellow();
			t_light->state = GREEN;
			t_light->event = GO;
		} else {
			led_reset();
			t_light->event = ERR;
		}
		break;
	case GO:
		if (t_light->state == GREEN) {
			led_green();
			t_light->state = GREEN_BLINK;
			t_light->event = PREPARE2;
		} else {
			led_reset();
			t_light->event = ERR;
		}
		break;
	case PREPARE2:
		if (t_light->state == GREEN_BLINK) {
			if (t_light->blink_counter >= 4) {
				t_light->event = CAUTION;
				t_light->state = YELLOW;
				t_light->blink_counter = 0;
			} else {
				led_green_blink();
				t_light->blink_counter += 1;
			}
		} else {
			led_reset();
			t_light->event = ERR;
		}
		break;
	case CAUTION:
		if (t_light->state == YELLOW) {
			led_yellow();
			t_light->event = STOP;
			t_light->state = RED;
		}
		break;
	case ERR:
		led_yellow_blink();
		t_light->state = YELLOW_BLINK;
		break;
	default:
		t_light->event = STOP;
		t_light->state = RED;
		break;
	}
}
