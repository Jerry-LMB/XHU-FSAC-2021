#ifndef canalystii_ros_H
#define canalystii_ros_H

#include "ros/ros.h"
#include "canalystii.h"


class canalystii_ros:public CANalystii{
private:
    ros::NodeHandle node_handle_;
    // appointed ROS topic     
    std::string can_msg_pub_topic_port0;
    std::string can_msg_pub_topic_port1;
    std::string can_msg_sub_port0_topic_;
    std::string can_msg_sub_port1_topic_;
      
public:
    canalystii_ros(int vci_device_type=VCI_USBCAN2, int vci_device_ind=0);
    //~canalystii_ros();
    // timer for sending CAN frame to CAN bus
	ros::Timer send_timer;
    // timer for receiving CAN frame from CAN bus
    ros::Timer receive_timer;
    // publish CAN frame to appointed ROS topic
    ros::Publisher can_msg_pub_port0_;
    ros::Publisher can_msg_pub_port1_;
    
    ros::Publisher veh_pose;
    ros::Publisher veh_spd;


    // subscribe CAN msg to send CAN frame
    ros::Subscriber sub_can_msg_port0_;
    ros::Subscriber sub_can_msg_port1_;
    //timer callback() for receiving CAN frame from CAN bus
    void receivetimerCallback(const ros::TimerEvent&);
    // timer callback() sending CAN frame to CAN bus
    void sendtimerCallback(const ros::TimerEvent&);
    // callback() for sending CAN frame to CAN bus
    void sub_can_msg_port0_Callback(const std_msgs::Int16MultiArray & input);
    void sub_can_msg_port1_Callback(const std_msgs::Int16MultiArray & input);
    void gps2xy(const double &lat,const double &lon);//gps2xy函数声明
    void GPS_Theta2Map_Theta(const float &gps_theta);//航向角转换函数声明
    void Spd_Transfor(const float &theta);//Vx,Vy获取函数声明
    std_msgs::Int16MultiArray  frame_50_51; 
    bool frame_50_51_initialized;
    float psi = 0.0; //初始化车辆横摆角 degrees
    double lat = 0.0; //初始化经度
    long long int lat_temp = 0;
    long long int Lat_temp = 0;

    long long int  lon_temp = 0;
    long long int Lon_temp = 0;
    double lon = 0.0; //初始化纬度

    float ve = 0.0;  //初始化东方速度
    long long int ve_temp = 0;
    long long int Ve_temp = 0;


    float vn = 0.0;  //初始化北方速度
    long long int vn_temp = 0;
    long long int Vn_temp = 0;

    long long int ax_temp = 0;
    long long int Ax_temp = 0;
    float ax = 0.0;

    long long int  ay_temp = 0;
    long long int Ay_temp = 0;
    float ay = 0.0;

    long long int  az_temp = 0;
    long long int Az_temp = 0;
    float az = 0.0;

    long long int  wz_temp = 0;
    long long int Wz_temp = 0;
    float  wz = 0.0;

//经纬度转XY定义变量
double x = 0;
double y = 0;
float vx  = 0;
float vy = 0;
float theta = 0;
float gps_theta = 0;
const float pi = 3.1415926;
const float KD2R = pi/180;
int ZoneNumber  = 0;
const double a = 6378137.0;
const double f = 1/298.257223563;
const double F = 298.257223563;
const double b = a*(1-f);
const double ee = (a*a-b*b)/(a*a);
const double e2 = (a*a-b*b)/(b*b);
const double n = (a-b)/(a+b);
const double n2 = n*n;
const double n3 = n2*n;
const double n4 = n2*n2;
const double n5 = n4*n;
const double al = (a + b) * (1 + n2 / 4 + n4 / 64) / 2.0;
const double bt = -3 * n / 2 + 9 * n3 / 16 - 3 * n5 / 32.0;
const double gm = 15 * n2 / 16 - 15 * n4 / 32;
const double dt = -35 * n3 / 48 + 105 * n5 / 256;
const double ep = 315 * n4 / 512;
double B = 0;
double L = 0;
double L0 = 0;
double l = 0;
double cl = 0;
double cl2 = 0;
double cl3 = 0;
double cl4 = 0;
double cl5 = 0;
double cl6 = 0;
double cl7 = 0;
double cl8 = 0;
double lB = 0;
double t = 0;
double t2 = 0;
double t4 = 0;
double t6 = 0;
double Nn = 0;
double yt = 0;
double N = 0;
double E = 0;
};
#endif
