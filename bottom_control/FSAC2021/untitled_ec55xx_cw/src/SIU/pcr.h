/*
 * Code generated for the formwork and Simulink model.
 *
 * FILE    : pcr.h
 *
 * VERSION : 1.000
 *
 * DATE    : Mon Mar 12 10:37:43 2012
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_pcr_h_
#define RTW_HEADER_pcr_h_

/* PA Field Definition */
#define PAD_FUNCTION_GPIO               0x0000
#define PAD_FUNCTION_PRIMARY            0x0400
#define PAD_FUNCTION_ALTERNATE          0x0800
#define PAD_FUNCTION_PRIMARY2           0x0C00
#define PAD_FUNCTION_SECOND_ALTERNATE   0x1000
/* OBE Field Definition */
#define PAD_OBE_ENABLE                  0x0200
#define PAD_OBE_DISABLE                 0x0000
/* IBE Field Definition */
#define PAD_IBE_ENABLE                  0x0100
#define PAD_IBE_DISABLE                 0x0000
/* DSC Field Definition */
#define PAD_DSC_10                      0x0000
#define PAD_DSC_20                      0x0040
#define PAD_DSC_30                      0x0080
#define PAD_DSC_50                      0x00C0
/* ODE Field Definition */
#define PAD_ODE_ENABLE                  0x0020
#define PAD_ODE_DISABLE                 0x0000
/* HYS Field Definition */
#define PAD_HYS_ENABLE                  0x0010
#define PAD_HYS_DISABLE                 0x0000
/* SRC Field Definition */
#define PAD_SRC_MIN                     0x0000
#define PAD_SRC_MED                     0x0004
#define PAD_SRC_RES                     0x0008
#define PAD_SRC_MAX                     0x000C
/* WPE Field Definition */
#define PAD_WPE_ENABLE                  0x0002
#define PAD_WPE_DISABLE                 0x0000
/* WPS Field Definition */
#define PAD_WPS_PULL_UP                 0x0001
#define PAD_WPS_PULL_DOWN               0x0000


