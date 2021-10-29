//
// File: Controller_MPC.cpp
//
// Code generated for Simulink model 'Controller_MPC'.
//
// Model version                  : 4.36
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Wed Jul 28 14:48:34 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Controller_MPC.h"
#include "Controller_MPC_private.h"

// Block signals (default storage)
B_Controller_MPC_T Controller_MPC_B;

// Block states (default storage)
DW_Controller_MPC_T Controller_MPC_DW;

// Real-time model
RT_MODEL_Controller_MPC_T Controller_MPC_M_ = RT_MODEL_Controller_MPC_T();
RT_MODEL_Controller_MPC_T *const Controller_MPC_M = &Controller_MPC_M_;

// Forward declaration for local functions
static void Controller_MPC_SystemCore_step(boolean_T *varargout_1,
  SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension varargout_2_Layout_Dim[16],
  uint32_T *varargout_2_Layout_Dim_SL_Info_, uint32_T
  *varargout_2_Layout_Dim_SL_Inf_0, uint32_T *varargout_2_Layout_DataOffset,
  real32_T varargout_2_Data[2004], uint32_T *varargout_2_Data_SL_Info_Curren,
  uint32_T *varargout_2_Data_SL_Info_Receiv);
static void Controller_MPC_SystemCore_step(boolean_T *varargout_1,
  SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension varargout_2_Layout_Dim[16],
  uint32_T *varargout_2_Layout_Dim_SL_Info_, uint32_T
  *varargout_2_Layout_Dim_SL_Inf_0, uint32_T *varargout_2_Layout_DataOffset,
  real32_T varargout_2_Data[2004], uint32_T *varargout_2_Data_SL_Info_Curren,
  uint32_T *varargout_2_Data_SL_Info_Receiv)
{
  *varargout_1 = Sub_Controller_MPC_3052.getLatestMessage
    (&Controller_MPC_B.b_varargout_2);
  memcpy(&varargout_2_Layout_Dim[0], &Controller_MPC_B.b_varargout_2.Layout.Dim
         [0], sizeof(SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension) << 4U);
  *varargout_2_Layout_Dim_SL_Info_ =
    Controller_MPC_B.b_varargout_2.Layout.Dim_SL_Info.CurrentLength;
  *varargout_2_Layout_Dim_SL_Inf_0 =
    Controller_MPC_B.b_varargout_2.Layout.Dim_SL_Info.ReceivedLength;
  *varargout_2_Layout_DataOffset =
    Controller_MPC_B.b_varargout_2.Layout.DataOffset;
  memcpy(&varargout_2_Data[0], &Controller_MPC_B.b_varargout_2.Data[0], 2004U *
         sizeof(real32_T));
  *varargout_2_Data_SL_Info_Curren =
    Controller_MPC_B.b_varargout_2.Data_SL_Info.CurrentLength;
  *varargout_2_Data_SL_Info_Receiv =
    Controller_MPC_B.b_varargout_2.Data_SL_Info.ReceivedLength;
}

