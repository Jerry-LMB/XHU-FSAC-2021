#include<iostream>
#include<serial/serial.h>
#include<geometry_msgs/Pose2D.h>
#include<geometry_msgs/Twist.h>
#include"InerNavi/InerNavi.h"
#include<cmath>
//#include<string>
InerNavi::InerNavi(uint32_t baudrate = 230400,uint16_t timeout = 1000)
:Baudrate(baudrate),Timeout(timeout)
    {
            PubPositon = nh.advertise<geometry_msgs::Pose2D>("/canalystii_ros/vehicle_Pose",50);
            PubStatus = nh.advertise<geometry_msgs::Twist>("/canalystii_ros/vehicle_spd",50);
            try 
            { 
                  //设置串口属性，并打开串口 
                  ser.setPort("/dev/ttyUSB4"); 
                  ser.setBaudrate(Baudrate); 
                  serial::Timeout to = serial::Timeout::simpleTimeout(Timeout); 
                  ser.setTimeout(to); 
                  ser.open(); 
            } 
            catch (serial::IOException& e) 
            { 
                  ROS_ERROR_STREAM("Unable to open port  !"); 
                  ros::shutdown();
            } 
            //检测串口是否已经打开，并给出提示信息 
            if(ser.isOpen()) 
            { 
                  ROS_INFO_STREAM("Serial Port initialized"); 
            } 
            else 
            { 
                  ROS_INFO_STREAM("unable to open serial port !"); 
                  ros::shutdown();
            }
            ros::Rate loop_rate(50);  
            while (ros::ok())
            {
                this->GetData();
                loop_rate.sleep();
            }
            ros::spin();
     }
