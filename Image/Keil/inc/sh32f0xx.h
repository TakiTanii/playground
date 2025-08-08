/**
  ******************************************************************************
  * @file    sh32f0xx.h
  * @author  MCD Application Team
  * @version V1.1.1
  * @date    7-April-2025
  * @brief   CMSIS Cortex-M0 Device Peripheral Access Layer Header File. 
  *          This file contains all the peripheral register's definitions, bits 
  *          definitions and memory mapping for SH32F0xx devices.  
  *          
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *           - Configuration section that allows to select:
  *              - The device used in the target application
  *              - To use or not the peripheral\u2019s drivers in application code(i.e. 
  *                code will be based on direct access to peripheral\u2019s registers 
  *                rather than drivers API), this option is controlled by 
  *                "#define USE_STDPERIPH_DRIVER"
  *              - To change few application-specific parameters such as the HSE 
  *                crystal frequency
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral\u2019s registers hardware
  *
  ******************************************************************************
**/


/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */


/**
 * @brief In the following line adjust the value of External High Speed oscillator (HSE)
   used in your application 
   
   Tip: To avoid modifying this file each time you need to use different HSE, you
        can define the HSE value in your toolchain compiler preprocessor.
  */

#ifndef __SH32F0XX_H
#define __SH32F0XX_H

#if !defined  (HSE_VALUE)     
#define HSE_VALUE    ((uint32_t)8000000) /*!< Value of the External oscillator in Hz*/
#endif /* HSE_VALUE */

/**
 * @brief In the following line adjust the External High Speed oscillator (HSE) Startup 
   Timeout value 
   */
#if !defined  (HSE_STARTUP_TIMEOUT)
#define HSE_STARTUP_TIMEOUT   ((uint16_t)0x5000) /*!< Time out for HSE start up */
#endif /* HSE_STARTUP_TIMEOUT */

/**
 * @brief In the following line adjust the Internal High Speed oscillator (HSI) Startup 
   Timeout value 
   */
#if !defined  (HSI_STARTUP_TIMEOUT)
#define HSI_STARTUP_TIMEOUT   ((uint16_t)0x5000) /*!< Time out for HSI start up */
#endif /* HSI_STARTUP_TIMEOUT */

#if !defined  (HSI_VALUE) 
#define HSI_VALUE  ((uint32_t)8000000) /*!< Value of the Internal High Speed oscillator in Hz.
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* HSI_VALUE */

#if !defined  (HSI14_VALUE) 
#define HSI14_VALUE ((uint32_t)14000000) /*!< Value of the Internal High Speed oscillator for ADC in Hz.
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* HSI14_VALUE */

#if !defined  (LSI_VALUE) 
#define LSI_VALUE  ((uint32_t)40000)    /*!< Value of the Internal Low Speed oscillator in Hz
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* LSI_VALUE */

#if !defined  (LSE_VALUE) 
#define LSE_VALUE  ((uint32_t)32768)    /*!< Value of the External Low Speed oscillator in Hz */
#endif /* LSE_VALUE */

/**
 * @brief SH32F0xx Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */
#define __CM0_REV                 0 /*!< Core Revision r0p0                            */
#define __MPU_PRESENT             0 /*!< SH32F0xx do not provide MPU                  */
#define __NVIC_PRIO_BITS          2 /*!< SH32F0xx uses 2 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0 /*!< Set to 1 if different SysTick Config is used  */

/*!< Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M0+ Processor Exceptions Numbers ******************************************************/
  NMI_IRQn                    = -14,    /*!< 2 Non Maskable Interrupt                                */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                        */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                          */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                          */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                      */

/******  SH01A specific Interrupt Numbers *****************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  USART1_IRQn                 = 1,      /*!< USART1 Interrupt                                        */
  USART2_IRQn                 = 2,      /*!< USART2 Interrupt                                        */
  USART3_IRQn                 = 3,      /*!< USART3 Interrupt                                        */
  I2C1_IRQn                   = 4,      /*!< I2C1 Interrupt                                          */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupts                            */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupts                            */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupts                            */
  DMA1_IRQn                   = 8,      /*!< DMA1 Interrupt                                          */
  DMA2_IRQn                   = 9,      /*!< DMA2 Interrupts                                         */
  TIM1_IRQn                   = 10,     /*!< TIM1 Interrupts                                         */
  TIM2_IRQn                   = 11,     /*!< TIM2 Interrupts                                         */
  TIM6_IRQn                   = 12,     /*!< TIM6 Interrupts                                         */
  TIM7_IRQn                   = 13,     /*!< TIM7 Interrupt                                          */
  SPI1_IRQn                   = 14,     /*!< SPI1 Interrupt                                          */
  SPI2_IRQn                   = 15,     /*!< SPI2 Interrupt                                          */
  SPI3_IRQn                   = 16,     /*!< SPI3 Interrupt                                          */
  CIM_IRQn                    = 17,     /*!< CIM Interrupt                                           */
} IRQn_Type;

/**
  * @}
  */

#include "core_cm0.h"
#include <stdint.h>
#include "sh32f0xx_conf.h"

/** @addtogroup Peripheral_registers_structures
  * @{
  */  

/** 
  * @brief Window WATCHDOG
  */

typedef struct
{
  __IO uint32_t CR;            /*!< WWDG Control register,                        Address offset: 0x000 */
  __IO uint32_t CFR;           /*!< WWDG Configuration register,                  Address offset: 0x004 */
  __IO uint32_t SR;            /*!< WWDG Status register,                         Address offset: 0x008 */
}WWDG_TypeDef;

/** 
  * @brief USART
  */

typedef struct
{
  __O   uint32_t  US_CR;                   /*!< Offset: 0x0000 Control Register                   (W)   */
  __IO  uint32_t  US_MR;                   /*!< Offset: 0x0004 Mode Register                      (R/W) */
  __O   uint32_t  US_IER;                  /*!< Offset: 0x0008 Interrupt Enable Register          (W)   */
  __O   uint32_t  US_IDR;                  /*!< Offset: 0x000C Interrupt Disable Register         (W)   */
  __O   uint32_t  US_IMR;                  /*!< Offset: 0x0010 Interrupt Mask Register            (R)   */
  __I   uint32_t  US_CSR;                  /*!< Offset: 0x0014 Channel Status Register            (R)   */
  __I   uint32_t  US_RHR;                  /*!< Offset: 0x0018 Receive Holding Register           (R)   */
  __O   uint32_t  US_THR;                  /*!< Offset: 0x001C Transmit Holding Register          (W)   */
  __IO  uint32_t  US_BRGR;                 /*!< Offset: 0x0020 Baud Rate Generator Register       (R/W) */
  __IO  uint32_t  US_RTOR;                 /*!< Offset: 0x0024 Receiver Time-out Register         (R/W) */
  __IO  uint32_t  US_TTGR;                 /*!< Offset: 0x0028 Transmitter Timeguard Register     (R/W) */
  __IO  uint32_t  US_XXX0;                 /*!< Offset: 0x002C Empty Register                     (R/W) */
  __I   uint32_t  US_RXPO;                 /*!< Offset: 0x0030 Receiver Pointer Register          (R)   */
  __I   uint32_t  US_RXCO;                 /*!< Offset: 0x0034 Receiver Counter Register          (R)   */
  __I   uint32_t  US_TXPO;                 /*!< Offset: 0x0038 Transmitter Pointer Register       (R)   */
  __I   uint32_t  US_TXCO;                 /*!< Offset: 0x003C Transmitter Counter Register       (R)   */
  __IO  uint32_t  US_FIDI;                 /*!< Offset: 0x0040 FI DI RATIO Register               (R/W) */
  __I   uint32_t  US_NER;                  /*!< Offset: 0x0044 Number of Errors Register          (R)   */
  __IO  uint32_t  US_XOXF;                 /*!< Offset: 0x0048 XON XOFF Register                  (R/W) */
  __IO  uint32_t  US_IF;                   /*!< Offset: 0x004C IrDA FILTER Register               (R/W) */
  __IO  uint32_t  US_MAN;                  /*!< Offset: 0x0050 Manchester Configuration Register  (R/W) */
  __IO  uint32_t  US_LINMR;                /*!< Offset: 0x0054 LIN Mode Register                  (R/W) */
  __IO  uint32_t  US_LINIR;                /*!< Offset: 0x0058 LIN Identifier Register            (R/W) */
  __I   uint32_t  US_LINBRR;               /*!< Offset: 0x005C LIN Baud Rate Register             (R)   */
  __IO  uint32_t  US_LONMR;                /*!< Offset: 0x0060 LON Mode Register                  (R/W) */
  __IO  uint32_t  US_LONPR;                /*!< Offset: 0x0064 LON Preamble Register              (R/W) */
  __IO  uint32_t  US_LONDL;                /*!< Offset: 0x0068 LON Data Length Register           (R/W) */
  __IO  uint32_t  US_LONL2HDR;             /*!< Offset: 0x006C LON L2HDR Register                 (R/W) */
  __I   uint32_t  US_LONBL;                /*!< Offset: 0x0070 LON Backlog Register               (R)   */
  __IO  uint32_t  US_LONB1TX;              /*!< Offset: 0x0074 LON Beta1 Tx Register              (R/W) */
  __IO  uint32_t  US_LONB1RX;              /*!< Offset: 0x0078 LON Beta1 Rx Register              (R/W) */
  __IO  uint32_t  US_LONPRIO;              /*!< Offset: 0x007C LON Priority Register              (R/W) */
  __IO  uint32_t  US_IDTTX;                /*!< Offset: 0x0080 LON IDT Tx Register                (R/W) */
  __IO  uint32_t  US_IDTRX;                /*!< Offset: 0x0084 LON IDT Rx Register                (R/W) */
  __IO  uint32_t  US_ICDIFF;               /*!< Offset: 0x0088 IC DIFF Register                   (R/W) */
  __IO  uint32_t  US_XXX1;                 /*!< Offset: 0x008C Empty Register                     (R/W) */
  __IO  uint32_t  US_XXX2;                 /*!< Offset: 0x0090 Empty Register                     (R/W) */
  __IO  uint32_t  US_XXX3;                 /*!< Offset: 0x0094 Empty Register                     (R/W) */
  __IO  uint32_t  US_XXX4;                 /*!< Offset: 0x0098 Empty Register                     (R/W) */
  __IO  uint32_t  US_XXX5;                 /*!< Offset: 0x009C Empty Register                     (R/W) */
  __IO  uint32_t  US_XXX6;                 /*!< Offset: 0x00A0 Empty Register                     (R/W) */
  __IO  uint32_t  US_XXX7;                 /*!< Offset: 0x00A4 Empty Register                     (R/W) */
  __IO  uint32_t  US_XXX8;                 /*!< Offset: 0x00A8 Empty Register                     (R/W) */
  __IO  uint32_t  US_XXX9;                 /*!< Offset: 0x00AC Empty Register                     (R/W) */
  __IO  uint32_t  US_XX10;                 /*!< Offset: 0x00B0 Empty Register                     (R/W) */
  __IO  uint32_t  US_XX11;                 /*!< Offset: 0x00B4 Empty Register                     (R/W) */
  __IO  uint32_t  US_XX12;                 /*!< Offset: 0x00B8 Empty Register                     (R/W) */
  __IO  uint32_t  US_XX13;                 /*!< Offset: 0x00BC Empty Register                     (R/W) */
  __IO  uint32_t  US_XX14;                 /*!< Offset: 0x00C0 Empty Register                     (R/W) */
  __IO  uint32_t  US_XX15;                 /*!< Offset: 0x00C4 Empty Register                     (R/W) */
  __IO  uint32_t  US_XX16;                 /*!< Offset: 0x00C8 Empty Register                     (R/W) */
  __IO  uint32_t  US_XX17;                 /*!< Offset: 0x00CC Empty Register                     (R/W) */
  __IO  uint32_t  US_XX18;                 /*!< Offset: 0x00D0 Empty Register                     (R/W) */
  __IO  uint32_t  US_XX19;                 /*!< Offset: 0x00D4 Empty Register                     (R/W) */
  __IO  uint32_t  US_XX20;                 /*!< Offset: 0x00D8 Empty Register                     (R/W) */
  __IO  uint32_t  US_XX21;                 /*!< Offset: 0x00DC Empty Register                     (R/W) */
  __IO  uint32_t  US_COUN;                 /*!< Offset: 0x00E0 Country Register                   (R/W) */
  __IO  uint32_t  US_WPMR;                 /*!< Offset: 0x00E4 Write Protect Mode Register        (R/W) */
  __IO  uint32_t  US_WPSR;                 /*!< Offset: 0x00E8 Write Protect Status Register      (R/W) */
  __IO  uint32_t  US_ADSI;                 /*!< Offset: 0x00EC ADDRSIZE Register                  (R/W) */
  __IO  uint32_t  US_NAM1;                 /*!< Offset: 0x00F0 NAME1 Register                     (R/W) */
  __IO  uint32_t  US_NAM2;                 /*!< Offset: 0x00F4 NAME2 Register                     (R/W) */
  __IO  uint32_t  US_FEAT;                 /*!< Offset: 0x00F8 FEATURES Register                  (R/W) */
  __I   uint32_t  US_VERSION;              /*!< Offset: 0x00FC Version Register                   (R)   */
} USART_TypeDef;

/** 
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t IDREV;           /*!<                                              Address offset: 0x00 */
       uint32_t RESERVED0;       /*!< Reserved,                                    Address offset: 0x04 */
       uint32_t RESERVED1;       /*!< Reserved,                                    Address offset: 0x08 */
       uint32_t RESERVED2;       /*!< Reserved,                                    Address offset: 0x0C */
  __IO uint32_t CFG;             /*!< I2C Configuration Register,                  Address offset: 0x10 */
  __IO uint32_t INTEN;           /*!< I2C Interrupt Enable Register,               Address offset: 0x14 */
  __IO uint32_t STATUS;          /*!< I2C Status Register,                         Address offset: 0x18 */
  __IO uint32_t ADDR;            /*!< I2C Address Register,                        Address offset: 0x1C */
  __IO uint32_t DATA;            /*!< I2C Data register,                           Address offset: 0x20 */
  __IO uint32_t CTRL;            /*!< I2C Control register,                        Address offset: 0x24 */
  __IO uint32_t CMD;             /*!< I2C Command register,                        Address offset: 0x28 */
  __IO uint32_t SETUP;           /*!< I2C Setup register,                          Address offset: 0x2C */
  __IO uint32_t TPM;             /*!< I2C Timing parameter multiplier register,    Address offset: 0x30 */
  __IO uint32_t TIMING;          /*!< I2C Timing register,                         Address offset: 0x34 */
  __IO uint32_t MASK;            /*!< I2C Make register,                           Address offset: 0x34 */
  __I  uint32_t REC_ADDR;        /*!< I2C Receive address register,                Address offset: 0x34 */
}I2C_TypeDef;

/** 
  * @brief EXTI
  */

typedef struct{
  __IO  uint32_t  RTSR;       /*!< EXTI Rising Edge Selection Register             Address offset: 0x00 */
  __IO  uint32_t  FTSR;       /*!< EXTI Falling Edge Selection Register            Address offset: 0x04 */
  __O   uint32_t  SWIER;      /*!< EXTI Software Interrupt Event Register          Address offset: 0x08 */
  __IO  uint32_t  PR;         /*!< EXTI Pending Register                           Address offset: 0x0C */
  __IO  uint32_t  EXTICR1;    /*!< EXTI Configuration Register 1                   Address offset: 0x10 */
  __IO  uint32_t  EXTICR2;    /*!< EXTI Configuration Register 2                   Address offset: 0x14 */
  __IO  uint32_t  IMR;        /*!< EXTI Interrupt Masking Register                 Address offset: 0x18 */
  __IO  uint32_t  EMR;        /*!< EXTI Event Masking Register                     Address offset: 0x1C */
}EXTI_TypeDef;

/** 
  * @brief DMA
  */

typedef struct
{
  __IO uint32_t CCR;          /*!< DMA channel x configuration register        Address offset: 0x10*(x)       */
  __IO uint32_t CNDTR;        /*!< DMA channel x number of data register       Address offset: 0x10*(x) + 0x4 */
  __IO uint32_t CPAR;         /*!< DMA channel x peripheral address register   Address offset: 0x10*(x) + 0x8 */
  __IO uint32_t CMAR;         /*!< DMA channel x memory address register       Address offset: 0x10*(x) + 0xC */
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;          /*!< DMA interrupt status register,             Address offset: 0x00            */
  __IO uint32_t IFCR;         /*!< DMA interrupt flag clear register          Address offset: 0x04            */
} DMA_TypeDef;

