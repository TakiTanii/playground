#include "sh32f0xx_spi.h"

void SPI_CTRLR0  (uint32_t i) {SPI1 -> CTRLR0 = i;}
void SPI_DFS32   (uint32_t i) {SPI1 -> CTRLR0 = (SPI1 -> CTRLR0 & ~SPI_CTRLR0_DFS    ) | ((i & 0x1F) << 16);}         
void SPI_FRF     (uint32_t i) {SPI1 -> CTRLR0 = (SPI1 -> CTRLR0 & ~SPI_CTRLR0_FRF    ) | ((i & 0x3) << 4);}  
void SPI_SCPH    (uint32_t i) {SPI1 -> CTRLR0 = (SPI1 -> CTRLR0 & ~SPI_CTRLR0_SCPH   ) | ((i & 0x1) << 6);}  
void SPI_SCPOL   (uint32_t i) {SPI1 -> CTRLR0 = (SPI1 -> CTRLR0 & ~SPI_CTRLR0_SCPOL  ) | ((i & 0x1) << 7);}  
void SPI_TMOD    (uint32_t i) {SPI1 -> CTRLR0 = (SPI1 -> CTRLR0 & ~SPI_CTRLR0_TMOD   ) | ((i & 0x3) << 8);}  
void SPI_SLV_OE  (uint32_t i) {SPI1 -> CTRLR0 = (SPI1 -> CTRLR0 & ~SPI_CTRLR0_SLV_OE ) | ((i & 0x1) << 10);} 
void SPI_SRL     (uint32_t i) {SPI1 -> CTRLR0 = (SPI1 -> CTRLR0 & ~SPI_CTRLR0_SRL    ) | ((i & 0x1) << 11);} 
void SPI_CFS     (uint32_t i) {SPI1 -> CTRLR0 = (SPI1 -> CTRLR0 & ~SPI_CTRLR0_CFS    ) | ((i & 0xF) << 12);} 
void SPI_SPI_FRF (uint32_t i) {SPI1 -> CTRLR0 = (SPI1 -> CTRLR0 & ~SPI_CTRLR0_SPI_FRF) | ((i & 0x3) << 21);} 
void SPI_SSTE    (uint32_t i) {SPI1 -> CTRLR0 = (SPI1 -> CTRLR0 & ~SPI_CTRLR0_SSTE   ) | ((i & 0x1) << 24);} 
void SPI_SECONV  (uint32_t i) {SPI1 -> CTRLR0 = (SPI1 -> CTRLR0 & ~SPI_CTRLR0_SECONV ) | ((i & 0x1) << 25);}

void SPI_CTRLR1 (uint32_t i) {SPI1 -> CTRLR1 = i;}

void SPI_SSIENR (uint32_t i) {SPI1 -> SSIENR = i;}

void SPI_MWCR  (uint32_t i) {SPI1 -> MWCR = i;}
void SPI_MHS   (uint32_t i) {SPI1 -> MWCR = (SPI1 -> MWCR & ~SPI_MWCR_MHS  ) | ((i & 0x1) << 2);}
void SPI_MDD   (uint32_t i) {SPI1 -> MWCR = (SPI1 -> MWCR & ~SPI_MWCR_MDD  ) | ((i & 0x1) << 1);}
void SPI_MWMOD (uint32_t i) {SPI1 -> MWCR = (SPI1 -> MWCR & ~SPI_MWCR_MWMOD) | ((i & 0x1) << 0);}

void SPI_SER    (uint32_t i) {SPI1 -> SER = i;}

void SPI_BAUDR  (uint32_t i) {SPI1 -> BAUDR = i;}

void SPI_TXFTLR (uint32_t i) {SPI1 -> TXFTLR = i;}

void SPI_RXFTLR (uint32_t i) {SPI1 -> RXFTLR = i;}