void InerNavi::GetData()
{
    //获取缓冲区的字节数
                  size_t  n = ser.available();
                  if (n!=0)
                        {
                              uint8_t buffer[1024];
                              //读取数据
                              n = ser.read(buffer , n);
                              //std::cout<<"n = "<<n<<std::endl;
                              for(int i = 0;i < n; i++)//判断前三个buffer是否以0xbd,0xdb,0x0b开头
                              {
                                    init0 = (uint8_t)(buffer[i]&0xff);
                                    //std::cout<<init0<<" ";
                                    if(init0 == 0xbd && i+3 < n)
                                    {
                                          init1 = (uint8_t)(buffer[i+1]&0xff);
                                          init2 = (uint8_t)(buffer[i+2]&0xff);
                                          if(init1 == 0xdb && init2 == 0x0b )
                                          {
                                                if(i + length < n)
                                                {
                                                      count = i+3;
                                                      break;
                                                }
                                          }
                                    }
                              }
                              /*计算横滚角*/
                              roll = ((uint8_t)(buffer[count]&0xff))+((uint8_t)(buffer[count+1]&0xff))*256;//计算横滚角
                              if(roll< 32768)
                              {
                                    real_roll = roll;
                              }
                              else
                              {
                                    real_roll = roll-65536;
                              }
                              //real_roll = *((int16_t*)(&roll));
                              Roll = float(real_roll)*roll_factor;
                              /*计算俯仰角*/
                              Pitch_Anagle = ((uint8_t)(buffer[count+2]&0xff)) + ((uint8_t)(buffer[count+3]&0xff))*256; 
                              if(Pitch_Anagle < 32768)
                              {
                                    real_PitchAnagle = Pitch_Anagle;
                              }
                              else
                              {
                                    real_PitchAnagle = Pitch_Anagle -65536;
                              }
                              //real_PitchAnagle = *((int16_t*)(&Pitch_Anagle));
                              Pitch_Anagle =(float) real_PitchAnagle*roll_factor;
                              /*计算方位角*/
                              Course_Angle = ((uint8_t)(buffer[count+4]&0xff)) + ((uint8_t)(buffer[count+5]&0xff))*256;
                              if(Course_Angle < 32768 )
                              {
                                    real_CourseAngle = Course_Angle;
                              }
                              else
                              {
                                    real_CourseAngle = Course_Angle-65536;
                              }
                              //real_CourseAngle = *((int16_t*)(&Course_Angle));
                              Course_Angle = (float)real_CourseAngle * roll_factor;
                              if(Course_Angle > 180 || Course_Angle < 0)
                              {
                                    Course_Angle = 360+Course_Angle;
                              }
                              this->GPS_Theta2Map(Course_Angle);
                              /*计算x轴角速度*/
                              wx = ((uint8_t)(buffer[count+6]&0xff)) + ((uint8_t)(buffer[count+7]&0xff))*256;
                              if(wx < 32768)
                              {
                                    real_wx = wx;
                              }
                              else
                              {
                                    real_wx = wx - 65536;
                              }
                              //real_wx =  *((int16_t*)(&wx));
                              Wx = (float)real_wx * w_factor;
                              /*计算y轴角速度*/
                              wy = ((uint8_t)(buffer[count+8]&0xff)) + ((uint8_t)(buffer[count+9]&0xff))*256;
                              if(wy < 32768)
                              {
                                    real_wx= wy;
                              }
                              else
                              {
                                    real_wy = wy - 65536;
                              }
                              //real_wy =  *((int16_t*)(&wy));
                              Wy = (float)real_wy * w_factor;
                              /*计算z轴角速度*/
                              wz = ((uint8_t)(buffer[count+10]&0xff))+ ((uint8_t)(buffer[count+11]&0xff))*256;
                              if(wz < 32768)
                              {
                                    real_wz = wz;
                              }
                              else
                              {
                                    real_wz = wz - 65536;
                              }
                              //real_wz =  *((int16_t*)(&wz));
                              Wz = (float)real_wz * w_factor;
                              /*计算x轴加速度*/
                              ax = ((uint8_t)(buffer[count+12]&0xff)) + ((uint8_t)(buffer[count+13]&0xff))*256;
                              if(ax < 32768)
                              {
                                    real_ax = ax;
                              }
                              else
                              {
                                    real_ax = ax - 65536;
                              }
                              //real_ax =  *((int16_t*)(&ax));
                              Ax = (float)real_ax * a_factor;
                              /*计算y轴加速度*/
                              ay = ((uint8_t)(buffer[count+14]&0xff)) + ((uint8_t)(buffer[count+15]&0xff))*256; 
                              if(ay < 32768)
                              {
                                    real_ay = ay;
                              }
                              else
                              {
                                    real_ay = ay - 65536;
                              }
                              //real_ay =  *((int16_t*)(&ay));
                              Ay = (float)(real_ay )* a_factor;
                              /*计算z轴加速度*/
                              az = (((uint8_t)(buffer[count+16]&0xff))) + ((uint8_t)(buffer[count+17]&0xff))*256;
                              if(az < 32768)
                              {
                                    real_az = az;
                              }
                              else
                              {
                                    real_az = az-65536;
                              }
                              //real_az =  *((int16_t*)(&az));
                              Az = ((float)(real_az))* a_factor;
                              /*计算纬度*/
                              lat =  ((uint8_t)(buffer[count+18]&0xff)) + ((uint8_t)(buffer[count+19]&0xff))*256+ ((uint8_t)(buffer[count+20]&0xff))*256*256 + ((uint8_t)(buffer[count+21]&0xff))*256*256*256;
                              if(lat < 2147483648)
                              {
                                    real_lat = lat;
                              }
                              else
                              {
                                    real_lat = lat -4294967296;
                              }
                              //real_lat = *((int32_t*)(&lat));
                              Lat = (double)real_lat*Lat_factor;
                              /*计算经度*/
                              lon =  ((uint8_t)(buffer[count+22]&0xff))+ ((uint8_t)(buffer[count+23]&0xff))*256 + ((uint8_t)(buffer[count+24]&0xff))*256*256 + ((uint8_t)(buffer[count+25]&0xff))*256*256*256;
                              if(lon < 2147483648)
                              {
                                    real_lon = lon;
                              }
                              else
                              {
                                    real_lon = lon-4294967296;
                              }
                              //real_lon =  *((int32_t*)(&lon));
                              Lon = (double)real_lon*Lat_factor;
                              this->GPS2XY(Lat,Lon);//经纬度转xy
                              if((abs(Last_x - x) > 1000 || abs(Last_y - y) > 1000) && last_flag == 1)
                              {
                                    y = Last_y;
                                    x = Last_x;
                              }
                              Last_x = x;
                              Last_y = y;
                              /*计算高度*/
                              high =  ((uint8_t)(buffer[count+26]&0xff)) + ((uint8_t)(buffer[count+27]&0xff))*256+ ((uint8_t)(buffer[count+28]&0xff))*256*256 + ((uint8_t)(buffer[count+29]&0xff))*256*256*256;
                              if(high < 21474483648)
                              {
                                    real_high = high;
                              }
                              else
                              {
                                    real_high = high-4294967296;
                              }
                              //real_high = *((int32_t*)(&high));
                              High = (double)real_high*high_factor;
                              /*计算北方速度*/
                              vn = ((uint8_t)(buffer[count+30]&0xff)) + ((uint8_t)(buffer[count+31]&0xff))*256;
                              if(vn < 32768)
                              {
                                    real_vn = vn;
                              }
                              else
                              {
                                    real_vn = vn - 65536;
                              }
                              //real_vn =  *((int16_t*)(&vn));
                              Vn = (float)real_vn* v_factor;
                              /*计算东方速度*/
                              ve = ((uint8_t)(buffer[count+32]&0xff)) + ((uint8_t)(buffer[count+33]&0xff))*256;
                              if (ve < 32768)
                              {
                                    real_ve = ve;
                              }
                              else
                              {
                                    real_ve = ve -65536;
                              }
                              //real_ve =  *((int16_t*)(&ve));
                              Ve = (float)real_ve* v_factor; 
                              this->Speed_Transfor(theta);//东方速度、北方速度转vx、vy
                              if(abs(vx - last_vx) > 5 && spd_flag == 1)
                              {
                                    vx = last_vx;
                              }
                              last_vx = vx;
                              if(abs(vy-last_vy) > 2 && spd_flag == 1)
                              {
                              vy = last_vy;
                              }
                              last_vy = vy;
                              //计算向地速度
                              vz = ((uint8_t)(buffer[count+34]&0xff))*256 + ((uint8_t)(buffer[count+35]&0xff));
                              if (vz < 32768)
                              {
                              real_vz = vz;
                              }
                              else
                              {
                              real_vz = vz - 65536;
                              }
                              // real_vz =  *((int16_t*)(&vz));
                              Vz = (float)real_vz* v_factor;                    
                              //反馈惯导状态
                              // status = ((uint8_t)(buffer[count+36]&0xff));
                              // real_status = *((int8_t*)(&status));
                              // Status = real_status;
                              ROS_INFO("x = %.7f,y = %.7f,vx = %.3f,vy = %.3f,Course_Angle = %.3f",x,y,vx,vy,theta);
                              geometry_msgs::Pose2D pose;
                              pose.x = x;
                              pose.y = y;
                              pose.theta = theta;
                              geometry_msgs::Twist STATUS;
                              STATUS.linear.x = vx;
                              STATUS.linear.y = vy;
                              STATUS.linear.z = Vz;
                              STATUS.angular.x = Wz;
                              STATUS.angular.y = Az;
                              STATUS.angular.z = Ay;
                              PubPositon.publish(pose);
                              PubStatus.publish(STATUS);                         
                  }
                  if((x >xmin &&x <xmax)  && (y>ymin && y < ymax)) 
                  {
                        last_flag = 1;
                        spd_flag = 1;
                  }
                  else
                  {
                        last_flag = 0;
                        spd_flag = 0;
                  }
                  count = 0;
}
//转换经纬度函数
void InerNavi::GPS2XY(const double &lat,const double &lon)
//void gps2xy(const double &lat,const double &lon)
{
      ZoneNumber = (int)((lon - 1.5)/3.0)+1;
      L0 = ZoneNumber*3.0;
      B = lat * KD2R;
      L = lon * KD2R;
      L0 = L0 * KD2R;
      l = L - L0;
      cl = (cos(B ) * l);
      cl2 = (cl * cl); 
      cl3 = (cl2 * cl); 
      cl4 = (cl2 * cl2); 
      cl5 = (cl4 * cl); 
      cl6 = (cl5 * cl); 
      cl7 = (cl6 * cl); 
      cl8 = (cl4 * cl4);
      lB = al * (B + bt * sin(2 * B ) + gm * sin(4 * B ) + dt * sin(6 * B ) + ep * sin(8 * B ));
      t = tan(B); 
      t2 = (t * t); 
      t4 = (t2 * t2); 
      t6 = (t4 * t2);
      Nn = a / sqrt(1 - ee * sin(B) * sin(B));
      yt = e2 * cos(B) * cos(B);
      N = lB;
      N = N + t * Nn * cl2 / 2;
      N = N + t * Nn * cl4 * (5 - t2 + 9 * yt + 4 * yt * yt) / 24;
      N = N + t * Nn * cl6 * (61 - 58 * t2 + t4 + 270 * yt - 330 * t2 * yt) / 720;
      N = N + t * Nn * cl8 * (1385 - 3111 * t2 + 543 * t4 - t6) / 40320;
      E = Nn * cl;
      E = E + Nn * cl3 * (1 - t2 + yt) / 6;
      E = E + Nn * cl5 * (5 - 18 * t2 + t4 + 14 * yt - 58 * t2 * yt) / 120;
      E = E + Nn * cl7 * (61 - 479 * t2 + 179 * t4 - t6) / 5040;
      E = E + 500000;
      y = 1 * N;//%0.9996
      x = 1 * (E - 500000.0) + 500000.0;
}
//航向角转换函数
void InerNavi::GPS_Theta2Map(const float &gps_theta)
//void GPS_Theta2Map_Theta(const float &gps_theta)
{
      if(gps_theta <= 90)
      theta = 90 - gps_theta;
      else if (gps_theta > 90)
      theta = 90 - gps_theta + 360; 
}
//Vx,Vy获取函数
void InerNavi::Speed_Transfor(const float &theta)
//void Spd_Transfor(const float &theta)
{
      vx = Vn*sin(theta*KD2R) + Ve*cos(theta*KD2R);
      vy = Vn*cos(theta*KD2R) - Ve*sin(theta*KD2R);
}


int main (int argc, char** argv) 
{ 
    //初始化节点 
    ros::init(argc, argv, "InerNavigation"); 
    InerNavi  InerNavigation;
    return 0;
}