/** 
  * @brief TIM
  */  

typedef struct
{
  __IO uint32_t CR1;             /*!< TIM control register 1,                      Address offset: 0x00 */
  __IO uint32_t CR2;             /*!< TIM control register 2,                      Address offset: 0x04 */
  __IO uint32_t SMCR;            /*!< TIM slave Mode Control register,             Address offset: 0x08 */
  __IO uint32_t DIER;            /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
  __IO uint32_t SR;              /*!< TIM status register,                         Address offset: 0x10 */
  __IO uint32_t EGR;             /*!< TIM event generation register,               Address offset: 0x14 */
  __IO uint32_t CCMR1;           /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
  __IO uint32_t CCMR2;           /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
  __IO uint32_t CCER;            /*!< TIM capture/compare enable register,         Address offset: 0x20 */
  __IO uint32_t CNT;             /*!< TIM counter register,                        Address offset: 0x24 */
  __IO uint32_t PSC;             /*!< TIM prescaler register,                      Address offset: 0x28 */
  __IO uint32_t ARR;             /*!< TIM auto-reload register,                    Address offset: 0x2C */
  __IO uint32_t RCR;             /*!< TIM  repetition counter register,            Address offset: 0x30 */
  __IO uint32_t CCR1;            /*!< TIM capture/compare register 1,              Address offset: 0x34 */
  __IO uint32_t CCR2;            /*!< TIM capture/compare register 2,              Address offset: 0x38 */
  __IO uint32_t CCR3;            /*!< TIM capture/compare register 3,              Address offset: 0x3C */
  __IO uint32_t CCR4;            /*!< TIM capture/compare register 4,              Address offset: 0x40 */
  __IO uint32_t BDTR;            /*!< TIM break and dead-time register,            Address offset: 0x44 */
  __IO uint32_t DCR;             /*!< TIM DMA control register,                    Address offset: 0x48 */
  __IO uint32_t DMAR;            /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
} TIM_TypeDef;

/** 
  * @brief DW_APB_SSI STRUCT
  */

typedef struct {
  __IO uint32_t CTRLR0;               // Control register 0
  __IO uint32_t CTRLR1;               // Control register 1
  __IO uint32_t SSIENR;               // SPI enable register
  __IO uint32_t MWCR;                 // Microwire control register
  __IO uint32_t SER;                  // Slave enable register
  __IO uint32_t BAUDR;                // Baud rate register
  __IO uint32_t TXFTLR;               // Transmit FIFO threshold register
  __IO uint32_t RXFTLR;               // Receive FIFO threshold register
  __IO uint32_t TXFLR;                // Transmit FIFO level register
  __IO uint32_t RXFLR;                // Receive FIFO level register
  __IO uint32_t SR;                   // Status register
  __IO uint32_t IMR;                  // Interrupt mask register
  __IO uint32_t ISR;                  // Interrupt status register
  __IO uint32_t RISR;                 // Raw interrupt status register
  __IO uint32_t TXOICR;               // Transmit FIFO overflow interrupt clear register
  __IO uint32_t RXOICR;               // Receive FIFO overflow interrupt clear register
  __IO uint32_t RXUICR;               // Receive FIFO underflow interrupt clear register
  __IO uint32_t MSTICR;               // Master interrupt clear register
  __IO uint32_t ICR;                  // Interrupt clear register
  __IO uint32_t DMACR;                // DMA control register
  __IO uint32_t DMATDLR;              // DMA transmit data level register
  __IO uint32_t DMARDLR;              // DMA receive data level register
  __IO uint32_t IDR;                  // SPI controller identification register
  __IO uint32_t SSI_VERSION_ID;       // SPI version register
  __IO uint32_t DR[35];               // Data register
  __IO uint32_t RSVD_X;               // Data register	
  __IO uint32_t RX_SAMPLE_DLY;        // Receive sample delay register
  __IO uint32_t SPI_CTRLR0;           // SPI control register 0
  __IO uint32_t TXD_DRIVE_EDGE;       // Transmit data drive edge control register
  __IO uint32_t RSVD;                 // Reserved register
} SPI_TypeDef;


/** 
  * @brief Reset and Clock control
  */

typedef struct
{
  __IO uint32_t CR;       /*!< RCC Clock control register                                 Address offset:0x00 */
  __IO uint32_t CFGR;     /*!< RCC Clock configuration register                           Address offset:0x04 */
  __IO uint32_t CIR;      /*!< RCC Clock interrupt register                               Address offset:0x08 */
  __IO uint32_t AHBRSTR;  /*!< RCC AHB peripheral reset register                          Address offset:0x0C */
  __IO uint32_t APBRSTR1; /*!< RCC APB peripheral reset register 1                        Address offset:0x10 */
  __IO uint32_t AHBENR;   /*!< RCC AHB peripheral clock enable register                   Address offset:0x14 */
  __IO uint32_t APBENR1;  /*!< RCC APB peripheral clock enable register 1                 Address offset:0x18 */
  __IO uint32_t CCIPR;    /*!< RCC Peripherals independent clock configuration register   Address offset:0x1C */
  __IO uint32_t BDCR;     /*!< RCC RTC domain control register                            Address offset:0x20 */ 
  __IO uint32_t CSR;      /*!< RCC Control/status register                                Address offset:0x24 */
  __IO uint32_t HSITRIM;  /*!< RCC HSI Internal clock sources calibration register        Address offset:0x28 */
  __IO uint32_t LSITRIM;  /*!< RCC LSI Internal clock sources calibration register        Address offset:0x2C */
  __IO uint32_t HSICNT;   /*!< RCC HSI counter register                                   Address offset:0x30 */
  __IO uint32_t HSECNT;   /*!< RCC HSE counter register                                   Address offset:0x34 */
  __IO uint32_t LSICNT;   /*!< RCC LSI counter register                                   Address offset:0x38 */
  __IO uint32_t LSECNT;   /*!< RCC LSE counter register                                   Address offset:0x3C */
} RCC_TypeDef;

/** 
  * @brief CRC
  */

typedef struct
{
  __IO uint32_t DR;           /*!< CRC data register                                       Address offset: 0x00 */
  __IO uint32_t MIR;          /*!< CRC middle data register                                Address offset: 0x04 */
  __IO uint32_t CR;           /*!< CRC control                                             Address offset: 0x08 */
} CRC_TypeDef;

/** 
  * @brief GPIO STRUCT 
  */
typedef struct
{	
  __IO uint32_t MODER; 			// Address offset:0x00
  __IO uint32_t OTYPER;	        // Address offset:0x04
  __IO uint32_t PUPDR; 	        // Address offset:0x08
  __IO uint32_t DIRR;    	    // Address offset:0x0C
  __I  uint32_t IDR;   	        // Address offset:0x10
  __IO uint32_t ODR;   	        // Address offset:0x14
  __IO uint32_t BSRR;  	        // Address offset:0x18
  __IO uint32_t LCKR;  	        // Address offset:0x1C
  __IO uint32_t AFRL;  	        // Address offset:0x20
  __IO uint32_t AFRH;  	        // Address offset:0x24
  __IO uint32_t BRR;   	        // Address offset:0x28
} GPIO_TypeDef;

/**
  * @brief System configuration controller
  */

typedef struct
{
  __IO    uint32_t  CFGR;             /*!< SYSCFG Configuration register,               Address offset:0x00 */
  __IO    uint32_t  FLASH_VREF_TRIM;  /*!< SYSCFG Flash Voltage Reference Triming       Address offset:0x04 */
} SYSCFG_TypeDef;

/**
  * @brief Debug Support
  */

typedef struct
{
  __IO    uint32_t  IDCODE;           /*!< DBG Device ID Code register,                 Address offset:0x00 */
  __IO    uint32_t  APB_FZ;           /*!< DBG APB Freeze register,                     Address offset:0x04 */
} DBG_TypeDef;

/**
  * @brief Power Control
  */

typedef struct
{
  __IO    uint32_t  CR;               /*!<PWR Control register,                         Address offset:0x00 */
  __IO    uint32_t  SR;               /*!<PWR Status register,                          Address offset:0x04 */
} PWR_TypeDef;

/**
  * @brief FSMC Control Register
  */

typedef struct {
  __IO uint32_t SCONR;                  /*!< SDRAM configuration register,                          Address offset: 0x00 */
  __IO uint32_t STMG0R;                 /*!< SDRAM timing register0,                                Address offset: 0x04 */
  __IO uint32_t STMG1R;                 /*!< SDRAM timing register1,                                Address offset: 0x08 */
  __IO uint32_t SCTLR;                  /*!< SDRAM control register,                                Address offset: 0x0C */
  __IO uint32_t SREFR;                  /*!< SDRAM refresh register,                                Address offset: 0x10 */
  __IO uint32_t SCSLR0_LOW;             /*!< Chip select register0 (lower 32-bits),                 Address offset: 0x14 */
  __IO uint32_t SCSLR1_LOW;             /*!< Chip select register1 (lower 32-bits),                 Address offset: 0x18 */
  __IO uint32_t SCSLR2_LOW;             /*!< Chip select register2 (lower 32-bits),                 Address offset: 0x1C */
  __IO uint32_t SCSLR3_LOW;             /*!< Chip select register3 (lower 32-bits),                 Address offset: 0x20 */
  __IO uint32_t SCSLR4_LOW;             /*!< Chip select register4 (lower 32-bits),                 Address offset: 0x24 */
  __IO uint32_t SCSLR5_LOW;             /*!< Chip select register5 (lower 32-bits),                 Address offset: 0x28 */
  __IO uint32_t SCSLR6_LOW;             /*!< Chip select register6 (lower 32-bits),                 Address offset: 0x2C */
  __IO uint32_t SCSLR7_LOW;             /*!< Chip select register7 (lower 32-bits),                 Address offset: 0x30 */
       uint32_t RESERVED0[8];           /*!< Reserved for SCSLRn_HIGH registers,                             0x34 - 0x50 */
  __IO uint32_t SMSKR0;                 /*!< Mask register 0,                                       Address offset: 0x54 */
  __IO uint32_t SMSKR1;                 /*!< Mask register 1,                                       Address offset: 0x58 */
  __IO uint32_t SMSKR2;                 /*!< Mask register 2,                                       Address offset: 0x5C */
  __IO uint32_t SMSKR3;                 /*!< Mask register 3,                                       Address offset: 0x60 */
  __IO uint32_t SMSKR4;                 /*!< Mask register 4,                                       Address offset: 0x64 */
  __IO uint32_t SMSKR5;                 /*!< Mask register 5,                                       Address offset: 0x68 */
  __IO uint32_t SMSKR6;                 /*!< Mask register 6,                                       Address offset: 0x6C */
  __IO uint32_t SMSKR7;                 /*!< Mask register 7,                                       Address offset: 0x70 */
  __IO uint32_t CSALIAS0_LOW;           /*!< Alias register for chip select0 (lower 32-bits),       Address offset: 0x74 */
  __IO uint32_t CSALIAS1_LOW;           /*!< Alias register for chip select1 (lower 32-bits),       Address offset: 0x78 */
       uint32_t RESERVED1[2];           /*!< Reserved for CSALIASn_HIGH registers,                           0x7C - 0x80 */
  __IO uint32_t CSREMAP0_LOW;           /*!< Remap register for chip select1 (lower 32-bits),       Address offset: 0x84 */
  __IO uint32_t CSREMAP1_LOW;           /*!< Remap register for chip select1 (lower 32-bits),       Address offset: 0x88 */
       uint32_t RESERVED2[2];           /*!< Reserved for CSREMAPn_HIGH registers,                           0x8C - 0x90 */
  __IO uint32_t SMTMGR_SET0;            /*!< Static memory timing register Set0,                    Address offset: 0x94 */
  __IO uint32_t SMTMGR_SET1;            /*!< Static memory timing register Set1,                    Address offset: 0x98 */
  __IO uint32_t SMTMGR_SET2;            /*!< Static memory timing register Set2,                    Address offset: 0x9C */
  __IO uint32_t FLASH_TRPDR;            /*!< FLASH memory tRPD timing register,                     Address offset: 0xA0 */
  __IO uint32_t SMCTLR;                 /*!< Static memory control register,                        Address offset: 0xA4 */
  __IO uint32_t SYNC_FLASH_OPCODE;      /*!< SYNCFLASH OPCODE register,                             Address offset: 0xA8 */
  __IO uint32_t ETN_MODE_REG;           /*!< Extension mode register,                               Address offset: 0xAC */
  __IO uint32_t SFCONR;                 /*!< SYNCFLASH configuration register,                      Address offset: 0xB0 */
  __IO uint32_t SFCTLR;                 /*!< SYNCFLASH control register,                            Address offset: 0xB4 */
  __IO uint32_t SFTMGR;                 /*!< SYNCFLASH timing register,                             Address offset: 0xB8 */
} FSMC_REG_TypeDef;



#define SRAM_BASE             ((uint32_t)0x20000000) /*!< SRAM base address in the alias region */
#define PERIPH_BASE           ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region */

/*!< Peripheral memory map */
#define APBPERIPH_BASE        PERIPH_BASE
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000)
#define IOPORT_BASE           ((uint32_t)0x50000000) /*!< IOPORT base address for FGPIO */
#define FSMC_BASE             ((uint32_t)0x60000000)        /*!< FSMC memory */
#define FSMC_REG_BASE         (FSMC_BASE   + 0x02000000)    /*!< FSMC register */

/*!< APB peripherals */
#define USART1_BASE           (APBPERIPH_BASE + 0x00000000) /*!< USART1 base address */
#define USART2_BASE           (APBPERIPH_BASE + 0x00000400) /*!< USART2 base address */
#define USART3_BASE           (APBPERIPH_BASE + 0x00000800) /*!< USART3 base address */
#define EXTI_BASE             (APBPERIPH_BASE + 0x00000C00) /*!< EXTI base address   */
#define SYSCFG_BASE           (APBPERIPH_BASE + 0x00001000) /*!< SYSCFG base address */
#define DBG_BASE              (APBPERIPH_BASE + 0x00001100) /*!< DBG base address    */
#define PWR_BASE              (APBPERIPH_BASE + 0x00001200) /*!< PWR base address    */
#define I2C1_BASE             (APBPERIPH_BASE + 0x00001400) /*!< I2C1 base address   */
#define SPI1_BASE             (APBPERIPH_BASE + 0x00001800) /*!< SPI1 base address   */
#define TIM1_BASE             (APBPERIPH_BASE + 0x00001C00) /*!< TIM1 base address   */
#define TIM2_BASE             (APBPERIPH_BASE + 0x00002000) /*!< TIM2 base address   */
#define TIM6_BASE             (APBPERIPH_BASE + 0x00002400) /*!< TIM6 base address   */
#define TIM7_BASE             (APBPERIPH_BASE + 0x00002800) /*!< TIM7 base address   */
#define WWDG_BASE             (APBPERIPH_BASE + 0x00002C00) /*!< WWDG base address   */
#define SPI2_BASE             (APBPERIPH_BASE + 0x00010000) /*!< SPI2 base address   */
#define SPI3_BASe             (APBPERIPH_BASE + 0x00010400) /*!< SPI3 base address   */

/*!< AHB peripherals */
#define DMA1_BASE             (AHBPERIPH_BASE + 0x00000000) /*!< DMA1 base address          */
#define DMA1_Channel1_BASE    (DMA1_BASE      + 0x00000010) /*!< DMA1 Channel1 base address */
#define DMA1_Channel2_BASE    (DMA1_BASE      + 0x00000020) /*!< DMA1 Channel2 base address */
#define DMA1_Channel3_BASE    (DMA1_BASE      + 0x00000030) /*!< DMA1 Channel3 base address */
#define DMA1_Channel4_BASE    (DMA1_BASE      + 0x00000040) /*!< DMA1 Channel4 base address */
#define DMA1_Channel5_BASE    (DMA1_BASE      + 0x00000050) /*!< DMA1 Channel5 base address */
#define DMA1_Channel6_BASE    (DMA1_BASE      + 0x00000060) /*!< DMA1 Channel6 base address */
#define DMA1_Channel7_BASE    (DMA1_BASE      + 0x00000070) /*!< DMA1 Channel7 base address */
#define DMA1_Channel8_BASE    (DMA1_BASE      + 0x00000080) /*!< DMA1 Channel8 base address */
#define DMA2_BASE             (AHBPERIPH_BASE + 0x00000400) /*!< DMA2 base address          */
#define DMA2_Channel1_BASE    (DMA2_BASE      + 0x00000010) /*!< DMA2 Channel1 base address */
#define DMA2_Channel2_BASE    (DMA2_BASE      + 0x00000020) /*!< DMA2 Channel2 base address */
#define DMA2_Channel3_BASE    (DMA2_BASE      + 0x00000030) /*!< DMA2 Channel3 base address */
#define DMA2_Channel4_BASE    (DMA2_BASE      + 0x00000040) /*!< DMA2 Channel4 base address */
#define DMA2_Channel5_BASE    (DMA2_BASE      + 0x00000050) /*!< DMA2 Channel5 base address */
#define DMA2_Channel6_BASE    (DMA2_BASE      + 0x00000060) /*!< DMA2 Channel6 base address */
#define DMA2_Channel7_BASE    (DMA2_BASE      + 0x00000070) /*!< DMA2 Channel7 base address */
#define DMA2_Channel8_BASE    (DMA2_BASE      + 0x00000080) /*!< DMA2 Channel8 base address */