void SPI_IMR   (uint32_t i) {SPI1 -> IMR = i;}
void SPI_MSTIM (uint32_t i) {SPI1 -> IMR = (SPI1 -> IMR & ~SPI_IMR_MSTIM) | ((i & 0x1) << 5);}
void SPI_RXFIM (uint32_t i) {SPI1 -> IMR = (SPI1 -> IMR & ~SPI_IMR_RXFIM) | ((i & 0x1) << 4);}
void SPI_RXOIM (uint32_t i) {SPI1 -> IMR = (SPI1 -> IMR & ~SPI_IMR_RXOIM) | ((i & 0x1) << 3);}
void SPI_RXUIM (uint32_t i) {SPI1 -> IMR = (SPI1 -> IMR & ~SPI_IMR_RXUIM) | ((i & 0x1) << 2);}
void SPI_TXOIM (uint32_t i) {SPI1 -> IMR = (SPI1 -> IMR & ~SPI_IMR_TXOIM) | ((i & 0x1) << 1);}
void SPI_TXEIM (uint32_t i) {SPI1 -> IMR = (SPI1 -> IMR & ~SPI_IMR_TXEIM) | ((i & 0x1) << 0);}

void SPI_DR (uint32_t i) {SPI1 -> DR[0] = i;}

void SPI_SPI_CTRLR0  (uint32_t i) {SPI1 -> SPI_CTRLR0 = i;}
void SPI_TRANS_TYPE  (uint32_t i) {SPI1 -> SPI_CTRLR0 = (SPI1 -> SPI_CTRLR0 & ~SPI_SPI_CTRLR0_TRANS_TYPE ) | ((i & 0x3 ) << 0);}
void SPI_ADDR_L      (uint32_t i) {SPI1 -> SPI_CTRLR0 = (SPI1 -> SPI_CTRLR0 & ~SPI_SPI_CTRLR0_ADDR_L     ) | ((i & 0xF ) << 2);}
void SPI_INST_L      (uint32_t i) {SPI1 -> SPI_CTRLR0 = (SPI1 -> SPI_CTRLR0 & ~SPI_SPI_CTRLR0_INST_L     ) | ((i & 0x3 ) << 8);}
void SPI_WAIT_CYCLES (uint32_t i) {SPI1 -> SPI_CTRLR0 = (SPI1 -> SPI_CTRLR0 & ~SPI_SPI_CTRLR0_WAIT_CYCLES) | ((i & 0x1F) << 11);}

// SSI: Check Status Register Bit  
void if_BUSY (uint32_t i) {while(((SPI1 -> SR >> 0) & 0x1) != i);}
void if_TFNF (uint32_t i) {while(((SPI1 -> SR >> 1) & 0x1) != i);}
void if_TFE  (uint32_t i) {while(((SPI1 -> SR >> 2) & 0x1) != i);}
void if_RFNE (uint32_t i) {while(((SPI1 -> SR >> 3) & 0x1) != i);}
void if_RFF  (uint32_t i) {while(((SPI1 -> SR >> 4) & 0x1) != i);}
void if_TXE  (uint32_t i) {while(((SPI1 -> SR >> 5) & 0x1) != i);}
void if_DCOL (uint32_t i) {while(((SPI1 -> SR >> 6) & 0x1) != i);}

void SSI_SR(int bit,int value) 
{
    while (((SPI1 -> SR) & (0x01 << bit)) != (value << bit));
}

void ON (void) {SPI_SSIENR(1);}
  
void OFF (void) {if_BUSY(0); SPI_SSIENR(0);}

void dly (int value) {for (int i=0 ; i<value*4 ; i++) __NOP();}

void Flash_05h(int bit,int times)
{
    int cmd = 0x05;
    int bit2rd = 0x01 << bit;
    int tmod = 0x02;
      
    OFF();
    SPI_TMOD       (tmod);
    SPI_ADDR_L     (0x00);
    SPI_WAIT_CYCLES(0x00);

    do
    {  
      ON();
      SPI1 -> DR[0] = cmd;
      dly(SPI1 -> BAUDR);
      //OFF();
      dly(times);
      //SPI1 -> DR[0];
    } while ((SPI1->DR[0] & bit2rd) != 0);
    OFF();
}

