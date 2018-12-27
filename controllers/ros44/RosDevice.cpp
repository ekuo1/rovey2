#include "RosDevice.hpp"

RosDevice::RosDevice(Device *device, Ros *ros, bool enableDefaultServices) {
  mDevice = device;
  mRos    = ros;
  if (device && enableDefaultServices) {
    mGetModel    = mRos->nodeHandle()->advertiseService(ros->name()+'/'+fixedDeviceName()+"/get_model", &RosDevice::getModelCallback, this);
    mGetName     = mRos->nodeHandle()->advertiseService(ros->name()+'/'+fixedDeviceName()+"/get_name", &RosDevice::getNameCallback, this);
    mGetNodeType = mRos->nodeHandle()->advertiseService(ros->name()+'/'+fixedDeviceName()+"/get_node_type", &RosDevice::getNodeTypeCallback, this);
  }
}

RosDevice::~RosDevice() {
  mGetModel.shutdown();
  mGetName.shutdown();
  mGetNodeType.shutdown();
}

bool RosDevice::getModelCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res){
  if (mDevice)
    res.value = mDevice->getModel();
  else
    res.value = "";
  return true;
}

bool RosDevice::getNameCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res) {
  if (mDevice)
    res.value = mDevice->getName();
  else
    res.value = "";
  return true;
}

bool RosDevice::getNodeTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res) {
  if (mDevice)
    res.value = mDevice->getNodeType();
  else
    res.value = 0;
  return true;
}

std::string RosDevice::deviceName() {
  if (mDevice)
    return mDevice->getName();
  else
    return "";
}

std::string RosDevice::fixedDeviceName() {
  return Ros::fixedNameString(deviceName());
}
