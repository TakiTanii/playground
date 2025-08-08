/**
  ******************************************************************************
  * @file    sh32f0xx_lptim.h
  * @author  MCD Application Team
  * @version V1.1.1
  * @date    31-July-2013
  * @brief   This file contains all the functions prototypes for the RCC
  *          firmware library.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#ifndef __SH32F0XX_LPTIM_H
#define __SH32F0XX_LPTIM_H
#include "sh32f0xx.h"

// CFGR --------------------------------------------
  void LPTIM_ENC(int value);
  void LPTIM_COUNTMODE(int value);
  void LPTIM_PRELOAD(int value);
  void LPTIM_WAVEPOL(int value);
  void LPTIM_WAVE(int value);
  void LPTIM_TIMOUT(int value);
  void LPTIM_TRIGEN(int value);
  void LPTIM_TRIGSEL(int value);
  void LPTIM_PRESC(int value);
  void LPTIM_TRGFLT(int value);
  void LPTIM_CKFLT(int value);
  void LPTIM_CKPOL(int value);
  void LPTIM_CKSEL(int value);

// CR --------------------------------------------
  void LPTIM_RSTARE(int value);
  void LPTIM_COUNTRST(int value);
  void LPTIM_CNTSTRT(int value);
  void LPTIM_SNGSTRT(int value);
  void LPTIM_ENABLE(int value);

// ICR ---------------------------------------------
  void LPTIM_DOWNCF(int value);
  void LPTIM_UPCF(int value);
  void LPTIM_ARROKCF(int value);
  void LPTIM_CMPOKCF(int value);
  void LPTIM_EXTTRIGCF(int value);
  void LPTIM_ARRMCF(int value);
  void LPTIM_CMPMCF(int value);

// IER ---------------------------------------------
  void LPTIM_DOWNIE(int value);
  void LPTIM_UPIE(int value);
  void LPTIM_ARROKIE(int value);
  void LPTIM_CMPOKIE(int value);
  void LPTIM_EXTTRIGIE(int value);
  void LPTIM_ARRMIE(int value);
  void LPTIM_CMPMIE(int value);

// CFGR2 ---------------------------------------------
  void LPTIM_IN2SEL(int value);
  void LPTIM_IN1SEL(int value);

// ARR ---------------------------------------------
  void LPTIM_ARR(int value);

// CMP-------------------------------------------
  void LPTIM_CMP(int value);

// Tools
  void DLY(int value);
#endif
