#include "RosGyro.hpp"
#include "sensor_msgs/Imu.h"

RosGyro::RosGyro(Gyro *gyroscope, Ros *ros) : RosSensor(gyroscope->getName(), gyroscope, ros) {
  mGyro = gyroscope;
}

// creates a publisher for Gyro values with a sensor_msgs/Imu as message type
ros::Publisher RosGyro::createPublisher() {
  sensor_msgs::Imu type;
  std::string topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/values";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get value from the gyroscope and publish it into a sensor_msgs/Imu
void RosGyro::publishValue(ros::Publisher publisher) {
  sensor_msgs::Imu value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
  value.orientation.x = 0.0;
  value.orientation.y = 0.0;
  value.orientation.z = 0.0;
  value.orientation.w = 0.0;
  value.orientation_covariance[0] = -1.0; // means no orientation information
  value.angular_velocity.x = mGyro->getValues()[1];
  value.angular_velocity.y = mGyro->getValues()[2];
  value.angular_velocity.z = mGyro->getValues()[3];
  for (int i=0; i<9; ++i) // means "covariance unknown"
    value.angular_velocity_covariance[i] = 0;
  value.linear_acceleration.x = 0.0;
  value.linear_acceleration.y = 0.0;
  value.linear_acceleration.z = 0.0;
  value.linear_acceleration_covariance[0] = -1.0; // means no linear_acceleration information
  publisher.publish(value);
}
