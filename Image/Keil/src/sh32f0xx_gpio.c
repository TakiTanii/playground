///**
//  ******************************************************************************
//  * @file    sh32f0xx_gpio.c
//  * @author  MCD Application Team
//  * @version V1.1.1
//  * @date    31-July-2013
//  * @brief   This file provides firmware functions to manage the following 
//  *          functionalities of the GPIO peripheral:
//  *           + Initialization and Configuration functions
//  *           + GPIO Read and Write functions
//  *           + GPIO Alternate functions configuration functions
//  *
//  *  @verbatim
//  *
//  *
//    ===========================================================================
//                         ##### How to use this driver #####
//    ===========================================================================
//      [..]
//      (#) Enable the GPIO AHB clock using RCC_AHBPeriphClockCmd()
//      (#) Configure the GPIO pin(s) using GPIO_Init()
//          Four possible configuration are available for each pin:
//         (++) Input: Floating, Pull-up, Pull-down.
//         (++) Output: Push-Pull (Pull-up, Pull-down or no Pull)
//                      Open Drain (Pull-up, Pull-down or no Pull).
//              In output mode, the speed is configurable: Low, Medium, Fast or High.
//         (++) Alternate Function: Push-Pull (Pull-up, Pull-down or no Pull)
//                                  Open Drain (Pull-up, Pull-down or no Pull).
//         (++) Analog: required mode when a pin is to be used as ADC channel,
//              DAC output or comparator input.
//      (#) Peripherals alternate function:
//         (++) For ADC, DAC and comparators, configure the desired pin in analog 
//              mode using GPIO_InitStruct->GPIO_Mode = GPIO_Mode_AN
//         (++) For other peripherals (TIM, USART...):
//              (+++) Connect the pin to the desired peripherals' Alternate 
//                    Function (AF) using GPIO_PinAFConfig() function. For PortC, 
//                    PortD and PortF, no configuration is needed.
//              (+++) Configure the desired pin in alternate function mode using
//                    GPIO_InitStruct->GPIO_Mode = GPIO_Mode_AF
//              (+++) Select the type, pull-up/pull-down and output speed via 
//                    GPIO_PuPd, GPIO_OType and GPIO_Speed members
//              (+++) Call GPIO_Init() function
//      (#) To get the level of a pin configured in input mode use GPIO_ReadInputDataBit()
//      (#) To set/reset the level of a pin configured in output mode use
//          GPIO_SetBits()/GPIO_ResetBits()
//      (#) During and just after reset, the alternate functions are not active and 
//          the GPIO pins are configured in input floating mode (except JTAG pins).
//      (#) The LSE oscillator pins OSC32_IN and OSC32_OUT can be used as 
//          general-purpose (PC14 and PC15, respectively) when the LSE oscillator 
//          is off. The LSE has priority over the GPIO function.
//      (#) The HSE oscillator pins OSC_IN/OSC_OUT can be used as general-purpose 
//          PD0 and PD1, respectively, when the HSE oscillator is off. The HSE has 
//          priority over the GPIO function.
//    @endverbatim
//  ******************************************************************************
//  * @attention
//  *
//  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
//  *
//  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
//  * You may not use this file except in compliance with the License.
//  * You may obtain a copy of the License at:
//  *
//  *        http://www.st.com/software_license_agreement_liberty_v2
//  *
//  * Unless required by applicable law or agreed to in writing, software 
//  * distributed under the License is distributed on an "AS IS" BASIS, 
//  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  * See the License for the specific language governing permissions and
//  * limitations under the License.
//  *
//  ******************************************************************************
//  */
//
///* Includes ------------------------------------------------------------------*/
#include "sh32f0xx_gpio.h"
#include "sh32f0xx_rcc.h"
////
/////** @addtogroup STM32F0xx_StdPeriph_Driver
////  * @{
////  */
////
/////** @defgroup GPIO 
////  * @brief GPIO driver modules
////  * @{
////  */
////
/////* Private typedef -----------------------------------------------------------*/
/////* Private define ------------------------------------------------------------*/
/////* Private macro -------------------------------------------------------------*/
/////* Private variables ---------------------------------------------------------*/
/////* Private function prototypes -----------------------------------------------*/
/////* Private functions ---------------------------------------------------------*/
////
/////** @defgroup GPIO_Private_Functions 
////  * @{
////  */
////
/////** @defgroup GPIO_Group1 Initialization and Configuration
//// *  @brief   Initialization and Configuration
//// *
////@verbatim
//// ===============================================================================
////                    ##### Initialization and Configuration #####
//// ===============================================================================
////
////@endverbatim
////  * @{
////  */
////#define AFIO_OFFSET                 (AFIO_BASE - PERIPH_BASE)
////
/////* --- EVENTCR Register -----*/
////
////#define PERIPH_BB_BASE              ((uint32_t )0x42000000)
////
/////* Alias word address of EVOE bit */
////#define EVCR_OFFSET                 (AFIO_OFFSET + 0x00)
////#define EVOE_BitNumber              ((uint8_t)0x07)
////#define EVCR_EVOE_BB                (PERIPH_BB_BASE + (EVCR_OFFSET * 32) + (EVOE_BitNumber * 4))
////#define EVCR_PORTPINCONFIG_MASK     ((uint16_t)0xFF80)
////#define LSB_MASK                    ((uint16_t)0xFFFF)
////#define DBGAFR_POSITION_MASK        ((uint32_t)0x000F0000)
////#define DBGAFR_SWJCFG_MASK          ((uint32_t)0xF0FFFFFF)
////#define DBGAFR_LOCATION_MASK        ((uint32_t)0x00200000)
////#define DBGAFR_NUMBITS_MASK         ((uint32_t)0x00100000)
////  
///*
//void GPIO_DeInit(GPIO_TypeDef* GPIOx)
//{
//  /// Check the parameters ///
//  //assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  
//  switch (*(uint32_t*)&GPIOx)
//  {
//    case GPIOA_BASE:
//      RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOA, ENABLE);
//      RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOA, DISABLE);
//      break;
//    case GPIOB_BASE:
//      RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOB, ENABLE);
//      RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOB, DISABLE);
//      break;
//    case GPIOC_BASE:
//      RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOC, ENABLE);
//      RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOC, DISABLE);
//      break;
//    case GPIOD_BASE:
//      RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOD, ENABLE);
//      RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOD, DISABLE);
//      break;

