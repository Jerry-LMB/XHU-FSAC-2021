//
// File: Controller_MPC.h
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
#ifndef RTW_HEADER_Controller_MPC_h_
#define RTW_HEADER_Controller_MPC_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "Controller_MPC_types.h"

// Child system includes
#include "Cont_PathFollowingControlSystem.h"
#include "rt_nonfinite.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_Controller_MPC_std_msgs_Float32MultiArray In1;// '<S4>/In1'
  SL_Bus_Controller_MPC_std_msgs_Float32MultiArray b_varargout_2;
  real32_T b_varargout_2_Data[2004];
  real_T kappar[501];                  // '<S3>/MATLAB Function'
  real_T thetar[501];                  // '<S3>/MATLAB Function'
  real_T yr[501];                      // '<S3>/MATLAB Function'
  real_T xr[501];                      // '<S3>/MATLAB Function'
  SL_Bus_Controller_MPC_std_msgs_Int16MultiArray BusAssignment;// '<S3>/Bus Assignment' 
  SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension b_varargout_2_Layout_Dim[16];
  SL_Bus_Controller_MPC_geometry_msgs_Twist In1_h;// '<S59>/In1'
  SL_Bus_Controller_MPC_geometry_msgs_Twist b_varargout_2_m;
  char_T b_zeroDelimTopic[29];
  SL_Bus_Controller_MPC_geometry_msgs_Pose2D In1_l;// '<S58>/In1'
  SL_Bus_Controller_MPC_geometry_msgs_Pose2D b_varargout_2_c;
  real_T y;
  real_T d_min_last;
  real_T d_min;
  real_T b_a;
  real_T Gain1;                        // '<S6>/Gain1'
  real_T d_err_idx_0;
  real32_T rtb_u_scale_k[2];
  real32_T rtb_DataTypeConversion4_c;
  real32_T rtb_DataTypeConversion3_b;
  real32_T rtb_DataTypeConversion1_p;
  real32_T rtb_DataTypeConversion2_c;
  int32_T dmin;
  int32_T i;
  uint32_T b_varargout_2_Layout_Dim_SL_Inf;
  uint32_T b_varargout_2_Layout_Dim_SL_I_g;
  uint32_T b_varargout_2_Layout_DataOffset;
  uint32_T b_varargout_2_Data_SL_Info_Curr;
  uint32_T b_varargout_2_Data_SL_Info_Rece;
  B_PathFollowingControlSystem__T PathFollowingControlSystem;// '<S8>/Path Following Control System' 
} B_Controller_MPC_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slroscpp_internal_block_S_T obj; // '<S12>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_p;// '<S11>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_o;// '<S2>/SourceBlock'
  ros_slroscpp_internal_block_P_T obj_a;// '<S9>/SinkBlock'
  real_T flag;                         // '<Root>/MATLAB Function'
  real_T enable_flag;                  // '<Root>/MATLAB Function'
  DW_PathFollowingControlSystem_T PathFollowingControlSystem;// '<S8>/Path Following Control System' 
} DW_Controller_MPC_T;

// Parameters (default storage)
struct P_Controller_MPC_T_ {
  real_T PathFollowingControlSystem_MaxA;
                              // Mask Parameter: PathFollowingControlSystem_MaxA
                                 //  Referenced by: '<S8>/Path Following Control System'

  real_T PathFollowingControlSystem_MaxS;
                              // Mask Parameter: PathFollowingControlSystem_MaxS
                                 //  Referenced by: '<S8>/Path Following Control System'

  real_T PathFollowingControlSystem_MinA;
                              // Mask Parameter: PathFollowingControlSystem_MinA
                                 //  Referenced by: '<S8>/Path Following Control System'

  real_T PathFollowingControlSystem_MinS;
                              // Mask Parameter: PathFollowingControlSystem_MinS
                                 //  Referenced by: '<S8>/Path Following Control System'

  real32_T PathFollowingControlSystem_Defa;
                              // Mask Parameter: PathFollowingControlSystem_Defa
                                 //  Referenced by: '<S8>/Path Following Control System'

  SL_Bus_Controller_MPC_std_msgs_Float32MultiArray Out1_Y0;// Computed Parameter: Out1_Y0
                                                              //  Referenced by: '<S4>/Out1'

  SL_Bus_Controller_MPC_std_msgs_Float32MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                                     //  Referenced by: '<S2>/Constant'

  SL_Bus_Controller_MPC_std_msgs_Int16MultiArray Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                     //  Referenced by: '<S5>/Constant'

  SL_Bus_Controller_MPC_geometry_msgs_Twist Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                         //  Referenced by: '<S59>/Out1'

  SL_Bus_Controller_MPC_geometry_msgs_Twist Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                                //  Referenced by: '<S12>/Constant'

  SL_Bus_Controller_MPC_geometry_msgs_Pose2D Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                          //  Referenced by: '<S58>/Out1'

  SL_Bus_Controller_MPC_geometry_msgs_Pose2D Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                                 //  Referenced by: '<S11>/Constant'

