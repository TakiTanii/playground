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
  WWDG_IRQn                   = 0,     /*!< Window WatchDog Interrupt                               */
  PVD_IRQn                    = 1,     /*!< PVD through EXTI Line detect Interrupt                  */
  RTC_IRQn                    = 2,     /*!< RTC through EXTI Line Interrupt                         */
  FLASH_IRQn                  = 3,    /*!< FLASH Interrupt                                         */
  RCC_IRQn                    = 4,    /*!< RCC Interrupt                                           */
  EXTI0_1_IRQn                = 5,    /*!< EXTI Line 0 and 1 Interrupts                            */
  EXTI2_3_IRQn                = 6,    /*!< EXTI Line 2 and 3 Interrupts                            */
  EXTI4_15_IRQn               = 7,    /*!< EXTI Line 4 to 15 Interrupts                            */
  DMA_IRQn                    = 8,    /*!< DMA Interrupt                                           */
  ADC_IRQn                    = 9,    /*!< ADC Interrupts                                          */
  TIM1_IRQn                   = 10,    /*!< TIM1 Interrupts                                         */
  TIM2_IRQn                   = 11,    /*!< TIM2 Interrupts                                         */
  TIM14_IRQn                  = 12,    /*!< TIM14 Interrupts                                        */
  TIM6_IRQn                   = 14,    /*!< TIM6 Interrupt                                          */
  TIM7_IRQn                   = 15,    /*!< TIM7 Interrupt                                          */
  LPTIM_IRQn                  = 16,    /*!< LPTIM Interrupt                                         */
  USART1_IRQn                 = 17,    /*!< USART1 Interrupt                                        */
  USART2_IRQn                 = 18,    /*!< UASRT2 Interrupt                                        */
  I2C1_IRQn                   = 19,    /*!< I2C1 Interrupt                                          */
  SPI1_IRQn                   = 20,    /*!< SPI1 Interrupt                                          */
  IWDG_IRQn                   = 21,    /*!< IWDG Interrupt                                          */
  CORDIC_IRQn                 = 22,    /*!< CORDIC Interrupt                                        */
  EXTI16_20_IRQn              = 23     /*!< EXTI Line 16 and 20 Interrupt                           */
} IRQn_Type;

/**
  * @}
  */

#include "core_cm0.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */  

/** 
  * @brief EXTI
  */

typedef struct{
  __IO  uint32_t  RTSR;       /*!< EXTI Rising Edge Selection Register                      Address offset: 0x000 */
  __IO  uint32_t  FTSR;       /*!< EXTI Falling Edge Selection Register                     Address offset: 0x004 */
  __O   uint32_t  SWIER;      /*!< EXTI Software Interrupt Event Register                   Address offset: 0x008 */
  __IO  uint32_t  PR;         /*!< EXTI Pending Register                                    Address offset: 0x00C */
  __IO  uint32_t  EXTICR1;    /*!< EXTI Configuration Register 1                            Address offset: 0x010 */
  __IO  uint32_t  EXTICR2;    /*!< EXTI Configuration Register 2                            Address offset: 0x014 */
  __IO  uint32_t  IMR;        /*!< EXTI Interrupt Masking Register                          Address offset: 0x018 */
  __IO  uint32_t  EMR;        /*!< EXTI Event Masking Register                              Address offset: 0x01C */
}EXTI_TypeDef;

/** 
  * @brief DMA
  */

typedef struct
{
    __IO uint32_t CCR;          /*!< DMA channel x configuration register              Address offset: 0x10*(x) */
    __IO uint32_t CNDTR;        /*!< DMA channel x number of data register       Address offset: 0x10*(x) + 0x4 */
    __IO uint32_t CPAR;         /*!< DMA channel x peripheral address register   Address offset: 0x10*(x) + 0x8 */
    __IO uint32_t CMAR;         /*!< DMA channel x memory address register       Address offset: 0x10*(x) + 0xC */
} DMA_Channel_TypeDef;

typedef struct
{
    __IO uint32_t ISR;          /*!< DMA interrupt status register,                        Address offset: 0x00 */
    __IO uint32_t IFCR;         /*!< DMA interrupt flag clear register                     Address offset: 0x04 */
} DMA_TypeDef;

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
}RCC_TypeDef;

/** 
  * @brief Real Time Clock
  */

typedef struct{
  __IO uint32_t TR;           /*!< RTC Time Register                                        Address offset: 0x000 */
  __IO uint32_t DR;           /*!< RTC Date Register                                        Address offset: 0x004 */
  __I  uint32_t SSR;          /*!< RTC Subsecond Register                                   Address offset: 0x008 */
  __IO uint32_t ICSR;         /*!< RTC Init Control and Status Register                     Address offset: 0x00C */
  __IO uint32_t PRER;         /*!< RTC Prescaler Register                                   Address offset: 0x010 */
  __IO uint32_t WUTR;         /*!< RTC Wakeup Timer Register                                Address offset: 0x014 */
  __IO uint32_t CR;           /*!< RTC Control Register                                     Address offset: 0x018 */
       uint32_t RESERVED0[2]; /*!< Reserved                                                                       */
  __O  uint32_t WPR;          /*!< RTC Write Protection Register                            Address offset: 0x024 */
  __IO uint32_t CALR;         /*!< RTC Calibration Register                                 Address offset: 0x028 */
  __O  uint32_t SHIFTR;       /*!< RTC Shift Control Register                               Address offset: 0x02C */
  __I  uint32_t TSTR;         /*!< RTC Timestamp Time Register                              Address offset: 0x030 */
  __I  uint32_t TSDR;         /*!< RTC Timestamp Date Register                              Address offset: 0x034 */
  __I  uint32_t TSSSR;        /*!< RTC Timestamp Subsecond Register                         Address offset: 0x038 */
       uint32_t RESERVED1;    /*!< Reserved                                                                       */
  __IO uint32_t ALRMAR;       /*!< RTC Alarm A Register                                     Address offset: 0x040 */
  __IO uint32_t ALRMASSR;     /*!< RTC Alarm A Subsecond Register                           Address offset: 0x044 */
  __IO uint32_t ALRMBR;       /*!< RTC Alarm B Register                                     Address offset: 0x048 */
  __IO uint32_t ALRMBSSR;     /*!< RTC Alarm B Subsecond Register                           Address offset: 0x04C */
  __I  uint32_t SR;           /*!< RTC Status Register                                      Address offset: 0x050 */
  __I  uint32_t MISR;         /*!< RTC Masked Interrupt Status Register                     Address offset: 0x054 */
       uint32_t RESERVED2;    /*!< Reserved                                                                       */
  __O  uint32_t SCR;          /*!< RTC Status Clear Register                                Address offset: 0x05C */
}RTC_TypeDef;

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
  * @brief CORDIC
  */

typedef struct{
  __IO uint32_t CSR;          /*!< CORDIC Config Status Register,                           Address offset:0x00 */
  __O  uint32_t ARG;          /*!< CORDIC Input Argument Register,                          Address offset:0x04 */
  __I  uint32_t RES;          /*!< CORDIC Output Result Register,                           Address offset:0x08 */
}CORDIC_TypeDef;

/** 
  * @brief Analog to Digital Converter  
  */

typedef struct
{
  __IO uint32_t ISR;           /*!< ADC Interrupt and Status register,                          Address offset:0x000 */
  __IO uint32_t IER;           /*!< ADC Interrupt Enable register,                              Address offset:0x004 */
  __IO uint32_t CR;            /*!< ADC Control register,                                       Address offset:0x008 */
  __IO uint32_t CFGR1;         /*!< ADC Configuration register 1,                               Address offset:0x00C */
  __IO uint32_t CFGR2;         /*!< ADC Configuration register 2,                               Address offset:0x010 */
  __IO uint32_t SMPR;          /*!< ADC Sampling time register,                                 Address offset:0x014 */
  __IO uint32_t AWDTR;         /*!< ADC Watchdog Threshold register,                            Address offset:0x018 */
  __IO uint32_t AWDCR;         /*!< ADC Analog Watchdog Configuration Register,                 Address offset:0x01C */
  __IO uint32_t CHSELR1;       /*!< ADC Channel Selection 1 registers,                          Address offset:0x020 */
  __IO uint32_t CHSELR2;       /*!< ADC Channel Selection 2 registers,                          Address offset:0x024 */
  __IO uint32_t JSQR;          /*!< ADC Injected Sequence register,                             Address offset:0x028 */
  __IO uint32_t DR;            /*!< ADC Data register,                                          Address offset:0x02C */
  __IO uint32_t JDR;           /*!< ADC Injected Data register,                                 Address offset:0x030 */
  __IO uint32_t DAR;           /*!< ADC Data Address register,                                  Address offset:0x034 */
  __IO uint32_t JDAR;          /*!< ADC Injected Data Address register,                         Address offset:0x038 */
  __IO uint32_t RESERVED[179]; /*!< Reserved,                                                                  0x04C */
  __IO uint32_t CCR;           /*!< ADC Common Control register,                                Address offset:0x308 */
} ADC_TypeDef;

/** 
  * @brief USART
  */
