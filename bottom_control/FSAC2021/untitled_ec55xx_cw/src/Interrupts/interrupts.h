/*
 * Code generated for the formwork and Simulink model.
 *
 * FILE    : interrupts.h
 *
 * VERSION : 1.000
 *
 * DATE    : Fri Feb 10 12:50:20 2012
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_


#include "MPC5554.h"        /* Used for MPC555x devices */
#include "rti.h"
#include "can.h"
#include "spi.h"
#include "sci.h"

#define  RTI_INTC_PRIORITY                 9      /* Define RTI Interrupt properity */
#define  ICU_INTC_PRIORITY                 10     /* Define the ICU interrupt priority */
#define  CAN0_INTC_PRIORITY                13	  /* CAN A INTC Priority Select:0-15(LOW-HIGH) */
#define  CAN1_INTC_PRIORITY			       11     /* CAN B INTC Priority Select:0-15(LOW-HIGH) */
#define  CAN2_INTC_PRIORITY			       12	  /* CAN C INTC Priority Select:0-15(LOW-HIGH) */
#define  SCI_INTC_PRIORITY			       8	  /* SCI INTC Priority Select:0-15(LOW-HIGH) */
#define  ETPU_INTC_Highest_PRIORITY		   15	  /* ETPU INTC Highest Priority:15 */
#define  ETPU_INTC_Lower_PRIORITY		   14	  /* ETPU INTC Lower Priority:14 */

#define SW_INT_VEC_CAN0_ESR_BOFF_INT       152
#define SW_INT_VEC_CAN0_ESR_ERR_INT        153
#define SW_INT_VEC_CAN0_IFRL_BUF0          155
#define SW_INT_VEC_CAN0_IFRL_BUF1          156
#define SW_INT_VEC_CAN0_IFRL_BUF2          157
#define SW_INT_VEC_CAN0_IFRL_BUF3          158
#define SW_INT_VEC_CAN0_IFRL_BUF4          159
#define SW_INT_VEC_CAN0_IFRL_BUF5          160
#define SW_INT_VEC_CAN0_IFRL_BUF6          161
#define SW_INT_VEC_CAN0_IFRL_BUF7          162
#define SW_INT_VEC_CAN0_IFRL_BUF8          163
#define SW_INT_VEC_CAN0_IFRL_BUF9          164
#define SW_INT_VEC_CAN0_IFRL_BUF10         165
#define SW_INT_VEC_CAN0_IFRL_BUF11         166
#define SW_INT_VEC_CAN0_IFRL_BUF12         167
#define SW_INT_VEC_CAN0_IFRL_BUF13         168
#define SW_INT_VEC_CAN0_IFRL_BUF14         169
#define SW_INT_VEC_CAN0_IFRL_BUF15         170
#define SW_INT_VEC_CAN0_IFRL_BUF16TO31     171
#define SW_INT_VEC_CAN0_IFRL_BUF32TO63     172

#define SW_INT_VEC_CAN1_ESR_BOFF_INT       280
#define SW_INT_VEC_CAN1_ESR_ERR_INT        281
#define SW_INT_VEC_CAN1_IFRL_BUF0          283
#define SW_INT_VEC_CAN1_IFRL_BUF1          284
#define SW_INT_VEC_CAN1_IFRL_BUF2          285
#define SW_INT_VEC_CAN1_IFRL_BUF3          286
#define SW_INT_VEC_CAN1_IFRL_BUF4          287
#define SW_INT_VEC_CAN1_IFRL_BUF5          288
#define SW_INT_VEC_CAN1_IFRL_BUF6          289
#define SW_INT_VEC_CAN1_IFRL_BUF7          290
#define SW_INT_VEC_CAN1_IFRL_BUF8          291
#define SW_INT_VEC_CAN1_IFRL_BUF9          292
#define SW_INT_VEC_CAN1_IFRL_BUF10         293
#define SW_INT_VEC_CAN1_IFRL_BUF11         294
#define SW_INT_VEC_CAN1_IFRL_BUF12         295
#define SW_INT_VEC_CAN1_IFRL_BUF13         296
#define SW_INT_VEC_CAN1_IFRL_BUF14         297
#define SW_INT_VEC_CAN1_IFRL_BUF15         298
#define SW_INT_VEC_CAN1_IFRL_BUF16TO31     299
#define SW_INT_VEC_CAN1_IFRL_BUF32TO63     300

