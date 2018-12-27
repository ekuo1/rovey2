#include "RosTouchSensor.hpp"
#include "webots_ros/BoolStamped.h"
#include "webots_ros/Float64Stamped.h"
#include "geometry_msgs/WrenchStamped.h"

RosTouchSensor::RosTouchSensor(TouchSensor *touchSensor, Ros *ros) : RosSensor(touchSensor->getName(), touchSensor, ros) {
  mTouchSensor = touchSensor;
  mTypeServer = RosDevice::rosAdvertiseService((ros->name())+'/'+RosDevice::fixedDeviceName()+"/get_type", &RosTouchSensor::getTypeCallback);
}

RosTouchSensor::~RosTouchSensor() {
  mTypeServer.shutdown();
  rosDisable();
}

// creates a publisher for touch sensor value with either a {Bool}, a {Float64}
// or a {WrenchStamped} as message type depending on TouchSensorType
ros::Publisher RosTouchSensor::createPublisher() {
  if (mTouchSensor->getType() == TouchSensor::FORCE) {
    webots_ros::Float64Stamped type;
    std::string topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/value";
    return RosDevice::rosAdvertiseTopic(topicName, type);
  } else if (mTouchSensor->getType() == TouchSensor::FORCE3D) {
    geometry_msgs::WrenchStamped type;
    std::string topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/values";
    return RosDevice::rosAdvertiseTopic(topicName, type);
  } else { // TouchSensor::BUMPER
    webots_ros::BoolStamped type;
    std::string topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/value";
    return RosDevice::rosAdvertiseTopic(topicName, type);
  }
}

// get value(s) from the touch sensor and publish it
void RosTouchSensor::publishValue(ros::Publisher publisher) {
  if (mTouchSensor->getType() == TouchSensor::BUMPER) {
    webots_ros::BoolStamped value;
    value.header.stamp = ros::Time::now();
    value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
    value.data = mTouchSensor->getValue();
    publisher.publish(value);
  } else if (mTouchSensor->getType() == TouchSensor::FORCE) {
    webots_ros::Float64Stamped value;
    value.header.stamp = ros::Time::now();
    value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
    value.data = mTouchSensor->getValue();
    publisher.publish(value);
  } else if (mTouchSensor->getType() == TouchSensor::FORCE3D) {
    geometry_msgs::WrenchStamped value;
    value.header.stamp = ros::Time::now();
    value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
    value.wrench.force.x = mTouchSensor->getValues()[0];
    value.wrench.force.y = mTouchSensor->getValues()[1];
    value.wrench.force.z = mTouchSensor->getValues()[2];
    value.wrench.torque.x = 0.0;
    value.wrench.torque.y = 0.0;
    value.wrench.torque.z = 0.0;
    publisher.publish(value);
  }
}

bool RosTouchSensor::getTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res) {
  res.value = mTouchSensor->getType();
  return true;
}