typedef struct
{
  __O   uint32_t  US_CR;                   /*!< Offset: 0x0000 Control Register                   (W) */
  __IO  uint32_t  US_MR;                   /*!< Offset: 0x0004 Mode Register                      (R/W) */
  __O   uint32_t  US_IER;                  /*!< Offset: 0x0008 Interrupt Enable Register          (W) */
  __O   uint32_t  US_IDR;                  /*!< Offset: 0x000C Interrupt Disable Register         (W) */
  __O   uint32_t  US_IMR;                  /*!< Offset: 0x0010 Interrupt Mask Register            (R) */
  __I   uint32_t  US_CSR;                  /*!< Offset: 0x0014 Channel Status Register            (R) */
  __I   uint32_t  US_RHR;                  /*!< Offset: 0x0018 Receive Holding Register           (R) */
  __O   uint32_t  US_THR;                  /*!< Offset: 0x001C Transmit Holding Register          (W) */
  __IO  uint32_t  US_BRGR;                 /*!< Offset: 0x0020 Baud Rate Generator Register       (R/W) */
  __IO  uint32_t  US_RTOR;                 /*!< Offset: 0x0024 Receiver Time-out Register         (R/W) */
  __IO  uint32_t  US_TTGR;                 /*!< Offset: 0x0028 Transmitter Timeguard Register     (R/W) */
  __IO  uint32_t  US_XXX0;                 /*!< Offset: 0x002C Empty Register                     (R/W) */
  __I   uint32_t  US_RXPO;                 /*!< Offset: 0x0030 Receiver Pointer Register          (R) */
  __I   uint32_t  US_RXCO;                 /*!< Offset: 0x0034 Receiver Counter Register          (R) */
  __I   uint32_t  US_TXPO;                 /*!< Offset: 0x0038 Transmitter Pointer Register       (R) */
  __I   uint32_t  US_TXCO;                 /*!< Offset: 0x003C Transmitter Counter Register       (R) */
  __IO  uint32_t  US_FIDI;                 /*!< Offset: 0x0040 FI DI RATIO Register               (R/W) */
  __I   uint32_t  US_NER;                  /*!< Offset: 0x0044 Number of Errors Register          (R) */
  __IO  uint32_t  US_XOXF;                 /*!< Offset: 0x0048 XON XOFF Register                  (R/W) */
  __IO  uint32_t  US_IF;                   /*!< Offset: 0x004C IrDA FILTER Register               (R/W) */
  __IO  uint32_t  US_MAN;                  /*!< Offset: 0x0050 Manchester Configuration Register  (R/W) */
  __IO  uint32_t  US_LINMR;                /*!< Offset: 0x0054 LIN Mode Register                  (R/W) */
  __IO  uint32_t  US_LINIR;                /*!< Offset: 0x0058 LIN Identifier Register            (R/W) */
  __I   uint32_t  US_LINBRR;               /*!< Offset: 0x005C LIN Baud Rate Register             (R) */
  __IO  uint32_t  US_LONMR;                /*!< Offset: 0x0060 LON Mode Register                  (R/W) */
  __IO  uint32_t  US_LONPR;                /*!< Offset: 0x0064 LON Preamble Register              (R/W) */
  __IO  uint32_t  US_LONDL;                /*!< Offset: 0x0068 LON Data Length Register           (R/W) */
  __IO  uint32_t  US_LONL2HDR;             /*!< Offset: 0x006C LON L2HDR Register                 (R/W) */
  __I   uint32_t  US_LONBL;                /*!< Offset: 0x0070 LON Backlog Register               (R) */
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
  __I   uint32_t  US_VERSION;              /*!< Offset: 0x00FC Version Register                   (R) */
} USART_TypeDef;


/** * @brief DW_APB_SSI STRUCT  ** */
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
    __IO uint32_t DR[35];                  // Data register
    __IO uint32_t RSVD_X;                  // Data register	
    __IO uint32_t RX_SAMPLE_DLY;        // Receive sample delay register
    __IO uint32_t SPI_CTRLR0;           // SPI control register 0
    __IO uint32_t TXD_DRIVE_EDGE;       // Transmit data drive edge control register
    __IO uint32_t RSVD;                 // Reserved register
} SPI_TypeDef;


/** * @brief GPIO STRUCT  ** */
typedef struct
{	
	__IO uint32_t MODER; 			    // address offset:0x00
	__IO uint32_t OTYPER;	        // address offset:0x04
	__IO uint32_t PUPDR; 	        // address offset:0x08
	__IO uint32_t DIRR;    	    	// address offset:0x0C
	__I  uint32_t IDR;   	        // address offset:0x10
	__IO uint32_t ODR;   	        // address offset:0x14
	__IO uint32_t BSRR;  	        // address offset:0x18
	__IO uint32_t LCKR;  	        // address offset:0x1C
	__IO uint32_t AFRL;  	        // address offset:0x20
	__IO uint32_t AFRH;  	        // address offset:0x24
	__IO uint32_t BRR;   	        // address offset:0x28
} GPIO_TypeDef;


/** * @brief FLASH STRUCT  ** */
typedef struct
{	
	__IO uint32_t ACR; 			    // address offset:0x00
	__IO uint32_t CR;	            // address offset:0x04
	__IO uint32_t KEYR; 	        // address offset:0x08
	__IO uint32_t SR;   	        // address offset:0x0C
	__IO uint32_t FAR;   	        // address offset:0x10
	__IO uint32_t PGSDR;  	        // address offset:0x14
	__IO uint32_t OBR;  	        // address offset:0x18
	__IO uint32_t FLASH_RESERVED1;  // address offset:0x1C
	__IO uint32_t PBRDP1R;  	    // address offset:0x20
	__IO uint32_t PBRDP2R;   	    // address offset:0x24
	__IO uint32_t WRP1R;	    	// address offset:0x28
	__IO uint32_t WRP2R;  		    // address offset:0x2C
	__IO uint32_t ECCR;    	    	// address offset:0x30
    __IO uint32_t FLASH_RESERVED2[3];
    __IO uint32_t CFGR;             // address offset:0x40
    __IO uint32_t FLASH_RESERVED3[15];
    __IO uint32_t MPSKEYRL;         // address offset:0x80
    __IO uint32_t MPSKEYRH;         // address offset:0x84
    __IO uint32_t ISPKEYRL;         // address offset:0x88
    __IO uint32_t ISPKEYRH;         // address offset:0x8C
    __IO uint32_t FLASH_RESERVED4[12];
    __IO uint32_t CONFIGKEYR;       // address offset:0xC0
} FLASH_TypeDef;


/** 
  * @brief Analog Control  
  */
typedef struct
{
  __IO uint32_t COMP1_CSR;     /*!< COMP 1 Comparator Control and Status register,              Address offset: 0x000 */
  __IO uint32_t COMP2_CSR;     /*!< COMP 2 Comparator Control and Status register,              Address offset: 0x004 */
  __IO uint32_t COMP_VCR;      /*!< COMP Comparator Voltage Reference register,                 Address offset: 0x008 */
  __IO uint32_t COMP1_POLL;    /*!< COMP 1 Comparator polling register,                         Address offset: 0x00C */
  __IO uint32_t COMP2_POLL;    /*!< COMP 2 Comparator polling register,                         Address offset: 0x010 */
  __IO uint32_t RESERVED1[11]; /*!< Reserved,                                                                   0x014 */
  __IO uint32_t OPAMP1_CSR;    /*!< OPAMP1 Control/Status register,                             Address offset: 0x040 */
  __IO uint32_t OPAMP1_TCMR;   /*!< OPAMP1 Timer Controlled Mode register,                      Address offset: 0x044 */
  __IO uint32_t RESERVED2[14]; /*!< Reserved,                                                                   0x048 */
  __IO uint32_t OPAMP2_CSR;    /*!< OPAMP2 Control/Status register,                             Address offset: 0x080 */
  __IO uint32_t OPAMP2_TCMR;   /*!< OPAMP2 Timer Controlled Mode register,                      Address offset: 0x084 */
  __IO uint32_t RESERVED3[14]; /*!< Reserved,                                                                   0x088 */
  __IO uint32_t OPAMP3_CSR;    /*!< OPAMP3 Control/Status register,                             Address offset: 0x0C0 */
  __IO uint32_t OPAMP3_TCMR;   /*!< OPAMP3 Timer Controlled Mode register,                      Address offset: 0x0C4 */
  __IO uint32_t RESERVED4[14]; /*!< Reserved,                                                                   0x0C8 */
  __IO uint32_t OPAMP4_CSR;    /*!< OPAMP4 Control/Status register,                             Address offset: 0x100 */
  __IO uint32_t OPAMP4_TCMR;   /*!< OPAMP4 Timer Controlled Mode register,                      Address offset: 0x104 */
  __IO uint32_t RESERVED5[14]; /*!< Reserved,                                                                   0x108 */
  __IO uint32_t OPAMP5_CSR;    /*!< OPAMP5 Control/Status register,                             Address offset: 0x140 */
  __IO uint32_t OPAMP5_TCMR;   /*!< OPAMP5 Timer Controlled Mode register,                      Address offset: 0x144 */
  __IO uint32_t RESERVED6[14]; /*!< Reserved,                                                                   0x148 */
  __IO uint32_t OPAMP6_CSR;    /*!< OPAMP5 Control/Status register,                             Address offset: 0x180 */
  __IO uint32_t OPAMP6_TCMR;   /*!< OPAMP5 Timer Controlled Mode register,                      Address offset: 0x184 */
  __IO uint32_t RESERVED7[14]; /*!< Reserved,                                                                   0x188 */
  __IO uint32_t DAC1_CR;       /*!< DAC 1 Control register,                                     Address offset: 0x1C0 */
  __IO uint32_t DAC1_DHR12R;   /*!< DAC 1 12-bit right aligned data holding register,           Address offset: 0x1C4 */
  __IO uint32_t DAC1_DHR12L;   /*!< DAC 1 12-bit left aligned data holding register,            Address offset: 0x1C8 */
  __IO uint32_t RESERVED8[13]; /*!< Reserved,                                                                   0x1CC */
  __IO uint32_t DAC2_CR;       /*!< DAC 2 Control register,                                     Address offset: 0x200 */
  __IO uint32_t DAC2_DHR12R;   /*!< DAC 2 12-bit right aligned data holding register,           Address offset: 0x204 */
  __IO uint32_t DAC2_DHR12L;   /*!< DAC 2 12-bit left aligned data holding register,            Address offset: 0x208 */    
  __IO uint32_t RESERVED9[13]; /*!< Reserved,                                                                   0x20C */
} ANA_CTRL_TypeDef;

