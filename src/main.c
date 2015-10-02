/**
 ******************************************************************************
 * @file    main.c
 * @author  sgeyer
 * @version 20150926.1
 * @date    2015/09/26
 ******************************************************************************
 */

#include "stm32f3xx.h"
#include "stm32f3_discovery.h"

#include "state_machine.h"

void EXTI0_Config();
void check_for_mode_change();

traffic_light_data t_light;

int main(void) {
	// Init the STM and its LEDs
	SystemInit();
	SystemCoreClockUpdate();

	SysTick_Config(SystemCoreClock / 1000);

	BSP_LED_Init(LED_RED);
	BSP_LED_Init(LED_ORANGE);
	BSP_LED_Init(LED_GREEN_2);

	EXTI0_Config();

	traffic_light_data* p_t_light = &t_light;

	while (true) {
		check_for_mode_change();
		traffic_light(p_t_light);
	}

	return EXIT_SUCCESS;
}

void check_for_mode_change() {
	if (t_light.interrupted && (t_light.state == RED || t_light.state == YELLOW_BLINK)) {
		if (t_light.state == YELLOW_BLINK) {
			t_light.state = RED;
			t_light.event = STOP;
		} else {
			t_light.state = YELLOW_BLINK;
			t_light.event = ERR;
		}

		t_light.interrupted = false;
	}
}

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

/**
 * @brief EXTI line detection callbacks
 * @param GPIO_Pin: Specifies the pins connected EXTI line
 * @retval None
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == USER_BUTTON_PIN) {
		t_light.interrupted = true;
	}
}