//    default:
//      break;
//  }
//}
//*/
/////**
////  * @brief  Deinitializes the Alternate Functions (remap, event control
////  *   and EXTI configuration) registers to their default reset
////  *   values.
////  * @param  None
////  * @retval : None
////  */
////void GPIO_AFIODeInit(void)
////{
////  RCC_APB2PeriphResetCmd(RCC_APB2Periph_AFIO, ENABLE);
////  RCC_APB2PeriphResetCmd(RCC_APB2Periph_AFIO, DISABLE);
////}
////
/////**
////  * @brief  Initializes the GPIOx peripheral according to the specified
////  *   parameters in the GPIO_InitStruct.
////  * @param GPIOx: where x can be (A..G) to select the GPIO peripheral.
////  * @param GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure that
////  *   contains the configuration information for the specified GPIO
////  *   peripheral.
////  * @retval : None
////  */
////void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
////{
////  uint32_t currentmode = 0x00, currentpin = 0x00, pinpos = 0x00, pos = 0x00;
////  uint32_t tmpreg = 0x00, pinmask = 0x00;
////  /* Check the parameters */
////  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
////  assert_param(IS_GPIO_MODE(GPIO_InitStruct->GPIO_Mode));
////  assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));  
////  
/////*---------------------------- GPIO Mode Configuration -----------------------*/
////  currentmode = ((uint32_t)GPIO_InitStruct->GPIO_Mode) & ((uint32_t)0x0F);
////  if ((((uint32_t)GPIO_InitStruct->GPIO_Mode) & ((uint32_t)0x10)) != 0x00)
////  { 
////    /* Check the parameters */
////    assert_param(IS_GPIO_SPEED(GPIO_InitStruct->GPIO_Speed));
////    /* Output mode */
////    currentmode |= (uint32_t)GPIO_InitStruct->GPIO_Speed;
////  }
/////*---------------------------- GPIO CRL Configuration ------------------------*/
////  /* Configure the eight low port pins */
////  if (((uint32_t)GPIO_InitStruct->GPIO_Pin & ((uint32_t)0x00FF)) != 0x00)
////  {
////    tmpreg = GPIOx->CRL;
////    for (pinpos = 0x00; pinpos < 0x08; pinpos++)
////    {
////      pos = ((uint32_t)0x01) << pinpos;
////      /* Get the port pins position */
////      currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;
////      if (currentpin == pos)
////      {
////        pos = pinpos << 2;
////        /* Clear the corresponding low control register bits */
////        pinmask = ((uint32_t)0x0F) << pos;
////        tmpreg &= ~pinmask;
////        /* Write the mode configuration in the corresponding bits */
////        tmpreg |= (currentmode << pos);
////        /* Reset the corresponding ODR bit */
////        if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD)
////        {
////          GPIOx->BRR = (((uint32_t)0x01) << pinpos);
////        }
////        else
////        {
////          /* Set the corresponding ODR bit */
////          if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU)
////          {
////            GPIOx->BSRR = (((uint32_t)0x01) << pinpos);
////          }
////        }
////      }
////    }
////    GPIOx->CRL = tmpreg;
////  }
////