/** 
  * @brief Window WATCHDOG
  */

typedef struct
{
  __IO uint32_t CR;            /*!< WWDG Control register,                                      Address offset: 0x000 */
  __IO uint32_t CFR;           /*!< WWDG Configuration register,                                Address offset: 0x004 */
  __IO uint32_t SR;            /*!< WWDG Status register,                                       Address offset: 0x008 */
}WWDG_TypeDef;


/** 
  * @brief Independent WATCHDOG
  */

typedef struct
{
  __O  uint32_t KR;            /*!< IWDG Key register,                                          Address offset: 0x000 */
  __IO uint32_t PR;            /*!< IWDG Prescaler register,                                    Address offset: 0x004 */
  __IO uint32_t RLR;           /*!< IWDG Reload register,                                       Address offset: 0x008 */
  __IO uint32_t SR;            /*!< IWDG Status register,                                       Address offset: 0x00C */ 
  __IO uint32_t WINR;          /*!< IWDG Window register,                                       Address offset: 0x010 */
  __I  uint32_t CNT;           /*!< IWDG CNT register,                                          Address offset: 0x018 */
}IWDG_TypeDef;


/** 
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t IDREV;           /*!<                                    Address offset: 0x00 */
       uint32_t RESERVED0;       /*!< Reserved,                          Address offset: 0x04 */
       uint32_t RESERVED1;       /*!< Reserved,                          Address offset: 0x08 */
       uint32_t RESERVED2;       /*!< Reserved,                          Address offset: 0x0C */
  __IO uint32_t CFG;             /*!< I2C Configuration Register,        Address offset: 0x10 */
  __IO uint32_t INTEN;           /*!< I2C Interrupt Enable Register,     Address offset: 0x14 */
  __IO uint32_t STATUS;          /*!< I2C Status Register,               Address offset: 0x18 */
  __IO uint32_t ADDR;            /*!< I2C Address Register,              Address offset: 0x1C */
  __IO uint32_t DATA;            /*!< I2C Data register,                 Address offset: 0x20 */
  __IO uint32_t CTRL;            /*!< I2C Control register,              Address offset: 0x24 */
  __IO uint32_t CMD;             /*!< I2C Command register,              Address offset: 0x28 */
  __IO uint32_t SETUP;           /*!< I2C Setup register,                Address offset: 0x2C */
  __IO uint32_t TPM;             /*!< I2C Timing parameter multiplier register, Address offset: 0x30 */
  __IO uint32_t TIMING;          /*!< I2C Timing register,               Address offset: 0x34 */
  __IO uint32_t MASK;            /*!< I2C Make register,                 Address offset: 0x34 */
  __I  uint32_t REC_ADDR;        /*!< I2C Receive address register,      Address offset: 0x34 */
}I2C_TypeDef;

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
  * @brief Low-power Timer
  */

typedef struct
{
  __IO    uint32_t  ISR;              /*!< LPTIM Interrupt and Status register,         Address offset:0x00 */
  __IO    uint32_t  ICR;              /*!< LPTIM Interrupt Clear register,              Address offset:0x04 */
  __IO    uint32_t  IER;              /*!< LPTIM Interrupt Enable register,             Address offset:0x08 */
  __IO    uint32_t  CFGR;             /*!< LPTIM Configuration register,                Address offset:0x0C */
  __IO    uint32_t  CR;               /*!< LPTIM Control register,                      Address offset:0x10 */
  __IO    uint32_t  CMP;              /*!< LPTIM Compare register,                      Address offset:0x14 */
  __IO    uint32_t  ARR;              /*!< LPTIM Autoreload register,                   Address offset:0x18 */
  __IO    uint32_t  CNT;              /*!< LPTIM Counter register,                      Address offset:0x1C */
  __IO    uint32_t  RESERVED;         /*!< Reserved,                                    Address offset:0x20 */
  __IO    uint32_t  CFGR2;            /*!< LPTIM Configuration register 2,              Address offset:0x24 */
}LPTIM_TypeDef;

/**
  * @brief System configuration controller
  */

typedef struct
{
  __IO    uint32_t  CFGR;             /*!< SYSCFG Configuration register,               Address offset:0x00 */
  __IO    uint32_t  FLASH_VREF_TRIM;  /*!< SYSCFG Flash Voltage Reference Triming       Address offset:0x04 */
}SYSCFG_TypeDef;

/**
  * @brief Debug Support
  */

typedef struct
{
  __IO    uint32_t  IDCODE;           /*!< DBG Device ID Code register,                 Address offset:0x00 */
  __IO    uint32_t  APB_FZ;           /*!< DBG APB Freeze register,                     Address offset:0x04 */
}DBG_TypeDef;

/**
  * @brief Power Control
  */

typedef struct
{
  __IO    uint32_t  CR;               /*!<PWR Control register,                         Address offset:0x00 */
  __IO    uint32_t  SR;               /*!<PWR Status register,                          Address offset:0x04 */
}PWR_TypeDef;

#define FLASH_BASE            ((uint32_t)0x08000000) /*!< FLASH base address in the alias region */
#define SRAM_BASE             ((uint32_t)0x20000000) /*!< SRAM base address in the alias region */
#define PERIPH_BASE           ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region */

/*!< Peripheral memory map */
#define APBPERIPH_BASE        PERIPH_BASE
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000)
#define IOPORT_BASE           ((uint32_t)0x50000000) /*!< IOPORT base address for FGPIO */

/*!< APB peripherals */
#define ADC_BASE              (APBPERIPH_BASE + 0x00000000) /*!< ADC base address */
#define ANA_CTRL_BASE         (APBPERIPH_BASE + 0x00000400) /*!< Analog (COMP+DAC+OPAMP) base address */
#define SYSCFG_BASE           (APBPERIPH_BASE + 0x00000800) /*!< SYSCFG base address */
#define DBG_BASE              (APBPERIPH_BASE + 0x00000900) /*!< DBG base address */
#define PWR_BASE              (APBPERIPH_BASE + 0x00000A00) /*!< PWR base address */
#define EXTI_BASE             (APBPERIPH_BASE + 0x00000C00) /*!< EXTI base address */
#define USART1_BASE           (APBPERIPH_BASE + 0x00001000) /*!< USART1 base address */
#define USART2_BASE           (APBPERIPH_BASE + 0x00001400) /*!< USART2 base address */
#define I2C1_BASE             (APBPERIPH_BASE + 0x00001800) /*!< I2C1 base address */
#define SPI1_BASE             (APBPERIPH_BASE + 0x00001C00) /*!< SPI1 base address */
#define TIM1_BASE             (APBPERIPH_BASE + 0x00002000) /*!< TIM1 base address */
#define TIM2_BASE             (APBPERIPH_BASE + 0x00002400) /*!< TIM2 base address */
#define TIM14_BASE            (APBPERIPH_BASE + 0x00002C00) /*!< TIM14 base address */
#define TIM6_BASE             (APBPERIPH_BASE + 0x00003400) /*!< TIM6 base address */
#define TIM7_BASE             (APBPERIPH_BASE + 0x00003800) /*!< TIM7 base address */
#define LPTIM_BASE            (APBPERIPH_BASE + 0x00003C00) /*!< LPTIM base address */
#define RTC_BASE              (APBPERIPH_BASE + 0x00004000) /*!< RTC base address */
#define WWDG_BASE             (APBPERIPH_BASE + 0x00004400) /*!< WWDG base address */
#define IWDG_BASE             (APBPERIPH_BASE + 0x00004800) /*!< IWDG base address */

/*!< AHB peripherals */
#define DMA_BASE              (AHBPERIPH_BASE + 0x00000000) /*!< DMA base address */
#define DMA_Channel1_BASE     (DMA_BASE       + 0x00000010) /*!< DMA Channel1 base address */
#define DMA_Channel2_BASE     (DMA_BASE       + 0x00000020) /*!< DMA Channel2 base address */
#define DMA_Channel3_BASE     (DMA_BASE       + 0x00000030) /*!< DMA Channel3 base address */
#define DMA_Channel4_BASE     (DMA_BASE       + 0x00000040) /*!< DMA Channel4 base address */
#define DMA_Channel5_BASE     (DMA_BASE       + 0x00000050) /*!< DMA Channel5 base address */
#define DMA_Channel6_BASE     (DMA_BASE       + 0x00000060) /*!< DMA Channel6 base address */
#define DMA_Channel7_BASE     (DMA_BASE       + 0x00000070) /*!< DMA Channel7 base address */
#define DMA_Channel8_BASE     (DMA_BASE       + 0x00000080) /*!< DMA Channel8 base address */
#define RCC_BASE              (AHBPERIPH_BASE + 0x00000400) /*!< RCC base address */
#define FLASH_CTRL_BASE       (AHBPERIPH_BASE + 0x00000800) /*!< Flash Controller base address */
#define CRC_BASE              (AHBPERIPH_BASE + 0x00000C00) /*!< CRC base address */
#define CORDIC_BASE           (AHBPERIPH_BASE + 0x00001000) /*!< Cordic base address */
#define GPIO_BASE             (AHBPERIPH_BASE + 0x00002000) /*!< GPIO base address */

#define GPIOA_BASE             (AHBPERIPH_BASE + 0x00002000) /*!< GPIO base address */
#define GPIOB_BASE             (AHBPERIPH_BASE + 0x00002100) /*!< GPIO base address */
#define GPIOC_BASE             (AHBPERIPH_BASE + 0x00002200) /*!< GPIO base address */
#define GPIOD_BASE             (AHBPERIPH_BASE + 0x00002300) /*!< GPIO base address */

/*!< IOPORT peripherals */
#define FGPIO_BASE            (IOPORT_BASE + 0x00000000)    /*!< FGPIO base address */

