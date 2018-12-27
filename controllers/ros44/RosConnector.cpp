#include "RosConnector.hpp"
#include "webots_ros/Int8Stamped.h"

RosConnector::RosConnector(Connector *connector, Ros *ros) : RosSensor(connector->getName() + "/presence_sensor", connector, ros) {
  std::string fixedDeviceName = RosDevice::fixedDeviceName();
  mLockServer = RosDevice::rosAdvertiseService((ros->name())+'/'+fixedDeviceName+"/lock", &RosConnector::lockCallback);
  mConnector = connector;
}

RosConnector::~RosConnector() {
  mLockServer.shutdown();
  rosDisable();
}

ros::Publisher RosConnector::createPublisher() {
  webots_ros::Int8Stamped type;
  std::string topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/presence";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get value from the connector and publish it
void RosConnector::publishValue(ros::Publisher publisher) {
  webots_ros::Int8Stamped value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
  value.data = mConnector->getPresence();
  publisher.publish(value);
}

bool RosConnector::lockCallback(webots_ros::set_bool::Request &req, webots_ros::set_bool::Response &res) {
  if (req.value) {
    mConnector->lock();
    res.success = true;
  } else {
    mConnector->unlock();
    res.success = true;
  }
  return true;
}
