#include "RosLightSensor.hpp"
#include "sensor_msgs/Illuminance.h"

RosLightSensor::RosLightSensor(LightSensor *lightSensor, Ros *ros) : RosSensor(lightSensor->getName(), lightSensor, ros) {
  mLightSensor = lightSensor;
}

// creates a publisher for light sensor value with a {double} as message type
ros::Publisher RosLightSensor::createPublisher() {
  sensor_msgs::Illuminance type;
  std::string topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/value";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get value from the light sensor and publish it
void RosLightSensor::publishValue(ros::Publisher publisher) {
  sensor_msgs::Illuminance value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
  value.illuminance = mLightSensor->getValue();
  value.variance = 0.0;
  publisher.publish(value);
}