#define FGPIOA_BASE            (IOPORT_BASE + 0x00000000)    /*!< FGPIO base address */
#define FGPIOB_BASE            (IOPORT_BASE + 0x00000100)    /*!< FGPIO base address */
#define FGPIOC_BASE            (IOPORT_BASE + 0x00000200)    /*!< FGPIO base address */
#define FGPIOD_BASE            (IOPORT_BASE + 0x00000300)    /*!< FGPIO base address */

/**
  * @}
  */
  
/** @addtogroup Peripheral_declaration
  * @{
  */  


/* APB peripherals */
#define ADC                 ((ADC_TypeDef *) ADC_BASE)             /*!< ADC */
#define ANA_CTRL            ((ANA_CTRL_TypeDef *) ANA_CTRL_BASE)   /*!< Analog (COMP+DAC+OPAMP) */
#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)       /*!< SYSCFG */
#define DBG                 ((DBG_TypeDef *) DBG_BASE)             /*!< DBG */
#define PWR                 ((PWR_TypeDef *) PWR_BASE)             /*!< PWR */
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)           /*!< EXTI */
#define USART1              ((USART_TypeDef *) USART1_BASE)        /*!< USART1 */
#define USART2              ((USART_TypeDef *) USART2_BASE)        /*!< USART2 */
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)            /*!< I2C1 */
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)            /*!< SPI1 */
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)            /*!< TIM1 */
#define TIM2                ((TIM_TypeDef *) TIM2_BASE)            /*!< TIM2 */
#define TIM14               ((TIM_TypeDef *) TIM14_BASE)           /*!< TIM14 */
#define TIM6                ((TIM_TypeDef *) TIM6_BASE)            /*!< TIM6 */
#define TIM7                ((TIM_TypeDef *) TIM7_BASE)            /*!< TIM7 */
#define LPTIM               ((LPTIM_TypeDef *) LPTIM_BASE)         /*!< LPTIM */
#define RTC                 ((RTC_TypeDef *) RTC_BASE)             /*!< RTC */
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)           /*!< WWDG */
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)           /*!< IWDG */

/* AHB peripherals */
#define DMA                 ((DMA_TypeDef *) DMA_BASE)             /*!< DMA */
#define DMA_Channel1        ((DMA_Channel_TypeDef *) DMA_Channel1_BASE)
#define DMA_Channel2        ((DMA_Channel_TypeDef *) DMA_Channel2_BASE)
#define DMA_Channel3        ((DMA_Channel_TypeDef *) DMA_Channel3_BASE)
#define DMA_Channel4        ((DMA_Channel_TypeDef *) DMA_Channel4_BASE)
#define DMA_Channel5        ((DMA_Channel_TypeDef *) DMA_Channel5_BASE)
#define DMA_Channel6        ((DMA_Channel_TypeDef *) DMA_Channel6_BASE)
#define DMA_Channel7        ((DMA_Channel_TypeDef *) DMA_Channel7_BASE)
#define DMA_Channel8        ((DMA_Channel_TypeDef *) DMA_Channel8_BASE)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)             /*!< RCC */
#define FLASH               ((FLASH_TypeDef *) FLASH_CTRL_BASE)    /*!< Flash Controller */
#define CRC                 ((CRC_TypeDef *) CRC_BASE)             /*!< CRC */
#define CORDIC              ((CORDIC_TypeDef *) CORDIC_BASE)       /*!< Cordic */
#define GPIO                ((GPIO_TypeDef *) GPIO_BASE)           /*!< GPIO */

#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)           /*!< GPIO */
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)           /*!< GPIO */
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)           /*!< GPIO */
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)           /*!< GPIO */

/* IOPORT peripherals */
#define FGPIO               ((GPIO_TypeDef *) FGPIO_BASE)          /*!< FGPIO */

#define FGPIOA              ((GPIO_TypeDef *) FGPIOA_BASE)          /*!< FGPIO */
#define FGPIOB              ((GPIO_TypeDef *) FGPIOB_BASE)          /*!< FGPIO */
#define FGPIOC              ((GPIO_TypeDef *) FGPIOC_BASE)          /*!< FGPIO */
#define FGPIOD              ((GPIO_TypeDef *) FGPIOD_BASE)          /*!< FGPIO */

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
/*                      Analog to Digital Converter (ADC)                     */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for ADC_ISR register  ******************/
#define ADC_ISR_JCCRDY                       ((uint32_t)0x00000200)        /*!< Injected Channel Config Ready */
#define ADC_ISR_CCRDY                        ((uint32_t)0x00000100)        /*!< Channel Config Ready */
#define ADC_ISR_OVR                          ((uint32_t)0x00000080)        /*!< Overrun flag */
#define ADC_ISR_AWD                          ((uint32_t)0x00000040)        /*!< Analog Watchdog flag */
#define ADC_ISR_JEOS                         ((uint32_t)0x00000020)        /*!< Injected End of Sequence */
#define ADC_ISR_JEOC                         ((uint32_t)0x00000010)        /*!< Injected End of Conversion */
#define ADC_ISR_JEOSMP                       ((uint32_t)0x00000008)        /*!< Injected End of Sampling */
#define ADC_ISR_EOS                          ((uint32_t)0x00000004)        /*!< End of Sequence */
#define ADC_ISR_EOC                          ((uint32_t)0x00000002)        /*!< End of Conversion */
#define ADC_ISR_EOSMP                        ((uint32_t)0x00000001)        /*!< End of Sampling */

/********************  Bits definition for ADC_IER register  ******************/
#define ADC_IER_JCCRDYIE                     ((uint32_t)0x00000200)        /*!< Injected Config Ready Interrupt */
#define ADC_IER_CCRDYIE                      ((uint32_t)0x00000100)        /*!< Channel Config Ready Interrupt */
#define ADC_IER_OVRIE                        ((uint32_t)0x00000080)        /*!< Overrun Interrupt */
#define ADC_IER_AWDIE                        ((uint32_t)0x00000040)        /*!< Analog Watchdog Interrupt */
#define ADC_IER_JEOSIE                       ((uint32_t)0x00000020)        /*!< Injected Sequence End Interrupt */
#define ADC_IER_JEOCIE                       ((uint32_t)0x00000010)        /*!< Injected Conversion End Interrupt */
#define ADC_IER_JEOSMPIE                     ((uint32_t)0x00000008)        /*!< Injected Sampling End Interrupt */
#define ADC_IER_EOSIE                        ((uint32_t)0x00000004)        /*!< Sequence End Interrupt */
#define ADC_IER_EOCIE                        ((uint32_t)0x00000002)        /*!< Conversion End Interrupt */
#define ADC_IER_EOSMPIE                      ((uint32_t)0x00000001)        /*!< Sampling End Interrupt */

/********************  Bits definition for ADC_CR register  *******************/
#define ADC_CR_JADSTART                      ((uint32_t)0x00000010)        /*!< Injected Conversion Start */
#define ADC_CR_ADSTP                         ((uint32_t)0x00000008)        /*!< Conversion Stop */
#define ADC_CR_ADSTART                       ((uint32_t)0x00000004)        /*!< Conversion Start */
#define ADC_CR_ADDIS                         ((uint32_t)0x00000002)        /*!< ADC Disable */
#define ADC_CR_ADEN                          ((uint32_t)0x00000001)        /*!< ADC Enable */

/*******************  Bits definition for ADC_CFGR1 register  *****************/
#define ADC_CFGR1_JQDIS                      ((uint32_t)0x80000000)        /*!< Injected Queue Disable */
#define ADC_CFGR1_JAUTO                      ((uint32_t)0x40000000)        /*!< Auto-Injected Conversion */
#define ADC_CFGR1_JQM                        ((uint32_t)0x20000000)        /*!< Injected Queue Mode */
#define ADC_CFGR1_SQNUM                      ((uint32_t)0x0F000000)        /*!< Regular Sequence Length */
#define ADC_CFGR1_AWDEN                      ((uint32_t)0x00800000)        /*!< Analog Watchdog Enable */
#define ADC_CFGR1_DMSEL                      ((uint32_t)0x00180000)        /*!< Dummy DAC Connect Select */
#define ADC_CFGR1_FREQ                       ((uint32_t)0x00060000)        /*!< ADC_CLK clock frequency flag */
#define ADC_CFGR1_DISCEN                     ((uint32_t)0x00010000)        /*!< Discontinuous Mode */
#define ADC_CFGR1_WAIT                       ((uint32_t)0x00004000)        /*!< Wait Conversion Mode */
#define ADC_CFGR1_CONT                       ((uint32_t)0x00002000)        /*!< Continuous Mode */
#define ADC_CFGR1_EXTEN                      ((uint32_t)0x00000C00)        /*!< External Trigger Polarity */
#define ADC_CFGR1_EXTSEL                     ((uint32_t)0x000001C0)        /*!< External Trigger Source */
#define ADC_CFGR1_ALIGN                      ((uint32_t)0x00000020)        /*!< Data Alignment */
#define ADC_CFGR1_PW                         ((uint32_t)0x00000018)        /*!< Power Control */
#define ADC_CFGR1_DMAEN                      ((uint32_t)0x00000001)        /*!< DMA Enable */

/*******************  Bits definition for ADC_CFGR2 register  *****************/
#define ADC_CFGR2_CKMODE                     ((uint32_t)0xC0000000)        /*!< Clock Mode */
#define ADC_CFGR2_LFTRIG                     ((uint32_t)0x20000000)        /*!< Low-Frequency Trigger Mode */
#define ADC_CFGR2_SRNUM                      ((uint32_t)0x003E0000)        /*!< SRAM Rounds Number */
#define ADC_CFGR2_SREN                       ((uint32_t)0x00010000)        /*!< SRAM Enable */
#define ADC_CFGR2_TOVS                       ((uint32_t)0x00000200)        /*!< Triggered Oversampling */
#define ADC_CFGR2_OVSS                       ((uint32_t)0x000001E0)        /*!< Oversampling Shift */
#define ADC_CFGR2_OVSR                       ((uint32_t)0x0000001C)        /*!< Oversampling Ratio */
#define ADC_CFGR2_OVSE                       ((uint32_t)0x00000001)        /*!< Oversample Enable */

