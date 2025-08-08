;******************** (C) COPYRIGHT 2017 MindMotion ********************
; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000200

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp                   ; Top of Stack
                DCD     Reset_Handler                  ; Reset Handler
                DCD     NMI_Handler                    ; NMI Handler
                DCD     HardFault_Handler              ; Hard Fault Handler
                DCD     0                              ; Reserved
                DCD     0                              ; Reserved
                DCD     0                              ; Reserved
                DCD     0                              ; Reserved
                DCD     0                              ; Reserved
                DCD     0                              ; Reserved
                DCD     0                              ; Reserved
                DCD     SVC_Handler                    ; SVCall Handler
                DCD     0                              ; Reserved
                DCD     0                              ; Reserved
                DCD     PendSV_Handler                 ; PendSV Handler
                DCD     SysTick_Handler                ; SysTick Handler

                ; External Interrupts
                DCD     WWDG_IRQHandler 
                DCD     USART1_IRQHandler 
                DCD     USART2_IRQHandler 
                DCD     USART3_IRQHandler 
                DCD     I2C1_IRQHandler   
                DCD     EXTI0_1_IRQHandler 
                DCD     EXTI2_3_IRQHandler 
                DCD     EXTI4_15_IRQHandler 
                DCD     DMA1_IRQHandler 
                DCD     DMA2_IRQHandler 
                DCD     TIM1_IRQHandler 
                DCD     TIM2_IRQHandler 
                DCD     TIM6_IRQHandler 
				DCD		TIM7_IRQHandler	
                DCD     SPI1_IRQHandler
                DCD     SPI2_IRQHandler 
                DCD     SPI3_IRQHandler
                DCD     CIM_IRQHandler 
      
__Vectors_End

__Vectors_Size  EQU  __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Reset handler routine
Reset_Handler    PROC
                 EXPORT  Reset_Handler                 [WEAK]
        IMPORT  __main
        IMPORT  SystemInit


        LDR     R0, =__initial_sp          ; set stack pointer 
        MSR     MSP, R0  

;;Check if boot space corresponds to test memory 

        LDR R0,=0x00000004
        LDR R1, [R0]
        LSRS R1, R1, #24
        LDR R2,=0x1F
        CMP R1, R2
        
        BNE ApplicationStart  
     
;; SYSCFG clock enable    
     
        LDR R0,=0x40021018 
        LDR R1,=0x00000001
        STR R1, [R0]
        
;; Set CFGR1 register with flash memory remap at address 0

        LDR R0,=0x40010000 
        LDR R1,=0x00000000
        STR R1, [R0]
ApplicationStart         
                 LDR     R0, =SystemInit
                 BLX     R0
                 LDR     R0, =__main
                 BX      R0
                 ENDP

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                    [WEAK]
                B       .
                ENDP
HardFault_Handler\
				PROC
                EXPORT  HardFault_Handler              [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                    [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler                 [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler                [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  WWDG_IRQHandler                	[WEAK]
                EXPORT  USART1_IRQHandler               [WEAK]
                EXPORT  USART2_IRQHandler               [WEAK]
                EXPORT  USART3_IRQHandler               [WEAK]
                EXPORT  I2C1_IRQHandler            	 	[WEAK]
                EXPORT  EXTI0_1_IRQHandler             	[WEAK]
                EXPORT  EXTI2_3_IRQHandler             	[WEAK]
                EXPORT  EXTI4_15_IRQHandler            	[WEAK]
                EXPORT  DMA1_IRQHandler       			[WEAK]
                EXPORT  DMA2_IRQHandler            		[WEAK]
                EXPORT  TIM1_IRQHandler 				[WEAK]
                EXPORT  TIM2_IRQHandler                	[WEAK]
                EXPORT  TIM6_IRQHandler               	[WEAK]
                EXPORT  TIM7_IRQHandler               	[WEAK]
                EXPORT  SPI1_IRQHandler               	[WEAK]
                EXPORT  SPI2_IRQHandler                 [WEAK]
                EXPORT  SPI3_IRQHandler                 [WEAK]
				EXPORT  CIM_IRQHandler                	[WEAK]


WWDG_IRQHandler
USART1_IRQHandler
USART2_IRQHandler
USART3_IRQHandler
I2C1_IRQHandler
EXTI0_1_IRQHandler
EXTI2_3_IRQHandler
EXTI4_15_IRQHandler
DMA1_IRQHandler
DMA2_IRQHandler
TIM1_IRQHandler
TIM2_IRQHandler
TIM6_IRQHandler
TIM7_IRQHandler
SPI1_IRQHandler
SPI2_IRQHandler
SPI3_IRQHandler
CIM_IRQHandler

		

     

                B       .

                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                 IF      :DEF:__MICROLIB
                
                 EXPORT  __initial_sp
                 EXPORT  __heap_base
                 EXPORT  __heap_limit
                
                 ELSE
                
                 IMPORT  __use_two_region_memory
                 EXPORT  __user_initial_stackheap
                 
__user_initial_stackheap

                 LDR     R0, =  Heap_Mem
                 LDR     R1, =(Stack_Mem + Stack_Size)
                 LDR     R2, = (Heap_Mem +  Heap_Size)
                 LDR     R3, = Stack_Mem
                 BX      LR

                 ALIGN

                 ENDIF

                 END

;******************** (C) COPYRIGHT 2017 MindMotion ********************
