
/*
 *-----------------------------------------------------------------------------
 *
 *      Checked In          : $Date: 2024-12-30  $
 *
 *      Creator             : liutianqi
 *
 *      Release Information : Cortex-M0 APB Peripheral TIM14
 *-----------------------------------------------------------------------------
 */

#include "sh32f0xx_tim.h"

/*
  CEN: Counter enable
  0: Counter disabled
  1: Counter enabled
*/
void TIMx_CR1(TIM_TypeDef* TIMx,  unsigned int ckd, unsigned int arpe,unsigned int cms, unsigned int dir, 
               unsigned int opm, unsigned int urs, unsigned int udis, unsigned int cen)
{
	TIMx-> CR1 = /*((uif_cpy << CMSDK_TIM1_CR1_UIFREMAP_Pos) & CMSDK_TIM1_CR1_UIFREMAP_Msk)|*/
                        ((ckd     << CMSDK_TIM1_CR1_CKD_Pos)      & CMSDK_TIM1_CR1_CKD_Msk     )|
                        ((arpe    << CMSDK_TIM1_CR1_ARPE_Pos)     & CMSDK_TIM1_CR1_ARPE_Msk    )|
                        ((cms     << CMSDK_TIM1_CR1_CMS_Pos)      & CMSDK_TIM1_CR1_CMS_Msk     )|
                        ((dir     << CMSDK_TIM1_CR1_DIR_Pos)      & CMSDK_TIM1_CR1_DIR_Msk     )|
                        ((opm     << CMSDK_TIM1_CR1_OPM_Pos)      & CMSDK_TIM1_CR1_OPM_Msk     )|
                        ((urs     << CMSDK_TIM1_CR1_URS_Pos)      & CMSDK_TIM1_CR1_URS_Msk     )|
                        ((udis    << CMSDK_TIM1_CR1_UDIS_Pos)     & CMSDK_TIM1_CR1_UDIS_Msk    )|
                        ((cen     << CMSDK_TIM1_CR1_CEN_Pos)      & CMSDK_TIM1_CR1_CEN_Msk     );
	return;
}

void TIMx_CR2(TIM_TypeDef* TIMx,  unsigned int ois4,  unsigned int ois3n, unsigned int ois3,  unsigned int ois2n, 
               unsigned int ois2,  unsigned int ois1n, unsigned int ois1, unsigned int ti1s, 
               unsigned int mms, unsigned int ccds, unsigned int ccus, unsigned int ccpc)
{
	TIMx-> CR2 =  ((ois4  << CMSDK_TIM1_CR2_OIS4_Pos)  & CMSDK_TIM1_CR2_OIS4_Msk )|
                         ((ois3n << CMSDK_TIM1_CR2_OIS3N_Pos) & CMSDK_TIM1_CR2_OIS3N_Msk)|
                         ((ois3  << CMSDK_TIM1_CR2_OIS3_Pos)  & CMSDK_TIM1_CR2_OIS3_Msk )|
                         ((ois2n << CMSDK_TIM1_CR2_OIS2N_Pos) & CMSDK_TIM1_CR2_OIS2N_Msk)|
                         ((ois2  << CMSDK_TIM1_CR2_OIS2_Pos)  & CMSDK_TIM1_CR2_OIS2_Msk )|
                         ((ois1n << CMSDK_TIM1_CR2_OIS1N_Pos) & CMSDK_TIM1_CR2_OIS1N_Msk)|
                         ((ois1  << CMSDK_TIM1_CR2_OIS1_Pos)  & CMSDK_TIM1_CR2_OIS1_Msk )|
                         ((ti1s  << CMSDK_TIM1_CR2_TI1S_Pos)  & CMSDK_TIM1_CR2_TI1S_Msk )|
                         ((mms   << CMSDK_TIM1_CR2_MMS_Pos)   & CMSDK_TIM1_CR2_MMS_Msk  )|
                         ((ccds  << CMSDK_TIM1_CR2_CCDS_Pos)  & CMSDK_TIM1_CR2_CCDS_Msk )|
                         ((ccus  << CMSDK_TIM1_CR2_CCUS_Pos)  & CMSDK_TIM1_CR2_CCUS_Msk )|
                         ((ccpc  << CMSDK_TIM1_CR2_CCPC_Pos)  & CMSDK_TIM1_CR2_CCPC_Msk );
	return;
}

