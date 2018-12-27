#include "ros/ros.h"
#include <nova_common/DriveCmd.h>
#include <webots_ros/set_float.h>

using namespace std;
ros::NodeHandle *n;


int main(int argc, char** argv)
{
    
    ros::init(argc, argv, "spiral_search");
    n = new ros::NodeHandle;
    
    ros::Publisher drive_pub= n->advertise<nova_common::DriveCmd>("/core_rover/driver/drive_cmd", 1);

    float rpm_limit, steer_limit;
    n->getParam("rpm_limit", rpm_limit);
    n->getParam("steer_limit", steer_limit);

    float x=0;

    while (ros::ok()) {

        nova_common::DriveCmd drive_msg;
        drive_msg.rpm = rpm_limit*10;
        drive_msg.steer_pct = x;

        x++;
        drive_pub.publish(drive_msg);
        ros::spinOnce();
  }

    return 0;   
}