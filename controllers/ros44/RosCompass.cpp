#include "RosCompass.hpp"
#include "sensor_msgs/MagneticField.h"

RosCompass::RosCompass(Compass *compass, Ros *ros) : RosSensor(compass->getName(), compass, ros) {
  mCompass = compass;
}

// creates a publisher for compass values with a [3x1] {double} array
// for x,y and z north's coordinates as message type
ros::Publisher RosCompass::createPublisher() {
  sensor_msgs::MagneticField type;
  std::string topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/values";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get value from the compass and publish it into a [3x1] {double} array
void RosCompass::publishValue(ros::Publisher publisher) {
  sensor_msgs::MagneticField value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
  value.magnetic_field.x = mCompass->getValues()[0];
  value.magnetic_field.y = mCompass->getValues()[1];
  value.magnetic_field.z = mCompass->getValues()[2];
  for (int i=0; i<9; ++i) // means "covariance unknown"
    value.magnetic_field_covariance[i] = 0;
  publisher.publish(value);
}
