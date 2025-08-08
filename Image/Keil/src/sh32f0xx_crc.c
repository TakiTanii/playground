#include "sh32f0xx_crc.h"

void CRC_DR  (uint32_t i) {CRC -> DR  = i;}

void CRC_MIR (uint32_t i) {CRC -> MIR = i;}

void CRC_CR  (uint32_t i) {CRC -> CR = i;}
void CRC_RVB (uint32_t i) {CRC -> CR = (CRC -> CR & ~CRC_CR_RVB) | ((i & 0x1) << 7);}
void CRC_RO  (uint32_t i) {CRC -> CR = (CRC -> CR & ~CRC_CR_RO ) | ((i & 0x1) << 6);}
void CRC_BEO (uint32_t i) {CRC -> CR = (CRC -> CR & ~CRC_CR_BEO) | ((i & 0x1) << 5);}
void CRC_BEI (uint32_t i) {CRC -> CR = (CRC -> CR & ~CRC_CR_BEI) | ((i & 0x1) << 4);}
void CRC_RI  (uint32_t i) {CRC -> CR = (CRC -> CR & ~CRC_CR_RI ) | ((i & 0x1) << 1);}
void CRC_RST (uint32_t i) {CRC -> CR = (CRC -> CR & ~CRC_CR_RST) | ((i & 0x1) << 0);}