#define RCC_BASE              (AHBPERIPH_BASE + 0x00000800) /*!< RCC base address   */
#define CRC_BASE              (AHBPERIPH_BASE + 0x00000C00) /*!< CRC base address   */
#define CIM_BASE              (AHBPERIPH_BASE + 0x00001000) /*!< CIM base address   */
#define GPIO_BASE             (AHBPERIPH_BASE + 0x00001800) /*!< GPIO base address  */
#define GPIOA_BASE            (GPIO_BASE      + 0x00000000) /*!< GPIOA base address */
#define GPIOB_BASE            (GPIO_BASE      + 0x00000100) /*!< GPIOB base address */
#define GPIOC_BASE            (GPIO_BASE      + 0x00000200) /*!< GPIOC base address */
#define GPIOD_BASE            (GPIO_BASE      + 0x00000300) /*!< GPIOD base address */
#define GPIOE_BASE            (GPIO_BASE      + 0x00000400) /*!< GPIOD base address */
#define GPIOF_BASE            (GPIO_BASE      + 0x00000500) /*!< GPIOD base address */

/*!< IOPORT peripherals */
#define FGPIO_BASE            (IOPORT_BASE + 0x00000000)    /*!< FGPIO base address */

#define FGPIOA_BASE           (IOPORT_BASE + 0x00000000)    /*!< FGPIO base address */
#define FGPIOB_BASE           (IOPORT_BASE + 0x00000100)    /*!< FGPIO base address */
#define FGPIOC_BASE           (IOPORT_BASE + 0x00000200)    /*!< FGPIO base address */
#define FGPIOD_BASE           (IOPORT_BASE + 0x00000300)    /*!< FGPIO base address */
#define FGPIOE_BASE           (IOPORT_BASE + 0x00000400)    /*!< FGPIO base address */
#define FGPIOF_BASE           (IOPORT_BASE + 0x00000500)    /*!< FGPIO base address */

/**
  * @}
  */
  
/** @addtogroup Peripheral_declaration
  * @{
  */ 

/*!< APB peripherals */
#define USART1           ((USART_TypeDef  *) USART1_BASE) /*!< USART1 base address */
#define USART2           ((USART_TypeDef  *) USART2_BASE) /*!< USART2 base address */
#define USART3           ((USART_TypeDef  *) USART3_BASE) /*!< USART3 base address */
#define EXTI             ((EXTI_TypeDef   *) EXTI_BASE  ) /*!< EXTI base address   */
#define SYSCFG           ((SYSCFG_TypeDef *) SYSCFG_BASE) /*!< SYSCFG base address */
#define DBG              ((DBG_TypeDef    *) DBG_BASE   ) /*!< DBG base address    */
#define PWR              ((PWR_TypeDef    *) PWR_BASE   ) /*!< PWR base address    */
#define I2C1             ((I2C_TypeDef    *) I2C1_BASE  ) /*!< I2C1 base address   */
#define SPI1             ((SPI_TypeDef    *) SPI1_BASE  ) /*!< SPI1 base address   */
#define TIM1             ((TIM_TypeDef    *) TIM1_BASE  ) /*!< TIM1 base address   */
#define TIM2             ((TIM_TypeDef    *) TIM2_BASE  ) /*!< TIM2 base address   */
#define TIM6             ((TIM_TypeDef    *) TIM6_BASE  ) /*!< TIM6 base address   */
#define TIM7             ((TIM_TypeDef    *) TIM7_BASE  ) /*!< TIM7 base address   */
#define WWDG             ((WWDG_TypeDef   *) WWDG_BASE  ) /*!< WWDG base address   */
#define SPI2             ((SPI_TypeDef    *) SPI2_BASE  ) /*!< SPI2 base address   */
#define SPI3             ((SPI_TypeDef    *) SPI3_BASe  ) /*!< SPI3 base address   */

/*!< AHB peripherals */
#define DMA1             ((DMA_TypeDef         *) DMA1_BASE         ) /*!< DMA1 base address          */
#define DMA1_Channel1    ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE) /*!< DMA1 Channel1 base address */
#define DMA1_Channel2    ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE) /*!< DMA1 Channel2 base address */
#define DMA1_Channel3    ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE) /*!< DMA1 Channel3 base address */
#define DMA1_Channel4    ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE) /*!< DMA1 Channel4 base address */
#define DMA1_Channel5    ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE) /*!< DMA1 Channel5 base address */
#define DMA1_Channel6    ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE) /*!< DMA1 Channel6 base address */
#define DMA1_Channel7    ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE) /*!< DMA1 Channel7 base address */
#define DMA1_Channel8    ((DMA_Channel_TypeDef *) DMA1_Channel8_BASE) /*!< DMA1 Channel8 base address */
#define DMA2             ((DMA_TypeDef         *) DMA2_BASE         ) /*!< DMA2 base address          */
#define DMA2_Channel1    ((DMA_Channel_TypeDef *) DMA2_Channel1_BASE) /*!< DMA2 Channel1 base address */
#define DMA2_Channel2    ((DMA_Channel_TypeDef *) DMA2_Channel2_BASE) /*!< DMA2 Channel2 base address */
#define DMA2_Channel3    ((DMA_Channel_TypeDef *) DMA2_Channel3_BASE) /*!< DMA2 Channel3 base address */
#define DMA2_Channel4    ((DMA_Channel_TypeDef *) DMA2_Channel4_BASE) /*!< DMA2 Channel4 base address */
#define DMA2_Channel5    ((DMA_Channel_TypeDef *) DMA2_Channel5_BASE) /*!< DMA2 Channel5 base address */
#define DMA2_Channel6    ((DMA_Channel_TypeDef *) DMA2_Channel6_BASE) /*!< DMA2 Channel6 base address */
#define DMA2_Channel7    ((DMA_Channel_TypeDef *) DMA2_Channel7_BASE) /*!< DMA2 Channel7 base address */
#define DMA2_Channel8    ((DMA_Channel_TypeDef *) DMA2_Channel8_BASE) /*!< DMA2 Channel8 base address */
                                        
#define RCC              ((RCC_TypeDef   *) RCC_BASE  ) /*!< RCC base address   */
#define CRC              ((CRC_TypeDef   *) CRC_BASE  ) /*!< CRC base address   */
#define CIM              ((CIM_TypeDef   *) CIM_BASE  ) /*!< CIM base address   */
#define GPIO             ((GPIO_TypeDef  *) GPIO_BASE ) /*!< GPIO base address  */
#define GPIOA            ((GPIO_TypeDef  *) GPIOA_BASE) /*!< GPIOA base address */
#define GPIOB            ((GPIO_TypeDef  *) GPIOB_BASE) /*!< GPIOB base address */
#define GPIOC            ((GPIO_TypeDef  *) GPIOC_BASE) /*!< GPIOC base address */
#define GPIOD            ((GPIO_TypeDef  *) GPIOD_BASE) /*!< GPIOD base address */
#define GPIOE            ((GPIO_TypeDef  *) GPIOE_BASE) /*!< GPIOD base address */
#define GPIOF            ((GPIO_TypeDef  *) GPIOF_BASE) /*!< GPIOD base address */

/* IOPORT peripherals */
#define FGPIO            ((GPIO_TypeDef *) FGPIO_BASE)          /*!< FGPIO */

#define FGPIOA           ((GPIO_TypeDef *) FGPIOA_BASE)         /*!< FGPIO */
#define FGPIOB           ((GPIO_TypeDef *) FGPIOB_BASE)         /*!< FGPIO */
#define FGPIOC           ((GPIO_TypeDef *) FGPIOC_BASE)         /*!< FGPIO */
#define FGPIOD           ((GPIO_TypeDef *) FGPIOD_BASE)         /*!< FGPIO */
#define FGPIOE           ((GPIO_TypeDef *) FGPIOE_BASE)         /*!< FGPIO */
#define FGPIOF           ((GPIO_TypeDef *) FGPIOF_BASE)         /*!< FGPIO */

/*!< FSMC */
#define FSMC_REG         ((FSMC_REG_TypeDef *) FSMC_REG_BASE) /*!< FSMC register */

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */
  
  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */
    
/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                             GPIO                                           */
/*                                                                            */
/******************************************************************************/
/******************* Bit defineition for GPIO_MODER register ********************/
#define GPIO_MODER_0                        ((uint32_t)0x00000001)
#define GPIO_MODER_1                        ((uint32_t)0x00000002)
#define GPIO_MODER_2                        ((uint32_t)0x00000004)
#define GPIO_MODER_3                        ((uint32_t)0x00000008)
#define GPIO_MODER_4                        ((uint32_t)0x00000010)
#define GPIO_MODER_5                        ((uint32_t)0x00000020)
#define GPIO_MODER_6                        ((uint32_t)0x00000040)
#define GPIO_MODER_7                        ((uint32_t)0x00000080)
#define GPIO_MODER_8                        ((uint32_t)0x00000100)
#define GPIO_MODER_9                        ((uint32_t)0x00000200)
#define GPIO_MODER_10                       ((uint32_t)0x00000400)
#define GPIO_MODER_11                       ((uint32_t)0x00000800)
#define GPIO_MODER_12                       ((uint32_t)0x00001000)
#define GPIO_MODER_13                       ((uint32_t)0x00002000)
#define GPIO_MODER_14                       ((uint32_t)0x00004000)
#define GPIO_MODER_15                       ((uint32_t)0x00008000)

/******************* Bit defineition for GPIO_OTYPER register ********************/
#define GPIO_OTYPER_OT_0                    ((uint32_t)0x00000001)
#define GPIO_OTYPER_OT_1                    ((uint32_t)0x00000002)
#define GPIO_OTYPER_OT_2                    ((uint32_t)0x00000004)
#define GPIO_OTYPER_OT_3                    ((uint32_t)0x00000008)
#define GPIO_OTYPER_OT_4                    ((uint32_t)0x00000010)
#define GPIO_OTYPER_OT_5                    ((uint32_t)0x00000020)
#define GPIO_OTYPER_OT_6                    ((uint32_t)0x00000040)
#define GPIO_OTYPER_OT_7                    ((uint32_t)0x00000080)
#define GPIO_OTYPER_OT_8                    ((uint32_t)0x00000100)
#define GPIO_OTYPER_OT_9                    ((uint32_t)0x00000200)
#define GPIO_OTYPER_OT_10                   ((uint32_t)0x00000400)
#define GPIO_OTYPER_OT_11                   ((uint32_t)0x00000800)
#define GPIO_OTYPER_OT_12                   ((uint32_t)0x00001000)
#define GPIO_OTYPER_OT_13                   ((uint32_t)0x00002000)
#define GPIO_OTYPER_OT_14                   ((uint32_t)0x00004000)
#define GPIO_OTYPER_OT_15                   ((uint32_t)0x00008000)

/******************* Bit defineition for GPIO_PUPDR register ********************/
#define GPIO_PUPDR_PUPDR0                   ((uint32_t)0x00000003)
#define GPIO_PUPDR_PUPDR0_0                 ((uint32_t)0x00000001)
#define GPIO_PUPDR_PUPDR0_1                 ((uint32_t)0x00000002)

#define GPIO_PUPDR_PUPDR1                   ((uint32_t)0x0000000C)
#define GPIO_PUPDR_PUPDR1_0                 ((uint32_t)0x00000004)
#define GPIO_PUPDR_PUPDR1_1                 ((uint32_t)0x00000008)

#define GPIO_PUPDR_PUPDR2                   ((uint32_t)0x00000030)
#define GPIO_PUPDR_PUPDR2_0                 ((uint32_t)0x00000010)
#define GPIO_PUPDR_PUPDR2_1                 ((uint32_t)0x00000020)

#define GPIO_PUPDR_PUPDR3                   ((uint32_t)0x000000C0)
#define GPIO_PUPDR_PUPDR3_0                 ((uint32_t)0x00000040)
#define GPIO_PUPDR_PUPDR3_1                 ((uint32_t)0x00000080)

#define GPIO_PUPDR_PUPDR4                   ((uint32_t)0x00000300)
#define GPIO_PUPDR_PUPDR4_0                 ((uint32_t)0x00000100)
#define GPIO_PUPDR_PUPDR4_1                 ((uint32_t)0x00000200)

#define GPIO_PUPDR_PUPDR5                   ((uint32_t)0x00000C00)
#define GPIO_PUPDR_PUPDR5_0                 ((uint32_t)0x00000400)
#define GPIO_PUPDR_PUPDR5_1                 ((uint32_t)0x00000800)

#define GPIO_PUPDR_PUPDR6                   ((uint32_t)0x00003000)
#define GPIO_PUPDR_PUPDR6_0                 ((uint32_t)0x00001000)
#define GPIO_PUPDR_PUPDR6_1                 ((uint32_t)0x00002000)

#define GPIO_PUPDR_PUPDR7 ((                (int32_t)0x0000C000)
#define GPIO_PUPDR_PUPDR7_0                 ((uint32_t)0x00004000)
#define GPIO_PUPDR_PUPDR7_1                 ((uint32_t)0x00008000)

#define GPIO_PUPDR_PUPDR8                   ((uint32_t)0x00030000)
#define GPIO_PUPDR_PUPDR8_0                 ((uint32_t)0x00010000)
#define GPIO_PUPDR_PUPDR8_1                 ((uint32_t)0x00020000)

#define GPIO_PUPDR_PUPDR9                   ((uint32_t)0x0000C000)
#define GPIO_PUPDR_PUPDR9_0                 ((uint32_t)0x00004000)
#define GPIO_PUPDR_PUPDR9_1                 ((uint32_t)0x00008000)

#define GPIO_PUPDR_PUPDR10                  ((uint32_t)0x00300000)
#define GPIO_PUPDR_PUPDR10_0                ((uint32_t)0x00100000)
#define GPIO_PUPDR_PUPDR10_1                ((uint32_t)0x00200000)

#define GPIO_PUPDR_PUPDR11                  ((uint32_t)0x00C00000)
#define GPIO_PUPDR_PUPDR11_0                ((uint32_t)0x00400000)
#define GPIO_PUPDR_PUPDR11_1                ((uint32_t)0x00800000)

#define GPIO_PUPDR_PUPDR12                  ((uint32_t)0x03000000)
#define GPIO_PUPDR_PUPDR12_0                ((uint32_t)0x01000000)
#define GPIO_PUPDR_PUPDR12_1                ((uint32_t)0x02000000)

#define GPIO_PUPDR_PUPDR13                  ((uint32_t)0x0C000000)
#define GPIO_PUPDR_PUPDR13_0                ((uint32_t)0x04000000)
#define GPIO_PUPDR_PUPDR13_1                ((uint32_t)0x08000000)

#define GPIO_PUPDR_PUPDR14                  ((uint32_t)0x30000000)
#define GPIO_PUPDR_PUPDR14_0                ((uint32_t)0x10000000)
#define GPIO_PUPDR_PUPDR14_1                ((uint32_t)0x20000000)

#define GPIO_PUPDR_PUPDR15                  ((uint32_t)0xC0000000)
#define GPIO_PUPDR_PUPDR15_0                ((uint32_t)0x40000000)
#define GPIO_PUPDR_PUPDR15_1                ((uint32_t)0x80000000)

/******************* Bit defineition for GPIO_IDR register ********************/
#define GPIO_IDR_0 	                        ((uint32_t)0x00000001)
#define GPIO_IDR_1 	                        ((uint32_t)0x00000002)
#define GPIO_IDR_2 	                        ((uint32_t)0x00000004)
#define GPIO_IDR_3 	                        ((uint32_t)0x00000008)
#define GPIO_IDR_4 	                        ((uint32_t)0x00000010)
#define GPIO_IDR_5 	                        ((uint32_t)0x00000020)
#define GPIO_IDR_6 	                        ((uint32_t)0x00000040)
#define GPIO_IDR_7 	                        ((uint32_t)0x00000080)
#define GPIO_IDR_8 	                        ((uint32_t)0x00000100)
#define GPIO_IDR_9 	                        ((uint32_t)0x00000200)
#define GPIO_IDR_10	                        ((uint32_t)0x00000400)
#define GPIO_IDR_11	                        ((uint32_t)0x00000800)
#define GPIO_IDR_12	                        ((uint32_t)0x00001000)
#define GPIO_IDR_13	                        ((uint32_t)0x00002000)
#define GPIO_IDR_14	                        ((uint32_t)0x00004000)
#define GPIO_IDR_15	                        ((uint32_t)0x00008000)

