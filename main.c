/**
 *****************************************************************************
 * @defgroup	Project
 * @brief		Project related code
 * @{
 *
 * @file		main.c
 * @version		1.0
 * @date		2013-11-22
 * @author		rct1
 *
 * @brief		main.c template
 *
 */

/*----- Header-Files -------------------------------------------------------*/
#include <stm32f4xx.h>				/* Processor STM32F407IG				*/
#include <lcd.h>
#include <carme_io2.h>
#include <uart.h>

#include <stdio.h>
#include <string.h>

#include "game.h"

/*----- Macros -------------------------------------------------------------*/
#define INT_PER_SEC			1000	/**< SysTick interrupts per second		*/



enum STATE {STATE_INPUT, STATE_MOVMENT, STATE_GUI, STATE_RS232, STATE__COUNT};


/*----- Data types ---------------------------------------------------------*/
int statemachine = STATE_INPUT;
/*----- Function prototypes ------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/
static __IO uint32_t TimingDelay;

/*----- Implementation -----------------------------------------------------*/
/**
 * @brief		This function waits for nTime / INT_PER_SEC seconds.
 *
 * @param[in]	nTime	Time to wait
 */
void Delay(__IO uint32_t nTime) {
	TimingDelay = nTime;
	while (TimingDelay != 0);
}

/**
 * @brief		SysTick interrupt handler
 */
void SysTick_Handler(void) {
	if (TimingDelay) {
		TimingDelay--;
	}
}

unsigned int read_Poti()
{
	unsigned int adc;
	CARME_IO2_ADC_Get(CARME_IO2_ADC_PORT0, &adc); //ADC Wert von Poit lesen
	return adc;
}
/**
 * @brief		main
 * @return		0 if success
 */
int main(void)
{


	LCD_Init();
	CARME_IO2_Init();

	if (SysTick_Config(SystemCoreClock / INT_PER_SEC)) {
		while (1);
	}


	while(1)
	{
		switch(statemachine)
		{
			case(STATE_INPUT):
			{

				LCD_DisplayStringXY(40, 120, "1");
				break;
			}
			case(STATE_MOVMENT):
			{
				LCD_DisplayStringXY(40, 120, "2");
				break;
			}
			case(STATE_RS232):
			{
				LCD_DisplayStringXY(40, 120, "3");
				break;
			}
			case(STATE_GUI):
			{
				LCD_DisplayStringXY(40, 120, "4");
				break;
			}
		}
		statemachine++;

		if(statemachine >= STATE__COUNT)
			statemachine = STATE_INPUT;


		Delay(2000);
	}

	return 0;
}


