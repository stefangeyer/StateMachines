/**
 ******************************************************************************
 * @file		led_functions.c
 * @author		Stefan Geyer
 * @version		1.0
 * @date		20151126
 * @brief		The functions that change the state of the leds
 *
 * Multiple functions were defined to change the led state. One resets all leds,
 * the other set a specific state.
 *
 * @bug		No known bugs.
 ******************************************************************************
 */

#include "stm32f3xx.h"
#include "stm32f3_discovery.h"

#include "led_functions.h"

void led_reset() {
	BSP_LED_Off(LED_RED);
	BSP_LED_Off(LED_ORANGE);
	BSP_LED_Off(LED_GREEN_2);
}

void led_red() {
	led_reset();
	BSP_LED_On(LED_RED);
	HAL_Delay(2000);
}

void led_red_yellow() {
	led_reset();
	BSP_LED_On(LED_RED);
	BSP_LED_On(LED_ORANGE);
	HAL_Delay(2000);
}

void led_green() {
	led_reset();
	BSP_LED_On(LED_GREEN_2);
	HAL_Delay(2000);
}

void led_green_blink() {
	led_reset();

	BSP_LED_On(LED_GREEN_2);
	HAL_Delay(500);
	BSP_LED_Off(LED_GREEN_2);
	HAL_Delay(500);
}

void led_yellow() {
	led_reset();
	BSP_LED_On(LED_ORANGE);
	HAL_Delay(2000);
}

void led_yellow_blink() {
	led_reset();

	BSP_LED_On(LED_ORANGE);
	HAL_Delay(500);
	BSP_LED_Off(LED_ORANGE);
	HAL_Delay(500);
}
