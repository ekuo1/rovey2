#include "RosDistanceSensor.hpp"
#include "sensor_msgs/Range.h"

RosDistanceSensor::RosDistanceSensor(DistanceSensor *distanceSensor, Ros *ros) :RosSensor(distanceSensor->getName(), distanceSensor, ros) {
  mDistanceSensor = distanceSensor;
  std::string deviceNameFixed = mDistanceSensor->getName();
  for (size_t i = 0; i < deviceNameFixed.size(); i++)
  {
    if (deviceNameFixed[i] == '-' || deviceNameFixed[i] == ' ')
      deviceNameFixed[i] = '_';
  }
  mMinValueServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+'/'+"get_min_value", &RosDistanceSensor::getMinValueCallback);
  mMaxValueServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+'/'+"get_max_value", &RosDistanceSensor::getMaxValueCallback);
  mApertureServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+'/'+"get_aperture", &RosDistanceSensor::getApertureCallback);
  mTypeServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+'/'+"get_type", &RosDistanceSensor::getTypeCallback);
}

RosDistanceSensor::~RosDistanceSensor() {
  mMinValueServer.shutdown();
  mMaxValueServer.shutdown();
  mApertureServer.shutdown();
  mTypeServer.shutdown();
  rosDisable();
}

// creates a publisher for distance sensor value with a {double} as message type
ros::Publisher RosDistanceSensor::createPublisher() {
  sensor_msgs::Range type;
  std::string topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/value";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get value from the distance sensor and publish it
void RosDistanceSensor::publishValue(ros::Publisher publisher) {
  sensor_msgs::Range value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
  if (mDistanceSensor->getType() == DistanceSensor::SONAR)
    value.radiation_type = 0;
  else if (mDistanceSensor->getType() == DistanceSensor::INFRA_RED)
    value.radiation_type = 1;
  value.field_of_view = mDistanceSensor->getAperture();
  value.min_range = mDistanceSensor->getMinValue();
  value.max_range = mDistanceSensor->getMaxValue();
  value.range = mDistanceSensor->getValue();
  publisher.publish(value);
}

bool RosDistanceSensor::getMinValueCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res) {
  res.value = mDistanceSensor->getMinValue();
  return true;
}

bool RosDistanceSensor::getMaxValueCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res) {
  res.value = mDistanceSensor->getMaxValue();
  return true;
}

bool RosDistanceSensor::getApertureCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res) {
  res.value = mDistanceSensor->getAperture();
  return true;
}

bool RosDistanceSensor::getTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res) {
  res.value = mDistanceSensor->getType();
  return true;
}
