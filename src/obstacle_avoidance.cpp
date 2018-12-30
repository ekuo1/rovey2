#include "ros/ros.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sensor_msgs/LaserScan.h>
#include <cstdlib>
#include <nova_common/DriveCmd.h>

using namespace std;

ros::NodeHandle *n;

std::vector <float> baseline;
static std::vector<float> lidarValues;
static int lidarResolution = 0;
static int halfResolution = 0;

void updateSpeed() {

    double leftObstacle = 0.0, rightObstacle = 0.0, frontObstacle = 0.0;

    for (int i = 0; i < lidarResolution; ++i) 
    {
        if (lidarValues[i] < baseline[i] - 1 || lidarValues[i]> baseline[i] + 1) // far obstacles are ignored
        {
            
                ROS_INFO("%d : %f %f %f", i, abs(lidarValues[i]-baseline[i]), lidarValues[i], baseline[i]);
                if (i < 600 && i > 500){
                    frontObstacle ++;
                }    
                else if (i< 550 && i > 400){
                    leftObstacle ++;

                }
                else if (i >550 && i < 700){
                    rightObstacle++;

                }
        }
    }

    if (frontObstacle > leftObstacle && frontObstacle > rightObstacle){ //front is the biggest
        if (rightObstacle > leftObstacle){
            //turn left
        }
        else{
            //turn right
        }
    }
    else if (rightObstacle > leftObstacle){
        //turn left
    }
    else if (leftObstacle > 0){
        //turn right
    }
    else{
        //go forward
    }

}

void lidarCallback(const sensor_msgs::LaserScan::ConstPtr& scan) {
  int scanSize = scan->ranges.size();
  lidarValues.resize(scanSize);
  lidarResolution = scanSize; 
  halfResolution = scanSize / 2;
  for (int i=0; i<scanSize; ++i){
      lidarValues[i] = scan->ranges[i];
      //ROS_INFO("%f\n", lidarValues[i]);
  }

  updateSpeed();

}


int main (int argc, char** argv) {

    string line;
    ifstream myfile;
    myfile.open("/home/turtle/catkin_ws/src/rovey2/src/laserscans.csv");

    if (myfile.is_open())
    {
    while (std::getline(myfile, line))
        {
        baseline.push_back(strtof((line).c_str(),0));
        //ROS_INFO("%f", strtof((line).c_str(),0));
        }
    }
    else cout << "Unable to open file"; 


    ros::init(argc, argv, "obstacle_avoidance");
    n = new ros::NodeHandle;

    ros::Subscriber sub_lidar_scan;

    sub_lidar_scan = n->subscribe("pioneer3at/Hokuyo_UTM_30LX/laser_scan/layer0", 10, lidarCallback);
    ROS_INFO("Topic for lidar initialized.");

    /*

    put these in the right place

    ros::Publisher drive_pub= n->advertise<nova_common::DriveCmd>("/core_rover/driver/drive_cmd", 1);
    
    float rpm_limit, steer_limit;
    n->getParam("rpm_limit", rpm_limit);
    n->getParam("steer_limit", steer_limit);

    nova_common::DriveCmd drive_msg;
    drive_msg.rpm = ;
    drive_msg.steer_pct = ;

    drive_pub.publish(drive_msg);
    */

    while (ros::ok()){

    ros::spinOnce();

    }



  return 0;
}