/******************  Bits definition for ADC_SMPR register  ********************/
#define ADC_SMPR_SMPSEL15                    ((uint32_t)0x00800000)        /*!< Channel 15 SMP select */
#define ADC_SMPR_SMPSEL14                    ((uint32_t)0x00400000)        /*!< Channel 14 SMP select */
#define ADC_SMPR_SMPSEL13                    ((uint32_t)0x00200000)        /*!< Channel 13 SMP select */
#define ADC_SMPR_SMPSEL12                    ((uint32_t)0x00100000)        /*!< Channel 12 SMP select */
#define ADC_SMPR_SMPSEL11                    ((uint32_t)0x00080000)        /*!< Channel 11 SMP select */
#define ADC_SMPR_SMPSEL10                    ((uint32_t)0x00040000)        /*!< Channel 10 SMP select */
#define ADC_SMPR_SMPSEL9                     ((uint32_t)0x00020000)        /*!< Channel 9 SMP select */
#define ADC_SMPR_SMPSEL8                     ((uint32_t)0x00010000)        /*!< Channel 8 SMP select */
#define ADC_SMPR_SMPSEL7                     ((uint32_t)0x00008000)        /*!< Channel 7 SMP select */
#define ADC_SMPR_SMPSEL6                     ((uint32_t)0x00004000)        /*!< Channel 6 SMP select */
#define ADC_SMPR_SMPSEL5                     ((uint32_t)0x00002000)        /*!< Channel 5 SMP select */
#define ADC_SMPR_SMPSEL4                     ((uint32_t)0x00001000)        /*!< Channel 4 SMP select */
#define ADC_SMPR_SMPSEL3                     ((uint32_t)0x00000800)        /*!< Channel 3 SMP select */
#define ADC_SMPR_SMPSEL2                     ((uint32_t)0x00000400)        /*!< Channel 2 SMP select */
#define ADC_SMPR_SMPSEL1                     ((uint32_t)0x00000200)        /*!< Channel 1 SMP select */
#define ADC_SMPR_SMPSEL0                     ((uint32_t)0x00000100)        /*!< Channel 0 SMP select */
#define ADC_SMPR_SMP2                        ((uint32_t)0x000000F0)        /*!< Sampling Time 2 */
#define ADC_SMPR_SMP1                        ((uint32_t)0x0000000F)        /*!< Sampling Time 1 */

/*******************  Bits definition for ADC_AWDTR register  *****************/
#define ADC_AWDTR_HT                         ((uint32_t)0x0FFF0000)        /*!< High Threshold */
#define ADC_AWDTR_LT                         ((uint32_t)0x00000FFF)        /*!< Low Threshold */

/*******************  Bits definition for ADC_AWDCR register  *****************/
#define ADC_AWDCR_AWDCH                      ((uint32_t)0x0000FFFF)        /*!< Analog Watchdog Channels */

/******************  Bits definition for ADC_CHSELR1 register  ****************/
#define ADC_CHSELR1_SQ1                      ((uint32_t)0x0000000F)        /*!< 1st Conversion in Sequence */
#define ADC_CHSELR1_SQ2                      ((uint32_t)0x000000F0)        /*!< 2nd Conversion in Sequence */
#define ADC_CHSELR1_SQ3                      ((uint32_t)0x00000F00)        /*!< 3rd Conversion in Sequence */
#define ADC_CHSELR1_SQ4                      ((uint32_t)0x0000F000)        /*!< 4th Conversion in Sequence */
#define ADC_CHSELR1_SQ5                      ((uint32_t)0x000F0000)        /*!< 5th Conversion in Sequence */
#define ADC_CHSELR1_SQ6                      ((uint32_t)0x00F00000)        /*!< 6th Conversion in Sequence */
#define ADC_CHSELR1_SQ7                      ((uint32_t)0x0F000000)        /*!< 7th Conversion in Sequence */
#define ADC_CHSELR1_SQ8                      ((uint32_t)0xF0000000)        /*!< 8th Conversion in Sequence */

/******************  Bits definition for ADC_CHSELR2 register  ****************/
#define ADC_CHSELR2_SQ9                      ((uint32_t)0x0000000F)        /*!< 9th Conversion in Sequence */
#define ADC_CHSELR1_SQ10                     ((uint32_t)0x000000F0)        /*!< 10th Conversion in Sequence */
#define ADC_CHSELR1_SQ11                     ((uint32_t)0x00000F00)        /*!< 11th Conversion in Sequence */
#define ADC_CHSELR1_SQ12                     ((uint32_t)0x0000F000)        /*!< 12th Conversion in Sequence */
#define ADC_CHSELR1_SQ13                     ((uint32_t)0x000F0000)        /*!< 13th Conversion in Sequence */
#define ADC_CHSELR1_SQ14                     ((uint32_t)0x00F00000)        /*!< 14th Conversion in Sequence */
#define ADC_CHSELR1_SQ15                     ((uint32_t)0x0F000000)        /*!< 15th Conversion in Sequence */
#define ADC_CHSELR1_SQ16                     ((uint32_t)0xF0000000)        /*!< 16th Conversion in Sequence */

/******************  Bits definition for ADC_JSQR register  *******************/
#define ADC_JSQR_JSQ4                        ((uint32_t)0x00F00000)        /*!< 4th Injected Conversion */
#define ADC_JSQR_JSQ3                        ((uint32_t)0x000F0000)        /*!< 3rd Injected Conversion */
#define ADC_JSQR_JSQ2                        ((uint32_t)0x0000F000)        /*!< 2nd Injected Conversion */
#define ADC_JSQR_JSQ1                        ((uint32_t)0x00000F00)        /*!< 1st Injected Conversion */
#define ADC_JSQR_JEXTSEL                     ((uint32_t)0x00000060)        /*!< Injected External Trigger Source */
#define ADC_JSQR_JEXTEN                      ((uint32_t)0x0000001C)        /*!< Injected Trigger Polarity */
#define ADC_JSQR_JNUM                        ((uint32_t)0x00000003)        /*!< Injected Sequence Length */

/********************  Bits definition for ADC_CCR register  *******************/
#define ADC_CCR_TSEN                         ((uint32_t)0x00800000)        /*!< Temperature Sensor Enable */
#define ADC_CCR_VREFEN                       ((uint32_t)0x00400000)        /*!< Internal Reference Enable */
#define ADC_CCR_PRESC                        ((uint32_t)0x003C0000)        /*!< ADC Prescaler */

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
/*                      Analog Comparators (COMP)                             */
/*                                                                            */
/******************************************************************************/
/***********************  Bit definition for COMP_CSR register  ***************/
/********************  Bits definition for COMP1_CSR register  ******************/
#define COMP1_CSR_LOCK                        ((uint32_t)0x80000000)        /*!< COMP1 register lock */
#define COMP1_CSR_VALUE                       ((uint32_t)0x40000000)        /*!< COMP1 output status */
#define COMP1_CSR_BLANKSEL                    ((uint32_t)0x001C0000)        /*!< COMP1 blanking source selector */
#define COMP1_CSR_PWRMODE                     ((uint32_t)0x00020000)        /*!< COMP1 power mode selector */
#define COMP1_CSR_HYST                        ((uint32_t)0x00010000)        /*!< COMP1 hysteresis selector */
#define COMP1_CSR_POLARITY                    ((uint32_t)0x00008000)        /*!< COMP1 output polarity */
#define COMP1_CSR_WINOUT                      ((uint32_t)0x00004000)        /*!< COMP1 window XOR output */
#define COMP1_CSR_INPSEL                      ((uint32_t)0x00000300)        /*!< COMP1 non-inverting input select */
#define COMP1_CSR_INNSEL                      ((uint32_t)0x000000C0)        /*!< COMP1 inverting input select */
#define COMP1_CSR_EN                          ((uint32_t)0x00000001)        /*!< COMP1 enable */

/********************  Bits definition for COMP2_CSR register  ******************/
#define COMP2_CSR_LOCK                        ((uint32_t)0x80000000)        /*!< COMP2 register lock */
#define COMP2_CSR_VALUE                       ((uint32_t)0x40000000)        /*!< COMP2 output status */
#define COMP2_CSR_BLANKSEL                    ((uint32_t)0x001C0000)        /*!< COMP2 blanking source selector */
#define COMP2_CSR_PWRMODE                     ((uint32_t)0x00020000)        /*!< COMP2 power mode selector */
#define COMP2_CSR_HYST                        ((uint32_t)0x00010000)        /*!< COMP2 hysteresis selector */
#define COMP2_CSR_POLARITY                    ((uint32_t)0x00008000)        /*!< COMP2 output polarity */
#define COMP2_CSR_WINOUT                      ((uint32_t)0x00004000)        /*!< COMP2 window XOR output */
#define COMP2_CSR_WINMODE                     ((uint32_t)0x00000800)        /*!< COMP2 window mode selector */
#define COMP2_CSR_INPSEL                      ((uint32_t)0x00000300)        /*!< COMP2 non-inverting input select */
#define COMP2_CSR_INNSEL                      ((uint32_t)0x000000C0)        /*!< COMP2 inverting input select */
#define COMP2_CSR_EN                          ((uint32_t)0x00000001)        /*!< COMP2 enable */

/********************  Bits definition for COMP_VCR register  *******************/
#define COMP_VCR_VCRSVIN                      ((uint32_t)0x00000010)        /*!< VREFINT source select */
#define COMP_VCR_VCREN                        ((uint32_t)0x00000008)        /*!< VREFINT enable */
#define COMP_VCR_VCRDIV                       ((uint32_t)0x00000007)        /*!< VREFINT divider select */

