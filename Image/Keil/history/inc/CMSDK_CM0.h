/**************************************************************************//**
 * @file     CMSDK_CM0.h
 * @brief    CMSIS Cortex-M0 Core Peripheral Access Layer Header File for
 *           Device CMSDK
 * @version  V3.01
 * @date     06. March 2012
 *
 * @note
 * Copyright (C) 2010-2012 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M
 * processor based microcontrollers.  This file can be freely distributed
 * within development tools that are supporting such ARM based processors.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/



#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup CMSDK_Definitions CMSDK Definitions
  This file defines all structures and symbols for CMSDK:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - Peripheral definitions
  @{
*/


/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup CMSDK_CMSIS Device CMSIS Definitions
  Configuration of the Cortex-M0 Processor and Core Peripherals
  @{
*/

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */


/* CMSDK_IIC Register Definitions */
#define CMSDK_IIC_IDREV_ID_Pos				              12
#define CMSDK_IIC_IDREV_ID_Msk				              (0xFFFFFul << CMSDK_IIC_IDREV_ID_Pos)
#define CMSDK_IIC_IDREV_RevMajor_Pos		            4
#define CMSDK_IIC_IDREV_RevMajor_Msk		            (0xFFul << CMSDK_IIC_IDREV_RevMajor_Pos)
#define CMSDK_IIC_IDREV_RevMinor_Pos		            0
#define CMSDK_IIC_IDREV_RevMinor_Msk		            (0xFul << CMSDK_IIC_IDREV_RevMinor_Pos)

#define CMSDK_IIC_CFG_FIFOSize_Pos			            0
#define CMSDK_IIC_CFG_FIFOSize_Msk			            (0x3ul << CMSDK_IIC_CFG_FIFOSize_Pos)

#define CMSDK_IIC_INTEN_Cmpl_Pos			              9
#define CMSDK_IIC_INTEN_Cmpl_Msk			              (0x1ul << CMSDK_IIC_INTEN_Cmpl_Pos)
#define CMSDK_IIC_INTEN_ByteRecv_Pos		            8
#define CMSDK_IIC_INTEN_ByteRecv_Msk		            (0x1ul << CMSDK_IIC_INTEN_ByteRecv_Pos)
#define CMSDK_IIC_INTEN_ByteTrans_Pos		            7
#define CMSDK_IIC_INTEN_ByteTrans_Msk		            (0x1ul << CMSDK_IIC_INTEN_ByteTrans_Pos)
#define CMSDK_IIC_INTEN_Start_Pos			              6
#define CMSDK_IIC_INTEN_Start_Msk			              (0x1ul << CMSDK_IIC_INTEN_Start_Pos)
#define CMSDK_IIC_INTEN_Stop_Pos			              5
#define CMSDK_IIC_INTEN_Stop_Msk			              (0x1ul << CMSDK_IIC_INTEN_Stop_Pos)
#define CMSDK_IIC_INTEN_ArbLose_Pos			            4
#define CMSDK_IIC_INTEN_ArbLose_Msk			            (0x1ul << CMSDK_IIC_INTEN_ArbLose_Pos)
#define CMSDK_IIC_INTEN_AddrHit_Pos			            3
#define CMSDK_IIC_INTEN_AddrHit_Msk			            (0x1ul << CMSDK_IIC_INTEN_AddrHit_Pos)
#define CMSDK_IIC_INTEN_FIFOHalf_Pos		            2
#define CMSDK_IIC_INTEN_FIFOHalf_Msk		            (0x1ul << CMSDK_IIC_INTEN_FIFOHalf_Pos)
#define CMSDK_IIC_INTEN_FIFOFull_Pos		            1
#define CMSDK_IIC_INTEN_FIFOFull_Msk		            (0x1ul << CMSDK_IIC_INTEN_FIFOFull_Pos)
#define CMSDK_IIC_INTEN_FIFOEmpty_Pos		            0
#define CMSDK_IIC_INTEN_FIFOEmpty_Msk		            (0x1ul << CMSDK_IIC_INTEN_FIFOEmpty_Pos)

#define CMSDK_IIC_STATUS_LineSDA_Pos		            14
#define CMSDK_IIC_STATUS_LineSDA_Msk		            (0x1ul << CMSDK_IIC_STATUS_LineSDA_Pos)
#define CMSDK_IIC_STATUS_LineSCL_Pos		            13
#define CMSDK_IIC_STATUS_LineSCL_Msk		            (0x1ul << CMSDK_IIC_STATUS_LineSCL_Pos)
#define CMSDK_IIC_STATUS_GenCall_Pos		            12
#define CMSDK_IIC_STATUS_GenCall_Msk		            (0x1ul << CMSDK_IIC_STATUS_GenCall_Pos)
#define CMSDK_IIC_STATUS_BusBusy_Pos		            11
#define CMSDK_IIC_STATUS_BusBusy_Msk		            (0x1ul << CMSDK_IIC_STATUS_BusBusy_Pos)
#define CMSDK_IIC_STATUS_ACK_Pos			              10
#define CMSDK_IIC_STATUS_ACK_Msk			              (0x1ul << CMSDK_IIC_STATUS_ACK_Pos)
#define CMSDK_IIC_STATUS_Cmpl_Pos			              9
#define CMSDK_IIC_STATUS_Cmpl_Msk			              (0x1ul << CMSDK_IIC_STATUS_Cmpl_Pos)
#define CMSDK_IIC_STATUS_ByteRecv_Pos		            8
#define CMSDK_IIC_STATUS_ByteRecv_Msk		            (0x1ul << CMSDK_IIC_STATUS_ByteRecv_Pos)
#define CMSDK_IIC_STATUS_ByteTrans_Pos	            7
#define CMSDK_IIC_STATUS_ByteTrans_Msk	            (0x1ul << CMSDK_IIC_STATUS_ByteTrans_Pos)
#define CMSDK_IIC_STATUS_Start_Pos			            6
#define CMSDK_IIC_STATUS_Start_Msk			            (0x1ul << CMSDK_IIC_STATUS_Start_Pos)
#define CMSDK_IIC_STATUS_Stop_Pos			              5
#define CMSDK_IIC_STATUS_Stop_Msk			              (0x1ul << CMSDK_IIC_STATUS_Stop_Pos)
#define CMSDK_IIC_STATUS_ArbLose_Pos		            4
#define CMSDK_IIC_STATUS_ArbLose_Msk		            (0x1ul << CMSDK_IIC_STATUS_ArbLose_Pos)
#define CMSDK_IIC_STATUS_AddrHit_Pos		            3
#define CMSDK_IIC_STATUS_AddrHit_Msk		            (0x1ul << CMSDK_IIC_STATUS_AddrHit_Pos)
#define CMSDK_IIC_STATUS_FIFOHalf_Pos		            2
#define CMSDK_IIC_STATUS_FIFOHalf_Msk		            (0x1ul << CMSDK_IIC_STATUS_FIFOHalf_Pos)
#define CMSDK_IIC_STATUS_FIFOFull_Pos		            1
#define CMSDK_IIC_STATUS_FIFOFull_Msk		            (0x1ul << CMSDK_IIC_STATUS_FIFOFull_Pos)
#define CMSDK_IIC_STATUS_FIFOEmpty_Pos	            0
#define CMSDK_IIC_STATUS_FIFOEmpty_Msk	            (0x1ul << CMSDK_IIC_STATUS_FIFOEmpty_Pos)

#define CMSDK_IIC_ADDR_Pos					                0
#define CMSDK_IIC_ADDR_Msk					                (0x3FFul << CMSDK_IIC_ADDR_Pos)

#define CMSDK_IIC_DATA_Pos					                0
#define CMSDK_IIC_DATA_Msk					                (0xFFul << CMSDK_IIC_ADDR_Pos)

#define CMSDK_IIC_CTRL_Phase_start_Pos	            12
#define CMSDK_IIC_CTRL_Phase_start_Msk	            (0x1ul << CMSDK_IIC_CTRL_Phase_start_Pos)
#define CMSDK_IIC_CTRL_Phase_addr_Pos		            11
#define CMSDK_IIC_CTRL_Phase_addr_Msk		            (0x1ul << CMSDK_IIC_CTRL_Phase_addr_Pos)
#define CMSDK_IIC_CTRL_Phase_data_Pos		            10
#define CMSDK_IIC_CTRL_Phase_data_Msk		            (0x1ul << CMSDK_IIC_CTRL_Phase_data_Pos)
#define CMSDK_IIC_CTRL_Phase_stop_Pos		            9
#define CMSDK_IIC_CTRL_Phase_stop_Msk		            (0x1ul << CMSDK_IIC_CTRL_Phase_stop_Pos)
#define CMSDK_IIC_CTRL_Dir_Pos				              8
#define CMSDK_IIC_CTRL_Dir_Msk				              (0x1ul << CMSDK_IIC_CTRL_Dir_Pos)
#define CMSDK_IIC_CTRL_DataCnt_Pos			            0
#define CMSDK_IIC_CTRL_DataCnt_Msk			            (0xFFul << CMSDK_IIC_CTRL_DataCnt_Pos)

#define CMSDK_IIC_CMD_Pos					                  0
#define CMSDK_IIC_CMD_Msk					                  (0x7ul << CMSDK_IIC_CMD_Pos)


#define CMSDK_IIC_SETUP_T_SCLRatio_Pos	            5
#define CMSDK_IIC_SETUP_T_SCLRatio_Msk	            (0x1ul << CMSDK_IIC_SETUP_T_SCLRatio_Pos)
#define CMSDK_IIC_SETUP_NOSTRETCH_Pos	              4
#define CMSDK_IIC_SETUP_NOSTRETCH_Msk	              (0x1ul << CMSDK_IIC_SETUP_NOSTRETCH_Pos)
#define CMSDK_IIC_SETUP_DMAEn_Pos			              3
#define CMSDK_IIC_SETUP_DMAEn_Msk			              (0x1ul << CMSDK_IIC_SETUP_DMAEn_Pos)
#define CMSDK_IIC_SETUP_Master_Pos			            2
#define CMSDK_IIC_SETUP_Master_Msk			            (0x1ul << CMSDK_IIC_SETUP_Master_Pos)
#define CMSDK_IIC_SETUP_Addressing_Pos	            1
#define CMSDK_IIC_SETUP_Addressing_Msk	            (0x1ul << CMSDK_IIC_SETUP_Addressing_Pos)
#define CMSDK_IIC_SETUP_IICEn_Pos			              0
#define CMSDK_IIC_SETUP_IICEn_Msk			              (0x1ul << CMSDK_IIC_SETUP_IICEn_Pos)

#define CMSDK_IIC_TIMING_T_SUDAT_Pos			          24
#define CMSDK_IIC_TIMING_T_SUDAT_Msk			          (0xFFul << CMSDK_IIC_TIMING_T_SUDAT_Pos)
#define CMSDK_IIC_TIMING_T_HDDAT_Pos			          16
#define CMSDK_IIC_TIMING_T_HDDAT_Msk			          (0xFFul << CMSDK_IIC_TIMING_T_HDDAT_Pos)
#define CMSDK_IIC_TIMING_T_SP_Pos			              11
#define CMSDK_IIC_TIMING_T_SP_Msk			              (0x1Ful << CMSDK_IIC_TIMING_T_SP_Pos)
#define CMSDK_IIC_TIMING_T_SCLHi_Pos			          0
#define CMSDK_IIC_TIMING_T_SCLHi_Msk			          (0x7FFul << CMSDK_IIC_TIMING_T_SCLHi_Pos)

#define CMSDK_IIC_MASK_Pos					                0
#define CMSDK_IIC_MASK_Msk					                (0x3FFul << CMSDK_IIC_MASK_Pos)

#define CMSDK_IIC_REC_ADDR_Pos					            0
#define CMSDK_IIC_REC_ADDR_Msk					            (0x3FFul << CMSDK_IIC_REC_ADDR_Pos)
/*@}*/ /* end of group CMSDK_IIC */

/*--------------------------- General-purpose timers (TIM14) ------------------------*/
/** @addtogroup CMSDK_TIM14 CMSDK General-purpose timers (TIM14)
  memory mapped structure for CMSDK_TIM14
  @{
*/

/* CMSDK_TIM14 Register Definitions */
#define CMSDK_TIM14_CR1_UIFREMAP_Pos				        11
#define CMSDK_TIM14_CR1_UIFREMAP_Msk				        (0x1ul << CMSDK_TIM14_CR1_UIFREMAP_Pos)
#define CMSDK_TIM14_CR1_CKD_Pos		                  8
#define CMSDK_TIM14_CR1_CKD_Msk		                  (0x3ul << CMSDK_TIM14_CR1_CKD_Pos)
#define CMSDK_TIM14_CR1_ARPE_Pos		                7
#define CMSDK_TIM14_CR1_ARPE_Msk		                (0x1ul << CMSDK_TIM14_CR1_ARPE_Pos)
#define CMSDK_TIM14_CR1_OPM_Pos                     3
#define CMSDK_TIM14_CR1_OPM_Msk                     (0x1ul << CMSDK_TIM14_CR1_OPM_Pos)
#define CMSDK_TIM14_CR1_URS_Pos                     2
#define CMSDK_TIM14_CR1_URS_Msk                     (0x1ul << CMSDK_TIM14_CR1_URS_Pos)
#define CMSDK_TIM14_CR1_UDIS_Pos                    1
#define CMSDK_TIM14_CR1_UDIS_Msk                    (0x1ul << CMSDK_TIM14_CR1_UDIS_Pos)
#define CMSDK_TIM14_CR1_CEN_Pos                     0
#define CMSDK_TIM14_CR1_CEN_Msk                     (0x1ul << CMSDK_TIM14_CR1_CEN_Pos)

#define CMSDK_TIM14_CR2_OIS1N_Pos				            9
#define CMSDK_TIM14_CR2_OIS1N_Msk				            (0x1ul << CMSDK_TIM14_CR2_OIS1N_Pos)
#define CMSDK_TIM14_CR2_OIS1_Pos		                8
#define CMSDK_TIM14_CR2_OIS1_Msk		                (0x1ul << CMSDK_TIM14_CR2_OIS1_Pos)
#define CMSDK_TIM14_CR2_MMS_Pos		                  4
#define CMSDK_TIM14_CR2_MMS_Msk		                  (0x7ul << CMSDK_TIM14_CR2_MMS_Pos)
#define CMSDK_TIM14_CR2_CCDS_Pos                    3
#define CMSDK_TIM14_CR2_CCDS_Msk                    (0x1ul << CMSDK_TIM14_CR2_CCDS_Pos)
#define CMSDK_TIM14_CR2_CCUS_Pos                    2
#define CMSDK_TIM14_CR2_CCUS_Msk                    (0x1ul << CMSDK_TIM14_CR2_CCUS_Pos)
#define CMSDK_TIM14_CR2_CCPC_Pos                    0
#define CMSDK_TIM14_CR2_CCPC_Msk                    (0x1ul << CMSDK_TIM14_CR2_CCPC_Pos)

#define CMSDK_TIM14_SMCR_MSM_Pos			                7
#define CMSDK_TIM14_SMCR_MSM_Msk			                (0x1ul << CMSDK_TIM14_SMCR_MSM_Pos)
#define CMSDK_TIM14_SMCR_TS_Pos		                    4
#define CMSDK_TIM14_SMCR_TS_Msk		                    (0x7ul << CMSDK_TIM14_SMCR_TS_Pos)
#define CMSDK_TIM14_SMCR_SMS_Pos		                  0
#define CMSDK_TIM14_SMCR_SMS_Msk		                  (0x7ul << CMSDK_TIM14_SMCR_SMS_Pos)

#define CMSDK_TIM14_DIER_TDE_Pos			                14
#define CMSDK_TIM14_DIER_TDE_Msk			                (0x1ul << CMSDK_TIM14_DIER_TDE_Pos)
#define CMSDK_TIM14_DIER_COMDE_Pos			              13
#define CMSDK_TIM14_DIER_COMDE_Msk			              (0x1ul << CMSDK_TIM14_DIER_COMDE_Pos)
#define CMSDK_TIM14_DIER_CC1DE_Pos			              9
#define CMSDK_TIM14_DIER_CC1DE_Msk			              (0x1ul << CMSDK_TIM14_DIER_CC1DE_Pos)
#define CMSDK_TIM14_DIER_UDE_Pos			                8
#define CMSDK_TIM14_DIER_UDE_Msk			                (0x1ul << CMSDK_TIM14_DIER_UDE_Pos)
#define CMSDK_TIM14_DIER_BIE_Pos			                7
#define CMSDK_TIM14_DIER_BIE_Msk			                (0x1ul << CMSDK_TIM14_DIER_BIE_Pos)
#define CMSDK_TIM14_DIER_TIE_Pos			                6
#define CMSDK_TIM14_DIER_TIE_Msk			                (0x1ul << CMSDK_TIM14_DIER_TIE_Pos)
#define CMSDK_TIM14_DIER_COMIE_Pos			              5
#define CMSDK_TIM14_DIER_COMIE_Msk			              (0x1ul << CMSDK_TIM14_DIER_COMIE_Pos)
#define CMSDK_TIM14_DIER_CC1IE_Pos			              1
#define CMSDK_TIM14_DIER_CC1IE_Msk			              (0x1ul << CMSDK_TIM14_DIER_CC1IE_Pos)
#define CMSDK_TIM14_DIER_UIE_Pos			                0
#define CMSDK_TIM14_DIER_UIE_Msk			                (0x1ul << CMSDK_TIM14_DIER_UIE_Pos)

#define CMSDK_TIM14_SR_CC1OF_Pos			            9
#define CMSDK_TIM14_SR_CC1OF_Msk			            (0x1ul << CMSDK_TIM14_SR_CC1OF_Pos)
#define CMSDK_TIM14_SR_BIF_Pos		                7
#define CMSDK_TIM14_SR_BIF_Msk		                (0x1ul << CMSDK_TIM14_SR_BIF_Pos)
#define CMSDK_TIM14_SR_TIF_Pos		                6
#define CMSDK_TIM14_SR_TIF_Msk		                (0x1ul << CMSDK_TIM14_SR_TIF_Pos)
#define CMSDK_TIM14_SR_COMIF_Pos			            5
#define CMSDK_TIM14_SR_COMIF_Msk			            (0x1ul << CMSDK_TIM14_SR_COMIF_Pos)
#define CMSDK_TIM14_SR_CC1IF_Pos		              1
#define CMSDK_TIM14_SR_CC1IF_Msk		              (0x1ul << CMSDK_TIM14_SR_CC1IF_Pos)
#define CMSDK_TIM14_SR_UIF_Pos		                0
#define CMSDK_TIM14_SR_UIF_Msk		                (0x1ul << CMSDK_TIM14_SR_UIF_Pos)

#define CMSDK_TIM14_EGR_BG_Pos		                    7
#define CMSDK_TIM14_EGR_BG_Msk		                    (0x1ul << CMSDK_TIM14_EGR_BG_Pos)
#define CMSDK_TIM14_EGR_TG_Pos		                    6
#define CMSDK_TIM14_EGR_TG_Msk		                    (0x1ul << CMSDK_TIM14_EGR_TG_Pos)
#define CMSDK_TIM14_EGR_COMG_Pos		                  5
#define CMSDK_TIM14_EGR_COMG_Msk		                  (0x1ul << CMSDK_TIM14_EGR_COMG_Pos)
#define CMSDK_TIM14_EGR_CC1G_Pos		                  1
#define CMSDK_TIM14_EGR_CC1G_Msk		                  (0x1ul << CMSDK_TIM14_EGR_CC1G_Pos)
#define CMSDK_TIM14_EGR_UG_Pos		                    0
#define CMSDK_TIM14_EGR_UG_Msk		                    (0x1ul << CMSDK_TIM14_EGR_UG_Pos)

#define CMSDK_TIM14_CCMR_IC1F_Pos					            4
#define CMSDK_TIM14_CCMR_IC1F_Msk					            (0xFul << CMSDK_TIM14_CCMR_IC1F_Pos)
#define CMSDK_TIM14_CCMR_IC1PSC_Pos					          2
#define CMSDK_TIM14_CCMR_IC1PSC_Msk					          (0x3ul << CMSDK_TIM14_CCMR_IC1PSC_Pos)
#define CMSDK_TIM14_CCMR_OC1M_Pos					            4
#define CMSDK_TIM14_CCMR_OC1M_Msk					            (0xFul << CMSDK_TIM14_CCMR_OC1M_Pos)
#define CMSDK_TIM14_CCMR_OC1PE_Pos					          3
#define CMSDK_TIM14_CCMR_OC1PE_Msk					          (0x1ul << CMSDK_TIM14_CCMR_OC1PE_Pos)
#define CMSDK_TIM14_CCMR_OC1FE_Pos					          2
#define CMSDK_TIM14_CCMR_OC1FE_Msk					          (0x1ul << CMSDK_TIM14_CCMR_OC1FE_Pos)
#define CMSDK_TIM14_CCMR_CC1S_Pos					            0
#define CMSDK_TIM14_CCMR_CC1S_Msk					            (0x3ul << CMSDK_TIM14_CCMR_CC1S_Pos)

#define CMSDK_TIM14_CCER_CC1NP_Pos					          3
#define CMSDK_TIM14_CCER_CC1NP_Msk					          (0x1ul << CMSDK_TIM14_CCER_CC1NP_Pos)
#define CMSDK_TIM14_CCER_CC1NE_Pos					          2
#define CMSDK_TIM14_CCER_CC1NE_Msk					          (0x1ul << CMSDK_TIM14_CCER_CC1NE_Pos)
#define CMSDK_TIM14_CCER_CC1P_Pos					            1
#define CMSDK_TIM14_CCER_CC1P_Msk					            (0x1ul << CMSDK_TIM14_CCER_CC1P_Pos)
#define CMSDK_TIM14_CCER_CC1E_Pos					            0
#define CMSDK_TIM14_CCER_CC1E_Msk					            (0x1ul << CMSDK_TIM14_CCER_CC1E_Pos)

#define CMSDK_TIM14_CNT_UIFCPY_Pos	                  31
#define CMSDK_TIM14_CNT_UIFCPY_Msk	                  (0x1ul << CMSDK_TIM14_CNT_UIFCPY_Pos)
#define CMSDK_TIM14_CNT_Cnt_Pos			                  0
#define CMSDK_TIM14_CNT_Cnt_Msk			                  (0xFFFFul << CMSDK_TIM14_CNT_Cnt_Pos)

#define CMSDK_TIM14_PSC_Pos					                  0
#define CMSDK_TIM14_PSC_Msk					                  (0xFFFFul << CMSDK_TIM14_PSC_Pos)

#define CMSDK_TIM14_ARR_Pos					                  0
#define CMSDK_TIM14_ARR_Msk					                  (0xFFFFul << CMSDK_TIM14_ARR_Pos)

#define CMSDK_TIM14_RCR_REP_Pos					              0
#define CMSDK_TIM14_RCR_REP_Msk					              (0xFFul << CMSDK_TIM14_RCR_REP_Pos)

#define CMSDK_TIM14_CCR1_Pos					                0
#define CMSDK_TIM14_CCR1_Msk					                (0xFFFFul << CMSDK_TIM14_CCR1_Pos)

#define CMSDK_TIM14_BDTR_BKF_Pos			                16
#define CMSDK_TIM14_BDTR_BKF_Msk			                (0xFFFFul << CMSDK_TIM14_BDTR_BKF_Pos)
#define CMSDK_TIM14_BDTR_MOE_Pos			                15
#define CMSDK_TIM14_BDTR_MOE_Msk			                (0x1ul << CMSDK_TIM14_BDTR_MOE_Pos)
#define CMSDK_TIM14_BDTR_AOE_Pos			                14
#define CMSDK_TIM14_BDTR_AOE_Msk			                (0x1ul << CMSDK_TIM14_BDTR_AOE_Pos)
#define CMSDK_TIM14_BDTR_BKP_Pos			                13
#define CMSDK_TIM14_BDTR_BKP_Msk			                (0x1ul << CMSDK_TIM14_BDTR_BKP_Pos)
#define CMSDK_TIM14_BDTR_BKE_Pos			                12
#define CMSDK_TIM14_BDTR_BKE_Msk			                (0x1ul << CMSDK_TIM14_BDTR_BKE_Pos)
#define CMSDK_TIM14_BDTR_OSSR_Pos			                11
#define CMSDK_TIM14_BDTR_OSSR_Msk			                (0x1ul << CMSDK_TIM14_BDTR_OSSR_Pos)
#define CMSDK_TIM14_BDTR_OSSI_Pos			                10
#define CMSDK_TIM14_BDTR_OSSI_Msk			                (0x1ul << CMSDK_TIM14_BDTR_OSSI_Pos)
#define CMSDK_TIM14_BDTR_LOCK_Pos			                8
#define CMSDK_TIM14_BDTR_LOCK_Msk			                (0x3ul << CMSDK_TIM14_BDTR_LOCK_Pos)
#define CMSDK_TIM14_BDTR_DTG_Pos			                0
#define CMSDK_TIM14_BDTR_DTG_Msk			                (0xFFul << CMSDK_TIM14_BDTR_DTG_Pos)

#define CMSDK_TIM14_DCR_DBL_Pos					              8
#define CMSDK_TIM14_DCR_DBL_Msk					              (0x1Ful << CMSDK_TIM14_DCR_DBL_Pos)
#define CMSDK_TIM14_DCR_DBA_Pos					              0
#define CMSDK_TIM14_DCR_DBA_Msk					              (0x1Ful << CMSDK_TIM14_DCR_DBA_Pos)

#define CMSDK_TIM14_DMAR_DMAB_Pos					            0
#define CMSDK_TIM14_DMAR_DMAB_Msk					            (0xFFFFul << CMSDK_TIM14_DMAR_DMAB_Pos)

#define CMSDK_TIM14_AF1_BKCMP2P_Pos			              11
#define CMSDK_TIM14_AF1_BKCMP2P_Msk			              (0x1ul << CMSDK_TIM14_AF1_BKCMP2P_Pos)
#define CMSDK_TIM14_AF1_BKCMP1P_Pos			              10
#define CMSDK_TIM14_AF1_BKCMP1P_Msk			              (0x1ul << CMSDK_TIM14_AF1_BKCMP1P_Pos)
#define CMSDK_TIM14_AF1_BKINP_Pos			                9
#define CMSDK_TIM14_AF1_BKINP_Msk			                (0x1ul << CMSDK_TIM14_AF1_BKINP_Pos)
#define CMSDK_TIM14_AF1_BKCMP2E_Pos			              2
#define CMSDK_TIM14_AF1_BKCMP2E_Msk			              (0x1ul << CMSDK_TIM14_AF1_BKCMP2E_Pos)
#define CMSDK_TIM14_AF1_BKCMP1E_Pos			              1
#define CMSDK_TIM14_AF1_BKCMP1E_Msk			              (0x1ul << CMSDK_TIM14_AF1_BKCMP1E_Pos)
#define CMSDK_TIM14_AF1_BKINE_Pos			                0
#define CMSDK_TIM14_AF1_BKINE_Msk			                (0x1ul << CMSDK_TIM14_AF1_BKINE_Pos)

#define CMSDK_TIM14_TISEL_Pos					                0
#define CMSDK_TIM14_TISEL_Msk					                (0xFul << CMSDK_TIM14_TISEL_Pos)
/*@}*/ /* end of group CMSDK_TIM14 */


/* CMSDK_TIM14 Register Definitions */
//#define CMSDK_TIM1_CR1_UIFREMAP_Pos				        11
//#define CMSDK_TIM1_CR1_UIFREMAP_Msk				        (0x1ul << CMSDK_TIM1_CR1_UIFREMAP_Pos)
#define CMSDK_TIM1_CR1_CKD_Pos		                8
#define CMSDK_TIM1_CR1_CKD_Msk		                (0x3ul << CMSDK_TIM1_CR1_CKD_Pos)
#define CMSDK_TIM1_CR1_ARPE_Pos		                7
#define CMSDK_TIM1_CR1_ARPE_Msk		                (0x1ul << CMSDK_TIM1_CR1_ARPE_Pos)
#define CMSDK_TIM1_CR1_CMS_Pos		                5
#define CMSDK_TIM1_CR1_CMS_Msk		                (0x3ul << CMSDK_TIM1_CR1_CMS_Pos)
#define CMSDK_TIM1_CR1_DIR_Pos		                4
#define CMSDK_TIM1_CR1_DIR_Msk		                (0x1ul << CMSDK_TIM1_CR1_DIR_Pos)
#define CMSDK_TIM1_CR1_OPM_Pos                    3
#define CMSDK_TIM1_CR1_OPM_Msk                    (0x1ul << CMSDK_TIM1_CR1_OPM_Pos)
#define CMSDK_TIM1_CR1_URS_Pos                    2
#define CMSDK_TIM1_CR1_URS_Msk                    (0x1ul << CMSDK_TIM1_CR1_URS_Pos)
#define CMSDK_TIM1_CR1_UDIS_Pos                   1
#define CMSDK_TIM1_CR1_UDIS_Msk                   (0x1ul << CMSDK_TIM1_CR1_UDIS_Pos)
#define CMSDK_TIM1_CR1_CEN_Pos                    0
#define CMSDK_TIM1_CR1_CEN_Msk                    (0x1ul << CMSDK_TIM1_CR1_CEN_Pos)

#define CMSDK_TIM1_CR2_OIS4_Pos		                15
#define CMSDK_TIM1_CR2_OIS4_Msk		                (0x1ul << CMSDK_TIM1_CR2_OIS4_Pos)
#define CMSDK_TIM1_CR2_OIS3N_Pos				          14
#define CMSDK_TIM1_CR2_OIS3N_Msk				          (0x1ul << CMSDK_TIM1_CR2_OIS3N_Pos)
#define CMSDK_TIM1_CR2_OIS3_Pos		                13
#define CMSDK_TIM1_CR2_OIS3_Msk		                (0x1ul << CMSDK_TIM1_CR2_OIS3_Pos)
#define CMSDK_TIM1_CR2_OIS2N_Pos				          12
#define CMSDK_TIM1_CR2_OIS2N_Msk				          (0x1ul << CMSDK_TIM1_CR2_OIS2N_Pos)
#define CMSDK_TIM1_CR2_OIS2_Pos		                11
#define CMSDK_TIM1_CR2_OIS2_Msk		                (0x1ul << CMSDK_TIM1_CR2_OIS2_Pos)
#define CMSDK_TIM1_CR2_OIS1N_Pos				          10
#define CMSDK_TIM1_CR2_OIS1N_Msk				          (0x1ul << CMSDK_TIM1_CR2_OIS1N_Pos)
#define CMSDK_TIM1_CR2_OIS1_Pos		                9
#define CMSDK_TIM1_CR2_OIS1_Msk		                (0x1ul << CMSDK_TIM1_CR2_OIS1_Pos)
#define CMSDK_TIM1_CR2_TI1S_Pos		                8
#define CMSDK_TIM1_CR2_TI1S_Msk		                (0x1ul << CMSDK_TIM1_CR2_TI1S_Pos)
#define CMSDK_TIM1_CR2_MMS_Pos		                4
#define CMSDK_TIM1_CR2_MMS_Msk		                (0xFul << CMSDK_TIM1_CR2_MMS_Pos)
#define CMSDK_TIM1_CR2_CCDS_Pos                   3
#define CMSDK_TIM1_CR2_CCDS_Msk                   (0x1ul << CMSDK_TIM1_CR2_CCDS_Pos)
#define CMSDK_TIM1_CR2_CCUS_Pos                   2
#define CMSDK_TIM1_CR2_CCUS_Msk                   (0x1ul << CMSDK_TIM1_CR2_CCUS_Pos)
#define CMSDK_TIM1_CR2_CCPC_Pos                   0
#define CMSDK_TIM1_CR2_CCPC_Msk                   (0x1ul << CMSDK_TIM1_CR2_CCPC_Pos)

#define CMSDK_TIM1_SMCR_ETP_Pos			                15
#define CMSDK_TIM1_SMCR_ETP_Msk			                (0x1ul << CMSDK_TIM1_SMCR_ETP_Pos)
#define CMSDK_TIM1_SMCR_ECE_Pos			                14
#define CMSDK_TIM1_SMCR_ECE_Msk			                (0x1ul << CMSDK_TIM1_SMCR_ECE_Pos)
#define CMSDK_TIM1_SMCR_ETPS_Pos			              12
#define CMSDK_TIM1_SMCR_ETPS_Msk			              (0x3ul << CMSDK_TIM1_SMCR_ETPS_Pos)
#define CMSDK_TIM1_SMCR_ETF_Pos			                8
#define CMSDK_TIM1_SMCR_ETF_Msk			                (0xFul << CMSDK_TIM1_SMCR_ETF_Pos)
#define CMSDK_TIM1_SMCR_MSM_Pos			                7
#define CMSDK_TIM1_SMCR_MSM_Msk			                (0x1ul << CMSDK_TIM1_SMCR_MSM_Pos)
#define CMSDK_TIM1_SMCR_TS_Pos		                  4
#define CMSDK_TIM1_SMCR_TS_Msk		                  (0x7ul << CMSDK_TIM1_SMCR_TS_Pos)
#define CMSDK_TIM1_SMCR_SMS_Pos		                  0
#define CMSDK_TIM1_SMCR_SMS_Msk		                  (0x7ul << CMSDK_TIM1_SMCR_SMS_Pos)

#define CMSDK_TIM1_DIER_TDE_Pos			                14
#define CMSDK_TIM1_DIER_TDE_Msk			                (0x1ul << CMSDK_TIM1_DIER_TDE_Pos)
#define CMSDK_TIM1_DIER_COMDE_Pos			              13
#define CMSDK_TIM1_DIER_COMDE_Msk			              (0x1ul << CMSDK_TIM1_DIER_COMDE_Pos)
#define CMSDK_TIM1_DIER_CC4DE_Pos			              12
#define CMSDK_TIM1_DIER_CC4DE_Msk			              (0x1ul << CMSDK_TIM1_DIER_CC4DE_Pos)
#define CMSDK_TIM1_DIER_CC3DE_Pos			              11
#define CMSDK_TIM1_DIER_CC3DE_Msk			              (0x1ul << CMSDK_TIM1_DIER_CC3DE_Pos)
#define CMSDK_TIM1_DIER_CC2DE_Pos			              10
#define CMSDK_TIM1_DIER_CC2DE_Msk			              (0x1ul << CMSDK_TIM1_DIER_CC2DE_Pos)
#define CMSDK_TIM1_DIER_CC1DE_Pos			              9
#define CMSDK_TIM1_DIER_CC1DE_Msk			              (0x1ul << CMSDK_TIM1_DIER_CC1DE_Pos)
#define CMSDK_TIM1_DIER_UDE_Pos			                8
#define CMSDK_TIM1_DIER_UDE_Msk			                (0x1ul << CMSDK_TIM1_DIER_UDE_Pos)
#define CMSDK_TIM1_DIER_BIE_Pos			                7
#define CMSDK_TIM1_DIER_BIE_Msk			                (0x1ul << CMSDK_TIM1_DIER_BIE_Pos)
#define CMSDK_TIM1_DIER_TIE_Pos			                6
#define CMSDK_TIM1_DIER_TIE_Msk			                (0x1ul << CMSDK_TIM1_DIER_TIE_Pos)
#define CMSDK_TIM1_DIER_COMIE_Pos			              5
#define CMSDK_TIM1_DIER_COMIE_Msk			              (0x1ul << CMSDK_TIM1_DIER_COMIE_Pos)
#define CMSDK_TIM1_DIER_CC4IE_Pos			              4
#define CMSDK_TIM1_DIER_CC4IE_Msk			              (0x1ul << CMSDK_TIM1_DIER_CC4IE_Pos)
#define CMSDK_TIM1_DIER_CC3IE_Pos			              3
#define CMSDK_TIM1_DIER_CC3IE_Msk			              (0x1ul << CMSDK_TIM1_DIER_CC3IE_Pos)
#define CMSDK_TIM1_DIER_CC2IE_Pos			              2
#define CMSDK_TIM1_DIER_CC2IE_Msk			              (0x1ul << CMSDK_TIM1_DIER_CC2IE_Pos)
#define CMSDK_TIM1_DIER_CC1IE_Pos			              1
#define CMSDK_TIM1_DIER_CC1IE_Msk			              (0x1ul << CMSDK_TIM1_DIER_CC1IE_Pos)
#define CMSDK_TIM1_DIER_UIE_Pos			                0
#define CMSDK_TIM1_DIER_UIE_Msk			                (0x1ul << CMSDK_TIM1_DIER_UIE_Pos)

#define CMSDK_TIM1_SR_CC4OF_Pos			            12
#define CMSDK_TIM1_SR_CC4OF_Msk			            (0x1ul << CMSDK_TIM1_SR_CC4OF_Pos)
#define CMSDK_TIM1_SR_CC3OF_Pos			            11
#define CMSDK_TIM1_SR_CC3OF_Msk			            (0x1ul << CMSDK_TIM1_SR_CC3OF_Pos)
#define CMSDK_TIM1_SR_CC2OF_Pos			            10
#define CMSDK_TIM1_SR_CC2OF_Msk			            (0x1ul << CMSDK_TIM1_SR_CC2OF_Pos)
#define CMSDK_TIM1_SR_CC1OF_Pos			            9
#define CMSDK_TIM1_SR_CC1OF_Msk			            (0x1ul << CMSDK_TIM1_SR_CC1OF_Pos)
#define CMSDK_TIM1_SR_BIF_Pos		                7
#define CMSDK_TIM1_SR_BIF_Msk		                (0x1ul << CMSDK_TIM1_SR_BIF_Pos)
#define CMSDK_TIM1_SR_TIF_Pos		                6
#define CMSDK_TIM1_SR_TIF_Msk		                (0x1ul << CMSDK_TIM1_SR_TIF_Pos)
#define CMSDK_TIM1_SR_COMIF_Pos			            5
#define CMSDK_TIM1_SR_COMIF_Msk			            (0x1ul << CMSDK_TIM1_SR_COMIF_Pos)
#define CMSDK_TIM1_SR_CC4IF_Pos		              4
#define CMSDK_TIM1_SR_CC4IF_Msk		              (0x1ul << CMSDK_TIM1_SR_CC4IF_Pos)
#define CMSDK_TIM1_SR_CC3IF_Pos		              3
#define CMSDK_TIM1_SR_CC3IF_Msk		              (0x1ul << CMSDK_TIM1_SR_CC3IF_Pos)
#define CMSDK_TIM1_SR_CC2IF_Pos		              2
#define CMSDK_TIM1_SR_CC2IF_Msk		              (0x1ul << CMSDK_TIM1_SR_CC2IF_Pos)
#define CMSDK_TIM1_SR_CC1IF_Pos		              1
#define CMSDK_TIM1_SR_CC1IF_Msk		              (0x1ul << CMSDK_TIM1_SR_CC1IF_Pos)
#define CMSDK_TIM1_SR_UIF_Pos		                0
#define CMSDK_TIM1_SR_UIF_Msk		                (0x1ul << CMSDK_TIM1_SR_UIF_Pos)

#define CMSDK_TIM1_EGR_BG_Pos		                    7
#define CMSDK_TIM1_EGR_BG_Msk		                    (0x1ul << CMSDK_TIM1_EGR_BG_Pos)
#define CMSDK_TIM1_EGR_TG_Pos		                    6
#define CMSDK_TIM1_EGR_TG_Msk		                    (0x1ul << CMSDK_TIM1_EGR_TG_Pos)
#define CMSDK_TIM1_EGR_COMG_Pos		                  5
#define CMSDK_TIM1_EGR_COMG_Msk		                  (0x1ul << CMSDK_TIM1_EGR_COMG_Pos)
#define CMSDK_TIM1_EGR_CC4G_Pos		                  4
#define CMSDK_TIM1_EGR_CC4G_Msk		                  (0x1ul << CMSDK_TIM1_EGR_CC4G_Pos)
#define CMSDK_TIM1_EGR_CC3G_Pos		                  3
#define CMSDK_TIM1_EGR_CC3G_Msk		                  (0x1ul << CMSDK_TIM1_EGR_CC3G_Pos)
#define CMSDK_TIM1_EGR_CC2G_Pos		                  2
#define CMSDK_TIM1_EGR_CC2G_Msk		                  (0x1ul << CMSDK_TIM1_EGR_CC2G_Pos)
#define CMSDK_TIM1_EGR_CC1G_Pos		                  1
#define CMSDK_TIM1_EGR_CC1G_Msk		                  (0x1ul << CMSDK_TIM1_EGR_CC1G_Pos)
#define CMSDK_TIM1_EGR_UG_Pos		                    0
#define CMSDK_TIM1_EGR_UG_Msk		                    (0x1ul << CMSDK_TIM1_EGR_UG_Pos)

#define CMSDK_TIM1_CCMR1_OC2M3_Pos					        17
#define CMSDK_TIM1_CCMR1_OC2M3_Msk					        (0x1ul << CMSDK_TIM1_CCMR1_OC2M3_Pos)
#define CMSDK_TIM1_CCMR1_OC1M3_Pos					        16
#define CMSDK_TIM1_CCMR1_OC1M3_Msk					        (0x1ul << CMSDK_TIM1_CCMR1_OC1M3_Pos)
#define CMSDK_TIM1_CCMR1_OC2CE_Pos					        15
#define CMSDK_TIM1_CCMR1_OC2CE_Msk					        (0x1ul << CMSDK_TIM1_CCMR1_OC2CE_Pos)
#define CMSDK_TIM1_CCMR1_IC2F_Pos					          12
#define CMSDK_TIM1_CCMR1_IC2F_Msk					          (0xFul << CMSDK_TIM1_CCMR1_IC2F_Pos)
#define CMSDK_TIM1_CCMR1_IC2PSC_Pos					        10
#define CMSDK_TIM1_CCMR1_IC2PSC_Msk					        (0x3ul << CMSDK_TIM1_CCMR1_IC2PSC_Pos)
#define CMSDK_TIM1_CCMR1_OC2M_Pos					          12
#define CMSDK_TIM1_CCMR1_OC2M_Msk					          (0x7ul << CMSDK_TIM1_CCMR1_OC2M_Pos)
#define CMSDK_TIM1_CCMR1_OC2PE_Pos					        11
#define CMSDK_TIM1_CCMR1_OC2PE_Msk					        (0x1ul << CMSDK_TIM1_CCMR1_OC2PE_Pos)
#define CMSDK_TIM1_CCMR1_OC2FE_Pos					        10
#define CMSDK_TIM1_CCMR1_OC2FE_Msk					        (0x1ul << CMSDK_TIM1_CCMR1_OC2FE_Pos)
#define CMSDK_TIM1_CCMR1_CC2S_Pos					          8
#define CMSDK_TIM1_CCMR1_CC2S_Msk					          (0x3ul << CMSDK_TIM1_CCMR1_CC2S_Pos)
#define CMSDK_TIM1_CCMR1_OC1CE_Pos					        7
#define CMSDK_TIM1_CCMR1_OC1CE_Msk					        (0x1ul << CMSDK_TIM1_CCMR1_OC1CE_Pos)
#define CMSDK_TIM1_CCMR1_IC1F_Pos					          4
#define CMSDK_TIM1_CCMR1_IC1F_Msk					          (0xFul << CMSDK_TIM1_CCMR1_IC1F_Pos)
#define CMSDK_TIM1_CCMR1_IC1PSC_Pos					        2
#define CMSDK_TIM1_CCMR1_IC1PSC_Msk					        (0x3ul << CMSDK_TIM1_CCMR1_IC1PSC_Pos)
#define CMSDK_TIM1_CCMR1_OC1M_Pos					          4
#define CMSDK_TIM1_CCMR1_OC1M_Msk					          (0x7ul << CMSDK_TIM1_CCMR1_OC1M_Pos)
#define CMSDK_TIM1_CCMR1_OC1PE_Pos					        3
#define CMSDK_TIM1_CCMR1_OC1PE_Msk					        (0x1ul << CMSDK_TIM1_CCMR1_OC1PE_Pos)
#define CMSDK_TIM1_CCMR1_OC1FE_Pos					        2
#define CMSDK_TIM1_CCMR1_OC1FE_Msk					        (0x1ul << CMSDK_TIM1_CCMR1_OC1FE_Pos)
#define CMSDK_TIM1_CCMR1_CC1S_Pos					          0
#define CMSDK_TIM1_CCMR1_CC1S_Msk					          (0x3ul << CMSDK_TIM1_CCMR1_CC1S_Pos)


#define CMSDK_TIM1_CCMR2_OC4M3_Pos					        17
#define CMSDK_TIM1_CCMR2_OC4M3_Msk					        (0x1ul << CMSDK_TIM1_CCMR2_OC4M3_Pos)
#define CMSDK_TIM1_CCMR2_OC3M3_Pos					        16
#define CMSDK_TIM1_CCMR2_OC3M3_Msk					        (0x1ul << CMSDK_TIM1_CCMR2_OC3M3_Pos)
#define CMSDK_TIM1_CCMR2_OC4CE_Pos					        15
#define CMSDK_TIM1_CCMR2_OC4CE_Msk					        (0x1ul << CMSDK_TIM1_CCMR2_OC4CE_Pos)
#define CMSDK_TIM1_CCMR2_IC4F_Pos					          12
#define CMSDK_TIM1_CCMR2_IC4F_Msk					          (0xFul << CMSDK_TIM1_CCMR2_IC4F_Pos)
#define CMSDK_TIM1_CCMR2_IC4PSC_Pos					        10
#define CMSDK_TIM1_CCMR2_IC4PSC_Msk					        (0x3ul << CMSDK_TIM1_CCMR2_IC4PSC_Pos)
#define CMSDK_TIM1_CCMR2_OC4M_Pos					          12
#define CMSDK_TIM1_CCMR2_OC4M_Msk					          (0x7ul << CMSDK_TIM1_CCMR2_OC4M_Pos)
#define CMSDK_TIM1_CCMR2_OC4PE_Pos					        11
#define CMSDK_TIM1_CCMR2_OC4PE_Msk					        (0x1ul << CMSDK_TIM1_CCMR2_OC4PE_Pos)
#define CMSDK_TIM1_CCMR2_OC4FE_Pos					        10
#define CMSDK_TIM1_CCMR2_OC4FE_Msk					        (0x1ul << CMSDK_TIM1_CCMR2_OC4FE_Pos)
#define CMSDK_TIM1_CCMR2_CC4S_Pos					          8
#define CMSDK_TIM1_CCMR2_CC4S_Msk					          (0x3ul << CMSDK_TIM1_CCMR2_CC4S_Pos)
#define CMSDK_TIM1_CCMR2_OC3CE_Pos					        7
#define CMSDK_TIM1_CCMR2_OC3CE_Msk					        (0x1ul << CMSDK_TIM1_CCMR2_OC3CE_Pos)
#define CMSDK_TIM1_CCMR2_IC3F_Pos					          4
#define CMSDK_TIM1_CCMR2_IC3F_Msk					          (0xFul << CMSDK_TIM1_CCMR2_IC3F_Pos)
#define CMSDK_TIM1_CCMR2_IC3PSC_Pos					        2
#define CMSDK_TIM1_CCMR2_IC3PSC_Msk					        (0x3ul << CMSDK_TIM1_CCMR2_IC3PSC_Pos)
#define CMSDK_TIM1_CCMR2_OC3M_Pos					          4
#define CMSDK_TIM1_CCMR2_OC3M_Msk					          (0x7ul << CMSDK_TIM1_CCMR2_OC3M_Pos)
#define CMSDK_TIM1_CCMR2_OC3PE_Pos					        3
#define CMSDK_TIM1_CCMR2_OC3PE_Msk					        (0x1ul << CMSDK_TIM1_CCMR2_OC3PE_Pos)
#define CMSDK_TIM1_CCMR2_OC3FE_Pos					        2
#define CMSDK_TIM1_CCMR2_OC3FE_Msk					        (0x1ul << CMSDK_TIM1_CCMR2_OC3FE_Pos)
#define CMSDK_TIM1_CCMR2_CC3S_Pos					          0
#define CMSDK_TIM1_CCMR2_CC3S_Msk					          (0x3ul << CMSDK_TIM1_CCMR2_CC3S_Pos)

#define CMSDK_TIM1_CCER_CC4P_Pos					          13
#define CMSDK_TIM1_CCER_CC4P_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC4P_Pos)
#define CMSDK_TIM1_CCER_CC4E_Pos					          12
#define CMSDK_TIM1_CCER_CC4E_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC4E_Pos)
#define CMSDK_TIM1_CCER_CC3NP_Pos					          11
#define CMSDK_TIM1_CCER_CC3NP_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC3NP_Pos)
#define CMSDK_TIM1_CCER_CC3NE_Pos					          10
#define CMSDK_TIM1_CCER_CC3NE_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC3NE_Pos)
#define CMSDK_TIM1_CCER_CC3P_Pos					          9
#define CMSDK_TIM1_CCER_CC3P_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC3P_Pos)
#define CMSDK_TIM1_CCER_CC3E_Pos					          8
#define CMSDK_TIM1_CCER_CC3E_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC3E_Pos)
#define CMSDK_TIM1_CCER_CC2NP_Pos					          7
#define CMSDK_TIM1_CCER_CC2NP_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC2NP_Pos)
#define CMSDK_TIM1_CCER_CC2NE_Pos					          6
#define CMSDK_TIM1_CCER_CC2NE_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC2NE_Pos)
#define CMSDK_TIM1_CCER_CC2P_Pos					          5
#define CMSDK_TIM1_CCER_CC2P_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC2P_Pos)
#define CMSDK_TIM1_CCER_CC2E_Pos					          4
#define CMSDK_TIM1_CCER_CC2E_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC2E_Pos)
#define CMSDK_TIM1_CCER_CC1NP_Pos					          3
#define CMSDK_TIM1_CCER_CC1NP_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC1NP_Pos)
#define CMSDK_TIM1_CCER_CC1NE_Pos					          2
#define CMSDK_TIM1_CCER_CC1NE_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC1NE_Pos)
#define CMSDK_TIM1_CCER_CC1P_Pos					          1
#define CMSDK_TIM1_CCER_CC1P_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC1P_Pos)
#define CMSDK_TIM1_CCER_CC1E_Pos					          0
#define CMSDK_TIM1_CCER_CC1E_Msk					          (0x1ul << CMSDK_TIM1_CCER_CC1E_Pos)

#define CMSDK_TIM1_CNT_UIFCPY_Pos	                  31
#define CMSDK_TIM1_CNT_UIFCPY_Msk	                  (0x1ul << CMSDK_TIM1_CNT_UIFCPY_Pos)
#define CMSDK_TIM1_CNT_Pos			                    0
#define CMSDK_TIM1_CNT_Msk			                    (0xFFFFul << CMSDK_TIM1_CNT_Pos)

#define CMSDK_TIM1_PSC_Pos					                0
#define CMSDK_TIM1_PSC_Msk					                (0xFFFFul << CMSDK_TIM1_PSC_Pos)

#define CMSDK_TIM1_ARR_Pos					                0
#define CMSDK_TIM1_ARR_Msk					                (0xFFFFul << CMSDK_TIM1_ARR_Pos)

#define CMSDK_TIM1_RCR_REP_Pos					            0
#define CMSDK_TIM1_RCR_REP_Msk					            (0xFFul << CMSDK_TIM1_RCR_REP_Pos)

#define CMSDK_TIM1_CCR1_ASYM_Pos					          16
#define CMSDK_TIM1_CCR1_ASYM_Msk					          (0xFFFFul << CMSDK_TIM1_CCR1_ASYM_Pos)
#define CMSDK_TIM1_CCR1_Pos					                0
#define CMSDK_TIM1_CCR1_Msk					                (0xFFFFul << CMSDK_TIM1_CCR1_Pos)

#define CMSDK_TIM1_CCR2_ASYM_Pos					          16
#define CMSDK_TIM1_CCR2_ASYM_Msk					          (0xFFFFul << CMSDK_TIM1_CCR2_ASYM_Pos)
#define CMSDK_TIM1_CCR2_Pos					                0
#define CMSDK_TIM1_CCR2_Msk					                (0xFFFFul << CMSDK_TIM1_CCR2_Pos)

#define CMSDK_TIM1_CCR3_ASYM_Pos					          16
#define CMSDK_TIM1_CCR3_ASYM_Msk					          (0xFFFFul << CMSDK_TIM1_CCR3_ASYM_Pos)
#define CMSDK_TIM1_CCR3_Pos					                0
#define CMSDK_TIM1_CCR3_Msk					                (0xFFFFul << CMSDK_TIM1_CCR3_Pos)

#define CMSDK_TIM1_CCR4_ASYM_Pos					          16
#define CMSDK_TIM1_CCR4_ASYM_Msk					          (0xFFFFul << CMSDK_TIM1_CCR4_ASYM_Pos)
#define CMSDK_TIM1_CCR4_Pos					                0
#define CMSDK_TIM1_CCR4_Msk					                (0xFFFFul << CMSDK_TIM1_CCR4_Pos)

//#define CMSDK_TIM1_BDTR_BKF_Pos			                16
//#define CMSDK_TIM1_BDTR_BKF_Msk			                (0xFFFFul << CMSDK_TIM1_BDTR_BKF_Pos)
#define CMSDK_TIM1_BDTR_MOE_Pos			                15
#define CMSDK_TIM1_BDTR_MOE_Msk			                (0x1ul << CMSDK_TIM1_BDTR_MOE_Pos)
#define CMSDK_TIM1_BDTR_AOE_Pos			                14
#define CMSDK_TIM1_BDTR_AOE_Msk			                (0x1ul << CMSDK_TIM1_BDTR_AOE_Pos)
#define CMSDK_TIM1_BDTR_BKP_Pos			                13
#define CMSDK_TIM1_BDTR_BKP_Msk			                (0x1ul << CMSDK_TIM1_BDTR_BKP_Pos)
#define CMSDK_TIM1_BDTR_BKE_Pos			                12
#define CMSDK_TIM1_BDTR_BKE_Msk			                (0x1ul << CMSDK_TIM1_BDTR_BKE_Pos)
#define CMSDK_TIM1_BDTR_OSSR_Pos			              11
#define CMSDK_TIM1_BDTR_OSSR_Msk			              (0x1ul << CMSDK_TIM1_BDTR_OSSR_Pos)
#define CMSDK_TIM1_BDTR_OSSI_Pos			              10
#define CMSDK_TIM1_BDTR_OSSI_Msk			              (0x1ul << CMSDK_TIM1_BDTR_OSSI_Pos)
#define CMSDK_TIM1_BDTR_LOCK_Pos			              8
#define CMSDK_TIM1_BDTR_LOCK_Msk			              (0x3ul << CMSDK_TIM1_BDTR_LOCK_Pos)
#define CMSDK_TIM1_BDTR_DTG_Pos			                0
#define CMSDK_TIM1_BDTR_DTG_Msk			                (0xFFul << CMSDK_TIM1_BDTR_DTG_Pos)

#define CMSDK_TIM1_DCR_DBL_Pos					            8
#define CMSDK_TIM1_DCR_DBL_Msk					            (0x1Ful << CMSDK_TIM1_DCR_DBL_Pos)
#define CMSDK_TIM1_DCR_DBA_Pos					            0
#define CMSDK_TIM1_DCR_DBA_Msk					            (0x1Ful << CMSDK_TIM1_DCR_DBA_Pos)

#define CMSDK_TIM1_DMAR_DMAB_Pos					          0
#define CMSDK_TIM1_DMAR_DMAB_Msk					          (0xFFFFul << CMSDK_TIM1_DMAR_DMAB_Pos)

//#define CMSDK_TIM1_AF1_BKCMP2P_Pos			            11
//#define CMSDK_TIM1_AF1_BKCMP2P_Msk			            (0x1ul << CMSDK_TIM1_AF1_BKCMP2P_Pos)
//#define CMSDK_TIM1_AF1_BKCMP1P_Pos			            10
//#define CMSDK_TIM1_AF1_BKCMP1P_Msk			            (0x1ul << CMSDK_TIM1_AF1_BKCMP1P_Pos)
//#define CMSDK_TIM1_AF1_BKINP_Pos			              9
//#define CMSDK_TIM1_AF1_BKINP_Msk			              (0x1ul << CMSDK_TIM1_AF1_BKINP_Pos)
//#define CMSDK_TIM1_AF1_BKCMP2E_Pos			            2
//#define CMSDK_TIM1_AF1_BKCMP2E_Msk			            (0x1ul << CMSDK_TIM1_AF1_BKCMP2E_Pos)
//#define CMSDK_TIM1_AF1_BKCMP1E_Pos			            1
//#define CMSDK_TIM1_AF1_BKCMP1E_Msk			            (0x1ul << CMSDK_TIM1_AF1_BKCMP1E_Pos)
//#define CMSDK_TIM1_AF1_BKINE_Pos			              0
//#define CMSDK_TIM1_AF1_BKINE_Msk			              (0x1ul << CMSDK_TIM1_AF1_BKINE_Pos)
//
//#define CMSDK_TIM1_TISEL_Pos					              0
//#define CMSDK_TIM1_TISEL_Msk					              (0xFul << CMSDK_TIM1_TISEL_Pos)
/*@}*/ /* end of group CMSDK_TIM1 */


#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

/*@}*/ /* end of group CMSDK_Peripherals */


