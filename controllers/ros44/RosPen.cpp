#include "RosPen.hpp"

RosPen::RosPen(Pen *pen, Ros *ros) : RosDevice(pen, ros) {
  std::string fixedDeviceName = RosDevice::fixedDeviceName();
  mWriteServer = RosDevice::rosAdvertiseService((ros->name())+'/'+fixedDeviceName+"/write", &RosPen::writeCallback);
  mSetInkColorServer = RosDevice::rosAdvertiseService((ros->name())+'/'+fixedDeviceName+"/set_ink_color", &RosPen::setInkColorCallback);
  mPen = pen;
}

RosPen::~RosPen() {
  mWriteServer.shutdown();
  mSetInkColorServer.shutdown();
}

bool RosPen::writeCallback(webots_ros::set_bool::Request &req, webots_ros::set_bool::Response &res) {
  mPen->write(req.value);
  res.success = true;
  return true;
}

bool RosPen::setInkColorCallback(webots_ros::pen_set_ink_color::Request &req, webots_ros::pen_set_ink_color::Response &res) {
  mPen->setInkColor(req.color, req.density);
  res.success = 1;
  return true;
}
