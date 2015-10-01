/*
 * state_centric.c
 *
 *  Created on: 26. Sep. 2015
 *      Author: Stefan
 */

#include "state_machine.h"

void traffic_light(traffic_light_data* t_light) {
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
		led_green_blink();
		t_light->state = YELLOW;
		break;
	case YELLOW:
		led_yellow();
		t_light->state = RED;
		break;
	case YELLOW_BLINK:
		led_yellow_blink();
		t_light->state = RED;
		break;
	default:
		t_light->state = YELLOW_BLINK;
		break;
	}
}