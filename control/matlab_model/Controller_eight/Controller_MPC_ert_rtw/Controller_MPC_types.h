//
// File: Controller_MPC_types.h
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
#ifndef RTW_HEADER_Controller_MPC_types_h_
#define RTW_HEADER_Controller_MPC_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension_

// MsgType=std_msgs/MultiArrayDimension
typedef struct {
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=Label_SL_Info:TruncateAction=warn 
  uint8_T Label[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Label
  SL_Bus_ROSVariableLengthArrayInfo Label_SL_Info;
  uint32_T Size;
  uint32_T Stride;
} SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_std_msgs_MultiArrayLayout_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_std_msgs_MultiArrayLayout_

// MsgType=std_msgs/MultiArrayLayout
typedef struct {
  // MsgType=std_msgs/MultiArrayDimension:IsVarLen=1:VarLenCategory=data:VarLenElem=Dim_SL_Info:TruncateAction=warn 
  SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension Dim[16];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Dim
  SL_Bus_ROSVariableLengthArrayInfo Dim_SL_Info;
  uint32_T DataOffset;
} SL_Bus_Controller_MPC_std_msgs_MultiArrayLayout;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_std_msgs_Float32MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_std_msgs_Float32MultiArray_

// MsgType=std_msgs/Float32MultiArray
typedef struct {
  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_Controller_MPC_std_msgs_MultiArrayLayout Layout;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  real32_T Data[2004];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
} SL_Bus_Controller_MPC_std_msgs_Float32MultiArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_std_msgs_Int16MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_std_msgs_Int16MultiArray_

// MsgType=std_msgs/Int16MultiArray
typedef struct {
  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_Controller_MPC_std_msgs_MultiArrayLayout Layout;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  int16_T Data[5];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
} SL_Bus_Controller_MPC_std_msgs_Int16MultiArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_geometry_msgs_Pose2D_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_geometry_msgs_Pose2D_

// MsgType=geometry_msgs/Pose2D
typedef struct {
  real_T X;
  real_T Y;
  real_T Theta;
} SL_Bus_Controller_MPC_geometry_msgs_Pose2D;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_Controller_MPC_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Controller_MPC_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_Controller_MPC_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_Controller_MPC_geometry_msgs_Vector3 Angular;
} SL_Bus_Controller_MPC_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_VCWbVJVDNux9Swb9DUvlNB_
#define DEFINED_TYPEDEF_FOR_struct_VCWbVJVDNux9Swb9DUvlNB_

typedef struct {
  real32_T MaxIterations;
  real32_T ConstraintTolerance;
  boolean_T UseWarmStart;
} struct_VCWbVJVDNux9Swb9DUvlNB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Bm9dhj1mgtduI2rza7l3jD_
#define DEFINED_TYPEDEF_FOR_struct_Bm9dhj1mgtduI2rza7l3jD_

typedef struct {
  real32_T MaxIterations;
  real32_T ConstraintTolerance;
  real32_T OptimalityTolerance;
  real32_T ComplementarityTolerance;
  real32_T StepTolerance;
} struct_Bm9dhj1mgtduI2rza7l3jD;

#endif

#ifndef struct_tag_eFCXAaC7vLdwjksE0MwgOD
#define struct_tag_eFCXAaC7vLdwjksE0MwgOD

struct tag_eFCXAaC7vLdwjksE0MwgOD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_eFCXAaC7vLdwjksE0MwgOD

#ifndef typedef_ros_slroscpp_internal_block_S_T
#define typedef_ros_slroscpp_internal_block_S_T

typedef tag_eFCXAaC7vLdwjksE0MwgOD ros_slroscpp_internal_block_S_T;

#endif                                 //typedef_ros_slroscpp_internal_block_S_T

#ifndef struct_tag_D6QYIVJDjoKN0blLVEpT8F
#define struct_tag_D6QYIVJDjoKN0blLVEpT8F

struct tag_D6QYIVJDjoKN0blLVEpT8F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_D6QYIVJDjoKN0blLVEpT8F

#ifndef typedef_ros_slroscpp_internal_block_P_T
#define typedef_ros_slroscpp_internal_block_P_T

typedef tag_D6QYIVJDjoKN0blLVEpT8F ros_slroscpp_internal_block_P_T;

#endif                                 //typedef_ros_slroscpp_internal_block_P_T

// Parameters for system: '<S8>/Path Following Control System'
typedef struct P_PathFollowingControlSystem__T_ P_PathFollowingControlSystem__T;

// Parameters (default storage)
typedef struct P_Controller_MPC_T_ P_Controller_MPC_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Controller_MPC_T RT_MODEL_Controller_MPC_T;

#endif                                 // RTW_HEADER_Controller_MPC_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
