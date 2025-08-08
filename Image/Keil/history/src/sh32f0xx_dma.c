// Includes ------------------------------------------------------------------
#include "sh32f0xx_dma.h"

// Private functions ---------------------------------------------------------
// ---------------------------------------------------------------------------
// DMA Clock Enable functions
// ---------------------------------------------------------------------------
void DMA_CLK_EN(int i) {RCC -> AHBENR = (RCC -> AHBENR & 0xFFFFFFFE) | (i & 0x1);}

// ---------------------------------------------------------------------------
// DMA ISR functions
// ---------------------------------------------------------------------------
void if_TEIF8(int i) {while((DMA -> ISR & DMA_ISR_TEIF8) != (i & 0x1) << 31);}
void if_HTIF8(int i) {while((DMA -> ISR & DMA_ISR_HTIF8) != (i & 0x1) << 30);}
void if_TCIF8(int i) {while((DMA -> ISR & DMA_ISR_TCIF8) != (i & 0x1) << 29);}
void if_GIF8 (int i) {while((DMA -> ISR & DMA_ISR_GIF8 ) != (i & 0x1) << 28);}
void if_TEIF7(int i) {while((DMA -> ISR & DMA_ISR_TEIF7) != (i & 0x1) << 27);}
void if_HTIF7(int i) {while((DMA -> ISR & DMA_ISR_HTIF7) != (i & 0x1) << 26);}
void if_TCIF7(int i) {while((DMA -> ISR & DMA_ISR_TCIF7) != (i & 0x1) << 25);}
void if_GIF7 (int i) {while((DMA -> ISR & DMA_ISR_GIF7 ) != (i & 0x1) << 24);}
void if_TEIF6(int i) {while((DMA -> ISR & DMA_ISR_TEIF6) != (i & 0x1) << 23);}
void if_HTIF6(int i) {while((DMA -> ISR & DMA_ISR_HTIF6) != (i & 0x1) << 22);}
void if_TCIF6(int i) {while((DMA -> ISR & DMA_ISR_TCIF6) != (i & 0x1) << 21);}
void if_GIF6 (int i) {while((DMA -> ISR & DMA_ISR_GIF6 ) != (i & 0x1) << 20);}
void if_TEIF5(int i) {while((DMA -> ISR & DMA_ISR_TEIF5) != (i & 0x1) << 19);}
void if_HTIF5(int i) {while((DMA -> ISR & DMA_ISR_HTIF5) != (i & 0x1) << 18);}
void if_TCIF5(int i) {while((DMA -> ISR & DMA_ISR_TCIF5) != (i & 0x1) << 17);}
void if_GIF5 (int i) {while((DMA -> ISR & DMA_ISR_GIF5 ) != (i & 0x1) << 16);}
void if_TEIF4(int i) {while((DMA -> ISR & DMA_ISR_TEIF4) != (i & 0x1) << 15);}
void if_HTIF4(int i) {while((DMA -> ISR & DMA_ISR_HTIF4) != (i & 0x1) << 14);}
void if_TCIF4(int i) {while((DMA -> ISR & DMA_ISR_TCIF4) != (i & 0x1) << 13);}
void if_GIF4 (int i) {while((DMA -> ISR & DMA_ISR_GIF4 ) != (i & 0x1) << 12);}
void if_TEIF3(int i) {while((DMA -> ISR & DMA_ISR_TEIF3) != (i & 0x1) << 11);}
void if_HTIF3(int i) {while((DMA -> ISR & DMA_ISR_HTIF3) != (i & 0x1) << 10);}
void if_TCIF3(int i) {while((DMA -> ISR & DMA_ISR_TCIF3) != (i & 0x1) <<  9);}
void if_GIF3 (int i) {while((DMA -> ISR & DMA_ISR_GIF3 ) != (i & 0x1) <<  8);}
void if_TEIF2(int i) {while((DMA -> ISR & DMA_ISR_TEIF2) != (i & 0x1) <<  7);}
void if_HTIF2(int i) {while((DMA -> ISR & DMA_ISR_HTIF2) != (i & 0x1) <<  6);}
void if_TCIF2(int i) {while((DMA -> ISR & DMA_ISR_TCIF2) != (i & 0x1) <<  5);}
void if_GIF2 (int i) {while((DMA -> ISR & DMA_ISR_GIF2 ) != (i & 0x1) <<  4);}
void if_TEIF1(int i) {while((DMA -> ISR & DMA_ISR_TEIF1) != (i & 0x1) <<  3);}
void if_HTIF1(int i) {while((DMA -> ISR & DMA_ISR_HTIF1) != (i & 0x1) <<  2);}
void if_TCIF1(int i) {while((DMA -> ISR & DMA_ISR_TCIF1) != (i & 0x1) <<  1);}
void if_GIF1 (int i) {while((DMA -> ISR & DMA_ISR_GIF1 ) != (i & 0x1) <<  0);}