void TIMx_SLV_MODE_CTRL(TIM_TypeDef* TIMx,  unsigned int etp,  unsigned int ece,  unsigned int etps, unsigned int etf,  unsigned int msm, unsigned int ts, unsigned int sms)
{
	TIMx-> SMCR = ((etp << CMSDK_TIM1_SMCR_ETP_Pos) & CMSDK_TIM1_SMCR_ETP_Msk)|
                       ((ece << CMSDK_TIM1_SMCR_ECE_Pos) & CMSDK_TIM1_SMCR_ECE_Msk)|
                       ((etps << CMSDK_TIM1_SMCR_ETPS_Pos) & CMSDK_TIM1_SMCR_ETPS_Msk)|
                       ((etf << CMSDK_TIM1_SMCR_ETF_Pos) & CMSDK_TIM1_SMCR_ETF_Msk)|
                       ((msm << CMSDK_TIM1_SMCR_MSM_Pos) & CMSDK_TIM1_SMCR_MSM_Msk)|
                       ((ts  << CMSDK_TIM1_SMCR_TS_Pos)  & CMSDK_TIM1_SMCR_TS_Msk )|
                       ((sms   << CMSDK_TIM1_SMCR_SMS_Pos) & CMSDK_TIM1_SMCR_SMS_Msk);
	return;
}

/*
  TI1SEL[3:0]: selects TI1[0] to TI1[15] input
  0000: TIM1_CH1 input
  0001: RTC CLK
  0010: HSE/32
  0011: MCO
  Others: Reserved
*/
/*void TIM1_IN_CLK_SEL( unsigned int clk_sel)
{
	CMSDK_TIM1 -> TISEL = (clk_sel << CMSDK_TIM1_TISEL_Pos) & CMSDK_TIM1_TISEL_Msk;
	return;
}*/


/*
  Bit 1 CC1IE: Capture/Compare 1 interrupt enable
  0: CC1 interrupt disabled
  1: CC1 interrupt enabled
  Bit 0 UIE: Update interrupt enable
  0: Update interrupt disabled
  1: Update interrupt enabled
*/
void TIMx_DMA_INT_EN(TIM_TypeDef* TIMx,  unsigned int tde, unsigned int comde,  unsigned int cc4de,  unsigned int cc3de,  
                      unsigned int cc2de,  unsigned int cc1de, unsigned int ude, unsigned int bie, 
                      unsigned int tie, unsigned int comie, unsigned int cc4ie, unsigned int cc3ie, 
                      unsigned int cc2ie,  unsigned int cc1ie, unsigned int uie)
{
	TIMx->DIER = ((tde<< CMSDK_TIM1_DIER_TDE_Pos) & CMSDK_TIM1_DIER_TDE_Msk)| 
                      ((comde<< CMSDK_TIM1_DIER_COMDE_Pos) & CMSDK_TIM1_DIER_COMDE_Msk)|
                      ((cc4de<< CMSDK_TIM1_DIER_CC4DE_Pos) & CMSDK_TIM1_DIER_CC4DE_Msk)|
                      ((cc3de<< CMSDK_TIM1_DIER_CC3DE_Pos) & CMSDK_TIM1_DIER_CC3DE_Msk)|
                      ((cc2de<< CMSDK_TIM1_DIER_CC2DE_Pos) & CMSDK_TIM1_DIER_CC2DE_Msk)|
                      ((cc1de<< CMSDK_TIM1_DIER_CC1DE_Pos) & CMSDK_TIM1_DIER_CC1DE_Msk)|
                      ((ude<< CMSDK_TIM1_DIER_UDE_Pos) & CMSDK_TIM1_DIER_UDE_Msk)|
                      ((bie<< CMSDK_TIM1_DIER_BIE_Pos) & CMSDK_TIM1_DIER_BIE_Msk)|
                      ((tie<< CMSDK_TIM1_DIER_TIE_Pos) & CMSDK_TIM1_DIER_TIE_Msk)|
                      ((comie<< CMSDK_TIM1_DIER_COMIE_Pos) & CMSDK_TIM1_DIER_COMIE_Msk)|
                      ((cc4ie << CMSDK_TIM1_DIER_CC4IE_Pos) & CMSDK_TIM1_DIER_CC4IE_Msk) |
                      ((cc3ie << CMSDK_TIM1_DIER_CC3IE_Pos) & CMSDK_TIM1_DIER_CC3IE_Msk) |
                      ((cc2ie << CMSDK_TIM1_DIER_CC2IE_Pos) & CMSDK_TIM1_DIER_CC2IE_Msk) |
                      ((cc1ie << CMSDK_TIM1_DIER_CC1IE_Pos) & CMSDK_TIM1_DIER_CC1IE_Msk) |
                       ((uie  << CMSDK_TIM1_DIER_UIE_Pos)  & CMSDK_TIM1_DIER_UIE_Msk);
	return;
}


