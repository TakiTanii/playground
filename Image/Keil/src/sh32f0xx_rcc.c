#include "sh32f0xx_rcc.h"

// Clk Ready ------------------------------
void if_HSERDY (void) {while(!(RCC -> CR   & RCC_CR_HSERDY  ));}
void if_HSIRDY (void) {while(!(RCC -> CR   & RCC_CR_HSIRDY  ));}
void if_LSERDY (void) {while(!(RCC -> BDCR & RCC_BDCR_LSERDY));}
void if_LSIRDY (void) {while(!(RCC -> CSR  & RCC_CSR_LSIRDY ));}

// CR -------------------------------------
void RCC_CR     (uint32_t i) {RCC -> CR = i;}
void RCC_CSSON  (uint32_t i) {RCC -> CR = (RCC -> CR & ~RCC_CR_CSSON ) | ((i & 0x1) << 5);}
void RCC_HSEBYP (uint32_t i) {RCC -> CR = (RCC -> CR & ~RCC_CR_HSEBYP) | ((i & 0x1) << 4);}
void RCC_HSEON  (uint32_t i) {RCC -> CR = (RCC -> CR & ~RCC_CR_HSEON ) | ((i & 0x1) << 2);}
void RCC_HSION  (uint32_t i) {RCC -> CR = (RCC -> CR & ~RCC_CR_HSION ) | ((i & 0x1) << 0);}

// CFGR -----------------------------------
void RCC_CFGR   (uint32_t i) {RCC -> CFGR = i;}
void RCC_MCOPRE (uint32_t i) {RCC -> CFGR = (RCC -> CFGR & ~RCC_CFGR_MCOPRE) | ((i & 0x7) << 28);}
void RCC_MCOSEL (uint32_t i) {RCC -> CFGR = (RCC -> CFGR & ~RCC_CFGR_MCOSEL) | ((i & 0x7) << 24);}
void RCC_HSEDRV (uint32_t i) {RCC -> CFGR = (RCC -> CFGR & ~RCC_CFGR_HSEDRV) | ((i & 0x7) << 17);}
void RCC_HSISEL (uint32_t i) {RCC -> CFGR = (RCC -> CFGR & ~RCC_CFGR_HSISEL) | ((i & 0x1) << 16);}
void RCC_PPRE   (uint32_t i) {RCC -> CFGR = (RCC -> CFGR & ~RCC_CFGR_PPRE  ) | ((i & 0x7) << 12);}
void RCC_HPRE   (uint32_t i) {RCC -> CFGR = (RCC -> CFGR & ~RCC_CFGR_HPRE  ) | ((i & 0xF) <<  8);}
void RCC_SW     (uint32_t i) {RCC -> CFGR = (RCC -> CFGR & ~RCC_CFGR_SW    ) | ((i & 0x7) <<  0);}

// CIR ------------------------------------
void RCC_CIR      (uint32_t i) {RCC -> CIR = i;}
void RCC_LSECSSC  (void)       {RCC -> CIR |= RCC_CIR_LSECSSC;}
void RCC_CSSC     (void)       {RCC -> CIR |= RCC_CIR_CSSC;}
void RCC_HSERDYIC (void)       {RCC -> CIR |= RCC_CIR_HSERDYIC;}
void RCC_HSIRDYIC (void)       {RCC -> CIR |= RCC_CIR_HSIRDYIC;}
void RCC_LSERDYIC (void)       {RCC -> CIR |= RCC_CIR_LSERDYIC;}
void RCC_LSIRDYIC (void)       {RCC -> CIR |= RCC_CIR_LSIRDYIC;}
void RCC_HSERDYIE (uint32_t i) {RCC -> CIR = (RCC -> CIR & ~RCC_CIR_HSERDYIE) | ((i & 0x1) << 3);}
void RCC_HSIRDYIE (uint32_t i) {RCC -> CIR = (RCC -> CIR & ~RCC_CIR_HSIRDYIE) | ((i & 0x1) << 2);}
void RCC_LSERDYIE (uint32_t i) {RCC -> CIR = (RCC -> CIR & ~RCC_CIR_LSERDYIE) | ((i & 0x1) << 1);}
void RCC_LSIRDYIE (uint32_t i) {RCC -> CIR = (RCC -> CIR & ~RCC_CIR_LSIRDYIE) | ((i & 0x1) << 0);}