//void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
//{
//  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;

//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));
//  assert_param(IS_GPIO_MODE(GPIO_InitStruct->GPIO_Mode));
//  assert_param(IS_GPIO_PUPD(GPIO_InitStruct->GPIO_PuPd));

//  /*-------------------------- Configure the port pins -----------------------*/
//  /*-- GPIO Mode Configuration --*/
//  for (pinpos = 0x00; pinpos < 0x10; pinpos++)
//  {
//    pos = ((uint32_t)0x01) << pinpos;

//    /* Get the port pins position */
//    currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;

//    if (currentpin == pos)
//    {
//      if ((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_DIG))
//      {
//        /* Check Speed mode parameters */
//        //assert_param(IS_GPIO_SPEED(GPIO_InitStruct->GPIO_Speed));

//        /* Speed mode configuration */
//        //GPIOx->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 << (pinpos * 2));
//        //GPIOx->OSPEEDR |= ((uint32_t)(GPIO_InitStruct->GPIO_Speed) << (pinpos * 2));

//        /* Check Output mode parameters */
//        assert_param(IS_GPIO_OTYPE(GPIO_InitStruct->GPIO_OType));

//        /* Output mode configuration */
//        GPIOx->OTYPER &= ~((GPIO_OTYPER_OT_0) << ((uint16_t)pinpos));
//        GPIOx->OTYPER |= (uint16_t)(((uint16_t)GPIO_InitStruct->GPIO_OType) << ((uint16_t)pinpos));
//      }

//      GPIOx->MODER  &= ~(GPIO_MODER_0 << (pinpos * 1));

//      GPIOx->MODER |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << (pinpos * 2));

//      /* Pull-up Pull down resistor configuration */
//      GPIOx->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t)pinpos * 2));
//      GPIOx->PUPDR |= (((uint32_t)GPIO_InitStruct->GPIO_PuPd) << (pinpos * 2));
//    }
//  }
//}



