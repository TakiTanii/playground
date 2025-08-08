#include "sh32f0xx_comp.h"
void COMP_EN1(int value){
  ANA_CTRL->COMP1_CSR = (ANA_CTRL->COMP1_CSR & 0xFFFFFFFE) | (value & 0x01);} 
void COMP_INNSEL1(int value){
  ANA_CTRL->COMP1_CSR = (ANA_CTRL->COMP1_CSR & 0xFFFFFF3F) | (value & 0x03) << 6;} 
void COMP_INPSEL1(int value){
  ANA_CTRL->COMP1_CSR = (ANA_CTRL->COMP1_CSR & 0xFFFFFCFF) | (value & 0x03) << 8;} 
void COMP_WINMODE1(int value){
  ANA_CTRL->COMP1_CSR = (ANA_CTRL->COMP1_CSR & 0xFFFFF7FF) | (value & 0x01) << 11;} 
void COMP_WINOUT1(int value){
  ANA_CTRL->COMP1_CSR = (ANA_CTRL->COMP1_CSR & 0xFFFFBFFF) | (value & 0x01) << 14;} 
void COMP_POLARITY1(int value){
  ANA_CTRL->COMP1_CSR = (ANA_CTRL->COMP1_CSR & 0xFFFF7FFF) | (value & 0x01) << 15;} 
void COMP_HYST1(int value){
ANA_CTRL->COMP1_CSR = (ANA_CTRL->COMP1_CSR & 0xFFFEFFFF) | (value & 0x01) << 16;} 
void COMP_PWRMODE1(int value){
ANA_CTRL->COMP1_CSR = (ANA_CTRL->COMP1_CSR & 0xFFFDFFFF) | (value & 0x01) << 17;}
void COMP_BLANKSEL1(int value){
ANA_CTRL->COMP1_CSR = (ANA_CTRL->COMP1_CSR & 0xFFE3FFFF) | (value & 0x07) << 18;}
void COMP_EN2(int value){
  ANA_CTRL->COMP2_CSR = (ANA_CTRL->COMP2_CSR & 0xFFFFFFFE) | (value & 0x01);} 
void COMP_INNSEL2(int value){
  ANA_CTRL->COMP2_CSR = (ANA_CTRL->COMP2_CSR & 0xFFFFFF3F) | (value & 0x03) << 6;} 
void COMP_INPSEL2(int value){
  ANA_CTRL->COMP2_CSR = (ANA_CTRL->COMP2_CSR & 0xFFFFFCFF) | (value & 0x03) << 8;} 
void COMP_WINMODE2(int value){
  ANA_CTRL->COMP2_CSR = (ANA_CTRL->COMP2_CSR & 0xFFFFF7FF) | (value & 0x01) << 11;} 
void COMP_WINOUT2(int value){
  ANA_CTRL->COMP2_CSR = (ANA_CTRL->COMP2_CSR & 0xFFFFBFFF) | (value & 0x01) << 14;} 
void COMP_POLARITY2(int value){
  ANA_CTRL->COMP2_CSR = (ANA_CTRL->COMP2_CSR & 0xFFFF7FFF) | (value & 0x01) << 15;} 
void COMP_HYST2(int value){
ANA_CTRL->COMP2_CSR = (ANA_CTRL->COMP2_CSR & 0xFFFEFFFF) | (value & 0x01) << 16;} 
void COMP_PWRMODE2(int value){
ANA_CTRL->COMP2_CSR = (ANA_CTRL->COMP2_CSR & 0xFFFDFFFF) | (value & 0x01) << 17;}
void COMP_BLANKSEL2(int value){
ANA_CTRL->COMP2_CSR = (ANA_CTRL->COMP2_CSR & 0xFFE3FFFF) | (value & 0x07) << 18;}
void COMP_VCRDIV(int value){
  ANA_CTRL->COMP_VCR = (ANA_CTRL->COMP_VCR & 0xFFFFFFF8) | (value & 0x07);}
void COMP_VCREN(int value){
  ANA_CTRL->COMP_VCR = (ANA_CTRL->COMP_VCR & 0xFFFFFFF7) | (value & 0x01)<< 3;}