/********************  Bits definition for COMP1_POLL register  *****************/
#define COMP1_POLL_POUT                       ((uint32_t)0x00000F00)        /*!< Polling outputs */
#define COMP1_POLL_PERIOD                     ((uint32_t)0x000000F0)        /*!< Polling period */
#define COMP1_POLL_FIXIN                      ((uint32_t)0x00000004)        /*!< Inverting input fixed mode */
#define COMP1_POLL_POLLCH                     ((uint32_t)0x00000003)        /*!< Polling channel select */

/********************  Bits definition for COMP2_POLL register  *****************/
#define COMP2_POLL_POUT                       ((uint32_t)0x00000F00)        /*!< Polling outputs */
#define COMP2_POLL_PERIOD                     ((uint32_t)0x000000F0)        /*!< Polling period */
#define COMP2_POLL_FIXIN                      ((uint32_t)0x00000004)        /*!< Inverting input fixed mode */
#define COMP2_POLL_POLLCH                     ((uint32_t)0x00000003)        /*!< Polling channel select */

/********************  Bits definition for DAC_CR register  ******************/
#define DAC_CR_SEL                           ((uint32_t)0x00000002)        /*!< DAC type selection */
#define DAC_CR_EN                            ((uint32_t)0x00000001)        /*!< DAC channel enable */

/********************  Bits definition for DAC_DHR12R register  *************/
#define DAC_DHR12R_DACCDHR                   ((uint32_t)0x00000FFF)        /*!< 12-bit right-aligned data */

/********************  Bits definition for DAC_DHR12L register  *************/
#define DAC_DHR12L_DACCDHR                   ((uint32_t)0x0000FFF0)        /*!< 12-bit left-aligned data */

/********************  Bits definition for OPAMPx_CSR register  ************/
#define OPAMPx_CSR_LOCK                     ((uint32_t)0x80000000)        /*!< Register lock */
#define OPAMPx_CSR_TRIMOFFSETN              ((uint32_t)0x00070000)        /*!< NMOS trim offset */
#define OPAMPx_CSR_TRIMOFFSETP              ((uint32_t)0x0000E000)        /*!< PMOS trim offset */
#define OPAMPx_CSR_PGA_GAIN                 ((uint32_t)0x00001F00)        /*!< Programmable gain amplifier value */
#define OPAMPx_CSR_OPAINTOEN                ((uint32_t)0x00000080)        /*!< Internal output enable */
#define OPAMPx_CSR_OPA_PW                   ((uint32_t)0x00000060)        /*!< Power consumption mode */
#define OPAMPx_CSR_VM_SEL                   ((uint32_t)0x00000018)        /*!< Inverting input selection */
#define OPAMPx_CSR_VP_SEL                   ((uint32_t)0x00000006)        /*!< Non-inverting input selection */
#define OPAMPx_CSR_OPAEN                    ((uint32_t)0x00000001)        /*!< Operational amplifier enable */

/********************  Bits definition for OPAMPx_TCMR register  ***********/
#define OPAMPx_TCMR_LOCK                    ((uint32_t)0x80000000)        /*!< Register lock */
#define OPAMPx_TCMR_T20CM_EN                ((uint32_t)0x00000020)        /*!< TIM20 trigger enable */
#define OPAMPx_TCMR_T8CM_EN                 ((uint32_t)0x00000010)        /*!< TIM8 trigger enable */
#define OPAMPx_TCMR_T1CM_EN                 ((uint32_t)0x00000008)        /*!< TIM1 trigger enable */
#define OPAMPx_TCMR_VPS_SEL                 ((uint32_t)0x00000006)        /*!< Non-inverting secondary input selection */
#define OPAMPx_TCMR_VMS_SEL                 ((uint32_t)0x00000001)        /*!< Inverting secondary input selection */

/******************************************************************************/
/*                                                                            */
/*                      Independent Watchdog (IWDG)                           */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for IWDG_KR register  ******************/
#define IWDG_KR_KEY                          ((uint32_t)0x0000FFFF)        /*!< Key Value */

/********************  Bits definition for IWDG_PR register  ******************/
#define IWDG_PR_PR                           ((uint32_t)0x00000007)        /*!< Prescaler Divider */

/*******************  Bits definition for IWDG_RLR register  ******************/
#define IWDG_RLR_RL                          ((uint32_t)0x00000FFF)        /*!< Watchdog Counter Reload Value */

/********************  Bits definition for IWDG_SR register  ******************/
#define IWDG_SR_PAUSE                        ((uint32_t)0x00000020)        /*!< IWDG Pause Control In Deepsleep Mode */
#define IWDG_SR_IREN                         ((uint32_t)0x00000010)        /*!< IWDG Interrupt Enable */
#define IWDG_SR_IR                           ((uint32_t)0x00000008)        /*!< IWDG Interrupt Flag */

/*******************  Bits definition for IWDG_WINR register  *****************/
#define IWDG_WINR_WIN                        ((uint32_t)0x00000FFF)        /*!< Watchdog Counter Window Value */

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
/*                            Low-power Timer (LPTIM)                         */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for LPTIM_ISR register  ********************/
#define LPTIM_ISR_CMPM                          ((uint32_t)0x00000001)         /*!< Compare match                                   */
#define LPTIM_ISR_ARRM                          ((uint32_t)0x00000002)         /*!< Autoreload match                                */
#define LPTIM_ISR_EXTTRIG                       ((uint32_t)0x00000004)         /*!< External trigger edge event                     */
#define LPTIM_ISR_CMPOK                         ((uint32_t)0x00000008)         /*!< Compare register update OK                      */
#define LPTIM_ISR_ARROK                         ((uint32_t)0x00000010)         /*!< Autoreload register update OK                   */
#define LPTIM_ISR_UP                            ((uint32_t)0x00000020)         /*!< Counter direction change DOWN to UP             */
#define LPTIM_ISR_DOWN                          ((uint32_t)0x00000040)         /*!< Counter direction change UP to DOWN             */

/*****************  Bit definition for LPTIM_ICR register  ********************/
#define LPTIM_ICR_CMPMCF                        ((uint32_t)0x00000001)         /*!< Compare match clear flag                        */
#define LPTIM_ICR_ARRMCF                        ((uint32_t)0x00000002)         /*!< Autoreload match clear flag                     */
#define LPTIM_ICR_EXTTRIGCF                     ((uint32_t)0x00000004)         /*!< External trigger valid edge clear flag          */
#define LPTIM_ICR_CMPOKCF                       ((uint32_t)0x00000008)         /*!< Compare register update OK clear flag           */
#define LPTIM_ICR_ARROKCF                       ((uint32_t)0x00000010)         /*!< Autoreload register update OK clear flag        */
#define LPTIM_ICR_UPCF                          ((uint32_t)0x00000020)         /*!< Direction change to UP clear flag               */
#define LPTIM_ICR_DOWNCF                        ((uint32_t)0x00000040)         /*!< Direction change to DOWN clear flag             */       

/*****************  Bit definition for LPTIM_IER register  ********************/
#define LPTIM_IER_CMPMIE                        ((uint32_t)0x00000001)         /*!< Compare match Interrupt Enable                  */                   
#define LPTIM_IER_ARRMIE                        ((uint32_t)0x00000002)         /*!< Autoreload match Interrupt Enable               */                
#define LPTIM_IER_EXTTRIGIE                     ((uint32_t)0x00000004)         /*!< External trigger valid edge Interrupt Enable    */     
#define LPTIM_IER_CMPOKIE                       ((uint32_t)0x00000008)         /*!< Compare register update OK Interrupt Enable     */      
#define LPTIM_IER_ARROKIE                       ((uint32_t)0x00000010)         /*!< Autoreload register update OK Interrupt Enable  */   
#define LPTIM_IER_UPIE                          ((uint32_t)0x00000020)         /*!< Direction change to UP Interrupt Enable         */          
#define LPTIM_IER_DOWNIE                        ((uint32_t)0x00000040)         /*!< Direction change to DOWN Interrupt Enable       */        

/****************  Bit definition for LPTIM_CFGR register  ********************/
#define LPTIM_CFGR_CKSEL                        ((uint32_t)0x00000001)         /*!< Clock selector                                  */
#define LPTIM_CFGR_CKPOL                        ((uint32_t)0x00000006)         /*!< Clock Polarity                                  */
#define LPTIM_CFGR_CKFLT                        ((uint32_t)0x00000018)         /*!< Configurable digital filter for external clock  */
#define LPTIM_CFGR_TRGFLT                       ((uint32_t)0x000000C0)         /*!< Configurable digital filter for trigger         */
#define LPTIM_CFGR_PRESC                        ((uint32_t)0x00000C00)         /*!< Clock prescaler                                 */
#define LPTIM_CFGR_TRIGSEL                      ((uint32_t)0x0000E000)         /*!< Trigger selector                                */
#define LPTIM_CFGR_TRIGEN                       ((uint32_t)0x00060000)         /*!< Trigger enable and polarity                     */
#define LPTIM_CFGR_TIMOUT                       ((uint32_t)0x00080000)         /*!< Timeout enable                                  */
#define LPTIM_CFGR_WAVE                         ((uint32_t)0x00100000)         /*!< Waveform shape                                  */
#define LPTIM_CFGR_WAVPOL                       ((uint32_t)0x00200000)         /*!< Waveform shape polarity                         */
#define LPTIM_CFGR_PRELOAD                      ((uint32_t)0x00400000)         /*!< Registers update mode                           */
#define LPTIM_CFGR_COUNTMODE                    ((uint32_t)0x00800000)         /*!< Counter mode enabled                            */
#define LPTIM_CFGR_ENC                          ((uint32_t)0x01000000)         /*!< Encoder mode enable                             */

