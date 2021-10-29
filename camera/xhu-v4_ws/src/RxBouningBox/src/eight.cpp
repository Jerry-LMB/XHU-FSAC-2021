/*****************************************************************************************************
#功能对坐标系进行转换后存储
＃作者：李美斌,朱兴建  
世界坐标系正北为Ｙ，正东为Ｘ，载体坐标系　前进方向为Ｙ，与Ｙ垂直的右边为Ｘ．
航向角是以正东方向（Ｘ），到前进方向的夹角，逆时针方向
车身坐标系是以车头前进方向为x，左边为y，跟摄像头有一个90度的转换
在大地坐标系下，x方向大概是40多万，y方向大概是300多万
这个程序是储存直线的
*************************************************************************************************/
#include<ros/ros.h>
#include<vector>
#include<iostream>
#include <cmath>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include "darknet_ros_msgs/BoundingBoxes.h"
#include "darknet_ros_msgs/BoundingBox.h"
#include <geometry_msgs/Pose2D.h>
#include <iomanip>
#include"RxBouningBox/point.h"
#include"RxBouningBox/point_array.h"
#include<geometry_msgs/Pose.h>
#include<geometry_msgs/PoseArray.h>

const float D2R = 3.1415926/180;
const float dd = 0.22;//转换车身坐标
class Position
{
  public:
  double x = 0.0;
  double y = 0.0;
};//申明位置类，用来储存绝对的坐标点
double X = 0.0;//定义的绝对坐标ｘ;
double Y = 0.0;//定义的绝对坐标y;
float  theta = 0.0;//定义航向角;
double  r_x = 0.0;//定义的车身坐标ｘ;是以车头的前进方向为x,左边为y,//定义的车身坐标y;
double  r_y =0.0;
std::vector<Position> yellow;//定义的vector数组类，来储存黄色的锥桶
double gr_x = 0.0;
double gr_y = 0.0;//设置的一进循环就直接把值转化为绝对坐标系
uint8_t FPS = 0;//计算帧数第一帧
uint8_t count1 = 0;//第一帧标志位
uint8_t count2 = 0;
uint8_t r_flag = 0;//定义的比较标志位，置1才执行比较
uint8_t c_flag = 0;
uint8_t rflag = 0;//设置的循环遍历的存储标志位
uint8_t cflag = 0;
Position yellow_;//申明类的对象left_和right_
class p_and_s //声明一个类 来实现一个节点订阅和发布消息
{
public:
  p_and_s()
  {
   Pub_point = nh.advertise<geometry_msgs::Pose>("/point",50);//申明订阅者和发布者，发布和订阅的队列长度要一样，不然会数据延迟
   Sub_imu = nh.subscribe("/canalystii_ros/vehicle_Pose",50,&p_and_s::CallBack_GPS,this);
   Sub_BX = nh.subscribe("/darknet_ros/bounding_boxes",50,&p_and_s::CallBack,this);
  }
  void CallBack(const darknet_ros_msgs:: BoundingBoxes::ConstPtr &msg)//bounding boxes 回调函数，接收距离数据实现坐标转换和发布
{
  if(FPS == 1 && count1 !=0 )
  {
    r_flag = 1;
    count1 = 0;
  }
  if(FPS == 1 && count2 !=0)
  {
    c_flag = 1;
    count2 = 0;
  }//只进一次，来储存第一帧的点
  for (uint8_t i = 0; i < msg->bounding_boxes.size(); i++)//循环遍历每一个框
  { 
    if((msg->bounding_boxes[i].Class == "yellow") == 1 && msg->bounding_boxes[i].ymax > 300 && X > 0)//当在直线时，分左右
    {     
          r_x = (msg->bounding_boxes[i].distancey)/100.0-dd;//将每次来的值从相机坐标系转化为车身坐标系，并且将距离单位转化为m
          r_y = -(msg->bounding_boxes[i].distancex)/100.0;
          gr_x = X + r_x*cos(theta*D2R) - r_y*sin(theta*D2R);//将进来的值，转化为绝对坐标系
          gr_y = Y + r_y*cos(theta*D2R) + r_x*sin(theta*D2R);
      if (r_flag == 0 )//将来的第一帧，近的框的坐标直接放入，vector里面
      { 
        yellow_.x =  X + r_x*cos(theta*D2R) - r_y*sin(theta*D2R);//将识别的坐标点转换到绝对坐标系
        yellow_.y =  Y + r_y*cos(theta*D2R) + r_x*sin(theta*D2R);
        yellow.push_back(yellow_);
        count1 = 1;
      }
      if (r_flag ==1 )//走第二帧开始，来的的每一个点，都去与vector数组里面的每一个值比较，只要有一个距离小于2，将存入标志位值1，并退出循环且这个点不放入ｖｅｃｔｏｒ
      { 
        for (std::vector<Position>::iterator it = yellow.begin();it!= yellow.end();it++)//循环遍历比较
          {
            if (pow(((*it).x - gr_x),2) + pow(((*it).y - gr_y),2) < 1 )
            {
              // (*it).x = ((*it).x + gr_x)/2;//对每次最后的一个值，进行均值的求解
              // (*it).y = ((*it).y + gr_y)/2;
              rflag = 1;
              break;
            }            
          }
          if(rflag == 0)//当来的点，都不满足上面的条件时．rflag = 0,将此点存入
          {
            yellow_.x = gr_x;//将识别的坐标点转换到绝对坐标系
            yellow_.y = gr_y;
             yellow.push_back(yellow_);
          }
      }
    } 
  } 
        double c_x = 0.0;
        double c_y = 0.0;
      if (yellow.size() == 4)// 当识别距离的范围就只能看到一个锥桶时
      {
        if(c_flag == 0)
        {
          p.position.x = (yellow[0].x  + yellow[1].x + yellow[2].x + yellow[3].x)/4;
          p.position.y = (yellow[0].y  + yellow[1].y + yellow[2].y + yellow[3].y)/4;
          p.position.z = theta;
          c_x = p.position.x;
          c_y = p.position.y;
          center.poses.push_back(p);
          count2 = 1;
        }
        if (c_flag ==1)
        { 
          for (auto it = center.poses.begin();it!= center.poses.end();it++)
          {
            if (pow(((*it).position.x - c_x),2) + pow(((*it).position.y - c_y),2) < 2 )
            {
              // (*it).position.x = ((*it).position.x + c_x)/2;
              // (*it).position.y = ((*it).position.y + c_y)/2;
              cflag = 1;
              break;
            }
          }
          if(cflag == 0)
          {
            // p.position.x = c_x;
            // p.position.y = c_y;
            // center.poses.push_back(p);
          }
       }
      }  
  FPS = 1;
  rflag = 0;
  cflag = 0;//循环完了，之后将标志位清零
      for (std::vector<Position>::iterator it = yellow.begin();it!= yellow.end();it++)
      {
        std::cout<<yellow.size()<<" ";
        std::cout<<"yellow_x = "<<std::setprecision(8)<<(*it).x<<" ";
        std::cout<<"yellow_y = "<<std::setprecision(9)<<(*it).y<<std::endl;
      }
      for (auto it = center.poses.begin();it!= center.poses.end();it++)
      {
        std::cout<<center.poses.size()<<" ";
        std::cout<<"center_x = "<<std::setprecision(8)<<(*it).position.x<<" ";
        std::cout<<"center_y = "<<std::setprecision(9)<<(*it).position.y<<" ";
        std::cout<<"center_z = "<<std::setprecision(9)<<(*it).position.y<<std::endl;
      }
  std::cout<<"一帧结束 = "<<std::endl;
   Pub_point.publish(p);//发布规划的点的坐标
}
void CallBack_GPS(const geometry_msgs::Pose2D::ConstPtr &msg)//gps回调函数，订阅gps信息
{
     Y = msg->y;
     X = msg->x;
     theta = msg->theta;
     //ROS_INFO("theta =%.2f ",theta);
}
 private:
    ros::NodeHandle nh;
    ros::Publisher Pub_point;
    ros::Subscriber Sub_imu;
    ros::Subscriber Sub_BX; 
    geometry_msgs::PoseArray  center;
    geometry_msgs::Pose p;
    //申明句炳，发布者，订阅者和储存偏移点的坐标
};
int main(int argc, char *argv[])
{
  ros::init(argc,argv,"eightNode");//初始化节点
  p_and_s SAPObject;//调用改类
  ros::spin();//一直在此处循环
  return 0;
}
