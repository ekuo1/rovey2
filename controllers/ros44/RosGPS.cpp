#include "RosGPS.hpp"
#include "sensor_msgs/NavSatFix.h"
#include "webots_ros/Float64Stamped.h"

RosGPS::RosGPS(GPS *gps, Ros *ros) : RosSensor(gps->getName(), gps, ros) {
  mGPS = gps;
  mCoordinateTypeServer = RosDevice::rosAdvertiseService((ros->name())+'/'+RosDevice::fixedDeviceName()+"/get_coordinate_system", &RosGPS::getCoordinateTypeCallback);
  mConvertServer = RosDevice::rosAdvertiseService((ros->name())+'/'+RosDevice::fixedDeviceName()+"/decimal_degrees_to_degrees_minutes_seconds", &RosGPS::convertToDegreesMinutesSecondsCallback);
}

RosGPS::~RosGPS() {
  mCoordinateTypeServer.shutdown();
  mConvertServer.shutdown();
  mSpeedPublisher.shutdown();
  rosDisable();
}

// creates a publisher for GPS values with a [3x1] {double} array
// for x,y and z absolute coordinates as message type
ros::Publisher RosGPS::createPublisher() {
  webots_ros::Float64Stamped speedType;
  mSpeedPublisher = RosDevice::rosAdvertiseTopic(mRos->name()+'/'+RosDevice::fixedDeviceName()+"/speed", speedType);

  sensor_msgs::NavSatFix type;
  std::string topicName = mRos->name()+'/'+RosDevice::fixedDeviceName()+"/values";
  return RosDevice::rosAdvertiseTopic(topicName, type);
}

// get value from the GPS and publish it into a [3x1] {double} array
void RosGPS::publishValue(ros::Publisher publisher) {
  sensor_msgs::NavSatFix value;
  value.header.stamp = ros::Time::now();
  value.header.frame_id = mRos->name() + '/' + RosDevice::fixedDeviceName();
  if (mGPS->getCoordinateSystem() == GPS::WGS84) {
    value.latitude = mGPS->getValues()[0];
    value.longitude = mGPS->getValues()[1];
    value.altitude = mGPS->getValues()[2];
  } else {
    value.latitude = mGPS->getValues()[0];
    value.longitude = mGPS->getValues()[2];
    value.altitude = mGPS->getValues()[1];
  }
  value.position_covariance_type = sensor_msgs::NavSatFix::COVARIANCE_TYPE_UNKNOWN;
  value.status.service = sensor_msgs::NavSatStatus::SERVICE_GPS;
  publisher.publish(value);

  webots_ros::Float64Stamped speedValue;
  speedValue.header.stamp = ros::Time::now();
  speedValue.data = mGPS->getSpeed();
  mSpeedPublisher.publish(speedValue);
}

bool RosGPS::getCoordinateTypeCallback(webots_ros::get_int::Request &req, webots_ros::get_int::Response &res) {
  res.value = mGPS->getCoordinateSystem();
  return true;
}

bool RosGPS::convertToDegreesMinutesSecondsCallback(webots_ros::gps_decimal_degrees_to_degrees_minutes_seconds::Request &req, webots_ros::gps_decimal_degrees_to_degrees_minutes_seconds::Response &res) {
  res.degreesMinutesSeconds = GPS::convertToDegreesMinutesSeconds(req.decimalDegrees);
  return true;
}
