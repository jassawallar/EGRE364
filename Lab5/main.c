#include "stm32l476xx.h"
#include "SysTimer.h"
#include "lcd.h"
#include "ADC.h"
#include "stm32l476xx.h"
#include <stdint.h>



void PE_Init(void) {
/* Enable GPIOs clock */ 	
	RCC->AHB2ENR |=   RCC_AHB2ENR_GPIOEEN;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PE8 and PE15
	//////////////////////////////////////////////////////////////////////////////////////////
	// GPIO Mode: Input(00, reset), Output(01), AlterFunc(10), Analog(11, reset)
	GPIOE->MODER &= ~(3U<<(2*15));  
	GPIOE->MODER |= 1U<<(2*15);      //  Output(01) PE15 R1

	GPIOE->MODER &= ~(3U<<(2*14));  
	GPIOE->MODER |= 1U<<(2*14);      //  Output(01) PE14 R2
	
	GPIOE->MODER &= ~(3U<<(2*13));  
	GPIOE->MODER |= 1U<<(2*13);      //  Output(01) PE13 R3
	
	GPIOE->MODER &= ~(3U<<(2*12));  
	GPIOE->MODER |= 1U<<(2*12);      //  Output(01) PE12 R4
	
	GPIOE->MODER &= ~(3U<<(2*8));  
	GPIOE->MODER |= 1U<<(2*8);      //  Output(01) TEST


	
	// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
	GPIOE->OSPEEDR &= ~(3U<<(2*15));
	GPIOE->OSPEEDR |=   3U<<(2*15);  // High speed PE15 R1

	GPIOE->OSPEEDR &= ~(3U<<(2*14));
	GPIOE->OSPEEDR |=   3U<<(2*14);  // High speed PE14 R2
	
	GPIOE->OSPEEDR &= ~(3U<<(2*13));
	GPIOE->OSPEEDR |=   3U<<(2*13);  // High speed PE13 R3
	
	GPIOE->OSPEEDR &= ~(3U<<(2*12));
	GPIOE->OSPEEDR |=   3U<<(2*12);  // High speed PE12 R4
	
	GPIOE->OSPEEDR &= ~(3U<<(2*8));
	GPIOE->OSPEEDR |=   3U<<(2*8);  // High speed TEST

	
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOE->OTYPER &= ~(1U<<15);       // Push-pull PE15 R1
	GPIOE->OTYPER &= ~(1U<<14);       // Push-pull PE14 R2
	GPIOE->OTYPER &= ~(1U<<13);       // Push-pull PE13 R3
	GPIOE->OTYPER &= ~(1U<<12);       // Push-pull PE15 R4
	GPIOE->OTYPER &= ~(1U<<8);       // Push-pull TEST

	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOE->PUPDR   &= ~(3U<<(2*15));  // No pull-up, no pull-down PE15 R1
	GPIOE->PUPDR   &= ~(3U<<(2*14));  // No pull-up, no pull-down PE14 R2
	GPIOE->PUPDR   &= ~(3U<<(2*13));  // No pull-up, no pull-down PE13 R3
	GPIOE->PUPDR   &= ~(3U<<(2*12));  // No pull-up, no pull-down PE12 R4
	GPIOE->PUPDR   &= ~(3U<<(2*8));  // No pull-up, no pull-down TEST 
}


void System_Clock_Init(void){
	
	RCC->CR |= RCC_CR_MSION; 
	
	// Select MSI as the clock source of System Clock
	RCC->CFGR &= ~RCC_CFGR_SW; 
	
	// Wait until MSI is ready
	while ((RCC->CR & RCC_CR_MSIRDY) == 0); 	
	
	// MSIRANGE can be modified when MSI is OFF (MSION=0) or when MSI is ready (MSIRDY=1). 
	RCC->CR &= ~RCC_CR_MSIRANGE; 
	RCC->CR |= RCC_CR_MSIRANGE_7;  // Select MSI 8 MHz	
 
	// The MSIRGSEL bit in RCC-CR select which MSIRANGE is used. 
	// If MSIRGSEL is 0, the MSIRANGE in RCC_CSR is used to select the MSI clock range.  (This is the default)
	// If MSIRGSEL is 1, the MSIRANGE in RCC_CR is used. 
	RCC->CR |= RCC_CR_MSIRGSEL; 
	
	// Enable MSI and wait until it's ready	
	while ((RCC->CR & RCC_CR_MSIRDY) == 0); 		
}


int main(void){

	int32_t counter = 0;
	int32_t counter2 = 0;
	int32_t counter3 = 0;
	int32_t counter4 = 0;
	int32_t threshold = 0x1000;
		
	System_Clock_Init(); // Set System Clock as 8 MHz
	PE_Init();
	SysTick_Init();
	LCD_Initialization();
	LCD_Clear();
	ADC_Init();							//Initialization for distance Sensor ADC convertion, Uses pin PA1

	
	while(1){
		
		GPIOE->MODER |= 1U<<(2*15);      //  Output(01)		
		
		GPIOE->ODR |=1U<<15;
		
			GPIOE->MODER |= 1U<<(2*14);      //  Output(01)		
		
		GPIOE->ODR |=1U<<14;
		
			GPIOE->MODER |= 1U<<(2*13);      //  Output(01)		
		
		GPIOE->ODR |=1U<<13;
		
			GPIOE->MODER |= 1U<<(2*12);      //  Output(01)		
		
		GPIOE->ODR |=1U<<12;
		delay(10);
		
		GPIOE->MODER &= ~(3U<<(2*15));
		 
		while (GPIOE->IDR & 0x8000) counter++;
		
		GPIOE->MODER &= ~(3U<<(2*14));
		 
		while (GPIOE->IDR & 0x4000) counter2++;
		
		GPIOE->MODER &= ~(3U<<(2*13));
		 
		while (GPIOE->IDR & 0x2000) counter3++;
		
		GPIOE->MODER &= ~(3U<<(2*12));
		 
		while (GPIOE->IDR & 0x1000) counter4++;

		
		if (counter>threshold){		
		LCD_WriteChar((uint8_t*)"B", 0, 0, 2);
		}
		else {
		LCD_WriteChar((uint8_t*)"W", 0, 0, 2);
		}
		
		if (counter2>threshold){		
		LCD_WriteChar((uint8_t*)"B", 0, 0, 3);
		}
		else {
		LCD_WriteChar((uint8_t*)"W", 0, 0, 3);
		}
		
		if (counter3>threshold){		
		LCD_WriteChar((uint8_t*)"B", 0, 0, 4);
		}
		else {
		LCD_WriteChar((uint8_t*)"W", 0, 0, 4);
		}
		if (counter4>threshold){		
		LCD_WriteChar((uint8_t*)"B", 0, 0, 5);
		}
		else {
		LCD_WriteChar((uint8_t*)"W", 0, 0, 5);
		}
		counter =0;
		counter2 =0;
		counter3 =0;
		counter4 =0;
	}
}

