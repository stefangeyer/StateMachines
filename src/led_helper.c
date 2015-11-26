#include "stm32f3xx.h"
#include "stm32f3_discovery.h"

#include "led_helper.h"

void led_reset() {
	led_red_off();
	led_orange_off();
	led_green_off();
}

void led_red_off() {
	BSP_LED_Off(LED_RED);
}

void led_orange_off() {
	BSP_LED_Off(LED_ORANGE);
}

void led_green_off() {
	BSP_LED_Off(LED_GREEN_2);
}

void toggle_led_red() {
	BSP_LED_Toggle(LED_RED);
}

void toggle_led_orange() {
	BSP_LED_Toggle(LED_ORANGE);
}

void toggle_led_green() {
	BSP_LED_Toggle(LED_GREEN_2);
}

void led_red() {
	led_reset();
	BSP_LED_On(LED_RED);
}

void led_yellow() {
	led_reset();
	BSP_LED_On(LED_ORANGE);
}

void led_green() {
	led_reset();
	BSP_LED_On(LED_GREEN_2);
}


void led_red_yellow() {
	led_reset();
	BSP_LED_On(LED_RED);
	BSP_LED_On(LED_ORANGE);
}


void led_yellow_blinking() {
	led_reset();
	BSP_LED_On(LED_ORANGE);
	BSP_LED_Off(LED_ORANGE);
}

void led_green_blinking() {
	led_reset();
	BSP_LED_On(LED_GREEN_2);
	BSP_LED_Off(LED_GREEN_2);
}