/******************* Bit defineition for GPIO_ODR register ********************/
#define GPIO_ODR_0 	                        ((uint32_t)0x00000001)
#define GPIO_ODR_1 	                        ((uint32_t)0x00000002)
#define GPIO_ODR_2 	                        ((uint32_t)0x00000004)
#define GPIO_ODR_3 	                        ((uint32_t)0x00000008)
#define GPIO_ODR_4 	                        ((uint32_t)0x00000010)
#define GPIO_ODR_5 	                        ((uint32_t)0x00000020)
#define GPIO_ODR_6 	                        ((uint32_t)0x00000040)
#define GPIO_ODR_7 	                        ((uint32_t)0x00000080)
#define GPIO_ODR_8 	                        ((uint32_t)0x00000100)
#define GPIO_ODR_9 	                        ((uint32_t)0x00000200)
#define GPIO_ODR_10	                        ((uint32_t)0x00000400)
#define GPIO_ODR_11	                        ((uint32_t)0x00000800)
#define GPIO_ODR_12	                        ((uint32_t)0x00001000)
#define GPIO_ODR_13	                        ((uint32_t)0x00002000)
#define GPIO_ODR_14	                        ((uint32_t)0x00004000)
#define GPIO_ODR_15	                        ((uint32_t)0x00008000)

/******************* Bit defineition for GPIO_BSRR register ********************/
#define GPIO_BSRR_BS_0                      ((uint32_t)0x00000001)
#define GPIO_BSRR_BS_1                      ((uint32_t)0x00000002)
#define GPIO_BSRR_BS_2                      ((uint32_t)0x00000004)
#define GPIO_BSRR_BS_3                      ((uint32_t)0x00000008)
#define GPIO_BSRR_BS_4                      ((uint32_t)0x00000010)
#define GPIO_BSRR_BS_5                      ((uint32_t)0x00000020)
#define GPIO_BSRR_BS_6                      ((uint32_t)0x00000040)
#define GPIO_BSRR_BS_7                      ((uint32_t)0x00000080)
#define GPIO_BSRR_BS_8                      ((uint32_t)0x00000100)
#define GPIO_BSRR_BS_9                      ((uint32_t)0x00000200)
#define GPIO_BSRR_BS_10                     ((uint32_t)0x00000400)
#define GPIO_BSRR_BS_11                     ((uint32_t)0x00000800)
#define GPIO_BSRR_BS_12                     ((uint32_t)0x00001000)
#define GPIO_BSRR_BS_13                     ((uint32_t)0x00002000)
#define GPIO_BSRR_BS_14                     ((uint32_t)0x00004000)
#define GPIO_BSRR_BS_15                     ((uint32_t)0x00008000)
#define GPIO_BSRR_BR_0                      ((uint32_t)0x00010000)
#define GPIO_BSRR_BR_1                      ((uint32_t)0x00020000)
#define GPIO_BSRR_BR_2                      ((uint32_t)0x00040000)
#define GPIO_BSRR_BR_3                      ((uint32_t)0x00080000)
#define GPIO_BSRR_BR_4                      ((uint32_t)0x00100000)
#define GPIO_BSRR_BR_5                      ((uint32_t)0x00200000)
#define GPIO_BSRR_BR_6                      ((uint32_t)0x00400000)
#define GPIO_BSRR_BR_7                      ((uint32_t)0x00800000)
#define GPIO_BSRR_BR_8                      ((uint32_t)0x01000000)
#define GPIO_BSRR_BR_9                      ((uint32_t)0x02000000)
#define GPIO_BSRR_BR_10                     ((uint32_t)0x04000000)
#define GPIO_BSRR_BR_11                     ((uint32_t)0x08000000)
#define GPIO_BSRR_BR_12                     ((uint32_t)0x10000000)
#define GPIO_BSRR_BR_13                     ((uint32_t)0x20000000)
#define GPIO_BSRR_BR_14                     ((uint32_t)0x40000000)
#define GPIO_BSRR_BR_15                     ((uint32_t)0x80000000)

/******************* Bit defineition for GPIO_LCKR register ********************/
#define GPIO_LCKR_LCK_0                     ((uint32_t)0x00000001)
#define GPIO_LCKR_LCK_1                     ((uint32_t)0x00000002)
#define GPIO_LCKR_LCK_2                     ((uint32_t)0x00000004)
#define GPIO_LCKR_LCK_3                     ((uint32_t)0x00000008)
#define GPIO_LCKR_LCK_4                     ((uint32_t)0x00000010)
#define GPIO_LCKR_LCK_5                     ((uint32_t)0x00000020)
#define GPIO_LCKR_LCK_6                     ((uint32_t)0x00000040)
#define GPIO_LCKR_LCK_7                     ((uint32_t)0x00000080)
#define GPIO_LCKR_LCK_8                     ((uint32_t)0x00000100)
#define GPIO_LCKR_LCK_9                     ((uint32_t)0x00000200)
#define GPIO_LCKR_LCK_10                    ((uint32_t)0x00000400)
#define GPIO_LCKR_LCK_11                    ((uint32_t)0x00000800)
#define GPIO_LCKR_LCK_12                    ((uint32_t)0x00001000)
#define GPIO_LCKR_LCK_13                    ((uint32_t)0x00002000)
#define GPIO_LCKR_LCK_14                    ((uint32_t)0x00004000)
#define GPIO_LCKR_LCK_15                    ((uint32_t)0x00008000)
#define GPIO_LCKR_LCKK	                    ((uint32_t)0x00010000)

/******************* Bit defineition for GPIO_AFRL register ********************/
#define GPIO_AFRL_AFRL0                     ((uint32_t)0x0000000F)
#define GPIO_AFRL_AFRL1                     ((uint32_t)0x000000F0)
#define GPIO_AFRL_AFRL2                     ((uint32_t)0x00000F00)
#define GPIO_AFRL_AFRL3                     ((uint32_t)0x0000F000)
#define GPIO_AFRL_AFRL4                     ((uint32_t)0x000F0000)
#define GPIO_AFRL_AFRL5                     ((uint32_t)0x00F00000)
#define GPIO_AFRL_AFRL6                     ((uint32_t)0x0F000000)
#define GPIO_AFRL_AFRL7                     ((uint32_t)0xF0000000)

/******************* Bit defineition for GPIO_AFRH register ********************/
#define GPIO_AFRH_AFRH0                     ((uint32_t)0x0000000F)
#define GPIO_AFRH_AFRH1                     ((uint32_t)0x000000F0)
#define GPIO_AFRH_AFRH2                     ((uint32_t)0x00000F00)
#define GPIO_AFRH_AFRH3                     ((uint32_t)0x0000F000)
#define GPIO_AFRH_AFRH4                     ((uint32_t)0x000F0000)
#define GPIO_AFRH_AFRH5                     ((uint32_t)0x00F00000)
#define GPIO_AFRH_AFRH6                     ((uint32_t)0x0F000000)
#define GPIO_AFRH_AFRH7                     ((uint32_t)0xF0000000)

/******************* Bit defineition for GPIO_SCHMITTR register ********************/
#define GPIO_SCHMITTR_CS_0                  ((uint32_t)0x00000001)
#define GPIO_SCHMITTR_CS_1                  ((uint32_t)0x00000002)
#define GPIO_SCHMITTR_CS_2                  ((uint32_t)0x00000004)
#define GPIO_SCHMITTR_CS_3                  ((uint32_t)0x00000008)
#define GPIO_SCHMITTR_CS_4                  ((uint32_t)0x00000010)
#define GPIO_SCHMITTR_CS_5                  ((uint32_t)0x00000020)
#define GPIO_SCHMITTR_CS_6                  ((uint32_t)0x00000040)
#define GPIO_SCHMITTR_CS_7                  ((uint32_t)0x00000080)
#define GPIO_SCHMITTR_CS_8                  ((uint32_t)0x00000100)
#define GPIO_SCHMITTR_CS_9                  ((uint32_t)0x00000200)
#define GPIO_SCHMITTR_CS_10                 ((uint32_t)0x00000400)
#define GPIO_SCHMITTR_CS_11                 ((uint32_t)0x00000800)
#define GPIO_SCHMITTR_CS_12                 ((uint32_t)0x00001000)
#define GPIO_SCHMITTR_CS_13                 ((uint32_t)0x00002000)
#define GPIO_SCHMITTR_CS_14                 ((uint32_t)0x00004000)
#define GPIO_SCHMITTR_CS_15                 ((uint32_t)0x00008000)

/******************* Bit defineition for GPIO_SRR register ********************/
#define GPIO_SRR_SR_0                       ((uint32_t)0x00000001)
#define GPIO_SRR_SR_1                       ((uint32_t)0x00000002)
#define GPIO_SRR_SR_2                       ((uint32_t)0x00000004)
#define GPIO_SRR_SR_3                       ((uint32_t)0x00000008)
#define GPIO_SRR_SR_4                       ((uint32_t)0x00000010)
#define GPIO_SRR_SR_5                       ((uint32_t)0x00000020)
#define GPIO_SRR_SR_6                       ((uint32_t)0x00000040)
#define GPIO_SRR_SR_7                       ((uint32_t)0x00000080)
#define GPIO_SRR_SR_8                       ((uint32_t)0x00000100)
#define GPIO_SRR_SR_9                       ((uint32_t)0x00000200)
#define GPIO_SRR_SR_10                      ((uint32_t)0x00000400)
#define GPIO_SRR_SR_11                      ((uint32_t)0x00000800)
#define GPIO_SRR_SR_12                      ((uint32_t)0x00001000)
#define GPIO_SRR_SR_13                      ((uint32_t)0x00002000)
#define GPIO_SRR_SR_14                      ((uint32_t)0x00004000)
#define GPIO_SRR_SR_15                      ((uint32_t)0x00008000)

/******************* Bit defineition for GPIO_DRR register ********************/
#define GPIO_DRR_DR_0                       ((uint32_t)0x00000001)
#define GPIO_DRR_DR_1                       ((uint32_t)0x00000002)
#define GPIO_DRR_DR_2                       ((uint32_t)0x00000004)
#define GPIO_DRR_DR_3                       ((uint32_t)0x00000008)
#define GPIO_DRR_DR_4                       ((uint32_t)0x00000010)
#define GPIO_DRR_DR_5                       ((uint32_t)0x00000020)
#define GPIO_DRR_DR_6                       ((uint32_t)0x00000040)
#define GPIO_DRR_DR_7                       ((uint32_t)0x00000080)
#define GPIO_DRR_DR_8                       ((uint32_t)0x00000100)
#define GPIO_DRR_DR_9                       ((uint32_t)0x00000200)
#define GPIO_DRR_DR_10                      ((uint32_t)0x00000400)
#define GPIO_DRR_DR_11                      ((uint32_t)0x00000800)
#define GPIO_DRR_DR_12                      ((uint32_t)0x00001000)
#define GPIO_DRR_DR_13                      ((uint32_t)0x00002000)
#define GPIO_DRR_DR_14                      ((uint32_t)0x00004000)
#define GPIO_DRR_DR_15                      ((uint32_t)0x00008000)

/******************* Bit defineition for GPIO_BRR register ********************/
#define GPIO_BRR_BR_0                       ((uint32_t)0x00000001)
#define GPIO_BRR_BR_1                       ((uint32_t)0x00000002)
#define GPIO_BRR_BR_2                       ((uint32_t)0x00000004)
#define GPIO_BRR_BR_3                       ((uint32_t)0x00000008)
#define GPIO_BRR_BR_4                       ((uint32_t)0x00000010)
#define GPIO_BRR_BR_5                       ((uint32_t)0x00000020)
#define GPIO_BRR_BR_6                       ((uint32_t)0x00000040)
#define GPIO_BRR_BR_7                       ((uint32_t)0x00000080)
#define GPIO_BRR_BR_8                       ((uint32_t)0x00000100)
#define GPIO_BRR_BR_9                       ((uint32_t)0x00000200)
#define GPIO_BRR_BR_10                      ((uint32_t)0x00000400)
#define GPIO_BRR_BR_11                      ((uint32_t)0x00000800)
#define GPIO_BRR_BR_12                      ((uint32_t)0x00001000)
#define GPIO_BRR_BR_13                      ((uint32_t)0x00002000)
#define GPIO_BRR_BR_14                      ((uint32_t)0x00004000)
#define GPIO_BRR_BR_15                      ((uint32_t)0x00008000)

/******************************************************************************/
/*                                                                            */
/*                         Window Watchdog (WWDG)                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for WWDG_CR register  *******************/
#define WWDG_CR_WDGA                         ((uint32_t)0x00000080)        /*!< Activation Bit */
#define WWDG_CR_T                            ((uint32_t)0x0000007F)        /*!< 7-bit Counter */

/*******************  Bits definition for WWDG_CFR register  ******************/
#define WWDG_CFR_WDGTB                       ((uint32_t)0x00003800)        /*!< Timer Base */
#define WWDG_CFR_EWI                         ((uint32_t)0x00000200)        /*!< Early Wakeup Interrupt */
#define WWDG_CFR_W                           ((uint32_t)0x0000007F)        /*!< 7-bit Window Value */

/*******************  Bits definition for WWDG_SR register  *******************/
#define WWDG_SR_EWIF                         ((uint32_t)0x00000001)        /*!<  Early Wakeup Interrupt Flag */

/******************************************************************************/
/*                                                                            */
/*                       CRC calculation unit (CRC)                           */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for CRC_DR register  *********************/
#define  CRC_DR_DR                           ((uint32_t)0xFFFFFFFF)            /*!< Data input               */

/*******************  Bit definition for CRC_MIR register  ********************/
#define  CRC_MIR_MIR                         ((uint32_t)0xFFFFFFFF)            /*!< Middle data              */

/*******************  Bit definition for CRC_CR register  *********************/
#define  CRC_CR_RST                              ((uint32_t)0x00000001)            /*!< CRC reset                */
#define  CRC_CR_RI                               ((uint32_t)0x00000002)            /*!< Reverse input            */
#define  CRC_CR_BEI                              ((uint32_t)0x00000010)            /*!< Big endian input         */
#define  CRC_CR_BEO                              ((uint32_t)0x00000020)            /*!< Big endian output        */
#define  CRC_CR_RO                               ((uint32_t)0x00000040)            /*!< Reverse output           */
#define  CRC_CR_RVB                              ((uint32_t)0x00000080)            /*!< Reverse CRC write data   */

/******************************************************************************/
/*                                                                            */
/*                      Reset and Clock control (RCC)                         */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for RCC_CR register  ***********************/
#define  RCC_CR_HSION                            ((uint32_t)0x00000001)        /*!< HSI clock enable                            */
#define  RCC_CR_HSIRDY                           ((uint32_t)0x00000002)        /*!< HSI clock ready flag                        */
#define  RCC_CR_HSEON                            ((uint32_t)0x00000004)        /*!< HSE clock enable                            */
#define  RCC_CR_HSERDY                           ((uint32_t)0x00000008)        /*!< HSE clock ready flag                        */
#define  RCC_CR_HSEBYP                           ((uint32_t)0x00000010)        /*!< HSE crystal oscillator bypass               */
#define  RCC_CR_CSSON                            ((uint32_t)0x00000020)        /*!< Clock security system enable                */

/*****************  Bit definition for RCC_CFGR register  *********************/
#define  RCC_CFGR_SW                             ((uint32_t)0x00000007)        /*!< System clock switch                         */
#define  RCC_CFGR_SWS                            ((uint32_t)0x00000038)        /*!< System clock switch status                  */
#define  RCC_CFGR_HPRE                           ((uint32_t)0x00000F00)        /*!< AHB prescaler                               */
#define  RCC_CFGR_PPRE                           ((uint32_t)0x00007000)        /*!< APB prescaler                               */
#define  RCC_CFGR_HSISEL                         ((uint32_t)0x00010000)        /*!< HSI select                                  */
#define  RCC_CFGR_HSEDRV                         ((uint32_t)0x000E0000)        /*!<                                             */
#define  RCC_CFGR_MCOSEL                         ((uint32_t)0x07000000)        /*!< Microcontroller clock output                */
#define  RCC_CFGR_MCOPRE                         ((uint32_t)0x70000000)        /*!< Microcontroller clock output prescaler      */

