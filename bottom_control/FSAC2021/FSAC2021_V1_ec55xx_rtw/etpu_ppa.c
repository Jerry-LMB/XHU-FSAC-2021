/*
 * Code generated for Simulink model FSAC2021_V1.
 *
 * FILE    : etpu_ppa.c
 *
 * VERSION : 1.219
 *
 * DATE    : Sat Oct 30 18:49:46 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "etpu_util.h"                 /* Utility routines for working eTPU */
#include "etpu_ppa.h"                  /* eTPU PPA API */

extern uint32_t fs_etpu_data_ram_start;

#if 1

/***************************************************************************
   FUNCTION     : fs_etpu_ppa_p_init
   PURPOSE      : To initialize an eTPU channel to generate a ppa output.
   INPUTS NOTES : This function has 5 parameters:
   channel - This is the channel number.
   0-31 for ETPU_A and 64-95 for ETPU_B.
   priority - This is the priority to assign to the channel.
   This parameter should be assigned a value of:
   ETPU_PRIORITY_HIGH, ETPU_PRIORITY_MIDDLE or
   ETPU_PRIORITY_LOW.
   timebase - This is the timer to use as a reference for the ppa
   function. This parameter should be assigned to a
   value of: FS_ETPU_PPA_INIT_TCR1 or
   FS_ETPU_PPA_INIT_TCR2.
   mode - This is the mode to use for PPA measurements. This
   parameter should be assigned a value of:
   FS_ETPU_PPA_LOW_P_PULSE,
   FS_ETPU_PPA_HIGH_P_PULSE,
   FS_ETPU_PPA_FALLING_P_EDGE,
   FS_ETPU_PPA_RISING_P_EDGE
   max_count - This is the number of periods or pulses that are
   accumulated before the measurement restarts. This
   parameter should be assigned a value in the range
   0 to 255. A value of zero or one results in the
   accumulation of one period or pulse width.
   sample_time - Defines the rate at which the measurement is updated
   in the absence of an edge.
   RETURNS NOTES: Error code is channel could not be initialized. Error code that
   can be returned are:
   WARNING      : *This function does not configure the pin, only the eTPU. In a
   system a pin may need to be configured to select the eTPU.
 ******************************************************************************/
int32_t fs_etpu_ppa_p_init( uint8_t channel, uint8_t priority, uint8_t timebase,
  uint8_t mode)
{
  uint32_t *pba;                       /*parameter base address for channel*/
  uint8_t *pba8;                       /*parameter base address for channel*/

  /* disable channel before changing anything else */
  fs_etpu_disable (channel);

  /*only get parameter RAM if the channel has not been used before */
  if (eTPU->CHAN[channel].CR.B.CPBA == 0 ) {
    /* get parameter RAM
       number of parameters passed from eTPU C code */
    pba = fs_etpu_malloc(FS_ETPU_PPA_P_NUM_PARMS);
    if (pba == 0) {
      return (FS_ETPU_ERROR_MALLOC);
    }
  } else                               /*set pba to what is in the CR register*/
  {
    pba= fs_etpu_data_ram(channel);
  }

  pba8= (uint8_t *) pba;

  /*write parameters*/
  eTPU->CHAN[channel].SCR.R = (mode);

  /*write hsr*/
  eTPU->CHAN[channel].HSRR.R = timebase;

  /*write chan config register */
  eTPU->CHAN[channel].CR.R =
    (priority << 28) + (FS_ETPU_PPA_P_TABLE_SELECT << 24) +
    (FS_ETPU_PPA_P_FUNCTION_NUMBER << 16) + (((uint32_t)pba -
    fs_etpu_data_ram_start) >> 3);
  return(0);
}

