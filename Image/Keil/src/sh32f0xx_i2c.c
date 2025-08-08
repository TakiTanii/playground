#include "sh32f0xx_i2c.h"

void I2C_INTEN        (uint32_t i) {I2C1 -> INTEN = i;}
void I2C_CMPL_EN      (uint32_t i) {I2C1 -> INTEN = (I2C1 -> INTEN & ~I2C_INTEN_CMPL     ) | ((i & 0x1) << 9);}
void I2C_BYTERECV_EN  (uint32_t i) {I2C1 -> INTEN = (I2C1 -> INTEN & ~I2C_INTEN_BYTERECV ) | ((i & 0x1) << 8);}
void I2C_BYTETRANS_EN (uint32_t i) {I2C1 -> INTEN = (I2C1 -> INTEN & ~I2C_INTEN_BYTETRANS) | ((i & 0x1) << 7);}
void I2C_START_EN     (uint32_t i) {I2C1 -> INTEN = (I2C1 -> INTEN & ~I2C_INTEN_START    ) | ((i & 0x1) << 6);}
void I2C_STOP_EN      (uint32_t i) {I2C1 -> INTEN = (I2C1 -> INTEN & ~I2C_INTEN_STOP     ) | ((i & 0x1) << 5);}
void I2C_ARBLOSE_EN   (uint32_t i) {I2C1 -> INTEN = (I2C1 -> INTEN & ~I2C_INTEN_ARBLOSE  ) | ((i & 0x1) << 4);}
void I2C_ADDRHIT_EN   (uint32_t i) {I2C1 -> INTEN = (I2C1 -> INTEN & ~I2C_INTEN_ADDRHIT  ) | ((i & 0x1) << 3);}
void I2C_FIFOHALF_EN  (uint32_t i) {I2C1 -> INTEN = (I2C1 -> INTEN & ~I2C_INTEN_FIFOHALF ) | ((i & 0x1) << 2);}
void I2C_FIFOFULL_EN  (uint32_t i) {I2C1 -> INTEN = (I2C1 -> INTEN & ~I2C_INTEN_FIFOFULL ) | ((i & 0x1) << 1);}
void I2C_FIFOEMPTY_EN (uint32_t i) {I2C1 -> INTEN = (I2C1 -> INTEN & ~I2C_INTEN_FIFOEMPTY) | ((i & 0x1) << 0);}

void I2C_STATUS       (uint32_t i) {I2C1 -> STATUS = i;}
void I2C_CMPL_CF      (uint32_t i) {I2C1 -> STATUS = (I2C1 -> STATUS & ~I2C_STATUS_CMPL     ) | ((i & 0x1) << 9);}
void I2C_BYTERECV_CF  (uint32_t i) {I2C1 -> STATUS = (I2C1 -> STATUS & ~I2C_STATUS_BYTERECV ) | ((i & 0x1) << 8);}
void I2C_BYTETRANS_CF (uint32_t i) {I2C1 -> STATUS = (I2C1 -> STATUS & ~I2C_STATUS_BYTETRANS) | ((i & 0x1) << 7);}
void I2C_START_CF     (uint32_t i) {I2C1 -> STATUS = (I2C1 -> STATUS & ~I2C_STATUS_START    ) | ((i & 0x1) << 6);}
void I2C_STOP_CF      (uint32_t i) {I2C1 -> STATUS = (I2C1 -> STATUS & ~I2C_STATUS_STOP     ) | ((i & 0x1) << 5);}
void I2C_ARBLOSE_CF   (uint32_t i) {I2C1 -> STATUS = (I2C1 -> STATUS & ~I2C_STATUS_ARBLOSE  ) | ((i & 0x1) << 4);}
void I2C_ADDRHIT_CF   (uint32_t i) {I2C1 -> STATUS = (I2C1 -> STATUS & ~I2C_STATUS_ADDRHIT  ) | ((i & 0x1) << 3);}

void I2C_ADDR (uint32_t i) {I2C1 -> ADDR = i;}

