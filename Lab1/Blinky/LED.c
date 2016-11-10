#include "LED.h"


//******************************************************************************************
// User LEDs: 
//   LD4 Red = PB2    LD5 Green = PE8
// Note: The Green LED is yellow on my board.
//       PE8 is also the TIM1_CH1N for ADC Triggers.
//******************************************************************************************
void LED_Init(void){
	/* Enable GPIOs clock */ 	
	RCC->AHB2ENR |=   RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOEEN | RCC_AHB2ENR_GPIOAEN;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// LD5 Green = PE10
	//////////////////////////////////////////////////////////////////////////////////////////
	// GPIO Mode: Input(00, reset), Output(01), AlterFunc(10), Analog(11, reset)
	GPIOE->MODER &= ~(0x03<<(2*10));  
	GPIOE->MODER |= 0x01<<(2*10);      //  Output(01)
		
	// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
	GPIOE->OSPEEDR &= ~(0x03<<(2*10));
	GPIOE->OSPEEDR |=   0x03<<(2*10);  // High speed
		
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOE->OTYPER &= ~(0x01<<10);       // Push-pull
	
	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOE->PUPDR   &= ~(0x03<<(2*10));  // No pull-up, no pull-down
	//////////////////////////////////////////////////////////////////////////////////////////
	
		//////////////////////////////////////////////////////////////////////////////////////////
	// LD5 Green = PE11
	//////////////////////////////////////////////////////////////////////////////////////////
	// GPIO Mode: Input(00, reset), Output(01), AlterFunc(10), Analog(11, reset)
	GPIOE->MODER &= ~(0x03<<(2*11));  
	GPIOE->MODER |= 0x01<<(2*11);      //  Output(01)
		
	// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
	GPIOE->OSPEEDR &= ~(0x03<<(2*11));
	GPIOE->OSPEEDR |=   0x03<<(2*11);  // High speed
		
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOE->OTYPER &= ~(0x01<<11);       // Push-pull
	
	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOE->PUPDR   &= ~(0x03<<(2*11));  // No pull-up, no pull-down
	//////////////////////////////////////////////////////////////////////////////////////////
	
		//////////////////////////////////////////////////////////////////////////////////////////
	// LD5 Green = PE12
	//////////////////////////////////////////////////////////////////////////////////////////
	// GPIO Mode: Input(00, reset), Output(01), AlterFunc(10), Analog(11, reset)
	GPIOE->MODER &= ~(0x03<<(2*12));  
	GPIOE->MODER |= 0x01<<(2*12);      //  Output(01)
		
	// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
	GPIOE->OSPEEDR &= ~(0x03<<(2*12));
	GPIOE->OSPEEDR |=   0x03<<(2*12);  // High speed
		
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOE->OTYPER &= ~(0x01<<12);       // Push-pull
	
	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOE->PUPDR   &= ~(0x03<<(2*12));  // No pull-up, no pull-down
	//////////////////////////////////////////////////////////////////////////////////////////
	
		//////////////////////////////////////////////////////////////////////////////////////////
	// LD5 Green = PE13
	//////////////////////////////////////////////////////////////////////////////////////////
	// GPIO Mode: Input(00, reset), Output(01), AlterFunc(10), Analog(11, reset)
	GPIOE->MODER &= ~(0x03<<(2*13));  
	GPIOE->MODER |= 0x01<<(2*13);      //  Output(01)
		
	// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
	GPIOE->OSPEEDR &= ~(0x03<<(2*13));
	GPIOE->OSPEEDR |=   0x03<<(2*13);  // High speed
		
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOE->OTYPER &= ~(0x01<<13);       // Push-pull
	
	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOE->PUPDR   &= ~(0x03<<(2*13));  // No pull-up, no pull-down
	//////////////////////////////////////////////////////////////////////////////////////////
	
		//////////////////////////////////////////////////////////////////////////////////////////
	// LD5 Green = PE14
	//////////////////////////////////////////////////////////////////////////////////////////
	// GPIO Mode: Input(00, reset), Output(01), AlterFunc(10), Analog(11, reset)
	GPIOE->MODER &= ~(0x03<<(2*14));  
	GPIOE->MODER |= 0x01<<(2*14);      //  Output(01)
		
	// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
	GPIOE->OSPEEDR &= ~(0x03<<(2*14));
	GPIOE->OSPEEDR |=   0x03<<(2*14);  // High speed
		
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOE->OTYPER &= ~(0x01<<14);       // Push-pull
	
	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOE->PUPDR   &= ~(0x03<<(2*14));  // No pull-up, no pull-down
	//////////////////////////////////////////////////////////////////////////////////////////
	
		//////////////////////////////////////////////////////////////////////////////////////////
	// LD5 Green = PE15
	//////////////////////////////////////////////////////////////////////////////////////////
	// GPIO Mode: Input(00, reset), Output(01), AlterFunc(10), Analog(11, reset)
	GPIOE->MODER &= ~(0x03<<(2*15));  
	GPIOE->MODER |= 0x01<<(2*15);      //  Output(01)
		
	// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
	GPIOE->OSPEEDR &= ~(0x03<<(2*15));
	GPIOE->OSPEEDR |=   0x03<<(2*15);  // High speed
		
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOE->OTYPER &= ~(0x01<<15);       // Push-pull
	
	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOE->PUPDR   &= ~(0x03<<(2*15));  // No pull-up, no pull-down
	//////////////////////////////////////////////////////////////////////////////////////////
	
	// LD5 Green = PE8
	//////////////////////////////////////////////////////////////////////////////////////////
	// GPIO Mode: Input(00, reset), Output(01), AlterFunc(10), Analog(11, reset)
	GPIOE->MODER &= ~(0x03<<(2*8));  
	GPIOE->MODER |= 0x01<<(2*8);      //  Output(01)
		
	// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
	GPIOE->OSPEEDR &= ~(0x03<<(2*8));
	GPIOE->OSPEEDR |=   0x03<<(2*8);  // High speed
		
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOE->OTYPER &= ~(0x01<<8);       // Push-pull
	
	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOE->PUPDR   &= ~(0x03<<(2*8));  // No pull-up, no pull-down
	
	//////////////////////////////////////////////////////////////////////////////////////////
	//PA0 Initialization
	// Sets PA0 to Output Mode (01)
	GPIOA->MODER &= ~(0x03<<(2*0));
	GPIOA->MODER |= 0x01<<(2*0);
	
	//Sets the speed of PA0 to a Fast Speed
	GPIOA->OSPEEDR &= ~(0x03<<(2*0));
	GPIOA->OSPEEDR |=   0x03<<(2*0);
	
	//Sets PA0 to be a push-pull output
	GPIOA->OTYPER &= ~(0x01<<0);
	
	//Sets PA0 to not have pull-up or pull-down
	GPIOA->PUPDR &= ~(0x03<<(2*0));
	
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	//PA0 Initilization
	//Sets PA0 to Output Mode
	GPIOA->MODER &= ~(0x03<<(2*0));
	GPIOA->MODER |= 0x01<<(2*0);
	
	//Sets PA0 to a Fast Speed
	GPIOA->OSPEEDR &= ~(0x03<<(2*0));
	GPIOA->OSPEEDR |=		0x03<<(2*0);
	
	//Sets PA0 to be a push-pull output
	GPIOA->OTYPER &= ~(0x01<<0);
	
	//Sets PA0 to not have pull-up or pull-down
	GPIOA->PUPDR &= ~(0x03<<(2*0));
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	//PA1 Initilization
	//Sets PA1 to Output Mode
	GPIOA->MODER &= ~(0x03<<(2*1));
	GPIOA->MODER |=		0x01<<(2*1);
	
	//Sets PA1 to a Fast Speed
	GPIOA->OSPEEDR &= ~(0x03<<(2*1));
	GPIOA->OSPEEDR |=		0x03<<(2*1);
	
	//Sets PA1 to be a push-pull output
	GPIOA->OTYPER &= ~(0x01<<1);
	
	//Sets PA1 to not have pull-up or pull-down
	GPIOA->PUPDR &= ~(0x03<<(2*1));
	
	/////////////////////////////////////////////////////////////////////////////////////////
	//PA2 Initilization
	//Sets PA2 to Output Mode
	GPIOA->MODER &= ~(0x03<<(2*2));
	GPIOA->MODER |=		0x01<<(2*2);
	
	//Sets PA2 to a Fast Speed
	GPIOA->OSPEEDR &= ~(0x03<<(2*2));
	GPIOA->OSPEEDR |=		0x03<<(2*2);
	
	//Sets PA2 to be a push-pull output
	GPIOA->OTYPER &= ~(0x01<<2);
	
	//Sets PA2 to not have pull-up or pull-down
	GPIOA->PUPDR &= ~(0x03<<(2*2));
	
	
	///////////////////////////////////////////////////////////////////////////////////////
	//PA3 Initilization
	//Sets PA3 to Output Mode
	GPIOA->MODER &= ~(0x03<<(2*3));
	GPIOA->MODER |=		0x01<<(2*3);
	
	//Sets PA3 to a Fast Speed
	GPIOA->OSPEEDR &= ~(0x03<<(2*3));
	GPIOA->OSPEEDR |=		0x03<<(2*3);
	
	//Sets PA3 to be a push-pull output
	GPIOA->OTYPER &= ~(0x01<<3);
	
	//Sets PA3 to not have pull-up or pull-down
	GPIOA->PUPDR &= ~(0x03<<(2*3));
	
	
}


