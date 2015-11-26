/*
 * led_functions.h
 *
 *  Created on: 26. Sep. 2015
 *      Author: Stefan
 */

#ifndef LED_FUNCTIONS_H_
#define LED_FUNCTIONS_H_

void led_reset();

void led_red();
void led_red_yellow();
void led_green();
void led_green_toggle();
void led_green_blink();
void led_yellow();
void led_yellow_toggle();
void led_yellow_blink();

void set_delay(int delay);
int get_delay();

#endif /* LED_FUNCTIONS_H_ */
