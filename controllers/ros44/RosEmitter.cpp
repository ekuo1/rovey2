#include "RosEmitter.hpp"

RosEmitter::RosEmitter(Emitter *emitter, Ros *ros) : RosDevice(emitter, ros) {
  mEmitter = emitter;
  std::string fixedDeviceName = RosDevice::fixedDeviceName();
  mSendServer = RosDevice::rosAdvertiseService((ros->name())+'/'+fixedDeviceName+"/send", &RosEmitter::sendCallback);
  mGetBufferSizeServer = RosDevice::rosAdvertiseService((ros->name())+'/'+fixedDeviceName+"/get_buffer_size", &RosEmitter::getBufferSizeCallback);
  mGetChannelServer = RosDevice::rosAdvertiseService((ros->name())+'/'+fixedDeviceName+"/get_channel", &RosEmitter::getChannelCallback);
  mGetRangeServer = RosDevice::rosAdvertiseService((ros->name())+'/'+fixedDeviceName+"/get_range", &RosEmitter::getRangeCallback);
  mSetChannelServer = RosDevice::rosAdvertiseService((ros->name())+'/'+fixedDeviceName+"/set_channel",&RosEmitter::setChannelCallback);
  mSetRangeServer = RosDevice::rosAdvertiseService((ros->name())+'/'+fixedDeviceName+"/set_range", &RosEmitter::setRangeCallback);
}

RosEmitter::~RosEmitter() {
  mSendServer.shutdown();
  mGetBufferSizeServer.shutdown();
  mGetChannelServer.shutdown();
  mGetRangeServer.shutdown();
  mSetChannelServer.shutdown();
  mSetRangeServer.shutdown();
}

bool RosEmitter::sendCallback(webots_ros::set_string::Request &req, webots_ros::set_string::Response &res) {
  mEmitter->send((void *)req.value.c_str(), req.value.size());
  res.success = true;
  return true;
}

bool RosEmitter::getBufferSizeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res) {
  res.value = mEmitter->getBufferSize();
  return true;
}

bool RosEmitter::getChannelCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res) {
  res.value = mEmitter->getChannel();
  return true;
}

bool RosEmitter::getRangeCallback(webots_ros::get_float::Request &req, webots_ros::get_float::Response &res) {
  res.value = mEmitter->getRange();
  return true;
}

bool RosEmitter::setChannelCallback(webots_ros::set_int::Request &req, webots_ros::set_int::Response &res) {
  mEmitter->setChannel(req.value);
  res.success = true;
  return true;
}

bool RosEmitter::setRangeCallback(webots_ros::set_float::Request &req, webots_ros::set_float::Response &res) {
  mEmitter->setRange(req.value);
  res.success = true;
  return true;
}