/***************************************************************************
   FUNCTION     : fs_etpu_ppa_init
   PURPOSE      : To initialize an eTPU channel to generate a ppa output.
   INPUTS NOTES : This function has 5 parameters:
   channel - This is the channel number.
   0-31 for ETPU_A and 64-95 for ETPU_B.
   priority - This is the priority to assign to the channel.
   This parameter should be assigned a value of:
   ETPU_PRIORITY_HIGH, ETPU_PRIORITY_MIDDLE or
   ETPU_PRIORITY_LOW.
   timebase - This is the timer to use as a reference for the ppa
   function. This parameter should be assigned to a
   value of: FS_ETPU_PPA_INIT_TCR1 or
   FS_ETPU_PPA_INIT_TCR2.
   mode - This is the mode to use for PPA measurements. This
   parameter should be assigned a value of:
   FS_ETPU_PPA_LOW_PULSE,
   FS_ETPU_PPA_HIGH_PULSE,
   FS_ETPU_PPA_FALLING_EDGE,
   FS_ETPU_PPA_RISING_EDGE
   max_count - This is the number of periods or pulses that are
   accumulated before the measurement restarts. This
   parameter should be assigned a value in the range
   0 to 255. A value of zero or one results in the
   accumulation of one period or pulse width.
   sample_time - Defines the rate at which the measurement is updated
   in the absence of an edge.
   RETURNS NOTES: Error code is channel could not be initialized. Error code that
   can be returned are:
   WARNING      : *This function does not configure the pin, only the eTPU. In a
   system a pin may need to be configured to select the eTPU.
 ******************************************************************************/
int32_t fs_etpu_ppa_init( uint8_t channel, uint8_t priority, uint8_t timebase,
  uint8_t mode, uint32_t max_count, uint32_t sample_time )
{
  uint32_t *pba;                       /*parameter base address for channel*/
  uint8_t *pba8;                       /*parameter base address for channel*/

  /* disable channel before changing anything else */
  fs_etpu_disable (channel);

  /*only get parameter RAM if the channel has not been used before */
  if (eTPU->CHAN[channel].CR.B.CPBA == 0 ) {
    /* get parameter RAM
       number of parameters passed from eTPU C code */
    pba = fs_etpu_malloc(FS_ETPU_PPA_NUM_PARMS);
    if (pba == 0) {
      return (FS_ETPU_ERROR_MALLOC);
    }
  } else                               /*set pba to what is in the CR register*/
  {
    pba= fs_etpu_data_ram(channel);
  }

  pba8= (uint8_t *) pba;

  /*write parameters*/
  *(pba + ((FS_ETPU_PPA_ACCUM_OFFSET - 1)>>2)) = 0;
  *(pba + ((FS_ETPU_PPA_PERIOD_COUNT_OFFSET - 1)>>2)) = 0;
  *(pba + ((FS_ETPU_PPA_SAMPLE_TIME_OFFSET - 1)>>2)) = sample_time;
  *(pba + ((FS_ETPU_PPA_MAX_COUNT_OFFSET - 1)>>2)) = max_count;
  *(pba8 + FS_ETPU_PPA_STAT_ACC_OFFSET ) = 0;
  eTPU->CHAN[channel].SCR.R = (mode);

  /*write hsr*/
  eTPU->CHAN[channel].HSRR.R = timebase;

  /*write chan config register */
  eTPU->CHAN[channel].CR.R =
    (priority << 28) + (FS_ETPU_PPA_TABLE_SELECT << 24) +
    (FS_ETPU_PPA_FUNCTION_NUMBER << 16) + (((uint32_t)pba -
    fs_etpu_data_ram_start) >> 3);
  return(0);
}

/******************************************************************************
   FUNCTION     : fs_etpu_ppa_get_accumulation
   PURPOSE      : This function call returns the status of the last measurement,
   and passes back the last accumulated pulse widths or accumulated
   periods, in counts of the selected timebase used to initialize
   the function: either TCR1 or TCR2
   INPUTS NOTES : This function has 2 parameters:
   channel - This is the channel number.
   0-31 for ETPU_A and 64-95 for ETPU_B.
 *result - A pointer to where the PPA result will be stored.

   RETURNS NOTES: returns status; if status is non zero the result has overflowed
   WARNING      : *This function does not configure the pin, only the eTPU. In a
   system a pin may need to be configured to select the eTPU.
 ******************************************************************************/
