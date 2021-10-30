/*
 * Code generated for Simulink model untitled.
 *
 * FILE    : adc.h
 *
 * VERSION : 1.0
 *
 * DATE    : Fri Jul 23 01:50:15 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_adc_h_
#define RTW_HEADER_adc_h_
#include "MPC5554.h"
#include "Std_Types.h"
#define SystemCLK_8                    0b00011
#define SystemCLK_10                   0b00100
#define SystemCLK_16                   0b00111
#define SystemCLK_20                   0b01001
#define SystemCLK_30                   0b01110
#define SystemCLK_32                   0b01111
#define SystemCLK_40                   0b10011
#define LST2                           0b00
#define LST8                           0b01
#define LST64                          0b10
#define LST128                         0b11
#define SWT_SS                         0b0001
#define SWT_CS                         0b1001
#define SS_ENABLE                      0b1
#define SS_DISABLE                     0b0

float32 ADC0_GCC_f = 0;
float32 ADC0_OCC_f = 0;
typedef union
{
  uint16 R;
  struct {
    uint16 ADC_EN:1;
    uint16 reserved1:3;
    uint16 ADC_EMUX:1;
    uint16 reserved2:6;
    uint16 ADC_CLK_PS:5;
  } B;
} ADC_CR;

typedef union
{
  uint16 R;
  struct {
    uint16 reserved1:1;
    uint16 GCCn:15;
  } B;
} ADC_GCCR;

typedef union
{
  uint16 R;
  struct {
    uint16 reserved1:2;
    uint16 OCCn:14;
  } B;
} ADC_OCCR;

typedef union
{
  uint32 Word;
  struct {
    uint32 EOQ:1;
    uint32 PAUSE:1;
    uint32 reserved1:3;
    uint32 EB:1;                       /* EB=0, on-chip ADC */
    uint32 BN:1;                       /* BN =0, ADC0; BN=1, ADC1 */
    uint32 CAL:1;                      /* CAL=0, no calibration; CAL=1, calibration */
    uint32 MSG_TAG:4;                  /* MSG_TAG=0b0000, result is sent to RFIFO0
                                          MSG_TAG=0b0001, result is sent to RFIFO1
                                          MSG_TAG=0b0010, result is sent to RFIFO2
                                          MSG_TAG=0b0011, result is sent to RFIFO3
                                          MSG_TAG=0b0100, result is sent to RFIFO4
                                          MSG_TAG=0b0101, result is sent to RFIFO5 */
    uint32 LST:2;                      /* Long sample time,LST=0b00, Sampling cycle=2 ADC CLK
                                          LST=0b01, Sampling cycle=8 ADC CLK
                                          LST=0b10, Sampling cycle=64 ADC CLK
                                          LST=0b11, Sampling cycle=128 ADC CLK */
    uint32 TSR:1;                      /* TSR=0, return conversion result only;
                                          TSR=1, return conversion time stamp after the conversion result */
    uint32 FMT:1;                      /* FMT=0, right justified unsigned; FMT=1, right justified signed */
    uint32 CHANNEL_NO:8;               /* 0~39 */
    uint32 reserved2:8;
  } B;
} ADC_CC;

typedef union
{
  uint32 Word;
  struct {
    uint32 EOQ:1;
    uint32 PAUSE:1;
    uint32 reserved1:3;
    uint32 EB:1;                       /* EB=0, on-chip ADC */
    uint32 BN:1;                       /* BN =0, ADC0; BN=1, ADC1 */
    uint32 RW:1;                       /* RW=0, write; RW=1, read */
    uint32 ADC_REG_HByte:8;            /* ADC register high byte */
    uint32 ADC_REG_LByte:8;            /* ADC register low byte */
    uint32 ADC_REG_ADDRESS:8;          /* ADC register address */
  } B;
} ADC_WC;

extern void ec_adc_init(void);
extern uint32 ec_adc_readresult(uint8 Chn);

#endif                                 /* RTW_HEADER_adc_h_ */

/* File trailer for ECUCoder generated file adc.h.
 *
 * [EOF]
 */
