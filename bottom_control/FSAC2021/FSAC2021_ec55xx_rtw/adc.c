/*
 * Code generated for Simulink model FSAC2021.
 *
 * FILE    : adc.c
 *
 * VERSION : 1.157
 *
 * DATE    : Wed Sep 01 03:10:55 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "adc.h"
#if 1

/**************************************************************************
 * FUNCTION :    ec_adc_init                                               *
 *                                                                         *
 * DESCRIPTION : Initialize the on-chip ADC moudule                        *
 *                                                                         *
 * PARAMETERS :  None                                                      *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_adc_init(void)
{
  uint8 i;
  uint32 RES_25 = 0;
  uint32 RES_75 = 0;
  uint32 ADC0_GCC = 0;
  uint32 ADC0_OCC = 0;

  //float32 ADC0_GCC_f = 0;
  //float32 ADC0_OCC_f = 0;
  ADC_CC ADC0_CC;
  ADC_WC ADC0_WC;                      /* Define one ADC write command */
  ADC_CR ADC0_CR;
  ADC0_WC.Word = 0;                    /* Clear the ADC command before give it value */
  ADC0_CR.B.ADC_EN = 1;                /* Enable ADC module */
  ADC0_CR.B.ADC_CLK_PS = SystemCLK_16; /* ADC clock = system clock/16 */
  ADC0_CR.B.ADC_EMUX = 0;              /* External multiplexer disabled */
  ADC0_WC.B.EOQ = 1;                   /* Make the command with the flag of EOQ */
  ADC0_WC.B.PAUSE = 0;                 /* The command do not have pause flag */
  ADC0_WC.B.EB = 0;                    /* The ADC command is sent to on-chip ADC */
  ADC0_WC.B.BN = 0;                    /* The command is sent to ADC0 */
  ADC0_WC.B.RW = 0;                    /* Write on-chip ADC */
  ADC0_WC.B.ADC_REG_HByte = (uint32)((ADC0_CR.R & 0xff00)>>8);
  ADC0_WC.B.ADC_REG_LByte = (uint32)((ADC0_CR.R & 0x00ff));
  ADC0_WC.B.ADC_REG_ADDRESS = 1;
  for (i=0; i<6; i++)                  /* Disable all RFDE interrupts */
  {
    EQADC.IDCR[i].B.RFDE = 0;
    EQADC.IDCR[i].B.RFDS = 0;
  }

  EQADC.CFPR[0].R = ADC0_WC.Word;      /* Push ADC write command to CFIFO0 */
  EQADC.CFCR[0].B.MODE = SWT_SS;       /* Software trigger, single scan CFIFOn */
  EQADC.CFCR[0].B.SSE = SS_ENABLE;     /* CFIFOn single-scan enable */
  while (EQADC.FISR[0].B.EOQF != 1) {
  }                                    /* Wait for end of queue flag */

  EQADC.FISR[0].B.EOQF = 1;            /* Clear end of queue flag */
  ADC0_CC.Word = 0;
  ADC0_CC.B.EOQ = 1;
  ADC0_CC.B.PAUSE = 0;
  ADC0_CC.B.EB = 0;
  ADC0_CC.B.BN = 0;
  ADC0_CC.B.CAL = 0;
  ADC0_CC.B.MSG_TAG = 0b0000;
  ADC0_CC.B.LST = LST8;
  ADC0_CC.B.TSR = 0;
  ADC0_CC.B.FMT = 0;
  ADC0_CC.B.CHANNEL_NO = 44;
  EQADC.CFPR[0].R = ADC0_CC.Word;
  EQADC.CFCR[0].B.SSE = SS_ENABLE;
  EQADC.CFCR[0].B.MODE = SWT_SS;
  while (EQADC.FISR[0].B.RFDF != 1) {
  }

  RES_25 = EQADC.RFPR[0].B.RFPOP;
  EQADC.FISR[0].B.RFDF = 1;
  EQADC.FISR[0].B.EOQF = 1;
  ADC0_CC.Word = 0;
  ADC0_CC.B.EOQ = 1;
  ADC0_CC.B.PAUSE = 0;
  ADC0_CC.B.EB = 0;
  ADC0_CC.B.BN = 0;
  ADC0_CC.B.CAL = 0;
  ADC0_CC.B.MSG_TAG = 0b0000;
  ADC0_CC.B.LST = LST8;
  ADC0_CC.B.TSR = 0;
  ADC0_CC.B.FMT = 0;
  ADC0_CC.B.CHANNEL_NO = 43;
  EQADC.CFPR[0].R = ADC0_CC.Word;
  EQADC.CFCR[0].B.SSE = SS_ENABLE;
  EQADC.CFCR[0].B.MODE = SWT_SS;
  while (EQADC.FISR[0].B.RFDF != 1) {
  }

  RES_75 = EQADC.RFPR[0].B.RFPOP;
  EQADC.FISR[0].B.RFDF = 1;
  EQADC.FISR[0].B.EOQF = 1;
  ADC0_GCC_f = (float)(12288-4096)/(RES_75 - RES_25);
  ADC0_OCC_f = 12288-ADC0_GCC_f*RES_75-2;

  //ADC0_GCC_f = 16384*ADC0_GCC_f;
  ADC0_GCC = (uint32)ADC0_GCC_f;
  ADC0_GCC = (uint32)ADC0_OCC_f;
}

/**************************************************************************
 * FUNCTION :    ec_adc_readresult                                         *
 *                                                                         *
 * DESCRIPTION : Start one ADC channel's conversion and get it's           *
 *               conversion result                                         *
 *                                                                         *
 * PARAMETERS :  -Chn: ADC0 channel, range from 0 to 39                    *
 *                                                                         *
 * RETURN :      -resultinmv: the ADC conversion result                    *
 ***************************************************************************/
uint32 ec_adc_readresult(uint8 Chn)
{
  float32 result = 0;
  uint32 resultinmv = 0;
  ADC_CC ADC0_CC;
  ADC0_CC.Word = 0;
  ADC0_CC.B.EOQ = 1;
  ADC0_CC.B.PAUSE = 0;
  ADC0_CC.B.EB = 0;
  ADC0_CC.B.BN = 0;
  ADC0_CC.B.CAL = 0;
  ADC0_CC.B.MSG_TAG = 0b0000;
  ADC0_CC.B.LST = LST8;
  ADC0_CC.B.TSR = 0;
  ADC0_CC.B.FMT = 0;
  ADC0_CC.B.CHANNEL_NO = Chn;
  EQADC.CFPR[0].R = ADC0_CC.Word;
  EQADC.CFCR[0].B.SSE = SS_ENABLE;
  EQADC.CFCR[0].B.MODE = SWT_SS;
  while (EQADC.FISR[0].B.RFDF != 1) {
  }

  result = EQADC.RFPR[0].B.RFPOP;
  result = result*ADC0_GCC_f+ADC0_OCC_f+2;
  resultinmv = 5000*result/0x3FFC;
  EQADC.FISR[0].B.RFDF = 1;
  EQADC.FISR[0].B.EOQF = 1;
  return resultinmv;
}

#endif

/* File trailer for ECUCoder generated file adc.c.
 *
 * [EOF]
 */