// Model step function
void Controller_MPC_step(void)
{
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // MATLABSystem: '<S2>/SourceBlock' incorporates:
  //   Inport: '<S4>/In1'

  Controller_MPC_SystemCore_step(&b_varargout_1,
    Controller_MPC_B.b_varargout_2_Layout_Dim,
    &Controller_MPC_B.b_varargout_2_Layout_Dim_SL_Inf,
    &Controller_MPC_B.b_varargout_2_Layout_Dim_SL_I_g,
    &Controller_MPC_B.b_varargout_2_Layout_DataOffset,
    Controller_MPC_B.b_varargout_2_Data,
    &Controller_MPC_B.b_varargout_2_Data_SL_Info_Curr,
    &Controller_MPC_B.b_varargout_2_Data_SL_Info_Rece);

  // Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S4>/Enable'

  if (b_varargout_1) {
    memcpy(&Controller_MPC_B.In1.Layout.Dim[0],
           &Controller_MPC_B.b_varargout_2_Layout_Dim[0], sizeof
           (SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension) << 4U);
    Controller_MPC_B.In1.Layout.Dim_SL_Info.CurrentLength =
      Controller_MPC_B.b_varargout_2_Layout_Dim_SL_Inf;
    Controller_MPC_B.In1.Layout.Dim_SL_Info.ReceivedLength =
      Controller_MPC_B.b_varargout_2_Layout_Dim_SL_I_g;
    Controller_MPC_B.In1.Layout.DataOffset =
      Controller_MPC_B.b_varargout_2_Layout_DataOffset;
    memcpy(&Controller_MPC_B.In1.Data[0], &Controller_MPC_B.b_varargout_2_Data[0],
           2004U * sizeof(real32_T));
    Controller_MPC_B.In1.Data_SL_Info.CurrentLength =
      Controller_MPC_B.b_varargout_2_Data_SL_Info_Curr;
    Controller_MPC_B.In1.Data_SL_Info.ReceivedLength =
      Controller_MPC_B.b_varargout_2_Data_SL_Info_Rece;
  }

  // End of Outputs for SubSystem: '<S2>/Enabled Subsystem'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Inport: '<S58>/In1'
  //   Inport: '<S59>/In1'
  //   MATLABSystem: '<S11>/SourceBlock'
  //   MATLABSystem: '<S12>/SourceBlock'
  //   MATLABSystem: '<S2>/SourceBlock'

  if (b_varargout_1 && (Controller_MPC_DW.flag == 0.0)) {
    Controller_MPC_DW.enable_flag = 1.0;
    Controller_MPC_DW.flag = 1.0;
  }

  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S3>/Enable'

  if (Controller_MPC_DW.enable_flag > 0.0) {
    // MATLAB Function: '<S3>/MATLAB Function'
    for (Controller_MPC_B.i = 0; Controller_MPC_B.i < 501; Controller_MPC_B.i++)
    {
      Controller_MPC_B.xr[Controller_MPC_B.i] =
        Controller_MPC_B.In1.Data[Controller_MPC_B.i];
      Controller_MPC_B.yr[Controller_MPC_B.i] =
        Controller_MPC_B.In1.Data[Controller_MPC_B.i + 501];
      Controller_MPC_B.thetar[Controller_MPC_B.i] =
        Controller_MPC_B.In1.Data[Controller_MPC_B.i + 1002];
      Controller_MPC_B.kappar[Controller_MPC_B.i] =
        Controller_MPC_B.In1.Data[Controller_MPC_B.i + 1503];
    }

    // End of MATLAB Function: '<S3>/MATLAB Function'

    // Outputs for Atomic SubSystem: '<S3>/Subscribe'
    // MATLABSystem: '<S11>/SourceBlock'
    b_varargout_1 = Sub_Controller_MPC_2055.getLatestMessage
      (&Controller_MPC_B.b_varargout_2_c);

    // Outputs for Enabled SubSystem: '<S11>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S58>/Enable'

    if (b_varargout_1) {
      Controller_MPC_B.In1_l = Controller_MPC_B.b_varargout_2_c;
    }

    // End of Outputs for SubSystem: '<S11>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S3>/Subscribe'

    // Gain: '<S6>/Gain1' incorporates:
    //   Inport: '<S58>/In1'
    //   MATLABSystem: '<S11>/SourceBlock'

    Controller_MPC_B.Gain1 = Controller_MPC_P.Gain1_Gain *
      Controller_MPC_B.In1_l.Theta;

    // Outputs for Atomic SubSystem: '<S3>/Subscribe1'
    // MATLABSystem: '<S12>/SourceBlock'
    b_varargout_1 = Sub_Controller_MPC_2057.getLatestMessage
      (&Controller_MPC_B.b_varargout_2_m);

    // Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S59>/Enable'

    if (b_varargout_1) {
      Controller_MPC_B.In1_h = Controller_MPC_B.b_varargout_2_m;
    }

    // End of Outputs for SubSystem: '<S12>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S3>/Subscribe1'

    // MATLAB Function: '<S8>/MATLAB Function' incorporates:
    //   Inport: '<S59>/In1'
    //   MATLABSystem: '<S12>/SourceBlock'

    Controller_MPC_B.d_err_idx_0 = 1.4 * cos(Controller_MPC_B.Gain1) +
      Controller_MPC_B.In1_l.X;
    Controller_MPC_B.y = 1.4 * sin(Controller_MPC_B.Gain1) +
      Controller_MPC_B.In1_l.Y;
    Controller_MPC_B.dmin = 0;
    Controller_MPC_B.d_min_last = 1.0;
    for (Controller_MPC_B.i = 0; Controller_MPC_B.i < 501; Controller_MPC_B.i++)
    {
      Controller_MPC_B.d_min = Controller_MPC_B.d_err_idx_0 -
        Controller_MPC_B.xr[Controller_MPC_B.i];
      Controller_MPC_B.b_a = Controller_MPC_B.y -
        Controller_MPC_B.yr[Controller_MPC_B.i];
      Controller_MPC_B.d_min = Controller_MPC_B.d_min * Controller_MPC_B.d_min +
        Controller_MPC_B.b_a * Controller_MPC_B.b_a;
      if (Controller_MPC_B.d_min < Controller_MPC_B.d_min_last) {
        Controller_MPC_B.dmin = Controller_MPC_B.i;
        Controller_MPC_B.d_min_last = Controller_MPC_B.d_min;
      }
    }

    Controller_MPC_B.d_err_idx_0 -= Controller_MPC_B.xr[Controller_MPC_B.dmin];
    Controller_MPC_B.d_min_last = Controller_MPC_B.y -
      Controller_MPC_B.yr[Controller_MPC_B.dmin];
    Controller_MPC_B.d_min = cos(Controller_MPC_B.thetar[Controller_MPC_B.dmin]);
    Controller_MPC_B.b_a = sin(Controller_MPC_B.thetar[Controller_MPC_B.dmin]);
    Controller_MPC_B.y = -Controller_MPC_B.b_a * Controller_MPC_B.d_err_idx_0 +
      Controller_MPC_B.d_min * Controller_MPC_B.d_min_last;
    Controller_MPC_B.d_err_idx_0 = Controller_MPC_B.Gain1 -
      ((Controller_MPC_B.d_min * Controller_MPC_B.d_err_idx_0 +
        Controller_MPC_B.b_a * Controller_MPC_B.d_min_last) *
       Controller_MPC_B.kappar[Controller_MPC_B.dmin] +
       Controller_MPC_B.thetar[Controller_MPC_B.dmin]);
    Controller_MPC_B.Gain1 = sin(Controller_MPC_B.d_err_idx_0);

    // Saturate: '<S8>/Saturation'
    if (Controller_MPC_B.In1_h.Linear.X > Controller_MPC_P.Saturation_UpperSat)
    {
      Controller_MPC_B.d_min_last = Controller_MPC_P.Saturation_UpperSat;
    } else if (Controller_MPC_B.In1_h.Linear.X <
               Controller_MPC_P.Saturation_LowerSat) {
      Controller_MPC_B.d_min_last = Controller_MPC_P.Saturation_LowerSat;
    } else {
      Controller_MPC_B.d_min_last = Controller_MPC_B.In1_h.Linear.X;
    }

    // End of Saturate: '<S8>/Saturation'

    // MATLAB Function: '<S8>/MATLAB Function'
    Controller_MPC_B.d_err_idx_0 = (cos(Controller_MPC_B.d_err_idx_0) *
      Controller_MPC_B.d_min_last - Controller_MPC_B.In1_h.Linear.Y *
      Controller_MPC_B.Gain1) / (1.0 -
      Controller_MPC_B.kappar[Controller_MPC_B.dmin] * Controller_MPC_B.y);

    // Saturate: '<S8>/Saturation1'
    if (Controller_MPC_B.d_err_idx_0 > Controller_MPC_P.Saturation1_UpperSat) {
      // DataTypeConversion: '<S8>/Data Type Conversion2'
      Controller_MPC_B.rtb_DataTypeConversion2_c = static_cast<real32_T>
        (Controller_MPC_P.Saturation1_UpperSat);
    } else if (Controller_MPC_B.d_err_idx_0 <
               Controller_MPC_P.Saturation1_LowerSat) {
      // DataTypeConversion: '<S8>/Data Type Conversion2'
      Controller_MPC_B.rtb_DataTypeConversion2_c = static_cast<real32_T>
        (Controller_MPC_P.Saturation1_LowerSat);
    } else {
      // DataTypeConversion: '<S8>/Data Type Conversion2'
      Controller_MPC_B.rtb_DataTypeConversion2_c = static_cast<real32_T>
        (Controller_MPC_B.d_err_idx_0);
    }

    // End of Saturate: '<S8>/Saturation1'

    // DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
    //   MATLAB Function: '<S8>/MATLAB Function'

    Controller_MPC_B.rtb_DataTypeConversion1_p = static_cast<real32_T>
      (Controller_MPC_B.kappar[Controller_MPC_B.dmin]);

    // DataTypeConversion: '<S8>/Data Type Conversion3' incorporates:
    //   MATLAB Function: '<S8>/MATLAB Function'

    Controller_MPC_B.rtb_DataTypeConversion3_b = static_cast<real32_T>
      (Controller_MPC_B.y);

    // DataTypeConversion: '<S8>/Data Type Conversion4'
    Controller_MPC_B.rtb_DataTypeConversion4_c = static_cast<real32_T>
      (Controller_MPC_B.Gain1);

    // Outputs for Atomic SubSystem: '<S8>/Path Following Control System'
    // Outputs for Atomic SubSystem: '<S8>/Path Following Control System'
    Cont_PathFollowingControlSystem(0.0F,
      Controller_MPC_B.rtb_DataTypeConversion2_c,
      Controller_MPC_B.rtb_DataTypeConversion1_p,
      Controller_MPC_B.rtb_DataTypeConversion3_b,
      Controller_MPC_B.rtb_DataTypeConversion4_c, Controller_MPC_B.rtb_u_scale_k,
      &Controller_MPC_B.PathFollowingControlSystem,
      &Controller_MPC_DW.PathFollowingControlSystem,
      &Controller_MPC_P.PathFollowingControlSystem,
      Controller_MPC_P.PathFollowingControlSystem_MinA,
      Controller_MPC_P.PathFollowingControlSystem_MinS,
      Controller_MPC_P.PathFollowingControlSystem_MaxA,
      Controller_MPC_P.PathFollowingControlSystem_MaxS);

    // End of Outputs for SubSystem: '<S8>/Path Following Control System'
    // End of Outputs for SubSystem: '<S8>/Path Following Control System'

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   Constant: '<S3>/Constant4'
    //   Constant: '<S5>/Constant'

    Controller_MPC_B.BusAssignment = Controller_MPC_P.Constant_Value_d;
    Controller_MPC_B.BusAssignment.Data_SL_Info.ReceivedLength =
      Controller_MPC_P.Constant4_Value;
    Controller_MPC_B.BusAssignment.Data_SL_Info.CurrentLength =
      Controller_MPC_P.Constant4_Value;

    // DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
    //   Constant: '<S3>/ID'

    Controller_MPC_B.d_min_last = floor(Controller_MPC_P.ID_Value);
    if (rtIsNaN(Controller_MPC_B.d_min_last) || rtIsInf
        (Controller_MPC_B.d_min_last)) {
      Controller_MPC_B.d_min_last = 0.0;
    } else {
      Controller_MPC_B.d_min_last = fmod(Controller_MPC_B.d_min_last, 65536.0);
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'

    Controller_MPC_B.BusAssignment.Data[0] = static_cast<int16_T>
      (Controller_MPC_B.d_min_last < 0.0 ? static_cast<int32_T>
       (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-Controller_MPC_B.d_min_last)))) : static_cast<int32_T>
       (static_cast<int16_T>(static_cast<uint16_T>(Controller_MPC_B.d_min_last))));

    // DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
    //   Constant: '<S3>/DataLen'

    Controller_MPC_B.d_min_last = floor(Controller_MPC_P.DataLen_Value);
    if (rtIsNaN(Controller_MPC_B.d_min_last) || rtIsInf
        (Controller_MPC_B.d_min_last)) {
      Controller_MPC_B.d_min_last = 0.0;
    } else {
      Controller_MPC_B.d_min_last = fmod(Controller_MPC_B.d_min_last, 65536.0);
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'

    Controller_MPC_B.BusAssignment.Data[1] = static_cast<int16_T>
      (Controller_MPC_B.d_min_last < 0.0 ? static_cast<int32_T>
       (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-Controller_MPC_B.d_min_last)))) : static_cast<int32_T>
       (static_cast<int16_T>(static_cast<uint16_T>(Controller_MPC_B.d_min_last))));

    // DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
    //   Constant: '<S3>/SPD'

    Controller_MPC_B.d_min_last = floor(Controller_MPC_P.SPD_Value);
    if (rtIsNaN(Controller_MPC_B.d_min_last) || rtIsInf
        (Controller_MPC_B.d_min_last)) {
      Controller_MPC_B.d_min_last = 0.0;
    } else {
      Controller_MPC_B.d_min_last = fmod(Controller_MPC_B.d_min_last, 65536.0);
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'

    Controller_MPC_B.BusAssignment.Data[2] = static_cast<int16_T>
      (Controller_MPC_B.d_min_last < 0.0 ? static_cast<int32_T>
       (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-Controller_MPC_B.d_min_last)))) : static_cast<int32_T>
       (static_cast<int16_T>(static_cast<uint16_T>(Controller_MPC_B.d_min_last))));

    // DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
    //   Constant: '<S3>/SPD1'
    //   DataTypeConversion: '<S8>/Data Type Conversion'
    //   Gain: '<S10>/Gain'
    //   Sum: '<S3>/Add'

    Controller_MPC_B.d_min_last = floor(Controller_MPC_P.Gain_Gain *
      Controller_MPC_B.rtb_u_scale_k[1] + Controller_MPC_P.SPD1_Value);
    if (rtIsNaN(Controller_MPC_B.d_min_last) || rtIsInf
        (Controller_MPC_B.d_min_last)) {
      Controller_MPC_B.d_min_last = 0.0;
    } else {
      Controller_MPC_B.d_min_last = fmod(Controller_MPC_B.d_min_last, 65536.0);
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'

    Controller_MPC_B.BusAssignment.Data[3] = static_cast<int16_T>
      (Controller_MPC_B.d_min_last < 0.0 ? static_cast<int32_T>
       (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-Controller_MPC_B.d_min_last)))) : static_cast<int32_T>
       (static_cast<int16_T>(static_cast<uint16_T>(Controller_MPC_B.d_min_last))));

    // DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
    //   Constant: '<S3>/Brk'

    Controller_MPC_B.d_min_last = floor(Controller_MPC_P.Brk_Value);
    if (rtIsNaN(Controller_MPC_B.d_min_last) || rtIsInf
        (Controller_MPC_B.d_min_last)) {
      Controller_MPC_B.d_min_last = 0.0;
    } else {
      Controller_MPC_B.d_min_last = fmod(Controller_MPC_B.d_min_last, 65536.0);
    }

    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'

    Controller_MPC_B.BusAssignment.Data[4] = static_cast<int16_T>
      (Controller_MPC_B.d_min_last < 0.0 ? static_cast<int32_T>
       (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-Controller_MPC_B.d_min_last)))) : static_cast<int32_T>
       (static_cast<int16_T>(static_cast<uint16_T>(Controller_MPC_B.d_min_last))));

    // Outputs for Atomic SubSystem: '<S3>/Publish'
    // MATLABSystem: '<S9>/SinkBlock'
    Pub_Controller_MPC_2063.publish(&Controller_MPC_B.BusAssignment);

    // End of Outputs for SubSystem: '<S3>/Publish'
  }

  // End of MATLAB Function: '<Root>/MATLAB Function'
  // End of Outputs for SubSystem: '<Root>/Subsystem1'
}

