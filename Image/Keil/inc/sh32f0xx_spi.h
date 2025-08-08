#ifndef __SH32F0XX_SPI_H
#define __SH32F0XX_SPI_H
#include "sh32f0xx.h"

void SPI_CTRLR0  (uint32_t i);
void SPI_DFS32   (uint32_t i);
void SPI_FRF     (uint32_t i);
void SPI_SCPH    (uint32_t i);
void SPI_SCPOL   (uint32_t i);
void SPI_TMOD    (uint32_t i);
void SPI_SLV_OE  (uint32_t i);
void SPI_SRL     (uint32_t i);
void SPI_CFS     (uint32_t i);
void SPI_SPI_FRF (uint32_t i);
void SPI_SSTE    (uint32_t i);
void SPI_SECONV  (uint32_t i);

void SPI_CTRLR1 (uint32_t i);

void SPI_SSIENR (uint32_t i);

void SPI_MWCR  (uint32_t i); 
void SPI_MHS   (uint32_t i); 
void SPI_MDD   (uint32_t i);
void SPI_MWMOD (uint32_t i);

void SPI_SER    (uint32_t i);

void SPI_BAUDR  (uint32_t i);

void SPI_TXFTLR (uint32_t i);

void SPI_RXFTLR (uint32_t i);

void SPI_IMR   (uint32_t i); 
void SPI_MSTIM (uint32_t i); 
void SPI_RXFIM (uint32_t i); 
void SPI_RXOIM (uint32_t i); 
void SPI_RXUIM (uint32_t i); 
void SPI_TXOIM (uint32_t i); 
void SPI_TXEIM (uint32_t i); 

void SPI_DR (uint32_t i);

void SPI_SPI_CTRLR0  (uint32_t i);
void SPI_TRANS_TYPE  (uint32_t i);
void SPI_ADDR_L      (uint32_t i);
void SPI_INST_L      (uint32_t i);
void SPI_WAIT_CYCLES (uint32_t i);

void if_BUSY (uint32_t i);
void if_TFNF (uint32_t i);
void if_TFE  (uint32_t i);
void if_RFNE (uint32_t i);
void if_RFF  (uint32_t i);
void if_TXE  (uint32_t i);
void if_DCOL (uint32_t i);

// SSIENR
void ON(void);
void OFF(void);

// Flash Operation
void Flash_05h(int bit, int times);
void Flash_38h(void);
void Flash_90h(int wait_cycles);
void Flash_06h(void);
void Flash_98h(void);
void Flash_C7h(void);
void Flash_60h(void);
void Flash_20h(int addr);
void Flash_0Bh(int addr, int wait_cycles, int ctrlr1);
void Flash_3Bh(int addr, int wait_cycles, int ctrlr1);
void Flash_FFh(void);

// Tool
void dly(int value);
void SSI_SR(int bit,int value);
//void RD_SR(int bit);
//void RD_ISR(int bit);
#endif
