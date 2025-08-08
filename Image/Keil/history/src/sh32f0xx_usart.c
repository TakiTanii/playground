#include "sh32f0xx_usart.h"

void USART_IO_CONFIG(void)
{
  GPIO->OTYPER |= 0x0000FFFF;
  GPIO->PUPDR  |= 0x0000FFFF;
  GPIO->MODER  |= 0x9FFF;
  GPIO->AFRL   = 0x00022222;
  GPIO->AFRH   |= 0x00022222;
  GPIO->DIRR   |= 0x1316;
}
void USART1_CLK_ENABLE(void)
{
    RCC -> APBENR1 = (RCC -> APBENR1 & 0xFFFFFFBF) | 0x00000040;
}
void USART1_CLK_DISABLE(void)
{
    RCC -> APBENR1 = (RCC -> APBENR1 & 0xFFFFFFBF);
}
void USART2_CLK_ENABLE(void)
{
    RCC -> APBENR1 = (RCC -> APBENR1 & 0xFFFFFF7F) | 0x00000080;
}
void USART2_CLK_DISABLE(void)
{
    RCC -> APBENR1 = (RCC -> APBENR1 & 0xFFFFFF7F);
}
void DMA_CLK_ENABLE(void)
{
    RCC -> AHBENR = (RCC -> AHBENR & 0xFFFFFFFE) | 0x00000001;
}
void DMA_CLK_DISABLE(void)
{
    RCC -> AHBENR = (RCC -> AHBENR & 0xFFFFFFFE);
}

void US_MR1_MODE(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFFFFFF0) | (value & 0x0F);} 
void US_MR1_USCLK(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFFFFFCF) | (value & 0x03) << 4;} 
void US_MR1_CHRL(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFFFFF3F) | (value & 0x03) << 6;} 
void US_MR1_SYNC(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFFFFEFF) | (value & 0x01) << 8;} 
void US_MR1_PAR(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFFFF1FF) | (value & 0x07) << 9;} 
void US_MR1_NBSTOP(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFFFCFFF) | (value & 0x03) << 12;} 
void US_MR1_MSBF(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFFEFFFF) | (value & 0x01) << 16;} 
void US_MR1_MODE9(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFFDFFFF) | (value & 0x01) << 17;} 
void US_MR1_OVER(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFF7FFFF) | (value & 0x01) << 19;} 
void US_MR1_CPHA(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFFFFEFF) | (value & 0x01) << 8;} 
void US_MR1_CPOL(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFFEFFFF) | (value & 0x01) << 16;}
void US_MR1_CLKO(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFFBFFFF) | (value & 0x01) << 18;} 
void US_MR1_WRDBT(int value){
  USART1->US_MR = (USART1->US_MR & 0xFFEFFFFF) | (value & 0x01) << 20;} 
void US_BRGR1_CD(unsigned int value){
  USART1->US_BRGR = (USART1->US_BRGR & 0xFFFF0000) | (value & 0xFFFF);} 
void US_BRGR1_FP(unsigned int value){
  USART1->US_BRGR = (USART1->US_BRGR & 0xFFF8FFFF) | (value & 0x07) << 16;} 
void US_MR1_MAN(int value){
  USART1->US_MR = (USART1->US_MR & 0xDFFFFFFF) | (value & 0x01) << 29;} 
void US_MAN1_TXPL(int value){
  USART1->US_MAN = (USART1->US_MAN & 0xFFFFFFF0) | (value & 0x0F);} 
void US_MAN1_TXPP(int value){
  USART1->US_MAN = (USART1->US_MAN & 0xFFFFFCFF) | (value & 0x03) << 8;} 
void US_MAN1_TXMPOL(int value){
  USART1->US_MAN = (USART1->US_MAN & 0xFFFFEFFF) | (value & 0x01) << 12;} 
void US_MAN1_RXPL(int value){
  USART1->US_MAN = (USART1->US_MAN & 0xFFF0FFFF) | (value & 0x0F) << 16;} 