// Model initialize function
void Controller_MPC_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  Controller_MPC_P.Saturation_UpperSat = rtInf;
  Controller_MPC_P.Saturation1_UpperSat = rtInf;

  // block I/O
  (void) memset((static_cast<void *>(&Controller_MPC_B)), 0,
                sizeof(B_Controller_MPC_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&Controller_MPC_DW), 0,
                sizeof(DW_Controller_MPC_T));

  {
    static const char_T tmp_0[28] = { '/', 'c', 'a', 'n', 'a', 'l', 'y', 's',
      't', 'i', 'i', '_', 'r', 'o', 's', '/', 'v', 'e', 'h', 'i', 'c', 'l', 'e',
      '_', 'P', 'o', 's', 'e' };

    static const char_T tmp_1[27] = { '/', 'c', 'a', 'n', 'a', 'l', 'y', 's',
      't', 'i', 'i', '_', 'r', 'o', 's', '/', 'v', 'e', 'h', 'i', 'c', 'l', 'e',
      '_', 's', 'p', 'd' };

    static const char_T tmp[20] = { '/', 'P', 'l', 'a', 'n', 'n', 'i', 'n', 'g',
      '_', 'T', 'r', 'a', 'j', 'e', 'c', 't', 'o', 'r', 'y' };

    static const char_T tmp_2[20] = { '/', 's', 'e', 'n', 'd', '_', 'c', 'a',
      'n', '_', 'm', 's', 'g', 's', '_', 'p', 'o', 'r', 't', '1' };

    int32_T i;
    char_T b_zeroDelimTopic[28];
    char_T b_zeroDelimTopic_0[21];

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S2>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S4>/Out1' incorporates:
    //   Inport: '<S4>/In1'

    Controller_MPC_B.In1 = Controller_MPC_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S2>/Enabled Subsystem'

    // Start for MATLABSystem: '<S2>/SourceBlock'
    Controller_MPC_DW.obj_o.matlabCodegenIsDeleted = false;
    Controller_MPC_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 20; i++) {
      b_zeroDelimTopic_0[i] = tmp[i];
    }

    b_zeroDelimTopic_0[20] = '\x00';
    Sub_Controller_MPC_3052.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    Controller_MPC_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function'
    Controller_MPC_DW.flag = 0.0;
    Controller_MPC_DW.enable_flag = 0.0;

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1'
    // SystemInitialize for Atomic SubSystem: '<S3>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S11>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S58>/Out1' incorporates:
    //   Inport: '<S58>/In1'

    Controller_MPC_B.In1_l = Controller_MPC_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S11>/Enabled Subsystem'

    // Start for MATLABSystem: '<S11>/SourceBlock'
    Controller_MPC_DW.obj_p.matlabCodegenIsDeleted = false;
    Controller_MPC_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 28; i++) {
      Controller_MPC_B.b_zeroDelimTopic[i] = tmp_0[i];
    }

    Controller_MPC_B.b_zeroDelimTopic[28] = '\x00';
    Sub_Controller_MPC_2055.createSubscriber(&Controller_MPC_B.b_zeroDelimTopic
      [0], 1);
    Controller_MPC_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S3>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<S3>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S12>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S59>/Out1' incorporates:
    //   Inport: '<S59>/In1'

    Controller_MPC_B.In1_h = Controller_MPC_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S12>/Enabled Subsystem'

    // Start for MATLABSystem: '<S12>/SourceBlock'
    Controller_MPC_DW.obj.matlabCodegenIsDeleted = false;
    Controller_MPC_DW.obj.isInitialized = 1;
    for (i = 0; i < 27; i++) {
      b_zeroDelimTopic[i] = tmp_1[i];
    }

    b_zeroDelimTopic[27] = '\x00';
    Sub_Controller_MPC_2057.createSubscriber(&b_zeroDelimTopic[0], 1);
    Controller_MPC_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S12>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S3>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<S8>/Path Following Control System' 
    PathFollowingControlSystem_Init
      (&Controller_MPC_DW.PathFollowingControlSystem,
       &Controller_MPC_P.PathFollowingControlSystem);

    // End of SystemInitialize for SubSystem: '<S8>/Path Following Control System' 

    // SystemInitialize for Atomic SubSystem: '<S3>/Publish'
    // Start for MATLABSystem: '<S9>/SinkBlock'
    Controller_MPC_DW.obj_a.matlabCodegenIsDeleted = false;
    Controller_MPC_DW.obj_a.isInitialized = 1;
    for (i = 0; i < 20; i++) {
      b_zeroDelimTopic_0[i] = tmp_2[i];
    }

    b_zeroDelimTopic_0[20] = '\x00';
    Pub_Controller_MPC_2063.createPublisher(&b_zeroDelimTopic_0[0], 1);
    Controller_MPC_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S3>/Publish'
    // End of SystemInitialize for SubSystem: '<Root>/Subsystem1'
  }
}