/*****************  Bit definition for RCC_CIR register  **********************/
#define  RCC_CIR_LSIRDYIE                        ((uint32_t)0x00000001)        /*!< LSI ready interrupt enable                  */
#define  RCC_CIR_LSERDYIE                        ((uint32_t)0x00000002)        /*!< LSE ready interrupt enable                  */
#define  RCC_CIR_HSIRDYIE                        ((uint32_t)0x00000004)        /*!< HSI ready interrupt enable                  */
#define  RCC_CIR_HSERDYIE                        ((uint32_t)0x00000008)        /*!< HSE ready interrupt enable                  */
#define  RCC_CIR_LSIRDYIF                        ((uint32_t)0x00000010)        /*!< LSI ready interrupt flag                    */
#define  RCC_CIR_LSERDYIF                        ((uint32_t)0x00000020)        /*!< LSE ready interrupt flag                    */
#define  RCC_CIR_HSIRDYIF                        ((uint32_t)0x00000040)        /*!< HSI ready interrupt flag                    */
#define  RCC_CIR_HSERDYIF                        ((uint32_t)0x00000080)        /*!< HSE ready interrupt flag                    */
#define  RCC_CIR_CSSF                            ((uint32_t)0x00000100)        /*!< HSE clock security system interrupt flag    */
#define  RCC_CIR_LSECSSF                         ((uint32_t)0x00000200)        /*!< LSE clock security system interrupt flag    */
#define  RCC_CIR_LSIRDYIC                        ((uint32_t)0x00000400)        /*!<                                             */
#define  RCC_CIR_LSERDYIC                        ((uint32_t)0x00000800)        /*!<                                             */
#define  RCC_CIR_HSIRDYIC                        ((uint32_t)0x00001000)        /*!<                                             */
#define  RCC_CIR_HSERDYIC                        ((uint32_t)0x00002000)        /*!<                                             */
#define  RCC_CIR_CSSC                            ((uint32_t)0x00004000)        /*!<                                             */
#define  RCC_CIR_LSECSSC                         ((uint32_t)0x00008000)        /*!<                                             */
#define  RCC_CIR_CLK_ERR                         ((uint32_t)0x00010000)        /*!<                                             */

/*****************  Bit definition for RCC_AHBRSTR register  ******************/
#define  RCC_AHBRSTR_DMARST                      ((uint32_t)0x00000001)        /*!< DMA and DMAMUX reset                        */
#define  RCC_AHBRSTR_FLASHRST                    ((uint32_t)0x00000100)        /*!< Flash memory interface reset                */
#define  RCC_AHBRSTR_CRCRST                      ((uint32_t)0x00001000)        /*!< CRC reset                                   */
#define  RCC_AHBRSTR_CORDICRST                   ((uint32_t)0x00002000)        /*!< CORDIC reset                                */

/*****************  Bit definition for RCC_APBRSTR1 register  *****************/
#define  RCC_APBRSTR1_ADCRST                     ((uint32_t)0x00000001)        /*!< ADC reset                                   */
#define  RCC_APBRSTR1_COMPRST                    ((uint32_t)0x00000002)        /*!< Comparator reset                            */
#define  RCC_APBRSTR1_USART1RST                  ((uint32_t)0x00000040)        /*!< USART1 reset                                */
#define  RCC_APBRSTR1_USART2RST                  ((uint32_t)0x00000080)        /*!< USARE2 reset                                */
#define  RCC_APBRSTR1_I2C1RST                    ((uint32_t)0x00000100)        /*!< I2C1 reset                                  */
#define  RCC_APBRSTR1_SPI1RST                    ((uint32_t)0x00000200)        /*!< SPI1 reset                                  */
#define  RCC_APBRSTR1_TIM1RST                    ((uint32_t)0x00000400)        /*!< TIM1 reset                                  */
#define  RCC_APBRSTR1_TIM2RST                    ((uint32_t)0x00000800)        /*!< TIM2 reset                                  */
#define  RCC_APBRSTR1_TIM14RST                   ((uint32_t)0x00001000)        /*!< TIM14 reset                                 */
#define  RCC_APBRSTR1_TIM6RST                    ((uint32_t)0x00008000)        /*!< TIM6 reset                                  */
#define  RCC_APBRSTR1_TIM7RST                    ((uint32_t)0x00010000)        /*!< TIM7 reset                                  */
#define  RCC_APBRSTR1_LPTIMRST                   ((uint32_t)0x00020000)        /*!< LPTIM reset                                 */

/*****************  Bit definition for RCC_AHBENR register  *******************/
#define  RCC_AHBENR_DMAEN                        ((uint32_t)0x00000001)        /*!< DMA clock enable                            */
#define  RCC_AHBENR_FLASHEN                      ((uint32_t)0x00000100)        /*!< Flash clock enable                          */
#define  RCC_AHBENR_CRCEN                        ((uint32_t)0x00001000)        /*!< CRC clock enable                            */
#define  RCC_AHBENR_CORDICEN                     ((uint32_t)0x00002000)        /*!< CORDIC clock enable                         */

/*****************  Bit definition for RCC_APBENR1 register  ******************/
#define  RCC_APBENR1_ADCEN                       ((uint32_t)0x00000001)        /*!< ADC clock enable                            */
#define  RCC_APBENR1_COMPEN                      ((uint32_t)0x00000002)        /*!< Comparator clock enable                     */
#define  RCC_APBENR1_USART1EN                    ((uint32_t)0x00000040)        /*!< USART1 clock enable                         */
#define  RCC_APBENR1_USART2EN                    ((uint32_t)0x00000080)        /*!< USART2 clock enable                         */
#define  RCC_APBENR1_I2C1EN                      ((uint32_t)0x00000100)        /*!< I2C1 clock enable                           */
#define  RCC_APBENR1_SPI1EN                      ((uint32_t)0x00000200)        /*!< SPI1 clock enable                           */
#define  RCC_APBENR1_TIM1EN                      ((uint32_t)0x00000400)        /*!< TIM1 clock enable                           */
#define  RCC_APBENR1_TIM2EN                      ((uint32_t)0x00000800)        /*!< TIM2 clock enable                           */
#define  RCC_APBENR1_TIM14EN                     ((uint32_t)0x00001000)        /*!< TIM14 clock enable                          */
#define  RCC_APBENR1_TIM6EN                      ((uint32_t)0x00008000)        /*!< TIM6 clock enable                           */
#define  RCC_APBENR1_TIM7EN                      ((uint32_t)0x00010000)        /*!< TIM7 clock enable                           */
#define  RCC_APBENR1_LPTIMEN                     ((uint32_t)0x00020000)        /*!< LPTIM clock enable                          */
#define  RCC_APBENR1_RTCEN_P                     ((uint32_t)0x00040000)        /*!< RTC clock enable                            */

/*****************  Bit definition for RCC_CCIPR register  ********************/
#define  RCC_CCIPR_LPTIMSEL                      ((uint32_t)0x000C0000)        /*!< LPTIM clock source selection                */
#define  RCC_CCIPR_ADCSEL                        ((uint32_t)0xC0000000)        /*!< ADC clock source selection                  */

/*****************  Bit definition for RCC_BDCR register  *********************/
#define  RCC_BDCR_LSEON                          ((uint32_t)0x00000001)        /*!< Low-speed clock output enable               */
#define  RCC_BDCR_LSERDY                         ((uint32_t)0x00000002)        /*!< LSE oscillator ready                        */
#define  RCC_BDCR_LSEBYP                         ((uint32_t)0x00000004)        /*!< LSE oscillator bypass                       */
#define  RCC_BDCR_LSEDRV                         ((uint32_t)0x00000038)        /*!< LSE oscillator drive capability             */
#define  RCC_BDCR_LSECSSON                       ((uint32_t)0x00000040)        /*!< CSS on LSE failure enable                   */
#define  RCC_BDCR_LSECSSD                        ((uint32_t)0x00000080)        /*!< CSS on LSE failure Detection                */
#define  RCC_BDCR_RTCSEL                         ((uint32_t)0x00000300)        /*!< RTC clock source selection                  */
#define  RCC_BDCR_RTCEN                          ((uint32_t)0x00008000)        /*!< RTC clock enable                            */
#define  RCC_BDCR_BDRST                          ((uint32_t)0x00010000)        /*!< RTC domain software reset                   */

/*****************  Bit definition for RCC_CSR register  **********************/
#define  RCC_CSR_LSION                           ((uint32_t)0x00000001)        /*!< LSI oscillator enable                       */
#define  RCC_CSR_LSIRDY                          ((uint32_t)0x00000002)        /*!< LSI oscillator ready                        */
#define  RCC_CSR_CPULOCKUPEN                     ((uint32_t)0x00000004)        /*!< CPU LOCKUP enable                           */
#define  RCC_CSR_RMVF                            ((uint32_t)0x00800000)        /*!< Remove reset flag                           */
#define  RCC_CSR_CPULOCKUPRSTF                   ((uint32_t)0x01000000)        /*!< CPU LOCKUP reset flag                       */
#define  RCC_CSR_PVDRSTF                         ((uint32_t)0x02000000)        /*!< PVD reset flag                              */
#define  RCC_CSR_PINRSTF                         ((uint32_t)0x04000000)        /*!< Pin reset flag                              */
#define  RCC_CSR_PWRRSTF                         ((uint32_t)0x08000000)        /*!< BOR or POR/PDR flag                         */
#define  RCC_CSR_SFTRSTF                         ((uint32_t)0x10000000)        /*!< Software reset flag                         */
#define  RCC_CSR_IWDGRSTF                        ((uint32_t)0x20000000)        /*!< Independent window watchdog reset flag      */
#define  RCC_CSR_WWDGRSTF                        ((uint32_t)0x40000000)        /*!< Window watchdog reset flag                  */

/*****************  Bit definition for RCC_HSI_TRIM ***************************/
#define RCC_HSI_TRIM_HSITRIM                     ((uint32_t)0x000007FF)        /*!<                                             */

/*****************  Bit definition for RCC_LSI_TRIM ***************************/
#define RCC_LSI_TRIM_LSITRIM                     ((uint32_t)0x000003FF)        /*!<                                             */

/*****************  Bit definition for RCC_HSICNT  ****************************/
#define  RCC_HSICNT                              ((uint32_t)0x00001FFF)        /*!< HSI counter                                 */

/*****************  Bit definition for RCC_HSECNT  ****************************/
#define  RCC_HSECNT                              ((uint32_t)0x0003FFFF)        /*!< HSE counter                                 */

/*****************  Bit definition for RCC_LSICNT  ****************************/
#define  RCC_LSICNT                              ((uint32_t)0x0000FFFF)        /*!< LSI counter                                 */

/*****************  Bit definition for RCC_LSECNT  ****************************/
#define  RCC_LSECNT                              ((uint32_t)0x001FFFFF)        /*!< LSE counter                                 */

/******************************************************************************/
/*                                                                            */
/*                           DMA Controller (DMA)                             */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for DMA_ISR register  ********************/
#define  DMA_ISR_GIF1                        ((uint32_t)0x00000001)            /*!< Channel 1 Global interrupt flag    */
#define  DMA_ISR_TCIF1                       ((uint32_t)0x00000002)            /*!< Channel 1 Transfer Complete flag   */
#define  DMA_ISR_HTIF1                       ((uint32_t)0x00000004)            /*!< Channel 1 Half Transfer flag       */
#define  DMA_ISR_TEIF1                       ((uint32_t)0x00000008)            /*!< Channel 1 Transfer Error flag      */
#define  DMA_ISR_GIF2                        ((uint32_t)0x00000010)            /*!< Channel 2 Global interrupt flag    */
#define  DMA_ISR_TCIF2                       ((uint32_t)0x00000020)            /*!< Channel 2 Transfer Complete flag   */
#define  DMA_ISR_HTIF2                       ((uint32_t)0x00000040)            /*!< Channel 2 Half Transfer flag       */
#define  DMA_ISR_TEIF2                       ((uint32_t)0x00000080)            /*!< Channel 2 Transfer Error flag      */
#define  DMA_ISR_GIF3                        ((uint32_t)0x00000100)            /*!< Channel 3 Global interrupt flag    */
#define  DMA_ISR_TCIF3                       ((uint32_t)0x00000200)            /*!< Channel 3 Transfer Complete flag   */
#define  DMA_ISR_HTIF3                       ((uint32_t)0x00000400)            /*!< Channel 3 Half Transfer flag       */
#define  DMA_ISR_TEIF3                       ((uint32_t)0x00000800)            /*!< Channel 3 Transfer Error flag      */
#define  DMA_ISR_GIF4                        ((uint32_t)0x00001000)            /*!< Channel 4 Global interrupt flag    */
#define  DMA_ISR_TCIF4                       ((uint32_t)0x00002000)            /*!< Channel 4 Transfer Complete flag   */
#define  DMA_ISR_HTIF4                       ((uint32_t)0x00004000)            /*!< Channel 4 Half Transfer flag       */
#define  DMA_ISR_TEIF4                       ((uint32_t)0x00008000)            /*!< Channel 4 Transfer Error flag      */
#define  DMA_ISR_GIF5                        ((uint32_t)0x00010000)            /*!< Channel 5 Global interrupt flag    */
#define  DMA_ISR_TCIF5                       ((uint32_t)0x00020000)            /*!< Channel 5 Transfer Complete flag   */
#define  DMA_ISR_HTIF5                       ((uint32_t)0x00040000)            /*!< Channel 5 Half Transfer flag       */
#define  DMA_ISR_TEIF5                       ((uint32_t)0x00080000)            /*!< Channel 5 Transfer Error flag      */
#define  DMA_ISR_GIF6                        ((uint32_t)0x00100000)            /*!< Channel 6 Global interrupt flag    */
#define  DMA_ISR_TCIF6                       ((uint32_t)0x00200000)            /*!< Channel 6 Transfer Complete flag   */
#define  DMA_ISR_HTIF6                       ((uint32_t)0x00400000)            /*!< Channel 6 Half Transfer flag       */
#define  DMA_ISR_TEIF6                       ((uint32_t)0x00800000)            /*!< Channel 6 Transfer Error flag      */
#define  DMA_ISR_GIF7                        ((uint32_t)0x01000000)            /*!< Channel 7 Global interrupt flag    */
#define  DMA_ISR_TCIF7                       ((uint32_t)0x02000000)            /*!< Channel 7 Transfer Complete flag   */
#define  DMA_ISR_HTIF7                       ((uint32_t)0x04000000)            /*!< Channel 7 Half Transfer flag       */
#define  DMA_ISR_TEIF7                       ((uint32_t)0x08000000)            /*!< Channel 7 Transfer Error flag      */
#define  DMA_ISR_GIF8                        ((uint32_t)0x10000000)            /*!< Channel 8 Global interrupt flag    */
#define  DMA_ISR_TCIF8                       ((uint32_t)0x20000000)            /*!< Channel 8 Transfer Complete flag   */
#define  DMA_ISR_HTIF8                       ((uint32_t)0x40000000)            /*!< Channel 8 Half Transfer flag       */
#define  DMA_ISR_TEIF8                       ((uint32_t)0x80000000)            /*!< Channel 8 Transfer Error flag      */

