#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_Controller_MPC_geometry_msgs_Pose2D and geometry_msgs::Pose2D

void convertFromBus(geometry_msgs::Pose2D* msgPtr, SL_Bus_Controller_MPC_geometry_msgs_Pose2D const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose2D");

  msgPtr->theta =  busPtr->Theta;
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
}

void convertToBus(SL_Bus_Controller_MPC_geometry_msgs_Pose2D* busPtr, geometry_msgs::Pose2D const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose2D");

  busPtr->Theta =  msgPtr->theta;
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
}


// Conversions between SL_Bus_Controller_MPC_geometry_msgs_Twist and geometry_msgs::Twist

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_Controller_MPC_geometry_msgs_Twist const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertFromBus(&msgPtr->angular, &busPtr->Angular);
  convertFromBus(&msgPtr->linear, &busPtr->Linear);
}

void convertToBus(SL_Bus_Controller_MPC_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertToBus(&busPtr->Angular, &msgPtr->angular);
  convertToBus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_Controller_MPC_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_Controller_MPC_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_Controller_MPC_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_Controller_MPC_std_msgs_Float32MultiArray and std_msgs::Float32MultiArray

void convertFromBus(std_msgs::Float32MultiArray* msgPtr, SL_Bus_Controller_MPC_std_msgs_Float32MultiArray const* busPtr)
{
  const std::string rosMessageType("std_msgs/Float32MultiArray");

  convertFromBusVariablePrimitiveArray(msgPtr->data, busPtr->Data, busPtr->Data_SL_Info);
  convertFromBus(&msgPtr->layout, &busPtr->Layout);
}

void convertToBus(SL_Bus_Controller_MPC_std_msgs_Float32MultiArray* busPtr, std_msgs::Float32MultiArray const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Float32MultiArray");

  convertToBusVariablePrimitiveArray(busPtr->Data, busPtr->Data_SL_Info, msgPtr->data, slros::EnabledWarning(rosMessageType, "data"));
  convertToBus(&busPtr->Layout, &msgPtr->layout);
}


// Conversions between SL_Bus_Controller_MPC_std_msgs_Int16MultiArray and std_msgs::Int16MultiArray

void convertFromBus(std_msgs::Int16MultiArray* msgPtr, SL_Bus_Controller_MPC_std_msgs_Int16MultiArray const* busPtr)
{
  const std::string rosMessageType("std_msgs/Int16MultiArray");

  convertFromBusVariablePrimitiveArray(msgPtr->data, busPtr->Data, busPtr->Data_SL_Info);
  convertFromBus(&msgPtr->layout, &busPtr->Layout);
}

void convertToBus(SL_Bus_Controller_MPC_std_msgs_Int16MultiArray* busPtr, std_msgs::Int16MultiArray const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Int16MultiArray");

  convertToBusVariablePrimitiveArray(busPtr->Data, busPtr->Data_SL_Info, msgPtr->data, slros::EnabledWarning(rosMessageType, "data"));
  convertToBus(&busPtr->Layout, &msgPtr->layout);
}


// Conversions between SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension and std_msgs::MultiArrayDimension

void convertFromBus(std_msgs::MultiArrayDimension* msgPtr, SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension const* busPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayDimension");

  convertFromBusVariablePrimitiveArray(msgPtr->label, busPtr->Label, busPtr->Label_SL_Info);
  msgPtr->size =  busPtr->Size;
  msgPtr->stride =  busPtr->Stride;
}

void convertToBus(SL_Bus_Controller_MPC_std_msgs_MultiArrayDimension* busPtr, std_msgs::MultiArrayDimension const* msgPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayDimension");

  convertToBusVariablePrimitiveArray(busPtr->Label, busPtr->Label_SL_Info, msgPtr->label, slros::EnabledWarning(rosMessageType, "label"));
  busPtr->Size =  msgPtr->size;
  busPtr->Stride =  msgPtr->stride;
}


// Conversions between SL_Bus_Controller_MPC_std_msgs_MultiArrayLayout and std_msgs::MultiArrayLayout

void convertFromBus(std_msgs::MultiArrayLayout* msgPtr, SL_Bus_Controller_MPC_std_msgs_MultiArrayLayout const* busPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayLayout");

  msgPtr->data_offset =  busPtr->DataOffset;
  convertFromBusVariableNestedArray(msgPtr->dim, busPtr->Dim, busPtr->Dim_SL_Info);
}

void convertToBus(SL_Bus_Controller_MPC_std_msgs_MultiArrayLayout* busPtr, std_msgs::MultiArrayLayout const* msgPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayLayout");

  busPtr->DataOffset =  msgPtr->data_offset;
  convertToBusVariableNestedArray(busPtr->Dim, busPtr->Dim_SL_Info, msgPtr->dim, slros::EnabledWarning(rosMessageType, "dim"));
}

