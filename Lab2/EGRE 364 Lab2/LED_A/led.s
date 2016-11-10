	AREA mydata, DATA, READWRITE

segt DCB 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F ;, 0x77, 0x7C, 0x39, 0x5E, 0x79 ;0x71

PERIPH_BASE EQU 0x40000000


	AREA mycode, CODE, READONLY
	EXPORT __main
	ENTRY
__main PROC
	
	
		BL gpio_init


		LDR	r0, =PERIPH_BASE ;PERIPH_BASE
		ADD r0, #0x08000000	;AHB2PERIPH_BASE
		ADD r1, r0, #0x01000	;GPIOE_BASE
		ADD r2, r0, #0x1C00		;GPIOH_BASE
		ADD r7, r0, #0x0000     ;GPIOA_BASE
	
		
		LDR r0, =segt
		MOV r3, #0

		
		LDR r11, = 0x0020 ;down
		LDR r8, = 0x0008 ;up



loop	LDRB r4, [r0,r3]
		
		LDR r5, [r1,#0x14]
		LDR r6, =0xFFFF03FF
		AND r5, r6
		ORR r5, r4, LSL #10
		STR r5, [r1,#0x14]
		
		LDR r5, [r2, #0x14]
		LDR r6, =0xFFFFFFFE
		AND r5, r6
		ORR r5, r4, LSR #6
		STR r5, [r2,#0x14]
		
		LDR r9, [r7,#0x10]; IDR address
		LDR r10, =0x00FF
		AND r9, r10		
	

		BL Delay
		CMP r8, r9
		BEQ done
		CMP r11,r9
		BEQ finish
		
		B loop

done	ADD r3, #1
		CMP r3, #10
		BNE loop
		MOV r3, #0
		B loop
		
finish	SUB r3, #1
		CMP r3, #-1
		BNE loop
		MOV r3, #9
		B loop
		
		
	    bx lr
	   ENDP
		   
Delay 		PROC 
			push {r1}
	
			ldr r1, =0x60000   ;initial value for loop counter
again  		NOP  		     ;execute two no-operation instructions
			NOP
			subs r1, #1
			bne again
			pop {r1}
			bx lr
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
			ENDP
				
				
	
			END
				