  real_T ID_Value;                     // Expression: 256
                                          //  Referenced by: '<S3>/ID'

  real_T DataLen_Value;                // Expression: 3
                                          //  Referenced by: '<S3>/DataLen'

  real_T SPD_Value;                    // Expression: 30
                                          //  Referenced by: '<S3>/SPD'

  real_T Gain1_Gain;                   // Expression: pi/180
                                          //  Referenced by: '<S6>/Gain1'

  real_T Saturation_UpperSat;          // Expression: inf
                                          //  Referenced by: '<S8>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0.01
                                          //  Referenced by: '<S8>/Saturation'

  real_T Saturation1_UpperSat;         // Expression: inf
                                          //  Referenced by: '<S8>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: 1
                                          //  Referenced by: '<S8>/Saturation1'

  real_T Gain_Gain;                    // Expression: 180/pi
                                          //  Referenced by: '<S10>/Gain'

  real_T SPD1_Value;                   // Expression: 120
                                          //  Referenced by: '<S3>/SPD1'

  real_T Brk_Value;                    // Expression: 0
                                          //  Referenced by: '<S3>/Brk'

  uint32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                          //  Referenced by: '<S3>/Constant4'

  P_PathFollowingControlSystem__T PathFollowingControlSystem;// '<S8>/Path Following Control System' 
};

// Real-time Model Data Structure
struct tag_RTM_Controller_MPC_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_Controller_MPC_T Controller_MPC_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_Controller_MPC_T Controller_MPC_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_Controller_MPC_T Controller_MPC_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void Controller_MPC_initialize(void);
  extern void Controller_MPC_step(void);
  extern void Controller_MPC_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Controller_MPC_T *const Controller_MPC_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Controller_MPC'
//  '<S1>'   : 'Controller_MPC/MATLAB Function'
//  '<S2>'   : 'Controller_MPC/Subscribe2'
//  '<S3>'   : 'Controller_MPC/Subsystem1'
//  '<S4>'   : 'Controller_MPC/Subscribe2/Enabled Subsystem'
//  '<S5>'   : 'Controller_MPC/Subsystem1/Blank Message'
//  '<S6>'   : 'Controller_MPC/Subsystem1/Degrees to Radians'
//  '<S7>'   : 'Controller_MPC/Subsystem1/MATLAB Function'
//  '<S8>'   : 'Controller_MPC/Subsystem1/MPC'
//  '<S9>'   : 'Controller_MPC/Subsystem1/Publish'
//  '<S10>'  : 'Controller_MPC/Subsystem1/Steer'
//  '<S11>'  : 'Controller_MPC/Subsystem1/Subscribe'
//  '<S12>'  : 'Controller_MPC/Subsystem1/Subscribe1'
//  '<S13>'  : 'Controller_MPC/Subsystem1/MPC/MATLAB Function'
//  '<S14>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System'
//  '<S15>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/Data Processing for MPC Controller'
//  '<S16>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/Longitudinal velocity must be positive'
//  '<S17>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers'
//  '<S18>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Models'
//  '<S19>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/Vehicle Models'
//  '<S20>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller'
//  '<S21>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller'
//  '<S22>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC'
//  '<S23>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check'
//  '<S24>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check A'
//  '<S25>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check B'
//  '<S26>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check C'
//  '<S27>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check D'
//  '<S28>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check DX'
//  '<S29>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check U'
//  '<S30>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check X'
//  '<S31>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check Y'
//  '<S32>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check1'
//  '<S33>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check2'
//  '<S34>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check'
//  '<S35>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check1'
//  '<S36>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check2'
//  '<S37>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check3'
//  '<S38>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check4'
//  '<S39>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check5'
//  '<S40>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check6'
//  '<S41>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check7'
//  '<S42>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check8'
//  '<S43>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Scalar Signal Check'
//  '<S44>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Scalar Signal Check1'
//  '<S45>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Scalar Signal Check2'
//  '<S46>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check'
//  '<S47>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check1'
//  '<S48>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check11'
//  '<S49>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check6'
//  '<S50>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/optimizer'
//  '<S51>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Controllers/Path Following Controller/Adaptive MPC Controller/MPC/optimizer/FixedHorizonOptimizer'
//  '<S52>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Models/MPC Model'
//  '<S53>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/MPC Models/MPC Model/Adaptive Model'
//  '<S54>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/Vehicle Models/Vehicle parametric model'
//  '<S55>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/Vehicle Models/Vehicle parametric model/Vehicle combined dynamics'
//  '<S56>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/Vehicle Models/Vehicle parametric model/Vehicle lateral dynamics'
//  '<S57>'  : 'Controller_MPC/Subsystem1/MPC/Path Following Control System/Vehicle Models/Vehicle parametric model/Vehicle longitudinal dynamics'
//  '<S58>'  : 'Controller_MPC/Subsystem1/Subscribe/Enabled Subsystem'
//  '<S59>'  : 'Controller_MPC/Subsystem1/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_Controller_MPC_h_

//
// File trailer for generated code.
//
// [EOF]
//