void US_MAN1_RXPP(int value){
  USART1->US_MAN = (USART1->US_MAN & 0xFCFFFFFF) | (value & 0x03) << 24;} 
void US_MAN1_RXMPOL(int value){
  USART1->US_MAN = (USART1->US_MAN & 0xEFFFFFFF) | (value & 0x01) << 28;} 

void US_MR2_MODE(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFFFFFF0) | (value & 0x0F);} 
void US_MR2_USCLK(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFFFFFCF) | (value & 0x03) << 4;} 
void US_MR2_CHRL(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFFFFF3F) | (value & 0x03) << 6;} 
void US_MR2_SYNC(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFFFFEFF) | (value & 0x01) << 8;} 
void US_MR2_PAR(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFFFF1FF) | (value & 0x07) << 9;} 
void US_MR2_NBSTOP(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFFFCFFF) | (value & 0x03) << 12;} 
void US_MR2_MSBF(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFFEFFFF) | (value & 0x01) << 16;} 
void US_MR2_MODE9(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFFDFFFF) | (value & 0x01) << 17;} 
void US_MR2_OVER(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFF7FFFF) | (value & 0x01) << 19;} 
void US_MR2_CPHA(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFFFFEFF) | (value & 0x01) << 8;} 
void US_MR2_CPOL(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFFEFFFF) | (value & 0x01) << 16;} 
void US_MR2_WRDBT(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFEFFFFF) | (value & 0x01) << 20;} 
void US_MR2_CLKO(int value){
  USART2->US_MR = (USART2->US_MR & 0xFFFBFFFF) | (value & 0x01) << 18;} 
void US_BRGR2_CD(unsigned int value){
  USART2->US_BRGR = (USART2->US_BRGR & 0xFFFF0000) | (value & 0xFFFF);} 
void US_BRGR2_FP(unsigned int value){
  USART2->US_BRGR = (USART2->US_BRGR & 0xFFF8FFFF) | (value & 0x07) << 16;} 
void US_LINMR1_CHKTYP(int value){
  USART1->US_LINMR = (USART1->US_LINMR & 0xFFFFFFEF) | (value & 0x01) << 4;}
void US_LINMR1_DLC(int value){
  USART1->US_LINMR = (USART1->US_LINMR & 0xFFFF00FF) | (value & 0xFF) << 8;}void US_LINMR2_CHKTYP(int value){
  USART2->US_LINMR = (USART2->US_LINMR & 0xFFFFFFEF) | (value & 0x01) << 4;}
void US_LINMR2_DLC(int value){
  USART2->US_LINMR = (USART2->US_LINMR & 0xFFFF00FF) | (value & 0xFF) << 8;}
void US_MR2_MAN(int value){
  USART2->US_MR = (USART2->US_MR & 0xDFFFFFFF) | (value & 0x01) << 29;} 
void US_MAN2_TXPL(int value){
  USART2->US_MAN = (USART2->US_MAN & 0xFFFFFFF0) | (value & 0x0F);} 
void US_MAN2_TXPP(int value){
  USART2->US_MAN = (USART2->US_MAN & 0xFFFFFCFF) | (value & 0x03) << 8;} 
void US_MAN2_TXMPOL(int value){
  USART2->US_MAN = (USART2->US_MAN & 0xFFFFEFFF) | (value & 0x01) << 12;} 
void US_MAN2_RXPL(int value){
  USART2->US_MAN = (USART2->US_MAN & 0xFFF0FFFF) | (value & 0x0F) << 16;} 
void US_MAN2_RXPP(int value){
  USART2->US_MAN = (USART2->US_MAN & 0xFCFFFFFF) | (value & 0x03) << 24;} 
void US_MAN2_RXMPOL(int value){
  USART2->US_MAN = (USART2->US_MAN & 0xEFFFFFFF) | (value & 0x01) << 28;} 
