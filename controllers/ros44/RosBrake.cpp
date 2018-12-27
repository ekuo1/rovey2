#include "RosBrake.hpp"
#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>

RosBrake::RosBrake(Brake *brake, Ros *ros) : RosDevice(brake, ros) {
  std::string fixedDeviceName = RosDevice::fixedDeviceName();
  mSetDampingConstantServer = RosDevice::rosAdvertiseService(ros->name()+'/'+fixedDeviceName+"/set_damping_constant", &RosBrake::setdampingConstantCallback);
  mGetTypeServer = RosDevice::rosAdvertiseService(ros->name()+'/'+fixedDeviceName+"/get_type", &RosBrake::getTypeCallback);
  mGetMotorNameServer = RosDevice::rosAdvertiseService(ros->name()+'/'+fixedDeviceName+"/get_motor_name", &RosBrake::getMotorNameCallback);
  mGetPositionSensorNameServer = RosDevice::rosAdvertiseService(ros->name()+'/'+fixedDeviceName+"/get_position_sensor_name", &RosBrake::getPositionSensorNameCallback);
  mBrake = brake;
}

RosBrake::~RosBrake() {
  mSetDampingConstantServer.shutdown();
  mGetTypeServer.shutdown();
}

bool RosBrake::setdampingConstantCallback(webots_ros::set_float::Request &req, webots_ros::set_float::Response &res) {
  mBrake->setDampingConstant(req.value);
  res.success = true;
  return true;
}

bool RosBrake::getTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res) {
  res.value = mBrake->getType();
  return true;
}

bool RosBrake::getMotorNameCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res) {
  Motor *motor = mBrake->getMotor();
  if (motor)
    res.value = motor->getName();
  else
    res.value = "";
  return true;
}

bool RosBrake::getPositionSensorNameCallback(webots_ros::get_string::Request &req, webots_ros::get_string::Response &res) {
  PositionSensor *positionSensor = mBrake->getPositionSensor();
  if (positionSensor)
    res.value = positionSensor->getName();
  else
    res.value = "";
  return true;
}