// AHBRSTR --------------------------------
void RCC_AHBRSTR   (uint32_t i) {RCC -> AHBRSTR = i;}
void RCC_CORDICRST (uint32_t i) {RCC -> AHBRSTR = (RCC -> AHBRSTR & ~RCC_AHBRSTR_CORDICRST) | ((i & 0x1) << 13);}
void RCC_CRCRST    (uint32_t i) {RCC -> AHBRSTR = (RCC -> AHBRSTR & ~RCC_AHBRSTR_CRCRST   ) | ((i & 0x1) << 12);}
void RCC_FLASHRST  (uint32_t i) {RCC -> AHBRSTR = (RCC -> AHBRSTR & ~RCC_AHBRSTR_FLASHRST ) | ((i & 0x1) <<  8);}
void RCC_DMARST    (uint32_t i) {RCC -> AHBRSTR = (RCC -> AHBRSTR & ~RCC_AHBRSTR_DMARST   ) | ((i & 0x1) <<  0);}

// APBRSTR1 -------------------------------
void RCC_APBRSTR1  (uint32_t i) {RCC -> APBRSTR1 = i;}
void RCC_LPTIMRST  (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_LPTIMRST ) | ((i & 0x1) << 17);}
void RCC_TIM7RST   (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_TIM7RST  ) | ((i & 0x1) << 16);}
void RCC_TIM6RST   (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_TIM6RST  ) | ((i & 0x1) << 15);}
void RCC_TIM14RST  (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_TIM14RST ) | ((i & 0x1) << 12);}
void RCC_TIM2RST   (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_TIM2RST  ) | ((i & 0x1) << 11);}
void RCC_TIM1RST   (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_TIM1RST  ) | ((i & 0x1) << 10);}
void RCC_SPI1RST   (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_SPI1RST  ) | ((i & 0x1) <<  9);}
void RCC_I2C1RST   (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_I2C1RST  ) | ((i & 0x1) <<  8);}
void RCC_USART2RST (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_USART2RST) | ((i & 0x1) <<  7);}
void RCC_USART1RST (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_USART1RST) | ((i & 0x1) <<  6);}
void RCC_COMPRST   (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_COMPRST  ) | ((i & 0x1) <<  1);}
void RCC_ADCRST    (uint32_t i) {RCC -> APBRSTR1 = (RCC -> APBRSTR1 & ~RCC_APBRSTR1_ADCRST   ) | ((i & 0x1) <<  0);}

// AHBENR ---------------------------------
void RCC_AHBENR   (uint32_t i) {RCC -> AHBENR = i;}
void RCC_CORDICEN (uint32_t i) {RCC -> AHBENR = (RCC -> AHBENR & ~RCC_AHBENR_CORDICEN) | ((i & 0x1) << 13);}
void RCC_CRCEN    (uint32_t i) {RCC -> AHBENR = (RCC -> AHBENR & ~RCC_AHBENR_CRCEN   ) | ((i & 0x1) << 12);}
void RCC_FLASHEN  (uint32_t i) {RCC -> AHBENR = (RCC -> AHBENR & ~RCC_AHBENR_FLASHEN ) | ((i & 0x1) <<  8);}
void RCC_DMAEN    (uint32_t i) {RCC -> AHBENR = (RCC -> AHBENR & ~RCC_AHBENR_DMAEN   ) | ((i & 0x1) <<  0);}