// ---------------------------------------------------------------------------
// DMA IFCR functions
// ---------------------------------------------------------------------------
void DMA_IFCR (int i)  {DMA -> IFCR = i;}
void DMA_CTEIF8(void)  {DMA -> IFCR |= DMA_IFCR_CTEIF8;}
void DMA_CHTIF8(void)  {DMA -> IFCR |= DMA_IFCR_CHTIF8;}
void DMA_CTCIF8(void)  {DMA -> IFCR |= DMA_IFCR_CTCIF8;}
void DMA_CGIF8 (void)  {DMA -> IFCR |= DMA_IFCR_CGIF8 ;}
void DMA_CTEIF7(void)  {DMA -> IFCR |= DMA_IFCR_CTEIF7;}       
void DMA_CHTIF7(void)  {DMA -> IFCR |= DMA_IFCR_CHTIF7;}
void DMA_CTCIF7(void)  {DMA -> IFCR |= DMA_IFCR_CTCIF7;}
void DMA_CGIF7 (void)  {DMA -> IFCR |= DMA_IFCR_CGIF7 ;}
void DMA_CTEIF6(void)  {DMA -> IFCR |= DMA_IFCR_CTEIF6;}
void DMA_CHTIF6(void)  {DMA -> IFCR |= DMA_IFCR_CHTIF6;}
void DMA_CTCIF6(void)  {DMA -> IFCR |= DMA_IFCR_CTCIF6;}
void DMA_CGIF6 (void)  {DMA -> IFCR |= DMA_IFCR_CGIF6 ;}
void DMA_CTEIF5(void)  {DMA -> IFCR |= DMA_IFCR_CTEIF5;}
void DMA_CHTIF5(void)  {DMA -> IFCR |= DMA_IFCR_CHTIF5;}
void DMA_CTCIF5(void)  {DMA -> IFCR |= DMA_IFCR_CTCIF5;}
void DMA_CGIF5 (void)  {DMA -> IFCR |= DMA_IFCR_CGIF5 ;}
void DMA_CTEIF4(void)  {DMA -> IFCR |= DMA_IFCR_CTEIF4;}
void DMA_CHTIF4(void)  {DMA -> IFCR |= DMA_IFCR_CHTIF4;}
void DMA_CTCIF4(void)  {DMA -> IFCR |= DMA_IFCR_CTCIF4;}
void DMA_CGIF4 (void)  {DMA -> IFCR |= DMA_IFCR_CGIF4 ;}
void DMA_CTEIF3(void)  {DMA -> IFCR |= DMA_IFCR_CTEIF3;}
void DMA_CHTIF3(void)  {DMA -> IFCR |= DMA_IFCR_CHTIF3;}
void DMA_CTCIF3(void)  {DMA -> IFCR |= DMA_IFCR_CTCIF3;}
void DMA_CGIF3 (void)  {DMA -> IFCR |= DMA_IFCR_CGIF3 ;}
void DMA_CTEIF2(void)  {DMA -> IFCR |= DMA_IFCR_CTEIF2;}
void DMA_CHTIF2(void)  {DMA -> IFCR |= DMA_IFCR_CHTIF2;}
void DMA_CTCIF2(void)  {DMA -> IFCR |= DMA_IFCR_CTCIF2;}
void DMA_CGIF2 (void)  {DMA -> IFCR |= DMA_IFCR_CGIF2 ;}
void DMA_CTEIF1(void)  {DMA -> IFCR |= DMA_IFCR_CTEIF1;}
void DMA_CHTIF1(void)  {DMA -> IFCR |= DMA_IFCR_CHTIF1;}
void DMA_CTCIF1(void)  {DMA -> IFCR |= DMA_IFCR_CTCIF1;}
void DMA_CGIF1 (void)  {DMA -> IFCR |= DMA_IFCR_CGIF1 ;}