// Flash: (06h) Write Enable 
void Flash_06h()
{
    // print_led("  - Write Enable\n");
    int cmd = 0x06;

    OFF();
    SPI_TMOD(0x01); 
    SPI_ADDR_L(0x00);
    ON();

    SPI1 -> DR[0] = cmd;
    dly(SPI1 -> BAUDR);
    OFF();
} 

// Flash: (0Bh) Fast Read
void Flash_0Bh(int addr, int wait_cycles, int ctrlr1)
{
    //printf("  - Fast Read\n");
    int cmd = 0x0B;
    int RD0[3] = {cmd, addr >> 8, addr & 0xFF};
    int tmod = 0x02;
    OFF();
    SPI_TMOD(tmod);
    SPI_ADDR_L(0x06);
    SPI_WAIT_CYCLES(wait_cycles);
    SPI1 -> CTRLR1 = ctrlr1;
    ON();

    for (int i=0;i<3;i++)
    {
        SPI1 -> DR[i+1] = RD0[i];
    }
   }

// Flash: (3Bh) Fast Read
void Flash_3Bh(int addr, int wait_cycles, int ctrlr1)
{
    //printf("  - Fast Read Dual\n");
    int cmd = 0x03B;
    int RD0[3] = {cmd, addr >> 8, addr & 0xFF};

    OFF();
    SPI_TMOD(0x02);
    SPI_ADDR_L(0x06);
    SPI_WAIT_CYCLES(wait_cycles);
    SPI1 -> CTRLR1 = ctrlr1;
    ON();

    for (int i=0;i<3;i++)
    {
        SPI1 -> DR[i+1] = RD0[i];
    }
}

// Flash: (20h) Sector Erase 
void Flash_20h(int addr)
{
    //print_led("  - Sector Erase\n");
    int cmd = 0x20;
    int SE[3] = {cmd, addr >> 8, addr & 0xFF};

    OFF();
    SPI_ADDR_L(0x04);
    ON();

    for (int i=0;i<3;i++)
    { 
        SPI1 -> DR[i+3] = SE[i];
    }

    dly(SPI1 -> BAUDR);
    OFF();
}  

// Flash: (38h) Enter QPI Mode 
void Flash_38h()
{
//    print_led("  - Enter QPI Mode\n");
    int cmd = 0x38;
 
    OFF();
    SPI_TRANS_TYPE(0x01);
    SPI_ADDR_L(0x00);
    ON();

    SPI1 -> DR[0] = cmd;
    // dly(SPI1 -> BAUDR);
    SSI_SR(0,1);
    OFF();
    SPI_TRANS_TYPE    (0x02); 
    SPI_ADDR_L(0x06);
}

// Flash: (60h) Chip Erase 
void Flash_60h()
{
//    print_led("  - Chip Erase\n");
    int cmd = 0x60;

    OFF();ON();

    SPI1 -> DR[0] = cmd;
    dly(SPI1 -> BAUDR);
    OFF();
}

// Flash: (90h) Read Manufacturer / Device ID
void Flash_90h(int wait_cycles)
{
    // printf("  - Read Manufacturer / Device ID(%d)\n",wait_cycles); 
    int cmd = 0x90;
    int RID[3] = {cmd, 0x00, 0x00};
    OFF();
    SPI_WAIT_CYCLES(wait_cycles);
    ON();

    for (int i=0;i<3;i++)
    { 
        SPI1 -> DR[i+3] = RID[i];
    }
    OFF();
}

// Flash: (98h) Global Unlock/Sector Unlock 
void Flash_98h()
{
    // print_led("  - Global Block/Sector Unlock\n");
    int cmd = 0x98;
    OFF();
    SPI_TMOD(0x01); 
    SPI_ADDR_L(0x00);
    ON();

    SPI1 -> DR[0] = cmd;
    dly(SPI1 -> BAUDR);
    OFF();
}    