/////*---------------------------- GPIO CRH Configuration ------------------------*/
////  /* Configure the eight high port pins */
////  if (GPIO_InitStruct->GPIO_Pin > 0x00FF)
////  {
////    tmpreg = GPIOx->CRH;
////    for (pinpos = 0x00; pinpos < 0x08; pinpos++)
////    {
////      pos = (((uint32_t)0x01) << (pinpos + 0x08));
////      /* Get the port pins position */
////      currentpin = ((GPIO_InitStruct->GPIO_Pin) & pos);
////      if (currentpin == pos)
////      {
////        pos = pinpos << 2;
////        /* Clear the corresponding high control register bits */
////        pinmask = ((uint32_t)0x0F) << pos;
////        tmpreg &= ~pinmask;
////        /* Write the mode configuration in the corresponding bits */
////        tmpreg |= (currentmode << pos);
////        /* Reset the corresponding ODR bit */
////        if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD)
////        {
////          GPIOx->BRR = (((uint32_t)0x01) << (pinpos + 0x08));
////        }
////        /* Set the corresponding ODR bit */
////        if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU)
////        {
////          GPIOx->BSRR = (((uint32_t)0x01) << (pinpos + 0x08));
////        }
////      }
////    }
////    GPIOx->CRH = tmpreg;
////  }
////}
////
/////**
////  * @brief  Fills each GPIO_InitStruct member with its default value.
////  * @param GPIO_InitStruct : pointer to a GPIO_InitTypeDef structure
////  *   which will be initialized.
////  * @retval : None
////  */
//void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct)
//{
//  /* Reset GPIO init structure parameters values */
//  GPIO_InitStruct->GPIO_Pin  = GPIO_Pin_All;
//  GPIO_InitStruct->GPIO_Mode = GPIO_Mode_DIG;
//  GPIO_InitStruct->GPIO_OType = GPIO_OType_PP;
//  GPIO_InitStruct->GPIO_PuPd = GPIO_PuPd_NOPULL;
//}


///**
//  * @brief  Reads the specified input port pin.
//  * @param GPIOx: where x can be (A..G) to select the GPIO peripheral.
//  * @param GPIO_Pin:  specifies the port bit to read.
//  *   This parameter can be GPIO_Pin_x where x can be (0..15).
//  * @retval : The input port pin value.
//  */
//uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  uint8_t bitstatus = 0x00;
//  
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GET_GPIO_PIN(GPIO_Pin)); 
//  
//  if ((GPIOx->IDR & GPIO_Pin) != (uint32_t)Bit_RESET)
//  {
//    bitstatus = (uint8_t)Bit_SET;
//  }
//  else
//  {
//    bitstatus = (uint8_t)Bit_RESET;
//  }
//  return bitstatus;
//}

///**
//  * @brief  Reads the specified GPIO input data port.
//  * @param GPIOx: where x can be (A..G) to select the GPIO peripheral.
//  * @retval : GPIO input data port value.
//  */
//uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  
//  return ((uint16_t)GPIOx->IDR);
//}

///**
//  * @brief  Reads the specified output data port bit.
//  * @param GPIOx: where x can be (A..G) to select the GPIO peripheral.
//  * @param GPIO_Pin:  specifies the port bit to read.
//  *   This parameter can be GPIO_Pin_x where x can be (0..15).
//  * @retval : The output port pin value.
//  */
//uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  uint8_t bitstatus = 0x00;
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GET_GPIO_PIN(GPIO_Pin)); 
//  
//  if ((GPIOx->ODR & GPIO_Pin) != (uint32_t)Bit_RESET)
//  {
//    bitstatus = (uint8_t)Bit_SET;
//  }
//  else
//  {
//    bitstatus = (uint8_t)Bit_RESET;
//  }
//  return bitstatus;
//}

///**
//  * @brief  Reads the specified GPIO output data port.
//  * @param GPIOx: where x can be (A..G) to select the GPIO peripheral.
//  * @retval : GPIO output data port value.
//  */
//uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//    
//  return ((uint16_t)GPIOx->ODR);
//}