void COMP_VCRSVIN(int value){
  ANA_CTRL->COMP_VCR = (ANA_CTRL->COMP_VCR & 0xFFFFFFEF) | (value & 0x01) << 4;} 
void COMP_POLLCH1(int value){
  ANA_CTRL->COMP1_POLL = (ANA_CTRL->COMP1_POLL & 0xFFFFFFFC) | (value & 0x03);}
void COMP_FXIN1(int value){
  ANA_CTRL->COMP1_POLL = (ANA_CTRL->COMP1_POLL & 0xFFFFFFFB) | (value & 0x01) << 2;}
void COMP_PERIOD1(int value){
  ANA_CTRL->COMP1_POLL = (ANA_CTRL->COMP1_POLL & 0xFFFFFF0F) | (value & 0x0F) << 4;}
void COMP_POLLCH2(int value){
  ANA_CTRL->COMP2_POLL = (ANA_CTRL->COMP2_POLL & 0xFFFFFFFC) | (value & 0x03);}
void COMP_FXIN2(int value){
  ANA_CTRL->COMP2_POLL = (ANA_CTRL->COMP2_POLL & 0xFFFFFFFB) | (value & 0x01) << 2;}
void COMP_PERIOD2(int value){
  ANA_CTRL->COMP2_POLL = (ANA_CTRL->COMP2_POLL & 0xFFFFFF0F) | (value & 0x0F) << 4;}
void DAC_EN1(int value){
  ANA_CTRL->DAC1_CR = (ANA_CTRL->DAC1_CR & 0xFFFFFFFE) | (value & 0x1);}
void DAC_SEL1(int value){
  ANA_CTRL->DAC1_CR = (ANA_CTRL->DAC1_CR & 0xFFFFFFFD) | (value & 0x1) << 1;}
void OPAMP_OPAEN1(int value){
  ANA_CTRL->OPAMP1_CSR = (ANA_CTRL->OPAMP1_CSR & 0xFFFFFFFE) | (value & 0x1);}
void OPAMP_VPSEL1(int value){
  ANA_CTRL->OPAMP1_CSR = (ANA_CTRL->OPAMP1_CSR & 0xFFFFFFF9) | (value & 0x3) << 1;}
void OPAMP_VMSEL1(int value){
  ANA_CTRL->OPAMP1_CSR = (ANA_CTRL->OPAMP1_CSR & 0xFFFFFFE7) | (value & 0x3) << 3;}
void OPAMP_OPAPW1(int value){
  ANA_CTRL->OPAMP1_CSR = (ANA_CTRL->OPAMP1_CSR & 0xFFFFFF9F) | (value & 0x3) << 5;}
void OPAMP_OPAINTOEN1(int value){
  ANA_CTRL->OPAMP1_CSR = (ANA_CTRL->OPAMP1_CSR & 0xFFFFFF7F) | (value & 0x1) << 7;}
void OPAMP_PGAGAIN1(int value){
  ANA_CTRL->OPAMP1_CSR = (ANA_CTRL->OPAMP1_CSR & 0xFFFFE0FF) | (value & 0x1F) << 8;}
void OPAMP_TRIMOFFSETP1(int value){
  ANA_CTRL->OPAMP1_CSR = (ANA_CTRL->OPAMP1_CSR & 0xFFFF1FFF) | (value & 0x7) << 13;}
void OPAMP_TRIMOFFSETN1(int value){
  ANA_CTRL->OPAMP1_CSR = (ANA_CTRL->OPAMP1_CSR & 0xFFF8FFFF) | (value & 0x7) << 16;}
void OPAMP_CSR_LOCK1(int value){
  ANA_CTRL->OPAMP1_CSR = (ANA_CTRL->OPAMP1_CSR & 0x7FFFFFFF) | (value & 0x1) << 31;}
void OPAMP_VMSSEL1(int value){
  ANA_CTRL->OPAMP1_TCMR = (ANA_CTRL->OPAMP1_TCMR & 0xFFFFFFFE) | (value & 0x1);}
void OPAMP_VPSSEL1(int value){
  ANA_CTRL->OPAMP1_TCMR = (ANA_CTRL->OPAMP1_TCMR & 0xFFFFFFF9) | (value & 0x3) << 1;}
