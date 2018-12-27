#include "RosLED.hpp"

RosLED::RosLED(LED *led, Ros *ros) : RosDevice(led, ros) {
  std::string fixedDeviceName = RosDevice::fixedDeviceName();
  mSetServer = RosDevice::rosAdvertiseService((ros->name())+'/'+fixedDeviceName+"/set_led", &RosLED::setCallback);
  mGetServer = RosDevice::rosAdvertiseService((ros->name())+'/'+fixedDeviceName+"/get_led", &RosLED::getCallback);
  mLED = led;
}

RosLED::~RosLED() {
  mSetServer.shutdown();
  mGetServer.shutdown();
}

// set LED device on/off depending on req value
bool RosLED::setCallback(webots_ros::set_int::Request &req, webots_ros::set_int::Response &res) {
  mLED->set(req.value);
  res.success = true;
  return true;
}

// send back LED value
bool RosLED::getCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res) {
  res.value = mLED->get();
  return true;
}