// APBENR1 --------------------------------
void RCC_APBENR1  (uint32_t i) {RCC -> APBENR1 = i;}
void RCC_LPTIMEN  (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_LPTIMEN ) | ((i & 0x1) << 17);}
void RCC_TIM7EN   (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_TIM7EN  ) | ((i & 0x1) << 16);}
void RCC_TIM6EN   (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_TIM6EN  ) | ((i & 0x1) << 15);}
void RCC_TIM14EN  (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_TIM14EN ) | ((i & 0x1) << 12);}
void RCC_TIM2EN   (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_TIM2EN  ) | ((i & 0x1) << 11);}
void RCC_TIM1EN   (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_TIM1EN  ) | ((i & 0x1) << 10);}
void RCC_SPI1EN   (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_SPI1EN  ) | ((i & 0x1) <<  9);}
void RCC_I2C1EN   (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_I2C1EN  ) | ((i & 0x1) <<  8);}
void RCC_USART2EN (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_USART2EN) | ((i & 0x1) <<  7);}
void RCC_USART1EN (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_USART1EN) | ((i & 0x1) <<  6);}
void RCC_COMPEN   (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_COMPEN  ) | ((i & 0x1) <<  1);}
void RCC_ADCEN    (uint32_t i) {RCC -> APBENR1 = (RCC -> APBENR1 & ~RCC_APBENR1_ADCEN   ) | ((i & 0x1) <<  0);}

// CCIPR ----------------------------------
void RCC_CCIPR    (uint32_t i) {RCC -> CCIPR = i;}
void RCC_ADCSEL   (uint32_t i) {RCC -> CCIPR = (RCC -> CCIPR & ~RCC_CCIPR_ADCSEL)   | (i & 0x3) << 30;}
void RCC_LPTIMSEL (uint32_t i) {RCC -> CCIPR = (RCC -> CCIPR & ~RCC_CCIPR_LPTIMSEL) | (i & 0x3) << 18;}

// BDCR -----------------------------------
void RCC_BDCR     (uint32_t i) {RCC -> BDCR = i;}
void RCC_BDRST    (uint32_t i) {RCC -> BDCR = (RCC -> BDCR & ~RCC_BDCR_BDRST   ) | ((i & 0x1) << 16);}
void RCC_RTCEN    (uint32_t i) {RCC -> BDCR = (RCC -> BDCR & ~RCC_BDCR_RTCEN   ) | ((i & 0x1) << 15);}
void RCC_RTCSEL   (uint32_t i) {RCC -> BDCR = (RCC -> BDCR & ~RCC_BDCR_RTCSEL  ) | ((i & 0x3) <<  8);}
void RCC_LSECSSON (uint32_t i) {RCC -> BDCR = (RCC -> BDCR & ~RCC_BDCR_LSECSSON) | ((i & 0x1) <<  6);}
void RCC_LSEDRV   (uint32_t i) {RCC -> BDCR = (RCC -> BDCR & ~RCC_BDCR_LSEDRV  ) | ((i & 0x7) <<  3);}
void RCC_LSEBYP   (uint32_t i) {RCC -> BDCR = (RCC -> BDCR & ~RCC_BDCR_LSEBYP  ) | ((i & 0x1) <<  2);}
void RCC_LSEON    (uint32_t i) {RCC -> BDCR = (RCC -> BDCR & ~RCC_BDCR_LSEON   ) | ((i & 0x1) <<  0);}

// CSR ------------------------------------
void RCC_CSR         (uint32_t i) {RCC -> CSR = i;}
void RCC_RMVF        (uint32_t i) {RCC -> CSR = (RCC -> CSR & ~RCC_CSR_RMVF)        | ((i & 0x1) << 23);}
void RCC_CPULOCKUPEN (uint32_t i) {RCC -> CSR = (RCC -> CSR & ~RCC_CSR_CPULOCKUPEN) | ((i & 0x1) << 2);}
void RCC_LSION       (uint32_t i) {RCC -> CSR = (RCC -> CSR & ~RCC_CSR_LSION)       | ((i & 0x1) << 0);}

// HSI_TRIM -------------------------------
void RCC_HSI_TRIM (uint32_t i) {RCC -> HSITRIM = i;}

// LSI_TRIM -------------------------------
void RCC_LSI_TRIM (uint32_t i) {RCC -> LSITRIM = i;}

// HSI_CNT --------------------------------
void RCC_HSI_CNT (uint32_t i) {RCC -> HSICNT = i;}

// HSE_CNT --------------------------------
void RCC_HSE_CNT (uint32_t i) {RCC -> HSECNT = i;}

// LSI_CNT --------------------------------
void RCC_LSI_CNT (uint32_t i) {RCC -> LSICNT = i;}

// LSE_CNT --------------------------------
void RCC_LSE_CNT (uint32_t i) {RCC -> LSECNT = i;}
