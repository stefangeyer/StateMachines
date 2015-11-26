/**
 ******************************************************************************
 * @file		led_helper.c
 * @author		Stefan Geyer
 * @version		1.0
 * @date		20151126
 * @brief		LED Functions
 *
 * These methods change the pysical state of the leds
 *
 * @bug		No known bugs.
 ******************************************************************************
 */
#ifndef LED_HELPER_H_
#define LED_HELPER_H_

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
void led_yellow();

/**
 * @brief Enable the green led
 *
 * @retval void None
 */
void led_green();

/**
 * @brief Enable the yellow led
 *
 * @retval void None
 */
void led_red_yellow();

/**
 * @brief Enable the green blink led
 *
 * @retval void None
 */
void led_green_blinking();

/**
 * @brief Enable the yellow blink led
 *
 * @retval void None
 */
void led_yellow_blinking();

/**
 * @brief Resets all leds
 *
 * Turns all the leds off no matter if they are on or off
 *
 * @retval void None
 */
void led_reset();

/**
 * @brief Resets leds
 *
 * Turns all the red leds off no matter if they are on or off
 *
 * @retval void None
 */
void led_red_off();

/**
 * @brief Resets leds
 *
 * Turns all the orange leds off no matter if they are on or off
 *
 * @retval void None
 */
void led_orange_off();

/**
 * @brief Resets leds
 *
 * Turns all the green leds off no matter if they are on or off
 *
 * @retval void None
 */
void led_green_off();

void toggle_led_red();
void toggle_led_orange();
void toggle_led_green();

#endif /* LED_HELPER_H_ */
