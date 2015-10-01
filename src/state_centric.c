/*
 * state_centric.c
 *
 *  Created on: 01. Okt. 2015
 *      Author: Stefan
 */

#include "state_machine.h"

void traffic_light(traffic_light_data* t_light) {
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
			t_light->event = CAUTION;
			led_green_blink();
			t_light->state = YELLOW;
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
		t_light->state = YELLOW_BLINK;
		break;
	}
}