void I2C_DATA (uint32_t i) {I2C1 -> DATA = i;}

void I2C_CTRL        (uint32_t i) {I2C1 -> CTRL = i;}
void I2C_PHASE_START (uint32_t i) {I2C1 -> CTRL = (I2C1 -> CTRL & ~I2C_CTRL_PHASE_START) | ((i & 0x1 ) << 12);}
void I2C_PHASE_ADDR  (uint32_t i) {I2C1 -> CTRL = (I2C1 -> CTRL & ~I2C_CTRL_PHASE_ADDR ) | ((i & 0x1 ) << 11);}
void I2C_PHASE_DATA  (uint32_t i) {I2C1 -> CTRL = (I2C1 -> CTRL & ~I2C_CTRL_PHASE_DATA ) | ((i & 0x1 ) << 10);}
void I2C_PHASE_STOP  (uint32_t i) {I2C1 -> CTRL = (I2C1 -> CTRL & ~I2C_CTRL_PHASE_STOP ) | ((i & 0x1 ) <<  9);}
void I2C_DIR         (uint32_t i) {I2C1 -> CTRL = (I2C1 -> CTRL & ~I2C_CTRL_DIR        ) | ((i & 0x1 ) <<  8);}
void I2C_DATACNT     (uint32_t i) {I2C1 -> CTRL = (I2C1 -> CTRL & ~I2C_CTRL_DATACNT    ) | ((i & 0xFF) <<  0);}

void I2C_CMD (uint32_t i) {I2C1 -> CMD = i;}

void I2C_SETUP      (uint32_t i) {I2C1 -> SETUP = i;}
void I2C_T_SCLRATIO (uint32_t i) {I2C1 -> SETUP = (I2C1 -> SETUP & ~I2C_SETUP_T_SCLRATIO) | ((i & 0x1) << 5);}
void I2C_NOSTRETCH  (uint32_t i) {I2C1 -> SETUP = (I2C1 -> SETUP & ~I2C_SETUP_NOSTRETCH ) | ((i & 0x1) << 4);}
void I2C_DMAEN      (uint32_t i) {I2C1 -> SETUP = (I2C1 -> SETUP & ~I2C_SETUP_DMAEN     ) | ((i & 0x1) << 3);}
void I2C_MASTER     (uint32_t i) {I2C1 -> SETUP = (I2C1 -> SETUP & ~I2C_SETUP_MASTER    ) | ((i & 0x1) << 2);}
void I2C_ADDRESSING (uint32_t i) {I2C1 -> SETUP = (I2C1 -> SETUP & ~I2C_SETUP_ADDRESSING) | ((i & 0x1) << 1);}
void I2C_IICEN      (uint32_t i) {I2C1 -> SETUP = (I2C1 -> SETUP & ~I2C_SETUP_IICEN     ) | ((i & 0x1) << 0);}

void I2C_TPM (uint32_t i) {I2C1 -> TPM = i;}

void I2C_TIMING  (uint32_t i) {I2C1 -> TIMING = i;}
void I2C_T_SUDAT (uint32_t i) {I2C1 -> TIMING = (I2C1 -> TIMING & ~I2C_TIMING_T_SUDAT) | ((i & 0xFF) << 24);}
void I2C_T_HDDAT (uint32_t i) {I2C1 -> TIMING = (I2C1 -> TIMING & ~I2C_TIMING_T_SP   ) | ((i & 0xFF) << 19);}
void I2C_T_SP    (uint32_t i) {I2C1 -> TIMING = (I2C1 -> TIMING & ~I2C_TIMING_T_HDDAT) | ((i & 0x1F) << 11);}
void I2C_T_SCLHI (uint32_t i) {I2C1 -> TIMING = (I2C1 -> TIMING & ~I2C_TIMING_T_SCLHI) | ((i & 0x7FF) << 0);}

void I2C_MASK (uint32_t i) {I2C1 -> MASK = i;}
