#include "ros/ros.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sensor_msgs/LaserScan.h>

using namespace std;
ros::NodeHandle *n;
static std::vector<float> lidarValues;



void lidarCallback(const sensor_msgs::LaserScan::ConstPtr& scan) {
  int scanSize = scan->ranges.size();
  lidarValues.resize(scanSize);

  for (int i=0; i<scanSize; ++i){
      lidarValues[i] = scan->ranges[i];
      ROS_INFO("%f\n", lidarValues[i]);
  }

}

int main(int argc, char** argv)
{
    
   
    ros::init(argc, argv, "lidar_subscribe");
    n = new ros::NodeHandle;

    ros::Subscriber sub_lidar_scan;

    sub_lidar_scan = n->subscribe("pioneer3at/Hokuyo_UTM_30LX/laser_scan/layer0", 10, lidarCallback);
    ROS_INFO("Topic for lidar initialized.");

    

    std::ofstream outputFile;
    outputFile.open("/home/turtle/catkin_ws/src/rovey2/src/laserscans.csv");

    

    // close the output file
    

    

   while (ros::ok()) {

    for (int i=0; i<lidarValues.size(); ++i){
        outputFile << lidarValues[i]<< ",";
        if (i %100 ==0){
            outputFile<<endl;
        }
    }

    ros::spinOnce();
  }
  
    outputFile.close();
    return 0;   
}