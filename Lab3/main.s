;******************** (C) Yifeng ZHU *******************************************
; @file    main.s
; @author  Yifeng Zhu
; @date    May-17-2015
; @note
;           This code is for the book "Embedded Systems with ARM Cortex-M 
;           Microcontrollers in Assembly Language and C, Yifeng Zhu, 
;           ISBN-13: 978-0982692639, ISBN-10: 0982692633
; @attension
;           This code is provided for education purpose. The author shall not be 
;           held liable for any direct, indirect or consequential damages, for any 
;           reason whatever. More information can be found from book website: 
;           http:;www.eece.maine.edu/~zhu/book
;*******************************************************************************

;*************************************  32L476GDISCOVERY ***************************************************************************
; STM32L4:  STM32L476VGT6 MCU = ARM Cortex-M4 + FPU + DSP, 
;           LQFP100, 1 MB of Flash, 128 KB of SRAM
;           Instruction cache = 32 lines of 4x64 bits (1KB)
;           Data cache = 8 lines of 4x64 bits (256 B)
;
; Joystick (MT-008A): 
;   Right = PA2        Up   = PA3         Center = PA0
;   Left  = PA1        Down = PA5
;
; User LEDs: 
;   LD4 Red   = PB2    LD5 Green = PE8
;   
; CS43L22 Audio DAC Stereo (I2C address 0x94):  
;   SAI1_MCK = PE2     SAI1_SD  = PE6    I2C1_SDA = PB7    Audio_RST = PE3    
;   SAI1_SCK = PE5     SAI1_FS  = PE4    I2C1_SCL = PB6                                           
;
; MP34DT01 Digital MEMS microphone 
;    Audio_CLK = PE9   Audio_DIN = PE7
;
; LSM303C eCompass (a 3D accelerometer and 3D magnetometer module): 
;   MEMS_SCK  = PD1    MAG_DRDY = PC2    XL_CS  = PE0             
;   MEMS_MOSI = PD4    MAG_CS  = PC0     XL_INT = PE1       
;                      MAG_INT = PC1 
;
; L3GD20 Gyro (three-axis digital output): 
;   MEMS_SCK  = PD1    GYRO_CS   = PD7
;   MEMS_MOSI = PD4    GYRO_INT1 = PD2
;   MEMS_MISO = PD3    GYRO_INT2 = PB8
;
; ST-Link V2 (Virtual com port, Mass Storage, Debug port): 
;   USART_TX = PD5     SWCLK = PA14      MFX_USART3_TX   MCO
;   USART_RX = PD6     SWDIO = PA13      MFX_USART3_RX   NRST
;   PB3 = 3V3_REG_ON   SWO   = PB3      
;
; Quad SPI Flash Memory (128 Mbit)
;   QSPI_CS  = PE11    QSPI_D0 = PE12    QSPI_D2 = PE14
;   QSPI_CLK = PE10    QSPI_D1 = PE13    QSPI_D3 = PE15
;
; LCD (24 segments, 4 commons)
;   VLCD = PC3
;   COM0 = PA8     COM1  = PA9      COM2  = PA10    COM3  = PB9
;   SEG0 = PA7     SEG6  = PD11     SEG12 = PB5     SEG18 = PD8
;   SEG1 = PC5     SEG7  = PD13     SEG13 = PC8     SEG19 = PB14
;   SEG2 = PB1     SEG8  = PD15     SEG14 = PC6     SEG20 = PB12
;   SEG3 = PB13    SEG9  = PC7      SEG15 = PD14    SEG21 = PB0
;   SEG4 = PB15    SEG10 = PA15     SEG16 = PD12    SEG22 = PC4
;   SEG5 = PD9     SEG11 = PB4      SEG17 = PD10    SEG23 = PA6
; 
; USB OTG
;   OTG_FS_PowerSwitchOn = PC9    OTG_FS_VBUS = PC11     OTG_FS_DM = PA11  
;   OTG_FS_OverCurrent   = PC10   OTG_FS_ID   = PC12    OTG_FS_DP = PA12  
;
; PC14 = OSC32_IN      PC15 = OSC32_OUT
; PH0  = OSC_IN        PH1  = OSC_OUT 
; 
; PA4  = DAC1_OUT1 (NLMFX0 WAKEUP)   PA5 = DAC1_OUT2 (Joy Down)
; PA3  = OPAMP1_VOUT (Joy Up)        PB0 = OPAMP2_VOUT (LCD SEG21)
;
;*****************************************************************************************************************


	INCLUDE core_cm4_constants.s		; Load Constant Definitions
	INCLUDE stm32l476xx_constants.s      

				
		
	AREA mydata, DATA, READWRITE
		
