// Includes ------------------------------------------------------------------
#include "sh32f0xx.h"

// Private functions ---------------------------------------------------------
// ---------------------------------------------------------------------------
// DMA Clock Enable functions
// ---------------------------------------------------------------------------
// Note: This function is used to turn on/off DMA clock enable
//       i could be set (0/1)
// ---------------------------------------------------------------------------
void DMA_CLK_EN (int i);

// ---------------------------------------------------------------------------
// DMA ISR functions
// ---------------------------------------------------------------------------
// Note: These functions are used to wait ISR value equals to i;
//       i could be set (0/1)
// ---------------------------------------------------------------------------
void if_TEIF8 (int i);
void if_HTIF8 (int i);
void if_TCIF8 (int i);
void if_GIF8  (int i);
void if_TEIF7 (int i);
void if_HTIF7 (int i);
void if_TCIF7 (int i);
void if_GIF7  (int i);
void if_TEIF6 (int i);
void if_HTIF6 (int i);
void if_TCIF6 (int i);
void if_GIF6  (int i);
void if_TEIF5 (int i);
void if_HTIF5 (int i);
void if_TCIF5 (int i);
void if_GIF5  (int i);
void if_TEIF4 (int i);
void if_HTIF4 (int i);
void if_TCIF4 (int i);
void if_GIF4  (int i);
void if_TEIF3 (int i);
void if_HTIF3 (int i);
void if_TCIF3 (int i);
void if_GIF3  (int i);
void if_TEIF2 (int i);
void if_HTIF2 (int i);
void if_TCIF2 (int i);
void if_GIF2  (int i);
void if_TEIF1 (int i);
void if_HTIF1 (int i);
void if_TCIF1 (int i);
void if_GIF1  (int i);

// ---------------------------------------------------------------------------
// DMA IFCR functions
// ---------------------------------------------------------------------------
// Note: These functions are used to set 1 to clear interrupt
//       i could be set (0x0000_0000-0xFFFF_FFFF)
// ---------------------------------------------------------------------------
void DMA_IFCR   (int i);
void DMA_CTEIF8 (void);
void DMA_CHTIF8 (void); 
void DMA_CTCIF8 (void); 
void DMA_CGIF8  (void); 
void DMA_CTEIF7 (void);
void DMA_CHTIF7 (void);  
void DMA_CTCIF7 (void);  
void DMA_CGIF7  (void);   
void DMA_CTEIF6 (void);  
void DMA_CHTIF6 (void);  
void DMA_CTCIF6 (void);  
void DMA_CGIF6  (void);   
void DMA_CTEIF5 (void);  
void DMA_CHTIF5 (void);  
void DMA_CTCIF5 (void); 
void DMA_CGIF5  (void);
void DMA_CTEIF4 (void);
void DMA_CHTIF4 (void);
void DMA_CTCIF4 (void);
void DMA_CGIF4  (void);
void DMA_CTEIF3 (void);
void DMA_CHTIF3 (void);
void DMA_CTCIF3 (void);
void DMA_CGIF3  (void);
void DMA_CTEIF2 (void);
void DMA_CHTIF2 (void);
void DMA_CTCIF2 (void);
void DMA_CGIF2  (void);
void DMA_CTEIF1 (void);
void DMA_CHTIF1 (void);
void DMA_CTCIF1 (void);
void DMA_CGIF1  (void);

// ---------------------------------------------------------------------------
// DMA Channel select functions
// ---------------------------------------------------------------------------
// Note: This function is used to select DMA Channel
//       i could be set (1-8)
// ---------------------------------------------------------------------------
DMA_Channel_TypeDef* DMA_Channel_CS(int i);

// ---------------------------------------------------------------------------
// DMA Channel_x Global Set functions
// ---------------------------------------------------------------------------
// Note: This function is used to set whole register of DMA channel_x
//       i     could be set (1-8)
//       ccr   could be set (0x0000_0000-0xFFFF_FFFF), see document for more details
//       cndtr could be set (0x0000_0000-0x0000_FFFF), see document for more details
//       cpar  could be set (0x0000_0000-0xFFFF_FFFF), see document for more details
//       cmar  could be set (0x0000_0000-0xFFFF_FFFF), see document for more details
// ---------------------------------------------------------------------------
void DMA_Channel_Set(int i, int ccr, int cndtr, int cpar, int cmar);

// ---------------------------------------------------------------------------
// DMA Channel_x CCR functions
// ---------------------------------------------------------------------------
// Note: These functions are used to set DMA Channel_x CCR register
//       i     could be set (1-8)
//      value of CCR could be set (0x0000_0000-0xFFFF_FFFF), see document for more details
// ---------------------------------------------------------------------------
void DMA_CCR     (int i, int value);
void DMA_REQ_ID  (int i, int value);
void DMA_MEM2MEM (int i, int value);
void DMA_PL      (int i, int value);
void DMA_MSIZE   (int i, int value);
void DMA_PSIZE   (int i, int value);
void DMA_MINC    (int i, int value);
void DMA_PINC    (int i, int value);
void DMA_CIRC    (int i, int value);
void DMA_DIR     (int i, int value);
void DMA_TEIE    (int i, int value);
void DMA_HTIE    (int i, int value);
void DMA_TCIE    (int i, int value);
void DMA_EN      (int i, int value);

// ---------------------------------------------------------------------------
// DMA Channel_x CNDTR functions
// ---------------------------------------------------------------------------
// Note: This function is used to set DMA Channel_x CNDTR register
//       i     could be set (1-8)
//       value could be set (0x0000_0000-0x0000_FFFF), see document for more details
// ---------------------------------------------------------------------------
void DMA_CNDTR (int i, int value);

// ---------------------------------------------------------------------------
// DMA Channel_x CPAR functions
// ---------------------------------------------------------------------------
// Note: This function is used to set DMA Channel_x CPAR register
//       i     could be set (1-8)
//       value could be set (0x0000_0000-0xFFFF_FFFF), see document for more details
// ---------------------------------------------------------------------------
void DMA_CPAR (int i, int value);

// ---------------------------------------------------------------------------
// DMA Channel_x CMAR functions
// ---------------------------------------------------------------------------
// Note: This function is used to set DMA Channel_x CMAR register
//       i     could be set (1-8)
//       value could be set (0x0000_0000-0xFFFF_FFFF), see document for more details
// ---------------------------------------------------------------------------
void DMA_CMAR (int i, int value); 
