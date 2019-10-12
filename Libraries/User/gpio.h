#ifndef _GPIO_H_
#define _GPIO_H_
#include "stm32f0xx.h"          
#include "stm32f0xx_gpio.h"     // Pins Interface
/*----------------User definition------------------------*/
#define GPIO_PORT_A									GPIOA								// GPIO port = A													
#define GPIO_PORT_C 								GPIOC								// GPIO port = C
#define GPIO_PORT_B	 								GPIOB								// GPIO port = B

#define GPIO_MODE_OUTPUT						GPIO_Mode_OUT				
#define GPIO_MODE_INPUT							GPIO_Mode_IN
#define GPIO_MODE_AF								GPIO_Mode_AF
#define GPIO_MODE_ANALOG						GPIO_Mode_AN

#define GPIO_LOW_SPEED							GPIO_Speed_2MHz
#define GPIO_MED_SPEED							GPIO_Speed_10MHz
#define GPIO_HIGH_SPEED							GPIO_Speed_50MHz

#define GPIO_TYPE_OUTPUT_PUSHPULL		GPIO_OType_PP			
#define GPIO_TYPE_OUTPUT_OPENDRAIN	GPIO_OType_OD		

#define GPIO_TYPE_INPUT_FLOATING		GPIO_PuPd_NOPULL	
#define GPIO_TYPE_INPUT_PULLUP			GPIO_PuPd_UP
#define GPIO_TYPE_INPUT_PULLDOWN		GPIO_PuPd_DOWN	

#define BOARD_LED_PIN								GPIO_Pin_5
#define BOARD_LED_PORT							GPIOA

#define BOARD_BUTTON_PIN						GPIO_Pin_13
#define BOARD_BUTTON_PORT						GPIOC

/*-------------------------------------------------------------------*/
void gpio_configuration(void);
#endif