uint32_t fs_etpu_ppa_get_accumulation( uint8_t channel)
{
  uint8_t status;
  uint32_t accum_result;
  uint32_t ec_ppa_result;
  ec_ppa_result = fs_etpu_get_chan_local_24(channel, FS_ETPU_PPA_RESULT_OFFSET);
  accum_result = fs_etpu_get_chan_local_24(channel, FS_ETPU_PPA_ACCUM_OFFSET);
  if (accum_result>2*(ec_ppa_result)) {
    fs_etpu_set_chan_local_24(channel,FS_ETPU_PPA_RESULT_OFFSET,0);
    status = 1;
  } else {
    status = 0;
  }

  if (ec_ppa_result > 25000) {
    return (0);
  } else {
    return (ec_ppa_result);
  }
}

/******************************************************************************
   FUNCTION     : fs_etpu_ppa_get_immediate
   PURPOSE      : This function call returns the status of the last measurement,
   and passes back the last accumulated pulse widths or accumulated
   periods, in counts of the selected timebase used to initialize
   the function: either TCR1 or TCR2
   INPUTS NOTES : This function has 2 parameters:
   channel - This is the channel number.
   0-31 for ETPU_A and 64-95 for ETPU_B.
 *result - A pointer to where the PPA result will be stored.
 *current_count - a pointer to where the current elapsed number
   of periods or pulse widths will be stored.
   RETURNS NOTES: returns stat_acc; if stat_acc is non zero the result has overflowed
   WARNING      : *This function does not configure the pin, only the eTPU. In a
   system a pin may need to be configured to select the eTPU.
 ******************************************************************************/
uint8_t fs_etpu_ppa_get_immediate( uint8_t channel, uint32_t *result, uint32_t
  *current_count )
{
  uint32_t *pba;                       /*parameter base address for channel*/
  uint8_t *pba8;
  uint8_t stat_acc;
  pba= fs_etpu_data_ram(channel);
  pba8= (uint8_t *) pba;
  *result = *(pba + ((FS_ETPU_PPA_ACCUM_OFFSET - 1)>>2)) & 0x00FFFFFF;
  *current_count= *(pba + ((FS_ETPU_PPA_PERIOD_COUNT_OFFSET - 1)>>2));
  stat_acc = *(pba8 + FS_ETPU_PPA_STAT_ACC_OFFSET );
  return (stat_acc);
}

/******************************************************************************
   FUNCTION     : ec_etpu_get_ppa_freq
   PURPOSE      : This function call returns the frequency result,
   and passes back the last accumulated
   periods, in counts of the selected timebase used to initialize
   the function: either TCR1 or TCR2
   INPUTS NOTES : This function has 1 parameters:
   channel - This is the channel number.
   0-31 for ETPU_A and 64-95 for ETPU_B.
   RETURNS NOTES: returns ec_etpu_ppa_freq;
   WARNING      : This function does not configure the pin, only the eTPU. In a
   system a pin may need to be configured to select the eTPU.
 ******************************************************************************/
uint32_t ec_etpu_get_ppa_freq(uint8_t channel)
{
  uint32_t ec_etpu_ppa_freq;
  ec_etpu_ppa_freq = fs_etpu_get_chan_local_24(channel,
    FS_ETPU_PPA_P_EC_PPA_PERIOD_OFFSET);
  ec_etpu_ppa_freq = 1000000/ec_etpu_ppa_freq;
  return ec_etpu_ppa_freq;
}

#endif

/* File trailer for ECUCoder generated file etpu_ppa.c.
 *
 * [EOF]
 */
