/*
 * Code generated for Simulink model FSAC2021_V1_Running.
 *
 * FILE    : pwm.h
 *
 * VERSION : 1.179
 *
 * DATE    : Sun Sep 26 20:42:00 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_pwm_h_
#define RTW_HEADER_pwm_h_
#include "MPC5554.h"
#include "Std_Types.h"

extern void ec_pwm_init(uint8 Chn);
extern void ec_pwm_output(uint8 Chn, uint32 Period, uint32 DutyCycle);

#endif                                 /* RTW_HEADER_pwm_h_ */

/* File trailer for ECUCoder generated file pwm.h.
 *
 * [EOF]
 */