#define SW_INT_VEC_CAN2_ESR_BOFF_INT       173
#define SW_INT_VEC_CAN2_ESR_ERR_INT        174
#define SW_INT_VEC_CAN2_IFRL_BUF0          176
#define SW_INT_VEC_CAN2_IFRL_BUF1          177
#define SW_INT_VEC_CAN2_IFRL_BUF2          178
#define SW_INT_VEC_CAN2_IFRL_BUF3          179
#define SW_INT_VEC_CAN2_IFRL_BUF4          180
#define SW_INT_VEC_CAN2_IFRL_BUF5          181
#define SW_INT_VEC_CAN2_IFRL_BUF6          182
#define SW_INT_VEC_CAN2_IFRL_BUF7          183
#define SW_INT_VEC_CAN2_IFRL_BUF8          184
#define SW_INT_VEC_CAN2_IFRL_BUF9          185
#define SW_INT_VEC_CAN2_IFRL_BUF10         186
#define SW_INT_VEC_CAN2_IFRL_BUF11         187
#define SW_INT_VEC_CAN2_IFRL_BUF12         188
#define SW_INT_VEC_CAN2_IFRL_BUF13         189
#define SW_INT_VEC_CAN2_IFRL_BUF14         190
#define SW_INT_VEC_CAN2_IFRL_BUF15         191
#define SW_INT_VEC_CAN2_IFRL_BUF16TO31     192
#define SW_INT_VEC_CAN2_IFRL_BUF32TO63     193

#define SOFT_INT_VEC_EMIOS_GFR_F0          51
#define SOFT_INT_VEC_EMIOS_GFR_F1          52
#define SOFT_INT_VEC_EMIOS_GFR_F2          53
#define SOFT_INT_VEC_EMIOS_GFR_F3          54
#define SOFT_INT_VEC_EMIOS_GFR_F4          55
#define SOFT_INT_VEC_EMIOS_GFR_F5          56
#define SOFT_INT_VEC_EMIOS_GFR_F6          57
#define SOFT_INT_VEC_EMIOS_GFR_F7          58
#define SOFT_INT_VEC_EMIOS_GFR_F8          59
#define SOFT_INT_VEC_EMIOS_GFR_F9          60
#define SOFT_INT_VEC_EMIOS_GFR_F10         61
#define SOFT_INT_VEC_EMIOS_GFR_F11         62
#define SOFT_INT_VEC_EMIOS_GFR_F12         63
#define SOFT_INT_VEC_EMIOS_GFR_F13         64
#define SOFT_INT_VEC_EMIOS_GFR_F14         65
#define SOFT_INT_VEC_EMIOS_GFR_F15         66

#define SOFT_INT_VEC_EMIOS_GFR_F16         202
#define SOFT_INT_VEC_EMIOS_GFR_F17         203
#define SOFT_INT_VEC_EMIOS_GFR_F18         204
#define SOFT_INT_VEC_EMIOS_GFR_F19         205
#define SOFT_INT_VEC_EMIOS_GFR_F20         206
#define SOFT_INT_VEC_EMIOS_GFR_F21         207
#define SOFT_INT_VEC_EMIOS_GFR_F22         208
#define SOFT_INT_VEC_EMIOS_GFR_F23         209

#define SOFT_INT_VEC_ESCIA_SR              146
#define SOFT_INT_VEC_ESCIB_SR              149

extern void ec_interrupts_init(void);
extern void ec_interrupts_allintreg(void);

#endif
