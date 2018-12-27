#include "RosPositionSensor.hpp"
#include "webots_ros/Float64Stamped.h"
#include <webots/Brake.hpp>
#include <webots/Motor.hpp>

RosPositionSensor::RosPositionSensor(PositionSensor *positionSensor, Ros *ros) : RosSensor(positionSensor->getName(), positionSensor, ros) {
  mPositionSensor = positionSensor;
  mTypeServer = RosDevice::rosAdvertiseService(ros->name()+'/'+RosDevice::fixedDeviceName()+"/get_type", &RosPositionSensor::getTypeCallback);
  mGetBrakeNameServer = RosDevice::rosAdvertiseService(ros->name()+'/'+RosDevice::fixedDeviceName()+"/get_brake_name", &RosPositionSensor::getBrakeNameCallback);
  mGetMotorNameServer = RosDevice::rosAdvertiseService(ros->name()+'/'+RosDevice::fixedDeviceName()+"/get_motor_name", &RosPositionSensor::getMotorNameCallback);
}

RosPositionSensor::~RosPositionSensor() {
  mTypeServer.shutdown();
  rosDisable();
}

// creates a publisher for position sensor value with a {double} as message type
ros::Publisher RosPositionSensor::createPublisher() {
  webots_ros::Float64Stamped type;
  std::string topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/value";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get value from the position sensor and publish it
void RosPositionSensor::publishValue(ros::Publisher publisher) {
  webots_ros::Float64Stamped value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
  value.data = mPositionSensor->getValue();
  publisher.publish(value);
}

bool RosPositionSensor::getTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res) {
  res.value = mPositionSensor->getType();
  return true;
}

bool RosPositionSensor::getBrakeNameCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res) {
  Brake *brake = mPositionSensor->getBrake();
  if (brake)
    res.value = brake->getName();
  else
    res.value = "";
  return true;
}

bool RosPositionSensor::getMotorNameCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res) {
  Motor *motor = mPositionSensor->getMotor();
  if (motor)
    res.value = motor->getName();
  else
    res.value = "";
  return true;
}