/*
  tim1 channel configured to output ccnp must be 0.
*/
void TIMx_POLARITY_EN_SEL(TIM_TypeDef* TIMx,  unsigned int cc4p, unsigned int cc4e, unsigned int cc3np, unsigned int cc3ne, 
                           unsigned int cc3p, unsigned int cc3e, unsigned int cc2np, unsigned int cc2ne, 
                           unsigned int cc2p, unsigned int cc2e, unsigned int cc1np, unsigned int cc1ne, unsigned int cc1p, unsigned int cc1e)
{
	TIMx->CCER = ((cc4p  << CMSDK_TIM1_CCER_CC4P_Pos)  & CMSDK_TIM1_CCER_CC4P_Msk)|
                      ((cc4e  << CMSDK_TIM1_CCER_CC4E_Pos)  & CMSDK_TIM1_CCER_CC4E_Msk)|
                      ((cc2np  << CMSDK_TIM1_CCER_CC3NP_Pos) & CMSDK_TIM1_CCER_CC3NP_Msk) |
                      ((cc3p  << CMSDK_TIM1_CCER_CC3P_Pos)  & CMSDK_TIM1_CCER_CC3P_Msk)|
                      ((cc3ne << CMSDK_TIM1_CCER_CC3NE_Pos) & CMSDK_TIM1_CCER_CC3NE_Msk) |
                      ((cc3e  << CMSDK_TIM1_CCER_CC3E_Pos)  & CMSDK_TIM1_CCER_CC3E_Msk)|
                      ((cc2np << CMSDK_TIM1_CCER_CC2NP_Pos) & CMSDK_TIM1_CCER_CC2NP_Msk) |
                      ((cc2p  << CMSDK_TIM1_CCER_CC2P_Pos)  & CMSDK_TIM1_CCER_CC2P_Msk)|
                      ((cc2ne << CMSDK_TIM1_CCER_CC2NE_Pos) & CMSDK_TIM1_CCER_CC2NE_Msk) |
                      ((cc2e  << CMSDK_TIM1_CCER_CC2E_Pos)  & CMSDK_TIM1_CCER_CC2E_Msk)|
                      ((cc1np << CMSDK_TIM1_CCER_CC1NP_Pos) & CMSDK_TIM1_CCER_CC1NP_Msk) |
                      ((cc1p  << CMSDK_TIM1_CCER_CC1P_Pos)  & CMSDK_TIM1_CCER_CC1P_Msk)|
                      ((cc1ne << CMSDK_TIM1_CCER_CC1NE_Pos) & CMSDK_TIM1_CCER_CC1NE_Msk) |
                      ((cc1e  << CMSDK_TIM1_CCER_CC1E_Pos)  & CMSDK_TIM1_CCER_CC1E_Msk);
	return;
}

/*
  Event Generate
*/
void TIMx_EGR_GEN(TIM_TypeDef* TIMx,  unsigned int bg, unsigned int tg, unsigned int comg, unsigned int cc4g, 
                   unsigned int cc3g, unsigned int cc2g, unsigned int cc1g, unsigned int ug)
{
  TIMx->EGR = ((bg  << CMSDK_TIM1_EGR_BG_Pos)  & CMSDK_TIM1_EGR_BG_Msk)|
                    ((tg  << CMSDK_TIM1_EGR_TG_Pos)  & CMSDK_TIM1_EGR_TG_Msk)|
                    ((comg  << CMSDK_TIM1_EGR_COMG_Pos)  & CMSDK_TIM1_EGR_COMG_Msk)|
                    ((cc4g  << CMSDK_TIM1_EGR_CC4G_Pos)  & CMSDK_TIM1_EGR_CC4G_Msk)|
                    ((cc3g  << CMSDK_TIM1_EGR_CC3G_Pos)  & CMSDK_TIM1_EGR_CC3G_Msk)|
                    ((cc2g  << CMSDK_TIM1_EGR_CC2G_Pos)  & CMSDK_TIM1_EGR_CC2G_Msk)|
                    ((cc1g  << CMSDK_TIM1_EGR_CC1G_Pos)  & CMSDK_TIM1_EGR_CC1G_Msk)|
                    ((ug  << CMSDK_TIM1_EGR_UG_Pos)  & CMSDK_TIM1_EGR_UG_Msk);
}

/*
  SR clear
*/
void TIMx_SR_CLEAR(TIM_TypeDef* TIMx,  unsigned int cc4of, unsigned int cc3of, unsigned int cc2of, unsigned int cc1of, unsigned int bif,
     unsigned int tif, unsigned int comif, unsigned int cc4if, unsigned int cc3if, unsigned int cc2if, unsigned int cc1if, unsigned int uif)
{
  TIMx-> SR = ((cc4of << CMSDK_TIM1_SR_CC4OF_Pos) & CMSDK_TIM1_SR_CC4OF_Msk) |
                     ((cc3of << CMSDK_TIM1_SR_CC3OF_Pos) & CMSDK_TIM1_SR_CC3OF_Msk) |
                     ((cc2of << CMSDK_TIM1_SR_CC2OF_Pos) & CMSDK_TIM1_SR_CC2OF_Msk) |
                     ((cc1of << CMSDK_TIM1_SR_CC1OF_Pos) & CMSDK_TIM1_SR_CC1OF_Msk) |
                     ((bif   << CMSDK_TIM1_SR_BIF_Pos)   & CMSDK_TIM1_SR_BIF_Msk)   |
                     ((tif   << CMSDK_TIM1_SR_TIF_Pos)   & CMSDK_TIM1_SR_TIF_Msk)   |
                     ((comif << CMSDK_TIM1_SR_COMIF_Pos) & CMSDK_TIM1_SR_COMIF_Msk) |
                     ((cc4if << CMSDK_TIM1_SR_CC4IF_Pos) & CMSDK_TIM1_SR_CC4IF_Msk) |
                     ((cc3if << CMSDK_TIM1_SR_CC3IF_Pos) & CMSDK_TIM1_SR_CC3IF_Msk) |
                     ((cc2if << CMSDK_TIM1_SR_CC2IF_Pos) & CMSDK_TIM1_SR_CC2IF_Msk) |
                     ((cc1if << CMSDK_TIM1_SR_CC1IF_Pos) & CMSDK_TIM1_SR_CC1IF_Msk) |
                     ((uif   << CMSDK_TIM1_SR_UIF_Pos)   & CMSDK_TIM1_SR_UIF_Msk);
}

