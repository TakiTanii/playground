#ifndef __SH32F0XX_I2C_H
#define __SH32F0XX_I2C_H
#include "sh32f0xx.h"

void I2C_INTEN        (uint32_t i);
void I2C_CMPL_EN      (uint32_t i);
void I2C_BYTERECV_EN  (uint32_t i);
void I2C_BYTETRANS_EN (uint32_t i);
void I2C_START_EN     (uint32_t i);
void I2C_STOP_EN      (uint32_t i);
void I2C_ARBLOSE_EN   (uint32_t i);
void I2C_ADDRHIT_EN   (uint32_t i);
void I2C_FIFOHALF_EN  (uint32_t i);
void I2C_FIFOFULL_EN  (uint32_t i);
void I2C_FIFOEMPTY_EN (uint32_t i);

void I2C_STATUS       (uint32_t i);
void I2C_CMPL_CF      (uint32_t i);
void I2C_BYTERECV_CF  (uint32_t i);
void I2C_BYTETRANS_CF (uint32_t i);
void I2C_START_CF     (uint32_t i);
void I2C_STOP_CF      (uint32_t i);
void I2C_ARBLOSE_CF   (uint32_t i);
void I2C_ADDRHIT_CF   (uint32_t i);

void I2C_ADDR (uint32_t i);

void I2C_DATA (uint32_t i);

void I2C_CTRL        (uint32_t i);
void I2C_PHASE_START (uint32_t i);
void I2C_PHASE_ADDR  (uint32_t i);
void I2C_PHASE_DATA  (uint32_t i);
void I2C_PHASE_STOP  (uint32_t i);
void I2C_DIR         (uint32_t i);
void I2C_DATACNT     (uint32_t i);

void I2C_CMD (uint32_t i);

void I2C_SETUP      (uint32_t i);
void I2C_T_SCLRATIO (uint32_t i);
void I2C_NOSTRETCH  (uint32_t i);
void I2C_DMAEN      (uint32_t i);
void I2C_MASTER     (uint32_t i);
void I2C_ADDRESSING (uint32_t i);
void I2C_IICEN      (uint32_t i);

void I2C_TPM (uint32_t i);

void I2C_TIMING  (uint32_t i);
void I2C_T_SUDAT (uint32_t i);
void I2C_T_SP    (uint32_t i);
void I2C_T_HDDAT (uint32_t i);
void I2C_T_SCLHI (uint32_t i);

void I2C_MASK (uint32_t i);

#endif
