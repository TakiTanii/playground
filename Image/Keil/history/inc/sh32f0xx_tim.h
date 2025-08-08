#ifndef __SH32F0XX_TIM_H
#define __SH32F0XX_TIM_H
#include "CMSDK_CM0.h"
#include "sh32f0xx.h"

 void TIMx_CR1(TIM_TypeDef* TIMx,  /*unsigned int uif_cpy,*/  unsigned int ckd, unsigned int arpe,unsigned int cms, unsigned int dir, unsigned int opm, unsigned int urs, unsigned int udis, unsigned int cen);
 void TIMx_CR2(TIM_TypeDef* TIMx, unsigned int ois4,  unsigned int ois3n, unsigned int ois3,  unsigned int ois2n, unsigned int ois2,  unsigned int ois1n, unsigned int ois1, unsigned int ti1s,  unsigned int mms, unsigned int ccds, unsigned int ccus, unsigned int ccpc);
 void TIMx_SLV_MODE_CTRL(TIM_TypeDef* TIMx, unsigned int etp,  unsigned int ece,  unsigned int etps, unsigned int etf,  unsigned int msm, unsigned int ts, unsigned int sms);
// void TIM1_IN_CLK_SEL( unsigned int clk_sel);
 void TIMx_DMA_INT_EN( TIM_TypeDef* TIMx, unsigned int tde, unsigned int comde,  unsigned int cc4de,  unsigned int cc3de,  unsigned int cc2de,  unsigned int cc1de, unsigned int ude, unsigned int bie, unsigned int tie, unsigned int comie, unsigned int cc4ie, unsigned int cc3ie, unsigned int cc2ie,  unsigned int cc1ie, unsigned int uie );
 void TIMx_POLARITY_EN_SEL(TIM_TypeDef* TIMx, unsigned int cc4p, unsigned int cc4e, unsigned int cc3np, unsigned int cc3ne, unsigned int cc3p, unsigned int cc3e, unsigned int cc2np, unsigned int cc2ne, unsigned int cc2p, unsigned int cc2e,  unsigned int cc1np, unsigned int cc1ne, unsigned int cc1p, unsigned int cc1e);
 void TIMx_CNT_VAL( TIM_TypeDef* TIMx, unsigned int cnt);
 void TIMx_PSC_VAL( TIM_TypeDef* TIMx, unsigned int psc);
 void TIMx_ARR_VAL( TIM_TypeDef* TIMx, unsigned int arr);
 void TIMx_RCR_VAL( TIM_TypeDef* TIMx, unsigned int rep);
 void TIMx_IN_CAP_MODE_SEL1( TIM_TypeDef* TIMx, unsigned int ic2f, unsigned int ic2psc, unsigned int cc2s,  unsigned int ic1f, unsigned int ic1psc, unsigned int cc1s);
 void TIMx_IN_CAP_MODE_SEL2( TIM_TypeDef* TIMx, unsigned int ic4f, unsigned int ic4psc, unsigned int cc4s, unsigned int ic3f, unsigned int ic3psc, unsigned int cc3s);
 void TIMx_OUT_CMP_MODE_SEL1(TIM_TypeDef* TIMx, unsigned int oc2ce,  unsigned int oc2m,  unsigned int oc2pe, unsigned int oc2fe, unsigned int cc2s, unsigned int oc1ce,  unsigned int oc1m,  unsigned int oc1pe, unsigned int oc1fe, unsigned int cc1s);
 void TIMx_OUT_CMP_MODE_SEL2(TIM_TypeDef* TIMx, unsigned int oc4ce,  unsigned int oc4m,  unsigned int oc4pe, unsigned int oc4fe, unsigned int cc4s, unsigned int oc3ce,  unsigned int oc3m,  unsigned int oc3pe, unsigned int oc3fe, unsigned int cc3s);
 void TIMx_CCR1_VAL(TIM_TypeDef* TIMx,  unsigned int ccr1_asym,  unsigned int ccr1);
 void TIMx_CCR2_VAL(TIM_TypeDef* TIMx,  unsigned int ccr2_asym,  unsigned int ccr2);
 void TIMx_CCR3_VAL(TIM_TypeDef* TIMx,  unsigned int ccr3_asym,  unsigned int ccr3);
 void TIMx_CCR4_VAL(TIM_TypeDef* TIMx,  unsigned int ccr4_asym,  unsigned int ccr4);
 void TIMx_DMA_CTRL(TIM_TypeDef* TIMx,  unsigned int dbl, unsigned int dba);
 void TIMx_DMA_ADDR(TIM_TypeDef* TIMx,  unsigned int dmab);