// Model terminate function
void Controller_MPC_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S2>/SourceBlock'
  if (!Controller_MPC_DW.obj_o.matlabCodegenIsDeleted) {
    Controller_MPC_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Enabled SubSystem: '<Root>/Subsystem1'
  // Terminate for Atomic SubSystem: '<S3>/Subscribe'
  // Terminate for MATLABSystem: '<S11>/SourceBlock'
  if (!Controller_MPC_DW.obj_p.matlabCodegenIsDeleted) {
    Controller_MPC_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/SourceBlock'
  // End of Terminate for SubSystem: '<S3>/Subscribe'

  // Terminate for Atomic SubSystem: '<S3>/Subscribe1'
  // Terminate for MATLABSystem: '<S12>/SourceBlock'
  if (!Controller_MPC_DW.obj.matlabCodegenIsDeleted) {
    Controller_MPC_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/SourceBlock'
  // End of Terminate for SubSystem: '<S3>/Subscribe1'

  // Terminate for Atomic SubSystem: '<S3>/Publish'
  // Terminate for MATLABSystem: '<S9>/SinkBlock'
  if (!Controller_MPC_DW.obj_a.matlabCodegenIsDeleted) {
    Controller_MPC_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SinkBlock'
  // End of Terminate for SubSystem: '<S3>/Publish'
  // End of Terminate for SubSystem: '<Root>/Subsystem1'
}

//
// File trailer for generated code.
//
// [EOF]
//