/*****************  Bit definition for LPTIM_CR register  *********************/
#define LPTIM_CR_ENABLE                         ((uint32_t)0x00000001)         /*!< LPTIM enable                                    */
#define LPTIM_CR_SNGSTRT                        ((uint32_t)0x00000002)         /*!< LPTIM start in Single mode                      */
#define LPTIM_CR_CNTSTRT                        ((uint32_t)0x00000004)         /*!< Timer start in Continuous mode                  */
#define LPTIM_CR_COUNTRST                       ((uint32_t)0x00000008)         /*!< Counter reset                                   */

/*****************  Bit definition for LPTIM_CMP register  ********************/
#define LPTIM_CMP_CMP                           ((uint32_t)0x0000FFFF)         /*!< Compare value                                   */

/*****************  Bit definition for LPTIM_ARR register  ********************/
#define LPTIM_ARR_ARR                           ((uint32_t)0x0000FFFF)         /*!< Auto reload value                               */

/*****************  Bit definition for LPTIM_CNT register  ********************/
#define LPTIM_CNT_CNT                           ((uint32_t)0x0000FFFF)         /*!< Counter value                                   */

/*****************  Bit definition for LPTIM_CFGR2 register  ******************/
#define LPTIM_CFGR2_IN1SEL                      ((uint32_t)0x00000003)         /*!< LPTIM input 1 selection                         */
#define LPTIM_CFGR2_IN2SEL                      ((uint32_t)0x00000030)         /*!< LPTIM input 2 selection                         */

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
#define  CR_RST                              ((uint32_t)0x00000001)            /*!< CRC reset                */
#define  CR_RI                               ((uint32_t)0x00000002)            /*!< Reverse input            */
#define  CR_BEI                              ((uint32_t)0x00000010)            /*!< Big endian input         */
#define  CR_BEO                              ((uint32_t)0x00000020)            /*!< Big endian output        */
#define  CR_RO                               ((uint32_t)0x00000040)            /*!< Reverse output           */
#define  CR_RVB                              ((uint32_t)0x00000080)            /*!< Reverse CRC write data   */

/******************************************************************************/
/*                                                                            */
/*                      CORDIC calculation unit (CORDIC)                      */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for CORDIC_CSR register  *****************/
#define  CORDIC_CSR_RRDY                        ((uint32_t)0x80000000)         /*!< Result Ready Flag        */
#define  CORDIC_CSR_ARGSIZE                     ((uint32_t)0x00400000)         /*!< Input Argument Size      */
#define  CORDIC_CSR_RESSIZE                     ((uint32_t)0x00200000)         /*!< Output Result Size       */
#define  CORDIC_CSR_NARGS                       ((uint32_t)0x00100000)         /*!< Num of Arguments         */
#define  CORDIC_CSR_NRES                        ((uint32_t)0x00080000)         /*!< Num of Results           */
#define  CORDIC_CSR_DMAWEN                      ((uint32_t)0x00040000)         /*!< DMA Write Enable         */
#define  CORDIC_CSR_DMAREN                      ((uint32_t)0x00020000)         /*!< DMA Read Enable          */
#define  CORDIC_CSR_IEN                         ((uint32_t)0x00010000)         /*!< Interrupt Enable         */
#define  CORDIC_CSR_SCALE                       ((uint32_t)0x00000700)         /*!< Scaling Factor           */
#define  CORDIC_CSR_PRECISION                   ((uint32_t)0x000000F0)         /*!< Precision of Iteration   */
#define  CORDIC_CSR_FUNC                        ((uint32_t)0x0000000F)         /*!< Function Select          */

/*******************  Bit definition for CORDIC_ARG register  *****************/
#define  CORDIC_ARG_ARG                         ((uint32_t)0xFFFFFFFF)         /*!< Input Argument           */

/*******************  Bit definition for CORDIC_RES register  *****************/
#define  CORDIC_RES_RES                         ((uint32_t)0xFFFFFFFF)         /*!< Output Result            */

/******************************************************************************/
/*                                                                            */
/*                    Digital to Analog Converter (DAC)                       */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DAC_CR register  ********************/

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
/*                          Real Time Clock (RTC)                             */
/*                                                                            */
/******************************************************************************/

/****************** Bit definition for RTC_TR register ************************/
#define  RTC_TR_PM                              ((uint32_t)0x00400000)         /*!< Time: 0:AM/24h 1:PM             */
#define  RTC_TR_HT                              ((uint32_t)0x00300000)         /*!< Time: Hour Tens (BCD)           */
#define  RTC_TR_HU                              ((uint32_t)0x000F0000)         /*!< Time: Hour Units (BCD)          */
#define  RTC_TR_MNT                             ((uint32_t)0x00007000)         /*!< Time: Minute Tens (BCD)         */
#define  RTC_TR_MNU                             ((uint32_t)0x00000F00)         /*!< Time: Minute Units (BCD)        */
#define  RTC_TR_ST                              ((uint32_t)0x00000070)         /*!< Time: Second Tens (BCD)         */
#define  RTC_TR_SU                              ((uint32_t)0x0000000F)         /*!< Time: Second Units (BCD)        */

/****************** Bit definition for RTC_DR register ************************/
#define  RTC_DR_YT                              ((uint32_t)0x00F00000)         /*!< Date: Year Tens (BCD)           */
#define  RTC_DR_YU                              ((uint32_t)0x000F0000)         /*!< Date: Year Units (BCD)          */
#define  RTC_DR_WDU                             ((uint32_t)0x0000E000)         /*!< Date: Weekday (BCD)             */
#define  RTC_DR_MT                              ((uint32_t)0x00001000)         /*!< Date: Month Tens (BCD)          */
#define  RTC_DR_MU                              ((uint32_t)0x00000F00)         /*!< Date: Month Units (BCD)         */
#define  RTC_DR_DT                              ((uint32_t)0x00000030)         /*!< Date: Day Tens (BCD)            */
#define  RTC_DR_DU                              ((uint32_t)0x0000000F)         /*!< Date: Day Units (BCD)           */

/****************** Bit definition for RTC_SSR register ***********************/
#define  RTC_SSR_SS                             ((uint32_t)0x0000FFFF)         /*!< Subsecond (binary)              */

/****************** Bit definition for RTC_ICSR register **********************/
#define  RTC_ICSR_CRPF                          ((uint32_t)0x00020000)         /*!< Control Register Pending Flag   */
#define  RTC_ICSR_RECALPF                       ((uint32_t)0x00010000)         /*!< Recalibration Pending Flag      */
#define  RTC_ICSR_INIT                          ((uint32_t)0x00000080)         /*!< Initialization Mode             */
#define  RTC_ICSR_INITF                         ((uint32_t)0x00000040)         /*!< Initialization Flag             */
#define  RTC_ICSR_RSF                           ((uint32_t)0x00000020)         /*!< Register Sync Flag              */
#define  RTC_ICSR_INITS                         ((uint32_t)0x00000010)         /*!< Initialization Status           */
#define  RTC_ICSR_SHPF                          ((uint32_t)0x00000008)         /*!< Shift Operation Pending Flag    */
#define  RTC_ICSR_WUTWF                         ((uint32_t)0x00000004)         /*!< Wakeup Timer Write Flag         */
#define  RTC_ICSR_ALRBWF                        ((uint32_t)0x00000002)         /*!< Alarm B Write Flag              */
#define  RTC_ICSR_ALRAWF                        ((uint32_t)0x00000001)         /*!< Alarm A Write Flag              */

/****************** Bit definition for RTC_PRER register **********************/
#define  RTC_PRER_PREDIV_A                      ((uint32_t)0x007F0000)         /*!< Async Prescaler Factor          */
#define  RTC_PRER_PREDIV_S                      ((uint32_t)0x00007FFF)         /*!< Sync Prescaler Factor           */

/****************** Bit definition for RTC_WUTR register **********************/
#define  RTC_WUTR_WUT                           ((uint32_t)0x0000FFFF)         /*!< Wakeup Timer Reload Value       */

/****************** Bit definition for RTC_ICSR register **********************/
#define  RTC_CR_COE                             ((uint32_t)0x00800000)         /*!< Calibration Output Enable       */
#define  RTC_CR_OSEL                            ((uint32_t)0x00600000)         /*!< Output Selection                */
#define  RTC_CR_POL                             ((uint32_t)0x00100000)         /*!< Output Polarity                 */
#define  RTC_CR_COSEL                           ((uint32_t)0x00080000)         /*!< Calibration Output Selection    */
#define  RTC_CR_TSIE                            ((uint32_t)0x00008000)         /*!< Timestamp Interrupt Enable      */
#define  RTC_CR_WUTIE                           ((uint32_t)0x00004000)         /*!< Wakeup timer Interrupt Enable   */
#define  RTC_CR_ALRBIE                          ((uint32_t)0x00002000)         /*!< Alarm B Interrupt Enable        */
#define  RTC_CR_ALRAIE                          ((uint32_t)0x00001000)         /*!< Alarm A Interrupt Enable        */
#define  RTC_CR_TSE                             ((uint32_t)0x00000800)         /*!< Timestamp Enable                */
#define  RTC_CR_WUTE                            ((uint32_t)0x00000400)         /*!< Wakeup timer Enable             */
#define  RTC_CR_ALRBE                           ((uint32_t)0x00000200)         /*!< Alarm B Enable                  */
#define  RTC_CR_ALRAE                           ((uint32_t)0x00000100)         /*!< Alarm A Enable                  */
#define  RTC_CR_FMT                             ((uint32_t)0x00000040)         /*!< Hour Format: 0:24h 1:AM/PM      */
#define  RTC_CR_BYPSHAD                         ((uint32_t)0x00000020)         /*!< Bypass Shadow Register          */
#define  RTC_CR_REFCKON                         ((uint32_t)0x00000010)         /*!< Reference Clock Enable          */
#define  RTC_CR_TSEDGE                          ((uint32_t)0x00000008)         /*!< Timestamp Active Edge           */
#define  RTC_CR_WUCKSEL                         ((uint32_t)0x00000007)         /*!< Wakeup Timer Clock Selection    */

