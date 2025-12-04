/*
 * main.c
 *
 *  Created on: Dec 3, 2025
 *      Author: med08
 */

//Header File
#include "main.h"

//Defines
#define btn_up GPIO_PIN_8
#define btn_down GPIO_PIN_9
#define HIGH GPIO_PIN_SET
#define LOW GPIO_PIN_RESET

//Variables Initialization
unsigned int countup = 0;
unsigned int countdown = 0x1F;
unsigned int sequenceval =4;
int j =0;

//MAIN FUNCTION
int main(void){

    GPIOA_Config();
    GPIOB_Config();

	while(1){
// Starting position : no button pushed --> Flashing all 5 LEDS twice then staying OFF.
		if (!HAL_GPIO_ReadPin(GPIOB, btn_up) && !HAL_GPIO_ReadPin(GPIOB, btn_down) ){
			while(j<2){																				//Make sure to blink LEDs twice signaling to begin to use "start blinking".
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8, HIGH);
				delay(500000);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8, LOW);
				delay(500000);
				j++;																				//when j increment to the value 3, all the LED already blinked twice signaling the start to avoid blinking again all LEDs when no buttons are pushed.
			}
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8, LOW);		//ALL LEDs stay off after "start" blinking if no button is pushed.
		}
// Count up Button pushed : Count up to 31 --> Flashing LEDs representing the countup value increasing to 31 and repeating from 0 on a 5 binary digits.
		else if(HAL_GPIO_ReadPin(GPIOB, btn_up)==1 && HAL_GPIO_ReadPin(GPIOB, btn_down)==0){
			if (countup < 32){
				HAL_GPIO_WritePin(GPIOA, countup<<4, HIGH);											//countup is shifted left 4 times because pins of port A begins from PA0 and we used in our circuit from 4 to 8, PA4 connected to LED1 representing LSB to PA8 connected to LED5 representing MSB
				delay(500000);																		//Delay in order to be able to visualize the counting.
				HAL_GPIO_WritePin(GPIOA, countup<<4, LOW);
				delay(500000);
				countup++;
			}
			else
				countup = 0;
		}
// Count down Button pushed : Count down to 0 --> Flashing LEDs representing the countdown value decreasing to 0 and repeating from 31 on a 5 binary digits.
		else if(HAL_GPIO_ReadPin(GPIOB, btn_up)==0 && HAL_GPIO_ReadPin(GPIOB, btn_down)==1){
			if (countdown > 0){
				HAL_GPIO_WritePin(GPIOA, countdown<<4, HIGH);
				delay(500000);
				HAL_GPIO_WritePin(GPIOA, countdown<<4, LOW);
				delay(500000);
				countdown--;
					}
			else
				countdown = 0x1F;
				}
// Both Button pushed : Count up power of two --> Flashing LED representing the next power of two number on 5 binary digits and repeat from 2 to the power of 0.
		else{
			if (sequenceval<9){																		//Last of sequenceval used value is 8 to flash the LED representing the maximum value 16.
				HAL_GPIO_WritePin(GPIOA, 1UL<<sequenceval, HIGH);
				delay(500000);
				HAL_GPIO_WritePin(GPIOA, 1UL<<sequenceval, LOW);
				delay(500000);
				sequenceval++;																		//Increment to flash LED representing next power of two.
			}
			else
				sequenceval=4;																		//Fix sequenceval to 4 to return to flashing the LED representing the LSB representing 2pow(0) = 1.
		}

	}

}

//GPIOA Configuration --> configuring 5 pins in port A to control LEDs for binary counter(PA4-PA5-PA6-PA7 and PA8).
void GPIOA_Config(void){

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef GPIOA_Init = {0};

	GPIOA_Init.Pin = GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8;
	GPIOA_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIOA_Init.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIOA_Init);


}

//GPIOB Configuration --> Configuring 2 pins in port B for two push buttons  : one for counting up(PB8) and one for counting down(PB9).
void GPIOB_Config(void){

	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_InitTypeDef GPIOB_Init = {0};

	GPIOB_Init.Pin = btn_down | btn_up;
	GPIOB_Init.Mode = GPIO_MODE_INPUT;
	GPIOB_Init.Pull = GPIO_PULLDOWN;


	HAL_GPIO_Init(GPIOB, &GPIOB_Init);
}

//Delay function
void delay(uint32_t delay_val){
	uint32_t i;
	for(i=0;i<delay_val;i++){}
}