/*******************  Bit definition for DMA_IFCR register  ********************/
#define  DMA_IFCR_CGIF1                      ((uint32_t)0x00000001)            /*!< Channel 1 Clear Global interrupt flag    */
#define  DMA_IFCR_CTCIF1                     ((uint32_t)0x00000002)            /*!< Channel 1 Clear Transfer Complete flag   */
#define  DMA_IFCR_CHTIF1                     ((uint32_t)0x00000004)            /*!< Channel 1 Clear Half Transfer flag       */
#define  DMA_IFCR_CTEIF1                     ((uint32_t)0x00000008)            /*!< Channel 1 Clear Transfer Error flag      */
#define  DMA_IFCR_CGIF2                      ((uint32_t)0x00000010)            /*!< Channel 2 Clear Global interrupt flag    */
#define  DMA_IFCR_CTCIF2                     ((uint32_t)0x00000020)            /*!< Channel 2 Clear Transfer Complete flag   */
#define  DMA_IFCR_CHTIF2                     ((uint32_t)0x00000040)            /*!< Channel 2 Clear Half Transfer flag       */
#define  DMA_IFCR_CTEIF2                     ((uint32_t)0x00000080)            /*!< Channel 2 Clear Transfer Error flag      */
#define  DMA_IFCR_CGIF3                      ((uint32_t)0x00000100)            /*!< Channel 3 Clear Global interrupt flag    */
#define  DMA_IFCR_CTCIF3                     ((uint32_t)0x00000200)            /*!< Channel 3 Clear Transfer Complete flag   */
#define  DMA_IFCR_CHTIF3                     ((uint32_t)0x00000400)            /*!< Channel 3 Clear Half Transfer flag       */
#define  DMA_IFCR_CTEIF3                     ((uint32_t)0x00000800)            /*!< Channel 3 Clear Transfer Error flag      */
#define  DMA_IFCR_CGIF4                      ((uint32_t)0x00001000)            /*!< Channel 4 Clear Global interrupt flag    */
#define  DMA_IFCR_CTCIF4                     ((uint32_t)0x00002000)            /*!< Channel 4 Clear Transfer Complete flag   */
#define  DMA_IFCR_CHTIF4                     ((uint32_t)0x00004000)            /*!< Channel 4 Clear Half Transfer flag       */
#define  DMA_IFCR_CTEIF4                     ((uint32_t)0x00008000)            /*!< Channel 4 Clear Transfer Error flag      */
#define  DMA_IFCR_CGIF5                      ((uint32_t)0x00010000)            /*!< Channel 5 Clear Global interrupt flag    */
#define  DMA_IFCR_CTCIF5                     ((uint32_t)0x00020000)            /*!< Channel 5 Clear Transfer Complete flag   */
#define  DMA_IFCR_CHTIF5                     ((uint32_t)0x00040000)            /*!< Channel 5 Clear Half Transfer flag       */
#define  DMA_IFCR_CTEIF5                     ((uint32_t)0x00080000)            /*!< Channel 5 Clear Transfer Error flag      */
#define  DMA_IFCR_CGIF6                      ((uint32_t)0x00100000)            /*!< Channel 6 Clear Global interrupt flag    */
#define  DMA_IFCR_CTCIF6                     ((uint32_t)0x00200000)            /*!< Channel 6 Clear Transfer Complete flag   */
#define  DMA_IFCR_CHTIF6                     ((uint32_t)0x00400000)            /*!< Channel 6 Clear Half Transfer flag       */
#define  DMA_IFCR_CTEIF6                     ((uint32_t)0x00800000)            /*!< Channel 6 Clear Transfer Error flag      */
#define  DMA_IFCR_CGIF7                      ((uint32_t)0x01000000)            /*!< Channel 7 Clear Global interrupt flag    */
#define  DMA_IFCR_CTCIF7                     ((uint32_t)0x02000000)            /*!< Channel 7 Clear Transfer Complete flag   */
#define  DMA_IFCR_CHTIF7                     ((uint32_t)0x04000000)            /*!< Channel 7 Clear Half Transfer flag       */
#define  DMA_IFCR_CTEIF7                     ((uint32_t)0x08000000)            /*!< Channel 7 Clear Transfer Error flag      */
#define  DMA_IFCR_CGIF8                      ((uint32_t)0x10000000)            /*!< Channel 8 Clear Global interrupt flag    */
#define  DMA_IFCR_CTCIF8                     ((uint32_t)0x20000000)            /*!< Channel 8 Clear Transfer Complete flag   */
#define  DMA_IFCR_CHTIF8                     ((uint32_t)0x40000000)            /*!< Channel 8 Clear Half Transfer flag       */
#define  DMA_IFCR_CTEIF8                     ((uint32_t)0x80000000)            /*!< Channel 8 Clear Transfer Error flag      */

/*******************  Bit definition for DMA_CCR register  ********************/
#define  DMA_CCR_EN                          ((uint32_t)0x00000001)            /*!< Channel enable                      */
#define  DMA_CCR_TCIE                        ((uint32_t)0x00000002)            /*!< Transfer complete interrupt enable  */
#define  DMA_CCR_HTIE                        ((uint32_t)0x00000004)            /*!< Half Transfer interrupt enable      */
#define  DMA_CCR_TEIE                        ((uint32_t)0x00000008)            /*!< Transfer error interrupt enable     */
#define  DMA_CCR_DIR                         ((uint32_t)0x00000010)            /*!< Data transfer direction             */
#define  DMA_CCR_CIRC                        ((uint32_t)0x00000020)            /*!< Circular mode                       */
#define  DMA_CCR_PINC                        ((uint32_t)0x00000040)            /*!< Peripheral increment mode           */
#define  DMA_CCR_MINC                        ((uint32_t)0x00000080)            /*!< Memory increment mode               */
#define  DMA_CCR_PSIZE                       ((uint32_t)0x00000300)            /*!< PSIZE[1:0] bits (Peripheral size)   */
#define  DMA_CCR_MSIZE                       ((uint32_t)0x00000C00)            /*!< MSIZE[1:0] bits (Memory size)       */
#define  DMA_CCR_PL                          ((uint32_t)0x00003000)            /*!< PL[1:0] bits(Channel Priority level)*/
#define  DMA_CCR_MEM                         ((uint32_t)0x00004000)            /*!< Memory to memory mode               */
#define  DMA_CCR_REQ_ID                      ((uint32_t)0x00FF0000)            /*!<    */

/******************  Bit definition for DMA_CNDTR register  *******************/
#define  DMA_CNDTR_NDT                       ((uint32_t)0x0000FFFF)            /*!< Number of data to Transfer          */

/******************  Bit definition for DMA_CPAR register  ********************/
#define  DMA_CPAR_PA                         ((uint32_t)0xFFFFFFFF)            /*!< Peripheral Address                  */

/******************  Bit definition for DMA_CMAR register  ********************/
#define  DMA_CMAR_MA                         ((uint32_t)0xFFFFFFFF)            /*!< Memory Address                      */

/******************************************************************************/
/*                                                                            */
/*                  External Interrupt/Event Controller (EXTI)                */
/*                                                                            */
/******************************************************************************/

/****************** Bit definition for EXTI_RTSR register *********************/
#define  EXTI_RTSR_RT                           ((uint32_t)0xFFFFFFFF)         /*!< Rising Edge Trigger Enable      */

/****************** Bit definition for EXTI_FTSR register *********************/
#define  EXTI_FTSR_FT                           ((uint32_t)0xFFFFFFFF)         /*!< Falling Edge Trigger Enable     */

/****************** Bit definition for EXTI_SWIER register ********************/
#define  EXTI_SWIER_SWI                         ((uint32_t)0xFFFFFFFF)         /*!< Software Interrupt Trigger      */

/****************** Bit definition for EXTI_PR register ***********************/
#define  EXTI_PR_PIF                            ((uint32_t)0xFFFFFFFF)         /*!< Pending Interrupt Flag          */

/****************** Bit definition for EXTI_EXTICR1 register ******************/
#define  EXTI_EXTICR1_EXTI0                     ((uint32_t)0x0000000F)         /*!< EXTI0  GPIO Port Selection      */
#define  EXTI_EXTICR1_EXTI1                     ((uint32_t)0x000000F0)         /*!< EXTI1  GPIO Port Selection      */
#define  EXTI_EXTICR1_EXTI2                     ((uint32_t)0x00000F00)         /*!< EXTI2  GPIO Port Selection      */
#define  EXTI_EXTICR1_EXTI3                     ((uint32_t)0x0000F000)         /*!< EXTI3  GPIO Port Selection      */
#define  EXTI_EXTICR1_EXTI4                     ((uint32_t)0x000F0000)         /*!< EXTI4  GPIO Port Selection      */
#define  EXTI_EXTICR1_EXTI5                     ((uint32_t)0x00F00000)         /*!< EXTI5  GPIO Port Selection      */
#define  EXTI_EXTICR1_EXTI6                     ((uint32_t)0x0F000000)         /*!< EXTI6  GPIO Port Selection      */
#define  EXTI_EXTICR1_EXTI7                     ((uint32_t)0xF0000000)         /*!< EXTI7  GPIO Port Selection      */

/****************** Bit definition for EXTI_EXTICR2 register ******************/
#define  EXTI_EXTICR2_EXTI8                     ((uint32_t)0x0000000F)         /*!< EXTI8  GPIO Port Selection      */
#define  EXTI_EXTICR2_EXTI9                     ((uint32_t)0x000000F0)         /*!< EXTI9  GPIO Port Selection      */
#define  EXTI_EXTICR2_EXTI10                    ((uint32_t)0x00000F00)         /*!< EXTI10 GPIO Port Selection      */
#define  EXTI_EXTICR2_EXTI11                    ((uint32_t)0x0000F000)         /*!< EXTI11 GPIO Port Selection      */
#define  EXTI_EXTICR2_EXTI12                    ((uint32_t)0x000F0000)         /*!< EXTI12 GPIO Port Selection      */
#define  EXTI_EXTICR2_EXTI13                    ((uint32_t)0x00F00000)         /*!< EXTI13 GPIO Port Selection      */
#define  EXTI_EXTICR2_EXTI14                    ((uint32_t)0x0F000000)         /*!< EXTI14 GPIO Port Selection      */
#define  EXTI_EXTICR2_EXTI15                    ((uint32_t)0xF0000000)         /*!< EXTI15 GPIO Port Selection      */

/****************** Bit definition for EXTI_IMR register **********************/
#define  EXTI_IMR_IM                            ((uint32_t)0xFFFFFFFF)         /*!< Interrupt Mask                  */

/****************** Bit definition for EXTI_EMR register **********************/
#define  EXTI_EMR_EM                            ((uint32_t)0xFFFFFFFF)         /*!< Event Mask                      */

/******************************************************************************/
/*                                                                            */
/*                   Inter-integrated Circuit Interface (I2C)                 */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for I2C_CFG register  *******************/
#define  I2C_CFG_FIFOSIZE                    ((uint16_t)0x0003)             /*!< FIFO size */

/******************  Bit definition for I2C_INTEN register  ******************/
#define I2C_INTEN_CMPL                       ((uint32_t)0x00000200)         /*!< Completion Interrupt enable */
#define I2C_INTEN_BYTERECV                   ((uint32_t)0x00000100)         /*!< Byte Receive Interrupt enable */
#define I2C_INTEN_BYTETRANS                  ((uint32_t)0x00000080)         /*!< Byte Transmit Interrupt enable */
#define I2C_INTEN_START                      ((uint32_t)0x00000040)         /*!< START Condition Interrupt enable */
#define I2C_INTEN_STOP                       ((uint32_t)0x00000020)         /*!< STOP Condition Interrupt enable */
#define I2C_INTEN_ARBLOSE                    ((uint32_t)0x00000010)         /*!< Arbitration Lose Interrupt enable */
#define I2C_INTEN_ADDRHIT                    ((uint32_t)0x00000008)         /*!< Address Hit Interrupt enable */
#define I2C_INTEN_FIFOHALF                   ((uint32_t)0x00000004)         /*!< FIFO Half Interrupt enable */
#define I2C_INTEN_FIFOFULL                   ((uint32_t)0x00000002)         /*!< FIFO Full Interrupt enable */
#define I2C_INTEN_FIFOEMPTY                  ((uint32_t)0x00000001)         /*!< FIFO Empty Interrupt enable */

/*****************  Bit definition for I2C_STATUS register  ******************/
#define I2C_STATUS_LINESDA                   ((uint32_t)0x00004000)         /*!< Current status of the SDA line */
#define I2C_STATUS_LINESCL                   ((uint32_t)0x00002000)         /*!< Current status of the SCL line */
#define I2C_STATUS_GENCALL                   ((uint32_t)0x00001000)         /*!< General Call address indication */
#define I2C_STATUS_BUSBUSY                   ((uint32_t)0x00000800)         /*!< Bus busy indication */
#define I2C_STATUS_ACK                       ((uint32_t)0x00000400)         /*!< Last received/transmitted ACK bit type */
#define I2C_STATUS_CMPL                      ((uint32_t)0x00000200)         /*!< Transaction Completion */
#define I2C_STATUS_BYTERECV                  ((uint32_t)0x00000100)         /*!< Byte received indication */
#define I2C_STATUS_BYTETRANS                 ((uint32_t)0x00000080)         /*!< Byte transmitted indication */
#define I2C_STATUS_START                     ((uint32_t)0x00000040)         /*!< START Condition indication */
#define I2C_STATUS_STOP                      ((uint32_t)0x00000020)         /*!< STOP Condition indication */
#define I2C_STATUS_ARBLOSE                   ((uint32_t)0x00000010)         /*!< Arbitration lost indication */
#define I2C_STATUS_ADDRHIT                   ((uint32_t)0x00000008)         /*!< Address hit indication */
#define I2C_STATUS_FIFOHALF                  ((uint32_t)0x00000004)         /*!< FIFO half-full/half-empty indication */
#define I2C_STATUS_FIFOFULL                  ((uint32_t)0x00000002)         /*!< FIFO full indication */
#define I2C_STATUS_FIFOEMPTY                 ((uint32_t)0x00000001)         /*!< FIFO empty indication */

/*****************  Bit definition for I2C_ADDR register  ******************/
#define I2C_ADDR_ADDR                        ((uint32_t)0x000003FF)         /*!< Slave address */

/*****************  Bit definition for I2C_DATA register  ******************/
#define I2C_DATA_DATA                        ((uint32_t)0x000000FF)         /*!< FIFO data */

/*****************  Bit definition for I2C_CTRL register  ******************/
#define I2C_CTRL_PHASE_START                 ((uint32_t)0x00001000)         /*!< Enable START condition */
#define I2C_CTRL_PHASE_ADDR                  ((uint32_t)0x00000800)         /*!< Enable Address phase */
#define I2C_CTRL_PHASE_DATA                  ((uint32_t)0x00000400)         /*!< Enable Data phase */
#define I2C_CTRL_PHASE_STOP                  ((uint32_t)0x00000200)         /*!< Enable STOP condition */
#define I2C_CTRL_DIR                         ((uint32_t)0x00000100)         /*!< Transaction direction */
#define I2C_CTRL_DATACNT                     ((uint32_t)0x000000FF)         /*!< Data counts in bytes */

/*****************  Bit definition for I2C_CMD register  ******************/
#define I2C_CMD_CMD                          ((uint32_t)0x00000007)         /*!< Command */

/*******************  Bit definition for I2C_SETUP register  ********************/
#define I2C_SETUP_T_SCLRATIO                 ((uint32_t)0x00000020)         /*!< SCL LOW period ratio */
#define I2C_SETUP_NOSTRETCH                  ((uint32_t)0x00000010)         /*!< No stretch enable */
#define I2C_SETUP_DMAEN                      ((uint32_t)0x00000008)         /*!< DMA enable */
#define I2C_SETUP_MASTER                     ((uint32_t)0x00000004)         /*!< Master/Slave mode */
#define I2C_SETUP_ADDRESSING                 ((uint32_t)0x00000002)         /*!< Addressing mode */
#define I2C_SETUP_IICEN                      ((uint32_t)0x00000001)         /*!< I2C controller enable */

/*******************  Bit definition for I2C_TPM register  ********************/
#define I2C_TPM_TPM                          ((uint32_t)0x0000000F)         /*!< I2C timing parameter multiplier */

/*******************  Bit definition for I2C_TPM register  ********************/
#define I2C_TIMING_T_SUDAT                   ((uint32_t)0xFF000000)         /*!< Data setup time */
#define I2C_TIMING_T_HDDAT                   ((uint32_t)0x00FF0000)         /*!< Data hold time */
#define I2C_TIMING_T_SP                      ((uint32_t)0x0000F800)         /*!< Spike suppression pulse width */
#define I2C_TIMING_T_SCLHI                   ((uint32_t)0x000007FF)         /*!< SCL HIGH period */

/*******************  Bit definition for I2C_MASK register  ********************/
#define I2C_MASK_MASK                        ((uint32_t)0x000003FF)         /*!<  */


/******************************************************************************/
/*                                                                            */
/*                               Timers (TIM)                                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TIM_CR1 register  ********************/
#define  TIM_CR1_CEN                         ((uint16_t)0x0001)            /*!<Counter enable */
#define  TIM_CR1_UDIS                        ((uint16_t)0x0002)            /*!<Update disable */
#define  TIM_CR1_URS                         ((uint16_t)0x0004)            /*!<Update request source */
#define  TIM_CR1_OPM                         ((uint16_t)0x0008)            /*!<One pulse mode */
#define  TIM_CR1_DIR                         ((uint16_t)0x0010)            /*!<Direction */

#define  TIM_CR1_CMS                         ((uint16_t)0x0060)            /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define  TIM_CR1_CMS_0                       ((uint16_t)0x0020)            /*!<Bit 0 */
#define  TIM_CR1_CMS_1                       ((uint16_t)0x0040)            /*!<Bit 1 */