/*
  Counter value
*/
void TIMx_CNT_VAL(TIM_TypeDef* TIMx,  unsigned int cnt)
{
	TIMx->CNT = (cnt << CMSDK_TIM1_CNT_Pos) & CMSDK_TIM1_CNT_Msk; 
	return;
}

/*PSC[15:0]: Prescaler value
 The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).
 PSC contains the value to be loaded in the active prescaler register at each update event.
 (including when the counter is cleared through UG bit of TIMx_EGR register or through trigger 
 controller when configured in ?reset mode?).
*/
void TIMx_PSC_VAL(TIM_TypeDef* TIMx,  unsigned int psc)
{
	TIMx->PSC = (psc << CMSDK_TIM1_PSC_Pos) & CMSDK_TIM1_PSC_Msk; 
	return;
}

/*
  ARR is the value to be loaded in the actual auto-reload register.
*/
void TIMx_ARR_VAL(TIM_TypeDef* TIMx,  unsigned int arr)
{
	TIMx->ARR = (arr << CMSDK_TIM1_ARR_Pos) & CMSDK_TIM1_ARR_Msk; 
	return;
}

void TIMx_RCR_VAL(TIM_TypeDef* TIMx,  unsigned int rep)
{
	TIMx->RCR = (rep << CMSDK_TIM1_RCR_REP_Pos) & CMSDK_TIM1_RCR_REP_Msk; 
	return;
}
/*
  Enter the filter sampling frequency in capture mode, which contains the clock division factor (CKD) as well as the ICF bit.
*/
void TIMx_IN_CAP_MODE_SEL1(TIM_TypeDef* TIMx,  unsigned int ic2f, unsigned int ic2psc, unsigned int cc2s, unsigned int ic1f, unsigned int ic1psc, unsigned int cc1s)
{
	TIMx->CCMR1= ((ic2f   << CMSDK_TIM1_CCMR1_IC2F_Pos)   & CMSDK_TIM1_CCMR1_IC2F_Msk   )|
                      ((ic2psc << CMSDK_TIM1_CCMR1_IC2PSC_Pos) & CMSDK_TIM1_CCMR1_IC2PSC_Msk )|
                      ((cc2s   << CMSDK_TIM1_CCMR1_CC2S_Pos)   & CMSDK_TIM1_CCMR1_CC2S_Msk )|
                      ((ic1f   << CMSDK_TIM1_CCMR1_IC1F_Pos)   & CMSDK_TIM1_CCMR1_IC1F_Msk   )|
                      ((ic1psc << CMSDK_TIM1_CCMR1_IC1PSC_Pos) & CMSDK_TIM1_CCMR1_IC1PSC_Msk )|
                      ((cc1s   << CMSDK_TIM1_CCMR1_CC1S_Pos)   & CMSDK_TIM1_CCMR1_CC1S_Msk );
	return;
}

void TIMx_IN_CAP_MODE_SEL2(TIM_TypeDef* TIMx,  unsigned int ic4f, unsigned int ic4psc, unsigned int cc4s, unsigned int ic3f, unsigned int ic3psc, unsigned int cc3s)
{
	TIMx->CCMR2= ((ic4f   << CMSDK_TIM1_CCMR2_IC4F_Pos)   & CMSDK_TIM1_CCMR2_IC4F_Msk   )|
                      ((ic4psc << CMSDK_TIM1_CCMR2_IC4PSC_Pos) & CMSDK_TIM1_CCMR2_IC4PSC_Msk )|
                      ((cc4s   << CMSDK_TIM1_CCMR2_CC4S_Pos)   & CMSDK_TIM1_CCMR2_CC4S_Msk )|
                      ((ic3f   << CMSDK_TIM1_CCMR2_IC3F_Pos)   & CMSDK_TIM1_CCMR2_IC3F_Msk   )|
                      ((ic3psc << CMSDK_TIM1_CCMR2_IC3PSC_Pos) & CMSDK_TIM1_CCMR2_IC3PSC_Msk )|
                      ((cc3s   << CMSDK_TIM1_CCMR2_CC3S_Pos)   & CMSDK_TIM1_CCMR2_CC3S_Msk );
	return;
}


