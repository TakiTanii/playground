#include "sh32f0xx.h"
void ADC_EOSMP(int value){
  ADC->ISR = 0x00000001;}
void ADC_EOC(int value){
  ADC->ISR = 0x00000002;} 
void ADC_EOS(int value){
  ADC->ISR = 0x00000004;} 
void ADC_JEOSMP(int value){
  ADC->ISR = 0x00000008;} 
void ADC_JEOC(int value){
  ADC->ISR = 0x00000010;} 
void ADC_JEOS(int value){
  ADC->ISR = 0x00000020;} 
void ADC_AWD(int value){
  ADC->ISR = 0x00000040;} 
void ADC_OVR(int value){
  ADC->ISR = 0x00000080;}
void ADC_JOVR(int value){
  ADC->ISR = 0x00000100;}
void ADC_CCRDY(int value){
  ADC->ISR = 0x00000200;} 
void ADC_JCCRDY(int value){
  ADC->ISR = 0x00000400;} 
void ADC_EOSMPIE(int value){
  ADC->IER = (ADC->IER & 0xFFFFFFFE) | (value & 0x01);}
void ADC_EOCIE(int value){
  ADC->IER = (ADC->IER & 0xFFFFFFFD) | (value & 0x01) << 1;} 
void ADC_EOSIE(int value){
  ADC->IER = (ADC->IER & 0xFFFFFFFB) | (value & 0x01) << 2;} 
void ADC_JEOSMPIE(int value){
  ADC->IER = (ADC->IER & 0xFFFFFFF7) | (value & 0x01) << 3;} 
void ADC_JEOCIE(int value){
  ADC->IER = (ADC->IER & 0xFFFFFFEF) | (value & 0x01) << 4;} 
void ADC_JEOSIE(int value){
  ADC->IER = (ADC->IER & 0xFFFFFFDF) | (value & 0x01) << 5;} 
void ADC_AWDIE(int value){
  ADC->IER = (ADC->IER & 0xFFFFFFBF) | (value & 0x01) << 6;} 
void ADC_OVRIE(int value){
  ADC->IER = (ADC->IER & 0xFFFFFF7F) | (value & 0x01) << 7;} 
void ADC_JOVRIE(int value){
  ADC->IER = (ADC->IER & 0xFFFFFEFF) | (value & 0x01) << 8;} 
void ADC_CCRDYIE(int value){
  ADC->IER = (ADC->IER & 0xFFFFFDFF) | (value & 0x01) << 9;} 
void ADC_JCCRDYIE(int value){
  ADC->IER = (ADC->IER & 0xFFFFFBFF) | (value & 0x01) << 10;} 
void ADC_ADEN(int value){
  ADC->CR = (ADC->CR & 0xFFFFFFFE) | (value & 0x01);}
void ADC_ADDIS(int value){
  ADC->CR = (ADC->CR & 0xFFFFFFFD) | (value & 0x01) << 1;}
void ADC_ADSTART(int value){
  ADC->CR = (ADC->CR & 0xFFFFFFFB) | (value & 0x01) << 2;}
void ADC_ADSTP(int value){
  ADC->CR = (ADC->CR & 0xFFFFFFF7) | (value & 0x01) << 3;}
void ADC_JADSTART(int value){
  ADC->CR = (ADC->CR & 0xFFFFFFEF) | (value & 0x01) << 4;}
void ADC_DMAEN(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xFFFFFFFE) | (value & 0x01);}
void ADC_PW(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xFFFFFFE7) | (value & 0x03) << 3;}
void ADC_ALIGN(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xFFFFFFDF) | (value & 0x01) << 5;}
void ADC_EXTSEL(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xFFFFFE3F) | (value & 0x07) << 6;}
void ADC_EXTEN(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xFFFFF3FF) | (value & 0x03) << 10;}
void ADC_CONT(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xFFFFDFFF) | (value & 0x01) << 13;}
void ADC_WAIT(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xFFFFBFFF) | (value & 0x01) << 14;}
void ADC_DISCEN(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xFFFEFFFF) | (value & 0x01) << 16;}
void ADC_AWDEN(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xFF7FFFFF) | (value & 0x01) << 23;}
void ADC_SQNUM(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xF0FFFFFF) | (value & 0x0F) << 24;}
void ADC_JQM(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xDFFFFFFF) | (value & 0x01) << 29;}
void ADC_JAUTO(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0xBFFFFFFF) | (value & 0x01) << 30;}
void ADC_JQDIS(int value){
  ADC->CFGR1 = (ADC->CFGR1 & 0x7FFFFFFF) | (value & 0x01) << 31;}
void ADC_OVSE(int value){
  ADC->CFGR2 = (ADC->CFGR2 & 0xFFFFFFFE) | (value & 0x01);}
