#include "canalystii_ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"
#include <iostream>
#include<math.h>
canalystii_ros::canalystii_ros(int vci_device_type, int vci_device_ind) : 
CANalystii(vci_device_type,vci_device_ind), node_handle_("~")
    {
        ROS_INFO("Inititalizing canalystii_ros.");
        int start_device_ = start_device();
        if(start_device_ == 0){
            ROS_ERROR("Start device error, please check usb cable or replug usb cable!");
            ros::shutdown();
        }
	
        /*
        else if(start_device_ == -1){
            ROS_ERROR("VIN check fail, please check device VIN or contact maintainer for help!");
            ros::shutdown();
        }
        */
        //initialize port 0
        VCI_INIT_CONFIG vci_conf;
        vci_conf.AccCode = 0x00000000;
        vci_conf.AccMask = 0xFFFFFFFF;
        vci_conf.Filter = 1;//receive all frames
        vci_conf.Timing0 = 0x01;
        vci_conf.Timing1 = 0x1C;//波特率 250kbps
        vci_conf.Mode = 0;//normal mode
        unsigned int can_idx = 0;
        if(!init_can_interface(can_idx,vci_conf)){
            ROS_ERROR("port 0 init error");
            ros::shutdown();
        }
        else
        {
            ROS_INFO("port 0 intialized!");
        }
        //initialize port 1
        can_idx=!can_idx;//change to port 1
	    vci_conf.Timing0=0x00;//波特率500 Kbps 
        vci_conf.Timing1 = 0x1C;
        if(!init_can_interface(can_idx,vci_conf)){
            ROS_ERROR("port 1 init error");
            ros::shutdown();
        }
        else
        {
            ROS_INFO("port 1 intialized!");
        }

        node_handle_.param<std::string>("can_msg_sub_port0_topic_", can_msg_sub_port0_topic_, "/send_can_msgs_port0");
        ROS_INFO("port 0 can msg receive from topic: %s .", can_msg_sub_port0_topic_.c_str());
        node_handle_.param<std::string>("can_msg_sub_port1_topic_", can_msg_sub_port1_topic_, "/send_can_msgs_port1");
        ROS_INFO("port 1 can msg receive from topic: %s .", can_msg_sub_port1_topic_.c_str());
        node_handle_.param<std::string>("can_msg_pub_topic_port0", can_msg_pub_topic_port0, "/received_can_msgs_port0");
        ROS_INFO("can msgs on port 0 will be published to topic: %s .", can_msg_pub_topic_port0.c_str());
        node_handle_.param<std::string>("can_msg_pub_topic_port1", can_msg_pub_topic_port1, "/received_can_msgs_port1");
        ROS_INFO("can msgs on port 1 will be published to topic: %s .", can_msg_pub_topic_port1.c_str());
                

        can_msg_pub_port0_  = node_handle_.advertise<std_msgs::Int16MultiArray >(can_msg_pub_topic_port0.c_str(), 50);
        can_msg_pub_port1_  = node_handle_.advertise<std_msgs::Int16MultiArray >(can_msg_pub_topic_port1.c_str(), 50);
        
	     //veh_pose = node_handle_.advertise<geometry_msgs::Pose2D>("vehicle_Pose",50);
	     //veh_spd = node_handle_.advertise<geometry_msgs::Twist>("vehicle_spd",50);
        sub_can_msg_port0_ = node_handle_.subscribe(can_msg_sub_port0_topic_.c_str(), 100, &canalystii_ros::sub_can_msg_port0_Callback, this);
        sub_can_msg_port1_ = node_handle_.subscribe(can_msg_sub_port1_topic_.c_str(), 100, &canalystii_ros::sub_can_msg_port1_Callback, this);

        receive_timer = node_handle_.createTimer(ros::Duration(0.01), &canalystii_ros::receivetimerCallback, this);//10ms cycle receive
        send_timer = node_handle_.createTimer(ros::Duration(0.05), &canalystii_ros::sendtimerCallback, this);//100ms cycle send
    }

