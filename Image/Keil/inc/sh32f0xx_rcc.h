#ifndef __SH32F0XX_RCC_H
#define __SH32F0XX_RCC_H
#include "sh32f0xx.h"

// Clk Ready ------------------------------
void if_HSERDY (void);
void if_HSIRDY (void);
void if_LSERDY (void);
void if_LSIRDY (void);

// CR -------------------------------------
void RCC_CR     (uint32_t i);   
void RCC_CSSON  (uint32_t i);
void RCC_HSEBYP (uint32_t i);
void RCC_HSEON  (uint32_t i);
void RCC_HSION  (uint32_t i);

// CFGR -----------------------------------
void RCC_CFGR   (uint32_t i);
void RCC_MCOPRE (uint32_t i);
void RCC_MCOSEL (uint32_t i);
void RCC_HSEDRV (uint32_t i);
void RCC_HSISEL (uint32_t i);
void RCC_PPRE   (uint32_t i);
void RCC_HPRE   (uint32_t i);
void RCC_SW     (uint32_t i);

// CIR ------------------------------------
void RCC_CIR      (uint32_t i);
void RCC_LSECSSC  (void);
void RCC_CSSC     (void);
void RCC_HSERDYIC (void);
void RCC_HSIRDYIC (void);
void RCC_LSERDYIC (void);
void RCC_LSIRDYIC (void);
void RCC_HSERDYIE (uint32_t i);
void RCC_HSIRDYIE (uint32_t i);
void RCC_LSERDYIE (uint32_t i);
void RCC_LSIRDYIE (uint32_t i);

// AHBRSTR --------------------------------
void RCC_AHBRSTR   (uint32_t i);
void RCC_CORDICRST (uint32_t i);
void RCC_CRCRST    (uint32_t i);
void RCC_FLASHRST  (uint32_t i);
void RCC_DMARST    (uint32_t i);

// APBRSTR1 -------------------------------
void RCC_APBRSTR1  (uint32_t i);
void RCC_LPTIMRST  (uint32_t i);
void RCC_TIM7RST   (uint32_t i);
void RCC_TIM6RST   (uint32_t i);
void RCC_TIM14RST  (uint32_t i);
void RCC_TIM2RST   (uint32_t i);
void RCC_TIM1RST   (uint32_t i);
void RCC_SPI1RST   (uint32_t i);
void RCC_I2C1RST   (uint32_t i);
void RCC_USART2RST (uint32_t i);
void RCC_USART1RST (uint32_t i);
void RCC_COMPRST   (uint32_t i);
void RCC_ADCRST    (uint32_t i);

// AHBENR ---------------------------------
void RCC_AHBENR   (uint32_t i);
void RCC_CORDICEN (uint32_t i);
void RCC_CRCEN    (uint32_t i);
void RCC_FLASHEN  (uint32_t i);
void RCC_DMAEN    (uint32_t i);

// APBENR1 --------------------------------
void RCC_APBENR1  (uint32_t i);
void RCC_LPTIMEN  (uint32_t i);
void RCC_TIM7EN   (uint32_t i);
void RCC_TIM6EN   (uint32_t i);
void RCC_TIM14EN  (uint32_t i);
void RCC_TIM2EN   (uint32_t i);
void RCC_TIM1EN   (uint32_t i);
void RCC_SPI1EN   (uint32_t i);
void RCC_I2C1EN   (uint32_t i);
void RCC_USART2EN (uint32_t i);
void RCC_USART1EN (uint32_t i);
void RCC_COMPEN   (uint32_t i);
void RCC_ADCEN    (uint32_t i);

// CCIPR ----------------------------------
void RCC_CCIPR    (uint32_t i);
void RCC_ADCSEL   (uint32_t i);
void RCC_LPTIMSEL (uint32_t i);

// BDCR -----------------------------------
void RCC_BDCR     (uint32_t i);
void RCC_BDRST    (uint32_t i);
void RCC_RTCEN    (uint32_t i);
void RCC_RTCSEL   (uint32_t i);
void RCC_LSECSSON (uint32_t i);
void RCC_LSEDRV   (uint32_t i);
void RCC_LSEBYP   (uint32_t i);
void RCC_LSEON    (uint32_t i);

// CSR ------------------------------------
void RCC_CSR         (uint32_t i);
void RCC_RMVF        (uint32_t i);
void RCC_CPULOCKUPEN (uint32_t i);
void RCC_LSION       (uint32_t i);

// HSI_TRIM -------------------------------
void RCC_HSI_TRIM (uint32_t i);

// LSI_TRIM -------------------------------
void RCC_LSI_TRIM (uint32_t i);

// HSI_CNT --------------------------------
void RCC_HSI_CNT (uint32_t i);

// HSE_CNT --------------------------------
void RCC_HSE_CNT (uint32_t i);

// LSI_CNT --------------------------------
void RCC_LSI_CNT (uint32_t i);

// LSE_CNT --------------------------------
void RCC_LSE_CNT (uint32_t i);

#endif