/****************** Bit definition for RTC_WPR register ***********************/
#define  RTC_WPR_KEY                            ((uint32_t)0x000000FF)         /*!< Write Protection Key            */

/****************** Bit definition for RTC_CALR register **********************/
#define  RTC_CALR_CALP                          ((uint32_t)0x00008000)         /*!< Calibration Plus                */
#define  RTC_CALR_CALM                          ((uint32_t)0x000001FF)         /*!< Calibration Minus               */

/****************** Bit definition for RTC_SHIFTR register ********************/
#define  RTC_SHIFTR_ADD1S                       ((uint32_t)0x80000000)         /*!< Shift: add 1 second             */
#define  RTC_SHIFTR_SUBFS                       ((uint32_t)0x00007FFF)         /*!< Shift: subtract subseconds      */

/****************** Bit definition for RTC_TSTR register **********************/
#define  RTC_TSTR_PM                            ((uint32_t)0x00400000)         /*!< Timestamp AM/PM                 */
#define  RTC_TSTR_HT                            ((uint32_t)0x00300000)         /*!< Timestamp Hour Tens (BCD)       */
#define  RTC_TSTR_HU                            ((uint32_t)0x000F0000)         /*!< Timestamp Hour Units (BCD)      */
#define  RTC_TSTR_MNT                           ((uint32_t)0x00007000)         /*!< Timestamp Minute Tens (BCD)     */
#define  RTC_TSTR_MNU                           ((uint32_t)0x00000F00)         /*!< Timestamp Minute Units (BCD)    */
#define  RTC_TSTR_ST                            ((uint32_t)0x00000070)         /*!< Timestamp Second Tens (BCD)     */
#define  RTC_TSTR_SU                            ((uint32_t)0x0000000F)         /*!< Timestamp Second Units (BCD)    */

/****************** Bit definition for RTC_TSDR register **********************/
#define  RTC_TSDR_WDU                           ((uint32_t)0x0000E000)         /*!< Timestamp Weekday (BCD)         */
#define  RTC_TSDR_MT                            ((uint32_t)0x00001000)         /*!< Timestamp Month Tens (BCD)      */
#define  RTC_TSDR_MU                            ((uint32_t)0x00000F00)         /*!< Timestamp Month Units (BCD)     */
#define  RTC_TSDR_DT                            ((uint32_t)0x00000030)         /*!< Timestamp Day Tens (BCD)        */
#define  RTC_TSDR_DU                            ((uint32_t)0x0000000F)         /*!< Timestamp Day Units (BCD)       */

/****************** Bit definition for RTC_TSSSR register *********************/
#define  RTC_TSSSR_SS                           ((uint32_t)0x0000FFFF)         /*!< Timestamp Subsecond (binary)    */

/****************** Bit definition for RTC_ALRMAR register ********************/
#define  RTC_ALRMAR_MSK4                        ((uint32_t)0x80000000)         /*!< Alarm A: Date Mask              */
#define  RTC_ALRMAR_WDSEL                       ((uint32_t)0x40000000)         /*!< Alarm A: Weekday Selection      */
#define  RTC_ALRMAR_DT                          ((uint32_t)0x30000000)         /*!< Alarm A: Day Tens (BCD)         */
#define  RTC_ALRMAR_DU                          ((uint32_t)0x0F000000)         /*!< Alarm A: Day Units (BCD)        */
#define  RTC_ALRMAR_MSK3                        ((uint32_t)0x00800000)         /*!< Alarm A: Hour Mask              */
#define  RTC_ALRMAR_PM                          ((uint32_t)0x00400000)         /*!< Alarm A: AM/PM                  */
#define  RTC_ALRMAR_HT                          ((uint32_t)0x00300000)         /*!< Alarm A: Hour Tens (BCD)        */
#define  RTC_ALRMAR_HU                          ((uint32_t)0x000F0000)         /*!< Alarm A: Hour Units (BCD)       */
#define  RTC_ALRMAR_MSK2                        ((uint32_t)0x00008000)         /*!< Alarm A: Minute Mask            */
#define  RTC_ALRMAR_MNT                         ((uint32_t)0x00007000)         /*!< Alarm A: Minute Tens (BCD)      */
#define  RTC_ALRMAR_MNU                         ((uint32_t)0x00000F00)         /*!< Alarm A: Minute Units (BCD)     */
#define  RTC_ALRMAR_MSK1                        ((uint32_t)0x00000080)         /*!< Alarm A: Second Mask            */
#define  RTC_ALRMAR_ST                          ((uint32_t)0x00000070)         /*!< Alarm A: Second Tens (BCD)      */
#define  RTC_ALRMAR_SU                          ((uint32_t)0x0000000F)         /*!< Alarm A: Second Units (BCD)     */

/****************** Bit definition for RTC_ALRMASSR register ******************/
#define  RTC_ALRMASSR_MASKSS                    ((uint32_t)0x0F000000)         /*!< Alarm A: Subsecond Mask         */
#define  RTC_ALRMASSR_SS                        ((uint32_t)0x00007FFF)         /*!< Alarm A: Subsecond (binary)     */

/****************** Bit definition for RTC_ALRMBR register ********************/
#define  RTC_ALRMBR_MSK4                        ((uint32_t)0x80000000)         /*!< Alarm B: Date Mask              */
#define  RTC_ALRMBR_WDSEL                       ((uint32_t)0x40000000)         /*!< Alarm B: Weekday Selection      */
#define  RTC_ALRMBR_DT                          ((uint32_t)0x30000000)         /*!< Alarm B: Day Tens (BCD)         */
#define  RTC_ALRMBR_DU                          ((uint32_t)0x0F000000)         /*!< Alarm B: Day Units (BCD)        */
#define  RTC_ALRMBR_MSK3                        ((uint32_t)0x00800000)         /*!< Alarm B: Hour Mask              */
#define  RTC_ALRMBR_PM                          ((uint32_t)0x00400000)         /*!< Alarm B: AM/PM                  */
#define  RTC_ALRMBR_HT                          ((uint32_t)0x00300000)         /*!< Alarm B: Hour Tens (BCD)        */
#define  RTC_ALRMBR_HU                          ((uint32_t)0x000F0000)         /*!< Alarm B: Hour Units (BCD)       */
#define  RTC_ALRMBR_MSK2                        ((uint32_t)0x00008000)         /*!< Alarm B: Minute Mask            */
#define  RTC_ALRMBR_MNT                         ((uint32_t)0x00007000)         /*!< Alarm B: Minute Tens (BCD)      */
#define  RTC_ALRMBR_MNU                         ((uint32_t)0x00000F00)         /*!< Alarm B: Minute Units (BCD)     */
#define  RTC_ALRMBR_MSK1                        ((uint32_t)0x00000080)         /*!< Alarm B: Second Mask            */
#define  RTC_ALRMBR_ST                          ((uint32_t)0x00000070)         /*!< Alarm B: Second Tens (BCD)      */
#define  RTC_ALRMBR_SU                          ((uint32_t)0x0000000F)         /*!< Alarm B: Second Units (BCD)     */

/****************** Bit definition for RTC_ALRMBSSR register ******************/
#define  RTC_ALRMBSSR_MASKSS                    ((uint32_t)0x0F000000)         /*!< Alarm B: Subsecond Mask         */
#define  RTC_ALRMBSSR_SS                        ((uint32_t)0x00007FFF)         /*!< Alarm B: Subsecond (binary)     */

/****************** Bit definition for RTC_SR register ************************/
#define  RTC_SR_TSOVF                           ((uint32_t)0x00000010)         /*!< Timestamp Overflow Flag         */
#define  RTC_SR_TSF                             ((uint32_t)0x00000008)         /*!< Timestamp Flag                  */
#define  RTC_SR_WUTF                            ((uint32_t)0x00000004)         /*!< Wakeup Timer Flag               */
#define  RTC_SR_ALRBF                           ((uint32_t)0x00000002)         /*!< Alarm B Flag                    */
#define  RTC_SR_ALRAF                           ((uint32_t)0x00000001)         /*!< Alarm A Flag                    */

/****************** Bit definition for RTC_MISR register **********************/
#define  RTC_MISR_TSOVMF                        ((uint32_t)0x00000010)         /*!< Timestamp Overflow Masked Flag  */
#define  RTC_MISR_TSMF                          ((uint32_t)0x00000008)         /*!< Timestamp Masked Flag           */
#define  RTC_MISR_WUTMF                         ((uint32_t)0x00000004)         /*!< Wakeup Timer Masked Flag        */
#define  RTC_MISR_ALRBMF                        ((uint32_t)0x00000002)         /*!< Alarm B Masked Flag             */
#define  RTC_MISR_ALRAMF                        ((uint32_t)0x00000001)         /*!< Alarm A Masked Flag             */

/****************** Bit definition for RTC_SCR register ***********************/
#define  RTC_SCR_CTSOVF                         ((uint32_t)0x00000010)         /*!< Clear Timestamp Overflow Flag   */
#define  RTC_SCR_CTSF                           ((uint32_t)0x00000008)         /*!< Clear Timestamp Flag            */
#define  RTC_SCR_CWUTF                          ((uint32_t)0x00000004)         /*!< Clear Wakeup Timer Flag         */
#define  RTC_SCR_CALRBF                         ((uint32_t)0x00000002)         /*!< Clear Alarm B Flag              */
#define  RTC_SCR_CALRAF                         ((uint32_t)0x00000001)         /*!< Clear Alarm A Flag              */

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
