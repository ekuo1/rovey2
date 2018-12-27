#include "RosKeyboard.hpp"
#include "webots_ros/Int32Stamped.h"

RosKeyboard::RosKeyboard(Keyboard *keyboard, Ros *ros) : RosSensor("keyboard", NULL, ros) {
  mKeyboard = keyboard;
}

// creates a publisher for keyboard values with a webots_ros/Int8Stamped as message type
ros::Publisher RosKeyboard::createPublisher() {
  webots_ros::Int32Stamped type;
  std::string topicName = mRos->name()+"/keyboard/key";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get value from the keyboard and publish it
void RosKeyboard::publishValue(ros::Publisher publisher) {
  webots_ros::Int32Stamped value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + "/keyboard";
  int key = mKeyboard->getKey();
  while (key >= 0) {
    value.data = key;
    publisher.publish(value);
    key = mKeyboard->getKey();
  }
}