void canalystii_ros::sub_can_msg_port0_Callback(const std_msgs::Int16MultiArray & input)
   {
        if(input.data.size() < 3)
        {
           ROS_ERROR("can msg data too short, Please check topic: %s !!!", can_msg_sub_port0_topic_.c_str());
           
           return;
        }
       //sending Standard frame to port 0
        int can_idx=0;
        int send_len = 1;
        std_msgs::Int16MultiArray  msg_send;
        msg_send = input;     

        if(send_can_frame(can_idx, msg_send, send_len)) ;//ROS_INFO("port 0 send frame succeed!");
        else  ROS_WARN("port 0 send frame failed!");

   }

void canalystii_ros::sub_can_msg_port1_Callback(const std_msgs::Int16MultiArray & input)
   {
        if(input.data.size() < 3)
        {
           ROS_INFO("data.size = :%d",input.data.size());
           ROS_ERROR("can msg data too short, Please check topic: %s !!!", can_msg_sub_port1_topic_.c_str());
           return;
        }
       //sending Standard frame to port 1
        int can_idx=1;
        int send_len = 1;
        std_msgs::Int16MultiArray  msg_send;
        msg_send = input;     

        if(send_can_frame(can_idx, msg_send, send_len)) ;//ROS_INFO("port 1 send frame succeed!");
        else  ROS_WARN("port 1 send frame failed!");

   }
void canalystii_ros::sendtimerCallback(const ros::TimerEvent&)
   {

   }