//******************************************************************************************
// Turn Red LED On
//******************************************************************************************
void PB2_On(void){
	GPIOB->ODR |= GPIO_ODR_ODR_2;
}

//******************************************************************************************
// Turn Red LED Off
//******************************************************************************************
void PB2_Off(void){
	GPIOB->ODR &= ~GPIO_ODR_ODR_2;
}

//******************************************************************************************
// Toggle Red LED 
//******************************************************************************************
void PB2_Toggle(void){
	GPIOB->ODR ^= GPIO_ODR_ODR_2;
}

//******************************************************************************************
// Turn Green LED On
//******************************************************************************************
void PE8_On(void){
	GPIOE->ODR |= GPIO_ODR_ODR_8;
}

//******************************************************************************************
// Turn Green LED Off
//******************************************************************************************
void PE8_Off(void){
	GPIOE->ODR &= ~GPIO_ODR_ODR_8;
}

//******************************************************************************************
// Toggle Green LED
//******************************************************************************************
void PE8_Toggle(void){
	GPIOE->ODR ^= GPIO_ODR_ODR_8;
}

//******************************************************************************************
// Turn PA0 On
//******************************************************************************************
void PA0_On(void){
	GPIOA->ODR |= GPIO_ODR_ODR_0;
}

//******************************************************************************************
// Turn PA0 Off
//******************************************************************************************
void PA0_Off(void){
	GPIOA->ODR &= ~GPIO_ODR_ODR_0;
}

