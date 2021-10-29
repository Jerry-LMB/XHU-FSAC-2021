#ifndef CANALYSTII_H
#define CANALYSTII_H
#include "controlcan.h"
#include "std_msgs/Int16MultiArray.h"

// CANalystii is a class for USB-CAN device, which offers
// start_device(), close_device(), init_can_interface(),
// receive_can_frame(), send_can_frame() and other methods.

class CANalystii{
public:
    CANalystii(int vci_device_type=VCI_USBCAN2, int vci_device_ind=0);
    ~CANalystii();
    // start device with default parameters
    int start_device();
    // close device with default parameters
    bool close_device();
    // init CAN port 0 or port 1
    bool init_can_interface(unsigned int can_idx, const VCI_INIT_CONFIG& vci_conf);
    // receive CAN frame from CAN port 0 or port 1
    unsigned int receive_can_frame(unsigned int can_idx, std_msgs::Int16MultiArray  input[], unsigned int recv_len, int wait_time=0);
    // send CAN frame to CAN port 0 or port 1
    bool send_can_frame(unsigned int can_idx, std_msgs::Int16MultiArray  &input, unsigned int send_len);
    // transform CAN frame from VCI_CAN_OBJ to ROS msg 
    static std_msgs::Int16MultiArray  can_obj2msg(const VCI_CAN_OBJ& can_obj);
    // transform CAN frame from ROS msg to VCI_CAN_OBJ
    static VCI_CAN_OBJ can_msg2obj(const std_msgs::Int16MultiArray & can_msg);
private:
    bool is_dev_start_;
    bool is_port_init_[2];
    bool is_port_start_[2];
    unsigned int vci_device_type_;//default: VCI_USBCAN2
    unsigned int vci_device_ind_;//default: 0, 0 for first device
    VCI_INIT_CONFIG vci_conf_[2];//to initialize CAN port 0 or port 1

};

#endif