// void TIM1_ALT_FUN( unsigned int bkcmp2p, unsigned int bkcmp1p, unsigned int bkinp, unsigned int bkcmp2e, unsigned int bkcmp1e, unsigned int bkine);
 void TIMx_BRK_DT_CFG(TIM_TypeDef* TIMx, unsigned int moe, unsigned int aoe, unsigned int bkp, unsigned int bke, unsigned int oosr, unsigned int ossi, unsigned int lock, unsigned int dtg);
 void TIMx_EGR_GEN(TIM_TypeDef* TIMx,  unsigned int bg, unsigned int tg, unsigned int comg, unsigned int cc4g, 
                                                 unsigned int cc3g, unsigned int cc2g, unsigned int cc1g, unsigned int ug);
 void TIMx_SR_CLEAR(TIM_TypeDef* TIMx,  unsigned int cc4of, unsigned int cc3of, unsigned int cc2of, unsigned int cc1of, unsigned int bif,
     unsigned int tif, unsigned int comif, unsigned int cc4if, unsigned int cc3if, unsigned int cc2if, unsigned int cc1if, unsigned int uif);

 void TIMx_CC1_MOE_SEL(TIM_TypeDef* TIMx, unsigned int cc1s);
 void TIMx_CC2_MOE_SEL(TIM_TypeDef* TIMx, unsigned int cc2s);
 void TIMx_CC3_MOE_SEL(TIM_TypeDef* TIMx, unsigned int cc3s);
 void TIMx_CC4_MOE_SEL(TIM_TypeDef* TIMx, unsigned int cc4s);
 void TIMx_LOCK(TIM_TypeDef* TIMx, unsigned lock);
 void TIMx_UIF_CF( TIM_TypeDef* TIMx, unsigned int uif);
 void TIMx_CC1IF_CF( TIM_TypeDef* TIMx, unsigned int cc1if);
 void TIMx_CC2IF_CF( TIM_TypeDef* TIMx, unsigned int cc2if);
 void TIMx_CC3IF_CF( TIM_TypeDef* TIMx, unsigned int cc3if);
 void TIMx_CC4IF_CF( TIM_TypeDef* TIMx, unsigned int cc4if);
 void TIMx_COMIF_CF( TIM_TypeDef* TIMx, unsigned int comif);
 void TIMx_TIF_CF( TIM_TypeDef* TIMx, unsigned int tif);
 void TIMx_BIF_CF( TIM_TypeDef* TIMx, unsigned int bif);
 void TIMx_CC1OF_CF( TIM_TypeDef* TIMx, unsigned int cc1of);
 void TIMx_CC2OF_CF( TIM_TypeDef* TIMx, unsigned int cc2of);
 void TIMx_CC3OF_CF( TIM_TypeDef* TIMx, unsigned int cc3of);
 void TIMx_CC4OF_CF( TIM_TypeDef* TIMx, unsigned int cc4of);
 void TIMx_UG_EG( TIM_TypeDef* TIMx, unsigned int ug);
 void TIMx_CC1G_EG( TIM_TypeDef* TIMx, unsigned int cc1g);
 void TIMx_CC2G_EG( TIM_TypeDef* TIMx, unsigned int cc2g);
 void TIMx_CC3G_EG( TIM_TypeDef* TIMx, unsigned int cc3g);
 void TIMx_CC4G_EG( TIM_TypeDef* TIMx, unsigned int cc4g);
 void TIMx_COMG_EG( TIM_TypeDef* TIMx, unsigned int comg);
 void TIMx_TG_EG( TIM_TypeDef* TIMx, unsigned int tg);
 void TIMx_BG_EG( TIM_TypeDef* TIMx, unsigned int bg);
 void TIMx_CEN( TIM_TypeDef* TIMx, unsigned int cen);
 void TIMx_CC1E(TIM_TypeDef* TIMx, unsigned int cc1e);
 void TIMx_CC1P(TIM_TypeDef* TIMx, unsigned int cc1p);
 void TIMx_CC1NE(TIM_TypeDef* TIMx, unsigned int cc1ne);
 void TIMx_CC1NP(TIM_TypeDef* TIMx, unsigned int cc1np);
 void TIMx_CC2E(TIM_TypeDef* TIMx, unsigned int cc2e);
 void TIMx_CC2P(TIM_TypeDef* TIMx, unsigned int cc2p);
 void TIMx_CC2NE(TIM_TypeDef* TIMx, unsigned int cc2ne);
 void TIMx_CC2NP(TIM_TypeDef* TIMx, unsigned int cc2np);
 void TIMx_CC3E(TIM_TypeDef* TIMx, unsigned int cc3e);
 void TIMx_CC3P(TIM_TypeDef* TIMx, unsigned int cc3p);
 void TIMx_CC3NE(TIM_TypeDef* TIMx, unsigned int cc3ne);
 void TIMx_CC3NP(TIM_TypeDef* TIMx, unsigned int cc3np);
 void TIMx_CC4E(TIM_TypeDef* TIMx, unsigned int cc4e);
 void TIMx_CC4P(TIM_TypeDef* TIMx, unsigned int cc4p);
 void TIMx_CCPC_EN_CFG(TIM_TypeDef* TIMx, unsigned int ccpc);
#endif

