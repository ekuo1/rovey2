#include "RosRadar.hpp"
#include "webots_ros/RadarTarget.h"
#include "webots_ros/Int8Stamped.h"

RosRadar::RosRadar(Radar *radar, Ros *ros) : RosSensor(radar->getName(), radar, ros) {
  mRadar = radar;
  std::string deviceNameFixed = RosDevice::fixedDeviceName();
  mGetMaxRangeServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+"/get_max_range", &RosRadar::getMaxRangeCallback);
  mGetMinRangeServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+"/get_min_range", &RosRadar::getMinRangeCallback);
  mGetVerticalFovServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+"/get_vertical_fov", &RosRadar::getVerticalFovCallback);
  mGetHorizontalFovServer = RosDevice::rosAdvertiseService((ros->name())+'/'+deviceNameFixed+"/get_horizontal_fov", &RosRadar::getHorizontalFovCallback);
}

RosRadar::~RosRadar() {
  mTargetsNumberPublisher.shutdown();
  rosDisable();
}

// creates a publisher for radar targets with a {RadarTarget} as message type
ros::Publisher RosRadar::createPublisher() {
  std::string deviceNameFixed = RosDevice::fixedDeviceName();
  webots_ros::Int8Stamped targetsNumberType;
  mTargetsNumberPublisher = RosDevice::rosAdvertiseTopic(mRos->name()+'/'+deviceNameFixed+"/number_of_targets", targetsNumberType);

  webots_ros::RadarTarget type;
  std::string topicName = mRos->name()+'/'+deviceNameFixed+"/targets";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get the target from the radar and publish them
void RosRadar::publishValue(ros::Publisher publisher) {
  int target_number = mRadar->getNumberOfTargets();
  webots_ros::Int8Stamped targetsNumber;
  targetsNumber.header.stamp = ros::Time::now();
  targetsNumber.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
  targetsNumber.data = target_number;
  mTargetsNumberPublisher.publish(targetsNumber);

  webots_ros::RadarTarget target;
  target.header.stamp = ros::Time::now();
  target.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
  const WbRadarTarget *targets = mRadar->getTargets();
  for(int i=0; i<target_number; ++i) {
    target.distance      = targets[i].distance;
    target.receivedPower = targets[i].received_power;
    target.speed         = targets[i].speed;
    target.azimuth       = targets[i].azimuth;
    publisher.publish(target);
  }
}

bool RosRadar::getMaxRangeCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res) {
  res.value = mRadar->getMaxRange();
  return true;
}

bool RosRadar::getMinRangeCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res) {
  res.value = mRadar->getMinRange();
  return true;
}

bool RosRadar::getVerticalFovCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res) {
  res.value = mRadar->getVerticalFov();
  return true;
}

bool RosRadar::getHorizontalFovCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res) {
  res.value = mRadar->getHorizontalFov();
  return true;
}
