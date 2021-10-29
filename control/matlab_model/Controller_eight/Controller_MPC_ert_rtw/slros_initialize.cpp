#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "Controller_MPC";

// For Block Controller_MPC/Subscribe2
SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_Controller_MPC_std_msgs_Float32MultiArray> Sub_Controller_MPC_3052;

// For Block Controller_MPC/Subsystem1/Subscribe
SimulinkSubscriber<geometry_msgs::Pose2D, SL_Bus_Controller_MPC_geometry_msgs_Pose2D> Sub_Controller_MPC_2055;

// For Block Controller_MPC/Subsystem1/Subscribe1
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_Controller_MPC_geometry_msgs_Twist> Sub_Controller_MPC_2057;

// For Block Controller_MPC/Subsystem1/Publish
SimulinkPublisher<std_msgs::Int16MultiArray, SL_Bus_Controller_MPC_std_msgs_Int16MultiArray> Pub_Controller_MPC_2063;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