seq1 DCB 2_0101,2_0110,2_1010,2_1001,2_0000
seq2 DCB 2_0101,2_1001,2_1010,2_0110,2_0000
seq3 DCB 2_0001,2_0100,2_0010,2_1000,2_0000
seq4 DCB 2_0001,2_1000,2_0010,2_0100,2_0000
seq5 DCB 2_0001,2_0101,2_0100,2_0110,2_0010,2_1010,2_1000,2_1001,2_0000

;PERIPH_BASE EQU 0x40000000
	
	AREA  main, CODE, READONLY
	EXPORT __main
	ENTRY	

__main	PROC
		BL RCC_Init
		BL gpio_init
		
		
repeat		
		LDR	r0, =PERIPH_BASE ;PERIPH_BASE
		ADD r0, #0x08000000	;AHB2PERIPH_BASE
		
		ADD r7, r0, #0x00000   ;GPIOE_BASE
		
		LDR r9, [r7,#0x10]; IDR address
		
		LDR r11, = 0x0020 ;down
		LDR r8, = 0x0008 ;up
				
		LDR r10, =0x00FF
		AND r9, r10	
		
	
		CMP r8, r9
		BEQ half
		CMP r11,r9
		BEQ full
		B repeat
		ENDP
		
		;------------------------------------------------------------------------------------------------------------------------;	
half	
		LDR r0,=GPIOE_BASE
		LDR r1, =seq5
		LDR r1, =seq4
		B loop_2
loop_2
		LDRB r2,[r1],#1
		CBNZ r2,next_2
		MOV r1, r5
		;B loop_2
		B repeat

next_2
		LDR r3,[r0,#GPIO_ODR]
		LDR r4,=0x0F
		BIC r3,r3,r4, LSL #10
		ORR r3,r3,r2,LSL #10
		STR r3, [r0,#GPIO_ODR]
		BL Delay_2
		;B repeat
		B loop_2
		
full
		LDR r0,=GPIOE_BASE
		LDR r1, =seq1
		LDR r1, =seq2
		LDR r1, =seq3
		LDR r1, =seq4
		;LDR r1, =seq5
		MOV r5, r1
		B loop_3
loop_3
		LDRB r2,[r1],#1
		CBNZ r2,next_3
		MOV r1, r5
		;B loop_3
		B repeat
next_3
		LDR r3,[r0,#GPIO_ODR]
		LDR r4,=0x0F
		BIC r3,r3,r4, LSL #10
		ORR r3,r3,r2,LSL #10
		STR r3, [r0,#GPIO_ODR]
		BL Delay_3
		;B repeat
		B loop_3
		
		;----------------------------------------------------------------------------------------------------------------------------;
	
RCC_Init 	PROC
			PUSH {R0,R1}
			LDR R0, =RCC_BASE
			LDR R1, [R0,#RCC_AHB2ENR]
			ORR R1,R1,#RCC_AHB2ENR_GPIOBEN
			STR R1, [R0,#RCC_AHB2ENR]
			POP {R1,R0}
			BX LR
			ENDP

		
gpio_init	PROC
			LDR	r0, =PERIPH_BASE
			ADD r0, #0x20000 	;AHB1PERIPH_BASE
			ADD r0, #0x1000		;RCC_BASE
			LDR	r1, [r0,#0x4C]  ;RCC->AHB2ENR
			ORR  r1,#0x91		;Enable GPIOE and GPIOH abd GPIOA
			STR	r1, [r0,#0x4C]
	
			LDR	r0, =PERIPH_BASE ;PERIPH_BASE
			ADD r0, #0x08000000	;AHB2PERIPH_BASE
			ADD r0, #0x01000	;GPIOE_BASE

			LDR r1, [r0,#0]     ;PE10-PE15
			LDR r2, =0x000FFFFF
			AND r1,r2			;GPIOE->MODER   &=  ~(0xFFFU << (2*10))
			LDR r2,=0x55500000
			ORR	r1,r2			;GPIOE->MODER |= (0x555U<< (2*10))
			STR	r1, [r0,#0]
			
			LDRH r1, [r0,#4]	;GPIOE->OTYPER
			LDR  r2, =0x03FF
			AND	 r1,r2			;GPIOE->OTYPER &= ~(0x3FU<<10)
			STRH r1, [r0,#4]
			
			LDR r1, [r0,#8]		;GPIOE->OSPEEDR
			LDR r2, =0xFFF00000
			ORR	r1, r2			;GPIOE->OSPEEDR |= (0xFFFU<<(2*10))
			STR r1, [r0,#8]
			
			LDR r1, [r0,#0x0C]		;GPIOE->PUPDR
			LDR r2, =0x000FFFFF
			AND	r1, r2				;GPIOE->PUPDR &= ~(0xFFFU << (2*10))
			STR r1, [r0,#0x0C]
			

			LDR	r0, =PERIPH_BASE ;PERIPH_BASE
			ADD r0, #0x08000000	;AHB2PERIPH_BASE
			ADD r0, #0x01C00	;GPIOH_BASE

			LDR r1, [r0,#0]     ;PH0
			AND r1,#0xFFFFFFFC  ;GPIOE->MODER   &=  ~(3)
			ORR	r1,#0x1			;GPIOE->MODER |= (1)
			STR	r1, [r0,#0]
			
			LDRH r1, [r0,#4]	;GPIOE->OTYPER
			LDR  r2, =0xFFFE
			AND	 r1, r2			;GPIOE->OTYPER &= ~(0x1)
			STRH r1, [r0,#4]
			
			LDR r1, [r0,#8]		;GPIOE->OSPEEDR
			ORR	r1,#0x3			;GPIOE->OSPEEDR |= (3)
			STR r1, [r0,#8]
			
			LDR r1, [r0,#0x0C]		;GPIOE->PUPDR
			AND	r1,#0xFFFFFFFC	;GPIOE->PUPDR &= ~(0x3)
			STR r1, [r0,#0x0C]
			
			;----------------------------------;
			
			LDR	r0, =PERIPH_BASE ;PERIPH_BASE
			ADD r0, #0x08000000	;AHB2PERIPH_BASE
			ADD r0, #0x0	;GPIOA_BASE

			LDR r1, [r0,#0]     ;PH0
			AND r1,#0xFFFFF33F  ;GPIOE->MODER   &=  ~(3)
			ORR	r1,#0x1			;GPIOE->MODER |= (1)
			STR	r1, [r0,#0]
		
			
			LDR r1, [r0,#0x0C]		;GPIOE->PUPDR
			AND	r1,#0x00000000      ;GPIOE->PUPDR &= ~(0x3)
			ORR r1, #0x00000880
			STR r1, [r0,#0x0C]
			
			
			
			BX	LR
			;--------------------------------------------------------------------------------;
			LDR	r0, =PERIPH_BASE ;PERIPH_BASE
			ADD r0, #0x08000000	;AHB2PERIPH_BASE
			ADD r0, #0x0	;GPIOA_BASE

			LDR r1, [r0,#0]     ;PH0
			AND r1,#0xFFFFF33F  ;GPIOE->MODER   &=  ~(3)
			ORR	r1,#0x1			;GPIOE->MODER |= (1)
			STR	r1, [r0,#0]
		
			
			LDR r1, [r0,#0x0C]		;GPIOE->PUPDR
			AND	r1,#0x00000000      ;GPIOE->PUPDR &= ~(0x3)
			ORR r1, #0x00000880
			STR r1, [r0,#0x0C]
			
			
			
			BX	LR
			ENDP
									
	
Delay_2
		push {r1}
		ldr r1, =7000 ;initial value for loop counter
again 	NOP ;execute two no-operation instructions
		NOP
		subs r1, #1
		bne again
		pop {r1}
		bx lr
		B repeat
		
Delay_3
		push {r1}
		ldr r1, =4000 ;initial value for loop counter
again_3	NOP ;execute two no-operation instructions
		NOP
		subs r1, #1
		bne again_3
		pop {r1}
		bx lr
		B repeat
				
		END