///**
//  * @brief  Sets the selected data port bits.
//  * @param GPIOx: where x can be (A..G) to select the GPIO peripheral.
//  * @param GPIO_Pin: specifies the port bits to be written.
//  *   This parameter can be any combination of GPIO_Pin_x where 
//  *   x can be (0..15).
//  * @retval : None
//  */
//void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GPIO_PIN(GPIO_Pin));
//  
//  GPIOx->BSRR = GPIO_Pin;
//}

///**
//  * @brief  Clears the selected data port bits.
//  * @param GPIOx: where x can be (A..G) to select the GPIO peripheral.
//  * @param GPIO_Pin: specifies the port bits to be written.
//  *   This parameter can be any combination of GPIO_Pin_x where 
//  *   x can be (0..15).
//  * @retval : None
//  */
//void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GPIO_PIN(GPIO_Pin));
//  
//  GPIOx->BRR = GPIO_Pin;
//}

///**
//  * @brief  Sets or clears the selected data port bit.
//  * @param GPIOx: where x can be (A..G) to select the GPIO peripheral.
//  * @param GPIO_Pin: specifies the port bit to be written.
//  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
//  * @param BitVal: specifies the value to be written to the selected bit.
//  *   This parameter can be one of the BitAction enum values:
//  * @arg Bit_RESET: to clear the port pin
//  * @arg Bit_SET: to set the port pin
//  * @retval : None
//  */
//void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
//  assert_param(IS_GPIO_BIT_ACTION(BitVal)); 
//  
//  if (BitVal != Bit_RESET)
//  {
//    GPIOx->BSRR = GPIO_Pin;
//  }
//  else
//  {
//    GPIOx->BRR = GPIO_Pin;
//  }
//}

///**
//  * @brief  Writes data to the specified GPIO data port.
//  * @param GPIOx: where x can be (A..G) to select the GPIO peripheral.
//  * @param PortVal: specifies the value to be written to the port output
//  *   data register.
//  * @retval : None
//  */
//void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  
//  GPIOx->ODR = PortVal;
//}