#define  TIM_CR1_ARPE                        ((uint16_t)0x0080)            /*!<Auto-reload preload enable */

#define  TIM_CR1_CKD                         ((uint16_t)0x0300)            /*!<CKD[1:0] bits (clock division) */
#define  TIM_CR1_CKD_0                       ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIM_CR1_CKD_1                       ((uint16_t)0x0200)            /*!<Bit 1 */

/*******************  Bit definition for TIM_CR2 register  ********************/
#define  TIM_CR2_CCPC                        ((uint16_t)0x0001)            /*!<Capture/Compare Preloaded Control */
#define  TIM_CR2_CCUS                        ((uint16_t)0x0004)            /*!<Capture/Compare Control Update Selection */
#define  TIM_CR2_CCDS                        ((uint16_t)0x0008)            /*!<Capture/Compare DMA Selection */

#define  TIM_CR2_MMS                         ((uint16_t)0x0070)            /*!<MMS[2:0] bits (Master Mode Selection) */
#define  TIM_CR2_MMS_0                       ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIM_CR2_MMS_1                       ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIM_CR2_MMS_2                       ((uint16_t)0x0040)            /*!<Bit 2 */

#define  TIM_CR2_TI1S                        ((uint16_t)0x0080)            /*!<TI1 Selection */
#define  TIM_CR2_OIS1                        ((uint16_t)0x0100)            /*!<Output Idle state 1 (OC1 output) */
#define  TIM_CR2_OIS1N                       ((uint16_t)0x0200)            /*!<Output Idle state 1 (OC1N output) */
#define  TIM_CR2_OIS2                        ((uint16_t)0x0400)            /*!<Output Idle state 2 (OC2 output) */
#define  TIM_CR2_OIS2N                       ((uint16_t)0x0800)            /*!<Output Idle state 2 (OC2N output) */
#define  TIM_CR2_OIS3                        ((uint16_t)0x1000)            /*!<Output Idle state 3 (OC3 output) */
#define  TIM_CR2_OIS3N                       ((uint16_t)0x2000)            /*!<Output Idle state 3 (OC3N output) */
#define  TIM_CR2_OIS4                        ((uint16_t)0x4000)            /*!<Output Idle state 4 (OC4 output) */

/*******************  Bit definition for TIM_SMCR register  *******************/
#define  TIM_SMCR_SMS                        ((uint16_t)0x0007)            /*!<SMS[2:0] bits (Slave mode selection) */
#define  TIM_SMCR_SMS_0                      ((uint16_t)0x0001)            /*!<Bit 0 */
#define  TIM_SMCR_SMS_1                      ((uint16_t)0x0002)            /*!<Bit 1 */
#define  TIM_SMCR_SMS_2                      ((uint16_t)0x0004)            /*!<Bit 2 */

#define  TIM_SMCR_TS                         ((uint16_t)0x0070)            /*!<TS[2:0] bits (Trigger selection) */
#define  TIM_SMCR_TS_0                       ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIM_SMCR_TS_1                       ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIM_SMCR_TS_2                       ((uint16_t)0x0040)            /*!<Bit 2 */

#define  TIM_SMCR_MSM                        ((uint16_t)0x0080)            /*!<Master/slave mode */

#define  TIM_SMCR_ETF                        ((uint16_t)0x0F00)            /*!<ETF[3:0] bits (External trigger filter) */
#define  TIM_SMCR_ETF_0                      ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIM_SMCR_ETF_1                      ((uint16_t)0x0200)            /*!<Bit 1 */
#define  TIM_SMCR_ETF_2                      ((uint16_t)0x0400)            /*!<Bit 2 */
#define  TIM_SMCR_ETF_3                      ((uint16_t)0x0800)            /*!<Bit 3 */

#define  TIM_SMCR_ETPS                       ((uint16_t)0x3000)            /*!<ETPS[1:0] bits (External trigger prescaler) */
#define  TIM_SMCR_ETPS_0                     ((uint16_t)0x1000)            /*!<Bit 0 */
#define  TIM_SMCR_ETPS_1                     ((uint16_t)0x2000)            /*!<Bit 1 */

#define  TIM_SMCR_ECE                        ((uint16_t)0x4000)            /*!<External clock enable */
#define  TIM_SMCR_ETP                        ((uint16_t)0x8000)            /*!<External trigger polarity */

/*******************  Bit definition for TIM_DIER register  *******************/
#define  TIM_DIER_UIE                        ((uint16_t)0x0001)            /*!<Update interrupt enable */
#define  TIM_DIER_CC1IE                      ((uint16_t)0x0002)            /*!<Capture/Compare 1 interrupt enable */
#define  TIM_DIER_CC2IE                      ((uint16_t)0x0004)            /*!<Capture/Compare 2 interrupt enable */
#define  TIM_DIER_CC3IE                      ((uint16_t)0x0008)            /*!<Capture/Compare 3 interrupt enable */
#define  TIM_DIER_CC4IE                      ((uint16_t)0x0010)            /*!<Capture/Compare 4 interrupt enable */
#define  TIM_DIER_COMIE                      ((uint16_t)0x0020)            /*!<COM interrupt enable */
#define  TIM_DIER_TIE                        ((uint16_t)0x0040)            /*!<Trigger interrupt enable */
#define  TIM_DIER_BIE                        ((uint16_t)0x0080)            /*!<Break interrupt enable */
#define  TIM_DIER_UDE                        ((uint16_t)0x0100)            /*!<Update DMA request enable */
#define  TIM_DIER_CC1DE                      ((uint16_t)0x0200)            /*!<Capture/Compare 1 DMA request enable */
#define  TIM_DIER_CC2DE                      ((uint16_t)0x0400)            /*!<Capture/Compare 2 DMA request enable */
#define  TIM_DIER_CC3DE                      ((uint16_t)0x0800)            /*!<Capture/Compare 3 DMA request enable */
#define  TIM_DIER_CC4DE                      ((uint16_t)0x1000)            /*!<Capture/Compare 4 DMA request enable */
#define  TIM_DIER_COMDE                      ((uint16_t)0x2000)            /*!<COM DMA request enable */
#define  TIM_DIER_TDE                        ((uint16_t)0x4000)            /*!<Trigger DMA request enable */

/********************  Bit definition for TIM_SR register  ********************/
#define  TIM_SR_UIF                          ((uint16_t)0x0001)            /*!<Update interrupt Flag */
#define  TIM_SR_CC1IF                        ((uint16_t)0x0002)            /*!<Capture/Compare 1 interrupt Flag */
#define  TIM_SR_CC2IF                        ((uint16_t)0x0004)            /*!<Capture/Compare 2 interrupt Flag */
#define  TIM_SR_CC3IF                        ((uint16_t)0x0008)            /*!<Capture/Compare 3 interrupt Flag */
#define  TIM_SR_CC4IF                        ((uint16_t)0x0010)            /*!<Capture/Compare 4 interrupt Flag */
#define  TIM_SR_COMIF                        ((uint16_t)0x0020)            /*!<COM interrupt Flag */
#define  TIM_SR_TIF                          ((uint16_t)0x0040)            /*!<Trigger interrupt Flag */
#define  TIM_SR_BIF                          ((uint16_t)0x0080)            /*!<Break interrupt Flag */
#define  TIM_SR_CC1OF                        ((uint16_t)0x0200)            /*!<Capture/Compare 1 Overcapture Flag */
#define  TIM_SR_CC2OF                        ((uint16_t)0x0400)            /*!<Capture/Compare 2 Overcapture Flag */
#define  TIM_SR_CC3OF                        ((uint16_t)0x0800)            /*!<Capture/Compare 3 Overcapture Flag */
#define  TIM_SR_CC4OF                        ((uint16_t)0x1000)            /*!<Capture/Compare 4 Overcapture Flag */

/*******************  Bit definition for TIM_EGR register  ********************/
#define  TIM_EGR_UG                          ((uint8_t)0x01)               /*!<Update Generation */
#define  TIM_EGR_CC1G                        ((uint8_t)0x02)               /*!<Capture/Compare 1 Generation */
#define  TIM_EGR_CC2G                        ((uint8_t)0x04)               /*!<Capture/Compare 2 Generation */
#define  TIM_EGR_CC3G                        ((uint8_t)0x08)               /*!<Capture/Compare 3 Generation */
#define  TIM_EGR_CC4G                        ((uint8_t)0x10)               /*!<Capture/Compare 4 Generation */
#define  TIM_EGR_COMG                        ((uint8_t)0x20)               /*!<Capture/Compare Control Update Generation */
#define  TIM_EGR_TG                          ((uint8_t)0x40)               /*!<Trigger Generation */
#define  TIM_EGR_BG                          ((uint8_t)0x80)               /*!<Break Generation */

/******************  Bit definition for TIM_CCMR1 register  *******************/
#define  TIM_CCMR1_CC1S                      ((uint16_t)0x0003)            /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define  TIM_CCMR1_CC1S_0                    ((uint16_t)0x0001)            /*!<Bit 0 */
#define  TIM_CCMR1_CC1S_1                    ((uint16_t)0x0002)            /*!<Bit 1 */

#define  TIM_CCMR1_OC1FE                     ((uint16_t)0x0004)            /*!<Output Compare 1 Fast enable */
#define  TIM_CCMR1_OC1PE                     ((uint16_t)0x0008)            /*!<Output Compare 1 Preload enable */

#define  TIM_CCMR1_OC1M                      ((uint16_t)0x0070)            /*!<OC1M[2:0] bits (Output Compare 1 Mode) */
#define  TIM_CCMR1_OC1M3                     ((uint32_t)0x10000)           /*!<OC1M[3] bits (Output Compare 1 Mode) */
#define  TIM_CCMR1_OC1M_0                    ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR1_OC1M_1                    ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR1_OC1M_2                    ((uint16_t)0x0040)            /*!<Bit 2 */

#define  TIM_CCMR1_OC1CE                     ((uint16_t)0x0080)            /*!<Output Compare 1Clear Enable */

#define  TIM_CCMR1_CC2S                      ((uint16_t)0x0300)            /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define  TIM_CCMR1_CC2S_0                    ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIM_CCMR1_CC2S_1                    ((uint16_t)0x0200)            /*!<Bit 1 */

#define  TIM_CCMR1_OC2FE                     ((uint16_t)0x0400)            /*!<Output Compare 2 Fast enable */
#define  TIM_CCMR1_OC2PE                     ((uint16_t)0x0800)            /*!<Output Compare 2 Preload enable */

#define  TIM_CCMR1_OC2M                      ((uint16_t)0x7000)            /*!<OC2M[2:0] bits (Output Compare 2 Mode) */
#define  TIM_CCMR1_OC2M3                     ((uint32_t)0x20000)           /*!<OC2M[3] bits (Output Compare 2 Mode) */
#define  TIM_CCMR1_OC2M_0                    ((uint16_t)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR1_OC2M_1                    ((uint16_t)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR1_OC2M_2                    ((uint16_t)0x4000)            /*!<Bit 2 */

#define  TIM_CCMR1_OC2CE                     ((uint16_t)0x8000)            /*!<Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIM_CCMR1_IC1PSC                    ((uint16_t)0x000C)            /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define  TIM_CCMR1_IC1PSC_0                  ((uint16_t)0x0004)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1PSC_1                  ((uint16_t)0x0008)            /*!<Bit 1 */

#define  TIM_CCMR1_IC1F                      ((uint16_t)0x00F0)            /*!<IC1F[3:0] bits (Input Capture 1 Filter) */
#define  TIM_CCMR1_IC1F_0                    ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1F_1                    ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR1_IC1F_2                    ((uint16_t)0x0040)            /*!<Bit 2 */
#define  TIM_CCMR1_IC1F_3                    ((uint16_t)0x0080)            /*!<Bit 3 */

#define  TIM_CCMR1_IC2PSC                    ((uint16_t)0x0C00)            /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define  TIM_CCMR1_IC2PSC_0                  ((uint16_t)0x0400)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2PSC_1                  ((uint16_t)0x0800)            /*!<Bit 1 */

#define  TIM_CCMR1_IC2F                      ((uint16_t)0xF000)            /*!<IC2F[3:0] bits (Input Capture 2 Filter) */
#define  TIM_CCMR1_IC2F_0                    ((uint16_t)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2F_1                    ((uint16_t)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR1_IC2F_2                    ((uint16_t)0x4000)            /*!<Bit 2 */
#define  TIM_CCMR1_IC2F_3                    ((uint16_t)0x8000)            /*!<Bit 3 */

/******************  Bit definition for TIM_CCMR2 register  *******************/
#define  TIM_CCMR2_CC3S                      ((uint16_t)0x0003)            /*!<CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define  TIM_CCMR2_CC3S_0                    ((uint16_t)0x0001)            /*!<Bit 0 */
#define  TIM_CCMR2_CC3S_1                    ((uint16_t)0x0002)            /*!<Bit 1 */

#define  TIM_CCMR2_OC3FE                     ((uint16_t)0x0004)            /*!<Output Compare 3 Fast enable */
#define  TIM_CCMR2_OC3PE                     ((uint16_t)0x0008)            /*!<Output Compare 3 Preload enable */

#define  TIM_CCMR2_OC3M                      ((uint16_t)0x0070)            /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define  TIM_CCMR2_OC3M3                     ((uint32_t)0x10000)           /*!<OC3M[3] bits (Output Compare 1 Mode) */
#define  TIM_CCMR2_OC3M_0                    ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR2_OC3M_1                    ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR2_OC3M_2                    ((uint16_t)0x0040)            /*!<Bit 2 */

#define  TIM_CCMR2_OC3CE                     ((uint16_t)0x0080)            /*!<Output Compare 3 Clear Enable */

#define  TIM_CCMR2_CC4S                      ((uint16_t)0x0300)            /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define  TIM_CCMR2_CC4S_0                    ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIM_CCMR2_CC4S_1                    ((uint16_t)0x0200)            /*!<Bit 1 */

#define  TIM_CCMR2_OC4FE                     ((uint16_t)0x0400)            /*!<Output Compare 4 Fast enable */
#define  TIM_CCMR2_OC4PE                     ((uint16_t)0x0800)            /*!<Output Compare 4 Preload enable */

#define  TIM_CCMR2_OC4M                      ((uint16_t)0x7000)            /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define  TIM_CCMR2_OC4M3                     ((uint32_t)0x20000)           /*!<OC4M[3] bits (Output Compare 1 Mode) */
#define  TIM_CCMR2_OC4M_0                    ((uint16_t)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR2_OC4M_1                    ((uint16_t)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR2_OC4M_2                    ((uint16_t)0x4000)            /*!<Bit 2 */

#define  TIM_CCMR2_OC4CE                     ((uint16_t)0x8000)            /*!<Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIM_CCMR2_IC3PSC                    ((uint16_t)0x000C)            /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define  TIM_CCMR2_IC3PSC_0                  ((uint16_t)0x0004)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3PSC_1                  ((uint16_t)0x0008)            /*!<Bit 1 */

#define  TIM_CCMR2_IC3F                      ((uint16_t)0x00F0)            /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define  TIM_CCMR2_IC3F_0                    ((uint16_t)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3F_1                    ((uint16_t)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR2_IC3F_2                    ((uint16_t)0x0040)            /*!<Bit 2 */
#define  TIM_CCMR2_IC3F_3                    ((uint16_t)0x0080)            /*!<Bit 3 */

#define  TIM_CCMR2_IC4PSC                    ((uint16_t)0x0C00)            /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define  TIM_CCMR2_IC4PSC_0                  ((uint16_t)0x0400)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4PSC_1                  ((uint16_t)0x0800)            /*!<Bit 1 */

#define  TIM_CCMR2_IC4F                      ((uint16_t)0xF000)            /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define  TIM_CCMR2_IC4F_0                    ((uint16_t)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4F_1                    ((uint16_t)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR2_IC4F_2                    ((uint16_t)0x4000)            /*!<Bit 2 */
#define  TIM_CCMR2_IC4F_3                    ((uint16_t)0x8000)            /*!<Bit 3 */

