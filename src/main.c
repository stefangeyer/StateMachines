/**
 ******************************************************************************
 * @file		main.c
 * @author		Stefan Geyer
 * @version		1.0
 * @date		20151126
 * @brief		Main function to call the state machines
 *
 * This file calls the state machine if defined.
 * In this exercise, the code will be executed in a infinite loop
 *
 * @bug		No known bugs.
 ******************************************************************************
 */

#include "stm32f3xx.h"
#include "stm32f3_discovery.h"

#include "state_machine.h"

traffic_light_data t_light;

int main(void) {
	// Init the STM and its LEDs
	SystemInit();
	SystemCoreClockUpdate();

	SysTick_Config(SystemCoreClock / 1000);

	BSP_LED_Init(LED_RED);
	BSP_LED_Init(LED_ORANGE);
	BSP_LED_Init(LED_GREEN_2);

	traffic_light_data* p_t_light = &t_light;

	while (true) {
		traffic_light(p_t_light);
	}

	return EXIT_SUCCESS;
}