void TIMx_CC1_MOE_SEL(TIM_TypeDef* TIMx, unsigned int cc1s){
    TIMx->CCMR1 = (TIMx->CCMR1 & 0x3FFFC)
      | (cc1s & 0x3);
  }

void TIMx_CC2_MOE_SEL(TIM_TypeDef* TIMx, unsigned int cc2s){
    TIMx->CCMR1 = (TIMx->CCMR1 & 0x3FCFF)
      | ((cc2s & 0x3) << CMSDK_TIM1_CCMR1_CC2S_Pos);
  }

void TIMx_CC3_MOE_SEL(TIM_TypeDef* TIMx, unsigned int cc3s){
    TIMx->CCMR2 = (TIMx->CCMR2 & 0x3FFFC)
      | (cc3s & 0x3);
  }

void TIMx_CC4_MOE_SEL(TIM_TypeDef* TIMx, unsigned int cc4s){
    TIMx->CCMR2 = (TIMx->CCMR2 & 0x3FCFF)
      | ((cc4s & 0x3) << CMSDK_TIM1_CCMR2_CC4S_Pos);
  }

void TIMx_LOCK(TIM_TypeDef* TIMx, unsigned lock){
    TIMx->BDTR = (TIMx->BDTR & 0xFCFF)
      | ((lock & 0x3) << CMSDK_TIM1_BDTR_LOCK_Pos);

}

void TIMx_OUT_CMP_MODE_SEL1(TIM_TypeDef* TIMx, unsigned int oc2ce,  unsigned int oc2m,  unsigned int oc2pe, unsigned int oc2fe, unsigned int cc2s, unsigned int oc1ce,  unsigned int oc1m,  unsigned int oc1pe, unsigned int oc1fe, unsigned int cc1s)
{
	TIMx->CCMR1 = ((oc1ce << CMSDK_TIM1_CCMR1_OC2CE_Pos) & CMSDK_TIM1_CCMR1_OC2CE_Msk   ) |
                      (((oc2m << CMSDK_TIM1_CCMR1_OC2M_Pos) & CMSDK_TIM1_CCMR1_OC2M_Msk) | (((oc2m >> 3 ) << CMSDK_TIM1_CCMR1_OC2M3_Pos) ))|
                      ((oc2pe << CMSDK_TIM1_CCMR1_OC2PE_Pos)& CMSDK_TIM1_CCMR1_OC2PE_Msk)|
                      ((oc2fe << CMSDK_TIM1_CCMR1_OC2FE_Pos)& CMSDK_TIM1_CCMR1_OC2FE_Msk)|
                      ((cc2s  << CMSDK_TIM1_CCMR1_CC2S_Pos) & CMSDK_TIM1_CCMR1_CC2S_Msk   )|
                      ((oc1ce << CMSDK_TIM1_CCMR1_OC1CE_Pos) & CMSDK_TIM1_CCMR1_OC1CE_Msk   )|
                      (((oc1m << CMSDK_TIM1_CCMR1_OC1M_Pos )& CMSDK_TIM1_CCMR1_OC1M_Msk ) | ((oc1m >> 3) << CMSDK_TIM1_CCMR1_OC1M3_Pos ))|
                      ((oc1pe << CMSDK_TIM1_CCMR1_OC1PE_Pos)& CMSDK_TIM1_CCMR1_OC1PE_Msk)|
                      ((oc1fe << CMSDK_TIM1_CCMR1_OC1FE_Pos)& CMSDK_TIM1_CCMR1_OC1FE_Msk)|
                      ((cc1s  << CMSDK_TIM1_CCMR1_CC1S_Pos) & CMSDK_TIM1_CCMR1_CC1S_Msk   );
	return;
}
void TIMx_OUT_CMP_MODE_SEL2(TIM_TypeDef* TIMx, unsigned int oc4ce,  unsigned int oc4m,  unsigned int oc4pe, unsigned int oc4fe, unsigned int cc4s, unsigned int oc3ce,  unsigned int oc3m,  unsigned int oc3pe, unsigned int oc3fe, unsigned int cc3s)
{
	TIMx->CCMR2 = ((oc4ce << CMSDK_TIM1_CCMR2_OC4CE_Pos) & CMSDK_TIM1_CCMR2_OC4CE_Msk   ) |
                      (((oc4m << CMSDK_TIM1_CCMR2_OC4M_Pos) & CMSDK_TIM1_CCMR2_OC4M_Msk) | ((oc4m >> 3)<< CMSDK_TIM1_CCMR2_OC4M3_Pos))|
                      ((oc4pe << CMSDK_TIM1_CCMR2_OC4PE_Pos)& CMSDK_TIM1_CCMR2_OC4PE_Msk)|
                      ((oc4fe << CMSDK_TIM1_CCMR2_OC4FE_Pos)& CMSDK_TIM1_CCMR2_OC4FE_Msk)|
                      ((cc4s  << CMSDK_TIM1_CCMR2_CC4S_Pos) & CMSDK_TIM1_CCMR2_CC4S_Msk   )|
                      ((oc3ce << CMSDK_TIM1_CCMR2_OC3CE_Pos) & CMSDK_TIM1_CCMR2_OC3CE_Msk   )|
                      (((oc3m << CMSDK_TIM1_CCMR2_OC3M_Pos )& CMSDK_TIM1_CCMR2_OC3M_Msk ) | ((oc3m >> 3) << CMSDK_TIM1_CCMR2_OC3M3_Pos ) )|
                      ((oc3pe << CMSDK_TIM1_CCMR2_OC3PE_Pos)& CMSDK_TIM1_CCMR2_OC3PE_Msk)|
                      ((oc3fe << CMSDK_TIM1_CCMR2_OC3FE_Pos)& CMSDK_TIM1_CCMR2_OC3FE_Msk)|
                      ((cc3s  << CMSDK_TIM1_CCMR2_CC3S_Pos) & CMSDK_TIM1_CCMR2_CC3S_Msk   );
	return;
}
void TIMx_CCR1_VAL(TIM_TypeDef* TIMx,  unsigned int ccr1_asym, unsigned int ccr1)
{
  TIMx->CCR1 = ((ccr1<< CMSDK_TIM1_CCR1_Pos) & CMSDK_TIM1_CCR1_Msk)|
                     ((ccr1_asym<< CMSDK_TIM1_CCR1_ASYM_Pos) & CMSDK_TIM1_CCR1_ASYM_Msk);
}

