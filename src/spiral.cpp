//--**--..--**--..--**--..--**--..--**--..--**--..--**--..--**--..--**--
// Description:
//  This program reads the rover's initial location at the start
//  of the search pattern, and generates a list of GPS coordinates
//  which are shaped in a spiral pattern. THese can be passed to the 
//  autonomous driving node (hopefully) 
//--..--**--..--**--..--**--..--**--..--**--..--**--..--**--..--**--..--

#include "ros/ros.h"
#include <sensor_msgs/NavSatFix.h>

using namespace std;
ros::NodeHandle *n;

float roveyLat, roveyLng, initLat, initLng;
bool initInit = false;

void gpsCallback(const sensor_msgs::NavSatFix::ConstPtr& gpsData) {
    roveyLat = gpsData->latitude;
    roveyLng = gpsData->longitude;

}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "spiral");
    n = new ros::NodeHandle;
    std::vector<float> t; 

    ros::Subscriber gps_sub;
    gps_sub = n->subscribe("/pioneer3at/gps/values", 10, gpsCallback);
    ROS_INFO("Topic for gps initialized.");


    for (int i = 0; i < 10; i++){
        t[i] = i*5;
    }

    while (ros::ok()){

        ros::spinOnce();

        if(!initInit){
            initLat = roveyLat;
            initLng = roveyLng;

            initInit = true;
            

        }

        



    }
}