// Flash: (C7h) Chip Erase 
void Flash_C7h()
{
//    print_led("  - Chip Erase\n");
    int cmd = 0xC7;

    OFF();ON();

    SPI1 -> DR[0] = cmd;
    dly(SPI1 -> BAUDR);
    OFF();
}

// Flash: (FFh) Exit QSPI 
void Flash_FFh()
{
    int cmd = 0xFF;

    OFF();ON();

    SPI1 -> DR[0] = cmd;
    dly(SPI1 -> BAUDR);
    OFF();
}
// SSI: Output Interrupt Status Register bit
/*
void RD_ISR (int bit)
{
    if (bit & 0x20)
    {
        if (((SPI1->ISR)&0x20) == 0)
            print_led("  ISR[5] | No Multi-Mst Intr\n");
        else 
            print_led("  ISR[5] | Multi-Mst Intr\n");
    }
    if (bit & 0x10)
    {
        if (((SPI1->ISR)&0x10) == 0) 
            print_led("  ISR[4] | No Rx-Full Intr\n");
        else 
            print_led("  ISR[4] | Rx-Full Intr\n");
    }
    if (bit & 0x08)
    {
        if (((SPI1->ISR)&0x8) == 0)
            print_led("  ISR[3] | No Rx-Empty Intr\n");
        else 
            print_led("  ISR[3] | Rx-Empty Intr\n");
    }    
    if (bit & 0x04)
    {
        if (((SPI1->ISR)&0x4) == 0)
            print_led("  ISR[2] | No Rx-Udflow Intr\n");
        else 
            print_led("  ISR[2] | Rx-Udflow Intr\n");
    }
    if (bit & 0x02)
    {
        if (((SPI1->ISR)&0x2) == 0)
            print_led("  ISR[1] | No Tx-Ovflow Intr\n");
        else 
            print_led("  ISR[1] | Tx-Ovflow Intr\n");
    } 
    if (bit & 0x01)
    {
        if (((SPI1->ISR)&0x1) == 0)
            print_led("  ISR[0] | No Tx-Empty Intr\n");
        else 
            print_led("  ISR[0] | Tx-Empty Intr\n");
    }
}

// SSI: Output Status Register bit
void RD_SR(int bit)
{
    if (bit & 0b1000000)
    {
        if (((SPI1->SR)&0x40) == 0)
            print_led("  SR [6] | No Data Coll Error\n");
        else 
            print_led("  SR [6] | Data Coll Error\n");
    }
    if (bit & 0b0100000)
    {
        if (((SPI1->SR)&0x20) == 0)
            print_led("  SR [5] | No Trans Error\n");
        else 
            print_led("  SR [5] | Trans Error\n");
    }
    if (bit & 0b0010000)
    {
        if (((SPI1->SR)&0x10) == 0) 
            print_led("  SR [4] | Not Full (Rx-FIFO)\n");
        else 
            print_led("  SR [4] | Full (Rx-FIFO)\n");
    }
    if (bit & 0b0001000)
    {
        if (((SPI1->SR)&0x8) == 0)
            print_led("  SR [3] | Empty (Rx-FIFO)\n");
        else 
            print_led("  SR [3] | Not Empty (Rx-FIFO)\n");
    }    
    if (bit & 0b0000100)
    {
        if (((SPI1->SR)&0x4) == 0)
            print_led("  SR [2] | Not Empty (Tx-FIFO)\n");
        else 
            print_led("  SR [2] | Empty (Tx-FIFO)\n");
    }
    if (bit & 0b0000010)
    {
        if (((SPI1->SR)&0x2) == 0)
            print_led("  SR [1] | Full (Tx-FIFO)\n");
        else 
            print_led("  SR [1] | Not Full (Tx-FIFO)\n");
    } 
    if (bit & 0b0000001)
    {
        if ((SPI1->SR & 0x1) == 0)
            print_led("  SR [0] | Idel/Disabled\n");
        else 
            print_led("  SR [0] | Busy\n");
    }
}
*/

