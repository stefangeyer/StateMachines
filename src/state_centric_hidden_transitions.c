/*
 * state_centric.c
 *
 *  Created on: 26. Sep. 2015
 *      Author: Stefan
 */

#include "state_machine.h"

void traffic_light2(traffic_light_data* t_light) {
	switch (t_light->state) {
	case RED:
		led_red();
		t_light->state = RED_YELLOW;
		break;
	case RED_YELLOW:
		led_red_yellow();
		t_light->state = GREEN;
		break;
	case GREEN:
		led_green();
		t_light->state = GREEN_BLINK;
		break;
	case GREEN_BLINK:
		if (t_light->blink_counter >= 4) {
			t_light->state = YELLOW;
			t_light->blink_counter = 0;
		} else {
			led_green_blink();
			t_light->blink_counter += 1;
		}
		break;
	case YELLOW:
		led_yellow();
		t_light->state = RED;
		break;
	case YELLOW_BLINK:
		led_yellow_blink();
		t_light->state = YELLOW_BLINK;
		break;
	default:
		t_light->state = RED;
		break;
	}
}