void canalystii_ros::receivetimerCallback(const ros::TimerEvent&)
   {
      int can_idx=1;
      unsigned int recv_len = 1000;//can length
	   unsigned int recv_id = 0u; //can id
	   unsigned int canid_index;

      std_msgs::Int16MultiArray  msg[1000];
	   std_msgs::Int16MultiArray  msg_temp;
      int len = receive_can_frame(can_idx,msg,recv_len,100); //read can msg
	for(int i=0;i<len;i++)
	{	
	std_msgs::Int16MultiArray  msg_temp = msg[i];
	
	recv_id = msg_temp.data[0];//catch canid
	//ROS_INFO("canid: %d\r\n",recv_id);
  //std::cout<<std::hex<<recv_id<<std::endl;

	if(recv_id == 0x706) canid_index = 1u;
	else if(recv_id == 0x703) canid_index = 2u;
   else if(recv_id == 0x705) canid_index = 3u;
   else if(recv_id == 0x721) canid_index = 4u;
	else if(recv_id == 0x723) canid_index = 5u;
	else
       {
         canid_index = 0u;
	   }
	switch(canid_index)
	{
		case 1: //收到航向角报文
		psi = (uint8_t)((msg_temp.data[4]>>4) | (msg_temp.data[3]<<4)) + ((uint8_t)((msg_temp.data[3]>>4)|(msg_temp.data[2]<<4)))*256 + ((uint8_t)(msg_temp.data[2]>>4))*256*256;
      psi = (float)psi*0.001f;
      std::cout<<std::hex<<msg_temp.data[0]<<" "<<std::hex<<msg_temp.data[2]<<" "<<std::hex<<msg_temp.data[3]<<" "<<std::hex<<(msg_temp.data[4])<<std::endl;
      ROS_INFO("pis = %f",psi);
		this->GPS_Theta2Map_Theta(psi);
		break;
		case 2: //收到经纬度报文(融合惯导前的gps数据)	//ROS_INFO("msg_temp.data[0] = %d,msg_temp.data[1] = %d,msg_temp.data[2] = %d,msg_temp.data[3] = %d,msg_temp.data[4] = %d,msg_temp.data[5] = %d",msg_temp.data[0],msg_temp.data[1],msg_temp.data[2],msg_temp.data[3],msg_temp.data[4],msg_temp.data[5]);
      //std::cout<<std::hex<<msg_temp.data[0]<<" "<<std::hex<<msg_temp.data[1]<<" "<<std::hex<<msg_temp.data[2]<<" "<<std::hex<<msg_temp.data[3]<<" "<<std::hex<<msg_temp.data[4]<<" "<<std::hex<<msg_temp.data[5]<<" "<<std::hex<<msg_temp.data[6]<<" "<<std::hex<<msg_temp.data[7]<<" "<<std::hex<<msg_temp.data[8]<<std::endl;
      lat_temp =(long long int )(msg_temp.data[5]) + (long long int)(msg_temp.data[4] *256) + (long long int)(msg_temp.data[3] *65536) + (long long int)(msg_temp.data[2] * 16777216 );
      //std::cout<<"lat_temp = "<<lat_temp<<std::endl;
      if(lat_temp > (4294967296/2))
			{
            //std::cout<<1111<<std::endl;
			   Lat_temp = lat_temp - 4294967296;
            //std::cout<<"Lat_temp = "<<Lat_temp<<std::endl;
			} 
         else
         {
            Lat_temp = lat_temp;
         }
		lat = (double)(Lat_temp) *0.0000001f;
      ROS_INFO("lat = %.3f",lat);
      lon_temp =((long long int)msg_temp.data[9] + ((long long int)msg_temp.data[8]) *256 + ((long long int)(msg_temp.data[7])) *65536 + ((long long int)(msg_temp.data[6])) * 16777216 );
      if(lon_temp > 4294967296/2)
			{
			   Lon_temp = lon_temp - 4294967296;
			}
         else
         {
            Lon_temp = lon_temp;
         }
		lon = (double)(Lon_temp) *0.0000001f;
      ROS_INFO("lon = %.3f",lon);
		this->gps2xy(lat,lon);
		break;
		case 3: //收到三方速度报文
			ve_temp = (long long int)msg_temp.data[3] + (long long int)(msg_temp.data[2] *256);
         //std::cout<<"ve_temp = "<<ve_temp<<std::endl;
         //std::cout<<std::hex<<msg_temp.data[0]<<" "<<std::hex<<msg_temp.data[1]<<" "<<std::hex<<msg_temp.data[2]<<" "<<std::hex<<msg_temp.data[3]<<" "<<std::hex<<msg_temp.data[4]<<" "<<std::hex<<msg_temp.data[5]<<" "<<std::hex<<msg_temp.data[6]<<" "<<std::hex<<msg_temp.data[7]<<" "<<std::hex<<msg_temp.data[8]<<" "<<std::hex<<msg_temp.data[9]<<std::endl;
			if (ve_temp >32768u)
			{
			   Ve_temp = ve_temp -65536;
			}
         else
         {
            Ve_temp = ve_temp;
         }
			ve = (float)(Ve_temp) * 0.01f;
			vn_temp= (long long int)msg_temp.data[5] + (long long int)msg_temp.data[4] * 256;
			 if (vn_temp >32768u)
			{
			   Vn_temp = vn_temp -65536u;
			}
         else
         {
            Vn_temp = vn_temp;
         }	
			vn = (float)(Vn_temp) * 0.01f;
		break;
		case 4: 
			ax_temp =((long long int)msg_temp.data[5] + ((long long int)msg_temp.data[4]) *256 + ((long long int)(msg_temp.data[3])) *65536 + ((long long int)(msg_temp.data[2])) * 16777216 );
         ay_temp = ((long long int)msg_temp.data[9] + ((long long int)msg_temp.data[8]) *256 + ((long long int)(msg_temp.data[7])) *65536 + ((long long int)(msg_temp.data[6])) * 16777216 );
			if(ax_temp > 4294967296/2)
			{
			   Ax_temp = ax_temp - 4294967296;
		
			}
         else
         {
            Ax_temp = ax_temp;
         }
         if(ay_temp > 4294967296/2)
			{
			   Ay_temp = ay_temp - 4294967296;
		
			}
         else
         {
            Ay_temp = ay_temp;
         }
			ax = (float)(Ax_temp) *1/7000000.0;
         ay = (float)(Ay_temp) *1/7000000.0;
		break;
		case 5://收到高度报文
			wz_temp =  ((long long int)msg_temp.data[9] + ((long long int)msg_temp.data[8]) *256 + ((long long int)(msg_temp.data[7])) *65536 + ((long long int)(msg_temp.data[6])) * 16777216 );
        //std::cout<<"wz_temp = "<<std::endl;
         if(wz_temp > 4294967296/2)
			{
			   Wz_temp = wz_temp - 4294967296;
			}
         else
         {
            Wz_temp = wz_temp;
         }
         wz = (float)(Wz_temp)*1/7000000.0f;
		break;
		default:
		break;
	}
	this->Spd_Transfor(theta);
	geometry_msgs::Pose2D Pose_msg;
	Pose_msg.x = x;
	Pose_msg.y = y;
	Pose_msg.theta = theta;
	//veh_pose.publish(Pose_msg);
	

	geometry_msgs::Twist Spd_msg;
	Spd_msg.linear.x = vx;
	Spd_msg.linear.y = vy;
	Spd_msg.linear.z = wz;
	//veh_spd.publish(Spd_msg);
	//ROS_INFO("Vehicle Pose: lat = %0.7f, lon = %0.7f, psi = %0.3f\r\nVehcile Spd: ve =%0.3f, vn=%0.3f,wz=%0.3f\r\n", Pose_msg.x , Pose_msg.y , Pose_msg.theta , Spd_msg.linear.x , Spd_msg.linear.y , Spd_msg.linear.z);
	}
      /*  for(int i =0; i<len; i++)
        {
            //ROS_INFO("port 0 received!");
            std_msgs::Int16MultiArray  msg_temp = msg[i]; //current msg

	
	    
           if(msg_temp.data[0] == 0x50 and msg_temp.data[2] == 0x55 and msg_temp.data[3] == 0x51)
            {
                frame_50_51 = msg_temp;
                frame_50_51_initialized = true;
            }
            else if(msg_temp.data[0] == 0x50 and msg_temp.data[2] == 0x55 and msg_temp.data[3] == 0x52 and frame_50_51_initialized)
            {
                std_msgs::Int16MultiArray  new_frame_50_50;
                new_frame_50_50 = msg_temp;
                new_frame_50_50.data[0] = 0x50;
                new_frame_50_50.data[1] = 8;
                new_frame_50_50.data[2] = 0x55;
                new_frame_50_50.data[3] = 0x50;
                new_frame_50_50.data[4] = frame_50_51.data[4];
                new_frame_50_50.data[5] = frame_50_51.data[5];
                new_frame_50_50.data[6] = frame_50_51.data[6];
                new_frame_50_50.data[7] = frame_50_51.data[7];
                new_frame_50_50.data[8] = msg_temp.data[8];
                new_frame_50_50.data[9] = msg_temp.data[9];
	
                // if(send_can_frame(can_idx, new_frame_50_50, 1)) ;//ROS_INFO("port 1 send frame 0x50 succeed!");
                // else  ROS_WARN("port 1 send frame 0x50 failed!");
                new_frame_50_50.layout.dim[0].label = "can0";
                can_msg_pub_port0_.publish(new_frame_50_50);
            }
            else
            {
                msg_temp.layout.dim[0].label = "can0";
                can_msg_pub_port0_.publish(msg_temp);
            }

        }
*/
        can_idx=!can_idx;//change to port 1
        len = receive_can_frame(can_idx,msg,recv_len,100);

        for(int i =0; i<len; i++)
        {
            //ROS_INFO("port 1 received!");
            std_msgs::Int16MultiArray  msg_temp = msg[i];
            msg_temp.layout.dim[0].label = "can1";
            can_msg_pub_port1_.publish(msg_temp);
        }
   }
//转换经纬度函数
void canalystii_ros::gps2xy(const double &lat,const double &lon)
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
}//航向角转换函数
void canalystii_ros::GPS_Theta2Map_Theta(const float &gps_theta)
{
 if(gps_theta <= 90)
  theta = 90 - gps_theta;
 else if (gps_theta > 90)
   theta = 90 - gps_theta + 360; 
}
//Vx,Vy获取函数
void canalystii_ros::Spd_Transfor(const float &theta)
{
  vx = vn*sin(theta*KD2R)+ve*cos(theta*KD2R);
  vy = vn*cos(theta*KD2R) - ve*sin(theta*KD2R);
}
