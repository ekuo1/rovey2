#include "RosMouse.hpp"

RosMouse::RosMouse(Mouse *mouse, Ros *ros) : RosSensor("mouse", NULL, ros) {
  mMouse = mouse;

  std::string fixedDeviceName = RosDevice::fixedDeviceName();
  mGetStateServer            = RosDevice::rosAdvertiseService((ros->name()) + '/' + fixedDeviceName + "/mouse_get_state", &RosMouse::getStateCallback);
  mEnable3dPositionServer    = RosDevice::rosAdvertiseService((ros->name()) + '/' + fixedDeviceName + "/mouse_enable_3d_position", &RosMouse::enable3dPositionCallback);
  mDisable3dPositionServer   = RosDevice::rosAdvertiseService((ros->name()) + '/' + fixedDeviceName + "/mouse_disable_3d_position", &RosMouse::disable3dPositionCallback);
  mIs3dPositionEnabledServer = RosDevice::rosAdvertiseService((ros->name()) + '/' + fixedDeviceName + "/mouse_is_3d_position_enabled", &RosMouse::is3dPositionEnabledCallback);
}

RosMouse::~RosMouse() {
  mGetStateServer.shutdown();
  mEnable3dPositionServer.shutdown();
  mDisable3dPositionServer.shutdown();
  mIs3dPositionEnabledServer.shutdown();
  rosDisable();
}

bool RosMouse::getStateCallback(webots_ros::mouse_get_state::Request &req, webots_ros::mouse_get_state::Response &res) {
  res.left = mMouse->getState().left;
  res.middle = mMouse->getState().middle;
  res.right = mMouse->getState().right;
  res.u = mMouse->getState().u;
  res.v = mMouse->getState().v;
  res.x = mMouse->getState().x;
  res.y = mMouse->getState().y;
  res.z = mMouse->getState().z;
  return true;
}

bool RosMouse::enable3dPositionCallback(webots_ros::set_bool::Request &req, webots_ros::set_bool::Response &res) {
  mMouse->enable3dPosition();
  res.success = true;
  return true;
}

bool RosMouse::disable3dPositionCallback(webots_ros::set_bool::Request &req, webots_ros::set_bool::Response &res) {
  mMouse->disable3dPosition();
  res.success = true;
  return true;
}

bool RosMouse::is3dPositionEnabledCallback(webots_ros::get_bool::Request &req, webots_ros::get_bool::Response &res) {
  res.value = mMouse->is3dPositionEnabled();
  return true;
}
