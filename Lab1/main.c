#include "stm32l476xx.h"
#include "LED.h"
#include "SysTimer.h"

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
uint32_t B1 = 0x1E000; 
uint32_t B2 = 0x0E000;
uint32_t B3	= 0x06000;
uint32_t B4 =	0x02000;
	
	
	int f=1;
	int a=1;
	
		
	System_Clock_Init(); // Set System Clock as 8 MHz
	LED_Init();
	SysTick_Init();

while(1){
	a = 1;
		while(a<=13){
			for(f=1; f<=5; f++){
		Stream(B1);
		
    delay(1);
    Stream(B2);
			
		delay(2);
		Stream(B3);
		
		delay(3);
		Stream(B4);
		
		delay(4);
	
}
			a++;
			B1 = B1 >> 1;
			B2 = B2 >> 1;
			B3 = B3 >> 1;
			B4 = B4 >> 1;
}
	 a = 1;


			B2 = B2 << 1;
			B3 = B3 << 2;
			B4 = B4 << 3;

	while(a<=13){
		
		
		for(f=1; f<=4; f++){
		Stream(B1);

    delay(1);
    Stream(B2);
			
		delay(2);
		Stream(B3);
		
		delay(3);
		Stream(B4);
		
		delay(4);
		}
		a++;
		B1 = B1 << 1;
		B2 = B2 << 1;	
		B3 = B3 << 1;
		B4 = B4 << 1;
	}
	a = 1;
	    B2 = B2 >> 1;
			B3 = B3 >> 2;
			B4 = B4 >> 3;
}
}