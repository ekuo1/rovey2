#include "RosBatterySensor.hpp"
#include "webots_ros/Float64Stamped.h"

RosBatterySensor::RosBatterySensor(Robot *robot, Ros *ros) : RosSensor("battery_sensor", NULL, ros) {
  mRobot = robot;
}

// creates a publisher for battery sensor value with a {double} as message type
ros::Publisher RosBatterySensor::createPublisher() {
  webots_ros::Float64Stamped type;
  std::string topicName = mRos->name()+"/battery_sensor/value";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get value from the battery sensor and publish it
void RosBatterySensor::publishValue(ros::Publisher publisher) {
  // creates a {double} message to put battery sensor data inside
  webots_ros::Float64Stamped value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + "/battery_sensor";
  value.data = mRobot->batterySensorGetValue();
  publisher.publish(value);
}