///**
//  * @brief  Locks GPIO Pins configuration registers.
//  * @param GPIOx: where x can be (A..G) to select the GPIO peripheral.
//  * @param GPIO_Pin: specifies the port bit to be written.
//  *   This parameter can be any combination of GPIO_Pin_x where 
//  *   x can be (0..15).
//  * @retval : None
//  */
//void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  uint32_t tmp = 0x00010000;
//  
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GPIO_PIN(GPIO_Pin));
//  
//  tmp |= GPIO_Pin;
//  /* Set LCKK bit */
//  GPIOx->LCKR = tmp;
//  /* Reset LCKK bit */
//  GPIOx->LCKR =  GPIO_Pin;
//  /* Set LCKK bit */
//  GPIOx->LCKR = tmp;
//  /* Read LCKK bit*/
//  tmp = GPIOx->LCKR;
//  /* Read LCKK bit*/
//  tmp = GPIOx->LCKR;
//}
////
/////**
////  * @brief  Selects the GPIO pin used as Event output.
////  * @param GPIO_PortSource: selects the GPIO port to be used as source
////  *   for Event output.
////  *   This parameter can be GPIO_PortSourceGPIOx where x can be
////  *   (A..E).
////  * @param GPIO_PinSource: specifies the pin for the Event output.
////  *   This parameter can be GPIO_PinSourcex where x can be (0..15).
////  * @retval : None
////  */
////void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource)
////{
////  uint32_t tmpreg = 0x00;
////  /* Check the parameters */
////  assert_param(IS_GPIO_EVENTOUT_PORT_SOURCE(GPIO_PortSource));
////  assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSource));
////    
////  tmpreg = AFIO->EVCR;
////  /* Clear the PORT[6:4] and PIN[3:0] bits */
////  tmpreg &= EVCR_PORTPINCONFIG_MASK;
////  tmpreg |= (uint32_t)GPIO_PortSource << 0x04;
////  tmpreg |= GPIO_PinSource;
////  AFIO->EVCR = tmpreg;
////}
////
/////**
////  * @brief  Enables or disables the Event Output.
////  * @param NewState: new state of the Event output.
////  *   This parameter can be: ENABLE or DISABLE.
////  * @retval : None
////  */
////void GPIO_EventOutputCmd(FunctionalState NewState)
////{
////  /* Check the parameters */
////  assert_param(IS_FUNCTIONAL_STATE(NewState));
////  
////  *(__IO uint32_t *) EVCR_EVOE_BB = (uint32_t)NewState;
////}
////
/////**
////  * @brief  Changes the mapping of the specified pin.
////  * @param GPIO_Remap: selects the pin to remap.
////  *   This parameter can be one of the following values:
////  * @arg GPIO_Remap_SPI1
////  * @arg GPIO_Remap_I2C1
////  * @arg GPIO_Remap_USART1
////  * @arg GPIO_Remap_USART2
////  * @arg GPIO_PartialRemap_USART3
////  * @arg GPIO_FullRemap_USART3
////  * @arg GPIO_PartialRemap_TIM1
////  * @arg GPIO_FullRemap_TIM1
////  * @arg GPIO_PartialRemap1_TIM2
////  * @arg GPIO_PartialRemap2_TIM2
////  * @arg GPIO_FullRemap_TIM2
////  * @arg GPIO_PartialRemap_TIM3
////  * @arg GPIO_FullRemap_TIM3
////  * @arg GPIO_Remap_TIM4
////  * @arg GPIO_Remap1_CAN1
////  * @arg GPIO_Remap2_CAN1
////  * @arg GPIO_Remap_PD01
////  * @arg GPIO_Remap_TIM5CH4_LSI
////  * @arg GPIO_Remap_ADC1_ETRGINJ
////  * @arg GPIO_Remap_ADC1_ETRGREG
////  * @arg GPIO_Remap_ADC2_ETRGINJ
////  * @arg GPIO_Remap_ADC2_ETRGREG
////  * @arg GPIO_Remap_SWJ_NoJTRST
////  * @arg GPIO_Remap_SWJ_JTAGDisable
////  * @arg GPIO_Remap_SWJ_Disable
////  * @param NewState: new state of the port pin remapping.
////  *   This parameter can be: ENABLE or DISABLE.
////  * @retval : None
////  */
////void GPIO_PinRemapConfig(uint32_t GPIO_Remap, FunctionalState NewState)
////{
////  uint32_t tmp = 0x00, tmp1 = 0x00, tmpreg = 0x00, tmpmask = 0x00;
////  /* Check the parameters */
////  assert_param(IS_GPIO_REMAP(GPIO_Remap));
////  assert_param(IS_FUNCTIONAL_STATE(NewState));  
////  
////  tmpreg = AFIO->MAPR;
////  tmpmask = (GPIO_Remap & DBGAFR_POSITION_MASK) >> 0x10;
////  tmp = GPIO_Remap & LSB_MASK;
////  if ((GPIO_Remap & (DBGAFR_LOCATION_MASK | DBGAFR_NUMBITS_MASK)) == (DBGAFR_LOCATION_MASK | DBGAFR_NUMBITS_MASK))
////  {
////    tmpreg &= DBGAFR_SWJCFG_MASK;
////    AFIO->MAPR &= DBGAFR_SWJCFG_MASK;
////  }
////  else if ((GPIO_Remap & DBGAFR_NUMBITS_MASK) == DBGAFR_NUMBITS_MASK)
////  {
////    tmp1 = ((uint32_t)0x03) << tmpmask;
////    tmpreg &= ~tmp1;
////    tmpreg |= ~DBGAFR_SWJCFG_MASK;
////  }
////  else
////  {
////    tmpreg &= ~(tmp << ((GPIO_Remap >> 0x15)*0x10));
////    tmpreg |= ~DBGAFR_SWJCFG_MASK;
////  }
////  if (NewState != DISABLE)
////  {
////    tmpreg |= (tmp << ((GPIO_Remap >> 0x15)*0x10));
////  }
////  AFIO->MAPR = tmpreg;
////}
////
/////**
////  * @brief  Selects the GPIO pin used as EXTI Line.
////  * @param GPIO_PortSource: selects the GPIO port to be used as
////  *   source for EXTI lines.
////  *   This parameter can be GPIO_PortSourceGPIOx where x can be
////  *   (A..G).
////  * @param GPIO_PinSource: specifies the EXTI line to be configured.
////  *   This parameter can be GPIO_PinSourcex where x can be (0..15).
////  * @retval : None
////  */
////void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource)
////{
////  uint32_t tmp = 0x00;
////  /* Check the parameters */
////  assert_param(IS_GPIO_EXTI_PORT_SOURCE(GPIO_PortSource));
////  assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSource));
////  
////  tmp = ((uint32_t)0x0F) << (0x04 * (GPIO_PinSource & (uint8_t)0x03));
////  AFIO->EXTICR[GPIO_PinSource >> 0x02] &= ~tmp;
////  AFIO->EXTICR[GPIO_PinSource >> 0x02] |= (((uint32_t)GPIO_PortSource) << (0x04 * (GPIO_PinSource & (uint8_t)0x03)));
////}
/////**
////  * @brief  Deinitializes the GPIOx peripheral registers to their default reset 
////  *         values.
////  * @param  GPIOx: where x can be (A, B, C, D or F) to select the GPIO peripheral.
////  * @retval None
////  */


