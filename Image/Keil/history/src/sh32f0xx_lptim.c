/**
  ******************************************************************************
  * @file    sh32f0xx_lptim.c
  * @author  MCD Application Team
  * @version V1.1.1
  * @date    31-July-2013
  * @brief   This file provides firmware functions to manage the following
  *          functionalities of the Reset and clock control (RCC) peripheral:
  *           + Internal/external clocks, PLL, CSS and MCO configuration
  *           + System, AHB and APB busses clocks configuration
  *           + Peripheral clocks configuration
  *           + Interrupts and flags management
  *
 @verbatim

 ===============================================================================
                     ##### LPTIM specific features #####
 ===============================================================================

 @endverbatim

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

/* Includes ------------------------------------------------------------------*/
#include "sh32f0xx_lptim.h"

/* Private functions ---------------------------------------------------------*/

// CFGR register
void LPTIM_ENC(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x0FFFFFF) | ((value & 0x1) << 24);}

void LPTIM_COUNTMODE(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x17FFFFF) | ((value & 0x1) << 23);}

void LPTIM_PRELOAD(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x1BFFFFF) | ((value & 0x1) << 22);}

void LPTIM_WAVEPOL(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x1DFFFFF) | ((value & 0x1) << 21);}

void LPTIM_WAVE(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x1EFFFFF) | ((value & 0x1) << 20);}

void LPTIM_TIMOUT(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x1F7FFFF) | ((value & 0x1) << 19);}

void LPTIM_TRIGEN(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x1F9FFFF) | ((value & 0x3) << 17);}

void LPTIM_TRIGSEL(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x1FF1FFF) | ((value & 0x7) << 13);}

void LPTIM_PRESC(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x1FFF1FF) | ((value & 0x7) << 9);}

void LPTIM_TRGFLT(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x1FFFF3F) | ((value & 0x3) << 6);}

void LPTIM_CKFLT(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x1FFFFE7) | ((value & 0x3) << 3);}

void LPTIM_CKPOL(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x1FFFFF9) | ((value & 0x3) << 1);}

void LPTIM_CKSEL(int value)
    {LPTIM -> CFGR = (LPTIM -> CFGR & 0x1FFFFFE) | (value & 0x1)       ;}

// CR register
void LPTIM_RSTARE(int value)
    {LPTIM -> CR = (LPTIM -> CR & 0x0F) | ((value & 0x1) << 4);} 

void LPTIM_COUNTRST(int value)
    {LPTIM -> CR = (LPTIM -> CR & 0x17) | ((value & 0x1) << 3);}

void LPTIM_CNTSTRT(int value)
    {LPTIM -> CR = (LPTIM -> CR & 0x1B) | ((value & 0x1) << 2);}

void LPTIM_SNGSTRT(int value)
    {LPTIM -> CR = (LPTIM -> CR & 0x1D) | ((value & 0x1) << 1);}

void LPTIM_ENABLE(int value)
    {LPTIM -> CR = (LPTIM -> CR & 0x1E) | (value & 0x1)       ;}

// ICR register
void LPTIM_DOWNCF(int value)
    {LPTIM -> ICR = (LPTIM -> ICR & 0x3F) | ((value & 0x1) << 6);}

void LPTIM_UPCF(int value)
    {LPTIM -> ICR = (LPTIM -> ICR & 0x5F) | ((value & 0x1) << 5);}

void LPTIM_ARROKCF(int value)
    {LPTIM -> ICR = (LPTIM -> ICR & 0x6F) | ((value & 0x1) << 4);}

void LPTIM_CMPOKCF(int value)
    {LPTIM -> ICR = (LPTIM -> ICR & 0x77) | ((value & 0x1) << 3);}

void LPTIM_EXTTRIGCF(int value)
    {LPTIM -> ICR = (LPTIM -> ICR & 0x7B) | ((value & 0x1) << 2);} 

void LPTIM_ARRMCF(int value)
    {LPTIM -> ICR = (LPTIM -> ICR & 0x7D) | ((value & 0x1) << 1);}

void LPTIM_CMPMCF(int value)
    {LPTIM -> ICR = (LPTIM -> ICR & 0x7E) | (value & 0x1)       ;}

// IER register
void LPTIM_DOWNIE(int value)
    {LPTIM -> IER = (LPTIM -> IER & 0x3F) | ((value & 0x1) << 6);}

void LPTIM_UPIE(int value)
    {LPTIM -> IER = (LPTIM -> IER & 0x5F) | ((value & 0x1) << 5);}

void LPTIM_ARROKIE(int value)
    {LPTIM -> IER = (LPTIM -> IER & 0x6F) | ((value & 0x1) << 4);}

void LPTIM_CMPOKIE(int value)
    {LPTIM -> IER = (LPTIM -> IER & 0x77) | ((value & 0x1) << 3);}

void LPTIM_EXTTRIGIE(int value)
    {LPTIM -> IER = (LPTIM -> IER & 0x7B) | ((value & 0x1) << 2);} 

void LPTIM_ARRMIE(int value)
    {LPTIM -> IER = (LPTIM -> IER & 0x7D) | ((value & 0x1) << 1);}

void LPTIM_CMPMIE(int value)
    {LPTIM -> IER = (LPTIM -> IER & 0x7E) | (value & 0x1)       ;}

// CFGR2 register
void LPTIM_IN2SEL(int value)
    {LPTIM -> CFGR2 = (LPTIM -> CFGR2 & 0x0F) | ((value & 0x3) << 4);}
void LPTIM_IN1SEL(int value)
    {LPTIM -> CFGR2 = (LPTIM -> CFGR2 & 0x3C) | (value & 0x3)       ;}

// ARR register
void LPTIM_ARR(int value)
    {LPTIM -> ARR = (LPTIM -> ARR & 0x0000) | (value & 0xFFFF);}

// CMP register
void LPTIM_CMP(int value)
    {LPTIM -> CMP = (LPTIM -> CMP & 0x0000) | (value & 0xFFFF);}

void DLY(int value)
{
    int i ;
    for (i=0 ; i<value ; i++)
    __NOP();
}

