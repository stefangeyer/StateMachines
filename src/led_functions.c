/*
 * led_functions.c
 *
 *  Created on: 26. Sep. 2015
 *      Author: Stefan
 */

#include "stm32f3xx.h"
#include "stm32f3_discovery.h"

#include "led_functions.h"

int delay = 0;

void led_reset() {
	BSP_LED_Off(LED_RED);
	BSP_LED_Off(LED_ORANGE);
	BSP_LED_Off(LED_GREEN_2);
}

void led_red() {
	led_reset();
	BSP_LED_On(LED_RED);
	set_delay(2000);
}

void led_red_yellow() {
	led_reset();
	BSP_LED_On(LED_RED);
	BSP_LED_On(LED_ORANGE);
	set_delay(2000);
}

void led_green() {
	led_reset();
	BSP_LED_On(LED_GREEN_2);
	set_delay(2000);
}

void led_green_toggle() {
	led_reset();

	BSP_LED_Toggle(LED_GREEN_2);
	set_delay(500);
}

void led_green_blink() {
	led_reset();

	BSP_LED_On(LED_GREEN_2);
	HAL_Delay(500);
	BSP_LED_Off(LED_GREEN_2);
	set_delay(500);
}

void led_yellow() {
	led_reset();
	BSP_LED_On(LED_ORANGE);
	set_delay(2000);
}

void led_yellow_toggle() {
	led_reset();

	BSP_LED_Toggle(LED_ORANGE);
}

void led_yellow_blink() {
	led_reset();

	BSP_LED_On(LED_ORANGE);
	HAL_Delay(500);
	BSP_LED_Off(LED_ORANGE);
	set_delay(500);
}

void set_delay(int d) {
	delay = d;
}

int get_delay() {
	return delay;
}
