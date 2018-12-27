#include "RosMotorSensor.hpp"
#include "webots_ros/Float64Stamped.h"

RosMotorSensor::RosMotorSensor(Motor *motor, std::string sensorName, Ros *ros) : RosSensor(sensorName, motor, ros, false) {
  mMotor = motor;
  if (sensorName == (RosDevice::fixedDeviceName()+"/force_feedback_sensor"))
    mType = 1;
  else if (sensorName == (RosDevice::fixedDeviceName()+"/torque_feedback_sensor"))
    mType = 2;
}

// creates a publisher for motor sensor values with a {double} as message mType
ros::Publisher RosMotorSensor::createPublisher() {
  webots_ros::Float64Stamped type;
  std::string topicName;
  if (mType == 1)
    topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/force_feedback";
  else if (mType == 2)
    topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/torque_feedback";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get value from the motor sensor and publish it into a {double} message
void RosMotorSensor::publishValue(ros::Publisher publisher) {
  webots_ros::Float64Stamped value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
  if (mType == 1)
    value.data = mMotor->getForceFeedback();
  else if (mType == 2)
    value.data = mMotor->getTorqueFeedback();
  publisher.publish(value);
}

void RosMotorSensor::rosEnable(int samplingPeriod) {
  if (mType == 1)
    mMotor->enableForceFeedback(samplingPeriod);
  else if (mType == 2)
    mMotor->enableTorqueFeedback(samplingPeriod);
}
void RosMotorSensor::rosDisable() {
  if (mType == 1)
    mMotor->disableForceFeedback();
  else if (mType == 2)
    mMotor->disableTorqueFeedback();
}

std::string RosMotorSensor::deviceName() {
  if (mType == 1)
    return RosDevice::fixedDeviceName()+"/force_feedback_sensor";
  else if (mType == 2)
    return RosDevice::fixedDeviceName()+"/torque_feedback_sensor";
  else
    return "wrong_mType_motor_sensor";
}

int RosMotorSensor::rosSamplingPeriod() {
  if (mType == 1)
    return mMotor->getForceFeedbackSamplingPeriod();
  else if (mType == 2)
    return mMotor->getTorqueFeedbackSamplingPeriod();
  else
    return 0;
}
