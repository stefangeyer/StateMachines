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
#include "state.h"

void EXTI0_Config();
trafficlight_data t_light;
trafficlight_data* p_t_light;
int main(void) {
	SystemInit();
	SystemCoreClockUpdate();

	SysTick_Config(SystemCoreClock / 1000);

	BSP_LED_Init(LED_RED);
	BSP_LED_Init(LED_ORANGE);
	BSP_LED_Init(LED_GREEN_2);

	EXTI0_Config();
	p_t_light = &t_light;

	// setting default states
	p_t_light->event = STOP;
	p_t_light->state = RED;
	p_t_light->blink_counter = 0;
	p_t_light->night = false;

	return EXIT_SUCCESS;
}

// configure interrupts
void EXTI0_Config(void) {
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable GPIOA clock */
	__GPIOA_CLK_ENABLE();

	/* Configure User Button, connected to PE6 IOs in External Interrupt Mode with Rising edge trigger detection. */
	GPIO_InitStructure.Pin = GPIO_PIN_0;
	GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Enable and set EXTI0 Interrupt to the lowest priority */
	HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

// interrupt callback
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	// gets called when user button is pressed
	if (GPIO_Pin == USER_BUTTON_PIN) {
		t_light.interrupted = true;
		if (t_light.interrupted) {
			// if night state is active, switch back to normal states
			if (t_light.state == YELLOW_BLINKING && p_t_light->night == true) {
				p_t_light->night = false;
				p_t_light->state = RED;
				p_t_light->event = STOP;
			} else {
				// activate night state
				p_t_light->night = true;
			}
			t_light.interrupted = false;
		}
	}
}

// this function is called every millisecond
void HAL_SYSTICK_Callback(void) {
	trafficlight(p_t_light);
}