void ADC_OVSR(int value){
  ADC->CFGR2 = (ADC->CFGR2 & 0xFFFFFFE3) | (value & 0x07) << 2;}
void ADC_OVSS(int value){
  ADC->CFGR2 = (ADC->CFGR2 & 0xFFFFFE1F) | (value & 0x0F) << 5;}
void ADC_TOVS(int value){
  ADC->CFGR2 = (ADC->CFGR2 & 0xFFFFFDFF) | (value & 0x01) << 9;}
void ADC_SREN(int value){
  ADC->CFGR2 = (ADC->CFGR2 & 0xFFFEFFFF) | (value & 0x01) << 16;}
void ADC_SRNUM(int value){
  ADC->CFGR2 = (ADC->CFGR2 & 0xFF81FFFF) | (value & 0x3F) << 17;}
void ADC_JSRNUM(int value){
  ADC->CFGR2 = (ADC->CFGR2 & 0xE07FFFFF) | (value & 0x3F) << 23;}
void ADC_LFTRIG(int value){
  ADC->CFGR2 = (ADC->CFGR2 & 0xDFFFFFFF) | (value & 0x01) << 29;}
void ADC_CKMODE(int value){
  ADC->CFGR2 = (ADC->CFGR2 & 0x3FFFFFFF) | (value & 0x03) << 30;}
void ADC_SMP1(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFFFFF0) | (value & 0x0F);}
void ADC_SMP2(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFFFF0F) | (value & 0x0F) << 4;}
void ADC_SMPSEL0(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFFFEFF) | (value & 0x01) << 8;}
void ADC_SMPSEL1(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFFFDFF) | (value & 0x01) << 9;}
void ADC_SMPSEL2(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFFFBFF) | (value & 0x01) << 10;}
void ADC_SMPSEL3(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFFF7FF) | (value & 0x01) << 11;}
void ADC_SMPSEL4(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFFEFFF) | (value & 0x01) << 12;}
void ADC_SMPSEL5(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFFDFFF) | (value & 0x01) << 13;}
void ADC_SMPSEL6(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFFBFFF) | (value & 0x01) << 14;}
void ADC_SMPSEL7(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFF7FFF) | (value & 0x01) << 15;}
void ADC_SMPSEL8(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFEFFFF) | (value & 0x01) << 16;}
void ADC_SMPSEL9(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFDFFFF) | (value & 0x01) << 17;}
void ADC_SMPSEL10(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFFBFFFF) | (value & 0x01) << 18;}
void ADC_SMPSEL11(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFF7FFFF) | (value & 0x01) << 19;}
void ADC_SMPSEL12(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFEFFFFF) | (value & 0x01) << 20;}
void ADC_SMPSEL13(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFDFFFFF) | (value & 0x01) << 21;}
void ADC_SMPSEL14(int value){
  ADC->SMPR = (ADC->SMPR & 0xFFBFFFFF) | (value & 0x01) << 22;}
void ADC_SMPSEL15(int value){
  ADC->SMPR = (ADC->SMPR & 0xFF7FFFFF) | (value & 0x01) << 23;}
void ADC_LT(int value){
  ADC->AWDTR = (ADC->AWDTR & 0xFFFFF000) | (value & 0xFFF);}
void ADC_HT(int value){
  ADC->AWDTR = (ADC->AWDTR & 0xF000FFFF) | (value & 0xFFF) << 16;}
void ADC_AWDCH0(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFFFFE) | (value & 0x01);}
void ADC_AWDCH1(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFFFFD) | (value & 0x01) << 1;}
void ADC_AWDCH2(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFFFFB) | (value & 0x01) << 2;}
void ADC_AWDCH3(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFFFF7) | (value & 0x01) << 3;}
void ADC_AWDCH4(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFFFEF) | (value & 0x01) << 4;}
void ADC_AWDCH5(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFFFDF) | (value & 0x01) << 5;}
void ADC_AWDCH6(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFFFBF) | (value & 0x01) << 6;}
void ADC_AWDCH7(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFFF7F) | (value & 0x01) << 7;}
void ADC_AWDCH8(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFFEFF) | (value & 0x01) << 8;}
void ADC_AWDCH9(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFFDFF) | (value & 0x01) << 9;}
void ADC_AWDCH10(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFFBFF) | (value & 0x01) << 10;}
void ADC_AWDCH11(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFF7FF) | (value & 0x01) << 11;}
void ADC_AWDCH12(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFEFFF) | (value & 0x01) << 12;}
void ADC_AWDCH13(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFDFFF) | (value & 0x01) << 13;}
void ADC_AWDCH14(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFFBFFF) | (value & 0x01) << 14;}
void ADC_AWDCH15(int value){
  ADC->AWDCR = (ADC->AWDCR & 0xFFFF7FFF) | (value & 0x01) << 15;}
