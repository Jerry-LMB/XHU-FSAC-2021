/* Include files */

#include "FSAC2021_sfun.h"
#include "FSAC2021_sfun_debug_macros.h"
#include "c2_FSAC2021.h"
#include "c3_FSAC2021.h"
#include "c4_FSAC2021.h"
#include "c5_FSAC2021.h"
#include "c6_FSAC2021.h"
#include "c7_FSAC2021.h"
#include "c8_FSAC2021.h"
#include "c9_FSAC2021.h"
#include "c10_FSAC2021.h"
#include "c11_FSAC2021.h"
#include "c12_FSAC2021.h"
#include "c13_FSAC2021.h"
#include "c14_FSAC2021.h"
#include "c15_FSAC2021.h"
#include "c16_FSAC2021.h"
#include "c17_FSAC2021.h"
#include "c18_FSAC2021.h"
#include "c19_FSAC2021.h"
#include "c20_FSAC2021.h"
#include "c21_FSAC2021.h"
#include "c22_FSAC2021.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _FSAC2021MachineNumber_;

/* Function Declarations */

/* Function Definitions */
void FSAC2021_initializer(void)
{
}

void FSAC2021_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_FSAC2021_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_FSAC2021_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_FSAC2021_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2994998167U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2990984301U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2823819254U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(220701144U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1311945562U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4156639972U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3272187444U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4265985740U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c2_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c3_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c4_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c5_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c6_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c7_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c8_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c9_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c10_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c11_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c12_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c13_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c14_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c15_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c16_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c17_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c18_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c19_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c20_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c21_FSAC2021_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_FSAC2021_get_check_sum(mxArray *plhs[]);
          sf_c22_FSAC2021_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2020127832U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2875675789U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(967944156U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3601629534U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2544937467U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2888261003U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3968821736U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(695197194U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_FSAC2021_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(aiChksum, "JlIZvTgRIdDHqIDzRhzFsH") == 0) {
          extern mxArray *sf_c2_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c2_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "pGuZfgrfpJIYPMrfpYo9CD") == 0) {
          extern mxArray *sf_c3_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c3_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "zeMgJag8A98EvvLNgRNr0D") == 0) {
          extern mxArray *sf_c4_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c4_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "SLGA9H6DXUzrVEBZg6Wv9G") == 0) {
          extern mxArray *sf_c5_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c5_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "1ReNGHeUGL9IdCn9rC8caC") == 0) {
          extern mxArray *sf_c6_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c6_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "YNqDptjskEoTby5w7dXfzD") == 0) {
          extern mxArray *sf_c7_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c7_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "vUOgDv1e48JpUl3q1jt0cG") == 0) {
          extern mxArray *sf_c8_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c8_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "kzZm0YXV2TTdt317STsvjD") == 0) {
          extern mxArray *sf_c9_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c9_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "1ReNGHeUGL9IdCn9rC8caC") == 0) {
          extern mxArray *sf_c10_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c10_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "1ReNGHeUGL9IdCn9rC8caC") == 0) {
          extern mxArray *sf_c11_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c11_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "XfAra0mqLx4L7D9GTKMUJF") == 0) {
          extern mxArray *sf_c12_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c12_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "DSFaNirOrgxguCdKDYcmWH") == 0) {
          extern mxArray *sf_c13_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c13_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "YO1ENp4gJoE9OjnrnE86fH") == 0) {
          extern mxArray *sf_c14_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c14_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "2ZXH1t66nvRSsgszLXdg6C") == 0) {
          extern mxArray *sf_c15_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c15_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "2ZXH1t66nvRSsgszLXdg6C") == 0) {
          extern mxArray *sf_c16_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c16_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "2ZXH1t66nvRSsgszLXdg6C") == 0) {
          extern mxArray *sf_c17_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c17_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "2ZXH1t66nvRSsgszLXdg6C") == 0) {
          extern mxArray *sf_c18_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c18_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "2ZXH1t66nvRSsgszLXdg6C") == 0) {
          extern mxArray *sf_c19_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c19_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "1ReNGHeUGL9IdCn9rC8caC") == 0) {
          extern mxArray *sf_c20_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c20_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "1ReNGHeUGL9IdCn9rC8caC") == 0) {
          extern mxArray *sf_c21_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c21_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "mKB5bNzSs5apYeQkXXX8KF") == 0) {
          extern mxArray *sf_c22_FSAC2021_get_autoinheritance_info(void);
          plhs[0] = sf_c22_FSAC2021_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_FSAC2021_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern const mxArray *sf_c2_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray *sf_c16_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray *sf_c17_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray *sf_c18_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray *sf_c19_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray *sf_c20_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray *sf_c21_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray *sf_c22_FSAC2021_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_FSAC2021_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_FSAC2021_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "O1ktSB9SXC4Xynft1iF3yD") == 0) {
          extern mxArray *sf_c2_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c2_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "iWubGBYXT52J3C4cLodxvB") == 0) {
          extern mxArray *sf_c3_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c3_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "0IGwR9FQ0ZPZ8XefFRL3iG") == 0) {
          extern mxArray *sf_c4_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c4_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "D6VQY3A9CHdYsC7WZTZy5") == 0) {
          extern mxArray *sf_c5_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c5_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "5TaKXVZMXHAVXfL3a1vRTG") == 0) {
          extern mxArray *sf_c6_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c6_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "Gru7f7aEvM6W08JY4ItTQB") == 0) {
          extern mxArray *sf_c7_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c7_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "GolpyT5se4FAc5g7OYMdlE") == 0) {
          extern mxArray *sf_c8_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c8_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "P6SuNemEPfyYsgT190PObG") == 0) {
          extern mxArray *sf_c9_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c9_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "5TaKXVZMXHAVXfL3a1vRTG") == 0) {
          extern mxArray *sf_c10_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c10_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "5TaKXVZMXHAVXfL3a1vRTG") == 0) {
          extern mxArray *sf_c11_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c11_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "MrCCAhE56lGEfErbGDUSXB") == 0) {
          extern mxArray *sf_c12_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c12_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "oRm7tqBreQg8m7iMyAC33F") == 0) {
          extern mxArray *sf_c13_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c13_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "hpds2ukzApV05LBxQq6wlG") == 0) {
          extern mxArray *sf_c14_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c14_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "oX1LV5YRVpM59C5TKqiu7B") == 0) {
          extern mxArray *sf_c15_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c15_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "oX1LV5YRVpM59C5TKqiu7B") == 0) {
          extern mxArray *sf_c16_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c16_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "oX1LV5YRVpM59C5TKqiu7B") == 0) {
          extern mxArray *sf_c17_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c17_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "oX1LV5YRVpM59C5TKqiu7B") == 0) {
          extern mxArray *sf_c18_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c18_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "oX1LV5YRVpM59C5TKqiu7B") == 0) {
          extern mxArray *sf_c19_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c19_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "5TaKXVZMXHAVXfL3a1vRTG") == 0) {
          extern mxArray *sf_c20_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c20_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "5TaKXVZMXHAVXfL3a1vRTG") == 0) {
          extern mxArray *sf_c21_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c21_FSAC2021_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "LNXSeAJLsAyxPauR01AHXC") == 0) {
          extern mxArray *sf_c22_FSAC2021_third_party_uses_info(void);
          plhs[0] = sf_c22_FSAC2021_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_FSAC2021_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "O1ktSB9SXC4Xynft1iF3yD") == 0) {
          extern mxArray *sf_c2_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "iWubGBYXT52J3C4cLodxvB") == 0) {
          extern mxArray *sf_c3_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "0IGwR9FQ0ZPZ8XefFRL3iG") == 0) {
          extern mxArray *sf_c4_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "D6VQY3A9CHdYsC7WZTZy5") == 0) {
          extern mxArray *sf_c5_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "5TaKXVZMXHAVXfL3a1vRTG") == 0) {
          extern mxArray *sf_c6_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "Gru7f7aEvM6W08JY4ItTQB") == 0) {
          extern mxArray *sf_c7_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "GolpyT5se4FAc5g7OYMdlE") == 0) {
          extern mxArray *sf_c8_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "P6SuNemEPfyYsgT190PObG") == 0) {
          extern mxArray *sf_c9_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "5TaKXVZMXHAVXfL3a1vRTG") == 0) {
          extern mxArray *sf_c10_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "5TaKXVZMXHAVXfL3a1vRTG") == 0) {
          extern mxArray *sf_c11_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "MrCCAhE56lGEfErbGDUSXB") == 0) {
          extern mxArray *sf_c12_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "oRm7tqBreQg8m7iMyAC33F") == 0) {
          extern mxArray *sf_c13_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "hpds2ukzApV05LBxQq6wlG") == 0) {
          extern mxArray *sf_c14_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "oX1LV5YRVpM59C5TKqiu7B") == 0) {
          extern mxArray *sf_c15_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "oX1LV5YRVpM59C5TKqiu7B") == 0) {
          extern mxArray *sf_c16_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "oX1LV5YRVpM59C5TKqiu7B") == 0) {
          extern mxArray *sf_c17_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "oX1LV5YRVpM59C5TKqiu7B") == 0) {
          extern mxArray *sf_c18_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c18_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "oX1LV5YRVpM59C5TKqiu7B") == 0) {
          extern mxArray *sf_c19_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c19_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "5TaKXVZMXHAVXfL3a1vRTG") == 0) {
          extern mxArray *sf_c20_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "5TaKXVZMXHAVXfL3a1vRTG") == 0) {
          extern mxArray *sf_c21_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "LNXSeAJLsAyxPauR01AHXC") == 0) {
          extern mxArray *sf_c22_FSAC2021_updateBuildInfo_args_info(void);
          plhs[0] = sf_c22_FSAC2021_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void FSAC2021_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _FSAC2021MachineNumber_ = sf_debug_initialize_machine(debugInstance,"FSAC2021",
    "sfun",0,21,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_FSAC2021MachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_FSAC2021MachineNumber_,0);
}

void FSAC2021_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_FSAC2021_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("FSAC2021",
      "FSAC2021");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_FSAC2021_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