void TIMx_CCR2_VAL(TIM_TypeDef* TIMx,  unsigned int ccr2_asym, unsigned int ccr2)
{
  TIMx->CCR2 = ((ccr2_asym<< CMSDK_TIM1_CCR2_ASYM_Pos) & CMSDK_TIM1_CCR2_ASYM_Msk)|
                     ((ccr2<< CMSDK_TIM1_CCR2_Pos) & CMSDK_TIM1_CCR2_Msk);
}

void TIMx_CCR3_VAL(TIM_TypeDef* TIMx,  unsigned int ccr3_asym, unsigned int ccr3)
{
  TIMx->CCR3 = ((ccr3_asym<< CMSDK_TIM1_CCR3_ASYM_Pos) & CMSDK_TIM1_CCR3_ASYM_Msk)|
                     ((ccr3<< CMSDK_TIM1_CCR3_Pos) & CMSDK_TIM1_CCR3_Msk);
}

void TIMx_CCR4_VAL(TIM_TypeDef* TIMx,  unsigned int ccr4_asym, unsigned int ccr4)
{
  TIMx->CCR4 = ((ccr4_asym<< CMSDK_TIM1_CCR4_ASYM_Pos) & CMSDK_TIM1_CCR4_ASYM_Msk)|
                     ((ccr4<< CMSDK_TIM1_CCR4_Pos) & CMSDK_TIM1_CCR4_Msk);
}

void TIMx_BRK_DT_CFG(TIM_TypeDef* TIMx,  unsigned int moe, unsigned int aoe, unsigned int bkp, unsigned int bke, unsigned int oosr, unsigned int ossi, unsigned int lock, unsigned int dtg)
{
  TIMx->BDTR = 
                      ((moe<< CMSDK_TIM1_BDTR_MOE_Pos)& CMSDK_TIM1_BDTR_MOE_Msk)|
                      ((aoe<< CMSDK_TIM1_BDTR_AOE_Pos)& CMSDK_TIM1_BDTR_AOE_Msk)|
                      ((bkp<< CMSDK_TIM1_BDTR_BKP_Pos) & CMSDK_TIM1_BDTR_BKP_Msk)|
                      ((bke<< CMSDK_TIM1_BDTR_BKE_Pos)& CMSDK_TIM1_BDTR_BKE_Msk)|
                      ((oosr<< CMSDK_TIM1_BDTR_OSSR_Pos)& CMSDK_TIM1_BDTR_OSSR_Msk)|
                      ((ossi<< CMSDK_TIM1_BDTR_OSSI_Pos)& CMSDK_TIM1_BDTR_OSSI_Msk)|
                      ((lock<< CMSDK_TIM1_BDTR_LOCK_Pos)& CMSDK_TIM1_BDTR_LOCK_Msk)|
                      ((dtg<< CMSDK_TIM1_BDTR_DTG_Pos)& CMSDK_TIM1_BDTR_DTG_Msk);
}

