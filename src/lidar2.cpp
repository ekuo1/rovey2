
#include "ros/ros.h"
#include <signal.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/Image.h>

#include <webots_ros/set_float.h>
#include <webots_ros/set_int.h>

#define TIME_STEP         32
#define NMOTORS            4
#define MAX_SPEED          6.4
#define OBSTACLE_THRESHOLD 0.1
#define DECREASE_FACTOR    0.9
#define BACK_SLOWDOWN      0.9

ros::NodeHandle *n;

static std::vector<float> lidarValues;

ros::ServiceClient timeStepClient;
webots_ros::set_int timeStepSrv;

static const char *motorNames[NMOTORS] = {
  "front_left_wheel", "front_right_wheel",
  "back_left_wheel", "back_right_wheel"
};

static int lidarResolution = 0;
static int halfResolution = 0;
static double maxRange = 0.0;
static double rangeThreshold = 0.0;
static std::vector<double> braitenbergCoefficients;
static bool areBraitenbergCoefficientsinitialized = false;

double rpm_limit;
double steer_limit;

// gaussian function
double gaussian(double x, double mu, double sigma) {
  return (1.0 / (sigma * sqrt(2.0 * M_PI))) * exp (-((x - mu) * (x - mu)) / (2 * sigma * sigma));
}

void updateSpeed() {
  // init dynamic variables
  double leftObstacle = 0.0, rightObstacle = 0.0, obstacle = 0.0;
  double speedFactor  = 1.0;
   
  // apply the braitenberg coefficients on the resulted values of the lidar
  // near obstacle sensed on the left side
  for (int i = 0; i < halfResolution; ++i) {
    if (lidarValues[i] < rangeThreshold) // far obstacles are ignored
      leftObstacle += braitenbergCoefficients[i] * (1.0 - lidarValues[i] / maxRange);
    // near obstacle sensed on the right side
    int j = lidarResolution - i - 1;
    if (lidarValues[j] < rangeThreshold)
      rightObstacle += braitenbergCoefficients[i] * (1.0 - lidarValues[j] / maxRange);
  }
  // overall front obstacle
  obstacle = leftObstacle + rightObstacle;
  // compute the speed according to the information on
  // obstacles
  if (obstacle > OBSTACLE_THRESHOLD){
    speedFactor = (1.0 - DECREASE_FACTOR * obstacle) * MAX_SPEED / obstacle;

  } 
  else {

  }
  
  // set speeds
  
}

void lidarCallback(const sensor_msgs::LaserScan::ConstPtr& scan) {
  int scanSize = scan->ranges.size();
  lidarValues.resize(scanSize);
  for (int i=0; i<scanSize; ++i)
    lidarValues[i] = scan->ranges[i];

  lidarResolution = scanSize; //1080 for Hokuyo
  halfResolution = scanSize / 2;
  maxRange = scan->range_max;
  rangeThreshold = maxRange / 15.0;
  if (!areBraitenbergCoefficientsinitialized) {
    braitenbergCoefficients.resize(lidarResolution);
    for (int i=0; i<lidarResolution; ++i)
      braitenbergCoefficients[i] = gaussian(i, halfResolution, lidarResolution / 5);
    areBraitenbergCoefficientsinitialized = true;
  }

  updateSpeed();
}

void quit(int sig) {
  ROS_INFO("User stopped the 'pioneer3at' node.");
  timeStepSrv.request.value = 0;
  timeStepClient.call(timeStepSrv);
  ros::shutdown();
  exit(0);
}


int main(int argc, char **argv)
{
  // create a node named 'obstacle_avoidance' on ROS network
  ros::init(argc, argv, "obstacle_avoidance");
  n = new ros::NodeHandle;
  
  //n.getParam("rpm_limit", rpm_limit);
  //n.getParam("steer_limit", steer_limit);
  
  //ROS_INFO("cat");
  //ROS_INFO("%f", rpm_limit);
  
  timeStepClient = n->serviceClient<webots_ros::set_int>("pioneer3at/robot/time_step");
  timeStepSrv.request.value = TIME_STEP;
  
  for (int i=0; i<NMOTORS; ++i) {
      ros::ServiceClient set_velocity_client;
      webots_ros::set_float set_velocity_srv;
      set_velocity_client = n->serviceClient<webots_ros::set_float>(std::string("pioneer3at/") + std::string(motorNames[i]) + std::string("/set_velocity"));
  }
  
  ros::Subscriber sub_lidar_scan;

  sub_lidar_scan = n->subscribe("pioneer3at/Hokuyo_UTM_30LX/laser_scan/layer0", 10, lidarCallback);
  //ROS_INFO("Topic for lidar initialized.");
  while (sub_lidar_scan.getNumPublishers() == 0);
  ROS_INFO("Topic for lidar scan connected.");
  
  signal(SIGINT, quit);
  
  while (ros::ok()) {
    ros::spinOnce();
    ROS_INFO("dog");
  }
  
  return 0;
}

