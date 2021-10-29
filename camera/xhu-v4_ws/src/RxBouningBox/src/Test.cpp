/*****************************************************************************************************
#功能对坐标系进行转换后存储
＃作者：朱兴建 , 李美斌
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
#include<std_msgs/UInt8.h>
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
double x = 0.0;
double y = 0.0;
double g_x = 0.0;
double g_y = 0.0;
std::vector<Position> red;//定义的ｖｅｃｔｏｒ数组类，来储存左边和右边的距离值
std::vector<Position> blue;
Position red_;//申明类的对象left_和right_
Position blue_;
uint8_t FPS = 0;//计算帧数第一帧
uint8_t count1 = 0;//第一帧标志位
uint8_t count2 = 0;
uint8_t count3 = 0;
uint8_t r_flag = 0;//定义的比较标志位，置1才执行比较
uint8_t b_flag = 0;
uint8_t c_flag = 0;
uint8_t bflag = 0;//设置的循环遍历的存储标志位
uint8_t rflag = 0;
uint8_t cflag = 0;
uint8_t test = 0;
class p_and_s //声明一个类 来实现一个节点订阅和发布消息
{
public:
  p_and_s()
  {
   Pub_point = nh.advertise<geometry_msgs::PoseArray>("/point",50);//申明订阅者和发布者，发布和订阅的队列长度要一样，不然会数据延迟
   Pub_stop = nh.advertise<std_msgs::UInt8>("/stop",50);//发布停止加速标志位话题
   Sub_imu = nh.subscribe("/canalystii_ros/vehicle_Pose",50,&p_and_s::CallBack_GPS,this);
   Sub_BX = nh.subscribe("/darknet_ros/bounding_boxes",50,&p_and_s::CallBack,this);
  }
   private:
    ros::NodeHandle nh;
    ros::Publisher Pub_point;
     ros::Publisher Pub_stop;
    ros::Subscriber Sub_imu;
    ros::Subscriber Sub_BX; 
    geometry_msgs::PoseArray  center;
    geometry_msgs::Pose p;
     std_msgs::UInt8 stop_flag;//申明句炳，发布者，订阅者和储存偏移点的坐标
void CallBack_GPS(const geometry_msgs::Pose2D::ConstPtr &msg)//gps回调函数，订阅gps信息
{
     Y = msg->y;
     X = msg->x;
     theta = msg->theta;
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
    b_flag = 1;
    count2 = 0;
  }
   if(FPS == 1 && count3 !=0)
  {
    c_flag = 1;
    count3 = 0;
  }//只进一次，来储存第一帧的点
  for (uint8_t i = 0; i < msg->bounding_boxes.size(); i++)//循环遍历每一个框，
  { 
    if((msg->bounding_boxes[i].Class == "red") == 1 && msg->bounding_boxes[i].ymax > 301 && X > 0)//当在直线时，分左右
    {     
          x = (msg->bounding_boxes[i].distancey)/100.0-dd;//将每次来的值从相机坐标系转化为车身坐标系，并且将距离单位转化为m
          y = -(msg->bounding_boxes[i].distancex)/100.0;
          g_x = X + x*cos(theta*D2R) - y*sin(theta*D2R);//将进来的值，转化为绝对坐标系
          g_y = Y + y*cos(theta*D2R) + x*sin(theta*D2R);
      if (r_flag == 0 )//将来的第一帧，近的框的坐标直接放入，vector里面
      { 
        red_.x =  g_x;//将识别的坐标点转换到绝对坐标系
        red_.y =  g_y;
        red.push_back(red_);
        count1 = 1;
      }
      if (r_flag ==1 )//走第二帧开始，来的的每一个点，都去与vector数组里面的每一个值比较，只要有一个距离小于2，将存入标志位值1，并退出循环且这个点不放入ｖｅｃｔｏｒ
      { 
        for (std::vector<Position>::iterator it = red.begin();it!= red.end();it++)//循环遍历比较
          {
            if (pow(((*it).x - g_x),2) + pow(((*it).y - g_y),2) < 1 )
            {
              (*it).x = ((*it).x + g_x)/2;//对每次最后的一个值，进行均值的求解
              (*it).y = ((*it).y + g_y)/2;
              rflag = 1;
              break;
            }            
          }
          if(rflag == 0)//当来的点，都不满足上面的条件时．rflag = 0,将此点存入
          {
            red_.x = g_x;//将识别的坐标点转换到绝对坐标系
            red_.y = g_y;
             red.push_back(red_);
          }
      }
    } 
    ///红色改*************************结束************************************************************/////////////////////////////////
    if ((msg->bounding_boxes[i].Class == "blue") == 1 && msg->bounding_boxes[i].ymax > 301 && X > 0)
    {
          x = (msg->bounding_boxes[i].distancey)/100.0-dd;//将坐标值赴给车身坐标系并转化为ｍ为单位
          y = -(msg->bounding_boxes[i].distancex)/100.0;
          g_x = X + x*cos(theta*D2R) - y*sin(theta*D2R);//将识别的坐标点转换到绝对坐标系
          g_y = Y + y*cos(theta*D2R) + x*sin(theta*D2R);
     if (b_flag == 0)
      {
        blue_.x = g_x;//将识别的坐标点转换到绝对坐标系
        blue_.y = g_y;
        blue.push_back(blue_);
        count2 = 1;  
      } 
      if (b_flag ==1)
      { 
          for (std::vector<Position>::iterator it = blue.begin();it!= blue.end();it++)
          {
            if (pow(((*it).x - g_x),2) + pow(((*it).y - g_y),2) < 1 )
            {
            (*it).x = ((*it).x + g_x)/2;
            (*it).y = ((*it).y + g_y)/2;
              bflag = 1;
              break;
            }
          }
          if(bflag == 0)
          {
            blue_.x = g_x;//将识别的坐标点转换到绝对坐标系
            blue_.y = g_y;
            blue.push_back(blue_);
          }
      } 
    }  
  } 
    if(red.size() >= 2 && blue.size() >=2 && X > 0)//平均值给点法//////////////////////////////// start
    {
        if(c_flag == 0)
        {
        p.position.x = X;
        p.position.y = Y;
        center.poses.push_back(p);
        p.position.x = (blue[0].x + red[0].x + blue[1].x + red[1].x)/4;
        p.position.y = (blue[0].y + red[0].y + blue[1].y + red[1].y)/4;
        center.poses.push_back(p);
        float th = atan((center.poses[1].position.y - center.poses[0].position.y)/(center.poses[1].position.x - center.poses[0].position.x));
        if(th < 0)
        {
          if(center.poses[1].position.y < center.poses[0].position.y && center.poses[1].position.x > center.poses[0].position.x)// 四象限
          {
              for (size_t i = 1; i < 8; i++)
              {
                p.position.x = center.poses[i].position.x + 5*cos(th);
                p.position.y = center.poses[i].position.y + 5*sin(th);
               center.poses.push_back(p);
              }           
          }
          if(center.poses[1].position.y > center.poses[0].position.y && center.poses[1].position.x  <  center.poses[0].position.x) // 二象限
          {
              for (size_t i = 1; i < 8; i++)
              {
                p.position.x = center.poses[i].position.x - 5*cos(th);
                p.position.y = center.poses[i].position.y - 5*sin(th);
               center.poses.push_back(p);
              }
          }
        }
        if(th >= 0)
        {
          if(center.poses[1].position.y > center.poses[0].position.y && center.poses[1].position.x > center.poses[0].position.x)// 一象限
          {
              for (size_t i = 1; i < 8; i++)
              {
                p.position.x = center.poses[i].position.x + 5*cos(th);
                p.position.y = center.poses[i].position.y + 5*sin(th);
               center.poses.push_back(p);
              }
          }
          if(center.poses[1].position.y < center.poses[0].position.y && center.poses[1].position.x < center.poses[0].position.x)// 三象限
          {
              for (size_t i = 1; i < 8; i++)
              {
                p.position.x = center.poses[i].position.x - 5*cos(th);
                p.position.y = center.poses[i].position.y - 5*sin(th);
               center.poses.push_back(p);
              }
          }
        }
        count3 = 1;
        test = 1;
        }
        // if (c_flag ==1)
        // { 
        //   for (auto it = center.poses.begin();it!= center.poses.end();it++)
        //   {
        //     if (pow(((*it).position.x - g_x),2) + pow(((*it).position.y - g_y),2) < 2 )
        //     {
        //       (*it).position.x = ((*it).position.x + g_x)/2;
        //       (*it).position.y = ((*it).position.y + g_y)/2;
        //       cflag = 1;
        //       break;
        //     }
        //   }
        //   if(cflag == 0)
        //   {
        //     p.position.x = g_x;
        //     p.position.y = g_y;
        //     center.poses.push_back(p);
        //   }
        // } 
    }  ////// end ////
    if (test ==1)
    {
        if ( pow((X - center.poses[0].position.x),2) + pow((Y - center.poses[0].position.y),2) >= 625)
      {
         stop_flag.data = 2;//z等于2时，就开始提速
        std::cout<<"开始减速2222"<<std::endl;
      }
    }
  FPS = 1;
  bflag = 0;
  rflag = 0;
  cflag = 0;//循环完了，之后将标志位清零
  // for (auto it = center.poses.begin();it!= center.poses.end();it++)
  //     {
  //       std::cout<<center.poses.size()<<" ";
  //       std::cout<<"center_x = "<<std::setprecision(8)<<(*it).position.x<<" ";
  //       std::cout<<"center_y = "<<std::setprecision(9)<<(*it).position.y<<std::endl;
  //     }
for (std::vector<Position>::iterator it = red.begin();it!= red.end();it++)
      {
        std::cout<<red.size()<<" ";
        std::cout<<"right_x = "<<std::setprecision(8)<<(*it).x<<" ";
        std::cout<<"right_y = "<<std::setprecision(9)<<(*it).y<<std::endl;
      }
      for (std::vector<Position>::iterator it = blue.begin();it!= blue.end();it++)
      {
        std::cout<<blue.size()<<" ";
        std::cout<<"left_x = "<<std::setprecision(8)<<(*it).x<<" ";
        std::cout<<"left_y = "<<std::setprecision(9)<<(*it).y<<std::endl;
      }
  std::cout<<"一帧结束 = "<<std::endl;
   Pub_point.publish(center);//发布规划的点的坐标
   Pub_stop.publish(stop_flag);// publish stop_flag
}
};
int main(int argc, char *argv[])
{
  ros::init(argc,argv,"test_node");//初始化节点
  p_and_s SAPObject;//调用该类
  ros::spin();//一直在此处循环
  return 0;
}