void TIMx_DMA_CTRL(TIM_TypeDef* TIMx,  unsigned int dbl, unsigned int dba)
{
  TIMx->DCR = ((dbl<< CMSDK_TIM1_DCR_DBL_Pos) & CMSDK_TIM1_DCR_DBL_Msk)|
                     ((dba<< CMSDK_TIM1_DCR_DBA_Pos) & CMSDK_TIM1_DCR_DBA_Msk);
}

void TIMx_DMA_ADDR(TIM_TypeDef* TIMx,  unsigned int dmab)
{
  TIMx->DMAR = ((dmab<< CMSDK_TIM1_DMAR_DMAB_Pos) & CMSDK_TIM1_DMAR_DMAB_Msk);
}

/*void TIM1_ALT_FUN( unsigned int bkcmp2p, unsigned int bkcmp1p, unsigned int bkinp, unsigned int bkcmp2e, unsigned int bkcmp1e, unsigned int bkine)
{
  TIMx->AF1 = ((bkcmp2p<< CMSDK_TIM1_AF1_BKCMP2P_Pos) & CMSDK_TIM1_AF1_BKCMP2P_Msk)|
                     ((bkcmp1p<< CMSDK_TIM1_AF1_BKCMP1P_Pos) & CMSDK_TIM1_AF1_BKCMP1P_Msk)|
                     ((bkinp<< CMSDK_TIM1_AF1_BKINP_Pos) & CMSDK_TIM1_AF1_BKINP_Msk)|
                     ((bkcmp2e<< CMSDK_TIM1_AF1_BKCMP2E_Pos) & CMSDK_TIM1_AF1_BKCMP2E_Msk)|
                     ((bkcmp1e<< CMSDK_TIM1_AF1_BKCMP1E_Pos) & CMSDK_TIM1_AF1_BKCMP1E_Msk)|
                     ((bkine<< CMSDK_TIM1_AF1_BKINE_Pos) & CMSDK_TIM1_AF1_BKINE_Msk);
}*/


void TIMx_UIF_CF(TIM_TypeDef* TIMx,  unsigned int uif)
{
  TIMx-> SR = (TIMx-> SR & 0x1FFE)
      | (uif & 0x1);
}


void TIMx_CC1IF_CF(TIM_TypeDef* TIMx,  unsigned int cc1if)
{
  TIMx-> SR = (TIMx-> SR & 0x1FFD)
      | ((cc1if & 0x1) << 1);
}


void TIMx_CC2IF_CF(TIM_TypeDef* TIMx,  unsigned int cc2if)
{
  TIMx-> SR = (TIMx-> SR & 0x1FFB)
      | ((cc2if & 0x1) << 2);
}


void TIMx_CC3IF_CF(TIM_TypeDef* TIMx,  unsigned int cc3if)
{
  TIMx-> SR = (TIMx-> SR & 0x1FF7)
      | ((cc3if & 0x1) << 3);
}


void TIMx_CC4IF_CF(TIM_TypeDef* TIMx,  unsigned int cc4if)
{
  TIMx-> SR = (TIMx-> SR & 0x1FEF)
      | ((cc4if & 0x1) << 4);
}


void TIMx_COMIF_CF(TIM_TypeDef* TIMx,  unsigned int comif)
{
  TIMx-> SR = (TIMx-> SR & 0x1FDF)
      | ((comif & 0x1) << 5);
}


void TIMx_TIF_CF(TIM_TypeDef* TIMx,  unsigned int tif)
{
  TIMx-> SR = (TIMx-> SR & 0x1FBF)
      | ((tif & 0x1) << 6);
}


void TIMx_BIF_CF(TIM_TypeDef* TIMx,  unsigned int bif)
{
  TIMx-> SR = (TIMx-> SR & 0x1F7F)
      | ((bif & 0x1) << 7);
}


void TIMx_CC1OF_CF(TIM_TypeDef* TIMx,  unsigned int cc1of)
{
  TIMx-> SR = (TIMx-> SR & 0x1DFF)
      | ((cc1of & 0x1) << 9);
}


void TIMx_CC2OF_CF(TIM_TypeDef* TIMx,  unsigned int cc2of)
{
  TIMx-> SR = (TIMx-> SR & 0x1BFF)
      | ((cc2of & 0x1) << 10);
}


void TIMx_CC3OF_CF(TIM_TypeDef* TIMx,  unsigned int cc3of)
{
  TIMx-> SR = (TIMx-> SR & 0x17FF)
      | ((cc3of & 0x1) << 11);
}


void TIMx_CC4OF_CF(TIM_TypeDef* TIMx,  unsigned int cc4of)
{
  TIMx-> SR = (TIMx-> SR & 0x0FFF)
      | ((cc4of & 0x1) << 12);
}

void TIMx_UG_EG(TIM_TypeDef* TIMx,  unsigned int ug)
{
    TIMx-> EGR = (TIMx-> EGR & 0xFE) | (ug & 0x1);
}

void TIMx_CC1G_EG(TIM_TypeDef* TIMx,  unsigned int cc1g)
{
    TIMx-> EGR = (TIMx-> EGR & 0xFD) | ((cc1g & 0x1) << 1);
}

