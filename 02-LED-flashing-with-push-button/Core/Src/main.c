/*
 * main.c
 *
 *  Created on: Nov 21, 2025
 *      Author: med08
 */

#include "main.h"

//MAIN FUNCTION
int main(void){

    GPIOA_Config();
    GPIOC_Config();
	while(1){
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 0)
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,SET);
		else
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,RESET);
	}
}

//GPIOC Configuration

void GPIOC_Config(void){

	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef GPIOC_Init = {};

	GPIOC_Init.Pin = GPIO_PIN_13;
	GPIOC_Init.Mode = GPIO_MODE_INPUT;
	GPIOC_Init.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOC, &GPIOC_Init);
}




//GPIOA Configuration
void GPIOA_Config(void){

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef GPIOA_Init = {};

	GPIOA_Init.Pin = GPIO_PIN_5;
	GPIOA_Init.Mode = GPIO_MODE_OUTPUT_PP;

	HAL_GPIO_Init(GPIOA, &GPIOA_Init);
}

/*void delay(uint32_t delay_val){
	uint32_t i;
	for(i=0;i<delay_val;i++){}
}*/
