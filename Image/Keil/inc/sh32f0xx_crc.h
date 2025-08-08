#ifndef __SH32F0XX_CRC_H
#define __SH32F0XX_CRC_H
#include "sh32f0xx.h"

void CRC_DR  (uint32_t i);

void CRC_MIR (uint32_t i);

void CRC_CR  (uint32_t i);
void CRC_RVB (uint32_t i);
void CRC_RO  (uint32_t i);
void CRC_BEO (uint32_t i);
void CRC_BEI (uint32_t i);
void CRC_RI  (uint32_t i);
void CRC_RST (uint32_t i);

#endif 
