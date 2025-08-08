#ifndef __SH32F0XX_USART_H
#define __SH32F0XX_USART_H
#include "sh32f0xx.h"
#define Channel 2
void USART_IO_CONFIG(void);
void USART1_CLK_ENABLE(void);
void USART1_CLK_DISABLE(void);
void USART2_CLK_ENABLE(void);
void USART2_CLK_DISABLE(void);
void DMA_CLK_ENABLE(void);
void DMA_CLK_DISABLE(void);
void US_MR1_MODE(int value);
void US_MR1_USCLK(int value);
void US_MR1_CHRL(int value);
void US_MR1_SYNC(int value);
void US_MR1_PAR(int value);
void US_MR1_NBSTOP(int value);
void US_MR1_MSBF(int value);
void US_MR1_MODE9(int value);
void US_MR1_OVER(int value);
void US_MR1_WRDBT(int value);
void US_MR1_CPHA(int value);
void US_MR1_CPOL(int value);
void US_MR1_CLKO(int value);
void US_LINMR1_CHKTYP(int value);
void US_LINMR1_DLC(int value);
void US_BRGR1_CD(unsigned int value);
void US_BRGR1_FP(unsigned int value);
void US_MR1_MAN(int value);
void US_MAN1_TXPL(int value);
void US_MAN1_TXPP(int value);
void US_MAN1_TXMPOL(int value);
void US_MAN1_RXPL(int value);
void US_MAN1_RXPP(int value);
void US_MAN1_RXMPOL(int value);

void US_MR2_MODE(int value);
void US_MR2_USCLK(int value);
void US_MR2_CHRL(int value);
void US_MR2_SYNC(int value);
void US_MR2_PAR(int value);
void US_MR2_NBSTOP(int value);
void US_MR2_MSBF(int value);
void US_MR2_MODE9(int value);
void US_MR2_OVER(int value);
void US_MR2_WRDBT(int value);
void US_MR2_CPHA(int value);
void US_MR2_CPOL(int value);
void US_MR2_CLKO(int value);
void US_LINMR2_CHKTYP(int value);
void US_LINMR2_DLC(int value);
void US_BRGR2_CD(unsigned int value);
void US_BRGR2_FP(unsigned int value);
void US_MR2_MAN(int value);
void US_MAN2_TXPL(int value);
void US_MAN2_TXPP(int value);
void US_MAN2_TXMPOL(int value);
void US_MAN2_RXPL(int value);
void US_MAN2_RXPP(int value);
void US_MAN2_RXMPOL(int value);

#endif 