//******************************************************************************************
// Toggle PA0
//******************************************************************************************
void PA0_Toggle(void){
	GPIOA->ODR ^= GPIO_ODR_ODR_0;
}

//******************************************************************************************
// Turn PB3 On
//******************************************************************************************
void PB3_On(void){
	GPIOB->ODR |= GPIO_ODR_ODR_3;
}

//******************************************************************************************
// Turn PB3 Off
//******************************************************************************************
void PB3_Off(void){
	GPIOB->ODR &= ~GPIO_ODR_ODR_3;
}

//******************************************************************************************
// Toggle PB3
//******************************************************************************************
void PB3_Toggle(void){
	GPIOB->ODR ^= GPIO_ODR_ODR_3;
}

//******************************************************************************************
// Turn PA5 On
//******************************************************************************************
void PA5_On(void){
	GPIOA->ODR |= GPIO_ODR_ODR_5;
}

//******************************************************************************************
// Turn PA5 Off
//******************************************************************************************
void PA5_Off(void){
	GPIOA->ODR &= ~GPIO_ODR_ODR_5;
}

//******************************************************************************************
// Toggle PA5
//******************************************************************************************
void PA5_Toggle(void){
	GPIOA->ODR ^= GPIO_ODR_ODR_5;
}

//******************************************************************************************
// Turn PA1 On
//******************************************************************************************
void PA1_On(void){
	GPIOA->ODR |= GPIO_ODR_ODR_1;
}

//******************************************************************************************
// Turn PA1 Off
//******************************************************************************************
void PA1_Off(void){
	GPIOA->ODR &= ~GPIO_ODR_ODR_1;
}

//******************************************************************************************
// Toggle PA1
//******************************************************************************************
void PA1_Toggle(void){
	GPIOA->ODR ^= GPIO_ODR_ODR_1;
}

//******************************************************************************************
// Turn PA2 On
//******************************************************************************************
void PA2_On(void){
	GPIOA->ODR |= GPIO_ODR_ODR_1;
}

//******************************************************************************************
// Turn PA2 Off
//******************************************************************************************
void PA2_Off(void){
	GPIOA->ODR &= ~GPIO_ODR_ODR_2;
}

//******************************************************************************************
// Toggle PA2
//******************************************************************************************
void PA2_Toggle(void){
	GPIOA->ODR ^= GPIO_ODR_ODR_2;
}


//******************************************************************************************
// Turn PA3 On
//******************************************************************************************
void PA3_On(void){
	GPIOA->ODR |= GPIO_ODR_ODR_3;
}

//******************************************************************************************
// Turn PA3 Off
//******************************************************************************************
void PA3_Off(void){
	GPIOA->ODR &= ~GPIO_ODR_ODR_3;
}

//******************************************************************************************
// Toggle PA3
//******************************************************************************************
void PA3_Toggle(void){
	GPIOA->ODR ^= GPIO_ODR_ODR_3;
}

//******************************************************************************************
// Turn PB6 On
//******************************************************************************************
void PB6_On(void){
	GPIOB->ODR |= GPIO_ODR_ODR_6;
}

//******************************************************************************************
// Turn PB6 Off
//******************************************************************************************
void PB6_Off(void){
	GPIOB->ODR &= ~(GPIO_ODR_ODR_6);
}

//******************************************************************************************
// Toggle PB6
//******************************************************************************************
void PB6_Toggle(void){
	GPIOB->ODR ^= GPIO_ODR_ODR_6;
}

//******************************************************************************************
// Turn PB7 On
//******************************************************************************************
void PB7_On(void){
	GPIOB->ODR |= GPIO_ODR_ODR_7;
}

//******************************************************************************************
// Turn PB7 Off
//******************************************************************************************
void PB7_Off(void){
	GPIOB->ODR &= ~GPIO_ODR_ODR_7;
}

//******************************************************************************************
// Toggle PB7
//******************************************************************************************
void PB7_Toggle(void){
	GPIOB->ODR ^= GPIO_ODR_ODR_7;
}

void init(void){
	int i =0;
	while(i <=12){
		//delay(75);
		GPIOE->ODR |= 0xF<<(6+i);
		i++;
	}
}
//	int fade (uint32_t led){
//		
//		return 0;
//	}
