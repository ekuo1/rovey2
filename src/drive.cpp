#include "ros/ros.h"
#include <nova_common/DriveCmd.h>

using namespace std;
ros::NodeHandle *n;

/*//
def bearingInDegrees(x, z):
    rad = math.atan2(x,z)
    radnorth = math.atan2(1,0) # north vector 1,0,0
    bearing = (rad-radnorth)/math.pi*180 

    if bearing < 0:
        bearing = bearing + 360.0
    return bearing

compass_sub = rospy.Subscriber("/pioneer3at/compass/values", MagneticField, compassCallback)

from sensor_msgs.msg import NavSatFix, MagneticField

def compassCallback(compassData):
    global rovey_pos
    x = compassData.magnetic_field.x
    z = compassData.magnetic_field.z
    rovey_pos.setOrientation(x,z)

orientation = bearingInDegrees(rovey_pos.x, rovey_pos.z)


*/
int main(int argc, char** argv)
{
    
    ros::init(argc, argv, "spiral_search");
    n = new ros::NodeHandle;
    


    ros::Publisher drive_pub= n->advertise<nova_common::DriveCmd>("/core_rover/driver/drive_cmd", 1);

    float rpm_limit, steer_limit;
    n->getParam("rpm_limit", rpm_limit);
    n->getParam("steer_limit", steer_limit);

    float x=10;

    while (ros::ok()) {

        nova_common::DriveCmd drive_msg;
        drive_msg.rpm = rpm_limit * x;
        drive_msg.steer_pct = steer_limit * 10* 0.2;

        
        drive_pub.publish(drive_msg);
        ros::spinOnce();
  }

    return 0;   
}