/* Pad Configuration Register Definition */
/* Pad Configuration Register 0 */
#define SIU_PCR0_CS_0                      0x0400
#define SIU_PCR0_ADDR_8                    0x0800
#define SIU_PCR0_GPIO_IN                   0x0100
#define SIU_PCR0_GPIO_OUT                  0x0203
/* Pad Configuration Register 1 */
#define SIU_PCR1_CS_1                      0x0400
#define SIU_PCR1_ADDR_9                    0x0800
#define SIU_PCR1_GPIO_IN                   0x0100
#define SIU_PCR1_GPIO_OUT                  0x0203
/* Pad Configuration Register 2:Reserved */
#define SIU_PCR2_CS_2                      0x0400
#define SIU_PCR2_ADDR_10                   0x0800
#define SIU_PCR2_GPIO_IN                   0x0100
#define SIU_PCR2_GPIO_OUT                  0x0203
/* Pad Configuration Register 3:Reserved */
#define SIU_PCR3_CS_3                      0x0400
#define SIU_PCR3_ADDR_11                   0x0800
#define SIU_PCR3_GPIO_IN                   0x0100
#define SIU_PCR3_GPIO_OUT                  0x0203
/* Pad Configuration Register 4:Reserved */
#define SIU_PCR4_ADDR_8                    0x0400
#define SIU_PCR4_GPIO_IN                   0x0100
#define SIU_PCR4_GPIO_OUT                  0x0203
/* Pad Configuration Register 5:Reserved */
#define SIU_PCR5_ADDR_9                    0x0400
#define SIU_PCR5_GPIO_IN                   0x0100
#define SIU_PCR5_GPIO_OUT                  0x0203
/* Pad Configuration Register 6:Reserved */
#define SIU_PCR6_ADDR_10                   0x0400
#define SIU_PCR6_GPIO_IN                   0x0100
#define SIU_PCR6_GPIO_OUT                  0x0203
/* Pad Configuration Register 7 */
#define SIU_PCR7_ADDR_11                   0x0400
#define SIU_PCR7_GPIO_IN                  0x0100
#define SIU_PCR7_GPIO_OUT                 0x0203
/* Pad Configuration Register 8 */
#define SIU_PCR8_ADDR_12                   0x0400
#define SIU_PCR8_GPIO_IN                   0x0100
#define SIU_PCR8_GPIO_OUT                  0x0203
/* Pad Configuration Register 9 */
#define SIU_PCR9_ADDR_13                   0x0400
#define SIU_PCR9_GPIO_IN                   0x0100
#define SIU_PCR9_GPIO_OUT                  0x0203
/* Pad Configuration Register 10 */
#define SIU_PCR10_ADDR_14                  0x0400
#define SIU_PCR10_GPIO_IN                  0x0100
#define SIU_PCR10_GPIO_OUT                 0x0203
/* Pad Configuration Register 11 */
#define SIU_PCR11_ADDR_15                  0x0400
#define SIU_PCR11_GPIO_IN                  0x0100
#define SIU_PCR11_GPIO_OUT                 0x0203
/* Pad Configuration Register 12 */
#define SIU_PCR12_ADDR_16                  0x0400
#define SIU_PCR12_GPIO_IN                  0x0100
#define SIU_PCR12_GPIO_OUT                 0x0203
/* Pad Configuration Register 13 */
#define SIU_PCR13_ADDR_17                  0x0400
#define SIU_PCR13_GPIO_IN                  0x0100
#define SIU_PCR13_GPIO_OUT                 0x0203
/* Pad Configuration Register 14 */
#define SIU_PCR14_ADDR_18                  0x0400
#define SIU_PCR14_GPIO_IN                  0x0100
#define SIU_PCR14_GPIO_OUT                 0x0203
/* Pad Configuration Register 15 */
#define SIU_PCR15_ADDR_19                  0x0400
#define SIU_PCR15_GPIO_IN                  0x0100
#define SIU_PCR15_GPIO_OUT                 0x0203
/* Pad Configuration Register 16 */
#define SIU_PCR16_ADDR_20                  0x0400
#define SIU_PCR16_GPIO_IN                  0x0100
#define SIU_PCR16_GPIO_OUT                 0x0203
/* Pad Configuration Register 17 */
#define SIU_PCR17_ADDR_21                  0x0400
#define SIU_PCR17_GPIO_IN                  0x0100
#define SIU_PCR17_GPIO_OUT                 0x0203
/* Pad Configuration Register 18 */
#define SIU_PCR18_ADDR_22                  0x0400
#define SIU_PCR18_GPIO_IN                  0x0100
#define SIU_PCR18_GPIO_OUT                 0x0203
/* Pad Configuration Register 19 */
#define SIU_PCR19_ADDR_23                  0x0400
#define SIU_PCR19_GPIO_IN                  0x0100
#define SIU_PCR19_GPIO_OUT                 0x0203
/* Pad Configuration Register 20 */
#define SIU_PCR20_ADDR_24                  0x0400
#define SIU_PCR20_GPIO_IN                  0x0100
#define SIU_PCR20_GPIO_OUT                 0x0203
/* Pad Configuration Register 21 */
#define SIU_PCR21_ADDR_25                  0x0400
#define SIU_PCR21_GPIO_IN                  0x0100
#define SIU_PCR21_GPIO_OUT                 0x0203
/* Pad Configuration Register 22 */
#define SIU_PCR22_ADDR_26                  0x0400
#define SIU_PCR22_GPIO_IN                  0x0100
#define SIU_PCR22_GPIO_OUT                 0x0203
/* Pad Configuration Register 23 */
#define SIU_PCR23_ADDR_27                  0x0400
#define SIU_PCR23_GPIO_IN                  0x0100
#define SIU_PCR23_GPIO_OUT                 0x0203
/* Pad Configuration Register 24 */
#define SIU_PCR24_ADDR_28                  0x0400
#define SIU_PCR24_GPIO_IN                  0x0100
#define SIU_PCR24_GPIO_OUT                 0x0203
/* Pad Configuration Register 25 */
#define SIU_PCR25_ADDR_29                  0x0400
#define SIU_PCR25_GPIO_IN                  0x0100
#define SIU_PCR25_GPIO_OUT                 0x0203
/* Pad Configuration Register 26 */
#define SIU_PCR26_ADDR_30                  0x0400
#define SIU_PCR26_GPIO_IN                  0x0100
#define SIU_PCR26_GPIO_OUT                 0x0203
/* Pad Configuration Register 27 */
#define SIU_PCR27_ADDR_31                  0x0400
#define SIU_PCR27_GPIO_IN                  0x0100
#define SIU_PCR27_GPIO_OUT                 0x0203
/* Pad Configuration Register 28 */
#define SIU_PCR28_DATA_0                   0x0400
#define SIU_PCR28_GPIO_IN                  0x0100
#define SIU_PCR28_GPIO_OUT                 0x0203
/* Pad Configuration Register 29 */
#define SIU_PCR29_DATA_1                   0x0400
#define SIU_PCR29_GPIO_IN                  0x0100
#define SIU_PCR29_GPIO_OUT                 0x0203
/* Pad Configuration Register 30 */
#define SIU_PCR30_DATA_2                   0x0400
#define SIU_PCR30_GPIO_IN                  0x0100
#define SIU_PCR30_GPIO_OUT                 0x0203
/* Pad Configuration Register 231 */
#define SIU_PCR31_DATA_3                   0x0400
#define SIU_PCR31_GPIO_IN                  0x0100
#define SIU_PCR31_GPIO_OUT                 0x0203
/* Pad Configuration Register 32 */
#define SIU_PCR32_DATA_4                   0x0400
#define SIU_PCR32_GPIO_IN                  0x0100
#define SIU_PCR32_GPIO_OUT                 0x0203
/* Pad Configuration Register 33 */
#define SIU_PCR33_DATA_5                   0x0400
#define SIU_PCR33_GPIO_IN                  0x0100
#define SIU_PCR33_GPIO_OUT                 0x0203
/* Pad Configuration Register 34 */
#define SIU_PCR34_DATA_6                   0x0400
#define SIU_PCR34_GPIO_IN                  0x0100
#define SIU_PCR34_GPIO_OUT                 0x0203
/* Pad Configuration Register 35 */
#define SIU_PCR35_DATA_7                   0x0400
#define SIU_PCR35_GPIO_IN                  0x0100
#define SIU_PCR35_GPIO_OUT                 0x0203
/* Pad Configuration Register 36 */
#define SIU_PCR36_DATA_8                   0x0400
#define SIU_PCR36_GPIO_IN                  0x0100
#define SIU_PCR36_GPIO_OUT                 0x0203
/* Pad Configuration Register 37 */
#define SIU_PCR37_DATA_9                   0x0400
#define SIU_PCR37_GPIO_IN                  0x0100
#define SIU_PCR37_GPIO_OUT                 0x0203
/* Pad Configuration Register 38 */
#define SIU_PCR38_DATA_10                  0x0400
#define SIU_PCR38_GPIO_IN                  0x0100
#define SIU_PCR38_GPIO_OUT                 0x0203
/* Pad Configuration Register 39 */
#define SIU_PCR39_DATA_11                  0x0400
#define SIU_PCR39_GPIO_IN                  0x0100
#define SIU_PCR39_GPIO_OUT                 0x0203
/* Pad Configuration Register 40 */
#define SIU_PCR40_DATA_12                  0x0400
#define SIU_PCR40_GPIO_IN                  0x0100
#define SIU_PCR40_GPIO_OUT                 0x0203
/* Pad Configuration Register 41 */
#define SIU_PCR41_DATA_13                  0x0400
#define SIU_PCR41_GPIO_IN                  0x0100
#define SIU_PCR41_GPIO_OUT                 0x0203
/* Pad Configuration Register 42 */
#define SIU_PCR42_DATA_14                  0x0400
#define SIU_PCR42_GPIO_IN                  0x0100
#define SIU_PCR42_GPIO_OUT                 0x0203
/* Pad Configuration Register 43 */
#define SIU_PCR43_DATA_15                  0x0400
#define SIU_PCR43_GPIO_IN                  0x0100
#define SIU_PCR43_GPIO_OUT                 0x0203
/* Pad Configuration Register 44 */
#define SIU_PCR44_DATA_16                  0x0400
#define SIU_PCR44_GPIO_IN                  0x0100
#define SIU_PCR44_GPIO_OUT                 0x0203
/* Pad Configuration Register 45 */
#define SIU_PCR45_DATA_17                  0x0400
#define SIU_PCR45_GPIO_IN                  0x0100
#define SIU_PCR45_GPIO_OUT                 0x0203
/* Pad Configuration Register 46 */
#define SIU_PCR46_DATA_18                  0x0400
#define SIU_PCR46_GPIO_IN                  0x0100
#define SIU_PCR46_GPIO_OUT                 0x0203
/* Pad Configuration Register 47 */
#define SIU_PCR47_DATA_19                  0x0400
#define SIU_PCR47_GPIO_IN                  0x0100
#define SIU_PCR47_GPIO_OUT                 0x0203
/* Pad Configuration Register 48 */
#define SIU_PCR48_DATA_20                  0x0400
#define SIU_PCR48_GPIO_IN                  0x0100
#define SIU_PCR48_GPIO_OUT                 0x0203
/* Pad Configuration Register 49 */
#define SIU_PCR49_DATA_21                  0x0400
#define SIU_PCR49_GPIO_IN                  0x0100
#define SIU_PCR49_GPIO_OUT                 0x0203
/* Pad Configuration Register 50 */
#define SIU_PCR50_DATA_22                  0x0400
#define SIU_PCR50_GPIO_IN                  0x0100
#define SIU_PCR50_GPIO_OUT                 0x0203
/* Pad Configuration Register 51 */
#define SIU_PCR51_DATA_23                  0x0400
#define SIU_PCR51_GPIO_IN                  0x0100
#define SIU_PCR51_GPIO_OUT                 0x0203
/* Pad Configuration Register 52 */
#define SIU_PCR52_DATA_24                  0x0400
#define SIU_PCR52_GPIO_IN                  0x0100
#define SIU_PCR52_GPIO_OUT                 0x0203
/* Pad Configuration Register 53 */
#define SIU_PCR53_DATA_25                  0x0400
#define SIU_PCR53_GPIO_IN                  0x0100
#define SIU_PCR53_GPIO_OUT                 0x0203
/* Pad Configuration Register 54 */
#define SIU_PCR54_DATA_26                  0x0400
#define SIU_PCR54_GPIO_IN                  0x0100
#define SIU_PCR54_GPIO_OUT                 0x0203
/* Pad Configuration Register 55 */
#define SIU_PCR55_DATA_27                  0x0400
#define SIU_PCR55_GPIO_IN                  0x0100
#define SIU_PCR55_GPIO_OUT                 0x0203
/* Pad Configuration Register 56 */
#define SIU_PCR56_DATA_28                  0x0400
#define SIU_PCR56_GPIO_IN                  0x0100
#define SIU_PCR56_GPIO_OUT                 0x0203
/* Pad Configuration Register 57 */
#define SIU_PCR57_DATA_29                  0x0400
#define SIU_PCR57_GPIO_IN                  0x0100
#define SIU_PCR57_GPIO_OUT                 0x0203
/* Pad Configuration Register 58 */
#define SIU_PCR58_DATA_30                  0x0400
#define SIU_PCR58_GPIO_IN                  0x0100
#define SIU_PCR58_GPIO_OUT                 0x0203
/* Pad Configuration Register 59 */
#define SIU_PCR59_DATA_31                  0x0400
#define SIU_PCR59_GPIO_IN                  0x0100
#define SIU_PCR59_GPIO_OUT                 0x0203
/* Pad Configuration Register 60 */
#define SIU_PCR60_TSIZ_0                   0x0400
#define SIU_PCR60_GPIO_IN                  0x0100
#define SIU_PCR60_GPIO_OUT                 0x0203
/* Pad Configuration Register 61 */
#define SIU_PCR61_TSIZ_1                   0x0400
#define SIU_PCR61_GPIO_IN                  0x0100
#define SIU_PCR61_GPIO_OUT                 0x0203
/* Pad Configuration Register 62 */
#define SIU_PCR62_WR                       0x0400
#define SIU_PCR62_GPIO_IN                  0x0100
#define SIU_PCR62_GPIO_OUT                 0x0203
/* Pad Configuration Register 63 */
#define SIU_PCR63_BDIP                     0x0400
#define SIU_PCR63_GPIO_IN                  0x0100
#define SIU_PCR63_GPIO_OUT                 0x0203
/* Pad Configuration Register 64 */
#define SIU_PCR64_WE_0                     0x0400
#define SIU_PCR64_BE_0                     0x0800
#define SIU_PCR64_GPIO_IN                  0x0100
#define SIU_PCR64_GPIO_OUT                 0x0203
/* Pad Configuration Register 65 */
#define SIU_PCR65_WE_1                     0x0400
#define SIU_PCR65_BE_1                     0x0800
#define SIU_PCR65_GPIO_IN                  0x0100
#define SIU_PCR65_GPIO_OUT                 0x0203
/* Pad Configuration Register 66 */
#define SIU_PCR66_WE_2                     0x0400
#define SIU_PCR66_BE_2                     0x0800
#define SIU_PCR66_GPIO_IN                  0x0100
#define SIU_PCR66_GPIO_OUT                 0x0203
/* Pad Configuration Register 67 */
#define SIU_PCR67_WE_3                     0x0400
#define SIU_PCR67_BE_3                     0x0800
#define SIU_PCR67_GPIO_IN                  0x0100
#define SIU_PCR67_GPIO_OUT                 0x0203
/* Pad Configuration Register 68 */
#define SIU_PCR68_OE                       0x0400
#define SIU_PCR68_GPIO_IN                  0x0100
#define SIU_PCR68_GPIO_OUT                 0x0203
/* Pad Configuration Register 69 */
#define SIU_PCR69_TS                       0x0400
#define SIU_PCR69_GPIO_IN                  0x0100
#define SIU_PCR69_GPIO_OUT                 0x0203
/* Pad Configuration Register 70 */
#define SIU_PCR70_TA                       0x0400
#define SIU_PCR70_GPIO_IN                  0x0100
#define SIU_PCR70_GPIO_OUT                 0x0203
/* Pad Configuration Register 71 */
#define SIU_PCR71_TEA                      0x0400
#define SIU_PCR71_GPIO_IN                  0x0100
#define SIU_PCR71_GPIO_OUT                 0x0203
/* Pad Configuration Register 72:Reserved */
#define SIU_PCR72_RST                      0x0003
#define SIU_PCR72_BR                       0x0400
#define SIU_PCR72_GPIO_IN                  0x0100
#define SIU_PCR72_GPIO_OUT                 0x0203
/* Pad Configuration Register 73:Reserved */
#define SIU_PCR73_RST                      0x0003
#define SIU_PCR73_BG                       0x0400
#define SIU_PCR73_GPIO_IN                  0x0100
#define SIU_PCR73_GPIO_OUT                 0x0203
/* Pad Configuration Register 74:Reserved */
#define SIU_PCR74_RST                      0x0003
#define SIU_PCR74_BB                       0x0400
#define SIU_PCR74_GPIO_IN                  0x0100
#define SIU_PCR74_GPIO_OUT                 0x0203
/* Pad Configuration Register 75 */
#define SIU_PCR75_MDO_4                    0x00C0
#define SIU_PCR75_GPIO_IN                  0x0100
#define SIU_PCR75_GPIO_OUT                 0x02C0
/* Pad Configuration Register 76 */
#define SIU_PCR76_MDO_5                    0x00C0
#define SIU_PCR76_GPIO_IN                  0x0100
#define SIU_PCR76_GPIO_OUT                 0x02C0
/* Pad Configuration Register 77 */
#define SIU_PCR77_MDO_6                    0x00C0
#define SIU_PCR77_GPIO_IN                  0x0100
#define SIU_PCR77_GPIO_OUT                 0x02C0
/* Pad Configuration Register 78 */
#define SIU_PCR78_MDO_7                    0x00C0
#define SIU_PCR78_GPIO_IN                  0x0100
#define SIU_PCR78_GPIO_OUT                 0x02C0
/* Pad Configuration Register 79 */
#define SIU_PCR79_MDO_8                    0x00C0
#define SIU_PCR79_GPIO_IN                  0x0100
#define SIU_PCR79_GPIO_OUT                 0x02C0
/* Pad Configuration Register 80 */
#define SIU_PCR80_MDO_9                    0x00C0
#define SIU_PCR80_GPIO_IN                  0x0100
#define SIU_PCR80_GPIO_OUT                 0x02C0
/* Pad Configuration Register 81 */
#define SIU_PCR81_MDO_10                   0x00C0
#define SIU_PCR81_GPIO_IN                  0x0100
#define SIU_PCR81_GPIO_OUT                 0x02C0
/* Pad Configuration Register 82 */
#define SIU_PCR82_MDO_11                   0x00C0
#define SIU_PCR82_GPIO_IN                  0x0100
#define SIU_PCR82_GPIO_OUT                 0x02C0
/* Pad Configuration Register 83 */
#define SIU_PCR83_CNTXA                    0x0403
#define SIU_PCR83_GPIO_IN                  0x0100
#define SIU_PCR83_GPIO_OUT                 0x0203
/* Pad Configuration Register 84 */
#define SIU_PCR84_CNRXA                    0x0403
#define SIU_PCR84_GPIO_IN                  0x0100
#define SIU_PCR84_GPIO_OUT                 0x0203
/* Pad Configuration Register 85 */
#define SIU_PCR85_CNTXB                    0x0403
#define SIU_PCR85_PCS_C3                   0x0803
#define SIU_PCR85_GPIO_IN                  0x0100
#define SIU_PCR85_GPIO_OUT                 0x0203
/* Pad Configuration Register 86 */
#define SIU_PCR86_CNRXB                    0x0403
#define SIU_PCR86_PCS_C4                   0x0803
#define SIU_PCR86_GPIO_IN                  0x0100
#define SIU_PCR86_GPIO_OUT                 0x0203
/* Pad Configuration Register 87 */ 
#define SIU_PCR87_CNTXC                    0x0403
#define SIU_PCR87_PCS_D3                   0x0803
#define SIU_PCR87_GPIO_IN                  0x0100
#define SIU_PCR87_GPIO_OUT                 0x0203
/* Pad Configuration Register 88 */
#define SIU_PCR88_CNRXC                    0x0403
#define SIU_PCR88_PCS_D4                   0x0803
#define SIU_PCR88_GPIO_IN                  0x0100
#define SIU_PCR88_GPIO_OUT                 0x0203
/* Pad Configuration Register 89 */
#define SIU_PCR89_TXDA                     0x0600
#define SIU_PCR89_GPIO_IN                  0x0100
#define SIU_PCR89_GPIO_OUT                 0x0203
/* Pad Configuration Register 90 */
#define SIU_PCR90_RXDA                     0x0500
#define SIU_PCR90_GPIO_IN                  0x0100
#define SIU_PCR90_GPIO_OUT                 0x0203
/* Pad Configuration Register 91 */
#define SIU_PCR91_TXDB                     0x0600
#define SIU_PCR91_PCS_D1                   0x0803
#define SIU_PCR91_GPIO_IN                  0x0100
#define SIU_PCR91_GPIO_OUT                 0x0203
/* Pad Configuration Register 92 */
#define SIU_PCR92_RXDB                     0x0500
#define SIU_PCR92_PCS_D5                   0x0803
#define SIU_PCR92_GPIO_IN                  0x0100
#define SIU_PCR92_GPIO_OUT                 0x0203
/* Pad Configuration Register 93 */
#define SIU_PCR93_SCK_A_Master             0x0600
#define SIU_PCR93_SCK_A_Slave              0x0500
#define SIU_PCR93_PCS_C1                   0x0803
#define SIU_PCR93_GPIO_IN                  0x0100
#define SIU_PCR93_GPIO_OUT                 0x0203
/* Pad Configuration Register 94 */
#define SIU_PCR94_SIN_A                    0x0500
#define SIU_PCR94_PCS_C2                   0x0803
#define SIU_PCR94_GPIO_IN                  0x0100
#define SIU_PCR94_GPIO_OUT                 0x0203
/* Pad Configuration Register 95 */
#define SIU_PCR95_SOUT_A                   0x0600
#define SIU_PCR95_PCS_C5                   0x0803
#define SIU_PCR95_GPIO_IN                  0x0100
#define SIU_PCR95_GPIO_OUT                 0x0203
/* Pad Configuration Register 96 */
#define SIU_PCR96_PCS_A0_Master            0x0600
#define SIU_PCR96_PCS_A0_Slave             0x0500
#define SIU_PCR96_PCS_D2                   0x0803
#define SIU_PCR96_GPIO_IN                  0x0100
#define SIU_PCR96_GPIO_OUT                 0x0203
/* Pad Configuration Register 97 */
#define SIU_PCR97_PCS_A1                   0x0400
#define SIU_PCR97_PCS_B2                   0x0800
#define SIU_PCR97_GPIO_IN                  0x0100
#define SIU_PCR97_GPIO_OUT                 0x0203
/* Pad Configuration Register 98 */
#define SIU_PCR98_PCS_A2                   0x0400
#define SIU_PCR98_SCK_D_Master             0x0A00
#define SIU_PCR98_SCK_D_Slave              0x0900
#define SIU_PCR98_GPIO_IN                  0x0100
#define SIU_PCR98_GPIO_OUT                 0x0203
/* Pad Configuration Register 99 */
#define SIU_PCR99_PCS_A3                   0x0400
#define SIU_PCR99_SIN_D                    0x0900
#define SIU_PCR99_GPIO_IN                  0x0100
#define SIU_PCR99_GPIO_OUT                 0x0203
/* Pad Configuration Register 100 */
#define SIU_PCR100_PCS_A4                  0x0400
#define SIU_PCR100_SOUT_D                  0x0A00
#define SIU_PCR100_GPIO_IN                 0x0100
#define SIU_PCR100_GPIO_OUT                0x0203
/* Pad Configuration Register 101 */
#define SIU_PCR101_PCS_A5                  0x0400
#define SIU_PCR101_PCS_B3                  0x0800
#define SIU_PCR101_GPIO_IN                 0x0100
#define SIU_PCR101_GPIO_OUT                0x0203
/* Pad Configuration Register 102 */
#define SIU_PCR102_SCK_B_Master            0x0600
#define SIU_PCR102_SCK_B_Slave             0x0500
#define SIU_PCR102_PCS_C1                  0x0800
#define SIU_PCR102_GPIO_IN                 0x0100
#define SIU_PCR102_GPIO_OUT                0x0203
/* Pad Configuration Register 103 */
#define SIU_PCR103_SIN_B                   0x0500
#define SIU_PCR103_PCS_C2                  0x0A00
#define SIU_PCR103_GPIO_IN                 0x0100
#define SIU_PCR103_GPIO_OUT                0x0203
/* Pad Configuration Register 104 */
#define SIU_PCR104_SOUT_B                  0x0600
#define SIU_PCR104_PCS_C5                  0x0800
#define SIU_PCR104_GPIO_IN                 0x0100
#define SIU_PCR104_GPIO_OUT                0x0203
/* Pad Configuration Register 105 */
#define SIU_PCR105_PCS_B0                  0x0400
#define SIU_PCR105_PCS_D2                  0x0800
#define SIU_PCR105_GPIO_IN                 0x0100
#define SIU_PCR105_GPIO_OUT                0x0203
/* Pad Configuration Register 106 */
#define SIU_PCR106_PCS_B1                  0x0400
#define SIU_PCR106_PCS_D0_Master           0x0A00
#define SIU_PCR106_PCS_D0_Slave            0x0900
#define SIU_PCR106_GPIO_IN                 0x0100
#define SIU_PCR106_GPIO_OUT                0x0203
/* Pad Configuration Register 107 */
#define SIU_PCR107_PCS_B2                  0x0400
#define SIU_PCR107_SOUT_C                  0x0A00
#define SIU_PCR107_GPIO_IN                 0x0100
#define SIU_PCR107_GPIO_OUT                0x0203
/* Pad Configuration Register 108 */
#define SIU_PCR108_PCS_B3                  0x0400
#define SIU_PCR108_SIN_C                   0x0900
#define SIU_PCR108_GPIO_IN                 0x0100
#define SIU_PCR108_GPIO_OUT                0x0203
/* Pad Configuration Register 109 */
#define SIU_PCR109_PCS_B4                  0x0400
#define SIU_PCR109_SCK_C_Master            0x0A00
#define SIU_PCR109_SCK_C_Slave             0x0900
#define SIU_PCR109_GPIO_IN                 0x0100
#define SIU_PCR109_GPIO_OUT                0x0203
/* Pad Configuration Register 110 */
#define SIU_PCR110_PCS_B5                  0x0400
#define SIU_PCR110_PCS_C0_Master           0x0A00
#define SIU_PCR110_PCS_C0_Slave            0x0900
#define SIU_PCR110_GPIO_IN                 0x0100
#define SIU_PCR110_GPIO_OUT                0x0203
/* Pad Configuration Register 111 */
#define SIU_PCR111_ETRIG_0                 0x0400
#define SIU_PCR111_GPIO_IN                 0x0100
#define SIU_PCR111_GPIO_OUT                0x0203
/* Pad Configuration Register 112 */
#define SIU_PCR112_ETRIG_1                 0x0400
#define SIU_PCR112_GPIO_IN                 0x0100
#define SIU_PCR112_GPIO_OUT                0x0203
/* Pad Configuration Register 113 */
#define SIU_PCR113_TCRCLK_A                0x0400
#define SIU_PCR113_IRQ_7                   0x0800
#define SIU_PCR113_GPIO_IN                 0x0100
#define SIU_PCR113_GPIO_OUT                0x0203
/* Pad Configuration Register 114 */
#define SIU_PCR114_TPU_A0_OUT              0x0603     //eTPU
#define SIU_PCR114_TPU_A0_IN               0x0500
#define SIU_PCR114_GPIO_IN                 0x0100
#define SIU_PCR114_GPIO_OUT                0x0203
/* Pad Configuration Register 115 */
#define SIU_PCR115_TPU_A1_OUT              0x0603
#define SIU_PCR115_TPU_A1_IN               0x0500
#define SIU_PCR115_GPIO_IN                 0x0100
#define SIU_PCR115_GPIO_OUT                0x0203
/* Pad Configuration Register 116 */
#define SIU_PCR116_TPU_A2_OUT              0x0603
#define SIU_PCR116_TPU_A2_IN               0x0500
#define SIU_PCR116_GPIO_IN                 0x0100
#define SIU_PCR116_GPIO_OUT                0x0203
/* Pad Configuration Register 117 */
#define SIU_PCR117_TPU_A3_OUT              0x0603
#define SIU_PCR117_TPU_A3_IN               0x0500
#define SIU_PCR117_GPIO_IN                 0x0100
#define SIU_PCR117_GPIO_OUT                0x0203
/* Pad Configuration Register 118 */
#define SIU_PCR118_TPU_A4_OUT              0x0603
#define SIU_PCR118_TPU_A4_IN               0x0500
#define SIU_PCR118_GPIO_IN                 0x0100
#define SIU_PCR118_GPIO_OUT                0x0203
/* Pad Configuration Register 119 */
#define SIU_PCR119_TPU_A5_OUT              0x0603
#define SIU_PCR119_TPU_A5_IN               0x0500
#define SIU_PCR119_GPIO_IN                 0x0100
#define SIU_PCR119_GPIO_OUT                0x0203
/* Pad Configuration Register 120 */
#define SIU_PCR120_TPU_A6_OUT              0x0603
#define SIU_PCR120_TPU_A6_IN               0x0500
#define SIU_PCR120_GPIO_IN                 0x0100
#define SIU_PCR120_GPIO_OUT                0x0203
/* Pad Configuration Register 121 */
#define SIU_PCR121_TPU_A7_OUT              0x0603
#define SIU_PCR121_TPU_A7_IN               0x0500
#define SIU_PCR121_GPIO_IN                 0x0100
#define SIU_PCR121_GPIO_OUT                0x0203
/* Pad Configuration Register 122 */
#define SIU_PCR122_TPU_A8_OUT              0x0603
#define SIU_PCR122_TPU_A8_IN               0x0500
#define SIU_PCR122_GPIO_IN                 0x0100
#define SIU_PCR122_GPIO_OUT                0x0203
/* Pad Configuration Register 123 */
#define SIU_PCR123_TPU_A9_OUT              0x0603
#define SIU_PCR123_TPU_A9_IN               0x0500
#define SIU_PCR123_GPIO_IN                 0x0100
#define SIU_PCR123_GPIO_OUT                0x0203
/* Pad Configuration Register 124 */
#define SIU_PCR124_TPU_A10_OUT             0x0603
#define SIU_PCR124_TPU_A10_IN              0x0500
#define SIU_PCR124_GPIO_IN                 0x0100
#define SIU_PCR124_GPIO_OUT                0x0203
/* Pad Configuration Register 125 */
#define SIU_PCR125_TPU_A11_OUT             0x0603
#define SIU_PCR125_TPU_A11_IN              0x0500
#define SIU_PCR125_GPIO_IN                 0x0100
#define SIU_PCR125_GPIO_OUT                0x0203
/* Pad Configuration Register 126 */
#define SIU_PCR126_TPU_A12_OUT             0x0603
#define SIU_PCR126_TPU_A12_IN              0x0500
#define SIU_PCR126_PCS_B1                  0x0800
#define SIU_PCR126_GPIO_IN                 0x0100
#define SIU_PCR126_GPIO_OUT                0x0203
/* Pad Configuration Register 127 */
#define SIU_PCR127_TPU_A13_OUT             0x0603
#define SIU_PCR127_TPU_A13_IN              0x0500
#define SIU_PCR127_PCS_B3                  0x0800
#define SIU_PCR127_GPIO_IN                 0x0100
#define SIU_PCR127_GPIO_OUT                0x0203
/* Pad Configuration Register 128 */
#define SIU_PCR128_TPU_A14_OUT             0x0603
#define SIU_PCR128_TPU_A14_IN              0x0500
#define SIU_PCR128_PCS_B4                  0x0800
#define SIU_PCR128_GPIO_IN                 0x0100
#define SIU_PCR128_GPIO_OUT                0x0203
/* Pad Configuration Register 129 */
#define SIU_PCR129_TPU_A15_OUT             0x0603
#define SIU_PCR129_TPU_A15_IN              0x0500
#define SIU_PCR129_PCS_B5                  0x0800
#define SIU_PCR129_GPIO_IN                 0x0100
#define SIU_PCR129_GPIO_OUT                0x0203
/* Pad Configuration Register 130 */
#define SIU_PCR130_TPU_A16_OUT             0x0603
#define SIU_PCR130_TPU_A16_IN              0x0500
#define SIU_PCR130_PCS_D1                  0x0800
#define SIU_PCR130_GPIO_IN                 0x0100
#define SIU_PCR130_GPIO_OUT                0x0203
/* Pad Configuration Register 131 */
#define SIU_PCR131_TPU_A17_OUT             0x0603
#define SIU_PCR131_TPU_A17_IN              0x0500
#define SIU_PCR131_PCS_D2                  0x0800
#define SIU_PCR131_GPIO_IN                 0x0100
#define SIU_PCR131_GPIO_OUT                0x0203
/* Pad Configuration Register 132 */
#define SIU_PCR132_TPU_A18_OUT             0x0603
#define SIU_PCR132_TPU_A18_IN              0x0500
#define SIU_PCR132_PCS_D3                  0x0800
#define SIU_PCR132_GPIO_IN                 0x0100
#define SIU_PCR132_GPIO_OUT                0x0203
/* Pad Configuration Register 133 */
#define SIU_PCR133_TPU_A19_OUT             0x0603
#define SIU_PCR133_TPU_A19_IN              0x0500
#define SIU_PCR133_PCS_D4                  0x0800
#define SIU_PCR133_GPIO_IN                 0x0100
#define SIU_PCR133_GPIO_OUT                0x0203
/* Pad Configuration Register 134 */
#define SIU_PCR134_TPU_A20_OUT             0x0603
#define SIU_PCR134_TPU_A20_IN              0x0500
#define SIU_PCR134_IRQ_8                   0x0800
#define SIU_PCR134_GPIO_IN                 0x0100
#define SIU_PCR134_GPIO_OUT                0x0203
/* Pad Configuration Register 135 */
#define SIU_PCR135_TPU_A21_OUT             0x0603
#define SIU_PCR135_TPU_A21_IN              0x0500
#define SIU_PCR135_IRQ_9                   0x0800
#define SIU_PCR135_GPIO_IN                 0x0100
#define SIU_PCR135_GPIO_OUT                0x0203
/* Pad Configuration Register 136 */
#define SIU_PCR136_TPU_A22_OUT             0x0603
#define SIU_PCR136_TPU_A22_IN              0x0500
#define SIU_PCR136_IRQ_10                  0x0800
#define SIU_PCR136_GPIO_IN                 0x0100
#define SIU_PCR136_GPIO_OUT                0x0203
/* Pad Configuration Register 137 */
#define SIU_PCR137_TPU_A23_OUT             0x0603
#define SIU_PCR137_TPU_A23_IN              0x0500
#define SIU_PCR137_IRQ_11                  0x0800
#define SIU_PCR137_GPIO_IN                 0x0100
#define SIU_PCR137_GPIO_OUT                0x0203
/* Pad Configuration Register 138 */
#define SIU_PCR138_TPU_A24                 0x0400
#define SIU_PCR138_IRQ_12                  0x0800
#define SIU_PCR138_GPIO_IN                 0x0100
#define SIU_PCR138_GPIO_OUT                0x0203
/* Pad Configuration Register 139 */
#define SIU_PCR139_TPU_A25                 0x0400
#define SIU_PCR139_IRQ_13                  0x0800
#define SIU_PCR139_GPIO_IN                 0x0100
#define SIU_PCR139_GPIO_OUT                0x0203
/* Pad Configuration Register 140 */
#define SIU_PCR140_TPU_A26                 0x0400
#define SIU_PCR140_IRQ_14                  0x0800
#define SIU_PCR140_GPIO_IN                 0x0100
#define SIU_PCR140_GPIO_OUT                0x0203
/* Pad Configuration Register 141 */
#define SIU_PCR141_TPU_A27                 0x0400
#define SIU_PCR141_IRQ_15                  0x0800
#define SIU_PCR141_GPIO_IN                 0x0100
#define SIU_PCR141_GPIO_OUT                0x0203
/* Pad Configuration Register 142 */
#define SIU_PCR142_TPU_A28                 0x0400
#define SIU_PCR142_PCS_C1                  0x0800
#define SIU_PCR142_GPIO_IN                 0x0100
#define SIU_PCR142_GPIO_OUT                0x0203
/* Pad Configuration Register 143 */
#define SIU_PCR143_TPU_A29                 0x0400
#define SIU_PCR143_PCS_C2                  0x0800
#define SIU_PCR143_GPIO_IN                 0x0100
#define SIU_PCR143_GPIO_OUT                0x0203
/* Pad Configuration Register 144 */
#define SIU_PCR144_TPU_A30_OUT             0x0603
#define SIU_PCR144_TPU_A30_IN              0x0500
#define SIU_PCR144_PCS_C3                  0x0800
#define SIU_PCR144_GPIO_IN                 0x0100
#define SIU_PCR144_GPIO_OUT                0x0203
/* Pad Configuration Register 145 */
#define SIU_PCR145_TPU_A31_OUT             0x0603
#define SIU_PCR145_TPU_A31_IN              0x0500
#define SIU_PCR145_PCS_C4                  0x0800
#define SIU_PCR145_GPIO_IN                 0x0100
#define SIU_PCR145_GPIO_OUT                0x0203
/* Pad Configuration Register 146 */
#define SIU_PCR146_TCRCLK_B                0x0400
#define SIU_PCR146_IRQ_6                   0x0800
#define SIU_PCR146_GPIO_IN                 0x0100
#define SIU_PCR146_GPIO_OUT                0x0203
/* Pad Configuration Register 147 */
#define SIU_PCR147_TPU_B_0_OUT             0x0603
#define SIU_PCR147_TPU_B_0_IN              0x0500
#define SIU_PCR147_GPIO_IN                 0x0100
#define SIU_PCR147_GPIO_OUT                0x0203
/* Pad Configuration Register 148 */
#define SIU_PCR148_TPU_B_1_OUT             0x0603
#define SIU_PCR148_TPU_B_1_IN              0x0500
#define SIU_PCR148_GPIO_IN                 0x0100
#define SIU_PCR148_GPIO_OUT                0x0203
/* Pad Configuration Register 149 */
#define SIU_PCR149_TPU_B_2_OUT             0x0603
#define SIU_PCR149_TPU_B_2_IN              0x0500
#define SIU_PCR149_GPIO_IN                 0x0100
#define SIU_PCR149_GPIO_OUT                0x0203
/* Pad Configuration Register 150 */
#define SIU_PCR150_TPU_B_3_OUT             0x0603
#define SIU_PCR150_TPU_B_3_IN              0x0500
#define SIU_PCR150_GPIO_IN                 0x0100
#define SIU_PCR150_GPIO_OUT                0x0203
/* Pad Configuration Register 151 */
#define SIU_PCR151_TPU_B_4_OUT             0x0603
#define SIU_PCR151_TPU_B_4_IN              0x0500
#define SIU_PCR151_GPIO_IN                 0x0100
#define SIU_PCR151_GPIO_OUT                0x0203
/* Pad Configuration Register 152 */
#define SIU_PCR152_TPU_B_5_OUT             0x0603
#define SIU_PCR152_TPU_B_5_IN              0x0500
#define SIU_PCR152_GPIO_IN                 0x0100
#define SIU_PCR152_GPIO_OUT                0x0203
/* Pad Configuration Register 153 */
#define SIU_PCR153_TPU_B_6_OUT             0x0603
#define SIU_PCR153_TPU_B_6_IN              0x0500
#define SIU_PCR153_GPIO_IN                 0x0100
#define SIU_PCR153_GPIO_OUT                0x0203
/* Pad Configuration Register 154 */
#define SIU_PCR154_TPU_B_7_OUT             0x0603
#define SIU_PCR154_TPU_B_7_IN              0x0500
#define SIU_PCR154_GPIO_IN                 0x0100
#define SIU_PCR154_GPIO_OUT                0x0203
/* Pad Configuration Register 155 */
#define SIU_PCR155_TPU_B_8_OUT             0x0603
#define SIU_PCR155_TPU_B_8_IN              0x0500
#define SIU_PCR155_GPIO_IN                 0x0100
#define SIU_PCR155_GPIO_OUT                0x0203
/* Pad Configuration Register 156 */
#define SIU_PCR156_TPU_B_9_OUT             0x0603
#define SIU_PCR156_TPU_B_9_IN              0x0500
#define SIU_PCR156_GPIO_IN                 0x0100
#define SIU_PCR156_GPIO_OUT                0x0203
/* Pad Configuration Register 157 */
#define SIU_PCR157_TPU_B_10_OUT            0x0603
#define SIU_PCR157_TPU_B_10_IN             0x0500
#define SIU_PCR157_GPIO_IN                 0x0100
#define SIU_PCR157_GPIO_OUT                0x0203
/* Pad Configuration Register 158 */
#define SIU_PCR158_TPU_B_11_OUT            0x0603
#define SIU_PCR158_TPU_B_11_IN             0x0500
#define SIU_PCR158_GPIO_IN                 0x0100
#define SIU_PCR158_GPIO_OUT                0x0203
/* Pad Configuration Register 159 */
#define SIU_PCR159_TPU_B_12_OUT            0x0603
#define SIU_PCR159_TPU_B_12_IN             0x0500
#define SIU_PCR159_GPIO_IN                 0x0100
#define SIU_PCR159_GPIO_OUT                0x0203
/* Pad Configuration Register 160 */
#define SIU_PCR160_TPU_B_13_OUT            0x0603
#define SIU_PCR160_TPU_B_13_IN             0x0500
#define SIU_PCR160_GPIO_IN                 0x0100
#define SIU_PCR160_GPIO_OUT                0x0203
/* Pad Configuration Register 161 */
#define SIU_PCR161_TPU_B_14_OUT            0x0603
#define SIU_PCR161_TPU_B_14_IN             0x0500
#define SIU_PCR161_GPIO_IN                 0x0100
#define SIU_PCR161_GPIO_OUT                0x0203
/* Pad Configuration Register 162 */
#define SIU_PCR162_TPU_B_15_OUT            0x0603
#define SIU_PCR162_TPU_B_15_IN             0x0500
#define SIU_PCR162_GPIO_IN                 0x0100
#define SIU_PCR162_GPIO_OUT                0x0203
/* Pad Configuration Register 163 */
#define SIU_PCR163_TPU_B_16_OUT            0x0603
#define SIU_PCR163_TPU_B_16_IN             0x0500
#define SIU_PCR163_PCS_A1                  0x0800
#define SIU_PCR163_GPIO_IN                 0x0100
#define SIU_PCR163_GPIO_OUT                0x0203
/* Pad Configuration Register 164 */
#define SIU_PCR164_TPU_B_17_OUT            0x0603
#define SIU_PCR164_TPU_B_17_IN             0x0500
#define SIU_PCR164_PCS_A2                  0x0800
#define SIU_PCR164_GPIO_IN                 0x0100
#define SIU_PCR164_GPIO_OUT                0x0203
/* Pad Configuration Register 165 */
#define SIU_PCR165_TPU_B_18_OUT            0x0603
#define SIU_PCR165_TPU_B_18_IN             0x0500
#define SIU_PCR165_PCS_A3                  0x0800
#define SIU_PCR165_GPIO_IN                 0x0100
#define SIU_PCR165_GPIO_OUT                0x0203
/* Pad Configuration Register 166 */
#define SIU_PCR166_TPU_B_19_OUT            0x0603
#define SIU_PCR166_TPU_B_19_IN             0x0500
#define SIU_PCR166_PCS_A4                  0x0800
#define SIU_PCR166_GPIO_IN                 0x0100
#define SIU_PCR166_GPIO_OUT                0x0203
/* Pad Configuration Register 167 */
#define SIU_PCR167_TPU_B_20_OUT            0x0603
#define SIU_PCR167_TPU_B_20_IN             0x0500
#define SIU_PCR167_GPIO_IN                 0x0100
#define SIU_PCR167_GPIO_OUT                0x0203
/* Pad Configuration Register 168 */
#define SIU_PCR168_TPU_B_21_OUT            0x0603
#define SIU_PCR168_TPU_B_21_IN             0x0500
#define SIU_PCR168_GPIO_IN                 0x0100
#define SIU_PCR168_GPIO_OUT                0x0203
/* Pad Configuration Register 169 */
#define SIU_PCR169_TPU_B_22_OUT            0x0603
#define SIU_PCR169_TPU_B_22_IN             0x0500
#define SIU_PCR169_GPIO_IN                 0x0100
#define SIU_PCR169_GPIO_OUT                0x0203
/* Pad Configuration Register 170 */
#define SIU_PCR170_TPU_B_23_OUT            0x0603
#define SIU_PCR170_TPU_B_23_IN             0x0500
#define SIU_PCR170_GPIO_IN                 0x0100
#define SIU_PCR170_GPIO_OUT                0x0203
/* Pad Configuration Register 171 */
#define SIU_PCR171_TPU_B_24_OUT            0x0603
#define SIU_PCR171_TPU_B_24_IN             0x0500
#define SIU_PCR171_GPIO_IN                 0x0100
#define SIU_PCR171_GPIO_OUT                0x0203
/* Pad Configuration Register 172 */
#define SIU_PCR172_TPU_B_25_OUT            0x0603
#define SIU_PCR172_TPU_B_25_IN             0x0500
#define SIU_PCR172_GPIO_IN                 0x0100
#define SIU_PCR172_GPIO_OUT                0x0203
/* Pad Configuration Register 173 */
#define SIU_PCR173_TPU_B_26_OUT            0x0603
#define SIU_PCR173_TPU_B_26_IN             0x0500
#define SIU_PCR173_GPIO_IN                 0x0100
#define SIU_PCR173_GPIO_OUT                0x0203
/* Pad Configuration Register 174 */
#define SIU_PCR174_TPU_B_27_OUT            0x0603
#define SIU_PCR174_TPU_B_27_IN             0x0500
#define SIU_PCR174_GPIO_IN                 0x0100
#define SIU_PCR174_GPIO_OUT                0x0203
/* Pad Configuration Register 175 */
#define SIU_PCR175_TPU_B_28_OUT            0x0603
#define SIU_PCR175_TPU_B_28_IN             0x0500
#define SIU_PCR175_GPIO_IN                 0x0100
#define SIU_PCR175_GPIO_OUT                0x0203
/* Pad Configuration Register 176 */
#define SIU_PCR176_TPU_B_29_OUT            0x0603
#define SIU_PCR176_TPU_B_29_IN             0x0500
#define SIU_PCR176_GPIO_IN                 0x0100
#define SIU_PCR176_GPIO_OUT                0x0203
/* Pad Configuration Register 177 */
#define SIU_PCR177_TPU_B_30_OUT            0x0603
#define SIU_PCR177_TPU_B_30_IN             0x0500
#define SIU_PCR177_GPIO_IN                 0x0100
#define SIU_PCR177_GPIO_OUT                0x0203
/* Pad Configuration Register 178 */
#define SIU_PCR178_TPU_B_31_OUT            0x0603
#define SIU_PCR178_TPU_B_31_IN             0x0500
#define SIU_PCR178_GPIO_IN                 0x0100
#define SIU_PCR178_GPIO_OUT                0x0203
/* Pad Configuration Register 179 */
#define SIU_PCR179_EMIOS_0_OUT             0x0603     //eMIOS
#define SIU_PCR179_EMIOS_0_IN              0x0500
#define SIU_PCR179_GPIO_IN                 0x0100
#define SIU_PCR179_GPIO_OUT                0x0203
/* Pad Configuration Register 180 */
#define SIU_PCR180_EMIOS_1_OUT             0x0603
#define SIU_PCR180_EMIOS_1_IN              0x0500
#define SIU_PCR180_GPIO_IN                 0x0100
#define SIU_PCR180_GPIO_OUT                0x0203
/* Pad Configuration Register 181 */
#define SIU_PCR181_EMIOS_2_OUT             0x0603
#define SIU_PCR181_EMIOS_2_IN              0x0500
#define SIU_PCR181_GPIO_IN                 0x0100
#define SIU_PCR181_GPIO_OUT                0x0203
/* Pad Configuration Register 182 */
#define SIU_PCR182_EMIOS_3_OUT             0x0603
#define SIU_PCR182_EMIOS_3_IN              0x0500
#define SIU_PCR182_GPIO_IN                 0x0100
#define SIU_PCR182_GPIO_OUT                0x0203
/* Pad Configuration Register 183 */
#define SIU_PCR183_EMIOS_4_OUT             0x0603
#define SIU_PCR183_EMIOS_4_IN              0x0500
#define SIU_PCR183_GPIO_IN                 0x0100
#define SIU_PCR183_GPIO_OUT                0x0203
/* Pad Configuration Register 184 */
#define SIU_PCR184_EMIOS_5_OUT             0x0603
#define SIU_PCR184_EMIOS_5_IN              0x0500
#define SIU_PCR184_GPIO_IN                 0x0100
#define SIU_PCR184_GPIO_OUT                0x0203
/* Pad Configuration Register 185 */
#define SIU_PCR185_EMIOS_6_OUT             0x0603
#define SIU_PCR185_EMIOS_6_IN              0x0500
#define SIU_PCR185_GPIO_IN                 0x0100
#define SIU_PCR185_GPIO_OUT                0x0203
/* Pad Configuration Register 186 */
#define SIU_PCR186_EMIOS_7_OUT             0x0603
#define SIU_PCR186_EMIOS_7_IN              0x0500
#define SIU_PCR186_GPIO_IN                 0x0100
#define SIU_PCR186_GPIO_OUT                0x0203
/* Pad Configuration Register 187 */
#define SIU_PCR187_EMIOS_8_OUT             0x0603
#define SIU_PCR187_EMIOS_8_IN              0x0500
#define SIU_PCR187_GPIO_IN                 0x0100
#define SIU_PCR187_GPIO_OUT                0x0203
/* Pad Configuration Register 188 */
#define SIU_PCR188_EMIOS_9_OUT             0x0603
#define SIU_PCR188_EMIOS_9_IN              0x0500
#define SIU_PCR188_GPIO_IN                 0x0100
#define SIU_PCR188_GPIO_OUT                0x0203
/* Pad Configuration Register 189 */
#define SIU_PCR189_EMIOS_10_OUT            0x0603
#define SIU_PCR189_EMIOS_10_IN             0x0500
#define SIU_PCR189_GPIO_IN                 0x0100
#define SIU_PCR189_GPIO_OUT                0x0203
/* Pad Configuration Register 190 */
#define SIU_PCR190_EMIOS_11_OUT            0x0603
#define SIU_PCR190_EMIOS_11_IN             0x0500
#define SIU_PCR190_GPIO_IN                 0x0100
#define SIU_PCR190_GPIO_OUT                0x0203
/* Pad Configuration Register 191 */
#define SIU_PCR191_EMIOS_12                0x0400
#define SIU_PCR191_SOUT_C                  0x0800
#define SIU_PCR191_GPIO_IN                 0x0100
#define SIU_PCR191_GPIO_OUT                0x0203
/* Pad Configuration Register 192 */
#define SIU_PCR192_EMIOS_13                0x0400
#define SIU_PCR192_SOUT_D                  0x0800
#define SIU_PCR192_GPIO_IN                 0x0100
#define SIU_PCR192_GPIO_OUT                0x0203
/* Pad Configuration Register 193 */
#define SIU_PCR193_EMIOS_14                0x0400
#define SIU_PCR193_IRQ_0                   0x0800
#define SIU_PCR193_GPIO_IN                 0x0100
#define SIU_PCR193_GPIO_OUT                0x0203
/* Pad Configuration Register 194 */
#define SIU_PCR194_EMIOS_15                0x0400
#define SIU_PCR194_IRQ_1                   0x0800
#define SIU_PCR194_GPIO_IN                 0x0100
#define SIU_PCR194_GPIO_OUT                0x0203
/* Pad Configuration Register 195 */
#define SIU_PCR195_EMIOS_16_OUT            0x0603
#define SIU_PCR195_EMIOS_16_IN             0x0500
#define SIU_PCR195_GPIO_IN                 0x0100
#define SIU_PCR195_GPIO_OUT                0x0203
/* Pad Configuration Register 196 */
#define SIU_PCR196_EMIOS_17_OUT            0x0603
#define SIU_PCR196_EMIOS_17_IN             0x0500
#define SIU_PCR196_GPIO_IN                 0x0100
#define SIU_PCR196_GPIO_OUT                0x0203
/* Pad Configuration Register 197 */
#define SIU_PCR197_EMIOS_18_OUT            0x0603
#define SIU_PCR197_EMIOS_18_IN             0x0500
#define SIU_PCR197_GPIO_IN                 0x0100
#define SIU_PCR197_GPIO_OUT                0x0203
/* Pad Configuration Register 198 */
#define SIU_PCR198_EMIOS_19_OUT            0x0603
#define SIU_PCR198_EMIOS_19_IN             0x0500
#define SIU_PCR198_GPIO_IN                 0x0100
#define SIU_PCR198_GPIO_OUT                0x0203
/* Pad Configuration Register 199 */
#define SIU_PCR199_EMIOS_20_OUT            0x0603
#define SIU_PCR199_EMIOS_20_IN             0x0500
#define SIU_PCR199_GPIO_IN                 0x0100
#define SIU_PCR199_GPIO_OUT                0x0203
/* Pad Configuration Register 200 */
#define SIU_PCR200_EMIOS_21_OUT            0x0603
#define SIU_PCR200_EMIOS_21_IN             0x0500
#define SIU_PCR200_GPIO_IN                 0x0100
#define SIU_PCR200_GPIO_OUT                0x0203
/* Pad Configuration Register 201 */
#define SIU_PCR201_EMIOS_22_OUT            0x0603
#define SIU_PCR201_EMIOS_22_IN             0x0500
#define SIU_PCR201_GPIO_IN                 0x0100
#define SIU_PCR201_GPIO_OUT                0x0203
/* Pad Configuration Register 202 */
#define SIU_PCR202_EMIOS_23_OUT            0x0603
#define SIU_PCR202_EMIOS_23_IN             0x0500
#define SIU_PCR202_GPIO_IN                 0x0100
#define SIU_PCR202_GPIO_OUT                0x0203
/* Pad Configuration Register 203 */
#define SIU_PCR203_GPIO_IN                 0x0100
#define SIU_PCR203_GPIO_OUT                0x0203
/* Pad Configuration Register 204 */
#define SIU_PCR204_GPIO_IN                 0x0100
#define SIU_PCR204_GPIO_OUT                0x0203
/* Pad Configuration Register 205 */
#define SIU_PCR205_GPIO_IN                 0x0100
#define SIU_PCR205_GPIO_OUT                0x0203
/* Pad Configuration Register 206 */
#define SIU_PCR206_GPIO_IN                 0x0100
#define SIU_PCR206_GPIO_OUT                0x0203
/* Pad Configuration Register 207 */
#define SIU_PCR207_GPIO_IN                 0x0100
#define SIU_PCR207_GPIO_OUT                0x0203
/* Pad Configuration Register 208 */
#define SIU_PCR208_PLLCFG_0                0x0C13
#define SIU_PCR208_IRQ_4                   0x0813
#define SIU_PCR208_GPIO_IN                 0x0100
#define SIU_PCR208_GPIO_OUT                0x0203
/* Pad Configuration Register 209 */
#define SIU_PCR209_PLLCFG_1                0x0C13
#define SIU_PCR209_IRQ_5                   0x0813
#define SIU_PCR209_SOUT_D                  0x1000
#define SIU_PCR209_GPIO_IN                 0x0100
#define SIU_PCR209_GPIO_OUT                0x0203
/* Pad Configuration Register 210 */
#define SIU_PCR210_RSTCFG                  0x0413
#define SIU_PCR210_GPIO_IN                 0x0100
#define SIU_PCR210_GPIO_OUT                0x0203
/* Pad Configuration Register 211 */
#define SIU_PCR211_BOOTCFG_0               0x0C12
#define SIU_PCR211_IRQ_2                   0x0812
#define SIU_PCR211_GPIO_IN                 0x0100
#define SIU_PCR211_GPIO_OUT                0x0202
/* Pad Configuration Register 212 */
#define SIU_PCR212_BOOTCFG_1               0x0C12
#define SIU_PCR212_IRQ_3                   0x0812
#define SIU_PCR212_GPIO_IN                 0x0100
#define SIU_PCR212_GPIO_OUT                0x0203
/* Pad Configuration Register 213 */
#define SIU_PCR213_WKPCFG                  0x0413
#define SIU_PCR213_GPIO_IN                 0x0100
#define SIU_PCR213_GPIO_OUT                0x0203
/* Pad Configuration Register 214 */
#define SIU_PCR214_ENGCLK                  0x02C0
/* Pad Configuration Register 215 */
#define SIU_PCR215_AN_12                   0x0C00
#define SIU_PCR215_MA_0                    0x0800
#define SIU_PCR215_SDS                     0x0000
/* Pad Configuration Register 216 */
#define SIU_PCR216_AN_13                   0x0C00
#define SIU_PCR216_MA_1                    0x0800
#define SIU_PCR216_SDO                     0x0000
/* Pad Configuration Register 217 */
#define SIU_PCR217_AN_14                   0x0C00
#define SIU_PCR217_MA_2                    0x0800
#define SIU_PCR217_SDI                     0x0000
/* Pad Configuration Register 218 */
#define SIU_PCR218_AN_15                   0x0400
#define SIU_PCR218_AN_FCK                  0x0000
/* Pad Configuration Register 219 */
#define SIU_PCR219_MCKO                    0x00C0
/* Pad Configuration Register 220 */
#define SIU_PCR220_MDO_0                   0x00C0
/* Pad Configuration Register 221 */
#define SIU_PCR221_MDO_1                   0x00C0
/* Pad Configuration Register 222 */
#define SIU_PCR222_MDO_2                   0x00C0
/* Pad Configuration Register 223 */
#define SIU_PCR223_MDO_3                   0x00C0
/* Pad Configuration Register 224 */
#define SIU_PCR224_MSEO_0                  0x00C0
/* Pad Configuration Register 225 */
#define SIU_PCR225_MSEO_1                  0x00C0
/* Pad Configuration Register 226 */
#define SIU_PCR226_RDY                     0x00C0
/* Pad Configuration Register 227 */
#define SIU_PCR227_EVTO                    0x00C0
/* Pad Configuration Register 228 */
#define SIU_PCR228_TDO                     0x00C0
/* Pad Configuration Register 229 */
#define SIU_PCR229_CLKOUT                  0x02C0
/* Pad Configuration Register 230 */
#define SIU_PCR230_RSTOUT                  0x000C

#endif /* RTW_HEADER_pcr_h_ */
