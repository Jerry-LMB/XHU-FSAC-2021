#include "ros/ros.h"
#include "canalystii_ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Twist.h"
int main(int argc, char **argv){
    ros::init(argc, argv, "canalystii_ros");
    canalystii_ros can_node(VCI_USBCAN2, 0);// 0 for first device 
    
    ros::AsyncSpinner spinner(4); // Use 4 threads
    spinner.start();
    ros::waitForShutdown();
    return 0;
}