/*******************  Bit definition for TIM_CCER register  *******************/
#define  TIM_CCER_CC1E                       ((uint16_t)0x0001)            /*!<Capture/Compare 1 output enable */
#define  TIM_CCER_CC1P                       ((uint16_t)0x0002)            /*!<Capture/Compare 1 output Polarity */
#define  TIM_CCER_CC1NE                      ((uint16_t)0x0004)            /*!<Capture/Compare 1 Complementary output enable */
#define  TIM_CCER_CC1NP                      ((uint16_t)0x0008)            /*!<Capture/Compare 1 Complementary output Polarity */
#define  TIM_CCER_CC2E                       ((uint16_t)0x0010)            /*!<Capture/Compare 2 output enable */
#define  TIM_CCER_CC2P                       ((uint16_t)0x0020)            /*!<Capture/Compare 2 output Polarity */
#define  TIM_CCER_CC2NE                      ((uint16_t)0x0040)            /*!<Capture/Compare 2 Complementary output enable */
#define  TIM_CCER_CC2NP                      ((uint16_t)0x0080)            /*!<Capture/Compare 2 Complementary output Polarity */
#define  TIM_CCER_CC3E                       ((uint16_t)0x0100)            /*!<Capture/Compare 3 output enable */
#define  TIM_CCER_CC3P                       ((uint16_t)0x0200)            /*!<Capture/Compare 3 output Polarity */
#define  TIM_CCER_CC3NE                      ((uint16_t)0x0400)            /*!<Capture/Compare 3 Complementary output enable */
#define  TIM_CCER_CC3NP                      ((uint16_t)0x0800)            /*!<Capture/Compare 3 Complementary output Polarity */
#define  TIM_CCER_CC4E                       ((uint16_t)0x1000)            /*!<Capture/Compare 4 output enable */
#define  TIM_CCER_CC4P                       ((uint16_t)0x2000)            /*!<Capture/Compare 4 output Polarity */
#define  TIM_CCER_CC4NP                      ((uint16_t)0x8000)            /*!<Capture/Compare 4 Complementary output Polarity */

/*******************  Bit definition for TIM_CNT register  ********************/
#define  TIM_CNT_CNT                         ((uint16_t)0xFFFF)            /*!<Counter Value */

/*******************  Bit definition for TIM_PSC register  ********************/
#define  TIM_PSC_PSC                         ((uint16_t)0xFFFF)            /*!<Prescaler Value */

/*******************  Bit definition for TIM_ARR register  ********************/
#define  TIM_ARR_ARR                         ((uint16_t)0xFFFF)            /*!<actual auto-reload Value */

/*******************  Bit definition for TIM_RCR register  ********************/
#define  TIM_RCR_REP                         ((uint8_t)0xFF)               /*!<Repetition Counter Value */

/*******************  Bit definition for TIM_CCR1 register  *******************/
#define  TIM_CCR1_CCR1                       ((uint16_t)0xFFFF)            /*!<Capture/Compare 1 Value */
#define  TIM_CCR1_CCR1_ASYM                  ((uint32_t)0xFFFF0000)        /*!<Compare Asymmetric 1 Value */

/*******************  Bit definition for TIM_CCR2 register  *******************/
#define  TIM_CCR2_CCR2                       ((uint16_t)0xFFFF)            /*!<Capture/Compare 2 Value */
#define  TIM_CCR2_CCR2_ASYM                  ((uint32_t)0xFFFF0000)        /*!<Compare Asymmetric 2 Value */

/*******************  Bit definition for TIM_CCR3 register  *******************/
#define  TIM_CCR3_CCR3                       ((uint16_t)0xFFFF)            /*!<Capture/Compare 3 Value */
#define  TIM_CCR3_CCR3_ASYM                  ((uint32_t)0xFFFF0000)        /*!<Compare Asymmetric 3 Value */

/*******************  Bit definition for TIM_CCR4 register  *******************/
#define  TIM_CCR4_CCR4                       ((uint16_t)0xFFFF)            /*!<Capture/Compare 4 Value */
#define  TIM_CCR4_CCR4_ASYM                  ((uint32_t)0xFFFF0000)        /*!<Compare Asymmetric 4 Value */

/*******************  Bit definition for TIM_BDTR register  *******************/
#define  TIM_BDTR_DTG                        ((uint16_t)0x00FF)            /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define  TIM_BDTR_DTG_0                      ((uint16_t)0x0001)            /*!<Bit 0 */
#define  TIM_BDTR_DTG_1                      ((uint16_t)0x0002)            /*!<Bit 1 */
#define  TIM_BDTR_DTG_2                      ((uint16_t)0x0004)            /*!<Bit 2 */
#define  TIM_BDTR_DTG_3                      ((uint16_t)0x0008)            /*!<Bit 3 */
#define  TIM_BDTR_DTG_4                      ((uint16_t)0x0010)            /*!<Bit 4 */
#define  TIM_BDTR_DTG_5                      ((uint16_t)0x0020)            /*!<Bit 5 */
#define  TIM_BDTR_DTG_6                      ((uint16_t)0x0040)            /*!<Bit 6 */
#define  TIM_BDTR_DTG_7                      ((uint16_t)0x0080)            /*!<Bit 7 */

#define  TIM_BDTR_LOCK                       ((uint16_t)0x0300)            /*!<LOCK[1:0] bits (Lock Configuration) */
#define  TIM_BDTR_LOCK_0                     ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIM_BDTR_LOCK_1                     ((uint16_t)0x0200)            /*!<Bit 1 */

#define  TIM_BDTR_OSSI                       ((uint16_t)0x0400)            /*!<Off-State Selection for Idle mode */
#define  TIM_BDTR_OSSR                       ((uint16_t)0x0800)            /*!<Off-State Selection for Run mode */
#define  TIM_BDTR_BKE                        ((uint16_t)0x1000)            /*!<Break enable */
#define  TIM_BDTR_BKP                        ((uint16_t)0x2000)            /*!<Break Polarity */
#define  TIM_BDTR_AOE                        ((uint16_t)0x4000)            /*!<Automatic Output enable */
#define  TIM_BDTR_MOE                        ((uint16_t)0x8000)            /*!<Main Output enable */

/*******************  Bit definition for TIM_DCR register  ********************/
#define  TIM_DCR_DBA                         ((uint16_t)0x001F)            /*!<DBA[4:0] bits (DMA Base Address) */
#define  TIM_DCR_DBA_0                       ((uint16_t)0x0001)            /*!<Bit 0 */
#define  TIM_DCR_DBA_1                       ((uint16_t)0x0002)            /*!<Bit 1 */
#define  TIM_DCR_DBA_2                       ((uint16_t)0x0004)            /*!<Bit 2 */
#define  TIM_DCR_DBA_3                       ((uint16_t)0x0008)            /*!<Bit 3 */
#define  TIM_DCR_DBA_4                       ((uint16_t)0x0010)            /*!<Bit 4 */

#define  TIM_DCR_DBL                         ((uint16_t)0x1F00)            /*!<DBL[4:0] bits (DMA Burst Length) */
#define  TIM_DCR_DBL_0                       ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIM_DCR_DBL_1                       ((uint16_t)0x0200)            /*!<Bit 1 */
#define  TIM_DCR_DBL_2                       ((uint16_t)0x0400)            /*!<Bit 2 */
#define  TIM_DCR_DBL_3                       ((uint16_t)0x0800)            /*!<Bit 3 */
#define  TIM_DCR_DBL_4                       ((uint16_t)0x1000)            /*!<Bit 4 */

/*******************  Bit definition for TIM_DMAR register  *******************/
#define  TIM_DMAR_DMAB                       ((uint16_t)0xFFFF)            /*!<DMA register for burst accesses */

/******************************************************************************/
/*                                                                            */
/*                    Serial Peripheral Interface (SPI)                       */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for SPI_CTRLR0 register  *******************/
#define SPI_CTRLR0_DFS                          ((uint32_t)0x001F0000)
#define SPI_CTRLR0_FRF                          ((uint32_t)0x00000030)
#define SPI_CTRLR0_SCPH                         ((uint32_t)0x00000040)
#define SPI_CTRLR0_SCPOL                        ((uint32_t)0x00000080)
#define SPI_CTRLR0_TMOD                         ((uint32_t)0x00000300)
#define SPI_CTRLR0_SLV_OE                       ((uint32_t)0x00000400)
#define SPI_CTRLR0_SRL                          ((uint32_t)0x00000800)
#define SPI_CTRLR0_CFS                          ((uint32_t)0x0000F000)
#define SPI_CTRLR0_SPI_FRF                      ((uint32_t)0x00600000)
#define SPI_CTRLR0_SSTE                         ((uint32_t)0x01000000)
#define SPI_CTRLR0_SECONV                       ((uint32_t)0x02000000)

/*****************  Bit definition for SPI_CTRLR1 register  *******************/
#define SPI_CTRLR1_NDF                          ((uint32_t)0x0000FFFF)

/*****************  Bit definition for SPI_SSIENR register  *******************/
#define SPI_SSIENR_SSI_EN                       ((uint32_t)0x00000001)

/*****************  Bit definition for SPI_BAUDR register  ********************/
#define SPI_BAUDR_SCKDV                         ((uint32_t)0x0000FFFF)

/*****************  Bit definition for SPI_SER register  **********************/
#define SPI_SER_SER                             ((uint32_t)0x00000001)

/*****************  Bit definition for MWCR register  *************************/
#define SPI_MWCR_MWMOD                          ((uint32_t)0x00000001)
#define SPI_MWCR_MDD                            ((uint32_t)0x00000002)
#define SPI_MWCR_MHS                            ((uint32_t)0x00000004)

/*****************  Bit definition for SPI_TXFTLR register  *******************/
#define SPI_TXFTLR_TFT                          ((uint32_t)0x00000007)

/*****************  Bit definition for SPI_RXFTLR register  *******************/
#define SPI_RXFTLR_RFT                          ((uint32_t)0x00000007)

/*****************  Bit definition for SPI_IMR register  **********************/
#define SPI_IMR_TXEIM                           ((uint32_t)0x00000001)
#define SPI_IMR_TXOIM                           ((uint32_t)0x00000002)
#define SPI_IMR_RXUIM                           ((uint32_t)0x00000004)
#define SPI_IMR_RXOIM                           ((uint32_t)0x00000008)
#define SPI_IMR_RXFIM                           ((uint32_t)0x00000010)
#define SPI_IMR_MSTIM                           ((uint32_t)0x00000020)

/*****************  Bit definition for SPI_TCFTLR register  *******************/
#define SPI_SPI_CTRLR0_TRANS_TYPE               ((uint32_t)0x00000003)
#define SPI_SPI_CTRLR0_ADDR_L                   ((uint32_t)0x0000003C)
#define SPI_SPI_CTRLR0_INST_L                   ((uint32_t)0x00000300)
#define SPI_SPI_CTRLR0_WAIT_CYCLES              ((uint32_t)0x0000F800)

/******************************************************************************/
/*                                                                            */
/*                 System configuration controller (SYSCFG)                   */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for SYSCFG_CFGR register  ******************/
#define SYSCFG_CFGR_MEM_MODE                    ((uint32_t)0x00000003)         /*!< Memory mapping selection bits                   */
#define SYSCFG_CFGR_LOCKUP_LOCK                 ((uint32_t)0x00000004)         /*!< Cortex®-M0+ LOCKUP bit enable bit               */
#define SYSCFG_CFGR_PVD_LOCK                    ((uint32_t)0x00000008)         /*!< PVD lock enable bit                             */
#define SYSCFG_CFGR_TIMER_BREAK_OSSI0_DISOUT    ((uint32_t)0x00000010)         /*!< Timer break OSSI0 disout                        */
#define SYSCFG_CFGR_ANALOG_TEST_SEL             ((uint32_t)0x000000E0)         /*!< Analog test select                              */
#define SYSCFG_CFGR_DIGITAL_TEST_SEL            ((uint32_t)0x00000F00)         /*!< Digital test select                             */
#define SYSCFG_CFGR_IREF_TRIM                   ((uint32_t)0x00003000)         /*!< Internal reference current trim                 */
#define SYSCFG_CFGR_TIM14_TISEL                 ((uint32_t)0x00010000)         /*!< Timer14 timer select                            */
#define SYSCFG_CFGR_TIM1_SYNC_CNT_EN            ((uint32_t)0x00020000)         /*!< Timer1 synchronous counting enable              */
#define SYSCFG_CFGR_TIM2_SYNC_CNT_EN            ((uint32_t)0x00040000)         /*!< Timer2 synchronous counting enable              */
#define SYSCFG_CFGR_TIM6_SYNC_CNT_EN            ((uint32_t)0x00080000)         /*!< Timer6 synchronous counting enable              */
#define SYSCFG_CFGR_TIM7_SYNC_CNT_EN            ((uint32_t)0x00100000)         /*!< Timer7 synchronous counting enable              */
#define SYSCFG_CFGR_TIM14_SYNC_CNT_EN           ((uint32_t)0x00200000)         /*!< Timer14 synchronous counting enable             */

/*****************  Bit definition for SYSCFG_CFGR register  ******************/
#define SYSCFG_FLASH_VREF_TRIM                  ((uint32_t)0x00000007)         /*!< Flash voltage reference triming                 */

/******************************************************************************/
/*                                                                            */
/*                            Debug Support (DBG)                             */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for DBG_IDCODE register  *******************/
#define DBG_IDCODE_DEV_ID                       ((uint32_t)0xFFFFFFFF)         /*!< Device identifier                                   */

/*****************  Bit definition for DBG_APB_FZ register  *******************/
#define DBG_APB_FZ_DBG_TIM1_STOP                ((uint32_t)0x00000002)         /*!< Clocking of TIM1 counter when the core is halted    */
#define DBG_APB_FZ_DBG_TIM2_STOP                ((uint32_t)0x00000004)         /*!< Clocking of TIM2 counter when the core is halted    */
#define DBG_APB_FZ_DBG_TIM3_STOP                ((uint32_t)0x00000008)         /*!< Clocking of TIM3 counter when the core is halted    */
#define DBG_APB_FZ_DBG_TIM6_STOP                ((uint32_t)0x00000040)         /*!< Clocking of TIM6 counter when the core is halted    */ 
#define DBG_APB_FZ_DBG_TIM7_STOP                ((uint32_t)0x00000080)         /*!< Clocking of TIM7 counter when the core is halted    */
#define DBG_APB_FZ_DBG_RTC_STOP                 ((uint32_t)0x00000400)         /*!< Clocking of RTC counter when the core is halted     */
#define DBG_APB_FZ_DBG_WWDG_STOP                ((uint32_t)0x00000800)         /*!< Clocking of WWDG counter when the core is halted    */
#define DBG_APB_FZ_DBG_IWDG_STOP                ((uint32_t)0x00001000)         /*!< Clocking of IWDG counter when the core is halted    */
#define DBG_APB_FZ_DBG_TIM14_STOP               ((uint32_t)0x00004000)         /*!< Clocking of TIM14 counter when the core is halted   */
#define DBG_APB_FZ_DBG_TIM15_STOP               ((uint32_t)0x00008000)         /*!< Clocking of TIM15 counter when the core is halted   */
#define DBG_APB_FZ_DBG_TIM16_STOP               ((uint32_t)0x00010000)         /*!< Clocking of TIM16 counter when the core is halted   */
#define DBG_APB_FZ_DBG_TIM17_STOP               ((uint32_t)0x00020000)         /*!< Clocking of TIM17 counter when the core is halted   */
#define DBG_APB_FZ_DBG_LPTIM1_STOP              ((uint32_t)0x80000000)         /*!< Clocking of LPTIM1 counter when the core is halted  */

/******************************************************************************/
/*                                                                            */
/*                            Power Control (PWR)                             */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for PWR_CR register  ***********************/
#define PWR_CR_FPD_STOP                           ((uint32_t)0x00000002)         /*!< Flash memory powered down during Stop mode */
#define PWR_CR_FPD_LPRUN                          ((uint32_t)0x00000004)         /*!< Flash memory powered down during Low-power run mode */
#define PWR_CR_FPD_LPSLP                          ((uint32_t)0x00000008)         /*!< Flash memory powered down during Low-power sleep mode */
#define PWR_CR_DBP                                ((uint32_t)0x00000010)         /*!< Disable RTC domain write protection */
#define PWR_CR_VOS                                ((uint32_t)0x00000060)         /*!< Voltage scaling range selection */
#define PWR_CR_LPR                                ((uint32_t)0x00000080)         /*!< Low-power run */
#define PWR_CR_PVDE                               ((uint32_t)0x00000100)         /*!< Power voltage detector enable */
#define PWR_CR_PVDT                               ((uint32_t)0x00007000)         /*!< Power voltage detector rising threshold selection */
#define PWR_CR_LVD_RST_EN                         ((uint32_t)0x00008000)         /*!< LVD reset enable */
#define PWR_CR_STOP_DLY_CNT                       ((uint32_t)0x00FF0000)         /*!< Stop delay counter */

/*****************  Bit definition for PWR_SR register  ***********************/
#define PWR_SR_FLASH_RDY                          ((uint32_t)0x00000001)         /*!< Flash ready flag */
#define PWR_SR_PVDO                               ((uint32_t)0x00000002)         /*!< Power voltage detector output */

#endif