void TIMx_CC2G_EG(TIM_TypeDef* TIMx,  unsigned int cc2g)
{
    TIMx-> EGR = (TIMx-> EGR & 0xFB) | ((cc2g & 0x1) << 2);
}

void TIMx_CC3G_EG(TIM_TypeDef* TIMx,  unsigned int cc3g)
{
    TIMx-> EGR = (TIMx-> EGR & 0xF7) | ((cc3g & 0x1) << 3);
}

void TIMx_CC4G_EG(TIM_TypeDef* TIMx,  unsigned int cc4g)
{
    TIMx-> EGR = (TIMx-> EGR & 0xEF) | ((cc4g & 0x1) << 4);
}

void TIMx_COMG_EG(TIM_TypeDef* TIMx,  unsigned int comg)
{
    TIMx-> EGR = (TIMx-> EGR & 0xDF) | ((comg & 0x1) << 5);
}

void TIMx_TG_EG(TIM_TypeDef* TIMx,  unsigned int tg)
{
    TIMx-> EGR = (TIMx-> EGR & 0xBF) | ((tg & 0x1) << 6);
}

void TIMx_BG_EG(TIM_TypeDef* TIMx,  unsigned int bg)
{
    TIMx-> EGR = (TIMx-> EGR & 0x7F) | ((bg & 0x1) << 7);
}

void TIMx_CEN(TIM_TypeDef* TIMx,  unsigned int cen)
{
    TIMx-> CR1 = (TIMx-> CR1 & 0x3FE) | (cen & 0x1);
}


void TIMx_CC1E(TIM_TypeDef* TIMx, unsigned int cc1e)
{
    TIMx->CCER = (TIMx->CCER & 0x3FFE) | (cc1e & 0x1);
}

void TIMx_CC1P(TIM_TypeDef* TIMx, unsigned int cc1p)
{
    TIMx->CCER = (TIMx->CCER & 0x3FFD) | ((cc1p & 0x1) << 1);
}

void TIMx_CC1NE(TIM_TypeDef* TIMx, unsigned int cc1ne)
{
    TIMx->CCER = (TIMx->CCER & 0x3FFB) | ((cc1ne & 0x1) << 2);
}

void TIMx_CC1NP(TIM_TypeDef* TIMx, unsigned int cc1np)
{
    TIMx->CCER = (TIMx->CCER & 0x3FF7) | ((cc1np & 0x1) << 3);
}

void TIMx_CC2E(TIM_TypeDef* TIMx, unsigned int cc2e)
{
    TIMx->CCER = (TIMx->CCER & 0x3FEF) | ((cc2e & 0x1) << 4);
}

void TIMx_CC2P(TIM_TypeDef* TIMx, unsigned int cc2p)
{
    TIMx->CCER = (TIMx->CCER & 0x3FDF) | ((cc2p & 0x1) << 5);
}

void TIMx_CC2NE(TIM_TypeDef* TIMx, unsigned int cc2ne)
{
    TIMx->CCER = (TIMx->CCER & 0x3FBF) | ((cc2ne & 0x1) << 6);
}

void TIMx_CC2NP(TIM_TypeDef* TIMx, unsigned int cc2np)
{
    TIMx->CCER = (TIMx->CCER & 0x3F7F) | ((cc2np & 0x1) << 7);
}

void TIMx_CC3E(TIM_TypeDef* TIMx, unsigned int cc3e)
{
    TIMx->CCER = (TIMx->CCER & 0x3EFF) | ((cc3e & 0x1) << 8);
}

void TIMx_CC3P(TIM_TypeDef* TIMx, unsigned int cc3p)
{
    TIMx->CCER = (TIMx->CCER & 0x3DFF) | ((cc3p & 0x1) << 9);
}

void TIMx_CC3NE(TIM_TypeDef* TIMx, unsigned int cc3ne)
{
    TIMx->CCER = (TIMx->CCER & 0x3BFF) | ((cc3ne & 0x1) << 10);
}

void TIMx_CC3NP(TIM_TypeDef* TIMx, unsigned int cc3np)
{
    TIMx->CCER = (TIMx->CCER & 0x37FF) | ((cc3np & 0x1) << 11);
}

void TIMx_CC4E(TIM_TypeDef* TIMx, unsigned int cc4e)
{
    TIMx->CCER = (TIMx->CCER & 0x2FFF) | ((cc4e & 0x1) << 12);
}

void TIMx_CC4P(TIM_TypeDef* TIMx, unsigned int cc4p)
{
    TIMx->CCER = (TIMx->CCER & 0x1FFF) | ((cc4p & 0x1) << 13);
}

void TIMx_CCPC_EN_CFG(TIM_TypeDef* TIMx, unsigned int ccpc)
{
    TIMx->CR2 = (TIMx->CR2 & 0xFFFE) | (ccpc & 0x1);
}

