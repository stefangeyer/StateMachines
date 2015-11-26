/*
 * led_functions.h
 *
 *  Created on: 26. Sep. 2015
 *      Author: Stefan
 */

#ifndef LED_FUNCTIONS_H_
#define LED_FUNCTIONS_H_

/**
 * @brief Resets all leds
 *
 * Turns all the leds off no matter if they are on or off
 *
 * @retval void None
 */
void led_reset();

/**
 * @brief Enable the red led
 *
 * @retval void None
 */
void led_red();

/**
 * @brief Enable the yellow led
 *
 * @retval void None
 */
void led_red_yellow();

/**
 * @brief Enable the green led
 *
 * @retval void None
 */
void led_green();

/**
 * @brief Enable the green blink led
 *
 * @param None
 * @retval void None
 */
void led_green_blink();

/**
 * @brief Enable the yellow led
 *
 * @retval void None
 */
void led_yellow();

/**
 * @brief Enable the yellow blink led
 *
 * @retval void None
 */
void led_yellow_blink();

#endif /* LED_FUNCTIONS_H_ */