void ADC_SQ1(int value){
  ADC->CHSELR1 = (ADC->CHSELR1 & 0xFFFFFFF0) | (value & 0x0F);}
void ADC_SQ2(int value){
  ADC->CHSELR1 = (ADC->CHSELR1 & 0xFFFFFF0F) | (value & 0x0F) << 4;}
void ADC_SQ3(int value){
  ADC->CHSELR1 = (ADC->CHSELR1 & 0xFFFFF0FF) | (value & 0x0F) << 8;}
void ADC_SQ4(int value){
  ADC->CHSELR1 = (ADC->CHSELR1 & 0xFFFF0FFF) | (value & 0x0F) << 12;}
void ADC_SQ5(int value){
  ADC->CHSELR1 = (ADC->CHSELR1 & 0xFFF0FFFF) | (value & 0x0F) << 16;}
void ADC_SQ6(int value){
  ADC->CHSELR1 = (ADC->CHSELR1 & 0xFF0FFFFF) | (value & 0x0F) << 20;}
void ADC_SQ7(int value){
  ADC->CHSELR1 = (ADC->CHSELR1 & 0xF0FFFFFF) | (value & 0x0F) << 24;}
void ADC_SQ8(int value){
  ADC->CHSELR1 = (ADC->CHSELR1 & 0x0FFFFFFF) | (value & 0x0F) << 28;}
void ADC_SQ9(int value){
  ADC->CHSELR2 = (ADC->CHSELR2 & 0xFFFFFFF0) | (value & 0x0F);}
void ADC_SQ10(int value){
  ADC->CHSELR2 = (ADC->CHSELR2 & 0xFFFFFF0F) | (value & 0x0F) << 4;}
void ADC_SQ11(int value){
  ADC->CHSELR2 = (ADC->CHSELR2 & 0xFFFFF0FF) | (value & 0x0F) << 8;}
void ADC_SQ12(int value){
  ADC->CHSELR2 = (ADC->CHSELR2 & 0xFFFF0FFF) | (value & 0x0F) << 12;}
void ADC_SQ13(int value){
  ADC->CHSELR2 = (ADC->CHSELR2 & 0xFFF0FFFF) | (value & 0x0F) << 16;}
void ADC_SQ14(int value){
  ADC->CHSELR2 = (ADC->CHSELR2 & 0xFF0FFFFF) | (value & 0x0F) << 20;}
void ADC_SQ15(int value){
  ADC->CHSELR2 = (ADC->CHSELR2 & 0xF0FFFFFF) | (value & 0x0F) << 24;}
void ADC_SQ16(int value){
  ADC->CHSELR2 = (ADC->CHSELR2 & 0x0FFFFFFF) | (value & 0x0F) << 28;}
void ADC_JNUM(int value){
  ADC->JSQR = (ADC->JSQR & 0xFFFFFFFC) | (value & 0x03);}
void ADC_JEXTSEL(int value){
  ADC->JSQR = (ADC->JSQR & 0xFFFFFFE3) | (value & 0x07) << 2;}
void ADC_JEXTEN(int value){
  ADC->JSQR = (ADC->JSQR & 0xFFFFFF9F) | (value & 0x03) << 5;}
void ADC_JSQ1(int value){
  ADC->JSQR = (ADC->JSQR & 0xFFFFF0FF) | (value & 0x0F) << 8;}
void ADC_JSQ2(int value){
  ADC->JSQR = (ADC->JSQR & 0xFFFF0FFF) | (value & 0x0F) << 12;}
void ADC_JSQ3(int value){
  ADC->JSQR = (ADC->JSQR & 0xFFF0FFFF) | (value & 0x0F) << 16;}
void ADC_JSQ4(int value){
  ADC->JSQR = (ADC->JSQR & 0xFF0FFFFF) | (value & 0x0F) << 20;}
void ADC_ADDR(int value){
  ADC->DAR = value;}
void ADC_JADDR(int value){
  ADC->JDAR = value;}
void ADC_PRESC(int value){
  ADC->CCR = (ADC->CCR & 0xFFC3FFFF) | (value & 0x0F) << 18;}
void ADC_VREFEN(int value){
  ADC->CCR = (ADC->CCR & 0xFFBFFFFF) | (value & 0x01) << 22;}
void ADC_TSEN(int value){
  ADC->CCR = (ADC->CCR & 0xFF7FFFFF) | (value & 0x01) << 23;}
void ADC_CLK_ENABLE(void)
{
    RCC -> APBENR1 = (RCC -> APBENR1 & 0xFFFFFFFE) | 0x00000001;
}
void ADC_CLK_DISABLE(void)
{
    RCC -> APBENR1 = (RCC -> APBENR1 & 0xFFFFFFFE);
}