// ---------------------------------------------------------------------------
// DMA Channel select functions
// ---------------------------------------------------------------------------
DMA_Channel_TypeDef* DMA_Channel_CS(int i)
{
    switch(i)
    {
        case 1: return DMA_Channel1;
        case 2: return DMA_Channel2;
        case 3: return DMA_Channel3;
        case 4: return DMA_Channel4;
        case 5: return DMA_Channel5;
        case 6: return DMA_Channel6;
        case 7: return DMA_Channel7;
        case 8: return DMA_Channel8;
        default : return 0;
    }
}

// ---------------------------------------------------------------------------
// DMA Channel_x Global Set functions
// ---------------------------------------------------------------------------
void DMA_Channel_Set(int i, int ccr, int cndtr, int cpar, int cmar)
{
    DMA_CCR(i, ccr);
    DMA_CNDTR(i, cndtr);
    DMA_CPAR(i, cpar);
    DMA_CMAR(i, cmar);
}

// ---------------------------------------------------------------------------
// DMA Channel_x CCR functions
// ---------------------------------------------------------------------------
void DMA_CCR(int i, int value)
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFF008000) | (value & 0x00FF7FFF);
}

void DMA_REQ_ID(int i, int value)   
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFF00FFFF) | ((value & 0xFF) << 16);
}

void DMA_MEM2MEM(int i, int value)  
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFBFFF) | ((value & 0x01) << 14);
}

void DMA_PL(int i, int value)       
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFCFFF) | ((value & 0x03) << 12);
}

void DMA_MSIZE(int i, int value)    
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFF3FF) | ((value & 0x03) << 10);
}

void DMA_PSIZE(int i, int value)    
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFFCFF) | ((value & 0x03) <<  8);
}

void DMA_MINC(int i, int value)     
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFFF7F) | ((value & 0x01) <<  7);
}

void DMA_PINC(int i, int value)     
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFFFBF) | ((value & 0x01) <<  6);
}
void DMA_CIRC(int i, int value)     
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFFFDF) | ((value & 0x01) <<  5);
}
void DMA_DIR(int i, int value)      
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFFFEF) | ((value & 0x01) <<  4);
}
void DMA_TEIE(int i, int value)     
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFFFF7) | ((value & 0x01) <<  3);
}
void DMA_HTIE(int i, int value)     
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFFFFB) | ((value & 0x01) <<  2);
}
void DMA_TCIE(int i, int value)     
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFFFFD) | ((value & 0x01) <<  1);
}
void DMA_EN(int i, int value)       
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CCR = (ch -> CCR & 0xFFFFFFFE) | ((value & 0x01) <<  0);
}

// ---------------------------------------------------------------------------
// DMA Channel_x CNDTR functions
// ---------------------------------------------------------------------------
void DMA_CNDTR(int i, int value)    
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CNDTR = (ch -> CNDTR & 0xFFFF0000) | (value & 0xFFFF);
}

// ---------------------------------------------------------------------------
// DMA Channel_x CPAR functions
// ---------------------------------------------------------------------------
void DMA_CPAR(int i, int value)     
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CPAR  = (ch -> CPAR  & 0x0) | (value & 0xFFFFFFFF);
}

// ---------------------------------------------------------------------------
// DMA Channel_x CMAR functions
// ---------------------------------------------------------------------------
void DMA_CMAR(int i, int value)     
{
    DMA_Channel_TypeDef *ch = DMA_Channel_CS(i);
    ch -> CMAR  = (ch -> CMAR  & 0x0) | (value & 0xFFFFFFFF);
}
