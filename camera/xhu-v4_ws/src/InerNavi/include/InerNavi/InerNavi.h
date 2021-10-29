#ifndef  _INERNAVI_
#define  _INERNAVI_
#include<iostream>
#include<ros/ros.h>
//define class
class InerNavi
{
public:
    InerNavi(uint32_t baudrate ,uint16_t timeout); 
    void GetData();
    void GPS2XY( const double &lat, const double &lon);
    void GPS_Theta2Map(const float &gps_theta);
     void Speed_Transfor( const float &theta);
private:
            uint32_t  Baudrate;
            uint16_t  Timeout;
            ros::NodeHandle nh; 
            ros::Publisher  PubPositon;
            ros::Publisher  PubStatus;
            serial::Serial ser;
};

void gps2xy( const double &lat, const double &lon);
void GPS_Theta2Map_Theta(const float &gps_theta);
void Spd_Transfor( const float &theta);
const uint32_t xmin = 400000;
const uint32_t xmax = 500000;
const uint32_t ymin = 3300000;
const uint32_t ymax = 3500000;
const uint8_t  length = 33;
//InertialNavigation Parameter
const float roll_factor = 360.0/32768.0;
const float w_factor = 300.0/32768.0;
const float a_factor = 12.0/32768.0;
const double Lon_factor = 0.0000001;
const double Lat_factor = 0.0000001;
const float high_factor = 0.001;
const float v_factor = 100.0/32768.0;

uint8_t spd_flag = 0;
uint8_t last_flag = 0;
uint8_t  init0,init1,init2;//用于存储前三个buffer中的数
uint8_t count = 0;
uint16_t  roll = 0;//横滚角
int16_t     real_roll = 0;
 float    Roll = 0;

uint16_t PitchAnagle = 0;
int16_t   real_PitchAnagle = 0;
float Pitch_Anagle = 0;

uint16_t CourseAngle = 0;
int16_t   real_CourseAngle = 0;
float Course_Angle = 0;

uint16_t wx = 0;
int16_t real_wx = 0;
float Wx = 0;

uint16_t wy = 0;
uint16_t real_wy = 0;
float Wy = 0;

uint16_t wz = 0;
int16_t real_wz = 0;
float Wz = 0;

uint16_t ax = 0;
int16_t real_ax = 0;
float Ax = 0;

uint16_t ay = 0;
int16_t real_ay = 0;
float Ay = 0;

uint16_t az = 0;
int16_t real_az = 0;
float Az = 0;

uint32_t lon = 0;
int32_t    real_lon = 0;
double Lon = 0;
double Last_y = 0;

uint32_t lat = 0;
int32_t   real_lat = 0;
double Lat = 0;
double Last_x  = 0;

uint32_t high = 0;
int32_t real_high = 0;
float High = 0;

uint16_t vn = 0;
int16_t   real_vn = 0;
float Vn = 0;

uint16_t ve = 0;
int16_t   real_ve = 0;
float Ve = 0;

uint16_t  vz = 0;
int16_t real_vz = 0;
float Vz = 0;

uint8_t  status = 0;
int8_t    real_status = 0;
int8_t Status  = 0;

//GPS Parameter
double x = 0;
double y = 0;
float vx  = 0;
float vy = 0;
float last_vx = 0;
float last_vy = 0;
float theta = 0;
float last_theta = 0;
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

//Function-Declaration 

#endif