void OPAMP_T1CMEN1(int value){
  ANA_CTRL->OPAMP1_TCMR = (ANA_CTRL->OPAMP1_TCMR & 0xFFFFFFF7) | (value & 0x1) << 3;}
void OPAMP_T8CMEN1(int value){
  ANA_CTRL->OPAMP1_TCMR = (ANA_CTRL->OPAMP1_TCMR & 0xFFFFFFEF) | (value & 0x1) << 4;}
void OPAMP_T20CMEN1(int value){
  ANA_CTRL->OPAMP1_TCMR = (ANA_CTRL->OPAMP1_TCMR & 0xFFFFFFDF) | (value & 0x1) << 5;}
void OPAMP_TCMR_LOCK1(int value){
  ANA_CTRL->OPAMP1_TCMR = (ANA_CTRL->OPAMP1_TCMR & 0x7FFFFFFF) | (value & 0x1) << 31;}
void OPAMP_OPAEN2(int value){
  ANA_CTRL->OPAMP2_CSR = (ANA_CTRL->OPAMP2_CSR & 0xFFFFFFFE) | (value & 0x1);}
void OPAMP_VPSEL2(int value){
  ANA_CTRL->OPAMP2_CSR = (ANA_CTRL->OPAMP2_CSR & 0xFFFFFFF9) | (value & 0x3) << 1;}
void OPAMP_VMSEL2(int value){
  ANA_CTRL->OPAMP2_CSR = (ANA_CTRL->OPAMP2_CSR & 0xFFFFFFE7) | (value & 0x3) << 3;}
void OPAMP_OPAPW2(int value){
  ANA_CTRL->OPAMP2_CSR = (ANA_CTRL->OPAMP2_CSR & 0xFFFFFF9F) | (value & 0x3) << 5;}
void OPAMP_OPAINTOEN2(int value){
  ANA_CTRL->OPAMP2_CSR = (ANA_CTRL->OPAMP2_CSR & 0xFFFFFF7F) | (value & 0x1) << 7;}
void OPAMP_PGAGAIN2(int value){
  ANA_CTRL->OPAMP2_CSR = (ANA_CTRL->OPAMP2_CSR & 0xFFFFE0FF) | (value & 0x1F) << 8;}
void OPAMP_TRIMOFFSETP2(int value){
  ANA_CTRL->OPAMP2_CSR = (ANA_CTRL->OPAMP2_CSR & 0xFFFF1FFF) | (value & 0x7) << 13;}
void OPAMP_TRIMOFFSETN2(int value){
  ANA_CTRL->OPAMP2_CSR = (ANA_CTRL->OPAMP2_CSR & 0xFFF8FFFF) | (value & 0x7) << 16;}
void OPAMP_CSR_LOCK2(int value){
  ANA_CTRL->OPAMP2_CSR = (ANA_CTRL->OPAMP2_CSR & 0x7FFFFFFF) | (value & 0x1) << 31;}
void OPAMP_VMSSEL2(int value){
  ANA_CTRL->OPAMP2_TCMR = (ANA_CTRL->OPAMP2_TCMR & 0xFFFFFFFE) | (value & 0x1);}
void OPAMP_VPSSEL2(int value){
  ANA_CTRL->OPAMP2_TCMR = (ANA_CTRL->OPAMP2_TCMR & 0xFFFFFFF9) | (value & 0x3) << 1;}
void OPAMP_T1CMEN2(int value){
  ANA_CTRL->OPAMP2_TCMR = (ANA_CTRL->OPAMP2_TCMR & 0xFFFFFFF7) | (value & 0x1) << 3;}
void OPAMP_T8CMEN2(int value){
  ANA_CTRL->OPAMP2_TCMR = (ANA_CTRL->OPAMP2_TCMR & 0xFFFFFFEF) | (value & 0x1) << 4;}
void OPAMP_T20CMEN2(int value){
  ANA_CTRL->OPAMP2_TCMR = (ANA_CTRL->OPAMP2_TCMR & 0xFFFFFFDF) | (value & 0x1) << 5;}
void OPAMP_TCMR_LOCK2(int value){
  ANA_CTRL->OPAMP2_TCMR = (ANA_CTRL->OPAMP2_TCMR & 0x7FFFFFFF) | (value & 0x1) << 31;}
