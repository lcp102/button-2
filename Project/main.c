/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private typedef -----------------------------------------------------------*/
#define DEBOUNCE_TIMEOUT  10   //in milliseconds
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t t0 = 0, t1 = 0;
uint8_t current_state = 0, prev_state = 0;
uint8_t pin_state;
/* Private function prototypes -----------------------------------------------*/
void toggle(void);
/* Private functions ---------------------------------------------------------*/
/**
  * @brief 	Button debouncing using state machine
  * @param  None
  * @retval None
  */
int main(void)
{

  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f0xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f0xx.c file
     */ 
      
  /* Add your application code here
     */
	clock_configuration();
	SysTick_Init();
	gpio_configuration();
  /* Infinite loop */
  while (1)
  {
	switch(current_state)
	{
		case 0: //RESTART
			current_state = 1;
			break;

		case 1:	//START
			pin_state = GPIO_ReadInputDataBit(BOARD_BUTTON_PORT,BOARD_BUTTON_PIN);
			if (pin_state == 0)
			{
				current_state = 2;
			}
			break;

		case 2: //SET TIMER
			t0 = get_millis();
			current_state = 3;
			break;

		case 3:	//WAIT
			pin_state = GPIO_ReadInputDataBit(BOARD_BUTTON_PORT, BOARD_BUTTON_PIN);
			if (pin_state)
			{
				current_state = 0;
				break;
			}
			t1 = get_millis();
			if ((t1 - t0) > DEBOUNCE_TIMEOUT)
			{
				current_state = 4;
			}
			break;

		case 4: //DETECTION
			pin_state = GPIO_ReadInputDataBit(BOARD_BUTTON_PORT, BOARD_BUTTON_PIN);
			if (pin_state)
			{
				toggle();
				current_state = 0;
			}
			break;
	}
  }
}

void toggle(void)
{
	static BitAction led_state = Bit_RESET;
	
	led_state = !led_state;
	GPIO_WriteBit(BOARD_LED_PORT, BOARD_LED_PIN, led_state = led_state ? Bit_SET : Bit_RESET);
}
#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*****END OF FILE****/
