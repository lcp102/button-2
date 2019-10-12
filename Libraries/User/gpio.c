#include "gpio.h"

void gpio_configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_StructInit(&GPIO_InitStruct);								 //Fills GPIO_InitStruct members with its default value
	
	GPIO_InitStruct.GPIO_Pin = BOARD_LED_PIN;         
	GPIO_InitStruct.GPIO_Mode = GPIO_MODE_OUTPUT;      
	GPIO_InitStruct.GPIO_Speed = GPIO_HIGH_SPEED;  				 
	GPIO_InitStruct.GPIO_OType = GPIO_TYPE_OUTPUT_PUSHPULL;       
	GPIO_Init(BOARD_LED_PORT, &GPIO_InitStruct);  
	
	GPIO_InitStruct.GPIO_Pin = BOARD_BUTTON_PIN;         
	GPIO_InitStruct.GPIO_Mode = GPIO_MODE_INPUT;      
	GPIO_InitStruct.GPIO_Speed = GPIO_HIGH_SPEED;  				 
	GPIO_InitStruct.GPIO_PuPd = GPIO_TYPE_INPUT_PULLUP;
	GPIO_Init(BOARD_BUTTON_PORT, &GPIO_InitStruct);  
}
