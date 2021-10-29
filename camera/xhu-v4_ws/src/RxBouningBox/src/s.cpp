/******************************************************
#功能对坐标系进行转换后存储
＃作者：朱兴建,李美斌
世界坐标系正北为Ｙ，正东为Ｘ，载体坐标系　前进方向为Ｙ，与Ｙ垂直的右边为Ｘ．
航向角是以正东方向（Ｘ），到前进方向的夹角，逆时针方向
车身坐标系是以车头前进方向为x，左边为y，跟摄像头有一个90度的转换
******************************************************/
#include<ros/ros.h>
#include<vector>
#include<iostream>
#include <cmath>
#include "darknet_ros_msgs/BoundingBoxes.h"
#include "darknet_ros_msgs/BoundingBox.h"
#include <geometry_msgs/Pose2D.h>
#include <iomanip>
#include<geometry_msgs/Pose.h>
#include<geometry_msgs/PoseArray.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include<std_msgs/UInt8.h>
const float D2R = 3.1415926/180;
const float dd = 0.22;//转换车身坐标
class Position
{
  public:
  double x = 0.0;
  double y = 0.0;
};//申明位置类，用来储存绝对的坐标点
double X = 0.0;//定义的绝对坐标X;
double Y = 0.0;//定义的绝对坐标X;
float  theta = 0.0;//定义航向角;
double  x = 0.0;//定义的车身坐标ｘ;是以车头的前进方向为x,左边为y,
double  y = 0.0;
double g_x = 0.0;
double g_y = 0.0;//设置的一进循环就直接把值转化为绝对坐标系
uint8_t r_flag = 0;//定义的比较存入标志位，置1才存入
uint8_t b_flag = 0;
uint8_t c_flag = 0;
uint8_t y_flag = 0;
uint8_t t_flag = 0;//黄色给中心点标志位
std::vector<Position> red;//定义的vector数组类，来储存左边和右边的距离值，不同的值
std::vector<Position> blue;
std::vector<Position> yellow;
uint8_t FPS = 0;//计算帧数第一帧
uint8_t count1 = 0;//第一帧标志位 blue是1，5
uint8_t count2 = 0;//red是2，4
uint8_t count3 = 0;//中心点存入
uint8_t count4 = 0;//红蓝锥桶储存比较位 当红蓝都有新的进来时，进行求平均值
uint8_t count5 = 0;
uint8_t count6 = 0;//yellow是6
uint8_t count7 = 0;//黄色给中心点是7
uint8_t bflag = 0;//设置的循环遍历的存储标志位
uint8_t rflag = 0;//red
uint8_t yflag = 0;//yellow
uint8_t cflag = 0;//center
uint8_t tflag =0;
uint8_t slam_begin = 0;  //建图完成存入点标志位
uint8_t slam_over = 0;
uint8_t no_save = 0;
uint8_t track_1 = 0;
uint8_t track_2 =0;
uint8_t test = 0;//存点标志位
uint8_t track_last =0;
uint8_t circle =0;
Position red_;//申明类的对象left_和right_
Position blue_;
Position yellow_;
/* 比较函数对检测的锥桶点进行储存*/
class p_and_s
{ 
   private:
    ros::NodeHandle nh;
    ros::Publisher Pub_point;
    ros::Publisher Pub_stop;
    ros::Subscriber Sub_imu;
    ros::Subscriber Sub_BX; 
    geometry_msgs::PoseArray  center;
    geometry_msgs::Pose p;//中心点数组
    std_msgs::UInt8 stop_flag;//加速停止标志位
  public:
  p_and_s()
  {
   Pub_point = nh.advertise<geometry_msgs::PoseArray>("/point",50);//发布中心点话题 
   Pub_stop = nh.advertise<std_msgs::UInt8>("/stop",50);//发布停止加速标志位话题
   Sub_imu = nh.subscribe("/canalystii_ros/vehicle_Pose",50,&p_and_s::CallBack_GPS,this);
   Sub_BX = nh.subscribe("/darknet_ros/bounding_boxes",50,&p_and_s::CallBack,this);
  }
  void CallBack_GPS(const geometry_msgs::Pose2D::ConstPtr &msg)
{
  Y = msg->y;
  X = msg->x;
  theta = msg->theta;
}
void CallBack(const darknet_ros_msgs:: BoundingBoxes::ConstPtr & msg)
{
  if(FPS == 1 && count1 !=0 )
  {
    b_flag = 1;
    count1 = 0;
  }
  if(FPS == 1 && count2 !=0)
  {
    r_flag = 1;
    count2 = 0;
  }
  if(FPS == 1 && count3 !=0)
  {
    c_flag = 1;
    count3 = 0;
  }
  if(FPS == 1 && count6 !=0)
  {
    y_flag = 1;
    count6 = 0;
  }
  if(FPS == 1 && count7 !=0)
  {
    t_flag = 1;
    count7 = 0;
  }//只进一次，来储存第一帧的点
  for (uint8_t i = 0; i < msg->bounding_boxes.size(); i++)
  { 
    if((msg->bounding_boxes[i].Class == "red") == 1 && msg->bounding_boxes[i].ymax >=300 && X > 0)//改为订阅颜色来存储
    {     
      x = (msg->bounding_boxes[i].distancey)/100.0-dd;//将每次来的值从相机坐标系转化为车身坐标系，并且将距离单位转化为m
      y = -(msg->bounding_boxes[i].distancex)/100.0;
      g_x = X + x*cos(theta*D2R) - y*sin(theta*D2R);//将进来的值，转化为绝对坐标系
      g_y = Y + y*cos(theta*D2R) + x*sin(theta*D2R);
      if (r_flag == 0 )//将来的第一帧，近的框的坐标直接放入，vector里面
      { 
        red_.x =  g_x;
        red_.y =  g_y;
        red.push_back(red_);
        count2 = 1;
      }
      if (r_flag ==1 )//走第二帧开始，来的的每一个点，都去与vector数组里面的每一个值比较，只要有一个距离小于2，将存入标志位值1，并退出循环且这个点不放入ｖｅｃｔｏｒ
      { 
        for (std::vector<Position>::iterator it = red.begin();it!= red.end();it++)//循环遍历比较
          {
            if (pow(((*it).x - g_x),2) + pow(((*it).y - g_y),2) < 4 )
            {
              (*it).x = ((*it).x + g_x)/2;
              (*it).y = ((*it).y + g_y)/2;//每次对最新的点，取平均值
              rflag = 1;
              break;
            }            
          }
          if(rflag == 0)//当来的点，都不满足上面的条件时．rflag = 0,将此点存入
          {
            red_.x = g_x;//将识别的坐标点转换到绝对坐标系
            red_.y = g_y;
            red.push_back(red_); 
            count4 = 1;
          }
      }
    }   
    ///红色改  结束****************************************//////////////////////////////////////
    if ((msg->bounding_boxes[i].Class == "blue") == 1  && msg->bounding_boxes[i].ymax >= 300 && X > 0 )
    {
      x = (msg->bounding_boxes[i].distancey)/100.0-dd;//将每次来的值从相机坐标系转化为车身坐标系，并且将距离单位转化为m
      y = -(msg->bounding_boxes[i].distancex)/100.0;
      g_x = X + x*cos(theta*D2R) - y*sin(theta*D2R);//将进来的值，转化为绝对坐标系
      g_y = Y + y*cos(theta*D2R) + x*sin(theta*D2R);
     if (b_flag == 0)
      {
        blue_.x = g_x;//将识别的坐标点转换到绝对坐标系
        blue_.y = g_y;
        blue.push_back(blue_);
        count1 = 1;  //将来的第一帧存入去
      } 
      if (b_flag ==1)
      { 
          for (std::vector<Position>::iterator it = blue.begin();it!= blue.end();it++)
          {
            if (pow(((*it).x - g_x),2) + pow(((*it).y - g_y),2) < 4 )
            {
            (*it).x = ((*it).x + g_x)/2;//每次将距离小的点，进 行均值求解
            (*it).y = ((*it).y + g_y)/2;
              bflag = 1;
              break;
            }
          }
          if(bflag == 0)
          {
            blue_.x = g_x;//将最新的点，存入vector中
            blue_.y = g_y;
            blue.push_back(blue_);
            count5 = 1;
          }
      } 
    } 
    //加入黄色停车标志
    if ((msg->bounding_boxes[i].Class == "yellow") == 1  && msg->bounding_boxes[i].ymax >= 300 && X > 0)
    {
      x = (msg->bounding_boxes[i].distancey)/100.0-dd;//将每次来的值从相机坐标系转化为车身坐标系，并且将距离单位转化为m
      y = -(msg->bounding_boxes[i].distancex)/100.0;
      g_x = X + x*cos(theta*D2R) - y*sin(theta*D2R);//将进来的值，转化为绝对坐标系
      g_y = Y + y*cos(theta*D2R) + x*sin(theta*D2R);
      if (y_flag == 0)
      {
        yellow_.x = g_x;//将识别的坐标点转换到绝对坐标系
        yellow_.y = g_y;
        yellow.push_back(yellow_);
        count6 = 1; //将来的第一帧存入去
      } 
      if (y_flag ==1)
      { 
          for (std::vector<Position>::iterator it = yellow.begin();it!= yellow.end();it++)
          {
            if (pow(((*it).x - g_x),2) + pow(((*it).y - g_y),2) < 2 )
            {
            // (*it).x = ((*it).x + g_x)/2;//每次将距离小的点，进 行均值求解
            // (*it).y = ((*it).y + g_y)/2;
              yflag = 1;
              break;
            }
          }
          if(yflag == 0)
          {
            yellow_.x = g_x;//将最新的点，存入vector中
            yellow_.y = g_y;
            yellow.push_back(yellow_);
          }
      } 
    }   
    } //储存点 到这里结束
    ///////////// 下面开始就是存储和偏移的中心点///////////////////////////////////////
     if (yellow.size() ==4 && X >0)//到时候改成四个点的黄色
      {
        if (t_flag == 0)
        {      
        p.position.x = X;
        p.position.y = Y;
        center.poses.push_back(p);
        p.position.x = (yellow[0].x+yellow[1].x+yellow[2].x+yellow[3].x)/4;
        p.position.y =  (yellow[0].y+yellow[1].y+yellow[2].y+yellow[3].y)/4;
        //  p.position.x = (yellow[yellow.size()-1].x+yellow[yellow.size()-2].x)/2;
        //  p.position.y =  (yellow[yellow.size()-1].y+yellow[yellow.size()-2].y)/2;
        center.poses.push_back(p);
        count7 = 1;
        test =1;
        }
        if (t_flag == 1)
        {
          //此时黄色储存完毕
        }
      }
      //黄色给点完毕/////////////////////////////////
      //重心给点法//////////////////
    if (blue.size() >=1 &&red.size()>=1 && X >0)
    {
      //  x = (blue[blue.size()-1].x  + blue[blue.size()-2].x + red[red.size()-1].x + red[red.size()-2].x)/4;
      //  y = (blue[blue.size()-1].y + blue[blue.size()-2].y + red[red.size()-1].y + red[red.size()-2].y)/4;//利用重心法进行点的发布
       //求平均值
       x = (blue[blue.size()-1].x  + red[red.size()-1].x)/2;
       y = (blue[blue.size()-1].y  + red[red.size()-1].y)/2;
       if (c_flag == 0)
       {
        // p.position.x = X;
        // p.position.y = Y;
        // center.poses.push_back(p);
        p.position.x = x;
        p.position.y = y;
        center.poses.push_back(p);
        count3 = 1;
        //  test =1;
       }
    if (c_flag ==1)
        { 
          for (auto it = center.poses.begin();it!= center.poses.end();it++)
          {
            if (pow(((*it).position.x - x),2) + pow(((*it).position.y - y),2) < 7 )
            {
              // (*it).position.x = ((*it).position.x + c_x)/2;
              // (*it).position.y = ((*it).position.y + c_y)/2;
              cflag = 1;
              break;
            }
          }
          if(cflag == 0 && count4 == 1 && count5 == 1 && no_save ==0)
          {
            std::cout<<"储存点"<<std::endl;
            p.position.x = x;//将最新的点，存入vector中
            p.position.y = y;
            center.poses.push_back(p);
            count4 = 0;
            count5 = 0;
          }
        } 
    }
    //高速寻迹停止记圈代码***********************************************///////////////////////////////////////
    
    if (test ==1)
    {
        if ( pow((X - center.poses[0].position.x),2) + pow((Y - center.poses[0].position.y),2) >= 36 && circle ==0)
      {
        slam_begin = 1;
        circle = 1;
        std::cout<<"建图开始2222"<<std::endl;
      }
  if (slam_begin == 1 && pow((X - center.poses[0].position.x),2) + pow((Y - center.poses[0].position.y),2) <= 36 && circle==1)
      {
        p.position.x = center.poses[0].position.x;
        p.position.y = center.poses[0].position.y;
        center.poses.push_back(p);
        p.position.x = center.poses[1].position.x;
        p.position.y =  center.poses[1].position.y;
        center.poses.push_back(p);
        p.position.x = center.poses[2].position.x;
        p.position.y =  center.poses[2].position.y;
        center.poses.push_back(p);
        circle = 2;
        slam_over =1;//建图完成，不再存入新的点
        no_save = 1;//此时不再存入新的点
        stop_flag.data = 2;//z等于2时，就开始提速
        std::cout<<"z= "<< stop_flag.data<<std::endl;
        std::cout<<"建图结束3333"<<std::endl;
      }
  if (slam_over == 1 && pow((X - center.poses[0].position.x),2) + pow((Y - center.poses[0].position.y),2) >= 36)
      {
        track_1 = 1;
      }
  if (track_1 == 1 && pow((X - center.poses[0].position.x),2) + pow((Y - center.poses[0].position.y),2) <= 9)
      {
        track_2 =1;
      }
  if (track_2 == 1 && pow((X - center.poses[0].position.x),2) + pow((Y - center.poses[0].position.y),2) >= 36)
      {
        track_last =1;
      }
  if (track_last ==1 && pow((X - center.poses[0].position.x),2) + pow((Y - center.poses[0].position.y),2) <= 9)
      {
        for (uint8_t i = 0; i < msg->bounding_boxes.size(); i++)
         {
           if ((msg->bounding_boxes[i].Class == "yellow") == 1 && msg->bounding_boxes[i].distancey <= 500)
           {
            stop_flag.data = 1;//z 至1就是停止标志位
           }
         }
      }
    }
    //***************************************///////////////结束  ////////////////
    //经过上面两次判断，直接就能把偏移的中心点，存入center中
    for (std::vector<Position>::iterator it = red.begin();it!= red.end();it++)
      {
        std::cout<<red.size()<<" ";
        std::cout<<"red_x = "<<std::setprecision(8)<<(*it).x<<" ";
        std::cout<<"red_y = "<<std::setprecision(9)<<(*it).y<<std::endl;
      }
    for (std::vector<Position>::iterator it = blue.begin();it!= blue.end();it++)
      {
        std::cout<<blue.size()<<" ";
        std::cout<<"blue_x = "<<std::setprecision(8)<<(*it).x<<" ";
        std::cout<<"blue_y = "<<std::setprecision(9)<<(*it).y<<std::endl;
      }//每次一帧来循环完之后，打印vector数组里面的值,剔除了相同的点
    for (auto it = center.poses.begin();it!= center.poses.end();it++)
      {
        std::cout<<center.poses.size()<<" ";
        std::cout<<"center_x = "<<std::setprecision(8)<<(*it).position.x<<" ";
        std::cout<<"center_y = "<<std::setprecision(9)<<(*it).position.y<<std::endl;
      }
      FPS = 1;
      bflag = 0;
      rflag = 0;
      cflag = 0;
      yflag =0;//循环完了，之后将标志位清零
      std::cout<<"一帧结束 = "<<std::endl;  
      Pub_point.publish(center);
      Pub_stop.publish(stop_flag);// publish 
}
};
int main(int argc, char **argv)
{
  ros::init(argc,argv,"S_node");//  初始化节点
  ros::NodeHandle nh; //申明句柄节点
  p_and_s SAPObject; //运行整个主函数，接受数据处理后发布出去
  ros::spin(); //循环等待
  return 0;
}