///*
//void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF)
//{
//  uint32_t temp = 0x00;
//  uint32_t temp_2 = 0x00;

//  // Check the parameters //
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSource));
//  assert_param(IS_GPIO_AF(GPIO_AF));

//  temp = ((uint32_t)(GPIO_AF) << ((uint32_t)((uint32_t)GPIO_PinSource & (uint32_t)0x07) * 4));
//  GPIOx->AFR[GPIO_PinSource >> 0x03] &= ~((uint32_t)0xF << ((uint32_t)((uint32_t)GPIO_PinSource & (uint32_t)0x07) * 4));
//  temp_2 = GPIOx->AFR[GPIO_PinSource >> 0x03] | temp;
//  GPIOx->AFR[GPIO_PinSource >> 0x03] = temp_2;
//}
//*/

//void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF)
//{
//    // Check the validity of input parameters
//    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//    assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSource));
//    assert_param(IS_GPIO_AF(GPIO_AF));

//    // Calculate the alternate function configuration value
//    // Each pin's alternate function is represented by 4 bits, so shift GPIO_AF accordingly
//    uint32_t af_value = (uint32_t)GPIO_AF << ((GPIO_PinSource % 8) * 4);

//    if (GPIO_PinSource < 8) {
//        // Handle GPIO pins from 0 to 7, using the AFRL register
//        // Clear the existing alternate function configuration for the corresponding pin
//        GPIOx->AFRL &= ~(0xF << ((GPIO_PinSource % 8) * 4));
//        // Set the new alternate function configuration
//        GPIOx->AFRL |= af_value;
//    } else {
//        // Handle GPIO pins from 8 to 15, using the AFRH register
//        // Clear the existing alternate function configuration for the corresponding pin
//        GPIOx->AFRH &= ~(0xF << ((GPIO_PinSource % 8) * 4));
//        // Set the new alternate function configuration
//        GPIOx->AFRH |= af_value;
//    }
//}


/////**
////  * @}
////  */
////
/////**
////  * @}
////  */
////
/////**
////  * @}
////  */
////
/////**
////  * @}
////  */
////
/////************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
