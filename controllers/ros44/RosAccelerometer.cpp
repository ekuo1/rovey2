#include "RosAccelerometer.hpp"
#include "sensor_msgs/Imu.h"

RosAccelerometer::RosAccelerometer(Accelerometer *accelerometer, Ros *ros) : RosSensor(accelerometer->getName(), accelerometer, ros) {
  mAccelerometer = accelerometer;
}

// creates a publisher for accelerometer values with a sensor_msgs/Imu as message type
ros::Publisher RosAccelerometer::createPublisher() {
  sensor_msgs::Imu type;
  std::string topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/values";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get value from the accelerometer and publish it
void RosAccelerometer::publishValue(ros::Publisher publisher) {
  sensor_msgs::Imu value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
  value.orientation.x = 0.0;
  value.orientation.y = 0.0;
  value.orientation.z = 0.0;
  value.orientation.w = 0.0;
  value.orientation_covariance[0] = -1.0; // means no orientation information
  value.angular_velocity.x = 0.0;
  value.angular_velocity.y = 0.0;
  value.angular_velocity.z = 0.0;
  value.angular_velocity_covariance[0] = -1.0; // means no angular_velocity information
  value.linear_acceleration.x = mAccelerometer->getValues()[0];
  value.linear_acceleration.y = mAccelerometer->getValues()[1];
  value.linear_acceleration.z = mAccelerometer->getValues()[2];
  for (int i=0; i<9; ++i) // means "covariance unknown"
    value.linear_acceleration_covariance[i] = 0;
  publisher.publish(value);
}
